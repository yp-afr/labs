#include <unistd.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <iterator>
#include <sstream>
#include <semaphore.h>

using namespace std;

struct mesg_buf
{
    long msgType;
    char msgText[70];
} mess_t; 

sem_t sem;

void doSomeJob(int msgid);

int main()
{
    sem_init(&sem,0,1);

    
    key_t key = ftok("test",65);
    key_t key_ = ftok("files", 66);
    
    int msgid = msgget(key_, 0666 | IPC_CREAT);
    int shmid = shmget(key,1024,0666|IPC_CREAT);
    char *names = (char*) shmat(shmid,(void*)0,0);
    
    cout<<"Enter names: ";
    cin.getline(names,128);
    
    mess_t.msgType = 1;
    
    srand(getpid());

    if(fork()==0)
    {
    	for(;;)
    		doSomeJob(msgid);
    }else
    {
    	if(fork() == 0)
    	{
    		for(;;)
    			doSomeJob(msgid);
    	}else
    	{
    		for(;;)
			{
				msgid = msgget(key_, 0666 | IPC_CREAT);
				msgrcv(msgid, &mess_t, sizeof(mess_t), 1, 0);
				cout << mess_t.msgText << endl;
			}
    	}
    }
    	
    
			

	return 0;
}

void doSomeJob(int msgid)
{
	char buffer[32];
	char file_name[16];
	key_t key = ftok("test",65);
	int shmid = shmget(key,1024,0666|IPC_CREAT);
	char *str = (char*) shmat(shmid,(void*)0,0);
	
	string file_names = "";
	for(int i = 0;i < strlen(str);i++) 
		file_names += str[i];
		
	istringstream iss(file_names);
	vector<string> vecOfFileNames((istream_iterator<string>(iss)), istream_iterator<string>());
	
	int file_num = rand() % vecOfFileNames.size();
	
	string message = to_string(getpid()); 
	message += " runs "; 
	message += vecOfFileNames[file_num];

	strcpy(buffer,message.c_str());
	strcpy(mess_t.msgText,buffer);
	strcpy(file_name,vecOfFileNames[file_num].c_str());
	
	sem_wait(&sem);
	msgsnd(msgid, &mess_t, sizeof(mess_t), 0);
	system(file_name);
	sem_post(&sem);	
}
