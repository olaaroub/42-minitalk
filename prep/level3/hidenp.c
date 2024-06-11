#include <stdio.h>
#include <unistd.h>
int main(int ac, char **av)
{
	if(3 == ac)
	{
		while(*av[2])
		{
			if(*av[2] == *av[1])
				av[1]++;
			av[2]++;
		}
		if(!(*av[1]))
			write(1, "1", 1);
		else 
			write(1, "0", 1);
	}
	write(1, "\n", 1);
}

