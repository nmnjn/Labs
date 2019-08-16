
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>

int main(){
    //the file should exist in the same directory
    int filePointer = open("temp.txt", O_RDONLY);
    //add error handling here

    char buffer[256];
    read(filePointer, buffer, sizeof(buffer));
    int i = 0;
    char ch;
    int characters, words, lines;

    characters = words = lines = 0;

    while(buffer[i] != '\0'){
        ch = buffer[i];
        characters++;
        printf("%c", ch);

        if (ch == '\n' || ch == '\0'){
            lines++;
            // characters--;
        }

        //this logic will miss the cases where there are two or more
        //blank spaces between each word
        if (ch == ' ' || ch == '\t' || ch == '\n' || ch == '\0'){
            words++;
            characters--;
        }

        i++;
    }

    printf("\n");
    printf("Total characters: %d\n", characters);
    printf("Total words: %d\n", words);
    printf("Total lines: %d\n", lines);
}