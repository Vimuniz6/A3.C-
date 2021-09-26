# inclui <stdio.h>
# inclui <stdlib.h>
# inclui <string.h>
# inclua <locale.h>
typedef   struct  cadastro
{
	int codigoCliente;
	char nome [ 30 ];
	int anoNasc;
	float totalGasto;
} cliente;

void   cadastrarCliente (cliente * cad, int * contador) {

	getchar ();
	printf ( " \ n Digite o Nome do cliente: \ n " );
	scanf ( " % 30 [^ \ n] " , & (cad + * contador) -> nome);
	printf ( " \ n Digite o ano de nascimente do cliente: \ n " );
	scanf ( " % d " , & (cad + * contador) -> anoNasc);
	printf ( " \ n Digite o gasto total do cliente: \ n " );
	scanf ( " % f " , & (cad + * contador) -> totalGasto);
	(cad + * contador) -> codigoCliente = * contador + 1 ;
	* contador = * contador + 1 ;

}

void   editarCliente (cliente * cad, int contador) {
	codigo int , opcao;

	printf ( " \ n Digite o id do cliente que deseja atualizar o montante de compras, ids disponíveis de 1 a% d \ n " , contador);
	scanf ( " % d " , & codigo);

	para ( int i = 0 ; i <contador; i ++)
	{
		if (codigo == (cad + i) -> codigoCliente)
		{
			printf ( " \ n Esse cliente que deseja atualizar o montante de compras? \ n " );
			printf ( " \ n% d. \ t% s \ t% d \ t% .2f \ n " , (cad + i) -> codigoCliente, (cad + i) -> nome, (cad + i) -> anoNasc, (cad + i) -> Gasto total);
			printf ( " \ n 1-Sim \ n 2-Não \ n " );
			scanf ( " % d " , & opcao);

			if (opcao == 1 )
			{
				printf ( " \ n Digite o novo montante de compraso \ n " );
				scanf ( " % f " , & (cad + i) -> totalGasto);
				printf ( " \ n% d. \ t% s \ t% d \ t% .2f \ n " , (cad + i) -> codigoCliente, (cad + i) -> nome, (cad + i) -> anoNasc, (cad + i) -> Gasto total);

			}
			pausa;
		}
		outro
		{
			printf ( " id do cliente não encontrado " );

		}
	}


}

int   excluirCliente (cliente * cad, int contador, cliente * aux)
{
	codigo int , opcao, x = 0 ;

	printf ( " \ n Digite o id do cliente que deseja excluir% d \ n " , contador);
	scanf ( " % d " , & codigo);

	para ( int i = 0 ; i <contador; i ++)
	{
		if (codigo == (cad + i) -> codigoCliente)
		{
			printf ( " \ n Esse cliente que deseja excluir? \ n " );
			printf ( " \ n% d. \ t% s \ t% d \ t% .2f \ n " , (cad + i) -> codigoCliente, (cad + i) -> nome, (cad + i) -> anoNasc, (cad + i) -> Gasto total);
			printf ( " \ n 1-Sim \ n 2-Não \ n " );
			scanf ( " % d " , & opcao);

			if (opcao == 1 )
			{
				para ( int j = 0 ; j <contador; j ++)
				{
					if ((cad + j) -> codigoCliente! = codigo)
					{
						(aux + x) -> codigoCliente = (cad + j) -> codigoCliente;
						strcpy ((aux + x) -> nome, (cad + j) -> nome);
						(aux + x) -> anoNasc = (cad + j) -> anoNasc;
						(aux + x) -> Gasto total = (cad + j) -> Gasto total;
						x ++;
					}
				}
				para ( int j = 0 ; j <x; j ++)
				{
					(cad + j) -> codigoCliente = j + 1 ;
					strcpy ((cad + j) -> nome, (aux + j) -> nome);
					(cad + j) -> anoNasc = (aux + j) -> anoNasc;
					(cad + j) -> totalGasto = (aux + j) -> totalGasto;
				}
			}
			retorno - 1 ;
		}
		outro
		{
			printf ( " id do cliente não encontrado " );
		}
	}
}

void   zerarMontante (cliente * cad, int contador) {
	para ( int i = 0 ; i <contador; i ++)
	{
		(cad + i) -> Gasto total = 0 ;
	}
}

void   melhorComprador (cliente * cad, int contador) {
	int aux = cad-> totalGasto, cod;
	para ( int i = 0 ; i <contador; i ++)
	{
		if (aux> (cad + i) -> totalGasto)
		{
			cod = (cad + i) -> codigoCliente;
		}
	}
	printf ( " \ n \ t MELHOR CLIENTE \ n " );
	printf ( " --------------------------------- " );
	para ( int i = 0 ; i <contador; i ++)
	{
		if (cod == (cad + i) -> codigoCliente)
		{
			printf ( " \ n% d. \ t% s \ t% d \ t% .2f \ n " , (cad + i) -> codigoCliente, (cad + i) -> nome, (cad + i) -> anoNasc, (cad + i) -> Gasto total);
		}
	}
	printf ( " --------------------------------- " );

}
void   buscaCliente (cliente * cad, int contador) {
	int cod;
	printf ( " \ n Digite o id do cliente: \ n " );
	scanf ( " % d " , & cod);
	printf ( " \ n \ t CLIENTE \ n " );
	printf ( " --------------------------------- " );
	para ( int i = 0 ; i <contador; i ++)
	{
		if (cod == (cad + i) -> codigoCliente)
		{
			printf ( " \ n% d. \ t% s \ t% d \ t% .2f \ n " , (cad + i) -> codigoCliente, (cad + i) -> nome, (cad + i) -> anoNasc, (cad + i) -> Gasto total);
		}
	}
	printf ( " --------------------------------- " );

}

void   imprimir (cliente * cad, int contador) {
	printf ( " \ n \ t LISTA DE CLIENTES \ n " );
	printf ( " --------------------------------- " );
	para ( int i = 0 ; i <contador; i ++)
	{
		printf ( " \ n% d. \ t% s \ t% d \ t% .2f \ n " , (cad + i) -> codigoCliente, (cad + i) -> nome, (cad + i) -> anoNasc, (cad + i) -> Gasto total);
	}
	printf ( " --------------------------------- " );
}

int   main () {
	setlocale (LC_ALL, " português " );
	cliente * cad;
	cliente * aux;

	cad = (cliente *) calloc ( 10 , sizeof (cliente));
	aux = (cliente *) calloc ( 10 , sizeof (cliente));

	int opcao, contador = 0 ;
	Faz
	{
		printf ( " \ n 1-Cadastro cliente \ n " );
		printf ( " \ n 2-Atualizar o montante de compras \ n " );
		printf ( " \ n 3-Remover cliente \ n " );
		printf ( " \ n 4-Zerar todos os montantes de compras \ n " );
		printf ( " \ n 5-Listar o cliente melhor comprador \ n " );
		printf ( " \ n 6-Buscar cliente \ n " );
		printf ( " \ n 7-Listar clientes \ n " );
		printf ( " \ n 0-Sair \ n " );
		printf ( " \ n \ n Digite a opção escolha: \ n " );
		scanf ( " % d " , & opcao);
		switch (opcao)
		{
		caso   1 :
			cadastrarCliente (cad, & contador);
			if (contador == 10 || contador% 10 == 0 )
			{
				printf ( " \ n Lista de cliente cheia, deseja criar mais 10 espaços para clientes? \ n " );
				printf ( " \ n 1-Sim \ n 2-Não \ n " );
				scanf ( " % d " , & opcao);

				if (opcao)
				{
					cad = (cliente *) realloc (cad, ((((contador + 1 ) / 10 ) * 10 ) * sizeof (cliente)));
					aux = (cliente *) realloc (cad, ((((contador + 1 ) / 10 ) * 10 ) * sizeof (cliente)));
				}
				outro
				{
					pausa;
				}
			}
			pausa;
		caso   2 :
			editarCliente (cad, contador);
			pausa;
		caso   3 :
			contador = contador + excluirCliente (cad, contador, aux);
			pausa;
		caso   4 :
			zerarMontante (cad, contador);
			imprimir (cad, contador);
			pausa;
		caso   5 :
			melhorComprador (cad, contador);
			pausa;
		caso   6 :
			buscaCliente (cad, contador);
			pausa;
		caso   7 :
			imprimir (cad, contador);
			pausa;
		padrão:
			if (opcao! = 0 )
			{
				printf ( " \ n Opção inválida \ n " );
			}
			pausa;
		}
	} enquanto (opcao! = 0 );
} 
