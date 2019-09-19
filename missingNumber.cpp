/* C++ implementation of QuickSort */
#include <bits/stdc++.h>
using namespace std;
// Una función para cambiar dos elementos
void swap(int* a, int* b)
{
int t = *a;
*a = *b;
*b = t;
}
/* Esta función toma el último elemento como pivote, lo coloca en su posición
correcta en el arreglo y posiciona todos los elementos menores a la izquierda y los
mayores a la derecha de el mismo*/
int partition (int arr[], int low, int high)
{
int pivot = arr[high]; // pivote
int i = (low - 1); // posición del primer elemento
for (int j = low; j <= high - 1; j++)
{
// Si el el elemento actual es menor que el pivote
if (arr[j] < pivot)
{
i++; // incrementar el index del menor elemento
swap(&arr[i], &arr[j]);
}
}
swap(&arr[i + 1], &arr[high]);
return (i + 1);
}
/* La función principal que corre QuickSort
arr[] --> arreglo a ordenar,
low --> límite inicial,
high --> límite final */
void quickSort(int arr[], int low, int high)
{
if (low < high)
{
/*pi es la partición del índice, arr[p] está en el lugar correcto */
int pi = partition(arr, low, high);
// Ordenando separadamente los elementos antes y después de la
// partición
quickSort(arr, low, pi - 1);
quickSort(arr, pi + 1, high);
}
}
/* Función para imprimir arreglo */
void printArray(int arr[], int size)
{
int i;
for (i = 0; i < size; i++)
cout << arr[i] << " ";
cout << endl;
}




void llenarArreglos(int elementos,int paro,int arreglo[]){
    if(paro != elementos){
        cout << "Elemento " << paro+1<<": ";
        cin >> arreglo[paro];
        llenarArreglos(elementos, paro+1, arreglo);
    }else{
        quickSort(arreglo, 0, elementos-1);
        cout << "Sorted array: \n";
        printArray(arreglo, elementos);
        cout << endl;
    }
    //int n = sizeof(A) / sizeof(A[0]);
}

void cantidadArreglos(int cant, int stop){
    if(stop != cant){
        cout << "Arreglo " << stop+1 << endl;
        cout << "Tamaño del arreglo " << stop+1 <<": ";
        int elementos;
        cin >> elementos;
        int arreglo[elementos];
        llenarArreglos(elementos, 0, arreglo);
        cantidadArreglos(cant, stop+1);
    }
}

// Código principal para utilizarlo
int main()
{
    int n;
    cout << "Cuantos arreglos desea ingresar?: ";
    cin >> n;
    cantidadArreglos(n,0);
return 0;
}
