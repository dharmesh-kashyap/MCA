#include<stdio.h>
#include<stdlib.h>

int mutex = 1;
int x = 0 ;
int Full = 0;
int Empty = 5;

int producer(){
    --mutex;
    --Empty;    
    ++Full;
    printf("The producer produced %d", x);
    x++;
    ++mutex;
}

int consumer(){
    --mutex;
    --x;
    ++Empty;
    --Full;
    printf("The Consumer Consumed %d", x);
    x--;
    ++mutex;
}

int Buffer(){
    printf("\n\tValue of FULL = %d",Full);
    printf("\n\tValue of EMPTY = %d",Empty);
}


int main(){

    int choice;

    do
    {
         printf("\nMenu\n1. Produce\n2. Consume\n3. Buffer\n4. Exit");
         printf("Enter the Choice = ");
         scanf("%d",&choice);

         switch (choice)
         {
         case 1:
            if((mutex == 1) && ( Empty!=0)){
                producer();
            } else {
                printf("The Buffer is full");
            }
            break;
         case 2:
            if((mutex == 1) && ( Full!=0)){
                consumer();
            } else {
                printf("The Buffer is Empty");
            }
            break;
         case 3 : 
         Buffer();
         break;
         case 4:
         printf("Exiting...");
         exit(0); 
         break;
         
         default:
            printf("Invalid Choice");
            break;
         }
        
    } while (choice!=4);
    

}