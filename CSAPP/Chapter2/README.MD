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
    Operation<br>
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

$$ T2Uw(x)=
\begin{cases}
 x+2^w ,x<0\\
x,x>=0
\end{cases}

$$

$$ U2Tw(x)=
\begin{cases}
 x ,   & x<=TMax_w\\
x-2^w, & x>TMax_w
\end{cases}
$$
----------------------------------
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

--------------------------------------
##### Unsigned Addition
*detecting_overflow_unsigned_addition.c*
>- gcc -o out/detecting_overflow_unsigned_addition detecting_overflow_unsigned_addition.c
##### Two's-Complement Addition Code

    char x = 127      1111 1111
    char y = 1        0000 0001
    char z = x + y   10000 0000 
                    z = x + y -2^8 = -128 

$$ x+^t_wy =\begin{cases}
 x,     & 2^{w-1}<=x+y       & \text {positive overflow}     \\
x-2^w,  & -2^{w-1}<=x+y<2^{w-1}    \\
x+y+2^w,& x+y<-2^{w-1}       & \text {negative overflow}
\end{cases}
$$

*two's_complement_addition_code.c*
>- gcc -o out/two's_complement_addition_code two's_complement_addition_code.c

-----------------------------------------
##### Unsigned Multiplcation
    char x;
    char y;
    char z = x * y;//truncate high 8 bit, z = (x*y)mod2^8
##### Multiplying by Constans
    Example: x*14
      14 = 2^3+2^2+2^1
      x*14 = (x<<3+x<<2+x<<1)

##### Dividing by Powers of 2
|  k  | Bias |     -12340+bias     |     >>k(binary)     | Decimal |
| --- | ---- | ------------------- | ------------------- | ------- |
|  0  |   0  | 1100 1111 1100 1100 | 1100 1111 1100 1100 |  -12340 |
|  1  |   1  | 1100 1111 1100 1101 | 1110 0111 1110 0110 |  -6170  |
|  4  |  15  | 1100 1111 1101 1011 | 1111 1100 1111 1101 |   -771  |
|  8  |  255 | 1101 0000 1100 1011 | 1111 1111 1101 0000 |   -48   |

-------
##### Floating-Point Representation
V = (-1)<sup>*s*</sup>×*M*×2<sup>*E*</sup><br>
   
    |--------| 31 |30----------23|22-----------0|
    | float  |  s |      exp     |     frac     |
    |-------------------------------------------|
    |        | 63 |62----------51|50-----------0|
    | double |  s |      exp     |     frac     |
    |-------------------------------------------|
> 1.Normalized

[s][ /= 0 and /= 255 ][f]<br>
*E* = e -bias<br>
8 bit

    bias = 2^8-1 = 127
    Emin = -126 | Emax = 127
    M = 1 + frac
> 2.Denormalized

[s][ 0000 0000 ][f]<br>

      Case 0: s = 0    M = f = 0   V = +0.0
      Case 1: s = 1    M = f = 0   V = -0.0
> 3.Infinity

[s][ 1111 1111 ][ 0000 ... 0000 ]

      Case 0: s = 0    f = 0       V = +∞
      Case 1: s = 1    f = 0       V = -∞
[s][ 1111 1111 ][ /=0 ]

      Case : ∞-∞  

##### 8-bit Floating-Point Format
|       Description      | Bit respresentation |  e  | bias | *E* |  2^E |  f  |   M  | value |
| ---------------------- | ------------------- | --- | ---- | --- | ---- | --- | ---- | ----- |
| Smallest Normalization |     0 0001 000      |  1  |   7  |  -6 | 1/64 | 0/8 |  8/8 | 8/512 |
|  Largest Normalization |     0 1110 111      | 14  |   7  |  7  |  128 | 7/8 | 15/8 |  240  |
|        Infinity        |     0 1111 000      |  -  |   -  |  -  |   -  |  -  |   -  |   ∞   |

##### Rounding
> 1.Round-down
> 2.Round-up
> 3.Round-to-zero
> 4.Round-to-even

##### Floating-Point Operations
    (1) (3.14+ 1e10)-1e10 = 0.0
    (2) (3.14) +(1e10 - 1e10) = 3.14
    (3) (1e20 * 1e20) * 1e-20 = +∞
    (4) 1e20 * (1e20 - 1e20) = 1e20
    (5) 1e20 * (1e20 - 1e20) = 0.0
    (6) 1e20 * 1e20 - 1e20*1e20 = NaN
