#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<unistd.h>
#include<dirent.h>
#include<string.h>
void copy_file(const char *src,const char *dst,mode_t mode)
{
           struct stat sbuf_src;
           FILE *fp_dst = fopen(dst,"w");
           FILE *fp_src = fopen(src,"r");
           if(fp_src == NULL || fp_dst == NULL)
           {
             fprintf(stderr,"open file error\n");
             return;

           }
           chmod(dst,sbuf_src.st_mode);
           
           char buf[10] = {};
           int r;
           while((r = fread(buf,1,sizeof(buf),fp_src)))
           {
                  fwrite(buf,1,r,fp_dst);
           }

               fclose(fp_dst);
               fclose(fp_src);

}

void cp_dir(const char *src,const char *dst)
{
       DIR *pdir = opendir(src);
       struct dirent *pd = NULL;

       struct stat sbuf_src;

       while((pd = readdir(pdir)) != NULL)
       {
            if(strcmp(pd->d_name,".")==0|| strcmp(pd->d_name,"..")==0)
               continue;

            int len = strlen(src)+2+strlen(pd->d_name);
            char *src_name = (char *)malloc(len);
            memset(src_name,0x00,len);
            sprintf(src_name,"%s/%s",src,pd->d_name);
            

            len = strlen(dst)+2+strlen(pd->d_name);
            char *dst_name = (char *)malloc(len);
            memset(dst_name,0x00,len);
            sprintf(dst_name,"%s/%s",dst,pd->d_name);

            lstat(src_name,&sbuf_src);
            if(S_ISREG(sbuf_src.st_mode))
            {
                copy_file(src_name,dst_name,sbuf_src.st_mode);
            }
            else if(S_ISDIR(sbuf_src.st_mode))
            {
                mkdir(dst_name,sbuf_src.st_mode);
                cp_dir(src_name,dst_name);
            }
       }
}



int main(int argc,char *argv[])
{
    if(argc != 3)
    {
        fprintf(stderr,"%s srv dst\n",argv[0]);
        exit(1);
    }

    struct stat sbuf_src;
    if((lstat(argv[1],&sbuf_src) == -1))
    {
         fprintf(stderr,"%s no such file",argv[1]);
         exit(1);
     }

     mode_t old = umask(0);
     if(S_ISREG(sbuf_src.st_mode))
     {
          struct stat sbuf_dst;
          if(lstat(argv[2],&sbuf_dst) ==-1)
          {
             copy_file(argv[1],argv[2],sbuf_src.st_mode);

          }
          else if(S_ISREG(sbuf_dst.st_mode))
          {
             printf("dst file is exit,shi fou fu gai?[y/n]");
             char c = 'n';
             scanf("%[yYnN]",&c);
             if(c == 'Y'||c == 'y')
             {
                copy_file(argv[1],argv[2],sbuf_src.st_mode);
             }
          }
          else if(S_ISDIR(sbuf_dst.st_mode))
          {
              int len = strlen(argv[1])+2+strlen(argv[2]);
              char *tmp = (char *)malloc(len);
              memset(tmp,0x00,len);
              sprintf(tmp,"%s/%s",argv[2],argv[1]);
         
              copy_file(argv[1],tmp,sbuf_src.st_mode);
          }
          
        }
        else if(S_ISDIR(sbuf_src.st_mode))
        {
           struct stat sbuf_dst;
           if(lstat(argv[2],&sbuf_dst) == -1)
           {
                mkdir(argv[2],sbuf_src.st_mode);
                cp_dir(argv[1],argv[2]);
            }
            else if(S_ISREG(sbuf_dst.st_mode))
            {
                fprintf(stderr,"bu neng jiang dir cope to file\n");
                exit(1);
            }
           else if(S_ISDIR(sbuf_dst.st_mode))
           {
              int len = strlen(argv[1])+2+strlen(argv[2]);
              char *tmp = (char *)malloc(len);
              memset(tmp,0x00,len);
              sprintf(tmp,"%s/%s",argv[2],argv[1]);
              cp_dir(argv[1],tmp);
           }
        }
              umask(old);
        }
