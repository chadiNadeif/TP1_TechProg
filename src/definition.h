// Vous devez ajouter ce #pragma a tous vos fichiers .h de votre projet.
// Il garantit que le fichier "header" n'est inclus qu'une seule fois par compilation,
// ce qui evite les erreurs de redefinition et les conflits de symboles.
#pragma once

#include <stdint.h>

void* allocate(size_t size);
typedef struct item Item;
struct item {
	char* name[256];
	int value;
};
typedef struct slot Slot;

typedef struct inventory Inventory;

// Vous devez definir les structures et fonctions que vous voulez exposer dans les "headers"
// Si jamais vous avez des fonctions avec des noms commun, vous devez les prefixer pour eviter des conflits de symboles
// Le prefix peut etre le nom de votre projet, exemple: forhonor_nom_de_fonction
void monprojet_add(Inventory* inventaire, Item* item);
void monprojet_remove(Inventory* inventaire, Item* item);
void monprojet_sort(Inventory* inventaire);
Item* monprojet_FindItemAt(Inventory* inventaire, int index);
Item* monprojet_FindItemByName(Inventory* inventaire, char* name[256]);
Item* File(Item* item, char* name);