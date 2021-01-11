#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>                                                                                                     //Biblioteca para lingua portuguesa

/*Declara��o prot�tipo das fun��es*/
void menu_principal();
void inserir_cliente();
void menu_clientes();
void menu_servicos();
void menu_listagens();
void menu_informacoes();
void menu_faturacao();
void info_cliente();
void atualizar_cliente();
void remover_cliente();
int* selecionar_cliente();
void adicionar_canal();
void menu_canais_base();
void menu_canais_extra();
void menu_canais_extra_xl();
void menu_disney();
void menu_canais_extra();
void menu_sportv();
void menu_tvcine();
void menu_voz2000m();
void menu_voz5000m();
void menu_voz_ilimitado();
void adicionar_voz();
void adicionar_servico();
void menu_canais_disponiveis();


typedef struct voz {
    int numeroMin;
} voz;

typedef struct canal {
    int numerocanais;
} canal;



typedef struct cliente {
   char  nome[50];
   int   nif;
   voz* voz;
   canal* canal;
} cliente;
struct cliente client[0];                                                                                               /*Como n�o sabemos a quantidade de clientes que v�o ser introduzidos,
                                                                                                                        foi criado um vector para ser possivel guardar v�rios clientes,
                                                                                                                        e posteriormente no programa, o tamanho deste
                                                                                                                        vector ser� assignado pelo input do utilizador.
                                                                                                                        */
int numero_client_total = 0;                                                                                            //vari�vel que guarda o n�mero total de clientes no programa

void menu_principal()                                                                                                   //Fun��o menu
    {
            system("cls");                                                                                              //Limpar ecr�
            int escolha_menu;                                                                                           //vari�vel local para guardar o valor da escolha do menu
                            /*Cabe�alho do menu e formata��o "gr�fica"*/
            printf("|------------------------------------------------------------|\n");
            printf("|                    MENU PRINCIPAL                          |\n");
            printf("|     1-Clientes                                             |\n");
            printf("|     2-Servicos                                             |\n");
            printf("|     3-Listagens                                            |\n");
            printf("|     4-Informa��o                                           |\n");
            printf("|     5-Fatura��o                                            |\n");
            printf("|------------------------------------------------------------|\n");

            scanf("%d", &escolha_menu);                                                                                 //Leitura e atribui��o do valor intrdouzido � vari�vel local escolha_menu
            switch(escolha_menu)                                                                                        //Fun��o caso para sele��o de menu consoante o valor introduizido
            {
                case 1: menu_clientes();                                                                                //caso o valor introduzido seja '1' -> a fun��o menu_clientes � invocada
                    break;
                case 2: menu_servicos();                                                                                //caso o valor introduzido seja '2' -> a fun��o menu_servicos � invocada
                    break;
                case 3: menu_listagens();                                                                               //caso o valor introduzido seja '3' -> a fun��o menu_listagens � invocada
                    break;
                case 4: menu_informacoes();                                                                             //caso o valor introduzido seja '4' -> a fun��o menu_informacoes � invocada
                    break;
                case 5: menu_faturacao();                                                                               //caso o valor introduzido seja '5' -> a fun��o menu_faturacao � invocada
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
            printf("|------------------------------------------------------------|\n");
            printf("|                    MENU CLIENTES                           |\n");
            printf("|     1-Inserir novos clientes                               |\n");
            printf("|     2-Atualizar informa��o cliente                         |\n");
            printf("|     3-Remover cliente                                      |\n");
            printf("|     4-Voltar ao menu principal                             |\n");
            printf("|------------------------------------------------------------|");

            scanf("%d", &escolha_menu);                                                                                 //Leitura e atribui��o do valor intrdouzido � vari�vel local escolha_menu
            switch(escolha_menu)                                                                                        //Fun��o caso para sele��o de menu consoante o valor introduizido
            {
                case 1: inserir_cliente();                                                                              //caso o valor introduzido seja '1' -> a fun��o inserir_cliente � invocada
                    break;
                case 2: atualizar_cliente();                                                                            //caso o valor introduzido seja '2' -> a fun��o atualizar_cliente � invocada
                    break;
                case 3: remover_cliente();                                                                              //caso o valor introduzido seja '3' -> a fun��o remover_cliente � invocada
                    break;
                case 4: menu_principal();                                                                               //caso o valor introduzido seja '4' -> a fun��o menu_principal � invocada
                    break;
            }
             menu_principal();
    }
void menu_servicos()                                                                                                    //Fun��o servi�os
    {
            system("cls");
            int escolha_menu;                                                                                             //Limpar ecr�
                    /*Cabe�alho do menu e formata��o "gr�fica"*/
            printf("|------------------------------------------------------------|\n");
            printf("|                    MENU SERVI�OS                           |\n");
            printf("|     1-Canais dispon�veis                                   |\n");
            printf("|     2-Servicos adicionais                                  |\n");
            printf("|     3-Tarif�rios do servi�o de voz                         |\n");
            printf("|     4-Voltar ao menu principal                             |\n");
            printf("|------------------------------------------------------------|\n");

            scanf("%d", &escolha_menu);                                                          //Leitura e atribui��o do valor intrdouzido � vari�vel local escolha_menu
            switch(escolha_menu)                                                                 //Fun��o caso para sele��o de menu consoante o valor introduizido
            {
                case 1: menu_canais_disponiveis();                                               //caso o valor introduzido seja '1' -> a fun��o menu_canaisdisponiveis � invocada
                    break;
                case 2: menu_servicos_adicionais();                                              //caso o valor introduzido seja '2' -> a fun��o menu_servicosadicionais � invocada
                    break;
                case 3: menu_tarifarios_servicos_voz();                                            //caso o valor introduzido seja '3' -> a fun��o menu_tarifarioservicovoz � invocada
                    break;
                case 4: menu_principal();                                          //caso o valor introduzido seja '4' -> a fun��o menu_coltaraomenuprincipal � invocada
                    break;
                }
                menu_principal();
    }

void menu_canaisdisponiveis()                                                                         //Fun��o inserir servico
    {
        system("cls");                                                                         //Limpar ecr�
        int i = 0;
        int escolha_menu;
                                                                                               //Inicializa��o da vari�vel contadora c

            printf("|------------------------------------------------------------|\n");
            printf("|                    CANAIS DISPONIVEIS                      |\n");
            printf("|     1-Canais base, 10 canais                               |\n");
            printf("|     2-Canais extra, 20 canais                              |\n");
            printf("|     3-Canais extra XL, 30 canais                           |\n");
            printf("|     4-Voltar ao menu principal                             |\n");
            printf("|------------------------------------------------------------|");

            scanf("%d", &escolha_menu);                                                   //Leitura e atribui��o do valor intrdouzido � vari�vel local escolha_menu
            switch(escolha_menu)                                                          //Fun��o caso para sele��o de menu consoante o valor introduizido
            {
                case 1:;
                    int* client = selecionar_cliente();
                    adicionar_canal(client, 10);
                    menu_canais_base();                                               //caso o valor introduzido seja '1' -> a fun��o menu_canaisbase � invocada
                    break;
                case 2: menu_canais_extra();
                        client = selecionar_cliente();
                    adicionar_canal(client, 20);                                             //caso o valor introduzido seja '2' -> a fun��o menu_canaisextra � invocada
                    break;
                case 3: menu_canais_extra_xl();
                        client = selecionar_cliente();
                    adicionar_canal(client, 30);                                            //caso o valor introduzido seja '3' -> a fun��o menu_canaisextraxl � invocada
                    break;
                case 4: menu_principal();                                     //caso o valor introduzido seja '4' -> a fun��o menu_voltaraomenuprincipal � invocada
                    break;
                }
        menu_principal();
    }

void menu_servicos_adicionais()                                                                                                    //Fun��o servi�os
    {
            system("cls");
            int escolha_menu;                                                                                             //Limpar ecr�
                    /*Cabe�alho do menu e formata��o "gr�fica"*/
            printf("|------------------------------------------------------------|\n");
            printf("|                    SERVICOS ADICIONAIS                     |\n");
            printf("|     1-Disney                                               |\n");
            printf("|     2-SporTv                                               |\n");
            printf("|     3-TVCine                                               |\n");
            printf("|     4-Voltar ao menu principal                             |\n");
            printf("|------------------------------------------------------------|\n");

            scanf("%d", &escolha_menu);                                                          //Leitura e atribui��o do valor intrdouzido � vari�vel local escolha_menu
            switch(escolha_menu)                                                                 //Fun��o caso para sele��o de menu consoante o valor introduizido
            {
                case 1: menu_disney();
                    int* client = selecionar_cliente();
                    adicionar_servico(client, "Disney");                                               //caso o valor introduzido seja '1' -> a fun��o menu_canaisbase � invocada
                    break;                                            //caso o valor introduzido seja '1' -> a fun��o menu_disney � invocada
                case 2: menu_sportv();
                    client = selecionar_cliente();
                    adicionar_servico(client, "SporTv");
                    break;
                case 3: menu_tvcine();
                    client = selecionar_cliente();
                    adicionar_servico(client, "TVCine");                              //caso o valor introduzido seja '3' -> a fun��o menu_tvcine � invocada
                    break;
                case 4: menu_principal();

                    break;
                }
                menu_principal();
    }

void menu_tarifarios_servicos_voz()                                                                                                    //Fun��o servi�os
    {
            system("cls");
            int escolha_menu;                                                                                              //Limpar ecr�
                    /*Cabe�alho do menu e formata��o "gr�fica"*/
            printf("|------------------------------------------------------------|\n");
            printf("|                    SERVICOS DE VOZ                         |\n");
            printf("|     1-Voz 2000 minutos                                     |\n");
            printf("|     2-Voz 5000 minutos                                     |\n");
            printf("|     3-Voz ilimitado                                        |\n");
            printf("|     4-Voltar ao menu principal                             |\n");
            printf("|------------------------------------------------------------|\n");

            scanf("%d", escolha_menu);                                                          //Leitura e atribui��o do valor intrdouzido � vari�vel local escolha_menu
            switch(escolha_menu)                                                                 //Fun��o caso para sele��o de menu consoante o valor introduizido
            {
                case 1: menu_voz2000m();
                 int* client = selecionar_cliente();
                    adicionar_voz(client, 2000);                                                        //caso o valor introduzido seja '1' -> a fun��o menu_voz1000m � invocada
                    break;
                case 2: menu_voz5000m();
                    client = selecionar_cliente();
                    adicionar_voz(client, 5000);                                                        //caso o valor introduzido seja '2' -> a fun��o menu_voz5000m � invocada
                    break;
                case 3: menu_voz_ilimitado();
                    client = selecionar_cliente();
                    adicionar_voz(client, 9999999999);                                                     //caso o valor introduzido seja '3' -> a fun��o menu_vozilimitado � invocada
                    break;
                case 4: menu_principal();                                            //caso o valor introduzido seja '4' -> a fun��o menu_coltaraomenuprincipal � invocada
                    break;
                }
                menu_principal();
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
            scanf("%d", &escolha_menu);                                                                                 //Leitura e atribui��o do valor intrdouzido � vari�vel local escolha_menu
            switch(escolha_menu)                                                                                        //Fun��o caso para sele��o de menu consoante o valor introduizido
            {
                case 1: info_cliente();                                                                                 //caso o valor introduzido seja '1' -> a fun��o info_cliente � invocada
                    break;
                case 2: menu_servicos();                                                                              //caso o valor introduzido seja '2' -> a fun��o menu_servicos � invocada
                    break;
                /*case 3: menu_listagens();                                                                               //caso o valor introduzido seja '3' -> a fun��o menu_listagens � invocada
                    break;
                case 4: menu_informacoes();                                                                             //caso o valor introduzido seja '4' -> a fun��o menu_informacoes � invocada
                    break;
                case 5: menu_faturacao();                                                                               //caso o valor introduzido seja '5' -> a fun��o menu_faturacao � invocada
                    break;*/
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
                        printf("Cliente selecionado - %s - Introduza novos dados\n", client[i].nome);
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


int* selecionar_cliente()
{
        int numero_cliente;
        int i = 0;
        printf("Selecione o cliente:\n");
        for (i = 0; i < numero_client_total; ++i){
                printf("Nome: %d \n NIF: %s\n", i, client[i].nome);
            }
        scanf("%d", numero_cliente);for(i = 0; i <= numero_client_total; ++i)
            {
                if(numero_cliente == i)
                    {
                        printf("Cliente selecionado:\n nome %s\n nif %d", client[i].nome, client[i].nif);
                    }
            }

        return &numero_cliente;
}

void adicionar_canal(int* clienteP, int numeroCanais)
{
   cliente *cliente = clienteP;
   voz* vozP = cliente->voz;
   vozP->numeroMin = numeroCanais;
}

void menu_canais_base(){
    canal canal;
    if(canal.numerocanais<10)
    canal.numerocanais = 10;
}

int main( ) {
        setlocale(LC_ALL,"Portuguese");                                                                                 //Linguagem local para a utiliza��o dos acentos da l�ngua portuguesa
        menu_principal();
        return 0;
}
