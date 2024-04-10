#include <stdio.h>
#include "function.h"

int main()
{
    struct Farm farm;
    int numAnimals;

    printf("Enter the number of animals: ");
    scanf("%d", &numAnimals);

    populateFarm(&farm, numAnimals);
    printFarm(&farm);

    return 0;
}