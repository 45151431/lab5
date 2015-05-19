#include"HugeInt.h"
ostream &operator<<(ostream &out, const HugeInt &tmp)
{
	if(tmp.sign=='-')
		out<<tmp.sign;
	int i=100-1;
	while(i>=0&&tmp.a[i]==0)
		i--;
	if(i<0)
		out<<"0";
	else
		while(i>=0)
			out<<tmp.a[i--];
	return out;
}
istream &operator>>(istream &in, HugeInt &tmp)
{
	string s;
	in>>s;
	if(s[0]=='-')
	{
		tmp.sign='-';
		for(int i=0, j=s.size()-2; i<s.size()-1; i++, j--)
			tmp.a[j]=s[i+1]-'0';
	}
	else
	{
		tmp.sign='+';
		for(int i=0, j=s.size()-1; i<s.size(); i++, j--)
			tmp.a[j]=s[i]-'0';
	}
	return in;
}
HugeInt::HugeInt()
{
	memset(a, 0, sizeof(a));
	sign='+';
}
HugeInt::HugeInt(long long int num)
{
	memset(a, 0, sizeof(a));
	if(num<0)
	{
		sign='-';
		num*=(-1);
		for(int i=0; i<100; i++)
		{
			a[i]=num%10;
			num/=10;
		}
	}
	else if(num>0)
	{
		sign='+';
		for(int i=0; i<100; i++)
		{
			a[i]=num%10;
			num/=10;
		}
	}
	else
	{
		sign='+';
		memset(a, 0, sizeof(a));
	}
}
HugeInt::HugeInt(string s)
{
	memset(a, 0, sizeof(a));
	if(s[0]=='-')
	{
		sign='-';
		for(int i=0, j=s.size()-2; i<s.size()-1; i++, j--)
			a[j]=s[i+1]-'0';
	}
	else
	{
		sign='+';
		for(int i=0, j=s.size()-1; i<s.size(); i++, j--)
			a[j]=s[i]-'0';
	}
}
HugeInt HugeInt::operator+(HugeInt &tmp)
{
	HugeInt result;
	if(sign==tmp.sign)//同號
	{
		plus(result, tmp);
		return result;
	}
	else
	{
		int mode=compare(tmp);
		if(mode==1)
			minus_1(result, tmp, 1);
		else if(mode==2)
			minus_2(result, tmp, 1);
		return result;
	}
}
HugeInt HugeInt::operator-(HugeInt &tmp)
{
	HugeInt result;
	if(sign!=tmp.sign)
	{
		plus(result, tmp);
		return result;
	}
	else
	{
		int mode=compare(tmp);
		if(mode==1)
			minus_1(result, tmp, 2);
		else if(mode==2)
			minus_2(result, tmp, 2);
		return result;
	}
}
const HugeInt &HugeInt::operator=(const HugeInt &tmp)
{
	for(int i=0; i<100; i++)
		a[i]=tmp.a[i];
	sign=tmp.sign;
	return *this;
}
void HugeInt::plus(HugeInt & result, HugeInt & tmp)
{
	result.sign=sign;
	for(int i=0; i<100; i++)
		result.a[i]=a[i]+tmp.a[i];
	for(int i=0; i<100-1; i++)
	{
		result.a[i+1]+=result.a[i]/10;
		result.a[i+1]%=10;
	}
}
int HugeInt::compare(HugeInt & tmp)
{
	for(int i=100-1; i>=0; i--)
		if(a[i]!=tmp.a[i])
		{
			if(a[i]>tmp.a[i])
				return 1;
			else
				return 2;
		}
	return 0;//全都相等
}
void HugeInt::minus_1(HugeInt & result, HugeInt & tmp, int mode)
{
	result.sign=sign;
	for(int i=0; i<100; i++)
		result.a[i]=a[i]-tmp.a[i];
	for(int i=0; i<100-1; i++)
		if(result.a[i]<0)
		{
			result.a[i+1]--;
			result.a[i]+=10;
		}
}
void HugeInt::minus_2(HugeInt & result, HugeInt & tmp, int mode)
{
	if(mode==1)
		result.sign=tmp.sign;
	else if(mode==2)
	{
		if(tmp.sign=='-')
			result.sign='+';
		else
			result.sign='-';
	}
	for(int i=0; i<100; i++)
		result.a[i]=tmp.a[i]-a[i];
	for(int i=0; i<100-1; i++)
		if(result.a[i]<0)
		{
			result.a[i+1]--;
			result.a[i]+=10;
		}
}
