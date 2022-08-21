#include <stdio.h>

void shift_operation(int x,int y){
    printf("x = %d\n",x);
    printf("[%d] << 4 = %d\n",x,x<<4);
    printf("[%d] >> 4 = %d\n",x,x>>4);

    printf("y = %d\n",y);
    printf("[%d] << 4 = %d\n",y,y<<4);
    printf("[%d] >> 4 = %d\n",y,y>>4);
}

int main(){
    unsigned int x = 99;
    signed int y = -149;
    shift_operation(x,y);
    return 0;
}