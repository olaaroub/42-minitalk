#include <unistd.h>
#include <stdio.h>

void	ft_putchar(char c)
{


	write(1, &c, 1);
}

void	print_bits(unsigned char num)
{
	int i = 7;
	unsigned char bit;
	while(i >= 0)
	{
		bit = (num >> i) & 1;
		ft_putchar(bit + '0');
		i--;
	}
}

unsigned char	reverse_bits(unsigned char num)
{
	unsigned char reversed;
	int i = 7;
	while(i >= 0)
	{
		reversed <<= 1;
		reversed |= (num & 1);
		num >>= 1;
		i--;
	}
	return reversed;
}

int main()
{
	unsigned char c = 'c';
	print_bits(c);
	write(1, "\n", 1);
	unsigned char n = reverse_bits(c);
	print_bits(n);
}
