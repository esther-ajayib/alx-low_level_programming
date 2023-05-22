#include <stdio.h>
#include <stdlib.h>
#include "dog.h"

/**
 *init_dog - Initializes a struct dog
 *@d: Pointer to the struct dog
 *@name: Name of the dog
 *@age: Age of the dog
 *@owner: Owner of the dog
 *
 *Description: This function initializes the fields of a struct dog.
 */

void init_dog(struct dog *d, char *name, float age, char *owner)
{
	if (d == NULL)
		return;

	d->name = name;
	d->age = age;
	d->owner = owner;
}
