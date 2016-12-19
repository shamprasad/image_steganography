#include <stdio.h>
#include <time.h>
#include<stdlib.h>
#include <string.h>
#include "md5.c"
static void MDPrint PROTO_LIST ((unsigned char [16]));
static void MDString (char *string,unsigned char key[16])

{
  MD5_CTX context;
  unsigned char digest[16];
  unsigned int len = strlen (string);

  MD5Init (&context);
  MD5Update (&context, string, len);
  MD5Final (digest, &context);

  
  MDPrint (digest,key);
  
}

static void MDPrint (unsigned char digest[16],unsigned char key[16])

{
  unsigned int i;

  for (i = 0; i < 16; i++)
 key[i] = digest[i];
}



