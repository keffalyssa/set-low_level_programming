unsigned int _strspn(char *s, char *accept)
{ unsigned int c=0; int i; while(*s){i=0; while(accept[i]&&accept[i]!=*s)i++; if(!accept[i])break; c++;s++;} return(c); }
