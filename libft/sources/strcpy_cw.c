/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strcpy_cw.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alazarev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/28 14:52:49 by alazarev          #+#    #+#             */
/*   Updated: 2018/07/28 14:52:51 by alazarev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strcpy_cw(unsigned char *dst, const unsigned char *src, size_t len)
{
	while (len--)
		*dst++ = *src++;
}
