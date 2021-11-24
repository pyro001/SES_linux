#include<pthread.h>
#include<stdio.h>
#include<unistd.h>
#include<iostream>
#include<string>

#define EVER ;;
using namespace std;

pthread_t AA_id;
pthread_t BB_id;
pthread_mutex_t amutex;
sem_t park_count;

class Screen
{
private:
static pthread_mutex_t lock;
public:
    static void write_string(string a)
    {
	pthread_mutex_lock(&lock);
	cout<<a<<"\n";
	pthread_mutex_unlock(&lock);
    }
    static void write_number(int b)
    {
	pthread_mutex_lock(&lock);
	cout<<b<<"\n";
	pthread_mutex_unlock(&lock);
    }
    static void new_line()
    {
	pthread_mutex_lock(&lock);
	cout<<"\n";
	pthread_mutex_unlock(&lock);
    }
    static void write_string_and_number(string a, int b)
    {
	pthread_mutex_lock(&lock);
	cout<<a<<"\n"<<b<<"\n";
	pthread_mutex_unlock(&lock);
    }
    
};
pthread_mutex_t Screen::lock = PTHREAD_MUTEX_INITIALIZER;

class Car
{
public:
	Car(int a)
	{num=a;
	//sem_wait(&park_count);
	}
	void get_number() {cout <<num <<endl;}
	void park()
	{
	sem_wait (&park_count);
	cout << "doing something" << endl;
	sem_post (&park_count);
	}
private:
	int num;
	static int max;
};

void* AA(void* ptr)
{
	for (EVER)
	{
        Screen::write_string("h");
	Screen::write_string("i");
	}
	return NULL;
}
void* BB(void* ptr)
{
	for (EVER)
	{
        Screen::write_string("bye");
	}
	return NULL;
}
int main(void)
{ 
   //pthread_create(&AA_id, NULL, &AA, NULL);
   //pthread_create(&BB_id, NULL, &BB, NULL);
	sem_init(park_count, 0, 4)

   //pthread_join(AA_id, NULL);
   //pthread_join(BB_id, NULL);
   Car c1(1),c2(2),c3(3),c4(4);
   for(EVER)
   {
   c1.park();
   c2.park();
   c3.park();
   c4.park();
   }
   
   return 0;
}
