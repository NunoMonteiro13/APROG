/*17_01_2021 - 16:40 AM*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>
#include <locale.h>

typedef struct canais {
    char nome_canal[50];
    float preco_canais;
    int canais_total;
}channel;
typedef struct tarifario {
    char nometarifario[50];
    float preco_tarifario;
    int tarifario_total;
}tarifariovoz;
typedef struct servicos {
    char nomeservicoad[50];
    float preco_canal;
    int servicosad_total;
}services;
typedef struct servicos_ {
    int totalcanais;
    int totalservicosad;
    int totaltarifarios;
}servicos_;
typedef struct clientes {
    char nome_cliente[50];
    int numero_nif;
    int clientes_total;
    servicos_ servicos_[10];
    int posisoes_canais[50];                                                                                            //Vetor que ir� guardar as posi��es dos canais
    int posicoes_servicosad[50];                                                                                        //Vetor que ir� guardar as posi��es dos servi�os adicionais
    int posicoes_tarifariosvoz[50];                                                                                     //Vetor que ir� guardar as posi��es dos tarif�rios de voz
}clients;

typedef struct database {
    clients clients[100];
    channel channel[100];
    services services[100];
    tarifariovoz tarifariovoz[100];
}database;
                                    /*Escrever nos ficheiros*/
void escrever(database *database){
    FILE *filepointer;

    filepointer=fopen("database.txt", "w");
    fprintf(filepointer, "%d", database->clients[0].clientes_total);
        int i = 0;
        for(i = 0; i < database->clients[0].clientes_total; ++i)                                                                        //Inicializa��o do ciclo 'para' que come�a em 0, vai at� o numero de clientes introduzidos e incrementa de 1 em 1
            {
                if(fprintf(filepointer, "%s", database->clients[i+1].nome_cliente) == NULL)
                    {
                        printf("falaha ao escrever");
                    }else{database->clients[i+1].nome_cliente[strlen(database->clients[i+1].nome_cliente) - 1] = '\0';}
            }
        for(i = 0; i < database->clients[0].clientes_total; ++i)                                                                        //Inicializa��o do ciclo 'para' que come�a em 0, vai at� o numero de clientes introduzidos e incrementa de 1 em 1
            {
                fprintf(filepointer, "%d\n", database->clients[i+1].numero_nif);
            }/*
        for(i = 0; i < database->channel[0].canais_total; ++i)                                                                        //Inicializa��o do ciclo 'para' que come�a em 0, vai at� o numero de clientes introduzidos e incrementa de 1 em 1
            {
                fprintf(filepointer, "%s\n", database->channel[i+1].nome_canal);
            }
        for(i = 0; i < database->services[0].servicosad_total; ++i)                                                                        //Inicializa��o do ciclo 'para' que come�a em 0, vai at� o numero de clientes introduzidos e incrementa de 1 em 1
            {
                fprintf(filepointer, "%s\n", database->services[i+1].nomeservicoad);
            }
        for(i = 0; i < database->tarifariovoz[0].tarifario_total; ++i)                                                                        //Inicializa��o do ciclo 'para' que come�a em 0, vai at� o numero de clientes introduzidos e incrementa de 1 em 1
            {
                fprintf(filepointer, "%s\n", database->tarifariovoz[i+1].nometarifario);
            }*/

    fclose(filepointer);
    menu_principal(database);
}
void escrevercanais(database *database){
    FILE *filepointer;

    filepointer=fopen("databasecanais.txt", "w");
    fprintf(filepointer, "%d", database->channel[0].canais_total);
        int i = 0;
        for(i = 0; i < database->channel[0].canais_total; ++i)                                                                        //Inicializa��o do ciclo 'para' que come�a em 0, vai at� o numero de clientes introduzidos e incrementa de 1 em 1
            {
                if(fprintf(filepointer, "%s", database->channel[i+1].nome_canal) == NULL)
                    {
                        printf("falaha ao escrever");
                    }else{database->channel[i+1].nome_canal[strlen(database->channel[i+1].nome_canal) - 1] = '\0';}
            }
        for(i = 0; i < database->channel[0].canais_total; ++i)                                                                        //Inicializa��o do ciclo 'para' que come�a em 0, vai at� o numero de clientes introduzidos e incrementa de 1 em 1
            {
                fprintf(filepointer, "%f\n", database->channel[i+1].preco_canais);
            }
    fclose(filepointer);
    menu_principal(database);
}
void escreverservicosad(database *database){
    FILE *filepointer;

    filepointer=fopen("databaseservicosadicionais.txt", "w");
    fprintf(filepointer, "%d", database->services[0].servicosad_total);
        int i = 0;
        for(i = 0; i < database->services[0].servicosad_total; ++i)                                                                        //Inicializa��o do ciclo 'para' que come�a em 0, vai at� o numero de clientes introduzidos e incrementa de 1 em 1
            {
                if(fprintf(filepointer, "%s", database->services[i+1].nomeservicoad) == NULL)
                    {
                        printf("falaha ao escrever");
                    }else{database->services[i+1].nomeservicoad[strlen(database->services[i+1].nomeservicoad) - 1] = '\0';}
            }
    fclose(filepointer);
    menu_principal(database);
}
void escrevertarifarios(database *database){
    FILE *filepointer;

    filepointer=fopen("databasetarifarios.txt", "w");
    fprintf(filepointer, "%d", database->tarifariovoz[0].tarifario_total);
        int i = 0;
        for(i = 0; i < database->tarifariovoz[0].tarifario_total; ++i)                                                                        //Inicializa��o do ciclo 'para' que come�a em 0, vai at� o numero de clientes introduzidos e incrementa de 1 em 1
            {
                if(fprintf(filepointer, "%s", database->tarifariovoz[i+1].nometarifario) == NULL)
                    {
                        printf("falaha ao escrever");
                    }else{database->tarifariovoz[i+1].nometarifario[strlen(database->tarifariovoz[i+1].nometarifario) - 1] = '\0';}
            }
    fclose(filepointer);
    menu_principal(database);
}
                                    /*Ler os ficheiros*/
void ler(database *database){
    FILE *filepointer;
    filepointer=fopen("database.txt", "r");
    int i = 0;
        fscanf(filepointer, "%d", &database->clients[0].clientes_total);
        for(i = 0; i < database->clients[0].clientes_total; ++i)                                                                        //Inicializa��o do ciclo 'para' que come�a em 0, vai at� o numero de clientes introduzidos e incrementa de 1 em 1
            {
                fgets(database->clients[i+1].nome_cliente, 50,  filepointer);
            }
        for(i = 0; i < database->clients[0].clientes_total; ++i)                                                                        //Inicializa��o do ciclo 'para' que come�a em 0, vai at� o numero de clientes introduzidos e incrementa de 1 em 1
            {
                fscanf(filepointer, "%d", &database->clients[i+1].numero_nif);
            }
        printf("ler\n");
        fclose(filepointer);
        lercanais(database);
}
void lercanais(database *database){
    FILE *filepointer;
    filepointer=fopen("databasecanais.txt", "r");
    int i = 0;
        fscanf(filepointer, "%d", &database->channel[0].canais_total);
        for(i = 0; i < database->channel[0].canais_total; ++i)                                                                        //Inicializa��o do ciclo 'para' que come�a em 0, vai at� o numero de clientes introduzidos e incrementa de 1 em 1
            {
                fgets(database->channel[i+1].nome_canal, 50,  filepointer);
            }
        for(i = 0; i < database->channel[0].canais_total; ++i)                                                                        //Inicializa��o do ciclo 'para' que come�a em 0, vai at� o numero de clientes introduzidos e incrementa de 1 em 1
            {
                fscanf(filepointer, "%f", &database->channel[i+1].preco_canais);
            }
        fclose(filepointer);
        printf("canais\n");
        lerservicosad(database);
}
void lerservicosad(database *database){
    FILE *filepointer;
    filepointer=fopen("databaseservicosadicionais.txt", "r");
    int i = 0;
        fscanf(filepointer, "%d", &database->services[0].servicosad_total);
        for(i = 0; i < database->services[0].servicosad_total; ++i)                                                                        //Inicializa��o do ciclo 'para' que come�a em 0, vai at� o numero de clientes introduzidos e incrementa de 1 em 1
            {
                fgets(database->services[i+1].nomeservicoad, 50,  filepointer);
            }
        fclose(filepointer);
        printf("servi�os adicionais\n");
        lertarifarios(database);
}
void lertarifarios(database *database){

    FILE *filepointer;

    filepointer=fopen("databasetarifarios.txt", "r");

    int i = 0;
        fscanf(filepointer, "%d", &database->tarifariovoz[0].tarifario_total);
        printf("tarif�rios\n");
        for(i = 0; i < database->tarifariovoz[0].tarifario_total; ++i)                                                                        //Inicializa��o do ciclo 'para' que come�a em 0, vai at� o numero de clientes introduzidos e incrementa de 1 em 1
            {
                fgets(database->tarifariovoz[i+1].nometarifario, 50,  filepointer);
            }
        fclose(filepointer);

        menu_principal(database);
}

void inserir_tarifariovoz(database *database){
        system("cls");                                                                                                  //Limpar ecr�
        int i = 0;                                                                                                      //Inicializa��o da vari�vel contadora i
        int quantidade_tarifarios = 0;                                                                                    //Inicializa��o da que ir� guardar a quantidade de clientes a serem adicionados
        printf("Indique a quantidade de tarif�rios de voz a serem inseridos: ");
        scanf("%d", &quantidade_tarifarios);                                                                              //Leitura da quantidade de clientes introduzida para a vari�vel quantidade_clientes
        fflush(stdin);
        for(i = 0; i < quantidade_tarifarios; ++i)                                                                        //Inicializa��o do ciclo 'para' que come�a em 0, vai at� o numero de clientes introduzidos e incrementa de 1 em 1
            {
                printf("Insira o tarif�rio de voz: ", i+database->tarifariovoz[i].nometarifario+1);
                if(fgets(database->tarifariovoz[i+database->tarifariovoz[0].tarifario_total+1].nometarifario, 50, stdin) == NULL)
                    {
                        printf("Falha a ler input");
                    }/*else
                    {
                        database->tarifariovoz[i+database->tarifariovoz[0].tarifario_total+1].nometarifario[strlen(database->tarifariovoz[i+database->tarifariovoz[0].tarifario_total+1].nometarifario) -1 ] = '\0';
                    }*/
                fflush(stdin);
                system ("cls");                                                                                         //Limpar ecr�
            }
        database->tarifariovoz[0].tarifario_total = quantidade_tarifarios + database->tarifariovoz[0].tarifario_total;
        //printf("%d - Clientes introduzidos com sucesso\n", database->clients[0].numero_client_total);
        system("pause");
        fflush(stdin);
        escrevertarifarios(database);
}
void inserir_canais(database *database){
        system("cls");                                                                                                  //Limpar ecr�
        int i = 0;                                                                                                      //Inicializa��o da vari�vel contadora i
        int quantidade_canais = 0;                                                                                    //Inicializa��o da que ir� guardar a quantidade de clientes a serem adicionados
        printf("Indique a quantidade de canais a serem inseridos: ");
        scanf("%d", &quantidade_canais);                                                                              //Leitura da quantidade de clientes introduzida para a vari�vel quantidade_clientes
        fflush(stdin);
        for(i = 0; i < quantidade_canais; ++i)                                                                        //Inicializa��o do ciclo 'para' que come�a em 0, vai at� o numero de clientes introduzidos e incrementa de 1 em 1
            {
                printf("Insira o nome do %d canal: ", i+database->channel[i].canais_total+1);
                if(fgets(database->channel[i+database->channel[0].canais_total+1].nome_canal, 50, stdin) == NULL)
                    {
                        printf("Falha ao ler input");
                    }//else{database->channel[i+database->channel[0].canais_total+1].nome_canal[strlen(database->channel[i+database->channel[0].canais_total+1].nome_canal) - 1] = '\0';}
                printf("Insira o pre�o do Canal: ", i+database->channel[i].canais_total+1);
                scanf("\n%f", &database->channel[i+database->channel[0].canais_total+1].preco_canais);                                                       //Leitura do NIF do cliente e guarda no vetor i na posi��o i
                fflush(stdin);                                                                                       //Limpar ecr�
            }
        database->channel[0].canais_total = quantidade_canais + database->channel[0].canais_total;
        printf("%d - Canais introduzidos com sucesso\n", database->channel[0].canais_total);
        system("pause");
        fflush(stdin);
        escrevercanais(database);
}
void inserir_servicosadicionais(database *database){
        system("cls");                                                                                                  //Limpar ecr�
        int i = 0;                                                                                                      //Inicializa��o da vari�vel contadora i
        int quantidade_servicosad = 0;                                                                                    //Inicializa��o da que ir� guardar a quantidade de clientes a serem adicionados
        printf("Indique a quantidade de servi�os adicionais a serem inseridos: ");
        scanf("%d", &quantidade_servicosad);                                                                              //Leitura da quantidade de clientes introduzida para a vari�vel quantidade_clientes
        fflush(stdin);
        for(i = 0; i < quantidade_servicosad; ++i)                                                                        //Inicializa��o do ciclo 'para' que come�a em 0, vai at� o numero de clientes introduzidos e incrementa de 1 em 1
            {
                printf("Insira o servi�o adicional: ", i+database->services[i].nomeservicoad+1);
                if(fgets(database->services[i+database->services[0].servicosad_total+1].nomeservicoad, 50, stdin) == NULL)
                    {
                        printf("Falha ao ler input");
                    }//else{database->services[i+database->services[0].servicosad_total+1].nomeservicoad[strlen(database->services[i+database->services[0].servicosad_total+1].nomeservicoad) -1] = '\0';}
                fflush(stdin);
                system ("cls");
            }
        database->services[0].servicosad_total = quantidade_servicosad + database->services[0].servicosad_total;
        system("pause");
        fflush(stdin);
        escreverservicosad(database);
}
void inserir_clientes(database *database){
        system("cls");                                                                                                  //Limpar ecr�
        int i = 0;                                                                                                      //Inicializa��o da vari�vel contadora i
        int quantidade_clientes = 0;                                                                                    //Inicializa��o da que ir� guardar a quantidade de clientes a serem adicionados
        printf("Indique a quantidade de clientes a serem inseridos: ");
        scanf("%d", &quantidade_clientes);                                                                              //Leitura da quantidade de clientes introduzida para a vari�vel quantidade_clientes
        fflush(stdin);
        for(i = 0; i < quantidade_clientes; ++i)                                                                        //Inicializa��o do ciclo 'para' que come�a em 0, vai at� o numero de clientes introduzidos e incrementa de 1 em 1
            {
                printf("Insira o nome do %d cliente: ", i+database->clients[i].clientes_total+1);
                if(fgets(database->clients[i+database->clients[0].clientes_total+1].nome_cliente, 50, stdin) == NULL)
                    {
                        printf("Falha ao ler input");
                    }//else{database->clients[i+database->clients[0].clientes_total+1].nome_cliente[strlen(database->clients[i+database->clients[0].clientes_total+1].nome_cliente) - 1] = '\0';}
                printf("Insira o NIF do %d cliente: ", i+database->clients[i].clientes_total+1);
                scanf("\n%d", &database->clients[i+database->clients[0].clientes_total+1].numero_nif);                                                       //Leitura do NIF do cliente e guarda no vetor i na posi��o i
                fflush(stdin);
                system ("cls");                                                                                         //Limpar ecr�
            }
        database->clients[0].clientes_total = quantidade_clientes + database->clients[0].clientes_total;
        //printf("%d - Clientes introduzidos com sucesso\n", database->clients[0].numero_client_total);
        system("pause");
        fflush(stdin);
        escrever(database);
}

void atualizar_cliente(database *database){

    int escolha_cliente;                                                                                            //Vari�vel que ir� guardar o cliente a ser atualizado
    int i = 0;                                                                                                      //Vari�vel contadora
    printf("Selecione o cliente que prentende atualizar:\n");
    for (i = 1; i <= database->clients[0].clientes_total ; ++i)                                                                       //ciclo para pesquisar o cliente guardado na vari�vel escolha_cliente
        {
            printf("%d - %s\n", i, database->clients[i].nome_cliente);
        }
    scanf("%d", &escolha_cliente);                                                                                  //Ap�s aparecer a lista dos clientes, leitura do cliente escolhido
    fflush(stdin);
    for(i = 1; i <= database->clients[0].nome_cliente; ++i)                                                                       //Ciclo pra selecionar o cliente contido na vari�vel escolha_ciente
        {
            if(escolha_cliente == i)                                                                                //Condi��o para selecionar o cliente escolhido
                {
                    printf("Clienten selecionado - %s - Introduza novos dados\n", database->clients[i].nome_cliente);
                    printf("Insira o nome do cliente: ");
                    fgets(database->clients[i].nome_cliente, 50, stdin);                                                        //Introdu��o dos dados atualizados do cliente
                    printf("Insira o NIF do cliente: ");
                    scanf("%d", &database->clients[i].numero_nif);
                }
        }
    printf("Cliente atualizado com sucesso!\n");
    fflush(stdin);
    system("pause");                                                                                                //Pausa o programa antes que outra instru��o seja eclientes_totalecutada
    escrever(database);
}
void atualizar_canais(database *database){

    int escolha_canal;                                                                                            //Vari�vel que ir� guardar o cliente a ser atualizado
    int i = 0;                                                                                                      //Vari�vel contadora
    printf("Selecione o canal que prentende atualizar:\n");
    for (i = 1; i <= database->channel[0].canais_total ; ++i)                                                                       //ciclo para pesquisar o cliente guardado na vari�vel escolha_cliente
        {
            printf("%d - %s\n", i, database->channel[i].nome_canal);
        }
    scanf("%d", &escolha_canal);                                                                                  //Ap�s aparecer a lista dos clientes, leitura do cliente escolhido
    fflush(stdin);
    for(i = 1; i <= database->channel[0].nome_canal; ++i)                                                                       //Ciclo pra selecionar o cliente contido na vari�vel escolha_ciente
        {
            if(escolha_canal == i)                                                                                //Condi��o para selecionar o cliente escolhido
                {
                    printf("Canal selecionado - %s - Introduza novos dados\n", database->channel[i].nome_canal);
                    printf("Insira o nome do canal: ");
                    fgets(database->channel[i].nome_canal, 50, stdin);                                                        //Introdu��o dos dados atualizados do cliente
                }
        }
    printf("Canal atualizado com sucesso!\n");
    fflush(stdin);
    system("pause");                                                                                                //Pausa o programa antes que outra instru��o seja eclientes_totalecutada
    escrevercanais(database);
}
void atualizar_servicosad(database *database){

    int escolha_servicoad;                                                                                            //Vari�vel que ir� guardar o cliente a ser atualizado
    int i = 0;                                                                                                      //Vari�vel contadora
    printf("Selecione o Servi�o adicional que prentende atualizar:\n");
    for (i = 1; i <= database->services[0].servicosad_total ; ++i)                                                                       //ciclo para pesquisar o cliente guardado na vari�vel escolha_cliente
        {
            printf("%d - %s\n", i, database->services[i].nomeservicoad);
        }
    scanf("%d", &escolha_servicoad);                                                                                  //Ap�s aparecer a lista dos clientes, leitura do cliente escolhido
    fflush(stdin);
    for(i = 1; i <= database->services[0].servicosad_total; ++i)                                                                       //Ciclo pra selecionar o cliente contido na vari�vel escolha_ciente
        {
            if(escolha_servicoad == i)                                                                                //Condi��o para selecionar o cliente escolhido
                {
                    printf("Servi�o adicional selecionado - %s - Introduza novos dados\n", database->services[i].nomeservicoad);
                    printf("Insira o novo servi�o adicional: ");
                    fgets(database->services[i].nomeservicoad, 50, stdin);                                                        //Introdu��o dos dados atualizados do cliente
                }
        }
    printf("Servi�o adicional atualizado com sucesso!\n");
    fflush(stdin);
    system("pause");                                                                                                //Pausa o programa antes que outra instru��o seja eclientes_totalecutada
    escreverservicosad(database);
}
void atualizar_tarifariovoz(database *database){

    int escolha_tarifariovoz;                                                                                            //Vari�vel que ir� guardar o cliente a ser atualizado
    int i = 0;                                                                                                      //Vari�vel contadora
    printf("Selecione o Tarif�rio de Voz que prentende atualizar:\n");
    for (i = 1; i <= database->tarifariovoz[0].tarifario_total ; ++i)                                                                       //ciclo para pesquisar o cliente guardado na vari�vel escolha_cliente
        {
            printf("%d - %s\n", i, database->tarifariovoz[i].nometarifario);
        }
    scanf("%d", &escolha_tarifariovoz);                                                                                  //Ap�s aparecer a lista dos clientes, leitura do cliente escolhido
    fflush(stdin);
    for(i = 1; i <= database->tarifariovoz[0].tarifario_total; ++i)                                                                       //Ciclo pra selecionar o cliente contido na vari�vel escolha_ciente
        {
            if(escolha_tarifariovoz == i)                                                                                //Condi��o para selecionar o cliente escolhido
                {
                    printf("Tarif�rio de Voz selecionado - %s - Introduza novos dados\n", database->tarifariovoz[i].nometarifario);
                    printf("Insira o Tarif�rio de Voz: ");
                    fgets(database->tarifariovoz[i].nometarifario, 50, stdin);                                                        //Introdu��o dos dados atualizados do cliente
                }
        }
    printf("Tarif�rio de Voz atualizado com sucesso!\n");
    fflush(stdin);
    system("pause");                                                                                                //Pausa o programa antes que outra instru��o seja eclientes_totalecutada
    escrevertarifarios(database);
}

void remover_canais(database *database){

    int escolha_canal;                                                                                            //Vari�vel que ir� guardar o cliente a ser atualizado
    int i = 0;
    char confirmacao;                                                                                                    //Vari�vel contadora
    printf("Selecione o canal que prentende remover:\n");
    for (i = 1; i <= database->channel[0].canais_total; ++i)                                                                       //ciclo para pesquisar o cliente guardado na vari�vel escolha_cliente
        {
            printf("%d - %s\n", i, database->channel[i].nome_canal);
        }
    scanf("%d", &escolha_canal);                                                                                  //Ap�s aparecer a lista dos clientes, leitura do cliente escolhido
    fflush(stdin);
    for(i = 0; i <= database->channel[0].canais_total; ++i)                                                                        //Ciclo pra selecionar o cliente contido na vari�vel escolha_ciente
        {
            if(escolha_canal == i)                                                                                //Condi��o para selecionar o cliente escolhido
                {
                    printf("Canal selecionado - %s\n",database->channel[i].nome_canal);                                           //Mostra o cliente selecionado
                    printf("Tem a certeza que deseja remover o canal - %s do programa ? [s/n]", database->channel[i].nome_canal);  //Mensagem para confirma��o do cliente a remover
                    scanf(" %c", &confirmacao);                                                                     //Leitura da confirma��o
                    if(confirmacao == 's')                                                                          //Testa se a confirma��o � sim ou n�o
                        {
                            for(i = escolha_canal; i < database->channel[0].canais_total; i++)                                  //Ciclo para selecionar o cliente prentendido
                                {

                                   database->channel[i] = database->channel[i+1];                                               //Descolacamento das vari�veis do vetor de forma a reorganizar removendo o cliente pretendido
                                }
                            printf("Canaal removido com sucesso!\n");
                        }else                                                                                       //Caso a confirma��o n�o seja verdadeira (escolha_cliente != 's'), a opera��o � cancelada
                        {
                            printf("Opera��o cancelada!\n");
                        }
                                                                                                                        //redu��o do n�mero total de cilentes presentes no programa
                }
        }
        if(confirmacao == 's')
            {

                database->channel[0].canais_total = database->channel[0].canais_total - 1;
            }
    fflush(stdin);
    system("pause");                                                                                                //Pausa o programa antes que outra instru��o seja eclientes_totalecutada
    escrevercanais(database);
}
void remover_cliente(database *database){

    int escolha_cliente;                                                                                            //Vari�vel que ir� guardar o cliente a ser atualizado
    int i = 0;
    char confirmacao;                                                                                                    //Vari�vel contadora
    printf("Selecione o cliente que prentende remover:\n");
    for(i = 1; i <= database->clients[0].clientes_total ; ++i)
        {
            printf("\nNome do %d cliente inserido: ", i);
            printf("%s", database->clients[i].nome_cliente);
        }
    scanf("%d", &escolha_cliente);                                                                                  //Ap�s aparecer a lista dos clientes, leitura do cliente escolhido
    fflush(stdin);
    for(i = 0; i <= database->clients[0].clientes_total; ++i)                                                                        //Ciclo pra selecionar o cliente contido na vari�vel escolha_ciente
        {
            if(escolha_cliente == i)                                                                                //Condi��o para selecionar o cliente escolhido
                {
                    printf("Cliente selecionado - %s\n",database->clients[i].nome_cliente);                                           //Mostra o cliente selecionado
                    printf("Tem a certeza que deseja remover o cliente - %s do programa ? [s/n]", database->clients[i].nome_cliente);  //Mensagem para confirma��o do cliente a remover
                    scanf(" %c", &confirmacao);                                                                     //Leitura da confirma��o
                    if(confirmacao == 's')                                                                          //Testa se a confirma��o � sim ou n�o
                        {
                            for(i = escolha_cliente; i < database->clients[0].clientes_total; i++)                                  //Ciclo para selecionar o cliente prentendido
                                {

                                   printf("\nquantidade clientes %d\n", database->clients[0].clientes_total);

                                   database->clients[i] = database->clients[i+1];                                               //Descolacamento das vari�veis do vetor de forma a reorganizar removendo o cliente pretendido

                                    printf("\nquantidade clientes %d\n", database->clients[0].clientes_total);
                                }
                            printf("Cliente removido com sucesso!\n");
                        }else                                                                                       //Caso a confirma��o n�o seja verdadeira (escolha_cliente != 's'), a opera��o � cancelada
                        {
                            printf("Opera��o cancelada!\n");
                        }
                }
        }
        if(confirmacao == 's')
            {
                printf("\nquantidade clientes %d\n", database->clients[0].clientes_total);
                system("pause");
                database->clients[0].clientes_total = database->clients[0].clientes_total - 1;
            }
    fflush(stdin);
    system("pause");                                                                                                //Pausa o programa antes que outra instru��o seja eclientes_totalecutada
    escrever(database);
}
void remover_servicoad(database *database){

    int escolha_cliente;                                                                                            //Vari�vel que ir� guardar o cliente a ser atualizado
    int i = 0;
    char confirmacao;                                                                                                    //Vari�vel contadora
    printf("Selecione o servi�o adicional que prentende remover:\n");
    for(i = 1; i <= database->services[0].servicosad_total ; ++i)
        {
            printf("\nNome do %d cliente inserido: ", i);
            printf("%s", database->services[i].nomeservicoad);
        }
    scanf("%d", &escolha_cliente);                                                                                  //Ap�s aparecer a lista dos clientes, leitura do cliente escolhido
    fflush(stdin);
    for(i = 0; i <= database->services[0].servicosad_total; ++i)                                                                        //Ciclo pra selecionar o cliente contido na vari�vel escolha_ciente
        {
            if(escolha_cliente == i)                                                                                //Condi��o para selecionar o cliente escolhido
                {
                    printf("Cliente selecionado - %s\n", database->services[i].nomeservicoad);                                           //Mostra o cliente selecionado
                    printf("Tem a certeza que deseja remover o cliente - %s do programa ? [s/n]", database->services[i].nomeservicoad);  //Mensagem para confirma��o do cliente a remover
                    scanf(" %c", &confirmacao);                                                                     //Leitura da confirma��o
                    if(confirmacao == 's')                                                                          //Testa se a confirma��o � sim ou n�o
                        {
                            for(i = escolha_cliente; i < database->services[0].servicosad_total; i++)                                  //Ciclo para selecionar o cliente prentendido
                                {
                                   database->services[i] = database->services[i+1];                                               //Descolacamento das vari�veis do vetor de forma a reorganizar removendo o cliente pretendido
                                }
                            printf("Servi�o adicional removido com sucesso!\n");
                        }else                                                                                       //Caso a confirma��o n�o seja verdadeira (escolha_cliente != 's'), a opera��o � cancelada
                        {
                            printf("Opera��o cancelada!\n");
                        }
                }
        }
        if(confirmacao == 's')
            {
                printf("\nquantidade servi�os adicionais %d\n", database->services[0].servicosad_total);
                system("pause");
                database->services[0].servicosad_total = database->services[0].servicosad_total - 1;
            }
    fflush(stdin);
    system("pause");                                                                                                //Pausa o programa antes que outra instru��o seja eclientes_totalecutada
    escreverservicosad(database);
}
void remover_tarifariodevoz(database *database){

    system("cls");
    int escolha_tarifariovoz;                                                                                            //Vari�vel que ir� guardar o cliente a ser atualizado
    int i = 0;
    char confirmacao;                                                                                                    //Vari�vel contadora
    printf("Selecione o Tarif�rio de voz que prentende remover:\n");
    for(i = 1; i <= database->tarifariovoz[0].tarifario_total ; ++i)
        {
            printf("\n%d - Tarif�rio inserido: ", i);
            printf("%s", database->tarifariovoz[i].nometarifario);
        }
    scanf("%d", &escolha_tarifariovoz);                                                                                  //Ap�s aparecer a lista dos clientes, leitura do cliente escolhido
    fflush(stdin);
    for(i = 0; i <= database->tarifariovoz[0].tarifario_total; ++i)                                                                        //Ciclo pra selecionar o cliente contido na vari�vel escolha_ciente
        {
            if(escolha_tarifariovoz == i)                                                                                //Condi��o para selecionar o cliente escolhido
                {
                    printf("Tarif�rio de Voz selecionado - %s\n", database->tarifariovoz[i].nometarifario);                                           //Mostra o cliente selecionado
                    printf("Tem a certeza que deseja remover o tarif�rio - %s do programa ? [s/n]", database->tarifariovoz[i].nometarifario);  //Mensagem para confirma��o do cliente a remover
                    scanf(" %c", &confirmacao);                                                                     //Leitura da confirma��o
                    if(confirmacao == 's')                                                                          //Testa se a confirma��o � sim ou n�o
                        {
                            for(i = escolha_tarifariovoz; i < database->tarifariovoz[0].tarifario_total; i++)                                  //Ciclo para selecionar o cliente prentendido
                                {
                                   database->tarifariovoz[i] = database->tarifariovoz[i+1];                                               //Descolacamento das vari�veis do vetor de forma a reorganizar removendo o cliente pretendido
                                }
                            printf("Tarif�rio de Voz removido com sucesso!\n");
                        }else                                                                                       //Caso a confirma��o n�o seja verdadeira (escolha_cliente != 's'), a opera��o � cancelada
                        {
                            printf("Opera��o cancelada!\n");
                        }
                }
        }
        if(confirmacao == 's')
            {
                printf("\nQuantidade Tarif�rios de Voz %d\n", database->tarifariovoz[0].tarifario_total);
                system("pause");
                database->tarifariovoz[0].tarifario_total = database->tarifariovoz[0].tarifario_total - 1;
            }
    fflush(stdin);
    system("pause");                                                                                                //Pausa o programa antes que outra instru��o seja eclientes_totalecutada
    escrevertarifarios(database);
}

void info_cliente(database *database){


    system("cls");                                                                                                  //Limpar ecr�
    printf("Numero clientes total: %d\n", database->clients[0].clientes_total);
    int i = 0;
    for(i = 1; i <= database->clients[0].clientes_total ; ++i)
        {
            printf("\nNome do %d cliente inserido: ", i);
            printf("%s", database->clients[i].nome_cliente);
            printf("\nNIF do %d cliente inserido: ", i);
            printf("%d\n", database->clients[i].numero_nif);
           /* printf("\Canal do %d cliente inserido: ", i);
            printf("%s\n", database->clients[i].servicos_[i].canal);
            printf("\Servi�os adicionais do %d cliente inserido: ", i);
            printf("%s\n", database->clients[i].servicos_[i].servicosadicionais);*/


        }
                                                                                                  //Pausa o programa antes que outra fun��o seja selecionada
    fflush(stdin);
    printf("Numero de clientes total: %d\n", database->clients[0].clientes_total);
    system("pause");
    menu_principal(database);
}
void info_canais(database *database){

    system("cls");                                                                                                  //Limpar ecr�
    int i = 0;
    printf("Numero de canais total: %d\n", database->channel[0].canais_total);
    for(i = 1; i <= database->channel[0].canais_total; ++i)
        {
            printf("\nNome do %d Canal inserido: %s - Pre�o: %0.2f\n", i, database->channel[i].nome_canal, database->channel[i].preco_canais);

        }
    system("pause");                                                                                                //Pausa o programa antes que outra fun��o seja selecionada
    fflush(stdin);
    menu_principal(database);
}
void info_servicosad(database *database){

    system("cls");                                                                                                      //Limpar ecr�
    int i = 0;
    printf("Numero de servi�os adicionais total: %d\n", database->services[0].servicosad_total);
    for(i = 1; i <= database->services[0].servicosad_total; ++i)
        {
            printf("%d - %s\n", i, database->services[i].nomeservicoad);
        }
    system("pause");                                                                                                    //Pausa o programa antes que outra fun��o seja selecionada
    fflush(stdin);
    menu_principal(database);
}
void info_tarifariosdevoz(database *database){

    system("cls");                                                                                                      //Limpar ecr�
    int i = 0;
    printf("Numero de tarif�rios de voz total: %d\n", database->tarifariovoz[0].tarifario_total);
    for(i = 1; i <= database->tarifariovoz[0].tarifario_total; ++i)
        {
            printf("%d - %s\n", i, database->tarifariovoz[i].nometarifario);
        }
    system("pause");                                                                                                    //Pausa o programa antes que outra fun��o seja selecionada
    fflush(stdin);
    menu_principal(database);
}

void menu_faturacao(database *database){

    int escolha_cliente;
    int escolha_canal;
    int escolha_servico;
    int escolha_tarifario;

    char escolha_adicionar_canais;
    char escolha_adicionar_servicosad;
    char escolha_adicionar_tarifarios;

    int total_canais_selecionados = 0;
    int total_servicosad_selecionados = 0;
    int total_tarifarios_selecionados = 0;

    int posicao_canal = 0;
    int posicao_servicoad = 0;
    int posicao_tarifariovoz = 0;

    int i = 0;

    for(i = 1; i <= database->clients[0].clientes_total ; ++i)
        {
            printf("\nNome do %d cliente inserido: ", i);
            printf("%s", database->clients[i].nome_cliente);
        }
    scanf("%d", &escolha_cliente);
    fflush(stdin);
    for(i = 0; i<= database->clients[0].clientes_total; i++)
        {
            if(escolha_cliente == i)
                {
                    printf("Cliente selecionado: %s\n", database->clients[i].nome_cliente);
                    do
                    {
                        system("cls");
                        total_canais_selecionados++;
                        printf("selecione o canal:\n");
                        for(i = 1; i <= database->channel[0].canais_total; i++)
                            {
                                printf("%d - %s", i, database->channel[i].nome_canal);
                            }
                        scanf("%d", &escolha_canal);
                        fflush(stdin);
                        for(i = 1; i <= database->channel[0].canais_total; i++)
                            {
                                if(escolha_canal == i)
                                    {
                                        printf("Canal selecionado: %s\n", database->channel[i].nome_canal);
                                        posicao_canal = escolha_canal;
                                    }
                            }
                        database->clients[escolha_cliente].posisoes_canais[total_canais_selecionados] = posicao_canal;
                        printf("pretende adicionar mais canais?: ");
                        scanf("%c", &escolha_adicionar_canais);
                        fflush(stdin);
                        }while(escolha_adicionar_canais == 's');
                    system("cls");
//                    for(i = 0; i<=total_canais_selecionados; i++)
//                        {
//                            printf("Canais selecionados: %d %s\n", database->clients[escolha_cliente].posisoes_canais[i], database->channel[database->clients[escolha_cliente].posisoes_canais[i]].nome_canal);
//                        }
//                    system("pause");
                    system("cls");

/*----------------------------------------------------------------------------------------------------------------------*/

                    do
                    {
                        system("cls");
                        total_servicosad_selecionados++;
                        printf("selecione o servi�o adicional:\n");
                        for(i = 1; i <= database->services[0].servicosad_total; i++)
                            {
                                printf("%d - %s", i, database->services[i].nomeservicoad);
                            }
                        scanf("%d", &escolha_servico);
                        fflush(stdin);
                        for(i = 1; i <= database->services[0].servicosad_total; i++)
                            {
                                if(escolha_servico == i)
                                    {
                                        printf("Servi�o adixional selecionado: %s\n", database->services[i].nomeservicoad);
                                        posicao_servicoad = escolha_servico;
                                    }
                            }
                        database->clients[escolha_cliente].posicoes_servicosad[total_servicosad_selecionados] = posicao_servicoad;
                        printf("pretende adicionar mais servi�os adicionais?: ");
                        scanf("%c", &escolha_adicionar_servicosad);
                        fflush(stdin);
                        }while(escolha_adicionar_servicosad == 's');
//                    system("cls");
//                    for(i = 0; i<=total_servicosad_selecionados; i++)
//                        {
//                            printf("Servi�os adicionais selecionados: %d %s\n", database->clients[escolha_cliente].posicoes_servicosad[i], database->services[database->clients[escolha_cliente].posicoes_servicosad[i]].nomeservicoad);
//                        }
//                    system("pause");
                    system("cls");
/*----------------------------------------------------------------------------------------------------------------------*/

                    do
                    {
                        system("cls");
                        total_tarifarios_selecionados++;
                        printf("selecione o Tarif�rio de Voz:\n");
                        for(i = 1; i <= database->tarifariovoz[0].tarifario_total; i++)
                            {
                                printf("%d - %s", i, database->tarifariovoz[i].nometarifario);
                            }
                        scanf("%d", &escolha_tarifario);
                        fflush(stdin);
                        for(i = 1; i <= database->tarifariovoz[0].tarifario_total; i++)
                            {
                                if(escolha_tarifario == i)
                                    {
                                        printf("Tarif�rio de Voz selecionado: %s\n", database->tarifariovoz[i].nometarifario);
                                        posicao_tarifariovoz = escolha_tarifario;
                                    }
                            }
                        database->clients[escolha_cliente].posicoes_tarifariosvoz[total_tarifarios_selecionados] = posicao_tarifariovoz;
                        printf("pretende adicionar mais Tarif�rio de Voz?: ");
                        scanf("%c", &escolha_adicionar_tarifarios);
                        fflush(stdin);
                        }while(escolha_adicionar_tarifarios == 's');
//                    system("cls");
//                    for(i = 0; i<=total_tarifarios_selecionados; i++)
//                        {
//                            printf("Tarif�rio de Voz: %d %s\n", database->clients[escolha_cliente].posicoes_tarifariosvoz[i], database->tarifariovoz[database->clients[escolha_cliente].posicoes_tarifariosvoz[i]].nometarifario);
//                        }
//                    system("pause");
                    system("cls");
                }//fim do IF

        }
            printf("|-----------------------------------------------------------------------|");
            printf("\n|                    FATURA DOS SERVI�OS ITCabo, lda                    |\n");
            printf("|-----------------------------------------------------------------------|\n");
            printf("Cliente: %s\n", database->clients[escolha_cliente].nome_cliente);
            printf("Canais associados ao servi�o:\n");
            for(i = 1; i<=total_canais_selecionados; i++)
                {
                    printf("Canal TV: %s\n", database->channel[database->clients[escolha_cliente].posisoes_canais[i]].nome_canal);
                }
            printf("|-----------------------------------------------------------------------|\n");
            printf("Servi�os Adicionais associados ao servi�o:\n");
            for(i = 1; i<=total_servicosad_selecionados; i++)
                {
                    printf("Servi�os adicionais: %s\n", database->services[database->clients[escolha_cliente].posicoes_servicosad[i]].nomeservicoad);
                }
            printf("|-----------------------------------------------------------------------|\n");
            printf("Tarif�rios de Voz associados ao servi�o:\n");
            for(i = 1; i<=total_tarifarios_selecionados; i++)
                {
                    printf("Tarif�rio de Voz: %s\n", database->tarifariovoz[database->clients[escolha_cliente].posicoes_tarifariosvoz[i]].nometarifario);
                }
            printf("|-----------------------------------------------------------------------|");
            system("pause");
}

void menu_listagens(database *database){
    char escolha_menu;
    do{
            system("cls");                                                                                              //Limpar ecr�

            printf("|-----------------------------------------------------------------------|");
            printf("\n|                    MENU LISTAGENS                                     |\n");
            printf("|     1-Lista dos Clientes                                              |\n");
            printf("|     2-Lista de Canais Dispon�veis                                     |\n");
            printf("|     3-Lista de Servi�os Adicionais                                    |\n");
            printf("|     4-Lista de Tarif�rios de voz                                      |\n");
            printf("|     5-Clientes ativos e inativos;                                     |\n");
            printf("|     6-Lista de clientes que est�o no fim do per�odo de fideliza��o    |\n");
            printf("|     7-Voltar ao menu principal                                        |\n");
            printf("|-----------------------------------------------------------------------|");
            scanf("%c", &escolha_menu);                                                                                 //Leitura e atribui��o do valor intrdouzido � vari�vel local escolha_menu
            fflush(stdin);
            switch(escolha_menu)                                                                                        //Fun��o caso para sele��o de menu consoante o valor introduizido
            {
                case '1': info_cliente(database);                                                                                 //caso o valor introduzido seja '1' -> a fun��o info_cliente � invocada
                    break;
                case '2': info_canais(database);                                                                              //caso o valor introduzido seja '2' -> a fun��o menu_servicos � invocada
//                    break;
                case '3': info_servicosad(database);                                                                                  //caso o valor introduzido seja '3' -> a fun��o info_canais � invocada
                      break;
                case '4': info_tarifariosdevoz(database);                                                                             //caso o valor introduzido seja '4' -> a fun��o menu_informacoes � invocada
                    break;
//                case 5: menu_faturacao();                                                                               //caso o valor introduzido seja '5' -> a fun��o menu_faturacao � invocada
//                    break;
                        default:
                    //CorDoTeclientes_totalto(252);                                                                                            //definir a cor de vermelho
                    printf("Valor introduzido inv�lido! Insira novamente.\n\n");
                    system("pause");
                    break;
            }
    }while(escolha_menu !='0');

}
void menu_clientes(database *database){

    char escolha_menu;
    do {

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
                case '1': inserir_clientes(database);                                                                              //caso o valor introduzido seja '1' -> a fun��o inserir_cliente � invocada
                    break;
                case '2': atualizar_cliente(database);                                                                            //caso o valor introduzido seja '2' -> a fun��o atualizar_cliente � invocada
                    break;
                case '3': remover_cliente(database);                                                                              //caso o valor introduzido seja '3' -> a fun��o remover_cliente � invocada
                   break;
                case '4': menu_principal(database);                                                                               //caso o valor introduzido seja '4' -> a fun��o menu_principal � invocada
                    break;
                        default:
                    //CorDoTeclientes_totalto(252);                                                                                            //definir a cor de vermelho
                    printf("Valor introduzido inv�lido! Insira novamente.\n\n");
                    system("pause");
                    break;
            }
    }while(escolha_menu !='0');

}
void menu_servicos(database *database){

        system("cls");                                                                                              //Limpar ecr�
        char escolha_menu;                                                                                           //vari�vel local para guardar o valor da escolha do menu
        do{

        printf("|------------------------------------------------------------|");
        printf("\n|                    MENU SERVI�OS                           |\n");
        printf("|     1-Inserir Canais dispon�veis                           |\n");
        printf("|     2-Inserir Servicos adicionais                          |\n");
        printf("|     3-Inserir Tarif�rios do servi�o de voz                 |\n");
        printf("|     4-Remover Canais dispon�veis                           |\n");
        printf("|     5-Remover Servi�os adicionais                          |\n");
        printf("|     6-Remover Tarif�rios do servi�o de voz                 |\n");
        printf("|     7-Atualizar Canais dispon�veis                         |\n");
        printf("|     8-Atualizar Servi�os dispon�veis                       |\n");
        printf("|     9-Atualizar Tarif�rios dispon�veis                     |\n");
        printf("|     10-Voltar ao menu principal                            |\n");
        printf("|------------------------------------------------------------|");
        scanf("%c", &escolha_menu);                                                                                     //Leitura e atribui��o do valor intrdouzido � vari�vel local escolha_menu
        switch(escolha_menu)                                                                                            //Fun��o caso para sele��o de menu consoante o valor introduizido
        {
            case '1': inserir_canais(database);                                                                         //caso o valor introduzido seja '1' -> a fun��o inserir_cliente � invocada
                break;
            case '2': inserir_servicosadicionais(database);                                                             //caso o valor introduzido seja '2' -> a fun��o atualizar_cliente � invocada
                break;
            case '3': inserir_tarifariovoz(database);                                                                            //caso o valor introduzido seja '3' -> a fun��o remover_cliente � invocada
                break;
            case '4': remover_canais(database);                                                                         //caso o valor introduzido seja '4' -> a fun��o menu_principal � invocada
                break;
            case '5': remover_servicoad(database);                                                                                   //caso o valor introduzido seja '4' -> a fun��o menu_principal � invocada
                break;
            case '6': remover_tarifariodevoz(database);                                                                             //caso o valor introduzido seja '4' -> a fun��o menu_principal � invocada
                break;
            case '7': atualizar_canais(database);                                                                       //caso o valor introduzido seja '4' -> a fun��o menu_principal � invocada
                break;
            case '8': atualizar_servicosad(database);                                                                       //caso o valor introduzido seja '4' -> a fun��o menu_principal � invocada
                break;
            case '9': atualizar_tarifariovoz(database);
                break;
                    default:
                    //CorDoTeclientes_totalto(252);                                                                     //definir a cor de vermelho
                    printf("Valor introduzido inv�lido! Insira novamente.\n\n");
                    system("pause");
                    break;
            }
        }while(escolha_menu !='0');

}
void menu_principal(database *database){


    char escolha_menu;
    do{


            system("cls");                                                                                                      //Limpar ecr�
            char escolha_menu;                                                                                                   //vari�vel local para guardar o valor da escolha do menu
            printf("|------------------------------------------------------------|");
            printf("\n|                    MENU PRINCIPAL                          |\n");
            printf("|     1-Clientes                                             |\n");
            printf("|     2-Servicos                                             |\n");
            printf("|     3-Listagens                                            |\n");
            printf("|     4-Informa��o                                           |\n");
            printf("|     5-Fatura��o                                            |\n");
            printf("|------------------------------------------------------------|\n");

            scanf("%c", &escolha_menu);                                                                                         //Leitura e atribui��o do valor intrdouzido � vari�vel local escolha_menu
            fflush(stdin);
            switch(escolha_menu)                                                                                                //Fun��o caso para sele��o de menu consoante o valor introduizido
            {
                case '1': menu_clientes(database);                                                                                        //caso o valor introduzido seja '1' -> a fun��o menu_clientes � invocada
                    break;
                case '2': menu_servicos(database);                                                                                        //caso o valor introduzido seja '2' -> a fun��o menu_servicos � invocada
                    break;
                case '3': menu_listagens(database);                                                                                       //caso o valor introduzido seja '3' -> a fun��o menu_listagens � invocada
                    break;
//                case 4: menu_informacoes();                                                                                     //caso o valor introduzido seja '4' -> a fun��o menu_informacoes � invocada
//                break;
                case '5': menu_faturacao(database);                                                                                       //caso o valor introduzido seja '5' -> a fun��o menu_faturacao � invocada
                    break;
                default:
//                    CorDoTeclientes_totalto(252);                                                                                            //definir a cor de vermelho
//                    printf("Valor introduzido inv�lido! Insira novamente.\n\n");
//                    system("pause");
                    break;
                }

        }while(escolha_menu !='0');
}

void main()
{

    setlocale(LC_ALL,"Portuguese");
    
    database l, *database=&l;
    
    
    ler(database);
    //ler(database);
    //escrever(database);
    //menu_principal(database);

}
