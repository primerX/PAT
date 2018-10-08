#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int maxn = 100010;
struct Student{
	int id;		//准考证号
	char name[10];		//姓名
	int score;		//分数 
}stu[maxn];

bool cmp1(Student a, Student b)
{
	return a.id < b.id;
}

bool cmp2(Student a, Student b)
{
	int s = strcmp(a.name, b.name);
	if(s != 0) return s < 0;		//姓名不相同，按姓名字典序从小到大 
	else{
		return a.id < b.id;		//姓名相同，按准考证号从小到大排序 
	}
}

bool cmp3(Student a, Student b)
{
	if(a.score != b.score)	return a.score < b.score;	//分数不同，按从小到大
	else return a.id < b.id;		//分数相同，则按准考证号从小到大 
}

int main()
{
	int n, c;
	scanf("%d %d", &n, &c);
	for(int i=0; i<n; i++){
		scanf("%d %s %d", &stu[i].id, &stu[i].name, &stu[i].score);
	}
	if(c == 1) sort(stu, stu+n, cmp1);
	else if(c==2) sort(stu, stu+n, cmp2);
	else if(c==3) sort(stu, stu+n, cmp3);
	for(int i=0; i<n; i++){
		printf("%06d %s %d\n", stu[i].id, stu[i].name, stu[i].score);
	}
	return 0;
}
