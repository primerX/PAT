#include<cstdio>
#include<algorithm>
using namespace std;

struct mooncake{
	double store;		//�����
	double sell;		//���ۼ�
	double price;		//���� 
}cake[1010];

bool cmp(mooncake a, mooncake b)	//���۰��Ӹߵ������� 
{
	return a.price > b.price; 
}

int main()
{
	int n;
	double D;
	scanf("%d %lf", &n, &D);
	for(int i=0; i<n; i++)
	{
		scanf("%lf", &cake[i].store);
	}
	for(int i=0; i<n; i++){
		scanf("%lf", &cake[i].sell);
		cake[i].price = cake[i].sell / cake[i].store;	//���㵥�� 
	}
	sort(cake, cake+n, cmp);	//�����۴Ӹߵ�������
	double ans = 0;		//����
	for(int i=0; i<n; i++){
		if(cake[i].store <= D){		//��������������±������
			D -= cake[i].store;		//�� i ���±�ȫ������
			ans += cake[i].sell; 
		}else{		//����±����������������
			ans += cake[i].price * D;		//ֻ�������������±�
			break; 
		}
	} 
	printf("%.2f\n", ans);
	return 0;
}
