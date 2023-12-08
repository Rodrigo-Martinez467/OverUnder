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
            text(string content = "", int x = 0, int y = 0, fontType font = mono12, class color color = black) : paintable(x, y, -1, color) {
                this->setText(content);
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
                
                Brain.Screen.setFont(this->font);
                Brain.Screen.printAt(this->x, this->y, this->content.c_str());
            }

            PaintableType getType() {
                return TEXT;
            }
        private:
            string content;
            fontType font;
    };
    
} // namespace vex

#endif