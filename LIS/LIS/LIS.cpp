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

// 알고스팟 LIS

//어떤 정수 수열에서 0개 이상의 숫자를 지우면 이 수열의 부분 수열(subsequence) 를 얻을 수 있다.예를 들어 10 7 4 9 의 부분 수열에는 7 4 9, 10 4, 10 9 등이 있다.단, 10 4 7 은 원래 수열의 순서와 다르므로 10 7 4 9 의 부분 수열이 아니다.
//
//어떤 부분 수열이 순증가할 때 이 부분 수열을 증가 부분 수열(increasing subsequence) 라고 한다.주어진 수열의 증가 부분 수열 중 가장 긴 것의 길이를 계산하는 프로그램을 작성하라.
//
//어떤 수열의 각 수가 이전의 수보다 클 때, 이 수열을 순증가 한다고 한다.

int idx; //최대 부분 수열의 길이
int length; // 수열 길이
int arr[501]; // 원래 주어진 수열
int cache[501]; // 메모제이션


void lis(int num)
{
	//해당 숫자가 더 크거나 배열이 비어있다면
	if (idx == 0 || (idx > 0 && cache[idx - 1] <= num))
	{
		cache[idx++] = num;
		return;
	}
	//증가 부분 수열에 성립하지 않은 숫자라면 삽입할 위치를 찾는다.
	int front = 0;
	int rear = idx - 1;

	//이진탐색
	while (front <= rear)
	{
		int mid = (front + rear) / 2;

		if (cache[mid] < num)
		{
			front = mid + 1;
		}
		else
		{
			rear = mid - 1;
		}
	}
	cache[rear + 1] = num;
}

int main(void)
{

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int c;
	cin >> c;

	while (c--)
	{
		idx = 0; //최대부분 수열 길이 초기화
		cin >> length;

		for (int i = 0; i < length; i++)
		{
			cin >> arr[i];
		}

		for (int i = 0; i < length; i++)
		{
			lis(arr[i]);
		}

		cout << idx << "\n";

	}


	return 0;
}