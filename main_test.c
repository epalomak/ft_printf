/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: epalomak <epalomak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 12:39:43 by epalomak          #+#    #+#             */
/*   Updated: 2020/09/10 17:33:58 by epalomak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"
#include <stdio.h>

int	main(void)
{
	void *p;

		printf("c conversion\n");
/*1*/ft_printf("{%-5c}\n",'e'); 
		printf("{%-5c}\n",'e');
/*2*/ft_printf("{%20c}\n", 'h');
		printf("{%20c}\n", 'h');
		printf("\n");

		printf("d conversion\n");
/*1*/ft_printf("{%-12.5d}\n",1234); 
		printf("{%-12.5d}\n",1234);
/*2*/ft_printf("{% .2d}\n",323); 
		printf("{% .2d}\n",323);
/*3*/ft_printf("{%+010d}\n",323);
		printf("{%+010d}\n",323);
/*4*/ft_printf("{%ld}\n",4546878785764); 
		printf("{%ld}\n",4546878785764);
/*5*/ft_printf("{%hhd}\n",'a');
		printf("{%hhd}\n",'a');
		printf("\n");

		printf("o conversion\n");
/*1*/ft_printf("{%-12.5o}\n",1234); 
		printf("{%-12.5o}\n",1234);
/*2*/ft_printf("{%#10o}\n",323);
		printf("{%#10o}\n",323);
/*3*/ft_printf("{%012o}\n",4546); 	
		printf("{%012o}\n",4546);
/*4*/ft_printf("{%ho}\n",'e'); 
		printf("{%ho}\n",'e');
		printf("\n");

		printf("u conversion\n");
/*1*/ft_printf("{%-12.5u}\n",(unsigned int)1234); 
		printf("{%-12.5u}\n",(unsigned int)1234);
/*2*/ft_printf("{%.2u}\n",(unsigned int)-323); 
		printf("{%.2u}\n",(unsigned int)-323);
/*3*/ft_printf("{%15u}\n",(unsigned int)323);
		printf("{%15u}\n",(unsigned int)323);
/*4*/ft_printf("{%llu}\n",(unsigned long long)4546878785764); 
		printf("{%llu}\n",(unsigned long long)4546878785764);
		printf("\n");

		printf("x & X conversion\n");
/*1*/ft_printf("{%#.3x}\n",1234); 
		printf("{%#.3x}\n",1234);
/*2*/ft_printf("{%08.4X}\n", 424);
		printf("{%08.4X}\n", 424);
/*3*/ft_printf("{%-10x}\n",323);
		printf("{%-10x}\n",323);
/*4*/ft_printf("{%012X}\n",4546); 	
		printf("{%012X}\n",4546);
		printf("\n");

		printf("s conversion\n");
/*1*/ft_printf("{%s}\n", NULL); 
		printf("{%s}\n",NULL);
/*2*/ft_printf("{%.4s}\n", "hey I am");
		printf("{%.4s}\n", "hey I am");
/*3*/ft_printf("{%-15s}\n", "hey I am");
		printf("{%-15s}\n","hey I am");
		printf("\n");

		printf("p conversion\n");
/*1*/ft_printf("{%p}\n", NULL); 
		printf("{%p}\n",NULL);
/*2*/ft_printf("{%p}\n", p);
		printf("{%p}\n", p);
/*3*/ft_printf("{%-18p}\n",p);
		printf("{%-18p}\n",p);
/*4*/ft_printf("{%-15p}\n", 0);
		printf("{%-15p}\n", 0);
		printf("\n");

		printf("f conversion\n");
/*1*/ft_printf("{%f}\n",-0.0005); 
		printf("{%f}\n",-0.0005);
/*2*/ft_printf("{%Lf}\n", 142.24141245l);
		printf("{%Lf}\n", 142.24141245l);
/*3*/ft_printf("{%-18f}\n",23.234);
		printf("{%-18f}\n",23.234);
/*4*/ft_printf("{%.13f}\n", 0.454);
		printf("{%.13f}\n", 0.454);
/*5*/ft_printf("{%f}\n", 1235412341235112.45412341234);
		printf("{%f}\n", 1235412341235112.45412341234);
		printf("\n");
	
		printf("multiple conversions\n");
/*1*/ft_printf("{%d, %.5s}\n",-1235, "hey test"); 
		printf("{%d, %.5s}\n",-1235, "hey test");
/*2*/ft_printf("{%lo, %10Lf}\n", 454634562355, 142.24141245l);
		printf("{%lo, %10Lf}\n", 454634562355, 142.24141245l);
/*3*/ft_printf("{%.13f, %-18p, %08.4X}\n", 0.454, p, 434);
		printf("{%.13f, %-18p, %08.4X}\n", 0.454, p, 434);
/*4*/ft_printf("{%f, %.13f, %#.5x}\n", 1235412341235112.45412341234, 142.24141245, 456);
		printf("{%f, %.13f, %#.5x}\n", 1235412341235112.45412341234, 142.24141245, 456);
/*5*/ft_printf("{%-f, %p, %.4x, %10s, %#.2o}\n", 123451.454, p, 43234, "hellou", 45676);
		printf("{%-f, %p, %.4x, %10s, %#.2o}\n", 123451.454, p, 43234, "hellou", 45676);
	printf("\n");

		printf("special case\n");
/*1*/ft_printf("%%\n");
		printf("%%\n");
/*2*/ft_printf("%f\n");
		printf("%f\n");
/*3*/ft_printf("%");
		printf("%");
	while(1)
	{
		
	}
	return(0);
}