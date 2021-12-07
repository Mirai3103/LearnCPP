#include<stdio.h>
#include<math.h>
struct toado{
    int x;
    int y;
};
typedef struct toado TD;

struct diem{
    TD A;
    TD B;
    TD C;
};
typedef struct diem DIEM;

void nhaptoado(TD &td){
    int tmp;
    printf("\nNhap x: ");
    scanf("%d",&tmp);
    td.x=tmp;
    printf("\nNhap y: ");
    scanf("%d",&tmp);
    td.y=tmp;
}

void xuat(TD td){
    printf("\n(%d,%d)",td.x,td.y);
}

void nhapdiem(DIEM &D){
    printf("Nhap toa do diem A: ");
    nhaptoado(D.A);
    printf("Nhap toa do diem B: ");
    nhaptoado(D.B);
    printf("Nhap toa do diem C: ");
    nhaptoado(D.C);
}

void xuatdiem(DIEM D){
    printf("\ndiem A: ");
    xuat(D.A);
    printf("\ndiem B: ");
    xuat(D.B);
    printf("\ndiem C: ");
    xuat(D.C);
}

float tinhdodai(DIEM D,DIEM Q){
    return sqrt(pow((D.x-Q.x),2)+pow((D.y-Q.y),2));
}
float TinhChuVi(DIEM D){
    float a=tinhdodai(D.A,D.B);
    float b=tinhdodai(D.B,D.C);
    float c=tinhdodai(D.C,D.A);
    float cv=a+b+c;
    return cv;
}
float TinhDienTich(DIEM D){
    float a=tinhdodai(D.A,D.B);
    float b=tinhdodai(D.B,D.C);
    float c=tinhdodai(D.C,D.A);
    float p=(a+b+c)/2;
    float DienTich = sqrt(p * (p - a) * (p - b) * (p - c));
    return DienTich;
}
diem TimTrongTam(DIEM t)
{
    diem G;
    G.x = (t.A.x + t.B.x + t.C.x) / 3;
    G.y = (t.A.y + t.B.y + t.C.y) / 3;

    return G;
}
int main(){
    TD td;
    DIEM D;
    nhapdiem(D);
    xuatdiem(D);
    float ChuVi = TinhChuVi(t);
    float DienTich = TinhDienTich(t);
    G = TimTrongTam(t);

    printf("\nChu vi tam giac = %.3f", ChuVi);
    printf("\nDien tich tam giac = %.3f", DienTich);

    printf("\nToa do trong tam G cua tam giac la: (%8.3f, %8.3f)", G.x, G.y);

    return 0;
}