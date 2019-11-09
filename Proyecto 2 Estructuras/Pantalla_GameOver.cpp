#include "Pantalla_GameOver.h"

Pantalla_GameOver::Pantalla_GameOver(bool final, int nivel, int& vidas, int vidasPerdidas, int fantasmasMuertos, int& ptsTotal, int tiempo)
{
	continuarPartida = !final;
	mensaje = NULL;
	backGround = NULL;
	for (int i = 0; i < 7; i++) {
		botones[i] = NULL;
	}


	this->finalBueno = final;
	rw = new RenderWindow(VideoMode(800, 600), "Fin de la Partida");
	rw->setFramerateLimit(15);
	this->nivel = nivel;
	this->vidas = vidas;
	this->vidasPerdidas = vidasPerdidas;
	this->fantasmasMuertos = fantasmasMuertos;
	this->ptsTotal = ptsTotal;
	this->tiempo = tiempo;

	if (finalBueno == true) {
		vistaBuena();//para el sistema de vistas es mejor tener listas para tener una cantidad ilimitada y controlable de botones textos y diferentes cosas
	}
	else {
		vistaMala();
	}



	overLoop();

}

void Pantalla_GameOver::setNivel(int nivel)
{
	this->nivel = nivel;
}

void Pantalla_GameOver::setVidas(int vidas)
{
	this->vidas = vidas;
}

void Pantalla_GameOver::setVidasPerdidas(int vidasPerdidas)
{
	this->vidasPerdidas = vidasPerdidas;
}

void Pantalla_GameOver::setFatnasmasMuertos(int fantasmasMuertos)
{
	this->fantasmasMuertos = fantasmasMuertos;
}

void Pantalla_GameOver::setPtsTotal(int ptsTotal)
{
	this->ptsTotal = ptsTotal;
}

void Pantalla_GameOver::setTiempo(int tiempo)
{
	this->tiempo = tiempo;
}



void Pantalla_GameOver::setFinalBueno(bool finalBueno)
{
	this->finalBueno = finalBueno;
}

void Pantalla_GameOver::setContinuarPartida(bool continuarPartida)
{
	this->continuarPartida = continuarPartida;
}

int Pantalla_GameOver::getNivel()
{
	return nivel;
}

int Pantalla_GameOver::getVidas()
{
	return vidas;
}

int Pantalla_GameOver::getVidasPerdidas()
{
	return vidasPerdidas;
}

int Pantalla_GameOver::getFatnasmasMuertos()
{
	return fantasmasMuertos;
}

int Pantalla_GameOver::getPtsTotal()
{
	return ptsTotal;
}

int Pantalla_GameOver::getTiempo()
{
	return tiempo;
}

bool Pantalla_GameOver::isFinalBueno()
{
	return finalBueno;
}

bool Pantalla_GameOver::getContinuarPartida()
{
	return continuarPartida;
}

void Pantalla_GameOver::overLoop()
{

	Event* evento = new Event();
	while (rw->isOpen()) {

		showEnd();

		while (rw->pollEvent(*evento)) {

			if (evento->type == Event::Closed || evento->key.code == Keyboard::Escape) {

				rw->close();

			}
			else if (evento->type == Event::MouseButtonReleased) {
				selecOption(Mouse::getPosition(*rw).x, Mouse::getPosition(*rw).y);
				cout << "Mouse X: " << Mouse::getPosition(*rw).x << "--> Mouse Y: " << Mouse::getPosition(*rw).y << endl;
			}

		}

	}

}



void Pantalla_GameOver::showEnd()
{
	rw->clear();

	mostrarVista();

	rw->display();
}

void Pantalla_GameOver::selecOption(int x, int y)
{
	for (int i = 0; i < 7; i++) {
		if (botones[i] != NULL) {

			if (botones[i]->getSprite() != NULL) {

				if (botones[i]->getAccion() == "Finalizar Partida") {
					
					//guardar datos en txts y salir al menu principal
					if (evaluarPosicionMouseBoton(x, y, botones[i]) == true) {
						cout << "Salido XD" << endl;

						//comenzar aqui a guardar los datos en el txt.....................
						guardarInformacionPartida();
						rw->close();

					}

				}
				else if(botones[i]->getAccion() == "Comprar Vida") {
					
					if (evaluarPosicionMouseBoton(x, y, botones[i]) == true) {

						cout << "Comprando Vida" << endl;

						//compramos vidas y disminuimos puntos

					}
					
				}
				else if (botones[i]->getAccion() == "Continuar Partida") {

					cout << "Pues Continuemos..." << endl;
					//reanudamos la partida y aumentamos las vidas.
					//pero no guardamos datos


					//cuando se compren vida y se le de Continuar partida la variable CONTINUAR PARTIDA SE DEBE HACER TRUE
				}
			}
		}
	}
}

bool Pantalla_GameOver::evaluarPosicionMouseBoton(int x, int y, Boton* boton)
{
	cout << "ENTRA" << endl;
	if (x <= (boton->getSprite()->getPosition().x + boton->getSprite()->getGlobalBounds().width / 2)
		&& x >= (boton->getSprite()->getPosition().x - boton->getSprite()->getGlobalBounds().width / 2)) {
		

		
		//resto 50 a la posicion del boton en Y debido a un inconveniente con el posicionamiento del mismo
		if (y <= ((boton->getSprite()->getPosition().y - 50) + boton->getSprite()->getGlobalBounds().height / 2)
			&& y >= ((boton->getSprite()->getPosition().y - 50) - boton->getSprite()->getGlobalBounds().height / 2)) {
			
			return true;

		}
		else {

			return false;

		}

	}
	else {

		return false;

	}
}


void Pantalla_GameOver::mostrarVista()
{
	for (int i = 0; i < 7; i++) {
		if (botones[i] != NULL) {

			if (botones[i]->getSprite() != NULL) {

				rw->draw(*botones[i]->getSprite());				

			}
			if (botones[i]->getText() != NULL) {

				rw->draw(*botones[i]->getText());

			}
		}
	}
}

void Pantalla_GameOver::vistaBuena()
{
	Texture* t1 = new Texture(),* t2 = new Texture();
	if (t1->loadFromFile("")) {
		backGround = new Sprite(*t1);
		backGround->setOrigin(backGround->getPosition().x + backGround->getGlobalBounds().width / 2, backGround->getPosition().y + backGround->getGlobalBounds().height / 2);
		backGround->setPosition(400,25);
	}
	if (t2->loadFromFile("")) {
		mensaje = new Sprite(*t2);
		mensaje->setOrigin(mensaje->getPosition().x + mensaje->getGlobalBounds().width / 2, mensaje->getPosition().y + mensaje->getGlobalBounds().height / 2);
		mensaje->setPosition(400, 75);
	}

	string r = "Game_Files/Textures/UI/Scenary/Rotulo1.png";
	botones[0] = new Boton("Ninguna", "Vidas: " + to_string(vidas), 400, 175, r, 400, 125, 1, 1, 1, 1);
	botones[1] = new Boton("Ninguna", "Fantasmas Muertos: " + to_string(fantasmasMuertos), 400, 225, r, 400, 175, 1, 1,  1, 1);
	botones[2] = new Boton("Ninguna", "Puntos Obtenidos: " + to_string(ptsTotal), 400, 275, r, 400, 225, 1, 1, 1, 1);
	botones[3] = new Boton("Ninguna", "Tiempo de Partida: " + to_string(tiempo) + " segundos.", 400, 325, r, 400, 275, 1, 1, 1, 1);
	if (vidasPerdidas != 0) {
		botones[4] = new Boton("Ninguna", "Muerte en Partida: Si" , 400, 375, r, 400, 325, 1, 1, 1, 1);
	}
	else {
		botones[4] = new Boton("Ninguna", "Muerte en Partida: No" , 400, 375, r, 400, 325, 1, 1, 1, 1);
	}
	
	botones[5] = new Boton("Finalizar Partida", "Volver al Menu Principal ", 400, 575, r, 400, 525, 1, 1, 1, 1);
	botones[6] = NULL;

	Color* c = new Color(255,255,255,100);

	for (int i = 0; i < 6; i++) {

		if (botones[i]->getSprite() != NULL) {
			botones[i]->getSprite()->setColor(*c);
			botones[i]->ajustarBtnTexto();
		}
		
	}

}

void Pantalla_GameOver::vistaMala()
{
	//hacer lo mismo que en vista buena y validar que si la parsona compro una vida entonces que que continuar partidad se haga verdadero

	///tambien se puede hacer un boton comprar vida, otro finalizar partida y otro continuar partida....

	//cuando el jugador se quede sin vidas y este en el menu principal se debera pasar a esta pantalla pero cambiando textos y 
	//sugiriendo que compre vidas...

}

void Pantalla_GameOver::guardarInformacionPartida()
{
	cout << "((((((((((((((((((((((((((((((((((((((((GUARDANDO VIDAS)))))))))))))))))))))))))))))))))))))))" << endl;
	guardarVidas("Game_Files/Data/Total_Vidas.txt");
	cout << "'" << endl;

	cout << "((((((((((((((((((((((((((((((((((((((((GUARDANDO VIDAS PERDIDAS)))))))))))))))))))))))))))))))))))))))" << endl;
	guardarVidasPerdidas("Game_Files/Data/Vidas_Perdidas.txt");
	cout << "'" << endl;

	cout << "((((((((((((((((((((((((((((((((((((((((GUARDANDO FANTASMAS COMIDOS)))))))))))))))))))))))))))))))))))))))" << endl;
	guardarFantasmasMuertos("Game_Files/Data/Fantasmas_Comidos.txt");
	cout << "'" << endl;

	cout << "((((((((((((((((((((((((((((((((((((((((GUARDANDO PUNTOS POR NIVEL)))))))))))))))))))))))))))))))))))))))" << endl;
	guardarPtsEnNivel("Game_Files/Data/Score/pts_" + to_string(nivel) + ".txt");
	cout << "'" << endl;

	cout << "((((((((((((((((((((((((((((((((((((((((GUARDANDO CANTIDAD DE VECES JUGAD)))))))))))))))))))))))))))))))))))))))" << endl;
	guardarCantidadVecesJugado("Game_Files/Data/Score/pts_" + to_string(nivel) + ".txt");
	cout << "'" << endl;

	cout << "((((((((((((((((((((((((((((((((((((((((GUARDANDO PUNTAJE TOTAL)))))))))))))))))))))))))))))))))))))))" << endl;
	guardarPtsTotal("Game_Files/Data/Score/ptj_Total.txt");//revisa las mayor cantidad de puntos alcanzados en los niveles ya que el jugador como minimo puede tener esa cantidad de puntos
	cout << "'" << endl;

	cout << "((((((((((((((((((((((((((((((((((((((((GUARDANDO PUNTOS SIN GASTAR)))))))))))))))))))))))))))))))))))))))" << endl;
	guardarPtsEnPosecion("Game_Files/Data/Score/ptj_Total.txt");
	cout << "'" << endl;

	cout << "((((((((((((((((((((((((((((((((((((((((GUARDANDO TIEMPO GLOBAL DE JUEGO)))))))))))))))))))))))))))))))))))))))" << endl;
	guardarTiempo("Game_Files/Data/Segundos_Juego.txt");
	cout << "'" << endl;

	cout << "((((((((((((((((((((((((((((((((((((((((GUARDANDO MEJOR TIEMPO DE JUEGO)))))))))))))))))))))))))))))))))))))))" << endl;
	guardarMejorTiempoPorNivel("Game_Files/Data/Score/pts_" + to_string(nivel) + ".txt");
	cout << "'" << endl;

	cout << "((((((((((((((((((((((((((((((((((((((((GUARDANDO PUNTOS SEGUN INMUNIDAD)))))))))))))))))))))))))))))))))))))))" << endl;
	guardarPtsPorInmunidad("Game_Files/Data/Score/ptj_Total.txt");
	cout << "'" << endl;



	cout << "NIVELLLLLL:::::::::::" << to_string(nivel) << endl;

	/////////7777777
}

void Pantalla_GameOver::guardarVidas(string ruta)
{
	ofstream f;//para escribir
	ifstream ff;//para leer
	string pal = "";
	int num = 0;
	//aguardamos las vidas
	f.open(ruta);
	f.seekp(0);
	cout << "vidas" << vidas << endl;
	if (!f.fail()) {

		f << to_string(vidas);

	}

	f.close();
	//guardamos las vidas

}

void Pantalla_GameOver::guardarVidasPerdidas(string ruta)
{
	ifstream in; ofstream out;
	string pal = "";
	int num = 0;
	in.open(ruta);
	if (!in.fail()) {

		getline(in, pal);

		stringstream x(pal);

		x >> num;

		num = num + vidasPerdidas;

		in.close();


		cout << "VIDASPERDIDASin: " << num << endl;
		cout << "VIDASPERDIDASout: " << vidasPerdidas << endl;
		out.open(ruta);
		if (!out.fail()) {

			out << num;
			out.close();
		}

	}
}

void Pantalla_GameOver::guardarFantasmasMuertos(string ruta)
{
	ifstream ff;
	ofstream f;
	string pal = "";
	int num = 0;
	//sumamos y guardamos los fantasmas muertos
	ff.open("Game_Files/Data/Fantasmas_Comidos.txt");
	if (!ff.fail()) {
		getline(ff, pal);
		stringstream x(pal);

		x >> num;

		num = fantasmasMuertos + num;
	}

	ff.close();
	f.open("Game_Files/Data/Fantasmas_Comidos.txt");
	if (!f.fail()) {
		f << num;
	}
	f.close();
	//sumamos y guardamos los fantasmas muertos

}

void Pantalla_GameOver::guardarPtsTotal(string ruta)
{
	//guardar Puntaje Total Ganado
	//ahora guardamos reccorremos los puntos del todos los txts y los sumamos, finalmente se guardan, esto para evitar que se haga trampa...(no es tan efectivo pero despues de un partida con trampas, el puntaje se correjira)
	
	ifstream ff;

	string pal = "";
	int num = 0, multiplicador = 0;//puntaje de todos los txt(niveles) ya anteriormente jugados
	string url = "";
	int n = 0;//punteje del txt abierto actualmente(este se le sumara a num)
	for (int i = 0; i < 10; i++) {
		url = "Game_Files/Data/Score/pts_" + to_string(i + 1) + ".txt";

		ff.open(url);

		if (!ff.fail()) {

			getline(ff, pal);
			getline(ff, pal);
			stringstream x(pal);
			x >> n;
			

			getline(ff, pal);
			getline(ff, pal);


			stringstream xx(pal);
			xx >> multiplicador;

			cout<< "Multiplicador: " << multiplicador << endl;
			if (multiplicador != 0) {
				
				n = n * multiplicador;
				cout << "YA MULTIPLICADO: " << n << endl;
			}
			else {
				n = n * 1;
			}
			
			num = num + n;

			ff.seekg(0);
		}
		ff.close();
	}
	//num = num + ptsTotal;
	
	ff.close();
	

	cout << "PUntaje Total: " << num << endl;
	setLine(to_string(num), ruta, 2);
	
	
	//guardar Puntaje Total Ganado

}

void Pantalla_GameOver::guardarPtsEnPosecion(string ruta)
{
	ifstream in;

	string pal = "";
	int num = 0;

	in.open(ruta);

	if (!in.fail()) {
		getline(in, pal);
		getline(in, pal);
		getline(in, pal);
		getline(in, pal);
		in.seekg(0);

		stringstream x(pal);

		x >> num;

		num = num + ptsTotal;

		setLine(to_string(num), ruta, 4);

		in.close();

	}
	else {
		in.close();//duda..........................................
	}
	

}

void Pantalla_GameOver::guardarPtsPorInmunidad(string ruta)
{
	ifstream in;

	string pal = "";
	int num = 0;
	int posicion = 0;

	in.open(ruta);

	if (!in.fail()) {

		if (vidasPerdidas != 0) {
			posicion = 6;
		}
		else {
			posicion = 8;
		}
		for (int i = 0; i < posicion; i++) {
			getline(in, pal);
		}
		//stringstream funciona de maera que si no encuentra ningun numeroen el texto su valor por defecto es 0
		//stoi daria un error si este numero se suma.....
		stringstream x(pal);
		x >> num;
		num = num + ptsTotal;
		in.seekg(0);
		in.close();
		setLine(to_string(num), ruta, posicion);

	}
	
}

void Pantalla_GameOver::guardarPtsEnNivel(string ruta)
{
	
	ifstream in;
	string pal = "";
	

	in.open(ruta);

	if (!in.fail()) {

		getline(in,pal);
		getline(in, pal);

		if (stoi(pal) < ptsTotal) {
			//int num = 0;
			in.close();

			setLine(to_string(ptsTotal), ruta, 2);

		}

	}
	in.close();
}

void Pantalla_GameOver::guardarTiempo(string ruta)
{
	ifstream in; ofstream out;
	string pal = "";
	int num = 0;

	in.open(ruta);
	

	if (!in.fail()) {

		getline(in, pal);
		num = tiempo + stoi(pal);

		in.close();
		out.open(ruta);

		if (!out.fail()) {

			out << num;

			out.close();

		}

	}

	
}

void Pantalla_GameOver::guardarMejorTiempoPorNivel(string ruta)
{

	ifstream in;
	string pal = "";
	int num = 0;

	in.open(ruta);

	if (!in.fail()) {

		for (int i = 0; i < 6; i++) {

			getline(in, pal);

		}

		in.close();
		
		stringstream x(pal);
		x >> num;
		cout << "num: " << num << endl;
		if (tiempo < num) {
			
			setLine(to_string(tiempo), ruta, 6);

		}

	}

	
	

}

void Pantalla_GameOver::guardarCantidadVecesJugado(string ruta)
{

	ifstream in;
	string p = "";
	int num = 0;
	in.open(ruta);

	if (!in.fail()) {
		
		
		getline(in, p);
		getline(in, p);
		getline(in, p);
		getline(in, p);
		
		stringstream x(p);

		x >> num;
		
		num++;//si se hace: num = stoi(p) + 1; --> esto no sirve...
		
		in.close();

		setLine(to_string(num), ruta, 4);
			
		
	}

	
	
}




void Pantalla_GameOver::setLine(string line, string ruta, int posicion)
{
	ifstream ff;
	ofstream f;

	//f.open(ruta);
	ff.open(ruta);

	if (!ff.fail()) {

		string* vec;//vector dinamico con las lineas del txt(use esto ya que no se como editar explicitamente una linea del txt
		int cont = 0, tpts = 0;//para el tamaño del vector y otro para el total de puntos
		string p;

		cout << "LINEA INGRESADA::::::::::::::::::::::::: " << line << endl;
		while (!ff.eof()) {

			getline(ff, p);
			cont++;
			cout << "LINEA " << cont << ": " << p << endl;
		}
		
		ff.seekg(0);

		vec = new string[cont];
		for (int i = 0; i < cont; i++) {

			getline(ff, vec[i]);
			cout << "VECTOR [" << i << "] =-->  ";
			cout << vec[i] << endl;;

		}
		
		//para casting de string a int, entre otras: se usa: stoi(string x);

		vec[posicion - 1] = line;//se suplanta el valor anterior por el valor dado
		//se guardardan los datos

		ff.close();
		f.open(ruta);

		if (!f.fail()) {

			for (int i = 0; i < cont; i++) {
				
				f << vec[i];
				cout << "METIDA  " << i << endl;

				if (i < cont - 1) {
					f << endl;
				}
			}

		}
		f.close();

	}
}
