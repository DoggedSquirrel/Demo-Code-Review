#include <stdio.h>

int uadd_ok(unsigned x,unsigned y){
    unsigned sum = x+y;
    return sum>=x;
}

int main(){
    unsigned x = __UINT32_MAX__;
    unsigned y = 1;
    if(uadd_ok(x,y)){
        printf("not overflow");
    }
    else{
        printf("overflow");
    }
}