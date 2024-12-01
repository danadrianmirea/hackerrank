#pragma once

#include <stdio.h>
#include <stdlib.h>
#define MAX_HEIGHT 41

struct box
{
    /**
     * Define three fields of type int: length, width and height
     */
    int length;
    int width;
    int height;
};

typedef struct box box;

int get_volume(box b)
{
    /**
     * Return the volume of the box
     */
    return b.length * b.height * b.width;
}

int is_lower_than_max_height(box b)
{
    /**
     * Return 1 if the box's height is lower than MAX_HEIGHT and 0 otherwise
     */
    return b.height < MAX_HEIGHT ? 1 : 0;
}

int TestBoxes()
{
    int n;

    char input[] = {"4 5 5 5 1 2 40 10 5 41 7 2 42"};

    sscanf(input + 0, "%d", &n);
    box *boxes = malloc(n * sizeof(box));
    int index = 1;
    for (int i = 0; i < n; i++)
    {
        int count = sscanf(input + index, "%d %d %d", &boxes[i].length, &boxes[i].width, &boxes[i].height);
        index += count;
    }
    for (int i = 0; i < n; i++)
    {
        if (is_lower_than_max_height(boxes[i]))
        {
            printf("%d\n", get_volume(boxes[i]));
        }
    }
    return 0;
}