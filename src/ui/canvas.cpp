#include "vex.h"

namespace ui {
	canvas::canvas() {}
	canvas::~canvas() {}

	void canvas::setElement( string key, paintable element ) {
		this->elements[key] = element;
	}

	bool canvas::has( string key ) {
		return this->elements.find(key) != this->elements.end();
	}

	void canvas::clear() {
		this->elements.clear();
	}

	void canvas::onScreenPressed( int x, int y ) {
		for (auto const& entry : this->elements) {
			paintable element = entry.second;
			element.onScreenPressed( x, y );
		}
	}

	void canvas::paint() {
		for (auto const& entry : this->elements) {
			paintable element = entry.second;
			element.paint();
		}
	}

	map<string, paintable> canvas::getMap() {
		return this->elements;
	}

	paintable canvas::get( string key ) {
		return this->elements.at(key);
	}
}