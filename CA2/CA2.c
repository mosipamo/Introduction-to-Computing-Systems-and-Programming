#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
void printboard() /*safeh aval bazi(zamin bazi)*/
{
    printf("                              p3               ");
    printf("\n");
    printf("      ------------------------------------------------    team1 : 0");
    printf("\n");
    for (int i = 0; i <= 5; i++)
    {
        printf("      |                                              |");
        printf("\n");
    }
    for (int i = 6; i <= 6; i++)
    {
        printf("    p2|                                              |p4");
        printf("\n");
    }
    for (int i = 0; i <= 5; i++)
    {
        printf("      |                                              |");
        printf("\n");
    }
    printf("      ------------------------------------------------    team2 : 0");
    printf("\n");
    printf("                              p1               ");
    printf("\n");
    printf("      ------------------------------------------------");
    printf("\n");
}

void new_printboard(int player[4][11], int typeC, int number, int t, int turn, int team1, int team2)
{ /*safeh bazi jadid shamel cart khodam va taghir dar soorat bazi kardan an*/
    printf("                               p3              ");
    printf("\n");
    printf("       ------------------------------------------------   team1 : %d", team1);
    printf("\n");
    for (int i = 0; i <= 5; i++)
    {
        printf("       |                                             |");
        printf("\n");
    }
    for (int i = 6; i <= 6; i++)
    {
        printf("     p2|                                             |p4");
        printf("\n");
    }
    for (int i = 0; i < 5; i++)
    {
        printf("       |                                             |");
        printf("\n");
    }
    if (typeC == 0) /*chap cart khodam ba shoroot*/
    {
        printf("       |                      %c%d                    |\n", 'A', number + 1);
    }
    else if (typeC == 1)
    {
        printf("       |                      %c%d                    |\n", 'B', number + 1);
    }
    else if (typeC == 2)
    {
        printf("       |                      %c%d                    |\n", 'C', number + 1);
    }
    else if (typeC == 3)
    {
        printf("       |                      %c%d                    |\n", 'D', number + 1);
    }
    printf("      ------------------------------------------------    team2 : %d", team2);
    printf("\n");

    printf("                              p1               ");
    printf("\n");
    printf("      ------------------------------------------------");
    printf("\n");
}

void shuffle_card(int *card)
{
    int i, r, temp;
    for (temp = 0, i = 0; temp < 44; i++, temp++)
        card[temp] = i;
    srand(time(NULL));
    for (i = 43; i > 0; i--)
    {
        r = rand() % i;
        temp = card[i];
        card[i] = card[r];
        card[r] = temp;
    }
}

void showcards(int card[44], int player[4][11], int len, int turn)
{
    int types[11];
    int numbers[11];
    int j;
    printf("symbol"); /*namayesh carthaye khodam*/
    for (j = 0; j < len; j++)
    {
        int card_p = player[turn][j]; /*turn == 0 -> p1*/
        types[j] = card_p / 11;
        numbers[j] = card_p % 11;
        printf("\t");
        if (types[j] == 0)
        {
            printf("|%c|  ", 'A');
        }
        else if (types[j] == 1)
        {
            printf("|%c|  ", 'B');
        }
        else if (types[j] == 2)
        {
            printf("|%c|  ", 'C');
        }
        else if (types[j] == 3)
        {
            printf("|%c|  ", 'D');
        }
        else
        {
            printf("|%c|  ", '-');
        }
    }
    printf("\n\t------------------------------------------------\n");
    printf("number");
    for (j = 0; j < len; j++)
    {
        if (player[turn][j] == 44) /*yani oon cart bazi shodeh*/
        {
            printf("\t|%d|", 0);
        }
        else
        {
            printf("\t|%d|", numbers[j] + 1);
        }
    }
    printf("\n\t------------------------------------------------\n");
    for (j = 0; j < 11; j++)
    {
        printf("\t%d", j);
    }
    printf("\n");
}

void cpu_play_conti(int moves[4], int start_type, int player[4][11], int card[44], int turn, int hokm)
{
    int card_p;
    int index = -1, value = -1;

    for (int i = 0; i < 11; i++)
    {
        card_p = player[turn][i];
        int types = card_p / 11;
        int numbers = card_p % 11;

        if (types == start_type) // عدده
        {
            if (numbers > value)
            {
                index = i;
                value = numbers;
            }
        }
    }

    if (index != -1)
    {
        int selected_card = player[turn][index];
        int types = selected_card / 11;
        int numbers = selected_card % 11;
        if (types == 0)
        {
            printf("%c%d", 'A', value + 1);
        }
        else if (types == 1)
        {
            printf("%c%d", 'B', value + 1);
        }
        else if (types == 2)
        {
            printf("%c%d", 'C', value + 1);
        }
        else if (types == 3)
        {
            printf("%c%d", 'D', value + 1);
        }
        else
            printf("%c", '-');
        printf("\n");
        moves[turn] = player[turn][index];
        player[turn][index] = 44;
        return;
    }

    value = 12;
    for (int i = 0; i < 11; i++)
    {
        card_p = player[turn][i];
        int types = card_p / 11;
        int numbers = card_p % 11;
        if (types == hokm)
        {
            if (numbers < value)
            {
                index = i;
                value = numbers;
            }
        }
    }
    if (index != -1)
    {
        int selected_card = player[turn][index];
        int types = selected_card / 11;
        int numbers = selected_card % 11;
        if (types == 0)
        {
            printf("%c%d", 'A', value + 1);
        }
        else if (types == 1)
        {
            printf("%c%d", 'B', value + 1);
        }
        else if (types == 2)
        {
            printf("%c%d", 'C', value + 1);
        }
        else if (types == 3)
        {
            printf("%c%d", 'D', value + 1);
        }
        printf("\n");
        moves[turn] = player[turn][index];
        player[turn][index] = 44;
        return;
    }

    value = 12;
    for (int i = 0; i < 11; i++)
    {
        card_p = player[turn][i];
        int types = card_p / 11;
        int numbers = card_p % 11;
        if (numbers < value && types != 4)
        {
            index = i;
            value = numbers;
        }
    }

    int selected_card = player[turn][index];
    int types = selected_card / 11;
    int numbers = selected_card % 11;
    if (types == 0)
    {
        printf("%c%d", 'A', value + 1);
    }
    else if (types == 1)
    {
        printf("%c%d", 'B', value + 1);
    }
    else if (types == 2)
    {
        printf("%c%d", 'C', value + 1);
    }
    else if (types == 3)
    {
        printf("%c%d", 'D', value + 1);
    }
    printf("\n");
    moves[turn] = player[turn][index];
    player[turn][index] = 44;
    return;
}

int compare_cards(int moves[4], int start_type, int player[4][11], int hokm)
{
    int winner = 0;
    int maxHokm = -1;
    int HokmIndex = -1;
    for (int i = 0; i < 4; i++) /*yaftan max hokm */
    {
        if (moves[i] / 11 == hokm)
        {
            if (moves[i] % 11 > maxHokm)
            {
                maxHokm = moves[i] % 11;
                HokmIndex = i;
            }
        }
    }
    if (HokmIndex != -1)
    {
        return HokmIndex;
    }
    int maxStart = -1;
    int StartIndex = -1;
    for (int i = 0; i < 4; i++) /*yaftan max cartha be joz hokm*/
    {
        if (moves[i] / 11 == start_type)
        {
            if (moves[i] % 11 > maxStart)
            {
                maxStart = moves[i] % 11;
                StartIndex = i;
            }
        }
    }
    return StartIndex;
}

int cpu_play_start(int moves[4], int turn, int player[4][11], int hokm)
{
    int naHokm = -1;
    int ind = -1;
    for (int i = 0; i < 11; i++) /*yaftan carti k hokm nist(nadare)*/
    {
        int card = player[turn][i];
        if (card != 44 && card / 11 != hokm && card % 11 > naHokm % 11)
        {
            naHokm = card;
            ind = i;
        }
    }
    if (ind != -1)
    {
        int card_p = player[turn][ind];
        int type_p = card_p / 11;
        int number_p = card_p % 11;
        if (type_p == 0)
        {
            printf("%c%d\n", 'A', number_p + 1);
        }
        else if (type_p == 1)
        {
            printf("%c%d\n", 'B', number_p + 1);
        }
        else if (type_p == 2)
        {
            printf("%c%d\n", 'C', number_p + 1);
        }
        else if (type_p == 3)
        {
            printf("%c%d\n", 'D', number_p + 1);
        }
        moves[turn] = player[turn][ind];
        player[turn][ind] = 44;
        return naHokm;
    }

    ind = -1;
    int hm = -1;
    for (int i = 0; i < 11; i++) /*agar hamash hokmeh*/
    {
        int card = player[turn][i];
        if (card != 44 && card > hm)
        {
            hm = card;
            ind = i;
        }
    }
    int card_p2 = player[turn][ind];
    int type_pp = card_p2 / 11;
    int number_pp = card_p2 % 11;
    if (type_pp == 0)
    {
        printf("%c%d\n", 'A', number_pp + 1);
    }
    else if (type_pp == 1)
    {
        printf("%c%d\n", 'B', number_pp + 1);
    }
    else if (type_pp == 2)
    {
        printf("%c%d\n", 'C', number_pp + 1);
    }
    else if (type_pp == 3)
    {
        printf("%c%d\n", 'D', number_pp + 1);
    }
    // printf("%d\n", player[turn][ind]);
    moves[turn] = player[turn][ind];
    player[turn][ind] = 44;
    return hm;
}

int main()
{
    printboard(); // safe bazi
    int card[44];
    shuffle_card(card);                                                                                                                                                      // bor zadan
    int cards[4][11] = {{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11}, {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11}, {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11}, {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11}}; // cards
    int player[4][11];
    int p = 0;
    int i, j;
    for (i = 0; i < 4; i++) /*dadan 5 cart be 4 bazicon*/
    {
        for (j = 0; j < 5; j++)
        {
            player[i][j] = card[p];
            p++;
        }
    }
    showcards(card, player, 5, 0);
    int hokm;
    char c;
    printf("\nEnter Bakhshnameh (Char): ");
    scanf("%c", &c);
    switch (c)
    { /*taeen hokm*/
    case 'A':
        hokm = 0;
        break;
    case 'B':
        hokm = 1;
        break;
    case 'C':
        hokm = 2;
        break;
    case 'D':
        hokm = 3;
        break;
    default:
        break;
    }
    for (int i = 0; i < 4; i++) /*dadan 4 cart be 4 bazicon*/
    {
        for (int j = 5; j < 9; j++)
        {
            player[i][j] = card[p];
            p++;
        }
    }
    for (int i = 0; i < 4; i++) /*dadan 2 cart be 4 bazicon*/
    {
        for (int j = 9; j < 11; j++)
        {
            player[i][j] = card[p];
            p++;
        }
    }
    showcards(card, player, 11, 0); /*namayeh 11 cart man*/
    printf("\nWhich card do you wanna play?");
    int turn = 0;
    int start = 1;
    int team1 = 0;
    int team2 = 0;
    while (1)
    {
        int t;
        int moves[4];
        int start_type = 0;
        for (int i = 0; i < 4; i++)
        {
            if (turn == 0)
            {
                if (start == 1)
                {
                    // code shoro dast
                    scanf("\n%d", &t);
                    int card_p = player[0][t]; /*carthaye man baz oon indexi ke zadam bazi misheh :| */
                    int typeC = card_p / 11;
                    int number = card_p % 11;
                    if (typeC == 0)
                    {
                        printf("%c", 'A');
                    }
                    else if (typeC == 1)
                    {
                        printf("%c", 'B');
                    }
                    else if (typeC == 2)
                    {
                        printf("%c", 'C');
                    }
                    else if (typeC == 3)
                    {
                        printf("%c", 'D');
                    }
                    start_type = typeC;
                    moves[0] = player[0][t];
                    player[0][t] = 44; /*yani cartam bazi shod dige nadarm*/
                    new_printboard(player, typeC, number, t, turn, team1, team2);
                    showcards(card, player, 11, 0);
                    start = 0;
                }
                else
                {
                    // code vasat dast
                    scanf("\n%d", &t);
                    int card_p = player[0][t];
                    moves[0] = card_p;
                    player[0][t] = 44;
                    new_printboard(player, start_type, card_p % 11, t, turn, team1, team2);
                    showcards(card, player, 11, 0);
                }
            }
            else
            {
                if (start == 1)
                {
                    int played_card = cpu_play_start(moves, turn, player, hokm);
                    start_type = played_card / 11;
                    start = 0;
                }
                else
                {
                    cpu_play_conti(moves, start_type, player, card, turn, hokm);
                }
            }
            turn++;
            turn %= 4;
        }
        int winner = compare_cards(moves, start_type, player, hokm);
        int state = 0;
        if (winner == 0 || winner == 2)
            team1++;
        else
            team2++;

        if (team1 == 6)
            state = 1;
        else if (team2 == 6)
            state = 2;
        else
            state = 0;

        if (state == 1)
        {
            printf("Team 1 won!");
            break;
        }
        else if (state == 2)
        {
            printf("Team 2 won!");
            break;
        }
        printf("winner : p%d\n", winner + 1);
        turn = winner;
        start = 1;
    }
    return 0;
}