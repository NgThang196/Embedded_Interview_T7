#include <stdio.h>
#define tinhtong_macro(a, b) (a + b)
static inline int tinhtong_inline(int a, int b) {
    return a + b;
}
int tinhtong_ham(int a, int b) {
    return a + b;
}
int main() {
    int num1 = 2;
    int num2 = 4;
    //Macro
    int kqua_macro = tinhtong_macro(num1, num2);
    printf("tong macro: %d\n", kqua_macro);
    //inline function
    int kqua_inline = tinhtong_inline(num1, num2);
    printf("tong inline: %d\n", kqua_inline);
    //function
    int kqua_function = tinhtong_function(num1, num2);
    printf("tong function: %d\n", kqua_function);
    return 0;
}
