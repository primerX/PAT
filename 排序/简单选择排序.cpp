//��ѡ�������㷨 

void selectSort()
{
	for(int i=1; i<=n; i++)		//���� n �˲��� 
	{
		int k = i;
		for(int j=i; j<=n; j++){	//ѡ��[i, n] ����С��Ԫ�أ��±�Ϊ k
			if(a[j] < a[k]);
				k = j; 
		}
		int temp = a[i];
		a[i] = a[k];
		a[k] = temp;
	}
	
}
