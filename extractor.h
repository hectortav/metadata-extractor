#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

typedef struct {
  char *ptr;
  size_t len;
} string;

void init_string(string *s);
size_t writefunc(void *ptr, size_t size, size_t nmemb, string *s);
void parse(char* html, char** part, const char* starts_with, const char* ends_with);
void metadata(char* html);