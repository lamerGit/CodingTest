#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <string>
#include <ctime>
#include <map>

using namespace std;
//
//n(1≤n≤1, 000)개의 도시가 있다.그리고 한 도시에서 출발하여 다른 도시에 도착하는 m(1≤m≤100, 000)개의 버스가 있다.우리는 A번째 도시에서 B번째 도시까지 가는데 드는 버스 비용을 최소화 시키려고 한다.
//그러면 A번째 도시에서 B번째 도시 까지 가는데 드는 최소비용과 경로를 출력하여라.항상 시작점에서 도착점으로의 경로가 존재한다.

const int UNKNOWN = 987654321;

int route[1003];
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
				route[e.dst] = e.src; //비용이 업데이트 되면 route에 저장되는 값은 전 인덱스값
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
	}
	int v1, v2;
	cin >> v1 >> v2;

	vector<int> temp = BellmanFord(edges, v, v1);

	cout << temp[v2] << "\n";

	int t = v2;

	vector<int> ans;
	while (t)
	{
		ans.push_back(t);
		t = route[t]; //route에 저장 된 값은 전 인덱스 값이므로 t가 0이 될때까지 경로를 찾는다
	}
	cout << ans.size() << "\n";

	for (int i = ans.size() - 1; i >= 0; i--)
	{
		cout << ans[i] << " ";
	}


	return 0;

}