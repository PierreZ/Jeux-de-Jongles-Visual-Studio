#include "Fenetre.h"

Fenetre::Fenetre(qreal width, qreal height, QObject * parent ) : QGraphicsScene(parent) {
    this->setSceneRect(0, 0, width, height);
	this->hauteur = height;
	this->largeur = width;
    this->setBackgroundBrush(QImage("fond.png"));
	
	score=0;
	score1=QString::number(score);
	QFont Font("Times", 60, QFont::Bold);
	QFont Font1("Times",20);
	


	 compteur=new QGraphicsTextItem(score1, NULL,this);  
	compteur->setVisible(true);
	compteur->setPos(350,0);
	compteur->setFont(Font);
	 compteur->setDefaultTextColor(Qt::white);


	label=new QGraphicsTextItem("high-score", NULL,this);
		label->setVisible(true);
	label->setPos(650,0);
	label->setFont(Font1);
	 label->setDefaultTextColor(Qt::white);
	 	
	 highestscore=0;
	 hiscore=new QGraphicsTextItem(QString::number(highestscore), NULL,this);
		hiscore->setVisible(true);
	hiscore->setPos(730,40);
	hiscore->setFont(Font1);
	 hiscore->setDefaultTextColor(Qt::white);



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
	a=ballon->move();
	if (ballon->collidesWithItem(tete)) {
		score++;
	score1=QString::number(score);
		compteur->setPlainText(score1);

		//qgei->setVisible(true);
		//ballon->inversion();
		ballon->move_collision();


	} else{
		//qgei->setVisible(false);
		}
if (a==1)
	this->restart_compteur();

}

void Fenetre::restart_compteur(){
 if (score>highestscore){
	 hiscore->setPlainText(score1);
	 highestscore=score;
	}
	score=0;
	score1=QString::number(score);
		compteur->setPlainText(score1);
}