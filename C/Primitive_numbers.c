#include <stdio.h>
#include <stdlib.h>


void primitiveNumbers_upto_n(int n);
int check_for_primitive(int aNumber);

int main()
{
    //requiring the n
    int n;
    printf("Enter Number : ");
    scanf("%d", &n);

    //primitive numbers upto that
    primitiveNumbers_upto_n(n);

    return 0;
}

void primitiveNumbers_upto_n(int n){

    if(n==1||n==0)
    {
        printf("no primitive numbers");

    }
    else{
        printf("From 1 to %d primitive numbers are : \n",n);

        for(int i=2; i<=n ;i++)
        {
            if(check_for_primitive(i)== 1)
                {
                    printf("%d \t", i);
                }
        }

    }


}

int check_for_primitive(int aNumber){ //only return a value if it is primitive

    int count = 0;

    for(int i=2; i<=aNumber/2; i++){
        if(aNumber%i==0){
            count++;
        }
    }
    if(count==0){
       return 1;
    }

}

