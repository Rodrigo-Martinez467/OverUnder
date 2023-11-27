#ifndef CANVAS_CLASS_H
#define CANVAS_CLASS_H

#include "ui/paintable.hpp"
#include <vector>

using namespace std;

namespace vex {
    class canvas {
        public:
            canvas() {}
            ~canvas() {}

            void addElement( paintable element ) {
                this->elements.resize( this->elements.capacity() + 1 );
                this->elements.push_back( element );
            }

            void addElements() {}
            
            template<typename First, typename ... Elements>
            void addElements( First element, const Elements&... rest ) {
                this->addElement( element );
                this->addElements( rest... );
            }

            void onScreenPressed() {
                for ( int i = 0; i < this->elements.size(); i++ ) {
                    this->elements[i].onScreenPressed();
                }
            }

            vector<paintable> getElements() {
                return this->elements;
            }
        private:
            vector<paintable> elements;
            
    };
} // namespace vex


#endif