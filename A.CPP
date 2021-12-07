#include <stdio.h>

struct hcn
{
	int x1, y1, x2, y2;
};
hcn a[100];
int x[100] = {};
int y[100] = {};
void sort(int arr[], int n)
{
	int temp;
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i; j < n; j++)
		{
			if (arr[i] > arr[j])
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}
void createXY(int n){
	int m=0;
	for (int i = 0; i < n; i++)
	{
		
		x[m] = a[i].x1;
		y[m]= a[i].y1;
		m = m + 1;
		x[m] = a[i].x2;
		y[m]= a[i].y2;
		m = m +1;

	}
	
}
void nhaphcn(int x[], int y[], int n)
{
	for (int i = 0; i < n; i++)
	{

		printf("nhap hinh chu nhat thu %d: \n", i + 1);
		printf("\tnhap x duoi trai: ");
		scanf("%d", &a[i].x1);
		printf("\tnhap y duoi trai: ");
		scanf("%d", &a[i].y1);

		printf("\tnhap x tren phai: ");
		scanf("%d", &a[i].x2);
		printf("\tnhap y tren phai: ");
		scanf("%d", &a[i].y2);
	}
	createXY(n);
}
bool ktthuoc(int i, int j, int n)
{
	for (int k = 0; k < n; k++)
	{
		if (a[k].x1 <= x[i - 1])
		{
			if (x[i] <= a[k].x2)
			{
				if (a[k].y1 <= y[j - 1])
				{
					if (y[j] <= a[k].y2)
					{
						return true;
					}
				}
			}
		}
	}
	return false;
}
int main()
{

	int n;
	int s = 0;
	printf("ban muon nhap bao nhieu HCN: ");
	scanf("%d", &n);
	nhaphcn(x,y,n);

	sort(x, 2 * n);
	sort(y, 2 * n);
	// for (int i = 0; i < n; i++)
	// {
	// 	printf("hcn(%d,%d), (%d,%d)\n", a[i].x1, a[i].y1, a[i].x2, a[i].y2);
	// }
	
	
	
	for (int i = 1; i < 2 * n; i++)
	{
		for (int j = 1; j < 2 * n; j++)
		{
			if(ktthuoc(i,j,n)){
				s = s+ (x[i]-x[i-1])*(y[j]-y[j-1]);
				//printf("hcn(%d,%d), (%d,%d)\n",x[i-1],y[j-1], x[i],y[j]);
			}
		}


	}
	printf("\n dien tich: %d", s);
	return 0;
}
