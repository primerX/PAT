#include<cstdio>

int change(char c)		//BΪ0��cΪ1��JΪ2��ǡ����ѭ����ˣ����ֵ������ 
{
	if(c == 'B') return 0;
	if(c == 'C') return 1;
	if(c == 'J') return 2; 
}

int main()
{
	char mp[3] = {'B', 'C', 'J'};
	int n;
	scanf("%d", &n);
	int time_A[3] = {0}, time_B[3] = {0};		//�ֱ��¼���ҵ�ʤ��ƽ�Ĵ���
	//��BCJ ˳��ֱ��¼�����������ƵĻ�ʤ����
	int hand_A[3] = {0}, hand_B[3] = {0};
	char c1, c2;
	int k1, k2;
	for(int i=0; i<n; i++)
	{
		getchar();		//���տո�
		scanf("%c %c", &c1, &c2);		//�ף��ҵ�����
		k1 = change(c1);
		k2 = change(c2);
		if((k1 + 1) % 3 == k2){		//�����Ӯ 
			time_A[0]++;		//��Ӯ�Ĵ�����1
			time_B[2]++;		//����Ĵ�����1
			hand_A[k1]++;		//�׿� k1 Ӯ�Ĵ�����1 
		} else if(k1 == k2){		//ƽ��
			time_A[1]++;
			time_B[2]++; 
		}else{				//�����Ӯ
			time_A[2]++;		//�׸��Ĵ�����1
			time_B[0]++;		//��Ӯ�Ĵ�����1
			hand_B[k2]++;		//�ѿ� k2 Ӯ�Ĵ�����1 
		}
	 } 
	 printf("%d %d %d\n", time_A[0], time_A[1], time_A[2]);
	 printf("%d %d %d\n", time_B[0], time_B[1], time_B[2]);
	 int id1 = 0, id2 = 0;
	 //�ҳ����һ�ʤ������������
	 for(int i=0; i<3; i++){
	 	if(hand_A[i] > id1) id1 = i;
	 	if(hand_B[i] > id2) id2 = i;
	 }
	 printf("%c %c", mp[id1], mp[id2]);		//ת���BCJ 
	return 0;
}
