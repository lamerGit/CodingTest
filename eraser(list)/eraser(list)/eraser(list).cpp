﻿//$N$개의 칸에 $1$ 부터 $N$ 까지의 수들이 왼쪽부터 순서대로 저장되어 있다.또, 각 칸은 왼쪽부터 $1$ 부터 $N$까지 순서대로 번호가 붙어 있다.즉, 처음에는 각 칸의 번호와 각 칸에 저장된 수가 같다.
//
//아래 그림은 $N = 7$일 때의 예이다.
//
//
//
//다음 작업을 수가 정확히 하나가 남을 때 까지 반복한다.
//
//(A)홀수번 칸의 수들을 모두 지운다(B) 남은 수들을 왼쪽으로 모은다.
//
//제일 첫 작업의(A) 단계가 끝나면 칸들의 상태는 다음과 같을 것이다.
//
//
//
//(B)단계가 끝나면 다음과 같을 것이다.
//
//
//
//두번째 작업이 진행되면 칸들은 아래 두 그림과 같이 바뀔 것이다.
//
//
//
//
//
//이제 수가 하나 남았으므로 작업은 더 이상 진행되지 않는다.
//
//$N$을 입력으로 받아 위와 같이 작업을 진행했을 때 마지막으로 남는 수를 계산하는 프로그램을 작성하라.
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <string>
#include <ctime>
#include <map>
#include <list>

using namespace std;


int main(void)
{

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	list<int> arr;

	for (int i = 1; i <= n; i++)
	{
		arr.push_back(i);
	}
	if (arr.size() == 1)
	{
		cout << 1;
		return 0;
	}

	do
	{
		int cnt = 1;


		for (list<int>::iterator it = arr.begin(); it != arr.end();)
		{
			if (cnt % 2 != 0)
			{
				it = arr.erase(it);
			}
			else
			{
				it++;
			}
			cnt++;
		}


	} while (arr.size() != 1);

	cout << arr.front();



	return 0;

}