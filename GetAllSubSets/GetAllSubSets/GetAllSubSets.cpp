#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <string>
#include <ctime>

using namespace std;

//모든 부분집합 구하기

void GetAllSubsets(vector<int> set, vector<int> subset, int index, vector<vector<vector<int>>>& allSubsets)
{
	//집합 set의 끝에 다다른 경우
	if (index == set.size())
	{
		//부분 집합 크기를 인덱스로 사용하여 부분집합을 allSubsets에 추가
		allSubsets[subset.size()].push_back(subset);
		return;
	}

	//원소를 추가하지 않고 재귀 호출
	GetAllSubsets(set, subset, index + 1, allSubsets);

	//원소를 부분집합에 추가한 후 재귀 호출
	subset.push_back(set[index]);
	GetAllSubsets(set, subset, index + 1, allSubsets);
}


int main(void)
{

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	vector<int> set = { 1,2,3,4,5,6 };
	vector<vector<vector<int>>> allSubSets(set.size() + 1);

	GetAllSubsets(set, {}, 0, allSubSets);

	for (int size = 0; size <= set.size(); size++)
	{
		//size는 부분집합의 원소 개수를 나타냄

		for (auto subset : allSubSets[size])
		{
			int sum = 0; // 부분집합 원소의 합
			cout << "[ ";
			for (auto number : subset)
			{
				sum += number; // number은 부분집합 원소
				cout << number << " ";
			}
			cout << "]\n";
		}

	}


	return 0;

}
