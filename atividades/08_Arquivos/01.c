#include <stdio.h>
#include <stdlib.h>

FILE* openFile(char filename[]);

int main() {
    FILE *file = openFile("meufile");
    if (file == NULL)
        return 1;

    int num;

    for (int i = 0; i < 5; i++) {
        scanf("%d", &num);
        fwrite(&num, sizeof(int), 1, file);
    }
    
    //rewind(file); // Reposiciona o ponteiro para o início do arquivo.
    fclose(file);

    FILE *file2 = fopen("meufile", "rb");
    int nums[5];
    fread(nums, sizeof(int), 5, file2);

    for (int i = 0; i < 5; i++) {
        printf("%d \n", nums[i]);
    }

    fclose(file2);
    return 0;
}

FILE* openFile(char filename[]) {
    FILE *file;
    if ((file = fopen(filename, "rb+")) == NULL) {
        if ((file = fopen(filename, "wb+")) == NULL) {
            return NULL;
        }
    }
    return file;
}
