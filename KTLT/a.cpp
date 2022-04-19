/* 
write a program to manage a list of courses using singly linked list. The program has the following functions:
1.  Declare a Node of song
2. Add a song to the list affter node Q
2. count the number of songs in the list
*/
#include <iostream>
#include <cstdlib>
using namespace std;

struct Song{
    int songId;
    string name;
    int length;
};

struct Node{
    Song song;
    Node *next;
};


struct List{
    Node *head;
    Node *tail;
};

void addAffterSongID(List &list, int songId, Song song){
    Node *p = list.head;
    while(p != NULL){
        if(p->song.songId == songId){
            Node *newNode = new Node;
            newNode->song = song;
            newNode->next = p->next;
            p->next = newNode;
            return;
        }
        p = p->next;
    }
}

int countSong(List &list){
    Node *p = list.head;
    int count = 0;
    while(p != NULL){
        count++;
        p = p->next;
    }
    return count;
}

void initList(List &list){
    list.head = NULL;
    list.tail = NULL;
}
void inputSong(Song &song){
    cout << "enter songId: ";
    cin >> song.songId;
    cout << "enter name: ";
    cin >> song.name;
    cout << "enter length: ";
    cin >> song.length;

}

void addSong(List &list){
    Song song;
    inputSong(song);
    if(list.head == NULL){
        list.head = new Node;
        list.head->song = song;
        list.head->next = NULL;
        list.tail = list.head;
    }
    else{
        list.tail->next = new Node;
        list.tail->next->song = song;
        list.tail->next->next = NULL;
        list.tail = list.tail->next;
    }
}

void displayList(List &list){
    Node *p = list.head;
    while(p != NULL){
        cout << p->song.songId << " " << p->song.name << " " << p->song.length << endl;
        p = p->next;
    }
}
int main(){
    List list;
    initList(list);
    Song song;
    int choice;
    do{
        cout << "1. add song" << endl;
        cout << "2. display list" << endl;
        cout << "3. count song" << endl;
        cout << "4. add affter songId" << endl;
        cout << "5. exit" << endl;
        cout << "enter your choice: ";
        cin >> choice;
        switch(choice){
            case 1:
                addSong(list);
                break;
            case 2:
                displayList(list);
                break;
            case 3:
                cout << "number of song: " << countSong(list) << endl;
                break;
            case 4:
                int songId;
                cout << "enter songId you want to add affter: ";
                cin >> songId;
                inputSong(song);
                addAffterSongID(list, songId, song);
                break;
            case 5:
                break;
            default:
                cout << "invalid choice" << endl;
    }}while(choice != 5);
    return 0;
}