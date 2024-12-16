#include <stdio.h>
#include <math.h>
//Ham hien thi menu
int displayMenu(){
	int choice;
	// In menu ra ngoai man hinh
	printf("\n MENU \n");
    printf("1.Nhap vao so phan tu va tung phan tu\n");
	printf("2.Hien thi cac phan tu trong mang\n");
	printf("3.Tinh do dai mang\n");
	printf("4.Tinh tong cac phan tu trong mang\n");
	printf("5.Hien thi phan tu lon nhat\n");
	printf("6.Thoat\n");
	printf("Lua chon cua ban:");
	// Gia tri nhap vao tu nguoi dung
	scanf("%d", &choice);
	return choice;
}
// Ham nhap mang
void nhapMang(int *arr, int *size) {
    printf("Nhap so phan tu cua mang: ");
    scanf("%d", size);
    printf("Nhap cac phan tu cua mang:\n");
    for (int i = 0; i < *size; i++) {
        printf("Phan tu arr[%d]: ", i + 1);
        scanf("%d", &arr[i]);
    }
}
// Ham hien thi mang
void hienThiMang(int *arr, int size) {
	printf("Cac phan tu trong mang:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
// Ham tinh do dai mang
int tinhDoDaiMang(int size) {
    return size;
}
// Ham tinh tong cac phan tu trong mang
int tinhTongMang(int *arr, int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum;
}
// Ham tim phan tu lon nhat trong mang
int timMax(int *arr, int size) {
    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}
int main() {
    int choice;
    int size = 0;
	int arr[100];
    do {
    	// Hien thi menu va lay gia tri chon
    	choice = displayMenu();
        switch (choice) {
            // Nhap vao so phan tu va tung phan tu
			case 1:
				// Nhap hai so nguyen tu nguoi dung
				if(size < 0 || size > 100){
                	printf("So phan tu mang khong hop le");
                break;
            	} else {
            		nhapMang(arr, &size);
				}
				break;
            // Hien thi cac phan tu trong mang
            case 2:
            	if(size < 0 || size > 100){
                	printf("Xin hay nhap mang");
                break;
            	} else {
	            	hienThiMang(arr, size);
                }
                break;
            // Tinh do dai mang
            case 3:
            	// Nhap hai so nguyen tu nguoi dung
            	if(size < 0 || size > 100){
                	printf("Xin hay nhap mang");
                	break;
            	} else {
					printf("Do dai mang la: %d\n", tinhDoDaiMang(size));
				}
				break;
			// Tinh tong cac phan tu trong mang
			case 4:
				if(size < 0 || size > 100){
                	printf("Xin hay nhap mang");
                	break;
            	} else {
            		printf("Tong cac phan tu trong mang: %d\n", tinhTongMang(arr, size));
            	}
            	break;
			// Hien thi phan tu lon nhat
			case 5:
				if(size < 0 || size > 100){
                	printf("Xin hay nhap mang");
                	break;
            	} else {
            	printf("Phan tu lon nhat trong mang: %d\n", timMax(arr, size));
				}
				break;
            // Thoat chuong trinh
			case 6:
                printf("Ket thuc chuong trinh.\n");
                break;
            default: {
                printf("Lua chon khong hop le!\n");
                break;
            }
        }
    } while (choice != 6);
    return 0;
}


