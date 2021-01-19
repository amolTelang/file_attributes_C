//c program for file attributes UNIX os


//header files
#include<stdlib.h>
#include<stdio.h>
#include<sys/stat.h>   //used for stat() system cal

//main function
int main(int argc,char *argv[])
{
	int iRet;			//variabele to store return value
	struct stat fileAtt;	//struct stat variale 

	if(argc!=2)	//if arguments passed is leass then 2
	{
		printf("\nUSAGE ./a.out <file_name>\n\n");
		exit(0);
	}
	//end if
	iRet=lstat(argv[1],&fileAtt);	//lstat() system call passing file name and stat varibale

	if(iRet<0)		//lstat return -1 if file does not exist
	{
		printf("\n %s file does not exist: stat failed\n\n",argv[1]);
		exit(0);
	}
	//end if

	//printing all the attributes of the given file
	printf("\nFile attributes");
	printf("\nFile name:%s\n",argv[1]);	//displays file name
	printf("\nFile System Id: %i \n",fileAtt.st_dev);	//gives file system id
	printf("\nFile Inode number %i \n",fileAtt.st_ino);	//gives inode number
	printf("\nFile Type: %F \n",fileAtt.st_mode);//shows protection mode
	printf("\nHard link count: %d\n",fileAtt.st_nlink);//gives hard link count     
	printf("\nFile User Id: %u\n",fileAtt.st_uid);	//gives user id of file owner
	printf("\nFile Group Id: %g \n",fileAtt.st_gid);	//gives group id of owner
	printf("\nFile size in number of bytes: %d\n",fileAtt.st_size);	//gives file size
	printf("\nLast access time :%x \n",fileAtt.st_atime);	//gives last access time of the file
	printf("\nFile permissions:");                                                                                                                                                                                                                                                                                                          
	printf( (S_ISDIR(fileAtt.st_mode)) ? "d" : "-"); //testing for a directory  
	printf( (fileAtt.st_mode & S_IRUSR) ? "r" : "-"); //read permission for user
	printf( (fileAtt.st_mode & S_IWUSR) ? "w" : "-"); //write permission for user 
 	printf( (fileAtt.st_mode & S_IXUSR) ? "x" : "-"); //execute/search  permission for user 
 	printf( (fileAtt.st_mode & S_IRGRP) ? "r" : "-"); //read permission for grupt
 	printf( (fileAtt.st_mode & S_IWGRP) ? "w" : "-"); //write permission for group
 	printf( (fileAtt.st_mode & S_IXGRP) ? "x" : "-"); //execute/search  permission for group 
 	printf( (fileAtt.st_mode & S_IROTH) ? "r" : "-"); //read permission for others 
 	printf( (fileAtt.st_mode & S_IWOTH) ? "w" : "-"); //write permission for  others 
 	printf( (fileAtt.st_mode & S_IXOTH) ? "x" : "-"); //execute/search  permission for others 
 	printf("\n\n"); 


}
//end main
