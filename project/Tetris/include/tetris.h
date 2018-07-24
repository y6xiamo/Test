#pragma once
//显示出一个格子
void draw_element(int x,int y,int c);

void draw_back();
//显示出图形
void draw_shape(int x,int y,struct shape p,int c);
void timer_tetris(struct data *p);

int tetris(struct data *p);
