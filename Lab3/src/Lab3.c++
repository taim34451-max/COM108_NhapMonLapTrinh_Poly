#include <stdio.h>
#include <math.h>

// kiểm tra số nguyên tố
int laSoNguyenTo(int n) {
    if (n < 2) return 0;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}

// tính giai thừa
long long giaiThua(int n) {
    long long gt = 1;
    for (int i = 1; i <= n; i++) {
        gt *= i;
    }
    return gt;
}

// tính tổng từ 1 đến n
int tong1denN(int n) {
    int tong = 0;
    for (int i = 1; i <= n; i++) tong += i;
    return tong;
}

int main() {
    int choice, n;

    do {
        printf("\n===== HELLO MAY NI NHA =====\n");
        printf("1. Kiem tra so nguyen to\n");
        printf("2. Tinh giai thua\n");
        printf("3. Tinh tong 1 den N\n");
        printf("4. Thoat\n");
        printf("==============================\n");
        printf("Chon chuc nang: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Nhap n: ");
                scanf("%d", &n);
                if (laSoNguyenTo(n))
                    printf("%d la so nguyen to.\n", n);
                else
                    printf("%d khong phai so nguyen to.\n", n);
                break;

            case 2:
                printf("Nhap n: ");
                scanf("%d", &n);
                printf("Giai thua cua %d la %lld\n", n, giaiThua(n));
                break;

            case 3:
                printf("Nhap n: ");
                scanf("%d", &n);
                printf("Tong tu 1 den %d la %d\n", n, tong1denN(n));
                break;

            case 4:
                printf("Thoat chuong trinh.\n");
                break;

            default:
                printf("NI BI DUI HA NI CHON LAI DI NI\n");
        }

    } while (choice != 4);

    return 0;
}