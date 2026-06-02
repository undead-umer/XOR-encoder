#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc <  4 || (argc > 1 && strcmp(argv[1], "--help") == 0)) {
      printf("Usage: %s <input file> <output file> <key>\n", argv[0]);
      printf("Example: secret.txt encrypted.bin mykey123\n", argv[0]);
      printf("The key can by any");
    } 
    
    if(argc < 4) {
        printf("Enter the parameters");
        return 1;
    }
     char *key = argv[3];
     int key_len = strlen(key);
     if (key_len == 0) {
     printf("The key must not be empty");
     return 1;
     }

   FILE *fin = fopen(argv[1], "rb");
   FILE *fout = fopen(argv[2], "wb");
   if (fin == NULL) { printf("[ERROR] Couldn't open the file %s\n", argv[1]); return 1; } 
   if (fout == NULL) { printf("[ERROR] Couldn't create file"); return 1; }
   
    
    unsigned char buffer[4096];
    size_t  bytesRead;
    while ((bytesRead = fread(buffer, 1, sizeof(buffer), fin)) > 0)  {
      int key_len = strlen(key);
      for(size_t i = 0; i < bytesRead; i++) {
      buffer[i] = buffer[i] ^  key[i % key_len];      
      }
     fwrite(buffer, 1, bytesRead, fout);

    }
    

     



   fclose(fin);
   fclose(fout);


   return 0;

}