#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

// --- HAM CHO ENTER ---
void choNhapEnter() {
    printf("\nNhan ENTER de quay lai menu...");
    fflush(stdin);
    getchar();  // Chờ ENTER
}

// --- HAM BO TRO ---
int timUCLN(int a, int b) {
    a = abs(a); b = abs(b);
    while (a != b) {
        if (a > b) a -= b;
        else b -= a;
    }
    return a;
}

struct SinhVien {
    char hoTen[50];
    float diem;
    char hocLuc[20];
};

// --- KHOI HAM CHUC NANG (giữ nguyên các chức năng cũ) ---

void chucNang1() {
    float n;
    printf("\n--- 1. KIEM TRA SO NGUYEN ---\n");
    printf("Nhap mot so: ");
    scanf("%f", &n);
    if (n == (int)n) {
        int x = (int)n;
        printf("-> %.0f la so nguyen.\n", n);
        
        int dem = 0;
        if (x < 2) printf("-> %d khong phai so nguyen to.\n", x);
        else {
            for (int i = 2; i <= sqrt(x); i++) {
                if (x % i == 0) { dem++; break; }
            }
            if (dem == 0) printf("-> %d la so nguyen to.\n", x);
            else printf("-> %d khong phai so nguyen to.\n", x);
        }
        
        int can = sqrt(x);
        if (can * can == x) printf("-> %d la so chinh phuong.\n", x);
        else printf("-> %d khong phai so chinh phuong.\n", x);
    } else {
        printf("-> %.2f khong phai la so nguyen.\n", n);
    }
}

void chucNang2() {
    int a, b;
    printf("\n--- 2. UCLN va BCNN ---\n");
    printf("Nhap a, b: ");
    scanf("%d%d", &a, &b);
    if(a <= 0 || b <= 0) { printf("Nhap so duong!\n"); return; }
    
    int x = a, y = b;
    while(a != b) {
        if(a > b) a -= b;
        else b -= a;
    }
    printf("UCLN: %d\n", a);
    printf("BCNN: %lld\n", (long long)x * y / a);
}

void chucNang3() {
    int gioDau, gioKet;
    printf("\n--- 3. TINH TIEN KARAOKE ---\n");
    printf("Nhap gio dau, gio ket (12-23): ");
    scanf("%d%d", &gioDau, &gioKet);
    
    if (gioDau < 12 || gioDau > 23 || gioKet < 12 || gioKet > 23 || gioDau >= gioKet) {
        printf("Gio khong hop le!\n");
        return;
    }
    
    float tien = 0;
    int gio = gioKet - gioDau;
    if (gio <= 3) tien = gio * 150000;
    else tien = 3 * 150000 + (gio - 3) * 150000 * 0.7;
    
    if (gioDau >= 14 && gioDau <= 17) tien *= 0.9;
    
    printf("Tong tien: %.0f VND\n", tien);
}

void chucNang4() {
    float kwh, tien = 0;
    printf("\n--- 4. TINH TIEN DIEN ---\n");
    printf("Nhap so kWh dien: ");
    scanf("%f", &kwh);
    if (kwh < 0) { printf("So kWh khong hop le!\n"); return; }
    
    if (kwh <= 50) tien = kwh * 1.678;
    else if (kwh <= 100) tien = 50 * 1.678 + (kwh - 50) * 1.734;
    else if (kwh <= 200) tien = 50 * 1.678 + 50 * 1.734 + (kwh - 100) * 2.014;
    else if (kwh <= 300) tien = 50 * 1.678 + 50 * 1.734 + 100 * 2.014 + (kwh - 200) * 2.536;
    else if (kwh <= 400) tien = 50 * 1.678 + 50 * 1.734 + 100 * 2.014 + 100 * 2.536 + (kwh - 300) * 2.834;
    else tien = 50 * 1.678 + 50 * 1.734 + 100 * 2.014 + 100 * 2.536 + 100 * 2.834 + (kwh - 400) * 2.927;
    
    printf("Tien dien: %.0f VND\n", tien * 1000);
}

void chucNang6() {
    double khoanVay;
    printf("\n--- 6. LAI SUAT VAY (12 THANG) ---\n");
    printf("Nhap so tien vay: ");
    scanf("%lf", &khoanVay);

    double gocPhaiTra = khoanVay / 12; 
    double laiSuat = 0.05; 

    printf("\n%-5s %-15s %-15s %-15s %-15s\n", "Ky", "Lai", "Goc", "Tong", "Con lai");

    for (int i = 1; i <= 12; i++) {
        double laiPhaiTra = khoanVay * laiSuat;
        double tongPhaiTra = laiPhaiTra + gocPhaiTra;
        khoanVay -= gocPhaiTra;

        printf("%-5d %-15.0lf %-15.0lf %-15.0lf %-15.0lf\n", 
                i, laiPhaiTra, gocPhaiTra, tongPhaiTra, khoanVay < 0 ? 0 : khoanVay);
    }
}

void chucNang8() {
    int n;
    printf("\n--- 8. XEP HANG SINH VIEN ---\n");
    printf("Nhap so luong SV: ");
    scanf("%d", &n);
    struct SinhVien sv[100];

    for (int i = 0; i < n; i++) {
        printf("\nNhap SV %d\n", i + 1);
        printf("Ten: ");
        fflush(stdin);
        gets(sv[i].hoTen);
        printf("Diem: ");
        scanf("%f", &sv[i].diem);

        if (sv[i].diem >= 9) strcpy(sv[i].hocLuc, "Xuat sac");
        else if (sv[i].diem >= 8) strcpy(sv[i].hocLuc, "Gioi");
        else if (sv[i].diem >= 6.5) strcpy(sv[i].hocLuc, "Kha");
        else if (sv[i].diem >= 5) strcpy(sv[i].hocLuc, "TB");
        else strcpy(sv[i].hocLuc, "Yeu");
    }

    // sort
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (sv[i].diem < sv[j].diem) {
                struct SinhVien t = sv[i];
                sv[i] = sv[j];
                sv[j] = t;
            }
        }
    }

    printf("\n%-20s %-10s %-10s\n", "Ten", "Diem", "Hoc Luc");
    for (int i = 0; i < n; i++) {
        printf("%-20s %.1f %-10s\n", sv[i].hoTen, sv[i].diem, sv[i].hocLuc);
    }
}

void chucNang10() {
    int tu1, mau1, tu2, mau2;
    printf("\n--- 10. TINH TOAN PHAN SO ---\n");
    printf("Nhap phan so 1 (tu mau): ");
    scanf("%d%d", &tu1, &mau1);
    printf("Nhap phan so 2 (tu mau): ");
    scanf("%d%d", &tu2, &mau2);

    if (mau1 == 0 || mau2 == 0) { printf("Mau so phai khac 0!\n"); return; }

    int tu, mau;

    // Tong
    tu = tu1 * mau2 + tu2 * mau1;
    mau = mau1 * mau2;
    int u = timUCLN(tu, mau);
    printf("Tong: %d/%d\n", tu/u, mau/u);

    // Hieu
    tu = tu1 * mau2 - tu2 * mau1;
    u = timUCLN(tu, mau);
    printf("Hieu: %d/%d\n", tu/u, mau/u);

    // Tich
    tu = tu1 * tu2;
    mau = mau1 * mau2;
    u = timUCLN(tu, mau);
    printf("Tich: %d/%d\n", tu/u, mau/u);

    // Thuong
    if (tu2 == 0) printf("Khong the chia!\n");
    else {
        tu = tu1 * mau2;
        mau = mau1 * tu2;
        u = timUCLN(tu, mau);
        printf("Thuong: %d/%d\n", tu/u, mau/u);
    }
}

// ---------------- MAIN -------------------
int main() {
    int chon;

    do {
        system("cls");
        printf("\n========= MENU =========\n");
        printf("1.  Kiem tra so nguyen\n");
        printf("2.  UCLN - BCNN\n");
        printf("3.  Tinh tien Karaoke\n");
        printf("4.  Tinh tien dien\n");
        printf("6.  Tinh lai suat vay\n");
        printf("8.  Sap xep sinh vien\n");
        printf("10. Tinh toan phan so\n");
        printf("0.  Thoat\n");
        printf("========================\n");
        printf("Nhap lua chon: ");

        if (scanf("%d", &chon) == 0) {
            fflush(stdin);
            chon = -1;
        }

        switch (chon) {
            case 1: chucNang1(); break;
            case 2: chucNang2(); break;
            case 3: chucNang3(); break;
            case 4: chucNang4(); break;
            case 6: chucNang6(); break;
            case 8: chucNang8(); break;
            case 10: chucNang10(); break;
            case 0: printf("Tam biet!\n"); return 0;
            default: printf("Lua chon sai!\n");
        }

        choNhapEnter();

    } while (1);

    return 0;
}
