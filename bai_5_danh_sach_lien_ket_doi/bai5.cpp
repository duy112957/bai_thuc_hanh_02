#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct SinhVien{
	char hoten[30];
	int masv;
	float diem1,diem2,diem3;
};

struct Node{
	struct SinhVien data;
	struct Node *link;
	struct Node *prev;
};

struct LList{
	struct Node *pHead;
	struct Node *pTail;
	int spt;
};

int isEmpty(struct LList l){
	return l.spt == 0;
}

void initList(struct LList *L){
	L->pHead = NULL;
	L->pTail = NULL;
	L->spt = 0;
}

void Nhap(struct SinhVien *sv){
	printf("Ho ten: ");
    scanf(" %[^\n]", sv->hoten);
    printf("Ma sinh vien: ");
    scanf("%d", &sv->masv);
    printf("Diem 1: ");
    scanf("%f", &sv->diem1);
    printf("Diem 2: ");
    scanf("%f", &sv->diem2);
    printf("Diem 3: ");
    scanf("%f", &sv->diem3);
}

void Xuat(struct SinhVien sv){
    printf("Ho ten: %s\tMa sv: %d\tDiem 1: %.2f\tDiem 2: %.2f\tDiem 3: %.2f\n",  sv.hoten, sv.masv, sv.diem1, sv.diem2, sv.diem3);
}

void insertHead(struct LList *L, struct SinhVien sv){
    struct Node *pp = (struct Node*)malloc(sizeof(struct Node));
    if(pp == NULL){
        printf("Khong du bo nho");
        return;
    }
    pp->data = sv;
    pp->prev = NULL;
    pp->link = L->pHead;
    if(isEmpty(*L)){
        L->pTail = pp;
    }else{
        L->pHead->prev = pp;
    }
    L->pHead = pp;
    L->spt++;
}

void insertTail(struct LList *L, struct SinhVien sv){
    struct Node *pp = (struct Node*)malloc(sizeof(struct Node));
    if(pp == NULL){
        printf("Khong du bo nho");
        return;
    }
    pp->data = sv;
    pp->prev = L->pTail;
    pp->link = NULL;
    if(isEmpty(*L)){
        L->pTail = pp;
        L->pHead = pp;
    }else{
        L->pTail->link = pp;
        L->pTail = pp;
    }
    L->spt++;
}

struct Node* findNode(struct LList L, int ma){
	struct Node* pp = L.pHead;
	while(pp != NULL && pp->data.masv != ma){
		pp = pp->link;
	}
	return pp;
}

void insertAfter(struct LList *L, struct SinhVien sv, int msv){
    struct Node *q = findNode(*L, msv);
    if(q == NULL){
        printf("Khong tim thay sinh vien");
        return;
    }
    struct Node *pp = (struct Node*)malloc(sizeof(struct Node));
    if(pp == NULL){
        printf("Khong du bo nho");
        return;
    }
    pp->data = sv;
    pp->prev = q;
    pp->link = q->link;
    if(q->link != NULL){
        q->link->prev = pp;
    }
    q->link = pp;
    if(q == L->pTail){
        L->pTail = pp;
    }
    L->spt++;
}

void deleteNode(struct LList *L, int msv){
    struct Node *q = findNode(*L, msv);
    if(q == NULL){
        printf("Khong tim thay sinh vien");
        return;
    }
    if(q->prev == NULL){
        L->pHead = q->link;
    }else{
        q->prev->link = q->link;
    }
    if(q->link == NULL){
        L->pTail = q->prev;
    }else{
        q->link->prev = q->prev;
    }
    free(q);
    L->spt--;
}

void deleteNodeByName(struct LList *L, char hoten[]){
    struct Node *q = L->pHead;
    while(q != NULL){
        if(strcmp(q->data.hoten, hoten) == 0){
            struct Node *temp = q;
            if(q->prev == NULL){
                L->pHead = q->link;
            }else{
                q->prev->link = q->link;
            }
            if(q->link == NULL){
                L->pTail = q->prev;
            }else{
                q->link->prev = q->prev;
            }
            q = q->link;
            free(temp);
            L->spt--;
        }else{
            q = q->link;
        }
    }
}

void processList(struct LList L) {
    struct Node *pp = L.pHead;
    if (isEmpty(L)) {
        printf("Danh sach rong!\n");
        return;
    }
    while (pp != NULL) {
        Xuat(pp->data);
        pp = pp->link;
    }
}

void freeList(struct LList *L) {
    struct Node *pp;
    while (L->pHead != NULL) {
        pp = L->pHead;
        L->pHead = L->pHead->link;
        free(pp);
    }
    L->pTail = NULL;
    L->spt = 0;
}

void swap(struct SinhVien *a, struct SinhVien *b){
    struct SinhVien temp = *a;
    *a = *b;
    *b = temp;
}

void sortByName(struct LList *L){
	struct Node *p, *q;
    for(p = L->pHead; p != NULL; p = p->link){
        for(q = p->link; q != NULL; q = q->link){
            if(strcmp(p->data.hoten, q->data.hoten) > 0){
                swap(&p->data, &q->data);
            }
        }
    }
}

void sortByMa(struct LList *L){
	struct Node *p, *q;
    for(p = L->pHead; p != NULL; p = p->link){
        for(q = p->link; q != NULL; q = q->link){
            if(p->data.masv > q->data.masv){
                swap(&p->data, &q->data);
            }
        }
    }
}

void tachDanhSach(struct LList *L, struct LList *L1, struct LList *L2){
	freeList(L1);
    freeList(L2);
	struct Node *pp = L->pHead;
	int spt1 = L->spt / 2;
	while(pp != NULL){
		if(spt1 > 0){
			spt1--;
			insertTail(L1,pp->data);
		}else{
			insertTail(L2,pp->data);
		}
		pp = pp->link;
	}
}

void ghepDanhSach(struct LList *L1, struct LList *L2){
    if(isEmpty(*L2)){
        return;
    }
    if(isEmpty(*L1)){
        L1->pHead = L2->pHead;
        L1->pTail = L2->pTail;
    }else{
        L1->pTail->link = L2->pHead;
        L2->pHead->prev = L1->pTail;
        L1->pTail = L2->pTail;
    }
    L1->spt += L2->spt;
    L2->pHead = NULL;
    L2->pTail = NULL;
    L2->spt = 0;
}



int main() {
    struct LList L,L1,L2;
    struct SinhVien x;
    int chon;
    int ma;
    char hoten[30];
    initList(&L);
    initList(&L1);
	initList(&L2);
    do {
        printf("\n===== QUAN LY SINH VIEN =====\n");
        printf("1. Them vao dau danh sach\n");
        printf("2. Them vao cuoi danh sach\n");
        printf("3: Them vao sau mot nut khac\n");
        printf("4: Tim kiem sinh vien theo ma sinh vien\n");
        printf("5: Tim kiem sinh vien theo ten sinh vien\n");
        printf("6. Xoa sinh vien theo ma\n");
        printf("7. Xoa sinh vien theo ten\n");
        printf("8. Sap xep theo ten\n");
        printf("9. Sap xep theo ma sinh vien\n");
        printf("10. Tach danh sach\n");
        printf("11. Ghep danh sach\n");
        printf("12. Duyet danh sach\n");
        printf("0. Thoat\n");
        printf("Moi ban chon: ");
        scanf("%d", &chon);
        switch (chon) {
            case 1:
                Nhap(&x);
                if (x.masv > 0) {
                    insertHead(&L, x);
                }
                break;
            case 2:
                Nhap(&x);
                if (x.masv > 0) {
                    insertTail(&L, x);
                }
                break;
            case 3:
                printf("Nhap ma sinh vien can chen sau: ");
                scanf("%d", &ma);
                printf("Nhap thong tin sinh vien moi:\n");
                Nhap(&x);
                if (x.masv > 0) {
                    insertAfter(&L, x, ma);
                }
                break;
            case 4: {
			    printf("Nhap ma sinh vien can tim: ");
			    scanf("%d", &ma);
			    struct Node *q = findNode(L, ma);
			    if (q == NULL) {
			        printf("Khong tim thay sinh vien!\n");
			        break;
			    }
			    Xuat(q->data);
			    break;
			}
			case 5: {
			    printf("Nhap ten sinh vien can tim: ");
			    getchar();
			    scanf("%[^\n]", hoten);
			    struct Node* pp = L.pHead;
				while(pp != NULL){
					if(strcmp(pp->data.hoten,hoten) == 0){
						Xuat(pp->data);
					}
					pp = pp->link;
				}
			    break;
			}
			case 6:
			    printf("Nhap ma sinh vien can xoa: ");
			    scanf("%d", &ma);
			    deleteNode(&L, ma);
		    	break;
	    	case 7: {
			   	printf("Nhap ho ten sinh vien can xoa: ");
			    scanf(" %[^\n]", hoten);
			    deleteNodeByName(&L, hoten);
			    break;
			}
			case 8:
				sortByName(&L);
				break;
			case 9:
				sortByMa(&L);
				break;
			case 10:
				tachDanhSach(&L,&L1,&L2);
				printf("Da tach thanh 2 danh sach\nDanh sach 1:\n");
				processList(L1);
				printf("Danh sach 2:\n");
				processList(L2);
				break;
			case 11:
				ghepDanhSach(&L1,&L2);
				printf("Da ghep thanh 1 danh sach\n");
				processList(L1);
				break;
            case 12:
                processList(L);
                break;
            case 0:
                printf("Bye bye!\n");
                break;
            default:
                printf("Lua chon khong hop le!\n");
        }

    } while (chon != 0);
    freeList(&L);
    freeList(&L1);
    freeList(&L2);
    return 0;
}

