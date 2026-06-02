# XOR-encoder
A simple C encoder/decoder using XOR and a cyclic key

## How to compile

Open terminal in the project folder and run:
bash
gcc -o xor_crypter main.c

How to use
Run the program from terminal:
bash
./xor_crypter <input file> <output file> <key>

Examples
Encrypt a file:
bash
./xor_crypter secret.txt encrypted.bin mykey123
Decrypt it back:
bash
./xor_crypter encrypted.bin decrypted.txt mykey123
Show help
bash
./xor_crypter --help
Important notes

You can specify file paths in the input and output lines, but the paths must be enclosed in quotation marks.

· The key cannot be empty
· File paths and key must use only English letters/numbers
· Russian or other non-English characters will cause errors

License

MIT
