#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <string>
#include <ctime>

using namespace std;

//N×N크기의 땅이 있고, 땅은 1×1개의 칸으로 나누어져 있다.각각의 땅에는 나라가 하나씩 존재하며, r행 c열에 있는 나라에는 A[r][c]명이 살고 있다.인접한 나라 사이에는 국경선이 존재한다.모든 나라는 1×1 크기이기 때문에, 모든 국경선은 정사각형 형태이다.
//
//오늘부터 인구 이동이 시작되는 날이다.
//
//인구 이동은 하루 동안 다음과 같이 진행되고, 더 이상 아래 방법에 의해 인구 이동이 없을 때까지 지속된다.
//
//국경선을 공유하는 두 나라의 인구 차이가 L명 이상, R명 이하라면, 두 나라가 공유하는 국경선을 오늘 하루 동안 연다.
//위의 조건에 의해 열어야하는 국경선이 모두 열렸다면, 인구 이동을 시작한다.
//국경선이 열려있어 인접한 칸만을 이용해 이동할 수 있으면, 그 나라를 오늘 하루 동안은 연합이라고 한다.
//연합을 이루고 있는 각 칸의 인구수는(연합의 인구수) / (연합을 이루고 있는 칸의 개수)가 된다.편의상 소수점은 버린다.
//연합을 해체하고, 모든 국경선을 닫는다.
//각 나라의 인구수가 주어졌을 때, 인구 이동이 며칠 동안 발생하는지 구하는 프로그램을 작성하시오.

int n, l, r;
int map[50][50];
int visited[50][50];
int cnt;

int find(int x, int y, int value) //연결되있는 나라를 구하는 함수
{
	if (x<0 || x>n - 1 || y<0 || y>n - 1) // 범위 안인지 확인
	{
		return 0;
	}
	if (visited[x][y]) // 방문했는지 확인
	{
		return 0;
	}

	if (value != -1) // value가 -1이면 첫시작 나라임
	{
		int diff = abs(value - map[x][y]); // value가 1이 아니면 현재나라 - 상하좌우중 선택된 나라

		if (diff<l || diff>r)  // 특정범위 안이 아니라면 return 0
		{
			return 0;
		}
	}

	visited[x][y] = 1;  //위에 조건들을 전부 넘어가면 방문표시
	cnt++; // 몇개의 나라를 방문했는지 확인
	int sum = map[x][y];  //주변의 나라를 전부 더해야하기 때문에 변수에 저장한 다음 상하좌우 전부 검사
	sum += find(x - 1, y, map[x][y]);
	sum += find(x + 1, y, map[x][y]);
	sum += find(x, y - 1, map[x][y]);
	sum += find(x, y + 1, map[x][y]);

	return sum; //전부 끝났으면 최종 sum값 리턴


}

void move(int x, int y, int value) //연결된 나라를 전부 sum/cnt로 만들어 주는함수
{
	if (x<0 || x>n - 1 || y<0 || y>n - 1)
	{
		return;
	}
	if (visited[x][y] != 1) // 0은 미방문 2은 최종인구라서 1이아닌 값은 전부 리턴
	{
		return;
	}
	//방문이 1인값이면 최종으로 됬다는 표시로 2로 만들어줌
	visited[x][y] = 2;

	map[x][y] = value; //맵값도 변경하고 상하좌우 1인값을 찾아서 2로 만들면서 map값도 sum/cnt로 변경
	move(x - 1, y, value); 
	move(x + 1, y, value);
	move(x, y - 1, value);
	move(x, y + 1, value);
}

int solve()
{
	int ret = 0;
	bool flag;
	do {
		flag = false;
		//memset(visited, 0, sizeof(visited));
		for (int i = 0; i < n; i++) //여러번 해야하기 때문에 할때 마다 방문초기화
		{
			for (int j = 0; j < n; j++)
			{
				visited[i][j] = 0;
			}
		}


		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (visited[i][j] == 0) // 방문하지 않았다면
				{
					cnt = 0; // 연결되 나라 초기화
					int sum = find(i, j, -1); // 연결된 나라의 전부의 값
					//find과정에서 연결될때마다 cnt++가 됨으로 cnt가 2이상이면 2개가 연결되었다는것
					if (cnt > 1)
					{
						flag = true; // 연결됬다는 표시
						move(i, j, sum / cnt); // 연결된 나라 전부 sum/cnt해준다.
					}
					else
					{
						visited[i][j] = 2; //연결된 나라가 없으면 최종값표시
					}
				}
			}


		}
		if (flag) // flag가 true 면 연결된 나라가 있었다는 표시
		{
			ret++;
		}
	} while (flag); // 연결된 나라가 없을때 까지 계속 while문을 돈다


	return ret;
}

int main(void)
{

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> l >> r;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> map[i][j];
		}
	}

	cout << solve() << "\n";

	return 0;

}