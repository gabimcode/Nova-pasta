// bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
void inserirMusica(); // função para inserir músicad
void verLista();      // função para ver a playlist
struct Playlist
{ // struct da playlist para armazenar a música
    char musica[50];
    char artista[40];
    float duracao;
    struct Playlist *prox;
};
struct Playlist *inicio, *fim, *aux;
int main()
{
    setlocale(LC_ALL, "Portuguese"); // para possibilitar o uso de acento, usar a biblioteca locale.h juntamente a essa linha de código
    int escolha, c;                  // definindo variaveis
    do
    {
        printf("||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
        printf("||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
        printf("|||||||||||||||||||||| Player de Música ||||||||||||||||||||||\n"); // titulo
        printf("||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
        printf("||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
        printf("||||| 1 - Inserir músicas em sua playlist personalizada: |||||\n"); // ao seleci-onar a opção 1, possibilita a inserção das músicas
        printf("|||||||||||||||2 - Ver as músicas da playlist: |||||||||||||||\n"); // ao selecionar a op-ção 2, possibilita a verificação das músicas inseridas
        printf("||||||||||||||||||||||||||3 - Sair. ||||||||||||||||||||||||||\n"); // ao selecionar a opção 3, possi-bilita a saída do programa
        printf("||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
        printf("||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
        printf("-----------Escolha uma das opções para prosseguir: -----------\n"); // nesse campo, inserir a opção desejada
        scanf_s("%d", &escolha);                                                    // escaneia o que foi inserido pelo teclado
        while ((c = getchar()) != '\n' && c != EOF)
        { // limpar o buffer do teclado
        }
        switch (escolha)
        { // colocar as opções
        case 1:
            inserirMusica();
            system("Cls");
            printf("\n");
            printf("||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
            printf("||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
            printf("|||||||||||||||||||||| Música Inserida! ||||||||||||||||||||||\n");
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
            printf("\n ---------- Escolha inválida! ----------\n");
            printf("\n");
            system("pause");
            break;
        }
        system("Cls");
    } while (escolha != 3);
    return 0;
}
void inserirMusica()
{ // função usada para inserção de músicas manualmente na lista
    int c;
    struct Playlist *novo = (struct Playlist *)malloc(sizeof(struct Playlist));
    printf("Insira o nome da música neste campo: \n");
    fgets(novo->musica, 49, stdin);
    printf("Insira o cantor/banda dessa música: \n");
    fgets(novo->artista, 39, stdin);
    printf("Qual a duração dessa música? (formato: 0,00)\n"); // formato aceito é utilizando vírgula
    scanf_s("%f", &novo->duracao);
    while ((c = getchar()) != '\n' && c != EOF)
    { // limpar buffer do teclado
    }
    novo->prox = NULL; // ordenação de inserção na playlist
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
        printf("Playlist vazia."); // se o inicio estiver null, a playlist não tem musica
    }
    else
    {
        while (aux != NULL)
        { // enquanto é diferente de null, mostra a playlist
            printf("- Título da música: %s \n", aux->musica);
            printf("- Artista: %s \n", aux->artista);
            printf("- Duração da música: %.2f \n", aux->duracao);
            aux = aux->prox;
            printf("\n\n");
        }
    }
}
