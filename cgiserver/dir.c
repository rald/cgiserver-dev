#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>

#define MAX_ENTRIES 1024

// Struct to store entries
typedef struct {
    char name[256];
} Entry;

int is_hidden(const char *name) {
    return name[0] == '.';
}

int main() {
    DIR *d;
    struct dirent *dir;
    struct stat st;
    Entry folders[MAX_ENTRIES];
    Entry files[MAX_ENTRIES];
    int folder_count = 0, file_count = 0;

    d = opendir(".");
    if (!d) {
        perror("opendir");
        return 1;
    }

    while ((dir = readdir(d)) != NULL) {
        if (is_hidden(dir->d_name))
            continue;

        if (stat(dir->d_name, &st) == -1) {
            perror("stat");
            continue;
        }

        if (S_ISDIR(st.st_mode)) {
            if (folder_count < MAX_ENTRIES) {
                strncpy(folders[folder_count].name, dir->d_name, sizeof(folders[folder_count].name)-1);
                folders[folder_count].name[sizeof(folders[folder_count].name)-1] = '\0';
                folder_count++;
            }
        } else {
            if (file_count < MAX_ENTRIES) {
                strncpy(files[file_count].name, dir->d_name, sizeof(files[file_count].name)-1);
                files[file_count].name[sizeof(files[file_count].name)-1] = '\0';
                file_count++;
            }
        }
    }

    closedir(d);

    for (int i = 0; i < folder_count; i++) {
        printf("<%s>\n", folders[i].name);
    }

    for (int i = 0; i < file_count; i++) {
        printf("%s\n", files[i].name);
    }

    return 0;
}
