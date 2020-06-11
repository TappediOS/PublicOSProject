// ***************************************
//  include - memory - fault.h
//  Update  develop4.0
// ***************************************

#include <types.h>

#ifndef __MEMORY_FAULT__
#define __MEMORY_FAULT__


extern void asmEmptyHandler(void);
extern void asmDeHandler(void);
extern void asmDbHandler(void);
extern void asmNmiHandler(void);
extern void asmBpHandler(void);
extern void asmOfHandler(void);
extern void asmBrHandler(void);
extern void asmUdHandler(void);
extern void asmNmHandler(void);
extern void asmDfHandler(void);
extern void asmTsHandler(void);
extern void asmNpHandler(void);
extern void asmSsHandler(void);
extern void asmGpHandler(void);
extern void asmPfHandler(void);
extern void asmMfHandler(void);
extern void asmAcHandler(void);
extern void asmMcHandler(void);
extern void asmXmHandler(void);

void emptyHandler(void);
void deHandler(void);
void dbHandler(void);
void nmiHandler(void);
void bpHandler(void);
void ofHandler(void);
void brHandler(void);
void udHandler(void);
void nmHandler(void);
void dfHandler(void);
void tsHandler(void);
void npHandler(void);
void ssHandler(void);
void gpHandler(void);
void pfHandler(void);
void mfHandler(void);
void acHandler(void);
void mcHandler(void);
void xmHandler(void);

#endif  // __MEMORY_FAULT__
