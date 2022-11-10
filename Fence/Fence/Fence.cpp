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

//알고스팟 울타리 잘라내기

//너비가 같은 N개의 나무 판자를 붙여 세운 울타리가 있습니다.
//시간이 지남에 따라 판자들이 부러지거나 망가져 높이가 다 달라진 관계로 울타리를 통째로 교체하기로 했습니다.
//이 때 버리는 울타리의 일부를 직사각형으로 잘라내 재활용하고 싶습니다.그림(b)는(a)의 울타리에서 잘라낼 수 있는 많은 직사각형 중 가장 넓은 직사각형을 보여줍니다.울타리를 구성하는 각 판자의 높이가 주어질 때, 
// 잘라낼 수 있는 직사각형의 최대 크기를 계산하는 프로그램을 작성하세요.단(c)처럼 직사각형을 비스듬히 잘라낼 수는 없습니다.
//
//판자의 너비는 모두 1이라고 가정합니다.

//중간부터 오른쪽 왼쪽 번갈아 가면서 확장한다.

//각 판자의 높이를 저장하는 배열
vector<int> h;

//h[left...right]구간에서 찾아낼 수 있는 가장 큰 사각형의 넓이를 반환
int solve(int left, int right)
{
	// 판자가 하나밖에 없는 경우
	if (left == right) return h[left];
	//[left,mid], [mid+1,right]의 두 구간으로 문제를 분할
	int mid = (left + right) / 2;
	//분할한 문제를 각개격파
	int ret = max(solve(left, mid), solve(mid + 1, right));

	//두 부분에 모두 걸치는 사각형 중 가장 큰 것을 찾는다.
	int lo = mid, hi = mid + 1;
	int height = min(h[lo], h[hi]);

	//[mid,mid+1]만 포함하는 너비 2인 사각형을 고려
	ret = max(ret, height * 2);

	//사각형이 입력 전체를 덮을 때까지 확장
	while (left < lo || hi < right)
	{
		if (hi < right && (lo == left || h[lo - 1] < h[hi + 1]))
		{
			hi++;
			height = min(height, h[hi]);
		}
		else {
			lo--;
			height = min(height, h[lo]);
		}
		ret = max(ret, height * (hi - lo + 1));
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
		int n;
		cin >> n;
		h.clear();
		for (int i = 0; i < n; i++)
		{
			int number;
			cin >> number;
			h.push_back(number);
		}

		cout << solve(0, n - 1) << "\n";

	}


	return 0;
}