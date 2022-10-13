#include <iostream>
#include <vector>
#include <cstring>
#include <sstream>
#include <string>
#include <map>
#include <stack>

using namespace std;

//입력
//4 3
//< tag1 value = "HelloWorld" >
//<tag2 name = "Name1">
//< / tag2>
//< / tag1>
//tag1.tag2~name
//tag1~name
//tag1~value
//
//출력
//Name1
//Not Found!
//HelloWorld

//태그처리 문제
// map에 key = tag1~value , value = HelloWorld 이런식으로 넣어서 해결해야한다.

int main(void)

{

	ios_base::sync_with_stdio(0);

	cin.tie(0);

	int n, q;
	cin >> n >> q;
	string temp;
	vector<string> hrml;
	vector<string> quer;
	cin.ignore();
	for (int i = 0; i < n; i++)
	{
		getline(cin, temp);
		hrml.push_back(temp);
	}

	for (int i = 0; i < q; i++)
	{
		getline(cin, temp);
		quer.push_back(temp);

	}

	map<string, string> m;
	stack<string> s;


	for (int i = 0; i < n; i++)
	{
		temp = hrml[i];
		temp.erase(remove(temp.begin(), temp.end(), '\"'), temp.end()); // 문자열에서 ""전부 제거
		temp.erase(remove(temp.begin(), temp.end(), '>'), temp.end()); // 문자열에서 >전부 제거
		if (temp.substr(0, 2) == "</") //</으로 시작하는 문자일경우
		{
			//tag.pop_back(); // tag vector에서 원소빼기
			s.pop();
		}
		else
		{
			stringstream ss;
			//ss.str("");
			ss << temp;   // ss temp문자 넣기
			string t1, p1, v1;
			char ch;
			ss >> ch >> t1 >> p1 >> ch >> v1;  //ch는 버리는 값 t1에는 태그 p1에는 value,name등 v1에는 값
			string temp1 = "";
			if (!s.empty()) // tag가 비어있지 않다면
			{
				//temp1 = tag[tag.size() - 1]; //  맨뒤에 값 할당
				//temp1 = temp1 + "." + t1;   // tag1.tag2 이런 형식만들어주기

				temp1 = s.top();
				temp1 = temp1 + "." + t1;

			}
			else //tag가 비어있다면
			{
				temp1 = t1; //temp1에 태그 넣어주기
			}
			//tag.push_back(temp1); //tag에 temp1할당
			s.push(temp1);

			m[s.top() + "~" + p1] = v1; // key : tag1~value, value : p1 할당
			while (ss) // 더 남아 있는 값이 있을 경우 map에 할당한다.
			{
				ss >> p1 >> ch >> v1;
				m[s.top() + "~" + p1] = v1;
			}

		}


	}
	for (int i = 0; i < q; i++)
	{
		if (m.find(quer[i]) == m.end())
		{
			cout << "Not Found!\n";
		}
		else
		{
			cout << m[quer[i]] << "\n";
		}
	}






	return 0;

}