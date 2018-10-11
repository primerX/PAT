#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn = 100010;
int n, p, a[maxn];

//binarySearch ������[i+1, n-1]��Χ�ڲ��ҵ�һ������ x ������λ��
int binarySearch(int i, long long x)
{
	if(a[n-1] <= x) return n;		//����������������� x������ n
	int left = i + 1, right = n - 1, mid;		//��[i+1, n-1]�ڲ���
	while(left < right){
		mid = (left + right) / 2;
		if(a[mid] <= x){		//��a[mid] <= x ˵����һ������ x ����ֻ���� mid ����
			left = mid + 1; 
		}else{					//��a[mid]>x ˵����һ������ x ������mid֮ǰ(��mid)
			right = mid; 
		}
	} 
	return left;
}

int main()
{
	scanf("%d %d", &n, &p);
	for(int i=0; i<n; i++){
		scanf("%d", &a[i]);
	}
	sort(a, a + n);			//��������
	int ans = 1;			//��󳤶ȣ���ֵΪ 1 ��ʾ������һ����
	for(int i=0; i<n; i++){
		//�� a[i]~a[n-1] �в��ҵ�һ������ a[i] * p ������������λ�ø� j
		int j = binarySearch(i, (long long)a[i] * p);
		ans = max(ans, j - i);		//������󳤶�	 
	} 
	printf("%d\n", ans);
	return 0;
}
