#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <string>
#include <ctime>
#include <map>

using namespace std;

//N줄에 0 이상 9 이하의 숫자가 세 개씩 적혀 있다.내려가기 게임을 하고 있는데, 이 게임은 첫 줄에서 시작해서 마지막 줄에서 끝나게 되는 놀이이다.

const int MAX = 100001;

int n;

int board[MAX][3];
int best[2][3];
int worst[2][3];

int main(void)
{

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cin >> board[i][j];
		}
	}

	for (int i = 1; i <= n; i++)
	{
		int cur = i % 2;
		int prev = (i - 1) % 2;

		best[cur][0] = max(best[prev][0], best[prev][1]) + board[i][0];
		best[cur][1] = max(max(best[prev][0], best[prev][1]), best[prev][2]) + board[i][1];
		best[cur][2] = max(best[prev][2], best[prev][1]) + board[i][2];


		worst[cur][0] = min(worst[prev][0], worst[prev][1]) + board[i][0];
		worst[cur][1] = min(min(worst[prev][0], worst[prev][1]), worst[prev][2]) + board[i][1];
		worst[cur][2] = min(worst[prev][2], worst[prev][1]) + board[i][2];

	}

	cout << max(max(best[n % 2][0], best[n % 2][1]), best[n % 2][2]) << " ";
	cout << min(min(worst[n % 2][0], worst[n % 2][1]), worst[n % 2][2]);


	return 0;

}