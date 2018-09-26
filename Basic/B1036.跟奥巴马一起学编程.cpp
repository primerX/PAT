#include<cstdio>

int main()
{
	int row, col;	//行，列
	char c;
	scanf("%d %c", &col, &c);	//输入列数，要使用的字符串
	if(col % 2 == 1) row = col / 2 + 1;		//col 为奇数，向上取整 
	else row = col / 2;
	
	//第一行
	for(int i=0; i<col; i++){
		printf("%c", c);		//col个字符 
	} 
	//第 2~row-1 行
	for(int i=2; i<row; i++){
		printf("%c", c);		//每行的第一个 c
		for(int j=0; j<col-2; j++)	//col-2 个空格
		{
			printf(" ");
		}
		printf("%c\n", c);		//每行的最后一个 c 
	} 
	//第 row 行
	for(int i=0; i<col; i++){
		printf("%c", c);		//col个字符 
	} 
	return 0;
}
