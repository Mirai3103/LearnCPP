class Matrix
{
private:
    int **pMatrix;
    int m;
    int n;
public:
    Matrix();
    Matrix(int m, int n){
    this->m = m;
    this->n = n;
    pMatrix = new int*[m];
    for (int i = 0; i < m; i++)
    {
        pMatrix[i] = new int[n];
    }
    }
    ~Matrix(){
        for (int i = 0; i < m; i++)
        {
            delete pMatrix[i];
        }
        delete [] pMatrix;
        pMatrix = nullptr;
    }
};


