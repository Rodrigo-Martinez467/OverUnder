#include "vex.h"

namespace ui {

ScreenButton::ScreenButton( int x, int y, int width, int height, class color color, void action(), Text buttonText ) : Paintable(x, y, color), buttonText(Text()) {
	this->action = action;
	this->buttonText = buttonText;
	this->repositionText();
}

ScreenButton::~ScreenButton() {}

bool ScreenButton::isPressed() {
	return this->pressed;
}

void ScreenButton::onScreenPressed( int x, int y ) {
	this->getPressed(x, y);
	if (this->isPressed())
		this->action();
	
	this->paint();
}

void ScreenButton::paint() {
	Brain.Screen.setPenColor(white);
	Brain.Screen.setFillColor(this->color);
	Brain.Screen.drawRectangle(this->x, this->y, this->width, this->height);

	this->buttonText.paint();
}

void ScreenButton::repositionText() {
	const int x = this->buttonText.x;
	const int y = this->buttonText.y;

	this->buttonText.setTransform(this->x, this->y);
	this->buttonText.move(x + 10, y + 10);
}

bool ScreenButton::getPressed( int tx, int ty ) {
	return ((tx >= this->x && tx <= this->x + this->width)
		&& (ty >= this->y && ty <= this->y + this->height));
}

}