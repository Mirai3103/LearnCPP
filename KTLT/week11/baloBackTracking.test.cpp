#include <iostream>
#include <fstream>
using namespace std;

struct Item
{
    int giaTri;
    int khoiLuong;
    bool havePut;
    Item()
    {
        giaTri = khoiLuong = 0;
        havePut = false;
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
int weight;
int length;
Item *listItems;
int weightHienTai;
int giaTriHienTai = 0;
int giaTriLonNhat = 0;
bool *listItemDaDungMax;
void TRY(int start = 0)
{
    if (weightHienTai > weight)
    {
        return;
    }
    if (weightHienTai <= weight)
    {
        if (giaTriHienTai > giaTriLonNhat)
        {
            giaTriLonNhat = giaTriHienTai;
            for (int i = 0; i < length; i++)
            {
                if (listItems[i].havePut)
                {
                    listItemDaDungMax[i] = true;
                }
                else
                {
                    listItemDaDungMax[i] = false;
                }
            }
        }
    }
    for (int i = start; i < length; i++)
    {
        if (listItems[i].havePut == false)
        {
            if (weightHienTai + listItems[i].khoiLuong <= weight)
            {
                weightHienTai += listItems[i].khoiLuong;
                giaTriHienTai += listItems[i].giaTri;
                listItems[i].havePut = true;
                TRY(i);
                weightHienTai -= listItems[i].khoiLuong;
                giaTriHienTai -= listItems[i].giaTri;
                listItems[i].havePut = false;
            }
        }
    }
    return;
}
int main()
{
    listItems = readFile(weight, length);
    listItemDaDungMax = new bool[length];
    for (int i = 0; i < length; i++)
    {
        listItemDaDungMax[i] = false;
    }
    TRY();
    cout << giaTriLonNhat << endl;
    for (int i = 0; i < length; i++)
    {
        if (listItemDaDungMax[i])
        {
            cout << i + 1 << " ";
        }
    }
}