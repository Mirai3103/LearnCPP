#include <iostream>
#include <array>
using namespace std;

bool subStringIgnoreOrder(int *a, int lengthA, int *b, int lengthB, int start = 0, int currentA = 0)
{
    if (lengthB > lengthA || start == lengthB || currentA == lengthA)
        return false;
    if (b[start] == a[currentA])
    {
        if (start == lengthB - 1)
            return true;
        return subStringIgnoreOrder(a, lengthA, b, lengthB, start + 1, currentA + 1);
    }
    else
    {
        return subStringIgnoreOrder(a, lengthA, b, lengthB, start, currentA + 1);
    }
}

int main()
{
    int A[] = {1, 5, 2, 1, 3, 7, 2};
    int B[] = {5, 1, 2};
    int C[] = {1, 2, 7, 2};
    if (subStringIgnoreOrder(A, sizeof(A) / sizeof(int), C, sizeof(C) / sizeof(int)))
    {
        cout << " phai";
    }
    else
    {
        cout << " khong phai";
    }
    return 0;
}
