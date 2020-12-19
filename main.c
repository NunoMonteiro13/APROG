#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>                                                                                 //Biblioteca para acentua��o da lingua portuguesa


struct cliente {
   char  nome[50];
   int   nif;
};
void menu_clientes()                                                                                //Fun��o clientes
    {
            system("cls");                                                                          //Limpar ecr�
            int escolha_menu;                                                                       //vari�vel local para guardar o valor da escolha do menu
                        /*Cabe�alho do menu e formata��o "gr�fica"*/
            printf("|------------------------------------------------------------|");
            printf("\n|                    MENU CLIENTES                           |\n");
            printf("|     1-Inserir novo clientes                                |\n");
            printf("|     2-Atualizar informa��o cliente                         |\n");
            printf("|     3-Remover cliente                                      |\n");
            printf("|     4-Voltar ao menu principal                             |\n");
            printf("|------------------------------------------------------------|");

            scanf("%d", &escolha_menu);                                                             //Leitura e atribui��o do valor intrdouzido � vari�vel local escolha_menu
            switch(escolha_menu)                                                                    //Fun��o caso para sele��o de menu consoante o valor introduizido
            {
                case 1: inserir_cliente();                                                          //caso o valor introduzido seja '1' -> a fun��o inserir_cliente � invocada
                    break;
                case 2: atualizar_cliente();                                                        //caso o valor introduzido seja '2' -> a fun��o atualizar_cliente � invocada
                    break;
                case 3: remover_cliente();                                                          //caso o valor introduzido seja '3' -> a fun��o remover_cliente � invocada
                    break;
                case 4: menu_principal();                                                           //caso o valor introduzido seja '4' -> a fun��o menu_principal � invocada
                    break;
            }
    }
void menu_servicos()                                                                                //Fun��o servi�os
    {
            system("cls");                                                                          //Limpar ecr�
                    /*Cabe�alho do menu e formata��o "gr�fica"*/
            printf("|------------------------------------------------------------|");
            printf("\n|                    MENU SERVI�OS                           |\n");
            printf("|     1-Canais dispon�veis                                   |\n");
            printf("|     2-Servicos adicionais                                  |\n");
            printf("|     3-Tarif�rios do servi�o de voz                         |\n");
            printf("|     4-Voltar ao menu principal                             |\n");
            printf("|------------------------------------------------------------|");
    }
void menu_listagens()                                                                               //Fun��o listagens
    {
            system("cls");                                                                          //Limpar ecr�
                    /*Cabe�alho do menu e formata��o "gr�fica"*/
            printf("|-----------------------------------------------------------------------|");
            printf("\n|                    MENU LISTAGENS                                     |\n");
            printf("|     1-Informa��o dos clientes                                         |\n");
            printf("|     2-Clientes ativos e inativos;                                     |\n");
            printf("|     3-Lista de canais dispon�veis                                     |\n");
            printf("|     4-Lista de servi�os adicionais                                    |\n");
            printf("|     5-Lista de clientes que est�o no fim do per�odo de fideliza��o    |\n");
            printf("|     6-Lista de tarif�rios                                             |\n");
            printf("|     7-Voltar ao menu principal                             |\n");
            printf("|-----------------------------------------------------------------------|");
    }
void menu_informacoes()                                                                             //Fun��o informa��es
    {
            system("cls");                                                                          //Limpar ecr�
                    /*Cabe�alho do menu e formata��o "gr�fica"*/
            printf("|------------------------------------------------------------|");
            printf("\n|                    MENU INFORMA��ES                        |\n");
            printf("|     1-Clientes inativos por falta de pagamento             |\n");
            printf("|     2-Servi�os de um determinado cliente                   |\n");
            printf("|     3-Voltar ao menu principal                             |\n");
            printf("|------------------------------------------------------------|");
    }
void menu_faturacao()                                                                               //Fun��o fatura��o
    {
            system("cls");                                                                          //Limpar ecr�
                    /*Cabe�alho do menu e formata��o "gr�fica"*/
            printf("|------------------------------------------------------------|");
            printf("\n|                    MENU FATURA��O                          |\n");
            printf("|     1-Calculo dos valores de chamada                       |\n");
            printf("|     2-Total a pagar pelo clinete                           |\n");
            printf("|     3-Voltar ao menu principal                             |\n");
            printf("|------------------------------------------------------------|");
    }
void menu_principal()                                                                               //Fun��o menu
    {
            system("cls");                                                                          //Limpar ecr�
            int escolha_menu;                                                                       //vari�vel local para guardar o valor da escolha do menu
                            /*Cabe�alho do menu e formata��o "gr�fica"*/
            printf("|------------------------------------------------------------|");
            printf("\n|                    MENU PRINCIPAL                          |\n");
            printf("|     1-Clientes                                             |\n");
            printf("|     2-Servicos                                             |\n");
            printf("|     3-Listagens                                            |\n");
            printf("|     4-Informa��o                                           |\n");
            printf("|     5-Fatura��o                                            |\n");
            printf("|------------------------------------------------------------|\n");

            scanf("%d", &escolha_menu);                                                             //Leitura e atribui��o do valor intrdouzido � vari�vel local escolha_menu
            switch(escolha_menu)                                                                    //Fun��o caso para sele��o de menu consoante o valor introduizido
            {
                case 1: menu_clientes();                                                            //caso o valor introduzido seja '1' -> a fun��o menu_clientes � invocada
                    break;
                case 2: menu_servicos();                                                            //caso o valor introduzido seja '2' -> a fun��o menu_servicos � invocada
                    break;
                case 3: menu_listagens();                                                           //caso o valor introduzido seja '3' -> a fun��o menu_listagens � invocada
                    break;
                case 4: menu_informacoes();                                                         //caso o valor introduzido seja '4' -> a fun��o menu_informacoes � invocada
                    break;
                case 5: menu_faturacao();                                                           //caso o valor introduzido seja '5' -> a fun��o menu_faturacao � invocada
                    break;
            }


    }
void inserir_cliente()
    {
        system("cls");                                                                              //Limpar ecr�
        struct cliente client[50];
        int i = 1;
        int j = 1;
        int quantidade_clientes = 0;

        printf("Indique a quantidade de clientes a serem insridos: ");
        scanf("%d", &quantidade_clientes);

        for(i = 0; i <= quantidade_clientes; ++i)
            {
                printf("Insira o nome do %d cliente: ", i+1);
                scanf(" %[^\t\n]c", client[i].nome);
                printf("Insira o NIF do %d cliente: ", i+1);
                scanf("%d", &client[i].nif);
                system ("cls");
            }
        for(j = 0; j <= quantidade_clientes; ++j)
            {
                printf("\nNome do %d cliente inserido: ", j+1);
                printf("%s", client[j].nome);
                printf("\nNIF do %d cliente inserido: ", j+1);
                printf("%d", client[j].nif);
            }
    }
void atualizar_cliente()
    {
        printf("atualizar cliente");
    }
void remover_cliente()
    {
        printf("remover cliente");
    }

int main( ) {
        setlocale(LC_ALL,"Portuguese");                                                             //Linguagem local para a utiliza��o dos acentos da l�ngua portuguesa
        //func_intro_clientes();
        menu_principal();
}
