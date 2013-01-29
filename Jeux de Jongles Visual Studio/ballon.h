#ifndef BALLON_H
#define BALLON_H

#include <vector>
#include <QLabel>
#include <QGraphicsPixmapItem>

class Ballon:public QGraphicsPixmapItem //double héritages
{
public:
    Ballon(int w, int h); //constructeur

	int getY(){return m_y;}
	void speed_reinit(int x,int y);
	void move();

private:
	int scene_width;
	int scene_height;
	int m_x;
	int m_y;
	int v_x;
	int v_y;
	
};

#endif // BALLON_H
