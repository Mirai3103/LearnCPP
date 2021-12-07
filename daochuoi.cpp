#include <stdio.h>
#include <math.h>
#include <string.h>

const char x[]={
	'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P',
	'Q','R','S','T','U','V','X','Y','Z','W'
};

int main(int argc,char **argv){
	int k,b;
	char s[100];
	char out[100];
	printf("Nhap gia tri he co so 10: ");
	scanf("%d",&k);
	printf("Nhap co so can doi: ");
	scanf("%d",&b);
    if(b==16){
        printf("sang he 16: %X", k);
        return 0;
    }

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
		// strrev(s);
        for (i; i>=0; i--)
        {
            printf("%c",s[i]);
        }
        
		}
	return 0;
}