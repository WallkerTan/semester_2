#include <stdio.h>

// Hàm đệ quy giải bài toán Tháp Hà Nội
void towerOfHanoi(int n, char from_rod, char to_rod, char aux_rod) {
    if (n == 1) {
        printf("Di chuyển đĩa 1 từ cột %c đến cột %c\n", from_rod, to_rod);
        return;
    }
    towerOfHanoi(n - 1, from_rod, aux_rod, to_rod);
    printf("Di chuyển đĩa %d từ cột %c đến cột %c\n", n, from_rod, to_rod);
    towerOfHanoi(n - 1, aux_rod, to_rod, from_rod);
}

int main() {
    int n; // Số lượng đĩa
    printf("Nhập số lượng đĩa: ");
    scanf("%d", &n);

    // Gọi hàm giải bài toán Tháp Hà Nội
    // Các cột được đặt tên là A, B, C
    // Đĩa được di chuyển từ cột A đến cột C, sử dụng cột B làm trung gian
    towerOfHanoi(n, 'A', 'C', 'B');

    return 0;
}