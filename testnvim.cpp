#include <stdio.h>
void nhapmang(int a[],int n){
    for(int i=0;i<n;i++){
        printf("\nNhap gia tri a[%d]= ",i);
        scanf("%d",&a[i]);
    }
}
void xuatmang(int a[],int n){
    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }
}
int daonguoc(int n)
{          
   int sdn=0;
   while (n!=0)
   {
      sdn=sdn*10+n%10;
      n=n/10;
   }
   return sdn;
}
int soganhdautien(int a[], int n)
{
   for (int i=0; i<n; i++){
	   if (daonguoc(a[i]) == a[i]){
		   return 1;
	   }     
   }
      
   return 0;
}
int main(){
	int a[100];
	int n; scanf("%d", &n);
	nhapmang(a,n);
	soganhdautien(a,n);
}