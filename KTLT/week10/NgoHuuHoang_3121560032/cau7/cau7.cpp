#include <iostream>
#include <fstream>
using namespace std;

int *readFile(int &n)
{
    ifstream fileIn;
    fileIn.open("BAI7.INP");
    fileIn >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        fileIn >> arr[i];
    }
    fileIn.close();
    return arr;
}

int count(int *arr, int n)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                for (int l = 0; l < n; l++)
                {
                    if (arr[i] + arr[j] + arr[k] == arr[l] * 3)
                    {
                        printf("%d %d %d --> %d\n", arr[i], arr[j], arr[k], arr[l]);
                        count++;
                    }
                }
            }
        }
    }
    return count;
}

int main()
{
    int n;
    int *arr = readFile(n);
    ofstream fileOut;
    fileOut.open("BAI7.OUT");
    fileOut << count(arr, n);
    fileOut.close();
    return 0;
}
