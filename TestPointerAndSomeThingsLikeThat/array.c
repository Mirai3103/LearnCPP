#include <stdio.h>


int istangdan(int *a,int n) 
{
 for (int i = 0; i < n-1; i++)
 {

     if(a[i] > a[i+1]) return 0;
 }
 return 1;
   
}

int main()
{
    int n = 3;
    int m = 4;
    int arr[m][n];

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d",&arr[i][j]);
        }
        
    }

    for (int i = 0; i < m; i++)
    {
        int *p = &arr[i][0];
        if(istangdan(p, n)){
            printf("dong %d tang dan\n",i+1);
        }else{
            printf("dong %d khong tang dan\n",i+1);
        }
        
    }
    


    // xuat mang
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%d; ",arr[i][j]);
        }
        printf("\n");
        
    }
    
    
    
    return 0;
}
