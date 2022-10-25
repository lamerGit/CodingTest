#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <string>
#include <ctime>

using namespace std;

//벨만포드 기본형

const int UNKNOWN = INT_MAX;

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

	//(v-1)번 반복
	for (int i = 0; i < v - 1; i++)
	{
		// 전체 에지에 대해 반복
		for (auto& e : edges)
		{

			//에지의 시작 정점의 거리 값이 UNKNOWN이면 스킵
			if (distance[e.src] == UNKNOWN)
				continue;

			//인접한 정점의 거리 값이 새로운 경로에 의한 거리 값보다 크면
			// 거리 값을 업데이트함
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

	int v = 5;
	vector<Edge> edges;

	//{시작 정점, 목표 정점, 가중치}
	vector<vector<int>> edge_map{ {0,1,3},{1,2,5},{1,3,10},{3,2,-7},{2,4,2} };

	for (auto& e : edge_map)
	{
		edges.emplace_back(Edge{ e[0],e[1],e[2] }); // push_back 이랑 같은 기능이지만 더좋다고 한다.
	}


	int start = 0;
	vector<int> distance = BellmanFord(edges, v, start);

	cout << "[" << start << "번 정점으로부터 최소 거리" << "\n";

	for (int i = 0; i < distance.size(); i++)
	{
		if (distance[i] == UNKNOWN)
		{
			cout << i << "번 정점 : 방문하지 않음!!" << "\n";
		}
		else
		{
			cout << i << "번 정점 : " << distance[i] << "\n";
		}
	}


	return 0;

}
