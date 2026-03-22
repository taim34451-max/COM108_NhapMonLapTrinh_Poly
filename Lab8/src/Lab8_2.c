#include <stdio.h>
#include <string.h>

// Kiểu dữ liệu SinhVien từ Bài 1
struct SinhVien {
    char maSV[20];
    char hoTen[50];
    float diem;
};

// Hàm xác định xếp loại
const char* xepLoai(float diem) {
    if (diem < 5) return "KXL";
    else if (diem < 7) return "Trung bình";
    else if (diem < 8) return "Khá";
    else if (diem < 9) return "Giỏi";
    else return "Xuất sắc";
}

int main() {
    struct SinhVien SD21301[39];
    int n;

    // Nhập số lượng sinh viên
    printf("Nhap so sinh vien (toi da 39): ");
    scanf("%d", &n);
    getchar(); // xoá ký tự '\n' còn lại

    // Nhập thông tin từng sinh viên
    for (int i = 0; i < n; i++) {
        printf("\n--- Sinh vien %d ---\n", i + 1);

        printf("Ma SV: ");
        fgets(SD21301[i].maSV, sizeof(SD21301[i].maSV), stdin);

        printf("Ho ten: ");
        fgets(SD21301[i].hoTen, sizeof(SD21301[i].hoTen), stdin);

        printf("Diem: ");
        scanf("%f", &SD21301[i].diem);
        getchar(); // xoá '\n'
    }

    // Xuất danh sách họ tên + xếp loại
    printf("\n===== DANH SACH XEP LOAI =====\n");
    for (int i = 0; i < n; i++) {
        printf("%d. %s- Xep loai: %s\n",
               i + 1,
               SD21301[i].hoTen,
               xepLoai(SD21301[i].diem));
    }

    return 0;
}
