/* 
------------------------------
	Nome: Pedro Jos� Garcia 
	N�mero USP: 11846943
------------------------------
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <windows.h>
#include <locale.h>

struct auxiliar{//�nicio estrutura (estrutura para auxiliar na exclus�o de produtos alugados).
	char codProduto[11];//armazena o c�digo do produto de at� 10 n�meros.
	char cpfCliente[12];//armazena o CPF do cliente (11 n�meros).
	char dataLocacao[9];//armazena a data da loca��o (8 n�meros).
	char dataDevolucao[9];//armazena a data da devoluc�o (8 n�meros).
};//fim estrutura

typedef struct auxiliar Aux;//cria um alias para a estrutura.

int carregaMenu();//fun��o para construir o menu.
bool cadastraCliente();//fun��o para cadastrar clientes.
bool cadastraProduto();//fun��o para cadastrar produtos.
bool locacaoProduto();//fun��o para alugar produtos.
bool devolucaoProduto();//fun��o para devolver produtos.
void limpaTela();//fun��o para limpar a tela.
bool verificaCliente(char * arqnome, int intervalo, char * cpfClienteD);//fun��o para verificar os clientes.
bool verificaProduto(char * arqnome, int intervalo, char * codProdutoD);//fun��o para verificar os produtos.
char * inverteData(char * data);//fun��o para formatar a data assim AAAAMMDD.
char * excluiProdutoAlugado(char * codProdutoD, char * cpfClienteD);//fun��o para excluir um produto, que foi devolvido, do arquivo de produtos alugados. 
FILE * abrirArquivo(char * nome, char * tipoAbertura);//fun��o para abrir um arquivo.

int main(){
	setlocale(LC_ALL, "Portuguese");//para funcionar a acentua��o nos printfs.
	
	int resp;
	
	do{//in�cio while.
	
		limpaTela();//limpa a tela.
		resp = carregaMenu();//chama a fun��o que carrega o menu e pega a op��o escolhida pelo usu�rio.	
		limpaTela();//limpa a tela.
		
		switch(resp){//in�cio switch-case.
			case 1://se a op��o for 1.
				if(!(cadastraCliente()))//verifica se foi poss�vel cadastrar o cliente.
					printf("\nN�o foi poss�vel cadastrar o cliente\n");
				break;
			case 2://se a op��o for 2.
				if(!(cadastraProduto()))//verifica se foi poss�vel cadastrar o produto.
					printf("\nN�o foi poss�vel cadastrar o produto\n");
				break;
			case 3://se a op��o for 3.
				if(!(locacaoProduto()))//verifica se foi poss�vel alugar o produto.
					printf("\nN�o foi poss�vel alugar o produto\n");
				break;	
			case 4://se a op��o for 4.
				if(!(devolucaoProduto()))//verifica se foi poss�vel devolver o produto.
					printf("\nN�o foi poss�vel devolver o produto\n");
				break;
		}//fim switch-case.
		
		Sleep(1000);
		
	}while(resp != 0);//fim while.
	
	return 0;
}

int carregaMenu(){//in�cio fun��o para construir o menu.
	int resp = 0;
	
	printf("MENU\n");
	printf("1 - Cadastro de Clientes\n");
	printf("2 - Cadastro de Produtos\n");
	printf("3 - Loca��o de Produtos\n");
	printf("4 - Devolu��o de Produtos\n");
	printf("0 - Finalizar Programa\n");
	
	scanf("%d",&resp);//armazena a resposta do usu�rio.
	
	return resp;//retorna a op��o escolhida pelo usu�rio.
}//fim fun��o para construir o menu.

void limpaTela(){//in�cio fun��o para limpar a tela.
	system("cls");//limpa a tela.
}//fim fun��o para limpar a tela.

bool cadastraCliente(){//in�cio fun��o para cadastrar clientes.
/*nome[101] -> armazena um nome de at� 100 caracteres. cpf[12] -> armazena um cpf com 11 n�meros.  
  endereco[301] -> armazena um endere�o de at� 300 caracteres. dataNascimento[9] -> armazena uma data de nascimento de 8 caracteres*/
	char nome[101], cpf[12], endereco[301], dataNascimento[9];
	FILE * cadastroCliente;//ponteiro para um arquivo.
	
	printf("Digite o nome: ");
	scanf(" %[^\n]s",nome);//armazena na vari�vel nome at� o usu�rio apertar enter.
	
	printf("\nDigite o CPF (somente numeros): ");
	scanf("%s",cpf);//armazena o cpf do cliente.
	
	if(verificaCliente("cadastroCliente.txt",4,cpf)){//�nicio if (verifica se j� existe cliente com esse cpf).
		printf("\nJ� existe cliente com este CPF!\n");
		return false;//se j� existir retorna falso.
	}//fim if.
	
	printf("\nDigite o endere�o: ");
	scanf(" %[^\n]s",endereco);//armazena na vari�vel endereco at� o usu�rio apertar enter.
	
	printf("\nDigite a data de nascimento (somente n�meros) (DDMMAAAA): ");
	scanf("%s",dataNascimento);//armazena a data de nascimento do cliente.
	
	cadastroCliente = abrirArquivo("cadastroCliente.txt","a+");//chama a fun��o para abrir o arquivo.
	if(fprintf(cadastroCliente,"%s\n%s\n%s\n%s\n",nome,cpf,endereco,dataNascimento)){//escreve os dados no arquivo de cadastro de cliente e verifica se gravou.
		printf("\nCliente cadastrado com sucesso!\n"); //se gravou, exibe a mensagem de sucesso.
		Sleep(1000);//pausa a exibi��o por 1 segundo.
		fclose(cadastroCliente);//fecha o arquivo.
		return true; 
	}else //se n�o gravou, retorna falso.
		return false;
}//fim fun��o para cadastrar clientes.

bool cadastraProduto(){//in�cio fun��o para cadastrar produtos.
/*codProduto[12] -> armazena o c�digo do produto com at� 10 n�meros. nome[101] -> armazena um nome de at� 100 caracteres.  
  genero[31] -> armazena um g�nero de at� 30 caracteres. autor[101] -> armazena o nome do autor, at� 100 caracteres.*/
	char codProduto[11], nome[101], genero[31], autor[101];
	FILE * cadastroProduto;//ponteiro para um arquivo.
	
	printf("Digite o nome: ");
	scanf(" %[^\n]s",nome);//armazena na vari�vel nome at� o usu�rio apertar enter.
	
	printf("\nDigite o g�nero: ");
	scanf(" %[^\n]s",genero);//armazena na vari�vel g�nero at� o usu�rio apertar enter.
	
	printf("\nDigite o c�digo do produto: ");
	scanf("%s",codProduto);//armazena o c�digo do produto.
	
	if(verificaProduto("cadastroProduto.txt",4,codProduto)){//in�cio if (verifica se j� existe produto com esse c�digo).
		printf("\nJ� existe produto com este codigo!\n");//se sim, exibe a mensagem e retorna falso.
		return false;
	}//fim if.
	
	printf("\nDigite o autor: ");
	scanf(" %[^\n]s",autor);//armazena na vari�vel autor at� o usu�rio apertar enter.
	
	cadastroProduto = abrirArquivo("cadastroProduto.txt","a+");//chama a fun��o para abrir o arquivo.
	if(fprintf(cadastroProduto,"%s\n%s\n%s\n%s\n",codProduto,nome,genero,autor)){//escreve os dados no arquivo de cadastro de produto e verifica se gravou.
		printf("\nProduto cadastrado com sucesso!\n");//se gravou, exibe a mensagem de sucesso.
		Sleep(1000);// pausa a exibi��o por 1 segundo
		fclose(cadastroProduto);// fecha o arquivo
		return true; 
	}else//se n�o gravou, retorna falso.
		return false;
}//fim fun��o para cadastrar produtos.

bool locacaoProduto(){//in�cio fun��o para alugar produtos.
/*dataLocacao[9] -> armazena a data de loca��o, 8 n�meros. dataDevolucao[101] -> armazena a data de devolu��o, 8 n�meros.  
  codProdutoD[11] -> armazena o c�digo do produto com at� 10 n�meros. cpfClienteD[12] -> armazena o CPF do cliente, 11 n�meros.*/
	char dataLocacao[9], dataDevolucao[9], codProdutoD[11], cpfClienteD[12];
	float valorLocacao, valorPago;//valorLocacao -> armazena o valor de aluguel do produto. valorPago -> armazena o valor pago pelo cliente.
	FILE * produtosAlugados;//ponteiro para um arquivo.
	
	printf("Digite o c�digo do produto: ");
	scanf("%s",codProdutoD);//armazena o c�digo do produto.

	if(!verificaProduto("cadastroProduto.txt",4,codProdutoD))//verifica se o produto existe.
		return false;//se n�o existir, retorna falso.
		
	if(verificaProduto("produtosAlugados.txt",4,codProdutoD)){//verifica se o produto foi alugado.
		printf("\nO produto j� foi alugado!\n");//se sim, exibe a mensagem e retorna falso.
		return false;
	}
		
	printf("\nDigite o CPF do cliente: ");
	scanf("%s",cpfClienteD);//armazena o CPF do cliente.

	if(!verificaCliente("cadastroCliente.txt",4,cpfClienteD))//verifica se o cliente existe.
		return false;//se n�o existir, retorna falso.

	if(verificaCliente("produtosAlugados.txt",4,cpfClienteD)){//verifica se o cliente alugou algum produto.
		printf("\nO cliente j� possui um produto alugado!\n");//se sim, exibe a mensagem e retorna falso.
		return false; 	
	}
    
	printf("\nDigite a data de loca��o (somente numeros) (DDMMAAAA): ");
	scanf("%s",dataLocacao);//armazena a data de loca��o.
	
	printf("\nDigite a data de devolu��o (somente numeros) (DDMMAAAA): ");
	scanf("%s",dataDevolucao);//armazena a data de devolu��o.
	
	printf("\nDigite o valor da loca��o: ");
	scanf("%f",&valorLocacao);//armazena o valor de loca��o.
	
	printf("\nDigite o valor pago pelo cliente: ");
	scanf("%f",&valorPago);//armazena o valor de pago.
	
	if(valorPago > valorLocacao)//verifica se o valor pago � maior que o de loca��o.
		printf("\nTroco: %.2f",valorPago - valorLocacao);//se sim, exibe o valor do troco.
	else{//se n�o.
		if(valorPago < valorLocacao)//verifica se o valor pago � menor que o de loca��o.
			printf("\nFalta %.2f reais!",valorLocacao - valorPago);//se sim, exibe o valor que falta o cliente pagar.
	}
	
	produtosAlugados = abrirArquivo("produtosAlugados.txt","a+");//chama a fun��o para abrir o arquivo.
	if(fprintf(produtosAlugados,"%s\n%s\n%s\n%s\n",codProdutoD,cpfClienteD,dataLocacao,dataDevolucao)){//escreve os dados no arquivo de produtos alugados e verifica se gravou.
		printf("\nProduto alugado com sucesso!\n");//se sim, exibe a mensagem de sucesso.
		Sleep(1000);//pausa a exibi��o por 1 segundo.
		fclose(produtosAlugados);//fecha o arquivo.
		return true;
	}else//se n�o gravou, retorna falso.
		return false;
}//fim fun��o para alugar produtos.

bool devolucaoProduto(){//in�cio fun��o para devolver produtos
/*dataDevolucao[9] -> armazena a data de devolucao retornada pela fun��o excluiProdutoAlugado, 8 n�meros. dataDevolucao[101] -> armazena a data de devolu��o, 8 n�meros.  
  codProdutoD[11] -> armazena o c�digo do produto com at� 10 n�meros. cpfClienteD[12] -> armazena o CPF do cliente, 11 n�meros.*/
	char codProdutoD[11], cpfClienteD[12], dataDevolucao[9], dataDevolucaoD[9];
	FILE * produtosDevolvidos;//ponteiro para um arquivo.
	
	printf("Digite o c�digo do produto: ");
	scanf("%s",codProdutoD);//armazena o c�digo do produto.
	
	if(!verificaProduto("produtosAlugados.txt",4,codProdutoD))//verifica se o produto foi alugado.
		return false;//se n�o, retorna falso.
	
	printf("\nDigite o CPF do cliente: ");
	scanf("%s",cpfClienteD);//armazena o CPF do cliente.
	
	if(!verificaCliente("produtosAlugados.txt",4,cpfClienteD))//verifica se o cliente possui produtos alugados.
		return false;//se n�o, retorna falso.
		
	//chama a fun��o excluiProdutoAlugado, chama a fun��o inverteData, e copia a data no formato AAAAMMDD, armazenando-a na vari�vel dataDevolucao.
	strcpy(dataDevolucao,inverteData(excluiProdutoAlugado(codProdutoD,cpfClienteD)));

	printf("\nDigite a data de devolu��o(somente numeros): ");
	scanf("%s",dataDevolucaoD);//armazena a data de devolu��o.
	
	strcpy(dataDevolucaoD,inverteData(dataDevolucaoD));//chama a fun��o inverteData, e copia a data no formato AAAAMMDD, armazenando-a na vari�vel dataDevolucaoD.

	if(atoi(dataDevolucaoD) > atoi(dataDevolucao))//verifica se a data que o cliente devolveu e maior que a data de devolu��o do produto.
		printf("\nO cliente dever� pagar R$5,00 pelo atraso\n");//se sim, exibe a mensagem de juros.

	produtosDevolvidos = abrirArquivo("produtosDevolvidos.txt","a+");//chama a fun��o para abrir o arquivo.	
	//escreve os dados do produto devolvido no arquivo de produtos devolvidos e verifica se gravou.
	if(!fprintf(produtosDevolvidos,"%s\n%s\n%s\n",codProdutoD,cpfClienteD,dataDevolucaoD))
		return false;//se n�o gravou, retorna falso.
	fclose(produtosDevolvidos);//fecha o arquivo.
	
	printf("\nDevolu��o feita com sucesso!\n");
	
	Sleep(1000);//pausa a exibi��o por 1 segundo.
	
	return true;
}//fim fun��o para devolver produtos

bool verificaCliente(char * arqnome, int intervalo, char * cpfClienteD){//�nicio fun��o para verificar cliente.
	int cont = 0, tamanho;//cont -> contador. tamanho -> armazena o tamanha do arquivo.
	char cpfCliente[12];//armazena o CPF do cliente.
	FILE * arq;//ponteiro para um arquivo.
	
	arq = abrirArquivo(arqnome,"a+");//chama a fun��o para abrir o arquivo.
	
	fseek(arq, 0, SEEK_END);//vai at� o fim do arquivo.
    tamanho = ftell(arq);//armazena quantos caracteres tem no arquivo.
    
    if(tamanho > 0){//verifica se o arquivo est� vazio.
		fseek(arq, 0, SEEK_SET);//se n�o est�, vai at� in�cio do arquivo.
		
		while(!feof(arq)){//in�cio while (percorrer� at� o final do arquivo).
			if((cont == intervalo-3) || (cont % intervalo == 0)){//verifica se o leitor est� na posi��o que est� gravada o CPF do cliente.
				fscanf(arq,"%s",cpfCliente);//se sim, armazena o CPF do cliente.
				
				if(!stricmp(cpfCliente,cpfClienteD)){//verifica se o encontrou o CPF do cliente.
					fclose(arq);//se sim, fecha o arquivo e retorna verdadeiro.
					return true;
				}
				cont = 0;//zera o contador.		
			}
			
			cont++;//acrescenta mais 1 no contador.
		}//fim while.	
	}//fim if.
	
	fclose(arq);//fecha o arquivo.
	
	return false;
}//fim fun��o para verificar cliente.

bool verificaProduto(char * arqnome, int intervalo, char * codProdutoD){//in�cio fun��o para verificar o produto.
	int cont = 0, tamanho;//cont -> contador. tamanho -> armazena o tamanha do arquivo.
	char codProduto[11];//armazena o c�digo do produto.
	FILE * arq;//ponteiro para um arquivo.
	
	arq = abrirArquivo(arqnome,"a+");//chama a fun��o para abrir o arquivo.

	fseek(arq, 0, SEEK_END);//vai at� o fim do arquivo.
    tamanho = ftell(arq);//armazena quantos caracteres tem no arquivo.
    
    if(tamanho > 0){//verifica se o arquivo est� vazio.
    	fseek(arq, 0, SEEK_SET);//se n�o est�, vai at� in�cio do arquivo.
    	
		while(!feof(arq)){//in�cio while (percorrer� at� o final do arquivo).
			if((cont == 0) || (cont % intervalo == 0)){//verifica se o leitor est� na posi��o que est� gravada o c�digo do produto.
				fscanf(arq,"%s",codProduto);//se sim, armazena o c�digo do produto.
				
				if(!stricmp(codProduto,codProdutoD)){//verifica se o encontrou o c�digo do produto.
					fclose(arq);//se sim, fecha o arquivo e retorna verdadeiro.
					return true;
				}
				
				cont = 0;//zera o contador.		
			}
			
			cont++;//acrescenta mais 1 no contador.
		}//fim while.
	}//fim if.
	
	fclose(arq);//fecha o arquivo.
	
	return false;	
}//fim fun��o para verificar o produto.

char * inverteData(char * data){//in�cio fun��o para formatar a data assim AAAAMMDD.
	char dataI[9];//armazena a data formatada.
	int cont,cont2;//contadores.
	
	for(cont = 0,cont2 = 4; cont < 4,cont2 < 8;cont++,cont2++){//percorrer� os 4 n�meros do ano na data (AAAA).
		dataI[cont] = data[cont2];//armazena os 4 n�meros do ano da data no come�o da data formatada.
	}
	
	for(cont = 4,cont2 = 2; cont < 7,cont2 < 4;cont++,cont2++){//percorrer� os 2 n�meros do m�s na data (MM).
		dataI[cont] = data[cont2];//armazena os 2 n�meros do m�s da data no meio da data formatada.
	}
	
	for(cont = 6,cont2 = 0; cont < 9,cont2 < 2;cont++,cont2++){//percorrer� os 2 n�meros do dia na data (DD).
		dataI[cont] = data[cont2];//armazena os 2 n�meros do dia da data no final da data formatada.
	}
	
	return dataI;//retorna a data formatada.
}//fim fun��o para formatar a data assim AAAAMMDD.

char * excluiProdutoAlugado(char * codProdutoD, char * cpfClienteD){//in�cio fun��o para excluir um produto, que foi devolvido, do arquivo de produtos alugados. 
	FILE * produtosAlugados;//ponteiro para um arquivo.
	int cont = 0, cont2 = 0, tamanho = 0;//cont,cont2 -> contadores. tamanho-> armazena o tamanha do arquivo.
	Aux * pA;//ponteiro para a estrutura auxiliar.
	char data[9], c;//data[9] -> armazena a data que ser� retornada. c -> armazena cada caractere do arquivo.
	
    produtosAlugados = abrirArquivo("produtosAlugados.txt","r");//chama a fun��o para abrir o arquivo.
		
	fseek(produtosAlugados, 0, SEEK_END);//vai at� o fim do arquivo.
    tamanho = ftell(produtosAlugados);//armazena quantos caracteres tem no arquivo.
    
    if(tamanho > 0){//verifica se o arquivo est� vazio.	
    	fseek(produtosAlugados, 0, SEEK_SET);//se n�o est�, vai at� in�cio do arquivo.
    	
    	while ((c = fgetc(produtosAlugados)) != EOF) {//percorrer� at� o final do arquivo.
        	if (c == '\n')//verifica se o caractere � igual ao caractere de "quebra de linha".
        		cont2++;//se sim, acrescenta mais 1 no contador para contar o n�mero de linhas que o arquivo possui.
    	}//isso servir� para contar quantos blocos de registros existe no arquivo de produtos alugados. Bloco -> codProduto, cpfCliente, dataLocacao, dataDevolucao.
    	
    	cont2 = cont2/4;//divide o n�mero de linhas do arquivo por 4 para pegar o n�mero de blocos no arquivo.
    	pA = (Aux *) malloc(cont2 * sizeof(Aux));//aloca "cont2s" espa�os na mem�ria para a estrutura auxiliar.
    	cont = 0;//zera o contador;
    	
    	fseek(produtosAlugados, 0, SEEK_SET);//volta para o in�cio do arquivo.
    	
		while(cont2 > 0){//percorrer� o arquivo, "cont2s" vezes.
		//l� um bloco do arquivo.
			fscanf(produtosAlugados,"%s %s %s %s",pA[cont].codProduto,pA[cont].cpfCliente,pA[cont].dataLocacao,pA[cont].dataDevolucao);
			cont++;	//acrescenta mais 1.
			cont2--;//decresce 1.
		}
	}
	
	fclose(produtosAlugados);//fecha o arquivo.
	
	for(cont2 = 0; cont2 < cont; cont2++){//percorerr� a estrutura auxiliar.
		if(!stricmp(pA[cont2].codProduto,codProdutoD)){//verifica se achou o c�digo do produto.
			if(stricmp(pA[cont2].cpfCliente,cpfClienteD)){//se sim, verifica se o CPF que o cliente falou � igual ao CPF do cliente que alugou o produto. 
				printf("\nN�o foi esse cliente que alugou esse produto!\n");//se n�o for igual, exibe a mensagem.
				exit(0);//e finaliza o programa.
			}
		}	
	}
	
	produtosAlugados = abrirArquivo("produtosAlugados.txt","w");//chama a fun��o para abrir o arquivo e abre no tipo "w" para sobrescrever o conte�do do arquivo.
		
    for(cont2 = 0; cont2 < cont; cont2++){//percorerr� o n�mero de blocos.
    	if(stricmp(pA[cont2].codProduto,codProdutoD))//verifica se o c�digo do produto da estrutura auxiliar � igual ao c�digo do produto devolvido.
    	//se n�o for igual, escreve o bloco no arquivo de produtos alugados.
    		fprintf(produtosAlugados,"%s\n%s\n%s\n%s\n",pA[cont2].codProduto,pA[cont2].cpfCliente,pA[cont2].dataLocacao,pA[cont2].dataDevolucao);
    	else//se for igual.
    		strcpy(data,pA[cont2].dataDevolucao);//copia a data de devolu��o do produto devolvido para a vari�vel data.
    }	

	fclose(produtosAlugados);//fecha o arquivo.
	
	free(pA);//libera a mem�ria alocada para pA.

	return data;//retorna a data de devolu��o do produto devolvido.
}//fim fun��o para excluir um produto, que foi devolvido, do arquivo de produtos alugados. 

FILE * abrirArquivo(char * nome, char * tipoAbertura){//in�cio fun��o para abrir o arquivo.
	if(fopen(nome,tipoAbertura) != NULL)//abre o arquivo e verifica se conseguiu abrir.
		return fopen(nome,tipoAbertura);//se conseguiu, retorna o arquivo aberto.
	else{//se n�o conseguiu, exibe a mensagem de erro e finaliza o programa.
		printf("\nN�o foi poss�vel abrir o arquivo\n");
		exit(0);
	}
}
