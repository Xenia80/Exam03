#include <unistd.h>
#include <stdarg.h>
#include <limits.h>
#include <stdio.h>

int g_var = 0;

void ft_putnbr(long digit, int len, char *str)
{
	if (digit >= len)
		ft_putnbr(digit/len, len, str);
	write(1, &str[digit % len], 1);
	g_var++;
}

int ft_printf(const char *str, ...)
{
	va_list ap;
	va_start(ap, str);
	while(*str)
	{
		if(*str == '%')
		{
			str++;
			if (*str == 's')
			{
				int len = 0;
				char *nstr = va_arg(ap, char *);
				if (!nstr)
					nstr = "null";
				while (nstr[len])
					len++;
				g_var += len;
				write(1, nstr, len);
				
			}
			else if (*str == 'd')
			{
				int d = va_arg(ap, int);
				if (d == INT_MIN)
				{
					write(1, "-2147483648", 11);
					g_var += 11;
				}
				else
				{
					if (d < 0)
					{
						write (1, "-", 1);
						g_var++;
						d = -d;
					}
					ft_putnbr(d, 10, "0123456789");
				}
			}
			else if (*str == 'x')
			{
				unsigned int x = va_arg(ap, unsigned int);
				ft_putnbr(x, 16, "0123456789abcdef");
			}
			str++;
		}
		else
			g_var += write(1, str++, 1);
	}
	va_end(ap);
	return (g_var);
}

int main ()
{
	ft_printf("%s\n", "dfgdgfhnhgngdh");
	printf("%s\n", "dfgdgfhnhgngdh");
	ft_printf("%d\n", 10);
	printf("%d\n", 10);
	ft_printf("%x\n", 15);
	printf("%x\n", 15);
	ft_printf("%ld\n", -2147483648);
	printf("%ld\n", -2147483648);
	ft_printf("%d\n", -75);
	printf("%d\n", -75);
	ft_printf("%d\n", 7);
	printf("%d\n", 7);
	ft_printf("%d\n", 100);
	printf("%d\n", 100);
	ft_printf("%d\n", 125);
	printf("%d\n", 125);
}