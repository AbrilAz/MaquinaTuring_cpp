#include "Libreria_ayudamaquina.h"


main(){
	int sino,i,j,cabezal,estado,valor,Vector1[A],Vector2[A],Vector3[A],Vector4[A];
    mensaje();mensaje2();mensaje();mensaje3();A1();A2();B1();B2();C1();C2();
    printf("\n\n\t\t");system("pause");mensaje();mensaje4();printf("\n\n\n\t\t");system("pause");
    mensaje();
	for (i=0; i<A; i++){
	    Vector1[i]=100;Vector2[i]=100;
	    Vector3[i]=100;Vector4[i]=100;
	}
	gotoxy (7,7); printf ("Ingresa cadena 1 binaria a sumar");
    grafico(18,4,8);llenar(Vector1,9);
	gotoxy (7,12); printf ("Ingresa cadena 2 binaria a sumar");
	grafico(18,4,13);llenar(Vector2,14);
	grafico(18,4,18);lleno(Vector3,19);
	grafico(18,4,23);lleno(Vector4,24);
	
	cabezal=1;
	estado=0;
   /*do{
	
	
	}while(estado != 3);
    if (estado==3){
    	gotoxy(53,7);printf("CADENA ACEPTADA");
	}
	
   gotoxy(17,23);printf("¿Desea ingresar otra cadena?  1)SI 0)NO: ");scanf("%d",&sino);
}while(sino!=0);*/
}
