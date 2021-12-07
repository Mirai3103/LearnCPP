#include <stdio.h>

// void nhaptensv(char *arr, int n){

// 	printf("hu");

int main() {
	int arr[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
	
	
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			printf("%3d",arr[i][j]);
		}
		printf("\n");
		
	}
	printf("dia chi bien arr %X \n", arr);
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			printf("arr[%d][%d] = %X ;  ",i,j,&arr[i][j]);
		}
		printf("\n\n");
		
	}

	printf("*arr = %X\n", *arr);
	printf("**arr = %X\n", **arr);
	printf("*(arr+1) = %X\n", *(arr+1));
	printf("**(arr+1) = %X\n", **(arr+1));

	int *p = &arr[0][0];

	printf("\n *(p+3) = %d", *(p+3) );
	

}