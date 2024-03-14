#include <iostream>
#include <fstream>
#include <string.h>
#include <stdlib.h>
#include <cstdlib>
#include <conio.h>
#include <windows.h>
#include <math.h>
#include <ctype.h>


using namespace std;

void gotoxy(int x,int y)
{

	HANDLE hCon=GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;
	SetConsoleCursorPosition(hCon,dwPos);
}
//lineas hotzontales
void lineaH(int x, int y, int r, char tipo)
{
	for (int i=x; i<=x+r; i++)
	{
		gotoxy(i,y);
		if (tipo=='s')
			cout<<(char)(196);
		else
			cout<<(char)(205);
	}
}
//LINEAS VERTICALES
void lineaV(int x, int y, int r, char tipo)
{
	for (int j=y; j<=y+r; j++)
	{
		gotoxy(x,j);
		if (tipo=='s')
			cout<<(char)(179);
		else
			cout<<(char)(186);
	}
}

struct recibo
{
	char codigo[10];
	char nombre [20];
	char ciudad [20];
	char fecha[20];
	char concepto[10];
	float valor ;
};


char cadena[20];
recibo e[50];
char cod[5];


//-------------------------------------
int leer_archivo()
{	
	//ifstream permite trabajar el archivo en modo de lectura
	ifstream leer;
	//open permite abrir el archivo
	leer.open ("recibos.txt");
	//good indica si la operacion de abrir el archivo fue exitosa
	//bad indica produjo una operacion invalida
	//fail indica si se produjo un error
	if (leer.good())
	{
		cout<<"El archivo fue abierto correctamente..."<<endl;
		//eof () Produce un 1 si se encuentra en el final del archivo
	// !leer.eof() indica que no esta en el final del archivo
		int i;
        i=0;
        while(!leer.eof())
        {
            leer>>cadena;
            strcpy(e[i].codigo,cadena);
            leer>>cadena;
            strcpy(e[i].nombre,cadena);
            leer>>cadena;
            strcpy(e[i].ciudad,cadena);
            leer>>cadena;
            strcpy(e[i].fecha,cadena);
            leer>>cadena;
            strcpy(e[i].concepto,cadena);
            leer>>cadena;
            e[i].valor=atof(cadena);
            i++;
        }
        //close permite cerrar el archivo
        leer.close();
        return (i);

	}
	else
	{
		cout<<"El archivo no se pudo abrir..."<<endl;
        return (-1);
	}

}


void capturar_dato(int n)
{
			
			cout <<"Codigo: ";
    		cin >>e[n].codigo;
    		cout <<"Pagado a: ";
    		cin >>e[n].nombre;
    		cout <<"Ciudad: ";
    		cin >>e[n].ciudad;
    		cout <<"fecha: ";
    		cin >>e[n].fecha;
    		cout <<"Concepto: ";
    		cin >>e[n].concepto;
    		cout <<"valor: ";
    		cin >>e[n].valor;
    		

    		
}

void imprime(int i)
{



		gotoxy(5,1);
		cout<<e[i].codigo;
		gotoxy(15,1);
		cout<<e[i].fecha;
		gotoxy(30,1);
		cout<<e[i].nombre;
		gotoxy(45,1);
		cout<<e[i].valor;
		gotoxy(55,1);
		cout<<e[i].ciudad;
		cout<<"\n";
		
}

void escribirarchivo(int n)
{
	ofstream escribir;
	escribir.open ("recibos.txt");
    if(escribir.good())
    {
    	cout<<"El archivo fue abierto correctamente..."<<endl;
    	int j = n - 1;
    	for (int i=0;i<n;i++)
        {
        		
    		escribir<<e[i].codigo;
            escribir<<(char)9; //Espacio en Blanco
            escribir<<e[i].nombre;
            escribir<<(char)9; //Espacio en Blanco
            escribir<<e[i].ciudad;
            escribir<<(char)9; //Espacio en Blanco
            escribir<<e[i].fecha;
            escribir<<(char)9; //Espacio en Blanco
            escribir<<e[i].concepto;
            escribir<<(char)9; //Espacio en Blanco
            escribir<<e[i].valor;
            if (i < j)
			{
            	escribir<<(char)10; //Salto de Linea
        	}
      }
		
        /*for (int i=0;i<n;i++)
        {
        	//cout<<"sssiii.."<<endl;
            //32 Espacio en blanco
            //10 Salto de Linea
            //9 Tabulador Horizontal
            escribir<<e[i].codigo;
            escribir<<(char)9; //Espacio en Blanco
            escribir<<e[i].nombre;
            escribir<<(char)9; //Espacio en Blanco
            escribir<<e[i].n1;
            escribir<<(char)9; //Espacio en Blanco
            escribir<<e[i].n2;
            escribir<<(char)9; //Espacio en Blanco
            escribir<<e[i].n3;
            escribir<<(char)9; //Espacio en Blanco
            escribir<<(char)10; //Salto de Linea
        }*/
        escribir.close();
    }
    else
    {
    	cout<<"El archivo no se pudo abrir..."<<endl;
    }
}
	int plano=0;
void lista_recibo(int n)
{	

	int num_menor;
	int num_mayor;
	for(int i=0;i<n;i++)
	{
		if(i==0)
		{
			num_menor=e[i].valor;
			num_mayor=num_menor;				
		}
		else
		{
			if(num_mayor<e[i].valor)
			{
				num_mayor=e[i].valor;
			}
			if(num_menor>e[i].valor)
			{
				num_menor=e[i].valor;
			}
		}
		
	}
	int total=0;
	for(int i=0;i<n;i++)
	{
		total=total+e[i].valor;
	}

	
	
	
	//system("cls");

	lineaH (4,0,60,'s');
	lineaH (4,2,60,'s');
	lineaV(65,1,plano++,'s'); 
	gotoxy(5,1);
	cout<<"#RC.";
	gotoxy(15,1);
	cout<<"Fecha";
	gotoxy(30,1);
	cout<<"Pagado A";
	gotoxy(45,1);
	cout<<"Valor";
	gotoxy(55,1);
	cout<<"Ciudad";
	cout<<"\n";


	for(int i=0;i<n;i++)
	{
		plano++;
		gotoxy(5,i+3);
		cout<<e[i].codigo;
		gotoxy(15,i+3);
		cout<<e[i].fecha;
		gotoxy(30,i+3);
		cout<<e[i].nombre;
		gotoxy(45,i+3);
		cout<<e[i].valor;
		gotoxy(55,i+3);
		cout<<e[i].ciudad;
				plano+1;

	}
	int x=plano;
	lineaH (5,x+3,60,'s');
    lineaV(65,3,x++,'s');
    lineaV(4,1,x+1,'s'); 
    gotoxy(4,0);
    printf("%c",218);
    gotoxy(4,x+2);
    printf("%c",192);
    gotoxy(65,0);
    printf("%c",191);
    gotoxy(65,x+2);
    printf("%c",217);
    gotoxy(65,2);
    printf("%c",180);
    gotoxy(4,2);
    printf("%c",195);
	    
	//cout<<plano;
	gotoxy(5,plano+4);
	cout<<"TOTAL:";
	gotoxy(12,plano+4);
	cout<<total;
	gotoxy(5,plano+5);
	cout<<"valor max: ";
	gotoxy(15,plano+5);
	cout<<num_mayor;
	gotoxy(5,plano+6);
	cout<<"valor min: ";
	gotoxy(15,plano+6);
	cout<<num_menor;
	cout<<"\n";
	
	getch();
	/*cout<<"\n";
	cout<<"\n";
	cout<<"\n";*/
	
}


void Consultar_recibo(char cod[],int n)
{
	int b=0;
	for(int i=0;i<n;i++)
	{
		if(strcmp(cod,e[i].codigo)==0)
		{
		lineaH (5,12,70,'s');
		lineaH (5,8,70,'s');
		lineaH (5,6,70,'s');
		lineaH (5,4,70,'s');
		lineaH (54,2,21,'s');
		lineaH (5,10,70,'s');
		lineaV(4,4,8,'s');
		lineaV(28,4,1,'s');
		lineaV(53,2,6,'s');
		lineaV(76,2,10,'s');
	
	//primer linea izq
		gotoxy(3,4);
		printf(" %c",218);
		gotoxy(4,12);
		printf("%c",192);
        gotoxy(4,8);
		printf("%c",195);
		gotoxy(4,6);
		printf("%c",195);
		gotoxy(4,10);
		printf("%c",195);
		
		//segunda linea
		gotoxy(28,4);
		printf("%c",194);
		gotoxy(28,6);
		printf("%c",193);
		//tercera linea
		gotoxy(53,2);
		printf("%c",218);
		gotoxy(53,4);
		printf("%c",197);
		gotoxy(53,6);
		printf("%c",197);
		gotoxy(53,8);
		printf("%c",193);
		//ultima linea
		gotoxy(76,2);
		printf("%c",191);
		gotoxy(76,4);
		printf("%c",180);
		gotoxy(76,6);
		printf("%c",180);
		gotoxy(76,8);
		printf("%c",180);
		gotoxy(76,10);
		printf("%c",180);
		gotoxy(76,12);
		printf("%c",217);
		
		


		
	
		
		gotoxy(55,3);
		cout<<"Recibo de Caja Menor";
		gotoxy(55,5);
		cout<<"No.";
		gotoxy(30,5);
		cout<<"Fecha";
		gotoxy(5,9);
		cout<<"Pagado A";
		gotoxy(5,5);
		cout<<"Ciudad";
		gotoxy(5,7);
		cout<<"Concepto";
		gotoxy(55,7);
		cout<<"Valor: $";
		gotoxy(5,11);
		cout<<"Valor";
	

		gotoxy(64,5);
		cout<<e[i].codigo;
		gotoxy(37,5);
		cout<<e[i].fecha;
		gotoxy(15,9);
		cout<<e[i].nombre;
		gotoxy(64,7);
		cout<<e[i].valor;
		gotoxy(15,5);
		cout<<e[i].ciudad;
		gotoxy(15,7);
		cout<<e[i].concepto;
		b=1;
		getch();
		
		}
	}
	if(b==0)
	{
		cout<<"el codigo no existe...\n";
	}	
}

void modificar_datos(int n)
{
	cout<<"Escriba el codigo del recibo que quiere --> ";
	cin>>cod;
	int pos;
	for(int i=0;i<n;i++)
	{
		if (strcmp(cod,e[i].codigo)==0)
		{
				pos=i;
			   	cout<<"datos de la persona  "<<endl;
   	            cout<<"Codigo --> "<<e[i].codigo<<endl;
   				cout<<"Nombre --> "<<e[i].nombre<<" --> ";
   				cin>>e[i].nombre;
   				cout<<"Ciudad --> "<<e[i].ciudad<<" --> ";
   				cin>>e[i].ciudad;
   				cout<<"Fecha --> "<<e[i].fecha<<" --> ";
   				cin>>e[i].fecha;
   				cout<<"concepto --> "<<e[i].concepto<<" --> ";
   				cin>>e[i].concepto;
   				cout<<"valor --> "<<e[i].valor<<" --> ";
   				cin>>e[i].valor;
		}
		
	}
	system("cls");
    cout<<"datos modificados";
	cout<<"\n";
	imprime(pos);
}









void menu(int n)
{
    int op;
    //op ='0';
    int j = 1;
    while (j!=0)
	{
		cout<<n<<endl; //para imprimir la cantidad de recibos

		lineaH (22,2,38,'s');
	    lineaH (22,4,38,'s');
		lineaH (22,11,38,'s');
		lineaV (22,2,9,'s');
		lineaV(60,2,9,'s');
		gotoxy(22,2);
		printf("%c",218);
		gotoxy(22,4);
		printf("%c",195);
		gotoxy(22,11);
		printf("%c",192);
		////////////////
		gotoxy(60,2);
		printf("%c",191);
		gotoxy(60,4);
		printf("%c",180);
		gotoxy(60,11);
		printf("%c",217);
		
		
		gotoxy(23,3);
		cout<<"MENU PRINCIPAL"<<endl;
    	gotoxy(23,5);
		cout<<"1.Capturar Documento"<<endl;
		gotoxy(23,6);
		cout<<"2.Consultar Documento"<<endl;
		gotoxy(23,7);
		cout<<"3.Listar Documentos"<<endl;
		gotoxy(23,8);
		cout<<"4.Modificar Documento"<<endl;
		gotoxy(23,9);
		cout<<"5.Salir"<<endl;
		gotoxy(23,10);
		cout<<"Seleccione una opcion(1-5): ";

		
		int valido;
		cin>>op; /*Esto porque scanf devuelve valor 0 cuando el valor ingresado no es del formato solicitado*/
		valido=op;
		if(!valido)
		{
			system("cls");
			cout<<"ERROR, no es un numero";
			break;
		}
		if(valido)
		{	
			switch (op)
			{
			case 1:
					if(n<50)
					{
						system("cls");
						capturar_dato(n);
						system("pause");
		                system("cls");
		                cout<<"datos guardados";
		                cout<<"\n";
		                imprime(n);
		                system("pause");
		                system("cls");
		                n++;
		                escribirarchivo(n);
		                plano=0;
		            
	            	}
	            	else
	            	{
	            		cout<<"supero la maxima cantidad de datos"<<endl;
	            		system("pause");
		                system("cls");
					}
					break;
				case 2:
					system("cls");
					char cod[5];
					cout<<"digite  el codigo que quiere consultar: ";
					cin>>cod;
					system("cls");
					Consultar_recibo(cod,n);
		            system("cls");
					break;
				case 3:
					if (n){
					system("cls");
					lista_recibo(n);
					//system("pause");
	                system("cls");
	            	}
					break;
				case 4:
					system("cls");
					modificar_datos(n);
					system("pause");
		            system("cls");
		            escribirarchivo(n);
		            system("pause");
		            system("cls");
					break;
	            case 5:
	            	cout<<"\n";
	                cout<<"A seleccionada la opcion de salir  : ADIOS)";
	                cout<<"\n";
	                system("pause");
	            	system("cls");
	                j = 0;
	                break;
	            default:
	            	//op = 6;
	            	cout<<"\n";
	            	cout<<"Elija una opcion que este dentro de los numeros dados .\n";
	            	getch();
	           		system("pause");
	            	system("cls");
	            	//cout<<op;
	            	break;
	            	//menu(n);
	            	
			}
		}
	}
}


main()
{

	int n;
	n = leer_archivo();
	if (n !=-1)
	{
		menu(n);	
	}	
}




