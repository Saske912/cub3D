/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfile <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/05 12:03:30 by pfile             #+#    #+#             */
/*   Updated: 2020/09/18 12:53:26 by pfile            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	sort_sprites_util(t_spr *spr1, t_spr *spr2)
{
	spr1->dst = spr2->dst;
	spr1->x = spr2->x;
	spr1->y = spr2->y;
	spr1->angle = spr2->angle;
}

void	sort_sprites(t_spr *spr, t_map *map)
{
	t_spr	sprite;
	int		i;
	int		n;
	int		max;

	n = 0;
	while (n < map->spr_count)
	{
		i = -1 + n;
		sprite.dst = 0;
		sprite.x = 0;
		sprite.y = 0;
		while (++i < map->spr_count)
			if (spr[i].dst > sprite.dst)
			{
				sort_sprites_util(&sprite, &spr[i]);
				max = i;
			}
		sort_sprites_util(&spr[max], &spr[n]);
		sort_sprites_util(&spr[n], &sprite);
		n++;
	}
}
