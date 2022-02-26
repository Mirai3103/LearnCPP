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
        cout << "Nhap ten tac gia thu " << i + 1 << ": ";
        cin.getline(listAuthor.nameOfAuthors[i], 100);
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
    cout << "Nhap ten sach: ";
    cin.getline(a.title, 100);
    fflush(stdin);
    cout << "Nhap danh sach tac gia: ";
    inputListAuthors(a.Authors);
    cout << "Nhap nam xuat ban: ";
    cin >> a.yearOfPublication;
}


void addBooks(Book listBooks[], int &length)
{
    cout << "Nhap so sach can them: ";
    int canthem = 0;
    cin >> canthem;
    int i = length;
    length += canthem;
    for (int i = length; i < canthem; i++)
    {
        cout << "Nhap thong tin cuon sach thu " << i + 1 << ":\n";
        inputBook(listBooks[i]);
    }
}


void inputListBook(Book listBooks[], int &length)
{
    cout << "Nhap so luong sach: ";
    cin >> length;
    for (int i = 0; i < length; i++)
    {
        cout << "Nhap thong tin cuon sach thu " << i + 1 << ":\n";
        inputBook(listBooks[i]);
    }
}


void display(Book listBooks[], int length)
{
    for (int i = 0; i < length; i++)
    {
        cout << endl
             << i + 1 << ". ";
        cout << "Ten sach: " << listBooks[i].title << endl;
        showListAuthors(listBooks[i].Authors);
        cout << "Nam xuat ban: " << listBooks[i].yearOfPublication << endl;
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
    cout << "\nnhap ten sach can tim: ";
    fflush(stdin);
    char title[100];
    cin.getline(title, 100);
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
    cout << "\nnhap vi tri cuon sach can sua: ";
    cin >> cansua;
    while (cansua < 1 || cansua > length)
    {
        cout << "nhap lai: ";
        cin >> cansua;
    }
    int choose;
    cout << "1. Tensach, 2.Tac gia, 3. Nam XB. Nhap thong tin muon sua: (1/2/3)" << endl;
    cin >> choose;
    switch (choose)
    {
    case 1:
        cout << "Nhap ten sach: ";
        fflush(stdin);
        cin.getline(listBooks[cansua - 1].title, 100);
        break;
    case 2:
        cout << "Nhap danh sach tac gia: ";
        inputListAuthors(listBooks[cansua - 1].Authors);
        break;
    case 3:
        cout << "Nhap nam xuat ban: ";
        cin >> listBooks[cansua - 1].yearOfPublication;
        break;

    default:
        cout << "lua chon khong hop le";
        break;
    }
    cout << "thanh cong";
}


void Delete(Book listBooks[], int &length)
{
    char a[100];
    cout << "Nhap ten sach can xoa: ";
    fflush(stdin);
    cin.getline(a, 100);
    int i = 0;
    int newlength;
    while (CompareTwoCharArr(a, listBooks[i].title) && i < length)
    {
        i++;
    }
    if (i < length)
    {

        for (; i < length; i++)
        {
            listBooks[i] = listBooks[i + 1];
        }
        length--;
        cout << "xoa thanh cong!";
    }
    else
    {
        cout << "khong tim thay sach can xoa!";
    }
}

void Menu()
{
    cout << "\n\t MENU" << endl;
    cout << "1. them sach." << endl;
    cout << "2. hien thi." << endl;
    cout << "3. tim kiem." << endl;
    cout << "4. sua thong tin." << endl;
    cout << "5. xoa" << endl;
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
        cout << "Nhap lua chon (1/2/3/4/5): ";
        cin >> choose;
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
                cout << "danh sach rong!";
            }
            else
            {
                display(listBooks, length);
            }

            break;
        case 3:
            if (length == 0)
            {
                cout << "danh sach rong!";
            }
            else
            {
                Book timkiem;
                if (findBook(listBooks, length, timkiem))
                {
                    cout << "tim thay: ";
                    cout << endl;
                    cout << "Ten sach: " << timkiem.title << "   ";
                    showListAuthors(timkiem.Authors);
                    cout << "Nam xuat ban: " << timkiem.yearOfPublication << "   ";
                }
                else
                {
                    cout << "khong tim thay";
                }
            }
            break;
        case 4:
            if (length == 0)
            {
                cout << "danh sach rong!";
            }
            else
            {
                EditBookData(listBooks, length);
            }

            break;
        case 5:
            Delete(listBooks, length);
            break;
        default:
            cout << "lu chon khong hop le";
            break;
        }
        cout << "\nban co muon tiep tuc? (Y/N): ";
        cin >> tieptuc;
        if (toupper(tieptuc) == 'N')
        {
            break;
        }
    }
    return 0;
}
