#include <stdio.h>
#include <stdlib.h>
#include <locale.h>// biblioteca de aloca�oes de texto por regi�o
#include <string.h>

//declara��o de fun��es
int registro();//respons�vel por cadastrar usuarios
int consulta();//responsavel por consultar usuarios
int deleta();//responsavel por deletar usuarios


int main()
{
	int opcaoMenu=0; //definindo variaveis
	int laco=1;

	setlocale(LC_ALL, "Portuguese");//definindo idioma

	for(laco=1;laco=1;)
	{
		system("cls");//limpa a tela de execu��o do programa
		
		printf("\n\t----Cart�rio da EBAC----\n\n");//come�o do Menu
		printf("\nEscolha uma op��o:\n\n");
		printf("\t1- Cadastrar Aluno\n");
		printf("\t2- Consultar Aluno\n");
		printf("\t3- Excluir Aluno\n\n");
		printf("Digite a op��o: ");//fim do Menu
		
		scanf("%d",&opcaoMenu);//armazenamento da opcao do menus
		system("cls");
		switch(opcaoMenu)//Come�o de sele��o do menu
		{
			
			case 1: 
			registro();//chamada da fun��o
			break;
			
			case 2:
			consulta();//chamada da fun��o
			break;
			
			case 3:
			deleta();//chamada da fun��o		
			break;
			
			case 4:
			
			break;
			
			default:
			printf("OP��O N�O DISPONIVEL TENTE NOVAMENTE OUTRA!\n");
			system("pause");//pausa a tela at� que o usu�rio clique alguma tecla
			break;
		}//fim da sele��o 
	}
}

//codigo das funcoes
int registro()
{
	
	setlocale(LC_ALL, "Portuguese");//definindo idioma
	char cpf[40],nome[40],sobrenome[40],cargo[40],arquivo[40];
	
	printf("\nDIGITE O CPF: ");
	scanf("%s",cpf);
	
	strcpy(arquivo,cpf);//responsavel por copiar as strings
	
	FILE *file,*exibe; //cria o arquivo
	file = fopen(arquivo, "w");//cria o arquivo no modo write "w", read "r" e write sem apagar conteudos anteriores "a"
	
		
	fprintf(file,"CPF: ");//printa no file criado o que esta escrito entre aspas
	
	fprintf(file,cpf);//salva o valor da variaveis
	fclose(file);//fecha o arquivo
	
	file = fopen(arquivo, "a");//abre o arquivo e salva sem apagar dados anteriores
	fprintf(file,"\nNome: ");//printa no file criado o que esta escrito entre aspas
	fclose(file);//fecha o file
	
	printf("DIGITE SEU NOME: ");
	scanf("%s",nome);
	
	file = fopen(arquivo,"a");
	fprintf(file,nome);
	fclose(file);
	
	file=fopen(arquivo, "a");
	fprintf(file,"\nSobrenome: ");
	fclose(file);
	
	printf("DIGITE O SOBRENOME: ");
	scanf("%s",sobrenome);
	
	file-fopen(arquivo,"a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file=fopen(arquivo, "a");
	fprintf(file,"\nCargo: ");
	fclose(file);
	
	printf("DIGITE O CARGO: ");
	scanf("%s",cargo);
	
	file=fopen(arquivo,"a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
	
	
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese");//definindo idioma
	char cpf[40], conteudo[200];
	
	printf("\nDIGITE O CPF PARA CONSULTA: ");
	scanf("%s",cpf);
	
	FILE *file;
	file=fopen(cpf,"r");
	
	if(file==NULL)
	{
		printf("N�O FOI POSS�VEL LOCALIZAR O CPF DESEJADO!\n");
	}
	
	printf("\n\n");
	while(fgets(conteudo,200,file)!=NULL)
	{
		printf("%s",conteudo);	
	}
	printf("\n\n");
	
	fclose(file);
	
	system("pause");
	
}

int deleta()
{
	char cpf[40];
	
	printf("DIGITE O CPF QUE DESEJA EXCLUIR: ");
	scanf("%s",cpf);
	
	
	
	FILE *file;
	file=fopen(cpf,"r");
	fclose(file);
		
	if(file==NULL)
	{
		printf("USU�RIO N�O DETECTADO!\n");
		system("pause");
		
	}
	else
	{
		remove(cpf);
		printf("USU�RIO EXCLUIDO COM SUCESSO!\n");
		system("pause");
	}
	
	
}
