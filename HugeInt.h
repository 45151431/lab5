#include<iostream>
#include<string>
#include<cstring>
using namespace std;
class HugeInt
{
	friend ostream &operator<<(ostream &, const HugeInt &);
	friend istream &operator>>(istream &, HugeInt &);
	public:
		HugeInt();
		HugeInt(long long int num);
		HugeInt(string str);
		HugeInt operator+(HugeInt &tmp);
		HugeInt operator-(HugeInt &tmp);
		const HugeInt &operator=(const HugeInt &tmp);
		void plus(HugeInt & a, HugeInt & b);
		int compare(HugeInt & tmp);
		void minus_1(HugeInt & a, HugeInt & b, int mode);
		void minus_2(HugeInt & a, HugeInt & b, int mode);
//	private:
		int a[100];
		char sign;
};
