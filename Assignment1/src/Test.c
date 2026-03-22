#include <stdio.h>
#include <math.h>

int main() {
    double x;
    int i;

    printf("Nhap so x: ");
    scanf("%lf", &x);

    // Kiểm tra có phải số nguyên không
    if (x != (int)x || x <= 1) {
        printf("x khong phai la so nguyen to\n");
        return 0;
    }

    int n = (int)x;

    for (i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            printf("x khong phai la so nguyen to\n");
            return 0;
        }
    }

    printf("x la so nguyen to\n");
    return 0;
}
