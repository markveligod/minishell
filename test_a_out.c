#include <stdio.h>

int main(int ac, char **av)
{
    for (int i = 0; i < ac; i++)
        printf("Hello World!\n I do it!!!\nText: %s\n", av[i]);
    return (0);
}