#include <stdio.h>

int nhapnguyenduong(){
	float n;
	scanf("%f", &n);
	while (n<=0 || ((int) n)*1.0 != n)
	{
		printf("nhap lai: ");
		scanf("%f", &n);
	}
	return (int)n;
}

int main() {
	int so = nhapnguyenduong();
	printf("%d",so);
}