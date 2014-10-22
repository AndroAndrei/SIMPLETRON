/******************UTILS-H**********************/
//Definiciones para el lenguaje maquina LMS

//Entrada y Salida
#define READ 10  //leer datos de la terminal y colocarlos en memoria
#define WRITE 11 //Escribir datos en la terminal

//Carga y almacenamiento
#define LOAD 20  //cargar de memoria al registro acumulador
#define STORE 21 //almacenar en memoria datos en el acumulador

//Operaciones aritmeticas
#define ADD 30 //Suma aritmetica resulatado queda en el acumulador
#define SUB 31 //Resta aritmetica resultado queda en el acumulador
#define DIV 32 //Division aritmetica
#define MUL 33 //Multiplicacion 

//Operaciones de transferencia de control
#define BRANCH 40 //Se desvia a una posicion especifica de memoria
#define BRANCHNEG 41 //desviarse si dato en el acumulador es negativo
#define BRANCHZERO 42 //desviarse si el acumulador es cero
#define HALT 43 //detener 
#define CENTINELA -99999

//Memoria de la maquina simple SIMPLETRON 
int memoria[100];
//Registros especiales de la maquina SIMPLETRON 
int acumulador=0;
int pinstruccion=0;
int reginstruccion=0;
int opcode=0;
int operando=0;
