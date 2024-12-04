#include "ayuda.h"

#define A 18
main(){
	int sino,i,j,cabezal,estado,valor,Vector[A];
    mensaje();mensaje2();mensaje();mensaje3();
    A1();A2();B1();B2();C1();C2();D1();D2();
    printf("\n\n\t\t");system("pause");
    mensaje();mensaje4();
    printf("\n\n\t\t");system("pause");

    do{
       struct nodo *TOPE = NULL, *p;
       mensaje();
       for (i=0; i<A; i++){
	     Vector[i]=100;
	   }
    gotoxy (7,7); printf ("Ingresa la cadena binaria a duplicar");
	grafico(18,4,8);
    gotoxy(6,9);printf("b");
    i=1;
    do{
    	gotoxy(6+(i*4),9);scanf("%d", &valor);
		Vector[i]= valor;
		i++;
	}while (valor>=0 && valor <=1 );
	 
    for (i=0; i<A; i++){
	    if (Vector[i]!= 0 && Vector[i]!=1){
	    	Vector[i]=100;
	    	gotoxy(6+(i*4),9);printf("b");
	    }
	}
	grafico(8,4,12);
	cabezal=1;
	estado=0;
	do{
		verpila(TOPE);
		Sleep(1000);
		if (estado==0){	
	        if (Vector[cabezal]!=100){
			   avance1(cabezal);Sleep(1000);avance2(cabezal);
			   	rlutil::setColor(rlutil::RED );A1();Sleep(1000);rlutil::setColor(rlutil::WHITE);A1();Sleep(1000);
	           cabezal++;
		    } else if (Vector[cabezal]==100){
			  Vector[cabezal]=3;
			  TOPE = push(TOPE,3);
			  gotoxy(6+(cabezal*4),9);printf("3");
			  avance1(cabezal);Sleep(1000);avance2(cabezal);
			  verpila(TOPE);
			  rlutil::setColor(rlutil::RED );A2();Sleep(1000);rlutil::setColor(rlutil::WHITE);A2();Sleep(1000);
			  cabezal--;
              estado=1;
		   }
		}
        if (estado==1){			
		    if (Vector[cabezal]!=100){
		    	avance1(cabezal);Sleep(1000);avance2(cabezal);
			    TOPE = push(TOPE,Vector[cabezal]);
			    verpila(TOPE);
			    rlutil::setColor(rlutil::RED );B1();Sleep(1000);rlutil::setColor(rlutil::WHITE);B1();Sleep(1000);
			    cabezal--;

		    }
			if (Vector[cabezal]==100){
                estado=2;
                avance1(cabezal);Sleep(1000);avance2(cabezal);
                rlutil::setColor(rlutil::RED );B2();Sleep(1000);rlutil::setColor(rlutil::WHITE);B2();Sleep(1000);
			    cabezal++;

		    }

		}

		if (estado==2){
			if ( Vector[cabezal]!=3 ){
			   avance1(cabezal);Sleep(1000);avance2(cabezal);
			   rlutil::setColor(rlutil::RED );C1();Sleep(1000);rlutil::setColor(rlutil::WHITE);C1();Sleep(1000);
			   cabezal++;

	     	}
			if (Vector[cabezal]==3 ){
                estado=3;
                avance1(cabezal);Sleep(1000);avance2(cabezal);
                rlutil::setColor(rlutil::RED );C2();Sleep(1000);rlutil::setColor(rlutil::WHITE);C2();Sleep(1000);
			    cabezal++;
	    	}

	   }
	   if(estado==3){
	   	 if (((Vector[cabezal]==100)) &&  !(PILA_VACIA(TOPE))){
         	avance1(cabezal);Sleep(1000);avance2(cabezal);
            p=TOPE;
			Vector[cabezal]=p->dato;
		    gotoxy(6+(cabezal*4),9);printf("%d", Vector[cabezal]);
		    TOPE = pop(TOPE);
		    verpila(TOPE);
		    rlutil::setColor(rlutil::RED );D1();Sleep(1000);rlutil::setColor(rlutil::WHITE);D1();Sleep(1000);
		    cabezal++;

		  }
		  if (PILA_VACIA(TOPE)){
			rlutil::setColor(rlutil::RED );D2();Sleep(1000);rlutil::setColor(rlutil::WHITE);D2();Sleep(1000);
			estado=4;
		   }

	    }
	}while(estado != 4);
    if (estado==4){
    	gotoxy(53,7);printf("CADENA ACEPTADA");
	}
	
   gotoxy(17,23);printf("¿Desea ingresar otra cadena?  1)SI 0)NO: ");scanf("%d",&sino);
}while(sino!=0);
    
   
    
}




