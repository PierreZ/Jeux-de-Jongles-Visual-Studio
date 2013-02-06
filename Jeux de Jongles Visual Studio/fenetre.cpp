#include "Fenetre.h"

Fenetre::Fenetre(qreal width, qreal height, QObject * parent ) : QGraphicsScene(parent) {
    this->setSceneRect(0, 0, width, height);
	this->hauteur = height;
	this->largeur = width;
    this->setBackgroundBrush(QImage("fond.png"));

	tete = new Tete();
	ballon = new Ballon(width, height);
	nui=new kinect();
	this->addItem(tete);
	this->addItem(ballon);

	this->anim_ball = false;

	QPen pen;
	pen.setColor(Qt::green);
	pen.setWidth(5);
	this->qgei = new QGraphicsEllipseItem(50,50,30,30, 0, this);
	qgei->setPen(pen);
	qgei->setVisible(false);

	timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    timer->start(30);
}

void Fenetre::keyPressEvent(QKeyEvent* keyEvent) {
	switch(keyEvent->key())
	{
	case Qt::Key_Left:
		if (tete->getX() > 0 ) tete->moveL();
		break;
		
		case Qt::Key_Right:
			if (tete->getX() < (this->width() - tete->boundingRect().width() )) tete->moveR();
		break;
			
		case Qt::Key_P:
			
		break;

		case Qt::Key_R:
			ballon->speed_reinit(0,20);
		break;

		case Qt::Key_Space:	
			anim_ball = !anim_ball;
		break;

		default:
		break;
	}  
}

void Fenetre::update(void) {
	x=nui->return_tete();
	tete->movekinect(x);
	if (!anim_ball) return;
	ballon->move();
	if (ballon->collidesWithItem(tete)) {
		qgei->setVisible(true);
		ballon->inversion();
		ballon->move();


	} else
		qgei->setVisible(false);
}