#include<cstdio>
#include<cstring>

const int maxn = 100010;
bool HashTable[256];		//ɢ�����飬������¼�����ϵ��ַ��Ƿ����
char str[maxn];

int main()
{
	memset(HashTable, true, sizeof(HashTable));		//��ֵΪtrue ��ʾ���м������
	fgets(str, maxn, stdin);		//��������ʧЧ�ļ�
	int len = strlen(str);
	for(int i=0; i<len; i++)
	{
		if(str[i] >= 'A' && str[i] <= 'Z'){
			str[i] = str[i] - 'A' + 'a';		//����Ǵ�д��ĸ����ת��ΪСд��ĸ 
		} 
		HashTable[str[i]] = false;		//����str[i]��ʧЧ 
	}
	fgets(str, maxn, stdin);		//������������ַ���
	len = strlen(str);
	for(int i=0; i<len; i++){
		if(str[i] >= 'A' && str[i] <= 'Z'){		//����Ǵ�д��ĸ����� 
			int low = str[i] - 'A' + 'a';		//����Ǵ�д��ĸ����ת��ΪСд��ĸ
			if(HashTable[low] == true && HashTable['+'] == true){
				//ֻ��Сд��ĸ�ļ�λ���ϵ���λ����ã����ܽ������
				printf("%c", str[i]); 
			} 
		}else if(HashTable[str[i]] == true){
			//���������ַ���ֻҪ��λ��ã��Ϳ������ 
			printf("%c", str[i]);
		}
	}
	printf("\n");
	return 0;
 } 
