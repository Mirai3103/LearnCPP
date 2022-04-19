#include <stdio.h>
/* viet chuong trinh  cho phep nguoi dung nhap vao ho vA TEN. tim va in ra man hinh:
 - so ki tu co trong ho ten vua duoc nhap
 - so luong tu vua nhap.
 */

int demSoKiTu(char str[]){
	int i =0;
	while(str[i]!='\0'){
		i++;
	}
	return --i;
}

int demSoLuongTu(char str[]){
	int i =0;
	int count = 0;
	while(str[i]!='\0'){
		i++;
		if(str[i]==' '){
			count++;
		}
	}
	return ++count;
}
int main(){
	char ten[100];
	printf("Nhap vao ho va ten: ");
	fgets(ten,100, stdin);
	printf("so ki tu la: %d", demSoKiTu(ten));
	printf("\n");
	printf("so tu la: %d", demSoLuongTu(ten));
}