/*用法示例*/
#include <stdio.h>
#include <stdlib.h>

extern char* StrSHA256(const char* str, int length, char* sha256);

int main(void){
    char text[] = "blackkitty";
    char sha256[65];
    StrSHA256(text,sizeof(text)-1,sha256);  // sizeof()计算的结果包含了末尾的'\0'应减1
    puts(sha256);
    puts(StrSHA256(text,sizeof(text)-1,sha256));    // 函数返回值即sha256，直接输出也可以
    return 0;
}