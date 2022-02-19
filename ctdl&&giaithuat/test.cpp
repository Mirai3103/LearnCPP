#include <iostream>
using namespace std;
struct ListAuthors
{
    char nameOfAuthors[10][100];
    int length;
};

struct Book
{
    char title[100];
    ListAuthors Authors;
    int yearOfPublication;
};
void inputListAuthors(ListAuthors &listAuthor)
{
    cout << "\nnhap so luong tac gia: ";
    cin >> listAuthor.length;
    fflush(stdin);
    for (int i = 0; i < listAuthor.length; i++)
    {
        std::cout << "Nhap ten tac gia thu " << i + 1 << ": ";
        std::cin.getline(listAuthor.nameOfAuthors[i], 100);
    }
}
void showListAuthors(ListAuthors listAuthor)
{
    cout << "ten tac gia: ";
    for (int i = 0; i < listAuthor.length; i++)
    {
        cout << listAuthor.nameOfAuthors[i] << ", ";
    }
    cout << endl;
}
void inputBook(Book &a)
{
    fflush(stdin);
    std::cout << "Nhap ten sach: ";
    std::cin.getline(a.title, 100);
    fflush(stdin);
    std::cout << "Nhap danh sach tac gia: ";
    inputListAuthors(a.Authors);
    std::cout << "Nhap nam xuat ban: ";
    std::cin >> a.yearOfPublication;
}
void addBooks(Book listBooks[], int &length)
{
    std::cout << "Nhap so sach can them: ";
    int canthem = 0;
    std::cin >> canthem;
    int i = length;
    length += canthem;
    for (int i = length; i < canthem; i++)
    {
        std::cout << "Nhap thong tin cuon sach thu " << i + 1 << ":\n";
        inputBook(listBooks[i]);
    }
}
void inputListBook(Book listBooks[], int &length)
{
    std::cout << "Nhap so luong sach: ";
    std::cin >> length;
    for (int i = 0; i < length; i++)
    {
        std::cout << "Nhap thong tin cuon sach thu " << i + 1 << ":\n";
        inputBook(listBooks[i]);
    }
}
void display(Book listBooks[], int length)
{
    for (int i = 0; i < length; i++)
    {
        std::cout << endl
                  << i + 1 << ". ";
        std::cout << "Ten sach: " << listBooks[i].title << endl;
        showListAuthors(listBooks[i].Authors);
        std::cout << "Nam xuat ban: " << listBooks[i].yearOfPublication << endl;
    }
}
bool CompareTwoCharArr(char a[], char b[])
{
    int ia = 0, ib = 0;
    while (a[ia] != '\0' && b[ib] != '\0')
    {
        if (a[ia++] != b[ib++])
        {
            return false;
        }
    }
    if (a[ia] == '\0' && b[ib] == '\0')
    {
        return true;
    }
    return false;
}
bool findBook(Book listBooks[], int length, Book &cantim)
{
    std::cout << "\nnhap ten sach can tim: ";
    fflush(stdin);
    char title[100];
    std::cin.getline(title, 100);
    for (int i = 0; i < length; i++)
    {
        if (CompareTwoCharArr(listBooks[i].title, title))
        {
            cantim = listBooks[i];
            return true;
        }
    }
    return false;
}
void EditBookData(Book listBooks[], int length)
{
    display(listBooks, length);
    int cansua;
    std::cout << "\nnhap vi tri cuon sach can sua: ";
    std::cin >> cansua;
    while (cansua < 1 || cansua > length)
    {
        std::cout << "nhap lai: ";
        std::cin >> cansua;
    }
    int choose;
    std::cout << "1. Tensach, 2.Tac gia, 3. Nam XB. Nhap thong tin muon sua: (1/2/3)" << endl;
    std::cin >> choose;
    switch (choose)
    {
    case 1:
        std::cout << "Nhap ten sach: ";
        fflush(stdin);
        std::cin.getline(listBooks[cansua - 1].title, 100);
        break;
    case 2:
        std::cout << "Nhap danh sach tac gia: ";
        inputListAuthors(listBooks[cansua - 1].Authors);
        break;
    case 3:
        std::cout << "Nhap nam xuat ban: ";
        std::cin >> listBooks[cansua - 1].yearOfPublication;
        break;

    default:
        std::cout << "lua chon khong hop le";
        break;
    }
    std::cout << "thanh cong";
}
void Menu()
{
    std::cout << "\n\t MENU" << endl;
    std::cout << "1. them sach." << endl;
    std::cout << "2. hien thi." << endl;
    std::cout << "3. tim kiem." << endl;
    std::cout << "4. sua thong tin." << endl;
}
int main()
{
    Book listBooks[100];
    int length = 0;
    char tieptuc = 'N';
    while (true)
    {
        int choose = 0;
        Menu();
        std::cout << "Nhap lua chon (1/2/3/4): ";
        std::cin >> choose;
        switch (choose)
        {
        case 1:
            if (length == 0)
            {
                inputListBook(listBooks, length);
            }
            else
            {
                addBooks(listBooks, length);
            }
            break;
        case 2:
            if (length == 0)
            {
                std::cout << "danh sach rong!";
            }
            else
            {
                display(listBooks, length);
            }

            break;
        case 3:
            if (length == 0)
            {
                std::cout << "danh sach rong!";
            }
            else
            {
                Book timkiem;
                if (findBook(listBooks, length, timkiem))
                {
                    std::cout << "tim thay: ";
                    std::cout << endl;
                    std::cout << "Ten sach: " << timkiem.title << "   ";
                    showListAuthors(timkiem.Authors);
                    std::cout << "Nam xuat ban: " << timkiem.yearOfPublication << "   ";
                }
                else
                {
                    std::cout << "khong tim thay";
                }
            }
            break;
        case 4:
            if (length == 0)
            {
                std::cout << "danh sach rong!";
            }
            else
            {
                EditBookData(listBooks, length);
            }

            break;
        default:
            break;
        }
        std::cout << "\nban co muon tiep tuc? (Y/N): ";
        std::cin >> tieptuc;
        if (toupper(tieptuc) == 'N')
        {
            break;
        }
    }
    return 0;
}
