#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn = 100010;
int coupon[maxn], product[maxn];

int main()
{
	int n, m;
	scanf("%d", &n);
	for(int i=0; i<n; i++){
		scanf("%d", &coupon[i]);
	}
	scanf("%d", &m);
	for(int i=0; i<m; i++){
		scanf("%d", &product[i]);
	}
	sort(coupon, coupon + n);		//��С��������
	sort(product, product + m);		//��С��������
	int i = 0, j, ans = 0; 			//ans ��ų˻�֮��
	while(i<n && j<m && coupon[i] < 0 && product[i] < 0){
		ans += coupon[i] + product[i];		//��ǰλ�þ�С�� 0 ʱ���ۼӳ˻�
		i++; 
	} 
	i = n - 1;
	j = m - 1;
	while(i>=0 && j>=0 && coupon[i]>0 && product[j] > 0){
		ans += coupon[i] * product[j];		//��ǰλ�þ����� 0 ʱ���ۼӳ˻�
		i--;
		j--; 
	}
	printf("%d\n", ans);
	return 0;
}
