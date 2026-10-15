#include<stdio.h>

int n=0;
int main(){
    n=n+1;
    if(n<5){
        main();
    }
    return 0;
}