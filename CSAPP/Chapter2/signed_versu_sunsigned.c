#include <stdio.h>

int main(int argc,char*argv[]){
    int a = -1;
    unsigned int b = 0;
    //2^32-1 < 0
    if(a<b){
        printf("-1<0");
    }
    else{
        printf("-1>0");
    }
    return 0;
}