#ifndef CANVAS_CLASS_H
#define CANVAS_CLASS_H

#include "ui/paintable.hpp"
#include <map>

using namespace std;

namespace vex {
    class canvas {
        public:
            canvas() {}
            ~canvas() {}

            void setElement( string key, paintable element ) {
                this->elements.insert(pair<string, paintable>(key, element));
            }

            void clear() {
                this->elements.clear();
            }

            void onScreenPressed( int x, int y ) {
                for (auto const& entry : this->elements) {
                    paintable element = entry.second;
                    element.onScreenPressed( x, y );
                }
            }

            map<string, paintable> getMap() {
                return this->elements;
            }

            paintable get(string key) {
                return this->elements.at(key);
            }
        private:
            map<string, paintable> elements = map<string, paintable>();
            
    };
} // namespace vex


#endif