#include <stdio.h>
#include <math.h>

// --- 1. XAY DUNG CAC HAM THEO YEU CAU ---

// Ham nhap mang: void inputArray(int x[10], int n)
void inputArray(int x[10], int n) {
    for (int i = 0; i < n; i++) {
        printf("Nhap a[%d] = ", i);
        scanf("%d", &x[i]);
    }
}

// Ham xuat mang: void showArray(int x[10], int n)
void showArray(int x[10], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", x[i]);
    }
    printf("\n");
}

// Ham dem so le: int elementOddArray(int x[10], int n)
int elementOddArray(int x[10], int n) {
    int dem = 0;
    for (int i = 0; i < n; i++) {
        if (x[i] % 2 != 0) dem++;
    }
    return dem;
}

// Ham dem so chan: int elementEvenArray(int x[10], int n)
int elementEvenArray(int x[10], int n) {
    int dem = 0;
    for (int i = 0; i < n; i++) {
        if (x[i] % 2 == 0) dem++;
    }
    return dem;
}

// Ham tinh tong le: int elementOddTotalArray(int x[10], int n)
int elementOddTotalArray(int x[10], int n) {
    int tong = 0;
    for (int i = 0; i < n; i++) {
        if (x[i] % 2 != 0) tong += x[i];
    }
    return tong;
}

// Ham tinh tong chan: int elementEvenTotalArray(int x[10], int n)
int elementEvenTotalArray(int x[10], int n) {
    int tong = 0;
    for (int i = 0; i < n; i++) {
        if (x[i] % 2 == 0) tong += x[i];
    }
    return tong;
}

// Ham kiem tra so nguyen to: int laSoNT(int x)
int laSoNT(int x) {
    if (x < 2) return 0;
    for (int i = 2; i <= sqrt(x); i++) {
        if (x % i == 0) return 0;
    }
    return 1;
}

// Ham kiem tra so chinh phuong: int laSoCP(float x)
// De bai yeu cau tham so float
int laSoCP(float x) {
    int k = (int)x; // Ep kieu float ve int
    int can = sqrt(k);
    if (can * can == k) return 1;
    return 0;
}

// --- 2. CHUONG TRINH CHINH (MAIN) ---

int main() {
    int a[10];
    int n;

    // Yeu cau: Nhap vao mang (toi da 10 phan tu)
    do {
        printf("Nhap so phan tu n (0 < n <= 10): ");
        scanf("%d", &n);
        if (n <= 0 || n > 10) printf("Nhap sai, n phai tu 1 den 10!\n");
    } while (n <= 0 || n > 10);

    // Goi ham nhap
    inputArray(a, n);

    // Yeu cau: Hien thi mang vua nhap
    printf("\nMang vua nhap la: ");
    showArray(a, n);

    // Yeu cau: Hien thi danh sach cac phan tu chia het cho 3
    printf("\nDanh sach cac phan tu chia het cho 3: ");
    int coSoChiaHet3 = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] % 3 == 0) {
            printf("%d ", a[i]);
            coSoChiaHet3 = 1;
        }
    }
    if (coSoChiaHet3 == 0) printf("Khong co");

    // Yeu cau: Hien thi so luong phan tu chan va le
    printf("\n\nSo luong phan tu Chan: %d", elementEvenArray(a, n));
    printf("\nSo luong phan tu Le  : %d", elementOddArray(a, n));

    // Yeu cau: Hien thi tong cac phan tu chan va le
    printf("\n\nTong cac phan tu Chan: %d", elementEvenTotalArray(a, n));
    printf("\nTong cac phan tu Le  : %d", elementOddTotalArray(a, n));

    // BONUS: De bai bat viet ham NT va CP nhung khong bat hien thi ket qua
    // Tuy nhien nen in ra de thay giao biet la ham da hoat dong.
    printf("\n\n--- Kiem tra them (Bonus) ---");
    printf("\nSo Nguyen To co trong mang: ");
    for(int i=0; i<n; i++) if(laSoNT(a[i])) printf("%d ", a[i]);
    
    printf("\nSo Chinh Phuong co trong mang: ");
    for(int i=0; i<n; i++) if(laSoCP((float)a[i])) printf("%d ", a[i]);

    printf("\n");
    return 0;
}