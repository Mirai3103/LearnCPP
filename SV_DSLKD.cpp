#include<iostream>
using namespace std;
struct date{
	int ngay;
	int thang;
	int nam;
};
struct sinhvien{
	string ten;
	string ms;
	float dtb;
	date ngaysinh;
};
typedef struct sinhvien SV;
struct node{
	SV data;
	struct node *pNext;
};
typedef struct node NODE;
struct list{
	NODE *pHead;
	NODE *pTail;
};
typedef struct list LIST;
void khoitaolist(LIST &l){
	l.pHead=NULL;
	l.pTail=NULL;
}
NODE *khoitaonode(SV x){
	NODE *p=new NODE;
	if(p==NULL){
		cout<<"\nKhong du bo nho cap phat";
	}else{
		p->data = x;
		p->pNext = NULL;
	}
	return p;
}
void themvaocuoi(LIST &l, NODE * x){
	if(l.pHead==NULL){
		l.pHead=l.pTail=x;
	}else{
		l.pTail->pNext=x;
		l.pTail=x;	
	}	
}
void nhapngaysinh(SV &sv){
	cout<<"\nngay: ";
	cin>>sv.ngaysinh.ngay;
	cout<<"\nthang: ";
	cin>>sv.ngaysinh.thang;
	cout<<"\nNam: ";
	cin>>sv.ngaysinh.nam;	
}
void nhapthongtin1thangsv(SV &sv){
    fflush(stdin);
	cout<<"\nNhap ten: ";
	getline(cin,sv.ten);
	cout<<"\nNhap ms: ";
	cin>>sv.ms;
	cout<<"\nNhap dtb: ";
	cin>>sv.dtb;
	nhapngaysinh(sv);
}
void nhapttdssv(LIST &l,int n){
	for(int i=1;i<=n;i++){
		SV x;
		nhapthongtin1thangsv(x);
		NODE *p= khoitaonode(x);
		themvaocuoi(l,p);
	}
}
void xuatdssv(LIST l){
	int dem=0;
	for(NODE *k=l.pHead; k!=NULL; k=k->pNext){
		cout<<"\nSinh vien thu "<<dem++;
		cout<<"\nHo ten: "<<k->data.ten;
	    cout<<"\nMa sv: "<<k->data.ms;
	    cout<<"\nNgay sinh: "<<k->data.ngaysinh.ngay<<"/"<<k->data.ngaysinh.thang<<"/"<<k->data.ngaysinh.nam;
	    cout<<"\ndiem: "<<k->data.dtb;
	}	
}
int main(){
	SV sv;
	LIST l;
	khoitaolist(l);
	int n;
	cout<<"Nhap so luong sv: ";
	cin>>n;

	nhapttdssv(l,n);
	xuatdssv(l);
}