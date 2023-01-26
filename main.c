//Practica 3
//Mendiante comunicacion UART enviar un nombre, recibirlo e invertilo 
//y reenviarlo con numeros consecutivos 
#include "lib/include.h"

//LECTURA DE CADENA 
char *leer_nombre(char delim, int *ptr)
{
    char letra;
    static char arreglo[50];
    int contador = 0;
    letra = readChar();  
    while (letra != delim)
    {
        arreglo[contador] = letra;
        letra = readChar();
        contador ++;
    }
    *ptr = strlen(arreglo );
    return &arreglo[0];
}

//INVERTIR CADENA
char *invertir_nombre(char *nombre, int longi)
{
    static char nombre_invertido[50];
    int cont = 0;
    int index = 0; 
    for (int i = longi; i > 0; i--)
    {
        nombre_invertido[cont] = *(nombre + (i -1));
        nombre_invertido[cont + 1] = index + '0';
        index ++; 
        cont = cont + 2;
    }
    nombre_invertido[cont - 1] = '\n'; 
    return &nombre_invertido[0];
}


int main(void)
{
    uint16_t valor = 0;
    char c='5';

    Configurar_PLL(_25MHZ);  //Confiuracion de velocidad de reloj
    Configurar_GPIO();
    Configurar_UART1();// FCLK 25MHz, baud rate 57600

    //Experimento 1
    //  Configurar_UART1(); //Jorge,Alberto,Navarro,Saul,Fabela -fclk 25MHZ Baud-rate 57600
    //  Configurar_UART7(); //Angel,Fernanda,Sonia,Aleidis,Monse -fclk 50MHZ Baud-rate 57600
    //  Configurar_UART4(); //Argelia,Roxana,Yesica,Vanesa,Christian,Abiu -fclk 10MHZ Baud-rate 4800
    //  Configurar_UART2(); //Brizet,Monse,Luis,Majo,Alonso -fclk 40MHZ Baud-rate 115200
    //  Configurar_UART3(); //Jesus,Yesica,Carlos,Dulce,Rodolfo,Leonardo -fclk 80MHZ Baud-rate 19200
    //  Configurar_UART2(); //Andrea,Avila,Pamela,Paulina -fclk 50MHZ Baud-rate 57600
    //  Configurar_UART5(); //Hector,Cecilia,Carolina,Jozzafat -fclk 40MHZ Baud-rate 28800
    
    int longitud;
    longitud = 0;

    while(1)
    {
         c = readChar();
         switch(c)
         {
             case 'r':
                 //GPIODATA port F 662
                 printChar('a');
                 GPIOF->DATA = (1<<1);
                 break;
             case 'b':
                 //GPIODATA port F 662
                 printChar('b');
                 GPIOF->DATA = (1<<2);
                 break;
             case 'g':
                 //GPIODATA port F 662
                 printChar('c');
                 GPIOF->DATA = (1<<3);
                 break;
             case 'y':
                 //GPIODATA port F 662
                 printChar('d');
                 GPIOF->DATA = (1<<3) | (1<<2);
                 break;
             default:
                 printChar((char)valor);
                 GPIOF->DATA = (0<<1) | (0<<2) | (0<<3);
                 break;
    char *nombre = leer_nombre(',',&longitud);
    char *nombre_invertido = invertir_nombre(nombre,longitud);
    printString(nombre_invertido);
         }
    }
}
