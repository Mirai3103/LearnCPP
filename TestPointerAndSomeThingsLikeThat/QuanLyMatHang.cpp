#include <iostream>
#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;
struct Item
{
    int ItemCode;
    string ItemName;
    string ItemUnit;
    float ItemWeight;
    float ItemPrice;
    void show()
    {
        printf("Ma mat hang: %d, ten mat hang: %s, don vi: %s, can nang: %.3f, gia: %.3f\n", ItemCode, ItemName, ItemUnit, ItemWeight, ItemPrice);
    }
};

struct Node
{
    Item value;
    Node *next;
};
struct LinkedList
{
private:
    Node *lastNode;
    Node *firstNode;

public:
    LinkedList()
    {
        firstNode = NULL;
        lastNode = NULL;
    }
    bool add(Item value)
    {
        if (firstNode == NULL)
        {
            firstNode = new Node();
            firstNode->value = value;
            firstNode->next = NULL;
            lastNode = firstNode;
            return true;
        }
        Node *temp = new Node();
        temp->value = value;
        temp->next = NULL;
        lastNode->next = temp;
        lastNode = temp;
        return true;
    }
    bool addFist(Item valu)
    {
        if (firstNode == NULL)
        {
            firstNode = new Node();
            firstNode->value = valu;
            firstNode->next = NULL;
            lastNode = firstNode;
            return true;
        }
        Node *nextNode = firstNode;
        while (nextNode != NULL)
        {
            if (nextNode->value.ItemCode == valu.ItemCode)
            {
                return false;
            }
        }
        Node *temp = new Node();
        temp->value = valu;
        temp->next = firstNode;
        firstNode = temp;
        return true;
    }
    bool deleteFirstValue(int itemCode)
    {
        Node *nextNode;
        nextNode = this->firstNode;
        while (nextNode != NULL)
        {
            if (nextNode->next != NULL)
            {
                if (nextNode->next->value.ItemCode == itemCode)
                {
                    Node *WillDelete = nextNode->next;
                    nextNode->next = nextNode->next->next;
                    delete WillDelete;
                    return true;
                }
            }
            nextNode = nextNode->next;
        }
        return false;
    }
    Item *FindItem(int itemCode)
    {
        Node *nextNode;
        nextNode = this->firstNode;
        while (nextNode != NULL)
        {
            if (nextNode->value.ItemCode == itemCode)
            {
                return &(nextNode->value);
            }
            nextNode = nextNode->next;
        }
        return NULL;
    }
    void setNull()
    {
        firstNode = NULL;
        lastNode = NULL;
    }
    Node *getFirstNode()
    {
        return this->firstNode;
    }
};
void ShowMenu()
{
    system("cls");
    cout << "DANH SACH MENU.\n";
    cout << "1. Hien thi toan bo danh sach." << endl;
    cout << "2. Tim 1 mat hang theo ma mat hang." << endl;
    cout << "3. Them 1 mat hang vao dau danh sach." << endl;
    cout << "4. Xoa mat hang bang ma mat hang." << endl;
    cout << "5. Nhap 1 dv tinh hien thi ds mat hang co dv do." << endl;
    cout << "6. dem so mat hang co don vi tinh la hop" << endl;
    cout << "7. sap xep tang dan theo don gia." << endl;
    cout << "8. de dai vc" << endl;
    cout << "9. Xoa toan bo danh sach." << endl;
    cout << "10. Luu vao file." << endl;
    cout << "Nhap lua chon cua ban: ";
}
void ShowList(LinkedList &list)
{

    Node *nextNode = list.getFirstNode();
    if (nextNode == NULL)
    {
        cout << "Danh sach rong" << endl;
    }
    else
    {
        while (nextNode != NULL)

        {
            nextNode->value.show();
            nextNode = nextNode->next;
        }
    }
}
void FindItem(LinkedList &list)
{
    int itemcode;
    cout << "nhap ma mat hang muon tim: ";
    cin >> itemcode;
    Item *item = list.FindItem(itemcode);
    if (item == NULL)
    {
        cout << "Khong tim thay" << endl;
    }
    else
    {
        cout << "da tim thay" << endl;
        (*item).show();
    }
}
void AddItem(LinkedList &list)
{
    int itemcode;
    cout << " Nhap ma mat hang:";
    cin >> itemcode;
    Item *item = list.FindItem(itemcode);
    if (item == NULL)
    {
        item = new Item();
        item->ItemCode = itemcode;
        cout << "Nhap ten mat hang: ";
        cin.ignore();
        getline(cin, item->ItemName);
        cout << "Nhap don vi tinh: ";
        getline(cin, item->ItemUnit);
        cout << "Nhap can nang: ";
        cin >> item->ItemWeight;
        cout << "Nhap gia: ";
        cin >> item->ItemPrice;
        list.addFist(*item);
    }
    else
    {
        cout << "Mat hang da ton tai" << endl;
        item->show();
    }
}
void DeleteItem(LinkedList &list)
{
    int itemcode;
    cout << " Nhap ma mat hang:";
    cin >> itemcode;
    list.deleteFirstValue(itemcode);
    cout << "Xong!";
}
void ChucNang5(LinkedList &list)
{
    cout << "nhap don vi: ";
    string dv;
    fflush(stdin);
    getline(cin, dv);
    Node *nextNode = list.getFirstNode();
    if (nextNode == NULL)
    {
        cout << "Danh sach rong" << endl;
    }
    else
    {
        while (nextNode != NULL)

        {
            if (nextNode->value.ItemUnit == dv)
            {
                nextNode->value.show();
            }

            nextNode = nextNode->next;
        }
    }
}
void ChucNang6(LinkedList &list)
{
    int count = 0;
    Node *nextNode = list.getFirstNode();
    if (nextNode == NULL)
    {
        cout << "Danh sach rong" << endl;
    }
    else
    {
        while (nextNode != NULL)

        {
            if (nextNode->value.ItemUnit == "hop")
            {
                count++;
            }

            nextNode = nextNode->next;
        }
        cout << endl
             << "co " << count << " mat hang" << endl;
    }
}
void ChucNang7(LinkedList &list)
{
    Node *nextNode = list.getFirstNode();
    if (nextNode == NULL)
    {
        cout << "Danh sach rong" << endl;
    }
    else
    {
        for (Node *Inode = nextNode; Inode != NULL; Inode = Inode->next)
        {
            for (Node *Jnode = Inode->next; Jnode != NULL; Jnode = Jnode->next)
            {
                if (Inode->value.ItemPrice > Jnode->value.ItemPrice)
                {
                    Item temp = Inode->value;
                    Inode->value = Jnode->value;
                    Jnode->value = temp;
                }
            }
        }
    }
}
void ChucNang8(LinkedList &list)
{
    Node *nextNode = list.getFirstNode();
    // if (nextNode == NULL)
    // {
    //     AddItem(list);
    // }
    // else
    // {
        int itemcode;
        cout << " Nhap ma mat hang:";
        cin >> itemcode;
        Item *item = list.FindItem(itemcode);
        if (item == NULL)
        {
            item = new Item();
            item->ItemCode = itemcode;
            cout << "Nhap ten mat hang: ";
            cin.ignore();
            getline(cin, item->ItemName);
            cout << "Nhap don vi tinh: ";
            getline(cin, item->ItemUnit);
            cout << "Nhap can nang: ";
            cin >> item->ItemWeight;
            cout << "Nhap gia: ";
            cin >> item->ItemPrice;
            for (Node *Inode = list.getFirstNode(); Inode != NULL; Inode = Inode->next)
            {
                if (Inode->value.ItemPrice <= item->ItemPrice)
                {
                    if (Inode->next->value.ItemCode >= item->ItemPrice || Inode->next == NULL)
                    {
                        Node *temp = new Node();
                        temp->value = *item;
                        temp->next = Inode->next;
                        Inode->next = temp;
                    }
                }
            }
        }
        else
        {
            cout << "Mat hang da ton tai" << endl;
            item->show();
        }
    
}
void ChucNang9(LinkedList &list)
{
    Node *nextNode = list.getFirstNode();
    Node *deleteNode;
    while (nextNode != NULL)
    {
        deleteNode = nextNode;
        nextNode = nextNode->next;
        delete deleteNode;
    }
    list.setNull();
}
void ChucNang10(LinkedList &list)
{
    ofstream file("data.csv", ios::out);
    string header = "Ma mat hang,ten mat hang,don vi,can nang,gia\n";
    file << header;
    for (Node *Inode = list.getFirstNode(); Inode != NULL; Inode = Inode->next)
    {
        file << Inode->value.ItemCode << "," << Inode->value.ItemName << "," << Inode->value.ItemUnit << "," << Inode->value.ItemWeight << "," << Inode->value.ItemPrice << "\n";
    }
    file.close();
}
int main()
{
    LinkedList list;
    char continueProgram;
    int chose;
    do
    {
        ShowMenu();
        cin >> chose;
        switch (chose)
        {
        case 1:
            ShowList(list);
            break;
        case 2:
            FindItem(list);
            break;
        case 3:
            AddItem(list);
            break;
        case 4:
            DeleteItem(list);
            break;
        case 5:
            ChucNang5(list);
            break;
        case 6:
            ChucNang6(list);
            break;
        case 7:
            ChucNang7(list);
            break;
        case 8:
            ChucNang8(list);
            break;
        case 9:
            ChucNang9(list);
            break;
        case 10:
            ChucNang10(list);
            break;
        default:
            cout << "Lua chon khong hop le";
            break;
        }
        cout << endl
             << "Ban co muon tiep tuc (Y/N):";
        fflush(stdin);
        cin >> continueProgram;
    } while (toupper(continueProgram) == 'Y');
}