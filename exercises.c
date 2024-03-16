#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Ejercicio 1: Encuentra e  l Elemento Mayor
Descripción: Escribe una función que tome un arreglo de enteros
y su tamaño, y devuelva el valor más grande del arreglo.
*/
int findMax(int arr[], int size) 
{
  //Creo una variable para guardar el valor maximo
  int almacenarMayor = arr[0];
  for (int i = 0; i < size; i++)
    {
      if (arr[i] > almacenarMayor)
      {
        almacenarMayor = arr[i];
      }
    }  
  return almacenarMayor;
}

/*
Ejercicio 2: Invertir un Arreglo
Descripción: Escribe una función que tome un arreglo y su tamaño, y luego
invierta el orden de sus elementos.
*/
void reverseArray(int arr[], int size) 
{
  int temp;
  for (int i = 0; i < size / 2; i++)
  {
    temp = arr[i];
    arr[i] = arr[size - i - 1];
    arr[size - i - 1] = temp;
  }
}

/*
Ejercicio 3: Filtrar Números Pares
Descripción: Escribe una función que tome un arreglo de enteros
y su tamaño, y luego devuelva un nuevo arreglo que contenga solo
los números pares del arreglo original.
*/
int *filterEvenNumbers(int arr[], int size, int *newSize) 
{
  int *arrPares = (int *) realloc(NULL, (* newSize) * sizeof(int *));
  if (arrPares == NULL) exit(EXIT_FAILURE);

  newSize = 0;

  for (int i = 0; i < size; i++)
    {
      if(arr[i] % 2 == 0)
      {
        (newSize)++;
        arrPares[*newSize - 1] = arr[i];
      }
    }

  
  return 0;
}

/*
Ejercicio 4: Fusión de dos Arreglos Ordenados
Descripción: Escribe una función que tome dos arreglos
ordenados y sus tamaños, y luego fusione estos dos
arreglos en un tercer arreglo también ordenado.
*/
void mergeSortedArrays(int arr1[], int size1, int arr2[], int size2,int result[]) 
{
  int nuevaTalla = size1 + size2;

  for (int i = 0; i < nuevaTalla; i++)
    {
      if(i < size1)
      {
        result[i] = arr1[i];
      }
      else
      {
        result[i] = arr2[i - size1];
      }
    }

  for (int i = 0; i < nuevaTalla - 1; i++)
    {
      for (int j = 0; j < nuevaTalla - i - 1; j++)
        {
          if (result[j] > result[j + 1])
          {
            int aux = result[j];
            result[j] = result[j + 1];
            result[j + 1] = aux;
          }
        }
    }
}


/*
Ejercicio 5: Comprobación de Ordenación
Descripción: Escribe una función que tome un arreglo y su tamaño,
y luego devuelva 1 si el arreglo está ordenado en orden ascendente,
  0 si no está ordenado, y -1 si está ordenado en orden descendente.
*/
int checkSorted(int arr[], int size) 
{ 
  //Inicializo las variables en verdadero
  int ascendente = 1; int descendente = 1;

  for(int i = 0; i < size - 1; i++)
    {
      //En caso de no cumplir, se cambia el valor de las variables a falso
      if(arr[i] > arr[i + 1]) ascendente = 0;
      else if(arr[i] < arr[i + 1]) descendente = 0;
    }
  
  if (ascendente) return 1;
  else if (descendente) return -1;
  else return 0;
}

/*
Ejercicio 6: Información de una Biblioteca
Descripción: Vamos a representar la información de una biblioteca. En la
biblioteca, hay libros, y cada libro tiene un autor. Queremos organizar esta
información utilizando estructuras anidadas en C. Escribe la función para
inicializar la información de un libro.
*/

typedef struct {
  char nombre[50];
  int anioNacimiento;
} Autor;

typedef struct {
  char titulo[100];
  Autor autor;
  int anioPublicacion;
} Libro;

void inicializarLibro(Libro *libro, const char *titulo, const char *nombreAutor,
                      int anioNacimiento, int anioPublicacion) 
{
  //Copio los strings
  strcpy(libro->titulo, titulo);
  strcpy(libro->autor.nombre, nombreAutor);
  //Copio los int
  libro->autor.anioNacimiento = anioNacimiento;
  libro->anioPublicacion = anioPublicacion; 
}

/*
Ejercicio 7: Lista enlazada de números
Descripción: Escribe una función que tome un arreglo de enteros y su tamaño, y
luego cree una lista enlazada usando la estructura Nodo. Cada nodo de la lista
debe contener un número del arreglo, y los nodos deben estar enlazados en el
mismo orden que los números aparecen en el arreglo. El último nodo de la lista
debe apuntar a NULL. La función debe devolver un puntero al primer nodo de la
lista enlazada.
Recuerda reservar memoria dinámica para cada nodo usando malloc.
  */

typedef struct nodo {
  int numero;
  struct nodo *siguiente; // puntero al siguiente nodo
} Nodo;

Nodo *crearListaEnlazada(int arr[], int size) 
{ 
  Nodo *temp = NULL;

  Nodo *listaNodo = (Nodo *) malloc(sizeof(Nodo));
  listaNodo->numero = arr[0];
  listaNodo->siguiente = NULL;

  for (int i = 1; i < size; i++)
    {
      temp = (Nodo *)malloc(sizeof(Nodo));
      temp->numero = arr[i];
      temp->siguiente = NULL;

      Nodo *aux = listaNodo;

      while (aux->siguiente != NULL)
        {
          aux = aux->siguiente;
        }
      aux->siguiente = temp;
    }
  return listaNodo;
}
