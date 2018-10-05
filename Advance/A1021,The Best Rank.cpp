#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;

struct Student{
	int id;		//存放6位整数的 id
	int grade[4];	//存放四个分数 
}stu[2010];

char course[4] = {'A', 'C', 'M', 'E'};	//按优先级排序，方便输出
int Rank[10000000][4] = {0};			//Rank[id][0]-Rank[id][3]为四门课对应的排名
int now;		//cmp函数中使用,表示当前按now, 号分数排序stu数组

bool cmp(Student a, Student b)		//stu 数组按 now 号分数递减排序 
{
	return a.grade[now] > b.grade[now];
}

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	//读入分数,其中grade[0]~grade[3]分别代表A,C,M,E
	for(int i=0; i<n; i++){
		scanf("%d %d %d %d", &stu[i].id, &stu[i].grade[1],
		&stu[i].grade[2], &stu[i].grade[3]);
		stu[i].grade[0] = round((stu[i].grade[1] + stu[i].grade[2] + 
		stu[i].grade[3]) / 3.0) + 0.5;
	} 
	for(now = 0; now<4; now++){		//枚举A,C,M,E 4个中的一个
		sort(stu, stu+n, cmp);		//对所有考生按分数从大到小排序
		Rank[stu[0].id][now] = 1;	//排序玩，将分数最高的设置为 1
		for(int i=1; i<n; i++){		//对于剩下的学生
			//若与前一位考生分数相同
			if(stu[i].grade[now] == stu[i-1].grade[now]){
				Rank[stu[i].id][now] = Rank[stu[i-1].id][now];	//排名相同 
			}else{
				Rank[stu[i].id][now] = i + 1;	//否则，为其设置正确的排名 
			}
		} 
	}
	int query;		//查询的考生ID
	for(int i=0; i<m; i++){
		scanf("%d", &query);
		if(Rank[query][0] == 0){		//如果这个考生ID不存在,则输出"N/A"
			printf("N/A\n");
		}else{
			int k = 0;		//选出Rank[query][0~3]中最小的(rank值越小，排名越高)
			for(int j=0; j<4; j++){
				if(Rank[query][j] < Rank[query][k]){
					k = j;
				}
			} 
			printf("%d %c\n", Rank[query][k], course[k]);
		}
	}
	return 0;
 } 
