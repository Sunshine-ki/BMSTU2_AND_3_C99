#include "../headers/sentence.h"

word_s *creat_sentence()
{
	return (word_s *)malloc(sizeof(word_s));
}

void add_words(word_s *s, char word[MAX_LEN_WORD], int n, int j)
{
	if (s[n].words)
		s[n].words = (char **)realloc(s[n].words, sizeof(char *) * (j + 1));
	else
		s[n].words = (char **)malloc(sizeof(char *) * (j + 1));

	s[n].words[j] = (char *)malloc((strlen(word) + 1) * sizeof(char));

	strcpy(s[n].words[j], word);
}

int input_sentence(word_s **sp, FILE *f)
{
	char word[MAX_LEN_WORD];
	int n = 0;
	char c;

	word_s *s = *sp;

	for (int i = 0, j = 0;;)
	{
		if (feof(f))
		{
			if (i)
			{
				word[i - 1] = '\0';
				add_words(s, word, n, j);
				// printf("%s\n", word);
				s[n].count = j + 1;
				n++;
			}
			break;
		}

		fscanf(f, "%c", &c);

		if (c == '\n')
		{
			word[i] = '\0';
			add_words(s, word, n, j);
			// printf("%s\n", word);
			s[n].count = j + 1;
			j = 0;
			i = 0;
			n++;

			s = (word_s *)realloc(s, sizeof(word_s) * (n + 1));
			continue;
		}

		if (c == ' ')
		{
			word[i] = '\0';

			add_words(s, word, n, j);
			// printf("%s ", word);
			j++;
			i = 0;
			continue;
		}
		word[i] = c;
		// printf("n = %d i = %d j = %d c = %c\n", n, i, j, c);
		i++;
	}
	*sp = s;

	return n;
}

void print_struct(word_s *s, int n)
{
	printf("n = %d\n\n", n);
	for (int i = 0; i < n; i++)
	{
		// printf("%d ", s[i].count);
		for (int j = 0; j < s[i].count; j++)
			printf("%s ", s[i].words[j]);
		puts("");
	}
}