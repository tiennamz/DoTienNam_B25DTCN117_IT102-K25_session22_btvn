#include<stdio.h>
#include <stdlib.h>
#include<string.h>
#define MAX 100
typedef struct dirthdayStruct{
    int day;
    int month;
    int year;
}birthday;
typedef struct studentStruct {
    char id[13];
    char name[50];
    birthday birthday;
    char address[50];
    char phone[15];

}student;
student listStudent[MAX];
int n_student;
int check=0;
void inputStudent();
void displayStudent();
void addStudent();
void deleteStudent();
void updateStudent();
void sortStudent();
void searchStudent();
int exitedId(char id[]);
int exitedPhone(char phone[]);
int checkDay(int day, int month, int year);
int checkMonth(int month);
int checkYear(int year);
int main() {
    int choice;
do{

    printf("\n1.Nhap thong tin sinh vien.\n");
    printf("2.Hien thi thong tin sinh vien.\n");
    printf("3.Them sinh vien vao cuoi danh sach.\n");
    printf("4.Xoa sinh vien theo ma sinh vien.\n");
    printf("5.Cap nhat thong tin sinh vien theo ma sinh vien.\n");
    printf("6.Sap xep sinh vien theo ho ten (A-Z).\n");
    printf("7.Tim kiem sinh vien theo ma sinh vien.\n");
    printf("8.thoat\n");

    printf("nhap lua chon: ");
    scanf("%d",&choice);
    fflush(stdin);
    switch(choice) {
        case 1:
            inputStudent();
            break;
        case 2:
            displayStudent();
            break;
        case 3:
            addStudent();
            break;
        case 4:
            deleteStudent();
            break;
        case 5:
            updateStudent();
            break;
        case 6:
            sortStudent();
            break;
        case 7 :
            searchStudent();
            break;
        case 8:
            printf("cam on da su dung");
            exit(0);
            default:
    printf("loi\n ");
    }

}while(1);
}

void inputStudent() {
    do {
        printf("nhap so sinh vien can them: ");
        scanf("%d",&n_student);
        fflush(stdin);
            if (n_student>MAX || n_student<1) {
                printf("moi ban nhap lai\n");
            }
    }while (n_student>MAX || n_student<1);

    for (int i=0;i<n_student;i++) {
        student s;
        do {
printf("nhap ma so sinh vien thu %d: ",i+1);
            gets(s.id);
            if (strlen(s.id)==0 || strcmp(s.id,"")==0) {
                printf("ma so sinh vien khong dc de trong\n");
            }else{  if (exitedId(s.id)==0) {
                printf("ma so sinh vien da ton tai\n");
            }
            }

        }while (strlen(s.id)==0 || strcmp(s.id," ")==0 ||exitedId(s.id)==0);

        do {
            printf("nhap ho ten sinh vien:");
            gets(s.name);
            if (strlen(s.name)==0 || strcmp(s.name," ")==0) {
                printf("ten khong dc de trong\n");
            }
        }while (strlen(s.name)==0 || strcmp(s.name," ")==0);

        do {
            printf("nhap ngay sinh: ");
            scanf("%d",&s.birthday.day);
            fflush(stdin);
            printf("nhap thang: ");
            scanf("%d",&s.birthday.month);
            fflush(stdin);
            printf("nhap nam sinh: ");
            scanf("%d",&s.birthday.year);
            fflush(stdin);
            if (!checkDay(s.birthday.day, s.birthday.month, s.birthday.year) || !checkMonth(s.birthday.month) || !checkYear(s.birthday.year) ) {
                printf("ngay thang nam sinh khong hop le\n");
            }
        }while (!checkDay(s.birthday.day, s.birthday.month, s.birthday.year) || !checkMonth(s.birthday.month) || !checkYear(s.birthday.year));

        do {
            printf("nhap dia chi sinh vien: ");
            gets(s.address);
            if (strlen(s.address)==0 || strcmp(s.address," ")==0) {
                printf("dia chi khong dc de trong\n");
            }
        }while (strlen(s.address)==0 || strcmp(s.address," ")==0);

        do {
            printf("nhap so dien thoai sinh vien: ");
            gets(s.phone);
            if (strlen(s.phone)==0 || strcmp(s.phone," ")==0) {
                printf("so dien thoai khong dc de trong\n");
            }else {
                if (exitedPhone(s.phone)==0) {
                    printf("so dien thoai da ton tai\n");
                }
            }
        }while (strlen(s.phone)==0 || strcmp(s.phone," ")==0 || exitedPhone(s.phone)==0);

        listStudent[i]=s;
    }
}

void displayStudent(){
        for (int i=0;i<116;i++) {
            printf("-");
        }
    printf("\n|%-15s|%-30s|%-20s|%-30s|%-15s|\n","ma sinh vien","ho ten","ngay sinh","dia chi","dien thoai");
    for (int i=0;i<116;i++) {
        printf("-");
    }
    for (int i=0;i<n_student;i++) {
        printf("\n|%-15s|%-30s|%-2d/%-2d/%-14d|%-30s|%-15s|\n",listStudent[i].id,listStudent[i].name,listStudent[i].birthday.day,listStudent[i].birthday.month,listStudent[i].birthday.year,listStudent[i].address,listStudent[i].phone);
    for (int i=0;i<116;i++) {
        printf("-");
    }
    }
}

void addStudent() {
    printf("nhap thong tin sinh vien can them\n");
    student s;
    do {
        printf("nhap ma so sinh vien ");
        gets(s.id);
        if (strlen(s.id)==0 || strcmp(s.id,"")==0) {
            printf("ma so sinh vien khong dc de trong\n");

        }else{ if (exitedId(s.id)==0) {
            printf("ma so sinh vien da ton tai\n");
        }
        }
    }while (strlen(s.id)==0 || strcmp(s.id," ")==0 ||exitedId(s.id)==0);

    do {
        printf("nhap ho ten sinh vien:");
        gets(s.name);
        if (strlen(s.name)==0 || strcmp(s.name," ")==0) {
            printf("ten khong dc de trong\n");
        }
    }while (strlen(s.name)==0 || strcmp(s.name," ")==0);

    do {
        printf("nhap ngay sinh: ");
        scanf("%d",&s.birthday.day);
        fflush(stdin);
        printf("nhap thang: ");
        scanf("%d",&s.birthday.month);
        fflush(stdin);
        printf("nhap nam sinh: ");
        scanf("%d",&s.birthday.year);
        fflush(stdin);
        if (!checkDay(s.birthday.day, s.birthday.month, s.birthday.year) || !checkMonth(s.birthday.month) || !checkYear(s.birthday.year) ) {
            printf("ngay thang nam sinh khong hop le\n");
        }
    }while (!checkDay(s.birthday.day, s.birthday.month, s.birthday.year) || !checkMonth(s.birthday.month) || !checkYear(s.birthday.year));

    do {
        printf("nhap dia chi sinh vien: ");
        gets(s.address);
        if (strlen(s.address)==0 || strcmp(s.address," ")==0) {
            printf("dia chi khong dc de trong\n");
        }
    }while (strlen(s.address)==0 || strcmp(s.address," ")==0);

    do {
        printf("nhap so dien thoai sinh vien: ");
        gets(s.phone);
        if (strlen(s.phone)==0 || strcmp(s.phone," ")==0) {
            printf("so dien thoai khong dc de trong\n");
        }else{
            if (exitedPhone(s.phone)==0) {
                printf("so dien thoai da ton tai\n");
            }
        }
    }while (strlen(s.phone)==0 || strcmp(s.phone," ")==0 || exitedPhone(s.phone)==0);
    listStudent[n_student]=s;
        n_student++;
}

void deleteStudent() {
    char delId[15];
    printf("nhap ma sinh vien sinh vien can xoa: ");
    gets(delId);
    if (exitedId(delId)==1) {
        printf("ma so sinh vien khong ton tai\n");
        return;
    }
    for (int i=0;i<n_student;i++) {
        if (strcmp(listStudent[i].id,delId)==0) {
            for (int j=i;j<n_student-1;j++) {
                listStudent[j]=listStudent[j+1];
            }
            n_student--;

        }
    }
}

void updateStudent() {
    char newStudent[15];
    printf("nhap ma so sinh vien muon cap nhap: ");
    gets(newStudent);
    if (exitedId(newStudent)==1) {
        printf("ma so sinh vien khong ton tai\n");
        return;
    }
    for (int i=0;i<n_student;i++) {
        if (strcmp(listStudent[i].id,newStudent)==0) {

        do {
            printf("nhap ho ten sinh vien:");
            gets(listStudent[i].name);
            if (strlen(listStudent[i].name)==0 || strcmp(listStudent[i].name," ")==0) {
                printf("ten khong dc de trong\n");
            }
        }while (strlen(listStudent[i].name)==0 || strcmp(listStudent[i].name," ")==0);

        do {
            printf("nhap ngay sinh: ");
            scanf("%d",&listStudent[i].birthday.day);
            fflush(stdin);
            printf("nhap thang: ");
            scanf("%d",&listStudent[i].birthday.month);
            fflush(stdin);
            printf("nhap nam sinh: ");
            scanf("%d",&listStudent[i].birthday.year);
            fflush(stdin);
            if (!checkDay(listStudent[i].birthday.day, listStudent[i].birthday.month, listStudent[i].birthday.year) || !checkMonth(listStudent[i].birthday.month) || !checkYear(listStudent[i].birthday.year) ) {
                printf("ngay thang nam sinh khong hop le\n");
            }
        }while (!checkDay(listStudent[i].birthday.day, listStudent[i].birthday.month, listStudent[i].birthday.year) || !checkMonth(listStudent[i].birthday.month) || !checkYear(listStudent[i].birthday.year));

        do {
            printf("nhap dia chi sinh vien: ");
            gets(listStudent[i].address);
            if (strlen(listStudent[i].address)==0 || strcmp(listStudent[i].address," ")==0) {
                printf("dia chi khong dc de trong\n");
            }
        }while (strlen(listStudent[i].address)==0 || strcmp(listStudent[i].address," ")==0);

        do {
            printf("nhap so dien thoai sinh vien: ");
            gets(listStudent[i].phone);
            if (strlen(listStudent[i].phone)==0 || strcmp(listStudent[i].phone," ")==0) {
                printf("so dien thoai khong dc de trong\n");

            }
        }while (strlen(listStudent[i].phone)==0 || strcmp(listStudent[i].phone," ")==0 );
        }
    }
}
void sortStudent() {
    for (int i=0;i<n_student;i++) {
        for (int j=0;j<n_student-1-i;j++) {
            if (strcmp(listStudent[j].name,listStudent[j+1].name) > 0) {
                student temp=listStudent[j];
                listStudent[j]=listStudent[j+1];
                listStudent[j+1]=temp;
            }
        }
    }
}
void searchStudent() {
    char idSearch[30];
    printf("nhap ma sinh vien can tim: ");
    gets(idSearch);
    if (exitedId(idSearch)==1) {
        printf("ma so sinh vien khong ton tai\n");
        return;
    }

    for (int i=0;i<n_student;i++) {
        if (strcmp(listStudent[i].id,idSearch)==0) {
            printf("tim thay sinh vien %s ma so sinh vien %s ngay thang nam sinh %d/%d/%d dia chi %s sdt %s",listStudent[i].name,listStudent[i].id,listStudent[i].birthday.day,listStudent[i].birthday.month,listStudent[i].birthday.year,listStudent[i].address,listStudent[i].phone);
        }
    }
}

int exitedId(char id[]) {
    for (int i=0;i<n_student;i++) {
        if (strcmp(id,listStudent[i].id)==0) {
            return 0;
        }
    }
    return 1;
}
int exitedPhone(char phone[]) {
    for (int i=0;i<n_student;i++) {
        if (strcmp(listStudent[i].phone,phone)==0) {
            return 0;
        }
    }
    return 1;
}
int checkDay(int day, int month, int year) {
    if (day<1) {
        return 0;
    }
    if (month==1 || month==3 || month==5 || month==7 || month==8 || month==10 || month==12) {
        if (day>31) {
            return 0;
        }
    }
    if (month==4 || month==6 || month==9 || month==11) {
        if (day>30) {
            return 0;
        }
    }
    if (month==2) {
        if ((year%4==0 && year%100!=0) || year%400==0) {
            if (day>29) {
                return 0;
            }
        }else {
                if (day>28) {
                    return 0;
                }
            }
        }

    return 1;
}
int checkMonth(int month) {
    if (month<1 || month>12) {
        return 0;
    }
    return 1;
}
int checkYear(int year) {
    if (year<1900 || year>2025) {
        return 0;
    }
    return 1;
}

