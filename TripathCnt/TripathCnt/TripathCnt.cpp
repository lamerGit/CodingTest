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

//알고스팟 삼각형 위의 최대 경로 수 세기

//9
//5 7
//1 3 2
//3 5 5 6
//위 형태와 같이 삼각형 모양으로 배치된 자연수들이 있습니다.맨 위의 숫자에서 시작해, 한 번에 한 칸씩 아래로 내려가 맨 아래 줄로 내려가는 경로를 만들려고 합니다.경로는 아래 줄로 내려갈 때마다 바로 아래 숫자, 혹은 오른쪽 아래 숫자로 내려갈 수 있습니다.
//
//이 때 숫자의 합이 가장 큰 경로는 하나가 아니라 여러 개일 수 있습니다.예를 들어 위 삼각형에서는{ 9, 7, 2, 6 }과{ 9, 7, 3, 5 }의 합이 모두 최대인 24이고, { 9, 7, 3, 5 }는 두 번 등장하거든요.
//
//삼각형이 주어질 때 최대 경로의 수를 세는 프로그램을 작성하세요.

int countCache[100][100];
int n;
int triangle[100][100];
int cache[100][100];

int path(int y, int x)
{
	if (y == n - 1) return triangle[y][x];

	if (cache[y][x] != -1) return cache[y][x];

	return cache[y][x] = max(path(y + 1, x), path(y + 1, x + 1)) + triangle[y][x];
}
//(y,x)에서 시작해서 맨 아래줄까지 내려가는 경로 중 최대 경로의 개수를 반환

int count(int y, int x)
{
	if (y == n - 1) return 1;

	if (countCache[y][x] != -1) return countCache[y][x];

	countCache[y][x] = 0;

	if (path(y + 1, x + 1) >= path(y + 1, x)) countCache[y][x] += count(y + 1, x + 1);
	if (path(y + 1, x + 1) <= path(y + 1, x)) countCache[y][x] += count(y + 1, x);

	return countCache[y][x];
}


int main(void)
{

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int c;
	cin >> c;

	while (c--)
	{
		cin >> n;
		memset(cache, -1, sizeof(cache));
		memset(countCache, -1, sizeof(countCache));

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < i + 1; j++)
			{
				cin >> triangle[i][j];
			}
		}

		cout << count(0, 0) << "\n";
	}

	return 0;
}