#include <iostream>
using namespace std;

struct Product
{
    private:
        string Name;
        string ProducerName;
        double Price;
    public:
        Product(){}
        Product(string name, string producerName, double price)
        :Name(name), ProducerName(producerName), Price(price){};
        void ShowInfo(){
            cout << "Ten san pham: "<<Name <<", Nha san xuat: "<<ProducerName<<", Gia: "<<Price<<endl;
        }
        void InputInfo(){
            cout << "Nhap ten san pham: ";
            cin >> this->Name;
            cout << "Nhap ten nha san xuat: ";
            cin >> this->ProducerName;
            cout << "Nhap gia san pham: ";
            cin >> this->Price;
        }
};

void ShowMenu(){
    cout << "\t=====Menu====="<<endl;
    cout <<"1. Nhap thong tin cho n san pham"<<endl;
    cout <<"2. Hien thi thong tin vua nhap"<<endl;
    cout <<"3. Xap xep thong tin giam dan theo gia va hien thi"<<endl;
    cout <<"4. Thoat"<<endl;
    cout <<"Nhap lua chon cua ban ( 1/ 2/ 3/ 4 ):"<<endl;
}

int main()
{
    /* code */
    return 0;
}
