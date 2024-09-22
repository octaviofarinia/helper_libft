/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_libft.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofarina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 15:51:44 by ofarina           #+#    #+#             */
/*   Updated: 2024/09/22 13:32:00 by ofarina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_LIBFT_H 
# define TESTS_LIBFT_H

typedef struct s_test
{
	const char *name;
	int (*test_func)(void);
} t_test;

void	test_ft_memcpy(void);

#endif
