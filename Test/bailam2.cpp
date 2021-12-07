#include <iostream>
#include <string> 
using namespace std;
string dateTimeToString(int sec){
	int phut =sec /60;
	sec = sec % 60;
	int gio = phut/60;
	phut = phut % 60;
	return to_string(gio) + "h" + to_string(phut)+"p"+ to_string(sec)+"s";
}
int main(){
	char input[3];
	cin >> input;
	cout << (input[0]- '0') +(input[1]- '0')+(input[2]- '0') << endl;
	cout<< dateTimeToString(3700);
	return 0;
}