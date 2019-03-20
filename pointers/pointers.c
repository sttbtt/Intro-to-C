#include <stdio.h>

/*
    Given a character pointer x (that points to an array of chars), and a
    character pointer y, copies the character contents of y over to x. Pointer
    arithmetic is necessary here. Also, make sure x points to a null terminator
    at its end to terminate it properly. 

    Example call:

    char buffer[1024];

    string_copy(buffer, "Hello!");
    printf("%s", buffer); // Prints "Hello!"
*/
void string_copy(char *x, char *y)
{
    int i = 0;
    while (y[i] != '\0') {
        x[i] = y[i];
        i++;
    }
}

/*
    Searches the input string `str` for the first instance of the 
    character `c` (an unsigned char). This function returns a pointer
    that points to the first instance of the character `c` in the
    input string `str`.

    Do not use the `strchr` function from the standard library.
*/
char *find_char(char *str, int c)
{
    while (*str != '\0')
    {
    if (*str == c) {
      return str;
    }
    str++;
    }
    return NULL;
}

/*
    Searches the input string `haystack` for the first instance of
    the string `needle`. This function returns a pointer that points
    to the first instance of the string `needle` in the input
    string `haystack`. 

    Do not use the `strstr` function from the standard library.
*/
char *find_string(char *haystack, char *needle)
{
  int count = 0;
  
  while (*haystack != '\0')
  {
    if (*haystack == *needle) {
      for (int i = 0; i < (int)strlen(needle); i++)
      {
        if (haystack[i] == '\0') {
            return NULL;
        }
        if (haystack[i] == needle[i]) {
          count++;
        }
//        printf("%c", haystack[i]);
        if (count == (int)strlen(needle)) {
          return haystack;
        }
      }
      
    }
    haystack++;
  }

  return NULL;
  
}

#ifndef TESTING
int main(void)
{
    char* hello = "hello";
    char* world = "world";
    char *found_char = find_char(hello, 'e');
    char *found_string = find_string(world, "or");

    printf("Found char: %s\n", found_char);
    printf("Found string: %s\n", found_string);

    return 0;
}
#endif
