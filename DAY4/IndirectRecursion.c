#include<stdio.h>
//int n=0;
int n;
void B(int n);
void A(int n)
{
    if(n>10){
        return;
    }
    printf("%d\n",n);
    B(n+1);
}

void B(int n)
{
    if(n>10){
        return;
    }
    printf("%d\n",n);
    A(n+1);
}
int main(){
    B(0);
    //return 0;
}