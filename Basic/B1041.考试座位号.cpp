#include<cstdio>

struct Student{
	long long id;	//准考证号
	int examSeat;	//座位号 
}testSeat[1010];	//以试机座位号作为下标来记录考生 

int main()
{
	int n, m, seat, examSeat;
	long long id;
	scanf("%d", &n);
	for(int i=0; i<n; i++)
	{
		scanf("%lld %d %d", &id, &seat, &examSeat);
		testSeat[seat].id = id;
		testSeat[seat].examSeat = examSeat;
	}
	scanf("%d", &m);		//查询个数
	for(int i=0; i<m; i++)
	{
		scanf("%d", &seat);
		printf("%lld %d", testSeat[seat].id, testSeat[seat].examSeat);
	 } 
	return 0;
}
