#include<cstdio>
#include<cstring>

struct node{
	char name[20], password[20];
	bool ischange;	//ischange == true ��ʾ password �Ѿ����޸� 
}T[1005];

//cypt �����ж� t ��password �Ƿ���Ҫ���޸ģ�����Ҫ
//���������޸Ĳ�������� cnt++ 
void crypt(node& t, int& cnt)
{
	int len = strlen(t.password);
	for(int i=0; i<len; i++){	//ö�� password ��ÿһλ
		if(t.password[i] == '1'){
			t.password[i] = '@';
			t.ischange = true;
		} else if(t.password[i] == '0'){
			t.password[i] = '%';
			t.ischange = true;
		}else if(t.password[i] == 'l'){		//Сд��ĸ l
			t.password[i] = 'L';
			t.ischange = true; 
		}else if(t.password[i] == 'O'){	//��д��ĸ O
			t.password[i] = 'o';
			t.ischange = true; 
		}
	}
	if(t.ischange){		//��� t ��password �ѱ��޸ģ������������ 1
		cnt++; 
	}
} 

int main()
{
	int n, cnt = 0;		//cnt ��¼��Ҫ�޸ĵ� password �ĸ��� 
	scanf("%d", &n);
	for(int i=0; i<n; i++){
		scanf("%s %s", &T[i].name, &T[i].password);
		T[i].ischange = false;		//��ʼ���������붼û���޸� 
	}
	for(int i=0; i<n; i++){
		crypt(T[i], cnt);	//�� T[i] ��password �ж��Ƿ���Ҫ�޸� 
	}
	if(cnt == 0)	//û��password ��Ҫ�޸�
	{
		if(n == 1){
			printf("There is %d account and no account is modified\n", n);
		}else{
			printf("There are %d account and no account is modified\n", n);
		}
	 }else{		//��password ��Ҫ�޸� 
	 	printf("%d\n", cnt);	//����
		for(int i=0; i<n; i++){
			//���T[i] ��password ��Ҫ�޸�,����� name �� password
			if(T[i].ischange){
				printf("%s %s\n", T[i].name, T[i].password);
			} 
		} 
	 } 
}
