#include <stdio.h>

#include <stdlib.h>

#include <stdbool.h>

#include <string.h>
/* Return true (non-zero) if c is a whitespace characer

   ('\t' or ' ').

   Zero terminators are not printable (therefore false) */
//true if on a space character
bool delim_character(char c){
  if (c == '\t' || c == ' ' || c == '\0')
    return true;
  return false;


}



/* Return true (non-zero) if c is a non-whitespace

   character (not tab or space).

   Zero terminators are not printable (therefore false) */
//false if on a space character
bool non_delim_character(char c){
  if (c == '\t' || c == ' ')
    return false;
  return true;


}



/* Returns a pointer to the first character of the next

   space-separated word*/

char *word_start(char* str){
  //loops through memory address until a non_delim_char is found and returns that memory address
  for (int i = 0; *(str+i) != '\0'; i++) {
    if (non_delim_character(*(str+i))) {
      return str+i;
    }
  }
}



/* Returns a pointer to the first space character of the zero

   terminated string*/

char *end_word(char* str){
  char *start = word_start(str);
  //after word_start, traverses through memory allocations until an delim_char is found
  for (int i = 0; *(start + i) != '\0'; i++) {
    if (delim_character(*(start + i + 1))) {
      return start + i;
    }
  }
}

// counts the number of words or tokens

int count_tokens(char* str){
  int counter = 0;
  //loops thrugh memory addresses and if a non_delim is before a delim_char, counter adds
  //and continues traversing until next non_delim, delim_char
  for (int i = 0; *(str + i) != '\0'; i++) {
    if (non_delim_character(*(str + i))) {
      if (delim_character(*(str + i + 1))) {
	counter++;
      }
    }
  }
  return counter;
}

/* Returns a freshly allocated zero-terminated vector of freshly allocated

   space-separated tokens from zero-terminated str.

   For example, tokenize("hello world string") would result in:

     tokens[0] = "hello"

     tokens[1] = "world"

     tokens[2] = "string"

     tokens[3] = 0

*/
//copies string and returns the copy
char *copy_str(char *inStr, short len){
  char *copy = (char *)malloc(len);
  for (int i = 0; i < len; i++) {
    *(copy + i) = *(inStr + i);
  }
  *(copy + len) = '\n';
  return copy;
}


//tokenizes string utilizing malloc to allocate memory
char** tokenize(char* str){
  char words = count_tokens(str) + 1;
  char **arr = (char **)malloc(sizeof(char *) * (words + 1));
  int i = 0;
  arr[i] = strtok(str, " ");
  for (i = 1; i < words; i++) {
    arr[i] = strtok(NULL, " ");
  }
  arr[i++] = '\0';
  return arr;
}

void print_all_tokens(char** tokens){
  for (int i = 0; **(tokens + i) != '\0'; i++) {
    printf("%s\n", **(tokens + i));
  }
}
int main() {
  char string[] = "hello test this is a longer string just to see what happens";
  print_all_tokens(tokenize(string));
}

