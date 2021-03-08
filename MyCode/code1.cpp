#include <stdio.h>
#include <stdlib.h>

int main(){
    int a;
    for (int i = 0; i<=9; i++){
        if(i % 2 == 0){
            a = i * 2;
        }
        printf("%d\n", a);
    }
    system("pause");
    return 0;
}