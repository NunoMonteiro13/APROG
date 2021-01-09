#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>                                                                                                     //Biblioteca para lingua portuguesa

/*Delcaração protótipo das funções*/
void menu_principal();
void inserir_cliente();
void menu_clientes();
void menu_servicos();
//void menu_listagens(struct canais channel[0]);
void menu_informacoes();
void menu_faturacao();
void info_cliente();
void atualizar_cliente();
void remover_cliente();
void inserir_canais();

//struct nomecanal info_canais(struct nomecanal);



/*Como não sabemos a quantidade de clientes que vão ser introduzidos,
foi criado um vector para ser possivel guardar vários clientes,
e posteriormente no programa, o tamanho deste
vector será assignado pelo input do utilizador.*/
struct cliente {
   char  nome[50];
   int   nif;
};
struct cliente client[0];

struct canais {
   char  canal[50];
   int   quantidade;
};
struct canais nomecanal[0];
void info_canais(struct canais channel[0]);


struct servicosadicionais {
   char  servicos[50];
};
struct servicosadicionais nomeservico[0];

struct tarifariovoz {
   char  tarifario[50];
};
struct tarifariovoz nometarifario[0];


int numero_client_total = 0;                                                                                            //variável que guarda o número total de clientes no programa
//int numero_canais_total = 0;                                                                                          //variável que guarda o número total de cnais no programa


void menu_principal()                                                                                                   //Função menu
    {
            system("cls");                                                                                              //Limpar ecrã
            int escolha_menu;                                                                                           //variável local para guardar o valor da escolha do menu
                            /*Cabeçalho do menu e formatação "gráfica"*/
            printf("|------------------------------------------------------------|");
            printf("\n|                    MENU PRINCIPAL                          |\n");
            printf("|     1-Clientes                                             |\n");
            printf("|     2-Servicos                                             |\n");
            printf("|     3-Listagens                                            |\n");
            printf("|     4-Informação                                           |\n");
            printf("|     5-Faturação                                            |\n");
            printf("|------------------------------------------------------------|\n");

            scanf("%c", &escolha_menu);                                                                                 //Leitura e atribuição do valor intrdouzido à variável local escolha_menu
            fflush(stdin);
            switch(escolha_menu)                                                                                        //Função caso para seleção de menu consoante o valor introduizido
            {
                case '1': menu_clientes();                                                                                //caso o valor introduzido seja '1' -> a função menu_clientes é invocada
                    break;
                case '2': menu_servicos();                                                                                //caso o valor introduzido seja '2' -> a função menu_servicos é invocada
                    break;
                case '3': menu_listagens();                                                                               //caso o valor introduzido seja '3' -> a função menu_listagens é invocada
                    break;
                case '4': menu_informacoes();                                                                             //caso o valor introduzido seja '4' -> a função menu_informacoes é invocada
                    break;
                case '5': menu_faturacao();                                                                               //caso o valor introduzido seja '5' -> a função menu_faturacao é invocada
                    break;
            }
    }
void inserir_cliente()                                                                                                  //Função inserir cliente
    {
        system("cls");                                                                                                  //Limpar ecrã
        int i = 0;                                                                                                      //Inicialização da variável contadora i
        int quantidade_clientes = 0;                                                                                    //Inicialização da que irá guardar a quantidade de clientes a serem adicionados
        printf("Indique a quantidade de clientes a serem inseridos: ");
        scanf("%d", &quantidade_clientes);                                                                              //Leitura da quantidade de clientes introduzida para a variável quantidade_clientes
        for(i = 0; i < quantidade_clientes; ++i)                                                                        //Inicialização do ciclo 'para' que começa em 0, vai até o numero de clientes introduzidos e incrementa de 1 em 1
            {
                printf("Insira o nome do %d cliente: ", i+numero_client_total+1);
                scanf(" %[^\t\n]c", client[i+numero_client_total].nome);                                                //Leitura do nome do cliente introduzido com a possibilidade de ler nomes separados por espaços
                printf("Insira o NIF do %d cliente: ", i+numero_client_total+1);
                scanf("%d", &client[i+numero_client_total].nif);                                                        //Leitura do NIF do cliente e guarda no vetor i na posição i
                system ("cls");                                                                                         //Limpar ecrã
            }
        numero_client_total = quantidade_clientes + numero_client_total;
        printf("%d - Clientes introduzidos com sucesso\n", numero_client_total);
        system("pause");
            /*REVER ESTA NECESSIDADE DESTA PARTE!!!!!!!!!*/
        /*for(j = 0; j <= quantidade_clientes; ++j)
            {
                printf("\nNome do %d cliente inserido: ", j+1);
                printf("%s", client[j].nome);
                printf("\nNIF do %d cliente inserido: ", j+1);
                printf("%d", client[j].nif);
            }*/
        menu_principal();                                                                                               //Após intrudoção dos clientes o programa volta para o menu principal
    }
void menu_clientes()                                                                                                    //Função clientes
    {
            system("cls");                                                                                              //Limpar ecrã
            int escolha_menu;                                                                                           //variável local para guardar o valor da escolha do menu
                        /*Cabeçalho do menu e formatação "gráfica"*/
            printf("|------------------------------------------------------------|");
            printf("\n|                    MENU CLIENTES                           |\n");
            printf("|     1-Inserir novo clientes                                |\n");
            printf("|     2-Atualizar informação cliente                         |\n");
            printf("|     3-Remover cliente                                      |\n");
            printf("|     4-Voltar ao menu principal                             |\n");
            printf("|------------------------------------------------------------|");

            scanf("%c", &escolha_menu);                                                                                 //Leitura e atribuição do valor intrdouzido à variável local escolha_menu
            fflush(stdin);
            switch(escolha_menu)                                                                                        //Função caso para seleção de menu consoante o valor introduizido
            {
                case '1': inserir_cliente();                                                                              //caso o valor introduzido seja '1' -> a função inserir_cliente é invocada
                    break;
                case '2': atualizar_cliente();                                                                            //caso o valor introduzido seja '2' -> a função atualizar_cliente é invocada
                    break;
                case '3': remover_cliente();                                                                              //caso o valor introduzido seja '3' -> a função remover_cliente é invocada
                    break;
                case '4': menu_principal();                                                                               //caso o valor introduzido seja '4' -> a função menu_principal é invocada
                    break;
            }
    }

void  inserir_canais()                                                                                                  //função recebe por referência a estrutura canais
    {

        system("cls");                                                                                                  //Limpar ecrã
        int i = 0;                                                                                                      //Inicialização da variável contadora i
        int j = 0;
        int quantidade_canais = 0;
        printf("Indique a quantidade de canais a serem inseridos: ");
        scanf("%d", &quantidade_canais);                                                                                //Leitura da quantidade de canais introduzida para a variável quantidade_serviços
        for(i = 0; i < quantidade_canais; ++i)                                                                          //Inicialização do ciclo 'para' que começa em 0, vai até o numero de canais introduzidos e incrementa de 1 em 1
            {
                printf("Insira o %d canal a ser adicionado: ", i+nomecanal[0].quantidade);
                scanf(" %[^\t\n]c", nomecanal[i+nomecanal[0].quantidade].canal);                                                //Leitura do nome do cliente introduzido com a possibilidade de ler nomes separados por espaços
                system("cls");
            }
        nomecanal[0].quantidade = quantidade_canais + nomecanal[0].quantidade;
        printf("%d canais introduzidos com sucesso!\n", quantidade_canais);
        printf("total de canais = %d\n", nomecanal[0].quantidade);
        system("pause");
        menu_principal();                                                                                               //Após intrudoção dos clientes o programa volta para o menu principal
    }

void menu_servicos()                                                                                                    //Função serviços
    {
            system("cls");                                                                                              //Limpar ecrã
            int escolha_menu;                                                                                           //variável local para guardar o valor da escolha do menu
                    /*Cabeçalho do menu e formatação "gráfica"*/
            printf("|------------------------------------------------------------|");
            printf("\n|                    MENU SERVIÇOS                           |\n");
            printf("|     1-Inserir Canais disponíveis                           |\n");
            printf("|     2-Inserir Servicos adicionais                          |\n");
            printf("|     3-Inserir Tarifários do serviço de voz                 |\n");
            printf("|     4-Remover Canais disponíveis                           |\n");
            printf("|     5-Remover Serviços adicionais                          |\n");
            printf("|     6-Remover Tarifários do serviço de voz                 |\n");
            printf("|     7-Voltar ao menu principal                             |\n");
            printf("|------------------------------------------------------------|");
            scanf("%c", &escolha_menu);                                                                                 //Leitura e atribuição do valor intrdouzido à variável local escolha_menu
            fflush(stdin);
            switch(escolha_menu)                                                                                        //Função caso para seleção de menu consoante o valor introduizido
            {
                case '1': inserir_canais();                                                                               //caso o valor introduzido seja '1' -> a função inserir_cliente é invocada
                    break;
//                case '2': atualizar_cliente();                                                                            //caso o valor introduzido seja '2' -> a função atualizar_cliente é invocada
//                    break;
//                case '3': remover_cliente();                                                                              //caso o valor introduzido seja '3' -> a função remover_cliente é invocada
//                    break;
//                case '4': menu_principal();                                                                               //caso o valor introduzido seja '4' -> a função menu_principal é invocada
//                    break;
//                case '5': menu_principal();                                                                               //caso o valor introduzido seja '4' -> a função menu_principal é invocada
//                    break;
//                case '6': menu_principal();                                                                               //caso o valor introduzido seja '4' -> a função menu_principal é invocada
//                    break;
//                case '7': menu_principal();                                                                               //caso o valor introduzido seja '4' -> a função menu_principal é invocada
//                    break;
            }

    }

void menu_listagens()                                                                                                   //Função listagens
    {
            system("cls");                                                                                              //Limpar ecrã
            int escolha_menu;                                                                                           //variável local para guardar o valor da escolha do menu
                    /*Cabeçalho do menu e formatação "gráfica"*/
            printf("|-----------------------------------------------------------------------|");
            printf("\n|                    MENU LISTAGENS                                     |\n");
            printf("|     1-Informação dos clientes                                         |\n");
            printf("|     2-Clientes ativos e inativos;                                     |\n");
            printf("|     3-Lista de canais disponíveis                                     |\n");
            printf("|     4-Lista de serviços adicionais                                    |\n");
            printf("|     5-Lista de clientes que estão no fim do período de fidelização    |\n");
            printf("|     6-Lista de tarifários                                             |\n");
            printf("|     7-Voltar ao menu principal                                        |\n");
            printf("|-----------------------------------------------------------------------|");
            scanf("%c", &escolha_menu);                                                                                 //Leitura e atribuição do valor intrdouzido à variável local escolha_menu
            switch(escolha_menu)                                                                                        //Função caso para seleção de menu consoante o valor introduizido

            {
                case '1': info_cliente();                                                                                 //caso o valor introduzido seja '1' -> a função info_cliente é invocada
                    break;
//                case '2': menu_servicos();                                                                              //caso o valor introduzido seja '2' -> a função menu_servicos é invocada
//                    break;
                case '3': info_canais(nomecanal);                                                                                  //caso o valor introduzido seja '3' -> a função info_canais é invocada
//                      break;
//                case '4': menu_informacoes();                                                                             //caso o valor introduzido seja '4' -> a função menu_informacoes é invocada
//                    break;
//                case '5': menu_faturacao();                                                                               //caso o valor introduzido seja '5' -> a função menu_faturacao é invocada
//                    break;
            }
    }
void menu_informacoes()                                                                                                 //Função informações
    {
            system("cls");                                                                                              //Limpar ecrã
                    /*Cabeçalho do menu e formatação "gráfica"*/
            printf("|------------------------------------------------------------|");
            printf("\n|                    MENU INFORMAÇÕES                        |\n");
            printf("|     1-Clientes inativos por falta de pagamento             |\n");
            printf("|     2-Serviços de um determinado cliente                   |\n");
            printf("|     3-Voltar ao menu principal                             |\n");
            printf("|------------------------------------------------------------|");
    }
void menu_faturacao()                                                                                                   //Função faturação
    {
            system("cls");                                                                                              //Limpar ecrã
                    /*Cabeçalho do menu e formatação "gráfica"*/
            printf("|------------------------------------------------------------|");
            printf("\n|                    MENU FATURAÇÂO                          |\n");
            printf("|     1-Calculo dos valores de chamada                       |\n");
            printf("|     2-Total a pagar pelo clinete                           |\n");
            printf("|     3-Voltar ao menu principal                             |\n");
            printf("|------------------------------------------------------------|");
    }
void info_cliente()
    {
        system("cls");                                                                                                  //Limpar ecrã
        int i = 0;
        printf("Numero de clientes total: %d\n", numero_client_total);
        for(i = 0; i < numero_client_total; ++i)
            {
                printf("\nNome do %d cliente inserido: ", i);
                printf("%s", client[i].nome);
                printf("\nNIF do %d cliente inserido: ", i);
                printf("%d\n", client[i].nif);
            }
        system("pause");                                                                                                //Pausa o programa antes que outra função seja selecionada
        menu_principal();
    }
void atualizar_cliente()
    {
        int escolha_cliente;                                                                                            //Variável que irá guardar o cliente a ser atualizado
        int i = 0;                                                                                                      //Variável contadora
        printf("Selecione o cliente que prentende atualizar:\n");
        for (i = 0; i < numero_client_total; ++i)                                                                       //ciclo para pesquisar o cliente guardado na variável escolha_cliente
            {
                printf("%d - %s\n", i, client[i].nome);
            }
        scanf("%d", &escolha_cliente);                                                                                  //Após aparecer a lista dos clientes, leitura do cliente escolhido
        for(i = 0; i <= numero_client_total; ++i)                                                                       //Ciclo pra selecionar o cliente contido na variável escolha_ciente
            {
                if(escolha_cliente == i)                                                                                //Condição para selecionar o cliente escolhido
                    {
                        printf("Clienten selecionado - %s - Introduza novos dados\n", client[i].nome);
                        printf("Insira o nome do cliente: ");
                        scanf(" %[^\t\n]c", client[i].nome);                                                            //Introdução dos dados atualizados do cliente
                        printf("Insira o NIF do cliente: ");
                        scanf("%d", &client[i].nif);
                    }
            }

        system("pause");                                                                                                //Pausa o programa antes que outra instrução seja executada
        menu_principal();
    }
void remover_cliente()
    {
        int escolha_cliente;                                                                                            //Variável que irá guardar o cliente a ser apagado
        int i = 0;                                                                                                      //Variável contadora
        char confirmacao;                                                                                               //Variável que irá guardar a confirmação para apagar o cliente
        printf("Selecione o cliente que prentende remover:\n");
        for (i = 0; i < numero_client_total; ++i)                                                                       //ciclo para pesquisar o cliente guardado na variável escolha_cliente
            {
                printf("%d - %s\n", i, client[i].nome);
            }
        scanf("%d", &escolha_cliente);                                                                                  //Após aparecer a lista dos clientes, leitura do cliente escolhido
        for(i = 0; i < numero_client_total; ++i)                                                                        //Ciclo pra selecionar o cliente contido na variável escolha_ciente
            {
                if(escolha_cliente == i)                                                                                //Condição para selecionar o cliente escolhido
                    {
                        printf("Cliente selecionado - %s\n", client[i].nome);                                           //Mostra o cliente selecionado
                        printf("Tem a certeza que deseja remover o cliente - %s do programa ? [s/n]", client[i].nome);  //Mensagem para confirmação do cliente a remover
                        scanf(" %c", &confirmacao);                                                                     //Leitura da confirmação
                        if(confirmacao == 's')                                                                          //Testa se a confirmação é sim ou não
                            {
                                for(i = escolha_cliente; i < numero_client_total; i++)                                  //Ciclo para selecionar o cliente prentendido
                                    {
                                        client[i] = client[i+1];                                                        //Descolacamento das variáveis do vetor de forma a reorganizar removendo o cliente pretendido
                                    }
                                printf("Cliente removido com sucesso!\n");
                            }else                                                                                       //Caso a confirmação não seja verdadeira (escolha_cliente != 's'), a operação é cancelada
                            {
                                printf("Operação cancelada!\n");
                            }
                        numero_client_total = numero_client_total - 1;                                                  //redução do número total de cilentes presentes no programa
                    }
            }

        system("pause");                                                                                                //Pausa o programa antes que outra instrução seja executada
        menu_principal();
    }

void info_canais(struct canais channel[0])
    {
        system("cls");                                                                                                  //Limpar ecrã
        int i = 0;
        printf("Numero de canais total: %d\n", channel[0].quantidade);
        for(i = 0; i < channel[0].quantidade; ++i)
            {
                printf("\n Canal %d inserido: ", i);
                printf("%s\n", channel[i].canal);
            }
        system("pause");                                                                                                //Pausa o programa antes que outra função seja selecionada
        menu_principal();
    }

int main( ) {
        setlocale(LC_ALL,"Portuguese");                                                                                 //Linguagem local para a utilização dos acentos da língua portuguesa
        menu_principal();

}

