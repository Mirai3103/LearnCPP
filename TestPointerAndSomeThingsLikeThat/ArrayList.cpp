#include <iostream>
using namespace std;

template <class T>
struct ArrayList
{
private:
    T *x;
    int length;

public:
    ArrayList()
    {
        this->length = 0;
        x = nullptr;
    }
    void add(T element)
    {
        if (x == nullptr)
        {
            x = new T[1];
            x[0] = element;
            this->length++;
        }
        else
        {
            this->length++;
            T *temp = new T[length];
            for (int i = 0; i < length - 1; i++)
            {
                temp[i] = x[i];
            }
            temp[length - 1] = element;
            delete[] x;
            x = nullptr;
            x = temp;
        }
    }
    void deleteAll()
    {
        length = 0;
        delete[] x;
        x = nullptr;
    }
    bool removeElement(T element)
    {

        int dem = 0;
        for (int i = 0; i < length; i++)
        {
            if (x[i] == element)
            {
                dem++;
            }
        }
        if (dem == 0)
            return false;
        if (length == dem)
        {
            delete[] x;
            x = nullptr;
            return true;
        }
        T *temp = new T[length - dem];
        int j = 0;
        for (int i = 0; i < length; i++)
        {
            if (x[i] == element)
            {
            }
            else
            {
                temp[j] = x[i];
                j++;
            }
        }
        length = length - dem;
        delete[] x;
        x = nullptr;
        x = temp;
        return true;
    }
    bool removeIndex(int index){
        if(index >= length) return false;

        T *temp = new T[length-1];
        int j = 0;
        for (int  i = 0; i < length; i++)
        {
            if(i == index) continue;
            temp[j] = x[i];
            j++;
        }
        delete []x;
        x = temp;
        length = length-1;
        
    }
    int get(int index)
    {
        return x[index];
    }
    int size()
    {
        return length;
    }
    bool addAll(ArrayList<T> arr){
        if(arr.size() == 0) return false;
        if(this->length == 0){
            x = new T[arr.size()];
            this->length== arr.size();
            for (int i = 0; i < length; i++)
            {
                x[i]= arr.get(i);
            }
            
        }
    }
    int indexOf(T element){
        for (int i = 0; i < length; i++)
        {
            if(x[i] == element){
                return i;
            }
        }
        return -1;
        
    }
    int lastIndexOf(T element){
        for (int i = length-1; i >= 0; i--)
        {
            if(x[i] == element){
                return i;
            }
        }
        return -1;
        
    }
    void show(){
        printf("[");
        for (int i = 0; i < length; i++)
        {
            printf("%d", x[i]);
            if(i!=length-1) printf(", ");
        }
        printf("]\n");
        
    }
    ~ArrayList()
    {
        delete[] x;
        x = nullptr;
    }

};
int main()
{
    ArrayList<int> a;
    a.add(4);
    a.add(5);
    a.add(6);
    a.show();

    return 0;
}
