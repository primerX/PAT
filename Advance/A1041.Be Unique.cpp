#include<cstdio>

int hashTable[10001] = {0};		//����������ֳ����˼���

int main()
{
	int n;
	int a[100001];			//a[] Ϊ��������� 
	scanf("%d", &n);
	for(int i=0; i<n; i++){
		scanf("%d", &a[i]);
		hashTable[a[i]]++;		//���� a[i] ���ֵĴ����� 1 
	}
	int ans = -1;		//��ŵ�һ�γ��ֵ���������ֻ��һ��������
	for(int i=0; i<n; i++){
		if(hashTable[a[i]] == 1){		//���� ֻ������һ��
			ans = a[i];
			break; 
		}
	} 
	if(ans == -1) printf("None");		//�Ҳ���ֻ����һ�ε�����
	else printf("%d\n", ans); 
	return 0;
 } 
