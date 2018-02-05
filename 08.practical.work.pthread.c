#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct 
{
  char type; 
  int amount; 
  char unit; 
} item;

#define BUFFER_SIZE 10
item buffer[BUFFER_SIZE];
int first = 0;
int last = 0;

void produce(item *i) {
while ((first + 1) % BUFFER_SIZE == last) {

}
memcpy(&buffer[first], i, sizeof(item));
first = (first + 1) % BUFFER_SIZE;
}

item *consume() {
item *i = malloc(sizeof(item));
while (first == last) {
}
memcpy(i, &buffer[last],sizeof(item));
last = (last + 1) % BUFFER_SIZE;
return i;
}
void *consumer(void *param){
	consume();
	printf("First of log values  = %d, last = %d \n", first,last);
	consume();
	printf("First of log values  = %d, last = %d \n", first,last);
	
}
void *producer(void *param){
        item i1,i2,i3;
	i1.type = '1';
	i1.amount = 5 ;
	i1.unit = '3';
        i2.type = '1';
	i2.amount = 3;
	i2.unit = '1';
        i3.type = '1';
	i3.amount = 20;
	i3.unit = '1';
	
        produce(&i1);
	printf("Log values of first = %d, last = %d \n", first,last);
	
	produce(&i2);
	printf("Log values of first = %d, last = %d \n", first,last);
	
	produce(&i3);
	printf("Log values of first = %d, last = %d \n", first,last);

}


int main()
{
        pthread_t tid;
	pthread_create(&tid, NULL, producer, NULL);
	pthread_create(&tid, NULL, consumer, NULL);
        pthread_join(tid, NULL);
}
