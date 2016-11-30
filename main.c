#include <stdio.h>
#include "ft_printf.h"


int		main(void)
{
	_FUNCTION_IN_TEST("ft_printf");
	_OUTPUT;

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

	_ASSERT(ft_printf(T1), printf(T1), E1);
	_ASSERT(ft_printf(T2), printf(T2), E2);
	_ASSERT(ft_printf(T3), printf(T3), E3);	

	printf("\nsimple conv -s\n\n");
	
	E1 = "Fail at simple conv letter";
	E2 = "Fail at simple conv number";
	E3 = "Fail at empty_string";

	_ASSERT(ft_printf("abc%s\n", "efg"), printf("abc%s\n", "efg"), E1);
	_ASSERT(ft_printf("111%s\n", "222"), printf("111%s\n", "222"), E2);
	_ASSERT(ft_printf("%s\n", ""), printf("%s\n", ""), E3);

	printf("\nmulti conv -s\n\n");
	
	E1 = "Fail at multi conv letter";
	E2 = "Fail at multi conv number";
	E3 = "Fail at only format";

	_ASSERT(ft_printf("abcd%shij%s%s\n", "efg", "kl", "mn"), printf("abcd%shij%s%s\n", "efg", "kl", "mn"), E1);
	_ASSERT(ft_printf("111%s333%s555%s\n", "222", "444", "666"), printf("111%s333%s555%s\n", "222", "444", "666"), E2);
	_ASSERT(ft_printf("%s%s%s%s\n", "a","b", "c", "d"), printf("%s%s%s%s\n", "a", "b", "c", "d"), E3);

	printf("\nmulti conv -d\n\n");
	
	E1 = "Fail at digit+";
	E2 = "Fail at digit-";
	E3 = "Fail at digit-";

	_ASSERT(ft_printf("%d\n", 42), printf("%d\n", 42), E1);
	_ASSERT(ft_printf("%d\n", -42), printf("%d\n", -42), E2);
	_ASSERT(ft_printf("%d%d%d%d\n", 1, 2, 3 ,4), printf("%d%d%d%d\n", 1, 2, 3, 4), E3);

	printf("\nmulti conv -c\n\n");
	
	E1 = "Fail at one conv char";
	E2 = "Fail at multi conv char";

	_ASSERT(ft_printf("%c\n", 'A'), printf("%c\n", 'A'), E1);
	_ASSERT(ft_printf("%c%c%c%c%c%c%c%c\n", 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'), printf("%c%c%c%c%c%c%c%c\n", 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h'), E2);

return (0);
}


