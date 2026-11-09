#include <stdio.h>
#include <stdlib.h>
struct SinhVien{
	char hoten[30];
	int masv;
	float diem1,diem2,diem3;
};
int main(){
	int n;
	scanf("%d", &n);
	struct SinhVien *a;
	a = (struct SinhVien*)malloc(n * sizeof(struct SinhVien));
	if (a == NULL) {
        printf("Khong du bo nho!\n");
        return 1;
    }
	for(int i = 0 ; i < n ;i++){
		printf("Sinh vien thu %d:\n", i + 1);
        printf("Ho ten: ");
        scanf(" %[^\n]", a[i].hoten);
        printf("Ma sinh vien: ");
        scanf("%d", &a[i].masv);
        printf("Diem 1: ");
        scanf("%f", &a[i].diem1);
        printf("Diem 2: ");
        scanf("%f", &a[i].diem2);
        printf("Diem 3: ");
        scanf("%f", &a[i].diem3);
	}
	printf("Danh sach vua nhap\n");
	for(int i = 0 ; i < n ;i++){
		printf("%s %d %.2f %.2f %.2f\n",a[i].hoten,a[i].masv,a[i].diem1,a[i].diem2,a[i].diem3);
	}
	free(a);
	a = NULL;
	return 0;
}
