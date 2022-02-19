#include <iostream>
using namespace std;

struct Element{
    int i;
    int j;
    int value;
};
struct sparse{
    int n;
    int m;
    int not_zero;
    Element *elements;
};

void create(sparse *s){
    cout << "nhap so dong va cot";
    cin >> s->n >> s->m;
    cout << "nhap so phan tu khac 0:";
    cin >> s->not_zero;
    s->elements = new Element[s->not_zero];
    for(int i = 0; i < s->not_zero; i++){
        cout << "nhap phan tu thu " << i + 1 << endl;
        cin >> s->elements[i].i >> s->elements[i].j >> s->elements[i].value;
    }


}
void display(sparse *s){
    cout << "so dong: " << s->n << endl;
    cout << "so cot: " << s->m << endl;
    cout << "so phan tu khac 0: " << s->not_zero << endl;
    for(int i = 0; i < s->not_zero; i++){
        cout << s->elements[i].i << " " << s->elements[i].j << " " << s->elements[i].value << endl;
    }
}
// add two sparse matrix
sparse add(sparse *s1, sparse *s2){
    sparse s;
    s.n = s1->n;
    s.m = s1->m;
    s.not_zero = 0;
    s.elements = new Element[s1->not_zero + s2->not_zero];
    int i = 0, j = 0, k = 0;
    while(i < s1->not_zero && j < s2->not_zero){
        if(s1->elements[i].i == s2->elements[j].i && s1->elements[i].j == s2->elements[j].j){
            s.elements[k].i = s1->elements[i].i;
            s.elements[k].j = s1->elements[i].j;
            s.elements[k].value = s1->elements[i].value + s2->elements[j].value;
            k++;
            i++;
            j++;
        }
        else if(s1->elements[i].i < s2->elements[j].i){
            s.elements[k].i = s1->elements[i].i;
            s.elements[k].j = s1->elements[i].j;
            s.elements[k].value = s1->elements[i].value;
            k++;
            i++;
        }
        else if(s1->elements[i].i > s2->elements[j].i){
            s.elements[k].i = s2->elements[j].i;
            s.elements[k].j = s2->elements[j].j;
            s.elements[k].value = s2->elements[j].value;
            k++;
            j++;
        }
    }
    while(i < s1->not_zero){
        s.elements[k].i = s1->elements[i].i;
        s.elements[k].j = s1->elements[i].j;
        s.elements[k].value = s1->elements[i].value;
        k++;
        i++;
    }
    while(j < s2->not_zero){
        s.elements[k].i = s2->elements[j].i;
        s.elements[k].j = s2->elements[j].j;
        s.elements[k].value = s2->elements[j].value;
        k++;
        j++;
    }
    return s;
}