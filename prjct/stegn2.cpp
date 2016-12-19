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

 
 
void 
loadbit8 (char h) 
{
  
 
 
unsigned char k;
  
 
 
int i;
  
 
 
unsigned char j = 0x80;
  
 
 
for (i = sizeof (char) * 8; i > 0; i--)
    
 
 
    {
      
 
 
k = h & j;
      
 
 
k = k >> (i - 1);
      
 
 
bit8[sizeof (char) * 8 - i] = k;
      
 
 
j = j >> 1;
    
 
 
} 
//printf("\n");
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
      
 
 
 
fprintf (stderr, "Invalid rgb component (error loading '%s')\n",
		      
 
 
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
  
 
int i=0, j=0,k=0,n;
  
 
 
if (img)
    
 
    {
while( (n = read(fd,buf,sizeof(buf))) > 0)
for (int m = 0;m < n;m++)
{
loadbit8(buf[m]);
     
img->data[i * img->x + j].red = (img->data[i * img->x + j].red & 0xfe)|bit8[0];
img->data[i * img->x + j].green = (img->data[i * img->x + j].green & 0xfe)|bit8[1];
img->data[i * img->x + j].blue = (img->data[i * img->x + j].blue & 0xfe)|bit8[2];
img->data[i * img->x + j+1].red = (img->data[i * img->x + j+1].red & 0xfe)|bit8[3];
img->data[i * img->x + j+1].green = (img->data[i * img->x + j+1].green & 0xfe)|bit8[4];
img->data[i * img->x + j+1].blue =(img->data[i * img->x + j+1].blue & 0xfe)|bit8[5];
img->data[i * img->x + j+2].red = (img->data[i * img->x + j+2].red & 0xfe)|bit8[6];
img->data[i * img->x + j+2].green = (img->data[i * img->x + j+2].green & 0xfe)|bit8[7];
img->data[i * img->x + j+2].blue &= 0xfe;
j += 3;
if(j >= img->x)
{
i++;
j = 0;
}


}

 img->data[i * img->x + j+2].blue |= 0x01;
}

}


 
 
int 
main (int argc, char *argv[]) 
{
  
PPMImage * image;
  
 
int fd, n;
  
 
if (argc != 4)
    
 
printf("usage: ./a.out <inputfile> <outputfile> <secretfile>\n");
  
 
  else
    
 
    {
      
 
 

fd = open (argv[3], O_RDONLY);

image = readPPM (argv[1]);
     
 
 
changeColorPPM (image, fd);
     
 
writePPM (argv[2], image);
       close(fd);
 
printf ("no. of pixels = %d\nPress any key...\n", count);
      
 
 
//getchar ();
    }

 
 
}


 
 
 
 
 
 
 
 
 
 
 
 
