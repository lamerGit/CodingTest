#include <string>
#include <vector>
#include <unordered_map>
#include <map>
#include <cmath>

using namespace std;

//주차요금 계산

//프로그래머스 2022 카카오 블라인드 주차 요금 계산 문제

int convert(string time) // 시간을 int로 바꿔주는 함수
{
    string hh = time.substr(0, 2);
    string mm = time.substr(3);
    return stoi(hh) * 60 + stoi(mm);
}

vector<int> solution(vector<int> fees, vector<string> records) {
    unordered_map<string, int> intime; //들어온 시간을 기록할 map
    map<string, int> result; //최종 계산에 쓸 map

    for (string r : records) {
        string time = r.substr(0, 5);
        string num = r.substr(6, 4);
        string inout = r.substr(11);
        if (inout == "IN")
        {
            intime[num] = convert(time); //들어올경우
        }
        else
        {
            result[num] += convert(time) - intime[num]; //나갈경우 result에 나간시간 - 들어온시간
            intime.erase(num); // 나갔으니 들어온 시간을 제거
        }
    }


    for (auto item : intime) // 하루가 지나도 나가지 않을 차들은 23 : 59 - 들어온 시간 해서 최종 계산용 map에 넣는다.
    {
        result[item.first] += 23 * 60 + 59 - item.second;
    }

    vector<int> answer;
    for (auto item : result)
    {
        if (item.second <= fees[0]) //기본 시간보다 작거나 같으면 그냥 넣기
        {
            answer.push_back(fees[1]);
        }
        else
        {   //기본 시간보다 많으면 기본요금 + (소수점 제거)((시간-기본시간) / 단위시간)) *단위 요금을 해준다
            answer.push_back(fees[1] + ceil((item.second - fees[0]) / (float)fees[2]) * fees[3]);
        }
    }



    return answer;
}