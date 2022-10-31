//커다란 공연장을 빌려서 록 페스티벌을 개최하려고 합니다.이 페스티벌은 여러 날 동안 진행되며, 하루에 한 팀의 밴드가 공연장에서 콘서트를 하게 됩니다.전체 밴드를 몇 팀 섭외할 지는 아직 결정하지 않았지만, 페스티벌의 간판 스타인 L개의 팀은 이미 섭외가 끝난 상태입니다.따라서 페스티벌은 최소 L일 이상 진행하게 됩니다.
//
//이번에 사용할 공연장은 하루 빌리는 데 드는 비용이 매일 매일 다릅니다.때문에 공연 일정을 잘 정해서 공연장 대여 비용을 줄이려고 합니다.앞으로 N일간의 공연장 대여 비용을 알고 있다고 합시다.이 중 L일 이상을 연속해서 대여하되, 공연장을 하루 빌리는 데 드는 평균 비용을 최소화하려면 어떻게 공연장을 빌려야 할까요 ?
//
//예를 들어 앞으로 6일간 공연장을 빌리는 데 드는 비용이 각{ 3, 1, 2, 3, 1, 2 }라고 합시다.이미 세 팀을 섭외했다고 하면, 3일 대신 4일 동안 공연을 진행해서 평균 비용을 더 저렴하게 할 수 있습니다. 3일 동안의 평균 대여 비용을 최소화하는 방법은 2일째부터 4일째까지 공연장을 대여하는 것인데, 이 때 하루 평균(1 + 2 + 3) / 3 = 2의 비용이 듭니다.반면 2일째부터 5일째까지 공연장을 대여하면 평균 비용이(1 + 2 + 3 + 1) / 4 = 7 / 4밖에 되지 않습니다.
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

//풀이 구간합을 이용해 1씩증가하면서 최소값을 찾는다

int sum[1001];

int main(void)
{

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int c;
	cin >> c;

	while (c--)
	{
		int n, l;

		memset(sum, 0, sizeof(sum));
		cin >> n >> l;

		for (int i = 0; i < n; i++)
		{
			int number;
			cin >> number;
			sum[i + 1] = sum[i] + number;
		}
		double answer = INT_MAX;

		for (int width = l; width <= n; width++)
		{
			for (int i = 0; i < n - width + 1; i++)
			{
				answer = min(answer, (sum[i + width] - sum[i]) / (double)width);
			}
		}


		cout << fixed;
		cout.precision(8);
		cout << answer << "\n";

	}


	return 0;

}