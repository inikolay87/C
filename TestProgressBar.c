#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define PROGRESS_BAR_WIDTH	50

void print_progress_bar(float percentage, int width) {
	int i;
	float count = (width*percentage/100 < width)?(width*percentage/100):width;
	int count_full = (int)count;
	int half = (int)((count - count_full) * 2);
	printf("\r[");
	for (i=0; i<count_full; i++) printf("\u2588");
	if (half) printf("\u258C");
	for (i=0; i<(width-count_full-half); i++) printf(" ");
	printf("]%5.1f%%", percentage);
	fflush(stdout);
}

void clear_progress_bar(int width) {
	int i;
	printf("\r");
	for (i=0; i<width+10; i++) printf(" ");
	printf("\r");
	fflush(stdout);
}

int main(int argc, char* argv[]) {
	int i;
	int start = 0;
	int stop = 100;

	printf("!!!Hello World!!!\n"); /* prints !!!Hello World!!! */
	for (i=0; i<=stop; i+=2) {
		print_progress_bar((float)(start+i)/stop*100, PROGRESS_BAR_WIDTH);
		usleep(100000);
	}
	clear_progress_bar(PROGRESS_BAR_WIDTH);
	printf("!!!Done!!!\n");

	return EXIT_SUCCESS;
}
