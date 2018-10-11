#include<cstdio>
#include<algorithm>
using namespace std;

const int maxn = 100010;
int n, p, a[maxn];

//binarySearch 函数在[i+1, n-1]范围内查找第一个大于 x 的数的位置
int binarySearch(int i, long long x)
{
	if(a[n-1] <= x) return n;		//如果所有数都不大于 x，返回 n
	int left = i + 1, right = n - 1, mid;		//在[i+1, n-1]内查找
	while(left < right){
		mid = (left + right) / 2;
		if(a[mid] <= x){		//若a[mid] <= x 说明第一个大于 x 的数只能在 mid 后面
			left = mid + 1; 
		}else{					//若a[mid]>x 说明第一个大于 x 的数在mid之前(含mid)
			right = mid; 
		}
	} 
	return left;
}

int main()
{
	scanf("%d %d", &n, &p);
	for(int i=0; i<n; i++){
		scanf("%d", &a[i]);
	}
	sort(a, a + n);			//递增排序
	int ans = 1;			//最大长度，初值为 1 表示至少有一个数
	for(int i=0; i<n; i++){
		//在 a[i]~a[n-1] 中查找第一个超过 a[i] * p 的数，返回其位置给 j
		int j = binarySearch(i, (long long)a[i] * p);
		ans = max(ans, j - i);		//更新最大长度	 
	} 
	printf("%d\n", ans);
	return 0;
}
