#include <stddef.h>
#include <stdio.h>
int main(){
    FILE *file = fopen("hello.txt", "rb");

    if (file == NULL) {
        printf("could not open the file");
        return 1;
    }

    unsigned char buffer[10];
    size_t bytes_read;
    size_t offset = 0;

    while (1) {

    bytes_read = fread(buffer, 1, sizeof(buffer), file);

    if (bytes_read == 0) {
        break;
    }

    printf("OFFSET: %08zX ", offset);
    for (size_t i = 0; i < bytes_read; i++ ) {
        printf("%02x ",buffer[i]);
    }

    for (size_t j = bytes_read;  j < sizeof(buffer);j++) {
        printf("   ");
    }

    printf(" ");
    for (size_t i = 0; i < bytes_read; i++ ) {
        if (buffer[i] >= 32 && buffer[i] <=126) {
            printf("%c",buffer[i]);
        }else {
        printf(".");
        }
        }

    printf("\n");
    offset += bytes_read;
    }


    fclose(file);
    return 0;
}
