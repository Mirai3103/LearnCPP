// 46_le dinh khanh quan_dhti14a2hn
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <iomanip>
using namespace std;
struct date
{
    int day;
    int month;
    int year;
    void input()
    {
        fflush(stdin);
        cout << "NHAP NGAY:";
        cin >> day;
        cout << "NHAP THANG:";
        cin >> month;
        cout << "NHAP NAM:";
        cin >> year;
    }
    void show()
    {
        cout << day << "/" << month << "/" << year;
    }
    string toString()
    {
        stringstream ss;
        ss << day << "/" << month << "/" << year;
        string rs;
        ss >> rs;
        return rs;
    }
};
date strToDate(string s)
{
    string tempstr;
    date a;
    stringstream str(s);
    getline(str, tempstr, '/');
    a.day = atoi(tempstr.c_str());
    getline(str, tempstr, '/');
    a.month = atoi(tempstr.c_str());
    getline(str, tempstr, '/');
    a.year = atoi(tempstr.c_str());
    return a;
}
class Developer
{
public:
    int ID;
    string FullName;
    date DateOfBirth;
    double hesoluong;
    Developer() {}
    Developer(int ID, string FullName, date dob, double hesoluong)
    {
        ID = ID;
        FullName = FullName;
        DateOfBirth = dob;
        hesoluong = hesoluong;
    }
    void input()
    {
        cout << "NHAP ID :";
        cin >> ID;
        cout << "NHAP HO VA TEN:";
        fflush(stdin);
        getline(cin, FullName);
        cout << "NHAP NGAY THANG NAM SINH:";
        DateOfBirth.input();
        cout << "NHAP HE SO LUONG :";
        cin >> hesoluong;
    }
    void show()
    {
        cout << setw(5) << ID
             << setw(25) << FullName
             << setw(10) << DateOfBirth.toString()
             << setw(5) << hesoluong;
    }
    ~Developer() {} // HAM `HUY?
};
class Teamleader : public Developer
{
public:
    double Luongtrachnghiem;
    int namcongtac;
    Teamleader(){};
    Teamleader(int ID, string FullName, date dob, double hesoluong, double Luongtrachnghiem, int namcongtac)
        : Developer(ID, FullName, dob, hesoluong)
    {
        Luongtrachnghiem = Luongtrachnghiem;
        namcongtac = namcongtac;
    }
    double tinhtienluong()
    {
        return this->hesoluong * 1300000 + this->namcongtac * 90000 + this->Luongtrachnghiem;
    }
    friend istream &operator>>(istream &is, Teamleader &leader) // nap chong` toan tu nhap
    {
        cout << "NHAP ID";
        is >> leader.ID;
        fflush(stdin);
        cout << "NHAP HO VA TEN:";
        getline(is, leader.FullName);
        cout << "NHAP NGAY THANG NAM SINH:";
        leader.DateOfBirth.input();
        cout << "NHAP HE SO LUONG:";
        is >> leader.hesoluong;
        cout << "NHAP LUONG TRACH NGhIEM:";
        is >> leader.Luongtrachnghiem;
        cout << "NHAP SO NAM CONG TAC :";
        is >> leader.namcongtac;
        return is;
    }
    friend ostream &operator<<(ostream &os, Teamleader &leader) // NAP CHONG TOAN TU XUAT
    {
        os << leader.ID << "," << leader.FullName << "," << leader.DateOfBirth.toString() << "," << leader.hesoluong << "," << leader.Luongtrachnghiem << "," << leader.namcongtac << endl;
        return os;
    }
    void show()
    {
    Developer::show();
        cout << setw(10) << Luongtrachnghiem
             << setw(5) << namcongtac << endl;
    }
    ~Teamleader() {} // HAM HUY
};
template <class T>
struct arraylist
{
private:
    T x[100];
    int length;

public:
    arraylist()
    {
        this->length = 0;
    }
    void push_back(T element)
    {
        x[length++] = element;
    }
    void deleteALl()
    {
        length = 0;
    }
    void removeIndex(int index)
    {
        if(index >= length) return;
       for (int i = index; i < length-1; i++)
       {
           x[i] = x[i+1];
       }
       length--;      
    }
    T get(int index)
    {
        return x[index];
    }
    int size()
    {
        return length;
    }
    int indexOf(T element)
    {
        for (int i = 0; i < length; i++)
        {
            if (x[i] == element)
                return i;
        }
        return -1;
    }
    void insert(int index, T element)
    {
        if (index >= length){
            push_back(element);
            return;
        }
            
        for (int i = length; i >index; i--)
        {
            x[i] = x[i-1];
        }
        x[index] = element;
        length++;
        
    }
    void sort(bool (*compare)(T a, T b))
    {
        for (int i = 0; i < length - 1; i++)
        {
            for (int j = i + 1; j < length; j++)
            {
                if (compare(x[i], x[j]))
                {
                    T temp = x[i];
                    x[i] = x[j];
                    x[j] = temp; // sap sep
                }
            }
        }
    }
};
bool compare(Teamleader l1, Teamleader l2)
{
    return l1.namcongtac < l2.namcongtac;
}
void showsetw(arraylist<Teamleader> list)
{
    cout << setw(5) << "ID"
         << setw(25) << "FullName"
         << setw(10) << "NHAp NGAY SINH"
         << setw(5) << "hsl"
         << setw(10) << "luongtracnghiem"
         << setw(4) << "nct" << endl;
    
    for (int i = 0; i < list.size(); i++)
    {
        
        list.get(i).show();
        
    }
}
void showMENU()
{
    cout << "1.XUAT RA DANh SACH:\n";
    cout << "2.IN RA DANH SACH SAP XEP NAM COG TAC\n";
    cout << "3.THEM  'NGUYEN HOA PHAT' \n";
    cout << "4.XOA DEVELOPER TREN 60 TUOI\n";
    cout << "5.SAVE AND EXIT\n";
}
void save(arraylist<Teamleader> &list)
{
    remove("data.csv");
    ofstream fileout("data.csv");
    fileout << "id,ten,ngay sinh, hsl, luong tn, nam cong tac" << endl;
    for (int i = 0; i < list.size(); i++)
    {
        Teamleader temp = list.get(i);
        fileout << temp;
    }
}
void case3(arraylist<Teamleader> &list)
{
    bool isfind = false;
    for (int i = 0; i < list.size(); i++)
    {
        if (list.get(i).FullName == "nguyen hoa phat")
        {
            isfind = true;
            break;
        }
    }
    if (!isfind)
    {
        cout << "CHEN NGUYEN HOA PHAT O VI TRI ?:";
        int k;
        cin >> k;
        Teamleader temp;
        temp.FullName = "nguyen hoa phat";
        cout << "NHAP ID :";
        cin >> temp.ID;
        fflush(stdin);
        cout << "NHAP NGAY THANG NAM SINH:";
        temp.DateOfBirth.input();
        cout << "NHAP HE SO LUONG :"; cin >> temp.hesoluong;
        cout << "NHAP LUONG TRACH NGHIEM:";
        cin >> temp.Luongtrachnghiem;
        cout << "NHAP SO NAM CONG TAC:";
        cin >> temp.namcongtac;
        list.insert(k, temp);
        
    }
    else
    {
        cout << "DA TON TAI:";
    }
}
void case4(arraylist<Teamleader> &list)
{
    int stack[100];
    int top = 0;
    for (int i = 0; i < list.size(); i++)
    {
        if(2021 - list.get(i).DateOfBirth.year >= 60)
        {
            stack[top++] = i;
        }
    }
    while (top > 0)
    {
        top--;
        list.removeIndex(stack[top]);
    }
}
void read(arraylist<Teamleader> &list)
{
    string line, tempstr;
    ifstream file("data.csv");
    if (!file.good()) // kiem tra file co ton tai
        return;
    getline(file, line);
     while (getline(file, line))
    {
        stringstream str(line);
        
        Teamleader temp;
        getline(str,tempstr, ',');
        temp.ID = atoi( tempstr.c_str() );
        getline(str,tempstr, ',');
        temp.FullName = tempstr;
        getline(str,tempstr, ',');
        temp.DateOfBirth = strToDate(tempstr);
        getline(str,tempstr, ',');
        temp.hesoluong = atof( tempstr.c_str() );
        getline(str,tempstr, ',');
        temp.Luongtrachnghiem = atof( tempstr.c_str() );
        getline(str,tempstr, '\n');
        temp.namcongtac = atoi( tempstr.c_str() );
        list.push_back(temp);
        
    }
}
int main()
{
    arraylist<Teamleader> listLeader;
    read(listLeader);
    cout << "DOC FILE" << listLeader.size() << "leader\n";
    int n;
    cout << "NHAP SO DEVELOPER:";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        Teamleader temp;
        cin >> temp;
        listLeader.push_back(temp);
    }
    while (true)
    {
        int in;
        
        showMENU();
        cin >> in;
        switch (in)
        {
        case 1:
            showsetw(listLeader);
            break;
        case 2:
            listLeader.sort(compare);
            showsetw(listLeader);
            break;
        case 3:
            case3(listLeader);
            break;
        case 4:
            case4(listLeader);
            break;
        default:
            save(listLeader);
            goto end;
            break;
        }
    }
end:
    cout << "LUU VAO FILE :";
    return 0;
}