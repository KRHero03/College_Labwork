#define SIZE 5
chan c = [6] of {int};

int buffer = 0;

active proctype producer() {
    int data=0;
    do
    :: buffer < SIZE -> 
        buffer = buffer + 1; 
        c ! data; 
        data++;
        printf("Buffer : %d\n",buffer);
        printf("Produced Item : %d\n",data);
    od
}
active proctype consumer() {
    int data;
    do
    ::  c?data; 
        buffer = buffer - 1;
        printf("Buffer : %d\n",buffer);
        printf("Consumed Item : %d\n",data);
    od
}
active proctype monitor() {
    assert (buffer <= SIZE && buffer >= 0);
}