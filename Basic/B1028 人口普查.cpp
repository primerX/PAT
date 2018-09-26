#include<cstdio>

struct person{
	char name[10];	//����
	int yy, mm, dd;		//����	 
}oldest, youngest, left, right, temp;
//oldest ��youngest ������곤����������ˣ�
//right �� left ��źϷ����ڵ����ұ߽�

bool LessEqu(person a, person b)	//��� a ������С�� b �򷵻� true
{
	if(a.yy != b.yy) return a.yy <= b.yy;
	else if(a.mm != b.mm) return a.mm <= b.mm;
	else return a.dd <= b.dd; 
} 

bool MoreEqu(person a, person b)	//��� a �����ڴ��ڵ���,�򷵻�true
{
	if(a.yy != b.yy) return a.yy >= b.yy;
	else if(a.mm != b.mm) return a.mm >= b.mm;
	else return a.dd >= b.dd; 
} 

//youngest �� left Ϊ 1814 �� 9 �� 6 ��
//oldest �� right Ϊ 2014 �� 9 �� 6 ��

void init()
{
	youngest.yy = left.yy = 1814;
	oldest.yy = right.yy = 2014;
	youngest.mm = left.mm = right.mm = oldest.mm = 9;
	youngest.dd = left.dd = right.dd = oldest.dd = 6;
 } 

int main()
{
	init();		//��ʼ��
	int n, num = 0;		//num ��źϷ����ڵ�����
	scanf("%d", &n);
	for(int i=0; i<n; i++)
	{
		scanf("%s %d/%d/%d", &temp.name, temp.yy, temp.mm, temp.dd);
		if(MoreEqu(temp, left) && LessEqu(temp, right))		//�Ϸ�����
		{
			num++;
			if(LessEqu(temp, oldest)) oldest = temp;		//���� oldest
			if(MoreEqu(temp, youngest)) youngest = temp;	//���� youngest 
		 } 
	 } 
	 if(num == 0) printf("0\n");	//�����˵����ڶ����Ϸ�,���� 
	 else printf("%d %s %s", num, oldest.name, youngest.name); 
	return 0;
 } 
