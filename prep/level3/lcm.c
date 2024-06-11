#include <stdio.h>
#include <stdlib.h>
unsigned int pgcd(unsigned int a, unsigned int b)
{
	unsigned int big;
	unsigned int small;
	unsigned int rest;
	unsigned int buff;
	if(a == 0)
		return b;
	else if( b == 0)
		return a;
	if(a > b)
	{
		big = a;
		small = b;
	}
	else
	{
		big = b;
		small = a;
	}
	while(small != 0)
	{
		buff = big / small;
		rest = big - buff * small;
		if(rest == 0)
			break;
		big = small;
		small = rest;
	}
	return small;
}

unsigned int lcm(unsigned int a, unsigned int b)
{
	if(a == 0 || b == 0)
		return 0;
	unsigned int lc = a * b;
	if (lc < 0)
		lc *= -1;
	lc /= pgcd(a, b);
	return lc;
}

int main(int ac, char **av)
{
	if(ac == 3)
	{
		int a = atoi(av[1]);
		int b = atoi(av[2]);
		int pgd = pgcd(a, b);
		int lc = lcm(a, b);
		printf("%d", pgd);
		printf("\n%d", lc);
	}
	printf("\n");
}
