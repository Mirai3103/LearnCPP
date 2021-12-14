#include <iostream>
using namespace std;
struct test
{
    string name;
};
int main(int argc, char const *argv[])
{
    test a;
    cin >> a.name;
    cout << a.name;
    return 0;
}

