#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LEN 1001 /* Buffer size for longest line */

// 1.8 编程练习
int main() {
   
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

    return 0;
}