#include <stdio.h>

#define OK 0
#define ERROR_OPEN -1
#define ERROR_EMPTY -2
#define TRUE 1
#define FALSE 0
#define ONE 1
#define ZERO 0
#define ERROR -1
#define NO_SOLUTIONS -3


int process(FILE *const f, int *const len)
{
    if (!f)
        return ERROR_OPEN;

    int num_pred;

    if (fscanf(f, "%d ", &num_pred) != TRUE)
        return ERROR_EMPTY;

    int len_positive_sequence = ONE;
    int max_positive_sequence = ONE;

    int len_negative_sequence = ONE;
    int max_negative_sequence = ONE;

    int flag = FALSE;
    int num, count = 1;

    // fseek(f, 0, SEEK_SET);

    while (fscanf(f, "%d ", &num) == TRUE)
    {
        if (num_pred > num)
        {
            len_positive_sequence = ONE;
            len_negative_sequence++;
            flag = TRUE;
        }
        else if (num_pred < num)
        {
            len_negative_sequence = ONE;
            len_positive_sequence++;
            flag = TRUE;
        }
        if (max_negative_sequence < len_negative_sequence)
            max_negative_sequence = len_negative_sequence;
        if (max_positive_sequence < len_positive_sequence)
            max_positive_sequence = len_positive_sequence;
        num_pred = num;
        count++;
    }
    if (!flag)
        max_negative_sequence = max_positive_sequence = ZERO;
    *len = max_negative_sequence > max_positive_sequence ?
        max_negative_sequence : max_positive_sequence;

    if (count == ONE)
        return NO_SOLUTIONS;

    return OK;
}

int main(void)
{
    setbuf(stdout, NULL);

    int len;

    const int err = process(stdin, &len);

    if (err)
        return err;

    printf("\nMaximum len sequence: %d\n", len);

    return OK;
}
