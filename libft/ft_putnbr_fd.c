/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cshi-xia <cshi-xia@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 12:12:39 by cshi-xia          #+#    #+#             */
/*   Updated: 2022/07/04 12:12:40 by cshi-xia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd){
	if (n == -2147483648){
		write(fd, "-", 1);
		ft_putchar_fd('2', fd);
		ft_putnbr_fd(147483648, fd);
		return ;
	}
	if (n < 0){
		write(fd, "-", 1);
		ft_putnbr_fd((n * - 1), fd);
		return ;
	}
	if (n >= 10)
		ft_putnbr_fd(n/10, fd);
	ft_putchar_fd((n%10) + '0', fd);
}
