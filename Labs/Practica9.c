#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#define SIZE 20

// Definici�n de variables globales
struct DataItem {
    int data;
    int key;
};
struct DataItem* hashArray[SIZE];                   // Tabla Hash
struct DataItem* dummyItem;                         // Para marcar nodos borrados.
struct DataItem* item;                              // Cualquier nodo

// Definici�n de funciones
int hashCode(int key);                              // Funci�n Hash
void insert(int key,int data);                      // Funci�n insert
struct DataItem *search(int key);                   // Funci�n search
struct DataItem* delete(struct DataItem* item);     // Funci�n delete
void display();                                     // Funci�n auxiliar.

int main() {
    dummyItem = (struct DataItem*) malloc(sizeof(struct DataItem));
    dummyItem->data = -1;
    dummyItem->key = -1;
    printf("Creando una Tabla Hash\n");
    insert(1, 20);
    insert(2, 70);
    insert(42, 80);         // colisi�n
    insert(4, 25);
    insert(12, 44);
    insert(14, 32);
    insert(17, 11);
    insert(13, 78);
    insert(37, 97);
    insert(24,11);          // colisi�n
    insert(64,11);          // colisi�n
    insert(84,11);          // colisi�n

    printf("Tabla creada.\n");
    // Despliega la tabla.
    display();

    printf("Busca el elemento 37 en la tabla.\n");
    item = search(37);

    if(item != NULL) {
        printf("Elemento encontrado: %d\n", item->key);
    } else {
        printf("Elemento no encontrado.\n");
    }
    printf("Borra el elemento 37 en la tabla.\n");
    delete(item);

    printf("Elemento 37 borrado.\n");
    
    display();

    printf("Busca el elemento 37 en la tabla.\n");
    item = search(37);

    if(item != NULL) {
        printf("Elemento encontrado: %d\n", item->data);
    } else {
        printf("Elemento no encontrado\n");
    }
    display();
    
    printf("Inserte el elemento 37 de nuevo\n");
    insert(37,97);
    display();
    
}
// Funci�n Hash
int hashCode(int key) {
    return key % SIZE;
}
// Funci�n search
struct DataItem *search(int key) {
    //get the hash
    int hashIndex = hashCode(key);
    //move in array until an empty
    while(hashArray[hashIndex] != NULL) {
        if(hashArray[hashIndex]->key == key) {
            return hashArray[hashIndex];
        }
        //go to next cell (linear probe)
        ++hashIndex;
        //wrap around the table
        hashIndex %= SIZE;
    }
    return NULL;
}

// Funci�n insert
void insert(int key,int data) {
    struct DataItem *item = (struct DataItem*) malloc(sizeof(struct DataItem));
    item->data = data;
    item->key = key;
    //get the hash
    int hashIndex = hashCode(key);
    //move in array until an empty or deleted cell
    while(hashArray[hashIndex] != NULL && hashArray[hashIndex]->key != -1) {
        //go to next cell (linear probe)
        ++hashIndex;
        //wrap around the table
        hashIndex %= SIZE;
    }
    hashArray[hashIndex] = item;
}

// Funci�n delete
struct DataItem* delete(struct DataItem* item) {
    int key = item->key;
    //get the hash
    int hashIndex = hashCode(key);
    //move in array until an empty
    while(hashArray[hashIndex] != NULL) {
        if(hashArray[hashIndex]->key == key) {
            struct DataItem* temp = hashArray[hashIndex];
            //assign a dummy item at deleted position
            hashArray[hashIndex] = dummyItem;
            return temp;
        }
        //go to next cell
        ++hashIndex;
        //wrap around the table
        hashIndex %= SIZE;
    }
    return NULL;
}
// Funci�n display.
void display() {
    int i = 0;
    for(i = 0; i<SIZE; i++) {
        if(hashArray[i] != NULL)
            printf("%2d: (%d,%d)\n",i,hashArray[i]->key,hashArray[i]->data);
        else
            printf("%2d: (~,~)\n",i);
    }
    printf("\n");
}
