#include<cstdio>
#include<algorithm>
using namespace std;

const int N = 111;
int origin[N], tempOri[N], changed[N];		//原始数据,原始数据备份,目标数组
int n;		//元素个数

bool isSame(int A[], int B[]){		//判断A 数组是否与 B数组相同
	for(int i=0; i<n; i++){
		if(A[i] != B[i]){
			return false;
		}
	} 
	return true;
}

bool showArray(int A[]){		//输出数组
	for(int i=0; i<n; i++){
		printf("%d", A[i]);
		if(i < n-1) printf(" ");
	} 
	printf("\n");
}

bool insertSort()		//插入排序
{
	bool flag = false;		//记录是否存在数组中间步骤与changed数组相同
	for(int i=1; i<n; i++){		//进行 n-1 趟排序 
		if(i != 1 && isSame(tempOri, changed)){
			//中间步骤与目标相同，且不是初始序列
			flag = true; 
		}
		//以下为插入部分
		int temp = tempOri[i], j = 1;
		while(j > 0 && tempOri[j-1] > temp){
			tempOri[j] = tempOri[j-1];
			j--;
		}
		tempOri[j] = temp;
		if(flag == true){
			return true;		//如果 flag 为 true,则说明已经达到目标数组 
		}
	} 
	return false;
 }
 
void mergeSort(){			//归并排序 
	bool flag = false;		//记录是否存在数组中间步骤与changed数组相同
	//以下为归并排序部分
	for(int step=2; step/2 <= n; step *= 2){
		if(step != 2 && isSame(tempOri, changed)){
			//中间步骤与目标步骤相同，且不是初始序列
			flag = true; 
		}
		for(int i=0; i<n; i+=step){
			sort(tempOri+i, tempOri+min(step+i, n));
		}
		if(flag == true){		//已经到达目标数组，输出tempOri数组
			showArray(tempOri);
			return; 
		}
	}
}

int main()
{
	scanf("%d", &n);
	for(int i=0; i<n; i++){
		scanf("%d", &origin[i]);		//输入起始数组
		tempOri[i] = origin[i];			//tempOri数组为备份，排序过程在此数组进行 
	}
	for(int i=0; i<n; i++){
		scanf("%d", changed[i]);		//目标数组 
	}
	if( insertSort() ){			//如果插入排序中找到目标数组
		printf("Insertion Sort\n");
		showArray(tempOri); 
	}else{			//否则为归并排序
		printf("Merge Sort\n");
		for(int i=0; i<n; i++){
			tempOri[i] = origin[i];		//还原tempOri数组 
		}
		mergeSort();		//归并排序 
	}
	return 0;
}
