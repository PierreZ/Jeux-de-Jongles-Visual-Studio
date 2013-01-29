#include <QApplication>
#include <Tete.h>
#include <ballon.h>
#include <QtGui>
#include <fenetre.h>
#include <QPropertyAnimation>



int main(int argc, char *argv[])
{
	QApplication app(argc, argv);// démarrage de l'application Qt


	Fenetre fond(800,600);//création de la scène, objet de type Graphicscene
	



	QGraphicsView view(&fond); // création de la visualisation de la scène
	view.show(); //affichage de la visualisation de la scène


	return app.exec();


}
