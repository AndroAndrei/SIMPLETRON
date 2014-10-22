/*PROGRAMA DE SIMULACION DE UNA MAQUINA SIMPLE
SIMPLETRON SECCION ESPECIAL DEL LIBRO COMO 
PROGRAMAR EN C/C++ DE LOS PROF. H.DEITEL Y P.DEITEL
***********************************************
VERSION 0.1 ELABORADA POR LENIN ROJAS
AKA NINJAVASCRIPT
***********************************************/

#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

void LimpiarMemoria(int mem[]); //Establecer la memoria con valores x defecto a cero
void VolcarMemoria(int mem[],int *,int *,int *,int *,int *);  //volcado de memoria en pantalla para ver el etado de los registros
void ImprimirBienvenida(void);  //Mensaje de Bienvenida al simulador de la maquina SIMPLETRON
void CargarBanco_M(int,int,int mem[]);//Cargar un banco parcial de la memoria
void Ejecutar(int mem[],int *,int *,int *,int *,int *); //Ejecutar las instrucciones almacenadas en la memoria

int main()
{
  int i=0,pcodigo=0;
  
  LimpiarMemoria(memoria);
  ImprimirBienvenida();
  printf("\nEstado de la memoria y de los registros ante de la carga del programa\n");
  VolcarMemoria(memoria,&acumulador,&pinstruccion,&reginstruccion,&opcode,&operando);
  
  //Carga del programa en la memoria
  while(i < 100)
  {
      do
      {
         printf("%.2d ? ",i);
         scanf("%d",&pcodigo);
         if(pcodigo == CENTINELA)
         {
           break;
         }
      }while((pcodigo <= -9999) || (pcodigo >= 9999));
      if(pcodigo == CENTINELA)
      {
        break;
      }
      memoria[i] = pcodigo;
      ++i;   
  }
  system("clear");
  printf("\nEstado de la memoria y de los registros despues de la carga del programa\n");
  VolcarMemoria(memoria,&acumulador,&pinstruccion,&reginstruccion,&opcode,&operando);
  Ejecutar(memoria,&acumulador,&pinstruccion,&reginstruccion,&opcode,&operando);
  //VolcarMemoria(memoria,&acumulador,&pinstruccion,&reginstruccion,&opcode,&operando);
}

void LimpiarMemoria(int mem[])
{
  int i;
  
  for(i=0;i < 100; i++)
  {
    mem[i] = 0;
  }
}

void VolcarMemoria(int mem[],int *acu,int *cp,int *ri,int *oc,int *op)
{
  int i,j;
  
  printf("REGISTROS:\n");
  printf("acumulador:");
  printf("\t%.4d\n",*acu);
  printf("cinstruccion:");
  printf("\t%2.2d\n",*cp);
  printf("reginstruccion:");
  printf("\t%.4d\n",*ri);
  printf("opcode:");
  printf("\t%2.2d\n",*oc);
  printf("operando:");
  printf("\t%2.2d\n",*op);
  printf("MEMORY:\n");
  for(i=0;i<10;i++)
  {
    printf("\t%d",i);
  }
  printf("\n");
  for(j=0;j<100;j += 10)
  {
    CargarBanco_M(j,j+10,mem);
    printf("\n");
  }
  printf("\n");
}

void ImprimirBienvenida(void)
{
   printf("\t\t\t*** Bienvenido a Simpletron! ***\n");
   printf("\t\t\t*** Porfavor Introduce tu programa ***\n");
   printf("\t\t\t*** una instruccion a la vez  ***\n");
   printf("\t\t\t*** Yo mostrare la direccion de memoria ***\n");
   printf("\t\t\t*** un signo de interrogacion (?) ***\n");
   printf("\t\t\t*** Luego tu introduces la palabra de codigo ***\n");
   printf("\t\t\t*** teclea el centinela -99999 para termiar ***\n");
   printf("\t\t\t*** la entrada de tu programa ***\n");

}

void CargarBanco_M(int linf,int lsup,int mem[])
{
  int i,bandera=1;
  
  for(i = linf;i < lsup; i++)
  {
     if(bandera)
      {
        printf("%2d",linf);
        printf("\t%+4.4d",mem[i]);
        bandera = 0;
      }
      else
      {
        printf("\t%+4.4d",mem[i]);
      }  
  }     
  
}

void Ejecutar(int mem[],int *acu,int *cp,int *ri,int *oc,int *op)
{
  *ri=1;
  
  while(*ri)
  {
    *ri = mem[*cp];
    *oc = *ri/100;
    *op = *ri%100;
    
    switch(*oc)
    {
      case 10:
             printf("\n? ");
             scanf("%d",&mem[*op]);
             ++(*cp);
             break;
      case 11:
             printf("\npos-memoria->%d: %+.4d\n",*op,mem[*op]);
             ++(*cp);
             break;
      case 20:
             *acu = mem[*op];
             ++(*cp);
             //*ri = 0;
             break;
      case 21:
             mem[*op] = *acu;
             ++(*cp);
             break;
      case 30:
             *acu += mem[*op];
             ++(*cp);
             break;
      case 31:
             *acu -= mem[*op];
             ++(*cp);
             break;
      case 32:
             if(mem[*op] != 0)
             {
               *acu/mem[*op];
               ++(*cp);
             }
             else
             {
               printf("ERROR:Division por cero\n\n");
               *ri = 0;
             }
             break;
      case 33:
             *acu * mem[*op];
             ++(*cp);
             break;
      case 40:
             *cp = *op;
             break;
      case 41:
              if(*acu < 0)
              {
                *cp = *op;
              }
              ++(*cp);
              break;
      case 42:
              if(*acu == 0)
              {
                *cp = *op;
              }
              ++(*cp);
              break;
      case 43:
             printf("\nEjecucion de simpletron terminada\n\n");
             VolcarMemoria(memoria,&acumulador,&pinstruccion,&reginstruccion,&opcode,&operando);
             ++(*cp);
             *ri=0;
             break;
      default:
             break;
            
    }
    
  }
  

}
