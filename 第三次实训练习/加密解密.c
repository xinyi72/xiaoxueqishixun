#include <stdio.h>
#include <stdlib.h>

// 加密函数：将文件每一位加指定值
void encryptFile(const char *inputFile, const char *outputFile, int shift) {
    FILE *fileIn = fopen(inputFile, "rb");
    if (fileIn == NULL) {
        perror("Error opening source file");
        return;
    }

    FILE *fileOut = fopen(outputFile, "wb");
    if (fileOut == NULL) {
        perror("Error opening target file");
        fclose(fileIn);
        return;
    }

    unsigned char buffer[1024];
    size_t bytes;

    while ((bytes = fread(buffer, 1, sizeof(buffer), fileIn)) > 0) {
        for (size_t i = 0; i < bytes; i++) {
            buffer[i] = (unsigned char)(buffer[i] + shift); // 加密：每一位加shift
        }
        fwrite(buffer, 1, bytes, fileOut);
    }

    printf("File encrypted successfully.\n");
    fclose(fileIn);
    fclose(fileOut);
}

// 解密函数：将文件每一位减指定值
void decryptFile(const char *inputFile, const char *outputFile, int shift) {
    FILE *fileIn = fopen(inputFile, "rb");
    if (fileIn == NULL) {
        perror("Error opening source file");
        return;
    }

    FILE *fileOut = fopen(outputFile, "wb");
    if (fileOut == NULL) {
        perror("Error opening target file");
        fclose(fileIn);
        return;
    }

    unsigned char buffer[1024];
    size_t bytes;

    while ((bytes = fread(buffer, 1, sizeof(buffer), fileIn)) > 0) {
        for (size_t i = 0; i < bytes; i++) {
            buffer[i] = (unsigned char)(buffer[i] - shift); // 解密：每一位减shift
        }
        fwrite(buffer, 1, bytes, fileOut);
    }

    printf("File decrypted successfully.\n");
    fclose(fileIn);
    fclose(fileOut);
}

int main() {
    const char *inputFile = "1.txt";
    const char *encryptedFile = "encrypted_1.png";
    const char *decryptedFile = "decrypted_1.png";
    int choice, shift;

    printf("选择你要干什么:\n1. 加密\n2. 解密\n");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("输入你要位移的数字:");
        scanf("%d", &shift);
        encryptFile(inputFile, encryptedFile, shift);
    } else if (choice == 2) {
        printf("输入你要位移的数字:");
        scanf("%d", &shift);
        decryptFile(encryptedFile, decryptedFile, shift);
    } else {
        printf("Invalid choice.\n");
    }

    return 0;
}
