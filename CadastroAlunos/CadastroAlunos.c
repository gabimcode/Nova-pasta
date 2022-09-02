// sobre o c�digo: fiz no Dev C++ pois meu computador est� muito lento e tem problemas para reconhecer o visual code
// resolvi colocar para inserir manualmente cada RU, nome e email pois estava tendo mais difi-culdade em inserir essas informa��es no pr�prio c�digo
// --------------------------------------------
// bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
void iniciarTabela();         // fun��o de espalhamento.
void inserirEst();            // fun��o usada para inserir um estudante na lista.
void verTabela();             // fun��o usada para mostrar a tabela/lista j� com os estudantes.
int gerarCodigoHash(int nRU); // fun��o para criar um c�digo hash para cada elemento da ta-bela.
#define F 11                  // definindo um valor constante que represente o tamanho da tabela, ou seja, po-de inserir at� 10 estudantes na mesma.
typedef struct
{              // struct armazena os dados
    int ruEst; // usando Est para estudante
    char nome[60];
    char email[100];
} dadosEst;
dadosEst tabelaHash[F];
dadosEst lerdadosEst()
{ // fun��o que l� os dados do estudante e retorna se houve sucesso na inser��o.
    dadosEst Est;
    int c;
    printf("Insira o nome do estudante:\n");
    fgets(Est.nome, 59, stdin);
    printf("\n");
    printf("Insira o RU do estudante:\n"); // inserir os dados necess�rios
    scanf_s("%d", &Est.ruEst);
    scanf_s("%*c");
    printf("\n");
    printf("Insira o email do estudante:\n");
    fgets(Est.email, 119, stdin);
    printf("\n");
    printf("Certo. Os dados foram inseridos com sucesso!\n"); // retornar quando h� sucesso
    printf("\n");
    system("pause");
    return Est;
}
// encontrar um estudante na tabela
dadosEst *encontrar(int nRU)
{
    int indice = gerarCodigoHash(nRU);
    while (tabelaHash[indice].ruEst != -1)
    {
        if (tabelaHash[indice].ruEst == nRU)
        {
            return &tabelaHash[indice];
        }
        else
        {
            indice = gerarCodigoHash(indice + 1);
        }
    }
    return NULL;
}
int main()
{
    setlocale(LC_ALL, "Portuguese"); // para possibilitar o uso de acento, usar a biblioteca loca-le.h juntamente a essa linha de c�digo
    int escolha, nRU, c;             // definindo vari�veis
    dadosEst *Est;
    iniciarTabela(); // inicia a tabela e a seguir, mostra um menu de op��es
    do
    {
        system("cls");
        printf("||||||||||||||||||||||||||||||||||||||||||||\n");
        printf("||||||||||||||||||||||||||||||||||||||||||||\n");
        printf("|||||||||||||| ALUNOS UNINTER ||||||||||||||\n");
        printf("||||||||||||||||||||||||||||||||||||||||||||\n");
        printf("||||||||||||||||||||||||||||||||||||||||||||\n");
        printf("|||||||| 1 - Inserir novo estudante ||||||||\n"); // digitar n�mero 1 para inserir estudante
        printf("|||| 2 - Encontrar um estudante pelo RU ||||\n"); // digitar n�mero 2 para procurar estudante
        printf("|||||| 3 - Listar todos os estudantes ||||||\n"); // digitar n�mero 3 para listar todos os estudantes
        printf("||||||||||||||||| 4 - Sair |||||||||||||||||\n"); // digitar n�mero 4 para sair
        printf("||||||||||||||||||||||||||||||||||||||||||||\n");
        printf("||||||||||||||||||||||||||||||||||||||||||||\n");
        printf("--------- Digite a op��o desejada: ---------\n"); // nesse campo, inserir a op��o dese-jada
        printf("\n");
        scanf_s("%d", &escolha); // escaneia o que foi inserido pelo teclado
        while ((c = getchar()) != '\n' && c != EOF)
        { // limpar o buffer do teclado
        }
        switch (escolha)
        { // colocar as op��es
        case 1:
            system("cls");
            printf("||||||||||||||||||||||||||||||||||||||||||||\n");
            printf("||||||||||||||||||||||||||||||||||||||||||||\n");
            printf("|||||||||||||| INSERIR ALUNO: ||||||||||||||\n");
            printf("||||||||||||||||||||||||||||||||||||||||||||\n");
            printf("||||||||||||||||||||||||||||||||||||||||||||\n");
            printf("\n");
            inserirEst(); // chama a fun��o que insere o estudante.
            break;
        case 2:
            system("cls");
            printf("||||||||||||||||||||||||||||||||||||||||||||\n");
            printf("||||||||||||||||||||||||||||||||||||||||||||\n");
            printf("||||||||||||| BUSCAR ESTUDANTE |||||||||||||\n");
            printf("||||||||||||||||||||||||||||||||||||||||||||\n");
            printf("||||||||||||||||||||||||||||||||||||||||||||\n");
            printf("- Para encontrar o estudante, digite o RU: -\n");
            printf("\n");
            scanf_s("%d", &nRU);
            Est = encontrar(nRU); // chama a fun��o que procura o ru.
            if (Est)
            { // se o estudante estiver cadastrado, ele foi encontrado
                printf("||||||||||||||||||||||||||||||||||||||||||||\n");
                printf("|||||||||| *ESTUDANTE ENCONTRADO* ||||||||||\n");
                printf("||||||||||||||||||||||||||||||||||||||||||||\n");
                printf("\n");
                // mostrar na tela as informa��es do estudante encontrado
                printf("Nome:\t%s", Est->nome);
                printf("RU:\t%d\n", Est->ruEst);
                printf("E-mail:\t%s", Est->email);
                printf("\n");
                system("pause");
            }
            else
            { // se o estudante n�o for encontrado
                printf("||||||||||||||||||||||||||||||||||||||||||||\n");
                printf("|||||||| *ESTUDANTE N�O ENCONTRADO* ||||||||\n"); // mostrar essa men-sagem na tela
                printf("||||||||||||||||||||||||||||||||||||||||||||\n");
                system("pause");
            }
            break;
        case 3:
            verTabela(); // chama a fun��o que v� os estudantes j� cadastrados.
            break;
        case 4:
            system("cls"); // encerra o programa, ou seja, n�o volta mais para o menu.
            printf("||||||||||||||||||||||||||||||||||||||||||||\n");
            printf("||||||| *SA�DA EFETUADA COM SUCESSO* |||||||\n");
            printf("||||||||||||||||||||||||||||||||||||||||||||\n");
            break;
        default: // caso aconte�a algo diferente do previsto no c�digo, apresenta mensagem de erro
            printf("------ Erro, op��o inv�lida! ------\n");
            system("pause");
            break;
        }
    } while (escolha != 4); // volta sempre para o menu at� que o usu�rio digite "4".
    return 0;
}
// fun��o de espalhamento
void iniciarTabela()
{
    int i;
    for (i = 0; i < F; i++)
    {
        tabelaHash[i].ruEst = -1;
    }
}
// fun��o que insere estudante
void inserirEst()
{
    dadosEst est = lerdadosEst();
    int indice = gerarCodigoHash(est.ruEst);
    while (tabelaHash[indice].ruEst != -1)
    {
        indice = gerarCodigoHash(indice + 1);
    }
    tabelaHash[indice] = est;
}
// funcao que lista os estudantes
void verTabela()
{
    system("cls");
    printf("||||||||||||||||||||||||||||||||||||||||||||\n");
    printf("|||||||||||| *MENU DE LISTAGEM* ||||||||||||\n");
    printf("||||||||||||||||||||||||||||||||||||||||||||\n");
    printf("\n");
    int i;
    for (i = 0; i < F; i++)
    {
        if (tabelaHash[i].ruEst != -1)
        {
            printf("Nome: %s\n", tabelaHash[i].nome);
            printf("RU: %d\n", tabelaHash[i].ruEst);
            printf("\n");
            printf("E-mail: %s\n", tabelaHash[i].email);
            printf("---------------------------------------------------");
            printf("\n");
        }
    }
    printf("\n");
    system("pause");
}
// fun��o que cria um c�digo hash para cada cadastro inserido.
int gerarCodigoHash(int numeroRU)
{
    return numeroRU % F;
}
