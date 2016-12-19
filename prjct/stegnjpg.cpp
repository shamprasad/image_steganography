#include<stdio.h> 
#include<stdlib.h> 
#include<unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<string.h>
#define CREATOR "yespee_4444@hotmail.com" 
#define RGB_COMPONENT_COLOR 255 
int count = 0;
char buf[513];
unsigned char bit8[32];
typedef struct 
{
unsigned char red, green, blue;
} PPMPixel;
typedef struct 
{
int x, y;
   
PPMPixel * data;
} PPMImage;
void 
loadbit8 (char h,int offset) 
{
unsigned char k;
int i;
unsigned char j = 0x80;
for (i = sizeof (char) * 8; i > 0; i--)
    {
k = h & j;
k = k >> (i - 1);
bit8[offset+(sizeof (char) * 8 - i)] = k;
j = j >> 1;
} 
} 
static PPMImage *

readPPM (const char *filename) 
{
 char buff[16];
 
PPMImage * img;
 
FILE * fp; 
 
int c, rgb_comp_color;
      //open PPM file for reading 
    fp = fopen (filename, "rb");
  
if (!fp)
        {
      
fprintf (stderr, "Unable to open file '%s'\n", filename);  
exit (1);
}
  
    if (!fgets (buff, sizeof (buff), fp))
    {
      
perror (filename);
exit (1);
    
}
  
    if (buff[0] != 'P' || buff[1] != '6')
    {
fprintf (stderr, "Invalid image format (must be 'P6')\n");
exit (1);
    
}
  
 
//alloc memory form image 
    img = (PPMImage *) malloc (sizeof (PPMImage));
if (!img)
    {
      
fprintf (stderr, "Unable to allocate memory\n");
exit (1);
    
}
  
    c = getc (fp);
  
while (c == '#')
    
    {
      
 
while (getc (fp) != '\n');
c = getc (fp);
}
  
ungetc (c, fp);
    if (fscanf (fp, "%d %d", &img->x, &img->y) != 2)
   
    {
fprintf (stderr, "Invalid image size (error loading '%s')\n",filename);
      
exit (1);
}
  
    if (fscanf (fp, "%d", &rgb_comp_color) != 1)
    {
fprintf (stderr,"Invalid rgb component (error loading '%s')\n",filename);
exit (1);
}
    if (rgb_comp_color != RGB_COMPONENT_COLOR)
    {
      
fprintf (stderr, "'%s' does not have 8-bits components\n",filename);
      
exit (1);
}
  
while (fgetc (fp) != '\n');
    img->data = (PPMPixel *) malloc (img->x * img->y * sizeof (PPMPixel));
if (!img)
    
    {
fprintf (stderr, "Unable to allocate memory\n");
      
exit (1);
    
}
  
    if (fread (img->data, 3 * img->x, img->y, fp) != img->y)
    {
fprintf (stderr, "Error loading image '%s'\n", filename);
      
exit (1);
    
}
fclose (fp);
return img;

}
void 
writePPM (const char *filename, PPMImage * img) 
{
  
FILE * fp;
    fp = fopen (filename, "wb");
  
if (!fp)
    
    {
      
fprintf (stderr, "Unable to open file '%s'\n", filename);
exit (1);
    
}
    fprintf (fp, "P6\n");
    fprintf (fp, "# Created by %s\n", CREATOR);
    fprintf (fp, "%d %d\n", img->x, img->y);
    fprintf (fp, "%d\n", RGB_COMPONENT_COLOR);
    fwrite (img->data, 3 * img->x, img->y, fp);
fclose (fp);
}

 unsigned char decode(unsigned char temp,int bcount)
{
unsigned char n2 = 0x00,n3 = 0x00,temp2 = temp,k = 0x01;
n2 = (temp & 0x01) ^ ((temp & 0x02) >> 1);
n3 = (temp & 0x01) ^ ((temp & 0x08) >> 3);
while((n2 != bit8[bcount]) || (n3 != bit8[bcount+1]))
{
temp2 = temp ^ k;
n2 = (temp2 & 0x01) ^ ((temp2 & 0x02) >> 1);
n3 = (temp2 & 0x01) ^ ((temp2 & 0x08) >> 3);
k = k << 1;
}
temp = temp2;
return temp;


}
 
 
void 
changeColorPPM (PPMImage * img, int fd,off_t fsize,char fname[20]) 
{
  
 
int i=0, j=0,k=0,n,bitcount = 0;
  off_t temp = 1; 
 
 
if (img)
    
 
    {
for(int offtcount = 0 ; offtcount < sizeof(off_t)*8;offtcount++)
{
bit8[offtcount] = (unsigned char)((fsize & temp) >> offtcount);
temp = temp << 1;
}

for(bitcount = 0; bitcount < 32; bitcount += 2){
img->data[i * img->x + j].red = decode(img->data[i * img->x + j].red,bitcount);bitcount += 2;
if(bitcount == 32) break;
img->data[i * img->x + j].green = decode(img->data[i * img->x + j].green,bitcount);bitcount += 2;
img->data[i * img->x + j].blue = decode(img->data[i * img->x + j].blue,bitcount);
j++;
}

j = 6;
for(k = 0; fname[k] != '\0';k++)
buf[k] = fname[k];
buf[k] = '\0';

for (int m = 0;buf[m] != '\0';m++)
{
loadbit8(buf[m],0);
     
img->data[i * img->x + j].red = decode(img->data[i * img->x + j].red,bitcount);bitcount += 2;
img->data[i * img->x + j].green = decode(img->data[i * img->x + j].green,bitcount);bitcount += 2;
img->data[i * img->x + j].blue &= 0xfe;
j++;
if(j >= img->x)
{
i++;
j = 0;
}
img->data[i * img->x + j].red = decode(img->data[i * img->x + j].red,bitcount);bitcount += 2;
img->data[i * img->x + j].green = decode(img->data[i * img->x + j].green,bitcount);bitcount += 2;
img->data[i * img->x + j].blue &= 0xfe;
j++;
if(j >= img->x)
{
i++;
j = 0;
}
bitcount = 0;
}
j--;
if(j < 0)
{
i--;
j = img->x - 1;
}
 img->data[i * img->x + j].blue |= 0x01;
j++;
if(j >= img->x)
{
i++;
j = 0;
}

while( (n = read(fd,buf,sizeof(buf))) > 0)
for (int m = 0;m < n;m += 3)
{
loadbit8(buf[m],0);
loadbit8(buf[m+1],8);
loadbit8(buf[m+2],16);
for(bitcount = 0; bitcount < 24; bitcount += 2){
img->data[i * img->x + j].red = decode(img->data[i * img->x + j].red,bitcount);bitcount += 2;
img->data[i * img->x + j].green = decode(img->data[i * img->x + j].green,bitcount);bitcount += 2;
img->data[i * img->x + j].blue = decode(img->data[i * img->x + j].blue,bitcount);
j++;
if(j >= img->x)
{
i++;
j = 0;
}

}

}

}
}
int 
main (int argc, char *argv[]) 
{
  char systm[20] = {'\0'};
char command[20] = {'\0'};
PPMImage * image;
int fd;
  struct stat statv;
stat(argv[3],&statv);
 
if (argc != 4)
printf("usage: ./a.out <inputfile> <outputfile> <secretfile>\n");
  else
    {
      
fd = open (argv[3], O_RDONLY);
sprintf(command,"%s%s%s","jpegtopnm ",argv[1]," >> tempimg");
system(command);
image = readPPM ("tempimg");
     char *basnam = basename(argv[3]);
changeColorPPM (image, fd,statv.st_size,basnam);     
 
writePPM (argv[2], image);
       close(fd);
remove("tempimg");

printf("heello\n");
    }


}


 
 
 
 
 
 
 
 
 
 
 
 
