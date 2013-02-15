#include "Ballon.h"


#include <QPropertyAnimation>

Ballon::Ballon(int w, int h) : QGraphicsPixmapItem() {
    this->setPixmap(QPixmap("ballon.png"));
	this->m_x = 300;
	this->m_y = 0;
	this->v_x = 10;
	this->v_y = 20;
	this->setPos(m_x, m_y);
	QGraphicsPixmapItem::MaskShape;
	scene_width = w;
	scene_height = h;
}

void Ballon::speed_reinit(int x,int y) {
	this->v_x = x;
	this->v_y = y;
}

int Ballon::move() {
	m_x += v_x;
	m_y += v_y;
	a=0;
	if ((m_x < 0) || ((m_x + this->boundingRect().width()) > scene_width)) v_x = -v_x;
	if ((m_y < 0) || ((m_y + this->boundingRect().height()) > scene_height)) v_y = -v_y;
	if (m_y>505)//Fin du jeu
		{a=1;
	this->speed_reinit(10,20);
	this->m_x = 300;
	this->m_y = 0;
		}


	this->setPos(m_x, m_y);
return a;
}

void Ballon::inversion() {
	
	v_y = -v_y;
}

void Ballon::move_collision(){

if (m_y<=300){
	v_y = -v_y;
}
else{
	v_x = -v_x;
	
}
}