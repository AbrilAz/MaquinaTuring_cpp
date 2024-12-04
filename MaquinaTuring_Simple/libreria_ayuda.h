#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <stdlib.h>
#include <rlutil.h>
void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
struct nodo {
    int dato;
    struct nodo *liga;
};
struct nodo *crea() {
    struct nodo *paux;
    paux = (struct nodo *)malloc(sizeof(struct nodo));
    return paux;
}

int PILA_VACIA(struct nodo *TOPE) {
    int BAND;
    if (TOPE == NULL) {
        BAND = 1;
    } else {
        BAND = 0;
    }

    return BAND;
}
struct nodo *push(struct nodo *TOPE, int DATO) {
    struct nodo *q;
        q = crea();
        q->dato = DATO;
        q->liga = TOPE;
    return q;
}

struct nodo *pop(struct nodo *TOPE) {
	struct nodo *q;
    if (PILA_VACIA(TOPE)) {
        gotoxy (10,16);printf("Subdesbordamiento - Pila vacia\n");
    } else {
        q= TOPE;
        TOPE = TOPE->liga;
        free(q);
        return TOPE;
    }
   
}
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
void borrado(int x1, int x2, int y1, int y2){
	int i,j;
	for (j=y1; j<=y2; j++){
		for (i=x1; i<=x2; i++){
		 gotoxy(i,j); printf (" ");
		
	    }
	}
}

void verpila(struct nodo *TOPE){
    struct nodo *p;
    int i=0;
        p= TOPE;
        gotoxy(6, 15);printf("%c",24);
        gotoxy(6, 16);printf("TOPE");

        while(p!=NULL){
        	gotoxy(6+(i*4), 13);printf("%d", p->dato);
            i++;
            p= p->liga;
		}
		Sleep(1000);
        gotoxy(6+(i*4), 13);printf("  ");

}






void mensaje(){
    system("cls");
	margen(2,2,78,23);
	margen(15,3,50,5);
	gotoxy (17,4); printf ("MAQUINA DE TURING DE SIMPLE ");
}
void mensaje2(){
	printf("\n\n\n\tUna maquina de Turing es una 7- tupla M = (Q, E, s, b, T, F, &) donde:\n\tQ Es un conjunto finito de estados.\n\tE Es un alfabeto de entrada.\n\tT Es un alfabeto llamado alfabeto de la cinta.\n\ts Es el estado inicial.\n\tb Es el simbolo en blanco (y no esta en E ).\n\tF Es el conjunto de estados finales o de aceptacion.\n\t&: Q x T -> Q x T x { L, R} Es una funcion parcial que se llama\n\tfuncion de transicion.");
    printf("\n\n\tAsignatura: Teoria de automatas");
  	printf("\n\n\tPulse ENTER para continuar [_]\b\b");
    getchar();
}
void mensaje3(){
	printf("\n\n\n\t\tDefinicion de la maquina Turing 'Duplica cadenas'\n\n\t\tQ = { q0, q1, q2, q3, q4 }\n\t\tE = { 0, 1 }\n\t\tT = { 0, 1, 100, 3 }\n\t\tF = { q4 }\n\t\ts = q0");
   printf("\n\n\t\tDiagrama de transicion");
}
void mensaje4(){
	printf("\n\n\n\tTransiciones\n\n\t&(q0,0) = (q0,0,R)\n\t&(q0,1) = (q0,1,R)\n\t(q0,100) = (q1,3,L)\n\t&(q1,0) = (q1,0->E,L)\n\t&(q1,1) = (q1,1->E,L)\n\t&(q1,100) = (q2,100,R)\n\t&(q2,0) = (q2,0,R)\n\t&(q2,1) = (q2,1,R)\n\t&(q2,3) = (q3,3,R)\n\t&(q3,100) = (q3,E->1,R)\n\t&(q3,100) = (q3,E->0,R)\n\t&(q3,3) = (q4,3,-)");
}
void avance1 (int cabezal){
	gotoxy(6+(cabezal*4),11);printf("%c",24);
}
void avance2 (int cabezal){
    gotoxy(6+(cabezal*4),11);printf(" ");
}

void A1( ){
    circulo(4,19);
    gotoxy(6,20);printf("q0");
    grafico(1,9,17);
    gotoxy(15,17);printf("0,0,R");
	gotoxy(15,18);printf("1,1,R");

}
void A2(){
int i;
    circulo(4,19);
    gotoxy(6,20);printf("q0");
    for(i=0; i<10; i++){
    	gotoxy(10+i,20);printf("_");
	}
	circulo(20,19);
    gotoxy(22,20);printf("q1");
    gotoxy(11,21);printf("100,3,L");
}
void B1(){
    circulo(20,19);
    gotoxy(22,20);printf("q1");
    grafico(1,25,17);
    gotoxy(31,17);printf("0,0->E,R");
	gotoxy(31,18);printf("1,1->E,R");
}
void B2(){
	int i;
    circulo(20,19);
    gotoxy(22,20);printf("q1");
        for(i=0; i<10; i++){
    	gotoxy(26+i,20);printf("_");
	}
	circulo(36,19);
    gotoxy(38,20);printf("q2");
    gotoxy(26,21);printf("100,100,R");
}
void C1(){
    circulo(36,19);
    gotoxy(38,20);printf("q2");
    grafico(1,41,17);
    gotoxy(47,17);printf("0,0,R");
	gotoxy(47,18);printf("1,1,R");
}
void C2(){
	int i;
    circulo(36,19);
    gotoxy(38,20);printf("q2");
    for(i=0; i<10; i++){
    	gotoxy(42+i,20);printf("_");
	}
	circulo(52,19);
    gotoxy(54,20);printf("q3");
    gotoxy(43,21);printf("3,3,R");
}
void D1(){
    circulo(52,19);
    gotoxy(54,20);printf("q3");
    grafico(1,57,17);
    gotoxy(63,17);printf("100,E->0,R");
	gotoxy(63,18);printf("100,1->1,R");
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

