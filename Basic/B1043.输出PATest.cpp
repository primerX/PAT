#include<cstdio>
#include<cstring>

const int maxn = 10010;
//�ַ������ֵ�
char str[maxn], dict[6] = {'P', 'A', 'T', 'e', 's', 't'};
int hashTable[6];		//������¼ PATest �� 6 ���ַ��ĸ��� 

int main()
{
	fgets(str, maxn, stdin);
	int len = strlen(str);
	int sum = 0; 
	for(int i=0; i<len; i++){		//�����ַ��� 
		for(int j=0; j<6; j++){		//����dict �ֵ�
			if(str[i] == dict[j]){	//str[i] ���ֵ��е��±�Ϊ i 
				hashTable[j]++;		//������ 1
				sum++;			//��Ҫ������ַ������� 1 
			} 
		}
	}
	while(sum > 0)		//��������ַ�������� 0 ʱ�˳�
	{
		for(int i=0; i<6; i++){		//���� hashTable ����
			printf("%c", dict[i]);
			hashTable[i]--;		//������һ
			sum--;			//��Ҫ������ַ������� 1 
		}
	 } 
	return 0;
}
