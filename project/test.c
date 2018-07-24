#include <stdio.h>
#include<stdlib.h>
#include<sys/time.h>
#include<signal.h>
#include<unistd.h>
#include<string.h>
#include<sys/timerfd.h>
#include<sys/select.h>
#include<stdint.h>
#include<errno.h>
#include<termios.h>

int main()
{
    int c;
    struct termios ts;
    tcgetattr(0,&ts);//终端控制函数
    ts.c_lflag &=  ~ ICANON;
    //将其方式改为非标准，读一个显示一个到应用程序
    ts.c_lflag &= ~ ECHO;
    //设置输入不显示
    tcsetattr(0,TCSANOW,&ts);
    //对其进行设置,TCSANOW立即改变其方式
    
    char buf[1024] = {};

    int i = 0;
    while((c = getchar())!= '\n')
    {
        buf[i++] = c;
        putchar('*');
        //读一个字符打印一个*,输密码时的应用场景
    }
    ts.c_lflag |= ICANON;//将其方式重新设置为标准模式
    ts.c_lflag |= ECHO;//将其显示方式重新设置为显示
    tcsetattr(0,TCSANOW,&ts);
    printf("buf = [%s]\n",buf);

}
//void handler(int s)
//{
////    printf("recv %d\n",s);
//}
//
//
////将定时器转换为文件描述符
//int main()
//{
//    int fd = timerfd_create(CLOCK_MONOTONIC,TFD_CLOEXEC);
//    if(fd == 1)
//    {
//        perror("timerfd_create");
//        exit(1);
//    }
//    struct itimerspec isp;
//    memset(&isp,0x00,sizeof(isp));
//    isp.it_value.tv_sec = 3;
//    isp.it_interval.tv_sec = 1;
//    timerfd_settime(fd,0,&isp,NULL);
//
//    int kfd = fileno(stdin);
//
//    fd_set set;
//    int maxfd = fd > kfd ? fd : kfd;
//    while(1)
//    {
//        FD_ZERO(&set);
//        FD_SET(fd,&set);
//        FD_SET(kfd,&set);
//
//       int nready =  select(maxfd+1,&set,NULL,NULL,NULL);
//       if(nready <= 0)
//       {
//           continue;
//       }
//       if(FD_ISSET(fd,&set))
//       {
//           uint64_t es;
//           int r = read(fd,&es,sizeof(es));
//           if(r <= 0)
//           {
//               break;
//           }
//           printf("r = %d\n",r);
//       }
//       if(FD_ISSET(kfd,&set))
//       {
//           char buf[1024] = {};
//           int r;
//lab:
//           r= read(kfd,buf,1024);
//           if(r < 0)
//           {
//               if(r == -1 && errno == EINTR)
//               {
//                   goto lab;
//               }
//               break;
//           }
//           printf("buf = [%s]\n",buf);
//        }
//    }
//
//    return 0;
//}

    //定时器
//    void handler(int s)
//    {
//        printf("recv %d\n",s);
//    }
//    int main()
//    {
//        struct sigaction act;
//        act.sa_handler = handler;
//        act.sa_flags = 0;
//        sigemptyset(&act.sa_mask);
//        sigaction(SIGALRM,&act,NULL);
//
//        struct itimerval tm;
//        memset(&tm,0x00,sizeof(tm));
//        tm.it_value.tv_sec = 4;//定时时间
//        tm.it_interval.tv_sec = 1;
//        setitimer(ITIMER_REAL,&tm,NULL);
//
//         for( ; ; )
//         {
//             pause();
//         }
//    }
//#define N 6
//
//void infeat_around(int arr[][N],int i,int j)
//{
//    if(i < 0 ||i >= N ||j < 0|| j >= N ||arr[i][j] != 1)
//    {
//        return;
//    }
//    arr[i][j] = 2;
//    infeat_around(arr,i-1,j);//上面
//    infeat_around(arr,i+1,j);//下面
//    infeat_around(arr,i,j+1);//左面
//    infeat_around(arr,i,j-1);//右面
//    
//
//}
////求一个数组有多少拐
//int land(int arr[N][N],int m,int n)
//{
//    int land = 0;
//    int i = 0;
//    for( ;i < m;i++)
//    {
//        int j = 0;
//        for(; j< n;j++)
//        {
//            if(arr[i][j] == 1)
//            {
//                land++;
//                //感染周围
//                infeat_around(arr,i ,j);
//            }
//
//        }
//
//    }
//    return land;
//}
//int main()
//{
//    int arr[N][N] = {
//        1,1,1,0,0,0,
//        1,0,0,0,1,1,
//        1,0,0,0,1,0,
//        0,0,1,1,1,0,
//        0,0,0,0,0,0,
//        1,1,1,0,0,0,
//    };
//    printf("land = %d\n",land(arr,N,N));
//    return 0;
//}

//define N 4
////旋转二维数组的四个角
//void rotate(int arr[N][N],int a,int b,int c,int d)
//{
//    int i = 0;
//    for( ;i < d - b;i++)
//    {
//        int tmp = arr[a][b+i];
//        arr[a][b+i] = arr[c-i][b];//将左下角的数赋给左上角
//        arr[c-i][b] = arr[c][d-i];//将右下角的数赋给左下角
//        arr[c][d-i] = arr[a+i][d];//将右上角的数赋给右下角
//        arr[a+i][d] = tmp;//将左上角赋给右上角
//    }
//}
//
////数组的旋转
//void rotateArr(int arr[N][N])
//{
//    int a = 0;//表示第一行
//    int b = 0;//表示第一列
//    int c = N - 1;//表示最后一行
//    int d = N - 1;//表示最后一列
//    {
//        rotate(arr,a++,b++,c--,d--);
//    }
//}
//
//void show(int arr[N][N])
//{
//    int i = 0;
//    for( ;i < N;i++)
//    {
//        int j = 0;
//        for( ;j < N;j++)
//        {
//            printf("%-3d",arr[i][j]);
//        }
//        printf("\n");
//    }
//}
//int main()
//{
//    int arr[N][N];
//    int i = 0;
//    int num = 1;
//    for( ;i < N;i++)
//    {
//        int j = 0;
//        for( ;j < N;j++)
//        {
//            arr[i][j] = num;
//            num++;
//        }
//    }
//    show(arr);
//    printf("\n");
//    rotateArr(arr);
//    show(arr);
//    
//    return 0;
//}
//int main()
//{
//    int i = 1;
//    for( ;i <= 8;i++)
//    {
//        printf("\033[3%dm",i-1);
//        int j = 1;
//        for( ; j <= 8;j++)
//        {
//            if(j <= i)
//            {
//                printf("%dx%d = %-3d",j,i,i*j);
//            }
//
//        }
//        printf("\033[03m\n");
//    }
//}
