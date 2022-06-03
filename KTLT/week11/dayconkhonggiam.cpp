#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;

int *readArrFromFile(int &n)
{
    ifstream fi;
    fi.open("songuyen.inp");
    fi >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        fi >> arr[i];
    }
    fi.close();
    return arr;
}

struct BaSoLonNhat
{
    int max1, max2, max3;
    BaSoLonNhat(int init)
    {
        max1 = max2 = max3 = init;
    }
};

BaSoLonNhat tim(int *arr, int n)
{
    BaSoLonNhat result(INT32_MIN);
    if (n < 3)
    {
        cout << "??????";
        return result;
    }

    for (int i = 0; i < n; i++)
    {
        if (arr[i] > result.max1)
        {
            result.max3 = result.max2;
            result.max2 = result.max1;
            result.max1 = arr[i];
        }
        else if (arr[i] > result.max2 && arr[i] != result.max1)
        {
            result.max3 = result.max2;
            result.max2 = arr[i];
        }
        else if (arr[i] > result.max3 && arr[i] != result.max2 && arr[i] != result.max1)
        {
            result.max3 = arr[i];
        }
    }
    return result;
}

void printArr(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int doDaiDayConTangDaiNhat(int *arr, int n)
{
    int max = 1;
    int count = 1;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] < arr[i - 1])
        {
            if (max < count)
            {
                max = count;
            }
            count = 1;
        }
        else
        {
            count++;
        }
    }
    if (max < count)
    {
        max = count;
    }
    return max;
}
int main()
{
    int length = 0;
    int *arr = readArrFromFile(length);
    printArr(arr, length);
    BaSoLonNhat baSoLonNhat = tim(arr, length);
    int doDaiDayConKhongGiam = doDaiDayConTangDaiNhat(arr, length);
    ofstream fo;
    fo.open("ketqua.out");
    fo << baSoLonNhat.max1 << " " << baSoLonNhat.max2 << " " << baSoLonNhat.max3 << endl;
    fo << doDaiDayConKhongGiam;
    fo.close();
    return 0;
}