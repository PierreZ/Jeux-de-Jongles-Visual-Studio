#include <QApplication>
#include <Tete.h>
#include <ballon.h>
#include <QtGui>
#include <fenetre.h>
#include <QPropertyAnimation>



int main(int argc, char *argv[])
{
	QApplication app(argc, argv);// d�marrage de l'application Qt


	Fenetre fond(800,600);//cr�ation de la sc�ne, objet de type Graphicscene
	



	QGraphicsView view(&fond); // cr�ation de la visualisation de la sc�ne
	view.show(); //affichage de la visualisation de la sc�ne


	return app.exec();


}
