#include "Tete.h"
#include <QGraphicsPixmapItem>

Tete::Tete() : QGraphicsPixmapItem() {

	this->setPixmap(QPixmap("tete.png"));
	
	this->m_x = 300;
	this->m_y = 370;
	this->speed = 10;

	this->setPos(m_x, m_y);
}

int Tete::getX() {//méthode qui renvoi l'attribut x
	return m_x;
}


void Tete::setX(int valeur){//méthode ecrivant dans l'attribut x
	m_x = valeur;
}

int Tete::getY(){
	return m_y;
}

void Tete::moveL() {
	m_x -= speed;
	this->setPos(m_x, m_y);
}

void Tete::moveR() {
	m_x += speed;
	this->setPos(m_x, m_y);
}