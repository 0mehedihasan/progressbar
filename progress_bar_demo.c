#include <stdio.h>
#include <stdlib.h>

// Define the progressbar struct
typedef struct {
    const char *label;
    int max;
    int current;
    int width; // Customizable width
} progressbar;

// Create a new progressbar
progressbar* progressbar_new(const char* label, int max) {
    progressbar* bar = (progressbar*)malloc(sizeof(progressbar));
    bar->label = label;
    bar->max = max;
    bar->current = 0;
    bar->width = 40; // Default width
    return bar;
}

// Set the width of the progressbar
void progressbar_set_width(progressbar* bar, int width) {
    bar->width = width;
}

// Increment the progress and update the display
void progressbar_inc(progressbar* bar) {
    bar->current++;
    int percent = (bar->current * 100) / bar->max;
    int progress = (bar->current * bar->width) / bar->max;

    printf("\r%s [", bar->label);
    for (int i = 0; i < bar->width; i++) {
        if (i < progress)
            printf("=");
        else
            printf(" ");
    }
    printf("] %d%%", percent);
    fflush(stdout);
}

// Finish and clean up the progressbar
void progressbar_finish(progressbar* bar) {
    printf("\n");
    free(bar);
}

// Example usage
int main() {
    progressbar *bar = progressbar_new("Loading", 100); // Create a new progressbar
    progressbar_set_width(bar, 50); // Set custom width to 50

    for (int i = 0; i < 100; i++) {
        // Simulate some work
        progressbar_inc(bar); // Increment progress
    }
    progressbar_finish(bar); // Finish and clean up
    return 0;
}
