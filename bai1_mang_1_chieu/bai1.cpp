#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    float *a;
    printf("Nhap so phan tu: ");
    scanf("%d", &n);
    a = (float*)malloc(n * sizeof(float));
    for (int i = 0; i < n; i++) {
        scanf("%f", a + i);
    }
    printf("\nMang vua nhap la: ");
    for (int i = 0; i < n; i++) {
        printf("%.2f ", *(a + i));
    }
    free(a);
    a = NULL;
    return 0;
}
