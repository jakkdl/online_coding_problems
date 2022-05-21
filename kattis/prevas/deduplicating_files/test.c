#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main() {
    char c;
    int r;


    scanf("%d", &r);


    for (int i = 0; i < 10; ++i) {
        r = fread(&c, 1, 1, stdin);
        printf("%c\n", c);
    }

    return 0;
}
