#include <iostream>
#include <vector>
#include <cstring>

using namespace std;


//무식하게 2*2*n 채우기
//무식하게 n=6 까지만 찾고 인터넷에 수열검색하면 답이나온다

int n;
vector<int> ChangeNumber(int n)
{
	vector<int> temp(3);
	int a = 0, b = 0, c = 0;

	for (int i = 0; i < n; i++)
	{
		b++;
		if (b % 2 == 0)
		{
			b = 0;
			a++;

			if (a % 2 == 0)
			{
				a = 0;
				c++;
			}


		}
	}

	temp[0] = a;
	temp[1] = b;
	temp[2] = c;

	return temp;

}

bool check(vector<vector<vector<int>>> v)
{

	for (int i = 0; i < v.size(); i++)
	{
		for (int j = 0; j < v[i].size(); j++)
		{
			for (int z = 0; z < v[i][j].size(); z++)
			{
				if (v[i][j][z] != 1)
				{
					return false;
				}
			}
		}
	}
	return true;
}

int ans = 0;

bool checkHegith(vector<vector<vector<int>>> map, vector<int> index)
{
	if (index[0] < 2 - 1 && index[1] < 2 && index[2] < n)
	{
		if (map[index[0]][index[1]][index[2]] == 1)
		{
			return false;
		}
		if (map[index[0] + 1][index[1]][index[2]] == 1)
		{
			return false;
		}

		return true;
	}
	else
	{
		return false;
	}

}

bool checkwidth(vector<vector<vector<int>>> map, vector<int> index)
{
	if (index[0] < 2 && index[1] < 2 - 1 && index[2] < n)
	{
		if (map[index[0]][index[1]][index[2]] == 1)
		{
			return false;
		}
		if (map[index[0]][index[1] + 1][index[2]] == 1)
		{
			return false;
		}

		return true;
	}
	else
	{
		return false;
	}

}

bool checkup(vector<vector<vector<int>>> map, vector<int> index)
{
	if (index[0] < 2 && index[1] < 2 && index[2] < n - 1)
	{
		if (map[index[0]][index[1]][index[2]] == 1)
		{
			return false;
		}
		if (map[index[0]][index[1]][index[2] + 1] == 1)
		{
			return false;
		}

		return true;
	}
	else
	{
		return false;
	}

}

void dfs(int index, vector<vector<vector<int>>> map)
{
	if (check(map))
	{
		ans++;
		return;
	}

	vector<int> ijz = ChangeNumber(index);

	if (ijz[0] < 2 && ijz[1] < 2 && ijz[2] < n)
	{
		if (checkwidth(map, ijz))
		{
			vector < vector<vector<int>>> temp = map;


			temp[ijz[0]][ijz[1]][ijz[2]] = 1;
			temp[ijz[0]][ijz[1] + 1][ijz[2]] = 1;

			dfs(index + 1, temp);

		}

		if (checkHegith(map, ijz))
		{
			vector < vector<vector<int>>> temp = map;

			temp[ijz[0]][ijz[1]][ijz[2]] = 1;
			temp[ijz[0] + 1][ijz[1]][ijz[2]] = 1;

			dfs(index + 1, temp);
		}

		if (checkup(map, ijz))
		{
			vector<vector<vector<int>>> temp = map;

			temp[ijz[0]][ijz[1]][ijz[2]] = 1;
			temp[ijz[0]][ijz[1]][ijz[2] + 1] = 1;

			dfs(index + 1, temp);
		}


		dfs(index + 1, map);

	}


}


int main(void)

{

	ios_base::sync_with_stdio(0);

	cin.tie(0);


	cin >> n;

	vector<vector<vector<int>>> test(2, vector<vector<int>>(2, vector<int>(n, 0)));

	dfs(0, test);

	cout << ans;

	return 0;

}