#include<cstdio>
#include<algorithm>
using namespace std;

struct Mooncake{
	double store;		//库存量
	double sell;		//总售价
	double price;		//单价 
}cake[1010];

bool cmp(Mooncake a, Mooncake b)
{
	return a.price > b.price;
}

int main()
{
	int n;
	double D;
	scanf("%d %lf", &n, &D);
	for(int i=0; i<n; i++){
		scanf("%d", &cake[i].store);
	}
	for(int i=0; i<n; i++){
		scanf("%d", &cake[i].sell);
		cake[i].price = cake[i].sell / cake[i].store;	//计算单价 
	}
	sort(cake, cake+n, cmp);		//单价从高到低排序
	double ans = 0;				//收益
	for(int i=0; i<n; i++){
		if(cake[i].store <= D){		//如果需求量大于月饼的库存量
			D -= cake[i].store;		//第 i 中月饼全部卖出
			ans += cake[i].sell; 
		}else{		//如果月饼库存量大于需求量 
			ans += cake[i].price * D;		//只卖出剩余需求量的月饼
			break; 
		}
	} 
	printf("%.2f\n", ans);
	return 0;
}
