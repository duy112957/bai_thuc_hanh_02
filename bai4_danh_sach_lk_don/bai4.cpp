#include <stdio.h>
#include <stdlib.h>

struct SinhVien {
    char hoten[30];
    int masv;
    float d1, d2, d3;
};

struct Node {
    struct SinhVien data;
    struct Node *link;
};

struct LList {
    struct Node *pHead;
    struct Node *pTail;
    int spt;
};

void initList(struct LList *L) {
    L->pHead = NULL;
    L->pTail = NULL;
    L->spt = 0;
}

int emptyList(struct LList L) {
    return L.spt == 0;
}

void nhap(struct SinhVien *x) {
    printf("Nhap ma sinh vien: ");
    scanf("%d", &x->masv);
    printf("Nhap ho ten: ");
    scanf(" %[^\n]", x->hoten);
    printf("Nhap diem mon 1: ");
    scanf("%f", &x->d1);
    printf("Nhap diem mon 2: ");
    scanf("%f", &x->d2);
    printf("Nhap diem mon 3: ");
    scanf("%f", &x->d3);
}

void in(struct SinhVien x) {
     printf("Ten: %s, Ma: %d, Diem 1: %.2f, Diem 2: %.2f, Diem 2: %.2f\n", x.hoten, x.masv, x.d1, x.d2, x.d3);
}

void insert_Head(struct LList *L, struct SinhVien x) {
    struct Node *pp;
    pp = (struct Node*)malloc(sizeof(struct Node));
    if (pp == NULL) {
        printf("Khong du bo nho!\n");
        return;
    }
    pp->data = x;
    pp->link = L->pHead;
    if (emptyList(*L)) {
        L->pTail = pp;
    }
    L->pHead = pp;
    L->spt++;
}

void insert_Tail(struct LList *L, struct SinhVien x) {
    struct Node *pp;
    pp = (struct Node*)malloc(sizeof(struct Node));
    if (pp == NULL) {
        printf("Khong du bo nho!\n");
        return;
    }
    pp->data = x;
    pp->link = NULL;
    if (emptyList(*L)) {
        L->pHead = pp;
        L->pTail = pp;
    } else {
        L->pTail->link = pp;
        L->pTail = pp;
    }
    L->spt++;
}

void insert_After(struct LList *L, int ma, struct SinhVien x) {
    struct Node *q = L->pHead;
    while (q != NULL && q->data.masv != ma) {
        q = q->link;
    }
    if (q == NULL) {
        printf("Khong tim thay sinh vien!\n");
        return;
    }
    struct Node *pp = (struct Node*)malloc(sizeof(struct Node));
    if (pp == NULL) {
        printf("Khong du bo nho!\n");
        return;
    }
    pp->data = x;
    pp->link = q->link;
    q->link = pp;
    if (q == L->pTail) {
        L->pTail = pp;
    }
    L->spt++;
}

void processList(struct LList L) {
    struct Node *pp = L.pHead;
    if (emptyList(L)) {
        printf("Danh sach rong!\n");
        return;
    }
    while (pp != NULL) {
        in(pp->data);
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

int main() {
    struct LList L;
    struct SinhVien x;
    int chon;
    int ma;
    initList(&L);
    do {
        printf("\n===== QUAN LY SINH VIEN =====\n");
        printf("1. Them vao dau danh sach\n");
        printf("2. Them vao cuoi danh sach\n");
        printf("3: Them vao sau mot nut khac\n");
        printf("9. Duyet danh sach\n");
        printf("0. Thoat\n");
        printf("Moi ban chon: ");
        scanf("%d", &chon);
        switch (chon) {
            case 1:
                nhap(&x);
                if (x.masv > 0) {
                    insert_Head(&L, x);
                }
                break;
            case 2:
                nhap(&x);
                if (x.masv > 0) {
                    insert_Tail(&L, x);
                }
                break;
            case 3:
                printf("Nhap ma sinh vien can chen sau: ");
                scanf("%d", &ma);
                printf("Nhap thong tin sinh vien moi:\n");
                nhap(&x);
                if (x.masv > 0) {
                    insert_After(&L, ma, x);
                }
                break;
            case 9:
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
    return 0;
}
