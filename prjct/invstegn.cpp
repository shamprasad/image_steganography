#include<stdio.h> 
#include<stdlib.h> 
#include<unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#define CREATOR "yespee_4444@hotmail.com" 
#define RGB_COMPONENT_COLOR 255 
int count = 0;

 
 
 
char buf[512];

 
 
 
unsigned char bit8[8];

 
 
 
 
 
 
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
  
 
 
 
 
 
    //read image format 
    if (!fgets (buff, sizeof (buff), fp))
    
 
 
 
    {
      
 
 
 
 
perror (filename);
      
 
 
 
 
exit (1);
    
 
 
 
 
}
  
 
 
 
 
 
    //check the image format 
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
  
 
 
 
 
//check for comments 
    c = getc (fp);
  
 
 
 
 
while (c == '#')
    
 
 
 
    {
      
 
 
 
 
while (getc (fp) != '\n');
      
 
 
 
 
c = getc (fp);
    
 
 
 
 
}
  
 
 
 
 
 
ungetc (c, fp);
  
 
 
 
 
    //read image size information 
    if (fscanf (fp, "%d %d", &img->x, &img->y) != 2)
    
 
 
 
    {
      
 
 
 
 
fprintf (stderr, "Invalid image size (error loading '%s')\n",
			
 
 
 
filename);
      
 
 
 
 
exit (1);
    
 
 
 
 
}
  
 
 
 
 
 
    //read rgb component 
    if (fscanf (fp, "%d", &rgb_comp_color) != 1)
    
 
 
 
    {
      
 
 
 
 
fprintf (stderr,
			"Invalid rgb component (error loading '%s')\n",
			
 
 
 
filename);
      
 
 
 
 
exit (1);
    
 
 
 
 
}
  
 
 
 
 
    //check rgb component depth 
    if (rgb_comp_color != RGB_COMPONENT_COLOR)
    
 
 
 
    {
      
 
 
 
 
fprintf (stderr, "'%s' does not have 8-bits components\n",
			
 
filename);
      
 
 
 
 
exit (1);
    
 
 
 
 
}
  
 
 
 
 
 
while (fgetc (fp) != '\n');
  
 
 
 
 
    //memory allocation for pixel data 
    img->data = (PPMPixel *) malloc (img->x * img->y * sizeof (PPMPixel));
  
 
 
 
 
 
if (!img)
    
 
 
 
    {
      
 
 
 
 
fprintf (stderr, "Unable to allocate memory\n");
      
 
 
 
 
exit (1);
    
 
 
 
 
}
  
 
 
 
 
//read pixel data from file 
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
  
 
 
    //open file for output 
    fp = fopen (filename, "wb");
  
 
 
if (!fp)
    
 
 
    {
      
 
fprintf (stderr, "Unable to open file '%s'\n", filename);
      
 
 
exit (1);
    
 
 
}
  
 
 
    //write the header file 
    //image format 
    fprintf (fp, "P6\n");
  
 
 
    //comments 
    fprintf (fp, "# Created by %s\n", CREATOR);
  
 
 
    //image size 
    fprintf (fp, "%d %d\n", img->x, img->y);
  
 
 
    // rgb component depth 
    fprintf (fp, "%d\n", RGB_COMPONENT_COLOR);
  
 
 
    // pixel data 
    fwrite (img->data, 3 * img->x, img->y, fp);
  
 
 
fclose (fp);

 
 
}


 
 
 
 
 
void 
changeColorPPM (PPMImage * img, int fd) 
{
  
 
 
int i = 0, j = 0,  n = 0;
  
 
unsigned char k ;
 char h;
 
if (img)
     


    {
  for (i = 0; i < img->y; i++)
	
 
	{
	 
for (j = 0; j < img->x; j +=3)
	    
 
	    {
	      
bit8[0] = 0x01 & img->data[i * img->x + j].red;
bit8[1] = 0x01 & img->data[i * img->x + j].green;
bit8[2] = 0x01 & img->data[i * img->x + j].blue;
bit8[3] = 0x01 & img->data[i * img->x + j+1].red;
bit8[4] = 0x01 & img->data[i * img->x + j+1].green;
bit8[5] = 0x01 & img->data[i * img->x + j+1].blue;
bit8[6] = 0x01 & img->data[i * img->x + j+2].red;
bit8[7] = 0x01 & img->data[i * img->x + j+2].green;
k = 0x01 & img->data[i * img->x + j+2].blue;
 h = '\0';
for (int m = 0; m < sizeof (char) * 8; m++)		    
h = h | (bit8[m] << (sizeof (char) * 8 - 1 - m));
buf[n++] = h;
if(n == sizeof(buf))
{
printf("%d\n",write(fd,buf,n));
n = 0;
}
if(k == 0x01){
printf("%d\n",write(fd,buf,n-1));
close(fd);
return;
}
}
 

}
	
 
}
    
 
}

 



 
 
 
 
int 
main (int argc, char *argv[]) 
{
  
 
PPMImage * image;
  
 
 
int fd, n;
  
 
 
if (argc != 3)
    
 
 
printf ("usage: ./a.out <inputfile> <outputfile>\n");
  
 
 
  else
    
 
 
    {
      
 
 
 
 
fd = open (argv[2], O_WRONLY | O_CREAT|O_TRUNC, 0777);
      
 
image = readPPM (argv[1]);
      
 
 
 
changeColorPPM (image, fd);
      
 
 
//writePPM (argv[2], image);
	
 
printf ("no. of pixels = %d\nPress any key...\n", count);
      
 
 
 
//getchar ();
    }

 
 
 
}


 
 
 
 
 
 
 
 
 
 
 
 
 
 
