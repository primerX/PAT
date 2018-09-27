#include<cstdio>
#include<cstring>

const int maxn = 110;
char A[maxn], B[maxn], ans[maxn] = {0};

void reverse(char s[])		//��ת�ַ���
{
	int len = strlen(s);
	for(int i=0; i<len/2; i++){
		int temp = s[i];		//����s[i] �� s[len-i-1]
		s[i] = s[len - i - 1];
		s[len - i - 1] = temp; 
	}
 } 

int main()
{
	scanf("%s %s", &A, &B);
	reverse(A);		//�� A �� B ��ת
	reverse(B);
	int lenA = strlen(A);
	int lenB = strlen(B);
	int len = lenA > lenB ? lenA: lenB;		//A�� B�Ľϴ󳤶� 
	for(int i=0; i<len; i++)		//�ӵ�λ��ʼ
	{
		int numA = i < lenA? A[i] -'0' : 0;	//numA��Ӧ A[i]
		int numB = i < lenB? B[i] -'0' : 0;	//numB��Ӧ B[i] 
		if(i % 2 == 0){
			int temp = (numA + numB) % 13;
			if(temp == 10) ans[i] = 'J';
			else if(temp == 11) ans[i] = 'Q';
			else if(temp == 12) ans[i] = 'K';
			else ans[i] = temp + '0';
		}else{
			int temp = numB - numA;
			if(temp < 0) temp += 10;
			ans[i] = temp + '0';	//����Ӧ���ַ� 
		}
	 } 
	 reverse(ans);	//��ת����ַ�
	 puts(ans);		//������ 
	return 0;
}
