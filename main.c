#include <stdio.h>
#include "ft_printf.h"


int		main(void)
{
	_FUNCTION_IN_TEST("ft_printf");


	char *E1;
	char *E2;
	char *E3;
	char *T1;
	char *T2;
	char *T3;

	printf(WHT "\nno conv - simple test\n\n");

	E1 = "Fail at simple test";
	E2 = "Fail at empty string";
	E3 = "Fail at newline";
	T1 = "This is\n a simple\n test\n";
	T2 = "";
	T3 = "\n";

	ft_printf("This is\n a simple\n test\n");
	printf("This is\n a simple\n test\n");
	ft_printf("");
	printf("");
	ft_printf("\n");
   	printf("\n");

	printf("\nsimple conv -s\n\n");
	
	E1 = "Fail at simple conv letter";
	E2 = "Fail at simple conv number";
	E3 = "Fail at empty_string";

	ft_printf("abc%s\n", "efg");
	printf("abc%s\n", "efg");
	ft_printf("111%s\n", "222");
   	printf("111%s\n", "222");
	ft_printf("%s\n", "");
   	printf("%s\n", "");

	printf("\nmulti conv -s\n\n");
	
	E1 = "Fail at multi conv letter";
	E2 = "Fail at multi conv number";
	E3 = "Fail at only format";

	ft_printf("abcd%shij%s%s\n", "efg", "kl", "mn"); 
	printf("abcd%shij%s%s\n", "efg", "kl", "mn");
	ft_printf("111%s333%s555%s\n", "222", "444", "666");
	printf("111%s333%s555%s\n", "222", "444", "666");
	ft_printf("%s%s%s%s\n", "a","b", "c", "d");
	printf("%s%s%s%s\n", "a", "b", "c", "d");

	printf("\nmulti conv -d\n\n");
	
	E1 = "Fail at digit+";
	E2 = "Fail at digit-";
	E3 = "Fail at digit-";

	ft_printf("%d\n", 42);
	printf("%d\n", 42);
	ft_printf("%d\n", -42);
	printf("%d\n", -42);
	ft_printf("%d%d%d%d\n", 1, 2, 3 ,4);
   	printf("%d%d%d%d\n", 1, 2, 3, 4);

	printf("\nmulti conv -c\n\n");
	
	E1 = "Fail at one conv char";
	E2 = "Fail at multi conv char";

	ft_printf("%c\n", 'A');
	printf("%c\n", 'A');
	ft_printf("%c%c%c%c%c%c%c%c\n", 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h');
	printf("%c%c%c%c%c%c%c%c\n", 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h');

	return (0);
}


