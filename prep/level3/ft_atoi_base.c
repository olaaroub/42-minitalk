#include <stdio.h>

int	ft_atoi_base(const char *str, int str_base)
{
	int sign = 1;
	int result = 0;

	if(*str == '-')
		sign = -1;
	while(*str)
	{
		result *= str_base;
		if(*str >= '0' && *str <= '9')
			result += *str -'0';
		else if(*str >= 'A' && *str <= 'Z')
			result += *str - '7';
		else if(*str >= 'a' && *str <= 'z')
			result += *str - 'W';
		str++;
	}
	return (result * sign);
}

int main()
{
	int n = ft_atoi_base("16abz", 36);
	printf("%d\n", n);
}
			
