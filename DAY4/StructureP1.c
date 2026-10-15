#include<stdio.h>

struct Adress{
    char village[100];
    int pincode;
    
};

struct Member{
    
    char name[100];
}

int main(){
    struct Member array[100];
    int n;
    double total;
    printf("Enter the number of members: ");
    scanf("%d",&n);

    for(int i=0;i<n;i++){
        printf("Enter the name of member %d: ",i+1);
        scanf("%s",array[i].name);
        printf("Enter the age of member %d: ",i+1);
        scanf("%d",&array[i].age);
        printf("Enter the village of member %d: ",i+1);
        scanf("%s",array[i].address.village);
        printf("Enter the pincode of member %d: ",i+1);
        scanf("%d",&array[i].address.pincode);
    }           
}