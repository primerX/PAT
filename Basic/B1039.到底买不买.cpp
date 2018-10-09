#include<cstdio>
#include<cstring>

const int maxn = 1010;
//hashTable ��¼��һ����ÿ����ɫ�ĸ���, �� miss ��¼ȱ�ٵ����Ӹ���
int hashTable[80] = {0}, miss = 0;

//�����ֺ���ĸת����hashTable ���±�
int change(char c)
{
	if(c >= '0' && c <= '9') return c - '0';		//����
	if(c >= 'a' && c <= 'z') return c - 'a' + 10;		//Сд��ĸ 
	if(c >= 'A' && c <= 'Z') return c - 'A' + 36;		//��д��ĸ 
} 

int main()
{
	char whole[maxn], target[maxn];
	fgets(whole, maxn, stdin);
	fgets(target, maxn, stdin);
	int len1 = strlen(whole);
	int len2 = strlen(target);
	for(int i=0; i<len1; i++){		//������һ��
		int id = change(whole[i]);	//�ַ�-> hashTable �±�
		hashTable[id]++;		//����ɫ������ 1 
	}
	for(int i=0; i<len2; i++){
		int id = change(target[i]);
		hashTable[id]--;		//����ɫ������һ 
		if(hashTable[id] < 0){		//����ɫ����С��1
			miss++; 
		}
	} 
	if(miss > 0) printf("No %d\n", miss);		//��ȱ��
	else printf("Yes %d\n", len1 - len2); 
	return 0;
 } 
