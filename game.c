#include <stdio.h>
#include <stdlib.h>

void gameBoard(char squares[3][3]) {
    system("clear");
    printf("\t %c | %c | %c \n", squares[0][0], squares[0][1], squares[0][2]);
    printf("\t-----------\n");
    printf("\t %c | %c | %c \n", squares[1][0], squares[1][1], squares[1][2]);
    printf("\t-----------\n");
    printf("\t %c | %c | %c \n\n\n", squares[2][0], squares[2][1], squares[2][2]);
}

int main() {
    char boardPosition[3][3] = {
        {'1', '2', '3'},
        {'4', '5', '6'},
        {'7', '8', '9'},
    };
    char playAgain;
    int playCounter, l, c, vez = 0;
    do {
        playCounter = 1;
        for (int i = 0; i <= 2; i++) 
            for (int j = 0; j <= 2; j++)
                boardPosition[i][j] = ' ';
      
        do {
            gameBoard(boardPosition);
            if (vez % 2 == 0) {
                printf("Jogador X\n");
            }
            else {
                printf("Jogador O\n");
            }
            printf("Digite a posição vertical: (em numero, exemplo: 1, 2, 3): ");
            scanf("%i", &l);
            printf("Digite a posição horizontal: (em numero, exemplo: 1, 2, 3): ");
            scanf("%i", &c);
            if (l < 1 || c < 1 || l > 3 || c > 3) {
                l = 0;
                c = 0;
            }
            else if (boardPosition[l - 1][c - 1] != ' ') {
                l = 0;
                c = 0;
            }
            else {
                if (vez % 2 == 0)
                  boardPosition[l - 1][c - 1] = 'X';

                else
                  boardPosition[l - 1][c - 1] = 'O';
              
                vez++;
                playCounter++;
            }
            if (boardPosition[0][0] == 'X' && boardPosition[0][1] == 'X' && boardPosition[0][2] == 'X')
                playCounter = 11;
          
            if (boardPosition[1][0] == 'X' && boardPosition[1][1] == 'X' && boardPosition[1][2] == 'X')
                playCounter = 11;
              
            if (boardPosition[2][0] == 'X' && boardPosition[2][1] == 'X' && boardPosition[2][2] == 'X')
                playCounter = 11;
          
            if (boardPosition[0][0] == 'X' && boardPosition[1][0] == 'X' && boardPosition[2][0] == 'X')
                playCounter = 11;

            if (boardPosition[0][1] == 'X' && boardPosition[1][1] == 'X' && boardPosition[2][1] == 'X')
                playCounter = 11;

            if (boardPosition[0][2] == 'X' && boardPosition[1][2] == 'X' && boardPosition[2][2] == 'X')
                playCounter = 11;

            if (boardPosition[0][0] == 'X' && boardPosition[1][1] == 'X' && boardPosition[2][2] == 'X')
                playCounter = 11;

            if (boardPosition[0][2] == 'X' && boardPosition[1][1] == 'X' && boardPosition[2][0] == 'X')
                playCounter = 11;


            if (boardPosition[0][0] == 'O' && boardPosition[0][1] == 'O' && boardPosition[0][2] == 'O')
                playCounter = 12;

            if (boardPosition[1][0] == 'O' && boardPosition[1][1] == 'O' && boardPosition[1][2] == 'O')
                playCounter = 12;

            if (boardPosition[2][0] == 'O' && boardPosition[2][1] == 'O' && boardPosition[2][2] == 'O')
                playCounter = 12;

            if (boardPosition[0][0] == 'O' && boardPosition[1][0] == 'O' && boardPosition[2][0] == 'O')
                playCounter = 12;

            if (boardPosition[0][1] == 'O' && boardPosition[1][1] == 'O' && boardPosition[2][1] == 'O')
                playCounter = 12;

            if (boardPosition[0][2] == 'O' && boardPosition[1][2] == 'O' && boardPosition[2][2] == 'O')
                playCounter = 12;

            if (boardPosition[0][0] == 'O' && boardPosition[1][1] == 'O' && boardPosition[2][2] == 'O')
                playCounter = 12;

            if (boardPosition[0][2] == 'O' && boardPosition[1][1] == 'O' && boardPosition[2][0] == 'O')
                playCounter = 12;


        } while (playCounter <= 9);
        gameBoard(boardPosition);
        if (playCounter == 10)
            printf("Jogo empatado\n");

        if (playCounter == 11)
            printf("Vencedor jogador X\n");

        if (playCounter == 12)
            printf("Vencedor O\n");

        printf("Deseja jogar novamente?[S-N]");
        scanf("%s", &playAgain);
      
    } while (playAgain == 's');
}
