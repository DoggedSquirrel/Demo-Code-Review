#include <stdio.h>

void log_operation(int x,int y){
    printf("!%x = %x\n",x,!x);
    printf("!!%x = %x\n",x,!!x);
    printf("%x && %x = %x\n",x,y,x&&y);
    printf("%x || %x = %x\n",x,y,x||y);
}

int main(int argc,char*argv[]){
    int x = 0x69;
    int y = 0x55;
    log_operation(x,y);
    /**
     * @brief 
     * if(a&&5/a)
     */
    
    return 0;
}