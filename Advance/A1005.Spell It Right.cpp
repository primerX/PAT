#include<cstdio>
#include<cstring>

char num[10][10] = {	//�����뵥�ʵĶ�Ӧ 
	"zero", "one", "two", "three", "four", "five",
	 "six", "seven", "eight","nine",};
char s[111];	//��ʼ�ַ���
int digit[10];
 
int main()
{
	fgets(s, 111, stdin);
	int len = strlen(s);
	int sum = 0, numLen = 0;	//sum Ϊ s ��λ��֮�ͣ�num ����sum �ĳ���
	for(int i=0; i<len; i++){
		sum += (s[i] - '0');	//�ۼ� s ��λ��,�õ� sum 
	}	
	if(sum == 0) {		//���sumΪ0���������num[0]
		printf("%s", num[0]); 
	}else{
		while(sum != 0) {	//��sum ��ŵ� digit ������
			digit[numLen++] = sum % 10;
			sum /= 10; 
		}
		for(int i = numLen-1; i>=0; i--){	//�Ӹ�λ����λ���digit ���� 
			printf("%s", num[digit[i]]);
			if(i !=0 ) printf(" ");		//���һ������֮��û�пո� 
		}
	} 
	return 0;
}
