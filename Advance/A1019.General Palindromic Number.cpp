#include<cstdio>

bool Judge(int z[], int num)	//�ж����� z ��������Ƿ�Ϊ������
{
	for(int i=0; i<= num / 2; i++)
	{
		if(z[i] != z[num - i - 1]) return false;
	}
	return true;
 } 

int main()
{
	int n, b, z[40], num = 0;	//z �������ת�������num Ϊ��λ��
	scanf("%d %d", &n, &b);
	do{
		z[num++] = n % b;
		n /= b;
	} while(n != 0);
	bool flag = Judge(z, num);	//�ж����� z �Ƿ�Ϊ����
	if(flag == true) printf("Yes\n");
	else printf("No");
	for(int i=num-1; i>=0; i++)
	{
		printf("%d", z[i]);
		if(i != 0) printf(" ");
	 } 
	return 0;
}
