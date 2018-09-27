#include<cstdio>
#include<cstring>

char num[10][5] = {		//将数字对应字符 
	"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"
};
char wei[5][5] = {
	"Shi", "Bai", "Qian", "Wan", "Yi"};
	
int main()
{
	char str[15];
	fgets(str, 15, stdin);
	int len = strlen(str);
	int left = 0, right = len - 1;	//left 与 right 分别指向字符串首尾元素
	if(str[0] == '-'){		//如果是负数，则输出"Fu",并把 left 右移一位 
		printf("Fu");
		left++;
	} 
	while(left + 4 <= right){
		right -= 4;			//将right 每次左移 4 位，直到left与right 在同一节 
	}
	while(left < len){		//循环每次处理数字的一节(4 位或小于 4位)
		bool flag = false;	//flag == false 表示没有累积的 0
		bool isPrint = false;	//isPrint==false 表示该节位没有输出过其中的位
		while(left <= right){	//从左至右处理数字中某节的每一位
			if(left > 0 && str[left] == '0'){	//如果当前位为 0
				flag = true; 
			} else{			//如果当前位不为 0
				if(flag == true){		//如果存在累积的 0
					printf(" ling");
					flag = false; 
				} 
				//只要不是首位，后面的每一位前都要输出空格
				if(left > 0) printf(" ");
				printf("%s", num[str[left] - '0']);		//输出当前数字
				isPrint = true;		//该节至少有一位被输出
				if(left != right){		//某节中除了个位外，都要输出十百千
					printf(" %s", wei[right - left - 1]);
				} 
			}
			left++;
		} 
		if(isPrint && right!=len-1){	//只要不是个位，就输出万或亿
			printf(" %s", wei[(len - 1 - right) / 4 + 2]);
		}
		right += 4;		//right 右移 4 位，输出下一节 
	} 
	return 0;
 } 
