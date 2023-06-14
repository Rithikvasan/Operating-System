#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>



int main() {
    char filename[500];
    char data [ MAX_SIZE];

    printf("Enter the filename: ");
    scanf("%s", filename);

    // Create a file using system call
    int fileDescriptor = open(filename, O_CREAT | O_WRONLY, 0644);

    if (fileDescriptor == -1) {
        perror("Error creating the file");
        exit(1);
    }

    // Get the data from the user
    printf("Enter the data: ");
    scanf(" %[^\n]", data);

    // Write the data to the file
    if (write(fileDescriptor, data, sizeof(data)) == -1) {
        perror("Error writing to the file");
        exit(1);
    }

    // Close the file
    close(fileDescriptor);

    // Open the file in read mode
    fileDescriptor = open(filename, O_RDONLY);

    if (fileDescriptor == -1) {
        perror("Error opening the file");
        exit(1);
    }
    char fileData[MAX_SIZE];
    ssize_t bytesRead = read(fileDescriptor, fileData, sizeof(fileData));

    if (bytesRead == -1) {
        perror("Error reading from the file");
        exit(1);
    }

    // Print the data read from the file
    printf("Data from the file:\n");
    printf("%s\n", fileData);

    // Close the file
    close(fileDescriptor);

    return 0;
}

