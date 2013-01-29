#include "Ballon.h"


#include <QPropertyAnimation>

Ballon::Ballon(int w, int h) : QGraphicsPixmapItem() {
    this->setPixmap(QPixmap("ballon.png"));
	this->m_x = 300;
	this->m_y = 0;
	this->v_x = 10;
	this->v_y = 20;
	this->setPos(m_x, m_y);

	scene_width = w;
	scene_height = h;
}

void Ballon::speed_reinit(int x,int y) {
	this->v_x = x;
	this->v_y = y;
}

void Ballon::move() {
	m_x += v_x;
	m_y += v_y;

	if ((m_x < 0) || ((m_x + this->boundingRect().width()) > scene_width)) v_x = -v_x;
	if ((m_y < 0) || ((m_y + this->boundingRect().height()) > scene_height)) v_y = -v_y;

	this->setPos(m_x, m_y);
}
