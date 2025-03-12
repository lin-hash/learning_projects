#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LEN 1001 /* Buffer size for longest line */

int main() {
   
    // 1.8 编程练习

    /*
    ** 1.Print the message "Hello world!" to the standard output.
    */
    printf("Hello world\n");

    /*
    ** 2. 从标准输入复制到标准输出，并对输出行标号
    ** 通过从输入中逐字符进行读取而不是逐行进行读取，可以避免长度限制
    */
    int ch;
    int line;
    int at_beginning;

    line = 0;
    at_beginning = 1;
    // 读取字符并逐个处理
    while( (ch = getchar()) != EOF ){
        // 如果位于第一行的起始位置，打印行号
        if(at_beginning == 1){
            at_beginning = 0;
            line++;
            printf("%d ",line);
        }

        // 打印字符，并对行尾进行检查。
        putchar( ch );
        if( ch == '\n')
            at_beginning = 1;

    }

    /*
    ** 4. Reads lines of input from the standard input and prints the longest line that
    ** was found to the standard output. It is assumed that no line will exceed
    Solution 1.4 continued ** 1000 characters.
    */
    char input[ MAX_LEN ];
    int len;
    char longest[ MAX_LEN ];
    int longest_len;
    /*
    ** Initialize length of the longest line found so far.
    */
    longest_len = -1;
    /*
    ** Read input lines, one by one.
    */
    while( gets( input ) != NULL ){
        /*
        ** Get length of this line. If it is longer than the previous
        ** longest line, save this line.
        */
        len = strlen( input );
        if( len > longest_len ){
            longest_len = len;
            strcpy( longest, input );
        }
    }
    /*
    ** If we saved any line at all from the input, print it now.
    */
    if( longest_len >= 0 )
    puts( longest );

    /* 
    ** `printf` 的格式化和骚操作
    */
    int a = 144;
    // printf 的返回值是输出到屏幕的字符个数，故可以嵌套 printf 来输出一个整数的位数
    printf("    %d\n", printf("%d", a));    // 想得到的骚操作之一   144    3

    printf("\033[1m\033[45;33m HELLO_WORLD \033[0m\n");     // 粉色底色，黄字的 HELLO_WORLD
    
    // 有关格式化，来源于 http://www.cplusplus.com/reference/cstdio/printf/?kw=printf
    printf ("Characters: %c %c \n", 'a', 65);       // Characters: a A 
    printf ("Decimals: %d %ld\n", 1977, 650000L);   // Decimals: 1977 650000
    printf ("Preceding with blanks: %10d \n", 1977); // Preceding with blanks:       1977
    printf ("Preceding with zeros: %010d \n", 1977); // Preceding with zeros: 0000001977
    printf ("Some different radices: %d %x %o %#x %#o \n", 100, 100, 100, 100, 100);
    // Some different radices: 100 64 144 0x64 0144
    printf ("floats: %4.2f %+.0e %E \n", 3.1416, 3.1416, 3.1416); //floats: 3.14 +3e+00 3.141600E+00 
    printf ("Width trick: %*d \n", 5, 10);          // *有点秀，没怎么遇见过，限制宽度
    //%*d 中的 * 被替换为 5，表示宽度为 5。
    //10 被格式化为 " 10"（前面补 3 个空格）。
    //输出： Width trick:    10
    printf ("%s \n", "A string");        //A string

    char str1[15];
    for (int i = 0; i < 10; ++i)
        scanf("%c", &str1[i]);

    printf("%s\n", str1);

    /* strcpy 函数 */
    char str2[15];
    strcpy(str2, str1);
    printf("%s\n", str2);

    /* strcat 函数 */
    char str3[30];
    strcat(str1, str2);         // 在 str1 后面追加 str2
    printf("%s\n", str1);

    return 0;
}