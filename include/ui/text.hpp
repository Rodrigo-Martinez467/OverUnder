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
            text(string content, int x, int y, fontType font, class color color, string role = "") : paintable(x, y, -1, color) {
                this->setText(content);
                this->role = role;
                this->paint();
            }
            ~text() {}
            
            static text getDefault() {
                return text("", 0, 0, mono12, black);
            }

            void setText(string string) {
                this->content = string;
            }

            void setFont(fontType font) {
                this->font = font;
            }

            string getRole() {
                return this->role;
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
            string role;
    };
    
} // namespace vex

#endif