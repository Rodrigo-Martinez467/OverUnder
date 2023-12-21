#include "vex.h"

namespace ui {

Paintable::Paintable( int x, int y, class color color ) {
	this->setTransform(x, y);
	this->setColor(color);
}

Paintable::~Paintable() {}

void Paintable::setTransform( int x, int y ) {
	this->x = x;
	this->y = y;
}

void Paintable::move( int x, int y ) {
	this->setTransform(this->x + x, this->y + y);
}

void Paintable::onScreenPressed( int x, int y ) {
	this->paint();
}

void Paintable::setColor( class color color ) {
	this->color = color;
}

void Paintable::paint() {}

}