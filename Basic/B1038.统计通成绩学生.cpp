#include<cstdio>
#include<cstring>

int hashTable[110];		//��¼ÿ���������ֵĴ���

int main()
{
	int n, score, k;
	scanf("%d", &n);
	for(int i=0; i<n; i++){
		scanf("%d", &score);	//����
		hashTable[score]++;		// ����score���ֵĴ����� 1 
	}
	scanf("%d", &k);
	for(int i=0; i<k; i++){
		scanf("%d", &score);
		printf("%d", hashTable[score]);		//��ѯ�������ֵĴ���
		if(i < k-1) printf(" ");		//ǰk-1 �������������ո� 
	} 
	return 0;
 } 
