#ifndef CANVAS_CLASS_H
#define CANVAS_CLASS_H

#include "vex.h"

using namespace std;

namespace ui {
    class canvas {
        public:
            canvas();
            ~canvas();

            void setElement( string key, paintable element );

            bool has( string key );

            void clear();

            void onScreenPressed( int x, int y );

            void paint();

            map<string, paintable> getMap();

            paintable get(string key);
        private:
            map<string, paintable> elements = map<string, paintable>();
            
    };
} // namespace ui


#endif