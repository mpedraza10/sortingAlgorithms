#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <stdio.h>
#include <sys/time.h>
using namespace std;
#include "Fraccion.h"

// Funciones para tomar el tiempo
void startTime(struct timeval &begin) {
    gettimeofday(&begin, 0);
}

void getTime(struct timeval begin, struct timeval end) {
    long seconds, microseconds;
    double elapsed;
    gettimeofday(&end, 0);
    seconds = end.tv_sec - begin.tv_sec;
    microseconds = end.tv_usec - begin.tv_usec;
    elapsed = seconds + microseconds*1e-6;
    printf("Tiempo de ejecución: %.8f seconds.\n", elapsed);
}

// Funcion para intercambiar valores de posicion en lista
template<class T>
void swap(vector<T>& list, int i, int j)
{
    // Creamos una variable auxiliar para guardar el valor de la posición i
    T temp = list[i];
    // Asignamos el valor de la posición j a la posición i
    list[i] = list[j];
    // Asignamos el valor de la posición i (aux) a la posición j
    list[j] = temp;
}

// Funcion para imprimir las listas
template<class T>
void print(vector<T> list)
{
    for (int i = 0; i < list.size(); i++)
    {
        cout << list[i] << " ";
    }
    cout << endl;
}


// Funcion para ordenamiento por intercambio (Swap Sort)
// Complejidad de algoritmo: O(n^2)
template<class T>
void swapSort(vector<T>& list, int& nSwaps, int& nComparisons)
{
    // Tiempo inicial
    struct timeval begin, end;
    gettimeofday(&begin, 0);

    for (int i = 0; i < list.size() - 1; i++)
    {
        for (int j = (i+1); j < list.size(); j++)
        {
            nComparisons++; // Incrementamos las comparaciones
            if (list[i] > list[j])
            {
                swap(list, i, j); // Intercambiamos valores
                nSwaps++; // Incrementamos los swaps
            }
        }
    }

    // Tiempo final
    gettimeofday(&end, 0);
    getTime(begin, end);
}

// Funcion para ordenamiento burbuja (Bubble Sort)
// Complejidad de algoritmo: O(n^2)
template<class T>
void bubbleSort(vector<T>& list, int& nSwaps, int& nComparisons)
{
    // Tiempo inicial
    struct timeval begin, end;
    gettimeofday(&begin, 0);

    // Variable auxiliar con el tamaño de la lista menos 1
    int aux = list.size()-1;
    // Creamos una variable booleana para saber si hubo intercambios
    bool swapped = true;

    // Ciclo para ordenar, recorremos la lista hasta que no haya intercambios y termines de
    while (aux > 0 && swapped)
    {
        // Inicilizamos la variable en falso
        swapped = false;

        // Recorremos la lista de inicio al penultimo elemento
        for (int i = 0; i < aux; i++)
        {
            // Incrementamos numero de comparaciones
            nComparisons++;
            // Comparamos si el elemento actual es mayor que el que le sigue
            if (list[i] > list[i+1])
            {
                // Usaos funcion para intercambiar los valores
                swap(list, i, i+1);
                // Incrementamos contador de intercambios
                nSwaps++;
                // Cambiamos la variable booleana a true
                swapped = true;
            }
        }
        // Decrementamos valor de aux para que termine de recorrer la lista antes
        aux--;
    }

    // Tiempo final
    gettimeofday(&end, 0);
    getTime(begin, end);

    // Otra forma con doble for

    /* for (int i = 0; i < list.size() - 1; i++)
    {
        for (int j = 0; j < list.size() - i - 1; j++)
        {
            if (list[j] > list[j+1])
            {
                swap(list, i, j);
            }
        }
    } */
}

// Funcion para ordenamiento por seleccion (Selection Sort)
// Complejidad de algoritmo: O(n^2)
template<class T>
void selectionSort(vector<T>& list, int& nSwaps, int& nComparisons)
{
    // Tiempo inicial
    struct timeval begin, end;
    gettimeofday(&begin, 0);

    for (int i = 0; i < list.size() - 1; i++)
    {
        // Creamos variable auxiliar para guardar posicion i
        int min = i;
        // Recorremos la lista desde el siguiente elemento hasta el final
        for (int j = i + 1; j < list.size(); j++)
        {
            // Comparamos si elemento actual (min) es mayor que elemento j, cambiamos el valor de min
            nComparisons++; // Incrementamos número de comparaciones
            if (list[i] > list[j])
            {
                // Camabiamos el valor de min
                min = j;
            }
        }
        // Si el valor de min no es la posicion i, intercambiamos
        if (min != i)
        {
            swap(list, i, min);
            // Incrementamos numero de intercambios
            nSwaps++;
        }
    }

    // Tiempo final
    gettimeofday(&end, 0);
    getTime(begin, end);
}

// Funcion para ordenamiento por seleccion (Selection Sort)
// Complejidad de algoritmo: O(n^2)
template<class T>
void insertionSort(vector<T>& list, int& nSwaps, int& nComparisons)
{
    // Tiempo inicial
    struct timeval begin, end;
    gettimeofday(&begin, 0);

    // Recorremos la lista desde el segundo elemento hasta el final
    for (int i = 1; i < list.size(); i++)
    {
        // Variable auxiliar para guardar posicion de i
        int j = i;

        // Ciclo donde recorremos mientras que j > 0
        while (j > 0)
        {
            // Si el elmento actual (j) es menor que (j-1), intercambiamos
            nComparisons++;
            if (list[i] < list[j-1])
            {
                // Intercambiamos
                swap(list, j, j-1);
                nSwaps++;
                // Decrementamos valor de j
                j--;
            }
            else
            {
                // Si el elemnto (j) es mayor que (j-1) salimos del ciclo
                j = 0;
            }
        }
    }

    // Tiempo final
    gettimeofday(&end, 0);
    getTime(begin, end);
}

template<class T>
void sortAlgorithm(vector<T> &list, string algorithm) {
    int nSwaps = 0;
    int nComparisons = 0;
    cout << "Ordenamiento por " << algorithm << endl;
    print(list);
    if (algorithm ==  "Intercambio") {
        swapSort(list, nSwaps, nComparisons);
    } else {
        if (algorithm ==  "Burbuja") {
            bubbleSort(list, nSwaps, nComparisons);
        } else {
            if (algorithm == "Selección Directa") {
                selectionSort(list, nSwaps, nComparisons);
            } else {
                if (algorithm == "Inserción") {
                    insertionSort(list, nSwaps, nComparisons);
                }
            }
        }
    }
    cout << "Lista ordenada: ";
    print(list);
    cout << "Número de intercambios: " << nSwaps << endl;
    cout << "Número de comparaciones: " << nComparisons << endl;
}



void createListInt(vector<int> &lista, int cantidad) {
    lista.clear();
    for (int i=0; i<cantidad; i++) {
        lista.push_back(rand() % 100 + 1);
    }
}

void createListChar(vector<char> &lista, int cantidad) {
    lista.clear();
    int r;
    for (int i=0; i<cantidad; i++) {
        r = rand() % 26;
        lista.push_back('a' + r);
    }
}

void createListFrac(vector<Fraccion> &lista, int cantidad) {
    lista.clear();
    int numerador, denominador;
    for (int i=0;i<cantidad;i++) {
        cout << "Teclea el numerador: " << endl;
        cin >> numerador;
        cout << "Teclea el denominador: " << endl;
        cin >> denominador;
        lista.push_back(Fraccion(numerador,denominador));
    }
}

void createListString(vector<string> &lista, int cantidad) {
    lista.clear();
    string valor;
    for (int i=0;i<cantidad;i++) {
        cout << "Teclea una palabra: " << endl;
        cin >> valor;
        lista.push_back(valor);
    }
}

int main()
{
    srand(time(NULL));

    vector<int> listIntOrig;
    vector<int> listInt;
    vector<Fraccion> listFracOrig;
    vector<Fraccion> listFrac;
    vector<char> listCharOrig;
    vector<char> listChar;
    vector<string> listStringOrig;
    vector<string> listString;
    int qty = 10;
    char listType = 'i';
    char opc = 'a';

    while (opc != 'z')
    {
        cout << endl;
        cout << "Menu" << endl;
        cout << "Eliga una de las opciones para comenzar: " << endl;
        cout << "a) Selecciona tipo de dato que deseas para crear tu lista (entero, fraccion, string, etc)" << endl;
        cout << "b) Orden por Intercambio" << endl;
        cout << "c) Orden por Burbuja" << endl;
        cout << "d) Orden por Selección Directa" << endl;
        cout << "e) Orden por Inserción" << endl;
        cout << "z) Salir" << endl;
        cout << endl << "Teclea una opción: ";
        cin >> opc;

        switch (opc) {
            case 'a':
                cout << "Teclea el tipo de datos deseado (e) entero, (f) fraccion, (c) char, (s) string " << endl;
                cin >> listType;
                switch (listType) {
                case 'e':
                    cout << "Teclea la cantidad de números enteros que deseas en la lista" << endl;
                    cin >> qty;
                    createListInt(listIntOrig,qty);
                    listInt = listIntOrig;
                    print(listInt);
                    break;
                case 'f':
                    qty = 6;
                    createListFrac(listFracOrig,qty);
                    listFrac = listFracOrig;
                    print(listFrac);
                    break;
                case 'c':
                    qty = 20;
                    createListChar(listCharOrig,qty);
                    listChar = listCharOrig;
                    print(listChar);
                    break;
                case 's':
                    qty = 7;
                    createListString(listStringOrig,qty);
                    listString = listStringOrig;
                    print(listString);
                    break;
                default:
                    cout << "Teclea la cantidad de números enteros que deseas en la lista" << endl;
                    cin >> qty;
                    createListInt(listIntOrig,qty);
                    listInt = listIntOrig;
                    print(listInt);
                    break;
                }
                break;
            case 'b':
                switch (listType) {
                case 'e':
                    listInt = listIntOrig;
                    sortAlgorithm(listInt, "Intercambio");
                    break;
                case 'f':
                    listFrac = listFracOrig;
                    sortAlgorithm(listFrac, "Intercambio");
                    break;
                case 'c':
                    listChar = listCharOrig;
                    sortAlgorithm(listChar, "Intercambio");
                    break;
                case 's':
                    listString = listStringOrig;
                    sortAlgorithm(listString, "Intercambio");
                    break;
                default:
                    listInt = listIntOrig;
                    sortAlgorithm(listInt, "Intercambio");
                    break;
                }
                break;
            case 'c':
                switch (listType) {
                case 'e':
                    listInt = listIntOrig;
                    sortAlgorithm(listInt, "Burbuja");
                    break;
                case 'f':
                    listFrac = listFracOrig;
                    sortAlgorithm(listFrac, "Burbuja");
                    break;
                case 'c':
                    listChar = listCharOrig;
                    sortAlgorithm(listChar, "Burbuja");
                    break;
                case 's':
                    listString = listStringOrig;
                    sortAlgorithm(listString, "Burbuja");
                    break;
                default:
                    listInt = listIntOrig;
                    sortAlgorithm(listInt, "Burbuja");
                    break;
                }
                break;
            case 'd':
                switch (listType) {
                case 'e':
                    listInt = listIntOrig;
                    sortAlgorithm(listInt, "Selección Directa");
                    break;
                case 'f':
                    listFrac = listFracOrig;
                    sortAlgorithm(listFrac, "Selección Directa");
                    break;
                case 'c':
                    listChar = listCharOrig;
                    sortAlgorithm(listChar, "Selección Directa");
                    break;
                case 's':
                    listString = listStringOrig;
                    sortAlgorithm(listString, "Selección Directa");
                    break;
                default:
                    listInt = listIntOrig;
                    sortAlgorithm(listInt, "Selección Directa");
                    break;
                }
                break;
            case 'e':
                switch (listType) {
                case 'e':
                    listInt = listIntOrig;
                    sortAlgorithm(listInt, "Inserción");
                    break;
                case 'f':
                    listFrac = listFracOrig;
                    sortAlgorithm(listFrac, "Inserción");
                    break;
                case 'c':
                    listChar = listCharOrig;
                    sortAlgorithm(listChar, "Inserción");
                    break;
                case 's':
                    listString = listStringOrig;
                    sortAlgorithm(listString, "Inserción");
                    break;
                default:
                    listInt = listIntOrig;
                    sortAlgorithm(listInt, "Inserción");
                    break;
                }
                break;
            case 'z':
                cout << endl << "¡Gracias!" << endl;
                break;
            default:
                break;
            }
    }

    return 0;
}

