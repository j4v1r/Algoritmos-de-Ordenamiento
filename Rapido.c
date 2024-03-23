/*
Insercion.c
V 1.0 Marzo 2024
Grupo: 2CM2
Autores: Colunga Aguilar Javier Alejandro
		
Programa que lee una n cantidad de n�meros y los escribe en un arreglo din�mico ptr,
despu�s ejecuta el algoritmo de ordenamiento R�pido O(n logn) que ordena estos 
n�meros de menor a mayor. Finalmente, imprime estos n�meros ordenados en un archivo
de texto y muestra el tiempo de ejecuci�n del ordenamiento.

Compilaci�n:
En el script.bat: 
gcc Rapido.c -o rapido
rapido n<archivo.txt> nombrearchivosalida.txt					

*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define TRUE 1
#define FALSE 0


void rapido(int *arr, int p, int r);
int pivote(int *arr, int p, int r);
void intercambiar(int *arr, int i, int j);

int main(int nums, char* argv[]){
	
	
	//Variables para medir el tiempo
	clock_t t_inicio, t_final;
    double t_intervalo;
	
	int* ptr; //Guarda la direcci�n del bloque creado
	int n, i, j, p, r;
	
	//Recibir por argumento el tamaño de n y el valor a buscar
	if (nums!=2) 
	{
		printf("\nIndique el tamanio de n - Ejemplo: [user@equipo]$ %s 100\n",argv[0]);
		exit(1);
	} 
	
	//Tomar el argumento del main
	n=atoi(argv[1]); //n
	
	
	//Asigna memoria dinamica usando malloc()
	ptr = malloc(n*sizeof(int));
		  //(int*) Cambio de una variable perteneciente a un tipo de dato a otro.
	
	if(ptr == NULL) {
		//Comprueba que la memoria s� fue asignada
        printf("Memoria no asignada\n");
        exit(0);
        
    }else{
    	
		//Leer de la entrada estandar los n valores y colocarlos en el arreglo de números
		for(i=0;i<n;i++){
			scanf("%d",&ptr[i]);
		}
		
	
		//*****************************************  
		//Algoritmo a medir el tiempo
		//*****************************************
		//Inicia medición del tiempo
		t_inicio = clock();
	
		//Llamar al algoritmo
		rapido(ptr, 0, n-1);
	
		//Termina medición del tiempo	
		t_final = clock();
	
		//Cálculo del tiempo y enviar mensaje a salida estandar con la medición  
    	t_intervalo = (double)(t_final - t_inicio) / CLOCKS_PER_SEC;
   
	
		//Mostrar el tiempo medido 
		printf("\n\nTiempo medido: %.8f segundos.", t_intervalo);
	
		//Enviar a la salida estandar el arreglo final
		printf("\n\nArreglo invertido:");
		for(i=0;i<n;i++){
			printf("\nptr[%d]=%d",i,ptr[i]);
		}
			
	}
	
	return 0;
}


/*
void rapido(int *arr,int p, int r)

Recibe: int *arr, direcci�n del arreglo ptr de memoria din�mica
		int p, inicio del arreglo recibido
		int r, final del arreglo recibido
		
Devuelve: void (No retorna valor explicito)

Observaciones: Si la primera posici�n del arreglo es menor que la �ltima se manda a llamar
la funci�n "pivote" para obtener un n�mero pivote ("j") que "divida" el arreglo en dos partes.
Despu�s, se vuelve a llamar la funci�n "rapido", enviando el arreglo, y la posici�n "p" como el 
inicio del arreglo y "j-1" como el final para los n�meros a la derecha del pivote y la posici�n 
"j+1" como el inicio y "r" como el final para los n�meros a la izquierda del pivote. 
*/
void rapido(int *arr, int p, int r){
	 
	if(p<r){
		int j=pivote(arr, p, r);
		rapido(arr, p, j-1);
		rapido(arr, j+1, r);
	}
	
	return;	
}


/*
void pivote(int *arr, int p, int r)

Recibe: int *arr, direcci�n del arreglo ptr de memoria din�mica
		int p, posici�n incial en el arreglo de los n�meros a la izquierda del pivote
		int r, posici�n final en el arreglo de los n�meros a la derecha del pivote
		
Devuelve: int j, la posici�n en el arreglo donde se encuentra el pivote seleccionado

Observaciones: La funci�n "pivote" se encarga de seleccionar el n�mero en la posici�n "p"
del arreglo (que llamaremos pivote) y compararlo con los n�meros a su izquierda (usando el
indice "i" e inciando desde el principio) y con los n�meros a su derecha (usando el indice
"j" e iniciando desde el final). 

Si un n�mero a la izquierda es mayor que el pivote se guarda la posici�n de este ("i"), 
de lo contrario el ciclo continua, avanzando una posici�n, hasta encontrar un n�mero mayor.
Lo mismo sucede con los n�meros a la derecha, si hay un n�mero menor que el pivote se guarda
su posici�n ("j"), de lo contrario el ciclo continua, retrocediendo una posici�n, hasta
encontar un n�mero menor.

Una vez se ha encontrado un n�mero mayor y un n�mero menor al pivote se manda a llamar la 
funci�n "intercambiar", enviando el arreglo y la posici�n de estos en el mismo para 
ser intercambiados entre ellos en el arreglo. 
Este ciclo se repite mientras el indice de los n�meros a la derecha del pivote ("i") sea
menor al indice de los n�meros a la izquierda ("j"), pues significa que ambos indices han 
llegado a la posici�n del pivote y todos los n�meros a la derecha son menores que el pivote
mientras que todos a la izquierda son mayores.

Despu�s, el pivote se coloca en la posici�n correcta en el arreglo mandando a llamar nuevamente
la funci�n "intercambiar" y enviando la posici�n original del pivote ("p") y la posici�n donde debe
colocarse ("j").

Finalmente, la funci�n regresa la posici�n en el arreglo donde se encuentra el pivote seleccionado ("j").
*/
int pivote(int *arr, int p, int r){
	
	int piv=arr[p], i=p+1, j=r;
	
	while(i<j){
		while(arr[i]<=piv && i<r){
			i++;
		}
		
		while(arr[j]>piv){
			j--;
		}
		
		if(i<j){
			intercambiar(arr, i, j);
		}
	}
	intercambiar(arr, p, j);
	
	return j;	
}


/*
void intercambiar(int *arr, int i, int j)

Recibe: int *arr, direcci�n del arreglo ptr de memoria din�mica
		int i, posici�n en el arreglo de un n�mero a intercambiar
		int j, posici�n en el arreglo de un n�mero a intercambiar
		
Devuelve: void (No retorna valor explicito)

Observaciones: Haciendo uso de la variable "aux", la funci�n intercambia los
n�meros en la posici�n "i" y "j" del arreglo, asignando a la variable "aux" 
el valor del n�mero en la posici�n "j", despu�s a la posici�n "j" el n�mero
en la posici�n "i" y finalmente a la posici�n "i" el valor de "aux".
*/
void intercambiar(int *arr, int i, int j){
	
	int aux;
	
	aux=arr[j];
	arr[j]=arr[i];
	arr[i]=aux;
	
	return;
}

