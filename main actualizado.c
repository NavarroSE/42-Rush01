/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manavarr <manavarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 15:05:00 by manavarr          #+#    #+#             */
/*   Updated: 2022/03/27 13:47:55 by manavarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_create_headers(char *parameters, int header_table[4][4])
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

void	ft_create_table(int vector_table[4][4][4])
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

void	ft_print_four(int *vector_table)
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

void	ft_header2table(int i, int j, int *vector_table)
{
	printf("header2table: %d, %d\n", i, j);
	if (i == 0)
		ft_print_four(vector_table + j * 4);
	else if (i == 1)
		ft_print_four(vector_table + 3 * 4 + j);
	else if (i == 2)
		ft_print_four(vector_table + j * 16 + 0);
	else
		ft_print_four(vector_table + j * 16 + 3);
}

void	ft_put_4s(int header_table[4][4], int *vector_table)
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
				ft_header2table(i, j, vector_table);
			j++;
		}
		i++;
	}
}

int	main(int argc, char *argv[])
{
	int	header_table[4][4];

	if (argc != 2)
	{
		printf("Error\n");
	}
	else
	{
		printf("%s\n\n", argv[1]);
		ft_create_headers(argv[1], header_table);
	}
	return (0);
}
