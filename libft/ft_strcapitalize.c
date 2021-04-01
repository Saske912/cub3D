/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfile <pfile@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/21 11:57:02 by pfile             #+#    #+#             */
/*   Updated: 2020/05/21 12:16:49 by pfile            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcapitalize(char *str)
{
	int i;

	i = -1;
	while (str[++i] != '\0')
	{
		if ((str[i] >= 97 && str[i] <= 122) && (((str[i - 1] < 97 \
			|| str[i - 1] > 122) && (str[i - 1] < 65 || \
			str[i - 1] > 90) && (str[i - 1] < 48 || \
				str[i - 1] > 57)) || i == 0))
			str[i] = str[i] - 32;
		else if ((str[i] >= 65 && str[i] <= 90) && i > 0 && \
				((str[i - 1] >= 97 && str[i - 1] <= 122) || \
				(str[i - 1] >= 65 && str[i - 1] <= 90) || \
				(str[i - 1] >= 48 && str[i - 1] <= 57)))
			str[i] = str[i] + 32;
	}
	return (str);
}
