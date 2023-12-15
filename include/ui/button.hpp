#ifndef BUTTON_CLASS_H
#define BUTTON_CLASS_H

#include "vex.h"

namespace ui {
    class screenButton : public paintable {
        public: 
            screenButton( int x, int y, int size, class color color, void action(), text buttonText );
            
            ~screenButton();

            bool isPressed();

            void onScreenPressed( int x, int y );

            void paint();
        private:
            bool pressed;
            void (* action)();
            text buttonText;

            void repositionText();
            
            bool getPressed(int tx, int ty);
    };
} // namespace ui

#endif