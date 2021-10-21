//Reversing a string using stack
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAX 20
int top;
char stack[MAX];
void Stackpush(char a) //Element pushed in Stack
{
    if(top == MAX-1)
    {
        printf("Overflow\nNo more characters can be added to the stack.");
        exit(0);
    }
    else
    {
        ++top;
        stack[top]=a;
    }
}
void Stackpop()//Element is deleted from Stack
{
    if(top==-1)
    {
        printf("Underflow\nNo more characters can be deleted from the stack.");
        exit(0);
    }
    else
    {
        top--;
        printf("%c",stack[top]);
    }
}
char ReverseString(char b[100]) //Reversing the String
{
    int blen=strlen(b),i;
    for(i=0;i<blen+1;i++)
        Stackpush(b[i]);
    for(i=0;i<blen+1;i++)
        Stackpop();
}
int main()
{
    char S[100];
    printf("Enter the input String:");
    scanf("%[^\n]%*c",S);
    printf("\nThe Reversed String is:\n");
    ReverseString(S);
    printf("\n");
    return 0;
}

