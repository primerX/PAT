#include<cstdio>

struct person{
	char name[10];	//姓名
	int yy, mm, dd;		//日期	 
}oldest, youngest, left, right, temp;
//oldest 与youngest 存放最年长与最年轻的人，
//right 与 left 存放合法日期的左右边界

bool LessEqu(person a, person b)	//如果 a 的日期小于 b 则返回 true
{
	if(a.yy != b.yy) return a.yy <= b.yy;
	else if(a.mm != b.mm) return a.mm <= b.mm;
	else return a.dd <= b.dd; 
} 

bool MoreEqu(person a, person b)	//如果 a 的日期大于等于,则返回true
{
	if(a.yy != b.yy) return a.yy >= b.yy;
	else if(a.mm != b.mm) return a.mm >= b.mm;
	else return a.dd >= b.dd; 
} 

//youngest 与 left 为 1814 年 9 月 6 日
//oldest 与 right 为 2014 年 9 月 6 日

void init()
{
	youngest.yy = left.yy = 1814;
	oldest.yy = right.yy = 2014;
	youngest.mm = left.mm = right.mm = oldest.mm = 9;
	youngest.dd = left.dd = right.dd = oldest.dd = 6;
 } 

int main()
{
	init();		//初始化
	int n, num = 0;		//num 存放合法日期的人数
	scanf("%d", &n);
	for(int i=0; i<n; i++)
	{
		scanf("%s %d/%d/%d", &temp.name, temp.yy, temp.mm, temp.dd);
		if(MoreEqu(temp, left) && LessEqu(temp, right))		//合法日期
		{
			num++;
			if(LessEqu(temp, oldest)) oldest = temp;		//更新 oldest
			if(MoreEqu(temp, youngest)) youngest = temp;	//更新 youngest 
		 } 
	 } 
	 if(num == 0) printf("0\n");	//所有人的日期都不合法,特判 
	 else printf("%d %s %s", num, oldest.name, youngest.name); 
	return 0;
 } 
