#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>
#include <map>
#include <limits>
#include <string>
#include <set>

using namespace std;

//트리의 지름이란, 트리에서 임의의 두 점 사이의 거리 중 가장 긴 것을 말한다.트리의 지름을 구하는 프로그램을 작성하시오.

struct Node
{
	int index;
	int dist;
};

int v, maxDist, maxNode;
bool visit[100001];
vector<Node> graph[100001];

void dfs(int node, int dist)
{
	if (visit[node])
		return;

	if (maxDist < dist)
	{
		maxDist = dist;
		maxNode = node;
	}

	visit[node] = true;

	for (int i = 0; i < graph[node].size(); i++)
	{
		dfs(graph[node][i].index, graph[node][i].dist + dist);
	}
}


int main(void)
{

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> v;
	int fr, to, dist;
	for (int i = 1; i <= v; i++)
	{
		cin >> fr;
		while (true)
		{
			cin >> to;
			if (to == -1)
			{
				break;
			}
			cin >> dist;

			graph[fr].push_back({ to,dist });
			graph[to].push_back({ fr,dist });

		}

	}

	dfs(1, 0);
	memset(visit, 0, sizeof(visit));
	maxDist = 0;

	dfs(maxNode, 0);

	cout << maxDist << "\n";

	return 0;

}
