
#include <stdio.h>
#include <math.h>
#include <string.h>
#define MAX 1000

typedef struct {
    int day;
    int month;
    int year;
} orderDate;

typedef struct {
    char id[50];
    char name[50];
    char money[50];
    char status[50];
    orderDate orderDates;
} Guest;

Guest guests[MAX];
int totalGuests = 0;

void enterInformationGuests();
int isValidDates(int day, int month, int year);
void disPlays(Guest guest);
void disPlaysInformationOfProducts();
void updateInformationOfProducts();
void deleteOrderById();
void sortOrdersByMoney();
void findOrderById();
int isIdExists(char id[]);

int main() {
    int choose;
    
    do {
        printf("\n=============== APP ORDER ===============");
        printf("\n1. Nhap thong tin don hang");
        printf("\n2. Hien thi thong tin don hang");
        printf("\n3. Cap nhat thong tin don hang");
        printf("\n4. Xoa don hang theo ma don");
        printf("\n5. Sap xep don hang theo tong tien");
        printf("\n6. Tim kiem don hang theo ma don hang");
        printf("\n7. Thoat");
        printf("\n==========================================");
        printf("\nNhap chuc nang: ");
        scanf("%d", &choose);
        getchar();
        
        switch (choose) {
            case 1:
                enterInformationGuests();
                break;
            case 2:
                disPlaysInformationOfProducts();
                break;
            case 3:
                updateInformationOfProducts();
                break;
            case 4:
                deleteOrderById();
                break;
            case 5:
                sortOrdersByMoney();
                break;
            case 6:
                findOrderById();
                break;
            case 7:
                printf("Cam on ban da su dung dich vu!\n");
                break;
            default:
                printf("Loi - Xin vui long nhap lai chuc nang tu 1 - 7\n");
        }
    } while (choose != 7);
    
    return 0;
}

void enterInformationGuests() {
    int n;
    printf("Nhap so luong don hang: ");
    scanf("%d", &n);
    getchar();
    
    if (totalGuests + n > MAX) {
        printf("Vuot qua so luong toi da! Chi co the them %d don hang.\n", MAX - totalGuests);
        n = MAX - totalGuests;
    }
    
    printf("\n========== NHAP THONG TIN DON HANG ==========\n");
    for (int i = 0; i < n; i++) {
        printf("\n----- Don hang thu %d -----\n", totalGuests + 1);
        
        // Nh?p ID
        do {
            printf("Ma don: ");
            fgets(guests[totalGuests].id, 50, stdin);
            guests[totalGuests].id[strcspn(guests[totalGuests].id, "\n")] = '\0';
            
            if (strlen(guests[totalGuests].id) == 0) {
                printf("Ma don khong duoc de trong!\n");
            } else if (isIdExists(guests[totalGuests].id)) {
                printf("Ma don da ton tai! Vui long nhap ma khac.\n");
                guests[totalGuests].id[0] = '\0';
            }
        } while (strlen(guests[totalGuests].id) == 0);
        
        // Nh?p tên
        do {
            printf("Ten khach hang: ");
            fgets(guests[totalGuests].name, 50, stdin);
            guests[totalGuests].name[strcspn(guests[totalGuests].name, "\n")] = '\0';
        } while (strlen(guests[totalGuests].name) == 0);
        
        // Nh?p ngày tháng n?m
        printf("--- Ngay dat hang ---\n");
        do {
            printf("Ngay: ");
            scanf("%d", &guests[totalGuests].orderDates.day);
            printf("Thang: ");
            scanf("%d", &guests[totalGuests].orderDates.month);
            printf("Nam: ");
            scanf("%d", &guests[totalGuests].orderDates.year);
            getchar();
            
            if (!isValidDates(guests[totalGuests].orderDates.day, 
                            guests[totalGuests].orderDates.month, 
                            guests[totalGuests].orderDates.year)) {
                printf("Ngay thang nam khong hop le! Vui long nhap lai.\n");
            }
        } while (!isValidDates(guests[totalGuests].orderDates.day, 
                             guests[totalGuests].orderDates.month, 
                             guests[totalGuests].orderDates.year));
        
        // Nh?p s? ti?n
        do {
            printf("Tong tien: ");
            fgets(guests[totalGuests].money, 50, stdin);
            guests[totalGuests].money[strcspn(guests[totalGuests].money, "\n")] = '\0';
        } while (strlen(guests[totalGuests].money) == 0);
        
        // Nh?p tr?ng thái
        do {
            printf("Trang thai: ");
            fgets(guests[totalGuests].status, 50, stdin);
            guests[totalGuests].status[strcspn(guests[totalGuests].status, "\n")] = '\0';
        } while (strlen(guests[totalGuests].status) == 0);
        
        totalGuests++;
        printf("Them don hang thanh cong!\n");
    }
}

int isValidDates(int day, int month, int year) {
    if (year < 1900 || year > 2025) {
        return 0;
    }
    
    if (month < 1 || month > 12) {
        return 0;
    }
    
    if (day < 1) {
        return 0;
    }
    
    if (month == 1 || month == 3 || month == 5 || month == 7 || 
        month == 8 || month == 10 || month == 12) {
        if (day > 31) {
            return 0;
        }
    } else if (month == 4 || month == 6 || month == 9 || month == 11) {
        if (day > 30) {
            return 0;
        }
    } else if (month == 2) {
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
            if (day > 29) {
                return 0;
            }
        } else {
            if (day > 28) {
                return 0;
            }
        }
    }
    
    return 1;
}

void disPlays(Guest guest) {
    printf("| %-12s | %-22s | %02d/%02d/%-15d | %-12s | %-15s |\n",
           guest.id,
           guest.name,
           guest.orderDates.day,
           guest.orderDates.month,
           guest.orderDates.year,
           guest.money,
           guest.status);
}

void disPlaysInformationOfProducts() {
    if (totalGuests == 0) {
        printf("\nDanh sach don hang rong!\n");
        return;
    }
    
    printf("\n=============== DANH SACH DON HANG ===============\n");
    printf("| Ma don      | Ten khach hang        | Ngay dat hang     | Tong tien   | Trang thai     |\n");
    printf("|-------------|-----------------------|-------------------|-------------|----------------|\n");
    for (int i = 0; i < totalGuests; i++) {
        disPlays(guests[i]);
    }
    printf("========================================================================================\n");
    printf("Tong so don hang: %d\n", totalGuests);
}

int isIdExists(char id[]) {
    for (int i = 0; i < totalGuests; i++) {
        if (strcmp(guests[i].id, id) == 0) {
            return 1;
        }
    }
    return 0;
}

void updateInformationOfProducts() {
    if (totalGuests == 0) {
        printf("Danh sach don hang rong! Vui long nhap thong tin truoc.\n");
        return;
    }
    
    char gueID[50];
    printf("Nhap ma don can cap nhat: ");
    fgets(gueID, 50, stdin);
    gueID[strcspn(gueID, "\n")] = '\0';
    
    int found = -1;
    for (int i = 0; i < totalGuests; i++) {
        if (strcmp(guests[i].id, gueID) == 0) {
            found = i;
            break;
        }
    }
    
    if (found == -1) {
        printf("Khong tim thay don hang voi ma: %s\n", gueID);
        return;
    }
    
    printf("\n=== CAP NHAT THONG TIN DON HANG ===\n");
    printf("Don hang hien tai:\n");
    disPlays(guests[found]);
    
    // C?p nh?t tên
    do {
        printf("\nTen khach hang moi (Enter de giu nguyen): ");
        char newName[50];
        fgets(newName, 50, stdin);
        newName[strcspn(newName, "\n")] = '\0';
        
        if (strlen(newName) > 0) {
            strcpy(guests[found].name, newName);
            break;
        } else {
            break;
        }
    } while (1);
    
    // C?p nh?t ngày tháng n?m
    printf("\n--- Cap nhat ngay dat hang ---\n");
    do {
        int newDay, newMonth, newYear;
        printf("Ngay moi (Enter 0 de giu nguyen): ");
        scanf("%d", &newDay);
        printf("Thang moi (Enter 0 de giu nguyen): ");
        scanf("%d", &newMonth);
        printf("Nam moi (Enter 0 de giu nguyen): ");
        scanf("%d", &newYear);
        getchar();
        
        if (newDay == 0 && newMonth == 0 && newYear == 0) {
            break;
        }
        
        int finalDay = (newDay != 0) ? newDay : guests[found].orderDates.day;
        int finalMonth = (newMonth != 0) ? newMonth : guests[found].orderDates.month;
        int finalYear = (newYear != 0) ? newYear : guests[found].orderDates.year;
        
        if (isValidDates(finalDay, finalMonth, finalYear)) {
            guests[found].orderDates.day = finalDay;
            guests[found].orderDates.month = finalMonth;
            guests[found].orderDates.year = finalYear;
            break;
        } else {
            printf("Ngay thang nam khong hop le! Vui long nhap lai.\n");
        }
    } while (1);
    
    // C?p nh?t s? ti?n
    do {
        printf("Tong tien moi (Enter de giu nguyen): ");
        char newMoney[50];
        fgets(newMoney, 50, stdin);
        newMoney[strcspn(newMoney, "\n")] = '\0';
        
        if (strlen(newMoney) > 0) {
            strcpy(guests[found].money, newMoney);
            break;
        } else {
            break;
        }
    } while (1);
    
    // C?p nh?t tr?ng thái
    do {
        printf("Trang thai moi (Enter de giu nguyen): ");
        char newStatus[50];
        fgets(newStatus, 50, stdin);
        newStatus[strcspn(newStatus, "\n")] = '\0';
        
        if (strlen(newStatus) > 0) {
            strcpy(guests[found].status, newStatus);
            break;
        } else {
            break;
        }
    } while (1);
    
    printf("Cap nhat thong tin thanh cong!\n");
}

void deleteOrderById() {
    if (totalGuests == 0) {
        printf("Danh sach don hang rong!\n");
        return;
    }
    
    char delID[50];
    printf("Nhap ma don can xoa: ");
    fgets(delID, 50, stdin);
    delID[strcspn(delID, "\n")] = '\0';
    
    int found = -1;
    for (int i = 0; i < totalGuests; i++) {
        if (strcmp(guests[i].id, delID) == 0) {
            found = i;
            break;
        }
    }
    
    if (found == -1) {
        printf("Khong tim thay don hang voi ma: %s\n", delID);
        return;
    }
    
    printf("Thong tin don hang se bi xoa:\n");
    disPlays(guests[found]);
    
    char confirm;
    printf("Ban co chac chan muon xoa? (y/n): ");
    scanf("%c", &confirm);
    getchar();
    
    if (confirm == 'y' || confirm == 'Y') {
        for (int i = found; i < totalGuests - 1; i++) {
            guests[i] = guests[i + 1];
        }
        totalGuests--;
        printf("Xoa don hang thanh cong!\n");
    } else {
        printf("Huy xoa don hang.\n");
    }
}

void sortOrdersByMoney() {
    if (totalGuests == 0) {
        printf("Danh sach don hang rong!\n");
        return;
    }
    
    for (int i = 0; i < totalGuests - 1; i++) {
        for (int j = 0; j < totalGuests - i - 1; j++) {
            // Chuy?n chu?i ti?n thành s? ?? so sánh
            float money1, money2;
            sscanf(guests[j].money, "%f", &money1);
            sscanf(guests[j + 1].money, "%f", &money2);
            
            if (money1 < money2) {
                Guest temp = guests[j];
                guests[j] = guests[j + 1];
                guests[j + 1] = temp;
            }
        }
    }
    
    printf("Sap xep don hang theo tong tien giam dan thanh cong!\n");
    disPlaysInformationOfProducts();
}

void findOrderById() {
    if (totalGuests == 0) {
        printf("Danh sach don hang rong!\n");
        return;
    }
    
    char searchID[50];
    printf("Nhap ma don can tim: ");
    fgets(searchID, 50, stdin);
    searchID[strcspn(searchID, "\n")] = '\0';
    
    int found = -1;
    for (int i = 0; i < totalGuests; i++) {
        if (strcmp(guests[i].id, searchID) == 0) {
            found = i;
            break;
        }
    }
    
    if (found == -1) {
        printf("Khong tim thay don hang voi ma: %s\n", searchID);
        return;
    }
    
    printf("\n=== THONG TIN DON HANG TIM THAY ===\n");
    printf("| Ma don      | Ten khach hang        | Ngay dat hang     | Tong tien   | Trang thai     |\n");
    printf("|-------------|-----------------------|-------------------|-------------|----------------|\n");
    disPlays(guests[found]);
    printf("========================================================================================\n");
}

