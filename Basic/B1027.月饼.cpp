#include<cstdio>
#include<algorithm>
using namespace std;

struct Mooncake{
	double store;		//�����
	double sell;		//���ۼ�
	double price;		//���� 
}cake[1010];

bool cmp(Mooncake a, Mooncake b)
{
	return a.price > b.price;
}

int main()
{
	int n;
	double D;
	scanf("%d %lf", &n, &D);
	for(int i=0; i<n; i++){
		scanf("%d", &cake[i].store);
	}
	for(int i=0; i<n; i++){
		scanf("%d", &cake[i].sell);
		cake[i].price = cake[i].sell / cake[i].store;	//���㵥�� 
	}
	sort(cake, cake+n, cmp);		//���۴Ӹߵ�������
	double ans = 0;				//����
	for(int i=0; i<n; i++){
		if(cake[i].store <= D){		//��������������±��Ŀ����
			D -= cake[i].store;		//�� i ���±�ȫ������
			ans += cake[i].sell; 
		}else{		//����±���������������� 
			ans += cake[i].price * D;		//ֻ����ʣ�����������±�
			break; 
		}
	} 
	printf("%.2f\n", ans);
	return 0;
}
