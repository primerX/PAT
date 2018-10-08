#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int maxn = 10010;

int Age[maxn] = {0};		//ĳ��������� 
struct Person{
	int age, worth;		//���䣬�Ƹ�ֵ
	char name[10];		//���� 
}ps[maxn], valid[maxn];		//�����ˣ��ڸ��������вƸ�ֵ��100���ڵ���

bool cmp(Person a, Person b)
{
	if(a.worth != b.worth) return a.worth > b.worth;	//�Ƹ�ֵ�Ӵ�С���� 
	else if(a.age != b.age) return a.age < b.age;		//�����С��������
	else strcmp(a.name, b.name) < 0;		//�������ֵ����С�������� 
 } 
 
int main()
{
	int n, k;
	scanf("%d %d", &n, &k);		//����������ѯ����
	for(int i=0; i<n; i++)
	{
		scanf("%s %d %d", &ps[i].name, &ps[i].age, &ps[i].worth);
	}
	sort(ps, ps+n, cmp);		//����
	int validNum = 0;			//��ŵ� valid �����е�����
	for(int i=0; i<n; i++)
	{
		if(Age[ps[i].age] < 100){		//����ps[i].age������С�� 100 ʱ
			Age[ps[i].age]++;	 		//����ps[i].age�������� 1 
			valid[validNum++] = ps[i];	//��ps[i] ������������ 
		}	
	} 
	int m, ageL, ageR;
	for(int i=1; i<=k; i++){
		scanf("%d %d %d", &m, &ageL, &ageR);	// ǰ M �ˣ��������� 
		printf("Case #%d:\n", i);
		int printNum = 0;		//�����������
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
