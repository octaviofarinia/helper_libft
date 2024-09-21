/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_memcpy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofarina <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 18:41:19 by ofarina           #+#    #+#             */
/*   Updated: 2024/09/21 19:05:37 by ofarina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include <stdio.h>
#include <string.h>
#define MAX_LEN 80
 
char source[ MAX_LEN ] = "This is the source string";
char target[ MAX_LEN ] = "This is the target string";
char ft_source[ MAX_LEN ] = "This is the ft_source string";
char ft_target[ MAX_LEN ] = "This is the ft_target string";
 
void test_ft_memcpy(void)
{
  printf( "BEGIN TEST - ft_memcpy.c\n");
  printf( "\tBefore memcpy, target is \"%s\"\n", target );
  memcpy( target, source, sizeof(source));
  printf( "\tAfter memcpy, target becomes \"%s\"\n", target );
  printf( "\tBefore ft_memcpy, target is \"%s\"\n", ft_target );
  ft_memcpy( ft_target, ft_source, sizeof(ft_source));
  printf( "\tAfter ft_memcpy, target becomes \"%s\"\n", ft_target );
  printf( "END TEST\n");
}
