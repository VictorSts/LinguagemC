#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
struct cliente {
       char codigo;
       char nome[35];
       char nova[100]; 
       char rua[100];
	   int numero[100]; 
       char email[50];
       char bairro[100];
       char cidade[100];
       char estado[100];   

struct cliente *proximo;

} *inicio, *ultimo, *novo; 

typedef cliente client;

int cadastrado(char str[35], int k);

int inserir()
{
int j = 0;
char nome2[35];
char codigo2;
int num2;
char nova2[100]; 
char rua2[100];
char numero2[100]; 
char email2[50];
char bairro2[100];
char cidade2[100];
char estado2[100];

client p; 
novo = (client *)malloc(sizeof(client)); 

if(novo == NULL) { 
printf("Erro ao tentar alocar memoria.\n"); 
return 0; 
}
     system("cls");
	 printf("\t*********************************************************************\n");
     printf("\t*                                                                   *\n");
     printf("\t*                 Cadastrar Conta Corrente                          *\n");
     printf("\t*                                                                   *\n");
     printf("\t*********************************************************************\n");
     printf("\t*********************************************************************\n");
     printf("\t*                                                                   *\n");
     printf("\t*                                                                   *\n");
     printf("\t*                                                                   *\n");
     printf("\t*********************************************************************\n"); 

printf("\n==>Informe o Numero da nova Conta: ");
scanf("%d", &novo->codigo); 

printf("Informe o Nome do Correntista: ");
scanf("%s", &novo->nome); 

printf("Endereco-Informe a Rua: "); 
scanf("%s", &novo->rua);          

printf("Endereco-Informe o Numero: ");
scanf("%s", &novo->numero);           

printf("Endereco-Informe o Bairro: ");
scanf("%s", &novo->bairro);          

printf("Endereco-Informe o Cidade: ");
scanf("%s", &novo->cidade);           

printf("Endereco-Informe o Estado: ");
scanf("%s", &novo->estado);          

printf("Informe o email: ");
scanf("%s", &novo->email);           

novo->proximo = NULL;
if(inicio == NULL) 
{ 
inicio = novo; 
ultimo = novo;
}
else
{
ultimo->proximo = novo;
novo->proximo = NULL; 
ultimo = novo;
}
return 1;
}
int limparmemoria() 
{
client *p, *p2; 
p2 = p = inicio;
if( inicio != NULL )
{ 
do {
p2 = p; 
p = p->proximo; 
free(p2); 
}while(p != NULL);
}
exit(0);
}

//Listar
int listar()
{
	 system("cls");
	 printf("\t****************************************************************\n");
	 printf("\t*                                                              *\n");
	 printf("\t*                 Listar Conta Corrente                        *\n");
	 printf("\t*                                                              *\n");
	 printf("\t****************************************************************\n");
	 printf("\t****************************************************************\n");
	 printf("\t*                                                              *\n");
	 printf("\t*                                                              *\n");
	 printf("\t****************************************************************\n");
	 
client *p; 
p = inicio; 
if(inicio == NULL)
printf("Nao há clientes adicionaros\n");
do {
printf(" -->Numero Conta Corrente %d\n", p->codigo); 
printf("Nome do Correntista %s\n", p->nome);
printf("Endereco-Rua %s\n", p->rua);
printf("Endereco-Numero %s\n", p->numero);
printf("Endereco-Bairro %s\n", p->bairro);
printf("Endereco-Cidade %s\n", p->cidade);
printf("Endereco-Estado %s\n", p->estado);
printf("E-mail do Correntista %s\n", p->email);
p = p->proximo; 
}while(p != NULL); 
system("pause");
}

//Excluir
int deletar(char str[35]) 
{
int r = 0;
char ch1,ch2;
client *antes, *atual, *ultimoo, *pass = NULL;
antes = atual = inicio;
do {
if(!strcmp(atual->nome,str)) 
{ 
if (atual == inicio && ultimo == NULL) 
{ 
free(atual); 
inicio = NULL; 
r = 1; 
break;
}
else if(atual == inicio)
{ 
inicio = atual->proximo;
free(atual); 
r = 1;
break;
}
else if (atual->codigo == ultimo->codigo) 
{ 
ultimo->proximo = antes; 
antes->proximo = NULL; 
free(atual); 
r = 1;
ultimo = antes;
break;
}
else 
{ 
pass = atual; 
pass = atual->proximo; 
antes->proximo = pass; 
r = 1;
free(atual);
break;
}
}
else 
{ 
antes = atual; 
atual = atual->proximo;
}
} while(antes != ultimo);
if(r > 0){ return 1; } else { return 0; } 
}



//menu

int main()
{
char str[35];
int a,p;
char ch1,ch2;
inicio = ultimo = novo = NULL;
for(;;)
{
system ("cls");
         printf("\t********************************************************************\n");
         printf("\t********************************************************************\n");
         printf("\t**                                                                **\n");
         printf("\t**                                                                **\n");
         printf("\t**                                                                **\n");
         printf("\t**                                                                **\n");
         printf("\t**                                                                **\n");
         printf("\t**                                                                **\n");
         printf("\t**                                                                **\n");
         printf("\t**                                                                **\n");
         printf("\t********************************************************************\n");
         printf("\t********************************************************************\n");
         printf("\t********************************************************************\n");
         printf("\t*               1-Cadastrar Conta Corrente                         *\n");
         printf("\t*               2-Listar Conta Corrente                            *\n");
         printf("\t*               3-Excluir Conta Corrente                           *\n");
         printf("\t*                                                                  *\n");
         printf("\t*               4-Sair                                             *\n");  
         printf("\t********************************************************************\n"); 
         printf("Entre com a opcao desejada: \n");
         scanf("%d", &a);
switch(a) 
{
case 1 : { 
if(inserir() == 1) { 
printf("\n\n - Cliente cadastrado com sucesso \n\n\n"); 
}
//else { 
//printf("\n\n - Código ou nome do cliente jah estao em uso.\n\n\n"); 
//}
system("pause");
break;
}
case 2 : listar(); break;

case 3 : { 
      system("cls");
	  printf ("\t********************************************************************\n");
      printf ("\t*                                                                  *\n");
      printf ("\t*                   Excluir Conta Corrente                         *\n");
      printf ("\t*                                                                  *\n");
      printf ("\t********************************************************************\n");
      printf ("\t********************************************************************\n");
      printf ("\t*                                                                  *\n");  
      printf ("\t*                                                                  *\n");
      printf ("\t*                                                                  *\n");  
      printf ("\t********************************************************************\n");
printf("\n-->Informe o Nome da Conta a ser excluida: ");
scanf("%s", &str); 
if(deletar(str) == 1)
{
printf("\n\n - Cliente excluido com sucesso \n\n\n");
}
else 
{
printf("\n\n - Não foi possivel excluir cliente \n\n\n");
}

printf("\n-->Conta nao encontrada no cadastro - entre com nova conta: ");
scanf("%s",&str);	
do{
client *p; 
p = ultimo;
if(ultimo == NULL)
printf(" \n-->Numero Conta Corrente %d\n", p->codigo); 
printf("Nome do Correntista %s\n", p->nome);
printf("Endereco-Rua %s\n", p->rua);
printf("Endereco-Numero %s\n", p->numero);
printf("Endereco-Bairro %s\n", p->bairro);
printf("Endereco-Cidade %s\n", p->cidade);
printf("Endereco-Estado %s\n", p->estado);
printf("E-mail do Correntista %s\n", p->email);
p = p->proximo;
}while(p != NULL); 
/*
printf("\nConfirme a exclusao  [S/N]  "); 
       ch1 = getchar();
       if(ch1 == 's')
		 {
       printf("\nConta Corrente excluida\n");
       
         } 
      else 
      ch2 = getchar();
	 if(ch2 == 'n')
	 {
     printf("\nConta Corrente NAO excluida\n");
     }
getch();

*/
}


case 4 : limparmemoria(); 
} 
}
}
