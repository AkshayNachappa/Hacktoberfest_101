#include <stdio.h>
#include <stdlib.h>


void primitiveNumbers_upto_n(int n);
int check_for_primitive(int aNumber);

int main()
{
    //requiring the n
    int n;
    scanf("%d", &n);

    //primitive numbers upto that
    primitiveNumbers_upto_n(n);

    return 0;
}

void primitiveNumbers_upto_n(int n){

    for(int i=1; i<=n ;i++){
        if(check_for_primitive(i)== 1){
            printf("%d \t", i);
        }
    }
}

int check_for_primitive(int aNumber){ //only return a value if it is primitive

    //how to know a given number is primitive
    int count = 0;  // as a primitive number only got 2 factors (1 & itself onlt) the count will be 2

    for(int i=1; i<=aNumber; i++){
        if(aNumber%i==aNumber || aNumber%i==0){
            count++;
        }
    }
    if(count==2){
       return 1;
    }

}
