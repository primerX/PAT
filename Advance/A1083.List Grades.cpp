#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int maxn = 50;
struct Student{
	char name[11];		//姓名
	char id[11];		//准考证号
	int grade;			//分数 
}stu[maxn];

bool cmp(Student a, Student b)
{
	return a.grade > b.grade;		//分数从大到小排序 
}

int main()
{
	int n, left, right;
	scanf("%d", &n);
	for(int i=0; i<n; i++){
		scanf("%s %s %d", &stu[i].name, &stu[i].id, &stu[i].grade);
	}
	scanf("%d %d", left, right);		//区间左右端点
	sort(stu, stu+n, cmp);
	bool flag = false;		//flag 记录是否存在[left, right]内的考生
	for(int i=0; i<n; i++)
	{
		if(stu[i].grade >= left && stu[i].grade <= right){
			printf("%s %s\n", stu[i].name, stu[i].id);
			flag = true;
		}
	 }
	 if(flag == false){		//所有考生分数都不在[left, right]中
	 	printf("None"); 
	 }
}
