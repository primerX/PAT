#include<cstdio>
#include<algorithm>
using namespace std;

bool cmp(int a, int b){		//�Ӵ�С����
	return a > b; 
}

void to_array(int n, int num[]){		//�� n ��ÿһλ���ִ浽 num ������
	for(int i=0; i<4; i++){
		num[i] = n % 10;
		n /= 10;
	}
}

int to_number(int num[]){		//�� num ����ת�������
	int sum = 0;
	for(int i=0; i<4; i++){
		sum = sum * 10 + num[i];
	} 
	return sum;
}

int main()
{
	// MIN �� MAX �ֱ��ʾ��������͵ݼ��������Сֵ�����ֵ
	int n, MAX, MIN;
	scanf("%d", &n);
	int num[5];
	while(1){
		to_array(n, num);		//�� n ת��������
		sort(num, num+4);		//�� num �����е�Ԫ�ش�С��������
		MIN = to_number(num);	//��ȡ��Сֵ
		sort(num, num+4, cmp);	//�� num �����е�Ԫ�شӴ�С����
		MAX = to_number(num);	//��ȡ��Сֵ
		n = MAX - MIN;		//�õ���һ����
		printf("%04d - %04d = %04d\n", MAX, MIN, n);
		if(n == 0|| n == 6147) break;		 
	} 
}
