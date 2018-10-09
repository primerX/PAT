#include<cstdio>
#include<algorithm>
using namespace std;

const int N = 1005;
int hashTable[N];

int main()
{
	int n, m, a;
	scanf("%d %d", &n, &m);
	for(int i=0; i<n; i++){
		scanf("%d", &a);
		hashTable[a]++;
	}
	for(int i=1; i<=m; i++){
		if(hashTable[i] && hashTable[m - i]){
			if(i == m - 1 && hashTable[i] <= 1){
				continue;
			}
			printf("%d %d", i, m - i);
			return 0;
		}
	}
	printf("No solution\n");
	return 0;
}
