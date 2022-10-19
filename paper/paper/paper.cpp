#include <iostream>
#include <vector>
#include <cstring>
#include <sstream>
#include <string>
#include <map>
#include <stack>
#include <math.h>
#include <queue>
#include <unordered_map>

using namespace std;

//N×N크기의 행렬로 표현되는 종이가 있다.종이의 각 칸에는 - 1, 0, 1 중 하나가 저장되어 있다.우리는 이 행렬을 다음과 같은 규칙에 따라 적절한 크기로 자르려고 한다.
//
//만약 종이가 모두 같은 수로 되어 있다면 이 종이를 그대로 사용한다.
//(1)이 아닌 경우에는 종이를 같은 크기의 종이 9개로 자르고, 각각의 잘린 종이에 대해서(1)의 과정을 반복한다.
//이와 같이 종이를 잘랐을 때, -1로만 채워진 종이의 개수, 0으로만 채워진 종이의 개수, 1로만 채워진 종이의 개수를 구해내는 프로그램을 작성하시오.

int ans[3];
int arr[2188][2188];

void paper(int x, int y, int n)
{
	int number = arr[x][y]; // 배열 최초의 번호
	bool flag = true;
	for (int i = x; i < x + n; i++)
	{
		for (int j = y; j < y + n; j++)
		{
			if (arr[i][j] != number)  // for문 돌면서 number와 같지 않다면 flag = false로 하고 break;
			{
				flag = false;
				break;
			}
		}
	}

	if (flag) // flag가 true라면 number가 -1 ,0 ,1 이라서 +1을 해준 배열에 넣어준다.
	{
		ans[number + 1]++;
	}
	else  // flag가 false 라면  +3씩 이동하면서 재귀
	{
		for (int i = x; i < x + n; i += n / 3)
		{
			for (int j = y; j < y + n; j += n / 3)
			{
				paper(i, j, n / 3);
			}
		}
	}

}


int main(void)

{

	ios_base::sync_with_stdio(0);

	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> arr[i][j];
		}
	}

	paper(0, 0, n);
	for (int i = 0; i < 3; i++)
	{
		cout << ans[i] << "\n";
	}



	return 0;

}
