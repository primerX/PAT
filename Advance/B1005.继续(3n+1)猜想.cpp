#include<cstdio>
#include<algorithm>
using namespace std;

bool cmp(int a, int b)
{
	return a > b;
}

int main()
{
	int n, m, a[110];
	scanf("%d", &n);
	bool hashTable[10000] = {0};		//hashTable[x] == true 表示 x 被覆盖 
	for(int i=0; i<n; i++){
		scanf("%d", &a[i]);
		m = a[i];
		while(m != 1){		//进行 3n + 1 猜想
			if(m % 2 == 1) m = (3 * m + 1) / 2;
			else m /= 2;
			hashTable[m] = true;		//将被覆盖的数的flag 设置为 true 
		}
	}
	int count = 0;		// count 用来表示"关键数"的个数
	for(int i=0; i<n; i++){
		if(hashTable[a[i]] == false){		//没有被覆盖
			count++; 
		}
	} 
	sort(a, a + n, cmp);		//从大到小排序
	for(int i=0; i<n; i++){
		if(hashTable[a[i]] == false){
			printf("%d", a[i]);
			count--;
			if(count > 0) printf(" ");
		}
	} 
}
