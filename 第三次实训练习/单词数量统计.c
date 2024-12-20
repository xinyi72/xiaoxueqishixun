#include <stdio.h>
#include <ctype.h>

// 统计文件中的单词数量
int countWordsInFile(const char *filename) {
    // 打开文件以读取
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Failed to open this file!");
        return 1;
    }

    // 用来标记当前是否处于一个单词中
    int inWord = 0;
    // 用来统计单词数量
    int Count = 0;
    // 用于存储从文件中读取的字符
    char ch;

    // 读取文件中的每个字符，直到文件结束 (EOF)
    while ((ch = fgetc(file)) != EOF) {
        // 如果当前字符是空白字符（空格、换行、制表符等）
        if (isspace(ch)) {
            // 设置 inWord 为 0，表示当前不在一个单词中
            inWord = 0;
        } else if (inWord == 0) {
            // 如果当前不在单词中，表示遇到一个新单词的开始
            inWord = 1;  // 进入单词状态
            Count++;      // 增加单词计数
        }
    }

    // 关闭文件
    fclose(file);
    // 返回单词计数
    return Count;
}

int main() {
    // 指定文件名
    char *filename = "单词.txt";
    // 调用 countWordsInFile 函数获取文件中的单词数
    int Count = countWordsInFile(filename);

    // 如果文件成功读取且没有错误
    if (Count >= 0) {
        // 打印文件中的单词数
        printf("文件 '%s' 中的单词数量: %d\n", filename, Count);
    }

    return 0;
}
