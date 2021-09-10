#include <stdio.h>
#include <string.h>

typedef struct{
	char item[21];
} lista;

void insertion(lista *listaCompras, unsigned short tam);

int main (){

	unsigned short casos, i, j;
	lista listaCompras[1010];
	char itens[20010], *cadaItem;

	scanf("%hu", &casos);

	while (casos--)
	{

		scanf(" %[^\n]", itens);

		i = 0;
		
		cadaItem = strtok(itens, " ");

		strcpy(listaCompras[i++].item, cadaItem);

		do{
			cadaItem = strtok('\0', " ");
			if (cadaItem == NULL)
				break;

			strcpy(listaCompras[i].item, cadaItem);

			i++;

		} while (cadaItem);

		insertion(listaCompras, i);

		for (j = 0; j < i; j++)
		{

			if (strcmp(listaCompras[j].item, listaCompras[j - 1].item) != 0)
			{
				if (j != 0 && j != i)
					printf(" ");

				printf("%s", listaCompras[j].item);
			}

		}

		printf("\n");
		memset(listaCompras, 0, sizeof(listaCompras));
		memset(itens, 0, sizeof(itens));

	}
	return 0;
}


void insertion(lista *listaCompras, unsigned short tam)
{

	short i = 1, j;
	lista pivo;

	while (i < tam)
	{

		j = i - 1;
		pivo = listaCompras[i];

		while (j >= 0 && strcmp(listaCompras[j].item, pivo.item) > 0)
		{

			listaCompras[j + 1] = listaCompras[j];
			j--;

		}

		listaCompras[j + 1] = pivo;
		i++;

	}

}
