#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int aces_counter(int set_aces, int black_jack)
{
    static int aces;

    if (set_aces)
        aces++;
    else if (aces)
    {
        if (black_jack + aces - 1 + 11 <= 21)
            return (black_jack + aces + 10);
        else
            return (black_jack + aces);
    }
    return (black_jack);
}

int main(int ac, char **av)
{
    char *tmp;
    int i = 0, black_jack = 0;
    if (ac == 2)
    {
        while (av[1][i])
        {
            if (av[1][i] == 'A')
                aces_counter(1, 0);
            else if (av[1][i] == 'T' || av[1][i] == 'J' || av[1][i] == 'D' || av[1][i] == 'K')
                black_jack += 10;
            else if (av[1][i] >= '2' && av[1][i] <= '9')
            {
                tmp = strndup(av[1] + i, 1);
                black_jack += atoi(tmp);
                free(tmp);
            }
            else
                return (1);
            i++;
        }
        black_jack = aces_counter(0, black_jack);
        if (black_jack == 21)
            printf("%s\n", "Blackjack!");
        else
            printf("%d\n", black_jack);
        return (0);
    }
    return (1);
}