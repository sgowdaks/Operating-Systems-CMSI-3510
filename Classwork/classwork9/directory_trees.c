#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>


 int main( int argc, char * argv[] ) {
    struct dirent *directoryEntry;  // Pointer for directory entry
    struct stat filestatus;

   // opendir() returns a pointer of DIR type
   //  we are looking at the current diretory, indicated by "."
    DIR *directory = opendir( "." );

   // opendir returns NULL if couldn't open directory
    if( directory == NULL ) {
       printf("Could not open current directory" );
       return 0;
    }

   // Refer to
   //  http://pubs.opengroup.org/onlinepubs/7990989775/xsh/readdir.html
   // for readdir() details

int one = 0;
int two  = 0;
int three = 0;
int four = 0;
int five = 0;

    char modeString[10];

    while( (directoryEntry = readdir( directory )) != NULL ){

      printf("%s\n", directoryEntry->d_name);

      if( stat( directoryEntry->d_name, &filestatus ) == -1 ) {
            printf( "\n   can't get file status for %s\n\n", argv[1] );
            return 0;
         }



   printf("   File type:              ");
   switch (filestatus.st_mode & S_IFMT) {
      case S_IFBLK:  printf("block device\n");            break;
      case S_IFCHR:  printf("character device\n");        break;
      case S_IFDIR:  printf("directory\n");               break;
      case S_IFIFO:  printf("FIFO/pipe\n");               break;
      case S_IFREG:  printf("regular file\n");            break;
 // only available on Mac/Linux
      case S_IFLNK:  printf("symlink\n");                 break;
 // only available on Mac/Linux
      case S_IFSOCK: printf("socket\n");                  break;
      default:       printf("unknown?\n");                break;
   }

   printf("   I-node number:          %ld\n", (long) filestatus.st_ino);
   printf("   Mode:                   %lo (octal)\n", (unsigned long) filestatus.st_mode);
   // makeModeStr( (unsigned long) filestatus.st_mode, modeString );
   printf( "   Mode in characters:     %s\n", modeString );
   printf("   Link count:             %ld\n", (long) filestatus.st_nlink);
   printf("   Ownership: UID:         %ld\n", (long) filestatus.st_uid);
   printf("   Ownership: GID:         %ld\n", (long) filestatus.st_gid);
  // only available on Mac/Linux
   printf("   Preferred I/O blk size: %ld bytes\n", (long) filestatus.st_blksize);

   printf("   File size:              %lld bytes\n", (long long) filestatus.st_size);
  // only available on Mac/Linux
   printf("   Blocks allocated:       %lld\n", (long long) filestatus.st_blocks);
   printf("   Last status change:     %s", ctime(&filestatus.st_ctime));
   printf("   Last file access:       %s", ctime(&filestatus.st_atime));
   printf("   Last file modification: %s\n\n\n", ctime(&filestatus.st_mtime));
   if((filestatus.st_size) < 512){
     one += 1;
   }
   else if( filestatus.st_size> 512 &&  filestatus.st_size < 2500){
     two += 1;
   }
   else if( filestatus.st_size > 2500 &&  filestatus.st_size < 5000){
     three += 1;
   }
   else if( filestatus.st_size > 5000 && filestatus.st_size< 50000){
     four += 1;
   }
   else{
     five += 1;
   }


}

printf("less than 512 bytes : %d\n",one );
printf("512 bytes or more but less than 2,500 bytes : %d\n",two);
printf("2,500 bytes or more but less than 5,000 bytes: %d\n", three );
printf("5,000 bytes or more but less than 50,000 bytes : %d\n",four );
printf("50,000 bytes or more : %d\n\n",five);



closedir(directory);

    return 0;
 }
