#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;

struct PNode{
	char id[20];
	int hh, mm, ss;
}temp, ans1, ans2;
//ans1 �������ǩ��ʱ��, ans2�������ǩ��ʱ��

//node1 ��ʱ����� node2 ��ʱ�䷵�� true 
bool great(PNode node1, PNode node2)	
{
	if(node1.hh != node2.hh) return node1.hh > node2.hh;
	else if(node1.mm != node2.mm) return node1.mm > node2.mm;
	else return node1.ss > node2.ss;
} 

int main()
{
	int n;
	scanf("%d", &n);
	ans1.hh = 24, ans1.mm = 60, ans1.ss = 60;	//�ѳ�ʼǩ��ʱ��������
	ans2.hh = 0, ans2.mm = 0, ans2.ss = 0;		//�ѳ�ʼǩ��ʱ�������С
	for(int i=0; i<n; i++)
	{
		//�ȶ���ǩ��ʱ��
		scanf("%s %d:%d:%d", &temp.id, &temp.hh, &temp.mm, &temp.ss);
		if(great(temp, ans1) == false) ans1 = temp;		//ans1ȥ��С��ʱ��
		//temp ����Ϊǩ��ʱ�����
		scanf("%d:%d:%d", &temp.hh, &temp.mm, &temp.ss);
		if(great(temp, ans2) == true) ans2 = temp;		//ans2ȡ�����ʱ�� 
	 } 
	printf("%s %s", ans1.id, ans2.id); 
	return 0;
 } 
