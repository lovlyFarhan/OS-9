class Screen {
public:
     Screen();

     void write_char(char chr, int colour=0x07);
     void write_string(const char *string);
     void write_line(const char *string);
     void clear();

private:
     struct video_char {
	  unsigned char chr;
	  unsigned char colour;
     };

     unsigned int m_video_memory_addr;

     unsigned int m_position;
     const unsigned int m_max_position;

};
