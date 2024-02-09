#include <stdio.h> // Biblioteca de comunica��o com o usu�rio
#include <stdlib.h> // Biblioteca de aloca��o de espa�os em mem�ria
#include <locale.h> // Biblioteca de aloca��o de texto por regi�o
#include <string.h> //Biblioteca respons�vel por cuidar das strings

int registro() //Fun��o respons�vel por cadastrar os usu�rios
{
	char arquivo[40]; //Cria��o das vari�veis/string
	char cpf[40];
	char nome[40];
	char sobrenome[80];
	char cargo[40];
	
	printf("Digite seu CPF: "); //Coletar informa��es do usu�rio
	scanf("%s", cpf); //%s = string
	
	strcpy(arquivo, cpf); //Respons�vel por copiar os valores das string
	
	FILE *file; //criar o arquivo
	file = fopen(arquivo, "w"); //w = escrever
	fprintf(file, cpf); //salvo valor
	fclose(file); //fechar arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file, ", ");
	fclose(file);
	
	printf("Digite seu nome: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file, nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ", ");
	fclose(file);
	
	printf("Digite seu sobrenome: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ", ");
	fclose(file);
	
	printf("Digite seu cargo: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
	
	system("pause");
}

int consultar()
{
	setlocale (LC_ALL, "Portuguese");
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)

	{
		printf("\nN�o foi poss�vel encontrar o CPF!\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio: \n\n");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usu�rio a ser deletado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("\nCPF n�o encontrado! \n\n");
		system("pause");
		return 0;
	}
	
	fclose(file);
	
	if(remove(cpf) >= 0)
	{
		printf("\nUsu�rio deletado com sucesso! \n\n");
	}
	else
	{
		printf("Erro ao remover o CPF! \n");
	}
	
	system("pause");
	return 0;
}

int main() 
{
	int opcao = 0; //Definindo vari�veis
	int x =1;
	
	for(x =1;x =1;) //la�o de repeti��o
	{
		
		system("cls"); //limpar a tela
	
        setlocale (LC_ALL, "Portuguese"); // Definindo a lingua que ser� usada
	
	    printf("\tCart�rio da EBAC\n\n"); // In�cio do menu
	    printf("Escolha a op��o desejada do menu:\n\n");
	    printf("\t1 - Registrar nomes\n");
	    printf("\t2 - Consultar nomes\n");
	    printf("\t3 - Deletar nomes\n\n");
	    printf("Op��o: "); //fim do menu
	
	    scanf("%d", &opcao); //Armazenando a escolha do usu�rio
	
	    system("cls");
	    
	    switch(opcao) //usado para deixar o c�digo mais enchuto, mas faz a mesma fun��o do IF
	    {
	    	case 1:
	    	registro();
	    	break;
	    	
	    	case 2:
	    	consultar();
	        break;
	        
	        case 3:
	        deletar();
	    	break;
	    	
	    	default:
	    	printf("Essa op��o n�o est� dispon�vel!\n");
	    	system("pause");
	    	break;
		}
	}
}
