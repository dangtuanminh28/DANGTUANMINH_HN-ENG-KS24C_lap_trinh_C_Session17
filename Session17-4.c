#include <stdio.h>
// Ham nhap mang
void nhapMang(int *arr, int *n) {
    printf("Nhap so phan tu cua mang: ");
    scanf("%d", n);
    printf("Nhap cac phan tu cua mang:\n");
    for (int i = 0; i < *n; i++) {
        printf("Phan tu thu %d: ", i + 1);
        scanf("%d", arr + i);
    }
}
// Ham in cac so chan
void inSoChan(int *arr, int n) {
    printf("Cac phan tu la so chan: ");
    for (int i = 0; i < n; i++) {
        if (*(arr + i) % 2 == 0) {
            printf("%d ", *(arr + i));
        }
    }
    printf("\n");
}
// Ham kiem tra so nguyen to
int laSoNguyenTo(int num) {
    if (num < 2) return 0;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return 0;
    }
    return 1;
}
// Ham in cac so nguyen to
void inSoNguyenTo(int *arr, int n) {
    printf("Cac phan tu co so nguyen to la: ");
    for (int i = 0; i < n; i++) {
        if (laSoNguyenTo(*(arr + i))) {
            printf("%d ", *(arr + i));
        }
    }
    printf("\n");
}
// Ham dao nguoc mang
void swapArr(int *arr, int n) {
    printf("Mang sau khi dao nguoc la: ");
    for (int i = n - 1; i >= 0; i--) {
        printf("%d ", *(arr + i));
    }
    printf("\n");
}
// Ham sap xep mang tang dan
void sapXepTangDan(int *arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (*(arr + i) > *(arr + j)) {
                int temp = *(arr + i);
                *(arr + i) = *(arr + j);
                *(arr + j) = temp;
            }
        }
    }
}
// Ham sap xep mang giam dan
void sapXepGiamDan(int *arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (*(arr + i) < *(arr + j)) {
                int temp = *(arr + i);
                *(arr + i) = *(arr + j);
                *(arr + j) = temp;
            }
        }
    }
}
// Ham tim kiem phan tu
void timKiemPhanTu(int *arr, int n) {
    int x, found = 0;
    printf("Nhap phan tu can tim: ");
    scanf("%d", &x);
    printf("Phan tu %d xuat hien o cac vi tri: ", x);
    for (int i = 0; i < n; i++) {
        if (*(arr + i) == x) {
            printf("%d ", i + 1);
            found = 1;
        }
    }
    if (!found) {
        printf("Khong co trong mang.");
    }
    printf("\n");
}
int main() {
    int arr[100];
	int n = 0;
	int choice;
    do {
        printf("\nMENU\n");
        printf("1.Nhap vao so phan tu va tung phan tu\n");
        printf("2.In ra cac phan tu la so chan\n");
        printf("3.In ra cac phan tu la so nguyen to\n");
        printf("4.Dao nguoc mang\n");
        printf("5.Sap xep mang\n");
        printf("a.Tang dan\n");
        printf("b.Giam dan\n");
        printf("6.Tim kiem phan tu trong mang\n");
        printf("7.Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                nhapMang(arr, &n);
                break;
            case 2:
                inSoChan(arr, n);
                break;
            case 3:
                inSoNguyenTo(arr, n);
                break;
            case 4:
                swapArr(arr, n);
                break;
            case 5: {
                int subChoice;
                printf("Chon 1 de sap xep tang dan, chon 2 de sap xep giam dan: ");
                scanf("%d", &subChoice);
                if (subChoice == 1) {
                    sapXepTangDan(arr, n);
                    printf("Mang sau khi sap xep tang dan: ");
                    for (int i = 0; i < n; i++) {
                        printf("%d ", *(arr + i));
                    }
                } else if (subChoice == 2) {
                    sapXepGiamDan(arr, n);
                    printf("Mang sau khi sap xep giam dan: ");
                    for (int i = 0; i < n; i++) {
                        printf("%d ", *(arr + i));
                    }
                } else {
                    printf("Lua chon khong hop le. Vui long nhap lai.\n");
                }
                printf("\n");
                break;
            }
            case 6:
                timKiemPhanTu(arr, n);
                break;
            case 7:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le. Vui long nhap lai.\n");
        }
    } while (choice != 7);
    return 0;
}

