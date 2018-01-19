#define BUFFER_SIZE 10

typedef struct
{
	char typer;
        int amount;
        char unit;
}item;

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

int main()
{
        item t1,t2;
	t1.type = '1';
	t1.amount = 5 ;
	t1.unit = '3';
        t2.type = '1';
	t2.amount = 3;
	t2.unit = '1';
	printf("First values  = %d, last values = %d \n", first,last);
	produce(&t1);
	printf("First values  = %d, last values = %d \n", first,last);
        produce(&t2);
	consume();
        printf("First values  = %d, last values = %d \n", first,last);
        return 0;
}
