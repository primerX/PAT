#include<cstdio>

int main()
{
	int n;
	scanf("%d", &n);
	int num = 0, ans[5];	//num ��� n ��λ��
	do{
		ans[num++] = n % 10;
		n /= 10;
	}while(n != 0);
	for(int i=num-1; i>=0; i--)		//�Ӹ�λ����λö��
	{
		if(i == 2)		// i �ǰ�λ
		{
			for(int j=0; j<ans[i]; j++) printf("B");	//���ans[i]��B 
		} 
		else if(i == 1)		//�����ʮλ
		{
			for(int j=0; j<ans[i]; j++) printf("S");	//���ans[i]��S 
		 }else{		//����Ǹ�λ 
		 	for(int j=1; j<=ans[i]; j++) printf("%d", j);
		 } 
	 } 
	return 0;
}
