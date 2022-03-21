  #include <unistd.h>
  #include <time.h>
  #include <sys/stat.h>
  #include <stdio.h>
  #include<fcntl.h>

   int main( int argc, char * argv[] ){
      struct stat info;
      char *infile;
      int fd;
      infile = argv[1];
      fd = open(infile, O_RDONLY);
      if( fstat( fd, &info ) < 0 ) {
         perror( "   Error getting info about standard input" );
         return -1;
      }
      printf( "\n\n   Standard input is owned by user number %d\n", &info.st_uid );
      printf( "   No of block allocated to the file %s\n", ( &info.st_rdev ) );
      printf( "   device this files represent %s\n", ctime( &info.st_atime ) );
      printf( "   Feild indicated the ID of group owner %s\n", ctime( &info.st_mtime) );

      if(S_ISREG(info.st_mode)){
         printf("%d", &info.st_mode);
         printf( "   It is a %lld-byte file.", &info.st_size );
      } else {
         printf( "   It is not a regular file.\n\n" );
      }
      return 0;
   }
