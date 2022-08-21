### Hexadecimal Notation 
        Hex digit  0    1    2    3    4    5    6    7    8    9    A    B    C    D    E    F
    Decimal value  0    1    2    3    4    5    6    7    8    9    10   11   12   13   14   15
     Binary value 0000 0001 0010 0011 0100 0101 0110 0111 1000 1001 1010 1011 1100 1101 1110 1111
### C declaration ----> Bytes
      Signed             Unsigned              32-bit          64-bit       
    --------------------------------------------------------------------
    [signed]char       unsigned char             1               1
    short              unsigned short            2               2
    int                   unsigned               4               4
    long               unsigned long             4               8
    int32_t               uint32_t               4               4           
    int64_t               uint64_t               8               8
    char *                                       4               8
    float                                        4               4
    double                                       8               8
### 大端法与小端法
    Bid endian(大端法)     0x01234567  ------- Inter与Sun
      0x100   0x101   0x102   0x103
        01      23      45      67
    Little endian(小端法)               ------ Mac与Android
      0x100   0x101   0x102   0x103
        67      45      23      01
*byte_print.c* 
>- gcc -o out/byte_print byte_print.c
### Boolean Algebra     
##### Bit_Level Operations----->Mask Operation
    ~           & 0 1       | 0 1       ^ 0 1 
    -----       -----       -----       -----
    1   0       0 0 0       0 0 1       0 0 1
    0   1       1 0 1       1 1 1       1 1 0
*bit_level_operation.c*
>- gcc -o out/bit_level_operation bit_level_operation.c
##### Logic Operation
    !       !0x69
    !!      !!0x69   
    &&      0x69 && 0x55
    ||      0x69 || 0x55
*logic_operation.c*
>- gcc -o out/logic_operation logic_operation.c
##### Shift Operation
      operation                   value1              value2
         x                      [01100011]          [10010101]
       x << 4                   [00110000]          [01010000]
     x >> 4(logical)            [00000110]          [00001001] <<<---unsigned
    x >> 4(arithmetic)          [00000110]          [11111001] <<<---signed 
*shift_operation.c*
>- gcc -o out/shift_operation shift_operation.c