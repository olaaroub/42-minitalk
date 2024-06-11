#include <stdio.h>
#include <stdlib.h>

int *ft_range(int start, int end)
{
	int size = end - start;
	if(end < start)
		size = start - end;
	int *tab = malloc(sizeof(int) * size + 1);
	int i = 0;
	if(end >= start)
	{
		while (start <= end)
			tab[i++] = start++;
		tab[i] = 0;
	}
	else 
	{
		while(end <= start)
			tab[i++] = end++;
		tab[i] = 0;
	}
	return tab;
}

int main()
{
	int start =  0;
	int end = -3;
	int *tab = ft_range(start, end);
	for(int i = 0; end <= start; i++,end++)
	{
		printf("%d\n", tab[i]);
	}
}
