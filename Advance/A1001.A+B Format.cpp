#include<cstdio>

int main()
{
	int num[10];
	int a, b, sum;
	scanf("%d %d", &a, &b);
	sum = a + b;
	if(sum < 0){	//sum Ϊ����ʱ��������Ų�ȡ sum ���෴�� 
		printf("-");
		sum = -sum;
	}
	int len = 0;	//len ��� sum �ĳ���
	if(sum == 0) num[len++] = 0;	//sum Ϊ 0 ʱ�ر���
	//�� sum �������� num[] �У����� sum �ĵ�λ��ŵ� num[] �ĵ�λ
	while(sum)
	{
		//�� sum ��ĩλ sum%10 ��ŵ� num[len], Ȼ��len++
		num[len++] = sum % 10;
		sum /= 10;	//ȡ�� sum ��ĩλ 
	 } 
	 for(int k=len-1; k>=0; k--)	//�Ӹ�λ��ʼ���
	 {
	 	printf("%d", num[k]);
	 	if(k > 0 && k%3 == 0) printf(",");	//ÿ 3 λһ�����ţ����һλ���� 
	  } 
	return 0;
 } 
