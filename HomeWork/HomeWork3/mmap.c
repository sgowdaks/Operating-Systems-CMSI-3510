#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <stdio.h>
#include <time.h>

int main(int argc, char* argv[])
{
  	clock_t stime;
  	stime = clock();

    if(argc != 2){
      perror("please provide the file name");
      return -1;
  }

	int file_ = open(argv[1], O_RDONLY);

	if (file_ < 0)
	{
		perror(argv[1]);
    return -1;
	}

	struct stat read;
	if (fstat(file_, &read) < 0)
	{
		perror("Error stating input file.");
		return -1;
	}

	char* addre_of = mmap(0, read.st_size, PROT_READ, MAP_SHARED, file_, 0);
	for(int i = 0;i < read.st_size; i++){
      if(addre_of[i] == 'X'){
          printf("X is in the file\n");
          close(file_);
          stime = clock() - stime;
        	double timeTaken = ((double)stime) / CLOCKS_PER_SEC;
        	printf("Execution Time: %f\n", timeTaken);
          return 0;
      }
  }
  printf("X not found!");
  stime = clock() - stime;
  double timeTaken = ((double)stime) / CLOCKS_PER_SEC;
  printf("Execution Time: %f\n", timeTaken);
  return 0;
}
