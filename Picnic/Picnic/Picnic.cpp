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
//
// 알고스팟 소풍
// 
//안드로메다 유치원 익스프레스반에서는 다음 주에 율동공원으로 소풍을 갑니다.원석 선생님은 소풍 때 학생들을 두 명씩 짝을 지어 행동하게 하려고 합니다.그런데 서로 친구가 아닌 학생들끼리 짝을 지어 주면 서로 싸우거나 같이 돌아다니지 않기 때문에, 항상 서로 친구인 학생들끼리만 짝을 지어 줘야 합니다.
//
//각 학생들의 쌍에 대해 이들이 서로 친구인지 여부가 주어질 때, 학생들을 짝지어줄 수 있는 방법의 수를 계산하는 프로그램을 작성하세요.짝이 되는 학생들이 일부만 다르더라도 다른 방법이라고 봅니다.예를 들어 다음 두 가지 방법은 서로 다른 방법입니다.
//
//(태연, 제시카) (써니, 티파니) (효연, 유리)
//(태연, 제시카) (써니, 유리) (효연, 티파니)

int n;
bool areFriends[10][10]; //[누가][누구랑]친구인지 기록해둘 변수

//takne[i]=i번째 학생이 짝을 이미 찾았으면 true,아니면false
int countPairings(bool taken[10])
{
	//남은 학생들 중 가장 번호가 빠른 학생을 찾는다.
	int firstFree = -1;

	for (int i = 0; i < n; i++)
	{
		if (!taken[i])
		{
			firstFree = i;
			break;
		}
	}
	// 모든 학생이 짝을 찾았으면 한 가지 방법을 찾았으니 종료
	if (firstFree == -1) return 1;
	int ret = 0;

	// 이 학생과 짝지을 학생을 결정
	for (int i = firstFree + 1; i < n; i++) //현재학생+1 에서 n-1까지 쭉본다 i는 해당학생
	{
		if (!taken[i] && areFriends[firstFree][i]) // 해당학생이 짝이 없고 현재 학생과 친구일경우
		{
			taken[firstFree] = taken[i] = true; // 현재학생과 해당학생 true
			ret += countPairings(taken); // 재귀돌면서 다른학생도 짝을 찾아준다
			taken[firstFree] = taken[i] = false; //다른 경우도 보기위해서 false로 바꾸어줌
		}
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
		int m;
		cin >> n >> m;
		memset(areFriends, false, sizeof(areFriends));
		bool taken[10];
		memset(taken, false, sizeof(taken));
		int a, b;
		for (int i = 0; i < m; i++)
		{
			cin >> a >> b;
			areFriends[a][b] = areFriends[b][a] = true; //서로 친구해주기
		}
		cout << countPairings(taken) << "\n";

	}


	return 0;
}