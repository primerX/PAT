#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;

struct Student{
	int id;		//���6λ������ id
	int grade[4];	//����ĸ����� 
}stu[2010];

char course[4] = {'A', 'C', 'M', 'E'};	//�����ȼ����򣬷������
int Rank[10000000][4] = {0};			//Rank[id][0]-Rank[id][3]Ϊ���ſζ�Ӧ������
int now;		//cmp������ʹ��,��ʾ��ǰ��now, �ŷ�������stu����

bool cmp(Student a, Student b)		//stu ���鰴 now �ŷ����ݼ����� 
{
	return a.grade[now] > b.grade[now];
}

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	//�������,����grade[0]~grade[3]�ֱ����A,C,M,E
	for(int i=0; i<n; i++){
		scanf("%d %d %d %d", &stu[i].id, &stu[i].grade[1],
		&stu[i].grade[2], &stu[i].grade[3]);
		stu[i].grade[0] = round((stu[i].grade[1] + stu[i].grade[2] + 
		stu[i].grade[3]) / 3.0) + 0.5;
	} 
	for(now = 0; now<4; now++){		//ö��A,C,M,E 4���е�һ��
		sort(stu, stu+n, cmp);		//�����п����������Ӵ�С����
		Rank[stu[0].id][now] = 1;	//�����棬��������ߵ�����Ϊ 1
		for(int i=1; i<n; i++){		//����ʣ�µ�ѧ��
			//����ǰһλ����������ͬ
			if(stu[i].grade[now] == stu[i-1].grade[now]){
				Rank[stu[i].id][now] = Rank[stu[i-1].id][now];	//������ͬ 
			}else{
				Rank[stu[i].id][now] = i + 1;	//����Ϊ��������ȷ������ 
			}
		} 
	}
	int query;		//��ѯ�Ŀ���ID
	for(int i=0; i<m; i++){
		scanf("%d", &query);
		if(Rank[query][0] == 0){		//����������ID������,�����"N/A"
			printf("N/A\n");
		}else{
			int k = 0;		//ѡ��Rank[query][0~3]����С��(rankֵԽС������Խ��)
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
