#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int maxn = 100010;
struct Student{
	int id;		//׼��֤��
	char name[10];		//����
	int score;		//���� 
}stu[maxn];

bool cmp1(Student a, Student b)
{
	return a.id < b.id;
}

bool cmp2(Student a, Student b)
{
	int s = strcmp(a.name, b.name);
	if(s != 0) return s < 0;		//��������ͬ���������ֵ����С���� 
	else{
		return a.id < b.id;		//������ͬ����׼��֤�Ŵ�С�������� 
	}
}

bool cmp3(Student a, Student b)
{
	if(a.score != b.score)	return a.score < b.score;	//������ͬ������С����
	else return a.id < b.id;		//������ͬ����׼��֤�Ŵ�С���� 
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
