#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

void	i_test(void);
void	d_test(void);
void	c_test(void);
void	s_test(void);
void	x_test(void);
void	p_test(void);
void	u_test(void);
void	dash_test(void);
void	period_test(void);
void	zero_test(void);
void	plus_test(void);
void	space_test(void);
void	hash_test(void);
void	mix_flag_test(void);
void	percent_test(void);

int	main(int argc, char **argv)
{
	char *n = NULL;
	int	ft;
	int	pf;

	printf("\033[0;31m __________%s__________\033[0;0m\n", "FT_PRINTF_VS_PRINTF_TESTS");
	if (argc > 1 && argv)
	{
		period_test();
		dash_test();
		zero_test();
		plus_test();
		space_test();
		hash_test();
		percent_test();
		mix_flag_test();
		// ft = ft_printf("%01.d\n", 0);
		// pf = printf("%01.d\n", 0);
		// printf("ft: %i pf: %i\n", ft, pf);
	}
	else
	{
		ft = ft_printf(" %s \n", n);
		pf = printf(" %s \n", n);
		printf("ft: %i pf: %i\n", ft, pf);
		ft = ft_printf("No converesions!\n");
		pf = printf("No converesions!\n");
		printf("ft: %i pf: %i\n", ft, pf);
		i_test();
		d_test();
		c_test();
		s_test();
		x_test();
		p_test();
		u_test();
	// 	ft = ft_printf("%01.d\n", 0);
	// 	pf = printf("%01.d\n", 0);
	// 	printf("ft: %i pf: %i\n", ft, pf);
	}
	return (0);
}

void	i_test(void)
{
	printf("\033[0;36m __________%s__________\033[0;0m\n", "INTEGER_TESTS");

	int ft;
	int	pf;

	ft = ft_printf(" %i \n", 0);
	pf = printf(" %i \n", 0);
	printf("ft: %i pf: %i\n", ft, pf);

	ft = ft_printf(" %i \n", -1);
	pf = printf(" %i \n", -1);
	printf("ft: %i pf: %i\n", ft, pf);

	ft = ft_printf(" %i \n", 1);
	pf = printf(" %i \n", 1);
	printf("ft: %i pf: %i\n", ft, pf);

	ft = ft_printf(" %i \n", 763236);
	pf = printf(" %i \n", 763236);
	printf("ft: %i pf: %i\n", ft, pf);

	ft = ft_printf(" %i \n", -763236);
	pf = printf(" %i \n", -763236);
	printf("ft: %i pf: %i\n", ft, pf);

	ft = ft_printf(" %i \n", INT_MAX);
	pf = printf(" %i \n", INT_MAX);
	printf("ft: %i pf: %i\n", ft, pf);

	ft = ft_printf(" %i \n", INT_MAX + 1);
	pf = printf(" %i \n", INT_MAX + 1);
	printf("ft: %i pf: %i\n", ft, pf);

	ft = ft_printf(" %i \n", INT_MIN);
	pf = printf(" %i \n", INT_MIN);
	printf("ft: %i pf: %i\n", ft, pf);


	ft = ft_printf(" %i \n", INT_MIN - 1);
	pf = printf(" %i \n", INT_MIN - 1);
	printf("ft: %i pf: %i\n", ft, pf);

	ft = ft_printf(" %i %i %i %i %i %i %i\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	pf = printf(" %i %i %i %i %i %i %i\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	printf("ft: %i pf: %i\n", ft, pf);
}

void	d_test(void)
{
	printf("\033[0;36m __________%s__________\033[0;0m\n", "DECIMAL_TESTS");

	int ft;
	int	pf;

	ft = ft_printf(" %d \n", 0);
	pf = printf(" %d \n", 0);
	printf("ft: %i pf: %i\n", ft, pf);

	ft = ft_printf(" %d \n", -1);
	pf = printf(" %d \n", -1);
	printf("ft: %i pf: %i\n", ft, pf);

	ft = ft_printf(" %d \n", 1);
	pf = printf(" %d \n", 1);
	printf("ft: %i pf: %i\n", ft, pf);

	ft = ft_printf(" %d \n", 763236);
	pf = printf(" %d \n", 763236);
	printf("ft: %i pf: %i\n", ft, pf);

	ft = ft_printf(" %d \n", -763236);
	pf = printf(" %d \n", -763236);
	printf("ft: %i pf: %i\n", ft, pf);

	ft = ft_printf(" %d \n", INT_MAX);
	pf = printf(" %d \n", INT_MAX);
	printf("ft: %i pf: %i\n", ft, pf);

	ft = ft_printf(" %d \n", INT_MAX + 1);
	pf = printf(" %d \n", INT_MAX + 1);
	printf("ft: %i pf: %i\n", ft, pf);

	ft = ft_printf(" %d \n", INT_MIN);
	pf = printf(" %d \n", INT_MIN);
	printf("ft: %i pf: %i\n", ft, pf);


	ft = ft_printf(" %d \n", INT_MIN - 1);
	pf = printf(" %d \n", INT_MIN - 1);
	printf("ft: %i pf: %i\n", ft, pf);

	ft = ft_printf(" %d %d %d %d %d %d %d\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	pf = printf(" %d %d %d %d %d %d %d\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	printf("ft: %i pf: %i\n", ft, pf);
}

void	c_test(void)
{
	printf("\033[0;36m __________%s__________\033[0;0m\n", "CHARACTER_TESTS");

	int ft;
	int	pf;

	ft = ft_printf("%c\n", '0');
	pf = printf("%c\n", '0');
	printf("\nft: %i pf: %i\n", ft, pf);

	ft = ft_printf("| %c |\n", '0');
	pf = printf("| %c |\n", '0');
	printf("\nft: %i pf: %i\n", ft, pf);

	ft = ft_printf("| %c |\n", -256);
	pf = printf("| %c |\n", 256);
	printf("\nft: %i pf: %i\n", ft, pf);

	ft = ft_printf("%c %c %c %c %c\n", 't', 'e', 's', 't', '!');
	pf = printf("%c %c %c %c %c\n", 't', 'e', 's', 't', '!');
	printf("\nft: %i pf: %i\n", ft, pf);

	ft = ft_printf("| %1c |\n", 'a');
	pf = printf("| %1c |\n", 'a');
	printf("\nft: %i pf: %i\n", ft, pf);

	// 	// char 	tests
// 	char	test = 't';
	
// 	ft_printf("char test: %c\n", test);
// 	ft_printf("char test: %c %c\n", test, test);
// 	ft_printf("char test: %c %c %c\n", test, test, 'p');
// 	ft_printf("char test: %c %c %c %c %c\n", test, test, test, test, test);
// 	ft_printf("char test: %-c\n", test);
// 	ft_printf("char test: |%-2c|\n", test);
// 	ft_printf("char test: |%-17c|\n", test);
// 	ft_printf("char test: |%2-c|\n", test); //default prints: char test: |t|
// 	ft_printf("char test: |%5c|\n", test);
}

void	s_test(void)
{
		printf("\033[0;36m __________%s__________\033[0;0m\n", "STRING_TESTS");

	int ft;
	int	pf;

	ft = ft_printf("%s\n", NULL);
	pf = printf("%s\n", NULL);
	printf("ft: %i pf: %i\n", ft, pf);

	ft = ft_printf(" NULL %s NULL \n", NULL);
	pf = printf(" NULL %s NULL \n", NULL);
	printf("ft: %i pf: %i\n", ft, pf);

	ft = ft_printf("%s\n", "");
	pf = printf("%s\n", "");
	printf("ft: %i pf: %i\n", ft, pf);

	ft = ft_printf("%s\n", " ");
	pf = printf("%s\n", " ");
	printf("ft: %i pf: %i\n", ft, pf);

	ft = ft_printf("%s\n", "");
	pf = printf("%s\n", "");
	printf("ft: %i pf: %i\n", ft, pf);

	ft = ft_printf("%s\n", "test");
	pf = printf("%s\n", "test");
	printf("ft: %i pf: %i\n", ft, pf);

	ft = ft_printf("%s\n", "test test test test test");
	pf = printf("%s\n", "test test test test test");
	printf("ft: %i pf: %i\n", ft, pf);

}

void	x_test(void)
{
	printf("\033[0;36m __________%s__________\033[0;0m\n", "HEXADECIMAL_TESTS");
	printf("\033[0;35m __________%s__________\033[0;0m\n", "x");

	int ft;
	int	pf;

	ft = ft_printf("%x\n", 0);
	pf = printf("%x\n", 0);
	printf("ft: %i pf: %i\n", ft, pf);

	ft = ft_printf("%x\n", -1);
	pf = printf("%x\n", -1);
	printf("ft: %i pf: %i\n", ft, pf);

	ft = ft_printf("%x\n", 15);
	pf = printf("%x\n", 15);
	printf("ft: %i pf: %i\n", ft, pf);

	ft = ft_printf("%x\n", 16);
	pf = printf("%x\n", 16);
	printf("ft: %i pf: %i\n", ft, pf);

	ft = ft_printf("%x\n", 17);
	pf = printf("%x\n", 17);
	printf("ft: %i pf: %i\n", ft, pf);

	ft = ft_printf(" %x \n", LONG_MAX);
	pf = printf(" %x \n", LONG_MAX);
	printf("\nft: %i pf: %i\n", ft, pf);

	ft = ft_printf(" %x \n", LONG_MIN);
	pf = printf(" %x \n", LONG_MIN);
	printf("\nft: %i pf: %i\n", ft, pf);

	ft = ft_printf(" %x \n", ULONG_MAX);
	pf = printf(" %x \n", ULONG_MAX);
	printf("\nft: %i pf: %i\n", ft, pf);

	ft = ft_printf(" %x \n", 9223372036854775807LL);
	pf = printf(" %x \n", 9223372036854775807LL);
	printf("\nft: %i pf: %i\n", ft, pf);

	ft = ft_printf(" %x %x %x %x %x %x %x\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	pf = printf(" %x %x %x %x %x %x %x\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	printf("\nft: %i pf: %i\n", ft, pf);

	printf("\033[0;35m __________%s__________\033[0;0m\n", "X");

	ft = ft_printf("%X\n", 0);
	pf = printf("%X\n", 0);
	printf("ft: %i pf: %i\n", ft, pf);

	ft = ft_printf("%X\n", -1);
	pf = printf("%X\n", -1);
	printf("ft: %i pf: %i\n", ft, pf);

	ft = ft_printf("%X\n", 15);
	pf = printf("%X\n", 15);
	printf("ft: %i pf: %i\n", ft, pf);

	ft = ft_printf("%X", 16);
	pf = printf("%X", 16);
	printf("ft: %i pf: %i\n", ft, pf);

	ft = ft_printf("%X\n", 17);
	pf = printf("%X\n", 17);
	printf("ft: %i pf: %i\n", ft, pf);

	ft = ft_printf(" %X \n", LONG_MAX);
	pf = printf(" %X \n", LONG_MAX);
	printf("\nft: %i pf: %i\n", ft, pf);

	ft = ft_printf(" %X \n", LONG_MIN);
	pf = printf(" %X \n", LONG_MIN);
	printf("\nft: %i pf: %i\n", ft, pf);

	ft = ft_printf(" %X \n", ULONG_MAX);
	pf = printf(" %X \n", ULONG_MAX);
	printf("\nft: %i pf: %i\n", ft, pf);

	ft = ft_printf(" %X \n", 9223372036854775807LL);
	pf = printf(" %X \n", 9223372036854775807LL);
	printf("\nft: %i pf: %i\n", ft, pf);

	ft = ft_printf(" %X %X %X %X %X %X %X\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	pf = printf(" %X %X %X %X %X %X %X\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	printf("\nft: %i pf: %i\n", ft, pf);
}

void	p_test(void)
{
	printf("\033[0;36m __________%s__________\033[0;0m\n", "POINTER_TESTS");

	int ft;
	int	pf;
	char	*test = "point to me!";
	char	**ptr = &test;

	ft = ft_printf(" %p \n", ptr);
	pf = printf(" %p \n", ptr);
	printf("ft: %i pf: %i\n", ft, pf);

	ft = ft_printf(" %p %p \n", 0, 0);
	pf = printf(" %p %p \n", 0, 0);
	printf("ft: %i pf: %i\n", ft, pf);

	ft = ft_printf(" %p \n", 1);
	pf = printf(" %p \n", 1);
	printf("ft: %i pf: %i\n", ft, pf);

	ft = ft_printf(" %p \n", -1);
	pf = printf(" %p \n", -1);
	printf("ft: %i pf: %i\n", ft, pf);

	ft = ft_printf(" %p \n", 15);
	pf = printf(" %p \n", 15);
	printf("ft: %i pf: %i\n", ft, pf);

	ft = ft_printf(" %p \n", 16);
	pf = printf(" %p \n", 16);
	printf("ft: %i pf: %i\n", ft, pf);

	ft = ft_printf(" %p %p \n", LONG_MIN, LONG_MAX);
	pf = printf(" %p %p \n", LONG_MIN, LONG_MAX);
	printf("ft: %i pf: %i\n", ft, pf);

	ft = ft_printf(" %p %p \n", INT_MIN, INT_MAX);
	pf = printf(" %p %p \n", INT_MIN, INT_MAX);
	printf("ft: %i pf: %i\n", ft, pf);

	ft = ft_printf(" %p %p \n", ULONG_MAX, -ULONG_MAX);
	pf = printf(" %p %p \n", ULONG_MAX, -ULONG_MAX);
	printf("ft: %i pf: %i\n", ft, pf);

}

void	u_test(void)
{
	printf("\033[0;36m __________%s__________\033[0;0m\n", "UNSIGNED_TESTS");

	int ft;
	int	pf;

	ft = ft_printf(" %u \n", 0);
	pf = printf(" %u \n", 0);
	printf("ft: %i pf: %i\n", ft, pf);

	ft = ft_printf(" %u \n", 1);
	pf = printf(" %u \n", 1);
	printf("ft: %i pf: %i\n", ft, pf);

	ft = ft_printf(" %u \n", 100);
	pf = printf(" %u \n", 100);
	printf("ft: %i pf: %i\n", ft, pf);

	ft = ft_printf(" %u \n", -1);
	pf = printf(" %u \n", -1);
	printf("ft: %i pf: %i\n", ft, pf);

	ft = ft_printf(" %u \n", -9);
	pf = printf(" %u \n", -9);
	printf("ft: %i pf: %i\n", ft, pf);

	ft = ft_printf(" %u \n", -10);
	pf = printf(" %u \n", -10);
	printf("ft: %i pf: %i\n", ft, pf);

	ft = ft_printf(" %u \n", INT_MIN);
	pf = printf(" %u \n", INT_MIN);
	printf("ft: %i pf: %i\n", ft, pf);

	ft = ft_printf(" %u \n", LONG_MAX);
	pf = printf(" %u \n", LONG_MAX);
	printf("ft: %i pf: %i\n", ft, pf);

	ft = ft_printf(" %u \n", LONG_MIN);
	pf = printf(" %u \n", LONG_MIN);
	printf("ft: %i pf: %i\n", ft, pf);

	ft = ft_printf(" %u \n", UINT_MAX);
	pf = printf(" %u \n", UINT_MAX);
	printf("ft: %i pf: %i\n", ft, pf);

	ft = ft_printf(" %u \n", ULONG_MAX);
	pf = printf(" %u \n", ULONG_MAX);
	printf("ft: %i pf: %i\n", ft, pf);

	ft = ft_printf(" %u \n", 9223372036854775807LL);
	pf = printf(" %u \n", 9223372036854775807LL);
	printf("ft: %i pf: %i\n", ft, pf);
}

void	dash_test(void)
{
	printf("\n\033[0;36m __________%s__________\033[0;0m\n", "DASH_TESTS");

	int ft;
	int	pf;

	printf("\033[0;35m __________%s__________\033[0;0m\n", "c_TESTS");
	ft = ft_printf("|%6c|\n", '0');
	pf = printf("|%6c|\n", '0');
	printf("\nft: %i pf: %i\n", ft, pf);

	ft = ft_printf("|%-c|\n", '0');
	pf = printf("|%-c|\n", '0');
	printf("\nft: %i pf: %i\n", ft, pf);

	ft = ft_printf("| %-c |\n", '0');
	pf = printf("| %-c |\n", '0');
	printf("\nft: %i pf: %i\n", ft, pf);

	ft = ft_printf("| %-c |\n", -256);
	pf = printf("| %-c |\n", 256);
	printf("\nft: %i pf: %i\n", ft, pf);

	ft = ft_printf("|%-c| |%-c| |%-c| |%-c| |%-c|\n", 't', 'e', 's', 't', '!');
	pf = printf("|%-c| |%-c| |%-c| |%-c| |%-c|\n", 't', 'e', 's', 't', '!');
	printf("\nft: %i pf: %i\n", ft, pf);

	ft = ft_printf("|%-6c|\n", '0');
	pf = printf("|%-6c|\n", '0');
	printf("\nft: %i pf: %i\n", ft, pf);

	ft = ft_printf("| %-0c |\n", '0');
	pf = printf("| %-0c |\n", '0');
	printf("\nft: %i pf: %i\n", ft, pf);

	ft = ft_printf("| %-10c |\n", -256);
	pf = printf("| %-10c |\n", 256);
	printf("\nft: %i pf: %i\n", ft, pf);

	ft = ft_printf("|%-1c| |%-2c| |%-3c| |%-4c| |%-5c|\n", 't', 'e', 's', 't', '!');
	pf = printf("|%-1c| |%-2c| |%-3c| |%-4c| |%-5c|\n", 't', 'e', 's', 't', '!');
	printf("\nft: %i pf: %i\n", ft, pf);

	printf("\033[0;35m __________%s__________\033[0;0m\n", "s_TESTS");
	ft = ft_printf("|%6s|\n", "");
	pf = printf("|%6s|\n", "");
	printf("ft: %i pf: %i\n", ft, pf);

	ft = ft_printf("|%-s|\n", "");
	pf = printf("|%-s|\n", "");
	printf("ft: %i pf: %i\n", ft, pf);

	ft = ft_printf("|%-10s|\n", " ");
	pf = printf("|%-10s|\n", " ");
	printf("ft: %i pf: %i\n", ft, pf);

	ft = ft_printf("|%-10s|\n", "");
	pf = printf("|%-10s|\n", "");
	printf("ft: %i pf: %i\n", ft, pf);

	ft = ft_printf("|%-20s|\n", "test");
	pf = printf("|%-20s|\n", "test");
	printf("ft: %i pf: %i\n", ft, pf);

	ft = ft_printf("|%-10s|\n", "test test test test test");
	pf = printf("|%-10s|\n", "test test test test test");
	printf("ft: %i pf: %i\n", ft, pf);

	ft = ft_printf("|%-50s|\n", "test test test test test");
	pf = printf("|%-50s|\n", "test test test test test");
	printf("ft: %i pf: %i\n", ft, pf);

	printf("\033[0;35m __________%s__________\033[0;0m\n", "p_TESTS");
	ft = ft_printf("|%6p|\n", -1);
	pf = printf("|%6p|\n", -1);
	printf("ft: %i pf: %i\n", ft, pf);

	ft = ft_printf("|%-6p|\n", -1);
	pf = printf("|%-6p|\n", -1);
	printf("ft: %i pf: %i\n", ft, pf);

	ft = ft_printf("|%-10p|\n", 1);
	pf = printf("|%-10p|\n", 1);
	printf("ft: %i pf: %i\n", ft, pf);

	ft = ft_printf("|%-120p|\n", 16);
	pf = printf("|%-120p|\n", 16);
	printf("ft: %i pf: %i\n", ft, pf);

	ft = ft_printf("|%-1p|\n", INT_MAX);
	pf = printf("|%-1p|\n", INT_MAX);
	printf("ft: %i pf: %i\n", ft, pf);

	printf("\033[0;35m __________%s__________\033[0;0m\n", "d_TESTS");
	ft = ft_printf("|%6d|\n", -1);
	pf = printf("|%6d|\n", -1);
	printf("ft: %i pf: %i\n", ft, pf);

	ft = ft_printf("|%-6d|\n", -1);
	pf = printf("|%-6d|\n", -1);
	printf("ft: %i pf: %i\n", ft, pf);

	ft = ft_printf("|%-6d|\n", -42);
	pf = printf("|%-6d|\n", -42);
	printf("ft: %i pf: %i\n", ft, pf);

	ft = ft_printf("|%-10d|\n", 1);
	pf = printf("|%-10d|\n", 1);
	printf("ft: %i pf: %i\n", ft, pf);

	ft = ft_printf("|%-120d|\n", 16);
	pf = printf("|%-120d|\n", 16);
	printf("ft: %i pf: %i\n", ft, pf);

	ft = ft_printf("|%-1d|\n", INT_MAX);
	pf = printf("|%-1d|\n", INT_MAX);
	printf("ft: %i pf: %i\n", ft, pf);

	printf("\033[0;35m __________%s__________\033[0;0m\n", "i_TESTS");
	ft = ft_printf("|%6i|\n", -1);
	pf = printf("|%6i|\n", -1);
	printf("ft: %i pf: %i\n", ft, pf);

	ft = ft_printf("|%-6i|\n", -1);
	pf = printf("|%-6i|\n", -1);
	printf("ft: %i pf: %i\n", ft, pf);

	ft = ft_printf("|%-6i|\n", -42);
	pf = printf("|%-6i|\n", -42);
	printf("ft: %i pf: %i\n", ft, pf);

	ft = ft_printf("|%-10i|\n", 1);
	pf = printf("|%-10i|\n", 1);
	printf("ft: %i pf: %i\n", ft, pf);

	ft = ft_printf("|%-120i|\n", 16);
	pf = printf("|%-120i|\n", 16);
	printf("ft: %i pf: %i\n", ft, pf);

	ft = ft_printf("|%-1i|\n", INT_MAX);
	pf = printf("|%-1i|\n", INT_MAX);
	printf("ft: %i pf: %i\n", ft, pf);

	printf("\033[0;35m __________%s__________\033[0;0m\n", "u_TESTS");
	ft = ft_printf("|%6u|\n", -1);
	pf = printf("|%6u|\n", -1);
	printf("ft: %i pf: %i\n", ft, pf);

	ft = ft_printf("|%-6u|\n", -1);
	pf = printf("|%-6u|\n", -1);
	printf("ft: %i pf: %i\n", ft, pf);

	ft = ft_printf("|%-6u|\n", -42);
	pf = printf("|%-6u|\n", -42);
	printf("ft: %i pf: %i\n", ft, pf);

	ft = ft_printf("|%-10u|\n", 1);
	pf = printf("|%-10u|\n", 1);
	printf("ft: %i pf: %i\n", ft, pf);

	ft = ft_printf("|%-120u|\n", 16);
	pf = printf("|%-120u|\n", 16);
	printf("ft: %i pf: %i\n", ft, pf);

	ft = ft_printf("|%-1u|\n", INT_MAX);
	pf = printf("|%-1u|\n", INT_MAX);
	printf("ft: %i pf: %i\n", ft, pf);

	ft = ft_printf("|%-1u|\n", UINT_MAX);
	pf = printf("|%-1u|\n", UINT_MAX);
	printf("ft: %i pf: %i\n", ft, pf);

	ft = ft_printf("|%-1u|\n", UINT_MAX + 1);
	pf = printf("|%-1u|\n", UINT_MAX + 1);
	printf("ft: %i pf: %i\n", ft, pf);

	printf("\033[0;35m __________%s__________\033[0;0m\n", "x_TESTS");
	ft = ft_printf("|%6x|\n", -1);
	pf = printf("|%6x|\n", -1);
	printf("ft: %i pf: %i\n", ft, pf);

	ft = ft_printf("|%-6x|\n", -1);
	pf = printf("|%-6x|\n", -1);
	printf("ft: %i pf: %i\n", ft, pf);

	ft = ft_printf("|%-6x|\n", -42);
	pf = printf("|%-6x|\n", -42);
	printf("ft: %i pf: %i\n", ft, pf);

	ft = ft_printf("|%-10x|\n", 1);
	pf = printf("|%-10x|\n", 1);
	printf("ft: %i pf: %i\n", ft, pf);

	ft = ft_printf("|%-120x|\n", 16);
	pf = printf("|%-120x|\n", 16);
	printf("ft: %i pf: %i\n", ft, pf);

	ft = ft_printf("|%-25x|\n", INT_MAX);
	pf = printf("|%-25x|\n", INT_MAX);
	printf("ft: %i pf: %i\n", ft, pf);

	ft = ft_printf("|%-1X|\n", UINT_MAX);
	pf = printf("|%-1X|\n", UINT_MAX);
	printf("ft: %i pf: %i\n", ft, pf);

	printf("\033[0;35m __________%s__________\033[0;0m\n", "X_TESTS");
	ft = ft_printf("|%6X|\n", -1);
	pf = printf("|%6X|\n", -1);
	printf("ft: %i pf: %i\n", ft, pf);

	ft = ft_printf("|%-6X|\n", -1);
	pf = printf("|%-6X|\n", -1);
	printf("ft: %i pf: %i\n", ft, pf);

	ft = ft_printf("|%-6X|\n", -42);
	pf = printf("|%-6X|\n", -42);
	printf("ft: %i pf: %i\n", ft, pf);

	ft = ft_printf("|%-10X|\n", 1);
	pf = printf("|%-10X|\n", 1);
	printf("ft: %i pf: %i\n", ft, pf);

	ft = ft_printf("|%-120X|\n", 16);
	pf = printf("|%-120X|\n", 16);
	printf("ft: %i pf: %i\n", ft, pf);

	ft = ft_printf("|%-25X|\n", INT_MAX);
	pf = printf("|%-25X|\n", INT_MAX);
	printf("ft: %i pf: %i\n", ft, pf);

	ft = ft_printf("|%-1X|\n", UINT_MAX);
	pf = printf("|%-1X|\n", UINT_MAX);
	printf("ft: %i pf: %i\n", ft, pf);
}

void	period_test(void)
{
	printf("\n\033[0;36m __________%s__________\033[0;0m\n", "PRECISION_TESTS");

	int ft;
	int	pf;

	printf("\033[0;35m __________%s__________\033[0;0m\n", "s_TESTS");
	ft = ft_printf(" %.s ", "print me");
	pf = printf(" %.s ", "print me");
	printf("\nft: %i pf: %i\n", ft, pf);

	ft = ft_printf(" %.4s ", "print me");
	pf = printf(" %.4s ", "print me");
	printf("\nft: %i pf: %i\n", ft, pf);

	ft = ft_printf(" %.20s ", "print me");
	pf = printf(" %.20s ", "print me");
	printf("\nft: %i pf: %i\n", ft, pf);

	ft = ft_printf(" %.2s ", "");
	pf = printf(" %.2s ", "");
	printf("\nft: %i pf: %i\n", ft, pf);

	ft = ft_printf(" |%.2s| ", " ");
	pf = printf(" |%.2s| ", " ");
	printf("\nft: %i pf: %i\n", ft, pf);

	printf("\033[0;35m __________%s__________\033[0;0m\n", "p_TESTS");
	ft = ft_printf("|%.p|\n", -1);
	pf = printf("|%.p|\n", -1);
	printf("ft: %i pf: %i\n", ft, pf);

	ft = ft_printf("|%.6p|\n", -1);
	pf = printf("|%.6p|\n", -1);
	printf("ft: %i pf: %i\n", ft, pf);

	ft = ft_printf("|%.10p|\n", 1);
	pf = printf("|%.10p|\n", 1);
	printf("ft: %i pf: %i\n", ft, pf);

	ft = ft_printf("|%.120p|\n", 16);
	pf = printf("|%.120p|\n", 16);
	printf("ft: %i pf: %i\n", ft, pf);

	ft = ft_printf("|%.20p|\n", INT_MAX);
	pf = printf("|%.20p|\n", INT_MAX);
	printf("ft: %i pf: %i\n", ft, pf);

	printf("\033[0;35m __________%s__________\033[0;0m\n", "d_TESTS");
	ft = ft_printf("|%.d|\n", -1);
	pf = printf("|%.d|\n", -1);
	printf("ft: %i pf: %i\n", ft, pf);

	ft = ft_printf("|%-.6d|\n", -1);
	pf = printf("|%.6d|\n", -1);
	printf("ft: %i pf: %i\n", ft, pf);

	ft = ft_printf("|%.6d|\n", -42);
	pf = printf("|%.6d|\n", -42);
	printf("ft: %i pf: %i\n", ft, pf);

	ft = ft_printf("|%.10d|\n", 1);
	pf = printf("|%.10d|\n", 1);
	printf("ft: %i pf: %i\n", ft, pf);

	ft = ft_printf("|%.120d|\n", 16);
	pf = printf("|%.120d|\n", 16);
	printf("ft: %i pf: %i\n", ft, pf);

	ft = ft_printf("|%.1d|\n", INT_MAX);
	pf = printf("|%.1d|\n", INT_MAX);
	printf("ft: %i pf: %i\n", ft, pf);

	printf("\033[0;35m __________%s__________\033[0;0m\n", "i_TESTS");
	ft = ft_printf("|%.i|\n", -1);
	pf = printf("|%.i|\n", -1);
	printf("ft: %i pf: %i\n", ft, pf);

	ft = ft_printf("|%-.6i|\n", -1);
	pf = printf("|%.6i|\n", -1);
	printf("ft: %i pf: %i\n", ft, pf);

	ft = ft_printf("|%.6i|\n", -42);
	pf = printf("|%.6i|\n", -42);
	printf("ft: %i pf: %i\n", ft, pf);

	ft = ft_printf("|%.10i|\n", 1);
	pf = printf("|%.10i|\n", 1);
	printf("ft: %i pf: %i\n", ft, pf);

	ft = ft_printf("|%.120i|\n", 16);
	pf = printf("|%.120i|\n", 16);
	printf("ft: %i pf: %i\n", ft, pf);

	ft = ft_printf("|%.1i|\n", INT_MAX);
	pf = printf("|%.1i|\n", INT_MAX);
	printf("ft: %i pf: %i\n", ft, pf);

	printf("\033[0;35m __________%s__________\033[0;0m\n", "u_TESTS");
	ft = ft_printf("|%6u|\n", -1);
	pf = printf("|%6u|\n", -1);
	printf("ft: %i pf: %i\n", ft, pf);

	ft = ft_printf("|%.6u|\n", -1);
	pf = printf("|%.6u|\n", -1);
	printf("ft: %i pf: %i\n", ft, pf);

	ft = ft_printf("|%.6u|\n", -42);
	pf = printf("|%.6u|\n", -42);
	printf("ft: %i pf: %i\n", ft, pf);

	ft = ft_printf("|%.10u|\n", 1);
	pf = printf("|%.10u|\n", 1);
	printf("ft: %i pf: %i\n", ft, pf);

	ft = ft_printf("|%.120u|\n", 16);
	pf = printf("|%.120u|\n", 16);
	printf("ft: %i pf: %i\n", ft, pf);

	ft = ft_printf("|%.1up|\n", INT_MAX);
	pf = printf("|%.1u|\n", INT_MAX);
	printf("ft: %i pf: %i\n", ft, pf);

	ft = ft_printf("|%.1u|\n", UINT_MAX);
	pf = printf("|%.1u|\n", UINT_MAX);
	printf("ft: %i pf: %i\n", ft, pf);

	ft = ft_printf("|%.1u|\n", UINT_MAX + 1);
	pf = printf("|%.1u|\n", UINT_MAX + 1);
	printf("ft: %i pf: %i\n", ft, pf);

	printf("\033[0;35m __________%s__________\033[0;0m\n", "x_TESTS");
	ft = ft_printf("|%6x|\n", -1);
	pf = printf("|%6x|\n", -1);
	printf("ft: %i pf: %i\n", ft, pf);

	ft = ft_printf("|%.6x|\n", -1);
	pf = printf("|%.6x|\n", -1);
	printf("ft: %i pf: %i\n", ft, pf);

	ft = ft_printf("|%.6x|\n", -42);
	pf = printf("|%.6x|\n", -42);
	printf("ft: %i pf: %i\n", ft, pf);

	ft = ft_printf("|%.10x|\n", 1);
	pf = printf("|%.10x|\n", 1);
	printf("ft: %i pf: %i\n", ft, pf);

	ft = ft_printf("|%.120x|\n", 16);
	pf = printf("|%.120x|\n", 16);
	printf("ft: %i pf: %i\n", ft, pf);

	ft = ft_printf("|%.25x|\n", INT_MAX);
	pf = printf("|%.25x|\n", INT_MAX);
	printf("ft: %i pf: %i\n", ft, pf);

	ft = ft_printf("|%.1X|\n", UINT_MAX);
	pf = printf("|%.1X|\n", UINT_MAX);
	printf("ft: %i pf: %i\n", ft, pf);

	printf("\033[0;35m __________%s__________\033[0;0m\n", "X_TESTS");
	ft = ft_printf("|%6X|\n", -1);
	pf = printf("|%6X|\n", -1);
	printf("ft: %i pf: %i\n", ft, pf);

	ft = ft_printf("|%.6X|\n", -1);
	pf = printf("|%.6X|\n", -1);
	printf("ft: %i pf: %i\n", ft, pf);

	ft = ft_printf("|%.6X|\n", -42);
	pf = printf("|%.6X|\n", -42);
	printf("ft: %i pf: %i\n", ft, pf);

	ft = ft_printf("|%.10X|\n", 1);
	pf = printf("|%.10X|\n", 1);
	printf("ft: %i pf: %i\n", ft, pf);

	ft = ft_printf("|%.120X|\n", 16);
	pf = printf("|%.120X|\n", 16);
	printf("ft: %i pf: %i\n", ft, pf);

	ft = ft_printf("|%.25X|\n", INT_MAX);
	pf = printf("|%.25X|\n", INT_MAX);
	printf("ft: %i pf: %i\n", ft, pf);

	ft = ft_printf("|%.1X|\n", UINT_MAX);
	pf = printf("|%.1X|\n", UINT_MAX);
	printf("ft: %i pf: %i\n", ft, pf);	
}

void	zero_test(void)
{
	printf("\n\033[0;36m __________%s__________\033[0;0m\n", "ZERO_TESTS");

	int ft;
	int	pf;

	printf("\033[0;35m __________%s__________\033[0;0m\n", "p_TESTS");
	ft = ft_printf("|%0p|\n", -1);
	pf = printf("|%0p|\n", -1);
	printf("ft: %i pf: %i\n", ft, pf);

	ft = ft_printf("|%06p|\n", -1);
	pf = printf("|%06p|\n", -1);
	printf("ft: %i pf: %i\n", ft, pf);

	ft = ft_printf("|%010p|\n", 1);
	pf = printf("|%010p|\n", 1);
	printf("ft: %i pf: %i\n", ft, pf);

	ft = ft_printf("|%0120p|\n", 16);
	pf = printf("|%0120p|\n", 16);
	printf("ft: %i pf: %i\n", ft, pf);

	ft = ft_printf("|%020p|\n", INT_MAX);
	pf = printf("|%020p|\n", INT_MAX);
	printf("ft: %i pf: %i\n", ft, pf);

	printf("\033[0;35m __________%s__________\033[0;0m\n", "d_TESTS");
	ft = ft_printf("|%0d|\n", -1);
	pf = printf("|%0d|\n", -1);
	printf("ft: %i pf: %i\n", ft, pf);

	ft = ft_printf("|%06d|\n", -1);
	pf = printf("|%06d|\n", -1);
	printf("ft: %i pf: %i\n", ft, pf);

	ft = ft_printf("|%06d|\n", -42);
	pf = printf("|%06d|\n", -42);
	printf("ft: %i pf: %i\n", ft, pf);

	ft = ft_printf("|%010d|\n", 1);
	pf = printf("|%010d|\n", 1);
	printf("ft: %i pf: %i\n", ft, pf);

	ft = ft_printf("|%0120d|\n", 16);
	pf = printf("|%0120d|\n", 16);
	printf("ft: %i pf: %i\n", ft, pf);

	ft = ft_printf("|%01d|\n", INT_MAX);
	pf = printf("|%01d|\n", INT_MAX);
	printf("ft: %i pf: %i\n", ft, pf);

	printf("\033[0;35m __________%s__________\033[0;0m\n", "i_TESTS");
	ft = ft_printf("|%0i|\n", -1);
	pf = printf("|%0i|\n", -1);
	printf("ft: %i pf: %i\n", ft, pf);

	ft = ft_printf("|%06i|\n", -1);
	pf = printf("|%06i|\n", -1);
	printf("ft: %i pf: %i\n", ft, pf);

	ft = ft_printf("|%06i|\n", -42);
	pf = printf("|%06i|\n", -42);
	printf("ft: %i pf: %i\n", ft, pf);

	ft = ft_printf("|%010i|\n", 1);
	pf = printf("|%010i|\n", 1);
	printf("ft: %i pf: %i\n", ft, pf);

	ft = ft_printf("|%0120i|\n", 16);
	pf = printf("|%0120i|\n", 16);
	printf("ft: %i pf: %i\n", ft, pf);

	ft = ft_printf("|%01i|\n", INT_MAX);
	pf = printf("|%01i|\n", INT_MAX);
	printf("ft: %i pf: %i\n", ft, pf);

	printf("\033[0;35m __________%s__________\033[0;0m\n", "u_TESTS");
	ft = ft_printf("|%6u|\n", -1);
	pf = printf("|%6u|\n", -1);
	printf("ft: %i pf: %i\n", ft, pf);

	ft = ft_printf("|%06u|\n", -1);
	pf = printf("|%06u|\n", -1);
	printf("ft: %i pf: %i\n", ft, pf);

	ft = ft_printf("|%06u|\n", -42);
	pf = printf("|%06u|\n", -42);
	printf("ft: %i pf: %i\n", ft, pf);

	ft = ft_printf("|%010u|\n", 1);
	pf = printf("|%010u|\n", 1);
	printf("ft: %i pf: %i\n", ft, pf);

	ft = ft_printf("|%0120u|\n", 16);
	pf = printf("|%0120u|\n", 16);
	printf("ft: %i pf: %i\n", ft, pf);

	ft = ft_printf("|%01u|\n", INT_MAX);
	pf = printf("|%01u|\n", INT_MAX);
	printf("ft: %i pf: %i\n", ft, pf);

	ft = ft_printf("|%01u|\n", UINT_MAX);
	pf = printf("|%01u|\n", UINT_MAX);
	printf("ft: %i pf: %i\n", ft, pf);

	ft = ft_printf("|%01u|\n", UINT_MAX + 1);
	pf = printf("|%01u|\n", UINT_MAX + 1);
	printf("ft: %i pf: %i\n", ft, pf);

	printf("\033[0;35m __________%s__________\033[0;0m\n", "x_TESTS");
	ft = ft_printf("|%6x|\n", -1);
	pf = printf("|%6x|\n", -1);
	printf("ft: %i pf: %i\n", ft, pf);

	ft = ft_printf("|%06x|\n", -1);
	pf = printf("|%06x|\n", -1);
	printf("ft: %i pf: %i\n", ft, pf);

	ft = ft_printf("|%06x|\n", -42);
	pf = printf("|%06x|\n", -42);
	printf("ft: %i pf: %i\n", ft, pf);

	ft = ft_printf("|%010x|\n", 1);
	pf = printf("|%010x|\n", 1);
	printf("ft: %i pf: %i\n", ft, pf);

	ft = ft_printf("|%0120x|\n", 16);
	pf = printf("|%0120x|\n", 16);
	printf("ft: %i pf: %i\n", ft, pf);

	ft = ft_printf("|%025x|\n", INT_MAX);
	pf = printf("|%025x|\n", INT_MAX);
	printf("ft: %i pf: %i\n", ft, pf);

	ft = ft_printf("|%01X|\n", UINT_MAX);
	pf = printf("|%01X|\n", UINT_MAX);
	printf("ft: %i pf: %i\n", ft, pf);

	printf("\033[0;35m __________%s__________\033[0;0m\n", "X_TESTS");
	ft = ft_printf("|%6X|\n", -1);
	pf = printf("|%6X|\n", -1);
	printf("ft: %i pf: %i\n", ft, pf);

	ft = ft_printf("|%06X|\n", -1);
	pf = printf("|%06X|\n", -1);
	printf("ft: %i pf: %i\n", ft, pf);

	ft = ft_printf("|%06X|\n", -42);
	pf = printf("|%06X|\n", -42);
	printf("ft: %i pf: %i\n", ft, pf);

	ft = ft_printf("|%010X|\n", 1);
	pf = printf("|%010X|\n", 1);
	printf("ft: %i pf: %i\n", ft, pf);

	ft = ft_printf("|%0120X|\n", 16);
	pf = printf("|%0120X|\n", 16);
	printf("ft: %i pf: %i\n", ft, pf);

	ft = ft_printf("|%025X|\n", INT_MAX);
	pf = printf("|%025X|\n", INT_MAX);
	printf("ft: %i pf: %i\n", ft, pf);

	ft = ft_printf("|%01X|\n", UINT_MAX);
	pf = printf("|%01X|\n", UINT_MAX);
	printf("ft: %i pf: %i\n", ft, pf);
}

void	plus_test(void)
{
	printf("\033[0;36m __________%s__________\033[0;0m\n", "PLUS_TESTS");

	int ft;
	int	pf;

	printf("\033[0;35m __________%s__________\033[0;0m\n", "d_TESTS");
	ft = ft_printf(" %+d ", 0);
	pf = printf(" %+d ", 0);
	printf("\nft: %i pf: %i\n", ft, pf);

	ft = ft_printf(" %+d ", -1);
	pf = printf(" %+d ", -1);
	printf("\nft: %i pf: %i\n", ft, pf);

	ft = ft_printf(" %+d ", 1);
	pf = printf(" %+d ", 1);
	printf("\nft: %i pf: %i\n", ft, pf);

	ft = ft_printf(" %+d ", -852);
	pf = printf(" %+d ", -852);
	printf("\nft: %i pf: %i\n", ft, pf);

	ft = ft_printf(" %+d %+d %+d %+d %+d %+d %+d\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	pf = printf(" %+d %+d %+d %+d %+d %+d %+d\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	printf("\nft: %i pf: %i\n", ft, pf);

	printf("\033[0;35m __________%s__________\033[0;0m\n", "i_TESTS");
	ft = ft_printf(" %+i ", 0);
	pf = printf(" %+i ", 0);
	printf("\nft: %i pf: %i\n", ft, pf);

	ft = ft_printf(" %+i ", -1);
	pf = printf(" %+i ", -1);
	printf("\nft: %i pf: %i\n", ft, pf);

	ft = ft_printf(" %+i ", 1);
	pf = printf(" %+i ", 1);
	printf("\nft: %i pf: %i\n", ft, pf);

	ft = ft_printf(" %+i ", -852);
	pf = printf(" %+i ", -852);
	printf("\nft: %i pf: %i\n", ft, pf);

	ft = ft_printf(" %+i %+i %+i %+i %+i %+i %+i\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	pf = printf(" %+i %+i %+i %+i %+i %+i %+i\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	printf("\nft: %i pf: %i\n", ft, pf);
}

void	space_test(void)
{
	printf("\n\033[0;36m __________%s__________\033[0;0m\n", "SPACE_TESTS");

	int ft;
	int	pf;

	printf("\033[0;35m __________%s__________\033[0;0m\n", "d_TESTS");
	ft = ft_printf(" % d ", 0);
	pf = printf(" % d ", 0);
	printf("\nft: %i pf: %i\n", ft, pf);

	ft = ft_printf(" % d ", -1);
	pf = printf(" % d ", -1);
	printf("\nft: %i pf: %i\n", ft, pf);

	ft = ft_printf(" % d ", 1);
	pf = printf(" % d ", 1);
	printf("\nft: %i pf: %i\n", ft, pf);

	ft = ft_printf(" % d ", -852);
	pf = printf(" % d ", -852);
	printf("\nft: %i pf: %i\n", ft, pf);

	ft = ft_printf(" % d % d % d % d % d % d % d\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	pf = printf(" % d % d % d % d % d % d % d\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	printf("\nft: %i pf: %i\n", ft, pf);

	printf("\033[0;35m __________%s__________\033[0;0m\n", "i_TESTS");
	ft = ft_printf(" % i ", 0);
	pf = printf(" % i ", 0);
	printf("\nft: %i pf: %i\n", ft, pf);

	ft = ft_printf(" % i ", -1);
	pf = printf(" % i ", -1);
	printf("\nft: %i pf: %i\n", ft, pf);

	ft = ft_printf(" % i ", 1);
	pf = printf(" % i ", 1);
	printf("\nft: %i pf: %i\n", ft, pf);

	ft = ft_printf(" % i ", -852);
	pf = printf(" % i ", -852);
	printf("\nft: %i pf: %i\n", ft, pf);

	ft = ft_printf(" % i % i % i % i % i % i % i\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	pf = printf(" % i % i % i % i % i % i % i\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	printf("\nft: %i pf: %i\n", ft, pf);
}

void	hash_test(void)
{
	printf("\n\033[0;36m __________%s__________\033[0;0m\n", "HASH_TESTS");

	int ft;
	int	pf;

	printf("\033[0;35m __________%s__________\033[0;0m\n", "x_TESTS");
	ft = ft_printf(" %#x ", 0);
	pf = printf(" %#x ", 0);
	printf("\nft: %i pf: %i\n", ft, pf);

	ft = ft_printf(" %#x ", -1);
	pf = printf(" %#x ", -1);
	printf("\nft: %i pf: %i\n", ft, pf);

	ft = ft_printf(" %#x ", 6816643);
	pf = printf(" %#x ", 6816643);
	printf("\nft: %i pf: %i\n", ft, pf);

	ft = ft_printf(" %#x %#x %#x %#x %#x %#x %#x\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	pf = printf(" %#x %#x %#x %#x %#x %#x %#x\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	printf("\nft: %i pf: %i\n", ft, pf);

	printf("\033[0;35m __________%s__________\033[0;0m\n", "X_TESTS");
	ft = ft_printf(" %#X ", 0);
	pf = printf(" %#X ", 0);
	printf("\nft: %i pf: %i\n", ft, pf);

	ft = ft_printf(" %#X ", -1);
	pf = printf(" %#X ", -1);
	printf("\nft: %i pf: %i\n", ft, pf);

	ft = ft_printf(" %#X ", 6816643);
	pf = printf(" %#X ", 6816643);
	printf("\nft: %i pf: %i\n", ft, pf);

	ft = ft_printf(" %#X %#X %#X %#X %#X %#X %#X\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	pf = printf(" %#X %#X %#X %#X %#X %#X %#X\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	printf("\nft: %i pf: %i\n", ft, pf);
}

void	mix_flag_test(void)
{
	printf("\033[0;36m __________%s__________\033[0;0m\n", "MIXED_FLAGS_TESTS");

	int ft;
	int	pf;

	// printf("\033[0;35m __________%s__________\033[0;0m\n", "zero_dash_TESTS");
	// 			printf("\033[0;34m __________%s__________\033[0;0m\n", "s_TESTS");
	// ft = ft_printf("|%0-s|\n", "hello_tester");
	// pf = printf("|%0-s|\n", "hello_tester");
	// printf("\nft: %i pf: %i\n", ft, pf);

	// ft = ft_printf("|%010-7s|\n", "hello_tester");
	// pf = printf("|%010-7s|\n", "hello_tester");
	// printf("\nft: %i pf: %i\n", ft, pf);

	// ft = ft_printf("|%010-0s|\n", "hello_tester");
	// pf = printf("|%010-0s|\n", "hello_tester");
	// printf("\nft: %i pf: %i\n", ft, pf);

	// ft = ft_printf("|%01-10s|\n", "hello_tester");
	// pf = printf("|%01-10s|\n", "hello_tester");
	// printf("\nft: %i pf: %i\n", ft, pf);

	// printf("\033[0;34m __________%s__________\033[0;0m\n", "d_TESTS");
	// ft = ft_printf("|%0-d|\n", 0);
	// pf = printf("|%0-d|\n", 0);
	// printf("\nft: %i pf: %i\n", ft, pf);

	// ft = ft_printf("|%010-7d|\n", 0);
	// pf = printf("|%010-7d|\n", 0);
	// printf("\nft: %i pf: %i\n", ft, pf);

	// ft = ft_printf("|%010-0d|\n", -1);
	// pf = printf("|%010-0d|\n", -1);
	// printf("\nft: %i pf: %i\n", ft, pf);

	// ft = ft_printf("|%01-10d|\n", 1);
	// pf = printf("|%01-10d|\n", 1);
	// printf("\nft: %i pf: %i\n", ft, pf);

	// ft = ft_printf("|%010-0d|\n", INT_MIN);
	// pf = printf("|%010-0d|\n", INT_MIN);
	// printf("\nft: %i pf: %i\n", ft, pf);

	// ft = ft_printf("|%01-10d|\n", INT_MAX);
	// pf = printf("|%01-10d|\n", INT_MAX);
	// printf("\nft: %i pf: %i\n", ft, pf);

	// printf("\033[0;34m __________%s__________\033[0;0m\n", "i_TESTS");
	// ft = ft_printf("|%0-i|\n", 0);
	// pf = printf("|%0-i|\n", 0);
	// printf("\nft: %i pf: %i\n", ft, pf);

	// ft = ft_printf("|%010-7i|\n", 0);
	// pf = printf("|%010-7i|\n", 0);
	// printf("\nft: %i pf: %i\n", ft, pf);

	// ft = ft_printf("|%010-0i|\n", -1);
	// pf = printf("|%010-0i|\n", -1);
	// printf("\nft: %i pf: %i\n", ft, pf);

	// ft = ft_printf("|%01-10i|\n", 1);
	// pf = printf("|%01-10i|\n", 1);
	// printf("\nft: %i pf: %i\n", ft, pf);

	// ft = ft_printf("|%010-0i|\n", INT_MIN);
	// pf = printf("|%010-0i|\n", INT_MIN);
	// printf("\nft: %i pf: %i\n", ft, pf);

	// ft = ft_printf("|%01-10i|\n", INT_MAX);
	// pf = printf("|%01-10i|\n", INT_MAX);
	// printf("\nft: %i pf: %i\n", ft, pf);

	// printf("\033[0;34m __________%s__________\033[0;0m\n", "u_TESTS");
	// ft = ft_printf("|%0-u|\n", 0);
	// pf = printf("|%0-u|\n", 0);
	// printf("\nft: %i pf: %i\n", ft, pf);

	// ft = ft_printf("|%010-7u|\n", 0);
	// pf = printf("|%010-7u|\n", 0);
	// printf("\nft: %i pf: %i\n", ft, pf);

	// ft = ft_printf("|%010-0u|\n", -1);
	// pf = printf("|%010-0u|\n", -1);
	// printf("\nft: %i pf: %i\n", ft, pf);

	// ft = ft_printf("|%01-10u|\n", 1);
	// pf = printf("|%01-10u|\n", 1);
	// printf("\nft: %i pf: %i\n", ft, pf);

	// ft = ft_printf("|%010-0u|\n", INT_MIN);
	// pf = printf("|%010-0u|\n", INT_MIN);
	// printf("\nft: %i pf: %i\n", ft, pf);

	// ft = ft_printf("|%01-10u|\n", UINT_MAX);
	// pf = printf("|%01-10u|\n", UINT_MAX);
	// printf("\nft: %i pf: %i\n", ft, pf);

	// printf("\033[0;34m __________%s__________\033[0;0m\n", "x_TESTS");
	// ft = ft_printf("|%0-x|\n", 0);
	// pf = printf("|%0-x|\n", 0);
	// printf("\nft: %i pf: %i\n", ft, pf);

	// ft = ft_printf("|%010-7x|\n", 0);
	// pf = printf("|%010-7x|\n", 0);
	// printf("\nft: %i pf: %i\n", ft, pf);

	// ft = ft_printf("|%010-0x|\n", -1);
	// pf = printf("|%010-0x|\n", -1);
	// printf("\nft: %i pf: %i\n", ft, pf);

	// ft = ft_printf("|%01-10x|\n", 1);
	// pf = printf("|%01-10x|\n", 1);
	// printf("\nft: %i pf: %i\n", ft, pf);

	// ft = ft_printf("|%010-0x|\n", INT_MIN);
	// pf = printf("|%010-0x|\n", INT_MIN);
	// printf("\nft: %i pf: %i\n", ft, pf);

	// ft = ft_printf("|%01-10x|\n", UINT_MAX);
	// pf = printf("|%01-10x|\n", UINT_MAX);
	// printf("\nft: %i pf: %i\n", ft, pf);

	// printf("\033[0;35m __________%s__________\033[0;0m\n", "dash_period_TESTS");
	// printf("\033[0;34m __________%s__________\033[0;0m\n", "s_TESTS");
	// ft = ft_printf("|%-.s|\n", "hello_tester");
	// pf = printf("|%-.s|\n", "hello_tester");
	// printf("\nft: %i pf: %i\n", ft, pf);

	// ft = ft_printf("|%-10.7s|\n", "hello_tester");
	// pf = printf("|%-10.7s|\n", "hello_tester");
	// printf("\nft: %i pf: %i\n", ft, pf);

	// ft = ft_printf("|%-10.0s|\n", "hello_tester");
	// pf = printf("|%-10.0s|\n", "hello_tester");
	// printf("\nft: %i pf: %i\n", ft, pf);

	// ft = ft_printf("|%-1.10s|\n", "hello_tester");
	// pf = printf("|%-1.10s|\n", "hello_tester");
	// printf("\nft: %i pf: %i\n", ft, pf);

	// printf("\033[0;34m __________%s__________\033[0;0m\n", "d_TESTS");
	// ft = ft_printf("|%-.d|\n", 0);
	// pf = printf("|%-.d|\n", 0);
	// printf("\nft: %i pf: %i\n", ft, pf);

	// ft = ft_printf("|%-10.7d|\n", 1);
	// pf = printf("|%-10.7d|\n", 1);
	// printf("\nft: %i pf: %i\n", ft, pf);

	// ft = ft_printf("|%-10.0d|\n", -1);
	// pf = printf("|%-10.0d|\n", -1);
	// printf("\nft: %i pf: %i\n", ft, pf);

	// ft = ft_printf("|%-1.10d|\n", 1);
	// pf = printf("|%-1.10d|\n", 1);
	// printf("\nft: %i pf: %i\n", ft, pf);

	// ft = ft_printf("|%-10.0d|\n", INT_MIN);
	// pf = printf("|%-10.0d|\n", INT_MIN);
	// printf("\nft: %i pf: %i\n", ft, pf);

	// ft = ft_printf("|%-1.10d|\n", INT_MAX);
	// pf = printf("|%-1.10d|\n", INT_MAX);
	// printf("\nft: %i pf: %i\n", ft, pf);

	// printf("\033[0;34m __________%s__________\033[0;0m\n", "i_TESTS");
	// ft = ft_printf("|%-.i|\n", 0);
	// pf = printf("|%-.i|\n", 0);
	// printf("\nft: %i pf: %i\n", ft, pf);

	// ft = ft_printf("|%-10.7i|\n", 1);
	// pf = printf("|%-10.7i|\n", 1);
	// printf("\nft: %i pf: %i\n", ft, pf);

	// ft = ft_printf("|%-10.0i|\n", -1);
	// pf = printf("|%-10.0i|\n", -1);
	// printf("\nft: %i pf: %i\n", ft, pf);

	// ft = ft_printf("|%-1.10i|\n", 1);
	// pf = printf("|%-1.10i|\n", 1);
	// printf("\nft: %i pf: %i\n", ft, pf);

	// ft = ft_printf("|%-10.0i|\n", INT_MIN);
	// pf = printf("|%-10.0i|\n", INT_MIN);
	// printf("\nft: %i pf: %i\n", ft, pf);

	// ft = ft_printf("|%-1.10i|\n", INT_MAX);
	// pf = printf("|%-1.10i|\n", INT_MAX);
	// printf("\nft: %i pf: %i\n", ft, pf);

	// printf("\033[0;34m __________%s__________\033[0;0m\n", "u_TESTS");
	// ft = ft_printf("|%-.u|\n", 0);
	// pf = printf("|%-.u|\n", 0);
	// printf("\nft: %i pf: %i\n", ft, pf);

	// ft = ft_printf("|%-.u|\n", 1);
	// pf = printf("|%-.u|\n", 1);
	// printf("\nft: %i pf: %i\n", ft, pf);

	// ft = ft_printf("|%-10.7u|\n", 0);
	// pf = printf("|%-10.7u|\n", 0);
	// printf("\nft: %i pf: %i\n", ft, pf);

	// ft = ft_printf("|%-10.0u|\n", -1);
	// pf = printf("|%-10.0u|\n", -1);
	// printf("\nft: %i pf: %i\n", ft, pf);

	// ft = ft_printf("|%-1.10u|\n", 1);
	// pf = printf("|%-1.10u|\n", 1);
	// printf("\nft: %i pf: %i\n", ft, pf);

	// ft = ft_printf("|%-10.0u|\n", INT_MIN);
	// pf = printf("|%-10.0u|\n", INT_MIN);
	// printf("\nft: %i pf: %i\n", ft, pf);

	// ft = ft_printf("|%-1.10u|\n", UINT_MAX);
	// pf = printf("|%-1.10u|\n", UINT_MAX);
	// printf("\nft: %i pf: %i\n", ft, pf);

	// printf("\033[0;34m __________%s__________\033[0;0m\n", "x_TESTS");
	// ft = ft_printf("|%-.x|\n", 0);
	// pf = printf("|%-.x|\n", 0);
	// printf("\nft: %i pf: %i\n", ft, pf);

	// ft = ft_printf("|%-10.7x|\n", 0);
	// pf = printf("|%-10.7x|\n", 0);
	// printf("\nft: %i pf: %i\n", ft, pf);

	// ft = ft_printf("|%-10.0x|\n", -1);
	// pf = printf("|%-10.0x|\n", -1);
	// printf("\nft: %i pf: %i\n", ft, pf);

	// ft = ft_printf("|%-1.10x|\n", 1);
	// pf = printf("|%-1.10x|\n", 1);
	// printf("\nft: %i pf: %i\n", ft, pf);

	// ft = ft_printf("|%-10.0x|\n", INT_MIN);
	// pf = printf("|%-10.0x|\n", INT_MIN);
	// printf("\nft: %i pf: %i\n", ft, pf);

	// ft = ft_printf("|%-1.10x|\n", UINT_MAX);
	// pf = printf("|%-1.10x|\n", UINT_MAX);
	// printf("\nft: %i pf: %i\n", ft, pf);
	
	// printf("\033[0;35m __________%s__________\033[0;0m\n", "zero_period_TESTS");
	// printf("\033[0;34m __________%s__________\033[0;0m\n", "d_TESTS");
	// ft = ft_printf("|%0.d|\n", 0);
	// pf = printf("|%0.d|\n", 0);
	// printf("\nft: %i pf: %i\n", ft, pf);

	// ft = ft_printf("|%010.7d|\n", 0);
	// pf = printf("|%010.7d|\n", 0);
	// printf("\nft: %i pf: %i\n", ft, pf);

	// ft = ft_printf("|%010.0d|\n", -1);
	// pf = printf("|%010.0d|\n", -1);
	// printf("\nft: %i pf: %i\n", ft, pf);

	// ft = ft_printf("|%01.10d|\n", 1);
	// pf = printf("|%01.10d|\n", 1);
	// printf("\nft: %i pf: %i\n", ft, pf);

	// ft = ft_printf("|%010.0d|\n", INT_MIN);
	// pf = printf("|%010.0d|\n", INT_MIN);
	// printf("\nft: %i pf: %i\n", ft, pf);

	// ft = ft_printf("|%01.10d|\n", INT_MAX);
	// pf = printf("|%01.10d|\n", INT_MAX);
	// printf("\nft: %i pf: %i\n", ft, pf);

	// printf("\033[0;34m __________%s__________\033[0;0m\n", "i_TESTS");
	// ft = ft_printf("|%0.i|\n", 0);
	// pf = printf("|%0.i|\n", 0);
	// printf("\nft: %i pf: %i\n", ft, pf);

	// ft = ft_printf("|%010.7i|\n", 0);
	// pf = printf("|%010.7i|\n", 0);
	// printf("\nft: %i pf: %i\n", ft, pf);

	ft = ft_printf("|%010.0i|\n", -1);
	pf = printf("|%010.0i|\n", -1);
	printf("\nft: %i pf: %i\n", ft, pf);

	ft = ft_printf("|%01.10i|\n", 1);
	pf = printf("|%01.10i|\n", 1);
	printf("\nft: %i pf: %i\n", ft, pf);

	ft = ft_printf("|%010.0i|\n", INT_MIN);
	pf = printf("|%010.0i|\n", INT_MIN);
	printf("\nft: %i pf: %i\n", ft, pf);

	ft = ft_printf("|%01.10i|\n", INT_MAX);
	pf = printf("|%01.10i|\n", INT_MAX);
	printf("\nft: %i pf: %i\n", ft, pf);

	printf("\033[0;34m __________%s__________\033[0;0m\n", "u_TESTS");
	ft = ft_printf("|%0.u|\n", 0);
	pf = printf("|%0.u|\n", 0);
	printf("\nft: %i pf: %i\n", ft, pf);

	ft = ft_printf("|%010.7u|\n", 0);
	pf = printf("|%010.7u|\n", 0);
	printf("\nft: %i pf: %i\n", ft, pf);

	ft = ft_printf("|%010.0u|\n", -1);
	pf = printf("|%010.0u|\n", -1);
	printf("\nft: %i pf: %i\n", ft, pf);

	ft = ft_printf("|%01.10u|\n", 1);
	pf = printf("|%01.10u|\n", 1);
	printf("\nft: %i pf: %i\n", ft, pf);

	ft = ft_printf("|%010.0u|\n", INT_MIN);
	pf = printf("|%010.0u|\n", INT_MIN);
	printf("\nft: %i pf: %i\n", ft, pf);

	ft = ft_printf("|%01.10u|\n", UINT_MAX);
	pf = printf("|%01.10u|\n", UINT_MAX);
	printf("\nft: %i pf: %i\n", ft, pf);

	printf("\033[0;34m __________%s__________\033[0;0m\n", "x_TESTS");
	ft = ft_printf("|%0.x|\n", 0);
	pf = printf("|%0.x|\n", 0);
	printf("\nft: %i pf: %i\n", ft, pf);

	ft = ft_printf("|%010.7x|\n", 0);
	pf = printf("|%010.7x|\n", 0);
	printf("\nft: %i pf: %i\n", ft, pf);

	ft = ft_printf("|%010.0x|\n", -1);
	pf = printf("|%010.0x|\n", -1);
	printf("\nft: %i pf: %i\n", ft, pf);

	ft = ft_printf("|%01.10x|\n", 1);
	pf = printf("|%01.10x|\n", 1);
	printf("\nft: %i pf: %i\n", ft, pf);

	ft = ft_printf("|%010.0x|\n", INT_MIN);
	pf = printf("|%010.0x|\n", INT_MIN);
	printf("\nft: %i pf: %i\n", ft, pf);

	ft = ft_printf("|%01.10x|\n", UINT_MAX);
	pf = printf("|%01.10x|\n", UINT_MAX);
	printf("\nft: %i pf: %i\n", ft, pf);

	printf("\033[0;35m __________%s__________\033[0;0m\n", "zero_dash_period_TESTS");
		printf("\033[0;34m __________%s__________\033[0;0m\n", "s_TESTS");
	ft = ft_printf("|%0-.s|\n", "hello_tester");
	pf = printf("|%0-.s|\n", "hello_tester");
	printf("\nft: %i pf: %i\n", ft, pf);

	ft = ft_printf("|%03-10.7s|\n", "hello_tester");
	pf = printf("|%03-10.7s|\n", "hello_tester");
	printf("\nft: %i pf: %i\n", ft, pf);

	ft = ft_printf("|%03-10.0s|\n", "hello_tester");
	pf = printf("|%03-10.0s|\n", "hello_tester");
	printf("\nft: %i pf: %i\n", ft, pf);

	ft = ft_printf("|%03-1.10s|\n", "hello_tester");
	pf = printf("|%03-1.10s|\n", "hello_tester");
	printf("\nft: %i pf: %i\n", ft, pf);

	printf("\033[0;34m __________%s__________\033[0;0m\n", "d_TESTS");
	ft = ft_printf("|%03-.d|\n", 0);
	pf = printf("|%03-.d|\n", 0);
	printf("\nft: %i pf: %i\n", ft, pf);

	ft = ft_printf("|%03-10.7d|\n", 0);
	pf = printf("|%03-10.7d|\n", 0);
	printf("\nft: %i pf: %i\n", ft, pf);

	ft = ft_printf("|%03-10.0d|\n", -1);
	pf = printf("|%03-10.0d|\n", -1);
	printf("\nft: %i pf: %i\n", ft, pf);

	ft = ft_printf("|%03-1.10d|\n", 1);
	pf = printf("|%03-1.10d|\n", 1);
	printf("\nft: %i pf: %i\n", ft, pf);

	ft = ft_printf("|%03-10.0d|\n", INT_MIN);
	pf = printf("|%03-10.0d|\n", INT_MIN);
	printf("\nft: %i pf: %i\n", ft, pf);

	ft = ft_printf("|%03-1.10d|\n", INT_MAX);
	pf = printf("|%03-1.10d|\n", INT_MAX);
	printf("\nft: %i pf: %i\n", ft, pf);

	printf("\033[0;34m __________%s__________\033[0;0m\n", "i_TESTS");
	ft = ft_printf("|%03-.i|\n", 0);
	pf = printf("|%03-.i|\n", 0);
	printf("\nft: %i pf: %i\n", ft, pf);

	ft = ft_printf("|%03-10.7i|\n", 0);
	pf = printf("|%03-10.7i|\n", 0);
	printf("\nft: %i pf: %i\n", ft, pf);

	ft = ft_printf("|%03-10.0i|\n", -1);
	pf = printf("|%03-10.0i|\n", -1);
	printf("\nft: %i pf: %i\n", ft, pf);

	ft = ft_printf("|%03-1.10i|\n", 1);
	pf = printf("|%03-1.10i|\n", 1);
	printf("\nft: %i pf: %i\n", ft, pf);

	ft = ft_printf("|%03-10.0i|\n", INT_MIN);
	pf = printf("|%03-10.0i|\n", INT_MIN);
	printf("\nft: %i pf: %i\n", ft, pf);

	ft = ft_printf("|%03-1.10i|\n", INT_MAX);
	pf = printf("|%03-1.10i|\n", INT_MAX);
	printf("\nft: %i pf: %i\n", ft, pf);

	printf("\033[0;34m __________%s__________\033[0;0m\n", "u_TESTS");
	ft = ft_printf("|%0-.u|\n", 0);
	pf = printf("|%0-.u|\n", 0);
	printf("\nft: %i pf: %i\n", ft, pf);

	ft = ft_printf("|%03-10.7u|\n", 0);
	pf = printf("|%03-10.7u|\n", 0);
	printf("\nft: %i pf: %i\n", ft, pf);

	ft = ft_printf("|%03-10.0u|\n", -1);
	pf = printf("|%03-10.0u|\n", -1);
	printf("\nft: %i pf: %i\n", ft, pf);

	ft = ft_printf("|%03-1.10u|\n", 1);
	pf = printf("|%03-1.10u|\n", 1);
	printf("\nft: %i pf: %i\n", ft, pf);

	ft = ft_printf("|%03-10.0u|\n", INT_MIN);
	pf = printf("|%03-10.0u|\n", INT_MIN);
	printf("\nft: %i pf: %i\n", ft, pf);

	ft = ft_printf("|%03-1.10u|\n", UINT_MAX);
	pf = printf("|%03-1.10u|\n", UINT_MAX);
	printf("\nft: %i pf: %i\n", ft, pf);

	printf("\033[0;34m __________%s__________\033[0;0m\n", "x_TESTS");
	ft = ft_printf("|%03-.x|\n", 0);
	pf = printf("|%03-.x|\n", 0);
	printf("\nft: %i pf: %i\n", ft, pf);

	ft = ft_printf("|%03-10.7x|\n", 0);
	pf = printf("|%03-10.7x|\n", 0);
	printf("\nft: %i pf: %i\n", ft, pf);

	ft = ft_printf("|%03-10.0x|\n", -1);
	pf = printf("|%03-10.0x|\n", -1);
	printf("\nft: %i pf: %i\n", ft, pf);

	ft = ft_printf("|%03-1.10x|\n", 1);
	pf = printf("|%03-1.10x|\n", 1);
	printf("\nft: %i pf: %i\n", ft, pf);

	ft = ft_printf("|%03-10.0x|\n", INT_MIN);
	pf = printf("|%03-10.0x|\n", INT_MIN);
	printf("\nft: %i pf: %i\n", ft, pf);

	ft = ft_printf("|%03-1.10x|\n", UINT_MAX);
	pf = printf("|%03-1.10x|\n", UINT_MAX);
	printf("\nft: %i pf: %i\n", ft, pf);
	
	printf("\033[0;35m __________%s__________\033[0;0m\n", "other_TESTS");
	ft = ft_printf("|%#6x|\n", UINT_MAX);
	pf = printf("|%#6x|\n", UINT_MAX);
	printf("\nft: %i pf: %i\n", ft, pf);

	ft = ft_printf("|%#06x|\n", 456);
	pf = printf("|%#06x|\n", 456);
	printf("\nft: %i pf: %i\n", ft, pf);

	ft = ft_printf("|%-#6x|\n", 456);
	pf = printf("|%-#6x|\n", 456);
	printf("\nft: %i pf: %i\n", ft, pf);

	ft = ft_printf("|%#.6x|\n", 456);
	pf = printf("|%#.6x|\n", 456);
	printf("\nft: %i pf: %i\n", ft, pf);

	ft = ft_printf("|%#10.6x|\n", 456);
	pf = printf("|%#10.6x|\n", 456);
	printf("\nft: %i pf: %i\n", ft, pf);

	ft = ft_printf("|%0#10x|\n", 456);
	pf = printf("|%0#10x|\n", 456);
	printf("\nft: %i pf: %i\n", ft, pf);
}

void	percent_test(void)
{
	printf("\033[0;36m __________%s__________\033[0;0m\n", "PERCENT_TESTS");

	int ft;
	int	pf;

	ft = ft_printf("|%|\n");
	pf = printf("|%|\n");
	printf("\nft: %i pf: %i\n", ft, pf);

	ft = ft_printf("|%");
	ft_printf("\n");
	pf = printf("|%");
	printf("\nft: %i pf: %i\n", ft, pf);

	ft = ft_printf("|%%|\n");
	pf = printf("|%%|\n");
	printf("\nft: %i pf: %i\n", ft, pf);

	ft = ft_printf("|%0-.%|\n");
	pf = printf("|%0-.%|\n");
	printf("\nft: %i pf: %i\n", ft, pf);

	ft = ft_printf("|%0-.4%|\n");
	pf = printf("|%0-.4%|\n");
	printf("\nft: %i pf: %i\n", ft, pf);

	ft = ft_printf("|%0-8.4%|\n");
	pf = printf("|%0-8.4%|\n");
	printf("\nft: %i pf: %i\n", ft, pf);

	ft = ft_printf("|%00-8%|\n");
	pf = printf("|%00-8%|\n");
	printf("\nft: %i pf: %i\n", ft, pf);

	ft = ft_printf("|%-6.4%|\n");
	pf = printf("|%-6.4%|\n");
	printf("\nft: %i pf: %i\n", ft, pf);

	ft = ft_printf("|%06.4%|\n");
	pf = printf("|%06.4%|\n");
	printf("\nft: %i pf: %i\n", ft, pf);

	ft = ft_printf("|%0-%|\n");
	pf = printf("|%0-%|\n");
	printf("\nft: %i pf: %i\n", ft, pf);

	ft = ft_printf("|%0-4%|\n");
	pf = printf("|%0-4%|\n");
	printf("\nft: %i pf: %i\n", ft, pf);

	ft = ft_printf("|%-04%|\n");
	pf = printf("|%-04%|\n");
	printf("\nft: %i pf: %i\n", ft, pf);

	ft = ft_printf("|%.3%|\n");
	pf = printf("|%.3%|\n");
	printf("\nft: %i pf: %i\n", ft, pf);

	ft = ft_printf("|%05%|\n");
	pf = printf("|%05%|\n");
	printf("\nft: %i pf: %i\n", ft, pf);

	ft = ft_printf("|% %|\n");
	pf = printf("|% %|\n");
	printf("\nft: %i pf: %i\n", ft, pf);

	ft = ft_printf("|%+%|\n");
	pf = printf("|%+%|\n");
	printf("\nft: %i pf: %i\n", ft, pf);

	ft = ft_printf("|%-5%|\n");
	pf = printf("|%-5%|\n");
	printf("\nft: %i pf: %i\n", ft, pf);
}
