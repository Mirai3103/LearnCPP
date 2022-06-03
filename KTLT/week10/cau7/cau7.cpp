#include <iostream>
#include <fstream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

struct Element
{
    int sum, i, j;
    Element(int sum, int i, int j) : sum(sum), i(i), j(j) {}
    Element(){};
};
struct BoBa
{
    int a, b, c;
    BoBa(int a, int b, int c) : a(a), b(b), c(c) {}
};
int pivot(Element *arr, int left, int right);
void quickSort(Element *arr, int left, int right);
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

int binarySrearch(vector<Element> &arr, int x)
{
    int left = 0;
    int right = arr.size() - 1;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (arr[mid].sum >= x)
        {
            right = mid - 1;
            if (arr[mid].sum == x)
                return mid;
        }
        else
        {
            left = mid + 1;
        }
    }
    return -1;
}

int solution(int *arr, int n)
{
    vector<Element> Sum2;
    for (int i = 0; i < n; i++)
    {

        for (int j = i + 1; j < n; j++)
        {

            Sum2.push_back(Element(arr[i] + arr[j], i, j));
        }
    }
    sort(Sum2.begin(), Sum2.end(), [](Element &a, Element &b)
         { return a.sum < b.sum; });

    vector<Element> SumX3MX2;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            SumX3MX2.push_back(Element(3 * arr[i] - arr[j], i, j));
        }
    }
    // vector<BoBa> boBa;
    int count = 0;
    for (int i = 0; i < SumX3MX2.size(); i++)
    {

        int isFind = binarySrearch(Sum2, SumX3MX2[i].sum);
        if (isFind != -1)
        {
            for (int j = isFind; j < Sum2.size(); j++)
            {
                if (Sum2[j].sum > SumX3MX2[i].sum)
                    break;
                if (Sum2[j].i != j && Sum2[j].j != i)
                {
                    count++;
                }
            }
        }
    }
    cout << count;
    return count;
}
int pivot(Element *arr, int left, int right)
{
    int pivot = arr[left].sum;
    while (left < right)
    {
        while (left < right && arr[right].sum >= pivot)
            right--;
        arr[left] = arr[right];
        while (left < right && arr[left].sum <= pivot)
            left++;
        arr[right] = arr[left];
    }
    arr[left].sum = pivot;
    return left;
}
void quickSort(Element *arr, int left, int right)
{
    if (left < right)
    {
        int Pivot = pivot(arr, left, right);
        quickSort(arr, left, Pivot - 1);
        quickSort(arr, Pivot + 1, right);
    }
}

int main()
{
    int n;
    int *arr = readFile(n);
    ofstream fileOut;
    fileOut.open("BAI7.OUT");
    fileOut << solution(arr, n);
    fileOut.close();
    return 0;
}
