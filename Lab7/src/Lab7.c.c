#include <stdio.h>
#include <string.h>
#include <ctype.h> // Thư viện cần thiết để xử lý chữ hoa/thường

int main() {
    // Khai báo biến
    char str[100]; // Tăng kích thước lên 100 cho thoải mái nhập
    char kt;
    int demKyTu = 0; // Biến đếm phải khởi tạo bằng 0
    int i;

    // Nhập chuỗi
    printf("Nhap chuoi bat ky: ");
    fgets(str, sizeof(str), stdin); 
    
    // fgets sẽ lấy cả phím Enter (\n) ở cuối, dòng này để xóa nó đi cho đẹp (tùy chọn)
    str[strcspn(str, "\n")] = 0; 

    puts(str); // In lại chuỗi (nếu muốn kiểm tra)

    // Nhập ký tự cần tìm
    printf("Nhap ky tu muon tim trong chuoi: ");
    scanf("%c", &kt);

    // --- PHẦN LOGIC CẦN THÊM ---
    for (i = 0; i < strlen(str); i++) {
        // So sánh kí tự ở vị trí i với kt
        // Dùng tolower để đưa cả 2 về chữ thường -> so sánh không phân biệt hoa/thường
        if (tolower(str[i]) == tolower(kt)) {
            demKyTu++;
        }
    }

    // --- PHẦN XUẤT KẾT QUẢ ---
    if (demKyTu > 0) {
        printf("Ky tu '%c' xuat hien %d lan trong chuoi.\n", kt, demKyTu);
    } 
    else {
        printf("Khong tim thay ky tu '%c' trong chuoi \"%s\".\n", kt, str);
    }

    return 0;
}