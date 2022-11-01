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

//가끔 TV 에 보면 원주율을 몇만 자리까지 줄줄 외우는 신동들이 등장하곤 합니다.이들이 이 수를 외우기 위해 사용하는 방법 중 하나로, 숫자를 몇 자리 이상 끊어 외우는 것이 있습니다.이들은 숫자를 세 자리에서 다섯 자리까지로 끊어서 외우는데, 가능하면 55555 나 123 같이 외우기 쉬운 조각들이 많이 등장하는 방법을 택하곤 합니다.
//
//이 때, 각 조각들의 난이도는 다음과 같이 정해집니다 :
//
//모든 숫자가 같을 때(예 : 333, 5555) 난이도 : 1
//숫자가 1씩 단조 증가하거나 단조 감소할 때(예 : 23456, 3210) 난이도 : 2
//두 개의 숫자가 번갈아 가며 출현할 때(예 : 323, 54545) 난이도 : 4
//숫자가 등차 수열을 이룰 때(예 : 147, 8642) 난이도 : 5
//그 외의 경우 난이도 : 10
//원주율의 일부가 입력으로 주어질 때, 난이도의 합을 최소화하도록 숫자들을 3자리에서 5자리까지 끊어 읽고 싶습니다.최소의 난이도를 계산하는 프로그램을 작성하세요.

const int INF = 987654321;
string n;

// N[a..b] 구간의 난이도를 반환한다.
int classify(int a, int b)
{
	//숫자 조각을 가져온다
	string m = n.substr(a, b - a + 1);

	//첫 글자만으로 이루어진 문자열과 같으면 난이도는 1 예) 333,5555
	if (m == string(m.size(), m[0])) return 1;

	//등차수열인지 검사//////////////////////////// 예)23456,3210
	bool progressive = true;

	for (int i = 0; i < m.size() - 1; i++)
	{
		if (m[i + 1] - m[i] != m[1] - m[0])
		{
			progressive = false;
		}
	}
	//////////////////////////////////////////////


	//등차수열이고 공차가 1혹은 -1이면 난이도는 2
	if (progressive && abs(m[1] - m[0]) == 1)
	{
		return 2;
	}

	//두 수가 번갈아 등장하는지 확인한다. 예)323,54545
	bool alternationg = true;
	for (int i = 0; i < m.size(); i++)
	{
		if (m[i] != m[i % 2])
		{
			alternationg = false;
		}
	}
	//////////////////////////////////////////////

	//두 수가 번갈아 등장하면 난이도는 4
	if (alternationg)return 4;

	//공차가 1 아닌 등차수열의 난이도는 5 예) 147,8642
	if (progressive)return 5;

	//나머지 10
	return 10;

}

int cache[10002];
//수열 N[begin..]를 외우는 방법 중 난이도의 최소 합을 출력
int memorize(int begin)
{
	//기저 사례: 수열의 끝에 도달했을 경우
	if (begin == n.size()) return 0;

	//메모이제이션
	int& ret = cache[begin];
	if (ret != -1)return ret;
	ret = INF;

	for (int i = 3; i <= 5; i++)
	{
		if (begin + i <= n.size())
		{
			ret = min(ret, memorize(begin + i) + classify(begin, begin + i - 1));
		}
	}
	return ret;
}


int main(void)
{

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int c;
	cin >> c;

	while (c--)
	{
		memset(cache, -1, sizeof(cache));
		cin >> n;
		cout << memorize(0) << "\n";
	}





	return 0;

}