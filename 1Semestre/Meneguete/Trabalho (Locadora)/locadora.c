/* 
------------------------------
	Nome: Pedro José Garcia 
	Número USP: 11846943
------------------------------
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <windows.h>
#include <locale.h>

struct auxiliar{//ínicio estrutura (estrutura para auxiliar na exclusão de produtos alugados).
	char codProduto[11];//armazena o código do produto de até 10 números.
	char cpfCliente[12];//armazena o CPF do cliente (11 números).
	char dataLocacao[9];//armazena a data da locação (8 números).
	char dataDevolucao[9];//armazena a data da devolucão (8 números).
};//fim estrutura

typedef struct auxiliar Aux;//cria um alias para a estrutura.

int carregaMenu();//função para construir o menu.
bool cadastraCliente();//função para cadastrar clientes.
bool cadastraProduto();//função para cadastrar produtos.
bool locacaoProduto();//função para alugar produtos.
bool devolucaoProduto();//função para devolver produtos.
void limpaTela();//função para limpar a tela.
bool verificaCliente(char * arqnome, int intervalo, char * cpfClienteD);//função para verificar os clientes.
bool verificaProduto(char * arqnome, int intervalo, char * codProdutoD);//função para verificar os produtos.
char * inverteData(char * data);//função para formatar a data assim AAAAMMDD.
char * excluiProdutoAlugado(char * codProdutoD, char * cpfClienteD);//função para excluir um produto, que foi devolvido, do arquivo de produtos alugados. 
FILE * abrirArquivo(char * nome, char * tipoAbertura);//função para abrir um arquivo.

int main(){
	setlocale(LC_ALL, "Portuguese");//para funcionar a acentuação nos printfs.
	
	int resp;
	
	do{//início while.
	
		limpaTela();//limpa a tela.
		resp = carregaMenu();//chama a função que carrega o menu e pega a opção escolhida pelo usuário.	
		limpaTela();//limpa a tela.
		
		switch(resp){//início switch-case.
			case 1://se a opção for 1.
				if(!(cadastraCliente()))//verifica se foi possível cadastrar o cliente.
					printf("\nNão foi possível cadastrar o cliente\n");
				break;
			case 2://se a opção for 2.
				if(!(cadastraProduto()))//verifica se foi possível cadastrar o produto.
					printf("\nNão foi possível cadastrar o produto\n");
				break;
			case 3://se a opção for 3.
				if(!(locacaoProduto()))//verifica se foi possível alugar o produto.
					printf("\nNão foi possível alugar o produto\n");
				break;	
			case 4://se a opção for 4.
				if(!(devolucaoProduto()))//verifica se foi possível devolver o produto.
					printf("\nNão foi possível devolver o produto\n");
				break;
		}//fim switch-case.
		
		Sleep(1000);
		
	}while(resp != 0);//fim while.
	
	return 0;
}

int carregaMenu(){//início função para construir o menu.
	int resp = 0;
	
	printf("MENU\n");
	printf("1 - Cadastro de Clientes\n");
	printf("2 - Cadastro de Produtos\n");
	printf("3 - Locação de Produtos\n");
	printf("4 - Devolução de Produtos\n");
	printf("0 - Finalizar Programa\n");
	
	scanf("%d",&resp);//armazena a resposta do usuário.
	
	return resp;//retorna a opção escolhida pelo usuário.
}//fim função para construir o menu.

void limpaTela(){//início função para limpar a tela.
	system("cls");//limpa a tela.
}//fim função para limpar a tela.

bool cadastraCliente(){//início função para cadastrar clientes.
/*nome[101] -> armazena um nome de até 100 caracteres. cpf[12] -> armazena um cpf com 11 números.  
  endereco[301] -> armazena um endereço de até 300 caracteres. dataNascimento[9] -> armazena uma data de nascimento de 8 caracteres*/
	char nome[101], cpf[12], endereco[301], dataNascimento[9];
	FILE * cadastroCliente;//ponteiro para um arquivo.
	
	printf("Digite o nome: ");
	scanf(" %[^\n]s",nome);//armazena na variável nome até o usuário apertar enter.
	
	printf("\nDigite o CPF (somente numeros): ");
	scanf("%s",cpf);//armazena o cpf do cliente.
	
	if(verificaCliente("cadastroCliente.txt",4,cpf)){//ínicio if (verifica se já existe cliente com esse cpf).
		printf("\nJá existe cliente com este CPF!\n");
		return false;//se já existir retorna falso.
	}//fim if.
	
	printf("\nDigite o endereço: ");
	scanf(" %[^\n]s",endereco);//armazena na variável endereco até o usuário apertar enter.
	
	printf("\nDigite a data de nascimento (somente números) (DDMMAAAA): ");
	scanf("%s",dataNascimento);//armazena a data de nascimento do cliente.
	
	cadastroCliente = abrirArquivo("cadastroCliente.txt","a+");//chama a função para abrir o arquivo.
	if(fprintf(cadastroCliente,"%s\n%s\n%s\n%s\n",nome,cpf,endereco,dataNascimento)){//escreve os dados no arquivo de cadastro de cliente e verifica se gravou.
		printf("\nCliente cadastrado com sucesso!\n"); //se gravou, exibe a mensagem de sucesso.
		Sleep(1000);//pausa a exibição por 1 segundo.
		fclose(cadastroCliente);//fecha o arquivo.
		return true; 
	}else //se não gravou, retorna falso.
		return false;
}//fim função para cadastrar clientes.

bool cadastraProduto(){//início função para cadastrar produtos.
/*codProduto[12] -> armazena o código do produto com até 10 números. nome[101] -> armazena um nome de até 100 caracteres.  
  genero[31] -> armazena um gênero de até 30 caracteres. autor[101] -> armazena o nome do autor, até 100 caracteres.*/
	char codProduto[11], nome[101], genero[31], autor[101];
	FILE * cadastroProduto;//ponteiro para um arquivo.
	
	printf("Digite o nome: ");
	scanf(" %[^\n]s",nome);//armazena na variável nome até o usuário apertar enter.
	
	printf("\nDigite o gênero: ");
	scanf(" %[^\n]s",genero);//armazena na variável gênero até o usuário apertar enter.
	
	printf("\nDigite o código do produto: ");
	scanf("%s",codProduto);//armazena o código do produto.
	
	if(verificaProduto("cadastroProduto.txt",4,codProduto)){//início if (verifica se já existe produto com esse código).
		printf("\nJá existe produto com este codigo!\n");//se sim, exibe a mensagem e retorna falso.
		return false;
	}//fim if.
	
	printf("\nDigite o autor: ");
	scanf(" %[^\n]s",autor);//armazena na variável autor até o usuário apertar enter.
	
	cadastroProduto = abrirArquivo("cadastroProduto.txt","a+");//chama a função para abrir o arquivo.
	if(fprintf(cadastroProduto,"%s\n%s\n%s\n%s\n",codProduto,nome,genero,autor)){//escreve os dados no arquivo de cadastro de produto e verifica se gravou.
		printf("\nProduto cadastrado com sucesso!\n");//se gravou, exibe a mensagem de sucesso.
		Sleep(1000);// pausa a exibição por 1 segundo
		fclose(cadastroProduto);// fecha o arquivo
		return true; 
	}else//se não gravou, retorna falso.
		return false;
}//fim função para cadastrar produtos.

bool locacaoProduto(){//início função para alugar produtos.
/*dataLocacao[9] -> armazena a data de locação, 8 números. dataDevolucao[101] -> armazena a data de devolução, 8 números.  
  codProdutoD[11] -> armazena o código do produto com até 10 números. cpfClienteD[12] -> armazena o CPF do cliente, 11 números.*/
	char dataLocacao[9], dataDevolucao[9], codProdutoD[11], cpfClienteD[12];
	float valorLocacao, valorPago;//valorLocacao -> armazena o valor de aluguel do produto. valorPago -> armazena o valor pago pelo cliente.
	FILE * produtosAlugados;//ponteiro para um arquivo.
	
	printf("Digite o código do produto: ");
	scanf("%s",codProdutoD);//armazena o código do produto.

	if(!verificaProduto("cadastroProduto.txt",4,codProdutoD))//verifica se o produto existe.
		return false;//se não existir, retorna falso.
		
	if(verificaProduto("produtosAlugados.txt",4,codProdutoD)){//verifica se o produto foi alugado.
		printf("\nO produto já foi alugado!\n");//se sim, exibe a mensagem e retorna falso.
		return false;
	}
		
	printf("\nDigite o CPF do cliente: ");
	scanf("%s",cpfClienteD);//armazena o CPF do cliente.

	if(!verificaCliente("cadastroCliente.txt",4,cpfClienteD))//verifica se o cliente existe.
		return false;//se não existir, retorna falso.

	if(verificaCliente("produtosAlugados.txt",4,cpfClienteD)){//verifica se o cliente alugou algum produto.
		printf("\nO cliente já possui um produto alugado!\n");//se sim, exibe a mensagem e retorna falso.
		return false; 	
	}
    
	printf("\nDigite a data de locação (somente numeros) (DDMMAAAA): ");
	scanf("%s",dataLocacao);//armazena a data de locação.
	
	printf("\nDigite a data de devolução (somente numeros) (DDMMAAAA): ");
	scanf("%s",dataDevolucao);//armazena a data de devolução.
	
	printf("\nDigite o valor da locação: ");
	scanf("%f",&valorLocacao);//armazena o valor de locação.
	
	printf("\nDigite o valor pago pelo cliente: ");
	scanf("%f",&valorPago);//armazena o valor de pago.
	
	if(valorPago > valorLocacao)//verifica se o valor pago é maior que o de locação.
		printf("\nTroco: %.2f",valorPago - valorLocacao);//se sim, exibe o valor do troco.
	else{//se não.
		if(valorPago < valorLocacao)//verifica se o valor pago é menor que o de locação.
			printf("\nFalta %.2f reais!",valorLocacao - valorPago);//se sim, exibe o valor que falta o cliente pagar.
	}
	
	produtosAlugados = abrirArquivo("produtosAlugados.txt","a+");//chama a função para abrir o arquivo.
	if(fprintf(produtosAlugados,"%s\n%s\n%s\n%s\n",codProdutoD,cpfClienteD,dataLocacao,dataDevolucao)){//escreve os dados no arquivo de produtos alugados e verifica se gravou.
		printf("\nProduto alugado com sucesso!\n");//se sim, exibe a mensagem de sucesso.
		Sleep(1000);//pausa a exibição por 1 segundo.
		fclose(produtosAlugados);//fecha o arquivo.
		return true;
	}else//se não gravou, retorna falso.
		return false;
}//fim função para alugar produtos.

bool devolucaoProduto(){//início função para devolver produtos
/*dataDevolucao[9] -> armazena a data de devolucao retornada pela função excluiProdutoAlugado, 8 números. dataDevolucao[101] -> armazena a data de devolução, 8 números.  
  codProdutoD[11] -> armazena o código do produto com até 10 números. cpfClienteD[12] -> armazena o CPF do cliente, 11 números.*/
	char codProdutoD[11], cpfClienteD[12], dataDevolucao[9], dataDevolucaoD[9];
	FILE * produtosDevolvidos;//ponteiro para um arquivo.
	
	printf("Digite o código do produto: ");
	scanf("%s",codProdutoD);//armazena o código do produto.
	
	if(!verificaProduto("produtosAlugados.txt",4,codProdutoD))//verifica se o produto foi alugado.
		return false;//se não, retorna falso.
	
	printf("\nDigite o CPF do cliente: ");
	scanf("%s",cpfClienteD);//armazena o CPF do cliente.
	
	if(!verificaCliente("produtosAlugados.txt",4,cpfClienteD))//verifica se o cliente possui produtos alugados.
		return false;//se não, retorna falso.
		
	//chama a função excluiProdutoAlugado, chama a função inverteData, e copia a data no formato AAAAMMDD, armazenando-a na variável dataDevolucao.
	strcpy(dataDevolucao,inverteData(excluiProdutoAlugado(codProdutoD,cpfClienteD)));

	printf("\nDigite a data de devolução(somente numeros): ");
	scanf("%s",dataDevolucaoD);//armazena a data de devolução.
	
	strcpy(dataDevolucaoD,inverteData(dataDevolucaoD));//chama a função inverteData, e copia a data no formato AAAAMMDD, armazenando-a na variável dataDevolucaoD.

	if(atoi(dataDevolucaoD) > atoi(dataDevolucao))//verifica se a data que o cliente devolveu e maior que a data de devolução do produto.
		printf("\nO cliente deverá pagar R$5,00 pelo atraso\n");//se sim, exibe a mensagem de juros.

	produtosDevolvidos = abrirArquivo("produtosDevolvidos.txt","a+");//chama a função para abrir o arquivo.	
	//escreve os dados do produto devolvido no arquivo de produtos devolvidos e verifica se gravou.
	if(!fprintf(produtosDevolvidos,"%s\n%s\n%s\n",codProdutoD,cpfClienteD,dataDevolucaoD))
		return false;//se não gravou, retorna falso.
	fclose(produtosDevolvidos);//fecha o arquivo.
	
	printf("\nDevolução feita com sucesso!\n");
	
	Sleep(1000);//pausa a exibição por 1 segundo.
	
	return true;
}//fim função para devolver produtos

bool verificaCliente(char * arqnome, int intervalo, char * cpfClienteD){//ínicio função para verificar cliente.
	int cont = 0, tamanho;//cont -> contador. tamanho -> armazena o tamanha do arquivo.
	char cpfCliente[12];//armazena o CPF do cliente.
	FILE * arq;//ponteiro para um arquivo.
	
	arq = abrirArquivo(arqnome,"a+");//chama a função para abrir o arquivo.
	
	fseek(arq, 0, SEEK_END);//vai até o fim do arquivo.
    tamanho = ftell(arq);//armazena quantos caracteres tem no arquivo.
    
    if(tamanho > 0){//verifica se o arquivo está vazio.
		fseek(arq, 0, SEEK_SET);//se não está, vai até início do arquivo.
		
		while(!feof(arq)){//início while (percorrerá até o final do arquivo).
			if((cont == intervalo-3) || (cont % intervalo == 0)){//verifica se o leitor está na posição que está gravada o CPF do cliente.
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
}//fim função para verificar cliente.

bool verificaProduto(char * arqnome, int intervalo, char * codProdutoD){//início função para verificar o produto.
	int cont = 0, tamanho;//cont -> contador. tamanho -> armazena o tamanha do arquivo.
	char codProduto[11];//armazena o código do produto.
	FILE * arq;//ponteiro para um arquivo.
	
	arq = abrirArquivo(arqnome,"a+");//chama a função para abrir o arquivo.

	fseek(arq, 0, SEEK_END);//vai até o fim do arquivo.
    tamanho = ftell(arq);//armazena quantos caracteres tem no arquivo.
    
    if(tamanho > 0){//verifica se o arquivo está vazio.
    	fseek(arq, 0, SEEK_SET);//se não está, vai até início do arquivo.
    	
		while(!feof(arq)){//início while (percorrerá até o final do arquivo).
			if((cont == 0) || (cont % intervalo == 0)){//verifica se o leitor está na posição que está gravada o código do produto.
				fscanf(arq,"%s",codProduto);//se sim, armazena o código do produto.
				
				if(!stricmp(codProduto,codProdutoD)){//verifica se o encontrou o código do produto.
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
}//fim função para verificar o produto.

char * inverteData(char * data){//início função para formatar a data assim AAAAMMDD.
	char dataI[9];//armazena a data formatada.
	int cont,cont2;//contadores.
	
	for(cont = 0,cont2 = 4; cont < 4,cont2 < 8;cont++,cont2++){//percorrerá os 4 números do ano na data (AAAA).
		dataI[cont] = data[cont2];//armazena os 4 números do ano da data no começo da data formatada.
	}
	
	for(cont = 4,cont2 = 2; cont < 7,cont2 < 4;cont++,cont2++){//percorrerá os 2 números do mês na data (MM).
		dataI[cont] = data[cont2];//armazena os 2 números do mês da data no meio da data formatada.
	}
	
	for(cont = 6,cont2 = 0; cont < 9,cont2 < 2;cont++,cont2++){//percorrerá os 2 números do dia na data (DD).
		dataI[cont] = data[cont2];//armazena os 2 números do dia da data no final da data formatada.
	}
	
	return dataI;//retorna a data formatada.
}//fim função para formatar a data assim AAAAMMDD.

char * excluiProdutoAlugado(char * codProdutoD, char * cpfClienteD){//início função para excluir um produto, que foi devolvido, do arquivo de produtos alugados. 
	FILE * produtosAlugados;//ponteiro para um arquivo.
	int cont = 0, cont2 = 0, tamanho = 0;//cont,cont2 -> contadores. tamanho-> armazena o tamanha do arquivo.
	Aux * pA;//ponteiro para a estrutura auxiliar.
	char data[9], c;//data[9] -> armazena a data que será retornada. c -> armazena cada caractere do arquivo.
	
    produtosAlugados = abrirArquivo("produtosAlugados.txt","r");//chama a função para abrir o arquivo.
		
	fseek(produtosAlugados, 0, SEEK_END);//vai até o fim do arquivo.
    tamanho = ftell(produtosAlugados);//armazena quantos caracteres tem no arquivo.
    
    if(tamanho > 0){//verifica se o arquivo está vazio.	
    	fseek(produtosAlugados, 0, SEEK_SET);//se não está, vai até início do arquivo.
    	
    	while ((c = fgetc(produtosAlugados)) != EOF) {//percorrerá até o final do arquivo.
        	if (c == '\n')//verifica se o caractere é igual ao caractere de "quebra de linha".
        		cont2++;//se sim, acrescenta mais 1 no contador para contar o número de linhas que o arquivo possui.
    	}//isso servirá para contar quantos blocos de registros existe no arquivo de produtos alugados. Bloco -> codProduto, cpfCliente, dataLocacao, dataDevolucao.
    	
    	cont2 = cont2/4;//divide o número de linhas do arquivo por 4 para pegar o número de blocos no arquivo.
    	pA = (Aux *) malloc(cont2 * sizeof(Aux));//aloca "cont2s" espaços na memória para a estrutura auxiliar.
    	cont = 0;//zera o contador;
    	
    	fseek(produtosAlugados, 0, SEEK_SET);//volta para o início do arquivo.
    	
		while(cont2 > 0){//percorrerá o arquivo, "cont2s" vezes.
		//lê um bloco do arquivo.
			fscanf(produtosAlugados,"%s %s %s %s",pA[cont].codProduto,pA[cont].cpfCliente,pA[cont].dataLocacao,pA[cont].dataDevolucao);
			cont++;	//acrescenta mais 1.
			cont2--;//decresce 1.
		}
	}
	
	fclose(produtosAlugados);//fecha o arquivo.
	
	for(cont2 = 0; cont2 < cont; cont2++){//percorerrá a estrutura auxiliar.
		if(!stricmp(pA[cont2].codProduto,codProdutoD)){//verifica se achou o código do produto.
			if(stricmp(pA[cont2].cpfCliente,cpfClienteD)){//se sim, verifica se o CPF que o cliente falou é igual ao CPF do cliente que alugou o produto. 
				printf("\nNão foi esse cliente que alugou esse produto!\n");//se não for igual, exibe a mensagem.
				exit(0);//e finaliza o programa.
			}
		}	
	}
	
	produtosAlugados = abrirArquivo("produtosAlugados.txt","w");//chama a função para abrir o arquivo e abre no tipo "w" para sobrescrever o conteúdo do arquivo.
		
    for(cont2 = 0; cont2 < cont; cont2++){//percorerrá o número de blocos.
    	if(stricmp(pA[cont2].codProduto,codProdutoD))//verifica se o código do produto da estrutura auxiliar é igual ao código do produto devolvido.
    	//se não for igual, escreve o bloco no arquivo de produtos alugados.
    		fprintf(produtosAlugados,"%s\n%s\n%s\n%s\n",pA[cont2].codProduto,pA[cont2].cpfCliente,pA[cont2].dataLocacao,pA[cont2].dataDevolucao);
    	else//se for igual.
    		strcpy(data,pA[cont2].dataDevolucao);//copia a data de devolução do produto devolvido para a variável data.
    }	

	fclose(produtosAlugados);//fecha o arquivo.
	
	free(pA);//libera a memória alocada para pA.

	return data;//retorna a data de devolução do produto devolvido.
}//fim função para excluir um produto, que foi devolvido, do arquivo de produtos alugados. 

FILE * abrirArquivo(char * nome, char * tipoAbertura){//início função para abrir o arquivo.
	if(fopen(nome,tipoAbertura) != NULL)//abre o arquivo e verifica se conseguiu abrir.
		return fopen(nome,tipoAbertura);//se conseguiu, retorna o arquivo aberto.
	else{//se não conseguiu, exibe a mensagem de erro e finaliza o programa.
		printf("\nNão foi possível abrir o arquivo\n");
		exit(0);
	}
}
