#include <stdio.h>
#include <string.h> 

void search(char* pat, char* txt) 
{ 
    int M = strlen(pat); 
    int N = strlen(txt); 
  
    /* A loop to slide pat[] one by one */
    for (int i = 0; i < N - M; i++) { 
        int j; 
  
        /* For current index i, check for pattern match */
        for (j = 0; j < M; j++) 
            if (txt[i + j] != pat[j]) 
                break; 
  
        if (j == M) // if pat[0...M-1] = txt[i, i+1, ...i+M-1] 
            printf("substring found at position %d \n", i+1); 
    } 
} 

int main() 
{ 
    char txt[] = "THIS IS ALGORITHM LAB FOR ALGOS"; 
    char pat[] = "ALGO"; 
    search(pat, txt); 
    return 0; 
} 
