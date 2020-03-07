#include "headers/binary_matrix.h"
#include "headers/unique_words.h"
#include "headers/sentence.h"
#include "headers/const.h"
#include "headers/find_max.h"

int main(const int argc, const char **const argv)
{
    word_s unique_words = {NULL, 0};
    word_s *s = creat_sentence();

    FILE *f_in = fopen(argv[FILE_NAME_IN], MODE_READ);

    int n = input_sentence(&s, f_in); // Кол-во предложений.

    unique_words.words = create_unique_words();
    input_unique(&unique_words, s, n);

    qsort(unique_words.words, unique_words.count, sizeof(char **), comp1);
    int **binary_matrix = create_binary_matrix(n);
    input_binary_matrix(binary_matrix, unique_words, s, n);

    // print_unique_words(unique_words);
    // print_struct(s, n);

    FILE *f_out = fopen(FILE_NAME_OUT, MODE_WRITE);
    print_matrix(f_out, binary_matrix, n, unique_words.count);

    find_two_max_sentence(s, binary_matrix, unique_words.count, n);

    fclose(f_in);
    fclose(f_out);

    return OK;
}
