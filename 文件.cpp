#include<stdio.h>
int main(){
	FILE *fp; 
	fp = fopen("D:/ok.txt","w+");
	fwrite("okwowoow",8,1,fp);//buffer size count fp
	fseek(fp,0,SEEK_SET);
	char str[20];
	fread(str,8,1,fp);
	str[8] = '\0';
	printf("%s\n",str);
	fclose(fp);
	/*
	
FILE * fopen(const char * path,const char * mode);
    -- path: 文件路径，如："F:\Visual Stdio 2012\test.txt"
    -- mode: 文件打开方式，例如：
             "r" 以只读方式打开文件，该文件必须存在。
             "w" 打开只写文件，若文件存在则文件长度清为0，即该文件内容会消失。若文件不存在则建立该文件。
           ?"w+" 打开可读写文件，若文件存在则文件长度清为零，即该文件内容会消失。若文件不存在则建立该文件。
             "a" 以附加的方式打开只写文件。若文件不存在，则会建立该文件，如果文件存在，写入的数据会被加到文件尾，即文件原先的内容会被保留。（EOF符保留）
             "a+" 以附加方式打开可读写的文件。若文件不存在，则会建立该文件，如果文件存在，写入的数据会被加到文件尾后，即文件原先的内容会被保留。（原来的EOF符不保留）
           ?"wb" 只写打开或新建一个二进制文件，只允许写数据。
           ?"wb+" 读写打开或建立一个二进制文件，允许读和写。
             "ab" 追加打开一个二进制文件，并在文件末尾写数据。
             "ab+"读写打开一个二进制文件，允许读，或在文件末追加数据。   
    --返回值: 文件顺利打开后，指向该流的文件指针就会被返回。如果文件打开失败则返回NULL，并把错误代码存在errno中。       
 ———————————————— 
版权声明：本文为CSDN博主「yangzhiyuan0928」的原创文章，遵循CC 4.0 by-sa版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/yang2011079080010/article/details/52528261*/
} 
