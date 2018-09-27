#include<cstdio>
#include<cstring>

int main()
{
	char str[10010];
	fgets(str, 10010, stdin);
	int len = strlen(str);
	if(str[0] == '-') printf("-");	//如果是负数，输出负号
	
	int pos = 0;	//pos 存放字符串中 E 的位置
	while(str[pos] != 'E') pos++;
	
	int exp = 0;	//exp 用来存放指数(先不考虑正负)
	for(int i=pos+2; i<len; i++){
		exp = exp * 10 + (str[i] - '0');
	}
	if(exp == 0)	//特判指数为 0 的情况
	{
		for(int i=1; i<pos; i++){
			printf("%c", str[i]);
		}
	 } 
	
	if(str[pos + 1] == '-')		//如果指数为负
	{
		printf("0.");
		for(int i=0; i<exp-1; i++)	//输出(exp-1)个 0
		{
			printf("0");
		 } 
		printf("%c", str[1]);	//输出除了小数点以外的数
		for(int i=3; i<pos; i++){
			printf("%c", str[i]);
		} 
	 } else{	//如果指数为正 
	 	for(int i=1; i<pos; i++){	//输出小数点移动之后的数 
	 		if(str[i] == '.') continue;		//略过原小数点
			 printf("%c", str[i]);	//输出当前位数
			 if(i == exp+2 && pos-3 != exp) {	//小数点加在位置(exp+2)上 
			 	//原小数点和E之间的数字个数(pos-3)不能等于小数点右移位数exp
				 printf("."); 
			 }
		 }
		 //如果指数exp 较大, 输出多余的 0
		 for(int i=0; i<exp-(pos-3); i++){
		 	printf("0");
		 	
		 } 
	 }
	return 0;
 } 
