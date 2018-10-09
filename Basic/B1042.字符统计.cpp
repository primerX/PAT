#include<cstdio>
#include<cstring>

const int maxn = 1010;
int hashTable[30] = {0};		//������¼ 'a(A)'~'z(Z)' �ĳ��ִ���
char str[maxn]; 

int main()
{
	fgets(str, maxn, stdin);
	int len = strlen(str);
	for(int i=0; i<len; i++){
		if(str[i] >= 'a' && str[i] <= 'z'){		//str[i]��Сд��ĸ
			hashTable[str[i] - 'a']++;			//str[i]���ִ����� 
		}else if(str[i] >= 'A' && str[i] <= 'Z'){	//str[i]�Ǵ�д��ĸ 
			hashTable[str[i] - 'A']++;		//str[i]��ӦСд��ĸ�ĳ��ִ����� 1 
		} 
	}
	int k = 0;		//��¼���������Ԫ�ص��±�
	for(int i=0; i<len; i++){
		if(hashTable[i] > hashTable[k]){
			k = i;
		}
	} 
	printf("%c %d\n", 'a' + k, hashTable[k]);		//�����Ӧ���ַ��ͳ��ִ��� 
	return 0;
}
