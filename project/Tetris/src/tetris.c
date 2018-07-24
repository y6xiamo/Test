#include<stdio.h>
#include<def.h>
#include<string.h>
#include<sys/select.h>
#include<unistd.h>
#include<keyboard.h>
#include<tetris.h>
//显示出一个格子
void draw_element(int x,int y,int c)
{
    x *= 2;
    printf("\033[%d;%dH\033[?25h",y,x);//\033[?25h隐藏光标
    printf("\033[3%dm\033[4%dm[]",c,c);
    fflush(stdout);     
    printf("\033[0m");//恢复光标

}
//显示出图形
void draw_shape(int x,int y,struct shape p,int c)
{
    int i = 0;
    for( ;i < H; i++)
    {
        int j = 0;
        for( ;j < W;j++)
        {
            if(p.s[i][j] != 0)
            {
                draw_element(x + j,y + i,c);
            }
        }
    }
}
//判断能否旋转
static struct shape turn_90(struct shape p)
{
    struct shape t;

    for(int i = 0;i < 5;i++)
    {
        for(int j = 0;j < 5;j++)
        {
            t.s[i][j] = p.s[4-i][j];
        }
    }
    return t;


}
//画背景颜色
void draw_back()
{
    int i = 0;
    for( ; i < H;i++)
    {
        int j = 0;
        for( ;j < W;j++)
        {
            draw_element(j,i,BC);
        }
    }

}

//定时显出图形
void timer_tetris(struct data *p)
{
    draw_shape(p->x,p->y,shape_arr[0],BC);
    p->y++;
    draw_shape(p->x,p->y,shape_arr[0],FC);
}

int tetris(struct data *p)
{
    int ret = 0;

    int c = get_key();
    if(is_left(c))
    {
        draw_shape(p->x,p->y,shape_arr[0],BC);
        p->x--;
        draw_shape(p->x,p->y,shape_arr[0],FC);
    }
    if(is_right(c))
    {
        draw_shape(p->x,p->y,shape_arr[0],BC);
        p->x++;
        draw_shape(p->x,p->y,shape_arr[0],FC);
    }
    if(is_up(c))
    {
        draw_shape(p->x,P->Y,shape_arr[0],BC);
        shape_arr[0] = turn_90(shape_arr[0]);
        draw_shape(p->x,p->y,shape_arr[0],FC);
    }
    if(is_down(c))
    {
        draw_shape(p->x,p->y,shape_arr[0],BC);
        p->y++;
        draw_shape(p->x,p->y,shape_arr[0],FC);
    }
    if(is_esc(c))
    {
        ret = 1;
    }
    return ret;
}
