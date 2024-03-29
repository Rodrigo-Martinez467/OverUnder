#ifndef TEXT_CLASS_H
#define TEXT_CLASS_H

#include "vex.h"

using namespace std;

namespace ui {

class Text : public Paintable {
    public:
        Text(string content = "", int x = 0, int y = 0, fontType font = mono12, class color color = black, class color textColor = white);
        ~Text();

        void setText(string string);

        void setFont(fontType font);

        void paint();
    private:
        string content;
        fontType font;

        vex::color textColor;
};

} // namespace ui

#endif