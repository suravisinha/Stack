#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
typedef struct stack
{
    int info;
    struct stack* link;
}stack;

stack *ptr;

// create a stack
void create_stack()
{
   if(!ptr)
   printf("Some error occured!\n");
   else
   {
       int num;
       printf("Enter the data: ");
       scanf("%d",&num);
       ptr->info=num;
       ptr->link=NULL;
   }
}
// display
stack* display()
{
    if(!ptr->info)
    printf("Some error occured\n");
    else
    {
        do
        {
        printf("%u ",ptr->info);
        ptr=ptr->link;
        }
        while(ptr!=NULL);
    }
    return ptr;
}

// push
void push()
{
    stack*temp=ptr;
    if(!ptr->info)
    create_stack();
    else
    {
        while(temp->link!=NULL)
        {
            temp=temp->link;
        }
        stack*new=(stack*)malloc(sizeof(stack));
        printf("Enter the info: ");
        scanf("%d",&new->info);
        temp->link=new;
        new->link=NULL;
    }
}
// pop
void pop()
{
    stack*q=ptr;
    if(!ptr->info)
    printf("Stack is empty\n");
    else
    {
        stack*p;
        q=q->link;
        while(q->link!=NULL)
        {

            q=q->link;
        }
        free(q);
    }
    
}
int main()
{
    ptr=(stack*)malloc(sizeof(stack));
    int ch1,ch3;
    char ch2;
    int flag=1;
    while(flag==1)
    {
        printf("\n*****STACK*****\n");
        printf("Enter your choice: \n");
        printf("1. Create a stack\n");
        printf("2. Display stacks\n");
        printf("3. Add a stack\n");
        printf("4. Delete a stack\n");
        scanf("%d",&ch1);

        switch(ch1)
        {
            case 1:create_stack();
            break;
            case 2:display();  
            break;
            case 3:push();
            break;
            case 4:pop();
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