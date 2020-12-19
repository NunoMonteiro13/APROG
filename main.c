#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>                                                                                 //Biblioteca para acentuação da lingua portuguesa


struct cliente {
   char  nome[50];
   int   nif;
};
void menu_clientes()                                                                                //Função clientes
    {
            system("cls");                                                                          //Limpar ecrã
            int escolha_menu;                                                                       //variável local para guardar o valor da escolha do menu
                        /*Cabeçalho do menu e formatação "gráfica"*/
            printf("|------------------------------------------------------------|");
            printf("\n|                    MENU CLIENTES                           |\n");
            printf("|     1-Inserir novo clientes                                |\n");
            printf("|     2-Atualizar informação cliente                         |\n");
            printf("|     3-Remover cliente                                      |\n");
            printf("|     4-Voltar ao menu principal                             |\n");
            printf("|------------------------------------------------------------|");

            scanf("%d", &escolha_menu);                                                             //Leitura e atribuição do valor intrdouzido à variável local escolha_menu
            switch(escolha_menu)                                                                    //Função caso para seleção de menu consoante o valor introduizido
            {
                case 1: inserir_cliente();                                                          //caso o valor introduzido seja '1' -> a função inserir_cliente é invocada
                    break;
                case 2: atualizar_cliente();                                                        //caso o valor introduzido seja '2' -> a função atualizar_cliente é invocada
                    break;
                case 3: remover_cliente();                                                          //caso o valor introduzido seja '3' -> a função remover_cliente é invocada
                    break;
                case 4: menu_principal();                                                           //caso o valor introduzido seja '4' -> a função menu_principal é invocada
                    break;
            }
    }
void menu_servicos()                                                                                //Função serviços
    {
            system("cls");                                                                          //Limpar ecrã
                    /*Cabeçalho do menu e formatação "gráfica"*/
            printf("|------------------------------------------------------------|");
            printf("\n|                    MENU SERVIÇOS                           |\n");
            printf("|     1-Canais disponíveis                                   |\n");
            printf("|     2-Servicos adicionais                                  |\n");
            printf("|     3-Tarifários do serviço de voz                         |\n");
            printf("|     4-Voltar ao menu principal                             |\n");
            printf("|------------------------------------------------------------|");
    }
void menu_listagens()                                                                               //Função listagens
    {
            system("cls");                                                                          //Limpar ecrã
                    /*Cabeçalho do menu e formatação "gráfica"*/
            printf("|-----------------------------------------------------------------------|");
            printf("\n|                    MENU LISTAGENS                                     |\n");
            printf("|     1-Informação dos clientes                                         |\n");
            printf("|     2-Clientes ativos e inativos;                                     |\n");
            printf("|     3-Lista de canais disponíveis                                     |\n");
            printf("|     4-Lista de serviços adicionais                                    |\n");
            printf("|     5-Lista de clientes que estão no fim do período de fidelização    |\n");
            printf("|     6-Lista de tarifários                                             |\n");
            printf("|     7-Voltar ao menu principal                             |\n");
            printf("|-----------------------------------------------------------------------|");
    }
void menu_informacoes()                                                                             //Função informações
    {
            system("cls");                                                                          //Limpar ecrã
                    /*Cabeçalho do menu e formatação "gráfica"*/
            printf("|------------------------------------------------------------|");
            printf("\n|                    MENU INFORMAÇÕES                        |\n");
            printf("|     1-Clientes inativos por falta de pagamento             |\n");
            printf("|     2-Serviços de um determinado cliente                   |\n");
            printf("|     3-Voltar ao menu principal                             |\n");
            printf("|------------------------------------------------------------|");
    }
void menu_faturacao()                                                                               //Função faturação
    {
            system("cls");                                                                          //Limpar ecrã
                    /*Cabeçalho do menu e formatação "gráfica"*/
            printf("|------------------------------------------------------------|");
            printf("\n|                    MENU FATURAÇÂO                          |\n");
            printf("|     1-Calculo dos valores de chamada                       |\n");
            printf("|     2-Total a pagar pelo clinete                           |\n");
            printf("|     3-Voltar ao menu principal                             |\n");
            printf("|------------------------------------------------------------|");
    }
void menu_principal()                                                                               //Função menu
    {
            system("cls");                                                                          //Limpar ecrã
            int escolha_menu;                                                                       //variável local para guardar o valor da escolha do menu
                            /*Cabeçalho do menu e formatação "gráfica"*/
            printf("|------------------------------------------------------------|");
            printf("\n|                    MENU PRINCIPAL                          |\n");
            printf("|     1-Clientes                                             |\n");
            printf("|     2-Servicos                                             |\n");
            printf("|     3-Listagens                                            |\n");
            printf("|     4-Informação                                           |\n");
            printf("|     5-Faturação                                            |\n");
            printf("|------------------------------------------------------------|\n");

            scanf("%d", &escolha_menu);                                                             //Leitura e atribuição do valor intrdouzido à variável local escolha_menu
            switch(escolha_menu)                                                                    //Função caso para seleção de menu consoante o valor introduizido
            {
                case 1: menu_clientes();                                                            //caso o valor introduzido seja '1' -> a função menu_clientes é invocada
                    break;
                case 2: menu_servicos();                                                            //caso o valor introduzido seja '2' -> a função menu_servicos é invocada
                    break;
                case 3: menu_listagens();                                                           //caso o valor introduzido seja '3' -> a função menu_listagens é invocada
                    break;
                case 4: menu_informacoes();                                                         //caso o valor introduzido seja '4' -> a função menu_informacoes é invocada
                    break;
                case 5: menu_faturacao();                                                           //caso o valor introduzido seja '5' -> a função menu_faturacao é invocada
                    break;
            }


    }
void inserir_cliente()
    {
        system("cls");                                                                              //Limpar ecrã
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
        setlocale(LC_ALL,"Portuguese");                                                             //Linguagem local para a utilização dos acentos da língua portuguesa
        //func_intro_clientes();
        menu_principal();
}
