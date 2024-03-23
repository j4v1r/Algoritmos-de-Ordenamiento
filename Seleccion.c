/*
Insercion.c
V 1.0 Marzo 2024
Grupo: 2CM2
Autores: Colunga Aguilar Javier Alejandro
		
Programa que lee una n cantidad de n鷐eros y los escribe en un arreglo din醡ico ptr,
despu閟 ejecuta el algoritmo de ordenamiento de Selecci髇 O(n^2) que ordena estos 
n鷐eros de menor a mayor. Finalmente, imprime estos n鷐eros ordenados en un archivo
de texto y muestra el tiempo de ejecuci髇 del ordenamiento.

Compilaci髇:
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
	//Variables para la medici贸n de tiempos    
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
	
	//Apartar memoria para n n煤meros  enteros
	ptr=malloc(n*sizeof(int));
	if(ptr == NULL)
	{
		printf("\nError al intentar reservar memoria para %d elementos\n",n);		
		exit(1);
	}	
	
	//Leer de la entrada estandar los n valores y colocarlos en el arreglo de n煤meros
	for(i=0;i<n;i++){
	
		scanf("%d",&ptr[i]);
	
	}
	
	//*****************************************  
	//Algoritmo a medir el tiempo
	//*****************************************
	//Inicia medici贸n del tiempo
	t_inicio = clock();
	
	//Llamar al algoritmo
	seleccion(ptr,n);
	
	//Termina medici贸n del tiempo	
	t_final = clock();
	
	//C谩lculo del tiempo y enviar mensaje a salida estandar con la medici贸n  
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

Recibe: int *A, direcci髇 del arreglo ptr de memoria din醡ica
		int n, cantidad de n鷐eros a ordenar 
		
Devuelve: void (No retorna valor explicito)

Observaciones: El algoritmo se encarga de recorrer todos los n鷐eros del arreglo
y encontrar el menor, despu閟 intercambia este n鷐ero con el que se encuentra 
en la primera posici髇. Despu閟 del primer ciclo revisa los n鷐eros del arreglo 
exceptuando aquellos de las posiciones que ya han sido colocadas en el orden 
correcto, los n鷐eros menores que se encuentren ser醤 colocados en la posici髇 
siguiente del que fue reordenado en el ciclo anterior. De esta manera en el 
primer ciclo se cambiara a la posici髇 0 del arreglo, el segundo ciclo a la 
posici髇 1, eltercero a la 2, etc.
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


