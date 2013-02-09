#include <cstdint>
#include "Screen.hpp"

using std::uint32_t;

void check_magic() {
     extern uint32_t magic;
     /* Uncomment the following if you want to be able to access the multiboot header */
     //extern "C" void *mbd;

     if ( magic != 0x2BADB002 )
     {
	  /* Something went not according to specs. Print an error */
	  /* message and halt, but do *not* rely on the multiboot */
	  /* data structure. */
     }

}

extern "C" void kmain(void)
{
     check_magic();

     Screen screen;
     screen.clear();

     for(int iii = 0; iii < 25; ++iii)
     {
	  screen.write_string("Hello World ");
	  screen.write_char((iii/10)+'0');
	  screen.write_char((iii%10)+'0');
	  screen.write_line("");
     }
}
