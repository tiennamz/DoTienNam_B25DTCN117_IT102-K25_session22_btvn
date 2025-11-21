#include<stdio.h>
#include<string.h>
#define MAX 100
    typedef struct {
        char name[50];
        int age;
        float grade;
    }student;
    student listStudent[MAX];
int n_student=0;

    void inputStudent();
    void displayStudent();
    float scoring();

    int main () {
        int choice;
        do {
            printf("\n1.Nhap thong tin hoc sinh.\n");
            printf("2.Hien thi thong tin cua hoc sinh.\n");
            printf("3.Tinh điem trung binh cua tat ca hoc sinh.\n");
        printf("\n");
            printf("nhap lua chon: ");
            scanf("%d", &choice);
            switch (choice) {
                case 1:
                    inputStudent();
                    break;
                case 2:
                    displayStudent();
                break;
                case 3:
                    scoring();
                    break;
            }

        }while (1);

    }
void inputStudent() {

        do {
            printf("nhap so luong sinh vien: ");
            scanf("%d",&n_student);
            if (n_student > MAX  || n_student<1){
                printf("loi, ,moi ban nhap lai!!!\n");
            }
        }while (n_student > MAX  || n_student<1);
            for (int i=0;i<n_student;i++) {
                printf("nhap thong tin sinh vien thu %d",i+1);
                student s;
                fflush(stdin);
                getchar();

                do {
                    printf("nhap ho ten sinh vien: ");
                    gets(s.name);
                    if (strlen(s.name) ==0 || strcmp(s.name," ")==0) {
                        printf("ho ten khong dc de trong\n");
                    }
                }while (strlen(s.name) ==0 || strcmp(s.name," ")==0);

                do {
                    printf("nhap tuoi sinh vien: ");
                    scanf("%d",&s.age);
                    fflush(stdin);

                   if (s.age<0 || s.age>100) {
                       printf("tuoi khong hop le\n");
                   }
                }while (s.age<0 || s.age>100);

                do {
                    printf("nhap diem sinh vien: ");
                    scanf("%f",&s.grade);

                    fflush(stdin);
                    if (s.grade<0 || s.grade>10) {
                        printf("diem khong hop le\n");
                    }

                }while (s.grade<0 || s.grade>10);
                listStudent[i]=s;
            }
            }

void displayStudent() {
        printf("\nthong tin sinh vien\n");
        for (int i=0;i<54;i++) {
            printf("-");
        }

        printf("\n|%-30s|%-10s|%-10s|\n","ho va ten","tuoi","diem");
        for (int i=0;i<54;i++) {
            printf("-");
        }
        for (int i=0;i<n_student;i++){
            student s=listStudent[i];

                printf("\n|%-30s|%-10d|%-10.2f|\n",s.name,s.age,s.grade);

            for (int i=0;i<54;i++) {
                printf("-");
            }
        }
    }
    float scoring() {
        float sum=0.0;
        for (int i=0;i<n_student;i++) {
            sum+=listStudent[i].grade;
        }

printf("diem trung binh sinh vien la: %.2f",sum/n_student);
        return sum/n_student;
}
