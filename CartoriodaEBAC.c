#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //bilioteca de alocação de espaço de memória
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> //biblioteca responsavel por cuidar das string


int registro()
{	
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Digite o CPF para pacadastro: ");
	scanf("%s", cpf);
	
	strcpy(arquivo, cpf); //Responsavel por copiar os calores das strings 
	
	FILE *file;//Cria o arquivo
	file=fopen(arquivo, "w");//Cria o arquivo e escreve os valores informados
	fprintf(file,cpf);//salva o valor da variavel
	fclose(file);//Fecha o arquivo
	
	file=fopen(arquivo, "a"); // O "a" Atualiza o arquivo
	fprintf(file, ","); // O "," serve para separar oque foi posto no arquivo
	fclose(file); // Fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);

	 file=fopen(arquivo, "a");
	 fprintf(file, nome);
	 fclose(file);
	 
	file= fopen(arquivo, "a");
	fprintf(file, " ");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file= fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	 
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
	
	file= fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);

	system("pause");
	
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o cpf a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r"); // Le o oque foi os dados guardados anteriormente
	
	if(file == NULL){
		printf("Não foi possivel abrir o arquivo, não foi localizado. \n");
	}
	
	while(fgets(conteudo, 200, file) != NULL) // procura o arquivo
	{
		printf("\nEssas são as informações do usuario: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
	
}
int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF que ira der deletado: ");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file==NULL){
		printf("Usuario ja deletado.\n" );
		system("pause");
	}
	
	
	
}
int main()
{
	int opcao=0; //Definindo as variaveis
	int x=1;

	for(x=1;x=1;) //Laço de repetição começa aqui 
	{
		system("cls");
	
		setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
		
		printf("### Cartório da EBAC ###\n\n"); //Inicio do menu
		printf("Escolha a opção desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n"); 
		printf("\t4 - Fechar programa\n\n");//Fim do menu
		printf("Qual opção desejada? ");
		scanf("%d", &opcao); //Aramazenando as informações do usuario
		
		system("cls"); //zerando a Tela
		
		switch(opcao)
		{
			case 1:
			registro();
			break;
			
			case 2:
			consulta();
			break;
				
			case 3:
			deletar();
			break;
			
			case 4:
			printf("sistema sendo finalizado!\n");
			return 0;
			break;
		
			default:
			printf("Essa opção não existe,\n");
			printf("Estaremos lhe redirecionando ao menu.\n\n");
			system("pause");
			break;
		}
		
	} //Laço termina aqui
}
