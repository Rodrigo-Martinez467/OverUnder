#include "vex.h"

namespace ui {

Canvas::Canvas() {}
Canvas::~Canvas() {}

void Canvas::setElement( string key, Paintable element ) {
	this->elements[key] = &element;
}

bool Canvas::has( string key ) {
	return this->elements.find(key) != this->elements.end();
}

void Canvas::clear() {
	this->elements.clear();
}

void Canvas::onScreenPressed( int x, int y ) {
	for (auto const& entry : this->elements) {
		Paintable* element = entry.second;
		element->onScreenPressed( x, y );
	}
}

void Canvas::paint() {
	for (auto const& entry : this->elements) {
		Paintable* element = entry.second;
		element->paint();
	}
}

map<string, Paintable*> Canvas::getMap() {
	return this->elements;
}

Paintable* Canvas::get(string key) {
	if (!this->has(key)) return nullptr;
	return this->elements.at(key);
}

}