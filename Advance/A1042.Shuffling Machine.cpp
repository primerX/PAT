#include<cstdio>

const int N = 54;
char mp[5] = {'S', 'H', 'C', 'D', 'J'};		//�Ƶı���뻨ɫ�Ĺ�ϵ
int start[N+1], end[N+1], next[N+1];	//next������ÿ��λ���ϵ����ڲ������λ�� 

int main()
{
	int k;
	scanf("%d", &k);
	for(int i=1; i<=N; i++){		//54���� �ӵ�һ�ſ�ʼ���±��1��ʼ��54
		start[i] = i;			//��ʼ���Ƶı�� 
	} 
	for(int i=1; i<=N; i++){
		scanf("%d", &next[i]);		//����ÿ��λ���ϵ����ڲ������λ�� 
	}
	for(int step=0; step<k; step++){	//ִ��k�β��� 
		for(int i=1; i<=N; i++){
			end[next[i]] = start[i];		//�ѵ� i��λ�õ��Ƶı�Ŵ���λ��next[i] 
		}
		for(int i=1; i<=N; i++){
			start[i] = end[i];		//��end���鸳ֵ��start���鹩�´β��� 
		} 
	} 
	
	for(int i=1; i<=N; i++)
	{
		//if(i != 1) printf(" ");		//���������ʽ
		start[i]--;
		printf("%c%d", mp[start[i]/13], start[i]%13 + 1);		//������ 
		if(i != N) printf(" ");
	}
	return 0;
}
