/*
 * Minimal debug helpers 
 */

//////////////////////////////////////////////////////////////////////
// magic debug bytes
//
volatile uint16_t __at (0x107e) _post_code;
#define POST(_x)    _post_code = _x

//////////////////////////////////////////////////////////////////////
// minimalist assert()
//
#ifdef assert
#undef assert
#endif
#define assert(cond)    if (!(cond)) { POST(0x6570); for(;;); }
