#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void tabuleiro(char casas2[3][3], int vez, char jogador1[50], char jogador2[50])
{
    system("clear");
    printf("==================================================== \n");
    printf("               %s VS %s          \n", jogador1, jogador2);
    printf("==================================================== \n \n");

    printf("\t          %c | %c | %c \n", casas2[0][0], casas2[0][1], casas2[0][2]);
    printf("\t          --------- \n");
    printf("\t          %c | %c | %c \n", casas2[1][0], casas2[1][1], casas2[1][2]);
    printf("\t          --------- \n");
    printf("\t          %c | %c | %c \n \n \n", casas2[2][0], casas2[2][1], casas2[2][2]);
    if (vez % 2 == 0)
    {
        printf("É a vez de %s (X): \n", jogador1);
    }
    else
    {
        printf("É a vez de %s (O): \n", jogador2);
    }
}

int main()
{

    char casas[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '8'}};

    char res, jogador1[50], jogador2[50], escolha_final[50];

    int cont_jogadas, l, c, vez = 0, i, j, escolha;

    printf("\nNome do 1º Jogador (X): ==> ");
    scanf("%s", &jogador1);
    printf("\nNome do 2º Jogador (O): ==> ");
    scanf("%s", &jogador2);

    do
    {
        cont_jogadas = 1;
        for (i = 0; i <= 2; i++)
        {
            for (j = 0; j <= 2; j++)
            {
                casas[i][j] = ' ';
            }
        }
        do
        {
            tabuleiro(casas, vez, jogador1, jogador2);

            printf("\n Digite a linha: ==> ");
            scanf("%i", &l);

            printf("\n Digite a coluna: ==> ");
            scanf("%i", &c);

            if (l < 1 || c < 1 || l > 3 || c > 3)
            {
                l = 0;
                c = 0;
            }
            else if (casas[l - 1][c - 1] != ' ')
            {
                l = 0;
                c = 0;
            }
            else
            {
                if (vez % 2 == 0)
                {
                    casas[l - 1][c - 1] = 'X';
                }
                else
                {
                    casas[l - 1][c - 1] = 'O';
                }
                vez++;
                cont_jogadas++;
            }

            // Ganhar em linhas X
            if (casas[0][0] == 'X' && casas[0][1] == 'X' && casas[0][2] == 'X')
            {
                cont_jogadas = 11;
            }
            if (casas[1][0] == 'X' && casas[1][1] == 'X' && casas[1][2] == 'X')
            {
                cont_jogadas = 11;
            }
            if (casas[2][0] == 'X' && casas[2][1] == 'X' && casas[2][2] == 'X')
            {
                cont_jogadas = 11;
            }

            // Ganhar em colunas X
            if (casas[0][0] == 'X' && casas[1][0] == 'X' && casas[2][0] == 'X')
            {
                cont_jogadas = 11;
            }
            if (casas[0][1] == 'X' && casas[1][1] == 'X' && casas[2][1] == 'X')
            {
                cont_jogadas = 11;
            }
            if (casas[0][2] == 'X' && casas[1][2] == 'X' && casas[2][2] == 'X')
            {
                cont_jogadas = 11;
            }

            // Ganhar na diagonal X
            if (casas[0][0] == 'X' && casas[1][1] == 'X' && casas[2][2] == 'X')
            {
                cont_jogadas = 11;
            }
            if (casas[0][2] == 'X' && casas[1][1] == 'X' && casas[2][0] == 'X')
            {
                cont_jogadas = 11;
            }

            // Ganhar em linhas O
            if (casas[0][0] == 'O' && casas[0][1] == 'O' && casas[0][2] == 'O')
            {
                cont_jogadas = 12;
            }
            if (casas[1][0] == 'O' && casas[1][1] == 'O' && casas[1][2] == 'O')
            {
                cont_jogadas = 12;
            }
            if (casas[2][0] == 'O' && casas[2][1] == 'O' && casas[2][2] == 'O')
            {
                cont_jogadas = 12;
            }

            // Ganhar em colunas O
            if (casas[0][0] == 'O' && casas[1][0] == 'O' && casas[2][0] == 'O')
            {
                cont_jogadas = 12;
            }
            if (casas[0][1] == 'O' && casas[1][1] == 'O' && casas[2][1] == 'O')
            {
                cont_jogadas = 12;
            }
            if (casas[0][2] == 'O' && casas[1][2] == 'O' && casas[2][2] == 'O')
            {
                cont_jogadas = 12;
            }

            // Ganhar na diagonal O
            if (casas[0][0] == 'O' && casas[1][1] == 'O' && casas[2][2] == 'O')
            {
                cont_jogadas = 12;
            }
            if (casas[0][2] == 'O' && casas[1][1] == 'O' && casas[2][0] == 'O')
            {
                cont_jogadas = 12;
            }

        } while (cont_jogadas <= 9);
        if (cont_jogadas == 10)
        {
            printf("Jogo Empatado, parabéns pela batalha \n");
        }
        else if (cont_jogadas == 11)
        {
            system("shutdown -c");
            system("clear");
            printf("Vencedor: %s (X) \n", jogador1);
            printf("Parabéns jovem muito forte \n");
        }
        else if (cont_jogadas == 12)
        {
            srand(time(NULL));
            escolha = rand() % 2;
            if (escolha == 0)
            {
                escolha_final[50] = 'desligar';
                system("shutdown --poweroff");
            }
            else
            {
                escolha_final[50] = 'reiniciar';
                system("shutdown -r");
            }

            system("clear");
            printf("Vencedor: %s (O) \n", jogador2);
            printf("Jovem Muito Fraco \n");
            printf("\n ============================================== \n");
            printf("\n O Seu computador vai %s em 1 minuto \n", escolha_final);
            printf("\n Para cancelar joga novamente e ganha \n");
            printf("\n ============================================== \n");
        }
        printf("Deseja jogar Novamente? [S/N] \n");
        scanf("%s", &res);
    } while (res == 'S');
}