#include <stdio.h>

void nhapmang(int a[],int &n);
int gtln(int a[],int n);


int main(int argc, char**argv){
	int n;
	printf("Nhap do dai cua mang: ");
	scanf("%d",&n);
    int a[n];
    nhapmang(a,n);
    int vitri=gtln(a,n);
	printf("\nPhan tu lon nhat o vi tri %d co gia tri la: %d",vitri,a[vitri-1]);
	return 0;
}

void nhapmang(int a[],int &n){
	for(int i=0;i<n;i++){
        printf("\na[%d]= ",i);
		scanf("%d",&a[i]);
	}
}


int gtln(int a[],int n){
	int max=a[0];
	int c ; // sua thanh int c = 0
	for(int i = 0;i<n;i++){
		if(max<a[i]){
			max=a[i];
			c=i;
		}
	}
	return ++c;
}