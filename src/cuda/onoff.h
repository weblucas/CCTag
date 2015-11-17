#pragma once

#define DEBUG_WRITE_ORIGINAL_AS_PGM
#define DEBUG_WRITE_ORIGINAL_AS_ASCII
#define DEBUG_WRITE_DX_AS_PGM
#define DEBUG_WRITE_DX_AS_ASCII
#define DEBUG_WRITE_DY_AS_PGM
#define DEBUG_WRITE_DY_AS_ASCII
#define DEBUG_WRITE_MAG_AS_PGM
#define DEBUG_WRITE_MAG_AS_ASCII
#define DEBUG_WRITE_MAP_AS_PGM
#define DEBUG_WRITE_MAP_AS_ASCII
#define DEBUG_WRITE_HYSTEDGES_AS_PGM
#define DEBUG_WRITE_EDGES_AS_PGM
#define DEBUG_WRITE_EDGELIST_AS_PPM
#define DEBUG_WRITE_EDGELIST_AS_ASCII
#define DEBUG_WRITE_VOTERS_AS_PPM
#define DEBUG_WRITE_CHOSEN_AS_PPM
#define DEBUG_WRITE_CHOSEN_VOTERS_AS_ASCII
#define DEBUG_WRITE_CHOSEN_ELECTED_AS_ASCII
#define DEBUG_WRITE_LINKED_AS_PPM
#define DEBUG_WRITE_LINKED_AS_PPM_INTENSE
#define DEBUG_WRITE_LINKED_AS_ASCII
#define DEBUG_WRITE_LINKED_AS_ASCII_INTENSE

#define DEBUG_LINKED_USE_INT4_BUFFER

/* Separable compilation allows one kernel to instantiate
 * others. That avoids complexity on the host side when,
 * e.g., GPU-side counters need to be checked before starting
 * a new kernel.
 */
#undef USE_SEPARABLE_COMPILATION
#undef USE_SEPARABLE_COMPILATION_IN_GRADDESC

/* Init _d_intermediate to 0 before uploading. Wastes time,
 * for debugging only. Required because of crash -O3 but not
 * with -G
 */
#define DEBUG_FRAME_UPLOAD_CUTS

/* Define if you want to compute identity both on GPU and CPU.
 * The GPU version takes precedence.
 * Otherwise, GPU is used if cudaPipe exists (the alternative,
 * param.useCuda == false is broken in the optim_identify_gpu
 * branch).
 */
#undef CPU_GPU_COST_FUNCTION_COMPARE

/* CUB functions always take a last parameters true or false.
 * If it is true, they run synchronously and print some debug
 * info.
 */
#define DEBUG_CUB_FUNCTIONS false

/* CUB RadixSort requires the DoubleBuffer structure and annoying
 * host-side sync in the CUB version that comes with CUDA 7.0.
 * CUDA 7.5 or standalone CUB 1.4.1 allow an output buffer.
 * However, so far they don't work.
 */
#undef RADIX_WITHOUT_DOUBLEBUFFER

/* For the CUB version included with CUDA 7.0, it was possible to
 * pass an arbitrary device pointer pointing to sufficiently large
 * memory.
 * Standalone CUB 1.4.1 fails unless the init call for determining
 * intermediate buffer size is made.
 */
#define CUB_INIT_CALLS

