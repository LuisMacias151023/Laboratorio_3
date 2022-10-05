/******************************************************************************
 // FileName:        main.cpp
 // Program version: Dev-C++ 5.11
 // Company:         TECNM - ITCH
 // Description:     LABORATORIO 3
 // Authors:         LUIS MACIAS
 // Updated:         03/10/2022
 
******************************************************************************/
#include <iostream>					
#include <stdlib.h>				
#include <cmath>					
using namespace std;

class ADC
{
	/*atributos*/
	private:
		static unsigned int resolucion;		  /* Resolución de 8,10 o 12*/
		static  float frecuencia;			  /* Frecuencia de Muestreo*/
		float voltaje;						  /*Voltaje de Entrada  0 a 3.3v*/
		float vout;				              /* conversion*/
	
	public:
		/*metodos*/
		ADC() {};	                            /*constructor*/
		float conversion();					    
		void captura (float);
		static void resol (int);
		static void frecu(float);
		static float getfrec();
};

/*inicializacion de las variables static*/
unsigned int ADC::resolucion = 0;
float ADC::frecuencia = 0;

/*inicializacion metodos*/
void ADC::resol(int _resolucion) {
resolucion = _resolucion;
}

void ADC::frecu(float _frecuencia) {
frecuencia = _frecuencia;
}

void ADC::captura(float _voltaje) {
voltaje = _voltaje;
}
/*getter*/
float ADC:: getfrec () {
return frecuencia;
}

float ADC::conversion()
{	
	/* ecuacion para adc*/
	vout = (voltaje*pow(2,resolucion)-1)/3.3;

	return vout;
}



/*prototipo de funcion*/
void portada(void);
void cap(void);
void cleanbuffin(void);
/*globales*/
  int i,res,cantidad;
  float volt,frec;
/*funcion main*/
int main()
{	 
    portada();
    cout<<"***************************CONVERTIDOR ADC***************************\n"<<endl;
	cap();
	ADC canal[cantidad];								/*arreglo de objetos*/
	
	for(i=0;i<cantidad;i++)
	{
		cout<<"TECLEA EL VALOR DEL CANAL AN"<<i+1<<": ";
		cleanbuffin();
								
		do										
		{
			cin>>volt;							
			
			if(volt>3.3)						
			cout<<"DATOS INVALIDOS"<<"\n"<<endl;	
		}
		
		while(volt>3.3);
		canal[i].captura(volt);
	}
	getchar();
	cout<<"\n";
	cout<<"            PRESIONA UNA TECLA PARA MOSTRAR LOS DATOS DE SALIDA..."<<endl;
	getchar();
	
	/*Imprime datos*/
	for(i=0;i<cantidad;i++)								
	{
		cout<<"El VALOR CONVERTIDO DE AN"<<i+1<<" CON FRECUENCIA "<<ADC::getfrec()<<" Hz"<<": "<<canal[i].conversion()<<endl;

	}
	getchar();
	return 0;
}
void cap(){
	
	do 											
	{
	    cout<<"TECLEA EL NUMERO DE CANALES A USAR (AN1...AN32): ";
	    cin>>cantidad;
	    cleanbuffin();
	    
	    if(!(cantidad>=1 && cantidad<32))
	    	cout<<" ERROR, DATOS INVALIDOS  \n"<<endl;
			
	}while(cantidad<1 || cantidad>32);
	   	
	do												//Validación de Datos Resolución
	{
		cout<<"TECLEA UNA RESOLUCION DE (8, 10, 12) Bits:  ";
		cin>>res;

		cleanbuffin();
		
		if(!(res == 8||res == 10||res == 12))
			cout<<"DATOS INVALIDOS"<<endl;	
		
	}while(!(res == 8||res == 10||res == 12));

	
	cout<<"TECLEA UNA FRECUENCIA DE MUESTREO: ";
	cin>>frec;
	
	ADC::resol(res);
	ADC::frecu(frec);
	
}
void portada(){

 cout<<"******************************************************************************"<<endl;
 cout<<"**FileName:        main.cpp"<<endl;
 cout<<"**Program version: Dev-C++ 5.11"<<endl;
 cout<<"**Company:         TECNM - ITCH"<<endl;
 cout<<"*Description:     LABORATORIO 3*"<<endl;
 cout<<"**Authors:         LUIS MACIAS"<<endl;
 cout<<"**Updated:         03/10/2022"<<endl;
}

/*funcion cleanbuffin para limpiar el buffer*/
void cleanbuffin(void){     
	int ch;
	while ((ch = fgetc(stdin)) != EOF)  /* Brinca o descarta todos los caracteres de stdin, */
	{                                   /* hasta que se encuentra con EOF, llegado al final del buffer.*/
	  if( ch == '\n' ) break;           /* o si encuentra un salto de linea */
	}
}

