#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>
#include <locale.h>

typedef struct clientes {
    char nome_cliente[50];
    int nif;
    int numero_nif;
    //int numero_client_total;
    int clientes_total;
}clients;
typedef struct canais {
    char nome_canal[50];
    int canais_total;
}channel;
typedef struct database {
    clients clients[100];
    channel channel[100];
}database;
void carregar(database *database){

    strcpy(database->clients[1].nome_cliente, "lucas");
    strcpy(database->clients[2].nome_cliente, "mateus");
    strcpy(database->clients[3].nome_cliente, "daniel");
    database->clients[1].numero_nif = 1;
    database->clients[2].numero_nif = 2;
    database->clients[3].numero_nif = 3;
    database->clients[0].clientes_total = 3;
    strcpy(database->channel[1].nome_canal, "TVI");
    strcpy(database->channel[2].nome_canal, "Radical");
    strcpy(database->channel[3].nome_canal, "RTP");
    database->channel[0].canais_total = 3;
    menu_principal(database);
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
    menu_principal(database);
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
                            for(i = escolha_cliente; i < database->clients->clientes_total; i++)                                  //Ciclo para selecionar o cliente prentendido
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
    menu_principal(database);
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
    menu_principal(database);
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
    menu_principal(database);
}
void info_cliente(database *database){


    system("cls");                                                                                                  //Limpar ecrã
    //printf("clientes total: %d\n",database->clients[0].numero_client_total);
    int i = 0;
    for(i = 1; i <= database->clients[0].clientes_total ; ++i)
        {
            printf("\nNome do %d cliente inserido: ", i);
            printf("%s", database->clients[i].nome_cliente);
            printf("\nNIF do %d cliente inserido: ", i);
            printf("%d\n", database->clients[i].numero_nif);
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
            printf("\nNome do %d cliente inserido: ", i);
            printf("%s\n\n\n", database->channel[i].nome_canal);
        }
    system("pause");                                                                                                //Pausa o programa antes que outra função seja selecionada
    fflush(stdin);
    menu_principal(database);
}
void menu_listagens(database *database){
    char escolha_menu;
    do{
            system("cls");                                                                                              //Limpar ecrã

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
            fflush(stdin);
            switch(escolha_menu)                                                                                        //Função caso para seleção de menu consoante o valor introduizido
            {
                case '1': info_cliente(database);                                                                                 //caso o valor introduzido seja '1' -> a função info_cliente é invocada
                    break;
//                case 2: menu_servicos();                                                                              //caso o valor introduzido seja '2' -> a função menu_servicos é invocada
//                    break;
                case '3': info_canais(database);                                                                                  //caso o valor introduzido seja '3' -> a função info_canais é invocada
                      break;
//                case 4: menu_informacoes();                                                                             //caso o valor introduzido seja '4' -> a função menu_informacoes é invocada
//                    break;
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
                fgets(database->channel[i+database->channel[0].canais_total+1].nome_canal, 50, stdin);
                system ("cls");                                                                                         //Limpar ecrã
            }
        database->channel[0].canais_total = quantidade_canais + database->channel[0].canais_total;
        printf("%d - Canais introduzidos com sucesso\n", database->channel[0].canais_total);
        system("pause");
        fflush(stdin);
        menu_principal(database);
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
                fgets(database->clients[i+database->clients[0].clientes_total+1].nome_cliente, 50, stdin);
                //fgets(database[i+database[0].clients[i].numero_client_total].clients->nome, 50, stdin);
                //scanf(" %[^\t\n]c", database[i+database->numero_client_total].nome);                                                //Leitura do nome do cliente introduzido com a possibilidade de ler nomes separados por espaços
                printf("Insira o NIF do %d cliente: ", i+database->clients[i].clientes_total+1);
                scanf("%d", &database->clients[i+database->clients[0].clientes_total+1].numero_nif);                                                       //Leitura do NIF do cliente e guarda no vetor i na posição i
                fflush(stdin);
                system ("cls");                                                                                         //Limpar ecrã
            }
        database->clients[0].clientes_total = quantidade_clientes + database->clients[0].clientes_total;
        //printf("%d - Clientes introduzidos com sucesso\n", database->clients[0].numero_client_total);
        system("pause");
        fflush(stdin);
        menu_principal(database);
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
        printf("|     7-Atualizar Serviços disponíveis                       |\n");
        printf("|     7-Atualizar Tarifários disponíveis                     |\n");
        printf("|     7-Voltar ao menu principal                             |\n");
        printf("|------------------------------------------------------------|");
        scanf("%c", &escolha_menu);                                                                                 //Leitura e atribuição do valor intrdouzido à variável local escolha_menu
        switch(escolha_menu)                                                                                        //Função caso para seleção de menu consoante o valor introduizido
        {
            case '1': inserir_canais(database);                                                                               //caso o valor introduzido seja '1' -> a função inserir_cliente é invocada
                break;
//                case 2: atualizar_cliente();                                                                            //caso o valor introduzido seja '2' -> a função atualizar_cliente é invocada
//                    break;
//                case 3: remover_cliente();                                                                              //caso o valor introduzido seja '3' -> a função remover_cliente é invocada
//                    break;
            case '4': remover_canais(database);                                                                               //caso o valor introduzido seja '4' -> a função menu_principal é invocada
                break;
//                case 5: menu_principal();                                                                               //caso o valor introduzido seja '4' -> a função menu_principal é invocada
//                    break;
//                case 6: menu_principal();                                                                               //caso o valor introduzido seja '4' -> a função menu_principal é invocada
//                    break;
            case '7': atualizar_canais(database);                                                                               //caso o valor introduzido seja '4' -> a função menu_principal é invocada
                break;
                    default:
                    //CorDoTeclientes_totalto(252);                                                                                            //definir a cor de vermelho
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
//        case 4: menu_informacoes();                                                                                     //caso o valor introduzido seja '4' -> a função menu_informacoes é invocada
//            break;
//        case 5: menu_faturacao();                                                                                       //caso o valor introduzido seja '5' -> a função menu_faturacao é invocada
//            break;
                default:
                    //CorDoTeclientes_totalto(252);                                                                                            //definir a cor de vermelho
                    printf("Valor introduzido inválido! Insira novamente.\n\n");
                    system("pause");
                    break;
                }

        }while(escolha_menu !='0');
}

void main()
{
    setlocale(LC_ALL,"Portuguese");
    database l, *database=&l;
    carregar(database);
    menu_principal(database);
}
