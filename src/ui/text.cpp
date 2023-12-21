#include "vex.h"

using namespace vex;

namespace ui {

Text::Text( string content, int x, int y, fontType font, vex::color color, vex::color textColor ) : Paintable( x, y, color ) {
	this->setText(content);
	this->setFont(font);
	this->textColor = textColor;
}

Text::~Text() {}

void Text::setText(string string) {
	this->content = string;
}

void Text::setFont(fontType font) {
	this->font = font;
}

void Text::paint() {
	if (this->content == "") return;

	Brain.Screen.setPenColor(this->textColor);
	Brain.Screen.setFillColor(this->color);
	Brain.Screen.setFont(this->font);
	Brain.Screen.printAt(this->x, this->y, this->content.c_str());
}

}