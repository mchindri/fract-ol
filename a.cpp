
















int	radical_1(int n)
{
	int i;

	i = 0;
	while (i * i <= n)
		i++;
	return (i - 1);
}

void	radical_2(int *n)
{
	int i;

	i = 0;
	while (i * i <= *n)
		i++;
	*n = i - 1;
}

void	radical_3(int &n)
{
	int i;

	i = 0;
	while (i * i <= n)
		i++;
	n = i - 1;
}

#include <stdio.h>
int main()
{
	int n;
	int aux;

	printf("introduceti n:");
	scanf("%d", &n);
	aux = radical_1(n);// int
	printf("Radical din %d = %d\n", n, aux);
	aux = n;
	radical_2(&aux);// int *
	printf("Radical din %d = %d\n", n, aux);
	aux = n;
	radical_3(aux);// int &
	printf("Radical din %d = %d\n", n, aux);
	return (0);
}
