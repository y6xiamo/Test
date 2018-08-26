#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/stat.h>
#include<pwd.h>
#include<grp.h>
#include<time.h>
#include<string.h>
#include<dirent.h>

void file_type(mode_t md)
{
    
    char mode[11] = "?---------";
       
    if((md & S_IFMT) == S_IFREG) mode[0] = '-';
    if((md & S_IFMT) == S_IFLNK) mode[0] = 'l';
    if((md & S_IFMT) == S_IFDIR) mode[0] = 'd';
    if((md & S_IFMT) == S_IFCHR) mode[0] = 'c';
    if((md & S_IFMT) == S_IFIFO) mode[0] = 'p';
    if((md & S_IFMT) == S_IFSOCK) mode[0] = 's';
    if((md & S_IFMT) == S_IFBLK) mode[0] = 'b';
     
    
    if(md & S_IRUSR) mode[1] = 'r';
    if(md & S_IWUSR) mode[2] = 'w';
    if(md & S_IXUSR) mode[3] = 'x';
    
    if(md & S_IRGRP) mode[4] = 'r';
    if(md & S_IWGRP) mode[5] = 'w';
    if(md & S_IXGRP) mode[6] = 'x';

    if(md & S_IROTH) mode[7] = 'r';
    if(md & S_IWOTH) mode[8] = 'w';
    if(md & S_IXOTH) mode[9] = 'x';
    printf("%s",mode);

}

int main(int argc,char *argv[])
{
    if(argc != 2)
    {
       fprintf(stderr,"usage:%s filename\n",argv[0]);
        exit(1);
    }
    
    struct stat sbuf;
    if(lstat(argv[1],&sbuf) == -1)
    {
        printf("no such file or directory\n");
        return 1;
    }
   
    
         
        file_type(sbuf.st_mode);

        printf("  %d  ",sbuf.st_nlink);    

        struct passwd *pw = getpwuid(sbuf.st_uid);
        if(pw != NULL)
           printf(" %s  ",pw->pw_name);

        struct group *gp = getgrgid(sbuf.st_gid);
        if(gp != NULL)
            printf(" %s  ",gp->gr_name);

        printf("%d",sbuf.st_size);

        struct tm *p = localtime(&sbuf.st_mtime);
        printf(" %4d%2d%2d",p->tm_year+1900,p->tm_mon+1,p->tm_mday);

        printf("%2d:%2d:%2d",p->tm_hour,p->tm_min,p->tm_sec);

        printf(" %s",argv[1]);

        if(S_ISLNK(sbuf.st_mode))
        {
            printf(" -> ");
            char target[256] ={};
            readlink(argv[1],target,sizeof(target));
            printf("%s",target);
        }
        printf("\n");
         
}
