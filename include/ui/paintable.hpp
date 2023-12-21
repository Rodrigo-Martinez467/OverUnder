#ifndef PAINTABLE_INTERFACE_H
#define PAINTABLE_INTERFACE_H

#include "vex.h"

using namespace vex;

namespace ui {

class Paintable {
    public:
        Paintable( int x = 0, int y = 0, class color color = black );

        void setTransform( int x, int y );

        void move( int x, int y );
        
        virtual void onScreenPressed( int x, int y );

        int x, y;
        color color;

        void setColor(class color color);
        
        virtual void paint();
        
        ~Paintable();
};

} // namespace ui


#endif