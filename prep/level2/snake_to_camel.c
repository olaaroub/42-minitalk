#include <unistd.h>

int main(int ac, char **av)
{
	if(2 == ac)
	{
		while(*av[1])
		{
			if(*av[1] == '_')
			{
				av[1]++;
				*av[1] -= 32;
			}
			write(1, av[1], 1);
			av[1]++;
		}
	}
	write(1, "\n", 1);
}
