#ifndef BUTTON_CLASS_H
#define BUTTON_CLASS_H

#include "vex.h"

namespace ui {

class ScreenButton : public Paintable {
    public: 
        ScreenButton( int x, int y, int width, int height, class color color, void action(), Text buttonText );
        
        ~ScreenButton();

        bool isPressed();

        void onScreenPressed( int x, int y );

        void paint();
    private:
        int width, height;
        
        bool pressed;
        void (* action)();
        Text buttonText;

        void repositionText();
        
        bool getPressed(int tx, int ty);
};

} // namespace ui

#endif