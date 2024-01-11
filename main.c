#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Constants
#define MAX_NAME_LENGTH 50
#define MAX_FILES 100
#define MAX_CONTENT_LENGTH 100

// File structure
typedef struct {
    char name[MAX_NAME_LENGTH];
    char content[MAX_CONTENT_LENGTH];
} File;

// Directory structure
typedef struct {
    char name[MAX_NAME_LENGTH];
    int file_count;
    File files[MAX_FILES];
} Directory;

// Filesystem structure
typedef struct {
    int dir_count;
    Directory directories[MAX_FILES];
} FileSystem;

File createFile(const char* name, const char* content)
{
    File newFile;
    strncpy(newFile.name, name, MAX_NAME_LENGTH-1);
    strncpy(newFile.content, content, MAX_NAME_LENGTH-1);
    return newFile;
}
Directory createDirectory(const char* name) {
    Directory newDir;
    strncpy(newDir.name, name, MAX_NAME_LENGTH - 1);
    newDir.file_count = 0;
    return newDir;
}
void addFileToDirectory(Directory* dir, const File* file) {
    if (dir->file_count < MAX_FILES) {
        dir->files[dir->file_count++] = *file;
    } else {
        printf("Directory is full, cannot add more files.\n");
    }
}

// Function to display the content of a file
// void displayFileContent(const File* file) {
//     printf("File Name: %s\n", file->name);
//     printf("Content: %s\n", file->content);
// }

// Function to display the files in a directory
void displayDirectoryContents(const Directory* dir) {
    printf("%s\n", dir->name);
    for (int i = 0; i < dir->file_count; ++i) {
        printf("        ");

        printf("%s",dir->files[i].name);
        printf("\n");
    }
}
// Function to display the filesystem contents
void displayFilesystemContents(const FileSystem* fs) {
    printf("Filesystem Contents:\n");
    for (int i = 0; i < fs->dir_count; ++i) {
        printf("    ");
        displayDirectoryContents(&fs->directories[i]);
        printf("\n");
    }
}

int main(){
    FileSystem filesystem;
    filesystem.dir_count = 0;

    // Create directories
    Directory dir1 = createDirectory("Folder1");
    Directory dir2 = createDirectory("Folder2");

    // Create files
    File file1 = createFile("File1.txt", "This is the content of File1.");
    File file2 = createFile("File2.txt", "Content of File2 goes here.");

    // Add files to directories
    addFileToDirectory(&dir1, &file1);
    addFileToDirectory(&dir2, &file2);
    addFileToDirectory(&dir1, &file1);
    addFileToDirectory(&dir2, &file2);

    addFileToDirectory(&dir1, &file1);
    addFileToDirectory(&dir2, &file2);
    addFileToDirectory(&dir1, &file1);
    addFileToDirectory(&dir2, &file2);

    // Add directories to the filesystem
    filesystem.directories[filesystem.dir_count++] = dir1;
    filesystem.directories[filesystem.dir_count++] = dir2;

    // Display filesystem contents
    displayFilesystemContents(&filesystem);
    return 0;
}