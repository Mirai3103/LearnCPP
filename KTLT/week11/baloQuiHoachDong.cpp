#include <iostream>
#include <fstream>
using namespace std;

struct Item
{
    int giaTri;
    int khoiLuong;
    Item()
    {
        giaTri = khoiLuong = 0;
    }
    void show()
    {
        cout << "gia tri: " << giaTri << " ";
        cout << "khoi luong: " << khoiLuong << endl;
    }
};

Item *readFile(int &weigth, int &length)
{
    ifstream file("balo.inp");
    file >> length >> weigth;
    Item *items = new Item[length];
    for (int i = 0; i < length; i++)
    {
        file >> items[i].khoiLuong >> items[i].giaTri;
    }
    file.close();
    return items;
}
void createTable(int maxWeight, int numberOfItem, Item *items)
{

    Item **table = new Item *[maxWeight + 1];
    for (int i = 0; i <= maxWeight; i++)
    {
        table[i] = new Item[numberOfItem + 1];
    }
    for (int i = 0; i <= maxWeight; i++)
    {
        for (int j = 0; j <= numberOfItem; j++)
        {
            if (i == 0 || j == 0)
            {
                table[i][j].giaTri = 0;
                table[i][j].khoiLuong = 0;
            }
            else if (items[j - 1].khoiLuong <= i)
            {
                int temp = table[i][j - 1].giaTri;
                if (items[j - 1].giaTri + table[i - items[j - 1].khoiLuong][j - 1].giaTri > temp)
                {
                    temp = items[j - 1].giaTri + table[i - items[j - 1].khoiLuong][j - 1].giaTri;
                }
                table[i][j].giaTri = temp;
                table[i][j].khoiLuong = items[j - 1].khoiLuong;
            }
            else
            {
                table[i][j].giaTri = table[i][j - 1].giaTri;
                table[i][j].khoiLuong = 0;
            }
        }
    }
    ofstream fo;
    fo.open("balo.out");
    fo << table[maxWeight][numberOfItem].giaTri << endl;
    cout << table[maxWeight][numberOfItem].giaTri << endl;

    int i = maxWeight;
    int j = numberOfItem;
    while (i > 0 && j > 0)
    {
        if (table[i][j].giaTri == table[i][j - 1].giaTri)
        {
            j--;
        }
        else
        {
            cout << j << " ";
            fo << j << " ";
            i -= table[i][j].khoiLuong;
            j--;
        }
    }
}
main()
{
    int weight;
    int length;
    Item *listItems = readFile(weight, length);
    createTable(weight, length, listItems);
    // todo: ghi vao file
}