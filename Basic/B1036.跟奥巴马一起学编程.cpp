#include<cstdio>

int main()
{
	int row, col;	//�У���
	char c;
	scanf("%d %c", &col, &c);	//����������Ҫʹ�õ��ַ���
	if(col % 2 == 1) row = col / 2 + 1;		//col Ϊ����������ȡ�� 
	else row = col / 2;
	
	//��һ��
	for(int i=0; i<col; i++){
		printf("%c", c);		//col���ַ� 
	} 
	//�� 2~row-1 ��
	for(int i=2; i<row; i++){
		printf("%c", c);		//ÿ�еĵ�һ�� c
		for(int j=0; j<col-2; j++)	//col-2 ���ո�
		{
			printf(" ");
		}
		printf("%c\n", c);		//ÿ�е����һ�� c 
	} 
	//�� row ��
	for(int i=0; i<col; i++){
		printf("%c", c);		//col���ַ� 
	} 
	return 0;
}
