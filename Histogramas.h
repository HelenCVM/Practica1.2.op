#pragma once

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <vector>
#include <fstream>
#include <sstream>
#include<algorithm>
//listado de directorio
# include <opencv2/dirent.h>

// Cuando se carga la cabecer opencv.hpp autom�ticamente se cargan las dem�s cabeceras
//#include <opencv2/opencv.hpp>

#include <opencv2/core/core.hpp> // Contiene los elementos b�sicos como el objeto Mat (matriz que representa la imagen)
#include <opencv2/highgui/highgui.hpp> // Contiene los elementos para crear una interfaz gr�fica b�sica
// OpenCV no est� pensado para crear interfaces gr�ficas potentes. Se centra en la visi�n artificial y PDI. Si se desea crear una interfaz gr�fica completa, se debe usar QT

#include <opencv2/imgcodecs/imgcodecs.hpp> // Contiene las funcionalidad para acceder a los c�decs que permiten leer diferentes formatos de imagen (JPEG, JPEG-2000, PNG, TIFF, GIF, etc.)

// Librer�as para acceder al video y para poder escribir v�deos en disco
#include <opencv2/video/video.hpp> 
#include <opencv2/videoio/videoio.hpp>

#include <opencv2/imgproc/imgproc.hpp> // Librer�a para realizar operaciones de PDI 


using namespace std;
using namespace cv;

class Histograma
{
public:
	Histograma(string);
	vector <string> listarDirectorio(string); //la clase vector es la equivalente del arraylist en java
	vector<int>CalculoHistograma(vector <string>,vector<string>);
	void CalcularHistogramaHSV(vector<string>);
	void Distancia(vector<string>, vector<string>);
	void Train(vector<string>);
private:
	string path;
};
