#include <iostream>
#include <vector>
#include <cstring>
#include <sstream>
#include <string>
#include <map>
#include <stack>
#include <math.h>
#include <queue>

using namespace std;


//회문찾기
//회문은 0
//1글자 빼서 회문이면 1
//그외것들 2
int main(void)

{

	ios_base::sync_with_stdio(0);

	cin.tie(0);

	int t;
	cin >> t;


	while (t--)
	{
		string s;
		cin >> s;

		string temp = s;
		bool check = false;
		int index = 0;
		for (int i = 0; i < s.length() / 2; i++)
		{
			if (s[i] != s[s.length() - i - 1])
			{
				check = true;  //대칭이 아니면 해당 인덱스 저장하고 체크후 break
				index = i; 
				break;
			}
		}
		if (!check)
		{
			cout << "0\n"; //체크가 안되면 회문
		}
		else
		{
			check = false;
			bool leftCheck = false;
			bool rightCheck = false;
			int rightIndex = s.length() - index - 1;  // 해당 인덱스의 반대편 인덱스 위치 저장
			s.erase(index, 1);  // 대칭이 아닌 요소 지우기
			temp.erase(rightIndex, 1);

			for (int i = 0; i < s.length() / 2; i++) // 검사
			{
				if (temp[i] != temp[temp.length() - i - 1])
				{
					rightCheck = true;
				}
				if (s[i] != s[s.length() - i - 1])
				{
					leftCheck = true;
				}
			}

			if (leftCheck && rightCheck)
			{
				check = true;
			}

			if (!check)
			{
				cout << "1\n"; //체크 표시가 안 되어 있다면 유사회문
			}
			else
			{
				cout << "2\n"; // 그외
			}



		}



	}



	return 0;

}