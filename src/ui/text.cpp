#include "vex.h"

using namespace vex;

namespace ui {
	text::text( string content, int x, int y, fontType font, vex::color color, vex::color textColor ) : paintable( x, y, color ) {
		this->setText(content);
		this->setFont(font);
		this->textColor = textColor;

		this->paint();
	}

	text::~text() {}

	void text::setText(string string) {
		this->content = string;
	}

	void text::setFont(fontType font) {
		this->font = font;
	}

	void text::paint() {
		if (this->content == "") return;

		Brain.Screen.setPenColor(this->textColor);
		Brain.Screen.setFillColor(this->color);
		Brain.Screen.setFont(this->font);
		Brain.Screen.printAt(this->x, this->y, this->content.c_str());
	}
}