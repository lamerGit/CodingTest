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

//알고스팟 보글

//보글(Boggle) 게임은 그림(a)와 같은 5x5 크기의 알파벳 격자인
//게임판의 한 글자에서 시작해서 펜을 움직이면서 만나는 글자를 그 순서대로 나열하여 만들어지는 영어 단어를 찾아내는 게임입니다.펜은 상하좌우, 혹은 대각선으로 인접한 칸으로 이동할 수 있으며 글자를 건너뛸 수는 없습니다.지나간 글자를 다시 지나가는 것은 가능하지만, 펜을 이동하지않고 같은 글자를 여러번 쓸 수는 없습니다.
//
//예를 들어 그림의(b), (c), (d)는 각각(a)의 격자에서 PRETTY, GIRL, REPEAT을 찾아낸 결과를 보여줍니다.
//
//보글 게임판과 알고 있는 단어들의 목록이 주어질 때, 보글 게임판에서 각 단어를 찾을 수 있는지 여부를 출력하는 프로그램을 작성하세요.

using namespace std;

const int dx[8] = { -1,-1,-1,1,1,1,0,0 };
const int dy[8] = { -1, 0, 1,-1,0,1,-1,1 };

const int mapSize = 5; //게임판 사이즈
const int maxIndex = 11; // 글자의 최대길이

char board[mapSize][mapSize]; // 맵
int cache[mapSize][mapSize][maxIndex]; // 방문을 체크할 cache, mapSize별 체크하면서 글자의 길이마다 체크해야되서 maxindex추가

// 5x5사이즈 안에 있는지 확인 범위밖이면 true 아니면 false
bool outRange(int y, int x)
{
	return (y<0 || y>mapSize - 1 || x<0 || x>mapSize - 1);
}

// 5x5의 보글 게임 판의 해당 위치에서 주어진 단어가 시작하는지를 반환
bool hasWord(int y, int x, const string& word, int index)
{
	// 시작 위치가 범위 밖이면 무조건 실패
	if (outRange(y, x))
	{
		return false;
	}
	// 첫 글자가 일치하지 않으면 실패
	if (board[y][x] != word[0])
	{
		return false;
	}
	// 단어 길이가 1이면 성공 (위에2가지 체크를 통과했으면 범위안이면서 첫글자가 일치하기 때문에 무조건 성공인 것이다)
	if (word.size() == 1) return true;

	// 방문안한곳은 -1이다 -1이 아니면 방문했다는 것이기 때문에 방문했을때의 결과를 리턴
	if (cache[y][x][index] != -1) return cache[y][x][index];

	//인접 8칸 검사
	for (int i = 0; i < 8; i++)
	{
		int ny = y + dy[i];
		int nx = x + dx[i];

		// 다음칸이 범위 안에있는지, 첫글자는 일치하는지 확인할 필요 없음

		//현재 칸에게 hasWord재귀돌면서 글자가완성되면 true 아니면 false를 준다.
		cache[y][x][index] = hasWord(ny, nx, word.substr(1), index + 1);

		// 위에 재귀문 돌아서 현재칸이 true가 되면 그대로 리턴
		if (cache[y][x][index])
			return cache[y][x][index];

	}
	return false;
}


int main(void)
{

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int c;
	cin >> c;

	while (c--)
	{
		for (int i = 0; i < mapSize; i++)
		{
			for (int j = 0; j < mapSize; j++)
			{
				cin >> board[i][j];
			}
		}


		int n;
		cin >> n;
		while (n--)
		{
			string s;
			cin >> s;

			memset(cache, -1, sizeof(cache));
			bool result = false;
			for (int i = 0; i < mapSize; i++)
			{
				for (int j = 0; j < mapSize; j++)
				{
					/*cache[i][j][0] = hasWord(i, j, s, 1);
					if (cache[i][j][0] == 1)
					{
						result = true;
						cout << s << " YES\n";
						break;
					}*/

					if (hasWord(i, j, s, 0))
					{
						result = true;
						cout << s << " YES\n";
						break;
					}
				}
				if (result)
					break;

			}
			if (!result)
				cout << s << " NO\n";

		}


	}


	return 0;
}