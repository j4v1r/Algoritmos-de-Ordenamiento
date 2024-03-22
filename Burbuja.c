/*
Burbuja.c
V 1.0 Marzo 2024
Grupo: 2CM2
Autores: Colunga Aguilar Javier Alejandro
		
Programa que lee una n cantidad de números y los escribe en un arreglo dinámico ptr,
después ejecuta el algoritmo de ordenamiento de Burbuja O(n^2) que ordena estos 
números de menor a mayor. Finalmente, imprime estos números ordenados en un archivo
de texto y muestra el tiempo de ejecución del ordenamiento.

Compilación:
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
		burbuja(ptr,n);
	
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
void burbuja(int *arr,int n)
Recibe: int *arr, dirección del arreglo ptr de memoria dinámica
		int n, cantidad de números a ordenar 
Devuelve: void (No retorna valor explicito)
Observaciones: Funciona tal que compara dos números adyacentes 
del arreglo ptr, si el primero es mayor que el segundo estos
intercambian posición entre ellos, así hasta llegar al último 
par de números. 
Este ciclo se repite tantas veces como números a ordenar, sin 
embargo, apartir del segundo ciclo deja de compararse un elemento
final del arreglo más, de tal manera que los números finales que 
dejan de compararse se determinan por c-1, siendo c el ciclo en 
el que se encuentra el programa.
Finalmente, para evitar hacer ciclos de comparación innecesarios
cuando el arreglo ya se encuentra ordenado, se agrega una variable
booleana nombrada "cambios" la cual asegura que durante el ciclo
haya habido al menos un cambio de posición entre elementos y por
lo tanto aún no está ordenado, de lo contrario finaliza el bucle 
y el programa, pues el arreglo ya está ordenado.
*/
void burbuja(int *arr, int n){
	 
	int i=0, j, aux;
	//Variable que determina si hubo cambios en el arreglo
	bool cambios = true;
	
	/*Bucle while que asegura la repetición de ciclos siempre que
	todos los números adyacentes hayan sido comparados y que haya 
	habido mínimo un cambio*/
	while(i<=n-2 && cambios!=false){
		//La variable "cambios" con valor "false" indica que no ha habido cambios
		cambios=false;
		for(j=0; j<=(n-2)-i; j++){
			/*Si el primero es mayor que el segundo entonces:*/
			if(arr[j]>arr[j+1]){
				//La variable "aux" toma el valor del segundo número
				aux=arr[j];
				//La primera posición toma el valor del número en la segunda
				arr[j]=arr[j+1];
				//La segunda posición toma el valor del número en "aux"
				arr[j+1]=aux;
				//Ha habido un cambio, por lo que cambios cambia a "true" 
				cambios=true;
			}
		}
		//El aumento de la variable "i" indica la finalización de un ciclo
		i+=1;
	}
		
	return;
	
}
