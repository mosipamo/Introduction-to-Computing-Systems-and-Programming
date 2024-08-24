#include <stdio.h>

#define CHAGH "Chagh"
#define BEDOON_TAGHIR "Bedoon Taghir"
#define LAGHAR "Laghar"



int main()
{
    int day = 0, cal = 0, res = 0, meal = 0;  
    printf("Please enter number of days : "); /* get number of days from user*/
    scanf("%d", &day);
    for (int i = 1; i <= day; i++) /* loop to get number of meals by using a number that user gives us*/
    {                              /*e.g -> day = 4 -> you have 4 meals*/
        scanf("%d", &meal);        /* get the meals(numbers)*/
        switch (meal)
        {
        case 1: /* calculate calories*/
            cal += 329;
            break;
        case 2:
            cal += 127;
            break;
        case 3:
            cal += 61;
            break;
        case 4:
            cal += 83;
            break;
        case 5:
            cal += 156;
            break;
        case 6:
            cal += 296;
            break;
        case 7:
            cal += 496;
            break;
        case 8:
            cal += 73;
            break;
        case 9:
            cal += 34;
            break;
        case 10:
            cal += 16;
            break;
        default:
            cal += 0;
            break;
        }
        res = cal - (day * 100); /* calculate result of eating meals and excercise*/
    }
    if (res > 0)
    {
        printf("Chagh");
    }
    else if (res == 0)
    {
        printf("Bedoon Taghir");
    }
    else
    {
        printf("Laghar");
    }
    return 0;
}