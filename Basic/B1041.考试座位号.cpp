#include<cstdio>

struct Student{
	long long id;	//׼��֤��
	int examSeat;	//��λ�� 
}testSeat[1010];	//���Ի���λ����Ϊ�±�����¼���� 

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
	scanf("%d", &m);		//��ѯ����
	for(int i=0; i<m; i++)
	{
		scanf("%d", &seat);
		printf("%lld %d", testSeat[seat].id, testSeat[seat].examSeat);
	 } 
	return 0;
}
