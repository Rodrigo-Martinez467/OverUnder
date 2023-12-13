#include "vex.h"

namespace ui {
	screenButton::screenButton( int x, int y, int size, class color color, void action(), text buttonText ) : paintable(x, y, size, color), buttonText(text()) {
		this->action = action;
		this->buttonText = buttonText;
		this->repositionText();

		this->paint();
	}

	screenButton::~screenButton() {}

	bool screenButton::isPressed() {
		return this->pressed;
	}

	void screenButton::onScreenPressed( int x, int y ) {
		this->getPressed(x, y);
		if (this->isPressed())
			this->action();
		
		this->paint();
	}

	void screenButton::paint() {
		Brain.Screen.setPenColor(white);
		Brain.Screen.setFillColor(this->color);
		Brain.Screen.drawRectangle(this->x, this->y, this->size, this->size);

		this->buttonText.paint();
	}

	void screenButton::repositionText() {
		const int x = this->buttonText.x;
		const int y = this->buttonText.y;

		this->buttonText.setTransform(this->x, this->y);
		this->buttonText.move(x + 10, y + 10);
	}

	bool screenButton::getPressed( int tx, int ty ) {
		return ((tx >= this->x && tx <= this->x + this->size)
			&& (ty >= this->y && ty <= this->y + this->size));
	}
}