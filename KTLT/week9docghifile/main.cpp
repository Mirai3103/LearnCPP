#include <iostream>
#include <cstring>
using namespace std;

int cau1()
{
    FILE *fi = fopen("THI3.INP", "r");
    char str[] = "que huong";
    int count = 0;
    char stemp[100];

    while (!feof(fi))
    {
        fgets(stemp, 100, fi);
        if (strstr(stemp, "que huong"))
        {
            count++;
        }
    }
    return count;
    fclose(fi);
}

int chuaTuCo5KiTuTroLen(char *str)
{
    int soKiTu = 0;
    int count = 0;
    while (*str != '\0')
    {
        if (*str != ' ')
        {
            soKiTu++;
        }
        else
        {
            if (soKiTu >= 5)
            {
                count++;
            }
            soKiTu = 0;
        }
        str++;
    }
    return count;
}

void cau2()
{
    FILE *fi = fopen("THI3.INP", "r");
    char str[] = "que huong";
    int count = 0;
    char stemp[256];
    int dong = 0;
    while (!feof(fi))
    {
        fgets(stemp, 256, fi);
        dong++;
        cout << "dong " << dong << "co :  " << chuaTuCo5KiTuTroLen(stemp) << " tu" << endl;
    }
    fclose(fi);
}

void soLuongNguyenAmMoiTu(char *str)
{
    int soNguyenAm = 0;
    int count = 0;
    while (*str != '\0')
    {
        char temp = toupper(*str);
        if (temp == 'U' || temp == 'E' || temp == 'O' || temp == 'A' || temp == 'I')
        {
            soNguyenAm++;
        }
        else
        {
            if (*str == ' ')
            {
                count++;
                printf("\ttu thu %d co: %d nguyen am\n", count, soNguyenAm);
                soNguyenAm = 0;
            }
        }
        str++;
    }
}

void cau3()
{
    FILE *fi = fopen("THI3.INP", "r");

    int count = 0;
    char stemp[256];
    int dong = 0;
    while (!feof(fi))
    {
        fgets(stemp, 256, fi);
        dong++;
        printf("==>dong %d: \n", dong);
        soLuongNguyenAmMoiTu(stemp);
    }
    fclose(fi);
}

int demSoTu(char *str)
{
    int soTu = 1;

    while (*str != '\0')
    {
        if (*str == ' ' && *(str + 1) != ' ')
        {
            soTu++;
        }
        str++;
    }
    return soTu;
}

void cau4()
{
    FILE *fi = fopen("THI3.INP", "r");
    char str[] = "que huong";
    int count = 0;
    char stemp[256];
    char smax[256];
    int maxWord = 0;
    while (!feof(fi))
    {
        fgets(stemp, 256, fi);
        int sotu = demSoTu(stemp);
        if (maxWord < sotu)
        {
            maxWord = sotu;
            strcpy(smax, stemp);
        }
    }
    cout << "tu co nhieu tu nhat: " << endl;
    cout << smax << endl
         << "co " << maxWord << "tu trong dong" << endl;
    fclose(fi);
}
void cau5()
{

    FILE *fi = fopen("THI3.INP", "r");
    char stemp[256];
    char **strList = new char *[20];
    int n = 0;
    while (!feof(fi))
    {
        fgets(stemp, 256, fi);
        strList[n] = new char[strlen(stemp + 1)];
        strcpy(strList[n], stemp);
        n++;
    }

    //  sap xep
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (demSoTu(strList[i]) > demSoTu(strList[j]))
            {
                char *s = *(strList + i);
                *(strList + i) = *(strList + j);
                *(strList + j) = s;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << strList[i] << endl;
    }
    fclose(fi);
}
int main(int argc, char const *argv[])
{

    // cout << cau1() << endl;
    // cau2();
    // cau3();
    // cau4();
    cau5();
    return 0;
}
