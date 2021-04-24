#include <pthread.h>
#include <iostream>
#include <unistd.h>

using std::cout;
using std::endl;

pthread_t philosophers[5];
pthread_mutex_t forks[5];

void* eating(void* arg)
{
    srand(time(NULL));
    int n = (int) (*(int*)arg);
    sleep(1);
    cout << "Философ " << n << " думает..." << std::endl;
    
    sleep(1);

    if(!pthread_mutex_lock(&forks[n]))
    {
        cout << "Философ " << n << " взял вилку " << n << " (левая) " << endl;
        if(!pthread_mutex_lock(&forks[(n+1)%5]))
        {
            cout << "Философ " << n << " взял вилку " << (n+1)%5 << " (правая) " << endl;  
            cout << "Философ " << n << " ест..." << endl;
            usleep(4000);
            cout << "Философ " << n << " поел" << endl;
            pthread_mutex_unlock(&forks[n]);
            pthread_mutex_unlock(&forks[(n+1)%5]);
        }else
        {    
            cout << "Философу " << n << "не удалось взять вилку " << (n+1)%5 << " (правая) " << endl;
        }
    }else
    {    
        cout << "Философу " << n << "не удалось взять вилку " << n << " (левая) " << endl;
    }
   

   

}

int main()
{
    for(int i = 0; i < 5; i++)
    {
        pthread_mutex_init(&forks[i], NULL);
    }
    for(int i = 0; i < 5; i++)
    {
        pthread_create(&philosophers[i], NULL, eating,(void*) &i);
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
