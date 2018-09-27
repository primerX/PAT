#include<cstdio>
#include<cstring>

struct node{
	char name[20], password[20];
	bool ischange;	//ischange == true 表示 password 已经被修改 
}T[1005];

//cypt 函数判断 t 的password 是否需要被修改，若需要
//则对其进行修改并令计数器 cnt++ 
void crypt(node& t, int& cnt)
{
	int len = strlen(t.password);
	for(int i=0; i<len; i++){	//枚举 password 的每一位
		if(t.password[i] == '1'){
			t.password[i] = '@';
			t.ischange = true;
		} else if(t.password[i] == '0'){
			t.password[i] = '%';
			t.ischange = true;
		}else if(t.password[i] == 'l'){		//小写字母 l
			t.password[i] = 'L';
			t.ischange = true; 
		}else if(t.password[i] == 'O'){	//大写字母 O
			t.password[i] = 'o';
			t.ischange = true; 
		}
	}
	if(t.ischange){		//如果 t 的password 已被修改，则令计数器加 1
		cnt++; 
	}
} 

int main()
{
	int n, cnt = 0;		//cnt 记录需要修改的 password 的个数 
	scanf("%d", &n);
	for(int i=0; i<n; i++){
		scanf("%s %s", &T[i].name, &T[i].password);
		T[i].ischange = false;		//初始化所有密码都没有修改 
	}
	for(int i=0; i<n; i++){
		crypt(T[i], cnt);	//对 T[i] 的password 判断是否需要修改 
	}
	if(cnt == 0)	//没有password 需要修改
	{
		if(n == 1){
			printf("There is %d account and no account is modified\n", n);
		}else{
			printf("There are %d account and no account is modified\n", n);
		}
	 }else{		//有password 需要修改 
	 	printf("%d\n", cnt);	//个数
		for(int i=0; i<n; i++){
			//如果T[i] 的password 需要修改,则输出 name 和 password
			if(T[i].ischange){
				printf("%s %s\n", T[i].name, T[i].password);
			} 
		} 
	 } 
}
