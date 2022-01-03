#include <stdio.h>
#include <math.h>

int nhapnguyenduong(){
	float n;
	printf("\nHay nhap so nguyen duong n: ");
	scanf("%f", &n);
	while (n<=0 || ((int) n)*1.0 != n)
	{
		printf("Nhap lai n: ");
		scanf("%f",&n);
	}

 	return (int)n;
}

void phantachthanhSNT(int &n){
	for(int i=2;i<=n;i++){
		int dem = 0;
		while(n%i==0){
			++dem;
			n=n/i;
		}
		if(dem){
			if(dem>1) printf ("%d^%d*",i,dem);
			else printf("%d*",i);
			if(n>i)
				printf("%d*",i);
		}
	}
}

int main(int argc,char **argv){
	
	int n = nhapnguyenduong();
	printf("%d",n);
	phantachthanhSNT(n);
	return 0;
}