#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

struct Student{
	char id[15];		//׼��֤��
	int score;			//����
	int location_number;	//������
	int local_rank;		//���������� 
}stu[30010];

bool cmp(Student a, Student b)
{
	if(a.score != b.score) return a.score > b.score;	//�Ȱ������Ӹߵ�������
	else return strcmp(a.id, b.id) < 0;		//������ͬ,��׼��������С�������� 
}

int main()
{
	int n, k, num = 0;		//num Ϊ�ܿ�����
	scanf("%d", &n);		//n Ϊ������
	for(int i=0; i<n; i++)
	{
		scanf("%d", &k);	//�����ڵ����� 
		for(int j=0; j<k; j++){
			scanf("%s %d", &stu[num].id, &stu[num].score);
			stu[num].location_number = i;		//�ÿ����Ŀ�����Ϊ i
			num++;			//�ܿ�������1 
		}
		sort(stu + num - k, stu + num, cmp);		//���ÿ����Ŀ�������
		stu[num - k].local_rank = 1;			//�ÿ�����һ����local_rankΪ 1
		for(int j = num - k + 1; j<num; j++)	//�Ըÿ���ʣ���ѧ�� 
		{
			if(stu[j].score == stu[j-1].score){		//�����ǰһλ������ͬ
				stu[j].local_rank = stu[j-1].local_rank;	//local_rankҲ��ͬ 
			}else{			//�����ǰһλ������ͬ��local_rankΪ�ÿ���ǰ������ 
				stu[j].local_rank = j + 1 - (num - k);
			}
		 } 
	 } 
	 printf("%d\n", num);			//����ܿ�����
	 sort(stu, stu + num, cmp);		//�����п�������
	 int r = 1;					//��ǰ����������
	 for(int i=0; i<num; i++){
	 	if(i > 0 && stu[i].score != stu[i-1].score){
	 		r = i + 1;		//��ǰ��������һ������������ͬʱ,��r����Ϊ����+1 
		 }
		 printf("%s ", stu[i].id);
		 printf("%d %d %d\n", r, stu[i].location_number, stu[i].local_rank);
	 } 
	return 0;
}
