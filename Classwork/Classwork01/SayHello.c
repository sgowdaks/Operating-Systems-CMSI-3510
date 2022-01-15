#include <stdio.h>
#include <stdlib.h>

int main( int argc, char * argv[] ) {

   char name[10];
   char   input[25];
   printf( "Hello, World!" );
   gets( input ) ;
   printf( "Hello, %s\n  !", input);
   exit( 0 );

}
