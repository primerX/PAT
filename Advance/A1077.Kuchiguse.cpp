#include<cstdio>
#include<cstring>

int n, minLen = 256, ans = 0;
char s[100][256];	//����100 ���ַ���, ÿ���ַ������� 256 ���ַ� 

int main()
{
	scanf("%d", &n);	//�ַ�������
	getchar();		//���ջ��з�
	for(int i=0; i<n; i++)
	{
		fgets(s[i], 256, stdin);
		int len = strlen(s[i]);
		if(len < minLen) minLen = len;	//ȡ��С����
		for(int j=0; i<len/2; j++){		//��ת�ַ��� s[i], ת��Ϊ�󹫹�ǰ׺ 
			char temp = s[i][j];	//����
			s[i][j] = s[i][len-j-1];
			s[i][len-j-1] = temp; 
		} 
	 }
	for(int i=0; i<minLen; i++){	//�ж������ַ����ĵ� i ���ַ��Ƿ�ȫ�����
		char c = s[0][i];		//ȡ��һ���ַ����ĵ� i ���ַ�
		bool same = true;
		for(int j=1; j<n; j++){		//�ж������ַ����ĵ� i ���ַ��Ƿ����c
			if(c != s[j][i]){		//ֻҪ��һ�����ȣ���ֹͣö�٣�˵������ǰ׺����
				same = false;
				break; 
			} 
		} 
		if(same) ans++;		//�������ַ����ĵ� i λ��ȣ�������� ans �� 1
		else break; 
	}
	if(ans){
		for(int i=ans-1; i>=0; i--){
			printf("%c", s[0][i]);
		}
	}else{
		printf("nai");		//�����ڹ���ǰ׺ 
	}
	return 0;
}
