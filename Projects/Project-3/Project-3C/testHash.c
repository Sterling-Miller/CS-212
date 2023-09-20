/* 
Tests project3C_hastable.c

NOTE FOR STUDENTS: To use please compile with: 
gcc -W -Wall -g testHash.c project3C_hashtable.c

To know if your ouput is correct run the executable and you should
get no output and no ERROR messages. Its fine if you have memory leaks
*/

#include "project3C_hashtable.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

int main()
{
  // Create a new hash table
  HashTable *ht = (HashTable *)malloc(sizeof(HashTable));
  if (ht == NULL)
  {
    fprintf(stderr, "Failed to allocate memory for hash table.\n");
    return 1;
  }
  
  // TEST INITALIZE HASH
  initialize(ht);

  if(ht->count != 0){
  	fprintf(stderr, "ERROR in initalize: count not initalized correctly\n");
  }
  for(int i = 0; i < BUCKET_SIZE; i++){
  	if(ht->bucket[i] != NULL){
  		fprintf(stderr, "ERROR in initalize: The hashtable array indexes are all not set to null\n");
  	}
  }

  // TEST HASH
  unsigned int hashVal = hash("blue");
  if(hashVal != 34){
  	fprintf(stderr, "ERROR in hash: hash(\"blue\") != 34\n");
  }

  hashVal = hash("tangerine");
  if(hashVal != 13){
  	fprintf(stderr, "ERROR in hash: hash(\"tangerine\") != 13\n");
  }
  hashVal = hash("celadon");
  if(hashVal != 0){
  	fprintf(stderr, "ERROR in hash: hash(\"celadon\") != 0\n");
  }


  // TEST INSERT
  insert(ht, "blue", 1);
  insert(ht, "tangerine", 2);
  insert(ht, "tangerine", 3); // dup key
  insert(ht, "celadon", 4);

  if(!ht->bucket[34] || ht->bucket[34]->value != 1 || strcmp("blue", ht->bucket[34]->key) != 0){
  	fprintf(stderr, "ERROR in insert: insert(ht, \"blue\", 1) did not work\n");
  }

  if(!ht->bucket[13] || ht->bucket[13]->value != 2 || strcmp("tangerine", ht->bucket[13]->key) != 0){
  	fprintf(stderr, "ERROR in insert: insert(ht, \"tangerine\", 2) did not work\n");
  }

  if(!ht->bucket[13] || !ht->bucket[13]->next || ht->bucket[13]->next->value != 3
      || strcmp("tangerine", ht->bucket[13]->next->key) != 0){
  	fprintf(stderr, "ERROR in insert: insert(ht, \"tangerine\", 3) did not work\n");
  }

  if(!ht->bucket[0] || ht->bucket[0]->value != 4 || strcmp("celadon", ht->bucket[0]->key) != 0){
  	fprintf(stderr, "ERROR in insert: insert(ht, \"celadon\", 4) did not work\n");
  }
  
  // Test the get function
  int *results = NULL;
  int count = 0;
  get(ht, "tangerine", &results, &count);
  
  if(count == 2){
  	if(!results || results[0] != 2 || results[1] != 3){
  		fprintf(stderr, "ERROR in get: get(ht, \"tangerine\", ...) results is not set right\n");
  	}
  }
  else{
  	fprintf(stderr, "ERROR in get: get(ht, \"tangerine\", ...) number of results incorrect\n");
  }

  if(results != NULL){
    free(results);
  }

  // Clean up results array
  results = NULL;
  count = 0;

  get(ht, "blue", &results, &count);
  
  if (count != 1 || !results || results[0] != 1)
  {
    fprintf(stderr, "ERROR in get: get(ht, \"blue\", ...) either does not set results or count right\n" );
  }

  if(results != NULL){
    free(results);
  }

  // Try to get a non-existing key
  results = NULL;
  count = 0;

  get(ht, "hehe", &results, &count);
  if(count != 0 || results != NULL){
    fprintf(stderr, "ERROR in get: get(ht, \"hehe\", ...) get does not work for non-existing key\n" );
  }


  // Test the load factor calculation
  float loadFactor = calculateLoadFactor(ht);
  if(! (loadFactor > 0.039 && loadFactor < 0.41)){
    fprintf(stderr, "ERROR in loadFactor: %f != 0.04. Rounding by the way\n", loadFactor);
  }
  //printf("Load factor of the hash table: %.2f\n", loadFactor);

  // Free the hash table
  freeHashTable(ht);
  //free(ht);
  
  return 0;
}