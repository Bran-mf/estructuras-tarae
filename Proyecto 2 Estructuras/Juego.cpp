#include "Juego.h"
Juego::Juego(Mapa* mapa, int lvl, string tema)
{

	pantalla_gameOver = NULL;

	//datos
	nivel = lvl;
	vidas = obtenerVidas();
	fantasmasMuertos = 0;
	ptsTotal = 0;
	tiempo = 0;

	pacDots = 0;


	tiempo_de_poder = 0;
	//datos



	//referente a personajes
	pacman = NULL; 
	for (int i = 0; i < 4; i++) {
		fantasmas[i] = NULL;
	}
	//referente a personajes



	//referente al escenario

	Texture texture;
	texture.loadFromFile("Game_Files/Textures/Backgrounds/Lvl" + to_string(lvl) + "/" + tema + ".jpg");
	background = new Sprite(texture);
	background->setPosition(0, 0);
	////////rectangulo para resaltar mapa
	backBanckground = new Sprite();
	Texture texture1;
	if (texture1.loadFromFile("Game_Files/Textures/UI/Buttons/grey_panel.png")) {
		backBanckground->setTexture(texture1);
		backBanckground->setPosition(0, 0);
		backBanckground->setScale(10.24, 7.2);
		Color* color = new Color(300, 300, 300, 120);
		backBanckground->setColor(*color);
	}
	////////rectangulo para resaltar mapa
	nombre = "NIVEL" + to_string(lvl) + ": " + tema;
	rx = 1024;
	ry = 720;
	fps = 60;
	rw = new RenderWindow(VideoMode(rx, ry), nombre);
	rw->setFramerateLimit(60);
	this->mapa = mapa;
	for (int i = 0; i < 21; i++) {
		for (int j = 0; j < 19; j++) {
			letras[i][j] = mapa->getLetras(i, j);
		}
	}
	cargarMapaVisual();
	//referente al escenario





	cout << "Pacdots Totales Restantes: " << pacDots << endl;
	cout << "Pts Optenidos: " << ptsTotal << endl;
	
	gameLoop();

	cout << "**************************************" << endl;
	cout << "Pacdots Totales Restantes: " << pacDots << endl;
	cout << "Pts Optenidos: " << ptsTotal << endl;
	//borrar estos cout<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
}



void Juego::setNivel(int nivel)
{
	this->nivel = nivel;
}

void Juego::setNombre(string nombre)
{
	this->nombre = nombre;
	rw->setTitle(nombre);
}

void Juego::setRX(int rx)
{
	this->rx = rx; 
	this->rw = new RenderWindow(VideoMode(rx, ry), nombre);
}

void Juego::setRY(int ry)
{
	this->ry = ry;
	this->rw = new RenderWindow(VideoMode(rx, ry), nombre);
}

void Juego::setRW(int x, int y)
{
	this->rw = new RenderWindow(VideoMode(rx, ry), nombre);
}

void Juego::setFps(int fps)
{
	this->fps = fps;
	this->rw->setFramerateLimit(fps);
}

int Juego::getNivel()
{
	return nivel;
}

string Juego::getNombre()
{
	return nombre;
}

int Juego::getRX()
{
	return rx;
}

int Juego::getRY()
{
	return ry;
}

RenderWindow *Juego::getRW()
{
	return rw;
}

int Juego::getFps()
{
	return fps;
}

int Juego::getPtsTotal()
{
	return ptsTotal;
}

int Juego::getPacdots()
{
	return pacDots;
}


void Juego::gameLoop()
{
	Event* evento = new Event();
	int mitadPacDots = pacDots / 2;
	int frames = 0;
	while (rw->isOpen()) {

		if (frames == 60) {
			frames = 0;
			tiempo++;
			if (pacman->getComer() == true) {
				
				tiempo_de_poder++;//el problemita aqui es que el tiempo no se reinicia si se come otro power pellet
				//sino que continua solamente
				//ademas como esta con base a la cantidad de frames entonces puede durar 9.5 segundos o similar

			}
		}

		while (rw->pollEvent(*evento)) {
			if (evento->type == Event::KeyPressed) {
				pacman->guardarTecla(evento);
			}
			else if (evento->type == Event::Closed) {
				rw->close();
				cout << "Su Tiempo Fue de: " << tiempo << "  Adios..." << endl;
			}
			//aquqi eventos para gameplay
		}

		/*cout << "POSITION X: " << pacman->getSprite()->getPosition().x << " POSITION Y: " << pacman->getSprite()->getPosition().y << endl;
		cout << "ORIGEN X: " << pacman->getSprite()->getOrigin().x << " ORIGIN Y: " << pacman->getSprite()->getOrigin().y << endl;*/
		//meter esto en asuntos pacman XD

		pacman->verFutColision(scenario, ptsTotal, pacDots, fantasmasMuertos, vidas, vidasPerdidas, fantasmas);
		pacman->moverPersonaje(scenario, ptsTotal, pacDots, fantasmasMuertos, vidas, vidasPerdidas, fantasmas);
		verificarTiempo_de_comida();

		//meter esto en asuntos pacman XD
		verificarPts(mitadPacDots);
		drawer();
		frames++;
	}

}

void Juego::drawer()
{
	rw->clear();
	rw->draw(*background);
	rw->draw(*backBanckground);
	mostrarScenarioAutomatico();
	mostrarFantasmas();
	mostrarPacman();
	

	rw->display();
}

void Juego::verificarTiempo_de_comida()
{

	if (pacman->getComer() == true) {

		if (tiempo_de_poder > 10) {

			//ya que el color de los fantasmas se cambiaria desde la clase personaje en el metodo de 
			//verificar posicion entonces aqui solo se vuelven a poner normales y se anula el poder de pacman
			pacman->setComer(false);
			tiempo_de_poder = 0;
			Texture* t = new Texture();
			if (t->loadFromFile("Game_Files/Textures/Personajes/Pacman/PacMan_Ini.png")) {
				pacman->getSprite()->setTexture(*t);
			}
			
			Color* c = new Color(255,255,255,255);
			for (int i = 0; i < 4; i++) {
				fantasmas[i]->getSprite()->setColor(*c);
			}
			c = NULL;

			//HACER COLOR DE LOS FANTASMAS NORMALES COMO ANTES
			
		}
		else {
			cout << "Tiempo: " << tiempo_de_poder << endl;
		}

	}

}

void Juego::verificarPts(int mitadPacDots)
{

	if (mitadPacDots == ptsTotal / 10) {

		//aumentar la velocidad de los fantasmas
		cout << "Mitad Putos" << endl;

	}
	if (pacDots == 0) {
		
		cout << "Todos los pacdots comidos" << endl;
		gamePassed();
		rw->close();
		//se muestran cuantas vidas quedaron, cuantos puntos hizo, cual es el puntaje total, cauntos fantasmas murieron,
		//tiempo que duro la partida y si murio  no en la partida

	}
	else if (vidas == 0) {
		cout << "Sin Vidas" << endl;
		if (gameOver() == false) {
			rw->close();
		}
		else {
			vidas = obtenerVidas();
			pacman->setVidas(vidas);
		}
		
		//verificar el puntaje global total para asi poder ver si se pueden comprar algunos juegos

	}

}

void Juego::terminarJuego()//pequeña incongruensa .....
{
	//si vidas = a 0 y faltan pacdots entocnes game over
	//sino si vidas != 0 y pacdots = 0 entonces pantalla pasada y mostrar datos de partida.
}

bool Juego::gameOver()
{
	pantalla_gameOver = new Pantalla_GameOver(false, nivel, vidas, vidasPerdidas, fantasmasMuertos, ptsTotal, tiempo);
	//llamar a la pantalla de game over para asi poder decidir si comprar mas vidas o abandonar la partida.
	//cuando se cierre la ventana se pide una variable que muestra si decide cerrar por completo la partida o si se continua
	//una variable booleana
	return pantalla_gameOver->getContinuarPartida();//aqui cambiar la vara dependiendode lo que arroje la clase pantalla_Game_Over

}

void Juego::gamePassed()
{

	pantalla_gameOver = new Pantalla_GameOver(true, nivel, vidas, vidasPerdidas, fantasmasMuertos, ptsTotal, tiempo);//true para mostr
	//mostrar una ventana para mostrar puntos e ir a la pantalla de lvls

}

void Juego::cargarMapaVisual()
{

	for (int y = 0; y < 21; y++) {

		for (int x = 0; x < 19; x++) {

			scenario[y][x] = elegirRutaTextura(letras[y][x],x,y);

		}

	}

}

Boton* Juego::elegirRutaTextura(char letra, int x, int y)
{
	if (letra == 'x' || letra == 'X') {//paredes

		return elegirTextura("","Game_Files/Textures/Gameplay/Blue_Panel1.png", x, y, 0.42f, 0.34f, 0, 0);

	}else if (letra == '1' || letra == '#' || letra == '$' || letra == '0') {//puntos comestibles
		if (letra == '0' || letra == '$') {
			
			pacDots++;
			return elegirTextura("Empoderante_Comer", "Game_Files/Textures/Gameplay/yellow_circle.png", x, y, 0.6f, 0.6f, -10, -10);

		}
		else {
			
			pacDots++;
			return elegirTextura("Comestible", "Game_Files/Textures/Gameplay/yellow_circle.png", x, y, 0.2f, 0.2f, -10, -10);

		}
		
	}
	else if (letra == 'p') {

		//agregar aqui el nombre del jugador
		//cambiar la velocidad para la defensa
		pacman = new Personaje(vidas, 6, "Mr. Pacman", (800 / 19) * (x), (720 / 21) * (y), "Game_Files/Textures/Personajes/Pacman/PacMan_Ini.png", 0.05f, 0.05f, false);
		//si la velocidad es mayor o igual a 7 entonces no pasa por lo slaberintos......
		return NULL;

	}
	else if (letra == 'f') {

		string r = "", n = "";
		int v = 0;
		for (int i = 0; i < 4; i++) {
			if (i == 0) {
				n = "Blinky";
				v = 3;
				r = "Game_Files/Textures/Personajes/Fantasmas/Blinky.png";
			}
			else if(i == 1){
				v = 2;
				n = "Pinky";
				r = "Game_Files/Textures/Personajes/Fantasmas/Pinky.png";
			}
			else if (i == 2) {
				v = 2;
				n = "Inky";
				r = "Game_Files/Textures/Personajes/Fantasmas/Inky.png";
			}
			else if (i == 3) {
				v = 2;
				n = "Clyde";
				r = "Game_Files/Textures/Personajes/Fantasmas/Clyde.png";
			}
			fantasmas[i] = new Personaje(0, v, n, (800 / 19) * x, (720 / 21) * y, r, 0.06, 0.06, true);
		}
		return NULL;
	}
	else {

		return NULL;

	}

}

Boton* Juego::elegirTextura(string accion, string ruta, int x, int y, float sclX, float sclY, float orX, float orY)
{

	Boton* btn = new Boton(accion, (800 / 19) * (x), (720 / 21) * (y), ruta, sclX, sclY, orX, orY);
	return btn;

}

void Juego::mostrarScenarioAutomatico()
{
	for (int i = 0; i < 19; i++) {

		for (int j = 0; j < 21; j++) {

			if (scenario[j][i] != NULL) {

				rw->draw(*scenario[j][i]->getSprite());

			}

		}

	}
}


void Juego::mostrarPacman() {

	if (pacman != NULL) {

		rw->draw(*pacman->getSprite());

	}

}

void Juego::mostrarFantasmas()
{

	for (int i = 0; i < 4; i++) {

		if (fantasmas[i] != NULL) {

			if (fantasmas[i]->getSprite() != NULL) {

				rw->draw(*fantasmas[i]->getSprite());

			}

		}

	}

}

int Juego::obtenerVidas()
{
	int num = -1;
	string n = "";
	ifstream f;
	f.open("Game_Files/Data/Total_Vidas.txt");
	if (!f.fail()) {
		getline(f, n);
		stringstream x(n);
		x >> num;
	}
	return num;
}