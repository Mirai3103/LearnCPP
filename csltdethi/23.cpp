
#include <iostream>
using namespace std;
struct Point
{
    int x;
    int y;
    int WhichQuarter(){
        if(x==0|| y == 0) return 0;
        if(x >0){
            if(y>0){
                return 1;
            }else{
                return 4;
            }
        }else{
            if(y>0){
                return 2;
            }else{
                return 3;
            }
        }
    }
};
void Nhap(Point *list, int n){
    for (int i = 0; i < n; i++)
    {
        cout << "Nhap toa do thu "<<i+1<<endl;
        cin >> (list[i].x) >> (list[i].y);

    }
    
}

void Yeucaubai(Point *list, int n){
    int Icounter =0, IICounter =0, IIICounter =0, IVCounter =0,CoordinateAxisCounter = 0;
    for (int i = 0; i < n; i++)
    {
        switch (list[i].WhichQuarter())
        {
        case 1:
            Icounter++;
            break;
        case 2:
            IICounter++;
            break;
        case 3:
            IIICounter++;
            break;
        case 4:
            IVCounter++;
            break;
        
        default:
            CoordinateAxisCounter++;
            break;
        }
    }
    cout << "so diem nam o phan tu thu nhat la: "<< Icounter<<endl;
    cout << "so diem nam o phan tu thu hai la: "<< IICounter<<endl;
    cout << "so diem nam o phan tu thu ba la: "<< IIICounter<<endl;
    cout << "so diem nam o phan tu thu bon la: "<< IVCounter<<endl;
    cout << "so diem nam tren truc toa do la: "<< CoordinateAxisCounter<<endl;
}

int main()
{
    int n;
    cout << "nhap so diem can nhap: ";
    cin >> n;
    Point *ListPoints = new Point[n];
    Nhap(ListPoints, n); 
    Yeucaubai(ListPoints, n);

    delete []ListPoints;
    ListPoints = nullptr;
    return 0;
}
