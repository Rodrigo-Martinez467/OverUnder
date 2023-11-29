#ifndef BUTTON_CLASS_H
#define BUTTON_CLASS_H

#include "ui/paintable.hpp"
#include "ui/text.hpp"
#include "vex_brain.h"
#include "vex_global.h"

namespace vex {
    class screenButton : public paintable {
        public: 
            screenButton( int x, int y, int size, class color color, void action(), text buttonText ) : paintable(x, y, size, color), buttonText(text::getDefault()) {
                this->init(action, buttonText);
            }
            
            ~screenButton() {}

            bool isPressed() {
                return this->pressed;
            }
            void onScreenPressed() {
                this->getPressed(Brain.Screen.xPosition(), Brain.Screen.yPosition());
                if (this->isPressed()) {
                    this->action();
                }
                
                this->paint();
            }

            void paint() {
                Brain.Screen.setFillColor(this->color);
                Brain.Screen.drawRectangle(this->x, this->y, this->size, this->size);
            }

            PaintableType getType() {
                return BUTTON;
            }
        private:
            bool pressed;
            void (* action)();
            text buttonText;

            void init(void action(), text buttonText) {
                this->action = action;
                this->buttonText = buttonText;

                this->paint();
            }
            
            bool getPressed(int tx, int ty) {
                return ((tx >= this->x && tx <= this->x + this->size) && (ty >= this->y && ty <= this->y + this->size));
            }
    };
} // namespace vex

#endif