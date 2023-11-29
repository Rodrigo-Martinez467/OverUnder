#ifndef PAINTABLE_INTERFACE_H
#define PAINTABLE_INTERFACE_H

#include "vex_color.h"
#include "helpers.h"
#include <array>

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
                this->x = x;
                this->y = y;
                this->size = size;
                this->setColor(color);
            }
            
            virtual void onScreenPressed() {
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