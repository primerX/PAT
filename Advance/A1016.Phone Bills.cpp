#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

const int maxn = 1010;
int toll[25];		//资费
struct Record{
	char name[25];			//姓名
	int month, dd, hh, mm;	//月份，日，时，分 
	bool status;		//status==true 表示该记录为on-line,否则为off-line 
}rec[maxn], temp;

bool cmp(Record a, Record b){
	int s = strcmp(a.name, b.name);
	if(s != 0 ) return s < 0;		//优先按姓名字典序从小到大排序
	else if(a.month != b.month) return a.month < b.month;	//按月份从小到大
	else if(a.dd != b.dd) return a.dd < b.dd;	//按日期从小到大
	else if(a.hh != b.hh) return a.hh < b.hh;	//按小时从小到大
	else return a.mm < b.mm;		//按分钟从小到大排序 
} 

void get_ans(int on, int off, int &time, int& money){
	temp = rec[on];
	while(temp.dd < rec[off].dd || temp.hh < rec[off].hh || temp.mm < rec[off].mm)
	{
		time++;		//该次记录总时间加 1 min
		money += toll[temp.hh];		//话费增加toll[temp.hh]
		temp.mm++;		//当前时间加一分钟
		if(temp.mm >= 60){		//当前分钟数到达 60
			temp.mm = 0;
			temp.hh++;			//进入下一个小时 
		}
		if(temp.hh >= 24){		//当前小时数到达 24
			temp.hh = 0;
			temp.dd++;			//进入下一天 
		}
	}
}

int main()
{
	for(int i=0; i<24; i++){
		scanf("%d", &toll[i]);		//话费 
	}
	int n;
	scanf("%d", &n);		//记录数
	char line[10];			//临时存放 on-line 或 off-line 的输入
	for(int i=0; i<n; i++){
		scanf("%s", rec[i].name);
		scanf("%d:%d:%d:%d", &rec[i].month, &rec[i].dd, &rec[i].hh, &rec[i].mm);
		scanf("%s", line);
		if(strcmp(line, "on-line") == 0){
			rec[i].status = true;		//如果是on-line,则令status为true 
		}else{
			rec[i].status = false;		//如果是 off-line, 则status为 false 
		}
	}
	sort(rec, rec+n, cmp);		//排序
	int on = 0, off, next;		//on 与 off 为配对的两条记录, next 为下一个用户
	while(on < n)		//每次循环处理单个用户的所有记录
	{
		int needPrint = 0;		//needPrint 表示该用户是否需要输出
		next = on;		//从当前位置寻找下一个用户
		while(next < n && strcmp(rec[next].name, rec[on].name) == 0){
			if(needPrint == 0 && rec[next].status == true){
				needPrint = 1;		//找到 On, 置 needPrint 为 1 
			}else if(needPrint == 1 && rec[next].status == false){
				needPrint = 2;		//找到 off, 置 needPrint 为 2 
			}
			next++; 
		}
		if(needPrint < 2){		//没有找到配对的 on 与 off
			on = next;
			continue; 
		}
		int AllMoney = 0;		//总共花费的前
		printf("%s %02d\n", rec[on].name, rec[on].month);
		while(on < next)		//寻找该用户的所有配对
		{
			while(on < next-1 && !(rec[on].status==true && rec[on+1].status==false)){
				on++;		//知道找到连续的on-line 和 off-line 
			}
			off = on + 1;		//off 必须是 on 的下一个
			if(off == next){	//已经输出完毕所有配对的on-line 和 off-line
				on = next;
				break; 
			}
			printf("%02d:%02d:%02d ", rec[on].dd, rec[on].hh, rec[on].mm);
			printf("%02d:%02d:%02d ", rec[off].dd, rec[off].hh, rec[off].mm);
			int time = 0, money = 0;		//时间，单次记录花费的钱
			get_ans(on, off, time, money);		//计算on 到 off 内的时间和金钱
			AllMoney += money;		//总金额加上该次记录的钱
			printf("%d $%.2f\n", time, money / 100.0);
			on = off + 1;		//完成一个配对, 从off+1 开始寻找下一对 
		 } 
		 printf("Total amount: $%.2f\n", AllMoney / 100.0);
	 } 
	return 0;
}
