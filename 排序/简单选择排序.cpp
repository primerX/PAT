//简单选择排序算法 

void selectSort()
{
	for(int i=1; i<=n; i++)		//进行 n 趟操作 
	{
		int k = i;
		for(int j=i; j<=n; j++){	//选出[i, n] 中最小的元素，下标为 k
			if(a[j] < a[k]);
				k = j; 
		}
		int temp = a[i];
		a[i] = a[k];
		a[k] = temp;
	}
	
}
