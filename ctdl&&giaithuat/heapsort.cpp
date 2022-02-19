#include <iostream>
using namespace std;

class TriangularMatrix {
    private:
        int n;
        int *a;
    public:
    //constructor
    TriangularMatrix(int n) {
        this->n = n;
        a = new int[n*(n+1)/2];
    }
    //destructor
    ~TriangularMatrix() {
        delete[] a;
    }
    //getter
    int getN() {
        return n;
    }
    //setter
    void setN(int n) {
        this->n = n;
    }
    //getter
    int getA(int i, int j) {
        return a[i*(i+1)/2 + j];
    }
    //setter
    void setA(int i, int j, int x) {
        a[i*(i+1)/2 + j] = x;
    }
    //print
    void print() {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= i; j++) {
                cout << a[i*(i+1)/2 + j] << " ";
            }
            cout << endl;
        }
    }

};
struct node {
            int x;
            node *next;
        };
class linkedlist {
    private:
        
        node *head;
        int size;
        
    public:
    //constructor
    linkedlist() {
        head = NULL;
        size = 0;
    }
    //destructor
    ~linkedlist() {
        node *p = head;
        while (p != NULL) {
            node *q = p;
            p = p->next;
            delete q;
        }
    }
    //getter
    int getSize() {
        return size;
    }
    //getter
    node * getHead() {
        return head;
    }
    void add(int x) {
        node *p = new node;
        p->x = x;
        p->next = head;
        head = p;
        size++;
    }
    void remove(int x) {
        node *p = head;
        node *q = NULL;
        while (p != NULL) {
            if (p->x == x) {
                if (q == NULL) {
                    head = p->next;
                } else {
                    q->next = p->next;
                }
                delete p;
                size--;
                break;
            }
            q = p;
            p = p->next;
        }
    }
    void addfirst(int x) {
        node *p = new node;
        p->x = x;
        p->next = head;
        head = p;
        size++;
    }
    void removefirst() {
        node *p = head;
        head = p->next;
        delete p;
        size--;
    }
    void print() {
        node *p = head;
        while (p != NULL) {
            cout << p->x << " ";
            p = p->next;
        }
        cout << endl;
    }
    void reverse() {
        node *p = head;
        node *q = NULL;
        while (p != NULL) {
            node *r = p->next;
            p->next = q;
            q = p;
            p = r;
        }
        head = q;
    };
    void sort() {
        node *p = head;
        node *q = NULL;
        while (p != NULL) {
            node *r = p->next;
            while (q != NULL) {
                if (p->x < q->x) {
                    int temp = p->x;
                    p->x = q->x;
                    q->x = temp;
                }
                q = q->next;
            }
            q = p;
            p = p->next;
        }
    }

};

// create Sparse matrix class using linkedlist
class SparseMatrix {
    private:
        int n;
        linkedlist *a;
    public:
    //constructor
    SparseMatrix(int n) {
        this->n = n;
        a = new linkedlist[n];
    }
    //destructor
    ~SparseMatrix() {
        delete[] a;
    }
    //getter
    int getN() {
        return n;
    }
    //setter
    void setN(int n) {
        this->n = n;
    }
    //getter
    linkedlist * getA() {
        return a;
    }
    //setter
    void setA(linkedlist *a) {
        this->a = a;
    }
    //print
    void print() {
        for (int i = 0; i < n; i++) {
            cout << i << ": ";
            a[i].print();
        }
    }
    //add
    void add(int i, int j, int x) {
        a[i].add(j);
        a[i].add(x);
    }
    //remove
    void remove(int i, int j) {
        a[i].remove(j);
    }
    //addfirst
    void addfirst(int i, int j, int x) {
        a[i].addfirst(j);
        a[i].addfirst(x);
    }
    //removefirst
    void removefirst(int i) {
        a[i].removefirst();
    }
    //print
    void print(int i) {
        a[i].print();
    }
    //reverse
    void reverse(int i) {
        a[i].reverse();
    }
    //sort
    void sort(int i) {
        a[i].sort();
    }
    void get(int i, int j) {
        int k = 0;
        int x = 0;
        node *p = a[i].getHead();
        while (p != NULL) {
            if (k == j) {
                x = p->x;
                break;
            }
            k++;
            p = p->next;
        }
        cout << x << endl;
    }
    void set(int i, int j, int x) {
        int k = 0;
        node *p = a[i].getHead();
        while (p != NULL) {
            if (k == j) {
                p->x = x;
                break;
            }
            k++;
            p = p->next;
        }
    }
};