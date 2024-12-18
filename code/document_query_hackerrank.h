#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<assert.h>
#define MAX_CHARACTERS 1005
#define MAX_PARAGRAPHS 5


char** split_string(const char* str, char delimiter, int* count) 
{
    char* temp = strdup(str);
    int size = 1;

    // Count occurrences of delimiter
    for (const char* p = temp; *p; p++) {
        if (*p == delimiter) {
            size++;
        }
    }

    char** result = malloc(size * sizeof(char*));
    char* token = strtok(temp, &delimiter);
    int index = 0;

    while (token) {
        result[index++] = strdup(token);
        token = strtok(NULL, &delimiter);
    }

    *count = index;
    free(temp);
    return result;
}


char* kth_word_in_mth_sentence_of_nth_paragraph(char**** document, int k, int m, int n) 
{
    return document[n - 1][m - 1][k - 1];
}

char** kth_sentence_in_mth_paragraph(char**** document, int k, int m) {

    return document[m - 1][k - 1];
}

char*** kth_paragraph(char**** document, int k) 
{
    return document[k - 1];
}

char**** get_document(char* text) 
{
    int paragraph_count;
    char** paragraphs = split_string(text, '\n', &paragraph_count);

    char**** document = malloc(paragraph_count * sizeof(char***));

    for (int i = 0; i < paragraph_count; i++) {
        int sentence_count;
        char** sentences = split_string(paragraphs[i], '.', &sentence_count);

        document[i] = malloc(sentence_count * sizeof(char**));

        for (int j = 0; j < sentence_count; j++) {
            int word_count;
            char** words = split_string(sentences[j], ' ', &word_count);

            document[i][j] = malloc(word_count * sizeof(char*));

            for (int k = 0; k < word_count; k++) {
                document[i][j][k] = words[k]; // Copy word pointers
            }
            free(words);
        }
        free(sentences);
    }

    free(paragraphs);
    return document;
}


char* get_input_text() 
{	
    int paragraph_count;
    scanf("%d", &paragraph_count);

    char p[MAX_PARAGRAPHS][MAX_CHARACTERS], doc[MAX_CHARACTERS];
    memset(doc, 0, sizeof(doc));
    getchar();
    for (int i = 0; i < paragraph_count; i++) {
        scanf("%[^\n]%*c", p[i]);
        strcat(doc, p[i]);
        if (i != paragraph_count - 1)
            strcat(doc, "\n");
    }

    char* returnDoc = (char*)malloc((strlen (doc)+1) * (sizeof(char)));
    strcpy(returnDoc, doc);
    return returnDoc;
}

void print_word(char* word) 
{
    printf("%s", word);
}

void print_sentence(char** sentence) 
{
    int word_count;
    scanf("%d", &word_count);
    for(int i = 0; i < word_count; i++){
        printf("%s", sentence[i]);
        if( i != word_count - 1)
            printf(" ");
    }
} 

void print_paragraph(char*** paragraph) 
{
    int sentence_count;
    scanf("%d", &sentence_count);
    for (int i = 0; i < sentence_count; i++) {
        print_sentence(*(paragraph + i));
        printf(".");
    }
}

void TestQueryDocument()
{
    char* text = get_input_text();
    char**** document = get_document(text);

    int q;
    scanf("%d", &q);

    while (q--) {
        int type;
        scanf("%d", &type);

        if (type == 3){
            int k, m, n;
            scanf("%d %d %d", &k, &m, &n);
            char* word = kth_word_in_mth_sentence_of_nth_paragraph(document, k, m, n);
            print_word(word);
        }

        else if (type == 2){
            int k, m;
            scanf("%d %d", &k, &m);
            char** sentence = kth_sentence_in_mth_paragraph(document, k, m);
            print_sentence(sentence);
        }

        else{
            int k;
            scanf("%d", &k);
            char*** paragraph = kth_paragraph(document, k);
            print_paragraph(paragraph);
        }
        printf("\n");
    }     
}