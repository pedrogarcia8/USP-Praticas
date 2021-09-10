/* ----------------------------
	Nome: Pedro José Garcia
	Número USP: 11846943
-------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){   

    int cont, cont2, cont3 = 0; // contadores.
    char string[11];// armazenará uma string de até 10 caracteres.

    scanf("%s", string);// armazena a string digitada pelo usuário.

    for (cont = 0; string[cont]; cont++){// percorrerá até a string ser nula ("\0").
		
        if (string[cont] != '{')// verifica se não abriu uma chave.
            continue;// se não abriu, continua percorrendo a string até achar uma chave aberta "{".

        for (cont2 = cont + 1; string[cont2]; cont2++){// percorrerá a string da posição da chave aberta até a string ser nula ("\0").
            if (string[cont2] == '}'){//verifica se encontrou uma chave fechada "}".
                string[cont] = ' '; // se encontrou limpa a chave aberta "{".
                string[cont2] = ' ';// e limpa a chave fechada "}". 			
                break;// e volta para o for anterior.
            }
        }
    }
//A estrutura for acima serve para verificar se após uma chave aberta "{" existe uma fechada "}", se existir ele apaga as duas chaves, e repete isso até o final da string.
    
    for (cont = 0; string[cont]; cont++)// percorrerá até a string ser nula ("\0").
        if ((string[cont] == '}')||(string[cont] == '{'))//verifica se ainda restou uma chave aberta "{" ou uma chave fechada "}".
            cont3++;// se restou, adiciona mais 1 no terceiro contador "cont3".
//Se ainda restar chave aberta "{" ou chave fechada "}" é por que a sequência de chaves está incorreta.
    if (cont3 == 0)//verifica se o terceiro contador "cont3" é nulo.
        printf("Correto\n");//se sim, exibe a mensagem de sequência correta.
    else
        printf("Errado\n");//se não, exibe a mensagem de sequência errada.
    
    return 0;

}
