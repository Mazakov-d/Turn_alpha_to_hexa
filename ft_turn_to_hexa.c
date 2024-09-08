#import <unistd.h>
#import <stdlib.h>

int main(int ac, char **av)
{
    (void)ac;
    int i;
    int j;
    int asci;
    char    *hexa;

    hexa = malloc(16);
    hexa = "0123456789abcdef";
    i = 0;
    while (av[++i])
    {
        j = 0;
        while (av[i][j])
        {
            if ((av[i][j] <= 'z' && av[i][j] >= 'a') ||
                (av[i][j] >= 'A' && av[i][j] <= 'Z'))
            {
                asci = av[i][j];
                write(1, &hexa[asci / 16], 1);
                write(1, &hexa[asci % 16], 1);
            }
            else
                write(1, &av[i][j], 1);
            j++;
        }
        write(1, "\n", 1);
    }
}