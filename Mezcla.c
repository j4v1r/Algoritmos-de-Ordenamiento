/*
Insercion.c
V 1.0 Marzo 2024
Grupo: 2CM2
Autores: Colunga Aguilar Javier Alejandro
		
Programa que lee una n cantidad de números y los escribe en un arreglo dinámico ptr,
después ejecuta el algoritmo de ordenamiento de Mezcla O(n log2n) que ordena estos 
números de menor a mayor. Finalmente, imprime estos números ordenados en un archivo
de texto y muestra el tiempo de ejecución del ordenamiento.

Compilación:
En el script.bat: 
gcc Mezcla.c -o mezcla
mezcla n<archivo.txt> nombrearchivosalida.txt					

*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

#define TRUE 1
#define FALSE 0

void mezclaPrin(int *A, int p, int r);
void mezcla(int *A,int p,int q,int r);


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
        
    }
    	
		for (i = 0; i < n; i++)
    scanf("%d", &ptr[i]);

  //*****************************************
  // Algoritmo a medir el tiempo
  //*****************************************
  // Inicia mediciÃ³n del tiempo
  t_inicio = clock();

  // Llamar al algoritmo
  mezclaPrin(ptr, 0, n - 1);

  // Termina mediciÃ³n del tiempo
  t_final = clock();

  // CÃ¡lculo del tiempo y enviar mensaje a salida estandar con la mediciÃ³n
  t_intervalo = (double)(t_final - t_inicio) / CLOCKS_PER_SEC;
  printf("\nTiempo medido: %.8f segundos.", t_intervalo);

  // Enviar a la salida estandar el arreglo final
  for (i = 0; i < n; i++)
    printf("\nptr[%d]=%d", i, ptr[i]);
		
	
	
	return 0;
}


/*
void mezclaPrin(int *A,int n)

Recibe: int *A, dirección del arreglo ptr de memoria dinámica
		int n, cantidad de números a ordenar 
		
Devuelve: void (No retorna valor explicito)

Observaciones: Si el incio del arreglo recibido es menor que el final de este entonces 
lo divide entre dos y manda a llamarse de nuevo dos veces, enviando el propio arreglo, 
el inicio ("p" para la pimera y "q+1" para la segunda, debido a que la división puede
no dar un número entero) y el final ("q" para la primera y "r" para la segunda) de 
cada mitad para volver a dividir cada mitad entre dos hasta llegar a un solo número 
por división. Además, manda a llamar a la función "mezcla" enviando el arreglo y su 
incio, mitad y final.
*/
void mezclaPrin(int *A , int p,int r)
{
	int q;
	if(p < r)
	{
		q=(p+r)/2;
		//printf("Llega a q %i", q);
		mezclaPrin(A, p, q);
		mezclaPrin(A, q+1, r);
		mezcla(A, p, q, r);
	}
	
	return;
}


/*
void  mezcla(int *A,int p, int q, int r)

Recibe: int *A, dirección del arreglo ptr de memoria dinámica
		int p, inicio del arreglo recibido
		int q, mitad del arreglo recibido
		int r, final del arreglo recibido
		
Devuelve: void (No retorna valor explicito)

Observaciones: Mezcla hace uso de un arreglo "arr" que tiene la longitud
de la unión de ambas mitades y un indice "k" que apunta a este mismo.
Mezcla se encarga de comparar los elementos del arreglo en la posición 
"i" y "j", copiando el menor de estos al arreglo auxiliar e incrementando
el valor del indice del número que se ha copiado así como el de "k".

Después de haber comparado y ordenado todos los números en el arreglo 
auxiliar se copian estos mismos al arreglo original desde la posición del
inicio de la primera mitad hasta el final de la segunda, marcando el valor
de k como el del incio de la primera mitad.
*/
void mezcla(int *A,int p,int q,int r)
{
int l=r-p+1, i=p, j=q+1;
int k;
int* arr;
arr = malloc(l*sizeof(int));

for(k=0;k<=l-1; k++){
	if(i<=q && j<=r){
		if(A[i]<A[j]){
			arr[k]=A[i];
			i++;
		}else{
			arr[k]=A[j];
			j++;
		}
	}else if(i<=q){
		arr[k]=A[i];
		i++;
	}else{
		arr[k]=A[j];
		j++;
	}
}
k=p;
for(i=0; i<=l-1; i++){
	A[k]=arr[i];
	k++;
}
return;
}




