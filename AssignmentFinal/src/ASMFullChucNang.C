#include <stdio.h>
#include <stdlib.h> // Thu vien cho rand() va system()
#include <time.h>   // Thu vien cho thoi gian
#include <math.h>   // Thu vien toan hoc
#include <string.h> // Thu vien xu ly chuoi

// --- CAC HAM BO TRO (HELPER) ---

// Ham tim UCLN de rut gon phan so (dung cho chuc nang 10)
int timUCLN(int a, int b) {
    a = abs(a); b = abs(b); // Lay gia tri tuyet doi
    while (a != b) {
        if (a > b) a = a - b;
        else b = b - a;
    }
    return a;
}

// Struct sinh vien cho chuc nang 8
struct SinhVien {
    char hoTen[50];
    float diem;
    char hocLuc[20];
};

// --- KHOI HAM CHUC NANG CU (1-3) ---

void chucNang1() {
    float n;
    printf("\n--- 1. KIEM TRA SO NGUYEN ---\n");
    printf("Nhap mot so: ");
    scanf("%f", &n);

    if (n == (int)n) {
        int x = (int)n;
        printf("-> %.0f la so nguyen.\n", n);

        // Kiem tra nguyen to
        int dem = 0;
        if (x < 2) printf("-> %d khong phai so nguyen to.\n", x);
        else {
            for (int i = 2; i <= sqrt(x); i++) {
                if (x % i == 0) { dem++; break; }
            }
            if (dem == 0) printf("-> %d la so nguyen to.\n", x);
            else printf("-> %d khong phai so nguyen to.\n", x);
        }

        // Kiem tra chinh phuong
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
    if(a<=0 || b<=0) { printf("Nhap so duong!\n"); return; }
    
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

// --- KHOI HAM CHUC NANG MOI (4-10) ---

// Chuc nang 4: Tinh tien dien (Bac thang)
void chucNang4() {
    float kwh, tien = 0;
    printf("\n--- 4. TINH TIEN DIEN ---\n");
    printf("Nhap so kWh dien tieu thu: ");
    scanf("%f", &kwh);

    if (kwh < 0) {
        printf("So kWh khong hop le!\n");
        return;
    }

    // Tinh theo cac bac trong bang
    if (kwh <= 50) {
        tien = kwh * 1.678;
    } else if (kwh <= 100) {
        tien = 50 * 1.678 + (kwh - 50) * 1.734;
    } else if (kwh <= 200) {
        tien = 50 * 1.678 + 50 * 1.734 + (kwh - 100) * 2.014;
    } else if (kwh <= 300) {
        tien = 50 * 1.678 + 50 * 1.734 + 100 * 2.014 + (kwh - 200) * 2.536;
    } else if (kwh <= 400) {
        tien = 50 * 1.678 + 50 * 1.734 + 100 * 2.014 + 100 * 2.536 + (kwh - 300) * 2.834;
    } else {
        tien = 50 * 1.678 + 50 * 1.734 + 100 * 2.014 + 100 * 2.536 + 100 * 2.834 + (kwh - 400) * 2.927;
    }

    printf("So tien dien can tra: %.3f nghin dong (hoac %.0f dong)\n", tien, tien * 1000);
}

// Chuc nang 5: Doi tien (Thuat toan tham lam - lay to to nhat truoc)
void chucNang5() {
    int tien;
    int menhGia[] = {500, 200, 100, 50, 20, 10, 5, 2, 1};
    int soLuongMenhGia = 9; // Co 9 loai tien

    printf("\n--- 5. DOI TIEN ---\n");
    printf("Nhap so tien can doi: ");
    scanf("%d", &tien);

    if (tien <= 0) {
        printf("So tien phai > 0\n");
        return;
    }

    printf("Ket qua doi tien:\n");
    for (int i = 0; i < soLuongMenhGia; i++) {
        int soTo = tien / menhGia[i]; // Tinh xem doi duoc bao nhieu to nay
        if (soTo > 0) {
            printf("%d to menh gia %d\n", soTo, menhGia[i]);
            tien = tien % menhGia[i]; // So tien con lai sau khi da doi
        }
    }
}

// Chuc nang 6: Tinh lai suat vay ngan hang (Giam dan)
void chucNang6() {
    double khoanVay;
    printf("\n--- 6. TINH LAI SUAT VAY (12 THANG) ---\n");
    printf("Nhap so tien vay: ");
    scanf("%lf", &khoanVay);

    double gocPhaiTra = khoanVay / 12; // Co dinh
    double laiSuat = 0.05; // 5%

    printf("\n%-5s %-15s %-15s %-15s %-15s\n", "Ky", "Lai phai tra", "Goc phai tra", "Tong phai tra", "Con lai");
    
    for (int i = 1; i <= 12; i++) {
        double laiPhaiTra = khoanVay * laiSuat;
        double tongPhaiTra = laiPhaiTra + gocPhaiTra;
        khoanVay = khoanVay - gocPhaiTra; // Tru dan goc
        
        // In ra bang, %.0lf la in so thuc khong lay so thap phan
        printf("%-5d %-15.0lf %-15.0lf %-15.0lf %-15.0lf\n", 
               i, laiPhaiTra, gocPhaiTra, tongPhaiTra, khoanVay < 0 ? 0 : khoanVay);
    }
}

// Chuc nang 7: Vay tien mua xe
void chucNang7() {
    float phanTramVay;
    double giaXe = 500000000; // 500 trieu
    printf("\n--- 7. VAY TIEN MUA XE (FIXED 500Tr) ---\n");
    printf("Nhap % phan tram vay toi da (VD: 80): ");
    scanf("%f", &phanTramVay);

    double soTienVay = giaXe * (phanTramVay / 100);
    double soTienTraTruoc = giaXe - soTienVay;
    
    // De bai: 24 nam, Lai suat 7.2%/nam
    int thoiHanThang = 24 * 12; 
    double laiSuatThang = 0.072 / 12; // 7.2% chia 12 thang
    double gocHangThang = soTienVay / thoiHanThang;

    printf("So tien tra truoc: %.0lf VND\n", soTienTraTruoc);
    printf("So tien vay: %.0lf VND\n", soTienVay);
    printf("Bang ke hoach tra no (Hien thi rut gon 12 thang dau):\n");
    
    printf("\n%-5s %-15s %-15s %-15s %-15s\n", "Thang", "Lai", "Goc", "Phai Tra", "Du No Con");

    // Chi in dai dien 12 thang dau tien vi 24 nam (288 thang) qua dai
    double duNo = soTienVay;
    for (int i = 1; i <= 12; i++) {
        double lai = duNo * laiSuatThang;
        double tong = lai + gocHangThang;
        duNo -= gocHangThang;
        printf("%-5d %-15.0lf %-15.0lf %-15.0lf %-15.0lf\n", i, lai, gocHangThang, tong, duNo);
    }
    printf("... (Con tiep den thang %d) ...\n", thoiHanThang);
}

// Chuc nang 8: Sap xep thong tin sinh vien
void chucNang8() {
    int n;
    printf("\n--- 8. XEP HANG SINH VIEN ---\n");
    printf("Nhap so luong sinh vien: ");
    scanf("%d", &n);

    // Tao mang cac struct sinh vien
    struct SinhVien sv[100]; // Toi da 100 sv

    // Nhap thong tin
    for (int i = 0; i < n; i++) {
        printf("Nhap ten SV thu %d: ", i + 1);
        fflush(stdin); // Xoa bo dem ban phim
        gets(sv[i].hoTen); // Nhap chuoi co dau cach
        
        printf("Nhap diem SV thu %d: ", i + 1);
        scanf("%f", &sv[i].diem);

        // Xep loai hoc luc ngay khi nhap
        if (sv[i].diem >= 9) strcpy(sv[i].hocLuc, "Xuat sac");
        else if (sv[i].diem >= 8) strcpy(sv[i].hocLuc, "Gioi");
        else if (sv[i].diem >= 6.5) strcpy(sv[i].hocLuc, "Kha");
        else if (sv[i].diem >= 5) strcpy(sv[i].hocLuc, "Trung binh");
        else strcpy(sv[i].hocLuc, "Yeu");
    }

    // Sap xep (Noi bot - Bubble Sort)
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (sv[i].diem < sv[j].diem) { // So sanh diem de doi cho
                struct SinhVien tam = sv[i];
                sv[i] = sv[j];
                sv[j] = tam;
            }
        }
    }

    // Xuat thong tin
    printf("\n%-20s %-10s %-15s\n", "Ho Ten", "Diem", "Hoc Luc");
    for (int i = 0; i < n; i++) {
        printf("%-20s %-10.1f %-15s\n", sv[i].hoTen, sv[i].diem, sv[i].hocLuc);
    }
}

// Chuc nang 9: Game FPOLY-LOTT
void chucNang9() {
    int so1, so2;
    printf("\n--- 9. GAME FPOLY-LOTT (01-15) ---\n");
    
    // Nhap so tu nguoi choi
    do {
        printf("Nhap so thu 1 (1-15): "); scanf("%d", &so1);
        printf("Nhap so thu 2 (1-15): "); scanf("%d", &so2);
        if (so1 < 1 || so1 > 15 || so2 < 1 || so2 > 15)
            printf("So phai tu 1 den 15. Nhap lai!\n");
    } while (so1 < 1 || so1 > 15 || so2 < 1 || so2 > 15);

    // Sinh so ngau nhien
    srand(time(0)); // Khoi tao hat giong ngau nhien theo thoi gian
    int kq1 = rand() % 15 + 1;
    int kq2 = rand() % 15 + 1;
    
    // Dam bao 2 so ket qua khac nhau (Luat xo so thuong la khac nhau)
    while (kq2 == kq1) {
        kq2 = rand() % 15 + 1;
    }

    printf("Ket qua xo so hom nay: %02d - %02d\n", kq1, kq2);

    // Kiem tra ket qua
    int dem = 0;
    if (so1 == kq1 || so1 == kq2) dem++;
    if (so2 == kq1 || so2 == kq2) dem++;

    if (dem == 2) printf("Chuc mung ban da trung GIAI NHAT!\n");
    else if (dem == 1) printf("Chuc mung ban da trung GIAI NHI!\n");
    else printf("Chuc ban may man lan sau!\n");
}

// Chuc nang 10: Tinh toan phan so
void chucNang10() {
    int tu1, mau1, tu2, mau2;
    printf("\n--- 10. TINH TOAN PHAN SO ---\n");
    printf("Nhap phan so 1 (tu mau): ");
    scanf("%d%d", &tu1, &mau1);
    printf("Nhap phan so 2 (tu mau): ");
    scanf("%d%d", &tu2, &mau2);

    if (mau1 == 0 || mau2 == 0) {
        printf("Mau so phai khac 0!\n");
        return;
    }

    // Tong
    int tuTong = tu1 * mau2 + tu2 * mau1;
    int mauTong = mau1 * mau2;
    int ucln = timUCLN(tuTong, mauTong);
    printf("Tong: %d/%d\n", tuTong/ucln, mauTong/ucln);

    // Hieu
    int tuHieu = tu1 * mau2 - tu2 * mau1;
    int mauHieu = mau1 * mau2;
    ucln = timUCLN(tuHieu, mauHieu);
    printf("Hieu: %d/%d\n", tuHieu/ucln, mauHieu/ucln);

    // Tich
    int tuTich = tu1 * tu2;
    int mauTich = mau1 * mau2;
    ucln = timUCLN(tuTich, mauTich);
    printf("Tich: %d/%d\n", tuTich/ucln, mauTich/ucln);

    // Thuong
    if (tu2 == 0) printf("Khong the chia (tu so thu 2 bang 0)!\n");
    else {
        int tuThuong = tu1 * mau2;
        int mauThuong = mau1 * tu2;
        ucln = timUCLN(tuThuong, mauThuong);
        printf("Thuong: %d/%d\n", tuThuong/ucln, mauThuong/ucln);
    }
}

// --- MAIN ---
int main() {
    int chon;
    do {
        printf("\n========= ASSIGNMENT ========\n");
        printf("1. Kiem tra so nguyen\n");
        printf("2. UCLN va BCNN\n");
        printf("3. Tinh tien Karaoke\n");
        printf("4. Tinh tien dien\n");
        printf("5. Doi tien\n");
        printf("6. Lai suat vay ngan hang\n");
        printf("7. Vay tien mua xe\n");
        printf("8. Sap xep sinh vien\n");
        printf("9. Game FPOLY-LOTT\n");
        printf("10. Tinh toan phan so\n");
        printf("0. Thoat\n");
        printf("=============================\n");
        printf("Moi chon chuc nang: ");
        scanf("%d", &chon);

        switch(chon) {
            case 1: chucNang1(); break;
            case 2: chucNang2(); break;
            case 3: chucNang3(); break;
            case 4: chucNang4(); break;
            case 5: chucNang5(); break;
            case 6: chucNang6(); break;
            case 7: chucNang7(); break;
            case 8: chucNang8(); break;
            case 9: chucNang9(); break;
            case 10: chucNang10(); break;
            case 0: printf("Tam biet!\n"); break;
            default: printf("Chon sai, moi chon lai!\n");
        }
        
        // Dung man hinh de xem ket qua (Tuy chon)
        // printf("Bam Enter de tiep tuc...");
        // fflush(stdin); getchar();

    } while (chon != 0);

    return 0;
}