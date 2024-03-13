#include <stdarg.h>
#include <stdio.h>

int t_str(const char *chaine)
{
    int i = 0;
    while (chaine[i] != '\0')
    {
        i++;
    }
    return i;
}

void affichage_char(const char *chaine)
{
    int taille_chaine = t_str(chaine);
    for (int k = 0; k < taille_chaine; k++)
    {
        putchar(chaine[k]);
    }
}

void trasfo_base(int n, char *base)
{
    if (base == 0)
    {
        return;
    }
    int t_base = t_str(base);

    char tab[10000];

    int indice = 0;

    while (n / t_base > 0)
    {
        tab[indice++] = base[n % t_base];
        n = n / t_base;
    }
    tab[indice++] = base[n % t_base];

    while (indice != 0)
    {
        putchar(tab[--indice]);
    }
}

void test_char(char val)
{
    putchar(val);
}

void test_str(char *valeur)
{
    if (valeur == NULL)
    {
        affichage_char("(null)");
    }
    else
    {
        affichage_char(valeur);
    }
}

void test_integer(int valeur)
{
    if (valeur < 0)
    {
        putchar('-');
        valeur = -valeur;
    }
    int inv = 0;

    while (valeur != 0)
    {
        inv *= 10;
        inv += valeur % 10;
        valeur /= 10;
    }

    while (inv != 0)
    {
        putchar(inv % 10 + '0');
        inv /= 10;
    }
}

void test_unsigned_integer(unsigned valeur)
{
    unsigned inv = 0;

    while (valeur != 0)
    {
        inv *= 10;
        inv += valeur % 10;
        valeur /= 10;
    }

    while (inv != 0)
    {
        putchar(inv % 10 + '0');
        inv /= 10;
    }
}

int tinyprintf(const char *format, ...)
{
    va_list argument;
    va_start(argument, format);
    int taille_chaine = t_str(format);
    for (int k = 0; k < taille_chaine; k++)
    {
        if (format[k] == '%')
        {
            if (format[k + 1] == '%')
            {
                affichage_char("%");
                k++;
            }

            else if (format[k + 1] == 's')
            {
                test_str(va_arg(argument, char *));
                k++;
            }

            else if (format[k + 1] == 'd')
            {
                test_integer(va_arg(argument, int));
                k++;
            }

            else if (format[k + 1] == 'u')
            {
                test_unsigned_integer(va_arg(argument, unsigned));
                k++;
            }

            else if (format[k + 1] == 'c')
            {
                test_char(va_arg(argument, int));
                k++;
            }

            else if (format[k + 1] == 'o')
            {
                trasfo_base(va_arg(argument, int), "01234567");
                k++;
            }

            else if (format[k + 1] == 'x')
            {
                trasfo_base(va_arg(argument, int), "0123456789abcdef");
                k++;
            }
        }
        else
        {
            putchar(format[k]);
        }
    }
    return 0;
}

int main(void)
{
    tinyprintf("%x", 10);
}
