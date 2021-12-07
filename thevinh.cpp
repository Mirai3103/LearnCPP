#include <stdio.h>
#include <math.h>
#include <string>
#include <iostream>
using namespace std;

const char x[]={
	'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P',
	'Q','R','S','T','U','V','X','Y','Z','W'
};

int main(int argc,char **argv){
	int n,k,b;
	char s[100];
	printf("Nhap n: ");
	scanf("%d",&n);
	
	while(n--){
		printf("Nhap gia tri he co so 10: ");
		scanf("%d",&k);
		printf("Nhap co so can doi: ");
		scanf("%d",&b);
		if(k==0){
			printf("\nerror");
		} else {
			int i=0;
			while(k>0){
				int temp = k%b;
				k/=b;
				s[i++]=x[temp];
			}
			s[i]='\0';
			puts(s);
		}
	}
	return 0;
}
