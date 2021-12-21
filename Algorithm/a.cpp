#include <iostream>

using namespace std;

struct Item
{
    int giatri;
    int kichthuoc;
    Item(int gt, int kt)
    {
        giatri = gt;
        kichthuoc = kt;
    }
};

void giaiquyet(Item list[], int start, int soItem, int TrongLuongTui, int &max, int &TongKTDaLay, int &giaTriDaLay)
{
    for (int i = start; i < soItem; i++)
    {
        if (TongKTDaLay + list[i].kichthuoc <= TrongLuongTui)
        {

            // lay do
            TongKTDaLay += list[i].kichthuoc;
            giaTriDaLay += list[i].giatri;
            // xem so do da lay
            if (giaTriDaLay > max)
                max = giaTriDaLay;
               
            giaiquyet(list, start + 1, soItem, TrongLuongTui, max, TongKTDaLay, giaTriDaLay);
            TongKTDaLay -= list[i].kichthuoc;
            giaTriDaLay -= list[i].giatri;
        }

    }   
}
int main()
{
    int SoItem = 6;
    int TrongLuongTui = 19;
    int max, tongdalay, giatridalay;
    Item listItem[] = {Item(7, 3), Item(10, 4), Item(20, 5), Item(19, 7), Item(13, 6), Item(40, 9)};
    giaiquyet(listItem, 0, SoItem, TrongLuongTui, max,tongdalay, giatridalay);
    cout <<  max ;
    return 0;
}
