
#include <stdio.h>
#include <stdlib.h>

struct SinhVien {
    char hoten[50];
    int ma;
    float diem1, diem2, diem3;
};

int main() {
    int n;
    struct SinhVien *sv;
    printf("Nhap so luong sinh vien: ");
    scanf("%d", &n);
    sv = (struct SinhVien*)malloc(n * sizeof(struct SinhVien));
    if (sv == NULL) {
        printf("Khong du bo nho!\n");
        return 1;
    }
    for (int i = 0; i < n; i++) {
        printf("\nSinh vien thu %d:\n", i + 1);
        printf("Ho ten: ");
        scanf(" %[^\n]", sv[i].hoten);
        printf("Ma sinh vien: ");
        scanf("%d", &sv[i].ma);
        printf("Diem 1: ");
        scanf("%f", &sv[i].diem1);
        printf("Diem 2: ");
        scanf("%f", &sv[i].diem2);
        printf("Diem 3: ");
        scanf("%f", &sv[i].diem3);
    }
    printf("\nDanh sach sinh vien\n");
    for (int i = 0; i < n; i++) {
        printf("\nSinh vien thu %d:\n", i + 1);
        printf("Ho ten: %s\n", sv[i].hoten);
        printf("Ma sinh vien: %d\n", sv[i].ma);
        printf("Diem 1: %.2f\n", sv[i].diem1);
        printf("Diem 2: %.2f\n", sv[i].diem2);
        printf("Diem 3: %.2f\n", sv[i].diem3);
    }
    free(sv);
    sv = NULL;
    return 0;
}
