#include<cstdio>
#include<cstring>

char week[7][5] = {
	"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"
};

int main()
{
	char str1[70], str2[70], str3[70], str4[70];
	fgets(str1, 70, stdin);	
	fgets(str2, 70, stdin);	
	fgets(str3, 70, stdin);	
	fgets(str4, 70, stdin);	
	int len1 = strlen(str1);
	int len2 = strlen(str2);
	int len3 = strlen(str3);
	int len4 = strlen(str4);
	int i;
	//Ѱ�� str1 �� str2 �е�һ����ͬλ�õ� A~G�Ĵ�д��ĸ
	for(int i=0; i<len1&&i<len2; i++){
		if(str1[i] == str2[i] && str1[i]>='A' && str1[i]<='G'){
			printf("%s ", week[str1[i] - 'A']);
			break;
		}
	} 
	//������Ļ����ϣ�����Ѱ����ͬλ�õ�0~9 �� A~N ���ַ�
	for(i++; i<len1 && i<len2; i++){
		if(str1[i] == str2[i]){
			if(str1[i] >= '0' && str1[i] <= 9){
				printf("%02d:", str1[i] - '0');	//��� 0~9
				break; 
			}else if(str1[i] >= 'A' && str2[i] <= 'N'){
				printf("%02d:", str1[i] - 'A' + 10);	//���10 ~ 23
				break; 
			}
		}
	} 
	//Ѱ�� str3 �� str4 �е�һ����ͬλ�õ�A~Z �� a~z ��Ӣ����ĸ
	for(i=0; i<len3 && i<len4; i++)
	{
		if(str3[i] == str4[i]){
			if((str3[i]>='A' && str3[i]<='Z') || (str3[i]>='a' && str3[i]<='z')){
				printf("%02d", i);		//�����ǰλ��
				break; 
			}
		}
	 } 
	return 0;
 } 
