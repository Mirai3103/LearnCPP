#include <iostream>
#include "TextTable.h"
using namespace std;
struct ThiSinh
{
private:
	string SBD;
	string FullName;
	double ForeignLanguageMark = 0;
	double BasicSubjectsMark = 0;
	double FoundationSubjectsMark = 0;
	double TotalMarks = 0;

public:
	ThiSinh() {}
	ThiSinh(string sbd, string fullName, double foreignLanguageMark, double basicSubjectsMark, double foundationSubjectsMark)
	{
		this->SBD = sbd;
		this->FullName = fullName;
		this->ForeignLanguageMark = foreignLanguageMark;
		this->BasicSubjectsMark = basicSubjectsMark;
		this->FoundationSubjectsMark = foundationSubjectsMark;
		this->TotalMarks = foreignLanguageMark + basicSubjectsMark + foundationSubjectsMark;
	}
	ThiSinh(string sdb, string fullName)
		: SBD(sdb), FullName(fullName) {}
	// getter, setter
	void setSBD(string sdb) { this->SBD = sdb; }
	string getSBD() { return this->SBD; }

	void setFullName(string fullName) { this->FullName = fullName; }
	string getFullName() { return this->FullName; }

	bool setForeignLanguageMark(double foreignLanguageMark)
	{
		if (foreignLanguageMark > 10 || foreignLanguageMark < 0)
			return false;
		this->ForeignLanguageMark = foreignLanguageMark;
		return true;
	}
	double getForeignLanguageMark() { return this->ForeignLanguageMark; }

	bool setBasicSubjectsMark(double basicSubjectsMark)
	{
		if (basicSubjectsMark > 10 || basicSubjectsMark < 0)
			return false;
		this->BasicSubjectsMark = basicSubjectsMark;
		return true;
	}
	double getBasicSubjectsMark() { return this->BasicSubjectsMark; }

	bool setFoundationSubjectsMark(double foundationSubjectsMark)
	{
		if (foundationSubjectsMark > 10 || foundationSubjectsMark < 0)
			return false;
		this->FoundationSubjectsMark = foundationSubjectsMark;
		this->TotalMarks = ForeignLanguageMark + BasicSubjectsMark + FoundationSubjectsMark;
		return true;
	}
	double getFoundationSubjectsMark() { return this->FoundationSubjectsMark; }

	double getTotalMarks() { return this->TotalMarks; }
	
	bool operator>(ThiSinh a)
	{
		return this->TotalMarks > a.getTotalMarks();
	}
	bool operator<(ThiSinh a)
	{
		return this->TotalMarks < a.getTotalMarks();
	}
};
void nhapDS(ThiSinh *DS, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "nhap thong tin thi sinh " << i + 1 << endl;
		string sbd, name;
		cout << "nhap sbd thi sinh: ";
		cin.ignore();
		getline(cin, sbd);
		cout << "Nhap ho va ten thi sinh: ";
		getline(cin, name);
		ThiSinh thisinh(sbd, name);
		double mark = -1;
		do
		{
			cout << "nhap diem mon ngoai ngu: ";
			cin >> mark;
		} while (!thisinh.setForeignLanguageMark(mark));
		do
		{
			cout << "nhap diem mon co ban: ";
			cin >> mark;
		} while (!thisinh.setBasicSubjectsMark(mark));
		do
		{
			cout << "nhap diem mon co so: ";
			cin >> mark;
		} while (!thisinh.setFoundationSubjectsMark(mark));
		DS[i] = thisinh;
	}
}
void yeuCauA(ThiSinh *DS, int n)
{
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		if ((DS[i].getBasicSubjectsMark() >= 5))
		{
			if ((DS[i].getForeignLanguageMark() >= 5))
			{
				if ((DS[i].getFoundationSubjectsMark() >= 5))
				{
					if (DS[i].getForeignLanguageMark() + DS[i].getFoundationSubjectsMark() >= 14)
					{
						count++;
					}
				}
			}
		}
	}
	cout << "so hoc sinh thoai man cau a la: " << count;
}
void ReverSort(ThiSinh *DS, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (DS[i] < DS[j])
			{
				ThiSinh temp = DS[i];
				DS[i] = DS[j];
				DS[j] = temp;
			}
		}
	}
}
void yeuCauB(ThiSinh *DS, int n)
{
	ReverSort(DS, n);
	cout << "\n3 thi sinh cao diem nhat la:\n";
	TextTable table('-', '|', '+');
	table.add("STT");
	table.add("SBD");
	table.add("Full Name");
	table.add("total Mark");
	table.endOfRow();
	for (int i = 0; i < 3; i++)
	{
		table.add(to_string(i + 1));
		table.add(DS[i].getSBD());
		table.add(DS[i].getFullName());
		table.add(to_string(DS[i].getTotalMarks()));
		table.endOfRow();
	}
	table.setAlignment(2, TextTable::Alignment::RIGHT);
	cout << table;
}
int main()
{
	int n;
	cout << "ban muon nhap bao nhieu thi sinh: ";
	cin >> n;
	ThiSinh *DSThiSinh = new ThiSinh[n];
	nhapDS(DSThiSinh, n);
	yeuCauA(DSThiSinh, n);
	yeuCauB(DSThiSinh, n);
	delete[] DSThiSinh;
	DSThiSinh = nullptr;
	return 0;
}