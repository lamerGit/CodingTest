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

//와일드카드는 다양한 운영체제에서 파일 이름의 일부만으로 파일 이름을 지정하는 방법이다.와일드카드 문자열은 일반적인 파일명과 같지만, * 나 ? 와 같은 특수 문자를 포함한다.
//
//와일드카드 문자열을 앞에서 한 글자씩 파일명과 비교해서, 모든 글자가 일치했을 때 해당 와일드카드 문자열이 파일명과 매치된다고 하자.단, 와일드카드 문자열에 포함된 ? 는 어떤 글자와 비교해도 일치한다고 가정하며, * 는 0 글자 이상의 어떤 문자열에도 일치한다고 본다.
//
//예를 들어 와일드 카드 he ? p 는 파일명 help 에도, heap 에도 매치되지만, helpp 에는 매치되지 않는다.와일드 카드* p* 는 파일명 help 에도, papa 에도 매치되지만, hello 에는 매치되지 않는다.
//
//와일드카드 문자열과 함께 파일명의 집합이 주어질 때, 그 중 매치되는 파일명들을 찾아내는 프로그램을 작성하시오.


//-1은 아직 답이 계산되지 않았음을 의미
// 1은 해당 입력들이 서로 대응됨
// 0은 해당 입력들이 서로 대응되지 않음


int cache[101][101];
//패턴과 문자열

string W, S;
// 와일드카드 패턴W[w..]가 문자열 S[s..]에 대응되는지 여부를 반환

bool matchMemoized(int w, int s)
{
	//메모이제이션
	if (cache[w][s] != -1) return cache[w][s];

	//W[w]와 S[s]를 맞춰나간다.
	while (s < S.size() && w < W.size() && (W[w] == '?' || W[w] == S[s]))
	{

		return cache[w][s] = matchMemoized(w + 1, s + 1);
	}
	//패턴 끝에 도달해서 끝난 경우 : 문자열도 끝났어야 참
	if (w == W.size())
	{
		return cache[w][s] = (s == S.size());
	}
	// *를 만나서 끝난 경우 : *에 몇 글자를 대응해야 할지 재귀 호출하면서 확인
	if (W[w] == '*')
	{

		if (matchMemoized(w + 1, s) || (s < S.size() && matchMemoized(w, s + 1)))
		{
			return cache[w][s] = 1;
		}


	}

	return cache[w][s] = 0;
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
		cin >> W;
		cin >> n;
		vector<string> s(n);
		vector<string> ans;

		for (int i = 0; i < n; i++)
		{
			cin >> s[i];
		}

		for (int i = 0; i < n; i++)
		{
			memset(cache, -1, sizeof(cache));
			S = s[i];
			if (matchMemoized(0, 0) == 1)
			{
				ans.push_back(S);
			}
		}

		sort(ans.begin(), ans.end());
		for (int i = 0; i < ans.size(); i++)
		{
			cout << ans[i] << "\n";
		}

	}


	return 0;
}