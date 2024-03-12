
#include <stdio.h>
#include<stdlib.h>
int mutex = 1;
int full = 0;
int empty = 5, x = 0;

void producer()
{
        --mutex;
        ++full;
        --empty;
        x++;
        printf("\nProducer produced item %d",x);
        ++mutex;
}


void consumer()
{
        --mutex;
        --full;
        ++empty;
        printf("\nConsumer consumed item %d",x);
        x--;
        ++mutex;
}
void buffer_val()
{
        printf("\n\tValue of FULL = %d",full);
        printf("\n\tValue of EMPTY = %d",empty);
}
int main()
{
        int n, i;
        printf("\n1.Produce an item \n2.Consume an item \n3.Buffer value \n4.Exit");

        for (i = 1; i > 0; i++)
        {

                printf("\nEnter your choice:");
                scanf("%d", &n);
                switch (n)
                {
                        case 1:
                                if (mutex == 1&&empty != 0)
                                {
                                        producer();
                                }
                                else
                                {
                                        printf("Buffer is full!");
                                }
                                break;

                        case 2:

                                if (mutex == 1&&full != 0)
                                {
                                        consumer();
                                }
                                else
                                {
                                        printf("Buffer is empty!");
                                }
                                break;
                        case 3:
                                buffer_val();
                                break;
                        case 4:
                                exit(0);
                }

        }
        return 0;
}
