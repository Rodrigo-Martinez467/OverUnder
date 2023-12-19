#include "vex.h"

using namespace std;

namespace ui {
	paintable::paintable( int x, int y, class color color ) {
		this->setTransform(x, y);
		this->setColor(color);
	}

	paintable::~paintable() {}

	void paintable::setTransform( int x, int y ) {
		this->x = x;
		this->y = y;
	}

	void paintable::move( int x, int y ) {
		this->setTransform(this->x + x, this->y + y);
	}

	void paintable::onScreenPressed( int x, int y ) {
		this->paint();
	}

	void paintable::setColor( class color color ) {
		this->color = color;
	}

	void paintable::paint() {}
}