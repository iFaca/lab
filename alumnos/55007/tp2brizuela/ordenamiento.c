#include "histograma.h"


int* ordenar(int valor , int* ptr ){
	int i,j,aux;
		
	if(valor==1){//de menor a mayor
		for(i=0; i<(20-1); i++){
			for (j=i+1; j<20; j++){
				if(ptr[j]< ptr[i]){
					aux=ptr[j];
					ptr[j]=ptr[i];
					ptr[i]=aux;
					
				}				
			}	
		}	
	}
	if (valor ==0){//de mayor a menor
		for(i=0; i<(20-1); i++){
               		for (j=i+1; j<20; j++){
                        	if(ptr[j]>ptr[i]){
                                	aux=ptr[j];
                                        ptr[j]=ptr[i];
                                        ptr[i]=aux;
					
                               	}
                       	}
               	}
       } 			
	
return ptr;
	

}
