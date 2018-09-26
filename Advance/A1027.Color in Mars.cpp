#include<cstdio>

char radix[13] = {		//建立0~13 与'0'~'9' 'A', 'B', 'C'的关系 
	'0', '1', '2', '3', '4', '5', '6', '7', '8', '9','A', 'B', 'C'
};

int main()
{
	int r, g, b;
	scanf("%d %d %d", &r, &g, &b);
	printf("#");
	//输出radix[a] 与 radix[b]
	printf("%c%c", radix[r/13], radix[r%13]);
	printf("%c%c", radix[g/13], radix[g%13]);
	printf("%c%c", radix[b/13], radix[b%13]); 
	return 0;
}
