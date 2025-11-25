#include <stdio.h>
#include <string.h>

#define MAX_ACCOUNT 100
#define PAGE_SIZE 10

struct Account {
    char accountId[20];
    char fullName[50];
    char phone[15];
    double balance;
    int status;
};

struct Account accountList[MAX_ACCOUNT] = {
    {"1", "Nguyen Van A", "0385938494", 500000, 1},
    {"2", "Nguyen Van B", "0983495876", 400000, 1},
    {"3", "Nguyen Van C", "0978746793", 0, 0}
};

int accountSize = 3;

void printMenu();
void addAccount();
void updateInfor();
void lockAccount();
void findAccount();

int main() {
    int choice;

    while (1) {
        printMenu();
        printf("Nhap lua chon cua ban: ");
        scanf("%d", &choice);
        getchar(); 

        switch (choice) {
            case 1:
                addAccount();
                break;
            case 2:
                updateInfor();
                break;
            case 3:
            	lockAccount();
            	break;
            case 4:
            	findAccount();
            case 9:
                printf("Thoat chuong trinh!\n");
                return 0;
            default:
                printf("Lua chon khong hop le. Vui long chon lai (1-9).\n");
        }
    }
    return 0;
}

void printMenu() {
    printf("+--------------- Mini Banking System ---------------+\n");
    printf("|1. Them moi tai khoan                              |\n");
    printf("|2. Cap nhat thong tin                              |\n");
    printf("|3. Quan ly trang thai                              |\n");
    printf("|4. Tra cuu                                         |\n");
    printf("|5. Danh sach                                       |\n");
    printf("|6. Sap xep danh sach                               |\n");
    printf("|7. Giao dich chuyen khoan                          |\n");
    printf("|8. Lich su giao dich                               |\n");
    printf("|9. Thoat chuong trinh                              |\n");
    printf("+---------------------------------------------------+\n");
}

// Them moi tai khoan
void addAccount() {		
    if (accountSize >= MAX_ACCOUNT) {	//kiem tra mang day hay ch
        printf("Danh sach da day, khong the them!\n");
        return;
    }


    while (1) {
        printf("Nhap Ma ID: ");
        fgets(accountList[accountSize].accountId, sizeof(accountList[accountSize].accountId), stdin);
        accountList[accountSize].accountId[strcspn(accountList[accountSize].accountId, "\n")] = '\0';

        if (strlen(accountList[accountSize].accountId) == 0) {
            printf("Vui long nhap ID !!!\n");
            continue;
        }

        int exist = 0;	//kiem tra ton tai
        for (int i = 0; i < accountSize; i++) {
            if (strcmp(accountList[accountSize].accountId, accountList[i].accountId) == 0) {
                exist = 1;
                break;
            }
        }
        if (exist) {
            printf("Ma ID da ton tai - Vui long nhap lai!!!\n");
            continue;
        }
        break;
    }

    while (1) {
        printf("Nhap Ho va Ten: ");
        fgets(accountList[accountSize].fullName, sizeof(accountList[accountSize].fullName), stdin);
        accountList[accountSize].fullName[strcspn(accountList[accountSize].fullName, "\n")] = '\0';

        if (strlen(accountList[accountSize].fullName) == 0) {
            printf("Ho va ten khong duoc rong!!!\n");
            continue;
        }
        break;
    }

    while (1) {
        printf("Nhap SDT: ");
        fgets(accountList[accountSize].phone, sizeof(accountList[accountSize].phone), stdin);
        accountList[accountSize].phone[strcspn(accountList[accountSize].phone, "\n")] = '\0';

        if (strlen(accountList[accountSize].phone) < 10) { // nhap sdt tren 10 so
            printf("SDT khong hop le!\n");
            continue;
        }
        break;
    }

    accountList[accountSize].balance = 0;	//them tai khoan so du mac dinh = 0
    accountList[accountSize].status = 1;
    accountSize++;

    printf("Da them thanh cong !!!\n");
}

// Cap nhat thong tin
void updateInfor() {
    char id[20];
    int found = -1;

    while (1) {
        printf("Nhap Ma ID can cap nhat: ");
        fgets(id, sizeof(id), stdin);
        id[strcspn(id, "\n")] = '\0';

        for (int i = 0; i < accountSize; i++) {
            if (strcmp(id, accountList[i].accountId) == 0) {
                found = i;
                break;
            }
        }

        if (found == -1) {
            printf("Khong tim thay tai khoan!!!\n");
            continue;
        }
        break;
    }
    printf("\n+-------------------------------- Thong tin hien tai --------------------------------+\n");
	printf("\n+----------+------------------------------+----------+--------------------+----------+\n");
	printf("|%-10s|%-30s|%-10s|%-20s|%-10s|\n","Ma ID","Ho va Ten","SDT","So du tai khoan","Trang thai");
	printf("+----------+------------------------------+----------+--------------------+----------+\n");
	printf("|%-10s|%-30s|%-10s|%-20.2f|%-10d|\n",accountList[found].accountId,accountList[found].fullName,accountList[found].phone,accountList[found].balance,accountList[found].status);
	printf("+----------+------------------------------+----------+--------------------+----------+\n");

    while (1) {
        printf("Nhap Ho va Ten: ");
        fgets(accountList[accountSize].fullName, sizeof(accountList[accountSize].fullName), stdin);
        accountList[accountSize].fullName[strcspn(accountList[accountSize].fullName, "\n")] = '\0';

        if (strlen(accountList[accountSize].fullName) == 0) {
            break;
        }
    }
	while (1) {
        printf("Nhap SDT moi: ");
        fgets(accountList[found].phone, sizeof(accountList[found].phone), stdin);
        accountList[found].phone[strcspn(accountList[found].phone, "\n")] = '\0';

        if (strlen(accountList[found].phone) < 10) {
            printf("SDT khong hop le!\n");
            continue;
        }
        break;
    	int duplicate = 0;	//kiem tra trung lap
        for (int i = 0; i < accountSize; i++) {
            if (strcmp(accountList[accountSize].phone, accountList[i].phone) == 0) {
                duplicate = 1;
                break;
            }
        
        if (duplicate == 1) {
        	printf("Sdt bi trung - Vui long nhap lai!!!\n");
        	continue;
        }
     	break;
		}
    }
    printf("Cap nhat thanh cong !!!\n");
	
}

// Khoa tai khoan
void lockAccount(){
	char id[20];
    int found = -1;

    while (1) {
        printf("Nhap Ma ID can khoa: ");
        fgets(id, sizeof(id), stdin);
        id[strcspn(id, "\n")] = '\0';

        for (int i = 0; i < accountSize; i++) {
            if (strcmp(id, accountList[i].accountId) == 0) {
                found = i;
                break;
            }
        }

        if (found == -1) {
            printf("Khong tim thay tai khoan!!!\n");
            continue;
        }
        break;
        if (found == 0) {
            printf("Ma ID khong ton tai - Vui long nhap lai!!!\n");
            continue;
        }
        break;
    }

    printf("\n+-------------------------------- Thong tin hien tai --------------------------------+\n");
	printf("\n+----------+------------------------------+----------+--------------------+----------+\n");
	printf("|%-10s|%-30s|%-10s|%-20s|%-10s|\n","Ma ID","Ho va Ten","SDT","So du tai khoan","Trang thai");
	printf("+----------+------------------------------+----------+--------------------+----------+\n");
	printf("|%-10s|%-30s|%-10s|%-20.2f|%-10d|\n",accountList[found].accountId,accountList[found].fullName,accountList[found].phone,accountList[found].balance,accountList[found].status);
	printf("+----------+------------------------------+----------+--------------------+----------+\n");
	
	char confirm;
	printf("Xac nhan khoa(Y/N)?: ");
    scanf("%c", &confirm);
    getchar();
    if (confirm == 'Y' || confirm == 'y') {
        accountList[found].status = 0;
        printf("Khoa tai khoan thanh cong!!!\n");
    } else {
        printf("Huy thao tac.\n");
    }
}

void findAccount(){
    char id[20], name[50];
    int found = -1;

    printf("Nhap ID: ");
    fgets(id, sizeof(id), stdin);
    id[strcspn(id, "\n")] = 0;

    printf("Nhap Ho Ten: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = 0;

    if (strlen(id) == 0 && strlen(name) == 0) {
        printf("Ban phai nhap ID hoac Ten!\n");
        return;
    }

    // Tim bang Id
    if (strlen(id) > 0) {
        for (int i = 0; i < accountSize; i++) {
            if (strcmp(id, accountList[i].accountId) == 0) {
                found = i;
                break;
            }
        }
    }

    // Khong co Id thi tim theo ten
    if (found == -1 && strlen(name) > 0) {
        for (int i = 0; i < accountSize; i++) {
            if (strcmp(name, accountList[i].fullName) == 0) {
                found = i;
                break;
            }
        }
    }

    if (found == -1) {
        printf("Khong tim thay tai khoan!\n");
        return;
    }
    
    printf("\n+-------------------------------- Thong tin hien tai --------------------------------+\n");
	printf("\n+----------+------------------------------+----------+--------------------+----------+\n");
	printf("|%-10s|%-30s|%-10s|%-20s|%-10s|\n","Ma ID","Ho va Ten","SDT","So du tai khoan","Trang thai");
	printf("+----------+------------------------------+----------+--------------------+----------+\n");
	printf("|%-10s|%-30s|%-10s|%-20.2f|%-10d|\n",accountList[found].accountId,accountList[found].fullName,accountList[found].phone,accountList[found].balance,accountList[found].status);
	printf("+----------+------------------------------+----------+--------------------+----------+\n");
}


