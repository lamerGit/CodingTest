#include <string>
#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;
//
//선영이는 주말에 할 일이 없어서 새로운 언어 AC를 만들었다.AC는 정수 배열에 연산을 하기 위해 만든 언어이다.이 언어에는 두 가지 함수 R(뒤집기)과 D(버리기)가 있다.
//
//함수 R은 배열에 있는 수의 순서를 뒤집는 함수이고, D는 첫 번째 수를 버리는 함수이다.배열이 비어있는데 D를 사용한 경우에는 에러가 발생한다.
//
//함수는 조합해서 한 번에 사용할 수 있다.예를 들어, "AB"는 A를 수행한 다음에 바로 이어서 B를 수행하는 함수이다.예를 들어, "RDD"는 배열을 뒤집은 다음 처음 두 수를 버리는 함수이다.
//
//배열의 초기값과 수행할 함수가 주어졌을 때, 최종 결과를 구하는 프로그램을 작성하시오.

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;

    while (t--)
    {
        string command; // 명령어 R은 뒤집기 D는 첫번쨰 수 버리기
        cin >> command;

        int n;
        cin >> n;

        string arr;  // 배열 입력받기
        cin >> arr;

        deque<int> dq; //  string에 입력받은 배열을 숫자로 변화에 dq에 넣는다

        string temp; // 배열 값이 2자리수 이상일때 처리할 변수

        for (int i = 0; i < arr.length(); i++)  // [1,2,3,4,5] 이런식으로 입력받은 string 변수을 for문으로 돌림
        {
            if (arr[i] == '[')
            {
                continue;
            }
            else if ('0' <= arr[i] && arr[i] <= '9')  // 숫자일 경우 temp에 넣음
            {
                temp += arr[i];
            }
            else if (arr[i] == ',' || arr[i] == ']') //,나 ]가 나올경우 temp가 비어있지 않았으면 dq에 숫자로 변환후 넣는다 temp는 초기화
            {
                if (!temp.empty())
                {
                    dq.push_back(stoi(temp));
                    temp.clear();
                }
            }
        }

        bool isError = false;  //비어있으면 error를 출력해야하기 때문에 그걸 체크할 변수
        bool isReverse = false; // 뒤집혀있는지 확인할 변수

        for (int i = 0; i < command.length(); i++)
        {
            if (command[i] == 'R')  // R이면 뒤집힘 표시
            {
                isReverse = !isReverse;
            }
            else    //D일 경우
            {
                if (dq.empty()) // 비어있으면 error
                {
                    isError = true;
                    cout << "error\n";
                    break;
                }
                else  //아니면 isReverse에 상태에 따라 앞에 원소를 뺄지 뒤에 원소를 뺄지 정한다.
                {
                    if (!isReverse)
                    {
                        dq.pop_front();
                    }
                    else
                    {
                        dq.pop_back();
                    }
                }
            }
        }

        if (!isError) // error가 안났으면 명령이 수행된 배열을 출력한다.
        {
            if (!isReverse)  // 뒤집혀있지 않으면 front부터 쭉 출력
            {
                cout << "[";
                while (!dq.empty())
                {
                    cout << dq.front();
                    dq.pop_front();
                    if (!dq.empty())
                    {
                        cout << ",";
                    }

                }

                cout << "]\n";
            }
            else // 뒤집혀있으면 pop부터 쭉 출력
            {
                cout << "[";
                while (!dq.empty())
                {
                    cout << dq.back();
                    dq.pop_back();
                    if (!dq.empty())
                    {
                        cout << ",";
                    }
                }

                cout << "]\n";
            }
        }
        

    }

}

