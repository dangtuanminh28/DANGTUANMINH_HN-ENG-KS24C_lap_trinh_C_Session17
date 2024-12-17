#include <stdio.h>
#include <string.h>

// Ham nhap chuoi
void nhapChuoi(char *str) {
    printf("Nhap vao chuoi: ");
    fflush(stdin); // Xoa bo dem truoc khi nhap
    fgets(str, 100, stdin); // Doc toi da 99 ky tu tu ban phim
    str[strcspn(str, "\n")] = '\0'; // Loai bo ky tu xuong dong neu co
}

// Ham in chuoi
void inChuoi(char *str) {
    printf("Chuoi vua nhap: %s\n", str);
}
// Ham dem so luong chu cai trong chuoi
int demChuCai(char *str) {
    int count = 0;
    while (*str != '\0') {
        if ((*str >= 'a' && *str <= 'z') || (*str >= 'A' && *str <= 'Z')) {
            count++;
        }
        str++;
    }
    return count;
}
// Ham dem so luong chu so trong chuoi
int demChuSo(char *str) {
    int count = 0;
    while (*str != '\0') {
        if (*str >= '0' && *str <= '9') {
            count++;
        }
        str++;
    }
    return count;
}
// Ham dem so luong ky tu dac biet trong chuoi
int demKyTuDacBiet(char *str) {
    int count = 0;
    while (*str != '\0') {
        if (!((*str >= 'a' && *str <= 'z') || (*str >= 'A' && *str <= 'Z') || (*str >= '0' && *str <= '9') || *str == ' ')) {
            count++;
        }
        str++;
    }
    return count;
}
int main() {
    char str[100]; // Mang chua chuoi
    int chon; // Lua chon cua nguoi dung
    do {
        // Hien thi menu
        printf("\nMENU\n");
        printf("1. Nhap vao chuoi\n");
        printf("2. In ra chuoi\n");
        printf("3. Dem so luong chu cai trong chuoi va in ra\n");
        printf("4. Dem so luong chu so trong chuoi va in ra\n");
        printf("5. Dem so luong ky tu dac biet trong chuoi va in ra\n");
        printf("6. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &chon);
        getchar(); // Loai bo ky tu xuong dong sau khi nhap lua chon
        switch (chon) {
            case 1:
                nhapChuoi(str);
                break;
            case 2:
                inChuoi(str);
                break;
            case 3:
                printf("So luong chu cai trong chuoi: %d\n", demChuCai(str));
                break;
            case 4:
                printf("So luong chu so trong chuoi: %d\n", demChuSo(str));
                break;
            case 5:
                printf("So luong ky tu dac biet trong chuoi: %d\n", demKyTuDacBiet(str));
                break;
            case 6:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le. Vui long nhap lai.\n");
        }
    } while (chon != 6);

    return 0;
}

