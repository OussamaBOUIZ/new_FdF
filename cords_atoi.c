/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cords_atoi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obouizga <obouizga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 07:54:07 by obouizga          #+#    #+#             */
/*   Updated: 2022/06/07 18:19:02 by obouizga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// t_iso	**iso_square(int row, int col)
// {
// 	t_iso	**iso_tab;
// 	int		i;

// 	iso_tab = malloc(sizeof(t_iso *) * (row + 1));
// 	if (!iso_tab)
// 		exit(EXIT_FAILURE);
// 	i = 0;
// 	while (i < row)
// 	{
// 		iso_tab[i] = malloc(sizeof(t_iso) * col + 1);////changed here added one
// 		if (!iso_tab[i])
// 			exit(EXIT_FAILURE);
// 		i++;
// 	}
// 	iso_tab[i] = 0;
// 	return (iso_tab);
// }


t_iso	**iso_square(int row, int col)
{
	t_iso	**iso_tab;
	int		i;

	iso_tab = malloc(sizeof(t_iso *) * (row + 1));
	if (!iso_tab)
		exit(EXIT_FAILURE);
	i = 0;
	while (i < row)
	{
		iso_tab[i] = malloc(sizeof(t_iso) * col);////changed here added one
		if (!iso_tab[i])
			exit(EXIT_FAILURE);
		i++;
	}
	iso_tab[i] = 0;
	return (iso_tab);
}

t_peri	get_perimeter(t_peri peri, t_d x, t_d y)
{
	if (x > peri.max_x)
		peri.max_x = x;
	if (x <= peri.min_x)
		peri.min_x = x;
	if (y > peri.max_y)
		peri.max_y = y;
	if (y <= peri.min_y)
		peri.min_y = y;
	return (peri);
}

t_sh	cords_atoi(char ***cor, int *dim, char **map)
{
	t_sh	sh;
	int		i;
	int		j;
	t_u		units;

	j = 0;
	i = 0;
	sh.iso = iso_square(dim[0], dim[1]);
	sh.peri.max_x = sh.iso[j][i].x;
	sh.peri.min_x = sh.iso[j][i].x;
	sh.peri.max_y = sh.iso[j][i].y;
	sh.peri.min_y = sh.iso[j][i].y;
	units = def_unit(dim, map, cor);
	while (cor[j])
	{
		i = 0;
		while (cor[j][i])
		{
			sh.iso[j][i] = to_isom((t_d)i, (t_d)j, s_atoi(cor[j][i]), units);
			sh.peri = get_perimeter(sh.peri, sh.iso[j][i].x, sh.iso[j][i].y);
			i++;
		}
		j++;
	}
	return (sh);
}
