#include <stdio.h>
#include "ft_printf.h"
#include <limits.h>

int		main(void)
{



	int		len2;
	

/*	len2 = ft_printf("This is a simple test.");
	len3 = printf("This is a simple test.");

	printf("%d vs %d\n", len2, len3);

	printf("\n");

	ft_printf("This is a simple test.\nSecond sentence.\n");
	printf("This is a simple test.\nSecond sentence.\n");
	ft_printf("");
	printf("");
	ft_printf("\n");
   	printf("\n");

 	
	
	len2 = ft_printf("%s\n", "abc");
	len3 = printf("%s\n", "abc");
	printf("%d vs %d\n", len2, len3);

	ft_printf("111%s333\n", "222");
	printf("111%s333\n", "222");
	ft_printf("%s333\n", "222");
   	printf("%s333\n", "222");
	ft_printf("111%s\n", "222");
 	printf("111%s\n", "222");
	ft_printf("{%s}\n", "");
	printf("{%s}\n", "");
	ft_printf("{%s}\n", 0);
//   	printf("{%s}\n", 0);

	printf("\nmulti conv -s\n\n");
*/
	int len;
/*
	len = ft_printf("111%s333%s555%saaa%sccc\n", "222", "444", "666", "bbb");
	len2 = printf("111%s333%s555%saaa%sccc\n", "222", "444", "666", "bbb");
	printf("%d vs %d\n", len, len2);
	len = ft_printf("111%s333%s555\n", "222", "444");
	printf("111%s333%s555\n", "222", "444");
	printf("%d vs 15\n", len);
	len = ft_printf("%s%s%s%s%s\n", "1","2", "3", "4", "5");
	printf("%s%s%s%s%s\n", "1", "2", "3", "4", "5");
	printf("%d vs 5\n", len);

	printf("print d\n\n");

	ft_printf("%d\n", 42);
	printf("%d\n", 42);
	ft_printf("%d\n", -42);
	printf("%d\n", -42);
	ft_printf("before %d after\n", 42);
	printf("before %d after\n", 42);
	ft_printf("%d%d%d%d%d\n", 1, -2, 3, -4 , 5);
	printf("%d%d%d%d%d\n", 1, -2, 3, -4 , 5);
	ft_printf("a%db%dc%dd\n", 1, -2, 3);
	printf("a%db%dc%dd\n", 1, -2, 3);
	ft_printf("%d\n", INT_MAX);
	printf("%d\n", INT_MAX);
	ft_printf("%d\n", INT_MIN);
	printf("%d\n", INT_MIN);
*/



/*	printf("\nmulti conv -d\n\n");
	
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

	char abc;

	ft_printf("%c\n", 'A');
	printf("%c\n", 'A');
	abc = ft_printf("%c%c", '4', '2');
	printf("%c%c", '4', '2');
	printf("\n%d vs 2\n", abc);
	abc = ft_printf("%c%c%c%c%c%c%c%c\n", 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h');
	printf("%c%c%c%c%c%c%c%c\n", 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h');
	printf("%d vs 9", abc);
	
	printf("\nprint color\n\n");

	E1 = "Fail at red";
	E2 = "Fail at yellow";
	E2 = "Fail at blu-cyn and yelred";

	ft_printf(RED "hello %s\n", "world");
	printf(RED"hello %s\n", "world");
	ft_printf(YEL "salut %s\n", "monde");
	printf(YEL "salut %s\n", "monde");
	ft_printf(BLU "salut %s" CYN "%svous allz bien ?\n" YEL RED "ROUGE\n", "la compagnie", "test");
	printf(BLU "salut %s" CYN "%svous allz bien ?\n" YEL RED "ROUGE\n", "la compagnie", "test");

	printf(RESET "gestion des erreurs\n\n");

	char *s1;
	char *s2;

	s1 = "hello world\n";
	s2 = "a toi mom frere mon lecteur\n";

	ft_printf(s1);
	printf(s1);
	ft_printf(s2);
	printf(s2);
	ft_printf("hello %s\n", NULL);
	printf("hello %s\n", NULL);
	ft_printf("hello : %d\n", NULL);
	printf("hello : %d\n", NULL);
	
	int	a;
	int b; 
	int c;
	int d;

	a = ft_printf("\n");
	printf("\n");
	printf("%d vs 1\n", a);
	b = ft_printf("test");
	printf("test");
	printf("%d vs 4\n", b);
	c = ft_printf("test\n");
	printf("test\n");
	printf("%d vs 5\n", c);
	ft_printf("1234");
	d = printf("1234");
	printf("%d vs 4\n", d);
	return (0); 
	
	printf("parsing flags precedence");
	ft_printf("my number : %+ d\n", 12345);
	printf(" \n");
	ft_printf("my number : % +d\n", 6789);
	printf("+\n");
	ft_printf("my number : %+-d\n", 34653);
	printf("-\n");
	ft_printf("my number : %+#x\n", 34653);
	printf("#\n");
	ft_printf("my number : %------+0d\n", 34653);
	printf("0\n");
	
	printf("parsing flags width");

	ft_printf("%789d\n", 100);
	printf("789\n");
	ft_printf("%.34567d\n", 100);
	printf("34567\n");
	ft_printf("%123.d\n", 100);
	printf("123\n");
	ft_printf("%987.1234d\n", 100);
	printf("987\n");
	printf("1234\n");
	ft_printf("%55d\n", 100);
	printf("55\n");


	printf("parsing flags prom\n");
	
	ft_printf("%lld", 100);
	printf("y\n");
	ft_printf("%hhd", 100);
	printf("w\n");
	ft_printf("%hld", 100);
	ft_printf("%lhd", 100);
	ft_printf("%hd", 100);
	printf("h\n");
	ft_printf("%d", 100);
	ft_printf("%ld", 100);
	printf("l\n");
	ft_printf("%zd", 100);
	printf("z\n");
	ft_printf("%jd", 100);
	printf("j\n");


	
	printf("parsing flags type\n");

	ft_printf("%a", 100);
	ft_printf("%q", 100);
	ft_printf("%s", 100);
	printf("s\n");
	ft_printf("%S", 100);
	printf("S\n");
	ft_printf("%p", 100);
	printf("p\n");
	ft_printf("%d", 100);
	printf("d\n");
	ft_printf("%D", 100);
	printf("D\n");
	ft_printf("%i", 100);
	printf("i\n");
	ft_printf("%o", 100);
	printf("o\n");
	ft_printf("%O", 100);
	printf("O\n");
	ft_printf("%u", 100);
	printf("u\n");
	ft_printf("%U", 100);
	printf("U\n");
	ft_printf("%x", 100);
	printf("x\n");
	ft_printf("%C", 100);
	printf("C\n");
	ft_printf("%X", 100);
	printf("X\n");
	ft_printf("%%", 100);
	printf("%%");

	printf("check validity\n");
	
	ft_printf("%#10ld", 100);
	printf("VRAI\n");
	ft_printf("%#10.10a", 100);
	printf("FAUX\n");
	ft_printf("%#010.10lld", 100);
	printf("VRAI\n");
	ft_printf("% #10.10w", 100);
	printf("FAUX\n");
	ft_printf("%# +-12345.657hd", 100);
	printf("VRAI\n");
	ft_printf("%123&sd", 100);
	printf("FAUX\n");


	printf("print argument\n");
	
	ft_printf("%#s");
	ft_printf("%0100.d");
	ft_printf("%w#100d");
	ft_printf("%#U");
	ft_printf("%100c");

	printf("print char and string\n");

	char	*p;

	p = "string";
	ft_printf("hello %s\n", "world");
	printf("hello %s\n", "world");
	ft_printf("salut %.10s\n", "comment ca va?");
	printf("salut %.10s\n", "comment ca va?");
	ft_printf("grosse phrase : %s\n", "abcdefghijklmnopqrstuvwxyz");
	printf("grosse phrase : %s\n", "abcdefghijklmnopqrstuvwxyz");
	ft_printf("char : %c\n", 'A');
	printf("char : %c\n", 'A');
//	ft_printf("pointer : %p\n", p);
//	printf("pointer : %p\n", p);
	ft_printf("Voici un pourcentage : %% non ?\n");
	printf("Voici un pourcentage : %% non ?\n");

	printf("print int\n");

	ft_printf("voici un int : %d yes ?\n", 100);
	printf("voici un int : %d yes ?\n", 100);
	ft_printf("voici un int : %D non?\n", 42);
	printf("voici un int : %D non?\n", 42);
	ft_printf("voici un int : %i non?\n", 150);
	printf("voici un int : %i non?\n", 150);
	ft_printf("voici un int precise : %10d non?\n", 84);
	printf("voici un int precise : %10d non?\n", 84);
*/
//	len = ft_printf("%");
//	len2 = ft_printf("%");
//	ft_putnbr(len);
//	ft_putnbr(len2);
//	len = ft_printf("% Zooo");
//	len2 = ft_printf("% Zooo ");
//	printf("\n%d vs %d\n", len, len2);
//	len = ft_printf("{%}");
//	len2 = ft_printf("{%}");
//	printf("\n%d vs %d\n", len, len2);


	len2 = 0;
	len = 0;

	len = ft_printf("%x", 42);
	ft_putchar(10);
	len2 = printf("%x", 0);

	printf("\n\n");
	ft_putnbr(len);
	ft_putchar(10);
	ft_putnbr(len2);

	return (0);
}
