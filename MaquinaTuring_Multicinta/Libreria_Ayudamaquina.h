#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <stdlib.h>
#include <rlutil.h>
#define A 18
void grafico (int n,int c,int f){
    int i;
    
	gotoxy (c,f); printf ("%c%c%c",218,196,196);
	gotoxy (c,f+1); printf ("%c",179);
	gotoxy (c,f+2); printf ("%c%c%c",192,196,196);
	for (i=0; i<n-1; i++){
	    gotoxy(c+(i*4)+3,f); printf ("%c%c%c%c",196,194,196,196);
		gotoxy(c+(i*4)+3,f+1);printf (" %c",179);
		gotoxy(c+(i*4)+3,f+2);printf ("%c%c%c%c",196,193,196,196);
	}
	gotoxy(c+(i*4)+3,f);printf ("%c%c",196,191);
	gotoxy(c+(i*4)+3,f+1); printf(" %c",179);
	gotoxy (c+(i*4)+3,f+2); printf ("%c%c",196,217);
}

 int margen(int x1, int y1, int x2, int y2){
	int x,y,i;
	x=x1;
	gotoxy(x1-1,y1); printf("%c",201);
	gotoxy(x1-1,y2); printf("%c",200);
	for(x1; x1<=x2; x1++){
 		gotoxy(x1,y1); printf("%c",205);
 		gotoxy(x1,y2); printf("%c",205);

	}
	gotoxy(x1,y1); printf("%c",187);
	gotoxy(x1,y2); printf("%c",188);
	y=y1+1;
	for(y; y<=(y2-1); y++){
		gotoxy(x-1,y); printf("%c",186);
 		gotoxy(x1,y); printf("%c",186);
	}
}

void circulo (int c,int f){
	int i;

	gotoxy (c,f); printf ("%c%c%c%c",218,196,196,196);
	gotoxy (c,f+1); printf ("%c",179);
	gotoxy (c,f+2); printf ("%c",179);
	gotoxy (c,f+3); printf ("%c%c%c",192,196,196);

	
	gotoxy(c+4,f);printf ("%c%c",196,191);
	gotoxy(c+4,f+1); printf(" %c",179);
	gotoxy(c+4,f+2); printf(" %c",179);
	gotoxy (c+3,f+3); printf("%c%c%c",196,196,217);
	
}


void mensaje(){
    system("cls");
	margen(2,2,78,29);
	margen(15,3,58,5);
	gotoxy (17,4); printf ("MAQUINA DE TURING DE MULTICINTA");
}
void mensaje2(){
	printf("\n\n\n\tUna maquina de Turing es una 7- tupla M = (Q, E, s, b, T, F, &) donde:\n\tQ Es un conjunto finito de estados.\n\tE Es un alfabeto de entrada.\n\tT Es un alfabeto llamado alfabeto de la cinta.\n\ts Es el estado inicial.\n\tb Es el simbolo en blanco (y no esta en E ).\n\tF Es el conjunto de estados finales o de aceptacion.\n\t&: Q x T -> Q x T x { L, R} Es una funcion parcial que se llama\n\tfuncion de transicion.");
    printf("\n\n\tAsignatura: Teoria de automatas");
  	printf("\n\n\tAlumna: Abril Azeneth Quintas Rojas");
  	printf("\n\n\tPulse ENTER para continuar [_]\b\b");
    getchar();
}
void mensaje3(){
	printf("\n\n\n\tDefinicion de la maquina Turing 'Suma de numeros binarios'\n\tQ = { q0, q1, q2, q3 }\t\tE = { 0, 1 }\n\tT = { 0, 1, 100 }\t\tF = { q3 }\n\ts = q0");
    printf("\n\n\tDiagrama de transicion");
}
void mensaje4(){
	printf("\n\n\n\tTransiciones\n\n\t&(q0,(0,0,100,100))= (q0,(0,0,100,100),(R,R,R,S))\n\t&(q0,(0,1,100,100))= (q0,(0,1,100,100),(R,R,R,S))\n\t&(q0,(1,0,100,100)) = (q0,(1,0,100,100),(R,R,R,S))\n\t&&(q0,(1,1,100,100)) = (q0,(1,1,100,100),(R,R,R,S))\n\t&(q0,(100,100,100,100)) = (q1,(100,100,100,100),(L,L,L,S))\n\t&(q1,(0,0,100,100))= (q1,(0,0,0,100),(L,L,L,S))\n\t&(q1,(0,1,100,100)) = (q1,(0,1,1,100),(L,L,L,S))\n\t&(q1,(1,0,100,100)) = (q1,(1,0,1,100),(L,L,L,S))\n\t&(q1,(1,1,100,100)) = (q2,(1,1,0,1),(L,L,L,S))\n\t&(q2,(0,0,100,1)) = (q1,(0,0,1,100),(L,L,L,S))\n\t&(q2,(0,1,100,1)) = (q2,(0,1,0,1),(L,L,L,S))\n\t&(q2,(1,0,100,1)) = (q2,(1,0,0,1),(L,L,L,S))\n\t&(q2,(1,1,100,1)) = (q2,(1,1,1,1),(L,L,L,S))\n\t&(q1,(100,100,100,100)) = (q3,(100,100,100,100),(S,S,S,S))\n\t&(q2,(100,100,100,1)) = (q3,(100,100,1,100),(S,S,L,S))");
}
void avance1 (int cabezal){
	gotoxy(6+(cabezal*4),11);printf("%c",24);
}
void avance2 (int cabezal){
    gotoxy(6+(cabezal*4),11);printf(" ");
}
void llenar(int Vector[A], int pos){
	int i=1,valor;
	gotoxy(6,pos);printf("b");
    do{
    	gotoxy(6+(i*4),pos);scanf("%d", &valor);
		Vector[i]= valor;
		i++;
	}while (valor>=0 && valor <=1 );
	for (i=0; i<A; i++){
	    if (Vector[i]!= 0 && Vector[i]!=1){
	    	Vector[i]=100;
	    	gotoxy(6+(i*4),pos);printf("b");
	    }
	}
}
void lleno(int Vector[A], int pos){
	int i;
	gotoxy(6,pos);printf("b");
	for (i=0; i<A; i++){
	    if (Vector[i]==100){
	    	gotoxy(6+(i*4),pos);printf("b");
	    }
	}
}
void A1( ){
	gotoxy(2,20); printf("->");
    circulo(4,19);
    gotoxy(6,20);printf("q0");
    grafico(1,9,17);
    gotoxy(3,13);printf("(0,0,100,100),(0,0,100,100),(R,R,R,S)");
    gotoxy(3,14);printf("(0,1,100,100),(0,1,100,100),(R,R,R,S)");
    gotoxy(3,15);printf("(1,0,100,100),(1,0,100,100),(R,R,R,S)");
	gotoxy(3,16);printf("(1,1,100,100),(1,1,100,100),(R,R,R,S)");

}
void A2(){
int i;
	circulo(4,19);
    gotoxy(6,20);printf("q0");
    for(i=0; i<27; i++){
    	gotoxy(10+i,20);printf("_");
	}
	circulo(36,19);
    gotoxy(38,20);printf("q1");
	gotoxy(9,21);printf("(100,100,100,100),(L,L,L,S)");
}
void B1(){
	circulo(36,19);
    gotoxy(38,20);printf("q1");
    grafico(1,41,17);
    gotoxy(41,12);printf("(0,0,100,100),(0,0,0,100),(L,L,L,S)");
	gotoxy(41,13);printf("(0,1,100,100)(0,1,1,100),(L,L,L,S)");
	gotoxy(41,14);printf("(1,0,100,100),(1,0,1,_),(L,L,L,S)");
}
void B2(){
	int i;
	circulo(36,19);
    gotoxy(38,20);printf("q1");
        for(i=0; i<27; i++){
    	gotoxy(42+i,20);printf("_");
	}
	circulo(68,19);
    gotoxy(70,20);printf("q2");
    gotoxy(38,23);printf("(1,1,100,100),(1,1,0,1),(L,L,L,S)");
}
void C1(){
	circulo(68,19);
    gotoxy(70,20);printf("q2");
    grafico(1,73,17);
    gotoxy(47,16);printf("(0,1,100,1),(0,1,0,1),(L,L,L,S)");
	gotoxy(47,17);printf("(1,0,100,1),(1,0,0,1),(L,L,L,S)");
	gotoxy(47,18);printf("(1,1,100,1),(1,1,1,1),(L,L,L,S)");
}
void C2(){
	int i;
	circulo(68,19);
    gotoxy(70,20);printf("q2");
    for(i=0; i<3; i++){
    	gotoxy(70,23+i);printf("|");
	}
	for(i=0; i<12; i++){
		gotoxy(58+i,25);printf("_");

	}
	rlutil::setColor(rlutil::RED );circulo(52,24);
    gotoxy(54,25);printf("q3");rlutil::setColor(rlutil::WHITE );
    gotoxy(40,28);printf("(100,100,100,1),(100,100,1,100),(S,S,L,S)");
}

void D2(){
	int i;
    circulo(52,19);
    gotoxy(54,20);printf("q3");
    for(i=0; i<10; i++){
    	gotoxy(58+i,20);printf("_");
	}
	circulo(68,19);
    gotoxy(70,20);printf("q4");
    gotoxy(58,21);printf("100,3->E,-");
}

