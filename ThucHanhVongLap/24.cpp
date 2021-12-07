#include <iostream>
using namespace std;
int pow(int coso, int luythua)
{
	// int rs = 1;
	// while (luythua--)
	// {
	// 	rs*=coso;
	// }
	// return rs;
	return luythua == 1 ? coso : coso * pow(coso, luythua - 1);
}
int demsochuso(int n){
	int sochuso = 0;
	while (n != 0)
	{
		n = n / 10;
		sochuso++;
	}
	return sochuso;
}

int tongluythua(int n, int sochuso){
	int S = 0;
	while (n != 0)
	{
		S += pow(n % 10, sochuso);
		n /= 10;
	}
	return S;
}

bool kiemtrasoAs(int n, int sochuso){
	
	return tongluythua(n,sochuso) ==n;
}
int main()
{
	int n;
	cin >> n;
	int sochuso = demsochuso(n);
	
	
	if (kiemtrasoAs(n,sochuso))
	{
		cout << n << " la so astrong";
	}
	else
	{
		cout << n << " khong phai la so astrong";
	}
}
