#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*
Questão 6. Construa um programa que leio o número de linhas e de colunas de uma matriz de números reais, 
aloque espaço dinamicamente para armazená-la em memória e a inicialize com valores fornecidos pelo usuário.
 Ao final, programa deverá imprimir a matriz com layout apropriado.
*/





int main()
{
	int lin, col, i, j;
	int **mat;
	
	printf("Digite o numero de linhas da matriz: ");
	scanf("%d", &lin);
	printf("Digite o numero de colunas da matriz: ");
	scanf("%d", &col);
	   
	mat = malloc(lin * sizeof(int*));// alocação de um vetor
	    
	for(i = 0; i < col; i++)  // alocação das linhas
	{		
		mat[i] = malloc(lin * sizeof(int));
	}
	
	for(i = 0; i < lin; i++)
	{
        	for(j = 0; j < col; j++)
            	{
            		printf("Digite um valor para a posicao mat[%d][%d]: ", i, j);
            		scanf("%d", &mat[i][j]);
            	}
	}


	printf("\n");
	printf("A matriz gerada foi:\n\n");

	for(i = 0; i < lin; i++) 	// imprime a matriz
	{
		for(j = 0; j < col; j++)
		{
			printf("%d ", mat[i][j]);
		}
			printf("\n");
	}
	printf("\n");

	return 0;
}




/*
Questão 5. Crie um programa que declare uma estruture para cadastro de alunos, sendo que:
• deverão ser armazenados, para cada aluno, matrícula, sobrenome e ano de nascimento; 1
• ao início do programa, o usuário deverá informar o número de alunos que serão armazenados;
• o programa deverá alocar dinamicamente a quantidade necessária de memória para armazenar os registros dos alunos; e 
• ao final, mostrar os dados armazenados e liberar a memória alocada.
*/
/*
struct cad{
	int matricula;
	char nome[15];
	char sobrenome[50];
	int ano;
};
typedef struct cad cad;

void flush_in(){ 
    int ch;
    while( (ch = fgetc(stdin)) != EOF && ch != '\n' ){} 
}


int main()
{
	int naluno=1, i=0;
	cad *aluno = (cad*)malloc(naluno*sizeof(cad));
		
	printf("Informe a quantidade de alunos: ");
	scanf("%d", &naluno);
	printf("\n");
	for(i=0; i<naluno; i++)
	{
		aluno = realloc(aluno, naluno*(sizeof(cad)));
		printf("***Entrada %d\n***", i+1);
		printf("Digite o numero de matricula: ");
		scanf("%d", &aluno[i].matricula);
		printf("Digite o nome: ");
		scanf("%s", aluno[i].nome);
		flush_in();//limpar buffer teclado
		printf("Digite o sobrenome: ");
		scanf("%s", aluno[i].sobrenome);
		flush_in();//limpar buffer teclado
		printf("Digite o ano nascimento: ");
		scanf("%d", &aluno[i].ano);	
		printf("\n");	
	}
	
	printf("\n");
	for(i=0; i<naluno; i++)
	{
		printf("***Entrada %d\n***", i+1);
		printf("Numero de matricula: %d\n", aluno[i].matricula);
		printf("Nome: %s\n", aluno[i].nome);
		printf("Sobrenome: %s\n", aluno[i].sobrenome);
		printf("Ano nascimento: %d\n", aluno[i].ano);
		printf("\n");	
	}

	free(aluno);
	return 0;
}
*/

/*
Questão 4. Faça um programa que leia uma quantidade qualquer de números armazenandoos em um array dinamicamente alocado e pare a leitura quando o usuário entrar com um número negativo. Em seguida, imprima o vetor lido. Use a função realloc para aumentar o tamanho atual do array quando necessário.
*/
/*
int main()
{
	int* vet;
	int i=0, j=0, n;
	

	
	do {
		printf("Digite um valor: ");
		scanf("%d", &n);		

		if(n<0)
		{
			printf("\nVoce digitou um valor negativo.\n");
			printf("PROGRAMA FINALIZADO!!\n");
			break;
		}

		vet = (int*)realloc(vet, i);
		vet[i] = n;
		i++;		
	}while(1);
	
	printf("\n");
	printf("O vetor digitado foi vet[%d] = {", i);
	for(j=0; j<i; j++)
	{
		printf(" %d ", vet[j]);
	}
	printf("}\n\n");

	
	free(vet);
	return 0;

}
*/

/*
Questão 3. Faça um programa para armazenar em memória um array de dados contendo 1500 valores do tipo int usando a função de alocação dinâmica de memória calloc. Após, faça um loop e verifique se o array contém realmente os 1500 valores inicializados com zero (conte os 1500 zeros do array).
*/

/*
int main()
{
	int* vet;
	int i, cont=0;
	
	//Armazenar em memória um array contendo 1500 valores do tipo int usando a função de alocação dinâmica de memória calloc
	vet = (int*)calloc(1500, sizeof(int));
	
	//loop e verifique se o array contém realmente os 1500 valores inicializados com zero
	for(i=0; i<1500; i++)
	{
		cont+= vet[i]==0
/*		
		if(vet[i]==0)
		{
			cont=cont+1;
		}
*/
/*
	}
	
	//Imprimir verificacao
	printf("\nForam contados %d numeros '0' dentro do vetor\n\n", cont);
	
	free(vet);
	return 0;
}
*/


/*
Questão 2. Faça um programa que leia do usúario o tamanho de uma string e chame uma função para alocar dinamicamente essa string. Em seguida, o usuário deverá informar o conteúdo dessa string. Finalmente imprima a string. Não se esqueça de desalocar a memória alocada!
*/

/*
int main()
{
	char* str;
	int num;
	
	//Ler o tamanho da string
	printf("\nDigite o tamanho da string: ");
	scanf("%d", &num);	
	setbuf(stdin, NULL); //limpar buffer teclado
	
	//Alocar dinamicamente essa string
	str = (char*)malloc(num*sizeof(char));
	
	//Informar o conteúdo dessa string
	printf("Digite a frase: ");
	setbuf(stdin, NULL); //limpar buffer teclado
	fgets(str, num, stdin);
	
	//Imprimir a string
	printf("\nA frase digitada foi:--->  ");
	printf("%s\n\n", str);	

	//Desalocar a memória alocada
	free(str);
	
	return 0;

}
*/


/*
Questão 1. Faça um programa que leia do usúario o tamanho de um array a ser lido e faça a alocação de memória. Em seguida, leia do usuário seus valores e imprima o array lido. Não se esqueça de desalocar a memória alocada!
*/

/*
int main()
{
	int* vet;
	int num, i=0;
	
	
	printf("\nDigite o tamanho do vetor: ");
	scanf("%d", &num);
	
	vet = (int*)malloc(num*sizeof(int));
	
	printf("\n");
	for(i=0; i<num; i++)
	{
		printf("Digite o valor para a posicao vet[%d]: ",i);
		scanf("%d", &vet[i]);
	}
	printf("\n");
	
	printf("O vetor digitado foi vet[%d] = {", num);
	for(i=0; i<num; i++)
	{
		printf(" %d ", vet[i]);
	}
	printf("}\n\n");
	
	free(vet);

	return 0;
}
*/

