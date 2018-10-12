#include<cstdio>
#include<algorithm>
using namespace std;

const int N = 111;
int origin[N], tempOri[N], changed[N];		//ԭʼ����,ԭʼ���ݱ���,Ŀ������
int n;		//Ԫ�ظ���

bool isSame(int A[], int B[]){		//�ж�A �����Ƿ��� B������ͬ
	for(int i=0; i<n; i++){
		if(A[i] != B[i]){
			return false;
		}
	} 
	return true;
}

bool showArray(int A[]){		//�������
	for(int i=0; i<n; i++){
		printf("%d", A[i]);
		if(i < n-1) printf(" ");
	} 
	printf("\n");
}

bool insertSort()		//��������
{
	bool flag = false;		//��¼�Ƿ���������м䲽����changed������ͬ
	for(int i=1; i<n; i++){		//���� n-1 ������ 
		if(i != 1 && isSame(tempOri, changed)){
			//�м䲽����Ŀ����ͬ���Ҳ��ǳ�ʼ����
			flag = true; 
		}
		//����Ϊ���벿��
		int temp = tempOri[i], j = 1;
		while(j > 0 && tempOri[j-1] > temp){
			tempOri[j] = tempOri[j-1];
			j--;
		}
		tempOri[j] = temp;
		if(flag == true){
			return true;		//��� flag Ϊ true,��˵���Ѿ��ﵽĿ������ 
		}
	} 
	return false;
 }
 
void mergeSort(){			//�鲢���� 
	bool flag = false;		//��¼�Ƿ���������м䲽����changed������ͬ
	//����Ϊ�鲢���򲿷�
	for(int step=2; step/2 <= n; step *= 2){
		if(step != 2 && isSame(tempOri, changed)){
			//�м䲽����Ŀ�경����ͬ���Ҳ��ǳ�ʼ����
			flag = true; 
		}
		for(int i=0; i<n; i+=step){
			sort(tempOri+i, tempOri+min(step+i, n));
		}
		if(flag == true){		//�Ѿ�����Ŀ�����飬���tempOri����
			showArray(tempOri);
			return; 
		}
	}
}

int main()
{
	scanf("%d", &n);
	for(int i=0; i<n; i++){
		scanf("%d", &origin[i]);		//������ʼ����
		tempOri[i] = origin[i];			//tempOri����Ϊ���ݣ���������ڴ�������� 
	}
	for(int i=0; i<n; i++){
		scanf("%d", changed[i]);		//Ŀ������ 
	}
	if( insertSort() ){			//��������������ҵ�Ŀ������
		printf("Insertion Sort\n");
		showArray(tempOri); 
	}else{			//����Ϊ�鲢����
		printf("Merge Sort\n");
		for(int i=0; i<n; i++){
			tempOri[i] = origin[i];		//��ԭtempOri���� 
		}
		mergeSort();		//�鲢���� 
	}
	return 0;
}
