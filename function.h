#ifndef FUNCTION_H
#define FUNCTION_H

#define MAX_ANIMALS 100 // Maximum number of animals in the farm

enum AnimalType
{
    COW,
    HORSE,
    SHEEP,
    PIG
};

enum Gender
{
    MALE,
    FEMALE
};

// Different breeds for each animal type
enum BreedCow
{
    HOLSTEIN,
    ANGUS,
    JERSEY,
    SIMMENTAL,
    HEREFORD
};

enum BreedHorse
{
    THOROUGHBRED,
    QUARTER_HORSE,
    APPALOOSA,
    ARABIAN,
    FRIESIAN
};

enum BreedSheep
{
    MERINO,
    DORSET,
    SUFFOLK,
    HAMPSHIRE,
    ROMNEY // Add ROMNEY breed for sheep
};

enum BreedPig
{
    BERKSHIRE,
    DUROC,
    YORKSHIRE,
    LANDRACE
};

struct Animal
{
    int tagNumber;
    char name[50];
    int age;
    enum AnimalType type;
    double weight;
    enum Gender gender;
    int numOffsprings;
    // Different breed fields for each animal type
    union
    {
        enum BreedCow cowBreed;
        enum BreedHorse horseBreed;
        enum BreedSheep sheepBreed;
        enum BreedPig pigBreed;
    } breed;
};

struct Farm
{
    struct Animal animals[MAX_ANIMALS];
    int animalCount;
};

// Function prototypes
void populateFarm(struct Farm *farm, int numAnimals);
void printFarm(const struct Farm *farm);

#endif
