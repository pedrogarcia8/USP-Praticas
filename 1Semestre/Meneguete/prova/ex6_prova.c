/* ----------------------------
	Nome: Pedro Jos� Garcia
	N�mero USP: 11846943
-------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){   

    int cont, cont2, cont3 = 0; // contadores.
    char string[11];// armazenar� uma string de at� 10 caracteres.

    scanf("%s", string);// armazena a string digitada pelo usu�rio.

    for (cont = 0; string[cont]; cont++){// percorrer� at� a string ser nula ("\0").
		
        if (string[cont] != '{')// verifica se n�o abriu uma chave.
            continue;// se n�o abriu, continua percorrendo a string at� achar uma chave aberta "{".

        for (cont2 = cont + 1; string[cont2]; cont2++){// percorrer� a string da posi��o da chave aberta at� a string ser nula ("\0").
            if (string[cont2] == '}'){//verifica se encontrou uma chave fechada "}".
                string[cont] = ' '; // se encontrou limpa a chave aberta "{".
                string[cont2] = ' ';// e limpa a chave fechada "}". 			
                break;// e volta para o for anterior.
            }
        }
    }
//A estrutura for acima serve para verificar se ap�s uma chave aberta "{" existe uma fechada "}", se existir ele apaga as duas chaves, e repete isso at� o final da string.
    
    for (cont = 0; string[cont]; cont++)// percorrer� at� a string ser nula ("\0").
        if ((string[cont] == '}')||(string[cont] == '{'))//verifica se ainda restou uma chave aberta "{" ou uma chave fechada "}".
            cont3++;// se restou, adiciona mais 1 no terceiro contador "cont3".
//Se ainda restar chave aberta "{" ou chave fechada "}" � por que a sequ�ncia de chaves est� incorreta.
    if (cont3 == 0)//verifica se o terceiro contador "cont3" � nulo.
        printf("Correto\n");//se sim, exibe a mensagem de sequ�ncia correta.
    else
        printf("Errado\n");//se n�o, exibe a mensagem de sequ�ncia errada.
    
    return 0;

}
