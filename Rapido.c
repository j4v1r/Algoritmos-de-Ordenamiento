/*
Insercion.c
V 1.0 Marzo 2024
Grupo: 2CM2
Autores: Colunga Aguilar Javier Alejandro
		
Programa que lee una n cantidad de números y los escribe en un arreglo dinámico ptr,
después ejecuta el algoritmo de ordenamiento Rápido O(n logn) que ordena estos 
números de menor a mayor. Finalmente, imprime estos números ordenados en un archivo
de texto y muestra el tiempo de ejecución del ordenamiento.

Compilación:
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
	
	int* ptr; //Guarda la dirección del bloque creado
	int n, i, j, p, r;
	
	//Recibir por argumento el tamaÃ±o de n y el valor a buscar
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
		//Comprueba que la memoria sí fue asignada
        printf("Memoria no asignada\n");
        exit(0);
        
    }else{
    	
		//Leer de la entrada estandar los n valores y colocarlos en el arreglo de nÃºmeros
		for(i=0;i<n;i++){
			scanf("%d",&ptr[i]);
		}
		
	
		//*****************************************  
		//Algoritmo a medir el tiempo
		//*****************************************
		//Inicia mediciÃ³n del tiempo
		t_inicio = clock();
	
		//Llamar al algoritmo
		rapido(ptr, 0, n-1);
	
		//Termina mediciÃ³n del tiempo	
		t_final = clock();
	
		//CÃ¡lculo del tiempo y enviar mensaje a salida estandar con la mediciÃ³n  
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

Recibe: int *arr, dirección del arreglo ptr de memoria dinámica
		int p, inicio del arreglo recibido
		int r, final del arreglo recibido
		
Devuelve: void (No retorna valor explicito)

Observaciones: Si la primera posición del arreglo es menor que la última se manda a llamar
la función "pivote" para obtener un número pivote ("j") que "divida" el arreglo en dos partes.
Después, se vuelve a llamar la función "rapido", enviando el arreglo, y la posición "p" como el 
inicio del arreglo y "j-1" como el final para los números a la derecha del pivote y la posición 
"j+1" como el inicio y "r" como el final para los números a la izquierda del pivote. 
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

Recibe: int *arr, dirección del arreglo ptr de memoria dinámica
		int p, posición incial en el arreglo de los números a la izquierda del pivote
		int r, posición final en el arreglo de los números a la derecha del pivote
		
Devuelve: int j, la posición en el arreglo donde se encuentra el pivote seleccionado

Observaciones: La función "pivote" se encarga de seleccionar el número en la posición "p"
del arreglo (que llamaremos pivote) y compararlo con los números a su izquierda (usando el
indice "i" e inciando desde el principio) y con los números a su derecha (usando el indice
"j" e iniciando desde el final). 

Si un número a la izquierda es mayor que el pivote se guarda la posición de este ("i"), 
de lo contrario el ciclo continua, avanzando una posición, hasta encontrar un número mayor.
Lo mismo sucede con los números a la derecha, si hay un número menor que el pivote se guarda
su posición ("j"), de lo contrario el ciclo continua, retrocediendo una posición, hasta
encontar un número menor.

Una vez se ha encontrado un número mayor y un número menor al pivote se manda a llamar la 
función "intercambiar", enviando el arreglo y la posición de estos en el mismo para 
ser intercambiados entre ellos en el arreglo. 
Este ciclo se repite mientras el indice de los números a la derecha del pivote ("i") sea
menor al indice de los números a la izquierda ("j"), pues significa que ambos indices han 
llegado a la posición del pivote y todos los números a la derecha son menores que el pivote
mientras que todos a la izquierda son mayores.

Después, el pivote se coloca en la posición correcta en el arreglo mandando a llamar nuevamente
la función "intercambiar" y enviando la posición original del pivote ("p") y la posición donde debe
colocarse ("j").

Finalmente, la función regresa la posición en el arreglo donde se encuentra el pivote seleccionado ("j").
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

Recibe: int *arr, dirección del arreglo ptr de memoria dinámica
		int i, posición en el arreglo de un número a intercambiar
		int j, posición en el arreglo de un número a intercambiar
		
Devuelve: void (No retorna valor explicito)

Observaciones: Haciendo uso de la variable "aux", la función intercambia los
números en la posición "i" y "j" del arreglo, asignando a la variable "aux" 
el valor del número en la posición "j", después a la posición "j" el número
en la posición "i" y finalmente a la posición "i" el valor de "aux".
*/
void intercambiar(int *arr, int i, int j){
	
	int aux;
	
	aux=arr[j];
	arr[j]=arr[i];
	arr[i]=aux;
	
	return;
}

