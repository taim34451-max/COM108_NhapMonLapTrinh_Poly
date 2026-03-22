#include <stdio.h>
#include <math.h>

// =======================================
// ========== KHAI BÁO HÀM ===============
// =======================================

// kiểm tra số nguyên tố (trả về 1 là đúng, 0 là sai)
int laSoNguyenTo(int n);

// tìm UCLN
int timUCLN(int a, int b);

// tìm BCNN
int timBCNN(int a, int b);

// =======================================
// ========== HÀM MAIN (MENU) ============
// =======================================

int main() {
    int choice;

    do {
        // MENU chính
        printf("\n===== CHUONG TRINH TINH TOAN =====\n");
        printf("1. Kiem tra so nguyen to\n");
        printf("2. Tim UCLN va BCNN\n");
        printf("0. Thoat chuong trinh\n");
        printf("Moi ban chon chuc nang: ");
        scanf("%d", &choice);

        // xử lý lựa chọn
        switch (choice) {

            case 1: {
                int n;
                printf("Nhap mot so nguyen: ");
                scanf("%d", &n);

                if (laSoNguyenTo(n))
                    printf("%d la so nguyen to.\n", n);
                else
                    printf("%d khong la so nguyen to.\n", n);

                break;
            }

            case 2: {
                int a, b;
                printf("Nhap so thu nhat: ");
                scanf("%d", &a);
                printf("Nhap so thu hai: ");
                scanf("%d", &b);

                int ucln = timUCLN(a, b);
                int bcnn = timBCNN(a, b);

                printf("UCLN(%d, %d) = %d\n", a, b, ucln);
                printf("BCNN(%d, %d) = %d\n", a, b, bcnn);

                break;
            }

            case 0:
                printf("Dang thoat...\n");
                break;

            default:
                printf("Lua chon khong hop le, vui long chon lai!\n");
        }

    } while (choice != 0);

    return 0;
}

// =======================================
// ======= PHAN CODE CAC CHUC NANG =======
// =======================================

// Hàm kiểm tra số nguyên tố
int laSoNguyenTo(int n) {
    if (n < 2) return 0;  // số nhỏ hơn 2 không phải số nguyên tố

    // chỉ cần chạy tới sqrt(n)
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0)
            return 0;   // chia hết → không phải số nguyên tố
    }
