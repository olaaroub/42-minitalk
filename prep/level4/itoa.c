#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int	count_digs(int n)
{
	int neg = 0;
	int i = 0;
	if(n == 0)
		return 1;
	if(n < 0)
		neg = 1;
	while(n != 0)
	{
		n /= 10;
		i++;
	}
	return i + neg;
}

char	*ft_itoa(int nbr)
{
	int n = count_digs(nbr);
	char *buff = (char*)malloc(sizeof(char) * n + 1);
	if(!buff)
		return NULL;
	buff[n] = '\0';
	if(nbr < 0)
	{
		buff[0] = '-';
		nbr *= -1;
	}
	if(nbr == 0)
		buff[0] = '0';
	else
	{
		while(n--, nbr != 0)
		{
			buff[n] = (nbr % 10) + 48;
			nbr = (nbr - (nbr % 10)) / 10;
		}
	}
	return buff;
}


int  main()
{
	char* ptr = ft_itoa(-454568);
	printf("%s\n", ptr);
}
