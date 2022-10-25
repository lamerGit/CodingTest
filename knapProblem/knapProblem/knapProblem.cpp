#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

int knapsack_01(int items, int capacity, vector<int> values, vector<int> weight)
{
	vector<vector<int>> dp(items + 1, vector<int>(capacity + 1, 0));

	for (int i = 1; i <= items; i++)
	{
		int currentWeight = weight[i - 1];
		int currentValue = values[i - 1];

		for (int totalWeight = 1; totalWeight <= capacity; totalWeight++)
		{
			if (totalWeight < currentWeight)
			{
				dp[i][totalWeight] = dp[i - 1][totalWeight];
			}
			else
			{
				dp[i][totalWeight] = max(dp[i - 1][totalWeight], dp[i - 1][totalWeight - currentWeight] + currentValue);
			}

		}


	}

	return dp[items][capacity];
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, k;
	vector<int> weight, value;
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		int w, v;
		cin >> w >> v;
		weight.push_back(w);
		value.push_back(v);
	}

	cout << knapsack_01(n, k, value, weight);


}