#ifndef PAINTABLE_INTERFACE_H
#define PAINTABLE_INTERFACE_H

#include "vex_color.h"
#include "helpers.h"

using namespace std;

namespace vex {
    enum PaintableType {
        DEFAULT,
        BUTTON,
        TEXT
    };
        
    class paintable {
        public:
            paintable( int x = 0, int y = 0, int size = 0, class color color = black ) {
                this->setTransform(x, y);
                this->size = size;
                this->setColor(color);
            }

            void setTransform( int x, int y ) {
                this->x = x;
                this->y = y;
            }

            void move( int x, int y ) {
                this->setTransform(this->x + x, this->y + y);
            }
            
            virtual void onScreenPressed( int x, int y ) {
                this->paint();
            }

            int x, y, size;
            color color;

            void setColor(class color color) {
                this->color = color;
            }
            
            virtual void paint() {}

            virtual PaintableType getType() {
                return DEFAULT;
            }
            
            ~paintable() {
                
            }
    };


} // namespace vex


#endif