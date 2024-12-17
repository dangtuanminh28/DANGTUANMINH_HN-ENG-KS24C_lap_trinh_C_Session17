#include <stdio.h>
// Ham tinh do dai chuoi (khong dung strlen)
int tinhDoDaiChuoi(char *str) {
    int dem = 0;
    while (*(str + dem) != '\0') {
        dem++;
    }
    return dem;
}
// Ham nhap chuoi
void nhapChuoi(char *str) {
    printf("Nhap chuoi: ");
    fgets(str, 200, stdin);
    // Loai bo ky tu xuong dong neu co
    int len = tinhDoDaiChuoi(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
}
// Ham dao nguoc chuoi
void daoNguocChuoi(char *str) {
    int len = tinhDoDaiChuoi(str);
    printf("Chuoi dao nguoc: ");
    for (int i = len - 1; i >= 0; i--) {
        printf("%c", *(str + i));
    }
    printf("\n");
}
// Ham dem so tu trong chuoi
int demSoTu(char *str) {
    int dem = 0, trongTu = 0;
    while (*str != '\0') {
        if (*str != ' ') {
            if (trongTu == 0) {
                dem++;
                trongTu = 1;
            }
        } else {
            trongTu = 0;
        }
        str++;
    }
    return dem;
}
// Ham so sanh do dai hai chuoi
void soSanhChuoi(char *str1, char *str2) {
    int len1 = tinhDoDaiChuoi(str1);
    int len2 = tinhDoDaiChuoi(str2);
    if (len1 > len2) {
        printf("Chuoi moi ngan hon chuoi ban dau.\n");
    } else if (len1 < len2) {
        printf("Chuoi moi dai hon chuoi ban dau.\n");
    } else {
        printf("Hai chuoi co do dai bang nhau.\n");
    }
}
// Ham chuyen chuoi sang chu in hoa
void inHoaChuoi(char *str) {
    printf("Chuoi in hoa: ");
    while (*str != '\0') {
        if (*str >= 'a' && *str <= 'z') {
            printf("%c", *str - 32); // Chuyen chu thuong sang chu hoa
        } else {
            printf("%c", *str);
        }
        str++;
    }
    printf("\n");
}
// Ham noi chuoi
void noiChuoi(char *str1, char *str2) {
    int i = tinhDoDaiChuoi(str1); // Vi tri bat dau noi
    int j = 0;
    while (str2[j] != '\0') {
        str1[i] = str2[j];
        i++;
        j++;
    }
    str1[i] = '\0'; // Ket thuc chuoi
    printf("Chuoi sau khi noi: %s\n", str1);
}
int main() {
    char chuoi1[200] = "", chuoi2[100] = "";
    int luaChon;
    do {
        printf("\nMENU\n");
        printf("1. Nhap vao chuoi\n");
        printf("2. In ra chuoi dao nguoc\n");
        printf("3. Dem so luong tu trong chuoi\n");
        printf("4. Nhap chuoi khac va so sanh do dai\n");
        printf("5. In hoa tat ca chu cai trong chuoi\n");
        printf("6. Nhap chuoi khac va noi vao chuoi ban dau\n");
        printf("7. Thoat\n");
        printf("Lua chon cua ban: ");
        scanf("%d", &luaChon);
        getchar(); // Loai bo ky tu xuong dong
        switch (luaChon) {
            case 1:
                nhapChuoi(chuoi1);
                break;
            case 2:
                daoNguocChuoi(chuoi1);
                break;
            case 3:
                printf("So tu trong chuoi: %d\n", demSoTu(chuoi1));
                break;
            case 4:
                printf("Nhap chuoi moi: ");
                nhapChuoi(chuoi2);
                soSanhChuoi(chuoi1, chuoi2);
                break;
            case 5:
                inHoaChuoi(chuoi1);
                break;
            case 6:
                printf("Nhap chuoi can noi: ");
                nhapChuoi(chuoi2);
                noiChuoi(chuoi1, chuoi2);
                break;
            case 7:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le, vui long thu lai.\n");
        }
    } while (luaChon != 7);
    return 0;
}

