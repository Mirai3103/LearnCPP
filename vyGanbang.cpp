#include <stdio.h>
#include <math.h>
double bailam(double arr[],int n, double x){

    double min = abs(arr[0]-x);
    double rs = arr[0] ;
    for (int i = 1; i < n; i++)
    {
        double temp  = abs(arr[i]-x) ;
        if(temp< min){
            min = temp;
            rs = arr[i];
        }
    }
    return rs;
    
}
int main()
{
    double arr[] = {1,8,9,4.4,3,9,2,4.2,7,4.7,3};
    int n = 11;
    printf("%.3f",bailam(arr,n, 5.0));
    return 0;
}
