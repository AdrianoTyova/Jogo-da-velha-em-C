#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void tabuleiro(char casas2[3][3], int vez, char jogador1[50])
{
    system("clear");
    printf("\t %c | %c | %c \n", casas2[0][0], casas2[0][1], casas2[0][2]);
    printf("\t --------- \n");
    printf("\t %c | %c | %c \n", casas2[1][0], casas2[1][1], casas2[1][2]);
    printf("\t --------- \n");
    printf("\t %c | %c | %c \n", casas2[2][0], casas2[2][1], casas2[2][2]);
    if (vez % 2 == 0)
    {
        printf("É a vez de %s (X): \n", jogador1);
    }
}

int main()
{

    char casas[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '8'}};

    char res, jogador1[50];
    int cont_jogadas, l, c, vez = 0, i, j, rl, rc, verificarR;

    printf("Nome do 1º Jogador (X): \n");
    scanf("%s", &jogador1);

    do
    {
        cont_jogadas = 1;

        // Limpar a matriz
        for (i = 0; i <= 2; i++)
        {
            for (j = 0; j <= 2; j++)
            {
                casas[i][j] = ' ';
            }
        }

        do
        {
            // Chamar a função tabuleiro
            tabuleiro(casas, vez, jogador1);

            //
            
            if (vez % 2 == 0)
            {
                // system("shutdown --poweroff");
                printf("Digite a linha: \n");
                scanf("%i", &l);

                printf("Digite a coluna: \n");
                scanf("%i", &c);
            }

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
                    do
                    {
                        srand(time(NULL));
                        rl = rand() % 3;
                        rc = rand() % 3;

                        // Validação para ver o número é valido
                        if (rl < 1 || rc < 1 || rl > 3 || rc > 3)
                        {
                            rl = 0;
                            rc = 0;
                        }

                        // Ver se o múmero já existe
                        else if (casas[rl][rc] != ' ')
                        {
                            rl = 0;
                            rc = 0;
                        }

                        // Inserir o valor na matriz
                        else
                        {
                            casas[rl][rc] = 'O';
                            verificarR = 1;
                        }
                    } while (verificarR == 0);
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
            if (casas[0][2] == 'X' && casas[1][1] == 'X' && casas[2][1] == 'X')
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
            if (casas[0][2] == 'O' && casas[1][1] == 'O' && casas[2][1] == 'O')
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

        // Depois de Terminar o Jogo Ver quem foi vencedor, perdedor ou empate
        if (cont_jogadas == 10)
        {
            printf("Jogo Empatado, parabéns pela batalha \n");
        }
        else if (cont_jogadas == 11)
        {
            printf("Vencedor: %s (X) \n", jogador1);
            printf("Parabéns jovem muito forte \n");
        }
        else if (cont_jogadas == 12)
        {
            printf("Vencedor: Computador (O) \n");
            printf("Jovem muito fraco \n");
        }
        printf("Deseja jogar Novamente? [S/N] \n");
        scanf("%s", &res);
    } while (res == 'S');
}
