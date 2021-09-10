#include <stdio.h>
#include "pessoa.h"

int main(){
	
	Pessoa * p1, * p2, * p3;
	
	p1 = criar("Pedro","Lirios 400");
	p2 = criar("Jorge","Orquideas 199");
	p3 = criar("Manuela","Girassois 534");
	
	printf("Endereco de Manuela: ",buscar(p3));
	
	if(excluir(p2))
		printf("Excluido com sucesso");
	else
		printf("falha ao excluir");
		
	
	return 0;
}
