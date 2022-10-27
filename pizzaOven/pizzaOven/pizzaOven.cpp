#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <string>
#include <ctime>
#include <map>
#include <queue>

using namespace std;


//피자를 굽는 전자식 오븐이 있다.이 오븐에 재료는 넣고 정확히 $N$분 동안 동작을 시키고자 한다.그런데 이 오븐에 준비된 버튼은 아래와 같은 동작을 하는 5가지이다.즉, 각각의 버튼은 동작 시간을 추가시키거나 감소시킨다.처음에 피자 오븐의 첫 시간은 0분으로 정해져 있다.시간을 감소시키는 버튼을 눌러서 시간이 0분보다 작아지는 경우에는 0분으로 설정된다.$t$가 현재 오븐에 세팅된 시간, $t'$은 버튼을 누른 뒤의 시간을 의미할 때, 각 버튼은 다음과 같은 기능을 가지고 있다.
//
//ADDH: $t' = t + 60$ 
//ADDT : $t' = t + 10$ 
//MINT : $t' = t - 10$ 
//ADDO : $t' = t + 1$ 
//MINO : $t' = t - 1$ 
//예를 들어, 58분을 설정하고 싶으면, ADDO(+1분) 버튼을 58번 눌러도 된다.하지만, ADDH(+60분) 버튼을 한 번 누른 뒤에 MINO(-1분) 버튼을 2번 누르면 3번의 작업으로 58분을 만들 수 있다. 42분을 설정하고 싶은 경우에는 버튼을 ADDH, MINT, MINT, ADDO, ADDO 순서로 5번 눌러서 만들 수 있다.ADDT, ADDT, ADDT, ADDT, ADDO, ADDO 순서로 6번 눌러서 만들 수 있지만, 버튼은 최소 횟수로 누르려고 한다.
//
//설정해야 할 시간이 주어졌을 때, 그 시간을 만들기 위해 눌러야 하는 버튼의 최소 횟수와 그 방법을 구하는 프로그램을 작성하시오.


//bfs활용문제

//일단 60분이 넘어간다면, 최대한 ADDH만을 사용해서 60분 단위로 올려줘야 최대한 적은 횟수로 버튼을 누를 수 있다.따라서 주어진 시간 N을 일단 60으로 나눈다.그러면 N / 60은 ADDH를 누른 횟수가 되는 것이고, 이제 우리는 N % 60분을 5가지의 버튼을 사용해서 맞춰주면 된다.
//
//또한 1분에서 59분까지의 버튼을 누르는 방법을 BFS를 사용해서 미리 구해두었다.
//
//사전 순으로 앞서는 방법을 출력하는 것이기 때문에 BFS 과정에서 큐에 구조체를 push할 때 MINO 버튼이 1 증가했을 때의 데이터부터 push해야 한다.

struct INFO {
	int addh, addt, mint, addo, mino, time;
};

int t, n;
INFO minute[65];
bool visited[65];
queue<INFO> q;

void Bfs()
{
	INFO info = { 0,0,0,0,0 };
	q.push(info);

	while (!q.empty())
	{
		INFO currInfo = q.front();
		q.pop();

		if (currInfo.time >= 0 && currInfo.time <= 60 && !visited[currInfo.time]) //time은 0보다 크거나 같고 60보다 작거나 같다
		{
			//visited[현재시간]을 해서 한번 방문한 시간은 방문하지 않는다.
			visited[currInfo.time] = true;
			minute[currInfo.time] = currInfo; //minute배열에 버튼 사용횟수 저장
			q.push({ currInfo.addh,currInfo.addt,currInfo.mint,currInfo.addo,currInfo.mino + 1,currInfo.time - 1 });
			q.push({ currInfo.addh,currInfo.addt,currInfo.mint,currInfo.addo + 1,currInfo.mino ,currInfo.time + 1 });
			q.push({ currInfo.addh,currInfo.addt,currInfo.mint + 1,currInfo.addo,currInfo.mino ,currInfo.time - 10 });
			q.push({ currInfo.addh,currInfo.addt + 1,currInfo.mint,currInfo.addo,currInfo.mino ,currInfo.time + 10 });
			q.push({ currInfo.addh + 1,currInfo.addt,currInfo.mint,currInfo.addo,currInfo.mino ,currInfo.time + 60 });


		}



	}
}


int main(void)
{

	ios_base::sync_with_stdio(0);
	cin.tie(0);

	Bfs();

	cin >> t;
	while (t--)
	{
		cin >> n;
		int m = n / 60;
		int r = n % 60;

		cout << minute[r].addh + m << " " << minute[r].addt << " " << minute[r].mint << " " << minute[r].addo << " " << minute[r].mino << "\n";


	}



	return 0;

}