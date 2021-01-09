#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>                                                                                                     //Biblioteca para lingua portuguesa

/*Delcara��o prot�tipo das fun��es*/
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



/*Como n�o sabemos a quantidade de clientes que v�o ser introduzidos,
foi criado um vector para ser possivel guardar v�rios clientes,
e posteriormente no programa, o tamanho deste
vector ser� assignado pelo input do utilizador.*/
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


int numero_client_total = 0;                                                                                            //vari�vel que guarda o n�mero total de clientes no programa
//int numero_canais_total = 0;                                                                                          //vari�vel que guarda o n�mero total de cnais no programa


void menu_principal()                                                                                                   //Fun��o menu
    {
            system("cls");                                                                                              //Limpar ecr�
            int escolha_menu;                                                                                           //vari�vel local para guardar o valor da escolha do menu
                            /*Cabe�alho do menu e formata��o "gr�fica"*/
            printf("|------------------------------------------------------------|");
            printf("\n|                    MENU PRINCIPAL                          |\n");
            printf("|     1-Clientes                                             |\n");
            printf("|     2-Servicos                                             |\n");
            printf("|     3-Listagens                                            |\n");
            printf("|     4-Informa��o                                           |\n");
            printf("|     5-Fatura��o                                            |\n");
            printf("|------------------------------------------------------------|\n");

            scanf("%c", &escolha_menu);                                                                                 //Leitura e atribui��o do valor intrdouzido � vari�vel local escolha_menu
            fflush(stdin);
            switch(escolha_menu)                                                                                        //Fun��o caso para sele��o de menu consoante o valor introduizido
            {
                case '1': menu_clientes();                                                                                //caso o valor introduzido seja '1' -> a fun��o menu_clientes � invocada
                    break;
                case '2': menu_servicos();                                                                                //caso o valor introduzido seja '2' -> a fun��o menu_servicos � invocada
                    break;
                case '3': menu_listagens();                                                                               //caso o valor introduzido seja '3' -> a fun��o menu_listagens � invocada
                    break;
                case '4': menu_informacoes();                                                                             //caso o valor introduzido seja '4' -> a fun��o menu_informacoes � invocada
                    break;
                case '5': menu_faturacao();                                                                               //caso o valor introduzido seja '5' -> a fun��o menu_faturacao � invocada
                    break;
            }
    }
void inserir_cliente()                                                                                                  //Fun��o inserir cliente
    {
        system("cls");                                                                                                  //Limpar ecr�
        int i = 0;                                                                                                      //Inicializa��o da vari�vel contadora i
        int quantidade_clientes = 0;                                                                                    //Inicializa��o da que ir� guardar a quantidade de clientes a serem adicionados
        printf("Indique a quantidade de clientes a serem inseridos: ");
        scanf("%d", &quantidade_clientes);                                                                              //Leitura da quantidade de clientes introduzida para a vari�vel quantidade_clientes
        for(i = 0; i < quantidade_clientes; ++i)                                                                        //Inicializa��o do ciclo 'para' que come�a em 0, vai at� o numero de clientes introduzidos e incrementa de 1 em 1
            {
                printf("Insira o nome do %d cliente: ", i+numero_client_total+1);
                scanf(" %[^\t\n]c", client[i+numero_client_total].nome);                                                //Leitura do nome do cliente introduzido com a possibilidade de ler nomes separados por espa�os
                printf("Insira o NIF do %d cliente: ", i+numero_client_total+1);
                scanf("%d", &client[i+numero_client_total].nif);                                                        //Leitura do NIF do cliente e guarda no vetor i na posi��o i
                system ("cls");                                                                                         //Limpar ecr�
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
        menu_principal();                                                                                               //Ap�s intrudo��o dos clientes o programa volta para o menu principal
    }
void menu_clientes()                                                                                                    //Fun��o clientes
    {
            system("cls");                                                                                              //Limpar ecr�
            int escolha_menu;                                                                                           //vari�vel local para guardar o valor da escolha do menu
                        /*Cabe�alho do menu e formata��o "gr�fica"*/
            printf("|------------------------------------------------------------|");
            printf("\n|                    MENU CLIENTES                           |\n");
            printf("|     1-Inserir novo clientes                                |\n");
            printf("|     2-Atualizar informa��o cliente                         |\n");
            printf("|     3-Remover cliente                                      |\n");
            printf("|     4-Voltar ao menu principal                             |\n");
            printf("|------------------------------------------------------------|");

            scanf("%c", &escolha_menu);                                                                                 //Leitura e atribui��o do valor intrdouzido � vari�vel local escolha_menu
            fflush(stdin);
            switch(escolha_menu)                                                                                        //Fun��o caso para sele��o de menu consoante o valor introduizido
            {
                case '1': inserir_cliente();                                                                              //caso o valor introduzido seja '1' -> a fun��o inserir_cliente � invocada
                    break;
                case '2': atualizar_cliente();                                                                            //caso o valor introduzido seja '2' -> a fun��o atualizar_cliente � invocada
                    break;
                case '3': remover_cliente();                                                                              //caso o valor introduzido seja '3' -> a fun��o remover_cliente � invocada
                    break;
                case '4': menu_principal();                                                                               //caso o valor introduzido seja '4' -> a fun��o menu_principal � invocada
                    break;
            }
    }

void  inserir_canais()                                                                                                  //fun��o recebe por refer�ncia a estrutura canais
    {

        system("cls");                                                                                                  //Limpar ecr�
        int i = 0;                                                                                                      //Inicializa��o da vari�vel contadora i
        int j = 0;
        int quantidade_canais = 0;
        printf("Indique a quantidade de canais a serem inseridos: ");
        scanf("%d", &quantidade_canais);                                                                                //Leitura da quantidade de canais introduzida para a vari�vel quantidade_servi�os
        for(i = 0; i < quantidade_canais; ++i)                                                                          //Inicializa��o do ciclo 'para' que come�a em 0, vai at� o numero de canais introduzidos e incrementa de 1 em 1
            {
                printf("Insira o %d canal a ser adicionado: ", i+nomecanal[0].quantidade);
                scanf(" %[^\t\n]c", nomecanal[i+nomecanal[0].quantidade].canal);                                                //Leitura do nome do cliente introduzido com a possibilidade de ler nomes separados por espa�os
                system("cls");
            }
        nomecanal[0].quantidade = quantidade_canais + nomecanal[0].quantidade;
        printf("%d canais introduzidos com sucesso!\n", quantidade_canais);
        printf("total de canais = %d\n", nomecanal[0].quantidade);
        system("pause");
        menu_principal();                                                                                               //Ap�s intrudo��o dos clientes o programa volta para o menu principal
    }

void menu_servicos()                                                                                                    //Fun��o servi�os
    {
            system("cls");                                                                                              //Limpar ecr�
            int escolha_menu;                                                                                           //vari�vel local para guardar o valor da escolha do menu
                    /*Cabe�alho do menu e formata��o "gr�fica"*/
            printf("|------------------------------------------------------------|");
            printf("\n|                    MENU SERVI�OS                           |\n");
            printf("|     1-Inserir Canais dispon�veis                           |\n");
            printf("|     2-Inserir Servicos adicionais                          |\n");
            printf("|     3-Inserir Tarif�rios do servi�o de voz                 |\n");
            printf("|     4-Remover Canais dispon�veis                           |\n");
            printf("|     5-Remover Servi�os adicionais                          |\n");
            printf("|     6-Remover Tarif�rios do servi�o de voz                 |\n");
            printf("|     7-Voltar ao menu principal                             |\n");
            printf("|------------------------------------------------------------|");
            scanf("%c", &escolha_menu);                                                                                 //Leitura e atribui��o do valor intrdouzido � vari�vel local escolha_menu
            fflush(stdin);
            switch(escolha_menu)                                                                                        //Fun��o caso para sele��o de menu consoante o valor introduizido
            {
                case '1': inserir_canais();                                                                               //caso o valor introduzido seja '1' -> a fun��o inserir_cliente � invocada
                    break;
//                case '2': atualizar_cliente();                                                                            //caso o valor introduzido seja '2' -> a fun��o atualizar_cliente � invocada
//                    break;
//                case '3': remover_cliente();                                                                              //caso o valor introduzido seja '3' -> a fun��o remover_cliente � invocada
//                    break;
//                case '4': menu_principal();                                                                               //caso o valor introduzido seja '4' -> a fun��o menu_principal � invocada
//                    break;
//                case '5': menu_principal();                                                                               //caso o valor introduzido seja '4' -> a fun��o menu_principal � invocada
//                    break;
//                case '6': menu_principal();                                                                               //caso o valor introduzido seja '4' -> a fun��o menu_principal � invocada
//                    break;
//                case '7': menu_principal();                                                                               //caso o valor introduzido seja '4' -> a fun��o menu_principal � invocada
//                    break;
            }

    }

void menu_listagens()                                                                                                   //Fun��o listagens
    {
            system("cls");                                                                                              //Limpar ecr�
            int escolha_menu;                                                                                           //vari�vel local para guardar o valor da escolha do menu
                    /*Cabe�alho do menu e formata��o "gr�fica"*/
            printf("|-----------------------------------------------------------------------|");
            printf("\n|                    MENU LISTAGENS                                     |\n");
            printf("|     1-Informa��o dos clientes                                         |\n");
            printf("|     2-Clientes ativos e inativos;                                     |\n");
            printf("|     3-Lista de canais dispon�veis                                     |\n");
            printf("|     4-Lista de servi�os adicionais                                    |\n");
            printf("|     5-Lista de clientes que est�o no fim do per�odo de fideliza��o    |\n");
            printf("|     6-Lista de tarif�rios                                             |\n");
            printf("|     7-Voltar ao menu principal                                        |\n");
            printf("|-----------------------------------------------------------------------|");
            scanf("%c", &escolha_menu);                                                                                 //Leitura e atribui��o do valor intrdouzido � vari�vel local escolha_menu
            switch(escolha_menu)                                                                                        //Fun��o caso para sele��o de menu consoante o valor introduizido

            {
                case '1': info_cliente();                                                                                 //caso o valor introduzido seja '1' -> a fun��o info_cliente � invocada
                    break;
//                case '2': menu_servicos();                                                                              //caso o valor introduzido seja '2' -> a fun��o menu_servicos � invocada
//                    break;
                case '3': info_canais(nomecanal);                                                                                  //caso o valor introduzido seja '3' -> a fun��o info_canais � invocada
//                      break;
//                case '4': menu_informacoes();                                                                             //caso o valor introduzido seja '4' -> a fun��o menu_informacoes � invocada
//                    break;
//                case '5': menu_faturacao();                                                                               //caso o valor introduzido seja '5' -> a fun��o menu_faturacao � invocada
//                    break;
            }
    }
void menu_informacoes()                                                                                                 //Fun��o informa��es
    {
            system("cls");                                                                                              //Limpar ecr�
                    /*Cabe�alho do menu e formata��o "gr�fica"*/
            printf("|------------------------------------------------------------|");
            printf("\n|                    MENU INFORMA��ES                        |\n");
            printf("|     1-Clientes inativos por falta de pagamento             |\n");
            printf("|     2-Servi�os de um determinado cliente                   |\n");
            printf("|     3-Voltar ao menu principal                             |\n");
            printf("|------------------------------------------------------------|");
    }
void menu_faturacao()                                                                                                   //Fun��o fatura��o
    {
            system("cls");                                                                                              //Limpar ecr�
                    /*Cabe�alho do menu e formata��o "gr�fica"*/
            printf("|------------------------------------------------------------|");
            printf("\n|                    MENU FATURA��O                          |\n");
            printf("|     1-Calculo dos valores de chamada                       |\n");
            printf("|     2-Total a pagar pelo clinete                           |\n");
            printf("|     3-Voltar ao menu principal                             |\n");
            printf("|------------------------------------------------------------|");
    }
void info_cliente()
    {
        system("cls");                                                                                                  //Limpar ecr�
        int i = 0;
        printf("Numero de clientes total: %d\n", numero_client_total);
        for(i = 0; i < numero_client_total; ++i)
            {
                printf("\nNome do %d cliente inserido: ", i);
                printf("%s", client[i].nome);
                printf("\nNIF do %d cliente inserido: ", i);
                printf("%d\n", client[i].nif);
            }
        system("pause");                                                                                                //Pausa o programa antes que outra fun��o seja selecionada
        menu_principal();
    }
void atualizar_cliente()
    {
        int escolha_cliente;                                                                                            //Vari�vel que ir� guardar o cliente a ser atualizado
        int i = 0;                                                                                                      //Vari�vel contadora
        printf("Selecione o cliente que prentende atualizar:\n");
        for (i = 0; i < numero_client_total; ++i)                                                                       //ciclo para pesquisar o cliente guardado na vari�vel escolha_cliente
            {
                printf("%d - %s\n", i, client[i].nome);
            }
        scanf("%d", &escolha_cliente);                                                                                  //Ap�s aparecer a lista dos clientes, leitura do cliente escolhido
        for(i = 0; i <= numero_client_total; ++i)                                                                       //Ciclo pra selecionar o cliente contido na vari�vel escolha_ciente
            {
                if(escolha_cliente == i)                                                                                //Condi��o para selecionar o cliente escolhido
                    {
                        printf("Clienten selecionado - %s - Introduza novos dados\n", client[i].nome);
                        printf("Insira o nome do cliente: ");
                        scanf(" %[^\t\n]c", client[i].nome);                                                            //Introdu��o dos dados atualizados do cliente
                        printf("Insira o NIF do cliente: ");
                        scanf("%d", &client[i].nif);
                    }
            }

        system("pause");                                                                                                //Pausa o programa antes que outra instru��o seja executada
        menu_principal();
    }
void remover_cliente()
    {
        int escolha_cliente;                                                                                            //Vari�vel que ir� guardar o cliente a ser apagado
        int i = 0;                                                                                                      //Vari�vel contadora
        char confirmacao;                                                                                               //Vari�vel que ir� guardar a confirma��o para apagar o cliente
        printf("Selecione o cliente que prentende remover:\n");
        for (i = 0; i < numero_client_total; ++i)                                                                       //ciclo para pesquisar o cliente guardado na vari�vel escolha_cliente
            {
                printf("%d - %s\n", i, client[i].nome);
            }
        scanf("%d", &escolha_cliente);                                                                                  //Ap�s aparecer a lista dos clientes, leitura do cliente escolhido
        for(i = 0; i < numero_client_total; ++i)                                                                        //Ciclo pra selecionar o cliente contido na vari�vel escolha_ciente
            {
                if(escolha_cliente == i)                                                                                //Condi��o para selecionar o cliente escolhido
                    {
                        printf("Cliente selecionado - %s\n", client[i].nome);                                           //Mostra o cliente selecionado
                        printf("Tem a certeza que deseja remover o cliente - %s do programa ? [s/n]", client[i].nome);  //Mensagem para confirma��o do cliente a remover
                        scanf(" %c", &confirmacao);                                                                     //Leitura da confirma��o
                        if(confirmacao == 's')                                                                          //Testa se a confirma��o � sim ou n�o
                            {
                                for(i = escolha_cliente; i < numero_client_total; i++)                                  //Ciclo para selecionar o cliente prentendido
                                    {
                                        client[i] = client[i+1];                                                        //Descolacamento das vari�veis do vetor de forma a reorganizar removendo o cliente pretendido
                                    }
                                printf("Cliente removido com sucesso!\n");
                            }else                                                                                       //Caso a confirma��o n�o seja verdadeira (escolha_cliente != 's'), a opera��o � cancelada
                            {
                                printf("Opera��o cancelada!\n");
                            }
                        numero_client_total = numero_client_total - 1;                                                  //redu��o do n�mero total de cilentes presentes no programa
                    }
            }

        system("pause");                                                                                                //Pausa o programa antes que outra instru��o seja executada
        menu_principal();
    }

void info_canais(struct canais channel[0])
    {
        system("cls");                                                                                                  //Limpar ecr�
        int i = 0;
        printf("Numero de canais total: %d\n", channel[0].quantidade);
        for(i = 0; i < channel[0].quantidade; ++i)
            {
                printf("\n Canal %d inserido: ", i);
                printf("%s\n", channel[i].canal);
            }
        system("pause");                                                                                                //Pausa o programa antes que outra fun��o seja selecionada
        menu_principal();
    }

int main( ) {
        setlocale(LC_ALL,"Portuguese");                                                                                 //Linguagem local para a utiliza��o dos acentos da l�ngua portuguesa
        menu_principal();

}

