#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* link;
};

struct node* tos = NULL;

int isEmpty() {
    return tos == NULL ? 1 : 0;
}

int top() {
    return tos->data;
}

void push(int input) {

    struct node* newnode = (struct node* )malloc(sizeof(struct node));
    newnode->data = input;
    newnode->link = NULL;

    newnode->link = tos;
    tos = newnode;
}

void pop() {
    struct node* temp = tos;
    tos = tos->link;
    free(temp);
}

int isOperator(char input) {
    return input=='+' || input=='-' || input=='*' || input=='/' ? 1 : 0;
}

int isNumber(char input) {
    return input>='0' && input<='9' ? 1: 0;
}

int performOperation(char opt,int opd1,int opd2) {
    switch(opt) {
    case '+':
        return opd1+opd2;
        break;

    case '-':
        return opd1-opd2;
        break;

    case '/':
        return opd1/opd2;
        break;

    case '*':
        return opd1*opd2;
        break;
    }
}

void evaluatePostfix(char *expression,int n) {
    int i;
    int op1,op2;
    for(i=0; i<n; i++) {
        if(expression[i]==' ' || expression[i]==',') {
            continue;
        } else if( isNumber(expression[i])) {
            int temp = 0;
            while(i<n && isNumber(expression[i])) {
                temp = (temp*10)  + (expression[i]-'0');
                printf("\n print: %d",expression[i]-'0');
                i++;
            }
            i--;
            push(temp);
        } else if( isOperator(expression[i]) ) {
            op2 = top(); pop();
            op1 = top(); pop();

            int result = performOperation(expression[i],op1,op2);
            push(result);
        }

    }
    printf("\n The evaluation is: %d",top());

}

int main()
{
    char *input;
    int n;
    printf("\n Enter the no of terms in the expression: ");
    scanf("%d",&n);

    input = (char*)malloc(sizeof(char)*n+1);
    printf("\n enter the term to evaluate: ");
    scanf("%s",input);

    evaluatePostfix(input,n);
    return 0;
}
