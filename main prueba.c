/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main prueba.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manavarr <manavarr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 15:05:00 by manavarr          #+#    #+#             */
/*   Updated: 2022/03/27 13:05:43 by manavarr         ###   ########.fr       */
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

int	main(int argc, char *argv[])
{
	int	header_table[4][4];
	int i, j;
	if (argc != 2)
	{
		printf("Error\n");
	}
	else
	{
		printf("%s\n\n", argv[1]);
		ft_create_headers(argv[1], header_table);
		for (j = 0; j < 4; j++)
			printf("%d", header_table[1][j]);
		printf("\n");
	}
	return (0);
}
