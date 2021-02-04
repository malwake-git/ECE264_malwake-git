// ***
// *** You must modify this file
// ***
#include <stdio.h>  
#include <stdlib.h> 
#include <string.h> 
#include <stdbool.h>
#include <errno.h>
#include "hw09.h"

// DO NOT MODIFY --->>>> From Here
// Do not modify this function. It is used for grading.
void printInput(char * msg, int * arr, int l, int m, int r)
{
  printf("%s(%6d, %6d, %6d)", msg, l, m, r);
  int ind;
  for (ind = l; ind <= r; ind ++)
    {
      printf("%d\n", arr[ind]);
    }
}
// DO NOT MODIFY <<<<--- Until Here

#ifdef TEST_READDATA
// the input file is binary, storing integers
//
// arr stores the address of a pointer for storing the
// address of the allocated memory
//
// size stores the address keeping the size of the array
bool readData(char * filename, int * * arr, int * size)
{
  // use fopen to open the file for read
  // return false if fopen fails
  FILE * fptr = fopen(filename,"rb");
  if (fptr == NULL)
    {
      return false;
    }
  // use fseek to go to the end of the file
  // check whether fseek fails
  // if fseek fails, fclose and return false
  int numEnd = 0;
  numEnd = fseek(fptr,0,SEEK_END);
  if (numEnd == -1)
    {
      fclose(fptr);
      return false;
    }

  // use ftell to determine the size of the file
  *size = ftell(fptr)/sizeof(int);
  int numBeg = 0;
  numBeg = fseek(fptr,0,SEEK_SET);
  if(numBeg == -1)
    {
      fclose(fptr);
      return false;
    }
  // use fseek to go back to the beginning of the file
  // check whether fseek fails

  // if fseek fails, fclose and return false

  // the number of integers is the file's size divided by
  // size of int

  // allocate memory for the array
  *arr = malloc(sizeof(int*) * (*size));
  
  // if malloc fails, fclose and return false
  if (*arr == NULL)
    {
      fclose(fptr);
      return false;
    }

  // use fread to read the number of integers in the file
  int numRead = 0;
  numRead = fread(*arr,sizeof(int),*size,fptr);
  if (numRead != *size)
    {
      free(arr);
      fclose(fptr);
      return false;
    }

  // if fread does not read the correct number
  // release allocated memory
  // fclose
  // return false
 
  fclose(fptr);
  
  // if fread succeeds
  // close the file  
  // update the argument for the array address
  // update the size of the array
  
  return true;
}
#endif

#ifdef TEST_WRITEDATA
// the output file is binary, storing sorted integers
// write the array of integers to a file
// must use fwrite. must not use fprintf
bool writeData(char * filename, const int * arr, int size)
{
  // fopen for write
  //FILE * fptr = fopen(filename,"wb");
  FILE * fptr = fopen(filename,"wb");
  if (fptr == NULL)
    {
      printf("Error %d\n",errno);
      return false;
    }
  // if fopen fails, return false

  // use fwrite to write the entire array to a file
  int numWrite = 0;
  numWrite = fwrite(arr,sizeof(int),size,fptr);
  if(numWrite != size)
    {
      fclose(fptr);
      return false;
    }

  // check whether all elements of the array have been written

  // fclose
  fclose(fptr);

  // if not all elements have been written, return false
  
  // if all elements have been written, return true
  return true;
}
#endif


#ifdef TEST_MERGE
// input: arr is an array and its two parts arr[l..m] and arr[m+1..r]
// are already sorted
//
// output: arr is an array and all elements in arr[l..r] are sorted
//
// l, m, r mean left, middle, and right respectively
//
// You can assume that l <= m <= r.
//
// Do not worry about the elements in arr[0..l-1] or arr[r+1..]

static void merge(int * arr, int l, int m, int r)
// a static function can be called within this file only
// a static function is invisible to other files
{
  // at the beginning of the function
#ifdef DEBUG
  // Do not modify this part between #ifdef DEBUG and #endif
  // This part is used for grading. 
  printInput("Merge in", arr, l, m, r);
#endif

  // if one or both of the arrays are empty, do nothing

  if(l >= r)
    {
      return;
    }

  // Hint: you may consider to allocate memory here.
  // Allocating additiional memory makes this function easier to write

  // merge the two parts (each part is already sorted) of the array
  // into one sorted array
  int n1 = m-l+1;
  int n2 = r-m;

  int * L;
  int * M;

  int k;
  int i;
  int j;

  L = malloc(sizeof(int*) * n1);
  M = malloc(sizeof(int*) * n2);

  if (L == NULL || M == NULL)
    {
      return;
    }

  for(i=0; i < n1; i++)
    {
      L[i] = arr[l+i];
    }
  for(j=0; j < n2; j++)
    {
      M[j] = arr[m+j+1];
    }
  
  i =0;
  j= 0;
  k =l;
  
  while (i < n1 && j < n2)
  {
    if (L[i] <= M[j])
  	{
  	  arr[k] = L[i];
  	  i++;
  	}
    else
  	{
  	  arr[k] = M[j];
  	  j++;
  	}
    k++;
  }

  while (i < n1)
   {
    arr[k] = L[i];
    i++;
    k++;
  }
  
  while (j < n2)
  {
    arr[k] = M[j];
    j++;
    k++;
  }

  free(M);
  free(L);
  // the following should be at the bottom of the function
#ifdef DEBUG
  // Do not modify this part between #ifdef DEBUG and #endif
  // This part is used for grading. 
  printInput("Merge out", arr, l, m, r);
#endif
}
#endif

// merge sort has the following steps:

// 1. if the input array has one or no element, it is already sorted
// 2. break the input array into two arrays. Their sizes are the same,
//    or differ by one
// 3. send each array to the mergeSort function until the input array
//    is small enough (one or no element)
// 4. sort the two arrays 
#ifdef TEST_MERGESSORT
void mergeSort(int arr[], int l, int r) 
{
  // at the beginning of the function
#ifdef DEBUG
  // Do not modify this part between #ifdef DEBUG and #endif
  // This part is used for grading. 
  printInput("mergeSort", arr, l, r, -1);
#endif

  // if the array has no or one element, do nothing
  if(l < r)
    {
      int m = l+(r-l)/2;
      mergeSort(arr,l,m);
      mergeSort(arr,m+1,r);
      merge(arr,l,m,r);
    }
  return;

  // divide the array into two arrays
  // call mergeSort with each array
  // merge the two arrays into one
} 
#endif
