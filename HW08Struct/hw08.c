// ***
// *** You must modify this file
// ***
#include <stdio.h>  
#include <stdlib.h> 
#include <string.h> 
#include <stdbool.h>
#include "hw08.h"


#ifdef TEST_COUNTVECTOR
int countVector(char * filename)
{
  // count the number of vectors in the file and return the number
  int numElem=0;
  Vector * vecArr;
  FILE * fptr = fopen(filename,"r");
  if (fptr == NULL)
    {
      return -1;
    }
  // The input is a binary file. You must use fread.
  // You must not use fscanf(, "%d", ) 
  //
  // If fopen fails, return -1
  //
  fseek(fptr, 0,SEEK_END); // seek to end of file
  int size = ftell(fptr)/sizeof(Vector);
  vecArr = malloc(sizeof(* vecArr) * size);
  fseek(fptr, 0L, SEEK_SET);
  numElem = fread(vecArr, sizeof(* vecArr), size,fptr);
  //
  fclose(fptr);
  free(vecArr);
  return numElem;
  // For the mode of fopen, you may use "r" without b
  //
}
#endif

#ifdef TEST_READVECTOR
bool readVector(char* filename, Vector * vecArr, int size)
{
  // if fopen fails, return false
  FILE * fptr = fopen(filename,"rb");
  if (fptr == NULL)
    {
      return false;
    }
  // read Vectors from the file.
  //
  int numRead = 0;
  numRead = fread(&vecArr[0], sizeof(* vecArr), size, fptr);
  if (numRead != size)
    {
      return false;
    }
  //
  // if the number of integers is different from size (too
  // few or too many) return false
  // 
  // if everything is fine, fclose and return true
  fclose(fptr);
  return true;

}
#endif

#ifdef TEST_COMPAREVECTOR
int compareVector(const void *a, const void *b)
{
  // compare the x attribute first
  // If the first vector's x is less than the second vector's x
  // return -1

  const Vector *p1 = a, *p2 = b;
  //const coordinates *a1 = *(const coordinates **)a;
  if ((p1->x) < (p2->x))
    {
      return -1;
    }
  // If the first vector's x is greater than the second vector's x
  // return 1
  if ((p1->x) > (p2->x))
    {
      return 1;
    }
  // If the two vectors' x is the same, compare the y attribute
  else
    {
      if ((p1->y) < (p2->y))
	{
	  return -1;
	}
      if ((p1->y) > (p2->y))
	{
	  return 1;
	}
      else
	{
	  if ((p1->z) < (p2->z))
	    {
	      return -1;
	    }
	  if ((p1->z) > (p2->z))
	    {
	      return 1;
	    }
	  else
	    {
	      return 0;
	    }
	}
    }
  return 0;
  //
  // If the first vector's y is less than the second vector's y
  // return -1
  // If the first vector's y is greater than the second vector's y
  // return 1
  // If the two vectors' y is the same, compare the z attribute
  //
  // If the first vector's z is less than the second vector's z
  // return -1
  // If the first vector's z is greater than the second vector's z
  // return 1
  // If the two vectors' x, y, z are the same (pairwise), return 0
}
#endif

#ifdef TEST_WRITEVECTOR
bool writeVector(char* filename, Vector * vecArr, int size)
{
  // if fopen fails, return false
  FILE * fptr = fopen(filename,"wb");
  if (fptr == NULL)
    {
      return false;
    }
  // write the array to file using fwrite
  // need to check how many have been written
  // if not all are written, fclose and return false
  int numWrite = 0;
  fseek(fptr,0,SEEK_SET);
  numWrite = fwrite(vecArr,sizeof(Vector),size,fptr);
  if(numWrite != size)
    {
      fclose(fptr);
      return false;
    }
  // 
  // fclose and return true
  fclose(fptr);
  return true;
}
#endif

// This function is provided to you. No need to change
void printVector(Vector * vecArr, int size)
{
  int ind = 0;
  for (ind = 0; ind < size; ind ++)
    {
      printf("%6d %6d %6d\n",
	     vecArr[ind].x, vecArr[ind].y, vecArr[ind].z);
    }
}
