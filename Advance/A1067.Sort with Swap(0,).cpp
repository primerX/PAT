#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn = 100010;
int pos[maxn];		//存放个数字当前所处的位置编号

int main()
{
	int n, ans = 0;		//ans 表示总交换次数
	scanf("%d", &n);
	int left = n - 1, num;	//left 存放除 0 之外的不在本位上的数的个数
	for(int i=0; i<n; i++){
		scanf("%d", &num);
		pos[num] = i;		//num 所处为位置为 i
		if(num == i && num != 0){		//如果除 0 以外有在本位上的数
			left--; 
		} 
	} 
	int k = 1;		//k 存放除 0 以外当前不在本位上的最小的数
	while(left > 0){		//只要还有数不在本位上
		//如果 0 在本位上，则寻找一个不在本地上的数与 0 交换
		if(pos[0] == 0){
			while(k < n){
				if(pos[k] != k){		//找到一个当前不在本位上的数 k
					swap(pos[0], pos[k]);	//将 k 和 0 交换位置
					ans++;			//交换次数加 1
					break; 
				}
				k++;		//判断 K + 1 是否在本位 
			} 	
		} 
		//只要 0 不在本位，就将 0 所在位置的数的当前位置与 0 的位置交换
		while(pos[0] != 0){
			swap(pos[0], pos[pos[0]]);		//将 0 与 pos[0] 交换
			ans++;		//交换次数加 1
			left--;		//不在本位数上的数的个数减一 
		} 
	}
	printf("%d\n", ans); 
	return 0;
 } 
