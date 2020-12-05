#include "Histogramas.h"
int histo[256];
int histoHSV[256];
vector  < int>  listaGris;

Histograma::Histograma(string path)
{
	this->path = path;
}
vector <string> Histograma::listarDirectorio(string path)
{
	vector <string> lista;
	DIR* pDir = opendir(path.c_str());
	struct dirent* entrada;
	while ((entrada = readdir(pDir)) != NULL) {
		lista.push_back(string(entrada->d_name));
	}
	closedir(pDir);
	return lista;

}



void Histograma::Train(vector <string> listaima) {

	vector<string>list;

	vector<string> list2;
	vector<string>list1;
	vector <int> trainList;
	vector <int> testList;
	int train;
	int test;
	int count = 0;
	for (size_t i = 2; i < listaima.size(); i++) {

		cout << "Imagenes del metodo train" << listaima[i] << endl;
		//	cout << "Mat" << imagen;
		count += 1;

		string dire = "C:/Disco Helen/Universidad/8vo/Vision-por-computador/Utilizable/Icons-50/" + listaima[i] + "/";
		//cout << "dire" << dire;

		list = listarDirectorio(dire);

		int count1 = 0;
		double co = list.size();
		int co1 = co * 0.8;
		for (size_t j = 2; j < list.size(); j++) {
			if (j <= co1) {

				list2.push_back(dire + list[j]);
				cout << "direcciones Train: " << list[j] << endl;
				cout << "Trainnnnnnnnn: " << list2.size() << endl;
				cout << "Metodo" << endl;
			}
			else if (j > co1) {
				list1.push_back(dire + list[j]);
				cout << "direcciones: Test" << list[j] << endl;
				cout << "Test: " << list1.size();
			}

			count1 += 1;

			cout << " " << endl;

		}

		cout << "tamanio del train: " << co1 << endl;


		for (size_t o = 0; o < list2.size(); o++)
		{
			cout << "Imprimiendo  LISTA_TRAIN: " << list2[o] << endl;

		}



		for (size_t t = 0; t < list1.size(); t++)
		{
			cout << " Imprimiendo LISTA_TEST: " << dire << list1[t] << endl;
			//	CalculoHistograma(list1)

		}

		trainList = CalculoHistograma(list2,list1);
		//testList = CalculoHistograma(list1);

		/*
		for (size_t x = 0; x < list2.size(); x++)
		{

			cout << "total train" << trainList[x];
			for (size_t w = 0; w < list1.size(); w++)
			{
				cout << "total test" << testList[w];

				if (testList[w] <= +trainList[x])
				{
					cout << "menores" << endl;

				}
			}


		}
		*/
	}


}


vector<int> Histograma::CalculoHistograma(vector <string> train, vector <string> test) {
	// Para leer la imagen se coloca el nombre y el modo de carga (original, escala de grises)
	cout << "Metodo de GRAY" << endl;

	Mat histoB;
	Mat histoG;
	Mat histoR;

	Mat histoBtrain;
	Mat histoGtrain;
	Mat histoRtrain;

	
	for (size_t i = 0; i < train.size(); i++)
	{
		cout << "Train lista" << train[i];
	}

	for (size_t i = 0; i < test.size(); i++)
	{
		cout << "Test lista" << test[i];
	}

	vector<int> trainList;
	for (size_t i = 0; i < test.size(); i++)
	{

		cout << test[i] << endl;
		Mat imagen = imread(test[i], IMREAD_UNCHANGED);
		Mat gris;

		//cvtColor(imagen, gris, COLOR_BGR2GRAY);
		vector<Mat> canalesBGR;
		split(imagen, canalesBGR);
		float rango[] = { 0, 256 };
		const float* rangoHistograma = { rango };
		vector<Mat> Resultado;
		// Aqu� se guardar� el histograma del canal Azul como una matriz de una sola columna y n filas
		int tam = 256;

		//Funci�n de OpenCV para calcular el histograma(permite calcular el histograma de un conjunto de im�genes)
		calcHist(&canalesBGR[0], 1, 0, Mat(), histoB, 1, &tam, &rangoHistograma, true, false);
		calcHist(&canalesBGR[1], 1, 0, Mat(), histoG, 1, &tam, &rangoHistograma, true, false);
		calcHist(&canalesBGR[2], 1, 0, Mat(), histoR, 1, &tam, &rangoHistograma, true, false);

		// Imprimimos el tama�o del histograma

		cout << "Filas: " << histoB.rows << " Columnas: " << histoB.cols << " Canales: " << histoB.channels() << endl;
		cout << "Primera canal";

		cout << "Tercera canal";
		for (int i = 0; i < histoR.rows; i++) {
			cout << "Histograma test Rojo" << histoR.at<float>(i, 0) << ",";
		}
		for (int i = 0; i < histoG.rows; i++) {
			cout << "Histograma test Verde" << histoG.at<float>(i, 0) << ",";
		}
		for (int i = 0; i < histoB.rows; i++) {
			cout << "Histograma test Blu"  << histoB.at<float>(i, 0) << ",";
		}
		cout << endl;

		//CAlculoooooooooooooooooooooooooooooooooooooooo

	}

	for (size_t j = 0; j < train.size(); j++)
	{

		cout << train[j] << endl;
		Mat imagentrain = imread(train[j], IMREAD_UNCHANGED);


		//cvtColor(imagen, gris, COLOR_BGR2GRAY);
		vector<Mat> canalesBGRTrain;
		split(imagentrain, canalesBGRTrain);
		float rangoo[] = { 0, 256 };
		const float* rangoHistogramaTrain = { rangoo };
		vector<Mat> Resultado;
		// Aqu� se guardar� el histograma del canal Azul como una matriz de una sola columna y n filas
		int tam = 256;

		//Funci�n de OpenCV para calcular el histograma(permite calcular el histograma de un conjunto de im�genes)
		calcHist(&canalesBGRTrain[0], 1, 0, Mat(), histoBtrain, 1, &tam, &rangoHistogramaTrain, true, false);
		calcHist(&canalesBGRTrain[1], 1, 0, Mat(), histoGtrain, 1, &tam, &rangoHistogramaTrain, true, false);
		calcHist(&canalesBGRTrain[2], 1, 0, Mat(), histoRtrain, 1, &tam, &rangoHistogramaTrain, true, false);

		// Imprimimos el tama�o del histograma

		cout << "Filas: " << histoBtrain.rows << " Columnas: " << histoBtrain.cols << " Canales: " << histoBtrain.channels() << endl;
		
		for (int i = 0; i < histoRtrain.rows; i++) {
			cout << "Histograma train Rojo" << histoRtrain.at<float>(i, 0) << ",";
		}
		for (int i = 0; i < histoGtrain.rows; i++) {
			cout << "Histograma train Verde" << histoGtrain.at<float>(i, 0) << ",";
		}
		for (int i = 0; i < histoBtrain.rows; i++) {
			cout<< "Histograma train Blu" << histoBtrain.at<float>(i, 0) << ",";
		}
		cout << endl;

		//CAlculoooooooooooooooooooooooooooooooooooooooo

	}

	int restRojo = 0;
	int restBlu = 0;
	int restGr = 0;

	int potenciaRojo = 0;
	int potenciaBlu = 0;
	int potenciaGr = 0;

	int sumRojo = 0;
	int sumBlu = 0;
	int sumGr = 0;
	int sumatoriaRojo = 0;
	int sumatoriaBlu = 0;
	int sumatoriaGr = 0;

	int sumaTotal = 0;

	for (size_t i = 0; i < test.size(); i++)
	{
		for (size_t j = 0; j < train.size(); j++)
		{
			restRojo = (histoR.at<float>(i, 0) - histoRtrain.at<float>(j, 0));
			restBlu = (histoB.at<float>(i, 0) - histoBtrain.at<float>(j, 0));
			restGr = (histoG.at<float>(i, 0) - histoGtrain.at<float>(j, 0));
				//rest = (histoB.at<float>(i, 0) - histoG.at<float>(i, 0) - histoR.at<float>(i, 0));
			cout << "rojo" << restRojo;
			potenciaRojo = (restRojo * restRojo);
			potenciaBlu = (restBlu * restBlu);
			potenciaGr = (restGr * restGr);


		}
		sumatoriaRojo = sumatoriaRojo + potenciaRojo;
		sumatoriaBlu = sumatoriaBlu + potenciaBlu;
		sumatoriaGr = sumatoriaGr + potenciaGr;
		sumRojo = sqrt(sumatoriaRojo);
		sumGr = sqrt(sumatoriaGr);
		sumBlu = sqrt(sumatoriaBlu);
		sumaTotal = sumRojo + sumBlu + sumGr;


	}

	trainList.push_back(sumaTotal);
	int smallest_element = *min_element(trainList.begin(), trainList.end());
	cout << endl;
	cout << "Suma Total" << sumaTotal;
	cout << "resta Rojo:  " << restRojo << "  Potencias Rojo: " << potenciaRojo << "  Sumatoria Rojo:" << sumatoriaRojo << " Raiz Rojo: " << sumRojo << endl;
	cout << "resta Azul:  " << restBlu << "  Potencias Azul: " << potenciaGr << "  Sumatoria Azul:" << sumatoriaBlu << " Raiz Azul: " << sumGr << endl;
	cout << "resta Verde:  " << restGr << "  Potencias Verde: " << potenciaGr << "  Sumatoria Verde:" << sumatoriaGr << " Raiz Verde: " << sumGr << endl;
	cout << "Lista de distancias" << trainList[0];
	cout << "Minimo" << smallest_element;


	return trainList;
}

void Histograma::CalcularHistogramaHSV(vector <string> listaimagenes) {
	cout << "Metodo de HSV";
	for (size_t i = 2; i < listaimagenes.size(); i++)
	{
		Mat imagahsv = imread("C:/Users/Portal Center/Documents/Uni/Octavo/VisionCompu/cc++/Practica2/Practica2/garfield/" + listaimagenes[i], IMREAD_UNCHANGED);

		Mat hsv;
		cvtColor(imagahsv, hsv, COLOR_BGR2HSV);
		//imshow("HSV",hsv);
		for (int i = 0; i < 256; i++) {
			histoHSV[i] = 0;
		}
		int pixel = 0;
		int max = 0;
		for (int i = 0; i < hsv.rows; i++) {
			for (int j = 0; j < hsv.cols; j++) {
				pixel = hsv.at<uchar>(i, j);
				histoHSV[pixel]++;
			}
		}
		// Imprimimos el histograma
		/*for (int i = 0; i < 256; i++) {
			cout << histoHSV[i] << ";";
		}*/
		waitKey(0);
		cout << " Imagenes: " << listaimagenes[i] << " columnas: " << hsv.rows << " Filas: " << hsv.cols << endl;

	}


}

void Histograma::Distancia(vector<string>train, vector<string>test) {
	 //git
}


