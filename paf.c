//Nombre:Esteban Mallea Sepulveda
//Rut: 19.172.524-7
//Profesor:Sergio Baltierra
//Fecha: 5 julio 2015

#include <stdio.h>

int main()
{

	FILE *archivo;
	int *puntero, *puntero2;
	int N, arreglo[100], arreglo2[100], i=0, p=1;
	int dif_1=0, dif_2=0, min_dif=0, aux=100;

	puntero=&arreglo[0];
	for (i = 0; i < 100; ++i)
	{
		*puntero=32;
		puntero++;
	}
	
	archivo=fopen("entrada.ent","r");
	
		if (archivo==NULL)
		{
			printf("Archivo no existe\n");
		}
		N=fgetc(archivo);
		N=N-48;				//cambio a entero del caracter

		puntero=&arreglo[0];		//asignaciones de memoria a los punteros
		puntero2=&arreglo2[0];

		for (i = 0; i < N*2; ++i) //N*2 para leer los espacios en blanco
		{
			*puntero=fgetc(archivo);

			if (*puntero==10 || *puntero==32)
			{
				*puntero=0;
			}
			if (*puntero!=0)  //traspaso de valores por punteros
			{
				*puntero=*puntero-48;
				*puntero2=*puntero;
				puntero2++;
			}
			puntero++;
		}
	fclose(archivo);
	
	// p representa el valor de corte de los sub-arreglos

	while(p<N){


		for (i = 0; i < p; ++i)			//sumas del primer sub-arreglo
		{
			puntero2=&arreglo2[i];
			dif_1=dif_1+(*puntero2);
			puntero2++;			
		}

		for (i = p; i < N; ++i)			//sumas del segundo sub-arreglo
		{	

			puntero=&arreglo2[i];
			dif_2=dif_2+(*puntero);
			puntero++;
		}

		min_dif = dif_1-dif_2;		//diferencia

		if (min_dif<0)				//aplicacion del valor absoluto
		{
			min_dif=min_dif*-1;
		}
		
		if (aux>min_dif)  			//almacenamiento de la menor diferencia
		{
			aux=min_dif;
		}

		//printf("minimas diferencias%d\n",min_dif );

		dif_2=0;
		dif_1=0;
		p++;
	}

	archivo=fopen("salida.sal","wb");  //impresion de la menor diferencia
		fprintf(archivo, "%d",aux );	
	fclose(archivo);


	//printf("esta es la minima diferencia %d\n",aux );

	return 0;
}