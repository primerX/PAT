#include<cstdio>

char s[3] = {'W', 'T', 'L'};

int main()
{
	double ans = 1.0, tmp, a;
	int idx;	//��¼ÿ��������ֵ��±�
	for(int i=0; i<3; i++)
	{
		tmp = 0.0;
		for(int j=0; j<3; j++)		//Ѱ�Ҹ����������ִ���tmp��
		{
			scanf("%lf", a);
			if(a > tmp){
				tmp = a;
				idx = j;
			}
		 } 
		 ans *= tmp;		//����ʽ�۳�
		 printf("%c ", s[idx]); 
	 } 
	 printf("%.2f", (ans*0.65 - 1) * 2);	//���������� 
	return 0;
}
