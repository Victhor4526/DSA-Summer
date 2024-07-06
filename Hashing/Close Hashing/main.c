#include <stdio.h>
#include <stdlib.h>
#include  "closeHashing.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
    Dictionary D;
    initDict(D);

    AnimalInfo info1 = {{"Blackie", 24}, "Dog", "Cebu", 111111};
    AnimalInfo info2 = {{"Rabi", 20}, "Rabbit", "Manila", 222222};
    AnimalInfo info3 = {{"Whitie", 23}, "Dog", "BGC", 333333};
    AnimalInfo info4 = {{"Brownie", 19}, "Dog", "Makati", 444444};


    insertSortByAge(D, info1);
    insertSortByAge(D, info2);
    insertSortByAge(D, info3);
    insertSortByAge(D, info4);

    deleteInfoByCageNo(D, 444444);

    visualize(D);

	return 0;
}
