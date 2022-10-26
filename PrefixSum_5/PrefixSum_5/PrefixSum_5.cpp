#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>
#include <map>
#include <limits>
#include <string>
#include <set>
#include <queue>

using namespace std;

//N×N개의 수가 N×N 크기의 표에 채워져 있다. (x1, y1)부터(x2, y2)까지 합을 구하는 프로그램을 작성하시오. (x, y)는 x행 y열을 의미한다.

//구간 합 구하기 문제를 응용해서 풀이함

int arr[1025][1025] = { 0 };

int main(void)
{

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;


	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			int number;
			cin >> number;
			arr[i][j + 1] = arr[i][j] + number;
		}
	}


	while (m--)
	{
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;

		int sum = 0;

		for (int i = x1; i <= x2; i++)
		{
			sum += arr[i][y2 + 1] - arr[i][y1];
		}

		cout << sum << "\n";
	}



	return 0;

}