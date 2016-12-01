/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 18:11:57 by ariard            #+#    #+#             */
/*   Updated: 2016/12/01 16:45:20 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROJECT_H
# define PROJECT_H

#define NRM  "\x1B[0m"
#define RED  "\x1B[31m"
#define GRN  "\x1B[32m"
#define YEL  "\x1B[33m"
#define BLU  "\x1B[34m"
#define MAG  "\x1B[35m"
#define CYN  "\x1B[36m"
#define WHT  "\x1B[37m"		

#include <stdio.h>

# define _LAUNCH_TEST  printf("%s------------------TEST BEGINNING--------------------%s\n\n", MAG, WHT);

#define _OUTPUT  int	out1;  int	out2;

#define MEMSET  ft_memset(a, 0, sizeof(a));\
	ft_memset(b, 0, sizeof(b));\

# define _ASSERT(x, y, E)  if ((int)(out1 = x) == (int)(out2 =y)) {\
	printf(GRN "[OK] "WHT"%s"YEL "[%d]" WHT"%s" YEL "[%d]\n", #x, out1, #y, out2);}\
	else{\
	printf(RED "[NO] "WHT"%s"YEL "[%d]" WHT"%s" YEL "[%d]\n", #x, out1, #y, out2);\
	printf(WHT"Error : %s\n", E);}

# define _FUNCTION_IN_TEST(x)  printf("\n"); printf("%s********************%s********************\n\n", CYN, x);
#endif
//
//	  ft_memset
//
//	  E = "Rate, essaye encore";
//
//	 _OUTPUT;
//	_FUNCTION_IN_TEST("ft_coucou");
//	_ASSERT(f_strlen("coucou"), f_strlen("coucou"), E);
//	_ASSERT(f_strlen("coucou"), f_strlen("couc"), E);
//	_ASSERT(f_strlen("coucou"), f_strlen("coucou"), E);
//	
//
