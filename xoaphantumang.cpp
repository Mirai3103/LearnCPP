#include <stdio.h>

void hienThi(int arr[], int n) {
	int i;
	for(i = 0; i < n; i++) {
		printf("%d, ", arr[i]);
	}
}
int main()
{
    int x = 11;
    int arr[] = {2,3,4,5,6,7,8,11,11,9,12,11,76,34,59,63,23,12,11};
   
    int n = sizeof(arr)/sizeof(arr[0]); // độ dài mảng
     hienThi(arr, n);
    int newArr[n]={0};
    int j=0;
    printf("\nsau khi xoa so 11\n");
    for (int i = 0; i < n; i++)
    {
        if(arr[i]!=x){
            newArr[j] = arr[i];
            j++;
        }
    }
    // hienthi(newArr,j);// neu chi xuat thi toi day la xong;
    int returnArr[j];// resize lai mang de phuc vu cho viec tinh toan
    for (int i = 0; i < j; i++)
    {
        returnArr[i] = newArr[i];
    }
    hienThi(returnArr, j);
    
    
    return 0;
}
