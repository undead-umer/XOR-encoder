#include <stdio.h>
#include <string.h>
// WARNING: This encoder is no longer a toy; it encrypts data and replaces it with old, unencrypted data.//

int main(int argc, char *argv[]) {
    if (argc < 2) {
    printf("Enter parameters");
       return 1;
    }
FILE *fin = fopen(argv[1], "rb+");
    if (fin == NULL) { printf("[ERROR] Couldn't open this file %s\n", argv[1]); return 1; }

    char *key = argv[2];
     int key_len = strlen(key);

    unsigned char buffer[4096];
    size_t bytesRead;
    while ((bytesRead = fread(buffer, 1, sizeof(buffer), fin)) > 0)  {
       for(size_t i = 0; i < bytesRead; i++) {
       buffer[i] ^= key[i % key_len];
       }
       fseek(fin, -bytesRead, SEEK_CUR);
       fwrite(buffer, 1, bytesRead, fin);
       fseek(fin, 0, SEEK_CUR);
    }

    fclose(fin);

    return 0;
}