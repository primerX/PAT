#include<cstdio>
#include<cstring>

int main()
{
	char str[1010];
	fgets(str, 1010, stdin);	//����һ�� 
	int len = strlen(str);
	
	int count[10] = {0};	//��¼0~9 ���ֵĴ���
	for(int i=0; i<len; i++)
	{
		count[str[i] - '0']++;	//��str[i] ��Ӧ���ֵ� count ֵ��1 
	}
	for(int i=0; i<10; i++)		//ö�� 0~9
	{
		if(count[i] != 0){
			printf("%d:%d", i, count[i]);
		}
	 } 
	return 0;
}
