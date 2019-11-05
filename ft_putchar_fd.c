//
// Created by Admin on 04/11/2019.
//

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}