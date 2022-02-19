#include <iostream>
using namespace std;
class test
{
private:
	char a[15];

public:
	void set();
	void show()
	{
		cout << a << endl;
	}
};
void test::set()
{
	cout << "Enter the name: ";
	cin.getline(a, 15);
}
int main()
{
	test t;
	t.set();
	t.show();
	return 0;
}