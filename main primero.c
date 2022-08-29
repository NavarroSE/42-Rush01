/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manavarr <manavarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 13:45:56 by manavarr          #+#    #+#             */
/*   Updated: 2022/03/27 13:45:57 by manavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	create_headers(char *parameters, int header_table[4][4])
{
	int	i;
	int	j;
	int	str_index;

	str_index = 0;
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			header_table[i][j] = (int)(parameters[str_index] - 48);
			str_index = str_index + 2;
			j++;
		}
		i++;
	}
}

void	create_table(int vector_table[4][4][4])
{
	int	i;
	int	j;
	int	k;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			k = 0;
			while (k < 4)
			{
				vector_table[i][j][k] = k + 1;
				k++;
			}
			j++;
		}
		i++;
	}
}

void	print_four(int *vector_table)
{
	int	i;

	*vector_table = 4;
	i = 1;
	while (i < 4)
	{
		*(vector_table + i) = 0;
		i++;
	}
}

void	header2table(int i, int j, int *vector_table)
{
	printf("header2table: %d, %d\n", i, j);
	if (i == 0)
		print_four(vector_table + j * 4);
	else if (i == 1)
		print_four(vector_table + 3 * 4 + j);
	else if (i == 2)
		print_four(vector_table + j * 16 + 0);
	else
		print_four(vector_table + j * 16 + 3);
}

void	put_4s(int header_table[4][4], int *vector_table)
{
	int	i;
	int	j;
	int	count;

	count = 0;
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (header_table[i][j] == 1)
				header2table(i, j, vector_table);
			j++;
		}
		i++;
	}
}

int	main(void)
{
	int i, j, k;
	int header_table[4][4];
	int vector_table[4][4][4];
	char parameters[] = "2 1 3 4 5 6 7 8 1 1 3 4 5 6 7 8";

	create_headers(parameters, header_table);
	create_table(vector_table);
	put_4s(header_table, vector_table);

	for (i = 0; i < 4; i++)
	{
		printf("0, 1, %d: %d ", i, vector_table[0][1][i]);
		printf("\n");
		printf("0, 0, %d: %d", i, vector_table[0][0][i]);
		printf("\n");
		printf("1, 0, %d: %d", i, vector_table[1][0][i]);
		printf("\n");
	}
}