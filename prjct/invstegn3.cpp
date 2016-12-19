#include<stdio.h> 
#include<stdlib.h> 
#include<unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#define CREATOR "yespee_4444@hotmail.com" 
#define RGB_COMPONENT_COLOR 255 

off_t count = 0;
int n = 0; 
char buf[513];
unsigned char bit8[32];
char fname[20];  
typedef struct 
{

unsigned char red, green, blue;
} PPMPixel;
 
typedef struct 
{
int x, y;
PPMPixel * data;
} PPMImage; 

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
void addtobuff(unsigned char k)
{
unsigned char h;
int i;
 h = '\0';
for (int m = 0; m < sizeof (char) * 8; m++)		    
h = h | (bit8[m] << (sizeof (char) * 8 - 1 - m));
fname[n++] = h;
if(k == 0x01)
fname[n] = '\0';
}
int addtobuff(int fd,off_t fsize)
{

unsigned char h;
 h = '\0';
for (int m = 0; m < sizeof (char) * 8; m++)		    
h = h | (bit8[m] << (sizeof (char) * 8 - 1 - m));
buf[n++] = h;
if(n == sizeof(buf))
{
write(fd,buf,n);
n = 0;
}
if(count == fsize+1){
write(fd,buf,n-1);
close(fd);
return 1;
}
return 0;
}
void 
changeColorPPM (PPMImage * img, int fd) 
{ 
int i = 0, j = 0, bitcount = 0;
 off_t fsize = 0;
 
unsigned char k = 0x00;
 
if (img)     
    {
while(1)
{
bit8[bitcount++] = (img->data[i * img->x + j].red & 0x01) ^ ((img->data[i * img->x + j].red & 0x02) >> 1);
bit8[bitcount++] = (img->data[i * img->x + j].red & 0x01) ^ ((img->data[i * img->x + j].red & 0x08) >> 3);
if(bitcount == 32) break;
bit8[bitcount++] = (img->data[i * img->x + j].green & 0x01) ^ ((img->data[i * img->x + j].green & 0x02) >> 1);
bit8[bitcount++] = (img->data[i * img->x + j].green & 0x01) ^ ((img->data[i * img->x + j].green & 0x08) >> 3);
bit8[bitcount++] = (img->data[i * img->x + j].blue & 0x01) ^ ((img->data[i * img->x + j].blue & 0x02) >> 1);
bit8[bitcount++] = (img->data[i * img->x + j].blue & 0x01) ^ ((img->data[i * img->x + j].blue & 0x08) >> 3);
j++;
}
for(int offtcount = sizeof(off_t)*8-1 ; offtcount >= 0;offtcount--)
fsize = (fsize << 1) | bit8[offtcount];

j = 6;
bitcount = 0;
n=0;

while(k == 0x00)
{

	     
bit8[bitcount++] = (img->data[i * img->x + j].red & 0x01) ^ ((img->data[i * img->x + j].red & 0x02) >> 1);
bit8[bitcount++] = (img->data[i * img->x + j].red & 0x01) ^ ((img->data[i * img->x + j].red & 0x08) >> 3);
bit8[bitcount++] = (img->data[i * img->x + j].green & 0x01) ^ ((img->data[i * img->x + j].green & 0x02) >> 1);
bit8[bitcount++] = (img->data[i * img->x + j].green & 0x01) ^ ((img->data[i * img->x + j].green & 0x08) >> 3);
k = 0x01 & img->data[i * img->x + j].blue;
if(bitcount == 8) { bitcount = 0;addtobuff(k);}
j++;
if(j >= img->x)
{
i++;
j = 0;
}
}
n=0;
bitcount = 0;

  for (i; i < img->y; i++)
	
 
	{
	 
for (j; j < img->x; j++)
	    
 
	    {
	     
bit8[bitcount++] = (img->data[i * img->x + j].red & 0x01) ^ ((img->data[i * img->x + j].red & 0x02) >> 1);
bit8[bitcount++] = (img->data[i * img->x + j].red & 0x01) ^ ((img->data[i * img->x + j].red & 0x08) >> 3);
if(bitcount == 8) {count++; bitcount = 0;if(addtobuff(fd,fsize)) return;}
bit8[bitcount++] = (img->data[i * img->x + j].green & 0x01) ^ ((img->data[i * img->x + j].green & 0x02) >> 1);
bit8[bitcount++] = (img->data[i * img->x + j].green & 0x01) ^ ((img->data[i * img->x + j].green & 0x08) >> 3);
if(bitcount == 8) {count++; bitcount = 0;if(addtobuff(fd,fsize)) return;}
bit8[bitcount++] = (img->data[i * img->x + j].blue & 0x01) ^ ((img->data[i * img->x + j].blue & 0x02) >> 1);
bit8[bitcount++] = (img->data[i * img->x + j].blue & 0x01) ^ ((img->data[i * img->x + j].blue & 0x08) >> 3);
if(bitcount == 8) {count++; bitcount = 0;if(addtobuff(fd,fsize)) return;}


}
 j=0;

}



}
    
}

int 
main (int argc, char *argv[]) 
{
PPMImage * image;
  
int fd, n;
  
if (argc != 2)
    
printf ("usage: ./a.out <inputfile>\n");
  else
    
    {
fd = open ("temp", O_WRONLY | O_CREAT|O_TRUNC, 0777);
image = readPPM (argv[1]);
changeColorPPM (image, fd);
fname[0] = 'k';
printf("%s",fname);
rename("temp",fname);
    }
}


 
 
 
 
 
 
 
 
 
 
 
 
 
 
