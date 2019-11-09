#include "Controller.h"

Controller::Controller()
{
	pantallaJugador = NULL;
	pantallaLvl = NULL;
	puntajeMaximo = 0;


	rx = 400; ry = 600; fps = 60;
	rw = new RenderWindow(VideoMode(rx, ry), "Menu Principal");
	rw->setFramerateLimit(fps);


	botones[0] = new Boton("Iniciar", "Iniciar", 200, 200, "Game_Files/Textures/UI/Buttons/blue_button00.png", 200, 200, 1.2, 1);
	botones[1] = new Boton("Jugador", "Jugador", 200, 300, "Game_Files/Textures/UI/Buttons/grey_button00.png", 200, 300, 1.2, 1);
	botones[2] = new Boton("Configuracion", "Configuracion", 200, 400, "Game_Files/Textures/UI/Buttons/red_button00.png", 200, 400, 1.2, 1);
	botones[3] = new Boton("Salir", "Salir", 200, 500, "Game_Files/Textures/UI/Buttons/yellow_button00.png", 200, 500, 1.2, 1);

	controllerLoop();
}

void Controller::setRX(int rx)
{
}

void Controller::setRY(int ry)
{
}

void Controller::setfps(int fps)
{
}

void Controller::setPuntajeManximo(int puntajeMaximo)
{
	ofstream file;
	file.open("Puntaje.txt");
	while (!file.eof()) {
		//hacer aqui demas
	}

}

void Controller::setRenderWindow(int x, int y)
{
}

void Controller::selector(int posX,int posY)//selector de ventana
{
	if (posX > botones[0]->getSprite()->getPosition().x - botones[0]->getAncho() / 2 && posX < botones[0]->getSprite()->getPosition().x + botones[0]->getAncho() / 2) {
		for (int i = 0; i < 4; i++) {
			if (posY > botones[i]->getSprite()->getPosition().y - botones[i]->getAlto() / 2 && posY < botones[i]->getSprite()->getPosition().y + botones[i]->getAlto() / 2) {
				if (botones[i]->getAccion() == "Iniciar") {
					verInicio();
					cout << "Inicio de Juego" << endl;
				}
				else if(botones[i]->getAccion() == "Jugador"){
					verPantallaJugador();
					cout << "Viendo datos Jugador" << endl;
				}
				else if (botones[i]->getAccion() == "Configuracion") {
					verConfiguracion();
					cout << "Viendo Configuracion" << endl;
				}
				else if (botones[i]->getAccion() == "Salir") {
					rw->close();
				}
			}
		}
	}
}

void Controller::verInicio()
{
	ifstream f;
	f.open("Game_Files/Data/Jugador.txt");
	string p = "-";
	getline(f, p);
	if (p != "-") {
		if (pantallaLvl != NULL) {
			pantallaLvl = NULL;
		}
		pantallaLvl = new Pantalla_Lvl();
	}
	else {

	}
	f.close();
}

void Controller::verPantallaJugador()
{

	if (pantallaJugador != NULL) {

		pantallaJugador = NULL;

	}
	pantallaJugador = new Pantalla_Jugador();

}

void Controller::verConfiguracion()
{
}

void Controller::verSelecNiveles()
{
}

void Controller::controllerLoop()
{
	
	Event* event = new Event();
	while (rw->isOpen()) {

		showItems();

		while (rw->pollEvent(*event)) {
			if (event->type == Event::Closed) {
				if (pantallaLvl != NULL) {
					pantallaLvl->getRW()->close();
				}
				rw->close();
			}else if (event->type == Event::MouseButtonReleased) {
				selector(Mouse::getPosition(*rw).x, Mouse::getPosition(*rw).y);
			}
		}
		
	}
}

void Controller::showItems()
{
	rw->clear(Color::Magenta);
	for (int i = 0; i < 4; i++) {
		rw->draw(*botones[i]->getSprite());
		rw->draw(*botones[i]->getText());
	}

	rw->display();
}

