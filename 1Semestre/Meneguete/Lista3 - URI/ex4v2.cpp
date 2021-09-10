#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{   

    int i, j, ans = 0;
    char string[100000];

    scanf("%s", string);

    for (i = 0; string[i]; i++)
    {

        if (string[i] != '(')
            continue;

        for (j = i + 1; string[j]; j++)
        {

            if (string[j] == ')')
            {

                string[i] = ' ';
                string[j] = ' ';
                break;

            }

        }

    }

    
    for (i = 0; string[i]; i++)
        if (string[i] == '(')
            ans++;

    if (ans == 0)
        printf("Partiu RU!");
    else
        printf("Ainda temos %d assunto(s) pendente(s)!\n", ans);
    
    return 0;

}
