#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn = 510;
const int INF = 1000000000;

struct Station{
	double price, dis;		//�۸����ľ��� 
}st[maxn];

bool cmp(Station a, Station b)
{
	return a.dis < b.dis;		//�������С���� 
}

int main()
{
	int n;
	double Cmax, D, Davg;
	scanf("%lf %lf %lf %d", &Cmax, &D, &Davg, &n);
	for(int i=0; i<n; i++){
		scanf("%lf %lf", &st[i].price, &st[i].dis);
	}
	st[n].price = 0;		//�������������յ�,�۸�Ϊ 0 
	st[n].dis = D;			//�յ����Ϊ D 
	sort(st, st + n, cmp);	//�������յ�վ�������С��������
	if(st[0].dis != 0){		//��������ĵ�һ������վ���벻�� 0��˵���޷�ǰ��
		printf("The maximum travel distance = 0.00\n"); 
	}else{
		int now = 0;		//now ��ʾ��ǰ�����ļ���վ���
		//�ܻ��ѣ���ǰ��������������ʻ����
		double ans = 0, nowTank = 0, Max = Cmax * Davg;
		while(now < n){		//ÿ��ѭ����ѡ����һ����Ҫ����ļ���վ
			//ѡ���ӵ�ǰ����վ�����ܵ��ﷶΧ�ڵ�һ���ͼ۵��ڵ�ǰ�ͼ۵ļ���վ
			//���û�е��ڵ�ǰ�ͼ۵ļ���վ����ѡ��۸���͵���һ�� 
			int k = -1;		//����ͼ۵ļ���վ���
			double priceMin = INF;		//����ͼ�
			for(int i=now+1; i<=n && st[i].dis - st[now].dis <= Max; i++){
				if(st[i].price < priceMin){		//����ͼ۱ȵ�ǰ����ͼ۵�
					priceMin = st[i].price;		//��������ͼ�
					k = i;
					//����Ҵ��һ���ͼ۵��ڵ�ǰ�ͼ۵ļ���վ����ֱ���ж�ѭ��
					if(priceMin < st[now].price){
						break;
					} 
				}
			}
			if(k == -1) break;	//����״̬���޷��ҵ�����վ���˳�ѭ����������
			//����Ϊ���ҵ��ɵ���ļ���վ k�� ����ת�ƻ���
			//need Ϊ�� now �� k ����Ҫ������
			double need = (st[k].dis - st[now].dis) / Davg;
			if(priceMin < st[now].price){		//�������վ k ���ͼ۵��ڵ�ǰ�ͼ�
				//ֻ���㹻�������վ k ����
				if(nowTank < need){			//�����ǰ�������� need
					ans += (need - nowTank) * st[now].price;	//���� need
					nowTank = 0;			//�������վ k ������������Ϊ 0 
				}else{		//�����ǰ�������� need
					nowTank -= need;		//ֱ�ӵ������վ 
				}
			}else{			//�������վ k ���ͼ۸��ڵ�ǰ�ͼ�
				ans += (Cmax - nowTank) + st[now].price;		//���������
				//�������վ k ������������Ϊ Cmax - need
				nowTank = Cmax - need; 
			}
			now = k;			//�������վ k��������һ��ѭ�� 
		}
		if(now == n){		//�ܵ����յ�
			printf("%.2f\n", ans); 
		}else{			//���ܵ����յ�
			printf("The maximum travel distance = %.2f\n", st[now].dis + Max); 
		}
	}
	return 0;
}
