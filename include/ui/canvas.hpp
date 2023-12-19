#ifndef CANVAS_CLASS_H
#define CANVAS_CLASS_H

#include "vex.h"

using namespace std;
using namespace Util;

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

            map<string, paintable*> getMap();

            paintable* get(string key);

            template<class target>
            target* get(string key) {
                paintable* obj = this->get(key);
                target* targetPtr = castPtr<paintable, target>(obj);
                return targetPtr;
            }
        private:
            map<string, paintable*> elements = map<string, paintable*>();
            
    };
} // namespace ui


#endif