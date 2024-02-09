#include <stdio.h> // Biblioteca de comunicação com o usuário
#include <stdlib.h> // Biblioteca de alocação de espaços em memória
#include <locale.h> // Biblioteca de alocação de texto por região
#include <string.h> //Biblioteca responsável por cuidar das strings

int registro() //Função responsável por cadastrar os usuários
{
	char arquivo[40]; //Criação das variáveis/string
	char cpf[40];
	char nome[40];
	char sobrenome[80];
	char cargo[40];
	
	printf("Digite seu CPF: "); //Coletar informações do usuário
	scanf("%s", cpf); //%s = string
	
	strcpy(arquivo, cpf); //Responsável por copiar os valores das string
	
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
		printf("\nNão foi possível encontrar o CPF!\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas são as informações do usuário: \n\n");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("\nCPF não encontrado! \n\n");
		system("pause");
		return 0;
	}
	
	fclose(file);
	
	if(remove(cpf) >= 0)
	{
		printf("\nUsuário deletado com sucesso! \n\n");
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
	int opcao = 0; //Definindo variáveis
	int x =1;
	
	for(x =1;x =1;) //laço de repetição
	{
		
		system("cls"); //limpar a tela
	
        setlocale (LC_ALL, "Portuguese"); // Definindo a lingua que será usada
	
	    printf("\tCartório da EBAC\n\n"); // Início do menu
	    printf("Escolha a opção desejada do menu:\n\n");
	    printf("\t1 - Registrar nomes\n");
	    printf("\t2 - Consultar nomes\n");
	    printf("\t3 - Deletar nomes\n\n");
	    printf("Opção: "); //fim do menu
	
	    scanf("%d", &opcao); //Armazenando a escolha do usuário
	
	    system("cls");
	    
	    switch(opcao) //usado para deixar o código mais enchuto, mas faz a mesma função do IF
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
	    	printf("Essa opção não está disponível!\n");
	    	system("pause");
	    	break;
		}
	}
}
