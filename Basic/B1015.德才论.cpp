#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

struct Student{
	char id[10];	//准考证号
	int de, cai, sum;	//德分，才分，总分
	int flag;		//考生类别：1~5 
}stu[100010]; 

bool cmp(Student a, Student b)
{
	if(a.flag != b.flag) return a.flag < b.flag;	//类别小的在前面
	else if(a.sum != b.sum) return a.sum > b.sum;	//类别相同时，总分大的在前
	else if(a.de != b.de) return a.de > b.de;		//总分相同时，德分大的在前
	else return strcmp(a.id, b.id) < 0;				//德分相同时，准考证号小的在前 
}

int main()
{
	int n, L, H;
	scanf("%d %d %d", &n, &L, &H);
	int m = n;		//m 为及格人数
	for(int i=0; i<n; i++)
	{
		scanf("%s %d %d", &stu[i].id, &stu[i].de, &stu[i].cai);
		stu[i].sum = stu[i].de + stu[i].cai;	//计算总分
		if(stu[i].de < L || stu[i].cai < L){	//先将不及格者设置为第5类
			stu[i].flag = 5;
			m--; 
		}else if(stu[i].de >= H && stu[i].cai >= H) stu[i].flag = 1;
		else if(stu[i].de >= H && stu[i].cai < H) stu[i].flag = 2;
		else if(stu[i].de >= stu[i].cai) stu[i].flag = 3;
		else stu[i].flag = 4;		//第4 类情况最多，因此放到最后 
	 }
	 sort(stu, stu+n, cmp);		//排序
	 printf("%d\n",m);
	 for(int i=0; i<m; i++){
	 	printf("%s %d %d", stu[i].id, stu[i].de, stu[i].cai);
	 } 
	return 0;
}
