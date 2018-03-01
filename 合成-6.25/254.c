/* 当前文件是D:\Read\gap.c*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <signal.h>
#include <ctype.h>
#include <time.h>
#include <limits.h>
#include <errno.h>
#include <signal.h>
#include <stddef.h>
#include <signal.h>
#include <setjmp.h> 
/* 当前文件是D:\Read\system.h*/

#ifdef  __STDC__
#define P(ARGS) ARGS
#else
#define P(ARGS) ()
#endif
#ifdef SPEC_CPU2000_P64
#define long __int64
#endif

#define IsAlpha(ch)     (isalpha((int)ch))
#define IsDigit(ch)     (isdigit((int)ch))

/* 当前文件是D:\Read\gasman.h*/

#ifdef SPEC_CPU2000_P64
#define long __int64
#endif
#define T_VOID           0
#define T_INT            1
#define T_INTPOS         2
#define T_INTNEG         3
#define T_RAT            4
#define T_CYC            5
#define T_UNKNOWN        6
#define T_FFE            7
#define T_PERM16         8
#define T_PERM32         9
#define T_WORD          10
#define T_SWORD         11
#define T_AGWORD        12
#define T_BOOL          13
#define T_CHAR          14
#define T_FUNCTION      15
#define T_FUNCINT       16
#define T_LIST          17
#define T_SET           18
#define T_VECTOR        19
#define T_VECFFE        20
#define T_BLIST         21
#define T_STRING        22
#define T_RANGE         23
#define T_REC           24
#define T_MATRIX        25
#define T_MATFFE        26
#define T_LISTX         27
#define T_VAR           28
#define T_VARAUTO       (T_VAR+ 1)
#define T_VARASS        (T_VAR+ 2)
#define T_LISTELM       (T_VAR+ 3)
#define T_LISTELML      (T_VAR+ 4)
#define T_LISTELMS      (T_VAR+ 5)
#define T_LISTELMSL     (T_VAR+ 6)
#define T_LISTASS       (T_VAR+ 7)
#define T_LISTASSL      (T_VAR+ 8)
#define T_LISTASSS      (T_VAR+ 9)
#define T_LISTASSSL     (T_VAR+10)
#define T_RECELM        (T_VAR+11)
#define T_RECASS        (T_VAR+12)
#define T_SUM           (T_VAR+13)
#define T_DIFF          (T_SUM+ 1)
#define T_PROD          (T_SUM+ 2)
#define T_QUO           (T_SUM+ 3)
#define T_MOD           (T_SUM+ 4)
#define T_POW           (T_SUM+ 5)
#define T_COMM          (T_SUM+ 6)
#define T_NOT           (T_SUM+ 7)
#define T_AND           (T_NOT+ 1)
#define T_OR            (T_NOT+ 2)
#define T_EQ            (T_NOT+ 3)
#define T_NE            (T_NOT+ 4)
#define T_LT            (T_NOT+ 5)
#define T_GE            (T_NOT+ 6)
#define T_LE            (T_NOT+ 7)
#define T_GT            (T_NOT+ 8)
#define T_IN            (T_NOT+ 9)
#define T_FUNCCALL      (T_NOT+10)
#define T_STATSEQ       (T_FUNCCALL+ 1)
#define T_IF            (T_FUNCCALL+ 2)
#define T_FOR           (T_FUNCCALL+ 3)
#define T_WHILE         (T_FUNCCALL+ 4)
#define T_REPEAT        (T_FUNCCALL+ 5)
#define T_RETURN        (T_FUNCCALL+ 6)
#define T_MAKEPERM      (T_FUNCCALL+ 7)
#define T_MAKEFUNC      (T_MAKEPERM+ 1)
#define T_MAKELIST      (T_MAKEPERM+ 2)
#define T_MAKESTRING    (T_MAKEPERM+ 3)
#define T_MAKERANGE     (T_MAKEPERM+ 4)
#define T_MAKEREC       (T_MAKEPERM+ 5)
#define T_CYCLE         (T_MAKEPERM+ 6)
#define T_FF            (T_CYCLE+ 1)
#define T_AGEN          (T_CYCLE+ 2)
#define T_AGGRP         (T_CYCLE+ 3)
#define T_PCPRES        (T_CYCLE+ 4)
#define T_AGEXP         (T_CYCLE+ 5)
#define T_AGLIST        (T_CYCLE+ 6)
#define T_RECNAM        (T_CYCLE+ 7)
#define T_EXEC          (T_CYCLE+ 8)
#define T_FREEBAG       (T_EXEC+ 1)
#define T_ILLEGAL       (T_FREEBAG+ 1)
typedef struct TypHeader {
unsigned long       size;
struct TypHeader    * * ptr;
char                name[3];
unsigned char       type;
}       * TypHandle;
#define SIZE_HD         ((size_t)sizeof(TypHandle))
#define TYPE(HD)        (((long)(HD) & T_INT) ? T_INT : ((HD)->type))
#define SIZE(HD)        ((HD)->size)
#define PTR(HD)         ((TypHandle*)((HD)->ptr))
/**/
TypHandle       HdIdWord;
TypHandle       HdTilde;
TypHandle       HdFields;
unsigned long   Pols [] = {
4, 1+2,
8, 1+2,
16, 1+2,
32, 1  +4,
64, 1+2  +8+16,
128, 1+2,
256, 1  +4+8+16,
512, 1      +16,
1024, 1+2+4+8   +32+64,
2048, 1  +4,
4096, 1+2  +8   +32+64+128,
8192, 1+2  +8+16,
16384, 1    +8   +32   +128,
32768, 1  +4  +16+32,
65536, 1  +4+8   +32,
9,  2 +2*3,
27,  1 +2*3,
81,  2           +2*27,
243,  1 +2*3,
729,  2 +2*3 +1*9       +2*81,
2187,  1      +2*9,
6561,  2 +2*3 +2*9       +1*81 +2*243,
19683,  1 +1*3 +2*9 +2*27,
59049,  2 +1*3            +2*81 +2*243 +2*729,
25,  2 +4*5,
125,  3 +3*5,
625,  2 +4*5 +4*25,
3125,  3 +4*5,
15625,  2      +1*25 +4*125 +1*625,
49,  3 +6*7,
343,  4      +6*49,
2401,  3 +4*7 +5*49,
16807,  4 +1*7,
121,  2 + 7*11,
1331,  9 + 2*11,
14641,  2 +10*11 +8*121,
169,  2 +12*13,
2197, 11 + 2*13,
28561,  2 +12*13 +3*169,
289,  3 +16*17,
4913, 14 + 1*17,
361,  2 +18*19,
6859, 17 + 4*19,
529,  5 +21*23,
12167, 18 + 2*23,
841,  2 +24*29,
24389, 27 + 2*29,
961,  3 +29*31,
29791, 28 + 1*31,
1369,  2 +33*37,
50653, 35 + 6*37,
1681,  6 + 38* 41,
1849,  3 + 42* 43,
2209,  5 + 45* 47,
2809,  2 + 49* 53,
3481,  2 + 58* 59,
3721,  2 + 60* 61,
4489,  2 + 63* 67,
5041,  7 + 69* 71,
5329,  5 + 70* 73,
6241,  3 + 78* 79,
6889,  2 + 82* 83,
7921,  3 + 82* 89,
9409,  5 + 96* 97,
10201,  2 + 97*101,
10609,  5 +102*103,
11449,  2 +103*107,
11881,  6 +108*109,
12769,  3 +101*113,
16129,  3 +126*127,
17161,  2 +127*131,
18769,  3 +131*137,
19321,  2 +138*139,
22201,  2 +145*149,
22801,  6 +149*151,
24649,  5 +152*157,
26569,  2 +159*163,
27889,  5 +166*167,
29929,  2 +169*173,
32041,  2 +172*179,
32761,  2 +177*181,
36481, 19 +190*191,
37249,  5 +192*193,
38809,  2 +192*197,
39601,  3 +193*199,
44521,  2 +207*211,
49729,  3 +221*223,
51529,  2 +220*227,
52441,  6 +228*229,
54289,  3 +232*233,
57121,  7 +237*239,
58081,  7 +238*241,
63001,  6 +242*251,
};
TypHandle       (* EvTab[ T_ILLEGAL ]) P(( TypHandle hd ));
TypHandle       HdExec;
long            IsProfiling;
TypHandle       HdTimes;
unsigned long   Timesum;
/**/
TypHandle       HdRnOp;
TypHandle       HdCall1,  HdCall2;
TypHandle       HdRnSum;
TypHandle       HdStrSum;
TypHandle       HdCallSum;
/**/
TypHandle       HdRnDiff;
TypHandle       HdStrDiff;
TypHandle       HdCallDiff;
TypHandle       HdRnProd;
TypHandle       HdStrProd;
TypHandle       HdCallProd;
TypHandle       HdRnQuo;
TypHandle       HdStrQuo;
TypHandle       HdCallQuo;
TypHandle       HdRnMod;
TypHandle       HdStrMod;
TypHandle       HdCallMod;
TypHandle       HdRnPow;
TypHandle       HdStrPow;
TypHandle       HdCallPow;
TypHandle       HdRnComm;
TypHandle       HdStrComm;
TypHandle       HdCallComm;
TypHandle       HdRnEq;
TypHandle       HdStrEq;
TypHandle       HdCallEq;
TypHandle       HdRnLt;
TypHandle       HdStrLt;
TypHandle       HdCallLt;
TypHandle       HdRnIn;
TypHandle       HdStrIn;
TypHandle       HdCallIn;
TypHandle       HdRnPrint;
TypHandle       HdStrPrint;
TypHandle       HdCallPrint;

TypHandle       HdVoid;
TypHandle       HdReturn;
TypHandle       HdTrue,  HdFalse;
char *          StrStat;
TypHandle       HdStat;
TypHandle       HdIdenttab;
unsigned long   NrIdenttab;
TypHandle       HdStack;
unsigned long   TopStack;
jmp_buf         ErrRet;
TypHandle       HdLast, HdLast2, HdLast3;
TypHandle       HdTime;

static TypHandle      hdRel;
static TypHandle      hdNums;
static TypHandle      hdTable;
static TypHandle      hdTabl2;
static TypHandle      hdNext;
static TypHandle      hdPrev;
static TypHandle      hdFact;
static TypHandle      hdTree;
static TypHandle      hdTree1;
static TypHandle      hdTree2;
static TypHandle      hdExponent;
static TypHandle      hdWordValue;
static long           treeType;
static long           treeWordLength;
static long           firstDef;
static long           lastDef;
static long           firstFree;
static long           lastFree;
static long           nrdel;
static long           dedfst;
static long           dedlst;
static long           dedgen [40960];
static long           dedcos [40960];
static long           dedSize = 40960;
static long           dedprint;
static long           wordList [1024];
static long           wordSize = 1023;
TypHandle               HdResult;
TypHandle               CycLastE;
long                    CycLastN;
unsigned long           Symbol;
char            Value [1024];
long            NrError;
long            NrErrLine;
char            * Prompt;
typedef struct {
long        file;
char        name [64];
char        line [256];
char        * ptr;
long        number;
}       TypInputFile;
TypInputFile    InputFiles [16];
TypInputFile    * Input;
char            * In;
typedef struct {
long        file;
char        line [256];
long        pos;
long        indent;
long        spos;
long        sindent;
}       TypOutputFile;
TypOutputFile   OutputFiles [16];
TypOutputFile   * Output;
long            Logfile = -1;
long            InputLogfile = -1;
long            TestInput  = -1;
long            TestOutput = -1;
char            TestLine [256];
TypHandle       (*TabElmList[T_VAR])  P(( TypHandle, long ));
TypHandle       (*TabElmfList[T_VAR]) P(( TypHandle, long ));
TypHandle       (*TabElmlList[T_VAR]) P(( TypHandle, long ));
TypHandle       (*TabElmrList[T_VAR]) P(( TypHandle, long ));
long            TabIsList [T_VAR];
long            (*TabLenList[T_VAR]) P(( TypHandle ));
char            SyFlags [] = {
#ifdef SYS_IS_BSD
'b', 's', 'd',
# define SYS_BSD        1
#else
# define SYS_BSD        0
#endif
#ifdef SYS_IS_MACH
'm', 'a', 'c', 'h',
# define SYS_MACH       1
#else
# define SYS_MACH       0
#endif
#ifdef SYS_IS_USG
'u', 's', 'g',
# define SYS_USG        1
#else
# define SYS_USG        0
#endif
#ifdef SYS_IS_OS2_EMX
'o', 's', '2', ' ', 'e', 'm', 'x',
# define SYS_OS2_EMX    1
#else
# define SYS_OS2_EMX    0
#endif
#ifdef SYS_IS_MSDOS_DJGPP
'm', 's', 'd', 'o', 's', ' ', 'd', 'j', 'g', 'p', 'p',
# define SYS_MSDOS_DJGPP 1
#else
# define SYS_MSDOS_DJGPP 0
#endif
#ifdef SYS_IS_TOS_GCC2
't', 'o', 's', ' ', 'g', 'c', 'c', '2',
# define SYS_TOS_GCC2   1
#else
# define SYS_TOS_GCC2   0
#endif
#ifdef SYS_IS_VMS
'v', 'm', 's',
# define SYS_VMS        1
#else
# define SYS_VMS        0
#endif
#ifdef __MWERKS__
# define SYS_IS_MAC_MPW
# define SYS_HAS_CALLOC_PROTO
#endif
#ifdef SYS_IS_MAC_MPW
'm', 'a', 'c', ' ', 'm', 'p', 'w',
# define SYS_MAC_MPW    1
#else
# define SYS_MAC_MPW    0
#endif
#ifdef SYS_IS_MAC_SYC
'm', 'a', 'c', ' ', 's', 'y', 'c',
# define SYS_MAC_SYC    1
#else
# define SYS_MAC_SYC    0
#endif
#if __GNUC__
' ', 'g', 'c', 'c',
#endif
#if SYS_ANSI
' ', 'a', 'n', 's', 'i',
#endif
#ifdef SYS_HAS_BROKEN_STRNCAT
' ', 's', 't', 'r', 'n', 'c', 'a', 't',
#endif
'\0' };
#if SYS_TOS_GCC2
# define __NO_INLINE__
int             _stksize = 64 * 1024;
long            SyStackSpace = 64 * 1024;
#endif
#if SYS_MAC_MPW || SYS_MAC_SYC
long            SyStackSpace = 64 * 1024;
#endif
#ifdef _WIN32
char            SyLibname [256] = ".";
#endif
#if SYS_BSD || SYS_MACH || SYS_USG || SYS_OS2_EMX
char            SyLibname [256] = "lib/";
#endif

char            SyLibname [256] = "lib\\";


char            SyHelpname [256];
long            SyBanner = 1;
long            SyQuiet = 0;
long            SyNrCols = 80;
long            SyNrRows = 24;
long            SyGasman = 0;
#ifdef _WIN32
long            SyMemory = 64 * 1024 * 1024;
#endif
#if SYS_BSD || SYS_MACH || SYS_USG || SYS_OS2_EMX
long            SyMemory = 4 * 1024 * 1024;
#endif
#if SYS_MSDOS_DJGPP
long            SyMemory = 4 * 1024 * 1024;
#endif
#if SYS_TOS_GCC2
long            SyMemory = 0;
#endif
#if SYS_VMS
long            SyMemory = 4 * 1024 * 1024;
#endif
#if SYS_MAC_MPW || SYS_MAC_SYC
long            SyMemory = 0;
#endif
char            SyInitfiles [16] [256];
long            syWindow = 0;
unsigned long   syStartTime;
unsigned long   syStopTime;
TypHandle       (*TabEq[T_VAR][T_VAR]) P(( TypHandle, TypHandle ));
TypHandle       HdNewHandles;
unsigned long   NrNewHandles;
TypHandle       (*TabDiff[T_VAR][T_VAR]) P(( TypHandle, TypHandle ));
TypHandle       (*TabProd[T_VAR][T_VAR]) P(( TypHandle, TypHandle ));
TypHandle       (*TabQuo[T_VAR][T_VAR]) P(( TypHandle, TypHandle ));
TypHandle       (*TabMod[T_VAR][T_VAR]) P(( TypHandle, TypHandle ));
TypHandle       (*TabPow[T_VAR][T_VAR]) P(( TypHandle, TypHandle ));
TypHandle       (*TabComm[T_VAR][T_VAR]) P(( TypHandle, TypHandle ));
extern  char            * NameType [];
extern  unsigned long   GasmanStatAlive [T_ILLEGAL];
extern  unsigned long   GasmanStatASize [T_ILLEGAL];
extern  unsigned long   GasmanStatTotal [T_ILLEGAL];
extern  unsigned long   GasmanStatTSize [T_ILLEGAL];
TypHandle       HdCPS,  HdCPL,  HdCPC;
int        CPP = 0;
long            CPN = 1;
TypHandle       (*TabLt[T_VAR][T_VAR]) P(( TypHandle, TypHandle ));
void            (*TabPlainList[T_VAR]) P(( TypHandle ));
long            (*TabIsDenseList[T_VAR]) P(( TypHandle ));
long            (*TabIsPossList[T_VAR]) P(( TypHandle ));
long            (*TabIsXTypeList[T_VAR]) P(( TypHandle ));
TypHandle       (*TabElmsList[T_VAR]) P(( TypHandle, TypHandle ));
TypHandle       (*TabAssList[T_VAR]) P(( TypHandle, long, TypHandle ));
TypHandle       (*TabAsssList[T_VAR]) P(( TypHandle, TypHandle, TypHandle ));
long            (*TabPosList[T_VAR]) P(( TypHandle, TypHandle, long ));
TypHandle       (*TabSum[T_VAR][T_VAR]) P(( TypHandle, TypHandle ));
/* 当前文件是D:\Read\scanner.h*/

#ifdef SPEC_CPU2000_P64
#define long __int64
#endif
#define S_ILLEGAL       (0L)
#define S_IDENT         ((1L<< 3))
#define S_INT           ((1L<< 4))
#define S_CHAR          ((1L<< 5)+0)
#define S_STRING        ((1L<< 5)+1)
#define S_DOT           ((1L<< 6))
#define S_LBRACK        ((1L<< 7)+0)
#define S_RBRACK        ((1L<< 8)+0)
#define S_LBRACE        ((1L<< 7)+1)
#define S_RBRACE        ((1L<< 8)+1)
#define S_LPAREN        ((1L<< 9))
#define S_RPAREN        ((1L<<10))
#define S_COMMA         ((1L<<11)+0)
#define S_DOTDOT        ((1L<<11)+1)
#define S_IF            ((1L<<12)+0)
#define S_THEN          ((1L<<13))
#define S_ELIF          ((1L<<14)+0)
#define S_ELSE          ((1L<<14)+1)
#define S_FI            ((1L<<15))
#define S_FOR           ((1L<<12)+1)
#define S_DO            ((1L<<16))
#define S_OD            ((1L<<17))
#define S_REPEAT        ((1L<<12)+2)
#define S_UNTIL         ((1L<<18))
#define S_WHILE         ((1L<<12)+3)
#define S_ASSIGN        ((1L<<19))
#define S_SEMICOLON     ((1L<<20))
#define S_FUNCTION      ((1L<<21))
#define S_LOCAL         ((1L<<22))
#define S_END           ((1L<<23))
#define S_RETURN        ((1L<<12)+4)
#define S_MAPTO         ((1L<<24))
#define S_NOT           ((1L<<25)+0)
#define S_AND           ((1L<<25)+1)
#define S_OR            ((1L<<25)+2)
#define S_EQ            ((1L<<26)+0)
#define S_LT            ((1L<<26)+1)
#define S_GT            ((1L<<26)+2)
#define S_NE            ((1L<<26)+3)
#define S_LE            ((1L<<26)+4)
#define S_GE            ((1L<<26)+5)
#define S_IN            ((1L<<26)+6)
#define S_PLUS          ((1L<<27)+0)
#define S_MINUS         ((1L<<27)+1)
#define S_MULT          ((1L<<28)+0)
#define S_DIV           ((1L<<28)+1)
#define S_MOD           ((1L<<28)+2)
#define S_POW           ((1L<<28)+3)
#define S_QUIT          ((1L<<29))
#define S_EOF           ((1L<<30))

typedef unsigned long   TypSymbolSet;
#define IS_IN(SYMBOL,SET)       ((SYMBOL) & ((SET) & ~7))
#define EXPRBEGIN  (S_IDENT|S_INT|S_STRING|S_LPAREN|S_FUNCTION)
#define STATBEGIN  (EXPRBEGIN|S_IF|S_FOR|S_WHILE|S_REPEAT|S_RETURN)




void            SyntaxError P(( char * msg ));
void            Match P(( unsigned long symbol, char * msg,
TypSymbolSet skipto ));
void            Pr P(( char * format, long arg1, long arg2 ));
long            OpenInput P(( char * filename ));
long            CloseInput P(( void ));
long            OpenOutput P(( char * filename ));
long            CloseOutput P(( void ));
long            OpenAppend P(( char * filename ));
long            CloseAppend P(( void ));
long            OpenLog P(( char * filename ));
long            CloseLog P(( void ));
long            OpenInputLog P(( char* ));
long            CloseInputLog P(( void ));
long            OpenTest P(( char * filename ));
long            CloseTest P(( void ));
void            InitScanner P(( void ));
/* 当前文件是D:\Read\eval.h*/

#ifdef SPEC_CPU2000_P64
#define long __int64
#endif
#define EVAL(hd)        ((long)(hd)&T_INT ? (hd) : (* EvTab[TYPE(hd)])((hd)))
#define SUM(hdL,hdR)    ((*TabSum[TYPE(hdL)][TYPE(hdR)])((hdL),(hdR)))
#define DIFF(hdL,hdR)   ((*TabDiff[TYPE(hdL)][TYPE(hdR)])((hdL),(hdR)))
#define PROD(hdL,hdR)   ((*TabProd[TYPE(hdL)][TYPE(hdR)])((hdL),(hdR)))
#define QUO(hdL,hdR)    ((*TabQuo[TYPE(hdL)][TYPE(hdR)])((hdL),(hdR)))
#define MOD(hdL,hdR)    ((*TabMod[TYPE(hdL)][TYPE(hdR)])((hdL),(hdR)))
#define POW(hdL,hdR)    ((*TabPow[TYPE(hdL)][TYPE(hdR)])((hdL),(hdR)))
#define EQ(hdL,hdR)     ((*TabEq[TYPE(hdL)][TYPE(hdR)])((hdL),(hdR)))
#define LT(hdL,hdR)     ((*TabLt[TYPE(hdL)][TYPE(hdR)])((hdL),(hdR)))

/* 当前文件是D:\Read\integer.h*/

#define INT_TO_HD(INT)  ((TypHandle) (((long)(INT) << 2) + T_INT))
#define HD_TO_INT(HD)   (((long)HD) >> 2)
typedef unsigned short  TypDigit;
TypHandle       EvInt P(( TypHandle hdInt ));
TypHandle       SumInt P(( TypHandle hdL, TypHandle hdR ));
TypHandle       DiffInt P(( TypHandle hdL, TypHandle hdR ));
TypHandle       ProdInt P(( TypHandle hdL, TypHandle hdR ));
TypHandle       ModInt P(( TypHandle hdL, TypHandle hdR ));
TypHandle       PowInt P(( TypHandle hdL, TypHandle hdR ));
TypHandle       EqInt P(( TypHandle hdL, TypHandle hdR ));
TypHandle       LtInt P(( TypHandle hdL, TypHandle hdR ));
void            PrInteger P(( TypHandle hdInt ));
TypHandle       FunIsInt P(( TypHandle hdCall ));
TypHandle       QuoInt P(( TypHandle hdL, TypHandle hdR ));
TypHandle       FunQuo P(( TypHandle hdCall ));
TypHandle       RemInt P(( TypHandle hdL, TypHandle hdR ));
TypHandle       FunRem P(( TypHandle hdCall ));
TypHandle       GcdInt P(( TypHandle hdL, TypHandle hdR ));
TypHandle       FunGcdInt P(( TypHandle hdCall ));
void            InitInt P(( void ));
/* 当前文件是D:\Read\idents.h*/

#ifdef SPEC_CPU2000_P64
#define long __int64
#endif

/* 当前文件是D:\Read\read.h*/

TypHandle       ReadIt P(( void ));
/* 当前文件是D:\Read\list.h*/

#ifdef SPEC_CPU2000_P64
#define long __int64
#endif
#define IS_LIST(LIST)           (TabIsList[TYPE(LIST)] != 0)

#define LEN_LIST(LIST)          ((*TabLenList[TYPE(LIST)])(LIST))
#define ELM_LIST(LIST,POS)      ((*TabElmList[TYPE(LIST)])(LIST,POS))
#define ELMF_LIST(LIST,POS)     ((*TabElmfList[TYPE(LIST)])(LIST,POS))
#define ELML_LIST(LIST,POS)     ((*TabElmlList[TYPE(LIST)])(LIST,POS))
#define ELMR_LIST(LIST,POS)     ((*TabElmrList[TYPE(LIST)])(LIST,POS))
#define ELMS_LIST(LIST,POSS)    ((*TabElmsList[TYPE(LIST)])(LIST,POSS))
#define ASS_LIST(LIST,POS,VAL)  ((*TabAssList[TYPE(LIST)])(LIST,POS,VAL))
#define ASSS_LIST(LI,POSS,VALS) ((*TabAsssList[TYPE(LI)])(LI,POSS,VALS))
#define POS_LIST(LIST,VAL,START)  ((*TabPosList[TYPE(LIST)])(LIST,VAL,START))
#define PLAIN_LIST(LIST)          ((*TabPlainList[TYPE(LIST)])(LIST))

#define IS_DENSE_LIST(LIST)     ((*TabIsDenseList[TYPE(LIST)])(LIST))
#define IS_POSS_LIST(LIST)      ((*TabIsPossList[TYPE(LIST)])(LIST))
#define IS_XTYPE_LIST(T,LIST)   ((*TabIsXTypeList[T])(LIST))

/* 当前文件是D:\Read\plist.h*/

#ifdef SPEC_CPU2000_P64
#define long __int64
#endif
#define PLEN_SIZE_PLIST(SIZE)           (((SIZE) - SIZE_HD) / SIZE_HD)
#define SIZE_PLEN_PLIST(PLEN)           (SIZE_HD + (PLEN) * SIZE_HD)
#define LEN_PLIST(LIST)                 (HD_TO_INT(PTR(LIST)[0]))
#define SET_LEN_PLIST(LIST,LEN)         (PTR(LIST)[0] = INT_TO_HD(LEN))
#define ELM_PLIST(LIST,POS)             (PTR(LIST)[POS])
#define SET_ELM_PLIST(LIST,POS,VAL)     (PTR(LIST)[POS] = (VAL))

/* 当前文件是D:\Read\string.h*/

#ifdef SPEC_CPU2000_P64
#define long __int64
#endif

#define SIZE_PLEN_STRING(PLEN)          (PLEN + 1L)
#define LEN_STRING(LIST)                (SIZE(LIST)-1)
#define ELM_STRING(LIST,POS)    (HdChars[((unsigned char*)PTR(LIST))[POS-1]])

/* 当前文件是D:\Read\statemen.h*/

TypHandle       EvStatseq P(( TypHandle hdSSeq ));
TypHandle       EvIf P(( TypHandle hdIf ));
TypHandle       EvFor P(( TypHandle hdFor ));
TypHandle       EvWhile P(( TypHandle hdWhile ));
TypHandle       EvRepeat P(( TypHandle hdRep ));
void            PrStatseq P(( TypHandle hdSSeq ));
void            PrIf P(( TypHandle hdIf ));
void            PrFor P(( TypHandle hdFor ));
void            PrWhile P(( TypHandle hdWhile ));
void            PrRepeat P(( TypHandle hdRep ));
void            InitStat P(( void ));
/* 当前文件是D:\Read\function.h*/

void            ChangeEnv P(( TypHandle hdEnv ));
TypHandle       EvFunccall P(( TypHandle hdCall ));
TypHandle       EvFunction P(( TypHandle hdDef ));
TypHandle       EvMakefunc P(( TypHandle hdFun ));
TypHandle       EvReturn P(( TypHandle hdRet ));
TypHandle       FunTrace P(( TypHandle hdCall ));
TypHandle       FunUntrace P(( TypHandle hdCall ));
TypHandle       FunProfile P(( TypHandle hdCall ));
void            PrFuncint P(( TypHandle hdFun ));
void            PrFunction P(( TypHandle hdFun ));
void            PrintFunction P(( TypHandle hdFun ));
void            PrFunccall P(( TypHandle hdCall ));
void            PrReturn P(( TypHandle hdRet ));
void            InitFunc P(( void ));
/* 当前文件是D:\Read\record.h*/

#ifdef SPEC_CPU2000_P64
#define long __int64
#endif



TypHandle       FunBacktrace ( hdCall )
TypHandle           hdCall;
{
short               level,  nrArg,  nrLoc,  i;
TypHandle           hdExec, hdDef;
if ( hdCall == 0 || SIZE(hdCall) == SIZE_HD ) {
level = 5;
}
else if ( SIZE(hdCall) == 2 * SIZE_HD ) {
hdDef = EVAL( PTR(hdCall)[1] );
if ( TYPE(hdDef) != T_INT )
return Error("usage: Backtrace( <level> )",0L,0L);
else
level = HD_TO_INT( hdDef );
}
else {
return Error("usage: Backtrace( <level> )",0L,0L);
}
for ( hdExec=HdExec; hdExec!=0 && level!=0; hdExec=PTR(hdExec)[4] ) {
if ( 0 < level ) {
if ( PTR(hdExec)[3] == HdCallSum )
Pr("<rec1> + <rec2> called from\n",0L,0L);
else if ( PTR(hdExec)[3] == HdCallDiff )
Pr("<rec1> - <rec2> called from\n",0L,0L);
else if ( PTR(hdExec)[3] == HdCallProd )
Pr("<rec1> * <rec2> called from\n",0L,0L);
else if ( PTR(hdExec)[3] == HdCallQuo )
Pr("<rec1> / <rec2> called from\n",0L,0L);
else if ( PTR(hdExec)[3] == HdCallMod )
Pr("<rec1> mod <rec2> called from\n",0L,0L);
else if ( PTR(hdExec)[3] == HdCallPow )
Pr("<rec1> ^ <rec2> called from\n",0L,0L);
else if ( PTR(hdExec)[3] == HdCallComm )
Pr("Comm(<rec1>,<rec2>) called from\n",0L,0L);
else if ( PTR(hdExec)[3] == HdCallEq )
Pr("<rec1> = <rec2> called from\n",0L,0L);
else if ( PTR(hdExec)[3] == HdCallLt )
Pr("<rec1> < <rec2> called from\n",0L,0L);
else if ( PTR(hdExec)[3] == HdCallIn )
Pr("<elm> in <rec> called from\n",0L,0L);
else if ( PTR(hdExec)[3] == HdCallPrint )
Pr("Print( <rec> ) called from\n",0L,0L);
else {
Print( PTR(hdExec)[3] );
Pr(" called from\n",0L,0L);
}
--level;
}
else {
if ( PTR(hdExec)[3] == HdCallSum )
Pr("<rec1> + <rec2> called from\n",0L,0L);
else if ( PTR(hdExec)[3] == HdCallDiff )
Pr("<rec1> - <rec2> called from\n",0L,0L);
else if ( PTR(hdExec)[3] == HdCallProd )
Pr("<rec1> * <rec2> called from\n",0L,0L);
else if ( PTR(hdExec)[3] == HdCallQuo )
Pr("<rec1> / <rec2> called from\n",0L,0L);
else if ( PTR(hdExec)[3] == HdCallMod )
Pr("<rec1> mod <rec2> called from\n",0L,0L);
else if ( PTR(hdExec)[3] == HdCallPow )
Pr("<rec1> ^ <rec2> called from\n",0L,0L);
else if ( PTR(hdExec)[3] == HdCallComm )
Pr("Comm(<rec1>,<rec2>) called from\n",0L,0L);
else if ( PTR(hdExec)[3] == HdCallEq )
Pr("<rec1> = <rec2> called from\n",0L,0L);
else if ( PTR(hdExec)[3] == HdCallLt )
Pr("<rec1> < <rec2> called from\n",0L,0L);
else if ( PTR(hdExec)[3] == HdCallIn )
Pr("<elm> in <rec> called from\n",0L,0L);
else if ( PTR(hdExec)[3] == HdCallPrint )
Pr("Print( <rec> ) called from\n",0L,0L);
else {
Print( PTR( PTR(hdExec)[3] )[0] );
Pr("%>( %>",0L,0L);
hdDef = EVAL( PTR( PTR(hdExec)[3] )[0] );
nrArg = ((short*)((char*)PTR(hdDef)+SIZE(hdDef)))[-2];
if ( nrArg == -1 )  nrArg = 1;
nrLoc = ((short*)((char*)PTR(hdDef)+SIZE(hdDef)))[-1];
if ( nrLoc < 0 )  nrLoc = -nrLoc-1;
for ( i = 1; i <= nrArg; ++i ) {
Print( PTR(hdExec)[i+nrArg+nrLoc+4] );
if ( i < nrArg )  Pr("%<, %>",0L,0L);
}
Pr(" %2<) called from\n",0L,0L);
}
++level;
}
}
if ( hdExec == 0 ) {
Pr("main loop\n",0L,0L);
}
else {
Pr("...\n",0L,0L);
}
return HdVoid;
}
TypHandle       Error ( msg, arg1, arg2 )
char                msg [];
long                arg1, arg2;
{
TypHandle           hd;
long                i;
long                ignore;




ignore = OpenOutput( "*errout*" );
if ( SyStrcmp( msg, "FunError" ) != 0 ) {
Pr("Error, ",0L,0L);  Pr( msg, arg1, arg2 );
}
else {
Pr("Error, ",0L,0L);  FunPrint( (TypHandle)arg1 );
}
if ( HdExec != 0 ) {
if ( HdStat != 0 && SyStrcmp( msg, "FunError" ) != 0 ) {
Pr(" at\n%s", (long)StrStat, 0L );
Print( HdStat );
Pr(" ...",0L,0L);
}
Pr(" in\n",0L,0L);
FunBacktrace( (TypHandle)0 );
}
else {
Pr("\n",0L,0L);
}
if ( HdExec != 0 && OpenInput( "*errin*" ) ) {
hd = HdExec;  TopStack = 0;
while ( hd != 0 && TopStack+1 < SIZE(HdStack)/SIZE_HD ) {
++TopStack;
hd = PTR(hd)[4];
}
hd = HdExec;  i = 0;
while ( hd != 0 && TopStack-i+1 > 0 ) {
++i;
PTR(HdStack)[TopStack-i+1] = PTR(hd)[2];
hd = PTR(hd)[4];
}
while ( Symbol != S_EOF ) {
Prompt = "brk> ";
EnterKernel();
NrError = 0;
hd = ReadIt();
if ( hd != 0 ) {
SyIsIntr();
hd = EVAL( hd );
if ( hd == HdReturn && PTR(hd)[0] != HdReturn ) {
while ( TopStack >= 1 )
PTR(HdStack)[TopStack--] = 0;
ExitKernel( hd );
ignore = CloseInput();
ignore = CloseOutput();
return PTR(hd)[0];
}
else if ( hd == HdReturn ) {
hd = HdVoid;
Symbol = S_EOF;
}
if ( TYPE(hd) != T_VOID ) {
PTR(HdLast)[0]  = hd;
if ( *In != ';' ) {
Print( hd );
Pr("\n",0L,0L);
}
}
}
ExitKernel( (TypHandle)0 );
}
while ( TopStack >= 1 )
PTR(HdStack)[TopStack--] = 0;
ignore = CloseInput();
}
ExitKernel( (TypHandle)2 );
while ( HdExec != 0 )  ChangeEnv( PTR(HdExec)[4] );
while ( CloseOutput() ) ;
while ( CloseInput() ) ;
longjmp( ErrRet, 1 );
return 0;
}
TypHandle       FunIgnore( hdCall )
TypHandle       hdCall;
{
return HdVoid;
}
TypHandle       FunError ( hdCall )
TypHandle           hdCall;
{
return Error("FunError", (long)hdCall, 0L );
}
TypHandle	FunWindowCmd ( hdCall )
TypHandle	    hdCall;
{
TypHandle       hdStr;
TypHandle       hdTmp;
TypHandle       hdCmd;
TypHandle       hdLst;
long            len;
long            n,  m;
long            i;
char          * ptr;
char          * qtr;
if ( SIZE(hdCall) != 2*SIZE_HD )
	return Error( "usage: WindowCmd( <cmds> )", 0L, 0L );
hdCmd = EVAL(PTR(hdCall)[1]);
if ( !IsList(hdCmd) )
	return Error( "usage: WindowCmd( <cmds> )", 0L, 0L );
hdTmp = ELM_LIST(hdCmd,1);
if ( TYPE(hdTmp) != T_STRING )
	return Error( "<cmd> must be a string", 0L, 0L );
if ( SIZE(hdTmp) != 4 )
	return Error( "<cmd> is not a valid command", 0L, 0L );
len   = 13;
hdLst = NewBag( T_LIST, (LEN_LIST(hdCmd)+1)*SIZE_HD );
for ( i = LEN_LIST(hdCmd);  1 < i;  i-- )
{
	hdTmp = ELM_LIST(hdCmd,i);
	if ( TYPE(hdTmp) != T_INT && ! IsString(hdTmp) )
	    return Error("%d.th argument must be a string or integer",i,0L);
	PTR(hdLst)[i] = hdTmp;
	if ( TYPE(hdTmp) == T_INT )
	    len += 12;
	else
	    len += 5 + 2*SIZE(hdTmp);
}
hdStr  = NewBag( T_STRING, len + 13 );
ptr    = (char*) PTR(hdStr);
*ptr   = '\0';
SyStrncat( ptr, (char*)PTR(ELM_LIST(hdCmd,1)), 3 );
ptr += 3;
for ( i = 2;  i < SIZE(hdLst)/SIZE_HD;  i++ )
{
	hdTmp = PTR(hdLst)[i];
	if ( TYPE(hdTmp) == T_INT )
	{
	    *ptr++ = 'I';
	    m = HD_TO_INT(hdTmp);
	    for ( m = (m<0)?-m:m;  0 < m;  m /= 10 )
		*ptr++ = (m%10) + '0';
	    if ( HD_TO_INT(hdTmp) < 0 )
		*ptr++ = '-';
	    else
		*ptr++ = '+';
	}
	else
	{
	    *ptr++ = 'S';
	    m = SIZE(hdTmp)-1;
	    for ( n = 7;  0 <= n;  n--, m /= 10 )
		*ptr++ = (m%10) + '0';
	    qtr = (char*) PTR(hdTmp);
	    for ( m = SIZE(hdTmp)-1;  0 < m;  m-- )
		*ptr++ = *qtr++;
	}
}
*ptr = 0;
qtr = (char*) PTR(hdStr);
len = (long)(ptr - qtr);
ptr = SyWinCmd( qtr, len );
len = SyStrlen(ptr);
hdLst = NewBag( T_LIST, SIZE_PLEN_PLIST(11) );
SET_LEN_PLIST( hdLst, 0 );
i = 1;
while ( 0 < len )
{
	if ( *ptr == 'I' )
	{
	    ptr++;
	    for ( n=0,m=1; '0' <= *ptr && *ptr <= '9'; ptr++,m *= 10,len-- )
		n += (*ptr-'0') * m;
	    if ( *ptr++ == '-' )
		n *= -1;
	    len -= 2;
	    AssPlist( hdLst, i, INT_TO_HD(n) );
	}
	else if ( *ptr == 'S' )
	{
	    ptr++;
	    for ( n = 0, m = 7;  0 <= m;  m-- )
		n = n*10 + (ptr[m]-'0');
	    hdTmp = NewBag( T_STRING, n+1 );
	    *(char*)PTR(hdTmp) = '\0';
	    ptr += 8;
	    SyStrncat( (char*)PTR(hdTmp), ptr, n );
	    ptr += n;
	    len -= n+9;
	    AssPlist( hdLst, i, hdTmp );
	}
	else
	    return Error( "unknown return value '%s'", (long)ptr, 0 );
	i++;
}
if ( ELM_LIST(hdLst,1) == INT_TO_HD(1) )
{
	hdStr = NewBag( T_STRING, 30 );
	SyStrncat( (char*) PTR(hdStr), "window system: ", 15 );
	SET_ELM_PLIST( hdLst, 1, hdStr );
	Resize( hdLst, i*SIZE_HD );
	return Error( "FunError", (long)hdLst, 0L );
}
else
{
	for ( m = 1;  m <= i-2;  m++ )
	    SET_ELM_PLIST( hdLst,m, ELM_LIST(hdLst,m+1) );
	SET_LEN_PLIST( hdLst, i-2 );
	return hdLst;
}
}
TypHandle       FunREAD ( hdCall )
TypHandle           hdCall;
{
TypHandle           hd,  hdName,  hdOld;
if ( SIZE(hdCall) != 2*SIZE_HD )
return Error("usage: READ( <filename> )",0L,0L);
hdName = EVAL( PTR(hdCall)[1] );
if ( ! IsString(hdName) )
return Error("usage: READ( <filename> )",0L,0L);
if ( ! OpenInput( (char*)PTR(hdName) ) )
return HdFalse;
hdOld = HdExec;  HdExec = 0;
while ( Symbol != S_EOF ) {
EnterKernel();
hd = ReadIt();
if ( hd != 0 )  hd = EVAL( hd );
if ( hd == HdReturn && PTR(hd)[0] != HdReturn )
return Error("READ: 'return' must not be used here",0L,0L);
else if ( hd == HdReturn )
return Error("READ: 'quit' must not be used here",0L,0L);
ExitKernel( (TypHandle)0 );
}
HdExec = hdOld;
if ( ! CloseInput() )
Error("READ: can not close input, this should not happen",0L,0L);
return HdTrue;
}
TypHandle       FunAUTO ( hdCall )
TypHandle           hdCall;
{
TypHandle           hdExpr,  hdVar;
long                i;
if ( SIZE(hdCall) < 3 * SIZE_HD )
return Error("usage: AUTO( <expr>, <var>, <var>... )",0L,0L);
hdExpr = PTR(hdCall)[1];
for ( i = 2; i < SIZE(hdCall)/SIZE_HD; ++i ) {
hdVar = PTR(hdCall)[i];
if ( TYPE(hdVar) != T_VAR && TYPE(hdVar) != T_VARAUTO )
return Error("usage: AUTO( <expr>, <var>, <var>... )",0L,0L);
Retype( hdVar, T_VARAUTO );
PTR(hdVar)[0] = hdExpr;
}
return HdVoid;
}
TypHandle       FunPrint ( hdCall )
TypHandle           hdCall;
{
TypHandle           hd;
long                i;
for ( i = 1; i < SIZE(hdCall)/SIZE_HD; ++i ) {
hd = EVAL( PTR(hdCall)[i] );
if ( IsString( hd ) && TYPE(hd) == T_STRING )  PrintString( hd );
else if ( TYPE( hd ) == T_MAKEFUNC )           PrintFunction( hd );
else if ( TYPE( hd ) == T_FUNCTION )           PrintFunction( hd );
else if ( TYPE( hd ) != T_VOID )               Print( hd );
else  hd = Error("function must return a value",0L,0L);
}
return HdVoid;
}
TypHandle       FunPrntTo ( hdCall )
TypHandle           hdCall;
{
TypHandle           hd;
long                i;
if ( SIZE(hdCall) == SIZE_HD )
return Error("usage: PrintTo( <file>, <obj>, <obj>... )",0L,0L);
hd = EVAL( PTR(hdCall)[1] );
if ( ! IsString(hd) )
return Error("usage: PrintTo( <file>, <obj>, <obj>... )",0L,0L);
if ( OpenOutput( (char*)PTR(hd) ) == 0 )
return Error("PrintTo: can not open the file for writing",0L,0L);
for ( i = 2; i < SIZE(hdCall)/SIZE_HD; ++i ) {
hd = EVAL( PTR(hdCall)[i] );
if ( IsString( hd ) && TYPE(hd) == T_STRING )  PrintString( hd );
else if ( TYPE( hd ) == T_MAKEFUNC )           PrintFunction( hd );
else if ( TYPE( hd ) == T_FUNCTION )           PrintFunction( hd );
else if ( TYPE( hd ) != T_VOID )               Print( hd );
else                                           Pr("",0L,0L);
}
if ( ! CloseOutput() )
Error("PrintTo: can not close output, this should not happen",0L,0L);
return HdVoid;
}
TypHandle       FunAppendTo ( hdCall )
TypHandle           hdCall;
{
TypHandle           hd;
long                i;
if ( SIZE(hdCall) == SIZE_HD )
return Error("usage: AppendTo( <file>, <obj>, <obj>... )",0L,0L);
hd = EVAL( PTR(hdCall)[1] );
if ( ! IsString(hd) )
return Error("usage: AppendTo( <file>, <obj>, <obj>... )",0L,0L);
if ( OpenAppend( (char*)PTR(hd) ) == 0 )
return Error("AppendTo: can not open the file for appending",0L,0L);
for ( i = 2; i < SIZE(hdCall)/SIZE_HD; ++i ) {
hd = EVAL( PTR(hdCall)[i] );
if ( IsString( hd ) && TYPE(hd) == T_STRING )  PrintString( hd );
else if ( TYPE( hd ) == T_MAKEFUNC )           PrintFunction( hd );
else if ( TYPE( hd ) == T_FUNCTION )           PrintFunction( hd );
else if ( TYPE( hd ) != T_VOID )               Print( hd );
else                                           Pr("",0L,0L);
}
if ( ! CloseOutput() )
Error("AppendTo: can not close output, this should not happen",0L,0L);
return HdVoid;
}
TypHandle       FunLogTo ( hdCall )
TypHandle           hdCall;
{
TypHandle           hdName;
if ( SIZE(hdCall) == SIZE_HD ) {
if ( ! CloseLog() )
return Error("LogTo: can not close the logfile",0L,0L);
}
else if ( SIZE(hdCall) == 2 * SIZE_HD ) {
hdName = EVAL( PTR(hdCall)[1] );
if ( ! IsString(hdName) )
return Error("usage: LogTo() or LogTo( <string> )",0L,0L);
if ( ! OpenLog( (char*)PTR(hdName) ) )
return Error("LogTo: can not log to %s",(long)PTR(hdName),0L);
}
return HdVoid;
}
TypHandle       FunLogInputTo ( hdCall )
TypHandle           hdCall;
{
TypHandle           hdName;
if ( SIZE(hdCall) == SIZE_HD ) {
if ( ! CloseInputLog() )
return Error("LogInputTo: can not close the logfile",0L,0L);
}
else if ( SIZE(hdCall) == 2 * SIZE_HD ) {
hdName = EVAL( PTR(hdCall)[1] );
if ( ! IsString(hdName) )
return Error("usage: LogInputTo() or LogTo( <string> )",0L,0L);
if ( ! OpenInputLog( (char*)PTR(hdName) ) )
return Error("LogInputTo: cannot log to %s",(long)PTR(hdName),0L);
}
return HdVoid;
}
TypHandle       FunReadTest ( hdCall )
TypHandle           hdCall;
{
TypHandle           hd,  hdName,  hdOld;
unsigned long       start;

if ( SIZE(hdCall) != 2*SIZE_HD )
return Error("usage: ReadTest( <filename> )",0L,0L);
hdName = EVAL( PTR(hdCall)[1] );
if ( ! IsString(hdName) )
return Error("usage: ReadTest( <filename> )",0L,0L);
if ( ! OpenTest( (char*)PTR(hdName) ) )
return Error("ReadTest: file '%s' must exist and be readable\n",
(long)PTR(hdName), 0L );
start = SyTime();
hdOld = HdExec;  HdExec = 0;
while ( Symbol != S_EOF ) {
EnterKernel();
hd = ReadIt();
if ( hd != 0 ) {
hd = EVAL( hd );
if ( hd == HdReturn && PTR(hd)[0] != HdReturn )
return Error("ReadTest: 'return' must not be used",0L,0L);
else if ( hd == HdReturn )
return Error("ReadTest: 'quit' must not be used",0L,0L);
PTR(HdTime)[0]  = INT_TO_HD( SyTime() - start );
if ( TYPE(hd) != T_VOID ) {
if ( *In != ';' ) {
IsString( hd );
Print( hd );
Pr("\n",0L,0L);
}
}
}
ExitKernel( (TypHandle)0 );
}
HdExec = hdOld;
if ( ! CloseTest() )
Error("ReadTest: can not close input, this should not happen",0L,0L);
return HdVoid;
}
TypHandle       FunHelp ( hdCall )
TypHandle           hdCall;
{
return Error("Help: not yet implemented",0L,0L);
}
TypHandle       FunExec ( hdCall )
TypHandle           hdCall;
{
TypHandle           hdCmd;
if ( SIZE(hdCall) != 2*SIZE_HD )
return Error("usage: Exec( <command> )",0L,0L);
hdCmd = EVAL( PTR(hdCall)[1] );
if ( ! IsString(hdCmd) )
return Error("usage: Exec( <command> )",0L,0L);
SyExec( (char*)PTR(hdCmd) );
return HdVoid;
}
TypHandle       FunRuntime ( hdCall )
TypHandle           hdCall;
{
if ( SIZE(hdCall) != SIZE_HD )
return Error("usage: Runtime()",0L,0L);
return INT_TO_HD( SyTime() );
}
TypHandle       FunSizeScreen ( hdCall )
TypHandle           hdCall;
{
TypHandle           hdSize;
long                len;
long                nr;
if ( SIZE(hdCall) != SIZE_HD && SIZE(hdCall) != 2*SIZE_HD )
return Error("usage: SizeScreen() or SizeScreen([<x>,<y>])",0L,0L);
if ( SIZE(hdCall) == SIZE_HD ) {
hdSize = NewBag( T_LIST, SIZE_PLEN_PLIST(0) );
SET_LEN_PLIST( hdSize, 0 );
}
else {
hdSize = EVAL( PTR(hdCall)[1] );
if ( ! IS_LIST(hdSize) || 2 < LEN_LIST(hdSize) )
return Error("usage: SizeScreen() or SizeScreen([<x>,<y>])",0L,0L);
}
if ( LEN_LIST(hdSize) < 1 || ELMF_LIST(hdSize,1) == 0 ) {
len = SyNrCols;
}
else {
if ( TYPE( ELMF_LIST(hdSize,1) ) != T_INT )
return Error("SizeScreen: <x> must be an integer",0L,0L);
len = HD_TO_INT( ELMF_LIST(hdSize,1) );
if ( len < 20  )  len = 20;
if ( 256 < len )  len = 256;
}
if ( LEN_LIST( hdSize ) < 2 || ELMF_LIST(hdSize,2) == 0 ) {
nr = SyNrRows;
}
else {
if ( TYPE( ELMF_LIST(hdSize,2) ) != T_INT )
return Error("SizeScreen: <y> must be an integer",0L,0L);
nr = HD_TO_INT( ELMF_LIST(hdSize,2) );
if ( nr < 10 )  nr = 10;
}
SyNrCols = len;
SyNrRows = nr;
hdSize = NewBag( T_LIST, SIZE_PLEN_PLIST(2) );
SET_LEN_PLIST( hdSize, 2 );
SET_ELM_PLIST( hdSize, 1, INT_TO_HD(len) );
SET_ELM_PLIST( hdSize, 2, INT_TO_HD(nr) );
return hdSize;
}
TypHandle	FunTmpName ( hdCall )
TypHandle       hdCall;
{
TypHandle       hdStr;
char          * str;
if ( SIZE(hdCall) != SIZE_HD )
	return Error( "usage: TmpName()", 0L, 0L );
str = SyTmpname();
if ( str == (char*)0 )
	return HdFalse;
hdStr = NewBag( T_STRING, SyStrlen(str)+1 );
*((char*)PTR(hdStr)) = 0;
SyStrncat( (char*)PTR(hdStr), str, SyStrlen(str) );
return hdStr;
}
TypHandle       FunIsIdentical ( hdCall )
TypHandle           hdCall;
{
TypHandle           hdL;
TypHandle           hdR;
if ( SIZE(hdCall) != 3*SIZE_HD )
return Error( "usage: IsIdentical( <l>, <r> )", 0L, 0L );
hdL = EVAL( PTR(hdCall)[1] );
hdR = EVAL( PTR(hdCall)[2] );
if ( TYPE(hdL) < T_LIST && TYPE(hdR) < T_LIST )
	return EQ( hdL, hdR );
else if ( TYPE(hdL) < T_LIST || TYPE(hdR) < T_LIST )
	return HdFalse;
else
	return ( hdL == hdR ) ? HdTrue : HdFalse;
}
TypHandle       FunHANDLE ( hdCall )
TypHandle           hdCall;
{
TypHandle           hdHD;
TypHandle           hdObj;
if ( SIZE(hdCall) != 2*SIZE_HD )
return Error("usage: HANDLE( <obj> )",0L,0L);
hdObj = EVAL( PTR(hdCall)[1] );
hdHD  = INT_TO_HD( (long)hdObj );
if ( HD_TO_INT(hdHD) != (long)hdObj )
return Error("HANDLE: %d does not fit into 28 bits",(long)hdObj,0L);
return hdHD;
}
TypHandle       FunOBJ ( hdCall )
TypHandle           hdCall;
{
TypHandle           hdObj;
TypHandle           hdHD;
if ( SIZE(hdCall) != 2*SIZE_HD )
return Error("usage: OBJ( <hd> )",0L,0L);
hdHD = EVAL( PTR(hdCall)[1] );
if ( TYPE( hdHD ) != T_INT )
return Error("OBJ: <hd> must be a small integer",0L,0L);
hdObj = (TypHandle)HD_TO_INT( hdHD );
return hdObj;
}
TypHandle       FunTYPE ( hdCall )
TypHandle           hdCall;
{
TypHandle           hdType;
TypHandle           hdObj;
if ( SIZE(hdCall) != 2*SIZE_HD )
return Error("usage: TYPE( <obj> )",0L,0L);
hdObj  = EVAL( PTR(hdCall)[1] );
if ( hdObj == 0 ) {
hdType = NewBag( T_STRING, 5 );
SyStrncat( (char*)PTR(hdType), "null", 4 );
}
else {
hdType = NewBag( T_STRING, SyStrlen(NameType[TYPE(hdObj)])+1 );
SyStrncat( (char*)PTR(hdType), NameType[TYPE(hdObj)],
SyStrlen(NameType[TYPE(hdObj)])+1 );
}
return hdType;
}
void            MarkObj ( hdObj )
TypHandle           hdObj;
{
unsigned long       i;
if ( hdObj == 0 || TYPE(hdObj) == T_INT )
return;
if ( T_ILLEGAL <= TYPE(hdObj) )
return;
hdObj->type += T_ILLEGAL;
for ( i = NrHandles( (hdObj->type)-T_ILLEGAL, SIZE(hdObj) ); 0 < i; i-- )
MarkObj( PTR(hdObj)[i-1] );
}
unsigned long   SizeObj ( hdObj )
TypHandle           hdObj;
{
unsigned long       size;
unsigned long       i;
if ( hdObj == 0 || TYPE(hdObj) == T_INT )
return 0L;
if ( TYPE(hdObj) < T_ILLEGAL )
return 0L;
hdObj->type -= T_ILLEGAL;
size = SIZE( hdObj );
for ( i = NrHandles( TYPE(hdObj), SIZE(hdObj) ); 0 < i; i-- )
size += SizeObj( PTR(hdObj)[i-1] );
return size;
}
TypHandle       FunSIZE ( hdCall )
TypHandle           hdCall;
{
unsigned long       size;
TypHandle           hdObj;
if ( SIZE(hdCall) != 2*SIZE_HD )
return Error("usage: SIZE( <obj> )",0L,0L);
hdObj  = EVAL( PTR(hdCall)[1] );
MarkObj( hdObj );
size = SizeObj( hdObj );
return INT_TO_HD( size );
}
TypHandle       FunGASMAN ( hdCall )
TypHandle           hdCall;
{
TypHandle           hdCmd;
unsigned long       i,  k;
if ( SIZE(hdCall) == SIZE_HD )
return Error(
"usage: GASMAN( \"display\"|\"clear\"|\"collect\"|\"message\" )",
0L,0L);
for ( i = 1; i < SIZE(hdCall)/SIZE_HD; i++ ) {
hdCmd = EVAL( PTR(hdCall)[i] );
if ( ! IsString(hdCmd) )
return Error(
"usage: GASMAN( \"display\"|\"clear\"|\"collect\"|\"message\" )",
0L,0L);
if ( SyStrcmp( (char*)PTR(hdCmd), "display" ) == 0 ) {
Pr("\t\t    type     alive     size     total     size\n",0L,0L);
for ( k = T_VOID; k < T_ILLEGAL-1; k++ ) {
Pr("%24s  ", (long)NameType[k], 0L );
Pr("%8d %8d  ",(long)GasmanStatAlive[k],
(long)GasmanStatASize[k]);
Pr("%8d %8d\n",(long)GasmanStatTotal[k],
(long)GasmanStatTSize[k]);
}
}
else if ( SyStrcmp( (char*)PTR(hdCmd), "clear" ) == 0 ) {
for ( k = T_VOID; k < T_ILLEGAL; k++ ) {
GasmanStatTotal[k] = GasmanStatAlive[k];
GasmanStatTSize[k] = GasmanStatASize[k];
}
}
else if ( SyStrcmp( (char*)PTR(hdCmd), "collect" ) == 0 ) {
CollectGarb();
}
else if ( SyStrcmp( (char*)PTR(hdCmd), "message" ) == 0 ) {
SyGasman = ! SyGasman;
}
else {
return Error(
"usage: GASMAN( \"display\"|\"clear\"|\"collect\"|\"message\" )",
0L,0L);
}
}
return HdVoid;
}
TypHandle       FunCoefficients ( hdCall )
TypHandle           hdCall;
{
long                pos, num, val;
TypHandle           hdRes, hdList, hdInt;
if ( SIZE( hdCall ) != 3 * SIZE_HD )
return Error("usage: Coefficients( <list>, <int> )",0L,0L);
hdList = EVAL( PTR(hdCall)[1] );
hdInt  = EVAL( PTR(hdCall)[2] );
if ( ! IS_LIST(hdList) || TYPE(hdInt) != T_INT)
return Error("usage: Coefficients( <list>, <int> )",0L,0L);
pos   = LEN_LIST( hdList );
hdRes = NewBag( T_LIST, SIZE_PLEN_PLIST( pos ) );
SET_LEN_PLIST( hdRes, pos );
num = HD_TO_INT( hdInt );
if ( num < 0 )
return Error("Coefficients: <int> must be non negative",0L,0L);
while ( 0 < num && 0 < pos ) {
hdInt = ELMF_LIST( hdList, pos );
if ( hdInt == 0 || TYPE( hdInt ) != T_INT )
return Error("Coefficients: <list>[%d] must be a positive integer",
(long)pos,0L);
val = HD_TO_INT(hdInt);
if ( val <= 0 )
return Error("Coefficients: <list>[%d] must be a positive integer",
(long)pos,0L);
SET_ELM_PLIST( hdRes, pos, INT_TO_HD( num % val ) );
pos--;
num /= val;
}
while ( 0 < pos ) {
SET_ELM_PLIST( hdRes, pos, INT_TO_HD( 0 ) );
pos--;
}
return hdRes;
}
TypHandle       FunNUMBERHANDLES ( hdCall )
TypHandle           hdCall;
{
long                typ;
TypHandle           hdTyp;
if ( SIZE( hdCall ) != 2 * SIZE_HD )
return Error("usage: NUMBER_HANDLES( <type> )",0L,0L);
hdTyp = EVAL( PTR(hdCall)[1] );
if (TYPE(hdTyp) != T_INT)
return Error("usage: NUMBER_HANDLES( <type> )",0L,0L);
typ = HD_TO_INT( hdTyp );
if (typ < 0 || typ >= T_ILLEGAL)
return Error("NUMBER_HANDLES: <type> must lie in [%d,%d]",
0L,(long)(T_ILLEGAL-1));
return INT_TO_HD( GasmanStatTotal[typ] );
}
TypHandle       FunSIZEHANDLES ( hdCall )
TypHandle           hdCall;
{
long                typ;
TypHandle           hdTyp;
if ( SIZE( hdCall ) != 2 * SIZE_HD )
return Error("usage: SIZE_HANDLES( <type> )",0L,0L);
hdTyp = EVAL( PTR(hdCall)[1] );
if (TYPE(hdTyp) != T_INT)
return Error("usage: SIZE_HANDLES( <type> )",0L,0L);
typ = HD_TO_INT( hdTyp );
if (typ < 0 || typ >= T_ILLEGAL)
return Error("SIZE_HANDLES: <type> must lie in [%d,%d]",
0L,(long)(T_ILLEGAL-1));
return INT_TO_HD( GasmanStatTSize[typ] );
}
void            InitGap ( argc, argv )
int                 argc;
char                * argv [];
{
TypHandle           hd;
long                i;
long                ignore;
char *              version;
InitSystem( argc, argv );
InitScanner();
InitGasman();
InitIdents();
InitEval();
HdLast  = FindIdent( "last"  );
HdLast2 = FindIdent( "last2" );
HdLast3 = FindIdent( "last3" );
HdTime  = FindIdent( "time"  );
hd = FindIdent( "VERSRC" );
version = "v3r4p0 1994/07/10";
PTR(hd)[0] = NewBag( T_STRING, SyStrlen(version)+1 );
SyStrncat( (char*)PTR(PTR(hd)[0]), version, SyStrlen(version)+1 );
hd = FindIdent( "VERSYS" );
version = SyFlags;
PTR(hd)[0] = NewBag( T_STRING, SyStrlen(version)+1 );
SyStrncat( (char*)PTR(PTR(hd)[0]), version, SyStrlen(version)+1 );
hd = FindIdent( "LIBNAME" );
PTR(hd)[0] = NewBag( T_STRING, (unsigned long)(SyStrlen(SyLibname)+1) );
SyStrncat( (char*)PTR(PTR(hd)[0]), SyLibname, SyStrlen(SyLibname) );
hd = FindIdent( "QUIET" );
if ( SyQuiet )  PTR(hd)[0] = HdTrue;
else            PTR(hd)[0] = HdFalse;
hd = FindIdent( "BANNER" );
if ( SyBanner )  PTR(hd)[0] = HdTrue;
else             PTR(hd)[0] = HdFalse;
InstIntFunc( "Ignore",     FunIgnore     );
InstIntFunc( "Error",      FunError      );
InstIntFunc( "Backtrace",  FunBacktrace  );
InstIntFunc( "WindowCmd",  FunWindowCmd  );
InstIntFunc( "READ",       FunREAD       );
InstIntFunc( "AUTO",       FunAUTO       );
InstIntFunc( "Print",      FunPrint      );
InstIntFunc( "PrintTo",    FunPrntTo     );
InstIntFunc( "AppendTo",   FunAppendTo   );
InstIntFunc( "LogTo",      FunLogTo      );
InstIntFunc( "LogInputTo", FunLogInputTo );
InstIntFunc( "ReadTest",   FunReadTest   );
InstIntFunc( "Help",        FunHelp        );
InstIntFunc( "Exec",        FunExec        );
InstIntFunc( "Runtime",     FunRuntime     );
InstIntFunc( "SizeScreen",  FunSizeScreen  );
InstIntFunc( "TmpName",     FunTmpName     );
InstIntFunc( "IsIdentical", FunIsIdentical );
InstIntFunc( "HANDLE",      FunHANDLE      );
InstIntFunc( "OBJ",         FunOBJ         );
InstIntFunc( "TYPE",        FunTYPE        );
InstIntFunc( "SIZE",        FunSIZE        );
InstIntFunc( "GASMAN",      FunGASMAN      );
InstIntFunc( "NUMBER_HANDLES",   FunNUMBERHANDLES );
InstIntFunc( "SIZE_HANDLES",     FunSIZEHANDLES   );
InstIntFunc( "CoefficientsInt", FunCoefficients );
if ( ! setjmp( ErrRet ) ) {
for ( i=0; i<sizeof(SyInitfiles)/sizeof(SyInitfiles[0]); ++i ) {
if ( SyInitfiles[i][0] != '\0' ) {
if ( OpenInput( SyInitfiles[i] ) ) {
while ( Symbol != S_EOF ) {
EnterKernel();
hd = ReadIt();
if ( hd != 0 )  hd = EVAL( hd );
if ( hd == HdReturn && PTR(hd)[0] != HdReturn )
Error("Read: 'return' must not be used",0L,0L);
else if ( hd == HdReturn )
Error("Read: 'quit' must not be used",0L,0L);
ExitKernel( (TypHandle)0 );
}
ignore = CloseInput();
}
else {
Error("can't read from \"%s\"",(long)SyInitfiles[i],0L);
}
}
}
}
}
/* 当前文件是D:\Read\agcollec.c*/

/* 当前文件是D:\Read\word.h*/

#ifdef SPEC_CPU2000_P64
#define long __int64
#endif
typedef     short           TypSword;
#define     SIZE_SWORD      ( (unsigned long) sizeof( TypSword ) )
#define     MAX_SWORD_NR    32768
















/* 当前文件是D:\Read\agcollec.h*/

#ifdef SPEC_CPU2000_P64
#define long __int64
#endif
#ifndef     COMBI_BOUND
#   define  COMBI_BOUND     13
#endif
#ifndef USE_SHIFT_TEST
#   define USE_SHIFT_TEST   0
#endif
#ifndef     PRINT_AG
#   define  PRINT_AG        0
#endif
#ifndef     GROUP_REC
#   define  GROUP_REC       1
#endif
#ifndef     USE_COMMS
#   define  USE_COMMS       1
#endif
#ifndef     AG_PROFILE
#   define  AG_PROFILE      1
#endif
#ifndef boolean
#define boolean         int
#endif
#ifndef TRUE
#define TRUE            1
#define FALSE           0
#endif
#define MAX( a, b )     ( (a) > (b) ? (a) : (b) )
#define MIN( a, b )     ( (a) < (b) ? (a) : (b) )
#define IND( i1, i2 )   ( (unsigned long)( (i1) * ( (i1) - 1 ) / 2 + (i2) ) )
#define     PTR_AW( hd )    ( (TypSword*)( PTR( hd ) + 1 ) )
#define     LEN_AW( hd )    ( (SIZE(hd)-SIZE_HD-SIZE_SWORD)/(2*SIZE_SWORD) )
#define     ISID_AW( hd )   ( SIZE( hd ) == SIZE_HD + SIZE_SWORD )
typedef     long            TypExp;
#define     SIZE_EXP        ( (unsigned long) sizeof( TypExp ) )
#define     MAX_AG_EXP      ( ( (long) 1 ) << 30 )
#define     SINGLE_COLLECTOR     0
#define     TRIPLE_COLLECTOR     1
#define     QUADR_COLLECTOR      2
#define     LEE_COLLECTOR        3
#define     COMBI2_COLLECTOR     4
#define     COMBI_COLLECTOR      5
typedef struct
{
char        * name;
void        (* init) P(( TypHandle, long ));
boolean     (* collect) P(( TypExp*, TypHandle ));
} TypCollectors;

#define     NR_GENERATORS                                  1
#define     HD_GENERATORS( g )                 ( PTR( g )[ 1 ] )
#define     GENERATORS( g )               ( PTR( PTR( g )[ 1 ] ) + 1 )
#define     NR_IDENTITY                                    3
#define     HD_IDENTITY( g )                   ( PTR( g )[ 3 ] )
#define     NR_WORDS                                       5
#define     HD_WORDS( g )                      ( PTR( g )[ 5 ] )
#define     WORDS( g )                    ( PTR( PTR( g )[ 5 ] ) + 1 )
#define     NR_POWERS                                      7
#define     HD_POWERS( g )                     ( PTR( g )[ 7 ] )
#define     POWERS( g )                   ( PTR( PTR( g )[ 7 ] ) + 1 )
#define     NR_INDICES                                     9
#define     HD_INDICES( g )                    ( PTR( g )[ 9 ] )
#define     INDICES( g )           ( (long*)PTR( PTR( g )[ 9 ] ) )
#define     NR_COMMUTATORS                                 11
#define     HD_COMMUTATORS( g )                ( PTR( g )[ 11 ] )
#define     COMMUTATORS( g )              ( PTR( PTR( g )[ 11 ] ) + 1 )
#define     NR_COLLECTOR                                   13
#define     HD_COLLECTOR( g )                  ( PTR( g )[ 13 ] )
#define     COLLECTOR( g )            HD_TO_INT( PTR( g )[ 13 ] )
#define     NR_NUMBER_OF_GENS                              15
#define     HD_NUMBER_OF_GENS( g )             ( PTR( g )[ 15 ] )
#define     NUMBER_OF_GENS( g )       HD_TO_INT( PTR( g )[ 15 ] )
#define     NR_SAVE_EXPONENTS                              17
#define     HD_SAVE_EXPONENTS( g )             ( PTR( g )[ 17 ] )
#define     SAVE_EXPONENTS( g )  ( (TypExp*)PTR( PTR( g )[ 17 ] ) )
#define     NR_COLLECT_EXPONENTS                                  19
#define     HD_COLLECT_EXPONENTS( g )                 ( PTR( g )[ 19 ] )
#define     COLLECT_EXPONENTS(g)         ((TypExp*)PTR( PTR( g )[ 19 ] ))
#define     NR_COLLECT_EXPONENTS_2                                21
#define     HD_COLLECT_EXPONENTS_2( g )               ( PTR( g )[ 21 ] )
#define     COLLECT_EXPONENTS_2( g )     ((TypExp*)PTR( PTR( g )[ 21 ] ))
#define     NR_COLLECTOR_FIRST                             23
#define     NR_COLLECTOR_LAST                              29
#define     NR_STACKS                                      23
#define     HD_STACKS( g )                     ( PTR( g )[ 23 ] )
#define     STACKS( g )                   ( PTR( PTR( g )[ 23 ] ) + 1 )
#define     NR_AVEC                                        25
#define     HD_AVEC( g )                       ( PTR( g )[ 25 ] )
#define     AVEC( g )              ( (long*)PTR( PTR( g )[ 25 ] ) )
#define     NR_CONJUGATES                                  27
#define     HD_CONJUGATES( g )                 ( PTR( g )[ 27 ] )
#define     CONJUGATES( g )               ( PTR( PTR( g )[ 27 ] ) + 1 )
#define     NR_TRIPLES                                     27
#define     HD_TRIPLES( g )                    ( PTR( g )[ 27 ] )
#define     TRIPLES( g )                  ( PTR( PTR( g )[ 27 ] ) + 1 )
#define     NR_TUPLE_BOUND                                 29
#define     HD_TUPLE_BOUND( g )                ( PTR( g )[ 29 ] )
#define     TUPLE_BOUND( g )          HD_TO_INT( PTR( g )[ 29 ] )
#define     NR_QUADRUPLES                                  27
#define     HD_QUADRUPLES( g )                 ( PTR( g )[ 27 ] )
#define     QUADRUPLES( g )               ( PTR( PTR( g )[ 27 ] ) + 1 )
#define     NR_CWEIGHTS                                    25
#define     HD_CWEIGHTS( g )                   ( PTR( g )[ 25 ] )
#define     CWEIGHTS( g )          ( (long*)PTR( PTR( g )[ 25 ] ) )
#define     NR_CSERIES                                     27
#define     HD_CSERIES( g )                    ( PTR( g )[ 27 ] )
#define     CSERIES( g )           ( (long*)PTR( PTR( g )[ 27 ] ) )
#define NAME_AW( hd, nr )   ( (char*)( PTR( WORDS( hd )[ nr ] ) + 1 ) + 1 )
TypHandle       EvalOop  P(( TypHandle, TypHandle, char * ));
TypHandle       EvalOop2 P(( TypHandle, TypHandle, TypHandle, char * ));
TypHandle       EvalOopN P(( TypHandle, TypHandle, TypHandle, char * ));
TypHandle       AgWordAgExp P(( TypHandle, TypHandle ));
void            SetCollectExponents P(( TypHandle ));
void            ClearCollectExponents P(( TypHandle ));
TypHandle       HeadAgWord P(( TypHandle, long ));
TypHandle       AgListWord P(( TypHandle, TypHandle ));
void        SetGeneratorsAgGroup P(( TypHandle ));
void        SetAvecAgGroup P(( TypHandle, long, long ));

boolean     SetCWeightsAgGroup P(( TypHandle, TypHandle ));
void        SetStacksAgGroup P(( TypHandle ));
TypHandle   SaveAndClearCollector P(( TypHandle ));
void        RestoreCollector P(( TypHandle, TypHandle ));
void            EvalRhs P(( TypHandle, long, long ));
void            EvalGenRels P(( TypHandle, long ));
void            CopyRelation P(( TypHandle, TypHandle, long ));
void            ReadRelators P(( TypHandle, TypHandle ));
void        InitSingle P(( TypHandle, long ));
void        InitTriple P(( TypHandle, long ));
void        InitQuadr P(( TypHandle, long ));
void        InitCombinatorial P(( TypHandle, long ));
boolean         AgCombinatorial P(( TypExp*, TypHandle ));
boolean         AgCombinatorial2 P(( TypExp*, TypHandle ));
int         AgSingle P(( TypExp*, TypHandle ));
int         AgTriple P(( TypExp*, TypHandle ));
int         AgQuadruple P(( TypExp*, TypHandle ));
void        ExpandStack P(( TypHandle ));
void            Collect P(( TypHandle, TypHandle, TypHandle ));
TypHandle       BlankAgGroup P(( void ));
TypHandle       AgSolution P(( TypHandle, TypHandle ));
TypHandle       AgSolution2 P(( TypHandle,TypHandle,TypHandle,TypHandle ));

/* 当前文件是D:\Read\aggroup.h*/

#ifdef SPEC_CPU2000_P64
#define long __int64
#endif

TypCollectors   Collectors[ COMBI_COLLECTOR + 1 ] =
{
{   "single",           InitSingle,             AgSingle            },
{   "triple",           InitTriple,             AgTriple            },
{   "quadruple",        InitQuadr,              AgQuadruple         },
{   "vaughanlee",       InitCombinatorial,      AgCombinatorial     },
{   "combinatorial",    InitCombinatorial,      AgCombinatorial2    },
{   "combinatorial",    InitCombinatorial,      AgCombinatorial     }
};
static TypHandle    * Powers, * Commutators;
static TypExp       * g;
static TypExp       * ExpStk;
static TypExp       ue, ce;
static TypSword     ug, cg;
static TypSword     LastClass, Class;
static TypSword     * * StrStk, * GenStk;
static long         NrGens;
static long         Prime;
static long         * CWeights, * CSeries;
static long         StkDim, Sp;
#define PUSH_STRING( s, e )  {*++StrStk=s; *++ExpStk=e; *++GenStk= -1; Sp++;}
#define POP_STRING( s, e )  { s= *StrStk--; e= *ExpStk--; GenStk--; Sp--; }
#define PUSH_GEN( g, e )    { *++GenStk=g; *++ExpStk=e; ++StrStk; Sp++; }
#define POP_GEN( g, e )     { g= *GenStk--; e= *ExpStk--; StrStk--; Sp--; }
static void     AddString ( str, exp )
TypSword        * str;
TypExp          exp;
{
TypHandle       hd;
TypExp          e,  * p;
e = exp * Prime;
#   if USE_SHIFT_TEST
if ( e / Prime != exp || ((e << 1 ) >> 1) != e )
#else
if ( e / Prime != exp || e >= MAX_AG_EXP )
#endif
Error( "Collector: integer overflow (e:%d, str:%d)", e, Prime );
for ( ; *str != -1; str += 2 )
{
p = &( g[ str[ 0 ] ] );
e = *p + exp * str[1];
#       if USE_SHIFT_TEST
if ( ((e << 1) >> 1) != e )
#       else
if ( e >= MAX_AG_EXP )
#       endif
Error("Collector: integer overflow (e:%d,g:%d)",e,g[str[0]]);
if ( e >= Prime )
{
*p = e % Prime;
if ( str[0] < LastClass )
{
hd = Powers[ str[0] ];
if ( ! ISID_AW( hd ) )
AddString( PTR_AW( hd ), e / Prime );
}
}
else
*p = e;
}
}
static void     AddGen ()
{
TypHandle       hd;
TypExp          * p, e;
p = g + ug;
e = *p + ue;
#   if USE_SHIFT_TEST
if ( ((e << 1) >> 1) != e )
#   else
if ( e >= MAX_AG_EXP )
#   endif
Error( "Collector: integer overflow (e:%d)", e, 0L );
if ( e >= Prime )
{
*p = e % Prime;
hd = Powers[ ug ];
if ( ! ISID_AW( hd ) )
AddString( PTR_AW( hd ), e / Prime );
}
else
*p = e;
}
static boolean  TripleWeight ()
{
TypHandle       hd;
TypExp          e, * p;
cg = CSeries[ Class - CWeights[ ug ] ];
for ( p = g + cg; cg > ug; cg--, p-- )
{
ce = *p;
if ( ce != 0 )
{
hd = Commutators[ IND( cg, ug ) ];
if ( ! ISID_AW( hd ) )
{
e = ce * ue;
if ( e / ce != ue )
Error( "Collector: integer overflow (ce:%d, ue:%d)",
ce, ue );
AddString( PTR_AW( hd ), e );
}
}
}
e = *p + ue;
#   if USE_SHIFT_TEST
if ( ((e << 1) >> 1) != e )
#   else
if ( e >= MAX_AG_EXP )
#   endif
Error( "Collector: integer overflow (g:%d, ue:%d)", g[ug], ue );
*p = e % Prime;
if ( e >= Prime )
{
hd = Powers[ ug ];
if ( ! ISID_AW( hd ) )
{
cg = CSeries[ Class - CWeights[ ug ] ];
for ( p = g + cg; cg > ug; cg--, p-- )
{
ce = *p;
if ( ce != 0 )
{
*p = 0;
PUSH_GEN( cg, ce );
if ( Sp > StkDim )
return FALSE;
}
}
AddString( PTR_AW( hd ), e / Prime );
}
}
return TRUE;
}
static int  VLCombiCollect ()
{
TypSword        i,  f,  l = 0,  uw;
TypHandle       hd;
TypExp          * p;
if ( ue > 1 )
{
PUSH_GEN( ug, ue - 1 );
if ( Sp > StkDim )
return 0;
ue = 1;
}
uw = CWeights[ ug ];
f  = CSeries[ Class - uw ];
l  = MAX( CSeries[ ( Class - uw ) / 2 ], ug );
if ( f < l )
Error("VLCombiCollect: f < l should not happen", 0L, 0L );
for ( cg = f, p = g + f; cg > ug; cg--, p-- )
{
ce = *p;
if ( ce != 0 )
{
hd = Commutators[ IND( cg, ug ) ];
if ( ! ISID_AW( hd ) )
{
if ( cg <= l )
break;
AddString( PTR_AW( hd ), ce );
}
}
}
if ( cg == ug )
{
if ( *p < Prime - 1 || ISID_AW( Powers[ ug ] ) )
return 2;
}
for ( i = f, p = g + f; i > cg; i--, p-- )
{
ce = *p;
if ( ce != 0 )
{
PUSH_GEN( i, ce );
if ( Sp > StkDim )
return 0;
*p = 0;
}
}
return 1;
}
static boolean  CombiCollect ()
{
TypSword        j,  f,  l = 0,  uw,  * str;
TypHandle       hd;
TypExp          * p,  * q,  i,  x,  y,  z,  t;
long            oldSp = 0;
#   if USE_SHIFT_TEST == 0
long            max = MAX_AG_EXP;
#   endif
#   if COMBI_BOUND > 0
if ( ue > COMBI_BOUND )
{
PUSH_GEN( ug, ue - COMBI_BOUND );
if ( Sp > StkDim )
return FALSE;
ue = COMBI_BOUND;
}
#   endif
uw = CWeights[ ug ];
f  = CSeries[ Class - uw ];
for ( i = 1; i <= ue; i++ )
{
l = MAX( CSeries[ ( Class - uw ) / 2 + ( i - 1 ) * uw ], ug ) + 1;
if ( f < l )
break;
oldSp = Sp + 1;
for ( cg = f, p = g + f; cg >= l; cg--, p-- )
{
ce = *p;
if ( ce != 0 )
{
PUSH_GEN( cg, ce );
if ( Sp > StkDim )
return FALSE;
*p = 0;
hd = Commutators[ IND( cg, ug ) ];
if ( ISID_AW( hd ) )
continue;
x = ce;
y = ue - i + 1;
z = 1;
if ( x % i == 0 )
x = x / i;
else if ( y % i == 0 )
y = y / i;
else
z = i;
t = x * y;
if ( t / x != y )
Error( "Collector: integer overflow (x:%d, y:%d)",x,y );
t = t / z;
x = t * Prime;
#               if USE_SHIFT_TEST
if ( x / Prime != t || ((x << 1) >> 1) != x )
#               else
if ( x / Prime != t || x >= MAX_AG_EXP )
#               endif
Error( "Collector: integer overflow (s:%d, t:%d)",
Prime, t );
for ( str = PTR_AW( hd ); str[ 0 ] != -1; str += 2 )
{
q   = &( g[ str[0] ] );
x   = str[1] * t;
*q += x;
#                   if USE_SHIFT_TEST
if ( (((*q) << 1) >> 1) != *q )
#                   else
if ( *q >= max )
#                   endif
{
if ( str[0] > f )
{
hd = Powers[ str[0] ];
if ( ! ISID_AW( hd ) )
AddString( PTR_AW(hd), *q/Prime );
*q = *q % Prime;
}
else
Error( "Collector: integer overflow (x:%d)",
x, 0L );
}
}
}
}
if ( oldSp > Sp )
break;
}
if ( oldSp <= Sp && f >= l )
{
l = MAX( CSeries[ ( Class - uw ) / 2 + ue * uw ], ug ) + 1;
for ( p = g + l; l <= f; l++, p++ )
{
ce = *p;
if ( ce != 0 )
{
PUSH_GEN( l, ce );
if ( Sp > StkDim )
return FALSE;
*p = 0;
}
}
}
for ( j = f + 1, p = g + ( f + 1 ); j < NrGens; j++, p++ )
if ( *p >= Prime )
{
hd = Powers[ j ];
if ( ! ISID_AW( hd ) )
AddString( PTR_AW( hd ), *p / Prime );
*p = *p % Prime;
}
return TRUE;
}
static boolean  OrdinaryCollect ()
{
TypHandle       hd;
TypSword        j;
TypExp          * p;
cg = CSeries[ Class - CWeights[ ug ] ];
for ( p = g + cg; cg > ug; cg--, p-- )
{
ce = *p;
if ( ce != 0 )
{
*p = 0;
hd = Commutators[ IND( cg, ug ) ];
if ( ISID_AW( hd ) )
{
PUSH_GEN( cg, ce );
if ( Sp > StkDim )
return FALSE;
}
else
{
if ( ue > 1 )
{
PUSH_GEN( ug, ue - 1 );
if ( Sp > StkDim )
return FALSE;
ue = 1;
}
if ( Sp + 2 * ce > StkDim )
return FALSE;
for ( j = 1; j <= ce; j++ )
{
PUSH_STRING( PTR_AW( hd ), 1 );
PUSH_GEN( cg, 1 );
}
}
}
}
return TRUE;
}
boolean         AgCombinatorial ( ptG, hdH )
TypExp          * ptG;
TypHandle       hdH;
{
TypHandle       hdGrp,  * hdStk;
TypSword        halfClass,  * str;
long            collNr,  i;
if  ( ISID_AW( hdH ) )
return TRUE;
hdGrp       = * PTR( hdH );
collNr      = COLLECTOR( hdGrp );
Prime       = INDICES( hdGrp )[ 0 ];
Powers      = POWERS( hdGrp );
Commutators = COMMUTATORS( hdGrp );
NrGens      = NUMBER_OF_GENS( hdGrp );
CWeights    = CWEIGHTS( hdGrp );
CSeries     = CSERIES( hdGrp );
hdStk       = STACKS( hdGrp );
StrStk      = ( (TypSword**) PTR( hdStk[ 0 ] ) ) - 1;
GenStk      = ( (TypSword*) PTR( hdStk[ 1 ] ) ) - 1;
ExpStk      = ( (TypExp*) PTR( hdStk[ 2 ] ) ) - 1;
StkDim      = SIZE( hdStk[ 0 ] ) / sizeof( TypSword* ) - 2;
Class       = CSeries[ 0 ];
halfClass   = ( Class == 1 ) ? -1 : CSeries[ Class / 2 ];
LastClass   = ( Class == 1 ) ?  0 : CSeries[ Class - 1 ] + 1;
g           = ptG;
PUSH_STRING( PTR_AW( hdH ), 1 );
Sp = 0;
while ( Sp >= 0 )
{
if ( *GenStk >= 0 )
{
POP_GEN( ug, ue );
if ( ug > halfClass )
{
AddGen();
continue;
}
}
else
{
POP_STRING( str, ue );
if ( str[ 0 ] > halfClass )
{
AddString( str, ue );
continue;
}
if ( str[ 2 ] != -1 )
PUSH_STRING( str + 2, ue );
ug = str[ 0 ];
ue = str[ 1 ];
}
if ( 3 * CWeights[ ug ] > Class )
{
if ( ! TripleWeight() )
return FALSE;
continue;
}
if ( collNr == LEE_COLLECTOR )
{
i = VLCombiCollect();
if ( i == 0 )
return FALSE;
if ( i == 1 )
if ( ! OrdinaryCollect() )
return FALSE;
}
else
{
if ( ! CombiCollect() )
return FALSE;
if ( ! OrdinaryCollect() )
return FALSE;
}
AddGen();
}
return TRUE;
}
#define PUSH_STRING_2( s )  { *++StrStk = s; *++GenStk = -1; Sp++; }
#define POP_STRING_2( s )   { s = *StrStk--; GenStk--; Sp--; }
#define PUSH_GEN_2( g )     { *++GenStk = g; ++StrStk; Sp++; }
#define POP_GEN_2( g )      { g = *GenStk--; StrStk--; Sp--; }
static void     AddString2 ( str )
TypSword        * str;
{
TypHandle       hd;
for ( ; *str != -1; str +=2 )
{
if ( g[ str[0] ] > 0 )
{
g[ str[0] ] = 0;
if ( str[0] < LastClass )
{
hd = Powers[ str[0] ];
if ( ! ISID_AW( hd ) )
AddString2( PTR_AW( hd ) );
}
}
else
g[ str[0] ] = 1;
}
}
static void     AddGen2 ()
{
TypHandle       hd;
if ( g[ ug ] > 0 )
{
g[ ug ] = 0;
hd = Powers[ ug ];
if ( ! ISID_AW( hd ) )
AddString2( PTR_AW( hd ) );
}
else
g[ ug ]  = 1;
}
static boolean  CombiCollect2 ()
{
TypExp          * p, i;
TypSword        l, uw;
TypHandle       hd;
uw = CWeights[ ug ];
l  = MAX( CSeries[ ( Class - uw ) / 2 ], ug );
cg = CSeries[ Class - uw ];
for ( p = g + cg; cg > l; cg--, p-- )
{
if ( *p > 0 )
{
hd = Commutators[ IND( cg, ug ) ];
if ( ! ISID_AW( hd ) )
AddString2( PTR_AW( hd ) );
}
}
if ( ug == cg && ( *p == 0 || ISID_AW( Powers[ cg ] ) ) )
return TRUE;
i = CSeries[ Class - CWeights[ ug ] ];
for ( p = g + i; i > cg; i--, p-- )
{
if ( *p != 0 )
{
*p = 0;
PUSH_GEN_2( i );
if ( Sp > StkDim )
return FALSE;
}
}
return TRUE;
}
static boolean  OrdinaryCollect2 ()
{
TypHandle       hd;
TypExp          * p;
for ( p = g + cg; cg > ug; cg--, p-- )
{
if ( *p != 0 )
{
*p = 0;
hd = Commutators[ IND( cg, ug ) ];
if (  ! ISID_AW( hd ) )
{
PUSH_STRING_2( PTR_AW( hd ) );
if ( Sp > StkDim )
return FALSE;
}
PUSH_GEN_2( cg );
if ( Sp > StkDim )
return FALSE;
}
}
return TRUE;
}
boolean         AgCombinatorial2 ( ptG, hdH )
TypExp          * ptG;
TypHandle       hdH;
{
TypSword        halfClass, * str;
TypHandle       * hdStk, hdGrp;
if  ( ISID_AW( hdH ) )
return TRUE;
hdGrp       = *PTR( hdH );
Powers      = POWERS( hdGrp );
Commutators = COMMUTATORS( hdGrp );
NrGens      = NUMBER_OF_GENS( hdGrp );
Prime       = INDICES( hdGrp )[ 0 ];
CWeights    = CWEIGHTS( hdGrp );
CSeries     = CSERIES( hdGrp );
hdStk       = STACKS( hdGrp );
StrStk      = ( (TypSword**) PTR( hdStk[ 0 ] ) ) - 1;
GenStk      = ( (TypSword*)  PTR( hdStk[ 1 ] ) ) - 1;
StkDim      = SIZE( hdStk[ 0 ] ) / sizeof( TypSword* ) - 2;
Class       = CSeries[ 0 ];
halfClass   = ( Class == 1 ) ? -1 : CSeries[ Class / 2 ];
LastClass   = ( Class == 1 ) ?  0 : CSeries[ Class - 1 ] + 1;
g           = ptG;
PUSH_STRING_2( PTR_AW( hdH ) );
Sp = 0;
while ( Sp >= 0 )
{
if ( *GenStk >= 0 )
{
POP_GEN_2( ug );
if ( ug > halfClass )
{
AddGen2();
continue;
}
}
else
{
POP_STRING_2( str );
if ( str[ 0 ] > halfClass )
{
AddString2( str );
continue;
}
if ( str[ 2 ] != -1 )
PUSH_STRING_2( str + 2 );
ug = str[ 0 ];
}
if ( ! CombiCollect2() )
return FALSE;
if ( cg != ug )
if ( ! OrdinaryCollect2() )
return FALSE;
AddGen2();
}
return TRUE;
}
boolean         AgSingle ( ptG, hdH )
TypExp          * ptG;
TypHandle       hdH;
{
TypSword    * * wStk, * * oStk, xr, ug;
TypExp      * kStk, * jStk, * p, nmv = 0;
TypHandle   * hdStk, hdGrp;
TypHandle   * conjugates, * powers;
long        stkDim, sP;
long        * avec;
long        * indices;
if  ( ISID_AW( hdH ) )
return TRUE;
hdGrp      = *PTR( hdH );
powers     = POWERS( hdGrp );
indices    = INDICES( hdGrp );
conjugates = CONJUGATES( hdGrp );
avec       = AVEC( hdGrp );
hdStk  = STACKS( hdGrp );
stkDim = SIZE( hdStk[ 0 ] ) / sizeof( TypSword* ) - 1;
wStk   = (TypSword**) PTR( hdStk[ 0 ] );
oStk   = (TypSword**) PTR( hdStk[ 1 ] );
kStk   = (TypExp*)  PTR( hdStk[ 2 ] );
jStk   = (TypExp*)  PTR( hdStk[ 3 ] );
sP     = 0;
*wStk  = PTR_AW( hdH );
*oStk  = PTR_AW( hdH );
*kStk  = PTR_AW( hdH )[ 1 ];
*jStk  = 1;
while ( sP >= 0 )
{
ug = *( *oStk );
if ( ug == -1 )
{
sP--;  wStk--;  oStk--;  kStk--;  jStk--;
}
else
{
*kStk -= avec[ ug ] == ug + 1 ? ( nmv = *kStk ) : ( nmv = 1 );
if ( ! *kStk )
{
*oStk += 2;
if ( **oStk == -1 )
{
if ( --(*jStk) > 0 )
{
*oStk = *wStk;
*kStk = *( *wStk + 1 );
}
else
{
sP--;  wStk--;  oStk--;  kStk--;  jStk--;
}
}
else
*kStk = *( *oStk + 1 );
}
for ( xr = avec[ ug ] - 1, p = ptG + xr; xr > ug; xr--, p-- )
{
if ( *p )
{
sP++;  wStk++;  oStk++;  kStk++;  jStk++;
if ( sP > stkDim )
return FALSE;
*wStk = *oStk = PTR_AW( conjugates[ IND(xr,ug) ] );
*kStk = *( *oStk + 1 );
*jStk = *p;
*p    = 0;
}
}
*p += nmv;
if ( *p < indices[ ug ] )
continue;
*p -= indices[ ug ];
if ( ! ISID_AW( powers[ ug ] ) )
{
sP++;  wStk++;  oStk++;  kStk++;  jStk++;
if ( sP > stkDim )
return FALSE;
*wStk = *oStk = PTR_AW( powers[ ug ] );
*kStk = *( *oStk + 1 );
*jStk = 1;
}
}
}
return TRUE;
}
boolean         AgTriple ( ptG, hdH )
TypExp          *ptG;
TypHandle       hdH;
{
TypHandle       * powers, * triple;
TypSword        * * oStk, * wStk, * eStk, xr, ug, maxExp;
TypExp          exp, nmv = 0, ind, * p;
TypHandle       * hdStk, hdGrp, * hdTmp;
long            stkDim, sP;
long            * avec;
long            * indices;
if  ( ISID_AW( hdH ) )
return FALSE;
hdGrp   = *PTR( hdH );
powers  = POWERS( hdGrp );
indices = INDICES( hdGrp );
triple  = TRIPLES( hdGrp );
avec    = AVEC( hdGrp );
maxExp  = TUPLE_BOUND( hdGrp );
hdStk  = STACKS( hdGrp );
stkDim = SIZE( hdStk[ 0 ] ) / sizeof( TypSword* ) - 1;
oStk   = (TypSword**) PTR( hdStk[ 0 ] );
wStk   = (TypSword*)  PTR( hdStk[ 1 ] );
eStk   = (TypSword*)  PTR( hdStk[ 2 ] );
sP     = 0;
*oStk  = PTR_AW( hdH );
while ( sP >= 0 )
{
if ( *oStk != 0 )
{
ug = **oStk;
if ( ug != -1 )
{
nmv   = *( *oStk + 1 );
*oStk += 2;
}
else
{
sP--; oStk--; wStk--; eStk--;
}
}
else
{
ug  = *wStk;
nmv = *eStk;
sP--; oStk--; wStk--; eStk--;
}
if ( ug != -1 )
{
while  ( nmv > maxExp )
{
sP++; oStk++; wStk++; eStk++;
if ( sP > stkDim )
return FALSE;
*oStk = 0;
*wStk = ug;
*eStk = maxExp;
nmv  -= maxExp;
}
for ( xr = avec[ ug ] - 1, p = ptG + xr; xr > ug; xr--, p-- )
{
exp = *p;
if ( exp )
{
ind = IND( xr, ug );
if ( triple[ ind ] )
{
hdTmp = PTR( triple[ ind ] ) + 1;
wStk += exp;
eStk += exp;
for ( ; exp > 0 ; exp-- )
{
sP++; oStk++;
if ( sP > stkDim )
return FALSE;
*oStk = PTR_AW( hdTmp[ nmv - 1 ] );
}
}
else
{
sP++; oStk++; wStk++; eStk++;
if ( sP > stkDim )
return FALSE;
*oStk = 0;
*wStk = xr;
*eStk = exp;
}
*p = 0;
}
}
*p += nmv;
if ( *p < indices[ ug ] )
continue;
*p -= indices[ ug ];
if ( ! ISID_AW( powers[ ug ] ) )
{
sP++; oStk++; wStk++; eStk++;
if ( sP > stkDim )
return FALSE;
*oStk = PTR_AW( powers[ ug ] );
}
}
}
return TRUE;
}
int         AgQuadruple ( ptG, hdH )
TypExp      * ptG;
TypHandle   hdH;
{
TypHandle       * powers, * quadruple;
TypSword        * * oStk, * wStk, * eStk, xr, ug, maxExp;
TypExp          exp, nmv = 0, ind, * p;
TypHandle       * hdStk, hdGrp, * hdTmp;
long            stkDim, sP;
long            * avec;
long            * indices;
if  ( ISID_AW( hdH ) )
return TRUE;
hdGrp     = *PTR( hdH );
powers    = POWERS( hdGrp );
indices   = INDICES( hdGrp );
quadruple = QUADRUPLES( hdGrp );
avec      = AVEC( hdGrp );
maxExp    = TUPLE_BOUND( hdGrp );
hdStk  = STACKS( hdGrp );
stkDim = SIZE( hdStk[ 0 ] ) / sizeof( TypSword* ) - 1;
oStk   = (TypSword**) PTR( hdStk[ 0 ] );
wStk   = (TypSword*)  PTR( hdStk[ 1 ] );
eStk   = (TypSword*)  PTR( hdStk[ 2 ] );
sP     = 0;
*oStk  = PTR_AW( hdH );
while ( sP >= 0 )
{
if ( *oStk != 0 )
{
ug = *( *oStk );
if ( ug != -1 )
{
nmv = *( *oStk + 1 );
*oStk += 2;
}
else
{
sP--; oStk--; wStk--; eStk--;
}
}
else
{
ug  = *wStk;
nmv = *eStk;
sP--; oStk--; wStk--; eStk--;
}
if ( ug != -1 )
{
while  ( nmv > maxExp )
{
sP++; oStk++; wStk++; eStk++;
if ( sP > stkDim )
return FALSE;
*oStk = 0;
*wStk = ug;
*eStk = maxExp;
nmv  -= maxExp;
}
for ( xr = avec[ ug ] - 1, p = ptG + xr; xr > ug; xr--, p-- )
{
exp = *p;
if ( exp )
{
ind = IND( xr, ug );
if ( quadruple[ ind ] )
{
hdTmp = PTR( quadruple[ ind ] ) + 1;
while  ( exp > maxExp )
{
sP++; oStk++; wStk++; eStk++;
if ( sP > stkDim )
return FALSE;
ind = (nmv-1) * MIN( (indices[xr]-1), maxExp )
+ maxExp - 1;
*oStk = PTR_AW( hdTmp[ ind ]);
exp  -= maxExp;
}
sP++; oStk++; wStk++; eStk++;
if ( sP > stkDim )
return FALSE;
ind = (nmv-1) * MIN( (indices[xr]-1 ), maxExp )
+ exp - 1;
*oStk = PTR_AW( hdTmp[ ind ]);
}
else
{
sP++; oStk++; wStk++; eStk++;
if ( sP > stkDim )
return FALSE;
*oStk = 0;
*wStk = xr;
*eStk = exp;
}
*p = 0;
}
}
*p += nmv;
if ( *p < indices[ ug ] )
continue;
*p -= indices[ ug ];
if ( ! ISID_AW( powers[ ug ] ) )
{
sP++; oStk++; wStk++; eStk++;
if ( sP > stkDim )
return FALSE;
*oStk = PTR_AW( powers[ ug ] );
}
}
}
return TRUE;
}
void        ExpandStack ( hdGrp )
TypHandle       hdGrp;
{
TypHandle       hdStk;
long            i, plus;
plus = NUMBER_OF_GENS( hdGrp ) * ( INDICES( hdGrp )[ 0 ] + 2 );
for ( i = LEN_LIST( HD_STACKS( hdGrp ) ); i > 0; i-- )
{
hdStk = PTR( HD_STACKS( hdGrp ) )[ i ];
switch ( TYPE( hdStk ) )
{
case T_STRING:
Resize( hdStk, SIZE( hdStk ) + plus * sizeof( TypSword* ) );
break;
case T_INTNEG:
Resize( hdStk, SIZE( hdStk ) + plus * SIZE_SWORD );
break;
case T_INTPOS:
Resize( hdStk, SIZE( hdStk ) + plus * SIZE_EXP );
break;
default:
ClearCollectExponents( hdGrp );
Error( "ExpandStacks: cannot expand (type=%d, group = %d)",
(long) TYPE( hdStk ),
(long) hdGrp );
break;
}
}
}
void            Collect ( hdExp, hdBup, hdWrd )
TypHandle       hdExp, hdWrd, hdBup;
{
TypHandle       hdSave = 0;
TypSword        * ptBup;
TypExp          * ptNew,  * ptOld,  * ptExp;
boolean         success;
long            i;
boolean         (* collector) P(( TypExp*, TypHandle ));
#   if AG_PROFILE
long                t1 = 0;
long                t2 = 0;



#   endif
#   if AG_PROFILE
if ( CPP )
PTR(HdCPC)[CPN] = INT_TO_HD(HD_TO_INT(PTR(HdCPC)[CPN])+1);
#   endif
if ( ISID_AW( hdWrd ) )
return;
#   if AG_PROFILE
if ( CPP )
t1 = SyTime();
#   endif
if ( hdExp == 0 )
{
SetCollectExponents( hdBup );
hdExp = HD_COLLECT_EXPONENTS( * PTR( hdBup ) );
}
if ( hdBup == 0 )
{
hdSave = HD_SAVE_EXPONENTS( * PTR( hdWrd ) );
ptNew  = (TypExp*) PTR( hdSave );
ptOld  = (TypExp*) PTR( hdExp );
for ( i = SIZE( hdExp ) / SIZE_EXP; i > 0; --i )
*( ptNew++ ) = *( ptOld++ );
}
i = COLLECTOR( * PTR( hdWrd ) );
if ( i > COMBI_COLLECTOR )
{
ClearCollectExponents( *PTR( hdWrd ) );
Error( "AgWord collector: unknown collector", 0L, 0L );
}
collector = Collectors[ i ].collect;
#   if AG_PROFILE
if ( CPP )
t1 = SyTime() - t1;
#   endif
do
{
#       if AG_PROFILE
if ( CPP )
t2 = SyTime();
#       endif
ptExp = (TypExp*) PTR( hdExp );
success = collector( ptExp, hdWrd );
if ( ! success )
{
ExpandStack( *PTR( hdWrd ) );
if ( hdBup == 0 )
{
ptNew = (TypExp*) PTR( hdExp );
ptOld = (TypExp*) PTR( hdSave );
for ( i = SIZE( hdSave ) / SIZE_EXP; i > 0; --i )
*( ptNew++ ) = *( ptOld++ );
}
else
{
ptNew = (TypExp*) PTR( hdExp );
for ( i = SIZE( hdExp ) / SIZE_EXP; i > 0; --i )
*( ptNew++ ) = 0;
ptNew = (TypExp*) PTR( hdExp );
for ( ptBup = PTR_AW( hdBup ); *ptBup != -1; ptBup += 2 )
ptNew[ (long)( *ptBup ) ] = *( ptBup + 1 );
}
}
}
while ( ! success );
#   if AG_PROFILE
if ( CPP )
{
t2 = SyTime() - t2;
PTR( HdCPL )[ CPN ] = INT_TO_HD( HD_TO_INT( ELM_LIST( HdCPL,
CPN ) ) + t1 + t2 );
}
#    endif
}
TypHandle       AgSolution ( hdA, hdB )
TypHandle       hdA;
TypHandle       hdB;
{
TypHandle       hdX, hdW, hdG, hdGrp;
TypExp          e, ea, eb;
TypSword        dx, db;
TypSword        * pt;
long            i, len;
hdGrp = * PTR( hdA );
SetCollectExponents( hdA );
hdW = HD_COLLECT_EXPONENTS( hdGrp );
len = NUMBER_OF_GENS( hdGrp );
hdX         = NewBag( T_AGWORD, (1 + 2 * len) * SIZE_SWORD + SIZE_HD );
*PTR( hdX ) = hdGrp;
hdG                = NewBag( T_AGWORD, SIZE_HD + 3 * SIZE_SWORD );
*PTR( hdG )        = hdGrp;
PTR_AW( hdG )[ 2 ] = -1;
dx = db = 0;
for ( i = 0; i < len; i++ )
{
ea = ( (TypExp*) PTR( hdW ) )[ i ];
pt = PTR_AW( hdB ) + db;
if ( pt[0] == i )
{
eb  = pt[1];
db += 2;
}
else
eb = 0;
e = eb - ea;
if ( e != 0 )
{
if ( e < 0 )
e += INDICES( hdGrp )[ i ];
PTR_AW( hdG )[0] = PTR_AW( hdX )[ dx++ ] = i;
PTR_AW( hdG )[1] = PTR_AW( hdX )[ dx++ ] = e;
Collect( hdW, 0, hdG );
}
}
PTR_AW( hdX )[ dx ] = -1;
Resize( hdX, SIZE_HD + ( dx + 1 ) * SIZE_SWORD );
ClearCollectExponents( * PTR( hdA ) );
return hdX;
}
TypHandle       AgSolution2 ( hdA, hdB, hdC, hdD )
TypHandle       hdA;
TypHandle       hdB;
TypHandle       hdC;
TypHandle       hdD;
{
TypHandle       hdX, hdW, hdV, hdG, hdGrp, hdCD;
TypExp          e, ea, eb, ec, * ptV, * ptW, * ptEnd;
TypSword        dx, dc;
TypSword        * pt;
long            i, len, p;
hdGrp = * PTR( hdA );
len   = NUMBER_OF_GENS( hdGrp );
SetCollectExponents( hdC );
hdW = HD_COLLECT_EXPONENTS( hdGrp );
hdV   = HD_COLLECT_EXPONENTS_2( hdGrp );
ptV   = (TypExp*) PTR( hdV );
ptEnd = (TypExp*)( (char*) ptV + SIZE( hdV ) );
while ( ptV < ptEnd )
*ptV++ = 0;
ptV = (TypExp*) PTR( hdV );
pt  = PTR_AW( hdA );
for ( ; pt[0] != -1; pt += 2 )
ptV[ pt[0] ] = pt[1];
ptW   = (TypExp*) PTR( hdW );
ptEnd = ptW + len;
while ( ptW < ptEnd && *ptW == *ptV )
{
*ptW++ = 0;
*ptV++ = 0;
}
Collect( hdW, 0, hdD );
hdCD = AgWordAgExp( HD_COLLECT_EXPONENTS( hdGrp ), hdGrp );
SetCollectExponents( hdB );
hdW = HD_COLLECT_EXPONENTS( hdGrp );
hdX         = NewBag( T_AGWORD, (1 + 2 * len) * SIZE_SWORD + SIZE_HD );
*PTR( hdX ) = hdGrp;
hdG                = NewBag( T_AGWORD, SIZE_HD + 3 * SIZE_SWORD );
*PTR( hdG )        = hdGrp;
PTR_AW( hdG )[ 2 ] = -1;
dx = dc = 0;
for ( i = 0; i < len; i++ )
{
ea = ( (TypExp*) PTR( hdV ) )[ i ];
eb = ( (TypExp*) PTR( hdW ) )[ i ];
pt = PTR_AW( hdCD ) + dc;
if ( pt[0] == i )
{
ec  = pt[1];
dc += 2;
}
else
ec = 0;
e = ec - ( ea + eb );
p = INDICES( hdGrp )[ i ];
while ( e <  0 )  e += p;
while ( e >= p )  e -= p;
if ( e != 0 )
{
PTR_AW( hdG )[0] = PTR_AW( hdX )[ dx++ ] = i;
PTR_AW( hdG )[1] = PTR_AW( hdX )[ dx++ ] = e;
Collect( hdW, 0, hdG );
}
e = ( (TypExp*) PTR( hdW ) )[ i ];
if ( e != 0 )
{
PTR_AW( hdG )[0] = i;
PTR_AW( hdG )[1] = e;
Collect( hdV, 0, hdG );
}
}
PTR_AW( hdX )[ dx ] = -1;
Resize( hdX, SIZE_HD + ( dx + 1 ) * SIZE_SWORD );
ClearCollectExponents( * PTR( hdA ) );
return hdX;
}
void        InitSingle ( hdCall, nr )
TypHandle       hdCall;
long            nr;
{
TypHandle       hdAgGroup, hdList, hdAgWord, hdGenJ, hdRnName;
long            nrGens, i, j;
if ( SIZE( hdCall ) > 3 * SIZE_HD )
Error( "usage: SetCollectorAgWord( <agword>, \"single\" )", 0L, 0L );
hdAgWord  = EVAL( PTR( hdCall )[ 1 ] );
hdAgGroup = *PTR( hdAgWord );
if ( COLLECTOR( hdAgGroup ) == SINGLE_COLLECTOR )
return;
SaveAndClearCollector( hdAgGroup );
hdRnName = FindRecname( "stacks" );
PTR( hdAgGroup )[ NR_STACKS - 1 ] = hdRnName;
hdRnName = FindRecname( "conjugates" );
PTR( hdAgGroup )[ NR_CONJUGATES - 1 ] = hdRnName;
nrGens = NUMBER_OF_GENS( hdAgGroup );
SetAvecAgGroup( hdAgGroup, 0, NUMBER_OF_GENS(hdAgGroup)-1 );
HD_COLLECTOR( hdAgGroup ) = INT_TO_HD( SINGLE_COLLECTOR );
SetStacksAgGroup( hdAgGroup );
hdList = NewBag( T_LIST, ( nrGens * ( nrGens - 1 ) / 2 + 1 ) * SIZE_HD );
PTR( hdList )[ 0 ] = INT_TO_HD( nrGens * ( nrGens - 1 ) / 2 );
HD_CONJUGATES( hdAgGroup ) = hdList;
for ( i = nrGens - 2; i >= 0; i-- )
for ( j = nrGens - 1; j > i; j-- )
{
if ( j < AVEC( hdAgGroup )[ i ] )
{
hdGenJ = GENERATORS( hdAgGroup )[ j ];
hdAgWord = COMMUTATORS( hdAgGroup )[ IND( j, i ) ];
if  ( ISID_AW( hdAgWord ) )
hdAgWord = hdGenJ;
else
hdAgWord = ProdAg( hdGenJ, hdAgWord );
}
else
hdAgWord = GENERATORS( hdAgGroup )[ j ];
CONJUGATES( hdAgGroup )[ IND( j, i ) ] = hdAgWord;
}
}
void        InitTriple ( hdCall, nr )
TypHandle       hdCall;
long            nr;
{
TypHandle       hdAgGroup, hdAgWord, hdInt, hdRnName;
TypHandle       hdGenI, hdGenJ, hdList, hdComm, hdTrip, hdTmp;
TypHandle       hdOld, hdAvec;
long            nrGens, expI, maxExp;
long            i, j, k;
if ( SIZE( hdCall ) > 4 * SIZE_HD )
Error( "usage: SetCollectorAgWord( <agword>, \"triple\" )", 0L, 0L );
hdAgWord  = EVAL( PTR( hdCall )[ 1 ] );
hdAgGroup = *PTR( hdAgWord );
if ( SIZE( hdCall ) == 4 * SIZE_HD )
{
hdInt = EVAL( PTR( hdCall )[ 3 ] );
if ( TYPE( hdInt ) != T_INT )
Error(
"usage: SetCollectorAgWord( <agword>, \"triple\", <bound> )",
0L, 0L );
maxExp = HD_TO_INT( hdInt );
if ( maxExp < 1 )
Error( "SetCollectorAgWord: needs a positive <bound>. ", 0L, 0L );
}
else
maxExp = 5;
if ( COLLECTOR( hdAgGroup ) == TRIPLE_COLLECTOR &&
maxExp == TUPLE_BOUND( hdAgGroup ) )
{
return;
}
hdOld  = SaveAndClearCollector( hdAgGroup );
SetAvecAgGroup( hdAgGroup, 0, NUMBER_OF_GENS(hdAgGroup)-1 );
hdAvec = HD_AVEC( hdAgGroup );
RestoreCollector( hdAgGroup, hdOld );
nrGens = NUMBER_OF_GENS( hdAgGroup );
hdList = NewBag( T_LIST, ( nrGens * ( nrGens - 1 ) / 2 + 1 ) * SIZE_HD );
PTR( hdList )[ 0 ] = INT_TO_HD( nrGens * ( nrGens - 1 ) / 2 );
for ( i = nrGens - 2; i >= 0; i-- )
for  ( j = nrGens - 1; j > i; j-- )
if ( j < ( (long*)PTR( hdAvec ) )[ i ] )
{
hdComm = COMMUTATORS( hdAgGroup )[ IND( j, i ) ];
if  ( ! ISID_AW( hdComm ) )
{
expI   = MIN( INDICES( hdAgGroup )[ i ] - 1, maxExp );
hdTrip = NewBag( T_LIST, ( expI + 1 ) * SIZE_HD );
PTR( hdTrip )[ 0 ] = INT_TO_HD( expI );
PTR( hdList )[ IND( j, i ) + 1 ] = hdTrip;
hdGenJ = GENERATORS( hdAgGroup )[ j ];
hdTmp  = ProdAg( hdGenJ, hdComm );
PTR( hdTrip )[ 1 ] = hdTmp;
}
}
SaveAndClearCollector( hdAgGroup );
hdRnName = FindRecname( "stacks" );
PTR( hdAgGroup )[ NR_STACKS - 1 ] = hdRnName;
hdRnName = FindRecname( "triples" );
PTR( hdAgGroup )[ NR_TRIPLES - 1 ] = hdRnName;
hdRnName = FindRecname( "tupleBound" );
PTR( hdAgGroup )[ NR_TUPLE_BOUND - 1 ] = hdRnName;
SetAvecAgGroup( hdAgGroup, 0, NUMBER_OF_GENS(hdAgGroup)-1 );
HD_COLLECTOR( hdAgGroup ) = INT_TO_HD( TRIPLE_COLLECTOR );
HD_TUPLE_BOUND( hdAgGroup ) = INT_TO_HD( maxExp );
HD_TRIPLES( hdAgGroup ) = hdList;
SetStacksAgGroup( hdAgGroup );
for ( i = nrGens - 2; i >= 0; i-- )
for  ( j = nrGens - 1; j > i; j-- )
if ( j < AVEC( hdAgGroup )[ i ] )
{
hdComm = COMMUTATORS( hdAgGroup )[ IND( j, i ) ];
if  ( ! ISID_AW( hdComm ) )
{
expI = MIN( INDICES( hdAgGroup )[ i ] - 1, maxExp );
hdTrip = TRIPLES( hdAgGroup )[ IND( j, i ) ];
hdGenI = GENERATORS( hdAgGroup )[ i ];
hdTmp = PTR( hdTrip )[ 1 ];
for ( k = 1; k < expI; k++ )
{
hdTmp = AgSolution( hdGenI, hdTmp );
hdTmp = ProdAg( hdTmp, hdGenI );
PTR( hdTrip )[ k + 1 ] = hdTmp;
}
}
}
}
void        InitQuadr ( hdCall, nr )
TypHandle       hdCall;
long            nr;
{
TypHandle       hdAgGroup, hdAgWord, hdRnName, hdInt;
TypHandle       hdTmp, hdQuadr, hdList, hdComm, hdOld, hdAvec;
TypHandle       hdGenI, hdGenJ;
long            i, j, k, l;
long            expI, expJ, ind, nrGens, maxExp;
if ( SIZE( hdCall ) > 4 * SIZE_HD )
Error(
"usage: SetCollectorAgWord( <agword>, \"quadruple\" )", 0L, 0L );
hdAgWord  = EVAL( PTR( hdCall )[ 1 ] );
hdAgGroup = *PTR( hdAgWord );
if ( SIZE( hdCall ) == 4 * SIZE_HD )
{
hdInt = EVAL( PTR( hdCall )[ 3 ] );
if ( TYPE( hdInt ) != T_INT )
Error(
"usage: SetCollectorAgWord( <agword>, \"quadruple\", <bound> )",
0L, 0L );
maxExp = HD_TO_INT( hdInt );
if ( maxExp < 1 )
Error( "SetCollectorAgWord: needs a positive <bound>. ", 0L, 0L );
}
else
maxExp = 5;
if ( COLLECTOR( hdAgGroup ) == QUADR_COLLECTOR &&
maxExp == TUPLE_BOUND( hdAgGroup ) )
{
return;
}
hdOld  = SaveAndClearCollector( hdAgGroup );
SetAvecAgGroup( hdAgGroup, 0, NUMBER_OF_GENS(hdAgGroup)-1 );
hdAvec = HD_AVEC( hdAgGroup );
RestoreCollector( hdAgGroup, hdOld );
nrGens = NUMBER_OF_GENS( hdAgGroup );
hdList = NewBag( T_LIST, ( nrGens * ( nrGens - 1 ) / 2 + 1 ) * SIZE_HD );
PTR( hdList )[ 0 ] = INT_TO_HD( nrGens * ( nrGens - 1 ) / 2 );
for ( i = nrGens - 2; i >= 0; i-- )
for  ( j = nrGens - 1; j > i; j-- )
if ( j < ( (long*)PTR( hdAvec ) )[ i ] )
{
hdComm = COMMUTATORS( hdAgGroup )[ IND( j, i ) ];
if  ( ! ISID_AW( hdComm ) )
{
expI = MIN( INDICES( hdAgGroup )[ i ] - 1, maxExp );
expJ = MIN( INDICES( hdAgGroup )[ j ] - 1, maxExp );
hdQuadr = NewBag( T_LIST, ( expI*expJ+1 ) * SIZE_HD );
PTR( hdQuadr )[ 0 ] = INT_TO_HD( expI * expJ );
PTR( hdList )[ IND( j, i ) + 1 ] = hdQuadr;
hdGenJ = GENERATORS( hdAgGroup )[ j ];
hdAgWord = ProdAg( hdGenJ, hdComm );
PTR( hdQuadr )[ 1 ] = hdAgWord;
hdTmp = hdAgWord;
for ( k = 1; k < expJ; k++ )
{
hdTmp = ProdAg( hdTmp , hdAgWord );
PTR( hdQuadr )[ k + 1 ] = hdTmp;
}
}
}
SaveAndClearCollector( hdAgGroup );
hdRnName = FindRecname( "stacks" );
PTR( hdAgGroup )[ NR_STACKS - 1 ] = hdRnName;
hdRnName = FindRecname( "quadruples" );
PTR( hdAgGroup )[ NR_QUADRUPLES - 1 ] = hdRnName;
hdRnName = FindRecname( "tupleBound" );
PTR( hdAgGroup )[ NR_TUPLE_BOUND - 1 ] = hdRnName;
SetAvecAgGroup( hdAgGroup, 0, NUMBER_OF_GENS(hdAgGroup)-1 );
HD_COLLECTOR( hdAgGroup ) = INT_TO_HD( QUADR_COLLECTOR );
HD_TUPLE_BOUND( hdAgGroup ) = INT_TO_HD( maxExp );
HD_QUADRUPLES( hdAgGroup )  = hdList;
SetStacksAgGroup( hdAgGroup );
for ( i = nrGens - 2; i >= 0; i-- )
for  ( j = nrGens - 1; j > i; j-- )
if ( j < AVEC( hdAgGroup )[ i ] )
{
hdComm =  COMMUTATORS( hdAgGroup )[ IND( j, i ) ];
if  ( ! ISID_AW( hdComm ) )
{
expI = MIN( INDICES( hdAgGroup )[ i ] - 1, maxExp );
expJ = MIN( INDICES( hdAgGroup )[ j ] - 1, maxExp );
hdQuadr = QUADRUPLES( hdAgGroup )[ IND( j, i ) ];
hdGenI = GENERATORS( hdAgGroup )[ i ];
ind = expJ;
hdAgWord = PTR( hdQuadr )[ 1 ];
for ( k = 1; k < expI; k++ )
{
hdTmp = AgSolution( hdGenI, hdAgWord );
hdAgWord = ProdAg( hdTmp, hdGenI );
PTR( hdQuadr )[ ind++ + 1 ] = hdAgWord;
hdTmp = hdAgWord;
for ( l = 1; l < expJ; l++ )
{
hdTmp = ProdAg( hdTmp, hdAgWord );
PTR( hdQuadr )[ ind++ + 1 ] = hdTmp;
}
}
}
}
}
void        InitCombinatorial ( hdCall, nr )
TypHandle       hdCall;
long            nr;
{
TypHandle       hdWrd,  hdGrp,  hdOld;
char            *usage1 = "SetCollectorAgWord( <g>, \"combinatorial\" )";
char            *usage2 = "SetCollectorAgWord( <g>, \"vaughanlee\" )";
if ( nr == LEE_COLLECTOR )
{
if ( SIZE( hdCall ) != 3 * SIZE_HD )
Error( "usage: %s", (long) usage2, 0L );
hdWrd  = EVAL( PTR( hdCall )[ 1 ] );
hdGrp = *PTR( hdWrd );
if ( COLLECTOR( hdGrp ) == LEE_COLLECTOR )
return;
}
else
{
if ( SIZE( hdCall ) != 3 * SIZE_HD )
Error( "usage: %s", (long) usage1, 0L );
hdWrd  = EVAL( PTR( hdCall )[ 1 ] );
hdGrp = *PTR( hdWrd );
if (    COLLECTOR( hdGrp ) == COMBI_COLLECTOR
|| COLLECTOR( hdGrp ) == COMBI2_COLLECTOR )
{
return;
}
}
hdOld = SaveAndClearCollector( hdGrp );
if ( ! SetCWeightsAgGroup( hdGrp, HdVoid ) )
{
Pr( "SetCollectorAgWord: leaves collector unchanged.\n", 0L, 0L );
RestoreCollector( hdGrp, hdOld );
return;
}
if ( nr == LEE_COLLECTOR )
HD_COLLECTOR( hdGrp ) = INT_TO_HD( LEE_COLLECTOR );
else
{
if ( INDICES( hdGrp )[ 0 ] == 2 )
HD_COLLECTOR( hdGrp ) = INT_TO_HD( COMBI2_COLLECTOR );
else
HD_COLLECTOR( hdGrp ) = INT_TO_HD( COMBI_COLLECTOR );
}
SetStacksAgGroup( hdGrp );
}
void            EvalRhs ( hdAgGroup, gen1, gen2 )
TypHandle       hdAgGroup;
long            gen1, gen2;
{
TypHandle       hdRel, hdEvalRel, hdGen;
long            i, lenRel, genNr;
if ( gen1 == gen2 )
hdRel = POWERS( hdAgGroup )[ gen1 ];
else
hdRel = COMMUTATORS( hdAgGroup )[ IND( gen1, gen2 ) ];
hdEvalRel = HD_IDENTITY( hdAgGroup );
if ( hdRel != 0 )
{
lenRel = SIZE( hdRel ) /  SIZE_SWORD;
for ( i = 0; i < lenRel; i += 2 )
{
if ( ( (TypSword*) PTR( hdRel ) )[ i + 1 ] == 0 )
continue;
if ( ( (TypSword*) PTR( hdRel ) )[ i ] <= gen2 )
{
if ( gen1 == gen2 )
Error(
"AgFpGroup: %s^%d contains an illegal generator",
(long) NAME_AW( hdAgGroup, gen1 ),
(long) ((TypSword*)PTR(hdRel)[i+1]) );
else
Error(
"AgFpGroup: [%s,%s] contains an illegal generator",
(long) NAME_AW( hdAgGroup, gen1 ),
(long) NAME_AW( hdAgGroup, gen2 ) );
}
else
{
genNr = ( (TypSword*) PTR( hdRel ) )[ i ];
hdGen = GENERATORS( hdAgGroup )[ genNr ];
hdEvalRel = ProdAg( hdEvalRel, PowAgI( hdGen,
INT_TO_HD( ( (TypSword*) PTR( hdRel ) )[ i + 1 ] ) ) );
}
}
}
if ( ISID_AW( hdEvalRel ) )
hdEvalRel = HD_IDENTITY( hdAgGroup );
if ( gen1 == gen2 )
POWERS( hdAgGroup )[ gen1 ] = hdEvalRel;
else
COMMUTATORS( hdAgGroup )[ IND( gen1, gen2 ) ] = hdEvalRel;
}
void            EvalGenRels ( hdAgGroup, genNr )
TypHandle       hdAgGroup;
long            genNr;
{
TypHandle       hdGenJ, hdTmp, hdComm;
long            nrGens;
long            i, j;
nrGens = NUMBER_OF_GENS ( hdAgGroup );
if ( INDICES( hdAgGroup )[ genNr ] == 0 )
Error( "AgGroupFpGroup: the index of generator %s is unknown",
(long) NAME_AW( hdAgGroup, genNr ), 0L );
for ( i = nrGens - 1; i >= genNr; i-- )
EvalRhs( hdAgGroup, i, genNr );
SetAvecAgGroup( hdAgGroup, genNr, genNr );
for ( j = nrGens - 1; j > genNr; j-- )
{
if ( j < AVEC( hdAgGroup )[ genNr ] )
{
hdComm = COMMUTATORS( hdAgGroup )[ IND( j, genNr ) ];
if  ( ISID_AW( hdComm ) )
{
hdTmp = GENERATORS( hdAgGroup )[ j ];
}
else
{
hdGenJ = GENERATORS( hdAgGroup )[ j ];
hdTmp = ProdAg( hdGenJ, hdComm );
}
}
else
{
hdTmp = GENERATORS( hdAgGroup )[ j ];
}
CONJUGATES( hdAgGroup )[ IND( j, genNr ) ] = hdTmp;
}
}
void            CopyRelation ( hdRel, hdGrp, nrRel )
TypHandle       hdRel;
TypHandle       hdGrp;
long            nrRel;
{
TypHandle       hdAgl,    hdW;
TypSword        * ptAgl,  * ptW;
long            lnAgl,    i,  j,  ei;
if ( SIZE( hdRel ) / SIZE_HD == 0 )
return;
hdAgl = AgListWord( hdRel, hdGrp );
if ( hdAgl == HdFalse )
{
Error( "%d. relation is no word in '~.generators'", nrRel, 0L );
return;
}
ptAgl  = (TypSword*) PTR( hdAgl );
lnAgl = ( SIZE( hdAgl ) - SIZE_SWORD ) / ( 2 * SIZE_SWORD );
if ( lnAgl < 3 && ptAgl[ 1 ] > 0 )
goto la;
if ( lnAgl < 3 && ptAgl[ 1 ] < 0 )
goto lb;
if (    ptAgl[ 1 ] != -1
|| ptAgl[ 5 ] !=  1
|| ( ptAgl[ 3 ] != 1 && ptAgl[ 3 ] != -1 )
|| ptAgl[ 0 ] != ptAgl[ 4 ] )
{
if ( ptAgl[ 1 ] > 0 )
goto la;
if ( ptAgl[ 1 ] < 0 )
goto lb;
}
if ( ptAgl[ 3 ] == 1 )
{
if ( ptAgl[ 2 ] > ptAgl[ 0 ] )
goto ld;
}
if ( ptAgl[ 3 ]  == -1 )
{
if ( lnAgl >= 4
&& ptAgl[ 7 ] == 1
&& ptAgl[ 0 ] > ptAgl[ 2 ]
&& ptAgl [ 2 ] == ptAgl[ 6 ] )
{
goto lc;
}
else
{
goto le;
}
}
Error( "relation %d is no Commutator/Conjugate/Power", nrRel, 0L );
return;
la:
i  = ptAgl[ 0 ];
ei = ptAgl[ 1 ];
if ( POWERS( hdGrp )[ i ] != 0 )
goto lerror;
INDICES( hdGrp )[ i ] = ei;
hdW = NewBag( T_AGLIST, ( 2 * ( lnAgl - 1 ) + 1 ) * SIZE_SWORD );
ptW = (TypSword*) PTR( hdW ) + 2 * ( lnAgl - 1 ) - 2;
ptW[ 2 ] = -1;
ptAgl = (TypSword*) PTR( hdAgl ) + 2;
while ( *ptAgl != -1 )
{
ptW[ 0 ] = *ptAgl++;
ptW[ 1 ] = - *ptAgl++;
ptW     -= 2;
}
POWERS( hdGrp )[ i ] = hdW;
return;
lb:
i  = ptAgl[ 0 ];
ei = ptAgl[ 1 ];
if ( POWERS( hdGrp )[ i ] != 0 )
goto lerror;
INDICES( hdGrp )[ i ] = -ei;
hdW   = NewBag( T_AGLIST, ( 2 * ( lnAgl - 1 ) + 1 ) * SIZE_SWORD );
ptW   = (TypSword*) PTR( hdW );
ptAgl = (TypSword*) PTR( hdAgl ) + 2;
while ( *ptAgl != -1 )
*ptW++ = *ptAgl++;
*ptW = -1;
POWERS( hdGrp )[ i ] = hdW;
return;
lc:
j = ptAgl[ 0 ];
i = ptAgl[ 2 ];
if ( COMMUTATORS( hdGrp )[ IND( j, i ) ] != 0 )
goto lerror;
hdW = NewBag( T_AGLIST, ( 2 * ( lnAgl - 4 ) + 1 ) * SIZE_SWORD );
ptW = (TypSword*) PTR( hdW ) + 2 * ( lnAgl - 4 ) - 2;
ptW[ 2 ] = -1;
ptAgl = (TypSword*) PTR( hdAgl ) + 8;
while ( *ptAgl != -1 )
{
ptW[ 0 ] = *ptAgl++;
ptW[ 1 ] = - *ptAgl++;
ptW     -= 2;
}
COMMUTATORS( hdGrp )[ IND( j, i ) ] = hdW;
return;
ld:
i = ptAgl[ 0 ];
j = ptAgl[ 2 ];
if ( COMMUTATORS( hdGrp )[ IND( j, i ) ] != 0 )
goto lerror;
hdW = NewBag( T_AGLIST, ( 2 * ( lnAgl - 3 ) + 3 ) * SIZE_SWORD );
ptW = (TypSword*) PTR( hdW ) + 2 * ( lnAgl - 3 );
ptW[ 2 ] = -1;
ptAgl = (TypSword*) PTR( hdAgl ) + 6;
while ( *ptAgl != -1 )
{
ptW[ 0 ] = *ptAgl++;
ptW[ 1 ] = - *ptAgl++;
ptW     -= 2;
}
ptW[ 0 ] = j;
ptW[ 1 ] = -1;
COMMUTATORS( hdGrp )[ IND( j, i ) ] = hdW;
return;
le:
i = ptAgl[ 0 ];
j = ptAgl[ 2 ];
if ( COMMUTATORS( hdGrp )[ IND( j, i ) ] != 0 )
goto lerror;
hdW = NewBag( T_AGLIST, ( 2 * ( lnAgl - 3 ) + 3 ) * SIZE_SWORD );
ptW = (TypSword*) PTR( hdW );
ptW[ 0 ] = j;
ptW[ 1 ] = -1;
ptW     += 2;
ptAgl = (TypSword*) PTR( hdAgl ) + 6;
while ( *ptAgl != -1 )
*ptW++ = *ptAgl++;
*ptW = -1;
COMMUTATORS( hdGrp )[ IND( j, i ) ] = hdW;
return;
lerror:
Error( "relation %d was already defined", nrRel, 0L );
}
void            ReadRelators ( hdRec, hdG )
TypHandle       hdRec,  hdG;
{
TypHandle       hdRels,  hdTmp,  hdRn;
TypHandle       * ptRec, * ptEnd;
TypSword        len;
long            i,  lnR;
len = NUMBER_OF_GENS( hdG );
hdRn  = FindRecname( "relators" );
ptRec = PTR( hdRec );
ptEnd = (TypHandle*)( (char*) ptRec + SIZE( hdRec ) );
while ( ptRec < ptEnd && ptRec[ 0 ] != hdRn )
ptRec += 2;
if ( ptRec == ptEnd )
{
hdRn  = FindRecname( "relations" );
ptRec = PTR( hdRec );
ptEnd = (TypHandle*)( (char*) ptRec + SIZE( hdRec ) );
while ( ptRec < ptEnd && ptRec[ 0 ] != hdRn )
ptRec += 2;
}
if ( ptRec == ptEnd )
Error( "AgGroupFpGroup: no '~.relators'.", 0L, 0L );
hdRels = ptRec[ 1 ];
if ( ! IsList( hdRels ) )
Error( "AgGroupFpGroup: no list '~.relators'.", 0L, 0L );
lnR = LEN_LIST( hdRels );
hdTmp = NewBag( T_LIST, ( len + 1 ) * SIZE_HD );
PTR( hdTmp )[ 0 ] = INT_TO_HD( len );
HD_POWERS( hdG ) = hdTmp;
hdTmp = NewBag( T_LIST, ( len * ( len - 1 ) / 2 + 1 ) * SIZE_HD );
PTR( hdTmp )[ 0 ] = INT_TO_HD( len * (len - 1 ) / 2 );
HD_COMMUTATORS( hdG ) = hdTmp;
hdTmp = NewBag( T_LIST, ( len * ( len - 1 ) / 2 + 1 ) * SIZE_HD );
PTR( hdTmp )[ 0 ] = INT_TO_HD( len * (len - 1 ) / 2 );
HD_CONJUGATES( hdG ) = hdTmp;
hdTmp = NewBag( T_INTPOS, len * sizeof( long ) );
HD_INDICES( hdG ) = hdTmp;
HD_COLLECTOR( hdG ) = INT_TO_HD( SINGLE_COLLECTOR );
SetStacksAgGroup( hdG );
for ( i = lnR; i > 0; i-- )
if ( PTR( hdRels )[ i ] != 0 )
CopyRelation( PTR( hdRels )[ i ], hdG, i+1 );
for ( i = len - 1; i >= 0; i-- )
EvalGenRels( hdG, i );
}

TypHandle           HdCallOop1;
TypHandle           HdCallOop2;
TypHandle       EvalOop ( hdObject, hdRecName, ErrorMsg )
TypHandle       hdObject;
TypHandle       hdRecName;
char            * ErrorMsg;
{
TypHandle       * ptRec, * ptEnd;
TypHandle       hdOp, hdTmp;
if ( TYPE( hdObject ) == T_REC )
{
ptRec = PTR( hdObject );
ptEnd = (TypHandle*) ( (char*) ptRec + SIZE( hdObject ) );
while ( ptRec < ptEnd && ptRec[ 0 ] != HdRnOp )
ptRec += 2;
if ( ptRec == ptEnd || TYPE( ptRec[ 1 ] ) != T_REC )
goto l1;
hdOp  = ptRec[ 1 ];
ptRec = PTR( hdOp );
ptEnd = (TypHandle*) ( (char*) ptRec + SIZE( hdOp ) );
while ( ptRec < ptEnd && ptRec[ 0 ] != hdRecName )
ptRec += 2;
if ( ptRec == ptEnd )
goto l1;
PTR( HdCallOop1 )[ 0 ] = ptRec[ 1 ];
PTR( HdCallOop1 )[ 1 ] = hdObject;
hdTmp = EVAL( HdCallOop1 );
PTR( HdCallOop1 )[ 0 ] = 0;
PTR( HdCallOop1 )[ 1 ] = 0;
return hdTmp;
}
l1:
return Error( ErrorMsg, 0L, 0L );
}
TypHandle       EvalOop2( hdObjectL, hdObjectR, hdRecName, ErrorMsg )
TypHandle       hdObjectL, hdObjectR;
TypHandle       hdRecName;
char            * ErrorMsg;
{
TypHandle       * ptRec, * ptEnd;
TypHandle       hdOp, hdTmp;
if ( TYPE( hdObjectL ) == T_REC )
{
ptRec = PTR( hdObjectL );
ptEnd = (TypHandle*) ( (char*) ptRec + SIZE( hdObjectL ) );
while ( ptRec < ptEnd && ptRec[ 0 ] != HdRnOp )
ptRec += 2;
if ( ptRec == ptEnd || TYPE( ptRec[ 1 ] ) != T_REC )
goto l1;
hdOp  = ptRec[ 1 ];
ptRec = PTR( hdOp );
ptEnd = (TypHandle*) ( (char*) ptRec + SIZE( hdOp ) );
while ( ptRec < ptEnd && ptRec[ 0 ] != hdRecName )
ptRec += 2;
if ( ptRec == ptEnd )
goto l1;
PTR( HdCallOop2 )[ 0 ] = ptRec[ 1 ];
PTR( HdCallOop2 )[ 1 ] = hdObjectL;
PTR( HdCallOop2 )[ 2 ] = hdObjectR;
hdTmp = EVAL( HdCallOop2 );
PTR( HdCallOop2 )[ 0 ] = 0;
PTR( HdCallOop2 )[ 1 ] = 0;
PTR( HdCallOop2 )[ 2 ] = 0;
return hdTmp;
}
l1:
if ( TYPE( hdObjectR ) == T_REC )
{
ptRec = PTR( hdObjectR );
ptEnd = (TypHandle*) ( (char*) ptRec + SIZE( hdObjectR ) );
while ( ptRec < ptEnd && ptRec[ 0 ] != HdRnOp )
ptRec += 2;
if ( ptRec == ptEnd || TYPE( ptRec[ 1 ] ) != T_REC )
goto l2;
hdOp  = ptRec[ 1 ];
ptRec = PTR( hdOp );
ptEnd = (TypHandle*) ( (char*) ptRec + SIZE( hdOp ) );
while ( ptRec < ptEnd && ptRec[ 0 ] != hdRecName )
ptRec += 2;
if ( ptRec == ptEnd )
goto l2;
PTR( HdCallOop2 )[ 0 ] = ptRec[ 1 ];
PTR( HdCallOop2 )[ 1 ] = hdObjectL;
PTR( HdCallOop2 )[ 2 ] = hdObjectR;
hdTmp = EVAL( HdCallOop2 );
PTR( HdCallOop2 )[ 0 ] = 0;
PTR( HdCallOop2 )[ 1 ] = 0;
PTR( HdCallOop2 )[ 2 ] = 0;
return hdTmp;
}
l2:
return Error( ErrorMsg, 0L, 0L );
}
TypHandle       EvalOopN ( hdObject, hdRecName, hdCall, ErrorMsg )
TypHandle       hdObject;
TypHandle       hdRecName;
TypHandle       hdCall;
char            * ErrorMsg;
{
TypHandle       * ptRec, * ptEnd, * ptCall, * ptTmp;
TypHandle       hdOp, hdTmp;
if ( TYPE( hdObject ) == T_REC )
{
ptRec = PTR( hdObject );
ptEnd = (TypHandle*) ( (char*) ptRec + SIZE( hdObject ) );
while ( ptRec < ptEnd && ptRec[ 0 ] != HdRnOp )
ptRec += 2;
if ( ptRec == ptEnd || TYPE( ptRec[ 1 ] ) != T_REC )
goto l1;
hdOp  = ptRec[ 1 ];
ptRec = PTR( hdOp );
ptEnd = (TypHandle*) ( (char*) ptRec + SIZE( hdOp ) );
while ( ptRec < ptEnd && ptRec[ 0 ] != hdRecName )
ptRec += 2;
if ( ptRec == ptEnd )
goto l1;
hdTmp  = NewBag( T_FUNCCALL, SIZE( hdCall ) );
ptTmp  = PTR( hdTmp );
ptCall = PTR( hdCall );
ptEnd  = (TypHandle*)( (char*) ptCall + SIZE( hdCall ) );
while ( ptCall < ptEnd )
* ptTmp++ = * ptCall++;
PTR( hdTmp )[ 0 ] = ptRec[ 1 ];
return EVAL( hdTmp );
}
l1:
return Error( ErrorMsg, 0L, 0L );
}
TypHandle       AgWordAgExp ( hdExp, hdGrp )
TypHandle      hdExp;
TypHandle      hdGrp;
{
TypHandle       hdWrd;
TypSword        * ptWrd;
TypExp          * ptExp,  * ptEnd;
long            lnWrd,  idx = 0;
lnWrd = 0;
ptExp = (TypExp*) PTR( hdExp );
ptEnd = (TypExp*) ( (char*) ptExp + SIZE( hdExp ) );
while ( ptExp < ptEnd && *ptExp == 0 )
ptExp++;
if ( ptExp < ptEnd )
idx = ptExp - (TypExp*) PTR( hdExp );
while ( ptExp < ptEnd )
if ( *ptExp++ )
lnWrd++;
if ( lnWrd == 0 )
return HD_IDENTITY( hdGrp );
hdWrd = NewBag( T_AGWORD, SIZE_HD + (2 * lnWrd + 1) * SIZE_SWORD );
ptWrd = PTR_AW( hdWrd );
*( PTR( hdWrd ) ) = hdGrp;
ptExp  = (TypExp*) PTR( hdExp ) + idx;
while ( lnWrd > 0 )
{
if ( *ptExp )
{
*( ptWrd++ ) = idx;
*( ptWrd++ ) = *ptExp;
*ptExp = 0;
lnWrd--;
}
idx++;
ptExp++;
}
*ptWrd = -1;
return hdWrd;
}
void        SetCollectExponents ( hdWrd )
TypHandle      hdWrd;
{
long           nrGens;
TypSword       * ptWrd;
TypExp         * ptExp;
TypHandle      hdGrp;
hdGrp  = * PTR( hdWrd );
nrGens = NUMBER_OF_GENS( hdGrp );
ptExp = COLLECT_EXPONENTS( hdGrp );
for ( ptWrd = PTR_AW( hdWrd ); *ptWrd != -1; ptWrd += 2 )
ptExp[ (long)( *ptWrd ) ] = *( ptWrd + 1 );
}
void        ClearCollectExponents ( hdAgGroup )
TypHandle      hdAgGroup;
{
TypExp         * ptExp, * ptEnd;
ptExp  = COLLECT_EXPONENTS( hdAgGroup );
ptEnd  = (TypExp*)( (char*)ptExp + NUMBER_OF_GENS(hdAgGroup)*SIZE_EXP );
for ( ; ptExp < ptEnd; ptExp++ )
* ptExp = 0;
}
TypHandle       HeadAgWord( hdAgWord, nrNew )
TypHandle       hdAgWord;
long            nrNew;
{
long            nrGens;
TypSword        * ptAgWord, * ptNew;
TypHandle       hdNew;
ptAgWord = PTR_AW( hdAgWord );
nrGens   = 0;
while ( * ptAgWord != -1 && * ptAgWord < nrNew )
{
nrGens++;
ptAgWord += 2;
}
hdNew = NewBag( T_AGWORD, SIZE_HD + ( 2 * nrGens + 1 ) * SIZE_SWORD );
*PTR( hdNew ) = *PTR( hdAgWord );
ptNew    = PTR_AW( hdNew );
ptAgWord = PTR_AW( hdAgWord );
for ( ; nrGens > 0; nrGens-- )
{
*( ptNew++ ) = *( ptAgWord++ );
*( ptNew++ ) = *( ptAgWord++ );
}
*ptNew = -1;
return hdNew;
}
long            FindAgenNr( hdAgen, hdAgGroup )
TypHandle       hdAgen, hdAgGroup;
{
long            k, nrGens;
TypHandle       * ptGens;
nrGens = NUMBER_OF_GENS( hdAgGroup );
ptGens = WORDS( hdAgGroup ) + ( nrGens - 1 );
for ( k = nrGens - 1; k >= 0; k--, ptGens-- )
{
if ( hdAgen == *ptGens )
return k + 1;
if ( hdAgen == PTR( *ptGens )[ 0 ] )
return - ( k + 1 );
}
return 0;
}
TypHandle       AgListWord ( hdWrd, hdGrp )
TypHandle       hdWrd;	
TypHandle       hdGrp;
{
TypHandle           hdAgl;
TypSword *          ptAgl;
TypHandle *         ptWrd;
TypHandle *         ptWrdEnd;
TypHandle *         ptWrd1;
TypHandle *         ptLst;
TypHandle *         ptLstBeg;
TypHandle *         ptLstEnd;
TypHandle           hdGen;
TypHandle           hdInv;
if ( TYPE(hdWrd) == T_SWORD )
hdWrd = WordSword( hdWrd );
else if ( TYPE(hdWrd) != T_WORD )
return HdFalse;
hdAgl = NewBag( T_AGLIST, (2 * SIZE(hdWrd)/SIZE_HD + 1) * SIZE_SWORD );
ptAgl = (TypSword*)PTR( hdAgl );
ptWrd    = PTR( hdWrd );
ptWrdEnd = PTR( hdWrd ) + SIZE( hdWrd ) / SIZE_HD;
hdGen    = HD_WORDS( hdGrp );
ptLstBeg = PTR( hdGen ) + 1;
ptLstEnd = PTR( hdGen ) + 1 + LEN_LIST( hdGen );
ptLst    = ptLstEnd - 1;
for ( ptWrd = PTR(hdWrd); ptWrd < ptWrdEnd; ptWrd = ptWrd1 ) {
hdGen = *ptWrd;
hdInv = *PTR(hdGen);
while ( ptLstBeg <= ptLst && *ptLst != hdGen && *ptLst != hdInv )
ptLst--;
if ( ptLst < ptLstBeg ) {
ptLst = ptLstEnd - 1;
while ( ptLstBeg <= ptLst && *ptLst != hdGen && *ptLst != hdInv )
ptLst--;
if ( ptLst < ptLstBeg )
return HdFalse;
}
ptWrd1 = ptWrd+1;
while ( ptWrd1 < ptWrdEnd && *ptWrd1 == hdGen )
ptWrd1++;
*ptAgl++ = ptLst - ptLstBeg;
*ptAgl++ = (*ptLst == hdGen) ? (ptWrd1 - ptWrd) : (ptWrd - ptWrd1);
}
*ptAgl++ = -1;
Resize( hdAgl, (ptAgl - (TypSword*)PTR(hdAgl)) * SIZE_SWORD );
return hdAgl;
}
TypHandle           BlankAgGroup ()
{
TypHandle           hdAgGroup, hdRnName;
long                i;
hdAgGroup = NewBag( T_REC, SIZE_HD * ( NR_COLLECTOR_LAST + 1 ) );
hdRnName = FindRecname( "unused" );
for ( i = ( NR_COLLECTOR_LAST - 1 ) / 2; i >= 0; i-- )
{
PTR( hdAgGroup )[ 2 * i ] = hdRnName;
PTR( hdAgGroup )[ 2 * i + 1 ] = INT_TO_HD( 0 );
}
hdRnName = FindRecname( "generators" );
PTR( hdAgGroup )[ NR_GENERATORS - 1 ] = hdRnName;
hdRnName = FindRecname( "identity" );
PTR( hdAgGroup )[ NR_IDENTITY - 1 ] = hdRnName;
hdRnName = FindRecname( "words" );
PTR( hdAgGroup )[ NR_WORDS - 1 ] = hdRnName;
hdRnName = FindRecname( "powers" );
PTR( hdAgGroup )[ NR_POWERS - 1 ] = hdRnName;
hdRnName = FindRecname( "indices" );
PTR( hdAgGroup )[ NR_INDICES - 1 ] = hdRnName;
hdRnName = FindRecname( "commutators" );
PTR( hdAgGroup )[ NR_COMMUTATORS - 1 ] = hdRnName;
hdRnName = FindRecname( "collector" );
PTR( hdAgGroup )[ NR_COLLECTOR - 1 ] = hdRnName;
hdRnName = FindRecname( "numberGenerators" );
PTR( hdAgGroup )[ NR_NUMBER_OF_GENS - 1 ] = hdRnName;
hdRnName = FindRecname( "saveExponents" );
PTR( hdAgGroup )[ NR_SAVE_EXPONENTS - 1 ] = hdRnName;
hdRnName = FindRecname( "collectExponents" );
PTR( hdAgGroup )[ NR_COLLECT_EXPONENTS - 1 ] = hdRnName;
return hdAgGroup;
}
void        SetGeneratorsAgGroup( hdAgGroup )
TypHandle       hdAgGroup;
{
long            nrGens, i;
TypHandle       hdList, hdAgWord;
nrGens = NUMBER_OF_GENS( hdAgGroup );
hdList = NewBag( T_LIST, ( nrGens + 1 ) * SIZE_HD );
PTR( hdList )[ 0 ] = INT_TO_HD( nrGens );
for ( i = nrGens; i >= 1; i-- )
{
hdAgWord = NewBag( T_AGWORD, SIZE_HD + 3 * SIZE_SWORD );
*PTR( hdAgWord ) = hdAgGroup;
PTR_AW( hdAgWord )[ 0 ] = i - 1;
PTR_AW( hdAgWord )[ 1 ] = 1;
PTR_AW( hdAgWord )[ 2 ] = -1;
PTR( hdList )[ i ] = hdAgWord;
}
HD_GENERATORS( hdAgGroup ) = hdList;
hdAgWord = NewBag( T_AGWORD, SIZE_HD + SIZE_SWORD );
*PTR( hdAgWord ) = hdAgGroup;
PTR_AW( hdAgWord )[ 0 ] = -1;
HD_IDENTITY( hdAgGroup ) = hdAgWord;
}
TypHandle   HdRnAvec;
void            SetAvecAgGroup ( hdAgGroup, low, high )
TypHandle           hdAgGroup;
long                low;
long                high;
{
TypHandle           hdAvec;
long *              ptAvec;
long                nrGens;
TypHandle *         ptComms;
TypHandle           hdId;
long                i, k, l;
nrGens  = NUMBER_OF_GENS( hdAgGroup );
hdId    = HD_IDENTITY( hdAgGroup );
if ( PTR(hdAgGroup)[NR_AVEC-1] != HdRnAvec ) {
PTR(hdAgGroup)[NR_AVEC-1] = HdRnAvec;
hdAvec = NewBag( T_INTPOS, nrGens * sizeof(long) );
HD_AVEC( hdAgGroup ) = hdAvec;
}
hdAvec  = HD_AVEC( hdAgGroup );
ptAvec  = (long*) PTR(hdAvec);
ptComms = COMMUTATORS( hdAgGroup );
for ( i = high; low <= i;  i-- ) {
k = (i == nrGens-1 ? nrGens+1 : ptAvec[i+1]);
if ( k == i+2 )  k = i+1;
l = nrGens;
while ( k <= l-1 && ptComms[ IND( l-1, i ) ] == hdId )
l--;
ptAvec[i] = l;
}
}
boolean     SetCWeightsAgGroup ( hdGrp, hdLst )
TypHandle       hdGrp;
TypHandle       hdLst;
{
TypHandle       hdWeights, hdSeries, hdId, hdRnName, hd;
TypHandle       * comms, * powers;
TypHandle       * ptComms;
long            * ptWeightI, * ptWeightJ, * ptWeightK;
long            * ptSeries, * ptWeights, * ptIndices;
long            nrGens, i, j, k, prime, max;
char            * str;
str = "#W  SetCollectorAgWord: %s\n";
nrGens    = NUMBER_OF_GENS( hdGrp );
hdWeights = NewBag( T_INTPOS, nrGens * sizeof( long ) );
ptWeights = (long*) PTR( hdWeights );
powers    = POWERS( hdGrp );
comms     = COMMUTATORS( hdGrp );
if ( hdLst == HdVoid )
for ( i = nrGens - 1; i >= 0; i-- )
ptWeights[ i ] = 1;
else
{
if ( LEN_LIST( hdLst ) != nrGens )
{
Pr( str, (long) "too few/many weights", 0L );
return FALSE;
}
for ( i = nrGens - 1; i >= 0; i-- )
{
if ( TYPE( PTR( hdLst )[ i + 1 ] ) != T_INT )
{
Pr( str, (long) "weights must integers", 0L );
return FALSE;
}
ptWeights[ i ] = HD_TO_INT( PTR( hdLst )[ i + 1 ] );
}
}
if ( hdLst == HdVoid )
{
ptWeightI = ptWeights + 1;
for ( i = 1; i < nrGens; i++, ptWeightI++ )
{
ptWeightJ = ptWeights;
for ( j = 0; j < i; j++, ptWeightJ++ )
{
ptWeightK = ptWeights;
ptComms   = & comms[ IND( j, 0 ) ];
for  ( k = 0; k < j; k++, ptWeightK++, ptComms++ )
{
hd = * ptComms;
if ( SIZE( hd ) == SIZE_HD + 3 * SIZE_SWORD
&& PTR_AW( hd )[ 0 ] == i )
{
* ptWeightI = MAX( * ptWeightI,
(* ptWeightK) + (* ptWeightJ) );
}
}
hd = powers[ j ];
if ( SIZE( hd ) == SIZE_HD + 3 * SIZE_SWORD
&& PTR_AW( hd )[ 0 ] == i )
{
* ptWeightI = MAX( * ptWeightI, ( * ptWeightJ ) + 1 );
}
}
}
max = 1;
for ( i = nrGens - 1; i >= 0; i-- )
max = MAX( max, ptWeights[ i ] );
if ( hdLst == HdVoid )
{
i = 1;
while ( i < nrGens && ptWeights[ i - 1 ] <= ptWeights[ i ] )
i++;
for ( ; i < nrGens; i++ )
ptWeights[ i ] = max;
}
}
for ( i = 1; i < nrGens; i++ )
{
if (  ptWeights[ i ] != ptWeights[ i-1 ]
&& ptWeights[ i ] != ( ptWeights[ i-1 ] + 1 ) )
{
Pr( str, (long) "incorrect central weights", 0L );
return FALSE;
}
}
hdSeries  = NewBag( T_INTPOS, ( nrGens + 1 ) * sizeof( long ) );
ptSeries  = (long*) PTR( hdSeries );
ptWeights = (long*) PTR( hdWeights );
powers    = POWERS( hdGrp );
comms     = COMMUTATORS( hdGrp );
ptIndices = INDICES( hdGrp );
prime = ptIndices[ 0 ];
for ( i = nrGens - 1; i > 0; i-- )
if ( prime != ptIndices[ i ] )
{
Pr( str, (long) "different indices", 0L );
return FALSE;
}
for ( i = 2; i < prime; i++ )
if ( prime % i == 0 )
{
Pr( str, (long) "no p-group", 0L );
return FALSE;
}
ptSeries[ 0 ] = 1;
for ( i = 0; i < nrGens; i++ )
{
if ( ptWeights[ i ] > ptSeries[ 0 ] )
{
ptSeries[ ptSeries[ 0 ] ] = i - 1;
ptSeries[ 0 ]++;
}
else if ( ptWeights[ i ] < ptSeries[ 0 ] )
{
Pr( str, (long) "incorrect central weights", 0L );
return FALSE;
}
}
ptSeries[ ptSeries[ 0 ] ] = i - 1;
hdId = HD_IDENTITY( hdGrp );
for ( i = 0; i < nrGens; i++ )
{
for ( j = 0; j < i; j++ )
{
hd = comms[ IND( i, j ) ];
if ( hd != hdId )
if ( ptWeights[ *PTR_AW(hd) ] < ptWeights[i]+ptWeights[j] )
{
Pr( str, (long) "commutator weights do not add.", 0L );
Pr( "#W  commutator [ %s, %s ] failed.\n",
(long) NAME_AW( hdGrp, i ),
(long) NAME_AW( hdGrp, j ) );
return FALSE;
}
}
hd = powers[ i ];
if ( hd != hdId )
if ( ptWeights[ *PTR_AW( hd )] < ptWeights[ i ] + 1  )
{
Pr( str, (long) "power weight does not change", 0L );
Pr( "#W  power %s ^ %d failed.\n",
(long) NAME_AW( hdGrp, i ), prime );
return FALSE;
}
}
Resize( hdSeries, ( ptSeries[ 0 ] + 1 ) * sizeof( long ) );
HD_CSERIES( hdGrp ) = hdSeries;
hdRnName = FindRecname( "centralSeries" );
PTR( hdGrp )[ NR_CSERIES - 1 ] = hdRnName;
HD_CWEIGHTS( hdGrp ) = hdWeights;
hdRnName = FindRecname( "centralWeights" );
PTR( hdGrp )[ NR_CWEIGHTS - 1 ] = hdRnName;
return TRUE;
}
void        SetStacksAgGroup( hdAgGroup )
TypHandle       hdAgGroup;
{
TypHandle       hdList = 0, hdTmp;
long            stackSize;
stackSize = NUMBER_OF_GENS( hdAgGroup ) * 10;
switch ( (int) COLLECTOR( hdAgGroup ) )
{
case SINGLE_COLLECTOR:
hdList = NewBag( T_LIST, 5 * SIZE_HD );
PTR( hdList )[ 0 ] = INT_TO_HD( 4 );
hdTmp = NewBag( T_STRING, stackSize * sizeof(TypSword*) );
PTR( hdList )[ 1 ] = hdTmp;
hdTmp = NewBag( T_STRING, stackSize * sizeof(TypSword*) );
PTR( hdList )[ 2 ] = hdTmp;
hdTmp = NewBag( T_INTPOS, stackSize * SIZE_EXP );
PTR( hdList )[ 3 ] = hdTmp;
hdTmp = NewBag( T_INTPOS, stackSize * SIZE_EXP );
PTR( hdList )[ 4 ] = hdTmp;
break;
case QUADR_COLLECTOR:
case TRIPLE_COLLECTOR:
hdList = NewBag( T_LIST, 4 * SIZE_HD );
PTR( hdList )[ 0 ] = INT_TO_HD( 3 );
hdTmp = NewBag( T_STRING, stackSize * sizeof(TypSword*) );
PTR( hdList )[ 1 ] = hdTmp;
hdTmp = NewBag( T_INTNEG, stackSize * SIZE_SWORD );
PTR( hdList )[ 2 ] = hdTmp;
hdTmp = NewBag( T_INTNEG, stackSize * SIZE_SWORD );
PTR( hdList )[ 3 ] = hdTmp;
break;
case LEE_COLLECTOR:
case COMBI_COLLECTOR:
case COMBI2_COLLECTOR:
if ( INDICES( hdAgGroup )[ 0 ] > 2 )
{
hdList = NewBag( T_LIST, 4 * SIZE_HD );
PTR( hdList )[ 0 ] = INT_TO_HD( 3 );
hdTmp = NewBag( T_STRING, stackSize * sizeof(TypSword*) );
PTR( hdList )[ 1 ] = hdTmp;
hdTmp = NewBag( T_INTNEG, stackSize * SIZE_SWORD );
PTR( hdList )[ 2 ] = hdTmp;
hdTmp = NewBag( T_INTPOS, stackSize * SIZE_EXP );
PTR( hdList )[ 3 ] = hdTmp;
}
else
{
hdList = NewBag( T_LIST, 3 * SIZE_HD );
PTR( hdList )[ 0 ] = INT_TO_HD( 2 );
hdTmp = NewBag( T_STRING, stackSize * sizeof( TypSword* ) );
PTR( hdList )[ 1 ] = hdTmp;
hdTmp = NewBag( T_INTNEG, stackSize * SIZE_SWORD );
PTR( hdList )[ 2 ] = hdTmp;
};
break;
default:
Error(
"SetCollectorAgWord: cannot initialize stacks for collector %d",
(long) COLLECTOR( hdAgGroup ), 0L );
}
HD_STACKS( hdAgGroup ) = hdList;
hdTmp = FindRecname( "stacks" );
PTR( hdAgGroup )[ NR_STACKS - 1 ] = hdTmp;
}
TypHandle   SaveAndClearCollector( hdAgGroup )
TypHandle       hdAgGroup;
{
TypHandle       hdSave, hdZero, hdRnName;
long            nrEntries, i;
nrEntries = ( NR_COLLECTOR_LAST - NR_COLLECTOR_FIRST + 2 ) / 2;
hdSave = NewBag( T_LIST, ( 2 * nrEntries + 2 ) * SIZE_HD );
PTR( hdSave )[ 0 ] = INT_TO_HD( 2 * nrEntries + 1 );
PTR( hdSave )[ 1 ] = HD_COLLECTOR( hdAgGroup );
for ( i = nrEntries * 2; i >= 1; i-- )
PTR( hdSave )[ i+1 ] = PTR( hdAgGroup )[ NR_COLLECTOR_FIRST-2+i ];
hdRnName = FindRecname( "unused" );
hdZero = INT_TO_HD( 0 );
for ( i = nrEntries - 1; i >= 0; i-- )
{
PTR( hdAgGroup )[ NR_COLLECTOR_FIRST - 1 + 2 * i ] = hdRnName;
PTR( hdAgGroup )[ NR_COLLECTOR_FIRST + 2 * i ] = hdZero;
}
return hdSave;
}
void        RestoreCollector( hdAgGroup, hdSave )
TypHandle       hdAgGroup;
TypHandle       hdSave;
{
long            nrEntries, i;
nrEntries = ( NR_COLLECTOR_LAST - NR_COLLECTOR_FIRST + 2 ) / 2;
HD_COLLECTOR( hdAgGroup ) = PTR( hdSave )[ 1 ] ;
for ( i = nrEntries * 2; i >= 1; i-- )
PTR( hdAgGroup )[ NR_COLLECTOR_FIRST-2+i ] = PTR( hdSave )[ i+1 ];
}
/* 当前文件是D:\Read\aggroup.c*/

/* 当前文件是D:\Read\finfield.h*/

#ifdef SPEC_CPU2000_P64
#define long __int64
#endif
typedef unsigned short          TypFFE;
#define SUCC_FF(FF)             ((TypFFE*)PTR(FF))
#define SIZE_FF(FF)             (*SUCC_FF(FF)+1)
#define FLD_FFE(FFE)            (PTR(FFE)[0])
#define SET_FLD_FFE(FFE,FF)     (FLD_FFE(FFE)=(FF))
#define VAL_FFE(FFE)            (*(TypFFE*)(PTR(FFE)+1))
#define SET_VAL_FFE(FFE,VAL)    (VAL_FFE(FFE)=(VAL))
#define SUM_FF(a,b,f)   ( (a)==0 || (b)==0 ? (a)+(b) :\
( (a)<=(b) ? PROD_FF(a,(f)[(b)-(a)+1],f) :\
PROD_FF(b,(f)[(a)-(b)+1],f) ) )
#define NEG_FF(a,f)     ( (a)==0 ? 0 :\
( *(f)%2==1 ? a :\
( (a)<=*(f)/2 ? (a)+*(f)/2 : (a)-*(f)/2 ) ) )
#define PROD_FF(a,b,f)  ( (a)==0 || (b)==0 ? 0 :\
( (a)-1<=*(f)-(b) ? (a)-1+(b) : (a)-1-(*(f)-(b)) ))
#define QUO_FF(a,b,f)   ( (a)==0 ? 0 :\
( (b)<=(a) ? (a)-(b)+1 : (*f)-(b)+1+(a) ) )
#define POW_FF(a,n,f)   ( (n)==0 ? 1 :\
( (a)==0 ? 0 : (((a)-1) * (n)) % *(f) + 1 ) )



















TypHandle       EqAg( hdL, hdR )
TypHandle       hdL, hdR;
{
TypSword        * ptL, * ptR;
if ( SIZE( hdL ) != SIZE( hdR )  )
return HdFalse;
if ( *PTR( hdL ) != *PTR( hdR ) )
return HdFalse;
if ( ISID_AW( hdL ) )
return HdTrue;
ptL = PTR_AW( hdL );
ptR = PTR_AW( hdR );
while ( *ptL != -1 )
if ( *( ptL++ ) != *( ptR++ ) )
return HdFalse;
return HdTrue;
}
TypHandle       LtAg( hdL, hdR )
TypHandle       hdL, hdR;
{
TypSword        * ptL, * ptR;
long            i, lenR, lenL;
if ( *PTR( hdL ) != *PTR( hdR ) )
{
if ( NUMBER_OF_GENS( *PTR( hdL ) ) < NUMBER_OF_GENS( *PTR( hdR ) ) )
return HdTrue;
if ( NUMBER_OF_GENS( *PTR( hdL ) ) > NUMBER_OF_GENS( *PTR( hdR ) ) )
return HdFalse;
if ( (long) *PTR( hdL ) < (long) *PTR( hdR ) )
return HdTrue;
else
return HdFalse;
}
lenR = LEN_AW( hdR );
if ( lenR == 0 )
return HdFalse;
lenL = LEN_AW( hdL );
if ( lenL == 0 )
return HdTrue;
ptL = PTR_AW( hdL );
ptR = PTR_AW( hdR );
for ( i = MIN( lenL, lenR ); i > 0; --i )
{
if ( *ptL != *ptR )
if ( *ptL < *ptR )
return HdFalse;
else
return HdTrue;
ptL++;
ptR++;
if ( *ptL != *ptR )
if ( *ptL > *ptR )
return HdFalse;
else
return HdTrue;
ptL++;
ptR++;
}
return ( lenL < lenR ) ? HdTrue : HdFalse;
}
TypHandle       EvAg( hdWrd )
TypHandle       hdWrd;
{
return hdWrd;
}
TypHandle       ProdAg ( hdL, hdR )
TypHandle       hdL,  hdR;
{
TypHandle       hd, hdAgGroup;
long            nrL, nrR, i;
TypSword        * pnew, * pold;
hdAgGroup = *PTR( hdL );
if ( hdAgGroup != *PTR( hdR ) )
return Error( "AgWord op: agwords have different groups", 0L, 0L );
nrL = LEN_AW( hdL );
if ( nrL == 0 )
return hdR;
nrR = LEN_AW( hdR );
if ( nrR == 0 )
return hdL;
if ( PTR_AW( hdL )[ 2 * ( nrL - 1 ) ] < PTR_AW( hdR )[ 0 ] )
{
hd = NewBag( T_AGWORD, (2*(nrL + nrR) + 1) * SIZE_SWORD + SIZE_HD );
*PTR( hd ) = hdAgGroup;
pold = PTR_AW( hdL );
pnew = PTR_AW( hd );
for( i = 2 * nrL; i > 0; --i )
*( pnew++ ) = *( pold++ );
pold = PTR_AW( hdR );
for ( i = 2 * nrR + 1; i > 0; --i )
*( pnew++ ) = *( pold++ );
return hd;
}
Collect( 0, hdL, hdR );
return AgWordAgExp( HD_COLLECT_EXPONENTS( hdAgGroup ), hdAgGroup );
}
TypHandle       PowAgI( hdL, hdR )
TypHandle       hdL,  hdR;
{
register long   i,  exp, pow, nr;
TypHandle       hd, hdGrp, hd1;
TypSword        * pt1, * pt2;
exp   = HD_TO_INT( hdR );
hdGrp = *PTR( hdL );
nr = LEN_AW( hdL );
if ( nr == 0 )
return hdL;
if ( exp == 0 )
return HD_IDENTITY( hdGrp );
if ( exp == 1 )
return hdL;
if ( exp > 0  &&  nr == 1 )
{
hd = NewBag( T_AGWORD, SIZE( hdL ) );
* PTR( hd ) = hdGrp;
pt1 = PTR_AW( hd );
pt2 = PTR_AW( hdL );
*( pt1++ ) = *pt2 ;
*( pt1+1 ) = -1;
i = exp * *( pt2 + 1 );
pow = INDICES( hdGrp )[ *pt2 ];
if ( i >= pow )
{
*pt1 = i % pow;
hd1 = POWERS( hdGrp )[ *pt2 ];
if ( *pt1 == 0 )
{
*( pt1-1 ) = -1;
Resize( hd, SIZE_HD + SIZE_SWORD );
}
if ( LEN_AW( hd1 ) )
hd = ProdAg( hd, PowAgI( hd1, INT_TO_HD( i / pow ) ) );
}
else
*pt1 = i;
return hd;
}
if ( exp == 2 )
return ProdAg( hdL, hdL );
else if ( exp == 3 )
return ProdAg( hdL, ProdAg( hdL, hdL ) );
else if ( exp > 0 )
{
if  ( exp % 2 )
{
hd = PowAgI( hdL, INT_TO_HD( (exp - 1) / 2 ) );
return ProdAg( hdL, ProdAg( hd, hd ) );
}
else
{
hd = PowAgI( hdL, INT_TO_HD( exp / 2 ) );
return ProdAg( hd, hd );
}
}
else if ( exp == -1 )
return AgSolution( hdL, HD_IDENTITY( hdGrp ) );
else
{
hd = PowAgI( hdL, INT_TO_HD( -exp ) );
return AgSolution( hd, HD_IDENTITY( hdGrp ) );
}
}
TypHandle       QuoAg( hdL, hdR )
TypHandle       hdL,  hdR;
{
return ProdAg( hdL, PowAgI( hdR, INT_TO_HD( -1 ) ) );
}
TypHandle       ModAg( hdL, hdR )
TypHandle       hdL, hdR;
{
if ( *PTR( hdR ) != *PTR( hdL ) )
return Error( "AgWord op: agwords have different groups", 0L, 0L );
if ( ISID_AW( hdL ) )
return hdR;
return AgSolution( hdL, hdR );
}
TypHandle       PowAgAg( hdL, hdR )
TypHandle       hdL,  hdR;
{
if ( *PTR( hdL ) != *PTR( hdR ) )
return Error( "AgWord op: agwords have different groups", 0L, 0L );
if ( ISID_AW( hdL ) || ISID_AW( hdR ) )
return hdL;
return AgSolution2( hdR, HD_IDENTITY( *PTR( hdL ) ), hdL, hdR );
}
TypHandle       CommAg( hdL, hdR )
TypHandle           hdL,  hdR;
{
TypHandle           hdC;
#   if USE_COMMS
TypHandle       hdId,  hdGrp;
long            nrL,   nrR;
TypSword        genL,  genR;
#   endif
if ( *PTR( hdL ) != *PTR( hdR ) )
return Error( "AgWord op: agwords have different groups", 0L, 0L );
#   if USE_COMMS
nrL = LEN_AW( hdL );
if ( nrL == 0 )
return hdL;
nrR = LEN_AW( hdR );
if ( nrR == 0 )
return hdR;
#   else
if ( ISID_AW( hdL ) )
return hdL;
if ( ISID_AW( hdR ) )
return hdR;
#   endif
#   if USE_COMMS
hdGrp = *PTR( hdL );
if ( nrL == 1
&& nrR == 1
&& PTR_AW( hdL )[ 1 ] == 1 && PTR_AW( hdR )[ 1 ] == 1 )
{
hdId = HD_IDENTITY( hdGrp );
genL = PTR_AW( hdL )[ 0 ];
genR = PTR_AW( hdR )[ 0 ];
if ( genL < genR )
hdC = COMMUTATORS( hdGrp )[ IND( genR, genL ) ];
else if ( genL > genR )
hdC = COMMUTATORS( hdGrp )[ IND( genL, genR ) ];
else
hdC = hdId;
if ( hdC == hdId )
return hdId;
else
{
if ( genL < genR )
return PowAgI( hdC, INT_TO_HD( -1 ) );
else
return hdC;
}
}
#   endif
return AgSolution2( hdR, hdL, hdL, hdR );
}
#if AG_PROFILE
long    TimeEqAg, TimeLtAg, TimeProdAg, TimeQuoAg;
long    TimeModAg, TimePowAgI, TimePowAgAg, TimeCommAg;
long    TimeSumAg, TimeDiffAg;
long    CallsEqAg, CallsLtAg, CallsProdAg, CallsQuoAg;
long    CallsModAg, CallsPowAgI, CallsPowAgAg, CallsCommAg;
long    CallsSumAg, CallsDiffAg;
long    RepTimes = 0;
TypHandle       TEqAg P(( TypHandle, TypHandle ));
TypHandle       TLtAg P(( TypHandle, TypHandle ));
TypHandle       TProdAg P(( TypHandle, TypHandle ));
TypHandle       TQuoAg P(( TypHandle, TypHandle ));
TypHandle       TModAg P(( TypHandle, TypHandle ));
TypHandle       TPowAgI P(( TypHandle, TypHandle ));
TypHandle       TPowAgAg P(( TypHandle, TypHandle ));
TypHandle       TCommAg P(( TypHandle, TypHandle ));
TypHandle       TEqAg( hdL, hdR )
TypHandle       hdL, hdR;
{
unsigned long   i, time;
TypHandle       hd = 0;
time = SyTime();
for ( i = 0; i < RepTimes; i++ )
hd = EqAg( hdL, hdR );
TimeEqAg += ( SyTime() - time );
CallsEqAg++;
return hd;
}
TypHandle       TLtAg( hdL, hdR )
TypHandle       hdL, hdR;
{
unsigned long   i, time;
TypHandle       hd = 0;
time = SyTime();
for ( i = 0; i < RepTimes; i++ )
hd = LtAg( hdL, hdR );
TimeLtAg += ( SyTime() - time );
CallsLtAg++;
return hd;
}
TypHandle       TProdAg( hdL, hdR )
TypHandle       hdL, hdR;
{
unsigned long   i, time;
TypHandle       hd = 0;
time = SyTime();
for ( i = 0; i < RepTimes; i++ )
hd = ProdAg( hdL, hdR );
TimeProdAg += ( SyTime() - time );
CallsProdAg++;
return hd;
}
TypHandle       TQuoAg( hdL, hdR )
TypHandle       hdL, hdR;
{
unsigned long   i, time;
TypHandle       hd = 0;
time = SyTime();
for ( i = 0; i < RepTimes; i++ )
hd = QuoAg( hdL, hdR );
TimeQuoAg += ( SyTime() - time );
CallsQuoAg++;
return hd;
}
TypHandle       TModAg( hdL, hdR )
TypHandle       hdL, hdR;
{
unsigned long   i, time;
TypHandle       hd = 0;
time = SyTime();
for ( i = 0; i < RepTimes; i++ )
hd = ModAg( hdL, hdR );
TimeModAg += ( SyTime() - time );
CallsModAg++;
return hd;
}
TypHandle       TPowAgI( hdL, hdR )
TypHandle       hdL, hdR;
{
unsigned long   i, time;
TypHandle       hd = 0;
time = SyTime();
for ( i = 0; i < RepTimes; i++ )
hd = PowAgI( hdL, hdR );
TimePowAgI += ( SyTime() - time );
CallsPowAgI++;
return hd;
}
TypHandle       TPowAgAg( hdL, hdR )
TypHandle       hdL, hdR;
{
unsigned long   i, time;
TypHandle       hd = 0;
time = SyTime();
for ( i = 0; i < RepTimes; i++ )
hd = PowAgAg( hdL, hdR );
TimePowAgAg += ( SyTime() - time );
CallsPowAgAg++;
return hd;
}
TypHandle       TCommAg( hdL, hdR )
TypHandle       hdL, hdR;
{
unsigned long   i, time;
TypHandle       hd = 0;
time = SyTime();
for ( i = 0; i < RepTimes; i++ )
hd = CommAg( hdL, hdR );
TimeCommAg += ( SyTime() - time );
CallsCommAg++;
return hd;
}
#endif
#if PRINT_AG | GROUP_REC
TypHandle       FunDUMPLONG( hdCall )
TypHandle       hdCall;
{
long            i, * ptr;
TypHandle       hdObj;
if ( SIZE( hdCall ) != 2 * SIZE_HD )
return Error( "usage: DUMP_LONG( <obj> )", 0L, 0L );
hdObj = EVAL( PTR( hdCall )[ 1 ] );
if ( hdObj == HdVoid )
return Error( "DUMP_LONG: function must return a value.", 0L, 0L );
ptr = (long*) PTR( hdObj );
for ( i = SIZE( hdObj ) - 1; i >= 0; i -= 4 )
Pr( "%d ", *ptr++, 0L );
Pr( "\n", 0L, 0L );
return HdVoid;
}
#endif
TypHandle           GapAgGroup ( hdGrp )
TypHandle           hdGrp;
{
TypHandle           hdRec, hdRn, hdList;
hdRec = NewBag( T_REC, 4 * SIZE_HD );
hdRn = FindRecname( "generators" );
PTR( hdRec )[ 0 ] = hdRn;
hdList = Copy( HD_GENERATORS( hdGrp ) );
PTR( hdRec )[ 1 ] = hdList;
hdRn = FindRecname( "identity" );
PTR( hdRec )[ 2 ] = hdRn;
PTR( hdRec )[ 3 ] = HD_IDENTITY( hdGrp );
return hdRec;
}
TypHandle       FunAgFpGroup ( hdCall )
TypHandle       hdCall;
{
TypHandle       hdRec,    hdGrp,    hdLst,    hdRn,  hdGns,  hdTmp;
TypHandle       * ptRec,  * ptEnd,  * ptLst,  * ptGns;
long            len,  i;
if ( SIZE( hdCall ) != 2 * SIZE_HD )
return Error( "usage: AgGroupFpGroup( <F> )", 0L, 0L );
hdRec = EVAL( PTR( hdCall )[ 1 ] );
if ( TYPE( hdRec ) != T_REC )
return Error( "usage: AgGroupFpGroup( <F> )", 0L, 0L );
hdGrp = BlankAgGroup();
hdRn  = FindRecname( "generators" );
ptRec = PTR( hdRec );
ptEnd = (TypHandle*) ( (char*) ptRec + SIZE( hdRec ) );
while ( ptRec < ptEnd && ptRec[ 0 ] != hdRn )
ptRec += 2;
if ( ptRec == ptEnd )
return Error( "AgGroupFpGroup: no '~.generators'.", 0L, 0L );
hdGns = ptRec[ 1 ];
if ( ! IsList( hdGns ) )
return Error( "AgGroupFpGroup: no list '~.generators'.", 0L, 0L );
len = HD_TO_INT( PTR( hdGns )[ 0 ] );
hdLst = NewBag( T_LIST, ( len + 1 ) * SIZE_HD );
PTR( hdLst )[ 0 ] = INT_TO_HD( len );
HD_WORDS( hdGrp ) = hdLst;
ptLst = PTR( hdLst );
ptGns = PTR( hdGns );
for ( i = len;  i > 0;  i-- )
{
hdTmp = ptGns[ i ];
if ( TYPE( hdTmp ) != T_WORD && TYPE( hdTmp ) != T_SWORD )
return Error( "%d. generator must be a word", i, 0L );
if ( TYPE( hdTmp ) == T_WORD )
{
if ( SIZE( hdTmp ) != SIZE_HD )
return Error( "%d. generator must have length 1", i, 0L );
ptLst[i] = PTR( hdTmp )[ 0 ];
}
else
{
if (    SIZE( hdTmp ) != SIZE_HD + 3 * SIZE_SWORD
|| PTR_AW( hdTmp )[ 1 ] != 1 )
{
return Error( "%d. generator must have length 1", i, 0L );
}
ptLst[i] = PTR( *PTR( hdTmp ) )[ PTR_AW( hdTmp )[0] + 1 ];
}
}
HD_NUMBER_OF_GENS( hdGrp ) = INT_TO_HD( len );
hdLst = NewBag( T_AGEXP, SIZE_EXP * len );
HD_SAVE_EXPONENTS( hdGrp ) = hdLst;
hdLst = NewBag( T_AGEXP, SIZE_EXP * len );
HD_COLLECT_EXPONENTS( hdGrp ) = hdLst;
ClearCollectExponents( hdGrp );
hdLst = NewBag( T_AGEXP, SIZE_EXP * len );
HD_COLLECT_EXPONENTS_2( hdGrp ) = hdLst;
SetGeneratorsAgGroup( hdGrp );
if ( len > 0 )
ReadRelators( hdRec, hdGrp );
return GapAgGroup( hdGrp );
}
TypHandle       FunSetCollectorAgWord ( hdCall )
TypHandle       hdCall;
{
TypHandle       hdWrd, hdStr;
long            i;
char            * usage = "usage: SetCollectorAgWord( <g>, <name> )";
if ( SIZE( hdCall ) < 3 * SIZE_HD )
return Error( usage, 0L, 0L );
hdWrd = EVAL( PTR( hdCall )[ 1 ] );
hdStr = EVAL( PTR( hdCall )[ 2 ] );
if ( TYPE( hdWrd ) != T_AGWORD || TYPE( hdStr ) != T_STRING )
return Error( usage, 0L, 0L );
for ( i = 0; i <= COMBI_COLLECTOR; i++ )
if ( ! SyStrcmp( Collectors[ i ].name, (char*) PTR( hdStr ) ) )
break;
if ( i > COMBI_COLLECTOR )
{
Pr( "#I  Known collectors: ", 0L, 0L );
for ( i = 0; i < COMBI2_COLLECTOR; i++ )
Pr( "%2>%s%<,%< ", (long) Collectors[ i ].name, 0L );
Pr( "%2>%s%<.%<\n", (long)Collectors[COMBI2_COLLECTOR].name, 0L );
return Error( "Collector \"%s\" unkown", (long) PTR( hdStr ), 0L );
}
Collectors[ i ].init( hdCall, i );
return HdVoid;
}
TypHandle       FunFactorAgWord ( hdCall )
TypHandle       hdCall;
{
TypHandle       hdL, hdR;
TypHandle       hdGrpL, hdGrpR, hdWrd;
TypSword        nrOld, nrNew;
TypSword        i;
if ( SIZE( hdCall ) != 3 * SIZE_HD  )
return Error( "usage: FactorAgWord( <g> , <to> )", 0L, 0L );
hdL = EVAL( PTR( hdCall )[ 1 ] );
hdR = EVAL( PTR( hdCall )[ 2 ] );
if ( TYPE( hdL ) != T_AGWORD  ||  TYPE( hdR ) != T_AGWORD )
return Error( "usage: FactorAgWord( <g> , <to> )", 0L, 0L );
hdGrpL = *PTR( hdL );
hdGrpR = *PTR( hdR );
nrOld = NUMBER_OF_GENS( hdGrpL );
nrNew = NUMBER_OF_GENS( hdGrpR );
for ( i = MIN( nrOld, nrNew ) - 1; i >= 0; i-- )
if ( INDICES( hdGrpL )[ i ] != INDICES( hdGrpR )[ i ] )
return Error(
"FactorAgWord: groups have different indices (%d != %d)",
(long) INDICES( hdGrpL )[ i ],
(long) INDICES( hdGrpR )[ i ] );
hdWrd = HeadAgWord( hdL, nrNew );
*PTR( hdWrd ) = hdGrpR;
return hdWrd;
}
TypHandle       FactorAgGroup ( hdGrp, new )
TypHandle       hdGrp;
long            new;
{
TypHandle       hdFac,  hdLst,  hdTmp,  hdOld,  hdNew;
long            i,  j,  old;
old = NUMBER_OF_GENS( hdGrp );
new = MIN( new, old );
hdFac = BlankAgGroup();
HD_COLLECTOR( hdFac )      = HD_COLLECTOR( hdGrp );
HD_NUMBER_OF_GENS( hdFac ) = INT_TO_HD( new );
SetGeneratorsAgGroup( hdFac );
hdTmp = NewBag( T_AGEXP, SIZE_EXP * new );
HD_SAVE_EXPONENTS( hdFac ) = hdTmp;
hdTmp = NewBag( T_AGEXP, SIZE_EXP * new );
HD_COLLECT_EXPONENTS( hdFac ) = hdTmp;
ClearCollectExponents( hdFac );
hdTmp = NewBag( T_AGEXP, SIZE_EXP * new );
HD_COLLECT_EXPONENTS_2( hdFac ) = hdTmp;
hdLst = NewBag( T_LIST, ( new + 1 ) * SIZE_HD );
*PTR( hdLst ) = INT_TO_HD( new );
HD_WORDS( hdFac ) = hdLst;
hdTmp = NewBag( T_INTPOS, new * sizeof( long ) );
HD_INDICES( hdFac ) = hdTmp;
for ( i = new - 1;  i >= 0;  i-- )
{
WORDS(   hdFac )[ i ] = WORDS(   hdGrp )[ i ];
INDICES( hdFac )[ i ] = INDICES( hdGrp )[ i ];
}
hdLst = NewBag( T_LIST, ( new + 1 ) * SIZE_HD );
*PTR( hdLst ) = INT_TO_HD( new );
HD_POWERS( hdFac ) = hdLst;
for ( i = new - 1;  i >= 0;  i-- )
{
hdTmp = HeadAgWord( POWERS( hdGrp )[ i ], new );
*PTR( hdTmp ) = hdFac;
PTR( hdLst )[i+1] = ISID_AW( hdTmp ) ? HD_IDENTITY( hdFac ) : hdTmp;
}
hdLst = NewBag( T_LIST, ( new * ( new - 1 ) / 2 + 1 ) * SIZE_HD );
*PTR( hdLst ) = INT_TO_HD( new * ( new - 1 ) / 2 );
HD_COMMUTATORS( hdFac ) = hdLst;
for ( i = new * ( new - 1 ) / 2 - 1;  i >= 0;  i-- )
{
hdTmp = HeadAgWord( COMMUTATORS( hdGrp )[ i ], new );
*PTR( hdTmp ) = hdFac;
PTR( hdLst )[i+1] = ISID_AW( hdTmp ) ? HD_IDENTITY( hdFac ) : hdTmp;
}
SaveAndClearCollector( hdFac );
switch( (int) COLLECTOR( hdFac ) )
{
case SINGLE_COLLECTOR:
SetAvecAgGroup( hdFac, 0, NUMBER_OF_GENS(hdFac)-1 );
hdLst = NewBag( T_LIST, ( new * (new-1)/2 + 1 ) * SIZE_HD );
*PTR( hdLst ) = INT_TO_HD( new * ( new - 1 ) / 2 );
for ( i = new * ( new - 1 ) / 2 - 1;  i >= 0;  i-- )
{
hdTmp = HeadAgWord( CONJUGATES( hdGrp )[ i ], new );
*PTR( hdTmp ) = hdFac;
if ( ISID_AW( hdTmp ) )
PTR( hdLst )[ i + 1 ] = HD_IDENTITY( hdFac );
else
PTR( hdLst )[ i + 1 ] = hdTmp;
}
HD_CONJUGATES( hdFac ) = hdLst;
hdTmp = FindRecname( "conjugates" );
PTR( hdFac )[ NR_CONJUGATES - 1 ] = hdTmp;
break;
case TRIPLE_COLLECTOR:
case QUADR_COLLECTOR:
SetAvecAgGroup( hdFac, 0, NUMBER_OF_GENS(hdFac)-1 );
hdLst = NewBag( T_LIST, ( new * (new-1)/2 + 1 ) * SIZE_HD );
*PTR( hdLst ) = INT_TO_HD( new * ( new - 1 ) / 2 );
HD_TRIPLES( hdFac ) = hdLst;
for ( i = new * ( new - 1 ) / 2 - 1;  i >= 0;  i-- )
{
hdTmp = TRIPLES( hdGrp )[ i ];
if ( hdTmp != 0 )
{
hdNew = NewBag( T_LIST, SIZE( hdTmp ) );
*PTR( hdNew ) = *PTR( hdTmp );
for ( j = 1; j < SIZE( hdTmp ) / SIZE_HD; j++ )
{
hdOld = HeadAgWord( PTR( hdTmp )[ j ], new );
*PTR( hdOld ) = hdFac;
PTR( hdNew )[ j ] = hdOld;
}
}
else
hdNew = 0;
TRIPLES( hdFac )[ i ] = hdNew;
}
HD_TUPLE_BOUND( hdFac ) = HD_TUPLE_BOUND( hdGrp );
hdTmp = FindRecname( "tupleBound" );
PTR( hdFac )[ NR_TUPLE_BOUND - 1 ] = hdTmp;
PTR(hdFac)[NR_TRIPLES-1] = PTR(hdGrp)[NR_TRIPLES-1];
break;
case LEE_COLLECTOR:
case COMBI_COLLECTOR:
case COMBI2_COLLECTOR:
SetCWeightsAgGroup( hdFac, HdVoid );
break;
}
SetStacksAgGroup( hdFac );
return GapAgGroup( hdFac );
}
TypHandle   FunFactorAgGroup ( hdCall )
TypHandle       hdCall;
{
TypHandle       hdWrd, hdGrp, hdInt;
long            new;
char            * usage = "usage: FactorAgGroup( <g>, <n> )";
if ( SIZE( hdCall ) != 3 * SIZE_HD  )
return Error( usage, 0L, 0L );
hdWrd = EVAL( PTR( hdCall )[ 1 ] );
hdInt = EVAL( PTR( hdCall )[ 2 ] );
if ( TYPE( hdInt ) != T_INT || TYPE( hdWrd ) != T_AGWORD )
return Error( usage, 0L, 0L );
hdGrp = *PTR( hdWrd );
new   = HD_TO_INT( hdInt );
if ( new < 0 )
return Error( "FactorAgGroup: negative composition length", 0L, 0L );
return FactorAgGroup( hdGrp, new );
}
#if GROUP_REC
TypHandle       FunAgGroupRecord ( hdCall )
TypHandle       hdCall;
{
TypHandle       hdWrd;
if ( SIZE( hdCall ) != 2 * SIZE_HD )
return Error( "usage: AgGroupRecord( <g> )", 0L, 0L );
hdWrd = EVAL( PTR( hdCall )[ 1 ] );
if ( TYPE( hdWrd ) != T_AGWORD )
return Error( "usage: AgGroupRecord( <g> )", 0L, 0L );
return *PTR( hdWrd );
}
#endif
TypHandle       HdRnSumAgWord,  HdCallSumAgWord;
TypHandle       SumAgWord ( hdP, hdV, hdW )
TypHandle       hdP;
TypHandle       hdV;
TypHandle       hdW;
{
TypHandle       hdSum = 0;
TypSword        * ptSum,  * ptV,  * ptW;
long            * ptIdx,  len,  nr,  exp;
#   if AG_PROFILE
unsigned long   i, time = 0;
#   endif
#   if AG_PROFILE
if ( RepTimes > 0 )
CallsSumAg++;
#   endif
if ( ISID_AW( hdV ) )
return hdW;
if ( ISID_AW( hdW ) )
return hdV;
#   if AG_PROFILE
if ( RepTimes > 0 )
time = SyTime();
i = 0;
do
{
#   endif
len = 0;
ptIdx = INDICES( hdP );
ptV = PTR_AW( hdV );
ptW = PTR_AW( hdW );
while ( * ptV != -1 && * ptW != -1 )
{
if ( * ptV < * ptW )
{
len++;
ptV += 2;
}
else if ( * ptV > * ptW )
{
len++;
ptW += 2;
}
else
{
nr = * ptV;
if ( ( * ++ptV + * ++ptW ) % ptIdx[ nr ] != 0 )
len++;
ptV++;
ptW++;
}
}
while ( * ptV != -1 )
{
len++;
ptV += 2;
}
while ( * ptW != -1 )
{
len++;
ptW += 2;
}
#   if AG_PROFILE
if ( i == 0 )
#   endif
hdSum = NewBag( T_AGWORD, SIZE_HD + ( 2 * len + 1 ) * SIZE_SWORD );
* PTR( hdSum ) = hdP;
ptSum = PTR_AW( hdSum );
ptV   = PTR_AW( hdV );
ptW   = PTR_AW( hdW );
ptIdx = INDICES( hdP );
while ( * ptV != -1 && * ptW != -1 )
{
if ( * ptV < * ptW )
{
* ptSum++ = * ptV++;
* ptSum++ = * ptV++;
}
else if ( * ptV > * ptW )
{
* ptSum++ = * ptW++;
* ptSum++ = * ptW++;
}
else
{
nr  = * ptV;
exp = ( * ++ptV + * ++ptW ) % ptIdx[ nr ];
if ( exp != 0 )
{
* ptSum++ = nr;
* ptSum++ = exp;
}
ptV++;
ptW++;
}
}
while ( * ptV != -1 )
{
* ptSum++ = * ptV++;
* ptSum++ = * ptV++;
}
while ( * ptW != -1 )
{
* ptSum++ = * ptW++;
* ptSum++ = * ptW++;
}
* ptSum = -1;
#   if AG_PROFILE
i++;
} while ( i < RepTimes );
if ( RepTimes > 0 )
TimeSumAg += ( SyTime() - time );
#   endif
return hdSum;
}
TypHandle       FunSumAgWord ( hdCall )
TypHandle       hdCall;
{
TypHandle       hdV,  hdW;
char            * usage = "usage: SumAgWord( <v>, <w> )";
if ( SIZE( hdCall ) != 3 * SIZE_HD )
return Error( usage, 0L, 0L );
hdV = EVAL( PTR( hdCall )[ 1 ] );
hdW = EVAL( PTR( hdCall )[ 2 ] );
if ( TYPE( hdV ) != T_AGWORD || TYPE( hdW ) != T_AGWORD )
return EvalOop2( hdV, hdW, HdRnSumAgWord, usage );
if ( * PTR( hdV ) != * PTR( hdW ) )
return Error("<v> and <w> must have a common parent group", 0L, 0L);
return SumAgWord( *PTR( hdV ), hdV, hdW );
}
TypHandle       HdRnDifferenceAgWord;
TypHandle       DifferenceAgWord ( hdP, hdV, hdW )
TypHandle       hdP;
TypHandle       hdV;
TypHandle       hdW;
{
TypHandle       hdDiff = 0;
TypSword        * ptDiff, * ptV, * ptW;
long            * ptIdx, len, nr, exp;
#   if AG_PROFILE
unsigned long   i, time = 0;
#   endif
#   if AG_PROFILE
CallsDiffAg++;
#   endif
if ( ISID_AW( hdW ) )
return hdV;
#   if AG_PROFILE
if ( RepTimes > 0 )
time = SyTime();
i = 0;
do
{
#   endif
len = 0;
ptIdx = INDICES( hdP );
ptV = PTR_AW( hdV );
ptW = PTR_AW( hdW );
while ( * ptV != -1 && * ptW != -1 )
{
if ( * ptV < * ptW )
{
len++;
ptV += 2;
}
else if ( * ptV > * ptW )
{
len++;
ptW += 2;
}
else
{
nr = * ptV;
if ( ( * ++ptV - *++ptW ) % ptIdx[ nr ] != 0 )
len++;
ptV++;
ptW++;
}
}
while ( * ptV != -1 )
{
len++;
ptV += 2;
}
while ( * ptW != -1 )
{
len++;
ptW += 2;
}
#   if AG_PROFILE
if ( i == 0 )
#   endif
hdDiff = NewBag( T_AGWORD, SIZE_HD + ( 2 * len + 1 ) * SIZE_SWORD );
* PTR( hdDiff ) = hdP;
ptDiff = PTR_AW( hdDiff );
ptV    = PTR_AW( hdV );
ptW    = PTR_AW( hdW );
ptIdx  = INDICES( hdP );
while ( * ptV != -1 && * ptW != -1 )
{
if ( * ptV < * ptW )
{
* ptDiff++ = * ptV++;
* ptDiff++ = * ptV++;
}
else if ( * ptV > * ptW )
{
nr = * ptW;
* ptDiff++ = * ptW++;
* ptDiff++ = ptIdx[ nr ] - * ptW++;
}
else
{
nr  = * ptV;
exp = ( * ++ptV - *++ptW ) % ptIdx[ nr ];
if ( exp < 0 )
exp += ptIdx[ nr ];
if ( exp != 0 )
{
* ptDiff++ = nr;
* ptDiff++ = exp;
}
ptV++;
ptW++;
}
}
while ( * ptV != -1 )
{
* ptDiff++ = * ptV++;
* ptDiff++ = * ptV++;
}
while ( * ptW != -1 )
{
nr = * ptW;
* ptDiff++ = * ptW++;
* ptDiff++ = ptIdx[ nr ] - * ptW++;
}
* ptDiff = -1;
#   if AG_PROFILE
i++;
} while ( i < RepTimes );
if ( RepTimes > 0 )
TimeDiffAg += ( SyTime() - time );
#   endif
return hdDiff;
}
TypHandle       FunDifferenceAgWord ( hdCall )
TypHandle       hdCall;
{
TypHandle       hdV,  hdW;
char            * usage = "usage: DifferenceAgWord( <v>, <w> )";
if ( SIZE( hdCall ) != 3 * SIZE_HD )
return Error( usage, 0L, 0L );
hdV = EVAL( PTR( hdCall )[ 1 ] );
hdW = EVAL( PTR( hdCall )[ 2 ] );
if ( TYPE( hdV ) != T_AGWORD || TYPE( hdW ) != T_AGWORD )
return EvalOop2( hdV, hdW, HdRnDifferenceAgWord, usage );
if ( * PTR( hdV ) != * PTR( hdW ) )
return Error("<v> and <w> must have a common parent group", 0L, 0L);
return DifferenceAgWord( *PTR( hdV ), hdV, hdW );
}
TypHandle       HdRnDepth;
TypHandle       FunDepthAgWord ( hdCall )
TypHandle       hdCall;
{
TypHandle       hdWrd;
char            * usage = "usage: DepthAgWord( <g> )";
if ( SIZE( hdCall ) != 2 * SIZE_HD )
return Error( usage, 0L, 0L );
hdWrd = EVAL( PTR( hdCall )[ 1 ] );
if ( TYPE( hdWrd ) == T_AGWORD )
{
	if ( *PTR_AW(hdWrd) == -1 )
	    return INT_TO_HD(NUMBER_OF_GENS(*PTR(hdWrd))+1);
	else
	    return INT_TO_HD( *(PTR_AW(hdWrd))+1 );
}
return EvalOop( hdWrd, HdRnDepth, usage );
}
TypHandle       HdRnTailDepth;
TypHandle       FunTailDepthAgWord ( hdCall )
TypHandle       hdCall;
{
TypHandle       hdWrd;
TypSword        * ptWrd;
long            sze;
char            * usage = "usage: TailDepthAgWord( <g> )";
if ( SIZE( hdCall ) != 2 * SIZE_HD )
return Error( usage, 0L, 0L );
hdWrd = EVAL( PTR( hdCall )[ 1 ] );
if ( TYPE( hdWrd ) == T_AGWORD )
{
sze = SIZE( hdWrd );
if ( sze == SIZE_HD + SIZE_SWORD )
return INT_TO_HD( 0 );
else
{
ptWrd = (TypSword*)( (char*) PTR( hdWrd ) + sze );
return INT_TO_HD( ( ptWrd[ -3 ] + 1 ) );
}
}
return EvalOop( hdWrd, HdRnTailDepth, usage );
}
TypHandle       HdRnCentralWeight;
TypHandle       FunCentralWeightAgWord( hdCall )
TypHandle       hdCall;
{
TypHandle       hdWrd, hdGrp;
if ( SIZE( hdCall ) != 2 * SIZE_HD  )
return( Error( "usage: CentralWeightAgWord( <g> )", 0L, 0L ) );
hdWrd = EVAL( PTR( hdCall )[ 1 ] );
if ( TYPE( hdWrd ) == T_AGWORD )
{
hdGrp = *PTR( hdWrd );
if (    COLLECTOR( hdGrp ) != COMBI_COLLECTOR
&& COLLECTOR( hdGrp ) != COMBI2_COLLECTOR
&& COLLECTOR( hdGrp ) != LEE_COLLECTOR )
{
return Error( "CentralWeightAgWord: needs a p-central-series",
0L, 0L );
}
if ( ISID_AW( hdWrd ) )
return INT_TO_HD( 0 );
else
return INT_TO_HD( CWEIGHTS( hdGrp )[ *PTR_AW( hdWrd ) ] );
}
return EvalOop( hdWrd,
HdRnCentralWeight,
"usage: CentralWeightAgWord( <g> )" );
}
TypHandle       HdRnLeadingExponent;
TypHandle       FunLeadingExponentAgWord( hdCall )
TypHandle       hdCall;
{
TypHandle       hdWrd;
if ( SIZE( hdCall ) != 2 * SIZE_HD )
return Error( "usage: LeadingExponentAgWord( <g> )", 0L, 0L );
hdWrd = EVAL( PTR( hdCall )[ 1 ] );
if ( TYPE( hdWrd ) == T_AGWORD )
{
if ( ! ISID_AW( hdWrd ) )
return INT_TO_HD( *( PTR_AW( hdWrd ) + 1 ) );
else
return INT_TO_HD( 0 );
}
return EvalOop( hdWrd, HdRnLeadingExponent,
"usage: LeadingExponent( <g> )" );
}
TypHandle       HdRnReducedAgWord;
TypHandle       FunReducedAgWord ( hdCall )
TypHandle       hdCall;
{
TypHandle       hdL, hdR;
TypHandle       hdGrp;
unsigned long   a, b, bb, i, q, order;
#   if AG_PROFILE
TypHandle       hdTmp;
#   endif
if ( SIZE( hdCall ) != 3 * SIZE_HD )
return Error( "usage: ReducedAgWord( <l>, <r> )", 0L, 0L );
hdL = EVAL( PTR( hdCall )[1] );
hdR = EVAL( PTR( hdCall )[2] );
if ( TYPE( hdL ) == T_AGWORD && TYPE( hdR ) == T_AGWORD )
{
hdGrp = *PTR( hdL );
if ( hdGrp != *PTR( hdR ) )
return Error( "ReducedAgWord: agwords are of different groups",
0L, 0L );
if ( ISID_AW( hdL ) || ISID_AW( hdR ) )
return Error( "ReducedAgWord: cannot reduce identity",
0L, 0L );
if ( *PTR_AW( hdL ) != *PTR_AW( hdR ) )
return Error( "ReducedAgWord: agwords have different depths",
0L, 0L );
a     = (unsigned long) *( PTR_AW( hdL ) + 1 );
b     = (unsigned long) *( PTR_AW( hdR ) + 1 );
order = INDICES( hdGrp )[ *PTR_AW( hdL ) ];
if ( b == 1 || order == 3 )
i = ( a * b ) % order;
else if ( b < a && a % b == 0 )
i = a / b;
else
{
i = a;
q = order - 2;
bb = b;
while ( q )
{
if ( q & 1 )
i = ( i * bb ) % order;
bb = ( bb * bb ) % order;
q = q / 2;
}
}
if ( ( b * i ) % order != a % order )
return Error( "ReducedAgWord: cannot reduce agword",0L,0L );
#       if AG_PROFILE
hdTmp = POW( hdR, INT_TO_HD( -(long) i ) );
return PROD( hdTmp, hdL );
#       else
return ProdAg( PowAgI( hdR, INT_TO_HD( -(long) i ) ),
hdL );
#       endif
}
return EvalOop2( hdL,
hdR,
HdRnReducedAgWord,
"usage: ReducedAgWord( <l>, <r> )" );
}
TypHandle       HdRnNormalizeIgs;
TypHandle       FunNormalizeIgs ( hdCall )
TypHandle       hdCall;
{
TypHandle       hdIgs, hdTmp, hdOne, hdPos, hdWrd, hdGrp, hdOrd, hdIdx;
TypHandle       hdExp;
TypExp          * ptPos, * ptEnd;
TypSword        * ptWrd;
long            i,  j,  d,  p;
char            *usage = "usage: NormalizeIgs( <igs> )";
if ( SIZE( hdCall ) != 2 * SIZE_HD )
return Error( usage, 0L, 0L );
hdIgs = EVAL( PTR( hdCall )[ 1 ] );
if ( ! IsList( hdIgs ) )
return Error( usage, 0L, 0L );
if ( LEN_LIST( hdIgs ) == 0 )
return HdVoid;
hdTmp = ELM_PLIST( hdIgs, 1 );
if ( TYPE( hdTmp ) != T_AGWORD )
return EvalOopN( hdTmp, HdRnNormalizeIgs, hdCall, usage );
hdGrp = PTR( hdTmp )[ 0 ];
if ( LEN_LIST( hdIgs ) > NUMBER_OF_GENS( hdGrp ) )
return Error( usage, 0L, 0L );
hdIdx = HD_INDICES( hdGrp );
hdOne = INT_TO_HD( 1 );
hdPos = HD_COLLECT_EXPONENTS_2( hdGrp );
ptPos = (TypExp*) PTR( hdPos );
ptEnd = (TypExp*)( (char*) ptPos + SIZE( hdPos ) );
while ( ptPos < ptEnd )
*ptPos++ = 0;
for ( i = LEN_LIST( hdIgs );  0 < i;  i-- )
{
hdWrd = ELM_PLIST( hdIgs, i );
if ( TYPE( hdWrd ) != T_AGWORD )
return Error( "%d.th element must be an ag word", i, 0L );
ptWrd = PTR_AW( hdWrd );
d = ptWrd[0];
if ( d == -1 )
return Error( "%d.th element is the identity", i, 0L );
( (TypExp*)PTR( hdPos ) )[ d ] = i;
hdExp = INT_TO_HD( ptWrd[1] );
hdOrd = INT_TO_HD( ( (long*) PTR( hdIdx ) )[ d ] );
hdExp = QUO( hdOne, hdExp );
hdExp = MOD( hdExp, hdOrd );
#       if AG_PROFILE
hdWrd = POW( hdWrd, hdExp );
#       else
hdWrd = PowAgI( hdWrd, hdExp );
#       endif
SET_ELM_PLIST( hdIgs, i, hdWrd );
}
for ( i = LEN_LIST( hdIgs ) - 1;  0 < i;  i-- )
{
hdWrd = ELM_PLIST( hdIgs, i );
j = 2;
while ( 1 )
{
ptWrd = PTR_AW( hdWrd );
d = ptWrd[j];
if ( d == -1 )
break;
p = ( (TypExp*) PTR( hdPos ) )[ d ];
if ( p != 0 )
{
hdExp = INT_TO_HD( ((long*)PTR(hdIdx))[d] - ptWrd[j+1] );
#               ifdef AG_PROFILE
hdTmp = ELM_PLIST( hdIgs, p );
hdTmp = POW( hdTmp, hdExp );
hdWrd = PROD( hdWrd, hdTmp );
#               else
hdTmp = PowAgI( ELM_PLIST( hdIgs, p ), hdExp );
hdWrd = ProdAg( hdWrd, hdTmp );
#               endif
j = 0;
}
j += 2;
}
SET_ELM_PLIST( hdIgs, i, hdWrd );
}
return HdVoid;
}
TypHandle       HdRnRelativeOrder;
TypHandle       FunRelativeOrderAgWord ( hdCall )
TypHandle       hdCall;
{
TypHandle       hdWrd;
if ( SIZE( hdCall ) != 2 * SIZE_HD  )
return Error( "usage: RelativeOrderAgWord( <g> )", 0L, 0L );
hdWrd = EVAL( PTR( hdCall )[1] );
if ( TYPE( hdWrd ) == T_AGWORD )
{
if ( ISID_AW( hdWrd ) )
return INT_TO_HD( 1 );
else
return INT_TO_HD( INDICES( *PTR( hdWrd ) )[ *PTR_AW( hdWrd ) ] );
}
return EvalOop(hdWrd, HdRnRelativeOrder, "usage: RelativeOrder( <g> )");
}
TypHandle       HdRnExponentAgWord;
TypHandle       FunExponentAgWord( hdCall )
TypHandle       hdCall;
{
TypHandle       hdWrd, hdI;
TypSword        * pt, * ptEnd;
long            i;
if ( SIZE( hdCall ) != 3 * SIZE_HD  )
return Error( "usage: ExponentAgWord( <g> , <i> )",0L,0L );
hdWrd = EVAL( PTR( hdCall )[1] );
hdI   = EVAL( PTR( hdCall )[2] );
if ( TYPE( hdWrd ) == T_AGWORD  &&  TYPE( hdI ) == T_INT )
{
i = HD_TO_INT( hdI ) - 1;
if ( i < 0 )
return Error("ExponentAgWord: bad generator number %d", i+1, 0L);
if ( i >= NUMBER_OF_GENS( *PTR( hdWrd ) ) )
return Error("ExponentAgWord: bad generator number %d", i+1, 0L);
pt    = PTR_AW( hdWrd );
ptEnd = pt + 2 * LEN_AW( hdWrd );
while ( pt < ptEnd )
{
if ( *pt == i )
return INT_TO_HD( (long) *( pt + 1 ) );
else if ( *pt > i )
return INT_TO_HD( 0 );
pt += 2;
}
return INT_TO_HD( 0 );
}
return EvalOop2( hdWrd, hdI,
HdRnExponentAgWord,
"usage: ExponentAgWord( <g> , <i> )" );
}
TypHandle       HdRnExponentsAgWord;
TypHandle       IntExponentsAgWord ( hdWrd, s, e )
TypHandle       hdWrd;
long            s;
long            e;
{
TypHandle       hdLst;
TypHandle       * ptLst;
TypSword        * ptWrd, * ptEnd;
long            i;
hdLst = NewBag( T_VECTOR, ( e - s + 2 ) * SIZE_HD );
*PTR( hdLst ) = INT_TO_HD( e - s + 1 );
ptLst = PTR( hdLst ) + 1;
for ( i = e - s; i >= 0; i-- )
ptLst[ i ] = INT_TO_HD( 0 );
ptWrd = PTR_AW( hdWrd );
ptEnd = ptWrd + 2 * LEN_AW( hdWrd );
s--;
e--;
while ( ptWrd < ptEnd && ptWrd[ 0 ] < s )
ptWrd += 2;
while ( ptWrd < ptEnd && ptWrd[ 0 ] <= e )
{
ptLst[ ptWrd[ 0 ] - s ] = INT_TO_HD( ptWrd[ 1 ] );
ptWrd += 2;
}
return hdLst;
}
TypHandle       FFExponentsAgWord ( hdWrd, s, e, hdZ )
TypHandle       hdWrd;
long            s;
long            e;
TypHandle       hdZ;
{
TypHandle       hdLst;
TypSword        * ptWrd,  * ptEnd;
TypFFE          * ptVec,  * ff,  l,  r;
long            i,  ordFF;
hdLst = NewBag( T_VECFFE, SIZE_HD + sizeof( TypFFE ) *( e - s + 1 ) );
*PTR( hdLst ) = *PTR( hdZ );
ff    = (TypFFE*) PTR( FLD_FFE( hdZ ) );
ordFF = SIZE_FF( FLD_FFE( hdZ ) );
ptVec = (TypFFE*)( PTR( hdLst ) + 1 );
for ( i = e - s;  i >= 0;  i-- )
ptVec[ i ] = 0;
ptWrd = PTR_AW( hdWrd );
ptEnd = ptWrd + 2 * LEN_AW( hdWrd );
s--;
e--;
while ( ptWrd < ptEnd && ptWrd[ 0 ] < s )
ptWrd += 2;
while ( ptWrd < ptEnd && ptWrd[ 0 ] <= e )
{
r = ( ptWrd[ 1 ] % ordFF + ordFF ) % ordFF;
if ( r == 0 )
l = 0;
else
for ( l = 1; 1 < r; r-- )
l = ( l == 0 ? 1 : ff[ l ] );
ptVec[ ptWrd[ 0 ] - s ] = l;
ptWrd += 2;
}
return hdLst;
}
TypHandle       FunExponentsAgWord ( hdCall )
TypHandle       hdCall;
{
TypHandle       hdWrd,  hdGrp,  hdS,  hdE,  hdZ;
long            s,  e;
char            * usage = "usage: ExponentsAgWord( <g>, <s>, <e>, <z> )";
if (    SIZE( hdCall ) <  2 * SIZE_HD
|| SIZE( hdCall ) >  5 * SIZE_HD
|| SIZE( hdCall ) == 3 * SIZE_HD )
{
return Error( usage, 0L, 0L );
}
hdWrd = EVAL( PTR( hdCall )[ 1 ] );
if ( TYPE( hdWrd ) == T_REC )
return EvalOopN( hdWrd, HdRnExponentsAgWord, hdCall, usage );
if ( TYPE( hdWrd ) != T_AGWORD )
return Error( usage, 0L, 0L );
hdGrp = * PTR( hdWrd );
if ( SIZE( hdCall ) == 2 * SIZE_HD )
{
s = 1;
e = NUMBER_OF_GENS( hdGrp );
}
else
{
hdS = EVAL( PTR( hdCall )[ 2 ] );
hdE = EVAL( PTR( hdCall )[ 3 ] );
if ( TYPE( hdS ) != T_INT || TYPE( hdE ) != T_INT )
return Error( usage, 0L, 0L );
s = HD_TO_INT( hdS );
e = HD_TO_INT( hdE );
if ( 1 > s || s > e )
{
return Error( "ExponentsAgWord: needs 0 less <s> not greater <e>",
0L, 0L );
}
if ( e > NUMBER_OF_GENS( hdGrp ) )
{
return Error( "ExponentsAgWord: <e> must not greater than %d",
(long) NUMBER_OF_GENS( hdGrp ), 0L );
}
}
if ( SIZE( hdCall ) != 5 * SIZE_HD )
{
return IntExponentsAgWord( hdWrd, s, e );
}
else
{
hdZ = EVAL( PTR( hdCall )[ 4 ] );
if ( TYPE( hdZ ) != T_FFE )
return Error( usage, 0L, 0L );
return FFExponentsAgWord( hdWrd, s, e, hdZ );
}
}
TypHandle       HdRnInformationAgWord;
TypHandle       FunInformationAgWord( hdCall )
TypHandle       hdCall;
{
TypHandle       hdGrp, hdWrd;
TypHandle       hdRec, hdTmp;
TypHandle       hd;
long            i, len;
char            * str;
if ( SIZE( hdCall ) != 2 * SIZE_HD  )
return Error( "usage: InformationAgWord( <g> )", 0L, 0L );
hdWrd = EVAL( PTR( hdCall )[ 1 ] );
if ( TYPE( hdWrd ) == T_AGWORD  )
{
hdGrp = *PTR( hdWrd );
hdRec = NewBag( T_REC, 8 * SIZE_HD );
len   = NUMBER_OF_GENS( hdGrp );
PTR( hdRec )[ 0 ] = FindRecname( "generators" );
hdTmp = Copy( HD_GENERATORS( hdGrp ) );
PTR( hdRec )[ 1 ] = hdTmp;
PTR( hdRec )[ 2 ] = FindRecname( "indices" );
hdTmp = NewBag( T_LIST, ( len + 1 ) * SIZE_HD );
*PTR( hdTmp ) = INT_TO_HD( len );
for ( i = len - 1; i >= 0; i-- )
PTR( hdTmp )[ i + 1 ] = INT_TO_HD( INDICES( hdGrp )[ i ] );
PTR( hdRec )[ 3 ] = hdTmp;
PTR( hdRec )[ 4 ] = FindRecname( "names" );
hdTmp = NewBag( T_LIST, ( len + 1 ) * SIZE_HD );
*PTR( hdTmp ) = INT_TO_HD( len );
for ( i = len -1; i >= 0; i-- )
{
str = NAME_AW( hdGrp, i );
hd = NewBag( T_STRING, SyStrlen( str ) + 1 );
*( (char*) PTR( hd ) ) = '\0';
SyStrncat( (char*) PTR( hd ), str, SyStrlen( str ) );
PTR( hdTmp )[ i + 1 ] = hd;
}
PTR( hdRec )[ 5 ] = hdTmp;
hdTmp = FindRecname( "collector" );
PTR( hdRec )[ 6 ] = hdTmp;
if ( COLLECTOR( hdGrp ) > COMBI_COLLECTOR )
return Error( "Corrupted group bag, collector = %d",
(long) COLLECTOR( hdGrp ), 0L );
str = Collectors[ COLLECTOR( hdGrp ) ].name;
hd = NewBag( T_STRING, SyStrlen( str ) + 1 );
*( (char*) PTR( hd ) ) = '\0';
SyStrncat( (char*) PTR( hd ), str, SyStrlen( str ) );
PTR( hdRec )[ 7 ] = hd;
if ( *PTR( hdWrd ) )
switch ( (int) COLLECTOR( hdGrp ) )
{
case TRIPLE_COLLECTOR:
case QUADR_COLLECTOR:
Resize( hdRec, 10 * SIZE_HD );
PTR( hdRec )[ 8 ] = FindRecname( "tupleBound" );
PTR( hdRec )[ 9 ] = INT_TO_HD(TUPLE_BOUND(hdGrp));
break;
}
return hdRec;
}
return EvalOop( hdWrd,
HdRnInformationAgWord,
"usage: InformationAgWord( <g> )" );
}
TypHandle       HdRnIsAgWord;
TypHandle       FunIsAgWord( hdCall )
TypHandle           hdCall;
{
TypHandle           hdObj, hdTmp;
TypHandle           * ptRec, * ptEnd;
TypHandle           hdOp;


if ( SIZE( hdCall ) != 2 * SIZE_HD )
return Error( "usage: IsAgWord( <obj> )", 0L, 0L );
hdObj = EVAL( PTR( hdCall )[ 1 ] );
if ( hdObj == HdVoid )
return Error( "IsAgWord: function must return a value", 0L, 0L );
if ( TYPE( hdObj ) == T_AGWORD )
return HdTrue;
if ( TYPE( hdObj ) != T_REC )
return HdFalse;
ptRec = PTR( hdObj );
ptEnd = (TypHandle*) ( (char*) ptRec + SIZE( hdObj ) );
while ( ptRec < ptEnd && ptRec[ 0 ] != HdRnOp )
ptRec += 2;
if ( ptRec == ptEnd || TYPE( ptRec[ 1 ] ) != T_REC )  goto l1;
hdOp  = ptRec[ 1 ];
ptRec = PTR( hdOp );
ptEnd = (TypHandle*) ( (char*) ptRec + SIZE( hdOp ) );
while ( ptRec < ptEnd && ptRec[ 0 ] != HdRnIsAgWord )
ptRec += 2;
if ( ptRec == ptEnd )
goto l1;
PTR( HdCallOop1 )[ 0 ] = ptRec[ 1 ];
PTR( HdCallOop1 )[ 1 ] = hdObj;
hdTmp = EVAL( HdCallOop1 );
PTR( HdCallOop1 )[ 0 ] = 0;
PTR( HdCallOop1 )[ 1 ] = 0;
return hdTmp;
l1:
return HdFalse;
}
TypHandle       HdRnIsCompatibleAgWord;
TypHandle       FunIsCompatibleAgWord ( hdCall )
TypHandle       hdCall;
{
TypHandle       hdA, hdB;
if ( SIZE( hdCall ) != 3 * SIZE_HD  )
return Error( "usage: IsCompatibleAgWord( <g> , <h> )", 0L, 0L );
hdA = EVAL( PTR( hdCall )[ 1 ] );
hdB = EVAL( PTR( hdCall )[ 2 ] );
if ( TYPE( hdA ) == T_AGWORD )
{
if ( TYPE( hdB ) == T_AGWORD )
return ( *PTR( hdA ) == *PTR( hdB ) ) ? HdTrue : HdFalse;
else
return HdFalse;
}
else
{
if ( TYPE( hdB ) == T_AGWORD )
return HdFalse;
else
return EvalOop2( hdA, hdB, HdRnIsCompatibleAgWord,
"<a> or <b> must be an ag word" );
}
}
#if AG_PROFILE
TypHandle       FunAgProfile ( hdCall )
TypHandle       hdCall;
{
TypHandle       hdInt;
if ( SIZE( hdCall ) != 2 * SIZE_HD && SIZE( hdCall ) != SIZE_HD )
return Error( "usage: AgProfile( <int> ) or AgProfile()",
0L, 0L );
if ( SIZE( hdCall ) == SIZE_HD )
{
if ( RepTimes <= 0 )
{
Pr( "No ag-profiling information, start profiling", 0L, 0L );
Pr( " with 'AgProfile( <int> )'\n",                 0L, 0L );
return HdVoid;
}
Pr( "function       calls        time   time/call\n", 0L, 0L );
Pr( "--------------------------------------------\n", 0L, 0L );
if ( CallsProdAg > 0 )
{
Pr( "ProdAg    %10d  %10d", CallsProdAg, TimeProdAg/RepTimes   );
Pr( "  %10d\n", TimeProdAg/RepTimes / CallsProdAg, 0L          );
}
if ( CallsQuoAg > 0 )
{
Pr( "QuoAg     %10d  %10d", CallsQuoAg, TimeQuoAg/RepTimes     );
Pr( "  %10d\n", TimeQuoAg/RepTimes / CallsQuoAg, 0L            );
}
if ( CallsPowAgI > 0 )
{
Pr( "PowAgI    %10d  %10d", CallsPowAgI, TimePowAgI/RepTimes   );
Pr( "  %10d\n", TimePowAgI/RepTimes / CallsPowAgI, 0L          );
}
if ( CallsPowAgAg > 0 )
{
Pr( "PowAgAg   %10d  %10d", CallsPowAgAg, TimePowAgAg/RepTimes );
Pr( "  %10d\n", TimePowAgAg/RepTimes / CallsPowAgAg, 0L        );
}
if ( CallsModAg > 0 )
{
Pr( "ModAg     %10d  %10d", CallsModAg, TimeModAg/RepTimes     );
Pr( "  %10d\n", TimeModAg/RepTimes / CallsModAg, 0L            );
}
if ( CallsCommAg > 0 )
{
Pr( "CommAg    %10d  %10d", CallsCommAg, TimeCommAg/RepTimes   );
Pr( "  %10d\n", TimeCommAg/RepTimes / CallsCommAg, 0L          );
}
if ( CallsLtAg > 0 )
{
Pr( "LtAg      %10d  %10d", CallsLtAg, TimeLtAg/RepTimes       );
Pr( "  %10d\n", TimeLtAg/RepTimes / CallsLtAg, 0L              );
}
if ( CallsEqAg > 0 )
{
Pr( "EqAg      %10d  %10d", CallsEqAg, TimeEqAg/RepTimes       );
Pr( "  %10d\n", TimeEqAg/RepTimes / CallsEqAg, 0L              );
}
if ( CallsSumAg > 0 )
{
Pr( "SumAg     %10d  %10d", CallsSumAg, TimeSumAg/RepTimes     );
Pr( "  %10d\n", TimeSumAg/RepTimes / CallsSumAg, 0L            );
}
if ( CallsDiffAg > 0 )
{
Pr( "DiffAg    %10d  %10d", CallsSumAg, TimeDiffAg/RepTimes    );
Pr( "  %10d\n", TimeDiffAg/RepTimes / CallsDiffAg, 0L          );
}
Pr( "--------------------------------------------\n", 0L, 0L );
Pr( "Evaluator functions repeated %d times.\n", RepTimes, 0L );
return HdVoid;
}
else
{
hdInt = EVAL( PTR( hdCall )[ 1 ] );
if ( TYPE( hdInt ) != T_INT )
return( Error( "usage: AgProfile( [<int>] )", 0L, 0L ) );
RepTimes = HD_TO_INT( hdInt );
if ( RepTimes > 0 )
{
CallsEqAg    = TimeEqAg    = 0;
CallsLtAg    = TimeLtAg    = 0;
CallsProdAg  = TimeProdAg  = 0;
CallsQuoAg   = TimeQuoAg   = 0;
CallsModAg   = TimeModAg   = 0;
CallsPowAgI  = TimePowAgI  = 0;
CallsPowAgAg = TimePowAgAg = 0;
CallsDiffAg  = TimeDiffAg  = 0;
CallsSumAg   = TimeSumAg   = 0;
TabEq  [ T_AGWORD ][ T_AGWORD ] = TEqAg;
TabLt  [ T_AGWORD ][ T_AGWORD ] = TLtAg;
TabProd[ T_AGWORD ][ T_AGWORD ] = TProdAg;
TabQuo [ T_AGWORD ][ T_AGWORD ] = TQuoAg;
TabMod [ T_AGWORD ][ T_AGWORD ] = TModAg;
TabPow [ T_AGWORD ][ T_INT    ] = TPowAgI;
TabPow [ T_AGWORD ][ T_AGWORD ] = TPowAgAg;
TabComm[ T_AGWORD ][ T_AGWORD ] = TCommAg;
return HdVoid;
}
else
{
RepTimes = 0;
TabEq  [ T_AGWORD ][ T_AGWORD ] = EqAg;
TabLt  [ T_AGWORD ][ T_AGWORD ] = LtAg;
TabProd[ T_AGWORD ][ T_AGWORD ] = ProdAg;
TabQuo [ T_AGWORD ][ T_AGWORD ] = QuoAg;
TabMod [ T_AGWORD ][ T_AGWORD ] = ModAg;
TabPow [ T_AGWORD ][ T_INT    ] = PowAgI;
TabPow [ T_AGWORD ][ T_AGWORD ] = PowAgAg;
TabComm[ T_AGWORD ][ T_AGWORD ] = CommAg;
return HdVoid;
}
}
}
#endif
#if AG_PROFILE

TypHandle       FunCollectorProfile ( hdCall )
TypHandle           hdCall;
{
TypHandle           hdA = 0;
long                i,  j;
char                * usage = "usage: CollectorProfile( ... )";
if ( SIZE( hdCall ) != 2 * SIZE_HD && SIZE( hdCall ) != SIZE_HD )
return Error( usage, 0L, 0L );
if ( SIZE( hdCall ) == 2 * SIZE_HD )
hdA = EVAL( PTR( hdCall )[ 1 ] );
if ( SIZE( hdCall ) == SIZE_HD )
{
Pr( "pnt    calls        time  time/call\n", 0L, 0L );
Pr( "-----------------------------------\n", 0L, 0L );
for ( i = 1;  i <= LEN_LIST( HdCPL );  i++ )
{
long    t,  c;
t = HD_TO_INT( ELM_PLIST( HdCPL, i ) );
c = HD_TO_INT( ELM_PLIST( HdCPC, i ) );
if ( c == 0 )
continue;
Pr( "%3d:  %6d  ", i, c );
Pr( "%10d   %8d\n", t, t/c );
}
Pr( "\nProfile point %d, profiling %sactive\n", CPN,
(long)( (CPP) ? "" : "in" ) );
return HdVoid;
}
else if ( TYPE( hdA ) == T_INT )
{
j = HD_TO_INT( hdA );
if ( j < 0 )
return Error( "<n> must be nonnegative", 0L, 0L);
else if ( j == 0 )
{
if ( LEN_LIST( HdCPS ) == 0 )
return Error( "no collector point set", 0L, 0L );
CPN = HD_TO_INT( ELM_PLIST( HdCPS, LEN_LIST( HdCPS ) ) );
PTR( HdCPS )[ 0 ] = INT_TO_HD( LEN_LIST( HdCPS ) - 1 );
return HdVoid;
}
else
{
if ( j > LEN_LIST( HdCPL ) )
{
Resize( HdCPL, ( j + 1 ) * SIZE_HD );
Resize( HdCPC, ( j + 1 ) * SIZE_HD );
for ( i = LEN_LIST( HdCPL ) + 1;  i <= j;  i++ )
{
PTR( HdCPL )[ i ] = INT_TO_HD( 0 );
PTR( HdCPC )[ i ] = INT_TO_HD( 0 );
}
PTR( HdCPL )[ 0 ] = INT_TO_HD( j );
PTR( HdCPC )[ 0 ] = INT_TO_HD( j );
}
Resize( HdCPS, ( LEN_LIST( HdCPS ) + 2 ) * SIZE_HD );
PTR( HdCPS )[ 0 ] = INT_TO_HD( LEN_LIST( HdCPS ) + 1 );
PTR( HdCPS )[ LEN_LIST( HdCPS ) ] = INT_TO_HD( CPN );
CPN = j;
return HdVoid;
}
}
else if ( TYPE( hdA ) == T_BOOL )
{
if ( hdA == HdTrue )
{
CPP = TRUE;
CPN = 1;
Resize( HdCPL, 2 * SIZE_HD );
Resize( HdCPC, 2 * SIZE_HD );
PTR( HdCPL )[ 0 ] = INT_TO_HD( 1 );
PTR( HdCPL )[ 1 ] = INT_TO_HD( 0 );
PTR( HdCPC )[ 0 ] = INT_TO_HD( 1 );
PTR( HdCPC )[ 1 ] = INT_TO_HD( 0 );
Resize( HdCPS, SIZE_HD );
PTR( HdCPS )[ 0 ] = INT_TO_HD( 0 );
}
else
CPP = FALSE;
return HdVoid;
}
return Error( usage, 0L, 0L );
}
#endif
#if ! PRINT_AG
void        PrAgWord ( hdAgWord )
TypHandle       hdAgWord;
{
TypSword        * pt, * ptEnd;
TypHandle       hdAgGroup;
if ( ISID_AW( hdAgWord ) )
Pr( "IdAgWord", 0L, 0L );
else
{
hdAgGroup = *PTR( hdAgWord );
pt    = PTR_AW( hdAgWord );
ptEnd = pt + 2 * ( LEN_AW( hdAgWord ) - 1 );
while ( pt < ptEnd )
{
Pr( "%>%s", (long) NAME_AW( hdAgGroup, *pt++ ), 0L );
if ( *pt != 1 )
Pr( "^%d", (long) *pt, 0L );
Pr( "*%<", 0L, 0L );
pt++;
}
Pr( "%>%s", (long) NAME_AW( hdAgGroup, *pt++ ), 0L );
if ( *pt != 1 )
Pr( "^%d", (long) *pt, 0L );
Pr ("%<", 0L, 0L );
}
}
#else
void    PrAgWord( hdAgWord )
TypHandle       hdAgWord;
{
TypSword        * pt, * ptEnd;
Pr( "%>agword( %>%d; %<", (long) *PTR( hdAgWord ) / 4L, 0L );
pt    = PTR_AW( hdAgWord );
ptEnd = (TypSword*)( (char*) PTR( hdAgWord ) + SIZE( hdAgWord ) );
while ( pt < ptEnd - 1 )
{
Pr( "%>%d, %<", (long) *pt++, 0L );
Pr( "%>%d; %<", (long) *pt++, 0L );
}
if ( pt < ptEnd )
Pr( "%d )%<", (long) *pt, 0L );
else
Pr( ")%<", 0L, 0L );
}
#endif
#if PRINT_AG | GROUP_REC
void        PrAgExp( hdAgExp )
TypHandle       hdAgExp;
{
TypExp          * pt, * ptEnd;
pt    = (TypExp*) PTR( hdAgExp );
ptEnd = (TypExp*)( (char*) PTR( hdAgExp ) + SIZE( hdAgExp ) );
if ( SIZE( hdAgExp ) == 0 )
Pr( "%>agexp( )%<", 0L, 0L );
else
{
Pr( "%>agexp( %<", 0L, 0L );
while ( pt < ptEnd - 1 )
Pr( "%>%d, %<", (long) (*pt++), 0L );
Pr( "%>%d )%<", (long) *pt, 0L );
}
}
#endif
#if PRINT_AG | GROUP_REC
void        PrAgList( hdAgList )
TypHandle       hdAgList;
{
TypSword        * pt, * ptEnd;
int             toggle;
pt    = (TypSword*) PTR( hdAgList );
ptEnd = (TypSword*)( (char*) PTR( hdAgList ) + SIZE( hdAgList ) );
if ( SIZE( hdAgList ) == 0 )
Pr( "%>aglist( )%<", 0L, 0L );
else
{
toggle = 0;
Pr( "%>aglist( %<", 0L, 0L );
while ( pt < ptEnd - 1 )
{
if ( toggle == 0 )
Pr( "%>%d, %<", (long) (*pt++), 0L );
else
Pr( "%>%d; %<", (long) (*pt++), 0L );
toggle = 1 - toggle;
}
Pr( "%>%d )%<", (long) *pt, 0L );
}
}
#endif
#if PRINT_AG | GROUP_REC
void    PrAgen( hdAgen )
TypHandle       hdAgen;
{
Pr( "%s", (long)( PTR( hdAgen ) + 1 ), 0L );
}
#endif

void        InitAg()
{
HdCallOop1 = NewBag( T_FUNCCALL, 2 * SIZE_HD );
HdCallOop2 = NewBag( T_FUNCCALL, 3 * SIZE_HD );
InstEvFunc( T_AGWORD, EvAg );
TabEq[ T_AGWORD ][ T_AGWORD ] = EqAg;
TabLt[ T_AGWORD ][ T_AGWORD ] = LtAg;
TabProd[ T_AGWORD ][ T_AGWORD ] = ProdAg;
TabQuo [ T_AGWORD ][ T_AGWORD ] = QuoAg;
TabMod [ T_AGWORD ][ T_AGWORD ] = ModAg;
TabPow [ T_AGWORD ][ T_INT    ] = PowAgI;
TabPow [ T_AGWORD ][ T_AGWORD ] = PowAgAg;
TabComm[ T_AGWORD ][ T_AGWORD ] = CommAg;
#   if ! PRINT_AG
#       if ! GROUP_REC
InstPrFunc(  T_AGWORD,      PrAgWord    );
#       else
InstPrFunc(  T_AGWORD,      PrAgWord    );
InstPrFunc(  T_AGEXP,       PrAgExp     );
InstPrFunc(  T_AGLIST,      PrAgList    );
InstPrFunc(  T_AGEN,        PrAgen      );
InstIntFunc( "DUMP_LONG",   FunDUMPLONG );
#       endif
#   else
InstPrFunc(  T_AGWORD,      PrAgWord    );
InstPrFunc(  T_AGEXP,       PrAgExp     );
InstPrFunc(  T_AGLIST,      PrAgList    );
InstPrFunc(  T_AGEN,        PrAgen      );
InstIntFunc( "DUMP_LONG",   FunDUMPLONG );
#   endif
HdRnSumAgWord             = FindRecname( "SumAgWord"          );
HdRnDifferenceAgWord      = FindRecname( "DifferenceAgWord"   );
HdRnDepth                 = FindRecname( "Depth"              );
HdRnTailDepth             = FindRecname( "TailDepth"          );
HdRnCentralWeight         = FindRecname( "CentralWeight"      );
HdRnLeadingExponent       = FindRecname( "LeadingExponent"    );
HdRnReducedAgWord         = FindRecname( "ReducedAgWord"      );
HdRnRelativeOrder         = FindRecname( "RelativeOrder"      );
HdRnExponentAgWord        = FindRecname( "ExponentAgWord"     );
HdRnExponentsAgWord       = FindRecname( "ExponentsAgWord"    );
HdRnInformationAgWord     = FindRecname( "InformationAgWord"  );
HdRnIsCompatibleAgWord    = FindRecname( "IsCompatibleAgWord" );
HdRnNormalizeIgs          = FindRecname( "NormalizeIgs"       );
HdRnIsAgWord              = FindRecname( "IsAgWord"           );
HdRnAvec = FindRecname( "avec" );
InstIntFunc( "SumAgWord",               FunSumAgWord             );
InstIntFunc( "DifferenceAgWord",        FunDifferenceAgWord      );
InstIntFunc( "DepthAgWord",             FunDepthAgWord           );
InstIntFunc( "TailDepthAgWord",         FunTailDepthAgWord       );
InstIntFunc( "CentralWeightAgWord",     FunCentralWeightAgWord   );
InstIntFunc( "LeadingExponentAgWord",   FunLeadingExponentAgWord );
InstIntFunc( "ReducedAgWord",           FunReducedAgWord         );
InstIntFunc( "RelativeOrderAgWord",     FunRelativeOrderAgWord   );
InstIntFunc( "ExponentAgWord",          FunExponentAgWord        );
InstIntFunc( "ExponentsAgWord",         FunExponentsAgWord       );
InstIntFunc( "InformationAgWord",       FunInformationAgWord     );
InstIntFunc( "IsAgWord",                FunIsAgWord              );
InstIntFunc( "IsCompatibleAgWord",      FunIsCompatibleAgWord   );
InstIntFunc( "NormalizeIgs",            FunNormalizeIgs         );
InstIntFunc( "AgFpGroup",               FunAgFpGroup            );
InstIntFunc( "FactorAgWord",            FunFactorAgWord         );
InstIntFunc( "FactorAgGroup",           FunFactorAgGroup        );
#   if GROUP_REC
InstIntFunc( "AgGroupRecord",       FunAgGroupRecord        );
#   endif
#   if AG_PROFILE
InstIntFunc( "AgProfile",           FunAgProfile            );
InstIntFunc( "CollectorProfile",    FunCollectorProfile     );
#   endif
#   if AG_PROFILE
HdCPL = NewBag( T_LIST, SIZE_HD );
PTR( HdCPL )[ 0 ] = INT_TO_HD( 0 );
HdCPC = NewBag( T_LIST, SIZE_HD );
PTR( HdCPC )[ 0 ] = INT_TO_HD( 0 );
HdCPS = NewBag( T_LIST, SIZE_HD );
PTR( HdCPS )[ 0 ] = INT_TO_HD( 0 );
#   endif
InstIntFunc( "SetCollectorAgWord", FunSetCollectorAgWord );
}
/* 当前文件是D:\Read\blister.c*/

/* 当前文件是D:\Read\range.h*/

#ifdef SPEC_CPU2000_P64
#define long __int64
#endif
#define SIZE_PLEN_RANGE(PLEN)           (3 * SIZE_HD)
#define LEN_RANGE(LIST)                 HD_TO_INT(PTR(LIST)[0])
#define SET_LEN_RANGE(LIST,LEN)         (PTR(LIST)[0] = INT_TO_HD(LEN))
#define LOW_RANGE(LIST)                 HD_TO_INT(PTR(LIST)[1])
#define SET_LOW_RANGE(LIST,LOW)         (PTR(LIST)[1] = INT_TO_HD(LOW))
#define INC_RANGE(LIST)                 HD_TO_INT(PTR(LIST)[2])
#define SET_INC_RANGE(LIST,INC)         (PTR(LIST)[2] = INT_TO_HD(INC))
#define ELM_RANGE(L,POS)        INT_TO_HD(LOW_RANGE(L)+(POS-1)*INC_RANGE(L))

/* 当前文件是D:\Read\set.h*/

#ifdef SPEC_CPU2000_P64
#define long __int64
#endif

/* 当前文件是D:\Read\blister.h*/

#ifdef SPEC_CPU2000_P64
#define long __int64
#endif
#define BIPEB                           (sizeof(unsigned long) * 8L)
#define PLEN_SIZE_BLIST(SIZE)           ((((SIZE)-SIZE_HD)/SIZE_HD) * BIPEB)
#define SIZE_PLEN_BLIST(PLEN)        (SIZE_HD+((PLEN)+BIPEB-1)/BIPEB*SIZE_HD)
#define LEN_BLIST(LIST)                 (HD_TO_INT(PTR(LIST)[0]))
#define SET_LEN_BLIST(LIST,LEN)         (PTR(LIST)[0] = INT_TO_HD(LEN))
#define ELM_BLIST(LIST,POS)             \
(((unsigned long*)(PTR(LIST)+1))[((POS)-1)/BIPEB]&((size_t)1<<((POS)-1)%BIPEB) ? \
HdTrue : HdFalse)
#define SET_ELM_BLIST(LIST,POS,VAL)     \
((VAL) == HdTrue ?                     \
(((unsigned long*)(PTR(LIST)+1))[((POS)-1)/BIPEB]|=((size_t)1<<((POS)-1)%BIPEB)):\
(((unsigned long*)(PTR(LIST)+1))[((POS)-1)/BIPEB]&=~((size_t)1<<((POS)-1)%BIPEB)))

long            LenBlist ( hdList )
TypHandle           hdList;
{
return LEN_BLIST( hdList );
}
TypHandle       ElmBlist ( hdList, pos )
TypHandle           hdList;
long                pos;
{
if ( LEN_BLIST( hdList ) < pos ) {
return Error(
"List Element: <list>[%d] must have a value",
pos, 0L );
}
return ELM_BLIST( hdList, pos );
}
TypHandle       ElmfBlist ( hdList, pos )
TypHandle           hdList;
long                pos;
{
return ELM_BLIST( hdList, pos );
}
TypHandle       ElmsBlist ( hdList, hdPoss )
TypHandle           hdList;
TypHandle           hdPoss;
{
TypHandle           hdElms;
long                lenList;
TypHandle           hdElm;
long                lenPoss;
long                pos;
long                inc;
unsigned long       block;
unsigned long       bit;
long                i;
if ( TYPE(hdPoss) != T_RANGE ) {
lenList = LEN_BLIST( hdList );
lenPoss = LEN_LIST( hdPoss );
hdElms = NewBag( T_BLIST, SIZE_PLEN_BLIST( lenPoss ) );
SET_LEN_BLIST( hdElms, lenPoss );
block = 0;  bit = 1;
for ( i = 1; i <= lenPoss; i++ ) {
pos = HD_TO_INT( ELMF_LIST( hdPoss, i ) );
if ( lenList < pos ) {
return Error(
"List Elements: <list>[%d] must have a value",
pos, 0L );
}
hdElm = ELM_BLIST( hdList, pos );
if ( hdElm == HdTrue )
block |= bit;
bit <<= 1;
if ( bit == 0 || i == lenPoss ) {
((unsigned long *)(PTR(hdElms)+1))[(i-1)/BIPEB] = block;
block = 0;
bit = 1;
}
}
}
else {
lenList = LEN_PLIST( hdList );
lenPoss = LEN_RANGE( hdPoss );
pos = LOW_RANGE( hdPoss );
inc = INC_RANGE( hdPoss );
if ( lenList < pos ) {
return Error(
"List Elements: <list>[%d] must have a value",
pos, 0L );
}
if ( lenList < pos + (lenPoss-1) * inc ) {
return Error(
"List Elements: <list>[%d] must have a value",
pos + (lenPoss-1) * inc, 0L );
}
hdElms = NewBag( T_BLIST, SIZE_PLEN_BLIST( lenPoss ) );
SET_LEN_BLIST( hdElms, lenPoss );
block = 0;  bit = 1;
for ( i = 1; i <= lenPoss; i++, pos += inc ) {
hdElm = ELM_BLIST( hdList, pos );
if ( hdElm == HdTrue )
block |= bit;
bit <<= 1;
if ( bit == 0 || i == lenPoss ) {
((unsigned long *)(PTR(hdElms)+1))[(i-1)/BIPEB] = block;
block = 0;
bit = 1;
}
}
}
return hdElms;
}
TypHandle       AssBlist ( hdList, pos, hdVal )
TypHandle           hdList;
long                pos;
TypHandle           hdVal;
{
long                plen;
if      ( pos <= LEN_BLIST(hdList) && hdVal == HdTrue ) {
SET_ELM_BLIST( hdList, pos, HdTrue );
}
else if ( pos <= LEN_BLIST(hdList) && hdVal == HdFalse ) {
SET_ELM_BLIST( hdList, pos, HdFalse );
}
else if ( pos == LEN_BLIST(hdList)+1 && hdVal == HdTrue ) {
if ( SIZE(hdList) < SIZE_PLEN_BLIST(pos) )
Resize( hdList, SIZE_PLEN_BLIST(pos) );
SET_LEN_BLIST( hdList, pos );
SET_ELM_BLIST( hdList, pos, HdTrue );
}
else if ( pos == LEN_BLIST(hdList)+1 && hdVal == HdFalse ) {
if ( SIZE(hdList) < SIZE_PLEN_BLIST(pos) )
Resize( hdList, SIZE_PLEN_BLIST(pos) );
SET_LEN_BLIST( hdList, pos );
SET_ELM_BLIST( hdList, pos, HdFalse );
}
else {
PLAIN_LIST( hdList );
Retype( hdList, T_LIST );
if ( LEN_PLIST(hdList) < pos ) {
plen = PLEN_SIZE_PLIST( SIZE(hdList) );
if ( plen + plen/8 + 4 < pos )
Resize( hdList, SIZE_PLEN_PLIST( pos ) );
else if ( plen < pos )
Resize( hdList, SIZE_PLEN_PLIST( plen + plen/8 + 4 ) );
SET_LEN_PLIST( hdList, pos );
}
SET_ELM_PLIST( hdList, pos, hdVal );
}
return hdVal;
}
TypHandle       AsssBlist ( hdList, hdPoss, hdVals )
TypHandle           hdList;
TypHandle           hdPoss;
TypHandle           hdVals;
{
PLAIN_LIST( hdList );
Retype( hdList, T_LIST );
return ASSS_LIST( hdList, hdPoss, hdVals );
}
long            PosBlist ( hdBlist, hdVal, start )
TypHandle           hdBlist;
TypHandle           hdVal;
long                start;
{
long                k;
long                len;
unsigned long       * ptBlist;
long                i,  j;
len = LEN_BLIST(hdBlist);
if ( len == start ) {
k = 0;
}
else if ( hdVal == HdTrue ) {
ptBlist = (unsigned long *)(PTR(hdBlist)+1);
if ( ptBlist[start/BIPEB] >> (start%BIPEB) != 0 ) {
i = start/BIPEB;
for ( j=start%BIPEB; j<BIPEB && (ptBlist[i]&((size_t)1<<j))==0; j++ )
;
}
else {
for ( i=start/BIPEB+1; i<(len-1)/BIPEB && ptBlist[i]==0; i++ )
;
for ( j=0; j<BIPEB && (ptBlist[i]&((size_t)1<<j))==0; j++ )
;
}
k = (BIPEB*i+j+1 <= len ? BIPEB*i+j+1 : 0);
}
else if ( hdVal == HdFalse ) {
ptBlist = (unsigned long *)(PTR(hdBlist)+1);
if ( ~ptBlist[start/BIPEB] >> (start%BIPEB) != 0 ) {
i = start/BIPEB;
for ( j=start%BIPEB; j<BIPEB && (~ptBlist[i]&((size_t)1<<j))==0; j++ )
;
}
else {
for ( i=start/BIPEB+1; i<(len-1)/BIPEB && ~ptBlist[i]==0; i++ )
;
for ( j=0; j<BIPEB && (~ptBlist[i]&((size_t)1<<j))==0; j++ )
;
}
k = (BIPEB*i+j+1 <= len ? BIPEB*i+j+1 : 0);
}
else {
k = 0;
}
return k;
}
void            PlainBlist ( hdList )
TypHandle           hdList;
{
long                lenList;
long                i;
lenList = LEN_BLIST( hdList );
Resize( hdList, SIZE_PLEN_PLIST( lenList ) );
Retype( hdList, T_LIST );
SET_LEN_PLIST( hdList, lenList );
for ( i = lenList; 0 < i; i-- )
SET_ELM_PLIST( hdList, i, ELM_BLIST( hdList, i ) );
}
long            IsDenseBlist ( hdList )
TypHandle           hdList;
{
return 1;
}
long            IsPossBlist ( hdList )
TypHandle           hdList;
{
return LEN_BLIST(hdList) == 0;
}
TypHandle       EqBlist ( hdL, hdR )
TypHandle           hdL;
TypHandle           hdR;
{
long                lenL;
long                lenR;
unsigned long       * ptL;
unsigned long       * ptR;
unsigned long       i;
lenL = LEN_BLIST( hdL );
lenR = LEN_BLIST( hdR );
if ( lenL != lenR ) {
return HdFalse;
}
ptL = (unsigned long *)(PTR(hdL)+1);
ptR = (unsigned long *)(PTR(hdR)+1);
for ( i = (lenL+BIPEB-1)/BIPEB; 0 < i; i-- ) {
if ( *ptL++ != *ptR++ )
return HdFalse;
}
return HdTrue;
}
long            IsBlist ( hdList )
TypHandle           hdList;
{
unsigned long       isBlist;
unsigned long       len;
unsigned long       block;
unsigned long       bit;
unsigned long       i;
if ( TYPE(hdList) == T_BLIST ) {
isBlist = 1;
}
else if ( ! IS_LIST( hdList ) ) {
isBlist = 0;
}
else {
len = LEN_LIST( hdList );
for ( i = 1; i <= len; i++ ) {
if ( ELMF_LIST( hdList, i ) == 0
|| (ELMF_LIST( hdList, i ) != HdTrue
&& ELMF_LIST( hdList, i ) != HdFalse) ) {
break;
}
}
isBlist = (len < i);
if ( isBlist ) {
block = 0;
bit = 1;
for ( i = 1; i <= len; i++ ) {
if ( ELMF_LIST( hdList, i ) == HdTrue )
block |= bit;
bit = bit << 1;
if ( bit == 0 || i == len ) {
((unsigned long *)(PTR(hdList)+1))[(i-1)/BIPEB] = block;
block = 0;
bit = 1;
}
}
Retype( hdList, T_BLIST );
Resize( hdList, SIZE_PLEN_BLIST( len ) );
SET_LEN_BLIST( hdList, len );
}
}
return isBlist;
}
TypHandle       FunIsBlist ( hdCall )
TypHandle           hdCall;
{
TypHandle           hdObj;
if ( SIZE(hdCall) != 2 * SIZE_HD )
return Error("usage: IsBlist( <obj> )",0L,0L);
hdObj = EVAL( PTR(hdCall)[1] );
if ( hdObj == HdVoid )
return Error("IsBlist: function must return a value",0L,0L);
return IsBlist( hdObj ) ? HdTrue : HdFalse;
}
TypHandle       FunBlistList ( hdCall )
TypHandle           hdCall;
{
TypHandle           hdBlist;
unsigned long       * ptBlist;
unsigned long       block;
unsigned long       bit;
TypHandle           hdList;
unsigned long       lnList;
TypHandle           hdSub;
TypHandle           * ptSub;
unsigned long       lnSub;
unsigned long       i, j, k, l;
long                s, t;
if ( SIZE(hdCall) != 3*SIZE_HD )
return Error("usage: BlistList( <list>, <sub> )",0L,0L);
hdList = EVAL( PTR(hdCall)[1] );
if ( ! IS_LIST(hdList) )
return Error("BlistList: <list> must be a list",0L,0L);
hdSub = EVAL( PTR(hdCall)[2] );
if ( ! IS_LIST(hdSub) )
return Error("BlistList: <sub> must be a list",0L,0L);
if ( TYPE(hdList) == T_RANGE && TYPE(hdSub) == T_RANGE ) {
lnList  = LEN_RANGE( hdList );
lnSub   = LEN_RANGE( hdSub );
hdBlist = NewBag( T_BLIST, SIZE_PLEN_BLIST( lnList ) );
PTR(hdBlist)[0] = INT_TO_HD(lnList);
ptBlist = (unsigned long *)(PTR(hdBlist)+1);
s = HD_TO_INT( ELM_RANGE( hdList, 1 ) );
t = HD_TO_INT( ELM_RANGE( hdSub, 1 ) );
if ( s <= t )  i = t - s + 1;
else           i = 1;
if ( i + lnSub - 1 <= lnList )  j = i + lnSub - 1;
else                            j = lnList;
for ( k = i; k <= j && (k-1)%BIPEB != 0; k++ )
ptBlist[(k-1)/BIPEB] |= ((size_t)1 << (k-1)%BIPEB);
for ( ; k+BIPEB <= j; k += BIPEB )
ptBlist[(k-1)/BIPEB] = ~0L;
for ( ; k <= j; k++ )
ptBlist[(k-1)/BIPEB] |= ((size_t)1 << (k-1)%BIPEB);
}
else if ( TYPE(hdList) == T_RANGE
&& (TYPE(hdSub) == T_LIST || TYPE(hdSub) == T_SET) ) {
lnList  = LEN_RANGE( hdList );
lnSub   = LEN_LIST( hdSub );
hdBlist = NewBag( T_BLIST, SIZE_PLEN_BLIST( lnList ) );
PTR(hdBlist)[0] = INT_TO_HD(lnList);
ptBlist = (unsigned long *)(PTR(hdBlist)+1);
ptSub = PTR(hdSub);
s = HD_TO_INT( ELM_RANGE( hdList, 1 ) );
for ( l = 1; l <= LEN_LIST(hdSub); l++ ) {
if ( ptSub[l] != 0 ) {
if ( TYPE( ptSub[l] ) == T_INT ) {
t = HD_TO_INT( ptSub[l] ) - s + 1;
if ( 0 < t && t <= lnList )
ptBlist[(t-1)/BIPEB] |= ((size_t)1 << (t-1)%BIPEB);
}
else {
k = PosRange( hdList, ptSub[l], 0L );
if ( k != 0 )
ptBlist[(k-1)/BIPEB] |= ((size_t)1 << (k-1)%BIPEB);
}
}
}
}
else if ( IsSet( hdList ) ) {
lnList = LEN_PLIST( hdList );
for ( i = lnList, l = 0; i != 0; i >>= 1, l++ ) ;
if ( TYPE(hdSub) != T_LIST && TYPE(hdSub) != T_SET )
IsList( hdSub );
lnSub = LEN_LIST( hdSub );
if ( l * lnSub < 2 * lnList ) {
hdBlist = NewBag( T_BLIST, SIZE_PLEN_BLIST( lnList ) );
PTR(hdBlist)[0] = INT_TO_HD(lnList);
for ( l = 1; l <= LEN_LIST(hdSub); l++ ) {
if ( PTR(hdSub)[l] != 0 ) {
i = 0;  k = lnList+1;
while ( i+1 < k ) {
j = (i + k) / 2;
if ( LT( PTR(hdList)[j], PTR(hdSub)[l] ) == HdTrue )
i = j;
else
k = j;
}
if ( k <= lnList
&& EQ( PTR(hdList)[k], PTR(hdSub)[l] ) == HdTrue )
((unsigned long *)(PTR(hdBlist)+1))[(k-1)/BIPEB]
|= ((size_t)1 << (k-1)%BIPEB);
}
}
}
else {
if ( ! IsSet( hdSub ) )  hdSub = SetList( hdSub );
hdBlist = NewBag( T_BLIST, SIZE_PLEN_BLIST( lnList ) );
PTR(hdBlist)[0] = INT_TO_HD(lnList);
k = 1;
block = 0;
bit   = 1;
for ( l = 1; l <= lnList; l++ ) {
while ( k <= lnSub
&& LT(PTR(hdSub)[k],PTR(hdList)[l]) == HdTrue )
k++;
if ( k <= lnSub
&& EQ(PTR(hdSub)[k],PTR(hdList)[l]) == HdTrue ) {
block |= bit;
k++;
}
bit = bit << 1;
if ( bit == 0 || l == lnList ) {
((unsigned long *)(PTR(hdBlist)+1))[(l-1)/BIPEB] = block;
block = 0;
bit   = 1;
}
}
}
}
else {
i = IsList( hdList );
if ( ! IsSet( hdSub ) )  hdSub = SetList( hdSub );
lnList  = LEN_LIST( hdList );
lnSub   = LEN_PLIST( hdSub );
hdBlist = NewBag( T_BLIST, SIZE_PLEN_BLIST( lnList ) );
PTR(hdBlist)[0] = INT_TO_HD(lnList);
k = 1;
block = 0;
bit   = 1;
for ( l = 1; l <= lnList; l++ ) {
if ( l == 1 || LT(PTR(hdList)[l-1],PTR(hdList)[l]) == HdTrue ) {
while ( k <= lnSub
&& LT(PTR(hdSub)[k],PTR(hdList)[l]) == HdTrue )
k++;
}
else {
i = 0;  k = LEN_PLIST(hdSub) + 1;
while ( i+1 < k ) {
j = (i + k) / 2;
if ( LT( PTR(hdSub)[j], PTR(hdList)[l] ) == HdTrue )
i = j;
else
k = j;
}
}
if ( k <= lnSub
&& EQ( PTR(hdSub)[k], PTR(hdList)[l] ) == HdTrue ) {
block |= bit;
k++;
}
bit = bit << 1;
if ( bit == 0 || l == lnList ) {
((unsigned long *)(PTR(hdBlist)+1))[(l-1)/BIPEB] = block;
block = 0;
bit   = 1;
}
}
}
return hdBlist;
}
TypHandle       FunListBlist ( hdCall )
TypHandle           hdCall;
{
TypHandle           hdSub;
TypHandle           hdList;
unsigned long       len;
TypHandle           hdBlist;
unsigned long       * ptBlist;
unsigned long       nrb;
unsigned long       m;
unsigned long       n;
unsigned long       i;
if ( SIZE(hdCall) != 3*SIZE_HD )
return Error("usage: ListBlist( <list>, <blist> )",0L,0L);
hdList = EVAL( PTR(hdCall)[1] );
if ( ! IS_LIST( hdList ) )
return Error("ListBlist: <list> must be a list",0L,0L);
PLAIN_LIST( hdList );
hdBlist = EVAL( PTR(hdCall)[2] );
if ( ! IsBlist( hdBlist ) )
return Error("ListBlist: <blist> must be a boolean list",0L,0L);
if ( LEN_PLIST( hdList ) != LEN_BLIST( hdBlist ) )
return Error("ListBlist: <list>, <blist> must have same size",0L,0L);
nrb = (LEN_BLIST(hdBlist)+BIPEB-1)/BIPEB;
ptBlist = (unsigned long *)(PTR(hdBlist)+1);
n = 0;
for ( i = 1; i <= nrb; i++, ptBlist++ ) {
m = *ptBlist;
m = (m & 0x55555555) + ((m >> 1) & 0x55555555);
m = (m & 0x33333333) + ((m >> 2) & 0x33333333);
m = (m + (m >>  4)) & 0x0f0f0f0f;
m = (m + (m >>  8));
m = (m + (m >> 16)) & 0x000000ff;
n += m;
}
hdSub = NewBag( TYPE(hdList), SIZE_PLEN_PLIST( n ) );
SET_LEN_PLIST( hdSub, n );
len = LEN_LIST( hdList );
n = 1;
for ( i = 1; i <= len; i++ ) {
if ( ELM_BLIST( hdBlist, i ) == HdTrue ) {
SET_ELM_PLIST( hdSub, n, ELMF_LIST( hdList, i ) );
n++;
}
}
return hdSub;
}
TypHandle       FunSizeBlist ( hdCall )
TypHandle           hdCall;
{
TypHandle           hdBlist;
unsigned long       * ptBlist;
unsigned long       nrb;
unsigned long       m;
unsigned long       n;
unsigned long       i;
if ( SIZE(hdCall) != 2*SIZE_HD )
return Error("usage: SizeBlist( <blist> )",0L,0L);
hdBlist = EVAL( PTR(hdCall)[1] );
if ( TYPE(hdBlist) != T_BLIST && ! IsBlist(hdBlist) )
return Error("SizeBlist: <blist> must be a boolean list",0L,0L);
nrb = (LEN_BLIST(hdBlist)+BIPEB-1)/BIPEB;
ptBlist = (unsigned long *)(PTR(hdBlist)+1);
n = 0;
for ( i = 1; i <= nrb; i++, ptBlist++ ) {
m = *ptBlist;
m = (m & 0x55555555) + ((m >> 1) & 0x55555555);
m = (m & 0x33333333) + ((m >> 2) & 0x33333333);
m = (m + (m >>  4)) & 0x0f0f0f0f;
m = (m + (m >>  8));
m = (m + (m >> 16)) & 0x000000ff;
n += m;
}
return INT_TO_HD( n );
}
TypHandle       FunIsSubsetBlist ( hdCall )
TypHandle           hdCall;
{
TypHandle           hdBlist1;
TypHandle           hdBlist2;
unsigned long       * ptBlist1;
unsigned long       * ptBlist2;
unsigned long       i;
if ( SIZE(hdCall) != 3*SIZE_HD )
return Error("usage: IsSubsetBlist( <blist1>, <blist2> )",0L,0L);
hdBlist1 = EVAL( PTR(hdCall)[1] );
if ( ! IsBlist( hdBlist1 ) )
return Error("IsSubsetBlist: <blist1> must be a boolean list",0L,0L);
hdBlist2 = EVAL( PTR(hdCall)[2] );
if ( ! IsBlist( hdBlist2 ) )
return Error("IsSubsetBlist: <blist2> must be a boolean list",0L,0L);
if ( LEN_BLIST(hdBlist1) != LEN_BLIST(hdBlist2) )
return Error("IsSubsetBlist: lists must have equal length",0L,0L);
ptBlist1 = (unsigned long *)(PTR(hdBlist1)+1);
ptBlist2 = (unsigned long *)(PTR(hdBlist2)+1);
for ( i = (LEN_BLIST(hdBlist1)+BIPEB-1)/BIPEB; 0 < i; i-- ) {
if ( *ptBlist1 != (*ptBlist1 | *ptBlist2) )
break;
ptBlist1++;  ptBlist2++;
}
return (i == 0) ? HdTrue : HdFalse;
}
TypHandle       FunUniteBlist ( hdCall )
TypHandle           hdCall;
{
TypHandle           hdBlist1;
TypHandle           hdBlist2;
unsigned long       * ptBlist1;
unsigned long       * ptBlist2;
unsigned long       i;
if ( SIZE(hdCall) != 3*SIZE_HD )
return Error("usage: UniteBlist( <blist1>, <blist2> )",0L,0L);
hdBlist1 = EVAL( PTR(hdCall)[1] );
if ( ! IsBlist( hdBlist1 ) )
return Error("UniteBlist: <blist1> must be a boolean list",0L,0L);
hdBlist2 = EVAL( PTR(hdCall)[2] );
if ( ! IsBlist( hdBlist2 ) )
return Error("UniteBlist: <blist2> must be a boolean list",0L,0L);
if ( LEN_BLIST(hdBlist1) != LEN_BLIST(hdBlist2) )
return Error("UniteBlist: lists must have equal length",0L,0L);
ptBlist1 = (unsigned long *)(PTR(hdBlist1)+1);
ptBlist2 = (unsigned long *)(PTR(hdBlist2)+1);
for ( i = (LEN_BLIST(hdBlist1)+BIPEB-1)/BIPEB; 0 < i; i-- )
*ptBlist1++ |= *ptBlist2++;
return HdVoid;
}
TypHandle       FunIntersectBlist ( hdCall )
TypHandle           hdCall;
{
TypHandle           hdBlist1;
TypHandle           hdBlist2;
unsigned long       * ptBlist1;
unsigned long       * ptBlist2;
unsigned long       i;
if ( SIZE(hdCall) != 3*SIZE_HD )
return Error("usage: IntersectBlist( <blist1>, <blist2> )",0L,0L);
hdBlist1 = EVAL( PTR(hdCall)[1] );
if ( ! IsBlist( hdBlist1 ) )
return Error("IntersectBlist: <blist1> must be a boolean list",0L,0L);
hdBlist2 = EVAL( PTR(hdCall)[2] );
if ( ! IsBlist( hdBlist2 ) )
return Error("IntersectBlist: <blist2> must be a boolean list",0L,0L);
if ( LEN_BLIST(hdBlist1) != LEN_BLIST(hdBlist2) )
return Error("IntersectBlist: lists must have equal length",0L,0L);
ptBlist1 = (unsigned long *)(PTR(hdBlist1)+1);
ptBlist2 = (unsigned long *)(PTR(hdBlist2)+1);
for ( i = (LEN_BLIST(hdBlist1)+BIPEB-1)/BIPEB; 0 < i; i-- )
*ptBlist1++ &= *ptBlist2++;
return HdVoid;
}
TypHandle       FunSubtractBlist ( hdCall )
TypHandle           hdCall;
{
TypHandle           hdBlist1;
TypHandle           hdBlist2;
unsigned long       * ptBlist1;
unsigned long       * ptBlist2;
unsigned long       i;
if ( SIZE(hdCall) != 3*SIZE_HD )
return Error("usage: SubtractBlist( <blist1>, <blist2> )",0L,0L);
hdBlist1 = EVAL( PTR(hdCall)[1] );
if ( ! IsBlist( hdBlist1 ) )
return Error("SubtractBlist: <blist1> must be a boolean list",0L,0L);
hdBlist2 = EVAL( PTR(hdCall)[2] );
if ( ! IsBlist( hdBlist2 ) )
return Error("SubtractBlist: <blist2> must be a boolean list",0L,0L);
if ( LEN_BLIST(hdBlist1) != LEN_BLIST(hdBlist2) )
return Error("SubtractBlist: lists must have equal length",0L,0L);
ptBlist1 = (unsigned long *)(PTR(hdBlist1)+1);
ptBlist2 = (unsigned long *)(PTR(hdBlist2)+1);
for ( i = (LEN_BLIST(hdBlist1)+BIPEB-1)/BIPEB; 0 < i; i-- )
*ptBlist1++ &= ~ *ptBlist2++;
return HdVoid;
}
TypHandle       FunDistanceBlist ( hdCall )
TypHandle           hdCall;
{
TypHandle           hdBlist1;
TypHandle           hdBlist2;
unsigned long       * ptBlist1;
unsigned long       * ptBlist2;
unsigned long       m;
unsigned long       n;
unsigned long       i;
if ( SIZE(hdCall) != 3*SIZE_HD )
return Error("usage: DistanceBlist( <blist1>, <blist2> )",0L,0L);
hdBlist1 = EVAL( PTR(hdCall)[1] );
if ( ! IsBlist( hdBlist1 ) )
return Error("DistanceBlist: <blist1> must be a boolean list",0L,0L);
hdBlist2 = EVAL( PTR(hdCall)[2] );
if ( ! IsBlist( hdBlist2 ) )
return Error("DistanceBlist: <blist2> must be a boolean list",0L,0L);
if ( LEN_BLIST(hdBlist1) != LEN_BLIST(hdBlist2) )
return Error("DistanceBlist: lists must have equal length",0L,0L);
ptBlist1 = (unsigned long *)(PTR(hdBlist1)+1);
ptBlist2 = (unsigned long *)(PTR(hdBlist2)+1);
n = 0;
for ( i = (LEN_BLIST(hdBlist1)+BIPEB-1)/BIPEB; 0 < i; i-- ) {
m = (*ptBlist1++) ^ (*ptBlist2++);
m = (m & 0x55555555) + ((m >> 1) & 0x55555555);
m = (m & 0x33333333) + ((m >> 2) & 0x33333333);
m = (m + (m >>  4)) & 0x0f0f0f0f;
m = (m + (m >>  8));
m = (m + (m >> 16)) & 0x000000ff;
n += m;
}
return INT_TO_HD(n);
}
TypHandle       EvList ( hdList )
TypHandle           hdList;
{
return hdList;
}
void            PrList ( hdList )
TypHandle           hdList;
{
long                lenList;
TypHandle           hdElm;
long                i;
lenList = LEN_LIST( hdList );
Pr("%2>[ %2>",0L,0L);
for ( i = 1;  i <= lenList;  i++ ) {
hdElm = ELMF_LIST( hdList, i );
if ( hdElm != 0 ) {
if ( 1 < i )  Pr("%<,%< %2>",0L,0L);
Print( hdElm );
}
else {
if ( 1 < i )  Pr("%2<,%2>",0L,0L);
}
}
Pr(" %4<]",0L,0L);
}
TypHandle       EqList ( hdL, hdR )
TypHandle           hdL;
TypHandle           hdR;
{
long                lenL;
long                lenR;
TypHandle           hdElmL;
TypHandle           hdElmR;
long                i;
lenL = LEN_LIST( hdL );
lenR = LEN_LIST( hdR );
if ( lenL != lenR ) {
return HdFalse;
}
for ( i = 1; i <= lenL; i++ ) {
hdElmL = ELML_LIST( hdL, i );
hdElmR = ELMR_LIST( hdR, i );
if ( hdElmL == 0 && hdElmR != 0 ) {
return HdFalse;
}
else if ( hdElmR == 0 && hdElmL != 0 ) {
return HdFalse;
}
else if ( hdElmL != hdElmR && EQ( hdElmL, hdElmR ) == HdFalse ) {
return HdFalse;
}
}
return HdTrue;
}
TypHandle       LtList ( hdL, hdR )
TypHandle           hdL;
TypHandle           hdR;
{
long                lenL;
long                lenR;
TypHandle           hdElmL;
TypHandle           hdElmR;
long                i;
lenL = LEN_LIST( hdL );
lenR = LEN_LIST( hdR );
for ( i = 1; i <= lenL && i <= lenR; i++ ) {
hdElmL = ELML_LIST( hdL, i );
hdElmR = ELMR_LIST( hdR, i );
if ( hdElmL == 0 && hdElmR != 0 ) {
return HdTrue;
}
else if ( hdElmR == 0 && hdElmL != 0 ) {
return HdFalse;
}
else if ( hdElmL != hdElmR && EQ( hdElmL, hdElmR ) == HdFalse ) {
return LT( hdElmL, hdElmR );
}
}
return (lenL < lenR) ? HdTrue : HdFalse;
}
TypHandle       SumList ( hdL, hdR )
TypHandle           hdL;
TypHandle           hdR;
{
return (*TabSum[XType(hdL)][XType(hdR)])( hdL, hdR );
}
TypHandle       SumSclList ( hdL, hdR )
TypHandle           hdL;
TypHandle           hdR;
{
TypHandle           hdS;
TypHandle           hdSS;
TypHandle           hdRR;
long                len;
long                i;
EnterKernel();
len = LEN_LIST( hdR );
hdS = NewBag( T_LIST, SIZE_PLEN_PLIST( len ) );
SET_LEN_PLIST( hdS, len );
for ( i = 1; i <= len; i++ ) {
hdRR = ELMR_LIST( hdR, i );
hdSS = SUM( hdL, hdRR );
SET_ELM_PLIST( hdS, i, hdSS );
}
ExitKernel( hdS );
return hdS;
}
TypHandle       SumListScl ( hdL, hdR )
TypHandle           hdL;
TypHandle           hdR;
{
TypHandle           hdS;
TypHandle           hdSS;
TypHandle           hdLL;
long                len;
long                i;
EnterKernel();
len = LEN_LIST( hdL );
hdS = NewBag( T_LIST, SIZE_PLEN_PLIST( len ) );
SET_LEN_PLIST( hdS, len );
for ( i = 1; i <= len; i++ ) {
hdLL = ELML_LIST( hdL, i );
hdSS = SUM( hdLL, hdR );
SET_ELM_PLIST( hdS, i, hdSS );
}
ExitKernel( hdS );
return hdS;
}
TypHandle       SumListList ( hdL, hdR )
TypHandle           hdL;
TypHandle           hdR;
{
TypHandle           hdS;
TypHandle           hdSS;
TypHandle           hdLL;
TypHandle           hdRR;
long                len;
long                i;
EnterKernel();
len = LEN_LIST( hdL );
if ( len != LEN_LIST( hdR ) ) {
return Error(
"Vector +: lists must have the same length",
0L, 0L );
}
hdS = NewBag( T_LIST, SIZE_PLEN_PLIST( len ) );
SET_LEN_PLIST( hdS, len );
for ( i = 1; i <= len; i++ ) {
hdLL = ELML_LIST( hdL, i );
hdRR = ELMR_LIST( hdR, i );
hdSS = SUM( hdLL, hdRR );
SET_ELM_PLIST( hdS, i, hdSS );
}
ExitKernel( hdS );
return hdS;
}
TypHandle       DiffList ( hdL, hdR )
TypHandle           hdL;
TypHandle           hdR;
{
return (*TabDiff[XType(hdL)][XType(hdR)])( hdL, hdR );
}
TypHandle       DiffSclList ( hdL, hdR )
TypHandle           hdL;
TypHandle           hdR;
{
TypHandle           hdD;
TypHandle           hdDD;
TypHandle           hdRR;
long                len;
long                i;
EnterKernel();
len = LEN_LIST( hdR );
hdD = NewBag( T_LIST, SIZE_PLEN_PLIST( len ) );
SET_LEN_PLIST( hdD, len );
for ( i = 1; i <= len; i++ ) {
hdRR = ELMR_LIST( hdR, i );
hdDD = DIFF( hdL, hdRR );
SET_ELM_PLIST( hdD, i, hdDD );
}
ExitKernel( hdD );
return hdD;
}
TypHandle       DiffListScl ( hdL, hdR )
TypHandle           hdL;
TypHandle           hdR;
{
TypHandle           hdD;
TypHandle           hdDD;
TypHandle           hdLL;
long                len;
long                i;
EnterKernel();
len = LEN_LIST( hdL );
hdD = NewBag( T_LIST, SIZE_PLEN_PLIST( len ) );
SET_LEN_PLIST( hdD, len );
for ( i = 1; i <= len; i++ ) {
hdLL = ELML_LIST( hdL, i );
hdDD = DIFF( hdLL, hdR );
SET_ELM_PLIST( hdD, i, hdDD );
}
ExitKernel( hdD );
return hdD;
}
TypHandle       DiffListList ( hdL, hdR )
TypHandle           hdL;
TypHandle           hdR;
{
TypHandle           hdD;
TypHandle           hdDD;
TypHandle           hdLL;
TypHandle           hdRR;
long                len;
long                i;
EnterKernel();
len = LEN_LIST( hdL );
if ( len != LEN_LIST( hdR ) ) {
return Error(
"Vector -: lists must have the same length",
0L, 0L );
}
hdD = NewBag( T_LIST, SIZE_PLEN_PLIST( len ) );
SET_LEN_PLIST( hdD, len );
for ( i = 1; i <= len; i++ ) {
hdLL = ELML_LIST( hdL, i );
hdRR = ELMR_LIST( hdR, i );
hdDD = DIFF( hdLL, hdRR );
SET_ELM_PLIST( hdD, i, hdDD );
}
ExitKernel( hdD );
return hdD;
}
TypHandle       ProdList ( hdL, hdR )
TypHandle           hdL;
TypHandle           hdR;
{
return (*TabProd[XType(hdL)][XType(hdR)])( hdL, hdR );
}
TypHandle       ProdSclList ( hdL, hdR )
TypHandle           hdL;
TypHandle           hdR;
{
TypHandle           hdP;
TypHandle           hdPP;
TypHandle           hdRR;
long                len;
long                i;
EnterKernel();
len = LEN_LIST( hdR );
hdP = NewBag( T_LIST, SIZE_PLEN_PLIST( len ) );
SET_LEN_PLIST( hdP, len );
for ( i = 1; i <= len; i++ ) {
hdRR = ELMR_LIST( hdR, i );
if ( hdRR != 0 ) {
hdPP = PROD( hdL, hdRR );
SET_ELM_PLIST( hdP, i, hdPP );
}
}
ExitKernel( hdP );
return hdP;
}
TypHandle       ProdListScl ( hdL, hdR )
TypHandle           hdL;
TypHandle           hdR;
{
TypHandle           hdP;
TypHandle           hdPP;
TypHandle           hdLL;
long                len;
long                i;
EnterKernel();
len = LEN_LIST( hdL );
hdP = NewBag( T_LIST, SIZE_PLEN_PLIST( len ) );
SET_LEN_PLIST( hdP, len );
for ( i = 1; i <= len; i++ ) {
hdLL = ELML_LIST( hdL, i );
if ( hdLL != 0 ) {
hdPP = PROD( hdLL, hdR );
SET_ELM_PLIST( hdP, i, hdPP );
}
}
ExitKernel( hdP );
return hdP;
}
TypHandle       ProdListList ( hdL, hdR )
TypHandle           hdL;
TypHandle           hdR;
{
TypHandle           hdP;
TypHandle           hdPP;
TypHandle           hdLL;
TypHandle           hdRR;
long                len;
long                i;
EnterKernel();
len = LEN_LIST( hdL );
if ( len != LEN_LIST( hdR ) ) {
return Error(
"Vector *: lists must have the same length",
0L, 0L );
}
hdLL = ELML_LIST( hdL, 1 );
hdRR = ELMR_LIST( hdR, 1 );
hdP  = PROD( hdLL, hdRR );
for ( i = 2; i <= len; i++ ) {
hdLL = ELML_LIST( hdL, i );
hdRR = ELMR_LIST( hdR, i );
hdPP = PROD( hdLL, hdRR );
hdP  = SUM( hdP, hdPP );
}
ExitKernel( hdP );
return hdP;
}
TypHandle       QuoList ( hdL, hdR )
TypHandle           hdL;
TypHandle           hdR;
{
return (*TabQuo[XType(hdL)][XType(hdR)])( hdL, hdR );
}
TypHandle       QuoLists ( hdL, hdR )
TypHandle           hdL;
TypHandle           hdR;
{
return PROD( hdL, POW( hdR, INT_TO_HD(-1) ) );
}
TypHandle       ModList ( hdL, hdR )
TypHandle           hdL;
TypHandle           hdR;
{
return (*TabMod[XType(hdL)][XType(hdR)])( hdL, hdR );
}
TypHandle       ModLists ( hdL, hdR )
TypHandle           hdL;
TypHandle           hdR;
{
return PROD( POW( hdL, INT_TO_HD(-1) ), hdR );
}
TypHandle       PowList ( hdL, hdR )
TypHandle           hdL;
TypHandle           hdR;
{
return (*TabPow[XType(hdL)][XType(hdR)])( hdL, hdR );
}
TypHandle       PowLists ( hdL, hdR )
TypHandle           hdL;
TypHandle           hdR;
{
return PROD( MOD( hdR, hdL ), hdR );
}
TypHandle       CommList ( hdL, hdR )
TypHandle           hdL;
TypHandle           hdR;
{
return (*TabComm[XType(hdL)][XType(hdR)])( hdL, hdR );
}
TypHandle       CommLists ( hdL, hdR )
TypHandle           hdL;
TypHandle           hdR;
{
return PROD( POW( PROD( hdR, hdL ), INT_TO_HD(-1) ), PROD( hdL, hdR ) );
}
TypHandle       EvElmList ( hdSel )
TypHandle           hdSel;
{
TypHandle           hdElm;
TypHandle           hdList;
TypHandle           hdPos;
long                pos;
hdList = EVAL( PTR(hdSel)[0] );
hdPos = EVAL( PTR(hdSel)[1] );
if ( TYPE(hdPos) != T_INT || HD_TO_INT(hdPos) <= 0 ) {
return Error(
"List Element: <position> must be a positive integer",
0L, 0L );
}
pos = HD_TO_INT( hdPos );
if ( TYPE(hdList) == T_LIST ) {
if ( LEN_PLIST( hdList ) < pos ) {
return Error(
"List Element: <list>[%d] must have a value",
pos, 0L );
}
hdElm = ELM_PLIST( hdList, pos );
if ( hdElm == 0 ) {
return Error(
"List Element: <list>[%d] must have a value",
pos, 0L );
}
}
else {
hdElm = ELM_LIST( hdList, pos );
}
return hdElm;
}
TypHandle       ElmListLevel ( hdLists, pos, level )
TypHandle           hdLists;
long                pos;
long                level;
{
long                lenLists;
TypHandle           hdList;
TypHandle           hdElm;
long                i;
if ( level == 1 ) {
lenLists = LEN_LIST( hdLists );
for ( i = 1; i <= lenLists; i++ ) {
hdList = ELMF_LIST( hdLists, i );
hdElm = ELM_LIST( hdList, pos );
SET_ELM_PLIST( hdLists, i, hdElm );
}
}
else {
lenLists = LEN_LIST( hdLists );
for ( i = 1; i <= lenLists; i++ ) {
hdList = ELMF_LIST( hdLists, i );
if ( ! IS_LIST( hdList ) ) {
return Error(
"List Element: <list> must be a list",
0L, 0L );
}
ElmListLevel( hdList, pos, level-1 );
}
}
return hdLists;
}
TypHandle       EvElmListLevel ( hdSel )
TypHandle           hdSel;
{
TypHandle           hdLists;
TypHandle           hdPos;
long                level;
hdLists = EVAL( PTR(hdSel)[0] );
if ( ! IS_LIST( hdLists ) ) {
return Error(
"List Element: <list> must be a list",
0L, 0L );
}
hdPos = EVAL( PTR(hdSel)[1] );
if ( TYPE(hdPos) != T_INT || HD_TO_INT(hdPos) <= 0 ) {
return Error(
"List Element: <position> must be a positive integer",
0L, 0L );
}
level = *(long*)(PTR(hdSel)+2);
return ElmListLevel( hdLists, HD_TO_INT(hdPos), level );
}
TypHandle       EvElmsList ( hdSel )
TypHandle           hdSel;
{
TypHandle           hdList;
TypHandle           hdPoss;
hdList = EVAL( PTR(hdSel)[0] );
hdPoss = EVAL( PTR(hdSel)[1] );
if ( ! IS_POSS_LIST( hdPoss ) ) {
return Error(
"List Elements: <positions> must be a dense list of positive integers",
0L, 0L );
}
return ELMS_LIST( hdList, hdPoss );
}
TypHandle       ElmsListLevel ( hdLists, hdPoss, level )
TypHandle           hdLists;
TypHandle           hdPoss;
long                level;
{
long                lenLists;
TypHandle           hdList;
TypHandle           hdElms;
long                i;
if ( level == 1 ) {
lenLists = LEN_LIST( hdLists );
for ( i = 1; i <= lenLists; i++ ) {
hdList = ELMF_LIST( hdLists, i );
hdElms = ELMS_LIST( hdList, hdPoss );
SET_ELM_PLIST( hdLists, i, hdElms );
}
}
else {
lenLists = LEN_LIST( hdLists );
for ( i = 1; i <= lenLists; i++ ) {
hdList = ELMF_LIST( hdLists, i );
if ( ! IS_LIST( hdList ) ) {
return Error(
"List Elements: <list> must be a list",
0L, 0L );
}
ElmsListLevel( hdList, hdPoss, level-1 );
}
}
return hdLists;
}
TypHandle       EvElmsListLevel ( hdSel )
TypHandle           hdSel;
{
TypHandle           hdLists;
TypHandle           hdPoss;
long                level;
hdLists = EVAL( PTR(hdSel)[0] );
if ( ! IS_LIST( hdLists ) ) {
return Error(
"List Elements: <list> must be a list",
0L, 0L );
}
hdPoss = EVAL( PTR(hdSel)[1] );
if ( ! IS_POSS_LIST( hdPoss ) ) {
return Error(
"List Elements: <positions> must be a dense list of positive integers",
0L, 0L );
}
level = *(long*)(PTR(hdSel)+2);
return ElmsListLevel( hdLists, hdPoss, level );
}
TypHandle       EvAssList ( hdAss )
TypHandle           hdAss;
{
TypHandle           hdList;
long                plen;
TypHandle           hdPos;
long                pos;
TypHandle           hdVal;
hdList = EVAL( PTR( PTR(hdAss)[0] )[0] );
hdPos = EVAL( PTR( PTR(hdAss)[0] )[1] );
if ( TYPE(hdPos) != T_INT || HD_TO_INT(hdPos) <= 0 ) {
return Error(
"List Element: <position> must be a positive integer",
0L, 0L );
}
pos = HD_TO_INT(hdPos);
hdVal = EVAL( PTR(hdAss)[1] );
if ( hdVal == HdVoid ) {
return Error(
"List Assignment: function must return a value",
0L, 0L );
}
if ( TYPE(hdList) == T_LIST ) {
if ( LEN_PLIST( hdList ) < pos ) {
plen = PLEN_SIZE_PLIST( SIZE( hdList ) );
if ( plen + plen/8 + 4 < pos )
Resize( hdList, SIZE_PLEN_PLIST( pos ) );
else if ( plen < pos )
Resize( hdList, SIZE_PLEN_PLIST( plen + plen/8 + 4 ) );
SET_LEN_PLIST( hdList, pos );
}
SET_ELM_PLIST( hdList, pos, hdVal );
}
else {
hdVal = ASS_LIST( hdList, HD_TO_INT(hdPos), hdVal );
}
return hdVal;
}
TypHandle       AssListLevel ( hdLists, pos, hdVals, level )
TypHandle           hdLists;
long                pos;
TypHandle           hdVals;
long                level;
{
TypHandle           hdList;
TypHandle           hdVal;
long                lenLists;
long                i;
if ( level == 1 ) {
lenLists = LEN_LIST( hdLists );
for ( i = 1; i <= lenLists; i++ ) {
hdList = ELMF_LIST( hdLists, i );
hdVal = ELMF_LIST( hdVals, i );
if ( hdVal == 0 ) {
return Error(
"List Assignment: <vals> must be a dense list",
0L, 0L );
}
ASS_LIST( hdList, pos, hdVal );
}
}
else {
lenLists = LEN_LIST( hdLists );
for ( i = 1; i <= lenLists; i++ ) {
hdList = ELMF_LIST( hdLists, i );
if ( ! IS_LIST( hdList ) ) {
return Error(
"List Assignment: <list> must be a list",
0L, 0L );
}
hdVal = ELMF_LIST( hdVals, i );
if ( hdVal == 0 ) {
return Error(
"List Assignment: <vals> must be a dense list",
0L, 0L );
}
if ( ! IS_LIST( hdVal ) ) {
return Error(
"List Assignment: <vals> must be a dense list",
i, 0L );
}
if ( LEN_LIST( hdList ) != LEN_LIST( hdVal ) ) {
return Error(
"List Assignment: <list> and <vals> must have the same length",
0L, 0L );
}
AssListLevel( hdList, pos, hdVal, level-1 );
}
}
return hdVals;
}
TypHandle       EvAssListLevel ( hdAss )
TypHandle           hdAss;
{
TypHandle           hdLists;
TypHandle           hdPos;
TypHandle           hdVals;
long                level;
hdLists = EVAL( PTR( PTR(hdAss)[0] )[0] );
if ( ! IS_LIST( hdLists ) ) {
return Error(
"List Assignment: <list> must be a list",
0L, 0L );
}
hdPos = EVAL( PTR( PTR(hdAss)[0] )[1] );
if ( TYPE(hdPos) != T_INT || HD_TO_INT(hdPos) <= 0 ) {
return Error(
"List Assignment: <position> must be a positive integer",
0L, 0L );
}
hdVals = EVAL( PTR(hdAss)[1] );
if ( hdVals == HdVoid ) {
return Error(
"List Assignment: function must return a value",
0L, 0L );
}
level = *(long*)(PTR(PTR(hdAss)[0])+2);
return AssListLevel( hdLists, HD_TO_INT(hdPos), hdVals, level );
}
TypHandle       EvAsssList ( hdAss )
TypHandle           hdAss;
{
TypHandle           hdList;
TypHandle           hdPoss;
TypHandle           hdVals;
hdList = EVAL( PTR( PTR(hdAss)[0] )[0] );
hdPoss = EVAL( PTR( PTR(hdAss)[0] )[1] );
if ( ! IS_POSS_LIST( hdPoss ) ) {
return Error(
"List Assignments: <positions> must be a dense list of positive integers",
0L, 0L );
}
hdVals = EVAL( PTR(hdAss)[1] );
if ( ! IS_DENSE_LIST( hdVals ) ) {
return Error(
"List Assignments: <vals> must be a dense list",
0L, 0L );
}
if ( LEN_LIST( hdVals ) != LEN_LIST( hdPoss ) ) {
return Error(
"List Assiments: <positions> and <vals> must have the same length",
0L, 0L );
}
return ASSS_LIST( hdList, hdPoss, hdVals );
}
TypHandle       AsssListLevel ( hdLists, hdPoss, hdVals, lev )
TypHandle           hdLists;
TypHandle           hdPoss;
TypHandle           hdVals;
long                lev;
{
long                lenLists;
long                lenPoss;
TypHandle           hdList;
TypHandle           hdVal;
long                i;
if ( lev == 1 ) {
lenPoss = LEN_LIST( hdPoss );
lenLists = LEN_LIST( hdLists );
for ( i = 1; i <= lenLists; i++ ) {
hdList = ELMF_LIST( hdLists, i );
hdVal = ELMF_LIST( hdVals, i );
if ( hdVal == 0 ) {
return Error(
"List Assignments: <vals> must be a dense list",
0L, 0L );
}
if ( ! IS_DENSE_LIST( hdVal ) ) {
return Error(
"List Assignments: <vals> must be a dense list",
0L, 0L );
}
if ( LEN_LIST( hdVal ) != lenPoss ) {
return Error(
"List Assigments: <positions> and <vals> must have the same lenght",
0L, 0L );
}
ASSS_LIST( hdList, hdPoss, hdVal );
}
}
else {
lenLists = LEN_LIST( hdLists );
for ( i = 1; i <= lenLists; i++ ) {
hdList = ELMF_LIST( hdLists, i );
if ( ! IS_LIST( hdList ) ) {
return Error(
"List Assignments: <list> must be a list",
0L, 0L );
}
hdVal = ELMF_LIST( hdVals, i );
if ( hdVal == 0 ) {
return Error(
"List Assignments: <vals> must be a dense list",
0L, 0L );
}
if ( ! IS_LIST( hdVal ) ) {
return Error(
"List Assignments: <vals> must be a dense list",
0L, 0L );
}
if ( LEN_LIST( hdVal ) != LEN_LIST( hdList ) ) {
return Error(
"List Assignments: <list> and <vals> must have the same length",
0L, 0L );
}
AsssListLevel( hdList, hdPoss, hdVal, lev-1 );
}
}
return hdVals;
}
TypHandle       EvAsssListLevel ( hdAss )
TypHandle           hdAss;
{
TypHandle           hdLists;
TypHandle           hdPoss;
TypHandle           hdVals;
long                level;
hdLists = EVAL( PTR( PTR(hdAss)[0] )[0] );
if ( ! IS_LIST( hdLists ) ) {
return Error(
"List Assignments: <list> must be a list",
0L, 0L );
}
hdPoss = EVAL( PTR( PTR(hdAss)[0] )[1] );
if ( ! IS_POSS_LIST( hdPoss ) ) {
return Error(
"List Assignments: <positions> must be a dense list of positive integers",
0L, 0L );
}
hdVals = EVAL( PTR(hdAss)[1] );
if ( hdVals == HdVoid ) {
return Error(
"List Assignments: function must return a value",
0L, 0L );
}
if ( ! IS_LIST( hdVals ) ) {
return Error(
"List Assignments: <vals> must be a list",
0L, 0L );
}
if ( LEN_LIST( hdVals ) != LEN_LIST( hdLists ) ) {
return Error(
"List Assignments: <lists> and <vals> must have the same length",
0L, 0L );
}
level = *(long*)(PTR(PTR(hdAss)[0])+2);
return AsssListLevel( hdLists, hdPoss, hdVals, level );
}
void            PrElmList ( hdSel )
TypHandle           hdSel;
{
Pr("%2>",0L,0L);  Print( PTR(hdSel)[0] );
Pr("%<[",0L,0L);  Print( PTR(hdSel)[1] );
Pr("%<]",0L,0L);
}
void            PrElmsList ( hdSel )
TypHandle           hdSel;
{
Pr("%2>",0L,0L);  Print( PTR(hdSel)[0] );
Pr("%<{",0L,0L);  Print( PTR(hdSel)[1] );
Pr("%<}",0L,0L);
}
void            PrAssList ( hdAss )
TypHandle           hdAss;
{
Pr("%2>",0L,0L);       Print( PTR(hdAss)[0] );
Pr("%< %>:= ",0L,0L);  Print( PTR(hdAss)[1] );
Pr("%2<",0L,0L);
}

/* 当前文件是D:\Read\coding.c*/

/* 当前文件是D:\Read\vecffe.h*/

#ifdef SPEC_CPU2000_P64
#define long __int64
#endif
#define PLEN_SIZE_VECFFE(SIZE)          (((SIZE) - SIZE_HD) / sizeof(TypFFE))
#define SIZE_PLEN_VECFFE(PLEN)          (SIZE_HD + (PLEN) * sizeof(TypFFE))
#define LEN_VECFFE(LIST)                PLEN_SIZE_VECFFE( SIZE( LIST ) )
#define SET_LEN_VECFFE(LIST,LEN)        Resize( LIST, SIZE_PLEN_VECFFE(LEN) )
#define FLD_VECFFE(LIST)                (PTR(LIST)[0])
#define SET_FLD_VECFFE(LIST,FLD)        (FLD_VECFFE(LIST) = (FLD))
#define VAL_VECFFE(VEC,POS)             (((TypFFE*)(PTR(VEC)+1))[(POS)-1])
#define SET_VAL_VECFFE(VEC,POS,VAL)     (VAL_VECFFE(VEC,POS) = (VAL))
#define ELM_VECFFE(LIST,POS,ELM)      (SET_FLD_FFE(ELM,FLD_VECFFE(LIST)), \
SET_VAL_FFE(ELM,VAL_VECFFE(LIST,POS)))
#define SET_ELM_VECFFE(LIST,POS,ELM)    SET_VAL_VECFFE(LIST,POS,VAL_FFE(ELM))

/* 当前文件是D:\Read\coding.h*/

#ifdef SPEC_CPU2000_P64
#define long __int64
#endif

unsigned long   RootPrimePower ( q )
long                q;
{
unsigned long       p;
if ( q < 2 )  return 0;
if ( q % 2 == 0 )  p = 2;
else for ( p = 3; q % p != 0; p += 2 ) ;
while ( q % p == 0 )  q /= p;
if ( q != 1 )  return 0;
return p;
}
unsigned long   ConvMatFFE ( mat, q )
TypHandle           mat;
unsigned long       q;
{
unsigned long       i;
if ( ! IsXTypeMatFFE(mat) )
return 0;
for ( i = 1; i <= LEN_LIST(mat); i++ )
if ( ! ConvVecFFE( ELM_LIST( mat, i ), q ) )
return 0;
return 1;
}
TypHandle       RootFiniteField ( q )
unsigned long       q;
{
TypHandle           hdZ;
TypHandle           hdFF;
TypFFE              * ff;
TypHandle           hdInd;
TypFFE              * ind;
unsigned long       p;
unsigned long       poly;
unsigned long       i, l, f, n, e;
if ( q <= 1 || 65536 < q )
return 0;
for ( i = 0;  i < SIZE(HdFields)/SIZE_HD;  ++i ) {
if ( ORD_FF( PTR(HdFields)[i] ) == q )
return PTR(HdFields)[i];
}
if ( q % 2 == 0 )  p = 2;
else for ( p = 3; q % p != 0; p += 2 ) ;
i = q;
while ( i % p == 0 )  { i = i / p; }
if ( i != 1 )
return 0;
hdFF  = NewBag( T_FF, q * sizeof(TypFFE) );
hdInd = NewBag( T_FF, q * sizeof(TypFFE) );
ff    = SUCC_FF( hdFF );
ind   = SUCC_FF( hdInd );
if ( q == p ) {
for ( e = 1, i = 1; i != p-1; ++e ) {
for ( f = e, i = 1; f != 1; ++i )
f = (f * e) % p;
}
poly = p-(e-1);
}
else {
for ( i = 0; Pols[i] != q; i += 2 ) ;
poly = Pols[i+1];
}
ind[ 0 ] = 0;
for ( e = 1, n = 0; n < q-1; ++n ) {
ind[ e ] = n + 1;
if ( p != 2 ) {
f = p * (e % (q/p));  l = ((p-1) * (e / (q/p))) % p;  e = 0;
for ( i = 1; i < q; i *= p )
e = e + i * ((f/i + l * (poly/i)) % p);
}
else {
if ( 2*e & q )  e = 2*e ^ poly ^ q;
else            e = 2*e;
}
}
ff[ 0 ] = q-1;
for ( e = 1, f = p-1; e < q; ++e ) {
if ( e < f ) {
ff[ ind[e] ] = ind[ e+1 ];
}
else {
ff[ ind[e] ] = ind[ e+1-p ];
f += p;
}
}
hdZ = NewBag( T_FFE, SIZE_HD + sizeof(TypFFE) );
SET_FLD_FFE( hdZ, hdFF );
if ( q == 2 ) SET_VAL_FFE(hdZ,1);
else          SET_VAL_FFE(hdZ,2);
Resize( HdFields, SIZE(HdFields) + SIZE_HD );
PTR(HdFields)[ SIZE(HdFields)/SIZE_HD - 1 ] = hdZ;
return hdZ;
}
unsigned long   ConvVecFFE ( vec, q )
TypHandle           vec;
unsigned long       q;
{
unsigned long       p;
unsigned long       d;
unsigned long       q1;
TypFFE *            v;
TypFFE              t;
unsigned long       i;
if ( ! IsXTypeVecFFE(vec) )
return 0;
if ( SIZE_FF( FLD_VECFFE(vec) ) == q )
return 1;
p = CharVecFFE(vec);
d = DegreeVecFFE(vec);
q1 = 1;
for ( i = 1; i <= d; i++ )
q1 *= p;
if ( q % p != 0 || (q-1) % (q1-1) != 0 )
return 0;
q1 = SIZE_FF( FLD_VECFFE(vec) );
SET_FLD_VECFFE( vec, FLD_FFE( RootFiniteField( q ) ) );
v = (TypFFE*)(PTR(vec) + 1);
for ( i = 1; i <= LEN_VECFFE(vec); i++, v++ ) {
t = *v;
if ( t != 0 )
*v = (t-1) * (q-1) / (q1-1) + 1;
}
return 1;
}
TypHandle       BlistsMatFF2 ( mat )
TypHandle           mat;
{
TypHandle           mat2;
TypHandle           row2;
unsigned long       i;
mat2 = NewBag( T_LIST, SIZE_PLEN_PLIST( LEN_LIST( mat ) ) );
SET_LEN_PLIST( mat2, LEN_LIST( mat ) );
for ( i = 1; i <= LEN_LIST( mat ); i++ ) {
row2 = BlistVecFF2( ELM_LIST( mat, i ) );
SET_ELM_PLIST( mat2, i, row2 );
}
return mat2;
}
TypHandle       BlistVecFF2 ( vec )
TypHandle           vec;
{
TypHandle           vec2;
unsigned long       len;
TypFFE *            v;
unsigned long *     v2;
unsigned long       blk;
unsigned long       bit;
unsigned long       i;
len = LEN_VECFFE(vec);
vec2 = NewBag( T_BLIST, SIZE_PLEN_BLIST( len ) );
SET_LEN_BLIST( vec2, len );
v = (TypFFE*)(PTR(vec) + 1);
v2 = (unsigned long *)(PTR(vec2) + 1);
blk = 0;
bit = 1;
for ( i = 1; i <= len; i++, v++ ) {
if ( *v != 0 )
blk |= bit;
bit <<= 1;
if ( bit == 0 || i == len ) {
*v2++ = blk;
blk = 0;
bit = 1;
}
}
return vec2;
}
TypHandle       VecFF2Blist ( vec )
TypHandle           vec;
{
TypHandle           vec2;
unsigned long       len;
TypFFE *            v2;
unsigned long       i;
len = LEN_BLIST( vec );
vec2 = NewBag( T_VECFFE, SIZE_PLEN_VECFFE( len ) );
SET_FLD_FFE( vec2, FLD_FFE( RootFiniteField( 2 ) ) );
v2 = (TypFFE*)(PTR(vec2) + 1);
for ( i = 1; i <= len; i++, v2++ ) {
if ( ELM_BLIST( vec, i ) == HdTrue )
*v2 = 1;
}
return vec2;
}
unsigned long   WeightVecFFE ( vec )
TypHandle           vec;
{
unsigned long       n;
TypFFE *            v;
unsigned long       i;
n = 0;
v = (TypFFE*)(PTR(vec) + 1);
for ( i = 1; i <= LEN_VECFFE( vec ); i++, v++ )
n += (*v != 0);
return n;
}
TypHandle       DistanceVecFFE ( vec1, vec2 )
TypHandle           vec1;
TypHandle           vec2;
{
unsigned long       n;
unsigned long       p;
unsigned long       d;
unsigned long       q;
unsigned long       d1;
unsigned long       d2;
TypFFE *            v1;
TypFFE *            v2;
unsigned long       k;
if ( ! IsXTypeVecFFE(vec1) )
return Error("DistancesVecFFE: %s",
(long)"<vec1> must be a finite field vector",0L);
if ( ! IsXTypeVecFFE(vec2) )
return Error("DistancesVecFFE: %s",
(long)"<vec2> must be a finite field vector",0L);
if ( LEN_VECFFE(vec1) != LEN_VECFFE(vec2) )
return Error("DistancesVecFFE: %s",
(long)"<vec1> and <vec2> must have the same length",0L);
if ( FLD_VECFFE(vec1) != FLD_VECFFE(vec2) ) {
p = CharVecFFE( vec1 );
if ( SIZE_FF( FLD_VECFFE(vec2) ) % p != 0 )
return Error("DistancesVecFFE: %s",
(long)"<vec1> and <vec2> must lie in a common field",0L);
d1 = DegreeVecFFE( vec1 );
d2 = DegreeVecFFE( vec2 );
for ( d = 1, q = p; d % d1 != 0 || d % d2 != 0; d++ )  q *= p;
if ( (  2 <= p && 17 <= d) || (  3 <= p && 11 <= d)
|| (  5 <= p &&  7 <= d) || (  7 <= p &&  6 <= d)
|| ( 11 <= p &&  5 <= d) || ( 17 <= p &&  4 <= d)
|| ( 41 <= p &&  3 <= d) || (257 <= p &&  2 <= d) )
return Error("DistancesVecFFE: %s",
(long)"<vec1> and <vec2> must lie in a common field",0L);
ConvVecFFE( vec1, q );
ConvVecFFE( vec2, q );
}
n = 0;
v1 = (TypFFE*)(PTR(vec1) + 1);
v2 = (TypFFE*)(PTR(vec2) + 1);
for ( k = 1; k <= LEN_VECFFE(vec1); k++, v1++, v2++ )
n += (*v1 != *v2);
return INT_TO_HD(n);
}
TypHandle       FunDistanceVecFFE ( hdCall )
TypHandle           hdCall;
{
if ( SIZE(hdCall) != 3*SIZE_HD )
return Error("number of arguments must be 2 not %d",
(long)(SIZE(hdCall)/SIZE_HD - 1), 0L );
return DistanceVecFFE(
EVAL( PTR(hdCall)[1] ), EVAL( PTR(hdCall)[2] ) );
}
TypHandle       DistancesDistributionVecFFEsVecFFE ( vecs, vec )
TypHandle           vecs;
TypHandle           vec;
{
TypHandle           dst;
unsigned long       n;
unsigned long       p;
unsigned long       d;
unsigned long       q;
unsigned long       d1;
unsigned long       d2;
TypFFE *            v1;
TypFFE *            v2;
TypHandle           cnt;
unsigned long       i, k;
if ( ! IsXTypeMatFFE(vecs) )
return Error("DistancesDistributionVecFFEsVecFFE: %s",
(long)"<vecs> must be a finite field matrix",0L);
if ( ! IsXTypeVecFFE(vec) )
return Error("DistancesDistributionVecFFEsVecFFE: %s",
(long)"<vec> must be a finite field vector",0L);
if ( LEN_VECFFE( ELM_LIST(vecs,1) ) != LEN_VECFFE(vec) )
return Error("DistancesDistributionVecFFEsVecFFE: %s",
(long)"<vecs>[1] and <vec> must have the same length",0L);
if ( FLD_VECFFE( ELM_LIST(vecs,1) ) != FLD_VECFFE(vec) ) {
p = CharVecFFE( ELM_LIST(vecs,1) );
if ( SIZE_FF( FLD_VECFFE(vec) ) % p != 0 )
return Error("DistancesDistributionVecFFEsVecFFE: %s",
(long)"<vecs> and <vec> must lie in a common field",0L);
d1 = DegreeMatFFE( vecs );
d2 = DegreeVecFFE( vec );
for ( d = 1, q = p; d % d1 != 0 || d % d2 != 0; d++ )  q *= p;
if ( (  2 <= p && 17 <= d) || (  3 <= p && 11 <= d)
|| (  5 <= p &&  7 <= d) || (  7 <= p &&  6 <= d)
|| ( 11 <= p &&  5 <= d) || ( 17 <= p &&  4 <= d)
|| ( 41 <= p &&  3 <= d) || (257 <= p &&  2 <= d) )
return Error("DistancesDistributionVecFFEsVecFFE: %s",
(long)"<vecs> and <vec> must lie in a common field",0L);
ConvMatFFE( vecs, q );
ConvVecFFE( vec, q );
}
dst = NewBag( T_LIST, SIZE_PLEN_PLIST( LEN_VECFFE(vec) + 1 ) );
SET_LEN_PLIST( dst, LEN_VECFFE(vec) + 1 );
for ( i = 1; i <= LEN_VECFFE(vec) + 1; i++ )
SET_ELM_PLIST( dst, i, INT_TO_HD(0) );
for ( i = 1; i <= LEN_LIST(vecs); i++ ) {
n = 0;
v1 = (TypFFE*)(PTR( ELM_LIST(vecs,i) ) + 1);
v2 = (TypFFE*)(PTR(vec) + 1);
for ( k = 1; k <= LEN_VECFFE(vec); k++, v1++, v2++ )
n += (*v1 != *v2);
cnt = ELM_PLIST( dst, n+1 );
cnt = (TypHandle)((long)cnt + (long)INT_TO_HD(1) - T_INT);
SET_ELM_PLIST( dst, n+1, cnt );
}
return dst;
}
TypHandle       FunDistancesDistributionVecFFEsVecFFE ( hdCall )
TypHandle           hdCall;
{
if ( SIZE(hdCall) != 3*SIZE_HD )
return Error("number of arguments must be 2 not %d",
(long)(SIZE(hdCall)/SIZE_HD - 1), 0L );
return DistancesDistributionVecFFEsVecFFE(
EVAL( PTR(hdCall)[1] ), EVAL( PTR(hdCall)[2] ) );
}
void            DDM2V2 ( mat, vec, sum, l, dst )
TypHandle           mat;
TypHandle           vec;
TypHandle           sum;
unsigned long       l;
TypHandle           dst;
{
unsigned long       nrb;
unsigned long *     r;
unsigned long *     s;
unsigned long *     v;
unsigned long       n;
unsigned long       b;
TypHandle           cnt;
unsigned long       k;
nrb = (LEN_BLIST(vec) + BIPEB-1) / BIPEB;
if ( l == LEN_LIST(mat)-1 ) {
n = 0;
s = (unsigned long *)(PTR( sum ) + 1);
v = (unsigned long *)(PTR( vec ) + 1);
for ( k = 1; k <= nrb; k++, s++, v++ ) {
b = *s ^ *v;
b = (b & 0x55555555) + ((b >> 1) & 0x55555555);
b = (b & 0x33333333) + ((b >> 2) & 0x33333333);
b = (b + (b >>  4)) & 0x0f0f0f0f;
b = (b + (b >>  8));
b = (b + (b >> 16)) & 0x000000ff;
n += b;
}
cnt = ELM_PLIST( dst, n+1 );
cnt = (TypHandle)((long)cnt + (long)INT_TO_HD(1) - T_INT);
if ( ((long)cnt & 3) != T_INT
|| (((long)cnt << 1) >> 1) != (long)cnt )
cnt = SumInt( cnt, INT_TO_HD(1) );
SET_ELM_PLIST( dst, n+1, cnt );
n = 0;
r = (unsigned long *)(PTR( ELM_LIST( mat, l+1 ) ) + 1);
s = (unsigned long *)(PTR( sum ) + 1);
v = (unsigned long *)(PTR( vec ) + 1);
for ( k = 1; k <= nrb; k++, r++, s++, v++ ) {
b = (*r ^ *s) ^ *v;
b = (b & 0x55555555) + ((b >> 1) & 0x55555555);
b = (b & 0x33333333) + ((b >> 2) & 0x33333333);
b = (b + (b >>  4)) & 0x0f0f0f0f;
b = (b + (b >>  8));
b = (b + (b >> 16)) & 0x000000ff;
n += b;
}
cnt = ELM_PLIST( dst, n+1 );
cnt = (TypHandle)((long)cnt + (long)INT_TO_HD(1) - T_INT);
if ( ((long)cnt & 3) != T_INT
|| (((long)cnt << 1) >> 1) != (long)cnt )
cnt = SumInt( cnt, INT_TO_HD(1) );
SET_ELM_PLIST( dst, n+1, cnt );
}
else {
DDM2V2( mat, vec, sum, l+1, dst );
r = (unsigned long *)(PTR( ELM_LIST( mat, l+1 ) ) + 1);
s = (unsigned long *)(PTR( sum ) + 1);
for ( k = 1; k <= nrb; k++, r++, s++ )
*s ^= *r;
DDM2V2( mat, vec, sum, l+1, dst );
r = (unsigned long *)(PTR( ELM_LIST( mat, l+1 ) ) + 1);
s = (unsigned long *)(PTR( sum ) + 1);
for ( k = 1; k <= nrb; k++, r++, s++ )
*s ^= *r;
}
}
void            DDMFVF ( mat, q, vec, sum, l, lim, dst )
TypHandle           mat;
unsigned long       q;
TypHandle           vec;
TypHandle           sum;
unsigned long       l;
unsigned long       lim;
TypHandle           dst;
{
TypHandle           cnt;
unsigned long       len;
TypFFE *            fld;
TypFFE *            r;
TypFFE *            s;
TypFFE *            v;
TypFFE              z;
unsigned long       n;
TypFFE              t;
unsigned long       k;
len = LEN_VECFFE(vec);
fld = SUCC_FF( FLD_VECFFE(vec) );
if ( l == LEN_LIST(mat)-1 ) {
n = 0;
s = (TypFFE*)(PTR( sum ) + 1);
v = (TypFFE*)(PTR( vec ) + 1);
for ( k = 1; k <= len; k++, s++, v++ ) {
n += (*s != *v);
}
cnt = ELM_LIST( dst, n+1 );
cnt = (TypHandle)((long)cnt + (long)INT_TO_HD(1) - T_INT);
if ( ((long)cnt & 3) != T_INT
|| (((long)cnt << 1) >> 1) != (long)cnt )
cnt = SumInt( cnt, INT_TO_HD(1) );
SET_ELM_PLIST( dst, n+1, cnt );
for ( z = 1; z <= lim; z++ ) {
n = 0;
r = (TypFFE*)(PTR( ELM_LIST( mat, l+1 ) ) + 1);
s = (TypFFE*)(PTR( sum ) + 1);
v = (TypFFE*)(PTR( vec ) + 1);
for ( k = 1; k <= len; k++, r++, s++, v++ ) {
t = PROD_FF( z, *r, fld );
n += (SUM_FF( *s, t, fld ) != *v);
}
cnt = ELM_LIST( dst, n+1 );
cnt = (TypHandle)((long)cnt + (long)INT_TO_HD(1) - T_INT);
if ( ((long)cnt & 3) != T_INT
|| (((long)cnt << 1) >> 1) != (long)cnt )
cnt = SumInt( cnt, INT_TO_HD(1) );
SET_ELM_PLIST( dst, n+1, cnt );
}
}
else {
DDMFVF( mat, q, vec, sum, l+1, lim, dst );
for ( z = 1; z <= lim; z++ ) {
r = (TypFFE*)(PTR( ELM_LIST( mat, l+1 ) ) + 1);
s = (TypFFE*)(PTR( sum ) + 1);
for ( k = 1; k <= len; k++, r++, s++ ) {
t = PROD_FF( z, *r, fld );
*s = SUM_FF( *s, t, fld );
}
DDMFVF( mat, q, vec, sum, l+1, q-1, dst );
z = NEG_FF( z, fld );
r = (TypFFE*)(PTR( ELM_LIST( mat, l+1 ) ) + 1);
s = (TypFFE*)(PTR( sum ) + 1);
for ( k = 1; k <= len; k++, r++, s++ ) {
t = PROD_FF( z, *r, fld );
*s = SUM_FF( *s, t, fld );
}
z = NEG_FF( z, fld );
}
}
}
TypHandle       DistancesDistributionMatFFEVecFFE ( mat, q, vec )
TypHandle           mat;
TypHandle           q;
TypHandle           vec;
{
TypHandle           dst;
unsigned long       p;
TypHandle           sum;
unsigned long       i;
if ( TYPE(q) != T_INT || ! (p = RootPrimePower( HD_TO_INT(q) )) )
return Error("DistancesDistributionMatFFEVecFFE: %s",
(long)"<q> must be a positive prime power",0L);
if ( ! ConvMatFFE( mat, HD_TO_INT(q) ) )
return Error("DistancesDistributionMatFFEVecFFE: %s",
(long)"<mat> must be a matrix over GF(<q>)",0L);
if ( ! ConvVecFFE( vec, HD_TO_INT(q) ) )
return Error("DistancesDistributionMatFFEVecFFE: %s",
(long)"<vec> must be a vector over GF(<q>)",0L);
if ( LEN_VECFFE( ELM_LIST(mat,1) ) != LEN_VECFFE(vec) )
return Error("DistancesDistributionMatFFEVecFFE: %s",
(long)"<mat>[<1>] and <vec> must have the same length",0L);
dst = NewBag( T_LIST, SIZE_PLEN_PLIST( LEN_VECFFE(vec) + 1 ) );
SET_LEN_PLIST( dst, LEN_VECFFE(vec) + 1 );
for ( i = 1; i <= LEN_VECFFE(vec) + 1; i++ )
SET_ELM_PLIST( dst, i, INT_TO_HD(0) );
if ( HD_TO_INT(q) == 2 ) {
sum = NewBag( T_BLIST, SIZE_PLEN_BLIST( LEN_VECFFE(vec) ) );
SET_LEN_BLIST( sum, LEN_VECFFE(vec) );
DDM2V2( BlistsMatFF2(mat), BlistVecFF2(vec), sum, 0, dst );
}
else if ( WeightVecFFE( vec ) == 0 ) {
sum = NewBag( T_VECFFE, SIZE_PLEN_VECFFE( LEN_VECFFE(vec) ) );
SET_FLD_VECFFE( sum, FLD_VECFFE(vec) );
DDMFVF( mat, HD_TO_INT(q), vec, sum, 0, 1, dst );
dst = PROD( dst, INT_TO_HD( HD_TO_INT(q) - 1 ) );
ASS_LIST( dst, 1, INT_TO_HD(1) );
}
else {
sum = NewBag( T_VECFFE, SIZE_PLEN_VECFFE( LEN_VECFFE(vec) ) );
SET_FLD_VECFFE( sum, FLD_VECFFE(vec) );
DDMFVF( mat, HD_TO_INT(q), vec, sum, 0, HD_TO_INT(q)-1, dst );
}
return dst;
}
TypHandle       FunDistancesDistributionMatFFEVecFFE ( hdCall )
TypHandle           hdCall;
{
if ( SIZE(hdCall) != 4*SIZE_HD )
return Error("number of arguments must be 3 not %d",
(long)(SIZE(hdCall)/SIZE_HD - 1), 0L );
return DistancesDistributionMatFFEVecFFE(
EVAL( PTR(hdCall)[1] ), EVAL( PTR(hdCall)[2] ),
EVAL( PTR(hdCall)[3] ) );
}
void            CVCM2V2 ( mat, vec, l, stop, sum, i, pmin, best )
TypHandle           mat;
TypHandle           vec;
unsigned long       l;
unsigned long       stop;
TypHandle           sum;
unsigned long       i;
unsigned long *     pmin;
TypHandle           best;
{
unsigned long       nrb;
unsigned long *     r;
unsigned long *     s;
unsigned long *     v;
unsigned long       n;
unsigned long       b;
unsigned long       j, k;
nrb = (LEN_BLIST(vec) + BIPEB-1) / BIPEB;
if ( l == 1 ) {
for ( j = i+1; j <= LEN_LIST(mat); j++ ) {
n = 0;
r = (unsigned long *)(PTR( ELM_LIST( mat, j ) ) + 1);
s = (unsigned long *)(PTR( sum ) + 1);
v = (unsigned long *)(PTR( vec ) + 1);
for ( k = 1; k <= nrb; k++, r++, s++, v++ ) {
b = (*r ^ *s) ^ *v;
b = (b & 0x55555555) + ((b >> 1) & 0x55555555);
b = (b & 0x33333333) + ((b >> 2) & 0x33333333);
b = (b + (b >>  4)) & 0x0f0f0f0f;
b = (b + (b >>  8));
b = (b + (b >> 16)) & 0x000000ff;
n += b;
}
if ( n < *pmin ) {
r = (unsigned long *)(PTR( ELM_LIST( mat, j ) ) + 1);
s = (unsigned long *)(PTR( sum ) + 1);
v = (unsigned long *)(PTR( best ) + 1);
for ( k = 1; k <= nrb; k++, r++, s++, v++ )
*v = *r ^ *s;
*pmin = n;
}
if ( *pmin <= stop )  return;
}
}
else {
for ( j = i+1; j+(l-1) <= LEN_LIST(mat); j++ ) {
r = (unsigned long *)(PTR( ELM_LIST( mat, j ) ) + 1);
s = (unsigned long *)(PTR( sum ) + 1);
for ( k = 1; k <= nrb; k++, r++, s++ )
*s ^= *r;
CVCM2V2( mat, vec, l-1, stop, sum, j, pmin, best );
if ( *pmin <= stop )  return;
r = (unsigned long *)(PTR( ELM_LIST( mat, j ) ) + 1);
s = (unsigned long *)(PTR( sum ) + 1);
for ( k = 1; k <= nrb; k++, r++, s++ )
*s ^= *r;
}
}
}
void            CVCMFVF ( mat, q, vec, l, stop, sum, i, lim, pmin, best )
TypHandle           mat;
unsigned long       q;
TypHandle           vec;
unsigned long       l;
unsigned long       stop;
TypHandle           sum;
unsigned long       i;
unsigned long       lim;
unsigned long *     pmin;
TypHandle           best;
{
unsigned long       len;
TypFFE *            fld;
TypFFE *            r;
TypFFE *            s;
TypFFE *            v;
unsigned long       n;
TypFFE              z;
TypFFE              t;
unsigned long       j, k;
len = LEN_VECFFE(vec);
fld = SUCC_FF( FLD_VECFFE(vec) );
if ( l == 1 ) {
for ( j = i+1; j <= LEN_LIST(mat); j++ ) {
for ( z = 1; z <= lim; z++ ) {
n = 0;
r = (TypFFE*)(PTR( ELM_LIST( mat, j ) ) + 1);
s = (TypFFE*)(PTR( sum ) + 1);
v = (TypFFE*)(PTR( vec ) + 1);
for ( k = 1; k <= len; k++, r++, s++, v++ ) {
t = PROD_FF( z, *r, fld );
n += (SUM_FF( *s, t, fld ) != *v);
}
if ( n < *pmin ) {
r = (TypFFE*)(PTR( ELM_LIST( mat, j ) ) + 1);
s = (TypFFE*)(PTR( sum ) + 1);
v = (TypFFE*)(PTR( best ) + 1);
for ( k = 1; k <= len; k++, r++, s++, v++ ) {
t = PROD_FF( z, *r, fld );
*v = SUM_FF( *s, t, fld );
}
*pmin = n;
}
if ( *pmin <= stop )  return;
}
}
}
else {
for ( j = i+1; j+(l-1) <= LEN_LIST(mat); j++ ) {
for ( z = 1; z <= lim; z++ ) {
r = (TypFFE*)(PTR( ELM_LIST( mat, j ) ) + 1);
s = (TypFFE*)(PTR( sum ) + 1);
for ( k = 1; k <= len; k++, r++, s++ ) {
t = PROD_FF( z, *r, fld );
*s = SUM_FF( *s, t, fld );
}
CVCMFVF( mat, q, vec, l-1, stop, sum, j, q-1, pmin, best );
if ( *pmin <= stop )  return;
z = NEG_FF( z, fld );
r = (TypFFE*)(PTR( ELM_LIST( mat, j ) ) + 1);
s = (TypFFE*)(PTR( sum ) + 1);
for ( k = 1; k <= len; k++, r++, s++ ) {
t = PROD_FF( z, *r, fld );
*s = SUM_FF( *s, t, fld );
}
z = NEG_FF( z, fld );
}
}
}
}
TypHandle       AClosestVectorCombinationsMatFFEVecFFE (mat,q,vec,l,stop)
TypHandle           mat;
TypHandle           q;
TypHandle           vec;
TypHandle           l;
TypHandle           stop;
{
TypHandle           best;
unsigned long       min;
unsigned long       p;
TypHandle           sum;
if ( TYPE(q) != T_INT || ! (p = RootPrimePower( HD_TO_INT(q) )) )
return Error("AClosestVectorCombinationsMatFFEVecFFE: %s",
(long)"<q> must be a positive prime power",0L);
if ( ! ConvMatFFE( mat, HD_TO_INT(q) ) )
return Error("AClosestVectorCombinationsMatFFEVecFFE: %s",
(long)"<mat> must be a matrix over GF(<q>)",0L);
if ( ! ConvVecFFE( vec, HD_TO_INT(q) ) )
return Error("AClosestVectorCombinationsMatFFEVecFFE: %s",
(long)"<vec> must be a vector over GF(<q>)",0L);
if ( LEN_VECFFE( ELM_LIST(mat,1) ) != LEN_VECFFE(vec) )
return Error("AClosestVectorCombinationsMatFFEVecFFE: %s",
(long)"<mat>[<1>] and <vec> must have the same length",0L);
if ( TYPE(l) != T_INT || HD_TO_INT(l)<0 || LEN_LIST(mat)<HD_TO_INT(l) )
return Error("AClosestVectorCombinationsMatFFEVecFFE: %s",
(long)"<l> must be an integer between 0 and Length(<mat>)",0L);
if ( TYPE(stop) != T_INT || HD_TO_INT(stop)<0 )
return Error("AClosestVectorCombinationsMatFFEVecFFE: %s",
(long)"<stop> must be a nonnegative integer",0L);
if ( HD_TO_INT(l) == 0 ) {
best = NewBag( T_VECFFE, SIZE_PLEN_VECFFE( LEN_VECFFE(vec) ) );
SET_FLD_VECFFE( best, FLD_VECFFE(vec) );
}
else if ( HD_TO_INT(q) == 2 ) {
sum = NewBag( T_BLIST, SIZE_PLEN_BLIST( LEN_LIST(vec) ) );
SET_LEN_BLIST( sum, LEN_LIST(vec) );
best = NewBag( T_BLIST, SIZE_PLEN_BLIST( LEN_LIST(vec) ) );
SET_LEN_BLIST( best, LEN_LIST(vec) );
min = LEN_LIST(vec) + 1;
CVCM2V2( BlistsMatFF2(mat), BlistVecFF2(vec),
HD_TO_INT(l), HD_TO_INT(stop), sum, 0, &min, best );
best = VecFF2Blist(best);
}
else if ( WeightVecFFE( vec ) == 0 ) {
sum = NewBag( T_VECFFE, SIZE_PLEN_VECFFE( LEN_VECFFE(vec) ) );
SET_FLD_VECFFE( sum, FLD_VECFFE(vec) );
best = NewBag( T_VECFFE, SIZE_PLEN_VECFFE( LEN_VECFFE(vec) ) );
SET_FLD_VECFFE( best, FLD_VECFFE(vec) );
min = LEN_LIST(vec) + 1;
CVCMFVF( mat, HD_TO_INT(q), vec, HD_TO_INT(l),
HD_TO_INT(stop), sum, 0, 1, &min, best );
}
else {
sum = NewBag( T_VECFFE, SIZE_PLEN_VECFFE( LEN_VECFFE(vec) ) );
SET_FLD_VECFFE( sum, FLD_VECFFE(vec) );
best = NewBag( T_VECFFE, SIZE_PLEN_VECFFE( LEN_VECFFE(vec) ) );
SET_FLD_VECFFE( best, FLD_VECFFE(vec) );
min = LEN_LIST(vec) + 1;
CVCMFVF( mat, HD_TO_INT(q), vec, HD_TO_INT(l),
HD_TO_INT(stop), sum, 0, HD_TO_INT(q)-1, &min, best );
}
return best;
}
TypHandle       FunAClosestVectorCombinationsMatFFEVecFFE ( hdCall )
TypHandle           hdCall;
{
if ( SIZE(hdCall) != 6*SIZE_HD )
return Error("number of arguments must be 5 not %d",
(long)(SIZE(hdCall)/SIZE_HD - 1), 0L );
return AClosestVectorCombinationsMatFFEVecFFE(
EVAL( PTR(hdCall)[1] ), EVAL( PTR(hdCall)[2] ),
EVAL( PTR(hdCall)[3] ), EVAL( PTR(hdCall)[4] ),
EVAL( PTR(hdCall)[5] ) );
}
unsigned long   CLM2 ( cls, rem, syn, vec, tam, l, i )
TypHandle           cls;
unsigned long       rem;
unsigned long       syn;
TypHandle           vec;
TypHandle           tam;
unsigned long       l;
unsigned long       i;
{
unsigned long       len;
TypFFE *            v;
TypHandle           cpy;
TypFFE *            c;
unsigned long       n;
unsigned long       j, k;
len = LEN_VECFFE(vec);
if ( l == 1 ) {
for ( j = i+1; j <= len; j++ ) {
((TypFFE*)(PTR(vec) + 1))[j-1] = 1;
n = syn ^ (unsigned long)PTR(tam)[j];
if ( PTR(cls)[n+1] == 0 ) {
cpy = NewBag( T_VECFFE, SIZE_PLEN_VECFFE(len) );
SET_FLD_VECFFE( cpy, FLD_VECFFE(vec) );
v = (TypFFE*)(PTR(vec) + 1);
c = (TypFFE*)(PTR(cpy) + 1);
for ( k = 1; k <= len; k++, v++, c++ )
*c = *v;
PTR(cls)[n+1] = cpy;
rem--;
if ( rem == 0 )  break;
}
((TypFFE*)(PTR(vec) + 1))[j-1] = 0;
}
}
else {
for ( j = i+1; j+(l-1) <= len; j++ ) {
((TypFFE*)(PTR(vec) + 1))[j-1] = 1;
syn ^= (unsigned long)PTR(tam)[j];
((TypFFE*)(PTR(vec) + 1))[j-1] = 1;
rem = CLM2( cls, rem, syn, vec, tam, l-1, j );
if ( rem == 0 )  break;
((TypFFE*)(PTR(vec) + 1))[j-1] = 0;
syn ^= (unsigned long)PTR(tam)[j];
}
}
return rem;
}
unsigned long   CLMF ( cls, rem, syn, q, vec, tam, l, i, lim )
TypHandle           cls;
unsigned long       rem;
TypHandle           syn;
unsigned long       q;
TypHandle           vec;
TypHandle           tam;
unsigned long       l;
unsigned long       i;
unsigned long       lim;
{
unsigned long       len;
unsigned long       len2;
TypFFE *            fld;
TypFFE *            v;
TypHandle           cpy;
TypFFE *            c;
TypFFE *            r;
TypFFE *            s;
unsigned long       n;
TypFFE              t;
TypFFE              z;
TypFFE              y;
unsigned long       j, k;
len = LEN_VECFFE(vec);
len2 = LEN_VECFFE(syn);
fld = SUCC_FF( FLD_VECFFE(vec) );
if ( l == 1 ) {
for ( j = i+1; j <= len; j++ ) {
for ( z = 1; z <= lim; z++ ) {
((TypFFE*)(PTR(vec) + 1))[j-1] = z;
n = 0;
r = (TypFFE*)(PTR( PTR(tam)[j] ) + 1);
s = (TypFFE*)(PTR( syn ) + 1);
for ( k = 1; k <= len2; k++, r++, s++ ) {
t = PROD_FF( z, *r, fld );
n = n * q + SUM_FF( *s, t, fld );
}
if ( PTR(cls)[n+1] == 0 ) {
for ( y = 1; y <= q-1; y++ ) {
cpy = NewBag( T_VECFFE, SIZE_PLEN_VECFFE(len) );
SET_FLD_VECFFE( cpy, FLD_VECFFE(vec) );
v = (TypFFE*)(PTR(vec) + 1);
c = (TypFFE*)(PTR(cpy) + 1);
for ( k = 1; k <= len; k++, v++, c++ )
*c = PROD_FF( y, *v, fld );
n = 0;
r = (TypFFE*)(PTR( PTR(tam)[j] ) + 1);
s = (TypFFE*)(PTR( syn ) + 1);
for ( k = 1; k <= len2; k++, r++, s++ ) {
t = PROD_FF( z, *r, fld );
t = SUM_FF( *s, t, fld );
n = n * q + PROD_FF( y, t, fld );
}
PTR(cls)[n+1] = cpy;
rem--;
if ( rem == 0 )  break;
}
}
((TypFFE*)(PTR(vec) + 1))[j-1] = 0;
}
}
}
else {
for ( j = i+1; j+(l-1) <= len; j++ ) {
for ( z = 1; z <= lim; z++ ) {
((TypFFE*)(PTR(vec) + 1))[j-1] = z;
r = (TypFFE*)(PTR( PTR(tam)[j] ) + 1);
s = (TypFFE*)(PTR( syn ) + 1);
for ( k = 1; k <= len2; k++, r++, s++ ) {
t = PROD_FF( z, *r, fld );
*s = SUM_FF( *s, t, fld );
}
rem = CLMF( cls, rem, syn, q, vec, tam, l-1, j, q-1 );
if ( rem == 0 )  break;
((TypFFE*)(PTR(vec) + 1))[j-1] = 0;
z = NEG_FF( z, fld );
r = (TypFFE*)(PTR( PTR(tam)[j] ) + 1);
s = (TypFFE*)(PTR( syn ) + 1);
for ( k = 1; k <= len2; k++, r++, s++ ) {
t = PROD_FF( z, *r, fld );
*s = SUM_FF( *s, t, fld );
}
z = NEG_FF( z, fld );
}
}
}
return rem;
}
TypHandle       CosetLeaderMatFFE ( mat, q )
TypHandle           mat;
TypHandle           q;
{
TypHandle           cls;
unsigned long       rem;
unsigned long       p;
unsigned long       len;
TypHandle           tam;
TypHandle           vec;
TypHandle           syn;
unsigned long       i, k, l;
if ( TYPE(q) != T_INT || ! (p = RootPrimePower( HD_TO_INT(q) )) )
return Error("CosetLeaderMatFFE: %s",
(long)"<q> must be a positive prime power",0L);
if ( ! ConvMatFFE( mat, HD_TO_INT(q) ) )
return Error("CosetLeaderMatFFE: %s",
(long)"<mat> must be a matrix over GF(<q>)",0L);
len = LEN_LIST(mat);
if ( (         2 <= HD_TO_INT(q) && 31 <= len)
|| (         3 <= HD_TO_INT(q) && 19 <= len)
|| (         4 <= HD_TO_INT(q) && 16 <= len)
|| (         5 <= HD_TO_INT(q) && 13 <= len)
|| (         8 <= HD_TO_INT(q) && 11 <= len)
|| (         9 <= HD_TO_INT(q) && 10 <= len)
|| (        13 <= HD_TO_INT(q) &&  9 <= len)
|| (        19 <= HD_TO_INT(q) &&  8 <= len)
|| (        32 <= HD_TO_INT(q) &&  7 <= len)
|| (        64 <= HD_TO_INT(q) &&  6 <= len)
|| (       181 <= HD_TO_INT(q) &&  5 <= len)
|| (      1024 <= HD_TO_INT(q) &&  4 <= len)
|| (     32768 <= HD_TO_INT(q) &&  3 <= len)
|| (1073741824 <= HD_TO_INT(q) &&  2 <= len) ) {
return Error("CosetLeaderMatFFE: %s",
(long)"sorry, no hope to finish",0L);
}
rem = 1;
for ( i = 1; i <= len; i++ )
rem *= HD_TO_INT(q);
cls = NewBag( T_LIST, SIZE_PLEN_PLIST( rem ) );
SET_LEN_PLIST( cls, rem );
vec = NewBag( T_VECFFE, SIZE(PTR(mat)[1]) );
SET_FLD_VECFFE( vec, FLD_VECFFE(PTR(mat)[1]) );
PTR(cls)[1] = vec;
rem--;
if ( HD_TO_INT(q) == 2 ) {
tam = NewBag( T_BLIST, SIZE_PLEN_PLIST(LEN_VECFFE(PTR(mat)[1])) );
SET_LEN_BLIST( tam, LEN_VECFFE(PTR(mat)[1]) );
for ( i = 1; i <= LEN_PLIST( tam ); i++ ) {
l = 0;
for ( k = 1; k <= len; k++ ) {
l = (l << 1)
| ((TypFFE*)(PTR( PTR(mat)[k] ) + 1))[i-1];
}
PTR(tam)[i] = (TypHandle)l;
}
vec = NewBag( T_VECFFE, SIZE(PTR(mat)[1]) );
SET_FLD_VECFFE( vec, FLD_VECFFE(PTR(mat)[1]) );
for ( l = 1; l <= len && rem != 0; l++ )
rem = CLM2( cls, rem, 0, vec, tam, l, 0 );
}
else {
tam = NewBag( T_LIST, SIZE_PLEN_PLIST(LEN_VECFFE(PTR(mat)[1])) );
SET_LEN_PLIST( tam, LEN_VECFFE(PTR(mat)[1]) );
for ( i = 1; i <= LEN_PLIST( tam ); i++ ) {
syn = NewBag( T_VECFFE, SIZE_PLEN_VECFFE(len) );
SET_FLD_VECFFE( syn, FLD_VECFFE(PTR(mat)[1]) );
for ( k = 1; k <= len; k++ ) {
((TypFFE*)(PTR(syn)+1))[k-1]
= ((TypFFE*)(PTR( PTR(mat)[k] ) + 1))[i-1];
}
PTR(tam)[i] = syn;
}
vec = NewBag( T_VECFFE, SIZE(PTR(mat)[1]) );
SET_FLD_VECFFE( vec, FLD_VECFFE(PTR(mat)[1]) );
syn = NewBag( T_VECFFE, SIZE_PLEN_VECFFE(len) );
SET_FLD_VECFFE( syn, FLD_VECFFE(PTR(mat)[1]) );
for ( l = 1; l <= len && rem != 0; l++ )
rem = CLMF( cls, rem, syn, HD_TO_INT(q), vec, tam, l, 0, 1 );
}
if ( rem != 0 ) {
return Error("CosetLeaderMatFFE: %s",
(long)"the rows of <mat> must be linearly independent",0L);
}
return cls;
}
TypHandle       FunCosetLeadersMatFFE ( hdCall )
TypHandle           hdCall;
{
if ( SIZE(hdCall) != 3*SIZE_HD )
return Error("number of arguments must be 2 not %d",
(long)(SIZE(hdCall)/SIZE_HD - 1), 0L );
return CosetLeaderMatFFE(
EVAL( PTR(hdCall)[1] ), EVAL( PTR(hdCall)[2] ) );
}
void            InitCoding ()
{
InstIntFunc( "DistanceVecFFE",
FunDistanceVecFFE );
InstIntFunc( "DistancesDistributionVecFFEsVecFFE",
FunDistancesDistributionVecFFEsVecFFE );
InstIntFunc( "DistancesDistributionMatFFEVecFFE",
FunDistancesDistributionMatFFEVecFFE );
InstIntFunc( "AClosestVectorCombinationsMatFFEVecFFE",
FunAClosestVectorCombinationsMatFFEVecFFE );
InstIntFunc( "CosetLeadersMatFFE",
FunCosetLeadersMatFFE );
}
/* 当前文件是D:\Read\costab.c*/

/* 当前文件是D:\Read\costab.h*/

#ifdef SPEC_CPU2000_P64
#define long __int64
#endif

void            CompressDeductionList ( )
{
TypHandle           * ptTable;
long                i, j;
if ( dedlst != dedSize ) {
Error( "invalid call of CompressDeductionList", 0L, 0L );
}
ptTable = PTR( hdTable );
j = 0;
for ( i = dedfst; i < dedlst; i++ ) {
if ( HD_TO_INT(PTR(ptTable[dedgen[i]])[dedcos[i]] ) != 0 && j < i ) {
dedgen[j] = dedgen[i];
dedcos[j] = dedcos[i];
j++;
}
}
dedfst = 1;
dedlst = j;
if ( dedlst == dedSize ) {
if ( dedprint == 0 ) {
Pr( "#I  WARNING: deductions being discarded\n", 0L, 0L );
dedprint = 1;
}
dedlst--;
}
}
TypHandle       FunApplyRel ( hdCall )
TypHandle           hdCall;
{
TypHandle           hdApp;
TypHandle           * ptApp;
TypHandle           hdRel;
TypHandle           * ptRel;
long                lp;
long                lc;
long                rp;
long                rc;
long                tc;
if ( SIZE(hdCall) != 3*SIZE_HD )
return Error( "usage: ApplyRel( <app>, <rel> )", 0L, 0L );
hdApp = EVAL( PTR(hdCall)[1] );
if ( (TYPE(hdApp) != T_LIST && TYPE(hdApp) != T_VECTOR)
|| HD_TO_INT( PTR( hdApp )[0] ) != 4 )
return Error( "ApplyRel: <app> must be a list", 0L, 0L );
ptApp = PTR( hdApp );
lp = HD_TO_INT( ptApp[1] );
lc = HD_TO_INT( ptApp[2] );
rp = HD_TO_INT( ptApp[3] );
rc = HD_TO_INT( ptApp[4] );
hdRel = EVAL( PTR(hdCall)[2] );
if ( TYPE(hdRel) != T_LIST && TYPE(hdRel) != T_SET )
return Error( "ApplyRel: <rel> must be a list", 0L, 0L );
ptRel = PTR(hdRel);
if ( rp == -1 )  rp = lp + HD_TO_INT( PTR(hdRel)[1] );
while ( lp < rp && 0 < (tc = HD_TO_INT(PTR(ptRel[rp])[rc])) ) {
rc = tc;  rp = rp - 2;
}
while ( lp < rp && 0 < (tc = HD_TO_INT(PTR(ptRel[lp])[lc])) ) {
lc = tc;  lp = lp + 2;
}
ptApp[1] = INT_TO_HD( lp );
ptApp[2] = INT_TO_HD( lc );
ptApp[3] = INT_TO_HD( rp );
ptApp[4] = INT_TO_HD( rc );
if ( lp == rp+1 && HD_TO_INT(PTR(ptRel[lp])[lc]) != rc )
return HdTrue;
else
return HdFalse;
}
void            HandleCoinc ( cos1, cos2 )
unsigned long       cos1, cos2;
{
TypHandle           * ptTable;
TypHandle           * ptNext;
TypHandle           * ptPrev;
unsigned long       c1, c2, c3;
unsigned long       i;
unsigned long       firstCoinc;
unsigned long       lastCoinc;
TypHandle           * gen,  * inv;
if ( cos1 == cos2 )  return;
ptTable = PTR( hdTable );
ptNext  = PTR( hdNext );
ptPrev  = PTR( hdPrev );
if ( cos2 < cos1 ) { c3 = cos1;  cos1 = cos2;  cos2 = c3;  }
if ( cos2 == lastDef )
lastDef  = HD_TO_INT( ptPrev[lastDef ] );
if ( cos2 == firstDef )
firstDef = HD_TO_INT( ptPrev[firstDef] );
ptNext[HD_TO_INT(ptPrev[cos2])] = ptNext[cos2];
if ( ptNext[cos2] != INT_TO_HD( 0 ) )
ptPrev[HD_TO_INT(ptNext[cos2])] = ptPrev[cos2];
firstCoinc        = cos2;
lastCoinc         = cos2;
ptNext[lastCoinc] = INT_TO_HD( 0 );
ptPrev[cos2] = INT_TO_HD( cos1 );
while ( firstCoinc != 0 ) {
cos1 = HD_TO_INT( ptPrev[firstCoinc] );  cos2 = firstCoinc;
for ( i = 1; i <= HD_TO_INT( ptTable[0] ); i++ ) {
gen = PTR(ptTable[i]);
inv = PTR( ptTable[ i + 2*(i % 2) - 1 ] );
c2 = HD_TO_INT( gen[cos2] );
if ( c2 != 0 ) {
c1 = HD_TO_INT( gen[cos1] );
if ( c1 == 0 )  {
gen[cos1] = INT_TO_HD( c2 );
gen[cos2] = INT_TO_HD( 0 );
inv[c2]   = INT_TO_HD( cos1 );
if ( dedlst == dedSize ) CompressDeductionList( );
dedgen[dedlst] = i;
dedcos[dedlst] = cos1;
dedlst++;
}
else {
inv[c2]   = INT_TO_HD( 0 );
gen[cos2] = INT_TO_HD( 0 );
if ( gen[cos1] == INT_TO_HD( 0 ) ) {
gen[cos1] = INT_TO_HD( cos1 );
if ( dedlst == dedSize ) CompressDeductionList( );
dedgen[dedlst] = i;
dedcos[dedlst] = cos1;
dedlst++;
}
while ( c1 != 1
&& HD_TO_INT(ptNext[HD_TO_INT(ptPrev[c1])]) != c1 ) {
c1 = HD_TO_INT(ptPrev[c1]);
}
while ( c2 != 1
&& HD_TO_INT(ptNext[HD_TO_INT(ptPrev[c2])]) != c2 ) {
c2 = HD_TO_INT(ptPrev[c2]);
}
if ( c1 != c2 ) {
if ( c2 < c1 ) { c3 = c1;  c1 = c2;  c2 = c3; }
if ( c2 == lastDef  )
lastDef  = HD_TO_INT(ptPrev[lastDef ]);
if ( c2 == firstDef )
firstDef = HD_TO_INT(ptPrev[firstDef]);
ptNext[HD_TO_INT(ptPrev[c2])] = ptNext[c2];
if ( ptNext[c2] != INT_TO_HD( 0 ) )
ptPrev[HD_TO_INT(ptNext[c2])] = ptPrev[c2];
ptNext[lastCoinc] = INT_TO_HD( c2 );
lastCoinc         = c2;
ptNext[lastCoinc] = INT_TO_HD( 0 );
ptPrev[c2] = INT_TO_HD( c1 );
}
}
}
}
if ( firstFree == 0 ) {
firstFree      = firstCoinc;
lastFree       = firstCoinc;
}
else {
ptNext[lastFree] = INT_TO_HD( firstCoinc );
lastFree         = firstCoinc;
}
firstCoinc = HD_TO_INT( ptNext[firstCoinc] );
ptNext[lastFree] = INT_TO_HD( 0 );
nrdel++;
}
}
TypHandle       FunMakeConsequences ( hdCall )
TypHandle           hdCall;
{
TypHandle           hdList;
TypHandle           hdSubs;
TypHandle           hdRels;
TypHandle           * ptRel;
TypHandle           * ptNums;
long                lp;
long                lc;
long                rp;
long                rc;
long                tc;
long                i;
TypHandle           hdTmp;
hdList = EVAL( PTR(hdCall)[1] );
if ( TYPE(hdList) != T_LIST ) {
return Error( "usage: MakeConsequences( [ ... ] )", 0L, 0L );
}
hdTable   = PTR(hdList)[1];
hdNext    = PTR(hdList)[2];
hdPrev    = PTR(hdList)[3];
firstFree = HD_TO_INT( PTR(hdList)[6] );
lastFree  = HD_TO_INT( PTR(hdList)[7] );
firstDef  = HD_TO_INT( PTR(hdList)[8] );
lastDef   = HD_TO_INT( PTR(hdList)[9] );
nrdel     = 0;
dedprint = 0;
dedfst = 0;
dedlst = 1;
dedgen[ 0 ] = HD_TO_INT( PTR(hdList)[10] );
dedcos[ 0 ] = HD_TO_INT( PTR(hdList)[11] );
while ( dedfst < dedlst ) {
hdTmp = PTR( hdTable )[dedgen[dedfst]];
hdTmp = PTR( hdTmp )[dedcos[dedfst]];
if ( HD_TO_INT(hdTmp) == 0 ) {
dedfst++;
continue;
}
hdSubs = PTR(hdList)[5];
for ( i = LEN_LIST( hdSubs ); 1 <= i; i-- ) {
if ( PTR(hdSubs)[i] != 0 ) {
hdNums = PTR( PTR(hdSubs)[i] )[1];
ptNums = PTR( hdNums );
hdRel = PTR( PTR(hdSubs)[i] )[2];
ptRel = PTR( hdRel );
lp = 2;
lc = 1;
rp = LEN_LIST( hdRel ) - 1;
rc = 1;
while ( lp<rp && 0 < (tc = HD_TO_INT(PTR(ptRel[rp])[rc])) ) {
rc = tc;  rp = rp - 2;
}
while ( lp<rp && 0 < (tc = HD_TO_INT(PTR(ptRel[lp])[lc])) ) {
lc = tc;  lp = lp + 2;
}
if ( lp == rp+1 && HD_TO_INT(PTR(ptRel[lp])[lc]) != rc ) {
if ( HD_TO_INT( PTR(ptRel[lp])[lc] ) != 0 ) {
HandleCoinc( HD_TO_INT( PTR(ptRel[lp])[lc] ), rc );
}
else if ( HD_TO_INT( PTR(ptRel[rp])[rc] ) != 0 ) {
HandleCoinc( HD_TO_INT( PTR(ptRel[rp])[rc] ), lc );
}
else {
PTR(ptRel[lp])[lc] = INT_TO_HD( rc );
PTR(ptRel[rp])[rc] = INT_TO_HD( lc );
if ( dedlst == dedSize ) CompressDeductionList( );
dedgen[ dedlst ] = HD_TO_INT( ptNums[lp] );
dedcos[ dedlst ] = lc;
dedlst++;
}
PTR(hdSubs)[i] = 0;
if ( i == LEN_LIST( hdSubs ) ) {
while ( 0 < i  && PTR(hdSubs)[i] == 0 )
--i;
PTR( hdSubs )[0] = INT_TO_HD( i );
}
}
}
}
hdRels = PTR( PTR(hdList)[4] )[ dedgen[dedfst] ];
for ( i = 1; i <= LEN_LIST( hdRels ); i++ ) {
hdNums = PTR( PTR(hdRels)[i] )[1];
ptNums = PTR( hdNums );
hdRel = PTR( PTR(hdRels)[i] )[2];
ptRel = PTR( hdRel );
lp = HD_TO_INT( PTR( PTR(hdRels)[i] )[3] );
lc = dedcos[ dedfst ];
rp = lp + HD_TO_INT( ptRel[1] );
rc = lc;
while ( lp<rp && 0 < (tc = HD_TO_INT(PTR(ptRel[rp])[rc])) ) {
rc = tc;  rp = rp - 2;
}
while ( lp<rp && 0 < (tc = HD_TO_INT(PTR(ptRel[lp])[lc])) ) {
lc = tc;  lp = lp + 2;
}
if ( lp == rp+1 && HD_TO_INT(PTR(ptRel[lp])[lc]) != rc ) {
if ( HD_TO_INT( PTR(ptRel[lp])[lc] ) != 0 ) {
HandleCoinc( HD_TO_INT( PTR(ptRel[lp])[lc] ), rc );
}
else if ( HD_TO_INT( PTR(ptRel[rp])[rc] ) != 0 ) {
HandleCoinc( HD_TO_INT( PTR(ptRel[rp])[rc] ), lc );
}
else {
PTR(ptRel[lp])[lc] = INT_TO_HD( rc );
PTR(ptRel[rp])[rc] = INT_TO_HD( lc );
if ( dedlst == dedSize ) CompressDeductionList( );
dedgen[ dedlst ] = HD_TO_INT( ptNums[lp] );
dedcos[ dedlst ] = lc;
dedlst++;
}
}
}
dedfst++;
}
PTR(hdList)[6] = INT_TO_HD( firstFree );
PTR(hdList)[7] = INT_TO_HD( lastFree  );
PTR(hdList)[8] = INT_TO_HD( firstDef  );
PTR(hdList)[9] = INT_TO_HD( lastDef   );
return INT_TO_HD( nrdel );
}
TypHandle       FunStandardizeTable ( hdCall )
TypHandle           hdCall;
{
TypHandle           * ptTable;
unsigned long       nrgen;
TypHandle           * g;
TypHandle           * h,  * i;
unsigned long       acos;
unsigned long       lcos;
unsigned long       mcos;
unsigned long       c1, c2;
TypHandle           tmp;
unsigned long       j, k;
hdTable = EVAL( PTR(hdCall)[1] );
ptTable = PTR(hdTable);
nrgen = LEN_LIST( hdTable ) / 2;
acos = 1;
lcos = 1;
while ( acos <= lcos ) {
for ( j = 1; j <= nrgen; j++ ) {
g = PTR( ptTable[2*j-1] );
if ( lcos+1 < HD_TO_INT( g[acos] ) ) {
lcos = lcos + 1;
mcos = HD_TO_INT( g[acos] );
for ( k = 1; k <= nrgen; k++ ) {
h = PTR( ptTable[2*k-1] );
i = PTR( ptTable[2*k] );
c1 = HD_TO_INT( h[lcos] );
c2 = HD_TO_INT( h[mcos] );
if ( c1 != 0 )  i[c1] = INT_TO_HD( mcos );
if ( c2 != 0 )  i[c2] = INT_TO_HD( lcos );
tmp     = h[lcos];
h[lcos] = h[mcos];
h[mcos] = tmp;
if ( i != h ) {
c1 = HD_TO_INT( i[lcos] );
c2 = HD_TO_INT( i[mcos] );
if ( c1 != 0 )  h[c1] = INT_TO_HD( mcos );
if ( c2 != 0 )  h[c2] = INT_TO_HD( lcos );
tmp     = i[lcos];
i[lcos] = i[mcos];
i[mcos] = tmp;
}
}
}
else if ( lcos < HD_TO_INT( g[acos] ) ) {
lcos = lcos + 1;
}
}
acos = acos + 1;
}
for ( j = 1; j <= nrgen; j++ ) {
PTR(ptTable[2*j-1])[0] = INT_TO_HD(lcos);
PTR(ptTable[2*j  ])[0] = INT_TO_HD(lcos);
}
return HdVoid;
}
void            InitializeCosetFactorWord ( )
{
TypHandle           * ptWord;
long                i;
if ( treeType == 1 )
hdWordValue = INT_TO_HD( 0 );
else if ( treeType == 0 ) {
ptWord = PTR( hdTree2 );
for ( i = 1; i <= treeWordLength; i++ )
{ ptWord[i] = INT_TO_HD( 0 ); }
}
else
wordList[0] = 0;
}
void            AddCosetFactor ( hdfactor )
TypHandle           hdfactor;
{
hdWordValue = SumInt( hdWordValue, hdfactor );
if ( hdExponent != INT_TO_HD( 0 ) ){
hdWordValue = RemInt( hdWordValue, hdExponent );
}
}
void            AddCosetFactor2 ( factor )
long                factor;
{
TypHandle           * ptFac;
TypHandle           * ptWord;
long                leng;
long                sum;
long                i;
if ( treeType == 0 )
{
ptWord = PTR( hdTree2 );
if ( factor > 0 )
{
ptFac = PTR( PTR( hdTree1 )[factor] );
leng = HD_TO_INT( ptFac[0] );
for ( i = 1; i <= leng; i++ )
{
sum = (long)ptWord[i] + (long)ptFac[i] - T_INT;
if ( ( ( sum << 1 ) >> 1 ) != sum )
Error(
"exponent too large, Modified Todd-Coxeter aborted",
0L, 0L );
ptWord[i] = (TypHandle)sum;
}
}
else
{
ptFac = PTR( PTR( hdTree1 )[-factor] );
leng = HD_TO_INT( ptFac[0] );
for ( i = 1; i <= leng; i++ )
{
sum = (long)ptWord[i] - (long)ptFac[i] + T_INT;
if ( ( ( sum << 1 ) >> 1 ) != sum )
Error(
"exponent too large, Modified Todd-Coxeter aborted",
0L, 0L );
ptWord[i] = (TypHandle)sum;
}
}
}
else if ( wordList[0] == 0 )
{ wordList[++wordList[0]] = factor; }
else if ( wordList[wordList[0]] == - factor )
{ --wordList[0]; }
else if ( wordList[0] < wordSize )
{ wordList[++wordList[0]] = factor; }
else {
wordList[0] = ( wordList[1] = TreeEntryC( ) == 0 ) ? 0 : 1;
AddCosetFactor2( factor );
}
}
void            SubtractCosetFactor ( hdfactor )
TypHandle           hdfactor;
{
hdWordValue = DiffInt( hdWordValue, hdfactor );
if ( hdExponent != INT_TO_HD( 0 ) ){
hdWordValue = RemInt( hdWordValue, hdExponent );
}
}
TypHandle       FunApplyRel2 ( hdCall )
TypHandle           hdCall;
{
TypHandle           hdApp;
TypHandle           * ptApp;
TypHandle           hdWord;
TypHandle           * ptWord;
TypHandle           * ptTree;
TypHandle           * ptTree2;
TypHandle           * ptRel;
TypHandle           * ptNums;
TypHandle           * ptTabl2;
TypHandle           hdrep;
long                lp;
long                lc;
long                rp;
long                rc;
long                rep;
long                tc;
long                bound;
long                last;
long                size;
long                i;
if ( SIZE(hdCall) != 4*SIZE_HD )
return Error( "usage: ApplyRel2( <app>, <rel>, <nums> )", 0L, 0L );
hdApp = EVAL( PTR(hdCall)[1] );
if ( (TYPE(hdApp) != T_LIST && TYPE(hdApp) != T_VECTOR)
|| HD_TO_INT( PTR( hdApp )[0] ) != 9 )
return Error( "ApplyRel2: <app> must be a list of length 9", 0L,0L );
ptApp = PTR( hdApp );
lp = HD_TO_INT( ptApp[1] );
lc = HD_TO_INT( ptApp[2] );
rp = HD_TO_INT( ptApp[3] );
rc = HD_TO_INT( ptApp[4] );
hdRel = EVAL( PTR(hdCall)[2] );
if ( TYPE(hdRel) != T_LIST && TYPE(hdRel) != T_SET &&
TYPE(hdRel) != T_VECTOR )
return Error( "ApplyRel2: <rel> must be a list", 0L, 0L );
if ( rp == -1 )  rp = lp + HD_TO_INT( PTR(hdRel)[1] );
hdNums = EVAL( PTR(hdCall)[3] );
if ( TYPE(hdNums) != T_LIST && TYPE(hdNums) != T_VECTOR )
return Error( "ApplyRel2: <nums> must be a list", 0L, 0L );
hdTabl2 = ptApp[6];
if ( TYPE(hdTabl2) != T_LIST && TYPE(hdTabl2) != T_SET )
return Error( "ApplyRel2: <rep> must be a list", 0L, 0L );
treeType = HD_TO_INT( ptApp[5] );
if ( treeType == 1 )
{
hdExponent = INT_TO_HD( 0 );
while ( lp < rp + 2 &&
0 < (tc = HD_TO_INT(PTR(PTR(hdRel)[lp])[lc])) ) {
hdrep = PTR( PTR(hdTabl2)[HD_TO_INT(PTR(hdNums)[lp])] )[lc];
hdExponent = DiffInt( hdExponent, hdrep );
lc = tc;  lp = lp + 2;
}
while ( lp < rp + 2 &&
0 < (tc = HD_TO_INT(PTR(PTR(hdRel)[rp])[rc])) ) {
hdrep = PTR( PTR(hdTabl2)[HD_TO_INT(PTR(hdNums)[rp])] )[rc];
hdExponent = SumInt( hdExponent, hdrep );
rc = tc;  rp = rp - 2;
}
PTR( hdApp )[9] = hdExponent;
}
else {
hdWord = ptApp[7];
if ( TYPE(hdWord) != T_LIST && TYPE(hdWord) != T_SET
&& TYPE(hdWord) != T_VECTOR )
return Error( "ApplyRel2: <word> must be a list", 0L, 0L );
if ( treeType == 0 )
{
hdTree = ptApp[8];
hdTree1 = PTR( hdTree )[1];
hdTree2 = PTR( hdTree )[2];
ptTree = PTR( hdTree );
treeWordLength = HD_TO_INT( ptTree[4] );
if ( HD_TO_INT( PTR( hdTree2 )[0] ) != treeWordLength )
return Error( "ApplyRel2: illegal word length", 0L, 0L );
InitializeCosetFactorWord( );
while ( lp < rp + 2 &&
0 < (tc = HD_TO_INT(PTR(PTR(hdRel)[lp])[lc])) ) {
rep = HD_TO_INT(
PTR( PTR(hdTabl2)[HD_TO_INT(PTR(hdNums)[lp])] )[lc] );
if ( rep != 0 )  { AddCosetFactor2( - rep ); }
lc = tc;  lp = lp + 2;
}
while ( lp < rp + 2 &&
0 < (tc = HD_TO_INT(PTR(PTR(hdRel)[rp])[rc])) ) {
rep = HD_TO_INT(
PTR( PTR(hdTabl2)[HD_TO_INT(PTR(hdNums)[rp])] )[rc] );
if ( rep != 0 )  { AddCosetFactor2( rep ); }
rc = tc;  rp = rp - 2;
}
ptWord = PTR( hdWord );
ptTree2 = PTR( hdTree2 );
if ( ptWord != ptTree2 ) {
if ( HD_TO_INT( ptWord[0] ) != treeWordLength )
return Error( "ApplyRel2: illegal word length", 0L, 0L );
for ( i = 0; i <= treeWordLength; i++ )
{ ptWord[i] = ptTree2[i]; }
}
}
else
{
{
bound = ( rp - lp + 3 ) / 2;
size = SIZE( hdWord ) / SIZE_HD - 1;
if ( size < bound ) {
size = ( bound > 2 * size ) ? bound : 2 * size;
Resize( hdWord, ( size + 1 ) * SIZE_HD );
}
}
ptRel = PTR( hdRel );
ptNums = PTR( hdNums );
ptTabl2 = PTR( hdTabl2 );
ptWord = PTR( hdWord );
last = 0;
while ( lp < rp + 2 && 0 < (tc = HD_TO_INT(PTR(ptRel[lp])[lc])) ) {
rep = HD_TO_INT( PTR( ptTabl2[HD_TO_INT(ptNums[lp])] )[lc] );
if ( rep != 0 ) {
if ( last > 0 && HD_TO_INT(ptWord[last]) == rep ) last--;
else  { ptWord[++last] = INT_TO_HD( - rep ); }
}
lc = tc;  lp = lp + 2;
}
if ( last > 0 ) {
last++;
for ( i = last / 2; i > 0; i-- ) {
hdrep = ptWord[i];
ptWord[i] = ptWord[last-i];
ptWord[last-i] = hdrep;
}
last--;
}
while ( lp < rp + 2 && 0 < (tc = HD_TO_INT(PTR(ptRel[rp])[rc])) ) {
rep = HD_TO_INT( PTR( ptTabl2[HD_TO_INT(ptNums[rp])] )[rc] );
if ( rep != 0 ) {
if ( last > 0 && HD_TO_INT(ptWord[last]) == - rep ) last--;
else  { ptWord[++last] = INT_TO_HD( rep ); }
}
rc = tc;  rp = rp - 2;
}
ptWord[0] = INT_TO_HD( last );
}
}
ptApp = PTR( hdApp );
ptApp[1] = INT_TO_HD( lp );
ptApp[2] = INT_TO_HD( lc );
ptApp[3] = INT_TO_HD( rp );
ptApp[4] = INT_TO_HD( rc );
return HdVoid;
}
TypHandle       FunCopyRel ( hdCall )
TypHandle           hdCall;
{
TypHandle           hdRel;
TypHandle           * ptRel;
TypHandle           hdCopy;
TypHandle           * ptCopy;
long                leng;
if ( SIZE(hdCall) != 2*SIZE_HD )
return Error( "usage: CopyRel( <relator> )", 0L, 0L );
hdRel = EVAL( PTR(hdCall)[1] );
if ( TYPE(hdRel) != T_LIST && TYPE(hdRel) != T_SET
&& TYPE(hdRel) != T_VECTOR )
return Error( "invalid <relator>", 0L,0L );
leng = HD_TO_INT( PTR( hdRel )[0] );
hdCopy = NewBag( T_LIST, (leng + 1) * SIZE_HD );
ptRel = PTR( hdRel );
ptCopy = PTR( hdCopy );
while ( leng >= 0 ) {
*ptCopy++ = *ptRel++;  leng--;
}
return hdCopy;
}
TypHandle       FunMakeCanonical ( hdCall )
TypHandle           hdCall;
{
TypHandle           hdRel;
TypHandle           * ptRel;
TypHandle           hd1, hd2;
long                leng, leng1;
long                max, min, next;
long                i, j, k, l;
long                ii, jj, kk;
if ( SIZE(hdCall) != 2*SIZE_HD )
return Error( "usage: MakeCanonical( <relator> )",
0L, 0L );
hdRel = EVAL( PTR(hdCall)[1] );
if ( TYPE(hdRel) != T_LIST && TYPE(hdRel) != T_SET
&& TYPE(hdRel) != T_VECTOR )
return Error( "invalid <relator>", 0L, 0L );
ptRel = PTR( hdRel ) + 1;
leng = HD_TO_INT( ptRel[-1] );
leng1 = leng - 1;
i = 0;
while ( i < leng1 && HD_TO_INT(ptRel[i]) == - HD_TO_INT(ptRel[leng1]) ) {
i++;  leng1--;
}
if ( i > 0 ) {
for ( j = i; j <= leng1; j++ ) {
ptRel[j-i] = ptRel[j];
}
leng1 = leng1 - i;
leng = leng1 + 1;
ptRel[-1] = INT_TO_HD( leng );
}
max = min = HD_TO_INT( ptRel[0] );
i = 0;  j = 0;
for ( k = 1; k < leng; k++ ) {
next = HD_TO_INT( ptRel[k] );
if ( next > max )  { max = next;  i = k; }
else if ( next <= min )  { min = next;  j = k; }
}
if ( max < - min )  { i = leng; }
else {
for ( k = i + 1; k < leng; k++ ) {
for ( ii = i, kk = k, l = 0; l < leng; ii = (ii + 1) % leng,
kk = (kk + 1) % leng, l++ ) {
if ( HD_TO_INT(ptRel[kk]) < HD_TO_INT(ptRel[ii]) )
{ break; }
else if ( HD_TO_INT(ptRel[kk]) > HD_TO_INT(ptRel[ii]) )
{ i = k;  break; }
}
if ( l == leng )  { break; }
}
}
if ( - max < min )  { j = leng; }
else {
for ( k = j - 1; k >= 0; k-- ) {
for ( jj = j, kk = k, l = 0; l < leng; jj = (jj + leng1) % leng,
kk = (kk + leng1) % leng, l++ ) {
if ( HD_TO_INT(ptRel[kk]) > HD_TO_INT(ptRel[jj]) )
{ break; }
else if ( HD_TO_INT(ptRel[kk]) < HD_TO_INT(ptRel[jj]) )
{ j = k;  break; }
}
if ( l == leng )  { break; }
}
}
if ( - min == max ) {
for ( ii = i, jj = j, l = 0; l < leng; ii = (ii + 1) % leng,
jj = (jj + leng1) % leng, l++ ) {
if ( - HD_TO_INT(ptRel[jj]) < HD_TO_INT(ptRel[ii]) )
{ break; }
else if ( - HD_TO_INT(ptRel[jj]) > HD_TO_INT(ptRel[ii]) )
{ i = leng;  break; }
}
}
if ( i == leng ) {
for ( k = 0; k < leng / 2;  k++ ) {
next = HD_TO_INT( ptRel[k] );
ptRel[k] = INT_TO_HD( - HD_TO_INT( ptRel[leng1-k] ) );
ptRel[leng1-k] = INT_TO_HD( - next );
}
if ( leng % 2 ) {
ptRel[leng1/2] = INT_TO_HD( - HD_TO_INT( ptRel[leng1/2] ) );
}
i = leng1 - j;
}
if ( i > 0 ) {
k = HD_TO_INT( GcdInt( INT_TO_HD(i), INT_TO_HD(leng) ) );
l = leng / k;
leng1 = leng - i;
for ( j = 0; j < k; j++ ) {
jj = (j + i) % leng;
hd1 = ptRel[jj];
for ( ii = 0; ii < l; ii++ ) {
jj = (jj + leng1) % leng;
hd2 = ptRel[jj];  ptRel[jj] = hd1;  hd1 = hd2;
}
}
}
return HdVoid;
}
TypHandle       FunTreeEntry ( hdCall )
TypHandle           hdCall;
{
TypHandle           * ptTree1;
TypHandle           * ptTree2;
TypHandle           hdWord;
TypHandle           * ptWord;
TypHandle           hdNew;
TypHandle           * ptNew;
TypHandle           * ptFac;
long                treesize;
long                numgens;
long                leng;
long                sign;
long                i, j, k;
long                gen;
long                u, u1, u2;
long                v, v1, v2;
long                t1, t2;
long                uabs, vabs;
if ( SIZE(hdCall) != 3*SIZE_HD )
return Error( "usage: TreeEntry( <tree>,<word> )", 0L, 0L );
hdTree = EVAL( PTR(hdCall)[1] );
if ( TYPE(hdTree) != T_LIST || HD_TO_INT(PTR(hdTree)[0]) < 5 )
return Error( "invalid <tree>", 0L, 0L );
hdTree1 = PTR( hdTree )[1];
hdTree2 = PTR( hdTree )[2];
if ( (TYPE(hdTree1) != T_LIST && TYPE(hdTree1) != T_VECTOR)
|| (TYPE(hdTree2) != T_LIST && TYPE(hdTree2) != T_VECTOR) )
return Error( "invalid <tree> components", 0L, 0L );
ptTree1 = PTR( hdTree1 );
ptTree2 = PTR( hdTree2 );
treesize = HD_TO_INT( ptTree1[0] );
numgens = HD_TO_INT( PTR( hdTree )[3] );
treeWordLength = HD_TO_INT( PTR( hdTree )[4] );
treeType = HD_TO_INT( PTR( hdTree )[5] );
hdWord = EVAL( PTR(hdCall)[2] );
if ( TYPE(hdWord) != T_LIST && TYPE(hdWord) != T_SET && TYPE(hdWord) !=
T_VECTOR ) return Error( "invalid <word>", 0L, 0L );
ptWord = PTR( hdWord );
if ( treeType == 0 )
{
if ( HD_TO_INT(ptWord[0]) != treeWordLength )
return Error( "inconsistent <word> length", 0L, 0L );
ptWord = PTR( hdTree2 );
for ( leng = treeWordLength; leng >= 1; leng-- )
{
if ( ptWord[leng] != INT_TO_HD( 0 ) )  { break; }
}
if ( leng == 0 )
{ return INT_TO_HD( 0 ); }
for ( k = 1; k <= leng; k++ )
{
if ( ptWord[k] != INT_TO_HD( 0 ) )  { break; }
}
sign = 1;
if ( HD_TO_INT( ptWord[k] ) < 0 )
{
sign = - 1;
for ( i = k; i <= leng; i++ )
{
ptWord[i] = INT_TO_HD( - HD_TO_INT( ptWord[i] ) );
}
}
for ( k = 1; k <= numgens; k++ )
{
ptFac = PTR( ptTree1[k] );
if ( HD_TO_INT( ptFac[0] ) == leng )
{
for ( i = 1; i <= leng; i++ )
{
if ( ptFac[i] != ptWord[i] )  { break; }
}
if ( i > leng )
{ return INT_TO_HD( sign * k ); }
}
}
numgens++;
if ( treesize < numgens ) {
treesize = 2 * treesize;
Resize( hdTree1, ( treesize + 1 ) * SIZE_HD );
PTR( hdTree1 )[0] = INT_TO_HD( treesize );
}
hdNew = NewBag( T_LIST, (leng + 1) * SIZE_HD );
PTR( hdTree )[3] = INT_TO_HD( numgens );
PTR( hdTree1 )[numgens] = hdNew;
ptWord = PTR( hdTree2 );
ptNew = PTR( hdNew );
ptNew[0] = INT_TO_HD( leng );
while ( leng > 0 ) {
ptNew[leng] = ptWord[leng];  leng--;
}
return INT_TO_HD( sign * numgens );
}
if ( PTR(hdTree1)[0] != PTR(hdTree2)[0] )
return Error( "inconsistent <tree> components", 0L, 0L );
for ( i = 1; i <= numgens; i++ ) {
if ( HD_TO_INT(ptTree1[i]) <= -i || HD_TO_INT(ptTree1[i]) >= i
|| HD_TO_INT(ptTree2[i]) <= -i || HD_TO_INT(ptTree2[i]) >= i )
return Error( "invalid <tree> components", 0L, 0L );
}
leng = HD_TO_INT(ptWord[0]);
for ( j = 0, i = 1; i <= leng; i++ ) {
gen = HD_TO_INT(ptWord[i]);
if ( gen == 0 ) continue;
if ( gen > numgens || gen < -numgens )
return Error( "invalid <word> entry [%d]", i, 0L );
if ( j > 0 && gen == - HD_TO_INT(ptWord[j]) )
{ j--; }
else
{ ptWord[++j] = ptWord[i]; }
}
for ( i = j + 1; i <= leng; i++ )
{ ptWord[i] = INT_TO_HD( 0 ); }
leng = j;
gen = ( leng == 0 ) ? 0 : HD_TO_INT( ptWord[1] );
u2 = 0;
for ( i = 2; i <= leng; i++ ) {
u = gen;
v = HD_TO_INT( PTR( hdWord )[i] );
while ( i ) {
if ( u == 0 || v == 0 || ( u + v ) == 0 ) {
gen = u + v;
break;
}
u1 = HD_TO_INT( ptTree1[ (u > 0) ? u : -u ] );
if ( u1 != 0 ) {
if ( u > 0 )  { u2 = HD_TO_INT( ptTree2[u] ); }
else  { u2 = - u1;   u1 = - HD_TO_INT( ptTree2[-u] ); }
if ( u2 == -v ) {
gen = u1;
break;
}
}
v1 = HD_TO_INT( ptTree1[ (v > 0) ? v : -v ] );
if ( v1 != 0 ) {
if ( v > 0 )  { v2 = HD_TO_INT( ptTree2[v] ); }
else  { v2 = - v1;   v1 = - HD_TO_INT( ptTree2[-v] ); }
if ( v1 == -u ) {
gen = v2;
break;
}
if ( u1 != 0 && v1 == - u2 ) {
u = u1;  v = v2;
continue;
}
}
if ( u < -v )
{ t1 = u;  t2 = v; }
else
{ t1 = -v;  t2 = -u; }
uabs = ( u > 0 ) ? u : -u;
vabs = ( v > 0 ) ? v : -v;
k = ( uabs > vabs ) ? uabs : vabs;
for ( k++; k <= numgens; k++ ) {
if ( HD_TO_INT(ptTree1[k]) == t1 &&
HD_TO_INT(ptTree2[k]) == t2 )  { break; }
}
if ( k > numgens ) {
numgens++;
if ( treesize < numgens ) {
treesize = 2 * treesize;
Resize( hdTree1, ( treesize + 1 ) * SIZE_HD );
Resize( hdTree2, ( treesize + 1 ) * SIZE_HD );
ptTree1 = PTR( hdTree1 );
ptTree2 = PTR( hdTree2 );
ptTree1[0] = INT_TO_HD( treesize );
ptTree2[0] = INT_TO_HD( treesize );
}
ptTree1[numgens] = INT_TO_HD( t1 );
ptTree2[numgens] = INT_TO_HD( t2 );
PTR( hdTree )[3] = INT_TO_HD( numgens );
}
gen = ( u > - v ) ? -k : k;
break;
}
}
return INT_TO_HD( gen );
}
long       TreeEntryC ( )
{
TypHandle           * ptTree1;
TypHandle           * ptTree2;
TypHandle           * ptWord;
TypHandle           * ptFac;
TypHandle           * ptNew;
TypHandle           hdNew;
long                treesize;
long                numgens;
long                leng;
long                sign;
long                i, k;
long                gen;
long                u, u1, u2;
long                v, v1, v2;
long                t1, t2;
long                uabs, vabs;
ptTree1 = PTR( hdTree1 );
ptTree2 = PTR( hdTree2 );
treesize = HD_TO_INT( ptTree1[0] );
numgens = HD_TO_INT( PTR( hdTree )[3] );
if ( treeType == 0 )
{
ptWord = PTR( hdTree2 );
for ( leng = treeWordLength; leng >= 1; leng-- )
{
if ( ptWord[leng] != INT_TO_HD( 0 ) )  { break; }
}
if ( leng == 0 )  { return 0; }
for ( k = 1; k <= leng; k++ )
{
if ( ptWord[k] != INT_TO_HD( 0 ) )  { break; }
}
sign = 1;
if ( HD_TO_INT( ptWord[k] ) < 0 )
{
sign = - 1;
for ( i = k; i <= leng; i++ )
{
ptWord[i] = INT_TO_HD( - HD_TO_INT( ptWord[i] ) );
}
}
for ( k = 1; k <= numgens; k++ )
{
ptFac = PTR( ptTree1[k] );
if ( HD_TO_INT( ptFac[0] ) == leng )
{
for ( i = 1; i <= leng; i++ )
{
if ( ptFac[i] != ptWord[i] )  { break; }
}
if ( i > leng )  { return sign * k; }
}
}
numgens++;
if ( treesize < numgens ) {
treesize = 2 * treesize;
Resize( hdTree1, ( treesize + 1 ) * SIZE_HD );
}
hdNew = NewBag( T_LIST, (leng + 1) * SIZE_HD );
PTR( hdTree )[3] = INT_TO_HD( numgens );
PTR( hdTree1 )[0] = INT_TO_HD( treesize );
PTR( hdTree1 )[numgens] = hdNew;
ptWord = PTR( hdTree2 );
ptNew = PTR( hdNew );
ptNew[0] = INT_TO_HD( leng );
while ( leng > 0 ) {
ptNew[leng] = ptWord[leng];  leng--;
}
return sign * numgens;
}
leng = wordList[0];
gen = ( leng == 0 ) ? 0 : wordList[1];
u2 = 0;
for ( i = 2; i <= leng; i++ ) {
u = gen;
v = wordList[i];
while ( i ) {
if ( u == 0 || v == 0 || ( u + v ) == 0 ) {
gen = u + v;
break;
}
u1 = HD_TO_INT( ptTree1[ (u > 0) ? u : -u ] );
if ( u1 != 0 ) {
if ( u > 0 )  { u2 = HD_TO_INT( ptTree2[u] ); }
else  { u2 = - u1;   u1 = - HD_TO_INT( ptTree2[-u] ); }
if ( u2 == -v ) {
gen = u1;
break;
}
}
v1 = HD_TO_INT( ptTree1[ (v > 0) ? v : -v ] );
if ( v1 != 0 ) {
if ( v > 0 )  { v2 = HD_TO_INT( ptTree2[v] ); }
else  { v2 = - v1;   v1 = - HD_TO_INT( ptTree2[-v] ); }
if ( v1 == -u ) {
gen = v2;
break;
}
if ( u1 != 0 && v1 == - u2 ) {
u = u1;  v = v2;
continue;
}
}
if ( u < -v )
{ t1 = u;  t2 = v; }
else
{ t1 = -v;  t2 = -u; }
uabs = ( u > 0 ) ? u : -u;
vabs = ( v > 0 ) ? v : -v;
k = ( uabs > vabs ) ? uabs : vabs;
for ( k++; k <= numgens; k++ ) {
if ( HD_TO_INT(ptTree1[k]) == t1 &&
HD_TO_INT(ptTree2[k]) == t2 )  { break; }
}
if ( k > numgens ) {
numgens++;
if ( treesize < numgens ) {
treesize = 2 * treesize;
Resize( hdTree1, ( treesize + 1 ) * SIZE_HD );
Resize( hdTree2, ( treesize + 1 ) * SIZE_HD );
ptTree1 = PTR( hdTree1 );
ptTree2 = PTR( hdTree2 );
ptTree1[0] = INT_TO_HD( treesize );
ptTree2[0] = INT_TO_HD( treesize );
}
ptTree1[numgens] = INT_TO_HD( t1 );
ptTree2[numgens] = INT_TO_HD( t2 );
PTR( hdTree )[3] = INT_TO_HD( numgens );
}
gen = ( u > - v ) ? -k : k;
break;
}
}
return gen;
}
void            HandleCoinc2 ( cos1, cos2, hdfactor )
long                cos1, cos2;
TypHandle           hdfactor;
{
TypHandle           * gen, * gen2;
TypHandle           * inv, * inv2;
TypHandle           * ptNext;
TypHandle           * ptPrev;
long                c1, c2;
long                firstCoinc;
long                lastCoinc;
TypHandle           hdf, hdff2;
TypHandle           hdf1, hdf2;
long                length;
long                save;
TypHandle           hdRemainder;
long                i, j;
TypHandle           hdTmp;
if ( cos1 == cos2 ) {
if ( treeType == 1 && hdfactor != INT_TO_HD( 0 ) ) {
if ( hdExponent == INT_TO_HD( 0 ) )
{ hdExponent = hdfactor; }
else {
hdRemainder = RemInt( hdfactor, hdExponent );
while ( hdRemainder != INT_TO_HD( 0 ) ) {
hdfactor = hdExponent;
hdExponent = hdRemainder;
hdRemainder = RemInt( hdfactor, hdExponent );
}
}
}
return;
}
if ( cos2 < cos1 ) {
save = cos1;  cos1 = cos2;  cos2 = save;
hdfactor = ( treeType == 1 ) ?
DiffInt( INT_TO_HD( 0 ), hdfactor ) :
INT_TO_HD( - HD_TO_INT( hdfactor ) );
}
ptNext  = PTR( hdNext );
ptPrev  = PTR( hdPrev );
if ( cos2 == lastDef )
lastDef  = HD_TO_INT( ptPrev[lastDef ] );
if ( cos2 == firstDef )
firstDef = HD_TO_INT( ptPrev[firstDef] );
ptNext[HD_TO_INT(ptPrev[cos2])] = ptNext[cos2];
if ( ptNext[cos2] != INT_TO_HD( 0 ) )
ptPrev[HD_TO_INT(ptNext[cos2])] = ptPrev[cos2];
firstCoinc        = cos2;
lastCoinc         = cos2;
ptNext[lastCoinc] = INT_TO_HD( 0 );
ptPrev[cos2] = INT_TO_HD( cos1 );
PTR( hdFact )[cos2] = hdfactor;
while ( firstCoinc != 0 ) {
cos2 = firstCoinc;
cos1 = HD_TO_INT( PTR( hdPrev )[cos2] );
hdfactor = PTR( hdFact )[cos2];
for ( i = 1; i <= HD_TO_INT( PTR( hdTable )[0] ); i++ ) {
j = i + 2*(i % 2) - 1;
gen = PTR( PTR( hdTable )[i] );
gen2 = PTR( PTR( hdTabl2 )[i] );
c2 = HD_TO_INT( gen[cos2] );
if ( c2 != 0 ) {
hdf2 = gen2[cos2];
c1 = HD_TO_INT( gen[cos1] );
if ( c1 == 0 )  {
if ( hdf2 == hdfactor )
{ hdff2 = INT_TO_HD( 0 ); }
else {
if ( treeType == 1 ) {
hdWordValue = INT_TO_HD( 0 );
if ( hdfactor != INT_TO_HD( 0 ) )
SubtractCosetFactor( hdfactor );
if ( hdf2 != INT_TO_HD( 0 ) )
AddCosetFactor( hdf2 );
hdff2 = hdWordValue;
}
else {
InitializeCosetFactorWord( );
if ( hdfactor != INT_TO_HD( 0 ) )
AddCosetFactor2( - HD_TO_INT( hdfactor ) );
if ( hdf2 != INT_TO_HD( 0 ) )
AddCosetFactor2( HD_TO_INT( hdf2 ) );
hdff2 = INT_TO_HD( TreeEntryC( ) );
}
}
hdTmp =  ( treeType == 1 ) ?
DiffInt( INT_TO_HD( 0 ), hdff2 ) :
INT_TO_HD( - HD_TO_INT( hdff2 ) );
gen = PTR( PTR( hdTable )[i] );
gen2 = PTR( PTR( hdTabl2 )[i] );
inv = PTR( PTR( hdTable )[j] );
inv2 = PTR( PTR( hdTabl2 )[j] );
gen[cos1]  = INT_TO_HD( c2 );
gen2[cos1] = hdff2;
gen[cos2]  = INT_TO_HD( 0 );
gen2[cos2] = INT_TO_HD( 0 );
inv[c2]    = INT_TO_HD( cos1 );
inv2[c2]   = hdTmp;
if ( dedlst == dedSize ) CompressDeductionList( );
dedgen[dedlst] = i;
dedcos[dedlst] = cos1;
dedlst++;
}
else {
hdf1 = gen2[cos1];
inv = PTR( PTR( hdTable )[j] );
inv2 = PTR( PTR( hdTabl2 )[j] );
inv[c2]    = INT_TO_HD( 0 );
inv2[c2]   = INT_TO_HD( 0 );
gen[cos2]  = INT_TO_HD( 0 );
gen2[cos2] = INT_TO_HD( 0 );
if ( gen[cos1] == INT_TO_HD( 0 ) ) {
if ( hdf2 == hdfactor )
hdff2 = INT_TO_HD( 0 );
else {
if ( treeType == 1 ) {
hdWordValue = INT_TO_HD( 0 );
if ( hdfactor != INT_TO_HD( 0 ) )
SubtractCosetFactor( hdfactor );
if ( hdf2 != INT_TO_HD( 0 ) )
AddCosetFactor( hdf2 );
hdff2 = hdWordValue;
}
else {
InitializeCosetFactorWord( );
if ( hdfactor != INT_TO_HD( 0 ) )
AddCosetFactor2(
- HD_TO_INT( hdfactor ) );
if ( hdf2 != INT_TO_HD( 0 ) )
AddCosetFactor2( HD_TO_INT( hdf2 ) );
hdff2 = INT_TO_HD( TreeEntryC( ) );
}
gen = PTR( PTR( hdTable )[i] );
gen2 = PTR( PTR( hdTabl2 )[i] );
}
gen[cos1]  = INT_TO_HD( cos1 );
gen2[cos1] = hdff2;
if ( dedlst == dedSize ) CompressDeductionList( );
dedgen[dedlst] = i;
dedcos[dedlst] = cos1;
dedlst++;
}
InitializeCosetFactorWord( );
if ( treeType == 1 )
{
if ( hdf2 != INT_TO_HD( 0 ) )
SubtractCosetFactor( hdf2 );
while ( c2 != 1 && HD_TO_INT(
PTR(hdNext)[HD_TO_INT(PTR(hdPrev)[c2])]) != c2 ) {
hdf2 = PTR(hdFact)[c2];
c2 = HD_TO_INT( PTR(hdPrev)[c2] );
if ( hdf2 != INT_TO_HD( 0 ) )
SubtractCosetFactor( hdf2 );
}
if ( hdfactor != INT_TO_HD( 0 ) )
AddCosetFactor( hdfactor );
if ( hdf1 != INT_TO_HD( 0 ) )
AddCosetFactor( hdf1 );
}
else if ( treeType == 0 )
{
if ( hdf2 != INT_TO_HD( 0 ) )
AddCosetFactor2( - HD_TO_INT( hdf2 ) );
while ( c2 != 1 && HD_TO_INT(
PTR(hdNext)[HD_TO_INT(PTR(hdPrev)[c2])]) != c2 ) {
hdf2 = PTR( hdFact )[c2];
c2 = HD_TO_INT( PTR(hdPrev)[c2] );
if ( hdf2 != INT_TO_HD( 0 ) )
AddCosetFactor2( - HD_TO_INT( hdf2 ) );
}
if ( hdfactor != INT_TO_HD( 0 ) )
AddCosetFactor2( HD_TO_INT( hdfactor ) );
if ( hdf1 != INT_TO_HD( 0 ) )
AddCosetFactor2( HD_TO_INT( hdf1 ) );
}
else
{
if ( hdf2 != INT_TO_HD( 0 ) )
AddCosetFactor2( HD_TO_INT( hdf2 ) );
while ( c2 != 1 && HD_TO_INT(
PTR(hdNext)[HD_TO_INT(PTR(hdPrev)[c2])]) != c2 ) {
hdf2 = PTR( hdFact )[c2];
c2 = HD_TO_INT( PTR(hdPrev)[c2] );
if ( hdf2 != INT_TO_HD( 0 ) )
AddCosetFactor2( HD_TO_INT( hdf2 ) );
}
if ( wordList[0] > 0 ) {
length = wordList[0] + 1;
for ( i = length / 2; i > 0; i-- ) {
save = wordList[i];
wordList[i] = - wordList[length-i];
wordList[length-i] = - save;
}
}
if ( hdfactor != INT_TO_HD( 0 ) )
AddCosetFactor2( HD_TO_INT( hdfactor ) );
if ( hdf1 != INT_TO_HD( 0 ) )
AddCosetFactor2( HD_TO_INT( hdf1 ) );
}
while ( c1 != 1 && HD_TO_INT(
PTR(hdNext)[HD_TO_INT(PTR(hdPrev)[c1])]) != c1 ) {
hdf1 = PTR(hdFact)[c1];
c1 = HD_TO_INT( PTR(hdPrev)[c1] );
if ( hdf1 != INT_TO_HD( 0 ) ) {
if ( treeType == 1 )
AddCosetFactor( hdf1 );
else
AddCosetFactor2( HD_TO_INT( hdf1 ) );
}
}
if ( c1 != c2 ) {
hdf = (treeType == 1 ) ?
hdWordValue : INT_TO_HD( TreeEntryC( ) );
if ( c2 < c1 ) {
save = c1;  c1 = c2;  c2 = save;
hdf = ( treeType == 1 ) ?
DiffInt( INT_TO_HD( 0 ), hdf ) :
INT_TO_HD( - HD_TO_INT( hdf ) );
}
ptNext  = PTR( hdNext );
ptPrev  = PTR( hdPrev );
if ( c2 == lastDef )
lastDef  = HD_TO_INT( ptPrev[lastDef ] );
if ( c2 == firstDef )
firstDef = HD_TO_INT( ptPrev[firstDef] );
ptNext[HD_TO_INT(ptPrev[c2])] = ptNext[c2];
if ( ptNext[c2] != INT_TO_HD( 0 ) ) {
ptPrev[HD_TO_INT(ptNext[c2])] = ptPrev[c2];
}
ptNext[lastCoinc] = INT_TO_HD( c2 );
lastCoinc         = c2;
ptNext[lastCoinc] = INT_TO_HD( 0 );
ptPrev[c2] = INT_TO_HD( c1 );
PTR( hdFact )[c2] = hdf;
}
else if ( treeType == 1 ) {
hdf = hdWordValue;
if ( hdf != INT_TO_HD( 0 ) ) {
if ( hdExponent == INT_TO_HD( 0 ) )
{ hdExponent = hdf; }
else {
hdRemainder = RemInt( hdf, hdExponent );
while ( hdRemainder != INT_TO_HD( 0 ) ) {
hdf = hdExponent;
hdExponent = hdRemainder;
hdRemainder = RemInt( hdf, hdExponent );
}
}
}
}
}
}
}
ptNext = PTR( hdNext );
if ( firstFree == 0 ) {
firstFree      = firstCoinc;
lastFree       = firstCoinc;
}
else {
ptNext[lastFree] = INT_TO_HD( firstCoinc );
lastFree         = firstCoinc;
}
firstCoinc = HD_TO_INT( ptNext[firstCoinc] );
ptNext[lastFree] = INT_TO_HD( 0 );
nrdel++;
}
}
TypHandle       FunMakeConsequences2 ( hdCall )
TypHandle           hdCall;
{
TypHandle           hdList;
TypHandle           hdSubs;
TypHandle           hdRels;
TypHandle           * ptRel;
long                lp;
long                lc;
long                rp;
long                rc;
long                tc;
long                length;
TypHandle           hdnum;
TypHandle           hdrep;
long                rep;
long                i, j;
TypHandle           hdTmp;
hdList = EVAL( PTR(hdCall)[1] );
if ( (TYPE(hdList) != T_LIST && TYPE(hdList) != T_VECTOR)
|| HD_TO_INT( PTR( hdList )[0] ) != 16 )
return Error( "usage: MakeConsequences2( [ ... ] )", 0L, 0L );
hdTable   = PTR( hdList )[1];
hdTabl2   = PTR( hdList )[12];
hdTree    = PTR( hdList )[14];
hdTree1   = PTR( hdTree )[1];
hdTree2   = PTR( hdTree )[2];
treeType  = HD_TO_INT( PTR( hdTree )[5] );
treeWordLength = HD_TO_INT( PTR( hdList )[15] );
hdExponent = PTR( hdList )[16];
hdNext    = PTR( hdList )[2];
hdPrev    = PTR( hdList )[3];
hdFact    = PTR( hdList )[13];
firstFree = HD_TO_INT( PTR( hdList )[6] );
lastFree  = HD_TO_INT( PTR( hdList )[7] );
firstDef  = HD_TO_INT( PTR( hdList )[8] );
lastDef   = HD_TO_INT( PTR( hdList )[9] );
nrdel     = 0;
dedprint = 0;
dedfst = 0;
dedlst = 1;
dedgen[ 0 ] = HD_TO_INT( PTR( hdList )[10] );
dedcos[ 0 ] = HD_TO_INT( PTR( hdList )[11] );
while ( dedfst < dedlst ) {
hdTmp = PTR(hdTable)[dedgen[dedfst]];
hdTmp = PTR(hdTmp)[dedcos[dedfst]];
if ( HD_TO_INT(hdTmp) == 0 ) {
dedfst++;
continue;
}
hdSubs = PTR( hdList )[5];
for ( i = LEN_LIST( hdSubs ); 1 <= i; i-- ) {
if ( PTR(hdSubs)[i] != 0 ) {
hdNums = PTR( PTR( hdSubs )[i] )[1];
hdRel = PTR( PTR( hdSubs )[i] )[2];
ptRel = PTR( hdRel );
lp = 2;
lc = 1;
rp = LEN_LIST( hdRel ) - 1;
rc = 1;
while ( lp < rp && 0 < (tc = HD_TO_INT(PTR(ptRel[lp])[lc])) ) {
lc = tc;  lp = lp + 2;
}
while ( lp < rp && 0 < (tc = HD_TO_INT(PTR(ptRel[rp])[rc])) ) {
rc = tc;  rp = rp - 2;
}
if ( lp == rp+1 && HD_TO_INT(PTR(ptRel[lp])[lc]) != rc ) {
lp = 2;
lc = 1;
rp = LEN_LIST( hdRel ) - 1;
rc = 1;
InitializeCosetFactorWord( );
if ( treeType == 1 )
{
while ( lp < rp + 2 &&
0 < (tc = HD_TO_INT(PTR(PTR(hdRel)[lp])[lc])) ) {
hdrep = PTR(PTR(
hdTabl2)[HD_TO_INT(PTR(hdNums)[lp])])[lc];
if ( hdrep != INT_TO_HD( 0 ) )
SubtractCosetFactor( hdrep );
lc = tc;  lp = lp + 2;
}
if ( i != 0 )  { AddCosetFactor( INT_TO_HD( i ) ); }
while ( lp < rp + 2
&& 0 < (tc = HD_TO_INT(PTR(PTR(hdRel)[rp])[rc])) ) {
hdrep = PTR(PTR(
hdTabl2)[HD_TO_INT(PTR(hdNums)[rp])])[rc];
if ( hdrep != INT_TO_HD( 0 ) )
AddCosetFactor( hdrep );
rc = tc;  rp = rp - 2;
}
}
else if ( treeType == 0 )
{
while ( lp < rp + 2 &&
0 < (tc = HD_TO_INT(PTR(PTR(hdRel)[lp])[lc])) ) {
rep = HD_TO_INT(PTR(PTR(hdTabl2)[
HD_TO_INT(PTR(hdNums)[lp])])[lc] );
if ( rep != 0 ) AddCosetFactor2( - rep );
lc = tc;  lp = lp + 2;
}
if ( i != 0 ) AddCosetFactor2( i );
while ( lp < rp + 2
&& 0 < (tc = HD_TO_INT(PTR(PTR(hdRel)[rp])[rc])) ) {
rep = HD_TO_INT(PTR(PTR(hdTabl2)[
HD_TO_INT(PTR(hdNums)[rp])])[rc] );
if ( rep != 0 ) AddCosetFactor2( rep );
rc = tc;  rp = rp - 2;
}
}
else
{
while ( lp < rp + 2 &&
0 < (tc = HD_TO_INT(PTR(PTR(hdRel)[lp])[lc])) ) {
rep = HD_TO_INT(PTR(PTR(hdTabl2)[
HD_TO_INT(PTR(hdNums)[lp])])[lc] );
if ( rep != 0 ) AddCosetFactor2( rep );
lc = tc;  lp = lp + 2;
}
if ( wordList[0] > 0 ) {
length = wordList[0] + 1;
for ( j = length / 2; j > 0; j-- ) {
rep = wordList[j];
wordList[j] = - wordList[length-j];
wordList[length-j] = - rep;
}
}
if ( i != 0 ) AddCosetFactor2( i );
while ( lp < rp + 2
&& 0 < (tc = HD_TO_INT(PTR(PTR(hdRel)[rp])[rc])) ) {
rep = HD_TO_INT(PTR(PTR(hdTabl2)[
HD_TO_INT(PTR(hdNums)[rp])])[rc] );
if ( rep != 0 ) AddCosetFactor2( rep );
rc = tc;  rp = rp - 2;
}
}
hdnum = ( treeType == 1 ) ?
hdWordValue : INT_TO_HD( TreeEntryC( ) );
if ( lp >= rp + 2 ) {
HandleCoinc2( rc, lc, hdnum );
}
else {
PTR(PTR(hdRel)[lp])[lc] = INT_TO_HD( rc );
PTR(PTR(hdTabl2)[HD_TO_INT(PTR(hdNums)[lp])])[lc] =
hdnum;
PTR(PTR(hdRel)[rp])[rc] = INT_TO_HD( lc );
hdTmp = ( treeType == 1 ) ?
DiffInt( INT_TO_HD( 0 ), hdnum ) :
INT_TO_HD( - HD_TO_INT( hdnum ) );
PTR(PTR(hdTabl2)[HD_TO_INT(PTR(hdNums)[rp])])[rc] =
hdTmp;
if ( dedlst == dedSize ) CompressDeductionList( );
dedgen[ dedlst ] = HD_TO_INT( PTR(hdNums)[lp] );
dedcos[ dedlst ] = lc;
dedlst++;
}
PTR(hdSubs)[i] = 0;
if ( i == LEN_LIST( hdSubs ) ) {
while ( 0 < i  && PTR(hdSubs)[i] == 0 )
--i;
PTR( hdSubs )[0] = INT_TO_HD( i );
}
}
}
}
hdRels = PTR( PTR( hdList )[4] )[ dedgen[dedfst] ];
for ( i = 1; i <= LEN_LIST( hdRels ); i++ ) {
hdNums = PTR( PTR( hdRels )[i] )[1];
hdRel = PTR( PTR( hdRels )[i] )[2];
ptRel = PTR( hdRel );
lp = HD_TO_INT( PTR( PTR(hdRels)[i] )[3] );
lc = dedcos[ dedfst ];
rp = lp + HD_TO_INT( ptRel[1] );
rc = lc;
while ( lp < rp && 0 < (tc = HD_TO_INT(PTR(ptRel[lp])[lc])) ) {
lc = tc;  lp = lp + 2;
}
while ( lp < rp && 0 < (tc = HD_TO_INT(PTR(ptRel[rp])[rc])) ) {
rc = tc;  rp = rp - 2;
}
if ( lp == rp+1 && ( HD_TO_INT(PTR(ptRel[lp])[lc]) != rc
|| treeType == 1 ) ) {
lp = HD_TO_INT( PTR( PTR(hdRels)[i] )[3] );
lc = dedcos[ dedfst ];
rp = lp + HD_TO_INT( ptRel[1] );
rc = lc;
InitializeCosetFactorWord( );
if ( treeType == 1 )
{
while ( lp < rp + 2 && 0 < (tc = HD_TO_INT(
PTR(PTR(hdRel)[lp])[lc])) ) {
hdrep = PTR(PTR(hdTabl2)[
HD_TO_INT(PTR(hdNums)[lp])])[lc];
if ( hdrep != INT_TO_HD( 0 ) )
SubtractCosetFactor( hdrep );
lc = tc;  lp = lp + 2;
}
while ( lp < rp + 2
&& 0 < (tc = HD_TO_INT(PTR(PTR(hdRel)[rp])[rc])) ) {
hdrep = PTR(PTR(hdTabl2)[
HD_TO_INT(PTR(hdNums)[rp])])[rc];
if ( hdrep != INT_TO_HD( 0 ) )
AddCosetFactor( hdrep );
rc = tc;  rp = rp - 2;
}
}
else if ( treeType == 0 )
{
while ( lp < rp + 2 &&
0 < (tc = HD_TO_INT(PTR(PTR(hdRel)[lp])[lc])) ) {
rep = HD_TO_INT(PTR(PTR(hdTabl2)[
HD_TO_INT(PTR(hdNums)[lp])])[lc] );
if ( rep != 0 ) AddCosetFactor2( rep );
lc = tc;  lp = lp + 2;
}
while ( lp < rp + 2
&& 0 < (tc = HD_TO_INT(PTR(PTR(hdRel)[rp])[rc])) ) {
rep = HD_TO_INT(PTR(PTR(hdTabl2)[
HD_TO_INT(PTR(hdNums)[rp])])[rc] );
if ( rep != 0 ) AddCosetFactor2( rep );
rc = tc;  rp = rp - 2;
}
}
else
{
while ( lp < rp + 2 &&
0 < (tc = HD_TO_INT(PTR(PTR(hdRel)[lp])[lc])) ) {
rep = HD_TO_INT(PTR(PTR(hdTabl2)[
HD_TO_INT(PTR(hdNums)[lp])])[lc] );
if ( rep != 0 ) AddCosetFactor2( rep );
lc = tc;  lp = lp + 2;
}
if ( wordList[0] > 0 ) {
length = wordList[0] + 1;
for ( j = length / 2; j > 0; j-- ) {
rep = wordList[j];
wordList[j] = - wordList[length-j];
wordList[length-j] = - rep;
}
}
while ( lp < rp + 2
&& 0 < (tc = HD_TO_INT(PTR(PTR(hdRel)[rp])[rc])) ) {
rep = HD_TO_INT(PTR(PTR(hdTabl2)[
HD_TO_INT(PTR(hdNums)[rp])])[rc] );
if ( rep != 0 ) AddCosetFactor2( rep );
rc = tc;  rp = rp - 2;
}
}
hdnum = ( treeType == 1 ) ?
hdWordValue : INT_TO_HD( TreeEntryC( ) );
if ( lp >= rp + 2 ) {
HandleCoinc2( rc, lc, hdnum );
}
else {
PTR(PTR(hdRel)[lp])[lc] = INT_TO_HD( rc );
PTR(PTR(hdTabl2)[HD_TO_INT(PTR(hdNums)[lp])])[lc] =
hdnum;
PTR(PTR(hdRel)[rp])[rc] = INT_TO_HD( lc );
hdTmp = ( treeType == 1 ) ?
DiffInt( INT_TO_HD( 0 ), hdnum ) :
INT_TO_HD( - HD_TO_INT( hdnum ) );
PTR(PTR(hdTabl2)[HD_TO_INT(PTR(hdNums)[rp])])[rc] =
hdTmp;
if ( dedlst == dedSize ) CompressDeductionList( );
dedgen[ dedlst ] = HD_TO_INT( PTR(hdNums)[lp] );
dedcos[ dedlst ] = lc;
dedlst++;
}
}
}
dedfst++;
}
PTR(hdList)[6] = INT_TO_HD( firstFree );
PTR(hdList)[7] = INT_TO_HD( lastFree  );
PTR(hdList)[8] = INT_TO_HD( firstDef  );
PTR(hdList)[9] = INT_TO_HD( lastDef   );
if ( treeType == 1 )
PTR(hdList)[16] = hdExponent;
return INT_TO_HD( nrdel );
}
TypHandle       FunStandardizeTable2 ( hdCall )
TypHandle           hdCall;
{
unsigned long       nrgen;
TypHandle           * ptTable;
TypHandle           * ptTabl2;
TypHandle           * g;
TypHandle           * h,  * i;
TypHandle           * h2,  * i2;
unsigned long       acos;
unsigned long       lcos;
unsigned long       mcos;
unsigned long       c1, c2;
TypHandle           tmp;
unsigned long       j, k;
hdTable = EVAL( PTR( hdCall )[1] );
ptTable = PTR( hdTable );
hdTabl2 = EVAL( PTR( hdCall )[2] );
ptTabl2 = PTR( hdTabl2 );
nrgen = LEN_LIST( hdTable ) / 2;
acos = 1;
lcos = 1;
while ( acos <= lcos ) {
for ( j = 1; j <= nrgen; j++ ) {
g = PTR( ptTable[2*j-1] );
if ( lcos+1 < HD_TO_INT( g[acos] ) ) {
lcos = lcos + 1;
mcos = HD_TO_INT( g[acos] );
for ( k = 1; k <= nrgen; k++ ) {
h = PTR( ptTable[2*k-1] );
i = PTR( ptTable[2*k] );
h2 = PTR( ptTabl2[2*k-1] );
i2 = PTR( ptTabl2[2*k] );
c1 = HD_TO_INT( h[lcos] );
c2 = HD_TO_INT( h[mcos] );
if ( c1 != 0 )  i[c1] = INT_TO_HD( mcos );
if ( c2 != 0 )  i[c2] = INT_TO_HD( lcos );
tmp     = h[lcos];
h[lcos] = h[mcos];
h[mcos] = tmp;
tmp      = h2[lcos];
h2[lcos] = h2[mcos];
h2[mcos] = tmp;
if ( i != h ) {
c1 = HD_TO_INT( i[lcos] );
c2 = HD_TO_INT( i[mcos] );
if ( c1 != 0 )  h[c1] = INT_TO_HD( mcos );
if ( c2 != 0 )  h[c2] = INT_TO_HD( lcos );
tmp     = i[lcos];
i[lcos] = i[mcos];
i[mcos] = tmp;
tmp      = i2[lcos];
i2[lcos] = i2[mcos];
i2[mcos] = tmp;
}
}
}
else if ( lcos < HD_TO_INT( g[acos] ) ) {
lcos = lcos + 1;
}
}
acos = acos + 1;
}
for ( j = 1; j <= nrgen; j++ ) {
PTR(ptTable[2*j-1])[0] = INT_TO_HD( lcos );
PTR(ptTable[2*j  ])[0] = INT_TO_HD( lcos );
PTR(ptTabl2[2*j-1])[0] = INT_TO_HD( lcos );
PTR(ptTabl2[2*j  ])[0] = INT_TO_HD( lcos );
}
return HdVoid;
}
TypHandle       FunAddAbelianRelator ( hdCall )
TypHandle       hdCall;
{
TypHandle           hdRels;
TypHandle           * ptRels;
TypHandle           hdRows;
TypHandle           * pt1;
TypHandle           * pt2;
long                numcols;
long                numrows;
long                i, j;
if ( SIZE(hdCall) != 3*SIZE_HD )
return Error("usage: AddAbelianRelator( <rels>, <number> )", 0L, 0L);
hdRels = EVAL( PTR(hdCall)[1] );
if ( TYPE(hdRels) != T_LIST )
return Error( "invalid relators list", 0L, 0L );
ptRels = PTR( hdRels );
hdRows = EVAL( PTR(hdCall)[2] );
if ( TYPE(hdRows) != T_INT )
return Error( "invalid relator number", 0L, 0L );
numrows = HD_TO_INT( hdRows );
if ( numrows < 1 || LEN_LIST( hdRels ) < numrows )
return Error( "inconsistent relator number", 0L, 0L );
pt2 = PTR( ptRels[numrows] );
numcols = LEN_LIST( ptRels[numrows] );
for ( i = 1;  i <= numcols;  i++ )
{
if ( HD_TO_INT( pt2[i] ) ) break;
}
if ( i > numcols ) return INT_TO_HD( numrows - 1 );
if ( HD_TO_INT( pt2[i] ) < 0 )
{
for ( j = i;  j <= numcols;  j++ )
{
pt2[j] = INT_TO_HD( -HD_TO_INT( pt2[j] ) );
}
}
for ( i = 1;  i < numrows;  i++ )
{
pt1 = PTR( ptRels[i] );
for ( j = 1;  j <= numcols;  j++ )
{
if ( pt1[j] != pt2[j] ) break;
}
if ( j > numcols ) break;
}
if ( i < numrows )
{
for ( i = 1;  i <= numcols;  i++ )
{
pt2[i] = INT_TO_HD( 0 );
}
numrows = numrows - 1;
}
return INT_TO_HD( numrows );
}
void            InitCosTab ()
{
InstIntFunc( "ApplyRel",            FunApplyRel           );
InstIntFunc( "MakeConsequences",    FunMakeConsequences   );
InstIntFunc( "StandardizeTable",    FunStandardizeTable   );
InstIntFunc( "ApplyRel2",           FunApplyRel2          );
InstIntFunc( "CopyRel",             FunCopyRel            );
InstIntFunc( "MakeCanonical",       FunMakeCanonical      );
InstIntFunc( "TreeEntry",           FunTreeEntry          );
InstIntFunc( "MakeConsequences2",   FunMakeConsequences2  );
InstIntFunc( "StandardizeTable2",   FunStandardizeTable2  );
InstIntFunc( "AddAbelianRelator",   FunAddAbelianRelator  );
}
/* 当前文件是D:\Read\cyclotom.c*/

/* 当前文件是D:\Read\cyclotom.h*/

TypHandle       DiffCyc P(( TypHandle hdL, TypHandle hdR ));


void            ConvertToBase ( hdRes, n )
TypHandle           hdRes;
long                n;
{
TypHandle           * res;
long                nn;
long                p,  q;
long                i,  k,  l;
long                t;
long                sum;
res = PTR(hdRes);
nn  = n;
if ( nn % 2 == 0 ) {
q = 2;  while ( nn % (2*q) == 0 )  q = 2*q;
nn = nn / q;
for ( i = 0; i < n; i += q ) {
for ( k = n/2 + i; k < n; k += n/q ) {
if ( res[k] != INT_TO_HD(0) ) {
l = (k + n/2) % n;
sum = (long)res[l] - (long)res[k] + T_INT;
if ( (((long)res[k] & 3) != T_INT)
|| ((sum & 3) != T_INT) || (((sum<<1)>>1) != sum) ) {
sum = (long)DIFF( res[l], res[k] );
res = PTR(hdRes);
}
res[l] = (TypHandle)sum;
res[k] = INT_TO_HD(0);
}
}
for ( k = k - n; k < i; k += n/q ) {
if ( res[k] != INT_TO_HD(0) ) {
l = (k + n/2) % n;
sum = (long)res[l] - (long)res[k] + T_INT;
if ( (((long)res[k] & 3) != T_INT)
|| ((sum & 3) != T_INT) || (((sum<<1)>>1) != sum) ) {
sum = (long)DIFF( res[l], res[k] );
res = PTR(hdRes);
}
res[l] = (TypHandle)sum;
res[k] = INT_TO_HD(0);
}
}
}
}
for ( p = 3; p <= nn; p += 2 ) {
if ( nn % p != 0 )  continue;
q = p;  while ( nn % (p*q) == 0 )  q = p*q;
nn = nn / q;
for ( i = 0; i < n; i += q ) {
t = (n/p-n/q)/2;
k = n - t + i;
if ( n <= t + i ) { k = k - n; t = t - n; }
for ( ; k < n; k += n/q ) {
if ( res[k] != INT_TO_HD(0) ) {
for ( l = k+n/p; l < k+n; l += n/p ) {
sum = (long)res[l%n] - (long)res[k] + T_INT;
if ( (((long)res[k] & 3) != T_INT)
|| ((sum&3) != T_INT) || (((sum<<1)>>1) != sum) ) {
sum = (long)DIFF( res[l%n], res[k] );
res = PTR(hdRes);
}
res[l%n] = (TypHandle)sum;
}
res[k] = INT_TO_HD(0);
}
}
for ( k = k - n; k <= t + i; k += n/q ) {
if ( res[k] != INT_TO_HD(0) ) {
for ( l = k+n/p; l < k+n; l += n/p ) {
sum = (long)res[l%n] - (long)res[k] + T_INT;
if ( (((long)res[k] & 3) != T_INT)
|| ((sum&3) != T_INT) || (((sum<<1)>>1) != sum) ) {
sum = (long)DIFF( res[l%n], res[k] );
res = PTR(hdRes);
}
res[l%n] = (TypHandle)sum;
}
res[k] = INT_TO_HD(0);
}
}
}
}
}
TypHandle       Cyclotomic ( hdRes, n, m )
TypHandle           hdRes;
long                n,  m;
{
TypHandle           hdCyc;
long                len;
TypHandle           * cfs;
unsigned short      * exs;
TypHandle           * res;
long                gcd,  s,  t;
long                eql;
TypHandle           cof;
long                i,  k;
long                nn;
long                p;
static long         lastN;
static long         phi;
static long         isSqfree;
static long         nrp;
res = PTR(hdRes);
len = 0;
gcd = n;
eql = 1;
cof = 0;
for ( i = 0; i < n; i++ ) {
if ( res[i] != INT_TO_HD(0) ) {
len++;
if ( gcd != 1 ) {
s = i; while ( s != 0 ) { t = s; s = gcd % s; gcd = t; }
}
if ( eql && cof == 0 )
cof = res[i];
else if ( eql && cof != res[i] && EQ(cof,res[i]) == HdFalse )
eql = 0;
}
}
if ( 1 < gcd ) {
for ( i = 1; i < n/gcd; i++ ) {
res[i]     = res[i*gcd];
res[i*gcd] = INT_TO_HD(0);
}
n = n / gcd;
}
if ( n != lastN ) {
lastN = n;
phi = n;  k = n;
isSqfree = 1;
nrp = 0;
for ( p = 2; p <= k; p++ ) {
if ( k % p == 0 ) {
phi = phi * (p-1) / p;
if ( k % (p*p) == 0 )  isSqfree = 0;
nrp++;
while ( k % p == 0 )  k = k / p;
}
}
}
if ( len == phi && eql && isSqfree ) {
for ( i = 0; i < n; i++ )
res[i] = INT_TO_HD(0);
if ( nrp % 2 == 0 )
res[0] = cof;
else
res[0] = DIFF( INT_TO_HD(0), cof );
n = 1;
}
gcd = phi; s = len; while ( s != 0 ) { t = s; s = gcd % s; gcd = t; }
nn = n;
for ( p = 3; p <= nn && p-1 <= gcd; p += 2 ) {
if ( nn % p != 0 )  continue;
nn = nn / p;  while ( nn % p == 0 )  nn = nn / p;
if ( n % (p*p) != 0 && len % (p-1) == 0 && m % p != 0 ) {
eql = 1;
for ( i = 0; i < n && eql; i += p ) {
cof = res[(i+n/p)%n];
for ( k = i+2*n/p; k < i+n && eql; k += n/p )
if ( res[k%n] != cof && EQ(res[k%n],cof) != HdTrue )
eql = 0;
}
if ( eql ) {
for ( i = 0; i < n; i += p ) {
cof = res[(i+n/p)%n];
res[i] = INT_TO_HD( -HD_TO_INT(cof) );
if ( ((long)cof & 3) != T_INT
|| (cof == INT_TO_HD(-(1<<28))) ) {
cof = DIFF( INT_TO_HD(0), cof );
res = PTR(hdRes);
res[i] = cof;
}
for ( k = i+n/p; k < i+n && eql; k += n/p )
res[k%n] = INT_TO_HD(0);
}
len = len / (p-1);
for ( i = 1; i < n/p; i++ ) {
res[i]   = res[i*p];
res[i*p] = INT_TO_HD(0);
}
n = n / p;
}
}
}
if ( n == 1 ) {
hdCyc  = res[0];
res[0] = INT_TO_HD(0);
}
else {
hdCyc = NewBag( T_CYC, (len+1)*(SIZE_HD+sizeof(unsigned short)));
cfs = PTR(hdCyc);
exs = (unsigned short*)(PTR(hdCyc)+len+1);
cfs[0] = INT_TO_HD(n);
exs[0] = 0;
k = 1;
res = PTR(hdRes);
for ( i = 0; i < n; i++ ) {
if ( res[i] != INT_TO_HD(0) ) {
cfs[k] = res[i];
exs[k] = i;
k++;
res[i] = INT_TO_HD(0);
}
}
}
return hdCyc;
}
TypHandle       EvCyc ( hdCyc )
TypHandle           hdCyc;
{
return hdCyc;
}
TypHandle       SumCyc ( hdL, hdR )
TypHandle           hdL, hdR;
{
long                nl,  nr;
long                n,  m;
long                len;
TypHandle           * cfs;
unsigned short      * exs;
TypHandle           * res;
long                i;
long                sum;
TypHandle           hdT;
long                nl2, nr2;
if ( TYPE(hdL) != T_CYC || (TYPE(hdR)==T_CYC && SIZE(hdL)<SIZE(hdR)) ) {
hdT = hdL;  hdL = hdR;  hdR = hdT;
}
nl2 = nl = (TYPE(hdL) != T_CYC ? 1 : HD_TO_INT(PTR(hdL)[0]));
nr2 = nr = (TYPE(hdR) != T_CYC ? 1 : HD_TO_INT(PTR(hdR)[0]));
n  = nl;  while ( n % nr != 0 )  n += nl;
m  = nl2 / ( n / nr2 );
nl = n/nl;
nr = n/nr;
if ( SIZE(HdResult) < n * SIZE_HD ) {
Resize( HdResult, n * SIZE_HD );
for ( i = 0; i < n; i++ )  PTR(HdResult)[i] = INT_TO_HD(0);
}
if ( TYPE(hdL) != T_CYC ) {
PTR(HdResult)[ 0 ] = hdL;
}
else {
len = SIZE(hdL)/(SIZE_HD+sizeof(unsigned short));
cfs = PTR(hdL);
exs = (unsigned short*)(PTR(hdL)+len);
res = PTR(HdResult);
if ( nl == 1 ) {
for ( i = 1; i < len; i++ )
res[exs[i]] = cfs[i];
}
else {
for ( i = 1; i < len; i++ )
res[exs[i]*nl] = cfs[i];
}
}
if ( TYPE(hdR) != T_CYC ) {
sum = (long)SUM( PTR(HdResult)[0], hdR );
PTR(HdResult)[ 0 ] = (TypHandle)sum;
}
else {
len = SIZE(hdR)/(SIZE_HD+sizeof(unsigned short));
cfs = PTR(hdR);
exs = (unsigned short*)(PTR(hdR)+len);
res = PTR(HdResult);
for ( i = 1; i < len; i++ ) {
sum = (long)res[exs[i]*nr] + (long)cfs[i] - T_INT;
if ( ((sum & 3) != T_INT) || (((sum<<1)>>1) != sum) ) {
sum = (long)SUM( res[exs[i]*nr], cfs[i] );
cfs = PTR(hdR);
exs = (unsigned short*)(PTR(hdR)+len);
res = PTR(HdResult);
}
res[exs[i]*nr] = (TypHandle)sum;
}
}
if ( m % nl != 0 || m % nr != 0 )  ConvertToBase( HdResult, n );
return Cyclotomic( HdResult, n, n/m );
}
TypHandle       DiffCyc ( hdL, hdR )
TypHandle           hdL, hdR;
{
long                nl, nr;
long                n,  m;
long                len;
TypHandle           * cfs;
unsigned short      * exs;
TypHandle           * res;
long                i;
long                sum;
long                nl2, nr2;
nl2 = nl = (TYPE(hdL) != T_CYC ? 1 : HD_TO_INT(PTR(hdL)[0]));
nr2 = nr = (TYPE(hdR) != T_CYC ? 1 : HD_TO_INT(PTR(hdR)[0]));
n  = nl;  while ( n % nr != 0 )  n += nl;
m  = nl2 / ( n / nr2 );
nl = n/nl;
nr = n/nr;
if ( SIZE(HdResult) < n * SIZE_HD ) {
Resize( HdResult, n * SIZE_HD );
for ( i = 0; i < n; i++ )  PTR(HdResult)[i] = INT_TO_HD(0);
}
if ( TYPE(hdL) != T_CYC ) {
PTR(HdResult)[ 0 ] = hdL;
}
else {
len = SIZE(hdL)/(SIZE_HD+sizeof(unsigned short));
cfs = PTR(hdL);
exs = (unsigned short*)(PTR(hdL)+len);
res = PTR(HdResult);
if ( nl == 1 ) {
for ( i = 1; i < len; i++ )
res[exs[i]] = cfs[i];
}
else {
for ( i = 1; i < len; i++ )
res[exs[i]*nl] = cfs[i];
}
}
if ( TYPE(hdR) != T_CYC ) {
sum = (long)DIFF( PTR(HdResult)[0], hdR );
PTR(HdResult)[ 0 ] = (TypHandle)sum;
}
else {
len = SIZE(hdR)/(SIZE_HD+sizeof(unsigned short));
cfs = PTR(hdR);
exs = (unsigned short*)(PTR(hdR)+len);
res = PTR(HdResult);
for ( i = 1; i < len; i++ ) {
sum = (long)res[exs[i]*nr] - (long)cfs[i] + T_INT;
if ( (((long)cfs[i] & 3) != T_INT)
|| ((sum & 3) != T_INT) || (((sum<<1)>>1) != sum) ) {
sum = (long)DIFF( res[exs[i]*nr], cfs[i] );
cfs = PTR(hdR);
exs = (unsigned short*)(PTR(hdR)+len);
res = PTR(HdResult);
}
res[exs[i]*nr] = (TypHandle)sum;
}
}
if ( m % nl != 0 || m % nr != 0 )  ConvertToBase( HdResult, n );
return Cyclotomic( HdResult, n, n/m );
}
TypHandle       ProdCycI ( hdL, hdR )
TypHandle           hdL, hdR;
{
TypHandle           hdP;
long                len;
TypHandle           * cfs;
unsigned short      * exs;
TypHandle           * cfp;
unsigned short      * exp;
long                i;
long                prd;
if ( TYPE(hdL) != T_CYC && TYPE(hdR) != T_CYC ) {
return PROD( hdL, hdR );
}
if ( TYPE(hdL) != T_CYC ) { hdP = hdL;  hdL = hdR;  hdR = hdP; }
if ( hdR == INT_TO_HD(0) ) {
hdP = INT_TO_HD(0);
}
else if ( hdR == INT_TO_HD(1) ) {
hdP = hdL;
}
else if ( hdR == INT_TO_HD(-1) ) {
hdP = NewBag( T_CYC, SIZE(hdL) );
PTR(hdP)[0] = PTR(hdL)[0];
len = SIZE(hdL)/(SIZE_HD+sizeof(unsigned short));
cfs = PTR(hdL);
cfp = PTR(hdP);
exs = (unsigned short*)(PTR(hdL)+len);
exp = (unsigned short*)(PTR(hdP)+len);
for ( i = 1; i < len; i++ ) {
prd = -(long)cfs[i] + 2;
if ( (((long)cfs[i] & 3) != T_INT)
|| (cfs[i] == INT_TO_HD(-(1<<28))) ) {
prd = (long)PROD( cfs[i], INT_TO_HD(-1) );
cfs = PTR(hdL);
cfp = PTR(hdP);
exs = (unsigned short*)(PTR(hdL)+len);
exp = (unsigned short*)(PTR(hdP)+len);
}
cfp[i] = (TypHandle)prd;
exp[i] = exs[i];
}
}
else if ( TYPE(hdR) == T_INT ) {
hdP = NewBag( T_CYC, SIZE(hdL) );
PTR(hdP)[0] = PTR(hdL)[0];
len = SIZE(hdL)/(SIZE_HD+sizeof(unsigned short));
cfs = PTR(hdL);
cfp = PTR(hdP);
exs = (unsigned short*)(PTR(hdL)+len);
exp = (unsigned short*)(PTR(hdP)+len);
for ( i = 1; i < len; i++ ) {
prd = ((long)cfs[i] - T_INT) * ((long)hdR >> 1);
if ( (((long)cfs[i] & 3) != T_INT)
|| (prd / ((long)hdR >> 1) != ((long)cfs[i] - T_INT)) ) {
prd = (long)PROD( cfs[i], hdR );
cfs = PTR(hdL);
cfp = PTR(hdP);
exs = (unsigned short*)(PTR(hdL)+len);
exp = (unsigned short*)(PTR(hdP)+len);
}
else {
prd = (prd >> 1) + T_INT;
}
cfp[i] = (TypHandle)prd;
exp[i] = exs[i];
}
}
else {
hdP = NewBag( T_CYC, SIZE(hdL) );
PTR(hdP)[0] = PTR(hdL)[0];
len = SIZE(hdL)/(SIZE_HD+sizeof(unsigned short));
cfs = PTR(hdL);
cfp = PTR(hdP);
exs = (unsigned short*)(PTR(hdL)+len);
exp = (unsigned short*)(PTR(hdP)+len);
for ( i = 1; i < len; i++ ) {
prd = (long)PROD( cfs[i], hdR );
cfs = PTR(hdL);
cfp = PTR(hdP);
exs = (unsigned short*)(PTR(hdL)+len);
exp = (unsigned short*)(PTR(hdP)+len);
cfp[i] = (TypHandle)prd;
exp[i] = exs[i];
}
}
return hdP;
}
TypHandle       ProdCyc ( hdL, hdR )
TypHandle           hdL, hdR;
{
long                nl, nr;
long                n,  m;
TypHandle           c;
long                e;
long                len;
TypHandle           * cfs;
unsigned short      * exs;
TypHandle           * res;
long                i,  k;
long                sum;
long                prd;
TypHandle           hdT;
long                nl2, nr2;
if ( TYPE(hdL) != T_CYC || TYPE(hdR) != T_CYC ) {
return ProdCycI( hdL, hdR );
}
if ( SIZE(hdL) < SIZE(hdR) ) { hdT = hdL;  hdL = hdR;  hdR = hdT; }
nl2 = nl = (TYPE(hdL) != T_CYC ? 1 : HD_TO_INT(PTR(hdL)[0]));
nr2 = nr = (TYPE(hdR) != T_CYC ? 1 : HD_TO_INT(PTR(hdR)[0]));
n  = nl;  while ( n % nr != 0 )  n += nl;
m  = nl2 / ( n / nr2 );
nl = n/nl;
nr = n/nr;
if ( SIZE(HdResult) < n * SIZE_HD ) {
Resize( HdResult, n * SIZE_HD );
for ( i = 0; i < n; i++ )  PTR(HdResult)[i] = INT_TO_HD(0);
}
for ( k = 1; k < SIZE(hdR)/(SIZE_HD+sizeof(unsigned short)); k++ ) {
c = PTR(hdR)[k];
e = nr * ((unsigned short*)(PTR(hdR)
+SIZE(hdR)/(SIZE_HD+sizeof(unsigned short))))[k] % n;
if ( c == INT_TO_HD(1) ) {
len = SIZE(hdL)/(SIZE_HD+sizeof(unsigned short));
cfs = PTR(hdL);
exs = (unsigned short*)(PTR(hdL)+len);
res = PTR(HdResult);
for ( i = 1; i < len; i++ ) {
sum = (long)res[(e+exs[i]*nl)%n] + (long)cfs[i] - T_INT;
if ( ((sum & 3) != T_INT) || (((sum<<1)>>1) != sum) ) {
sum = (long)SUM( res[(e+exs[i]*nl)%n], cfs[i] );
cfs = PTR(hdL);
exs = (unsigned short*)(PTR(hdL)+len);
res = PTR(HdResult);
}
res[(e+exs[i]*nl)%n] = (TypHandle)sum;
}
}
else if ( c == INT_TO_HD(-1) ) {
len = SIZE(hdL)/(SIZE_HD+sizeof(unsigned short));
cfs = PTR(hdL);
exs = (unsigned short*)(PTR(hdL)+len);
res = PTR(HdResult);
for ( i = 1; i < len; i++ ) {
sum = (long)res[(e+exs[i]*nl)%n] - (long)cfs[i] + T_INT;
if ( (((long)cfs[i] & 3) != T_INT)
|| ((sum & 3) != T_INT) || (((sum<<1)>>1) != sum) ) {
sum = (long)DIFF( res[(e+exs[i]*nl)%n], cfs[i] );
cfs = PTR(hdL);
exs = (unsigned short*)(PTR(hdL)+len);
res = PTR(HdResult);
}
res[(e+exs[i]*nl)%n] = (TypHandle)sum;
}
}
else if ( TYPE(c) == T_INT ) {
len = SIZE(hdL)/(SIZE_HD+sizeof(unsigned short));
cfs = PTR(hdL);
exs = (unsigned short*)(PTR(hdL)+len);
res = PTR(HdResult);
for ( i = 1; i < len; i++ ) {
prd = ((long)cfs[i] - T_INT) * ((long)c >> 1);
sum = (long)res[(e+exs[i]*nl)%n] + (prd >> 1);
if ( (((long)cfs[i] & 3) != T_INT)
|| (prd / ((long)c >> 1) != ((long)cfs[i] - T_INT))
|| ((sum & 3) != T_INT) || (((sum<<1)>>1) != sum) ) {
prd = (long)PROD( c, cfs[i] );
exs = (unsigned short*)(PTR(hdL)+len);
res = PTR(HdResult);
sum = (long)SUM( res[(e+exs[i]*nl)%n], (TypHandle)prd );
cfs = PTR(hdL);
exs = (unsigned short*)(PTR(hdL)+len);
res = PTR(HdResult);
}
res[(e+exs[i]*nl)%n] = (TypHandle)sum;
}
}
else {
len = SIZE(hdL)/(SIZE_HD+sizeof(unsigned short));
for ( i = 1; i < len; i++ ) {
cfs = PTR(hdL);
prd = (long)PROD( c, cfs[i] );
exs = (unsigned short*)(PTR(hdL)+len);
res = PTR(HdResult);
sum = (long)SUM( res[(e+exs[i]*nl)%n], (TypHandle)prd );
exs = (unsigned short*)(PTR(hdL)+len);
res = PTR(HdResult);
res[(e+exs[i]*nl)%n] = (TypHandle)sum;
}
}
}
ConvertToBase( HdResult, n );
return Cyclotomic( HdResult, n, n/m );
}
TypHandle       QuoCyc ( hdL, hdR )
TypHandle           hdL, hdR;
{
long                n;
long                sqr;
long                len;
TypHandle           hdI;
long                i,  k;
long                gcd,  s,  t;
TypHandle           * cfs;
unsigned short      * exs;
TypHandle           * res;
if ( TYPE(hdR) != T_CYC ) {
hdI = QUO( INT_TO_HD(1), hdR );
}
else {
n   = HD_TO_INT( PTR(hdR)[0] );
for ( sqr = 2; sqr*sqr <= n && n % (sqr*sqr) != 0; sqr++ )
;
len = SIZE(hdR)/(SIZE_HD+sizeof(unsigned short));
hdI = INT_TO_HD(1);
for ( i = 2; i < n; i++ ) {
gcd = n; s = i; while ( s != 0 ) { t = s; s = gcd % s; gcd = t; }
if ( gcd == 1 ) {
cfs = PTR(hdR);
exs = (unsigned short*)(PTR(hdR)+len);
res = PTR(HdResult);
for ( k = 1; k < len; k++ )
res[i*exs[k]%n] = cfs[k];
if ( n < sqr*sqr ) {
hdI = ProdCyc( hdI, Cyclotomic( HdResult, n, n ) );
}
else {
ConvertToBase( HdResult, n );
hdI = ProdCyc( hdI, Cyclotomic( HdResult, n, 1 ) );
}
}
}
hdI = ProdCycI( hdI, QUO( INT_TO_HD(1), ProdCyc( hdR, hdI ) ) );
}
return ProdCyc( hdL, hdI );
}
TypHandle       PowCyc ( hdL, hdR )
TypHandle           hdL, hdR;
{
TypHandle           hdP;
long                exp;
long                n;
long                i;
exp = HD_TO_INT(hdR);
if ( exp == 0 ) {
hdP = INT_TO_HD(1);
}
else if ( exp == 1 ) {
hdP = hdL;
}
else if ( TYPE(hdL) != T_CYC ) {
hdP = PowInt( hdL, hdR );
}
else if ( hdL == PTR(CycLastE)[0] ) {
exp = (exp % CycLastN + CycLastN) % CycLastN;
PTR(HdResult)[ exp ] = INT_TO_HD(1);
ConvertToBase( HdResult, CycLastN );
hdP = Cyclotomic( HdResult, CycLastN, 1 );
}
else if ( SIZE(hdL) == 2*(SIZE_HD+sizeof(short)) ) {
n = HD_TO_INT(PTR(hdL)[0]);
hdP = POW( PTR(hdL)[1], hdR );
i = ((unsigned short*)(PTR(hdL)+2))[1];
PTR(HdResult)[(exp*i%n+n)%n] = hdP;
ConvertToBase( HdResult, n );
hdP = Cyclotomic( HdResult, n, 1 );
}
else {
if ( exp < 0 ) {
hdL = QuoCyc( INT_TO_HD(1), hdL );
exp = -exp;
}
hdP = INT_TO_HD(1);
while ( exp != 0 ) {
if ( exp % 2 == 1 )  hdP = ProdCyc( hdP, hdL );
if ( exp     >  1 )  hdL = ProdCyc( hdL, hdL );
exp = exp / 2;
}
}
return hdP;
}
TypHandle       EqCyc ( hdL, hdR )
TypHandle           hdL, hdR;
{
long                len;
TypHandle           * cfl;
unsigned short      * exl;
TypHandle           * cfr;
unsigned short      * exr;
long                i;
if ( PTR(hdL)[0] != PTR(hdR)[0] )
return HdFalse;
if ( SIZE(hdL) != SIZE(hdR) )
return HdFalse;
len = SIZE(hdL)/(SIZE_HD+sizeof(unsigned short));
cfl = PTR(hdL);
cfr = PTR(hdR);
exl = (unsigned short*)(PTR(hdL)+len);
exr = (unsigned short*)(PTR(hdR)+len);
for ( i = 1; i < len; i++ ) {
if ( exl[i] != exr[i] )
return HdFalse;
else if ( cfl[i] != cfr[i] && EQ(cfl[i],cfr[i]) == HdFalse )
return HdFalse;
}
return HdTrue;
}
TypHandle       LtCyc ( hdL, hdR )
TypHandle           hdL, hdR;
{
long                lel;
TypHandle           * cfl;
unsigned short      * exl;
long                ler;
TypHandle           * cfr;
unsigned short      * exr;
long                i;
if ( PTR(hdL)[0] != PTR(hdR)[0] )
if ( HD_TO_INT(PTR(hdL)[0]) < HD_TO_INT(PTR(hdR)[0]) )
return HdTrue;
else
return HdFalse;
lel = SIZE(hdL)/(SIZE_HD+sizeof(unsigned short));
ler = SIZE(hdR)/(SIZE_HD+sizeof(unsigned short));
cfl = PTR(hdL);
cfr = PTR(hdR);
exl = (unsigned short*)(PTR(hdL)+lel);
exr = (unsigned short*)(PTR(hdR)+ler);
for ( i = 1; i < lel && i < ler; i++ ) {
if ( exl[i] != exr[i] )
if ( exl[i] < exr[i] )
return LT( cfl[i], INT_TO_HD(0) );
else
return LT( INT_TO_HD(0), cfr[i] );
else if ( cfl[i] != cfr[i] && EQ(cfl[i],cfr[i]) == HdFalse )
return LT( cfl[i], cfr[i] );
}
if ( lel < ler )
return LT( INT_TO_HD(0), cfr[i] );
else if ( ler < lel )
return LT( cfl[i], INT_TO_HD(0) );
else
return HdFalse;
}
void            PrCyc ( hdCyc )
TypHandle           hdCyc;
{
long                n;
long                len;
TypHandle           * cfs;
unsigned short      * exs;
long                i;
n   = HD_TO_INT( PTR(hdCyc)[0] );
len = SIZE(hdCyc)/(SIZE_HD+sizeof(unsigned short));
cfs = PTR(hdCyc);
exs = (unsigned short*)(PTR(hdCyc)+len);
Pr("%>",0L,0L);
for ( i = 1; i < len; i++ ) {
if (      cfs[i]==INT_TO_HD(1)            && exs[i]==0 )
Pr("1",0L,0L);
else if ( cfs[i]==INT_TO_HD(1)            && exs[i]==1 && i==1 )
Pr("%>E(%d%<)",n,0L);
else if ( cfs[i]==INT_TO_HD(1)            && exs[i]==1 )
Pr("%>+E(%d%<)",n,0L);
else if ( cfs[i]==INT_TO_HD(1)                         && i==1 )
Pr("%>E(%d)%>^%2<%d",n,(long)exs[i]);
else if ( cfs[i]==INT_TO_HD(1) )
Pr("%>+E(%d)%>^%2<%d",n,(long)exs[i]);
else if ( LT(INT_TO_HD(0),cfs[i])==HdTrue && exs[i]==0 )
Print(cfs[i]);
else if ( LT(INT_TO_HD(0),cfs[i])==HdTrue && exs[i]==1 && i==1 ) {
Pr("%>",0L,0L); Print(cfs[i]); Pr("%>*%<E(%d%<)",n,0L); }
else if ( LT(INT_TO_HD(0),cfs[i])==HdTrue && exs[i]==1 ) {
Pr("%>+",0L,0L); Print(cfs[i]); Pr("%>*%<E(%d%<)",n,0L); }
else if ( LT(INT_TO_HD(0),cfs[i])==HdTrue              && i==1 ) {
Pr("%>",0L,0L); Print(cfs[i]);
Pr("%>*%<E(%d)%>^%2<%d",n,(long)exs[i]); }
else if ( LT(INT_TO_HD(0),cfs[i])==HdTrue ) {
Pr("%>+",0L,0L); Print(cfs[i]);
Pr("%>*%<E(%d)%>^%2<%d",n,(long)exs[i]); }
else if ( cfs[i]==INT_TO_HD(-1)           && exs[i]==0 )
Pr("%>-%<1",0L,0L);
else if ( cfs[i]==INT_TO_HD(-1)           && exs[i]==1 )
Pr("%>-E(%d%<)",n,0L);
else if ( cfs[i]==INT_TO_HD(-1) )
Pr("%>-E(%d)%>^%2<%d",n,(long)exs[i]);
else if (                                    exs[i]==0 )
Print(cfs[i]);
else if (                                    exs[i]==1 ) {
Pr("%>",0L,0L); Print(cfs[i]); Pr("%>*%<E(%d%<)",n,0L); }
else {
Pr("%>",0L,0L); Print(cfs[i]);
Pr("%>*%<E(%d)%>^%2<%d",n,(long)exs[i]); }
}
Pr("%<",0L,0L);
}
TypHandle       FunE ( hdCall )
TypHandle           hdCall;
{
long                i;
if ( SIZE(hdCall) != 2*SIZE_HD )
return Error("usage: E(<n>)",0L,0L);
hdCall = EVAL(PTR(hdCall)[1]);
if ( TYPE(hdCall) != T_INT || HD_TO_INT(hdCall) <= 0 )
return Error("E: <n> must be a positive integer",0L,0L);
if ( hdCall == INT_TO_HD(1) )
return INT_TO_HD(1);
else if ( hdCall == INT_TO_HD(2) )
return INT_TO_HD(-1);
if ( CycLastN != HD_TO_INT(hdCall) ) {
CycLastN = HD_TO_INT(hdCall);
if ( SIZE(HdResult) < CycLastN * SIZE_HD ) {
Resize( HdResult, CycLastN * SIZE_HD );
for ( i = 0; i < CycLastN; i++ )  PTR(HdResult)[i]=INT_TO_HD(0);
}
PTR(HdResult)[1] = INT_TO_HD(1);
ConvertToBase( HdResult, CycLastN );
PTR(CycLastE)[0] = Cyclotomic( HdResult, CycLastN, 1 );
}
return PTR(CycLastE)[0];
}
TypHandle       FunIsCyc ( hdCall )
TypHandle           hdCall;
{
TypHandle           hdObj;
if ( SIZE(hdCall) != 2 * SIZE_HD )
return Error("usage: IsCyc( <obj> )",0L,0L);
hdObj = EVAL( PTR(hdCall)[1] );
if ( hdObj == HdVoid )
return Error("IsCyc: function must return a value",0L,0L);
if ( TYPE(hdObj) == T_CYC
|| TYPE(hdObj) == T_INT    || TYPE(hdObj) == T_RAT
|| TYPE(hdObj) == T_INTPOS || TYPE(hdObj) == T_INTNEG )
return HdTrue;
else
return HdFalse;
}
TypHandle       FunIsCycInt ( hdCall )
TypHandle           hdCall;
{
TypHandle           hdObj;
long                len;
TypHandle           * cfs;
long                i;
if ( SIZE(hdCall) != 2 * SIZE_HD )
return Error("usage: IsCycInt( <obj> )",0L,0L);
hdObj = EVAL( PTR(hdCall)[1] );
if ( hdObj == HdVoid )
return Error("IsCycInt: function must return a value",0L,0L);
if ( TYPE(hdObj) == T_INT
|| TYPE(hdObj) == T_INTPOS || TYPE(hdObj) == T_INTNEG ) {
return HdTrue;
}
else if ( TYPE(hdObj) == T_RAT ) {
return HdFalse;
}
else if ( TYPE(hdObj) == T_CYC ) {
len = SIZE(hdObj)/(SIZE_HD+sizeof(unsigned short));
cfs = PTR(hdObj);
for ( i = 1; i < len; i++ ) {
if ( TYPE(cfs[i]) == T_RAT )
return HdFalse;
}
return HdTrue;
}
else {
return HdFalse;
}
}
TypHandle       FunNofCyc ( hdCall )
TypHandle           hdCall;
{
TypHandle           hdCyc;
TypHandle           hdList;
unsigned long       n;
unsigned long       m;
unsigned long       gcd, s, t;
unsigned long       i;
if ( SIZE(hdCall) != 2 * SIZE_HD )
return Error("usage: NofCyc( <cyc> )",0L,0L);
hdCyc = EVAL( PTR(hdCall)[1] );
if ( TYPE(hdCyc) != T_INT    && TYPE(hdCyc) != T_RAT
&& TYPE(hdCyc) != T_INTPOS && TYPE(hdCyc) != T_INTNEG
&& TYPE(hdCyc) != T_CYC    && TYPE(hdCyc) != T_LIST
&& TYPE(hdCyc) != T_SET    && TYPE(hdCyc) != T_VECTOR )
return Error("NofCyc: <cyc> must be a cyclotomic or a list",0L,0L);
if ( TYPE(hdCyc) == T_INT    || TYPE(hdCyc) == T_RAT
|| TYPE(hdCyc) == T_INTPOS || TYPE(hdCyc) == T_INTNEG ) {
n = 1;
}
else if ( TYPE(hdCyc) == T_CYC ) {
n = HD_TO_INT( PTR(hdCyc)[0] );
}
else {
hdList = hdCyc;
n = 1;
for ( i = 1; i <= LEN_LIST( hdList ); i++ ) {
hdCyc = ELM_LIST( hdList, i );
if ( TYPE(hdCyc) == T_INT    || TYPE(hdCyc) == T_RAT
|| TYPE(hdCyc) == T_INTPOS || TYPE(hdCyc) == T_INTNEG )
m = 1;
else if ( TYPE(hdCyc) == T_CYC )
m = HD_TO_INT( PTR(hdCyc)[0] );
else
return Error("NofCyc: <list>[%d] must be a cyclotomic",
(long)i,0L);
gcd = n; s = m; while ( s != 0 ) { t = s; s = gcd % s; gcd = t; }
n = n / gcd * m;
}
}
return INT_TO_HD(n);
}
TypHandle       FunCoeffsCyc ( hdCall )
TypHandle           hdCall;
{
TypHandle           hdCyc;
TypHandle           hdList;
long                n;
long                len;
TypHandle           * cfs;
unsigned short      * exs;
TypHandle           * res;
long                i;
if ( SIZE(hdCall) != 2*SIZE_HD )
return Error("usage: COEFFSCYC( <cyc> )",0L,0L);
hdCyc = EVAL( PTR(hdCall)[1] );
if ( TYPE(hdCyc) != T_INT    && TYPE(hdCyc) != T_RAT
&& TYPE(hdCyc) != T_INTPOS && TYPE(hdCyc) != T_INTNEG
&& TYPE(hdCyc) != T_CYC )
return Error("COEFFSCYC: <cyc> must be a cyclotomic",0L,0L);
if ( TYPE(hdCyc) == T_INT    || TYPE(hdCyc) == T_RAT
|| TYPE(hdCyc) == T_INTPOS || TYPE(hdCyc) == T_INTNEG ) {
hdList = NewBag( T_LIST, SIZE_HD+SIZE_HD );
PTR(hdList)[0] = INT_TO_HD(1);
PTR(hdList)[1] = hdCyc;
}
else {
n = HD_TO_INT( PTR(hdCyc)[0] );
hdList = NewBag( T_LIST, (n+1)*SIZE_HD );
PTR(hdList)[0] = INT_TO_HD(n);
len = SIZE(hdCyc)/(SIZE_HD+sizeof(unsigned short));
cfs = PTR(hdCyc);
exs = (unsigned short*)(PTR(hdCyc)+len);
res = PTR(hdList) + 1;
for ( i = 0; i < n; i++ )
res[i] = INT_TO_HD(0);
for ( i = 1; i < len; i++ )
res[exs[i]] = cfs[i];
}
return hdList;
}
TypHandle       FunGaloisCyc ( hdCall )
TypHandle           hdCall;
{
TypHandle           hdG;
long                n;
long                sqr;
long                ord;
long                gcd,  s,  t;
TypHandle           hdCyc;
long                len;
TypHandle           * cfs;
unsigned short      * exs;
TypHandle           * res;
long                i;
long                sum;
if ( SIZE(hdCall) != 3*SIZE_HD )
return Error("usage: GaloisCyc( <cyc>, <ord> )",0L,0L);
hdCyc = EVAL( PTR(hdCall)[2] );
if ( TYPE(hdCyc) != T_INT )
return Error("GaloisCyc: <ord> must be an integer",0L,0L);
ord = HD_TO_INT(hdCyc);
hdCyc = EVAL( PTR(hdCall)[1] );
if ( TYPE(hdCyc) != T_INT    && TYPE(hdCyc) != T_RAT
&& TYPE(hdCyc) != T_INTPOS && TYPE(hdCyc) != T_INTNEG
&& TYPE(hdCyc) != T_CYC )
return Error("GaloisCyc: <cyc> must be a cyclotomic",0L,0L);
if ( TYPE(hdCyc) == T_INT    || TYPE(hdCyc) == T_RAT
|| TYPE(hdCyc) == T_INTPOS || TYPE(hdCyc) == T_INTNEG )
return hdCyc;
n = HD_TO_INT( PTR(hdCyc)[0] );
for ( sqr = 2; sqr*sqr <= n && n % (sqr*sqr) != 0; sqr++ )
;
ord = (ord % n + n) % n;
gcd = n; s = ord;  while ( s != 0 ) { t = s; s = gcd % s; gcd = t; }
if ( ord == 1 ) {
hdG = hdCyc;
}
else if ( ord == 0 ) {
len = SIZE(hdCyc)/(SIZE_HD+sizeof(unsigned short));
cfs = PTR(hdCyc);
hdG = INT_TO_HD(0);
for ( i = 1; i < len; i++ ) {
sum = (long)hdG + (long)cfs[i] - T_INT;
if ( ((sum & 3) != T_INT) || (((sum<<1)>>1) != sum) ) {
sum = (long)SUM( (TypHandle)hdG, cfs[i] );
cfs = PTR(hdCyc);
}
hdG = (TypHandle)sum;
}
}
else if ( n % 2 == 0  && ord == n/2 ) {
hdG = INT_TO_HD(0);
len = SIZE(hdCyc)/(SIZE_HD+sizeof(unsigned short));
cfs = PTR(hdCyc);
exs = (unsigned short*)(PTR(hdCyc)+len);
for ( i = 1; i < len; i++ ) {
if ( exs[i] % 2 == 1 ) {
sum = (long)hdG - (long)cfs[i] + T_INT;
if ( (((long)hdG & 3) != T_INT )
|| ((sum & 3) != T_INT) || (((sum<<1)>>1) != T_INT) ) {
sum = (long)DIFF( hdG, cfs[i] );
cfs = PTR(hdCyc);
exs = (unsigned short*)(PTR(hdCyc)+len);
}
hdG = (TypHandle)sum;
}
else {
sum = (long)hdG + (long)cfs[i] - T_INT;
if ( (((long)sum&3) != T_INT) || (((sum<<1)>>1) != T_INT) ) {
sum = (long)SUM( hdG, cfs[i] );
cfs = PTR(hdCyc);
exs = (unsigned short*)(PTR(hdCyc)+len);
}
hdG = (TypHandle)sum;
}
}
}
else if ( gcd == 1 ) {
len = SIZE(hdCyc)/(SIZE_HD+sizeof(unsigned short));
cfs = PTR(hdCyc);
exs = (unsigned short*)(PTR(hdCyc)+len);
res = PTR(HdResult);
for ( i = 1; i < len; i++ ) {
res[exs[i]*ord%n] = cfs[i];
}
if ( n < sqr*sqr || (ord == n-1 && n % 2 != 0) ) {
hdG = Cyclotomic( HdResult, n, n );
}
else {
ConvertToBase( HdResult, n );
hdG = Cyclotomic( HdResult, n, 1 );
}
}
else {
len = SIZE(hdCyc)/(SIZE_HD+sizeof(unsigned short));
cfs = PTR(hdCyc);
exs = (unsigned short*)(PTR(hdCyc)+len);
res = PTR(HdResult);
for ( i = 1; i < len; i++ ) {
sum = (long)res[exs[i]*ord%n] + (long)cfs[i] - T_INT;
if ( ((sum & 3) != T_INT) || (((sum<<1)>>1) != sum) ) {
sum = (long)SUM( res[exs[i]*ord%n], cfs[i] );
cfs = PTR(hdCyc);
exs = (unsigned short*)(PTR(hdCyc)+len);
res = PTR(HdResult);
}
res[exs[i]*ord%n] = (TypHandle)sum;
}
if ( n < sqr*sqr ) {
hdG = Cyclotomic( HdResult, n, 1 );
}
else {
ConvertToBase( HdResult, n );
hdG = Cyclotomic( HdResult, n, 1 );
}
}
return hdG;
}
TypHandle       IsTrue ( hdL, hdR )
TypHandle           hdL, hdR;
{
return HdTrue;
}
TypHandle       IsFalse ( hdL, hdR )
TypHandle           hdL, hdR;
{
return HdFalse;
}

/* 当前文件是D:\Read\eval.c*/

/* 当前文件是D:\Read\rational.h*/

TypHandle       EvRat P(( TypHandle hdRat ));
TypHandle       SumRat P(( TypHandle hdL, TypHandle hdR ));
TypHandle       DiffRat P(( TypHandle hdL, TypHandle hdR ));
TypHandle       ProdRat P(( TypHandle hdL, TypHandle hdR ));
TypHandle       QuoRat P(( TypHandle hdL, TypHandle hdR ));
TypHandle       ModRat P(( TypHandle hdL, TypHandle hdR ));
TypHandle       PowRat P(( TypHandle hdL, TypHandle hdR ));
TypHandle       EqRat P(( TypHandle hdL, TypHandle hdR ));
TypHandle       LtRat P(( TypHandle hdL, TypHandle hdR ));
void            PrRat P(( TypHandle hdRat ));
TypHandle       FunIsRat P(( TypHandle hdCall ));
TypHandle       FunNumerator P(( TypHandle hdCall ));
TypHandle       FunDenominator P(( TypHandle hdCall ));
void            InitRat P(( void ));
/* 当前文件是D:\Read\unknown.h*/
/* 当前文件是D:\Read\polynom.h*/

#ifdef SPEC_CPU2000_P64
#define long __int64
#endif

#define ADD_COEFFS( hdL, hdR, hdM ) \
(TabAddCoeffs[XType(hdL)][XType(hdR)]( hdL, hdR, hdM ))

#define MULTIPLY_COEFFS(hdP,hdL,l,hdR,r) \
(TabMultiplyCoeffs[XType(hdL)][XType(hdR)](hdP,hdL,l,hdR,r))

#define REDUCE_COEFFS( hdL, l, hdR, r ) \
(TabReduceCoeffs[XType(hdL)][XType(hdR)]( hdL, l, hdR, r ))

#define REDUCE_COEFFS_MOD( hdL, l, hdR, r ) \
(TabReduceCoeffsMod[XType(hdL)][XType(hdR)]( hdL, l, hdR, r, hdN ))

/* 当前文件是D:\Read\pcpresen.h*/

#ifndef     PCP_DEBUG
#   define  PCP_DEBUG       0
#endif
#ifndef boolean
#define boolean         int
#endif

/* 当前文件是D:\Read\vector.h*/

#ifdef SPEC_CPU2000_P64
#define long __int64
#endif

TypHandle       CantEval ( hd )
TypHandle           hd;
{
return Error("Panic: can't eval bag of type %d",(long)TYPE(hd),0L);
}

TypHandle       Sum ( hd )
TypHandle           hd;
{
TypHandle           hdL,  hdR;
long                result;
int                 ov;
hdL = EVAL( PTR(hd)[0] );  hdR = EVAL( PTR(hd)[1] );
if ( (long)hdL & (long)hdR & T_INT ) {
result = (long)hdL + (long)hdR - T_INT;
ov = (int)result;
if ( ((ov << 1) >> 1) == ov )
return (TypHandle)ov;
}
return SUM( hdL, hdR );
}
TypHandle       CantSum ( hdL, hdR )
TypHandle           hdL;
TypHandle           hdR;
{
return Error("operations: sum of %s and %s is not defined",
(long)NameType[TYPE(hdL)], (long)NameType[TYPE(hdR)] );
}

TypHandle       Diff ( hd )
TypHandle           hd;
{
TypHandle           hdL,  hdR;
long                result;
int                 ov;
hdL = EVAL( PTR(hd)[0] );  hdR = EVAL( PTR(hd)[1] );
if ( (long)hdL & (long)hdR & T_INT ) {
result = (long)hdL - (long)hdR;
ov = (int)result;
if ( ((ov << 1) >> 1) == ov )
return (TypHandle)(ov + T_INT);
}
return DIFF(hdL,hdR);
}
TypHandle       CantDiff ( hdL, hdR )
TypHandle           hdL;
TypHandle           hdR;
{
return Error("operations difference of %s and %s is not defined",
(long)NameType[TYPE(hdL)], (long)NameType[TYPE(hdR)] );
}

TypHandle       Prod ( hd )
TypHandle           hd;
{
TypHandle           hdL,  hdR;
long                result;
int                 ov;
hdL = EVAL( PTR(hd)[0] );  hdR = EVAL( PTR(hd)[1] );
if ( (long)hdL & (long)hdR & T_INT ) {
result = ((long)hdL - 1) * ((long)hdR >> 1);
ov = (int)result;
if ( ((long)hdR >> 1) == 0
|| ov / ((long)hdR >> 1) == ((long)hdL - 1) )
return (TypHandle)((ov >> 1) + T_INT);
}
return PROD( hdL, hdR );
}
TypHandle       CantProd ( hdL, hdR )
TypHandle           hdL;
TypHandle           hdR;
{
return Error("operations: product of %s and %s is not defined",
(long)NameType[TYPE(hdL)], (long)NameType[TYPE(hdR)] );
}

TypHandle       Quo ( hd )
TypHandle           hd;
{
TypHandle           hdL,  hdR;
hdL = EVAL( PTR(hd)[0] );  hdR = EVAL( PTR(hd)[1] );
return QUO( hdL, hdR );
}
TypHandle       CantQuo ( hdL, hdR )
TypHandle           hdL;
TypHandle           hdR;
{
return Error("operations: quotient of %s and %s is not defined",
(long)NameType[TYPE(hdL)], (long)NameType[TYPE(hdR)] );
}

TypHandle       Mod ( hd )
TypHandle           hd;
{
TypHandle           hdL,  hdR;
hdL = EVAL( PTR(hd)[0] );  hdR = EVAL( PTR(hd)[1] );
return MOD( hdL, hdR );
}
TypHandle       CantMod ( hdL, hdR )
TypHandle           hdL;
TypHandle           hdR;
{
return Error("operations: remainder of %s and %s is not defined",
(long)NameType[TYPE(hdL)], (long)NameType[TYPE(hdR)] );
}

TypHandle       Pow ( hd )
TypHandle           hd;
{
TypHandle           hdL,  hdR;
hdL = EVAL( PTR(hd)[0] );  hdR = EVAL( PTR(hd)[1] );
return POW( hdL, hdR );
}
TypHandle       CantPow ( hdL, hdR )
TypHandle           hdL;
TypHandle           hdR;
{
return Error("operations: power of %s and %s is not defined",
(long)NameType[TYPE(hdL)], (long)NameType[TYPE(hdR)] );
}

TypHandle       IntComm ( hdCall )
TypHandle       hdCall;
{
TypHandle       hdL, hdR;
if ( SIZE(hdCall) != 3 * SIZE_HD )
return Error("usage: Comm( <expr>, <expr> )",0L,0L);
hdL = EVAL( PTR(hdCall)[1] );  hdR = EVAL( PTR(hdCall)[2] );
return (* TabComm[ TYPE(hdL) ][ TYPE(hdR) ]) ( hdL, hdR );
}
TypHandle       CantComm ( hdL, hdR )
TypHandle           hdL;
TypHandle           hdR;
{
return Error("operations: commutator of %s and %s is not defined",
(long)NameType[TYPE(hdL)], (long)NameType[TYPE(hdR)] );
}
TypHandle       FunLeftQuotient ( hdCall )
TypHandle       hdCall;
{
TypHandle       hdL, hdR;
if ( SIZE( hdCall ) != 3 * SIZE_HD )
return Error( "usage: LeftQuotient( <expr>, <expr> )", 0L, 0L );
hdL = EVAL( PTR( hdCall )[ 1 ] );
hdR = EVAL( PTR( hdCall )[ 2 ] );
return ( * TabMod[ TYPE(hdL) ][ TYPE(hdR) ] ) ( hdL, hdR );
}

TypHandle       Eq ( hd )
TypHandle           hd;
{
TypHandle           hdL,  hdR;
hdL = EVAL( PTR(hd)[0] );  hdR = EVAL( PTR(hd)[1] );
if ( hdL == hdR )
return HdTrue;
if ( ((long)hdL & (long)hdR & T_INT) ) {
if ( HD_TO_INT(hdL) == HD_TO_INT(hdR) )  return HdTrue;
else                                     return HdFalse;
}
return EQ( hdL, hdR );
}

TypHandle       Lt ( hd )
TypHandle           hd;
{
TypHandle           hdL,  hdR;
hdL = EVAL( PTR(hd)[0] );  hdR = EVAL( PTR(hd)[1] );
if ( hdL == hdR )
return HdFalse;
if ( ((long)hdL & (long)hdR & T_INT) ) {
if ( HD_TO_INT(hdL) < HD_TO_INT(hdR) )  return HdTrue;
else                                    return HdFalse;
}
return LT( hdL, hdR );
}
TypHandle       Ne ( hd )
TypHandle           hd;
{
TypHandle           hdL,  hdR;
hdL = EVAL( PTR(hd)[0] );  hdR = EVAL( PTR(hd)[1] );
if ( hdL == hdR )
return HdFalse;
if ( ((long)hdL & (long)hdR & T_INT) ) {
if ( HD_TO_INT(hdL) != HD_TO_INT(hdR) )  return HdTrue;
else                                     return HdFalse;
}
if ( EQ(hdL,hdR) == HdTrue )  hdL = HdFalse;
else                          hdL = HdTrue;
return hdL;
}
TypHandle       Le ( hd )
TypHandle           hd;
{
TypHandle           hdL,  hdR;
hdL = EVAL( PTR(hd)[0] );  hdR = EVAL( PTR(hd)[1] );
if ( hdL == hdR )
return HdTrue;
if ( ((long)hdL & (long)hdR & T_INT) ) {
if ( HD_TO_INT(hdL) <= HD_TO_INT(hdR) )  return HdTrue;
else                                     return HdFalse;
}
if ( LT( hdR, hdL ) == HdTrue )  hdL = HdFalse;
else                             hdL = HdTrue;
return hdL;
}
TypHandle       Gt ( hd )
TypHandle           hd;
{
TypHandle    hdL,  hdR;
hdL = EVAL( PTR(hd)[0] );  hdR = EVAL( PTR(hd)[1] );
if ( hdL == hdR )
return HdFalse;
if ( ((long)hdL & (long)hdR & T_INT) ) {
if ( HD_TO_INT(hdL) >  HD_TO_INT(hdR) )  return HdTrue;
else                                     return HdFalse;
}
return LT( hdR, hdL );
}
TypHandle       Ge ( hd )
TypHandle           hd;
{
TypHandle           hdL,  hdR;
hdL = EVAL( PTR(hd)[0] );  hdR = EVAL( PTR(hd)[1] );
if ( hdL == hdR )
return HdTrue;
if ( ((long)hdL & (long)hdR & T_INT) ) {
if ( HD_TO_INT(hdL) >= HD_TO_INT(hdR) )  return HdTrue;
else                                     return HdFalse;
}
if ( LT( hdL, hdR ) == HdTrue )  hdL = HdFalse;
else                             hdL = HdTrue;
return hdL;
}

TypHandle       EvVar ( hdVar )
TypHandle           hdVar;
{
if ( PTR(hdVar)[0] == 0 )
return Error("Variable: '%s' must have a value",
(long)(PTR(hdVar)+1), 0L );
return PTR(hdVar)[0];
}
TypHandle       EvVarAuto ( hdVar )
TypHandle           hdVar;
{
TypHandle           ignore;
if ( T_VAR <= TYPE( PTR(hdVar)[0] ) ) {
ignore = EVAL( PTR(hdVar)[0] );
if ( T_VAR <= TYPE( PTR(hdVar)[0] ) ) {
return Error("AUTO: '%s' must be defined by the evaluation",
(long)(PTR(hdVar)+1), 0L );
}
}
Retype( hdVar, T_VAR );
return PTR(hdVar)[0];
}
TypHandle       EvVarAss ( hdAss )
TypHandle           hdAss;
{
TypHandle           hdVal;
hdVal = EVAL( PTR(hdAss)[1] );
if ( hdVal == HdVoid )
return Error("Assignment: function must return a value",0L,0L);
PTR( PTR(hdAss)[0] )[0] = hdVal;
return hdVal;
}
TypHandle       EvBool ( hdBool )
TypHandle           hdBool;
{
return hdBool;
}
TypHandle       EvNot ( hdBool )
TypHandle           hdBool;
{
hdBool = EVAL( PTR(hdBool)[0] );
if ( hdBool == HdTrue )
return HdFalse;
else if ( hdBool == HdFalse )
return HdTrue;
else
return Error("not: <expr> must evaluate to 'true' or 'false'",0L,0L);
}
TypHandle       EvAnd ( hd )
TypHandle           hd;
{
TypHandle           hd1;
hd1 = EVAL( PTR(hd)[0] );
if ( hd1 == HdFalse )
return HdFalse;
else if ( hd1 != HdTrue )
return Error("and: <expr> must evaluate to 'true' or 'false'",0L,0L);
hd1 = EVAL( PTR(hd)[1] );
if ( hd1 == HdFalse )
return HdFalse;
else if ( hd1 != HdTrue )
return Error("and: <expr> must evaluate to 'true' or 'false'",0L,0L);
return HdTrue;
}
TypHandle       EvOr ( hd )
TypHandle           hd;
{
TypHandle           hd1;
hd1 = EVAL( PTR(hd)[0] );
if ( hd1 == HdTrue )
return HdTrue;
else if ( hd1 != HdFalse )
return Error("or: <expr> must evaluate to 'true' or 'false'",0L,0L);
hd1 = EVAL( PTR(hd)[1] );
if ( hd1 == HdTrue )
return HdTrue;
else if ( hd1 != HdFalse )
return Error("or: <expr> must evaluate to 'true' or 'false'",0L,0L);
return HdFalse;
}
TypHandle       EqBool ( hdL, hdR )
TypHandle           hdL,  hdR;
{
if ( hdL == hdR )  return HdTrue;
else               return HdFalse;
}
TypHandle       LtBool ( hdL, hdR )
TypHandle           hdL, hdR;
{
if ( hdL == HdTrue && hdR == HdFalse )  return HdTrue;
else                                    return HdFalse;
}
void            PrBool ( hd )
TypHandle           hd;
{
if ( hd == HdTrue )  Pr("true",0L,0L);
else                 Pr("false",0L,0L);
}
TypHandle       FunIsBool ( hdCall )
TypHandle           hdCall;
{
TypHandle           hdObj;
if ( SIZE(hdCall) != 2 * SIZE_HD )
return Error("usage: IsBool( <obj> )",0L,0L);
hdObj = EVAL( PTR(hdCall)[1] );
if ( hdObj == HdVoid )
return Error("IsBool: function must return a value",0L,0L);
if ( TYPE(hdObj) == T_BOOL )
return HdTrue;
else
return HdFalse;
}
TypHandle       FunShallowCopy ( hdCall )
TypHandle           hdCall;
{
TypHandle           hdOld;
TypHandle           * ptOld;
TypHandle           hdNew;
TypHandle           * ptNew;
unsigned long       i;
if ( SIZE(hdCall) != 2*SIZE_HD )
return Error("usage: ShallowCopy( <obj> )",0L,0L);
hdOld = EVAL( PTR(hdCall)[1] );
if ( T_LIST <= TYPE(hdOld) && TYPE(hdOld) < T_VAR ) {
hdNew = NewBag( TYPE(hdOld), SIZE(hdOld) );
ptOld = PTR(hdOld);
ptNew = PTR(hdNew);
for ( i = (SIZE(hdOld)+SIZE_HD-1)/SIZE_HD; 0 < i; i-- )
*ptNew++ = *ptOld++;
}
else {
hdNew = hdOld;
}
return hdNew;
}
TypHandle       CopyShadow ( hdOld )
TypHandle           hdOld;
{
TypHandle           hdNew;
TypHandle           hdTmp;
unsigned long       n;
unsigned long       i;
hdNew = NewBag( TYPE(hdOld), SIZE(hdOld) );
hdOld->name[2] = 0;
n = NrHandles( TYPE(hdOld), SIZE(hdOld) );
for ( i = n; 0 < i; i-- ) {
if ( PTR(hdOld)[i-1] != 0
&& T_LIST <= TYPE(PTR(hdOld)[i-1])
&& TYPE(PTR(hdOld)[i-1]) < T_VAR
&& PTR(hdOld)[i-1]->name[2] != 0 ) {
hdTmp = CopyShadow( PTR(hdOld)[i-1] );
PTR(hdNew)[i-1] = hdTmp;
}
}
return hdNew;
}
void            CopyForward ( hdOld, hdNew )
TypHandle           hdOld;
TypHandle           hdNew;
{
unsigned long       n;
unsigned long       i;
PTR(hdOld)[-1] = hdNew;
n = NrHandles( TYPE(hdOld), SIZE(hdOld) );
for ( i = n; 0 < i; i-- ) {
if ( PTR(hdOld)[i-1] != 0 && PTR(hdNew)[i-1] != 0 )
CopyForward( PTR(hdOld)[i-1], PTR(hdNew)[i-1] );
}
}
void            CopyCopy ( hdOld, hdNew )
TypHandle           hdOld;
TypHandle           hdNew;
{
unsigned long       n;
unsigned long       i;
n = NrHandles( TYPE(hdOld), SIZE(hdOld) );
for ( i = (SIZE(hdOld)+SIZE_HD-1)/SIZE_HD; n < i; i-- ) {
PTR(hdNew)[i-1] = PTR(hdOld)[i-1];
}
for ( i = n; 0 < i; i-- ) {
if ( PTR(hdOld)[i-1] != 0 && PTR(hdNew)[i-1] != 0 )
CopyCopy( PTR(hdOld)[i-1], PTR(hdNew)[i-1] );
else if ( PTR(hdOld)[i-1] != 0 && TYPE(PTR(hdOld)[i-1]) != T_INT )
PTR(hdNew)[i-1] = PTR( PTR(hdOld)[i-1] )[-1];
else
PTR(hdNew)[i-1] = PTR(hdOld)[i-1];
}
}
void            CopyCleanup ( hdOld )
TypHandle           hdOld;
{
unsigned long       n;
unsigned long       i;
PTR(hdOld)[-1] = hdOld;
hdOld->name[2] = 1;
n = NrHandles( TYPE(hdOld), SIZE(hdOld) );
for ( i = n; 0 < i; i-- ) {
if ( PTR(hdOld)[i-1] != 0
&& T_LIST <= TYPE(PTR(hdOld)[i-1])
&& TYPE(PTR(hdOld)[i-1]) < T_VAR
&& PTR(hdOld)[i-1]->name[2] == 0 )
CopyCleanup( PTR(hdOld)[i-1] );
}
}
TypHandle       Copy ( hdOld )
TypHandle           hdOld;
{
TypHandle           hdNew;
EnterKernel();
if ( T_LIST <= TYPE(hdOld) && TYPE(hdOld) < T_VAR ) {
hdNew = CopyShadow( hdOld );
CopyForward( hdOld, hdNew );
CopyCopy( hdOld, hdNew );
CopyCleanup( hdOld );
}
else {
hdNew = hdOld;
}
ExitKernel(hdNew);
return hdNew;
}
TypHandle       FunCopy ( hdCall )
TypHandle           hdCall;
{
if ( SIZE(hdCall) != 2 * SIZE_HD )
return Error("usage: Copy( <obj> )",0L,0L);
return Copy( EVAL( PTR(hdCall)[1] ) );
}
TypHandle       FunIsBound ( hdCall )
TypHandle           hdCall;
{
TypHandle           hd, hdList, hdInd, hdRec, hdNam, Result;
unsigned long       i;
char                value [16];
char                * p;
if ( SIZE(hdCall) != 2*SIZE_HD )
return Error("usage: IsBound( <obj> )",0L,0L);
hd = PTR(hdCall)[1];
if ( TYPE(hd) != T_VAR     && TYPE(hd) != T_VARAUTO
&& TYPE(hd) != T_LISTELM && TYPE(hd) != T_RECELM )
return Error("IsBound: <obj> must be a variable",0L,0L);
if ( TYPE(hd) == T_VAR ) {
if ( PTR(hd)[0] != 0 )
Result = HdTrue;
else
Result = HdFalse;
}
else if ( TYPE(hd) == T_VARAUTO ) {
Result = HdTrue;
}
else if ( TYPE(hd) == T_LISTELM ) {
hdList = EVAL( PTR(hd)[0] );
if ( ! IS_LIST(hdList) )
return Error("IsBound: <list> must be a list",0L,0L);
hdInd = EVAL( PTR(hd)[1] );
if ( TYPE(hdInd) != T_INT || HD_TO_INT(hdInd) <= 0 )
return Error("IsBound: <index> must be positive int",0L,0L);
if ( HD_TO_INT(hdInd) <= LEN_LIST(hdList)
&& ELMF_LIST(hdList,HD_TO_INT(hdInd)) != 0 )
Result = HdTrue;
else
Result = HdFalse;
}
else {
hdRec = EVAL( PTR(hd)[0] );
hdNam = PTR(hd)[1];
if ( TYPE(hdNam) != T_RECNAM ) {
hdNam = EVAL(hdNam);
if ( IsString( hdNam ) ) {
hdNam = FindRecname( (char*)PTR(hdNam) );
}
else if ( TYPE(hdNam) == T_INT && 0 <= HD_TO_INT(hdNam) ) {
i = HD_TO_INT(hdNam);
p = value + sizeof(value);  *--p = '\0';
do { *--p = '0' + i % 10; } while ( (i /= 10) != 0 );
hdNam = FindRecname( p );
}
else {
return Error("<rec>.(<name>) <name> must be a string",0L,0L);
}
}
if ( TYPE(hdRec) != T_REC )
return Error("IsBound: <record> must be a record",0L,0L);
for ( i = 0; i < SIZE(hdRec)/(2*SIZE_HD); ++i )
if ( PTR(hdRec)[2*i] == hdNam )
break;
if ( i < SIZE(hdRec)/(2*SIZE_HD) )
Result = HdTrue;
else
Result = HdFalse;
}
return Result;
}
TypHandle       FunUnbind ( hdCall )
TypHandle           hdCall;
{
TypHandle           hd, hdList, hdInd, hdRec, hdNam;
unsigned long       i;
char                value [16];
char                * p;
if ( SIZE(hdCall) != 2*SIZE_HD )
return Error("usage: Unbind( <obj> )",0L,0L);
hd = PTR(hdCall)[1];
if ( TYPE(hd) != T_VAR     && TYPE(hd) != T_VARAUTO
&& TYPE(hd) != T_LISTELM && TYPE(hd) != T_RECELM )
return Error("Unbind: <obj> must be a variable",0L,0L);
if ( TYPE(hd) == T_VAR ) {
PTR(hd)[0] = 0;
}
else if ( TYPE(hd) == T_VARAUTO ) {
Retype( hd, T_VAR );
PTR(hd)[0] = 0;
}
else if ( TYPE(hd) == T_LISTELM ) {
hdList = EVAL( PTR(hd)[0] );
if ( ! IS_LIST( hdList ) )
return Error("Unbind: <list> must be a list",0L,0L);
PLAIN_LIST( hdList );
Retype( hdList, T_LIST );
hdInd = EVAL( PTR(hd)[1] );
if ( TYPE(hdInd) != T_INT || HD_TO_INT(hdInd) <= 0 )
return Error("Unbind: <index> must be positive int",0L,0L);
i = HD_TO_INT(hdInd);
if ( i < LEN_PLIST(hdList) ) {
SET_ELM_PLIST( hdList, i, 0 );
}
else if ( i == LEN_PLIST( hdList ) ) {
SET_ELM_PLIST( hdList, i, 0 );
while ( 0 < i && ELM_PLIST( hdList, i ) == 0 )
i--;
SET_LEN_PLIST( hdList, i );
}
}
else {
hdRec = EVAL( PTR(hd)[0] );
hdNam = PTR(hd)[1];
if ( TYPE(hdNam) != T_RECNAM ) {
hdNam = EVAL(hdNam);
if ( IsString( hdNam ) ) {
hdNam = FindRecname( (char*)PTR(hdNam) );
}
else if ( TYPE(hdNam) == T_INT && 0 <= HD_TO_INT(hdNam) ) {
i = HD_TO_INT(hdNam);
p = value + sizeof(value);  *--p = '\0';
do { *--p = '0' + i % 10; } while ( (i /= 10) != 0 );
hdNam = FindRecname( p );
}
else {
return Error("<rec>.(<name>) <name> must be a string",0L,0L);
}
}
if ( TYPE(hdRec) != T_REC )
return Error("Unbind: <record> must be a record",0L,0L);
for ( i = 0; i < SIZE(hdRec)/(2*SIZE_HD); i++ ) {
if ( PTR(hdRec)[2*i] == hdNam )
break;
}
if ( i < SIZE(hdRec)/(2*SIZE_HD) ) {
while ( i < SIZE(hdRec)/(2*SIZE_HD)-1 ) {
PTR(hdRec)[2*i] = PTR(hdRec)[2*i+2];
PTR(hdRec)[2*i+1] = PTR(hdRec)[2*i+3];
i++;
}
Resize( hdRec, SIZE(hdRec)-2*SIZE_HD );
}
}
return HdVoid;
}
void            (* PrTab[ T_ILLEGAL ] ) P(( TypHandle hd ));
TypHandle       HdTildePr;
void            Print ( hd )
TypHandle           hd;
{
TypHandle           ignore;
unsigned long       len;
TypHandle           hdObj[256];
unsigned long       index[256];
TypHandle           cur;
unsigned long       i;
if ( SyIsIntr() ) {
Pr( "%c", (long)'\03', 0L );
ignore = Error("user interrupt while printing",0L,0L);
}
if ( TYPE(hd) == T_INT || hd->name[2] != 0 ) {
if ( PTR(HdTildePr)[0] == 0 )
PTR(HdTildePr)[0] = hd;
if ( (T_LIST <= TYPE(hd) && TYPE(hd) < T_VAR)
|| TYPE(hd) == T_PERM16 || TYPE(hd) == T_PERM32 )
hd->name[2] = 0;
(* PrTab[ TYPE(hd) ] ) (hd);
if ( (T_LIST <= TYPE(hd) && TYPE(hd) < T_VAR)
|| TYPE(hd) == T_PERM16 || TYPE(hd) == T_PERM32 )
hd->name[2] = 1;
if ( hd == PTR(HdTildePr)[0] )
PTR(HdTildePr)[0] = 0;
}
else {
len = 0;
hdObj[0] = HdTildePr;
index[0] = 0;
cur = PTR( hdObj[len] )[ index[len] ];
while ( hd != cur ) {
for ( i = 0; i <= len && hdObj[i] != cur; i++ ) ;
if ( cur != 0
&& (TYPE(cur)==T_LIST || TYPE(cur)==T_SET || TYPE(cur)==T_REC)
&& SIZE(cur) != 0
&& len < i ) {
len++;
hdObj[len] = cur;
index[len] = 0;
cur = PTR( hdObj[len] )[ index[len] ];
}
else if ( index[len] < SIZE(hdObj[len])/SIZE_HD-1 ) {
index[len]++;
cur = PTR( hdObj[len] )[ index[len] ];
}
else {
if ( len != 0 )  len--;
cur = 0;
}
}
for ( i = 0; i <= len; i++ ) {
if ( TYPE(hdObj[i]) == T_VAR )
Pr("~",0L,0L);
else if ( TYPE(hdObj[i])==T_LIST || TYPE(hdObj[i])==T_SET )
Pr("[%d]",index[i],0L);
else
Pr(".%s",(long)PTR(PTR(hdObj[i])[index[i]-1]),0L);
}
}
}
void            CantPrint ( hd )
TypHandle           hd;
{
Error("Panic: can't print bag of type %d",(long)TYPE(hd),0L);
}
void            PrVar ( hdVar )
TypHandle           hdVar;
{
char *              name;
name = (char*)(PTR(hdVar)+1);
if ( !SyStrcmp(name,"and")      || !SyStrcmp(name,"do")
|| !SyStrcmp(name,"elif")     || !SyStrcmp(name,"else")
|| !SyStrcmp(name,"end")      || !SyStrcmp(name,"fi")
|| !SyStrcmp(name,"for")      || !SyStrcmp(name,"function")
|| !SyStrcmp(name,"if")       || !SyStrcmp(name,"in")
|| !SyStrcmp(name,"local")    || !SyStrcmp(name,"mod")
|| !SyStrcmp(name,"not")      || !SyStrcmp(name,"od")
|| !SyStrcmp(name,"or")       || !SyStrcmp(name,"repeat")
|| !SyStrcmp(name,"return")   || !SyStrcmp(name,"then")
|| !SyStrcmp(name,"until")    || !SyStrcmp(name,"while")
|| !SyStrcmp(name,"quit") ) {
Pr("\\",0L,0L);
}
for ( name = (char*)(PTR(hdVar)+1); *name != '\0'; name++ ) {
if ( IsAlpha(*name) || IsDigit(*name) || *name == '_' )
Pr("%c",(long)(*name),0L);
else
Pr("\\%c",(long)(*name),0L);
}
}
void            PrVarAss ( hdAss )
TypHandle           hdAss;
{
Pr("%2>",0L,0L);
Print(PTR(hdAss)[0]);
Pr("%< %>:= ",0L,0L);
Print(PTR(hdAss)[1]);
Pr("%2<",0L,0L);
}
long            prPrec;
void            PrNot ( hdNot )
TypHandle           hdNot;
{
long                oldPrec;
oldPrec = prPrec;  prPrec = 4;
Pr("not%> ",0L,0L);  Print( PTR(hdNot)[0] );  Pr("%<",0L,0L);
prPrec = oldPrec;
}
void            PrBinop ( hdOp )
TypHandle           hdOp;
{
long                oldPrec;
char                * op;
oldPrec = prPrec;
switch ( TYPE(hdOp) ) {
case T_AND:    op = "and";  prPrec = 2;   break;
case T_OR:     op = "or";   prPrec = 2;   break;
case T_EQ:     op = "=";    prPrec = 6;   break;
case T_LT:     op = "<";    prPrec = 6;   break;
case T_GT:     op = ">";    prPrec = 6;   break;
case T_NE:     op = "<>";   prPrec = 6;   break;
case T_LE:     op = "<=";   prPrec = 6;   break;
case T_GE:     op = ">=";   prPrec = 6;   break;
case T_IN:     op = "in";   prPrec = 6;   break;
case T_SUM:    op = "+";    prPrec = 8;   break;
case T_DIFF:   op = "-";    prPrec = 8;   break;
case T_PROD:   op = "*";    prPrec = 10;  break;
case T_QUO:    op = "/";    prPrec = 10;  break;
case T_MOD:    op = "mod";  prPrec = 10;  break;
case T_POW:    op = "^";    prPrec = 12;  break;
default:       op = "<bogus-operator>";   break;
}
if ( oldPrec > prPrec )  Pr("%>(%>",0L,0L);
else                     Pr("%2>",0L,0L);
if ( TYPE(hdOp) == T_POW
&& ((TYPE(PTR(hdOp)[0]) == T_INT && HD_TO_INT(PTR(hdOp)[0]) < 0)
|| TYPE(PTR(hdOp)[0]) == T_INTNEG) )
Pr("(",0L,0L);
Print( PTR(hdOp)[0] );
if ( TYPE(hdOp) == T_POW
&& ((TYPE(PTR(hdOp)[0]) == T_INT && HD_TO_INT(PTR(hdOp)[0]) < 0)
|| TYPE(PTR(hdOp)[0]) == T_INTNEG) )
Pr(")",0L,0L);
Pr("%2< %2>%s%> %<",(long)op,0L);
++prPrec;
Print( PTR(hdOp)[1] );
--prPrec;
if ( oldPrec > prPrec )  Pr("%2<)",0L,0L);
else                     Pr("%2<",0L,0L);
prPrec = oldPrec;
}
void            PrComm ( hd )
TypHandle           hd;
{
Pr("%>Comm(%> ",0L,0L);
Print(PTR(hd)[0]);
Pr("%<,%>",0L,0L);
Print(PTR(hd)[1]);
Pr("%2<)",0L,0L);
}
void            InstEvFunc ( type, func )
unsigned int        type;
TypHandle           (* func) ();
{
EvTab[ type ] = func;
}
void            InstBinOp ( table, leftType, rightType, func )
TypHandle           (* table [T_VAR][T_VAR]) ();
unsigned int        leftType,  rightType;
TypHandle           (* func) ();
{
table[ leftType ][ rightType ] = func;
}
void            InstPrFunc ( type, func )
unsigned int        type;
void                (* func) ();
{
PrTab[ type ] = func;
}
void            InstVar ( name, hdVal )
char                * name;
TypHandle           hdVal;
{
TypHandle           hdVar;
hdVar = FindIdent( name );
if ( PTR(hdVar)[0] != 0 )
Error("Panic: symbol clash %s during initialization",(long)name,0L);
PTR(hdVar)[0] = hdVal;
}
void            InstIntFunc ( name, func )
char                name [];
TypHandle           (* func) ();
{
TypHandle           hdDef,  hdVar;
hdDef = NewBag( T_FUNCINT, sizeof(TypHandle(**)()) );
* (TypHandle(**)())PTR(hdDef) = func;
hdVar = FindIdent( name );
if ( PTR(hdVar)[0] != 0 )
Error("Panic: symbol clash %s during initialization",(long)name,0L);
PTR(hdVar)[0] = hdDef;
}
void            InitEval ()
{
unsigned int        type,  typeL,  typeR;
for ( type = 0; type < T_ILLEGAL; ++type ) {
EvTab[type] = CantEval;
PrTab[type] = CantPrint;
}
for ( typeL = 0; typeL < T_VAR; ++typeL ) {
for ( typeR = 0; typeR < T_VAR; ++typeR ) {
TabSum[typeL][typeR]  = CantSum;
TabDiff[typeL][typeR] = CantDiff;
TabProd[typeL][typeR] = CantProd;
TabQuo[typeL][typeR]  = CantQuo;
TabMod[typeL][typeR]  = CantMod;
TabPow[typeL][typeR]  = CantPow;
TabComm[typeL][typeR] = CantComm;
}
}
for ( typeL = 0; typeL < T_VAR; ++typeL ) {
for ( typeR = 0; typeR <= typeL; ++typeR ) {
TabEq[typeL][typeR] = IsFalse;
TabLt[typeL][typeR] = IsFalse;
}
for ( typeR = typeL+1; typeR < T_VAR; ++typeR ) {
TabEq[typeL][typeR] = IsFalse;
TabLt[typeL][typeR] = IsTrue;
}
}
InstEvFunc( T_SUM,      Sum      );
InstEvFunc( T_DIFF,     Diff     );
InstEvFunc( T_PROD,     Prod     );
InstEvFunc( T_QUO,      Quo      );
InstEvFunc( T_MOD,      Mod      );
InstEvFunc( T_POW,      Pow      );
InstIntFunc( "Comm",  IntComm  );
InstIntFunc( "LeftQuotient",  FunLeftQuotient );
InstEvFunc( T_EQ,       Eq       );
InstEvFunc( T_LT,       Lt       );
InstEvFunc( T_LE,       Le       );
InstEvFunc( T_NE,       Ne       );
InstEvFunc( T_GT,       Gt       );
InstEvFunc( T_GE,       Ge       );
InstPrFunc( T_SUM,      PrBinop    );
InstPrFunc( T_DIFF,     PrBinop    );
InstPrFunc( T_PROD,     PrBinop    );
InstPrFunc( T_QUO,      PrBinop    );
InstPrFunc( T_MOD,      PrBinop    );
InstPrFunc( T_POW,      PrBinop    );
InstPrFunc( T_COMM,     PrComm     );
InstPrFunc( T_EQ,       PrBinop    );
InstPrFunc( T_LT,       PrBinop    );
InstPrFunc( T_GT,       PrBinop    );
InstPrFunc( T_NE,       PrBinop    );
InstPrFunc( T_LE,       PrBinop    );
InstPrFunc( T_GE,       PrBinop    );
InstPrFunc( T_IN,       PrBinop    );
InstEvFunc( T_VAR,      EvVar      );
InstEvFunc( T_VARAUTO,  EvVarAuto  );
InstEvFunc( T_VARASS,   EvVarAss   );
InstPrFunc( T_VAR,      PrVar      );
InstPrFunc( T_VARAUTO,  PrVar      );
InstPrFunc( T_VARASS,   PrVarAss   );
HdVoid  = NewBag( T_VOID, 0L );
HdTrue  = NewBag(T_BOOL,0L);  InstVar( "true",  HdTrue  );
HdFalse = NewBag(T_BOOL,0L);  InstVar( "false", HdFalse );
InstEvFunc( T_BOOL,     EvBool     );
InstEvFunc( T_NOT,      EvNot      );
InstEvFunc( T_AND,      EvAnd      );
InstEvFunc( T_OR,       EvOr       );
InstPrFunc( T_BOOL,     PrBool     );
InstPrFunc( T_NOT,      PrNot      );
InstPrFunc( T_AND,      PrBinop    );
InstPrFunc( T_OR,       PrBinop    );
TabEq[ T_BOOL ][ T_BOOL ] = EqBool;
TabLt[ T_BOOL ][ T_BOOL ] = LtBool;
InstIntFunc( "IsBool",      FunIsBool      );
InstIntFunc( "ShallowCopy", FunShallowCopy );
InstIntFunc( "Copy",        FunCopy        );
InstIntFunc( "IsBound",     FunIsBound     );
InstIntFunc( "Unbind",      FunUnbind      );
HdTildePr = FindIdent( "~~" );
InitInt();
InitRat();
InitCyc();
InitUnknown();
InitFF();
InitPolynom();
InitPermutat();
InitWord();
InitCosTab();
InitTietze();
InitAg();
InitPcPres();
InitList();
InitPlist();
InitSet();
InitVector();
InitVecFFE();
InitBlist();
InitRange();
InitString();
InitRec();
InitStat();
InitFunc();
InitCoding();
}
/* 当前文件是D:\Read\finfield.c*/

#define ORD_FF(FFE)             (SIZE_FF(FLD_FFE(FFE)))



TypHandle       CommonFF ( hdL, hdR )
TypHandle           hdL;
TypHandle           hdR;
{
TypHandle           hdZ;
unsigned long       q;
unsigned long       p;
unsigned long       d;
unsigned long       v;
unsigned long       ql, qr;
unsigned long       dl, dr;
q = ORD_FF(hdL);
if ( q % 2 == 0 )  p = 2;
else for ( p = 3; q % p != 0; p++ ) ;
if ( ORD_FF(hdR) % p != 0 )
return 0;
v = VAL_FFE(hdL);
if ( v == 0 )  return PTR(hdR)[0];
q = ORD_FF(hdL);
ql = p;
dl = 1;
while ( (q-1) % (ql-1) != 0 || (v-1) % ((q-1)/(ql-1)) != 0 ) {
ql *= p;
dl += 1;
}
v = VAL_FFE(hdR);
if ( v == 0 )  return PTR(hdL)[0];
q = ORD_FF(hdR);
qr = p;
dr = 1;
while ( (q-1) % (qr-1) != 0 || (v-1) % ((q-1)/(qr-1)) != 0 ) {
qr *= p;
dr += 1;
}
q = ql;
d = dl;
while ( d % dr != 0 ) {
q *= ql;
d += dl;
}
if ( (  2 <= p && 17 <= d) || (  3 <= p && 11 <= d)
|| (  5 <= p &&  7 <= d) || (  7 <= p &&  6 <= d)
|| ( 11 <= p &&  5 <= d) || ( 17 <= p &&  4 <= d)
|| ( 41 <= p &&  3 <= d) || (257 <= p &&  2 <= d) )
return (TypHandle)1;
hdZ = RootFiniteField( q );
if ( hdZ == 0 )
return 0;
return FLD_FFE(hdZ);
}
TypHandle       EvFFE ( hdFFE )
TypHandle           hdFFE;
{
return hdFFE;
}
TypHandle       SumFFE ( hdL, hdR )
TypHandle           hdL;
TypHandle           hdR;
{
TypHandle           hdX;
TypFFE              x;
TypHandle           hdFF;
TypFFE              * field;
TypFFE              l;
TypFFE              r;
if ( TYPE(hdL) == T_INT ) {
hdFF = FLD_FFE(hdR);
field = SUCC_FF( hdFF );
r = (HD_TO_INT(hdL) % (long)ORD_FF(hdR) + ORD_FF(hdR)) % ORD_FF(hdR);
if ( r == 0 )  l = 0;
else for ( l = 1; 1 < r; --r )  l = (l == 0 ? 1 : field[l]);
r = VAL_FFE(hdR);
}
else if ( TYPE(hdR) == T_INT ) {
hdFF = FLD_FFE(hdL);
field = SUCC_FF( hdFF );
l = (HD_TO_INT(hdR) % (long)ORD_FF(hdL) + ORD_FF(hdL)) % ORD_FF(hdL);
if ( l == 0 )  r = 0;
else for ( r = 1; 1 < l; --l )  r = (r == 0 ? 1 : field[r]);
l = VAL_FFE(hdL);
}
else if ( FLD_FFE(hdL) == FLD_FFE(hdR) ) {
hdFF = FLD_FFE(hdL);
field = SUCC_FF( hdFF );
l = VAL_FFE(hdL);
r = VAL_FFE(hdR);
}
else if ( ORD_FF(hdL)%ORD_FF(hdR)==0 && ORD_FF(hdL)%(ORD_FF(hdR)-1)<=1 ){
hdFF = FLD_FFE(hdL);
field = SUCC_FF( hdFF );
l = VAL_FFE(hdL);
if ( VAL_FFE(hdR) == 0 )  r = 0;
else r = (ORD_FF(hdL)-1) / (ORD_FF(hdR)-1) * (VAL_FFE(hdR)-1) + 1;
}
else if ( ORD_FF(hdR)%ORD_FF(hdL)==0 && ORD_FF(hdR)%(ORD_FF(hdL)-1)<=1 ){
hdFF = FLD_FFE(hdR);
field = SUCC_FF( hdFF );
if ( VAL_FFE(hdL) == 0 )  l = 0;
else l = (ORD_FF(hdR)-1) / (ORD_FF(hdL)-1) * (VAL_FFE(hdL)-1) + 1;
r = VAL_FFE(hdR);
}
else {
hdFF = CommonFF( hdL, hdR );
if ( hdFF == 0 )
return Error(
"Finite field +: operands must have the same characteristic",
0L,0L);
else if ( hdFF == (TypHandle)1 )
return Error(
"Finite field +: smallest common superfield to large",
0L,0L);
field = SUCC_FF( hdFF );
if ( VAL_FFE(hdL) == 0 )  l = 0;
else  l = (VAL_FFE(hdL)-1) * field[0] / (ORD_FF(hdL)-1) + 1;
if ( VAL_FFE(hdR) == 0 )  r = 0;
else  r = (VAL_FFE(hdR)-1) * field[0] / (ORD_FF(hdR)-1) + 1;
}
x             = SUM_FF( l, r, field );
hdX           = NewBag( T_FFE, SIZE_HD + sizeof(TypFFE) );
SET_FLD_FFE( hdX, hdFF );
SET_VAL_FFE( hdX, x );
return  hdX;
}
TypHandle       DiffFFE ( hdL, hdR )
TypHandle           hdL;
TypHandle           hdR;
{
TypHandle           hdX;
TypFFE              x;
TypHandle           hdFF;
TypFFE              * field;
TypFFE              l;
TypFFE              r;
if ( TYPE(hdL) == T_INT ) {
hdFF = FLD_FFE(hdR);
field = SUCC_FF( hdFF );
r = (HD_TO_INT(hdL) % (long)ORD_FF(hdR) + ORD_FF(hdR)) % ORD_FF(hdR);
if ( r == 0 )  l = 0;
else for ( l = 1; 1 < r; --r )  l = (l == 0 ? 1 : field[l]);
r = VAL_FFE(hdR);
}
else if ( TYPE(hdR) == T_INT ) {
hdFF = FLD_FFE(hdL);
field = SUCC_FF( hdFF );
l = (HD_TO_INT(hdR) % (long)ORD_FF(hdL) + ORD_FF(hdL)) % ORD_FF(hdL);
if ( l == 0 )  r = 0;
else for ( r = 1; 1 < l; --l )  r = (r == 0 ? 1 : field[r]);
l = VAL_FFE(hdL);
}
else if ( FLD_FFE(hdL) == FLD_FFE(hdR) ) {
hdFF = FLD_FFE(hdL);
field = SUCC_FF( hdFF );
l = VAL_FFE(hdL);
r = VAL_FFE(hdR);
}
else if ( ORD_FF(hdL)%ORD_FF(hdR)==0 && ORD_FF(hdL)%(ORD_FF(hdR)-1)<=1 ){
hdFF = FLD_FFE(hdL);
field = SUCC_FF( hdFF );
l = VAL_FFE(hdL);
if ( VAL_FFE(hdR) == 0 )  r = 0;
else r = (ORD_FF(hdL)-1) / (ORD_FF(hdR)-1) * (VAL_FFE(hdR)-1) + 1;
}
else if ( ORD_FF(hdR)%ORD_FF(hdL)==0 && ORD_FF(hdR)%(ORD_FF(hdL)-1)<=1 ){
hdFF = FLD_FFE(hdR);
field = SUCC_FF( hdFF );
if ( VAL_FFE(hdL) == 0 )  l = 0;
else l = (ORD_FF(hdR)-1) / (ORD_FF(hdL)-1) * (VAL_FFE(hdL)-1) + 1;
r = VAL_FFE(hdR);
}
else {
hdFF = CommonFF( hdL, hdR );
if ( hdFF == 0 )
return Error(
"Finite field -: operands must have the same characteristic",
0L,0L);
else if ( hdFF == (TypHandle)1 )
return Error(
"Finite field -: smallest common superfield to large",
0L,0L);
field = SUCC_FF( hdFF );
if ( VAL_FFE(hdL) == 0 )  l = 0;
else  l = (VAL_FFE(hdL)-1) * field[0] / (ORD_FF(hdL)-1) + 1;
if ( VAL_FFE(hdR) == 0 )  r = 0;
else  r = (VAL_FFE(hdR)-1) * field[0] / (ORD_FF(hdR)-1) + 1;
}
x             = NEG_FF( r, field );
x             = SUM_FF( l, x, field );
hdX           = NewBag( T_FFE, SIZE_HD + sizeof(TypFFE) );
SET_FLD_FFE( hdX, hdFF );
SET_VAL_FFE( hdX, x );
return  hdX;
}
TypHandle       ProdFFE ( hdL, hdR )
TypHandle           hdL;
TypHandle           hdR;
{
TypHandle           hdX;
TypFFE              x;
TypHandle           hdFF;
TypFFE              * field;
TypFFE              l;
TypFFE              r;
if ( TYPE(hdL) == T_INT ) {
hdFF = FLD_FFE(hdR);
field = SUCC_FF( hdFF );
r = (HD_TO_INT(hdL) % (long)ORD_FF(hdR) + ORD_FF(hdR)) % ORD_FF(hdR);
if ( r == 0 )  l = 0;
else for ( l = 1; 1 < r; --r )  l = (l == 0 ? 1 : field[l]);
r = VAL_FFE(hdR);
}
else if ( TYPE(hdR) == T_INT ) {
hdFF = FLD_FFE(hdL);
field = SUCC_FF( hdFF );
l = (HD_TO_INT(hdR) % (long)ORD_FF(hdL) + ORD_FF(hdL)) % ORD_FF(hdL);
if ( l == 0 )  r = 0;
else for ( r = 1; 1 < l; --l )  r = (r == 0 ? 1 : field[r]);
l = VAL_FFE(hdL);
}
else if ( FLD_FFE(hdL) == FLD_FFE(hdR) ) {
hdFF = FLD_FFE(hdL);
field = SUCC_FF( hdFF );
l = VAL_FFE(hdL);
r = VAL_FFE(hdR);
}
else if ( ORD_FF(hdL)%ORD_FF(hdR)==0 && ORD_FF(hdL)%(ORD_FF(hdR)-1)<=1 ){
hdFF = FLD_FFE(hdL);
field = SUCC_FF( hdFF );
l = VAL_FFE(hdL);
if ( VAL_FFE(hdR) == 0 )  r = 0;
else r = (ORD_FF(hdL)-1) / (ORD_FF(hdR)-1) * (VAL_FFE(hdR)-1) + 1;
}
else if ( ORD_FF(hdR)%ORD_FF(hdL)==0 && ORD_FF(hdR)%(ORD_FF(hdL)-1)<=1 ){
hdFF = FLD_FFE(hdR);
field = SUCC_FF( hdFF );
if ( VAL_FFE(hdL) == 0 )  l = 0;
else l = (ORD_FF(hdR)-1) / (ORD_FF(hdL)-1) * (VAL_FFE(hdL)-1) + 1;
r = VAL_FFE(hdR);
}
else {
hdFF = CommonFF( hdL, hdR );
if ( hdFF == 0 )
return Error(
"Finite field *: operands must have the same characteristic",
0L,0L);
else if ( hdFF == (TypHandle)1 )
return Error(
"Finite field *: smallest common superfield to large",
0L,0L);
field = SUCC_FF( hdFF );
if ( VAL_FFE(hdL) == 0 )  l = 0;
else  l = (VAL_FFE(hdL)-1) * field[0] / (ORD_FF(hdL)-1) + 1;
if ( VAL_FFE(hdR) == 0 )  r = 0;
else  r = (VAL_FFE(hdR)-1) * field[0] / (ORD_FF(hdR)-1) + 1;
}
x             = PROD_FF( l, r, field );
hdX           = NewBag( T_FFE, SIZE_HD + sizeof(TypFFE) );
SET_FLD_FFE( hdX, hdFF );
SET_VAL_FFE( hdX, x );
return  hdX;
}
TypHandle       QuoFFE ( hdL, hdR )
TypHandle           hdL;
TypHandle           hdR;
{
TypHandle           hdX;
TypFFE              x;
TypHandle           hdFF;
TypFFE              * field;
TypFFE              l;
TypFFE              r;
if ( TYPE(hdL) == T_INT ) {
hdFF = FLD_FFE(hdR);
field = SUCC_FF( hdFF );
r = (HD_TO_INT(hdL) % (long)ORD_FF(hdR) + ORD_FF(hdR)) % ORD_FF(hdR);
if ( r == 0 )  l = 0;
else for ( l = 1; 1 < r; --r )  l = (l == 0 ? 1 : field[l]);
r = VAL_FFE(hdR);
}
else if ( TYPE(hdR) == T_INT ) {
hdFF = FLD_FFE(hdL);
field = SUCC_FF( hdFF );
l = (HD_TO_INT(hdR) % (long)ORD_FF(hdL) + ORD_FF(hdL)) % ORD_FF(hdL);
if ( l == 0 )  r = 0;
else for ( r = 1; 1 < l; --l )  r = (r == 0 ? 1 : field[r]);
l = VAL_FFE(hdL);
}
else if ( FLD_FFE(hdL) == FLD_FFE(hdR) ) {
hdFF = FLD_FFE(hdL);
field = SUCC_FF( hdFF );
l = VAL_FFE(hdL);
r = VAL_FFE(hdR);
}
else if ( ORD_FF(hdL)%ORD_FF(hdR)==0 && ORD_FF(hdL)%(ORD_FF(hdR)-1)<=1 ){
hdFF = FLD_FFE(hdL);
field = SUCC_FF( hdFF );
l = VAL_FFE(hdL);
if ( VAL_FFE(hdR) == 0 )  r = 0;
else r = (ORD_FF(hdL)-1) / (ORD_FF(hdR)-1) * (VAL_FFE(hdR)-1) + 1;
}
else if ( ORD_FF(hdR)%ORD_FF(hdL)==0 && ORD_FF(hdR)%(ORD_FF(hdL)-1)<=1 ){
hdFF = FLD_FFE(hdR);
field = SUCC_FF( hdFF );
if ( VAL_FFE(hdL) == 0 )  l = 0;
else l = (ORD_FF(hdR)-1) / (ORD_FF(hdL)-1) * (VAL_FFE(hdL)-1) + 1;
r = VAL_FFE(hdR);
}
else {
hdFF = CommonFF( hdL, hdR );
if ( hdFF == 0 )
return Error(
"Finite field /: operands must have the same characteristic",
0L,0L);
else if ( hdFF == (TypHandle)1 )
return Error(
"Finite field /: smallest common superfield to large",
0L,0L);
field = SUCC_FF( hdFF );
if ( VAL_FFE(hdL) == 0 )  l = 0;
else  l = (VAL_FFE(hdL)-1) * field[0] / (ORD_FF(hdL)-1) + 1;
if ( VAL_FFE(hdR) == 0 )  r = 0;
else  r = (VAL_FFE(hdR)-1) * field[0] / (ORD_FF(hdR)-1) + 1;
}
if ( r == 0 ) return Error("divisor must be nonzero",0L,0L);
x             = QUO_FF( l, r, field );
hdX           = NewBag( T_FFE, SIZE_HD + sizeof(TypFFE) );
SET_FLD_FFE( hdX, hdFF );
SET_VAL_FFE( hdX, x );
return  hdX;
}
TypHandle       PowFFE ( hdL, hdR )
TypHandle           hdL;
TypHandle           hdR;
{
TypHandle           hdX;
TypFFE              x;
TypHandle           hdFF;
TypFFE              * field;
TypFFE              l;
long                r;
hdFF = FLD_FFE(hdL);
field = SUCC_FF( hdFF );
l = VAL_FFE(hdL);
r = HD_TO_INT( hdR );
if ( r < 0 ) {
if ( l == 0 )  return Error("divisor must be nonzero",0L,0L);
l = QUO_FF( 1, l, field );
r = -r;
}
x             = POW_FF( l, r, field );
hdX           = NewBag( T_FFE, SIZE_HD + sizeof(TypFFE) );
SET_FLD_FFE( hdX, hdFF );
SET_VAL_FFE( hdX, x );
return hdX;
}
TypHandle       EqFFE ( hdL, hdR )
TypHandle           hdL;
TypHandle           hdR;
{
TypFFE              l,  r;
long                fl, fr;
long                pl, pr;
long                ml, mr;
l  = VAL_FFE(hdL);
r  = VAL_FFE(hdR);
fl = ORD_FF(hdL);
fr = ORD_FF(hdR);
if ( l == 0 || r == 0 ) {
if ( l == 0 && r == 0 )  return HdTrue;
else                     return HdFalse;
}
if ( fl == fr ) {
if ( l == r )  return HdTrue;
else           return HdFalse;
}
if ( fl % 2 == 0 )  pl = 2;
else for ( pl = 3; fl % pl != 0; pl += 2 ) ;
if ( fr % 2 == 0 )  pr = 2;
else for ( pr = 3; fr % pr != 0; pr += 2 ) ;
if ( pl != pr ) {
return HdFalse;
}
ml = pl;
while ( (fl-1) % (ml-1) != 0 || (l-1) % ((fl-1)/(ml-1)) != 0 )  ml *= pl;
mr = pr;
while ( (fr-1) % (mr-1) != 0 || (r-1) % ((fr-1)/(mr-1)) != 0 )  mr *= pr;
if ( ml != mr ) {
return HdFalse;
}
if ( (l-1) / ((fl-1)/(ml-1)) == (r-1) / ((fr-1)/(mr-1)) )  return HdTrue;
else                                                      return HdFalse;
}
TypHandle       LtFFE ( hdL, hdR )
TypHandle           hdL;
TypHandle           hdR;
{
TypFFE              l,  r;
long                fl, fr;
long                pl, pr;
long                ml, mr;
l  = VAL_FFE(hdL);
r  = VAL_FFE(hdR);
fl = ORD_FF(hdL);
fr = ORD_FF(hdR);
if ( l == 0 || r == 0 ) {
if ( l == 0 && r != 0 )  return HdTrue;
else                     return HdFalse;
}
if ( fl % 2 == 0 )  pl = 2;
else for ( pl = 3; fl % pl != 0; pl += 2 ) ;
if ( fr % 2 == 0 )  pr = 2;
else for ( pr = 3; fr % pr != 0; pr += 2 ) ;
if ( pl != pr ) {
if ( pl < pr )  return HdTrue;
else            return HdFalse;
}
ml = pl;
while ( (fl-1) % (ml-1) != 0 || (l-1) % ((fl-1)/(ml-1)) != 0 )  ml *= pl;
mr = pr;
while ( (fr-1) % (mr-1) != 0 || (r-1) % ((fr-1)/(mr-1)) != 0 )  mr *= pr;
if ( ml != mr ) {
if ( ml < mr )  return HdTrue;
else            return HdFalse;
}
if ( (l-1) / ((fl-1)/(ml-1)) < (r-1) / ((fr-1)/(mr-1)) )  return HdTrue;
else                                                      return HdFalse;
}
void            PrFFE ( hdFFE )
TypHandle           hdFFE;
{
PrFF( FLD_FFE(hdFFE), VAL_FFE(hdFFE) );
}
void            PrFF ( hdField, value )
TypHandle           hdField;
unsigned int        value;
{
unsigned long       o;
unsigned long       p;
unsigned long       m;
unsigned long       d;
o = SIZE_FF( hdField );
if ( o % 2 == 0 )  p = 2;
else for ( p = 3; o % p != 0; p += 2 ) ;
if ( value == 0 ) {
Pr("%>0*Z(%>%d%2<)",(long)p,0L);
}
else {
d = 1;  m = p;
while ( (o-1) % (m-1) != 0 || (value-1) % ((o-1)/(m-1)) != 0 ) {
d++;  m *= p;
}
value = (value-1) / ((o-1)/(m-1)) + 1;
Pr("%>Z(%>%d%<",(long)p,0L);
if ( d == 1 )  Pr("%<)",0L,0L);
else  Pr("^%>%d%2<)",(long)d,0L);
if ( value != 2 )  Pr("^%>%d%<",(long)value-1,0L);
}
}
TypHandle       FunIsFFE ( hdCall )
TypHandle           hdCall;
{
TypHandle           hdObj;
if ( SIZE(hdCall) != 2 * SIZE_HD )
return Error("usage: IsFFE( <obj> )",0L,0L);
hdObj = EVAL( PTR(hdCall)[1] );
if ( hdObj == HdVoid )
return Error("IsFFE: function must return a value",0L,0L);
if ( TYPE(hdObj) == T_FFE )
return HdTrue;
else
return HdFalse;
}
long            CharFFE ( hdFFE )
TypHandle           hdFFE;
{
unsigned long       p;
unsigned long       q;
q = SIZE_FF( FLD_FFE( hdFFE ) );
if ( q % 2 == 0 ) {
p = 2;
}
else {
for ( p = 3; q % p != 0; p += 2 )
;
}
return p;
}
long            DegreeFFE ( hdFFE )
TypHandle           hdFFE;
{
unsigned long       d;
TypFFE              v;
unsigned long       p;
unsigned long       q;
unsigned long       r;
v = VAL_FFE( hdFFE );
q = SIZE_FF( FLD_FFE( hdFFE ) );
if ( q % 2 == 0 ) {
p = 2;
}
else {
for ( p = 3; q % p != 0; p += 2 )
;
}
r = p;
d = 1;
if ( v != 0 ) {
while ( (q-1)%(r-1) != 0 || (v-1)%((q-1)/(r-1)) != 0 ) {
r *= p;
d += 1;
}
}
return d;
}
TypHandle       FunLogFFE ( hdCall )
TypHandle           hdCall;
{
TypHandle           hdZ;
TypHandle           hdR;
TypHandle           hdFF;
TypFFE              * field;
long                i,  k,  o,  a,  b,  t;
if ( SIZE(hdCall) != 2 * SIZE_HD && SIZE(hdCall) != 3 * SIZE_HD )
return Error("usage: LogFFE( <z> ) or LogFFE( <z>, <r> )",0L,0L);
if ( SIZE(hdCall) == 2 * SIZE_HD ) {
hdZ = EVAL( PTR(hdCall)[1] );
if ( TYPE(hdZ) != T_FFE )
return Error("LogFFE: <z> must be a finite field element",0L,0L);
if ( VAL_FFE(hdZ)==0 )
return Error("LogFFE: <z> must be nonzero",0L,0L);
i = VAL_FFE(hdZ) - 1;
k = 1;
o = ORD_FF(hdZ) - 1;
}
else {
hdZ = EVAL( PTR(hdCall)[1] );
if ( TYPE(hdZ) != T_FFE )
return Error("LogFFE: <z> must be a finite field element",0L,0L);
hdR = EVAL( PTR(hdCall)[2] );
if ( TYPE(hdR) != T_FFE )
return Error("LogFFE: <r> must be a finite field element",0L,0L);
if ( FLD_FFE(hdZ) == FLD_FFE(hdR) ) {
if ( VAL_FFE(hdZ) == 0 )
return Error("LogFFE: <z> must be nonzero",0L,0L);
i = VAL_FFE(hdZ) - 1;
if ( VAL_FFE(hdR) == 0 )
return Error("LogFFE: <r> must be nonzero",0L,0L);
k = VAL_FFE(hdR) - 1;
o = ORD_FF(hdZ) - 1;
}
else if (ORD_FF(hdR)%ORD_FF(hdZ)==0&&ORD_FF(hdR)%(ORD_FF(hdZ)-1)<=1){
if ( VAL_FFE(hdZ) == 0 )
return Error("LogFFE: <z> must be nonzero",0L,0L);
i = (ORD_FF(hdR)-1) / (ORD_FF(hdZ)-1) * (VAL_FFE(hdZ)-1);
if ( VAL_FFE(hdR) == 0 )
return Error("LogFFE: <r> must be nonzero",0L,0L);
k = VAL_FFE(hdR) - 1;
o = ORD_FF(hdR) - 1;
}
else if (ORD_FF(hdZ)%ORD_FF(hdR)==0&&ORD_FF(hdZ)%(ORD_FF(hdR)-1)<=1){
if ( VAL_FFE(hdZ) == 0 )
return Error("LogFFE: <z> must be nonzero",0L,0L);
i = VAL_FFE(hdZ) - 1;
if ( VAL_FFE(hdR) == 0 )
return Error("LogFFE: <r> must be nonzero",0L,0L);
k = (ORD_FF(hdZ)-1) / (ORD_FF(hdR)-1) * (VAL_FFE(hdR)-1);
o = ORD_FF(hdZ) - 1;
}
else {
hdFF = CommonFF( hdZ, hdR );
if ( hdFF == 0 )
return Error(
"LogFFE: operands must have the same characteristic",
0L,0L);
else if ( hdFF == (TypHandle)1 )
return Error(
"LogFFE: smallest common superfield to large",
0L,0L);
field = SUCC_FF( hdFF );
if ( VAL_FFE(hdZ) == 0 )
return Error("LogFFE: <z> must be nonzero",0L,0L);
i = (VAL_FFE(hdZ)-1) * field[0] / (ORD_FF(hdZ)-1);
if ( VAL_FFE(hdR) == 0 )
return Error("LogFFE: <r> must be nonzero",0L,0L);
k = (VAL_FFE(hdR)-1) * field[0] / (ORD_FF(hdR)-1);
o = field[0];
}
}
a = 1;  b = 0;
while ( o != 0 ) {
t = b;  b = a - (k/o) * b;  a = t;
t = o;  o = k - (k/o) * o;  k = t;
}
if ( i % k != 0 )
return Error("LogFFE: <z> must be a power of <r>",0L,0L);
return INT_TO_HD( i / k * a );
}
TypHandle HdIntFFEs;
TypHandle HdLastIntFFE;
TypHandle ConvTabIntFFE ( q )
long                q;
{
long                i;
TypHandle           hdZ;
TypFFE              y;
TypFFE *            field;
if ( HdLastIntFFE != 0 && LEN_LIST(HdLastIntFFE) == q )
	return HdLastIntFFE;
for ( i = LEN_LIST(HdIntFFEs);  0 < i;  i-- ) {
	HdLastIntFFE = ELM_LIST( HdIntFFEs, i );
	if ( LEN_LIST(HdLastIntFFE) == q )
	    break;
}
if ( 0 < i )
	return HdLastIntFFE;
HdLastIntFFE = NewBag( T_LIST, SIZE_PLEN_PLIST(q) );
hdZ   = RootFiniteField(q);
field = SUCC_FF(FLD_FFE(hdZ));
SET_LEN_PLIST( HdLastIntFFE, q );
SET_ELM_PLIST( HdLastIntFFE, 1, INT_TO_HD(0) );
for ( i = 1, y = 1;  y != 0;  y = field[y], i++ ) {
	SET_ELM_PLIST( HdLastIntFFE, y+1, INT_TO_HD(i) );
}
ASS_LIST( HdIntFFEs, LEN_LIST(HdIntFFEs)+1, HdLastIntFFE );
return HdLastIntFFE;
}
TypHandle FunIntFFE ( hdCall )
TypHandle           hdCall;
{
TypHandle           hdZ;
TypHandle           ff;
long                q;
TypHandle           tab;
TypHandle           hdRes;
if ( SIZE(hdCall) != 2 * SIZE_HD )
return Error("usage: IntFFE( <z> )", 0L, 0L );
hdZ = EVAL( PTR(hdCall)[1] );
if ( TYPE(hdZ) != T_FFE )
return Error("IntFFE: <z> must be a finite field element",0L,0L);
ff = FLD_FFE(hdZ);
q  = SIZE_FF(ff);
tab = ConvTabIntFFE(q);
hdRes = ELM_PLIST( tab, VAL_FFE(hdZ)+1 );
if ( hdRes == 0 )
	return Error("IntFFE: <z> must lie in the prime field",0L,0L);
else
	return hdRes;
}
TypHandle       FunZ ( hdCall )
TypHandle           hdCall;
{
TypHandle           hdZ;
if ( SIZE(hdCall) != 2*SIZE_HD )
return Error("usage: Z( <q> )",0L,0L);
hdZ = EVAL( PTR(hdCall)[1] );
if ( TYPE(hdZ) != T_INT || HD_TO_INT(hdZ) <= 1 )
return Error("Z: <q> must be a prime power in [2..65536]",0L,0L);
hdZ = RootFiniteField( HD_TO_INT(hdZ) );
if ( hdZ == 0 )
return Error("Z: <q> must be a prime power in [2..65536]",0L,0L);
return hdZ;
}
void            InitFF ()
{
InstEvFunc( T_FFE, EvFFE );
InstPrFunc( T_FFE, PrFFE );
TabSum[  T_FFE ][ T_FFE ] = SumFFE;
TabSum[  T_INT ][ T_FFE ] = SumFFE;
TabSum[  T_FFE ][ T_INT ] = SumFFE;
TabDiff[ T_FFE ][ T_FFE ] = DiffFFE;
TabDiff[ T_INT ][ T_FFE ] = DiffFFE;
TabDiff[ T_FFE ][ T_INT ] = DiffFFE;
TabProd[ T_FFE ][ T_FFE ] = ProdFFE;
TabProd[ T_INT ][ T_FFE ] = ProdFFE;
TabProd[ T_FFE ][ T_INT ] = ProdFFE;
TabQuo[  T_FFE ][ T_FFE ] = QuoFFE;
TabQuo[  T_INT ][ T_FFE ] = QuoFFE;
TabQuo[  T_FFE ][ T_INT ] = QuoFFE;
TabPow[  T_FFE ][ T_INT ] = PowFFE;
TabEq[   T_FFE ][ T_FFE ] = EqFFE;
TabLt[   T_FFE ][ T_FFE ] = LtFFE;
HdFields  = NewBag( T_LIST, 0 );
HdIntFFEs = NewBag( T_LIST, SIZE_PLEN_PLIST(0) );
SET_LEN_PLIST( HdIntFFEs, 0 );
InstIntFunc( "IsFFE",   FunIsFFE   );
InstIntFunc( "LogFFE",  FunLogFFE  );
InstIntFunc( "IntFFE",  FunIntFFE  );
InstIntFunc( "Z",       FunZ       );
}
/* 当前文件是D:\Read\function.c*/


void            ChangeEnv ( hdEnv )
TypHandle           hdEnv;
{
register TypHandle  hdDo, hdComm, hdTmp, hdUndo;
register TypHandle  * ptUndo,  * ptDef,  * ptDo;
register short      nr,  i;
hdDo   = 0;
hdComm = hdEnv;
while ( hdComm != 0 && PTR(hdComm)[1] != HdTrue ) {
hdTmp          = PTR(hdComm)[0];
PTR(hdComm)[0] = hdDo;
hdDo           = hdComm;
hdComm         = hdTmp;
}
hdUndo = HdExec;
while ( hdUndo != hdComm ) {
ptUndo = PTR(hdUndo);
ptDef  = PTR(ptUndo[2]);
nr = (SIZE(ptUndo[2])-2*sizeof(short)-2*SIZE_HD)/SIZE_HD;
for ( i = 1; i <= nr; ++i ) {
hdTmp = ptUndo[i+4];
ptUndo[i+4] = PTR(ptDef[i])[0];
PTR(ptDef[i])[0] = hdTmp;
}
ptUndo[1] = HdFalse;
hdUndo    = ptUndo[0];
}
while ( hdDo != 0 ) {
ptDo   = PTR(hdDo);
ptDef  = PTR(ptDo[2]);
nr = (SIZE(ptDo[2])-2*sizeof(short)-2*SIZE_HD)/SIZE_HD;
for ( i = 1; i <= nr; ++i ) {
hdTmp = ptDo[i+4];
ptDo[i+4] = PTR(ptDef[i])[0];
PTR(ptDef[i])[0] = hdTmp;
}
ptDo[1] = HdTrue;
hdTmp   = ptDo[0];
ptDo[0] = hdComm;
hdComm  = hdDo;
hdDo    = hdTmp;
}
HdExec = hdComm;
}
TypHandle       EvFunccall ( hdCall )
TypHandle           hdCall;
{
TypHandle           hdDef,  hdExec,  hdRes = 0,  hdOld;
TypHandle           hdStat,  hd;
TypHandle           hdTilde;
short               nrArg,  nrLoc,  i,  trace;
unsigned long       time = 0,  sime = 0;
hdStat = HdStat;
hdDef = EVAL( PTR(hdCall)[0] );
if ( TYPE(hdDef) != T_FUNCTION && TYPE(hdDef) != T_FUNCINT )
return Error("Function: <function> must be a function",0L,0L);
if ( TYPE(hdDef) == T_FUNCINT ) {
if ( IsProfiling ) {
IsProfiling = 1;
time = SyTime()-Timesum;
for ( i = 0; i < SIZE(HdTimes)/SIZE_HD; i += 5 ) {
if ( PTR(HdTimes)[i] == hdDef ) {
sime = SyTime() - HD_TO_INT( PTR(HdTimes)[i+4] );
break;
}
}
if ( i == SIZE(HdTimes)/SIZE_HD ) {
sime = SyTime();
}
}
hdRes = (** (TypHandle(**)P(()))PTR(hdDef)) ( hdCall );
if ( IsProfiling == 1 ) {
time = SyTime()-Timesum-time;  Timesum += time;
for ( i = 0; i < SIZE(HdTimes)/SIZE_HD; i += 5 ) {
if ( PTR(HdTimes)[i] == hdDef ) {
PTR(HdTimes)[i+2]=INT_TO_HD(HD_TO_INT(PTR(HdTimes)[i+2])+1);
PTR(HdTimes)[i+3]=INT_TO_HD(HD_TO_INT(PTR(HdTimes)[i+3])+time);
PTR(HdTimes)[i+4]=INT_TO_HD(SyTime()-sime);
break;
}
}
if ( i == SIZE(HdTimes)/SIZE_HD ) {
Resize( HdTimes, SIZE(HdTimes) + 5*SIZE_HD );
PTR(HdTimes)[i]   = hdDef;
PTR(HdTimes)[i+1] = PTR(hdCall)[0];
PTR(HdTimes)[i+2] = INT_TO_HD(1);
PTR(HdTimes)[i+3] = INT_TO_HD(time);
PTR(HdTimes)[i+4] = INT_TO_HD(SyTime()-sime);
}
while ( 0 < i
&& (long)PTR(HdTimes)[i-2] < (long)PTR(HdTimes)[i+3] ) {
hd = PTR(HdTimes)[i-5];
PTR(HdTimes)[i-5] = PTR(HdTimes)[i];
PTR(HdTimes)[i]   = hd;
hd = PTR(HdTimes)[i-4];
PTR(HdTimes)[i-4] = PTR(HdTimes)[i+1];
PTR(HdTimes)[i+1] = hd;
hd = PTR(HdTimes)[i-3];
PTR(HdTimes)[i-3] = PTR(HdTimes)[i+2];
PTR(HdTimes)[i+2] = hd;
hd = PTR(HdTimes)[i-2];
PTR(HdTimes)[i-2] = PTR(HdTimes)[i+3];
PTR(HdTimes)[i+3] = hd;
hd = PTR(HdTimes)[i-1];
PTR(HdTimes)[i-1] = PTR(HdTimes)[i+4];
PTR(HdTimes)[i+4] = hd;
i -= 5;
}
}
return( hdRes );
}
EnterKernel();
trace = 0;
nrArg = ((short*)((char*)PTR(hdDef) + SIZE(hdDef)))[ -2 ];
nrLoc = ((short*)((char*)PTR(hdDef) + SIZE(hdDef)))[ -1 ];
if ( nrArg == -1 ) {
hdRes = NewBag( T_LIST, SIZE_PLEN_PLIST( SIZE(hdCall)/SIZE_HD-1 ) );
SET_LEN_PLIST( hdRes, SIZE(hdCall)/SIZE_HD-1 );
for ( i = 1; i < SIZE(hdCall)/SIZE_HD; i++ ) {
hd = EVAL( PTR(hdCall)[i] );
if ( TYPE(hd) == T_VOID )
hd = Error("illegal void argument",0L,0L);
SET_ELM_PLIST( hdRes, i, hd );
}
nrArg = 1;
trace = 2;
}
else if ( nrArg != SIZE(hdCall) / SIZE_HD - 1 )
return Error("Function: number of args must be %d",(long)nrArg,0L);
if ( nrLoc < 0 ) {
trace |= 1;  nrLoc = -nrLoc-1;
Pr("\n%2>",0L,0L);  Print( PTR(hdCall)[0] );  Pr("%<( ",0L,0L);
}
hdExec = NewBag( T_EXEC, SIZE_HD*(2*nrArg+nrLoc+5) );
if ( PTR(hdDef)[nrArg+nrLoc+1] == 0 )  PTR(hdExec)[0] = HdExec;
else PTR(hdExec)[0] = PTR(hdDef)[nrArg+nrLoc+1];
PTR(hdExec)[1] = HdFalse;
PTR(hdExec)[2] = hdDef;
PTR(hdExec)[3] = hdCall;
PTR(hdExec)[4] = HdExec;
for ( i = 1; i <= nrArg; ++i ) {
if ( ! (trace & 2) )
hdRes = EVAL( PTR(hdCall)[i] );
if ( TYPE(hdRes) == T_VOID )
hdRes = Error("illegal void argument",0L,0L);
PTR(hdExec)[i+4] = hdRes;
PTR(hdExec)[nrArg+nrLoc+i+4] = hdRes;
if ( trace & 1 ) {
Pr("%>",0L,0L);  Print( hdRes );
if ( i < nrArg )  Pr("%<, ",0L,0L);
else              Pr("%< )",0L,0L);
}
}
hdOld = HdExec;
ChangeEnv( hdExec );
if ( IsProfiling ) {
IsProfiling = 1;
time = SyTime()-Timesum;
for ( i = 0; i < SIZE(HdTimes)/SIZE_HD; i += 5 ) {
if ( PTR(HdTimes)[i] == PTR(hdDef)[0] ) {
sime = SyTime() - HD_TO_INT( PTR(HdTimes)[i+4] );
break;
}
}
if ( i == SIZE(HdTimes)/SIZE_HD ) {
sime = SyTime();
}
}
StrStat = "";  HdStat = PTR(hdDef)[0];
hdTilde = PTR(HdTilde)[0];
PTR(HdTilde)[0] = 0;
hdRes =  EVAL( PTR(hdDef)[0] );
if ( hdRes == HdReturn )
hdRes = PTR(hdRes)[0];
else
hdRes = HdVoid;
if ( IsProfiling == 1 ) {
time = SyTime()-Timesum-time;  Timesum += time;
for ( i = 0; i < SIZE(HdTimes)/SIZE_HD; i += 5 ) {
if ( PTR(HdTimes)[i] == PTR(hdDef)[0] ) {
PTR(HdTimes)[i+2]=INT_TO_HD(HD_TO_INT(PTR(HdTimes)[i+2])+1);
PTR(HdTimes)[i+3]=INT_TO_HD(HD_TO_INT(PTR(HdTimes)[i+3])+time);
PTR(HdTimes)[i+4]=INT_TO_HD(SyTime()-sime);
break;
}
}
if ( i == SIZE(HdTimes)/SIZE_HD ) {
Resize( HdTimes, SIZE(HdTimes) + 5*SIZE_HD );
PTR(HdTimes)[i]   = PTR(hdDef)[0];
PTR(HdTimes)[i+1] = PTR(hdCall)[0];
PTR(HdTimes)[i+2] = INT_TO_HD(1);
PTR(HdTimes)[i+3] = INT_TO_HD(time);
PTR(HdTimes)[i+4] = INT_TO_HD(SyTime()-sime);
}
while ( 0 < i
&& (long)PTR(HdTimes)[i-2] < (long)PTR(HdTimes)[i+3] ) {
hd = PTR(HdTimes)[i-5];
PTR(HdTimes)[i-5] = PTR(HdTimes)[i];
PTR(HdTimes)[i]   = hd;
hd = PTR(HdTimes)[i-4];
PTR(HdTimes)[i-4] = PTR(HdTimes)[i+1];
PTR(HdTimes)[i+1] = hd;
hd = PTR(HdTimes)[i-3];
PTR(HdTimes)[i-3] = PTR(HdTimes)[i+2];
PTR(HdTimes)[i+2] = hd;
hd = PTR(HdTimes)[i-2];
PTR(HdTimes)[i-2] = PTR(HdTimes)[i+3];
PTR(HdTimes)[i+3] = hd;
hd = PTR(HdTimes)[i-1];
PTR(HdTimes)[i-1] = PTR(HdTimes)[i+4];
PTR(HdTimes)[i+4] = hd;
i -= 5;
}
}
ChangeEnv( hdOld );
if ( trace & 1 ) {
Pr("\n%>",0L,0L); Print( PTR(hdCall)[0] );  Pr("%< returns",0L,0L);
if ( hdRes != HdVoid )  Print( hdRes );
Pr("%<",0L,0L);
}
HdStat = hdStat;
PTR(HdTilde)[0] = hdTilde;
ExitKernel(hdRes);
return hdRes;
}
TypHandle       EvFunction ( hdDef )
TypHandle           hdDef;
{
return hdDef;
}
TypHandle       EvMakefunc ( hdFun )
TypHandle           hdFun;
{
TypHandle           Result;
short               nrArg,  nrLoc, i;
Result = NewBag( T_FUNCTION, SIZE(hdFun) );
nrArg = ((short*)((char*)PTR(hdFun) + SIZE(hdFun)))[ -2 ];
nrLoc = ((short*)((char*)PTR(hdFun) + SIZE(hdFun)))[ -1 ];
((short*)((char*)PTR(Result) + SIZE(Result)))[ -2 ] = nrArg;
((short*)((char*)PTR(Result) + SIZE(Result)))[ -1 ] = nrLoc;
if ( nrArg == -1 )  nrArg = 1;
for ( i = 0; i <= nrArg+nrLoc; ++i )
PTR(Result)[i] = PTR(hdFun)[i];
PTR(Result)[nrArg+nrLoc+1] = HdExec;
return Result;
}
TypHandle       EvReturn ( hdRet )
TypHandle           hdRet;
{
TypHandle           hd;
if ( PTR(hdRet)[0] == HdReturn )
hd = HdReturn;
else if ( PTR(hdRet)[0] == HdVoid )
hd = HdVoid;
else
hd = EVAL( PTR(hdRet)[0] );
PTR(HdReturn)[0] = hd;
return HdReturn;
}
TypHandle       FunIsFunc ( hdCall )
TypHandle           hdCall;
{
TypHandle           hdObj;
if ( SIZE(hdCall) != 2 * SIZE_HD )
return Error("usage: IsFunc( <obj> )",0L,0L);
hdObj = EVAL( PTR(hdCall)[1] );
if ( hdObj == HdVoid )
return Error("IsFunc: function must return a value",0L,0L);
if ( TYPE(hdObj) == T_FUNCTION || TYPE(hdObj) == T_FUNCINT )
return HdTrue;
else
return HdFalse;
}
TypHandle       FunTrace ( hdCall )
TypHandle           hdCall;
{
TypHandle           hdDef;
short               nrLoc,  i;
for ( i = 1; i < SIZE(hdCall)/SIZE_HD; ++i ) {
hdDef = EVAL( PTR(hdCall)[i] );
if ( TYPE(hdDef) == T_FUNCINT )
return Error("sorry I can not trace internal function",0L,0L);
if ( TYPE(hdDef) != T_FUNCTION )
return Error("usage: Trace( <function>... )",0L,0L);
nrLoc = ((short*)((char*)PTR(hdDef)+SIZE(hdDef)))[-1];
if ( 0 <= nrLoc )  nrLoc = -nrLoc-1;
((short*)((char*)PTR(hdDef)+SIZE(hdDef)))[-1] = nrLoc;
}
return HdVoid;
}
TypHandle       FunUntrace ( hdCall )
TypHandle           hdCall;
{
TypHandle           hdDef;
short               nrLoc, i;
for ( i = 1; i < SIZE(hdCall)/SIZE_HD; ++i ) {
hdDef = EVAL( PTR(hdCall)[i] );
if ( TYPE(hdDef) != T_FUNCTION )
return Error("usage: Untrace( <function>... )",0L,0L);
nrLoc = ((short*)((char*)PTR(hdDef)+SIZE(hdDef)))[-1];
if ( nrLoc < 0 )  nrLoc = -nrLoc-1;
((short*)((char*)PTR(hdDef)+SIZE(hdDef)))[-1] = nrLoc;
}
return HdVoid;
}
TypHandle       FunProfile ( hdCall )
TypHandle           hdCall;
{
TypHandle           hdArg;
short               i;
long                total;
if ( 2 * SIZE_HD < SIZE(hdCall) ) {
return Error("usage: Profile( true|false ) or Profile()",0L,0L);
}
else if ( SIZE(hdCall) == 2 * SIZE_HD ) {
hdArg = EVAL( PTR(hdCall)[1] );
if ( hdArg == HdTrue ) {
IsProfiling = 2;
Resize( HdTimes, 0 * SIZE_HD );
}
else if ( hdArg == HdFalse ) {
IsProfiling = 0;
}
else {
return Error("usage: Profile( true|false ) or Profile()",0L,0L);
}
}
else {
total = 0;
for ( i = 0; i < SIZE(HdTimes)/SIZE_HD; i += 5 )
total = total + HD_TO_INT( PTR(HdTimes)[i+3] );
if ( total == 0 )  total = 1;
Pr(" count    time percent time/call child function\n",0L,0L);
for ( i = 0; i < SIZE(HdTimes)/SIZE_HD; i += 5 ) {
Pr("%6d  ", HD_TO_INT( PTR(HdTimes)[i+2] ), 0L );
Pr("%6d  ", HD_TO_INT( PTR(HdTimes)[i+3] ), 0L );
Pr("%6d  ", 100 * HD_TO_INT(PTR(HdTimes)[i+3]) / total, 0L );
Pr("%6d  ", HD_TO_INT( PTR(HdTimes)[i+3] ) /
HD_TO_INT( PTR(HdTimes)[i+2] ), 0L );
Pr("%6d  ", HD_TO_INT( PTR(HdTimes)[i+4] ), 0L );
Print( PTR(HdTimes)[i+1] );
Pr("\n",0L,0L);
}
Pr("        %6d     100                  TOTAL\n",total-1,0L);
}
return HdVoid;
}
TypHandle FunApplyFunc ( hdCall )
TypHandle		hdCall;
{
TypHandle           hdNew;		
TypHandle           hdFunc;
TypHandle           hdList;
long                i;
if ( SIZE(hdCall) != 3*SIZE_HD )
	return Error( "usage: ApplFunc( <func>, <list> )", 0L, 0L );
hdFunc = EVAL(PTR(hdCall)[1]);
hdList = EVAL(PTR(hdCall)[2]);
if ( ! IS_DENSE_LIST(hdList) )
	return Error( "<list> must be a dense list", 0L, 0L );
hdNew = NewBag( T_FUNCCALL, SIZE_HD*(1+LEN_LIST(hdList)) );
PTR(hdNew)[0] = hdFunc;
for ( i = LEN_LIST(hdList);  0 < i;  i-- )
	PTR(hdNew)[i] = ELMF_LIST( hdList, i );
return EVAL(hdNew);
}
void            PrFuncint ( hdFun )
TypHandle           hdFun;
{
Pr("%2>function%< %>(...)%< %>internal;%< %>end%2<",0L,0L);
}
long            prFull;
void            PrFunction ( hdFun )
TypHandle           hdFun;
{
short               nrArg,  nrLoc,  i;
Pr("%5>function%< ( %>",0L,0L);
nrArg = ((short*)((char*)PTR(hdFun) + SIZE(hdFun)))[-2];
if ( nrArg == -1 )  nrArg = 1;
for ( i = 1; i <= nrArg; ++i ) {
Print( PTR(hdFun)[i] );
if ( i != nrArg )  Pr("%<, %>",0L,0L);
}
Pr(" %<)",0L,0L);
if ( prFull == 0 ) {
Pr(" ...%4< ",0L,0L);
}
else {
Pr("\n",0L,0L);
nrLoc = ((short*)((char*)PTR(hdFun) + SIZE(hdFun)))[-1];
if ( nrLoc < 0 )  nrLoc = -nrLoc-1;
if ( nrLoc >= 1 ) {
Pr("%>local  ",0L,0L);
for ( i = 1; i <= nrLoc; ++i ) {
Print( PTR(hdFun)[i+nrArg] );
if ( i != nrLoc )  Pr("%<, %>",0L,0L);
}
Pr("%<;\n",0L,0L);
}
Print( PTR(hdFun)[0] );
Pr(";%4<\n",0L,0L);
}
Pr("end",0L,0L);
}
void            PrintFunction ( hdFun )
TypHandle           hdFun;
{
prFull = 1L;
PrFunction( hdFun );
prFull = 0L;
}
void            PrFunccall ( hdCall )
TypHandle           hdCall;
{
long                i;
Pr("%2>",0L,0L);  Print( PTR(hdCall)[0] ); Pr("%<( %>",0L,0L);
for ( i = 1; i < SIZE(hdCall)/SIZE_HD; ++i ) {
Print( PTR(hdCall)[i] );
if ( i != SIZE(hdCall)/SIZE_HD-1 )
Pr("%<, %>",0L,0L);
}
Pr(" %2<)",0L,0L);
}
void            PrReturn ( hdRet )
TypHandle           hdRet;
{
if ( PTR(hdRet)[0] == HdReturn ) {
Pr("quit",0L,0L);
}
else if ( PTR(hdRet)[0] == HdVoid ) {
Pr("return",0L,0L);
}
else {
Pr("%2>return%< %>",0L,0L);
Print( PTR(hdRet)[0] );
Pr("%2<",0L,0L);
}
}
void            InitFunc ()
{
InstEvFunc( T_FUNCCALL, EvFunccall  );
InstEvFunc( T_FUNCTION, EvFunction  );
InstEvFunc( T_FUNCINT,  EvFunction  );
InstEvFunc( T_MAKEFUNC, EvMakefunc  );
InstEvFunc( T_RETURN,   EvReturn    );
InstPrFunc( T_FUNCCALL, PrFunccall  );
InstPrFunc( T_FUNCTION, PrFunction  );
InstPrFunc( T_FUNCINT,  PrFuncint   );
InstPrFunc( T_MAKEFUNC, PrFunction  );
InstPrFunc( T_RETURN,   PrReturn    );
InstIntFunc( "IsFunc",      FunIsFunc    );
InstIntFunc( "TraceFunc",   FunTrace     );
InstIntFunc( "UntraceFunc", FunUntrace   );
InstIntFunc( "ApplyFunc",   FunApplyFunc );
HdTimes = NewBag( T_LIST, 0 );
InstIntFunc( "Profile", FunProfile );
HdReturn = NewBag( T_RETURN, SIZE_HD );
}
/* 当前文件是D:\Read\gasman.c*/

char            * NameType [] = {
"void",
"integer", "integer (> 2^28)", "integer (< -2^28)",
"rational", "cyclotomic", "unknown",
"finite field element",
"permutation", "permutation",
"word", "sparse word", "agword",
"boolean", "character",
"function", "internal function",
"list", "set", "vector", "finite field vector", "boolean list",
"string", "range",
"record",
"matrix (extended)", "matffe (extended)", "list (extended)",
"variable", "autoread variable", "var assignment",
"list element", "list element", "sublist", "sublist",
"list assignment","list assignment","list assignment","list assignment",
"record element", "record assignment",
"+", "-", "*", "/", "mod", "^", "commutator",
"not", "and", "or", "=", "<>", "<", ">=", "<=", ">", "in",
"function call", "statement sequence", "if statement",
"for loop", "while loop", "repeat loop", "return statement",
"var permutation", "var function", "var list", "var string", "var range",
"var record",
"cycle", "finite field",
"abstract generator",
"aggroup", "polycyclic presentation",
"ag exponent vector", "ag exponent/generator",
"record name",
"stack frame",
"free bag"
};
unsigned long   GasmanStatAlive [T_ILLEGAL];
unsigned long   GasmanStatASize [T_ILLEGAL];
unsigned long   GasmanStatTotal [T_ILLEGAL];
unsigned long   GasmanStatTSize [T_ILLEGAL];
struct {
long        handles;
long        data;
char        name[4];
}               Size [] = {
{         0,               0,  "voi" },
{         0,               0,  "123" },
{         0,              -1,  "+12" },
{         0,              -1,  "-12" },
{ 2*SIZE_HD,               0,  "1/2" },
{  -SIZE_HD,  -sizeof(short),  "cyc" },
{         0,    sizeof(long),  "unk" },
{   SIZE_HD,   sizeof(short),  "ffe" },
{         0,              -1,  "prm" },
{         0,              -1,  "prm" },
{  -SIZE_HD,               0,  "wrd" },
{   SIZE_HD,              -1,  "swd" },
{   SIZE_HD,              -1,  "agw" },
{         0,               0,  "bol" },
{         0,               1,  "chr" },
{  -SIZE_HD, 2*sizeof(short),  "-> " },
{         0,    sizeof(long),  "fni" },
{  -SIZE_HD,               0,  "[1]" },
{  -SIZE_HD,               0,  "{1}" },
{  -SIZE_HD,               0,  "vec" },
{   SIZE_HD,              -1,  "vff" },
{   SIZE_HD,              -1,  "bli" },
{         0,              -1,  "str" },
{ 2*SIZE_HD,               0,  "ran" },
{  -SIZE_HD,               0,  "rec" },
{  -SIZE_HD,               0,  "max" },
{  -SIZE_HD,               0,  "mfx" },
{  -SIZE_HD,               0,  "lsx" },
{   SIZE_HD,              -1,  "var" },
{   SIZE_HD,              -1,  "aut" },
{ 2*SIZE_HD,               0,  "v:=" },
{ 2*SIZE_HD,               0,  "l[]" },
{ 2*SIZE_HD,    sizeof(long),  "l[]" },
{ 2*SIZE_HD,               0,  "l{}" },
{ 2*SIZE_HD,    sizeof(long),  "l{}" },
{ 2*SIZE_HD,               0,  "l:=" },
{ 2*SIZE_HD,    sizeof(long),  "l:=" },
{ 2*SIZE_HD,               0,  "l:=" },
{ 2*SIZE_HD,    sizeof(long),  "l:=" },
{ 2*SIZE_HD,               0,  "r.e" },
{ 2*SIZE_HD,               0,  "r:=" },
{ 2*SIZE_HD,               0,  "+  " },
{ 2*SIZE_HD,               0,  "-  " },
{ 2*SIZE_HD,               0,  "*  " },
{ 2*SIZE_HD,               0,  "/  " },
{ 2*SIZE_HD,               0,  "mod" },
{ 2*SIZE_HD,               0,  "^  " },
{ 2*SIZE_HD,               0,  "com" },
{   SIZE_HD,               0,  "not" },
{ 2*SIZE_HD,               0,  "and" },
{ 2*SIZE_HD,               0,  "or " },
{ 2*SIZE_HD,               0,  "=  " },
{ 2*SIZE_HD,               0,  "<> " },
{ 2*SIZE_HD,               0,  "<  " },
{ 2*SIZE_HD,               0,  ">= " },
{ 2*SIZE_HD,               0,  "<= " },
{ 2*SIZE_HD,               0,  ">  " },
{ 2*SIZE_HD,               0,  "in " },
{  -SIZE_HD,               0,  "f()" },
{  -SIZE_HD,               0,  ";;;" },
{  -SIZE_HD,               0,  "if " },
{ 3*SIZE_HD,               0,  "for" },
{ 2*SIZE_HD,               0,  "whi" },
{ 2*SIZE_HD,               0,  "rep" },
{  -SIZE_HD,               0,  "ret" },
{  -SIZE_HD,               0,  "mpr" },
{  -SIZE_HD, 2*sizeof(short),  "mfu" },
{  -SIZE_HD,               0,  "mls" },
{         0,              -1,  "mst" },
{  -SIZE_HD,               0,  "mrn" },
{  -SIZE_HD,               0,  "mre" },
{  -SIZE_HD,               0,  "cyc" },
{         0,              -1,  "ff " },
{   SIZE_HD,              -1,  "gen" },
{  -SIZE_HD,               0,  "agp" },
{  -SIZE_HD,               0,  "pcp" },
{         0,              -1,  "age" },
{         0,              -1,  "agl" },
{         0,              -1,  "rnm" },
{  -SIZE_HD,               0,  "stk" },
{         0,              -1,  "fre" }
};
long            NrHandles ( type, size )
unsigned int        type;
unsigned long       size;
{
register long       hs, is;
hs = Size[type].handles;
if ( hs >= 0 )  return hs / SIZE_HD;
is = Size[type].data;
if ( is >= 0 )  return (size - is) / SIZE_HD;
return ( hs * (long)size / (hs + is) ) / SIZE_HD;
}

void            EnterKernel ()
{
++NrNewHandles;
if ( SIZE_HD * NrNewHandles == SIZE(HdNewHandles) )
Resize( HdNewHandles, SIZE(HdNewHandles) + 4096 * SIZE_HD );
}
void            ExitKernel ( hd )
TypHandle           hd;
{
unsigned long       i;
if ( hd != (TypHandle)2 ) {
while ( PTR(HdNewHandles)[--NrNewHandles] != 0 )
PTR(HdNewHandles)[NrNewHandles] = 0;
if ( hd != 0 )
PTR(HdNewHandles)[NrNewHandles++] = hd;
}
else {
i = NrNewHandles;  NrNewHandles = 0;
while ( PTR(HdNewHandles)[NrNewHandles] != 0 )
++NrNewHandles;
while ( --i > NrNewHandles )
PTR(HdNewHandles)[i] = 0;
}
}
TypHandle       HdFree;
TypHandle       FreeHandle;
unsigned long   NrFreeHandles;
unsigned long   IsResizeCall;
TypHandle       HdResize;
TypHandle       * FirstBag;
char            * asStr ( i )
unsigned long       i;
{
static char        s [7];
s[0] = i < 100000 ? ' ' : '0' + i / 100000 % 10;
s[1] = i <  10000 ? ' ' : '0' + i /  10000 % 10;
s[2] = i <   1000 ? ' ' : '0' + i /   1000 % 10;
s[3] = i <    100 ? ' ' : '0' + i /    100 % 10;
s[4] = i <     10 ? ' ' : '0' + i /     10 % 10;
s[5] =                    '0' + i          % 10;
s[6] = '\0';
return s;
}
void            CollectGarb ()
{
TypHandle           first,  last,  h;
TypHandle           * d,  * s,  * e;
long                i;
unsigned long       NrBags = 0;
if ( SyGasman )  SyFputs("#G  collect garbage, ",3);
first = last = HdNewHandles;
PTR(last)[-1] = 0;
while ( first != 0 ) {
for ( i = NrHandles(TYPE(first),SIZE(first))-1; i >= 0; --i ) {
h = PTR(first)[i];
if ( h != 0 && ((long)h & T_INT) == 0 && PTR(h)[-1] == h ) {
PTR(last)[-1] = h;
last = h;
PTR(last)[-1] = 0;
}
}
h = PTR(first)[-1];
PTR(first)[-1] = (TypHandle)((unsigned long)first + 1);
first = h;
++NrBags;
}
SyPinfo( 1, NrBags );
if ( SyGasman ) {
	SyFputs( asStr(NrBags), 3 );
	SyFputs( " used, ", 3 );
}
NrBags = 0;
d = s = FirstBag-1;
while ( s < PTR(HdFree)-1 ) {
#if defined(SPEC_CPU2000_LP64) || defined(SPEC_CPU2000_P64)
if ( ((long)*s & 7L) == 0 ) {
#else
if ( ((long)*s & 3L) == 0 ) {
#endif
#ifdef  STAT
GasmanStatAlive[((TypHandle)((long)*s & ~3L))->type]--;
GasmanStatASize[((TypHandle)((long)*s & ~3L))->type]
-= ((TypHandle)((long)*s & ~3L))->size;
#endif
#if defined(SPEC_CPU2000_LP64) || defined(SPEC_CPU2000_P64)
((TypHandle)((long)*s & ~7L))->ptr = (TypHandle*)FreeHandle;
((TypHandle)((long)*s & ~7L))->type = T_ILLEGAL;
FreeHandle = (TypHandle)((long)*s & ~7L);
s = s + (SIZE((TypHandle)((long)*s & ~7L))+2*SIZE_HD-1) / SIZE_HD;
#else
((TypHandle)((long)*s & ~3L))->ptr = (TypHandle*)FreeHandle;
((TypHandle)((long)*s & ~3L))->type = T_ILLEGAL;
FreeHandle = (TypHandle)((long)*s & ~3L);
s = s + (SIZE((TypHandle)((long)*s & ~3L))+2*SIZE_HD-1) / SIZE_HD;
#endif
++NrBags;
++NrFreeHandles;
}
#if defined(SPEC_CPU2000_LP64) || defined(SPEC_CPU2000_P64)
else if ( ((long)*s & 7L) == 1 ) {
((TypHandle)((long)*s & ~7L))->ptr = d+1;
e = s + (SIZE((TypHandle)((long)*s & ~7L))+2*SIZE_HD-1) / SIZE_HD;
*d++ = (TypHandle)((long)*s++ & ~7L);
#else
else if ( ((long)*s & 3L) == 1 ) {
((TypHandle)((long)*s & ~3L))->ptr = d+1;
e = s + (SIZE((TypHandle)((long)*s & ~3L))+2*SIZE_HD-1) / SIZE_HD;
*d++ = (TypHandle)((long)*s++ & ~3L);
#endif
if ( d != s )
while ( s < e )  *d++ = *s++;
else
s = d = e;
}
#if defined(SPEC_CPU2000_LP64) || defined(SPEC_CPU2000_P64)
else if ( ((long)*s & 7L) == 2 ) {
#else
else if ( ((long)*s & 3L) == 2 ) {
#endif
s = s + ((long)*s + SIZE_HD) / SIZE_HD;
}
else {
SyFputs("Gasman: is caught off base by a bag with tag 3.\n",3);
SyExit( 1 );
}
}
SyPinfo( 2, NrBags );
if ( SyGasman ) {
	SyFputs( asStr(NrBags), 3 );
	SyFputs( " dead, ", 3 );
}
NrBags = 0;
s = d+1;
e = PTR(HdFree);
while ( s < e )  *s++ = 0;
HdFree->size += (char*)PTR(HdFree) - (char*)(d+1);
HdFree->ptr  = d+1;
PTR(HdFree)[-1] = HdFree;
SyPinfo( 3, SIZE(HdFree) );
SyPinfo( 4, ((long)PTR(HdFree)-(long)HdFree+SIZE(HdFree)) );
if ( SyGasman ) {
SyFputs(asStr(SIZE(HdFree)/1024),3);
SyFputs(" KB free, ",3);
SyFputs(asStr(((long)PTR(HdFree)-(long)HdFree+SIZE(HdFree))/1024),3);
SyFputs(" KB total\n",3);
}
}
unsigned long   lastType,  lastSize;
TypHandle       NewBag ( type, size )
unsigned int        type;
unsigned long       size;
{
long                needed, wished;
TypHandle           hdBag;
TypHandle           * s,  * d,  * e;
TypHandle           h;
if ( IsResizeCall ) {
hdBag = HdResize;
}
else if ( FreeHandle != (TypHandle)0 ) {
hdBag      = FreeHandle;
FreeHandle = (TypHandle)PTR(FreeHandle);
NrFreeHandles--;
}
else {
CollectGarb();
if ( NrFreeHandles < 20000 ) {
needed = (char*)FirstBag - (char*)HdFree;
if ( SIZE(HdFree) < needed ) {
if ( SyGetmem( needed ) != (char*)-1 ) {
HdFree->size += needed;
}
else {
SyFputs("Gasman: has no handle for a bag of type ",3);
SyFputs(Size[type].name,3);
SyFputs(" and size ",3);  SyFputs(asStr(size),3);
SyFputs(".\n",3);
SyExit( 1 );
}
}
d = PTR(HdFree) + needed / SIZE_HD - 1;
s = PTR(HdFree) - 1;
e = (FirstBag-1);
while ( e <= s )  *d-- = *s--;
for ( h = HdFree; h < (TypHandle)(FirstBag-1); ++h ) {
if ( h->type != T_ILLEGAL )
h->ptr += needed / SIZE_HD;
}
HdFree->size -= needed;
FirstBag = FirstBag + needed / SIZE_HD;
d = (TypHandle*)h;
for ( ; h+2 < (TypHandle)(FirstBag-1); ++h ) {
h->ptr = (TypHandle*)(h+1);
h->type = T_ILLEGAL;
++NrFreeHandles;
}
h->ptr = (TypHandle*)FreeHandle;
FreeHandle = (TypHandle)d;
}
hdBag = FreeHandle;
FreeHandle = (TypHandle)PTR(FreeHandle);
}
if ( SIZE(HdFree) < size + SIZE_HD ) {
CollectGarb();
if ( SIZE(HdFree) < size + SIZE_HD ) {
needed = ( size + SIZE_HD - SIZE(HdFree) + 1023 ) & ~1023;
wished = ( ((char*)PTR(HdFree) - (char*)HdFree + size) / 4
+ size + SIZE_HD - SIZE(HdFree) + 1023 ) & ~1023;
if ( SyGetmem( (long)wished ) != (char*)-1 ) {
HdFree->size += wished;
}
else if ( SyGetmem( (long)needed ) != (char*)-1 ) {
HdFree->size += needed;
}
else {
SyFputs("Gasman: has no space for a bag of type ",3);
SyFputs(Size[type].name,3);
SyFputs(" and size ",3);  SyFputs(asStr(size),3);
SyFputs(".\n",3);
SyExit( 1 );
}
}
}
if ( PTR(HdFree)[-1] != HdFree ) {
SyFputs("Gasman: last bag of type ",3);
SyFputs(Size[lastType].name,3);
SyFputs(" and size ",3);  SyFputs(asStr(lastSize),3);
SyFputs(" has overwritten the free bag.\n",3);
SyExit( 1 );
}
lastType = type;  lastSize = size;
hdBag->type = type;
hdBag->name[0] = Size[type].name[0];
hdBag->name[1] = Size[type].name[1];
hdBag->name[2] = Size[type].name[2];
hdBag->size = size;
hdBag->ptr  = HdFree->ptr;
PTR(hdBag)[-1] = hdBag;
HdFree->name[0] = 'f';
HdFree->name[1] = 'r';
HdFree->name[2] = 'e';
HdFree->size -= (size + SIZE_HD + SIZE_HD-1) & ~(SIZE_HD-1);
HdFree->ptr  += (size + SIZE_HD + SIZE_HD-1) / SIZE_HD;
PTR(HdFree)[-1] = HdFree;
if ( ! IsResizeCall ) {
PTR(HdNewHandles)[NrNewHandles++] = hdBag;
if ( SIZE_HD * NrNewHandles == SIZE(HdNewHandles) )
Resize( HdNewHandles, SIZE(HdNewHandles) + 4096 * SIZE_HD );
}
#ifdef  STAT
GasmanStatAlive[type]++;
GasmanStatASize[type] += size;
GasmanStatTotal[type]++;
GasmanStatTSize[type] += size;
#endif
return hdBag;
}
void            Retype ( hdBag, newType )
TypHandle           hdBag;
unsigned int        newType;
{
#ifdef  STAT
GasmanStatAlive[hdBag->type]--;
GasmanStatAlive[newType]++;
GasmanStatASize[hdBag->type] -= hdBag->size;
GasmanStatASize[newType] += hdBag->size;
GasmanStatTotal[hdBag->type]--;
GasmanStatTotal[newType]++;
GasmanStatTSize[hdBag->type] -= hdBag->size;
GasmanStatTSize[newType] += hdBag->size;
#endif
hdBag->type = newType;
}
void            Resize ( hdBag, newSize )
TypHandle           hdBag;
unsigned long       newSize;
{
unsigned long       oldSize;
unsigned char       typeBag;
TypHandle           hdNew;
TypHandle           * s,  * d,  * e;
typeBag = TYPE(hdBag);
oldSize = SIZE(hdBag);
#if defined(SPEC_CPU2000_LP64) || defined(SPEC_CPU2000_P64)
if ( ((newSize + 7) & ~7) == ((oldSize + 7) & ~7) ) {
#else
if ( ((newSize + 3) & ~3) == ((oldSize + 3) & ~3) ) {
#endif
#ifdef  STAT
GasmanStatASize[typeBag] += newSize - oldSize;
#endif
hdBag->size = newSize;
}
else if ( newSize < oldSize ) {
s = PTR(hdBag) + NrHandles(typeBag,oldSize);
e = PTR(hdBag) + (newSize + SIZE_HD-1)/SIZE_HD;
d = PTR(hdBag) + NrHandles(typeBag,newSize);
if ( d < s )
while ( d < e )  *d++ = *s++;
#if defined(SPEC_CPU2000_LP64) || defined(SPEC_CPU2000_P64)
*e = (TypHandle)(((oldSize+7)&~7) - ((newSize+7)&~7) - SIZE_HD + 2);
#else
*e = (TypHandle)(((oldSize+3)&~3) - ((newSize+3)&~3) - SIZE_HD + 2);
#endif
hdBag->size = newSize;
#ifdef  STAT
GasmanStatASize[typeBag] += newSize - oldSize;
#endif
}
else {
IsResizeCall = 1;
hdNew = NewBag( typeBag, newSize );
IsResizeCall = 0;
s = PTR(hdBag);
e = PTR(hdBag) + NrHandles(typeBag,oldSize);
d = PTR(hdNew);
while ( s < e )  *d++ = *s++;
s = e;
e = PTR(hdBag) + (oldSize + SIZE_HD-1)/SIZE_HD;
d = PTR(hdNew) + NrHandles(typeBag,newSize);
while ( s < e )  *d++ = *s++;
#if defined(SPEC_CPU2000_LP64) || defined(SPEC_CPU2000_P64)
PTR(hdBag)[-1] = (TypHandle)(((SIZE(hdBag) + 7) & ~7) + 2);
#else
PTR(hdBag)[-1] = (TypHandle)(((SIZE(hdBag) + 3) & ~3) + 2);
#endif
hdBag->ptr  = hdNew->ptr;
hdBag->size = hdNew->size;
PTR(hdBag)[-1] = hdBag;
#ifdef  STAT
GasmanStatAlive[typeBag]--;
GasmanStatASize[typeBag] -= oldSize;
GasmanStatTotal[typeBag]--;
#endif
}
}
void            InitGasman ()
{
if ( SyMemory < 32 * 1024 )  SyMemory = 32 * 1024;
SyMemory = (SyMemory + 1023) & ~1023;
HdFree = (TypHandle)SyGetmem( SyMemory );
if ( HdFree == (TypHandle)-1 ) {
SyFputs("Gasman: can not get memory for the initial workspace.\n",3);
SyExit( 1 );
}
HdFree->type = T_FREEBAG;
HdFree->size = (3 * SyMemory / 4 - SIZE_HD) & ~(SIZE_HD-1);
HdFree->ptr  = (TypHandle*)((char*)HdFree + (SyMemory - HdFree->size));
PTR(HdFree)[-1] = HdFree;
for ( FreeHandle = HdFree+1;
FreeHandle+2 < (TypHandle)(PTR(HdFree)-1);
FreeHandle++ ) {
FreeHandle->ptr = (TypHandle*)(FreeHandle+1);
FreeHandle->type = T_ILLEGAL;
++NrFreeHandles;
}
FreeHandle = HdFree + 1;
HdNewHandles = FreeHandle;
FreeHandle = (TypHandle)PTR(FreeHandle);
HdNewHandles->type = T_LIST;
HdNewHandles->size = 4096 * SIZE_HD;
HdNewHandles->ptr  = HdFree->ptr;
PTR(HdNewHandles)[-1] = HdNewHandles;
HdFree->size -= 4096 * SIZE_HD + SIZE_HD;
HdFree->ptr  += (4096 * SIZE_HD + SIZE_HD) / SIZE_HD;
PTR(HdFree)[-1] = HdFree;
FirstBag = PTR(HdNewHandles);
HdResize = FreeHandle;
FreeHandle = (TypHandle)PTR(FreeHandle);
IsResizeCall = 0;
}
/* 当前文件是D:\Read\idents.c*/


void            PushFunction ( hdFun )
TypHandle           hdFun;
{
PTR(HdStack)[++TopStack] = hdFun;
}
void            PopFunction ()
{
PTR(HdStack)[TopStack--] = 0;
}
unsigned long   IsUndefinedGlobal;
TypHandle       FindIdent ( name )
char                name [];
{
TypHandle           hd,  hdIdenttab,  hd2;
char                * p;
unsigned long       i,  k,  nrEntries;
IsUndefinedGlobal = 0;
for ( i = TopStack; i > 0; --i ) {
hd = PTR(HdStack)[i];
nrEntries = (SIZE(hd) - 2*sizeof(short)) / SIZE_HD - 1;
for ( k = 1; k < nrEntries; ++k ) {
if ( ! SyStrcmp( name, (char*)(PTR(PTR(hd)[k])+1) ) )
return PTR(hd)[k];
}
}
for ( k = 0, p = name; *p != '\0'; ++p )  k = 65599 * k + *p;
k = k % (SIZE(HdIdenttab) / SIZE_HD);
while ( PTR(HdIdenttab)[k] != 0
&& SyStrcmp( (char*)(PTR(PTR(HdIdenttab)[k])+1), name ) ) {
k = (k + 1) % (SIZE(HdIdenttab) / SIZE_HD);
}
if ( PTR(HdIdenttab)[k] != 0 ) {
if ( PTR( PTR(HdIdenttab)[k] )[0] == 0 && TopStack != 0 )
IsUndefinedGlobal = 1;
return PTR(HdIdenttab)[k];
}
if ( TopStack != 0 )
IsUndefinedGlobal = 1;
hd = NewBag( T_VAR, SIZE_HD+SyStrlen(name)+1 );
SyStrncat( (char*)(PTR(hd)+1), name, SyStrlen(name)  );
PTR(HdIdenttab)[k] = hd;
++NrIdenttab;
if ( 3 * NrIdenttab / 2 < SIZE(HdIdenttab) / SIZE_HD )
return hd;
hdIdenttab = NewBag( T_LIST, SIZE(HdIdenttab) );
for ( i = 0; i < SIZE(hdIdenttab) / SIZE_HD; ++i ) {
PTR(hdIdenttab)[i] = PTR(HdIdenttab)[i];
PTR(HdIdenttab)[i] = 0;
}
Resize( HdIdenttab, 2 * SIZE(HdIdenttab) + SIZE_HD );
for ( i = 0; i < SIZE(hdIdenttab) / SIZE_HD; ++i ) {
hd2 = PTR(hdIdenttab)[i];
if ( hd2 == 0 )  continue;
for ( k = 0, p = (char*)(PTR(hd2)+1); *p != '\0'; ++p )
k = 65599 * k + *p;
k = k % (SIZE(HdIdenttab) / SIZE_HD);
while ( PTR(HdIdenttab)[k] != 0 )
k = (k + 1) % (SIZE(HdIdenttab) / SIZE_HD);
PTR(HdIdenttab)[k] = hd2;
}
return hd;
}
TypHandle       HdRectab;
unsigned long   NrRectab;
TypHandle       FindRecname ( name )
char                name [];
{
TypHandle           hd,  hdRectab,  hd2;
char                * p;
unsigned long       i,  k;
for ( k = 0, p = name; *p != '\0'; ++p )  k = 65599 * k + *p;
k = k % (SIZE(HdRectab) / SIZE_HD);
while ( PTR(HdRectab)[k] != 0
&& SyStrcmp( (char*)(PTR(PTR(HdRectab)[k])), name ) ) {
k = (k + 1) % (SIZE(HdRectab) / SIZE_HD);
}
if ( PTR(HdRectab)[k] != 0 ) {
return PTR(HdRectab)[k];
}
hd = NewBag( T_RECNAM, (unsigned long)(SyStrlen(name)+1) );
SyStrncat( (char*)PTR(hd), name, SyStrlen(name) );
PTR(HdRectab)[k] = hd;
++NrRectab;
if ( 3 * NrRectab / 2 < SIZE(HdRectab) / SIZE_HD )
return hd;
hdRectab = NewBag( T_LIST, SIZE(HdRectab) );
for ( i = 0; i < SIZE(hdRectab) / SIZE_HD; ++i ) {
PTR(hdRectab)[i] = PTR(HdRectab)[i];
PTR(HdRectab)[i] = 0;
}
Resize( HdRectab, 2 * SIZE(HdRectab) + SIZE_HD );
for ( i = 0; i < SIZE(hdRectab) / SIZE_HD; ++i ) {
hd2 = PTR(hdRectab)[i];
if ( hd2 == 0 )  continue;
for ( k = 0, p = (char*)PTR(hd2); *p != '\0'; ++p )
k = 65599 * k + *p;
k = k % (SIZE(HdRectab) / SIZE_HD);
while ( PTR(HdRectab)[k] != 0 )
k = (k + 1) % (SIZE(HdRectab) / SIZE_HD);
PTR(HdRectab)[k] = hd2;
}
return hd;
}
unsigned long   iscomplete ( name, len, rn )
char                * name;
unsigned long       len;
unsigned long       rn;
{
char                * curr;
unsigned long       i, k;
TypHandle           hdTab;
if ( ! rn )  hdTab = HdIdenttab;
else         hdTab = HdRectab;
for ( i = 0; i < SIZE(hdTab)/SIZE_HD; i++ ) {
if ( PTR(hdTab)[i] == 0 )  continue;
if ( ! rn )  curr = (char*)(PTR(PTR(hdTab)[i])+1);
else         curr = (char*)(PTR(PTR(hdTab)[i]));
for ( k = 0; name[k] != 0 && curr[k] == name[k]; k++ ) ;
if ( k == len && curr[k] == '\0' )  return 1;
}
return 0;
}
unsigned long   completion ( name, len, rn )
char                * name;
unsigned long       len;
unsigned long       rn;
{
char                * curr,  * next;
unsigned long       i, k;
TypHandle           hdTab;
if ( ! rn )  hdTab = HdIdenttab;
else         hdTab = HdRectab;
next = 0;
for ( i = 0; i < SIZE(hdTab)/SIZE_HD; i++ ) {
if ( PTR(hdTab)[i] == 0 )  continue;
if ( ! rn )  curr = (char*)(PTR(PTR(hdTab)[i])+1);
else         curr = (char*)(PTR(PTR(hdTab)[i]));
for ( k = 0; name[k] != 0 && curr[k] == name[k]; k++ ) ;
if ( k < len || curr[k] <= name[k] )  continue;
if ( next != 0 ) {
for ( k = 0; curr[k] != '\0' && curr[k] == next[k]; k++ ) ;
if ( k < len || next[k] < curr[k] )  continue;
}
next = curr;
}
if ( next != 0 ) {
for ( k = 0; next[k] != '\0'; k++ )
name[k] = next[k];
name[k] = '\0';
}
return next != 0;
}
void            InitIdents ()
{
HdIdenttab = NewBag( T_LIST,  997 * SIZE_HD );
HdRectab   = NewBag( T_LIST,  997 * SIZE_HD );
HdStack    = NewBag( T_LIST, 1024 * SIZE_HD );
}
/* 当前文件是D:\Read\integer.c*/

#ifndef SPEC_INT32_T
#define	SPEC_INT32_T	int
#endif
TypHandle       EvInt ( hdInt )
TypHandle           hdInt;
{
return hdInt;
}
TypHandle       SumInt ( hdL, hdR )
TypHandle           hdL, hdR;
{
register SPEC_INT32_T  i;
register SPEC_INT32_T  k;
register SPEC_INT32_T  c;
register TypDigit   * l;
register TypDigit   * r;
register TypDigit   * s;
register unsigned SPEC_INT32_T * l2;
register unsigned SPEC_INT32_T * s2;
register TypHandle  hdS;
if ( (long)hdL & (long)hdR & T_INT ) {
i = (SPEC_INT32_T)hdL + (SPEC_INT32_T)hdR - 1;
if ( ((i << 1) >> 1) == i )
return (TypHandle)i;
i = HD_TO_INT(hdL) + HD_TO_INT(hdR);
if ( 0 < i ) {
hdS = NewBag( T_INTPOS, 4*sizeof(TypDigit) );
((TypDigit*)PTR(hdS))[0] = i;
((TypDigit*)PTR(hdS))[1] = i >> 16;
}
else {
hdS = NewBag( T_INTNEG, 4*sizeof(TypDigit) );
((TypDigit*)PTR(hdS))[0] = (-i);
((TypDigit*)PTR(hdS))[1] = (-i) >> 16;
}
}
else if ( (long)hdL & T_INT || (long)hdR & T_INT ) {
if ( (long)hdL & T_INT ) {
hdS = hdL;  hdL = hdR;  hdR = hdS;
}
if ( (TYPE(hdL) == T_INTNEG && 0 <= HD_TO_INT(hdR))
|| (TYPE(hdL) == T_INTPOS && HD_TO_INT(hdR) < 0) ) {
if ( TYPE(hdL) == T_INTPOS ) { Retype( hdL, T_INTNEG ); }
else                         { Retype( hdL, T_INTPOS ); }
hdS = DiffInt( hdR, hdL );
if ( TYPE(hdL) == T_INTPOS ) { Retype( hdL, T_INTNEG ); }
else                         { Retype( hdL, T_INTPOS ); }
return hdS;
}
if ( TYPE(hdL) == T_INTPOS ) {
i   = HD_TO_INT(hdR);
hdS = NewBag( T_INTPOS, SIZE(hdL) );
}
else {
i   = -HD_TO_INT(hdR);
hdS = NewBag( T_INTNEG, SIZE(hdL) );
}
l = (TypDigit*)PTR(hdL);
s = (TypDigit*)PTR(hdS);
c = *l++ + (TypDigit)i;                  *s++ = c;
c = *l++ + (TypDigit)(i>>16) + (c>>16);  *s++ = c;
c = *l++                     + (c>>16);  *s++ = c;
c = *l++                     + (c>>16);  *s++ = c;
for ( k=SIZE(hdL)/(4*sizeof(TypDigit))-1; k!=0 && (c>>16)!=0; --k ) {
c = *l++ + (c>>16);  *s++ = c;
c = *l++ + (c>>16);  *s++ = c;
c = *l++ + (c>>16);  *s++ = c;
c = *l++ + (c>>16);  *s++ = c;
}
for ( l2 = (unsigned SPEC_INT32_T*)l, s2 = (unsigned SPEC_INT32_T*)s; k != 0; --k ) {
*s2++ = *l2++;
*s2++ = *l2++;
}
if ( (c>>16) != 0 ) {
Resize( hdS, SIZE(hdS) + 4*sizeof(TypDigit) );
((TypDigit*)PTR(hdS))[SIZE(hdS)/sizeof(TypDigit)-4] = (c>>16);
}
}
else {
if ( (TYPE(hdL) == T_INTPOS && TYPE(hdR) == T_INTNEG)
|| (TYPE(hdL) == T_INTNEG && TYPE(hdR) == T_INTPOS) ) {
if ( TYPE(hdL) == T_INTPOS )  { Retype( hdL, T_INTNEG ); }
else                          { Retype( hdL, T_INTPOS ); }
hdS = DiffInt( hdR, hdL );
if ( TYPE(hdL) == T_INTPOS )  { Retype( hdL, T_INTNEG ); }
else                          { Retype( hdL, T_INTPOS ); }
return hdS;
}
if ( SIZE(hdL) < SIZE(hdR) ) {
hdS = hdL;  hdL = hdR;  hdR = hdS;
}
if ( TYPE(hdL) == T_INTPOS ) {
hdS = NewBag( T_INTPOS, SIZE(hdL) );
}
else {
hdS = NewBag( T_INTNEG, SIZE(hdL) );
}
l = (TypDigit*)PTR(hdL);
r = (TypDigit*)PTR(hdR);
s = (TypDigit*)PTR(hdS);
c = 0;
for ( k = SIZE(hdR)/(4*sizeof(TypDigit)); k != 0; --k ) {
c = *l++ + *r++ + (c>>16);  *s++ = c;
c = *l++ + *r++ + (c>>16);  *s++ = c;
c = *l++ + *r++ + (c>>16);  *s++ = c;
c = *l++ + *r++ + (c>>16);  *s++ = c;
}
for ( k = (SIZE(hdL)-SIZE(hdR))/(4*sizeof(TypDigit));
k != 0 && (c>>16) != 0; --k ) {
c = *l++ + (c>>16);  *s++ = c;
c = *l++ + (c>>16);  *s++ = c;
c = *l++ + (c>>16);  *s++ = c;
c = *l++ + (c>>16);  *s++ = c;
}
for ( l2 = (unsigned SPEC_INT32_T*)l, s2 = (unsigned SPEC_INT32_T*)s; k != 0; --k ) {
*s2++ = *l2++;
*s2++ = *l2++;
}
if ( (c>>16) != 0 ) {
Resize( hdS, SIZE(hdS) + 4*sizeof(TypDigit) );
((TypDigit*)PTR(hdS))[SIZE(hdS)/sizeof(TypDigit)-4] = (c>>16);
}
}
return hdS;
}
TypHandle       DiffInt ( hdL, hdR )
TypHandle           hdL, hdR;
{
register SPEC_INT32_T  i;
register SPEC_INT32_T  k;
register SPEC_INT32_T  c;
register TypDigit   * l;
register TypDigit   * r;
register TypDigit   * d;
register unsigned SPEC_INT32_T * l2;
register unsigned SPEC_INT32_T * d2;
register TypHandle  hdD;
if ( (SPEC_INT32_T)hdL & (SPEC_INT32_T)hdR & T_INT ) {
i = (SPEC_INT32_T)hdL - (SPEC_INT32_T)hdR + 1;
if ( ((i << 1) >> 1) == i )
return (TypHandle)i;
i = HD_TO_INT(hdL) - HD_TO_INT(hdR);
if ( 0 < i ) {
hdD = NewBag( T_INTPOS, 4*sizeof(TypDigit) );
((TypDigit*)PTR(hdD))[0] = i;
((TypDigit*)PTR(hdD))[1] = i >> 16;
}
else {
hdD = NewBag( T_INTNEG, 4*sizeof(TypDigit) );
((TypDigit*)PTR(hdD))[0] = (-i);
((TypDigit*)PTR(hdD))[1] = (-i) >> 16;
}
}
else if ( (long)hdL & T_INT || (long)hdR & T_INT ) {
if ( (long)hdL & T_INT ) {
hdD = hdL;  hdL = hdR;  hdR = hdD;
c = -1;
}
else {
c =  1;
}
if ( (TYPE(hdL) == T_INTNEG && 0 <= HD_TO_INT(hdR))
|| (TYPE(hdL) == T_INTPOS && HD_TO_INT(hdR) < 0)  ) {
if ( TYPE(hdL) == T_INTPOS )  Retype( hdL, T_INTNEG );
else                          Retype( hdL, T_INTPOS );
hdD = SumInt( hdL, hdR );
if ( TYPE(hdL) == T_INTPOS )  Retype( hdL, T_INTNEG );
else                          Retype( hdL, T_INTPOS );
if ( c == 1 ) {
if ( TYPE(hdD) == T_INTPOS )  Retype( hdD, T_INTNEG );
else                          Retype( hdD, T_INTPOS );
}
return hdD;
}
if ( TYPE(hdL) == T_INTPOS ) {
i   = HD_TO_INT(hdR);
if ( c == 1 )  hdD = NewBag( T_INTPOS, SIZE(hdL) );
else           hdD = NewBag( T_INTNEG, SIZE(hdL) );
}
else {
i   = - HD_TO_INT(hdR);
if ( c == 1 )  hdD = NewBag( T_INTNEG, SIZE(hdL) );
else           hdD = NewBag( T_INTPOS, SIZE(hdL) );
}
l = (TypDigit*)PTR(hdL);
d = (TypDigit*)PTR(hdD);
c = *l++ - (TypDigit)i;                  *d++ = c;
c = *l++ - (TypDigit)(i>>16) + (c>>16);  *d++ = c;
c = *l++                     + (c>>16);  *d++ = c;
c = *l++                     + (c>>16);  *d++ = c;
for ( k=SIZE(hdL)/(4*sizeof(TypDigit))-1; k!=0 && (c>>16)!=0; --k ) {
c = *l++ + (c>>16);  *d++ = c;
c = *l++ + (c>>16);  *d++ = c;
c = *l++ + (c>>16);  *d++ = c;
c = *l++ + (c>>16);  *d++ = c;
}
for ( l2 = (unsigned SPEC_INT32_T*)l, d2 = (unsigned SPEC_INT32_T*)d; k != 0; --k ) {
*d2++ = *l2++;
*d2++ = *l2++;
}
if ( ((unsigned SPEC_INT32_T*)d==d2
&& d[-4]==0 && d[-3]==0 && d[-2]==0 && d[-1]==0)
|| (SIZE(hdD)==4*sizeof(TypDigit) && d[-2]==0 && d[-1]==0) ) {
d = (TypDigit*)PTR(hdD);
for ( k=SIZE(hdD)/sizeof(TypDigit); k != 0; --k ) {
if ( d[k-1] != 0 )
break;
}
if ( k<=2 && TYPE(hdD) == T_INTPOS
&& (unsigned long)(65536*d[1]+d[0]) < (1<<28) )
hdD = INT_TO_HD( 65536*d[1]+d[0] );
else if ( k<=2 && TYPE(hdD) == T_INTNEG
&& (unsigned long)(65536*d[1]+d[0]) <= (1<<28) )
hdD = INT_TO_HD( -(65536*d[1]+d[0]) );
else
Resize( hdD, (((k + 3) / 4) * 4) * sizeof(TypDigit) );
}
}
else {
if ( (TYPE(hdL) == T_INTPOS && TYPE(hdR) == T_INTNEG)
|| (TYPE(hdL) == T_INTNEG && TYPE(hdR) == T_INTPOS) ) {
if ( TYPE(hdR) == T_INTPOS )  Retype( hdR, T_INTNEG );
else                          Retype( hdR, T_INTPOS );
hdD = SumInt( hdL, hdR );
if ( TYPE(hdR) == T_INTPOS )  Retype( hdR, T_INTNEG );
else                          Retype( hdR, T_INTPOS );
return hdD;
}
if ( SIZE(hdL) <  SIZE(hdR)
|| (TYPE(hdL) == T_INTPOS && LtInt(hdL,hdR) == HdTrue)
|| (TYPE(hdL) == T_INTNEG && LtInt(hdR,hdL) == HdTrue) ) {
hdD = hdL;  hdL = hdR;  hdR = hdD;  c = -1;
}
else {
c = 1;
}
if ( (TYPE(hdL) == T_INTPOS && c ==  1)
|| (TYPE(hdL) == T_INTNEG && c == -1) )
hdD = NewBag( T_INTPOS, SIZE(hdL) );
else
hdD = NewBag( T_INTNEG, SIZE(hdL) );
l = (TypDigit*)PTR(hdL);
r = (TypDigit*)PTR(hdR);
d = (TypDigit*)PTR(hdD);
c = 0;
for ( k = SIZE(hdR)/(4*sizeof(TypDigit)); k != 0; --k ) {
c = *l++ - *r++ + (c>>16);  *d++ = c;
c = *l++ - *r++ + (c>>16);  *d++ = c;
c = *l++ - *r++ + (c>>16);  *d++ = c;
c = *l++ - *r++ + (c>>16);  *d++ = c;
}
for ( k = (SIZE(hdL)-SIZE(hdR))/(4*sizeof(TypDigit));
k != 0 && (c>>16) != 0; --k ) {
c = *l++ + (c>>16);  *d++ = c;
c = *l++ + (c>>16);  *d++ = c;
c = *l++ + (c>>16);  *d++ = c;
c = *l++ + (c>>16);  *d++ = c;
}
for ( d2 = (unsigned SPEC_INT32_T*)d, l2 = (unsigned SPEC_INT32_T*)l; k != 0; --k ) {
*d2++ = *l2++;
*d2++ = *l2++;
}
if ( ((unsigned SPEC_INT32_T*)d==d2
&& d[-4]==0 && d[-3]==0 && d[-2]==0 && d[-1]==0)
|| (SIZE(hdD)==4*sizeof(TypDigit) && d[-2]==0 && d[-1]==0) ) {
d = (TypDigit*)PTR(hdD);
for ( k=SIZE(hdD)/sizeof(TypDigit); k != 0; --k ) {
if ( d[k-1] != 0 )
break;
}
if ( k<=2 && TYPE(hdD) == T_INTPOS
&& (unsigned long)(65536*d[1]+d[0]) < (1<<28) )
hdD = INT_TO_HD( 65536*d[1]+d[0] );
else if ( k<=2 && TYPE(hdD) == T_INTNEG
&& (unsigned long)(65536*d[1]+d[0]) <= (1<<28) )
hdD = INT_TO_HD( -(65536*d[1]+d[0]) );
else
Resize( hdD, (((k + 3) / 4) * 4) * sizeof(TypDigit) );
}
}
return hdD;
}
TypHandle       ProdInt ( hdL, hdR )
TypHandle           hdL, hdR;
{
register SPEC_INT32_T  i;
register SPEC_INT32_T  k;
register unsigned SPEC_INT32_T c;
register TypDigit   l;
register TypDigit   * r;
register TypDigit   * p;
register TypHandle  hdP;
if ( (SPEC_INT32_T)hdL & (SPEC_INT32_T)hdR & T_INT ) {
i = ((SPEC_INT32_T)hdL - 1) * ((SPEC_INT32_T)hdR >> 1);
if ( ((SPEC_INT32_T)hdR >> 1) == 0 || i / ((SPEC_INT32_T)hdR >> 1) == ((SPEC_INT32_T)hdL-1) ) {
return (TypHandle)((i >> 1) + T_INT);
}
i = HD_TO_INT(hdL);
k = HD_TO_INT(hdR);
if ( (0 < i && 0 < k) || (i < 0 && k < 0) )
hdP = NewBag( T_INTPOS, 4*sizeof(TypDigit) );
else
hdP = NewBag( T_INTNEG, 4*sizeof(TypDigit) );
p = (TypDigit*)PTR(hdP);
if ( i < 0 )  i = -i;
if ( k < 0 )  k = -k;
c = (TypDigit)i       * (TypDigit)k;                        p[0] = c;
c = (TypDigit)i       * (TypDigit)(k>>16)        + (c>>16); p[1] = c;
p[2] = c>>16;
c = (TypDigit)(i>>16) * (TypDigit)k       + p[1];           p[1] = c;
c = (TypDigit)(i>>16) * (TypDigit)(k>>16) + p[2] + (c>>16); p[2] = c;
p[3] = c>>16;
}
else if ( (SPEC_INT32_T)hdL & T_INT || (SPEC_INT32_T)hdR & T_INT ) {
if ( (SPEC_INT32_T)hdR & T_INT ) {
i = HD_TO_INT(hdR);  hdR = hdL;
}
else {
i = HD_TO_INT(hdL);
}
if ( i == 0 )
return INT_TO_HD(0);
if ( i == 1 ) {
return hdR;
}
if ( i == -1
&& TYPE(hdR) == T_INTPOS && SIZE(hdR) == 4*sizeof(TypDigit)
&& ((TypDigit*)PTR(hdR))[3]==0     && ((TypDigit*)PTR(hdR))[2]==0
&&65536*((TypDigit*)PTR(hdR))[1]+((TypDigit*)PTR(hdR))[0]==(1<<28)) {
return INT_TO_HD( -(1<<28) );
}
if ( i == -1 ) {
if ( TYPE(hdR) == T_INTPOS ) hdP = NewBag( T_INTNEG, SIZE(hdR) );
else                         hdP = NewBag( T_INTPOS, SIZE(hdR) );
r = (TypDigit*)PTR(hdR);
p = (TypDigit*)PTR(hdP);
for ( k = SIZE(hdR)/(4*sizeof(TypDigit)); k != 0; --k ) {
*p++ = *r++;  *p++ = *r++;  *p++ = *r++;  *p++ = *r++;
}
return hdP;
}
if ( (0<i && TYPE(hdR)==T_INTPOS) || (i<0 && TYPE(hdR)==T_INTNEG) )
hdP = NewBag( T_INTPOS, 4*sizeof(TypDigit)+SIZE(hdR) );
else
hdP = NewBag( T_INTNEG, 4*sizeof(TypDigit)+SIZE(hdR) );
if ( i < 0 )  i = -i;
l = (TypDigit)i;
if ( l != 0 ) {
r = (TypDigit*)PTR(hdR);
p = (TypDigit*)PTR(hdP);
c = 0;
for ( k = SIZE(hdR)/(4*sizeof(TypDigit)); k != 0; --k ) {
c = l * *r++ + (c>>16);  *p++ = c;
c = l * *r++ + (c>>16);  *p++ = c;
c = l * *r++ + (c>>16);  *p++ = c;
c = l * *r++ + (c>>16);  *p++ = c;
}
*p = (c>>16);
}
l = i >> 16;
if ( l != 0 ) {
r = (TypDigit*)PTR(hdR);
p = (TypDigit*)PTR(hdP) + 1;
c = 0;
for ( k = SIZE(hdR)/(4*sizeof(TypDigit)); k != 0; --k ) {
c = l * *r++ + *p + (c>>16);  *p++ = c;
c = l * *r++ + *p + (c>>16);  *p++ = c;
c = l * *r++ + *p + (c>>16);  *p++ = c;
c = l * *r++ + *p + (c>>16);  *p++ = c;
}
*p = (c>>16);
}
p = (TypDigit*)PTR(hdP) + SIZE(hdP)/sizeof(TypDigit);
if ( p[-4]==0 && p[-3]==0 && p[-2]==0 && p[-1]==0 ) {
Resize( hdP, SIZE(hdP) - 4*sizeof(TypDigit) );
}
}
else {
if ( SIZE(hdL) > SIZE(hdR) ) {
hdP = hdR;  hdR = hdL;  hdL = hdP;
}
if ( TYPE(hdL) == TYPE(hdR) )
hdP = NewBag( T_INTPOS, SIZE(hdL)+SIZE(hdR) );
else
hdP = NewBag( T_INTNEG, SIZE(hdL)+SIZE(hdR) );
for ( i = 0; i < SIZE(hdL)/sizeof(TypDigit); ++i ) {
l = ((TypDigit*)PTR(hdL))[i];
if ( l == 0 )  continue;
r = (TypDigit*)PTR(hdR);
p = (TypDigit*)PTR(hdP) + i;
c = 0;
for ( k = SIZE(hdR)/(4*sizeof(TypDigit)); k != 0; --k ) {
c = l * *r++ + *p + (c>>16);  *p++ = c;
c = l * *r++ + *p + (c>>16);  *p++ = c;
c = l * *r++ + *p + (c>>16);  *p++ = c;
c = l * *r++ + *p + (c>>16);  *p++ = c;
}
*p = (c>>16);
}
p = (TypDigit*)PTR(hdP) + SIZE(hdP)/sizeof(TypDigit);
if ( p[-4]==0 && p[-3]==0 && p[-2]==0 && p[-1]==0 ) {
Resize( hdP, SIZE(hdP) - 4*sizeof(TypDigit) );
}
}
return hdP;
}
TypHandle       ModInt ( hdL, hdR )
TypHandle           hdL, hdR;
{
register SPEC_INT32_T  i;
register SPEC_INT32_T  k;
register unsigned SPEC_INT32_T c;
register TypDigit   d;
register TypDigit   * l;
register TypDigit   * r;
register TypDigit   r1;
register TypDigit   r2;
register unsigned SPEC_INT32_T rs;
register unsigned SPEC_INT32_T e;
register TypHandle  hdM;
register TypDigit   * m;
register unsigned SPEC_INT32_T m01;
register TypDigit   m2;
register TypDigit   qi;
if ( (SPEC_INT32_T)hdL & (SPEC_INT32_T)hdR & T_INT ) {
if ( hdR == INT_TO_HD(0) ) {
return Error("Integer operations: <divisor> must be nonzero",
0L,0L);
}
i = HD_TO_INT(hdL);
k = HD_TO_INT(hdR);
if (      0 <= i && 0 <= k )  i =       (  i %  k );
else if ( 0 <= i && k <  0 )  i =       (  i % -k );
else if ( i < 0  && 0 <= k )  i = ( k - ( -i %  k )) % k;
else if ( i < 0  && k <  0 )  i = (-k - ( -i % -k )) % k;
hdM = INT_TO_HD( i );
}
else if ( (SPEC_INT32_T)hdL & T_INT ) {
if ( hdL == INT_TO_HD(-(1<<28))
&& TYPE(hdR) == T_INTPOS && SIZE(hdR) == 4*sizeof(TypDigit)
&& ((TypDigit*)PTR(hdR))[3] == 0 && ((TypDigit*)PTR(hdR))[2] == 0
&& 65536*((TypDigit*)PTR(hdR))[1]+((TypDigit*)PTR(hdR))[0]==1<<28 )
hdM = INT_TO_HD(0);
else if ( 0 <= HD_TO_INT(hdL) )
hdM = hdL;
else if ( TYPE(hdR) == T_INTPOS )
hdM = SumInt( hdL, hdR );
else
hdM = DiffInt( hdL, hdR );
}
else if ( (SPEC_INT32_T)hdR & T_INT
&& HD_TO_INT(hdR) < 65536 && -65536 <= HD_TO_INT(hdR) ) {
if ( hdR == INT_TO_HD(0) ) {
return Error("Integer operations: <divisor> must be nonzero",
0L,0L);
}
i = HD_TO_INT(hdR);  if ( i < 0 )  i = -i;
if ( 65536 % i == 0 ) {
c = ((TypDigit*)PTR(hdL))[0] % i;
}
else {
l = (TypDigit*)PTR(hdL) + SIZE(hdL)/sizeof(TypDigit) - 1;
c = 0;
for ( ; l >= (TypDigit*)PTR(hdL); --l ) {
c  = (c<<16) + *l;
c  = c % i;
}
}
if ( TYPE(hdL) == T_INTPOS )
hdM = INT_TO_HD( c );
else if ( c == 0 )
hdM = INT_TO_HD( c );
else if ( 0 <= HD_TO_INT(hdR) )
hdM = SumInt( INT_TO_HD( -c ), hdR );
else
hdM = DiffInt( INT_TO_HD( -c ), hdR );
}
else {
if ( (SPEC_INT32_T)hdR & T_INT ) {
if ( 0 < HD_TO_INT(hdR) ) {
hdM = NewBag( T_INTPOS, 4*sizeof(TypDigit) );
((TypDigit*)PTR(hdM))[0] = (TypDigit)(HD_TO_INT(hdR));
((TypDigit*)PTR(hdM))[1] = (HD_TO_INT(hdR)>>16);
hdR = hdM;
}
else {
hdM = NewBag( T_INTNEG, 4*sizeof(TypDigit) );
((TypDigit*)PTR(hdM))[0] = (TypDigit)(-HD_TO_INT(hdR));
((TypDigit*)PTR(hdM))[1] = (-HD_TO_INT(hdR))>>16;
hdR = hdM;
}
}
if ( SIZE(hdL) < SIZE(hdR) ) {
if ( TYPE(hdL) == T_INTPOS )
return hdL;
else if ( TYPE(hdR) == T_INTPOS )
return SumInt( hdL, hdR );
else
return DiffInt( hdL, hdR );
}
hdM = NewBag( TYPE(hdL), SIZE(hdL) + 4*sizeof(TypDigit) );
l = (TypDigit*)PTR(hdL);
m = (TypDigit*)PTR(hdM);
for ( k = SIZE(hdL)/sizeof(TypDigit)-1; k >= 0; --k )
*m++ = *l++;
rs = SIZE(hdR)/sizeof(TypDigit);
r  = (TypDigit*)PTR(hdR);
while ( r[rs-1] == 0 )  --rs;
for ( e = 0; (r[rs-1]<<e) + (r[rs-2]>>(16-e)) < 65536/2; ++e ) ;
r1 = (r[rs-1]<<e) + (r[rs-2]>>(16-e));
r2 = (r[rs-2]<<e) + (rs>=3 ? r[rs-3]>>(16-e) : 0);
for ( i = (SIZE(hdM)-SIZE(hdR))/sizeof(TypDigit)-1; i >= 0; --i ) {
m = ((TypDigit*)PTR(hdM)) + rs + i;
m01 = ((65536*m[0]+m[-1])<<e) + (m[-2]>>(16-e));
if ( m01 == 0 )  continue;
m2  = (m[-2]<<e) + (rs+i>=3 ? m[-3]>>(16-e) : 0);
if ( (m[0]<<e)+(m[-1]>>(16-e)) < r1 )  qi = m01 / r1;
else                                   qi = 65536 - 1;
while ( m01-qi*r1 < 65536 && 65536*(m01-qi*r1)+m2 < qi*r2 )
--qi;
d = 0;
m = ((TypDigit*)PTR(hdM)) + i;
r = ((TypDigit*)PTR(hdR));
for ( k = 0; k < rs; ++k, ++m, ++r ) {
c = *m - qi * *r - d;  *m = c;  d = -(c>>16);
}
c = *m - d;  *m = c;  d = -(c>>16);
if ( d != 0 ) {
d = 0;
m = ((TypDigit*)PTR(hdM)) + i;
r = ((TypDigit*)PTR(hdR));
for ( k = 0; k < rs; ++k, ++m, ++r ) {
c = *m + *r + d;  *m = c;  d = (c>>16);
}
c = *m + d;  *m = c;  d = (c>>16);
qi--;
}
}
m = ((TypDigit*)PTR(hdM))+ SIZE(hdM)/sizeof(TypDigit);
if ( (m[-4]==0 && m[-3]==0 && m[-2]==0 && m[-1]==0)
|| (SIZE(hdM)==4*sizeof(TypDigit) && m[-2]==0 && m[-1]==0) ) {
m = (TypDigit*)PTR(hdM);
for ( k=SIZE(hdM)/sizeof(TypDigit); k != 0; --k ) {
if ( m[k-1] != 0 )
break;
}
if ( k<=2 && TYPE(hdM) == T_INTPOS
&& (unsigned SPEC_INT32_T)(65536*m[1]+m[0]) < (1<<28) )
hdM = INT_TO_HD( 65536*m[1]+m[0] );
else if ( k<=2 && TYPE(hdM) == T_INTNEG
&& (unsigned SPEC_INT32_T)(65536*m[1]+m[0]) <= (1<<28) )
hdM = INT_TO_HD( -(65536*m[1]+m[0]) );
else
Resize( hdM, (((k + 3) / 4) * 4) * sizeof(TypDigit) );
}
if ( (TYPE(hdM) == T_INT && HD_TO_INT(hdM) < 0)
|| TYPE(hdM) == T_INTNEG ) {
if ( TYPE(hdR) == T_INTPOS )
hdM = SumInt( hdM, hdR );
else
hdM = DiffInt( hdM, hdR );
}
}
return hdM;
}
TypHandle       PowInt ( hdL, hdR )
TypHandle           hdL, hdR;
{
register SPEC_INT32_T  i;
register TypHandle  hdP;
if ( ! ((SPEC_INT32_T)hdR & T_INT) ) {
if ( hdL == INT_TO_HD(0) )
hdP = INT_TO_HD(0);
else if ( hdL == INT_TO_HD(1) )
hdP = INT_TO_HD(1);
else if ( hdL == INT_TO_HD(-1) && ((TypDigit*)PTR(hdR))[0] % 2 == 0 )
hdP = INT_TO_HD(1);
else if ( hdL == INT_TO_HD(-1) && ((TypDigit*)PTR(hdR))[0] % 2 != 0 )
hdP = INT_TO_HD(-1);
else
hdP = Error("Integer operations: <exponent> is to large",0L,0L);
}
else if ( HD_TO_INT(hdR) < 0 ) {
if ( hdL == INT_TO_HD(0) )
hdP = Error("IntOps: 0 ^ %d is not defined",HD_TO_INT(hdR),0L);
else if ( hdL == INT_TO_HD(1) )
hdP = INT_TO_HD(1);
else if ( hdL == INT_TO_HD(-1) && HD_TO_INT(hdR) % 2 == 0 )
hdP = INT_TO_HD(1);
else if ( hdL == INT_TO_HD(-1) && HD_TO_INT(hdR) % 2 != 0 )
hdP = INT_TO_HD(-1);
else
hdP = QUO( INT_TO_HD(1),
PowInt( hdL, INT_TO_HD( -HD_TO_INT(hdR)) ) );
}
else {
hdP = INT_TO_HD(1);
i = HD_TO_INT(hdR);
while ( i != 0 ) {
if ( i % 2 == 1 )  hdP = ProdInt( hdP, hdL );
if ( i     >  1 )  hdL = ProdInt( hdL, hdL );
i = i / 2;
}
}
return hdP;
}
TypHandle       EqInt ( hdL, hdR )
TypHandle           hdL, hdR;
{
register SPEC_INT32_T  k;
register TypDigit   * l;
register TypDigit   * r;
if ( (SPEC_INT32_T)hdL & (SPEC_INT32_T)hdR & T_INT ) {
if ( HD_TO_INT(hdL) == HD_TO_INT(hdR) )  return HdTrue;
else                                     return HdFalse;
}
else if ( (SPEC_INT32_T)hdL & T_INT ) {
return HdFalse;
}
else if ( (SPEC_INT32_T)hdR & T_INT ) {
return HdFalse;
}
else {
if ( TYPE(hdL) != TYPE(hdR) || SIZE(hdL) != SIZE(hdR) )
return HdFalse;
l = (TypDigit*)PTR(hdL);
r = (TypDigit*)PTR(hdR);
for ( k = SIZE(hdL)/(4*sizeof(TypDigit))-1; k >= 0; --k ) {
if ( *l++ != *r++ )  return HdFalse;
if ( *l++ != *r++ )  return HdFalse;
if ( *l++ != *r++ )  return HdFalse;
if ( *l++ != *r++ )  return HdFalse;
}
return HdTrue;
}
}
TypHandle       LtInt ( hdL, hdR )
TypHandle           hdL, hdR;
{
register SPEC_INT32_T  k;
register TypDigit   * l;
register TypDigit   * r;
if ( (SPEC_INT32_T)hdL & (SPEC_INT32_T)hdR & T_INT ) {
if ( HD_TO_INT(hdL) <  HD_TO_INT(hdR) )  return HdTrue;
else                                     return HdFalse;
}
else if ( (SPEC_INT32_T)hdL & T_INT ) {
if ( TYPE(hdR) == T_INTPOS )  return HdTrue;
else                          return HdFalse;
}
else if ( (SPEC_INT32_T)hdR & T_INT ) {
if ( TYPE(hdL) == T_INTPOS )  return HdFalse;
else                          return HdTrue;
}
else {
if (      TYPE(hdL) == T_INTNEG && TYPE(hdR) == T_INTPOS )
return HdTrue;
else if ( TYPE(hdL) == T_INTPOS && TYPE(hdR) == T_INTNEG )
return HdFalse;
else if ( (TYPE(hdL) == T_INTPOS && SIZE(hdL) < SIZE(hdR))
|| (TYPE(hdL) == T_INTNEG && SIZE(hdL) > SIZE(hdR)) )
return HdTrue;
else if ( (TYPE(hdL) == T_INTPOS && SIZE(hdL) > SIZE(hdR))
|| (TYPE(hdL) == T_INTNEG && SIZE(hdL) < SIZE(hdR)) )
return HdFalse;
l = (TypDigit*)PTR(hdL);
r = (TypDigit*)PTR(hdR);
for ( k = SIZE(hdL)/sizeof(TypDigit)-1; k >= 0; --k ) {
if ( l[k] != r[k] ) {
if ( (TYPE(hdL) == T_INTPOS && l[k] < r[k])
|| (TYPE(hdL) == T_INTNEG && l[k] > r[k]) )
return HdTrue;
else
return HdFalse;
}
}
return HdFalse;
}
}
TypDigit        PrIntC [1000];
TypDigit        PrIntD [1205];
void            PrInteger ( hdInt )
TypHandle           hdInt;
{
register long       i, k;
register TypDigit   * p;
register unsigned long      c;
if ( (long)hdInt & T_INT ) {
Pr( "%>%d%<", HD_TO_INT(hdInt), 0L );
}
else if ( SIZE(hdInt)/sizeof(TypDigit) < 1000 ) {
Pr("%>",0L,0L);
if ( TYPE(hdInt) == T_INTNEG )
Pr("-",0L,0L);
i = 0;
for ( k = 0; k < SIZE(hdInt)/sizeof(TypDigit); ++k )
PrIntC[k] = ((TypDigit*)PTR(hdInt))[k];
while ( k > 0 && PrIntC[k-1] == 0 )  --k;
while ( k > 0 ) {
for ( c = 0, p = PrIntC+k-1; p >= PrIntC; --p ) {
c  = (c<<16) + *p;
*p = c / 10000;
c  = c - 10000 * *p;
}
PrIntD[i++] = c;
while ( k > 0 && PrIntC[k-1] == 0 )  --k;
}
Pr( "%d", (long)PrIntD[--i], 0L );
while ( i > 0 )
Pr( "%04d", (long)PrIntD[--i], 0L );
Pr("%<",0L,0L);
}
else {
Pr("<<an integer too large to be printed>>",0L,0L);
}
}
TypHandle       FunIsInt ( hdCall )
TypHandle           hdCall;
{
TypHandle           hdObj;
if ( SIZE(hdCall) != 2 * SIZE_HD )
return Error("usage: IsInt( <obj> )",0L,0L);
hdObj = EVAL( PTR(hdCall)[1] );
if ( hdObj == HdVoid )
return Error("IsInt: function must return a value",0L,0L);
if ( TYPE(hdObj) == T_INT
|| TYPE(hdObj) == T_INTPOS || TYPE(hdObj) == T_INTNEG )
return HdTrue;
else
return HdFalse;
}
TypHandle       QuoInt ( hdL, hdR )
TypHandle           hdL, hdR;
{
register SPEC_INT32_T i;
register SPEC_INT32_T k;
register unsigned SPEC_INT32_T c;
register TypDigit   d;
register TypDigit   * l;
register unsigned SPEC_INT32_T l01;
register TypDigit   l2;
register TypDigit   * r;
register TypDigit   r1;
register TypDigit   r2;
register unsigned SPEC_INT32_T rs;
register unsigned SPEC_INT32_T  e;
register TypDigit   * q;
register TypHandle  hdQ;
register TypDigit   qi;
if ( (long)hdL & (long)hdR & T_INT ) {
if ( hdR == INT_TO_HD(0) ) {
return Error("Integer operations: <divisor> must be nonzero",
0L,0L);
}
if ( hdL == INT_TO_HD(-(1<<28)) && hdR == INT_TO_HD(-1) ) {
hdQ = NewBag( T_INTPOS, 4*sizeof(TypDigit) );
((TypDigit*)PTR(hdQ))[1] = 1<<12;
((TypDigit*)PTR(hdQ))[0] = 0;
return hdQ;
}
i = HD_TO_INT(hdL);
k = HD_TO_INT(hdR);
if (      0 <= i && 0 <= k )  i =    (  i /  k );
else if ( 0 <= i && k <  0 )  i =  - (  i / -k );
else if ( i < 0  && 0 <= k )  i =  - ( -i /  k );
else if ( i < 0  && k <  0 )  i =    ( -i / -k );
hdQ = INT_TO_HD( i );
}
else if ( (long)hdL & T_INT ) {
if ( hdL == INT_TO_HD(-(1<<28))
&& TYPE(hdR) == T_INTPOS && SIZE(hdR) == 4*sizeof(TypDigit)
&& ((TypDigit*)PTR(hdR))[3] == 0 && ((TypDigit*)PTR(hdR))[2] == 0
&& 65536*((TypDigit*)PTR(hdR))[1]+((TypDigit*)PTR(hdR))[0]==1<<28 )
hdQ = INT_TO_HD(-1);
else
hdQ = INT_TO_HD(0);
}
else if ( (long)hdR & T_INT
&& HD_TO_INT(hdR) < 65536 && -65536 <= HD_TO_INT(hdR) ) {
if ( hdR == INT_TO_HD(0) ) {
return Error("Integer operations: <divisor> must be nonzero",
0L,0L);
}
i = HD_TO_INT(hdR);  if ( i < 0 )  i = -i;
if ( (TYPE(hdL)==T_INTPOS && 0 < HD_TO_INT(hdR))
|| (TYPE(hdL)==T_INTNEG && HD_TO_INT(hdR) < 0) )
hdQ = NewBag( T_INTPOS, SIZE(hdL) );
else
hdQ = NewBag( T_INTNEG, SIZE(hdL) );
l = (TypDigit*)PTR(hdL) + SIZE(hdL)/sizeof(TypDigit) - 1;
q = (TypDigit*)PTR(hdQ) + SIZE(hdQ)/sizeof(TypDigit) - 1;
c = 0;
for ( ; l >= (TypDigit*)PTR(hdL); --l, --q ) {
c  = (c<<16) + *l;
*q = c / i;
c  = c - i * *q;
}
q = ((TypDigit*)PTR(hdQ)) + SIZE(hdQ)/sizeof(TypDigit);
if ( q[-4]==0 && q[-3]==0 && q[-2]==0 && q[-1]==0 ) {
Resize( hdQ, SIZE(hdQ)-4*sizeof(TypDigit) );
}
q = ((TypDigit*)PTR(hdQ)) + SIZE(hdQ)/sizeof(TypDigit);
if ( SIZE(hdQ)==4*sizeof(TypDigit) && q[-2]==0 && q[-1]==0 ) {
if ( TYPE(hdQ) == T_INTPOS
&& (unsigned long)(65536*q[-3]+q[-4]) < (1<<28) )
hdQ = INT_TO_HD( 65536*q[-3]+q[-4] );
else if ( TYPE(hdQ) == T_INTNEG
&& (unsigned long)(65536*q[-3]+q[-4]) <= (1<<28) )
hdQ = INT_TO_HD( -(65536*q[-3]+q[-4]) );
}
}
else {
if ( (long)hdR & T_INT ) {
if ( 0 < HD_TO_INT(hdR) ) {
hdQ = NewBag( T_INTPOS, 4*sizeof(TypDigit) );
((TypDigit*)PTR(hdQ))[0] = (TypDigit)(HD_TO_INT(hdR));
((TypDigit*)PTR(hdQ))[1] = (HD_TO_INT(hdR)>>16);
hdR = hdQ;
}
else {
hdQ = NewBag( T_INTNEG, 4*sizeof(TypDigit) );
((TypDigit*)PTR(hdQ))[0] = (TypDigit)(-HD_TO_INT(hdR));
((TypDigit*)PTR(hdQ))[1] = (-HD_TO_INT(hdR))>>16;
hdR = hdQ;
}
}
if ( SIZE(hdL) < SIZE(hdR) )
return INT_TO_HD(0);
hdQ = NewBag( TYPE(hdL), SIZE(hdL) + 4*sizeof(TypDigit) );
l = (TypDigit*)PTR(hdL);
q = (TypDigit*)PTR(hdQ);
for ( k = SIZE(hdL)/sizeof(TypDigit)-1; k >= 0; --k )
*q++ = *l++;
hdL = hdQ;
rs = SIZE(hdR)/sizeof(TypDigit);
r  = (TypDigit*)PTR(hdR);
while ( r[rs-1] == 0 )  --rs;
for ( e = 0; (r[rs-1]<<e) + (r[rs-2]>>(16-e)) < 65536/2; ++e ) ;
r1 = (r[rs-1]<<e) + (r[rs-2]>>(16-e));
r2 = (r[rs-2]<<e) + (rs>=3 ? r[rs-3]>>(16-e) : 0);
if ( TYPE(hdL) == TYPE(hdR) )
hdQ = NewBag( T_INTPOS, SIZE(hdL)-SIZE(hdR) );
else
hdQ = NewBag( T_INTNEG, SIZE(hdL)-SIZE(hdR) );
for ( i = (SIZE(hdL)-SIZE(hdR))/sizeof(TypDigit)-1; i >= 0; --i ) {
l = ((TypDigit*)PTR(hdL)) + rs + i;
l01 = ((65536*l[0]+l[-1])<<e) + (l[-2]>>(16-e));
if ( l01 == 0 )  continue;
l2  = (l[-2]<<e) + (rs+i>=3 ? l[-3]>>(16-e) : 0);
if ( (l[0]<<e)+(l[-1]>>(16-e)) < r1 )  qi = l01 / r1;
else                                   qi = 65536 - 1;
while ( l01-qi*r1 < 65536 && 65536*(l01-qi*r1)+l2 < qi*r2 )
--qi;
d = 0;
l = ((TypDigit*)PTR(hdL)) + i;
r = ((TypDigit*)PTR(hdR));
for ( k = 0; k < rs; ++k, ++l, ++r ) {
c = *l - qi * *r - d;  *l = c;  d = -(c>>16);
}
c = *l - d; d = -(c>>16);
if ( d != 0 ) {
d = 0;
l = ((TypDigit*)PTR(hdL)) + i;
r = ((TypDigit*)PTR(hdR));
for ( k = 0; k < rs; ++k, ++l, ++r ) {
c = *l + *r + d;  *l = c;  d = (c>>16);
}
c = *l + d; d = (c>>16);
qi--;
}
((TypDigit*)PTR(hdQ))[i] = qi;
}
q = ((TypDigit*)PTR(hdQ)) + SIZE(hdQ)/sizeof(TypDigit);
if ( SIZE(hdQ)>4*sizeof(TypDigit)
&& q[-4]==0 && q[-3]==0 && q[-2]==0 && q[-1]==0 ) {
Resize( hdQ, SIZE(hdQ)-4*sizeof(TypDigit) );
}
q = ((TypDigit*)PTR(hdQ)) + SIZE(hdQ)/sizeof(TypDigit);
if ( SIZE(hdQ)==4*sizeof(TypDigit) && q[-2]==0 && q[-1]==0 ) {
if ( TYPE(hdQ) == T_INTPOS
&& (unsigned long)(65536*q[-3]+q[-4]) < (1<<28) )
hdQ = INT_TO_HD( 65536*q[-3]+q[-4] );
else if ( TYPE(hdQ) == T_INTNEG
&& (unsigned long)(65536*q[-3]+q[-4]) <= (1<<28) )
hdQ = INT_TO_HD( -(65536*q[-3]+q[-4]) );
}
}
return hdQ;
}
TypHandle       FunQuo ( hdCall )
TypHandle           hdCall;
{
register TypHandle  hdL, hdR;
if ( SIZE(hdCall) != 3 * SIZE_HD )
return Error("usage: QuoInt( <int>, <int> )",0L,0L);
hdL = EVAL( PTR(hdCall)[1] );
if ( TYPE(hdL)!=T_INT && TYPE(hdL)!=T_INTPOS && TYPE(hdL)!=T_INTNEG )
return Error("usage: QuoInt( <int>, <int> )",0L,0L);
hdR = EVAL( PTR(hdCall)[2] );
if ( TYPE(hdR)!=T_INT && TYPE(hdR)!=T_INTPOS && TYPE(hdR)!=T_INTNEG )
return Error("usage: QuoInt( <int>, <int> )",0L,0L);
return QuoInt( hdL, hdR );
}
TypHandle       RemInt ( hdL, hdR )
TypHandle           hdL, hdR;
{
register long       i;
register long       k;
register unsigned long      c;
register TypDigit   d;
register TypDigit   * l;
register TypDigit   * r;
register TypDigit   r1;
register TypDigit   r2;
register unsigned long      rs;
register unsigned long      e;
register TypHandle  hdM;
register TypDigit   * m;
register unsigned long      m01;
register TypDigit   m2;
register TypDigit   qi;
if ( (long)hdL & (long)hdR & T_INT ) {
if ( hdR == INT_TO_HD(0) ) {
return Error("Integer operations: <divisor> must be nonzero",
0L,0L);
}
i = HD_TO_INT(hdL);
k = HD_TO_INT(hdR);
if (      0 <= i && 0 <= k )  i =    (  i %  k );
else if ( 0 <= i && k <  0 )  i =    (  i % -k );
else if ( i < 0  && 0 <= k )  i =  - ( -i %  k );
else if ( i < 0  && k <  0 )  i =  - ( -i % -k );
hdM = INT_TO_HD( i );
}
else if ( (long)hdL & T_INT ) {
if ( hdL == INT_TO_HD(-(1<<28))
&& TYPE(hdR) == T_INTPOS && SIZE(hdR) == 4*sizeof(TypDigit)
&& ((TypDigit*)PTR(hdR))[3] == 0 && ((TypDigit*)PTR(hdR))[2] == 0
&& 65536*((TypDigit*)PTR(hdR))[1]+((TypDigit*)PTR(hdR))[0]==1<<28 )
hdM = INT_TO_HD(0);
else
hdM = hdL;
}
else if ( (long)hdR & T_INT
&& HD_TO_INT(hdR) < 65536 && -65536 <= HD_TO_INT(hdR) ) {
if ( hdR == INT_TO_HD(0) ) {
return Error("Integer operations: <divisor> must be nonzero",
0L,0L);
}
i = HD_TO_INT(hdR);  if ( i < 0 )  i = -i;
if ( 65536 % i == 0 ) {
c = ((TypDigit*)PTR(hdL))[0] % i;
}
else {
l = (TypDigit*)PTR(hdL) + SIZE(hdL)/sizeof(TypDigit) - 1;
c = 0;
for ( ; l >= (TypDigit*)PTR(hdL); --l ) {
c  = (c<<16) + *l;
c  = c % i;
}
}
if ( TYPE(hdL) == T_INTPOS )
hdM = INT_TO_HD(  c );
else
hdM = INT_TO_HD( -c );
}
else {
if ( (long)hdR & T_INT ) {
if ( 0 < HD_TO_INT(hdR) ) {
hdM = NewBag( T_INTPOS, 4*sizeof(TypDigit) );
((TypDigit*)PTR(hdM))[0] = (TypDigit)(HD_TO_INT(hdR));
((TypDigit*)PTR(hdM))[1] = (HD_TO_INT(hdR)>>16);
hdR = hdM;
}
else {
hdM = NewBag( T_INTNEG, 4*sizeof(TypDigit) );
((TypDigit*)PTR(hdM))[0] = (TypDigit)(-HD_TO_INT(hdR));
((TypDigit*)PTR(hdM))[1] = (-HD_TO_INT(hdR))>>16;
hdR = hdM;
}
}
if ( SIZE(hdL) < SIZE(hdR) )
return hdL;
hdM = NewBag( TYPE(hdL), SIZE(hdL) + 4*sizeof(TypDigit) );
l = (TypDigit*)PTR(hdL);
m = (TypDigit*)PTR(hdM);
for ( k = SIZE(hdL)/sizeof(TypDigit)-1; k >= 0; --k )
*m++ = *l++;
rs = SIZE(hdR)/sizeof(TypDigit);
r  = (TypDigit*)PTR(hdR);
while ( r[rs-1] == 0 )  --rs;
for ( e = 0; (r[rs-1]<<e) + (r[rs-2]>>(16-e)) < 65536/2; ++e ) ;
r1 = (r[rs-1]<<e) + (r[rs-2]>>(16-e));
r2 = (r[rs-2]<<e) + (rs>=3 ? r[rs-3]>>(16-e) : 0);
for ( i = (SIZE(hdM)-SIZE(hdR))/sizeof(TypDigit)-1; i >= 0; --i ) {
m = ((TypDigit*)PTR(hdM)) + rs + i;
m01 = ((65536*m[0]+m[-1])<<e) + (m[-2]>>(16-e));
if ( m01 == 0 )  continue;
m2  = (m[-2]<<e) + (rs+i>=3 ? m[-3]>>(16-e) : 0);
if ( (m[0]<<e)+(m[-1]>>(16-e)) < r1 )  qi = m01 / r1;
else                                   qi = 65536 - 1;
while ( m01-qi*r1 < 65536 && 65536*(m01-qi*r1)+m2 < qi*r2 )
--qi;
d = 0;
m = ((TypDigit*)PTR(hdM)) + i;
r = ((TypDigit*)PTR(hdR));
for ( k = 0; k < rs; ++k, ++m, ++r ) {
c = *m - qi * *r - d;  *m = c;  d = -(c>>16);
}
c = *m - d;  *m = c;  d = -(c>>16);
if ( d != 0 ) {
d = 0;
m = ((TypDigit*)PTR(hdM)) + i;
r = ((TypDigit*)PTR(hdR));
for ( k = 0; k < rs; ++k, ++m, ++r ) {
c = *m + *r + d;  *m = c;  d = (c>>16);
}
c = *m + d;  *m = c;  d = (c>>16);
qi--;
}
}
m = ((TypDigit*)PTR(hdM))+ SIZE(hdM)/sizeof(TypDigit);
if ( (m[-4]==0 && m[-3]==0 && m[-2]==0 && m[-1]==0)
|| (SIZE(hdM)==4*sizeof(TypDigit) && m[-2]==0 && m[-1]==0) ) {
m = (TypDigit*)PTR(hdM);
for ( k=SIZE(hdM)/sizeof(TypDigit); k != 0; --k ) {
if ( m[k-1] != 0 )
break;
}
if ( k<=2 && TYPE(hdM) == T_INTPOS
&& (unsigned long)(65536*m[1]+m[0]) < (1<<28) )
hdM = INT_TO_HD( 65536*m[1]+m[0] );
else if ( k<=2 && TYPE(hdM) == T_INTNEG
&& (unsigned long)(65536*m[1]+m[0]) <= (1<<28) )
hdM = INT_TO_HD( -(65536*m[1]+m[0]) );
else
Resize( hdM, (((k + 3) / 4) * 4) * sizeof(TypDigit) );
}
}
return hdM;
}
TypHandle       FunRem ( hdCall )
TypHandle           hdCall;
{
register TypHandle  hdL, hdR;
if ( SIZE(hdCall) != 3 * SIZE_HD )
return Error("usage: RemInt( <int>, <int> )",0L,0L);
hdL = EVAL( PTR(hdCall)[1] );
if ( TYPE(hdL)!=T_INT && TYPE(hdL)!=T_INTPOS && TYPE(hdL)!=T_INTNEG )
return Error("usage: RemInt( <int>, <int> )",0L,0L);
hdR = EVAL( PTR(hdCall)[2] );
if ( TYPE(hdR)!=T_INT && TYPE(hdR)!=T_INTPOS && TYPE(hdR)!=T_INTNEG )
return Error("usage: RemInt( <int>, <int> )",0L,0L);
return RemInt( hdL, hdR );
}
TypHandle       GcdInt ( hdL, hdR )
TypHandle           hdL, hdR;
{
register SPEC_INT32_T i;
register SPEC_INT32_T k;
register unsigned SPEC_INT32_T   c;
register TypDigit   d;
register TypDigit   * r;
register TypDigit   r1;
register TypDigit   r2;
register unsigned SPEC_INT32_T rs;
register unsigned SPEC_INT32_T e;
register TypDigit   * l;
register unsigned SPEC_INT32_T l01;
register TypDigit   l2;
register unsigned SPEC_INT32_T ls;
register TypDigit   qi;
register TypHandle  hdG;
if ( (long)hdL & (long)hdR & T_INT ) {
i = HD_TO_INT(hdL);  if ( i < 0 )  i = -i;
k = HD_TO_INT(hdR);  if ( k < 0 )  k = -k;
while ( k != 0 ) {
c = k;
k = i % k;
i = c;
}
if ( i == (1<<28) ) {
hdG = NewBag( T_INTPOS, 4*sizeof(TypDigit) );
((TypDigit*)PTR(hdG))[0] = i;
((TypDigit*)PTR(hdG))[1] = (i>>16);
}
else {
hdG = INT_TO_HD( i );
}
}
else if ( ((long)hdL & T_INT
&& HD_TO_INT(hdL) < 65536 && -65536 <= HD_TO_INT(hdL))
|| ((long)hdR & T_INT
&& HD_TO_INT(hdR) < 65536 && -65536 <= HD_TO_INT(hdR)) ) {
if ( (long)hdL & T_INT ) {
hdG = hdL;  hdL = hdR;  hdR = hdG;
}
if ( hdR == INT_TO_HD(0) )
return hdL;
i = HD_TO_INT(hdR);  if ( i < 0 )  i = -i;
l = (TypDigit*)PTR(hdL) + SIZE(hdL)/sizeof(TypDigit) - 1;
c = 0;
for ( ; l >= (TypDigit*)PTR(hdL); --l ) {
c  = (c<<16) + *l;
c  = c % i;
}
k = c;
while ( k != 0 ) {
c = k;
k = i % k;
i = c;
}
if ( i == (1<<28) ) {
hdG = NewBag( T_INTPOS, 4*sizeof(TypDigit) );
((TypDigit*)PTR(hdG))[0] = i;
((TypDigit*)PTR(hdG))[1] = (i>>16);
}
else {
hdG = INT_TO_HD( i );
}
}
else {
if ( (long)hdL & T_INT ) {
if ( 0 < HD_TO_INT(hdL) ) {
hdG = NewBag( T_INTPOS, 4*sizeof(TypDigit) );
((TypDigit*)PTR(hdG))[0] = (TypDigit)(HD_TO_INT(hdL));
((TypDigit*)PTR(hdG))[1] = (HD_TO_INT(hdL)>>16);
hdL = hdG;
}
else {
hdG = NewBag( T_INTNEG, 4*sizeof(TypDigit) );
((TypDigit*)PTR(hdG))[0] = (TypDigit)(-HD_TO_INT(hdL));
((TypDigit*)PTR(hdG))[1] = (-HD_TO_INT(hdL))>>16;
hdL = hdG;
}
}
if ( (long)hdR & T_INT ) {
if ( 0 < HD_TO_INT(hdR) ) {
hdG = NewBag( T_INTPOS, 4*sizeof(TypDigit) );
((TypDigit*)PTR(hdG))[0] = (TypDigit)(HD_TO_INT(hdR));
((TypDigit*)PTR(hdG))[1] = (HD_TO_INT(hdR)>>16);
hdR = hdG;
}
else {
hdG = NewBag( T_INTNEG, 4*sizeof(TypDigit) );
((TypDigit*)PTR(hdG))[0] = (TypDigit)(-HD_TO_INT(hdR));
((TypDigit*)PTR(hdG))[1] = (-HD_TO_INT(hdR))>>16;
hdR = hdG;
}
}
hdG = NewBag( T_INTPOS, SIZE(hdL) + 4*sizeof(TypDigit) );
l = (TypDigit*)PTR(hdL);
r = (TypDigit*)PTR(hdG);
for ( k = SIZE(hdL)/sizeof(TypDigit)-1; k >= 0; --k )
*r++ = *l++;
hdL = hdG;
ls = SIZE(hdL)/sizeof(TypDigit);
l  = (TypDigit*)PTR(hdL);
while ( ls >= 1 && l[ls-1] == 0 )  --ls;
hdG = NewBag( T_INTPOS, SIZE(hdR) + 4*sizeof(TypDigit) );
r = (TypDigit*)PTR(hdR);
l = (TypDigit*)PTR(hdG);
for ( k = SIZE(hdR)/sizeof(TypDigit)-1; k >= 0; --k )
*l++ = *r++;
hdR = hdG;
rs = SIZE(hdR)/sizeof(TypDigit);
r  = (TypDigit*)PTR(hdR);
while ( rs >= 1 && r[rs-1] == 0 )  --rs;
while ( rs >= 2 ) {
for ( e = 0; (r[rs-1]<<e) + (r[rs-2]>>(16-e)) < 65536/2; ++e ) ;
r1 = (r[rs-1]<<e) + (r[rs-2]>>(16-e));
r2 = (r[rs-2]<<e) + (rs>=3 ? r[rs-3]>>(16-e) : 0);
for ( i = ls - rs; i >= 0; --i ) {
l = ((TypDigit*)PTR(hdL)) + rs + i;
l01 = ((65536*l[0]+l[-1])<<e) + (l[-2]>>(16-e));
if ( l01 == 0 )  continue;
l2  = (l[-2]<<e) + (rs+i>=3 ? l[-3]>>(16-e) : 0);
if ( (l[0]<<e)+(l[-1]>>(16-e)) < r1 )  qi = l01 / r1;
else                                   qi = 65536 - 1;
while ( l01-qi*r1 < 65536 && 65536*(l01-qi*r1)+l2 < qi*r2 )
--qi;
d = 0;
l = ((TypDigit*)PTR(hdL)) + i;
r = ((TypDigit*)PTR(hdR));
for ( k = 0; k < rs; ++k, ++l, ++r ) {
c = *l - qi * *r - d;  *l = c;  d = -(c>>16);
}
c = *l - d;  *l = c;  d = -(c>>16);
if ( d != 0 ) {
d = 0;
l = ((TypDigit*)PTR(hdL)) + i;
r = ((TypDigit*)PTR(hdR));
for ( k = 0; k < rs; ++k, ++l, ++r ) {
c = *l + *r + d;  *l = c;  d = (c>>16);
}
c = *l + d;  *l = c;  d = (c>>16);
qi--;
}
}
hdG = hdL;  hdL = hdR;  hdR = hdG;
ls = rs;
rs = SIZE(hdR)/sizeof(TypDigit);
r  = (TypDigit*)PTR(hdR);
while ( rs >= 1 && r[rs-1] == 0 )  --rs;
}
if ( rs == 0 ) {
l = ((TypDigit*)PTR(hdL))+ SIZE(hdL)/sizeof(TypDigit);
if ( (l[-4]==0 && l[-3]==0 && l[-2]==0 && l[-1]==0)
|| (SIZE(hdL)==4*sizeof(TypDigit) && l[-2]==0 && l[-1]==0) ) {
l = (TypDigit*)PTR(hdL);
for ( k=SIZE(hdL)/sizeof(TypDigit); k != 0; --k ) {
if ( l[k-1] != 0 )
break;
}
if ( k<=2 && TYPE(hdL) == T_INTPOS
&& (unsigned long)(65536*l[1]+l[0]) < (1<<28) )
hdL = INT_TO_HD( 65536*l[1]+l[0] );
else if ( k<=2 && TYPE(hdL) == T_INTNEG
&& (unsigned long)(65536*l[1]+l[0]) <= (1<<28) )
hdL = INT_TO_HD( -(65536*l[1]+l[0]) );
else
Resize( hdL, (((k + 3) / 4) * 4) * sizeof(TypDigit) );
}
hdG = hdL;
}
else {
i = r[0];
l = (TypDigit*)PTR(hdL) + SIZE(hdL)/sizeof(TypDigit) - 1;
c = 0;
for ( ; l >= (TypDigit*)PTR(hdL); --l ) {
c  = (c<<16) + *l;
c  = c % i;
}
k = c;
while ( k != 0 ) {
c = k;
k = i % k;
i = c;
}
if ( i == (1<<28) ) {
hdG = NewBag( T_INTPOS, 4*sizeof(TypDigit) );
((TypDigit*)PTR(hdG))[0] = i;
((TypDigit*)PTR(hdG))[1] = (i>>16);
}
else {
hdG = INT_TO_HD( i );
}
}
}
return hdG;
}
TypHandle       FunGcdInt ( hdCall )
TypHandle           hdCall;
{
register TypHandle  hdL, hdR;
if ( SIZE(hdCall) != 3 * SIZE_HD )
return Error("usage: GcdInt( <int>, <int> )",0L,0L);
hdL = EVAL( PTR(hdCall)[1] );
if ( TYPE(hdL)!=T_INT && TYPE(hdL)!=T_INTPOS && TYPE(hdL)!=T_INTNEG )
return Error("usage: GcdInt( <int>, <int> )",0L,0L);
hdR = EVAL( PTR(hdCall)[2] );
if ( TYPE(hdR)!=T_INT && TYPE(hdR)!=T_INTPOS && TYPE(hdR)!=T_INTNEG )
return Error("usage: GcdInt( <int>, <int> )",0L,0L);
return GcdInt( hdL, hdR );
}
void            InitInt ()
{
InstEvFunc( T_INT,    EvInt );
InstEvFunc( T_INTPOS, EvInt );
InstEvFunc( T_INTNEG, EvInt );
InstPrFunc( T_INT,    PrInteger );
InstPrFunc( T_INTPOS, PrInteger );
InstPrFunc( T_INTNEG, PrInteger );
TabSum[  T_INT    ][ T_INT    ] = SumInt;
TabSum[  T_INT    ][ T_INTPOS ] = SumInt;
TabSum[  T_INT    ][ T_INTNEG ] = SumInt;
TabSum[  T_INTPOS ][ T_INT    ] = SumInt;
TabSum[  T_INTPOS ][ T_INTPOS ] = SumInt;
TabSum[  T_INTPOS ][ T_INTNEG ] = SumInt;
TabSum[  T_INTNEG ][ T_INT    ] = SumInt;
TabSum[  T_INTNEG ][ T_INTPOS ] = SumInt;
TabSum[  T_INTNEG ][ T_INTNEG ] = SumInt;
TabDiff[ T_INT    ][ T_INT    ] = DiffInt;
TabDiff[ T_INT    ][ T_INTPOS ] = DiffInt;
TabDiff[ T_INT    ][ T_INTNEG ] = DiffInt;
TabDiff[ T_INTPOS ][ T_INT    ] = DiffInt;
TabDiff[ T_INTPOS ][ T_INTPOS ] = DiffInt;
TabDiff[ T_INTPOS ][ T_INTNEG ] = DiffInt;
TabDiff[ T_INTNEG ][ T_INT    ] = DiffInt;
TabDiff[ T_INTNEG ][ T_INTPOS ] = DiffInt;
TabDiff[ T_INTNEG ][ T_INTNEG ] = DiffInt;
TabProd[ T_INT    ][ T_INT    ] = ProdInt;
TabProd[ T_INT    ][ T_INTPOS ] = ProdInt;
TabProd[ T_INT    ][ T_INTNEG ] = ProdInt;
TabProd[ T_INTPOS ][ T_INT    ] = ProdInt;
TabProd[ T_INTPOS ][ T_INTPOS ] = ProdInt;
TabProd[ T_INTPOS ][ T_INTNEG ] = ProdInt;
TabProd[ T_INTNEG ][ T_INT    ] = ProdInt;
TabProd[ T_INTNEG ][ T_INTPOS ] = ProdInt;
TabProd[ T_INTNEG ][ T_INTNEG ] = ProdInt;
TabMod[  T_INT    ][ T_INT    ] = ModInt;
TabMod[  T_INT    ][ T_INTPOS ] = ModInt;
TabMod[  T_INT    ][ T_INTNEG ] = ModInt;
TabMod[  T_INTPOS ][ T_INT    ] = ModInt;
TabMod[  T_INTPOS ][ T_INTPOS ] = ModInt;
TabMod[  T_INTPOS ][ T_INTNEG ] = ModInt;
TabMod[  T_INTNEG ][ T_INT    ] = ModInt;
TabMod[  T_INTNEG ][ T_INTPOS ] = ModInt;
TabMod[  T_INTNEG ][ T_INTNEG ] = ModInt;
TabPow[  T_INT    ][ T_INT    ] = PowInt;
TabPow[  T_INT    ][ T_INTPOS ] = PowInt;
TabPow[  T_INT    ][ T_INTNEG ] = PowInt;
TabPow[  T_INTPOS ][ T_INT    ] = PowInt;
TabPow[  T_INTPOS ][ T_INTPOS ] = PowInt;
TabPow[  T_INTPOS ][ T_INTNEG ] = PowInt;
TabPow[  T_INTNEG ][ T_INT    ] = PowInt;
TabPow[  T_INTNEG ][ T_INTPOS ] = PowInt;
TabPow[  T_INTNEG ][ T_INTNEG ] = PowInt;
TabEq[   T_INT    ][ T_INT    ] = EqInt;
TabEq[   T_INT    ][ T_INTPOS ] = EqInt;
TabEq[   T_INT    ][ T_INTNEG ] = EqInt;
TabEq[   T_INTPOS ][ T_INT    ] = EqInt;
TabEq[   T_INTPOS ][ T_INTPOS ] = EqInt;
TabEq[   T_INTPOS ][ T_INTNEG ] = EqInt;
TabEq[   T_INTNEG ][ T_INT    ] = EqInt;
TabEq[   T_INTNEG ][ T_INTPOS ] = EqInt;
TabEq[   T_INTNEG ][ T_INTNEG ] = EqInt;
TabLt[   T_INT    ][ T_INT    ] = LtInt;
TabLt[   T_INT    ][ T_INTPOS ] = LtInt;
TabLt[   T_INT    ][ T_INTNEG ] = LtInt;
TabLt[   T_INTPOS ][ T_INT    ] = LtInt;
TabLt[   T_INTPOS ][ T_INTPOS ] = LtInt;
TabLt[   T_INTPOS ][ T_INTNEG ] = LtInt;
TabLt[   T_INTNEG ][ T_INT    ] = LtInt;
TabLt[   T_INTNEG ][ T_INTPOS ] = LtInt;
TabLt[   T_INTNEG ][ T_INTNEG ] = LtInt;
InstIntFunc( "IsInt",  FunIsInt  );
InstIntFunc( "QuoInt", FunQuo    );
InstIntFunc( "RemInt", FunRem    );
InstIntFunc( "GcdInt", FunGcdInt );
}
/* 当前文件是D:\Read\list.c*/


long            CantLenList ( hdList )
TypHandle           hdList;
{
return HD_TO_INT( Error("Length: <list> must be a list",0L,0L) );
}

TypHandle       CantElmList ( hdList, pos )
TypHandle           hdList;
long                pos;
{
return Error("List Element: <list> must be a list",0L,0L);
}

TypHandle       CantElmsList ( hdList, hdPoss )
TypHandle           hdList;
TypHandle           hdPoss;
{
return Error("List Elements: <list> must be a list",0L,0L);
}
TypHandle       CantAssList ( hdList, pos, hdVal )
TypHandle           hdList;
long                pos;
TypHandle           hdVal;
{
return Error("List Assignment: <list> must be a list",0L,0L);
}

TypHandle       CantAsssList ( hdList, hdPoss, hdVals )
TypHandle           hdList;
TypHandle           hdPoss;
TypHandle           hdVals;
{
return Error("List Assignment: <list> must be a list",0L,0L);
}

long            CantPosList ( hdList, hdVal, start )
TypHandle           hdList;
TypHandle           hdVal;
long                start;
{
return HD_TO_INT( Error("Position: <list> must be a list",0L,0L) );
}

void            CantPlainList ( hdList )
TypHandle           hdList;
{
Error("Panic: cannot convert <list> to a plain list",0L,0L);
}
long            IsList ( hdObj )
TypHandle           hdObj;
{
if ( ! IS_LIST( hdObj ) ) {
return 0;
}
else {
PLAIN_LIST( hdObj );
return 1;
}
}

long            NotIsDenseList ( hdObj )
TypHandle           hdObj;
{
return 0;
}

long            NotIsPossList ( hdObj )
TypHandle           hdObj;
{
return 0;
}

long            XType ( hdObj )
TypHandle           hdObj;
{
long                t;
if ( TYPE(hdObj) < T_LIST || TYPE(hdObj) == T_REC )
return TYPE(hdObj);
for ( t = T_VAR-1; T_LIST <= t; t-- ) {
if ( TabIsXTypeList[t] != 0 && IS_XTYPE_LIST( t, hdObj ) )
return t;
}
return T_LISTX;
}

TypHandle       EvIn ( hdIn )
TypHandle           hdIn;
{
TypHandle           hdVal;
TypHandle           hdList;
long                pos;
hdVal = EVAL( PTR(hdIn)[0] );
if ( hdVal == HdVoid ) {
return Error(
"In: function must return a value",
0L, 0L );
}
hdList = EVAL( PTR(hdIn)[1] );
if ( TYPE(hdList) == T_REC )
return InRec( hdVal, hdList );
pos = POS_LIST( hdList, hdVal, 0L );
return (pos != 0) ? HdTrue : HdFalse;
}
TypHandle       FunIsList ( hdCall )
TypHandle           hdCall;
{
TypHandle           hdObj;
if ( SIZE(hdCall) != 2 * SIZE_HD )
return Error("usage: IsList( <obj> )",0L,0L);
hdObj = EVAL( PTR(hdCall)[1] );
if ( hdObj == HdVoid ) {
return Error(
"IsList: function must return a value",
0L,0L);
}
return IS_LIST(hdObj) ? HdTrue : HdFalse;
}
long            IsVector ( hdObj )
TypHandle           hdObj;
{
if ( IS_LIST( hdObj ) && (TabIsList[ XType( hdObj ) ] == 2) )
return 1;
else
return 0;
}
TypHandle       FunIsVector ( hdCall )
TypHandle           hdCall;
{
TypHandle           hdObj;
if ( SIZE(hdCall) != 2*SIZE_HD )
return Error("usage: IsVector( <obj> )",0L,0L);
hdObj = EVAL( PTR(hdCall)[1] );
if ( hdObj == HdVoid )
return Error("IsVector: function must return value",0L,0L);
if ( IS_LIST( hdObj ) && (TabIsList[ XType( hdObj ) ] == 2) )
return HdTrue;
else
return HdFalse;
}
TypHandle       FunIsMat ( hdCall )
TypHandle           hdCall;
{
TypHandle           hdObj;
if ( SIZE(hdCall) != 2*SIZE_HD )
return Error("usage: IsMat( <obj> )",0L,0L);
hdObj = EVAL( PTR(hdCall)[1] );
if ( hdObj == HdVoid )
return Error("IsMat: function must return value",0L,0L);
if ( IS_LIST( hdObj ) && (TabIsList[ XType( hdObj ) ] == 3) )
return HdTrue;
else
return HdFalse;
}
TypHandle       FunLength ( hdCall )
TypHandle           hdCall;
{
TypHandle           hdList;
if ( SIZE(hdCall) != 2 * SIZE_HD )
return Error("usage: Length( <list> )",0L,0L);
hdList = EVAL( PTR(hdCall)[1] );
if ( TYPE(hdList) == T_LIST ) {
return PTR(hdList)[0];
}
else {
return INT_TO_HD( LEN_LIST( hdList ) );
}
}
TypHandle       FunAdd ( hdCall )
TypHandle           hdCall;
{
TypHandle           hdList;
TypHandle           hdVal;
long                pos;
long                plen;
if ( SIZE(hdCall) != 3 * SIZE_HD ) {
return Error(
"usage: Add( <list>, <val> )",
0L, 0L );
}
hdList = EVAL( PTR(hdCall)[1] );
if ( ! IS_LIST( hdList ) ) {
return Error(
"Add: <list> must be a list",
0L, 0L );
}
hdVal = EVAL( PTR(hdCall)[2] );
if ( hdVal == HdVoid ) {
return Error(
"Add: function must return a value",
0L, 0L );
}
if ( TYPE(hdList) == T_LIST ) {
pos = LEN_PLIST( hdList ) + 1;
plen = PLEN_SIZE_PLIST( SIZE( hdList ) );
if ( plen + plen/8 + 4 < pos )
Resize( hdList, SIZE_PLEN_PLIST( pos ) );
else if ( plen < pos )
Resize( hdList, SIZE_PLEN_PLIST( plen + plen/8 + 4 ) );
SET_LEN_PLIST( hdList, pos );
SET_ELM_PLIST( hdList, pos, hdVal );
}
else {
pos = LEN_LIST( hdList ) + 1;
ASS_LIST( hdList, pos, hdVal );
}
return HdVoid;
}
TypHandle       FunAppend ( hdCall )
TypHandle           hdCall;
{
TypHandle           hdList1;
TypHandle           hdList2;
long                lenList1;
long                lenList2;
TypHandle           hdElm;
long                plen;
long                i;
if ( SIZE(hdCall) != 3 * SIZE_HD )
return Error("usage: Append( <list1>, <list2> )",0L,0L);
hdList1 = EVAL( PTR(hdCall)[1] );
if ( ! IS_LIST( hdList1 ) ) {
return Error(
"Append: <list1> must be a list",
0L,0L);
}
PLAIN_LIST( hdList1 );
Retype( hdList1, T_LIST );
lenList1 = LEN_PLIST( hdList1 );
hdList2 = EVAL( PTR(hdCall)[2] );
if ( ! IS_LIST( hdList2 ) ) {
return Error(
"Append: <list2> must be a list",
0L,0L);
}
lenList2 = LEN_LIST( hdList2 );
if ( 0 < lenList2 ) {
plen = PLEN_SIZE_PLIST( SIZE(hdList1) );
if ( plen + plen/8 + 4 < lenList1 + lenList2 )
Resize( hdList1, SIZE_PLEN_PLIST( lenList1 + lenList2 ) );
else if ( plen < lenList1 + lenList2 )
Resize( hdList1, SIZE_PLEN_PLIST( plen + plen/8 + 4 ) );
SET_LEN_PLIST( hdList1, lenList1+lenList2 );
}
if ( TYPE(hdList2) == T_LIST ) {
for ( i = 1; i <= lenList2; i++ ) {
hdElm = ELM_PLIST( hdList2, i );
SET_ELM_PLIST( hdList1, i+lenList1, hdElm );
}
}
else {
for ( i = 1; i <= lenList2; i++ ) {
hdElm = ELMF_LIST( hdList2, i );
SET_ELM_PLIST( hdList1, i+lenList1, hdElm );
}
}
return HdVoid;
}
TypHandle       FunPosition ( hdCall )
TypHandle           hdCall;
{
TypHandle           hdList;
TypHandle           hdVal;
long                start;
long                k;
if ( SIZE(hdCall) != 3*SIZE_HD && SIZE(hdCall) != 4*SIZE_HD ) {
return Error(
"usage: Position( <list>, <obj> )",
0L,0L);
}
if ( SIZE(hdCall) == 4*SIZE_HD ) {
hdVal = EVAL( PTR(hdCall)[3] );
if ( TYPE(hdVal) != T_INT || HD_TO_INT(hdVal) < 0 ) {
return Error(
"Position: <start> must be a nonnegative int",
0L,0L);
}
start = HD_TO_INT(hdVal);
}
else {
start = 0;
}
hdVal = EVAL( PTR(hdCall)[2] );
if ( hdVal == HdVoid ) {
return Error(
"Position: function must return a value",
0L,0L);
}
hdList = EVAL( PTR(hdCall)[1] );
if ( ! IS_LIST( hdList ) ) {
return Error(
"Position: <list> must be a list",
0L,0L);
}
k = POS_LIST( hdList, hdVal, start );
return (k != 0) ? INT_TO_HD( k ) : HdFalse;
}
TypHandle       FunOnPoints ( hdCall )
TypHandle           hdCall;
{
TypHandle           hdRes;
TypHandle           hdPnt;
TypHandle           hdElm;
if ( SIZE(hdCall) != 3*SIZE_HD )
return Error("usage: OnPoints( <point>, <g> )",0L,0L);
hdPnt = EVAL( PTR(hdCall)[1] );
hdElm = EVAL( PTR(hdCall)[2] );
hdRes = POW( hdPnt, hdElm );
return hdRes;
}
TypHandle       FunOnPairs ( hdCall )
TypHandle           hdCall;
{
TypHandle           hdRes;
TypHandle           hdPair;
TypHandle           hdElm;
TypHandle           hdTmp;
if ( SIZE(hdCall) != 3*SIZE_HD )
return Error("usage: OnPairs( <pair>, <g> )",0L,0L);
hdPair = EVAL( PTR(hdCall)[1] );
if ( ! IS_LIST( hdPair ) )
return Error("OnPairs: <pair> must be a list",0L,0L);
hdElm = EVAL( PTR(hdCall)[2] );
if ( LEN_LIST( hdPair ) != 2 )
return Error("<pair> must be a list of length 2",0L,0L);
hdRes = NewBag( T_LIST, SIZE_PLEN_PLIST( 2 ) );
SET_LEN_PLIST( hdRes, 2 );
hdTmp = POW( ELMF_LIST( hdPair, 1 ), hdElm );
SET_ELM_PLIST( hdRes, 1, hdTmp );
hdTmp = POW( ELMF_LIST( hdPair, 2 ), hdElm );
SET_ELM_PLIST( hdRes, 2, hdTmp );
return hdRes;
}
TypHandle       FunOnTuples ( hdCall )
TypHandle           hdCall;
{
TypHandle           hdRes;
TypHandle           hdTup;
TypHandle           hdElm;
TypHandle           hdTmp;
unsigned long       i;
if ( SIZE(hdCall) != 3*SIZE_HD )
return Error("usage: OnTuples( <tuple>, <g> )",0L,0L);
hdTup = EVAL( PTR(hdCall)[1] );
if ( ! IS_LIST( hdTup ) )
return Error("OnTuples: <tuple> must be a list",0L,0L);
hdElm = EVAL( PTR(hdCall)[2] );
if ( TYPE(hdElm) == T_PERM16 || TYPE(hdElm) == T_PERM32 ) {
PLAIN_LIST( hdTup );
return OnTuplesPerm( hdTup, hdElm );
}
hdRes = NewBag( T_LIST, SIZE_PLEN_PLIST( LEN_LIST(hdTup) ) );
SET_LEN_PLIST( hdRes, LEN_LIST(hdTup) );
for ( i = LEN_LIST(hdTup); 1 <= i; i-- ) {
hdTmp = POW( ELMF_LIST( hdTup, i ), hdElm );
SET_ELM_PLIST( hdRes, i, hdTmp );
}
return hdRes;
}
TypHandle       FunOnSets ( hdCall )
TypHandle           hdCall;
{
TypHandle           hdRes;
TypHandle           hdSet;
TypHandle           hdElm;
TypHandle           hdTmp;
unsigned long       len;
unsigned long       mutable;
unsigned long       h;
unsigned long       i, k;
if ( SIZE(hdCall) != 3*SIZE_HD )
return Error("usage: OnSets( <tuple>, <g> )",0L,0L);
hdSet = EVAL( PTR(hdCall)[1] );
if ( TYPE(hdSet) != T_SET && ! IsSet( hdSet ) )
return Error("OnSets: <tuple> must be a set",0L,0L);
hdElm = EVAL( PTR(hdCall)[2] );
if ( TYPE(hdElm) == T_PERM16 || TYPE(hdElm) == T_PERM32 ) {
return OnSetsPerm( hdSet, hdElm );
}
len = LEN_LIST(hdSet);
hdRes = NewBag( T_LIST, SIZE_PLEN_PLIST( len ) );
SET_LEN_PLIST( hdRes, 0 );
mutable = 0;
for ( i = 1; i <= len; i++ ) {
hdTmp = POW( ELMF_LIST( hdSet, i ), hdElm );
SET_ELM_PLIST( hdRes, i, hdTmp );
mutable = mutable || (T_LIST <= TYPE(hdTmp));
}
h = 1;  while ( 9*h + 4 < len )  h = 3*h + 1;
while ( 0 < h ) {
for ( i = h+1; i <= len; i++ ) {
hdTmp = ELM_PLIST( hdRes, i );  k = i;
while ( h < k && LT( hdTmp, ELM_PLIST(hdRes,k-h) ) == HdTrue ) {
SET_ELM_PLIST( hdRes, k, ELM_PLIST(hdRes,k-h) );
k -= h;
}
SET_ELM_PLIST( hdRes, k, hdTmp );
}
h = h / 3;
}
k = 0;
if ( 0 < len ) {
hdTmp = ELM_PLIST( hdRes, 1 );
k = 1;
for ( i = 2; i <= len; i++ ) {
if ( EQ( hdTmp, ELM_PLIST( hdRes, i ) ) != HdTrue ) {
k += 1;
hdTmp = ELM_PLIST( hdRes, i );
SET_ELM_PLIST( hdRes, k, hdTmp );
}
}
}
if ( ! mutable )
Retype( hdRes, T_SET );
if ( k < len )
Resize( hdRes, SIZE_PLEN_PLIST(k) );
SET_LEN_PLIST( hdRes, k );
return hdRes;
}
TypHandle       FunOnRight ( hdCall )
TypHandle           hdCall;
{
TypHandle           hdRes;
TypHandle           hdPnt;
TypHandle           hdElm;
if ( SIZE(hdCall) != 3*SIZE_HD )
return Error("usage: OnRight( <point>, <g> )",0L,0L);
hdPnt = EVAL( PTR(hdCall)[1] );
hdElm = EVAL( PTR(hdCall)[2] );
hdRes = PROD( hdPnt, hdElm );
return hdRes;
}
TypHandle       FunOnLeft ( hdCall )
TypHandle           hdCall;
{
TypHandle           hdRes;
TypHandle           hdPnt;
TypHandle           hdElm;
if ( SIZE(hdCall) != 3*SIZE_HD )
return Error("usage: OnLeft( <point>, <g> )",0L,0L);
hdPnt = EVAL( PTR(hdCall)[1] );
hdElm = EVAL( PTR(hdCall)[2] );
hdRes = PROD( hdElm, hdPnt );
return hdRes;
}
TypHandle DepthListx ( hdVec )
TypHandle           hdVec;
{
long                pos;
TypHandle           zero;
long                len;
TypHandle           tmp;
len = LEN_LIST(hdVec);
if ( len == 0 )
return INT_TO_HD(1);
tmp = ELML_LIST(hdVec,1);
if ( TYPE(tmp) == T_INT )
zero = INT_TO_HD(0);
else
zero = PROD( INT_TO_HD(0), tmp );
for ( pos = 1;  pos <= len;  pos++ ) {
tmp = ELML_LIST(hdVec,pos);
if ( T_LIST <= TYPE(tmp) && TYPE(tmp) < T_REC )
return Error( "DepthVector: <list> must be a vector", 0L, 0L );
if ( zero != tmp && EQ( zero, tmp ) == HdFalse )
break;
}
return INT_TO_HD(pos);
}
TypHandle (*TabDepthVector[T_VAR]) P(( TypHandle ));
TypHandle FunDepthVector ( hdCall )
TypHandle           hdCall;
{
TypHandle           hdVec;
if ( SIZE(hdCall) != 2 * SIZE_HD )
return Error("usage: DepthVector( <vec> )", 0L, 0L);
hdVec = EVAL(PTR(hdCall)[1]);
return TabDepthVector[XType(hdVec)]( hdVec );
}
TypHandle CantDepthVector ( hdList )
TypHandle           hdList;
{
return Error( "DepthVector: <list> must be a vector", 0L, 0L );
}
void            InitList ()
{
long                type1, type2;
for ( type1 = T_VOID; type1 < T_VAR; type1++ ) {
TabIsList     [type1] = 0;
TabLenList    [type1] = CantLenList;
TabElmList    [type1] = CantElmList;
TabElmfList   [type1] = CantElmList;
TabElmlList   [type1] = CantElmList;
TabElmrList   [type1] = CantElmList;
TabElmsList   [type1] = CantElmsList;
TabAssList    [type1] = CantAssList;
TabAsssList   [type1] = CantAsssList;
TabPosList    [type1] = CantPosList;
TabPlainList  [type1] = CantPlainList;
TabIsDenseList[type1] = NotIsDenseList;
TabIsPossList [type1] = NotIsPossList;
}
for ( type1 = T_VOID;  type1 < T_VAR;  type1++ )
TabDepthVector[type1] = CantDepthVector;
TabDepthVector[T_LISTX ] = DepthListx;
TabDepthVector[T_VECTOR] = DepthListx;
for ( type1 = T_LIST; type1 < T_REC; type1++ ) {
EvTab[type1] = EvList;
PrTab[type1] = PrList;
}
for ( type1 = T_LIST; type1 < T_REC; type1++ ) {
for ( type2 = T_LIST; type2 < T_REC; type2++ ) {
TabEq[type1][type2] = EqList;
TabLt[type1][type2] = LtList;
}
}
for ( type1 = T_INT; type1 < T_REC; type1++ ) {
TabSum [type1  ][T_LIST ] = SumList;
TabSum [type1  ][T_SET  ] = SumList;
TabSum [type1  ][T_RANGE] = SumList;
TabSum [T_LIST ][type1  ] = SumList;
TabSum [T_SET  ][type1  ] = SumList;
TabSum [T_RANGE][type1  ] = SumList;
TabDiff[type1  ][T_LIST ] = DiffList;
TabDiff[type1  ][T_SET  ] = DiffList;
TabDiff[type1  ][T_RANGE] = DiffList;
TabDiff[T_LIST ][type1  ] = DiffList;
TabDiff[T_SET  ][type1  ] = DiffList;
TabDiff[T_RANGE][type1  ] = DiffList;
TabProd[type1  ][T_LIST ] = ProdList;
TabProd[type1  ][T_SET  ] = ProdList;
TabProd[type1  ][T_RANGE] = ProdList;
TabProd[T_LIST ][type1  ] = ProdList;
TabProd[T_SET  ][type1  ] = ProdList;
TabProd[T_RANGE][type1  ] = ProdList;
TabQuo [type1  ][T_LIST ] = QuoList;
TabQuo [type1  ][T_SET  ] = QuoList;
TabQuo [type1  ][T_RANGE] = QuoList;
TabQuo [T_LIST ][type1  ] = QuoList;
TabQuo [T_SET  ][type1  ] = QuoList;
TabQuo [T_RANGE][type1  ] = QuoList;
TabMod [type1  ][T_LIST ] = ModList;
TabMod [type1  ][T_SET  ] = ModList;
TabMod [type1  ][T_RANGE] = ModList;
TabMod [T_LIST ][type1  ] = ModList;
TabMod [T_SET  ][type1  ] = ModList;
TabMod [T_RANGE][type1  ] = ModList;
TabPow [type1  ][T_LIST ] = PowList;
TabPow [type1  ][T_SET  ] = PowList;
TabPow [type1  ][T_RANGE] = PowList;
TabPow [T_LIST ][type1  ] = PowList;
TabPow [T_SET  ][type1  ] = PowList;
TabPow [T_RANGE][type1  ] = PowList;
TabComm[type1  ][T_LIST ] = CommList;
TabComm[type1  ][T_SET  ] = CommList;
TabComm[type1  ][T_RANGE] = CommList;
TabComm[T_LIST ][type1  ] = CommList;
TabComm[T_SET  ][type1  ] = CommList;
TabComm[T_RANGE][type1  ] = CommList;
}
for ( type1 = T_INT; type1 < T_LIST; type1++ ) {
TabSum [type1  ][T_LISTX] = SumSclList;
TabSum [T_LISTX][type1  ] = SumListScl;
TabDiff[type1  ][T_LISTX] = DiffSclList;
TabDiff[T_LISTX][type1  ] = DiffListScl;
TabProd[type1  ][T_LISTX] = ProdSclList;
TabProd[T_LISTX][type1  ] = ProdListScl;
TabQuo [T_LISTX][type1  ] = QuoLists;
TabMod [type1  ][T_LISTX] = ModLists;
}
EvTab[T_LISTELM  ] = EvElmList;
EvTab[T_LISTELML ] = EvElmListLevel;
EvTab[T_LISTELMS ] = EvElmsList;
EvTab[T_LISTELMSL] = EvElmsListLevel;
EvTab[T_LISTASS  ] = EvAssList;
EvTab[T_LISTASSL ] = EvAssListLevel;
EvTab[T_LISTASSS ] = EvAsssList;
EvTab[T_LISTASSSL] = EvAsssListLevel;
PrTab[T_LISTELM  ] = PrElmList;
PrTab[T_LISTELML ] = PrElmList;
PrTab[T_LISTELMS ] = PrElmsList;
PrTab[T_LISTELMSL] = PrElmsList;
PrTab[T_LISTASS  ] = PrAssList;
PrTab[T_LISTASSL ] = PrAssList;
PrTab[T_LISTASSS ] = PrAssList;
PrTab[T_LISTASSSL] = PrAssList;
EvTab[T_IN       ] = EvIn;
InstIntFunc( "IsList",       FunIsList   );
InstIntFunc( "IsVector",     FunIsVector );
InstIntFunc( "IsMat",        FunIsMat    );
InstIntFunc( "Length",       FunLength   );
InstIntFunc( "Add",          FunAdd      );
InstIntFunc( "Append",       FunAppend   );
InstIntFunc( "Position",     FunPosition );
InstIntFunc( "OnPoints",     FunOnPoints );
InstIntFunc( "OnPairs",      FunOnPairs  );
InstIntFunc( "OnTuples",     FunOnTuples );
InstIntFunc( "OnSets",       FunOnSets   );
InstIntFunc( "OnRight",      FunOnRight  );
InstIntFunc( "OnLeft",       FunOnLeft   );
InstIntFunc( "DepthVector",  FunDepthVector  );
}
/* 当前文件是D:\Read\pcpresen.c*/

TypHandle       FunPcp ( hdCall )
TypHandle       hdCall;
{
TypHandle       hdLst,  hdGrp,  hdN,  hdP,  hdStr,  hdCol,  hdSwrds;
long            p,  n,  i;
char            * usage = "usage: Pcp( <str>, <n>, <p>, <collector> )";
if ( SIZE( hdCall ) != 5 * SIZE_HD )
return Error( usage, 0L, 0L );
hdStr = EVAL( PTR( hdCall )[ 1 ] );
hdN   = EVAL( PTR( hdCall )[ 2 ] );
hdP   = EVAL( PTR( hdCall )[ 3 ] );
hdCol = EVAL( PTR( hdCall )[ 4 ] );
if (    TYPE( hdStr ) != T_STRING
|| TYPE( hdN   ) != T_INT
|| TYPE( hdP   ) != T_INT
|| TYPE( hdCol ) != T_STRING )
{
return Error( usage, 0L, 0L );
}
n = HD_TO_INT( hdN );
p = HD_TO_INT( hdP );
if ( n < 1 )
return Error( "Pcp: <n> must be positive", 0L, 0L );
if ( n > MAX_SWORD_NR )
return Error( "Pcp: <n> must be less then %d",
(long) MAX_SWORD_NR, 0L );
for ( i = 2;  i < p;  i++ )
if ( p % i == 0 )
return Error( "Pcp: <p> must be a prime", 0L, 0L );
hdGrp = BlankAgGroup();
HD_NUMBER_OF_GENS( hdGrp ) = INT_TO_HD( n );
hdLst = NewBag( T_AGEXP, SIZE_EXP * n );
HD_SAVE_EXPONENTS( hdGrp ) = hdLst;
hdLst = NewBag( T_AGEXP, SIZE_EXP * n );
HD_COLLECT_EXPONENTS( hdGrp ) = hdLst;
hdLst = NewBag( T_AGEXP, SIZE_EXP * n );
HD_COLLECT_EXPONENTS_2( hdGrp ) = hdLst;
ClearCollectExponents( hdGrp );
SetGeneratorsAgGroup( hdGrp );
hdLst = NewBag( T_LIST, ( n + 1 ) * SIZE_HD );
PTR( hdLst )[ 0 ] = INT_TO_HD( n );
HD_POWERS( hdGrp ) = hdLst;
for ( i = n;  i > 0;  i-- )
PTR( hdLst )[ i ] = HD_IDENTITY( hdGrp );
hdLst = NewBag( T_LIST, ( n * ( n - 1 ) / 2 + 1 ) * SIZE_HD );
PTR( hdLst )[ 0 ] = INT_TO_HD( n * ( n - 1 ) / 2 );
HD_COMMUTATORS( hdGrp ) = hdLst;
for ( i = n * ( n - 1 ) / 2;  i > 0;  i-- )
PTR( hdLst )[ i ] = HD_IDENTITY( hdGrp );
hdLst = NewBag( T_INTPOS, n * sizeof( long ) );
HD_INDICES( hdGrp ) = hdLst;
for ( i = n - 1;  i >= 0;  i-- )
INDICES( hdGrp )[ i ] = p;
for ( i = 0;  i <= COMBI_COLLECTOR;  i++ )
if ( ! SyStrcmp( Collectors[ i ].name, (char*) PTR( hdCol ) ) )
break;
if ( i > COMBI_COLLECTOR )
return Error("Pcp: unknown collector \"%s\"", (long)PTR(hdCol), 0L);
HD_COLLECTOR( hdGrp ) = INT_TO_HD( i );
if ( i == COMBI_COLLECTOR || i == COMBI2_COLLECTOR )
{
SetCWeightsAgGroup( hdGrp, HdVoid );
if ( p == 2 )
HD_COLLECTOR( hdGrp ) = INT_TO_HD( COMBI2_COLLECTOR );
else
HD_COLLECTOR( hdGrp ) = INT_TO_HD( COMBI_COLLECTOR );
}
else if ( i == LEE_COLLECTOR )
{
SetCWeightsAgGroup( hdGrp, HdVoid );
HD_COLLECTOR( hdGrp ) = INT_TO_HD( LEE_COLLECTOR );
}
else
return Error( "Pcp: not ready yet", 0L, 0L );
for ( i = n - 1;  i >= 0;  i-- )
Retype( GENERATORS( hdGrp )[ i ], T_SWORD );
Retype( HD_IDENTITY( hdGrp ), T_SWORD );
hdSwrds = Words( hdStr, n );
HD_WORDS( hdGrp ) = *PTR( PTR( hdSwrds )[ 1 ] );
SetStacksAgGroup( hdGrp );
Retype( hdGrp, T_AGGRP );
hdLst = NewBag( T_PCPRES, SIZE_HD );
PTR( hdLst )[ 0 ] = hdGrp;
return hdLst;
}
TypHandle       FunAgPcp ( hdCall )
TypHandle           hdCall;
{
TypHandle           hdP, hdTmp;

char                * usage = "usage: AgPcp( <P> )";
if ( SIZE( hdCall ) != 2 * SIZE_HD )
return Error( usage, 0L, 0L );
hdP = EVAL( PTR( hdCall )[ 1 ] );
if ( TYPE( hdP ) != T_PCPRES )
return Error( usage, 0L, 0L );
hdP = *PTR( hdP );
hdTmp = FactorAgGroup( hdP, NUMBER_OF_GENS( hdP ) );
return GapAgGroup( hdTmp );
}
TypHandle       FunGeneratorsPcp ( hdCall )
TypHandle       hdCall;
{
TypHandle       hdP;
char            * usage = "usage: GeneratorsPcp( <P> )";
if ( SIZE( hdCall ) != 2 * SIZE_HD )
return Error( usage, 0L, 0L );
hdP = EVAL( PTR( hdCall )[ 1 ] );
if ( TYPE( hdP ) != T_PCPRES )
return Error( usage, 0L, 0L );
return Copy( HD_GENERATORS( *PTR( hdP ) ) );
}
TypHandle       FunExtendCentralPcp ( hdCall )
TypHandle       hdCall;
{
TypHandle       * ptL,  hdL,  hdP,  hdN,  hdA,  hdI,  hdTmp;
long            i,  j,  old,  new,  len,  p;
char            * usage = "usage: ExtendCentralPcp( <P>, <L>, <p> )";
if ( SIZE( hdCall ) != 4 * SIZE_HD )
return Error( usage, 0L, 0L );
hdP = EVAL( PTR( hdCall )[ 1 ] );
hdL = EVAL( PTR( hdCall )[ 2 ] );
hdN = EVAL( PTR( hdCall )[ 3 ] );
if ( TYPE(hdP) != T_PCPRES || TYPE(hdL) != T_LIST || TYPE(hdN) != T_INT )
return Error( usage, 0L, 0L );
hdP = *PTR( hdP );
p   = HD_TO_INT( hdN );
old = NUMBER_OF_GENS( hdP );
len = LEN_LIST( hdL );
new = old + len;
hdL = Copy( hdL );
for ( i = len;  i > 0;  i-- )
{
hdTmp = ELM_PLIST( hdL, i );
if ( TYPE( hdTmp ) != T_STRING )
return Error( usage, 0L, 0L );
hdA = NewBag( T_AGEN, SIZE_HD + SIZE( hdTmp ) + 1 );
*(char*)( PTR( hdA ) + 1 ) = '\0';
SyStrncat( (char*)( PTR( hdA ) + 1 ), "+", 1 );
SyStrncat( (char*)( PTR( hdA ) + 1 ),
(char*)( PTR( hdTmp ) ),
SIZE( hdTmp ) - 1 );
hdI = NewBag( T_AGEN, SIZE_HD + SIZE( hdTmp ) + 1 );
*(char*)( PTR( hdI ) + 1 ) = '\0';
SyStrncat( (char*)( PTR( hdI ) + 1 ), "-", 1 );
SyStrncat( (char*)( PTR( hdI ) + 1 ),
(char*)( PTR( hdTmp ) ),
SIZE( hdTmp ) - 1 );
PTR( hdA )[ 0 ] = hdI;
PTR( hdI )[ 0 ] = hdA;
SET_ELM_PLIST( hdL, i, hdA );
}
switch ( COLLECTOR( hdP ) )
{
case LEE_COLLECTOR:
case COMBI_COLLECTOR:
case COMBI2_COLLECTOR:
if ( p != INDICES( hdP )[ 0 ] )
return Error( "can only extend with prime %d",
INDICES( hdP )[ 0 ], 0L );
break;
default:
return Error( "ExtendCentralPcp: not ready!", 0L, 0L );
}
HD_NUMBER_OF_GENS( hdP ) = INT_TO_HD( new );
SetGeneratorsAgGroup( hdP );
for ( i = new - 1;  i >= 0;  i-- )
Retype( GENERATORS( hdP )[ i ], T_SWORD );
Retype( HD_IDENTITY( hdP ), T_SWORD );
Resize( HD_SAVE_EXPONENTS( hdP ),      new * SIZE_EXP );
Resize( HD_COLLECT_EXPONENTS( hdP ),   new * SIZE_EXP );
Resize( HD_COLLECT_EXPONENTS_2( hdP ), new * SIZE_EXP );
Resize( HD_POWERS( hdP ), ( new + 1 ) * SIZE_HD );
ptL = POWERS( hdP );
ptL[ -1 ] = INT_TO_HD( new );
for ( i = old;  i < new;  i++ )
ptL[ i ] = HD_IDENTITY( hdP );
Resize( HD_COMMUTATORS( hdP ), ( new*(new-1)/2 + 1 ) * SIZE_HD );
ptL = COMMUTATORS( hdP );
ptL[ -1 ] = INT_TO_HD( new * ( new - 1 ) / 2 );
for ( i = old * (old-1) / 2;  i < new * (new-1) / 2;  i++ )
ptL[ i ] = HD_IDENTITY( hdP );
Resize( HD_INDICES( hdP ), new * sizeof( long ) );
for ( i = old;  i < new;  i++ )
INDICES( hdP )[ i ] = p;
Resize( HD_WORDS( hdP ), ( new + 1 ) * SIZE_HD );
ptL = WORDS( hdP );
ptL[ -1 ] = INT_TO_HD( new );
for ( i = old;  i < new;  i++ )
ptL[ i ] = ELM_PLIST( hdL, i + 1 - old );
switch ( COLLECTOR( hdP ) )
{
case LEE_COLLECTOR:
case COMBI_COLLECTOR:
case COMBI2_COLLECTOR:
Resize( HD_CWEIGHTS( hdP ), new * sizeof( long ) );
j = CWEIGHTS( hdP )[ old - 1 ] + 1;
for ( i = old;  i < new;  i++ )
CWEIGHTS( hdP )[ i ] = j;
len = SIZE( HD_CSERIES( hdP ) ) / sizeof( long );
Resize( HD_CSERIES( hdP ), ( len + 1 ) * sizeof( long ) );
CSERIES( hdP )[ len ] = new - 1;
CSERIES( hdP )[ 0 ] = CSERIES( hdP )[ 0 ] + 1;
break;
default:
return Error( "ExtendCentralPcp: not ready!", 0L, 0L );
}
return HdVoid;
}
TypHandle       FunCentralWeightsPcp ( hdCall )
TypHandle       hdCall;
{
TypHandle       hdVec,  hdP;
TypHandle       * ptVec;
long            i,  n,  * ptWgt;
char            * usage = "usage: CentralWeightsPcp( <P> )";
if ( SIZE( hdCall ) != 2 * SIZE_HD )
return Error( usage, 0L, 0L );
hdP = EVAL( PTR( hdCall )[ 1 ] );
if ( TYPE( hdP ) != T_PCPRES )
return Error( usage, 0L, 0L );
hdP = *PTR( hdP );
switch( COLLECTOR( hdP ) )
{
case LEE_COLLECTOR:
case COMBI_COLLECTOR:
case COMBI2_COLLECTOR:
break;
default:
return Error( "combinatorial collector not installed", 0L, 0L );
}
n = NUMBER_OF_GENS( hdP );
hdVec = NewBag( T_LIST, ( n + 1 ) * SIZE_HD );
ptVec = PTR( hdVec ) + 1;
ptVec[ -1 ] = INT_TO_HD( n );
ptWgt = CWEIGHTS( hdP );
for ( i = n - 1;  i >= 0;  i-- )
ptVec[ i ] = INT_TO_HD( ptWgt[ i ] );
return hdVec;
}
TypHandle       FunDefineCentralWeightsPcp ( hdCall )
TypHandle       hdCall;
{
TypHandle       hdVec,  hdP;
TypHandle       * ptVec;
long            i,  n;
char            * usage = "DefineCentralWeightsPcp( <P>, <W> )";
if ( SIZE( hdCall ) != 3 * SIZE_HD )
return Error( usage, 0L, 0L );
hdP   = EVAL( PTR( hdCall )[ 1 ] );
hdVec = EVAL( PTR( hdCall )[ 2 ] );
if ( TYPE( hdP ) != T_PCPRES || ! IsList( hdVec ) )
return Error( usage, 0L, 0L );
hdP = *PTR( hdP );
switch( COLLECTOR( hdP ) )
{
case LEE_COLLECTOR:
case COMBI_COLLECTOR:
case COMBI2_COLLECTOR:
break;
default:
return Error( "combinatorial collector not installed", 0L, 0L );
}
n = NUMBER_OF_GENS( hdP );
if ( LEN_LIST( hdVec ) > n )
return Error( "presentation has only %d generators", n, 0L );
ptVec = PTR( hdVec ) + 1;
for ( i = LEN_LIST( hdVec ) - 1;  i >= 0;  i-- )
if ( TYPE( ptVec[ i ] ) != T_INT )
return Error( usage, 0L, 0L );
if ( LEN_LIST( hdVec ) != n )
{
hdVec = Copy( hdVec );
i = LEN_LIST( hdVec ) + 1;
Resize( hdVec, ( n + 1 ) * SIZE_HD );
PTR( hdVec )[ 0 ] = INT_TO_HD( n );
ptVec = PTR( hdVec );
if ( i == 1 )
{
ptVec[ i++ ] = INT_TO_HD( 1 );
}
for ( ;  i <= n;  i++ )
ptVec[ i ] = ptVec[ i - 1 ];
}
SetCWeightsAgGroup( hdP, hdVec );
return HdVoid;
}
TypHandle       FunDefineCommPcp ( hdCall )
TypHandle       hdCall;
{
TypHandle       hdW,  hdP,  hdI,  hdJ;
long            len,  i,  j,  * ptWgt;
char            * usage = "DefineCommPcp( <P>, <i>, <j>, <w> )";
if ( SIZE( hdCall ) != 5 * SIZE_HD )
return Error( usage, 0L, 0L );
hdP = EVAL( PTR( hdCall )[ 1 ] );
hdI = EVAL( PTR( hdCall )[ 2 ] );
hdJ = EVAL( PTR( hdCall )[ 3 ] );
hdW = EVAL( PTR( hdCall )[ 4 ] );
if ( TYPE(hdP) != T_PCPRES || TYPE(hdI) != T_INT || TYPE(hdJ) != T_INT )
return Error( usage, 0L, 0L );
hdP = *PTR( hdP );
len = NUMBER_OF_GENS( hdP );
i   = HD_TO_INT( hdI ) - 1;
j   = HD_TO_INT( hdJ ) - 1;
if ( i < 0 || j < 0 )
return Error( "generator number must be positive", 0L, 0L );
if ( i >= len || j >= len )
return Error( "presenation has only %d generators", len, 0L );
if ( i <= j )
return Error( "<i> must be greater than <j>", 0L, 0L );
switch( COLLECTOR( hdP ) )
{
case LEE_COLLECTOR:
case COMBI_COLLECTOR:
case COMBI2_COLLECTOR:
break;
default:
return Error( "combinatorial collector not installed", 0L, 0L );
}
if ( TYPE( hdW ) != T_SWORD && TYPE( hdW ) != T_WORD )
return Error( usage, 0L, 0L );
if ( ! IsNormedPcp( hdP, &hdW ) )
return Error( "<w> must be a normed word of <P>", 0L, 0L );
if ( ISID_AW( hdW ) )
COMMUTATORS( hdP )[ IND( i, j ) ] = HD_IDENTITY( hdP );
else
{
ptWgt = CWEIGHTS( hdP );
if ( ptWgt[ i ] + ptWgt[ j ] > ptWgt[ PTR_AW( hdW )[ 0 ] ] )
return Error( "central weights do not add", 0L, 0L );
COMMUTATORS( hdP )[ IND( i, j ) ] = hdW;
}
return HdVoid;
}
TypHandle       FunAddCommPcp ( hdCall )
TypHandle       hdCall;
{
TypHandle       hdW,  hdP,  hdI,  hdJ;
long            len,  i,  j,  * ptWgt;
char            * usage = "AddCommPcp( <P>, <i>, <j>, <w> )";
if ( SIZE( hdCall ) != 5 * SIZE_HD )
return Error( usage, 0L, 0L );
hdP = EVAL( PTR( hdCall )[ 1 ] );
hdI = EVAL( PTR( hdCall )[ 2 ] );
hdJ = EVAL( PTR( hdCall )[ 3 ] );
hdW = EVAL( PTR( hdCall )[ 4 ] );
if ( TYPE(hdP) != T_PCPRES || TYPE(hdI) != T_INT || TYPE(hdJ) != T_INT )
return Error( usage, 0L, 0L );
hdP = *PTR( hdP );
len = NUMBER_OF_GENS( hdP );
i   = HD_TO_INT( hdI ) - 1;
j   = HD_TO_INT( hdJ ) - 1;
if ( i < 0 || j < 0 )
return Error( "generator number must be positive", 0L, 0L );
if ( i >= len || j >= len )
return Error( "presenation has only %d generators", len, 0L );
if ( i <= j )
return Error( "<i> must be greater than <j>", 0L, 0L );
switch( COLLECTOR( hdP ) )
{
case LEE_COLLECTOR:
case COMBI_COLLECTOR:
case COMBI2_COLLECTOR:
break;
default:
return Error( "combinatorial collector not installed", 0L, 0L );
}
if ( TYPE( hdW ) != T_SWORD && TYPE( hdW ) != T_WORD )
return Error( usage, 0L, 0L );
if ( ! IsNormedPcp( hdP, &hdW ) )
return Error( "<w> must be a normed word of <P>", 0L, 0L );
if ( ! ISID_AW( hdW ) )
{
hdW   = SumAgWord( hdP, hdW, COMMUTATORS( hdP )[ IND( i, j ) ] );
ptWgt = CWEIGHTS( hdP );
if ( ptWgt[ i ] + ptWgt[ j ] > ptWgt[ PTR_AW( hdW )[ 0 ] ] )
return Error( "central weights do not add", 0L, 0L );
COMMUTATORS( hdP )[ IND( i, j ) ] = hdW;
Retype( hdW, T_SWORD );
}
return HdVoid;
}
TypHandle       FunSubtractCommPcp ( hdCall )
TypHandle       hdCall;
{
TypHandle       hdW,  hdP,  hdI,  hdJ;
long            len,  i,  j,  * ptWgt;
char            * usage = "SubtractCommPcp( <P>, <i>, <j>, <w> )";
if ( SIZE( hdCall ) != 5 * SIZE_HD )
return Error( usage, 0L, 0L );
hdP = EVAL( PTR( hdCall )[ 1 ] );
hdI = EVAL( PTR( hdCall )[ 2 ] );
hdJ = EVAL( PTR( hdCall )[ 3 ] );
hdW = EVAL( PTR( hdCall )[ 4 ] );
if ( TYPE(hdP) != T_PCPRES || TYPE(hdI) != T_INT || TYPE(hdJ) != T_INT )
return Error( usage, 0L, 0L );
hdP = *PTR( hdP );
len = NUMBER_OF_GENS( hdP );
i   = HD_TO_INT( hdI ) - 1;
j   = HD_TO_INT( hdJ ) - 1;
if ( i < 0 || j < 0 )
return Error( "generator number must be positive", 0L, 0L );
if ( i >= len || j >= len )
return Error( "presenation has only %d generators", len, 0L );
if ( i <= j )
return Error( "<i> must be greater than <j>", 0L, 0L );
switch( COLLECTOR( hdP ) )
{
case LEE_COLLECTOR:
case COMBI_COLLECTOR:
case COMBI2_COLLECTOR:
break;
default:
return Error( "combinatorial collector not installed", 0L, 0L );
}
if ( TYPE( hdW ) != T_SWORD && TYPE( hdW ) != T_WORD )
return Error( usage, 0L, 0L );
if ( ! IsNormedPcp( hdP, &hdW ) )
return Error( "<w> must be a normed word of <P>", 0L, 0L );
if ( ! ISID_AW( hdW ) )
{
hdW   = DifferenceAgWord( hdP, COMMUTATORS( hdP )[ IND(i,j) ], hdW );
ptWgt = CWEIGHTS( hdP );
if ( ptWgt[ i ] + ptWgt[ j ] > ptWgt[ PTR_AW( hdW )[ 0 ] ] )
return Error( "central weights do not add", 0L, 0L );
COMMUTATORS( hdP )[ IND( i, j ) ] = hdW;
Retype( hdW, T_SWORD );
}
return HdVoid;
}
TypHandle       FunDefinePowerPcp ( hdCall )
TypHandle       hdCall;
{
TypHandle       hdW,  hdP,  hdI;
long            len,  i,  * ptWgt;
char            * usage = "DefinePowerPcp( <P>, <i>, <w> )";
if ( SIZE( hdCall ) != 4 * SIZE_HD )
return Error( usage, 0L, 0L );
hdP = EVAL( PTR( hdCall )[ 1 ] );
hdI = EVAL( PTR( hdCall )[ 2 ] );
hdW = EVAL( PTR( hdCall )[ 3 ] );
if ( TYPE( hdP ) != T_PCPRES || TYPE( hdI ) != T_INT )
return Error( usage, 0L, 0L );
hdP = *PTR( hdP );
len = NUMBER_OF_GENS( hdP );
i   = HD_TO_INT( hdI ) - 1;
if ( i < 0 )
return Error( "generator number must be positive", 0L, 0L );
if ( i >= len )
return Error( "presenation has only %d generators", len, 0L );
if ( TYPE( hdW ) != T_SWORD && TYPE( hdW ) != T_WORD )
return Error( usage, 0L, 0L );
if ( ! IsNormedPcp( hdP, &hdW ) )
return Error( "<w> must be a normed word of <P>", 0L, 0L );
if ( ISID_AW( hdW ) )
POWERS( hdP )[ i ] = HD_IDENTITY( hdP );
else
{
switch( COLLECTOR( hdP ) )
{
case LEE_COLLECTOR:
case COMBI_COLLECTOR:
case COMBI2_COLLECTOR:
ptWgt = CWEIGHTS( hdP );
if ( ptWgt[ i ] >= ptWgt[ PTR_AW( hdW )[ 0 ] ] )
return Error( "central weight does not grow", 0L, 0L );
break;
case SINGLE_COLLECTOR:
if ( i >= PTR_AW( hdW )[ 0 ] )
return Error( "depth does not grow", 0L, 0L );
break;
}
POWERS( hdP )[ i ] = hdW;
}
return HdVoid;
}
TypHandle       FunAddPowerPcp ( hdCall )
TypHandle       hdCall;
{
TypHandle       hdW,  hdP,  hdI;
long            len,  i,  * ptWgt;
char            * usage = "AddPowerPcp( <P>, <i>, <w> )";
if ( SIZE( hdCall ) != 4 * SIZE_HD )
return Error( usage, 0L, 0L );
hdP = EVAL( PTR( hdCall )[ 1 ] );
hdI = EVAL( PTR( hdCall )[ 2 ] );
hdW = EVAL( PTR( hdCall )[ 3 ] );
if ( TYPE( hdP ) != T_PCPRES || TYPE( hdI ) != T_INT )
return Error( usage, 0L, 0L );
hdP = *PTR( hdP );
len = NUMBER_OF_GENS( hdP );
i   = HD_TO_INT( hdI ) - 1;
if ( i < 0 )
return Error( "generator number must be positive", 0L, 0L );
if ( i >= len )
return Error( "presenation has only %d generators", len, 0L );
if ( TYPE( hdW ) != T_SWORD && TYPE( hdW ) != T_WORD )
return Error( usage, 0L, 0L );
if ( ! IsNormedPcp( hdP, &hdW ) )
return Error( "<w> must be a normed word of <P>", 0L, 0L );
if ( ! ISID_AW( hdW ) )
{
hdW = SumAgWord( hdP, hdW, POWERS( hdP )[ i ] );
switch( COLLECTOR( hdP ) )
{
case LEE_COLLECTOR:
case COMBI_COLLECTOR:
case COMBI2_COLLECTOR:
ptWgt = CWEIGHTS( hdP );
if ( ptWgt[ i ] >= ptWgt[ PTR_AW( hdW )[ 0 ] ] )
return Error( "central weight does not grow", 0L, 0L );
break;
case SINGLE_COLLECTOR:
if ( i >= PTR_AW( hdW )[ 0 ] )
return Error( "depth does not grow", 0L, 0L );
break;
}
Retype( hdW, T_SWORD );
POWERS( hdP )[ i ] = hdW;
}
return HdVoid;
}
TypHandle       FunSubtractPowerPcp ( hdCall )
TypHandle       hdCall;
{
TypHandle       hdW,  hdP,  hdI;
long            len,  i,  * ptWgt;
char            * usage = "SubtractPowerPcp( <P>, <i>, <w> )";
if ( SIZE( hdCall ) != 4 * SIZE_HD )
return Error( usage, 0L, 0L );
hdP = EVAL( PTR( hdCall )[ 1 ] );
hdI = EVAL( PTR( hdCall )[ 2 ] );
hdW = EVAL( PTR( hdCall )[ 3 ] );
if ( TYPE( hdP ) != T_PCPRES || TYPE( hdI ) != T_INT )
return Error( usage, 0L, 0L );
hdP = *PTR( hdP );
len = NUMBER_OF_GENS( hdP );
i   = HD_TO_INT( hdI ) - 1;
if ( i < 0 )
return Error( "generator number must be positive", 0L, 0L );
if ( i >= len )
return Error( "presenation has only %d generators", len, 0L );
if ( TYPE( hdW ) != T_SWORD && TYPE( hdW ) != T_WORD )
return Error( usage, 0L, 0L );
if ( ! IsNormedPcp( hdP, &hdW ) )
return Error( "<w> must be a normed word of <P>", 0L, 0L );
if ( ! ISID_AW( hdW ) )
{
hdW = DifferenceAgWord( hdP, POWERS( hdP )[ i ], hdW );
switch( COLLECTOR( hdP ) )
{
case LEE_COLLECTOR:
case COMBI_COLLECTOR:
case COMBI2_COLLECTOR:
ptWgt = CWEIGHTS( hdP );
if ( ptWgt[ i ] >= ptWgt[ PTR_AW( hdW )[ 0 ] ] )
return Error( "central weight does not grow", 0L, 0L );
break;
case SINGLE_COLLECTOR:
if ( i >= PTR_AW( hdW )[ 0 ] )
return Error( "depth does not grow", 0L, 0L );
break;
}
Retype( hdW, T_SWORD );
POWERS( hdP )[ i ] = hdW;
}
return HdVoid;
}
void            ShrinkSwords( hdP, hdL, hdM )
TypHandle       hdP;
TypHandle       hdL;
TypHandle       hdM;
{
TypHandle       hdG,  hdT;
TypSword        * ptG,  * ptH;
long            i,  j,  new,  * ptM;
for ( i = LEN_LIST( hdL );  i > 0;  i-- )
{
ptM = (long*) PTR( hdM );
hdG = ELM_PLIST( hdL, i );
ptG = PTR_AW( hdG );
if ( *ptG == -1 )
{
SET_ELM_PLIST( hdL, i, HD_IDENTITY( hdP ) );
continue;
}
new = 0;
while ( *ptG != -1 )
{
if ( ptM[ ptG[0] ] != -1 )
new++;
ptG += 2;
}
hdT = NewBag( T_SWORD, SIZE_HD + ( 2 * new + 1 ) * SIZE_SWORD );
*PTR( hdT ) = hdP;
SET_ELM_PLIST( hdL, i, hdT );
ptH = PTR_AW( hdT );
ptG = PTR_AW( hdG );
ptM = (long*) PTR( hdM );
while ( *ptG != -1 )
{
j = ptM[ ptG[0] ];
if ( j != -1 )
{
ptH[0] = j;
ptH[1] = ptG[1];
ptH   += 2;
}
ptG += 2;
}
ptH[0] = -1;
}
}
TypHandle       FunShrinkPcp ( hdCall )
TypHandle       hdCall;
{
TypHandle       hdP,  hdC,  hdL,  hdT,  hdG;
TypHandle       * ptT,  * ptG,  * ptC;
long            * piT,  * piG,  * ptL;
long            i,  j,  i0,  j0,  new,  old,  len;
char            * usage = "usage: ShrinkPcp( <P>, <L> )";
if ( SIZE( hdCall ) != 3 * SIZE_HD )
return Error( usage, 0L, 0L );
hdP = EVAL( PTR( hdCall )[ 1 ] );
hdC = EVAL( PTR( hdCall )[ 2 ] );
if ( TYPE( hdP ) != T_PCPRES || ! IsVector( hdC ) )
return Error( usage, 0L, 0L );
if ( LEN_LIST( hdC ) == 0 )
return HdVoid;
i = COLLECTOR( *PTR( hdP ) );
if (i != COMBI2_COLLECTOR && i != COMBI_COLLECTOR && i != LEE_COLLECTOR)
return Error( "ShrinkPcp: not ready!", 0L, 0L );
len = LEN_LIST( hdC );
old = NUMBER_OF_GENS( *PTR( hdP ) );
hdL = NewBag( T_STRING, old * sizeof( long ) );
ptC = PTR( hdC ) + 1;
ptL = (long*) PTR( hdL );
if ( old <= len )
return Error( "cannot delete every generators of <P>", 0L, 0L );
for ( i = 0;  i < len;  i++ )
{
j = HD_TO_INT( ptC[ i ] ) - 1;
if ( TYPE( ptC[ i ] ) != T_INT || 0 > j || j >= old )
return Error( "illegal generator number %d", j + 1, 0L );
if ( ptL[ j ] != 0 )
return Error( "duplicate generator number %d", j, 0L );
ptL[ j ] = -1;
}
for ( i = 0, j = 0;  i < old;  i++ )
{
if ( ptL[ i ] == 0 )
ptL[ i ] = j++;
}
hdG = *PTR( hdP );
hdT = NewBag( T_AGGRP, SIZE( hdG ) );
ptG = PTR( hdG );
ptT = PTR( hdT );
for ( i = SIZE( hdG ) / SIZE_HD - 1;  i >= 0;  i-- )
*ptT++ = *ptG++;
*PTR( hdP ) = hdT;
Resize( hdG, SIZE( HD_WORDS( hdT ) ) );
Retype( hdG, TYPE( HD_WORDS( hdT ) ) );
ptG = PTR( hdG );
ptT = PTR( HD_WORDS( hdT ) );
for ( i = SIZE( hdG ) / SIZE_HD - 1;  i >= 0;  i-- )
*ptG++ = *ptT++;
hdP = hdT;
new = old - len;
HD_NUMBER_OF_GENS( hdP ) = INT_TO_HD( new );
SetGeneratorsAgGroup( hdP );
for ( i = new - 1;  i >= 0;  i-- )
Retype( GENERATORS( hdP )[ i ], T_SWORD );
Retype( HD_IDENTITY( hdP ), T_SWORD );
hdT = NewBag( T_LIST, ( new + 1 ) * SIZE_HD );
ptT = PTR( hdT ) + 1;
ptG = WORDS( hdP );
ptL = (long*) PTR( hdL );
ptT[ -1 ] = INT_TO_HD( new );
for ( i = old - 1;  i >= 0;  i-- )
{
j = ptL[ i ];
if ( j != -1 )
ptT[ j ] = ptG[ i ];
}
HD_WORDS( hdP ) = hdT;
hdT = NewBag( T_INTPOS, new * sizeof( long ) );
piT = (long*) PTR( hdT );
piG = INDICES( hdP );
ptL = (long*) PTR( hdL );
for ( i = old - 1;  i >= 0;  i-- )
{
j = ptL[ i ];
if ( j != -1 )
piT[ j ] = piG[ i ];
}
HD_INDICES( hdP ) = hdT;
ptT = POWERS( hdP );
ptG = POWERS( hdP );
ptL = (long*) PTR( hdL );
ptT[ -1 ] = INT_TO_HD( new );
for ( i = 0;  i < old;  i++ )
{
j = ptL[ i ];
if ( j != -1 )
ptT[ j ] = ptG[ i ];
}
Resize( HD_POWERS( hdP ), ( new + 1 ) * SIZE_HD );
ptT = COMMUTATORS( hdP );
ptG = COMMUTATORS( hdP );
ptL = (long*) PTR( hdL );
ptT[ -1 ] = INT_TO_HD( new * ( new - 1 ) / 2 );
for ( i = 1;  i < old;  i++ )
{
i0 = ptL[ i ];
if ( i0 != -1 )
{
for ( j = 0;  j < i;  j++ )
{
j0 = ptL[ j ];
if ( j0 != -1 )
ptT[ IND( i0, j0 ) ] = ptG[ IND( i, j ) ];
}
}
}
Resize( HD_COMMUTATORS( hdP ), ( new * (new - 1) / 2 + 1 ) * SIZE_HD );
ShrinkSwords( hdP, HD_POWERS( hdP ),      hdL );
ShrinkSwords( hdP, HD_COMMUTATORS( hdP ), hdL );
Resize( HD_SAVE_EXPONENTS( hdP ),      new * SIZE_EXP );
Resize( HD_COLLECT_EXPONENTS( hdP ),   new * SIZE_EXP );
Resize( HD_COLLECT_EXPONENTS_2( hdP ), new * SIZE_EXP );
switch ( COLLECTOR( hdP ) )
{
case LEE_COLLECTOR:
case COMBI_COLLECTOR:
case COMBI2_COLLECTOR:
hdT = NewBag( T_INTPOS, new * sizeof( long ) );
piT = (long*) PTR( hdT );
piG = CWEIGHTS( hdP );
ptL = (long*) PTR( hdL );
for ( i = old - 1;  i >= 0;  i-- )
{
j = ptL[ i ];
if ( j != -1 )
piT[ j ] = piG[ i ];
}
HD_CWEIGHTS( hdP ) = hdT;
hdT = NewBag( T_INTPOS, ( new + 1 ) * sizeof( long ) );
piT = (long*) PTR( hdT );
piG = CWEIGHTS( hdP );
piT[ 0 ] = 1;
for ( i = 0;  i < new;  i++ )
{
if ( piG[ i ] > piT[ 0 ] )
{
piT[ piT[ 0 ] ] = i - 1;
piT[ 0 ]++;
}
}
piT[ piT[ 0 ] ] = i - 1;
Resize( hdT, ( piT[ 0 ] + 1 ) * sizeof( long ) );
HD_CSERIES( hdP ) = hdT;
break;
default:
return Error( "ShrinkPcp: not ready!", 0L, 0L );
}
return HdVoid;
}
TypHandle       FunTriangleIndex( hdCall )
TypHandle       hdCall;
{
TypHandle       hdI, hdJ;
long            i,   j;
char            * usage = "usage: TriangleIndex( <i>, <j> )";
if ( SIZE( hdCall ) != 3 * SIZE_HD )
return Error( usage, 0L, 0L );
hdI = EVAL( PTR( hdCall )[ 1 ] );
hdJ = EVAL( PTR( hdCall )[ 2 ] );
if ( TYPE( hdI ) != T_INT || TYPE( hdJ ) != T_INT )
return Error( usage, 0L, 0L );
i = HD_TO_INT( hdI );
j = HD_TO_INT( hdJ );
return INT_TO_HD( ( i - 1 ) * ( i - 2 ) / 2 + j );
}
TypHandle   NormalWordPcp ( hdP, hdG )
TypHandle           hdP;
TypHandle           hdG;
{
TypHandle           hdQ,  hdR;
TypHandle           * ptW;
TypSword            * ptG;
long                i;
if ( TYPE( hdG ) == T_SWORD )
{
hdQ = *PTR( hdG );
if ( hdQ == hdP )
return hdG;
if ( TYPE( hdQ ) == T_AGGRP )
hdQ = HD_WORDS( hdQ );
hdG = SwordSword( HD_WORDS( hdP ), hdG );
}
else if ( hdG == HdIdWord )
return HD_IDENTITY( hdP );
else
hdG = SwordWord( HD_WORDS( hdP ), hdG );
if ( hdG == HdFalse )
return hdG;
ptW = GENERATORS( hdP );
ptG = PTR_AW( hdG );
hdR = HD_IDENTITY( hdP );
i = 0;
while ( *ptG != -1 )
{
hdR = ProdAg( hdR, PowAgI( ptW[ ptG[0] ], INT_TO_HD( ptG[1] ) ) );
i  += 2;
ptG = &( PTR_AW( hdG )[ i ] );
ptW = GENERATORS( hdP );
}
Retype( hdR, T_SWORD );
return hdR;
}
TypHandle       FunNormalWordPcp ( hdCall )
TypHandle       hdCall;
{
TypHandle       hdG,  hdP;
char            * usage = "NormalWordPcp( <P>, <g> )";
if ( SIZE( hdCall ) != 3 * SIZE_HD )
return Error( usage, 0L, 0L );
hdP = EVAL( PTR( hdCall )[ 1 ] );
hdG = EVAL( PTR( hdCall )[ 2 ] );
if ( TYPE(hdP)!=T_PCPRES || (TYPE(hdG)!=T_WORD && TYPE(hdG)!=T_SWORD) )
return Error( usage, 0L, 0L );
hdP = *PTR( hdP );
hdG = NormalWordPcp( hdP, hdG );
if ( hdG == HdFalse )
return Error( "<g> must be an element of <P>", 0L, 0L );
return hdG;
}
TypHandle       FunProductPcp ( hdCall )
TypHandle           hdCall;
{
TypHandle           hdP,  hdA,  hdB,  hdR;
long                len,  a,  b;
char                * usage = "usage: ProductPcp( <P>, <a>, <b> )";
if ( SIZE( hdCall ) != 4 * SIZE_HD )
return Error( usage, 0L, 0L );
hdP = EVAL( PTR( hdCall )[ 1 ] );
if ( TYPE( hdP ) != T_PCPRES )
return Error( usage, 0L, 0L );
hdP = *PTR( hdP );
hdA = EVAL( PTR( hdCall )[ 2 ] );
hdB = EVAL( PTR( hdCall )[ 3 ] );
len = NUMBER_OF_GENS( hdP );
if ( TYPE( hdA ) == T_INT )
{
a = HD_TO_INT( hdA ) - 1;
if ( a < 0 )
return Error( "generator number must be positive", 0L, 0L );
if ( a >= len )
return Error("presentation has only %d generators", len, 0L);
hdA = GENERATORS( hdP )[ a ];
}
else if ( TYPE( hdA ) == T_WORD || TYPE( hdA ) == T_SWORD )
{
hdA = NormalWordPcp( hdP, hdA );
if ( hdA == HdFalse )
return Error( "<a> must be a word of <P>", 0L, 0L );
}
else
return Error( usage, 0L, 0L );
if ( TYPE( hdB ) == T_INT )
{
b = HD_TO_INT( hdB ) - 1;
if ( b < 0 )
return Error( "generator number must be positive", 0L, 0L );
if ( b >= len )
return Error("presentation has only %d generators", len, 0L);
hdB = GENERATORS( hdP )[ b ];
}
else if ( TYPE( hdB ) == T_WORD || TYPE( hdB ) == T_SWORD )
{
hdB = NormalWordPcp( hdP, hdB );
if ( hdB == HdFalse )
return Error( "<b> must be a word of <P>", 0L, 0L );
}
else
return Error( usage, 0L, 0L );
hdR = ProdAg( hdA, hdB );
Retype( hdR, T_SWORD );
return hdR;
}
TypHandle       FunLeftQuotientPcp ( hdCall )
TypHandle           hdCall;
{
TypHandle           hdP,  hdA,  hdB,  hdR;
long                len,  a,  b;
char                * usage = "usage: LeftQuotientPcp( <P>, <a>, <b> )";
if ( SIZE( hdCall ) != 4 * SIZE_HD )
return Error( usage, 0L, 0L );
hdP = EVAL( PTR( hdCall )[ 1 ] );
if ( TYPE( hdP ) != T_PCPRES )
return Error( usage, 0L, 0L );
hdP = *PTR( hdP );
hdA = EVAL( PTR( hdCall )[ 2 ] );
hdB = EVAL( PTR( hdCall )[ 3 ] );
len = NUMBER_OF_GENS( hdP );
if ( TYPE( hdA ) == T_INT )
{
a = HD_TO_INT( hdA ) - 1;
if ( a < 0 )
return Error( "generator number must be positive", 0L, 0L );
if ( a >= len )
return Error("presentation has only %d generators", len, 0L);
hdA = GENERATORS( hdP )[ a ];
}
else if ( TYPE( hdA ) == T_WORD || TYPE( hdA ) == T_SWORD )
{
hdA = NormalWordPcp( hdP, hdA );
if ( hdA == HdFalse )
return Error( "<a> must be a word of <P>", 0L, 0L );
}
else
return Error( usage, 0L, 0L );
if ( TYPE( hdB ) == T_INT )
{
b = HD_TO_INT( hdB ) - 1;
if ( b < 0 )
return Error( "generator number must be positive", 0L, 0L );
if ( b >= len )
return Error("presentation has only %d generators", len, 0L);
hdB = GENERATORS( hdP )[ b ];
}
else if ( TYPE( hdB ) == T_WORD || TYPE( hdB ) == T_SWORD )
{
hdB = NormalWordPcp( hdP, hdB );
if ( hdB == HdFalse )
return Error( "<b> must be a word of <P>", 0L, 0L );
}
else
return Error( usage, 0L, 0L );
hdR = ModAg( hdA, hdB );
Retype( hdR, T_SWORD );
return hdR;
}
TypHandle       FunQuotientPcp ( hdCall )
TypHandle           hdCall;
{
TypHandle           hdP,  hdA,  hdB,  hdR;
long                len,  a,  b;
char                * usage = "usage: QuotientPcp( <P>, <a>, <b> )";
if ( SIZE( hdCall ) != 4 * SIZE_HD )
return Error( usage, 0L, 0L );
hdP = EVAL( PTR( hdCall )[ 1 ] );
if ( TYPE( hdP ) != T_PCPRES )
return Error( usage, 0L, 0L );
hdP = *PTR( hdP );
hdA = EVAL( PTR( hdCall )[ 2 ] );
hdB = EVAL( PTR( hdCall )[ 3 ] );
len = NUMBER_OF_GENS( hdP );
if ( TYPE( hdA ) == T_INT )
{
a = HD_TO_INT( hdA ) - 1;
if ( a < 0 )
return Error( "generator number must be positive", 0L, 0L );
if ( a >= len )
return Error("presentation has only %d generators", len, 0L);
hdA = GENERATORS( hdP )[ a ];
}
else if ( TYPE( hdA ) == T_WORD || TYPE( hdA ) == T_SWORD )
{
hdA = NormalWordPcp( hdP, hdA );
if ( hdA == HdFalse )
return Error( "<a> must be a word of <P>", 0L, 0L );
}
else
return Error( usage, 0L, 0L );
if ( TYPE( hdB ) == T_INT )
{
b = HD_TO_INT( hdB ) - 1;
if ( b < 0 )
return Error( "generator number must be positive", 0L, 0L );
if ( b >= len )
return Error("presentation has only %d generators", len, 0L);
hdB = GENERATORS( hdP )[ b ];
}
else if ( TYPE( hdB ) == T_WORD || TYPE( hdB ) == T_SWORD )
{
hdB = NormalWordPcp( hdP, hdB );
if ( hdB == HdFalse )
return Error( "<b> must be a word of <P>", 0L, 0L );
}
else
return Error( usage, 0L, 0L );
hdR = QuoAg( hdA, hdB );
Retype( hdR, T_SWORD );
return hdR;
}
TypHandle       FunCommPcp ( hdCall )
TypHandle           hdCall;
{
TypHandle           hdP,  hdA,  hdB,  hdR;
long                col,  a,  b,  nrA,  nrB,  len;
char                * usage = "usage: CommPcp( <P>, <a>, <b> )";
if ( SIZE( hdCall ) != 4 * SIZE_HD )
return Error( usage, 0L, 0L );
hdP = EVAL( PTR( hdCall )[ 1 ] );
if ( TYPE( hdP ) != T_PCPRES )
return Error( usage, 0L, 0L );
hdP = *PTR( hdP );
hdA = EVAL( PTR( hdCall )[ 2 ] );
hdB = EVAL( PTR( hdCall )[ 3 ] );
col = COLLECTOR( hdP );
len = NUMBER_OF_GENS( hdP );
if ( col==COMBI_COLLECTOR || col==COMBI2_COLLECTOR || col==LEE_COLLECTOR)
{
if ( TYPE( hdA ) == T_INT && TYPE( hdB ) == T_INT )
{
a = HD_TO_INT( hdA ) - 1;
b = HD_TO_INT( hdB ) - 1;
if ( a < 0 || b < 0 )
return Error( "generator number must be positive", 0L, 0L );
if ( a >= len || b >= len )
return Error("presentation has only %d generators", len, 0L);
if ( a == b )
return HD_IDENTITY( hdP );
else if ( a > b )
return COMMUTATORS( hdP )[ IND( a, b ) ];
else
{
hdR = COMMUTATORS( hdP )[ IND( b, a ) ];
hdR = PowAgI( hdR, INT_TO_HD( -1 ) );
Retype( hdR, T_SWORD );
return hdR;
}
}
}
if ( TYPE( hdA ) == T_INT )
{
a = HD_TO_INT( hdA ) - 1;
if ( a < 0 )
return Error( "generator number must be positive", 0L, 0L );
if ( a >= len )
return Error("presentation has only %d generators", len, 0L);
hdA = GENERATORS( hdP )[ a ];
}
else if ( TYPE( hdA ) == T_WORD || TYPE( hdA ) == T_SWORD )
{
hdA = NormalWordPcp( hdP, hdA );
if ( hdA == HdFalse )
return Error( "<a> must be a word of <P>", 0L, 0L );
}
else
return Error( usage, 0L, 0L );
if ( TYPE( hdB ) == T_INT )
{
b = HD_TO_INT( hdB ) - 1;
if ( b < 0 )
return Error( "generator number must be positive", 0L, 0L );
if ( b >= len )
return Error("presentation has only %d generators", len, 0L);
hdB = GENERATORS( hdP )[ b ];
}
else if ( TYPE( hdB ) == T_WORD || TYPE( hdB ) == T_SWORD )
{
hdB = NormalWordPcp( hdP, hdB );
if ( hdB == HdFalse )
return Error( "<b> must be a word of <P>", 0L, 0L );
}
else
return Error( usage, 0L, 0L );
nrA = LEN_AW( hdA );
if ( nrA == 0 )
return HD_IDENTITY( hdP );
nrB = LEN_AW( hdB );
if ( nrB == 0 )
return HD_IDENTITY( hdP );
if (  (    col == COMBI_COLLECTOR
|| col == COMBI2_COLLECTOR
|| col == LEE_COLLECTOR )
&& nrA == 1
&& nrB == 1
&& PTR_AW( hdA )[ 1 ] == 1
&& PTR_AW( hdB )[ 1 ] == 1 )
{
a = PTR_AW( hdA )[ 0 ];
b = PTR_AW( hdB )[ 0 ];
if ( a == b )
return HD_IDENTITY( hdP );
if ( a > b )
return COMMUTATORS( hdP )[ IND( a, b ) ];
else
{
hdR = COMMUTATORS( hdP )[ IND( b, a ) ];
hdR = PowAgI( hdR, INT_TO_HD( -1 ) );
Retype( hdR, T_SWORD );
return hdR;
}
}
hdR = AgSolution2( hdB, hdA, hdA, hdB );
Retype( hdR, T_SWORD );
return hdR;
}
TypHandle       FunConjugatePcp ( hdCall )
TypHandle           hdCall;
{
TypHandle           hdP,  hdA,  hdB,  hdR;
long                col,  a,  b,  nrA,  nrB, len;
char                * usage = "usage: ConjugatePcp( <P>, <a>, <b> )";
if ( SIZE( hdCall ) != 4 * SIZE_HD )
return Error( usage, 0L, 0L );
hdP = EVAL( PTR( hdCall )[ 1 ] );
if ( TYPE( hdP ) != T_PCPRES )
return Error( usage, 0L, 0L );
hdP = *PTR( hdP );
hdA = EVAL( PTR( hdCall )[ 2 ] );
hdB = EVAL( PTR( hdCall )[ 3 ] );
col = COLLECTOR( hdP );
len = NUMBER_OF_GENS( hdP );
if ( col == SINGLE_COLLECTOR )
{
if ( TYPE( hdA ) == T_INT && TYPE( hdB ) == T_INT )
{
a = HD_TO_INT( hdA ) - 1;
b = HD_TO_INT( hdB ) - 1;
if ( a < 0 || b < 0 )
return Error( "generator number must be positive", 0L, 0L );
if ( a >= len || b >= len )
return Error("presentation has only %d generators", len, 0L);
if ( a == b )
return GENERATORS( hdP )[ a ];
else if ( a > b )
return CONJUGATES( hdP )[ IND( a, b ) ];
else
{
hdA = GENERATORS( hdP )[ a ];
hdB = GENERATORS( hdP )[ b ];
hdR = AgSolution2( hdB, HD_IDENTITY( hdP ), hdA, hdB );
Retype( hdR, T_SWORD );
return hdR;
}
}
}
if ( TYPE( hdA ) == T_INT )
{
a = HD_TO_INT( hdA ) - 1;
if ( a < 0 )
return Error( "generator number must be positive", 0L, 0L );
if ( a >= len )
return Error("presentation has only %d generators", len, 0L);
hdA = GENERATORS( hdP )[ a ];
}
else if ( TYPE( hdA ) == T_WORD || TYPE( hdA ) == T_SWORD )
{
hdA = NormalWordPcp( hdP, hdA );
if ( hdA == HdFalse )
return Error( "<a> must be a word of <P>", 0L, 0L );
}
else
return Error( usage, 0L, 0L );
if ( TYPE( hdB ) == T_INT )
{
b = HD_TO_INT( hdB ) - 1;
if ( b < 0 )
return Error( "generator number must be positive", 0L, 0L );
if ( b >= len )
return Error("presentation has only %d generators", len, 0L);
hdB = GENERATORS( hdP )[ b ];
}
else if ( TYPE( hdB ) == T_WORD || TYPE( hdB ) == T_SWORD )
{
hdB = NormalWordPcp( hdP, hdB );
if ( hdB == HdFalse )
return Error( "<b> must be a word of <P>", 0L, 0L );
}
else
return Error( usage, 0L, 0L );
nrA = LEN_AW( hdA );
nrB = LEN_AW( hdB );
if ( nrA == 0 || nrB == 0 )
return hdA;
if (    col == SINGLE_COLLECTOR
&& nrA == 1
&& nrB == 1
&& PTR_AW( hdA )[ 1 ] == 1
&& PTR_AW( hdB )[ 1 ] == 1 )
{
a = PTR_AW( hdA )[ 0 ];
b = PTR_AW( hdB )[ 0 ];
if ( a == b )
return HD_IDENTITY( hdP );
if ( a > b )
return CONJUGATES( hdP )[ IND( a, b ) ];
else
{
hdR = AgSolution2( hdB, HD_IDENTITY( hdP ), hdA, hdB );
Retype( hdR, T_SWORD );
return hdR;
}
}
hdR = AgSolution2( hdB, HD_IDENTITY( hdP ), hdA, hdB );
Retype( hdR, T_SWORD );
return hdR;
}
TypHandle       FunPowerPcp ( hdCall )
TypHandle           hdCall;
{
TypHandle           hdP,  hdG, hdN, hdR;
long                n;
char                * usage = "usage: PowerPcp( <P>, <g>, <n> )";
if ( SIZE( hdCall ) < 3 * SIZE_HD || SIZE( hdCall ) > 4 * SIZE_HD )
return Error( usage, 0L, 0L );
hdP = EVAL( PTR( hdCall )[ 1 ] );
if ( TYPE( hdP ) != T_PCPRES )
return Error( usage, 0L, 0L );
hdP = *PTR( hdP );
hdG = EVAL( PTR( hdCall )[ 2 ] );
if ( TYPE( hdG ) == T_INT )
{
n = HD_TO_INT( hdG );
if ( n < 1 )
return Error( "generator number must be positive", 0L, 0L );
if ( n > NUMBER_OF_GENS( hdP ) )
return Error( "presenation has only %d generators",
NUMBER_OF_GENS( hdP ), 0L );
if ( SIZE( hdCall ) == 3 * SIZE_HD )
return POWERS( hdP )[ n - 1 ];
hdG = GENERATORS( hdP )[ n - 1 ];
}
else if ( TYPE( hdG ) == T_WORD || TYPE( hdG ) == T_SWORD )
{
hdG = NormalWordPcp( hdP, hdG );
if ( hdG == HdFalse )
return Error( "<g> must be a word of <P>", 0L, 0L );
}
else
return Error( usage, 0L, 0L );
if ( ISID_AW( hdG ) )
return hdG;
if ( SIZE( hdCall ) == 3 * SIZE_HD )
hdN = INT_TO_HD( INDICES( hdP )[ *PTR_AW( hdG ) ] );
else
hdN = EVAL( PTR( hdCall )[ 3 ] );
if ( TYPE( hdN ) != T_INT )
return Error( usage, 0L, 0L );
hdR = PowAgI( hdG, hdN );
Retype( hdR, T_SWORD );
return hdR;
}
boolean     IsNormedPcp ( hdP, hdV )
TypHandle       hdP;
TypHandle       * hdV;
{
TypHandle       hdQ;
TypSword        * ptV,  lst;
long            * ptI;
if ( TYPE( *hdV ) == T_SWORD )
{
hdQ = *PTR( *hdV );
if ( hdQ == hdP )
return TRUE;
if ( TYPE( hdQ ) == T_AGGRP )
hdQ = HD_WORDS( hdQ );
*hdV = SwordSword( HD_WORDS( hdP ), *hdV );
}
else if ( *hdV == HdIdWord )
{
*hdV = HD_IDENTITY( hdP );
return TRUE;
}
else
*hdV = SwordWord( HD_WORDS( hdP ), *hdV );
if ( *hdV == HdFalse )
return FALSE;
ptV = PTR_AW( *hdV );
ptI = INDICES( hdP );
lst = -1;
while ( *ptV != -1 )
{
if ( ptV[ 0 ] <= lst )
return FALSE;
if ( ptV[ 1 ] < 0 || ptV[ 1 ] >= ptI[ ptV[ 0 ] ] )
return FALSE;
lst  = ptV[ 0 ];
ptV += 2;
}
*PTR( *hdV ) = hdP;
return TRUE;
}
TypHandle       FunSumPcp ( hdCall )
TypHandle       hdCall;
{
TypHandle       hdP,  hdV,  hdW;
char            * usage = "usage: SumPcp( <P>, <v>, <w> )";
if ( SIZE( hdCall ) != 4 * SIZE_HD )
return Error( usage, 0L, 0L );
hdP = EVAL( PTR( hdCall )[ 1 ] );
hdV = EVAL( PTR( hdCall )[ 2 ] );
hdW = EVAL( PTR( hdCall )[ 3 ] );
if (      TYPE( hdP ) != T_PCPRES
|| ( TYPE( hdV ) != T_SWORD && TYPE( hdV ) != T_WORD )
|| ( TYPE( hdW ) != T_SWORD && TYPE( hdW ) != T_WORD ) )
{
return Error( usage, 0L, 0L );
}
hdP = *PTR( hdP );
if ( ! IsNormedPcp( hdP, &hdV ) )
return Error( "SumPcp: <v> must be a normed word of <P>", 0L, 0L );
if ( ! IsNormedPcp( hdP, &hdW ) )
return Error( "SumPcp: <w> must be a normed word of <P>", 0L, 0L );
hdV = SumAgWord( hdP, hdV, hdW );
Retype( hdV, T_SWORD );
return hdV;
}
TypHandle       FunDifferencePcp ( hdCall )
TypHandle       hdCall;
{
TypHandle       hdP,  hdV,  hdW;
char            * usage = "usage: DifferencePcp( <P>, <v>, <w> )";
if ( SIZE( hdCall ) != 4 * SIZE_HD )
return Error( usage, 0L, 0L );
hdP = EVAL( PTR( hdCall )[ 1 ] );
hdV = EVAL( PTR( hdCall )[ 2 ] );
hdW = EVAL( PTR( hdCall )[ 3 ] );
if (      TYPE( hdP ) != T_PCPRES
|| ( TYPE( hdV ) != T_SWORD && TYPE( hdV ) != T_WORD )
|| ( TYPE( hdW ) != T_SWORD && TYPE( hdW ) != T_WORD ) )
{
return Error( usage, 0L, 0L );
}
hdP = *PTR( hdP );
if ( ! IsNormedPcp( hdP, &hdV ) )
return Error("DifferencePcp: <v> must be a normed word of <P>",0L,0L);
if ( ! IsNormedPcp( hdP, &hdW ) )
return Error("DifferencePcp: <w> must be a normed word of <P>",0L,0L);
hdV = DifferenceAgWord( hdP, hdV, hdW );
Retype( hdV, T_SWORD );
return hdV;
}
TypHandle       FunExponentPcp ( hdCall )
TypHandle       hdCall;
{
TypHandle       hdP,  hdG,  hdI;
TypSword        * ptG,  * ptE;
long            i;
char            * usage = "usage: ExponentPcp( <P>, <g>, <i> )";
if ( SIZE( hdCall ) != 4 * SIZE_HD  )
return Error( usage, 0L, 0L );
hdP = EVAL( PTR( hdCall )[ 1 ] );
hdG = EVAL( PTR( hdCall )[ 2 ] );
hdI = EVAL( PTR( hdCall )[ 3 ] );
if ( TYPE( hdP ) != T_PCPRES || TYPE( hdI ) != T_INT )
return Error( usage, 0L, 0L );
hdP = *PTR( hdP );
i   = HD_TO_INT( hdI ) - 1;
if ( *PTR( hdG ) != hdP && ! IsNormedPcp( hdP, &hdG ) )
return Error( "<g> must be a normed word of <P>", 0L, 0L );
if ( i < 0 )
return Error( "generator number must be positive", 0L, 0L );
if ( i >= NUMBER_OF_GENS( hdP ) )
return Error( "presentation <P> has only %d generators",
NUMBER_OF_GENS( hdP ), 0L );
ptG = PTR_AW( hdG );
ptE = ptG + 2 * LEN_AW( hdG );
while ( ptG < ptE )
{
if ( ptG[0] == i )
return INT_TO_HD( ptG[1] );
else if ( ptG[0] > i )
return INT_TO_HD( 0 );
ptG += 2;
}
return INT_TO_HD( 0 );
}
TypHandle       FunExponentsPcp ( hdCall )
TypHandle       hdCall;
{
TypHandle       hdP,  hdV;
char            * usage = "usage: ExponentsPcp( <P>, <v> )";
if ( SIZE( hdCall ) != 3 * SIZE_HD )
return Error( usage, 0L, 0L );
hdP = EVAL( PTR( hdCall )[ 1 ] );
hdV = EVAL( PTR( hdCall )[ 2 ] );
if (      TYPE( hdP ) != T_PCPRES
|| ( TYPE( hdV ) != T_SWORD && TYPE( hdV ) != T_WORD ) )
{
return Error( usage, 0L, 0L );
}
hdP = *PTR( hdP );
if ( ! IsNormedPcp( hdP, &hdV ) )
return Error("ExponentsPcp: <v> must be a normed word of <P>",0L,0L);
return IntExponentsAgWord( hdV, 1, NUMBER_OF_GENS( hdP ) );
}
TypHandle       FunDepthPcp ( hdCall )
TypHandle       hdCall;
{
TypHandle       hdWrd,  hdP;
char            * usage = "usage: DepthPcp( <P>, <g> )";
if ( SIZE( hdCall ) != 3 * SIZE_HD )
return Error( usage, 0L, 0L );
hdP   = EVAL( PTR( hdCall )[ 1 ] );
hdWrd = EVAL( PTR( hdCall )[ 2 ] );
if ((TYPE(hdWrd)!=T_WORD && TYPE(hdWrd)!=T_SWORD) || TYPE(hdP)!=T_PCPRES)
return Error( usage, 0L, 0L );
hdP = *PTR( hdP );
if ( ! IsNormedPcp( hdP, &hdWrd ) )
return Error("DepthPcp: <g> must be a normed word of <P>",0L,0L);
return INT_TO_HD( ( *( PTR_AW( hdWrd ) ) + 1 ) );
}
TypHandle       FunTailDepthPcp ( hdCall )
TypHandle       hdCall;
{
TypHandle       hdWrd,  hdP;
TypSword        * ptWrd;
char            * usage = "usage: TailDepthPcp( <P>, <g> )";
if ( SIZE( hdCall ) != 3 * SIZE_HD )
return Error( usage, 0L, 0L );
hdP   = EVAL( PTR( hdCall )[ 1 ] );
hdWrd = EVAL( PTR( hdCall )[ 2 ] );
if ((TYPE(hdWrd)!=T_WORD && TYPE(hdWrd)!=T_SWORD) || TYPE(hdP)!=T_PCPRES)
return Error( usage, 0L, 0L );
hdP = *PTR( hdP );
if ( ! IsNormedPcp( hdP, &hdWrd ) )
return Error("TailDepthPcp: <g> must be a normed word of <P>",0L,0L);
if ( ISID_AW( hdWrd ) )
return INT_TO_HD( 0 );
ptWrd = (TypSword*)( (char*) PTR( hdWrd ) + SIZE( hdWrd ) );
return INT_TO_HD( ( ptWrd[ -3 ] + 1 ) );
}
#if 0
TypHandle       FunAgWordExponents ( hdCall )
TypHandle       hdCall;
{
TypHandle       hdW, hdL, hdP, hdI;
TypSword        * ptW;
long            * ptIndices, nonTrivial, i, exp, start;
if ( SIZE( hdCall ) < 3 * SIZE_HD || SIZE( hdCall ) > 4 * SIZE_HD )
{
return Error( "usage: AgWordExponents( <pcpres>, <list> )", 0L, 0L );
}
hdP = EVAL( PTR( hdCall )[ 1 ] );
hdL = EVAL( PTR( hdCall )[ 2 ] );
if ( SIZE( hdCall ) == 4 * SIZE_HD )
{
hdI = EVAL( PTR( hdCall )[ 3 ] );
if ( TYPE( hdI ) != T_INT )
{
return Error("usage: AgWordExponents( <pcpres>, <list>, <start> )",
0L, 0L );
}
start = HD_TO_INT( hdI ) - 1;
}
else
start = 0;
if ( TYPE( hdP ) != T_PCPRES
|| ! IsVector( hdL )
|| ( LEN_LIST( hdL ) > 0 && TYPE( ELM_PLIST(hdL,0) ) != T_INT ) )
{
return Error( "usage: AgWordExponents( <pcpres>, <list> )", 0L, 0L );
}
if ( start < 0 )
{
return Error( "AgWordExponents: <start> must be positive", 0L, 0L );
}
if ( start + LEN_LIST( hdL ) > NUMBER_OF_GENS( hdP ) )
{
return Error( "AgWordExponents: too many generators", 0L, 0L );
}
nonTrivial = 0;
ptIndices = INDICES( hdP );
for ( i = LEN_LIST( hdL ); i > 0; i-- )
if ( HD_TO_INT( ELM_PLIST( hdL, i ) ) % ptIndices[ i+start-1 ] != 0 )
nonTrivial++;
hdW = NewBag( T_AGWORD, SIZE_HD + ( 2 * nonTrivial + 1 ) * SIZE_GEN );
*PTR( hdW ) = hdP;
ptW = PTR_AW( hdW ) + 2 * nonTrivial;
*ptW-- = -1;
ptIndices = INDICES( hdP );
for ( i = LEN_LIST( hdL ); i > 0; i-- )
{
exp = HD_TO_INT( ELM_PLIST( hdL, i ) ) % ptIndices[ i+start-1 ];
if ( exp != 0 )
{
*ptW-- = exp;
*ptW-- = i + start - 1;
}
}
return hdW;
}
#endif
TypHandle       FunBaseReducedPcp ( hdCall )
TypHandle       hdCall;
{
TypHandle       hdV,  hdW,  hdL,  hdP;
TypSword        * ptW,  * ptV;
TypExp          * ptR;
long            * ptIdx,  lenL,  i,  exp;
char            * usage = "usage: BaseReducedPcp( <P>, <B>, <v> )";
if ( SIZE( hdCall ) != 4 * SIZE_HD )
return Error( usage, 0L, 0L );
hdP = EVAL( PTR( hdCall )[ 1 ] );
hdL = EVAL( PTR( hdCall )[ 2 ] );
hdW = EVAL( PTR( hdCall )[ 3 ] );
if (    ! IsList( hdL )
|| ( TYPE( hdW ) != T_WORD && TYPE( hdW ) != T_SWORD )
||   TYPE( hdP ) != T_PCPRES )
{
return Error( usage, 0L, 0L );
}
hdP = *PTR( hdP );
if ( ! IsNormedPcp( hdP, &hdW ) )
return Error( "<v> must be a normed word of <P>", 0L, 0L );
lenL = LEN_LIST( hdL );
if ( lenL > NUMBER_OF_GENS( hdP ) )
return Error( "<P> has only %d generators, but <B> has length %d",
NUMBER_OF_GENS( hdP ), lenL );
ptW = PTR_AW( hdW );
if ( *ptW == -1 || *ptW >= lenL )
return hdW;
SetCollectExponents( hdW );
ptIdx = INDICES( hdP );
ptR = COLLECT_EXPONENTS( hdP );
for ( i = *ptW;  i < lenL;  i++ )
{
exp = ptR[ i ];
if ( exp != 0 )
{
hdV = ELM_PLIST( hdL, i + 1 );
if ( hdV == 0 )
continue;
if ( *PTR( hdV ) != hdP )
{
if ( ! IsNormedPcp( hdP, &hdV ) )
{
ClearCollectExponents( hdP );
return Error( "element %d must be a normed word of <P>",
i + 1, 0L );
}
else
{
SET_ELM_PLIST( hdL, i + 1, hdV );
ptIdx = INDICES( hdP );
ptR   = COLLECT_EXPONENTS( hdP );
}
}
ptV = PTR_AW( hdV );
if ( *ptV != i )
{
ClearCollectExponents( hdP );
return Error( "depth of %d. base element must be %d",
i + 1, i + 1 );
}
if ( *( ptV + 1 ) != 1 )
{
ClearCollectExponents( hdP );
return Error( "leading exponent of %d. element must be 1",
i + 1, 0L );
}
while ( *ptV != -1 )
{
ptR[*ptV] = (ptR[*ptV] - exp*(ptV[1])) % ptIdx[*ptV];
if ( ptR[ *ptV ] < 0 )
ptR[ *ptV ] += ptIdx[ *ptV ];
ptV += 2;
}
}
}
hdV = AgWordAgExp( HD_COLLECT_EXPONENTS( hdP ), hdP );
Retype( hdV, T_SWORD );
return hdV;
}
TypHandle       FunTailReducedPcp ( hdCall )
TypHandle       hdCall;
{
TypHandle       hdV, hdW, hdL, hdP;
TypSword        * ptW, * ptV;
TypExp          * ptR;
long            * ptIdx, lenL, i, exp, lenV;
char            * usage = "TailReducedPcp( <P>, <B>, <v> )";
if ( SIZE( hdCall ) != 4 * SIZE_HD )
return Error( usage, 0L, 0L );
hdP = EVAL( PTR( hdCall )[ 1 ] );
hdL = EVAL( PTR( hdCall )[ 2 ] );
hdW = EVAL( PTR( hdCall )[ 3 ] );
if (    ! IsList( hdL )
|| ( TYPE( hdW ) != T_WORD && TYPE( hdW ) != T_SWORD )
||   TYPE( hdP ) != T_PCPRES )
{
return Error( usage, 0L, 0L );
}
hdP = *PTR( hdP );
if ( ! IsNormedPcp( hdP, &hdW ) )
return Error( "<v> must be a normed word of <P>", 0L, 0L );
lenL = LEN_LIST( hdL );
if ( lenL > NUMBER_OF_GENS( hdP ) )
return Error( "<P> has only %d generators, but <B> has length %d",
NUMBER_OF_GENS( hdP ), lenL );
ptW = PTR_AW( hdW );
if ( *ptW == -1 )
return hdW;
SetCollectExponents( hdW );
ptIdx = INDICES( hdP );
ptR = COLLECT_EXPONENTS( hdP );
for ( i = lenL - 1; i >= 0; i-- )
{
exp = ptR[ i ];
if ( exp != 0 )
{
hdV = ELM_PLIST( hdL, i + 1 );
if ( hdV == 0 )
continue;
if ( *PTR( hdV ) != hdP )
{
if ( ! IsNormedPcp( hdP, &hdV ) )
{
ClearCollectExponents( hdP );
return Error( "element %d must be a normed word of <P>",
i + 1, 0L );
}
else
{
SET_ELM_PLIST( hdL, i + 1, hdV );
ptIdx = INDICES( hdP );
ptR   = COLLECT_EXPONENTS( hdP );
}
}
ptV  = PTR_AW( hdV );
lenV = LEN_AW( hdV );
if ( ptV[ 2 * lenV - 2 ] != i )
{
ClearCollectExponents( hdP );
return Error( "tail depth of %d. base element must be %d",
i + 1, i + 1 );
}
if ( ptV[ 2 * lenV - 1 ] != 1 )
{
ClearCollectExponents( hdP );
return Error( "trailing exponent of %d. element must be 1",
i + 1, 0L );
}
while ( *ptV != -1 )
{
ptR[*ptV] = (ptR[*ptV] - exp*(ptV[1])) % ptIdx[*ptV];
if ( ptR[ *ptV ] < 0 )
ptR[ *ptV ] += ptIdx[ *ptV ];
ptV += 2;
}
}
}
hdV = AgWordAgExp( HD_COLLECT_EXPONENTS( hdP ), hdP );
Retype( hdV, T_SWORD );
return hdV;
}
#if PCP_DEBUG
TypHandle       FunPowersPcp ( hdCall )
TypHandle       hdCall;
{
TypHandle       hdP;
char            * usage = "usage: PowersPcp( <P> )";
if ( SIZE( hdCall ) != 2 * SIZE_HD )
return Error( usage, 0L, 0L );
hdP = EVAL( PTR( hdCall )[ 1 ] );
if ( TYPE( hdP ) != T_PCPRES )
return Error( usage, 0L, 0L );
return HD_POWERS( *PTR( hdP ) );
}
TypHandle       FunCommutatorsPcp ( hdCall )
TypHandle       hdCall;
{
TypHandle       hdP;
char            * usage = "usage: CommutatorsPcp( <P> )";
if ( SIZE( hdCall ) != 2 * SIZE_HD )
return Error( usage, 0L, 0L );
hdP = EVAL( PTR( hdCall )[ 1 ] );
if ( TYPE( hdP ) != T_PCPRES )
return Error( usage, 0L, 0L );
return HD_COMMUTATORS( *PTR( hdP ) );
}
#endif
void        PrPcPres( hdP )
TypHandle       hdP;
{
Pr( "<Pcp: %d generators, %s collector>",
(long) NUMBER_OF_GENS( *PTR( hdP ) ),
(long) Collectors[ COLLECTOR( *PTR( hdP ) ) ].name );
}
void        InitPcPres ()
{
InstIntFunc( "NormalWordPcp",           FunNormalWordPcp            );
InstIntFunc( "PowerPcp",                FunPowerPcp                 );
InstIntFunc( "CommPcp",                 FunCommPcp                  );
InstIntFunc( "ConjugatePcp",            FunConjugatePcp             );
InstIntFunc( "ProductPcp",              FunProductPcp               );
InstIntFunc( "QuotientPcp",             FunQuotientPcp              );
InstIntFunc( "LeftQuotientPcp",         FunLeftQuotientPcp          );
InstIntFunc( "SumPcp",                  FunSumPcp                   );
InstIntFunc( "DifferencePcp",           FunDifferencePcp            );
InstIntFunc( "ExponentPcp",             FunExponentPcp              );
InstIntFunc( "ExponentsPcp",            FunExponentsPcp             );
InstIntFunc( "DepthPcp",                FunDepthPcp                 );
InstIntFunc( "TailDepthPcp",            FunTailDepthPcp             );
InstIntFunc( "BaseReducedPcp",          FunBaseReducedPcp           );
InstIntFunc( "TailReducedPcp",          FunTailReducedPcp           );
InstPrFunc( T_PCPRES,                   PrPcPres                    );
InstIntFunc( "GeneratorsPcp",           FunGeneratorsPcp            );
InstIntFunc( "CentralWeightsPcp",       FunCentralWeightsPcp        );
InstIntFunc( "DefineCentralWeightsPcp", FunDefineCentralWeightsPcp  );
InstIntFunc( "DefineCommPcp",           FunDefineCommPcp            );
InstIntFunc( "AddCommPcp",              FunAddCommPcp               );
InstIntFunc( "SubtractCommPcp",         FunSubtractCommPcp          );
InstIntFunc( "DefinePowerPcp",          FunDefinePowerPcp           );
InstIntFunc( "AddPowerPcp",             FunAddPowerPcp              );
InstIntFunc( "SubtractPowerPcp",        FunSubtractPowerPcp         );
InstIntFunc( "Pcp",                     FunPcp                      );
InstIntFunc( "TriangleIndex",           FunTriangleIndex            );
InstIntFunc( "ExtendCentralPcp",        FunExtendCentralPcp         );
InstIntFunc( "ShrinkPcp",               FunShrinkPcp                );
InstIntFunc( "AgPcp",                   FunAgPcp                    );
#if PCP_DEBUG
InstIntFunc( "PowersPcp",           FunPowersPcp                );
InstIntFunc( "CommutatorsPcp",      FunCommutatorsPcp           );
#endif
}
/* 当前文件是D:\Read\permutat.c*/

typedef unsigned short  TypPoint16;
typedef unsigned long   TypPoint32;
#define IMAGE(I,PT,DG)  (((I) < (DG)) ? (PT)[(I)] : (I))
TypHandle               HdPerm;
TypHandle       EvPerm ( hdPerm )
TypHandle           hdPerm;
{
return hdPerm;
}
TypHandle       EvMakeperm ( hdPerm )
TypHandle           hdPerm;
{
TypHandle           hdRes;
TypHandle           hdCyc;
TypHandle           hd;
unsigned long       psize;
unsigned long       lsize;
unsigned long       nsize;
TypPoint32          first;
TypPoint32          last;
TypPoint32          curr;
long                i, j, k;
psize = 0;
for ( i = 0; i < SIZE(hdPerm)/SIZE_HD; i++ )
psize += SIZE( PTR(hdPerm)[i] ) / SIZE_HD;
if ( psize <= 65536 ) {
hdRes = NewBag(T_PERM16,(unsigned long)(psize*sizeof(TypPoint16)));
for ( i = 0; i < psize; i++ )
((TypPoint16*)PTR(hdRes))[i] = i;
}
else {
hdRes = NewBag(T_PERM32,(unsigned long)(psize*sizeof(TypPoint32)));
for ( i = 0; i < psize; i++ )
((TypPoint32*)PTR(hdRes))[i] = i;
}
lsize = 0;
for ( i = 0; i < SIZE(hdPerm)/SIZE_HD; i++ ) {
hdCyc = PTR(hdPerm)[i];
first = 0;
last = 0;
for ( j = 0; j < SIZE(hdCyc)/SIZE_HD; j++ ) {
hd = EVAL( PTR(hdCyc)[j] );
if ( TYPE(hd) != T_INT || HD_TO_INT(hd) <= 0 )
return Error("Perm: <point> must be an positive int",0L,0L);
curr = HD_TO_INT(hd)-1;
if ( psize < curr+1 ) {
if ( psize+256 < curr+1 )       nsize = curr+1;
else if ( psize+256 <= 65536 )  nsize = psize + 256;
else if ( curr+1 <= 65536 )     nsize = 65536;
else                            nsize = psize + 1024;
if ( psize <= 65536 && 65536 < nsize ) {
Retype(hdRes,T_PERM32);
Resize(hdRes,(unsigned long)(nsize*sizeof(TypPoint32)));
for ( k = psize-1; 0 <= k; k-- ) {
((TypPoint32*)PTR(hdRes))[k]
= ((TypPoint16*)PTR(hdRes))[k];
}
for ( ; psize < nsize; psize++ )
((TypPoint32*)PTR(hdRes))[psize] = psize;
}
else if ( psize <= 65536 ) {
Resize(hdRes,(unsigned long)(nsize*sizeof(TypPoint16)));
for ( ; psize < nsize; psize++ )
((TypPoint16*)PTR(hdRes))[psize] = psize;
}
else {
Resize(hdRes,(unsigned long)(nsize*sizeof(TypPoint32)));
for ( ; psize < nsize; psize++ )
((TypPoint32*)PTR(hdRes))[psize] = psize;
}
}
if ( lsize < curr+1 ) {
lsize = curr+1;
}
if ( (j != 0 && last == curr)
|| (psize <= 65536 && ((TypPoint16*)PTR(hdRes))[curr]!=curr)
|| (65536 < psize && ((TypPoint32*)PTR(hdRes))[curr]!=curr) ) {
return Error("Perm: cycles must be disjoint",0L,0L);
}
if ( j == 0 )
first = curr;
else if ( psize <= 65536 )
((TypPoint16*)PTR(hdRes))[last] = curr;
else
((TypPoint32*)PTR(hdRes))[last] = curr;
last = curr;
}
if ( psize <= 65536 )
((TypPoint16*)PTR(hdRes))[last] = first;
else
((TypPoint32*)PTR(hdRes))[last] = first;
}
if ( psize <= 65536 )
Resize( hdRes, (unsigned long)(lsize * sizeof(TypPoint16)) );
else
Resize( hdRes, (unsigned long)(lsize * sizeof(TypPoint32)) );
return hdRes;
}
TypHandle       ProdPP ( hdL, hdR )
TypHandle           hdL;
TypHandle           hdR;
{
TypHandle           hdP;
unsigned long       degP;
TypPoint16          * ptP;
unsigned long       degL;
TypPoint16          * ptL;
unsigned long       degR;
TypPoint16          * ptR;
unsigned long       p;
degL = SIZE(hdL) / sizeof(TypPoint16);
degR = SIZE(hdR) / sizeof(TypPoint16);
degP = degL < degR ? degR : degL;
hdP  = NewBag( T_PERM16, (unsigned long)(degP * sizeof(TypPoint16)) );
ptL = (TypPoint16*)PTR(hdL);
ptR = (TypPoint16*)PTR(hdR);
ptP = (TypPoint16*)PTR(hdP);
if ( degL <= degR ) {
for ( p = 0; p < degL; p++ )
*(ptP++) = ptR[ *(ptL++) ];
for ( p = degL; p < degR; p++ )
*(ptP++) = ptR[ p ];
}
else {
for ( p = 0; p < degL; p++ )
*(ptP++) = IMAGE( ptL[ p ], ptR, degR );
}
return hdP;
}
TypHandle       ProdPQ ( hdL, hdR )
TypHandle           hdL;
TypHandle           hdR;
{
TypHandle           hdP;
unsigned long       degP;
TypPoint32          * ptP;
unsigned long       degL;
TypPoint16          * ptL;
unsigned long       degR;
TypPoint32          * ptR;
unsigned long       p;
degL = SIZE(hdL) / sizeof(TypPoint16);
degR = SIZE(hdR) / sizeof(TypPoint32);
degP = degL < degR ? degR : degL;
hdP  = NewBag( T_PERM32, (unsigned long)(degP * sizeof(TypPoint32)) );
ptL = (TypPoint16*)PTR(hdL);
ptR = (TypPoint32*)PTR(hdR);
ptP = (TypPoint32*)PTR(hdP);
if ( degL <= degR ) {
for ( p = 0; p < degL; p++ )
*(ptP++) = ptR[ *(ptL++) ];
for ( p = degL; p < degR; p++ )
*(ptP++) = ptR[ p ];
}
else {
for ( p = 0; p < degL; p++ )
*(ptP++) = IMAGE( ptL[ p ], ptR, degR );
}
return hdP;
}
TypHandle       ProdQP ( hdL, hdR )
TypHandle           hdL;
TypHandle           hdR;
{
TypHandle           hdP;
unsigned long       degP;
TypPoint32          * ptP;
unsigned long       degL;
TypPoint32          * ptL;
unsigned long       degR;
TypPoint16          * ptR;
unsigned long       p;
degL = SIZE(hdL) / sizeof(TypPoint32);
degR = SIZE(hdR) / sizeof(TypPoint16);
degP = degL < degR ? degR : degL;
hdP  = NewBag( T_PERM32, (unsigned long)(degP * sizeof(TypPoint32)) );
ptL = (TypPoint32*)PTR(hdL);
ptR = (TypPoint16*)PTR(hdR);
ptP = (TypPoint32*)PTR(hdP);
if ( degL <= degR ) {
for ( p = 0; p < degL; p++ )
*(ptP++) = ptR[ *(ptL++) ];
for ( p = degL; p < degR; p++ )
*(ptP++) = ptR[ p ];
}
else {
for ( p = 0; p < degL; p++ )
*(ptP++) = IMAGE( ptL[ p ], ptR, degR );
}
return hdP;
}
TypHandle       ProdQQ ( hdL, hdR )
TypHandle           hdL;
TypHandle           hdR;
{
TypHandle           hdP;
unsigned long       degP;
TypPoint32          * ptP;
unsigned long       degL;
TypPoint32          * ptL;
unsigned long       degR;
TypPoint32          * ptR;
unsigned long       p;
degL = SIZE(hdL) / sizeof(TypPoint32);
degR = SIZE(hdR) / sizeof(TypPoint32);
degP = degL < degR ? degR : degL;
hdP  = NewBag( T_PERM32, (unsigned long)(degP * sizeof(TypPoint32)) );
ptL = (TypPoint32*)PTR(hdL);
ptR = (TypPoint32*)PTR(hdR);
ptP = (TypPoint32*)PTR(hdP);
if ( degL <= degR ) {
for ( p = 0; p < degL; p++ )
*(ptP++) = ptR[ *(ptL++) ];
for ( p = degL; p < degR; p++ )
*(ptP++) = ptR[ p ];
}
else {
for ( p = 0; p < degL; p++ )
*(ptP++) = IMAGE( ptL[ p ], ptR, degR );
}
return hdP;
}
TypHandle       QuoPP ( hdL, hdR )
TypHandle           hdL;
TypHandle           hdR;
{
TypHandle           hdQ;
unsigned long       degQ;
TypPoint16          * ptQ;
unsigned long       degL;
TypPoint16          * ptL;
unsigned long       degR;
TypPoint16          * ptR;
TypPoint16          * ptI;
unsigned long       p;
degL = SIZE(hdL) / sizeof(TypPoint16);
degR = SIZE(hdR) / sizeof(TypPoint16);
degQ = degL < degR ? degR : degL;
hdQ  = NewBag( T_PERM16, (unsigned long)(degQ * sizeof(TypPoint16)) );
if ( SIZE(HdPerm) < SIZE(hdR) )  Resize( HdPerm, SIZE(hdR) );
ptI = (TypPoint16*)PTR(HdPerm);
ptR = (TypPoint16*)PTR(hdR);
for ( p = 0; p < degR; p++ )
ptI[ *ptR++ ] = p;
ptL = (TypPoint16*)PTR(hdL);
ptI = (TypPoint16*)PTR(HdPerm);
ptQ = (TypPoint16*)PTR(hdQ);
if ( degL <= degR ) {
for ( p = 0; p < degL; p++ )
*(ptQ++) = ptI[ *(ptL++) ];
for ( p = degL; p < degR; p++ )
*(ptQ++) = ptI[ p ];
}
else {
for ( p = 0; p < degL; p++ )
*(ptQ++) = IMAGE( ptL[ p ], ptI, degR );
}
ptI = (TypPoint16*)PTR(HdPerm);
for ( p = 0; p < degR; p++ )
ptI[ p ] = 0;
return hdQ;
}
TypHandle       QuoPQ ( hdL, hdR )
TypHandle           hdL;
TypHandle           hdR;
{
TypHandle           hdQ;
unsigned long       degQ;
TypPoint32          * ptQ;
unsigned long       degL;
TypPoint16          * ptL;
unsigned long       degR;
TypPoint32          * ptR;
TypPoint32          * ptI;
unsigned long       p;
degL = SIZE(hdL) / sizeof(TypPoint16);
degR = SIZE(hdR) / sizeof(TypPoint32);
degQ = degL < degR ? degR : degL;
hdQ  = NewBag( T_PERM32, (unsigned long)(degQ * sizeof(TypPoint32)) );
if ( SIZE(HdPerm) < SIZE(hdR) )  Resize( HdPerm, SIZE(hdR) );
ptI = (TypPoint32*)PTR(HdPerm);
ptR = (TypPoint32*)PTR(hdR);
for ( p = 0; p < degR; p++ )
ptI[ *ptR++ ] = p;
ptL = (TypPoint16*)PTR(hdL);
ptI = (TypPoint32*)PTR(HdPerm);
ptQ = (TypPoint32*)PTR(hdQ);
if ( degL <= degR ) {
for ( p = 0; p < degL; p++ )
*(ptQ++) = ptI[ *(ptL++) ];
for ( p = degL; p < degR; p++ )
*(ptQ++) = ptI[ p ];
}
else {
for ( p = 0; p < degL; p++ )
*(ptQ++) = IMAGE( ptL[ p ], ptI, degR );
}
ptI = (TypPoint32*)PTR(HdPerm);
for ( p = 0; p < degR; p++ )
ptI[ p ] = 0;
return hdQ;
}
TypHandle       QuoQP ( hdL, hdR )
TypHandle           hdL;
TypHandle           hdR;
{
TypHandle           hdQ;
unsigned long       degQ;
TypPoint32          * ptQ;
unsigned long       degL;
TypPoint32          * ptL;
unsigned long       degR;
TypPoint16          * ptR;
TypPoint16          * ptI;
unsigned long       p;
degL = SIZE(hdL) / sizeof(TypPoint32);
degR = SIZE(hdR) / sizeof(TypPoint16);
degQ = degL < degR ? degR : degL;
hdQ  = NewBag( T_PERM32, (unsigned long)(degQ * sizeof(TypPoint32)) );
if ( SIZE(HdPerm) < SIZE(hdR) )  Resize( HdPerm, SIZE(hdR) );
ptI = (TypPoint16*)PTR(HdPerm);
ptR = (TypPoint16*)PTR(hdR);
for ( p = 0; p < degR; p++ )
ptI[ *ptR++ ] = p;
ptL = (TypPoint32*)PTR(hdL);
ptI = (TypPoint16*)PTR(HdPerm);
ptQ = (TypPoint32*)PTR(hdQ);
if ( degL <= degR ) {
for ( p = 0; p < degL; p++ )
*(ptQ++) = ptI[ *(ptL++) ];
for ( p = degL; p < degR; p++ )
*(ptQ++) = ptI[ p ];
}
else {
for ( p = 0; p < degL; p++ )
*(ptQ++) = IMAGE( ptL[ p ], ptI, degR );
}
ptI = (TypPoint16*)PTR(HdPerm);
for ( p = 0; p < degR; p++ )
ptI[ p ] = 0;
return hdQ;
}
TypHandle       QuoQQ ( hdL, hdR )
TypHandle           hdL;
TypHandle           hdR;
{
TypHandle           hdQ;
unsigned long       degQ;
TypPoint32          * ptQ;
unsigned long       degL;
TypPoint32          * ptL;
unsigned long       degR;
TypPoint32          * ptR;
TypPoint32          * ptI;
unsigned long       p;
degL = SIZE(hdL) / sizeof(TypPoint32);
degR = SIZE(hdR) / sizeof(TypPoint32);
degQ = degL < degR ? degR : degL;
hdQ  = NewBag( T_PERM32, (unsigned long)(degQ * sizeof(TypPoint32)) );
if ( SIZE(HdPerm) < SIZE(hdR) )  Resize( HdPerm, SIZE(hdR) );
ptI = (TypPoint32*)PTR(HdPerm);
ptR = (TypPoint32*)PTR(hdR);
for ( p = 0; p < degR; p++ )
ptI[ *ptR++ ] = p;
ptL = (TypPoint32*)PTR(hdL);
ptI = (TypPoint32*)PTR(HdPerm);
ptQ = (TypPoint32*)PTR(hdQ);
if ( degL <= degR ) {
for ( p = 0; p < degL; p++ )
*(ptQ++) = ptI[ *(ptL++) ];
for ( p = degL; p < degR; p++ )
*(ptQ++) = ptI[ p ];
}
else {
for ( p = 0; p < degL; p++ )
*(ptQ++) = IMAGE( ptL[ p ], ptI, degR );
}
ptI = (TypPoint32*)PTR(HdPerm);
for ( p = 0; p < degR; p++ )
ptI[ p ] = 0;
return hdQ;
}
TypHandle       ModPP ( hdL, hdR )
TypHandle           hdL;
TypHandle           hdR;
{
TypHandle           hdM;
unsigned long       degM;
TypPoint16          * ptM;
unsigned long       degL;
TypPoint16          * ptL;
unsigned long       degR;
TypPoint16          * ptR;
unsigned long       p;
degL = SIZE(hdL) / sizeof(TypPoint16);
degR = SIZE(hdR) / sizeof(TypPoint16);
degM = degL < degR ? degR : degL;
hdM = NewBag( T_PERM16, (unsigned long)(degM * sizeof(TypPoint16)) );
ptL = (TypPoint16*)PTR(hdL);
ptR = (TypPoint16*)PTR(hdR);
ptM = (TypPoint16*)PTR(hdM);
if ( degL <= degR ) {
for ( p = 0; p < degL; p++ )
ptM[ *(ptL++) ] = *(ptR++);
for ( p = degL; p < degR; p++ )
ptM[ p ] = *(ptR++);
}
else {
for ( p = 0; p < degR; p++ )
ptM[ *(ptL++) ] = *(ptR++);
for ( p = degR; p < degL; p++ )
ptM[ *(ptL++) ] = p;
}
return hdM;
}
TypHandle       ModPQ ( hdL, hdR )
TypHandle           hdL;
TypHandle           hdR;
{
TypHandle           hdM;
unsigned long       degM;
TypPoint32          * ptM;
unsigned long       degL;
TypPoint16          * ptL;
unsigned long       degR;
TypPoint32          * ptR;
unsigned long       p;
degL = SIZE(hdL) / sizeof(TypPoint16);
degR = SIZE(hdR) / sizeof(TypPoint32);
degM = degL < degR ? degR : degL;
hdM = NewBag( T_PERM32, (unsigned long)(degM * sizeof(TypPoint32)) );
ptL = (TypPoint16*)PTR(hdL);
ptR = (TypPoint32*)PTR(hdR);
ptM = (TypPoint32*)PTR(hdM);
if ( degL <= degR ) {
for ( p = 0; p < degL; p++ )
ptM[ *(ptL++) ] = *(ptR++);
for ( p = degL; p < degR; p++ )
ptM[ p ] = *(ptR++);
}
else {
for ( p = 0; p < degR; p++ )
ptM[ *(ptL++) ] = *(ptR++);
for ( p = degR; p < degL; p++ )
ptM[ *(ptL++) ] = p;
}
return hdM;
}
TypHandle       ModQP ( hdL, hdR )
TypHandle           hdL;
TypHandle           hdR;
{
TypHandle           hdM;
unsigned long       degM;
TypPoint32          * ptM;
unsigned long       degL;
TypPoint32          * ptL;
unsigned long       degR;
TypPoint16          * ptR;
unsigned long       p;
degL = SIZE(hdL) / sizeof(TypPoint32);
degR = SIZE(hdR) / sizeof(TypPoint16);
degM = degL < degR ? degR : degL;
hdM = NewBag( T_PERM32, (unsigned long)(degM * sizeof(TypPoint32)) );
ptL = (TypPoint32*)PTR(hdL);
ptR = (TypPoint16*)PTR(hdR);
ptM = (TypPoint32*)PTR(hdM);
if ( degL <= degR ) {
for ( p = 0; p < degL; p++ )
ptM[ *(ptL++) ] = *(ptR++);
for ( p = degL; p < degR; p++ )
ptM[ p ] = *(ptR++);
}
else {
for ( p = 0; p < degR; p++ )
ptM[ *(ptL++) ] = *(ptR++);
for ( p = degR; p < degL; p++ )
ptM[ *(ptL++) ] = p;
}
return hdM;
}
TypHandle       ModQQ ( hdL, hdR )
TypHandle           hdL;
TypHandle           hdR;
{
TypHandle           hdM;
unsigned long       degM;
TypPoint32          * ptM;
unsigned long       degL;
TypPoint32          * ptL;
unsigned long       degR;
TypPoint32          * ptR;
unsigned long       p;
degL = SIZE(hdL) / sizeof(TypPoint32);
degR = SIZE(hdR) / sizeof(TypPoint32);
degM = degL < degR ? degR : degL;
hdM = NewBag( T_PERM32, (unsigned long)(degM * sizeof(TypPoint32)) );
ptL = (TypPoint32*)PTR(hdL);
ptR = (TypPoint32*)PTR(hdR);
ptM = (TypPoint32*)PTR(hdM);
if ( degL <= degR ) {
for ( p = 0; p < degL; p++ )
ptM[ *(ptL++) ] = *(ptR++);
for ( p = degL; p < degR; p++ )
ptM[ p ] = *(ptR++);
}
else {
for ( p = 0; p < degR; p++ )
ptM[ *(ptL++) ] = *(ptR++);
for ( p = degR; p < degL; p++ )
ptM[ *(ptL++) ] = p;
}
return hdM;
}
TypHandle       PowPI ( hdL, hdR )
TypHandle           hdL;
TypHandle           hdR;
{
TypHandle           hdP;
TypPoint16          * ptP;
TypPoint16          * ptL;
TypPoint16          * ptKnown;
unsigned long       deg;
long                exp,  e;
unsigned long       len;
unsigned long       p,  q,  r;
deg = SIZE(hdL) / sizeof(TypPoint16);
hdP = NewBag( T_PERM16, (unsigned long)(deg * sizeof(TypPoint16)) );
if ( TYPE(hdR)==T_INT && 0<=HD_TO_INT(hdR) && HD_TO_INT(hdR)<8 ) {
exp = HD_TO_INT(hdR);
ptL = (TypPoint16*)PTR(hdL);
ptP = (TypPoint16*)PTR(hdP);
for ( p = 0; p < deg; p++ ) {
q = p;
for ( e = 0; e < exp; e++ )
q = ptL[q];
ptP[p] = q;
}
}
else if ( TYPE(hdR)==T_INT && 8 <= HD_TO_INT(hdR) ) {
if ( SIZE(HdPerm) < SIZE(hdL) )  Resize( HdPerm, SIZE(hdL) );
ptKnown = (TypPoint16*)PTR(HdPerm);
exp = HD_TO_INT(hdR);
ptL = (TypPoint16*)PTR(hdL);
ptP = (TypPoint16*)PTR(hdP);
for ( p = 0; p < deg; p++ ) {
if ( ptKnown[p] == 0 ) {
len = 1;
for ( q = ptL[p]; q != p; q = ptL[q] ) {
len++;  ptKnown[q] = 1;
}
r = p;
for ( e = 0; e < exp % len; e++ )
r = ptL[r];
ptP[p] = r;
r = ptL[r];
for ( q = ptL[p]; q != p; q = ptL[q] ) {
ptP[q] = r;
r = ptL[r];
}
}
}
for ( p = 0; p < SIZE(hdL)/sizeof(TypPoint16); p++ )
ptKnown[p] = 0;
}
else if ( TYPE(hdR)==T_INTPOS ) {
if ( SIZE(HdPerm) < SIZE(hdL) )  Resize( HdPerm, SIZE(hdL) );
ptKnown = (TypPoint16*)PTR(HdPerm);
ptL = (TypPoint16*)PTR(hdL);
ptP = (TypPoint16*)PTR(hdP);
for ( p = 0; p < deg; p++ ) {
if ( ptKnown[p] == 0 ) {
len = 1;
for ( q = ptL[p]; q != p; q = ptL[q] ) {
len++;  ptKnown[q] = 1;
}
r = p;
exp = HD_TO_INT( ModInt( hdR, INT_TO_HD(len) ) );
for ( e = 0; e < exp; e++ )
r = ptL[r];
ptP[p] = r;
r = ptL[r];
for ( q = ptL[p]; q != p; q = ptL[q] ) {
ptP[q] = r;
r = ptL[r];
}
}
}
for ( p = 0; p < SIZE(hdL)/sizeof(TypPoint16); p++ )
ptKnown[p] = 0;
}
else if ( TYPE(hdR)==T_INT && HD_TO_INT(hdR) == -1 ) {
ptL = (TypPoint16*)PTR(hdL);
ptP = (TypPoint16*)PTR(hdP);
for ( p = 0; p < deg; p++ )
ptP[ *(ptL++) ] = p;
}
else if ( TYPE(hdR)==T_INT && -8<HD_TO_INT(hdR) && HD_TO_INT(hdR)<0 ) {
exp = -HD_TO_INT(hdR);
ptL = (TypPoint16*)PTR(hdL);
ptP = (TypPoint16*)PTR(hdP);
for ( p = 0; p < deg; p++ ) {
q = p;
for ( e = 0; e < exp; e++ )
q = ptL[q];
ptP[q] = p;
}
}
else if ( TYPE(hdR)==T_INT && HD_TO_INT(hdR) <= -8 ) {
if ( SIZE(HdPerm) < SIZE(hdL) )  Resize( HdPerm, SIZE(hdL) );
ptKnown = (TypPoint16*)PTR(HdPerm);
exp = -HD_TO_INT(hdR);
ptL = (TypPoint16*)PTR(hdL);
ptP = (TypPoint16*)PTR(hdP);
for ( p = 0; p < deg; p++ ) {
if ( ptKnown[p] == 0 ) {
len = 1;
for ( q = ptL[p]; q != p; q = ptL[q] ) {
len++;  ptKnown[q] = 1;
}
r = p;
for ( e = 0; e < exp % len; e++ )
r = ptL[r];
ptP[r] = p;
r = ptL[r];
for ( q = ptL[p]; q != p; q = ptL[q] ) {
ptP[r] = q;
r = ptL[r];
}
}
}
for ( p = 0; p < SIZE(hdL)/sizeof(TypPoint16); p++ )
ptKnown[p] = 0;
}
else if ( TYPE(hdR)==T_INTNEG ) {
if ( SIZE(HdPerm) < SIZE(hdL) )  Resize( HdPerm, SIZE(hdL) );
ptKnown = (TypPoint16*)PTR(HdPerm);
hdR = ProdInt( INT_TO_HD(-1), hdR );
ptL = (TypPoint16*)PTR(hdL);
ptP = (TypPoint16*)PTR(hdP);
for ( p = 0; p < deg; p++ ) {
if ( ptKnown[p] == 0 ) {
len = 1;
for ( q = ptL[p]; q != p; q = ptL[q] ) {
len++;  ptKnown[q] = 1;
}
r = p;
exp = HD_TO_INT( ModInt( hdR, INT_TO_HD(len) ) );
for ( e = 0; e < exp % len; e++ )
r = ptL[r];
ptP[r] = p;
r = ptL[r];
for ( q = ptL[p]; q != p; q = ptL[q] ) {
ptP[r] = q;
r = ptL[r];
}
}
}
for ( p = 0; p < SIZE(hdL)/sizeof(TypPoint16); p++ )
ptKnown[p] = 0;
}
return hdP;
}
TypHandle       PowQI ( hdL, hdR )
TypHandle           hdL;
TypHandle           hdR;
{
TypHandle           hdP;
TypPoint32          * ptP;
TypPoint32          * ptL;
TypPoint32          * ptKnown;
unsigned long       deg;
long                exp,  e;
unsigned long       len;
unsigned long       p,  q,  r;
deg = SIZE(hdL) / sizeof(TypPoint32);
hdP = NewBag( T_PERM32, (unsigned long)(deg * sizeof(TypPoint32)) );
if ( TYPE(hdR)==T_INT && 0<=HD_TO_INT(hdR) && HD_TO_INT(hdR)<8 ) {
exp = HD_TO_INT(hdR);
ptL = (TypPoint32*)PTR(hdL);
ptP = (TypPoint32*)PTR(hdP);
for ( p = 0; p < deg; p++ ) {
q = p;
for ( e = 0; e < exp; e++ )
q = ptL[q];
ptP[p] = q;
}
}
else if ( TYPE(hdR)==T_INT && 8 <= HD_TO_INT(hdR) ) {
if ( SIZE(HdPerm) < SIZE(hdL) )  Resize( HdPerm, SIZE(hdL) );
ptKnown = (TypPoint32*)PTR(HdPerm);
exp = HD_TO_INT(hdR);
ptL = (TypPoint32*)PTR(hdL);
ptP = (TypPoint32*)PTR(hdP);
for ( p = 0; p < deg; p++ ) {
if ( ptKnown[p] == 0 ) {
len = 1;
for ( q = ptL[p]; q != p; q = ptL[q] ) {
len++;  ptKnown[q] = 1;
}
r = p;
for ( e = 0; e < exp % len; e++ )
r = ptL[r];
ptP[p] = r;
r = ptL[r];
for ( q = ptL[p]; q != p; q = ptL[q] ) {
ptP[q] = r;
r = ptL[r];
}
}
}
for ( p = 0; p < SIZE(hdL)/sizeof(TypPoint32); p++ )
ptKnown[p] = 0;
}
else if ( TYPE(hdR)==T_INTPOS ) {
if ( SIZE(HdPerm) < SIZE(hdL) )  Resize( HdPerm, SIZE(hdL) );
ptKnown = (TypPoint32*)PTR(HdPerm);
ptL = (TypPoint32*)PTR(hdL);
ptP = (TypPoint32*)PTR(hdP);
for ( p = 0; p < deg; p++ ) {
if ( ptKnown[p] == 0 ) {
len = 1;
for ( q = ptL[p]; q != p; q = ptL[q] ) {
len++;  ptKnown[q] = 1;
}
r = p;
exp = HD_TO_INT( ModInt( hdR, INT_TO_HD(len) ) );
for ( e = 0; e < exp; e++ )
r = ptL[r];
ptP[p] = r;
r = ptL[r];
for ( q = ptL[p]; q != p; q = ptL[q] ) {
ptP[q] = r;
r = ptL[r];
}
}
}
for ( p = 0; p < SIZE(hdL)/sizeof(TypPoint32); p++ )
ptKnown[p] = 0;
}
else if ( TYPE(hdR)==T_INT && HD_TO_INT(hdR) == -1 ) {
ptL = (TypPoint32*)PTR(hdL);
ptP = (TypPoint32*)PTR(hdP);
for ( p = 0; p < deg; p++ )
ptP[ *(ptL++) ] = p;
}
else if ( TYPE(hdR)==T_INT && -8<HD_TO_INT(hdR) && HD_TO_INT(hdR)<0 ) {
exp = -HD_TO_INT(hdR);
ptL = (TypPoint32*)PTR(hdL);
ptP = (TypPoint32*)PTR(hdP);
for ( p = 0; p < deg; p++ ) {
q = p;
for ( e = 0; e < exp; e++ )
q = ptL[q];
ptP[q] = p;
}
}
else if ( TYPE(hdR)==T_INT && HD_TO_INT(hdR) <= -8 ) {
if ( SIZE(HdPerm) < SIZE(hdL) )  Resize( HdPerm, SIZE(hdL) );
ptKnown = (TypPoint32*)PTR(HdPerm);
exp = -HD_TO_INT(hdR);
ptL = (TypPoint32*)PTR(hdL);
ptP = (TypPoint32*)PTR(hdP);
for ( p = 0; p < deg; p++ ) {
if ( ptKnown[p] == 0 ) {
len = 1;
for ( q = ptL[p]; q != p; q = ptL[q] ) {
len++;  ptKnown[q] = 1;
}
r = p;
for ( e = 0; e < exp % len; e++ )
r = ptL[r];
ptP[r] = p;
r = ptL[r];
for ( q = ptL[p]; q != p; q = ptL[q] ) {
ptP[r] = q;
r = ptL[r];
}
}
}
for ( p = 0; p < SIZE(hdL)/sizeof(TypPoint32); p++ )
ptKnown[p] = 0;
}
else if ( TYPE(hdR)==T_INTNEG ) {
if ( SIZE(HdPerm) < SIZE(hdL) )  Resize( HdPerm, SIZE(hdL) );
ptKnown = (TypPoint32*)PTR(HdPerm);
hdR = ProdInt( INT_TO_HD(-1), hdR );
ptL = (TypPoint32*)PTR(hdL);
ptP = (TypPoint32*)PTR(hdP);
for ( p = 0; p < deg; p++ ) {
if ( ptKnown[p] == 0 ) {
len = 1;
for ( q = ptL[p]; q != p; q = ptL[q] ) {
len++;  ptKnown[q] = 1;
}
r = p;
exp = HD_TO_INT( ModInt( hdR, INT_TO_HD(len) ) );
for ( e = 0; e < exp % len; e++ )
r = ptL[r];
ptP[r] = p;
r = ptL[r];
for ( q = ptL[p]; q != p; q = ptL[q] ) {
ptP[r] = q;
r = ptL[r];
}
}
}
for ( p = 0; p < SIZE(hdL)/sizeof(TypPoint32); p++ )
ptKnown[p] = 0;
}
return hdP;
}
TypHandle       PowIP ( hdL, hdR )
TypHandle           hdL;
TypHandle           hdR;
{
long                img;
if ( TYPE(hdL) == T_INTPOS )
return hdL;
img = HD_TO_INT( hdL );
if ( img <= 0 )
return Error("Perm Op: point must be positive (%d)",img,0L);
if ( img <= SIZE(hdR)/sizeof(TypPoint16) ) {
img = ((TypPoint16*)PTR(hdR))[img-1] + 1;
}
return INT_TO_HD(img);
}
TypHandle       PowIQ ( hdL, hdR )
TypHandle           hdL;
TypHandle           hdR;
{
long                img;
if ( TYPE(hdL) == T_INTPOS )
return hdL;
img = HD_TO_INT( hdL );
if ( img <= 0 )
return Error("Perm Op: point must be positive (%d)",img,0L);
if ( img <= SIZE(hdR)/sizeof(TypPoint32) ) {
img = ((TypPoint32*)PTR(hdR))[img-1] + 1;
}
return INT_TO_HD(img);
}
TypHandle       QuoIP ( hdL, hdR )
TypHandle           hdL;
TypHandle           hdR;
{
long                pre;
long                img;
TypPoint16          * ptR;
if ( TYPE(hdL) == T_INTPOS )
return hdL;
img = HD_TO_INT(hdL);
if ( img <= 0 )
return Error("PermOps: %d must be positive",HD_TO_INT(hdL),0L);
pre = img;
ptR = (TypPoint16*)PTR(hdR);
if ( img <= SIZE(hdR)/sizeof(TypPoint16) ) {
while ( ptR[ pre-1 ] != img-1 )
pre = ptR[ pre-1 ] + 1;
}
return INT_TO_HD(pre);
}
TypHandle       QuoIQ ( hdL, hdR )
TypHandle           hdL;
TypHandle           hdR;
{
long                pre;
long                img;
TypPoint32          * ptR;
if ( TYPE(hdL) == T_INTPOS )
return hdL;
img = HD_TO_INT(hdL);
if ( img <= 0 )
return Error("PermOps: %d must be positive",HD_TO_INT(hdL),0L);
pre = img;
ptR = (TypPoint32*)PTR(hdR);
if ( img <= SIZE(hdR)/sizeof(TypPoint32) ) {
while ( ptR[ pre-1 ] != img-1 )
pre = ptR[ pre-1 ] + 1;
}
return INT_TO_HD(pre);
}
TypHandle       PowPP ( hdL, hdR )
TypHandle           hdL;
TypHandle           hdR;
{
TypHandle           hdC;
unsigned long       degC;
TypPoint16          * ptC;
unsigned long       degL;
TypPoint16          * ptL;
unsigned long       degR;
TypPoint16          * ptR;
unsigned long       p;
degL = SIZE(hdL) / sizeof(TypPoint16);
degR = SIZE(hdR) / sizeof(TypPoint16);
degC = degL < degR ? degR : degL;
hdC = NewBag( T_PERM16, (unsigned long)(degC * sizeof(TypPoint16)) );
ptL = (TypPoint16*)PTR(hdL);
ptR = (TypPoint16*)PTR(hdR);
ptC = (TypPoint16*)PTR(hdC);
if ( degL == degR ) {
for ( p = 0; p < degC; p++ )
ptC[ ptR[p] ] = ptR[ ptL[p] ];
}
else {
for ( p = 0; p < degC; p++ )
ptC[ IMAGE(p,ptR,degR) ] = IMAGE( IMAGE(p,ptL,degL), ptR, degR );
}
return hdC;
}
TypHandle       PowPQ ( hdL, hdR )
TypHandle           hdL;
TypHandle           hdR;
{
TypHandle           hdC;
unsigned long       degC;
TypPoint32          * ptC;
unsigned long       degL;
TypPoint16          * ptL;
unsigned long       degR;
TypPoint32          * ptR;
unsigned long       p;
degL = SIZE(hdL) / sizeof(TypPoint16);
degR = SIZE(hdR) / sizeof(TypPoint32);
degC = degL < degR ? degR : degL;
hdC = NewBag( T_PERM32, (unsigned long)(degC * sizeof(TypPoint32)) );
ptL = (TypPoint16*)PTR(hdL);
ptR = (TypPoint32*)PTR(hdR);
ptC = (TypPoint32*)PTR(hdC);
if ( degL == degR ) {
for ( p = 0; p < degC; p++ )
ptC[ ptR[p] ] = ptR[ ptL[p] ];
}
else {
for ( p = 0; p < degC; p++ )
ptC[ IMAGE(p,ptR,degR) ] = IMAGE( IMAGE(p,ptL,degL), ptR, degR );
}
return hdC;
}
TypHandle       PowQP ( hdL, hdR )
TypHandle           hdL;
TypHandle           hdR;
{
TypHandle           hdC;
unsigned long       degC;
TypPoint32          * ptC;
unsigned long       degL;
TypPoint32          * ptL;
unsigned long       degR;
TypPoint16          * ptR;
unsigned long       p;
degL = SIZE(hdL) / sizeof(TypPoint32);
degR = SIZE(hdR) / sizeof(TypPoint16);
degC = degL < degR ? degR : degL;
hdC = NewBag( T_PERM32, (unsigned long)(degC * sizeof(TypPoint32)) );
ptL = (TypPoint32*)PTR(hdL);
ptR = (TypPoint16*)PTR(hdR);
ptC = (TypPoint32*)PTR(hdC);
if ( degL == degR ) {
for ( p = 0; p < degC; p++ )
ptC[ ptR[p] ] = ptR[ ptL[p] ];
}
else {
for ( p = 0; p < degC; p++ )
ptC[ IMAGE(p,ptR,degR) ] = IMAGE( IMAGE(p,ptL,degL), ptR, degR );
}
return hdC;
}
TypHandle       PowQQ ( hdL, hdR )
TypHandle           hdL;
TypHandle           hdR;
{
TypHandle           hdC;
unsigned long       degC;
TypPoint32          * ptC;
unsigned long       degL;
TypPoint32          * ptL;
unsigned long       degR;
TypPoint32          * ptR;
unsigned long       p;
degL = SIZE(hdL) / sizeof(TypPoint32);
degR = SIZE(hdR) / sizeof(TypPoint32);
degC = degL < degR ? degR : degL;
hdC = NewBag( T_PERM32, (unsigned long)(degC * sizeof(TypPoint32)) );
ptL = (TypPoint32*)PTR(hdL);
ptR = (TypPoint32*)PTR(hdR);
ptC = (TypPoint32*)PTR(hdC);
if ( degL == degR ) {
for ( p = 0; p < degC; p++ )
ptC[ ptR[p] ] = ptR[ ptL[p] ];
}
else {
for ( p = 0; p < degC; p++ )
ptC[ IMAGE(p,ptR,degR) ] = IMAGE( IMAGE(p,ptL,degL), ptR, degR );
}
return hdC;
}
TypHandle       CommPP ( hdL, hdR )
TypHandle           hdL;
TypHandle           hdR;
{
TypHandle           hdC;
unsigned long       degC;
TypPoint16          * ptC;
unsigned long       degL;
TypPoint16          * ptL;
unsigned long       degR;
TypPoint16          * ptR;
unsigned long       p;
degL = SIZE(hdL) / sizeof(TypPoint16);
degR = SIZE(hdR) / sizeof(TypPoint16);
degC = degL < degR ? degR : degL;
hdC = NewBag( T_PERM16, (unsigned long)(degC * sizeof(TypPoint16)) );
ptL = (TypPoint16*)PTR(hdL);
ptR = (TypPoint16*)PTR(hdR);
ptC = (TypPoint16*)PTR(hdC);
if ( degL == degR ) {
for ( p = 0; p < degC; p++ )
ptC[ ptL[ ptR[ p ] ] ] = ptR[ ptL[ p ] ];
}
else {
for ( p = 0; p < degC; p++ )
ptC[ IMAGE( IMAGE(p,ptR,degR), ptL, degL ) ]
= IMAGE( IMAGE(p,ptL,degL), ptR, degR );
}
return hdC;
}
TypHandle       CommPQ ( hdL, hdR )
TypHandle           hdL;
TypHandle           hdR;
{
TypHandle           hdC;
unsigned long       degC;
TypPoint32          * ptC;
unsigned long       degL;
TypPoint16          * ptL;
unsigned long       degR;
TypPoint32          * ptR;
unsigned long       p;
degL = SIZE(hdL) / sizeof(TypPoint16);
degR = SIZE(hdR) / sizeof(TypPoint32);
degC = degL < degR ? degR : degL;
hdC = NewBag( T_PERM32, (unsigned long)(degC * sizeof(TypPoint32)) );
ptL = (TypPoint16*)PTR(hdL);
ptR = (TypPoint32*)PTR(hdR);
ptC = (TypPoint32*)PTR(hdC);
if ( degL == degR ) {
for ( p = 0; p < degC; p++ )
ptC[ ptL[ ptR[ p ] ] ] = ptR[ ptL[ p ] ];
}
else {
for ( p = 0; p < degC; p++ )
ptC[ IMAGE( IMAGE(p,ptR,degR), ptL, degL ) ]
= IMAGE( IMAGE(p,ptL,degL), ptR, degR );
}
return hdC;
}
TypHandle       CommQP ( hdL, hdR )
TypHandle           hdL;
TypHandle           hdR;
{
TypHandle           hdC;
unsigned long       degC;
TypPoint32          * ptC;
unsigned long       degL;
TypPoint32          * ptL;
unsigned long       degR;
TypPoint16          * ptR;
unsigned long       p;
degL = SIZE(hdL) / sizeof(TypPoint32);
degR = SIZE(hdR) / sizeof(TypPoint16);
degC = degL < degR ? degR : degL;
hdC = NewBag( T_PERM32, (unsigned long)(degC * sizeof(TypPoint32)) );
ptL = (TypPoint32*)PTR(hdL);
ptR = (TypPoint16*)PTR(hdR);
ptC = (TypPoint32*)PTR(hdC);
if ( degL == degR ) {
for ( p = 0; p < degC; p++ )
ptC[ ptL[ ptR[ p ] ] ] = ptR[ ptL[ p ] ];
}
else {
for ( p = 0; p < degC; p++ )
ptC[ IMAGE( IMAGE(p,ptR,degR), ptL, degL ) ]
= IMAGE( IMAGE(p,ptL,degL), ptR, degR );
}
return hdC;
}
TypHandle       CommQQ ( hdL, hdR )
TypHandle           hdL;
TypHandle           hdR;
{
TypHandle           hdC;
unsigned long       degC;
TypPoint32          * ptC;
unsigned long       degL;
TypPoint32          * ptL;
unsigned long       degR;
TypPoint32          * ptR;
unsigned long       p;
degL = SIZE(hdL) / sizeof(TypPoint32);
degR = SIZE(hdR) / sizeof(TypPoint32);
degC = degL < degR ? degR : degL;
hdC = NewBag( T_PERM32, (unsigned long)(degC * sizeof(TypPoint32)) );
ptL = (TypPoint32*)PTR(hdL);
ptR = (TypPoint32*)PTR(hdR);
ptC = (TypPoint32*)PTR(hdC);
if ( degL == degR ) {
for ( p = 0; p < degC; p++ )
ptC[ ptL[ ptR[ p ] ] ] = ptR[ ptL[ p ] ];
}
else {
for ( p = 0; p < degC; p++ )
ptC[ IMAGE( IMAGE(p,ptR,degR), ptL, degL ) ]
= IMAGE( IMAGE(p,ptL,degL), ptR, degR );
}
return hdC;
}
TypHandle       EqPP ( hdL, hdR )
TypHandle           hdL;
TypHandle           hdR;
{
unsigned long       degL;
TypPoint16          * ptL;
unsigned long       degR;
TypPoint16          * ptR;
unsigned long       p;
degL = SIZE(hdL) / sizeof(TypPoint16);
degR = SIZE(hdR) / sizeof(TypPoint16);
ptL = (TypPoint16*)PTR(hdL);
ptR = (TypPoint16*)PTR(hdR);
if ( degL <= degR ) {
for ( p = 0; p < degL; p++ )
if ( *(ptL++) != *(ptR++) )
return HdFalse;
for ( p = degL; p < degR; p++ )
if (        p != *(ptR++) )
return HdFalse;
}
else {
for ( p = 0; p < degR; p++ )
if ( *(ptL++) != *(ptR++) )
return HdFalse;
for ( p = degR; p < degL; p++ )
if ( *(ptL++) !=        p )
return HdFalse;
}
return HdTrue;
}
TypHandle       EqPQ ( hdL, hdR )
TypHandle           hdL;
TypHandle           hdR;
{
unsigned long       degL;
TypPoint16          * ptL;
unsigned long       degR;
TypPoint32          * ptR;
unsigned long       p;
degL = SIZE(hdL) / sizeof(TypPoint16);
degR = SIZE(hdR) / sizeof(TypPoint32);
ptL = (TypPoint16*)PTR(hdL);
ptR = (TypPoint32*)PTR(hdR);
if ( degL <= degR ) {
for ( p = 0; p < degL; p++ )
if ( *(ptL++) != *(ptR++) )
return HdFalse;
for ( p = degL; p < degR; p++ )
if (        p != *(ptR++) )
return HdFalse;
}
else {
for ( p = 0; p < degR; p++ )
if ( *(ptL++) != *(ptR++) )
return HdFalse;
for ( p = degR; p < degL; p++ )
if ( *(ptL++) !=        p )
return HdFalse;
}
return HdTrue;
}
TypHandle       EqQP ( hdL, hdR )
TypHandle           hdL;
TypHandle           hdR;
{
unsigned long       degL;
TypPoint32          * ptL;
unsigned long       degR;
TypPoint16          * ptR;
unsigned long       p;
degL = SIZE(hdL) / sizeof(TypPoint32);
degR = SIZE(hdR) / sizeof(TypPoint16);
ptL = (TypPoint32*)PTR(hdL);
ptR = (TypPoint16*)PTR(hdR);
if ( degL <= degR ) {
for ( p = 0; p < degL; p++ )
if ( *(ptL++) != *(ptR++) )
return HdFalse;
for ( p = degL; p < degR; p++ )
if (        p != *(ptR++) )
return HdFalse;
}
else {
for ( p = 0; p < degR; p++ )
if ( *(ptL++) != *(ptR++) )
return HdFalse;
for ( p = degR; p < degL; p++ )
if ( *(ptL++) !=        p )
return HdFalse;
}
return HdTrue;
}
TypHandle       EqQQ ( hdL, hdR )
TypHandle           hdL;
TypHandle           hdR;
{
unsigned long       degL;
TypPoint32          * ptL;
unsigned long       degR;
TypPoint32          * ptR;
unsigned long       p;
degL = SIZE(hdL) / sizeof(TypPoint32);
degR = SIZE(hdR) / sizeof(TypPoint32);
ptL = (TypPoint32*)PTR(hdL);
ptR = (TypPoint32*)PTR(hdR);
if ( degL <= degR ) {
for ( p = 0; p < degL; p++ )
if ( *(ptL++) != *(ptR++) )
return HdFalse;
for ( p = degL; p < degR; p++ )
if (        p != *(ptR++) )
return HdFalse;
}
else {
for ( p = 0; p < degR; p++ )
if ( *(ptL++) != *(ptR++) )
return HdFalse;
for ( p = degR; p < degL; p++ )
if ( *(ptL++) !=        p )
return HdFalse;
}
return HdTrue;
}
TypHandle       LtPP ( hdL, hdR )
TypHandle           hdL;
TypHandle           hdR;
{
unsigned long       degL;
TypPoint16          * ptL;
unsigned long       degR;
TypPoint16          * ptR;
unsigned long       p;
degL = SIZE(hdL) / sizeof(TypPoint16);
degR = SIZE(hdR) / sizeof(TypPoint16);
ptL = (TypPoint16*)PTR(hdL);
ptR = (TypPoint16*)PTR(hdR);
if ( degL <= degR ) {
for ( p = 0; p < degL; p++ )
if ( *(ptL++) != *(ptR++) )
if ( *(--ptL) < *(--ptR) )  return HdTrue ;
else                        return HdFalse;
for ( p = degL; p < degR; p++ )
if (        p != *(ptR++) )
if (        p < *(--ptR) )  return HdTrue ;
else                        return HdFalse;
}
else {
for ( p = 0; p < degR; p++ )
if ( *(ptL++) != *(ptR++) )
if ( *(--ptL) < *(--ptR) )  return HdTrue ;
else                        return HdFalse;
for ( p = degR; p < degL; p++ )
if ( *(ptL++) != p )
if ( *(--ptL) <        p )  return HdTrue ;
else                        return HdFalse;
}
return HdFalse;
}
TypHandle       LtPQ ( hdL, hdR )
TypHandle           hdL;
TypHandle           hdR;
{
unsigned long       degL;
TypPoint16          * ptL;
unsigned long       degR;
TypPoint32          * ptR;
unsigned long       p;
degL = SIZE(hdL) / sizeof(TypPoint16);
degR = SIZE(hdR) / sizeof(TypPoint32);
ptL = (TypPoint16*)PTR(hdL);
ptR = (TypPoint32*)PTR(hdR);
if ( degL <= degR ) {
for ( p = 0; p < degL; p++ )
if ( *(ptL++) != *(ptR++) )
if ( *(--ptL) < *(--ptR) )  return HdTrue ;
else                        return HdFalse;
for ( p = degL; p < degR; p++ )
if (        p != *(ptR++) )
if (        p < *(--ptR) )  return HdTrue ;
else                        return HdFalse;
}
else {
for ( p = 0; p < degR; p++ )
if ( *(ptL++) != *(ptR++) )
if ( *(--ptL) < *(--ptR) )  return HdTrue ;
else                        return HdFalse;
for ( p = degR; p < degL; p++ )
if ( *(ptL++) != p )
if ( *(--ptL) <        p )  return HdTrue ;
else                        return HdFalse;
}
return HdFalse;
}
TypHandle       LtQP ( hdL, hdR )
TypHandle           hdL;
TypHandle           hdR;
{
unsigned long       degL;
TypPoint32          * ptL;
unsigned long       degR;
TypPoint16          * ptR;
unsigned long       p;
degL = SIZE(hdL) / sizeof(TypPoint32);
degR = SIZE(hdR) / sizeof(TypPoint16);
ptL = (TypPoint32*)PTR(hdL);
ptR = (TypPoint16*)PTR(hdR);
if ( degL <= degR ) {
for ( p = 0; p < degL; p++ )
if ( *(ptL++) != *(ptR++) )
if ( *(--ptL) < *(--ptR) )  return HdTrue ;
else                        return HdFalse;
for ( p = degL; p < degR; p++ )
if (        p != *(ptR++) )
if (        p < *(--ptR) )  return HdTrue ;
else                        return HdFalse;
}
else {
for ( p = 0; p < degR; p++ )
if ( *(ptL++) != *(ptR++) )
if ( *(--ptL) < *(--ptR) )  return HdTrue ;
else                        return HdFalse;
for ( p = degR; p < degL; p++ )
if ( *(ptL++) != p )
if ( *(--ptL) <        p )  return HdTrue ;
else                        return HdFalse;
}
return HdFalse;
}
TypHandle       LtQQ ( hdL, hdR )
TypHandle           hdL;
TypHandle           hdR;
{
unsigned long       degL;
TypPoint32          * ptL;
unsigned long       degR;
TypPoint32          * ptR;
unsigned long       p;
degL = SIZE(hdL) / sizeof(TypPoint32);
degR = SIZE(hdR) / sizeof(TypPoint32);
ptL = (TypPoint32*)PTR(hdL);
ptR = (TypPoint32*)PTR(hdR);
if ( degL <= degR ) {
for ( p = 0; p < degL; p++ )
if ( *(ptL++) != *(ptR++) )
if ( *(--ptL) < *(--ptR) )  return HdTrue ;
else                        return HdFalse;
for ( p = degL; p < degR; p++ )
if (        p != *(ptR++) )
if (        p < *(--ptR) )  return HdTrue ;
else                        return HdFalse;
}
else {
for ( p = 0; p < degR; p++ )
if ( *(ptL++) != *(ptR++) )
if ( *(--ptL) < *(--ptR) )  return HdTrue ;
else                        return HdFalse;
for ( p = degR; p < degL; p++ )
if ( *(ptL++) != p )
if ( *(--ptL) <        p )  return HdTrue ;
else                        return HdFalse;
}
return HdFalse;
}
void            PrPermP ( hdPerm )
TypHandle           hdPerm;
{
unsigned long       degPerm;
TypPoint16          * ptPerm;
unsigned long       p,  q;
short               isId;
char                * fmt1, * fmt2;
degPerm = SIZE(hdPerm) / sizeof(TypPoint16);
if      ( degPerm <    10 ) { fmt1 = "%>(%>%1d%<"; fmt2 = ",%>%1d%<"; }
else if ( degPerm <   100 ) { fmt1 = "%>(%>%2d%<"; fmt2 = ",%>%2d%<"; }
else if ( degPerm <  1000 ) { fmt1 = "%>(%>%3d%<"; fmt2 = ",%>%3d%<"; }
else if ( degPerm < 10000 ) { fmt1 = "%>(%>%4d%<"; fmt2 = ",%>%4d%<"; }
else                        { fmt1 = "%>(%>%5d%<"; fmt2 = ",%>%5d%<"; }
isId = 1;
ptPerm = (TypPoint16*)PTR(hdPerm);
for ( p = 0; p < degPerm; p++ ) {
q = ptPerm[p];
while ( p < q )  q = ptPerm[q];
if ( p == q && ptPerm[p] != p ) {
isId = 0;
Pr(fmt1,(long)(p+1),0L);
for ( q = ptPerm[p]; q != p; q = ptPerm[q] )
Pr(fmt2,(long)(q+1),0L);
Pr("%<)",0L,0L);
}
}
if ( isId )  Pr("()",0L,0L);
}
void            PrPermQ ( hdPerm )
TypHandle           hdPerm;
{
unsigned long       degPerm;
TypPoint32          * ptPerm;
unsigned long       p,  q;
short               isId;
char                * fmt1, * fmt2;
degPerm = SIZE(hdPerm) / sizeof(TypPoint32);
if      ( degPerm <    10 ) { fmt1 = "%>(%>%1d%<"; fmt2 = ",%>%1d%<"; }
else if ( degPerm <   100 ) { fmt1 = "%>(%>%2d%<"; fmt2 = ",%>%2d%<"; }
else if ( degPerm <  1000 ) { fmt1 = "%>(%>%3d%<"; fmt2 = ",%>%3d%<"; }
else if ( degPerm < 10000 ) { fmt1 = "%>(%>%4d%<"; fmt2 = ",%>%4d%<"; }
else                        { fmt1 = "%>(%>%5d%<"; fmt2 = ",%>%5d%<"; }
isId = 1;
ptPerm = (TypPoint32*)PTR(hdPerm);
for ( p = 0; p < degPerm; p++ ) {
q = ptPerm[p];
while ( p < q )  q = ptPerm[q];
if ( p == q && ptPerm[p] != p ) {
isId = 0;
Pr(fmt1,(long)(p+1),0L);
for ( q = ptPerm[p]; q != p; q = ptPerm[q] )
Pr(fmt2,(long)(q+1),0L);
Pr("%<)",0L,0L);
}
}
if ( isId )  Pr("()",0L,0L);
}
void            PrMakeperm ( hdPerm )
TypHandle           hdPerm;
{
TypHandle           hdCyc;
unsigned long       i,  k;
for ( i = 0; i < SIZE(hdPerm)/SIZE_HD; i++ ) {
Pr("%>(",0L,0L);
hdCyc = PTR(hdPerm)[i];
for ( k = 0; k < SIZE(hdCyc)/SIZE_HD; k++ ) {
Pr("%>",0L,0L);
Print( PTR(hdCyc)[k] );
Pr("%<",0L,0L);
if ( k < SIZE(hdCyc)/SIZE_HD-1 )  Pr(",",0L,0L);
}
Pr("%<)",0L,0L);
}
}
TypHandle       FunIsPerm ( hdCall )
TypHandle           hdCall;
{
TypHandle           hdObj;
if ( SIZE(hdCall) != 2 * SIZE_HD )
return Error("usage: IsPerm( <obj> )",0L,0L);
hdObj = EVAL( PTR(hdCall)[1] );
if ( hdObj == HdVoid )
return Error("IsPerm: function must return a value",0L,0L);
if ( TYPE(hdObj) == T_PERM16 || TYPE(hdObj) == T_PERM32 )
return HdTrue;
else
return HdFalse;
}
TypHandle       FunPermList ( hdCall )
TypHandle           hdCall;
{
TypHandle           hdPerm;
TypPoint16          * ptPerm16;
TypPoint32          * ptPerm32;
unsigned long       degPerm;
TypHandle           hdList;
TypHandle           * ptList;
TypPoint16          * ptTmp16;
TypPoint32          * ptTmp32;
long                i,  k;
if ( SIZE(hdCall) != 2 * SIZE_HD )
return Error("usage: PermList( <list> )",0L,0L);
hdList = EVAL( PTR(hdCall)[1] );
if ( ! IS_LIST( hdList ) )
return Error("usage: PermList( <list> )",0L,0L);
PLAIN_LIST( hdList );
if ( LEN_LIST( hdList ) <= 65536 ) {
degPerm = LEN_LIST( hdList );
if ( SIZE(HdPerm) < degPerm * sizeof(TypPoint16) )
Resize( HdPerm, degPerm * sizeof(TypPoint16) );
hdPerm   = NewBag( T_PERM16, degPerm * sizeof(TypPoint16) );
ptPerm16 = (TypPoint16*)PTR(hdPerm);
ptList   = PTR(hdList);
ptTmp16  = (TypPoint16*)PTR(HdPerm);
for ( i = 1; i <= degPerm; i++ ) {
if ( ptList[i] == 0 ) {
for ( i = 1; i <= degPerm; i++ )  ptTmp16[i-1] = 0;
return Error("PermList: <list>[%d] must be defined",(long)i,0L);
}
if ( TYPE(ptList[i]) != T_INT ) {
for ( i = 1; i <= degPerm; i++ )  ptTmp16[i-1] = 0;
return Error("PermList: <list>[%d] must be integer",(long)i,0L);
}
k = HD_TO_INT(ptList[i]);
if ( k <= 0 || degPerm < k ) {
for ( i = 1; i <= degPerm; i++ )  ptTmp16[i-1] = 0;
return Error("PermList: <list>[%d] must lie in [1..%d]",
(long)i, (long)degPerm );
}
if ( ptTmp16[k-1] != 0 ) {
for ( i = 1; i <= degPerm; i++ )  ptTmp16[i-1] = 0;
return Error("PermList: <point> %d must occur only once",
(long)k, 0L );
}
ptTmp16[k-1] = 1;
ptPerm16[i-1] = k-1;
}
for ( i = 1; i <= degPerm; i++ )
ptTmp16[i-1] = 0;
}
else {
degPerm = LEN_LIST( hdList );
if ( SIZE(HdPerm) < degPerm * sizeof(TypPoint32) )
Resize( HdPerm, degPerm * sizeof(TypPoint32) );
hdPerm   = NewBag( T_PERM32, degPerm * sizeof(TypPoint32) );
ptPerm32 = (TypPoint32*)PTR(hdPerm);
ptList   = PTR(hdList);
ptTmp32  = (TypPoint32*)PTR(HdPerm);
for ( i = 1; i <= degPerm; i++ ) {
if ( ptList[i] == 0 ) {
for ( i = 1; i <= degPerm; i++ )  ptTmp32[i-1] = 0;
return Error("PermList: <list>[%d] must be defined",(long)i,0L);
}
if ( TYPE(ptList[i]) != T_INT ) {
for ( i = 1; i <= degPerm; i++ )  ptTmp32[i-1] = 0;
return Error("PermList: <list>[%d] must be integer",(long)i,0L);
}
k = HD_TO_INT(ptList[i]);
if ( k <= 0 || degPerm < k ) {
for ( i = 1; i <= degPerm; i++ )  ptTmp32[i-1] = 0;
return Error("PermList: <list>[%d] must lie in [1..%d]",
(long)i, (long)degPerm );
}
if ( ptTmp32[k-1] != 0 ) {
for ( i = 1; i <= degPerm; i++ )  ptTmp32[i-1] = 0;
return Error("PermList: <point> %d must occur only once",
(long)k, 0L );
}
ptTmp32[k-1] = 1;
ptPerm32[i-1] = k-1;
}
for ( i = 1; i <= degPerm; i++ )
ptTmp32[i-1] = 0;
}
return hdPerm;
}
TypHandle       FunLargestMovedPointPerm ( hdCall )
TypHandle           hdCall;
{
unsigned long       sup;
TypHandle           hdPerm;
TypPoint16          * ptPerm16;
TypPoint32          * ptPerm32;
if ( SIZE(hdCall) != 2 * SIZE_HD )
return Error("usage: LargestMovedPointPerm( <perm> )",0L,0L);
hdPerm = EVAL( PTR(hdCall)[1] );
if ( TYPE(hdPerm) != T_PERM16 && TYPE(hdPerm) != T_PERM32 )
return Error("usage: LargestMovedPointPerm( <perm> )",0L,0L);
if ( TYPE(hdPerm) == T_PERM16 ) {
ptPerm16 = (TypPoint16*)PTR(hdPerm);
for ( sup = SIZE(hdPerm)/sizeof(TypPoint16); 1 <= sup; sup-- ) {
if ( ptPerm16[sup-1] != sup-1 )
break;
}
}
else {
ptPerm32 = (TypPoint32*)PTR(hdPerm);
for ( sup = SIZE(hdPerm)/sizeof(TypPoint32); 1 <= sup; sup-- ) {
if ( ptPerm32[sup-1] != sup-1 )
break;
}
}
if ( sup == 0 )
return Error("LargestMovedPointPerm: <perm> must not be the identity",
0L,0L);
return INT_TO_HD( sup );
}
TypHandle       FunCycleLengthPermInt ( hdCall )
TypHandle           hdCall;
{
TypHandle           hdPerm;
TypPoint16          * ptPerm16;
TypPoint32          * ptPerm32;
unsigned long       deg;
TypHandle           hdPnt;
unsigned long       pnt;
unsigned long       len;
unsigned long       p;
if ( SIZE(hdCall) != 3 * SIZE_HD )
return Error("usage: CycleLengthPermInt( <perm>, <point> )",0L,0L);
hdPerm = EVAL( PTR(hdCall)[1] );
if ( TYPE(hdPerm) != T_PERM16 && TYPE(hdPerm) != T_PERM32 )
return Error("CycleLengthPermInt: <perm> must be a permutation",0L,0L);
hdPnt = EVAL( PTR(hdCall)[2] );
if ( TYPE(hdPnt) != T_INT || HD_TO_INT(hdPnt) <= 0 )
return Error("CycleLengthPermInt: <point> must be an integer",0L,0L);
if ( TYPE(hdPerm) == T_PERM16 ) {
ptPerm16 = (TypPoint16*)PTR(hdPerm);
deg = SIZE(hdPerm)/sizeof(TypPoint16);
pnt = HD_TO_INT(hdPnt)-1;
len = 1;
if ( pnt < deg ) {
for ( p = ptPerm16[pnt]; p != pnt; p = ptPerm16[p] )
len++;
}
}
else {
ptPerm32 = (TypPoint32*)PTR(hdPerm);
deg = SIZE(hdPerm)/sizeof(TypPoint32);
pnt = HD_TO_INT(hdPnt)-1;
len = 1;
if ( pnt < deg ) {
for ( p = ptPerm32[pnt]; p != pnt; p = ptPerm32[p] )
len++;
}
}
return INT_TO_HD(len);
}
TypHandle       FunCyclePermInt ( hdCall )
TypHandle           hdCall;
{
TypHandle           hdList;
TypHandle           * ptList;
TypHandle           hdPerm;
TypPoint16          * ptPerm16;
TypPoint32          * ptPerm32;
unsigned long       deg;
TypHandle           hdPnt;
unsigned long       pnt;
unsigned long       len;
unsigned long       p;
if ( SIZE(hdCall) != 3 * SIZE_HD )
return Error("usage: CyclePermInt( <perm>, <point> )",0L,0L);
hdPerm = EVAL( PTR(hdCall)[1] );
if ( TYPE(hdPerm) != T_PERM16 && TYPE(hdPerm) != T_PERM32 )
return Error("CyclePermInt: <perm> must be a permutation",0L,0L);
hdPnt = EVAL( PTR(hdCall)[2] );
if ( TYPE(hdPnt) != T_INT || HD_TO_INT(hdPnt) <= 0 )
return Error("CyclePermInt: <point> must be an integer",0L,0L);
if ( TYPE(hdPerm) == T_PERM16 ) {
ptPerm16 = (TypPoint16*)PTR(hdPerm);
deg = SIZE(hdPerm)/sizeof(TypPoint16);
pnt = HD_TO_INT(hdPnt)-1;
len = 1;
if ( pnt < deg ) {
for ( p = ptPerm16[pnt]; p != pnt; p = ptPerm16[p] )
len++;
}
hdList = NewBag( T_LIST, SIZE_HD + len*SIZE_HD );
PTR(hdList)[0] = INT_TO_HD( len );
ptList = PTR(hdList);
ptPerm16 = (TypPoint16*)PTR(hdPerm);
len = 1;
ptList[len++] = INT_TO_HD( pnt+1 );
if ( pnt < deg ) {
for ( p = ptPerm16[pnt]; p != pnt; p = ptPerm16[p] )
ptList[len++] = INT_TO_HD( p+1 );
}
}
else {
ptPerm32 = (TypPoint32*)PTR(hdPerm);
deg = SIZE(hdPerm)/sizeof(TypPoint32);
pnt = HD_TO_INT(hdPnt)-1;
len = 1;
if ( pnt < deg ) {
for ( p = ptPerm32[pnt]; p != pnt; p = ptPerm32[p] )
len++;
}
hdList = NewBag( T_LIST, SIZE_HD + len*SIZE_HD );
PTR(hdList)[0] = INT_TO_HD( len );
ptList = PTR(hdList);
ptPerm32 = (TypPoint32*)PTR(hdPerm);
len = 1;
ptList[len++] = INT_TO_HD( pnt+1 );
if ( pnt < deg ) {
for ( p = ptPerm32[pnt]; p != pnt; p = ptPerm32[p] )
ptList[len++] = INT_TO_HD( p+1 );
}
}
return hdList;
}
TypHandle       FunOrderPerm ( hdCall )
TypHandle           hdCall;
{
TypHandle           hdPerm;
TypPoint16          * ptPerm16;
TypPoint32          * ptPerm32;
TypHandle           ord;
TypPoint16          * ptKnown16;
TypPoint32          * ptKnown32;
unsigned long       len;
unsigned long       gcd,  s,  t;
unsigned long       p,  q;
if ( SIZE(hdCall) != 2 * SIZE_HD )
return Error("usage: OrderPerm( <perm> )",0L,0L);
hdPerm = EVAL( PTR(hdCall)[1] );
if ( TYPE(hdPerm) != T_PERM16 && TYPE(hdPerm) != T_PERM32 )
return Error("OrderPerm: <perm> must be a permutation",0L,0L);
if ( SIZE(HdPerm) < SIZE(hdPerm) )  Resize( HdPerm, SIZE(hdPerm) );
if ( TYPE(hdPerm) == T_PERM16 ) {
ptPerm16  = (TypPoint16*)PTR(hdPerm);
ptKnown16 = (TypPoint16*)PTR(HdPerm);
ord = INT_TO_HD(1);
for ( p = 0; p < SIZE(hdPerm)/sizeof(TypPoint16); p++ ) {
if ( ptKnown16[p] == 0 && ptPerm16[p] != p ) {
len = 1;
for ( q = ptPerm16[p]; q != p; q = ptPerm16[q] ) {
len++;  ptKnown16[q] = 1;
}
gcd = len;  s = HD_TO_INT( ModInt( ord, INT_TO_HD(len) ) );
while ( s != 0 ) {
t = s;  s = gcd % s;  gcd = t;
}
ord = ProdInt( ord, INT_TO_HD( len / gcd ) );
}
}
for ( p = 0; p < SIZE(hdPerm)/sizeof(TypPoint16); p++ )
ptKnown16[p] = 0;
}
else {
ptPerm32  = (TypPoint32*)PTR(hdPerm);
ptKnown32 = (TypPoint32*)PTR(HdPerm);
ord = INT_TO_HD(1);
for ( p = 0; p < SIZE(hdPerm)/sizeof(TypPoint32); p++ ) {
if ( ptKnown32[p] == 0 && ptPerm32[p] != p ) {
len = 1;
for ( q = ptPerm32[p]; q != p; q = ptPerm32[q] ) {
len++;  ptKnown32[q] = 1;
}
gcd = len;  s = HD_TO_INT( ModInt( ord, INT_TO_HD(len) ) );
while ( s != 0 ) {
t = s;  s = gcd % s;  gcd = t;
}
ord = ProdInt( ord, INT_TO_HD( len / gcd ) );
}
}
for ( p = 0; p < SIZE(hdPerm)/sizeof(TypPoint32); p++ )
ptKnown32[p] = 0;
}
return ord;
}
TypHandle       FunSignPerm ( hdCall )
TypHandle           hdCall;
{
TypHandle           hdPerm;
TypPoint16          * ptPerm16;
TypPoint32          * ptPerm32;
long                sign;
TypPoint16          * ptKnown16;
TypPoint32          * ptKnown32;
unsigned long       len;
unsigned long       p,  q;
if ( SIZE(hdCall) != 2 * SIZE_HD )
return Error("usage: SignPerm( <perm> )",0L,0L);
hdPerm = EVAL( PTR(hdCall)[1] );
if ( TYPE(hdPerm) != T_PERM16 && TYPE(hdPerm) != T_PERM32 )
return Error("SignPerm: <perm> must be a permutation",0L,0L);
if ( SIZE(HdPerm) < SIZE(hdPerm) )  Resize( HdPerm, SIZE(hdPerm) );
if ( TYPE(hdPerm) == T_PERM16 ) {
ptPerm16  = (TypPoint16*)PTR(hdPerm);
ptKnown16 = (TypPoint16*)PTR(HdPerm);
sign = 1;
for ( p = 0; p < SIZE(hdPerm)/sizeof(TypPoint16); p++ ) {
if ( ptKnown16[p] == 0 && ptPerm16[p] != p ) {
len = 1;
for ( q = ptPerm16[p]; q != p; q = ptPerm16[q] ) {
len++;  ptKnown16[q] = 1;
}
if ( len % 2 == 0 )
sign = -sign;
}
}
for ( p = 0; p < SIZE(hdPerm)/sizeof(TypPoint16); p++ )
ptKnown16[p] = 0;
}
else {
ptPerm32  = (TypPoint32*)PTR(hdPerm);
ptKnown32 = (TypPoint32*)PTR(HdPerm);
sign = 1;
for ( p = 0; p < SIZE(hdPerm)/sizeof(TypPoint32); p++ ) {
if ( ptKnown32[p] == 0 && ptPerm32[p] != p ) {
len = 1;
for ( q = ptPerm32[p]; q != p; q = ptPerm32[q] ) {
len++;  ptKnown32[q] = 1;
}
if ( len % 2 == 0 )
sign = -sign;
}
}
for ( p = 0; p < SIZE(hdPerm)/sizeof(TypPoint32); p++ )
ptKnown32[p] = 0;
}
return INT_TO_HD( sign );
}
TypHandle       FunSmallestGeneratorPerm ( hdCall )
TypHandle           hdCall;
{
TypHandle           hdSmall;
TypPoint16          * ptSmall16;
TypPoint32          * ptSmall32;
TypHandle           hdPerm;
TypPoint16          * ptPerm16;
TypPoint32          * ptPerm32;
TypPoint16          * ptKnown16;
TypPoint32          * ptKnown32;
TypHandle           ord;
TypHandle           pow;
unsigned long       len;
unsigned long       gcd,  s,  t;
unsigned long       min;
unsigned long       p,  q;
unsigned long       l, n, x, gcd2;
if ( SIZE(hdCall) != 2 * SIZE_HD )
return Error("usage: SmallestGeneratorPerm( <perm> )",0L,0L);
hdPerm = EVAL( PTR(hdCall)[1] );
if ( TYPE(hdPerm) != T_PERM16 && TYPE(hdPerm) != T_PERM32 )
return Error("SmallestGeneratorPerm: <perm> must be a permutation",
0L,0L);
if ( SIZE(HdPerm) < SIZE(hdPerm) )  Resize( HdPerm, SIZE(hdPerm) );
if ( TYPE(hdPerm) == T_PERM16 ) {
hdSmall = NewBag( T_PERM16, (unsigned long)SIZE(hdPerm) );
ptPerm16   = (TypPoint16*)PTR(hdPerm);
ptKnown16  = (TypPoint16*)PTR(HdPerm);
ptSmall16  = (TypPoint16*)PTR(hdSmall);
ord = INT_TO_HD(1);  pow = INT_TO_HD(0);
for ( p = 0; p < SIZE(hdPerm)/sizeof(TypPoint16); p++ ) {
if ( ptKnown16[p] == 0 ) {
len = 1;
for ( q = ptPerm16[p]; q != p; q = ptPerm16[q] ) {
len++;  ptKnown16[q] = 1;
}
gcd = len;  s = HD_TO_INT( ModInt( ord, INT_TO_HD(len) ) );
while ( s != 0 ) {
t = s;  s = gcd % s;  gcd = t;
}
x = HD_TO_INT( ModInt( pow, INT_TO_HD( gcd ) ) );
min = SIZE(hdPerm)/sizeof(TypPoint16)-1;
n = 0;
for ( q = p, l = 0; l < len; l++ ) {
gcd2 = len;  s = l;
while ( s != 0 ) { t = s; s = gcd2 % s; gcd2 = t; }
if ( l % gcd == x && gcd2 == 1 && q <= min ) {
min = q;
n = l;
}
q = ptPerm16[q];
}
ptSmall16[p] = min;
for ( q = ptPerm16[p]; q != p; q = ptPerm16[q] ) {
min = ptPerm16[min];  ptSmall16[q] = min;
}
while ( HD_TO_INT( ModInt( pow, INT_TO_HD(len) ) ) != n )
pow = SumInt( pow, ord );
ord = ProdInt( ord, INT_TO_HD( len / gcd ) );
}
}
for ( p = 0; p < SIZE(hdPerm)/sizeof(TypPoint16); p++ )
ptKnown16[p] = 0;
}
else {
hdSmall = NewBag( T_PERM32, (unsigned long)SIZE(hdPerm) );
ptPerm32   = (TypPoint32*)PTR(hdPerm);
ptKnown32  = (TypPoint32*)PTR(HdPerm);
ptSmall32  = (TypPoint32*)PTR(hdSmall);
ord = INT_TO_HD(1);  pow = INT_TO_HD(0);
for ( p = 0; p < SIZE(hdPerm)/sizeof(TypPoint32); p++ ) {
if ( ptKnown32[p] == 0 ) {
len = 1;
for ( q = ptPerm32[p]; q != p; q = ptPerm32[q] ) {
len++;  ptKnown32[q] = 1;
}
gcd = len;  s = HD_TO_INT( ModInt( ord, INT_TO_HD(len) ) );
while ( s != 0 ) {
t = s;  s = gcd % s;  gcd = t;
}
x = HD_TO_INT( ModInt( pow, INT_TO_HD( gcd ) ) );
min = SIZE(hdPerm)/sizeof(TypPoint32)-1;
n = 0;
for ( q = p, l = 0; l < len; l++ ) {
gcd2 = len;  s = l;
while ( s != 0 ) { t = s; s = gcd2 % s; gcd2 = t; }
if ( l % gcd == x && gcd2 == 1 && q <= min ) {
min = q;
n = l;
}
q = ptPerm32[q];
}
ptSmall32[p] = min;
for ( q = ptPerm32[p]; q != p; q = ptPerm32[q] ) {
min = ptPerm32[min];  ptSmall32[q] = min;
}
while ( HD_TO_INT( ModInt( pow, INT_TO_HD(len) ) ) != n )
pow = SumInt( pow, ord );
ord = ProdInt( ord, INT_TO_HD( len / gcd ) );
}
}
for ( p = 0; p < SIZE(hdPerm)/sizeof(TypPoint32); p++ )
ptKnown32[p] = 0;
}
return hdSmall;
}
TypHandle       OnTuplesPerm ( hdTup, hdPrm )
TypHandle           hdTup;
TypHandle           hdPrm;
{
TypHandle           hdRes;
TypHandle           * ptRes;
TypHandle           * ptTup;
TypPoint16          * ptPrm16;
TypPoint32          * ptPrm32;
TypHandle           hdTmp;
unsigned long       lmp;
unsigned long       i, k;
hdRes = NewBag( T_LIST, SIZE_HD + LEN_LIST(hdTup)*SIZE_HD );
PTR(hdRes)[0] = PTR(hdTup)[0];
if ( TYPE(hdPrm) == T_PERM16 ) {
ptTup = PTR(hdTup) + LEN_LIST(hdTup);
ptRes = PTR(hdRes) + LEN_LIST(hdTup);
ptPrm16 = (TypPoint16*)PTR(hdPrm);
lmp = SIZE(hdPrm) / sizeof(TypPoint16);
for ( i = LEN_LIST(hdTup); 1 <= i; i--, ptTup--, ptRes-- ) {
if ( TYPE( *ptTup ) == T_INT ) {
k = HD_TO_INT( *ptTup );
if ( k <= 0 )
hdTmp = Error("Perm Op: point must be positive (%d)",k,0L);
else if ( k <= lmp )
hdTmp = INT_TO_HD( ptPrm16[k-1] + 1 );
else
hdTmp = INT_TO_HD( k );
*ptRes = hdTmp;
}
else {
hdTmp = POW( *ptTup, hdPrm );
ptTup = PTR(hdTup) + i;
ptRes = PTR(hdRes) + i;
ptPrm16 = (TypPoint16*)PTR(hdPrm);
*ptRes = hdTmp;
}
}
}
else {
ptTup = PTR(hdTup) + LEN_LIST(hdTup);
ptRes = PTR(hdRes) + LEN_LIST(hdTup);
ptPrm32 = (TypPoint32*)PTR(hdPrm);
lmp = SIZE(hdPrm) / sizeof(TypPoint32);
for ( i = LEN_LIST(hdTup); 1 <= i; i--, ptTup--, ptRes-- ) {
if ( TYPE( *ptTup ) == T_INT ) {
k = HD_TO_INT( *ptTup );
if ( k <= 0 )
hdTmp = Error("Perm Op: point must be positive (%d)",k,0L);
else if ( k <= lmp )
hdTmp = INT_TO_HD( ptPrm32[k-1] + 1 );
else
hdTmp = INT_TO_HD( k );
*ptRes = hdTmp;
}
else {
hdTmp = POW( *ptTup, hdPrm );
ptTup = PTR(hdTup) + i;
ptRes = PTR(hdRes) + i;
ptPrm32 = (TypPoint32*)PTR(hdPrm);
*ptRes = hdTmp;
}
}
}
return hdRes;
}
TypHandle       OnSetsPerm ( hdSet, hdPrm )
TypHandle           hdSet;
TypHandle           hdPrm;
{
TypHandle           hdRes;
TypHandle           * ptRes;
TypHandle           * ptTup;
TypPoint16          * ptPrm16;
TypPoint32          * ptPrm32;
TypHandle           hdTmp;
unsigned long       lmp;
unsigned long       isint;
unsigned long       len;
unsigned long       h;
unsigned long       i, k;
hdRes = NewBag( T_LIST, SIZE_HD + LEN_LIST(hdSet)*SIZE_HD );
PTR(hdRes)[0] = PTR(hdSet)[0];
if ( TYPE(hdPrm) == T_PERM16 ) {
ptTup = PTR(hdSet) + LEN_LIST(hdSet);
ptRes = PTR(hdRes) + LEN_LIST(hdSet);
ptPrm16 = (TypPoint16*)PTR(hdPrm);
lmp = SIZE(hdPrm) / sizeof(TypPoint16);
isint = 1;
for ( i = LEN_LIST(hdSet); 1 <= i; i--, ptTup--, ptRes-- ) {
if ( TYPE( *ptTup ) == T_INT ) {
k = HD_TO_INT( *ptTup );
if ( k <= 0 )
hdTmp = Error("Perm Op: point must be positive (%d)",k,0L);
else if ( k <= lmp )
hdTmp = INT_TO_HD( ptPrm16[k-1] + 1 );
else
hdTmp = INT_TO_HD( k );
*ptRes = hdTmp;
}
else {
isint = 0;
hdTmp = POW( *ptTup, hdPrm );
ptTup = PTR(hdSet) + i;
ptRes = PTR(hdRes) + i;
ptPrm16 = (TypPoint16*)PTR(hdPrm);
*ptRes = hdTmp;
}
}
}
else {
ptTup = PTR(hdSet) + LEN_LIST(hdSet);
ptRes = PTR(hdRes) + LEN_LIST(hdSet);
ptPrm32 = (TypPoint32*)PTR(hdPrm);
lmp = SIZE(hdPrm) / sizeof(TypPoint32);
isint = 1;
for ( i = LEN_LIST(hdSet); 1 <= i; i--, ptTup--, ptRes-- ) {
if ( TYPE( *ptTup ) == T_INT ) {
k = HD_TO_INT( *ptTup );
if ( k <= 0 )
hdTmp = Error("Perm Op: point must be positive (%d)",k,0L);
else if ( k <= lmp )
hdTmp = INT_TO_HD( ptPrm32[k-1] + 1 );
else
hdTmp = INT_TO_HD( k );
*ptRes = hdTmp;
}
else {
isint = 0;
hdTmp = POW( *ptTup, hdPrm );
ptTup = PTR(hdSet) + i;
ptRes = PTR(hdRes) + i;
ptPrm32 = (TypPoint32*)PTR(hdPrm);
*ptRes = hdTmp;
}
}
}
if ( isint ) {
len = LEN_LIST(hdRes);
h = 1;  while ( 9*h + 4 < len )  h = 3*h + 1;
while ( 0 < h ) {
for ( i = h+1; i <= len; i++ ) {
hdTmp = PTR(hdRes)[i];  k = i;
while ( h < k && ((long)hdTmp < (long)(PTR(hdRes)[k-h])) ) {
PTR(hdRes)[k] = PTR(hdRes)[k-h];
k -= h;
}
PTR(hdRes)[k] = hdTmp;
}
h = h / 3;
}
	Retype( hdRes, T_SET );
}
else {
len = LEN_LIST(hdRes);
h = 1;  while ( 9*h + 4 < len )  h = 3*h + 1;
while ( 0 < h ) {
for ( i = h+1; i <= len; i++ ) {
hdTmp = PTR(hdRes)[i];  k = i;
while ( h < k && LT( hdTmp, PTR(hdRes)[k-h] ) == HdTrue ) {
PTR(hdRes)[k] = PTR(hdRes)[k-h];
k -= h;
}
PTR(hdRes)[k] = hdTmp;
}
h = h / 3;
}
if ( 0 < len ) {
hdTmp = PTR(hdRes)[1];  k = 1;
for ( i = 2; i <= len; i++ ) {
if ( EQ( hdTmp, PTR(hdRes)[i] ) != HdTrue ) {
k++;
hdTmp = PTR(hdRes)[i];
PTR(hdRes)[k] = hdTmp;
}
}
if ( k < len ) {
Resize( hdRes, SIZE_HD+k*SIZE_HD );
PTR(hdRes)[0] = INT_TO_HD(k);
}
}
}
return hdRes;
}
void            InitPermutat ()
{
InstEvFunc( T_PERM16,   EvPerm     );
InstEvFunc( T_PERM32,   EvPerm     );
InstEvFunc( T_MAKEPERM, EvMakeperm );
InstPrFunc( T_PERM16,   PrPermP    );
InstPrFunc( T_PERM32,   PrPermQ    );
InstPrFunc( T_MAKEPERM, PrMakeperm );
TabProd[ T_PERM16 ][ T_PERM16 ] = ProdPP;
TabProd[ T_PERM16 ][ T_PERM32 ] = ProdPQ;
TabProd[ T_PERM32 ][ T_PERM16 ] = ProdQP;
TabProd[ T_PERM32 ][ T_PERM32 ] = ProdQQ;
TabQuo[  T_PERM16 ][ T_PERM16 ] = QuoPP;
TabQuo[  T_PERM16 ][ T_PERM32 ] = QuoPQ;
TabQuo[  T_PERM32 ][ T_PERM16 ] = QuoQP;
TabQuo[  T_PERM32 ][ T_PERM32 ] = QuoQQ;
TabMod[  T_PERM16 ][ T_PERM16 ] = ModPP;
TabMod[  T_PERM16 ][ T_PERM32 ] = ModPQ;
TabMod[  T_PERM32 ][ T_PERM16 ] = ModQP;
TabMod[  T_PERM32 ][ T_PERM32 ] = ModQQ;
TabPow[  T_PERM16 ][ T_INT    ] = PowPI;
TabPow[  T_PERM16 ][ T_INTPOS ] = PowPI;
TabPow[  T_PERM16 ][ T_INTNEG ] = PowPI;
TabPow[  T_PERM32 ][ T_INT    ] = PowQI;
TabPow[  T_PERM32 ][ T_INTPOS ] = PowQI;
TabPow[  T_PERM32 ][ T_INTNEG ] = PowQI;
TabPow[  T_INT    ][ T_PERM16 ] = PowIP;
TabPow[  T_INTPOS ][ T_PERM16 ] = PowIP;
TabPow[  T_INT    ][ T_PERM32 ] = PowIQ;
TabPow[  T_INTPOS ][ T_PERM32 ] = PowIQ;
TabQuo[  T_INT    ][ T_PERM16 ] = QuoIP;
TabQuo[  T_INTPOS ][ T_PERM16 ] = QuoIP;
TabQuo[  T_INT    ][ T_PERM32 ] = QuoIQ;
TabQuo[  T_INTPOS ][ T_PERM32 ] = QuoIQ;
TabPow[  T_PERM16 ][ T_PERM16 ] = PowPP;
TabPow[  T_PERM16 ][ T_PERM32 ] = PowPQ;
TabPow[  T_PERM32 ][ T_PERM16 ] = PowQP;
TabPow[  T_PERM32 ][ T_PERM32 ] = PowQQ;
TabComm[ T_PERM16 ][ T_PERM16 ] = CommPP;
TabComm[ T_PERM16 ][ T_PERM32 ] = CommPQ;
TabComm[ T_PERM32 ][ T_PERM16 ] = CommQP;
TabComm[ T_PERM32 ][ T_PERM32 ] = CommQQ;
TabEq[   T_PERM16 ][ T_PERM16 ] = EqPP;
TabEq[   T_PERM16 ][ T_PERM32 ] = EqPQ;
TabEq[   T_PERM32 ][ T_PERM16 ] = EqQP;
TabEq[   T_PERM32 ][ T_PERM32 ] = EqQQ;
TabLt[   T_PERM16 ][ T_PERM16 ] = LtPP;
TabLt[   T_PERM16 ][ T_PERM32 ] = LtPQ;
TabLt[   T_PERM32 ][ T_PERM16 ] = LtQP;
TabLt[   T_PERM32 ][ T_PERM32 ] = LtQQ;
InstIntFunc( "IsPerm",                FunIsPerm                );
InstIntFunc( "PermList",              FunPermList              );
InstIntFunc( "LargestMovedPointPerm", FunLargestMovedPointPerm );
InstIntFunc( "CycleLengthPermInt",    FunCycleLengthPermInt    );
InstIntFunc( "CyclePermInt",          FunCyclePermInt          );
InstIntFunc( "OrderPerm",             FunOrderPerm             );
InstIntFunc( "SignPerm",              FunSignPerm              );
InstIntFunc( "SmallestGeneratorPerm", FunSmallestGeneratorPerm );
HdPerm = NewBag( T_PERM16, (unsigned long)1000*sizeof(TypPoint16) );
}
/* 当前文件是D:\Read\plist.c*/

long            LenPlist ( hdList )
TypHandle           hdList;
{
return LEN_PLIST( hdList );
}
TypHandle       ElmPlist ( hdList, pos )
TypHandle           hdList;
long                pos;
{
TypHandle           hdElm;
if ( LEN_PLIST( hdList ) < pos ) {
return Error(
"List Element: <list>[%d] must have a value",
pos, 0L );
}
hdElm = ELM_PLIST( hdList, pos );
if ( hdElm == 0 ) {
return Error(
"List Element: <list>[%d] must have a value",
pos, 0L );
}
return hdElm;
}
TypHandle       ElmfPlist ( hdList, pos )
TypHandle           hdList;
long                pos;
{
return ELM_PLIST( hdList, pos );
}
TypHandle       ElmsPlist ( hdList, hdPoss )
TypHandle           hdList;
TypHandle           hdPoss;
{
TypHandle           hdElms;
long                lenList;
TypHandle           hdElm;
long                lenPoss;
long                pos;
long                inc;
long                i;
if ( TYPE(hdPoss) != T_RANGE ) {
lenList = LEN_PLIST( hdList );
lenPoss = LEN_LIST( hdPoss );
hdElms = NewBag( T_LIST, SIZE_PLEN_PLIST( lenPoss ) );
SET_LEN_PLIST( hdElms, lenPoss );
for ( i = 1; i <= lenPoss; i++ ) {
pos = HD_TO_INT( ELMF_LIST( hdPoss, i ) );
if ( lenList < pos ) {
return Error(
"List Elements: <list>[%d] must have a value",
pos, 0L );
}
hdElm = ELM_PLIST( hdList, pos );
if ( hdElm == 0 ) {
return Error(
"List Elements: <list>[%d] must have a value",
pos, 0L );
}
SET_ELM_PLIST( hdElms, i, hdElm );
}
}
else {
lenList = LEN_PLIST( hdList );
lenPoss = LEN_RANGE( hdPoss );
pos = LOW_RANGE( hdPoss );
inc = INC_RANGE( hdPoss );
if ( lenList < pos ) {
return Error(
"List Elements: <list>[%d] must have a value",
pos, 0L );
}
if ( lenList < pos + (lenPoss-1) * inc ) {
return Error(
"List Elements: <list>[%d] must have a value",
pos + (lenPoss-1) * inc, 0L );
}
hdElms = NewBag( T_LIST, SIZE_PLEN_PLIST( lenPoss ) );
SET_LEN_PLIST( hdElms, lenPoss );
for ( i = 1; i <= lenPoss; i++, pos += inc ) {
hdElm = ELM_PLIST( hdList, pos );
if ( hdElm == 0 ) {
return Error(
"List Elements: <list>[%d] must have a value",
pos, 0L );
}
SET_ELM_PLIST( hdElms, i, hdElm );
}
}
return hdElms;
}
TypHandle       AssPlist ( hdList, pos, hdVal )
TypHandle           hdList;
long                pos;
TypHandle           hdVal;
{
long                plen;
if ( LEN_PLIST( hdList ) < pos ) {
plen = PLEN_SIZE_PLIST( SIZE( hdList ) );
if ( plen + plen/8 + 4 < pos )
Resize( hdList, SIZE_PLEN_PLIST( pos ) );
else if ( plen < pos )
Resize( hdList, SIZE_PLEN_PLIST( plen + plen/8 + 4 ) );
SET_LEN_PLIST( hdList, pos );
}
SET_ELM_PLIST( hdList, pos, hdVal );
return hdVal;
}
TypHandle       AsssPlist ( hdList, hdPoss, hdVals )
TypHandle           hdList;
TypHandle           hdPoss;
TypHandle           hdVals;
{
long                lenPoss;
long                pos;
long                max;
long                inc;
TypHandle           hdVal;
long                plen;
long                i;
if ( TYPE(hdPoss) != T_RANGE ) {
lenPoss = LEN_LIST( hdPoss );
max = LEN_PLIST( hdList );
for ( i = 1; i <= lenPoss; i++ ) {
if ( max < HD_TO_INT( ELMF_LIST( hdPoss, i ) ) )
max = HD_TO_INT( ELMF_LIST( hdPoss, i ) );
}
if ( LEN_PLIST(hdList) < max ) {
plen = PLEN_SIZE_PLIST( SIZE(hdList) );
if ( plen + plen/8 + 4 < max )
Resize( hdList, SIZE_PLEN_PLIST( max ) );
else if ( plen < max )
Resize( hdList, SIZE_PLEN_PLIST( plen + plen/8 + 4 ) );
SET_LEN_PLIST( hdList, max );
}
for ( i = 1; i <= lenPoss; i++ ) {
pos = HD_TO_INT( ELMF_LIST( hdPoss, i ) );
hdVal = ELMF_LIST( hdVals, i );
SET_ELM_PLIST( hdList, pos, hdVal );
}
}
else {
lenPoss = LEN_RANGE( hdPoss );
pos = LOW_RANGE( hdPoss );
inc = INC_RANGE( hdPoss );
max = LEN_PLIST( hdList );
if ( max < pos )
max = pos;
if ( max < pos + (lenPoss-1) * inc )
max = pos + (lenPoss-1) * inc;
if ( LEN_PLIST(hdList) < max ) {
plen = PLEN_SIZE_PLIST( SIZE(hdList) );
if ( plen + plen/8 + 4 < max )
Resize( hdList, SIZE_PLEN_PLIST( max ) );
else if ( plen < max )
Resize( hdList, SIZE_PLEN_PLIST( plen + plen/8 + 4 ) );
SET_LEN_PLIST( hdList, max );
}
for ( i = 1; i <= lenPoss; i++, pos += inc ) {
hdVal = ELMF_LIST( hdVals, i );
SET_ELM_PLIST( hdList, pos, hdVal );
}
}
return hdVals;
}
long            PosPlist ( hdList, hdVal, start )
TypHandle           hdList;
TypHandle           hdVal;
long                start;
{
long                lenList;
TypHandle           hdElm;
long                i;
lenList = LEN_PLIST( hdList );
for ( i = start+1; i <= lenList; i++ ) {
hdElm = ELM_PLIST( hdList, i );
if ( hdElm != 0 && (hdElm == hdVal || EQ( hdElm, hdVal ) == HdTrue) )
break;
}
return (lenList < i ? 0 : i);
}
void            PlainPlist ( hdList )
TypHandle           hdList;
{
return;
}
long            IsDensePlist ( hdList )
TypHandle           hdList;
{
long                lenList;
long                i;
lenList = LEN_PLIST( hdList );
for ( i = 1; i <= lenList; i++ ) {
if ( ELM_PLIST( hdList, i ) == 0 )
return 0;
}
return 1;
}
long            IsPossPlist ( hdList )
TypHandle           hdList;
{
long                lenList;
TypHandle           hdElm;
long                i;
lenList = LEN_PLIST( hdList );
for ( i = 1; i <= lenList; i++ ) {
hdElm = ELM_PLIST( hdList, i );
if ( hdElm == 0 || TYPE(hdElm) != T_INT || HD_TO_INT(hdElm) <= 0 )
return 0;
}
return 1;
}
TypHandle       EqPlist ( hdL, hdR )
TypHandle           hdL;
TypHandle           hdR;
{
long                lenL;
long                lenR;
TypHandle           hdElmL;
TypHandle           hdElmR;
long                i;
lenL = LEN_PLIST( hdL );
lenR = LEN_PLIST( hdR );
if ( lenL != lenR ) {
return HdFalse;
}
for ( i = 1; i <= lenL; i++ ) {
hdElmL = ELM_PLIST( hdL, i );
hdElmR = ELM_PLIST( hdR, i );
if ( hdElmL == 0 && hdElmR != 0 ) {
return HdFalse;
}
else if ( hdElmR == 0 && hdElmL != 0 ) {
return HdFalse;
}
else if ( hdElmL != hdElmR && EQ( hdElmL, hdElmR ) == HdFalse ) {
return HdFalse;
}
}
return HdTrue;
}
TypHandle       LtPlist ( hdL, hdR )
TypHandle           hdL;
TypHandle           hdR;
{
long                lenL;
long                lenR;
TypHandle           hdElmL;
TypHandle           hdElmR;
long                i;
lenL = LEN_PLIST( hdL );
lenR = LEN_PLIST( hdR );
for ( i = 1; i <= lenL && i <= lenR; i++ ) {
hdElmL = ELM_PLIST( hdL, i );
hdElmR = ELM_PLIST( hdR, i );
if ( hdElmL == 0 && hdElmR != 0 ) {
return HdTrue;
}
else if ( hdElmR == 0 && hdElmL != 0 ) {
return HdFalse;
}
else if ( hdElmL != hdElmR && EQ( hdElmL, hdElmR ) == HdFalse ) {
return LT( hdElmL, hdElmR );
}
}
return (lenL < lenR) ? HdTrue : HdFalse;
}
TypHandle       EvMakeList ( hdLiteral )
TypHandle           hdLiteral;
{
TypHandle           hdList;
if ( PTR(HdTilde)[0] == 0 ) {
hdList = MakeList( HdTilde, 0, hdLiteral );
PTR(HdTilde)[0] = 0;
}
else {
hdList = MakeList( 0, 0, hdLiteral );
}
return hdList;
}
TypHandle       MakeList ( hdDst, ind, hdLiteral )
TypHandle           hdDst;
long                ind;
TypHandle           hdLiteral;
{
TypHandle           hdList;
long                len;
TypHandle           hd;
long                i;
len = LEN_PLIST( hdLiteral );
hdList = NewBag( T_LIST, SIZE_PLEN_PLIST( len ) );
SET_LEN_PLIST( hdList, len );
if ( hdDst != 0 )  PTR(hdDst)[ind] = hdList;
for ( i = 1; i <= len; i++ ) {
if ( ELM_PLIST( hdLiteral, i ) != 0 ) {
EnterKernel();
if ( TYPE( ELM_PLIST( hdLiteral, i ) ) == T_MAKELIST ) {
MakeList( hdList, i, ELM_PLIST( hdLiteral, i ) );
}
else if ( TYPE( PTR(hdLiteral)[i] ) == T_MAKEREC ) {
MakeRec( hdList, i, ELM_PLIST( hdLiteral, i ) );
}
else {
hd = EVAL( ELM_PLIST( hdLiteral, i ) );
while ( hd == HdVoid ) {
hd = Error(
"List: function must return a value",
0L,0L);
}
SET_ELM_PLIST( hdList, i, hd );
}
ExitKernel(0);
}
}
return hdList;
}
void            PrMakeList ( hdMake )
TypHandle           hdMake;
{
long                lenList;
TypHandle           hdElm;
long                i;
lenList = LEN_PLIST( hdMake );
Pr("%2>[ %2>",0L,0L);
for ( i = 1;  i <= lenList;  i++ ) {
hdElm = ELM_PLIST( hdMake, i );
if ( hdElm != 0 ) {
if ( 1 < i )  Pr("%<,%< %2>",0L,0L);
Print( hdElm );
}
else {
if ( 1 < i )  Pr("%2<,%2>",0L,0L);
}
}
Pr(" %4<]",0L,0L);
}
void            InitPlist ()
{
TabIsList[T_LIST]       = 1;
TabLenList[T_LIST]      = LenPlist;
TabElmList[T_LIST]      = ElmPlist;
TabElmfList[T_LIST]     = ElmfPlist;
TabElmlList[T_LIST]     = ElmfPlist;
TabElmrList[T_LIST]     = ElmfPlist;
TabElmsList[T_LIST]     = ElmsPlist;
TabAssList[T_LIST]      = AssPlist;
TabAsssList[T_LIST]     = AsssPlist;
TabPosList[T_LIST]      = PosPlist;
TabPlainList[T_LIST]    = PlainPlist;
TabIsDenseList[T_LIST]  = IsDensePlist;
TabIsPossList[T_LIST]   = IsPossPlist;
EvTab[T_LIST]           = EvList;
PrTab[T_LIST]           = PrList;
TabEq[T_LIST][T_LIST]   = EqPlist;
TabLt[T_LIST][T_LIST]   = LtPlist;
EvTab[T_MAKELIST]       = EvMakeList;
PrTab[T_MAKELIST]       = PrMakeList;
}
/* 当前文件是D:\Read\polynom.c*/

TypHandle UnifiedFieldVecFFE ( hdL,  hdR )
TypHandle	    hdL;	
TypHandle       hdR;
{
TypHandle           hdFld;
unsigned long       p;
unsigned long       q;
unsigned long       q1;
unsigned long       dl;
unsigned long       dr;
TypHandle           hdElm;
TypFFE              v;
unsigned long       i, k;
if ( FLD_VECFFE(hdL) == FLD_VECFFE(hdR) )
	return FLD_VECFFE(hdL);
p = CharVecFFE(hdL);
if ( p != CharVecFFE(hdR) )
	return Error( "vectors have different characteristic", 0L, 0L );
dl = DegreeVecFFE(hdL);
dr = DegreeVecFFE(hdR);
for ( k = dl;  dl % dr != 0;  dl += k )  ;
if ( (  2 <= p && 17 <= dl ) || (   3 <= p && 11 <= dl )
|| (  5 <= p &&  7 <= dl ) || (   7 <= p &&  6 <= dl )
|| ( 11 <= p &&  5 <= dl ) || (  17 <= p &&  4 <= dl )
|| ( 41 <= p &&  3 <= dl ) || ( 257 <= p &&  2 <= dl ) )
{
	return Error( "common superfield is too large", 0L, 0L );
}
for ( q = 1, k = 1;  k <= dl;  k++ )  q *= p;
if ( (SIZE_FF(FLD_VECFFE(hdL))-1) % (q-1) == 0 )
	hdFld = FLD_VECFFE(hdL);
else if ( (SIZE_FF(FLD_VECFFE(hdR))-1) % (q-1) == 0 )
	hdFld = FLD_VECFFE(hdR);
else
	hdFld = FLD_FFE( RootFiniteField( q ) );
q = SIZE_FF(hdFld);
for ( i = 0;  i <= 1;  i++ )
{
	hdElm = ( i == 0 ) ? hdL : hdR;
	if ( FLD_VECFFE(hdElm) != hdFld )
	{
	    q1 = SIZE_FF( FLD_VECFFE(hdElm) );
	    for ( k = LEN_VECFFE(hdElm);  0 < k;  k-- )
	    {
		v = VAL_VECFFE( hdElm, k );
		SET_VAL_VECFFE( hdElm, k, v==0 ? v : (v-1)*(q-1)/(q1-1)+1 );
	    }
	    SET_FLD_VECFFE( hdElm, hdFld );
	}
}
return FLD_VECFFE(hdL);
}
TypHandle (*TabShiftedCoeffs[T_VAR]) P(( TypHandle, long ));
TypHandle FunShiftedCoeffs ( hdCall )
TypHandle       	hdCall;
{
TypHandle       	hdC;		
TypHandle       	hdN;		
if ( SIZE(hdCall) != 3 * SIZE_HD )
return Error( "usage: ShiftedCoeffs( <c>, <nr> )", 0L, 0L );
hdC = EVAL( PTR(hdCall)[1] );
hdN = EVAL( PTR(hdCall)[2] );
if ( TYPE(hdN) != T_INT )
	return Error( "<nr> must be an integer", 0L, 0L );
return TabShiftedCoeffs[XType(hdC)]( hdC, HD_TO_INT(hdN) );
}
TypHandle CantShiftedCoeffs ( hdList, n )
TypHandle           hdList;
long                n;
{
return Error( "<list> must be a vector", 0L, 0L );
}
TypHandle ShiftedCoeffsListx ( hdC, n )
TypHandle		hdC;
long		n;
{
TypHandle		hdS;		
TypHandle		hdZero;		
long                l;		
long                i;
l = LEN_LIST(hdC);
if ( l == 0 )
	hdS = Copy(hdC);
else if ( n < 0 ) {
	
	if ( l <= -n ) {
	    hdS = NewBag( T_LIST, SIZE_PLEN_PLIST(0) );
	    SET_LEN_PLIST( hdS, 0 );
	    return hdS;
	}
	
	hdS = NewBag( T_LIST, SIZE_PLEN_PLIST(l+n) );
	SET_LEN_PLIST( hdS, l+n );
	for ( i = l;  -n < i;  i-- )
	    SET_ELM_PLIST( hdS, i+n, ELM_PLIST(hdC,i) );
}
else if ( 0 < n ) {
	hdS = NewBag( T_LIST, SIZE_PLEN_PLIST(l+n) );
	SET_LEN_PLIST( hdS, l+n );
	for ( i = l;  0 < i;  i-- )
	    SET_ELM_PLIST( hdS, i+n, ELM_PLIST(hdC,i) );
	hdZero = PROD( ELML_LIST(hdC,1), INT_TO_HD(0) );
	for ( i = n;  0 < i;  i-- )
	    SET_ELM_PLIST( hdS, i, hdZero );
}
else
	hdS = Copy(hdC);
return hdS;
}
TypHandle ShiftedCoeffsVecFFE ( hdC, n )
TypHandle		hdC;
long		n;
{
TypHandle		hdS;		
TypFFE		tmp;		
long                l;		
long                i;
l = LEN_VECFFE(hdC);
if ( n < 0 ) {
	
	if ( l <= -n ) {
	    hdS = NewBag( T_LIST, SIZE_PLEN_PLIST(0) );
	    SET_LEN_PLIST( hdS, 0 );
	    return hdS;
	}
	
	hdS = NewBag( T_VECFFE, SIZE_PLEN_VECFFE(l+n) );
	SET_FLD_VECFFE( hdS, FLD_VECFFE(hdC) );
	for ( i = l;  -n < i;  i-- ) {
	    tmp = VAL_VECFFE( hdC, i );
	    SET_VAL_VECFFE( hdS, i+n, tmp );
	}
}
else if ( 0 < n )
{
	hdS = NewBag( T_VECFFE, SIZE_PLEN_VECFFE(l+n) );
	SET_FLD_VECFFE( hdS, FLD_VECFFE(hdC) );
	for ( i = l;  0 < i;  i-- ) {
	    tmp = VAL_VECFFE( hdC, i );
	    SET_VAL_VECFFE( hdS, i+n, tmp );
	}
	for ( i = n;  0 < i;  i-- )
	    SET_VAL_VECFFE( hdS, i, 0 );
}
else
	hdS = Copy(hdC);
return hdS;
}
TypHandle (*TabNormalizeCoeffs[T_VAR]) P(( TypHandle ));
TypHandle FunNormalizeCoeffs ( hdCall )
TypHandle       hdCall;
{
TypHandle       hdC;
if ( SIZE( hdCall ) != 2 * SIZE_HD )
return Error( "usage: NormalizeCoeffs( <c> )", 0L, 0L );
hdC = EVAL( PTR(hdCall)[1] );
return TabNormalizeCoeffs[XType(hdC)]( hdC );
}
TypHandle CantNormalizeCoeffs ( hdList )
TypHandle           hdList;
{
return Error( "<list> must be a vector", 0L, 0L );
}
TypHandle NormalizeCoeffsVecFFE ( hdC )
TypHandle		hdC;
{
TypFFE		tmp;
long		len;		
long		l1;		
long		l2;		
long		i;		
len = LEN_VECFFE(hdC);
for ( l1 = 1;  l1 <= len;  l1++ )
	if ( VAL_VECFFE( hdC, l1 ) != 0 )
	    break;
for ( l2 = len;  l1 < l2;  l2-- )
	if ( VAL_VECFFE( hdC, l2 ) != 0 )
	    break;
if ( l2 < l1 ) {
	Retype( hdC, T_LIST );
	Resize( hdC, SIZE_PLEN_PLIST(0) );
	SET_LEN_PLIST( hdC, 0 );
	return INT_TO_HD(0);
}
if ( 1 < l1 )
	for ( i = l1;  i <= l2;  i++ ) {
	    tmp = VAL_VECFFE( hdC, i );
	    SET_VAL_VECFFE( hdC, i-l1+1, tmp );
	}
Resize( hdC, SIZE_PLEN_VECFFE(l2-l1+1) );
return INT_TO_HD(l1-1);
}
TypHandle NormalizeCoeffsListx ( hdC )
TypHandle		hdC;
{
TypHandle		hdZero;
TypHandle		hdTmp;
long		len;		
long		l1;		
long		l2;		
long		i;		
if ( LEN_LIST(hdC) == 0 )
	return INT_TO_HD(0);
hdZero = PROD( INT_TO_HD(0), ELM_LIST(hdC,1) );
len = LEN_LIST(hdC);
for ( l1 = 1;  l1 <= len;  l1++ ) {
	hdTmp = ELML_LIST(hdC,l1);
	if ( EQ( hdTmp, hdZero ) == HdFalse )
	    break;
}
for ( l2 = len;  l1 < l2;  l2-- ) {
	hdTmp = ELML_LIST(hdC,l2);
	if ( EQ( hdTmp, hdZero ) == HdFalse )
	    break;
}
if ( l2 < l1 ) {
	Retype( hdC, T_LIST );
	Resize( hdC, SIZE_PLEN_PLIST(0) );
	SET_LEN_PLIST( hdC, 0 );
	return INT_TO_HD(0);
}
if ( 1 < l1 )
	for ( i = l1;  i <= l2;  i++ ) {
	    hdTmp = ELML_LIST( hdC, i );
	    SET_ELM_PLIST( hdC, i-l1+1, hdTmp );
	}
Resize( hdC, SIZE_PLEN_PLIST(l2-l1+1) );
SET_LEN_PLIST( hdC, l2-l1+1 );
return INT_TO_HD(l1-1);
}
void (*TabShrinkCoeffs[T_VAR]) P(( TypHandle ));
TypHandle FunShrinkCoeffs ( hdCall )
TypHandle       hdCall;
{
TypHandle       hdC;
if ( SIZE( hdCall ) != 2 * SIZE_HD )
return Error( "usage: ShrinkCoeffs( <c> )", 0L, 0L );
hdC = EVAL( PTR(hdCall)[1] );
TabShrinkCoeffs[XType(hdC)]( hdC );
return HdVoid;
}
void CantShrinkCoeffs ( hdList )
TypHandle           hdList;
{
Error( "<list> must be a vector", 0L, 0L );
}
void ShrinkCoeffsVecFFE ( hdC )
TypHandle		hdC;
{
long		len;		
long		i;		
len = LEN_VECFFE(hdC);
for ( i = len;  0 < i;  i-- )
	if ( VAL_VECFFE( hdC, i ) != 0 )
	    break;
if ( 0 == i ) {
	Retype( hdC, T_LIST );
	Resize( hdC, SIZE_PLEN_PLIST(0) );
	SET_LEN_PLIST( hdC, 0 );
	return;
}
Resize( hdC, SIZE_PLEN_VECFFE(i) );
}
void ShrinkCoeffsListx ( hdC )
TypHandle		hdC;
{
TypHandle		hdZero;
TypHandle		hdTmp;
long		len;		
long		i;		
if ( LEN_LIST(hdC) == 0 )
	return;
hdZero = PROD( INT_TO_HD(0), ELM_LIST(hdC,1) );
len = LEN_LIST(hdC);
for ( i = len;  0 < i;  i-- ) {
	hdTmp = ELML_LIST(hdC,i);
	if ( EQ( hdTmp, hdZero ) == HdFalse )
	    break;
}
if ( 0 == i ) {
	Retype( hdC, T_LIST );
	Resize( hdC, SIZE_PLEN_PLIST(0) );
	SET_LEN_PLIST( hdC, 0 );
	return;
}
Resize( hdC, SIZE_PLEN_PLIST(i) );
SET_LEN_PLIST( hdC, i );
}
void (*TabAddCoeffs[T_VAR][T_VAR]) P(( TypHandle, TypHandle, TypHandle ));
void CantAddCoeffs ( hdL, hdR, hdM )
TypHandle		hdL;
TypHandle		hdR;
TypHandle       	hdM;
{
Error("<l> and <r> must be vectors over a common field", 0L, 0L);
}
void AddCoeffsListxListx ( hdL, hdR, hdM )
TypHandle		hdL;
TypHandle		hdR;
TypHandle       	hdM;
{
TypHandle           hdLL;
TypHandle           hdRR;
TypHandle           hdAA;
long                l;
long                r;
long                m;
long                i;
l = LEN_LIST(hdL);
r = LEN_LIST(hdR);
if ( l < r ) {
	hdLL = PROD( ELML_LIST(hdR,1), INT_TO_HD(0) );
	for ( i = l+1;  i <= r;  i++ )
ASS_LIST( hdL, i, hdLL );
	l = r;
}
m = ( l < r ) ? l : r;
if ( hdM == INT_TO_HD(1) ) {
	for ( i = 1;  i <= m;  i++ ) {
	    hdLL = ELM_LIST( hdL, i );
	    hdRR = ELM_LIST( hdR, i );
	    hdAA = SUM( hdLL, hdRR );
	    ASS_LIST( hdL, i, hdAA );
	}
	for ( i = m+1;  i <= r;  i++ ) {
	    hdRR = ELM_LIST( hdR, i );
	    ASS_LIST( hdL, i, hdRR );
	}
}
else {
	for ( i = 1;  i <= m;  i++ ) {
	    hdLL = ELM_LIST( hdL, i );
	    hdRR = ELM_LIST( hdR, i );
	    hdRR = PROD( hdRR, hdM );
	    hdAA = SUM( hdLL, hdRR );
	    ASS_LIST( hdL, i, hdAA );
	}
	for ( i = m+1;  i <= r;  i++ ) {
	    hdRR = ELM_LIST( hdR, i );
	    hdRR = PROD( hdRR, hdM );
	    ASS_LIST( hdL, i, hdRR );
	}
}
}
void AddCoeffsVecFFEVecFFE ( hdL, hdR, hdM )
TypHandle		hdL;
TypHandle		hdR;
TypHandle       	hdM;
{
long            l;
long            r;
TypFFE          m;
TypFFE        * ptL;
TypFFE        * ptR;
TypFFE        * ptE;
TypFFE        * f;
TypFFE          t;
if ( TYPE(hdM) == T_FFE ) {
	if ( UnifiedFieldVecFFE(hdL,hdR) == FLD_FFE(hdM) )
	    m = VAL_FFE(hdM);
	else {
	    hdR = PROD( hdR, hdM );
	    m   = 1;
	}
}
else {
	if ( INT_TO_HD(1) != hdM ) {
	    hdR = PROD( hdR, hdM );
	    hdM = INT_TO_HD(1);
	    TabAddCoeffs[XType(hdL)][XType(hdR)]( hdL, hdR, hdM );
	    return;
	}
	else
	    m = 1;
}
if ( m == 0 )
	return;
l = LEN_VECFFE(hdL);
r = LEN_VECFFE(hdR);
if ( l < r ) {
	Resize( hdL, SIZE_PLEN_VECFFE(r) );
	SET_VAL_VECFFE( hdL, l+1, 0 );
	l = r;
}
f = (TypFFE*) PTR( UnifiedFieldVecFFE( hdL, hdR ) );
ptL = (TypFFE*)( PTR(hdL) + 1 );
ptR = (TypFFE*)( PTR(hdR) + 1 );
ptE = ptR + r;
if ( m == 1 ) {
	while ( ptR < ptE ) {
	    *ptL = SUM_FF( *ptL, *ptR, f );
	    ptL++;
	    ptR++;
	}
}
else {
	while ( ptR < ptE ) {
	    t = PROD_FF( *ptR, m, f );
	    *ptL = SUM_FF( *ptL, t, f );
	    ptL++;
	    ptR++;
	}
}
}
void AddCoeffsListxVecFFE ( hdL, hdR, hdM )
TypHandle		hdL;
TypHandle		hdR;
TypHandle       	hdM;
{
if ( LEN_LIST(hdL) == 0 ) {
	Retype( hdL, T_VECFFE );
	Resize( hdL, SIZE_PLEN_VECFFE(1) );
	SET_FLD_VECFFE( hdL, FLD_VECFFE(hdR) );
	SET_VAL_VECFFE( hdL, 1, 0 );
	
	AddCoeffsVecFFEVecFFE( hdL, hdR, hdM );
}
else
	AddCoeffsListxListx( hdL, hdR, hdM );
}
TypHandle FunAddCoeffs ( hdCall )
TypHandle       	hdCall;
{
TypHandle       	hdL;
TypHandle       	hdR;
TypHandle       	hdM;
if ( 4 * SIZE_HD < SIZE(hdCall) || SIZE(hdCall) < 3 * SIZE_HD )
return Error( "usage: AddCoeffs( <l>, <r> )", 0L, 0L );
hdL = EVAL( PTR(hdCall)[1] );
hdR = EVAL( PTR(hdCall)[2] );
if ( 4 * SIZE_HD == SIZE(hdCall) )
	hdM = EVAL( PTR(hdCall)[3] );
else
	hdM = INT_TO_HD(1);
TabAddCoeffs[XType(hdL)][XType(hdR)]( hdL, hdR, hdM );
return HdVoid;
}
TypHandle FunSumCoeffs ( hdCall )
TypHandle       	hdCall;
{
TypHandle       	hdL;
TypHandle       	hdR;
TypHandle       	hdM;
if ( SIZE(hdCall) != 3 * SIZE_HD )
return Error( "usage: SumCoeffs( <l>, <r> )", 0L, 0L );
hdL = Copy( EVAL( PTR(hdCall)[1] ) );
hdR = EVAL( PTR(hdCall)[2] );
hdM = INT_TO_HD(1);
TabAddCoeffs[XType(hdL)][XType(hdR)]( hdL, hdR, hdM );
return hdL;
}
long (*TabMultiplyCoeffs[T_VAR][T_VAR]) P((
TypHandle, TypHandle, long, TypHandle, long ));
long CantMultiplyCoeffs ( hdP, hdL, l, hdR, r )
TypHandle	    	hdP;	
TypHandle       	hdL;
TypHandle       	hdR;
long            	l;
long            	r;
{
Error( "<l> and <r> must be vectors over a common field", 0L, 0L);
return 0;
}
long MultiplyCoeffsListxListx ( hdP, hdL, l, hdR, r )
TypHandle	    	hdP;	
TypHandle       	hdL;
TypHandle       	hdR;
long            	l;
long            	r;
{
TypHandle       	hdLL;
TypHandle       	hdRR;
TypHandle       	hdPP;
TypHandle       	hdTT;
long            	i,u,k;
if ( l == 0 || r == 0 )
	return 0;
for ( i = l+r;  1 < i;  i-- )
{
	hdPP = INT_TO_HD(0);
	u = ( i-1 < l ) ? i-1 : l;
	for ( k = ( i-r < 1 ) ? 1 : i-r;  k <= u;  k++ )
	{
	    hdLL = ELML_LIST( hdL, k   );
	    hdRR = ELMR_LIST( hdR, i-k );
	    hdTT = PROD( hdLL, hdRR );
	    hdPP = SUM( hdPP, hdTT );
	}
	ASS_LIST( hdP, i-1, hdPP );
}
return r+l-1;
}
long MultiplyCoeffsVecFFEVecFFE ( hdP, hdL, l, hdR, r )
TypHandle	    	hdP;	
TypHandle       	hdL;
TypHandle       	hdR;
long            	l;
long            	r;
{
TypFFE *            ptL;
TypFFE * 		ptLL;
TypFFE * 		ptEnd;
TypFFE * 		ptR;
TypFFE * 		ptP;
TypFFE * 		ptPP;
TypFFE * 		f;
TypFFE              t;
long                i;
if ( l == 0 || r == 0 )
	return 0;
f = (TypFFE*) PTR( UnifiedFieldVecFFE( hdL, hdR ) );
SET_FLD_VECFFE( hdP, FLD_VECFFE(hdL) );
if ( l < r ) {
	ptL = (TypFFE*)( PTR(hdL) + 1 );
	ptR = (TypFFE*)( PTR(hdR) + 1 );
}
else {
	ptR = (TypFFE*)( PTR(hdL) + 1 );
	ptL = (TypFFE*)( PTR(hdR) + 1 );
	i = l;  l = r;  r = i;
}
ptP = (TypFFE*)( PTR(hdP) + 1 );
for ( ptPP = ptP, ptEnd = ptP + (l+r-1);  ptPP < ptEnd;  ptPP++ )
	*ptPP = 0;
ptEnd = ptL + l;
for ( i = 0;  i < r;  i++, ptR++, ptP++ ) {
	if ( *ptR != 0 ) {
	    for ( ptLL = ptL, ptPP = ptP;  ptLL < ptEnd;  ptLL++, ptPP++ )
		if ( *ptLL != 0 ) {
		    t = PROD_FF( *ptLL, *ptR, f );
		    *ptPP = SUM_FF( *ptPP, t, f );
		}
	}
}
return l+r-1;
}
TypHandle (*TabProductCoeffs[T_VAR][T_VAR]) P(( TypHandle, TypHandle ));
TypHandle FunProductCoeffs ( hdCall )
TypHandle       	hdCall;
{
TypHandle       	hdL;
TypHandle       	hdR;
if ( SIZE(hdCall) != 3 * SIZE_HD )
return Error( "usage: ProductCoeffs( <l>, <r> )", 0L, 0L );
hdL = EVAL( PTR(hdCall)[1] );
hdR = EVAL( PTR(hdCall)[2] );
return TabProductCoeffs[XType(hdL)][XType(hdR)]( hdL, hdR );
}
TypHandle CantProductCoeffs ( hdL, hdR )
TypHandle		hdL;
TypHandle		hdR;
{
return Error("<l> and <r> must be vectors over a common field", 0L, 0L);
}
TypHandle ProductCoeffsListxListx ( hdL, hdR )
TypHandle		hdL;
TypHandle		hdR;
{
TypHandle		hdP;		
long		l;		
long		r;		
l = LEN_LIST(hdL);
r = LEN_LIST(hdR);
if ( l == 0 || r == 0 ) {
	hdP = NewBag( T_LIST, SIZE_PLEN_PLIST(0) );
	SET_LEN_PLIST( hdP, 0 );
	return hdP;
}
hdP = NewBag( T_LIST, SIZE_PLEN_PLIST(l+r-1) );
SET_LEN_PLIST( hdP, l+r-1 );
TabMultiplyCoeffs[T_LISTX][T_LISTX]( hdP, hdL, l, hdR, r );
return hdP;
}
TypHandle ProductCoeffsVecFFEVecFFE ( hdL, hdR )
TypHandle		hdL;
TypHandle		hdR;
{
TypHandle		hdP;		
long		l;		
long		r;		
l = LEN_VECFFE(hdL);
r = LEN_VECFFE(hdR);
if ( l == 0 || r == 0 ) {
	hdP = NewBag( T_LIST, SIZE_PLEN_PLIST(0) );
	SET_LEN_PLIST( hdP, 0 );
	return hdP;
}
hdP = NewBag( T_VECFFE, SIZE_PLEN_VECFFE(l+r-1) );
TabMultiplyCoeffs[T_VECFFE][T_VECFFE]( hdP, hdL, l, hdR, r );
SET_FLD_VECFFE( hdP, FLD_VECFFE(hdL) );
return hdP;
}
TypHandle (*TabProductCoeffsMod[T_VAR][T_VAR]) P((
TypHandle, TypHandle, TypHandle ));
TypHandle FunProductCoeffsMod ( hdCall )
TypHandle       	hdCall;
{
TypHandle       	hdL;
TypHandle       	hdR;
TypHandle       	hdN;
if ( SIZE(hdCall) != 4 * SIZE_HD )
return Error( "usage: ProductCoeffsMod( <l>, <r>, <p> )", 0L, 0L );
hdL = EVAL( PTR(hdCall)[1] );
hdR = EVAL( PTR(hdCall)[2] );
hdN = EVAL( PTR(hdCall)[3] );
return TabProductCoeffsMod[XType(hdL)][XType(hdR)]( hdL, hdR, hdN );
}
TypHandle CantProductCoeffsMod ( hdL, hdR, hdN )
TypHandle		hdL;
TypHandle		hdR;
TypHandle		hdN;
{
return Error("<l> and <r> must be vectors over a common field", 0L, 0L);
}
TypHandle ProductCoeffsModListxListx ( hdL, hdR, hdN )
TypHandle		hdL;
TypHandle		hdR;
TypHandle		hdN;
{
TypHandle		hdP;		
TypHandle           hdLL;
TypHandle           hdRR;
TypHandle           hdPP;
TypHandle           hdTT;
TypHandle           hdQ;
long                i,  u,  k;
long		l;		
long		r;		
l = LEN_LIST(hdL);
r = LEN_LIST(hdR);
if ( l == 0 || r == 0 || hdN == INT_TO_HD(0) ) {
	hdP = NewBag( T_LIST, SIZE_PLEN_PLIST(0) );
	SET_LEN_PLIST( hdP, 0 );
	return hdP;
}
hdP = NewBag( T_LIST, SIZE_PLEN_PLIST(l+r-1) );
SET_LEN_PLIST( hdP, l+r-1 );
if ( LT( hdN, INT_TO_HD(0) ) == HdTrue )
{
	hdN = DIFF( INT_TO_HD(0), hdN );
	hdQ = SUM( hdN, INT_TO_HD(1) );
	hdQ = QuoInt( hdQ, INT_TO_HD(2) );
	hdQ = DIFF( hdQ, INT_TO_HD(1) );
}
else
	hdQ = 0;
for ( i = l+r;  1 < i;  i-- )
{
	hdPP = INT_TO_HD(0);
	u = ( i-1 < l ) ? i-1 : l;
	for ( k = ( i-r < 1 ) ? 1 : i-r;  k <= u;  k++ )
	{
	    hdLL = ELML_LIST( hdL, k   );
	    hdRR = ELMR_LIST( hdR, i-k );
	    hdTT = PROD( hdLL, hdRR );
	    hdPP = SUM( hdPP, hdTT );
	}
	hdPP = MOD( hdPP, hdN );
	if ( hdQ != 0 && LT( hdQ, hdPP ) == HdTrue )
	    hdPP = DIFF( hdPP, hdN );
	SET_ELM_PLIST( hdP, i-1, hdPP );
}
return hdP;
}
long (*TabReduceCoeffs[T_VAR][T_VAR]) P((
TypHandle, long, TypHandle, long ));
long CantReduceCoeffs ( hdL, l, hdR, r )
TypHandle       	hdL;
long            	l;
TypHandle       	hdR;
long            	r;
{
Error( "<l> and <r> must be vectors over a common field", 0L, 0L);
return 0;
}
long ReduceCoeffsListxListx ( hdL, l, hdR, r )
TypHandle       	hdL;
long            	l;
TypHandle       	hdR;
long            	r;
{
TypHandle           hdLL;
TypHandle           hdRR;
TypHandle           hdCC;
TypHandle           hdTT;
long                i,  k;
if ( r == 0 ) {
	Error( "<r> must be non zero", 0L, 0L );
	return 0;
}
hdCC = PROD( ELML_LIST( hdR, 1 ), INT_TO_HD(0) );
for ( ;  0 < r;  r-- ) {
	hdTT = ELMR_LIST( hdR, r );
	if ( EQ( hdCC, hdTT ) == HdFalse )
	    break;
}
if ( r == 0 ) {
	Error( "<r> must be non zero", 0L, 0L );
	return 0;
}
if ( l == 0 )
	return 0;
for ( i = l-r;  0 <= i;  i-- )
{
	hdLL = ELMR_LIST( hdL, i+r );
	if ( hdLL != INT_TO_HD(0) ) {
	    hdRR = ELML_LIST( hdR, r );
	    hdCC = QUO( hdLL, hdRR );
	    for ( k = r;  0 < k;  k-- )
	    {
		hdRR = ELML_LIST( hdR, k );
		hdTT = PROD( hdCC, hdRR );
		hdLL = ELMR_LIST( hdL, i+k );
		hdLL = DIFF( hdLL, hdTT );
		ASS_LIST( hdL, i+k, hdLL );
	    }
	}
}
return ( l < r ) ? l : r-1;
}
long ReduceCoeffsVecFFEVecFFE ( hdL, l, hdR, r )
TypHandle       	hdL;
long            	l;
TypHandle       	hdR;
long            	r;
{
TypFFE *            ptL;
TypFFE *            ptLL;
TypFFE *            ptR;
TypFFE *            ptRR;
TypFFE *            f;
TypFFE              o;
TypFFE              c,q,t;
register long       i,k;
ptR = (TypFFE*)( PTR(hdR) + 1 ) + (r-1);
while ( 0 < r && *ptR == 0 ) {
	r--;  ptR--;
}
if ( r == 0 )
	Error( "<r> must be non zero", 0L, 0L );
if ( l == 0 )
	return 0;
f = (TypFFE*) PTR( UnifiedFieldVecFFE( hdL, hdR ) );
o = *f;
ptL = (TypFFE*)( PTR(hdL) + 1 );
ptR = (TypFFE*)( PTR(hdR) + 1 ) + (r-1);
c = ( o%2 == 1 ? (*ptR) : ( (*ptR) <= o/2 ? (*ptR)+o/2 : (*ptR)-o/2 ) );
for ( i = l-r;  0 <= i;  i-- ) {
	
	ptLL = ptL + (i-1+r);
if ( *ptLL == 0 )
	    continue;
	q = ( c <= (*ptLL) ? (*ptLL)-c+1 : o-c+1+(*ptLL) );
	for ( k = r, ptRR = ptR;  0 < k;  k--, ptLL--, ptRR-- ) {
	    if ( *ptRR == 0 )
		continue;
	    t = ( q-1 <= o-(*ptRR) ) ? q-1+(*ptRR) : q-1-(o-(*ptRR));
	    if ( *ptLL == 0 )
		*ptLL = t;
	    else if ( *ptLL <= t )
		*ptLL = PROD_FF( *ptLL, f[t-(*ptLL)+1], f );
	    else
		*ptLL = PROD_FF( t, f[(*ptLL)-t+1], f );
	}
}
return ( l < r ) ? l : r-1;
}
TypHandle FunReduceCoeffs ( hdCall )
TypHandle 		hdCall;
{
TypHandle       	hdL;
long                l;
TypHandle           hdR;
long                r;
if ( SIZE( hdCall ) != 3 * SIZE_HD )
return Error( "usage: ReduceCoeffs( <l>, <r> )", 0L, 0L );
hdL = EVAL( PTR(hdCall)[1] );
hdR = EVAL( PTR(hdCall)[2] );
l   = LEN_LIST(hdL);
r   = LEN_LIST(hdR);
TabReduceCoeffs[XType(hdL)][XType(hdR)]( hdL, l, hdR, r );
return HdVoid;
}
TypHandle FunRemainderCoeffs ( hdCall )
TypHandle       hdCall;
{
TypHandle       	hdL;
long                l;
TypHandle           hdR;
long                r;
if ( SIZE( hdCall ) != 3 * SIZE_HD )
return Error( "usage: ReduceCoeffs( <l>, <r> )", 0L, 0L );
hdL = EVAL( PTR(hdCall)[1] );
hdR = EVAL( PTR(hdCall)[2] );
l   = LEN_LIST(hdL);
r   = LEN_LIST(hdR);
hdL = Copy(hdL);
TabReduceCoeffs[XType(hdL)][XType(hdR)]( hdL, l, hdR, r );
return hdL;
}
long (*TabReduceCoeffsMod[T_VAR][T_VAR]) P((
TypHandle, long, TypHandle, long, TypHandle ));
long CantReduceCoeffsMod ( hdL, l, hdR, r, hdP )
TypHandle       	hdL;
long            	l;
TypHandle       	hdR;
long            	r;
TypHandle       	hdP;
{
Error( "<l> and <r> must be vectors over a common field", 0L, 0L);
return 0;
}
long ReduceCoeffsModListxListx ( hdL, l, hdR, r, hdP )
TypHandle       	hdL;
long            	l;
TypHandle       	hdR;
long            	r;
TypHandle       	hdP;
{
TypHandle       hdLL;
TypHandle       hdRR;
TypHandle       hdCC;
TypHandle       hdTT;
TypHandle       hdQ;
long            i,  k;
if ( r == 0 ) {
	Error( "<r> must be non zero", 0L, 0L );
	return 0;
}
hdCC = PROD( ELML_LIST( hdR, 1 ), INT_TO_HD(0) );
for ( ;  0 < r;  r-- ) {
	hdTT = ELMR_LIST( hdR, r );
	if ( EQ( hdCC, hdTT ) == HdFalse )
	    break;
}
if ( r == 0 ) {
	Error( "<r> must be non zero", 0L, 0L );
	return 0;
}
if ( l == 0 )
	return 0;
if ( EQ( hdP, INT_TO_HD(0) ) == HdTrue ) {
	for ( i = l;  0 < i;  i-- )
	    ASS_LIST( hdL, i, INT_TO_HD(0) );
	return 0;
}
if ( LT( hdP, INT_TO_HD(0) ) == HdTrue ) {
	hdP = DIFF( INT_TO_HD(0), hdP );
	hdQ = SUM( hdP, INT_TO_HD(1) );
	hdQ = QuoInt( hdQ, INT_TO_HD(2) );
	hdQ = DIFF( hdQ, INT_TO_HD(1) );
}
else
	hdQ = 0;
if ( l < r ) {
	for ( i = l;  0 < i;  i-- ) {
	    hdTT = MOD( ELMF_LIST(hdL,i), hdP );
	    if ( hdQ != 0 && LT( hdQ, hdTT ) == HdTrue )
		hdTT = DIFF( hdTT, hdP );
	    ASS_LIST( hdL, i, hdTT );
	}
	r = l+1;
}
else
	for ( i = l-r;  0 <= i;  i-- ) {
	    hdLL = ELM_LIST( hdL, i+r );
	    if ( hdLL != INT_TO_HD(0) ) {
		hdRR = ELM_LIST( hdR, r );
		hdCC = QUO( hdLL, hdRR );
		hdCC = MOD( hdCC, hdP );
		for ( k = r;  0 < k;  k-- ) {
		    hdRR = ELM_LIST( hdR, k );
		    hdTT = PROD( hdCC, hdRR );
		    hdLL = ELM_LIST( hdL, i+k );
		    hdLL = DIFF( hdLL, hdTT );
		    hdLL = MOD( hdLL, hdP );
		    if ( hdQ != 0 && LT( hdQ, hdLL ) == HdTrue )
			hdLL = DIFF( hdLL, hdP );
		    SET_ELM_PLIST( hdL, i+k, hdLL );
		}
	    }
	}
return r-1;
}
long ReduceCoeffsModListx ( hdL, l, hdR, r, hdP )
TypHandle       	hdL;
long            	l;
TypHandle       	hdR;
long            	r;
TypHandle       	hdP;
{
TypHandle       hdTT;
TypHandle       hdQ;
long            i;
if ( l == 0 )
	return 0;
if ( EQ( hdP, INT_TO_HD(0) ) == HdTrue ) {
	for ( i = l;  0 < i;  i-- )
	    ASS_LIST( hdL, i, INT_TO_HD(0) );
	return 0;
}
if ( LT( hdP, INT_TO_HD(0) ) == HdTrue ) {
	hdP = DIFF( INT_TO_HD(0), hdP );
	hdQ = SUM( hdP, INT_TO_HD(1) );
	hdQ = QuoInt( hdQ, INT_TO_HD(2) );
	hdQ = DIFF( hdQ, INT_TO_HD(1) );
}
else
	hdQ = 0;
for ( i = l;  0 < i;  i-- ) {
	hdTT = MOD( ELMF_LIST(hdL,i), hdP );
	if ( hdQ != 0 && LT( hdQ, hdTT ) == HdTrue )
	    hdTT = DIFF( hdTT, hdP );
	ASS_LIST( hdL, i, hdTT );
}
return l;
}
TypHandle FunReduceCoeffsMod ( hdCall )
TypHandle       hdCall;
{
TypHandle       	hdL;
long                l;
TypHandle           hdR;
long                r;
TypHandle           hdN;
if ( 4*SIZE_HD < SIZE(hdCall) || SIZE(hdCall) < 3*SIZE_HD )
return Error( "usage: ReduceCoeffsMod( <l>, <r>, <p> )", 0L, 0L );
hdL = EVAL( PTR(hdCall)[1] );
l   = LEN_LIST(hdL);
if ( SIZE(hdCall) == 4*SIZE_HD ) {
	hdR = EVAL( PTR(hdCall)[2] );
	r   = LEN_LIST(hdR);
	hdN = EVAL( PTR(hdCall)[3] );
}
else {
	hdR = HdVoid;
	r   = 0;
	hdN = EVAL( PTR(hdCall)[2] );
}
TabReduceCoeffsMod[XType(hdL)][XType(hdR)]( hdL, l, hdR, r, hdN );
return HdVoid;
}
TypHandle (*TabPowerModCoeffsInt[T_VAR][T_VAR]) P((
TypHandle, TypHandle, TypHandle ));
TypHandle (*TabPowerModCoeffsLInt[T_VAR][T_VAR]) P((
TypHandle, TypHandle, TypHandle ));
TypHandle FunPowerModCoeffs ( hdCall )
TypHandle 		hdCall;
{
TypHandle       	hdG;
TypHandle       	hdE;
TypHandle       	hdR;
if ( SIZE( hdCall ) != 4 * SIZE_HD )
return Error( "usage: PowerModCoeffs( <g>, <exp>, <r> )", 0L, 0L );
hdG = EVAL( PTR(hdCall)[1] );
hdE = EVAL( PTR(hdCall)[2] );
hdR = EVAL( PTR(hdCall)[3] );
if ( TYPE(hdE)!=T_INTPOS && ( TYPE(hdE)!=T_INT || HD_TO_INT(hdE)<1 ) )
	return Error( "<exp> must be a positive integer", 0L, 0L );
if ( TYPE(hdE) == T_INT )
	return TabPowerModCoeffsInt [XType(hdG)][XType(hdR)](hdG, hdE, hdR);
else
	return TabPowerModCoeffsLInt[XType(hdG)][XType(hdR)](hdG, hdE, hdR);
}
TypHandle PowerModListxIntListx ( hdG, hdE, hdR )
TypHandle       	hdG;
TypHandle       	hdE;
TypHandle       	hdR;
{
TypHandle	        hdP;
TypHandle           hdR1;
TypHandle           hdR2;
long                g;
long                r;
long                p;
unsigned long       exp;
unsigned long       i;
r = LEN_LIST(hdR);
if ( r == 0 ) {
	Error( "<r> must be non zero", 0L, 0L );
	return 0;
}
hdR1 = PROD( ELML_LIST( hdR, 1 ), INT_TO_HD(0) );
for ( ;  0 < r;  r-- ) {
	hdR2 = ELMR_LIST( hdR, r );
	if ( EQ( hdR1, hdR2 ) == HdFalse )
	    break;
}
if ( r == 0 ) {
	Error( "<r> must be non zero", 0L, 0L );
	return 0;
}
hdG = Copy(hdG);
g   = REDUCE_COEFFS( hdG, LEN_LIST(hdG), hdR, r );
for ( ;  0 < g;  g-- ) {
	hdR2 = ELMR_LIST( hdG, g );
	if ( EQ( hdR1, hdR2 ) == HdFalse )
	    break;
}
if ( g == 0 ) {
	hdG = NewBag( T_LIST, SIZE_PLEN_PLIST(0) );
	SET_LEN_PLIST( hdG, 0 );
	return hdG;
}
hdR1 = Copy(hdG);
hdR2 = NewBag( T_LIST, SIZE_PLEN_PLIST(2*r) );
PLAIN_LIST(hdG);
PLAIN_LIST(hdR1);
Resize( hdR1, SIZE_PLEN_PLIST(2*r) );
SET_LEN_PLIST( hdR1, 2*r );
i   = 1 << 31;
p   = 0;
hdP = 0;
exp = HD_TO_INT(hdE);
while ( 1 < i ) {
	if ( hdP ) {
	
	    p = TabMultiplyCoeffs[T_LISTX][T_LISTX]( hdR2, hdP, p, hdP, p );
	    p = TabReduceCoeffs[T_LISTX][T_LISTX]( hdR2, p, hdR, r );
	    hdR1 = hdP;  hdP = hdR2;  hdR2 = hdR1;
	}
	i = i / 2;
	if ( i <= exp ) {
	    if ( hdP ) {
		
		p = TabMultiplyCoeffs[T_LISTX][T_LISTX](hdR2,hdP,p,hdG,g);
		p = TabReduceCoeffs[T_LISTX][T_LISTX](hdR2,p,hdR,r);
		hdR1 = hdP;  hdP = hdR2;  hdR2 = hdR1;
	    }
	    else {
		hdP = hdR1;
		p = g;
	    }
	    exp = exp - i;
	}
}
SET_LEN_PLIST( hdP, p );
return hdP;
}
TypHandle PowerModVecFFEIntVecFFE ( hdG, hdE, hdR )
TypHandle       	hdG;
TypHandle       	hdE;
TypHandle       	hdR;
{
TypHandle	        hdP;
TypHandle           hdR1;
TypHandle           hdR2;
long                g;
long                r;
long                p;
unsigned long       exp;
unsigned long       i;
r = LEN_VECFFE(hdR);
if ( r == 0 ) {
	Error( "<r> must be non zero", 0L, 0L );
	return 0;
}
for ( ;  0 < r;  r-- ) {
	if ( VAL_VECFFE( hdR, r ) != 0 )
	    break;
}
if ( r == 0 ) {
	Error( "<r> must be non zero", 0L, 0L );
	return 0;
}
hdG = Copy(hdG);
g   = REDUCE_COEFFS( hdG, LEN_LIST(hdG), hdR, r );
for ( ;  0 < g;  g-- ) {
	if ( VAL_VECFFE( hdG, g ) != 0 )
	    break;
}
if ( g == 0 ) {
	hdG = NewBag( T_LIST, SIZE_PLEN_PLIST(0) );
	SET_LEN_PLIST( hdG, 0 );
	return hdG;
}
hdR1 = Copy(hdG);
hdR2 = NewBag( T_VECFFE, SIZE_PLEN_VECFFE(2*r) );
SET_FLD_VECFFE( hdR2, FLD_VECFFE(hdR1) );
Resize( hdR1, SIZE_PLEN_VECFFE(2*r) );
i   = 1 << 31;
p   = 0;
hdP = 0;
exp = HD_TO_INT(hdE);
while ( 1 < i ) {
	if ( hdP ) {
	
	    p = TabMultiplyCoeffs[T_VECFFE][T_VECFFE](hdR2,hdP,p,hdP,p);
	    p = TabReduceCoeffs[T_VECFFE][T_VECFFE]( hdR2, p, hdR, r );
	    hdR1 = hdP;  hdP = hdR2;  hdR2 = hdR1;
	}
	i = i / 2;
	if ( i <= exp ) {
	    if ( hdP ) {
		
		p = TabMultiplyCoeffs[T_VECFFE][T_VECFFE](hdR2,hdP,p,hdG,g);
		p = TabReduceCoeffs[T_VECFFE][T_VECFFE](hdR2,p,hdR,r);
		hdR1 = hdP;  hdP = hdR2;  hdR2 = hdR1;
	    }
	    else {
		hdP = hdR1;
		p = g;
	    }
	    exp = exp - i;
	}
}
SET_LEN_VECFFE( hdP, p );
return hdP;
}
TypHandle PowerModListxLIntListx ( hdG, hdE, hdR )
TypHandle       	hdG;
TypHandle       	hdE;
TypHandle       	hdR;
{
TypHandle	        hdP;
TypHandle           hdR1;
TypHandle           hdR2;
TypDigit            e;
long                g;
long                r;
long                p;
unsigned long       i;
long                l;
r = LEN_LIST(hdR);
if ( r == 0 ) {
	Error( "<r> must be non zero", 0L, 0L );
	return 0;
}
hdR1 = PROD( ELML_LIST( hdR, 1 ), INT_TO_HD(0) );
for ( ;  0 < r;  r-- ) {
	hdR2 = ELMR_LIST( hdR, r );
	if ( EQ( hdR1, hdR2 ) == HdFalse )
	    break;
}
if ( r == 0 ) {
	Error( "<r> must be non zero", 0L, 0L );
	return 0;
}
hdG = Copy(hdG);
g   = REDUCE_COEFFS( hdG, LEN_LIST(hdG), hdR, r );
for ( ;  0 < g;  g-- ) {
	hdR2 = ELMR_LIST( hdG, g );
	if ( EQ( hdR1, hdR2 ) == HdFalse )
	    break;
}
if ( g == 0 ) {
	hdG = NewBag( T_LIST, SIZE_PLEN_PLIST(0) );
	SET_LEN_PLIST( hdG, 0 );
	return hdG;
}
hdR1 = Copy(hdG);
hdR2 = NewBag( T_LIST, SIZE_PLEN_PLIST(2*r) );
PLAIN_LIST(hdR1);
PLAIN_LIST(hdG);
Resize( hdR1, SIZE_PLEN_PLIST(2*r) );
SET_LEN_PLIST( hdR1, 2*r );
hdP = 0;
p   = 0;
for ( l = SIZE(hdE)/sizeof(TypDigit)-1;  0 <= l;  l-- ) {
	i = 1 << (8*sizeof(TypDigit));
	e = ((TypDigit*) PTR(hdE))[l];
	while ( 1 < i ) {
	    if ( hdP ) {
		
		p = TabMultiplyCoeffs[T_LISTX][T_LISTX](hdR2,hdP,p,hdP,p);
		p = TabReduceCoeffs[T_LISTX][T_LISTX]( hdR2, p, hdR, r );
		hdR1 = hdP;  hdP = hdR2;  hdR2 = hdR1;
	    }
	    i = i / 2;
	    if ( i <= e ) {
		if ( hdP ) {
		
p = TabMultiplyCoeffs[T_LISTX][T_LISTX](hdR2,hdP,p,hdG,g);
		   p = TabReduceCoeffs[T_LISTX][T_LISTX]( hdR2, p, hdR, r );
		   hdR1 = hdP;  hdP = hdR2;  hdR2 = hdR1;
		}
		else {
		    hdP = hdR1;
		    p = g;
		}
		e = e - i;
	    }
	}
}
SET_LEN_PLIST( hdP, p );
return hdP;
}
TypHandle PowerModVecFFELIntVecFFE ( hdG, hdE, hdR )
TypHandle       	hdG;
TypHandle       	hdE;
TypHandle       	hdR;
{
TypHandle	        hdP;
TypHandle           hdR1;
TypHandle           hdR2;
TypDigit            e;
long                g;
long                r;
long                p;
unsigned long       i;
long                l;
r = LEN_VECFFE(hdR);
if ( r == 0 ) {
	Error( "<r> must be non zero", 0L, 0L );
	return 0;
}
for ( ;  0 < r;  r-- ) {
	if ( VAL_VECFFE( hdR, r ) != 0 )
	    break;
}
if ( r == 0 ) {
	Error( "<r> must be non zero", 0L, 0L );
	return 0;
}
hdG = Copy(hdG);
g   = REDUCE_COEFFS( hdG, LEN_LIST(hdG), hdR, r );
for ( ;  0 < g;  g-- ) {
	if ( VAL_VECFFE( hdG, g ) != 0 )
	    break;
}
if ( g == 0 ) {
	hdG = NewBag( T_LIST, SIZE_PLEN_PLIST(0) );
	SET_LEN_PLIST( hdG, 0 );
	return hdG;
}
hdR1 = Copy(hdG);
hdR2 = NewBag( T_VECFFE, SIZE_PLEN_VECFFE(2*r) );
SET_FLD_VECFFE( hdR2, FLD_VECFFE(hdR1) );
Resize( hdR1, SIZE_PLEN_VECFFE(2*r) );
hdP = 0;
p   = 0;
for ( l = SIZE(hdE)/sizeof(TypDigit)-1;  0 <= l;  l-- ) {
	i = 1 << (8*sizeof(TypDigit));
	e = ((TypDigit*) PTR(hdE))[l];
	while ( 1 < i ) {
	    if ( hdP ) {
		
		p = TabMultiplyCoeffs[T_VECFFE][T_VECFFE](hdR2,hdP,p,hdP,p);
		p = TabReduceCoeffs[T_VECFFE][T_VECFFE]( hdR2, p, hdR, r );
		hdR1 = hdP;  hdP = hdR2;  hdR2 = hdR1;
	    }
	    i = i / 2;
	    if ( i <= e ) {
		if ( hdP ) {
		
p = TabMultiplyCoeffs[T_VECFFE][T_VECFFE](hdR2,hdP,p,hdG,g);
	         p = TabReduceCoeffs[T_VECFFE][T_VECFFE]( hdR2, p, hdR, r );
	         hdR1 = hdP;  hdP = hdR2;  hdR2 = hdR1;
		}
		else {
		    hdP = hdR1;
		    p = g;
		}
		e = e - i;
	    }
	}
}
SET_LEN_VECFFE( hdP, p );
return hdP;
}
TypHandle CantPowerModCoeffs ( hdG, hdE, hdR )
TypHandle       	hdG;
TypHandle       	hdE;
TypHandle       	hdR;
{
Error( "<g> and <r> must be vectors over a common field", 0L, 0L);
return 0;
}
void InitPolynom ()
{
long            type1, type2;    	
for ( type1 = T_VOID;  type1 < T_VAR;  type1++ ) {
TabNormalizeCoeffs[type1] = CantNormalizeCoeffs;
TabShrinkCoeffs   [type1] = CantShrinkCoeffs;
TabShiftedCoeffs  [type1] = CantShiftedCoeffs;
	for ( type2 = T_VOID;  type2 < T_VAR;  type2++ ) {
	    TabAddCoeffs         [type1][type2] = CantAddCoeffs;
	    TabMultiplyCoeffs    [type1][type2] = CantMultiplyCoeffs;
	    TabProductCoeffs     [type1][type2] = CantProductCoeffs;
	    TabProductCoeffsMod  [type1][type2] = CantProductCoeffsMod;
	    TabReduceCoeffs      [type1][type2] = CantReduceCoeffs;
	    TabReduceCoeffsMod   [type1][type2] = CantReduceCoeffsMod;
	    TabPowerModCoeffsInt [type1][type2] = CantPowerModCoeffs;
	    TabPowerModCoeffsLInt[type1][type2] = CantPowerModCoeffs;
	}
}
TabNormalizeCoeffs[T_LISTX ] = NormalizeCoeffsListx;
TabNormalizeCoeffs[T_VECTOR] = NormalizeCoeffsListx;
TabNormalizeCoeffs[T_VECFFE] = NormalizeCoeffsVecFFE;
TabShrinkCoeffs[T_LISTX ] = ShrinkCoeffsListx;
TabShrinkCoeffs[T_VECTOR] = ShrinkCoeffsListx;
TabShrinkCoeffs[T_VECFFE] = ShrinkCoeffsVecFFE;
TabShiftedCoeffs  [T_LISTX ] = ShiftedCoeffsListx;
TabShiftedCoeffs  [T_VECTOR] = ShiftedCoeffsListx;
TabShiftedCoeffs  [T_VECFFE] = ShiftedCoeffsVecFFE;
TabAddCoeffs[T_LISTX ][T_LISTX ] = AddCoeffsListxListx;
TabAddCoeffs[T_LISTX ][T_VECTOR] = AddCoeffsListxListx;
TabAddCoeffs[T_LISTX ][T_VECFFE] = AddCoeffsListxVecFFE;
TabAddCoeffs[T_VECTOR][T_LISTX ] = AddCoeffsListxListx;
TabAddCoeffs[T_VECTOR][T_VECTOR] = AddCoeffsListxListx;
TabAddCoeffs[T_VECTOR][T_VECFFE] = AddCoeffsListxListx;
TabAddCoeffs[T_VECFFE][T_LISTX ] = AddCoeffsListxListx;
TabAddCoeffs[T_VECFFE][T_VECTOR] = AddCoeffsListxListx;
TabAddCoeffs[T_VECFFE][T_VECFFE] = AddCoeffsVecFFEVecFFE;
TabMultiplyCoeffs[T_LISTX ][T_LISTX ] = MultiplyCoeffsListxListx;
TabMultiplyCoeffs[T_LISTX ][T_VECTOR] = MultiplyCoeffsListxListx;
TabMultiplyCoeffs[T_LISTX ][T_VECFFE] = MultiplyCoeffsListxListx;
TabMultiplyCoeffs[T_VECTOR][T_LISTX ] = MultiplyCoeffsListxListx;
TabMultiplyCoeffs[T_VECTOR][T_VECTOR] = MultiplyCoeffsListxListx;
TabMultiplyCoeffs[T_VECTOR][T_VECFFE] = MultiplyCoeffsListxListx;
TabMultiplyCoeffs[T_VECFFE][T_LISTX ] = MultiplyCoeffsListxListx;
TabMultiplyCoeffs[T_VECFFE][T_VECTOR] = MultiplyCoeffsListxListx;
TabMultiplyCoeffs[T_VECFFE][T_VECFFE] = MultiplyCoeffsVecFFEVecFFE;
TabProductCoeffs[T_LISTX ][T_LISTX ] = ProductCoeffsListxListx;
TabProductCoeffs[T_LISTX ][T_VECTOR] = ProductCoeffsListxListx;
TabProductCoeffs[T_LISTX ][T_VECFFE] = ProductCoeffsListxListx;
TabProductCoeffs[T_VECTOR][T_LISTX ] = ProductCoeffsListxListx;
TabProductCoeffs[T_VECTOR][T_VECTOR] = ProductCoeffsListxListx;
TabProductCoeffs[T_VECTOR][T_VECFFE] = ProductCoeffsListxListx;
TabProductCoeffs[T_VECFFE][T_LISTX ] = ProductCoeffsListxListx;
TabProductCoeffs[T_VECFFE][T_VECTOR] = ProductCoeffsListxListx;
TabProductCoeffs[T_VECFFE][T_VECFFE] = ProductCoeffsVecFFEVecFFE;
TabProductCoeffsMod[T_LISTX ][T_LISTX ] = ProductCoeffsModListxListx;
TabProductCoeffsMod[T_LISTX ][T_VECTOR] = ProductCoeffsModListxListx;
TabProductCoeffsMod[T_LISTX ][T_VECFFE] = ProductCoeffsModListxListx;
TabProductCoeffsMod[T_VECTOR][T_LISTX ] = ProductCoeffsModListxListx;
TabProductCoeffsMod[T_VECTOR][T_VECTOR] = ProductCoeffsModListxListx;
TabProductCoeffsMod[T_VECTOR][T_VECFFE] = ProductCoeffsModListxListx;
TabProductCoeffsMod[T_VECFFE][T_LISTX ] = ProductCoeffsModListxListx;
TabProductCoeffsMod[T_VECFFE][T_VECTOR] = ProductCoeffsModListxListx;
TabProductCoeffsMod[T_VECFFE][T_VECFFE] = ProductCoeffsModListxListx;
TabReduceCoeffs[T_LISTX ][T_LISTX ] = ReduceCoeffsListxListx;
TabReduceCoeffs[T_LISTX ][T_VECTOR] = ReduceCoeffsListxListx;
TabReduceCoeffs[T_LISTX ][T_VECFFE] = ReduceCoeffsListxListx;
TabReduceCoeffs[T_VECTOR][T_LISTX ] = ReduceCoeffsListxListx;
TabReduceCoeffs[T_VECTOR][T_VECTOR] = ReduceCoeffsListxListx;
TabReduceCoeffs[T_VECTOR][T_VECFFE] = ReduceCoeffsListxListx;
TabReduceCoeffs[T_VECFFE][T_LISTX ] = ReduceCoeffsListxListx;
TabReduceCoeffs[T_VECFFE][T_VECTOR] = ReduceCoeffsListxListx;
TabReduceCoeffs[T_VECFFE][T_VECFFE] = ReduceCoeffsVecFFEVecFFE;
TabReduceCoeffsMod[T_LISTX ][T_LISTX ] = ReduceCoeffsModListxListx;
TabReduceCoeffsMod[T_LISTX ][T_VECTOR] = ReduceCoeffsModListxListx;
TabReduceCoeffsMod[T_LISTX ][T_VECFFE] = ReduceCoeffsModListxListx;
TabReduceCoeffsMod[T_LISTX ][T_VOID  ] = ReduceCoeffsModListx;
TabReduceCoeffsMod[T_VECTOR][T_LISTX ] = ReduceCoeffsModListxListx;
TabReduceCoeffsMod[T_VECTOR][T_VECTOR] = ReduceCoeffsModListxListx;
TabReduceCoeffsMod[T_VECTOR][T_VECFFE] = ReduceCoeffsModListxListx;
TabReduceCoeffsMod[T_VECTOR][T_VOID  ] = ReduceCoeffsModListx;
TabReduceCoeffsMod[T_VECFFE][T_LISTX ] = ReduceCoeffsModListxListx;
TabReduceCoeffsMod[T_VECFFE][T_VECTOR] = ReduceCoeffsModListxListx;
TabReduceCoeffsMod[T_VECFFE][T_VECFFE] = ReduceCoeffsModListxListx;
TabReduceCoeffsMod[T_VECFFE][T_VOID  ] = ReduceCoeffsModListx;
TabPowerModCoeffsInt[T_LISTX ][T_LISTX ] = PowerModListxIntListx;
TabPowerModCoeffsInt[T_LISTX ][T_VECTOR] = PowerModListxIntListx;
TabPowerModCoeffsInt[T_LISTX ][T_VECFFE] = PowerModListxIntListx;
TabPowerModCoeffsInt[T_VECTOR][T_LISTX ] = PowerModListxIntListx;
TabPowerModCoeffsInt[T_VECTOR][T_VECTOR] = PowerModListxIntListx;
TabPowerModCoeffsInt[T_VECTOR][T_VECFFE] = PowerModListxIntListx;
TabPowerModCoeffsInt[T_VECFFE][T_LISTX ] = PowerModListxIntListx;
TabPowerModCoeffsInt[T_VECFFE][T_VECTOR] = PowerModListxIntListx;
TabPowerModCoeffsInt[T_VECFFE][T_VECFFE] = PowerModVecFFEIntVecFFE;
TabPowerModCoeffsLInt[T_LISTX ][T_LISTX ] = PowerModListxLIntListx;
TabPowerModCoeffsLInt[T_LISTX ][T_VECTOR] = PowerModListxLIntListx;
TabPowerModCoeffsLInt[T_LISTX ][T_VECFFE] = PowerModListxLIntListx;
TabPowerModCoeffsLInt[T_VECTOR][T_LISTX ] = PowerModListxLIntListx;
TabPowerModCoeffsLInt[T_VECTOR][T_VECTOR] = PowerModListxLIntListx;
TabPowerModCoeffsLInt[T_VECTOR][T_VECFFE] = PowerModListxLIntListx;
TabPowerModCoeffsLInt[T_VECFFE][T_LISTX ] = PowerModListxLIntListx;
TabPowerModCoeffsLInt[T_VECFFE][T_VECTOR] = PowerModListxLIntListx;
TabPowerModCoeffsLInt[T_VECFFE][T_VECFFE] = PowerModVecFFELIntVecFFE;
InstIntFunc( "ShiftedCoeffs",   	FunShiftedCoeffs    );
InstIntFunc( "NormalizeCoeffs",     FunNormalizeCoeffs  );
InstIntFunc( "ShrinkCoeffs",        FunShrinkCoeffs  );
InstIntFunc( "AddCoeffs",       	FunAddCoeffs 	    );
InstIntFunc( "SumCoeffs",       	FunSumCoeffs 	    );
InstIntFunc( "ProductCoeffs",   	FunProductCoeffs    );
InstIntFunc( "ProductCoeffsMod",	FunProductCoeffsMod );
InstIntFunc( "ReduceCoeffs",    	FunReduceCoeffs     );
InstIntFunc( "RemainderCoeffs", 	FunRemainderCoeffs  );
InstIntFunc( "ReduceCoeffsMod", 	FunReduceCoeffsMod  );
InstIntFunc( "PowerModCoeffs",  	FunPowerModCoeffs   );
}
/* 当前文件是D:\Read\range.c*/

long            LenRange ( hdList )
TypHandle           hdList;
{
return LEN_RANGE( hdList );
}
TypHandle       ElmRange ( hdList, pos )
TypHandle           hdList;
long                pos;
{
if ( LEN_RANGE( hdList ) < pos ) {
return Error(
"List Element: <list>[%d] must have a value",
pos, 0L );
}
return ELM_RANGE( hdList, pos );
}
TypHandle       ElmfRange ( hdList, pos )
TypHandle           hdList;
long                pos;
{
return ELM_RANGE( hdList, pos );
}
TypHandle       ElmsRange ( hdList, hdPoss )
TypHandle           hdList;
TypHandle           hdPoss;
{
TypHandle           hdElms;
long                lenList;
TypHandle           hdElm;
long                lenPoss;
long                pos;
long                inc;
long                i;
if ( TYPE(hdPoss) != T_RANGE ) {
lenList = LEN_RANGE( hdList );
lenPoss = LEN_LIST( hdPoss );
hdElms = NewBag( T_LIST, SIZE_PLEN_PLIST( lenPoss ) );
SET_LEN_PLIST( hdElms, lenPoss );
for ( i = 1; i <= lenPoss; i++ ) {
pos = HD_TO_INT( ELMF_LIST( hdPoss, i ) );
if ( lenList < pos ) {
return Error(
"List Elements: <list>[%d] must have a value",
pos, 0L );
}
hdElm = ELM_RANGE( hdList, pos );
SET_ELM_PLIST( hdElms, i, hdElm );
}
}
else {
lenList = LEN_RANGE( hdList );
lenPoss = LEN_RANGE( hdPoss );
pos = LOW_RANGE( hdPoss );
inc = INC_RANGE( hdPoss );
if ( lenList < pos ) {
return Error(
"List Elements: <list>[%d] must have a value",
pos, 0L );
}
if ( lenList < pos + (lenPoss-1) * inc ) {
return Error(
"List Elements: <list>[%d] must have a value",
pos + (lenPoss-1) * inc, 0L );
}
hdElms = NewBag( T_RANGE, SIZE_PLEN_RANGE( lenPoss ) );
SET_LEN_RANGE( hdElms, lenPoss );
SET_LOW_RANGE( hdElms, HD_TO_INT( ELM_RANGE( hdList, pos ) ) );
SET_INC_RANGE( hdElms, inc * INC_RANGE( hdList ) );
}
return hdElms;
}
TypHandle       AssRange ( hdList, pos, hdVal )
TypHandle           hdList;
long                pos;
TypHandle           hdVal;
{
long                plen;
PLAIN_LIST( hdList );
Retype( hdList, T_LIST );
if ( LEN_PLIST( hdList ) < pos ) {
plen = PLEN_SIZE_PLIST( SIZE(hdList) );
if ( plen + plen/8 + 4 < pos )
Resize( hdList, SIZE_PLEN_PLIST( pos ) );
else if ( plen < pos )
Resize( hdList, SIZE_PLEN_PLIST( plen + plen/8 + 4 ) );
SET_LEN_PLIST( hdList, pos );
}
SET_ELM_PLIST( hdList, pos, hdVal );
return hdVal;
}
TypHandle       AsssRange ( hdList, hdPoss, hdVals )
TypHandle           hdList;
TypHandle           hdPoss;
TypHandle           hdVals;
{
PLAIN_LIST( hdList );
Retype( hdList, T_LIST );
return ASSS_LIST( hdList, hdPoss, hdVals );
}
long            PosRange ( hdList, hdVal, start )
TypHandle           hdList;
TypHandle           hdVal;
long                start;
{
long                k;
long                lenList;
long                low;
long                inc;
long                val;
lenList = LEN_RANGE(hdList);
low     = LOW_RANGE(hdList);
inc     = INC_RANGE(hdList);
if ( start == lenList ) {
k = 0;
}
else if ( TYPE(hdVal) == T_INT ) {
val = HD_TO_INT(hdVal);
if ( 0 < inc
&& low + start * inc <= val && val <= low + (lenList-1) * inc
&& (val - low) % inc == 0 ) {
k = (val - low) / inc + 1;
}
else if ( inc < 0
&& low + (lenList-1) * inc <= val && val <= low + start * inc
&& (val - low) % inc == 0 ) {
k = (val - low) / inc + 1;
}
else {
k = 0;
}
}
else if ( TYPE(hdVal) == T_REC ) {
for ( k = start+1; k <= lenList; k++ ) {
if ( EQ( INT_TO_HD( low + (k-1) * inc ), hdVal ) == HdTrue )
break;
}
if ( lenList < k ) {
k = 0;
}
}
else {
k = 0;
}
return k;
}
void            PlainRange ( hdList )
TypHandle           hdList;
{
long                lenList;
long                low;
long                inc;
long                i;
lenList = LEN_RANGE( hdList );
low     = LOW_RANGE( hdList );
inc     = INC_RANGE( hdList );
Retype( hdList, T_LIST );
Resize( hdList, SIZE_PLEN_PLIST( lenList ) );
SET_LEN_PLIST( hdList, lenList );
for ( i = 1; i <= lenList; i++ ) {
SET_ELM_PLIST( hdList, i, INT_TO_HD( low + (i-1) * inc ) );
}
}
long            IsDenseRange ( hdList )
TypHandle           hdList;
{
return 1;
}
long            IsPossRange ( hdList )
TypHandle           hdList;
{
if ( LOW_RANGE( hdList ) <= 0 )
return 0;
if ( HD_TO_INT( ELM_RANGE( hdList, LEN_RANGE(hdList) ) ) <= 0 )
return 0;
return 1;
}
void            PrRange ( hdRange )
TypHandle           hdRange;
{
Pr( "%2>[ %2>%d",
LOW_RANGE(hdRange), 0L );
if ( INC_RANGE(hdRange) != 1 )
Pr( "%<,%< %2>%d",
LOW_RANGE(hdRange)+INC_RANGE(hdRange), 0L );
Pr( "%2< .. %2>%d%4< ]",
LOW_RANGE(hdRange)+(LEN_RANGE(hdRange)-1)*INC_RANGE(hdRange),0L);
}
TypHandle       EqRange ( hdL, hdR )
TypHandle           hdL;
TypHandle           hdR;
{
if ( LEN_RANGE(hdL) == LEN_RANGE(hdR)
&& LOW_RANGE(hdL) == LOW_RANGE(hdR)
&& INC_RANGE(hdL) == INC_RANGE(hdR) ) {
return HdTrue;
}
else {
return HdFalse;
}
}
TypHandle       LtRange ( hdL, hdR )
TypHandle           hdL;
TypHandle           hdR;
{
if ( LOW_RANGE(hdL) < LOW_RANGE(hdR) )
return HdTrue;
else if ( LOW_RANGE(hdR) < LOW_RANGE(hdL) )
return HdFalse;
if ( INC_RANGE(hdL) < INC_RANGE(hdR) )
return HdTrue;
else if ( INC_RANGE(hdR) < INC_RANGE(hdL) )
return HdFalse;
if ( LEN_RANGE(hdL) < LEN_RANGE(hdR) )
return HdTrue;
else if ( LEN_RANGE(hdR) < LEN_RANGE(hdL) )
return HdFalse;
return HdFalse;
}
TypHandle       EvMakeRange ( hdMake )
TypHandle           hdMake;
{
TypHandle           hdRange;
TypHandle           hdL;
long                low;
TypHandle           hdH;
long                high;
long                inc;
hdL = EVAL( PTR(hdMake)[0] );
if ( TYPE(hdL) != T_INT )
return Error("Range: <low> must be an integer",0L,0L);
low = HD_TO_INT( hdL );
if ( SIZE( hdMake ) == 3 * SIZE_HD ) {
hdH = EVAL( PTR(hdMake)[1] );
if ( TYPE(hdH) != T_INT )
return Error("Range: <second> must be an integer",0L,0L);
if ( HD_TO_INT( hdH ) == low )
return Error("Range: <second> must not be equal to <low>",0L,0L);
inc = HD_TO_INT( hdH ) - low;
}
else {
inc = 1;
}
hdH = EVAL( PTR(hdMake)[SIZE(hdMake)/SIZE_HD-1] );
if ( TYPE( hdH ) != T_INT )
return Error("Range: <high> must be an integer",0L,0L);
high = HD_TO_INT( hdH );
if ( (high - low) % inc != 0 )
return Error("Range: <high>-<low> must be divisible by <inc>",0L,0L);
if ( (0 < inc && high < low) || (inc < 0 && low < high) ) {
hdRange = NewBag( T_LIST, SIZE_PLEN_PLIST( 0 ) );
SET_LEN_PLIST( hdRange, 0 );
}
else if ( low == high ) {
hdRange = NewBag( T_LIST, SIZE_PLEN_PLIST( 1 ) );
SET_LEN_PLIST( hdRange, 1 );
SET_ELM_PLIST( hdRange, 1, INT_TO_HD( low ) );
}
else {
hdRange = NewBag( T_RANGE, SIZE_PLEN_RANGE( (high-low) / inc + 1 ) );
SET_LEN_RANGE( hdRange, (high-low) / inc + 1 );
SET_LOW_RANGE( hdRange, low );
SET_INC_RANGE( hdRange, inc );
}
return hdRange;
}
void            PrMakeRange ( hdMake )
TypHandle           hdMake;
{
if ( SIZE( hdMake ) == 2 * SIZE_HD ) {
Pr("%2>[ %2>",0L,0L);    Print( PTR(hdMake)[0] );
Pr("%2< .. %2>",0L,0L);  Print( PTR(hdMake)[1] );
Pr(" %4<]",0L,0L);
}
else {
Pr("%2>[ %2>",0L,0L);    Print( PTR(hdMake)[0] );
Pr("%<,%< %2>",0L,0L);   Print( PTR(hdMake)[1] );
Pr("%2< .. %2>",0L,0L);  Print( PTR(hdMake)[2] );
Pr(" %4<]",0L,0L);
}
}
long            IsRange ( hdList )
TypHandle           hdList;
{
long                isRange;
long                len;
long                low;
long                inc;
long                i;
if ( TYPE(hdList) == T_RANGE ) {
isRange = 1;
}
else if ( ! IS_LIST( hdList ) ) {
isRange = 0;
}
else if ( LEN_LIST(hdList) == 0 ) {
isRange = 1;
}
else if ( LEN_LIST(hdList)==1 && TYPE(ELMF_LIST(hdList,1))==T_INT ) {
isRange = 1;
}
else if ( ELMF_LIST(hdList,1)==0 || TYPE(ELMF_LIST(hdList,1))!=T_INT ) {
isRange = 0;
}
else if ( ELMF_LIST(hdList,2)==0 || TYPE(ELMF_LIST(hdList,2))!=T_INT ) {
isRange = 0;
}
else if ( ELMF_LIST(hdList,1) == ELMF_LIST(hdList,2) ) {
isRange = 0;
}
else {
len = LEN_LIST(hdList);
low = HD_TO_INT( ELMF_LIST( hdList, 1 ) );
inc = HD_TO_INT( ELMF_LIST( hdList, 2 ) ) - low;
for ( i = 3;  i <= len;  i++ ) {
if ( ELMF_LIST(hdList,i) != INT_TO_HD( low + (i-1) * inc ) )
break;
}
isRange = (len < i);
if ( isRange && 2 < len ) {
Retype( hdList, T_RANGE );
Resize( hdList, SIZE_PLEN_RANGE( len ) );
SET_LEN_RANGE( hdList, len );
SET_LOW_RANGE( hdList, low );
SET_INC_RANGE( hdList, inc );
}
}
return isRange;
}
TypHandle       FunIsRange ( hdCall )
TypHandle           hdCall;
{
TypHandle           hdObj;
if ( SIZE(hdCall) != 2 * SIZE_HD )
return Error("usage: IsRange( <obj> )",0L,0L);
hdObj = EVAL( PTR(hdCall)[1] );
if ( hdObj == HdVoid )
return Error("IsRange: function must return a value",0L,0L);
return IsRange(hdObj) ? HdTrue : HdFalse;
}
void            InitRange ()
{
TabIsList[T_RANGE]      = 1;
TabLenList[T_RANGE]     = LenRange;
TabElmList[T_RANGE]     = ElmRange;
TabElmfList[T_RANGE]    = ElmfRange;
TabElmlList[T_RANGE]    = ElmfRange;
TabElmrList[T_RANGE]    = ElmfRange;
TabElmsList[T_RANGE]    = ElmsRange;
TabAssList[T_RANGE]     = AssRange;
TabAsssList[T_RANGE]    = AsssRange;
TabPosList[T_RANGE]     = PosRange;
TabPlainList[T_RANGE]   = PlainRange;
TabIsDenseList[T_RANGE] = IsDenseRange;
TabIsPossList[T_RANGE]  = IsPossRange;
EvTab[T_RANGE]          = EvList;
PrTab[T_RANGE]          = PrRange;
TabLt[T_RANGE][T_RANGE] = LtRange;
EvTab[T_MAKERANGE]      = EvMakeRange;
PrTab[T_MAKERANGE]      = PrMakeRange;
InstIntFunc( "IsRange", FunIsRange );
}
/* 当前文件是D:\Read\rational.c*/

TypHandle       EvRat ( hdRat )
TypHandle           hdRat;
{
return hdRat;
}
TypHandle       SumRat ( hdL, hdR )
TypHandle           hdL, hdR;
{
TypHandle           numL, denL;
TypHandle           numR, denR;
TypHandle           hdG1, hdG2;
TypHandle           numS, denS;
TypHandle           hdS;
if ( TYPE(hdL) == T_RAT ) { numL = PTR(hdL)[0];  denL = PTR(hdL)[1];  }
else {                      numL = hdL;          denL = INT_TO_HD(1); }
if ( TYPE(hdR) == T_RAT ) { numR = PTR(hdR)[0];  denR = PTR(hdR)[1];  }
else {                      numR = hdR;          denR = INT_TO_HD(1); }
hdG1 = GcdInt( denL, denR );
if ( hdG1 == INT_TO_HD(1) ) {
numS = SumInt( ProdInt( numL, denR ), ProdInt( numR, denL ) );
denS = ProdInt( denL, denR );
}
else {
numS = SumInt( ProdInt( numL, QuoInt( denR, hdG1 ) ),
ProdInt( numR, QuoInt( denL, hdG1 ) ) );
hdG2 = GcdInt( numS, hdG1 );
numS = QuoInt( numS, hdG2 );
denS = ProdInt( QuoInt( denL, hdG1 ), QuoInt( denR, hdG2 ) );
}
if ( denS != INT_TO_HD(1) ) {
hdS  = NewBag( T_RAT, 2 * SIZE_HD );
PTR(hdS)[0] = numS;
PTR(hdS)[1] = denS;
}
else {
hdS = numS;
}
return hdS;
}
TypHandle       DiffRat ( hdL, hdR )
TypHandle           hdL, hdR;
{
TypHandle           numL, denL;
TypHandle           numR, denR;
TypHandle           hdG1, hdG2;
TypHandle           numD, denD;
TypHandle           hdD;
if ( TYPE(hdL) == T_RAT ) { numL = PTR(hdL)[0];  denL = PTR(hdL)[1];  }
else {                      numL = hdL;          denL = INT_TO_HD(1); }
if ( TYPE(hdR) == T_RAT ) { numR = PTR(hdR)[0];  denR = PTR(hdR)[1];  }
else {                      numR = hdR;          denR = INT_TO_HD(1); }
hdG1 = GcdInt( denL, denR );
if ( hdG1 == INT_TO_HD(1) ) {
numD = DiffInt( ProdInt( numL, denR ), ProdInt( numR, denL ) );
denD = ProdInt( denL, denR );
}
else {
numD = DiffInt( ProdInt( numL, QuoInt( denR, hdG1 ) ),
ProdInt( numR, QuoInt( denL, hdG1 ) ) );
hdG2 = GcdInt( numD, hdG1 );
numD = QuoInt( numD, hdG2 );
denD = ProdInt( QuoInt( denL, hdG1 ), QuoInt( denR, hdG2 ) );
}
if ( denD != INT_TO_HD(1) ) {
hdD  = NewBag( T_RAT, 2 * SIZE_HD );
PTR(hdD)[0] = numD;
PTR(hdD)[1] = denD;
}
else {
hdD = numD;
}
return hdD;
}
TypHandle       ProdRat ( hdL, hdR )
TypHandle           hdL, hdR;
{
TypHandle           numL, denL;
TypHandle           numR, denR;
TypHandle           hdG1, hdG2;
TypHandle           numP, denP;
TypHandle           hdP;
if ( TYPE(hdL) == T_RAT ) { numL = PTR(hdL)[0];  denL = PTR(hdL)[1];  }
else {                      numL = hdL;          denL = INT_TO_HD(1); }
if ( TYPE(hdR) == T_RAT ) { numR = PTR(hdR)[0];  denR = PTR(hdR)[1];  }
else {                      numR = hdR;          denR = INT_TO_HD(1); }
hdG1 = GcdInt( numL, denR );
hdG2 = GcdInt( numR, denL );
if ( hdG1 == INT_TO_HD(1) && hdG2 == INT_TO_HD(1) ) {
numP = ProdInt( numL, numR );
denP = ProdInt( denL, denR );
}
else {
numP = ProdInt( QuoInt( numL, hdG1 ), QuoInt( numR, hdG2 ) );
denP = ProdInt( QuoInt( denL, hdG2 ), QuoInt( denR, hdG1 ) );
}
if ( denP != INT_TO_HD(1) ) {
hdP = NewBag( T_RAT, 2 * SIZE_HD );
PTR(hdP)[0] = numP;
PTR(hdP)[1] = denP;
}
else {
hdP = numP;
}
return hdP;
}
TypHandle       QuoRat ( hdL, hdR )
TypHandle           hdL, hdR;
{
TypHandle           numL, denL;
TypHandle           numR, denR;
TypHandle           hdG1, hdG2;
TypHandle           numQ, denQ;
TypHandle           hdQ;
if ( TYPE(hdL) == T_RAT ) { numL = PTR(hdL)[0];  denL = PTR(hdL)[1];  }
else {                      numL = hdL;          denL = INT_TO_HD(1); }
if ( TYPE(hdR) == T_RAT ) { numR = PTR(hdR)[0];  denR = PTR(hdR)[1];  }
else {                      numR = hdR;          denR = INT_TO_HD(1); }
if ( numR == INT_TO_HD(0) )
return Error("divisor must not be zero",0L,0L);
if ( (TYPE(numR)==T_INT && HD_TO_INT(numR)<0) || TYPE(numR)==T_INTNEG ) {
numR = ProdInt( INT_TO_HD(-1), numR );
denR = ProdInt( INT_TO_HD(-1), denR );
}
hdG1 = GcdInt( numL, numR );
hdG2 = GcdInt( denR, denL );
if ( hdG1 == INT_TO_HD(1) && hdG2 == INT_TO_HD(1) ) {
numQ = ProdInt( numL, denR );
denQ = ProdInt( denL, numR );
}
else {
numQ = ProdInt( QuoInt( numL, hdG1 ), QuoInt( denR, hdG2 ) );
denQ = ProdInt( QuoInt( denL, hdG2 ), QuoInt( numR, hdG1 ) );
}
if ( denQ != INT_TO_HD(1) ) {
hdQ = NewBag( T_RAT, 2 * SIZE_HD );
PTR(hdQ)[0] = numQ;
PTR(hdQ)[1] = denQ;
}
else {
hdQ = numQ;
}
return hdQ;
}
TypHandle       ModRat ( hdL, hdR )
TypHandle           hdL, hdR;
{
TypHandle           hdA, hdAL, hdB, hdBL, hdH, hdHL, hdQ;
if ( (TYPE(hdR)==T_INT && HD_TO_INT(hdR)<0) || TYPE(hdR)==T_INTNEG )
hdR = ProdInt( INT_TO_HD(-1), hdR );
hdA = hdR;          hdAL = INT_TO_HD(0);
hdB = PTR(hdL)[1];  hdBL = INT_TO_HD(1);
while ( hdB != INT_TO_HD(0) ) {
hdQ  = QuoInt( hdA, hdB );
hdH  = hdB;  hdHL = hdBL;
hdB  = DiffInt( hdA,  ProdInt( hdQ, hdB  ) );
hdBL = DiffInt( hdAL, ProdInt( hdQ, hdBL ) );
hdA  = hdH;  hdAL = hdHL;
}
if ( hdA != INT_TO_HD(1) )
return Error("RatOps: denominator must be invertable",0L,0L);
return ModInt( ProdInt( PTR(hdL)[0], hdAL ), hdR );
}
TypHandle       PowRat ( hdL, hdR )
TypHandle           hdL, hdR;
{
TypHandle           numP, denP;
TypHandle           hdP;
numP = PowInt( PTR(hdL)[0], hdR );
denP = PowInt( PTR(hdL)[1], hdR );
if ( hdR == INT_TO_HD(0) ) {
hdP = INT_TO_HD(1);
}
else if ( hdR == INT_TO_HD(1) ) {
hdP = hdL;
}
else if ( (TYPE(hdR)==T_INT&&0<HD_TO_INT(hdR)) || TYPE(hdR)==T_INTPOS ) {
numP = PowInt( PTR(hdL)[0], hdR );
denP = PowInt( PTR(hdL)[1], hdR );
hdP = NewBag( T_RAT, 2 * SIZE_HD );
PTR(hdP)[0] = numP;
PTR(hdP)[1] = denP;
}
else if ( PTR(hdL)[0] == INT_TO_HD(1) ) {
hdP = PowInt( PTR(hdL)[1], ProdInt(INT_TO_HD(-1),hdR) );
}
else if ( PTR(hdL)[0] == INT_TO_HD(-1) ) {
hdP = ProdInt( PowInt( PTR(hdL)[0], ProdInt(INT_TO_HD(-1),hdR) ),
PowInt( PTR(hdL)[1], ProdInt(INT_TO_HD(-1),hdR) ) );
}
else {
numP = PowInt( PTR(hdL)[1], ProdInt( INT_TO_HD(-1), hdR ) );
denP = PowInt( PTR(hdL)[0], ProdInt( INT_TO_HD(-1), hdR ) );
hdP  = NewBag( T_RAT, 2 * SIZE_HD );
if ( (TYPE(denP) == T_INT && 0 < HD_TO_INT(denP))
|| TYPE(denP) == T_INTPOS ) {
PTR(hdP)[0] = numP;
PTR(hdP)[1] = denP;
}
else {
PTR(hdP)[0] = ProdInt( INT_TO_HD(-1), numP );
PTR(hdP)[1] = ProdInt( INT_TO_HD(-1), denP );
}
}
return hdP;
}
TypHandle       EqRat ( hdL, hdR )
TypHandle           hdL, hdR;
{
TypHandle           numL, denL;
TypHandle           numR, denR;
if ( TYPE(hdL) == T_RAT ) { numL = PTR(hdL)[0];  denL = PTR(hdL)[1];  }
else {                      numL = hdL;          denL = INT_TO_HD(1); }
if ( TYPE(hdR) == T_RAT ) { numR = PTR(hdR)[0];  denR = PTR(hdR)[1];  }
else {                      numR = hdR;          denR = INT_TO_HD(1); }
if ( EqInt(numL,numR) == HdTrue && EqInt(denL,denR) == HdTrue )
return HdTrue;
else
return HdFalse;
}
TypHandle       LtRat ( hdL, hdR )
TypHandle           hdL, hdR;
{
TypHandle           numL, denL;
TypHandle           numR, denR;
if ( TYPE(hdL) == T_RAT ) { numL = PTR(hdL)[0];  denL = PTR(hdL)[1];  }
else {                      numL = hdL;          denL = INT_TO_HD(1); }
if ( TYPE(hdR) == T_RAT ) { numR = PTR(hdR)[0];  denR = PTR(hdR)[1];  }
else {                      numR = hdR;          denR = INT_TO_HD(1); }
return LtInt( ProdInt( numL, denR ), ProdInt( numR, denL ) );
}
void            PrRat ( hdRat )
TypHandle           hdRat;
{
Pr("%>",0L,0L);
Print( PTR(hdRat)[0] );
Pr("%</%>",0L,0L);
Print( PTR(hdRat)[1] );
Pr("%<",0L,0L);
}
TypHandle       FunIsRat ( hdCall )
TypHandle           hdCall;
{
TypHandle           hdObj;
if ( SIZE(hdCall) != 2 * SIZE_HD )
return Error("usage: IsRat( <obj> )",0L,0L);
hdObj = EVAL( PTR(hdCall)[1] );
if ( hdObj == HdVoid )
return Error("IsRat: function must return a value",0L,0L);
if ( TYPE(hdObj) == T_RAT    || TYPE(hdObj) == T_INT
|| TYPE(hdObj) == T_INTPOS || TYPE(hdObj) == T_INTNEG )
return HdTrue;
else
return HdFalse;
}
TypHandle       FunNumerator ( hdCall )
TypHandle           hdCall;
{
TypHandle           hdRat;
if ( SIZE(hdCall) != 2 * SIZE_HD )
return Error("usage: Numerator( <rat> )",0L,0L);
hdRat = EVAL( PTR(hdCall)[1] );
if ( hdRat == HdVoid )
return Error("Numerator: function must return a value",0L,0L);
if ( TYPE(hdRat) != T_RAT    && TYPE(hdRat) != T_INT
&& TYPE(hdRat) != T_INTPOS && TYPE(hdRat) != T_INTNEG )
return Error("usage: Numerator( <rat> )",0L,0L);
if ( TYPE(hdRat) == T_RAT )
return PTR(hdRat)[0];
else
return hdRat;
}
TypHandle       FunDenominator ( hdCall )
TypHandle           hdCall;
{
TypHandle           hdRat;
if ( SIZE(hdCall) != 2 * SIZE_HD )
return Error("usage: Denominator( <rat> )",0L,0L);
hdRat = EVAL( PTR(hdCall)[1] );
if ( hdRat == HdVoid )
return Error("Denominator: function must return a value",0L,0L);
if ( TYPE(hdRat) != T_RAT    && TYPE(hdRat) != T_INT
&& TYPE(hdRat) != T_INTPOS && TYPE(hdRat) != T_INTNEG )
return Error("usage: Denominator( <rat> )",0L,0L);
if ( TYPE(hdRat) == T_RAT )
return PTR(hdRat)[1];
else
return INT_TO_HD(1);
}
void            InitRat ()
{
InstEvFunc( T_RAT, EvRat );
InstPrFunc( T_RAT, PrRat );
TabSum[  T_RAT    ][ T_RAT    ] = SumRat;
TabSum[  T_INT    ][ T_RAT    ] = SumRat;
TabSum[  T_INTPOS ][ T_RAT    ] = SumRat;
TabSum[  T_INTNEG ][ T_RAT    ] = SumRat;
TabSum[  T_RAT    ][ T_INT    ] = SumRat;
TabSum[  T_RAT    ][ T_INTPOS ] = SumRat;
TabSum[  T_RAT    ][ T_INTNEG ] = SumRat;
TabDiff[ T_RAT    ][ T_RAT    ] = DiffRat;
TabDiff[ T_INT    ][ T_RAT    ] = DiffRat;
TabDiff[ T_INTPOS ][ T_RAT    ] = DiffRat;
TabDiff[ T_INTNEG ][ T_RAT    ] = DiffRat;
TabDiff[ T_RAT    ][ T_INT    ] = DiffRat;
TabDiff[ T_RAT    ][ T_INTPOS ] = DiffRat;
TabDiff[ T_RAT    ][ T_INTNEG ] = DiffRat;
TabProd[ T_RAT    ][ T_RAT    ] = ProdRat;
TabProd[ T_INT    ][ T_RAT    ] = ProdRat;
TabProd[ T_INTPOS ][ T_RAT    ] = ProdRat;
TabProd[ T_INTNEG ][ T_RAT    ] = ProdRat;
TabProd[ T_RAT    ][ T_INT    ] = ProdRat;
TabProd[ T_RAT    ][ T_INTPOS ] = ProdRat;
TabProd[ T_RAT    ][ T_INTNEG ] = ProdRat;
TabQuo[  T_INT    ][ T_INT    ] = QuoRat;
TabQuo[  T_INT    ][ T_INTPOS ] = QuoRat;
TabQuo[  T_INT    ][ T_INTNEG ] = QuoRat;
TabQuo[  T_INTPOS ][ T_INT    ] = QuoRat;
TabQuo[  T_INTPOS ][ T_INTPOS ] = QuoRat;
TabQuo[  T_INTPOS ][ T_INTNEG ] = QuoRat;
TabQuo[  T_INTNEG ][ T_INT    ] = QuoRat;
TabQuo[  T_INTNEG ][ T_INTPOS ] = QuoRat;
TabQuo[  T_INTNEG ][ T_INTNEG ] = QuoRat;
TabQuo[  T_RAT    ][ T_RAT    ] = QuoRat;
TabQuo[  T_INT    ][ T_RAT    ] = QuoRat;
TabQuo[  T_INTPOS ][ T_RAT    ] = QuoRat;
TabQuo[  T_INTNEG ][ T_RAT    ] = QuoRat;
TabQuo[  T_RAT    ][ T_INT    ] = QuoRat;
TabQuo[  T_RAT    ][ T_INTPOS ] = QuoRat;
TabQuo[  T_RAT    ][ T_INTNEG ] = QuoRat;
TabMod[  T_RAT    ][ T_INT    ] = ModRat;
TabMod[  T_RAT    ][ T_INTPOS ] = ModRat;
TabMod[  T_RAT    ][ T_INTNEG ] = ModRat;
TabPow[  T_RAT    ][ T_INT    ] = PowRat;
TabPow[  T_RAT    ][ T_INTPOS ] = PowRat;
TabPow[  T_RAT    ][ T_INTNEG ] = PowRat;
TabEq[   T_RAT    ][ T_RAT    ] = EqRat;
TabLt[   T_RAT    ][ T_RAT    ] = LtRat;
TabLt[   T_INT    ][ T_RAT    ] = LtRat;
TabLt[   T_INTPOS ][ T_RAT    ] = LtRat;
TabLt[   T_INTNEG ][ T_RAT    ] = LtRat;
TabLt[   T_RAT    ][ T_INT    ] = LtRat;
TabLt[   T_RAT    ][ T_INTPOS ] = LtRat;
TabLt[   T_RAT    ][ T_INTNEG ] = LtRat;
InstIntFunc( "IsRat",       FunIsRat       );
InstIntFunc( "Numerator",   FunNumerator   );
InstIntFunc( "Denominator", FunDenominator );
}
/* 当前文件是D:\Read\read.c*/

TypHandle       RdExpr P(( TypSymbolSet follow ));
TypHandle       RdStats P(( TypSymbolSet follow ));
TypHandle       BinBag ( type, hdL, hdR )
unsigned int        type;
TypHandle           hdL,  hdR;
{
TypHandle           hdBin;
if ( NrError >= 1 )  return 0;
hdBin = NewBag( type, 2 * SIZE_HD );
PTR(hdBin)[0] = hdL;  PTR(hdBin)[1] = hdR;
return hdBin;
}
TypHandle       HdCurLHS;
TypHandle       RdVar ( follow )
TypSymbolSet        follow;
{
TypHandle           hdVar,  hd;
TypHandle           hdTmp;
long                level;
long                i;
if ( Symbol == S_IDENT )  hdVar = FindIdent( Value );
else                      hdVar = 0;
Match( S_IDENT, "identifier", follow );
level = 0;
if ( IsUndefinedGlobal && Symbol != S_MAPTO && hdVar != HdCurLHS ) {
SyntaxError("warning, undefined global variable");
NrError--;
NrErrLine--;
}
while ( IS_IN(Symbol,S_LBRACK|S_LBRACE|S_DOT|S_LPAREN) ) {
if ( Symbol == S_LBRACK ) {
Match( S_LBRACK, "", 0L );
hd = RdExpr( S_RBRACK|follow );
Match( S_RBRACK, "]", follow );
if ( level == 0 ) {
hdVar = BinBag( T_LISTELM, hdVar, hd );
}
else {
hdTmp = NewBag( T_LISTELML, 2*SIZE_HD+sizeof(long) );
PTR(hdTmp)[0] = hdVar;
PTR(hdTmp)[1] = hd;
*(long*)(PTR(hdTmp)+2) = level;
hdVar = hdTmp;
}
}
else if ( Symbol == S_LBRACE ) {
Match( S_LBRACE, "", 0L );
hd = RdExpr( S_RBRACE|follow );
Match( S_RBRACE, "}", follow );
if ( level == 0 ) {
hdVar = BinBag( T_LISTELMS, hdVar, hd );
}
else {
hdTmp = NewBag( T_LISTELMSL, 2*SIZE_HD+sizeof(long) );
PTR(hdTmp)[0] = hdVar;
PTR(hdTmp)[1] = hd;
*(long*)(PTR(hdTmp)+2) = level;
hdVar = hdTmp;
}
level += 1;
}
else if ( Symbol == S_DOT ) {
Match( S_DOT, "", 0L );
if ( Symbol == S_INT ) {
hd = FindRecname( Value );
Match( S_INT, "", follow );
}
else if ( Symbol == S_IDENT ) {
hd = FindRecname( Value );
Match( S_IDENT, "", follow );
}
else if ( Symbol == S_LPAREN ) {
Match( S_LPAREN, "", follow );
hd = RdExpr( follow );
Match( S_RPAREN, ")", follow );
if ( hd != 0 && TYPE(hd) == T_MAKESTRING )
hd = FindRecname( (char*)PTR(hd) );
}
else {
SyntaxError("record component name expected");
hd = 0;
}
hdVar = BinBag( T_RECELM, hdVar, hd );
level = 0;
}
else {
Match( S_LPAREN, "", 0L );
hd = NewBag( T_FUNCCALL, 4 * SIZE_HD );
PTR(hd)[0] = hdVar;  hdVar = hd;
i = 1;
if ( Symbol != S_RPAREN ) {
i++;
if ( SIZE(hdVar) < i * SIZE_HD )
Resize( hdVar, (i+i/8+4) * SIZE_HD );
hd = RdExpr( S_RPAREN|follow );
PTR(hdVar)[i-1] = hd;
}
while ( Symbol == S_COMMA ) {
Match( S_COMMA, "", 0L );
i++;
if ( SIZE(hdVar) < i * SIZE_HD )
Resize( hdVar, (i+i/8+4) * SIZE_HD );
hd = RdExpr( S_RPAREN|follow );
PTR(hdVar)[i-1] = hd;
}
Match( S_RPAREN, ")", follow );
Resize( hdVar, i * SIZE_HD );
level = 0;
}
}
if ( NrError >= 1 )  return 0;
return hdVar;
}
TypHandle       RdList ( follow )
TypSymbolSet        follow;
{
TypHandle           hdList;
unsigned long       len;
TypHandle           hd;
unsigned long       i;
Match( S_LBRACK, "", 0L );
hdList = NewBag( T_MAKELIST, 4 * SIZE_HD );
i = 0;
len = 0;
if ( Symbol != S_RBRACK ) {
i++;
if ( SIZE(hdList) <= i * SIZE_HD )
Resize( hdList, (i+i/8+4) * SIZE_HD );
if ( Symbol != S_COMMA ) {
hd = RdExpr( S_RBRACK|follow );
PTR(hdList)[i] = hd;
len = i;
}
}
while ( Symbol == S_COMMA ) {
Match( S_COMMA, "", 0L );
i++;
if ( SIZE(hdList) <= i*SIZE_HD )
Resize( hdList, (i+i/8+4) * SIZE_HD );
if ( Symbol != S_COMMA && Symbol != S_RBRACK ) {
hd = RdExpr( S_RBRACK|follow );
PTR(hdList)[i] = hd;
len = i;
}
}
if ( Symbol == S_DOTDOT ) {
Match( S_DOTDOT, "", 0L );
i++;
if ( 3 < i )
SyntaxError("'..' unexpexcted");
if ( SIZE(hdList) <= i*SIZE_HD )
Resize( hdList, (i+i/8+4) * SIZE_HD );
hd = RdExpr( S_RBRACK|follow );
Match( S_RBRACK, "]", follow );
PTR(hdList)[i] = hd;
if ( NrError >= 1 )  return 0;
hd = NewBag( T_MAKERANGE, i * SIZE_HD );
PTR(hd)[0] = PTR(hdList)[1];
PTR(hd)[1] = PTR(hdList)[2];
if ( i == 3 )
PTR(hd)[2] = PTR(hdList)[3];
return hd;
}
Match( S_RBRACK, "]", follow );
Resize( hdList, (i+1)*SIZE_HD );
PTR(hdList)[0] = INT_TO_HD(len);
if ( NrError >= 1 )  return 0;
return hdList;
}
TypHandle       RdRec ( follow )
TypSymbolSet        follow;
{
TypHandle           hdRec,  hd;
unsigned long       i;
Match( S_IDENT, "", 0L );
Match( S_LPAREN, "(", follow|S_RPAREN|S_COMMA );
hdRec = NewBag( T_MAKEREC, 8 * SIZE_HD );
i = 0;
if ( Symbol != S_RPAREN ) {
i++;
if ( SIZE(hdRec) < i*2*SIZE_HD )
Resize( hdRec, (i+i/8+4) * 2 * SIZE_HD );
if ( Symbol == S_INT ) {
hd = FindRecname( Value );
Match( S_INT, "", follow );
}
else if ( Symbol == S_IDENT ) {
hd = FindRecname( Value );
Match( S_IDENT, "", follow );
}
else if ( Symbol == S_LPAREN ) {
Match( S_LPAREN, "", follow );
hd = RdExpr( follow );
Match( S_RPAREN, ")", follow );
if ( hd != 0 && TYPE(hd) == T_MAKESTRING )
hd = FindRecname( (char*)PTR(hd) );
}
else {
SyntaxError("record component name expected");
hd = 0;
}
PTR(hdRec)[2*i-2] = hd;
Match( S_ASSIGN, ":=", follow );
hd = RdExpr( S_RPAREN|follow );
PTR(hdRec)[2*i-1] = hd;
}
while ( Symbol == S_COMMA ) {
Match( S_COMMA, "", 0L );
i++;
if ( SIZE(hdRec) < i * 2 * SIZE_HD )
Resize( hdRec, (i+i/8+4) * 2 * SIZE_HD );
if ( Symbol == S_INT ) {
hd = FindRecname( Value );
Match( S_INT, "", follow );
}
else if ( Symbol == S_IDENT ) {
hd = FindRecname( Value );
Match( S_IDENT, "", follow );
}
else if ( Symbol == S_LPAREN ) {
Match( S_LPAREN, "", follow );
hd = RdExpr( follow );
Match( S_RPAREN, ")", follow );
if ( hd != 0 && TYPE(hd) == T_MAKESTRING )
hd = FindRecname( (char*)PTR(hd) );
}
else {
SyntaxError("record component name expected");
hd = 0;
}
PTR(hdRec)[2*i-2] = hd;
Match( S_ASSIGN, ":=", follow );
hd = RdExpr( S_RPAREN|follow );
PTR(hdRec)[2*i-1] = hd;
}
Match( S_RPAREN, ")", follow );
Resize( hdRec, i * 2 * SIZE_HD );
if ( NrError >= 1 )  return 0;
return hdRec;
}
TypHandle       RdPerm ( hdFirst, follow )
TypHandle           hdFirst;
TypSymbolSet        follow;
{
TypHandle           hdPerm,  hdCyc,  hd;
unsigned long       i,  k,  m,  isConst;
isConst = (hdFirst != 0) && (TYPE(hdFirst) == T_INT);
hdPerm = NewBag( T_MAKEPERM, 256*SIZE_HD );  i = 1;
m = 2;
hdCyc = NewBag( T_CYCLE, m*SIZE_HD );  k = 1;
PTR(hdPerm)[i-1] = hdCyc;
PTR(hdCyc)[0] = hdFirst;
while ( Symbol == S_COMMA ) {
Match( S_COMMA, "", 0L );
if ( ++k*SIZE_HD > SIZE(hdCyc) )
Resize( hdCyc, (k+15)*SIZE_HD );
hd = RdExpr( S_RPAREN|follow );
PTR(hdCyc)[k-1] = hd;
isConst = isConst && (hd != 0) && (TYPE(hd) == T_INT);
}
Match( S_RPAREN, ")", follow );
Resize( hdCyc, k*SIZE_HD );
if ( k > m )  m = k;
while ( Symbol == S_LPAREN ) {
Match( S_LPAREN, "", 0L );
if ( ++i*SIZE_HD > SIZE(hdPerm) )
Resize( hdPerm, (i+255)*SIZE_HD );
hdCyc = NewBag( T_CYCLE, m*SIZE_HD );  k = 1;
PTR(hdPerm)[i-1] = hdCyc;
hd = RdExpr( S_RPAREN|follow );
PTR(hdCyc)[0] = hd;
while ( Symbol == S_COMMA ) {
Match( S_COMMA, "", 0L );
if ( ++k*SIZE_HD > SIZE(hdCyc) )
Resize( hdCyc, (k+15) * SIZE_HD );
hd = RdExpr( S_RPAREN|follow );
PTR(hdCyc)[k-1] = hd;
isConst = isConst && (hd != 0) && (TYPE(hd) == T_INT);
}
Match( S_RPAREN, ")", follow );
Resize( hdCyc, k*SIZE_HD );
if ( k > m )  m = k;
}
Resize( hdPerm, i*SIZE_HD );
if ( NrError >= 1 )  return 0;
if ( isConst )  return EVAL( hdPerm );
return hdPerm;
}
TypHandle       RdFunc ( follow )
TypSymbolSet        follow;
{
TypHandle           hdFun, hd;
short               nrArg = 0,  nrLoc = 0;
Match( S_FUNCTION, "", 0L );
hdFun = NewBag( T_MAKEFUNC, 2*SIZE_HD + 2*sizeof(short) );
PushFunction( hdFun );
Match( S_LPAREN, "(", S_IDENT|S_RPAREN|S_LOCAL|STATBEGIN|S_END|follow );
if ( Symbol != S_RPAREN ) {
hd = NewBag( T_VAR, SIZE_HD+SyStrlen(Value)+1 );
SyStrncat( (char*)(PTR(hd)+1), Value, SyStrlen(Value) );
Resize( hdFun, SIZE(hdFun) + SIZE_HD );
PTR(hdFun)[++nrArg] = hd;
Match( S_IDENT, "ident", S_RPAREN|S_LOCAL|STATBEGIN|S_END|follow );
}
while ( Symbol == S_COMMA ) {
Match( S_COMMA, "", 0L );
hd = NewBag( T_VAR, SIZE_HD+SyStrlen(Value)+1 );
SyStrncat( (char*)(PTR(hd)+1), Value, SyStrlen(Value) );
Resize( hdFun, SIZE(hdFun) + SIZE_HD );
PTR(hdFun)[++nrArg] = hd;
Match( S_IDENT, "ident", S_RPAREN|S_LOCAL|STATBEGIN|S_END|follow );
}
Match( S_RPAREN, ")", S_LOCAL|STATBEGIN|S_END|follow );
if ( Symbol == S_LOCAL ) {
Match( S_LOCAL, "", 0L );
hd = NewBag( T_VAR, SIZE_HD+SyStrlen(Value)+1 );
SyStrncat( (char*)(PTR(hd)+1), Value, SyStrlen(Value) );
Resize( hdFun, SIZE(hdFun) + SIZE_HD );
PTR(hdFun)[ nrArg+ ++nrLoc ] = hd;
Match( S_IDENT, "identifier", STATBEGIN|S_END|follow );
while ( Symbol == S_COMMA ) {
Match( S_COMMA, "", 0L );
hd = NewBag( T_VAR, SIZE_HD+SyStrlen(Value)+1 );
SyStrncat( (char*)(PTR(hd)+1), Value, SyStrlen(Value) );
Resize( hdFun, SIZE(hdFun) + SIZE_HD );
PTR(hdFun)[ nrArg+ ++nrLoc ] = hd;
Match( S_IDENT, "identifier", STATBEGIN|S_END|follow );
}
Match( S_SEMICOLON, ";", STATBEGIN|S_END|follow );
}
if ( nrArg == 1 && ! SyStrcmp("arg",(char*)(PTR(PTR(hdFun)[nrArg])+1)) )
nrArg = -1;
*( (short*)((char*)PTR(hdFun) + SIZE(hdFun)) - 2 ) = nrArg;
*( (short*)((char*)PTR(hdFun) + SIZE(hdFun)) - 1 ) = nrLoc;
hd = RdStats( S_END|follow );
PTR(hdFun)[0] = hd;
Match( S_END, "end", follow );
PopFunction();
if ( NrError >= 1 ) return 0;
return hdFun;
}
TypHandle       RdAtom ( follow )
TypSymbolSet        follow;
{
TypHandle           hdAt;
long                i;
unsigned long       nr, pow;
if ( Symbol == S_INT ) {
EnterKernel();
nr   = 0;
pow  = 1;
hdAt = INT_TO_HD(0);
for ( i = 0; Value[i] != '\0'; ++i ) {
nr  = 10 * nr + Value[i]-'0';
pow = 10 * pow;
if ( pow == 100000000L ) {
hdAt = SumInt( ProdInt(hdAt,INT_TO_HD(pow)), INT_TO_HD(nr) );
nr   = 0;
pow  = 1;
}
}
if ( hdAt == INT_TO_HD(0) )
hdAt = INT_TO_HD(nr);
else if ( pow != 1 )
hdAt = SumInt( ProdInt(hdAt,INT_TO_HD(pow)), INT_TO_HD(nr) );
Match(Symbol,"",0L);
ExitKernel( TYPE(hdAt) == T_INT ? 0 : hdAt );
}
else if ( Symbol == S_LPAREN ) {
Match( S_LPAREN, "", 0L );
if ( Symbol == S_RPAREN ) {
Match( S_RPAREN, "", 0L );
hdAt = NewBag( T_PERM16, 0L );
}
else {
hdAt = RdExpr( follow );
if ( Symbol == S_COMMA ) {
hdAt = RdPerm( hdAt, follow );
}
else {
Match( S_RPAREN, ")", follow );
}
}
}
else if ( Symbol == S_LBRACK ) {
hdAt = RdList( follow );
}
else if ( Symbol == S_IDENT && SyStrcmp( Value, "rec" ) == 0 ) {
hdAt = RdRec( follow );
}
else if ( Symbol == S_CHAR ) {
hdAt = NewBag( T_CHAR, 1 );
*((char*)PTR(hdAt)) = Value[0];
Match( S_CHAR, "", 0L );
}
else if ( Symbol == S_STRING ) {
hdAt = NewBag( T_MAKESTRING, (unsigned long)(SyStrlen(Value)+1) );
SyStrncat( (char*)(PTR(hdAt)), Value, SyStrlen(Value) );
Match( S_STRING, "", 0L );
}
else if ( Symbol == S_FUNCTION ) {
hdAt = RdFunc( follow );
}
else if ( Symbol == S_IDENT ) {
hdAt = RdVar( follow );
}
else {
Match( S_INT, "expression", follow );
hdAt = 0;
}
if ( NrError >= 1 )  return 0;
return hdAt;
}
TypHandle       RdFactor ( follow )
TypSymbolSet        follow;
{
TypHandle           hdFac,  hdAt;
long                sign1,  sign2;
sign1 = 0;
while ( Symbol == S_MINUS  || Symbol == S_PLUS ) {
if ( sign1 == 0 )  sign1 = 1;
if ( Symbol == S_MINUS ) sign1 = - sign1;
Match( Symbol, "", 0L );
}
hdFac = RdAtom( follow );
while ( Symbol == S_POW ) {
Match( S_POW, "", 0L );
sign2 = 0;
while ( Symbol == S_MINUS  || Symbol == S_PLUS ) {
if ( sign2 == 0 )  sign2 = 1;
if ( Symbol == S_MINUS ) sign2 = - sign2;
Match( Symbol, "", 0L );
}
hdAt = RdAtom(follow);
if ( sign2 == -1 && NrError == 0 && TYPE(hdFac) <= T_INTNEG )
hdAt = ProdInt( INT_TO_HD(-1), hdAt );
else if ( sign2 == -1 && NrError == 0 )
hdAt = BinBag( T_PROD, INT_TO_HD(-1), hdAt );
hdFac = BinBag( T_POW, hdFac, hdAt );
if ( Symbol == S_POW )  SyntaxError("'^' is not associative");
}
if ( sign1 == -1 && NrError == 0 && TYPE(hdFac) <= T_INTNEG )
hdFac = ProdInt( INT_TO_HD(-1), hdFac );
else if ( sign1 == -1 && NrError == 0 )
hdFac = BinBag( T_PROD, INT_TO_HD(-1), hdFac );
return hdFac;
}
TypHandle       RdTerm ( follow )
TypSymbolSet        follow;
{
TypHandle           hdTer,  hdFac;
unsigned int        type;
hdTer = RdFactor( follow );
while ( Symbol==S_MULT || Symbol==S_DIV || Symbol==S_MOD ) {
switch ( Symbol ) {
case S_MULT:  type = T_PROD;  break;
case S_DIV:   type = T_QUO;   break;
default:      type = T_MOD;   break;
}
Match( Symbol, "", 0L );
hdFac = RdFactor( follow );
hdTer = BinBag( type, hdTer, hdFac );
}
return hdTer;
}
TypHandle       RdAri ( follow )
TypSymbolSet        follow;
{
TypHandle           hdAri,  hdTer;
unsigned int        type;
hdAri = RdTerm( follow );
while ( IS_IN(Symbol,S_PLUS|S_MINUS) ) {
type = (Symbol == S_PLUS) ?  T_SUM :  T_DIFF;
Match( Symbol, "", 0L );
hdTer = RdTerm( follow );
hdAri = BinBag( type, hdAri, hdTer );
}
return hdAri;
}
TypHandle       RdRel ( follow )
TypSymbolSet        follow;
{
TypHandle           hdRel,  hdAri;
unsigned int        type;
short               isNot;
isNot = 0;
while ( Symbol == S_NOT ) { isNot = ! isNot;  Match( S_NOT, "", 0L ); }
hdRel = RdAri( follow );
if ( IS_IN(Symbol,S_EQ|S_LT|S_GT|S_NE|S_LE|S_GE|S_IN) ) {
switch ( Symbol ) {
case S_EQ:  type = T_EQ;  break;
case S_LT:  type = T_LT;  break;
case S_GT:  type = T_GT;  break;
case S_NE:  type = T_NE;  break;
case S_LE:  type = T_LE;  break;
case S_GE:  type = T_GE;  break;
default:    type = T_IN;  break;
}
Match( Symbol, "", 0L );
hdAri = RdAri( follow );
hdRel = BinBag( type, hdRel, hdAri );
}
if ( isNot && NrError == 0 ) {
hdAri = NewBag( T_NOT, SIZE_HD );
PTR(hdAri)[0] = hdRel;  hdRel = hdAri;
}
return hdRel;
}
TypHandle       RdAnd ( follow )
TypSymbolSet        follow;
{
TypHandle           hdAnd,  hdRel;
hdAnd = RdRel( follow );
while ( Symbol == S_AND ) {
Match( Symbol, "", 0L );
hdRel = RdRel( follow );
hdAnd = BinBag( T_AND, hdAnd, hdRel );
}
return hdAnd;
}
TypHandle       RdLog ( follow )
TypSymbolSet        follow;
{
TypHandle           hdLog,  hdAnd;
hdLog = RdAnd( follow );
while ( Symbol == S_OR ) {
Match( Symbol, "", 0L );
hdAnd = RdAnd( follow );
hdLog = BinBag( T_OR, hdLog, hdAnd );
}
return hdLog;
}
TypHandle       RdExpr ( follow )
TypSymbolSet        follow;
{
TypHandle           hdExp,  hdFun,  hdTmp;
hdExp = RdLog( follow|S_MAPTO );
if ( Symbol == S_MAPTO ) {
if ( hdExp != 0 && TYPE(hdExp) != T_VAR )
SyntaxError("left hand side of '->' must be a variable");
if ( NrError == 0 ) {
hdTmp = NewBag( T_VAR, SIZE(hdExp) );
SyStrncat( (char*)(PTR(hdTmp)+1),
(char*)(PTR(hdExp)+1),
SyStrlen( (char*)(PTR(hdExp)+1) ) );
}
else {
hdTmp = NewBag( T_VAR, SIZE_HD + 1 );
}
hdFun = NewBag( T_MAKEFUNC, 3*SIZE_HD + 2*sizeof(short) );
PTR(hdFun)[1] = hdTmp;
*( (short*)((char*)PTR(hdFun) + SIZE(hdFun)) - 2 ) = 1;
*( (short*)((char*)PTR(hdFun) + SIZE(hdFun)) - 1 ) = 0;
PushFunction( hdFun );
Match( Symbol, "", 0L );
hdExp = RdLog( follow );
hdTmp = NewBag( T_RETURN, SIZE_HD );
PTR(hdTmp)[0] = hdExp;
PTR(hdFun)[0] = hdTmp;
hdExp = hdFun;
PopFunction();
}
return hdExp;
}
TypHandle       RdIf ( follow )
TypSymbolSet        follow;
{
TypHandle           hd[128],  hdIf;
short               i = 0;
Match( S_IF, "", 0L );
hd[i++] = RdExpr( S_THEN|S_ELIF|S_ELSE|S_FI|follow );
Match( S_THEN, "then", STATBEGIN|S_ELIF|S_ELSE|S_FI|follow );
hd[i++] = RdStats( S_ELIF|S_ELSE|S_FI|follow );
while ( Symbol == S_ELIF ) {
Match( S_ELIF, "", 0L );
hd[i++] = RdExpr( S_THEN|S_ELIF|S_ELSE|S_FI|follow );
Match( S_THEN, "then", STATBEGIN|S_ELIF|S_ELSE|S_FI|follow );
hd[i++] = RdStats( S_ELIF|S_ELSE|S_FI|follow );
}
if ( Symbol == S_ELSE ) {
Match( S_ELSE, "", 0L );
hd[i++] = RdStats( S_FI|follow );
}
Match( S_FI, "fi", follow );
if ( NrError >= 1 )  return 0;
hdIf = NewBag( T_IF, i * SIZE_HD );
while ( i >= 1 ) { --i;  PTR(hdIf)[i] = hd[i]; }
return hdIf;
}
TypHandle       RdFor ( follow )
TypSymbolSet        follow;
{
TypHandle           hdVar,  hdList,  hdStats,  hdFor;
Match( S_FOR, "", 0L );
hdVar = FindIdent( Value );
Match( S_IDENT, "identifier", S_IN|S_DO|S_OD|follow );
if ( IsUndefinedGlobal ) {
SyntaxError("warning, undefined global variable");
NrError--;
NrErrLine--;
}
Match( S_IN, "in", S_DO|S_OD|follow );
hdList = RdExpr( S_DO|S_OD|follow );
Match( S_DO, "do", STATBEGIN|S_OD|follow );
hdStats = RdStats( S_OD|follow );
Match( S_OD, "od", follow );
if ( NrError >= 1 )  return 0;
hdFor = NewBag( T_FOR, 3 * SIZE_HD );
PTR(hdFor)[0] = hdVar;  PTR(hdFor)[1] = hdList;
PTR(hdFor)[2] = hdStats;
return hdFor;
}
TypHandle       RdWhile ( follow )
TypSymbolSet    follow;
{
TypHandle       hdCond,  hdStats,  hdWhile;
Match( S_WHILE, "", 0L );
hdCond = RdExpr( S_DO|S_OD|follow );
Match( S_DO, "do", STATBEGIN|S_DO|follow );
hdStats = RdStats( S_OD|follow );
Match( S_OD, "od", follow );
if ( NrError >= 1 )  return 0;
hdWhile = NewBag( T_WHILE, 2 * SIZE_HD );
PTR(hdWhile)[0] = hdCond;  PTR(hdWhile)[1] = hdStats;
return hdWhile;
}
TypHandle       RdRepeat ( follow )
TypSymbolSet    follow;
{
TypHandle       hdStats,  hdCond,  hdRep;
Match( S_REPEAT, "", 0L );
hdStats = RdStats( S_UNTIL|follow );
Match( S_UNTIL, "until", EXPRBEGIN|follow );
hdCond = RdExpr( follow );
if ( NrError >= 1 )  return 0;
hdRep = NewBag( T_REPEAT, 2 * SIZE_HD );
PTR(hdRep)[0] = hdCond;  PTR(hdRep)[1] = hdStats;
return hdRep;
}
TypHandle       RdReturn ( follow )
TypSymbolSet        follow;
{
TypHandle           hdRet,  hdExpr;
Match( S_RETURN, "", 0L );
if ( Symbol == S_SEMICOLON ) {
if ( NrError >= 1 )  return 0;
hdRet = NewBag( T_RETURN, SIZE_HD );
PTR(hdRet)[0] = HdVoid;
}
else {
hdExpr = RdExpr( follow );
if ( NrError >= 1 )  return 0;
hdRet = NewBag( T_RETURN, SIZE_HD );
PTR(hdRet)[0] = hdExpr;
}
return hdRet;
}
TypHandle       RdQuit ( follow )
TypSymbolSet        follow;
{
TypHandle           hdQuit;
Match( S_QUIT, "", follow );
hdQuit = NewBag( T_RETURN, SIZE_HD );
PTR(hdQuit)[0] = HdReturn;
return hdQuit;
}
TypHandle       RdStat ( follow )
TypSymbolSet        follow;
{
TypHandle           hd,  hdExpr,  hdAss;
if ( Symbol == S_IF      )  return RdIf( follow );
if ( Symbol == S_FOR     )  return RdFor( follow );
if ( Symbol == S_WHILE   )  return RdWhile( follow );
if ( Symbol == S_REPEAT  )  return RdRepeat( follow );
if ( Symbol == S_RETURN  )  return RdReturn( follow );
if ( Symbol == S_QUIT    )  return RdQuit( follow );
hd = RdExpr( S_ASSIGN|follow );
if ( Symbol != S_ASSIGN )  return hd;
if ( hd != 0
&& TYPE(hd) != T_VAR      && TYPE(hd) != T_VARAUTO
&& TYPE(hd) != T_LISTELM  && TYPE(hd) != T_LISTELML
&& TYPE(hd) != T_LISTELMS && TYPE(hd) != T_LISTELMSL
&& TYPE(hd) != T_RECELM  )
SyntaxError("left hand side of assignment must be a variable");
Match( S_ASSIGN, "", 0L );
if ( HdCurLHS == 0 ) {
HdCurLHS = hd;
hdExpr = RdExpr( follow );
HdCurLHS = 0;
}
else {
hdExpr = RdExpr( follow );
}
if ( NrError >= 1 )  return 0;
if      ( TYPE(hd)==T_VAR       )  hdAss = BinBag(T_VARASS,   hd,hdExpr);
else if ( TYPE(hd)==T_VARAUTO   )  hdAss = BinBag(T_VARASS,   hd,hdExpr);
else if ( TYPE(hd)==T_LISTELM   )  hdAss = BinBag(T_LISTASS,  hd,hdExpr);
else if ( TYPE(hd)==T_LISTELML  )  hdAss = BinBag(T_LISTASSL, hd,hdExpr);
else if ( TYPE(hd)==T_LISTELMS  )  hdAss = BinBag(T_LISTASSS, hd,hdExpr);
else if ( TYPE(hd)==T_LISTELMSL )  hdAss = BinBag(T_LISTASSSL,hd,hdExpr);
else                               hdAss = BinBag(T_RECASS,   hd,hdExpr);
return hdAss;
}
TypHandle       RdStats ( follow )
TypSymbolSet        follow;
{
TypHandle           hdStats,  hd [1024];
short               i = 0;
if ( Symbol == S_SEMICOLON ) {
Match( S_SEMICOLON, "", 0L );
}
else {
while ( IS_IN(Symbol,STATBEGIN) || i == 0 ) {
if ( i == 1024 ) {
SyntaxError("sorry, can not read more than 1024 statements");
i = 0;
}
hd[i++] = RdStat( S_SEMICOLON|follow );
if ( Symbol == S_SEMICOLON
&& hd[i-1] != 0                && TYPE(hd[i-1]) != T_VARASS
&& TYPE(hd[i-1]) != T_LISTASS  && TYPE(hd[i-1]) != T_LISTASSL
&& TYPE(hd[i-1]) != T_LISTASSS && TYPE(hd[i-1]) != T_LISTASSSL
&& TYPE(hd[i-1]) != T_RECASS
&& !(T_FUNCCALL<=TYPE(hd[i-1]) && TYPE(hd[i-1])<=T_RETURN)) {
SyntaxError("warning, this statement has no effect");
NrError--;
NrErrLine--;
}
Match( S_SEMICOLON, ";", follow );
}
}
if ( NrError >= 1 )  return 0;
if ( i == 1 )  return hd[0];
hdStats = NewBag( T_STATSEQ, i * SIZE_HD );
while ( i >= 1 ) { --i; PTR(hdStats)[i] = hd[i]; }
return hdStats;
}
TypHandle       ReadIt ()
{
TypHandle           hd;
Match( Symbol, "", 0L );
Prompt = "> ";
if ( Symbol == S_SEMICOLON || Symbol == S_EOF  )
return 0;
hd = RdStat( S_SEMICOLON|S_EOF );
if ( Symbol != S_SEMICOLON )
SyntaxError("; expected");
if ( Symbol == S_EOF )
return 0;
if ( NrError >= 1 )
return 0;
return hd;
}
/* 当前文件是D:\Read\record.c*/

TypHandle       EvRec ( hdRec )
TypHandle           hdRec;
{
return hdRec;
}

TypHandle       EvMakeRec ( hdLiteral )
TypHandle           hdLiteral;
{
TypHandle           hdRec;
if ( PTR(HdTilde)[0] == 0 ) {
hdRec = MakeRec( HdTilde, 0, hdLiteral );
PTR(HdTilde)[0] = 0;
}
else {
hdRec = MakeRec( 0, 0, hdLiteral );
}
return hdRec;
}
TypHandle       MakeRec ( hdDst, ind, hdLiteral )
TypHandle           hdDst;
unsigned long       ind;
TypHandle           hdLiteral;
{
TypHandle           hdRec;
TypHandle           hdNam;
TypHandle           hdVal;
unsigned long       i;
unsigned long       k;
char                value [16];
char                * p;
hdRec = NewBag( T_REC, SIZE(hdLiteral) );
if ( hdDst != 0 )  PTR(hdDst)[ind] = hdRec;
for ( i = 0; i < SIZE(hdLiteral)/SIZE_HD/2; i++ ) {
hdNam = PTR(hdLiteral)[2*i];
if ( TYPE(hdNam) != T_RECNAM ) {
hdNam = EVAL(hdNam);
if ( IsString( hdNam ) ) {
hdNam = FindRecname( (char*)PTR(hdNam) );
}
else if ( TYPE(hdNam) == T_INT && 0 <= HD_TO_INT(hdNam) ) {
k = HD_TO_INT(hdNam);
p = value + sizeof(value);  *--p = '\0';
do { *--p = '0' + k % 10; } while ( (k /= 10) != 0 );
hdNam = FindRecname( p );
}
else {
return Error("<rec>.(<name>) <name> must be a string",0L,0L);
}
}
PTR(hdRec)[2*i] = hdNam;
if ( TYPE( PTR(hdLiteral)[2*i+1] ) == T_MAKELIST ) {
MakeList( hdRec, 2*i+1, PTR(hdLiteral)[2*i+1] );
}
else if ( TYPE( PTR(hdLiteral)[2*i+1] ) == T_MAKEREC ) {
MakeRec( hdRec, 2*i+1, PTR(hdLiteral)[2*i+1] );
}
else {
hdVal             = EVAL( PTR(hdLiteral)[2*i+1] );
while ( hdVal == HdVoid )
Error("Record: function must return a value",0L,0L);
PTR(hdRec)[2*i+1] = hdVal;
}
}
return hdRec;
}
TypHandle     EvRecElm ( hdElm )
TypHandle           hdElm;
{
TypHandle           hdRec,  hdNam,  * ptRec,  *ptEnd;
unsigned long       k;
char                value [16];
char                * p;
hdRec = EVAL( PTR(hdElm)[0] );
if ( TYPE(hdRec) != T_REC )
return Error("Record: left operand must be a record",0L,0L);
hdNam = PTR(hdElm)[1];
if ( TYPE(hdNam) != T_RECNAM ) {
hdNam = EVAL(hdNam);
if ( IsString( hdNam ) ) {
hdNam = FindRecname( (char*)PTR(hdNam) );
}
else if ( TYPE(hdNam) == T_INT && 0 <= HD_TO_INT(hdNam) ) {
k = HD_TO_INT(hdNam);
p = value + sizeof(value);  *--p = '\0';
do { *--p = '0' + k % 10; } while ( (k /= 10) != 0 );
hdNam = FindRecname( p );
}
else {
return Error("<rec>.(<name>) <name> must be a string",0L,0L);
}
}
ptRec = PTR(hdRec);
ptEnd = (TypHandle*)((char*)ptRec + SIZE(hdRec));
while ( ptRec < ptEnd && ptRec[0] != hdNam )  ptRec += 2;
if ( ptRec == ptEnd ) {
return Error("Record: element '%s' must have an assigned value",
(long)PTR(hdNam), 0L );
}
return ptRec[1];
}
TypHandle       EvRecAss ( hdAss )
TypHandle           hdAss;
{
TypHandle           hdRec,  hdNam,  hdVal;
TypHandle           * ptRec,  * ptEnd;
unsigned long       k;
char                value [16];
char                * p;
hdRec = EVAL( PTR(PTR(hdAss)[0])[0] );
if ( TYPE(hdRec) != T_REC ) {
return Error(
"Record Assignment: left operand must be a record",
0L, 0L );
}
hdNam = PTR(PTR(hdAss)[0])[1];
if ( TYPE(hdNam) != T_RECNAM ) {
hdNam = EVAL(hdNam);
if ( IsString( hdNam ) ) {
hdNam = FindRecname( (char*)PTR(hdNam) );
}
else if ( TYPE(hdNam) == T_INT && 0 <= HD_TO_INT(hdNam) ) {
k = HD_TO_INT(hdNam);
p = value + sizeof(value);  *--p = '\0';
do { *--p = '0' + k % 10; } while ( (k /= 10) != 0 );
hdNam = FindRecname( p );
}
else {
return Error("<rec>.(<name>) <name> must be a string",0L,0L);
}
}
hdVal = EVAL( PTR(hdAss)[1] );
if ( hdVal == HdVoid ) {
return Error(
"Record Assignment: function must return a value",
0L, 0L );
}
ptRec = PTR(hdRec);
ptEnd = (TypHandle*)((char*)ptRec + SIZE(hdRec));
while ( ptRec < ptEnd && ptRec[0] != hdNam )  ptRec += 2;
if ( ptRec == ptEnd ) {
Resize( hdRec, SIZE(hdRec) + 2*SIZE_HD );
ptRec = PTR(hdRec) + SIZE(hdRec)/SIZE_HD - 2;
ptRec[0] = hdNam;
}
ptRec[1] = hdVal;
return hdVal;
}

TypHandle       SumRec ( hdL, hdR )
TypHandle           hdL, hdR;
{
TypHandle           hdOp;
TypHandle           * ptRec,  * ptEnd;
if ( TYPE(hdR) != T_REC )  goto l1;
ptRec = PTR(hdR);
ptEnd = (TypHandle*)((char*)ptRec + SIZE(hdR));
while ( ptRec < ptEnd && ptRec[0] != HdRnOp )  ptRec += 2;
if ( ptRec == ptEnd || TYPE(ptRec[1]) != T_REC )  goto l1;
hdOp = ptRec[1];
ptRec = PTR(hdOp);
ptEnd = (TypHandle*)((char*)ptRec + SIZE(hdOp));
while ( ptRec < ptEnd && ptRec[0] != HdRnSum )  ptRec += 2;
if ( ptRec == ptEnd )  goto l1;
PTR(HdCallSum)[0] = ptRec[1];
PTR(HdCallSum)[1] = hdL;
PTR(HdCallSum)[2] = hdR;
hdOp = EVAL( HdCallSum );
PTR(HdCallSum)[0] = HdStrSum;
PTR(HdCallSum)[1] = 0;
PTR(HdCallSum)[2] = 0;
return hdOp;
l1:
if ( TYPE(hdL) != T_REC )  goto l2;
ptRec = PTR(hdL);
ptEnd = (TypHandle*)((char*)ptRec + SIZE(hdL));
while ( ptRec < ptEnd && ptRec[0] != HdRnOp )  ptRec += 2;
if ( ptRec == ptEnd || TYPE(ptRec[1]) != T_REC )  goto l2;
hdOp = ptRec[1];
ptRec = PTR(hdOp);
ptEnd = (TypHandle*)((char*)ptRec + SIZE(hdOp));
while ( ptRec < ptEnd && ptRec[0] != HdRnSum )  ptRec += 2;
if ( ptRec == ptEnd )  goto l2;
PTR(HdCallSum)[0] = ptRec[1];
PTR(HdCallSum)[1] = hdL;
PTR(HdCallSum)[2] = hdR;
hdOp = EVAL( HdCallSum );
PTR(HdCallSum)[0] = HdStrSum;
PTR(HdCallSum)[1] = 0;
PTR(HdCallSum)[2] = 0;
return hdOp;
l2:
return Error("Record: one operand must have '~.operations.+'",0L,0L);
}

TypHandle       DiffRec ( hdL, hdR )
TypHandle           hdL, hdR;
{
TypHandle           hdOp;
TypHandle           * ptRec,  * ptEnd;
if ( TYPE(hdR) != T_REC )  goto l1;
ptRec = PTR(hdR);
ptEnd = (TypHandle*)((char*)ptRec + SIZE(hdR));
while ( ptRec < ptEnd && ptRec[0] != HdRnOp )  ptRec += 2;
if ( ptRec == ptEnd || TYPE(ptRec[1]) != T_REC )  goto l1;
hdOp = ptRec[1];
ptRec = PTR(hdOp);
ptEnd = (TypHandle*)((char*)ptRec + SIZE(hdOp));
while ( ptRec < ptEnd && ptRec[0] != HdRnDiff )  ptRec += 2;
if ( ptRec == ptEnd )  goto l1;
PTR(HdCallDiff)[0] = ptRec[1];
PTR(HdCallDiff)[1] = hdL;
PTR(HdCallDiff)[2] = hdR;
hdOp = EVAL( HdCallDiff );
PTR(HdCallDiff)[0] = HdStrDiff;
PTR(HdCallDiff)[1] = 0;
PTR(HdCallDiff)[2] = 0;
return hdOp;
l1:
if ( TYPE(hdL) != T_REC )  goto l2;
ptRec = PTR(hdL);
ptEnd = (TypHandle*)((char*)ptRec + SIZE(hdL));
while ( ptRec < ptEnd && ptRec[0] != HdRnOp )  ptRec += 2;
if ( ptRec == ptEnd || TYPE(ptRec[1]) != T_REC )  goto l2;
hdOp = ptRec[1];
ptRec = PTR(hdOp);
ptEnd = (TypHandle*)((char*)ptRec + SIZE(hdOp));
while ( ptRec < ptEnd && ptRec[0] != HdRnDiff )  ptRec += 2;
if ( ptRec == ptEnd )  goto l2;
PTR(HdCallDiff)[0] = ptRec[1];
PTR(HdCallDiff)[1] = hdL;
PTR(HdCallDiff)[2] = hdR;
hdOp = EVAL( HdCallDiff );
PTR(HdCallDiff)[0] = HdStrDiff;
PTR(HdCallDiff)[1] = 0;
PTR(HdCallDiff)[2] = 0;
return hdOp;
l2:
return Error("Record: one operand must have '~.operations.-'",0L,0L);
}

TypHandle       ProdRec ( hdL, hdR )
TypHandle           hdL, hdR;
{
TypHandle           hdOp;
TypHandle           * ptRec,  * ptEnd;
if ( TYPE(hdR) != T_REC )  goto l1;
ptRec = PTR(hdR);
ptEnd = (TypHandle*)((char*)ptRec + SIZE(hdR));
while ( ptRec < ptEnd && ptRec[0] != HdRnOp )  ptRec += 2;
if ( ptRec == ptEnd || TYPE(ptRec[1]) != T_REC )  goto l1;
hdOp = ptRec[1];
ptRec = PTR(hdOp);
ptEnd = (TypHandle*)((char*)ptRec + SIZE(hdOp));
while ( ptRec < ptEnd && ptRec[0] != HdRnProd )  ptRec += 2;
if ( ptRec == ptEnd )  goto l1;
PTR(HdCallProd)[0] = ptRec[1];
PTR(HdCallProd)[1] = hdL;
PTR(HdCallProd)[2] = hdR;
hdOp = EVAL( HdCallProd );
PTR(HdCallProd)[0] = HdStrProd;
PTR(HdCallProd)[1] = 0;
PTR(HdCallProd)[2] = 0;
return hdOp;
l1:
if ( TYPE(hdL) != T_REC )  goto l2;
ptRec = PTR(hdL);
ptEnd = (TypHandle*)((char*)ptRec + SIZE(hdL));
while ( ptRec < ptEnd && ptRec[0] != HdRnOp )  ptRec += 2;
if ( ptRec == ptEnd || TYPE(ptRec[1]) != T_REC )  goto l2;
hdOp = ptRec[1];
ptRec = PTR(hdOp);
ptEnd = (TypHandle*)((char*)ptRec + SIZE(hdOp));
while ( ptRec < ptEnd && ptRec[0] != HdRnProd )  ptRec += 2;
if ( ptRec == ptEnd )  goto l2;
PTR(HdCallProd)[0] = ptRec[1];
PTR(HdCallProd)[1] = hdL;
PTR(HdCallProd)[2] = hdR;
hdOp = EVAL( HdCallProd );
PTR(HdCallProd)[0] = HdStrProd;
PTR(HdCallProd)[1] = 0;
PTR(HdCallProd)[2] = 0;
return hdOp;
l2:
return Error("Record: one operand must have '~.operations.*'",0L,0L);
}

TypHandle       QuoRec ( hdL, hdR )
TypHandle           hdL, hdR;
{
TypHandle           hdOp;
TypHandle           * ptRec,  * ptEnd;
if ( TYPE(hdR) != T_REC )  goto l1;
ptRec = PTR(hdR);
ptEnd = (TypHandle*)((char*)ptRec + SIZE(hdR));
while ( ptRec < ptEnd && ptRec[0] != HdRnOp )  ptRec += 2;
if ( ptRec == ptEnd || TYPE(ptRec[1]) != T_REC )  goto l1;
hdOp = ptRec[1];
ptRec = PTR(hdOp);
ptEnd = (TypHandle*)((char*)ptRec + SIZE(hdOp));
while ( ptRec < ptEnd && ptRec[0] != HdRnQuo )  ptRec += 2;
if ( ptRec == ptEnd )  goto l1;
PTR(HdCallQuo)[0] = ptRec[1];
PTR(HdCallQuo)[1] = hdL;
PTR(HdCallQuo)[2] = hdR;
hdOp = EVAL( HdCallQuo );
PTR(HdCallQuo)[0] = HdStrQuo;
PTR(HdCallQuo)[1] = 0;
PTR(HdCallQuo)[2] = 0;
return hdOp;
l1:
if ( TYPE(hdL) != T_REC )  goto l2;
ptRec = PTR(hdL);
ptEnd = (TypHandle*)((char*)ptRec + SIZE(hdL));
while ( ptRec < ptEnd && ptRec[0] != HdRnOp )  ptRec += 2;
if ( ptRec == ptEnd || TYPE(ptRec[1]) != T_REC )  goto l2;
hdOp = ptRec[1];
ptRec = PTR(hdOp);
ptEnd = (TypHandle*)((char*)ptRec + SIZE(hdOp));
while ( ptRec < ptEnd && ptRec[0] != HdRnQuo )  ptRec += 2;
if ( ptRec == ptEnd )  goto l2;
PTR(HdCallQuo)[0] = ptRec[1];
PTR(HdCallQuo)[1] = hdL;
PTR(HdCallQuo)[2] = hdR;
hdOp = EVAL( HdCallQuo );
PTR(HdCallQuo)[0] = HdStrQuo;
PTR(HdCallQuo)[1] = 0;
PTR(HdCallQuo)[2] = 0;
return hdOp;
l2:
return Error("Record: one operand must have '~.operations./'",0L,0L);
}

TypHandle       ModRec ( hdL, hdR )
TypHandle           hdL, hdR;
{
TypHandle           hdOp;
TypHandle           * ptRec,  * ptEnd;
if ( TYPE(hdR) != T_REC )  goto l1;
ptRec = PTR(hdR);
ptEnd = (TypHandle*)((char*)ptRec + SIZE(hdR));
while ( ptRec < ptEnd && ptRec[0] != HdRnOp )  ptRec += 2;
if ( ptRec == ptEnd || TYPE(ptRec[1]) != T_REC )  goto l1;
hdOp = ptRec[1];
ptRec = PTR(hdOp);
ptEnd = (TypHandle*)((char*)ptRec + SIZE(hdOp));
while ( ptRec < ptEnd && ptRec[0] != HdRnMod )  ptRec += 2;
if ( ptRec == ptEnd )  goto l1;
PTR(HdCallMod)[0] = ptRec[1];
PTR(HdCallMod)[1] = hdL;
PTR(HdCallMod)[2] = hdR;
hdOp = EVAL( HdCallMod );
PTR(HdCallMod)[0] = HdStrMod;
PTR(HdCallMod)[1] = 0;
PTR(HdCallMod)[2] = 0;
return hdOp;
l1:
if ( TYPE(hdL) != T_REC )  goto l2;
ptRec = PTR(hdL);
ptEnd = (TypHandle*)((char*)ptRec + SIZE(hdL));
while ( ptRec < ptEnd && ptRec[0] != HdRnOp )  ptRec += 2;
if ( ptRec == ptEnd || TYPE(ptRec[1]) != T_REC )  goto l2;
hdOp = ptRec[1];
ptRec = PTR(hdOp);
ptEnd = (TypHandle*)((char*)ptRec + SIZE(hdOp));
while ( ptRec < ptEnd && ptRec[0] != HdRnMod )  ptRec += 2;
if ( ptRec == ptEnd )  goto l2;
PTR(HdCallMod)[0] = ptRec[1];
PTR(HdCallMod)[1] = hdL;
PTR(HdCallMod)[2] = hdR;
hdOp = EVAL( HdCallMod );
PTR(HdCallMod)[0] = HdStrMod;
PTR(HdCallMod)[1] = 0;
PTR(HdCallMod)[2] = 0;
return hdOp;
l2:
return Error("Record: one operand must have '~.operations.mod'",0L,0L);
}

TypHandle       PowRec ( hdL, hdR )
TypHandle           hdL, hdR;
{
TypHandle           hdOp;
TypHandle           * ptRec,  * ptEnd;
if ( TYPE(hdR) != T_REC )  goto l1;
ptRec = PTR(hdR);
ptEnd = (TypHandle*)((char*)ptRec + SIZE(hdR));
while ( ptRec < ptEnd && ptRec[0] != HdRnOp )  ptRec += 2;
if ( ptRec == ptEnd || TYPE(ptRec[1]) != T_REC )  goto l1;
hdOp = ptRec[1];
ptRec = PTR(hdOp);
ptEnd = (TypHandle*)((char*)ptRec + SIZE(hdOp));
while ( ptRec < ptEnd && ptRec[0] != HdRnPow )  ptRec += 2;
if ( ptRec == ptEnd )  goto l1;
PTR(HdCallPow)[0] = ptRec[1];
PTR(HdCallPow)[1] = hdL;
PTR(HdCallPow)[2] = hdR;
hdOp = EVAL( HdCallPow );
PTR(HdCallPow)[0] = HdStrPow;
PTR(HdCallPow)[1] = 0;
PTR(HdCallPow)[2] = 0;
return hdOp;
l1:
if ( TYPE(hdL) != T_REC )  goto l2;
ptRec = PTR(hdL);
ptEnd = (TypHandle*)((char*)ptRec + SIZE(hdL));
while ( ptRec < ptEnd && ptRec[0] != HdRnOp )  ptRec += 2;
if ( ptRec == ptEnd || TYPE(ptRec[1]) != T_REC )  goto l2;
hdOp = ptRec[1];
ptRec = PTR(hdOp);
ptEnd = (TypHandle*)((char*)ptRec + SIZE(hdOp));
while ( ptRec < ptEnd && ptRec[0] != HdRnPow )  ptRec += 2;
if ( ptRec == ptEnd )  goto l2;
PTR(HdCallPow)[0] = ptRec[1];
PTR(HdCallPow)[1] = hdL;
PTR(HdCallPow)[2] = hdR;
hdOp = EVAL( HdCallPow );
PTR(HdCallPow)[0] = HdStrPow;
PTR(HdCallPow)[1] = 0;
PTR(HdCallPow)[2] = 0;
return hdOp;
l2:
return Error("Record: one operand must have '~.operations.^'",0L,0L);
}

TypHandle       CommRec ( hdL, hdR )
TypHandle           hdL, hdR;
{
TypHandle           hdOp;
TypHandle           * ptRec,  * ptEnd;
if ( TYPE(hdR) != T_REC )  goto l1;
ptRec = PTR(hdR);
ptEnd = (TypHandle*)((char*)ptRec + SIZE(hdR));
while ( ptRec < ptEnd && ptRec[0] != HdRnOp )  ptRec += 2;
if ( ptRec == ptEnd || TYPE(ptRec[1]) != T_REC )  goto l1;
hdOp = ptRec[1];
ptRec = PTR(hdOp);
ptEnd = (TypHandle*)((char*)ptRec + SIZE(hdOp));
while ( ptRec < ptEnd && ptRec[0] != HdRnComm )  ptRec += 2;
if ( ptRec == ptEnd )  goto l1;
PTR(HdCallComm)[0] = ptRec[1];
PTR(HdCallComm)[1] = hdL;
PTR(HdCallComm)[2] = hdR;
hdOp = EVAL( HdCallComm );
PTR(HdCallComm)[0] = HdStrComm;
PTR(HdCallComm)[1] = 0;
PTR(HdCallComm)[2] = 0;
return hdOp;
l1:
if ( TYPE(hdL) != T_REC )  goto l2;
ptRec = PTR(hdL);
ptEnd = (TypHandle*)((char*)ptRec + SIZE(hdL));
while ( ptRec < ptEnd && ptRec[0] != HdRnOp )  ptRec += 2;
if ( ptRec == ptEnd || TYPE(ptRec[1]) != T_REC )  goto l2;
hdOp = ptRec[1];
ptRec = PTR(hdOp);
ptEnd = (TypHandle*)((char*)ptRec + SIZE(hdOp));
while ( ptRec < ptEnd && ptRec[0] != HdRnComm )  ptRec += 2;
if ( ptRec == ptEnd )  goto l2;
PTR(HdCallComm)[0] = ptRec[1];
PTR(HdCallComm)[1] = hdL;
PTR(HdCallComm)[2] = hdR;
hdOp = EVAL( HdCallComm );
PTR(HdCallComm)[0] = HdStrComm;
PTR(HdCallComm)[1] = 0;
PTR(HdCallComm)[2] = 0;
return hdOp;
l2:
return Error("Record: one operand must have '~.operations.comm'",0L,0L);
}

TypHandle       EqRec ( hdL, hdR )
TypHandle           hdL, hdR;
{
TypHandle           hdOp;
TypHandle           * ptRec,  * ptEnd;
unsigned long       i, k;
if ( TYPE(hdR) != T_REC )  goto l1;
ptRec = PTR(hdR);
ptEnd = (TypHandle*)((char*)ptRec + SIZE(hdR));
while ( ptRec < ptEnd && ptRec[0] != HdRnOp )  ptRec += 2;
if ( ptRec == ptEnd || TYPE(ptRec[1]) != T_REC )  goto l1;
hdOp = ptRec[1];
ptRec = PTR(hdOp);
ptEnd = (TypHandle*)((char*)ptRec + SIZE(hdOp));
while ( ptRec < ptEnd && ptRec[0] != HdRnEq )  ptRec += 2;
if ( ptRec == ptEnd )  goto l1;
PTR(HdCallEq)[0] = ptRec[1];
PTR(HdCallEq)[1] = hdL;
PTR(HdCallEq)[2] = hdR;
hdOp = EVAL( HdCallEq );
PTR(HdCallEq)[0] = HdStrEq;
PTR(HdCallEq)[1] = 0;
PTR(HdCallEq)[2] = 0;
return hdOp;
l1:
if ( TYPE(hdL) != T_REC )  goto l2;
ptRec = PTR(hdL);
ptEnd = (TypHandle*)((char*)ptRec + SIZE(hdL));
while ( ptRec < ptEnd && ptRec[0] != HdRnOp )  ptRec += 2;
if ( ptRec == ptEnd || TYPE(ptRec[1]) != T_REC )  goto l2;
hdOp = ptRec[1];
ptRec = PTR(hdOp);
ptEnd = (TypHandle*)((char*)ptRec + SIZE(hdOp));
while ( ptRec < ptEnd && ptRec[0] != HdRnEq )  ptRec += 2;
if ( ptRec == ptEnd )  goto l2;
PTR(HdCallEq)[0] = ptRec[1];
PTR(HdCallEq)[1] = hdL;
PTR(HdCallEq)[2] = hdR;
hdOp = EVAL( HdCallEq );
PTR(HdCallEq)[0] = HdStrEq;
PTR(HdCallEq)[1] = 0;
PTR(HdCallEq)[2] = 0;
return hdOp;
l2:
if ( TYPE(hdL) != T_REC || TYPE(hdR) != T_REC || SIZE(hdL) != SIZE(hdR) )
return HdFalse;
for ( i = 0; i < SIZE(hdL)/(2*SIZE_HD); ++i ) {
for ( k = 0; k < SIZE(hdR)/(2*SIZE_HD); ++k ) {
if ( PTR(hdL)[2*i] == PTR(hdR)[2*k] ) {
if ( PTR(hdL)[2*i+1] != PTR(hdR)[2*k+1]
&& EQ( PTR(hdL)[2*i+1], PTR(hdR)[2*k+1] ) != HdTrue )
return HdFalse;
break;
}
}
if ( k == SIZE(hdR)/(2*SIZE_HD) )
return HdFalse;
}
return HdTrue;
}

TypHandle       LtRec ( hdL, hdR )
TypHandle           hdL, hdR;
{
TypHandle           hdOp;
TypHandle           * ptRec;
TypHandle           * ptEnd;
TypHandle           hdNam;
TypHandle           hdVal;
unsigned long       h;
unsigned long       i, k;
if ( TYPE(hdR) != T_REC )  goto l1;
ptRec = PTR(hdR);
ptEnd = (TypHandle*)((char*)ptRec + SIZE(hdR));
while ( ptRec < ptEnd && ptRec[0] != HdRnOp )  ptRec += 2;
if ( ptRec == ptEnd || TYPE(ptRec[1]) != T_REC )  goto l1;
hdOp = ptRec[1];
ptRec = PTR(hdOp);
ptEnd = (TypHandle*)((char*)ptRec + SIZE(hdOp));
while ( ptRec < ptEnd && ptRec[0] != HdRnLt )  ptRec += 2;
if ( ptRec == ptEnd )  goto l1;
PTR(HdCallLt)[0] = ptRec[1];
PTR(HdCallLt)[1] = hdL;
PTR(HdCallLt)[2] = hdR;
hdOp = EVAL( HdCallLt );
PTR(HdCallLt)[0] = HdStrLt;
PTR(HdCallLt)[1] = 0;
PTR(HdCallLt)[2] = 0;
return hdOp;
l1:
if ( TYPE(hdL) != T_REC )  goto l2;
ptRec = PTR(hdL);
ptEnd = (TypHandle*)((char*)ptRec + SIZE(hdL));
while ( ptRec < ptEnd && ptRec[0] != HdRnOp )  ptRec += 2;
if ( ptRec == ptEnd || TYPE(ptRec[1]) != T_REC )  goto l2;
hdOp = ptRec[1];
ptRec = PTR(hdOp);
ptEnd = (TypHandle*)((char*)ptRec + SIZE(hdOp));
while ( ptRec < ptEnd && ptRec[0] != HdRnLt )  ptRec += 2;
if ( ptRec == ptEnd )  goto l2;
PTR(HdCallLt)[0] = ptRec[1];
PTR(HdCallLt)[1] = hdL;
PTR(HdCallLt)[2] = hdR;
hdOp = EVAL( HdCallLt );
PTR(HdCallLt)[0] = HdStrLt;
PTR(HdCallLt)[1] = 0;
PTR(HdCallLt)[2] = 0;
return hdOp;
l2:
if ( TYPE(hdL) < TYPE(hdR) )
return HdTrue;
else if ( TYPE(hdR) < TYPE(hdL) )
return HdFalse;
h = 1;  while ( 9*h + 4 < SIZE(hdL)/(2*SIZE_HD) )  h = 3*h + 1;
while ( 0 < h ) {
for ( i = h+1; i <= SIZE(hdL)/(2*SIZE_HD); i++ ) {
hdNam = PTR(hdL)[2*i-2];
hdVal = PTR(hdL)[2*i-1];
k = i;
while ( h < k
&& SyStrcmp( (char*)PTR(hdNam),
(char*)PTR( PTR(hdL)[2*(k-h)-2] ) ) < 0 ) {
PTR(hdL)[2*k-2] = PTR(hdL)[2*(k-h)-2];
PTR(hdL)[2*k-1] = PTR(hdL)[2*(k-h)-1];
k -= h;
}
PTR(hdL)[2*k-2] = hdNam;
PTR(hdL)[2*k-1] = hdVal;
}
h = h / 3;
}
h = 1;  while ( 9*h + 4 < SIZE(hdR)/(2*SIZE_HD) )  h = 3*h + 1;
while ( 0 < h ) {
for ( i = h+1; i <= SIZE(hdR)/(2*SIZE_HD); i++ ) {
hdNam = PTR(hdR)[2*i-2];
hdVal = PTR(hdR)[2*i-1];
k = i;
while ( h < k
&& SyStrcmp( (char*)PTR(hdNam),
(char*)PTR( PTR(hdR)[2*(k-h)-2] ) ) < 0 ) {
PTR(hdR)[2*k-2] = PTR(hdR)[2*(k-h)-2];
PTR(hdR)[2*k-1] = PTR(hdR)[2*(k-h)-1];
k -= h;
}
PTR(hdR)[2*k-2] = hdNam;
PTR(hdR)[2*k-1] = hdVal;
}
h = h / 3;
}
for ( i = 1; i <= SIZE(hdR)/(2*SIZE_HD); i++ ) {
if ( i > SIZE(hdL)/(2*SIZE_HD) ) {
return HdTrue;
}
else if ( PTR(hdL)[2*i-2] != PTR(hdR)[2*i-2] ) {
if ( SyStrcmp( (char*)PTR( PTR(hdR)[2*i-2] ),
(char*)PTR( PTR(hdL)[2*i-2] ) ) < 0 ) {
return HdTrue;
}
else {
return HdFalse;
}
}
else if ( EQ( PTR(hdL)[2*i-1], PTR(hdR)[2*i-1] ) == HdFalse ) {
return LT( PTR(hdL)[2*i-1], PTR(hdR)[2*i-1] );
}
}
return HdFalse;
}

TypHandle       InRec ( hdL, hdR )
TypHandle           hdL, hdR;
{
TypHandle           hdOp;
TypHandle           * ptRec,  * ptEnd;
if ( TYPE(hdR) != T_REC )  goto l1;
ptRec = PTR(hdR);
ptEnd = (TypHandle*)((char*)ptRec + SIZE(hdR));
while ( ptRec < ptEnd && ptRec[0] != HdRnOp )  ptRec += 2;
if ( ptRec == ptEnd || TYPE(ptRec[1]) != T_REC )  goto l1;
hdOp = ptRec[1];
ptRec = PTR(hdOp);
ptEnd = (TypHandle*)((char*)ptRec + SIZE(hdOp));
while ( ptRec < ptEnd && ptRec[0] != HdRnIn )  ptRec += 2;
if ( ptRec == ptEnd )  goto l1;
PTR(HdCallIn)[0] = ptRec[1];
PTR(HdCallIn)[1] = hdL;
PTR(HdCallIn)[2] = hdR;
hdOp = EVAL( HdCallIn );
PTR(HdCallIn)[0] = HdStrIn;
PTR(HdCallIn)[1] = 0;
PTR(HdCallIn)[2] = 0;
return hdOp;
l1:
return Error("Record: right operand must have '~.operations.in'",0L,0L);
}

void            PrRec ( hdRec )
TypHandle           hdRec;
{
TypHandle           hdOp;
TypHandle           * ptRec,  * ptEnd;
unsigned long       i;
TypHandle           ignore;
char                * name;
if ( TYPE(hdRec) != T_REC )  goto l1;
ptRec = PTR(hdRec);
ptEnd = (TypHandle*)((char*)ptRec + SIZE(hdRec));
while ( ptRec < ptEnd && ptRec[0] != HdRnOp )  ptRec += 2;
if ( ptRec == ptEnd || TYPE(ptRec[1]) != T_REC )  goto l1;
hdOp = ptRec[1];
ptRec = PTR(hdOp);
ptEnd = (TypHandle*)((char*)ptRec + SIZE(hdOp));
while ( ptRec < ptEnd && ptRec[0] != HdRnPrint )  ptRec += 2;
if ( ptRec == ptEnd )  goto l1;
PTR(HdCallPrint)[0] = ptRec[1];
PTR(HdCallPrint)[1] = hdRec;
ignore = EVAL( HdCallPrint );
PTR(HdCallPrint)[0] = HdStrPrint;
PTR(HdCallPrint)[1] = 0;
return;
l1:
Pr("%2>rec(\n%2>",0L,0L);
for ( i = 0; i < SIZE(hdRec)/(2*SIZE_HD); ++i ) {
if ( TYPE( PTR(hdRec)[2*i] ) == T_RECNAM ) {
name = (char*)PTR(PTR(hdRec)[2*i]);
if ( !SyStrcmp(name,"and")      || !SyStrcmp(name,"do")
|| !SyStrcmp(name,"elif")     || !SyStrcmp(name,"else")
|| !SyStrcmp(name,"end")      || !SyStrcmp(name,"fi")
|| !SyStrcmp(name,"for")      || !SyStrcmp(name,"function")
|| !SyStrcmp(name,"if")       || !SyStrcmp(name,"in")
|| !SyStrcmp(name,"local")    || !SyStrcmp(name,"mod")
|| !SyStrcmp(name,"not")      || !SyStrcmp(name,"od")
|| !SyStrcmp(name,"or")       || !SyStrcmp(name,"repeat")
|| !SyStrcmp(name,"return")   || !SyStrcmp(name,"then")
|| !SyStrcmp(name,"until")    || !SyStrcmp(name,"while")
|| !SyStrcmp(name,"quit") ) {
Pr("\\",0L,0L);
}
for ( name = (char*)PTR(PTR(hdRec)[2*i]); *name!='\0'; name++ ) {
if ( IsAlpha(*name) || IsDigit(*name) || *name == '_' )
Pr("%c",(long)(*name),0L);
else
Pr("\\%c",(long)(*name),0L);
}
}
else {
Pr(" (",0L,0L);
Print( PTR(hdRec)[2*i] );
Pr(")",0L,0L);
}
Pr("%< := %>",0L,0L);
Print( PTR(hdRec)[2*i+1] );
if ( i < SIZE(hdRec)/(2*SIZE_HD)-1 )
Pr("%2<,\n%2>",0L,0L);
}
Pr(" %4<)",0L,0L);
}
void            PrRecElm ( hdElm )
TypHandle           hdElm;
{
char *              name;
Pr( "%>", 0L, 0L );
Print( PTR(hdElm)[0] );
if ( TYPE( PTR(hdElm)[1] ) == T_RECNAM ) {
Pr("%<.%>",0L,0L);
name = (char*)PTR(PTR(hdElm)[1]);
if ( !SyStrcmp(name,"and")      || !SyStrcmp(name,"do")
|| !SyStrcmp(name,"elif")     || !SyStrcmp(name,"else")
|| !SyStrcmp(name,"end")      || !SyStrcmp(name,"fi")
|| !SyStrcmp(name,"for")      || !SyStrcmp(name,"function")
|| !SyStrcmp(name,"if")       || !SyStrcmp(name,"in")
|| !SyStrcmp(name,"local")    || !SyStrcmp(name,"mod")
|| !SyStrcmp(name,"not")      || !SyStrcmp(name,"od")
|| !SyStrcmp(name,"or")       || !SyStrcmp(name,"repeat")
|| !SyStrcmp(name,"return")   || !SyStrcmp(name,"then")
|| !SyStrcmp(name,"until")    || !SyStrcmp(name,"while")
|| !SyStrcmp(name,"quit") ) {
Pr("\\",0L,0L);
}
for ( name = (char*)PTR(PTR(hdElm)[1]); *name != '\0'; name++ ) {
if ( IsAlpha(*name) || IsDigit(*name) || *name == '_' )
Pr("%c",(long)(*name),0L);
else
Pr("\\%c",(long)(*name),0L);
}
Pr("%<",0L,0L);
}
else {
Pr( "%<.%>(", 0L, 0L );
Print( PTR(hdElm)[1] );
Pr( ")%<", 0L, 0L );
}
}
void            PrRecAss ( hdAss )
TypHandle           hdAss;
{
Pr( "%2>", 0L, 0L );
Print( PTR(hdAss)[0] );
Pr( "%< %>:= ", 0L, 0L );
Print( PTR(hdAss)[1] );
Pr( "%2<", 0L, 0L );
}
TypHandle       FunIsRec ( hdCall )
TypHandle           hdCall;
{
TypHandle           hdObj;
if ( SIZE(hdCall) != 2 * SIZE_HD )
return Error("usage: IsRec( <obj> )",0L,0L);
hdObj = EVAL( PTR(hdCall)[1] );
if ( hdObj == HdVoid )
return Error("IsRec: function must return a value",0L,0L);
if ( TYPE(hdObj) == T_REC )
return HdTrue;
else
return HdFalse;
}
TypHandle       FunRecFields ( hdCall )
TypHandle           hdCall;
{
TypHandle           hdRec,  hdNam;
TypHandle           hdStr;
long                i;
if ( SIZE(hdCall) != 2*SIZE_HD )
return Error("usage: RecFields( <rec> )",0L,0L);
hdRec = EVAL( PTR(hdCall)[1] );
if ( TYPE(hdRec) != T_REC )
return Error("RecFields: <rec> must be a record",0L,0L);
hdNam = NewBag( T_LIST, SIZE_PLEN_PLIST( SIZE(hdRec) / SIZE_HD / 2 ) );
SET_LEN_PLIST( hdNam, SIZE(hdRec) / SIZE_HD / 2 );
for ( i = 1; i <= LEN_PLIST( hdNam ); i++ ) {
hdStr = NewBag( T_STRING, SIZE( PTR(hdRec)[2*i-2] ) );
SyStrncat( (char*)PTR(hdStr),
(char*)PTR( PTR(hdRec)[2*i-2] ),
SIZE( PTR(hdRec)[2*i-2] ) );
SET_ELM_PLIST( hdNam, i, hdStr );
}
return hdNam;
}
void            InitRec ()
{
long                i;
InstEvFunc( T_REC,     EvRec     );
InstEvFunc( T_MAKEREC, EvMakeRec );
InstEvFunc( T_RECELM,  EvRecElm  );
InstEvFunc( T_RECASS,  EvRecAss  );
InstPrFunc( T_REC,     PrRec     );
InstPrFunc( T_MAKEREC, PrRec     );
InstPrFunc( T_RECELM,  PrRecElm  );
InstPrFunc( T_RECASS,  PrRecAss  );
HdTilde = FindIdent( "~" );
HdRnOp     = FindRecname( "operations" );
HdRnSum     = FindRecname( "+"     );
HdCallSum   = NewBag( T_FUNCCALL, 3 * SIZE_HD );
HdStrSum    = FindIdent( "<rec1> + <rec2>" );
PTR(HdCallSum)[0] = HdStrSum;
HdRnDiff    = FindRecname( "-"     );
HdCallDiff  = NewBag( T_FUNCCALL, 3 * SIZE_HD );
HdStrDiff   = FindIdent( "<rec1> - <rec2>" );
PTR(HdCallDiff)[0] = HdStrDiff;
HdRnProd    = FindRecname( "*"     );
HdCallProd  = NewBag( T_FUNCCALL, 3 * SIZE_HD );
HdStrProd   = FindIdent( "<rec1> * <rec2>" );
PTR(HdCallProd)[0] = HdStrProd;
HdRnQuo     = FindRecname( "/"     );
HdCallQuo   = NewBag( T_FUNCCALL, 3 * SIZE_HD );
HdStrQuo    = FindIdent( "<rec1> / <rec2>" );
PTR(HdCallQuo)[0] = HdStrQuo;
HdRnMod     = FindRecname( "mod"   );
HdCallMod   = NewBag( T_FUNCCALL, 3 * SIZE_HD );
HdStrMod    = FindIdent( "<rec1> mod <rec2>" );
PTR(HdCallMod)[0] = HdStrMod;
HdRnPow     = FindRecname( "^"     );
HdCallPow   = NewBag( T_FUNCCALL, 3 * SIZE_HD );
HdStrPow    = FindIdent( "<rec1> ^ <rec2>" );
PTR(HdCallPow)[0] = HdStrPow;
HdRnComm    = FindRecname( "Comm"  );
HdCallComm  = NewBag( T_FUNCCALL, 3 * SIZE_HD );
HdStrComm   = FindIdent( "Comm( <rec1>, <rec2> )" );
PTR(HdCallComm)[0] = HdStrComm;
HdRnEq      = FindRecname( "="     );
HdCallEq    = NewBag( T_FUNCCALL, 3 * SIZE_HD );
HdStrEq     = FindIdent( "<rec1> = <rec2>" );
PTR(HdCallEq)[0] = HdStrEq;
HdRnLt      = FindRecname( "<"     );
HdCallLt    = NewBag( T_FUNCCALL, 3 * SIZE_HD );
HdStrLt     = FindIdent( "<rec1> < <rec2>" );
PTR(HdCallLt)[0] = HdStrLt;
HdRnIn      = FindRecname( "in"    );
HdCallIn    = NewBag( T_FUNCCALL, 3 * SIZE_HD );
HdStrIn     = FindIdent( "<obj> in <rec>" );
PTR(HdCallIn)[0] = HdStrIn;
HdRnPrint   = FindRecname( "Print" );
HdCallPrint = NewBag( T_FUNCCALL, 2 * SIZE_HD );
HdStrPrint  = FindIdent( "Print( <rec> )" );
PTR(HdCallPrint)[0] = HdStrPrint;
for ( i = T_VOID; i < T_VAR; ++i ) {
TabSum[  i ][ T_REC ] = SumRec;
TabSum[  T_REC ][ i ] = SumRec;
TabDiff[ i ][ T_REC ] = DiffRec;
TabDiff[ T_REC ][ i ] = DiffRec;
TabProd[ i ][ T_REC ] = ProdRec;
TabProd[ T_REC ][ i ] = ProdRec;
TabQuo[  i ][ T_REC ] = QuoRec;
TabQuo[  T_REC ][ i ] = QuoRec;
TabMod[  i ][ T_REC ] = ModRec;
TabMod[  T_REC ][ i ] = ModRec;
TabPow[  i ][ T_REC ] = PowRec;
TabPow[  T_REC ][ i ] = PowRec;
TabEq[   i ][ T_REC ] = EqRec;
TabEq[   T_REC ][ i ] = EqRec;
TabLt[   i ][ T_REC ] = LtRec;
TabLt[   T_REC ][ i ] = LtRec;
TabComm[ i ][ T_REC ] = CommRec;
TabComm[ T_REC ][ i ] = CommRec;
}
InstIntFunc( "IsRec",       FunIsRec       );
InstIntFunc( "RecFields",   FunRecFields   );
}
/* 当前文件是D:\Read\scanner.c*/


char            GetLine ()
{
if ( Input->file == 0 ) {
if ( ! SyQuiet ) Pr( "%s%c", (long)Prompt, (long)'\03' );
else             Pr( "%c", (long)'\03', 0L );
}
else if ( Input->file == 2 ) {
Pr( "%s%c", (long)Prompt, (long)'\03' );
}
if ( Input->line < In && (*(In-1) == '\n' || *(In-1) == '\r') )
Input->number++;
In = Input->line;  In[0] = '\0';
NrErrLine = 0;
if ( Input->file == TestInput && TestLine[0] != '\0' ) {
SyStrncat( In, TestLine, sizeof(Input->line) );
TestLine[0] = '\0';
}
else if ( ! SyFgets( In, sizeof(Input->line), Input->file ) ) {
In[0] = '\377';  In[1] = '\0';
return *In;
}
if ( In[0] == '?' ) {
In[SyStrlen(In)-1] = '\0';
SyHelp( In+1, Input->file );
In[0] = '\n';
In[1] = '\0';
}
if ( Logfile != -1 && (Input->file == 0 || Input->file == 2) )
SyFputs( In, Logfile );
if ( InputLogfile != -1 && (Input->file == 0 || Input->file == 2) )
SyFputs( In, InputLogfile );
if ( Input->file == TestInput && In[0] == '#' && In[1] == '>' ) {
SyFputs( In, TestOutput );
return GetLine();
}
return *In;
}
#define GET_CHAR()      (*++In != '\0' ? *In : GetLine())
void            GetSymbol P(( void ));
void            GetIdent ()
{
long                i;
long                isQuoted;
isQuoted = 0;
for ( i=0; IsAlpha(*In) || IsDigit(*In) || *In=='_' || *In=='\\'; i++ ) {
if ( *In == '\\' ) {
GET_CHAR();
	    if      ( *In == '\n' && i == 0 )  { GetSymbol();  return; }
else if ( *In == '\n' && i < sizeof(Value)-1 )  i--;
else if ( *In == 'n'  && i < sizeof(Value)-1 )  Value[i] = '\n';
else if ( *In == 't'  && i < sizeof(Value)-1 )  Value[i] = '\t';
else if ( *In == 'r'  && i < sizeof(Value)-1 )  Value[i] = '\r';
else if ( *In == 'b'  && i < sizeof(Value)-1 )  Value[i] = '\b';
else if (                i < sizeof(Value)-1 )  Value[i] = *In;
isQuoted = 1;
}
else {
if ( i < sizeof(Value)-1 )  Value[i] = *In;
}
GET_CHAR();
}
if ( i < sizeof(Value)-1 )  Value[i] = '\0';
Symbol = S_IDENT;
switch ( 256*Value[0]+Value[i-1] ) {
case 256*'a'+'d': if(!SyStrcmp(Value,"and"))     Symbol=S_AND;     break;
case 256*'d'+'o': if(!SyStrcmp(Value,"do"))      Symbol=S_DO;      break;
case 256*'e'+'f': if(!SyStrcmp(Value,"elif"))    Symbol=S_ELIF;    break;
case 256*'e'+'e': if(!SyStrcmp(Value,"else"))    Symbol=S_ELSE;    break;
case 256*'e'+'d': if(!SyStrcmp(Value,"end"))     Symbol=S_END;     break;
case 256*'f'+'i': if(!SyStrcmp(Value,"fi"))      Symbol=S_FI;      break;
case 256*'f'+'r': if(!SyStrcmp(Value,"for"))     Symbol=S_FOR;     break;
case 256*'f'+'n': if(!SyStrcmp(Value,"function"))Symbol=S_FUNCTION;break;
case 256*'i'+'f': if(!SyStrcmp(Value,"if"))      Symbol=S_IF;      break;
case 256*'i'+'n': if(!SyStrcmp(Value,"in"))      Symbol=S_IN;      break;
case 256*'l'+'l': if(!SyStrcmp(Value,"local"))   Symbol=S_LOCAL;   break;
case 256*'m'+'d': if(!SyStrcmp(Value,"mod"))     Symbol=S_MOD;     break;
case 256*'n'+'t': if(!SyStrcmp(Value,"not"))     Symbol=S_NOT;     break;
case 256*'o'+'d': if(!SyStrcmp(Value,"od"))      Symbol=S_OD;      break;
case 256*'o'+'r': if(!SyStrcmp(Value,"or"))      Symbol=S_OR;      break;
case 256*'r'+'t': if(!SyStrcmp(Value,"repeat"))  Symbol=S_REPEAT;  break;
case 256*'r'+'n': if(!SyStrcmp(Value,"return"))  Symbol=S_RETURN;  break;
case 256*'t'+'n': if(!SyStrcmp(Value,"then"))    Symbol=S_THEN;    break;
case 256*'u'+'l': if(!SyStrcmp(Value,"until"))   Symbol=S_UNTIL;   break;
case 256*'w'+'e': if(!SyStrcmp(Value,"while"))   Symbol=S_WHILE;   break;
case 256*'q'+'t': if(!SyStrcmp(Value,"quit"))    Symbol=S_QUIT;    break;
}
if ( isQuoted )  Symbol = S_IDENT;
}
void            GetInt ()
{
long                i;
long                isInt;
isInt = 1;
for ( i=0; IsDigit(*In) || IsAlpha(*In) || *In=='_' || *In=='\\'; i++ ) {
if ( *In == '\\' ) {
GET_CHAR();
if      ( *In == '\n' && i < sizeof(Value)-1 )  i--;
else if ( *In == 'n'  && i < sizeof(Value)-1 )  Value[i] = '\n';
else if ( *In == 't'  && i < sizeof(Value)-1 )  Value[i] = '\t';
else if ( *In == 'r'  && i < sizeof(Value)-1 )  Value[i] = '\r';
else if ( *In == 'b'  && i < sizeof(Value)-1 )  Value[i] = '\b';
else if ( *In == 'c'  && i < sizeof(Value)-1 )  Value[i] = '\03';
else if (                i < sizeof(Value)-1 )  Value[i] = *In;
}
else {
if ( i < sizeof(Value)-1 )  Value[i] = *In;
}
if ( ! IsDigit(*In) && *In != '\n' )  isInt = 0;
GET_CHAR();
}
if ( sizeof(Value)-1 <= i )
SyntaxError("integer must have less than 1024 digits");
if ( i < sizeof(Value)-1 )  Value[i] = '\0';
if ( isInt )  Symbol = S_INT;
else          Symbol = S_IDENT;
}
void            GetStr ()
{
long                i = 0;
GET_CHAR();
for ( i = 0; *In != '"' && *In != '\n' && *In != '\377'; i++ ) {
if ( *In == '\\' ) {
GET_CHAR();
if      ( *In == '\n' && i < sizeof(Value)-1 )  i--;
else if ( *In == 'n'  && i < sizeof(Value)-1 )  Value[i] = '\n';
else if ( *In == 't'  && i < sizeof(Value)-1 )  Value[i] = '\t';
else if ( *In == 'r'  && i < sizeof(Value)-1 )  Value[i] = '\r';
else if ( *In == 'b'  && i < sizeof(Value)-1 )  Value[i] = '\b';
else if ( *In == 'c'  && i < sizeof(Value)-1 )  Value[i] = '\03';
else if (                i < sizeof(Value)-1 )  Value[i] = *In;
}
else {
if ( i < sizeof(Value)-1 )  Value[i] = *In;
}
GET_CHAR();
}
if ( *In == '\n'  )
SyntaxError("string must not include <newline>");
if ( *In == '\377' )
SyntaxError("string must end with \" before end of file");
if ( sizeof(Value)-1 <= i )
SyntaxError("string must have less than 1024 characters");
if ( i < sizeof(Value)-1 )  Value[i] = '\0';
Symbol = S_STRING;
if ( *In == '"' )  GET_CHAR();
}
void            GetChar ()
{
GET_CHAR();
if ( *In == '\\' ) {
GET_CHAR();
if ( *In == 'n'  )       Value[0] = '\n';
else if ( *In == 't'  )  Value[0] = '\t';
else if ( *In == 'r'  )  Value[0] = '\r';
else if ( *In == 'b'  )  Value[0] = '\b';
else if ( *In == 'c'  )  Value[0] = '\03';
else                     Value[0] = *In;
}
else {
Value[0] = *In;
}
GET_CHAR();
if ( *In != '\'' )
SyntaxError("missing single quote in character constant");
Symbol = S_CHAR;
if ( *In == '\'' )  GET_CHAR();
}
void            GetSymbol ()
{
if ( *In == '\0' )
GET_CHAR();
while (*In==' '||*In=='\t'||*In=='\n'||*In=='\r'||*In=='\f'||*In=='#') {
if ( *In == '#' ) {
while ( *In != '\n' && *In != '\r' && *In != '\377' )
GET_CHAR();
}
GET_CHAR();
}
switch ( *In ) {
case '.':   Symbol = S_DOT;                         GET_CHAR();
if ( *In == '.' ) { Symbol = S_DOTDOT;  GET_CHAR();  break; }
break;
case '[':   Symbol = S_LBRACK;                      GET_CHAR();  break;
case ']':   Symbol = S_RBRACK;                      GET_CHAR();  break;
case '{':   Symbol = S_LBRACE;                      GET_CHAR();  break;
case '}':   Symbol = S_RBRACE;                      GET_CHAR();  break;
case '(':   Symbol = S_LPAREN;                      GET_CHAR();  break;
case ')':   Symbol = S_RPAREN;                      GET_CHAR();  break;
case ',':   Symbol = S_COMMA;                       GET_CHAR();  break;
case ':':   Symbol = S_ILLEGAL;                     GET_CHAR();
if ( *In == '=' ) { Symbol = S_ASSIGN;  GET_CHAR();  break; }
break;
case ';':   Symbol = S_SEMICOLON;                   GET_CHAR();  break;
case '=':   Symbol = S_EQ;                          GET_CHAR();  break;
case '<':   Symbol = S_LT;                          GET_CHAR();
if ( *In == '=' ) { Symbol = S_LE;      GET_CHAR();  break; }
if ( *In == '>' ) { Symbol = S_NE;      GET_CHAR();  break; }
break;
case '>':   Symbol = S_GT;                          GET_CHAR();
if ( *In == '=' ) { Symbol = S_GE;      GET_CHAR();  break; }
break;
case '+':   Symbol = S_PLUS;                        GET_CHAR();  break;
case '-':   Symbol = S_MINUS;                       GET_CHAR();
if ( *In == '>' ) { Symbol=S_MAPTO;     GET_CHAR();  break; }
break;
case '*':   Symbol = S_MULT;                        GET_CHAR();  break;
case '/':   Symbol = S_DIV;                         GET_CHAR();  break;
case '^':   Symbol = S_POW;                         GET_CHAR();  break;
case '"':                                           GetStr();    break;
case '\'':                                          GetChar();   break;
case '\\':                                          GetIdent();  break;
case '_':                                           GetIdent();  break;
case '~':   Value[0] = '~';  Value[1] = '\0';
Symbol = S_IDENT;                       GET_CHAR();  break;
case '0': case '1': case '2': case '3': case '4':
case '5': case '6': case '7': case '8': case '9':   GetInt();    break;
case '\377': Symbol = S_EOF;                        *In = '\0';  break;
default :   if ( IsAlpha(*In) )                   { GetIdent();  break; }
Symbol = S_ILLEGAL;                     GET_CHAR();  break;
}
}
void            SyntaxError ( msg )
char                * msg;
{
long                i;
NrError++;
NrErrLine++;
if ( NrErrLine != 1 )
return;
Pr( "Syntax error: %s", (long)msg, 0L );
if ( SyStrcmp( "*stdin*", Input->name ) != 0 )
Pr( " in %s line %d", (long)Input->name, (long)Input->number );
Pr( "\n", 0L, 0L );
Pr( "%s", (long)Input->line, 0L );
for ( i = 0; i < In - Input->line - 1; i++ ) {
if ( Input->line[i] == '\t' )  Pr("\t",0L,0L);
else  Pr(" ",0L,0L);
}
Pr( "^\n", 0L, 0L );
}
void            Match ( symbol, msg, skipto )
unsigned long       symbol;
char                * msg;
TypSymbolSet        skipto;
{
char                errmsg [256];
if ( symbol == Symbol ) {
GetSymbol();
}
else {
errmsg[0] ='\0';
SyStrncat( errmsg, msg, sizeof(errmsg)-1 );
SyStrncat( errmsg, " expected",
(long)(sizeof(errmsg)-1-SyStrlen(errmsg)) );
SyntaxError( errmsg );
while ( ! IS_IN( Symbol, skipto ) )
GetSymbol();
}
}
void            PutLine ()
{
if ( TestInput != -1 && TestOutput == Output->file
&& (TestLine[0]!='\0' || SyFgets(TestLine,sizeof(TestLine),TestInput))
&& TestLine[0]=='#' && TestLine[1]=='>'
&& ! SyStrcmp( TestLine+2, Output->line ) ) {
TestLine[0] = '\0';
}
else {
SyFputs( Output->line, Output->file );
}
if ( Logfile != -1 && (Output->file == 1 || Output->file == 3))
SyFputs( Output->line, Logfile );
}
void            PutChr ( ch )
char                ch;
{
long                i;
char                str [ 256 ];
if ( ch == '\01' ) {
if ( Output->indent < Output->pos
&& SyNrCols-Output->pos  + 16*Output->indent
<= SyNrCols-Output->spos + 16*Output->sindent ) {
Output->spos     = Output->pos;
Output->sindent  = Output->indent;
}
Output->indent++;
}
else if ( ch == '\02' ) {
if ( Output->indent < Output->pos
&& SyNrCols-Output->pos  + 16*Output->indent
<= SyNrCols-Output->spos + 16*Output->sindent ) {
Output->spos     = Output->pos;
Output->sindent  = Output->indent;
}
Output->indent--;
}
else if ( ch == '\03' ) {
Output->line[ Output->pos ] = '\0';
PutLine();
Output->pos      = 0;
Output->spos     = 0;
Output->sindent  = 666;
}
else if ( ch == '\n' || ch == '\r' ) {
Output->line[ Output->pos++ ] = ch;
Output->line[ Output->pos   ] = '\0';
PutLine();
Output->pos = 0;
for ( i = 0;  i < Output->indent; i++ )
Output->line[ Output->pos++ ] = ' ';
Output->spos     = 0;
Output->sindent  = 666;
}
else if ( Output->pos < SyNrCols-2 ) {
Output->line[ Output->pos++ ] = ch;
}
else if ( Output->spos == Output->pos && ch == ' ' ) {
;
}
else if ( Output->spos != 0 ) {
Output->line[ Output->pos++ ] = ch;
Output->line[ Output->pos++ ] = '\0';
for ( i = Output->spos; i < Output->pos; i++ )
str[ i-Output->spos ] = Output->line[ i ];
Output->line[ Output->spos++ ] = '\n';
Output->line[ Output->spos   ] = '\0';
PutLine();
Output->pos = 0;
for ( i = 0; i < Output->sindent; i++ )
Output->line[ Output->pos++ ] = ' ';
for ( i = 0; str[ i ] != '\0'; i++ )
Output->line[ Output->pos++ ] = str[ i ];
Output->spos     = 0;
Output->sindent  = 666;
}
else {
Output->line[ Output->pos++ ] = '\\';
Output->line[ Output->pos++ ] = '\n';
Output->line[ Output->pos   ] = '\0';
PutLine();
Output->pos = 0;
Output->line[ Output->pos++ ] = ch;
Output->spos     = 0;
Output->sindent  = 666;
}
}
void            Pr ( format, arg1, arg2 )
char                * format;
long                arg1, arg2;
{
char                * p,  * q;
long                prec,  n;
char                fill;
for ( p = format; *p != '\0'; p++ ) {
if ( *p == '%' ) {
p++;
if ( *p == '0' )  fill = '0';  else fill = ' ';
for ( prec = 0; IsDigit(*p); p++ )
prec = 10 * prec + *p - '0';
if ( *p == 'd' ) {
if ( arg1 < 0 ) {
prec--;
for ( n=1; n <= -(arg1/10); n*=10 )
prec--;
while ( --prec > 0 )  PutChr(fill);
PutChr('-');
for ( ; n > 0; n /= 10 )
PutChr( (char)(-((arg1/n)%10) + '0') );
arg1 = arg2;
}
else {
for ( n=1; n<=arg1/10; n*=10 )
prec--;
while ( --prec > 0 )  PutChr(fill);
for ( ; n > 0; n /= 10 )
PutChr( (char)(((arg1/n)%10) + '0') );
arg1 = arg2;
}
}
else if ( *p == 's' ) {
for ( q = (char*)arg1; *q != '\0'; q++ )
prec--;
while ( prec-- > 0 )  PutChr(' ');
for ( q = (char*)arg1; *q != '\0'; q++ )
PutChr( *q );
arg1 = arg2;
}
else if ( *p == 'c' ) {
PutChr( (char)arg1 );
arg1 = arg2;
}
else if ( *p == '>' ) {
PutChr( '\01' );
while ( --prec > 0 )
PutChr( '\01' );
}
else if ( *p == '<' ) {
PutChr( '\02' );
while ( --prec > 0 )
PutChr( '\02' );
}
else if ( *p == '%' ) {
PutChr( '%' );
}
else {
for ( p = "%format error"; *p != '\0'; p++ )
PutChr( *p );
}
}
else {
PutChr( *p );
}
}
}
long            OpenInput ( filename )
char                * filename;
{
long                file;
if ( Input+1 == InputFiles+(sizeof(InputFiles)/sizeof(InputFiles[0])) )
return 0;
if ( TestInput != -1 && ! SyStrcmp( filename, "*errin*" ) )
return 1;
file = SyFopen( filename, "r" );
if ( file == -1 )
return 0;
if ( Input != InputFiles-1 )
Input->ptr = In;
Input++;
Input->file = file;
Input->name[0] = '\0';
SyStrncat( Input->name, filename, sizeof(Input->name) );
In = Input->line;
In[0] = In[1] = '\0';
Symbol = S_ILLEGAL;
Input->number = 1;
return 1;
}
long            CloseInput ()
{
if ( Input == InputFiles )
return 0;
if ( Input->file == TestInput )
return 0;
SyFclose( Input->file );
Input--;
In = Input->ptr;
Symbol = S_ILLEGAL;
return 1;
}
long            OpenOutput ( filename )
char                * filename;
{
long                file;
if ( Output+1==OutputFiles+(sizeof(OutputFiles)/sizeof(OutputFiles[0])) )
return 0;
if ( TestInput != -1 && ! SyStrcmp( filename, "*errout*" ) )
return 1;
file = SyFopen( filename, "w" );
if ( file == -1 )
return 0;
Output++;
Output->file    = file;
Output->line[0] = '\0';
Output->pos     = 0;
Output->indent  = 0;
Output->spos    = 0;
Output->sindent = 666;
return 1;
}
long            CloseOutput ()
{
if ( Output == OutputFiles )
return 0;
if ( Output->file == TestOutput )
return 0;
Pr( "%c", (long)'\03', 0L );
SyFclose( Output->file );
Output--;
return 1;
}
long            OpenAppend ( filename )
char                * filename;
{
long                file;
if ( Output+1==OutputFiles+(sizeof(OutputFiles)/sizeof(OutputFiles[0])) )
return 0;
if ( TestInput != -1 && ! SyStrcmp( filename, "*errout*" ) )
return 1;
file = SyFopen( filename, "a" );
if ( file == -1 )
return 0;
Output++;
Output->file    = file;
Output->line[0] = '\0';
Output->pos     = 0;
Output->indent  = 0;
Output->spos    = 0;
Output->sindent = 666;
return 1;
}
long            CloseAppend ()
{
if ( Output == OutputFiles )
return 0;
if ( Output->file == TestOutput )
return 0;
Pr( "%c", (long)'\03', 0L );
SyFclose( Output->file );
Output--;
return 1;
}
long            OpenLog ( filename )
char                * filename;
{
if ( Logfile != -1 )
return 0;
Logfile = SyFopen( filename, "w" );
if ( Logfile == -1 )
return 0;
return 1;
}
long            CloseLog ()
{
if ( Logfile == -1 )
return 0;
SyFclose( Logfile );
Logfile = -1;
return 1;
}
long            OpenInputLog ( filename )
char                * filename;
{
if ( InputLogfile != -1 )
return 0;
InputLogfile = SyFopen( filename, "w" );
if ( InputLogfile == -1 )
return 0;
return 1;
}
long            CloseInputLog ()
{
if ( InputLogfile == -1 )
return 0;
SyFclose( InputLogfile );
InputLogfile = -1;
return 1;
}
long            OpenTest ( filename )
char                * filename;
{
if ( TestInput != -1 )
return 0;
if ( ! OpenInput( filename ) )
return 0;
TestInput   = Input->file;
TestOutput  = Output->file;
TestLine[0] = '\0';
return 1;
}
long            CloseTest ()
{
if ( TestInput != Input->file )
return 0;
SyFclose( Input->file );
Input--;
In = Input->ptr;
Symbol = S_ILLEGAL;
TestInput   = -1;
TestOutput  = -1;
TestLine[0] = '\0';
return 1;
}
void            InitScanner ()
{
long                ignore;
Input  = InputFiles-1;   ignore = OpenInput(  "*stdin*"  );
Output = OutputFiles-1;  ignore = OpenOutput( "*stdout*" );
Logfile = -1;  InputLogfile = -1;  TestInput = -1;  TestOutput = -1;
}
/* 当前文件是D:\Read\set.c*/

long            LenSet ( hdList )
TypHandle           hdList;
{
return LEN_PLIST( hdList );
}
TypHandle       ElmSet ( hdList, pos )
TypHandle           hdList;
long                pos;
{
TypHandle           hdElm;
if ( LEN_PLIST( hdList ) < pos ) {
return Error(
"List Element: <list>[%d] must have a value",
pos, 0L );
}
hdElm = ELM_PLIST( hdList, pos );
return hdElm;
}
TypHandle       ElmfSet ( hdList, pos )
TypHandle           hdList;
long                pos;
{
return ELM_PLIST( hdList, pos );
}
TypHandle       ElmsSet ( hdList, hdPoss )
TypHandle           hdList;
TypHandle           hdPoss;
{
TypHandle           hdElms;
long                lenList;
TypHandle           hdElm;
long                lenPoss;
long                pos;
long                inc;
long                i;
if ( TYPE(hdPoss) != T_RANGE ) {
lenList = LEN_PLIST( hdList );
lenPoss = LEN_LIST( hdPoss );
if ( TYPE(hdPoss) == T_SET )
hdElms = NewBag( T_SET, SIZE_PLEN_PLIST( lenPoss ) );
else
hdElms = NewBag( T_LIST, SIZE_PLEN_PLIST( lenPoss ) );
SET_LEN_PLIST( hdElms, lenPoss );
for ( i = 1; i <= lenPoss; i++ ) {
pos = HD_TO_INT( ELMF_LIST( hdPoss, i ) );
if ( lenList < pos ) {
return Error(
"List Elements: <list>[%d] must have a value",
pos, 0L );
}
hdElm = ELM_PLIST( hdList, pos );
SET_ELM_PLIST( hdElms, i, hdElm );
}
}
else {
lenList = LEN_PLIST( hdList );
lenPoss = LEN_RANGE( hdPoss );
pos = LOW_RANGE( hdPoss );
inc = INC_RANGE( hdPoss );
if ( lenList < pos ) {
return Error(
"List Elements: <list>[%d] must have a value",
pos, 0L );
}
if ( lenList < pos + (lenPoss-1) * inc ) {
return Error(
"List Elements: <list>[%d] must have a value",
pos + (lenPoss-1) * inc, 0L );
}
if ( 0 < inc )
hdElms = NewBag( T_SET, SIZE_PLEN_PLIST( lenPoss ) );
else
hdElms = NewBag( T_LIST, SIZE_PLEN_PLIST( lenPoss ) );
SET_LEN_PLIST( hdElms, lenPoss );
for ( i = 1; i <= lenPoss; i++, pos += inc ) {
hdElm = ELM_PLIST( hdList, pos );
SET_ELM_PLIST( hdElms, i, hdElm );
}
}
return hdElms;
}
TypHandle       AssSet ( hdList, pos, hdVal )
TypHandle           hdList;
long                pos;
TypHandle           hdVal;
{
long                plen;
Retype( hdList, T_LIST );
if ( LEN_PLIST( hdList ) < pos ) {
plen = PLEN_SIZE_PLIST( SIZE(hdList) );
if ( plen + plen/8 + 4 < pos )
Resize( hdList, SIZE_PLEN_PLIST( pos ) );
else if ( plen < pos )
Resize( hdList, SIZE_PLEN_PLIST( plen + plen/8 + 4 ) );
SET_LEN_PLIST( hdList, pos );
}
SET_ELM_PLIST( hdList, pos, hdVal );
return hdVal;
}
TypHandle       AsssSet ( hdList, hdPoss, hdVals )
TypHandle           hdList;
TypHandle           hdPoss;
TypHandle           hdVals;
{
Retype( hdList, T_LIST );
return ASSS_LIST( hdList, hdPoss, hdVals );
}
long            PosSet ( hdList, hdVal, start )
TypHandle           hdList;
TypHandle           hdVal;
long                start;
{
unsigned long       lenList;
unsigned long       i, j, k;
lenList = LEN_PLIST( hdList );
i = start;  k = lenList + 1;
while ( i+1 < k ) {
j = (i + k) / 2;
if ( LT( ELM_PLIST(hdList,j), hdVal ) == HdTrue )  i = j;
else                                               k = j;
}
if ( lenList < k || EQ( ELM_PLIST(hdList,k), hdVal ) != HdTrue )
k = 0;
return k;
}
void            PlainSet ( hdList )
TypHandle           hdList;
{
return;
}
long            IsDenseSet ( hdList )
TypHandle           hdList;
{
return 1;
}
long            IsPossSet ( hdList )
TypHandle           hdList;
{
long                lenList;
TypHandle           hdElm;
lenList = LEN_PLIST( hdList );
if ( lenList == 0 )
return 1;
hdElm = ELM_PLIST( hdList, 1 );
if ( TYPE(hdElm) != T_INT || HD_TO_INT(hdElm) <= 0 )
return 0;
hdElm = ELM_PLIST( hdList, lenList );
if ( TYPE(hdElm) != T_INT )
return 0;
return 1;
}
TypHandle       EqSet ( hdL, hdR )
TypHandle           hdL;
TypHandle           hdR;
{
long                lenL;
long                lenR;
TypHandle           hdElmL;
TypHandle           hdElmR;
long                i;
lenL = LEN_PLIST( hdL );
lenR = LEN_PLIST( hdR );
if ( lenL != lenR ) {
return HdFalse;
}
for ( i = 1; i <= lenL; i++ ) {
hdElmL = ELM_PLIST( hdL, i );
hdElmR = ELM_PLIST( hdR, i );
if ( hdElmL != hdElmR && EQ( hdElmL, hdElmR ) == HdFalse ) {
return HdFalse;
}
}
return HdTrue;
}
TypHandle       LtSet ( hdL, hdR )
TypHandle           hdL;
TypHandle           hdR;
{
long                lenL;
long                lenR;
TypHandle           hdElmL;
TypHandle           hdElmR;
long                i;
lenL = LEN_PLIST( hdL );
lenR = LEN_PLIST( hdR );
for ( i = 1; i <= lenL && i <= lenR; i++ ) {
hdElmL = ELM_PLIST( hdL, i );
hdElmR = ELM_PLIST( hdR, i );
if ( hdElmL != hdElmR && EQ( hdElmL, hdElmR ) == HdFalse ) {
return LT( hdElmL, hdElmR );
}
}
return (lenL < lenR) ? HdTrue : HdFalse;
}
TypHandle       SetList ( hdList )
TypHandle           hdList;
{
TypHandle           hdSet;
TypHandle           hdElm;
long                lenSet;
long                lenList;
long                mutable;
long                h;
long                i, k;
lenList = LEN_LIST( hdList );
hdSet = NewBag( T_SET, SIZE_PLEN_PLIST( lenList ) );
lenSet = 0;
mutable = 0;
for ( i = 1; i <= lenList; i++ ) {
hdElm = ELMF_LIST( hdList, i );
if ( hdElm != 0 ) {
lenSet += 1;
mutable = mutable || (T_LIST <= TYPE(hdElm));
SET_ELM_PLIST( hdSet, lenSet, hdElm );
}
}
h = 1;  while ( 9*h + 4 < lenSet )  h = 3*h + 1;
while ( 0 < h ) {
for ( i = h+1; i <= lenSet; i++ ) {
hdElm = ELM_PLIST( hdSet, i );  k = i;
while ( h < k && LT( hdElm, ELM_PLIST(hdSet,k-h) ) == HdTrue ) {
SET_ELM_PLIST( hdSet, k, ELM_PLIST(hdSet,k-h) );
k -= h;
}
SET_ELM_PLIST( hdSet, k, hdElm );
}
h = h / 3;
}
if ( 0 < lenSet ) {
hdElm = ELM_PLIST( hdSet, 1 );
k = 1;
for ( i = 2; i <= lenSet; i++ ) {
if ( EQ( hdElm, ELM_PLIST( hdSet, i ) ) != HdTrue ) {
k += 1;
hdElm = ELM_PLIST( hdSet, i );
SET_ELM_PLIST( hdSet, k, hdElm );
}
}
if ( k < lenSet )
lenSet = k;
}
if ( mutable )
Retype( hdSet, T_LIST );
if ( lenSet < lenList )
Resize( hdSet, SIZE_PLEN_PLIST( lenSet ) );
SET_LEN_PLIST( hdSet, lenSet );
return hdSet;
}
TypHandle       FunSet ( hdCall )
TypHandle           hdCall;
{
TypHandle           hdSet;
TypHandle           hdList;
long                lenList;
long                i;
if ( SIZE(hdCall) != 2 * SIZE_HD )
return Error("usage: Set( <obj> )",0L,0L);
hdList = EVAL( PTR(hdCall)[1] );
if ( ! IS_LIST( hdList ) ) {
return Error(
"Set: <list> must be a list",
0L, 0L );
}
if ( IsSet( hdList ) ) {
lenList = LEN_PLIST(hdList);
hdSet = NewBag( TYPE(hdList), SIZE_PLEN_PLIST( lenList ) );
SET_LEN_PLIST( hdSet, lenList );
for ( i = 1; i <= lenList; i++ ) {
SET_ELM_PLIST( hdSet, i, ELM_PLIST( hdList, i ) );
}
}
else {
hdSet = SetList( hdList );
}
return hdSet;
}
long            IsSet ( hdList )
TypHandle           hdList;
{
long                isSet;
long                lenList;
TypHandle           hdElm1, hdElm2;
long                mutable;
long                i;
if ( ! IS_LIST( hdList ) ) {
isSet = 0;
}
else if ( TYPE(hdList) == T_SET ) {
isSet = 1;
}
else if ( TYPE(hdList) == T_RANGE && 0 < INC_RANGE(hdList) ) {
PLAIN_LIST( hdList );
Retype( hdList, T_SET );
isSet = 1;
}
else if ( TYPE(hdList) == T_RANGE ) {
isSet = 0;
}
else if ( LEN_LIST(hdList) == 0 ) {
PLAIN_LIST( hdList );
Retype( hdList, T_SET );
isSet = 1;
}
else if ( ELMF_LIST( hdList, 1 ) == 0 ) {
isSet = 0;
}
else {
PLAIN_LIST( hdList );
lenList = LEN_PLIST( hdList );
hdElm1 = ELM_PLIST( hdList, 1 );
mutable = T_LIST <= TYPE(hdElm1);
for ( i = 2; i <= lenList; i++ ) {
hdElm2 = ELM_PLIST( hdList, i );
if ( hdElm2 == 0 || LT( hdElm1, hdElm2 ) != HdTrue )
break;
mutable = mutable || (T_LIST <= TYPE(hdElm2));
hdElm1 = hdElm2;
}
isSet = (lenList < i);
if ( isSet && ! mutable )  Retype( hdList, T_SET );
}
return isSet;
}
TypHandle       FunIsSet ( hdCall )
TypHandle           hdCall;
{
TypHandle           hdObj;
if ( SIZE(hdCall) != 2 * SIZE_HD )
return Error("usage: IsSet( <obj> )",0L,0L);
hdObj = EVAL( PTR(hdCall)[1] );
if ( hdObj == HdVoid )
return Error("IsSet: function must return a value",0L,0L);
return IsSet( hdObj ) ? HdTrue : HdFalse;
}
TypHandle       FunIsEqualSet ( hdCall )
TypHandle           hdCall;
{
TypHandle           hdSet1;
TypHandle           hdSet2;
unsigned long       l1;
unsigned long       l2;
unsigned long       i;
if ( SIZE(hdCall) != 3 * SIZE_HD )
return Error("usage: IsEqualSet( <set1>, <set2> )",0L,0L);
hdSet1 = EVAL( PTR(hdCall)[1] );
if ( ! IS_LIST(hdSet1) )
return Error("IsEqualSet: <set1> must be a list",0L,0L);
hdSet2 = EVAL( PTR(hdCall)[2] );
if ( ! IS_LIST(hdSet2) )
return Error("IsEqualSet: <set2> must be a list",0L,0L);
if ( ! IsSet( hdSet1 ) )  hdSet1 = SetList( hdSet1 );
if ( ! IsSet( hdSet2 ) )  hdSet2 = SetList( hdSet2 );
l1 = LEN_PLIST( hdSet1 );
l2 = LEN_PLIST( hdSet2 );
if ( l1 != l2 )  return HdFalse;
for ( i = 1; i <= l1; i++ ) {
if ( ELM_PLIST(hdSet1,i) != ELM_PLIST(hdSet2,i)
&& EQ( ELM_PLIST(hdSet1,i), ELM_PLIST(hdSet2,i) ) != HdTrue )
break;
}
return (i == l1+1) ? HdTrue : HdFalse;
}
TypHandle       FunIsSubsetSet ( hdCall )
TypHandle           hdCall;
{
TypHandle           hdSet1;
TypHandle           hdSet2;
unsigned long       l1;
unsigned long       l2;
unsigned long       i1;
unsigned long       i2;
unsigned long       i, j, k;
if ( SIZE(hdCall) != 3 * SIZE_HD )
return Error("usage: IsSubsetSet( <set1>, <set2> )",0L,0L);
hdSet1 = EVAL( PTR(hdCall)[1] );
if ( ! IS_LIST(hdSet1) )
return Error("IsSubsetSet: <set1> must be a list",0L,0L);
hdSet2 = EVAL( PTR(hdCall)[2] );
if ( ! IS_LIST(hdSet2) )
return Error("IsSubsetSet: <set2> must be a list",0L,0L);
if ( ! IsSet( hdSet1 ) )  hdSet1 = SetList( hdSet1 );
if ( IsSet( hdSet2 ) ) {
l1 = LEN_PLIST( hdSet1 );
l2 = LEN_PLIST( hdSet2 );
i1 = 1;
i2 = 1;
while ( i2 <= l2 && l2 + i1 <= l1 + i2 ) {
if ( ELM_PLIST(hdSet1,i1) == ELM_PLIST(hdSet2,i2)
|| EQ(ELM_PLIST(hdSet1,i1),ELM_PLIST(hdSet2,i2)) == HdTrue ) {
i1++;  i2++;
}
else if (LT(ELM_PLIST(hdSet1,i1),ELM_PLIST(hdSet2,i2))==HdTrue) {
i1++;
}
else {
break;
}
}
}
else {
PLAIN_LIST( hdSet2 );
l1 = LEN_PLIST( hdSet1 );
l2 = LEN_PLIST( hdSet2 );
for ( i2 = 1; i2 <= l2; i2++ ) {
if ( ELM_PLIST(hdSet2,i2) == 0 )
continue;
i = 0;  k = l1+1;
while ( i+1 < k ) {
j = (i + k) / 2;
if ( LT(ELM_PLIST(hdSet1,j),ELM_PLIST(hdSet2,i2)) == HdTrue )
i = j;
else
k = j;
}
if ( l1 < k
|| EQ(ELM_PLIST(hdSet1,k),ELM_PLIST(hdSet2,i2)) != HdTrue ) {
break;
}
}
}
return (i2 == l2 + 1) ? HdTrue : HdFalse;
}
TypHandle       FunAddSet ( hdCall )
TypHandle           hdCall;
{
TypHandle           hdSet;
TypHandle           hdObj;
unsigned long       len;
unsigned long       i,  j,  k;
if ( SIZE(hdCall) != 3 * SIZE_HD )
return Error("usage: AddSet( <set>, <obj> )",0L,0L);
hdSet = EVAL( PTR(hdCall)[1] );
hdObj = EVAL( PTR(hdCall)[2] );
if ( ! IsSet( hdSet ) )
return Error("AddSet: <set> must be a proper set",0L,0L);
if ( hdObj == HdVoid )
return Error("AddSet: <obj> function must return a value",0L,0L);
len   = LEN_PLIST( hdSet );
i = 0;  k = len+1;
while ( i+1 < k ) {
j = (i + k) / 2;
if ( LT( ELM_PLIST(hdSet,j), hdObj ) == HdTrue )  i = j;
else                                              k = j;
}
if ( len < k || EQ( ELM_PLIST(hdSet,k), hdObj ) != HdTrue ) {
if ( SIZE(hdSet) < SIZE_PLEN_PLIST( len+1 ) )
Resize( hdSet, SIZE_PLEN_PLIST( len + len/8 + 4 ) );
SET_LEN_PLIST( hdSet, len+1 );
for ( i = len+1; k < i; i-- )
SET_ELM_PLIST( hdSet, i, ELM_PLIST(hdSet,i-1) );
SET_ELM_PLIST( hdSet, k, hdObj );
	if ( TYPE(hdSet) == T_SET && T_LIST <= TYPE(hdObj) )
	    Retype( hdSet, T_LIST );
}
return HdVoid;
}
TypHandle       FunRemoveSet ( hdCall )
TypHandle           hdCall;
{
TypHandle           hdSet;
TypHandle           hdObj;
unsigned long       len;
unsigned long       i,  j,  k;
if ( SIZE(hdCall) != 3 * SIZE_HD )
return Error("usage: RemoveSet( <set>, <obj> )",0L,0L);
hdSet = EVAL( PTR(hdCall)[1] );
hdObj = EVAL( PTR(hdCall)[2] );
if ( ! IsSet( hdSet ) )
return Error("RemoveSet: <set> must be a proper set",0L,0L);
if ( hdObj == HdVoid )
return Error("RemoveSet: <obj> function must return a value",0L,0L);
len   = LEN_PLIST( hdSet );
i = 0;  k = len+1;
while ( i+1 < k ) {
j = (i + k) / 2;
if ( LT( ELM_PLIST(hdSet,j), hdObj ) == HdTrue )  i = j;
else                                              k = j;
}
if ( k <= len && EQ( ELM_PLIST(hdSet,k), hdObj ) == HdTrue ) {
for ( i = k; i < len; i++ )
SET_ELM_PLIST( hdSet, i, ELM_PLIST(hdSet,i+1) );
SET_ELM_PLIST( hdSet, len, 0 );
SET_LEN_PLIST( hdSet, len-1 );
}
return HdVoid;
}
TypHandle       HdUnion;
TypHandle       FunUniteSet ( hdCall )
TypHandle           hdCall;
{
TypHandle           hdSet1;
TypHandle           hdSet2;
unsigned long       l1;
unsigned long       l2;
unsigned long       lr;
unsigned long       i1;
unsigned long       i2;
long                plen;
if ( SIZE(hdCall) != 3*SIZE_HD )
return Error("usage: UniteSet( <set1>, <set2> )",0L,0L);
hdSet1 = EVAL( PTR(hdCall)[1] );
hdSet2 = EVAL( PTR(hdCall)[2] );
if ( ! IsSet( hdSet1 ) )
return Error("UniteSet: <set1> must be a set",0L,0L);
if ( ! IS_LIST(hdSet2) )
return Error("UniteSet: <set2> must be a list",0L,0L);
if ( ! IsSet( hdSet2 ) )  hdSet2 = SetList( hdSet2 );
l1 = LEN_PLIST( hdSet1 );
l2 = LEN_PLIST( hdSet2 );
if ( SIZE(HdUnion) < SIZE_PLEN_PLIST( l1+l2 ) ) {
plen = PLEN_SIZE_PLIST( SIZE(HdUnion) );
if ( plen + plen/8 + 4 < l1 + l2 )
Resize( HdUnion, SIZE_PLEN_PLIST( l1+l2 ) );
else
Resize( HdUnion, SIZE_PLEN_PLIST( plen + plen/8 + 4 ) );
}
lr = 0;
i1 = 1;
i2 = 1;
while ( i1 <= l1 || i2 <= l2 ) {
if ( i1 <= l1 && i2 <= l2
&& (ELM_PLIST(hdSet1,i1) == ELM_PLIST(hdSet2,i2)
|| EQ(ELM_PLIST(hdSet1,i1),ELM_PLIST(hdSet2,i2)) == HdTrue) ) {
SET_ELM_PLIST( HdUnion, lr+1, ELM_PLIST(hdSet1,i1) );
lr++; i1++;  i2++;
}
else if ( i2 == l2 + 1
|| (i1<=l1
&& LT(ELM_PLIST(hdSet1,i1),ELM_PLIST(hdSet2,i2))==HdTrue) ) {
SET_ELM_PLIST( HdUnion, lr+1, ELM_PLIST(hdSet1,i1) );
lr++; i1++;
}
else {
SET_ELM_PLIST( HdUnion, lr+1, ELM_PLIST(hdSet2,i2) );
lr++; i2++;
}
}
if ( SIZE(hdSet1) < SIZE_PLEN_PLIST( lr ) ) {
plen = PLEN_SIZE_PLIST( SIZE(hdSet1) );
if ( plen + plen/8 + 4 < lr )
Resize( hdSet1, SIZE_PLEN_PLIST( lr ) );
else
Resize( hdSet1, SIZE_PLEN_PLIST( plen + plen/8 + 4 ) );
}
for ( i1 = 1; i1 <= lr; i1++ ) {
SET_ELM_PLIST( hdSet1, i1, ELM_PLIST( HdUnion, i1 ) );
SET_ELM_PLIST( HdUnion, i1, 0 );
}
SET_LEN_PLIST( hdSet1, lr );
return HdVoid;
}
TypHandle       FunIntersectSet ( hdCall )
TypHandle           hdCall;
{
TypHandle           hdSet1;
TypHandle           hdSet2;
unsigned long       l1;
unsigned long       l2;
unsigned long       lr;
unsigned long       i1;
unsigned long       i2;
if ( SIZE(hdCall) != 3*SIZE_HD )
return Error("usage: IntersectSet( <set1>, <set2> )",0L,0L);
hdSet1 = EVAL( PTR(hdCall)[1] );
hdSet2 = EVAL( PTR(hdCall)[2] );
if ( ! IsSet( hdSet1 ) )
return Error("IntersectSet: <set1> must be a set",0L,0L);
if ( ! IS_LIST(hdSet2) )
return Error("IntersectSet: <set2> must be a list",0L,0L);
if ( ! IsSet( hdSet2 ) )  hdSet2 = SetList( hdSet2 );
l1 = LEN_PLIST( hdSet1 );
l2 = LEN_PLIST( hdSet2 );
lr = 0;
i1 = 1;
i2 = 1;
while ( i1 <= l1 && i2 <= l2 ) {
if ( ELM_PLIST(hdSet1,i1) == ELM_PLIST(hdSet2,i2)
|| EQ( ELM_PLIST(hdSet1,i1), ELM_PLIST(hdSet2,i2) ) == HdTrue ) {
SET_ELM_PLIST( hdSet1, lr+1, ELM_PLIST(hdSet1,i1) );
lr++; i1++;  i2++;
}
else if ( LT(ELM_PLIST(hdSet1,i1),ELM_PLIST(hdSet2,i2)) == HdTrue ) {
i1++;
}
else {
i2++;
}
}
SET_LEN_PLIST( hdSet1, lr );
if ( SIZE_PLEN_PLIST( lr + lr/8 + 4 ) < SIZE(hdSet1) ) {
Resize( hdSet1, SIZE_PLEN_PLIST( lr ) );
}
else {
while ( lr < SIZE(hdSet1)/SIZE_HD-1 ) {
SET_ELM_PLIST( hdSet1, lr+1, 0 );
lr++;
}
}
return HdVoid;
}
TypHandle       FunSubtractSet ( hdCall )
TypHandle           hdCall;
{
TypHandle           hdSet1;
TypHandle           hdSet2;
unsigned long       l1;
unsigned long       l2;
unsigned long       lr;
unsigned long       i1;
unsigned long       i2;
if ( SIZE(hdCall) != 3*SIZE_HD )
return Error("usage: SubtractSet( <set1>, <set2> )",0L,0L);
hdSet1 = EVAL( PTR(hdCall)[1] );
hdSet2 = EVAL( PTR(hdCall)[2] );
if ( ! IsSet( hdSet1 ) )
return Error("SubtractSet: <set1> must be a set",0L,0L);
if ( ! IS_LIST(hdSet2) )
return Error("SubtractSet: <set2> must be a list",0L,0L);
if ( ! IsSet( hdSet2 ) )  hdSet2 = SetList( hdSet2 );
l1 = LEN_PLIST( hdSet1 );
l2 = LEN_PLIST( hdSet2 );
lr = 0;
i1 = 1;
i2 = 1;
while ( i1 <= l1 ) {
if ( i2 <= l2
&& (ELM_PLIST(hdSet1,i1) == ELM_PLIST(hdSet2,i2)
|| EQ( ELM_PLIST(hdSet1,i1), ELM_PLIST(hdSet2,i2) ) == HdTrue) ) {
i1++;  i2++;
}
else if ( i2 == l2+1
|| LT(ELM_PLIST(hdSet1,i1),ELM_PLIST(hdSet2,i2)) == HdTrue ) {
SET_ELM_PLIST( hdSet1, lr+1, ELM_PLIST(hdSet1,i1) );
lr++; i1++;
}
else {
i2++;
}
}
SET_LEN_PLIST( hdSet1, lr );
if ( SIZE_PLEN_PLIST( lr + lr/8 + 4 ) < SIZE(hdSet1) ) {
Resize( hdSet1, SIZE_PLEN_PLIST( lr ) );
}
else {
while ( lr < SIZE(hdSet1)/SIZE_HD-1 ) {
SET_ELM_PLIST( hdSet1, lr+1, 0 );
lr++;
}
}
return HdVoid;
}
void            InitSet ()
{
TabIsList[T_SET]      = 1;
TabLenList[T_SET]     = LenSet;
TabElmList[T_SET]     = ElmSet;
TabElmfList[T_SET]    = ElmfSet;
TabElmlList[T_SET]    = ElmfSet;
TabElmrList[T_SET]    = ElmfSet;
TabElmsList[T_SET]    = ElmsSet;
TabAssList[T_SET]     = AssSet;
TabAsssList[T_SET]    = AsssSet;
TabPosList[T_SET]     = PosSet;
TabPlainList[T_SET]   = PlainSet;
TabIsDenseList[T_SET] = IsDenseSet;
TabIsPossList[T_SET]  = IsPossSet;
EvTab[T_SET]          = EvList;
PrTab[T_SET]          = PrList;
TabEq[T_SET][T_SET]   = EqSet;
TabLt[T_SET][T_SET]   = LtSet;
InstIntFunc( "Set",          FunSet          );
InstIntFunc( "IsSet",        FunIsSet        );
InstIntFunc( "IsEqualSet",   FunIsEqualSet   );
InstIntFunc( "IsSubsetSet",  FunIsSubsetSet  );
InstIntFunc( "AddSet",       FunAddSet       );
InstIntFunc( "RemoveSet",    FunRemoveSet    );
InstIntFunc( "UniteSet",     FunUniteSet     );
InstIntFunc( "IntersectSet", FunIntersectSet );
InstIntFunc( "SubtractSet",  FunSubtractSet  );
HdUnion = NewBag( T_SET, SIZE_PLEN_PLIST( 1024 ) );
SET_LEN_PLIST( HdUnion, 0 );
}
/* 当前文件是D:\Read\statemen.c*/


TypHandle       EvStatseq ( hdSSeq )
TypHandle           hdSSeq;
{
TypHandle           hdRes;
unsigned long       k;
for ( k = 0; k < SIZE(hdSSeq)/SIZE_HD; ++k ) {
StrStat = "";  HdStat = PTR(hdSSeq)[k];
hdRes = EVAL( HdStat );
if ( hdRes == HdReturn )  return hdRes;
}
return HdVoid;
}
TypHandle       EvIf ( hdIf )
TypHandle           hdIf;
{
TypHandle           hdRes,  hdSSeq;
unsigned long       i,  k;
for ( i = 0; i < SIZE(hdIf) / (2*SIZE_HD); ++i ) {
if ( i == 0 ) StrStat = "if ";  else StrStat = "elif ";
HdStat = PTR(hdIf)[2*i];
hdRes = EVAL( HdStat );
while ( hdRes != HdTrue && hdRes != HdFalse )
hdRes=Error("if: <expr> must evaluate to 'true' or 'false'",0L,0L);
if ( hdRes == HdTrue ) {
hdSSeq = PTR(hdIf)[2*i+1];
if ( TYPE(hdSSeq) == T_STATSEQ ) {
for ( k = 0; k < SIZE(hdSSeq)/SIZE_HD; ++k ) {
StrStat = "";  HdStat = PTR(hdSSeq)[k];
hdRes = EVAL( HdStat );
if ( hdRes == HdReturn )  return hdRes;
}
}
else {
StrStat = "";  HdStat = hdSSeq;
hdRes = EVAL( HdStat );
if ( hdRes == HdReturn )  return hdRes;
}
return HdVoid;
}
}
if ( SIZE(hdIf) % (2*SIZE_HD) != 0 ) {
hdSSeq = PTR(hdIf)[SIZE(hdIf)/SIZE_HD-1];
if ( TYPE(hdSSeq) == T_STATSEQ ) {
for ( k = 0; k < SIZE(hdSSeq)/SIZE_HD; ++k ) {
StrStat = "";  HdStat = PTR(hdSSeq)[k];
hdRes = EVAL( HdStat );
if ( hdRes == HdReturn )  return hdRes;
}
}
else {
StrStat = "";  HdStat = hdSSeq;
hdRes = EVAL( HdStat );
if ( hdRes == HdReturn )  return hdRes;
}
return HdVoid;
}
return HdVoid;
}
TypHandle       EvFor ( hdFor )
TypHandle           hdFor;
{
TypHandle           hdList,  hdRes,  hdVar,  hdSSeq,  hdElm;
long                j;
unsigned long       i,  k;
hdVar  = PTR(hdFor)[0];
hdSSeq = PTR(hdFor)[2];
StrStat = "for <var>  in ";  HdStat = PTR(hdFor)[1];
if ( TYPE(HdStat) == T_MAKERANGE && SIZE(HdStat) == 2*SIZE_HD ) {
hdList = HdStat;
hdElm = EVAL( PTR(hdList)[0] );
while ( TYPE(hdElm) != T_INT )
hdElm = Error("Range: <low> must be an integer",0L,0L);
hdList = EVAL( PTR(hdList)[1] );
while ( TYPE(hdList) != T_INT )
hdList = Error("Range: <high> must be an integer",0L,0L);
for ( j = HD_TO_INT(hdElm); j <= HD_TO_INT(hdList); j++ ) {
PTR(hdVar)[0] = INT_TO_HD( j );
EnterKernel();
if ( TYPE(hdSSeq) == T_STATSEQ ) {
for ( k = 0; k < SIZE(hdSSeq)/SIZE_HD; ++k ) {
StrStat = "";  HdStat = PTR(hdSSeq)[k];
hdRes = EVAL( HdStat );
if ( hdRes == HdReturn ) {
ExitKernel( hdRes );
return hdRes;
}
}
}
else {
StrStat = "";  HdStat = hdSSeq;
hdRes = EVAL( HdStat );
if ( hdRes == HdReturn ) {
ExitKernel( hdRes );
return hdRes;
}
}
StrStat = "for ";  HdStat = hdVar;
if ( SyIsIntr() )  Error("user interrupt",0L,0L);
ExitKernel( (TypHandle)0 );
}
}
else {
hdList = EVAL( HdStat );
while ( ! IS_LIST( hdList ) )
hdList = Error("for: <list> must evaluate to a list",0L,0L);
EnterKernel();  ExitKernel( hdList );
for ( i = 1; 1; ++i ) {
if ( LEN_LIST(hdList) < i )  break;
hdElm = ELMF_LIST( hdList, i );
if ( hdElm == 0 )  continue;
PTR(hdVar)[0] = hdElm;
EnterKernel();
if ( TYPE(hdSSeq) == T_STATSEQ ) {
for ( k = 0; k < SIZE(hdSSeq)/SIZE_HD; ++k ) {
StrStat = "";  HdStat = PTR(hdSSeq)[k];
hdRes = EVAL( HdStat );
if ( hdRes == HdReturn ) {
ExitKernel( hdRes );
return hdRes;
}
}
}
else {
StrStat = "";  HdStat = hdSSeq;
hdRes = EVAL( HdStat );
if ( hdRes == HdReturn ) {
ExitKernel( hdRes );
return hdRes;
}
}
StrStat = "for ";  HdStat = hdVar;
if ( SyIsIntr() )  Error("user interrupt",0L,0L);
ExitKernel( (TypHandle)0 );
}
}
return HdVoid;
}
TypHandle       EvWhile ( hdWhile )
TypHandle           hdWhile;
{
TypHandle           hdRes,  hdCond,  hdSSeq;
unsigned long       k;
hdCond = PTR(hdWhile)[0];
hdSSeq = PTR(hdWhile)[1];
StrStat = "while ";  HdStat = hdCond;
hdRes = EVAL( hdCond );
while ( hdRes != HdTrue && hdRes != HdFalse )
hdRes = Error("while: <expr> must evalate to 'true' or 'false'",0L,0L);
if ( SyIsIntr() )  Error("user interrupt",0L,0L);
while ( hdRes == HdTrue ) {
EnterKernel();
if ( TYPE(hdSSeq) == T_STATSEQ ) {
for ( k = 0; k < SIZE(hdSSeq)/SIZE_HD; ++k ) {
StrStat = "";  HdStat = PTR(hdSSeq)[k];
hdRes = EVAL( HdStat );
if ( hdRes == HdReturn ) {
ExitKernel( hdRes );
return hdRes;
}
}
}
else {
StrStat = "";  HdStat = hdSSeq;
hdRes = EVAL( HdStat );
if ( hdRes == HdReturn ) {
ExitKernel( hdRes );
return hdRes;
}
}
StrStat = "while ";  HdStat = hdCond;
hdRes = EVAL( hdCond );
while ( hdRes != HdTrue && hdRes != HdFalse )
hdRes=Error("while: <expr> must evaluate to 'true' or 'false'",
0L,0L);
if ( SyIsIntr() )  Error("user interrupt",0L,0L);
ExitKernel( (TypHandle)0 );
}
return HdVoid;
}
TypHandle       EvRepeat ( hdRep )
TypHandle           hdRep;
{
TypHandle           hdRes, hdCond, hdSSeq;
unsigned long       k;
hdCond = PTR(hdRep)[0];
hdSSeq = PTR(hdRep)[1];
do {
EnterKernel();
if ( TYPE(hdSSeq) == T_STATSEQ ) {
for ( k = 0; k < SIZE(hdSSeq)/SIZE_HD; ++k ) {
StrStat = "";  HdStat = PTR(hdSSeq)[k];
hdRes = EVAL( HdStat );
if ( hdRes == HdReturn ) {
ExitKernel( hdRes );
return hdRes;
}
}
}
else {
StrStat = "";  HdStat = hdSSeq;
hdRes = EVAL( HdStat );
if ( hdRes == HdReturn ) {
ExitKernel( hdRes );
return hdRes;
}
}
StrStat = "until ";  HdStat = hdCond;
hdRes = EVAL( hdCond );
while ( hdRes != HdTrue && hdRes != HdFalse )
hdRes=Error("repeat: <expr> must evaluate to 'true' or 'false'",
0L,0L);
if ( SyIsIntr() )  Error("user interrupt",0L,0L);
ExitKernel( (TypHandle)0 );
} while ( hdRes != HdTrue );
return HdVoid;
}
void            PrStatseq ( hdSSeq )
TypHandle           hdSSeq;
{
unsigned long       k;
for ( k = 0; k < SIZE(hdSSeq)/SIZE_HD; ++k ) {
Print( PTR(hdSSeq)[k] );
if ( k < SIZE(hdSSeq)/SIZE_HD-1 )
Pr(";\n",0L,0L);
}
}
void            PrIf ( hdIf )
TypHandle           hdIf;
{
unsigned long       i;
for ( i = 0; i < SIZE(hdIf)/SIZE_HD/2; ++i ) {
if ( i == 0 ) Pr("if%4> ",0L,0L);  else Pr("elif%4> ",0L,0L);
Print( PTR(hdIf)[2*i] );
Pr("%2<  then%2>\n",0L,0L);
Print( PTR(hdIf)[2*i+1] );
Pr(";%4<\n",0L,0L);
}
if ( SIZE(hdIf)/SIZE_HD % 2 != 0 ) {
Pr("else%4>\n",0L,0L);
Print( PTR(hdIf)[ SIZE(hdIf)/SIZE_HD -1 ] );
Pr(";%4<\n",0L,0L);
}
Pr("fi",0L,0L);
}
void            PrFor ( hdFor )
TypHandle           hdFor;
{
Pr("for%4> ",0L,0L);       Print( PTR(hdFor)[0] );
Pr("%2<  in%2> ",0L,0L);   Print( PTR(hdFor)[1] );
Pr("%2<  do%2>\n",0L,0L);  Print( PTR(hdFor)[2] );
Pr(";%4<\nod",0L,0L);
}
void            PrWhile ( hdWhile )
TypHandle           hdWhile;
{
Pr("while%4> ",0L,0L);     Print( PTR(hdWhile)[0] );
Pr("%2<  do%2>\n",0L,0L);  Print( PTR(hdWhile)[1] );
Pr(";%4<\nod",0L,0L);
}
void            PrRepeat ( hdRep )
TypHandle           hdRep;
{
Pr("repeat%4>\n",0L,0L);
Print( PTR(hdRep)[1] );
Pr(";%4<\nuntil%2> ",0L,0L);
Print( PTR(hdRep)[0] );
Pr("%2<",0L,0L);
}
void            InitStat ()
{
InstEvFunc( T_STATSEQ,  EvStatseq );
InstEvFunc( T_IF,       EvIf      );
InstEvFunc( T_FOR,      EvFor     );
InstEvFunc( T_WHILE,    EvWhile   );
InstEvFunc( T_REPEAT,   EvRepeat  );
InstPrFunc( T_STATSEQ,  PrStatseq );
InstPrFunc( T_IF,       PrIf      );
InstPrFunc( T_FOR,      PrFor     );
InstPrFunc( T_WHILE,    PrWhile   );
InstPrFunc( T_REPEAT,   PrRepeat  );
}
/* 当前文件是D:\Read\string.c*/

TypHandle               HdChars [256];
TypHandle       EvChar ( hdChr )
TypHandle           hdChr;
{
return hdChr;
}
TypHandle       EqChar ( hdL, hdR )
TypHandle           hdL;
TypHandle           hdR;
{
if ( *(unsigned char*)PTR(hdL) == *(unsigned char*)PTR(hdR) )
return HdTrue;
else
return HdFalse;
}
TypHandle       LtChar ( hdL, hdR )
TypHandle           hdL;
TypHandle           hdR;
{
if ( *(unsigned char*)PTR(hdL) < *(unsigned char*)PTR(hdR) )
return HdTrue;
else
return HdFalse;
}
void            PrChar ( hdChr )
TypHandle           hdChr;
{
unsigned char       chr;
chr = *(unsigned char*)PTR(hdChr);
if      ( chr == '\n'  )  Pr("'\\n'",0L,0L);
else if ( chr == '\t'  )  Pr("'\\t'",0L,0L);
else if ( chr == '\r'  )  Pr("'\\r'",0L,0L);
else if ( chr == '\b'  )  Pr("'\\b'",0L,0L);
else if ( chr == '\03' )  Pr("'\\c'",0L,0L);
else if ( chr == '\''  )  Pr("'\\''",0L,0L);
else if ( chr == '\\'  )  Pr("'\\\\'",0L,0L);
else                      Pr("'%c'",(long)chr,0L);
}
long            LenString ( hdList )
TypHandle           hdList;
{
return LEN_STRING( hdList );
}
TypHandle       ElmString ( hdList, pos )
TypHandle           hdList;
long                pos;
{
if ( LEN_STRING( hdList ) < pos ) {
return Error(
"List Element: <list>[%d] must have a value",
pos, 0L );
}
return ELM_STRING( hdList, pos );
}
TypHandle       ElmfString ( hdList, pos )
TypHandle           hdList;
long                pos;
{
return ELM_STRING( hdList, pos );
}
TypHandle       ElmsString ( hdList, hdPoss )
TypHandle           hdList;
TypHandle           hdPoss;
{
TypHandle           hdElms;
long                lenList;
unsigned char       elm;
long                lenPoss;
long                pos;
long                inc;
long                i;
if ( TYPE(hdPoss) != T_RANGE ) {
lenList = LEN_PLIST( hdList );
lenPoss = LEN_LIST( hdPoss );
hdElms = NewBag( T_STRING, SIZE_PLEN_STRING( lenPoss ) );
for ( i = 1; i <= lenPoss; i++ ) {
pos = HD_TO_INT( ELMF_LIST( hdPoss, i ) );
if ( lenList < pos ) {
return Error(
"List Elements: <list>[%d] must have a value",
pos, 0L );
}
elm = ((unsigned char*)PTR(hdList))[pos-1];
((unsigned char*)PTR(hdElms))[i-1] = elm;
}
}
else {
lenList = LEN_PLIST( hdList );
lenPoss = LEN_RANGE( hdPoss );
pos = LOW_RANGE( hdPoss );
inc = INC_RANGE( hdPoss );
if ( lenList < pos ) {
return Error(
"List Elements: <list>[%d] must have a value",
pos, 0L );
}
if ( lenList < pos + (lenPoss-1) * inc ) {
return Error(
"List Elements: <list>[%d] must have a value",
pos + (lenPoss-1) * inc, 0L );
}
hdElms = NewBag( T_STRING, SIZE_PLEN_STRING( lenPoss ) );
for ( i = 1; i <= lenPoss; i++, pos += inc ) {
elm = ((unsigned char*)PTR(hdList))[pos-1];
((unsigned char*)PTR(hdElms))[i-1] = elm;
}
}
return hdElms;
}
TypHandle       AssString ( hdList, pos, hdVal )
TypHandle           hdList;
long                pos;
TypHandle           hdVal;
{
long                plen;
PLAIN_LIST( hdList );
Retype( hdList, T_LIST );
if ( LEN_PLIST(hdList) < pos ) {
plen = PLEN_SIZE_PLIST( SIZE(hdList) );
if ( plen + plen/8 + 4 < pos )
Resize( hdList, SIZE_PLEN_PLIST( pos ) );
else if ( plen < pos )
Resize( hdList, SIZE_PLEN_PLIST( plen + plen/8 + 4 ) );
SET_LEN_PLIST( hdList, pos );
}
SET_ELM_PLIST( hdList, pos, hdVal );
return hdVal;
}
TypHandle       AsssString ( hdList, hdPoss, hdVals )
TypHandle           hdList;
TypHandle           hdPoss;
TypHandle           hdVals;
{
PLAIN_LIST( hdList );
Retype( hdList, T_LIST );
return ASSS_LIST( hdList, hdPoss, hdVals );
}
long            PosString ( hdList, hdVal, start )
TypHandle           hdList;
TypHandle           hdVal;
long                start;
{
long                lenList;
TypHandle           hdElm;
long                i;
lenList = LEN_STRING( hdList );
for ( i = start+1; i <= lenList; i++ ) {
hdElm = ELML_LIST( hdList, i );
if ( hdElm != 0 && (hdElm == hdVal || EQ( hdElm, hdVal ) == HdTrue) )
break;
}
return (lenList < i ? 0 : i);
}
void            PlainString ( hdList )
TypHandle           hdList;
{
long                lenList;
TypHandle           hdCopy;
long                i;
lenList = LEN_STRING( hdList );
hdCopy = NewBag( T_LIST, SIZE_PLEN_PLIST( lenList ) );
SET_LEN_PLIST( hdCopy, lenList );
for ( i = 1; i <= lenList; i++ ) {
SET_ELM_PLIST( hdCopy, i, ELM_STRING( hdList, i ) );
}
Resize( hdList, SIZE_PLEN_PLIST( lenList ) );
Retype( hdList, T_LIST );
SET_LEN_PLIST( hdList, lenList );
for ( i = 1; i <= lenList; i++ ) {
SET_ELM_PLIST( hdList, i, ELM_PLIST( hdCopy, i ) );
}
}
long            IsDenseString ( hdList )
TypHandle           hdList;
{
return 1;
}
long            IsPossString ( hdList )
TypHandle           hdList;
{
return LEN_STRING( hdList ) == 0;
}
TypHandle       EqString ( hdL, hdR )
TypHandle           hdL;
TypHandle           hdR;
{
if ( SyStrcmp( (char*)PTR(hdL), (char*)PTR(hdR) ) == 0 )
return HdTrue;
return HdFalse;
}
TypHandle       LtString ( hdL, hdR )
TypHandle           hdL;
TypHandle           hdR;
{
if ( SyStrcmp( (char*)PTR(hdL), (char*)PTR(hdR) ) < 0 )
return HdTrue;
return HdFalse;
}
void            PrString ( hdStr )
TypHandle           hdStr;
{
char                * p;
Pr("\"",0L,0L);
for ( p = (char*)PTR(hdStr); *p != '\0'; ++p ) {
if      ( *p == '\n'  )  Pr("\\n",0L,0L);
else if ( *p == '\t'  )  Pr("\\t",0L,0L);
else if ( *p == '\r'  )  Pr("\\r",0L,0L);
else if ( *p == '\b'  )  Pr("\\b",0L,0L);
else if ( *p == '\03' )  Pr("\\c",0L,0L);
else if ( *p == '"'   )  Pr("\\\"",0L,0L);
else if ( *p == '\\'  )  Pr("\\\\",0L,0L);
else                     Pr("%c",(long)*p,0L);
}
Pr("\"",0L,0L);
}
void            PrintString ( hdStr )
TypHandle           hdStr;
{
Pr( "%s", (long)(char*)PTR(hdStr), 0L );
}
long            IsString ( hdList )
TypHandle           hdList;
{
long                isString;
long                lenList;
TypHandle           hdElm;
long                i;
if ( ! IS_LIST( hdList ) ) {
isString = 0;
}
else if ( TYPE(hdList) == T_STRING ) {
isString = 1;
}
else if ( LEN_LIST( hdList ) == 0 ) {
isString = 1;
}
else {
lenList = LEN_LIST( hdList );
for ( i = 1; i <= lenList; i++ ) {
hdElm = ELMF_LIST( hdList, i );
if ( hdElm == 0 || TYPE( hdElm ) != T_CHAR )
break;
}
isString = lenList < i;
if ( isString ) {
for ( i = 1; i <= lenList; i++ ) {
hdElm = ELMF_LIST( hdList, i );
((unsigned char*)PTR(hdList))[i-1] =
*((unsigned char*)PTR(hdElm));
}
((unsigned char*)PTR(hdList))[lenList] = '\0';
Retype( hdList, T_STRING );
Resize( hdList, SIZE_PLEN_STRING( lenList ) );
}
}
return isString;
}
TypHandle       FunIsString ( hdCall )
TypHandle           hdCall;
{
TypHandle           hdObj;
if ( SIZE(hdCall) != 2 * SIZE_HD )
return Error("usage: IsString( <obj> )",0L,0L);
hdObj = EVAL( PTR(hdCall)[1] );
if ( hdObj == HdVoid )
return Error("IsString: function must return a value",0L,0L);
if ( IsString( hdObj ) )
return HdTrue;
else
return HdFalse;
}
TypHandle       EvMakeString ( hdMake )
TypHandle           hdMake;
{
TypHandle           hdString;
hdString = NewBag( T_STRING, SIZE(hdMake) );
SyStrncat( (char*)PTR(hdString), (char*)PTR(hdMake), SIZE(hdMake)-1 );
return hdString;
}
void            InitString ()
{
long                i;
EvTab[T_CHAR] = EvChar;
PrTab[T_CHAR] = PrChar;
TabEq[T_CHAR][T_CHAR] = EqChar;
TabLt[T_CHAR][T_CHAR] = LtChar;
for ( i = 0; i < 256; i++ ) {
HdChars[i] = NewBag( T_CHAR, (size_t)1 );
*(unsigned char*)PTR(HdChars[i]) = (unsigned char)i;
}
TabIsList[T_STRING]       = 1;
TabLenList[T_STRING]      = LenString;
TabElmList[T_STRING]      = ElmString;
TabElmfList[T_STRING]     = ElmfString;
TabElmlList[T_STRING]     = ElmfString;
TabElmrList[T_STRING]     = ElmfString;
TabElmsList[T_STRING]     = ElmsString;
TabAssList[T_STRING]      = AssString;
TabAsssList[T_STRING]     = AsssString;
TabPosList[T_STRING]      = PosString;
TabPlainList[T_STRING]    = PlainString;
TabIsDenseList[T_STRING]  = IsDenseString;
TabIsPossList[T_STRING]   = IsPossString;
EvTab[T_STRING]           = EvList;
PrTab[T_STRING]           = PrString;
TabEq[T_STRING][T_STRING] = EqString;
TabLt[T_STRING][T_STRING] = LtString;
EvTab[T_MAKESTRING]       = EvMakeString;
PrTab[T_MAKESTRING]       = PrString;
InstIntFunc( "IsString",            FunIsString     );
}
/* 当前文件是D:\Read\system.c*/

#ifdef SYS_HAS_ANSI
# define SYS_ANSI       SYS_HAS_ANSI
#else
# ifdef __STDC__
#  define SYS_ANSI      1
# else
#  define SYS_ANSI      0
# endif
#endif
#ifdef SYS_HAS_CONST
# define SYS_CONST      SYS_HAS_CONST
#else
# ifdef __STDC__
#  define SYS_CONST     const
# else
#  define SYS_CONST
# endif
#endif
#ifdef SYS_HAS_SIZE_T
typedef size_t int
#endif

long            SyStrlen ( str )
char *              str;
{
return strlen( str );
}
long            SyStrcmp ( str1, str2 )
char *              str1;
char *              str2;
{
return strcmp( str1, str2 );
}
#ifdef SYS_HAS_BROKEN_STRNCAT
char *          SyStrncat ( dst, src, len )
char *              dst;
char *              src;
long                len;
{
char *              p;
char *              q;
for ( p = dst;  *p;  p++ )
;
for ( q = src;  *q && 0 < len;  len-- )
*p++ = *q++;
*p = 0;
return dst;
}
#else
char *          SyStrncat ( dst, src, len )
char *              dst;
char *              src;
long                len;
{
return strncat( dst, src, len );
}
#endif
#ifndef SYS_STDIO_H
# include       <stdio.h>
# define SYS_STDIO_H
#endif
#ifndef SYS_HAS_STDIO_PROTO





#endif
struct {
FILE *      fp;
FILE *      echo;
char        buf [BUFSIZ];
}       syBuf [16];
long            SyFopen ( name, mode )
char *              name;
char *              mode;
{
long                fid;
if ( SyStrcmp( name, "*stdin*" ) == 0 ) {
if ( SyStrcmp( mode, "r" ) != 0 )  return -1;
return 0;
}
else if ( SyStrcmp( name, "*stdout*" ) == 0 ) {
if ( SyStrcmp( mode, "w" ) != 0 )  return -1;
return 1;
}
else if ( SyStrcmp( name, "*errin*" ) == 0 ) {
if ( SyStrcmp( mode, "r" ) != 0 )  return -1;
if ( syBuf[2].fp == (FILE*)0 )  return -1;
return 2;
}
else if ( SyStrcmp( name, "*errout*" ) == 0 ) {
if ( SyStrcmp( mode, "w" ) != 0 )  return -1;
return 3;
}
for ( fid = 4; fid < sizeof(syBuf)/sizeof(syBuf[0]); ++fid )
if ( syBuf[fid].fp == (FILE*)0 )  break;
if ( fid == sizeof(syBuf)/sizeof(syBuf[0]) )
return (long)-1;
syBuf[fid].fp = fopen( name, mode );
if ( syBuf[fid].fp == (FILE*)0 )
return (long)-1;
setbuf( syBuf[fid].fp, syBuf[fid].buf );
return fid;
}
void            SyFclose ( fid )
long                fid;
{
if ( syBuf[fid].fp == (FILE*)0 ) {
fputs("gap: panic 'SyFclose' asked to close closed file!\n",stderr);
SyExit( 1 );
}
if ( fid == 0 || fid == 1 || fid == 2 || fid == 3 ) {
return;
}
if ( fclose( syBuf[fid].fp ) == EOF ) {
fputs("gap: 'SyFclose' cannot close file, ",stderr);
fputs("maybe your file system is full?\n",stderr);
}
syBuf[fid].fp = (FILE*)0;
}



#if SYS_MAC_SYC

#endif





long            syLineEdit = 1;
long            syCTRD = 1;
long            syNrchar;
char            syPrompt [256];
char            syHistory [8192];
char *          syHi = syHistory;
int             syCTRO;
#define CTR(C)          ((C) & 0x1F)
#define ESC(C)          ((C) | 0x100)
#define CTV(C)          ((C) | 0x200)
#define IS_SEP(C)       (!IsAlpha(C) && !IsDigit(C) && (C)!='_')
char *          SyFgets ( line, length, fid )
char                line [];
long                length;
long                fid;
{
int                 ch,  ch2,  ch3, last;
char                * p,  * q,  * r,  * s,  * t;
char                * h;
static char         yank [512];
char                old [512],  new [512];
int                 oldc,  newc;
int                 rep;
char                buffer [512];
int                 rn;
if ( fid != 0 && fid != 2 ) {
p = fgets( line, (int)length, syBuf[fid].fp );
return p;
}
if ( syLineEdit == 0 ) {
syStopTime = SyTime();
p = fgets( line, (int)length, syBuf[fid].fp );
syStartTime += SyTime() - syStopTime;
return p;
}
if ( syLineEdit == 1 && ! syStartraw(fid) ) {
syStopTime = SyTime();
p = fgets( line, (int)length, syBuf[fid].fp );
syStartTime += SyTime() - syStopTime;
return p;
}
syStopTime = SyTime();
line[0] = '\0';  p = line;  h = syHistory;
for ( q = old; q < old+sizeof(old); ++q )  *q = ' ';
oldc = 0;
last = 0;
while ( 1 ) {
rep = 1;  ch2 = 0;
do {
if ( syCTRO % 2 == 1  )  { ch = CTR('N'); syCTRO = syCTRO - 1; }
else if ( syCTRO != 0 )  { ch = CTR('O'); rep = syCTRO / 2; }
#if ! SYS_MAC_SYC
else ch = syGetch(fid);
#endif
#if SYS_MAC_SYC
else ch = syGetch2(fid,*p);
#endif
if ( ch2==0        && ch==CTR('V') ) {             ch2=ch; ch=0;}
if ( ch2==0        && ch==CTR('[') ) {             ch2=ch; ch=0;}
if ( ch2==0        && ch==CTR('U') ) {             ch2=ch; ch=0;}
if ( ch2==CTR('[') && ch==CTR('V') ) { ch2=ESC(CTR('V'));  ch=0;}
if ( ch2==CTR('[') && isdigit(ch)  ) { rep=ch-'0'; ch2=ch; ch=0;}
if ( ch2==CTR('[') && ch=='['      ) {             ch2=ch; ch=0;}
if ( ch2==CTR('U') && ch==CTR('V') ) { rep=4*rep;  ch2=ch; ch=0;}
if ( ch2==CTR('U') && ch==CTR('[') ) { rep=4*rep;  ch2=ch; ch=0;}
if ( ch2==CTR('U') && ch==CTR('U') ) { rep=4*rep;  ch2=ch; ch=0;}
if ( ch2==CTR('U') && isdigit(ch)  ) { rep=ch-'0'; ch2=ch; ch=0;}
if ( isdigit(ch2)  && ch==CTR('V') ) {             ch2=ch; ch=0;}
if ( isdigit(ch2)  && ch==CTR('[') ) {             ch2=ch; ch=0;}
if ( isdigit(ch2)  && ch==CTR('U') ) {             ch2=ch; ch=0;}
if ( isdigit(ch2)  && isdigit(ch)  ) { rep=10*rep+ch-'0';  ch=0;}
} while ( ch == 0 );
if ( ch2==CTR('V') )       ch  = CTV(ch);
if ( ch2==ESC(CTR('V')) )  ch  = CTV(ch | 0x80);
if ( ch2==CTR('[') )       ch  = ESC(ch);
if ( ch2==CTR('U') )       rep = 4*rep;
if ( ch2=='[' && ch=='A')  ch  = CTR('P');
if ( ch2=='[' && ch=='B')  ch  = CTR('N');
if ( ch2=='[' && ch=='C')  ch  = CTR('F');
if ( ch2=='[' && ch=='D')  ch  = CTR('B');
while ( rep-- > 0 ) {
switch ( ch ) {
case CTR('A'):
while ( p > line )  --p;
break;
case ESC('B'):
case ESC('b'):
if ( p > line ) do {
--p;
} while ( p>line && (!IS_SEP(*(p-1)) || IS_SEP(*p)));
break;
case CTR('B'):
if ( p > line )  --p;
break;
case CTR('F'):
if ( *p != '\0' )  ++p;
break;
case ESC('F'):
case ESC('f'):
if ( *p != '\0' ) do {
++p;
} while ( *p!='\0' && (IS_SEP(*(p-1)) || !IS_SEP(*p)));
break;
case CTR('E'):
while ( *p != '\0' )  ++p;
break;
case CTR('H'):
case 127:
if ( p == line ) break;
--p;
case CTR('D'):
if ( p == line && *p == '\0' && syCTRD ) {
ch = EOF; rep = 0; break;
}
if ( *p != '\0' ) {
for ( q = p; *(q+1) != '\0'; ++q )
*q = *(q+1);
*q = '\0';
}
break;
case CTR('X'):
p = line;
case CTR('K'):
if ( last!=CTR('X') && last!=CTR('K') && last!=ESC(127)
&& last!=ESC('D') && last!=ESC('d') )  yank[0] = '\0';
for ( r = yank; *r != '\0'; ++r ) ;
for ( s = p; *s != '\0'; ++s )  r[s-p] = *s;
r[s-p] = '\0';
*p = '\0';
break;
case ESC(127):
q = p;
if ( p > line ) do {
--p;
} while ( p>line && (!IS_SEP(*(p-1)) || IS_SEP(*p)));
if ( last!=CTR('X') && last!=CTR('K') && last!=ESC(127)
&& last!=ESC('D') && last!=ESC('d') )  yank[0] = '\0';
for ( r = yank; *r != '\0'; ++r ) ;
for ( ; yank <= r; --r )  r[q-p] = *r;
for ( s = p; s < q; ++s )  yank[s-p] = *s;
for ( r = p; *q != '\0'; ++q, ++r )
*r = *q;
*r = '\0';
break;
case ESC('D'):
case ESC('d'):
q = p;
if ( *q != '\0' ) do {
++q;
} while ( *q!='\0' && (IS_SEP(*(q-1)) || !IS_SEP(*q)));
if ( last!=CTR('X') && last!=CTR('K') && last!=ESC(127)
&& last!=ESC('D') && last!=ESC('d') )  yank[0] = '\0';
for ( r = yank; *r != '\0'; ++r ) ;
for ( s = p; s < q; ++s )  r[s-p] = *s;
r[s-p] = '\0';
for ( r = p; *q != '\0'; ++q, ++r )
*r = *q;
*r = '\0';
break;
case CTR('T'):
if ( p == line )  break;
if ( *p == '\0' )  --p;
if ( p == line )  break;
ch2 = *(p-1);  *(p-1) = *p;  *p = ch2;
++p;
break;
case CTR('L'):
for ( r = syHistory; *r != '\0' && *r != '\n'; ++r ) {
ch2 = *r;
for ( q = p; ch2; ++q ) {
ch3 = *q; *q = ch2; ch2 = ch3;
}
*q = '\0'; ++p;
}
break;
case CTR('Y'):
for ( r = yank; *r != '\0' && *r != '\n'; ++r ) {
ch2 = *r;
for ( q = p; ch2; ++q ) {
ch3 = *q; *q = ch2; ch2 = ch3;
}
*q = '\0'; ++p;
}
break;
case CTR('P'):
while ( *h != '\0' ) {
for ( q = line; q < p; ++q )
if ( *q != h[q-line] )  break;
if ( q == p )  break;
while ( *h != '\n' && *h != '\0' )  ++h;
if ( *h == '\n' ) ++h;
}
q = p;
while ( *h!='\0' && h[q-line]!='\n' && h[q-line]!='\0' ) {
*q = h[q-line];  ++q;
}
*q = '\0';
while ( *h != '\0' && *h != '\n' )  ++h;
if ( *h == '\n' ) ++h;  else h = syHistory;
syHi = h;
break;
case CTR('N'):
h = syHi;
if ( h > syHistory ) {
do {--h;} while (h>syHistory && *(h-1)!='\n');
if ( h==syHistory )  while ( *h != '\0' ) ++h;
}
while ( *h != '\0' ) {
if ( h==syHistory )  while ( *h != '\0' ) ++h;
do {--h;} while (h>syHistory && *(h-1)!='\n');
for ( q = line; q < p; ++q )
if ( *q != h[q-line] )  break;
if ( q == p )  break;
if ( h==syHistory )  while ( *h != '\0' ) ++h;
}
q = p;
while ( *h!='\0' && h[q-line]!='\n' && h[q-line]!='\0' ) {
*q = h[q-line];  ++q;
}
*q = '\0';
while ( *h != '\0' && *h != '\n' )  ++h;
if ( *h == '\n' ) ++h;  else h = syHistory;
syHi = h;
break;
case ESC('<'):
while ( *h != '\0' ) ++h;
do {--h;} while (h>syHistory && *(h-1)!='\n');
q = p = line;
while ( *h!='\0' && h[q-line]!='\n' && h[q-line]!='\0' ) {
*q = h[q-line];  ++q;
}
*q = '\0';
while ( *h != '\0' && *h != '\n' )  ++h;
if ( *h == '\n' ) ++h;  else h = syHistory;
syHi = h;
break;
case ESC('>'):
h = syHistory;
p = line;
*p = '\0';
syHi = h;
break;
case CTR('S'):
if ( *p != '\0' ) {
ch2 = syGetch(fid);
q = p+1;
while ( *q != '\0' && *q != ch2 )  ++q;
if ( *q == ch2 )  p = q;
}
break;
case CTR('R'):
if ( p > line ) {
ch2 = syGetch(fid);
q = p-1;
while ( q > line && *q != ch2 )  --q;
if ( *q == ch2 )  p = q;
}
break;
case ESC('U'):
case ESC('u'):
if ( *p != '\0' ) do {
if ('a' <= *p && *p <= 'z')  *p = *p + 'A' - 'a';
++p;
} while ( *p!='\0' && (IS_SEP(*(p-1)) || !IS_SEP(*p)));
break;
case ESC('C'):
case ESC('c'):
while ( *p!='\0' && IS_SEP(*p) )  ++p;
if ( 'a' <= *p && *p <= 'z' )  *p = *p + 'A'-'a';
if ( *p != '\0' ) ++p;
case ESC('L'):
case ESC('l'):
if ( *p != '\0' ) do {
if ('A' <= *p && *p <= 'Z')  *p = *p + 'a' - 'A';
++p;
} while ( *p!='\0' && (IS_SEP(*(p-1)) || !IS_SEP(*p)));
break;
case ESC(CTR('L')):
syEchoch('\n',fid);
for ( q = syPrompt; q < syPrompt+syNrchar; ++q )
syEchoch( *q, fid );
for ( q = old; q < old+sizeof(old); ++q )  *q = ' ';
oldc = 0;
break;
case EOF:
break;
case CTR('M'):
case CTR('J'):
while ( *p != '\0' )  ++p;
*p++ = '\n'; *p = '\0';
rep = 0;
break;
case CTR('O'):
while ( *p != '\0' )  ++p;
*p++ = '\n'; *p = '\0';
syCTRO = 2 * rep + 1;
rep = 0;
break;
case CTR('I'):
if ( p == line || IS_SEP(p[-1]) ) {
ch2 = ch & 0xff;
for ( q = p; ch2; ++q ) {
ch3 = *q; *q = ch2; ch2 = ch3;
}
*q = '\0'; ++p;
}
else {
if ( (q = p) > line ) do {
--q;
} while ( q>line && (!IS_SEP(*(q-1)) || IS_SEP(*q)));
rn = (line < q && *(q-1) == '.');
r = buffer;  s = q;
while ( s < p )  *r++ = *s++;
*r = '\0';
if ( iscomplete( buffer, p-q, rn ) ) {
if ( last != CTR('I') )
syEchoch( CTR('G'), fid );
else {
syWinPut( fid, "@c", "" );
syEchos( "\n    ", fid );
syEchos( buffer, fid );
while ( completion( buffer, p-q, rn ) ) {
syEchos( "\n    ", fid );
syEchos( buffer, fid );
}
syEchos( "\n", fid );
for ( q=syPrompt; q<syPrompt+syNrchar; ++q )
syEchoch( *q, fid );
for ( q = old; q < old+sizeof(old); ++q )
*q = ' ';
oldc = 0;
syWinPut( fid, (fid == 0 ? "@i" : "@e"), "" );
}
}
else if ( ! completion( buffer, p-q, rn ) ) {
if ( last != CTR('I') )
syEchoch( CTR('G'), fid );
else {
syWinPut( fid, "@c", "" );
syEchos("\n    identifier has no completions\n",
fid);
for ( q=syPrompt; q<syPrompt+syNrchar; ++q )
syEchoch( *q, fid );
for ( q = old; q < old+sizeof(old); ++q )
*q = ' ';
oldc = 0;
syWinPut( fid, (fid == 0 ? "@i" : "@e"), "" );
}
}
else {
t = p;
for ( s = buffer+(p-q); *s != '\0'; s++ ) {
ch2 = *s;
for ( r = p; ch2; r++ ) {
ch3 = *r; *r = ch2; ch2 = ch3;
}
*r = '\0'; p++;
}
while ( t < p && completion( buffer, t-q, rn ) ) {
r = t;  s = buffer+(t-q);
while ( r < p && *r == *s ) {
r++; s++;
}
s = p;  p = r;
while ( *s != '\0' )  *r++ = *s++;
*r = '\0';
}
if ( t == p ) {
if ( last != CTR('I') )
syEchoch( CTR('G'), fid );
else {
syWinPut( fid, "@c", "" );
buffer[t-q] = '\0';
while ( completion( buffer, t-q, rn ) ) {
syEchos( "\n    ", fid );
syEchos( buffer, fid );
}
syEchos( "\n", fid );
for ( q=syPrompt; q<syPrompt+syNrchar; ++q )
syEchoch( *q, fid );
for ( q = old; q < old+sizeof(old); ++q )
*q = ' ';
oldc = 0;
syWinPut( fid, (fid == 0 ? "@i" : "@e"), "");
}
}
}
}
break;
default:
ch2 = ch & 0xff;
for ( q = p; ch2; ++q ) {
ch3 = *q; *q = ch2; ch2 = ch3;
}
*q = '\0'; ++p;
break;
}
last = ch;
}
if ( ch==EOF || ch=='\n' || ch=='\r' || ch==CTR('O') ) {
syEchoch('\r',fid);  syEchoch('\n',fid);  break;
}
for ( q = line, r = new, newc = 0; *q != '\0'; ++q ) {
if ( q == p )  newc = r-new;
if ( *q==CTR('I') )  { do *r++=' '; while ((r-new+syNrchar)%8); }
else if ( *q==0x7F ) { *r++ = '^'; *r++ = '?'; }
else if ( '\0'<=*q && *q<' '  ) { *r++ = '^'; *r++ = *q+'@'; }
else if ( ' ' <=*q && *q<0x7F ) { *r++ = *q; }
else {
*r++ = '\\';                   *r++ = '0'+(unsigned)*q/64%4;
*r++ = '0'+(unsigned)*q/8 %8;  *r++ = '0'+(unsigned)*q   %8;
}
if ( r >= new+SyNrCols-syNrchar-2 ) {
if ( q >= p ) { q++; break; }
new[0] = '$';   new[1] = r[-5]; new[2] = r[-4];
new[3] = r[-3]; new[4] = r[-2]; new[5] = r[-1];
r = new+6;
}
}
if ( q == p )  newc = r-new;
for (      ; r < new+sizeof(new); ++r )  *r = ' ';
if ( q[0] != '\0' && q[1] != '\0' )
new[SyNrCols-syNrchar-2] = '$';
else if ( q[1] == '\0' && ' ' <= *q && *q < 0x7F )
new[SyNrCols-syNrchar-2] = *q;
else if ( q[1] == '\0' && q[0] != '\0' )
new[SyNrCols-syNrchar-2] = '$';
for ( q = old, r = new; r < new+sizeof(new); ++r, ++q ) {
if ( *q == *r )  continue;
while (oldc<(q-old)) { syEchoch(old[oldc],fid);  ++oldc; }
while (oldc>(q-old)) { syEchoch('\b',fid);       --oldc; }
*q = *r;  syEchoch( *q, fid ); ++oldc;
}
while ( oldc < newc ) { syEchoch(old[oldc],fid);  ++oldc; }
while ( oldc > newc ) { syEchoch('\b',fid);       --oldc; }
}
for ( q = syHistory+sizeof(syHistory)-3; q >= syHistory+(p-line); --q )
*q = *(q-(p-line));
for ( p = line, q = syHistory; *p != '\0'; ++p, ++q )
*q = *p;
syHistory[sizeof(syHistory)-3] = '\n';
if ( syHi != syHistory )
syHi = syHi + (p-line);
if ( syHi > syHistory+sizeof(syHistory)-2 )
syHi = syHistory+sizeof(syHistory)-2;
syWinPut( fid, (*line != '\0' ? "@r" : "@x"), line );
if (line[0]=='g'&&line[1]=='a'&&line[2]=='p'&&line[3]=='>'&&line[4]==' ')
for ( p = line, q = line+5; q[-1] != '\0'; p++, q++ )  *p = *q;
if (line[0]=='b'&&line[1]=='r'&&line[2]=='k'&&line[3]=='>'&&line[4]==' ')
for ( p = line, q = line+5; q[-1] != '\0'; p++, q++ )  *p = *q;
if (line[0]=='>'&&line[1]==' ')
for ( p = line, q = line+2; q[-1] != '\0'; p++, q++ )  *p = *q;
if ( syLineEdit == 1 )
syStopraw(fid);
syStartTime += SyTime() - syStopTime;
if ( *line == '\0' )
return (char*)0;
return line;
}
#if SYS_BSD || SYS_MACH
#ifndef SYS_SGTTY_H
# include       <sgtty.h>
# define SYS_SGTTY_H
#endif
#ifndef SYS_HAS_IOCTL_PROTO

#endif
struct sgttyb   syOld, syNew;
struct tchars   syOldT, syNewT;
#ifndef SYS_SIGNAL_H
# include       <signal.h>
# ifdef SYS_HAS_SIG_T
#  define SYS_SIG_T     SYS_HAS_SIG_T
# else
#  define SYS_SIG_T     void
# endif
# define SYS_SIGNAL_H
typedef SYS_SIG_T       sig_handler_t P(( int ));
#endif
#ifndef SYS_HAS_SIGNAL_PROTO



#endif
#ifndef SYS_HAS_READ_PROTO


#endif
#ifdef SIGTSTP
long            syFid;
SYS_SIG_T       syAnswerCont ( signr )
int                 signr;
{
syStartraw( syFid );
signal( SIGCONT, SIG_DFL );
kill( getpid(), SIGCONT );
#ifdef SYS_HAS_SIG_T
return 0;
#endif
}
SYS_SIG_T       syAnswerTstp ( signr )
int                 signr;
{
syStopraw( syFid );
signal( SIGCONT, syAnswerCont );
kill( getpid(), SIGTSTP );
#ifdef SYS_HAS_SIG_T
return 0;
#endif
}
#endif
int             syStartraw ( fid )
long                fid;
{
if ( syWindow ) {
if      ( fid == 0 ) { syWinPut( fid, "@i", "" );  return 1; }
else if ( fid == 2 ) { syWinPut( fid, "@e", "" );  return 1; }
else {                                             return 0; }
}
if ( ioctl( fileno(syBuf[fid].fp), TIOCGETP, (char*)&syOld ) == -1 )
return 0;
if ( ioctl( fileno(syBuf[fid].fp), TIOCGETC, (char*)&syOldT ) == -1 )
return 0;
syNewT = syOldT;
syNewT.t_intrc  = -1;
syNewT.t_quitc  = -1;
if ( ioctl( fileno(syBuf[fid].fp), TIOCSETC, (char*)&syNewT ) == -1 )
return 0;
syNew = syOld;
syNew.sg_flags |= CBREAK;
syNew.sg_flags &= ~ECHO;
if ( ioctl( fileno(syBuf[fid].fp), TIOCSETN, (char*)&syNew ) == -1 )
return 0;
#ifdef SIGTSTP
syFid = fid;
signal( SIGTSTP, syAnswerTstp );
#endif
return 1;
}
void            syStopraw ( fid )
long                fid;
{
if ( syWindow )
return;
#ifdef SIGTSTP
signal( SIGTSTP, SIG_DFL );
#endif
if ( ioctl( fileno(syBuf[fid].fp), TIOCSETN, (char*)&syOld ) == -1 )
fputs("gap: 'ioctl' could not turn off raw mode!\n",stderr);
if ( ioctl( fileno(syBuf[fid].fp), TIOCSETC, (char*)&syOldT ) == -1 )
fputs("gap: 'ioctl' could not turn off raw mode!\n",stderr);
}
int             syGetch ( fid )
long                fid;
{
char                ch;
while ( read( fileno(syBuf[fid].fp), &ch, 1 ) != 1 || ch == '\0' )
;
if ( syWindow && ch == '@' ) {
do {
while ( read(fileno(syBuf[fid].fp), &ch, 1) != 1 || ch == '\0' )
;
} while ( ch < '@' || 'z' < ch );
if ( ch == 'y' ) {
syWinPut( fileno(syBuf[fid].echo), "@s", "" );
ch = syGetch(fid);
}
else if ( 'A' <= ch && ch <= 'Z' )
ch = CTR(ch);
}
return ch;
}
void            syEchoch ( ch, fid )
int                 ch;
long                fid;
{
char                ch2;
ch2 = ch;
write( fileno(syBuf[fid].echo), (char*)&ch2, 1 );
if ( syWindow && ch == '@' ) {
ch2 = ch;
write( fileno(syBuf[fid].echo), (char*)&ch2, 1 );
}
}
void            syEchos ( str, fid )
char *              str;
long                fid;
{
if ( syWindow && fid < 4 )
syWinPut( fid, (fid == 1 ? "@n" : "@f"), str );
else
write( fileno(syBuf[fid].echo), str, SyStrlen(str) );
}
#endif
#if SYS_USG
#ifndef SYS_TERMIO_H
# include       <termio.h>
# define SYS_TERMIO_H
#endif
#ifndef SYS_HAS_IOCTL_PROTO

#endif
struct termio   syOld, syNew;
#ifndef SYS_SIGNAL_H
# include       <signal.h>
# ifdef SYS_HAS_SIG_T
#  define SYS_SIG_T     SYS_HAS_SIG_T
# else
#  define SYS_SIG_T     void
# endif
# define SYS_SIGNAL_H
typedef SYS_SIG_T       sig_handler_t P(( int ));
#endif
#ifndef SYS_HAS_SIGNAL_PROTO



#endif
#ifndef SYS_HAS_READ_PROTO


#endif
#ifdef SIGTSTP
long            syFid;
SYS_SIG_T       syAnswerCont ( signr )
int                 signr;
{
syStartraw( syFid );
signal( SIGCONT, SIG_DFL );
kill( getpid(), SIGCONT );
#ifdef SYS_HAS_SIG_T
return 0;
#endif
}
SYS_SIG_T       syAnswerTstp ( signr )
int                 signr;
{
syStopraw( syFid );
signal( SIGCONT, syAnswerCont );
kill( getpid(), SIGTSTP );
#ifdef SYS_HAS_SIG_T
return 0;
#endif
}
#endif
int             syStartraw ( fid )
long                fid;
{
if ( syWindow ) {
if      ( fid == 0 ) { syWinPut( fid, "@i", "" );  return 1; }
else if ( fid == 2 ) { syWinPut( fid, "@e", "" );  return 1; }
else {                                             return 0; }
}
if ( ioctl( fileno(syBuf[fid].fp), TCGETA, &syOld ) == -1 )   return 0;
syNew = syOld;
syNew.c_cc[VINTR] = 0377;
syNew.c_cc[VQUIT] = 0377;
syNew.c_iflag    &= ~(INLCR|ICRNL);
syNew.c_cc[VMIN]  = 1;
syNew.c_cc[VTIME] = 0;
syNew.c_lflag    &= ~(ECHO|ICANON);
if ( ioctl( fileno(syBuf[fid].fp), TCSETAW, &syNew ) == -1 )  return 0;
#ifdef SIGTSTP
syFid = fid;
signal( SIGTSTP, syAnswerTstp );
#endif
return 1;
}
void            syStopraw ( fid )
long                fid;
{
if ( syWindow )
return;
#ifdef SIGTSTP
signal( SIGTSTP, SIG_DFL );
#endif
if ( ioctl( fileno(syBuf[fid].fp), TCSETAW, &syOld ) == -1 )
fputs("gap: 'ioctl' could not turn off raw mode!\n",stderr);
}
int             syGetch ( fid )
long                fid;
{
char                ch;
while ( read( fileno(syBuf[fid].fp), &ch, 1 ) != 1 || ch == '\0' )
;
if ( syWindow && ch == '@' ) {
do {
while ( read(fileno(syBuf[fid].fp), &ch, 1) != 1 || ch == '\0' )
;
} while ( ch < '@' || 'z' < ch );
if ( ch == 'y' ) {
syWinPut( fileno(syBuf[fid].echo), "@s", "" );
ch = syGetch(fid);
}
else if ( 'A' <= ch && ch <= 'Z' )
ch = CTR(ch);
}
return ch;
}
void            syEchoch ( ch, fid )
int                 ch;
long                fid;
{
char                ch2;
ch2 = ch;
write( fileno(syBuf[fid].echo), (char*)&ch2, 1 );
if ( syWindow && ch == '@' ) {
ch2 = ch;
write( fileno(syBuf[fid].echo), (char*)&ch2, 1 );
}
}
void            syEchos ( str, fid )
char *              str;
long                fid;
{
if ( syWindow && fid < 4 )
syWinPut( fid, (fid == 1 ? "@n" : "@f"), str );
else
write( fileno(syBuf[fid].echo), str, SyStrlen(str) );
}
#endif
#if SYS_OS2_EMX
#ifndef SYS_TERMIO_H
# include       <termio.h>
# define SYS_TERMIO_H
#endif
#ifndef SYS_HAS_IOCTL_PROTO

#endif
struct termio   syOld, syNew;
#ifndef SYS_SIGNAL_H
# include       <signal.h>
# ifdef SYS_HAS_SIG_T
#  define SYS_SIG_T     SYS_HAS_SIG_T
# else
#  define SYS_SIG_T     void
# endif
# define SYS_SIGNAL_H
typedef SYS_SIG_T       sig_handler_t P(( int ));
#endif
#ifndef SYS_HAS_SIGNAL_PROTO



#endif
#ifndef SYS_HAS_READ_PROTO


#endif
#ifdef SIGTSTP
long            syFid;
SYS_SIG_T       syAnswerCont ( signr )
int                 signr;
{
syStartraw( syFid );
signal( SIGCONT, SIG_DFL );
kill( getpid(), SIGCONT );
#ifdef SYS_HAS_SIG_T
return 0;
#endif
}
SYS_SIG_T       syAnswerTstp ( signr )
int                 signr;
{
syStopraw( syFid );
signal( SIGCONT, syAnswerCont );
kill( getpid(), SIGTSTP );
#ifdef SYS_HAS_SIG_T
return 0;
#endif
}
#endif
int             syStartraw ( fid )
long                fid;
{
if ( syWindow ) {
if      ( fid == 0 ) { syWinPut( fid, "@i", "" );  return 1; }
else if ( fid == 2 ) { syWinPut( fid, "@e", "" );  return 1; }
else {                                             return 0; }
}
if ( ioctl( fileno(syBuf[fid].fp), TCGETA, &syOld ) == -1 )   return 0;
syNew = syOld;
syNew.c_cc[VINTR] = 0377;
syNew.c_cc[VQUIT] = 0377;
syNew.c_iflag    &= ~(INLCR|ICRNL);
syNew.c_cc[VMIN]  = 1;
syNew.c_cc[VTIME] = 0;
syNew.c_lflag    &= ~(ECHO|ICANON|IDEFAULT);
if ( ioctl( fileno(syBuf[fid].fp), TCSETAW, &syNew ) == -1 )  return 0;
#ifdef SIGTSTP
syFid = fid;
signal( SIGTSTP, syAnswerTstp );
#endif
return 1;
}
void            syStopraw ( fid )
long                fid;
{
if ( syWindow )
return;
#ifdef SIGTSTP
signal( SIGTSTP, SIG_DFL );
#endif
if ( ioctl( fileno(syBuf[fid].fp), TCSETAW, &syOld ) == -1 )
fputs("gap: 'ioctl' could not turn off raw mode!\n",stderr);
}
#ifndef SYS_KBD_H
# include       <sys/kbdscan.h>
# define SYS_KBD_H
#endif
int             syGetch ( fid )
long                fid;
{
unsigned char       ch;
int                 ch2;
syGetchAgain:
while ( read( fileno(syBuf[fid].fp), &ch, 1 ) != 1 )
;
if ( syWindow && ch == '@' ) {
do {
while ( read(fileno(syBuf[fid].fp), &ch, 1) != 1 )
;
} while ( ch < '@' || 'z' < ch );
if ( ch == 'y' ) {
syWinPut( fileno(syBuf[fid].echo), "@s", "" );
ch = syGetch(fid);
}
else if ( 'A' <= ch && ch <= 'Z' )
ch = CTR(ch);
}
ch2 = ch;
if ( ch == '\0' ) {
while ( read( fileno(syBuf[fid].fp), &ch, 1 ) != 1 )
;
switch ( ch ) {
case K_LEFT:            ch2 = CTR('B');  break;
case K_RIGHT:           ch2 = CTR('F');  break;
case K_UP:
case K_PAGEUP:          ch2 = CTR('P');  break;
case K_DOWN:
case K_PAGEDOWN:        ch2 = CTR('N');  break;
case K_DEL:             ch2 = CTR('D');  break;
case K_HOME:            ch2 = CTR('A');  break;
case K_END:             ch2 = CTR('E');  break;
case K_CTRL_END:        ch2 = CTR('K');  break;
case K_CTRL_LEFT:
case K_ALT_B:           ch2 = ESC('B');  break;
case K_CTRL_RIGHT:
case K_ALT_F:           ch2 = ESC('F');  break;
case K_ALT_D:           ch2 = ESC('D');  break;
case K_ALT_DEL:
case K_ALT_BACKSPACE:   ch2 = ESC(127);  break;
case K_ALT_U:           ch2 = ESC('U');  break;
case K_ALT_L:           ch2 = ESC('L');  break;
case K_ALT_C:           ch2 = ESC('C');  break;
case K_CTRL_PAGEUP:     ch2 = ESC('<');  break;
case K_CTRL_PAGEDOWN:   ch2 = ESC('>');  break;
default:                goto syGetchAgain;
}
}
return ch2;
}
void            syEchoch ( ch, fid )
int                 ch;
long                fid;
{
char                ch2;
ch2 = ch;
write( fileno(syBuf[fid].echo), (char*)&ch2, 1 );
if ( syWindow && ch == '@' ) {
ch2 = ch;
write( fileno(syBuf[fid].echo), (char*)&ch2, 1 );
}
}
void            syEchos ( str, fid )
char *              str;
long                fid;
{
if ( syWindow && fid < 4 )
syWinPut( fid, (fid == 1 ? "@n" : "@f"), str );
else
write( fileno(syBuf[fid].echo), str, SyStrlen(str) );
}
#endif
#if _WIN32
# define GETKEY()       getchar()
# define PUTCHAR(C)     putchar(C)
# define KBHIT()        kbhit()
unsigned long   syStopout;
char            syTypeahead [256];
char            syAltMap [35] = "QWERTYUIOP    ASDFGHJKL     ZXCVBNM";
int             syStartraw ( fid )
long                fid;
{
if ( ! isatty( fileno(syBuf[fid].fp) ) )
return 0;
return 1;
}
void            syStopraw ( fid )
long                fid;
{
}
int             syGetch ( fid )
long                fid;
{
int                 ch;
if ( syTypeahead[0] != '\0' ) {
ch = syTypeahead[0];
strcpy( syTypeahead, syTypeahead+1 );
}
else {
ch = GETKEY();
}
if ( 0x110 <= ch && ch <= 0x132 )   ch = ESC( syAltMap[ch-0x110] );
else if ( ch == 0x147 )             ch = CTR('A');
else if ( ch == 0x14f )             ch = CTR('E');
else if ( ch == 0x148 )             ch = CTR('P');
else if ( ch == 0x14b )             ch = CTR('B');
else if ( ch == 0x14d )             ch = CTR('F');
else if ( ch == 0x150 )             ch = CTR('N');
else if ( ch == 0x153 )             ch = CTR('D');
else                                ch &= 0xFF;
return ch;
}
void            syEchoch ( ch, fid )
int                 ch;
long                fid;
{
PUTCHAR( ch );
}
void            syEchos ( str, fid )
char *              str;
long                fid;
{
char *              s;
while ( syStopout )  syStopout = (GETKEY() == CTR('S'));
for ( s = str; *s != '\0'; s++ )
PUTCHAR( *s );
}
#endif
#if SYS_MSDOS_DJGPP
#ifndef SYS_KBD_H
# include       <pc.h>
# define GETKEY()       getkey()
# define PUTCHAR(C)     putchar(C)
# define KBHIT()        kbhit()
# define SYS_KBD_H
#endif
unsigned long   syStopout;
char            syTypeahead [256];
char            syAltMap [35] = "QWERTYUIOP    ASDFGHJKL     ZXCVBNM";
int             syStartraw ( fid )
long                fid;
{
if ( ! isatty( fileno(syBuf[fid].fp) ) )
return 0;
return 1;
}
void            syStopraw ( fid )
long                fid;
{
}
int             syGetch ( fid )
long                fid;
{
int                 ch;
if ( syTypeahead[0] != '\0' ) {
ch = syTypeahead[0];
strcpy( syTypeahead, syTypeahead+1 );
}
else {
ch = GETKEY();
}
if ( 0x110 <= ch && ch <= 0x132 )   ch = ESC( syAltMap[ch-0x110] );
else if ( ch == 0x147 )             ch = CTR('A');
else if ( ch == 0x14f )             ch = CTR('E');
else if ( ch == 0x148 )             ch = CTR('P');
else if ( ch == 0x14b )             ch = CTR('B');
else if ( ch == 0x14d )             ch = CTR('F');
else if ( ch == 0x150 )             ch = CTR('N');
else if ( ch == 0x153 )             ch = CTR('D');
else                                ch &= 0xFF;
return ch;
}
void            syEchoch ( ch, fid )
int                 ch;
long                fid;
{
PUTCHAR( ch );
}
void            syEchos ( str, fid )
char *              str;
long                fid;
{
char *              s;
while ( syStopout )  syStopout = (GETKEY() == CTR('S'));
for ( s = str; *s != '\0'; s++ )
PUTCHAR( *s );
}
#endif
#if SYS_TOS_GCC2
#ifndef SYS_KBD_H
# include       <unixlib.h>
# include       <osbind.h>
# define GETKEY()       Bconin( 2 )
# define PUTCHAR(C)     do{if(C=='\n')Bconout(2,'\r');Bconout(2,C);}while(0)
# define KBHIT()        Bconstat( 2 )
# define SYS_KBD_H
#endif
unsigned long   syStopout;
char            syTypeahead [256];
int             syStartraw ( fid )
long                fid;
{
if ( ! isatty( fileno(syBuf[fid].fp) ) )
return 0;
return 1;
}
void            syStopraw ( fid )
long                fid;
{
}
int             syGetch ( fid )
long                fid;
{
int                 ch;
if ( syTypeahead[0] != '\0' ) {
ch = syTypeahead[0];
strcpy( syTypeahead, syTypeahead+1 );
}
else {
ch = GETKEY();
}
if (      ch == 0x00480000 )        ch = CTR('P');
else if ( ch == 0x004B0000 )        ch = CTR('B');
else if ( ch == 0x004D0000 )        ch = CTR('F');
else if ( ch == 0x00500000 )        ch = CTR('N');
else if ( ch == 0x00730000 )        ch = CTR('Y');
else if ( ch == 0x00740000 )        ch = CTR('Z');
else                                ch = ch & 0xFF;
return ch;
}
void            syEchoch ( ch, fid )
int                 ch;
long                fid;
{
PUTCHAR( ch );
}
void            syEchos ( str, fid )
char *              str;
long                fid;
{
char *              s;
while ( syStopout )  syStopout = (GETKEY() == CTR('S'));
for ( s = str; *s != '\0'; s++ )
PUTCHAR( *s );
}
#endif
#if SYS_VMS
#ifndef SYS_HAS_MISC_PROTO

#endif
unsigned int            syVirKbd;
int             syStartraw ( fid )
long                fid;
{
return isatty( fileno(syBuf[fid].fp) );
}
void            syStopraw ( fid )
long                fid;
{
}
int             syGetch ( fid )
long                fid;
{
char                ch;
smg$read_keystroke( &syVirKbd, &ch );
return ch;
}
void            syEchoch ( ch, fid )
int                 ch;
long                fid;
{
char                ch2;
ch2 = ch;
write( fileno(syBuf[fid].echo), (char*)&ch2, 1 );
}
void            syEchos ( str, fid )
char *              str;
long                fid;
{
write( fileno(syBuf[fid].echo), str, SyStrlen(str) );
}
#endif
#if SYS_MAC_MPW
int             syStartraw ( fid )
long                fid;
{
SyIsIntr();
return 0;
}
void            syStopraw ( fid )
long                fid;
{
}
int             syGetch ( fid )
long                fid;
{
}
void            syEchoch ( ch, fid )
int                 ch;
long                fid;
{
}
void            syEchos ( str, fid )
char *              str;
long                fid;
{
char *              s;
for ( s = str; *s != '\0'; s++ )
putchar( *s );
fflush( stdout );
}
#endif
#if SYS_MAC_SYC
#ifndef SYS_UNIX_H
# include       <unix.h>
# define SYS_UNIX_H
#endif
#ifndef SYS_CONSOLE_H
# include       <Console.h>
# define SYS_CONSOLE_H
#endif
#ifndef SYS_OSUTILS_H
# include       <OSUtils.h>
# define SYS_OSUTILS_H
#endif
int             syStartraw ( fid )
long                fid;
{
if ( ! isatty( fileno(syBuf[fid].fp) ) )
return 0;
csetmode( C_RAW, syBuf[fid].fp );
return 1;
}
void            syStopraw ( fid )
long                fid;
{
if ( isatty( fileno(syBuf[fid].fp) ) )
return;
csetmode( C_ECHO, syBuf[fid].fp );
}
int             syGetch ( fid )
long                fid;
{
return syGetch2( fid, '\0' );
}
int             syGetch2 ( fid, cur )
long                fid;
int                 cur;
{
int                 ch;
if ( ! isatty( fileno(syBuf[fid].fp) ) )
return EOF;
syEchoch( (cur != '\0' ? cur : ' ') | 0x80, fid );
syEchoch( '\b', fid );
while ( ((ch = getchar()) == EOF) || (0x7F < ch) )
;
if (      ch == 28 )  ch = CTR('B');
else if ( ch == 29 )  ch = CTR('F');
else if ( ch == 30 )  ch = CTR('P');
else if ( ch == 31 )  ch = CTR('N');
syEchoch( (cur != '\0' ? cur : ' '), fid );
syEchoch( '\b', fid );
return ch;
}
void            syEchoch ( ch, fid )
int                 ch;
long                fid;
{
if ( ! isatty( fileno(syBuf[fid].fp) ) )
return;
if ( 31 < (ch & 0x7F) || ch == '\b' || ch == '\n' || ch == '\r' )
putchar( ch );
else if ( ch == CTR('G') )
SysBeep( 1 );
else
putchar( '?' );
}
void            syEchos ( str, fid )
char *              str;
long                fid;
{
char *              s;
if ( ! isatty( fileno(syBuf[fid].fp) ) )
return;
for ( s = str; *s != '\0'; s++ )
putchar( *s );
}
#endif
#if SYS_BSD || SYS_MACH || SYS_USG || SYS_OS2_EMX || SYS_VMS || SYS_MAC_MPW || SYS_MAC_SYC
void            SyFputs ( line, fid )
char                line [];
long                fid;
{
long                i;
if ( fid == 1 || fid == 3 ) {
syNrchar = 0;
for ( i = 0; line[i] != '\0'; i++ ) {
if ( line[i] == '\n' )  syNrchar = 0;
else                    syPrompt[syNrchar++] = line[i];
}
syPrompt[syNrchar] = '\0';
}
else {
for ( i = 0; line[i] != '\0'; i++ )
;
}
if ( syWindow && fid < 4 )
syWinPut( fid, (fid == 1 ? "@n" : "@f"), line );
else
#if ! (SYS_MAC_MPW || SYS_MAC_SYC)
write( fileno(syBuf[fid].fp), line, i );
#endif
#if SYS_MAC_MPW || SYS_MAC_SYC
fputs( line, syBuf[fid].fp );
#endif
}
#endif
#ifdef _WIN32
void            SyFputs ( line, fid )
char                line [];
long                fid;
{
long                i;
char *              s;
	if ( isatty( fileno(syBuf[fid].fp ))) {
for ( s = line; *s != '\0'; s++ )
PUTCHAR( *s );
	}
	else {
		fputs(line, syBuf[fid].fp);
	}
}
#endif
#if SYS_MSDOS_DJGPP || SYS_TOS_GCC2
void            SyFputs ( line, fid )
char                line [];
long                fid;
{
long                i;
char *              s;
if ( isatty( fileno(syBuf[fid].fp) ) ) {
syNrchar = 0;
for ( i = 0; line[i] != '\0'; i++ ) {
if ( line[i] == '\n' )  syNrchar = 0;
else                    syPrompt[syNrchar++] = line[i];
}
syPrompt[syNrchar] = '\0';
while ( syStopout )  syStopout = (GETKEY() == CTR('S'));
for ( s = line; *s != '\0'; s++ )
PUTCHAR( *s );
}
else {
fputs( line, syBuf[fid].fp );
}
}
#endif
#if ! (SYS_MAC_MPW || SYS_MAC_SYC)
void            syWinPut ( fid, cmd, str )
long                fid;
char *              cmd;
char *              str;
{
long                fd;
char                tmp [130];
char *              s;
char *              t;
if ( ! syWindow || 4 <= fid )
return;
if ( fid == 0 || fid == 2 )  fd = fileno(syBuf[fid].echo);
else                         fd = fileno(syBuf[fid].fp);
write( fd, cmd, SyStrlen(cmd) );
s = str;  t = tmp;
while ( *s != '\0' ) {
if ( *s == '@' ) {
*t++ = '@';  *t++ = *s++;
}
else if ( CTR('A') <= *s && *s <= CTR('Z') ) {
*t++ = '@';  *t++ = *s++ - CTR('A') + 'A';
}
else {
*t++ = *s++;
}
if ( 128 <= t-tmp ) {
write( fd, tmp, t-tmp );
t = tmp;
}
}
if ( 0 < t-tmp ) {
write( fd, tmp, t-tmp );
}
}
#endif
#if SYS_MAC_MPW || SYS_MAC_SYC
void            syWinPut ( fid, cmd, str )
long                fid;
char *              cmd;
char *              str;
{
}
#endif
void            SyPinfo ( nr, size )
int                 nr;
long                size;
{
char                cmd [3];
char                buf [16];
char *              b;
cmd[0] = '@';
cmd[1] = nr + '0';
cmd[2] = '\0';
b = buf;
while ( 0 < size ) {
*b++ = (size % 10) + '0';
size /= 10;
}
*b++ = '+';
*b = '\0';
syWinPut( 1, cmd, buf );
}
#if ! (SYS_MAC_MPW || SYS_MAC_SYC)
char            WinCmdBuffer [8000];
char *          SyWinCmd ( str,  len )
char *              str;
long                len;
{
char                buf [130];
char *              s;
char *              b;
unsigned long       i;
if ( ! syWindow )
return "I1+S52000000No Window Handler Present";
len = 0;
for ( s = str; *s != '\0'; s++ )
len += 1 + (*s == '@' || (CTR('A') <= *s && *s <= CTR('Z')));
b = buf;
for ( i = 0; i < 8; i++ ) {
*b++ = (len % 10) + '0';
len /= 10;
}
*b = '\0';
syWinPut( 1, "@w", buf );
syWinPut( 1, "", str );
s = WinCmdBuffer;
i = 10;
do {
while ( 0 < i ) {
len = read( 0, s, i );
i  -= len;
s  += len;
}
if ( WinCmdBuffer[0] == '@' && WinCmdBuffer[1] == 'y' ) {
for ( i = 2;  i < 10;  i++ )
WinCmdBuffer[i-2] = WinCmdBuffer[i];
s -= 2;
i  = 2;
}
} while ( 0 < i );
if ( WinCmdBuffer[0] != '@' || WinCmdBuffer[1] != 'a' )
return "I1+S41000000Illegal Answer";
for ( len = 0, i = 9;  1 < i;  i-- )
len = len*10 + (WinCmdBuffer[i]-'0');
s = WinCmdBuffer;
i = len;
while ( 0 < i ) {
len = read( 0, s, i );
i  -= len;
s  += len;
}
for ( b = s = WinCmdBuffer;  0 < len;  len-- ) {
if ( *s == '@' ) {
s++;
if ( *s == '@' )
*b++ = '@';
else if ( 'A' <= *s && *s <= 'Z' )
*b++ = CTR(*s);
s++;
}
else {
*b++ = *s++;
}
}
*b = 0;
return WinCmdBuffer;
}
#endif
#if SYS_MAC_MPW || SYS_MAC_SYC
char *          SyWinCmd ( str,  len )
char *              str;
long                len;
{
return 0;
}
#endif
#if SYS_BSD || SYS_MACH || SYS_USG || SYS_OS2_EMX || SYS_VMS
#ifndef SYS_SIGNAL_H
# include       <signal.h>
# ifdef SYS_HAS_SIG_T
#  define SYS_SIG_T     SYS_HAS_SIG_T
# else
#  define SYS_SIG_T     void
# endif
# define SYS_SIGNAL_H
typedef SYS_SIG_T       sig_handler_t P(( int ));
#endif
#ifndef SYS_HAS_SIGNAL_PROTO



#endif
#ifndef SYS_TIME_H
# if SYS_VMS
#  include      <types.h>
# endif
# include       <time.h>
# define SYS_TIME_H
#endif
#ifndef SYS_HAS_TIME_PROTO
# if SYS_ANSI

# else

# endif
#endif
unsigned long   syLastIntr;
SYS_SIG_T       syAnswerIntr ( signr )
int                 signr;
{
unsigned long       nowIntr;
nowIntr = time(0);
if ( syLastIntr && nowIntr-syLastIntr < 1 ) {
fputs("gap: you hit '<ctr>-C' twice in a second, goodbye.\n",stderr);
SyExit( 1 );
}
syLastIntr = nowIntr;
#if ! SYS_OS2_EMX
signal( SIGINT, syAnswerIntr );
#else
signal( signr, SIG_ACK );
#endif
#ifdef SYS_HAS_SIG_T
return 0;
#endif
}
long            SyIsIntr ()
{
long        isIntr;
isIntr = (syLastIntr != 0);
syLastIntr = 0;
return isIntr;
}
#endif
#ifdef _WIN32
long            SyIsIntr ()
{
	return 0;
}
#endif
#if SYS_MSDOS_DJGPP || SYS_TOS_GCC2
long            syIsIntrFreq = 20;
long            syIsIntrCount = 0;
long            SyIsIntr ()
{
int         ch, i;
if ( 0 < --syIsIntrCount )
return 0;
syIsIntrCount = syIsIntrFreq;
if ( syLineEdit && KBHIT() ) {
while ( KBHIT() ) {
ch = GETKEY();
if ( ch == CTR('C') || ch == CTR('Z') || ch == 0x12E ) {
PUTCHAR('^'); PUTCHAR('C');
syTypeahead[0] = '\0';
syStopout = 0;
return (size_t)1;
}
else if ( ch == CTR('X') ) {
PUTCHAR('^'); PUTCHAR('X');
syTypeahead[0] = '\0';
syStopout = 0;
}
else if ( ch == CTR('S') ) {
syStopout = 1;
}
else if ( syStopout ) {
syStopout = 0;
}
else {
for ( i = 0; i < sizeof(syTypeahead)-1; ++i ) {
if ( syTypeahead[i] == '\0' ) {
PUTCHAR(ch);
syTypeahead[i] = ch;
syTypeahead[i+1] = '\0';
break;
}
}
}
}
return 0L;
}
return 0L;
}
#endif
#if SYS_MAC_MPW
#ifdef  SYS_HAS_TOOL
#ifndef SYS_SIGNAL_H
# include       <Signal.h>
# ifdef SYS_HAS_SIG_T
#  define SYS_SIG_T     SYS_HAS_SIG_T
# else
#  define SYS_SIG_T     void
# endif
# define SYS_SIGNAL_H
typedef SYS_SIG_T       sig_handler_t P(( int ));
#endif
#ifndef SYS_HAS_SIGNAL_PROTO

#endif
#ifndef SYS_CURSORCTL_H
# include       <CursorCtl.h>
# define SYS_CURSORCTL_H
#endif
unsigned long   syNrIntr;
unsigned long   syLastIntr;
long            syIsIntrFreq = 100;
long            syIsIntrCount =  0;
void            syAnswerIntr ( signr )
int                 signr;
{
signal( SIGINT, &syAnswerIntr );
if ( syNrIntr && SyTime()-syLastIntr <= 1000 )
SyExit( 1 );
syNrIntr   = syNrIntr + 1;
syLastIntr = SyTime();
}
long            SyIsIntr ()
{
long                syIsIntr;
if ( 0 < --syIsIntrCount )
return 0;
syIsIntrCount = syIsIntrFreq;
Show_Cursor( HIDDEN_CURSOR );
SpinCursor( 8 );
syIsIntr = (syNrIntr != 0);
while ( syNrIntr ) {
while ( getchar() != EOF ) ;
clearerr( stdin );
syNrIntr = syNrIntr - 1;
}
return syIsIntr;
}
#else
#ifndef SYS_TYPES_H
# include       <Types.h>
# define SYS_TYPES_H
#endif
#ifndef SYS_OSUTILS_H
# include       <OSUtils.h>
# define SYS_OSUTILS_H
#endif
#ifndef SYS_OSEVENTS_H
# include       <OSEvents.h>
# define SYS_OSEVENTS_H
#endif
#ifndef SYS_EVENTS_H
# include       <Events.h>
# define SYS_EVENTS_H
#endif
unsigned long   syNrIntr;
unsigned long   syLastIntr;
long            syIsIntrFreq = 100;
long            syIsIntrCount =  0;
long            SyIsIntr ()
{
long                syIsIntr;
struct QHdr *       queue;
struct EvQEl *      qentry;
if ( 0 < --syIsIntrCount )
return 0;
syIsIntrCount = syIsIntrFreq;
queue = GetEvQHdr();
qentry = (struct EvQEl *)(queue->qHead);
while ( qentry ) {
if ( qentry->evtQWhat == keyDown
&&   ( ((qentry->evtQModifiers & controlKey) != 0)
&& ((qentry->evtQMessage & charCodeMask) ==   3))
|| ( ((qentry->evtQModifiers & cmdKey    ) != 0)
&& ((qentry->evtQMessage & charCodeMask) == '.')) ) {
syNrIntr++;
}
qentry = (struct EvQEl *)(qentry->qLink);
}
syIsIntr = (syNrIntr != 0);
if ( syNrIntr ) {
FlushEvents( keyDownMask, 0 );
syNrIntr = 0;
}
return syIsIntr;
}
#endif
#endif
#if SYS_MAC_SYC
#ifndef SYS_SIGNAL_H
# include       <signal.h>
# ifdef SYS_HAS_SIG_T
#  define SYS_SIG_T     SYS_HAS_SIG_T
# else
#  define SYS_SIG_T     void
# endif
# define SYS_SIGNAL_H
typedef SYS_SIG_T       sig_handler_t P(( int ));
#endif
#ifndef SYS_HAS_SIGNAL_PROTO

#endif
#ifndef SYS_TYPES_H
# include       <Types.h>
# define SYS_TYPES_H
#endif
#ifndef SYS_LOWMEM_H
# include       <LowMem.h>
# define SYS_LOWMEM_H
#endif
#ifndef SYS_OSUTILS_H
# include       <OSUtils.h>
# define SYS_OSUTILS_H
#endif
#ifndef SYS_OSEVENTS_H
# include       <OSEvents.h>
# define SYS_OSEVENTS_H
#endif
#ifndef SYS_EVENTS_H
# include       <Events.h>
# define SYS_EVENTS_H
#endif
#ifndef SYS_LOMEM_H
# include       <LoMem.h>
# define SYS_LOMEM_H
#endif
#ifndef SYS_DESK_H
# include       <Desk.h>
# define SYS_DESK_H
#endif
unsigned long   syNrIntr;
long            syIsIntrFreq  =  60;
long            syIsIntrCount =   0;
long            syIsBackFreq  = 600;
long            syIsBackCount =   0;
void            syAnswerIntr ( signr )
int                 signr;
{
signal( SIGINT, &syAnswerIntr );
syNrIntr = syNrIntr + 1;
}
long            SyIsIntr ()
{
long                syIsIntr;
struct QHdr *       queue;
struct EvQEl *      qentry;
EventRecord         theEvent;
if ( (*(long*)0x016A) <= syIsIntrCount )
return 0;
syIsIntrCount = (*(long*)0x016A) + syIsIntrFreq;
if ( syIsBackCount < (*(long*)0x016A) ) {
syIsBackCount = (*(long*)0x016A) + syIsBackFreq;
SystemTask();
SEvtEnb = false;
GetNextEvent( activMask, &theEvent );
}
syIsIntr = (syNrIntr != 0);
while ( syNrIntr ) {
while ( getchar() != EOF ) ;
clearerr( stdin );
syNrIntr = syNrIntr - 1;
}
queue = GetEvQHdr();
qentry = (struct EvQEl *)(queue->qHead);
while ( qentry ) {
if ( qentry->evtQWhat == keyDown
&&   ( ((qentry->evtQModifiers & controlKey) != 0)
&& ((qentry->evtQMessage & charCodeMask) ==   3))
|| ( ((qentry->evtQModifiers & cmdKey    ) != 0)
&& ((qentry->evtQMessage & charCodeMask) == '.')) ) {
syNrIntr++;
}
qentry = (struct EvQEl *)(qentry->qLink);
}
syIsIntr = syIsIntr || (syNrIntr != 0);
if ( syNrIntr ) {
FlushEvents( keyDownMask, 0 );
syNrIntr = 0;
}
return syIsIntr;
}
#endif
#ifndef SYS_STDLIB_H
# if SYS_ANSI
#  include      <stdlib.h>
# endif
# define SYS_STDLIB_H
#endif
#ifndef SYS_HAS_MISC_PROTO

#endif
#if SYS_MAC_SYC
#ifndef SYS_CONSOLE_H
# include       <Console.h>
# define SYS_CONSOLE_H
#endif
#endif
void            SyExit ( ret )
long                ret;
{
#if SYS_MAC_MPW
# ifndef SYS_HAS_TOOL
fputs("gap: please use <option>-'Q' to close the window.\n",stdout);
# endif
#endif
#if SYS_MAC_SYC
if ( ret != 0 )
console_options.pause_atexit = 1;
if ( console_options.pause_atexit == 1 )
printf( "gap: enter <return> to exit");
#endif
exit( (int)ret );
}
#ifndef SYS_STDLIB_H
# if SYS_ANSI
#  include      <stdlib.h>
# endif
# define SYS_STDLIB_H
#endif
#ifndef SYS_HAS_MISC_PROTO

#endif
#if ! (SYS_MAC_MPW || SYS_MAC_SYC)
void            SyExec ( cmd )
char *              cmd;
{
long                ignore;
syWinPut( 0, "@z", "" );
ignore = system( cmd );
syWinPut( 0, "@mAgIc", "" );
}
#endif
#if SYS_MAC_MPW || SYS_MAC_SYC
void            SyExec ( cmd )
char *              cmd;
{
}
#endif
#ifdef _WIN32
unsigned long   SyTime ()
{
	time_t ltime;
	return time(&ltime)*1000;
}
#endif
#if SYS_BSD || SYS_MACH || SYS_MSDOS_DJGPP
#ifndef SYS_HAS_NO_GETRUSAGE
#ifndef SYS_RESOURCE_H
# include       <sys/time.h>
# include       <sys/resource.h>
# define SYS_RESOURCE_H
#endif
#ifndef SYS_HAS_TIME_PROTO

#endif
unsigned long   SyTime ()
{
struct rusage       buf;
if ( getrusage( RUSAGE_SELF, &buf ) ) {
fputs("gap: panic 'SyTime' cannot get time!\n",stderr);
SyExit( 1 );
}
return buf.ru_utime.tv_sec*1000 + buf.ru_utime.tv_usec/1000 -syStartTime;
}
#endif
#ifdef SYS_HAS_NO_GETRUSAGE
#ifndef SYS_TIMES_H
# include       <sys/types.h>
# include       <sys/times.h>
# define SYS_TIMES_H
#endif
#ifndef SYS_HAS_TIME_PROTO

#endif
unsigned long   SyTime ()
{
struct tms          tbuf;
if ( times( &tbuf ) == -1 ) {
fputs("gap: panic 'SyTime' cannot get time!\n",stderr);
SyExit( 1 );
}
return 100 * tbuf.tms_utime / (60/10) - syStartTime;
}
#endif
#endif
#if SYS_USG || SYS_OS2_EMX
#ifndef SYS_TIMES_H
# include       <sys/param.h>
# include       <sys/types.h>
# include       <sys/times.h>
# define SYS_TIMES_H
#endif
#ifndef SYS_HAS_TIME_PROTO

#endif
unsigned long   SyTime ()
{
struct tms          tbuf;
if ( times( &tbuf ) == -1 ) {
fputs("gap: panic 'SyTime' cannot get time!\n",stderr);
SyExit( 1 );
}
return 100 * tbuf.tms_utime / (HZ / 10) - syStartTime;
}
#endif
#if SYS_TOS_GCC2 || SYS_VMS
#ifndef SYS_TIME_H
# include       <time.h>
# define SYS_TIME_H
#endif
#ifndef SYS_HAS_TIME_PROTO
# if SYS_ANSI

# define SYS_CLOCKS     CLOCKS_PER_SEC
# else

#  if SYS_TOS_GCC2
#   define SYS_CLOCKS   200
#  else
#   define SYS_CLOCKS   100
#  endif
# endif
#endif
unsigned long   SyTime ()
{
return 100 * (unsigned long)clock() / (SYS_CLOCKS/10) - syStartTime;
}
#endif
#if SYS_MAC_MPW || SYS_MAC_SYC
#ifndef SYS_TYPES_H
# include       <Types.h>
# define SYS_TYPES_H
#endif
#ifndef SYS_EVENTS_H
# include       <Events.h>
# define SYS_EVENTS_H
#endif
unsigned long   SyTime ()
{
return 100 * (unsigned long)TickCount() / (60/10) - syStartTime;
}
#endif
#ifndef SYS_STDIO_H
# include       <stdio.h>
# define SYS_STDIO_H
#endif
#ifndef SYS_HAS_MISC_PROTO

#endif
char *          SyTmpname ()
{
return tmpnam( (char*)0 );
}
char            syChapnames [128][16];
char            syLastTopics [16] [64] = { "Welcome to GAP" };
short           syLastIndex = 0;
void            SyHelp ( topic, fin )
char *              topic;
long                fin;
{
char                filename [256];
long                fid;
char                line [256];
unsigned long       chapnr;
char                chapname [64];
unsigned long       secnr;
char                secname [1024];
char                secline [128];
long                match;
long                matches;
char                last [256];
char                last2 [256];
long                offset;
char                ch;
long                spaces;
char                status;
char                * p, * q, * r;
unsigned long       i, j;
unsigned long       raw;
raw = (syLineEdit == 1 && syStartraw( fin ));
syWinPut( fin, "@h", "" );
if ( SyHelpname[0] == '\0' ) {
q = SyHelpname;
p = SyLibname;
while ( *p != '\0' )  *q++ = *p++;
*q = '\0';
for ( p = SyHelpname; *p != '\0'; p++ ) ;
while ( SyHelpname < p && (p[0]!='l' || p[1]!='i' || p[2]!='b') )
p--;
p[0] = 'd'; p[1] = 'o'; p[2] = 'c';
}
while ( *topic == ' ' )  topic++;
if ( topic[0] == '\0' ) {
topic = syLastTopics[ syLastIndex ];
}
offset = 0;
last[0] = '\0';
if ( SyStrcmp( topic, "<" ) == 0 ) {
topic = syLastTopics[ syLastIndex ];
offset = -1;
}
if ( SyStrcmp( topic, ">" ) == 0 ) {
topic = syLastTopics[ syLastIndex ];
offset = 1;
}
last2[0] = '\0';
if ( SyStrcmp( topic, "<<" ) == 0 ) {
topic = syLastTopics[ syLastIndex ];
offset = -2;
}
if ( SyStrcmp( topic, ">>" ) == 0 ) {
topic = syLastTopics[ syLastIndex ];
offset = 2;
}
if ( topic[0] == '-' ) {
while ( *topic++ == '-' )
syLastIndex = (syLastIndex + 15) % 16;
topic = syLastTopics[ syLastIndex ];
if ( topic[0] == '\0' ) {
syEchos( "Help: this section has no previous section\n", fin );
syLastIndex = (syLastIndex + 1) % 16;
if ( raw )  syStopraw( fin );
return;
}
syLastIndex = (syLastIndex + 15) % 16;
}
if ( topic[0] == '+' ) {
while ( *topic++ == '+' )
syLastIndex = (syLastIndex + 1) % 16;
topic = syLastTopics[ syLastIndex ];
if ( topic[0] == '\0' ) {
syEchos( "Help: this section has no previous section\n", fin );
syLastIndex = (syLastIndex + 15) % 16;
if ( raw )  syStopraw( fin );
return;
}
syLastIndex = (syLastIndex + 15) % 16;
}
if ( SyStrcmp( topic, "Welcome to GAP" ) == 0 ) {
syEchos( "    Welcome to GAP ______________________________", fin );
syEchos( "_____________ Welcome to GAP\n",                    fin );
syEchos( "\n",                                                fin );
syEchos( "    Welcome to GAP.\n",                             fin );
syEchos( "\n",                                                fin );
syEchos( "    GAP is a system for computational group theor", fin );
syEchos( "y.\n",                                              fin );
syEchos( "\n",                                                fin );
syEchos( "    Enter '?About GAP'    for a step by step intr", fin );
syEchos( "oduction to GAP.\n",                                fin );
syEchos( "    Enter '?Help'         for information how to ", fin );
syEchos( "use the GAP help system.\n",                        fin );
syEchos( "    Enter '?Chapters'     for a list of the chapt", fin );
syEchos( "ers of the GAP help system.\n",                     fin );
syEchos( "    Enter '?Copyright'    for the terms under whi", fin );
syEchos( "ch you can use and copy GAP.\n",                    fin );
syEchos( "\n",                                                fin );
syEchos( "    In each case do *not* enter the single quotes", fin );
syEchos( "(') , they are  used in help\n",                    fin );
syEchos( "    sections only to delimit text that you actual", fin );
syEchos( "ly enter.\n",                                       fin );
syEchos( "\n",                                                fin );
p = "Welcome to GAP";
syLastIndex = (syLastIndex + 1) % 16;
q = syLastTopics[ syLastIndex ];
while ( *p != '\0' )  *q++ = *p++;
*q = '\0';
if ( raw )  syStopraw( fin );
return;
}
if ( SyStrcmp(topic,"chapters")==0 || SyStrcmp(topic,"Chapters")==0 ) {
filename[0] = '\0';
SyStrncat( filename, SyHelpname, sizeof(filename)-12 );
SyStrncat( filename, "manual.toc", 11 );
fid = SyFopen( filename, "r" );
if ( fid == -1 ) {
syEchos( "Help: cannot open the table of contents file '",fin );
syEchos( filename, fin );
syEchos( "'\n", fin );
syEchos( "maybe use the option '-h <hlpname>'?\n", fin );
if ( raw )  syStopraw( fin );
return;
}
syEchos( "    Table of Chapters _________________", fin );
syEchos( "____________________ Table of Contents\n", fin );
offset = 2;
while ( SyFgets( line, sizeof(line), fid ) ) {
for ( p = line; *p != '\0' && ! IsDigit(*p); p++ )  ;
for ( i = 0; IsDigit(*p); p++ )  i = 10*i+*p-'0';
if ( *p == '.' )  p++;
for ( j = 0; IsDigit(*p); p++ )  j = 10*j+*p-'0';
if ( *p == '}' )  p++;
if ( i == 0 || ! IsAlpha(*p) ) {
syEchos("Help: contentsline is garbage in 'manual.toc'",fin);
SyFclose( fid );
if ( raw )  syStopraw( fin );
return;
}
if ( j != 0 )  continue;
if ( offset == SyNrRows && raw ) {
syEchos( "    -- <space> for more --", fin );
ch = syGetch( fin );
syEchos("\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b",
fin);
syEchos( "                          ", fin );
syEchos("\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b",
fin);
if ( ch == 'q' )  {
syEchos( "\n", fin );
break;
}
else if ( ch == '\n' || ch == '\r' ) {
offset = SyNrRows - 1;
}
else {
offset = 2;
}
}
q = line;
while ( *p != '}' )  *q++ = *p++;
*q++ = '\n';
*q = '\0';
syEchos( "    ", fin );
syEchos( line, fin );
offset++;
}
p = "Chapters";
syLastIndex = (syLastIndex + 1) % 16;
q = syLastTopics[ syLastIndex ];
while ( *p != '\0' )  *q++ = *p++;
*q = '\0';
SyFclose( fid );
if ( raw )  syStopraw( fin );
return;
}
if ( SyStrcmp(topic,"sections")==0 || SyStrcmp(topic,"Sections")==0 ) {
filename[0] = '\0';
SyStrncat( filename, SyHelpname, sizeof(filename)-12 );
SyStrncat( filename, "manual.toc", 11 );
fid = SyFopen( filename, "r" );
if ( fid == -1 ) {
syEchos( "Help: cannot open the table of contents file '",fin);
syEchos( filename, fin );
syEchos( "'\n", fin );
syEchos( "maybe use the option '-h <hlpname>'?\n", fin );
if ( raw )  syStopraw( fin );
return;
}
syEchos( "    Table of Sections _________________", fin );
syEchos( "____________________ Table of Contents\n", fin );
offset = 2;
while ( SyFgets( line, sizeof(line), fid ) ) {
for ( p = line; *p != '\0' && ! IsDigit(*p); p++ )  ;
for ( i = 0; IsDigit(*p); p++ )  i = 10*i+*p-'0';
if ( *p == '.' )  p++;
for ( j = 0; IsDigit(*p); p++ )  j = 10*j+*p-'0';
if ( *p == '}' )  p++;
if ( i == 0 || ! IsAlpha(*p) ) {
syEchos("Help: contentsline is garbage in 'manual.toc'",fin);
SyFclose( fid );
if ( raw )  syStopraw( fin );
return;
}
if ( offset == SyNrRows && raw ) {
syEchos( "    -- <space> for more --", fin );
ch = syGetch( fin );
syEchos("\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b",
fin);
syEchos( "                          ", fin );
syEchos("\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b",
fin);
if ( ch == 'q' )  {
syEchos( "\n", fin );
break;
}
else if ( ch == '\n' || ch == '\r' ) {
offset = SyNrRows - 1;
}
else {
offset = 2;
}
}
q = line;
while ( *p != '}' )  *q++ = *p++;
*q++ = '\n';
*q = '\0';
if ( j == 0 )  syEchos( "    ", fin );
else            syEchos( "        ", fin );
syEchos( line, fin );
offset++;
}
p = "Sections";
syLastIndex = (syLastIndex + 1) % 16;
q = syLastTopics[ syLastIndex ];
while ( *p != '\0' )  *q++ = *p++;
*q = '\0';
SyFclose( fid );
if ( raw )  syStopraw( fin );
return;
}
if ( SyStrcmp(topic,"copyright")==0 || SyStrcmp(topic,"Copyright")==0 ) {
filename[0] = '\0';
SyStrncat( filename, SyHelpname, sizeof(filename)-14 );
SyStrncat( filename, "copyrigh.tex", 13 );
fid = SyFopen( filename, "r" );
if ( fid == -1 ) {
syEchos( "Help: cannot open the copyright file '",fin);
syEchos( filename, fin );
syEchos( "'\n", fin );
syEchos( "maybe use the option '-h <helpname>'?\n", fin );
if ( raw )  syStopraw( fin );
return;
}
syEchos( "    Copyright _________________________", fin );
syEchos( "____________________________ Copyright\n", fin );
offset = 2;
while ( SyFgets( line, sizeof(line), fid ) ) {
if ( line[0] == '%' )  continue;
p = line;
q = "\\thispagestyle";
while ( *p == *q ) { p++; q++; }
if ( *q == '\0' )  continue;
if ( offset == SyNrRows && raw ) {
syEchos( "    -- <space> for more --", fin );
ch = syGetch( fin );
syEchos("\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b",
fin);
syEchos( "                          ", fin );
syEchos("\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b",
fin);
if ( ch == 'q' )  {
syEchos( "\n", fin );
break;
}
else if ( ch == '\n' || ch == '\r' ) {
offset = SyNrRows - 1;
}
else {
offset = 2;
}
}
p = line;
q = "{\\large";
while ( *p == *q ) { p++; q++; }
if ( *q == '\0' ) {
syEchos( "    Copyright (c) 1992 ", fin );
syEchos( "by Lehrstuhl D fuer Mathematik\n", fin );
continue;
}
p = line;
q = last;
spaces = 0;
while ( *p != '\0' ) {
if ( *p == '\\' || *p == '{' || *p == '}' ) {
if ( last < q && q[-1] == ' ' )
*q++ = ' ';
else
spaces++;
}
else if ( *p == ' ' ) {
*q++ = ' ';
while ( 0 < spaces ) {
*q++ = ' ';
spaces--;
}
}
else {
*q++ = *p;
}
p++;
}
*q = '\0';
syEchos( "    ", fin );  syEchos( last, fin );
offset++;
}
p = "Copyright";
syLastIndex = (syLastIndex + 1) % 16;
q = syLastTopics[ syLastIndex ];
while ( *p != '\0' )  *q++ = *p++;
*q = '\0';
SyFclose( fid );
if ( raw )  syStopraw( fin );
return;
}
if ( topic[0] == '?' ) {
topic++;
while ( *topic == ' ' )  topic++;
filename[0] = '\0';
SyStrncat( filename, SyHelpname, sizeof(filename)-12 );
SyStrncat( filename, "manual.idx", 11 );
fid = SyFopen( filename, "r" );
if ( fid == -1 ) {
syEchos( "Help: cannot open the index file '", fin);
syEchos( filename, fin );
syEchos( "'\n", fin );
syEchos( "maybe use the option '-h <hlpname>'?\n", fin );
if ( raw )  syStopraw( fin );
return;
}
line[0] = '\0';
SyStrncat( line, topic, 40 );
SyStrncat( line,
" _________________________________________________________________",
73 - 5 );
line[72-5] = ' ';
line[73-5] = '\0';
SyStrncat( line, "Index", 6 );
SyStrncat( line, "\n", 2 );
syEchos( "    ", fin );
syEchos( line, fin );
offset = 2;
while ( SyFgets( line, sizeof(line), fid ) ) {
if ( line[0] == '%' ) {
while ( line[0] == '%' ) {
if ( ! SyFgets( line, sizeof(line), fid ) ) {
syEchos( "Help: index file is garbage\n", fin );
SyFclose( fid );
if ( raw )  syStopraw( fin );
return;
}
}
q = secname;
p = line + 12;
while ( *p != '}' )  *q++ = *p++;
*q = '\0';
}
if ( secname[0] == '\0' )  continue;
for ( r = line + 12; *r != '\0'; r++ ) {
p = topic;
q = r;
while ( (*p | 0x20) == (*q | 0x20) ) { p++; q++; }
if ( *p == '\0' )  break;
}
if ( *r == '\0' )  continue;
if ( offset == SyNrRows && raw ) {
syEchos( "    -- <space> for more --", fin );
ch = syGetch( fin );
syEchos("\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b",
fin);
syEchos( "                          ", fin );
syEchos("\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b",
fin);
if ( ch == 'q' )  {
syEchos( "\n", fin );
break;
}
else if ( ch == '\n' || ch == '\r' ) {
offset = SyNrRows - 1;
}
else {
offset = 2;
}
}
syEchos( "    ", fin );
syEchos( secname, fin );
p = secname;
q = line + 12;
while ( *p == *q ) { p++; q++; }
if ( *p != '\0' ) {
syEchos( " (", fin );
for ( p = line + 12; *p != '}'; p++ ) ;
*p = '\0';
syEchos( line + 12, fin );
syEchos( ")", fin );
}
syEchos( "\n", fin );
offset++;
secname[0] = '\0';
}
SyFclose( fid );
if ( raw )  syStopraw( fin );
return;
}
filename[0] = '\0';
SyStrncat( filename, SyHelpname, sizeof(filename)-12 );
SyStrncat( filename, "manual.toc", 11 );
fid = SyFopen( filename, "r" );
if ( fid == -1 ) {
syEchos( "Help: cannot open the table of contents file '", fin );
syEchos( filename, fin );
syEchos( "'\n", fin );
syEchos( "maybe use the option '-h <hlpname>'?\n", fin );
if ( raw )  syStopraw( fin );
return;
}
chapnr = 0;
secnr = 0;
secname[0] = '\0';
matches = 0;
while ( SyFgets( line, sizeof(line), fid ) ) {
for ( p = line; *p != '\0' && ! IsDigit(*p); p++ )  ;
for ( i = 0; IsDigit(*p); p++ )  i = 10*i+*p-'0';
if ( *p == '.' )  p++;
for ( j = 0; IsDigit(*p); p++ )  j = 10*j+*p-'0';
if ( *p == '}' )  p++;
if ( i == 0 || ! IsAlpha(*p) ) {
syEchos("Help: contentsline is garbage in 'manual.toc'",fin);
SyFclose( fid );
return;
}
q = topic;
match = 2;
while ( *p != '}' && match ) {
if ( *q != '\0' && (*p | 0x20) == (*q | 0x20) ) {
p++; q++;
}
else if ( *q == ' ' || *q == '\0' ) {
p++;
match = 1;
}
else {
match = 0;
}
}
if ( *q != '\0' )  match = 0;
if ( match == 2 && offset == -1 ) {
if ( last[0] == '\0' ) {
syEchos("Help: the last section is the first one\n", fin );
SyFclose( fid );
if ( raw )  syStopraw( fin );
return;
}
q = line;
p = last;
while ( *p != '\0' )  *q++ = *p++;
*q = '\0';
}
if ( match == 2 && offset == 1 ) {
if ( ! SyFgets( line, sizeof(line), fid ) ) {
syEchos("Help: the last section is the last one\n", fin );
SyFclose( fid );
if ( raw )  syStopraw( fin );
return;
}
}
if ( match == 2 && offset == -2 ) {
if ( last2[0] == '\0' ) {
syEchos("Help: the last section is the first one\n", fin );
SyFclose( fid );
if ( raw )  syStopraw( fin );
return;
}
q = line;
p = last2;
while ( *p != '\0' )  *q++ = *p++;
*q = '\0';
}
if ( match == 2 && offset == 2 ) {
while ( 1 ) {
if ( ! SyFgets( line, sizeof(line), fid ) ) {
syEchos("Help: the last section is in the last chapter\n",
fin );
SyFclose( fid );
if ( raw )  syStopraw( fin );
return;
}
for ( p = line; *p != '\0' && ! IsDigit(*p); p++ )  ;
for ( ; *p != '}' && *p != '.'; p++ )  ;
if ( *p == '}' )  break;
}
}
for ( p = line; *p != '\0' && ! IsDigit(*p); p++ )  ;
for ( i = 0; IsDigit(*p); p++ )  i = 10*i+*p-'0';
if ( *p == '.' )  p++;
for ( j = 0; IsDigit(*p); p++ )  j = 10*j+*p-'0';
if ( *p == '}' )  p++;
if ( i == 0 || ! IsAlpha(*p) ) {
syEchos("Help: contentsline is garbage in 'manual.toc'",fin);
SyFclose( fid );
if ( raw )  syStopraw( fin );
return;
}
if ( match == 2 ) {
chapnr = i;
secnr  = j;
q = secname;
while ( *p != '}' )  *q++ = *p++;
*q = '\0';
matches = 1;
break;
}
else if ( match == 1 ) {
chapnr = i;
secnr  = j;
q = secname;
while ( *q != '\0' )  q++;
if ( q != secname && q < secname+sizeof(secname)-1 )
*q++ = '\n';
while ( *p != '}' && q < secname+sizeof(secname)-1 )
*q++ = *p++;
*q = '\0';
matches++;
}
q = last;
p = line;
while ( *p != '\0' ) *q++ = *p++;
*q = '\0';
if ( j == 0 ) {
q = last2;
p = line;
while ( *p != '\0' )  *q++ = *p++;
*q = '\0';
}
}
SyFclose( fid );
if ( matches == 0 ) {
syEchos( "Help: no section with this name was found\n", fin );
if ( raw )  syStopraw( fin );
return;
}
if ( 2 <= matches ) {
syEchos( "Help: several sections match this topic\n", fin );
syEchos( secname, fin );
syEchos( "\n", fin );
if ( raw )  syStopraw( fin );
return;
}
if ( syChapnames[0][0] == '\0' ) {
filename[0] = '\0';
SyStrncat( filename, SyHelpname, sizeof(filename)-12 );
SyStrncat( filename, "manual.tex", 11 );
fid = SyFopen( filename, "r" );
if ( fid == -1 ) {
syEchos( "Help: cannot open the manual file '", fin );
syEchos( filename, fin );
syEchos( "'\n", fin );
syEchos( "maybe use the option '-h <hlpname>'?\n", fin );
if ( raw )  syStopraw( fin );
return;
}
offset = 0;
while ( SyFgets( line, sizeof(line), fid ) ) {
p = line;
q = "\\Include{";
while ( *p == *q ) { p++; q++; }
if ( *q == '\0' ) {
q = syChapnames[offset];
while ( *p != '}' )  *q++ = *p++;
*q = '\0';
offset++;
}
}
SyFclose( fid );
}
filename[0] = '\0';
SyStrncat( filename, SyHelpname, sizeof(filename)-13 );
SyStrncat( filename, syChapnames[chapnr-1], 9 );
SyStrncat( filename, ".tex", 4 );
fid = SyFopen( filename, "r" );
if ( fid == -1 ) {
syEchos( "Help: cannot open the chapter file '", fin );
syEchos( filename, fin );
syEchos( "'\n", fin );
syEchos( "maybe use the option '-h <hlpname>'?\n", fin );
if ( raw )  syStopraw( fin );
return;
}
if ( secnr == 0 ) {
secline[0] = '\0';
SyStrncat( secline, "\\Chapter{", 10 );
SyStrncat( secline, secname, sizeof(secline)-10 );
}
else {
secline[0] = '\0';
SyStrncat( secline, "\\Section{", 10 );
SyStrncat( secline, secname, sizeof(secline)-10 );
}
match = 0;
while ( ! match && SyFgets( line, sizeof(line), fid ) ) {
p = line;
q = secline;
while ( *p == *q ) { p++; q++; }
match = (*q == '\0' && *p == '}');
p = line;
q = "\\Chapter{";
while ( *p == *q ) { p++; q++; }
if ( *q == '\0' ) {
q = chapname;
while ( *p != '}' )  *q++ = *p++;
*q = '\0';
}
}
if ( ! match ) {
syEchos( "Help: could not find section '", fin );
syEchos( secname, fin );
syEchos( "' in chapter file '", fin );
syEchos( filename, fin );
syEchos( "'\n", fin );
SyFclose( fid );
if ( raw )  syStopraw( fin );
return;
}
p = secname;
syLastIndex = (syLastIndex + 1) % 16;
q = syLastTopics[ syLastIndex ];
while ( *p != '\0' )  *q++ = *p++;
*q = '\0';
line[0] = '\0';
SyStrncat( line, secname, 40 );
SyStrncat( line,
" _____________________________________________________________________",
73 - SyStrlen(chapname) );
line[72-SyStrlen(chapname)] = ' ';
line[73-SyStrlen(chapname)] = '\0';
SyStrncat( line, chapname, SyStrlen(chapname)+1 );
SyStrncat( line, "\n", 2 );
syEchos( "    ", fin );
syEchos( line, fin );
offset = 2;
status = 'a';
while ( SyFgets( line, sizeof(line), fid ) ) {
p = line;
q = "\\index{";
while ( *p == *q ) { p++; q++; }
if ( *q == '\0' )  continue;
p = line;
q = "\\newpage";
while ( *p == *q ) { p++; q++; }
if ( *q == '\0' )  continue;
p = line;
q = "\\begin{";
while ( *p == *q ) { p++; q++; }
if ( *q == '\0' )  continue;
p = line;
q = "\\end{";
while ( *p == *q ) { p++; q++; }
if ( *q == '\0' )  continue;
p = line;
q = "%%%%%%%%%%%%%%%%";
while ( *p == *q ) { p++; q++; }
if ( *q == '\0' )  break;
p = line;
q = "%";
while ( *p == *q ) { p++; q++; }
if ( *q == '\0' )  continue;
if ( offset == SyNrRows && raw ) {
syEchos( "    -- <space> for more --", fin );
ch = syGetch( fin );
syEchos("\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b",
fin);
syEchos( "                          ", fin );
syEchos("\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b\b",
fin);
if ( ch == 'q' )  {
syEchos( "\n", fin );
break;
}
else if ( ch == '\n' || ch == '\r' ) {
offset = SyNrRows - 1;
}
else {
offset = 2;
}
}
p = line;
q = "\\vspace{";
while ( *p == *q ) { p++; q++; }
if ( *q == '\0' ) {
syEchos( "\n", fin );
offset++;
continue;
}
p = line;
q = last;
spaces = 0;
while ( *p != '\0' ) {
if ( *p == '\\' && status != '|' ) {
if ( last < q && q[-1] == ' ' )
*q++ = ' ';
else
spaces++;
}
else if ( *p=='{' && (line==p || p[-1]!='\\') && status!='|' ) {
if ( status == '$' )
*q++ = '(';
else if ( last < q && q[-1] == ' ' )
*q++ = ' ';
else
spaces++;
}
else if ( *p=='}' && (line==p || p[-1]!='\\') && status!='|' ) {
if ( status == '$' )
*q++ = ')';
else if ( last < q && q[-1] == ' ' )
*q++ = ' ';
else
spaces++;
}
else if ( *p=='$' && (line==p || p[-1]!='\\') && status!='|' ) {
if ( last < q && q[-1] == ' ' )
*q++ = ' ';
else
spaces++;
if ( status != '$' )
status = '$';
else
status = 'a';
}
else if ( *p == ' ' && status != '|' ) {
*q++ = ' ';
while ( 0 < spaces ) {
*q++ = ' ';
spaces--;
}
}
else if ( *p=='|' && (line==p || p[-1]!='\\'
|| status=='|' || status=='#') ) {
if ( status == '|' || status == '#' )
status = 'a';
else
status = '|';
spaces++;
}
else if ( *p == '#' ) {
if ( status == '|' )
status = '#';
*q++ = *p;
}
else if ( *p == '\n' ) {
if ( status == '#' )
status = '|';
*q++ = *p;
}
else if ( *p == '>' && line!=p && p[-1]=='\\' ) {
spaces++;
}
else if ( *p == '=' && line!=p && p[-1]=='\\' ) {
spaces++;
}
else {
*q++ = *p;
}
p++;
}
*q = '\0';
syEchos( "    ", fin );  syEchos( last, fin );
offset++;
}
SyFclose( fid );
if ( raw )  syStopraw( fin );
}
#if SYS_BSD||SYS_USG||SYS_OS2_EMX||SYS_MSDOS_DJGPP||SYS_TOS_GCC2||SYS_VMS
char *          syHighmem;
#endif
#if SYS_MACH
#ifdef ARCH_INCLUDE
# include       <mach/mach.h>
#else
# include       <mach.h>
#endif
vm_address_t      syBase  = 0;
long              sySize  = 0;
long              syUsed  = 0;
char *          SyGetmem ( size )
long                size;
{
vm_address_t        adr;
long                new;
if ( syBase == 0 ) {
sySize = ( (size+vm_page_size-1) / vm_page_size ) * vm_page_size;
syUsed = size;
if ( vm_allocate(task_self(),&syBase,sySize,TRUE) != KERN_SUCCESS ) {
fputs("gap: panic 'SyGetmem' vm_allocate failed!\n",stderr);
SyExit(1);
}
return (char*) syBase;
}
else if ( syUsed + size <= sySize ) {
syUsed += size;
return (char*) syBase + (syUsed-size);
}
else {
new = ( (size+vm_page_size-1) / vm_page_size ) * vm_page_size;
adr = (vm_address_t)( (char*) syBase + sySize );
if ( vm_allocate(task_self(),&adr,new,FALSE) != KERN_SUCCESS ) {
fputs("gap: sorry, cannot extend the workspace, ",stderr);
fputs("maybe use option '-a <memory>'?\n",stderr);
SyExit( 1 );
}
syUsed += size;
sySize += new;
return (char*) syBase + (syUsed-size);
}
}
#endif
#ifndef _WIN32
#ifndef SYS_HAS_CALLOC_PROTO
# if SYS_ANSI

# else

# endif
#endif
char *          syWorkspace;
char *          SyGetmem ( size )
long                size;
{
if ( syWorkspace == 0 ) {
syWorkspace = calloc( (size_t) (size/4), (size_t)4 );
#if defined(SPEC_CPU2000_LP64) || defined(SPEC_CPU2000_P64)
syWorkspace = (char*)(((long)syWorkspace + 7) & ~7);
#else
syWorkspace = (char*)(((long)syWorkspace + 3) & ~3);
#endif
return syWorkspace;
}
else {
return (char*)-1;
}
}
#else
char *          syWorkspace;
char *          SyGetmem ( size )
long                size;
{
if ( syWorkspace == 0 ) {
syWorkspace = calloc( (size_t) (size/4), (size_t)4 );
#if defined(SPEC_CPU2000_LP64) || defined(SPEC_CPU2000_P64)
syWorkspace = (char*)(((long)syWorkspace + 7) & ~7);
#else
syWorkspace = (char*)(((long)syWorkspace + 3) & ~3);
#endif
return syWorkspace;
}
else {
return (char*)-1;
}
}
#endif
#if SYS_MAC_SYC
#ifndef SYS_STRING_H
# include      <string.h>
# define SYS_STRING_H
#endif
#ifndef SYS_HAS_MEMSET_PROTO

#endif
char *          syWorkspace;
char *          SyGetmem ( size )
long                size;
{
if ( syWorkspace == 0 ) {
syWorkspace = (char*)NewPtr( size + 3 );
#if defined(SPEC_CPU2000_LP64) || defined(SPEC_CPU2000_P64)
syWorkspace = (char*)(((long)syWorkspace + 7) & ~7);
#else
syWorkspace = (char*)(((long)syWorkspace + 3) & ~3);
#endif
memset( syWorkspace, 0, size );
return syWorkspace;
}
else {
return (char*)-1;
}
}
#endif
#ifndef SYS_STDLIB_H
# if SYS_ANSI
#  include      <stdlib.h>
# endif
# define SYS_STDLIB_H
#endif
#ifndef SYS_HAS_MISC_PROTO


#endif
#ifndef SYS_HAS_MISC_PROTO


#endif
#ifndef SYS_STDLIB_H
# if SYS_ANSI
#  include      <stdlib.h>
# endif
# define SYS_STDLIB_H
#endif
#ifndef SYS_HAS_MALLOC_PROTO
# if SYS_ANSI


# else


# endif
#endif
#if SYS_TOS_GCC2
# ifndef SYS_BASEPAGE_H
#  include      <basepage.h>
#  define SYS_BASEPAGE_H
# endif
#endif
#if SYS_MAC_SYC
#ifndef SYS_CONSOLE_H
# include       <Console.h>
# define SYS_CONSOLE_H
#endif
#endif
#if SYS_MAC_MPW || SYS_MAC_SYC
# ifndef SYS_HAS_TOOL
#  ifndef SYS_MEMORY_H
#   include     <Memory.h>
#   define SYS_MEMORY_H
#  endif
# endif
#endif
#if SYS_MAC_MPW || SYS_MAC_SYC
# ifndef SYS_HAS_TOOL
char *          syArgv [128];
char            syArgl [1024];
# endif
#endif
#if SYS_MAC_SYC
long *          dedgen;
long *          dedcos;
long            dedSize = 40960;
#endif
void            InitSystem ( argc, argv )
int                 argc;
char *              argv [];
{
long                fid;
long                pre = 63*1024;
int                 gaprc = 1;
char *              ptr;
long                i, k;
#if SYS_MAC_MPW || SYS_MAC_SYC
# ifndef SYS_HAS_TOOL
SetApplLimit( GetApplLimit() - (SyStackSpace - StackSpace() + 1024) );
MaxApplZone();
if ( StackSpace() < SyStackSpace ) {
fputs("gap: cannot get enough stack space.\n",stderr);
SyExit( 1 );
}
# endif
#endif
#if SYS_BSD || SYS_MACH || SYS_USG || SYS_VMS
syBuf[0].fp = stdin;   setbuf( stdin, syBuf[0].buf );
if ( isatty( fileno(stdin) ) ) {
if ( isatty( fileno(stdout) )
&& ! SyStrcmp( ttyname(fileno(stdin)), ttyname(fileno(stdout)) ) )
syBuf[0].echo = stdout;
else
syBuf[0].echo = fopen( ttyname(fileno(stdin)), "w" );
if ( syBuf[0].echo != (FILE*)0 && syBuf[0].echo != stdout )
setbuf( syBuf[0].echo, (char*)0 );
}
else {
syBuf[0].echo = stdout;
}
syBuf[1].fp = stdout;  setbuf( stdout, (char*)0 );
if ( isatty( fileno(stderr) ) ) {
if ( isatty( fileno(stdin) )
&& ! SyStrcmp( ttyname(fileno(stdin)), ttyname(fileno(stderr)) ) )
syBuf[2].fp = stdin;
else
syBuf[2].fp = fopen( ttyname(fileno(stderr)), "r" );
if ( syBuf[2].fp != (FILE*)0 && syBuf[2].fp != stdin )
setbuf( syBuf[2].fp, syBuf[2].buf );
syBuf[2].echo = stderr;
}
syBuf[3].fp = stderr;  setbuf( stderr, (char*)0 );
#endif
#if SYS_OS2_EMX
syBuf[0].fp = stdin;   setbuf( stdin, syBuf[0].buf );
if ( isatty( fileno(stdin) ) ) {
if ( isatty( fileno(stdout) ) )
syBuf[0].echo = stdout;
else
syBuf[0].echo = fopen( "CON", "w" );
if ( syBuf[0].echo != (FILE*)0 && syBuf[0].echo != stdout )
setbuf( syBuf[0].echo, (char*)0 );
}
else {
syBuf[0].echo = stdout;
}
syBuf[1].fp = stdout;  setbuf( stdout, (char*)0 );
if ( isatty( fileno(stderr) ) ) {
if ( isatty( fileno(stdin) ) )
syBuf[2].fp = stdin;
else
syBuf[2].fp = fopen( "CON", "r" );
if ( syBuf[2].fp != (FILE*)0 && syBuf[2].fp != stdin )
setbuf( syBuf[2].fp, syBuf[2].buf );
syBuf[2].echo = stderr;
}
syBuf[3].fp = stderr;  setbuf( stderr, (char*)0 );
#endif
#if SYS_MSDOS_DJGPP || SYS_TOS_GCC2 || _WIN32
syBuf[0].fp = stdin;   setbuf( stdin, syBuf[0].buf );
syBuf[1].fp = stdout;  setbuf( stdout, (char*)0 );
syBuf[3].fp = stderr;  setbuf( stderr, (char*)0 );
if ( isatty( fileno(stderr) ) )
syBuf[2].fp = stderr;
#endif
#if SYS_MAC_MPW || SYS_MAC_SYC
syBuf[0].fp = stdin;
syBuf[1].fp = stdout;
syBuf[2].fp = stdin;
syBuf[3].fp = stderr;
#endif
#if SYS_BSD || SYS_MACH || SYS_USG || SYS_OS2_EMX || SYS_VMS
if ( signal( SIGINT, SIG_IGN ) != SIG_IGN )
signal( SIGINT, syAnswerIntr );
#endif
#if SYS_OS2_EMX
signal( SIGBREAK, syAnswerIntr );
#endif
#if SYS_MAC_MPW
# ifdef SYS_HAS_TOOL
signal( SIGINT, &syAnswerIntr );
# endif
#endif
#if SYS_MAC_SYC
signal( SIGINT, &syAnswerIntr );
#endif
#if SYS_MAC_MPW || SYS_MAC_SYC
# ifndef SYS_HAS_TOOL
if ( (fid = SyFopen( "gap.options", "r" )) != -1 ) {
argc = 0;
argv = syArgv;
argv[argc++] = "gap";
ptr = syArgl;
while ( SyFgets( ptr, (sizeof(syArgl)-1) - (ptr-syArgl), fid )
&& (ptr-syArgl) < (sizeof(syArgl)-1) ) {
while ( *ptr != '#' && *ptr != '\0' )
ptr++;
}
ptr = syArgl;
while ( *ptr==' ' || *ptr=='\t' || *ptr=='\n' )  *ptr++ = '\0';
while ( *ptr != '\0' ) {
argv[argc++] = ptr;
while ( *ptr!=' ' && *ptr!='\t' && *ptr!='\n' && *ptr!='\0' ) {
if ( *ptr=='\\' )
for ( k = 0; ptr[k+1] != '\0'; k++ )
ptr[k] = ptr[k+1];
ptr++;
}
while ( *ptr==' ' || *ptr=='\t' || *ptr=='\n' )  *ptr++ = '\0';
}
SyFclose( fid );
}
# endif
#endif
while ( argc > 1 && argv[1][0] == '-' ) {
if ( SyStrlen(argv[1]) != 2 ) {
fputs("gap: sorry, options must not be grouped '",stderr);
fputs(argv[1],stderr);  fputs("'.\n",stderr);
goto usage;
}
switch ( argv[1][1] ) {
case 'b':
SyBanner = ! SyBanner;
break;
case 'g':
SyGasman = ! SyGasman;
break;
case 'l':
if ( argc < 3 ) {
fputs("gap: option '-l' must have an argument.\n",stderr);
goto usage;
}
SyLibname[0] = '\0';
SyStrncat( SyLibname, argv[2], sizeof(SyLibname)-2 );
#if SYS_BSD || SYS_MACH || SYS_USG || SYS_OS2_EMX
if ( SyLibname[SyStrlen(SyLibname)-1] != '/'
&& SyLibname[SyStrlen(SyLibname)-1] != ';' )
SyStrncat( SyLibname, "/", 1 );
#endif
#if SYS_MSDOS_DJGPP || SYS_TOS_GCC2 || _WIN32
if ( SyLibname[SyStrlen(SyLibname)-1] != '\\'
&& SyLibname[SyStrlen(SyLibname)-1] != ';' )
SyStrncat( SyLibname, "\\", 1 );
#endif
++argv; --argc;
break;
case 'h':
if ( argc < 3 ) {
fputs("gap: option '-h' must have an argument.\n",stderr);
goto usage;
}
SyHelpname[0] = '\0';
#if SYS_BSD || SYS_MACH || SYS_USG || SYS_OS2_EMX
SyStrncat( SyHelpname, argv[2], sizeof(SyLibname)-2 );
if ( SyLibname[SyStrlen(SyHelpname)-1] != '/' )
SyStrncat( SyHelpname, "/", 1 );
#endif
#if SYS_MSDOS_DJGPP || SYS_TOS_GCC2 || _WIN32
SyStrncat( SyHelpname, argv[2], sizeof(SyLibname)-2 );
if ( SyLibname[SyStrlen(SyHelpname)-1] != '\\' )
SyStrncat( SyHelpname, "\\", 1 );
#endif
++argv; --argc;
break;
case 'm':
if ( argc < 3 ) {
fputs("gap: option '-m' must have an argument.\n",stderr);
goto usage;
}
SyMemory = atoi(argv[2]);
if ( argv[2][SyStrlen(argv[2])-1] == 'k'
|| argv[2][SyStrlen(argv[2])-1] == 'K' )
SyMemory = SyMemory * 1024;
if ( argv[2][SyStrlen(argv[2])-1] == 'm'
|| argv[2][SyStrlen(argv[2])-1] == 'M' )
SyMemory = SyMemory * 1024 * 1024;
++argv; --argc;
break;
case 'a':
if ( argc < 3 ) {
fputs("gap: option '-a' must have an argument.\n",stderr);
goto usage;
}
pre = atoi(argv[2]);
if ( argv[2][SyStrlen(argv[2])-1] == 'k'
|| argv[2][SyStrlen(argv[2])-1] == 'K' )
pre = pre * 1024;
if ( argv[2][SyStrlen(argv[2])-1] == 'm'
|| argv[2][SyStrlen(argv[2])-1] == 'M' )
pre = pre * 1024 * 1024;
++argv; --argc;
break;
case 'n':
if ( ! syWindow )  syLineEdit = 0;
break;
case 'f':
if ( ! syWindow )  syLineEdit = 2;
break;
case 'q':
SyQuiet = ! SyQuiet;
break;
case 'x':
if ( argc < 3 ) {
fputs("gap: option '-x' must have an argument.\n",stderr);
goto usage;
}
SyNrCols = atoi(argv[2]);
++argv; --argc;
break;
case 'y':
if ( argc < 3 ) {
fputs("gap: option '-y' must have an argument.\n",stderr);
goto usage;
}
SyNrRows = atoi(argv[2]);
++argv; --argc;
break;
case 'e':
if ( ! syWindow )  syCTRD = ! syCTRD;
break;
#if SYS_BSD || SYS_MACH || SYS_USG
case 'p':
syWindow     = 1;
syLineEdit   = 1;
syCTRD       = 1;
syWinPut( 0, "@p", "" );
syBuf[2].fp = stdin;  syBuf[2].echo = stdout;
syBuf[3].fp = stdout;
break;
#endif
#if SYS_MSDOS_DJGPP || SYS_TOS_GCC2 || SYS_MAC_MPW || SYS_MAC_SYC
case 'z':
if ( argc < 3 ) {
fputs("gap: option '-z' must have an argument.\n",stderr);
goto usage;
}
syIsIntrFreq = atoi(argv[2]);
++argv; --argc;
break;
#endif
#if SYS_MAC_SYC
case 'Z':
if ( argc < 3 ) {
fputs("gap: option '-Z' must have an argument.\n",stderr);
goto usage;
}
syIsBackFreq = atoi(argv[2]);
++argv; --argc;
break;
#endif
#if SYS_OS2_EMX
case 'E':
syLineEdit = 2;
syBuf[2].fp = stdin;
syBuf[2].echo = stderr;
break;
#endif
case 'r':
gaprc = ! gaprc;
break;
default:
fputs("gap: '",stderr);  fputs(argv[1],stderr);
fputs("' option is unknown.\n",stderr);
goto usage;
}
++argv; --argc;
}
#if SYS_MAC_SYC
console_options.title = "\pGAP 3.4.2";
console_options.nrows = SyNrRows;
console_options.ncols = SyNrCols;
console_options.pause_atexit = 0;
cinverse( 1, stdin );
#endif
#if SYS_MAC_SYC
dedgen = (long*)NewPtr( dedSize * sizeof(long) );
dedcos = (long*)NewPtr( dedSize * sizeof(long) );
#endif
ptr = malloc( (size_t) pre );
if ( ptr != 0 )  free( ptr );
i = 0;  fid = -1;
while ( fid == -1 && i <= SyStrlen(SyLibname) ) {
for ( k = i; SyLibname[k] != '\0' && SyLibname[k] != ';'; k++ )  ;
SyInitfiles[0][0] = '\0';
if ( sizeof(SyInitfiles[0]) < k-i+6+1 ) {
fputs("gap: <libname> is too long\n",stderr);
goto usage;
}
SyStrncat( SyInitfiles[0], SyLibname+i, k-i );
SyStrncat( SyInitfiles[0], "init.g", 6 );
if ( (fid = SyFopen( SyInitfiles[0], "r" )) != -1 )
SyFclose( fid );
i = k + 1;
}
if ( fid != -1 ) {
i = 1;
}
else {
i = 0;
SyInitfiles[0][0] = '\0';
if ( ! SyQuiet ) {
fputs("gap: hmm, I cannot find '",stderr);
fputs(SyLibname,stderr);
fputs("init.g', maybe use option '-l <libname>'?\n",stderr);
}
}
if ( gaprc ) {
#if SYS_BSD || SYS_MACH || SYS_USG
if ( getenv("HOME") != 0 ) {
SyInitfiles[i][0] = '\0';
SyStrncat(SyInitfiles[i],getenv("HOME"),sizeof(SyInitfiles[0])-1);
SyStrncat( SyInitfiles[i], "/.gaprc",
(long)(sizeof(SyInitfiles[0])-1-SyStrlen(SyInitfiles[i])));
if ( (fid = SyFopen( SyInitfiles[i], "r" )) != -1 ) {
++i;
SyFclose( fid );
}
else {
SyInitfiles[i][0] = '\0';
}
}
#endif
#if SYS_OS2_EMX || SYS_MSDOS_DJGPP || SYS_TOS_GCC2 || _WIN32
if ( getenv("HOME") != 0 ) {
SyInitfiles[i][0] = '\0';
SyStrncat(SyInitfiles[i],getenv("HOME"),sizeof(SyInitfiles[0])-1);
SyStrncat( SyInitfiles[i], "/gap.rc",
(long)(sizeof(SyInitfiles[0])-1-SyStrlen(SyInitfiles[i])));
if ( (fid = SyFopen( SyInitfiles[i], "r" )) != -1 ) {
++i;
SyFclose( fid );
}
else {
SyInitfiles[i][0] = '\0';
}
}
#endif
#if SYS_VMS
if ( getenv("GAP_INI") != 0 ) {
SyStrncat(SyInitfiles[i],getenv("GAP_INI"),sizeof(SyInitfiles[0])-1);
if ( (fid = SyFopen( SyInitfiles[i], "r" )) != -1 ) {
++i;
SyFclose( fid );
}
else {
SyInitfiles[i][0] = '\0';
}
}
#endif
#if SYS_MAC_MPW || SYS_MAC_SYC
SyInitfiles[i][0] = '\0';
SyStrncat( SyInitfiles[i], "gap.rc",
(long)(sizeof(SyInitfiles[0])-1-SyStrlen(SyInitfiles[i])));
if ( (fid = SyFopen( SyInitfiles[i], "r" )) != -1 ) {
++i;
SyFclose( fid );
}
else {
SyInitfiles[i][0] = '\0';
}
#endif
}
while ( argc > 1 ) {
if ( i >= sizeof(SyInitfiles)/sizeof(SyInitfiles[0]) ) {
fputs("gap: sorry, cannot handle so many init files.\n",stderr);
goto usage;
}
SyInitfiles[i][0] = '\0';
SyStrncat( SyInitfiles[i], argv[1], sizeof(SyInitfiles[0])-1 );
++i;
++argv;  --argc;
}
#if SYS_TOS_GCC2
if ( SyMemory <= 0 ) {
SyMemory = (long)_base->p_hitpa - (long)_base->p_lowtpa
- _base->p_tlen - _base->p_dlen - _base->p_blen
- _stksize - pre - 8192 + SyMemory;
}
#endif
#if SYS_VMS
smg$create_virtual_keyboard( &syVirKbd );
#endif
#if SYS_MAC_MPW || SYS_MAC_SYC
# ifndef SYS_HAS_TOOL
if ( SyMemory <= 0 ) {
SyMemory = MaxMem( &i ) - SyMemory - 384*1024;
if ( SyMemory < 1024*1024 ) {
fputs(
"gap: please use the 'Get Info' command in the Finder 'Desk' menu\n",
stderr );
fputs(
"     to set the minimum amount of memory to at least 2560 KByte,\n",
stderr );
fputs(
"     and the preferred amount of memory to 5632 KByte or more.\n",
stderr );
SyExit( 1 );
}
}
# endif
#endif
syStartTime = SyTime();
return;
usage:
fputs("usage: gap [-l <libname>] [-h <hlpname>] [-m <memory>]\n",stderr);
fputs("           [-g] [-n] [-q] [-b] [-x <nr>]  [-y <nr>]\n",stderr);
fputs("           <file>...\n",stderr);
fputs("  run the Groups, Algorithms and Programming system.\n",stderr);
SyExit( 1 );
}
/* 当前文件是D:\Read\tietze.c*/

#define    TZ_NUMGENS        1
#define    TZ_NUMRELS        2
#define    TZ_TOTAL          3
#define    TZ_GENERATORS     4
#define    TZ_INVERSES       5
#define    TZ_RELATORS       6
#define    TZ_LENGTHS        7
#define    TZ_FLAGS          8
#define    TZ_LENGTHTIETZE  20
TypHandle       TzRelExponent1 ( hdRel )
TypHandle           hdRel;
{
TypHandle           * ptRel;
long                leng;
long                exp;
long                i, j, ij;
ptRel = PTR( hdRel ) + 1;
leng = HD_TO_INT( ptRel[-1] );
exp = 1;
for ( i = 1; i <= leng/2; i++ ) {
if ( leng % i == 0 ) {
for ( j = 0, ij = i ; j < leng; j++, ij = ( ij + 1 ) % leng ) {
if ( ptRel[j] != ptRel[ij] )  break;
}
if ( j == leng ) {
exp = leng / i;
break;
}
}
}
return INT_TO_HD( exp );
}
TypHandle       FunTzRelator ( hdCall )
TypHandle           hdCall;
{
TypHandle           hdTie;
TypHandle           * ptTie;
TypHandle           hdGens;
TypHandle           * ptGens;
TypHandle           hdInvs;
TypHandle           * ptInvs;
TypHandle           hdWrd;
TypHandle           * ptWrd;
TypHandle           hdRel;
TypHandle           * ptRel;
TypHandle           * pt1, * pt2;
TypHandle           hdFac, hdGen;
long                numgens;
long                leng;
long                reduced;
long                i, j;
if ( SIZE(hdCall) != 3*SIZE_HD )
return Error( "usage: TzRelator(<Tietze stack>,<word>)", 0L, 0L );
hdTie = EVAL( PTR(hdCall)[1] );
if (TYPE(hdTie) != T_LIST || HD_TO_INT(PTR(hdTie)[0]) != TZ_LENGTHTIETZE)
return Error( "invalid <Tietze stack>", 0L, 0L );
ptTie = PTR( hdTie );
hdGens = ptTie[TZ_GENERATORS];
numgens = HD_TO_INT(ptTie[TZ_NUMGENS]);
if ( hdGens == 0
|| (TYPE(hdGens) != T_LIST && TYPE(hdGens) != T_SET)
|| HD_TO_INT(PTR(hdGens)[0]) != numgens )
return Error( "invalid Tietze generators list", 0L, 0L );
ptGens = PTR( hdGens );
for ( i = 1; i <= numgens; i++ ) {
if ( TYPE(ptGens[i]) == T_SWORD ) ptGens[i] = WordSword( ptGens[i] );
}
hdInvs = ptTie[TZ_INVERSES];
if ( hdInvs == 0
|| (TYPE(hdInvs) != T_LIST && TYPE(hdInvs) != T_VECTOR)
|| HD_TO_INT(PTR(hdInvs)[0]) != 2 * numgens + 1 )
return Error( "invalid Tietze inverses list", 0L, 0L );
hdWrd = EVAL( PTR(hdCall)[2] );
if ( TYPE(hdWrd) == T_SWORD ) hdWrd = WordSword( hdWrd );
if ( TYPE(hdWrd) != T_WORD )
return Error( "TzRelator: <word> must be a word", 0L, 0L );
leng = SIZE( hdWrd ) / SIZE_HD;
hdRel = NewBag( T_LIST, (leng + 1) * SIZE_HD );
ptGens = PTR( hdGens );
ptInvs = PTR( hdInvs ) + numgens + 1;
ptWrd = PTR( hdWrd );
ptRel = PTR( hdRel );
pt2 = ptRel;
for ( j = 0; j < leng; j++ ) {
if ( TYPE(ptWrd[j]) == T_SWORD ) ptWrd[j] = WordSword( ptWrd[j] );
hdFac = ptWrd[j];
for ( i = 1; i <= numgens; i++ ) {
hdGen = PTR( ptGens[i] )[0];
if ( hdFac == hdGen || hdFac == *PTR( hdGen ) )
break;
}
if ( i > numgens )
return HdFalse;
if ( hdFac != hdGen ) i = HD_TO_INT( ptInvs[i] );
if ( pt2 > ptRel && *pt2 == ptInvs[i] )
--pt2;
else
*++pt2 = INT_TO_HD( i );
}
pt1 = ++ptRel;
while ( pt1 < pt2 && *pt1 == ptInvs[HD_TO_INT(*pt2)] ) {
++pt1;  --pt2;
}
if ( ptRel < pt1 ) {
while ( pt1 <= pt2 )   *ptRel++ = *pt1++;
pt2 = --ptRel;
}
reduced = pt2 - PTR( hdRel );
if ( reduced < leng ) {
Resize( hdRel, ( reduced + 1 ) * SIZE_HD );
leng = reduced;
}
PTR( hdRel )[0] = INT_TO_HD( leng );
return hdRel;
}
TypHandle       FunTzWord ( hdCall )
TypHandle           hdCall;
{
TypHandle           hdTie;
TypHandle           * ptTie;
TypHandle           hdGens;
TypHandle           * ptGens;
TypHandle           hdRel;
TypHandle           * ptRel;
TypHandle           hdWrd;
TypHandle           * ptWrd;
long                numgens;
long                leng;
long                i, iabs, j;
if ( SIZE(hdCall) != 3*SIZE_HD )
return Error( "usage: TzWord(<Tietze stack>,<Tietze relator>)",
0L, 0L );
hdTie = EVAL( PTR(hdCall)[1] );
if (TYPE(hdTie) != T_LIST || HD_TO_INT(PTR(hdTie)[0]) != TZ_LENGTHTIETZE)
return Error( "invalid <Tietze stack>", 0L, 0L );
ptTie = PTR( hdTie );
hdGens = ptTie[TZ_GENERATORS];
numgens = HD_TO_INT(ptTie[TZ_NUMGENS]);
if ( hdGens == 0
|| (TYPE(hdGens) != T_LIST && TYPE(hdGens) != T_SET)
|| HD_TO_INT(PTR(hdGens)[0]) != numgens )
return Error( "invalid Tietze generators list", 0L, 0L );
hdRel = EVAL( PTR(hdCall)[2] );
if ( TYPE(hdRel) != T_LIST && TYPE(hdRel) != T_SET && TYPE(hdRel) !=
T_VECTOR ) return Error( "invalid <Tietze relator>", 0L, 0L );
ptRel = PTR( hdRel );
leng = HD_TO_INT(ptRel[0]);
hdWrd = NewBag( T_WORD, leng * SIZE_HD );
ptGens = PTR( hdGens );
ptRel = PTR( hdRel );
ptWrd = PTR( hdWrd );
for ( j = 0; j < leng; j++ ) {
i = HD_TO_INT( *++ptRel );
	if ( i < -numgens || numgens < i || !i )
return Error( "invalid <Tietze relator> entry [%d] = %d", j, i );
iabs = ( i > 0 ) ? i : -i;
if ( TYPE(ptGens[iabs]) == T_SWORD )
ptGens[iabs] = WordSword( ptGens[iabs] );
if ( TYPE(ptGens[iabs]) != T_WORD || SIZE(ptGens[iabs]) != SIZE_HD )
return Error( "invalid Tietze generator [%d]", iabs, 0L );
*ptWrd++ = ( i > 0 ) ?
PTR( ptGens[iabs] )[0] : *PTR( PTR( ptGens[iabs] )[0] );
}
return hdWrd;
}
TypHandle       FunTzSortC ( hdCall )
TypHandle           hdCall;
{
TypHandle           hdTie;
TypHandle           * ptTie;
TypHandle           hdRels;
TypHandle           * ptRels;
TypHandle           hdLens;
TypHandle           * ptLens;
TypHandle           hdFlags;
TypHandle           * ptFlags;
unsigned long       numrels;
unsigned long       i, h, k;
TypHandle           hdrel, hdlen;
TypHandle           hdflag;
if ( SIZE(hdCall) != 2*SIZE_HD )
return Error( "usage: TzSortC(<Tietze stack>)", 0L, 0L );
hdTie = EVAL( PTR(hdCall)[1] );
if (TYPE(hdTie) != T_LIST || HD_TO_INT(PTR(hdTie)[0]) != TZ_LENGTHTIETZE)
return Error( "invalid <Tietze stack>", 0L, 0L );
ptTie = PTR( hdTie );
hdRels = ptTie[TZ_RELATORS];
numrels = HD_TO_INT(ptTie[TZ_NUMRELS]);
if ( hdRels == 0
|| (TYPE(hdRels) != T_LIST && TYPE(hdRels) != T_SET)
|| HD_TO_INT(PTR(hdRels)[0]) != numrels )
return Error( "invalid Tietze relators list", 0L, 0L );
ptRels = PTR( hdRels );
hdLens = ptTie[TZ_LENGTHS];
if ( hdLens == 0
|| (TYPE(hdLens) != T_VECTOR && TYPE(hdLens) != T_LIST)
|| HD_TO_INT(PTR(hdLens)[0]) != numrels )
return Error( "invalid Tietze lengths list", 0L, 0L );
ptLens = PTR( hdLens );
hdFlags = ptTie[TZ_FLAGS];
if ( hdFlags == 0
|| (TYPE(hdFlags) != T_VECTOR && TYPE(hdFlags) != T_LIST)
|| HD_TO_INT(PTR(hdFlags)[0]) != numrels )
return Error( "invalid Tietze flags list", 0L, 0L );
ptFlags = PTR( hdFlags );
for ( i = 1; i <= numrels; i++ ) {
if ( ptRels[i] == 0
|| (TYPE(ptRels[i]) != T_LIST && TYPE(ptRels[i]) != T_SET
&& TYPE(ptRels[i]) != T_VECTOR)
|| HD_TO_INT(ptLens[i]) != HD_TO_INT(PTR(ptRels[i])[0]) )
return Error( "inconsistent Tietze lengths list", 0L, 0L );
}
h = 1;
while ( 9 * h + 4 < numrels ) h = 3 * h + 1;
while ( 0 < h ) {
for ( i = h + 1; i <= numrels; i++ ) {
hdrel = ptRels[i];  hdlen = ptLens[i];  hdflag = ptFlags[i];
k = i;
if ( HD_TO_INT(hdlen) ) {
while ( h < k
&& ( !HD_TO_INT(ptLens[k-h])
|| hdlen < ptLens[k-h]
|| (hdlen == ptLens[k-h] && hdflag > ptFlags[k-h]))) {
ptRels[k] = ptRels[k-h];
ptLens[k] = ptLens[k-h];
ptFlags[k] = ptFlags[k-h];
k = k - h;
}
}
ptRels[k] = hdrel;  ptLens[k] = hdlen;  ptFlags[k] = hdflag;
}
h = h / 3;
}
for ( i = numrels; i > 0; i-- ) {
if ( HD_TO_INT(ptLens[i]) )
break;
}
if ( i < numrels ) {
ptRels[0] = ptLens[0] = ptFlags[0] = ptTie[TZ_NUMRELS] =
INT_TO_HD ( i );
Resize( hdRels, ( i + 1 ) * SIZE_HD );
Resize( hdLens, ( i + 1 ) * SIZE_HD );
Resize( hdFlags, ( i + 1 ) * SIZE_HD );
}
return HdVoid;
}
TypHandle       FunTzRenumberGens ( hdCall )
TypHandle           hdCall;
{
TypHandle           hdTie;
TypHandle           * ptTie;
TypHandle           hdRels;
TypHandle           * ptRels;
TypHandle           hdInvs;
TypHandle           * ptInvs;
TypHandle           * ptRel;
long                numgens;
long                numrels;
long                old;
long                leng;
long                i, j;
if ( SIZE(hdCall) != 2*SIZE_HD )
return Error( "usage: TzRenumberGens(<Tietze stack>)", 0L, 0L );
hdTie = EVAL( PTR(hdCall)[1] );
if (TYPE(hdTie) != T_LIST || HD_TO_INT(PTR(hdTie)[0]) != TZ_LENGTHTIETZE)
return Error( "invalid <Tietze stack>", 0L, 0L );
ptTie = PTR( hdTie );
hdRels = ptTie[TZ_RELATORS];
numrels = HD_TO_INT(ptTie[TZ_NUMRELS]);
if ( hdRels == 0
|| (TYPE(hdRels) != T_LIST && TYPE(hdRels) != T_SET)
|| HD_TO_INT(PTR(hdRels)[0]) != numrels )
return Error( "invalid Tietze relators list", 0L, 0L );
ptRels = PTR( hdRels );
hdInvs = ptTie[TZ_INVERSES];
numgens = HD_TO_INT(ptTie[TZ_NUMGENS]);
if ( hdInvs == 0
|| (TYPE(hdInvs) != T_LIST && TYPE(hdInvs) != T_VECTOR)
|| HD_TO_INT(PTR(hdInvs)[0]) != 2 * numgens + 1 )
return Error( "invalid Tietze inverses list", 0L, 0L );
ptInvs = PTR( hdInvs ) + numgens + 1;
for ( i = 1; i <= numrels; i++ ) {
ptRel = PTR( ptRels[i] );
leng = HD_TO_INT( ptRel[0] );
for ( j = 1; j <= leng; j++ ) {
old = HD_TO_INT( ptRel[j] );
if ( old < -numgens || numgens < old || old == 0 )
return Error( "gen no. %d in rel no. %d out of range", j,i );
ptRel[j] = ptInvs[-old];
}
}
return HdVoid;
}
TypHandle       FunTzReplaceGens ( hdCall )
TypHandle           hdCall;
{
TypHandle           hdTie;
TypHandle           * ptTie;
TypHandle           hdRels;
TypHandle           * ptRels;
TypHandle           hdLens;
TypHandle           * ptLens;
TypHandle           hdFlags;
TypHandle           * ptFlags;
TypHandle           hdInvs;
TypHandle           * ptInvs;
TypHandle           hdRel;
TypHandle           * ptRel;
TypHandle           * pt1, * pt2;
long                numgens;
long                numrels;
long                total;
long                old, new;
long                leng, reduced;
long                altered;
long                i, j;
if ( SIZE(hdCall) != 2*SIZE_HD )
return Error( "usage: TzReplaceGens(<Tietze stack>)", 0L, 0L );
hdTie = EVAL( PTR(hdCall)[1] );
if (TYPE(hdTie) != T_LIST || HD_TO_INT(PTR(hdTie)[0]) != TZ_LENGTHTIETZE)
return Error( "invalid <Tietze stack>", 0L, 0L );
ptTie = PTR( hdTie );
hdRels = ptTie[TZ_RELATORS];
numrels = HD_TO_INT(ptTie[TZ_NUMRELS]);
if ( hdRels == 0
|| (TYPE(hdRels) != T_LIST && TYPE(hdRels) != T_SET)
|| HD_TO_INT(PTR(hdRels)[0]) != numrels )
return Error( "invalid Tietze relators list", 0L, 0L );
ptRels = PTR( hdRels );
hdLens = ptTie[TZ_LENGTHS];
if ( hdLens == 0
|| (TYPE(hdLens) != T_VECTOR && TYPE(hdLens) != T_LIST)
|| HD_TO_INT(PTR(hdLens)[0]) != numrels )
return Error( "invalid Tietze lengths list", 0L, 0L );
ptLens = PTR( hdLens );
total = 0;
for ( i = 1; i <= numrels; i++ ) {
if ( ptRels[i] == 0
|| (TYPE(ptRels[i]) != T_LIST && TYPE(ptRels[i]) != T_SET
&& TYPE(ptRels[i]) != T_VECTOR)
|| HD_TO_INT(ptLens[i]) != HD_TO_INT(PTR(ptRels[i])[0]) )
return Error( "inconsistent Tietze lengths list entry [%d]",
i, 0L );
total += HD_TO_INT(ptLens[i]);
}
if ( total != HD_TO_INT(ptTie[TZ_TOTAL]) )
return Error( "inconsistent total length", 0L, 0L );
hdFlags = ptTie[TZ_FLAGS];
if ( hdFlags == 0
|| (TYPE(hdFlags) != T_VECTOR && TYPE(hdFlags) != T_LIST)
|| HD_TO_INT(PTR(hdFlags)[0]) != numrels )
return Error( "invalid Tietze flags list", 0L, 0L );
ptFlags = PTR( hdFlags );
hdInvs = ptTie[TZ_INVERSES];
numgens = HD_TO_INT(ptTie[TZ_NUMGENS]);
if ( hdInvs == 0
|| (TYPE(hdInvs) != T_LIST && TYPE(hdInvs) != T_VECTOR)
|| HD_TO_INT(PTR(hdInvs)[0]) != 2 * numgens + 1 )
return Error( "invalid Tietze inverses list", 0L, 0L );
ptInvs = PTR( hdInvs ) + numgens + 1;
for ( i = 1; i <= numrels; i++ ) {
hdRel = ptRels[i];
pt2 = ptRel = PTR( hdRel );
leng = HD_TO_INT( ptLens[i] );
altered = 0;
if ( HD_TO_INT( ptFlags[i] ) == 3 && leng == 2 &&
ptRel[1] == ptInvs[-HD_TO_INT(ptRel[1])] ) {
continue;
}
for ( j = 1; j <= leng; j++ ) {
old = HD_TO_INT( ptRel[j] );
if ( old < -numgens || numgens < old || old == 0 )
return Error( "gen no. %d in rel no. %d out of range", j,i );
new = HD_TO_INT( ptInvs[-old] );
if ( !new ) {
altered = 1;
continue;
}
if ( pt2 > ptRel && *pt2 == ptInvs[new] ) {
altered = 1;
--pt2;
}
else {
if ( new != old )  { altered = 1; }
*++pt2 = INT_TO_HD( new );
}
}
if ( !altered ) { continue; }
pt1 = ++ptRel;
while ( pt1 < pt2 && *pt1 == ptInvs[HD_TO_INT(*pt2)] ) {
++pt1;  --pt2;
}
if ( ptRel < pt1 ) {
while ( pt1 <= pt2 )  { *ptRel++ = *pt1++; }
pt2 = --ptRel;
}
ptRel = PTR( hdRel );
reduced = pt2 - ptRel;
if ( reduced < leng ) {
ptRel[0] = INT_TO_HD( reduced );
ptLens[i] = INT_TO_HD( reduced );
total = total - leng + reduced;
Resize( hdRel, ( reduced + 1 ) * SIZE_HD );
ptRels = PTR( hdRels );
ptLens = PTR( hdLens );
ptFlags = PTR( hdFlags );
ptInvs = PTR( hdInvs ) + numgens + 1;
}
PTR( hdFlags )[i] = INT_TO_HD( 1 );
}
ptTie = PTR( hdTie );
ptTie[TZ_TOTAL] = INT_TO_HD( total );
return HdVoid;
}
TypHandle       FunTzSubstituteGen ( hdCall )
TypHandle           hdCall;
{
TypHandle           hdTie;
TypHandle           * ptTie;
TypHandle           hdRels;
TypHandle           * ptRels;
TypHandle           hdLens;
TypHandle           * ptLens;
TypHandle           hdFlags;
TypHandle           hdInvs;
TypHandle           * ptInvs;
TypHandle           hdWrd;
TypHandle           * ptWrd;
TypHandle           hdIwrd;
TypHandle           * ptIwrd;
TypHandle           hdNew;
TypHandle           * ptNew;
TypHandle           hdRel;
TypHandle           * ptRel;
TypHandle           * pt1, * pt2;
TypHandle           * pt3;
long                numgens;
long                numrels;
long                total;
long                given;
long                gen, ginv;
long                next;
long                leng, newleng;
long                wleng;
long                occ;
long                i, j;
if ( SIZE(hdCall) != 4*SIZE_HD ) return Error(
"usage: TzSubstituteGen(<Tietze stack>,<gen no.>,<Tietze word>)",
0L, 0L );
hdTie = EVAL( PTR(hdCall)[1] );
if (TYPE(hdTie) != T_LIST || HD_TO_INT(PTR(hdTie)[0]) != TZ_LENGTHTIETZE)
return Error( "invalid <Tietze stack>", 0L, 0L );
ptTie = PTR( hdTie );
hdRels = ptTie[TZ_RELATORS];
numrels = HD_TO_INT(ptTie[TZ_NUMRELS]);
if ( hdRels == 0
|| (TYPE(hdRels) != T_LIST && TYPE(hdRels) != T_SET)
|| HD_TO_INT(PTR(hdRels)[0]) != numrels )
return Error( "invalid Tietze relators list", 0L, 0L );
ptRels = PTR( hdRels );
hdLens = ptTie[TZ_LENGTHS];
if ( hdLens == 0
|| (TYPE(hdLens) != T_VECTOR && TYPE(hdLens) != T_LIST)
|| HD_TO_INT(PTR(hdLens)[0]) != numrels )
return Error( "invalid Tietze lengths list", 0L, 0L );
ptLens = PTR( hdLens );
hdFlags = ptTie[TZ_FLAGS];
if ( hdFlags == 0
|| (TYPE(hdFlags) != T_VECTOR && TYPE(hdFlags) != T_LIST)
|| HD_TO_INT(PTR(hdFlags)[0]) != numrels )
return Error( "invalid Tietze flags list", 0L, 0L );
hdInvs = ptTie[TZ_INVERSES];
numgens = HD_TO_INT(ptTie[TZ_NUMGENS]);
if ( hdInvs == 0
|| (TYPE(hdInvs) != T_LIST && TYPE(hdInvs) != T_VECTOR)
|| HD_TO_INT(PTR(hdInvs)[0]) != 2 * numgens + 1 )
return Error( "invalid Tietze inverses list", 0L, 0L );
ptInvs = PTR( hdInvs ) + numgens + 1;
given = HD_TO_INT( EVAL( PTR(hdCall)[2] ) );
gen = ( given > 0 ) ? given : -given;
if ( gen <= 0 || numgens < gen )
return Error( "generator number %d out of range", gen, 0L );
ginv = HD_TO_INT(ptInvs[gen]);
hdWrd = EVAL( PTR(hdCall)[3] );
if ( TYPE(hdWrd) != T_LIST && TYPE(hdWrd) != T_VECTOR )
return Error( "invalid replacing word", 0L, 0L );
ptWrd = PTR( hdWrd );
wleng = HD_TO_INT( ptWrd[0] );
for ( i = 1; i <= wleng; i++ ) {
next = HD_TO_INT( ptWrd[i] );
if ( next < -numgens || next == 0 || next > numgens )
return Error( "entry [%d] of <Tietze word> out of range", i,0L );
}
total = 0;
for ( i = 1; i <= numrels; i++ ) {
if ( ptRels[i] == 0
|| (TYPE(ptRels[i]) != T_LIST && TYPE(ptRels[i]) != T_SET
&& TYPE(ptRels[i]) != T_VECTOR)
|| HD_TO_INT(ptLens[i]) != HD_TO_INT(PTR(ptRels[i])[0]) )
return Error( "inconsistent Tietze lengths list", 0L, 0L );
total += HD_TO_INT(ptLens[i]);
}
if ( total != HD_TO_INT(ptTie[TZ_TOTAL]) )
return Error( "inconsistent total length", 0L, 0L );
hdIwrd = NewBag( T_LIST, (wleng + 1) * SIZE_HD );
ptRels = PTR( hdRels );
ptLens = PTR( hdLens );
ptInvs = PTR( hdInvs ) + numgens + 1;
ptWrd = PTR( hdWrd );
ptIwrd = PTR( hdIwrd );
ptIwrd[0] = INT_TO_HD( wleng );
pt1 = ptWrd;  pt2 = ptIwrd + wleng;
while ( pt2 > ptIwrd )
*pt2-- = ptInvs[HD_TO_INT(*++pt1)];
if ( given < 0 ) {
hdNew = hdWrd;  hdWrd = hdIwrd;  hdIwrd = hdNew;
ptWrd = PTR( hdWrd );  ptIwrd = PTR( hdIwrd );
}
for ( i = 1; i <= numrels; i++ ) {
hdRel = ptRels[i];
ptRel = PTR( hdRel );
leng = HD_TO_INT( ptLens[i] );
if ( leng == 0 )  { continue; }
occ = 0;
for ( j = 1; j <= leng; j++ ) {
next = HD_TO_INT( ptRel[j] );
if ( next < -numgens || numgens < next )
return Error( "gen no. %d in rel no. %d out of range", j,i );
if (next == gen || next == ginv ) ++occ;
}
if ( occ == 0 )  { continue; }
hdNew = NewBag( T_LIST, (leng + occ * (wleng - 1) + 1) * SIZE_HD );
ptLens = PTR( hdLens );
ptInvs = PTR( hdInvs ) + numgens + 1;
ptWrd = PTR( hdWrd );
ptIwrd = PTR( hdIwrd );
ptRel = PTR( hdRel );
pt2 = ptNew = PTR( hdNew );
for ( j = 1; j <= leng; j++ ) {
next = HD_TO_INT( ptRel[j] );
if ( next == gen || next == -gen ) {
pt1 = ( next > 0 ) ? ptWrd : ptIwrd;
pt3 = pt1 + wleng;
while ( pt1 < pt3 ) {
++pt1;
if ( pt2 > ptNew && *pt2 == ptInvs[HD_TO_INT(*pt1)] )
--pt2;
else
*++pt2 = *pt1;
}
}
else {
if ( pt2 > ptNew && *pt2 == ptInvs[next] )
--pt2;
else
*++pt2 = INT_TO_HD( next );
}
}
pt1 = ++ptNew;
while ( pt1 < pt2 && *pt1 == ptInvs[HD_TO_INT(*pt2)] ) {
++pt1;  --pt2;
}
if ( ptNew < pt1 ) {
while ( pt1 <= pt2 )   *ptNew++ = *pt1++;
pt2 = --ptNew;
}
ptNew = PTR( hdNew );
newleng = pt2 - ptNew;
ptNew[0] = INT_TO_HD( newleng );
ptLens[i] = INT_TO_HD( newleng );
total = total - leng + newleng;
Resize( hdNew, ( newleng + 1 ) * SIZE_HD );
ptRels = PTR( hdRels );
ptLens = PTR( hdLens );
ptRels[i] = hdNew;
PTR( hdFlags )[i] = INT_TO_HD( 1 );
}
ptTie = PTR( hdTie );
ptTie[TZ_TOTAL] = INT_TO_HD( total );
return HdVoid;
}
TypHandle       FunTzOccurrences ( hdCall )
TypHandle           hdCall;
{
TypHandle           hdTie;
TypHandle           * ptTie;
TypHandle           hdRels;
TypHandle           * ptRels;
TypHandle           hdRes;
TypHandle           hdCnts;
TypHandle           * ptCnts;
TypHandle           hdMins;
TypHandle           * ptMins;
TypHandle           hdLens;
TypHandle           * ptLens;
TypHandle           hdRel;
TypHandle           * ptRel;
TypHandle           hdAux;
long                * ptAux;
long                numgens;
long                numrels;
long                leng;
long                num, next;
long                i, k;
long                c;
long                nr;
long                nr1;
long                nrm;
long                min;
if ( SIZE(hdCall) != 2*SIZE_HD && SIZE(hdCall) != 3*SIZE_HD )
return Error("usage: TzOccurrences( <Tietze stack> [, <gen no.> ] )",
0L, 0L );
hdTie = EVAL( PTR(hdCall)[1] );
if (TYPE(hdTie) != T_LIST || HD_TO_INT(PTR(hdTie)[0]) != TZ_LENGTHTIETZE)
return Error( "invalid <Tietze stack>", 0L, 0L );
ptTie = PTR( hdTie );
numgens = HD_TO_INT(ptTie[TZ_NUMGENS]);
numrels = HD_TO_INT(ptTie[TZ_NUMRELS]);
hdRels = ptTie[TZ_RELATORS];
if ( hdRels == 0
|| (TYPE(hdRels) != T_LIST && TYPE(hdRels) != T_SET)
|| HD_TO_INT(PTR(hdRels)[0]) != numrels )
return Error( "invalid Tietze relators list", 0L, 0L );
ptRels = PTR( hdRels );
if ( SIZE(hdCall) == 3*SIZE_HD ) {
num = HD_TO_INT( EVAL( PTR(hdCall)[2] ) );
if ( num <= 0 || numgens < num )
return Error( "given generator number out of range", 0L, 0L );
numgens = 1;
}
else  num = numgens;
hdCnts = NewBag( T_LIST, SIZE_HD + numgens * SIZE_HD );
PTR(hdCnts)[0] = INT_TO_HD( numgens );
for ( k = 1; k <= numgens; k++ )
PTR(hdCnts)[k] = INT_TO_HD( 0 );
hdMins = NewBag( T_LIST, SIZE_HD + numgens * SIZE_HD );
PTR(hdMins)[0] = INT_TO_HD( 0 );
hdLens = NewBag( T_LIST, SIZE_HD + numgens * SIZE_HD );
PTR(hdLens)[0] = INT_TO_HD( 0 );
hdRes = NewBag( T_LIST, SIZE_HD + 3 * SIZE_HD );
PTR(hdRes)[0] = INT_TO_HD( 3 );
PTR(hdRes)[1] = hdCnts;
PTR(hdRes)[2] = hdMins;
PTR(hdRes)[3] = hdLens;
ptAux = 0;
if ( numgens > 1 ) {
hdAux = NewBag( T_STRING, ( numgens + 1 ) * sizeof( long ) );
ptAux = (long*)PTR(hdAux);
ptAux[0] = numgens;
for ( k = 1; k <= numgens; k++ )
ptAux[k] = 0;
}
ptRels = PTR(hdRels);
ptCnts = PTR(hdCnts);
ptLens = PTR(hdLens);
ptMins = PTR(hdMins);
if ( numgens == 1 ) {
nr = 0;  nrm = 0;  min = 0;
for ( i = 1; i <= numrels; i++ ) {
hdRel = ptRels[i];
if ( hdRel == 0
|| (TYPE(hdRel) != T_LIST && TYPE(hdRel) != T_SET
&& TYPE(hdRel) != T_VECTOR) )
return Error("invalid entry [%d] in Tietze relators list",
i,0L);
ptRel = PTR(hdRel);
leng = HD_TO_INT( ptRel[0] );
nr1 = 0;
for ( k = 1; k <= leng; k++ ) {
next = HD_TO_INT( ptRel[k] );
if ( next == num || next == -num )  { nr1++; }
}
nr += nr1;
if ( nrm == 0
|| (0 < nr1 && nr1 < nrm)
|| (nr1 == nrm && SIZE(hdRel) < SIZE(ptRels[min])) ) {
nrm = nr1;  min = i;
}
}
ptCnts[1] = INT_TO_HD( nr );
if ( nr != 0 ) {
ptCnts[1] = INT_TO_HD( nr );
ptLens[0] = INT_TO_HD( 1 );  ptLens[1] = INT_TO_HD( nrm );
ptMins[0] = INT_TO_HD( 1 );  ptMins[1] = INT_TO_HD( min );
}
}
else {
for ( i = 1; i <= numrels; i++ ) {
hdRel = ptRels[i];
if ( hdRel == 0
|| (TYPE(hdRel) != T_LIST && TYPE(hdRel) != T_SET
&& TYPE(hdRel) != T_VECTOR) )
return Error("invalid entry [%d] in Tietze relators list",
i,0L);
ptRel = PTR(hdRel);
leng = HD_TO_INT( ptRel[0] );
for ( k = 1; k <= leng; k++ ) {
next = HD_TO_INT( ptRel[k] );
if ( next < 0 ) next = -next;
if ( next == 0 || numgens < next ) return Error(
"invalid entry [%d][%d] in Tietze relators list",i,k );
(ptAux[next])++;
}
for ( k = 1; k <= numgens; k++ ) {
c = ptAux[k];
if ( !c )  continue;
ptAux[k] = 0;
ptCnts[k] = INT_TO_HD( HD_TO_INT( ptCnts[k] ) + c );
if ( (0 < c && ptLens[k] == 0)
|| (0 < c && c < HD_TO_INT(ptLens[k]))
|| (0 < c && c == HD_TO_INT(ptLens[k])
&& SIZE(hdRel) < SIZE(ptRels[HD_TO_INT(ptMins[k])])) ) {
ptLens[k] = INT_TO_HD( c );
ptMins[k] = INT_TO_HD( i );
}
}
}
k = numgens;
while ( ptMins[k] == 0 )  k--;
PTR(hdMins)[0] = INT_TO_HD( k );
PTR(hdLens)[0] = INT_TO_HD( k );
}
return hdRes;
}
TypHandle       FunTzOccurrencesPairs ( hdCall )
TypHandle           hdCall;
{
TypHandle           hdTie;
TypHandle           * ptTie;
TypHandle           hdRels;
TypHandle           * ptRels;
TypHandle           hdInvs;
TypHandle           * ptInvs;
TypHandle           hdRes;
TypHandle           * ptRes;
TypHandle           hdRel;
TypHandle           * ptRel;
TypHandle           hdNum;
TypHandle           hdInv;
long                num, i, ii;
long                numgens;
long                numrels;
long                length;
long                j1, j2, r;
if ( SIZE(hdCall) != 3*SIZE_HD && SIZE(hdCall) != 4*SIZE_HD ) return
Error(
"usage: TzOccurrencesPairs( <Tietze stack>, <gen> [, <list> ] )",
0L, 0L );
hdTie = EVAL( PTR(hdCall)[1] );
if (TYPE(hdTie) != T_LIST || HD_TO_INT(PTR(hdTie)[0]) != TZ_LENGTHTIETZE)
return Error( "invalid <Tietze stack>", 0L, 0L );
ptTie = PTR( hdTie );
hdRels = ptTie[TZ_RELATORS];
numrels = HD_TO_INT(ptTie[TZ_NUMRELS]);
if ( hdRels == 0
|| (TYPE(hdRels) != T_LIST && TYPE(hdRels) != T_SET)
|| HD_TO_INT(PTR(hdRels)[0]) != numrels )
return Error( "invalid Tietze relators list", 0L, 0L );
hdInvs = ptTie[TZ_INVERSES];
numgens = HD_TO_INT(ptTie[TZ_NUMGENS]);
if ( hdInvs == 0
|| (TYPE(hdInvs) != T_LIST && TYPE(hdInvs) != T_VECTOR)
|| HD_TO_INT(PTR(hdInvs)[0]) != 2 * numgens + 1 )
return Error( "invalid Tietze inverses list", 0L, 0L );
hdNum = EVAL( PTR(hdCall)[2] );
if ( TYPE(hdNum) != T_INT )
return Error( "<gen> must be a Tietze generator number", 0L, 0L );
num = HD_TO_INT( hdNum );
if ( num <= 0 || num > numgens )
return Error( "given generator number is out of range", 0L, 0L );
if ( SIZE(hdCall) == 3* SIZE_HD ) {
hdRes = NewBag( T_LIST, SIZE_HD + 4 * numgens * SIZE_HD );
PTR( hdRes )[0] = INT_TO_HD( 4 * numgens );
}
else {
hdRes = EVAL( PTR(hdCall)[3] );
if ( hdRes == 0
|| (TYPE(hdRes) != T_LIST && TYPE(hdRes) != T_VECTOR)
|| HD_TO_INT(PTR(hdRes)[0]) != 4 * numgens )
return Error(
"<list> must be a list of length 4 * number of generators",
0L, 0L );
}
if ( num == numgens )  { return hdRes; }
ptRels = PTR( hdRels );
ptInvs = PTR( hdInvs ) + numgens + 1;
ptRes = PTR( hdRes );
hdInv = ptInvs[num];
for ( i = 1; i <= 4 * numgens; i++ ) {
ptRes[i] = INT_TO_HD( 0 );
}
for ( r = 1; r <= numrels; r++ ) {
hdRel = ptRels[r];
if ( hdRel == 0
|| (TYPE(hdRel) != T_LIST && TYPE(hdRel) != T_SET
&& TYPE(hdRel) != T_VECTOR) )
return Error( "invalid Tietze relator [%d]", 0L, 0L );
ptRel = PTR( hdRel ) + 1;
length = HD_TO_INT( ptRel[-1] );
if ( length < 2 )  { continue; }
j1 = ( length - 1 ) % length;
for ( j2 = 0; j2 < length; j1 = j2, j2++ ) {
if ( ptRel[j1] == hdNum || ptRel[j1] == hdInv ) {
i = HD_TO_INT( ptRel[j2] );
if ( -num <= i && i <= num )  { continue; }
	        if ( i < - numgens || numgens < i ) return Error(
"invalid entry %d in <Tietze relator> [%d]", i, r );
if ( i < 0 ) i = numgens - i;
if ( ptRel[j1] != hdNum ) i = i + 2 * numgens;
ptRes[i] = INT_TO_HD( HD_TO_INT( ptRes[i] ) + 1 );
}
else if ( ptRel[j2] == hdNum || ptRel[j2] == hdInv ) {
i = HD_TO_INT( ptRel[j1] );
if ( -num <= i && i <= num )  { continue; }
	        if ( i < - numgens || numgens < i ) return Error(
"invalid entry %d in <Tietze relator> [%d]", i, r );
ii = HD_TO_INT( ptInvs[i] );
if ( !( (hdNum == hdInv
&& ptRel[(j2+1)%length] == INT_TO_HD(ii))
|| (i == ii
&& ptInvs[HD_TO_INT(ptRel[(j1+length-1)%length])]
== ptRel[j2]) ) ) {
if ( ii < 0 ) ii = numgens - ii;
if ( ptRel[j2] != hdInv ) ii = ii + 2 * numgens;
ptRes[ii] = INT_TO_HD( HD_TO_INT( ptRes[ii] ) + 1 );
}
}
}
}
return hdRes;
}
TypHandle       FunTzSearchC ( hdCall )
TypHandle           hdCall;
{
TypHandle           hdTie;
TypHandle           * ptTie;
TypHandle           hdRels;
TypHandle           * ptRels;
TypHandle           hdLens;
TypHandle           * ptLens;
TypHandle           hdInvs;
TypHandle           * ptInvs;
TypHandle           hdFlags;
TypHandle           * ptFlags;
TypHandle           hdWrd;
TypHandle           hdl;
TypHandle           hdw;
TypHandle           hdPos1;
TypHandle           hdPos2;
TypHandle           hdEqu;
char                keys1[8192], keys2[8192], keys3[8192];
unsigned long       inv;
unsigned long       key;
long                numgens;
long                numrels;
long                total;
TypHandle           * ptr;
TypHandle           * v,  * w;
TypHandle           * ptx,  * pty;
long                i1, j1;
long                i2, j2;
long                i3, j3;
long                len1;
long                lmin, lmax;
long                pos1, pos2;
long                xmax;
long                newflag, flag1;
long                xflag, yflag;
long                xlen, xlen1;
long                mlen;
long                ylen, ylen1;
long                newlen;
long                n, m;
long                count;
long                i, j, jj, x, y;
long                lasty;
long                altered;
long                equal;
if ( SIZE(hdCall) != 4*SIZE_HD && SIZE(hdCall) != 5*SIZE_HD )
return Error(
"usage: TzSearchC( <Tietze stack>, <pos1>, <pos1> [,<equal>] )",
0L, 0L );
hdTie = EVAL( PTR(hdCall)[1] );
if (TYPE(hdTie) != T_LIST || HD_TO_INT(PTR(hdTie)[0]) != TZ_LENGTHTIETZE)
return Error( "invalid <Tietze stack>", 0L, 0L );
ptTie = PTR( hdTie );
hdRels = ptTie[TZ_RELATORS];
numrels = HD_TO_INT(ptTie[TZ_NUMRELS]);
if ( hdRels == 0
|| (TYPE(hdRels) != T_LIST && TYPE(hdRels) != T_SET)
|| HD_TO_INT(PTR(hdRels)[0]) != numrels )
return Error( "invalid Tietze relators list", 0L, 0L );
ptRels = PTR( hdRels );
hdLens = ptTie[TZ_LENGTHS];
if ( hdLens == 0
|| (TYPE(hdLens) != T_VECTOR && TYPE(hdLens) != T_LIST)
|| HD_TO_INT(PTR(hdLens)[0]) != numrels )
return Error( "invalid Tietze lengths list", 0L, 0L );
ptLens = PTR( hdLens );
hdFlags = ptTie[TZ_FLAGS];
if ( hdFlags == 0
|| (TYPE(hdFlags) != T_VECTOR && TYPE(hdFlags) != T_LIST)
|| HD_TO_INT(PTR(hdFlags)[0]) != numrels )
return Error( "invalid Tietze flags list", 0L, 0L );
ptFlags = PTR( hdFlags );
total = 0;
for ( i = 1; i <= numrels; i++ ) {
if ( ptRels[i] == 0
|| (TYPE(ptRels[i]) != T_LIST && TYPE(ptRels[i]) != T_SET
&& TYPE(ptRels[i]) != T_VECTOR)
|| HD_TO_INT(ptLens[i]) != HD_TO_INT(PTR(ptRels[i])[0]) )
return Error( "inconsistent Tietze lengths list entry [%d]",
i, 0L );
total += HD_TO_INT(ptLens[i]);
}
if ( total != HD_TO_INT(ptTie[TZ_TOTAL]) )
return Error( "inconsistent total length", 0L, 0L );
hdInvs = ptTie[TZ_INVERSES];
numgens = HD_TO_INT(ptTie[TZ_NUMGENS]);
if ( hdInvs == 0
|| (TYPE(hdInvs) != T_LIST && TYPE(hdInvs) != T_VECTOR)
|| HD_TO_INT(PTR(hdInvs)[0]) != 2 * numgens + 1 )
return Error( "invalid Tietze inverses list", 0L, 0L );
ptInvs = PTR( hdInvs ) + numgens + 1;
hdPos1 = EVAL( PTR(hdCall)[2] );
if ( TYPE(hdPos1) != T_INT )
return Error( "<position1> must be a posititve int", 0L ,0L );
pos1 = HD_TO_INT( hdPos1 );
if ( pos1 > numrels )
return Error( "<position1> not in range: %d", pos1, 0L );
hdPos2 = EVAL( PTR(hdCall)[3] );
if ( TYPE(hdPos2) != T_INT )
return Error( "<position2> must be a posititve int", 0L, 0L );
pos2 = HD_TO_INT( hdPos2 );
if ( pos2 > numrels )
return Error( "<position2> not in range: %d", pos2, 0L );
hdEqu = (SIZE(hdCall)==4*SIZE_HD) ? HdFalse : EVAL(PTR(hdCall)[4]);
if ( TYPE(hdEqu) != T_BOOL )
return Error( "<equal> must be false or true", 0L, 0L );
equal = ( hdEqu == HdTrue );
while ( pos1 <= pos2
&& (HD_TO_INT( ptLens[pos1] ) < 2
|| HD_TO_INT( ptFlags[pos1] ) > 1
|| (equal && ( HD_TO_INT( ptLens[pos1] ) < 4
|| HD_TO_INT( ptLens[pos1] ) % 2 == 1 ) ) ) )
pos1++;
if ( pos1 > pos2 || pos1 == numrels )  { return INT_TO_HD( 0 ); }
len1 = HD_TO_INT( ptLens[pos1] );
lmin = len1 - ( len1 % 2 );
lmax = ( equal ) ? lmin : lmin + 1;
newflag = ( equal ) ? 1 : 2;
count = 0;
lasty = 0;
xmax = pos1 - 1;
flag1 = HD_TO_INT( ptFlags[pos1] );
mlen = equal ? ( lmin + 1 ) / 2 : lmin / 2 + 1;
inv = 1;
for ( i = 1; i <= mlen; i++ )
inv = 109109 * inv;
for ( i = 0; i < 2048; i++ )
((unsigned long *)keys1)[i] =
((unsigned long *)keys2)[i] =
((unsigned long *)keys3)[i] = 0;
for ( y = pos1; y < numrels; ) {
hdWrd = ptRels[y];
ylen = HD_TO_INT( ptLens[y] );
yflag = HD_TO_INT( ptFlags[y] );
if ( y <= pos2 && lmin <= ylen && ylen <= lmax && yflag <= 1 ) {
ptr = PTR(hdWrd);
key = 0;
for ( i = 0, w = ptr+1; i < mlen; i++, w++ )
key = 109109 * key + ( (unsigned long)*w >> 2 );
for ( i = 0, v = ptr+1, w = v+mlen; i < ylen; i++, v++, w++ ) {
keys1[ key & 8191 ] = 1;
keys2[ (key >> 11) & 8191 ] |= (1 << ((key >> 8) & 7));
keys3[ (key >> 19) & 8191 ] |= (1 << ((key >> 16) & 7));
if ( i == ylen-mlen )  w = ptr+1;
key = 109109 * key - inv * ( (unsigned long)*v >> 2 )
+ ( (unsigned long)*w >> 2 );
}
key = 0;
for ( i = 0, w = ptr+ylen; i < mlen; i++, w-- ) {
key = 109109 * key
+ ( (unsigned long) ptInvs[HD_TO_INT(*w)] >> 2 );
}
for ( i = 0, v = ptr+ylen, w = v-mlen; i < ylen; i++, v--, w-- ) {
keys1[ key & 8191 ] = 1;
keys2[ (key >> 11) & 8191 ] |= (1 << ((key >> 8) & 7));
keys3[ (key >> 19) & 8191 ] |= (1 << ((key >> 16) & 7));
if ( i == ylen-mlen )  w = ptr+ylen;
key = 109109 * key
- inv * ( (unsigned long) ptInvs[HD_TO_INT(*v)] >> 2 )
+ ( (unsigned long) ptInvs[HD_TO_INT(*w)] >> 2 );
}
if ( len1 > ylen ) len1 = ylen;
if ( flag1 < yflag ) flag1 = yflag;
xmax = y;
}
y++;
hdl = ptRels[y];
ylen = HD_TO_INT( ptLens[y] );
yflag = HD_TO_INT( ptFlags[y] );
ylen1 = ylen - 1;
altered = 0;
if ( y > lasty
&& (ylen < len1 || yflag > 1 || (!equal && !(yflag + flag1)) ) )
continue;
lasty = y;
ptr = PTR(hdl);
key = 0;
for ( j = 0, w = ptr+1; j < mlen; j++, w++ )
key = 109109 * key + ( (unsigned long)*w >> 2 );
for ( j = 0; j < ylen; j++ ) {
if ( keys1[ key & 8191 ]
&& (keys2[ (key >> 11) & 8191 ] & (1 << ((key >> 8) & 7)))
&& (keys3[ (key >> 19) & 8191 ] & (1 << ((key >> 16) & 7))) ){
for ( x = pos1; x <= xmax; x++ ) {
hdw = ptRels[x];
xlen = HD_TO_INT( ptLens[x] );
xflag = HD_TO_INT( ptFlags[x] );
if ( xlen < len1 || xlen > lmax || xlen > ylen
|| xflag > 1 || (!equal && !( xflag + yflag )) )
continue;
xlen1 = xlen - 1;
ptx = PTR(hdw) + 1;
pty = PTR(hdl) + 1;
for ( i = 0; i < xlen; i++ ) {
i2 = i;  j2 = j;
for ( n = 0; n < xlen; n++,
i2 = (i2 == xlen1) ? 0 : i2 + 1,
j2 = (j2 == ylen1) ? 0 : j2 + 1 ) {
if ( ptx[i2] != pty[j2] )  break;
}
if ( n < mlen )  continue;
i1 = (i == 0) ? xlen1 : i - 1;
j1 = (j == 0) ? ylen1 : j - 1;
for ( ; n < xlen; n++,
i1 = (i1 == 0) ? xlen1 : i1 - 1,
j1 = (j1 == 0) ? ylen1 : j1 - 1 ) {
if ( ptx[i1] != pty[j1] )  break;
}
if ( n == xlen - n ) {
j2 = j;
for ( m = 0; m < n; m++,
i1 = (i1 == 0) ? xlen1 : i1 - 1,
j2 = (j2 == ylen1) ? 0 : j2 + 1 ) {
pty[j2] = ptInvs[HD_TO_INT(ptx[i1])];
}
i3 = (i + n) % xlen;
for ( jj = 0; jj <= ylen - n; jj++ ) {
i2 = i;  j2 = jj;
for ( m = 0; m < n; m++,
i2 = (i2 == xlen1) ? 0 : i2 + 1,
j2 = (j2 == ylen1) ? 0 : j2 + 1 ) {
if ( ptx[i2] != pty[j2] )
break;
}
if ( m < n )  continue;
i1 = (i == 0) ? xlen1 : i - 1;
if ( ptx[i1] == pty[(jj + ylen1) % ylen] ||
ptx[i3] == pty[(jj + n) % ylen] )
continue;
j2 = jj;
for ( m = 0; m < n; m++,
i1 = (i1 == 0) ? xlen1 : i1 - 1,
j2 = (j2 == ylen1) ? 0 : j2 + 1 ) {
pty[j2] = ptInvs[HD_TO_INT(ptx[i1])];
}
jj = -1;
}
ptFlags[y] = INT_TO_HD( newflag );
altered = 1;
++count;
break;
}
m = ylen - n;  n = xlen - n;
if ( n == 0 ) {
for ( ; 1 < m; m -= 2,
j1 = (j1 == 0) ? ylen1 : j1 - 1,
j2 = (j2 == ylen1) ? 0 : j2 + 1 ) {
if ( pty[j1] != ptInvs[HD_TO_INT(pty[j2])] )
break;
}
}
newlen = m + n;
if ( j2 > 0 ) {
if ( j2 <= j1 )  { jj = 0;  j3 = j1;  j1 = m - 1; }
else  { jj = j1 + n + 1;  j3 = ylen - 1; }
for ( ; j2 <= j3; ) {
pty[jj++] = pty[j2++];
}
}
for ( ; n > 0; n--, i1 = (i1 == 0) ? xlen1 : i1 - 1 ) {
pty[++j1] = ptInvs[HD_TO_INT(ptx[i1])];
}
pty[-1] = INT_TO_HD( newlen );
ptLens[y] = INT_TO_HD( newlen );
total = total - ylen + newlen;
ptFlags[y] = INT_TO_HD( newflag );
Resize( hdl, (newlen + 1) * SIZE_HD );
ptRels = PTR( hdRels );
ptLens = PTR( hdLens );
ptFlags = PTR( hdFlags);
ptInvs = PTR( hdInvs ) + numgens + 1;
altered = 1;
++count;
--y;
break;
}
if ( altered ) break;
for ( i = 0; i < xlen; i++ ) {
i2 = xlen1 - i;  j2 = j;
for ( n = 0; n < xlen; n++,
i2 = (i2 == 0) ? xlen1 : i2 - 1,
j2 = (j2 == ylen1) ? 0 : j2 + 1 ) {
if ( ptInvs[HD_TO_INT(ptx[i2])] != pty[j2] )
break;
}
if ( n < mlen )  continue;
i1 = (i == 0) ? 0 : xlen - i;
j1 = (j == 0) ? ylen1 : j - 1;
for ( ; n < xlen; n++,
i1 = (i1 == xlen1) ? 0 : i1 + 1,
j1 = (j1 == 0) ? ylen1 : j1 - 1 ) {
if ( ptInvs[HD_TO_INT(ptx[i1])] != pty[j1] )
break;
}
if ( n == xlen - n ) {
j2 = j;
for ( m = 0; m < n; m++,
i1 = (i1 == xlen1) ? 0 : i1 + 1,
j2 = (j2 == ylen1) ? 0 : j2 + 1 ) {
pty[j2] = ptx[i1];
}
ptFlags[y] = INT_TO_HD( newflag );
altered = 1;
++count;
break;
}
m = ylen - n;  n = xlen - n;
if ( n == 0 ) {
for ( ; 1 < m; m -= 2,
j1 = (j1 == 0) ? ylen1 : j1 - 1,
j2 = (j2 == ylen1) ? 0 : j2 + 1 ) {
if ( pty[j1] != ptInvs[HD_TO_INT(pty[j2])] )
break;
}
}
newlen = m + n;
if ( j2 > 0 ) {
if ( j2 <= j1 )  { jj = 0;  j3 = j1;  j1 = m - 1; }
else  { jj = j1 + n + 1;  j3 = ylen - 1; }
for ( ; j2 <= j3; ) {
pty[jj++] = pty[j2++];
}
}
for ( ; n > 0; n--, i1 = (i1 == xlen1) ? 0 : i1 + 1 ) {
pty[++j1] = ptx[i1];
}
pty[-1] = INT_TO_HD( newlen );
ptLens[y] = INT_TO_HD( newlen );
total = total - ylen + newlen;
ptFlags[y] = INT_TO_HD( newflag );
Resize( hdl, (newlen + 1) * SIZE_HD );
ptRels = PTR( hdRels );
ptLens = PTR( hdLens );
ptFlags = PTR( hdFlags);
ptInvs = PTR( hdInvs ) + numgens + 1;
altered = 1;
++count;
--y;
break;
}
if ( altered ) break;
}
}
if ( altered ) break;
v = ptr + 1 + j;  w = ptr + 1 + ( j + mlen ) % ylen;
key = 109109 * key - inv * ( (unsigned long)*v >> 2 )
+ ( (unsigned long)*w >> 2 );
}
}
PTR( hdTie )[TZ_TOTAL] = INT_TO_HD( total );
return INT_TO_HD( count );
}
void            InitTietze ()
{
InstIntFunc( "TzRelator",           FunTzRelator          );
InstIntFunc( "TzWord",              FunTzWord             );
InstIntFunc( "TzSortC",             FunTzSortC            );
InstIntFunc( "TzRenumberGens",      FunTzRenumberGens     );
InstIntFunc( "TzReplaceGens",       FunTzReplaceGens      );
InstIntFunc( "TzSubstituteGen",     FunTzSubstituteGen    );
InstIntFunc( "TzOccurrences",       FunTzOccurrences      );
InstIntFunc( "TzOccurrencesPairs",  FunTzOccurrencesPairs );
InstIntFunc( "TzSearchC",           FunTzSearchC          );
}
/* 当前文件是D:\Read\unknown.c*/

long            LargestUnknown;
TypHandle       EvUnknown ( hdUnk )
TypHandle           hdUnk;
{
return hdUnk;
}
TypHandle       NewUnknown ()
{
TypHandle           hdUnk;
LargestUnknown++;
hdUnk = NewBag( T_UNKNOWN, sizeof(long) );
((long*)PTR(hdUnk))[0] = LargestUnknown;
return hdUnk;
}
TypHandle       SumUnknown ( hdL, hdR )
TypHandle           hdL, hdR;
{
if ( hdL == INT_TO_HD(0) )
return hdR;
else if ( hdR == INT_TO_HD(0) )
return hdL;
else
return NewUnknown();
}
TypHandle       DiffUnknown ( hdL, hdR )
TypHandle           hdL, hdR;
{
if ( hdR == INT_TO_HD(0) )
return hdL;
else if ( TYPE(hdL) == T_UNKNOWN && TYPE(hdR) == T_UNKNOWN
&& ((long*)PTR(hdL))[0] == ((long*)PTR(hdR))[0] )
return INT_TO_HD(0);
else
return NewUnknown();
}
TypHandle       ProdUnknown ( hdL, hdR )
TypHandle           hdL, hdR;
{
if ( hdL == INT_TO_HD(0) || hdR == INT_TO_HD(0) )
return INT_TO_HD(0);
else if ( hdL == INT_TO_HD(1) )
return hdR;
else if ( hdR == INT_TO_HD(1) )
return hdL;
else
return NewUnknown();
}
TypHandle       QuoUnknown ( hdL, hdR )
TypHandle           hdL, hdR;
{
if ( hdR == INT_TO_HD(0) )
return Error("divisor must be nonzero",0L,0L);
else if ( TYPE(hdR) == T_UNKNOWN )
return Error("divisor must no be unknown (could be zero)",0L,0L);
else if ( hdR == INT_TO_HD(1) )
return hdL;
else
return NewUnknown();
}
TypHandle       PowUnknown ( hdL, hdR )
TypHandle           hdL, hdR;
{
if ( hdR == INT_TO_HD(0) )
return INT_TO_HD(1);
else if ( HD_TO_INT(hdR) < 0 )
return Error("divisor must not be unknown (could be zero)",0L,0L);
else
return NewUnknown();
}
TypHandle       EqUnknown ( hdL, hdR )
TypHandle           hdL, hdR;
{
if ( ((long*)PTR(hdL))[0] == ((long*)PTR(hdR))[0] )
return HdTrue;
else
return HdFalse;
}
TypHandle       LtUnknown ( hdL, hdR )
TypHandle           hdL, hdR;
{
if ( ((long*)PTR(hdL))[0] < ((long*)PTR(hdR))[0] )
return HdTrue;
else
return HdFalse;
}
void            PrUnknown ( hdUnk )
TypHandle           hdUnk;
{
Pr("%>Unknown(%d)%<",((long*)PTR(hdUnk))[0],0L);
}
TypHandle       FunUnknown ( hdCall )
TypHandle           hdCall;
{
TypHandle           hdUnk;
long                n;
if ( SIZE(hdCall) != SIZE_HD && SIZE(hdCall) != 2*SIZE_HD )
return Error("usage: Unknown() or Unknown(<n>)",0L,0L);
if ( SIZE(hdCall) == 2 * SIZE_HD ) {
hdUnk = EVAL( PTR(hdCall)[1] );
if ( TYPE(hdUnk) != T_INT || HD_TO_INT(hdUnk) <= 0 )
return Error("Unknown: <n> must be a positive integer",0L,0L);
n = HD_TO_INT(hdUnk);
if ( LargestUnknown < n )  LargestUnknown = n;
}
else {
LargestUnknown++;
n = LargestUnknown;
}
hdUnk = NewBag( T_UNKNOWN, sizeof(long) );
((long*)PTR(hdUnk))[0] = n;
return hdUnk;
}
TypHandle       FunIsUnknown ( hdCall )
TypHandle           hdCall;
{
TypHandle           hdObj;
if ( SIZE(hdCall) != 2 * SIZE_HD )
return Error("usage: IsUnknown( <obj> )",0L,0L);
hdObj = EVAL( PTR(hdCall)[1] );
if ( hdObj == HdVoid )
return Error("IsUnknown: function must return a value",0L,0L);
if ( TYPE(hdObj) == T_UNKNOWN )
return HdTrue;
else
return HdFalse;
}
void            InitUnknown ()
{
unsigned int        type;
InstEvFunc( T_UNKNOWN, EvUnknown );
InstPrFunc( T_UNKNOWN, PrUnknown );
for ( type = T_INT; type <= T_UNKNOWN; type++ ) {
TabSum[  type ][ T_UNKNOWN ] = SumUnknown;
TabSum[  T_UNKNOWN ][ type ] = SumUnknown;
TabDiff[ type ][ T_UNKNOWN ] = DiffUnknown;
TabDiff[ T_UNKNOWN ][ type ] = DiffUnknown;
TabProd[ type ][ T_UNKNOWN ] = ProdUnknown;
TabProd[ T_UNKNOWN ][ type ] = ProdUnknown;
TabQuo[  type ][ T_UNKNOWN ] = QuoUnknown;
TabQuo[  T_UNKNOWN ][ type ] = QuoUnknown;
}
TabPow[ T_UNKNOWN ][ T_INT ] = PowUnknown;
TabEq[ T_UNKNOWN ][ T_UNKNOWN ] = EqUnknown;
TabLt[ T_UNKNOWN ][ T_UNKNOWN ] = LtUnknown;
InstIntFunc( "Unknown",   FunUnknown   );
InstIntFunc( "IsUnknown", FunIsUnknown );
}
/* 当前文件是D:\Read\vecffe.c*/

long            LenVecFFE ( hdList )
TypHandle           hdList;
{
return LEN_VECFFE( hdList );
}
TypHandle       ElmVecFFE ( hdList, pos )
TypHandle           hdList;
long                pos;
{
TypHandle           hdElm;
if ( LEN_VECFFE( hdList ) < pos ) {
return Error(
"List Element: <list>[%d] must have a value",
pos, 0L );
}
hdElm = NewBag( T_FFE, SIZE_HD + sizeof(TypFFE) );
ELM_VECFFE( hdList, pos, hdElm );
return hdElm;
}
TypHandle       ElmfVecFFE ( hdList, pos )
TypHandle           hdList;
long                pos;
{
TypHandle           hdElm;
hdElm = NewBag( T_FFE, SIZE_HD + sizeof(TypFFE) );
ELM_VECFFE( hdList, pos, hdElm );
return hdElm;
}
TypHandle       HdVecFFEL;
TypHandle       ElmlVecFFE ( hdList, pos )
TypHandle           hdList;
long                pos;
{
ELM_VECFFE( hdList, pos, HdVecFFEL );
return HdVecFFEL;
}
TypHandle       HdVecFFER;
TypHandle       ElmrVecFFE ( hdList, pos )
TypHandle           hdList;
long                pos;
{
ELM_VECFFE( hdList, pos, HdVecFFER );
return HdVecFFER;
}
TypHandle       ElmsVecFFE ( hdList, hdPoss )
TypHandle           hdList;
TypHandle           hdPoss;
{
TypHandle           hdElms;
long                lenList;
TypFFE              hdElm;
long                lenPoss;
long                pos;
long                inc;
long                i;
if ( TYPE(hdPoss) != T_RANGE ) {
lenList = LEN_VECFFE( hdList );
lenPoss = LEN_LIST( hdPoss );
hdElms = NewBag( T_VECFFE, SIZE_PLEN_VECFFE( lenPoss ) );
SET_FLD_VECFFE( hdElms, FLD_VECFFE( hdList ) );
for ( i = 1; i <= lenPoss; i++ ) {
pos = HD_TO_INT( ELMF_LIST( hdPoss, i ) );
if ( lenList < pos ) {
return Error(
"List Elements: <list>[%d] must have a value",
pos, 0L );
}
hdElm = VAL_VECFFE( hdList, pos );
SET_VAL_VECFFE( hdElms, i, hdElm );
}
}
else {
lenList = LEN_VECFFE( hdList );
lenPoss = LEN_RANGE( hdPoss );
pos = LOW_RANGE( hdPoss );
inc = INC_RANGE( hdPoss );
if ( lenList < pos ) {
return Error(
"List Elements: <list>[%d] must have a value",
pos, 0L );
}
if ( lenList < pos + (lenPoss-1) * inc ) {
return Error(
"List Elements: <list>[%d] must have a value",
pos + (lenPoss-1) * inc, 0L );
}
hdElms = NewBag( T_VECFFE, SIZE_PLEN_VECFFE( lenPoss ) );
SET_FLD_VECFFE( hdElms, FLD_VECFFE( hdList ) );
for ( i = 1; i <= lenPoss; i++, pos += inc ) {
hdElm = VAL_VECFFE( hdList, pos );
SET_VAL_VECFFE( hdElms, i, hdElm );
}
}
return hdElms;
}
TypHandle       AssVecFFE ( hdList, pos, hdVal )
TypHandle           hdList;
long                pos;
TypHandle           hdVal;
{
long                plen;
if ( TYPE(hdVal) == T_FFE && FLD_FFE(hdVal) == FLD_VECFFE(hdList)
&& pos <= LEN_VECFFE(hdList) ) {
SET_ELM_VECFFE( hdList, pos, hdVal );
}
else if ( TYPE(hdVal) == T_FFE && FLD_FFE(hdVal) == FLD_VECFFE(hdList)
&& pos == LEN_VECFFE(hdList)+1 ) {
Resize( hdList, SIZE_PLEN_VECFFE( pos ) );
SET_ELM_VECFFE( hdList, pos, hdVal );
}
else {
PLAIN_LIST( hdList );
if ( LEN_PLIST( hdList ) < pos ) {
plen = PLEN_SIZE_PLIST( SIZE(hdList) );
if ( plen + plen/8 + 4 < pos )
Resize( hdList, SIZE_PLEN_PLIST( pos ) );
else if ( plen < pos )
Resize( hdList, SIZE_PLEN_PLIST( plen + plen/8 + 4 ) );
SET_LEN_PLIST( hdList, pos );
}
SET_ELM_PLIST( hdList, pos, hdVal );
}
return hdVal;
}
TypHandle       AsssVecFFE ( hdList, hdPoss, hdVals )
TypHandle           hdList;
TypHandle           hdPoss;
TypHandle           hdVals;
{
PLAIN_LIST( hdList );
Retype( hdList, T_LIST );
return ASSS_LIST( hdList, hdPoss, hdVals );
}
long            PosVecFFE ( hdList, hdVal, start )
TypHandle           hdList;
TypHandle           hdVal;
long                start;
{
long                lenList;
TypHandle           hdElm;
long                i;
lenList = LEN_VECFFE( hdList );
for ( i = start+1; i <= lenList; i++ ) {
hdElm = ELML_LIST( hdList, i );
if ( hdElm != 0 && (hdElm == hdVal || EQ( hdElm, hdVal ) == HdTrue) )
break;
}
return (lenList < i ? 0 : i);
}
void            PlainVecFFE ( hdList )
TypHandle           hdList;
{
long                lenList;
TypHandle           hdCopy;
long                i;
lenList = LEN_VECFFE( hdList );
hdCopy = NewBag( T_LIST, SIZE_PLEN_PLIST( lenList ) );
SET_LEN_PLIST( hdCopy, lenList );
for ( i = 1; i <= lenList; i++ ) {
SET_ELM_PLIST( hdCopy, i, ElmfVecFFE( hdList, i ) );
}
Resize( hdList, SIZE_PLEN_PLIST( lenList ) );
Retype( hdList, T_LIST );
SET_LEN_PLIST( hdList, lenList );
for ( i = 1; i <= lenList; i++ ) {
SET_ELM_PLIST( hdList, i, ELM_PLIST( hdCopy, i ) );
}
}
long            IsDenseVecFFE ( hdList )
TypHandle           hdList;
{
return 1;
}
long            IsPossVecFFE ( hdList )
TypHandle           hdList;
{
return LEN_VECFFE( hdList ) == 0;
}
long            IsXTypeVecFFE ( hdList )
TypHandle           hdList;
{
long                isVecFFE;
unsigned long       len;
TypHandle           hdFld;
unsigned long       p;
unsigned long       d;
unsigned long       q;
TypHandle           hdElm;
TypFFE              v;
unsigned long       q1;
unsigned long       d1;
unsigned long       i, k;
if ( TYPE(hdList) == T_VECFFE ) {
isVecFFE = 1;
}
else if ( TYPE(hdList) != T_LIST && TYPE(hdList) != T_SET ) {
isVecFFE = 0;
}
else if ( LEN_PLIST( hdList ) == 0 || ELM_PLIST( hdList, 1 ) == 0 ) {
isVecFFE = 0;
}
else if ( TYPE( ELM_PLIST( hdList, 1 ) ) == T_FFE ) {
len = LEN_PLIST( hdList );
hdFld = FLD_FFE( ELM_PLIST( hdList, 1 ) );
for ( i = 2; i <= len; i++ ) {
hdElm = ELM_PLIST( hdList, i );
if ( hdElm == 0 || TYPE(hdElm) != T_FFE
|| FLD_FFE( hdElm ) != hdFld ) {
break;
}
}
isVecFFE = (len < i);
if ( isVecFFE ) {
for ( i = 1; i <= len; i++ ) {
hdElm = ELM_PLIST( hdList, i );
v = VAL_FFE( hdElm );
SET_VAL_VECFFE( hdList, i, v );
}
Retype( hdList, T_VECFFE );
SET_FLD_VECFFE( hdList, hdFld );
SET_LEN_VECFFE( hdList, len );
}
else {
p = CharFFE( ELM_PLIST( hdList, 1 ) );
d = 1;
for ( i = 1; i <= len; i++ ) {
hdElm = ELM_PLIST( hdList, i );
if ( hdElm == 0 || TYPE(hdElm) != T_FFE
|| SIZE_FF( FLD_FFE( hdElm ) ) % p != 0 ) {
break;
}
d1 = DegreeFFE( hdElm );
for ( k = d; d % d1 != 0; d += k )  ;
if ( (  2 <= p && 17 <= d) || (  3 <= p && 11 <= d)
|| (  5 <= p &&  7 <= d) || (  7 <= p &&  6 <= d)
|| ( 11 <= p &&  5 <= d) || ( 17 <= p &&  4 <= d)
|| ( 41 <= p &&  3 <= d) || (257 <= p &&  2 <= d) ) {
break;
}
}
isVecFFE = (len < i);
if ( isVecFFE ) {
for ( q = 1, k = 1; k <= d; k++ )  q *= p;
if ( (SIZE_FF(FLD_FFE(ELM_PLIST(hdList,1)))-1) % (q-1) == 0 )
hdFld = FLD_FFE( ELM_PLIST(hdList,1) );
else
hdFld = FLD_FFE( RootFiniteField( q ) );
q = SIZE_FF( hdFld );
for ( i = 1; i <= len; i++ ) {
hdElm = ELM_PLIST( hdList, i );
q1 = SIZE_FF( FLD_FFE( hdElm ) );
v = VAL_FFE( hdElm );
SET_VAL_VECFFE( hdList, i,
v==0 ? v : (v-1)*(q-1)/(q1-1)+1 );
}
Retype( hdList, T_VECFFE );
SET_FLD_VECFFE( hdList, hdFld );
SET_LEN_VECFFE( hdList, len );
}
}
}
else {
isVecFFE = 0;
}
return isVecFFE;
}
long            IsXTypeMatFFE ( hdList )
TypHandle           hdList;
{
long                isMatFFE;
unsigned long       len;
unsigned long       col;
TypHandle           hdFld;
unsigned long       p;
unsigned long       d;
unsigned long       q;
TypHandle           hdElm;
TypFFE              v;
unsigned long       q1;
unsigned long       d1;
unsigned long       i, k;
if ( TYPE(hdList) != T_LIST && TYPE(hdList) != T_SET ) {
isMatFFE = 0;
}
else if ( LEN_PLIST( hdList ) == 0 || ELM_PLIST( hdList, 1 ) == 0 ) {
isMatFFE = 0;
}
else if ( IsXTypeVecFFE( ELM_PLIST( hdList, 1 ) ) ) {
len = LEN_PLIST( hdList );
col = LEN_VECFFE( ELM_PLIST( hdList, 1 ) );
hdFld = FLD_VECFFE( ELM_PLIST( hdList, 1 ) );
for ( i = 2; i <= len; i++ ) {
hdElm = ELM_PLIST( hdList, i );
if ( hdElm == 0 || TYPE(hdElm) != T_VECFFE
|| col != LEN_VECFFE( hdElm )
|| FLD_VECFFE( hdElm ) != hdFld ) {
break;
}
}
isMatFFE = (len < i);
if ( ! isMatFFE ) {
p = CharVecFFE( ELM_PLIST( hdList, 1 ) );
d = 1;
for ( i = 1; i <= len; i++ ) {
hdElm = ELM_PLIST( hdList, i );
if ( hdElm == 0 || ! IsXTypeVecFFE( hdElm )
|| col != LEN_VECFFE( hdElm )
|| SIZE_FF( FLD_VECFFE( hdElm ) ) % p != 0 ) {
break;
}
d1 = DegreeVecFFE( hdElm );
for ( k = d; d % d1 != 0; d += k )  ;
if ( (  2 <= p && 17 <= d) || (  3 <= p && 11 <= d)
|| (  5 <= p &&  7 <= d) || (  7 <= p &&  6 <= d)
|| ( 11 <= p &&  5 <= d) || ( 17 <= p &&  4 <= d)
|| ( 41 <= p &&  3 <= d) || (257 <= p &&  2 <= d) ) {
break;
}
}
isMatFFE = (len < i);
if ( isMatFFE ) {
for ( q = 1, k = 1; k <= d; k++ )  q *= p;
if ( (SIZE_FF(FLD_VECFFE(ELM_PLIST(hdList,1)))-1)%(q-1)==0 )
hdFld = FLD_VECFFE( ELM_PLIST(hdList,1) );
else
hdFld = FLD_FFE( RootFiniteField( q ) );
q = SIZE_FF( hdFld );
for ( i = 1; i <= len; i++ ) {
hdElm = ELM_PLIST( hdList, i );
if ( FLD_VECFFE( hdElm ) != hdFld ) {
q1 = SIZE_FF( FLD_VECFFE( hdElm ) );
for ( k = 1; k <= col; k++ ) {
v = VAL_VECFFE( hdElm, k );
SET_VAL_VECFFE( hdElm, k,
v==0 ? v : (v-1)*(q-1)/(q1-1)+1 );
}
SET_FLD_VECFFE( hdElm, hdFld );
}
}
}
}
}
else {
isMatFFE = 0;
}
return isMatFFE;
}
TypHandle       SumFFEVecFFE ( hdL, hdR )
TypHandle           hdL;
TypHandle           hdR;
{
TypHandle           hdS;
unsigned long       len;
unsigned long       p;
unsigned long       q;
unsigned long       d;
TypHandle           hdFld;
TypFFE *            fld;
unsigned long       qL;
unsigned long       dL;
TypFFE              vL;
unsigned long       qR;
unsigned long       dR;
TypFFE              vR;
unsigned long       i;
if ( FLD_FFE( hdL ) == FLD_VECFFE( hdR ) ) {
len = LEN_VECFFE( hdR );
hdS = NewBag( T_VECFFE, SIZE_PLEN_VECFFE( len ) );
hdFld = FLD_FFE( hdL );
fld = SUCC_FF( hdFld );
SET_FLD_VECFFE( hdS, hdFld );
vL = VAL_FFE( hdL );
for ( i = 1; i <= len; i++ ) {
vR = VAL_VECFFE( hdR, i );
SET_VAL_VECFFE( hdS, i, SUM_FF( vL, vR, fld ) );
}
}
else {
len = LEN_VECFFE( hdR );
hdS = NewBag( T_VECFFE, SIZE_PLEN_VECFFE( len ) );
p = CharFFE( hdL );
if ( SIZE_FF( FLD_VECFFE( hdR ) ) % p != 0 )
return Error("Vector +: operands must lie in a common field",0L,0L);
dL = DegreeFFE( hdL );
dR = DegreeVecFFE( hdR );
for ( d = 1, q = p; d % dR != 0 || d % dL != 0; d++ )  q *= p;
if ( (  2 <= p && 17 <= d) || (  3 <= p && 11 <= d)
|| (  5 <= p &&  7 <= d) || (  7 <= p &&  6 <= d)
|| ( 11 <= p &&  5 <= d) || ( 17 <= p &&  4 <= d)
|| ( 41 <= p &&  3 <= d) || (257 <= p &&  2 <= d) )
return Error("Vector +: smallest common field too large",0L,0L);
if ( (SIZE_FF(FLD_FFE(hdL))-1) % (q-1) == 0 )
hdFld = FLD_FFE( hdL );
else if ( (SIZE_FF(FLD_VECFFE(hdR))-1) % (q-1) == 0 )
hdFld = FLD_VECFFE( hdR );
else
hdFld = FLD_FFE( RootFiniteField( q ) );
fld = SUCC_FF( hdFld );
q = SIZE_FF( hdFld );
SET_FLD_VECFFE( hdS, hdFld );
qL = SIZE_FF( FLD_FFE( hdL ) );
vL = VAL_FFE( hdL );
if ( vL != 0 )  vL = (vL-1)*(q-1)/(qL-1)+1;
qR = SIZE_FF( FLD_VECFFE( hdR ) );
for ( i = 1; i <= len; i++ ) {
vR = VAL_VECFFE( hdR, i );
if ( vR != 0 )  vR = (vR-1)*(q-1)/(qR-1)+1;
SET_VAL_VECFFE( hdS, i, SUM_FF( vL, vR, fld ) );
}
}
return hdS;
}
TypHandle       SumVecFFEFFE ( hdL, hdR )
TypHandle           hdL;
TypHandle           hdR;
{
TypHandle           hdS;
unsigned long       len;
unsigned long       p;
unsigned long       q;
unsigned long       d;
TypHandle           hdFld;
TypFFE *            fld;
unsigned long       qL;
unsigned long       dL;
TypFFE              vL;
unsigned long       qR;
unsigned long       dR;
TypFFE              vR;
unsigned long       i;
if ( FLD_VECFFE( hdL ) == FLD_FFE( hdR ) ) {
len = LEN_VECFFE( hdL );
hdS = NewBag( T_VECFFE, SIZE_PLEN_VECFFE( len ) );
hdFld = FLD_VECFFE( hdL );
fld = SUCC_FF( hdFld );
SET_FLD_VECFFE( hdS, hdFld );
vR = VAL_FFE( hdR );
for ( i = 1; i <= len; i++ ) {
vL = VAL_VECFFE( hdL, i );
SET_VAL_VECFFE( hdS, i, SUM_FF( vL, vR, fld ) );
}
}
else {
len = LEN_VECFFE( hdL );
hdS = NewBag( T_VECFFE, SIZE_PLEN_VECFFE( len ) );
p = CharVecFFE( hdL );
if ( SIZE_FF( FLD_FFE( hdR ) ) % p != 0 )
return Error("Vector +: operands must lie in a common field",0L,0L);
dL = DegreeVecFFE( hdL );
dR = DegreeFFE( hdR );
for ( d = 1, q = p; d % dR != 0 || d % dL != 0; d++ )  q *= p;
if ( (  2 <= p && 17 <= d) || (  3 <= p && 11 <= d)
|| (  5 <= p &&  7 <= d) || (  7 <= p &&  6 <= d)
|| ( 11 <= p &&  5 <= d) || ( 17 <= p &&  4 <= d)
|| ( 41 <= p &&  3 <= d) || (257 <= p &&  2 <= d) )
return Error("Vector +: smallest common field too large",0L,0L);
if ( (SIZE_FF(FLD_VECFFE(hdL))-1) % (q-1) == 0 )
hdFld = FLD_VECFFE( hdL );
else if ( (SIZE_FF(FLD_FFE(hdR))-1) % (q-1) == 0 )
hdFld = FLD_FFE( hdR );
else
hdFld = FLD_FFE( RootFiniteField( q ) );
fld = SUCC_FF( hdFld );
q = SIZE_FF( hdFld );
SET_FLD_VECFFE( hdS, hdFld );
qR = SIZE_FF( FLD_FFE( hdR ) );
vR = VAL_FFE( hdR );
if ( vR != 0 )  vR = (vR-1)*(q-1)/(qR-1)+1;
qL = SIZE_FF( FLD_VECFFE( hdL ) );
for ( i = 1; i <= len; i++ ) {
vL = VAL_VECFFE( hdL, i );
if ( vL != 0 )  vL = (vL-1)*(q-1)/(qL-1)+1;
SET_VAL_VECFFE( hdS, i, SUM_FF( vL, vR, fld ) );
}
}
return hdS;
}
TypHandle       SumVecFFEVecFFE ( hdL, hdR )
TypHandle           hdL;
TypHandle           hdR;
{
TypHandle           hdS;
unsigned long       len;
unsigned long       p;
unsigned long       q;
unsigned long       d;
TypHandle           hdFld;
TypFFE *            fld;
unsigned long       qL;
unsigned long       dL;
TypFFE              vL;
unsigned long       qR;
unsigned long       dR;
TypFFE              vR;
unsigned long       i;
if ( FLD_VECFFE( hdL ) == FLD_VECFFE( hdR ) ) {
len = LEN_VECFFE( hdL );
if ( len != LEN_VECFFE( hdR ) )
return Error("Vector +: vectors must have the same length",0L,0L);
hdS = NewBag( T_VECFFE, SIZE_PLEN_VECFFE( len ) );
hdFld = FLD_VECFFE( hdL );
fld = SUCC_FF( hdFld );
SET_FLD_VECFFE( hdS, hdFld );
for ( i = 1; i <= len; i++ ) {
vL = VAL_VECFFE( hdL, i );
vR = VAL_VECFFE( hdR, i );
SET_VAL_VECFFE( hdS, i, SUM_FF( vL, vR, fld ) );
}
}
else {
len = LEN_VECFFE( hdL );
if ( len != LEN_VECFFE( hdR ) )
return Error("Vector +: vectors must have the same length",0L,0L);
hdS = NewBag( T_VECFFE, SIZE_PLEN_VECFFE( len ) );
p = CharVecFFE( hdL );
if ( SIZE_FF( FLD_VECFFE( hdR ) ) % p != 0 )
return Error("Vector +: operands must lie in a common field",0L,0L);
dL = DegreeVecFFE( hdL );
dR = DegreeVecFFE( hdR );
for ( d = 1, q = p; d % dR != 0 || d % dL != 0; d++ )  q *= p;
if ( (  2 <= p && 17 <= d) || (  3 <= p && 11 <= d)
|| (  5 <= p &&  7 <= d) || (  7 <= p &&  6 <= d)
|| ( 11 <= p &&  5 <= d) || ( 17 <= p &&  4 <= d)
|| ( 41 <= p &&  3 <= d) || (257 <= p &&  2 <= d) )
return Error("Vector +: smallest common field too large",0L,0L);
if ( (SIZE_FF(FLD_VECFFE(hdL))-1) % (q-1) == 0 )
hdFld = FLD_VECFFE( hdL );
else if ( (SIZE_FF(FLD_VECFFE(hdR))-1) % (q-1) == 0 )
hdFld = FLD_VECFFE( hdR );
else
hdFld = FLD_FFE( RootFiniteField( q ) );
fld = SUCC_FF( hdFld );
q = SIZE_FF( hdFld );
SET_FLD_VECFFE( hdS, hdFld );
qL = SIZE_FF( FLD_VECFFE( hdL ) );
qR = SIZE_FF( FLD_VECFFE( hdR ) );
for ( i = 1; i <= len; i++ ) {
vL = VAL_VECFFE( hdL, i );
if ( vL != 0 )  vL = (vL-1)*(q-1)/(qL-1)+1;
vR = VAL_VECFFE( hdR, i );
if ( vR != 0 )  vR = (vR-1)*(q-1)/(qR-1)+1;
SET_VAL_VECFFE( hdS, i, SUM_FF( vL, vR, fld ) );
}
}
return hdS;
}
TypHandle       SumVectorFFE ( hdL, hdR )
TypHandle           hdL;
TypHandle           hdR;
{
TypHandle           hdS;
TypFFE              vS;
unsigned long       len;
TypHandle           hdFld;
TypFFE              * fld;
unsigned long       q;
TypHandle           hdLL;
long                l;
TypFFE              vL;
TypFFE              vR;
unsigned long       i;
if ( TYPE( ELMF_LIST( hdL, 1 ) ) != T_INT )
return SumListScl( hdL, hdR );
hdFld = FLD_FFE( hdR );
fld = SUCC_FF( hdFld );
q = SIZE_FF( hdFld );
len = LEN_LIST( hdL );
hdS = NewBag( T_VECFFE, SIZE_PLEN_VECFFE(len) );
SET_LEN_VECFFE( hdS, len );
SET_FLD_VECFFE( hdS, hdFld );
for ( i = 1; i <= len; i++ ) {
hdLL = ELMF_LIST( hdL, i );
if ( TYPE(hdLL) != T_INT ) {
return Error("operations: sum of %s and %s is not defined",
(long)NameType[TYPE(hdLL)], (long)NameType[TYPE(hdR)] );
}
l = (HD_TO_INT(hdLL) % (long)q + q) % q;
if ( l == 0 )  vL = 0;
else for ( vL = 1; 1 < l; --l )  vL = (vL == 0 ? 1 : fld[vL]);
vR = VAL_FFE(hdR);
vS = SUM_FF( vL, vR, fld );
SET_VAL_VECFFE( hdS, i, vS );
}
return hdS;
}
TypHandle       SumFFEVector ( hdL, hdR )
TypHandle           hdL;
TypHandle           hdR;
{
TypHandle           hdS;
TypFFE              vS;
unsigned long       len;
TypHandle           hdFld;
TypFFE              * fld;
unsigned long       q;
TypFFE              vL;
TypHandle           hdRR;
long                r;
TypFFE              vR;
unsigned long       i;
if ( TYPE( ELMF_LIST( hdR, 1 ) ) != T_INT )
return SumSclList( hdL, hdR );
hdFld = FLD_FFE( hdL );
fld = SUCC_FF( hdFld );
q = SIZE_FF( hdFld );
len = LEN_LIST( hdR );
hdS = NewBag( T_VECFFE, SIZE_PLEN_VECFFE(len) );
SET_LEN_VECFFE( hdS, len );
SET_FLD_VECFFE( hdS, hdFld );
for ( i = 1; i <= len; i++ ) {
hdRR = ELMF_LIST( hdR, i );
if ( TYPE(hdRR) != T_INT ) {
return Error("operations: sum of %s and %s is not defined",
(long)NameType[TYPE(hdL)], (long)NameType[TYPE(hdRR)] );
}
vL = VAL_FFE(hdL);
r = (HD_TO_INT(hdRR) % (long)q + q) % q;
if ( r == 0 )  vR = 0;
else for ( vR = 1; 1 < r; --r )  vR = (vR == 0 ? 1 : fld[vR]);
vS = SUM_FF( vL, vR, fld );
SET_VAL_VECFFE( hdS, i, vS );
}
return hdS;
}
TypHandle       DiffFFEVecFFE ( hdL, hdR )
TypHandle           hdL;
TypHandle           hdR;
{
TypHandle           hdD;
unsigned long       len;
unsigned long       p;
unsigned long       q;
unsigned long       d;
TypHandle           hdFld;
TypFFE *            fld;
unsigned long       qL;
unsigned long       dL;
TypFFE              vL;
unsigned long       qR;
unsigned long       dR;
TypFFE              vR;
unsigned long       i;
if ( FLD_FFE( hdL ) == FLD_VECFFE( hdR ) ) {
len = LEN_VECFFE( hdR );
hdD = NewBag( T_VECFFE, SIZE_PLEN_VECFFE( len ) );
hdFld = FLD_FFE( hdL );
fld = SUCC_FF( hdFld );
SET_FLD_VECFFE( hdD, hdFld );
vL = VAL_FFE( hdL );
for ( i = 1; i <= len; i++ ) {
vR = VAL_VECFFE( hdR, i );
vR = NEG_FF( vR, fld );
SET_VAL_VECFFE( hdD, i, SUM_FF( vL, vR, fld ) );
}
}
else {
len = LEN_VECFFE( hdR );
hdD = NewBag( T_VECFFE, SIZE_PLEN_VECFFE( len ) );
p = CharFFE( hdL );
if ( SIZE_FF( FLD_VECFFE( hdR ) ) % p != 0 )
return Error("Vector -: operands must lie in a common field",0L,0L);
dL = DegreeFFE( hdL );
dR = DegreeVecFFE( hdR );
for ( d = 1, q = p; d % dR != 0 || d % dL != 0; d++ )  q *= p;
if ( (  2 <= p && 17 <= d) || (  3 <= p && 11 <= d)
|| (  5 <= p &&  7 <= d) || (  7 <= p &&  6 <= d)
|| ( 11 <= p &&  5 <= d) || ( 17 <= p &&  4 <= d)
|| ( 41 <= p &&  3 <= d) || (257 <= p &&  2 <= d) )
return Error("Vector -: smallest common field too large",0L,0L);
if ( (SIZE_FF(FLD_FFE(hdL))-1) % (q-1) == 0 )
hdFld = FLD_FFE( hdL );
else if ( (SIZE_FF(FLD_VECFFE(hdR))-1) % (q-1) == 0 )
hdFld = FLD_VECFFE( hdR );
else
hdFld = FLD_FFE( RootFiniteField( q ) );
fld = SUCC_FF( hdFld );
q = SIZE_FF( hdFld );
SET_FLD_VECFFE( hdD, hdFld );
qL = SIZE_FF( FLD_FFE( hdL ) );
vL = VAL_FFE( hdL );
if ( vL != 0 )  vL = (vL-1)*(q-1)/(qL-1)+1;
qR = SIZE_FF( FLD_VECFFE( hdR ) );
for ( i = 1; i <= len; i++ ) {
vR = VAL_VECFFE( hdR, i );
if ( vR != 0 )  vR = (vR-1)*(q-1)/(qR-1)+1;
vR = NEG_FF( vR, fld );
SET_VAL_VECFFE( hdD, i, SUM_FF( vL, vR, fld ) );
}
}
return hdD;
}
TypHandle       DiffVecFFEFFE ( hdL, hdR )
TypHandle           hdL;
TypHandle           hdR;
{
TypHandle           hdD;
unsigned long       len;
unsigned long       p;
unsigned long       q;
unsigned long       d;
TypHandle           hdFld;
TypFFE *            fld;
unsigned long       qL;
unsigned long       dL;
TypFFE              vL;
unsigned long       qR;
unsigned long       dR;
TypFFE              vR;
unsigned long       i;
if ( FLD_VECFFE( hdL ) == FLD_FFE( hdR ) ) {
len = LEN_VECFFE( hdL );
hdD = NewBag( T_VECFFE, SIZE_PLEN_VECFFE( len ) );
hdFld = FLD_VECFFE( hdL );
fld = SUCC_FF( hdFld );
SET_FLD_VECFFE( hdD, hdFld );
vR = VAL_FFE( hdR );
vR = NEG_FF( vR, fld );
for ( i = 1; i <= len; i++ ) {
vL = VAL_VECFFE( hdL, i );
SET_VAL_VECFFE( hdD, i, SUM_FF( vL, vR, fld ) );
}
}
else {
len = LEN_VECFFE( hdL );
hdD = NewBag( T_VECFFE, SIZE_PLEN_VECFFE( len ) );
p = CharVecFFE( hdL );
if ( SIZE_FF( FLD_FFE( hdR ) ) % p != 0 )
return Error("Vector -: operands must lie in a common field",0L,0L);
dL = DegreeVecFFE( hdL );
dR = DegreeFFE( hdR );
for ( d = 1, q = p; d % dR != 0 || d % dL != 0; d++ )  q *= p;
if ( (  2 <= p && 17 <= d) || (  3 <= p && 11 <= d)
|| (  5 <= p &&  7 <= d) || (  7 <= p &&  6 <= d)
|| ( 11 <= p &&  5 <= d) || ( 17 <= p &&  4 <= d)
|| ( 41 <= p &&  3 <= d) || (257 <= p &&  2 <= d) )
return Error("Vector -: smallest common field too large",0L,0L);
if ( (SIZE_FF(FLD_VECFFE(hdL))-1) % (q-1) == 0 )
hdFld = FLD_VECFFE( hdL );
else if ( (SIZE_FF(FLD_FFE(hdR))-1) % (q-1) == 0 )
hdFld = FLD_FFE( hdR );
else
hdFld = FLD_FFE( RootFiniteField( q ) );
fld = SUCC_FF( hdFld );
q = SIZE_FF( hdFld );
SET_FLD_VECFFE( hdD, hdFld );
qR = SIZE_FF( FLD_FFE( hdR ) );
vR = VAL_FFE( hdR );
if ( vR != 0 )  vR = (vR-1)*(q-1)/(qR-1)+1;
vR = NEG_FF( vR, fld );
qL = SIZE_FF( FLD_VECFFE( hdL ) );
for ( i = 1; i <= len; i++ ) {
vL = VAL_VECFFE( hdL, i );
if ( vL != 0 )  vL = (vL-1)*(q-1)/(qL-1)+1;
SET_VAL_VECFFE( hdD, i, SUM_FF( vL, vR, fld ) );
}
}
return hdD;
}
TypHandle       DiffVecFFEVecFFE ( hdL, hdR )
TypHandle           hdL;
TypHandle           hdR;
{
TypHandle           hdD;
unsigned long       len;
unsigned long       p;
unsigned long       q;
unsigned long       d;
TypHandle           hdFld;
TypFFE *            fld;
unsigned long       qL;
unsigned long       dL;
TypFFE              vL;
unsigned long       qR;
unsigned long       dR;
TypFFE              vR;
unsigned long       i;
if ( FLD_VECFFE( hdL ) == FLD_VECFFE( hdR ) ) {
len = LEN_VECFFE( hdL );
if ( len != LEN_VECFFE( hdR ) )
return Error("Vector -: vectors must have the same length",0L,0L);
hdD = NewBag( T_VECFFE, SIZE_PLEN_VECFFE( len ) );
hdFld = FLD_VECFFE( hdL );
fld = SUCC_FF( hdFld );
SET_FLD_VECFFE( hdD, hdFld );
for ( i = 1; i <= len; i++ ) {
vL = VAL_VECFFE( hdL, i );
vR = VAL_VECFFE( hdR, i );
vR = NEG_FF( vR, fld );
SET_VAL_VECFFE( hdD, i, SUM_FF( vL, vR, fld ) );
}
}
else {
len = LEN_VECFFE( hdL );
if ( len != LEN_VECFFE( hdR ) )
return Error("Vector -: vectors must have the same length",0L,0L);
hdD = NewBag( T_VECFFE, SIZE_PLEN_VECFFE( len ) );
p = CharVecFFE( hdL );
if ( SIZE_FF( FLD_VECFFE( hdR ) ) % p != 0 )
return Error("Vector -: operands must lie in a common field",0L,0L);
dL = DegreeVecFFE( hdL );
dR = DegreeVecFFE( hdR );
for ( d = 1, q = p; d % dR != 0 || d % dL != 0; d++ )  q *= p;
if ( (  2 <= p && 17 <= d) || (  3 <= p && 11 <= d)
|| (  5 <= p &&  7 <= d) || (  7 <= p &&  6 <= d)
|| ( 11 <= p &&  5 <= d) || ( 17 <= p &&  4 <= d)
|| ( 41 <= p &&  3 <= d) || (257 <= p &&  2 <= d) )
return Error("Vector -: smallest common field too large",0L,0L);
if ( (SIZE_FF(FLD_VECFFE(hdL))-1) % (q-1) == 0 )
hdFld = FLD_VECFFE( hdL );
else if ( (SIZE_FF(FLD_VECFFE(hdR))-1) % (q-1) == 0 )
hdFld = FLD_VECFFE( hdR );
else
hdFld = FLD_FFE( RootFiniteField( q ) );
fld = SUCC_FF( hdFld );
q = SIZE_FF( hdFld );
SET_FLD_VECFFE( hdD, hdFld );
qL = SIZE_FF( FLD_VECFFE( hdL ) );
qR = SIZE_FF( FLD_VECFFE( hdR ) );
for ( i = 1; i <= len; i++ ) {
vL = VAL_VECFFE( hdL, i );
if ( vL != 0 )  vL = (vL-1)*(q-1)/(qL-1)+1;
vR = VAL_VECFFE( hdR, i );
if ( vR != 0 )  vR = (vR-1)*(q-1)/(qR-1)+1;
vR = NEG_FF( vR, fld );
SET_VAL_VECFFE( hdD, i, SUM_FF( vL, vR, fld ) );
}
}
return hdD;
}
TypHandle       DiffVectorFFE ( hdL, hdR )
TypHandle           hdL;
TypHandle           hdR;
{
TypHandle           hdD;
TypFFE              vD;
unsigned long       len;
TypHandle           hdFld;
TypFFE              * fld;
unsigned long       q;
TypHandle           hdLL;
long                l;
TypFFE              vL;
TypFFE              vR;
unsigned long       i;
if ( TYPE( ELMF_LIST( hdL, 1 ) ) != T_INT )
return DiffListScl( hdL, hdR );
hdFld = FLD_FFE( hdR );
fld = SUCC_FF( hdFld );
q = SIZE_FF( hdFld );
len = LEN_LIST( hdL );
hdD = NewBag( T_VECFFE, SIZE_PLEN_VECFFE(len) );
SET_LEN_VECFFE( hdD, len );
SET_FLD_VECFFE( hdD, hdFld );
for ( i = 1; i <= len; i++ ) {
hdLL = ELMF_LIST( hdL, i );
if ( TYPE(hdLL) != T_INT ) {
return Error("operations: sum of %s and %s is not defined",
(long)NameType[TYPE(hdLL)], (long)NameType[TYPE(hdR)] );
}
l = (HD_TO_INT(hdLL) % (long)q + q) % q;
if ( l == 0 )  vL = 0;
else for ( vL = 1; 1 < l; --l )  vL = (vL == 0 ? 1 : fld[vL]);
vR = VAL_FFE(hdR);
vR = NEG_FF( vR, fld );
vD = SUM_FF( vL, vR, fld );
SET_VAL_VECFFE( hdD, i, vD );
}
return hdD;
}
TypHandle       DiffFFEVector ( hdL, hdR )
TypHandle           hdL;
TypHandle           hdR;
{
TypHandle           hdD;
TypFFE              vD;
unsigned long       len;
TypHandle           hdFld;
TypFFE              * fld;
unsigned long       q;
TypFFE              vL;
TypHandle           hdRR;
long                r;
TypFFE              vR;
unsigned long       i;
if ( TYPE( ELMF_LIST( hdR, 1 ) ) != T_INT )
return DiffSclList( hdL, hdR );
hdFld = FLD_FFE( hdL );
fld = SUCC_FF( hdFld );
q = SIZE_FF( hdFld );
len = LEN_LIST( hdR );
hdD = NewBag( T_VECFFE, SIZE_PLEN_VECFFE(len) );
SET_LEN_VECFFE( hdD, len );
SET_FLD_VECFFE( hdD, hdFld );
for ( i = 1; i <= len; i++ ) {
hdRR = ELMF_LIST( hdR, i );
if ( TYPE(hdRR) != T_INT ) {
return Error("operations: sum of %s and %s is not defined",
(long)NameType[TYPE(hdL)], (long)NameType[TYPE(hdRR)] );
}
vL = VAL_FFE(hdL);
r = (HD_TO_INT(hdRR) % (long)q + q) % q;
if ( r == 0 )  vR = 0;
else for ( vR = 1; 1 < r; --r )  vR = (vR == 0 ? 1 : fld[vR]);
vR = NEG_FF( vR, fld );
vD = SUM_FF( vL, vR, fld );
SET_VAL_VECFFE( hdD, i, vD );
}
return hdD;
}
TypHandle       ProdFFEVecFFE ( hdL, hdR )
TypHandle           hdL;
TypHandle           hdR;
{
TypHandle           hdP;
unsigned long       len;
unsigned long       p;
unsigned long       q;
unsigned long       d;
TypHandle           hdFld;
TypFFE *            fld;
unsigned long       qL;
unsigned long       dL;
TypFFE              vL;
unsigned long       qR;
unsigned long       dR;
TypFFE              vR;
unsigned long       i;
if ( FLD_FFE( hdL ) == FLD_VECFFE( hdR ) ) {
len = LEN_VECFFE( hdR );
hdP = NewBag( T_VECFFE, SIZE_PLEN_VECFFE( len ) );
hdFld = FLD_FFE( hdL );
fld = SUCC_FF( hdFld );
SET_FLD_VECFFE( hdP, hdFld );
vL = VAL_FFE( hdL );
for ( i = 1; i <= len; i++ ) {
vR = VAL_VECFFE( hdR, i );
SET_VAL_VECFFE( hdP, i, PROD_FF( vL, vR, fld ) );
}
}
else {
len = LEN_VECFFE( hdR );
hdP = NewBag( T_VECFFE, SIZE_PLEN_VECFFE( len ) );
p = CharFFE( hdL );
if ( SIZE_FF( FLD_VECFFE( hdR ) ) % p != 0 )
return Error("Vector *: operands must lie in a common field",0L,0L);
dL = DegreeFFE( hdL );
dR = DegreeVecFFE( hdR );
for ( d = 1, q = p; d % dR != 0 || d % dL != 0; d++ )  q *= p;
if ( (  2 <= p && 17 <= d) || (  3 <= p && 11 <= d)
|| (  5 <= p &&  7 <= d) || (  7 <= p &&  6 <= d)
|| ( 11 <= p &&  5 <= d) || ( 17 <= p &&  4 <= d)
|| ( 41 <= p &&  3 <= d) || (257 <= p &&  2 <= d) )
return Error("Vector *: smallest common field too large",0L,0L);
if ( (SIZE_FF(FLD_FFE(hdL))-1) % (q-1) == 0 )
hdFld = FLD_FFE( hdL );
else if ( (SIZE_FF(FLD_VECFFE(hdR))-1) % (q-1) == 0 )
hdFld = FLD_VECFFE( hdR );
else
hdFld = FLD_FFE( RootFiniteField( q ) );
fld = SUCC_FF( hdFld );
q = SIZE_FF( hdFld );
SET_FLD_VECFFE( hdP, hdFld );
qL = SIZE_FF( FLD_FFE( hdL ) );
vL = VAL_FFE( hdL );
if ( vL != 0 )  vL = (vL-1)*(q-1)/(qL-1)+1;
qR = SIZE_FF( FLD_VECFFE( hdR ) );
for ( i = 1; i <= len; i++ ) {
vR = VAL_VECFFE( hdR, i );
if ( vR != 0 )  vR = (vR-1)*(q-1)/(qR-1)+1;
SET_VAL_VECFFE( hdP, i, PROD_FF( vL, vR, fld ) );
}
}
return hdP;
}
TypHandle       ProdVecFFEFFE ( hdL, hdR )
TypHandle           hdL;
TypHandle           hdR;
{
TypHandle           hdP;
unsigned long       len;
unsigned long       p;
unsigned long       q;
unsigned long       d;
TypHandle           hdFld;
TypFFE *            fld;
unsigned long       qL;
unsigned long       dL;
TypFFE              vL;
unsigned long       qR;
unsigned long       dR;
TypFFE              vR;
unsigned long       i;
if ( FLD_VECFFE( hdL ) == FLD_FFE( hdR ) ) {
len = LEN_VECFFE( hdL );
hdP = NewBag( T_VECFFE, SIZE_PLEN_VECFFE( len ) );
hdFld = FLD_VECFFE( hdL );
fld = SUCC_FF( hdFld );
SET_FLD_VECFFE( hdP, hdFld );
vR = VAL_FFE( hdR );
for ( i = 1; i <= len; i++ ) {
vL = VAL_VECFFE( hdL, i );
SET_VAL_VECFFE( hdP, i, PROD_FF( vL, vR, fld ) );
}
}
else {
len = LEN_VECFFE( hdL );
hdP = NewBag( T_VECFFE, SIZE_PLEN_VECFFE( len ) );
p = CharVecFFE( hdL );
if ( SIZE_FF( FLD_FFE( hdR ) ) % p != 0 )
return Error("Vector *: operands must lie in a common field",0L,0L);
dL = DegreeVecFFE( hdL );
dR = DegreeFFE( hdR );
for ( d = 1, q = p; d % dR != 0 || d % dL != 0; d++ )  q *= p;
if ( (  2 <= p && 17 <= d) || (  3 <= p && 11 <= d)
|| (  5 <= p &&  7 <= d) || (  7 <= p &&  6 <= d)
|| ( 11 <= p &&  5 <= d) || ( 17 <= p &&  4 <= d)
|| ( 41 <= p &&  3 <= d) || (257 <= p &&  2 <= d) )
return Error("Vector *: smallest common field too large",0L,0L);
if ( (SIZE_FF(FLD_VECFFE(hdL))-1) % (q-1) == 0 )
hdFld = FLD_VECFFE( hdL );
else if ( (SIZE_FF(FLD_FFE(hdR))-1) % (q-1) == 0 )
hdFld = FLD_FFE( hdR );
else
hdFld = FLD_FFE( RootFiniteField( q ) );
fld = SUCC_FF( hdFld );
q = SIZE_FF( hdFld );
SET_FLD_VECFFE( hdP, hdFld );
qR = SIZE_FF( FLD_FFE( hdR ) );
vR = VAL_FFE( hdR );
if ( vR != 0 )  vR = (vR-1)*(q-1)/(qR-1)+1;
qL = SIZE_FF( FLD_VECFFE( hdL ) );
for ( i = 1; i <= len; i++ ) {
vL = VAL_VECFFE( hdL, i );
if ( vL != 0 )  vL = (vL-1)*(q-1)/(qL-1)+1;
SET_VAL_VECFFE( hdP, i, PROD_FF( vL, vR, fld ) );
}
}
return hdP;
}
TypHandle       ProdVecFFEVecFFE ( hdL, hdR )
TypHandle           hdL;
TypHandle           hdR;
{
TypHandle           hdP;
TypFFE              vP;
unsigned long       len;
unsigned long       p;
unsigned long       q;
unsigned long       d;
TypHandle           hdFld;
TypFFE *            fld;
unsigned long       qL;
unsigned long       dL;
TypFFE              vL;
unsigned long       qR;
unsigned long       dR;
TypFFE              vR;
TypFFE              vQ;
unsigned long       i;
if ( FLD_VECFFE( hdL ) == FLD_VECFFE( hdR ) ) {
len = LEN_VECFFE( hdL );
if ( len != LEN_VECFFE( hdR ) )
return Error("Vector *: vectors must have the same length",0L,0L);
hdP = NewBag( T_FFE, SIZE_HD + sizeof(TypFFE) );
hdFld = FLD_VECFFE( hdL );
fld = SUCC_FF( hdFld );
SET_FLD_FFE( hdP, hdFld );
vP = 0;
for ( i = 1; i <= len; i++ ) {
vL = VAL_VECFFE( hdL, i );
vR = VAL_VECFFE( hdR, i );
vQ = PROD_FF( vL, vR, fld );
vP = SUM_FF( vP, vQ, fld );
}
SET_VAL_FFE( hdP, vP );
}
else {
len = LEN_VECFFE( hdL );
if ( len != LEN_VECFFE( hdR ) )
return Error("Vector *: vectors must have the same length",0L,0L);
hdP = NewBag( T_FFE, SIZE_HD + sizeof(TypFFE) );
p = CharVecFFE( hdL );
if ( SIZE_FF( FLD_VECFFE( hdR ) ) % p != 0 )
return Error("Vector *: operands must lie in a common field",0L,0L);
dL = DegreeVecFFE( hdL );
dR = DegreeVecFFE( hdR );
for ( d = 1, q = p; d % dR != 0 || d % dL != 0; d++ )  q *= p;
if ( (  2 <= p && 17 <= d) || (  3 <= p && 11 <= d)
|| (  5 <= p &&  7 <= d) || (  7 <= p &&  6 <= d)
|| ( 11 <= p &&  5 <= d) || ( 17 <= p &&  4 <= d)
|| ( 41 <= p &&  3 <= d) || (257 <= p &&  2 <= d) )
return Error("Vector *: smallest common field too large",0L,0L);
if ( (SIZE_FF(FLD_VECFFE(hdL))-1) % (q-1) == 0 )
hdFld = FLD_VECFFE( hdL );
else if ( (SIZE_FF(FLD_VECFFE(hdR))-1) % (q-1) == 0 )
hdFld = FLD_VECFFE( hdR );
else
hdFld = FLD_FFE( RootFiniteField( q ) );
fld = SUCC_FF( hdFld );
q = SIZE_FF( hdFld );
SET_FLD_FFE( hdP, hdFld );
qL = SIZE_FF( FLD_VECFFE( hdL ) );
qR = SIZE_FF( FLD_VECFFE( hdR ) );
vP = 0;
for ( i = 1; i <= len; i++ ) {
vL = VAL_VECFFE( hdL, i );
if ( vL != 0 )  vL = (vL-1)*(q-1)/(qL-1)+1;
vR = VAL_VECFFE( hdR, i );
if ( vR != 0 )  vR = (vR-1)*(q-1)/(qR-1)+1;
vQ = PROD_FF( vL, vR, fld );
vP = SUM_FF( vP, vQ, fld );
}
SET_VAL_FFE( hdP, vP );
}
return hdP;
}
TypHandle       ProdVecFFEMatFFE ( hdL, hdR )
TypHandle           hdL;
TypHandle           hdR;
{
TypHandle           hdP;
TypFFE              vP;
unsigned long       len;
unsigned long       col;
unsigned long       p;
unsigned long       q;
unsigned long       d;
TypHandle           hdFld;
TypFFE *            fld;
unsigned long       qL;
unsigned long       dL;
TypFFE              vL;
TypHandle           hdRR;
unsigned long       qR;
unsigned long       dR;
TypFFE              vR;
TypFFE              vQ;
unsigned long       i, k;
if ( FLD_VECFFE( hdL ) == FLD_VECFFE( ELM_PLIST( hdR, 1 ) ) ) {
len = LEN_VECFFE( hdL );
col = LEN_VECFFE( ELM_PLIST( hdR, 1 ) );
if ( len != LEN_PLIST( hdR ) )
return Error("Vector *: vectors must have the same length",0L,0L);
hdP = NewBag( T_VECFFE, SIZE_PLEN_VECFFE( col ) );
hdFld = FLD_VECFFE( hdL );
fld = SUCC_FF( hdFld );
SET_FLD_VECFFE( hdP, hdFld );
for ( i = 1; i <= len; i++ ) {
vL = VAL_VECFFE( hdL, i );
hdRR = ELM_PLIST( hdR, i );
if ( vL == 1 ) {
for ( k = 1; k <= col; k++ ) {
vR = VAL_VECFFE( hdRR, k );
vP = VAL_VECFFE( hdP, k );
vP = SUM_FF( vP, vR, fld );
SET_VAL_VECFFE( hdP, k, vP );
}
}
else if ( vL != 0 ) {
for ( k = 1; k <= col; k++ ) {
vR = VAL_VECFFE( hdRR, k );
vP = VAL_VECFFE( hdP, k );
vQ = PROD_FF( vL, vR, fld );
vP = SUM_FF( vP, vQ, fld );
SET_VAL_VECFFE( hdP, k, vP );
}
}
}
}
else {
len = LEN_VECFFE( hdL );
col = LEN_VECFFE( ELM_PLIST( hdR, 1 ) );
if ( len != LEN_PLIST( hdR ) )
return Error("Vector *: vectors must have the same length",0L,0L);
hdP = NewBag( T_VECFFE, SIZE_PLEN_VECFFE( col ) );
p = CharVecFFE( hdL );
if ( SIZE_FF( FLD_VECFFE( ELM_PLIST( hdR, 1 ) ) ) % p != 0 )
return Error("Vector *: operands must lie in a common field",0L,0L);
dL = DegreeVecFFE( hdL );
qR = SIZE_FF( FLD_VECFFE( ELM_PLIST( hdR, 1 ) ) );
for ( dR = 1,  q = p;  q != qR;  q *= p,  dR++ ) ;
for ( d = 1, q = p; d % dR != 0 || d % dL != 0; d++ )  q *= p;
if ( (  2 <= p && 17 <= d) || (  3 <= p && 11 <= d)
|| (  5 <= p &&  7 <= d) || (  7 <= p &&  6 <= d)
|| ( 11 <= p &&  5 <= d) || ( 17 <= p &&  4 <= d)
|| ( 41 <= p &&  3 <= d) || (257 <= p &&  2 <= d) )
return Error("Vector *: smallest common field too large",0L,0L);
if ( (SIZE_FF(FLD_VECFFE(hdL))-1) % (q-1) == 0 )
hdFld = FLD_VECFFE( hdL );
else if ( (SIZE_FF(FLD_VECFFE(ELM_PLIST(hdR,1)))-1) % (q-1) == 0 )
hdFld = FLD_VECFFE( ELM_PLIST( hdR, 1 ) );
else
hdFld = FLD_FFE( RootFiniteField( q ) );
fld = SUCC_FF( hdFld );
q = SIZE_FF( hdFld );
SET_FLD_VECFFE( hdP, hdFld );
qL = SIZE_FF( FLD_VECFFE( hdL ) );
qR = SIZE_FF( FLD_VECFFE( ELM_PLIST( hdR, 1 ) ) );
for ( i = 1; i <= len; i++ ) {
vL = VAL_VECFFE( hdL, i );
if ( vL != 0 )  vL = (vL-1)*(q-1)/(qL-1)+1;
hdRR = ELM_PLIST( hdR, i );
if ( vL == 1 ) {
for ( k = 1; k <= col; k++ ) {
vR = VAL_VECFFE( hdRR, k );
if ( vR != 0 )  vR = (vR-1)*(q-1)/(qR-1)+1;
vP = VAL_VECFFE( hdP, k );
vP = SUM_FF( vP, vR, fld );
SET_VAL_VECFFE( hdP, k, vP );
}
}
else if ( vL != 0 ) {
for ( k = 1; k <= col; k++ ) {
vR = VAL_VECFFE( hdRR, k );
if ( vR != 0 )  vR = (vR-1)*(q-1)/(qR-1)+1;
vP = VAL_VECFFE( hdP, k );
vQ = PROD_FF( vL, vR, fld );
vP = SUM_FF( vP, vQ, fld );
SET_VAL_VECFFE( hdP, k, vP );
}
}
}
}
return hdP;
}
TypHandle       ProdVectorFFE ( hdL, hdR )
TypHandle           hdL;
TypHandle           hdR;
{
TypHandle           hdP;
TypFFE              vP;
unsigned long       len;
TypHandle           hdFld;
TypFFE              * fld;
unsigned long       q;
TypHandle           hdLL;
long                l;
TypFFE              vL;
TypFFE              vR;
unsigned long       i;
if ( TYPE( ELMF_LIST( hdL, 1 ) ) != T_INT )
return ProdListScl( hdL, hdR );
hdFld = FLD_FFE( hdR );
fld = SUCC_FF( hdFld );
q = SIZE_FF( hdFld );
len = LEN_LIST( hdL );
hdP = NewBag( T_VECFFE, SIZE_PLEN_VECFFE(len) );
SET_LEN_VECFFE( hdP, len );
SET_FLD_VECFFE( hdP, hdFld );
for ( i = 1; i <= len; i++ ) {
hdLL = ELMF_LIST( hdL, i );
if ( TYPE(hdLL) != T_INT ) {
return Error("operations: product of %s and %s is not defined",
(long)NameType[TYPE(hdLL)], (long)NameType[TYPE(hdR)] );
}
l = (HD_TO_INT(hdLL) % (long)q + q) % q;
if ( l == 0 )  vL = 0;
else for ( vL = 1; 1 < l; --l )  vL = (vL == 0 ? 1 : fld[vL]);
vR = VAL_FFE(hdR);
vP = PROD_FF( vL, vR, fld );
SET_VAL_VECFFE( hdP, i, vP );
}
return hdP;
}
TypHandle       ProdFFEVector ( hdL, hdR )
TypHandle           hdL;
TypHandle           hdR;
{
TypHandle           hdP;
TypFFE              vP;
unsigned long       len;
TypHandle           hdFld;
TypFFE              * fld;
unsigned long       q;
TypFFE              vL;
TypHandle           hdRR;
long                r;
TypFFE              vR;
unsigned long       i;
if ( TYPE( ELMF_LIST( hdR, 1 ) ) != T_INT )
return ProdSclList( hdL, hdR );
hdFld = FLD_FFE( hdL );
fld = SUCC_FF( hdFld );
q = SIZE_FF( hdFld );
len = LEN_LIST( hdR );
hdP = NewBag( T_VECFFE, SIZE_PLEN_VECFFE(len) );
SET_LEN_VECFFE( hdP, len );
SET_FLD_VECFFE( hdP, hdFld );
for ( i = 1; i <= len; i++ ) {
hdRR = ELMF_LIST( hdR, i );
if ( TYPE(hdRR) != T_INT ) {
return Error("operations: product of %s and %s is not defined",
(long)NameType[TYPE(hdL)], (long)NameType[TYPE(hdRR)] );
}
vL = VAL_FFE(hdL);
r = (HD_TO_INT(hdRR) % (long)q + q) % q;
if ( r == 0 )  vR = 0;
else for ( vR = 1; 1 < r; --r )  vR = (vR == 0 ? 1 : fld[vR]);
vP = PROD_FF( vL, vR, fld );
SET_VAL_VECFFE( hdP, i, vP );
}
return hdP;
}
TypHandle       PowMatFFEInt ( hdL, hdR )
TypHandle           hdL;
TypHandle           hdR;
{
TypHandle           hdP = 0;
TypHandle           hdPP;
TypHandle           hdQQ;
TypFFE              ppp;
TypFFE              qqq;
TypHandle           hdLL;
TypFFE              tmp;
TypHandle           hdFld;
TypFFE *            fld;
unsigned long       len;
long                e;
unsigned long       i, k, l;
len = LEN_PLIST( hdL );
if ( len != LEN_VECFFE( ELM_PLIST( hdL, 1 ) ) ) {
return Error(
"Matrix operations ^: <mat> must be square",
0L,0L);
}
hdFld = FLD_VECFFE( ELM_PLIST( hdL, 1 ) );
if ( TYPE(hdR) == T_INT && hdR == INT_TO_HD(0) ) {
hdP = NewBag( T_LIST, SIZE_PLEN_PLIST( len ) );
SET_LEN_PLIST( hdP, len );
for ( i = 1; i <= len; i++ ) {
hdPP = NewBag( T_VECFFE, SIZE_PLEN_VECFFE( len ) );
SET_FLD_VECFFE( hdPP, hdFld );
SET_ELM_PLIST( hdP, i, hdPP );
}
for ( i = 1; i <= len; i++ ) {
hdPP = ELM_PLIST( hdP, i );
for ( k = 1; k <= len; k++ )
SET_VAL_VECFFE( hdPP, k, 0 );
SET_VAL_VECFFE( hdPP, i, 1 );
}
}
if ( TYPE(hdR) == T_INT && hdR == INT_TO_HD(1) ) {
hdP = NewBag( T_LIST, SIZE_PLEN_PLIST( len ) );
SET_LEN_PLIST( hdP, len );
for ( i = 1; i <= len; i++ ) {
hdPP = NewBag( T_VECFFE, SIZE_PLEN_VECFFE( len ) );
SET_FLD_VECFFE( hdPP, hdFld );
SET_ELM_PLIST( hdP, i, hdPP );
}
for ( i = 1; i <= len; i++ ) {
hdPP = ELM_PLIST( hdP, i );
hdLL = ELM_PLIST( hdL, i );
for ( k = 1; k <= len; k++ )
SET_VAL_VECFFE( hdPP, k, VAL_VECFFE( hdLL, k ) );
}
}
if ( (TYPE(hdR) == T_INT && HD_TO_INT(hdR) < 0)
|| (TYPE(hdR) == T_INTNEG) ) {
hdP = NewBag( T_LIST, SIZE_PLEN_PLIST( len ) );
SET_LEN_PLIST( hdP, len );
for ( i = 1; i <= len; i++ ) {
hdPP = NewBag( T_VECFFE, SIZE_PLEN_VECFFE( 2 * len ) );
SET_FLD_VECFFE( hdPP, hdFld );
SET_ELM_PLIST( hdP, i, hdPP );
}
for ( i = 1; i <= len; i++ ) {
hdPP = ELM_PLIST( hdP, i );
for ( k = 1; k <= len; k++ )
SET_VAL_VECFFE( hdPP, k, 0 );
SET_VAL_VECFFE( hdPP, i, 1 );
}
for ( i = 1; i <= len; i++ ) {
hdPP = ELM_PLIST( hdP, i );
hdLL = ELM_PLIST( hdL, i );
for ( k = 1; k <= len; k++ )
SET_VAL_VECFFE( hdPP, k + len, VAL_VECFFE( hdLL, k ) );
}
fld = SUCC_FF( hdFld );
for ( k = len+1; k <= 2*len; k++ ) {
for ( i = k-len;
i <= len && VAL_VECFFE( ELM_PLIST(hdP,i), k ) == 0;
i++ )
;
if ( len < i )
return Error("Matrix: <mat> must be invertible",0L,0L);
hdPP = ELM_PLIST( hdP, i );
SET_ELM_PLIST( hdP, i, ELM_PLIST( hdP, k-len ) );
SET_ELM_PLIST( hdP, k-len, hdPP );
ppp = QUO_FF( 1, VAL_VECFFE( hdPP, k ), fld );
for ( l = 1; l <= 2*len; l++ ) {
tmp = PROD_FF( ppp, VAL_VECFFE( hdPP, l ), fld );
SET_VAL_VECFFE( hdPP, l, tmp );
}
for ( i = 1; i <= len; i++ ) {
hdQQ = ELM_PLIST( hdP, i );
ppp = NEG_FF( VAL_VECFFE( hdQQ, k ), fld );
if ( i != k-len && ppp != 0 ) {
for ( l = 1; l <= 2*len; l++ ) {
tmp = PROD_FF( ppp, VAL_VECFFE( hdPP, l ), fld );
qqq = VAL_VECFFE( hdQQ, l );
tmp = SUM_FF( qqq, tmp, fld );
SET_VAL_VECFFE( hdQQ, l, tmp );
}
}
}
}
for ( i = 1; i <= len; i++ ) {
Resize( ELM_PLIST( hdP, i ), SIZE_PLEN_VECFFE( len ) );
}
hdL = hdP;
if ( TYPE(hdR) == T_INT )  hdR = INT_TO_HD( -HD_TO_INT(hdR) );
}
if ( TYPE(hdR) == T_INT && 1 < HD_TO_INT(hdR) ) {
hdP = 0;
k = (size_t)1 << 31;
e = HD_TO_INT(hdR);
while ( 1 < k ) {
hdP = (hdP == 0 ? hdP : ProdListScl( hdP, hdP ));
k = k / 2;
if ( k <= e ) {
hdP = (hdP == 0 ? hdL : ProdListScl( hdP, hdL ));
e = e - k;
}
}
}
if ( TYPE(hdR) != T_INT ) {
hdP = 0;
for ( i = SIZE(hdR)/sizeof(TypDigit); 0 < i; i-- ) {
k = (size_t)1 << (8*sizeof(TypDigit));
e = ((TypDigit*) PTR(hdR))[i-1];
while ( 1 < k ) {
hdP = (hdP == 0 ? hdP : ProdListScl( hdP, hdP ));
k = k / 2;
if ( k <= e ) {
hdP = (hdP == 0 ? hdL : ProdListScl( hdP, hdL ));
e = e - k;
}
}
}
}
return hdP;
}
void            PrVecFFE ( hdList )
TypHandle           hdList;
{
unsigned long       len;
unsigned long       i;
len = LEN_VECFFE(hdList);
Pr("%2>[ %2>",0L,0L);
for ( i = 1;  i <= len;  i++ ) {
if ( 1 < i )  Pr("%2<, %2>",0L,0L);
PrFF( PTR(hdList)[0], VAL_VECFFE(hdList,i) );
}
Pr(" %4<]",0L,0L);
}
TypHandle DepthVecFFE ( hdVec )
TypHandle           hdVec;
{
long                pos;
long                len;
len = LEN_VECFFE(hdVec);
for ( pos = 1;  pos <= len;  pos++ )
if ( VAL_VECFFE( hdVec, pos ) != 0 )
break;
return INT_TO_HD(pos);
}
long            CharVecFFE ( hdVec )
TypHandle           hdVec;
{
unsigned long       p;
unsigned long       q;
q = SIZE_FF( FLD_VECFFE( hdVec ) );
if ( q % 2 == 0 ) {
p = 2;
}
else {
for ( p = 3; q % p != 0; p += 2 )
;
}
return p;
}
long            CharMatFFE ( hdMat )
TypHandle           hdMat;
{
return CharVecFFE( ELM_PLIST( hdMat, 1 ) );
}
TypHandle       FunCharFFE ( hdCall )
TypHandle           hdCall;
{
unsigned long       p;
TypHandle           hdZ;
if ( SIZE(hdCall) != 2 * SIZE_HD )
return Error("usage: CharFFE( <z> )",0L,0L);
hdZ = EVAL( PTR(hdCall)[1] );
if ( TYPE(hdZ) == T_FFE ) {
p = CharFFE( hdZ );
}
else if ( IsXTypeVecFFE( hdZ ) ) {
p = CharVecFFE( hdZ );
}
else if ( IsXTypeMatFFE( hdZ ) ) {
p = CharMatFFE( hdZ );
}
else {
return Error(
"CharFFE: <z> must be a finite field element, vector, or matrix",
0L,0L);
}
return INT_TO_HD( p );
}
long            DegreeVecFFE ( hdVec )
TypHandle           hdVec;
{
unsigned long       d;
unsigned long       len;
unsigned long       p;
unsigned long       q;
TypFFE              v;
unsigned long       q1;
unsigned long       d1;
unsigned long       i, k;
q = SIZE_FF( FLD_FFE( hdVec ) );
if ( q % 2 == 0 )  p = 2;
else for ( p = 3; q % p != 0; p += 2 )  ;
d = 1;
len = LEN_VECFFE( hdVec );
for ( i = 1; i <= len; i++ ) {
v = VAL_VECFFE( hdVec, i );
q1 = p;
d1 = 1;
if ( v != 0 ) {
while ( (q-1)%(q1-1) != 0 || (v-1)%((q-1)/(q1-1)) != 0 ) {
q1 *= p;
d1 += 1;
}
}
for ( k = d; d % d1 != 0; d += k )  ;
}
return d;
}
long            DegreeMatFFE ( hdMat )
TypHandle           hdMat;
{
unsigned long       d;
unsigned long       len;
unsigned long       p;
unsigned long       q;
TypHandle           hdElm;
unsigned long       d1;
unsigned long       i, k;
q = SIZE_FF( FLD_FFE( ELM_PLIST( hdMat, 1 ) ) );
if ( q % 2 == 0 ) p = 2;
else for ( p = 3; q % p != 0; p += 2 ) ;
d = 1;
len = LEN_PLIST( hdMat );
for ( i = 1; i <= len; i++ ) {
hdElm = ELM_PLIST( hdMat, i );
d1 = DegreeVecFFE( hdElm );
for ( k = d; d % d1 != 0; d += k )  ;
}
return d;
}
TypHandle       FunDegreeFFE ( hdCall )
TypHandle           hdCall;
{
unsigned long       d;
TypHandle           hdZ;
if ( SIZE(hdCall) != 2 * SIZE_HD )
return Error("usage: DegreeFFE( <z> )",0L,0L);
hdZ = EVAL( PTR(hdCall)[1] );
if ( TYPE(hdZ) == T_FFE ) {
d = DegreeFFE( hdZ );
}
else if ( IsXTypeVecFFE( hdZ ) ) {
d = DegreeVecFFE( hdZ );
}
else if ( IsXTypeMatFFE( hdZ ) ) {
d = DegreeMatFFE( hdZ );
}
else {
return Error(
"DegreeFFE: <z> must be a finite field element, vector, or matrix",
0L,0L);
}
return INT_TO_HD( d );
}
TypHandle       FunLogVecFFE ( hdCall )
TypHandle           hdCall;
{
long                exp, pos;
TypHandle           hdPos, hdVec;
if ( SIZE( hdCall ) != 3 * SIZE_HD )
return Error("usage: LogVecFFE( <vector>, <position> )",0L,0L);
hdVec = EVAL( PTR(hdCall)[1] );
hdPos = EVAL( PTR(hdCall)[2] );
if ( ! IsVector(hdVec) || TYPE(hdVec)!=T_VECFFE || TYPE(hdPos)!=T_INT )
return Error("usage: LogVecFFE( <vector>, <position> )",0L,0L);
pos = HD_TO_INT( hdPos );
if (pos <= 0 || LEN_VECFFE( hdVec ) < pos)
return Error("LogVecFFE: <position> argument is out of range",0L,0L);
exp = VAL_VECFFE( hdVec, pos );
if (exp == 0)   return HdFalse;
else            return INT_TO_HD( exp-1 );
}
TypHandle (*TabIntVecFFE[T_VAR]) P(( TypHandle, long ));
TypHandle FunIntVecFFE ( hdCall )
TypHandle           hdCall;
{
long                pos;
TypHandle           hdPos;
TypHandle           hdVec;
if ( SIZE(hdCall) != 2 * SIZE_HD && SIZE(hdCall) != 3 * SIZE_HD )
return Error( "usage: IntVecFFE( <vec>, <pos> )", 0L, 0L );
hdVec = EVAL(PTR(hdCall)[1]);
if ( T_REC <= TYPE(hdVec) || TYPE(hdVec) < T_LIST )
return Error( "IntVecFFE: <list> must be a finite field vector",
0L, 0L );
if ( SIZE(hdCall) == 2 * SIZE_HD )
pos = 0;
else {
hdPos = EVAL( PTR(hdCall)[2] );
if ( TYPE(hdPos) != T_INT )
return Error( "<pos> must be an integer", 0L, 0L );
pos = HD_TO_INT(hdPos);
if ( pos <= 0 )
return Error( "List Element: <pos> must be a positive integer",
0L, 0L );
if ( LEN_LIST(hdVec) < pos )
return Error( "List Element: <list>[%d] must have a value",
(long)pos, 0L );
}
return TabIntVecFFE[XType(hdVec)]( hdVec, pos );
}
TypHandle CantIntVecFFE ( hdList, pos )
TypHandle           hdList;
long                pos;
{
return Error("IntVecFFE: <list> must be a finite field vector",0L,0L);
}
TypHandle IntVecFFE ( hdVec, pos )
TypHandle           hdVec;
long                pos;
{
TypHandle           hdRes;
TypHandle           hdElm;
TypHandle           tab;
long                len;
long                i;
tab = ConvTabIntFFE( SIZE_FF( FLD_VECFFE(hdVec) ) );
if ( pos == 0 ) {
len   = LEN_LIST(hdVec);
hdRes = NewBag( T_LIST, SIZE_PLEN_PLIST(len) );
SET_LEN_PLIST( hdRes, len );
for ( i = len;  0 < i;  i-- ) {
hdElm = ELM_PLIST( tab, VAL_VECFFE(hdVec,i)+1 );
if ( hdElm == 0 )
return Error( "IntVecFFE: <z> must lie in the prime field",
0L, 0L );
SET_ELM_PLIST( hdRes, i, hdElm );
}
}
else {
hdRes = ELM_PLIST( tab, VAL_VECFFE(hdVec,pos)+1 );
if ( hdRes == 0 )
return Error( "IntVecFFE: <z> must lie in the prime field",
0L, 0L );
}
return hdRes;
}
TypHandle       FunMakeVecFFE ( hdCall )
TypHandle           hdCall;
{
TypHandle           hdList;
TypHandle           hdFFE;
unsigned long       len;
TypHandle           hdElm;
TypHandle           hdFF;
TypFFE *            field;
unsigned long       p;
TypFFE              l;
TypFFE              r;
unsigned long       i;
if ( SIZE(hdCall) != 3 * SIZE_HD ) {
return Error("usage: MakeVecFFE( <list>, <ffe> )",0L,0L);
}
hdList = EVAL(PTR(hdCall)[1]);
if ( IS_LIST(hdList) && LEN_LIST(hdList) == 0 ) {
return HdVoid;
}
if ( XType(hdList) != T_VECTOR ) {
return Error("MakeVecFFE: <list> must be a list of integers",0L,0L);
}
len = LEN_LIST(hdList);
hdFFE  = EVAL(PTR(hdCall)[2]);
if ( TYPE(hdFFE) != T_FFE ) {
return Error("MakeVecFFE: <ffe> must be finite field element",0L,0L);
}
hdFF  = FLD_FFE(hdFFE);
field = SUCC_FF(hdFF);
p     = CharFFE(hdFFE);
for ( i = 1;  i <= len;  i++ ) {
hdElm = ELM_LIST( hdList, i );
if ( hdElm == 0 || TYPE(hdElm) != T_INT ) {
return Error(
"MakeVecFFE: <list> must be a list of integers",
0L,0L);
}
l = HD_TO_INT(hdElm);
l = (l % p + p) % p;
if ( l == 0 )  r = 0;
else for ( r = 1; 1 < l; --l )  r = (r == 0 ? 1 : field[r]);
l = VAL_FFE(hdFFE);
SET_VAL_VECFFE( hdList, i, PROD_FF( l, r, field ) );
}
Retype( hdList, T_VECFFE );
SET_FLD_VECFFE( hdList, hdFF );
SET_LEN_VECFFE( hdList, len );
return HdVoid;
}
TypHandle       FunNumberVecFFE ( hdCall )
TypHandle           hdCall;
{
long                num, dim, exp, i;
TypHandle           hdVec, hdPows, hdInts;
if ( SIZE( hdCall ) != 4 * SIZE_HD )
return Error("usage: NumberVecFFE(<vector>,<powers>,<integers>)",
0L,0L);
hdVec  = EVAL( PTR(hdCall)[1] );
hdPows = EVAL( PTR(hdCall)[2] );
hdInts = EVAL( PTR(hdCall)[3] );
if ( ! IsVector(hdVec) || TYPE(hdVec) != T_VECFFE
|| (TYPE(hdPows) != T_LIST && TYPE(hdPows) != T_VECTOR)
|| (TYPE(hdInts) != T_LIST && TYPE(hdInts) != T_VECTOR) )
return Error("usage: NumberVecFFE(<vector>,<powers>,<integers>)",
0L,0L);
if (LEN_VECFFE( hdVec ) < LEN_LIST( hdPows ))
return Error("NumberVecFFE: <vector> is shorter than <powers>",
0L,0L);
if (SIZE_FF( FLD_VECFFE( hdVec ) ) != (LEN_LIST( hdInts )+1))
return Error("NumberVecFFE: <integers> has bad length",0L,0L);
num = 1;
dim = LEN_LIST( hdPows );
for (i = 1; i <= dim; ++i) {
exp = VAL_VECFFE( hdVec, i );
if (exp != 0)
num += HD_TO_INT( ELM_PLIST( hdPows, i ) )
* HD_TO_INT( ELM_PLIST( hdInts, exp ) );
}
return INT_TO_HD( num );
}
void            InitVecFFE ()
{
long                type;
TabIsList     [T_VECFFE] = 2;
TabIsList     [T_MATFFE] = 3;
TabLenList    [T_VECFFE] = LenVecFFE;
TabElmList    [T_VECFFE] = ElmVecFFE;
TabElmfList   [T_VECFFE] = ElmfVecFFE;
TabElmlList   [T_VECFFE] = ElmlVecFFE;
TabElmrList   [T_VECFFE] = ElmrVecFFE;
TabElmsList   [T_VECFFE] = ElmsVecFFE;
TabAssList    [T_VECFFE] = AssVecFFE;
TabAsssList   [T_VECFFE] = AsssVecFFE;
TabPosList    [T_VECFFE] = PosVecFFE;
TabPlainList  [T_VECFFE] = PlainVecFFE;
TabIsDenseList[T_VECFFE] = IsDenseVecFFE;
TabIsPossList [T_VECFFE] = IsPossVecFFE;
TabIsXTypeList[T_VECFFE] = IsXTypeVecFFE;
TabIsXTypeList[T_MATFFE] = IsXTypeMatFFE;
for ( type = T_LIST;  type < T_REC;  type++ )
TabIntVecFFE[type] = CantIntVecFFE;
TabIntVecFFE  [T_VECFFE] = IntVecFFE;
TabDepthVector[T_VECFFE] = DepthVecFFE;
EvTab[T_VECFFE] = EvList;
PrTab[T_VECFFE] = PrVecFFE;
TabEq[T_VECFFE][T_VECFFE] = EqList;
TabLt[T_VECFFE][T_VECFFE] = LtList;
TabSum [T_INT   ][T_VECFFE] = SumSclList;
TabSum [T_FFE   ][T_VECFFE] = SumFFEVecFFE;
TabSum [T_VECFFE][T_INT   ] = SumListScl;
TabSum [T_VECFFE][T_FFE   ] = SumVecFFEFFE;
TabSum [T_INT   ][T_MATFFE] = SumSclList;
TabSum [T_FFE   ][T_MATFFE] = SumSclList;
TabSum [T_MATFFE][T_INT   ] = SumListScl;
TabSum [T_MATFFE][T_FFE   ] = SumListScl;
TabSum [T_VECTOR][T_VECFFE] = SumListList;
TabSum [T_VECFFE][T_VECTOR] = SumListList;
TabSum [T_VECFFE][T_VECFFE] = SumVecFFEVecFFE;
TabSum [T_MATRIX][T_MATFFE] = SumListList;
TabSum [T_MATFFE][T_MATRIX] = SumListList;
TabSum [T_MATFFE][T_MATFFE] = SumListList;
TabSum [T_VECTOR][T_FFE   ] = SumVectorFFE;
TabSum [T_FFE   ][T_VECTOR] = SumFFEVector;
TabDiff[T_INT   ][T_VECFFE] = DiffSclList;
TabDiff[T_FFE   ][T_VECFFE] = DiffFFEVecFFE;
TabDiff[T_VECFFE][T_INT   ] = DiffListScl;
TabDiff[T_VECFFE][T_FFE   ] = DiffVecFFEFFE;
TabDiff[T_INT   ][T_MATFFE] = DiffSclList;
TabDiff[T_FFE   ][T_MATFFE] = DiffSclList;
TabDiff[T_MATFFE][T_INT   ] = DiffListScl;
TabDiff[T_MATFFE][T_FFE   ] = DiffListScl;
TabDiff[T_VECTOR][T_VECFFE] = DiffListList;
TabDiff[T_VECFFE][T_VECTOR] = DiffListList;
TabDiff[T_VECFFE][T_VECFFE] = DiffVecFFEVecFFE;
TabDiff[T_MATRIX][T_MATFFE] = DiffListList;
TabDiff[T_MATFFE][T_MATRIX] = DiffListList;
TabDiff[T_MATFFE][T_MATFFE] = DiffListList;
TabDiff[T_VECTOR][T_FFE   ] = DiffVectorFFE;
TabDiff[T_FFE   ][T_VECTOR] = DiffFFEVector;
TabProd[T_INT   ][T_VECFFE] = ProdSclList;
TabProd[T_FFE   ][T_VECFFE] = ProdFFEVecFFE;
TabProd[T_VECFFE][T_INT   ] = ProdListScl;
TabProd[T_VECFFE][T_FFE   ] = ProdVecFFEFFE;
TabProd[T_INT   ][T_MATFFE] = ProdSclList;
TabProd[T_FFE   ][T_MATFFE] = ProdSclList;
TabProd[T_MATFFE][T_INT   ] = ProdListScl;
TabProd[T_MATFFE][T_FFE   ] = ProdListScl;
TabProd[T_VECTOR][T_VECFFE] = ProdListList;
TabProd[T_VECFFE][T_VECTOR] = ProdListList;
TabProd[T_VECFFE][T_VECFFE] = ProdVecFFEVecFFE;
TabProd[T_VECTOR][T_MATFFE] = ProdListList;
TabProd[T_VECFFE][T_MATRIX] = ProdListList;
TabProd[T_VECFFE][T_MATFFE] = ProdVecFFEMatFFE;
TabProd[T_MATRIX][T_VECFFE] = ProdListScl;
TabProd[T_MATFFE][T_VECTOR] = ProdListScl;
TabProd[T_MATFFE][T_VECFFE] = ProdListScl;
TabProd[T_MATRIX][T_MATFFE] = ProdListScl;
TabProd[T_MATFFE][T_MATRIX] = ProdListScl;
TabProd[T_MATFFE][T_MATFFE] = ProdListScl;
TabProd[T_VECFFE][T_LISTX ] = ProdListList;
TabProd[T_MATFFE][T_LISTX ] = ProdSclList;
TabProd[T_LISTX ][T_MATFFE] = ProdListScl;
TabProd[T_VECTOR][T_FFE   ] = ProdVectorFFE;
TabProd[T_FFE   ][T_VECTOR] = ProdFFEVector;
TabQuo [T_VECFFE][T_INT   ] = QuoLists;
TabQuo [T_VECFFE][T_FFE   ] = QuoLists;
TabQuo [T_INT   ][T_MATFFE] = QuoLists;
TabQuo [T_FFE   ][T_MATFFE] = QuoLists;
TabQuo [T_MATFFE][T_INT   ] = QuoLists;
TabQuo [T_MATFFE][T_FFE   ] = QuoLists;
TabQuo [T_VECTOR][T_MATFFE] = QuoLists;
TabQuo [T_VECFFE][T_MATRIX] = QuoLists;
TabQuo [T_VECFFE][T_MATFFE] = QuoLists;
TabQuo [T_MATRIX][T_MATFFE] = QuoLists;
TabQuo [T_MATFFE][T_MATRIX] = QuoLists;
TabQuo [T_MATFFE][T_MATFFE] = QuoLists;
TabQuo [T_LISTX ][T_MATFFE] = QuoLists;
TabMod [T_INT   ][T_VECFFE] = ModLists;
TabMod [T_FFE   ][T_VECFFE] = ModLists;
TabMod [T_INT   ][T_MATFFE] = ModLists;
TabMod [T_FFE   ][T_MATFFE] = ModLists;
TabMod [T_MATFFE][T_INT   ] = ModLists;
TabMod [T_MATFFE][T_FFE   ] = ModLists;
TabMod [T_MATFFE][T_VECTOR] = ModLists;
TabMod [T_MATRIX][T_VECFFE] = ModLists;
TabMod [T_MATFFE][T_VECFFE] = ModLists;
TabMod [T_MATRIX][T_MATFFE] = ModLists;
TabMod [T_MATFFE][T_MATRIX] = ModLists;
TabMod [T_MATFFE][T_MATFFE] = ModLists;
TabMod [T_MATFFE][T_LISTX ] = ModLists;
TabPow [T_MATFFE][T_INT   ] = PowMatFFEInt;
TabPow [T_MATFFE][T_INTPOS] = PowMatFFEInt;
TabPow [T_MATFFE][T_INTNEG] = PowMatFFEInt;
TabPow [T_VECTOR][T_MATFFE] = ProdListList;
TabPow [T_VECFFE][T_MATRIX] = ProdListList;
TabPow [T_VECFFE][T_MATFFE] = ProdVecFFEMatFFE;
TabPow [T_MATFFE][T_MATFFE] = PowLists;
TabComm[T_MATRIX][T_MATFFE] = CommLists;
TabComm[T_MATFFE][T_MATRIX] = CommLists;
TabComm[T_MATFFE][T_MATFFE] = CommLists;
HdVecFFEL = NewBag( T_FFE, SIZE_HD + sizeof(TypFFE) );
HdVecFFER = NewBag( T_FFE, SIZE_HD + sizeof(TypFFE) );
InstIntFunc( "CharFFE",      FunCharFFE      );
InstIntFunc( "DegreeFFE",    FunDegreeFFE    );
InstIntFunc( "LogVecFFE",    FunLogVecFFE    );
InstIntFunc( "IntVecFFE",    FunIntVecFFE    );
InstIntFunc( "MakeVecFFE",   FunMakeVecFFE   );
InstIntFunc( "NumberVecFFE", FunNumberVecFFE );
}
/* 当前文件是D:\Read\vector.c*/

#ifndef SPEC_INT32_T
#define	SPEC_INT32_T	int
#endif
long            LenVector ( hdList )
TypHandle           hdList;
{
return LEN_PLIST( hdList );
}
TypHandle       ElmVector ( hdList, pos )
TypHandle           hdList;
long                pos;
{
TypHandle           hdElm;
if ( LEN_PLIST( hdList ) < pos ) {
return Error(
"List Element: <list>[%d] must have a value",
pos, 0L );
}
hdElm = ELM_PLIST( hdList, pos );
return hdElm;
}
TypHandle       ElmfVector ( hdList, pos )
TypHandle           hdList;
long                pos;
{
return ELM_PLIST( hdList, pos );
}
TypHandle       ElmsVector ( hdList, hdPoss )
TypHandle           hdList;
TypHandle           hdPoss;
{
TypHandle           hdElms;
long                lenList;
TypHandle           hdElm;
long                lenPoss;
long                pos;
long                inc;
long                i;
if ( TYPE(hdPoss) != T_RANGE ) {
lenList = LEN_PLIST( hdList );
lenPoss = LEN_LIST( hdPoss );
hdElms = NewBag( T_VECTOR, SIZE_PLEN_PLIST( lenPoss ) );
SET_LEN_PLIST( hdElms, lenPoss );
for ( i = 1; i <= lenPoss; i++ ) {
pos = HD_TO_INT( ELMF_LIST( hdPoss, i ) );
if ( lenList < pos ) {
return Error(
"List Elements: <list>[%d] must have a value",
pos, 0L );
}
hdElm = ELM_PLIST( hdList, pos );
SET_ELM_PLIST( hdElms, i, hdElm );
}
}
else {
lenList = LEN_PLIST( hdList );
lenPoss = LEN_RANGE( hdPoss );
pos = LOW_RANGE( hdPoss );
inc = INC_RANGE( hdPoss );
if ( lenList < pos ) {
return Error(
"List Elements: <list>[%d] must have a value",
pos, 0L );
}
if ( lenList < pos + (lenPoss-1) * inc ) {
return Error(
"List Elements: <list>[%d] must have a value",
pos + (lenPoss-1) * inc, 0L );
}
hdElms = NewBag( T_VECTOR, SIZE_PLEN_PLIST( lenPoss ) );
SET_LEN_PLIST( hdElms, lenPoss );
for ( i = 1; i <= lenPoss; i++, pos += inc ) {
hdElm = ELM_PLIST( hdList, pos );
SET_ELM_PLIST( hdElms, i, hdElm );
}
}
return hdElms;
}
TypHandle       AssVector ( hdList, pos, hdVal )
TypHandle           hdList;
long                pos;
TypHandle           hdVal;
{
long                plen;
if ( T_INT <= TYPE(hdVal) && TYPE(hdVal) <= T_UNKNOWN
&& pos <= LEN_PLIST(hdList) ) {
SET_ELM_PLIST( hdList, pos, hdVal );
}
else if ( T_INT <= TYPE(hdVal) && TYPE(hdVal) <= T_UNKNOWN
&& pos == LEN_PLIST(hdList)+1 ) {
if ( PLEN_SIZE_PLIST( SIZE(hdList) ) < pos )
Resize( hdList, SIZE_PLEN_PLIST( (pos-1) + (pos-1)/8 + 4 ) );
SET_LEN_PLIST( hdList, pos );
SET_ELM_PLIST( hdList, pos, hdVal );
}
else {
Retype( hdList, T_LIST );
if ( LEN_PLIST( hdList ) < pos ) {
plen = PLEN_SIZE_PLIST( SIZE(hdList) );
if ( plen + plen/8 + 4 < pos )
Resize( hdList, SIZE_PLEN_PLIST( pos ) );
else if ( plen < pos )
Resize( hdList, SIZE_PLEN_PLIST( plen + plen/8 + 4 ) );
SET_LEN_PLIST( hdList, pos );
}
SET_ELM_PLIST( hdList, pos, hdVal );
}
return hdVal;
}
TypHandle       AsssVector ( hdList, hdPoss, hdVals )
TypHandle           hdList;
TypHandle           hdPoss;
TypHandle           hdVals;
{
Retype( hdList, T_LIST );
return ASSS_LIST( hdList, hdPoss, hdVals );
}
long            PosVector ( hdList, hdVal, start )
TypHandle           hdList;
TypHandle           hdVal;
long                start;
{
long                lenList;
TypHandle           hdElm;
long                i;
lenList = LEN_PLIST( hdList );
for ( i = start+1; i <= lenList; i++ ) {
hdElm = ELM_PLIST( hdList, i );
if ( hdElm == hdVal || EQ( hdElm, hdVal ) == HdTrue )
break;
}
return (lenList < i ? 0 : i);
}
void            PlainVector ( hdList )
TypHandle           hdList;
{
return;
}
long            IsDenseVector ( hdList )
TypHandle           hdList;
{
return 1;
}
long            IsPossVector ( hdList )
TypHandle           hdList;
{
long                lenList;
TypHandle           hdElm;
long                i;
lenList = LEN_PLIST( hdList );
for ( i = 1; i <= lenList; i++ ) {
hdElm = ELM_PLIST( hdList, i );
if ( TYPE(hdElm) != T_INT || HD_TO_INT(hdElm) <= 0 )
return 0;
}
return 1;
}
long            IsXTypeVector ( hdList )
TypHandle           hdList;
{
long                isVector;
unsigned long       len;
TypHandle           hdElm;
unsigned long       i;
if ( TYPE( hdList ) == T_VECTOR ) {
isVector = (TYPE(ELM_PLIST(hdList,1)) <= T_UNKNOWN) ? 1 : 2;
}
else if ( TYPE(hdList) == T_RANGE ) {
PLAIN_LIST( hdList );
Retype( hdList, T_VECTOR );
isVector = 1;
}
else if ( TYPE(hdList) != T_LIST && TYPE(hdList) != T_SET ) {
isVector = 0;
}
else if ( LEN_PLIST( hdList ) == 0 || ELM_PLIST( hdList, 1 ) == 0 ) {
isVector = 0;
}
else if ( TYPE( ELM_PLIST( hdList, 1 ) ) <= T_UNKNOWN ) {
len = LEN_PLIST( hdList );
for ( i = 2; i <= len; i++ ) {
hdElm = ELM_PLIST( hdList, i );
if ( hdElm == 0 || T_UNKNOWN < TYPE(hdElm) )
break;
}
isVector = (len < i) ? 1 : 0;
if ( len < i ) {
Retype( hdList, T_VECTOR );
}
}
else if ( TYPE( ELM_PLIST( hdList, 1 ) ) == T_REC ) {
len = LEN_PLIST( hdList );
for ( i = 2; i <= len; i++ ) {
hdElm = ELM_PLIST( hdList, i );
if ( hdElm == 0 || TYPE(hdElm) != T_REC )
break;
}
isVector = (len < i) ? 2 : 0;
if ( isVector ) {
Retype( hdList, T_VECTOR );
}
}
else {
isVector = 0;
}
return isVector;
}
long            IsXTypeMatrix ( hdList )
TypHandle           hdList;
{
long                isMatrix;
unsigned long       cols;
unsigned long       len;
TypHandle           hdElm;
unsigned long       i;
if ( TYPE(hdList) != T_LIST && TYPE(hdList) != T_SET ) {
isMatrix = 0;
}
else if ( LEN_PLIST( hdList ) == 0 || ELM_PLIST( hdList, 1 ) == 0 ) {
isMatrix = 0;
}
else if ( IsXTypeVector( ELM_PLIST( hdList, 1 ) ) == 1 ) {
cols = LEN_PLIST( ELM_PLIST( hdList, 1 ) );
len = LEN_PLIST( hdList );
for ( i = 2; i <= len; i++ ) {
hdElm = ELM_PLIST( hdList, i );
if ( hdElm == 0
|| IsXTypeVector( hdElm ) != 1
|| LEN_PLIST( hdElm ) != cols ) {
break;
}
}
isMatrix = (len < i) ? 1 : 0;
}
else if ( IsXTypeVector( ELM_PLIST( hdList, 1 ) ) == 2 ) {
cols = LEN_PLIST( ELM_PLIST( hdList, 1 ) );
len = LEN_PLIST( hdList );
for ( i = 2; i <= len; i++ ) {
hdElm = ELM_PLIST( hdList, i );
if ( hdElm == 0
|| IsXTypeVector( hdElm ) != 2
|| LEN_PLIST( hdElm ) != cols ) {
break;
}
}
isMatrix = (len < i) ? 2 : 0;
}
else {
isMatrix = 0;
}
return isMatrix;
}
TypHandle       EqVector ( hdL, hdR )
TypHandle           hdL;
TypHandle           hdR;
{
unsigned long       lenL;
unsigned long       lenR;
TypHandle           hdElmL;
TypHandle           hdElmR;
unsigned long       i;
lenL = LEN_PLIST( hdL );
lenR = LEN_PLIST( hdR );
if ( lenL != lenR ) {
return HdFalse;
}
for ( i = 1; i <= lenL; i++ ) {
hdElmL = ELM_PLIST( hdL, i );
hdElmR = ELM_PLIST( hdR, i );
if ( hdElmL != hdElmR && EQ( hdElmL, hdElmR ) == HdFalse ) {
return HdFalse;
}
}
return HdTrue;
}
TypHandle       LtVector ( hdL, hdR )
TypHandle           hdL;
TypHandle           hdR;
{
unsigned long       lenL;
unsigned long       lenR;
TypHandle           hdElmL;
TypHandle           hdElmR;
unsigned long       i;
lenL = LEN_PLIST( hdL );
lenR = LEN_PLIST( hdR );
for ( i = 1; i <= lenL && i <= lenR; i++ ) {
hdElmL = ELM_PLIST( hdL, i );
hdElmR = ELM_PLIST( hdR, i );
if ( hdElmL != hdElmR && EQ( hdElmL, hdElmR ) == HdFalse ) {
return LT( hdElmL, hdElmR );
}
}
return (lenL < lenR) ? HdTrue : HdFalse;
}
TypHandle       SumIntVector ( hdL, hdR )
TypHandle           hdL;
TypHandle           hdR;
{
TypHandle           hdS;
TypHandle *         ptS;
TypHandle           hdSS;
TypHandle *         ptR;
TypHandle           hdRR;
unsigned long       len;
unsigned long       isVec;
unsigned long       i;
EnterKernel();
len = LEN_PLIST( hdR );
hdS = NewBag( T_LIST, SIZE_PLEN_PLIST( len ) );
SET_LEN_PLIST( hdS, len );
isVec = 1;
ptR = PTR( hdR );
ptS = PTR( hdS );
for ( i = 1; i <= len; i++ ) {
hdRR = ptR[i];
hdSS = (TypHandle)((long)hdL + (long)hdRR - T_INT);
if ( (((long)hdSS) & 3) != T_INT
|| ((((SPEC_INT32_T)hdSS)<<1)>>1) != ((SPEC_INT32_T)hdSS) ) {
hdSS = SUM( hdL, hdRR );
ptR  = PTR( hdR );
ptS  = PTR( hdS );
isVec = isVec && TYPE(hdSS) <= T_UNKNOWN;
}
ptS[i] = hdSS;
}
if ( isVec )  Retype( hdS, T_VECTOR );
ExitKernel( hdS );
return hdS;
}
TypHandle       SumVectorInt ( hdL, hdR )
TypHandle           hdL;
TypHandle           hdR;
{
TypHandle           hdS;
TypHandle *         ptS;
TypHandle           hdSS;
TypHandle *         ptL;
TypHandle           hdLL;
unsigned long       len;
unsigned long       isVec;
unsigned long       i;
EnterKernel();
len = LEN_PLIST( hdL );
hdS = NewBag( T_LIST, SIZE_PLEN_PLIST( len ) );
SET_LEN_PLIST( hdS, len );
isVec = 1;
ptL = PTR( hdL );
ptS = PTR( hdS );
for ( i = 1; i <= len; i++ ) {
hdLL = ptL[i];
hdSS = (TypHandle)((long)hdLL + (long)hdR - T_INT);
if ( (((long)hdSS) & 3) != T_INT
|| ((((SPEC_INT32_T)hdSS)<<1)>>1) != ((SPEC_INT32_T)hdSS) ) {
hdSS = SUM( hdLL, hdR );
ptL  = PTR( hdL );
ptS  = PTR( hdS );
isVec = isVec && TYPE(hdSS) <= T_UNKNOWN;
}
ptS[i] = hdSS;
}
if ( isVec )  Retype( hdS, T_VECTOR );
ExitKernel( hdS );
return hdS;
}
TypHandle       SumVectorVector ( hdL, hdR )
TypHandle           hdL;
TypHandle           hdR;
{
TypHandle           hdS;
TypHandle *         ptS;
TypHandle           hdSS;
TypHandle *         ptL;
TypHandle           hdLL;
TypHandle *         ptR;
TypHandle           hdRR;
unsigned long       len;
unsigned long       isVec;
unsigned long       i;
EnterKernel();
len = LEN_PLIST( hdL );
if ( len != LEN_PLIST( hdR ) ) {
return Error(
"Vector +: vectors must have the same length",
0L, 0L );
}
hdS = NewBag( T_LIST, SIZE_PLEN_PLIST( len ) );
SET_LEN_PLIST( hdS, len );
isVec = 1;
ptL = PTR( hdL );
ptR = PTR( hdR );
ptS = PTR( hdS );
for ( i = 1; i <= len; i++ ) {
hdLL = ptL[i];
hdRR = ptR[i];
hdSS = (TypHandle)((long)hdLL + (long)hdRR - T_INT);
if ( (((long)hdSS) & 3) != T_INT
|| ((((SPEC_INT32_T)hdSS)<<1)>>1) != ((SPEC_INT32_T)hdSS) ) {
hdSS = SUM( hdLL, hdRR );
ptL  = PTR( hdL );
ptR  = PTR( hdR );
ptS  = PTR( hdS );
isVec = isVec && TYPE(hdSS) <= T_UNKNOWN;
}
ptS[i] = hdSS;
}
if ( isVec )  Retype( hdS, T_VECTOR );
ExitKernel( hdS );
return hdS;
}
TypHandle       DiffIntVector ( hdL, hdR )
TypHandle           hdL;
TypHandle           hdR;
{
TypHandle           hdD;
TypHandle *         ptD;
TypHandle           hdDD;
TypHandle *         ptR;
TypHandle           hdRR;
unsigned long       len;
unsigned long       isVec;
unsigned long       i;
EnterKernel();
len = LEN_PLIST( hdR );
hdD = NewBag( T_LIST, SIZE_PLEN_PLIST( len ) );
SET_LEN_PLIST( hdD, len );
isVec = 1;
ptR = PTR( hdR );
ptD = PTR( hdD );
for ( i = 1; i <= len; i++ ) {
hdRR = ptR[i];
hdDD = (TypHandle)((long)hdL - (long)hdRR + T_INT);
if ( (((long)hdDD) & 3) != T_INT || (((long)hdL) & 3) != T_INT
|| ((((SPEC_INT32_T)hdDD)<<1)>>1) != ((SPEC_INT32_T)hdDD) ) {
hdDD = DIFF( hdL, hdRR );
ptR  = PTR( hdR );
ptD  = PTR( hdD );
isVec = isVec && TYPE(hdDD) <= T_UNKNOWN;
}
ptD[i] = hdDD;
}
if ( isVec )  Retype( hdD, T_VECTOR );
ExitKernel( hdD );
return hdD;
}
TypHandle       DiffVectorInt ( hdL, hdR )
TypHandle           hdL;
TypHandle           hdR;
{
TypHandle           hdD;
TypHandle *         ptD;
TypHandle           hdDD;
TypHandle *         ptL;
TypHandle           hdLL;
unsigned long       len;
unsigned long       isVec;
unsigned long       i;
EnterKernel();
len = LEN_PLIST( hdL );
hdD = NewBag( T_LIST, SIZE_PLEN_PLIST( len ) );
SET_LEN_PLIST( hdD, len );
isVec = 1;
ptL = PTR( hdL );
ptD = PTR( hdD );
for ( i = 1; i <= len; i++ ) {
hdLL = ptL[i];
hdDD = (TypHandle)((long)hdLL - (long)hdR + T_INT);
if ( (((long)hdDD) & 3) != T_INT || (((long)hdLL) & 3) != T_INT
|| ((((SPEC_INT32_T)hdDD)<<1)>>1) != ((SPEC_INT32_T)hdDD) ) {
hdDD = DIFF( hdLL, hdR );
ptL  = PTR( hdL );
ptD  = PTR( hdD );
isVec = isVec && TYPE(hdDD) <= T_UNKNOWN;
}
ptD[i] = hdDD;
}
if ( isVec )  Retype( hdD, T_VECTOR );
ExitKernel( hdD );
return hdD;
}
TypHandle       DiffVectorVector ( hdL, hdR )
TypHandle           hdL;
TypHandle           hdR;
{
TypHandle           hdD;
TypHandle *         ptD;
TypHandle           hdDD;
TypHandle *         ptL;
TypHandle           hdLL;
TypHandle *         ptR;
TypHandle           hdRR;
unsigned long       len;
unsigned long       isVec;
unsigned long       i;
EnterKernel();
len = LEN_PLIST( hdL );
if ( len != LEN_PLIST( hdR ) ) {
return Error(
"Vector -: vectors must have the same length",
0L, 0L );
}
hdD = NewBag( T_LIST, SIZE_PLEN_PLIST( len ) );
SET_LEN_PLIST( hdD, len );
isVec = 1;
ptL = PTR( hdL );
ptR = PTR( hdR );
ptD = PTR( hdD );
for ( i = 1; i <= len; i++ ) {
hdLL = ptL[i];
hdRR = ptR[i];
hdDD = (TypHandle)((long)hdLL - (long)hdRR + T_INT);
if ( (((long)hdDD) & 3) != T_INT || (((long)hdLL) & 3) != T_INT
|| ((((SPEC_INT32_T)hdDD)<<1)>>1) != ((SPEC_INT32_T)hdDD) ) {
hdDD = DIFF( hdLL, hdRR );
ptL  = PTR( hdL );
ptR  = PTR( hdR );
ptD  = PTR( hdD );
isVec = isVec && TYPE(hdDD) <= T_UNKNOWN;
}
ptD[i] = hdDD;
}
if ( isVec )  Retype( hdD, T_VECTOR );
ExitKernel( hdD );
return hdD;
}
TypHandle       ProdIntVector ( hdL, hdR )
TypHandle           hdL;
TypHandle           hdR;
{
TypHandle           hdP;
TypHandle *         ptP;
TypHandle           hdPP;
TypHandle *         ptR;
TypHandle           hdRR;
unsigned long       len;
unsigned long       isVec;
unsigned long       i;
EnterKernel();
len = LEN_PLIST( hdR );
hdP = NewBag( T_LIST, SIZE_PLEN_PLIST( len ) );
SET_LEN_PLIST( hdP, len );
isVec = 1;
ptR = PTR( hdR );
ptP = PTR( hdP );
for ( i = 1; i <= len; i++ ) {
hdRR = ptR[i];
hdPP = (TypHandle)(((long)hdL-T_INT) * ((long)hdRR>>1));
if ( ((long)hdRR & 3) != T_INT
|| (((long)hdRR >> 1) != 0
&& (long)hdPP / ((long)hdRR>>1) != ((long)hdL-T_INT)) ) {
hdPP = PROD( hdL, hdRR );
ptR  = PTR( hdR );
ptP  = PTR( hdP );
isVec = isVec && TYPE(hdPP) <= T_UNKNOWN;
}
else {
hdPP = (TypHandle)(((long)hdPP>>1) + T_INT);
}
ptP[i] = hdPP;
}
if ( isVec )  Retype( hdP, T_VECTOR );
ExitKernel( hdP );
return hdP;
}
TypHandle       ProdVectorInt ( hdL, hdR )
TypHandle           hdL;
TypHandle           hdR;
{
TypHandle           hdP;
TypHandle *         ptP;
TypHandle           hdPP;
TypHandle *         ptL;
TypHandle           hdLL;
unsigned long       len;
unsigned long       isVec;
unsigned long       i;
EnterKernel();
len = LEN_PLIST( hdL );
hdP = NewBag( T_LIST, SIZE_PLEN_PLIST( len ) );
SET_LEN_PLIST( hdP, len );
isVec = 1;
ptL = PTR( hdL );
ptP = PTR( hdP );
for ( i = 1; i <= len; i++ ) {
hdLL = ptL[i];
hdPP = (TypHandle)(((long)hdLL-T_INT) * ((long)hdR>>1));
if ( ((long)hdLL & 3) != T_INT
|| (((long)hdR>>1) != 0
&& (long)hdPP / ((long)hdR>>1) != ((long)hdLL-T_INT)) ) {
hdPP = PROD( hdLL, hdR );
ptL  = PTR( hdL );
ptP  = PTR( hdP );
isVec = isVec && TYPE(hdPP) <= T_UNKNOWN;
}
else {
hdPP = (TypHandle)(((long)hdPP>>1) + T_INT);
}
ptP[i] = hdPP;
}
if ( isVec )  Retype( hdP, T_VECTOR );
ExitKernel( hdP );
return hdP;
}
TypHandle       ProdVectorVector ( hdL, hdR )
TypHandle           hdL;
TypHandle           hdR;
{
TypHandle           hdP;
TypHandle           hdPP;
TypHandle           hdSS;
TypHandle *         ptL;
TypHandle           hdLL;
TypHandle *         ptR;
TypHandle           hdRR;
unsigned long       len;
unsigned long       i;
EnterKernel();
len = LEN_PLIST( hdL );
if ( len != LEN_PLIST( hdR ) ) {
return Error(
"Vector *: vectors must have the same length",
0L, 0L );
}
ptL = PTR( hdL );
ptR = PTR( hdR );
hdLL = ptL[1];
hdRR = ptR[1];
hdPP = (TypHandle)(((long)hdLL-T_INT) * ((long)hdRR>>1));
if ( ((long)hdLL & 3) != T_INT || ((long)hdRR & 3) != T_INT
|| (((long)hdRR>>1) != 0
&& (long)hdPP / ((long)hdRR>>1) != ((long)hdLL-T_INT)) ) {
hdPP = PROD( hdLL, hdRR );
ptL  = PTR( hdL );
ptR  = PTR( hdR );
}
else {
hdPP = (TypHandle)(((long)hdPP >> 1) + T_INT);
}
hdP = hdPP;
for ( i = 2; i <= len; i++ ) {
hdLL = ptL[i];
hdRR = ptR[i];
hdPP = (TypHandle)(((long)hdLL-T_INT) * ((long)hdRR>>1));
if ( ((long)hdLL & 3) != T_INT || ((long)hdRR & 3) != T_INT
|| (((long)hdRR>>1) != 0
&& (long)hdPP / ((long)hdRR>>1) != ((long)hdLL-T_INT)) ) {
hdPP = PROD( hdLL, hdRR );
ptL  = PTR( hdL );
ptR  = PTR( hdR );
}
else {
hdPP = (TypHandle)(((long)hdPP>>1) + T_INT);
}
hdSS = (TypHandle)((long)hdP + (long)hdPP - T_INT);
if ( (((long)hdSS) & 3) != T_INT
|| ((((SPEC_INT32_T)hdSS)<<1)>>1) != ((SPEC_INT32_T)hdSS) ) {
hdSS = SUM( hdP, hdPP );
ptL  = PTR( hdL );
ptR  = PTR( hdR );
}
hdP = hdSS;
}
ExitKernel( hdP );
return hdP;
}
TypHandle       ProdVectorMatrix ( hdL, hdR )
TypHandle           hdL;
TypHandle           hdR;
{
TypHandle           hdP;
TypHandle *         ptP;
TypHandle           hdPP;
TypHandle           hdSS;
TypHandle           hdQQ;
TypHandle           hdLL;
TypHandle           hdRR;
TypHandle *         ptRR;
TypHandle           hdRRR;
unsigned long       len;
unsigned long       col;
unsigned long       isVec;
unsigned long       i, k;
len = LEN_PLIST( hdL );
col = LEN_PLIST( ELM_PLIST( hdR, 1 ) );
if ( len != LEN_PLIST( hdR ) )
return Error("Vector *: vectors must have the same length",0L,0L);
hdP = PROD( ELM_PLIST( hdL, 1 ), ELM_PLIST( hdR, 1 ) );
isVec = (TYPE(hdP) == T_VECTOR);
for ( i = 2; i <= len; i++ ) {
EnterKernel();
hdLL = ELM_PLIST( hdL, i );
hdRR = ELM_PLIST( hdR, i );
ptRR = PTR( hdRR );
ptP  = PTR( hdP  );
if ( hdLL == INT_TO_HD(1) ) {
for ( k = 1; k <= col; k++ ) {
hdRRR = ptRR[k];
hdPP = ptP[k];
hdSS = (TypHandle)((long)hdPP + (long)hdRRR - T_INT);
if ( (((long)hdSS) & 3) != T_INT
|| ((((SPEC_INT32_T)hdSS)<<1)>>1) != ((SPEC_INT32_T)hdSS) ) {
hdSS = SUM( hdPP, hdRRR );
ptRR = PTR( hdRR );
ptP  = PTR( hdP );
isVec = isVec && TYPE(hdSS) <= T_UNKNOWN;
}
ptP[k] = hdSS;
}
}
else if ( hdLL == INT_TO_HD(-1) ) {
for ( k = 1; k <= col; k++ ) {
hdRRR = ptRR[k];
hdPP = ptP[k];
hdSS = (TypHandle)((long)hdPP - (long)hdRRR + T_INT);
if ( (((long)hdSS) & 3) != T_INT
|| (((long)hdPP) & 3) != T_INT
|| ((((SPEC_INT32_T)hdSS)<<1)>>1) != ((SPEC_INT32_T)hdSS) ) {
hdSS = DIFF( hdPP, hdRRR );
ptRR = PTR( hdRR );
ptP  = PTR( hdP );
isVec = isVec && TYPE(hdSS) <= T_UNKNOWN;
}
ptP[k] = hdSS;
}
}
else if ( hdLL != INT_TO_HD(0) ) {
for ( k = 1; k <= col; k++ ) {
hdRRR = ptRR[k];
hdPP = (TypHandle)(((long)hdLL-T_INT) * ((long)hdRRR>>1));
if ( ((long)hdLL & 3) != T_INT || ((long)hdRRR & 3) != T_INT
|| (((long)hdRRR>>1) != 0
&& (long)hdPP / ((long)hdRRR>>1) != ((long)hdLL-T_INT))) {
hdPP = PROD( hdLL, hdRRR );
ptRR = PTR( hdRR );
ptP  = PTR( hdP );
}
else {
hdPP = (TypHandle)(((long)hdPP>>1) + T_INT);
}
hdQQ = ptP[k];
hdSS = (TypHandle)((long)hdQQ + (long)hdPP - T_INT);
if ( (((long)hdSS) & 3) != T_INT
|| ((((SPEC_INT32_T)hdSS)<<1)>>1) != ((SPEC_INT32_T)hdSS) ) {
hdSS = SUM( hdQQ, hdPP );
ptRR = PTR( hdRR );
ptP  = PTR( hdP );
isVec = isVec && TYPE(hdSS) <= T_UNKNOWN;
}
ptP[k] = hdSS;
}
}
ExitKernel( (TypHandle)0 );
}
if ( isVec )  Retype( hdP, T_VECTOR );
return hdP;
}
TypHandle       PowMatrixInt ( hdL, hdR )
TypHandle           hdL;
TypHandle           hdR;
{
TypHandle           hdP = 0;
TypHandle           hdPP;
TypHandle           hdQQ;
TypHandle           hdPPP;
TypHandle           hdLL;
TypHandle           hdOne;
TypHandle           hdZero;
TypHandle           hdTmp;
unsigned long       len;
long                e;
unsigned long       i, k, l;
len = LEN_PLIST( hdL );
if ( len != LEN_PLIST( ELM_PLIST( hdL, 1 ) ) ) {
return Error(
"Matrix operations ^: <mat> must be square",
0L,0L);
}
hdOne = POW( ELM_PLIST( ELM_PLIST( hdL, 1 ), 1 ), INT_TO_HD(0) );
hdZero = DIFF( hdOne, hdOne );
if ( TYPE(hdR) == T_INT && hdR == INT_TO_HD(0) ) {
hdP = NewBag( T_LIST, SIZE_PLEN_PLIST( len ) );
SET_LEN_PLIST( hdP, len );
for ( i = 1; i <= len; i++ ) {
hdPP = NewBag( T_VECTOR, SIZE_PLEN_PLIST( len ) );
SET_LEN_PLIST( hdPP, len );
SET_ELM_PLIST( hdP, i, hdPP );
}
for ( i = 1; i <= len; i++ ) {
hdPP = ELM_PLIST( hdP, i );
for ( k = 1; k <= len; k++ )
SET_ELM_PLIST( hdPP, k, hdZero );
SET_ELM_PLIST( hdPP, i, hdOne );
}
}
if ( TYPE(hdR) == T_INT && hdR == INT_TO_HD(1) ) {
hdP = NewBag( T_LIST, SIZE_PLEN_PLIST( len ) );
SET_LEN_PLIST( hdP, len );
for ( i = 1; i <= len; i++ ) {
hdPP = NewBag( T_VECTOR, SIZE_PLEN_PLIST( len ) );
SET_LEN_PLIST( hdPP, len );
SET_ELM_PLIST( hdP, i, hdPP );
}
for ( i = 1; i <= len; i++ ) {
hdPP = ELM_PLIST( hdP, i );
hdLL = ELM_PLIST( hdL, i );
for ( k = 1; k <= len; k++ )
SET_ELM_PLIST( hdPP, k, ELM_PLIST( hdLL, k )  );
}
}
if ( (TYPE(hdR) == T_INT && HD_TO_INT(hdR) < 0)
|| (TYPE(hdR) == T_INTNEG) ) {
hdP = NewBag( T_LIST, SIZE_PLEN_PLIST( len ) );
SET_LEN_PLIST( hdP, len );
for ( i = 1; i <= len; i++ ) {
hdPP = NewBag( T_VECTOR, SIZE_PLEN_PLIST( 2 * len ) );
SET_LEN_PLIST( hdPP, len );
SET_ELM_PLIST( hdP, i, hdPP );
}
for ( i = 1; i <= len; i++ ) {
hdPP = ELM_PLIST( hdP, i );
for ( k = 1; k <= len; k++ )
SET_ELM_PLIST( hdPP, k, hdZero );
SET_ELM_PLIST( hdPP, i, hdOne );
}
for ( i = 1; i <= len; i++ ) {
hdPP = ELM_PLIST( hdP, i );
hdLL = ELM_PLIST( hdL, i );
for ( k = 1; k <= len; k++ )
SET_ELM_PLIST( hdPP, k + len, ELM_PLIST( hdLL, k )  );
}
for ( k = len+1; k <= 2*len; k++ ) {
EnterKernel();
for ( i = k-len;
i <= len
&& (ELM_PLIST( ELM_PLIST(hdP,i), k ) == hdZero
|| EQ( ELM_PLIST( ELM_PLIST(hdP,i), k ), hdZero ) == HdTrue);
i++ )
;
if ( len < i )
return Error("Matrix: <mat> must be invertible",0L,0L);
hdPP = ELM_PLIST( hdP, i );
SET_ELM_PLIST( hdP, i, ELM_PLIST( hdP, k-len ) );
SET_ELM_PLIST( hdP, k-len, hdPP );
hdPPP = POW( ELM_PLIST( hdPP, k ), INT_TO_HD(-1) );
for ( l = 1; l <= 2*len; l++ ) {
hdTmp = PROD( hdPPP, ELM_PLIST( hdPP, l ) );
SET_ELM_PLIST( hdPP, l, hdTmp );
}
for ( i = 1; i <= len; i++ ) {
hdQQ = ELM_PLIST( hdP, i );
hdPPP = DIFF( hdZero, ELM_PLIST( hdQQ, k ) );
if ( i != k-len
&& hdPPP != hdZero
&& EQ( hdPPP, hdZero ) == HdFalse ) {
for ( l = 1; l <= 2*len; l++ ) {
hdTmp = PROD( hdPPP, ELM_PLIST( hdPP, l ) );
hdTmp = SUM( ELM_PLIST( hdQQ, l ), hdTmp );
SET_ELM_PLIST( hdQQ, l, hdTmp );
}
}
}
ExitKernel( (TypHandle)0 );
}
for ( i = 1; i <= len; i++ ) {
Resize( ELM_PLIST( hdP, i ), SIZE_PLEN_PLIST( len ) );
SET_LEN_PLIST( ELM_PLIST( hdP, i ), len );
}
hdL = hdP;
if ( TYPE(hdR) == T_INT )  hdR = INT_TO_HD( -HD_TO_INT(hdR) );
}
if ( TYPE(hdR) == T_INT && 1 < HD_TO_INT(hdR) ) {
hdP = 0;
k = (size_t)1 << 31;
e = HD_TO_INT(hdR);
while ( 1 < k ) {
hdP = (hdP == 0 ? hdP : ProdListScl( hdP, hdP ));
k = k / 2;
if ( k <= e ) {
hdP = (hdP == 0 ? hdL : ProdListScl( hdP, hdL ));
e = e - k;
}
}
}
if ( TYPE(hdR) != T_INT ) {
hdP = 0;
for ( i = SIZE(hdR)/sizeof(TypDigit); 0 < i; i-- ) {
k = (size_t)1 << (8*sizeof(TypDigit));
e = ((TypDigit*) PTR(hdR))[i-1];
while ( 1 < k ) {
hdP = (hdP == 0 ? hdP : ProdListScl( hdP, hdP ));
k = k / 2;
if ( k <= e ) {
hdP = (hdP == 0 ? hdL : ProdListScl( hdP, hdL ));
e = e - k;
}
}
}
}
return hdP;
}
void            InitVector ()
{
unsigned long       type;
TabIsList     [T_VECTOR] = 2;
TabIsList     [T_MATRIX] = 3;
TabLenList    [T_VECTOR] = LenVector;
TabElmList    [T_VECTOR] = ElmVector;
TabElmfList   [T_VECTOR] = ElmfVector;
TabElmlList   [T_VECTOR] = ElmfVector;
TabElmrList   [T_VECTOR] = ElmfVector;
TabElmsList   [T_VECTOR] = ElmsVector;
TabAssList    [T_VECTOR] = AssVector;
TabAsssList   [T_VECTOR] = AsssVector;
TabPosList    [T_VECTOR] = PosVector;
TabPlainList  [T_VECTOR] = PlainVector;
TabIsDenseList[T_VECTOR] = IsDenseVector;
TabIsPossList [T_VECTOR] = IsPossVector;
TabIsXTypeList[T_VECTOR] = IsXTypeVector;
TabIsXTypeList[T_MATRIX] = IsXTypeMatrix;
EvTab[T_VECTOR] = EvList;
PrTab[T_VECTOR] = PrList;
TabEq[T_VECTOR][T_VECTOR] = EqVector;
TabLt[T_VECTOR][T_VECTOR] = LtVector;
for ( type = T_INT; type <= T_FFE; type++ ) {
TabSum [type    ][T_VECTOR] = SumSclList;
TabSum [T_VECTOR][type    ] = SumListScl;
TabSum [type    ][T_MATRIX] = SumSclList;
TabSum [T_MATRIX][type    ] = SumListScl;
}
TabSum [T_INT   ][T_VECTOR] = SumIntVector;
TabSum [T_VECTOR][T_INT   ] = SumVectorInt;
TabSum [T_VECTOR][T_VECTOR] = SumVectorVector;
TabSum [T_MATRIX][T_MATRIX] = SumListList;
for ( type = T_INT; type <= T_FFE; type++ ) {
TabDiff[type    ][T_VECTOR] = DiffSclList;
TabDiff[T_VECTOR][type    ] = DiffListScl;
TabDiff[type    ][T_MATRIX] = DiffSclList;
TabDiff[T_MATRIX][type    ] = DiffListScl;
}
TabDiff[T_INT   ][T_VECTOR] = DiffIntVector;
TabDiff[T_VECTOR][T_INT   ] = DiffVectorInt;
TabDiff[T_VECTOR][T_VECTOR] = DiffVectorVector;
TabDiff[T_MATRIX][T_MATRIX] = DiffListList;
for ( type = T_INT; type <= T_FFE; type++ ) {
TabProd[type    ][T_VECTOR] = ProdSclList;
TabProd[T_VECTOR][type    ] = ProdListScl;
TabProd[type    ][T_MATRIX] = ProdSclList;
TabProd[T_MATRIX][type    ] = ProdListScl;
}
TabProd[T_INT   ][T_VECTOR] = ProdIntVector;
TabProd[T_VECTOR][T_INT   ] = ProdVectorInt;
TabProd[T_VECTOR][T_VECTOR] = ProdVectorVector;
TabProd[T_VECTOR][T_MATRIX] = ProdVectorMatrix;
TabProd[T_MATRIX][T_VECTOR] = ProdListScl;
TabProd[T_MATRIX][T_MATRIX] = ProdListScl;
TabProd[T_VECTOR][T_LISTX ] = ProdListList;
TabProd[T_MATRIX][T_LISTX ] = ProdSclList;
TabProd[T_LISTX ][T_MATRIX] = ProdListScl;
for ( type = T_INT; type <= T_FFE; type++ ) {
TabQuo [T_VECTOR][type    ] = QuoLists;
TabQuo [type    ][T_MATRIX] = QuoLists;
TabQuo [T_MATRIX][type    ] = QuoLists;
}
TabQuo [T_VECTOR][T_MATRIX] = QuoLists;
TabQuo [T_MATRIX][T_MATRIX] = QuoLists;
TabQuo [T_LISTX ][T_MATRIX] = QuoLists;
for ( type = T_INT; type <= T_FFE; type++ ) {
TabMod [type    ][T_VECTOR] = ModLists;
TabMod [type    ][T_MATRIX] = ModLists;
TabMod [T_MATRIX][type    ] = ModLists;
}
TabMod [T_MATRIX][T_VECTOR] = ModLists;
TabMod [T_MATRIX][T_MATRIX] = ModLists;
TabMod [T_MATRIX][T_LISTX ] = ModLists;
TabPow [T_MATRIX][T_INT   ] = PowMatrixInt;
TabPow [T_MATRIX][T_INTPOS] = PowMatrixInt;
TabPow [T_MATRIX][T_INTNEG] = PowMatrixInt;
TabPow [T_VECTOR][T_MATRIX] = ProdVectorMatrix;
TabPow [T_MATRIX][T_MATRIX] = PowLists;
TabComm[T_MATRIX][T_MATRIX] = CommLists;
}
/* 当前文件是D:\Read\word.c*/

#ifndef SPEC_INT32_T
#define	SPEC_INT32_T	int
#endif
TypHandle       SwordWord ( hdLst, hdWrd )
TypHandle       hdLst;
TypHandle       hdWrd;
{
TypHandle       hdSwrd,  * ptLst,  * ptEnd,  * ptG;
TypSword        * ptSwrd;
long            len,  lnSwrd,  i,  exp;
len = SIZE( hdWrd ) / SIZE_HD;
hdSwrd = NewBag( T_SWORD, SIZE_HD + 2 * SIZE_SWORD * len + SIZE_SWORD );
ptEnd  = PTR( hdWrd ) + len - 1;
ptLst  = PTR( hdLst ) + 1;
len    = LEN_LIST( hdLst );
PTR( hdSwrd )[0] = hdLst;
ptSwrd = (TypSword*)( PTR( hdSwrd ) + 1 );
lnSwrd = 0;
for ( ptG = PTR( hdWrd ); ptG <= ptEnd; ptG++ )
{
for ( i = len - 1; i >= 0; i-- )
if ( ptLst[i] == *ptG || ptLst[i] == *PTR( *ptG ) )
break;
if ( i < 0 )
return HdFalse;
exp = 1;
while ( ptG < ptEnd && ptG[0] == ptG[1] )
{
ptG++;
exp++;
}
if ( ptLst[ i ] == *PTR( *ptG ) )
exp = -exp;
*ptSwrd++ = i;
*ptSwrd++ = exp;
	if ( MAX_SWORD_NR <= exp )
	    return Error( "SwordWord: exponent overflow", 0L, 0L );
lnSwrd++;
}
*ptSwrd = -1;
Resize( hdSwrd, SIZE_HD + ( 2 * lnSwrd + 1 ) * SIZE_SWORD );
return hdSwrd;
}
TypHandle       WordSword ( hdSwrd )
TypHandle       hdSwrd;
{
TypHandle       hdWrd, * ptWrd, * ptLst, hdAgn;
TypSword        * ptSwrd;
long            len, i;
len    = 0;
ptSwrd = (TypSword*)( PTR( hdSwrd ) + 1 );
while ( *ptSwrd != -1 )
{
len    += ( ptSwrd[1] < 0 ) ? ( -ptSwrd[1] ) : ptSwrd[1];
ptSwrd += 2;
}
hdWrd  = NewBag( T_WORD, len * SIZE_HD );
ptWrd  = PTR( hdWrd );
ptSwrd = (TypSword*)( PTR( hdSwrd ) + 1 );
if ( TYPE( *PTR( hdSwrd ) ) == T_AGGRP )
ptLst = PTR( HD_WORDS( *PTR( hdSwrd ) ) ) + 1;
else
ptLst = PTR( *PTR( hdSwrd ) ) + 1;
while ( *ptSwrd != -1 )
{
if ( ptSwrd[1] > 0 )
{
hdAgn = ptLst[ ptSwrd[ 0 ] ];
len   = ptSwrd[ 1 ];
}
else
{
hdAgn = *PTR( ptLst[ ptSwrd[ 0 ] ] );
len   = -ptSwrd[ 1 ];
}
for ( i = len; i > 0; i-- )
*ptWrd++ = hdAgn;
ptSwrd += 2;
}
return hdWrd;
}
TypHandle       SwordSword ( hdLst, hdSwrd )
TypHandle       hdLst;
TypHandle       hdSwrd;
{
if ( *PTR( hdSwrd ) == hdLst )
return hdSwrd;
return SwordWord( hdLst, WordSword( hdSwrd ) );
}
TypHandle       EvWord ( hdWord )
TypHandle       hdWord;
{
return hdWord;
}
TypHandle       ProdWord ( hdL, hdR )
TypHandle       hdL,  hdR;
{
SPEC_INT32_T      lnL,  lnR,  lnRR, e;
TypHandle       * ptL,  * ptR,  * ptRes;
TypHandle       hdRes, hdLstL, hdLstR;
TypSword        * gtL,  * gtR,  * gtRes;
if ( TYPE( hdL ) == T_WORD && SIZE( hdL ) == 0 )
return hdR;
if ( TYPE( hdL ) == T_SWORD && SIZE( hdL ) == SIZE_HD + SIZE_SWORD )
return hdR;
if ( TYPE( hdR ) == T_WORD && SIZE( hdR ) == 0 )
return hdL;
if ( TYPE( hdR ) == T_SWORD && SIZE( hdR ) == SIZE_HD + SIZE_SWORD )
return hdL;
if ( TYPE( hdL ) == T_WORD || TYPE( hdR ) == T_WORD )
{
if ( TYPE( hdL ) == T_SWORD )
hdL = WordSword( hdL );
if ( TYPE( hdR ) == T_SWORD )
hdR = WordSword( hdR );
lnL = SIZE( hdL ) / SIZE_HD;  ptL = PTR( hdL ) + lnL - 1;
lnR = SIZE( hdR ) / SIZE_HD;  ptR = PTR( hdR );
while ( 0 < lnL && 0 < lnR && *ptL == *PTR( *ptR ) )
{
--lnL;  --ptL;
--lnR;  ++ptR;
}
if ( lnL + lnR == 0 )
return HdIdWord;
hdRes = NewBag( T_WORD, ( lnL + lnR ) * SIZE_HD );
ptRes = PTR( hdRes );
ptL   = PTR( hdL );
ptR   = PTR( hdR ) + SIZE( hdR ) / SIZE_HD - lnR;
while ( 0 < lnL )  { *ptRes++ = *ptL++;  --lnL; }
while ( 0 < lnR )  { *ptRes++ = *ptR++;  --lnR; }
return hdRes;
}
hdLstL = PTR( hdL )[ 0 ];
hdLstR = PTR( hdR )[ 0 ];
if ( TYPE( hdLstL ) == T_AGGRP )
hdLstL = HD_WORDS( hdLstL );
if ( TYPE( hdLstR ) == T_AGGRP )
hdLstR = HD_WORDS( hdLstR );
if ( hdLstL != hdLstR )
return ProdWord( WordSword( hdL ), WordSword( hdR ) );
lnL  = ( SIZE( hdL ) - SIZE_HD - SIZE_SWORD ) / (2 * SIZE_SWORD);
lnRR = lnR  = ( SIZE( hdR ) - SIZE_HD - SIZE_SWORD ) / (2 * SIZE_SWORD);
gtL = (TypSword*)( PTR( hdL ) + 1 ) + 2 * ( lnL - 1 );
gtR = (TypSword*)( PTR( hdR ) + 1 );
while ( 0 < lnL && 0 < lnR && gtL[0]==gtR[0] && gtL[1] == -gtR[1] )
{
--lnL;  gtL -= 2;
--lnR;  gtR += 2;
}
if ( lnL + lnR == 0 )
return HdIdWord;
if ( 0 < lnL && 0 < lnR && gtL[ 0 ] == gtR[ 0 ] )
hdRes = NewBag( T_SWORD, SIZE_HD + (2*(lnL+lnR) - 1) * SIZE_SWORD );
else
hdRes = NewBag( T_SWORD, SIZE_HD + (2*(lnL+lnR) + 1) * SIZE_SWORD );
gtRes = (TypSword*)( PTR( hdRes ) + 1 );
gtL   = (TypSword*)( PTR( hdL ) + 1 );
gtR   = (TypSword*)( PTR( hdR ) + 1 ) + 2 * ( lnRR - lnR );
while ( 1 < lnL )
{
*gtRes++ = *gtL++;
*gtRes++ = *gtL++;
--lnL;
}
if ( 0 < lnL )
{
if ( 0 < lnR && gtL[0] == gtR[0] )
{
--lnR;
++gtR;
*gtRes++ = *gtL++;
e = *gtL++ + *gtR++;
if ( ((e << 16) >> 16) != e )
return Error( "Words: integer overflow", 0L, 0L );
*gtRes++ = e;
}
else
{
*gtRes++ = *gtL++;
*gtRes++ = *gtL++;
}
}
while ( 0 < lnR )
{
*gtRes++ = *gtR++;
*gtRes++ = *gtR++;
--lnR;
}
PTR( hdRes )[ 0 ] = hdLstL;
*gtRes = -1;
return hdRes;
}
TypHandle       QuoWord ( hdL, hdR )
TypHandle       hdL,  hdR;
{
SPEC_INT32_T             lnL,  lnR,  e;
TypHandle       * ptL,  * ptR,  * ptRes;
TypHandle       hdRes, hdLstL, hdLstR;
TypSword        * gtL,  * gtR,  * gtRes;
if ( TYPE( hdL ) == T_WORD && SIZE( hdL ) == 0 )
return PowWI( hdR, INT_TO_HD( -1 ) );
if ( TYPE( hdL ) == T_SWORD && SIZE( hdL ) == SIZE_HD + SIZE_SWORD )
return PowWI( hdR, INT_TO_HD( -1 ) );
if ( TYPE( hdR ) == T_WORD && SIZE( hdR ) == 0 )
return hdL;
if ( TYPE( hdR ) == T_SWORD && SIZE( hdR ) == SIZE_HD + SIZE_SWORD )
return hdL;
if ( TYPE( hdL ) == T_WORD || TYPE( hdR ) == T_WORD )
{
if ( TYPE( hdL ) == T_SWORD )
hdL = WordSword( hdL );
if ( TYPE( hdR ) == T_SWORD )
hdR = WordSword( hdR );
lnL = SIZE( hdL ) / SIZE_HD;  ptL = PTR( hdL ) + lnL - 1;
lnR = SIZE( hdR ) / SIZE_HD;  ptR = PTR( hdR ) + lnR - 1;
while ( 0 < lnL && 0 < lnR && *ptL == *ptR )
{
--lnL;  --ptL;
--lnR;  --ptR;
}
if ( lnL + lnR == 0 )
return HdIdWord;
hdRes = NewBag( T_WORD, ( lnL + lnR ) * SIZE_HD );
ptRes = PTR( hdRes );
ptL   = PTR( hdL );
ptR   = PTR( hdR ) + lnR - 1;
while ( 0 < lnL )  { *ptRes++ = *ptL++;          --lnL; }
while ( 0 < lnR )  { *ptRes++ = *PTR( *ptR-- );  --lnR; }
return hdRes;
}
hdLstL = PTR( hdL )[ 0 ];
hdLstR = PTR( hdR )[ 0 ];
if ( TYPE( hdLstL ) == T_AGGRP )
hdLstL = HD_WORDS( hdLstL );
if ( TYPE( hdLstR ) == T_AGGRP )
hdLstR = HD_WORDS( hdLstR );
if ( hdLstL != hdLstR )
return QuoWord( WordSword( hdL ), WordSword( hdR ) );
lnL  = ( SIZE( hdL ) - SIZE_HD - SIZE_SWORD ) / ( 2 * SIZE_SWORD );
lnR  = ( SIZE( hdR ) - SIZE_HD - SIZE_SWORD ) / ( 2 * SIZE_SWORD );
gtL = (TypSword*)( PTR( hdL ) + 1 ) + 2 * ( lnL - 1 );
gtR = (TypSword*)( PTR( hdR ) + 1 ) + 2 * ( lnR - 1 );
while ( 0 < lnL && 0 < lnR && gtL[0]==gtR[0] && gtL[1] == gtR[1] )
{
--lnL;  gtL -= 2;
--lnR;  gtR -= 2;
}
if ( lnL + lnR == 0 )
return HdIdWord;
if ( 0 < lnL && 0 < lnR && gtL[ 0 ] == gtR[ 0 ] )
hdRes = NewBag( T_SWORD, SIZE_HD + (2*(lnL+lnR) - 1) * SIZE_SWORD );
else
hdRes = NewBag( T_SWORD, SIZE_HD + (2*(lnL+lnR) + 1) * SIZE_SWORD );
gtRes = (TypSword*)( PTR( hdRes ) + 1 );
gtL   = (TypSword*)( PTR( hdL ) + 1 );
gtR   = (TypSword*)( PTR( hdR ) + 1 ) + 2 * ( lnR - 1 );
while ( 1 < lnL )
{
*gtRes++ = *gtL++;
*gtRes++ = *gtL++;
--lnL;
}
if ( 0 < lnL )
{
if ( 0 < lnR && gtL[0] == gtR[0] )
{
*gtRes++ = *gtL++;
e = *gtL++ - gtR[1];
if ( ((e << 16) >> 16) != e )
return Error( "Words: integer overflow", 0L, 0L );
*gtRes++ = e;
--lnR;
gtR -= 2;
}
else
{
*gtRes++ = *gtL++;
*gtRes++ = *gtL++;
}
}
while ( 0 < lnR )
{
*gtRes++ = gtR[0];
*gtRes++ = -gtR[1];
--lnR;
gtR -= 2;
}
PTR( hdRes )[ 0 ] = hdLstL;
*gtRes = -1;
return hdRes;
}
TypHandle       ModWord ( hdL, hdR )
TypHandle       hdL,  hdR;
{
SPEC_INT32_T             lnL,  lnR,  lnLL,  lnRR,  e;
TypHandle       * ptL,  * ptR,  * ptRes;
TypHandle       hdRes, hdLstL, hdLstR;
TypSword        * gtL,  * gtR,  * gtRes;
if ( TYPE( hdL ) == T_WORD && SIZE( hdL ) == 0 )
return hdR;
if ( TYPE( hdL ) == T_SWORD && SIZE( hdL ) == SIZE_HD + SIZE_SWORD )
return hdR;
if ( TYPE( hdR ) == T_WORD && SIZE( hdR ) == 0 )
return PowWI( hdL, INT_TO_HD( -1 ) );
if ( TYPE( hdR ) == T_SWORD && SIZE( hdR ) == SIZE_HD + SIZE_SWORD )
return PowWI( hdL, INT_TO_HD( -1 ) );
if ( TYPE( hdL ) == T_WORD || TYPE( hdR ) == T_WORD )
{
if ( TYPE( hdL ) == T_SWORD )
hdL = WordSword( hdL );
if ( TYPE( hdR ) == T_SWORD )
hdR = WordSword( hdR );
lnL = SIZE( hdL ) / SIZE_HD;  ptL = PTR( hdL );
lnR = SIZE( hdR ) / SIZE_HD;  ptR = PTR( hdR );
while ( 0 < lnL && 0 < lnR && *ptL == *ptR )
{
--lnL;  ++ptL;
--lnR;  ++ptR;
}
if ( lnL + lnR == 0 )
return HdIdWord;
hdRes = NewBag( T_WORD, ( lnL + lnR ) * SIZE_HD );
ptRes = PTR( hdRes );
ptL   = PTR( hdL ) + SIZE( hdL ) / SIZE_HD - 1;
ptR   = PTR( hdR ) + SIZE( hdR ) / SIZE_HD - lnR;
while ( 0 < lnL )  { *ptRes++ = *PTR( *ptL-- );  --lnL; }
while ( 0 < lnR )  { *ptRes++ = *ptR++;          --lnR; }
return hdRes;
}
hdLstL = PTR( hdL )[ 0 ];
hdLstR = PTR( hdR )[ 0 ];
if ( TYPE( hdLstL ) == T_AGGRP )
hdLstL = HD_WORDS( hdLstL );
if ( TYPE( hdLstR ) == T_AGGRP )
hdLstR = HD_WORDS( hdLstR );
if ( hdLstL != hdLstR )
return ModWord( WordSword( hdL ), WordSword( hdR ) );
lnLL = lnL  = ( SIZE( hdL ) - SIZE_HD - SIZE_SWORD ) / (2 * SIZE_SWORD);
lnRR = lnR  = ( SIZE( hdR ) - SIZE_HD - SIZE_SWORD ) / (2 * SIZE_SWORD);
gtL = (TypSword*)( PTR( hdL ) + 1 );
gtR = (TypSword*)( PTR( hdR ) + 1 );
while ( 0 < lnL && 0 < lnR && gtL[0]==gtR[0] && gtL[1] == gtR[1] )
{
--lnL;  gtL += 2;
--lnR;  gtR += 2;
}
if ( lnL + lnR == 0 )
return HdIdWord;
if ( 0 < lnL && 0 < lnR && gtL[ 0 ] == gtR[ 0 ] )
hdRes = NewBag( T_SWORD, SIZE_HD + (2*(lnL+lnR) - 1) * SIZE_SWORD );
else
hdRes = NewBag( T_SWORD, SIZE_HD + (2*(lnL+lnR) + 1) * SIZE_SWORD );
gtRes = (TypSword*)( PTR( hdRes ) + 1 );
gtL   = (TypSword*)( PTR( hdL ) + 1 ) + 2 * ( lnLL - 1 );
gtR   = (TypSword*)( PTR( hdR ) + 1 ) + 2 * ( lnRR - lnR );
while ( 1 < lnL )
{
*gtRes++ = gtL[0];
*gtRes++ = -gtL[1];
gtL -= 2;
--lnL;
}
if ( 0 < lnL )
{
if ( 0 < lnR && gtL[0] == gtR[0] )
{
--lnR;
++gtR;
*gtRes++ = gtL[0];
e = -gtL[1] + *gtR++;
if ( ((e << 16) >> 16) != e )
return Error( "Words: integer overflow", 0L, 0L );
*gtRes++ = e;
}
else
{
*gtRes++ = gtL[0];
*gtRes++ = -gtL[1];
}
}
while ( 0 < lnR )
{
*gtRes++ = *gtR++;
*gtRes++ = *gtR++;
--lnR;
}
PTR( hdRes )[ 0 ] = hdLstL;
*gtRes = -1;
return hdRes;
}
TypHandle       PowWI ( hdL, hdR )
TypHandle       hdL,  hdR;
{
TypHandle       hdRes,  hdLst;
TypHandle       * ptL,  * ptRes;
TypSword        * gtL,  * gtR;
long            exp;
exp = HD_TO_INT( hdR );
if ( exp == 0 )
return HdIdWord;
if ( TYPE( hdL ) == T_WORD && SIZE( hdL ) == 0 )
return HdIdWord;
if ( TYPE( hdL ) == T_SWORD && SIZE( hdL ) == SIZE_HD + SIZE_SWORD )
return HdIdWord;
if ( exp < 0 )
{
if ( TYPE( hdL ) == T_WORD )
{
hdRes = NewBag( T_WORD, SIZE( hdL ) );
ptRes = PTR( hdRes );
ptL   = PTR( hdL ) + SIZE( hdL ) / SIZE_HD - 1;
while ( ptL >= PTR(hdL) )  *ptRes++ = *PTR( *ptL-- );
}
else
{
hdRes = NewBag( T_SWORD, SIZE( hdL ) );
hdLst = PTR( hdL )[0];
if ( TYPE( hdLst ) == T_AGGRP )
hdLst = HD_WORDS( PTR( hdL )[0] );
PTR( hdRes )[0] = hdLst;
gtL  = (TypSword*)( PTR( hdL ) + 1 );
gtR  = (TypSword*)( (char*) PTR( hdRes ) + SIZE(hdRes) ) - 1;
*gtR = -1;
gtR -= 2;
while ( *gtL != -1 )
{
gtR[0] = *gtL++;
gtR[1] = -*gtL++;
gtR   -= 2;
}
}
hdL = hdRes;
exp = - exp;
}
if ( exp == 1 )
{
hdRes = hdL;
}
else
{
hdRes = HdIdWord;
while ( exp > 0 )
{
if ( exp % 2 == 1 )
{
hdRes = ProdWord( hdRes, hdL );
exp   = exp - 1;
}
else
{
hdL = ProdWord( hdL, hdL );
exp = exp / 2;
}
}
}
return hdRes;
}
TypHandle       PowWW ( hdL, hdR )
TypHandle       hdL,  hdR;
{
if ( TYPE( hdL ) == T_WORD && TYPE( hdR ) == T_SWORD )
hdR = WordSword( hdR );
if ( TYPE( hdL ) == T_SWORD && TYPE( hdR ) == T_WORD )
hdL = WordSword( hdL );
return ProdWord( PowWI( hdR, INT_TO_HD( -1 ) ), ProdWord( hdL, hdR ) );
}
TypHandle       CommWord ( hdL, hdR )
TypHandle       hdL,  hdR;
{
if ( TYPE( hdL ) == T_WORD && TYPE( hdR ) == T_SWORD )
hdR = WordSword( hdR );
if ( TYPE( hdL ) == T_SWORD && TYPE( hdR ) == T_WORD )
hdL = WordSword( hdL );
return ProdWord( PowWI( hdL, INT_TO_HD( -1 ) ),
ProdWord( PowWI( hdR, INT_TO_HD( -1 ) ),
ProdWord( hdL, hdR ) ) );
}
TypHandle       EqWord ( hdL, hdR )
TypHandle       hdL,  hdR;
{
TypHandle       * ptL,  * ptR,  * ptEnd,  hdLstL,  hdLstR, hdTmp;
TypSword        * gtL,  * gtR;
long            i, j;
if ( TYPE( hdL ) == T_WORD && TYPE( hdR ) == T_WORD )
{
if ( SIZE( hdL ) != SIZE( hdR ) )
return HdFalse;
ptL = PTR( hdL );
ptR = PTR( hdR );
for ( i = SIZE( hdL ) / SIZE_HD; i > 0; --i, ++ptL, ++ptR )
if ( *ptL != *ptR )
return HdFalse;
return HdTrue;
}
else if ( TYPE( hdL ) == T_SWORD && TYPE( hdR ) == T_SWORD )
{
if ( SIZE( hdL ) != SIZE( hdR ) )
return HdFalse;
hdLstL = PTR( hdL )[ 0 ];
hdLstR = PTR( hdR )[ 0 ];
if ( TYPE( hdLstL ) == T_AGGRP )
hdLstL = HD_WORDS( hdLstL );
if ( TYPE( hdLstR ) == T_AGGRP )
hdLstR = HD_WORDS( hdLstR );
if ( hdLstL == hdLstR )
{
gtL = (TypSword*)( PTR( hdL ) + 1 );
gtR = (TypSword*)( PTR( hdR ) + 1 );
while ( *gtL != -1 && gtL[0] == gtR[0] && gtL[1] == gtR[1] )
{
gtL += 2;
gtR += 2;
}
return ( *gtL == -1 && *gtR == -1 ) ? HdTrue : HdFalse;
}
else
{
ptL  = PTR( hdLstL ) + 1;
ptR  = PTR( hdLstR ) + 1;
gtL = (TypSword*)( PTR( hdL ) + 1 );
gtR = (TypSword*)( PTR( hdR ) + 1 );
while ( *gtL != -1
&& *gtR != -1
&& ( ( ptL[ gtL[0] ] == ptR[ gtR[0] ]
&& gtL[1] == gtR[1] )
|| ( ptL[ gtL[0] ] == *PTR( ptR[ gtR[0] ] )
&& gtL[1] != -gtR[1]) ) )
{
gtL += 2;
gtR += 2;
}
return ( *gtL == -1 && *gtR == -1 ) ? HdTrue : HdFalse;
}
}
else
{
if ( TYPE( hdL ) == T_WORD )
{
hdTmp = hdL;
hdL   = hdR;
hdR   = hdTmp;
}
hdLstL = PTR( hdL )[ 0 ];
if ( TYPE( hdLstL ) == T_AGGRP )
hdLstL = HD_WORDS( hdLstL );
ptL   = PTR( hdLstL ) + 1;
gtL  = (TypSword*)( PTR( hdL ) + 1 );
ptR   = PTR( hdR );
ptEnd = (TypHandle*)( (char*) ptR + SIZE( hdR ) );
while ( *gtL != -1 && ptR < ptEnd )
{
if ( *ptR == ptL[ gtL[0] ] )
{
if ( gtL[1] < 0 )
return HdFalse;
hdTmp = ptL[ gtL[0] ];
for ( j = gtL[1]; j > 0; j--, ptR++ )
if ( ptR == ptEnd || *ptR != hdTmp )
return HdFalse;
gtL += 2;
}
else if ( *ptR == *PTR( ptL[ gtL[0] ] ) )
{
if ( gtL[1] > 0 )
return HdFalse;
hdTmp = *PTR( ptL[ gtL[0] ] );
for ( j = -gtL[1]; j > 0; j--, ptR++ )
if ( ptR == ptEnd || *ptR != hdTmp )
return HdFalse;
gtL += 2;
}
else
return HdFalse;
}
return ( *gtL == -1 && ptR == ptEnd ) ? HdTrue : HdFalse;
}
}
TypHandle       LtAgen ( hdL, hdR )
TypHandle       hdL,  hdR;
{
long            c;
if ( hdL == hdR )
return HdFalse;
else
{
if ( *PTR( hdL ) == hdR )
{
if ( *( (char*) ( PTR( hdL ) + 1 ) ) == '-' )
return HdFalse;
else
return HdTrue;
}
c = SyStrcmp( (char*)(PTR(hdL)+1)+1, (char*)(PTR(hdR)+1)+1 );
if ( c < 0 )
return HdTrue;
else if ( c > 0 )
return HdFalse;
else
{
if ( *( (char*) ( PTR( hdL ) + 1 ) ) == '-' )
hdL = *PTR( hdL );
if ( *( (char*) ( PTR( hdR ) + 1 ) ) == '-' )
hdR = *PTR( hdR );
return ( hdL < hdR ) ? HdTrue : HdFalse;
}
}
}
TypHandle       LtWord ( hdL, hdR )
TypHandle       hdL,  hdR;
{
TypHandle       * ptL,  * ptR,  hdLstL,  hdLstR, hdTmp;
TypSword          * gtL,  * gtR;
long            i,  j,  lnL,  lnR;
if ( TYPE( hdL ) == T_WORD && TYPE( hdR ) == T_WORD )
{
if ( SIZE( hdL ) < SIZE( hdR ) )  return HdTrue;
if ( SIZE( hdL ) > SIZE( hdR ) )  return HdFalse;
ptL = PTR( hdL );
ptR = PTR( hdR );
for ( i = SIZE( hdL ) / SIZE_HD; i > 0; --i, ++ptL, ++ptR )
if ( *ptL != *ptR )
return LtAgen( *ptL, *ptR );
return HdFalse;
}
else if ( TYPE( hdL ) == T_SWORD && TYPE( hdR ) == T_SWORD )
{
gtL = (TypSword*)( PTR( hdL ) + 1 );
lnL  = 0;
while ( *gtL != -1 )
{
lnL  += ( gtL[1] < 0 ) ? -gtL[1] : gtL[1];
gtL += 2;
}
gtR = (TypSword*)( PTR( hdR ) + 1 );
lnR  = 0;
while ( *gtR != -1 )
{
lnR  += ( gtR[1] < 0 ) ? -gtR[1] : gtR[1];
gtR += 2;
}
if ( lnL != lnR )
return ( lnL < lnR ) ? HdTrue : HdFalse;
hdLstL = PTR( hdL )[ 0 ];
hdLstR = PTR( hdR )[ 0 ];
if ( TYPE( hdLstL ) == T_AGGRP )
hdLstL = HD_WORDS( hdLstL );
if ( TYPE( hdLstR ) == T_AGGRP )
hdLstR = HD_WORDS( hdLstR );
ptL  = PTR( hdLstL ) + 1;
ptR  = PTR( hdLstR ) + 1;
gtL = (TypSword*)( PTR( hdL ) + 1 );
gtR = (TypSword*)( PTR( hdR ) + 1 );
if ( hdLstL == hdLstR )
{
while ( *gtL != -1 && gtL[0] == gtR[0] && gtL[1] == gtR[1] )
{
gtL += 2;
gtR += 2;
}
}
else
{
while ( *gtL != -1
&& ( ( ptL[ gtL[0] ] == ptR[ gtR[0] ]
&& gtL[1] == gtR[1] )
|| ( ptL[ gtL[0] ] == *PTR( ptR[ gtR[0] ] )
&& gtL[1] != -gtR[1]) ) )
{
gtL += 2;
gtR += 2;
}
}
if ( *gtL == -1 )
return HdFalse;
hdL = ( gtL[1] < 0 ) ? *PTR( ptL[ gtL[0] ] ) : ptL[ gtL[0] ];
hdR = ( gtR[1] < 0 ) ? *PTR( ptR[ gtR[0] ] ) : ptR[ gtR[0] ];
if ( hdL != hdR )
return LtAgen( hdL, hdR );
lnL = ( gtL[1] < 0 ) ? -gtL[1] : gtL[1];
lnR = ( gtR[1] < 0 ) ? -gtR[1] : gtR[1];
if ( lnL < lnR )
{
gtL += 2;
hdL  = ( gtL[1] < 0 ) ? *PTR( ptL[ gtL[0] ] ) : ptL[ gtL[0] ];
}
else
{
gtR += 2;
hdR  = ( gtR[1] < 0 ) ? *PTR( ptR[ gtR[0] ] ) : ptR[ gtR[0] ];
}
return LtAgen( hdL, hdR );
}
else if ( TYPE( hdL ) == T_SWORD && TYPE( hdR ) == T_WORD )
{
gtL = (TypSword*)( PTR( hdL ) + 1 );
lnL  = 0;
while ( *gtL != -1 )
{
lnL  += ( gtL[1] < 0 ) ? -gtL[1] : gtL[1];
gtL += 2;
}
lnR = SIZE( hdR ) / SIZE_HD;
if ( lnL != lnR )
return ( lnL < lnR ) ? HdTrue : HdFalse;
hdLstL = PTR( hdL )[ 0 ];
if ( TYPE( hdLstL ) == T_AGGRP )
hdLstL = HD_WORDS( hdLstL );
ptL   = PTR( hdLstL ) + 1;
gtL  = (TypSword*)( PTR( hdL ) + 1 );
ptR   = PTR( hdR );
while ( *gtL != -1 )
{
if ( *ptR == ptL[ gtL[0] ] )
{
if ( gtL[1] < 0 )
return LtAgen( *PTR( ptL[ gtL[0] ] ), *ptR );
hdTmp = ptL[ gtL[0] ];
for ( j = gtL[1]; j > 0; j--, ptR++ )
if ( *ptR != hdTmp )
return LtAgen( hdTmp, *ptR );
gtL += 2;
}
else if ( *ptR == *PTR( ptL[ gtL[0] ] ) )
{
if ( gtL[1] > 0 )
return LtAgen( ptL[ gtL[0] ], *ptR );
hdTmp = *PTR( ptL[ gtL[0] ] );
for ( j = -gtL[1]; j > 0; j--, ptR++ )
if ( *ptR != hdTmp )
return LtAgen( hdTmp, *ptR );
gtL += 2;
}
else if ( gtL[1] > 0 )
return LtAgen( ptL[ gtL[0] ], *ptR );
else if ( gtL[1] < 0 )
return LtAgen( *PTR( ptL[ gtL[0] ] ), *ptR );
}
return HdFalse;
}
else
{
if ( EqWord( hdL, hdR ) == HdTrue )
return HdFalse;
else
return ( LtWord( hdR, hdL ) == HdTrue ) ? HdFalse : HdTrue;
}
}
void        PrSword ( hdWrd )
TypHandle       hdWrd;
{
TypHandle       * ptLst;
TypSword        * ptWrd;
ptWrd = (TypSword*)( PTR( hdWrd ) + 1 );
if ( ptWrd[ 0 ] == -1 )
{
Pr( "IdWord", 0L, 0L );
}
else
{
if ( TYPE( *PTR( hdWrd ) ) == T_AGGRP )
ptLst = PTR( HD_WORDS( *PTR( hdWrd ) ) ) + 1;
else
ptLst = PTR( *PTR( hdWrd ) ) + 1;
if ( ptWrd[ 1 ] == 1 )
Pr( "%s", (long)((char*)(PTR(ptLst[ptWrd[0]])+1)+1), 0L );
else
Pr( "%s^%d",(long)((char*)(PTR(ptLst[ptWrd[0]])+1)+1),ptWrd[1] );
ptWrd += 2;
while ( ptWrd[ 0 ] != -1 )
{
if ( ptWrd[ 1 ] != 1 )
Pr( "*%s^%d",
(long)((char*)(PTR(ptLst[ ptWrd[0] ])+1)+1),
ptWrd[ 1 ] );
else
Pr( "*%s", (long)((char*)(PTR(ptLst[ ptWrd[0] ])+1)+1), 0L );
ptWrd += 2;
}
}
}
void            PrWord ( hdWrd )
TypHandle       hdWrd;
{
long            nr, i, exp;
nr = SIZE( hdWrd ) / SIZE_HD;
if ( nr == 0 )
{
Pr( "IdWord", 0L, 0L );
}
else
{
i = 0;
while ( i < nr )
{
if ( PTR( hdWrd )[ i ] == 0 )
Pr( "~", 0L, 0L );
else
{
exp = 1;
while ( i < nr-1 && PTR( hdWrd )[i] == PTR( hdWrd )[i+1] )
{
i++;
exp++;
}
if ( *( (char*) ( PTR( PTR( hdWrd )[ i ] ) + 1 ) ) == '-' )
exp *= -1;
if ( exp == 1 )
Pr( "%s",
(long) ( (char*)( PTR( PTR( hdWrd )[i] ) + 1 ) + 1 ),
0L );
else
Pr( "%s^%d",
(long) ( (char*)( PTR( PTR( hdWrd )[i] ) + 1 ) + 1 ),
(long) exp );
}
if ( i != nr - 1 )
Pr( "*", 0L, 0L );
i++;
}
}
}
TypHandle       FunAbstractGenerator ( hdCall )
TypHandle       hdCall;
{
TypHandle       hdStr,  hdWrd,  hdAgn,  hdInv;
if ( SIZE( hdCall ) != 2 * SIZE_HD )
return Error( "usage: AbstractGenerator( <str> )", 0L, 0L );
hdStr = EVAL( PTR( hdCall )[ 1 ] );
if ( TYPE( hdStr ) != T_STRING && ! IsString( hdStr ) )
return Error( "usage: AbstractGenerator( <str> )", 0L, 0L );
hdAgn = NewBag( T_AGEN, SIZE_HD + SIZE( hdStr ) + 1 );
*(char*)( PTR( hdAgn ) + 1 ) = '\0';
SyStrncat( (char*) ( PTR( hdAgn ) + 1 ), "+", 1 );
SyStrncat( (char*) ( PTR( hdAgn ) + 1 ),
(char*) PTR( hdStr ),
SIZE( hdStr ) - 1 );
hdInv = NewBag( T_AGEN, SIZE_HD + SIZE( hdStr ) + 1 );
*(char*)( PTR( hdInv ) + 1 ) = '\0';
SyStrncat( (char*) ( PTR( hdInv ) + 1 ), "-", 1 );
SyStrncat( (char*) ( PTR( hdInv ) + 1 ),
(char*) PTR( hdStr ),
SIZE( hdStr ) - 1 );
PTR( hdAgn )[ 0 ] = hdInv;
PTR( hdInv )[ 0 ] = hdAgn;
hdWrd             = NewBag( T_WORD, SIZE_HD );
PTR( hdWrd )[ 0 ] = hdAgn;
return hdWrd;
}
TypHandle       Words ( hdStr, n )
TypHandle       hdStr;
long            n;
{
TypHandle       hdLst,  hdAgn,  hdInv,  hdTmp,  hdWrds;
TypHandle       * ptTmp;
long            i,  j;
char            str[ 6 ],  * p;
hdLst = NewBag( T_LIST, ( n + 1 ) * SIZE_HD );
PTR( hdLst )[ 0 ] = INT_TO_HD( n );
str[ 5 ] = '\0';
for ( i = 1; i <= n; i++ )
{
p = str + 5;
j = i;
while ( j > 0 )
{
if ( p < str )
return Error( "Words: integer-string overflow", 0L, 0L );
*--p = j % 10 + '0';
j   /= 10;
}
j = SyStrlen( p );
hdAgn = NewBag( T_AGEN, SIZE_HD + SIZE( hdStr ) + j + 1 );
*(char*)( PTR( hdAgn ) + 1 ) = '\0';
SyStrncat( (char*) ( PTR( hdAgn ) + 1 ), "+", 1 );
SyStrncat( (char*) ( PTR( hdAgn ) + 1 ),
(char*) PTR( hdStr ),
SIZE( hdStr ) - 1 );
SyStrncat( (char*) ( PTR( hdAgn ) + 1 ), p, j );
hdInv = NewBag( T_AGEN, SIZE_HD + SIZE( hdStr ) + j + 1 );
*(char*)( PTR( hdInv ) + 1 ) = '\0';
SyStrncat( (char*) ( PTR( hdInv ) + 1 ), "-", 1 );
SyStrncat( (char*) ( PTR( hdInv ) + 1 ),
(char*) PTR( hdStr ),
SIZE( hdStr ) - 1 );
SyStrncat( (char*) ( PTR( hdInv ) + 1 ), p, j );
PTR( hdAgn )[ 0 ] = hdInv;
PTR( hdInv )[ 0 ] = hdAgn;
PTR( hdLst )[ i ] = hdAgn;
}
hdWrds = NewBag( T_LIST, ( n + 1 ) * SIZE_HD );
PTR( hdWrds )[ 0 ] = INT_TO_HD( n );
for ( i = 1; i <= n; i++ )
{
hdTmp = NewBag( T_SWORD, SIZE_HD + 3 * SIZE_SWORD );
ptTmp = PTR( hdTmp ) + 1;
ptTmp[ -1 ] = hdLst;
( (TypSword*) ptTmp )[ 0 ] = i - 1;
( (TypSword*) ptTmp )[ 1 ] = 1;
( (TypSword*) ptTmp )[ 2 ] = -1;
PTR( hdWrds )[ i ] = hdTmp;
}
return hdWrds;
}
TypHandle       FunAbstractGenerators ( hdCall )
TypHandle       hdCall;
{
TypHandle       hdStr, hdN;
long            n;
if ( SIZE( hdCall ) != 3 * SIZE_HD )
return Error( "usage: AbstractGenerators( <str>, <n> )", 0L, 0L );
hdStr = EVAL( PTR( hdCall )[ 1 ] );
hdN   = EVAL( PTR( hdCall )[ 2 ] );
if ( (TYPE( hdStr ) != T_STRING && ! IsString( hdStr ))
|| TYPE( hdN ) != T_INT )
return Error( "usage: AbstractGenerators( <str>, <n> )", 0L, 0L );
n = HD_TO_INT( hdN );
if ( n <= 0 )
return Error( "number of words <n> must be positive", 0L, 0L );
if ( n > MAX_SWORD_NR )
return Error( "number of words <n> must be less than %d",
MAX_SWORD_NR - 1, 0L );
return Words( hdStr, n );
}
TypHandle       FunLenWord ( hdCall )
TypHandle       hdCall;
{
TypHandle       hdWord;
TypSword        * ptSwrd;
long            len;
if ( SIZE( hdCall ) != 2 * SIZE_HD )
return Error( "usage: LengthWord( <word> )", 0L, 0L );
hdWord = EVAL( PTR( hdCall )[ 1 ] );
if ( TYPE( hdWord ) == T_WORD )
return INT_TO_HD( SIZE( hdWord ) / SIZE_HD );
else if ( TYPE( hdWord ) == T_SWORD )
{
len = 0;
ptSwrd = (TypSword*)( PTR( hdWord ) + 1 );
while ( ptSwrd[0] != -1 )
{
len    += ( ptSwrd[1] < 0 ) ? -ptSwrd[1] : ptSwrd[1];
ptSwrd += 2;
}
return INT_TO_HD( len );
}
else
return Error( "usage: LengthWord( <word> )", 0L, 0L );
}
TypHandle   FunSubword ( hdCall )
TypHandle       hdCall;
{
TypHandle       hdWord, hdFrom, hdTo, hdRes;
long            i, toVal, fromVal;
if ( SIZE( hdCall ) != 4 * SIZE_HD )
return Error( "usage: Subword( <word>, <from>, <to> )", 0L, 0L );
hdWord  = EVAL( PTR( hdCall )[ 1 ] );
hdFrom  = EVAL( PTR( hdCall )[ 2 ] );
hdTo    = EVAL( PTR( hdCall )[ 3 ] );
if ( TYPE( hdWord ) == T_SWORD )
hdWord = WordSword( hdWord );
if ( TYPE( hdWord )    != T_WORD
|| TYPE( hdFrom ) != T_INT
|| TYPE( hdTo )   != T_INT )
{
return Error( "usage: Subword( <word>, <from>, <to> )", 0L, 0L );
}
fromVal = HD_TO_INT( hdFrom );
if ( fromVal <= 0 || SIZE( hdWord ) / SIZE_HD < fromVal )
return Error( "Subword: illegal <from> value", 0L, 0L );
toVal = HD_TO_INT( hdTo );
if ( toVal < fromVal || SIZE( hdWord )/SIZE_HD < toVal )
return Error( "Subword: illegal <to> value", 0L, 0L );
hdRes = NewBag( T_WORD, ( toVal - fromVal + 1 ) * SIZE_HD );
for ( i = fromVal; i <= toVal; ++i )
PTR( hdRes )[ i - fromVal ] = PTR( hdWord )[ i - 1 ];
return hdRes;
}
TypHandle       FunSubs( hdCall )
TypHandle      hdCall;
{
register TypHandle      hdWord,  hdFrom,  hdTo,  hdBy;
TypHandle      hdRes;
register TypHandle      * ptWord,  * ptRes;
long           szRes,  i;
long           fromVal, toVal;
if ( SIZE(hdCall) != 5 * SIZE_HD )
return Error(
"usage: SubstitutedWord( <word>, <from>, <to>, <by> )", 0L,0L );
hdWord = EVAL( PTR( hdCall )[ 1 ] );
hdFrom = EVAL( PTR( hdCall )[ 2 ] );
hdTo   = EVAL( PTR( hdCall )[ 3 ] );
hdBy   = EVAL( PTR( hdCall )[ 4 ] );
if ( TYPE( hdWord ) == T_SWORD )
hdWord = WordSword( hdWord );
if ( TYPE( hdBy ) == T_SWORD )
hdBy = WordSword( hdBy );
if ( TYPE( hdWord )    != T_WORD
|| TYPE( hdFrom ) != T_INT
|| TYPE( hdTo )   != T_INT
|| TYPE( hdBy )   != T_WORD )
{
return Error(
"usage: SubstitutedWord( <word>, <from>, <to>, <by> )", 0L,0L );
}
fromVal = HD_TO_INT( hdFrom );
toVal   = HD_TO_INT( hdTo );
if ( fromVal <= 0  || SIZE(hdWord)/SIZE_HD < fromVal )
return Error( "SubstitutedWord: illegal <from> value", 0L, 0L );
if ( toVal < fromVal || SIZE(hdWord)/SIZE_HD < toVal )
return Error( "SubstitutedWord: illegal <to> value", 0L, 0L );
szRes  = SIZE( hdWord ) + SIZE( hdBy ) - SIZE_HD * (toVal - fromVal + 1);
hdRes  = NewBag( T_WORD, szRes );
ptWord = PTR( hdWord );
ptRes  = PTR( hdRes );
for ( i = fromVal; i > 1; --i ) {
*ptRes++ = *ptWord++;
}
ptWord = PTR( hdBy );
ptRes--;
while ( PTR( hdRes ) <= ptRes &&
ptWord < PTR( hdBy ) + ( SIZE( hdBy ) / SIZE_HD ) &&
*PTR( *ptWord ) == *ptRes )
{
ptWord++;
*ptRes-- = 0;
szRes    = szRes - 2 * SIZE_HD;
}
ptRes++;
while ( ptWord < PTR( hdBy ) + ( SIZE( hdBy ) / SIZE_HD ) )
*ptRes++ = *ptWord++;
ptWord   = PTR( hdWord ) + toVal;
ptRes--;
while ( PTR( hdRes ) <= ptRes &&
ptWord < PTR( hdWord ) + ( SIZE( hdWord ) / SIZE_HD ) &&
PTR( *ptWord )[ 0 ] == *ptRes )
{
ptWord++;
*ptRes-- = 0;
szRes    = szRes - 2 * SIZE_HD;
}
ptRes++;
while ( ptWord < PTR( hdWord ) + ( SIZE( hdWord ) / SIZE_HD ) )
*ptRes++ = *ptWord++;
Resize( hdRes, szRes );
return hdRes;
}
TypHandle       FunPosWord ( hdCall )
TypHandle      hdCall;
{
TypHandle      hdWord,  hdSub,  hdFrom;
register TypHandle      * ptWord,  * ptSub;
register long           i,  j, fromVal, endVal;
if ( SIZE( hdCall ) != 4 * SIZE_HD && SIZE( hdCall ) != 3 * SIZE_HD )
return Error("usage: PositionWord( <word>, <sub>[, <from>] )", 0L,0L );
hdWord = EVAL( PTR( hdCall )[ 1 ] );
if ( TYPE( hdWord ) == T_SWORD )
hdWord = WordSword( hdWord );
if ( TYPE( hdWord ) != T_WORD )
return Error("usage: PositionWord( <word>, <sub>[, <from>] )", 0L,0L );
hdSub = EVAL( PTR( hdCall )[ 2 ] );
if ( TYPE( hdSub ) != T_WORD )
return Error("usage: PositionWord( <word>, <sub>[, <from>] )", 0L,0L );
if ( SIZE( hdCall ) == 4 * SIZE_HD ) {
hdFrom = EVAL( PTR(hdCall)[ 3 ] );
if ( TYPE( hdFrom ) != T_INT )
return Error(
"usage: PositionWord( <word>, <sub>[, <from>] )", 0L, 0L );
fromVal = HD_TO_INT( hdFrom );
} else
fromVal = 1;
if ( fromVal < 1 )
return Error( "PositionWord: illegal <from> value", 0L, 0L );
endVal = ( (long) ( SIZE(hdWord)-SIZE(hdSub) ) / (long) SIZE_HD + 1 );
for ( i = fromVal; i <= endVal; ++i ) {
ptWord = PTR( hdWord ) + i - 1;
ptSub  = PTR( hdSub );
for ( j = 0; j < SIZE( hdSub ) / SIZE_HD; ++j ) {
if ( *ptSub++ != *ptWord++ )
break;
}
if ( j == SIZE( hdSub ) / SIZE_HD ) {
return INT_TO_HD( i );
}
}
return HdFalse;
}
TypHandle       FunIsWord ( hdCall )
TypHandle       hdCall;
{
TypHandle       hdObj;
if ( SIZE( hdCall ) != 2 * SIZE_HD )
return Error( "usage: IsWord( <obj> )", 0L, 0L );
hdObj = EVAL( PTR(hdCall)[1] );
if ( hdObj == HdVoid )
return Error( "IsWord: function must return a value", 0L, 0L );
if ( TYPE( hdObj ) == T_WORD || TYPE( hdObj ) == T_SWORD )
return HdTrue;
else
return HdFalse;
}
TypHandle       FunEliminated( hdCall )
TypHandle       hdCall;
{
TypHandle       hdWord,  * ptWord,  hdGen,  hdInv,  hdBy,  * ptBy;
TypHandle       hdRes,  * ptRes;
long            szRes,  i;
if ( SIZE( hdCall ) != 4 * SIZE_HD )
return Error( "usage: EliminatedWord( <word>, <gen>, <by> )",
0L, 0L );
hdWord = EVAL( PTR( hdCall )[ 1 ] );
hdGen  = EVAL( PTR( hdCall )[ 2 ] );
hdBy   = EVAL( PTR( hdCall )[ 3 ] );
if ( TYPE( hdWord ) == T_SWORD )
hdWord = WordSword( hdWord );
if ( TYPE( hdGen ) == T_SWORD )
hdGen = WordSword( hdGen );
if ( TYPE( hdBy ) == T_SWORD )
hdBy = WordSword( hdBy );
if ( TYPE( hdWord )    != T_WORD
|| TYPE( hdGen )  != T_WORD
|| SIZE( hdGen )  != SIZE_HD
|| TYPE( hdBy )   != T_WORD )
{
return Error( "usage: EliminatedWord( <word>, <gen>, <by> )",
0L, 0L );
}
hdGen = PTR( hdGen )[ 0 ];
hdInv = PTR( hdGen )[ 0 ];
ptWord = PTR( hdWord );
szRes  = SIZE( hdWord );
for ( i = 0; i < SIZE( hdWord ) / SIZE_HD; ++i ) {
if ( ptWord[ i ] == hdGen || ptWord[ i ] == hdInv )
szRes = szRes + SIZE(hdBy) - SIZE_HD;
}
hdRes  = NewBag( T_WORD, szRes );
ptRes  = PTR( hdRes );
ptWord = PTR( hdWord );
while ( ptWord < PTR( hdWord ) + SIZE( hdWord ) / SIZE_HD ) {
if ( *ptWord == hdGen ) {
ptBy = PTR( hdBy );
while ( ptBy < PTR( hdBy ) + SIZE( hdBy ) / SIZE_HD ) {
if ( ptRes > PTR( hdRes ) &&
ptRes[-1] == PTR(ptBy[0])[0] )
{
ptRes--;
szRes = szRes - 2 * SIZE_HD;
} else {
*ptRes = *ptBy;
ptRes++;
}
ptBy++;
}
} else if ( *ptWord == hdInv ) {
ptBy = PTR( hdBy ) + SIZE( hdBy ) / SIZE_HD - 1;
while ( ptBy >= PTR( hdBy ) ) {
if ( ptRes > PTR( hdRes ) && ptRes[-1] == *ptBy ) {
ptRes--;
szRes = szRes - 2 * SIZE_HD;
} else {
*ptRes = PTR( ptBy[ 0 ] )[ 0 ];
ptRes++;
}
ptBy--;
}
} else {
if ( ptRes > PTR(hdRes) &&
ptRes[-1] == PTR(ptWord[0])[0] )
{
ptRes--;
szRes = szRes - 2 * SIZE_HD;
} else {
*ptRes = *ptWord;
ptRes++;
}
}
ptWord++;
}
Resize( hdRes, szRes );
return hdRes;
}
TypHandle       FunExpsum ( hdCall )
TypHandle       hdCall;
{
TypHandle       hdWord,  * ptWord,  hdGen,  hdInv;
long            expsum,  i;
if ( SIZE( hdCall ) != 3 * SIZE_HD )
return Error( "usage: ExponentSumWord( <word>, <gen> )", 0L, 0L );
hdWord = EVAL( PTR( hdCall )[ 1 ] );
hdGen  = EVAL( PTR( hdCall )[ 2 ] );
if ( TYPE( hdWord ) == T_SWORD )
hdWord = WordSword( hdWord );
if ( TYPE( hdGen ) == T_SWORD )
hdGen = WordSword( hdGen );
if ( TYPE( hdWord )    != T_WORD
|| TYPE( hdGen )  != T_WORD
|| SIZE( hdGen )  != SIZE_HD )
{
return Error( "usage: ExponentSumWord( <w>, <g> )", 0L, 0L );
}
hdGen  = PTR( hdGen )[ 0 ];
hdInv  = PTR( hdGen )[ 0 ];
expsum = 0;
ptWord = PTR( hdWord );
for ( i = 0; i < SIZE( hdWord ) / SIZE_HD; ++i )
{
if ( ptWord[ i ] == hdGen )  expsum++;
if ( ptWord[ i ] == hdInv )  expsum--;
}
return INT_TO_HD( expsum );
}
TypHandle       FunMappedWord ( hdCall )
TypHandle       hdCall;
{
long            i,  k,  exp;
TypHandle       * ptOld,  hdGenOld = 0,  hdGen,  hdTmp2 = 0;
TypHandle       hdWord,  hdOld,  hdNew,  hdNewWord,  hdTmp;
long            lenOld,  lenNew,  lenWord;
char            * usage = "usage: MappedWord( <word>, <old>, <new> )";
if ( SIZE( hdCall ) != 4 * SIZE_HD )
return Error( usage, 0L, 0L );
hdWord = EVAL( PTR( hdCall )[ 1 ] );
hdOld  = EVAL( PTR( hdCall )[ 2 ] );
hdNew  = EVAL( PTR( hdCall )[ 3 ] );
if ( TYPE( hdWord ) == T_SWORD )
hdWord = WordSword( hdWord );
if ( TYPE(hdWord) != T_WORD || ! IsList(hdOld) || ! IsList(hdNew) )
return Error( usage, 0L, 0L );
lenOld = LEN_LIST( hdOld );
lenNew = LEN_LIST( hdNew );
if ( lenNew != lenOld )
return Error( "needs lists of equal length", 0L, 0L );
if ( lenNew < 1 )
return Error( "needs at least one generator", 0L, 0L );
for ( i = 1; i <= lenNew; i++ )
{
hdTmp = PTR( hdOld )[ i ];
if ( TYPE( hdTmp ) == T_SWORD )
{
hdTmp = WordSword( hdTmp );
PTR( hdOld )[ i ] = hdTmp;
}
if ( TYPE( hdTmp ) != T_WORD || SIZE( hdTmp ) != SIZE_HD )
return Error( "needs words of length 1", 0L, 0L );
}
hdTmp     = PTR( hdNew )[ 1 ];
hdNewWord = POW( hdTmp, INT_TO_HD( 0 ) );
i         = 0;
lenWord   = SIZE( hdWord ) / SIZE_HD;
while ( i < lenWord )
{
ptOld = PTR( hdOld );
hdGen = PTR( hdWord )[ i ];
for ( k = lenNew;  0 < k;  k-- )
{
hdGenOld = PTR( ptOld[ k ] )[ 0 ];
if ( hdGen == hdGenOld || hdGen == *PTR( hdGenOld ) )
break;
}
exp = 1;
while ( i < lenWord - 1 && hdGen == PTR( hdWord )[ i + 1 ] )
{
i++;
exp++;
}
if ( k < 1 )
{
if ( hdTmp2 == 0 || hdTmp2 == hdNewWord )
hdTmp2 = NewBag( T_WORD, SIZE_HD );
PTR( hdTmp2 )[0] = hdGen;
if ( exp == 1 )
hdNewWord = PROD( hdNewWord, hdTmp2 );
else
{
hdTmp = POW( hdTmp2, INT_TO_HD( exp ) );
hdNewWord = PROD( hdNewWord, hdTmp );
}
}
else
{
if ( hdGen != hdGenOld )
exp *= -1;
if ( exp == 1 )
hdNewWord = PROD( hdNewWord, PTR( hdNew )[ k ] );
else
{
hdTmp = POW( PTR( hdNew )[ k ], INT_TO_HD( exp ) );
hdNewWord = PROD( hdNewWord, hdTmp );
}
}
i++;
}
return hdNewWord;
}

void            InitWord ()
{
long            typeL, typeR;
InstEvFunc( T_WORD,  EvWord  );
InstEvFunc( T_SWORD, EvWord  );
InstPrFunc( T_WORD,  PrWord  );
InstPrFunc( T_SWORD, PrSword );
for ( typeL = T_WORD; typeL <= T_SWORD; typeL++ )
{
for ( typeR = T_WORD; typeR <= T_SWORD; typeR++ )
{
TabProd[ typeL ][ typeR ] = ProdWord;
TabQuo [ typeL ][ typeR ] = QuoWord;
TabMod [ typeL ][ typeR ] = ModWord;
TabPow [ typeL ][ typeR ] = PowWW;
TabComm[ typeL ][ typeR ] = CommWord;
TabEq  [ typeL ][ typeR ] = EqWord;
TabLt  [ typeL ][ typeR ] = LtWord;
}
TabPow[ typeL ][ T_INT ] = PowWI;
}
InstIntFunc( "AbstractGenerator",   FunAbstractGenerator  );
InstIntFunc( "AbstractGenerators",  FunAbstractGenerators );
InstIntFunc( "LengthWord",          FunLenWord            );
InstIntFunc( "Subword",             FunSubword            );
InstIntFunc( "SubstitutedWord",     FunSubs               );
InstIntFunc( "PositionWord",        FunPosWord            );
InstIntFunc( "IsWord",              FunIsWord             );
InstIntFunc( "ExponentSumWord",     FunExpsum             );
InstIntFunc( "MappedWord",          FunMappedWord         );
InstIntFunc( "EliminatedWord",      FunEliminated         );
HdIdWord = NewBag( T_WORD, 0 );
InstVar( "IdWord", HdIdWord );
}
void            InitBlist ()
{
TabIsList[T_BLIST]      = 1;
TabLenList[T_BLIST]     = LenBlist;
TabElmList[T_BLIST]     = ElmBlist;
TabElmfList[T_BLIST]    = ElmfBlist;
TabElmlList[T_BLIST]    = ElmfBlist;
TabElmrList[T_BLIST]    = ElmfBlist;
TabElmsList[T_BLIST]    = ElmsBlist;
TabAssList[T_BLIST]     = AssBlist;
TabAsssList[T_BLIST]    = AsssBlist;
TabPosList[T_BLIST]     = PosBlist;
TabPlainList[T_BLIST]   = PlainBlist;
TabIsDenseList[T_BLIST] = IsDenseBlist;
TabIsPossList[T_BLIST]  = IsPossBlist;
EvTab[T_BLIST]          = EvList;
PrTab[T_BLIST]          = PrList;
TabEq[T_BLIST][T_BLIST] = EqBlist;
TabLt[T_BLIST][T_BLIST] = LtList;
InstIntFunc( "IsBlist",        FunIsBlist        );
InstIntFunc( "BlistList",      FunBlistList      );
InstIntFunc( "ListBlist",      FunListBlist      );
InstIntFunc( "SizeBlist",      FunSizeBlist      );
InstIntFunc( "IsSubsetBlist",  FunIsSubsetBlist  );
InstIntFunc( "IntersectBlist", FunIntersectBlist );
InstIntFunc( "UniteBlist",     FunUniteBlist     );
InstIntFunc( "SubtractBlist",  FunSubtractBlist  );
InstIntFunc( "DistanceBlist",  FunDistanceBlist  );
}
void            InitCyc ()
{
long                i;
HdResult = NewBag( T_LIST, 1000*SIZE_HD );
for ( i = 0; i < 1000; i++ )
PTR(HdResult)[i] = INT_TO_HD(0);
CycLastE = NewBag( T_LIST, SIZE_HD );
InstEvFunc( T_CYC, EvCyc );
InstPrFunc( T_CYC, PrCyc );
TabSum[  T_CYC    ][ T_CYC    ] = SumCyc;
TabSum[  T_INT    ][ T_CYC    ] = SumCyc;
TabSum[  T_INTPOS ][ T_CYC    ] = SumCyc;
TabSum[  T_INTNEG ][ T_CYC    ] = SumCyc;
TabSum[  T_RAT    ][ T_CYC    ] = SumCyc;
TabSum[  T_CYC    ][ T_INT    ] = SumCyc;
TabSum[  T_CYC    ][ T_INTPOS ] = SumCyc;
TabSum[  T_CYC    ][ T_INTNEG ] = SumCyc;
TabSum[  T_CYC    ][ T_RAT    ] = SumCyc;
TabDiff[ T_CYC    ][ T_CYC    ] = DiffCyc;
TabDiff[ T_INT    ][ T_CYC    ] = DiffCyc;
TabDiff[ T_INTPOS ][ T_CYC    ] = DiffCyc;
TabDiff[ T_INTNEG ][ T_CYC    ] = DiffCyc;
TabDiff[ T_RAT    ][ T_CYC    ] = DiffCyc;
TabDiff[ T_CYC    ][ T_INT    ] = DiffCyc;
TabDiff[ T_CYC    ][ T_INTPOS ] = DiffCyc;
TabDiff[ T_CYC    ][ T_INTNEG ] = DiffCyc;
TabDiff[ T_CYC    ][ T_RAT    ] = DiffCyc;
TabProd[ T_CYC    ][ T_CYC    ] = ProdCyc;
TabProd[ T_INT    ][ T_CYC    ] = ProdCycI;
TabProd[ T_INTPOS ][ T_CYC    ] = ProdCycI;
TabProd[ T_INTNEG ][ T_CYC    ] = ProdCycI;
TabProd[ T_RAT    ][ T_CYC    ] = ProdCycI;
TabProd[ T_CYC    ][ T_INT    ] = ProdCycI;
TabProd[ T_CYC    ][ T_INTPOS ] = ProdCycI;
TabProd[ T_CYC    ][ T_INTNEG ] = ProdCycI;
TabProd[ T_CYC    ][ T_RAT    ] = ProdCycI;
TabQuo[  T_CYC    ][ T_CYC    ] = QuoCyc;
TabQuo[  T_INT    ][ T_CYC    ] = QuoCyc;
TabQuo[  T_INTPOS ][ T_CYC    ] = QuoCyc;
TabQuo[  T_INTNEG ][ T_CYC    ] = QuoCyc;
TabQuo[  T_RAT    ][ T_CYC    ] = QuoCyc;
TabQuo[  T_CYC    ][ T_INT    ] = QuoCyc;
TabQuo[  T_CYC    ][ T_INTPOS ] = QuoCyc;
TabQuo[  T_CYC    ][ T_INTNEG ] = QuoCyc;
TabQuo[  T_CYC    ][ T_RAT    ] = QuoCyc;
TabPow[  T_CYC    ][ T_INT    ] = PowCyc;
TabEq[   T_CYC    ][ T_CYC    ] = EqCyc;
TabLt[   T_CYC    ][ T_CYC    ] = LtCyc;
TabLt[   T_INT    ][ T_CYC    ] = IsTrue;
TabLt[   T_INTPOS ][ T_CYC    ] = IsTrue;
TabLt[   T_INTNEG ][ T_CYC    ] = IsTrue;
TabLt[   T_RAT    ][ T_CYC    ] = IsTrue;
TabLt[   T_CYC    ][ T_INT    ] = IsFalse;
TabLt[   T_CYC    ][ T_INTPOS ] = IsFalse;
TabLt[   T_CYC    ][ T_INTNEG ] = IsFalse;
TabLt[   T_CYC    ][ T_RAT    ] = IsFalse;
InstIntFunc( "E",         FunE         );
InstIntFunc( "IsCyc",     FunIsCyc     );
InstIntFunc( "IsCycInt",  FunIsCycInt  );
InstIntFunc( "NofCyc",    FunNofCyc    );
InstIntFunc( "COEFFSCYC", FunCoeffsCyc );
InstIntFunc( "GaloisCyc", FunGaloisCyc );
}
int             main ( argc, argv )
int                 argc;
char                * argv [];
{
TypHandle           hd;
unsigned long       start;


InitGap( argc, argv );
setjmp( ErrRet );
while ( Symbol != S_EOF ) {
Prompt = "gap> ";
EnterKernel();
NrError = 0;
hd = ReadIt();
if ( hd != 0 ) {
SyIsIntr();
start = SyTime();
hd = EVAL( hd );
if ( hd == HdReturn && PTR(hd)[0] != HdReturn )
Error("'return' must not be used in main loop",0L,0L);
else if ( hd == HdReturn ) {
hd = HdVoid;
Symbol = S_EOF;
}
PTR(HdTime)[0]  = INT_TO_HD( SyTime() - start );
if ( TYPE(hd) != T_VOID ) {
PTR(HdLast3)[0] = PTR(HdLast2)[0];
PTR(HdLast2)[0] = PTR(HdLast)[0];
PTR(HdLast)[0]  = hd;
if ( *In != ';' ) {
IsString( hd );
Print( hd );
Pr("\n",0L,0L);
}
}
}
ExitKernel( (TypHandle)0 );
}
SyExit( 0 );
return 0;
}
