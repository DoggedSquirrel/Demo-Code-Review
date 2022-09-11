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
##### Bit_Level Operations----->Mask 
Operation
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
### Integer Presentation
|   C data type   |     minimum     |     maximum     |     Bytes    |
| --------------- | --------------- | --------------- | ------------ |
|  [signed] char  |      -2^7       |      2^7-1      |       1      |
|  unsigned char  |        0        |      2^8-1      |       1      |   
|       short     |     -2^15       |      2^15-1     |       2      |
|  unsigned short |        0        |      2^32-1     |       2      |
|       int       |     -2^31       |      2^31-1     |       4      |
|  unsigned int   |        0        |      2^32-1     |       4      |
|      long       |     -2^63       |      2^63-1     |       8      |
|  unsigned long  |        0        |      2^64-1     |       8      |
|     int32_t     |     -2^31       |      2^31-1     |       4      |
|    uint32_t     |        0        |     2^64-1      |       4      |
|     int64_t     |     -2^63       |      2^63-1     |       8      |
|    uint64_t     |        0        |      2^64-1     |       8      |
---------------------------------------
|        |        |        |        |
| ------ | ------ | ------ | ------ |
| Xw-1   | Xw-2   | ...    | X0     |

---------------------------------------
##### Unsigned EnCodings

*B2U*<sub>$\mathcal{w}$</sub>($\vec{x}$)≐$\mathcal{x}$<sub>$\mathcal{w-1}$</sub>·$\mathcal{2}$<sup>$\mathcal{w-1}$</sup>+$\mathcal{x}$<sub>$\mathcal{w-2}$</sub>·$\mathcal{2}$<sup>$\mathcal{w-2}$</sup>+...+$\mathcal{x}$<sub>$\mathcal{0}$</sub>·$\mathcal{2}$<sup>$\mathcal{0}$</sup>
= $$\sum_{i=1}^{w-1}x~i~*2^i$$

##### Two's Complement Encoding

*B2U*<sub>$\mathcal{w}$</sub>($\vec{x}$)≐$\mathcal{x}$<sub>$\mathcal{w-1}$</sub>·$-\mathcal{2}$<sup>$\mathcal{w-1}$</sup>+$\mathcal{x}$<sub>$\mathcal{w-2}$</sub>·$\mathcal{2}$<sup>$\mathcal{w-2}$</sup>+...+$\mathcal{x}$<sub>$\mathcal{0}$</sub>·$\mathcal{2}$<sup>$\mathcal{0}$</sup>
= $\mathcal{x}$<sub>$\mathcal{w-1}$</sub>·$-\mathcal{2}$<sup>$\mathcal{w-1}$</sup> + $$\sum_{i=1}^{w-2}x~i~*2^i$$

##### Conversions between Signed and Unsigned 

$$ T2Uw(x)=\left\{
\begin{matrix}
 x+2^w ,x<0\\
x,x>=0
\end{matrix}
\right.
$$

$$ U2Tw(x)=\left\{
\begin{matrix}
 x ,   x<=TMax_w\\
x-2^w,  x>TMax_w
\end{matrix}
\right.
$$

##### Expanding the Bit Representation of a Number
> Zero Extension

| unsign char |     unsign short    |
| ----------- | ------------------- |
|  1111 1110  | 0000 0000 1111 1110 |

> Unsign Extension

| unsign char |     unsign short    |
| ----------- | ------------------- |
|  1111 1110  | 1111 1111 1111 1110 |

*B2T<sub>w</sub>(X)* = *B2T<sub>w+1</sub>(X)*

0x1110 = -8+4+2=-2

0x11110 = -16+8+4+2=-2

> Truncating Number

32 bit -> low 16 bit<br>
*B2T<sub>k</sub>*(X) =  *B2T<sub>2k</sub>*(X) mod 2<sup>*k*</sup>

*truncating_number.c*
>- gcc -o out/truncating_number truncating_number.c

