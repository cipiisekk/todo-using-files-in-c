# Simple todo list app
A command-line TODO application written in C that stores tasks in files and allows users to add, list, remove, and complete tasks.
<br>

<img width="284" height="678.5" alt="image" src="https://github.com/user-attachments/assets/285285f3-7167-4c8c-a5d7-88379302ff43" />



<br>

## TODO LIST
- [ ] improve algorithm for saving data (it sucks)
- [ ] make possible to type spaces in input for item name

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



