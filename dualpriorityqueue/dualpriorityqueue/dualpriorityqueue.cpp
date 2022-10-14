#include <iostream>
#include <vector>
#include <cstring>
#include <sstream>
#include <string>
#include <map>
#include <stack>
#include <math.h>
#include <queue>

using namespace std;

const int MAX = 1000001;

bool visited[MAX];

int main(void)

{

	ios_base::sync_with_stdio(0);

	cin.tie(0);

	int t;
	cin >> t;

	while (t--)
	{
		int n;
		cin >> n;

		priority_queue<pair<int, int>> maxHeap;
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;


		for (int i = 0; i < n; i++)
		{
			char op;
			int num;
			cin >> op >> num;

			if (op == 'I') //대문자 I일경우 queue 넣기
			{
				maxHeap.push({ num,i });
				minHeap.push({ num,i });
				visited[i] = true; // i번째 인덱스 방문을 true
			}
			else
			{
				if (num == 1) // 1일 경우 최댓값을 삭제
				{
					//유효하지 않은 숫자들 전부 pop
					while (!maxHeap.empty() && !visited[maxHeap.top().second])
					{
						maxHeap.pop();
					}

					if (!maxHeap.empty())
					{
						//pop하므로 유효하지 않다고 표시
						visited[maxHeap.top().second] = false;
						maxHeap.pop();
					}



				}
				else
				{
					while (!minHeap.empty() && !visited[minHeap.top().second])
					{
						minHeap.pop();
					}

					if (!minHeap.empty())
					{
						visited[minHeap.top().second] = false;
						minHeap.pop();
					}
				}



			}

		}

		while (!maxHeap.empty() && !visited[maxHeap.top().second])
		{
			maxHeap.pop();
		}
		while (!minHeap.empty() && !visited[minHeap.top().second])
		{
			minHeap.pop();
		}


		if (minHeap.empty() && maxHeap.empty())
		{
			cout << "EMPTY\n";
		}
		else
		{
			cout << maxHeap.top().first << " " << minHeap.top().first << "\n";
		}





	}



	return 0;

}