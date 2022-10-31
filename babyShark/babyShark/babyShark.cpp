#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <string>
#include <ctime>
#include <map>
#include <list>
#include <queue>

using namespace std;

//N×N 크기의 공간에 물고기 M마리와 아기 상어 1마리가 있다.공간은 1×1 크기의 정사각형 칸으로 나누어져 있다.한 칸에는 물고기가 최대 1마리 존재한다.
//
//아기 상어와 물고기는 모두 크기를 가지고 있고, 이 크기는 자연수이다.가장 처음에 아기 상어의 크기는 2이고, 아기 상어는 1초에 상하좌우로 인접한 한 칸씩 이동한다.
//
//아기 상어는 자신의 크기보다 큰 물고기가 있는 칸은 지나갈 수 없고, 나머지 칸은 모두 지나갈 수 있다.아기 상어는 자신의 크기보다 작은 물고기만 먹을 수 있다.따라서, 크기가 같은 물고기는 먹을 수 없지만, 그 물고기가 있는 칸은 지나갈 수 있다.
//
//아기 상어가 어디로 이동할지 결정하는 방법은 아래와 같다.
//
//더 이상 먹을 수 있는 물고기가 공간에 없다면 아기 상어는 엄마 상어에게 도움을 요청한다.
//먹을 수 있는 물고기가 1마리라면, 그 물고기를 먹으러 간다.
//먹을 수 있는 물고기가 1마리보다 많다면, 거리가 가장 가까운 물고기를 먹으러 간다.
//거리는 아기 상어가 있는 칸에서 물고기가 있는 칸으로 이동할 때, 지나야하는 칸의 개수의 최솟값이다.
//거리가 가까운 물고기가 많다면, 가장 위에 있는 물고기, 그러한 물고기가 여러마리라면, 가장 왼쪽에 있는 물고기를 먹는다.
//아기 상어의 이동은 1초 걸리고, 물고기를 먹는데 걸리는 시간은 없다고 가정한다.즉, 아기 상어가 먹을 수 있는 물고기가 있는 칸으로 이동했다면, 이동과 동시에 물고기를 먹는다.물고기를 먹으면, 그 칸은 빈 칸이 된다.
//
//아기 상어는 자신의 크기와 같은 수의 물고기를 먹을 때 마다 크기가 1 증가한다.예를 들어, 크기가 2인 아기 상어는 물고기를 2마리 먹으면 크기가 3이 된다.
//
//공간의 상태가 주어졌을 때, 아기 상어가 몇 초 동안 엄마 상어에게 도움을 요청하지 않고 물고기를 잡아먹을 수 있는지 구하는 프로그램을 작성하시오.

struct Point {
	int r, c, d; //위치 r,c rc까지 이동하기위한 거리
};

int n;
int seaMap[20][20];
int dr[4] = { -1,1,0,0 };
int dc[4] = { 0,0,-1,1 };

int solve(int r, int c)
{
	int ret = 0; //잡아먹는 시간
	int size = 2; //첫크기
	int cnt = 2; // 한마리 먹을때 마다 cnt--해주고 0이되면 size++

	Point minPt = { r,c,0 };

	do {
		bool visited[20][20] = { false }; //방문한것 다시방문 못하게 기록하는 변수
		queue<Point> myqueue;
		visited[minPt.r][minPt.c] = true;  //초기 위치 방문
		myqueue.push({ minPt.r,minPt.c,0 });
		minPt.d = 987654321; //rc까지 이동하기위한 거리를 최대값으로 넣는다.
		                     //이 값이 변하지 않으면 잡아먹을수 있는 물고기가 없다는 뜻으로 while문을 종료한다.

		while (!myqueue.empty()) //bfs시작
		{
			Point curr = myqueue.front();
			myqueue.pop();


			if (curr.d > minPt.d)break; //가까운 거리부터 탐색하기 때문에 큰값이 나오면 더이상 할필요가 없다
			if (seaMap[curr.r][curr.c] > size) continue; // 큰물고기를 발견하면 continue;
			if (seaMap[curr.r][curr.c] != 0 && seaMap[curr.r][curr.c] < size) //자신이 아니고 작은물고기면
			{
				if (curr.d < minPt.d) //이동한 거리가 curr이 minPt보다 작으면 minPt값 갱신 
				{
					minPt = curr;
				}
				else if (curr.d == minPt.d) //이동한 거리가 같을때
				{
					if (curr.r < minPt.r) // 위쪽에 있는 물고기 먼저 먹어야하기 때문에 minPt값 갱신
					{
						minPt = curr;
					}
					else if (curr.r == minPt.r && curr.c < minPt.c) //위쪽위치도 같으면 왼쪽부터 먹어야 하기때문에 왼쪽값이 작을때 갱신
					{
						minPt = curr;
					}
				}
				continue; //이미 가장가까운 물고기를 찾았기 때문에 continue를 해준다.
			}


			for (int i = 0; i < 4; i++)
			{
				int nr = curr.r + dr[i];
				int nc = curr.c + dc[i];
				if (nr<0 || nr>n - 1 || nc<0 || nc>n - 1)continue;
				if (visited[nr][nc])continue;
				visited[nr][nc] = true;
				myqueue.push({ nr,nc,curr.d + 1 });

			}

		}

		if (minPt.d != 987654321)
		{
			ret += minPt.d; // 거리=시간 이라서 ret값에 거리값을 더해준다.
			cnt--;          // size업을 위한 cnt감소
			if (cnt == 0)
			{
				size++;
				cnt = size;
			}
			seaMap[minPt.r][minPt.c] = 0; // 물고기를 먹었으니 그곳을 0으로 변경
		}



	} while (minPt.d != 987654321);



	return ret;
}


int main(void)
{

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	int sr, sc;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> seaMap[i][j];
			if (seaMap[i][j] == 9)
			{
				sr = i;
				sc = j;
				seaMap[i][j] = 0;
			}
		}
	}

	cout << solve(sr, sc);

	return 0;

}