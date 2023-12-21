#ifndef CANVAS_CLASS_H
#define CANVAS_CLASS_H

#include "vex.h"

using namespace std;
using namespace util;

namespace ui {

class Canvas {
    public:
        Canvas();
        ~Canvas();

        void setElement( string key, Paintable element );

        bool has( string key );

        void clear();

        void onScreenPressed( int x, int y );

        void paint();

        map<string, Paintable*> getMap();

        Paintable* get(string key);

        template<class target, typename enable_if<is_base_of<Paintable, target>::value>::type* = nullptr>
        target* get(string key) {
            Paintable* obj = this->get(key);
            target* targetPtr = castPtr<Paintable, target>(obj);
            return targetPtr;
        }
    private:
        map<string, Paintable*> elements = map<string, Paintable*>();
        
};

} // namespace ui


#endif