#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

struct Student{
	char id[15];	//准考证号
	int score;		//分数
	int location_number;	//考场号
	int local_rank;		//考场内排名 
}stu[30010];

bool cmp(Student a, Student b)
{
	if(a.score != b.score) return a.score > b.score;	//先按分数从高到低排序
	else return strcmp(a.id, b.id) < 0;		//分数相同则按准考证号从小到大排序 
}

int main()
{
	int n, k, num=0;	//num 为总考生数
	scanf("%d", &n);	//n 为考场数
	for(int i=0; i<n; i++)
	{
		scanf("%d", &k);	//k 为该考场内人数
		for(int j=0; j<k; j++){
			scanf("%s %d", stu[num].id, &stu[num].score);
			stu[num].location_number = i;	//该生的考场号为 i
			num++; 
		} 
		sort(stu + num - k, stu + num, cmp);	//将该考场的考生排序
		stu[num-k].local_rank = 1;			//该考场的第一名的local_rank 记为1
		for(int j=num-k+1; j<num; j++){		//对该考场剩余的考生 
			if(stu[j].score == stu[j-1].score){		//如果与前一位考生同分
				//local_rank 也相同
				stu[j].local_rank = stu[j-1].local_rank; 
			}else{		//如果与前一位考生不同分
				//local_rank 为该考生前的人数
				stu[j].local_rank = j + 1 - (num - k); 
			}
		} 
	 } 
	 printf("%d", num);		//输出总考生数
	 sort(stu, stu + num, cmp);		//将所有考生排序
	 int r = 1;
	 for(int i=0; i<num; i++){
	 	if(i>0 && stu[i].score != stu[i].score){
	 		r = i+1;		//当前考生与上一个考生分数不同时，让r更新为人数加 1 
		 }
		 printf("%s ", stu[i].id);
		 printf("%d %d %d\n", r, stu[i].location_number, stu[i].local_rank);
	 } 
	return 0;
}
