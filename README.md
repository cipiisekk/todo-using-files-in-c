# Simple todo list app
A command-line TODO application written in C that stores tasks in files and allows users to add, list, remove, and complete tasks.

<br>

## TODO LIST
- [ ] improve algorithm for saving data (it sucks)

<br>

## string utils

```c
void clearBuffer(void){
    char c;
    while((c = getchar()) != '\n' && c != EOF);
}

bool isSame(char* s1, char* s2){
    while(*s1 != '\0' && *s2 != '\0'){
        if(*s1 != *s2) return false;
        s1++;
        s2++;
    }
    if(*s1 != *s2) return false;
    return true;
}

void myLower(char* s){
    if (*s >= 'A' && *s <= 'Z'){
        *s-= 'a' - 'A';
    }
}
```


