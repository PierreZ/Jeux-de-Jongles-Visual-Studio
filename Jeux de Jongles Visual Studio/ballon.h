#ifndef BALLON_H
#define BALLON_H

#include <vector>
#include <QLabel>
#include <QGraphicsPixmapItem>
#include <qDebug>
class Ballon:public QGraphicsPixmapItem //double h�ritages
{
public:
    Ballon(int w, int h); //constructeur

	int getY(){return m_y;}
	void speed_reinit(int x,int y);
	int move();
	void inversion();
	void move_collision();
private:
	int a;
	int scene_width;
	int scene_height;
	int m_x;
	int m_y;
	int v_x;
	int v_y;
	
};

#endif // BALLON_H
