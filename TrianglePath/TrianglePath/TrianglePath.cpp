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

int n, triangle[100][100];
int cache[100][100];
//(y,x) 위치부터 맨 아래줄까지 내려가면서 얻을 수 있는 최대 경로의 합을 반환

int path(int y, int x)
{
	//마지막에 도착하면 반환
	if (y == n - 1) return triangle[y][x];

	if (cache[y][x] != -1)return cache[y][x];
	//그냥 내려가기 y+1,x  오른쪽으로 내려가기 y+1,x+1중 더 큰값 + triangle[y][x](현재위치)를 저장
	return cache[y][x] = max(path(y + 1, x), path(y + 1, x + 1)) + triangle[y][x];
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

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < i + 1; j++)
			{
				cin >> triangle[i][j];
			}
		}

		cout << path(0, 0) << "\n";



	}


	return 0;
}