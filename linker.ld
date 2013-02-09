/* From http://wiki.osdev.org/C%2B%2B_Bare_Bones */
ENTRY (loader)

SECTIONS
{
    . = 0x00100000;

    .text ALIGN (0x1000) :
    {
        *(.text)
        *(.gnu.linkonce.t*)
    }

    /* Note that the ctor and dtor sections need to be properly */
    /* aligned. The linker script shown here does that by placing them at */
    /* the beginning of the .rodata section, which is aligned at a page */
    /* boundary. */

    .rodata ALIGN (0x1000) :
    {
        start_ctors = .;
        *(SORT(.ctors*))  /* Note the "SORT" */
        end_ctors = .;

        start_dtors = .;
        *(SORT(.dtors*))
        end_dtors = .;

        *(.rodata*)
        *(.gnu.linkonce.r*)
    }

    .data ALIGN (0x1000) :
    {
        *(.data)
        *(.gnu.linkonce.d*)
    }

    .bss :
    {
        sbss = .;
        *(COMMON)
        *(.bss)
        *(.gnu.linkonce.b*)
        ebss = .;
    }

    /DISCARD/ :
    {
        *(.comment)
        *(.eh_frame) /* discard this, unless you are implementing runtime support for C++ exceptions. */
    }
}
