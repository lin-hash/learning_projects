#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 1.8 编程练习
int main() {
   
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

    return 0;
}