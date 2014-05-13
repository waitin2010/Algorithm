/* problem: 843 - crypt kicker */

/* n: the number of words 
 * no more than 1000 words 
 * no word exceeds 16 letters 
 * encrypted lines not exceed 80 characters 
 */

#include <stdio.h>
#include <string.h>

#define WORD_NUM 1000 + 1
#define WORD_LEN 16 + 1
#define SENTENCE_LEN  80 + 1

int n; /* the number of words */
char words[WORD_NUM][WORD_LEN];/* each word */
char sentence[SENTENCE_LEN];/* the encrypted line */

int main(){
  int i;
  scanf("%d",&n);
  for(i=0;i<n;i++)
    scanf("%s",words[i]);
  for(i=0;i<n;i++)
    printf("%s\n",words[i]);
  while(gets(sentence)!=NULL)
    puts(sentence);
  return 0;
}
