#include <stdio.h>
#include <string.h>

typedef struct
{
    char ten[50];
    char lop[50];
    float diemMon1;
    float diemMon2;
    char xepLoai[50];
} sinhVien;

void nhap(sinhVien p[50], int *n)
{
    do
    {
        printf("\nNhap so luong sinh vien: ");
        scanf("%d\n",&n);
    } while (*n <= 0);
    for (int i = 0; i < *n; i++)
    {
        printf("\nSinh vien thu %d", i + 1);
        printf("\nNhap ten sinh vien: ");
        fflush(stdin);
        gets(p[i].ten);

        printf("\nNhap lop sinh vien: ");
        fflush(stdin);
        gets(p[i].lop);

        printf("\nNhap diem mon 1: ");
        scanf("%f", &p[i].diemMon1);

        printf("\nNhap diem mon 2: ");
        scanf("%f", &p[i].diemMon2);
    }
}

float diemTrungBinh(sinhVien p)
{
    return (p.diemMon1 + p.diemMon2) / 2;
}

void xepLoaiSV(sinhVien p[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (diemTrungBinh(p[i]) >= 8)
        {
            strcpy(p[i].xepLoai, "GIOI");
        }
        else if (8 > diemTrungBinh(p[i]) && diemTrungBinh(p[i]) >= 6.5)
        {
            strcpy(p[i].xepLoai, "KHA");
        }
        else if (6.5 > diemTrungBinh(p[i]) && diemTrungBinh(p[i]) >= 5)
        {
            strcpy(p[i].xepLoai, "TRUNG BINH");
        }
        else
        {
            strcpy(p[i].xepLoai, "YEU");
        }
    }
}

void xuat(sinhVien p[50], int n)
{
    xepLoaiSV(p,n);
    for (int i = 0; i < n; i++)
    {
        printf("\nThong tin sinh vien %d: ", i + 1);
        printf("\nHo va ten: %s", p[i].ten);
        printf("\nLop: %s", p[i].lop);
        printf("\nDiem mon 1: %.2f", p[i].diemMon1);
        printf("\nDiem mon 2: %.2f", p[i].diemMon2);
        printf("\nXep loai: %s", p[i].xepLoai);
    }
}

int main(int argc, char const *argv[])
{
    sinhVien p[50];
    int n;
    nhap(p, &n);
    xuat(p, n);
    return 0;
}