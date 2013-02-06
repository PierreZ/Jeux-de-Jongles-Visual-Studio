#ifndef DEF_Tete
#define DEF_Tete

#include <QtGui>

#include <QGraphicsPixmapItem>

class Tete : public QGraphicsPixmapItem // On hérite de QLabel
{
public:

	Tete();
	int getX();
	void setX(int valeur);
	int getY();
	void setSpeed(int s){speed+=s;}
	void moveL();
	void moveR();
	void movekinect(float x);


private:
	int m_x;
	int m_y;
	int speed;
};

#endif
