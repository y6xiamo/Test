#include<stdio.h>
#include<stdlib.h>
#include<dirent.h>
#include<string.h>
#include<sys/stat.h>
#include<unistd.h>

void print_tree(const char * str,int gap,char shp)
{
    DIR *pdir = opendir(str);
    if(pdir == NULL)
        return;

    struct dirent  *pd = NULL;
    while((pd = readdir(pdir)) != NULL)
    {
          if(strcmp(pd->d_name,".") == 0 ||strcmp(pd->d_name,"..") == 0)
              continue;
          int len = strlen(str)+1+strlen(pd->d_name);
          char * tmp = malloc(len);
          sprintf(tmp,"%s/%s",str,pd->d_name);

          struct stat sbuf;
          lstat(tmp,&sbuf);

          int i;
          for(i = 0;i<gap;i++)
              printf("%c",shp);

          char *p = strrchr(tmp,'/');
          if(p == NULL)
              printf("%s\n",p);
          else
              printf("%s\n",p+1);

          if(S_ISREG(sbuf.st_mode))
              //printf
          if(S_ISDIR(sbuf.st_mode))
              print_tree(tmp,gap,shp);
    }
}
int main()
{
    print_tree(".",0,'-');
}
