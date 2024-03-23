/*
Insercion.c
V 1.0 Marzo 2024
Grupo: 2CM2
Autores: Colunga Aguilar Javier Alejandro
		
Programa que lee una n cantidad de n�meros y los escribe en un arreglo din�mico ptr,
despu�s ejecuta el algoritmo de ordenamiento Shell de orden de complejidad variante
que ordena estos n�meros de menor a mayor. Finalmente, imprime estos n�meros 
ordenados en un archivo de texto y muestra el tiempo de ejecuci�n del ordenamiento.

Compilaci�n:
En el script.bat: 
gcc Shell.c -o shell
shell n<archivo.txt> nombrearchivosalida.txt					

*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

#define TRUE 1
#define FALSE 0


void shell(int *arr, int n);

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
		shell(ptr,n);
	
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
void shell(int *arr,int n)

Recibe: int *arr, direcci�n del arreglo ptr de memoria din�mica
		int n, cantidad de n�meros a ordenar 
		
Devuelve: void (No retorna valor explicito)

Observaciones: Shell retoma el m�todo de Inserci�n pero en pos de eficientar 
el mismo se decide agrandar la cantiddd de posciones que intercambian los 
n�meros comparados. Para esto se divide inicialmente el arreglo a la mitad, 
ayudandose de la funci�n "trunc()" para asegurarse que la cantidad de n�meros 
en cada mitad sea entero. 
Despu�s de esto se comparan los n�meros en las mismas posiciones de cada mitad
(i-k, para la primera mitad e i para la segunda) y si el n�mero que se encuentra 
en la primera mitad es mayor que el que de la segunda entonces se intercambian 
y el proceso de comparaci�n e intercambio continua con los siguientes n�meros, 
si al finalizar de comparar todos los n�meros de las mitades no ha habido un 
cambio entonces se detiene el ciclo de comparaci�n y se dividen los intervalos 
de nuevo en 2, repitiendo todo el proceso anterior hasta que las mitades sean 
de un solo n�mero, donde se realiza una Inserci�n est�ndar.
*/
void shell(int *arr, int n){
	 
	int k=trunc(n/2);
	
	while(k>=1){
		int b=1;
		while(b!=0){
			b=0;
			for(int i=k;i<=(n-1); i++){
				if(arr[i-k]>arr[i]){
					int aux=arr[i];
					arr[i]=arr[i-k];
					arr[i-k]=aux;
					b+=1;
				}
			}
		}
		k=trunc(k/2);
	}
		
	return;
	
}
