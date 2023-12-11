#ifndef TEXT_CLASS_H
#define TEXT_CLASS_H

#include "ui/paintable.hpp"
#include "vex_global.h"
#include <string>

using namespace std;

namespace vex
{
    class text : public paintable {
        public:
            text(string content = "", int x, int y, fontType font = mono12, class color color, class color textColor = white) : paintable(x, y, -1, color) {
                this->setText(content);
                this->setFont(font);
                this->textColor = textColor;

                this->paint();
            }
            ~text() {}

            void setText(string string) {
                this->content = string;
            }

            void setFont(fontType font) {
                this->font = font;
            }

            void paint() {
                if (this->content == "") return;

                Brain.Screen.setPenColor(this->textColor);
                Brain.Screen.setFillColor(this->color);
                Brain.Screen.setFont(this->font);
                Brain.Screen.printAt(this->x, this->y, this->content.c_str());
            }

            PaintableType getType() {
                return TEXT;
            }
        private:
            string content;
            fontType font;

            vex::color textColor;
    };
    
} // namespace vex

#endif