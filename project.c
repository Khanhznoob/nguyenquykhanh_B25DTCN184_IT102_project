#include <stdio.h>
#include <string.h>
#define MAX 100

struct Account {
	char accountId[20];
	char fullName[50];
	char phone[15];
	double balance;
	int status;
};

struct Transaction {
	char transactionId[20];
	char senderId[20];
	char receiverId[20];
	double amount;
	char type[10];
	char date[20];
};

struct Account accountList[MAX] = {		// Danh sach tai khoan
	{"A001", "Duong Van Y", "0385938494", 500.000, 1},
	{"A002", "Le Thi E", "0983495876", 400.000, 1},
	{"A003", "Vuong Thi Z", "0978746793", 0.000, 0},
	{"A004", "Ta Thi AD", "0912345678", 1500.000, 1},
	{"A005", "Tran Van D", "0905123456", 2300.000, 1},
	{"A006", "Dang Van H", "0987654321", 120.000, 1},
	{"A007", "Chu Van S", "0932456789", 340.000, 1},
	{"A008", "Pham Van F", "0923456789", 760.000, 1},
	{"A009", "Quach Van AC", "0945678123", 540.000, 1},
	{"A010", "Nguyen Van C", "0919785643", 1200.000, 1},
	{"A011", "Mai Thi T", "0931234567", 990.000, 1},
	{"A012", "Phung Van AA", "0962345678", 3500.000, 1},
	{"A013", "Vu Thi L", "0978765432", 100.000, 0},
	{"A014", "Dao Van K", "0913456782", 890.000, 1},
	{"A015", "Hoang Thi G", "0952346789", 440.000, 1},
	{"A016", "Ly Van Q", "0981122334", 210.000, 1},
	{"A017", "Ton Thi X", "0935544332", 530.000, 1},
	{"A018", "Bao Thi AB", "0907788996", 760.000, 0},
	{"A019", "Phan Thi N", "0946677885", 150.000, 1},
	{"A020", "Nguyen Van A", "0939988776", 280.000, 1},
	{"A021", "Duong Thi R", "0972233445", 830.000, 1},
	{"A022", "Ngo Thi P", "0903344556", 600.000, 1},
	{"A023", "La Van W", "0915566778", 720.000, 1},
	{"A024", "Do Van U", "0934433221", 190.000, 0},
	{"A025", "Trinh Van M", "0956677889", 890.000, 1},
	{"A026", "Nguyen Van B", "0941122334", 770.000, 1},
	{"A027", "Bui Thi I", "0988877665", 1100.000, 1},
	{"A028", "Duong Thi R", "0912233445", 640.000, 1},
	{"A029", "Vo Van O", "0925566778", 540.000, 1},
	{"A030", "Trieu Van AE", "0966677889", 3000.000, 1},
	{"A031", "Pham Thi Y", "0901112233", 450.000, 1},
	{"A032", "Nguyen Van T", "0912223344", 820.000, 1},
	{"A033", "Hoang Van U", "0923334455", 120.000, 0},
	{"A034", "Tran Thi P", "0934445566", 960.000, 1},
	{"A035", "Phan Van R", "0945556677", 780.000, 1},
	{"A036", "Le Van S", "0956667788", 110.000, 1},
	{"A037", "Bui Van H", "0967778899", 2000.000, 1},
	{"A038", "Do Thi K", "0978889900", 340.000, 1},
	{"A039", "Vo Thi L", "0989990011", 600.000, 1},
	{"A040", "Ta Van M", "0902223344", 50.000, 0},
	{"A041", "Chu Thi Q", "0913334455", 880.000, 1},
	{"A042", "Phung Van Z", "0924445566", 1300.000, 1},
	{"A043", "Trinh Thi X", "0935556677", 760.000, 1},
	{"A044", "Dang Van O", "0946667788", 240.000, 1},
	{"A045", "Nguyen Thi G", "0957778899", 990.000, 1},
	{"A046", "Mai Van B", "0968889900", 310.000, 1},
	{"A047", "La Thi D", "0979990011", 170.000, 0},
	{"A048", "Quach Van H", "0980001122", 450.000, 1},
	{"A049", "Ton Van E", "0903334455", 2200.000, 1},
	{"A050", "Bao Thi J", "0914445566", 560.000, 1}
};
int accountSize = 50;

struct Transaction transactionList[MAX] = {
	{"T001","A005","A012",1450.000,"Transfer","01/01/2025"},
	{"T002","A010","A010",700.000,"Deposit","02/01/2025"},
	{"T003","A003","A003",350.000,"Withdraw","03/01/2025"},
	{"T004","A014","A027",890.000,"Transfer","04/01/2025"},
	{"T005","A018","A018",1200.000,"Deposit","05/01/2025"},
	{"T006","A007","A007",430.000,"Withdraw","06/01/2025"},
	{"T007","A021","A009",1750.000,"Transfer","07/01/2025"},
	{"T008","A011","A011",900.000,"Deposit","08/01/2025"},
	{"T009","A016","A016",520.000,"Withdraw","09/01/2025"},
	{"T010","A023","A030",1100.000,"Transfer","10/01/2025"},
	{"T011","A006","A006",650.000,"Deposit","11/01/2025"},
	{"T012","A015","A015",300.000,"Withdraw","12/01/2025"},
	{"T013","A004","A022",980.000,"Transfer","13/01/2025"},
	{"T014","A020","A020",1500.000,"Deposit","14/01/2025"},
	{"T015","A017","A017",450.000,"Withdraw","15/01/2025"},
	{"T016","A025","A003",2100.000,"Transfer","16/01/2025"},
	{"T017","A029","A029",700.000,"Deposit","17/01/2025"},
	{"T018","A008","A008",360.000,"Withdraw","18/01/2025"},
	{"T019","A019","A024",1250.000,"Transfer","19/01/2025"},
	{"T020","A012","A012",800.000,"Deposit","20/01/2025"},
	{"T021","A002","A002",470.000,"Withdraw","21/01/2025"},
	{"T022","A028","A014",1680.000,"Transfer","22/01/2025"},
	{"T023","A030","A030",540.000,"Deposit","23/01/2025"},
	{"T024","A013","A013",310.000,"Withdraw","24/01/2025"},
	{"T025","A009","A018",2000.000,"Transfer","25/01/2025"},
	{"T026","A024","A024",900.000,"Deposit","26/01/2025"},
	{"T027","A001","A001",400.000,"Withdraw","27/01/2025"},
	{"T028","A026","A005",1550.000,"Transfer","28/01/2025"},
	{"T029","A022","A022",650.000,"Deposit","29/01/2025"},
	{"T030","A011","A011",380.000,"Withdraw","30/01/2025"},
};
int transactionSize = 30;

// Nguyen mau ham
void printMenu();
void addAccount();
void updateInfor();
void lockAccount();
void searchAccount();
void showAccPaginate();
void sortAccounts();
void transferMoney();

// Ham main
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
				searchAccount();
				break;
			case 5:
				showAccPaginate();
				break;
			case 6:
				sortAccounts();
				break;
			case 7:
				transferMoney();
				break;
			case 8:
				break;
			case 9:
				printf("Thoat chuong trinh!\n");
				return 0;
			default:
				printf("Lua chon khong hop le. Vui long chon lai (1-9).\n");
		}
	}
	return 0;
}
// In menu
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
	if (accountSize >= MAX) {	//kiem tra mang day hay ch
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
		// Kiem tra rong
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

		if (strlen(accountList[accountSize].phone) != 10) { // nhap sdt dung 10 so
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

	// nhap id
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
	printf("|%-10s|%-30s|%-10s|%-20.3lf|%-10s|\n",
	       accountList[found].accountId,
	       accountList[found].fullName,
	       accountList[found].phone,
	       accountList[found].balance,
	       accountList[found].status == 1? "Active" : "Locked");
	printf("+----------+------------------------------+----------+--------------------+----------+\n");

	// Nhap ten
	char newName[50];
	printf("Nhap Ho va Ten moi: ");
	fgets(newName, sizeof(newName), stdin);
	newName[strcspn(newName, "\n")] = '\0';

	if (strlen(newName) > 0) {
		strcpy(accountList[found].fullName, newName);
	}

	// Nhap sdt
	while (1) {
		printf("Nhap SDT moi: ");
		char newPhone[15];
		fgets(newPhone, sizeof(newPhone), stdin);
		newPhone[strcspn(newPhone, "\n")] = '\0';

		// bo trong
		if (strlen(newPhone) == 0) {
			break;
		}

		if (strlen(newPhone) < 10) {
			printf("SDT khong hop le!\n");
			continue;
		}

		// Kiem tra trung lap
		int duplicate = 0;
		for (int i = 0; i < accountSize; i++) {
			if (i != found && strcmp(newPhone, accountList[i].phone) == 0) {
				duplicate = 1;
				break;
			}
		}

		if (duplicate) {
			printf("SDT bi trung - Vui long nhap lai!\n");
			continue;
		}

		strcpy(accountList[found].phone, newPhone); //thoa man cac dkien thi gan
		break;
	}

	printf("Cap nhat thanh cong!!!\n");
}
// Khoa tai khoan
void lockAccount() {
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
	}

	printf("\n+-------------------------------- Thong tin hien tai --------------------------------+\n");
	printf("\n+----------+------------------------------+----------+--------------------+----------+\n");
	printf("|%-10s|%-30s|%-10s|%-20s|%-10s|\n","Ma ID","Ho va Ten","SDT","So du tai khoan","Trang thai");
	printf("+----------+------------------------------+----------+--------------------+----------+\n");
	printf("|%-10s|%-30s|%-10s|%-20.3lf|%-10s|\n",
	       accountList[found].accountId,
	       accountList[found].fullName,
	       accountList[found].phone,
	       accountList[found].balance,
	       accountList[found].status == 1 ? "Active" : "Locked");
	printf("+----------+------------------------------+----------+--------------------+----------+\n");

	char confirm; // xac nhan muon khoa hay khong
	printf("Xac nhan khoa(Y/N)?: ");
	scanf("%c", &confirm);
	getchar();
	if (confirm == 'Y' || confirm == 'y') {
		accountList[found].status = 0;
		printf("Khoa tai khoan thanh cong!!!\n");
	} else if (confirm == 'N' || confirm == 'n') {
		printf("Huy thao tac.\n");
	} else {
		printf("Sai cu phap - Vui long nhap lai!\n");
	}
}
// Tim tai khoan
void searchAccount() {
    char keyword[50];
    char lowerKeyword[50];
    char lowerId[20];
    char lowerName[50];
    int found = 0; 
    
    printf("Nhap Ma ID hoac Ho Ten: ");
    fgets(keyword, sizeof(keyword), stdin);
    keyword[strcspn(keyword, "\n")] = 0;
    
    // Chuyen keyword sang chu thuong
    strcpy(lowerKeyword, keyword);
    for (int i = 0; lowerKeyword[i] != '\0'; i++) {
        if (lowerKeyword[i] >= 'A' && lowerKeyword[i] <= 'Z') {
            lowerKeyword[i] = lowerKeyword[i] + 32;
        }
    }
    printf("+----------+------------------------------+----------+--------------------+----------+\n");
    printf("|%-10s|%-30s|%-10s|%-20s|%-10s|\n", "Ma ID", "Ho va Ten", "SDT", "So du tai khoan", "Trang thai");
    printf("+----------+------------------------------+----------+--------------------+----------+\n");
    
    for (int i = 0; i < accountSize; i++) {
        // Chuyen id sang chu thuong
        strcpy(lowerId, accountList[i].accountId);
        for (int j = 0; lowerId[j] != '\0'; j++) {
            if (lowerId[j] >= 'A' && lowerId[j] <= 'Z') {
                lowerId[j] = lowerId[j] + 32;
            }
        }
        
        // Chuyen ten sang chu thuong
        strcpy(lowerName, accountList[i].fullName);
        for (int j = 0; lowerName[j] != '\0'; j++) {
            if (lowerName[j] >= 'A' && lowerName[j] <= 'Z') {
                lowerName[j] = lowerName[j] + 32;
            }
        }
        // Tin kiem
        if (strstr(lowerId, lowerKeyword) != NULL || strstr(lowerName, lowerKeyword) != NULL) {
            printf("|%-10s|%-30s|%-10s|%-20.3lf|%-10s|\n",
                   accountList[i].accountId,
                   accountList[i].fullName,
                   accountList[i].phone,
                   accountList[i].balance,
                   accountList[i].status == 1 ? "Active" : "Locked");
            found++;
        }
    }  
    printf("+----------+------------------------------+----------+--------------------+----------+\n");
    if (found == 0) {
        printf("Khong co ket qua phu hop !!!\n");
    } else {
        printf("Tim thay %d ket qua.\n", found);
    }
}
// Hien thi danh sach tai khoan
void showAccPaginate() {
	int page_number = 1;
	int page_size =10;
	// Tinh tong so trang
	int kq = accountSize/page_size;
	int total_pages = (accountSize % page_size == 0)? kq : kq+1;

	while (1) {
		printf("Moi ban chon so trang can xem (1-%d) : ", total_pages);
		scanf("%d", &page_number);
		// kiem tra dieu kien
		if (page_number < 1 || page_number > total_pages) {
			printf("Loi du lieu khong hop le !!\n");
			continue;
		}

		// Tinh vi tri bat dau va ket thuc
		int start = (page_number-1)*page_size;
		int end = start + page_size;
		printf("\n+--------------------------------------Trang %d/%d-------------------------------------+\n",page_number,total_pages);
		printf("\n+----------+------------------------------+----------+--------------------+----------+\n");
		printf("|%-10s|%-30s|%-10s|%-20s|%-10s|\n","Ma ID","Ho va Ten","SDT","So du tai khoan","Trang thai");
		for (int i = start; i < end && i < accountSize; i++) {
			printf("|%-10s|%-30s|%-10s|%-20.3lf|%-10s|\n",
			       accountList[i].accountId,
			       accountList[i].fullName,
			       accountList[i].phone,
			       accountList[i].balance,
			       accountList[i].status == 1 ? "Active" : "Locked");
		}
		printf("+----------+------------------------------+----------+--------------------+----------+\n");
		fflush(stdin);
		printf("Ban co muon thoat hay ko (y/n): ");
		char ch = getchar();
		if (ch == 'y' || ch == 'Y') {
			break;
		}
	}
}
// Sap xep tai khoan
void sortAccounts() {
	if (accountSize == 0) {
		printf("Khong co du lieu de sap xep!\n");
		return;
	}
	// 2 lua chon
	int choice;
	printf("1. Sap xep theo so du (giam dan)\n");
	printf("2. Sap xep theo ten (A-Z)\n");
	printf("Nhap lua chon: ");
	scanf("%d", &choice);
	getchar();

	switch (choice) {
		case 1:
			for (int i = 0; i < accountSize - 1; i++) {
				for (int j = 0; j < accountSize - i - 1; j++) {
					if (accountList[j].balance < accountList[j + 1].balance) { // Dieu kien giam dan
						struct Account temp = accountList[j];
						accountList[j] = accountList[j + 1];
						accountList[j + 1] = temp;
					}
				}
			}
			printf("Da sap xep theo so du giam dan!\n");
			break;
		case 2:
			for (int i = 0; i < accountSize; i++) {
				for (int j = 0; j < accountSize - i - 1; j++) {
					if (strcmp(accountList[j].fullName, accountList[j + 1].fullName) > 0) { // Dieu kien A - Z
						struct Account temp = accountList[j];
						accountList[j] = accountList[j + 1];
						accountList[j + 1] = temp;
					}
				}
			}
			printf("Da sap xep theo ten A-Z!\n");
			break;
		default:
			printf("Lua chon khong hop le!\n");
			return;
	}
	printf("Da sap xep xong! Chon lua chon 5 de xem danh sach! \n");
}
// Chuyen khoan
void transferMoney() {
	char senderId[20];
	char receiverId[20];
	double amount = 0;
	int foundSenderId = -1;
	int foundReceiverId = -1;

	// Nhap Id nguoi gui
	while (1) {
		printf("Nhap Id nguoi gui: ");
		fgets(senderId, sizeof(senderId), stdin);
		senderId[strcspn(senderId, "\n")] = '\0';
		if (strlen(senderId) == 0) {
			printf("Vui long nhap Id nguoi gui!!!\n");
			continue;
		}
		foundSenderId = -1;
		for (int i = 0; i < accountSize; i++) {
			if (strcmp(senderId, accountList[i].accountId) == 0) {
				foundSenderId = i;
				// Kiem tra trang thai
				if (accountList[i].status == 0) {
					printf("Tai khoan da bi khoa - Khong the thuc hien giao dich!\n");
					foundSenderId = -1;
				}
				break;
			}
		}
		if (foundSenderId == -1) {
			printf("Khong tim thay tai khoan hoac tai khoan bi khoa!\n");
			continue;
		}
		break;
	}

	// Nhap Id nguoi nhan
	while (1) {
		printf("Nhap ID nguoi nhan: ");
		fgets(receiverId, sizeof(receiverId), stdin);
		receiverId[strcspn(receiverId, "\n")] = '\0';
		if (strlen(receiverId) == 0) {
			printf("Vui long nhap ID nguoi nhan !!!\n");
			continue;
		}
		// Kiem tra trung
		if (strcmp(receiverId, senderId) == 0) {
			printf("ID nguoi nhan trung voi ID nguoi gui - Vui long nhap lai !!\n");
			continue;
		}
		foundReceiverId = -1;
		for (int i = 0; i < accountSize; i++) {
			if (strcmp(receiverId, accountList[i].accountId) == 0) {
				foundReceiverId = i;
				break;
			}
		}
		if (foundReceiverId == -1) {
			printf("Khong tim thay tai khoan nguoi nhan!!\n");
			continue;
		}
		break;
	}

	// Nhap va kiem tra so tien
	while (1) {
		printf("Nhap so tien: ");
		scanf("%lf", &amount);
		getchar();
		if (amount <= 0) {
			printf("So tien phai lon hon 0 - Vui long nhap lai !!\n");
			continue;
		}
		if (amount > accountList[foundSenderId].balance) {
			printf("So du khong du!! So du hien tai: %.3lf\n", accountList[foundSenderId].balance);
			continue;
		}
		break;
	}

	// Sua so du
	accountList[foundSenderId].balance -= amount;
	accountList[foundReceiverId].balance += amount;

	// Luu giao dich
	if (transactionSize < 50) {
		char transactionId[20];
		sprintf(transactionId, "T%d", transactionSize + 1);
		strcpy(transactionList[transactionSize].transactionId, transactionId);
		strcpy(transactionList[transactionSize].senderId, senderId);
		strcpy(transactionList[transactionSize].receiverId, receiverId);
		transactionList[transactionSize].amount = amount;
		strcpy(transactionList[transactionSize].type, "Transfer");
		strcpy(transactionList[transactionSize].date, "28/11/2025");
		transactionSize++;
	}

	printf("\nChuyen khoan thanh cong!\n");
	printf("So du nguoi gui con lai: %.3lf\n", accountList[foundSenderId].balance);
	printf("So du nguoi nhan: %.3lf\n", accountList[foundReceiverId].balance);
}


