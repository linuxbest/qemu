#include <assert.h>
#include "cpu.h"
#include "exec/helper-proto.h"
#include "qemu/host-utils.h"

#include "hw/lm32/lm32_pic.h"
#include "hw/char/lm32_juart.h"

#include "exec/cpu_ldst.h"
#include "mmu_helper.h"

#ifndef CONFIG_USER_ONLY
#include "sysemu/sysemu.h"
#endif

#define DEBUG_MMU

#ifdef DEBUG_MMU
#  define LOG_MMU(...) qemu_log(__VA_ARGS__)
#  define LOG_MMU_STATE(cpu) log_cpu_state((cpu), 0)
#else
#  define LOG_MMU(...) do { } while (0)
#  define LOG_MMU_STATE(cpu) do { } while (0)
#endif

#if !defined(CONFIG_USER_ONLY)

uint32_t lm32_mmu_get_psw(CPULM32State *state, uint32_t ie)
{
	uint32_t psw = state->psw | ie;
	LOG_MMU("mmu: read psw %08x, ie %08x\n", psw, ie);
	return psw;
}

uint32_t lm32_mmu_get_vadr(CPULM32State *state)
{
	LOG_MMU("mmu: read vadr %08x\n", 0);
	/* TODO */
	return 0;
}

uint32_t lm32_mmu_get_badr(CPULM32State *state)
{
	LOG_MMU("mmu: read badr %08x\n", 0);
	/* TODO */
	return 0;
}

void lm32_mmu_set_psw(CPULM32State *state, uint32_t psw)
{
	LOG_MMU("mmu: write psw %08x => %08x\n", state->psw, psw);
	state->psw = psw;
}

void lm32_mmu_set_vadr(CPULM32State *state, uint32_t r)
{
	LOG_MMU("mmu: write vadr %08x\n", r);
	/* TODO */
}

void lm32_mmu_set_padr(CPULM32State *state, uint32_t r)
{
	LOG_MMU("mmu: write padr %08x\n", r);
	/* TODO */
}

int lm32_mmu_translate(LM32MMUResult *res, CPULM32State *env, uint32_t vaddr,
                        int rw, int mmu_idx)
{
	LOG_MMU("mmu: translate vadr %08x, rw %d, idx %d\n", vaddr, rw, mmu_idx);
	res->phy = vaddr;
	return 0;
}

#endif
