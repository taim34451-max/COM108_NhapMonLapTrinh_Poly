#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// --- KHAI BÁO NGUYÊN MẪU HÀM ---
void chucNang1_KiemTraSo();
void chucNang2_UCLN_BCNN();
void chucNang3_TinhTienKaraoke();
void chucNang4_TinhTienDien();
void chucNang6_LaiSuatNganHang();
int kiemTraSoNguyenTo(int n);
int kiemTraSoChinhPhuong(int n);

// --- HÀM MAIN ---
int main() {
    int choice;
    while(1) {
        printf("\n================= MENU CHUONG TRINH ================\n");
        printf("1. Chuc nang tim tinh nguyen cua mot so\n");
        printf("2. Chuc nang tim UCLN va BCNN\n");
        printf("3. Chuc nang tinh tien quan Karaoke\n");
        printf("4. Chuc nang tinh tien dien\n");
        printf("6. Chuc nang vay tien ngan hang\n");
        printf("8. Coming soon...\n");
        printf("0. Thoat chuong trinh\n");
        printf("====================================================\n");
        printf("Moi ban chon chuc nang (0-8): ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                chucNang1_KiemTraSo();
                break;
            case 2:
                chucNang2_UCLN_BCNN();
                break;
            case 3:
                chucNang3_TinhTienKaraoke();
                break;
            case 4:
                chucNang4_TinhTienDien();
                break;
            case 6:
                chucNang6_LaiSuatNganHang();
                break;
            case 8:
                printf("\nChuc nang dang phat trien...\n");
                break;
            case 0:
                printf("\nCam on ban da su dung chuong trinh!\n");
                exit(0);
            default:
                printf("\nLua chon khong hop le! Vui long chon lai.\n");
        }
        printf("\n(Nhan Enter de tiep tuc...)");
        getchar(); getchar(); // Dung man hinh de xem ket qua
        system("cls"); // Lenh xoa man hinh (tren Windows)
    }
    return 0;
}

// --- TRIỂN KHAI CÁC HÀM CHỨC NĂNG ---

// 1. Tìm tính nguyên của một số
void chucNang1_KiemTraSo() {
    float x;
    printf("\n--- 1. KIEM TRA SO NGUYEN/NGUYEN TO/CHINH PHUONG ---\n");
    printf("Nhap vao mot so x: ");
    scanf("%f", &x);

    if (x == (int)x) {
        int n = (int)x;
        printf("%.2f la so nguyen.\n", x);
        
        if (kiemTraSoNguyenTo(n)) {
            printf("%d la so nguyen to.\n", n);
        } else {
            printf("%d khong phai la so nguyen to.\n", n);
        }

        if (kiemTraSoChinhPhuong(n)) {
            printf("%d la so chinh phuong.\n", n);
        } else {
            printf("%d khong phai la so chinh phuong.\n", n);
        }
    } else {
        printf("%.2f khong phai la so nguyen.\n", x);
    }
}

int kiemTraSoNguyenTo(int n) {
    if (n < 2) return 0;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}

int kiemTraSoChinhPhuong(int n) {
    int sq = sqrt(n);
    return (sq * sq == n);
}

// 2. Tìm UCLN và BCNN
void chucNang2_UCLN_BCNN() {
    int a, b, tempA, tempB;
    printf("\n--- 2. TIM UCLN VA BCNN ---\n");
    printf("Nhap so a: "); scanf("%d", &a);
    printf("Nhap so b: "); scanf("%d", &b);
    
    if(a == 0 || b == 0){
        printf("Khong ton tai UCLN, BCNN cho so 0.\n");
        return;
    }

    tempA = abs(a);
    tempB = abs(b);
    
    // Thuat toan Euclid tim UCLN
    while (tempA != tempB) {
        if (tempA > tempB) tempA -= tempB;
        else tempB -= tempA;
    }
    int ucln = tempA;
    int bcnn = (abs(a * b) / ucln);

    printf("Uoc chung lon nhat cua %d va %d la: %d\n", a, b, ucln);
    printf("Boi chung nho nhat cua %d va %d la: %d\n", a, b, bcnn);
}

// 3. Tính tiền quán Karaoke
void chucNang3_TinhTienKaraoke() {
    float gioBatDau, gioKetThuc, soGioChoi, tienThanhToan;
    const float GIA_TIEN_GIO = 150000;
    
    printf("\n--- 3. TINH TIEN KARAOKE ---\n");
    printf("Gio hoat dong: 12h - 23h\n");
    printf("Nhap gio bat dau: "); scanf("%f", &gioBatDau);
    printf("Nhap gio ket thuc: "); scanf("%f", &gioKetThuc);

    if (gioBatDau < 12 || gioKetThuc > 23 || gioBatDau >= gioKetThuc) {
        printf("Gio khong hop le! (Phai tu 12h-23h va gio ket thuc > gio bat dau)\n");
        return;
    }

    soGioChoi = gioKetThuc - gioBatDau;
    
    // Giam gia 30% cho moi gio ke tu gio thu 4
    if (soGioChoi <= 3) {
        tienThanhToan = soGioChoi * GIA_TIEN_GIO;
    } else {
        tienThanhToan = 3 * GIA_TIEN_GIO + (soGioChoi - 3) * GIA_TIEN_GIO * 0.7;
    }

    // Giam gia 10% tong bill neu bat dau trong khoang 14h-17h
    if (gioBatDau >= 14 && gioBatDau <= 17) {
        tienThanhToan = tienThanhToan * 0.9;
        printf("Ban duoc giam them 10%% vi hat trong khung gio vang!\n");
    }

    printf("Tong so gio choi: %.1f gio\n", soGioChoi);
    printf("Tong tien phai tra: %.0f VND\n", tienThanhToan);
}

// 4. Tính tiền điện (Theo bậc thang quy định chung)
void chucNang4_TinhTienDien() {
    float kwh, tienDien;
    printf("\n--- 4. TINH TIEN DIEN ---\n");
    printf("Nhap so kWh dien tieu thu: ");
    scanf("%f", &kwh);

    if (kwh < 0) {
        printf("So kWh khong hop le!\n");
        return;
    }

    // Bang gia dien tham khao 6 bac
    if (kwh <= 50) {
        tienDien = kwh * 1678;
    } else if (kwh <= 100) {
        tienDien = 50 * 1678 + (kwh - 50) * 1734;
    } else if (kwh <= 200) {
        tienDien = 50 * 1678 + 50 * 1734 + (kwh - 100) * 2014;
    } else if (kwh <= 300) {
        tienDien = 50 * 1678 + 50 * 1734 + 100 * 2014 + (kwh - 200) * 2536;
    } else if (kwh <= 400) {
        tienDien = 50 * 1678 + 50 * 1734 + 100 * 2014 + 100 * 2536 + (kwh - 300) * 2834;
    } else {
        tienDien = 50 * 1678 + 50 * 1734 + 100 * 2014 + 100 * 2536 + 100 * 2834 + (kwh - 400) * 2927;
    }

    printf("So tien dien phai tra (chua VAT): %.0f VND\n", tienDien);
}

// 6. Tính lãi suất vay ngân hàng (Trả góp dư nợ giảm dần)
void chucNang6_LaiSuatNganHang() {
    double soTienVay, laiSuatNam;
    int kyHan; // So thang
    
    printf("\n--- 6. TINH LAI SUAT VAY NGAN HANG (Du no giam dan) ---\n");
    printf("Nhap so tien vay (VND): "); scanf("%lf", &soTienVay);
    printf("Nhap lai suat vay (%%/nam): "); scanf("%lf", &laiSuatNam); // Vi du 12%
    printf("Nhap ky han vay (thang): "); scanf("%d", &kyHan);

    double gocPhaiTra = soTienVay / kyHan;
    double laiSuatThang = laiSuatNam / 12 / 100; // Doi ra % thang
    double tienLai, tongPhaiTra;
    double duNo = soTienVay;

    printf("\n%-5s | %-15s | %-15s | %-15s | %-15s\n", "Ky", "Lai phai tra", "Goc phai tra", "Tong phai tra", "Du no con lai");
    printf("---------------------------------------------------------------------------\n");

    for (int i = 1; i <= kyHan; i++) {
        tienLai = duNo * laiSuatThang;
        tongPhaiTra = gocPhaiTra + tienLai;
        duNo = duNo - gocPhaiTra;
        
        // Xu ly so am nho do lam tron o thang cuoi
        if (duNo < 0) duNo = 0; 

        printf("%-5d | %-15.0lf | %-15.0lf | %-15.0lf | %-15.0lf\n", 
                i, tienLai, gocPhaiTra, tongPhaiTra, duNo);
    }
}