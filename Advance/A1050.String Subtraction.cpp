#include<cstdio>
#include<cstring>

const int max_len = 10005;
char a[max_len], b[max_len];
bool hashTable[128];		//��¼�ַ��Ƿ��ڵڶ����ַ�������ֹ�

int main()
{
	fgets(a, max_len, stdin);
	fgets(b, max_len, stdin);
	int lenA = strlen(a);
	int lenB = strlen(b);
	for(int i=0; i<lenB; i++){
		hashTable[b[i]] = true;		//�ڶ����ַ�������ַ�table����Ϊtrue 
	}
	for(int i=0; i<lenA; i++){
		if(hashTable[a[i]] == false){		//����ڵڶ����ַ�����û���ֹ�
			printf("%c", a[i]); 
		}
	}
	return 0;
 } 
