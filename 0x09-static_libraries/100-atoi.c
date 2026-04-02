int _atoi(char *s)
{ int sign=1,r=0,st=0; while(*s){ if(*s=='-')sign*=-1; else if(*s>='0'&&*s<='9'){r=r*10+(*s-'0');st=1;} else if(st)break; s++;} return(sign*r); }
