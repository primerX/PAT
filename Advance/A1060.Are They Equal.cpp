#include<cstdio>
#include<iostream>
#include<string>
using namespace std;

int n;		//��Чλ��

string deal(string s, int& e)
{
	int k = 0;		//s ���±�
	while(s.length() > 0 && s[0] == '0'){
		s.erase(s.begin());		//ȥ��ǰ�� 0  
	}
	if(s[0] == '.'){		//ȡ��ǰ�� 0 ����С���㣬˵�� s ��С��1��С��
		s.erase(s.begin());		//ȡ��С����
		while(s.length() > 0 && s[0] == '0'){
			s.erase(s.begin());		//ȥ��С��������λǰ��� 0
			e--;			//ÿȥ��һ�� 0��ָ�� e ��һ 
		} 
	}else{		//ȥ��ǰ�� 0 ����С���㣬���ҵ������С����ɾ��
		while(k < s.length() && s[k] != '.'){		//Ѱ��С����
			e++;		//ֻҪ������С�������ָ��e++ 
		}
		if(k < s.length()){		//while ������ k<s.lenght() ˵��������С����
			s.erase(s.begin() + k);		//��С����ɾ�� 
		}
	}
	if(s.length() == 0){
		e = 0;			//���ȥ����ǰ�� 0 �� s �ĳ��ȱ�Ϊ 0��˵�������Ϊ 0 
	}
	int num = 0;
	k = 0;
	string res;
	while(num < n){		//ֻҪ���Ȼ�û�� n
		if(k < s.length()) res += s[k++];		//ֻҪ�������־���ӵ� res ĩβ
		else res+= '0';		//���� res ĩβ��� 0
		num++;		//���ȼ� 1 
	}
	return res;
 } 
 
 int main()
 {
 	string s1, s2, s3, s4;
 	cin >> n >> s1 >> s2;
 	int e1 = 0, e2 = 0;			//e1, e2 Ϊ s1, s2 ��ָ��
	s3 = deal(s1, e1);
	s4 = deal(s2, e2);
	if(s3 == s4 && e1 == e2){		//������ͬ����ָ����ͬ
		cout << "YES 0." << s3 << "*10^" << e1 << endl; 
	} else{
		cout << "N0 0." << s3 << "*10" << e1 <<" 0." << s4 << "*10^" << e2 << endl;
	}
	return 0;
 }
