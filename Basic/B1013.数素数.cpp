#include<cstdio>

const int maxn = 1000001;
int prime[maxn], num = 0;
bool p[maxn] = {0};

void find_prime(int n)
{
	for(int i=2; i<maxn; i++){
		if(p[i] == false){
			prime[num++] = i;
			if(num >= n) break;		//只需要 n 个素数
			for(int j=i+i; j<maxn; j+=i){
				p[j] = true;
			} 
		}
	}
}

int main()
{
	int m, n, count = 0;
	scanf("%d %d", &m, &n);
	find_prime(n);
	for(int i=m; i<=n; i++){	//输出第 m 个素数至第 n 个素数
		printf("%d", prime[i-1]);		//下标从 0 开始
		count++;
		if(count % 10 != 0 && i < n) printf(" "); 
		else printf(" ");
	}
	return 0;
}
