#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <cstring>
#include <string>
#include <iostream>
#include <sys/msg.h>
#include <semaphore.h>

using namespace std;

typedef struct mymsgbuf
{
    long mtype;
    string text;
} mess_t;

sem_t sems[3];
int qIds[3];
mess_t msgs[3];
mess_t buffs[3];

void doSomeWork(int shmid, int id);

int main()
{
    for(int i = 0; i < 3; i++)
    {
        sem_init(&sems[i],0,1);
    }    
    
    key_t key = ftok("files", 65);
    
    int shmid = shmget(key,1024,0666 | IPC_CREAT);
    string *str; 
    str =(string*) shmat(shmid,0,0);
    

    str[0] = "./test1"; 
    str[1] = "./test2";
    str[2] = "./test3";
    str[3] = "./test4";
    
    key_t msgKeys[3];
    for(int i = 0; i < 3; i++)
    {
        msgKeys[i] = ftok((char*)i,i);
        qIds[i] = msgget(msgKeys[i], IPC_CREAT | 0660);
    }

    for(int i = 0; i < 3; i++)
    {
        if(fork()==0)
        {
            doSomeWork(shmid,i);
        }
    }
    shmdt(str);
    shmctl(shmid,IPC_RMID,NULL);

    int length = sizeof(mess_t) - sizeof(long);
    int i = 0;
    for(;;)
    {   
        if(i == 4) i = 0;
        usleep(50);
        sem_wait(&sems[i]);
        int rec = msgrcv(qIds[i], &buffs[i], length, 0, IPC_NOWAIT);
        if(rec != -1) cout << buffs[i].text;
        sem_post(&sems[i]);
        i++; 
    }
     return 0;
}

void doSomeWork(int shmid_, int id)
{
    srand(getpid());
    string *str_ = (string*) shmat(shmid_,0,0);
    int counter = 0;
    int length = sizeof(mess_t) - sizeof(long); 
    while(counter != 3)
    {  
        sem_wait(&sems[id]); 
        int n = rand()%4;
        system(str_[n].c_str());
        counter++;
        msgs[id].mtype = 1;
        msgs[id].text +="[";
        msgs[id].text += getpid();
        msgs[id].text +="]";
        msgs[id].text += "runs ";
        msgs[id].text += str_[n];
        msgs[id].text += "\n";
        msgsnd(qIds[id], &msgs[id], length,0);
        sleep(rand()%3);
        sem_post(&sems[id]);
    }

}


