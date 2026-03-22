#include <stdio.h>
#include <stdlib.h>

int main() {
    // In ra các số chẵn < 100
    for (int i = 2; i < 100; i++) {
        if (i % 2 == 0)
            printf("%d\t", i);
    }

    printf("\n");
    system("pause"); // hoặc getchar();
    return 0;
}

