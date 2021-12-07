
#include <stdio.h>
#include <stdbool.h>

typedef struct phanso{
	int tu,mau;
}phanso;

void input2Array(phanso arr[100][100],int n, int m){
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			printf("\nNhap phan so o %dx%d : ",++i,++j);
			i=--i;
			j=--j;
			printf("\nNhap tu so: ");
			scanf("%d",&arr[i][j].tu);
			printf("\nNhap mau so: ");
			scanf("%d",&arr[i][j].mau);
		}
	}
}

void compact(phanso arr[100][100],int n,int m){
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			float a=arr[i][j].tu;
			float b=arr[i][j].mau;
			int ucln=1;

			if(a==0){
				ucln=(a+b); 
			}else{
				while(a!=b){
					if(a>b) a=a-b;
					else b=b-a;
				}
				ucln=a;
			}
			arr[i][j].tu = arr[i][j].tu/ucln;
			arr[i][j].mau = arr[i][j].mau/ucln;
		}
	}
}
void output2Arry(phanso arr[100][100], int n, int m){
	compact(arr,n,m);
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			printf("\t %d/%d",arr[i][j].tu,arr[i][j].mau);
		}
		printf("\n");
	}
}

int ucln(int a, int b){
    int r;
    while (a % b != 0){
        r = a % b;
        a = b;
        b = r;
    }
    return b;
}

phanso rutGon(phanso &p) {
	if(p.tu!= 0){
		int u = ucln(p.tu, p.mau);
		p.tu/= u;
		p.mau/= u;
	}
	return p;
}

phanso maxArray(phanso arr[100][100],int m, int n){
	int a,b;
	int i,j;
	phanso max=arr[0][0];
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			a=max.tu*arr[i][j].mau;
			b=max.mau*arr[i][j].tu;
			if(a<b){
				max = arr[i][j];
			}
		}
	}
	return max;
}

void outputMaxArray(phanso x){
	printf("\nPhan so lon nhat trong mang la: %d/%d",x.tu,x.mau);
}

phanso totalArry(phanso arr[100][100], int n , int m){

	phanso total = arr[0][0];
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			total.tu=total.tu*arr[i][j].mau+total.mau*arr[i][j].tu;
			total.mau=total.mau*arr[i][j].mau;
		}
	}
	return total;
}

void xuli(phanso arr[100][100]){
	phanso tong = totalArry(arr,m,n);
	tong.tu=tong.tu*arr[0][0].mau-tong.mau*arr[0][0].tu;
	tong.mau=tong.mau*arr[0][0].mau;
	printf("\nTong cac phan so da cho la: %d/%d",tong.tu,tong.mau);
}

int main(int argc, char **argv){
	int n,m;
	phanso arr[100][100];
	printf("\nNhap do dai cua mang theo hang: ");
	scanf("%d",&n);
	printf("\nNhap do dai cua mang theo cot: ");
	scanf("%d",&m);
	input2Array(arr,n,m);
	phanso x = maxArray(arr,n,m);
	outputMaxArray(x);
	xuli(arr);
	return 0;
}