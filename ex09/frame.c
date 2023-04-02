#include <stdio.h>
#include <string.h>

int main(int ac, const char **av)
{
    int max = 0, tmp = 0, i = 1;
    if (ac > 1)
    {
        while (i < ac)
        {
            tmp = strlen(av[i++]);
            if (tmp > max)
                max = tmp;
        }
        i = -4;
        while (i++ < max)
            printf("*");
        puts("");
        while (ac > 1)
        {
            tmp = printf("* %s ", *++av);
            while (tmp++ -2 <= max)
                printf(" ");
            printf("*\n");
            ac--;
        }
        i = -4;
        while (i++ < max)
            printf("*");
    }
    return (0);
}