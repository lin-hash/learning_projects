#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 1.8 编程练习
int main() {
   
   /*
    ** 3. 从标准输入读取一些字符,并把它们写到标准输出上，同时计算checksum
    ** 注意：
    ** 当输入的 getchar() 字符整形提升后，即八进制字符为 0377，
    ** 即在十进制意义下为 255，在二进制表示下为 1111 1111。
    ** 那么它赋给整数 int 类型就等于 -1，且又等于 EOF，使得循环终止。
    */
    int a;
    char sum = -1;
    char c = 0377;      // signed char 255 = -1 unsigned char 255 = 255
    unsigned char d = 0377;
    a = c;
    printf("%d\n", a);  // -1
    a = d;
    printf("%d\n", a);  // 255

    while ((a = getchar()) != EOF) {
        putchar(a);
        sum += a;
    }
    printf("%d\n", sum);

    return 0;
}