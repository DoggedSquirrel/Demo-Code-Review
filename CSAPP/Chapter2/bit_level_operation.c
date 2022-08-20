#include <stdio.h>

void NotX(int x){
    printf("not 0x%x = 0x%x\n",x,~x);
}
void XAndY(int x,int y){
    printf(" 0x%x & 0x%x = 0x%x\n",x,y,x&y);
}

void XOrY(int x,int y){
    printf(" 0x%x | 0x%x = 0x%x\n",x,y,x|y);
}


int main(int argc,char*argv[]){
    int x = 0x41;
    int y = 0x69;
    int z = 0x55;
    NotX(x);
    XAndY(y,z);
    XOrY(y,z);
    return 0;
}