#include <iostream>

void f1(int n, int cur_n=1);
void f2(int n1, int n2);
int f3(int n, int sum=1);
int f4(int n, bool start = true);

int main()
{
	std::cout << "Numbers from 1 to N (6):\n";
	f1(6);

	std::cout << "Numbers from A to B (8, 13):\n";
	f2(8, 13);

	std::cout << "\nLenght of number (45554):\n" << f3(44554) << std::endl;

	std::cout << "Simple delimeters (14):" << std::endl;
	f4(14);
	
}



int f4(int n, bool start)
{
	int cnt_delimeters = 0;
	for (int i = 1; i < n; ++i)
	{
			if (n % i == 0)
			{	cnt_delimeters++;
				if (start && f4(i, false) == 1) std::cout << i << std::endl;
			}
	}
	return cnt_delimeters;
}


int f3(int n, int sum)
{
	if (n / 10 > 0)
	{
		f3(n / 10, ++sum);
	}
	else return sum;
}

void f2(int n1, int n2)
{
	if (n1 < n2)
	{
		std::cout << n1++ << std::endl;
		f2(n1, n2);
	}
	else if (n1 > n2)
	{
		std::cout << n1-- << std::endl;
		f2(n1, n2);
	}
	else std::cout << n1;
}
void f1(int n, int cur_n) 
{
	if (cur_n <= n)
	{
		std::cout << cur_n++ << std::endl;
		f1(n, cur_n);
	}
}