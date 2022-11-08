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

//알고스팟 게임판 덮기

//H* W 크기의 게임판이 있습니다.게임판은 검은 칸과 흰 칸으로 구성된 격자 모양을 하고 있는데 이 중 모든 흰 칸을 3칸짜리 L자 모양의 블록으로 덮고 싶습니다.이 때 블록들은 자유롭게 회전해서 놓을 수 있지만, 서로 겹치거나, 검은 칸을 덮거나, 게임판 밖으로 나가서는 안 됩니다.위 그림은 한 게임판과 이를 덮는 방법을 보여줍니다.
//
//게임판이 주어질 때 이를 덮는 방법의 수를 계산하는 프로그램을 작성하세요.

using namespace std;

//cover에서 빈칸을 찾는다 -> set으로 검사 -> 가능한 칸일 경우 덮고 cover재귀 -> 재귀가끝난후 원상복구
//                                        

//주어진 칸을 덮을 수 있는 네가지 방법
//칸을 덮기위해서 이동해야하는 방향이다.
//현재칸은 무조건 덮히고 그칸을 기준으로 이동하는 것이다
const int coverType[4][3][2] =
{ {{0,0},{1,0},{0,1}}, //현재, 오른쪽, 밑
  {{0,0},{0,1},{1,1}}, //현재, 오른쪽, 오른쪽+밑
  {{0,0},{1,0},{1,1}}, //현재, 아래, 오른쪽+밑
  {{0,0},{1,0},{1,-1}} //현재, 아래, 왼쪽+밑
};

//board의 (y,x)를 type번 방법으로 덮거나, 덮었던 블록을 없앤다
//delta=1이면 덮고,-1이면 덮었던 블록을 없앤다
//만약 블록이 제대로 덮이지 않을 경우false를 반환

bool set(vector<vector<int>>& board, int y, int x, int type, int delta)
{
	bool ok = true;
	for (int i = 0; i < 3; i++)
	{
		const int ny = y + coverType[type][i][0];
		const int nx = x + coverType[type][i][1];

		if (ny < 0 || ny >= board.size() || nx < 0 || nx >= board[0].size()) //게임판 밖으로 나간경우
		{
			ok = false;
		}
		else if ((board[ny][nx] += delta) > 1) //이미 덮혀있는 경우
		{
			ok = false;
		}

	}
	return ok;
}

//board의 모든 빈칸을 덮을 수 있는 방법의 수를 반환
//board[i][j]=1 이미 덮인 칸 혹은 검은 칸
//board[i][j]=0 아직덮이지 않은 칸


int cover(vector < vector<int>>& board)
{
	//아직 채우지 못한 칸 중 가장 윗줄 왼쪽에 있는 칸을 찾는다.
	int y = -1, x = -1;
	for (int i = 0; i < board.size(); i++)
	{
		for (int j = 0; j < board[i].size(); j++)
		{
			if (board[i][j] == 0)
			{
				y = i;
				x = j;
				break;
			}
		}
		if (y != -1) //y가 -1이 아니면 아직덮이지 않은 칸이므로 break
			break;
	}

	//모든 칸을 채웠으면 1을 반환
	if (y == -1)
	{
		return 1;
	}
	int ret = 0;

	for (int type = 0; type < 4; type++)
	{
		if (set(board, y, x, type, 1))
		{
			ret += cover(board);
		}
		//덮었던 블록을 치운다
		set(board, y, x, type, -1);
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
		int h, w;
		cin >> h >> w;
		vector<vector<int>> v(h, vector<int>(w));
		for (int i = 0; i < h; i++)
		{
			string s;
			cin >> s;
			for (int j = 0; j < s.size(); j++)
			{
				if (s[j] == '#')
				{
					v[i][j] = 1;
				}
				else
				{
					v[i][j] = 0;
				}
			}
		}
		cout << cover(v) << "\n";
	}


	return 0;
}