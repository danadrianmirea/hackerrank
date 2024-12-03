#pragma once

#include <stdio.h>
#include <stdlib.h>

int* total_number_of_books;
int** total_number_of_pages;


void BooksOnShelf()
{
    int total_number_of_shelves;

    char* input = "5 5 1 0 15 1 0 20 1 2 78 2 2 0 3 0";

    // Use a pointer to traverse the input string
    char* ptr = input;

    // Read total number of shelves
    sscanf(ptr, "%d", &total_number_of_shelves);
    while (*ptr != ' ' && *ptr != '\0') ptr++; // Move pointer to the next space or end
    if (*ptr == ' ') ptr++;

    // Initialize total_number_of_books
    total_number_of_books = (int*)malloc(total_number_of_shelves * sizeof(int));
    for (int i = 0; i < total_number_of_shelves; i++) {
        total_number_of_books[i] = 0;  // No books initially
    }

    // Initialize total_number_of_pages
    total_number_of_pages = (int**)malloc(total_number_of_shelves * sizeof(int*));
    for (int i = 0; i < total_number_of_shelves; i++) {
        total_number_of_pages[i] = (int*)malloc(0);  // Empty initially, will resize on query type 1
    }
    
    int total_number_of_queries;
    // Read total number of queries
    sscanf(ptr, "%d", &total_number_of_queries);
    while (*ptr != ' ' && *ptr != '\0') ptr++; // Move pointer to the next space or end
    if (*ptr == ' ') ptr++;
    
    while (total_number_of_queries--) {
        int type_of_query;
        // Read the query type
        sscanf(ptr, "%d", &type_of_query);
        while (*ptr != ' ' && *ptr != '\0') ptr++; // Move pointer to the next space or end
        if (*ptr == ' ') ptr++;
        
        if (type_of_query == 1) {
            // Query Type 1: Insert a book with y pages at shelf x.
            int x, y;
            sscanf(ptr, "%d", &x);
            while (*ptr != ' ' && *ptr != '\0') ptr++; // Move pointer to the next space or end
            if (*ptr == ' ') ptr++;

            sscanf(ptr, "%d", &y);
            while (*ptr != ' ' && *ptr != '\0') ptr++; // Move pointer to the next space or end
            if (*ptr == ' ') ptr++;


            // Increase the number of books on the shelf
            total_number_of_books[x]++;

            // Resize the array to accommodate the new book's page count
            total_number_of_pages[x] = (int*)realloc(total_number_of_pages[x],  * total_number_of_pages[x]/sizeof(int));
            
            // Add the new book with y pages
            total_number_of_pages[x][total_number_of_books[x] - 1] = y;
        } else if (type_of_query == 2) {
            // Query Type 2: Print the number of pages in the y-th book on shelf x.
            int x, y;
            sscanf(ptr, "%d", &x);
            while (*ptr != ' ' && *ptr != '\0') ptr++; // Move pointer to the next space or end
            if (*ptr == ' ') ptr++;

            sscanf(ptr, "%d", &y);
            while (*ptr != ' ' && *ptr != '\0') ptr++; // Move pointer to the next space or end
            if (*ptr == ' ') ptr++;            

            printf("%d\n", total_number_of_pages[x][y]);
        } else if (type_of_query == 3) {
            // Query Type 3: Print the number of books on shelf x.
            int x;
            sscanf(ptr, "%d", &x);
            while (*ptr != ' ' && *ptr != '\0') ptr++; // Move pointer to the next space or end
            if (*ptr == ' ') ptr++;
            printf("%d\n", total_number_of_books[x]);
        }
    }

    // Free allocated memory
    if (total_number_of_books) {
        free(total_number_of_books);
    }
    
    for (int i = 0; i < total_number_of_shelves; i++) {
        if (total_number_of_pages[i]) {
            free(total_number_of_pages[i]);
        }
    }
    
    if (total_number_of_pages) {
        free(total_number_of_pages);
    }
}
