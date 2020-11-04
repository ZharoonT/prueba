#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include "acceso.h"
#include "MOSTRAR.h"
#include "jarvis.h"
#include "UNILIB.h"
#define UP 72
#define DOWN 80
#define ENTER 13
#define right 77
#define left 75
typedef struct datos
{ /*STRUCTURA*/
    char nombre[16];
    char apellido[16];
    char carnet[11];
} datos_t;
/*definimos una esturctura de datos para tratar como un objeto cada matricula*/
/*----------Remplazar lo de la estructura-----------*/
int ingles1[10]; /*I semestre*/
int introduccion[10];
int filosofia[10];
int geometria[10];
int ingles2[10]; /*II semestre*/
int lenguaje[10];
int conceptos[10];
int mate1[10];
int redaccion[10];
int i = 0, confirmando = 0, p = 0,w=0,r=0; /*confirmando vendria siendo la variable bool para saber el grupo en que esta*/
/*---------------------------------------------------------------------------------------------------------------------------------------*/
/*prototipamos las funciones*/

int menu(void);
void home(void);
void add(void);
void show(datos_t []);
/*void delete(datos_t []);*/
/*---------------------------------------------------------------------------*/
void agregar(datos_t[]);
void editar(datos_t e[],int);
void delete(datos_t []);
void validando(char[], int, int);
void validando2(char[], int, int);
int validarNUM(int, int);
void validarCarnet(char[], int, int);
int menu2();
void buscar(char[],int,int);
void first_register(datos_t [],int,int);
void second_register(datos_t [],int,int);
void menu_delete_student(datos_t []);
int direc();
int capture();
/*------------------------------------------------------------------------------------------*/
int main()
{
    char val[16];
	int opcion=0,x,y;
   
    datos_t e[10];
    int repited=1,selection1=1,selection2=6,key=0,i=0,posicion1=0,posicion2=5,group2=0;
    int opc = 0, estudiantes_matriculados = 0;
    int sum=0;/*PARA SUMAR el promedio*/
    
    float average;
    /*Registro Previo*/
    char nombre_aux[] = "WILLIAM", apellido_aux[] = "CACERES", carnet_aux[] = "2020-0393U"; /*Registro previo 1M1*/
    char nombre_aux2[] = "ZHAROON", apellido_aux2[] = "TREMINIO", carnet_aux2[] = "2020-0269U";
    char nombre_aux3[] = "MICHELLE", apellido_aux3[] = "CALDERON", carnet_aux3[] = "2020-0339U"; /*Registro previo 1m2*/
    char nombre_aux4[] = "GABRIELA", apellido_aux4[] = "ROBLETO", carnet_aux4[] = "2020-0429U";
    char nombre[16];char apellido[16];char posicion[5];
    int validacion=0;
    int find=0,pos=0,eje_y=0;
    fflush(stdin);
    
    strcpy(e[0].nombre, nombre_aux);
    strcpy(e[0].apellido, apellido_aux);
    strcpy(e[0].carnet, carnet_aux); /*Registro previo 1M1*/
    strcpy(e[1].nombre, nombre_aux2);
    strcpy(e[1].apellido, apellido_aux2);
    strcpy(e[1].carnet, carnet_aux2);
    strcpy(e[5].nombre, nombre_aux3);
    strcpy(e[5].apellido, apellido_aux3);
    strcpy(e[5].carnet, carnet_aux3); /*Registro previo 1m2*/
    strcpy(e[6].nombre, nombre_aux4);
    strcpy(e[6].apellido, apellido_aux4);
    strcpy(e[6].carnet, carnet_aux4);
    for (i = 0; i < 2; i++)
    {
        ingles1[i] = 98;
        geometria[i] = 86;
        filosofia[i] = 100;
        introduccion[i] = 100;
        ingles2[i] = 100;
        lenguaje[i] = 100;
        mate1[i] = 96;
        redaccion[i] = 100;
        conceptos[i] = 89;
    }
    for (i = 5; i < 7; i++)
    {
        ingles1[i] = 100;
        geometria[i] = 86;
        filosofia[i] = 100;
        introduccion[i] = 100;
        ingles2[i] = 100;
        lenguaje[i] = 100;
        mate1[i] = 96;
        redaccion[i] = 100;
        conceptos[i] = 90;
    }
    clrscr();
    textcolor(WHITE);
    logo();
    barra();
    acceso();
    grupos:
    opcion=menu2();
    switch(opcion)
    {
        case 1:
        clrscr();cprintf("1M1");
        confirmando=1;
         p = 1;
         p=p+w;
         getch();
         break;
         case 3:
         clrscr();cprintf("1M2");
         confirmando=2;
         p=6;
         p=p+r;
        getch();
        break;
        case 5:
        exit(-1);
        break;
    }
/*--------------------------------------------------------------------------------------------------------------*/
menu:
  
    opc = menu();
    switch (opc)
    {
    case 0:

        gotoxy(20, 5);
        printf("HOME......");
        if(confirmando==1){
            gotoxy(15,2);textcolor(GREEN);cprintf("1M1-CO");
        }else{
            gotoxy(15,2);textcolor(GREEN);cprintf("1M1-CO");
        }
        getch();
        goto menu;
        break;
    case 4:
        
        if (confirmando == 1 && p >= 0 && p < 4)
        {
            p=1;
            w++;
            p=p+w;
            agregar(e);
            fflush(stdin);
            clrscr();
           
        }else{
            if (confirmando == 2 && p >= 5 && p < 9)
            {
            p=6;
            r++;
            p=p+r;
            agregar(e);
            fflush(stdin);
            clrscr();
            }
            fflush(stdin);
        }
        goto menu;
        break;
    case 8:
        clrscr();
        /*update*/
        repited=1;
        selection1=1;
        selection2=6;
        key=0;i=0;posicion1=0;posicion2=5;group2=0;
        textcolor(WHITE);
        if(confirmando==1)
        {
        do
	    {   
		    system("cls");menu_vista();textcolor(LIGHTGREEN);
            gotoxy(22,2);cprintf("SELECCIONE EL ESTUDIANTE A EDITAR: ");
		    gotoxy(26,5+selection1);cprintf(">");/*Imprime flecha*/
            textcolor(WHITE);
            for(i=0;i<(p+1);i++)
            {
                gotoxy(28,6+i);cprintf("%d. %s %s",i+1,e[i].nombre,e[i].apellido);/*Imprime alumnos*/
            }
		    do{key=getch();}while(key!=UP && key!= DOWN && key!= ENTER);/*Caputuro la tecla*/
		    switch(key)
		    {
			    case UP:
                posicion1--;
				selection1--;
                if(selection1<1)
                {
                    selection1=1;posicion1=0;
                }
                break;
			    case DOWN:
                posicion1++;
				selection1++;
                if(selection1>(p+1))
                {
                    selection1=1;posicion1=0;
                }
                if(selection1>(p+2))
                {
                    selection1=1;posicion1=0;
                }
                if(selection1>(p+3))
                {
                    selection1=1;posicion1=0;
                }
                if(selection1>(p+4))
                {
                    selection1=1;posicion1=0;
                }
                break;
			    case ENTER:
                    gotoxy(25,20);
                    textcolor(LIGHTRED);cprintf("EL ESTUDIANTE HA SIDO EDITADO");
                    gotoxy(25,22);cprintf("%d",posicion1);/*Aqui se imprime la posicion, solo es para guiarse*/
                    editar(e,posicion1);
                repited=0;
                break;
		    }
	    } while (repited);
	    /*return selection;*/
    }
    /*----------------SEGUNDO GRUPO---------------*/
    if(confirmando==2)
    {
        do
	    {
		    system("cls");menu_vista();textcolor(LIGHTGREEN);
            gotoxy(22,2);cprintf("SELECCIONE EL ESTUDIANTE A EDITAR: ");
		    gotoxy(26,3+selection2);cprintf(">");/*Imprime flecha*/
            textcolor(WHITE);
            group2=0;/*Limpiamos, esto para que se vaya mostrando el orden del num de students a partir de la pos 5*/
            for(i=5;i<(p+1);i++)
            {
                group2++;
                gotoxy(28,4+i);cprintf("%d. %s %s",group2,e[i].nombre,e[i].apellido);/*Imprime alumnos*/
            }
		    do{key=getch();}while(key!=UP && key!= DOWN && key!= ENTER);/*Caputuro la tecla*/
		    switch(key)
		    {
			    case UP:
                    posicion2--;
				    selection2--;
                    if(selection2<6)
                    {
                        selection2=6;posicion2=5;
                    }
                    break;
			    case DOWN:
                    posicion2++;
				    selection2++;
                    if(selection2>(p+1))
                    {
                        selection2=6;posicion2=5;
                    }
                    if(selection2>(p+2))
                    {
                        selection2=6;posicion2=5;
                    }
                    if(selection2>(p+3))
                    {
                        selection2=6;posicion2=5;
                    }
                    if(selection2>(p+4))
                    {
                        selection2=6;posicion2=5;
                    }
                    break;
			    case ENTER:
                    gotoxy(25,20);
                    textcolor(LIGHTRED);cprintf("EL ESTUDIANTE HA SIDO EDITAR");
                    gotoxy(20,22);cprintf("%d",posicion2);/*Aqui se imprime la posicion, solo es para guiarse*/
                    editar(e,posicion2);
                repited=0;
                break;
		    }
	    } while (repited);
    }
        getch();
        goto menu;
        break;
    case 12:
        /*mostrar*/

        show(e);
        goto menu;
        break;
    case 16:
        
        textcolor(WHITE);
        gotoxy(25,2);
        cprintf("BUSCAR");
        gotoxy(15,5);x=40;y=5;
        cprintf("Nombre que desea buscar: ");
        buscar(val,x,y);
        if (confirmando==1)
        {
           for (i = 0; i < p+1; i++)
          {
            if(strcmp(e[i].nombre,val/*nombre*/)==0 )/*&& strcmp(e[i].apellido,apellido)==0)*/
            {
                find=1;
                gotoxy(20,7+i);
                cprintf("%s %s %s\n",e[i].nombre,e[i].apellido,e[i].carnet);
                /*pos=i;Encontramos la posicion del nombre**/
            }
          }
          if (find==0)
          {
            gotoxy(20,7);
             cprintf("Estudiante no encontrado");
          }
          find=0;

        }
        if (confirmando==2){
            for (i = 5; i < p+1; i++)
             {
            if(strcmp(e[i].nombre,val/*nombre*/)==0) /*&& strcmp(e[i].apellido,apellido)==0)*/
            {
                find=1;
                gotoxy(20,7+i);
                cprintf("%s %s %s\n",e[i].nombre,e[i].apellido,e[i].carnet);
                /*pos=i;Encontramos la posicion del nombre**/
            }
          }
           if (find==0)
          {
             gotoxy(20,7); 
             cprintf("Estudiante no encontrado");
          }
           find=0;
        }
        getch();
        goto menu;
        break;
    case 20:
        /*delete(e);*/
        menu_delete_student(e);
        getch();    
        goto menu;
        break;
    case 24:
        
        goto grupos;
        
        break;
    }
    return 0;
}
/*-------------------------------------------------------------------*/
void menu_delete_student(datos_t e[])
{
	int repited=1,selection1=1,selection2=6,key=0,i=0,posicion1=0,posicion2=5,group2=0;
    /*proposito de las variables: repite: maneja los bucles do-while, selection1: manejo de menu de estudiantes del 1er grupo, 
    permite la movilizacion de la flecha
    a partir del punto 1, donde los nombres empiezan a imprimirse, selection2: tiene el mismo proposito, solo que trabaja con el grupo 2,
    key: recoge las teclas, i: para el for (basico xD), posicion1: maneja al grupo1, esta variable permite darme la posicion de la ubicacion
    de la flecha, donde se encuentra el nombre de student, esto con el proposito de poder eliminarlo, posicion2: tienen el mismo
    proposito solo que este maneja al grupo2, group2: lo use como un pequeño contador para imprimir los nombre del 1m2,
    lo que permite imprimirlos contando desde el 1, porque si no, los nombres se me imprimirian a partir de 5 que es donde
    empiezan los students del grupo 2, FIN*/
    if(confirmando==1)
    {
        do
	    {
		    system("cls");textcolor(LIGHTGREEN);menu_vista();
            gotoxy(22,2);cprintf("SELECCIONE EL ESTUDIANTE A ELIMINAR: ");
		    gotoxy(26,5+selection1);cprintf(">");/*Imprime flecha*/
            textcolor(WHITE);
            for(i=0;i<(p+1);i++)
            {
                gotoxy(28,6+i);cprintf("%d. %s %s",i+1,e[i].nombre,e[i].apellido);/*Imprime alumnos*/
            }
		    do{key=getch();}while(key!=UP && key!= DOWN && key!= ENTER);/*Caputuro la tecla*/
		    switch(key)
		    {
			    case UP:
                posicion1--;
				selection1--;
                if(selection1<1)
                {
                    selection1=1;posicion1=0;
                }
                break;
			    case DOWN:
                posicion1++;
				selection1++;
                if(selection1>(p+1))
                {
                    selection1=1;posicion1=0;
                }
                if(selection1>(p+2))
                {
                    selection1=1;posicion1=0;
                }
                if(selection1>(p+3))
                {
                    selection1=1;posicion1=0;
                }
                if(selection1>(p+4))
                {
                    selection1=1;posicion1=0;
                }
                break;
			    case ENTER:
                    gotoxy(25,20);
                    textcolor(LIGHTRED);cprintf("EL ESTUDIANTE HA SIDO ELIMINADO");
                    /*gotoxy(25,22);cprintf("%d",posicion1);*//*Aqui se imprime la posicion, solo es para guiarse*/
                    for(i=0;i<(p+1);i++)
                    {
                        if(posicion1==i)
                        {
                            for(i=posicion1;i<p;i++)
                            {
                            strcpy(e[i].nombre,e[i+1].nombre);strcpy(e[i].apellido,e[i+1].apellido);strcpy(e[i].carnet,e[i+1].carnet);
                            ingles1[i]=ingles1[i+1];geometria[i]=geometria[i+1];introduccion[i]=introduccion[i+1];filosofia[i]=filosofia[i+1];
                            ingles2[i]=ingles2[i+1];lenguaje[i]=lenguaje[i+1];redaccion[i]=redaccion[i+1];conceptos[i]=conceptos[i+1];mate1[i]=mate1[i+1];
                            }
                            p--;
                            w--;
                        }
                    }
                repited=0;
                break;
		    }
	    } while (repited);
	    /*return selection;*/
    }
    /*----------------SEGUNDO GRUPO---------------*/
    if(confirmando==2)
    {
        do
	    {
		    system("cls");textcolor(LIGHTGREEN);
            gotoxy(22,2);cprintf("SELECCIONE EL ESTUDIANTE A ELIMINAR: ");
		    gotoxy(26,3+selection2);cprintf(">");/*Imprime flecha*/
            textcolor(WHITE);
            group2=0;/*Limpiamos, esto para que se vaya mostrando el orden del num de students a partir de la pos 5*/
            for(i=5;i<(p+1);i++)
            {
                group2++;
                gotoxy(28,4+i);cprintf("%d. %s %s",group2,e[i].nombre,e[i].apellido);/*Imprime alumnos*/
            }
		    do{key=getch();}while(key!=UP && key!= DOWN && key!= ENTER);/*Caputuro la tecla*/
		    switch(key)
		    {
			    case UP:
                    posicion2--;
				    selection2--;
                    if(selection2<6)
                    {
                        selection2=6;posicion2=5;
                    }
                    break;
			    case DOWN:
                    posicion2++;
				    selection2++;
                    if(selection2>(p+1))
                    {
                        selection2=6;posicion2=5;
                    }
                    if(selection2>(p+2))
                    {
                        selection2=6;posicion2=5;
                    }
                    if(selection2>(p+3))
                    {
                        selection2=6;posicion2=5;
                    }
                    if(selection2>(p+4))
                    {
                        selection2=6;posicion2=5;
                    }
                    break;
			    case ENTER:
                    gotoxy(25,20);
                    textcolor(LIGHTRED);cprintf("EL ESTUDIANTE HA SIDO ELIMINADO");
                    /*gotoxy(20,22);cprintf("%d",posicion2);*//*Aqui se imprime la posicion, solo es para guiarse*/
                    for(i=5;i<(p+1);i++)
                    {
                        if(posicion2==i)
                        {
                            for(i=posicion2;i<p;i++)
                            {
                            strcpy(e[i].nombre,e[i+1].nombre);strcpy(e[i].apellido,e[i+1].apellido);strcpy(e[i].carnet,e[i+1].carnet);
                            ingles1[i]=ingles1[i+1];geometria[i]=geometria[i+1];introduccion[i]=introduccion[i+1];filosofia[i]=filosofia[i+1];
                            ingles2[i]=ingles2[i+1];lenguaje[i]=lenguaje[i+1];redaccion[i]=redaccion[i+1];conceptos[i]=conceptos[i+1];mate1[i]=mate1[i+1];
                            }
                            p--;
                            r--;
                        }
                    }
                repited=0;
                break;
		    }
	    } while (repited);
    }
}
/*----------------------------------------------------------------------*/
void menu_vista(){
    int a = 0, i = 0, repite = 1, key, seleccion = 0;

    char *opcion[7] = {"HOME", "ADD", "UPDATE", "SHOW", "SEARCH", "DELETE", "RETURN"};
    clrscr();
    textcolor(WHITE);
    for (i = 1; i < 26; i++)
    {
        gotoxy(10, i);
        cprintf("|");
    }
    home();

    for (i = 0; i < 7; i++)
    {
        gotoxy(3, 1 + a);
        cprintf("%s", opcion[i]);
        a = a + 4;
    }
}
int menu()
{
    int a = 0, i = 0, repite = 1, key, seleccion = 0;

    char *opcion[7] = {"HOME", "ADD", "UPDATE", "SHOW", "SEARCH", "DELETE", "RETURN"};
    clrscr();
    textcolor(WHITE);
    for (i = 1; i < 26; i++)
    {
        gotoxy(10, i);
        cprintf("|");
    }
    home();

    for (i = 0; i < 7; i++)
    {
        gotoxy(3, 1 + a);
        cprintf("%s", opcion[i]);
        a = a + 4;
    }
    do
    {
        gotoxy(1, 1 + seleccion);
        textcolor(RED);
        cprintf("%c", 219);
        gotoxy(2, 1 + seleccion);
        textcolor(RED);
        cprintf("%c", 219);
        gotoxy(3, 1 + seleccion);
        textcolor(RED);
        cprintf("%c", 219);
        gotoxy(4, 1 + seleccion);
        textcolor(RED);
        cprintf("%c", 219);
        gotoxy(5, 1 + seleccion);
        textcolor(RED);
        cprintf("%c", 219);
        gotoxy(6, 1 + seleccion);
        textcolor(RED);
        cprintf("%c", 219);
        gotoxy(7, 1 + seleccion);
        textcolor(RED);
        cprintf("%c", 219);
        gotoxy(8, 1 + seleccion);
        textcolor(RED);
        cprintf("%c", 219);
        gotoxy(9, 1 + seleccion);
        textcolor(RED);
        cprintf("%c", 219);
        textcolor(WHITE);
        gotoxy(1, 1 + seleccion);
        cprintf("[");
        textcolor(WHITE);
        gotoxy(9, 1 + seleccion);
        cprintf("]");
        if (seleccion == 0)
        {
            i = 0;
        }
        else if (seleccion == 4)
        {
            i = 1;
        }
        else if (seleccion == 8)
        {
            i = 2;
        }
        else if (seleccion == 12)
        {
            i = 3;
        }
        else if (seleccion == 16)
        {
            i = 4;
        }
        else if (seleccion == 20)
        {
            i = 5;
        }
        else if (seleccion == 24)
        {
            i = 6;
        }
        textcolor(BLUE);
        gotoxy(3, 1 + (seleccion));
        cprintf("%s", opcion[i]);

        do
        {
            key = getch(); /*Captura tecla*/
        } while (key != UP && key != DOWN && key != ENTER);
        switch (key)
        {
        case UP: /*arriba*/
            gotoxy(1, 1 + seleccion);
            textcolor(BLACK);
            cprintf("%c", 219);
            gotoxy(2, 1 + seleccion);
            textcolor(BLACK);
            cprintf("%c", 219);
            gotoxy(3, 1 + seleccion);
            textcolor(BLACK);
            cprintf("%c", 219);
            gotoxy(4, 1 + seleccion);
            textcolor(BLACK);
            cprintf("%c", 219);
            gotoxy(5, 1 + seleccion);
            textcolor(BLACK);
            cprintf("%c", 219);
            gotoxy(6, 1 + seleccion);
            textcolor(BLACK);
            cprintf("%c", 219);
            gotoxy(7, 1 + seleccion);
            textcolor(BLACK);
            cprintf("%c", 219);
            gotoxy(8, 1 + seleccion);
            textcolor(BLACK);
            cprintf("%c", 219);
            gotoxy(9, 1 + seleccion);
            textcolor(BLACK);
            cprintf("%c", 219);
            textcolor(BLACK);
            gotoxy(1, 1 + (seleccion));
            cprintf("[");
            textcolor(BLACK);
            gotoxy(9, 1 + seleccion);
            cprintf("]");
            textcolor(WHITE);
            gotoxy(3, 1 + (seleccion));
            cprintf("%s", opcion[i]);

            seleccion -= 4; /*Opcion disminuye*/

            if (seleccion < 0)
                seleccion = 24; /*Si la opcion menor que 1 que se vuelva a la ultima opcion*/
            break;
        case DOWN: /*abajo*/

            seleccion += 4; /*Opcion aumenta*/
            gotoxy(1, 1 + seleccion - 4);
            textcolor(BLACK);
            cprintf("%c", 219);
            gotoxy(2, 1 + seleccion - 4);
            textcolor(BLACK);
            cprintf("%c", 219);
            gotoxy(3, 1 + seleccion - 4);
            textcolor(BLACK);
            cprintf("%c", 219);
            gotoxy(4, 1 + seleccion - 4);
            textcolor(BLACK);
            cprintf("%c", 219);
            gotoxy(5, 1 + seleccion - 4);
            textcolor(BLACK);
            cprintf("%c", 219);
            gotoxy(6, 1 + seleccion - 4);
            textcolor(BLACK);
            cprintf("%c", 219);
            gotoxy(7, 1 + seleccion - 4);
            textcolor(BLACK);
            cprintf("%c", 219);
            gotoxy(8, 1 + seleccion - 4);
            textcolor(BLACK);
            cprintf("%c", 219);
            gotoxy(9, 1 + seleccion - 4);
            textcolor(BLACK);
            cprintf("%c", 219);
            textcolor(BLACK);
            gotoxy(1, 1 + (seleccion - 4));
            cprintf("[");
            textcolor(BLACK);
            gotoxy(9, 1 + (seleccion - 4));
            cprintf("]");
            textcolor(WHITE);
            gotoxy(3, 1 + (seleccion - 4));
            cprintf("%s", opcion[i]);

            if (seleccion > 24 || seleccion < 0)
                seleccion = 0; /*Si la opcion mayor que el numero de opciones que se vuelva al 1*/
            break;
        case ENTER:
            repite = 0; /*Se sale*/
            break;
        }
    } while (repite == 1);
    
    
        return seleccion;

}

void home()
{
    time_t tiempoahora;
    time(&tiempoahora);

    gotoxy(55, 1);
    cprintf("%s\n", ctime(&tiempoahora));
    if(confirmando==1){
            gotoxy(15,1);textcolor(WHITE);cprintf("1M1-CO");
    }else{
        gotoxy(15,1);textcolor(WHITE);cprintf("1M2-CO");
        }
}
/*add students*/
void agregar(datos_t e[])
{
    char validar[16];
    char validar2[16];
    char array[11];
    int i = 0, opc = 0, x, y;
    int repite = 1, key, seleccion = 0;
    fflush(stdin);
    fflush(stdin);
    textcolor(WHITE);
    fflush(stdin);
    gotoxy(15, 3);
    cprintf("Ingrese nombre:");
    x = 35;
    y = 3;
    validando(validar, x, y);
    strcpy(e[p].nombre, validar);
    gotoxy(15, 5);
    cprintf("Ingrese apellido:");
    x = 35;
    y = 5;
    validando2(validar2, x, y);
    strcpy(e[p].apellido, validar2);
    fflush(stdin); /*todo mal*/
car:
    fflush(stdin);
    gotoxy(1, 8);
    clreol();
    for (i = 0; i < 11; i++)
    {
        array[i] = ' ';
    }
    gotoxy(15, 7);
    cprintf("Ingrese carnet:");
    x = 35;
    y = 7;
    validarCarnet(array, x, y);
    for (i = 0; i < 11; i++)
    {
        fflush(stdin);
        if (strcmp(e[i].carnet, array) == 0)
        {
            gotoxy(23, 10);
            cprintf("ESTE ESTUDIANTE YA EXISTE EN EL SISTEMA!");
            sleep(3);
            gotoxy(23, 10);
            clreol();
            goto car;
        }
    }
    strcpy(e[p].carnet, array);
    fflush(stdin);

    for (i = 11; i < 81; i++)
    {
        gotoxy(i, 9);
        cprintf("-");
    }
    gotoxy(40, 10);
    cprintf("Semestre?");
    for (i = 11; i < 81; i++)
    {
        gotoxy(i, 11);
        cprintf("-");
    }
    textcolor(GREEN);
    gotoxy(15, 12);
    cprintf("I");
    gotoxy(44, 12);
    cprintf("II");
    gotoxy(71, 12);
    cprintf("I y II");

    do
    {
        textcolor(WHITE);
        gotoxy(11 + seleccion, 12);
        cprintf("[");
        gotoxy(20 + seleccion, 12);
        cprintf("]");

        do
        {
            key = getch(); /*Captura tecla*/
        } while (key != ENTER && key != left && key != right);
        switch (key)
        {
        case left:
            textcolor(BLACK);
            gotoxy(11 + seleccion, 12);
            cprintf("[");
            gotoxy(20 + seleccion, 12);
            cprintf("]");
            seleccion -= 29; /*Opcion disminuye*/
            if (seleccion < 0)
                seleccion = 58; /*Si la opcion menor que 1 que se vuelva a la ultima opcion*/
            break;
        case right:
            textcolor(BLACK);
            gotoxy(11 + seleccion, 12);
            cprintf("[");
            gotoxy(20 + seleccion, 12);
            cprintf("]");
            seleccion += 29; /*Opcion aumenta*/
            if (seleccion > 81 || seleccion < 0)
                seleccion = 0; /*Si la opcion mayor que el numero de opciones que se vuelva al 1*/
            break;
        case ENTER:
            repite = 0; /*Se sale*/

            break;
        }

    } while (repite == 1);
    for (i = 11; i < 81; i++)
    {
        gotoxy(i, 13);
        cprintf("-");
    }

    fflush(stdin);
    /*trbajamos las opciones con la variable seleccion directamente la cual varia el valor de acuerdo a la posicion en pantalla*/
    if (seleccion == 0)
    {
        fflush(stdin);
        textcolor(WHITE);
        /*gotoxy(25,12);cprintf("[I semestre]");*/
        gotoxy(15, 15);
        cprintf("Ingles I: ");
        x = 30;
        y = 15;
        ingles1[p] = validarNUM(x, y);
        gotoxy(15, 17);
        cprintf("Introduccion: ");
        x = 30;
        y = 17;
        introduccion[p] = validarNUM(x, y);
        gotoxy(15, 19);
        cprintf("Filosofia: ");
        x = 30;
        y = 19;
        filosofia[p] = validarNUM(x, y);
        gotoxy(15, 21);
        cprintf("Geometria: ");
        x = 30;
        y = 21;
        geometria[p] = validarNUM(x, y);
        ingles2[p] = -1;
        conceptos[p] = -1;
        mate1[p] = -1;
        lenguaje[p] = -1;
        redaccion[p] = -1;
    }
    if (seleccion == 29)
    {
        fflush(stdin);
        textcolor(WHITE);
        /*gotoxy(25,12);cprintf("[II semestre]");*/
        gotoxy(15, 15);
        cprintf("Matematicas I: ");
        x = 40;
        y = 15;
        mate1[p] = validarNUM(x, y);
        gotoxy(15, 17);
        cprintf("Redaccion: ");
        x = 40;
        y = 17;
        redaccion[p] = validarNUM(x, y);
        gotoxy(15, 19);
        cprintf("Conceptos: ");
        x = 40;
        y = 19;
        conceptos[p] = validarNUM(x, y);
        ingles2[p] = -1;
        lenguaje[p] = -1;
        ingles1[p] = -1;
        introduccion[p] = -1;
        filosofia[p] = -1;
        geometria[p] = -1;
    }
    if (seleccion == 58)
    {
        fflush(stdin);
        textcolor(WHITE);
        /*gotoxy(25,12);cprintf("[I y II semestre]");*/
        gotoxy(15, 15);
        cprintf("Ingles I: ");
        x = 30;
        y = 15;
        ingles1[p] = validarNUM(x, y);
        gotoxy(15, 17);
        cprintf("Introduccion: ");
        x = 30;
        y = 17;
        introduccion[p] = validarNUM(x, y);
        gotoxy(15, 19);
        cprintf("Filosofia: ");
        x = 30;
        y = 19;
        filosofia[p] = validarNUM(x, y);
        gotoxy(15, 21);
        cprintf("Geometria: ");
        x = 30;
        y = 21;
        geometria[p] = validarNUM(x, y);
        if (ingles1[p] > 59 && introduccion[p] > 59)
        {
            fflush(stdin);
            gotoxy(50, 15);
            cprintf("Ingles II: ");
            x = 65;
            y = 15;
            ingles2[p] = validarNUM(x, y);
            gotoxy(50, 17);
            cprintf("Lenguaje: ");
            x = 65;
            y = 17;
            lenguaje[p] = validarNUM(x, y);
            gotoxy(50, 19);
            cprintf("Matematicas I: ");
            x = 65;
            y = 19;
            mate1[p] = validarNUM(x, y);
            gotoxy(50, 21);
            cprintf("Redaccion: ");
            x = 65;
            y = 21;
            redaccion[p] = validarNUM(x, y);
            gotoxy(50, 23);
            cprintf("Conceptos: ");
            x = 65;
            y = 23;
            conceptos[p] = validarNUM(x, y);
        }
        if (ingles1[p] <= 59 && introduccion[p] <= 59)
        {
            fflush(stdin);
            gotoxy(50, 15);
            cprintf("Matematicas I: ");
            x = 65;
            y = 15;
            mate1[p] = validarNUM(x, y);
            gotoxy(50, 17);
            cprintf("Redaccion: ");
            x = 65;
            y = 17;
            redaccion[p] = validarNUM(x, y);
            gotoxy(50, 19);
            cprintf("Conceptos: ");
            x = 65;
            y = 19;
            conceptos[p] = validarNUM(x, y);
            ingles2[p] = -1;
            lenguaje[p] = -1;
        }
        if (ingles1[p] > 59 && introduccion[p] <= 59) /*si aprueba ingles pero no inntro*/
        {
            fflush(stdin);
            gotoxy(50, 15);
            cprintf("Matematicas I: ");
            x = 65;
            y = 15;
            mate1[p] = validarNUM(x, y);
            gotoxy(50, 17);
            cprintf("Redaccion: ");
            x = 65;
            y = 17;
            redaccion[p] = validarNUM(x, y);
            gotoxy(50, 19);
            cprintf("Conceptos: ");
            x = 65;
            y = 19;
            conceptos[p] = validarNUM(x, y);
            gotoxy(50, 21);
            cprintf("Ingles II: ");
            x = 65;
            y = 21;
            ingles2[p] = validarNUM(x, y);
            lenguaje[p] = -1;
        }
        if (ingles1[p] <= 59 && introduccion[p] > 59)
        {
            fflush(stdin);
            gotoxy(50, 15);
            cprintf("Matematicas I: ");
            x = 65;
            y = 15;
            mate1[p] = validarNUM(x, y);
            gotoxy(50, 17);
            cprintf("Redaccion: ");
            x = 65;
            y = 17;
            redaccion[p] = validarNUM(x, y);
            gotoxy(50, 19);
            cprintf("Conceptos: ");
            x = 65;
            y = 19;
            conceptos[p] = validarNUM(x, y);
            gotoxy(50, 21);
            cprintf("Lenguaje: ");
            x = 65;
            y = 21;
            lenguaje[p] = validarNUM(x, y);
            ingles2[p] = -1;
        }
    }
    textcolor(GREEN);
    gotoxy(15, 23);
    cprintf("PRES ONE KEY TO CONTINUE");
    getch();
    fflush(stdin);
}
/*-------------------------OPCION MOSTRAR---------------------*/
void show(datos_t e[])
{
    char *option[3]={"I SEMESTRE","II SEMESTRE","Regresar"};
    int op=0,repited=1;
    do
    {
	    system("cls");
        textcolor(WHITE);
	    op=direc(option);
	    switch(op)
	    {
		case 1: first_register(e,p,confirmando);I_SEMESTER();break;
		case 3: second_register(e,p,confirmando);II_SEMESTER();break;
		case 5:;repited=0;break;
	    }
    } while (repited);
}
void first_register(datos_t e[],int p,int confirmando)
{
	int i=0,sum=0,y=0;float average=0;
    system("cls");textcolor(WHITE);menu_vista();
    fflush(stdin);
    if(confirmando==1)
    {
        for(i=0;i<(p+1);i++)
        {
            fflush(stdin);
            if(ingles1[i]!=-1 && geometria[i]!=-1 && filosofia[i]!=-1 && introduccion[i]!=-1)
            {
                sum=(ingles1[i]+geometria[i]+filosofia[i]+introduccion[i]);
                average=sum/4;
				gotoxy(43,7+i*2);cprintf("%.2f",average);
            }
            else
            {
				gotoxy(45,7+i*2);cprintf("-");
            }
        }
        for(i=0;i<(p+1);i++)
        {
            /*Aqui se imprimer los datos*/
            fflush(stdin);
	        gotoxy(12,7+i*2);cprintf("%s %s\n",e[i].nombre,e[i].apellido);gotoxy(29,7+(i*2));cprintf("%s",e[i].carnet);
            if(ingles1[i]==-1)
            {
                gotoxy(67,7+i*2);cprintf("-");
            }else
            {
				gotoxy(67,7+i*2);cprintf("%d",ingles1[i]);
            }
            if(filosofia[i]==-1)
            {
                gotoxy(74,7+i*2);cprintf("-");
            }else
            {
                gotoxy(74,7+i*2);cprintf("%d",filosofia[i]);
            }
            if(geometria[i]==-1)
            {
                gotoxy(59,7+(i*2));cprintf("-");
            }else
            {
                gotoxy(59,7+(i*2));cprintf("%d",geometria[i]);
            }
            if(introduccion[i]==-1)
            {
                gotoxy(52,7+i*2);cprintf("-");
            }
            else
            {
                gotoxy(52,7+i*2);cprintf("%d",introduccion[i]);
            }
        }
    }
    if(confirmando==2)
    {
        for(i=5;i<(p+1);i++)
        {
            y++;
            fflush(stdin);
            if(ingles1[i]!=-1 && geometria[i]!=-1 && filosofia[i]!=-1 && introduccion[i]!=-1)
            {
                sum=(ingles1[i]+geometria[i]+filosofia[i]+introduccion[i]);
                average=sum/4;
			    gotoxy(43,5+y*2);cprintf("%.2f",average);
            }
            else
            {
				gotoxy(45,5+y*2);cprintf("-");
            }
        }
        y=0;
        for(i=5;i<(p+1);i++)
        {
            y++;
            fflush(stdin);
            /*Aqui se imprimer los datos*/
	        gotoxy(12,5+(y*2));cprintf("%s %s\n",e[i].nombre,e[i].apellido);gotoxy(30,5+(y*2));cprintf("%s",e[i].carnet);
             if(ingles1[i]==-1)
            {
                gotoxy(67,5+(y*2));cprintf("-");
            }else
            {
				gotoxy(67,5+(y*2));cprintf("%d",ingles1[i]);
            }
            if(filosofia[i]==-1)
            {
                gotoxy(74,5+(y*2));cprintf("-");
            }else
            {
                gotoxy(74,5+(y*2));cprintf("%d",filosofia[i]);
            }
            if(geometria[i]==-1)
            {
                gotoxy(59,5+(y*2));cprintf("-");
            }else
            {
                gotoxy(59,5+(y*2));cprintf("%d",geometria[i]);
            }
            if(introduccion[i]==-1)
            {
                gotoxy(52,5+(y*2));cprintf("-");
            }
            else
            {
                gotoxy(52,5+(y*2));cprintf("%d",introduccion[i]);
            }
	        /*gotoxy(67,5+(y*2));cprintf("%d",ingles1[i]);gotoxy(59,5+(y*2));cprintf("%d",geometria[i]);gotoxy(74,5+(y*2));cprintf("%d",filosofia[i]);gotoxy(52,5+(y*2));cprintf("%d",introduccion[i]);*/
        }
    }
    gotoxy(15,24);cprintf("<-- to returns");
}
/*----------------------------II SEMESTRE---------------------------------*/
void second_register(datos_t e[],int p,int confirmando)
{
    int i=0,sum=0,y=0;float average=0;
    system("cls");textcolor(WHITE);menu_vista();
    if(confirmando==1)
    {
        for(i=0;i<(p+1);i++)
        {
            fflush(stdin);
            if(ingles2[i]!=-1 && mate1[i]!=-1 && lenguaje[i]!=-1 && redaccion[i]!=-1 && conceptos[i]!=-1)
            {
                sum=(ingles2[i]+mate1[i]+lenguaje[i]+redaccion[i]+conceptos[i]);
		        average=sum/5;
				gotoxy(43,7+i*2);cprintf("%.2f",average);
            }else
            {
                if(mate1[i]!=-1 && redaccion[i]!=-1 && conceptos[i]!=-1)
                {
                    sum=(mate1[i]+redaccion[i]+conceptos[i]);
		            average=sum/3;
					gotoxy(43,7+i*2);cprintf("%.2f",average);
                }else
                {
				gotoxy(45,7+i*2);cprintf("-");
                }
            }
        }
        for(i=0;i<(p+1);i++)
        {
            fflush(stdin);
	        gotoxy(12,7+i*2);cprintf("%s %s\n",e[i].nombre,e[i].apellido);gotoxy(29,7+i*2);cprintf("%s",e[i].carnet);
            if(ingles2[i]==-1)
            {
                 gotoxy(74,7+i*2);cprintf("-");
            }else
            {
				gotoxy(74,7+i*2);cprintf("%d",ingles2[i]);
            }
            if(mate1[i]==-1)
            {
                gotoxy(52,7+i*2);cprintf("-");
            }else
            {
				gotoxy(52,7+i*2);cprintf("%d",mate1[i]);
            }
            if(lenguaje[i]==-1)
            {
                gotoxy(63,7+i*2);cprintf("-");
            }else
            {
				gotoxy(63,7+i*2);cprintf("%d",lenguaje[i]);
            }
            if(redaccion[i]==-1)
            {
                gotoxy(68,7+i*2);cprintf("-");
            }else
            {
				gotoxy(68,7+i*2);cprintf("%d",redaccion[i]);
            }
            if(conceptos[i]==-1)
            {
                gotoxy(58,7+i*2);cprintf("-");
            }else
            {
				gotoxy(58,7+i*2);cprintf("%d",conceptos[i]);
            }
        }
    }
    if(confirmando==2)
    {
        for(i=5;i<(p+1);i++)
        {
            y++;
            fflush(stdin);
            if(ingles2[i]!=-1 && mate1[i]!=-1 && lenguaje[i]!=-1 && redaccion[i]!=-1 && conceptos[i]!=-1)
            {
                sum=(ingles2[i]+mate1[i]+lenguaje[i]+redaccion[i]+conceptos[i]);
		        average=sum/5;
                gotoxy(43,5+y*2);cprintf("%.2f",average);
            }else
            {
                /*Si solo lleva estas tres clases sacar el promedio /3*/
                if(mate1[i]!=-1 && redaccion[i]!=-1 && conceptos[i]!=-1)
                {
                    sum=(mate1[i]+redaccion[i]+conceptos[i]);
		            average=sum/3;
                    gotoxy(43,5+y*2);cprintf("%.2f",average);
                }else
                {
					gotoxy(45,5+y*2);cprintf("-");
                }
            }
        }
        y=0;
        for(i=5;i<(p+1);i++)
        {
            y++;
            fflush(stdin);
            gotoxy(12,5+y*2);cprintf("%s %s\n",e[i].nombre,e[i].apellido);gotoxy(30,5+y*2);cprintf("%s",e[i].carnet);
            if(ingles2[i]==-1)
            {
                gotoxy(74,5+y*2);cprintf("-");
            }else
            {
                gotoxy(74,5+y*2);cprintf("%d",ingles2[i]);
            }
            if (mate1[i]==-1)
            {
                gotoxy(52,5+y*2);cprintf("-");
            }else
            {
                gotoxy(52,5+y*2);cprintf("%d",mate1[i]);
            }
            if (lenguaje[i]==-1)
            {
                gotoxy(63,5+y*2);cprintf("-");
            }else
            {
                gotoxy(63,5+y*2);cprintf("%d",lenguaje[i]);
            }
            if (redaccion[i]==-1)
            {
                gotoxy(68,5+y*2);cprintf("-");
            }else
            {
                gotoxy(68,5+y*2);cprintf("%d",redaccion[i]);
            }
            if (conceptos[i]==-1)
            {
                gotoxy(58,5+y*2);cprintf("-");
            }
            else
            {
                gotoxy(58,5+y*2);cprintf("%d",conceptos[i]);
            }
	        /*gotoxy(74,5+y*2);cprintf("%d",ingles2[i]);gotoxy(52,5+y*2);cprintf("%d",mate1[i]);gotoxy(63,5+y*2);cprintf("%d",lenguaje[i]);gotoxy(68,5+y*2);cprintf("%d",redaccion[i]);gotoxy(58,5+y*2);cprintf("%d",conceptos[i]);*/
        }
        
    }
    gotoxy(15,24);cprintf("<-- to returns");
}
/*---------------------Direccionales para I Y II SEMESTRE-----------------*/
int direc()
{
    int repited=1,selec=1,key,i=0,cont=1;
    char *option[3]={"I SEMESTRE","II SEMESTRE","Regresar"};
    /*for(i=0;i<3;i++){ gotoxy(34,8+cont);cprintf("%s",option[i]); cont+=2;}*/
    do
    {
	    system("cls");
        textcolor(WHITE);menu_vista();
        gotoxy(30,2);cprintf("Seleccione una opcion");
	    gotoxy(32,7+selec);printf(">");gotoxy(47,7+selec);cprintf("<");
	    for(i=0;i<3;i++){
            fflush(stdin); 
            textcolor(WHITE);
            gotoxy(34,8+i*2);printf("%s",option[i]); 
        }
        /*gotoxy(35,8);cprintf("%s",option[0]);gotoxy(35,10);cprintf("%s",option[1]);gotoxy(36,12);cprintf("%s",option[2]);*/
	    do{ key=getch(); }while(key!=UP && key!= DOWN && key!= ENTER);
	    switch(key)
	    {
		    case UP: selec-=2; if(selec<1) selec=5;break;
	        case DOWN: selec+=2; if(selec>5) selec=1;break;
	        case ENTER:repited=0;break;
	    }
    } while (repited);
    return selec;
}

/*-------------------------para el nombre y apellido----------------------*/
void validando(char validar[], int x, int y)
{
    char Reciv_tecla = ' ';
    int i = 0;
    fflush(stdin);
    textcolor(WHITE);
VAL:
    fflush(stdin);
    gotoxy(x, y);
    clreol();
    for (i = 0; i < 17; i++)
    {
        validar[i] = ' ';
    } /*limpiamos TODO!!*/
    i = 0;
llenar:
    while (Reciv_tecla = getch())
    {

        if (Reciv_tecla > 64 && Reciv_tecla < 91 && i < 16 || Reciv_tecla > 96 && Reciv_tecla < 123 && i < 16)
        {
            Reciv_tecla = toupper(Reciv_tecla);
            validar[i] = Reciv_tecla;
            cprintf("%c", validar[i]);
            i++;
            goto llenar;
        }
        if (Reciv_tecla == '\b')
        {
            goto VAL;
        }
        if (i == 2 && Reciv_tecla == '\r')
        {
            goto VAL;
        }
        if (i < 2 && Reciv_tecla == '\r')
        {
            goto VAL;
        }
        if (i > 2 && i < 17 && Reciv_tecla == '\r')
        {
            validar[i] = '\0';
            break;
        }
    } /*Fuera del ciclo preguntamos*/
    if (validar[i] == '\0')
    {
    }
    else
    {
        goto VAL;
    }
}
void validando2(char validar2[], int x, int y)
{
    char Reciv_tecla = ' ';
    int i = 0;
    fflush(stdin);
    textcolor(WHITE);
VAL:
    fflush(stdin);
    gotoxy(x, y);
    clreol();
    for (i = 0; i < 17; i++)
    {
        validar2[i] = ' ';
    } /*limpiamos TODO!!*/
    i = 0;
llenar:
    while (Reciv_tecla = getch())
    {

        if (Reciv_tecla > 64 && Reciv_tecla < 91 && i < 16 || Reciv_tecla > 96 && Reciv_tecla < 123 && i < 16)
        {
            Reciv_tecla = toupper(Reciv_tecla);
            validar2[i] = Reciv_tecla;
            cprintf("%c", validar2[i]);
            i++;
            goto llenar;
        }
        if (Reciv_tecla == '\b')
        {
            goto VAL;
        }
        if (i == 2 && Reciv_tecla == '\r')
        {
            goto VAL;
        }
        if (i < 2 && Reciv_tecla == '\r')
        {
            goto VAL;
        }
        if (i > 2 && i < 17 && Reciv_tecla == '\r')
        {
            validar2[i] = '\0';
            break;
        }
    } /*Fuera del ciclo preguntamos*/
    if (validar2[i] == '\0')
    {
    }
    else
    {
        goto VAL;
    }
}
/*-------------------------para el carnet----------------------*/
void validarCarnet(char array[], int x, int y)
{
    char Reciv_tecla = ' ';
    int i = 0;
    fflush(stdin);
    textcolor(WHITE);
carnet:
    fflush(stdin);
    gotoxy(x, y);
    clreol();
    for (i = 0; i < 11; i++)
    {
        array[i] = ' ';
    } /*limpiamos TODO!!*/
    i = 0;
llenar:
    while (Reciv_tecla = getch()) /*ciclo infinito*/
    {
        fflush(stdin);
        if (Reciv_tecla > 47 && Reciv_tecla < 58 && i < 4) /*Preguntamos si es un numero*/
        {
            array[i] = Reciv_tecla;
            cprintf("%c", array[i]);
            i++;
            goto llenar;
        }
        if (i == 4)
        {
            array[i] = '-';
            cprintf("%c", array[i]);
            i++;
            goto llenar;
        }                                                           /*le ponemos eel guion de forma predeterminada*/
        if (Reciv_tecla > 47 && Reciv_tecla < 58 && i > 4 && i < 9) /*Preguntamos si es un numero*/
        {
            array[i] = Reciv_tecla;
            cprintf("%c", array[i]);
            i++;
            goto llenar;
        }
        if (i == 9)
        {
            array[i] = 'U';
            cprintf("%c", array[i]);
            i++;
        } /*Que le ponga la u ya de forma predeterminada*/
        if (i == 10 && Reciv_tecla == '\r')
        {
            array[i] = '\0';
            break;
        } /*Si el arreglo ya esta lleno*/
        if (Reciv_tecla == '\b')
        {
            goto carnet;
        } /*si borra su numero que lo devuelva*/
        if (Reciv_tecla == '\r')
        {
            goto carnet;
        }
    }
    /*Fuera del ciclo ya validamos si lo que esta digitado es logico o correcto*/
    if (array[0] == '1')
    {
        if (array[1] == '9' && array[2] > 55 && array[2] < 58 && array[3] > 50 && array[3] < 58 && array[10] == '\0')
        { /*Solo sigue su curso porque esta bueno*/
        }
        else
        {
            goto carnet;
        }
    }
    else if (array[0] == '2')
    {
        if (array[1] == '0')
        {
            if (array[2] > 47 && array[2] < 50 && array[3] > 47 && array[3] < 58 && array[10] == '\0')
            { /*Solo sigue su curso*/
            }
            else if (array[2] == '2' && array[3] == '0' && array[10] == '\0')
            { /*Solo sigue su curso*/
            }
            else
            {
                goto carnet;
            }
        }
        else
        {
            goto carnet;
        }
    }
    if (!(array[0] == '1' || array[0] == '2'))
    {
        goto carnet;
    }
    fflush(stdin);
}
int validarNUM(int x, int y)
{
    char Reciv_tecla = ' ';
    int i = 0, entero;
    char arreg[3];

    fflush(stdin);
    textcolor(WHITE);
NUM:
    fflush(stdin);
    gotoxy(x, y);
    clreol();
    for (i = 0; i < 4; i++)
    {
        arreg[i] = ' ';
    } /*limpiamos TODO!!*/
    i = 0;
llenar:
    while (Reciv_tecla = getch())
    {
        if (Reciv_tecla > 47 && Reciv_tecla < 58 && i < 3) /*Preguntamos si es un numero*/
        {
            arreg[i] = Reciv_tecla;
            cprintf("%c", arreg[i]);
            i++;
            goto llenar;
        }
        if (Reciv_tecla == '\b')
        {
            goto NUM;
        } /*si borra su numero que lo devuelva*/
        if (i == 0 && Reciv_tecla == '\r')
        {
            goto NUM;
        }
        if (i == 1 && Reciv_tecla == '\r')
        {
            arreg[i] = '\0';
            break;
        }
        if (i == 2 && Reciv_tecla == '\r')
        {
            arreg[i] = '\0';
            break;
        }
        if (i == 3 && Reciv_tecla == '\r')
        {
            arreg[i] = '\0';
            break;
        }
    }
    /*Fuera del ciclo ya validamos si lo que esta digitado es logico o correcto*/
    if (i == 1 && arreg[0] > 47 && arreg[0] < 58 && arreg[1] == '\0')
    {
    }
    else if (i == 2 && arreg[0] > 48 && arreg[0] < 58 && arreg[1] > 47 && arreg[1] < 58 && arreg[2] == '\0')
    {
    }
    else if (i == 3 && arreg[0] == '1' && arreg[1] == '0' && arreg[2] == '0' && arreg[3] == '\0')
    {
    }
    else
    {
        goto NUM;
    }
    if (!(i == 1 || i == 2 || i == 3))
    {
        goto NUM;
    }
    /*SI ya esta todo bien convertimos*/
    entero = atoi(arreg);
    return entero;
}
int menu2()
{
    int repited=1,selec=1,key,i;
    char *group[]={"1M1","1M2","EXIT"};
    do
    {
	    system("cls");
        textcolor(WHITE);
        gotoxy(28,2);cprintf("Seleccione una opcion");
	    gotoxy(32,7+selec);cprintf(">");gotoxy(40,7+selec);cprintf("<");
	    for(i=0;i<3;i++){ 
            gotoxy(34,8+i*2);cprintf("%s",group[i]); 
        }
        /*gotoxy(35,8);cprintf("%s",group[0]);gotoxy(35,10);cprintf("%s",group[1]);gotoxy(36,12);cprintf("%s",group[2]);*/
	    do{ key=getch(); }while(key!=UP && key!= DOWN && key!= ENTER);
	    switch(key)
	    {
		    case UP: selec-=2; if(selec<1) selec=5;break;
	        case DOWN: selec+=2; if(selec>6) selec=1;break;
	        case ENTER:repited=0;break;
	    }
    } while (repited);
    return selec;
}
void buscar(char val[], int x, int y)
{
    char Reciv_tecla = ' ';
    int i = 0;
    fflush(stdin);
    textcolor(WHITE);
VAL:
    fflush(stdin);
    gotoxy(x, y);
    clreol();
    for (i = 0; i < 17; i++)
    {
        val[i] = ' ';
    } /*limpiamos TODO!!*/
    i = 0;
llenar:
    while (Reciv_tecla = getch())
    {

        if (Reciv_tecla > 64 && Reciv_tecla < 91 && i < 16 || Reciv_tecla > 96 && Reciv_tecla < 123 && i < 16)
        {
            Reciv_tecla = toupper(Reciv_tecla);
            val[i] = Reciv_tecla;
            cprintf("%c", val[i]);
            i++;
            goto llenar;
        }
        if (Reciv_tecla == '\b')
        {
            goto VAL;
        }
        if (i == 2 && Reciv_tecla == '\r')
        {
            goto VAL;
        }
        if (i < 2 && Reciv_tecla == '\r')
        {
            goto VAL;
        }
        if (i > 2 && i < 17 && Reciv_tecla == '\r')
        {
            val[i] = '\0';
            break;
        }
    } /*Fuera del ciclo preguntamos*/
    if (val[i] == '\0')
    {
    }
    else
    {
        goto VAL;
    }
}
/*editar*/
void editar(datos_t e[],int posicion)
{
    char validar[16];
    char validar2[16];
    char array[11];
    int i = 0, opc = 0, x, y;
    int repite = 1, key, seleccion = 0;
    fflush(stdin);
    fflush(stdin);
    textcolor(WHITE);
    menu_vista();
    fflush(stdin);
    gotoxy(15, 3);
    cprintf("Ingrese nombre:");
    x = 35;
    y = 3;
    validando(validar, x, y);
    strcpy(e[posicion].nombre, validar);
    gotoxy(15, 5);
    cprintf("Ingrese apellido:");
    x = 35;
    y = 5;
    validando2(validar2, x, y);
    strcpy(e[posicion].apellido, validar2);
    fflush(stdin); /*todo mal*/

    /*---------------------------------------*/
    /*actualizamos las notas registradas*/
    if(ingles1[posicion]!=-1){
        gotoxy(15, 10);
        cprintf("Ingles I: ");
        x = 30;
        y = 10;
        ingles1[posicion] = validarNUM(x, y);
    }
    if(introduccion[posicion]!=-1){
        
        gotoxy(15, 12);
        cprintf("Introduccion: ");
        x = 30;
        y = 12;
        introduccion[posicion] = validarNUM(x, y);
    }
    if(filosofia[posicion]!=-1){
        gotoxy(15, 14);
        cprintf("Filosofia: ");
        x = 30;
        y = 14;
        filosofia[posicion] = validarNUM(x, y);
    }
    if(geometria[posicion]!=-1){
        gotoxy(15, 16);
        cprintf("Geometria: ");
        x = 30;
        y = 16;
        geometria[posicion] = validarNUM(x, y);
    }
    /*-----------------------------------------------------------------------segundo semestre*/
    if(mate1[posicion]!=-1){
            fflush(stdin);
            gotoxy(50, 10);
            cprintf("Matematicas I: ");
            x = 65;
            y = 10;
            mate1[posicion] = validarNUM(x, y);
    }
    if(redaccion[posicion]!=-1){
        gotoxy(50,12);
        cprintf("Redaccion: ");
        x = 60;
        y = 12;
        redaccion[posicion] = validarNUM(x, y);

    }
    if(conceptos[posicion]!=-1){
        gotoxy(50, 14);
        cprintf("Conceptos: ");
        x = 60;
        y = 14;
        conceptos[posicion] = validarNUM(x, y);
    }
    if(ingles2[posicion]!=-1){
            fflush(stdin);
            gotoxy(50, 16);
            cprintf("Ingles II: ");
            x = 60;
            y = 16;
            ingles2[posicion] = validarNUM(x, y);
    }
    if(lenguaje[posicion]!=-1){
            gotoxy(50, 18);
            cprintf("Lenguaje: ");
            x = 60;
            y = 18;
            lenguaje[posicion] = validarNUM(x, y);
    }   
    gotoxy(15, 23);
    cprintf("PRES ONE KEY TO CONTINUE");
    getch();
    fflush(stdin);
}