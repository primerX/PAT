#include<cstdio>
#include<cstring>

int main()
{
	char str[100];
	gets(str);
	int N = strlen(str);	//��ȡ�ַ��ĳ���
	int n1 = (N + 2) / 3, n3 = n1, n2 = N + 2 - n1 - n3;
	for(int i=0; i<n1-1; i++)	//���ǰn1 - 1 ��
	{
		printf("%c", str[i]);
		for(int j=0; j<n2-2; j++)	
		{
			printf(" ");	//��� n2 - 2���ո� 
		}
		printf("%c\n", str[N-i-1]);		//�����ǰ�е��Ҳ��ַ� 
	 } 
	 for(int i=0; i<n2; i++)
	 {
	 	printf("%c", str[n1+i-1]);		//����ײ��� n ���ַ� 
	  } 
	return 0;
 } 
