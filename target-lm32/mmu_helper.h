#ifndef QEMU_HW_MMU_LM32_H
#define QEMU_HW_MMU_LM32_H

uint32_t lm32_mmu_get_psw(CPULM32State *state, uint32_t ie);
uint32_t lm32_mmu_get_vadr(CPULM32State *state);
uint32_t lm32_mmu_get_badr(CPULM32State *state);

void lm32_mmu_set_psw(CPULM32State *state, uint32_t r);
void lm32_mmu_set_padr(CPULM32State *state, uint32_t r);
void lm32_mmu_set_vadr(CPULM32State *state, uint32_t r);

#endif
