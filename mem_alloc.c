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

#define HEAPMAX 100000 //Defines the maximum size of the heap

//Explicit free list entry
typedef struct{
    NODE_E * prev; //Previous node in Free List
    NODE_E * next; //Next node in Free List
    size_t payload; //Size of the memory block
}NODE_E;

//Node of singly linked list which will hold all requests
typedef struct{
    char func;
    int param[3];
    REQUEST * next; 
}REQUEST;

//Function primatives
REQUEST* readLine(char* buf);

int main(int argc, char *argv[]){ //argv[] = {mem_alloc, input_file, [i]mplicit/[e]xplicit, [f]irst-fit/[b]est-fit}
    if(argc != 4) {
        printf("Too many/few arguments!\n./mem_alloc input.csv (i||e) (f||b)\n");
        return -1;
    }

    if(*argv[2] != 'i' && *argv[2] != 'e') {
        printf("Invalid input! [i]mplicit/[e]xplicit\n./mem_alloc input.csv (i||e) (f||b)\n");
        return -1;
    }
    
    if(*argv[3] != 'f' && *argv[2] != 'b') {
        printf("Invalid input! [f]irst/[b]est\n./mem_alloc input.csv (i||e) (f||b)\n");
        return -1;
    }

    char ie = *argv[2];
    char fb = *argv[3];
    
    
    size_t heapsize = 0; //Storage for current size of heap

    char *buffer = NULL; //Buffer used to parse input file
    size_t length = 0; //# of chars returned by getline()

    char *input = argv[1];
    FILE *input_fd = fopen(input, "r"); //Open the input csv in "read-only" mode
    REQUEST head; //Blank request struct to act as the head of the request list
    REQUEST cursor; //"Cursor" node for following the linked list
    head = cursor; 
    getline(&buffer, &length, input_fd); //Read first line from the file
    do{

        REQUEST * req = readLine(&buffer); //Create new list item
        cursor.next = req; //Attach to the current node in the list
        cursor = cursor.next; //Move cursor to the new request
        getline(&buffer, &length, input_fd); //Read next line from the file


        //TODO: Complete strsep operations for each field
        // char func; //Separate function code
        // size_t size; //Separate size
        // char* dest; //Separate destination
        // switch (func)
        // {
        // case 'a': //Alloc
        //     myAlloc(size, ie, fb);
        //     break;
        // case 'r': //Realloc
        //     myRealloc(dest, size);
        //     break;

        // case 'f': //Free
        //     myFree(dest);
        //     break;
        // default:
        //     printf("Invalid input from csv file!");
        //     break;
        // }

    } while(strchr(buffer, '\n')); //Continue reading lines until the last character 

}

//4 Functions
//1) myAlloc(n)
//receive integer value of bytes to allocate
//return "pointer" of the starting address of the payload in the allocated block
char * myAlloc(size_t n, char ie, char fb){
    char * ptr;
    //Generate new free-list entry
    //Step through free-list
    if (fb = 'f')
    {
        //First-Fit - Step through each list until a free entry of the appropriate size is found
    }
    else
    {
        //Best-Fit - Step through the entire list and pick the option with the one with the least extra
    }
    //If no free space is found for new entry
    //mySbrk(n); //Increase heap size
    return ptr;
}

//2) myRealloc(*,n)
//recieve pointer and new size
//return a "pointer" to new block
//free old block
//myRealloc(*, 0) = myfree()
void myRealloc(char* ptr, size_t n){
    //Make non-void
    //Find specified entry in free list
    //Free specified
    //myFree(ptr);
    //Allocate new entry
    //myAlloc(n);
    //Return pointer to new block
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
    size_t newHeap; //
    //Return error
    if (newHeap > HEAPMAX)
    {
        printf("Heap max size exceeded!\n");
        //Exit program?
    }
    
}

REQUEST* readLine(char* buf){
    //Generate new 
    REQUEST* req = malloc(sizeof(REQUEST));

    char* bufp = buf;
    char* token = NULL;
    token = strsep(&bufp, ",\n");
    req->func = strdup(token);
    token = strsep(&bufp, ",\n");
    int i = 0;
    while (token != "\n")
    {
        req->param[i] = atoi(token);
        i++;
        token = strsep(&bufp, ",\n");
    }
    return req;
}
