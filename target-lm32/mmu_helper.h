#ifndef QEMU_HW_MMU_LM32_H
#define QEMU_HW_MMU_LM32_H

uint32_t lm32_mmu_get_psw(CPULM32State *state, uint32_t ie);
uint32_t lm32_mmu_get_vadr(CPULM32State *state);
uint32_t lm32_mmu_get_badr(CPULM32State *state);

void lm32_mmu_set_psw(CPULM32State *state, uint32_t r);
void lm32_mmu_set_padr(CPULM32State *state, uint32_t r);
void lm32_mmu_set_vadr(CPULM32State *state, uint32_t r);

typedef struct {
    uint32_t phy;
    uint32_t pfn;
    int g:1;
    int v:1;
    int k:1;
    int w:1;
    int e:1;
    int cause_op;
} LM32MMUResult;

int lm32_mmu_translate(LM32MMUResult *res,
                        CPULM32State *env, uint32_t vaddr,
                        int rw, int mmu_idx);
#endif
