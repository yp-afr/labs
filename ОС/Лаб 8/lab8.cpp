#include <pthread.h> 

#include <iostream> 

#include <unistd.h> 

#include <ctime> 

 

pthread_t philosophers[5]; 

pthread_mutex_t forks[5]; 

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

printf("Philosopher %d is thinking...\n", n); 

if(!pthread_mutex_trylock(&forks[n])) //пытаемся взять левую вилку, в случае успеха trylock возвращает 0, по этому "!" 

{ 

printf("Philosopher %d took the fork %d (left) \n", n,n); //выводим сообщение в случае успеха 

//пытаемся взять правую вилку 
 

if(!pthread_mutex_trylock(&forks[(n+1)%5])) 

{ 

printf("Philosopher %d took the fork %d (right) \n", n,(n+1)%5);//выводим сообщение в случае успеха 

//начинаем кушать 

printf("Philosopher %d is eating...\n", n); 

usleep(rand()%1000*800); 

spg[n] -= 200; 

printf("Philosopher %d finished eating\n", n); 

start_time[n] = clock(); //поскольку философ поел, то он не может потерять сознание раньше остальных, для него таймер обновляется 

//далее кладем обе вилки обратно на стол 

pthread_mutex_unlock(&forks[n]);  

printf("Philosopher %d put down the fork %d (left) \n",n,n); 

pthread_mutex_unlock(&forks[(n+1)%5]); 

printf("Philosopher %d put down the fork %d (right) \n",n,(n+1)%5); 

}else{ 

//в случае неудачи, сообщаем о том, что вилку взять не удалось 

printf("Philosopher %d can`t pick up the fork %d (right) \n",n,(n+1)%5); 

}  

}else{ 

printf("Philosopher %d can`t pick up the fork %d (left) \n",n,n); 

} 

//далее смотрим сколько времени прошло с момента как философ сел за стол и на основе делаем проверку 

end_time[n] = clock();  

if(end_time[n] - start_time[n] > 5000) 

{ 

printf("Philosopher %d lost consciuosness!\n", n); 

pthread_exit(0); 

break; 

} 

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