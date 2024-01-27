#include <stdio.h>
#define SIZE 20

int stack[SIZE];
int top = -1;

void push(int data) 
{
    if (top < SIZE - 1) 
	{
        stack[++top] = data;
    } 
	else 
	{
        printf("\nStack Full!\n");
    }
}

int pop() 
{
    if (top >= 0) 
	{
        return stack[top--];
    } 
	else 
	{
        printf("\nStack Empty!\n");
        return -1;
    }
}

void displayLastSubmitted() 
{
    if (top >= 0) 
	{
        printf("\nLast Submitted Register Number = %d\n", stack[top]);
    }
	else 
	{
        printf("\nNo one has submitted\n");
    }
}

void displayFirstTenSubmitted() 
{
    int count = 0;
    printf("Reg.no of the first 10 students who submitted:\n");
    while (count < 10 && top >= 0) 
	{
        printf("%d\n", stack[top--]);
        count++;
    }
}

void hasSubmitted(int regno) 
{
	int i;
    for (i = 0; i <= top; i++) 
	{
        if (stack[i] == regno) 
		{
            printf("\nStudent with Register Number %d has submitted the assignment.\n", regno);
            break;
        }
        else
        {
        	printf("\nStudent with Register Number %d has not submitted the assignment.\n", regno);
        	break;
		}
    }
}

void display()
{
	if(top == -1)
		printf("\nStack is Empty!!!");
	else
	{
		int i;
		printf("\nStack elements are:\n");
		for(i=top; i>=0; i--)
			printf("%d\n",stack[i]);
	}
}

int main() 
{
    
	int value, choice, val_reg;
	while(1)
	{
		printf("\n23MCA0078 || Prasath VS");
		printf("\n\n***** MENU *****\n");
		printf("1. Push\n2. Pop\n3. Display last submitted\n4. Display first 10 submitted\n5. Check particular student submitted\n6. Display all\n7. Exit");
		printf("\nEnter your choice: ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: 
				printf("\nEnter the value to be insert: ");
				scanf("%d",&value);
				push(value);
				break;
			case 2: 
				pop();
				break;
			case 3: 
				displayLastSubmitted();
				break;
			case 4:
				displayFirstTenSubmitted();
				break;
			case 5:
				printf("\nEnter Student Reg.no: ");
				scanf("%d", &val_reg);
				hasSubmitted(val_reg);
				break;
			case 6:
				display();
				break;
			case 7: 
				exit(0);
			default: 	
				printf("\nWrong selection!!! Try again!!!");
		}
	}
}

