#ifndef DRAW_TEXT_H
#define DRAW_TEXT_H

typedef struct
{
    int font_size; // 字体大小
    int start_x;   // 水平起始位置
    int start_y;   // 垂直起始位置
} TextBox;

TextBox draw_text_on_box(int box_size, const char *str);

#endif // DRAW_TEXT_H