// Antonio Villanueva Segura Matriz Rusa 5x5 sin librerias graficas solo terminal
#include<iostream>
#include<stdlib.h>
#include<time.h>
#include <string>
#include <graphics.h>
using namespace std;

//-------------------------------------------------------------------------------------------
int sumaFila (int fila,int matriz[5][5],bool validados[5][5],bool soloValidados=true){
	int suma=0;
	for (int columna=0;columna<5;columna++){
		if (soloValidados){
			if (validados [fila][columna]){//Si en la matriz validados es 1 sumo si no No
				suma+=matriz[fila][columna];//Suma toda esta fila		
			}
		}
		else{//Suma todos los elementos de esta fila , sin utilizar la matriz de validacion
				suma+=matriz[fila][columna];//Suma toda esta fila	
			}
		}

	return suma;
}
//-------------------------------------------------------------------------------------------
int sumaColumna (int columna,int matriz[5][5],bool validados[5][5],bool soloValidados=true){
	int suma=0;

	for (int fila=0;fila<5;fila++){;

		if (soloValidados){
			if (validados [fila][columna]){//Si en la matriz validados es 1 sumo si no No
				suma+=matriz[fila][columna];//Suma toda esta fila		
			}
			
		}
		else{//Suma todos los elementos de esta fila , sin utilizar la matriz de validacion
				suma+=matriz[fila][columna];//Suma toda esta fila	
			}			
		}
	
	return suma;
}

//-------------------------------------------------------------------------------------------
bool testLinea(int linea,int a[5][5],bool b[5][5],bool c[5][5]){//Compara matriz usuario con la prevista
	//Si la lina coincide con lo previsto retorna verdadero si no falso
	if (sumaFila (linea,a,b) == sumaFila (linea,a,c)){
		return true;
	}
	return false;
}

//-------------------------------------------------------------------------------------------
bool testColumna(int columna,int a[5][5],bool b[5][5],bool c[5][5]){//Compara matriz usuario con la prevista
	//Si la columna usuario maquina  retorna verdadero si no falso
	if (sumaColumna (columna,a,b) == sumaColumna (columna,a,c)){//cpu == usuario ?
		return true;
	}
	return false;
}
//-------------------------------------------------------------------------------------------
string creaSuperior(int matriz[5][5],bool validados[5][5],bool usuario[5][5]){
	//Crea la linea de sumas, superior , suma de columnas de datos validados en la matriz validados[]
	string LineaSuperior="";
	for (int columna=0;columna<5;columna++){	
		
		if ( !(testColumna(columna,matriz,validados,usuario))){//Coincide la suma esperada con la del usuario ?	
			LineaSuperior+="["+to_string (sumaColumna(columna,matriz,validados)) +"]\t";//Solo datos validados
		}else{
			LineaSuperior+="[*]\t";
		}
	}
	return LineaSuperior;
}

//-------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------

int main(){
	int opc;
	int x,y;
	int matriz1[5][5];//La creo sin inicializar , sin valores predefinidos , salvo que quieras valores concretos 
	bool validados[5][5];//Datos aleatorios 1 o 0, que es lo que voy a sumar de  la anterior , puede ser fijo si quieres 
	bool usuario[5][5];//Datos que introduce el usuario
	
	srand(time(NULL));//generamos aleatoriamente ciertas posiciones 	
		
//Creo , inicializo valores de la matriz1 y la matriz "validados" , dos por uno , en un mismo bucle
   	for (int x=0;x<5;x++){
		for (int y=0;y<5;y++){
			matriz1[x][y]=1+rand()%9;//Valores Numericos
			validados[x][y]=rand()%2;//Si es 1 se suma  0 no se suma 
			usuario[x][y]=true;//Todos los elementos se suman
		}
	}

	cout <<" I N I C I A L I Z A D A S  MATRICES "<<endl;
   	   	
//BUCLE PRINCIPAL juego -------------------------------------------------------------------
	while (true){//Bucle principal del juego
					
//MATRIZ DE USUARIO	
			cout <<"DATOS ENTRADA USUARIO"<<endl;
			for (int linea=0;linea<5;linea++){
				cout <<"\n\t\t\t";
				for (int columna=0;columna<5;columna++){
					cout<<usuario [linea][columna] <<"\t";
				}
				cout<<endl;//Salto de linea
			}			
			
			cout<<"DATOS VALIDADOS "<<endl;
//MATRIZ DE DATOS VALIDADOS EN validados [5][5] ...pueden ser fijos			
			for (int linea=0;linea<5;linea++){
				cout <<"\n\t\t\t";
				for (int columna=0;columna<5;columna++){
					cout<<validados [linea][columna] <<"\t";
				}
				cout<<endl;//Salto de linea
			}
			
//DATOS DE LA MATRIZ CON LAS SUMAS			
			cout<<"MATRIZ "<<endl;   
			cout << "\n\t\t\t"<<creaSuperior (matriz1,validados,usuario)<<endl;//Suma superior	
			
			
			for (int linea=0;linea<5;linea++){//Recorre todas la lineas
				
				
				//Crea lateral izquierda
				if  (!testLinea(linea,matriz1,validados,usuario)){//Valida la suma
					
					cout <<"\n\t\t"<<"["<<to_string (sumaFila(linea,matriz1,validados))<<"]";//Suma izquierda
				}else{cout <<"\n\t\t[*]";}
				
				cout <<"\t";
				
				
				for (int columna=0;columna<5;columna++){//Imprime la matriz1 entera
					cout<< matriz1 [linea][columna] << "\t";
				}
				
				//cout <<"["<<to_string (sumaFila(linea,matriz1,validados))<<"]";//Suma derecha
				
				//Crea laterala derecho
				//Crea lateral izquierda
				if  (!testLinea(linea,matriz1,validados,usuario)){//Valida la suma
					
					cout <<"["<<to_string (sumaFila(linea,matriz1,validados))<<"]";//Suma izquierda
				}else{cout <<"[*]";}			
				
				
				cout<<endl;//Salto de linea
			}   	
			
			cout << "\n\t\t\t"<<creaSuperior (matriz1,validados,usuario)<<endl;//Suma inferior	   	
			

			cout<<"\t ===================================================="<<endl;

// FIN DATOS DE LA MATRIZ CON LAS SUMAS	

//Entrada de datos		
			cout <<"Introduzca la coordenada a modificar ,elemento que se elimina o anade "<<endl;
			
			cout <<"x:";cin>>y;
			cout <<"y:";cin >>x;
		
			usuario[x][y]=!usuario[x][y];//Invierte el estado del usuario , invertimos en la matriz de usuario
		
			cout <<"Modificado "<<to_string(x)<<","<<to_string(y)<<" = "<<to_string(usuario[x][y])<<endl;
			
	}
}
