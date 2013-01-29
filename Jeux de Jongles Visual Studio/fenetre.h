#ifndef DEF_Fenetre
#define DEF_Fenetre

#include <QApplication>
#include <QWidget>
#include <QtGui>

#include "tete.h"
#include "ballon.h"


class Fenetre : public QGraphicsScene // On hérite de QWidget
{

	Q_OBJECT

public:
	Fenetre(qreal width, qreal height, QObject * parent = 0 ); //constructeur
	void keyPressEvent(QKeyEvent* keyEvent);


public slots:
		void update(void);

private:
	int hauteur;
	int largeur;
	QTimer *timer;
	Tete * tete;
	Ballon * ballon;
	bool anim_ball;
	QGraphicsEllipseItem * qgei;
};

#endif
