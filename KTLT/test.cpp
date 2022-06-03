#include <iostream>
#include <math.h>
using namespace std;
// input:
// M = 13, N = 12
// 3 12 5 6 1 7 61 9 0 10 11 32 4
// 12 1 4 61 12 0 14 11 10 3 4 32
// output:
// 12 1 61 0 11 4

struct Node
{
    int data;
    int index;
};

int TRIANGLE[5][5] = {{7}, {3, 8}, {8, 1, 0}, {2, 7, 4, 4}, {4, 5, 100, 6, 5}};
void createTable(int n)
{
    Node *table = new Node[n];
    table[0].data = TRIANGLE[0][0];
    table[0].index = 0;
    for (int i = 1; i < n; i++)
    {
        table[i].data = max(table[i - 1].data + TRIANGLE[i][table->index], table[i - 1].data + TRIANGLE[i][table->index + 1]);
    }
    // print table data
    for (int i = 0; i < n; i++)
    {
        cout << table[i].data << " ";
    }
};
int main()
{
    createTable(5);
}