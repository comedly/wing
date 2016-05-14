#include<iostream>
using namespace std;

//常规解法
//令数字最右边的一位与运算上1，判断最右一位是否为1，是，计数器加1，右移一位，反之只需右移，
//但是当输入一个负数时，程序就会陷入死循环
int NumberOf1_1(int n)
{
	int count = 0;
	while (n)
	{
		if(n & 1)
			count++;
		n = n >> 1;
	}
	return count;
}

//可避免死循环
//输入的数字不变，先令n与1位运算，判断是否为1，再令1左移，与之判断
//但此种方法，循环次数为整数的二进制位数，32位的整数系统中需要循环32，显然不优
int NumberOf1_2(int n)
{
	unsigned int flag = 1;
	int count = 0;
	while (flag)
	{
		if(n & flag)
			count++;
		flag = flag << 1;
	}
	return count;
}

//此种方法既避免了死循环，还可减少循环的次数即一个整数中有几个1就循环几次
//总结起来就是;把一个整数减去1，再和原来的整数位与运算，就把该整数最右边的一个1变为0了，一个整数中有几个1就可以进行多少次这样的操作

int NumberOf1_3(int n)
{
	int count = 0;
	while (n)
	{
		count++;
		n = n & (n-1);
	}
	return count;
}

int main()
{
	int n = 0;
	n = NumberOf1_1(15);
	cout<<n<<endl;
	n = NumberOf1_2(15);
	cout<<n<<endl;
	n = NumberOf1_3(15);
	cout<<n<<endl;
	system("pause");
	return 0;
}