#include <stdio.h>

struct userInfor
{
    
    int nr;
    char name[50];
    
} list;

struct userInfor list;

int main(void) 
{
    

    printf("\n------Cadastro de Telefone------\n\n\n");
    printf("Nome do usuario:\n");
    //fgets(list.name, 50, stdin);

    printf("Digite o numeiro do usuario: ");
    scanf("%d", &list.nr);
    

    printf("isso aqui %s", list.name,"%d\n",list.nr);

    return 0;

}