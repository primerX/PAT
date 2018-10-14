#include<cstdio>
#include<iostream>
#include<string>
using namespace std;

int n;		//有效位数

string deal(string s, int& e)
{
	int k = 0;		//s 的下标
	while(s.length() > 0 && s[0] == '0'){
		s.erase(s.begin());		//去除前导 0  
	}
	if(s[0] == '.'){		//取出前导 0 后是小数点，说明 s 是小于1的小数
		s.erase(s.begin());		//取出小数点
		while(s.length() > 0 && s[0] == '0'){
			s.erase(s.begin());		//去掉小数点后非零位前面的 0
			e--;			//每去掉一个 0，指数 e 减一 
		} 
	}else{		//去掉前导 0 后不是小数点，则找到后面的小数点删除
		while(k < s.length() && s[k] != '.'){		//寻找小数点
			e++;		//只要不碰到小数点就让指数e++ 
		}
		if(k < s.length()){		//while 结束后 k<s.lenght() 说明碰到了小数点
			s.erase(s.begin() + k);		//把小数点删除 
		}
	}
	if(s.length() == 0){
		e = 0;			//如果去除掉前导 0 后 s 的长度变为 0，说明这个数为 0 
	}
	int num = 0;
	k = 0;
	string res;
	while(num < n){		//只要精度还没到 n
		if(k < s.length()) res += s[k++];		//只要还有数字就添加到 res 末尾
		else res+= '0';		//否则 res 末尾添加 0
		num++;		//精度加 1 
	}
	return res;
 } 
 
 int main()
 {
 	string s1, s2, s3, s4;
 	cin >> n >> s1 >> s2;
 	int e1 = 0, e2 = 0;			//e1, e2 为 s1, s2 的指数
	s3 = deal(s1, e1);
	s4 = deal(s2, e2);
	if(s3 == s4 && e1 == e2){		//主体相同并且指数相同
		cout << "YES 0." << s3 << "*10^" << e1 << endl; 
	} else{
		cout << "N0 0." << s3 << "*10" << e1 <<" 0." << s4 << "*10^" << e2 << endl;
	}
	return 0;
 }
