#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>
#include <map>
#include <limits>
#include <string>

using namespace std;
//
//빨간색 볼과 파란색 볼이 <그림 1>에서 보인 것처럼 일직선상에 섞여 놓여 있을 때, 볼을 옮겨서 같은 색 볼끼리 인접하게 놓이도록 하려고 한다.볼을 옮기는 규칙은 다음과 같다.
//
//바로 옆에 다른 색깔의 볼이 있으면 그 볼을 모두 뛰어 넘어 옮길 수 있다.즉, 빨간색 볼은 옆에 있는 파란색 볼 무더기를 한 번에 뛰어 넘어 옮길 수 있다.유사하게, 파란색 볼은 옆에 있는 빨간색 볼 무더기를 한 번에 뛰어 넘어 옮길 수 있다.
//옮길 수 있는 볼의 색깔은 한 가지이다.즉, 빨간색 볼을 처음에 옮겼으면 다음에도 빨간색 볼만 옮길 수 있다.유사하게, 파란색 볼을 처음에 옮겼으면 다음에도 파란색 볼만 옮길 수 있다.

//
//파란색들을 왼쪽으로 다 모을 때, 오른쪽으로 모을 때
//
//
//
//빨간색들을 왼쪽으로 다 모을 때, 오른쪽으로 모을 때
//
//
//
//(코드에서 정말로 배열의 각 방을 스왑하거나 하지는 않는다.개수를 셀 뿐이다.)
//
//
//
//이렇게 네 가지의 경우를 모두 구해 최소값을 구하도록 만들었다.


int main(void)
{

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	string s;
	cin >> s;

	int size = s.length();
	bool check = false;
	int minNumber = INT_MAX;
	int cnt = 0;

	for (int i = 0; i < size; i++)
	{
		if (s[i] == 'B')
		{
			check = true;
		}
		if (check && s[i] == 'R')
		{
			cnt++;
		}

	}
	check = false;
	minNumber = min(minNumber, cnt);
	cnt = 0;

	for (int i = n - 1; i >= 0; i--)
	{
		if (s[i] == 'B')
		{
			check = true;
		}
		if (check && s[i] == 'R')
		{
			cnt++;
		}

	}
	check = false;
	minNumber = min(minNumber, cnt);
	cnt = 0;

	for (int i = 0; i < size; i++)
	{
		if (s[i] == 'R')
		{
			check = true;
		}
		if (check && s[i] == 'B')
		{
			cnt++;
		}

	}
	check = false;
	minNumber = min(minNumber, cnt);
	cnt = 0;


	for (int i = n - 1; i >= 0; i--)
	{
		if (s[i] == 'R')
		{
			check = true;
		}
		if (check && s[i] == 'B')
		{
			cnt++;
		}

	}
	check = false;
	minNumber = min(minNumber, cnt);
	cnt = 0;

	cout << minNumber;

	return 0;

}
