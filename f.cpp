
#include <stdio.h>
#include <math.h>

bool isPrime(int x) {

	for (int i = 2; i <= sqrt(x); i++)
	{
		if (x % i == 0)return false;
	}
	return x >= 2;

}
int lowerPrime(int x){
	
	while(x >=2) {

		if(isPrime(x)) return x;
		x--;
	}
	return 1;
}
int main() {
	int n;
	scanf("%d", &n);
	int now = lowerPrime(n);
	int affter = lowerPrime(now-1);
	int max = now - affter;
	while(affter >=2){
		now = affter;
		affter = lowerPrime(now-1);
		int khoangcach = abs(now- affter);
		if(khoangcach > max) max = khoangcach;
		printf("(%d, %d)", now, affter);
	}
	printf("\n %d", max);
}