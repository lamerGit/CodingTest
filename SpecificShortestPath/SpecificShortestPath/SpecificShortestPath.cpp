#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <string>
#include <ctime>

using namespace std;
//
//방향성이 없는 그래프가 주어진다.세준이는 1번 정점에서 N번 정점으로 최단 거리로 이동하려고 한다.또한 세준이는 두 가지 조건을 만족하면서 이동하는 특정한 최단 경로를 구하고 싶은데, 그것은 바로 임의로 주어진 두 정점은 반드시 통과해야 한다는 것이다.
//
//세준이는 한번 이동했던 정점은 물론, 한번 이동했던 간선도 다시 이동할 수 있다.하지만 반드시 최단 경로로 이동해야 한다는 사실에 주의하라. 1번 정점에서 N번 정점으로 이동할 때, 주어진 두 정점을 반드시 거치면서 최단 경로로 이동하는 프로그램을 작성하시오.

//풀이
//v1,v2 <- 꼭지나야 하는 경로일때
//v1,v2 부터시작하는 경로를 구하고
// 1->v1->v2->n
// 1->v2->v1->n 2가지 경우가 있기때문에
// min(result[v1] + temp1[v2] + temp2[v - 1], result[v2] + temp2[v1] + temp1[v - 1]); 이런식으로 정답에 넣어준다

const int UNKNOWN = 987654321;

struct Edge
{
	int src;
	int dst;
	int weight;
};

vector<int> BellmanFord(vector < Edge> edges, int v, int start)
{

	vector<int> distance(v, UNKNOWN);
	distance[start] = 0;

	for (int i = 0; i < v - 1; i++)
	{
		for (auto& e : edges)
		{

			if (distance[e.src] == UNKNOWN)
				continue;

			if (distance[e.dst] > distance[e.src] + e.weight)
			{
				distance[e.dst] = distance[e.src] + e.weight;
			}

		}
	}

	return distance;


}


int main(void)
{

	ios_base::sync_with_stdio(0);
	cin.tie(0);


	int v;

	cin >> v;
	v++;
	vector<Edge> edges;

	int m;
	cin >> m;

	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		edges.emplace_back(Edge{ a,b,c });
		edges.emplace_back(Edge{ b,a,c });
	}
	int v1, v2;
	cin >> v1 >> v2;

	vector<int> result = BellmanFord(edges, v, 1);
	vector<int> temp1 = BellmanFord(edges, v, v1);
	vector<int> temp2 = BellmanFord(edges, v, v2);

	int answer = min(result[v1] + temp1[v2] + temp2[v - 1], result[v2] + temp2[v1] + temp1[v - 1]);

	if (answer >= UNKNOWN || answer < 0)
	{
		cout << -1;
	}
	else
	{
		cout << answer;
	}


	return 0;

}