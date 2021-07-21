#include "extractor.h"

void init_string(string *s) {
    s->len = 0;
    s->ptr = malloc(s->len+1);
    if (s->ptr == NULL) {
        fprintf(stderr, "malloc failed\n");
        exit(EXIT_FAILURE);
    }
    s->ptr[0] = '\0';
}

size_t writefunc(void *ptr, size_t size, size_t nmemb, string *s) {
    size_t new_len = s->len + size*nmemb;
    s->ptr = realloc(s->ptr, new_len+1);
    if (s->ptr == NULL) {
        fprintf(stderr, "realloc failed\n");
        exit(EXIT_FAILURE);
    }
    memcpy(s->ptr+s->len, ptr, size*nmemb);
    s->ptr[new_len] = '\0';
    s->len = new_len;

    return size*nmemb;
}

void parse(char* html, char** part, const char* starts_with, const char* ends_with) {
    char *start, *end;
    if ((start = strstr(html, starts_with))) {
        start += strlen(starts_with);
        if ((end = strstr(start, ends_with))) {
            (*part) = malloc(end - start + 1);
            memcpy(*part, start, end - start);
            part[0][end - start] = '\0';
        }
    }
}

char * my_strcatt(char *s1, const char *s2)
{
    const size_t a = strlen(s1);
    const size_t b = strlen(s2);
    const size_t size_ab = a + b + 1;

    s1 = realloc(s1, size_ab);

    memcpy(s1 + a, s2, b + 1);

    return s1;
}

void metadata(char* html, char** meta) {
    (*meta) = malloc(strlen("{\"metadata\":{") + 1);
    strcpy((*meta), "{\"metadata\":{");
    char *start = html, *end, *data, *name = NULL, *value = NULL;
    char isFirst = 1;
    while ((start = strstr(start, "<meta")) != NULL) {
        if ((end = strstr(start, ">"))) {
            start += strlen("<meta");
            data = malloc(end - start + 1);
            memcpy(data, start, end - start );
            data[end - start] = '\0';
            parse(data, &name, "name=\"", "\"");
            if (name == NULL) {
                parse(data, &name, "property=\"", "\"");
            }
            parse(data, &value, "content=\"", "\"");
            if (name != NULL && value != NULL) {
                if (isFirst == 0) {
                    (*meta) = my_strcatt((*meta), ",\"%s");
                } else {
                    (*meta) = my_strcatt((*meta), "\"%s");
                }
                (*meta) = my_strcatt((*meta), name);
                (*meta) = my_strcatt((*meta), "\":\"");
                (*meta) = my_strcatt((*meta), value);
                (*meta) = my_strcatt((*meta), "\"");
                isFirst = 0;
                free(name);
                name = NULL;
                free(value);
                value = NULL;
            }
            free(data);
        } else {
            start += strlen("<meta");
        }
    }
    (*meta) = my_strcatt((*meta), "}}");
}

char* extract(const char* url) {
    char *head = NULL;
    CURL *curl;
    curl = curl_easy_init();
    if(curl) {
        char* meta = NULL;
        string s;
        init_string(&s);
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writefunc);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &s);
        curl_easy_perform(curl);
        if (s.ptr[0] != '\0') {
            parse(s.ptr, &head, "<head>", "</head>");
            metadata(head, &meta);
        } else {
            meta = malloc(sizeof(char)*3);
            strcpy(meta, "{}");
        }
        free(s.ptr);
        free(head);
        curl_easy_cleanup(curl);
        return meta;
    }
    return NULL;
}

int main(int argc, char **argv) {
    char* metadata = extract(argv[1]);
    printf("%s\n", metadata);
    free(metadata);
    return 0;
}
