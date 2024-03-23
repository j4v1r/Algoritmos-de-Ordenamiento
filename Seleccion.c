/*
Insercion.c
V 1.0 Marzo 2024
Grupo: 2CM2
Autores: Colunga Aguilar Javier Alejandro
		
Programa que lee una n cantidad de n�meros y los escribe en un arreglo din�mico ptr,
despu�s ejecuta el algoritmo de ordenamiento de Selecci�n O(n^2) que ordena estos 
n�meros de menor a mayor. Finalmente, imprime estos n�meros ordenados en un archivo
de texto y muestra el tiempo de ejecuci�n del ordenamiento.

Compilaci�n:
En el script.bat: 
gcc Seleccion.c -o seleccion
seleccion n<archivo.txt> nombrearchivosalida.txt					

*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define TRUE 1
#define FALSE 0

void seleccion(int *A, int n);

int main(int nums, char* argv[]){
	//Variables para la medición de tiempos    
    clock_t t_inicio, t_final;
    double t_intervalo;

	//Variables para el algoritmo
	int k,j,i,n,p;
	int *ptr;
	
	//Recirbir por argumento el tamanio de n y el valor a buscar
	if(nums!=2)
	{
		printf("\nIndique el tamanio de n - Ejemplo: [user@equipo]$ %s 100\n",argv[0]);
		exit(1);
	}
	
	//Tomar el argumento del main
	n=atoi(argv[1]); //n
	
	//Apartar memoria para n números  enteros
	ptr=malloc(n*sizeof(int));
	if(ptr == NULL)
	{
		printf("\nError al intentar reservar memoria para %d elementos\n",n);		
		exit(1);
	}	
	
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
	seleccion(ptr,n);
	
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
	
	return 0;
}


/*
void seleccion(int *A,int n)

Recibe: int *A, direcci�n del arreglo ptr de memoria din�mica
		int n, cantidad de n�meros a ordenar 
		
Devuelve: void (No retorna valor explicito)

Observaciones: El algoritmo se encarga de recorrer todos los n�meros del arreglo
y encontrar el menor, despu�s intercambia este n�mero con el que se encuentra 
en la primera posici�n. Despu�s del primer ciclo revisa los n�meros del arreglo 
exceptuando aquellos de las posiciones que ya han sido colocadas en el orden 
correcto, los n�meros menores que se encuentren ser�n colocados en la posici�n 
siguiente del que fue reordenado en el ciclo anterior. De esta manera en el 
primer ciclo se cambiara a la posici�n 0 del arreglo, el segundo ciclo a la 
posici�n 1, eltercero a la 2, etc.
*/
void seleccion(int *A, int n)
{
	int i,j,p,k,aux;
	
	for(k=0;k<=(n-2);k++)
	{
		p=k;
		for(i=(k+1);i<=(n-1);i++)
		{
			if(A[i]<A[p])
			{
				p=i;
			}
			
		aux = A[p];
		A[p] = A[k];
		A[k] = aux;	
		}
		
	}
	return;
}


