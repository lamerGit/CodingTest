#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <string>
#include <ctime>
#include <map>
#include <list>
#include <queue>
#include <cstring>

using namespace std;

//카라츠바 알고리즘 기본형

//num[]의 자릿수 올림을 처리

void normalize(vector<int>& num)
{
	num.push_back(0);
	//자릿수 올림을 처리
	for (int i = 0; i < num.size() - 1; i++)
	{
		if (num[i] < 0)
		{
			int borrow = (abs(num[i]) + 9) / 10;
			num[i + 1] -= borrow;
			num[i] += borrow * 10;

		}
		else
		{
			num[i + 1] += num[i] / 10;
			num[i] %= 10;
		}
	}
	while (num.size() > 1 && num.back() == 0)
	{
		num.pop_back();
	}
}

//두 긴 자연수의 곱을 반환
//각 배열에는 각 수의 자릿수가 1의 자리에서부터 시작해 저장되어 있다
//예 : multiply([3,2,1], [6,5,4])=123*456=56088=[8,8,0,6,5]

vector<int> multiply(const vector<int>& a, const vector<int>& b)
{
	vector<int> c(a.size() + b.size() + 1, 0);
	for (int i = 0; i < a.size(); i++)
	{
		for (int j = 0; j < b.size(); j++)
		{
			c[i + j] += (a[i] * b[j]);
		}
	}
	normalize(c);
	return c;

}


//a+=b*(10^k)를 구현
void addTo(vector<int>& a, const vector<int>& b, int k)
{
	int length = b.size();
	a.resize(max(a.size() + 1, b.size() + k));

	for (int i = 0; i < length; i++)
	{
		a[i + k] += b[i];
	}

	//정규화
	for (int i = 0; i < a.size(); i++)
	{
		if (a[i] >= 10)
		{
			a[i + 1] += a[i] / 10;
			a[i] %= 10;
		}
	}


}
//a-=b를 구현 a>=b를 가정
void subFrom(vector<int>& a, const vector<int>& b)
{
	int length = b.size();
	a.resize(max(a.size() + 1, b.size() + 1));

	for (int i = 0; i < length; i++)
	{
		a[i] -= b[i];
	}

	//정규화
	for (int i = 0; i < a.size(); i++)
	{
		if (a[i] < 0)
		{
			a[i] += 10;
			a[i + 1] -= 1;
		}
	}

}

//두 긴 정수의 곱을 반환
//(a0+a1)*(b0+b1)=(a0*b0)(=z0)+(a1*b0+a0*b1)(=z1)+(a1*b1)(=z2)의 원리

vector<int> karatsuba(const vector<int>& a, const vector<int>& b)
{
	int an = a.size();
	int bn = b.size();

	if (an < bn) return karatsuba(b, a);

	if (an == 0 || bn == 0) return vector<int>();

	if (an <= 50) return multiply(a, b);

	int half = an / 2;

	vector<int> a0(a.begin(), a.begin() + half);
	vector<int> a1(a.begin() + half, a.end());
	vector<int> b0(b.begin(), b.begin() + min<int>(b.size(), half));
	vector<int> b1(b.begin() + min<int>(b.size(), half), b.end());

	//z2=a1*b1
	vector<int> z2 = karatsuba(a1, b1);

	//z0=a0*b0
	vector<int> z0 = karatsuba(a0, b0);

	//a0=a0+a1; b0=b0+b1
	addTo(a0, a1, 0);
	addTo(b0, b1, 0);

	//z1=(a0*b0)-z0-z2;
	vector<int> z1 = karatsuba(a0, b0);
	subFrom(z1, z0);
	subFrom(z1, z2);

	//ret=z0+z1*10^half+z2*10^(half*2)
	vector<int> ret;
	addTo(ret, z0, 0);
	addTo(ret, z1, half);
	addTo(ret, z2, half + half);
	return ret;

}


int main(void)
{

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	vector<int> a, b, result;

	string number;

	cout << "첫번째 정수 :";
	cin >> number;
	for (int i = number.size() - 1; i >= 0; i--)
	{
		a.push_back(number[i] - '0');
	}

	cout << "두번째 정수 :";
	cin >> number;
	for (int i = number.size() - 1; i >= 0; i--)
	{
		b.push_back(number[i] - '0');
	}

	result = karatsuba(a, b);

	for (int i = result.size() - 1; i >= 0; i--)
	{
		cout << result[i];
	}


	return 0;

}