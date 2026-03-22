#include <stdio.h>
#include <math.h>

// Khai báo nguyên mẫu hàm
void inputArray(int x[10], int n);
void showArray(int x[10], int n);
int isPrime(int n);
void printPrimeElements(int a[], int n);

int main() {
    int a[10], size;

    printf("\nNhap so phan tu mang (<=10): ");
    scanf("%d", &size);

    if(size < 1 || size > 10){
        printf("Size khong hop le!\n");
        return 0;
    }

    // Nhập và in mảng
    inputArray(a, size);
    showArray(a, size);

    printf("=================\n");

    // In ra các số nguyên tố
    printPrimeElements(a, size);

    return 0;
}

// Nhập mảng
void inputArray(int x[10], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("x[%d] = ", i);
        scanf("%d", &x[i]);
    }
}

// In mảng
void showArray(int x[10], int n) {
    int i;
    printf("---------------\n");
    for (i = 0; i < n; i++) {
        printf("%d ", x[i]);
    }
    printf("\n");
}

// Hàm kiểm tra số nguyên tố
int isPrime(int n) {
    if (n < 2) return 0;
    int i;
    for (i = 2; i <= sqrt(n); i++) {
        if (n % i == 0)
            return 0;
    }
    return 1;
}

// In các phần tử là số nguyên tố
void printPrimeElements(int a[], int n) {
    int i, count = 0;

    printf("Cac so nguyen to trong mang: ");

    for (i = 0; i < n; i++) {
        if (isPrime(a[i])) {
            printf("%d ", a[i]);
            count++;
        }
    }

    if (count == 0)
        printf("Khong co so nguyen to nao!");

    printf("\n");
}

