//	[VERSION] 1.9, 4
// Do not modify manually.

#ifndef _HT46F47E_H_
#define _HT46F47E_H_

#ifndef __DISABLE_HGCC_BUILD_IN__
#include "build-in.h"
#endif

#define DEFINE_ISR(isr_name, vector) void __attribute((interrupt(vector))) isr_name(void)

#define DEFINE_SFR(sfr_type, sfr, addr) static volatile sfr_type sfr __attribute__ ((at(addr)))

typedef unsigned char __sfr_byte;

typedef struct {
	unsigned char __c : 1;
	unsigned char __ac : 1;
	unsigned char __z : 1;
	unsigned char __ov : 1;
	unsigned char __pdf : 1;
	unsigned char __to : 1;
	unsigned char : 2;
} __status_bits;

typedef union {
	__status_bits bits;
	__sfr_byte byte;
} __status_type;

typedef struct {
	unsigned char __emi : 1;
	unsigned char __eei : 1;
	unsigned char __eti : 1;
	unsigned char __eadi : 1;
	unsigned char __eif : 1;
	unsigned char __tf : 1;
	unsigned char __adf : 1;
	unsigned char : 1;
} __intc_bits;

typedef union {
	__intc_bits bits;
	__sfr_byte byte;
} __intc_type;

typedef struct {
	unsigned char __psc0 : 1;
	unsigned char __psc1 : 1;
	unsigned char __psc2 : 1;
	unsigned char __te : 1;
	unsigned char __ton : 1;
	unsigned char : 1;
	unsigned char __tm0 : 1;
	unsigned char __tm1 : 1;
} __tmrc_bits;

typedef union {
	__tmrc_bits bits;
	__sfr_byte byte;
} __tmrc_type;

typedef struct {
	unsigned char __pa0 : 1;
	unsigned char __pa1 : 1;
	unsigned char __pa2 : 1;
	unsigned char __pa3 : 1;
	unsigned char __pa4 : 1;
	unsigned char __pa5 : 1;
	unsigned char __pa6 : 1;
	unsigned char __pa7 : 1;
} __pa_bits;

typedef union {
	__pa_bits bits;
	__sfr_byte byte;
} __pa_type;

typedef struct {
	unsigned char __pac0 : 1;
	unsigned char __pac1 : 1;
	unsigned char __pac2 : 1;
	unsigned char __pac3 : 1;
	unsigned char __pac4 : 1;
	unsigned char __pac5 : 1;
	unsigned char __pac6 : 1;
	unsigned char __pac7 : 1;
} __pac_bits;

typedef union {
	__pac_bits bits;
	__sfr_byte byte;
} __pac_type;

typedef struct {
	unsigned char __pb0 : 1;
	unsigned char __pb1 : 1;
	unsigned char __pb2 : 1;
	unsigned char __pb3 : 1;
	unsigned char : 4;
} __pb_bits;

typedef union {
	__pb_bits bits;
	__sfr_byte byte;
} __pb_type;

typedef struct {
	unsigned char __pbc0 : 1;
	unsigned char __pbc1 : 1;
	unsigned char __pbc2 : 1;
	unsigned char __pbc3 : 1;
	unsigned char : 4;
} __pbc_bits;

typedef union {
	__pbc_bits bits;
	__sfr_byte byte;
} __pbc_type;

typedef struct {
	unsigned char __pd0 : 1;
	unsigned char : 7;
} __pd_bits;

typedef union {
	__pd_bits bits;
	__sfr_byte byte;
} __pd_type;

typedef struct {
	unsigned char __pdc0 : 1;
	unsigned char : 7;
} __pdc_bits;

typedef union {
	__pdc_bits bits;
	__sfr_byte byte;
} __pdc_type;

typedef struct {
	unsigned char : 7;
	unsigned char __d0 : 1;
} __adrl_bits;

typedef union {
	__adrl_bits bits;
	__sfr_byte byte;
} __adrl_type;

typedef struct {
	unsigned char __d1 : 1;
	unsigned char __d2 : 1;
	unsigned char __d3 : 1;
	unsigned char __d4 : 1;
	unsigned char __d5 : 1;
	unsigned char __d6 : 1;
	unsigned char __d7 : 1;
	unsigned char __d8 : 1;
} __adrh_bits;

typedef union {
	__adrh_bits bits;
	__sfr_byte byte;
} __adrh_type;

typedef struct {
	unsigned char __acs0 : 1;
	unsigned char __acs1 : 1;
	unsigned char __acs2 : 1;
	unsigned char __pcr0 : 1;
	unsigned char __pcr1 : 1;
	unsigned char __pcr2 : 1;
	unsigned char __eocb : 1;
	unsigned char __start : 1;
} __adcr_bits;

typedef union {
	__adcr_bits bits;
	__sfr_byte byte;
} __adcr_type;

typedef struct {
	unsigned char __adcs0 : 1;
	unsigned char __adcs1 : 1;
	unsigned char : 6;
} __acsr_bits;

typedef union {
	__acsr_bits bits;
	__sfr_byte byte;
} __acsr_type;

typedef struct {
	unsigned char : 4;
	unsigned char __cs : 1;
	unsigned char __sk : 1;
	unsigned char __di : 1;
	unsigned char __do : 1;
} __eecr_bits;

typedef union {
	__eecr_bits bits;
	__sfr_byte byte;
} __eecr_type;


DEFINE_SFR(__sfr_byte, __mp0, 0x01);
DEFINE_SFR(__sfr_byte, __mp1, 0x03);
DEFINE_SFR(__sfr_byte, __bp, 0x04);
DEFINE_SFR(__sfr_byte, __acc, 0x05);
DEFINE_SFR(__sfr_byte, __pcl, 0x06);
DEFINE_SFR(__sfr_byte, __tblp, 0x07);
DEFINE_SFR(__sfr_byte, __tblh, 0x08);
DEFINE_SFR(__status_type, __status, 0x0a);
DEFINE_SFR(__intc_type, __intc, 0x0b);
DEFINE_SFR(__sfr_byte, __tmr, 0x0d);
DEFINE_SFR(__tmrc_type, __tmrc, 0x0e);
DEFINE_SFR(__pa_type, __pa, 0x12);
DEFINE_SFR(__pac_type, __pac, 0x13);
DEFINE_SFR(__pb_type, __pb, 0x14);
DEFINE_SFR(__pbc_type, __pbc, 0x15);
DEFINE_SFR(__pd_type, __pd, 0x18);
DEFINE_SFR(__pdc_type, __pdc, 0x19);
DEFINE_SFR(__sfr_byte, __pwm, 0x1a);
DEFINE_SFR(__adrl_type, __adrl, 0x24);
DEFINE_SFR(__adrh_type, __adrh, 0x25);
DEFINE_SFR(__adcr_type, __adcr, 0x26);
DEFINE_SFR(__acsr_type, __acsr, 0x27);
DEFINE_SFR(__eecr_type, __eecr, 0x140);
DEFINE_SFR(__sfr_byte, __iar0, 0x00);
DEFINE_SFR(__sfr_byte, __iar1, 0x02);

#define _iar0     __iar0
#define _iar1     __iar1
#define _mp0      __mp0
#define _mp1      __mp1
#define _bp       __bp
#define _acc      __acc
#define _pcl      __pcl
#define _tblp     __tblp
#define _tblh     __tblh
#define _status   __status.byte
#define _intc     __intc.byte
#define _tmr      __tmr
#define _tmrc     __tmrc.byte
#define _pa       __pa.byte
#define _pac      __pac.byte
#define _pb       __pb.byte
#define _pbc      __pbc.byte
#define _pd       __pd.byte
#define _pdc      __pdc.byte
#define _pwm      __pwm
#define _adrl     __adrl.byte
#define _adrh     __adrh.byte
#define _adcr     __adcr.byte
#define _acsr     __acsr.byte
#define _eecr     __eecr.byte

#define _c        __status.bits.__c
#define _ac       __status.bits.__ac
#define _z        __status.bits.__z
#define _ov       __status.bits.__ov
#define _pdf      __status.bits.__pdf
#define _to       __status.bits.__to
#define _emi      __intc.bits.__emi
#define _eei      __intc.bits.__eei
#define _eti      __intc.bits.__eti
#define _eadi     __intc.bits.__eadi
#define _eif      __intc.bits.__eif
#define _tf       __intc.bits.__tf
#define _adf      __intc.bits.__adf
#define _psc0     __tmrc.bits.__psc0
#define _psc1     __tmrc.bits.__psc1
#define _psc2     __tmrc.bits.__psc2
#define _te       __tmrc.bits.__te
#define _ton      __tmrc.bits.__ton
#define _tm0      __tmrc.bits.__tm0
#define _tm1      __tmrc.bits.__tm1
#define _pa0      __pa.bits.__pa0
#define _pa1      __pa.bits.__pa1
#define _pa2      __pa.bits.__pa2
#define _pa3      __pa.bits.__pa3
#define _pa4      __pa.bits.__pa4
#define _pa5      __pa.bits.__pa5
#define _pa6      __pa.bits.__pa6
#define _pa7      __pa.bits.__pa7
#define _pac0     __pac.bits.__pac0
#define _pac1     __pac.bits.__pac1
#define _pac2     __pac.bits.__pac2
#define _pac3     __pac.bits.__pac3
#define _pac4     __pac.bits.__pac4
#define _pac5     __pac.bits.__pac5
#define _pac6     __pac.bits.__pac6
#define _pac7     __pac.bits.__pac7
#define _pb0      __pb.bits.__pb0
#define _pb1      __pb.bits.__pb1
#define _pb2      __pb.bits.__pb2
#define _pb3      __pb.bits.__pb3
#define _pbc0     __pbc.bits.__pbc0
#define _pbc1     __pbc.bits.__pbc1
#define _pbc2     __pbc.bits.__pbc2
#define _pbc3     __pbc.bits.__pbc3
#define _pd0      __pd.bits.__pd0
#define _pdc0     __pdc.bits.__pdc0
#define _d0       __adrl.bits.__d0
#define _d1       __adrh.bits.__d1
#define _d2       __adrh.bits.__d2
#define _d3       __adrh.bits.__d3
#define _d4       __adrh.bits.__d4
#define _d5       __adrh.bits.__d5
#define _d6       __adrh.bits.__d6
#define _d7       __adrh.bits.__d7
#define _d8       __adrh.bits.__d8
#define _acs0     __adcr.bits.__acs0
#define _acs1     __adcr.bits.__acs1
#define _acs2     __adcr.bits.__acs2
#define _pcr0     __adcr.bits.__pcr0
#define _pcr1     __adcr.bits.__pcr1
#define _pcr2     __adcr.bits.__pcr2
#define _eocb     __adcr.bits.__eocb
#define _start    __adcr.bits.__start
#define _adcs0    __acsr.bits.__adcs0
#define _adcs1    __acsr.bits.__adcs1
#define _cs       __eecr.bits.__cs
#define _sk       __eecr.bits.__sk
#define _di       __eecr.bits.__di
#define _do       __eecr.bits.__do

#define ___mkstr(x)                #x
#define __EEPROM_DATA(a, b, c, d, e, f, g, h) \
                         asm("eeprom_data .section 'eeprom'"); \
                         asm("db\t" ___mkstr(a));        \
                         asm("db\t" ___mkstr(b));        \
                         asm("db\t" ___mkstr(c));        \
                         asm("db\t" ___mkstr(d));        \
                         asm("db\t" ___mkstr(e));        \
                         asm("db\t" ___mkstr(f));        \
                         asm("db\t" ___mkstr(g));        \
                         asm("db\t" ___mkstr(h));        

#endif // _HT46F47E_H_
