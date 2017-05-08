#pragma once

/* Pushed by the INT handlers in the order that a PUSHA would. */
union reg {
    struct {
        unsigned char l;
        unsigned char h;
    };
    unsigned short x;
};

struct callregs {
    union reg di;
    union reg si;
    union reg bp;
    union reg sp;
    union reg bx;
    union reg dx;
    union reg cx;
    union reg ax;
    unsigned short ds;
    unsigned short flags;
};

enum FlagBitPos {
    CF_OFFS = 0,
    PF_OFFS = 2,
    AF_OFFS = 4,
    ZF_OFFS = 6,
    SF_OFFS = 7,
    TF_OFFS = 8,
    IF_OFFS = 9,
    DF_OFFS = 10,
    OF_OFFS = 11
};

enum Flag {
    CF = (1 << CF_OFFS),
    PF = (1 << PF_OFFS),
    AF = (1 << AF_OFFS),
    ZF = (1 << ZF_OFFS),
    SF = (1 << SF_OFFS),
    TF = (1 << TF_OFFS),
    IF = (1 << IF_OFFS),
    DF = (1 << DF_OFFS),
    OF = (1 << OF_OFFS),
};

void panic(const char *p);
void *memset(void *s, int c, unsigned short n);