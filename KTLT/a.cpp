#include <stdio.h>
#include <string.h>


// ** Hàm thêm 1 kí tự vào vị trí bất kỳ trong chuỗi
void Add_1_Element_To_The_String(char a[], int vitrithem, char phantumuonthem)
{
    int i;
    for (i = strlen(a); i >= vitrithem; i--)
    {
        a[i + 1] = a[i];
    }
    a[vitrithem] = phantumuonthem;
}

int main()
{
	char s[30] = "";
	printf("\nDo dai cua chuoi: %d", 30);
	printf("\nNhap ho ten cua sinh vien: ");
	fgets(s, 30, stdin);
	printf("\nChuoi truoc khi them: %s", s);
	int n;
	char k;
	printf("\nNhap vi tri muon them: ");

	scanf("%d", &n);
getchar();
	printf("\nNhap phan tu muon them: ");
	scanf("%c", &k);
	Add_1_Element_To_The_String(s, n, k);
	printf("Chuoi sau khi them: %s", s);
	getchar();
	return 0;
}