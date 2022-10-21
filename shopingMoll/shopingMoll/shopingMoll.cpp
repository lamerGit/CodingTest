#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;

//대형 쇼핑몰에서 쇼핑을 마친 N명의 고객들이 계산을 하고 쇼핑몰을 떠나고자 계산대 앞에 줄을 서 있다.각 고객은 커다란 짐수레(cart)에 물건을 담아 계산대로 간다.쇼핑몰에는 아래 그림과 같이 K개의 계산대가 병렬로 배치되어 있다.쇼핑몰 안내원들은 계산대에 온 사람들을 가장 빨리 계산을 마칠 수 있는 계산대로 안내를 한다.안내원은 각 계산대에서 기다리고 있는 사람들이 계산을 하는데 얼마나 걸리는지 이미 알고 있다.
//
//
//
//안내원이 고객을 계산대로 안내할 때 두 계산대에서 기다려야 할 시간이 같을 경우에는 가장 번호가 작은 계산대로 안내를 한다.즉 3번, 5번 계산대에서 기다릴 시간이 똑같이 15분으로 최소일 경우에는 3번으로 안내를 한다.
//
//계산을 마친 고객은 출구를 통하여 쇼핑몰을 완전히 빠져 나간다.만일 계산대에서 계산을 마친 고객의 시간이 동일하다면 출구에 가까운 높은 번호 계산대의 고객부터 먼저 빠져나간다.예를 들어 두 계산대 4번과 10번에서 두 고객이 동시에 계산을 마쳤다면 계산대의 번호가 더 높은 10번 계산대의 고객이 먼저 쇼핑몰을 나간다.물건을 계산하는 데에는 종류에 관계없이 동일하게 1분이 소요된다.즉, 물건이 w개 있는 손님이 계산을 마치는 데에는 정확히 w분이 소요된다.
//
//여러분은 계산대로 들어가기 위하여 줄을 서 있는 고객 N명의 정보(회원번호, 구매한 물건의 수)를 알고 있을 때, 이들이 계산을 하고 쇼핑몰을 빠져나오는 순서를 구해야 한다.계산대로 들어가고 계산대에서 나오는데 걸리는 시간은 없다고 가정한다.


//-Cmp 비교함수를 통해 우선순위큐의 정렬 방법을 정리한다
//
//- Counter의 수만큼 enterCounter 우선순위큐에 미리 삽입한다(id는 0으로 설정.이유는 하단에..)
//
//- id와 물건의 수 w를 입력받고, enterCounter의 top에 있는 원소를 Pop하고 현재 들어갈 고객에 대한 정보를 삽입한다 - 이때, 고객의 id를 나타내는 id가 0이 아니라면 goExit 우선순위큐에 삽입한다(나가는 순서)
//
//- goExit 우선순위큐에서 삽입할 때에는 tmp.cidx의 값을 음수로 바꿔서 삽입한다(카운터 번호가 높을수록 먼저 나간다)
//
//- num만큼 입력을 정보를 입력 받은 후, enterCounter에 고객에 대한 정보가 남아있을 수 있으니, enterCounter 우선순위큐에 남은 원소를 위의 조건과 동일하게 처리한다
//
//- goExit 우선순위큐에서 1개씩 뽑으면서 Id * 나가는 순번을 Answer에 저장한다.이때, Int형을 벗어날 수 있으니 Long Long으로 설정한다

struct info {
	long long id;
	int cidx, val;
};

struct cmp
{
	bool operator()(info& a, info& b)
	{
		if (a.val == b.val)
		{
			return a.cidx > b.cidx;
		}
		return a.val > b.val;
	}


};

info tmp;
int num, k, w;
long long id;


int main(void)
{

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> num >> k;
	priority_queue<info, vector<info>, cmp>enterCounter, goExit;
	long long answer = 0;
	for (int i = 0; i < k; i++)
	{
		enterCounter.push({ 0,i,0 });
	}
	for (int i = 0; i < num; i++)
	{
		cin >> id >> w;
		tmp = enterCounter.top();
		enterCounter.pop();
		enterCounter.push({ id,tmp.cidx,tmp.val + w });
		if (tmp.id > 0)
		{
			goExit.push({ tmp.id,-tmp.cidx,tmp.val });

		}



	}
	while (!enterCounter.empty())
	{
		tmp = enterCounter.top();
		enterCounter.pop();
		if (tmp.id > 0)
		{
			goExit.push({ tmp.id,-tmp.cidx,tmp.val });
		}
	}
	int cnt = 1;
	while (!goExit.empty())
	{
		long long vv = goExit.top().id;
		goExit.pop();
		answer += (vv * cnt);
		cnt++;
	}

	cout << answer;




	return 0;

}
