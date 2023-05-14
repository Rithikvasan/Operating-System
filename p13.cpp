#include <stdio.h>
#include <string.h>

#define MAX_FILES 10
#define MAX_FILE_NAME 20
#define MAX_DIR_NAME 20

typedef struct {
    char name[MAX_FILE_NAME];
    int size;
} File;

typedef struct {
    char name[MAX_DIR_NAME];
    int num_files;
    File files[MAX_FILES];
} Directory;

void addFile(Directory *dir) {
    if (dir->num_files == MAX_FILES) {
        printf("Cannot add more files to directory '%s'.\n", dir->name);
        return;
    }

    File file;
    printf("Enter file name: ");
    scanf("%s", file.name);
    printf("Enter file size: ");
    scanf("%d", &file.size);

    dir->files[dir->num_files++] = file;

    printf("File '%s' added to directory '%s'.\n", file.name, dir->name);
}

void displayFiles(Directory *dir) {
    printf("Files in directory '%s':\n", dir->name);
    if (dir->num_files == 0) {
        printf("No files found.\n");
        return;
    }

    for (int i = 0; i < dir->num_files; i++) {
        printf("%s\t%d KB\n", dir->files[i].name, dir->files[i].size);
    }
}

int main() {
    Directory dir;
    strcpy(dir.name, "CSE");
    dir.num_files = 0;

    printf("Directory '%s' created.\n", dir.name);

    addFile(&dir); // Add file A
    addFile(&dir); // Add file B
    addFile(&dir); // Add file C

    displayFiles(&dir); // Display all files in directory

    return 0;
}

