// khai báo thư viên
#include <iostream>
using namespace std;

// khai báo struct
struct ListAuthors
{
    string *authorsName;
    int length;
};

struct Book
{
    string title;
    ListAuthors authors;
    int yearOfPublication;
};

// Khai báo prototype các hàm
void showMenu();
void inputABook(Book &book);
void inputAuthorsList(ListAuthors *authors);
Book *inputBooksList(int &length);
void showABookInfo(Book book);
void showBooksList(Book *booksList, int length);
Book *findBookByName(Book *booksList, int length);
void findBookAndUpdate(Book *booksList, int length);
void addBook(Book *booksList, int &length);
void insertBook(Book *booksList, int &length);
void deleteBook(Book *booksList, int &length);

// Hàm main
int main()
{
    int choice;
    Book *booksList;
    int length;
    do
    {
        showMenu();
        cin >> choice;
        switch (choice)
        {
        case 1:
            booksList = inputBooksList(length);
            break;
        case 2:
            showBooksList(booksList, length);
            break;
        case 3:
            findBookByName(booksList, length);
            break;
        case 4:
            findBookAndUpdate(booksList, length);
            break;
        case 5:
            addBook(booksList, length);
            break;
        case 6:
            insertBook(booksList, length);
            break;
        case 7:
            deleteBook(booksList, length);
            break;
        case 8:
            break;
        default:
            cout << "Nhap sai, moi nhap lai!" << endl;
            break;
        }
    } while (choice != 8);
    return 0;
}

// các hàm
void showMenu()
{
    cout << "1. Nhap  cuon sach" << endl;
    cout << "2. Hien thi danh sach cac cuon sach" << endl;
    cout << "3. Tim sach theo ten" << endl;
    cout << "4. Cap nhat thong tin sach" << endl;
    cout << "5. Them sach vao danh sach" << endl;
    cout << "6. Them sach vao vi tri bat ki" << endl;
    cout << "7. Thoat" << endl;
}
void inputAuthorsList(ListAuthors *authors)
{
    cout << "how many authors do you want input? ";
    cin >> authors->length;
    authors->authorsName = new string[authors->length];
    for (int i = 0; i < authors->length; i++)
    {
        fflush(stdin);
        getline(cin, authors->authorsName[i]);
    }
    cout << "end of author input\n";
}

void inputABook(Book &book)
{
    cout << "book title: ";
    cin >> book.title;
    cout << "input authors: \n";
    inputAuthorsList(&book.authors);
    cout << "input the year of publication: ";
    cin >> book.yearOfPublication;
}

Book *inputBooksList(int &length)
{
    cout << "how many books do you want input? ";
    cin >> length;
    Book *bookList = new Book[length];
    for (int i = 0; i < length; i++)
    {
        inputABook(bookList[i]);
    }
    return bookList;
}

void showABookInfo(Book book)
{
    cout << "title: " << book.title << endl;
    cout << "authors: ";
    for (int i = 0; i < book.authors.length; i++)
    {
        cout << book.authors.authorsName[i];
        if (i != book.authors.length - 1)
        {
            cout << ", ";
        }
        else
        {
            cout << ".";
        }
    }
    cout << endl;
    cout << "Year published: " << book.yearOfPublication << endl;
    cout << "==========================================" << endl;
}

void showBooksList(Book *booksList, int length)
{
    for (int i = 0; i < length; i++)
    {
        cout << "index: " << i << endl;
        showABookInfo(booksList[i]);
    }
}

Book *findBookByName(Book *booksList, int length)
{
    string name;
    cout << "input the name of book: ";
    cin >> name;
    Book *bookList = new Book[length];
    for (int i = 0; i < length; i++)
    {
        if (bookList[i].title == name)
        {
            return (bookList + i);
        }
    }
    return NULL;
}

void findBookAndUpdate(Book *booksList, int length)
{
    Book *book = findBookByName(booksList, length);
    if (book != NULL)
    {
        cout << "what information do you want to update?\n";
        cout << "1. title\n";
        cout << "2. authors\n";
        cout << "3. year of publication\n";
        int choice;
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "input new title: ";
            cin >> book->title;
            break;
        case 2:
            cout << "input new authors: \n";
            inputAuthorsList(&book->authors);
        case 3:
            cout << "input new year of publication: ";
            cin >> book->yearOfPublication;
            break;
        default:
            cout << "invalid choice\n";
            break;
        }
    }
    else
    {
        cout << "book not found\n";
    }
}

void addBook(Book *booksList, int &length)
{
    Book *newBookList = new Book[length + 1];
    for (int i = 0; i < length; i++)
    {
        newBookList[i] = booksList[i];
    }
    inputABook(newBookList[length]);
    delete[] booksList;
    booksList = newBookList;
    length++;
}

void insertBook(Book *booksList, int &length)
{
    showBooksList(booksList, length);
    Book *newBookList = new Book[length + 1];
    int index;
    cout << "input the index of book you want to insert: ";
    cin >> index;
    for (int i = 0; i < index; i++)
    {
        newBookList[i] = booksList[i];
    }
    inputABook(newBookList[index]);
    for (int i = index; i < length; i++)
    {
        newBookList[i + 1] = booksList[i];
    }
    delete[] booksList;
    booksList = newBookList;
    length++;
}

void deleteBook(Book *booksList, int &length)
{
    Book *newBookList = new Book[length - 1];
    int index;
    showBooksList(booksList, length);
    cout
        << "input the index of book you want to delete: ";
    cin >> index;
    for (int i = 0; i < index; i++)
    {
        newBookList[i] = booksList[i];
    }
    for (int i = index; i < length - 1; i++)
    {
        newBookList[i] = booksList[i + 1];
    }
    delete[] booksList;
    booksList = newBookList;
    length--;
}