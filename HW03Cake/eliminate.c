// ***
// *** You MUST modify this file
// ***

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h> 
#include <string.h> 

#ifdef TEST_ELIMINATE
// 100% of the score
void eliminate(int n, int k)
{
  // allocate an arry of n elements
  int * arr = malloc(sizeof(* arr) * n);
  // check whether memory allocation succeeds.
  // if allocation fails, stop
  if (arr == NULL)
    {
      fprintf(stderr, "malloc fail\n");
      return;
    }
  // initialize all elements
  
  // counting to k,
  // mark the eliminated element
  // print the index of the marked element
  // repeat until only one element is unmarked

  int steps = k; //number of steps (movement) at each round
  int c; //elminition locator
  int i, r, j; //loops counters
                 // r= number of rounds
                // i = numbers generator
                // j = array organizer counter after each elimination
  
  steps = k; //number of steps at each round
  c = steps - 1; //number of steps over the index
  // generate numbers for each index at the array

  for (i = 0; i < n; i++)
    {
        arr[i] = i + 1;
    }

    // process of elimination
    for (r = n - 1; r > 0; r--)
    {
      printf("%d\n",arr[c]-1);
      arr[c] = 'X'; // Mark the eliminated space with 'X'
      // Remove X from the game (array)
      for (j = c; j < r; j++)
      {
          arr[j] = arr[j + 1];
      }

      c = c + steps - 1; // generate new locator

      while (c >= r)
      {
          c = c - r;
      }
    }
  // print the last one
    printf("%d\n",arr[c]-1);
  // release the memory of the array
  free (arr);
}
#endif
