#include <stdio.h>
#include <math.h>

int laSoNguyen(float x) { return x == (int)x; }

int laSoCP(float x) {
    if (!laSoNguyen(x) || x < 0) return 0;
    int k = sqrt(x);
    return k * k == (int)x;
}

int laSoNT(float x) {
    if (!laSoNguyen(x)) return 0;
    int n = (int)x;
    if (n <= 1) return 0;
    for (int i = 2; i <= sqrt(n); i++)
        if (n % i == 0) return 0;
    return 1;
}

void menu() {
    printf("\n===== MENU =====\n");
    printf("1. Kiem tra so nguyen\n");
    printf("2. Kiem tra so chinh phuong\n");
    printf("3. Kiem tra so nguyen to\n");
    printf("0. Thoat\n");
}

int main() {
    int chon;
    float x;

    while (1) {
        menu();
        printf("Nhap lua chon: ");
        scanf("%d", &chon);

        if (chon == 0) break;

        printf("Nhap so: ");
        scanf("%f", &x);

        if (chon == 1)
            printf(laSoNguyen(x) ? "So nguyen\n" : "Khong so nguyen\n");
        else if (chon == 2)
            printf(laSoCP(x) ? "So chinh phuong\n" : "Khong chinh phuong\n");
        else if (chon == 3)
            printf(laSoNT(x) ? "So nguyen to\n" : "Khong nguyen to\n");
        else
            printf("Lua chon sai!\n");

        getchar(); getchar();
    }
}
