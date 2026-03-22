#include <stdio.h>   // thư viện nhập xuất: printf, scanf
#include <math.h>    // thư viện toán học: sqrt(), pow()

// --------------------- MENU ---------------------
// Hàm này chỉ hiện menu cho người dùng chọn chức năng
void menu() {
    printf("\n=============== MENU CHUC NANG ===============\n");
    printf("1. Kiem tra tinh chat cua so (nguyen, thuc, nguyen to, chinh phuong)\n");
    printf("2. Tinh UCLN va BCNN (theo cach tru dan)\n");
    printf("3. Tinh tien Karaoke (don gia theo gio)\n");
    printf("4. Tinh tien dien (bieu gia bac thang)\n");
    printf("6. Tinh tien vay ngan hang lai don (lai * thang)\n");
    printf("8. Dang cap nhat...\n");
    printf("0. Thoat chuong trinh\n");
    printf("==============================================\n");
    printf("Nhap lua chon: ");  // người dùng nhập số
}

int main() {

    int luachon;  // biến lưu lựa chọn menu

    // dùng vòng lặp để chạy lại menu sau mỗi chức năng
    do {
        menu();               // gọi hàm in menu
        scanf("%d", &luachon); // nhập lựa chọn

        // =======================================================
        // =============== CHUC NANG 1 ============================
        // kiểm tra tính chất của 1 số
        // =======================================================
        if (luachon == 1) {

            float x;  // dùng float để nhận cả số thực lẫn số nguyên
            printf("Nhap so x: ");
            scanf("%f", &x);

            // Cách nhận biết số nguyên: nếu nó bằng chính nó dạng int
            if (x == (int)x) {
                int n = (int)x;     // ép kiểu float -> int
                printf("%d la so nguyen\n", n);

                // ---- Kiểm tra số chính phương ----
                // Ý tưởng: căn bậc 2 của n nếu bình phương lại bằng n ⇒ chính phương
                int k = sqrt(n);
                if (k * k == n) {
                    printf("%d la so chinh phuong\n", n);
                } else {
                    printf("%d khong phai so chinh phuong\n", n);
                }

                // ---- Kiểm tra số nguyên tố ----
                // Số nguyên tố chỉ có 2 ước: 1 và chính nó
                int dem = 0;
                for (int i = 1; i <= n; i++) {
                    if (n % i == 0) { // nếu i chia hết n
                        dem++;
                    }
                }

                if (dem == 2)
                    printf("%d la so nguyen to\n", n);
                else
                    printf("%d khong phai so nguyen to\n", n);

            } else {
                // Nếu không phải số nguyên
                printf("%.2f la so thuc\n", x);
            }
                // Dừng màn hình
                printf("\nNhap 1 de quay lai menu, 0 de thoat: ");
                scanf("%d", &luachon);
                break;
            }


        // =======================================================
        // =============== CHUC NANG 2 ============================
        // Tính UCLN và BCNN theo cách trừ dần
        // =======================================================
        else if (luachon == 2) {

            int a, b;
            printf("Nhap a: ");
            scanf("%d", &a);
            printf("Nhap b: ");
            scanf("%d", &b);

            // Sao chép để lát còn tính BCNN
            int x = a;
            int y = b;

            // Thuật toán: Trừ số lớn cho số nhỏ, lặp lại cho đến khi bằng nhau
            while (x != y) {
                if (x > y) {
                    x = x - y;  // nếu x lớn hơn thì trừ y
                } else {
                    y = y - x;  // ngược lại
                }
            }

            int ucln = x;              // khi x == y chính là UCLN
            int bcnn = (a * b) / ucln; // công thức tính BCNN

            printf("UCLN = %d\n", ucln);
            printf("BCNN = %d\n", bcnn);
             // Dừng màn hình
                printf("\nNhap 1 de quay lai menu, 0 de thoat: ");
                scanf("%d", &luachon);
                break;
        }


        // =======================================================
        // =============== CHUC NANG 3 ============================
        // Tính tiền karaoke dựa trên số giờ
        // =======================================================
        else if (luachon == 3) {

            int bd, kt;  // thời gian bắt đầu - kết thúc
            printf("Gio bat dau: ");
            scanf("%d", &bd);

            printf("Gio ket thuc: ");
            scanf("%d", &kt);

            // Kiểm tra hợp lệ giờ (0 - 24)
            if (bd < 0 || kt > 24 || kt <= bd) {
                printf("Du lieu khong dung!\n");
            } else {
                int sogio = kt - bd;  // số giờ sử dụng
                int tien;            // tiền phải trả

                // Mức giá: 3h đầu 150k, sau đó 120k
                if (sogio <= 3) {
                    tien = sogio * 150000;
                } else {
                    tien = 3 * 150000 + (sogio - 3) * 120000;
                }

                printf("Tien Karaoke = %d VND\n", tien);
            }
             // Dừng màn hình
                printf("\nNhap 1 de quay lai menu, 0 de thoat: ");
                scanf("%d", &luachon);
                break;
        }


        // =======================================================
        // =============== CHUC NANG 4 ============================
        // Tính tiền điện theo số kW (bậc thang)
        // =======================================================
        else if (luachon == 4) {

            int kw;
            printf("Nhap so kW: ");
            scanf("%d", &kw);

            float tien;  // lưu số tiền phải trả

            // Bậc thang:
            // 0 - 50 kWh : 1678
            // 51 - 100    : 1734
            // >100        : 2014

            if (kw <= 50)
                tien = kw * 1678;
            else if (kw <= 100)
                tien = 50 * 1678 + (kw - 50) * 1734;
            else
                tien = 50 * 1678 + 50 * 1734 + (kw - 100) * 2014;

            printf("Tien dien = %.0f VND\n", tien);
             // Dừng màn hình
                printf("\nNhap 1 de quay lai menu, 0 de thoat: ");
                scanf("%d", &luachon);
                break;
        }


        // =======================================================
        // =============== CHUC NANG 6 ============================
        // Tính tiền vay ngân hàng (lãi đơn)
        // Công thức: tiền lãi = gốc * (lãi suất %) * số tháng
        // =======================================================
        else if (luachon == 6) {

            float goc, lai;
            int thang;

            printf("Tien vay: ");
            scanf("%f", &goc);

            printf("Lai suat (%%/thang): ");
            scanf("%f", &lai);   // lãi suất tính theo %

            printf("So thang: ");
            scanf("%d", &thang);

            // tính tổng tiền
            float laithang = goc * (lai / 100) * thang; // tiền lãi
            float tong = goc + laithang;               // tổng phải trả

            printf("Tong tien phai tra = %.0f VND\n", tong);
        }


        else if (luachon == 8) {
            printf("Tinh nang dang cap nhat...\n");
        }

        else if (luachon == 0) {
            printf("Thoat chuong trinh...\n");
        }

        else {
            printf("Lua chon khong hop le!\n");
        }

    } while (luachon != 0);  // vòng lặp menu dừng khi người dùng nhập 0

     // Dừng màn hình
                printf("\nNhap 1 de quay lai menu, 0 de thoat: ");
                scanf("%d", &luachon);
return 0;
}
