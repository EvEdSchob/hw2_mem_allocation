/*
Date 7/30/24
Class: CS4541
Assignment: Memory Allocation
Author: Evan Schober
*/
#define _GNU_SOURCE
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>

#define HEAPMAX 100000 //

int main(int argc, char *argv[]){ //argv[] = {mem_alloc, input_file, [i]mplicit/[e]xplicit, [f]irst-fit/[b]est-fit}
    if(argc != 4) {
        printf("Too many/few arguments!\n./mam_alloc input.csv (i||e) (f||b)\n");
        return -1;
    }

    if(*argv[2] != 'i' && *argv[2] != 'e') {
        printf("Invalid input! [i]mplicit/[e]xplicit\n./mam_alloc input.csv (i||e) (f||b)\n");
        return -1;
    }
    
    if(*argv[3] != 'f' && *argv[2] != 'b') {
        printf("Invalid input! [f]irst/[b]est\n./mam_alloc input.csv (i||e) (f||b)\n");
        return -1;
    }

    //TODO: Switch for implicit/explicit free-list
    //TODO: Switch for first/best fit algorithms
    
    size_t heapsize = 0; //Storage for current size of heap

    char *buffer = NULL; //Buffer used to parse files
    size_t length = 0; //# of chars returned by getline()

    char *input = argv[1];
    FILE *input_fd = fopen(input, "r"); //Open the input csv in "read-only" mode
    getline(&buffer, &length, input_fd); //Read first line from the file
    do{
        //TODO: Complete strsep operations for each field
        char func; //Separate function
        size_t size; //Separate size
        char* dest; //Separate destination
        switch (func)
        {
        case 'a': //Alloc
            myAlloc(size);
            break;
        case 'r': //Realloc
            myRealloc(dest, size);
            break;

        case 'f': //Free
            myFree(dest);
            break;
        default:
            printf("Invalid input from csv file!");
            break;
        }

    } while(strchr(buffer, '\n')); //Continue reading lines until the last character 

}

//4 Functions
//1) myAlloc(n)
//receive integer value of bytes to allocate
//return "pointer" of the starting address of the payload in the allocated block
void myAlloc(size_t n){
    //Make non-void
}

//2) myRealloc(*,n)
//recieve pointer and new size
//return a "pointer" to new block
//free old block
//myRealloc(*, 0) = myfree()
void myRealloc(char* ptr, size_t n){
    //Make non-void
}

//3) myFree(*)
//frees the block at the specified pointer
//no return value == void
//does nothing if the referenced pointer has not been alloc'd or realloc'd
void myFree(char * ptr){
    
}

//4) mySbrk(n)
//adjusts the size of the heap based on input size
//returns an error if sizeof(heap) > HEAPMAX
void mySbrk(size_t n){
    //Make non-void
    //Return error
}

