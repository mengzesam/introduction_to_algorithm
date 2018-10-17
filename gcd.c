#include <stdio.h>
int gcd(int a,int b){
    if(b==0)
        return a;
    return gcd(b,a%b);
}

int main(){
    printf("gcd:%d\n",gcd(0,84));
    return 0;
}