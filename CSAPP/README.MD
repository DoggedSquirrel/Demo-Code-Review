# CSAPP

## Chapter1 A Tour of Compter System(计算机系统漫游)

#### **预处理(Preprocessing)**
>- gcc -E -I./ hello.c -o hello.i 
>- cpp hello.c -I./ -o hello.i
#### **编译(Compilation)**
>- gcc -S -I./ hello.c -o hello.s
#### **汇编(Assemble)**
>- as hello.s -o hello.o
>- gcc -c hello.s -o hello.o
#### **链接(Linking)**
>- ld -o hello hello.o inc/*.o

## Part Ⅰ. Program Structure and Execution(程序结构和执行)

## Part Ⅱ. Running Program on a System(在系统上运行程序)

## Part Ⅲ. Interaction and Communication between Programs(进程间的交互和通信)