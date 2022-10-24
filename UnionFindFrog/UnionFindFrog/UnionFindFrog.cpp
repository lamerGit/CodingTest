#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <string>

using namespace std;

//
//통나무 N개가 가로(수평) 방향으로 연못에 떠 있다.개구리는 한 통나무 A에서 다른 통나무 B로 정확히 수직 방향으로 점프할 수 있다.단, 점프할 때 다른 통나무 위를(끝 점 포함) 지나면 안된다.
//
//예를 들어 <그림 1>에서 1번 통나무에서 2번 통나무로 점선을 따라 개구리가 점프하는 것이 가능하다. 1번 통나무에서 2번 통나무로 점프한 후 다시 3번 통나무로 점프하면 1번 통나무에서 3번 통나무로 이동하는 것이 가능하다. (통나무 위에서 걸어서 움직이는 것은 언제든 가능하다.)

//통나무들의 위치를 입력받아 질문으로 주어진 통나무들의 쌍에 대해서 개구리가 한 통나무에서 다른 통나무로 한번 이상의 점프로 이동이 가능한지 판단하는 프로그램을 작성하라.

//유니온 파인드라는 알고리즘사용해 푸는것이다

//유니온 파인드 예제

//#include<iostream>
//using namespace std;
//int parent[9]; // 위 그림에서 배열에 해당하는 것
//
//int find(int x) {
//	if (parent[x] == x) // 배열 인덱스와 값이 같다면 해당 값 리턴
//		return x;
//	return parent[x] = find(parent[x]); // 배열의 값을 인덱스로 갖는 값 리턴
//}
//
//void merge(int x, int y) {
//	x = find(x);
//	y = find(y); // 각각 find연산을 통해 루트 노드를 가짐
//	if (x == y) return; // x와 y가 같다면 이미 연결되어있는 것
//	parent[y] = x; // 배열의 y인덱스에 x값을 저장
//}
//
//bool isUnion(int x, int y) { // 두 노드가 연결되어있는지 판별하는 함수
//	x = find(x);
//	y = find(y);
//	if (x == y)
//		return true;
//	return false;
//}
//
//int main() {
//	for (int i = 1; i <= 8; i++) // 배열 초기화 과정
//		parent[i] = i;
//
//	merge(1, 2);
//	merge(4, 5);
//	merge(5, 6);
//	cout << "2와 4는 같은 집합인가?\n" << isUnion(2, 4) << "\n"; // false
//	merge(1, 5);
//	cout << "2와 4는 같은 집합인가?\n" << isUnion(2, 4) << "\n"; // true
//	return 0;
//}


#define MAX 100001

typedef struct info
{
	int x1, x2, num;
};

int n, q, p[MAX];
vector<info> v;

bool cmp(const info& a, const info& b)
{
	return a.x1 < b.x1;
}

int Find(int x)
{
	if (x == p[x])
	{
		return x;
	}
	return p[x] = Find(p[x]);
}

void Union(int a, int b)
{
	a = Find(a);
	b = Find(b);

	if (a < b)
	{
		p[b] = a;
	}
	else
	{
		p[a] = b;
	}
}


int main(void)
{

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> q;

	int x1, x2, y;

	for (int i = 1; i <= n; i++)
	{
		cin >> x1 >> x2 >> y;
		v.push_back({ x1,x2,i });
		p[i] = i;
	}

	sort(v.begin(), v.end(), cmp);

	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (v[j].x1 <= v[i].x2)
			{
				Union(v[i].num, v[j].num);
			}
			else
			{
				break;
			}
		}
	}

	int f, t;
	for (int i = 0; i < q; i++)
	{
		cin >> f >> t;
		if (Find(f) == Find(t))
		{
			cout << "1" << "\n";
		}
		else
		{
			cout << "0" << "\n";
		}

	}

	return 0;

}
