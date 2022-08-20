#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef unsigned char* byte_pointer;

void show_bytes(const byte_pointer start,const int len){
    int i;
    for(int i=0;i < len;i++){
        printf(" %.2x",start[i]);
    }
    printf("\n");
}

void show_int(const int x){
    printf("the bytes of int[%d]: ",x);
    show_bytes((byte_pointer) &x,sizeof(x));
}

void show_float(const float x){
    printf("the bytes of float[%f]:",x);
    show_bytes((byte_pointer) &x,sizeof(x));
}
void show_pointer(const int* x){
    printf("the bytes of pointer[%d]:",*x);
    show_bytes((byte_pointer) &x,sizeof(x));
}

void show_string(const char* x){
    printf("the bytes of string[%s]:",x);
    show_bytes((byte_pointer) x,strlen(x));
}

int main(int argc,char *argv[]){
    if(argc < 2||argc>2){
        printf("input BytePrint arg1\n");
        return 1;
    }
    int x = strtol(argv[1],NULL,10);
    int y = strtod(argv[1],NULL);
    int* z = &x;
    const char *s = "abcde";
    show_int(x);
    show_float(y);
    show_pointer(z);
    show_string(s);
    return 0;
}