#include<cstdio>

struct Poly{
	int exp;		//ָ��
	double cof;		//ϵ�� 
}poly[12];

double ans[2001];		//��Ž�� 

int main()
{
	int n, m, number = 0;
	scanf("%d", &n);		//��һ������ʽ�з���ϵ��������
	for(int i=0; i<n; i++)
	{
		scanf("%d %lf", &poly[i].exp, &poly[i].cof);	//��һ������ʽ��ָ����ϵ�� 
	 } 
	scanf("%d", &m);
	for(int i=0; i<m; i++)
	{
		int exp;
		double cof;
		scanf("%d %lf", &exp, &cof);	//�ڶ�������ʽ��ָ����ϵ��
		for(int j=0; j<n; j++)
		{
			ans[exp + poly[j].exp] += (cof * poly[j].cof);
		} 
	}
	for(int i=0; i<=2000; i++)
	{
		if(ans[i] != 0.0) number++;		//�ۼƷ���ϵ�������� 
	}
	printf("%d", number);
	for(int i=2000; i>=0; i--)
	{
		if(ans[i] != 0.0){
			printf(" %d %.1f", i, ans[i]);
		}
	}
	return 0;
}
