#include <iostream>
using namespace std;

class Tower
{
private:
    int *A;
    int size;
public:
    Tower(int n){
        size = n;
        A = new int[n];
    }
    Tower(){
        size = 0;
        A = new int[50];
    }
    ~Tower(){
        delete []A;
    }

    int pop(){
        if(size == 0) return -1;
        return A[--size];
    }
    void push(int element){
        A[size++]=element;
        if(!CheckIfArrSorted(size)){
            cout << "\nerror!";
            exit(0);
        }
    }
    bool CheckIfArrSorted(int n)
    {
        if (n <= 1)
            return true;
        if (A[n - 1] < A[n - 2])
            return false;
        return CheckIfArrSorted(n - 1);
    }
};

void TowerOfHaNoi(Tower &A, Tower &B, Tower &C ){
    
}
