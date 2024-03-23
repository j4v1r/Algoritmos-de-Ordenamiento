/*
Insercion.c
V 1.0 Marzo 2024
Grupo: 2CM2
Autores: Colunga Aguilar Javier Alejandro
		
Programa que lee una n cantidad de números y los escribe en un arreglo dinámico ptr,
después ejecuta el algoritmo de ordenamiento de Inserción O(n^2) que ordena estos 
números de menor a mayor. Finalmente, imprime estos números ordenados en un archivo
de texto y muestra el tiempo de ejecución del ordenamiento.

Compilación:
En el script.bat: 
gcc Insercion.c -o insercion
insercion n<archivo.txt> nombrearchivosalida.txt					

*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define TRUE 1
#define FALSE 0


void insercion(int *arr, int n);

int main(int nums, char* argv[]){
	
	
	//Variables para medir el tiempo
	clock_t t_inicio, t_final;
    double t_intervalo;
	
	int* ptr; //Guarda la dirección del bloque creado
	int n, i, j;
	
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
		insercion(ptr,n);
	
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
void insercion(int *arr,int n)

Recibe: int *arr, dirección del arreglo ptr de memoria dinámica
		int n, cantidad de números a ordenar 
		
Devuelve: void (No retorna valor explicito)

Observaciones: Inserción se ocupa de comparar un número del arreglo, comenzando desde
la izquierda (la posción [0]), con los que se encuentran a la izquierda de este hasta 
encontrar un número menor o llegar al final del arreglo, se inserta en la siguiente 
posición del número menor a este o al incio del arreglo, desplazando a la derecha 
todos los números mayores comparados anteriormente. Este ciclo continua hasta que el 
último número del arreglo haya sido comparado con todos los demás. 
*/

void insercion(int *arr, int n){
	 
	int i, j, aux;
	
	for(i=0;i<=n-1;i++ ){
		j=i;
		aux=arr[i];
		while(j>0 && (aux<arr[j-1])){
			arr[j]=arr[j-1];
			j--;
		}
		arr[j]=aux;
	}
		
	return;
	
}
