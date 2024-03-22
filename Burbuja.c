/*
Burbuja.c
V 1.0 Marzo 2024
Grupo: 2CM2
Autores: Colunga Aguilar Javier Alejandro
		
Programa que lee una n cantidad de n�meros y los escribe en un arreglo din�mico ptr,
despu�s ejecuta el algoritmo de ordenamiento de Burbuja O(n^2) que ordena estos 
n�meros de menor a mayor. Finalmente, imprime estos n�meros ordenados en un archivo
de texto y muestra el tiempo de ejecuci�n del ordenamiento.

Compilaci�n:
En el script.bat: 
gcc Burbuja.c -o burbuja
burbuja n<archivo.txt> nombrearchivosalida.txt					
*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include <stdbool.h>

#define TRUE 1
#define FALSE 0


void burbuja(int *arr, int n);

int main(int nums, char* argv[]){
	
	
	//Variables para medir el tiempo
	clock_t t_inicio, t_final;
    double t_intervalo;
	
	int* ptr; //Guarda la direcci�n del bloque creado
	int n, i, j;
	
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
		burbuja(ptr,n);
	
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
void burbuja(int *arr,int n)
Recibe: int *arr, direcci�n del arreglo ptr de memoria din�mica
		int n, cantidad de n�meros a ordenar 
Devuelve: void (No retorna valor explicito)
Observaciones: Funciona tal que compara dos n�meros adyacentes 
del arreglo ptr, si el primero es mayor que el segundo estos
intercambian posici�n entre ellos, as� hasta llegar al �ltimo 
par de n�meros. 
Este ciclo se repite tantas veces como n�meros a ordenar, sin 
embargo, apartir del segundo ciclo deja de compararse un elemento
final del arreglo m�s, de tal manera que los n�meros finales que 
dejan de compararse se determinan por c-1, siendo c el ciclo en 
el que se encuentra el programa.
Finalmente, para evitar hacer ciclos de comparaci�n innecesarios
cuando el arreglo ya se encuentra ordenado, se agrega una variable
booleana nombrada "cambios" la cual asegura que durante el ciclo
haya habido al menos un cambio de posici�n entre elementos y por
lo tanto a�n no est� ordenado, de lo contrario finaliza el bucle 
y el programa, pues el arreglo ya est� ordenado.
*/
void burbuja(int *arr, int n){
	 
	int i=0, j, aux;
	//Variable que determina si hubo cambios en el arreglo
	bool cambios = true;
	
	/*Bucle while que asegura la repetici�n de ciclos siempre que
	todos los n�meros adyacentes hayan sido comparados y que haya 
	habido m�nimo un cambio*/
	while(i<=n-2 && cambios!=false){
		//La variable "cambios" con valor "false" indica que no ha habido cambios
		cambios=false;
		for(j=0; j<=(n-2)-i; j++){
			/*Si el primero es mayor que el segundo entonces:*/
			if(arr[j]>arr[j+1]){
				//La variable "aux" toma el valor del segundo n�mero
				aux=arr[j];
				//La primera posici�n toma el valor del n�mero en la segunda
				arr[j]=arr[j+1];
				//La segunda posici�n toma el valor del n�mero en "aux"
				arr[j+1]=aux;
				//Ha habido un cambio, por lo que cambios cambia a "true" 
				cambios=true;
			}
		}
		//El aumento de la variable "i" indica la finalizaci�n de un ciclo
		i+=1;
	}
		
	return;
	
}
