/* Cho một mảng số nguyên a, bạn hãy tính tổng tất cả các số có giá trị lớn hơn trung bình cộng của dãy.
Nếu không có số nào thỏa đề, hãy trả về -1*/
#include <iostream>
#include <vector>
using namespace std;
double trungbinhcong(std::vector<int> a) {
	double s = 0;
	for (int i = 0; i < a.size(); i++)
	{
		s = s + a[i];
	}
	return s / a.size();
}
int sumNumbersLargerAverage(std::vector<int> a)
{
	double tbc = trungbinhcong(a);
	int s = 0;
	for (int i = 0; i  < a.size() ; ++i)
	{
		if (a[i] > tbc) {
			s = s + a[i];
		}
	}
	return s;

}
int main()
{
	vector<int> arr = {1, 2, 3, 4, 5};
	cout << false;
	return 0;
}