#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>                                                                                                     //Biblioteca para lingua portuguesa

/*Declaração protótipo das funções*/
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
struct cliente client[0];                                                                                               /*Como não sabemos a quantidade de clientes que vão ser introduzidos,
                                                                                                                        foi criado um vector para ser possivel guardar vários clientes,
                                                                                                                        e posteriormente no programa, o tamanho deste
                                                                                                                        vector será assignado pelo input do utilizador.
                                                                                                                        */
int numero_client_total = 0;                                                                                            //variável que guarda o número total de clientes no programa

void menu_principal()                                                                                                   //Função menu
    {
            system("cls");                                                                                              //Limpar ecrã
            int escolha_menu;                                                                                           //variável local para guardar o valor da escolha do menu
                            /*Cabeçalho do menu e formatação "gráfica"*/
            printf("|------------------------------------------------------------|\n");
            printf("|                    MENU PRINCIPAL                          |\n");
            printf("|     1-Clientes                                             |\n");
            printf("|     2-Servicos                                             |\n");
            printf("|     3-Listagens                                            |\n");
            printf("|     4-Informação                                           |\n");
            printf("|     5-Faturação                                            |\n");
            printf("|------------------------------------------------------------|\n");

            scanf("%d", &escolha_menu);                                                                                 //Leitura e atribuição do valor intrdouzido à variável local escolha_menu
            switch(escolha_menu)                                                                                        //Função caso para seleção de menu consoante o valor introduizido
            {
                case 1: menu_clientes();                                                                                //caso o valor introduzido seja '1' -> a função menu_clientes é invocada
                    break;
                case 2: menu_servicos();                                                                                //caso o valor introduzido seja '2' -> a função menu_servicos é invocada
                    break;
                case 3: menu_listagens();                                                                               //caso o valor introduzido seja '3' -> a função menu_listagens é invocada
                    break;
                case 4: menu_informacoes();                                                                             //caso o valor introduzido seja '4' -> a função menu_informacoes é invocada
                    break;
                case 5: menu_faturacao();                                                                               //caso o valor introduzido seja '5' -> a função menu_faturacao é invocada
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
            printf("|------------------------------------------------------------|\n");
            printf("|                    MENU CLIENTES                           |\n");
            printf("|     1-Inserir novos clientes                               |\n");
            printf("|     2-Atualizar informação cliente                         |\n");
            printf("|     3-Remover cliente                                      |\n");
            printf("|     4-Voltar ao menu principal                             |\n");
            printf("|------------------------------------------------------------|");

            scanf("%d", &escolha_menu);                                                                                 //Leitura e atribuição do valor intrdouzido à variável local escolha_menu
            switch(escolha_menu)                                                                                        //Função caso para seleção de menu consoante o valor introduizido
            {
                case 1: inserir_cliente();                                                                              //caso o valor introduzido seja '1' -> a função inserir_cliente é invocada
                    break;
                case 2: atualizar_cliente();                                                                            //caso o valor introduzido seja '2' -> a função atualizar_cliente é invocada
                    break;
                case 3: remover_cliente();                                                                              //caso o valor introduzido seja '3' -> a função remover_cliente é invocada
                    break;
                case 4: menu_principal();                                                                               //caso o valor introduzido seja '4' -> a função menu_principal é invocada
                    break;
            }
             menu_principal();
    }
void menu_servicos()                                                                                                    //Função serviços
    {
            system("cls");
            int escolha_menu;                                                                                             //Limpar ecrã
                    /*Cabeçalho do menu e formatação "gráfica"*/
            printf("|------------------------------------------------------------|\n");
            printf("|                    MENU SERVIÇOS                           |\n");
            printf("|     1-Canais disponíveis                                   |\n");
            printf("|     2-Servicos adicionais                                  |\n");
            printf("|     3-Tarifários do serviço de voz                         |\n");
            printf("|     4-Voltar ao menu principal                             |\n");
            printf("|------------------------------------------------------------|\n");

            scanf("%d", &escolha_menu);                                                          //Leitura e atribuição do valor intrdouzido à variável local escolha_menu
            switch(escolha_menu)                                                                 //Função caso para seleção de menu consoante o valor introduizido
            {
                case 1: menu_canais_disponiveis();                                               //caso o valor introduzido seja '1' -> a função menu_canaisdisponiveis é invocada
                    break;
                case 2: menu_servicos_adicionais();                                              //caso o valor introduzido seja '2' -> a função menu_servicosadicionais é invocada
                    break;
                case 3: menu_tarifarios_servicos_voz();                                            //caso o valor introduzido seja '3' -> a função menu_tarifarioservicovoz é invocada
                    break;
                case 4: menu_principal();                                          //caso o valor introduzido seja '4' -> a função menu_coltaraomenuprincipal é invocada
                    break;
                }
                menu_principal();
    }

void menu_canaisdisponiveis()                                                                         //Função inserir servico
    {
        system("cls");                                                                         //Limpar ecrã
        int i = 0;
        int escolha_menu;
                                                                                               //Inicialização da variável contadora c

            printf("|------------------------------------------------------------|\n");
            printf("|                    CANAIS DISPONIVEIS                      |\n");
            printf("|     1-Canais base, 10 canais                               |\n");
            printf("|     2-Canais extra, 20 canais                              |\n");
            printf("|     3-Canais extra XL, 30 canais                           |\n");
            printf("|     4-Voltar ao menu principal                             |\n");
            printf("|------------------------------------------------------------|");

            scanf("%d", &escolha_menu);                                                   //Leitura e atribuição do valor intrdouzido à variável local escolha_menu
            switch(escolha_menu)                                                          //Função caso para seleção de menu consoante o valor introduizido
            {
                case 1:;
                    int* client = selecionar_cliente();
                    adicionar_canal(client, 10);
                    menu_canais_base();                                               //caso o valor introduzido seja '1' -> a função menu_canaisbase é invocada
                    break;
                case 2: menu_canais_extra();
                        client = selecionar_cliente();
                    adicionar_canal(client, 20);                                             //caso o valor introduzido seja '2' -> a função menu_canaisextra é invocada
                    break;
                case 3: menu_canais_extra_xl();
                        client = selecionar_cliente();
                    adicionar_canal(client, 30);                                            //caso o valor introduzido seja '3' -> a função menu_canaisextraxl é invocada
                    break;
                case 4: menu_principal();                                     //caso o valor introduzido seja '4' -> a função menu_voltaraomenuprincipal é invocada
                    break;
                }
        menu_principal();
    }

void menu_servicos_adicionais()                                                                                                    //Função serviços
    {
            system("cls");
            int escolha_menu;                                                                                             //Limpar ecrã
                    /*Cabeçalho do menu e formatação "gráfica"*/
            printf("|------------------------------------------------------------|\n");
            printf("|                    SERVICOS ADICIONAIS                     |\n");
            printf("|     1-Disney                                               |\n");
            printf("|     2-SporTv                                               |\n");
            printf("|     3-TVCine                                               |\n");
            printf("|     4-Voltar ao menu principal                             |\n");
            printf("|------------------------------------------------------------|\n");

            scanf("%d", &escolha_menu);                                                          //Leitura e atribuição do valor intrdouzido à variável local escolha_menu
            switch(escolha_menu)                                                                 //Função caso para seleção de menu consoante o valor introduizido
            {
                case 1: menu_disney();
                    int* client = selecionar_cliente();
                    adicionar_servico(client, "Disney");                                               //caso o valor introduzido seja '1' -> a função menu_canaisbase é invocada
                    break;                                            //caso o valor introduzido seja '1' -> a função menu_disney é invocada
                case 2: menu_sportv();
                    client = selecionar_cliente();
                    adicionar_servico(client, "SporTv");
                    break;
                case 3: menu_tvcine();
                    client = selecionar_cliente();
                    adicionar_servico(client, "TVCine");                              //caso o valor introduzido seja '3' -> a função menu_tvcine é invocada
                    break;
                case 4: menu_principal();

                    break;
                }
                menu_principal();
    }

void menu_tarifarios_servicos_voz()                                                                                                    //Função serviços
    {
            system("cls");
            int escolha_menu;                                                                                              //Limpar ecrã
                    /*Cabeçalho do menu e formatação "gráfica"*/
            printf("|------------------------------------------------------------|\n");
            printf("|                    SERVICOS DE VOZ                         |\n");
            printf("|     1-Voz 2000 minutos                                     |\n");
            printf("|     2-Voz 5000 minutos                                     |\n");
            printf("|     3-Voz ilimitado                                        |\n");
            printf("|     4-Voltar ao menu principal                             |\n");
            printf("|------------------------------------------------------------|\n");

            scanf("%d", escolha_menu);                                                          //Leitura e atribuição do valor intrdouzido à variável local escolha_menu
            switch(escolha_menu)                                                                 //Função caso para seleção de menu consoante o valor introduizido
            {
                case 1: menu_voz2000m();
                 int* client = selecionar_cliente();
                    adicionar_voz(client, 2000);                                                        //caso o valor introduzido seja '1' -> a função menu_voz1000m é invocada
                    break;
                case 2: menu_voz5000m();
                    client = selecionar_cliente();
                    adicionar_voz(client, 5000);                                                        //caso o valor introduzido seja '2' -> a função menu_voz5000m é invocada
                    break;
                case 3: menu_voz_ilimitado();
                    client = selecionar_cliente();
                    adicionar_voz(client, 9999999999);                                                     //caso o valor introduzido seja '3' -> a função menu_vozilimitado é invocada
                    break;
                case 4: menu_principal();                                            //caso o valor introduzido seja '4' -> a função menu_coltaraomenuprincipal é invocada
                    break;
                }
                menu_principal();
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
            scanf("%d", &escolha_menu);                                                                                 //Leitura e atribuição do valor intrdouzido à variável local escolha_menu
            switch(escolha_menu)                                                                                        //Função caso para seleção de menu consoante o valor introduizido
            {
                case 1: info_cliente();                                                                                 //caso o valor introduzido seja '1' -> a função info_cliente é invocada
                    break;
                case 2: menu_servicos();                                                                              //caso o valor introduzido seja '2' -> a função menu_servicos é invocada
                    break;
                /*case 3: menu_listagens();                                                                               //caso o valor introduzido seja '3' -> a função menu_listagens é invocada
                    break;
                case 4: menu_informacoes();                                                                             //caso o valor introduzido seja '4' -> a função menu_informacoes é invocada
                    break;
                case 5: menu_faturacao();                                                                               //caso o valor introduzido seja '5' -> a função menu_faturacao é invocada
                    break;*/
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
                        printf("Cliente selecionado - %s - Introduza novos dados\n", client[i].nome);
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
        setlocale(LC_ALL,"Portuguese");                                                                                 //Linguagem local para a utilização dos acentos da língua portuguesa
        menu_principal();
        return 0;
}
