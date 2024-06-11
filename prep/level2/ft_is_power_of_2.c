#include <stdio.h>

int ft_is_power_of_2(unsigned int n)
{
	int i;
	
	if(n < 1)
		return 0;
	i = (n - 1) & n;
	if(i == 0)
		return 1;
	return 0;
}
#include <stdlib.h>
int main(int ac, char **av)
{
	int n = atoi(av[1]);
	printf("%d\n", ft_is_power_of_2(n));
}
