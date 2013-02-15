#ifndef DEF_Fenetre
#define DEF_Fenetre
#include <Qt>
#include <QApplication>
#include <QWidget>
#include <QtGui>
#include <QGraphicsTextItem>
#include <QString>
#include <QFont>
#include <QColor>
#include "tete.h"
#include "ballon.h"
#include "kinect.h"

class Fenetre : public QGraphicsScene // On hérite de QWidget
{

	Q_OBJECT

public:
	Fenetre(qreal width, qreal height, QObject * parent = 0 ); //constructeur
	void keyPressEvent(QKeyEvent* keyEvent);
	void restart_compteur();

public slots:
		void update(void);

private:
	int a;
	QString score1;
	int highestscore;
	int score;
	float x;
	int hauteur;
	int largeur;
	QTimer *timer;
	Tete * tete;
	Ballon * ballon;
	kinect * nui;
	bool anim_ball;
	QGraphicsEllipseItem * qgei;
	QGraphicsTextItem * compteur;
	QGraphicsTextItem * label;
	QGraphicsTextItem * hiscore;
	QColor *white;

};

#endif
