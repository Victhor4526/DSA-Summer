#include <stdio.h>
#include <stdlib.h>
#include  "openHashing.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
    Dictionary D;
    initDict(D);

    AnimalInfo info1 = {{"Blackie", 24}, "Dog", "Cebu", 111111};
    AnimalInfo info2 = {{"Mengmeng", 20}, "Cat", "Manila", 12223};
    AnimalInfo info3 = {{"Whitie", 23}, "Dog", "BGC", 333333};
    AnimalInfo info4 = {{"Brownie", 19}, "Dog", "Makati", 444444};

    SortviaAge(D, info1);
    SortviaAge(D, info2);
    SortviaAge(D, info3);
    SortviaAge(D, info4);

    deleteCageNo(D, 444444);

    visualize(D);

	return 0;
}
