#include <string>
#include <vector>
#include <sstream>
#include <cmath>

using namespace std;

//K 진수에서 소수 개수 구하기

//n을 k진수로 변환후 그중에서 소수가 몇개인지 구하는 문제

// 예) n = 437674, k = 3일때 211020101011로 변하고 0을 제외하고 211 2 11 나온다. 


bool check(long long num)
{
    if (num == 2) return true;
    if (num == 1 || num % 2 == 0) return false;

    for (long long i = 3; i <= (long long)sqrt(num); i += 2)
    {
        if (num % i == 0) return false;
    }

    return true;
}


string convert(int num, int base)
{
    int q = num / base, r = num % base;
    if (q)
        return convert(q, base) + to_string(r);
    else
        return to_string(r);
}

int solution(int n, int k) {
    string number = k == 10 ? to_string(n) : convert(n, k);
    stringstream ss(number);


    int answer = 0;
    string value;
    while (getline(ss, value, '0')) // 0이 나오기 전까지의 문자열을 value에 넣는다
    {
        int s = value.size();
        if (s && check(stol(value)))
            answer++;
    }



    return answer;
}