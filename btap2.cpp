#include <stdio.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

void readFromFile(FILE *file,int **&arr, int &n, int &m)
{
    fscanf(file,"%d %d",&n, &m);


   
    arr = new int*[n];
    for (int i=0;i<n;i++) {
        arr[i] = new int[m];
    }
    for (int i=0;i<n;i++) {
        for (int j=0;j<m;j++) {
            fscanf(file,"%d",&arr[i][j]);
        }
    }

}

int maxcot(int **&a, int m, int n, int c)
{
    int maxc = a[0][c];
    for (int i=1;i<n;i++) {
        if (a[i][c]>maxc) {
            maxc = a[i][c];
        }
    }
    return maxc;
}

int findmin(int **&a, int m,int n)
{
    int minvalue = a[0][0];
    int maxc;
    for(int i=0;i<n;i++) {
        maxc = maxcot(a,m,n,i);
        if(maxc<minvalue) minvalue = maxc;
    }
    return minvalue;
}

void makeArrayB(int **&a,int m,int n,int **&b)
{

    b = new int*[n];
    for (int i=0;i<n;i++) {
        b[i] = new int[m];
    }
    for(int j=0;j<m;j++) {
        int maxc = maxcot(a,m,n,j);
        for (int i=0;i<n;i++) {
            b[i][j] = a[i][j] * maxc;
        }
    } 

}

int main()
{
    FILE *fi = fopen("input_2.txt","r");
    if (fi==NULL) {
        cout << "Memmory error!!!";
    }
    int n,m;
    int **arr;
    readFromFile(fi,arr,n,m);
    fclose(fi);
    for (int i=0;i<n;i++) { 
        for (int j=0;j<m;j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    
    FILE *fo = fopen("output_2.txt","w");

    int kqb =  findmin(arr,m,n);
    printf("%d",kqb);
    fprintf(fo,"Cau b: %d\n",kqb);
    int **b;
    makeArrayB(arr,m,n,b);
    fprintf(fo,"Cau c:\n");
    for (int i=0;i<n;i++) {
        for (int j=0;j<m;j++) {
            fprintf(fo,"%d ",b[i][j]);
        }
        fprintf(fo,"\n");
    }
  
    fclose(fo);
    return 0;
}
