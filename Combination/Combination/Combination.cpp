#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>
#include <map>
#include <limits>
#include <string>
#include <set>
#include <queue>

using namespace std;

vector<vector<string>> dp(101, vector<string>(101, "-1"));

string bigNumAdd(string num1, string num2)  //두개의 문자열로된 숫자 더한것을 문자열로 바꿔주는 함수
{
	long long sum = 0;
	string result;

	while (!num1.empty() || !num2.empty() || sum)
	{
		if (!num1.empty())
		{
			sum += num1.back() - '0';
			num1.pop_back();
		}
		if (!num2.empty())
		{
			sum += num2.back() - '0';
			num2.pop_back();
		}

		result.push_back((sum % 10) + '0');
		sum /= 10;

	}
	reverse(result.begin(), result.end());
	return result;

}




string com(int n, int r) // 조합
{
	if (n == r || r == 0) return "1";
	if (dp[n][r] != "-1") return dp[n][r];
	dp[n][r] = bigNumAdd(com(n - 1, r - 1), com(n - 1, r));
	return dp[n][r];

}

int main(void)
{

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int a, b;
	cin >> a >> b;

	cout << com(a, b);

	return 0;

}