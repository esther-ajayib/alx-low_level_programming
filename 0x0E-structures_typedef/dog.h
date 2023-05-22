#ifndef DOG_H
#define DOG_H

/**
 *struct dog - Structure representing a dog
 *@name: Pointer to the name of the dog
 *@age: Age of the dog
 *@owner: Pointer to the owner of the dog
 *
 *Description: This structure represents a dog and its attributes.
 *
 */
typedef struct dog
{
	char *name;
	float age;
	char *owner;
} dog_t;

void init_dog(struct dog *d, char *name, float age, char *owner);
void init_dog(dog_t *d, char *name, float age, char *owner);

#endif /* DOG_H */
