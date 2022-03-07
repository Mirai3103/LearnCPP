#include <iostream>
#include <chrono>
using namespace std::chrono;
 
// After function call

using namespace std;
int arr[100][100] = {{1}};
void pascal(int n)
{

    if (n == 0)
    {
        cout << "1" << endl;
        return;
    }
    pascal(n - 1);
    arr[n][0] = 1;
    arr[n][n] = 1;
    for (int i = 1; i < n; i++)
    {
        arr[n][i] = arr[n - 1][i - 1] + arr[n - 1][i];
    }
    for (int i = 0; i <= n; i++)
    {
        cout << arr[n][i] << " ";
    }
    cout << endl;
}
int Cnk(int n, int k){
    if(k==0||k==n) return 1;
    if(k>n) return 0;
    return Cnk(n-1,k)+Cnk(n-1,k-1);
}
int main()
{
    // auto start = high_resolution_clock::now();
    // pascal(4);
    // auto stop = high_resolution_clock::now();
    // auto duration = duration_cast<microseconds>(stop - start);
    // cout << duration.count() << endl;
    cout << Cnk(9,4);
}