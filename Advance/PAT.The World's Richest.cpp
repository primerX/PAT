#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int maxn = 10010;

int Age[maxn] = {0};		//某年龄的人数 
struct Person{
	int age, worth;		//年龄，财富值
	char name[10];		//姓名 
}ps[maxn], valid[maxn];		//所有人，在各自年龄中财富值在100以内的人

bool cmp(Person a, Person b)
{
	if(a.worth != b.worth) return a.worth > b.worth;	//财富值从大到小排序 
	else if(a.age != b.age) return a.age < b.age;		//年龄从小到大排序
	else strcmp(a.name, b.name) < 0;		//姓名按字典序从小到大排序 
 } 
 
int main()
{
	int n, k;
	scanf("%d %d", &n, &k);		//总人数，查询次数
	for(int i=0; i<n; i++)
	{
		scanf("%s %d %d", &ps[i].name, &ps[i].age, &ps[i].worth);
	}
	sort(ps, ps+n, cmp);		//排序
	int validNum = 0;			//存放到 valid 数组中的人数
	for(int i=0; i<n; i++)
	{
		if(Age[ps[i].age] < 100){		//年龄ps[i].age的人数小于 100 时
			Age[ps[i].age]++;	 		//年龄ps[i].age的人数加 1 
			valid[validNum++] = ps[i];	//将ps[i] 加入新数组中 
		}	
	} 
	int m, ageL, ageR;
	for(int i=1; i<=k; i++){
		scanf("%d %d %d", &m, &ageL, &ageR);	// 前 M 人，年龄区间 
		printf("Case #%d:\n", i);
		int printNum = 0;		//已输出的人数
		for(int j=0; j<validNum && printNum < m; j++){
			if(valid[j].age >= ageL && valid[j].age <= ageR){
				printf("%s %d %d\n", valid[j].name, valid[j].age, valid[j].worth);
				printNum++;
			}
		}
		if(printNum == 0) printf("None\n");
	}
	return 0;
}
