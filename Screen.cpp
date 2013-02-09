#include "Screen.hpp"

/* Text mode memory takes two bytes for every "character" on screen.
   One is the ASCII code byte, the other the attribute byte.
*/
/* The attribute byte carries the foreground colour in its
   lowest 4 bits and the background color in its highest 3 bits.
   The interpretation of bit #7 depends on how you (or the BIOS) configured the hardware
*/


Screen::Screen():
     m_video_memory_addr(0xB8000),
     m_position(0),
     m_max_position(80*25) /* 80 columns x 25 lines*/

{}


void Screen::write_char(char chr, int colour)
{
     if(m_position < m_max_position-1)
     {
	  ++m_position;
     }
     else
     {
	  m_position=0;
     }
     video_char* video_memory;
     video_memory = reinterpret_cast<video_char*>(m_video_memory_addr);

     video_memory[m_position-1].chr = chr;
     video_memory[m_position-1].colour = colour;


}
void Screen::write_string(const char *string)
{
     while( *string != 0 )
     {
	  write_char(*string++);
     }
}

void Screen::write_line(const char * string)
{
     write_string(string);
     unsigned int cols_left = 80 - (m_position % 80);
     for(unsigned int iii = 0; iii < cols_left; ++iii)
     {
	  write_char(0x0);
     }
}

void Screen::clear()
{
     video_char* video_memory;
     video_memory = reinterpret_cast<video_char*>(m_video_memory_addr);

     video_char zero = {0, 0};

     for(unsigned int iii = 0; iii != m_max_position; ++iii)
     {
	  video_memory[iii] = zero;
     }

     m_position = 0;
}
