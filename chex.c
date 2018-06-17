#include <stdio.h>

int print_hex_colour(char *line, int size)
{
    int x,y;

    for(x = 0; x < size; x++)
    {
        y = (int)line[x];
        if((y > 47) && (y < 53))  // 0 - 4
            printf("\033[037;%dm",(40 + (y - 47)));
        if((y > 52) && (y < 58))  // 5 - 9
            printf("\033[030;%dm",(40 + (y - 52)));
        if((y > 64) && (y < 68))  // A - C
            printf("\033[035;%dm",(40 + (y - 64)));
        if((y > 67) && (y < 71))  // D - F
            printf("\033[033;%dm",(44 + (y - 67)));
        if((y > 96) && (y < 100)) // a - c
            printf("\033[035;%dm",(40 + (y - 96)));
        if((y > 99) && (y < 103)) // d - f
            printf("\033[033;%dm",(44 + (y - 99)));
        printf("%c",line[x]);
        printf("\033[0m"); // reset
    }
    return 0;
}

int main(int ac, char **av)
{
    char *line = NULL;
    size_t size, num;

    while ((num = getline(&line, &size, stdin)) != -1) 
        print_hex_colour(line, num);
    return 0;
}
