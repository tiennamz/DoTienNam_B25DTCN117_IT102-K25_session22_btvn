#include<stdio.h>
#include<string.h>
#define MAX 50
typedef struct {
    char name[50];
    char phoneNumber[15];
    char email[50];
}phone;
phone listPhone[MAX];
int n_phone=0;
void add();
void display();
void search();
void deletePhone();
int main() {
    do {
        int choice;
        printf("\n1.them lien he moi\n");
        printf("2.hien thi tat ca danh ba\n");
        printf("3.tim kiem theo ten\n");
        printf("4.xoa lien he theo ten\n");
        printf("\n");
        printf("nhap lua chon: ");
        scanf("%d", &choice);
        fflush(stdin);
        getchar();
        switch (choice) {
            case 1:
                add();
                break;
            case 2:
                display();
                break;
            case 3:
                search();
                break;
            case 4:
                deletePhone();
                break;
        }

    }while (1);

}

void add() {
    int n_add;
    do {
        printf("nhap so nguoi muon them: ");
        scanf("%d",&n_add);
        fflush(stdin);
        if (n_add <= 0) {
            printf("khong hop le\n");
        }

    }while (n_add <= 0);

    for (int i=0;i<n_add;i++) {

        printf("nhap ten thu %d: ",i+1);
        gets(listPhone[n_phone].name);

        printf("nhap so dien thoai:");
        gets(listPhone[n_phone].phoneNumber);

        printf("nhap email: ");
        gets(listPhone[n_phone].email);

        n_phone++;

    }

}

void display() {

    for (int i=0;i<79;i++) {
        printf("-");
    }
        printf("\n|%-30s|%-15s|%-30s|\n","ho va ten","so dien thoai","email");
    for (int i=0;i<79;i++) {
        printf("-");
    }
    for (int i=0;i<n_phone;i++) {
        printf("\n|%-30s|%-15s|%-30s|\n",listPhone[i].name,listPhone[i].phoneNumber,listPhone[i].email);

    for (int i=0;i<79;i++) {
        printf("-");
    }
    }
}
void search() {
char nameSearch[50];
    int found=0;
    printf("nhap ten can tim: ");
    gets(nameSearch);
    for (int i=0;i<n_phone;i++) {
        if (strcmp(listPhone[i].name,nameSearch)==0) {
            printf("tim thay %s sdt %s email %s",nameSearch,listPhone[i].phoneNumber,listPhone[i].email);
            found=1;
        }

        }

if (found==0) {
            printf("khong tim thay");
}
}
    void deletePhone() {
    char nameSearch[50];
    int found=0;
    printf("nhap ten can xoa: ");
    gets(nameSearch);
    for (int i=0;i<n_phone;i++) {
        if (strcmp(listPhone[i].name,nameSearch)==0) {
            for (int j=i;j<n_phone-1;j++) {
                listPhone[j]=listPhone[j+1];
            }
            found=1;
            n_phone--;
            break;
        }
    }
    if (found==0) {
        printf("khong thay ten de xoa");
    }
}