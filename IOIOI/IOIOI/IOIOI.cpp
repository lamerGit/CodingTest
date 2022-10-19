
#include <iostream>
#include <string>

using namespace std;
//
//N + 1개의 I와 N개의 O로 이루어져 있으면, I와 O이 교대로 나오는 문자열을 PN이라고 한다.
//
//P1 IOI
//P2 IOIOI
//P3 IOIOIOI
//PN IOIOI...OI(O가 N개)
//I와 O로만 이루어진 문자열 S와 정수 N이 주어졌을 때, S안에 PN이 몇 군데 포함되어 있는지 구하는 프로그램을 작성하시오.


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    int len;
    string s;
    cin >> n;
    cin >> len;
    cin >> s;

    int ans = 0;

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i + 1] == 'O' && s[i + 2] == 'I') // 현재 인덱스 +1='O', +2='I'일때 시작
        {
            int oh = 0;
            while (s[i] == 'I' && s[i + 1] == 'O') // i가 I이고 i+1이 O이면
            {
                i += 2;  //i+2를 하면서 인덱스를 올린다.
                oh++;    //O의 갯수도 카운터
                if (s[i] == 'I' && oh == n)  // IOI가 성립하고 oh가 n과 같다면
                {
                    oh--;  //이전 O는 확인 안해도 된다는듯
                    ans++;
                }
            }


        }
    }

    cout << ans;
}

