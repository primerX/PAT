#include<cstdio>

const int N = 100010;
int sum[N];
int n, s, nearS = 10000010;

//upper_bound ����������[L, R) �ڵ�һ������ x ��λ��
upper_bound(int L, int R, int x) 
{
	int left = L, right = R, mid;
	while(left < right)
	{
		mid = (left + right) / 2;
		if(sum[mid] > x){
			right = mid;
		}else{
			left = mid + 1;
		}
	}
	return left;
}

int main()
{
	scanf("%d %d", &n, &s);		//Ԫ�ظ�����ֵ s
	sum[0] = 0;		//��ʼ�� sum[0] = 0
	for(int i=1; i<=n; i++){
		scanf("%d", sum[i]);
		sum[i] += sum[i-1];
	} 
	for(int i=1; i<=n; i++){	//ö����˵�
		int j = upper_bound(i, n+1, sum[i-1] + s);		//���Ҷ˵�
		if(sum[j-1] - sum[i-1] == s){		//���ҳɹ�(�� j-1 ������ j)
			nearS = s;			//��ӽ� s ��ֵ���� s
			break; 
		}else if(j <= n && sum[j] - sum[i-1] < nearS){
			//���ڴ��� s �ĽⲢС�� nearS
			nearS = sum[j] - sum[i - 1];		//���µ�ǰ nearS 
		}
	}
	for(int i=1; i<=n; i++){
		int j = upper_bound(i, n+1, sum[i-1] + nearS);	//���Ҷ˵�
		if(sum[j - 1] - sum[i - 1] == nearS){		//���ҳɹ�
			printf("%d-%d\n", i, j-1);			//�����˵���Ҷ˵� 
		}	
	}
	return 0;
}
