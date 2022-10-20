#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>

// 구간합 구하기
//수 N개가 주어졌을 때, i번째 수부터 j번째 수까지 합을 구하는 프로그램을 작성하시오.
//
//반복문을 사용하여 i~k사이의 값을 더하는 알고리즘의 시간복잡도는 O(n)이다.
//이 같은 알고리즘을 사용할 경우 n의 값이 클 경우 이를 정해진 시간 내에 해결할 수 없다.
//하지만 구간 합 알고리즘을 사용하여 구간합을 구하는 경우 O(1)의 성능을 갖는다.
//구간 합 알고리즘은 현재 진행단계까지의 인덱스까지 값의 합을 저장하는 sum[]배열을 사용한다.
//j번째 바로 앞까지의 총합에 arr[j] 값을 더하면 j번째까지의 총합을 의미하므로 sum[j] = sum[j - 1] + arr[j] 로 표현할 수 있다.
using namespace std;

int sum[100000];

int main(void)
{

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;


	for (int i = 0; i < n; i++)
	{
		int number;
		cin >> number;
		sum[i + 1] = sum[i] + number;


	}

	while (m--)
	{
		int i, j;
		cin >> i >> j;
		cout << sum[j] - sum[i - 1] << "\n";  // index가 1부터 시작하는 컨셉이라 -1를 해준다
	}




	return 0;

}
