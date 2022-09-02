// bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
void inserirMusica(); // fun��o para inserir m�sicad
void verLista();      // fun��o para ver a playlist
struct Playlist
{ // struct da playlist para armazenar a m�sica
    char musica[50];
    char artista[40];
    float duracao;
    struct Playlist *prox;
};
struct Playlist *inicio, *fim, *aux;
int main()
{
    setlocale(LC_ALL, "Portuguese"); // para possibilitar o uso de acento, usar a biblioteca locale.h juntamente a essa linha de c�digo
    int escolha, c;                  // definindo variaveis
    do
    {
        printf("||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
        printf("||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
        printf("|||||||||||||||||||||| Player de M�sica ||||||||||||||||||||||\n"); // titulo
        printf("||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
        printf("||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
        printf("||||| 1 - Inserir m�sicas em sua playlist personalizada: |||||\n"); // ao seleci-onar a op��o 1, possibilita a inser��o das m�sicas
        printf("|||||||||||||||2 - Ver as m�sicas da playlist: |||||||||||||||\n"); // ao selecionar a op-��o 2, possibilita a verifica��o das m�sicas inseridas
        printf("||||||||||||||||||||||||||3 - Sair. ||||||||||||||||||||||||||\n"); // ao selecionar a op��o 3, possi-bilita a sa�da do programa
        printf("||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
        printf("||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
        printf("-----------Escolha uma das op��es para prosseguir: -----------\n"); // nesse campo, inserir a op��o desejada
        scanf_s("%d", &escolha);                                                    // escaneia o que foi inserido pelo teclado
        while ((c = getchar()) != '\n' && c != EOF)
        { // limpar o buffer do teclado
        }
        switch (escolha)
        { // colocar as op��es
        case 1:
            inserirMusica();
            system("Cls");
            printf("\n");
            printf("||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
            printf("||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
            printf("|||||||||||||||||||||| M�sica Inserida! ||||||||||||||||||||||\n");
            printf("||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
            printf("||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
            printf("\n");
            system("pause");
            break;
        case 2:
            system("Cls");
            printf("\n");
            printf("||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
            printf("||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
            printf("|||||||||||||||||||||||||| Playlist ||||||||||||||||||||||||||\n");
            printf("||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
            printf("||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
            printf("\n");
            verLista();
            system("pause");
            break;
        case 3:
            system("Cls");
            printf("\n");
            printf("||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
            printf("||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
            printf("||||||||||||||||||||| Programa encerrado |||||||||||||||||||||\n");
            printf("||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
            printf("||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
            printf("\n");
            system("pause");
            break;
        default:
            printf("\n ---------- Escolha inv�lida! ----------\n");
            printf("\n");
            system("pause");
            break;
        }
        system("Cls");
    } while (escolha != 3);
    return 0;
}
void inserirMusica()
{ // fun��o usada para inser��o de m�sicas manualmente na lista
    int c;
    struct Playlist *novo = (struct Playlist *)malloc(sizeof(struct Playlist));
    printf("Insira o nome da m�sica neste campo: \n");
    fgets(novo->musica, 49, stdin);
    printf("Insira o cantor/banda dessa m�sica: \n");
    fgets(novo->artista, 39, stdin);
    printf("Qual a dura��o dessa m�sica? (formato: 0,00)\n"); // formato aceito � utilizando v�rgula
    scanf_s("%f", &novo->duracao);
    while ((c = getchar()) != '\n' && c != EOF)
    { // limpar buffer do teclado
    }
    novo->prox = NULL; // ordena��o de inser��o na playlist
    if (inicio == NULL)
    {
        inicio = fim = novo;
    }
    else
    {
        fim->prox = novo;
        fim = novo;
    }
}
void verLista()
{
    aux = inicio;
    if (inicio == NULL)
    {
        printf("Playlist vazia."); // se o inicio estiver null, a playlist n�o tem musica
    }
    else
    {
        while (aux != NULL)
        { // enquanto � diferente de null, mostra a playlist
            printf("- T�tulo da m�sica: %s \n", aux->musica);
            printf("- Artista: %s \n", aux->artista);
            printf("- Dura��o da m�sica: %.2f \n", aux->duracao);
            aux = aux->prox;
            printf("\n\n");
        }
    }
}
