#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

struct Student{
	char id[15];	//׼��֤��
	int score;		//����
	int location_number;	//������
	int local_rank;		//���������� 
}stu[30010];

bool cmp(Student a, Student b)
{
	if(a.score != b.score) return a.score > b.score;	//�Ȱ������Ӹߵ�������
	else return strcmp(a.id, b.id) < 0;		//������ͬ��׼��֤�Ŵ�С�������� 
}

int main()
{
	int n, k, num=0;	//num Ϊ�ܿ�����
	scanf("%d", &n);	//n Ϊ������
	for(int i=0; i<n; i++)
	{
		scanf("%d", &k);	//k Ϊ�ÿ���������
		for(int j=0; j<k; j++){
			scanf("%s %d", stu[num].id, &stu[num].score);
			stu[num].location_number = i;	//�����Ŀ�����Ϊ i
			num++; 
		} 
		sort(stu + num - k, stu + num, cmp);	//���ÿ����Ŀ�������
		stu[num-k].local_rank = 1;			//�ÿ����ĵ�һ����local_rank ��Ϊ1
		for(int j=num-k+1; j<num; j++){		//�Ըÿ���ʣ��Ŀ��� 
			if(stu[j].score == stu[j-1].score){		//�����ǰһλ����ͬ��
				//local_rank Ҳ��ͬ
				stu[j].local_rank = stu[j-1].local_rank; 
			}else{		//�����ǰһλ������ͬ��
				//local_rank Ϊ�ÿ���ǰ������
				stu[j].local_rank = j + 1 - (num - k); 
			}
		} 
	 } 
	 printf("%d", num);		//����ܿ�����
	 sort(stu, stu + num, cmp);		//�����п�������
	 int r = 1;
	 for(int i=0; i<num; i++){
	 	if(i>0 && stu[i].score != stu[i].score){
	 		r = i+1;		//��ǰ��������һ������������ͬʱ����r����Ϊ������ 1 
		 }
		 printf("%s ", stu[i].id);
		 printf("%d %d %d\n", r, stu[i].location_number, stu[i].local_rank);
	 } 
	return 0;
}
