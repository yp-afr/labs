#include <pthread.h>
#include <iostream>
#include <unistd.h>
#include <ctime>


pthread_t philosophers[5];
pthread_mutex_t forks[5];
pthread_cond_t cond[5];
int start_time[5];
int end_time[5];


int spg[5] = {400, 400, 400, 400, 400}; // "тарелки" по 400г спаггети, за раз философ может сьесть 200г

void* eating(void* arg)
{
    
    int n = (int) (*(int*)arg); //конвертировали аргумент в интовое число
    start_time[n] = clock(); //замеряем время каждого филосова в тот момент как он "сел за стол"
    while(spg[n] != 0) //пока конкретная "тарелка" не пуста пробуем брать вилки и кушать
    {
        srand(time(NULL));
        usleep(rand()%1000*800);
        //cout << "Философ " << n << " думает..." << std::endl;
        printf("Философ %d думает...\n", n);
        pthread_mutex_lock(&forks[n]); 
        printf("Философ %d взял вилку %d (левая) \n", n,n);  
        pthread_mutex_lock(&forks[(n+1)%5]);   
        printf("Философ %d взял вилку %d (правая) \n", n,(n+1)%5);    
        printf("Философ %d ест...\n", n);    
        usleep(rand()%1000*800);   
        spg[n] -= 200;
        printf("Философ %d поел\n", n);   
        start_time[n] = clock();   
        pthread_mutex_unlock(&forks[n]); 
        printf("Философ %d положил вилку %d (левая) \n",n,n);
        pthread_mutex_unlock(&forks[(n+1)%5]);
        printf("Философ %d положил вилку %d (правая) \n",n,(n+1)%5);  
        end_time[n] = clock(); 
        if(end_time[n] - start_time[n] >  10000)
        {
            printf("Философ %d потерял сознание\n", n);
            pthread_exit(0);
            break;
        }
    }
}

int main()
{
    for(int i = 0; i < 5; i++)
    {
        pthread_cond_init(&cond[i], NULL);
    }
    for(int i = 0; i < 5; i++)
    {
        pthread_mutex_init(&forks[i], NULL);
    }
    for(int i = 0; i < 5; i++)
    {
        pthread_create(&philosophers[i], NULL, eating,&i);
        usleep(10);
    }
    for(int i = 0; i < 5; i++)
    {
        pthread_join(philosophers[i], NULL);
    }
    for(int i = 0; i < 5; i++)
    {
        pthread_mutex_destroy(&forks[i]);
    }
    return 0;
}
