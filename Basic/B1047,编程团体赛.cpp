#include<cstdio>

const int maxn = 1010;
int hashTable[maxn] = {0};		//ÿ������ķ���

int main()
{
	int n;
	scanf("%d", &n);
	for(int i=0; i<n; i++){
		int team, member, score;	//�����ţ���Ա��ţ��÷�
		scanf("%d-%d %d", &team, &member, &score);
		hashTable[team] += score;		//���Ϊ team �Ķ�������ܷ� 
	}
	int k, max = -1;
	for(int i=0; i<maxn; i++){		//�ҵ�hashTable ��������ֵ
		if(hashTable[i] > hashTable[max]){
			k = i;
			max = hashTable[i];
		} 
	}
	printf("%d %d\n", k, max);		//������ 
	return 0;
 } 
