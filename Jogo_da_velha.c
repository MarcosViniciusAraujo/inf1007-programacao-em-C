#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

void showBoard(char boardGame[5][5])
{
     int i, j;

     for (i = 0; i < 5; i++)
     {
          for (j = 0; j < 5; j++)
          {
               printf("%c", boardGame[i][j]);
          }

          printf("\n");
     }
}

void changeValue(char boardGame[5][5], int pos, char *gameCode)
{
     char symbol;
     //user
     if (gameCode == "user")
          symbol = 'X';
     //CPU
     else if (gameCode == "CPU")
          symbol = 'O';

     switch (pos)
     {
     case 1:
          boardGame[0][0] = symbol;
          break;

     case 2:
          boardGame[0][2] = symbol;
          break;

     case 3:
          boardGame[0][4] = symbol;
          break;

     case 4:
          boardGame[2][0] = symbol;
          break;

     case 5:
          boardGame[2][2] = symbol;
          break;

     case 6:
          boardGame[2][4] = symbol;
          break;

     case 7:
          boardGame[4][0] = symbol;
          break;

     case 8:
          boardGame[4][2] = symbol;
          break;

     case 9:
          boardGame[4][4] = symbol;
          break;

     default:
          break;
     }
}

bool freeSpaces(bool vet[9])
{
     int i;
     int cont = 0;

     for (i = 0; i < 9; i++)
     {
          if (vet[i] == false)
          {
               cont++;
          }
     }

     if (cont < 9)
     {
          return true;
     }

     else
     {
          return false;
     }
}

int getRandomPos(bool usedEsp[9])
{
     int rand_value = rand() % 9;

     while (usedEsp[rand_value] == false)
     {
          rand_value = rand() % 10;
     }

     return rand_value + 1;
}

int main()
{
     int posUser, posCpu;
     bool usedEsp[9] = {true, true, true, true, true, true, true, true, true};

     char boardGame[5][5] = {
         {' ', '|', ' ', '|', ' '},
         {'-', '|', '-', '|', '-'},
         {' ', '|', ' ', '|', ' '},
         {'-', '|', '-', '|', '-'},
         {' ', '|', ' ', '|', ' '}};

     showBoard(boardGame);

     while (freeSpaces(usedEsp) == true)
     {
          printf("Digite o local: ");
          scanf("%d", &posUser);

          usedEsp[posUser - 1] = false;
          changeValue(boardGame, posUser, "");
          showBoard(boardGame);

          //CPU
          posCpu = getRandomPos(usedEsp);
          usedEsp[posCpu - 1] = false;
          changeValue(boardGame, posCpu, "CPU");
          showBoard(boardGame);
     }

     return 0;
}
