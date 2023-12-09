#ifndef BUTTON_CLASS_H
#define BUTTON_CLASS_H

#include "ui/paintable.hpp"
#include "ui/text.hpp"
#include "vex_brain.h"
#include "vex_global.h"

namespace vex {
    class screenButton : public paintable {
        public: 
            screenButton( int x, int y, int size, class color color, void action(), text buttonText ) : paintable(x, y, size, color), buttonText(text()) {
                this->action = action;
                this->buttonText = buttonText;
                this->repositionText();

                this->paint();
            }
            
            ~screenButton() {}

            bool isPressed() {
                return this->pressed;
            }
            void onScreenPressed( int x, int y ) {
                this->getPressed(x, y);
                if (this->isPressed())
                    this->action();
                
                this->paint();
            }

            void paint() {
                Brain.Screen.setFillColor(this->color);
                Brain.Screen.drawRectangle(this->x, this->y, this->size, this->size);

                this->buttonText.paint();
            }

            PaintableType getType() {
                return BUTTON;
            }
        private:
            bool pressed;
            void (* action)();
            text buttonText;

            void repositionText() {
                const int x = this->buttonText.x;
                const int y = this->buttonText.y;

                this->buttonText.setTransform(this->x, this->y);
                this->buttonText.move(x + 10, y + 10);
            }
            
            bool getPressed(int tx, int ty) {
                return ((tx >= this->x && tx <= this->x + this->size)
                    && (ty >= this->y && ty <= this->y + this->size));
            }
    };
} // namespace vex

#endif