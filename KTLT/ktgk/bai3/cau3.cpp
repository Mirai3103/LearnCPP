#include <iostream>
#include <math.h>
using namespace std;

int *createArray(int length)
{
    return new int[length];
}

void inputArray(int *arr, int length)
{
    for (int i = 0; i < length; i++)
    {
        printf("Nhap arr[%d]: ", i);
        cin >> arr[i];
    }
}
void showArray(int *arr, int length)
{
    for (int i = 0; i < length; i++)
    {
        printf("%d, ", arr[i]);
    }
    cout << endl;
}
bool isPrimeNumber(int n)
{
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
            return false;
    }
    return n >= 2;
}
int primeNumberCount(int *arr, int length)
{
    int count = 0;
    for (int i = 0; i < length; i++)
    {
        if (isPrimeNumber(arr[i]))
        {
            count++;
        }
    }
    return count;
}
void sort(int *arr, int length)
{
    for (int i = 0; i < length; i++)
    {
        for (int j = i + 1; j < length; j++)
        {
            if (arr[i] > arr[j])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void tim3SoCoTichLonNhat(int *arr, int length)
{
    if (length < 3)
    {
        cout << "do dai mang khong du 3 phan thu!";
    }
    else
    {
        // sort(arr, length);da sort tang dan o cau b
        int tich1 = arr[0] * arr[1] * arr[length - 1];
        int tich2 = arr[length - 3] * arr[length - 2] * arr[length - 1];
        if (tich1 > tich2)
        {
            printf("3 so co tich lon nhat la: %d, %d, %d", arr[0], arr[1], arr[length - 1]);
        }
        else
        {
            printf("3 so co tich lon nhat la: %d, %d, %d", arr[length - 3], arr[length - 2], arr[length - 1]);
        }
    }
}
int main()
{
    int length;
    do
    {
        cout << "nhap do dai cua mang >0: ";
        cin >> length;
    } while (length <= 0);
    int *arr = createArray(length);
    inputArray(arr, length);
    cout << "mang vua nhap la: ";
    showArray(arr, length);
    printf("Mang co %d so nguyen to!\n", primeNumberCount(arr, length));
    sort(arr, length);
    cout << "Mang sau khi sap xep: ";
    showArray(arr, length);
    tim3SoCoTichLonNhat(arr, length);
    delete[] arr;
    return 0;
}

// vet can
// void tim3SoCoTichLonNhat(int *arr, int length)
// {
//     if (length < 3)
//     {
//         cout << "do dai mang khong du 3 phan thu!";
//     }
//     else
//     {
//         int x, y, z;
//         int tich = 1;
//         int max = arr[0] * arr[1] * arr[2];
//         for (int i = 0; i < length - 2; i++)
//         {
//             for (int j = i + 1; j < length - 1; j++)
//             {

//                 for (int k = j + 1; k < length; k++)
//                 {
//                     tich = arr[i] * arr[j] * arr[k];
//                     if (tich > max)
//                     {
//                         max = tich;
//                         x = arr[i];
//                         y = arr[j];
//                         z = arr[k];
//                     }
//                 }
//             }
//         }
//         printf("3 so co tich lon nhat la: %d, %d, %d", x, y, z);
//     }
// }