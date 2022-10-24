#include <iostream>
#include <functional>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
#include <cmath>
#include <string.h>
#include <vector>

using namespace std;

//
//KOI 본선 대회에 N명의 학생이 참가했다.이 학생들을 각각 1부터 N까지 정수로 표현하자.대회가 끝나고 성적을 발표하는데, 이 대회는 전체 학생의 등수를 발표 하는 대신, 두 학생 A, B가 대회 본부에 찾아가면 본부는 두 학생 중 어느 학생이 더 잘 했는지를 알려준다.둘 이상의 학생이 동점인 경우는 없다.
//
//자신의 전체에서 등수가 궁금한 학생들은 둘 씩 짝을 지어서 대회 본부에 총 M번 질문을 했다.여러분은 등수를 알고 싶은 학생 X와 대회 본부의 질문에 대한 답들 로부터 이 학생 X의 등수 범위를 찾아서 출력한다.질문에 대한 답으로 알 수 있는 최대한 정확한 답을 출력한다.


typedef long long ll;

int n, m, x, visited[100001];
vector<int> adj[100001], reverse_adj[100001];
int cnt = -1, reverse_cnt = -1;

void dfs(int cur)
{
    if (visited[cur])
        return;

    visited[cur] = true;
    cnt++;

    for (int next : adj[cur])
        dfs(next);
}

void reverse_dfs(int cur)
{
    if (visited[cur])
        return;

    visited[cur] = true;
    reverse_cnt++;

    for (int next : reverse_adj[cur])
        reverse_dfs(next);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("input.txt", "r", stdin);

    cin >> n >> m >> x;

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;

        adj[a].push_back(b);         // 정방향 간선
        reverse_adj[b].push_back(a); // 역방향 간선
    }

    dfs(x);

    memset(visited, 0x00, sizeof(visited));
    reverse_dfs(x);

    cout << reverse_cnt + 1 << ' ' << n - cnt << endl;

    return 0;
}

//틀린코드 (내가 짠거) 효율성 실패

//#include <iostream>
//#include <vector>
//#include <cstring>
//#include <queue>
//#include <algorithm>
//#include <map>
//#include <limits>
//#include <string>
//#include <set>
//
//using namespace std;
//
//struct cmpNumber
//{
//	set<int> bigNumber;
//	set<int> smallNumber;
//};
//
//void upNumber(int n, int target, map<int, cmpNumber>& m) n번째 수보다 작은 target을 n번째 수보다 큰 그룹에 넣는 함수
//{
//	m[n].smallNumber.insert(target);
//
//	for (auto i : m[n].bigNumber)
//	{
//		upNumber(i, target, m);
//	}
//
//
//}
//
//void FindBigNumber(int n, set<int>& s, map<int, cmpNumber> m) n을 s에 넣고 n보다큰 수를 찾아서 s에 넣는 함수
//{
//	s.insert(n);
//
//	for (auto i : m[n].bigNumber)
//	{
//		FindBigNumber(i, s, m);
//	}
//
//
//}



//int main(void)
//{
//
//	ios_base::sync_with_stdio(0);
//	cin.tie(0);
//	map<int, cmpNumber> mapNumber;
//
//
//	int n, m, x;
//	cin >> n >> m >> x;
//
//	for (int i = 1; i <= n; i++)
//	{
//		mapNumber[i];
//	}
//
//	while (m--)
//	{
//		int a, b;
//		cin >> a >> b;
//
//		mapNumber[a].smallNumber.insert(b);
//		mapNumber[b].bigNumber.insert(a);
//
//		for (auto i : mapNumber[a].bigNumber)
//		{
//			upNumber(i, b, mapNumber);
//		}
//
//
//
//	}
//
//	for (int i = 1; i <= n; i++)
//	{
//		cout << i << " big : ";
//		for (auto j : mapNumber[i].bigNumber)
//		{
//			cout << j << " ";
//		}
//		cout << "\n";
//	}
//
//	for (int i = 1; i <= n; i++)
//	{
//		cout << i << " small : ";
//		for (auto j : mapNumber[i].smallNumber)
//		{
//			cout << j << " ";
//		}
//		cout << "\n";
//	}
//
//	if (mapNumber[x].bigNumber.empty())
//	{
//		cout << mapNumber[x].bigNumber.size() + 1 << " ";
//	}
//	else
//	{
//		set<int> temp;
//		for (auto i : mapNumber[x].bigNumber)
//		{
//			FindBigNumber(i, temp, mapNumber);
//
//		}
//
//		cout << temp.size() + 1 << " ";
//
//
//	}
//	cout << n - mapNumber[x].smallNumber.size();
//
//
//	return 0;
//
//}
