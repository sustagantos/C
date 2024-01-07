#ifndef _STRING_H_
#define _STRING_H_
#define MAX 20
#define SEPARATOR "\n______________________________"

typedef struct ELEMENT{
    char letter;
    struct ELEMENT *next;
}element;

typedef struct SENTENCE{
    element *first;
}sentence;

sentence* sentenceInit();
element* createElement(char digit);
void addToSentence(sentence *s, char digit);
void printSentence(sentence *s);
int sentenceSize(sentence *s);
void freeSentence(sentence *sent);
void copySentence(sentence *destination, sentence *source);
void concatenate(sentence *destination, sentence *first, sentence *second);

#endif