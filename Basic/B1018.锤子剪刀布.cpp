#include<cstdio>

int change(char c)		//B为0，c为1，J为2，恰好是循环相克，且字典序递增 
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
	int time_A[3] = {0}, time_B[3] = {0};		//分别记录甲乙的胜负平的次数
	//按BCJ 顺序分别记录甲乙三种手势的获胜次数
	int hand_A[3] = {0}, hand_B[3] = {0};
	char c1, c2;
	int k1, k2;
	for(int i=0; i<n; i++)
	{
		getchar();		//吸收空格
		scanf("%c %c", &c1, &c2);		//甲，乙的手势
		k1 = change(c1);
		k2 = change(c2);
		if((k1 + 1) % 3 == k2){		//如果甲赢 
			time_A[0]++;		//甲赢的次数加1
			time_B[2]++;		//已输的次数加1
			hand_A[k1]++;		//甲考 k1 赢的次数加1 
		} else if(k1 == k2){		//平局
			time_A[1]++;
			time_B[2]++; 
		}else{				//如果已赢
			time_A[2]++;		//甲负的次数加1
			time_B[0]++;		//已赢的次数加1
			hand_B[k2]++;		//已靠 k2 赢的次数加1 
		}
	 } 
	 printf("%d %d %d\n", time_A[0], time_A[1], time_A[2]);
	 printf("%d %d %d\n", time_B[0], time_B[1], time_B[2]);
	 int id1 = 0, id2 = 0;
	 //找出甲乙获胜次数最多的手势
	 for(int i=0; i<3; i++){
	 	if(hand_A[i] > id1) id1 = i;
	 	if(hand_B[i] > id2) id2 = i;
	 }
	 printf("%c %c", mp[id1], mp[id2]);		//转变回BCJ 
	return 0;
}
