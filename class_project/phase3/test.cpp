#include <iostream>
int main(int argc, char ** argv)
{
	int a = 0;
	int b = 0;
	
	b = a + (a++);
	std::cout << b;
	return 0;
}
