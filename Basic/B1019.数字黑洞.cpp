#include<cstdio>
#include<algorithm>
using namespace std;

bool cmp(int a, int b){		//从大到小排序
	return a > b; 
}

void to_array(int n, int num[]){		//将 n 的每一位数字存到 num 数组中
	for(int i=0; i<4; i++){
		num[i] = n % 10;
		n /= 10;
	}
}

int to_number(int num[]){		//将 num 数组转变成数字
	int sum = 0;
	for(int i=0; i<4; i++){
		sum = sum * 10 + num[i];
	} 
	return sum;
}

int main()
{
	// MIN 与 MAX 分别表示递增排序和递减排序的最小值和最大值
	int n, MAX, MIN;
	scanf("%d", &n);
	int num[5];
	while(1){
		to_array(n, num);		//将 n 转换成数组
		sort(num, num+4);		//对 num 数组中的元素从小到大排序
		MIN = to_number(num);	//获取最小值
		sort(num, num+4, cmp);	//对 num 数组中的元素从大到小排序
		MAX = to_number(num);	//获取最小值
		n = MAX - MIN;		//得到下一个数
		printf("%04d - %04d = %04d\n", MAX, MIN, n);
		if(n == 0|| n == 6147) break;		 
	} 
}
