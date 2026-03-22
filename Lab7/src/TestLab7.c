#include <stdio.h>
#include <string.h>

int main() {
    // 1. Khai báo tài khoản và mật khẩu đúng (Lưu trong máy)
    // Bạn có thể sửa nội dung trong ngoặc kép tùy ý
    char sysUser[] = "Mai Thành Tài";    
    char sysPass[] = "lololo";

    // 2. Khai báo biến để nhận dữ liệu người dùng nhập vào
    char inputUser[50];
    char inputPass[50];
 
    printf("=== CHUONG TRINH DANG NHAP ===\n");

    // 3. Nhập Username
    printf("Nhap Username: ");
    fgets(inputUser, sizeof(inputUser), stdin);
    // Xóa ký tự xuống dòng (\n) do fgets để lại
    inputUser[strcspn(inputUser, "\n")] = 0; 

    // 4. Nhập Password
    printf("Nhap Password: ");
    fgets(inputPass, sizeof(inputPass), stdin);
    // Xóa ký tự xuống dòng (\n) do fgets để lại
    inputPass[strcspn(inputPass, "\n")] = 0; 

    // 5. Kiểm tra đăng nhập
    // strcmp(a, b) == 0 nghĩa là chuỗi a giống hệt chuỗi b
    if (strcmp(inputUser, sysUser) == 0 && strcmp(inputPass, sysPass) == 0) {
        printf("\n=> THONG BAO: Dang nhap thanh cong!\n");
        printf("Chao mung %s quay tro lai.\n", inputUser);
    } else {
        printf("\n=> CANH BAO: Dang nhap that bai!\n");
        printf("Username hoac Password khong dung.\n");
    }

    return 0;
}