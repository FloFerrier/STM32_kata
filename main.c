#include <stdint.h>

#define RCC_BASE_ADDR ((uint32_t)0x40023800)

extern uint32_t _etext;
extern uint32_t _sdata;
extern uint32_t _edata;
extern uint32_t _sbss;
extern uint32_t _ebss;
extern uint32_t _data_loadaddr;

void Reset_Handler(void);
int main(void);

void Reset_Handler(void) {
    /* Copy .data section to RAM */ 
    uint32_t size = (uint32_t) &_edata - (uint32_t) &_sdata;

    uint8_t *pSrc = (uint8_t *) &_etext;
    uint8_t *pDst = (uint8_t *) &_data_loadaddr;

    for (uint32_t i; i< size; i++) {
        *pDst++ = *pSrc++;
    }

    /* Initialize the .bss zone to 0 */ 
    size = (uint32_t) &_ebss - (uint32_t) &_sbss;
    pDst = (uint8_t *) &_sbss;

    for (uint32_t i; i < size; i++) {
        *pDst++ = 0;
    }

    (void) main();
}

int main(void) {

    static uint32_t tmp = 0;
    while(1) {
        ++tmp;
    }

    return 0;
}