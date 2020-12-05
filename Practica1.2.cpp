// Practica1.2.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include "Histogramas.h"

int main(int argc, char* argv[])
{
	Histograma* histograma = new Histograma("Probando");
	vector <string> lista = histograma->listarDirectorio("C:/Disco Helen/Universidad/8vo/Vision-por-computador/Utilizable/Icons-50");
	//vector <string> listaHSV = histograma->listarDirectorio("C:/Users/helen/Downloads/Icons-50/airplane/");

	//histograma->CalculoHistograma(lista);
	histograma->Train(lista);
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
