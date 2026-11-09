#include <stdio.h>
#include <stdlib.h>

int main(){
	int n,m;
	scanf("%d%d", &n,&m);
	float **a;
	a = (float **)malloc(n * sizeof(float *));
	if(a == NULL){
		printf("Khong du bo nho");
		return 1;
	}
	for(int i = 0 ; i < n;i++){
		a[i] = (float *) malloc(m * sizeof(float));
		if(a[i] == NULL){
			printf("Khong du bo nho");
			return 1;
		}
	}
	for(int i = 0 ; i < n;i++){
		for(int j = 0 ; j < m;j++){
			scanf("%f",&a[i][j]);
		}
	}
	printf("Danh sach\n");
	for(int i = 0 ; i < n;i++){
		for(int j = 0 ; j < m;j++){
			printf("%.2f\t",a[i][j]);
		}
		printf("\n");
	}
	for (int i = 0; i < h; i++) {
        free(a[i]);
    }
    free(a);
	a = NULL;
	return 0;
}
