#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// http://www.trsampaio.com/2014/08/31/calculo-numerico-computacional-decomposicao-lu/
// Fonte: http://www.trsampaio.com/
#define n 7000
 
void show_matrix(float *mat){
    int i,j;
    for(i=0;i<n;i++){
        printf("|");
        for(j=0;j<n;j++){
            printf(" %.2f",mat[(i*n)+j]);
        }
        printf(" |\n");
    }    
}

void preencheMatriz(float *mat) {
    srand( (unsigned)time(NULL) );

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            mat[(i*n)+j] = rand()%100000;
        }
    }
}
 
void gauss(float *mat){
    /*
    m21=m21/m11
    m31=m31/m11
    m41=m41/m11
    */
    int i,j;
    float *M = (float *)calloc(n*n, sizeof(float));
    float *aux = (float *)malloc(n*n*sizeof(float));
    preencheMatriz(aux);
    //Calculando os multiplicadores da Gauss
    //Movimenta a coluna
    for(j=0;j<n;j++){      
        //Movimenta a linha
        for(i=j+1;i<n;i++){
            if(aux[(i*n)+j]!=0)
             {
                M[(i*n)+j]=aux[(i*n)+j]/aux[(j*n)+i];
                //multiplico a linha do multiplicar por -(multiplicador)
                int c=0;
               
                //Movimenta a coluna
                for(c=j;c<n;c++){
                    aux[(i*n)+c]=aux[(i*n)+c]+aux[(j*n)+c]*(-1*(M[(i*n)+j]));
                }      
            }      
            //system("pause");
        }//Todos os multiplicadores da coluna j estão definidos
             
    }
    printf("\n\n*********RESULTADO FINAL**********\n");
    for(i=0;i<n;i++) M[(i*n)+i]=1;
    /*printf("\n----Matriz L----\n");
    show_matrix(M);
   
    printf("\n----Matriz U----\n");
    show_matrix(aux);*/
}

 
int main(){
    float *A = (float *)malloc(n*n*sizeof(float));
   
    preencheMatriz(A);
    /*printf("***Seja A a matriz original***\n");
    printf("----Matriz A----\n");
    show_matrix(A);*/
   
    gauss(A);
   
    system("pause");
    return 0;  
}