#include <stdio.h>

#define N 5

int b[N], in = 0, out = 0, full = 0, empty = N;

void produce() {
    int x;

    if(empty == 0) {
        printf("Full\n");
        return;
    }

    printf("Item: ");
    scanf("%d", &x);

    b[in] = x;
    printf("Produced %d at pos %d\n", x, in);

    in = (in + 1) % N;
    empty--;
    full++;
}

void consume() {
    if(full == 0) {
        printf("Empty\n");
        return;
    }

    printf("Consumed %d from pos %d\n", b[out], out);

    out = (out + 1) % N;
    full--;
    empty++;
}

void display() {
    if(full == 0) {
        printf("Buffer Empty\n");
        return;
    }

    printf("Buffer: ");
    for(int i = 0; i < full; i++)
        printf("%d ", b[(out + i) % N]);

    printf("\n");
}

int main() {
    int ch;

    while(1) {
        printf("\n1.Produce 2.Consume 3.Display 4.Exit\n");
        scanf("%d", &ch);

        if(ch == 1) produce();
        else if(ch == 2) consume();
        else if(ch == 3) display();
        else break;
    }

    return 0;
}
