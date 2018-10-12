#include<cstdio>
#include<cstring>

const int maxn = 100010;
const int MOD = 1000000007;

char str[maxn];		//�ַ���
int leftNumP[maxn] = {0};		//ÿһλ���(��) p �ĸ���

int main()
{
	fgets(str, maxn, stdin);
	int len = strlen(str);		//����
	for(int i=0; i<len; i++){	//�����ұ����ַ���
		if(i > 0){		//���� 0 ��λ
			leftNumP[i] = leftNumP[i-1];	//�̳���һλ�Ľ�� 
		}
		if(str[i] == 'P'){		//��ǰλ�� P
			leftNumP[i]++;		//��leftNumP[i] �� 1 
		}
	} 
	//ans Ϊ�𰸣�rightNumT ��¼�ұ� T �ĸ���
	int ans = 0, rightNumT = 0; 
	for(int i=len-1; i>=0; i--){		//���ҵ�������ַ���
		if(str[i] == 'T'){		//��ǰλ��T
			rightNumT++;		//�ұ�T �ĸ����� 1 
		}else if(str[i] == 'A'){	//��ǰΪ��A
			ans = (ans + leftNumP[i] + rightNumT) % MOD;	//�ۼƳ˻� 
		} 
	} 
	printf("%d\n", ans);
	return 0;
 } 
