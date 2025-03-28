#include "definition.h"
#include <string.h>
#include <stdio.h>
#include<stdlib.h>

// Il est important de faire l'implementation de vos fonctions dans un fichier .c
// Si vous le faites dans le fichier "header", chaque fichier qui l'include va compiler l`implementation
// et cela causeras des definitions de symboles multiples.


struct slot {
	Item* item;
	Slot* prev;
	Slot* next;
};
struct inventory {
	Slot* first;
	Slot* last;
	int count;
};
void monprojet_add(Inventory* inventaire, Item* item) {
	Slot* slot = allocate(sizeof(Slot));
	slot->item;
	if (inventaire->first == NULL) {
		inventaire->first = slot;
		inventaire->last = slot;
		inventaire->count = 1;
		return;
	}
	slot->prev = inventaire->last;
	inventaire->last->next = slot;
	inventaire->last = slot;
	inventaire->count++;
}
void monprojet_remove(Inventory* inventaire, Item* item) {
	Slot* current = inventaire->first;
	while (current != NULL) {
		if (current->item == item) {
			if (current->prev != NULL) {
				current->prev->next = current->next;
			}
			if (current->next != NULL) {
				current->next->prev = current->prev;
			}
			inventaire->count--;
			current = NULL;
			break;
		}
		current = current->next;
	}
}
void monprojet_sort(Inventory* inventaire) {
	Slot* temp = inventaire->first;
	while (temp != inventaire->last) {
		Item* Item1 = temp->item;
		Item* Item2 = temp->next->item;
		if (Item1->value>Item2->value) {
			int tempo = Item1->value;
			Item1->value = Item2->value;
			Item2->value = tempo;			
		}
		temp = temp->next;
	}
}
Item* monprojet_FindItemAt(Inventory* inventaire, int index) {
	if (index < 0 || index >= inventaire->count) {
		return NULL;
	}
	Slot* current = inventaire->first;
	for (int i = 0; i <= index; i++) {
		current = current->next;
		if (i == index) {
			return current->item;
		}
	}
}
Item* monprojet_FindItemByName(Inventory* inventaire, char* name[256]) {
	Item* item = { 0 };
	Slot* current = inventaire->first;
	while (current != NULL && strcmp(current->item->name, name)!=0) {

		current = current->next;
		if (current != NULL && strcmp(current->item->name, name) == 0) {

			return item;
		}
	}
}
Item* File(Item* item, char* name) {
	Item* file = fopen(name, "a");
	int i = 0;
	Item default_items[8];
	if (file == NULL) {
		printf("Error!\n");
		return 1;
	}
	fprintf(file, "\nfiole\n");
	printf("Done");
	
	fclose(file);
	return 0;
}
