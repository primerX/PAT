#include<cstdio>

int main()
{
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	int sum = a + b;
	int ans[31], num = 0;	//ans ������� D ���Ƶ�ÿһλ
	do{		//����ת�� 
		ans[num++] = sum % c;
		sum /= c;
	} while(sum != 0);
	for(int i=num-1; i>=0; i--)		//�Ӹ�λ����λ�������
	{
		printf("%d", ans[i]);
	 } 
	return 0;
}
