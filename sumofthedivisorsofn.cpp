#include <stdio.h>

// map<int,int> primeFactorization(int n){
//         map<int, int> primefactorizations ;
//     int i = 2;
//     while (n!=1)
//     {   
//         if(n % i == 0) primefactorizations[i]=0;
//         while (n % i == 0)
//         {
//             n = n / i;
//             primefactorizations[i]++;
//         }
//         i++;
//     }
    
//     return primefactorizations;
// }

// int sumofthedivisors(map<int, int> primefactorizations){
//     int sum=1;
//     int temp, powers,thuaso;
//     for (auto const &value : primefactorizations)
//     {
//         temp = 0;
//         powers = 1;
//         thuaso = value.first;
//         for (int i = 0; i <= value.second; i++)
//         {
//             temp = temp + powers;
//             powers = powers*thuaso;
//         }
//         sum = sum * temp;
//     }

//     return sum;
    
// }
// bool isPerfectNumber(int n){
//     return 2*n == sumofthedivisors(primeFactorization(n));
// }

int tonguoc(int n){
    int sum=1;
    int n2 = n;
    int temp, powers,thuaso;
    int i = 2;
    while (n!=1)
    {   temp = 1;
        thuaso =i;
        powers = 1;
        while (n % i == 0)
        {
            n = n / i;//6//3
            powers = powers*thuaso;// 2//4
            temp = temp + powers; // 3//7
            
        }
        sum = sum * temp;
        i++;
    }

    return (sum - n2);
}
int main()
{
    int n = 1000000;
    for (int i = 2; i < n; i++)
    {
        int tong = tonguoc(i);
        if(tong <= i){
            continue;
        }
        if(tong < n){
            if(tonguoc(tong)==i){
                printf("%d va %d \n",i, tong);
            }
        }
    }
    return 0;
}
