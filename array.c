#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define max 4
typedef struct stack
{
    int top;
    int capacity;
    int* array;
}stack;

int top;
stack *ptr;

// create a stack
stack* create_stack()
{
    if(!ptr)
    printf("Some eror occured\n");
    
    ptr->capacity=max;
    ptr->top=-1;
    ptr->array=malloc(ptr->capacity*sizeof(stack));

    if(!ptr->array)
    return NULL;

    return ptr;
}
// display
void display()
{
    if(ptr->top==ptr->capacity-1)
    printf("Stack is empty\n");
    else
    {
        for(int i=0;i<=ptr->top;i++)
        {
            printf("%d ",ptr->array[i]);
        }
    }
    
}

// push
void push()
{
    if(ptr->top==ptr->capacity-1)
    printf("Stack is full!\n");
    else
    {
        int info;
        printf("Enter the data: ");
        scanf("%d",&info);
        ptr->array[++ptr->top]=info;
        printf("Data pushed into the stack\n");
    }
    
}
// pop
void pop()
{
    if(ptr->top==-1)
    printf("The stack is empty\n");
    else
    {
        printf("Deletion successfull\n");
        ptr->top--;
    }
    
}
int main()
{
    ptr=(stack*)malloc(sizeof(stack));
    int ch1,ch3;
    char ch2;
    int flag=1;
    create_stack();
    while(flag==1)
    {
        printf("\n*****STACK*****\n");
        printf("Enter your choice: \n");
        printf("1. Display stacks\n");
        printf("2. Add a stack\n");
        printf("3. Delete a stack\n");
        printf("4. Exit\n");
        scanf("%d",&ch1);

        switch(ch1)
        {
            case 1:display();  
            break;
            case 2:push();
            break;
            case 3:pop();
            break;
        }
        
        printf("Do you wish to continue?(Y/N)\n");
        scanf(" %c",&ch2);
        ch2=toupper(ch2);
        if(ch2=='N')
        flag=0;
        else
        flag=1;
        
    }
    return 0;
}