#include <stdio.h>
#include <stdlib.h>

int is_prime(int nbr)
{
	if (nbr <= 1)
		return 0;
	int check = 2;
	while(check < nbr)
	{
		if(nbr % check == 0)
			return 0;
		check++;
	}
	return 1;
}


int main(int ac, char **av)
{
	if(2 == ac)
	{
		int nbr = atoi(av[1]);
		if(nbr == 1)
			printf("1");
		else
		{
			int check = 2;
			while(nbr >= check)
			{
				if(nbr % check == 0)
				{
					printf("%d", check);
					if(check != nbr)
						printf("*");
					nbr /= check;
					check--;
				}
				check++;
			}
		}
	}
	printf("\n");
}

