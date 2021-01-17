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
    int posisoes_canais[50];                                                                                            //Vetor que irá guardar as posições dos canais
    int posicoes_servicosad[50];                                                                                        //Vetor que irá guardar as posições dos serviços adicionais
    int posicoes_tarifariosvoz[50];                                                                                     //Vetor que irá guardar as posições dos tarifários de voz
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
        for(i = 0; i < database->clients[0].clientes_total; ++i)                                                                        //Inicialização do ciclo 'para' que começa em 0, vai até o numero de clientes introduzidos e incrementa de 1 em 1
            {
                if(fprintf(filepointer, "%s", database->clients[i+1].nome_cliente) == NULL)
                    {
                        printf("falaha ao escrever");
                    }else{database->clients[i+1].nome_cliente[strlen(database->clients[i+1].nome_cliente) - 1] = '\0';}
            }
        for(i = 0; i < database->clients[0].clientes_total; ++i)                                                                        //Inicialização do ciclo 'para' que começa em 0, vai até o numero de clientes introduzidos e incrementa de 1 em 1
            {
                fprintf(filepointer, "%d\n", database->clients[i+1].numero_nif);
            }/*
        for(i = 0; i < database->channel[0].canais_total; ++i)                                                                        //Inicialização do ciclo 'para' que começa em 0, vai até o numero de clientes introduzidos e incrementa de 1 em 1
            {
                fprintf(filepointer, "%s\n", database->channel[i+1].nome_canal);
            }
        for(i = 0; i < database->services[0].servicosad_total; ++i)                                                                        //Inicialização do ciclo 'para' que começa em 0, vai até o numero de clientes introduzidos e incrementa de 1 em 1
            {
                fprintf(filepointer, "%s\n", database->services[i+1].nomeservicoad);
            }
        for(i = 0; i < database->tarifariovoz[0].tarifario_total; ++i)                                                                        //Inicialização do ciclo 'para' que começa em 0, vai até o numero de clientes introduzidos e incrementa de 1 em 1
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
        for(i = 0; i < database->channel[0].canais_total; ++i)                                                                        //Inicialização do ciclo 'para' que começa em 0, vai até o numero de clientes introduzidos e incrementa de 1 em 1
            {
                if(fprintf(filepointer, "%s", database->channel[i+1].nome_canal) == NULL)
                    {
                        printf("falaha ao escrever");
                    }else{database->channel[i+1].nome_canal[strlen(database->channel[i+1].nome_canal) - 1] = '\0';}
            }
        for(i = 0; i < database->channel[0].canais_total; ++i)                                                                        //Inicialização do ciclo 'para' que começa em 0, vai até o numero de clientes introduzidos e incrementa de 1 em 1
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
        for(i = 0; i < database->services[0].servicosad_total; ++i)                                                                        //Inicialização do ciclo 'para' que começa em 0, vai até o numero de clientes introduzidos e incrementa de 1 em 1
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
        for(i = 0; i < database->tarifariovoz[0].tarifario_total; ++i)                                                                        //Inicialização do ciclo 'para' que começa em 0, vai até o numero de clientes introduzidos e incrementa de 1 em 1
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
        for(i = 0; i < database->clients[0].clientes_total; ++i)                                                                        //Inicialização do ciclo 'para' que começa em 0, vai até o numero de clientes introduzidos e incrementa de 1 em 1
            {
                fgets(database->clients[i+1].nome_cliente, 50,  filepointer);
            }
        for(i = 0; i < database->clients[0].clientes_total; ++i)                                                                        //Inicialização do ciclo 'para' que começa em 0, vai até o numero de clientes introduzidos e incrementa de 1 em 1
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
        for(i = 0; i < database->channel[0].canais_total; ++i)                                                                        //Inicialização do ciclo 'para' que começa em 0, vai até o numero de clientes introduzidos e incrementa de 1 em 1
            {
                fgets(database->channel[i+1].nome_canal, 50,  filepointer);
            }
        for(i = 0; i < database->channel[0].canais_total; ++i)                                                                        //Inicialização do ciclo 'para' que começa em 0, vai até o numero de clientes introduzidos e incrementa de 1 em 1
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
        for(i = 0; i < database->services[0].servicosad_total; ++i)                                                                        //Inicialização do ciclo 'para' que começa em 0, vai até o numero de clientes introduzidos e incrementa de 1 em 1
            {
                fgets(database->services[i+1].nomeservicoad, 50,  filepointer);
            }
        fclose(filepointer);
        printf("serviços adicionais\n");
        lertarifarios(database);
}
void lertarifarios(database *database){

    FILE *filepointer;

    filepointer=fopen("databasetarifarios.txt", "r");

    int i = 0;
        fscanf(filepointer, "%d", &database->tarifariovoz[0].tarifario_total);
        printf("tarifários\n");
        for(i = 0; i < database->tarifariovoz[0].tarifario_total; ++i)                                                                        //Inicialização do ciclo 'para' que começa em 0, vai até o numero de clientes introduzidos e incrementa de 1 em 1
            {
                fgets(database->tarifariovoz[i+1].nometarifario, 50,  filepointer);
            }
        fclose(filepointer);

        menu_principal(database);
}

void inserir_tarifariovoz(database *database){
        system("cls");                                                                                                  //Limpar ecrã
        int i = 0;                                                                                                      //Inicialização da variável contadora i
        int quantidade_tarifarios = 0;                                                                                    //Inicialização da que irá guardar a quantidade de clientes a serem adicionados
        printf("Indique a quantidade de tarifários de voz a serem inseridos: ");
        scanf("%d", &quantidade_tarifarios);                                                                              //Leitura da quantidade de clientes introduzida para a variável quantidade_clientes
        fflush(stdin);
        for(i = 0; i < quantidade_tarifarios; ++i)                                                                        //Inicialização do ciclo 'para' que começa em 0, vai até o numero de clientes introduzidos e incrementa de 1 em 1
            {
                printf("Insira o tarifário de voz: ", i+database->tarifariovoz[i].nometarifario+1);
                if(fgets(database->tarifariovoz[i+database->tarifariovoz[0].tarifario_total+1].nometarifario, 50, stdin) == NULL)
                    {
                        printf("Falha a ler input");
                    }/*else
                    {
                        database->tarifariovoz[i+database->tarifariovoz[0].tarifario_total+1].nometarifario[strlen(database->tarifariovoz[i+database->tarifariovoz[0].tarifario_total+1].nometarifario) -1 ] = '\0';
                    }*/
                fflush(stdin);
                system ("cls");                                                                                         //Limpar ecrã
            }
        database->tarifariovoz[0].tarifario_total = quantidade_tarifarios + database->tarifariovoz[0].tarifario_total;
        //printf("%d - Clientes introduzidos com sucesso\n", database->clients[0].numero_client_total);
        system("pause");
        fflush(stdin);
        escrevertarifarios(database);
}
void inserir_canais(database *database){
        system("cls");                                                                                                  //Limpar ecrã
        int i = 0;                                                                                                      //Inicialização da variável contadora i
        int quantidade_canais = 0;                                                                                    //Inicialização da que irá guardar a quantidade de clientes a serem adicionados
        printf("Indique a quantidade de canais a serem inseridos: ");
        scanf("%d", &quantidade_canais);                                                                              //Leitura da quantidade de clientes introduzida para a variável quantidade_clientes
        fflush(stdin);
        for(i = 0; i < quantidade_canais; ++i)                                                                        //Inicialização do ciclo 'para' que começa em 0, vai até o numero de clientes introduzidos e incrementa de 1 em 1
            {
                printf("Insira o nome do %d canal: ", i+database->channel[i].canais_total+1);
                if(fgets(database->channel[i+database->channel[0].canais_total+1].nome_canal, 50, stdin) == NULL)
                    {
                        printf("Falha ao ler input");
                    }//else{database->channel[i+database->channel[0].canais_total+1].nome_canal[strlen(database->channel[i+database->channel[0].canais_total+1].nome_canal) - 1] = '\0';}
                printf("Insira o preço do Canal: ", i+database->channel[i].canais_total+1);
                scanf("\n%f", &database->channel[i+database->channel[0].canais_total+1].preco_canais);                                                       //Leitura do NIF do cliente e guarda no vetor i na posição i
                fflush(stdin);                                                                                       //Limpar ecrã
            }
        database->channel[0].canais_total = quantidade_canais + database->channel[0].canais_total;
        printf("%d - Canais introduzidos com sucesso\n", database->channel[0].canais_total);
        system("pause");
        fflush(stdin);
        escrevercanais(database);
}
void inserir_servicosadicionais(database *database){
        system("cls");                                                                                                  //Limpar ecrã
        int i = 0;                                                                                                      //Inicialização da variável contadora i
        int quantidade_servicosad = 0;                                                                                    //Inicialização da que irá guardar a quantidade de clientes a serem adicionados
        printf("Indique a quantidade de serviços adicionais a serem inseridos: ");
        scanf("%d", &quantidade_servicosad);                                                                              //Leitura da quantidade de clientes introduzida para a variável quantidade_clientes
        fflush(stdin);
        for(i = 0; i < quantidade_servicosad; ++i)                                                                        //Inicialização do ciclo 'para' que começa em 0, vai até o numero de clientes introduzidos e incrementa de 1 em 1
            {
                printf("Insira o serviço adicional: ", i+database->services[i].nomeservicoad+1);
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
        system("cls");                                                                                                  //Limpar ecrã
        int i = 0;                                                                                                      //Inicialização da variável contadora i
        int quantidade_clientes = 0;                                                                                    //Inicialização da que irá guardar a quantidade de clientes a serem adicionados
        printf("Indique a quantidade de clientes a serem inseridos: ");
        scanf("%d", &quantidade_clientes);                                                                              //Leitura da quantidade de clientes introduzida para a variável quantidade_clientes
        fflush(stdin);
        for(i = 0; i < quantidade_clientes; ++i)                                                                        //Inicialização do ciclo 'para' que começa em 0, vai até o numero de clientes introduzidos e incrementa de 1 em 1
            {
                printf("Insira o nome do %d cliente: ", i+database->clients[i].clientes_total+1);
                if(fgets(database->clients[i+database->clients[0].clientes_total+1].nome_cliente, 50, stdin) == NULL)
                    {
                        printf("Falha ao ler input");
                    }//else{database->clients[i+database->clients[0].clientes_total+1].nome_cliente[strlen(database->clients[i+database->clients[0].clientes_total+1].nome_cliente) - 1] = '\0';}
                printf("Insira o NIF do %d cliente: ", i+database->clients[i].clientes_total+1);
                scanf("\n%d", &database->clients[i+database->clients[0].clientes_total+1].numero_nif);                                                       //Leitura do NIF do cliente e guarda no vetor i na posição i
                fflush(stdin);
                system ("cls");                                                                                         //Limpar ecrã
            }
        database->clients[0].clientes_total = quantidade_clientes + database->clients[0].clientes_total;
        //printf("%d - Clientes introduzidos com sucesso\n", database->clients[0].numero_client_total);
        system("pause");
        fflush(stdin);
        escrever(database);
}

void atualizar_cliente(database *database){

    int escolha_cliente;                                                                                            //Variável que irá guardar o cliente a ser atualizado
    int i = 0;                                                                                                      //Variável contadora
    printf("Selecione o cliente que prentende atualizar:\n");
    for (i = 1; i <= database->clients[0].clientes_total ; ++i)                                                                       //ciclo para pesquisar o cliente guardado na variável escolha_cliente
        {
            printf("%d - %s\n", i, database->clients[i].nome_cliente);
        }
    scanf("%d", &escolha_cliente);                                                                                  //Após aparecer a lista dos clientes, leitura do cliente escolhido
    fflush(stdin);
    for(i = 1; i <= database->clients[0].nome_cliente; ++i)                                                                       //Ciclo pra selecionar o cliente contido na variável escolha_ciente
        {
            if(escolha_cliente == i)                                                                                //Condição para selecionar o cliente escolhido
                {
                    printf("Clienten selecionado - %s - Introduza novos dados\n", database->clients[i].nome_cliente);
                    printf("Insira o nome do cliente: ");
                    fgets(database->clients[i].nome_cliente, 50, stdin);                                                        //Introdução dos dados atualizados do cliente
                    printf("Insira o NIF do cliente: ");
                    scanf("%d", &database->clients[i].numero_nif);
                }
        }
    printf("Cliente atualizado com sucesso!\n");
    fflush(stdin);
    system("pause");                                                                                                //Pausa o programa antes que outra instrução seja eclientes_totalecutada
    escrever(database);
}
void atualizar_canais(database *database){

    int escolha_canal;                                                                                            //Variável que irá guardar o cliente a ser atualizado
    int i = 0;                                                                                                      //Variável contadora
    printf("Selecione o canal que prentende atualizar:\n");
    for (i = 1; i <= database->channel[0].canais_total ; ++i)                                                                       //ciclo para pesquisar o cliente guardado na variável escolha_cliente
        {
            printf("%d - %s\n", i, database->channel[i].nome_canal);
        }
    scanf("%d", &escolha_canal);                                                                                  //Após aparecer a lista dos clientes, leitura do cliente escolhido
    fflush(stdin);
    for(i = 1; i <= database->channel[0].nome_canal; ++i)                                                                       //Ciclo pra selecionar o cliente contido na variável escolha_ciente
        {
            if(escolha_canal == i)                                                                                //Condição para selecionar o cliente escolhido
                {
                    printf("Canal selecionado - %s - Introduza novos dados\n", database->channel[i].nome_canal);
                    printf("Insira o nome do canal: ");
                    fgets(database->channel[i].nome_canal, 50, stdin);                                                        //Introdução dos dados atualizados do cliente
                }
        }
    printf("Canal atualizado com sucesso!\n");
    fflush(stdin);
    system("pause");                                                                                                //Pausa o programa antes que outra instrução seja eclientes_totalecutada
    escrevercanais(database);
}
void atualizar_servicosad(database *database){

    int escolha_servicoad;                                                                                            //Variável que irá guardar o cliente a ser atualizado
    int i = 0;                                                                                                      //Variável contadora
    printf("Selecione o Serviço adicional que prentende atualizar:\n");
    for (i = 1; i <= database->services[0].servicosad_total ; ++i)                                                                       //ciclo para pesquisar o cliente guardado na variável escolha_cliente
        {
            printf("%d - %s\n", i, database->services[i].nomeservicoad);
        }
    scanf("%d", &escolha_servicoad);                                                                                  //Após aparecer a lista dos clientes, leitura do cliente escolhido
    fflush(stdin);
    for(i = 1; i <= database->services[0].servicosad_total; ++i)                                                                       //Ciclo pra selecionar o cliente contido na variável escolha_ciente
        {
            if(escolha_servicoad == i)                                                                                //Condição para selecionar o cliente escolhido
                {
                    printf("Serviço adicional selecionado - %s - Introduza novos dados\n", database->services[i].nomeservicoad);
                    printf("Insira o novo serviço adicional: ");
                    fgets(database->services[i].nomeservicoad, 50, stdin);                                                        //Introdução dos dados atualizados do cliente
                }
        }
    printf("Serviço adicional atualizado com sucesso!\n");
    fflush(stdin);
    system("pause");                                                                                                //Pausa o programa antes que outra instrução seja eclientes_totalecutada
    escreverservicosad(database);
}
void atualizar_tarifariovoz(database *database){

    int escolha_tarifariovoz;                                                                                            //Variável que irá guardar o cliente a ser atualizado
    int i = 0;                                                                                                      //Variável contadora
    printf("Selecione o Tarifário de Voz que prentende atualizar:\n");
    for (i = 1; i <= database->tarifariovoz[0].tarifario_total ; ++i)                                                                       //ciclo para pesquisar o cliente guardado na variável escolha_cliente
        {
            printf("%d - %s\n", i, database->tarifariovoz[i].nometarifario);
        }
    scanf("%d", &escolha_tarifariovoz);                                                                                  //Após aparecer a lista dos clientes, leitura do cliente escolhido
    fflush(stdin);
    for(i = 1; i <= database->tarifariovoz[0].tarifario_total; ++i)                                                                       //Ciclo pra selecionar o cliente contido na variável escolha_ciente
        {
            if(escolha_tarifariovoz == i)                                                                                //Condição para selecionar o cliente escolhido
                {
                    printf("Tarifário de Voz selecionado - %s - Introduza novos dados\n", database->tarifariovoz[i].nometarifario);
                    printf("Insira o Tarifário de Voz: ");
                    fgets(database->tarifariovoz[i].nometarifario, 50, stdin);                                                        //Introdução dos dados atualizados do cliente
                }
        }
    printf("Tarifário de Voz atualizado com sucesso!\n");
    fflush(stdin);
    system("pause");                                                                                                //Pausa o programa antes que outra instrução seja eclientes_totalecutada
    escrevertarifarios(database);
}

void remover_canais(database *database){

    int escolha_canal;                                                                                            //Variável que irá guardar o cliente a ser atualizado
    int i = 0;
    char confirmacao;                                                                                                    //Variável contadora
    printf("Selecione o canal que prentende remover:\n");
    for (i = 1; i <= database->channel[0].canais_total; ++i)                                                                       //ciclo para pesquisar o cliente guardado na variável escolha_cliente
        {
            printf("%d - %s\n", i, database->channel[i].nome_canal);
        }
    scanf("%d", &escolha_canal);                                                                                  //Após aparecer a lista dos clientes, leitura do cliente escolhido
    fflush(stdin);
    for(i = 0; i <= database->channel[0].canais_total; ++i)                                                                        //Ciclo pra selecionar o cliente contido na variável escolha_ciente
        {
            if(escolha_canal == i)                                                                                //Condição para selecionar o cliente escolhido
                {
                    printf("Canal selecionado - %s\n",database->channel[i].nome_canal);                                           //Mostra o cliente selecionado
                    printf("Tem a certeza que deseja remover o canal - %s do programa ? [s/n]", database->channel[i].nome_canal);  //Mensagem para confirmação do cliente a remover
                    scanf(" %c", &confirmacao);                                                                     //Leitura da confirmação
                    if(confirmacao == 's')                                                                          //Testa se a confirmação é sim ou não
                        {
                            for(i = escolha_canal; i < database->channel[0].canais_total; i++)                                  //Ciclo para selecionar o cliente prentendido
                                {

                                   database->channel[i] = database->channel[i+1];                                               //Descolacamento das variáveis do vetor de forma a reorganizar removendo o cliente pretendido
                                }
                            printf("Canaal removido com sucesso!\n");
                        }else                                                                                       //Caso a confirmação não seja verdadeira (escolha_cliente != 's'), a operação é cancelada
                        {
                            printf("Operação cancelada!\n");
                        }
                                                                                                                        //redução do número total de cilentes presentes no programa
                }
        }
        if(confirmacao == 's')
            {

                database->channel[0].canais_total = database->channel[0].canais_total - 1;
            }
    fflush(stdin);
    system("pause");                                                                                                //Pausa o programa antes que outra instrução seja eclientes_totalecutada
    escrevercanais(database);
}
void remover_cliente(database *database){

    int escolha_cliente;                                                                                            //Variável que irá guardar o cliente a ser atualizado
    int i = 0;
    char confirmacao;                                                                                                    //Variável contadora
    printf("Selecione o cliente que prentende remover:\n");
    for(i = 1; i <= database->clients[0].clientes_total ; ++i)
        {
            printf("\nNome do %d cliente inserido: ", i);
            printf("%s", database->clients[i].nome_cliente);
        }
    scanf("%d", &escolha_cliente);                                                                                  //Após aparecer a lista dos clientes, leitura do cliente escolhido
    fflush(stdin);
    for(i = 0; i <= database->clients[0].clientes_total; ++i)                                                                        //Ciclo pra selecionar o cliente contido na variável escolha_ciente
        {
            if(escolha_cliente == i)                                                                                //Condição para selecionar o cliente escolhido
                {
                    printf("Cliente selecionado - %s\n",database->clients[i].nome_cliente);                                           //Mostra o cliente selecionado
                    printf("Tem a certeza que deseja remover o cliente - %s do programa ? [s/n]", database->clients[i].nome_cliente);  //Mensagem para confirmação do cliente a remover
                    scanf(" %c", &confirmacao);                                                                     //Leitura da confirmação
                    if(confirmacao == 's')                                                                          //Testa se a confirmação é sim ou não
                        {
                            for(i = escolha_cliente; i < database->clients[0].clientes_total; i++)                                  //Ciclo para selecionar o cliente prentendido
                                {

                                   printf("\nquantidade clientes %d\n", database->clients[0].clientes_total);

                                   database->clients[i] = database->clients[i+1];                                               //Descolacamento das variáveis do vetor de forma a reorganizar removendo o cliente pretendido

                                    printf("\nquantidade clientes %d\n", database->clients[0].clientes_total);
                                }
                            printf("Cliente removido com sucesso!\n");
                        }else                                                                                       //Caso a confirmação não seja verdadeira (escolha_cliente != 's'), a operação é cancelada
                        {
                            printf("Operação cancelada!\n");
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
    system("pause");                                                                                                //Pausa o programa antes que outra instrução seja eclientes_totalecutada
    escrever(database);
}
void remover_servicoad(database *database){

    int escolha_cliente;                                                                                            //Variável que irá guardar o cliente a ser atualizado
    int i = 0;
    char confirmacao;                                                                                                    //Variável contadora
    printf("Selecione o serviço adicional que prentende remover:\n");
    for(i = 1; i <= database->services[0].servicosad_total ; ++i)
        {
            printf("\nNome do %d cliente inserido: ", i);
            printf("%s", database->services[i].nomeservicoad);
        }
    scanf("%d", &escolha_cliente);                                                                                  //Após aparecer a lista dos clientes, leitura do cliente escolhido
    fflush(stdin);
    for(i = 0; i <= database->services[0].servicosad_total; ++i)                                                                        //Ciclo pra selecionar o cliente contido na variável escolha_ciente
        {
            if(escolha_cliente == i)                                                                                //Condição para selecionar o cliente escolhido
                {
                    printf("Cliente selecionado - %s\n", database->services[i].nomeservicoad);                                           //Mostra o cliente selecionado
                    printf("Tem a certeza que deseja remover o cliente - %s do programa ? [s/n]", database->services[i].nomeservicoad);  //Mensagem para confirmação do cliente a remover
                    scanf(" %c", &confirmacao);                                                                     //Leitura da confirmação
                    if(confirmacao == 's')                                                                          //Testa se a confirmação é sim ou não
                        {
                            for(i = escolha_cliente; i < database->services[0].servicosad_total; i++)                                  //Ciclo para selecionar o cliente prentendido
                                {
                                   database->services[i] = database->services[i+1];                                               //Descolacamento das variáveis do vetor de forma a reorganizar removendo o cliente pretendido
                                }
                            printf("Serviço adicional removido com sucesso!\n");
                        }else                                                                                       //Caso a confirmação não seja verdadeira (escolha_cliente != 's'), a operação é cancelada
                        {
                            printf("Operação cancelada!\n");
                        }
                }
        }
        if(confirmacao == 's')
            {
                printf("\nquantidade serviços adicionais %d\n", database->services[0].servicosad_total);
                system("pause");
                database->services[0].servicosad_total = database->services[0].servicosad_total - 1;
            }
    fflush(stdin);
    system("pause");                                                                                                //Pausa o programa antes que outra instrução seja eclientes_totalecutada
    escreverservicosad(database);
}
void remover_tarifariodevoz(database *database){

    system("cls");
    int escolha_tarifariovoz;                                                                                            //Variável que irá guardar o cliente a ser atualizado
    int i = 0;
    char confirmacao;                                                                                                    //Variável contadora
    printf("Selecione o Tarifário de voz que prentende remover:\n");
    for(i = 1; i <= database->tarifariovoz[0].tarifario_total ; ++i)
        {
            printf("\n%d - Tarifário inserido: ", i);
            printf("%s", database->tarifariovoz[i].nometarifario);
        }
    scanf("%d", &escolha_tarifariovoz);                                                                                  //Após aparecer a lista dos clientes, leitura do cliente escolhido
    fflush(stdin);
    for(i = 0; i <= database->tarifariovoz[0].tarifario_total; ++i)                                                                        //Ciclo pra selecionar o cliente contido na variável escolha_ciente
        {
            if(escolha_tarifariovoz == i)                                                                                //Condição para selecionar o cliente escolhido
                {
                    printf("Tarifário de Voz selecionado - %s\n", database->tarifariovoz[i].nometarifario);                                           //Mostra o cliente selecionado
                    printf("Tem a certeza que deseja remover o tarifário - %s do programa ? [s/n]", database->tarifariovoz[i].nometarifario);  //Mensagem para confirmação do cliente a remover
                    scanf(" %c", &confirmacao);                                                                     //Leitura da confirmação
                    if(confirmacao == 's')                                                                          //Testa se a confirmação é sim ou não
                        {
                            for(i = escolha_tarifariovoz; i < database->tarifariovoz[0].tarifario_total; i++)                                  //Ciclo para selecionar o cliente prentendido
                                {
                                   database->tarifariovoz[i] = database->tarifariovoz[i+1];                                               //Descolacamento das variáveis do vetor de forma a reorganizar removendo o cliente pretendido
                                }
                            printf("Tarifário de Voz removido com sucesso!\n");
                        }else                                                                                       //Caso a confirmação não seja verdadeira (escolha_cliente != 's'), a operação é cancelada
                        {
                            printf("Operação cancelada!\n");
                        }
                }
        }
        if(confirmacao == 's')
            {
                printf("\nQuantidade Tarifários de Voz %d\n", database->tarifariovoz[0].tarifario_total);
                system("pause");
                database->tarifariovoz[0].tarifario_total = database->tarifariovoz[0].tarifario_total - 1;
            }
    fflush(stdin);
    system("pause");                                                                                                //Pausa o programa antes que outra instrução seja eclientes_totalecutada
    escrevertarifarios(database);
}

void info_cliente(database *database){


    system("cls");                                                                                                  //Limpar ecrã
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
            printf("\Serviços adicionais do %d cliente inserido: ", i);
            printf("%s\n", database->clients[i].servicos_[i].servicosadicionais);*/


        }
                                                                                                  //Pausa o programa antes que outra função seja selecionada
    fflush(stdin);
    printf("Numero de clientes total: %d\n", database->clients[0].clientes_total);
    system("pause");
    menu_principal(database);
}
void info_canais(database *database){

    system("cls");                                                                                                  //Limpar ecrã
    int i = 0;
    printf("Numero de canais total: %d\n", database->channel[0].canais_total);
    for(i = 1; i <= database->channel[0].canais_total; ++i)
        {
            printf("\nNome do %d Canal inserido: %s - Preço: %0.2f\n", i, database->channel[i].nome_canal, database->channel[i].preco_canais);

        }
    system("pause");                                                                                                //Pausa o programa antes que outra função seja selecionada
    fflush(stdin);
    menu_principal(database);
}
void info_servicosad(database *database){

    system("cls");                                                                                                      //Limpar ecrã
    int i = 0;
    printf("Numero de serviços adicionais total: %d\n", database->services[0].servicosad_total);
    for(i = 1; i <= database->services[0].servicosad_total; ++i)
        {
            printf("%d - %s\n", i, database->services[i].nomeservicoad);
        }
    system("pause");                                                                                                    //Pausa o programa antes que outra função seja selecionada
    fflush(stdin);
    menu_principal(database);
}
void info_tarifariosdevoz(database *database){

    system("cls");                                                                                                      //Limpar ecrã
    int i = 0;
    printf("Numero de tarifários de voz total: %d\n", database->tarifariovoz[0].tarifario_total);
    for(i = 1; i <= database->tarifariovoz[0].tarifario_total; ++i)
        {
            printf("%d - %s\n", i, database->tarifariovoz[i].nometarifario);
        }
    system("pause");                                                                                                    //Pausa o programa antes que outra função seja selecionada
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
                        printf("selecione o serviço adicional:\n");
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
                                        printf("Serviço adixional selecionado: %s\n", database->services[i].nomeservicoad);
                                        posicao_servicoad = escolha_servico;
                                    }
                            }
                        database->clients[escolha_cliente].posicoes_servicosad[total_servicosad_selecionados] = posicao_servicoad;
                        printf("pretende adicionar mais serviços adicionais?: ");
                        scanf("%c", &escolha_adicionar_servicosad);
                        fflush(stdin);
                        }while(escolha_adicionar_servicosad == 's');
//                    system("cls");
//                    for(i = 0; i<=total_servicosad_selecionados; i++)
//                        {
//                            printf("Serviços adicionais selecionados: %d %s\n", database->clients[escolha_cliente].posicoes_servicosad[i], database->services[database->clients[escolha_cliente].posicoes_servicosad[i]].nomeservicoad);
//                        }
//                    system("pause");
                    system("cls");
/*----------------------------------------------------------------------------------------------------------------------*/

                    do
                    {
                        system("cls");
                        total_tarifarios_selecionados++;
                        printf("selecione o Tarifário de Voz:\n");
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
                                        printf("Tarifário de Voz selecionado: %s\n", database->tarifariovoz[i].nometarifario);
                                        posicao_tarifariovoz = escolha_tarifario;
                                    }
                            }
                        database->clients[escolha_cliente].posicoes_tarifariosvoz[total_tarifarios_selecionados] = posicao_tarifariovoz;
                        printf("pretende adicionar mais Tarifário de Voz?: ");
                        scanf("%c", &escolha_adicionar_tarifarios);
                        fflush(stdin);
                        }while(escolha_adicionar_tarifarios == 's');
//                    system("cls");
//                    for(i = 0; i<=total_tarifarios_selecionados; i++)
//                        {
//                            printf("Tarifário de Voz: %d %s\n", database->clients[escolha_cliente].posicoes_tarifariosvoz[i], database->tarifariovoz[database->clients[escolha_cliente].posicoes_tarifariosvoz[i]].nometarifario);
//                        }
//                    system("pause");
                    system("cls");
                }//fim do IF

        }
            printf("|-----------------------------------------------------------------------|");
            printf("\n|                    FATURA DOS SERVIÇOS ITCabo, lda                    |\n");
            printf("|-----------------------------------------------------------------------|\n");
            printf("Cliente: %s\n", database->clients[escolha_cliente].nome_cliente);
            printf("Canais associados ao serviço:\n");
            for(i = 1; i<=total_canais_selecionados; i++)
                {
                    printf("Canal TV: %s\n", database->channel[database->clients[escolha_cliente].posisoes_canais[i]].nome_canal);
                }
            printf("|-----------------------------------------------------------------------|\n");
            printf("Serviços Adicionais associados ao serviço:\n");
            for(i = 1; i<=total_servicosad_selecionados; i++)
                {
                    printf("Serviços adicionais: %s\n", database->services[database->clients[escolha_cliente].posicoes_servicosad[i]].nomeservicoad);
                }
            printf("|-----------------------------------------------------------------------|\n");
            printf("Tarifários de Voz associados ao serviço:\n");
            for(i = 1; i<=total_tarifarios_selecionados; i++)
                {
                    printf("Tarifário de Voz: %s\n", database->tarifariovoz[database->clients[escolha_cliente].posicoes_tarifariosvoz[i]].nometarifario);
                }
            printf("|-----------------------------------------------------------------------|");
            system("pause");
}

void menu_listagens(database *database){
    char escolha_menu;
    do{
            system("cls");                                                                                              //Limpar ecrã

            printf("|-----------------------------------------------------------------------|");
            printf("\n|                    MENU LISTAGENS                                     |\n");
            printf("|     1-Lista dos Clientes                                              |\n");
            printf("|     2-Lista de Canais Disponíveis                                     |\n");
            printf("|     3-Lista de Serviços Adicionais                                    |\n");
            printf("|     4-Lista de Tarifários de voz                                      |\n");
            printf("|     5-Clientes ativos e inativos;                                     |\n");
            printf("|     6-Lista de clientes que estão no fim do período de fidelização    |\n");
            printf("|     7-Voltar ao menu principal                                        |\n");
            printf("|-----------------------------------------------------------------------|");
            scanf("%c", &escolha_menu);                                                                                 //Leitura e atribuição do valor intrdouzido à variável local escolha_menu
            fflush(stdin);
            switch(escolha_menu)                                                                                        //Função caso para seleção de menu consoante o valor introduizido
            {
                case '1': info_cliente(database);                                                                                 //caso o valor introduzido seja '1' -> a função info_cliente é invocada
                    break;
                case '2': info_canais(database);                                                                              //caso o valor introduzido seja '2' -> a função menu_servicos é invocada
//                    break;
                case '3': info_servicosad(database);                                                                                  //caso o valor introduzido seja '3' -> a função info_canais é invocada
                      break;
                case '4': info_tarifariosdevoz(database);                                                                             //caso o valor introduzido seja '4' -> a função menu_informacoes é invocada
                    break;
//                case 5: menu_faturacao();                                                                               //caso o valor introduzido seja '5' -> a função menu_faturacao é invocada
//                    break;
                        default:
                    //CorDoTeclientes_totalto(252);                                                                                            //definir a cor de vermelho
                    printf("Valor introduzido inválido! Insira novamente.\n\n");
                    system("pause");
                    break;
            }
    }while(escolha_menu !='0');

}
void menu_clientes(database *database){

    char escolha_menu;
    do {

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
                case '1': inserir_clientes(database);                                                                              //caso o valor introduzido seja '1' -> a função inserir_cliente é invocada
                    break;
                case '2': atualizar_cliente(database);                                                                            //caso o valor introduzido seja '2' -> a função atualizar_cliente é invocada
                    break;
                case '3': remover_cliente(database);                                                                              //caso o valor introduzido seja '3' -> a função remover_cliente é invocada
                   break;
                case '4': menu_principal(database);                                                                               //caso o valor introduzido seja '4' -> a função menu_principal é invocada
                    break;
                        default:
                    //CorDoTeclientes_totalto(252);                                                                                            //definir a cor de vermelho
                    printf("Valor introduzido inválido! Insira novamente.\n\n");
                    system("pause");
                    break;
            }
    }while(escolha_menu !='0');

}
void menu_servicos(database *database){

        system("cls");                                                                                              //Limpar ecrã
        char escolha_menu;                                                                                           //variável local para guardar o valor da escolha do menu
        do{

        printf("|------------------------------------------------------------|");
        printf("\n|                    MENU SERVIÇOS                           |\n");
        printf("|     1-Inserir Canais disponíveis                           |\n");
        printf("|     2-Inserir Servicos adicionais                          |\n");
        printf("|     3-Inserir Tarifários do serviço de voz                 |\n");
        printf("|     4-Remover Canais disponíveis                           |\n");
        printf("|     5-Remover Serviços adicionais                          |\n");
        printf("|     6-Remover Tarifários do serviço de voz                 |\n");
        printf("|     7-Atualizar Canais disponíveis                         |\n");
        printf("|     8-Atualizar Serviços disponíveis                       |\n");
        printf("|     9-Atualizar Tarifários disponíveis                     |\n");
        printf("|     10-Voltar ao menu principal                            |\n");
        printf("|------------------------------------------------------------|");
        scanf("%c", &escolha_menu);                                                                                     //Leitura e atribuição do valor intrdouzido à variável local escolha_menu
        switch(escolha_menu)                                                                                            //Função caso para seleção de menu consoante o valor introduizido
        {
            case '1': inserir_canais(database);                                                                         //caso o valor introduzido seja '1' -> a função inserir_cliente é invocada
                break;
            case '2': inserir_servicosadicionais(database);                                                             //caso o valor introduzido seja '2' -> a função atualizar_cliente é invocada
                break;
            case '3': inserir_tarifariovoz(database);                                                                            //caso o valor introduzido seja '3' -> a função remover_cliente é invocada
                break;
            case '4': remover_canais(database);                                                                         //caso o valor introduzido seja '4' -> a função menu_principal é invocada
                break;
            case '5': remover_servicoad(database);                                                                                   //caso o valor introduzido seja '4' -> a função menu_principal é invocada
                break;
            case '6': remover_tarifariodevoz(database);                                                                             //caso o valor introduzido seja '4' -> a função menu_principal é invocada
                break;
            case '7': atualizar_canais(database);                                                                       //caso o valor introduzido seja '4' -> a função menu_principal é invocada
                break;
            case '8': atualizar_servicosad(database);                                                                       //caso o valor introduzido seja '4' -> a função menu_principal é invocada
                break;
            case '9': atualizar_tarifariovoz(database);
                break;
                    default:
                    //CorDoTeclientes_totalto(252);                                                                     //definir a cor de vermelho
                    printf("Valor introduzido inválido! Insira novamente.\n\n");
                    system("pause");
                    break;
            }
        }while(escolha_menu !='0');

}
void menu_principal(database *database){


    char escolha_menu;
    do{


            system("cls");                                                                                                      //Limpar ecrã
            char escolha_menu;                                                                                                   //variável local para guardar o valor da escolha do menu
            printf("|------------------------------------------------------------|");
            printf("\n|                    MENU PRINCIPAL                          |\n");
            printf("|     1-Clientes                                             |\n");
            printf("|     2-Servicos                                             |\n");
            printf("|     3-Listagens                                            |\n");
            printf("|     4-Informação                                           |\n");
            printf("|     5-Faturação                                            |\n");
            printf("|------------------------------------------------------------|\n");

            scanf("%c", &escolha_menu);                                                                                         //Leitura e atribuição do valor intrdouzido à variável local escolha_menu
            fflush(stdin);
            switch(escolha_menu)                                                                                                //Função caso para seleção de menu consoante o valor introduizido
            {
                case '1': menu_clientes(database);                                                                                        //caso o valor introduzido seja '1' -> a função menu_clientes é invocada
                    break;
                case '2': menu_servicos(database);                                                                                        //caso o valor introduzido seja '2' -> a função menu_servicos é invocada
                    break;
                case '3': menu_listagens(database);                                                                                       //caso o valor introduzido seja '3' -> a função menu_listagens é invocada
                    break;
//                case 4: menu_informacoes();                                                                                     //caso o valor introduzido seja '4' -> a função menu_informacoes é invocada
//                break;
                case '5': menu_faturacao(database);                                                                                       //caso o valor introduzido seja '5' -> a função menu_faturacao é invocada
                    break;
                default:
//                    CorDoTeclientes_totalto(252);                                                                                            //definir a cor de vermelho
//                    printf("Valor introduzido inválido! Insira novamente.\n\n");
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
