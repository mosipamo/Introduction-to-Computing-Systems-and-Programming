#include "stdio.h"

#define FIRST_AREA 1
#define SECOND_AREA 2
#define THIRD_AREA 3
#define FOURTH_AREA 4
#define TRUE 1

int main() {
    // defining variables
    int num_of_office, floor, room, area, num_of_jumps = 0;
    float height;

    scanf("%d", &num_of_office);

    // calculate floor and room
    floor = (num_of_office) / 100;
    room = (num_of_office) % 100;

    // find area
    if (room >= 1 && room <= 4) 
        area = FIRST_AREA;
    else if (room >= 5 && room <= 8)
        area = SECOND_AREA;
    else if (room >= 9 && room <= 12)
        area = THIRD_AREA;
    else if (room >= 13 && room <= 16)
        area = FOURTH_AREA;

    scanf("%f", &height);

    float half_height = height / 2; // half height for next jumps
    int res = (2 * floor) + 1; // the minimum jump height
    float ans = 0.0 + height; // height after first jump
    num_of_jumps++;

    // calculate number of jumps after the first jump
    while (ans <= res) {
        ans += half_height;
        num_of_jumps++;
    }

    printf("%d\n", area);
    printf("%d", num_of_jumps - 1);
}