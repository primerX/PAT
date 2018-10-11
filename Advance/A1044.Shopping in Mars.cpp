#include<cstdio>

const int N = 100010;
int sum[N];
int n, s, nearS = 10000010;

//upper_bound 函数返回在[L, R) 内第一个大于 x 的位置
upper_bound(int L, int R, int x) 
{
	int left = L, right = R, mid;
	while(left < right)
	{
		mid = (left + right) / 2;
		if(sum[mid] > x){
			right = mid;
		}else{
			left = mid + 1;
		}
	}
	return left;
}

int main()
{
	scanf("%d %d", &n, &s);		//元素个数，值 s
	sum[0] = 0;		//初始化 sum[0] = 0
	for(int i=1; i<=n; i++){
		scanf("%d", sum[i]);
		sum[i] += sum[i-1];
	} 
	for(int i=1; i<=n; i++){	//枚举左端点
		int j = upper_bound(i, n+1, sum[i-1] + s);		//求右端点
		if(sum[j-1] - sum[i-1] == s){		//查找成功(是 j-1 而不是 j)
			nearS = s;			//最接近 s 的值就是 s
			break; 
		}else if(j <= n && sum[j] - sum[i-1] < nearS){
			//存在大于 s 的解并小于 nearS
			nearS = sum[j] - sum[i - 1];		//更新当前 nearS 
		}
	}
	for(int i=1; i<=n; i++){
		int j = upper_bound(i, n+1, sum[i-1] + nearS);	//求右端点
		if(sum[j - 1] - sum[i - 1] == nearS){		//查找成功
			printf("%d-%d\n", i, j-1);			//输出左端点和右端点 
		}	
	}
	return 0;
}
