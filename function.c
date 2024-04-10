#include <stdio.h>
#include "function.h"

void populateFarm(struct Farm *farm, int numAnimals)
{
    printf("Enter details for each animal:\n");
    farm->animalCount = numAnimals;
    int i;
    for (i = 0; i < numAnimals; ++i)
    {
        printf("Animal %d:\n", i + 1);
        printf("Tag Number: ");
        scanf("%d", &farm->animals[i].tagNumber);
        printf("Name: ");
        scanf("%s", farm->animals[i].name);
        printf("Age: ");
        scanf("%d", &farm->animals[i].age);
        printf("Type (0: Cow, 1: Horse, 2: Sheep, 3: Pig): ");
        scanf("%d", (int *)&farm->animals[i].type);
        printf("Weight: ");
        scanf("%lf", &farm->animals[i].weight);
        printf("Gender (0: Male, 1: Female): ");
        scanf("%d", (int *)&farm->animals[i].gender);
        printf("Number of Offsprings: ");
        scanf("%d", &farm->animals[i].numOffsprings);

        // Additional prompts for breed based on animal type
        switch (farm->animals[i].type)
        {
        case COW:
            printf("Breed (0: Holstein, 1: Angus, 2: Jersey, 3: Simmental, 4: Hereford): ");
            scanf("%d", (int *)&farm->animals[i].breed.cowBreed);
            break;
        case HORSE:
            printf("Breed (0: Thoroughbred, 1: Quarter Horse, 2: Appaloosa, 3: Arabian, 4: Friesian): ");
            scanf("%d", (int *)&farm->animals[i].breed.horseBreed);
            break;
        case SHEEP:
            printf("Breed (0: Merino, 1: Dorset, 2: Suffolk, 3: Hampshire, 4: Romney): ");
            scanf("%d", (int *)&farm->animals[i].breed.sheepBreed);
            break;
        case PIG:
            printf("Breed (0: Berkshire, 1: Duroc, 2: Yorkshire, 3: Landrace, 4: Hampshire): ");
            scanf("%d", (int *)&farm->animals[i].breed.pigBreed);
            break;
        default:
            break;
        }
    }
}

void printFarm(const struct Farm *farm)
{
    int i;
    printf("Farm Animals:\n");
    for (i = 0; i < farm->animalCount; ++i)
    {
        const char *typeStr;
        switch (farm->animals[i].type)
        {
        case COW:
            typeStr = "Cow";
            break;
        case HORSE:
            typeStr = "Horse";
            break;
        case SHEEP:
            typeStr = "Sheep";
            break;
        case PIG:
            typeStr = "Pig";
            break;
        default:
            typeStr = "Unknown";
            break;
        }

        const char *genderStr;
        switch (farm->animals[i].gender)
        {
        case MALE:
            genderStr = "Male";
            break;
        case FEMALE:
            genderStr = "Female";
            break;
        default:
            genderStr = "Unknown";
            break;
        }

        const char *breedStr;
        switch (farm->animals[i].type)
        {
        case COW:
            switch (farm->animals[i].breed.cowBreed)
            {
            case HOLSTEIN:
                breedStr = "Holstein";
                break;
            case ANGUS:
                breedStr = "Angus";
                break;
            case JERSEY:
                breedStr = "Jersey";
                break;
            case SIMMENTAL:
                breedStr = "Simmental";
                break;
            case HEREFORD:
                breedStr = "Hereford";
                break;
            default:
                breedStr = "Unknown";
                break;
            }
            break;
        case HORSE:
            switch (farm->animals[i].breed.horseBreed)
            {
            case THOROUGHBRED:
                breedStr = "Thoroughbred";
                break;
            case QUARTER_HORSE:
                breedStr = "Quarter Horse";
                break;
            case APPALOOSA:
                breedStr = "Appaloosa";
                break;
            case ARABIAN:
                breedStr = "Arabian";
                break;
            case FRIESIAN:
                breedStr = "Friesian";
                break;
            default:
                breedStr = "Unknown";
                break;
            }
            break;
        case SHEEP:
            switch (farm->animals[i].breed.sheepBreed)
            {
            case MERINO:
                breedStr = "Merino";
                break;
            case DORSET:
                breedStr = "Dorset";
                break;
            case SUFFOLK:
                breedStr = "Suffolk";
                break;
            case HAMPSHIRE:
                breedStr = "Hampshire";
                break;
            case ROMNEY:
                breedStr = "Romney";
                break;
            default:
                breedStr = "Unknown";
                break;
            }
            break;
        case PIG:
            switch (farm->animals[i].breed.pigBreed)
            {
            case BERKSHIRE:
                breedStr = "Berkshire";
                break;
            case DUROC:
                breedStr = "Duroc";
                break;
            case YORKSHIRE:
                breedStr = "Yorkshire";
                break;
            case LANDRACE:
                breedStr = "Landrace";
                break;
            default:
                breedStr = "Unknown";
                break;
            }
            break;
        default:
            breedStr = "Unknown";
            break;
        }

        printf("Tag Number: %d, Name: %s, Age: %d, Type: %s, Weight: %.2f, Gender: %s, Offsprings: %d, Breed: %s\n",
               farm->animals[i].tagNumber,
               farm->animals[i].name,
               farm->animals[i].age,
               typeStr,
               farm->animals[i].weight,
               genderStr,
               farm->animals[i].numOffsprings,
               breedStr);
    }
}
