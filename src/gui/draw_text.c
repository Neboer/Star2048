#include "draw_text.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


TextBox draw_text_on_box(int box_size, const char* str) {
    TextBox result = {0, 0, 0};  // 初始化结果结构体
    int str_length = strlen(str);

    // 如果字符串为空，直接返回默认结果
    if (str_length == 0) {
        return result;
    }

    // 计算最大字体大小
    int font_size = box_size / str_length;

    // 如果盒子太小无法容纳字符串，则返回默认结果
    if (font_size == 0) {
        return result;
    }

    // 计算总宽度
    int total_width = font_size * str_length;

    // 计算水平和垂直居中的起始位置
    int start_x = (box_size - total_width) / 2;
    int start_y = (box_size - font_size) / 2;

    // 填充结果结构体
    result.font_size = font_size;
    result.start_x = start_x;
    result.start_y = start_y;

    return result;
}
