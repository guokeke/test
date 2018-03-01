/* 当前文件是D:\Read\main.c*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <signal.h>
#include <ctype.h>
#include <time.h>
#include <limits.h>
#include <errno.h>
#define MAIN_VARS
typedef struct netbox {
struct netbox *nterm ;
int terminal ;
int extint   ;
int xpos     ;
int ypos     ;
int newx     ;
int newy     ;
short int row  ;
short int cell ;
short int net ;
#ifdef HAVE_SIGNED_CHAR
signed char pinloc   ;
#else
char pinloc   ;
#endif
char unequiv  ;
char flag     ;
char layer    ;
}
*NBOXPTR ,
NBOX ;
#define ABS(value)   ( (value)>=0 ? (value) : -(value) )
#define LEFT  -1
#define RIGHT 1
#define OLD 0
#define NEW 1
#ifndef UTILS_H
#define UTILS_H
#endif
#define LRECL 255
#ifdef HAVE_LIMITS_H
#else
#ifndef INT_MAX
#define INT_MAX 2147483647
#endif
#ifndef INT_MIN
#define INT_MIN (-INT_MAX - 1)
#endif
#endif







#ifdef VMS
#define TW_OK 1
#define TW_FAIL 0
#else
#define TW_OK 0
#define TW_FAIL 1
#endif
#define FEED_INSTANCES
#define twopen(a,b,c) (openFile(a,b,c))
#define twclose(a)    (fclose(a))
#ifndef MAXINT
#define MAXINT 0x7FFFFFFF
#endif
#define RAND (Yacm_random() )
#define ZERO 0
#define ALLOC(type)    (  (type *) safe_malloc ( sizeof(type) )  )
#define LINE printf(" file : %s  line # %d\n", __FILE__,__LINE__);
#define ABS(value)   ( (value)>=0 ? (value) : -(value) )
#define make_string(s) strcpy(safe_malloc(strlen(s)+1), s)
#define SetBin(x) (( (Trybin=((x)-binOffst)/binWidth)<0 ) ? 0 : \
((Trybin>numBins) ? numBins : Trybin ))
#define CULLNULL (CBOXPTR) NULL
#define NETNULL (NBOXPTR) NULL
#define DIMNULL (DBOXPTR) NULL
#define TILENULL (TIBOXPTR) NULL
#define TERMNULL (TEBOXPTR) NULL
#define TNETNULL (TNETSPTR) NULL
#define L   1
#define B   4
#define MUL 5
#define MUR 6
#define MLL 7
#define MLR 8
#define ML  9
#define MR  10
#define MB  11
#define MT  12
#define MM  13
#define MTT 14
#define MBB 15
#define TRUE 1
#define FALSE 0
#define LEFT_MOST 0
#define RITE_MOST 1
#define FEED_FLAG 2
#define NOT_DONE -2
#define NO_PINS -1000
#define BIG_NUMBER 32000
#define ROW_STATS rowgrid
#define YES 1
#define NO 0
#define ABORT 1
#define NOABORT 0
typedef struct blockbox {
int bxcenter  ;
int bycenter  ;
short int bleft     ;
short int bright    ;
short int bbottom   ;
short int btop      ;
short int bheight   ;
short int blength   ;
short int desire    ;
short int oldsize   ;
short int newsize   ;
short int bclass    ;
short int borient   ;
} *BBOXPTR, BBOX ;

typedef struct termbox {
struct termbox *nextterm ;
NBOXPTR  termptr;
int cellterm    ;
int ei          ;
short int net   ;
short int txpos[2] ;
short int typos[2] ;
short int ue    ;
} *TEBOXPTR, TEBOX ;
typedef struct tilebox {
short int left     ;
short int right    ;
short int bottom   ;
short int top      ;
TEBOXPTR termsptr ;
}
*TIBOXPTR ,
TIBOX ;
typedef struct cellbox {
char *cname           ;
char corient          ;
char orflag           ;
int cxcenter          ;
int cycenter          ;
short int cclass      ;
short int cheight     ;
short int clength     ;
short int border      ;
short int cblock      ;
short int numterms    ;
short int padside     ;
TIBOXPTR tileptr ;
}
*CBOXPTR ,
CBOX ;
typedef struct dimbox {
NBOXPTR netptr ;
char *name   ;
char dflag    ;
char feedflag ;
char ignore   ;
int old_total ;
int new_total ;
int xmin     ;
int newxmin  ;
int xmax     ;
int newxmax  ;
int ymin     ;
int newymin  ;
int ymax     ;
int newymax  ;
short int Lnum     ;
short int newLnum  ;
short int Rnum     ;
short int newRnum  ;
short int Bnum     ;
short int newBnum  ;
short int Tnum     ;
short int newTnum  ;
short int numpins  ;
double Vweight ;
double Hweight ;
}
*DBOXPTR ,
DBOX ;
typedef struct hash {
char *hname ;
int hnum ;
struct hash *hnext ;
}
HASHBOX ,
*HASHPTR ;
typedef struct rowbox {
int startx  ;
int endx    ;
int endx1   ;
int startx2 ;
int ypos    ;
int desiredL ;
} ROWBOX ;
typedef struct binbox {
int left ;
int right ;
int *cell ;
int penalty ;
int nupenalty ;
} BINBOX ,
*BINPTR ;
typedef struct changrdbox {
NBOXPTR netptr ;
short int tracks ;
short int ntracks ;
short int SegType ;
short int nSegType ;
struct changrdbox *prevgrd ;
struct changrdbox *nprevgrd ;
struct changrdbox *nextgrd ;
struct changrdbox *nnextgrd ;
struct densitybox *dptr ;
}
*CHANGRDPTR ,
CHANGRDBOX ;
typedef struct tgridbox {
CHANGRDPTR up ;
CHANGRDPTR down ;
}
*TGRIDPTR ,
TGRIDBOX ;
typedef struct densitybox {
CHANGRDPTR grdptr ;
struct densitybox *next ;
struct densitybox *nnext ;
struct densitybox *back ;
struct densitybox *nback ;
}
*DENSITYPTR ,
DENSITYBOX ;
typedef struct segbox {
short int channel ;
int pin1    ;
int pin2    ;
CHANGRDPTR pin1ptr    ;
CHANGRDPTR pin2ptr   ;
}
*SEGBOXPTR ,
SEGBOX ;
typedef struct switchbox {
int net ;
char nflag ;
char ncurrent ;
char nswYorN ;
char current ;
char swYorN ;
short int key ;
short int nkey ;
SEGBOXPTR ntop ;
SEGBOXPTR nbot ;
SEGBOXPTR top ;
SEGBOXPTR bot ;
}
*SWITCHBOXPTR ,
SWITCHBOX ;
typedef struct edgeBox {
short int group1 ;
short int group2 ;
short int cost   ;
short int marked ;
short int poison ;
short int done   ;
}
*edgeBptr,
edgeBox ;
typedef struct chkBox {
short int lowx  ;
short int highx ;
short int ming  ;
short int maxg  ;
short int chky  ;
}
*chkBptr,
chkBox ;
typedef struct csPinBox {
int pin  ;
short int xloc ;
short int yloc ;
short int top  ;
}
*csPinPtr ,
csPinBox ;
typedef struct csGroup {
int extint  ;
int aveX    ;
int aveY    ;
short int poison  ;
short int edge1   ;
short int edge2   ;
short int unequiv ;
short int block   ;
short int check   ;
short int numPins ;
short int pinLimit ;
short int flag    ;
csPinBox *pinArray ;
}
csGroup ;
FILE *fpo ;
extern unsigned randomSeed  ;
extern unsigned randomSeed2 ;
extern char cktName[128] ;
extern int connection_machine ;
extern int estimate_feeds ;
extern int tw_fast ;
extern int gate_array_special ;
extern int pin_layers_given ;
extern int no_feeds_side_nets ;
extern int no_net_normalize ;
extern int route2act ;    /* added for placement adjusted for routing */
extern int routeGrid ;    /* used only if global routing is performed */
extern int gridCell ;    /* used only if global routing is performed */
extern int feedLayer ;
extern int resume_run ;
extern int attmax ;
extern int maxCellO ;
extern int iteration ;
extern int iwire ;
extern int iwirex ;
extern int iwirey ;
extern int fwire ;
extern int fwirex ;
extern int fwirey ;
extern int blkxspan ;
extern int blkyspan ;
extern int ffeeds ;
extern int addFeeds ;
extern int fdWidth ;
extern int lrtxspan ;
extern int lrtyspan ;
extern int **pairArray ;
extern int attprcel ;
extern int doglobal ; 
extern int cswaps ;
extern int costonly ;
extern int restart  ;
extern int ifrange ;
extern int *fixarray ;
extern int tw_fast ;
extern int tw_slow ;
extern double T1 ;
extern double Tzero ;
extern double *desired_accept ;
extern double imprange ;
extern double binpenCon ;
extern double indent ;
extern double rowSep ;
extern double roLenCon ;
extern double stopdeg ;
extern double macspace[16] ;
extern double cost_scale_factor ;


extern int tracks ;
extern int numChans ;
extern int *maxTrack ;
extern int rowHeight ;
extern int maxterm ;
extern int fdthrus ;
extern int numSegs ;
extern int impcount ;
extern int *nofeed ;
extern int stage ;
extern int *pinlist ;
extern int one_pin_feedthru ;

/* 当前文件是D:\Read\standard.h*/

/* 当前文件是D:\Read\utils.h*/



extern HASHPTR *hashtab ;
extern int netctr ;
extern CBOXPTR  *carray  ;
extern DBOXPTR   *netarray   ;
extern NBOXPTR *tearray  ;
extern BBOXPTR *barray ;
extern ROWBOX *rowArray ;
extern BINBOX ***binptr ;
extern CHANGRDPTR ULgrdptr , URgrdptr , LLgrdptr , LRgrdptr , *Shuffle ;
extern int bdxlen , bdylen ;
extern int numblock ;
extern int numcells ;
extern int numterms ;
extern int numnets ;
extern int numRows ;
extern int penalty  ;
extern int funccost ;
extern int Trybin   ;
extern int binpenal ;
extern int rowpenal ;
extern int newrowpenal ;
extern int newbinpenal ;
extern int Left_bound, Rite_bound ;
extern int **cedgebin, cedge_binwidth, num_edgebin ;
extern int gtopChan , gbotChan ;
extern int one_pin_feedthru ;
extern int numBins  ;
extern int binWidth ;
extern int binOffst ;
extern int fdWidth  ;
extern int feeds ;
extern short int **rowgrid ;
extern int windx ;
extern int randVar ;
extern int max_blklength ;
extern int desiredL ;
extern int implicit_feed_count ;
extern int *feeds_in_row ;
extern int resume_run ;
extern int uneven_cell_height ;
extern int track_spacing ;
extern char cktName[] ;
extern FILE *fpo ;

/* 当前文件是D:\Read\parser.c*/
int celllen ;
int *fixLRBT ;
double *padspace ;
parser( fp )
FILE *fp ;
{
DBOXPTR nptr ;
int cell , test , layer ;
int block , left , right , bottom , top ;
int xpos , ypos , orient ;
int from , orderchk ;
int length , terms ;
int term , i , pinctr ;
double space ;
char input[1024] ;
celllen = 0 ;
cell = 0 ;
terms = 0 ;
pinctr = 0 ;
maketabl() ;
while( fscanf( fp , " %s " , input ) == 1 ) {
if( strcmp( input , "cell") == 0 ) {
	cell++ ;
	orderchk = 0 ;
	test = fscanf( fp , " %s " , input ) ;
	if( test != 1 ) {
	    fprintf( fpo, "Failed to input dummy cell number/name ");
	    fprintf( fpo, "in the .cel file\n");
	    fprintf( fpo, "Current cell: %d\n", cell ) ;
	    exit(TW_FAIL);
	}
	fscanf( fp , " %s " , input ) ;
} else if( strcmp( input , "left") == 0 ) {
	test = fscanf( fp , " %d " , &left ) ;
	if( test != 1 ) {
	    fprintf( fpo, "Failed to input left ");
	    fprintf( fpo, "in the .cel file\n");
	    fprintf( fpo, "Current cell: %d\n", cell ) ;
	    exit(TW_FAIL);
	}
	fscanf( fp , " %s " , input ) ;
	if( strcmp( input , "right") == 0 ) {
	    test = fscanf( fp , " %d " , &right ) ;
	    if( test != 1 ) {
		fprintf( fpo, "Failed to input right ");
		fprintf( fpo, "in the .cel file\n");
		fprintf( fpo, "Current cell: %d\n", cell ) ;
		exit(TW_FAIL);
	    }
	} else {
	    fprintf( fpo, "Failed to find keyword right ");
	    fprintf( fpo, "for a cell\n") ;
	    fprintf( fpo, "Current cell: %d\n", cell ) ;
	    exit(TW_FAIL) ;
	}
	fscanf( fp , " %s " , input ) ;
	if( strcmp( input , "bottom") == 0 ) {
	    test = fscanf( fp , " %d " , &bottom ) ;
	    if( test != 1 ) {
		fprintf( fpo, "Failed to input bottom ");
		fprintf( fpo, "in the .cel file\n");
		fprintf( fpo, "Current cell: %d\n", cell ) ;
		exit(TW_FAIL);
	    }
	} else {
	    fprintf( fpo, "Failed to find keyword bottom ");
	    fprintf( fpo, "for a cell\n") ;
	    fprintf( fpo, "Current cell: %d\n", cell ) ;
	    exit(TW_FAIL) ;
	}
	fscanf( fp , " %s " , input ) ;
	if( strcmp( input , "top") == 0 ) {
	    test = fscanf( fp , " %d " , &top ) ;
	    if( test != 1 ) {
		fprintf( fpo,"Failed to input top ");
		fprintf( fpo,"in the .cel file\n");
		fprintf( fpo, "Current cell: %d\n", cell ) ;
		exit(TW_FAIL);
	    }
	} else {
	    fprintf( fpo, "Failed to find keyword top ");
	    fprintf( fpo, "for a cell\n") ;
	    fprintf( fpo, "Current cell: %d\n", cell ) ;
	    exit(TW_FAIL) ;
	}
	if( right + left != 0  &&  right + left != 1 || left > 0 ) {
	    fprintf( fpo, "The given center of the cell ");
	    fprintf( fpo, "is not (right + left) div 2\n");
	    fprintf( fpo, "Where the remainder is truncated\n");
	    fprintf( fpo, "Current cell: %d\n", cell ) ;
	    exit(TW_FAIL) ;
	}
	if( top + bottom != 0 && top + bottom != 1 || bottom > 0 ) {
	    fprintf( fpo, "The given center of the cell ");
	    fprintf( fpo, "is not (top + bottom) div 2\n");
	    fprintf( fpo, "Where the remainder is truncated\n");
	    fprintf( fpo, "Current cell: %d\n", cell ) ;
	    exit(TW_FAIL) ;
	}
	length = right - left ;
	celllen += length ;
} else if( strcmp( input , "initially") == 0 ) {
	if( orderchk != 0 ) {
	    fprintf(fpo,"cannot preplace fixed sequence\n");
	    fprintf( fpo, "in the .cel file\n");
	    fprintf( fpo, "Current cell: %d\n", cell ) ;
	    exit(TW_FAIL);
	}
	orderchk = 1 ;
	fscanf( fp , " %s " , input ) ;
	if( strcmp( input , "fixed") == 0 ) {
	} else if( strcmp( input , "nonfixed") == 0 ) {
	} else {
	    fprintf( fpo, "Failed to find fixed or nonfixed\n");
	    fprintf( fpo, "Current cell: %d\n", cell ) ;
	    exit(TW_FAIL) ;
	}
	test = fscanf( fp , " %d " , &from ) ;
	if( test != 1 ) {
	    fprintf(fpo,"Failed to input amount from following ");
	    fprintf(fpo,"(fixed,nonfixed) in the .cel file");
	    fprintf(fpo,"Current cell: %d\n", cell ) ;
	    exit(TW_FAIL);
	}
	fscanf( fp , " %s " , input ) ;
	if( strcmp( input , "from") != 0 ) {
	    fprintf( fpo, "Failed to find keyword from ");
	    fprintf( fpo, "in the .cel file");
	    fprintf( fpo, "Current cell: %d\n", cell ) ;
	    exit(TW_FAIL) ;
	}
	fscanf( fp , " %s " , input ) ;
	if( strcmp( input , "left") == 0 ) {
	} else if( strcmp( input , "right") == 0 ) {
	} else {
	    fprintf( fpo, "Failed to find left or right\n");
	    fprintf( fpo, "following from in the .cel file");
	    fprintf( fpo, "Current cell: %d\n", cell ) ;
	    exit(TW_FAIL) ;
	}
	fscanf( fp , " %s " , input ) ;
	if( strcmp( input , "of") != 0 ) {
	    fprintf( fpo, "Failed to find keyword of ");
	    fprintf( fpo, "in the .cel file");
	    fprintf( fpo, "Current cell: %d\n", cell ) ;
	    exit(TW_FAIL) ;
	}
	fscanf( fp , " %s " , input ) ;
	if( strcmp( input , "block") != 0 ) {
	    fprintf( fpo, "Failed to find keyword block ");
	    fprintf( fpo, "in the .cel file");
	    fprintf( fpo, "Current cell: %d\n", cell ) ;
	    exit(TW_FAIL) ;
	}
	test = fscanf( fp , " %d " , &block ) ;
	if( test != 1 ) {
	    fprintf(fpo,"Failed to input amount from following ");
	    fprintf(fpo,"(fixed,nonfixed) in the .cel file");
	    fprintf(fpo,"Current cell: %d\n", cell ) ;
	    exit(TW_FAIL);
	}
	
} else if( strcmp( input , "nomirror") == 0 ) {
} else if( strcmp( input , "pin") == 0 ) {
	fscanf( fp , " %s " , input ) ;
	if( strcmp( input , "name") != 0 ) {
	    fprintf( fpo, "Failed to find keyword name ");
	    fprintf( fpo, "for a pin\n") ;
	    fprintf( fpo, "Current cell: %d\n", cell ) ;
	    exit(TW_FAIL) ;
	}
	test = fscanf( fp , " %s " , input ) ;
	if( test != 1 ) {
	    fprintf( fpo, "Failed to input pin name ");
	    fprintf( fpo, "in the .cel file\n");
	    fprintf( fpo, "Current cell: %d\n", cell ) ;
	    exit(TW_FAIL);
	}
	fscanf( fp , " %s " , input ) ;
	if( strcmp( input , "signal") != 0 ) {
	    fprintf( fpo, "Failed to find keyword signal ");
	    fprintf( fpo, "for a pin\n") ;
	    fprintf( fpo, "Current cell: %d\n", cell ) ;
	    exit(TW_FAIL) ;
	}
	test = fscanf( fp , " %s " , input ) ;
	if( test != 1 ) {
	    fprintf( fpo, "Failed to input signal name ");
	    fprintf( fpo, "in the .cel file\n");
	    fprintf( fpo, "Current cell: %d\n", cell ) ;
	    exit(TW_FAIL);
	}
	if( strcmp( input , "TW_PASS_THRU" ) != 0 ) {
	    addhash( input ) ;
	    pinctr++ ;
	}
	if( pin_layers_given != 0 ) {
	    fscanf( fp , " %s " , input ) ;
	    if( strcmp( input , "layer") != 0 ) {
		fprintf( fpo, "Failed to find keyword layer ");
		fprintf( fpo, "for a pin\n") ;
		fprintf( fpo, "Current cell: %d\n", cell ) ;
		exit(TW_FAIL) ;
	    }
	    test = fscanf( fp , " %d " , &layer ) ;
	    if( test != 1 ) {
		fprintf( fpo, "Failed to input layer number ");
		fprintf( fpo, "in the .cel file\n");
		fprintf( fpo, "Current cell: %d\n", cell ) ;
		exit(TW_FAIL);
	    }
	    if( layer != 1 && layer != 2 && layer != 3 ) {
		fprintf( fpo, "Currently, a layer number ");
		fprintf( fpo, "in the .cel file must be either 1, 2,\n");
		fprintf( fpo, "or 3.   Current cell: %d\n", cell ) ;
		exit(TW_FAIL);
	    }
	}
	test = fscanf( fp , " %d %d " , &xpos , &ypos ) ;
	if( test != 2 ) {
	    fprintf( fpo, "Failed to input 2 items ");
	    fprintf( fpo, "for pin in the .cel file\n");
	    fprintf( fpo, "Current cell: %d\n", cell ) ;
	    exit(TW_FAIL);
	}
} else if( strcmp( input , "equiv") == 0 ) {
	fscanf( fp , " %s " , input ) ;
	if( strcmp( input , "name") != 0 ) {
	    fprintf( fpo, "Failed to find keyword name ");
	    fprintf( fpo, "for an equiv pin\n") ;
	    fprintf( fpo, "Current cell: %d\n", cell ) ;
	    exit(TW_FAIL) ;
	}
	test = fscanf( fp , " %s " , input ) ;
	if( test != 1 ) {
	    fprintf( fpo, "Failed to input equiv pin name ");
	    fprintf( fpo, "in the .cel file\n");
	    fprintf( fpo, "Current cell: %d\n", cell ) ;
	    exit(TW_FAIL);
	}
	if( pin_layers_given != 0 ) {
	    fscanf( fp , " %s " , input ) ;
	    if( strcmp( input , "layer") != 0 ) {
		fprintf( fpo, "Failed to find keyword layer ");
		fprintf( fpo, "for an equiv pin\n") ;
		fprintf( fpo, "Current cell: %d\n", cell ) ;
		exit(TW_FAIL) ;
	    }
	    test = fscanf( fp , " %d " , &layer ) ;
	    if( test != 1 ) {
		fprintf( fpo, "Failed to input layer number ");
		fprintf( fpo, "in the .cel file\n");
		fprintf( fpo, "Current cell: %d\n", cell ) ;
		exit(TW_FAIL);
	    }
	    if( layer != 1 && layer != 2 && layer != 3 ) {
		fprintf( fpo, "Currently, a layer number ");
		fprintf( fpo, "in the .cel file must be either 1, 2,\n");
		fprintf( fpo, "or 3.   Current cell: %d\n", cell ) ;
		exit(TW_FAIL);
	    }
	}
	test = fscanf( fp , " %d %d " , &xpos , &ypos ) ;
	if( test != 2 ) {
	    fprintf( fpo, "Failed to input 2 items ");
	    fprintf( fpo, "for equiv in the .cel file\n");
	    fprintf( fpo, "Current cell: %d\n", cell ) ;
	    exit(TW_FAIL);
	}
} else if( strcmp( input , "unequiv") == 0 ) {
	fscanf( fp , " %s " , input ) ;
	if( strcmp( input , "name") != 0 ) {
	    fprintf( fpo, "Failed to find keyword name ");
	    fprintf( fpo, "for an unequiv pin\n") ;
	    fprintf( fpo, "Current cell: %d\n", cell ) ;
	    exit(TW_FAIL) ;
	}
	test = fscanf( fp , " %s " , input ) ;
	if( test != 1 ) {
	    fprintf( fpo, "Failed to input unequiv pin name ");
	    fprintf( fpo, "in the .cel file\n");
	    fprintf( fpo, "Current cell: %d\n", cell ) ;
	    exit(TW_FAIL);
	}
	if( pin_layers_given != 0 ) {
	    fscanf( fp , " %s " , input ) ;
	    if( strcmp( input , "layer") != 0 ) {
		fprintf( fpo, "Failed to find keyword layer ");
		fprintf( fpo, "for an unequiv pin\n") ;
		fprintf( fpo, "Current cell: %d\n", cell ) ;
		exit(TW_FAIL) ;
	    }
	    test = fscanf( fp , " %d " , &layer ) ;
	    if( test != 1 ) {
		fprintf( fpo, "Failed to input layer number ");
		fprintf( fpo, "in the .cel file\n");
		fprintf( fpo, "Current cell: %d\n", cell ) ;
		exit(TW_FAIL);
	    }
	    if( layer != 1 && layer != 2 && layer != 3 ) {
		fprintf( fpo, "Currently, a layer number ");
		fprintf( fpo, "in the .cel file must be either 1, 2,\n");
		fprintf( fpo, "or 3.   Current cell: %d\n", cell ) ;
		exit(TW_FAIL);
	    }
	}
	test = fscanf( fp , " %d %d " , &xpos , &ypos ) ;
	if( test != 2 ) {
	    fprintf( fpo, "Failed to input 2 items ");
	    fprintf( fpo, "for unequiv in the .cel file\n");
	    fprintf( fpo, "Current cell: %d\n", cell ) ;
	    exit(TW_FAIL);
	}
} else if( strcmp( input , "pad") == 0 ) {
	terms++ ;
	test = fscanf( fp , " %s " , input ) ;
	if( test != 1 ) {
	    fprintf( fpo, "Failed to input dummy pad number/name ");
	    fprintf( fpo, "in the .cel file\n");
	    fprintf( fpo, "Current cell: %d\n", cell ) ;
	    exit(TW_FAIL);
	}
	fscanf( fp , " %s " , input ) ;
	fscanf( fp , " %s " , input ) ;
	if( strcmp( input , "orient") == 0 ) {
	    test = fscanf( fp , " %d " , &orient ) ;
	    if( test != 1 ) {
		fprintf( fpo, "Failed to input orient ");
		fprintf( fpo, "in the .cel file\n");
		fprintf( fpo, "Current cell: %d\n", cell ) ;
		exit(TW_FAIL);
	    }
	} else {
	    fprintf( fpo, "Failed to find keyword orient ");
	    fprintf( fpo, "for a pad\n") ;
	    fprintf( fpo, "Current cell: %d\n", cell ) ;
	    exit(TW_FAIL) ;
	}
	fscanf( fp , " %s " , input ) ;
	if( strcmp( input , "padside") == 0 ) {
	    test = fscanf( fp , " %s " , input ) ;
	    if( test != 1 ) {
		fprintf( fpo, "Failed to input padside ");
		fprintf( fpo, "in the .cel file\n");
		fprintf( fpo, "Current cell: %d\n", cell ) ;
		exit(TW_FAIL);
	    }
	} else {
	    fprintf( fpo, "Failed to find keyword padside ");
	    fprintf( fpo, "for a pad\n") ;
	    fprintf( fpo, "Current cell: %d\n", cell ) ;
	    exit(TW_FAIL) ;
	}
	fscanf( fp , " %s " , input ) ;
	if( strcmp( input , "left") == 0 ) {
	    test = fscanf( fp , " %d " , &left ) ;
	    if( test != 1 ) {
		fprintf( fpo, "Failed to input left ");
		fprintf( fpo, "in the .cel file\n");
		fprintf( fpo, "Current cell: %d\n", cell ) ;
		exit(TW_FAIL);
	    }
	} else {
	    fprintf( fpo, "Failed to find keyword left ");
	    fprintf( fpo, "for a pad\n") ;
	    fprintf( fpo, "Current cell: %d\n", cell ) ;
	    exit(TW_FAIL) ;
	}
	fscanf( fp , " %s " , input ) ;
	if( strcmp( input , "right") == 0 ) {
	    test = fscanf( fp , " %d " , &right ) ;
	    if( test != 1 ) {
		fprintf( fpo, "Failed to input right ");
		fprintf( fpo, "in the .cel file\n");
		fprintf( fpo, "Current cell: %d\n", cell ) ;
		exit(TW_FAIL);
	    }
	} else {
	    fprintf( fpo, "Failed to find keyword right ");
	    fprintf( fpo, "for a pad\n") ;
	    fprintf( fpo, "Current cell: %d\n", cell ) ;
	    exit(TW_FAIL) ;
	}
	if( right + left != 0  &&  right + left != 1 ) {
	    fprintf( fpo, "The given center of the cell ");
	    fprintf( fpo, "is not (right + left) div 2\n");
	    fprintf( fpo, "Where the remainder is truncated\n");
	    fprintf( fpo, "Current cell: %d\n", cell ) ;
	    exit(TW_FAIL) ;
	}
	fscanf( fp , " %s " , input ) ;
	if( strcmp( input , "bottom") == 0 ) {
	    test = fscanf( fp , " %d " , &bottom ) ;
	    if( test != 1 ) {
		fprintf( fpo, "Failed to input bottom ");
		fprintf( fpo, "in the .cel file\n");
		fprintf( fpo, "Current cell: %d\n", cell ) ;
		exit(TW_FAIL);
	    }
	} else {
	    fprintf( fpo, "Failed to find keyword bottom ");
	    fprintf( fpo, "for a pad\n") ;
	    fprintf( fpo, "Current cell: %d\n", cell ) ;
	    exit(TW_FAIL) ;
	}
	fscanf( fp , " %s " , input ) ;
	if( strcmp( input , "top") == 0 ) {
	    test = fscanf( fp , " %d " , &top ) ;
	    if( test != 1 ) {
		fprintf( fpo,"Failed to input top ");
		fprintf( fpo,"in the .cel file\n");
		fprintf( fpo, "Current cell: %d\n", cell ) ;
		exit(TW_FAIL);
	    }
	} else {
	    fprintf( fpo, "Failed to find keyword top ");
	    fprintf( fpo, "for a pad\n") ;
	    fprintf( fpo, "Current cell: %d\n", cell ) ;
	    exit(TW_FAIL) ;
	}
	if( top + bottom != 0  &&  top + bottom != 1 ) {
	    fprintf( fpo, "The given center of the cell ");
	    fprintf( fpo, "is not (top + bottom) div 2\n");
	    fprintf( fpo, "Where the remainder is truncated\n");
	    fprintf( fpo, "Current cell: %d\n", cell ) ;
	    exit(TW_FAIL) ;
	}
} else if( strcmp( input , "sidespace") == 0 ) {
	test = fscanf( fp , " %lf " , &space ) ;
} else {
	fprintf( fpo, "Found unparsable keyword in ");
	fprintf( fpo, "the .cel file\n");
	fprintf( fpo, "Current cell: %d\n", cell ) ;
	exit(TW_FAIL) ;
}
}
rewind( fp ) ;
numcells = cell  ;
numterms = terms ;
padspace = (double *) safe_malloc( (numterms + 1) * sizeof(double) ) ;
for( i = 1 ; i <= numterms ; i++ ) {
padspace[i] = 0.0 ;
}
fixLRBT  = (int *) safe_malloc( 4 * sizeof( int ) ) ;
fixLRBT[0] = 0 ;
fixLRBT[1] = 0 ;
fixLRBT[2] = 0 ;
fixLRBT[3] = 0 ;
netarray = (DBOXPTR *) safe_malloc( (netctr + 1) * sizeof( DBOXPTR ) ) ;
for( i = 1 ; i <= netctr ; i++ ) {
nptr = netarray[ i ] = (DBOXPTR) safe_malloc( sizeof( DBOX ) ) ;
nptr->netptr  = NETNULL ;
nptr->name    = NULL    ;
nptr->dflag   = 0       ;
nptr->xmin    = 0       ;
nptr->newxmin = 0       ;
nptr->xmax    = 0       ;
nptr->newxmax = 0       ;
nptr->ymin    = 0       ;
nptr->newymin = 0       ;
nptr->ymax    = 0       ;
nptr->newymax = 0       ;
nptr->Hweight = 1.0     ;
nptr->Vweight = 1.0     ;
nptr->feedflag = 0      ;
nptr->ignore   = 0      ;
}
numnets = netctr ;
tearray = (NBOXPTR *)safe_malloc( (pinctr + 1) * sizeof( NBOXPTR ) );
for( term = 1 ; term <= pinctr ; term++ ) {
tearray[ term ] = NETNULL ;
}
maxterm = pinctr ;
return ;
}
/* 当前文件是D:\Read\readblck.c*/

int *nofeed ;
double *relativeLen ;
readblck( fp )
FILE *fp ;
{
int test , block , class , height , row ;
double relLen ;
char input[32] ;
block = 0 ;
while( fscanf( fp , " %s " , input ) == 1 ) {
if( strcmp( input , "block") == 0 ) {
	block++ ;
	fscanf( fp , " %s " , input ) ;
	if( strcmp( input , "height") == 0 ) {
	    test = fscanf( fp , " %d " , &height ) ;
	    if( test != 1 ) {
		fprintf( fpo,"Failed to input height of a block\n");
		fprintf( fpo,"at position height\n");
		exit(TW_FAIL);
	    }
	} else {
	    fprintf(fpo,"unexpected keyword in the .blk file\n");
	    fprintf( fpo, "at position height\n");
	    fprintf( fpo, "current block: %d\n", block );
	    exit(TW_FAIL);
	}
	fscanf( fp , " %s " , input ) ;
	if( strcmp( input , "class") == 0 ) {
	    test = fscanf( fp , " %d " , &class ) ;
	    if( test != 1 ) {
		fprintf( fpo, "Failed to input class of a block\n");
		fprintf( fpo, "current block: %d\n", block );
		exit(TW_FAIL);
	    }
	} else {
	    fprintf( fpo, "unexpected keyword in the .blk file\n");
	    fprintf( fpo, "at position class\n");
	    fprintf( fpo, "current block: %d\n", block );
	    exit(TW_FAIL);
	}
} else if( strcmp( input , "mirror") == 0 ) {
} else if( strcmp( input , "nofeeds") == 0 ) {
} else if( strcmp( input , "relative_length") == 0 ) {
	test = fscanf( fp , " %f " , &relLen ) ;
} else {
	fprintf( fpo, "unexpected keyword in the .blk file\n");
	fprintf( fpo, "current block: %d\n", block );
	exit(TW_FAIL);
}
}
numblock = block ;
rewind( fp ) ;
barray = (BBOXPTR *) safe_malloc( (numblock + 1) * sizeof( BBOXPTR ) ) ;
nofeed = (int *) safe_malloc( ( numblock + 2 ) * sizeof( int ) ) ;
for( row = 0 ; row <= numblock + 1 ; row++ ) {
nofeed[row] = 0 ;
}
relativeLen = (double *) safe_malloc( (numblock + 1) * sizeof( double ) ) ;
for( block = 1 ; block <= numblock ; block++ ) {
relativeLen[block] = 1.0 ;
}
for( block = 1 ; block <= numblock ; block++ ) {
barray[ block ] = (BBOXPTR) safe_malloc( sizeof( BBOX ));
barray[ block ]->bxcenter = 0 ;
barray[ block ]->bycenter = 0 ;
barray[ block ]->bleft    = 0 ;
barray[ block ]->bright   = 0 ;
barray[ block ]->bbottom  = 0 ;
barray[ block ]->btop     = 0 ;
barray[ block ]->bheight  = 0 ;
barray[ block ]->blength  = 0 ;
barray[ block ]->bclass   = 0 ;
barray[ block ]->borient  = 0 ;
barray[ block ]->desire   = 0 ;
barray[ block ]->oldsize  = 0 ;
barray[ block ]->newsize  = 0 ;
}
block = 0 ;
while( fscanf( fp , " %s " , input ) == 1 ) {
if( strcmp( input , "block" ) == 0 ) {
	block++ ;
	fscanf( fp , " %s " , input ) ;
	fscanf( fp , " %d " , &height ) ;
	barray[block]->btop    = height - height / 2 ;
	barray[block]->bbottom = - height / 2 ;
	barray[block]->bheight = height ;
	fscanf( fp , " %s " , input ) ;
	fscanf( fp , " %d " , &class ) ;
	barray[block]->bclass = class ;
	barray[block]->borient = 1 ;
} else if( strcmp( input , "mirror" ) == 0 ) {
	barray[block]->borient = 2 ;
} else if( strcmp( input , "nofeeds" ) == 0 ) {
	nofeed[block] = 1 ;
} else if( strcmp( input , "relative_length" ) == 0 ) {
	fscanf( fp , " %f " , &relLen ) ;
	relativeLen[block] = relLen ;
}
}
return ;
}
/* 当前文件是D:\Read\config1.c*/

#define MAXMACRO 50
typedef struct macrobox {
int mx ;
int my ;
} MACROBOX ;
int *blkToRow ;
int rowHeight ;
BBOXPTR boxptr , *oldbarray ;
CBOXPTR cellptr ;
MACROBOX *macroArray ;
int *filledTo , *endRow ;
int macNumber , row , totalR ;
int totalBlock , borient , empty , cell , middleRow ;
int extraSpace , pad , height , width , bot , top , trow ;
static int rows1;
int brow , rite , left , coreHeight , coreWidth , count , macro ;
int maxHeight , space , separation , yshift , xshift , last ;
int coreTop , coreRite , block , maxWidth , *padArray , numMacro ;
int URmacro , Rmacro , edge ;
int k , blk , zxshift , zyshift ;
int mttshift , mbbshift ;
double dsum , ratio ;
config1()
{
double totalF , modulation , constant ;
int M , r , topRowY , centerY ;
int count_mtt , count_mbb ;
CBOXPTR padptr ;
macroArray = (MACROBOX *) safe_malloc((MAXMACRO + 1) * sizeof(MACROBOX));
macNumber = 0 ;
numRows = numblock ;
rowArray = (ROWBOX *) safe_malloc( (numRows + 1) * sizeof( ROWBOX ) ) ;
for( row = 1 ; row <= numRows ; row++ ) {
rowArray[row].endx1   = -1 ;
rowArray[row].startx2 = -1 ;
}
totalR = celllen ;
rowHeight = 0 ;
for( row = 1 ; row <= numRows ; row++ ) {
rowHeight += barray[row]->btop - barray[row]->bbottom ;
}
rowHeight /= numRows ;
for( row = 1 ; row <= numRows ; row++ ) {
rowArray[row].startx = 0 ;
rowArray[row].ypos = (row - 1) * (rowSep + 1) * rowHeight +
						rowHeight / 2 ;
}
if( numRows > 1 ) {
totalF = 0.0 ;
for( r = 1 ; r <= numRows ; r++ ) {
	totalF += relativeLen[r] ;
}
topRowY = rowArray[numRows].ypos ;
centerY = (topRowY + rowArray[1].ypos) / 2 ;
M = (int) ( (double) totalR / totalF ) ;
dsum = 0.0 ;
for( r = 1 ; r <= numRows ; r++ ) {
	dsum += relativeLen[r] *
			    (double)(ABS(rowArray[r].ypos - centerY));
}
dsum /= totalF ;
dsum *= 1.0 / (double)( topRowY - centerY ) ;
constant = 1.0 + (1.0 - indent) * (1.0 - dsum) ;
for( r = 1 ; r <= numRows ; r++ ) {
	rowArray[r].endx = (int)((double) M *
				    constant * relativeLen[r]);
	modulation = 1.0 + (1.0 - indent) * (
			  ((double)(ABS(rowArray[r].ypos - centerY)) /
			   (double)(topRowY - centerY)) - dsum);
	rowArray[r].desiredL = (int) (
		    (double) M * relativeLen[r] * modulation ) + 1 ;
}
} else {
rowArray[1].endx = totalR ;
rowArray[1].desiredL = rowArray[1].endx ;
}
extraSpace = rowSep * rowHeight ;
for( k = 1 ; k <= 15 ; k++ ) {
if( macspace[k] < 0.0 ) {
	macspace[k] = extraSpace ;
} else {
	macspace[k] *= rowHeight ;
}
}
middleRow = numRows / 2 ;
padArray = (int *) safe_malloc( (numterms + 1) * sizeof( int ) ) ;
for( pad = 1 ; pad <= numterms ; pad++ ) {
padArray[pad] = 0 ;
}
numMacro = 0 ;
for( pad = numcells + 1 ; pad <= numcells + numterms ; pad++ ) {
if( carray[pad]->padside == MUL || carray[pad]->padside == ML ||
				    carray[pad]->padside == MLL ) {
	padArray[++numMacro] = pad ;
}
}
for( pad = numcells + 1 ; pad <= numcells + numterms ; pad++ ) {
if( carray[pad]->padside == MT || carray[pad]->padside == MM ||
				    carray[pad]->padside == MB ) {
	padArray[++numMacro] = pad ;
}
}
for( pad = numcells + 1 ; pad <= numcells + numterms ; pad++ ) {
if( carray[pad]->padside == MUR ) {
	padArray[++numMacro] = pad ;
	URmacro = numMacro ;
}
}
for( pad = numcells + 1 ; pad <= numcells + numterms ; pad++ ) {
if( carray[pad]->padside == MR ) {
	padArray[++numMacro] = pad ;
	Rmacro = numMacro ;
}
}
for( pad = numcells + 1 ; pad <= numcells + numterms ; pad++ ) {
if( carray[pad]->padside == MLR ) {
	padArray[++numMacro] = pad ;
}
}
for( macro = 1 ; macro <= numMacro ; macro++ ) {
pad = padArray[macro] ;
padptr = carray[pad] ;
height = padptr->tileptr->top - padptr->tileptr->bottom ;
width  = padptr->tileptr->right - padptr->tileptr->left ;
macNumber++ ;
switch( padptr->padside ) {
case MUL : for( row = numRows ; row >= 1 ; row-- ) {
		    if( rowArray[row].ypos +
				rowSep * rowHeight * 0.33 <=
				rowArray[numRows].ypos - height ) {
			break ;
		    }
		}
		
		rows1 = numRows - row ;
		for( row++ ; row <= numRows ; row++ ) {
		    rowArray[row].startx = width + macspace[MUL] ;
		    rowArray[row].desiredL -= width + macspace[MUL] ;
		}
		for( row = 1 ; row <= numRows ; row++ ) {
		    rowArray[row].endx += (rows1 *
				(width + macspace[MUL]) ) / numRows ;
		    rowArray[row].desiredL += (rows1 *
				(width + macspace[MUL]) ) / numRows ;
		}
		macroArray[macNumber].mx = width / 2 ;
		macroArray[macNumber].my =
			(rowArray[numRows].ypos + rowHeight / 2) -
							height / 2 ;
		break ;
case MUR : for( row = numRows ; row >= 1 ; row-- ) {
		    if( rowArray[row].ypos +
				 rowSep * rowHeight * 0.33 <=
				 rowArray[numRows].ypos - height ) {
			break ;
		    }
		}
		
		rows1 = numRows - row ;
		for( row++ ; row <= numRows ; row++ ) {
		    rowArray[row].endx -= width + macspace[MUR] ;
		    rowArray[row].desiredL -= width + macspace[MUR] ;
		}
		for( row = 1 ; row <= numRows ; row++ ) {
		    rowArray[row].endx += (rows1 *
				(width + macspace[MUR]) ) / numRows ;
		    rowArray[row].desiredL += (rows1 *
				(width + macspace[MUR]) ) / numRows ;
		}
		macroArray[macNumber].mx = rowArray[numRows].endx +
					   macspace[MUR] + width / 2 ;
		macroArray[macNumber].my =
			(rowArray[numRows].ypos + rowHeight / 2) -
							height / 2 ;
		break ;
case MLL : for( row = 1 ; row <= numRows ; row++ ) {
		    if( rowArray[row].ypos -
					rowSep * rowHeight * 0.33 >=
					rowArray[1].ypos + height ) {
			break ;
		    }
		}
		
		rows1 = row - 1 ;
		for( row-- ; row >= 1 ; row-- ) {
		    rowArray[row].startx = width + macspace[MLL] ;
		    rowArray[row].desiredL -= width + macspace[MLL] ;
		}
		for( row = 1 ; row <= numRows ; row++ ) {
		    rowArray[row].endx += (rows1 *
				(width + macspace[MLL]) ) / numRows ;
		    rowArray[row].desiredL += (rows1 *
				(width + macspace[MLL]) ) / numRows ;
		}
		macroArray[macNumber].mx = width / 2 ;
		macroArray[macNumber].my =
			(rowArray[1].ypos - rowHeight / 2) +
							height / 2 ;
		break ;
case MLR : for( row = 1 ; row <= numRows ; row++ ) {
		    if( rowArray[row].ypos -
					rowSep * rowHeight * 0.33 >=
					rowArray[1].ypos + height ) {
			break ;
		    }
		}
		
		rows1 = row - 1 ;
		for( row-- ; row >= 1 ; row-- ) {
		    rowArray[row].endx -= width + macspace[MLR] ;
		    rowArray[row].desiredL -= width + macspace[MLR] ;
		}
		for( row = 1 ; row <= numRows ; row++ ) {
		    rowArray[row].endx += (rows1 *
				(width + macspace[MLR]) ) / numRows ;
		    rowArray[row].desiredL += (rows1 *
				(width + macspace[MLR]) ) / numRows ;
		}
		if( URmacro != 0 ) {
		    macroArray[URmacro].mx += (rows1 *
			    (width + macspace[MLR]) ) / numRows ;
		}
		if( Rmacro != 0 ) {
		    macroArray[Rmacro].mx += (rows1 *
			    (width + macspace[MLR]) ) / numRows ;
		}
		macroArray[macNumber].mx = rowArray[1].endx +
					   macspace[MLR] + width / 2 ;
		macroArray[macNumber].my =
			(rowArray[1].ypos - rowHeight / 2) +
							height / 2 ;
		break ;
case ML  : bot = rowArray[middleRow].ypos - height / 2 ;
		top = bot + height ;
		for( row = 1 ; row <= numRows ; row++ ) {
		    if( rowArray[row].ypos - rowHeight / 2 -
			    rowSep * rowHeight * 0.33 >= top ) {
			break ;
		    }
		}
		trow = row ;
		for( row = numRows ; row >= 1 ; row-- ) {
		    if( rowArray[row].ypos + rowHeight / 2 +
				    rowSep * rowHeight * 0.33 <= bot ) {
			break ;
		    }
		}
		brow = row ;
		
		rows1 = trow - brow - 1 ;
		for( row = brow + 1 ; row < trow ; row++ ) {
		    rowArray[row].startx = width + macspace[ML] ;
		    rowArray[row].desiredL -= width + macspace[ML] ;
		}
		for( row = 1 ; row <= numRows ; row++ ) {
		    rowArray[row].endx += (rows1 *
				(width + macspace[ML]) ) / numRows ;
		    rowArray[row].desiredL += (rows1 *
				(width + macspace[ML]) ) / numRows ;
		}
		macroArray[macNumber].mx = width / 2 ;
		macroArray[macNumber].my = rowArray[middleRow].ypos;
		break ;
case MR  : bot = rowArray[middleRow].ypos - height / 2 ;
		top = bot + height ;
		for( row = 1 ; row <= numRows ; row++ ) {
		    if( rowArray[row].ypos - rowHeight / 2 -
				    rowSep * rowHeight * 0.33 >= top ) {
			break ;
		    }
		}
		trow = row ;
		for( row = numRows ; row >= 1 ; row-- ) {
		    if( rowArray[row].ypos + rowHeight / 2 +
				    rowSep * rowHeight * 0.33 <= bot ) {
			break ;
		    }
		}
		brow = row ;
		
		rows1 = trow - brow - 1 ;
		for( row = brow + 1 ; row < trow ; row++ ) {
		    rowArray[row].endx -= width + macspace[MR] ;
		    rowArray[row].desiredL -= width + macspace[MR] ;
		}
		for( row = 1 ; row <= numRows ; row++ ) {
		    rowArray[row].endx += (rows1 *
				(width + macspace[MR]) ) / numRows ;
		    rowArray[row].desiredL += (rows1 *
				(width + macspace[MR]) ) / numRows ;
		}
		if( URmacro != 0 ) {
		    macroArray[URmacro].mx += (rows1 *
				(width + macspace[MR]) ) / numRows ;
		}
		macroArray[macNumber].mx =
				    rowArray[middleRow].endx +
				    macspace[MR] + width / 2 ;
		macroArray[macNumber].my = rowArray[middleRow].ypos;
		break ;
case MM  : bot = rowArray[middleRow].ypos - height / 2 ;
		top = bot + height ;
		
		left = (rowArray[middleRow].startx +
			rowArray[middleRow].endx ) / 2 ;
		rite = left + width ;
		for( row = 1 ; row <= numRows ; row++ ) {
		    if( rowArray[row].ypos - rowHeight / 2 -
				    rowSep * rowHeight * 0.67 >= top ) {
			break ;
		    }
		}
		trow = row ;
		for( row = numRows ; row >= 1 ; row-- ) {
		    if( rowArray[row].ypos + rowHeight / 2 +
				    rowSep * rowHeight * 0.67 <= bot ) {
			break ;
		    }
		}
		brow = row ;
		
		rows1 = trow - brow - 1 ;
		for( row = brow + 1 ; row < trow ; row++ ) {
		    rowArray[row].endx1   = left - macspace[MM] ;
		    rowArray[row].startx2 = rite + macspace[MM] ;
		   rowArray[row].desiredL -= width + 2 * macspace[MM];
		}
		for( row = 1 ; row <= numRows ; row++ ) {
		    rowArray[row].endx += (rows1 *
			      (width + 2 * macspace[MM]) ) / numRows ;
		    rowArray[row].desiredL += (rows1 *
			      (width + 2 * macspace[MM]) ) / numRows ;
		}
		macroArray[macNumber].mx = (left + rite) / 2 ;
		macroArray[macNumber].my = (bot + top) / 2 ;
		break ;
case MB  : bot = rowArray[1].ypos - rowHeight / 2 ;
		top = bot + height ;
		left = (rowArray[1].startx +
				rowArray[1].endx ) / 2 - width / 2 ;
		rite = left + width ;
		for( row = 1 ; row <= numRows ; row++ ) {
		    if( rowArray[row].ypos - rowHeight / 2 -
				    rowSep * rowHeight * 0.67 >= top ) {
			break ;
		    }
		}
		trow = row ;
		brow = 0 ;
		
		rows1 = trow - brow - 1 ;
		for( row = brow + 1 ; row < trow ; row++ ) {
		    rowArray[row].endx1   = left - macspace[MB] ;
		    rowArray[row].startx2 = rite + macspace[MB] ;
		   rowArray[row].desiredL -= width + 2 * macspace[MB];
		}
		for( row = 1 ; row <= numRows ; row++ ) {
		    rowArray[row].endx += (rows1 *
			(width + 2 * macspace[MB]) ) / numRows ;
		    rowArray[row].desiredL += (rows1 *
			(width + 2 * macspace[MB]) ) / numRows ;
		}
		macroArray[macNumber].mx = (left + rite) / 2 ;
		macroArray[macNumber].my = (bot + top) / 2 ;
		break ;
case MT  : top = rowArray[numRows].ypos + rowHeight / 2 ;
		bot = top - height ;
		left = (rowArray[numRows].startx +
			rowArray[numRows].endx ) / 2 - width / 2 ;
		rite = left + width ;
		trow = numRows + 1 ;
		for( row = numRows ; row >= 1 ; row-- ) {
		    if( rowArray[row].ypos + rowHeight / 2 +
				    rowSep * rowHeight * 0.67 <= bot ) {
			break ;
		    }
		}
		brow = row ;
		
		rows1 = trow - brow - 1 ;
		for( row = brow + 1 ; row < trow ; row++ ) {
		    rowArray[row].endx1   = left - macspace[MT] ;
		    rowArray[row].startx2 = rite + macspace[MT] ;
		   rowArray[row].desiredL -= width + 2 * macspace[MT];
		}
		for( row = 1 ; row <= numRows ; row++ ) {
		    rowArray[row].endx += (rows1 *
			     (width + 2 * macspace[MT]) ) / numRows ;
		    rowArray[row].desiredL += (rows1 *
			     (width + 2 * macspace[MT]) ) / numRows ;
		}
		macroArray[macNumber].mx = (left + rite) / 2 ;
		macroArray[macNumber].my = (bot + top) / 2 ;
		break ;
	default: fprintf(fpo,"screwup in finding padside\n");
		 exit(TW_FAIL);
		 break ;
}
}
coreHeight = rowArray[numRows].ypos + rowHeight - rowHeight / 2 ;
coreWidth = 0 ;
for( row = 1 ; row <= numRows ; row++ ) {
if( rowArray[row].endx > coreWidth ) {
	coreWidth = rowArray[row].endx ;
}
}
for( macro = 1 ; macro <= numMacro ; macro++ ) {
pad = padArray[macro] ;
edge = macroArray[macro].mx + carray[pad]->tileptr->right ;
if( edge > coreWidth ) {
	coreWidth = edge ;
}
}
mbbshift = 0 ;
height   = 0 ;
width    = 0 ;
count_mbb = 0 ;
for( pad = numcells + 1 ; pad <= numcells + numterms ; pad++ ) {
padptr = carray[pad] ;
if( padptr->padside == MBB ) {
	if( padptr->tileptr->top - padptr->tileptr->bottom > height ){
	    height = padptr->tileptr->top - padptr->tileptr->bottom ;
	}
	width += padptr->tileptr->right - padptr->tileptr->left ;
	count_mbb++ ;
}
}
if( count_mbb > 0 ) {
mbbshift = height + rowSep * rowHeight ;
for( row = 1 ; row <= numRows ; row++ ) {
	rowArray[row].ypos += mbbshift ;
}
coreHeight += mbbshift ;
if( width > coreWidth ) {
	coreWidth = width ;
}
space = coreWidth - width ;
separation = space / (count_mbb + 1) ;
if( separation < 0 ) {
	separation = 0 ;
}
maxHeight = height ;
height    = 0 ;
width     = 0 ;
last      = separation ;
for( pad = numcells + 1 ; pad <= numcells + numterms ; pad++ ) {
	padptr = carray[pad] ;
	if( padptr->padside == MBB ) {
	    height = padptr->tileptr->top - padptr->tileptr->bottom ;
	    width  = padptr->tileptr->right - padptr->tileptr->left ;
	    padptr->cxcenter = last + width / 2  ;
	    padptr->cycenter = maxHeight - height / 2 - 1 ;
	    last += separation + width ;
	}
}
}
mttshift = 0 ;
height   = 0 ;
width    = 0 ;
count_mtt = 0 ;
for( pad = numcells + 1 ; pad <= numcells + numterms ; pad++ ) {
padptr = carray[pad] ;
if( padptr->padside == MTT ) {
	if( padptr->tileptr->top - padptr->tileptr->bottom > height ){
	    height = padptr->tileptr->top - padptr->tileptr->bottom ;
	}
	width += padptr->tileptr->right - padptr->tileptr->left ;
	count_mtt++ ;
}
}
if( count_mtt > 0 ) {
mttshift = height + rowSep * rowHeight ;
coreHeight += mttshift ;
if( width > coreWidth ) {
	coreWidth = width ;
}
space = coreWidth - width ;
separation = space / (count_mtt + 1) ;
if( separation < 0 ) {
	separation = 0 ;
}
height    = 0 ;
width     = 0 ;
last      = separation ;
for( pad = numcells + 1 ; pad <= numcells + numterms ; pad++ ) {
	padptr = carray[pad] ;
	if( padptr->padside == MTT ) {
	    height = padptr->tileptr->top - padptr->tileptr->bottom ;
	    width  = padptr->tileptr->right - padptr->tileptr->left ;
	    padptr->cxcenter = last + width / 2  ;
	    padptr->cycenter = coreHeight + rowSep * rowHeight +
						    height / 2 ;
	    last += separation + width ;
	}
}
}
return ;
}
int a , b , ablock , bblock ;
#define DELTA_B 1
#define PICK_INT(l,u) (((l)<(u)) ? ((RAND % ((u)-(l)+1))+(l)) : (l))
double partition() ;
double compute_and_combination() ;
double combination() ;
double expected_value() ;
double expected_svalue() ;
double finalRowControl ;
double initialRowControl ;
int newpenal ;
int Apost , Bpost ;
int *cellaptr , *cellbptr ;
int earlyRej , Rej_error ;

int wire_chg , binpen_chg , rowpen_chg ;

int attempts ;
int delta_vert_cost ;
int tot_num_feeds ;
int tot_missing_rows ;

int *num_feeds ;
int *tmp_num_feeds ;
int *missing_rows ;
int *tmp_missing_rows ;
static char **rows ;
char **tmp_rows ;
#define T 2
#define R 3
/* 当前文件是D:\Read\ucxx2.c*/

int axcenter , aycenter , bxcenter , bycenter ;
int anxcenter , bnxcenter ;
int aleft , aright , bleft , bright ;
int potential_errors , error_count , P_limit ;
double total_wire_chg ;
double sigma_wire_chg ;
double mean_wire_chg ;
int wire_chgs ;

ucxx2( )
{
CBOXPTR acellptr , bcellptr ;
TIBOXPTR atileptr , btileptr ;
TEBOXPTR atermptr , btermptr ;
int error_light_is_on ;
int cost ;
int aorient , borient ;
int a1LoBin, a1HiBin, b1LoBin, b1HiBin ;
int a2LoBin, a2HiBin, b2LoBin, b2HiBin ;
int startxa1 , endxa1 , startxa2 , endxa2 ;
int startxb1 , endxb1 , startxb2 , endxb2 ;
int anbin , bnbin , i ;
int truth ;
double temp ;
acellptr = carray[ a ]    ;
axcenter = acellptr->cxcenter ;
aycenter = acellptr->cycenter ;
aorient  = acellptr->corient  ;
atileptr = acellptr->tileptr ;
aleft    = atileptr->left    ;
aright   = atileptr->right   ;
atermptr = atileptr->termsptr ;
bcellptr = carray[ b ]    ;
bxcenter = bcellptr->cxcenter ;
bycenter = bcellptr->cycenter ;
borient  = bcellptr->corient  ;
btileptr = bcellptr->tileptr ;
bleft    = btileptr->left    ;
bright   = btileptr->right   ;
btermptr = btileptr->termsptr ;
newbinpenal = binpenal ;
newrowpenal = rowpenal ;
newpenal    = penalty  ;
new_old( bright-bleft-aright+aleft ) ;
find_new_pos() ;
a1LoBin = SetBin( startxa1 = axcenter + aleft  ) ;
a1HiBin = SetBin( endxa1   = axcenter + aright ) ;
b1LoBin = SetBin( startxb1 = bxcenter + bleft  ) ;
b1HiBin = SetBin( endxb1   = bxcenter + bright ) ;
a2LoBin = SetBin( startxa2 = anxcenter + aleft  ) ;
a2HiBin = SetBin( endxa2   = anxcenter + aright ) ;
b2LoBin = SetBin( startxb2 = bnxcenter + bleft  ) ;
b2HiBin = SetBin( endxb2   = bnxcenter + bright ) ;
old_assgnto_new2( a1LoBin , a1HiBin , b1LoBin , b1HiBin ,
		  a2LoBin , a2HiBin , b2LoBin , b2HiBin ) ;
sub_penal( startxa1 , endxa1 , ablock , a1LoBin , a1HiBin ) ;
sub_penal( startxb1 , endxb1 , bblock , b1LoBin , b1HiBin ) ;
add_penal( startxa2 , endxa2 , bblock , a2LoBin , a2HiBin ) ;
add_penal( startxb2 , endxb2 , ablock , b2LoBin , b2HiBin ) ;
binpen_chg = newbinpenal - binpenal ;
rowpen_chg = newrowpenal - rowpenal ;
newpenal = (int)( roLenCon * (double) newrowpenal +
				binpenCon * (double) newbinpenal ) ;
error_light_is_on = 0 ;
if( newpenal - penalty > P_limit ) {
if( potential_errors < 100 ) {
	++potential_errors ;
	error_light_is_on = 1 ;
} else {
	earlyRej++ ;
	return( -1 ) ;
}
}
if( ablock != bblock ) {
term_newpos_a( atermptr , anxcenter , bycenter , aorient ) ;
term_newpos_b( btermptr , bnxcenter , aycenter , borient ) ;
} else {
term_newpos( atermptr , anxcenter , bycenter , aorient ) ;
term_newpos( btermptr , bnxcenter , aycenter , borient ) ;
}
cost = funccost ;
delta_vert_cost = 0 ;
if( ablock != bblock ) {
new_dbox_a( atermptr , &cost ) ;
new_dbox_a( btermptr , &cost ) ;
} else {
new_dbox( atermptr , &cost ) ;
new_dbox( btermptr , &cost ) ;
}
wire_chg = cost - funccost ;
truth = acceptt(funccost + penalty - cost - newpenal - delta_vert_cost);
if( truth == 1 ) {
if( error_light_is_on ) {
	error_count++ ;
}
new_assgnto_old2( a1LoBin , a1HiBin , b1LoBin , b1HiBin ,
		      a2LoBin , a2HiBin , b2LoBin , b2HiBin ) ;
if( ablock != bblock ) {
	dbox_pos_2( atermptr ) ;
	dbox_pos_2( btermptr ) ;
} else {
	dbox_pos( atermptr ) ;
	dbox_pos( btermptr ) ;
}
anbin = SetBin( anxcenter ) ;
bnbin = SetBin( bnxcenter ) ;
if( cellaptr != cellbptr ) {
	remv_cell( cellaptr , Apost ) ;
	remv_cell( cellbptr , Bpost ) ;
	add_cell( &binptr[bblock][anbin]->cell , a ) ;
	add_cell( &binptr[ablock][bnbin]->cell , b ) ;
} else {
	remv_cell( cellaptr , Apost ) ;
	for( i = 1 ; i <= *cellaptr ; i++ ) {
	    if( cellaptr[i] == b ) {
		break ;
	    }
	}
	remv_cell( cellaptr , i ) ;
	add_cell( &binptr[ablock][anbin]->cell , a ) ;
	add_cell( &binptr[ablock][bnbin]->cell , b ) ;
}
if( wire_chg < 0 ) {
	temp = (double) - wire_chg ;
	total_wire_chg += temp ;
	sigma_wire_chg += (temp - mean_wire_chg) *
					(temp - mean_wire_chg) ;
	wire_chgs++ ;
}
acellptr->cblock   = bblock    ;
acellptr->cxcenter = anxcenter ;
acellptr->cycenter = bycenter  ;
bcellptr->cblock   = ablock    ;
bcellptr->cxcenter = bnxcenter ;
bcellptr->cycenter = aycenter  ;
funccost = cost ;
binpenal = newbinpenal ;
rowpenal = newrowpenal ;
penalty  = newpenal ;
if( ablock != bblock ) {
	barray[ablock]->oldsize = barray[ablock]->newsize ;
	barray[bblock]->oldsize = barray[bblock]->newsize ;
}
return( 1 ) ;
} else {
return( 0 ) ;
}
}
int minxspan ;
double mean_width ;
int offset_limit ;
int blkleft , blkrite ;
double table1[1024] , table2[1024] , table3[1024] ;
int moveable_cells ;
int fdthrus ;
#define T 2
#define R 3
int *xfeeds_in_row ;
int est_fds ;
short int **row_map ;
short int num_calls = 0 ;
/* 当前文件是D:\Read\uloop.c*/
uloop()
{
CBOXPTR acellptr, bcellptr ;
BBOXPTR ablckptr , bblckptr ;
DBOXPTR dimptr ;
int botblk , topblk ;
int flips , rejects ;
int axcenter , bxcenter , bycenter ;
int aorient , borient ;
int bleft , bright ;
int blk , pairflips ;
int i , r , l , t ;
int abin , bbin ;
int firstTry , fds , net , cost ;
double target_row_penalty ;
double target_bin_penalty ;
double temp , accept_deviation , fp_ratio , percent_error ;
double factor , total_feed_length , target_feed_length ;
static double avg_VW ;
attempts  = 0 ;
flips     = 0 ;
rejects   = 0 ;
pairflips = 0 ;
earlyRej  = 0 ;
Rej_error = 0 ;
potential_errors = 0 ;
error_count = 0 ;
if( iteration == 0 || resume_run == 1 ) {
P_limit = (int) ( 10.0 * mean_width ) ;
} else {
if( wire_chgs > 0 ) {
	mean_wire_chg = total_wire_chg / (double) wire_chgs ;
	if( iteration > 1 ) {
	    sigma_wire_chg = sqrt( sigma_wire_chg / (double) wire_chgs);
	} else {
	    sigma_wire_chg = 3.0 * mean_wire_chg ;
	}
} else {
	mean_wire_chg  = 0.0 ;
	sigma_wire_chg = 0.0 ;
}
P_limit = mean_wire_chg + 1.3 * sigma_wire_chg +
					    T / cost_scale_factor;
}
sigma_wire_chg = 0.0 ;
total_wire_chg = 0.0 ;
wire_chgs = 0 ;
windx = minxspan ;
attmax = ((int)((double)(iteration) /
	      121.0 * (double)(2 * attprcel - attprcel / 2) ) +
	      (double)(attprcel / 2) ) * moveable_cells ;
if( tw_fast ){
attmax /= tw_fast ;
}
if( tw_slow ){
attmax *= tw_slow ;
}
fds = 0 ;
if( iteration >= 4 ) {
fds = controlf() ;
if( iteration <= 105 ) {
	total_feed_length = (double) est_fds ;
	target_feed_length = 0.7 * (double) implicit_feed_count -
		    ((0.5 * (double) implicit_feed_count  / 105.0 ) *
					((double)iteration));
	if( implicit_feed_count > 0 ) {
	    factor = (double)(total_feed_length - target_feed_length) /
				((double) implicit_feed_count) ;
	} else {
	    factor = 0.0 ;
	}
	cost = 0 ;
	for( net = 1 ; net <= numnets ; net++ ) {
	    dimptr = netarray[net] ;
	    if( dimptr->Vweight <= 1.0 ) {
		dimptr->Vweight *= 1.0 + factor ;
		if( dimptr->Vweight < 0.5 ) {
		    dimptr->Vweight = 0.5 ;
		} else if( dimptr->Vweight > 1.0 ) {
		    dimptr->Vweight = 1.0 ;
		}
	    }
	    avg_VW += dimptr->Vweight ;
	    cost += ((int)( dimptr->Hweight *
		    (double)( dimptr->xmax - dimptr->xmin))) +
		    ((int)( dimptr->Vweight *
		    (double)( dimptr->ymax - dimptr->ymin)));
	}
	avg_VW /= (double) numnets ;
	funccost = cost ;
}
} else {
avg_VW = 0.0 ;
}
while( attempts < attmax ) {
a = PICK_INT( 1 , numcells ) ;
acellptr = carray[ a ]  ;
if( acellptr->cclass == -1 ) {
	continue ;
}
ablock   = acellptr->cblock ;
ablckptr = barray[ ablock ] ;
axcenter = acellptr->cxcenter ;
aorient = acellptr->corient ;
abin = SetBin( axcenter ) ;
cellaptr = binptr[ablock][abin]->cell ;
for( i = 1 ; i <= *cellaptr ; i++ ) {
	if( cellaptr[i] == a ) {
	     Apost = i ;
	     break ;
	}
}
bblock = 0 ;
firstTry = 0 ;
if( (botblk = ablock - DELTA_B) < 1) {
	botblk = 1 ;
}
if( (topblk = ablock + DELTA_B) > numblock ) {
	 topblk = numblock ;
}
for( i = 1 ; ; i++ ) {
	do {
	    blk = XPICK_INT( botblk , topblk , firstTry ) ;
	    bblckptr = barray[ blk ] ;
	} while( ablckptr->bclass != bblckptr->bclass ) ;
	
	bleft = bblckptr->bxcenter + bblckptr->bleft ;
	bright = bblckptr->bxcenter + bblckptr->bright ;
	l = (bleft >= axcenter - windx) ? bleft : (axcenter-windx);
	r = (bright <= axcenter + windx) ? bright : (axcenter+windx);
	if( l > r ) {
	    if( i == 1 ) {
		firstTry = blk ;
		continue ;
	    } else if( i == 3 ) {
		if( r < bleft ) {
		    l = r = bleft ;
		} else {
		    l = r = bright ;
		}
	    } else {
		firstTry = - ablock ;
		continue ;
	    }
	}
	bblock = blk ;
	bycenter = bblckptr->bycenter ;
	if( bblock == ablock ) {
	    bxcenter = XPICK_INT( l, r, axcenter ) ;
	} else {
	    bxcenter = XPICK_INT( l, r, 0 ) ;
	}
	break ;
}
bbin = SetBin( bxcenter ) ;
cellbptr = binptr[bblock][bbin]->cell ;
if( *cellbptr == 0 ) {
	if( ablckptr->borient == 1 ) {
	    if( bblckptr->borient == 1 ) {
		if( ucxx1( bxcenter, bycenter)){
		    flips++ ;
		} else {
		    rejects++ ;
		    if( rejects % 6 == 0 && acellptr->orflag != 0){
			uc0( a , (aorient == 0) ? 2 : 0 );
		    }
		}
	    } else {
		if( ucxxo1( bxcenter,bycenter,(aorient == 0) ? 1 : 3 )){
		    flips++ ;
		} else {
		    rejects++ ;
		    if( rejects % 6 == 0 && acellptr->orflag != 0){
			uc0( a , (aorient == 0) ? 2 : 0 );
		    }
		}
	    }
	} else {  	
	    if( bblckptr->borient == 1 ) {
		if( ucxxo1( bxcenter, bycenter,
			    (aorient == 1) ? 0 : 2)){
		    flips++ ;
		} else {
		    rejects++ ;
		    if( rejects % 6 == 0 && acellptr->orflag != 0){
			uc0( a , (aorient == 1) ? 3 : 1 );
		    }
		}
	    } else {
		if( ucxx1( bxcenter, bycenter) ){
		    flips++ ;
		} else {
		    rejects++ ;
		    if( rejects % 6 == 0 && acellptr->orflag != 0){
			uc0( a , (aorient == 1) ? 3 : 1 );
		    }
		}
	    }
	}
} else {
	Bpost = PICK_INT( 1 , *cellbptr ) ;
	b = cellbptr[ Bpost ] ;
	bcellptr  = carray[b] ;
	bblock    = bcellptr->cblock   ;
	bblckptr = barray[ bblock ] ;
	if( acellptr->cclass != bcellptr->cclass || a == b ) {
	    continue ;
	}
	
	borient   = bcellptr->corient  ;
	if( ablckptr->borient == 1 ) {
	    if( bblckptr->borient == 1 ) {
		t = ucxx2( ) ;
		if( t == -1 ) {
		    rejects++ ;
		    if( rejects % 6 == 0 && acellptr->orflag != 0){
			uc0( a , (aorient == 0) ? 2 : 0 );
		    }
		    attempts++ ;
		    continue ;
		} else if( t == 1 ) {
		    pairflips++ ;
		} else {
		    rejects++ ;
		    if( rejects % 6 == 0 && acellptr->orflag != 0){
			uc0( a , (aorient == 0) ? 2 : 0 );
		    }
		}
	    } else {
		t = ucxxo2( (aorient == 0) ? 1:3, (borient == 1)
							 ? 0:2 ) ;
		if( t == -1 ) {
		    rejects++ ;
		    if( rejects % 6 == 0 && acellptr->orflag != 0){
			uc0( a , (aorient == 0) ? 2 : 0 );
		    }
		    attempts++ ;
		    continue ;
		} else if( t == 1 ) {
		    pairflips++ ;
		} else {
		    rejects++ ;
		    if( rejects % 6 == 0 && acellptr->orflag != 0){
			uc0( a , (aorient == 0) ? 2 : 0 );
		    }
		}
	    }
	} else {
	    if( bblckptr->borient == 1 ) {
		t = ucxxo2( (aorient == 1) ? 0:2, (borient == 0)
							    ? 1:3) ;
		if( t == -1 ) {
		    rejects++ ;
		    if( rejects % 6 == 0 && acellptr->orflag != 0){
			uc0( a , (aorient == 1) ? 3 : 1 );
		    }
		    attempts++ ;
		    continue ;
		} else if( t == 1 ) {
		    pairflips++ ;
		} else {
		    rejects++ ;
		    if( rejects % 6 == 0 && acellptr->orflag != 0){
			uc0( a , (aorient == 1) ? 3 : 1 );
		    }
		}
	    } else {
		t = ucxx2( ) ;
		if( t == -1 ) {
		    rejects++ ;
		    if( rejects % 6 == 0 && acellptr->orflag != 0){
			uc0( a , (aorient == 1) ? 3 : 1 );
		    }
		    attempts++ ;
		    continue ;
		} else if( t == 1 ) {
		    pairflips++ ;
		} else {
		    rejects++ ;
		    if( rejects % 6 == 0 && acellptr->orflag != 0){
			uc0( a , (aorient == 1) ? 3 : 1 );
		    }
		}
	    }
	}
}
attempts++ ;
}
if( potential_errors > 0 ) {
percent_error = (double) error_count / (double) potential_errors ;
} else {
percent_error = 0.0 ;
}
percent_error *= 100.0 ;
temp = 100.0 * (double)(pairflips + flips) / (double)(attmax) ;
if( pairflips > 0.0001 ) {
fp_ratio = 100.0 * (double)flips/(double)pairflips ;
} else {
fp_ratio = 100.0 ;
}
vert_statistics() ;
fprintf(fpo,"%3d %3d %4d %8d %7d %5d %4.1f %4.1f %4.1f %4.1f %4.1f",
	iteration+1, (int)T, fds , funccost, penalty, P_limit,
	percent_error,binpenCon, roLenCon, temp, fp_ratio);
fprintf(fpo," %4.1f %5d %6d\n", 100.0*(double)earlyRej/(double)attmax,
			tot_num_feeds , ABS(tot_missing_rows) );
fflush( fpo ) ;
if( iteration < 1 || resume_run == 1 ) {
if( iteration < 1 ) {
	cost_scale_factor = 1.0 ;
}
rowcon() ;
resume_run = 0 ;
} else if( iteration < 100 ) {
accept_deviation = (temp - desired_accept[iteration]) / 40.0 ;
cost_scale_factor *= 1.0 + accept_deviation ;
}
if( iteration <= 104 ) {
target_bin_penalty = (1.40 - ((1.15/105.0)*((double)iteration+1.0))) *
						(double) totalR ;
binpenCon += ((double) binpenal - target_bin_penalty) /
					    (double) totalR ;
binpenCon = (binpenCon > 0.5) ? binpenCon : 0.5 ;
target_row_penalty = (initialRowControl -
		(((initialRowControl - finalRowControl) / 105.0 ) *
			    ((double)iteration+1.0))) * (double) totalR ;
roLenCon += ((double) rowpenal - target_row_penalty) /
					    target_row_penalty ;
					
roLenCon = (roLenCon > 0.5) ? roLenCon : 0.5 ;
penalty = (int)( binpenCon * (double) binpenal +
				roLenCon * (double) rowpenal ) ;
}
return ;
}
/* 当前文件是D:\Read\dimbox.c*/


check_cost()
{
DBOXPTR  dimptr  ;
NBOXPTR  netptr  ;
TEBOXPTR termptr ;
int old_mean , oldx , net , initial_cost , total ;
initial_cost = 0 ;
for( net = 1 ; net <= numnets ; net++ ) {
dimptr = netarray[net] ;
total = 0 ;
for( netptr = dimptr->netptr ; netptr ; netptr = netptr->nterm ) {
	total += netptr->xpos ;
}
old_mean = total / dimptr->numpins ;
for( netptr = dimptr->netptr ; netptr ; netptr = netptr->nterm ) {
	oldx = netptr->xpos ;
	initial_cost += ABS( oldx - old_mean ) ;
}
}
return( initial_cost ) ;
}
initialize_cost()
{
DBOXPTR  dimptr  ;
NBOXPTR  netptr  ;
TEBOXPTR termptr ;
int old_mean , oldx , net , initial_cost ;
initial_cost = 0 ;
for( net = 1 ; net <= numnets ; net++ ) {
dimptr = netarray[net] ;
dimptr->old_total = 0 ;
for( netptr = dimptr->netptr ; netptr ; netptr = netptr->nterm ) {
	dimptr->old_total += netptr->xpos ;
}
old_mean = dimptr->old_total / dimptr->numpins ;
for( netptr = dimptr->netptr ; netptr ; netptr = netptr->nterm ) {
	oldx = netptr->xpos ;
	initial_cost += ABS( oldx - old_mean ) ;
}
}
return( initial_cost ) ;
}
new_dbox( antrmptr , costptr )
TEBOXPTR antrmptr ;
int *costptr ;
{
NBOXPTR  netptr  ;
DBOXPTR  dimptr  ;
TEBOXPTR termptr ;
int old_mean , new_mean , oldx , newx ;
for( termptr = antrmptr ; termptr ; termptr = termptr->nextterm ) {
dimptr = netarray[ termptr->net ] ;
if( dimptr->dflag == 0  ) {
	continue ;
}
dimptr->dflag = 0 ;
new_mean = dimptr->new_total / dimptr->numpins ;
old_mean = dimptr->old_total / dimptr->numpins ;
for( netptr = dimptr->netptr ; netptr ; netptr = netptr->nterm ) {
	oldx = netptr->xpos ;
	if( netptr->flag == 1 ) {
	    newx = netptr->newx ;
	    netptr->flag = 0 ;
	} else {
	    newx = oldx ;
	}
	*costptr += ABS( newx - new_mean ) - ABS( oldx - old_mean ) ;
}
}
return ;
}
new_dbox_a( antrmptr , costptr )
TEBOXPTR antrmptr ;
int *costptr ;
{
DBOXPTR  dimptr  ;
NBOXPTR  netptr  ;
TEBOXPTR termptr ;
int old_mean , new_mean , oldx , newx ;
int f , m , min , max , row , net ;
char *rowsptr ;
for( termptr = antrmptr ; termptr ; termptr = termptr->nextterm ) {
net = termptr->net ;
dimptr = netarray[ net ] ;
if( dimptr->dflag == 0  ) {
	continue ;
}
dimptr->dflag = 0 ;
new_mean = dimptr->new_total / dimptr->numpins ;
old_mean = dimptr->old_total / dimptr->numpins ;
for( netptr = dimptr->netptr ; netptr ; netptr = netptr->nterm ) {
	oldx = netptr->xpos ;
	if( netptr->flag == 1 ) {
	    newx = netptr->newx ;
	    netptr->flag = 0 ;
	} else {
	    newx = oldx ;
	}
	*costptr += ABS( newx - new_mean ) - ABS( oldx - old_mean ) ;
}
f = 0 ;
m = 0 ;
rowsptr = tmp_rows[net] ;
for( row = 0 ; rowsptr[row] == 0 ; row++ ) ;
min = row ;
for( row = numRows+1; rowsptr[row] == 0;row--);
max = row ;
for( row = min ; row <= max ; row++ ) {
	if( rowsptr[row] == 0 ) {
	    f++ ;
	} else {
	    m++ ;
	}
}
tmp_num_feeds[net] = f ;
if( min < max ) {
	m += 2 ;
} else if( min == max ) {
	m += 1 ;
} else {
	m = 0 ;
}
tmp_missing_rows[net] = -m ;
delta_vert_cost += ((tmp_num_feeds[net] - num_feeds[net]) +
		   (tmp_missing_rows[net] - missing_rows[net])) *
		   2 * rowHeight ;
}
return ;
}
term_newpos( antrmptr , xcenter , ycenter , newaor )
TEBOXPTR antrmptr ;
int xcenter , ycenter , newaor ;
{
TEBOXPTR termptr ;
NBOXPTR ttermptr ;
DBOXPTR dimptr ;
for( termptr = antrmptr ; termptr ; termptr = termptr->nextterm ) {
ttermptr = termptr->termptr ;
ttermptr->flag = 1 ;
ttermptr->newx = termptr->txpos[ newaor/2 ] + xcenter ;
dimptr = netarray[ termptr->net ] ;
if( dimptr->dflag == 0 ) {
	dimptr->dflag = 1 ;
	dimptr->new_total = dimptr->old_total +
				ttermptr->newx - ttermptr->xpos ;
} else {
	dimptr->new_total += ttermptr->newx - ttermptr->xpos ;
}
}
return ;
}
term_newpos_a( antrmptr , xcenter , ycenter , newaor )
TEBOXPTR antrmptr ;
int xcenter , ycenter , newaor ;
{
TEBOXPTR termptr ;
NBOXPTR ttermptr ;
DBOXPTR dimptr ;
char *rowsptr1 , *rowsptr2 ;
int net , row ;
for( termptr = antrmptr ; termptr ; termptr = termptr->nextterm ) {
ttermptr = termptr->termptr ;
ttermptr->flag = 1 ;
ttermptr->newx = termptr->txpos[ newaor/2 ] + xcenter ;
net = termptr->net ;
dimptr = netarray[ net ] ;
rowsptr2 = tmp_rows[net] ;
if( dimptr->dflag == 0 ) {
	dimptr->dflag = 1 ;
	rowsptr1 = rows[net] ;
	for( row = 0 ; row <= numRows + 1 ; row++ ) {
	    rowsptr2[row] = rowsptr1[row] ;
	}
	rowsptr2[ablock]-- ;
	rowsptr2[bblock]++ ;
	dimptr->new_total = dimptr->old_total +
				ttermptr->newx - ttermptr->xpos ;
} else {
	rowsptr2[ablock]-- ;
	rowsptr2[bblock]++ ;
	dimptr->new_total += ttermptr->newx - ttermptr->xpos ;
}
}
return ;
}
term_newpos_b( antrmptr , xcenter , ycenter , newaor )
TEBOXPTR antrmptr ;
int xcenter , ycenter , newaor ;
{
TEBOXPTR termptr ;
NBOXPTR ttermptr ;
DBOXPTR dimptr ;
char *rowsptr1 , *rowsptr2 ;
int net , row ;
for( termptr = antrmptr ; termptr ; termptr = termptr->nextterm ) {
ttermptr = termptr->termptr ;
ttermptr->flag = 1 ;
ttermptr->newx = termptr->txpos[ newaor/2 ] + xcenter ;
net = termptr->net ;
dimptr = netarray[ net ] ;
rowsptr2 = tmp_rows[net] ;
if( dimptr->dflag == 0 ) {
	dimptr->dflag = 1 ;
	rowsptr1 = rows[net] ;
	for( row = 0 ; row <= numRows + 1 ; row++ ) {
	    rowsptr2[row] = rowsptr1[row] ;
	}
	rowsptr2[bblock]-- ;
	rowsptr2[ablock]++ ;
	dimptr->new_total = dimptr->old_total +
				ttermptr->newx - ttermptr->xpos ;
} else {
	rowsptr2[bblock]-- ;
	rowsptr2[ablock]++ ;
	dimptr->new_total += ttermptr->newx - ttermptr->xpos ;
}
}
return ;
}
dbox_pos( antrmptr )
TEBOXPTR antrmptr ;
{
DBOXPTR dimptr ;
TEBOXPTR termptr ;
for( termptr = antrmptr ; termptr ; termptr = termptr->nextterm ) {
dimptr = netarray[ termptr->net ] ;
dimptr->old_total = dimptr->new_total ;
termptr->termptr->xpos = termptr->termptr->newx ;
}
return ;
}
dbox_pos_2( antrmptr )
TEBOXPTR antrmptr ;
{
NBOXPTR netptr ;
DBOXPTR dimptr ;
TEBOXPTR termptr ;
int x , net , row ;
register char *rowsptr1 , *rowsptr2 ;
for( termptr = antrmptr ; termptr ; termptr = termptr->nextterm ) {
net = termptr->net ;
dimptr = netarray[ net ] ;
dimptr->old_total = dimptr->new_total ;
termptr->termptr->xpos = termptr->termptr->newx ;
missing_rows[net] = tmp_missing_rows[net] ;
num_feeds[net] = tmp_num_feeds[net] ;
rowsptr1 = rows[net] ;
rowsptr2 = tmp_rows[net] ;
for( row = 0 ; row <= numRows + 1 ; row++ ) {
	rowsptr1[row] = rowsptr2[row] ;
}
}
return ;
}
initialize_rows()
{
TEBOXPTR termptr ;
int net , row , cell , min , max , f , m ;
char *rowsptr ;
num_feeds = (int *) safe_malloc( (1 + numnets) * sizeof(int) ) ;
tmp_num_feeds = (int *) safe_malloc( (1 + numnets) * sizeof(int) ) ;
missing_rows = (int *) safe_malloc( (1 + numnets) * sizeof(int) ) ;
tmp_missing_rows = (int *) safe_malloc( (1 + numnets) * sizeof(int) ) ;
rows = (char **) safe_malloc( (1 + numnets) * sizeof(char *) ) ;
tmp_rows = (char **) safe_malloc( (1 + numnets) * sizeof(char *) ) ;
for( net = 1 ; net <= numnets ; net++ ) {
rows[net] = (char *) safe_malloc( (2 + numRows) * sizeof(char) ) ;
tmp_rows[net] = (char *) safe_malloc( (2 + numRows) * sizeof(char));
for( row = 0 ; row <= numRows + 1 ; row++ ) {
	rows[net][row] = 0 ;
	tmp_rows[net][row] = 0 ;
}
missing_rows[net] = 0 ;
tmp_missing_rows[net] = 0 ;
num_feeds[net] = 0 ;
tmp_num_feeds[net] = 0 ;
}
for( cell = 1 ; cell <= numcells + numterms ; cell++ ) {
if( cell > numcells ) {
	if( carray[cell]->padside != T &&
				carray[cell]->padside != B &&
				carray[cell]->padside != MTT &&
				carray[cell]->padside != MBB ) {
	    continue ;
	} else if( carray[cell]->padside == T ||
				carray[cell]->padside == MTT ) {
	    carray[cell]->cblock = row = numRows + 1 ;
	} else {
	    carray[cell]->cblock = row = 0 ;
	}
} else {
	row = carray[cell]->cblock ;
}
for( termptr = carray[cell]->tileptr->termsptr ;
		termptr != TERMNULL ; termptr = termptr->nextterm ) {
	rows[ termptr->net ][ row ]++ ;
}
}
for( net = 1 ; net <= numnets ; net++ ) {
f = 0 ;
m = 0 ;
rowsptr = rows[net] ;
for( row = 0 ; rowsptr[row] == 0 ; row++ ) ;
min = row ;
for( row = numRows + 1 ; rowsptr[row] == 0 ; row-- ) ;
max = row ;
for( row = min ; row <= max ; row++ ) {
	if( rowsptr[row] == 0 ) {
	    f++ ;
	} else {
	    m++ ;
	}
}
num_feeds[net] = f ;
if( min < max ) {
	m += 2 ;
} else if( min == max ) {
	m += 1 ;
} else {
	m = 0 ;
}
missing_rows[net] = -m ;
}
return ;
}
check_row_values()
{
TEBOXPTR termptr ;
int net , row , cell , min , max , f , m , fds, mrs ;
char *rowsptr , **check_rows ;
int *check_feeds ;
check_feeds = (int *) safe_malloc( (1 + numnets) * sizeof(int) ) ;
check_rows = (char **) safe_malloc( (1 + numnets) * sizeof(char *) ) ;
for( net = 1 ; net <= numnets ; net++ ) {
check_rows[net] = (char *) safe_malloc((2+numRows) * sizeof(char));
for( row = 0 ; row <= numRows + 1 ; row++ ) {
	check_rows[net][row] = 0 ;
}
check_feeds[net] = 0 ;
}
for( cell = 1 ; cell <= numcells + numterms ; cell++ ) {
if( cell > numcells ) {
	if( carray[cell]->padside != T &&
				carray[cell]->padside != B &&
				carray[cell]->padside != MTT &&
				carray[cell]->padside != MBB ) {
	    continue ;
	} else if( carray[cell]->padside == T ||
				carray[cell]->padside == MTT ) {
	    carray[cell]->cblock = row = numRows + 1 ;
	} else {
	    carray[cell]->cblock = row = 0 ;
	}
} else {
	row = carray[cell]->cblock ;
}
for( termptr = carray[cell]->tileptr->termsptr ;
		termptr != TERMNULL ; termptr = termptr->nextterm ) {
	check_rows[ termptr->net ][ row ]++ ;
}
}
fds = 0 ;
mrs = 0 ;
for( net = 1 ; net <= numnets ; net++ ) {
f = 0 ;
m = 0 ;
rowsptr = check_rows[net] ;
for( row = 0 ; rowsptr[row] == 0 ; row++ ) ;
min = row ;
for( row = numRows + 1 ; rowsptr[row] == 0 ; row-- ) ;
max = row ;
for( row = min ; row <= max ; row++ ) {
	if( rowsptr[row] == 0 ) {
	    f++ ;
	} else {
	    m++ ;
	}
}
fds += f ;
if( min < max ) {
	m += 2 ;
} else if( min == max ) {
	m += 1 ;
} else {
	m = 0 ;
}
mrs -= m ;
}
safe_free( check_feeds ) ;
for( net = 1 ; net <= numnets ; net++ ) {
safe_free( check_rows[net] ) ;
}
safe_free( check_rows ) ;
fprintf(fpo,"FEEDS:%d     MRs:%d\n", fds , mrs ) ;
printf("FEEDS:%d     MRs:%d\n", fds , mrs ) ;
fflush(stdout);
fflush(fpo) ;
return ;
}
vert_statistics()
{
int net ;
tot_missing_rows = 0 ;
tot_num_feeds = 0 ;
for( net = 1 ; net <= numnets ; net++ ) {
tot_missing_rows += missing_rows[net] ;
tot_num_feeds += num_feeds[net] ;
}
return ;
}





/* 当前文件是D:\Read\main.h*/

/* 当前文件是D:\Read\acceptt.c*/

#define RAND (Yacm_random() )
#define MASK 0x3ff



int acceptt( delta_cost )
int delta_cost ;
{
int truth ;
double fred ;
register unsigned fract ;
fred =  ((double) delta_cost * cost_scale_factor ) / T ;
if( fred >= 0.0 ) {
truth = 1 ;
} else if( fred < -80.0 ) {
truth = 0 ;
} else if( fred > -0.0001 ) {
if( 1.0 + fred > ( (double) RAND / (double)0x7fffffff ) ) {
	truth = 1 ;
} else {
	truth = 0 ;
}
} else {
fract = (int)( -fred * 8388608.0 ) ;
if( (table1[ (fract >> 20) & MASK ] *
		    table2[ (fract >> 10) & MASK] *
		    table3[ fract & MASK ]) >
		    ( (double) RAND / (double)0x7fffffff ) ) {
	truth = 1 ;
} else {
	truth = 0 ;
}
}
return(truth) ;
}
int *act_feeds_in_row ;
int pad_line ;
int last_feed ;

int impcount ;
#define R 3
int *feed_location ;
typedef struct ipbox {
struct ipbox *npin ;
int ixpos ;
int iypos ;
int layer ;
char *ipname ;
} IPBOX , *IPBOXPTR ;
typedef struct ibox {
struct ibox *niptr ;
int iactive ;
int aveXpos ;
int icell ;
IPBOXPTR iptr ;
} IBOX , *IBOXPTR ;
#define INULL  (IBOXPTR) NULL
#define IPNULL (IPBOXPTR) NULL
IBOXPTR siptr ;
IBOXPTR *impFeeds  ;

int *top_row_for_this_net ;
int *bot_row_for_this_net ;


char **pinnames ;
/* 当前文件是D:\Read\addimp.c*/


addimp( row, net )
int row , net ;
{
CBOXPTR ptr ;
TEBOXPTR termptr ;
IPBOXPTR ipptr , tipptr , bipptr ;
NBOXPTR nptr , n1ptr , n2ptr ;
int pin , orient , realcell ;
realcell = siptr->icell ;
ptr = carray[ realcell ] ;
ptr->numterms += 2 ;
for( ipptr = siptr->iptr ; ; ipptr = ipptr->npin ) {
if( ipptr->iypos > 0 ) {
	break ;
}
}
tipptr = ipptr ;
for( ipptr = siptr->iptr ; ; ipptr = ipptr->npin ) {
if( ipptr->iypos < 0 ) {
	break ;
}
}
bipptr = ipptr ;
termptr = ptr->tileptr->termsptr ;
if( termptr != TERMNULL ) {
while( termptr->nextterm != TERMNULL ) {
	termptr = termptr->nextterm ;
}
termptr = termptr->nextterm = (TEBOXPTR) safe_malloc(sizeof(TEBOX));
} else {
termptr = ptr->tileptr->termsptr =(TEBOXPTR)
					safe_malloc(sizeof(TEBOX));
}
termptr->cellterm = ++maxterm ;
pinnames[maxterm] = (char *) safe_malloc( (strlen(tipptr->ipname) + 1) *
						sizeof( char ) ) ;
sprintf( pinnames[maxterm] , "%s" , tipptr->ipname ) ;
termptr->ei = maxterm ;
termptr->ue = 0 ;
tearray[maxterm] = ( NBOXPTR )safe_malloc( sizeof( NBOX ) ) ;
termptr->nextterm = (TEBOXPTR) safe_malloc(sizeof(TEBOX));
termptr->nextterm->nextterm = TERMNULL  ;
termptr->nextterm->ei = maxterm ;
termptr->nextterm->ue = 0 ;
termptr->nextterm->cellterm = ++maxterm ;
pinnames[maxterm] = (char *) safe_malloc( (strlen(bipptr->ipname) + 1) *
						sizeof( char ) ) ;
sprintf( pinnames[maxterm] , "%s" , bipptr->ipname ) ;
tearray[maxterm] = ( NBOXPTR )safe_malloc( sizeof( NBOX ) ) ;
termptr->txpos[0] = tipptr->ixpos ;
termptr->typos[0] = tipptr->iypos ;
termptr->txpos[1] = -termptr->txpos[0] ;
termptr->typos[1] = -termptr->typos[0] ;
if( ptr->clength % 2 != 0 ) {
termptr->txpos[1]++  ;
}
if( ptr->cheight % 2 != 0 ) {
termptr->typos[1]++ ;
}
pin = termptr->cellterm ;
nptr = netarray[net]->netptr ;
for( ; nptr->nterm != NETNULL ; nptr = nptr->nterm ) ;
nptr = nptr->nterm = (NBOXPTR) safe_malloc( sizeof(NBOX) ) ;
tearray[pin] = nptr ;
nptr->terminal = pin  ;
nptr->flag     = 0    ;
nptr->row      = row  ;
nptr->cell     = realcell ;
nptr->net      = net ;
nptr->extint   = termptr->ei ;
nptr->unequiv  = termptr->ue ;
nptr->layer    = tipptr->layer ;
n1ptr = nptr ;
termptr = termptr->nextterm ;
termptr->txpos[0] =  bipptr->ixpos ;
termptr->typos[0] =  bipptr->iypos ;
termptr->txpos[1] = -termptr->txpos[0] ;
termptr->typos[1] = -termptr->typos[0] ;
if( ptr->clength % 2 != 0 ) {
termptr->txpos[1]++  ;
}
if( ptr->cheight % 2 != 0 ) {
termptr->typos[1]++ ;
}
pin = termptr->cellterm ;
nptr = nptr->nterm = (NBOXPTR) safe_malloc( sizeof(NBOX) ) ;
tearray[pin] = nptr ;
nptr->nterm = NETNULL ;
nptr->terminal = pin  ;
nptr->flag     = 0    ;
nptr->row      = row  ;
nptr->cell     = realcell ;
nptr->net      = net ;
nptr->extint   = termptr->ei ;
nptr->unequiv  = termptr->ue ;
nptr->layer    = bipptr->layer ;
n2ptr = nptr ;
orient = ptr->corient ;
if( orient == 0 || orient == 2 ) {
n1ptr->pinloc = 1 ;
n2ptr->pinloc = -1 ;
} else {
n1ptr->pinloc = -1 ;
n2ptr->pinloc = 1 ;
}
return ;
}
/* 当前文件是D:\Read\alignfeed.c*/



alignfeed()
{
int row , last_up , last_dn , up , dn , cell_up , cell_dn ;
int net_up , net_dn , x_up , distance ;
distance = 0 ;
for( row = numRows - 1 ; row >= 1 ; row-- ) {
last_up = pairArray[row+1][0] ;
last_dn = pairArray[row][0] ;
for( up = 1 ; up <= last_up ; up++ ) {
	cell_up = pairArray[row+1][up] ;
	if( cell_up >= numcells - fdthrus + 1 ) {
	    if( carray[cell_up]->tileptr->termsptr == TERMNULL ) {
		continue ;
	    }
	    net_up = tearray[ carray[cell_up]->tileptr->
					termsptr->cellterm ]->net ;
	    x_up   = carray[cell_up]->cxcenter ;
	    for( dn = 1 ; dn <= last_dn ; dn++ ) {
		cell_dn = pairArray[row][dn] ;
		if( cell_dn >= numcells - fdthrus + 1 ) {
		    if( carray[cell_dn]->tileptr->termsptr ==
							TERMNULL ) {
			continue ;
		    }
		    net_dn = tearray[ carray[cell_dn]->tileptr->
					termsptr->cellterm ]->net;
		    if( net_dn != net_up ) {
			continue ;
		    }
		    distance += re_place( pairArray[row] ,
					    cell_dn , dn , x_up ) ;
		    break ;
		}
	    }
	}
}
}
return( distance ) ;
}
re_place( rowptr , cell , index , x_location )
int *rowptr , cell , index , x_location ;
{
int i , j , last , prev_x ;
last = rowptr[0] ;
if( carray[ rowptr[1] ]->cxcenter >= x_location ) {
i = 0 ;
} else if( carray[ rowptr[last] ]->cxcenter <= x_location ) {
i = last ;
} else {
for( i = 1 ; i < last ; i++ ) {
	if( carray[ rowptr[i] ]->cxcenter <= x_location &&
		    carray[ rowptr[i+1] ]->cxcenter >= x_location ) {
	    break ;
	}
}
}
prev_x = carray[cell]->cxcenter ;
if( index > i + 1 ) {
for( j = index - 1 ; j >= i + 1 ; j-- ) {
	carray[ rowptr[j] ]->cxcenter += fdWidth ;
	rowptr[j+1] = rowptr[j] ;
}
rowptr[i+1] = cell ;
carray[cell]->cxcenter = carray[ rowptr[i+2] ]->cxcenter +
	carray[ rowptr[i+2] ]->tileptr->left - (fdWidth - fdWidth / 2);
} else if( index < i ) {
for( j = index + 1 ; j <= i ; j++ ) {
	carray[ rowptr[j] ]->cxcenter -= fdWidth ;
	rowptr[j-1] = rowptr[j] ;
}
rowptr[i] = cell ;
carray[cell]->cxcenter = carray[ rowptr[i-1] ]->cxcenter +
	carray[ rowptr[i-1] ]->tileptr->right + fdWidth / 2 ;
}
return( ABS( carray[cell]->cxcenter - prev_x) ) ;
}
align_init()
{
int row , i , cell , *rowptr , j , last , width ;
for( row = 1 ; row <= numRows ; row++ ) {
last = pairArray[row][0] ;
for( i = 1 ; i <= last ; i++ ) {
	cell = pairArray[row][i] ;
	if( cell < numcells - fdthrus + 1 ) {
	    break ;
	}
}
if( i > 1 && i <= last ) {
	rowptr = pairArray[row] ;
	width = carray[cell]->tileptr->right -
				    carray[cell]->tileptr->left ;
	for( j = i - 1 ; j >= 1 ; j-- ) {
	    carray[ rowptr[j] ]->cxcenter += width ;
	    rowptr[j+1] = rowptr[j] ;
	}
	rowptr[1] = cell ;
	carray[cell]->cxcenter = carray[ rowptr[2] ]->cxcenter +
	    carray[ rowptr[2] ]->tileptr->left - (width - width / 2) ;
}
for( i = last ; i >= 1 ; i-- ) {
	cell = pairArray[row][i] ;
	if( cell < numcells - fdthrus + 1 ) {
	    break ;
	}
}
if( i < last && i >= 1 ) {
	rowptr = pairArray[row] ;
	width = carray[cell]->tileptr->right -
				    carray[cell]->tileptr->left ;
	for( j = i + 1 ; j <= last ; j++ ) {
	    carray[ rowptr[j] ]->cxcenter -= width ;
	    rowptr[j-1] = rowptr[j] ;
	}
	rowptr[last] = cell ;
	carray[cell]->cxcenter = carray[ rowptr[last-1] ]->cxcenter +
	    carray[ rowptr[last-1] ]->tileptr->right + width / 2 ;
}
}
return ;
}
/* 当前文件是D:\Read\buildimp.c*/


IPBOXPTR xipptr ;


buildimp( icell, xrel , yrel , pname , flag , layer )
int icell , xrel , yrel , flag , layer ;
char pname[] ;
{
CBOXPTR ptr ;
IBOXPTR iptr ;
int row ;
if( flag == 1 ) {
ptr = carray[ icell ] ;
row = blkToRow[ ptr->cblock ] ;
iptr = impFeeds[row] ;
if( iptr != (IBOXPTR) NULL ) {
	while( iptr->niptr != (IBOXPTR) NULL ) {
	    iptr = iptr->niptr ;
	}
	iptr->niptr = (IBOXPTR) safe_malloc( sizeof( IBOX ) ) ;
	iptr = iptr->niptr ;
} else {
	impFeeds[row] = (IBOXPTR) safe_malloc( sizeof( IBOX ) ) ;
	iptr = impFeeds[row] ;
}
iptr->icell = icell ;
iptr->iactive = 0 ;
iptr->aveXpos = ptr->cxcenter + xrel ;
iptr->niptr = (IBOXPTR) NULL ;
iptr->iptr = (IPBOXPTR) safe_malloc( sizeof( IPBOX ) ) ;
xipptr = iptr->iptr ;
xipptr->ixpos = xrel ;
xipptr->iypos = yrel ;
xipptr->layer = layer ;
xipptr->ipname = (char *)safe_malloc((strlen(pname) + 1) * sizeof(char));
sprintf( xipptr->ipname , "%s" , pname ) ;
xipptr->npin = (IPBOXPTR) NULL ;
} else {
xipptr->npin = (IPBOXPTR) safe_malloc( sizeof( IPBOX ) ) ;
xipptr = xipptr->npin ;
xipptr->ixpos = xrel ;
xipptr->iypos = yrel ;
xipptr->layer = layer ;
xipptr->ipname = (char *)safe_malloc((strlen(pname) + 1) * sizeof(char));
sprintf( xipptr->ipname , "%s" , pname ) ;
xipptr->npin = (IPBOXPTR) NULL ;
}
return ;
}
build_feed_imp( feed , x , row )
int feed , x , row ;
{
IBOXPTR iptr ;
char pname[128] ;
iptr = impFeeds[row] ;
if( iptr != (IBOXPTR) NULL ) {
while( iptr->niptr != (IBOXPTR) NULL ) {
	iptr = iptr->niptr ;
}
iptr->niptr = (IBOXPTR) safe_malloc( sizeof( IBOX ) ) ;
iptr = iptr->niptr ;
} else {
impFeeds[row] = (IBOXPTR) safe_malloc( sizeof( IBOX ) ) ;
iptr = impFeeds[row] ;
}
iptr->icell = numcells + feed ;
iptr->iactive = -1 ;
iptr->aveXpos = x - fdWidth / 2 ;
iptr->niptr = (IBOXPTR) NULL ;
iptr->iptr = (IPBOXPTR) safe_malloc( sizeof( IPBOX ) ) ;
xipptr = iptr->iptr ;
xipptr->ixpos = - fdWidth / 2 ;
xipptr->iypos = barray[1]->bheight - barray[1]->bheight / 2 ;
xipptr->layer = 0 ;
sprintf( pname , "%s.%d" , "twfeed" , feed ) ;
xipptr->ipname = (char *)safe_malloc((strlen(pname) + 1) * sizeof(char));
sprintf( xipptr->ipname , "%s" , pname ) ;
xipptr = xipptr->npin = (IPBOXPTR) safe_malloc( sizeof( IPBOX ) ) ;
xipptr->ixpos = - fdWidth / 2 ;
xipptr->iypos = - barray[1]->bheight / 2 ;
xipptr->layer = 0 ;
xipptr->ipname = (char *)safe_malloc((strlen(pname) + 1) * sizeof(char));
sprintf( xipptr->ipname , "%s" , pname ) ;
xipptr->npin = (IPBOXPTR) NULL ;
return ;
}
/* 当前文件是D:\Read\changrid.c*/
#define TW_OK 0
#define TW_FAIL 1
#define RAND (Yacm_random() )
#define TOP 1
#define BOT 0
#define YES 1
#define NO 0
#define ABORT 1
#define NOABORT 0
#define twopen(a,b,c) (openFile(a,b,c))
#define twclose(a)    (fclose(a))

#define DENSENULL ((DENSITYPTR)NULL)
#define GRDNULL ( ( CHANGRDPTR )NULL )
int attlimit ;
SWITCHBOX  *aNetSeg ;
CHANGRDPTR *Begin , *End ;
TGRIDPTR *Tgrid ;
DENSITYPTR **Densebox , **DboxHead ;
int *anet , *netchgs , *fixnetseg ;
int numChans , numSegs , numSwSegs , tracks ;
int *maxTrack , *nmaxTrack , max_tdensity ;

#define T   2
#define R   3
#define GOING_UP 1
#define GOING_DN -1
#define GOING_UP_OR_DN 0
#define SAME_ROW 0
#define UP_ROW 1
#define DN_ROW -1
#define TOP_SIDE 1
#define BOT_SIDE -1
#define BOTH_SIDES 0
#define UNEQUIV_SIDES 2
#define SUCCESS 1
#define FAILURE 0
int **pseudoPins ;
int **pseudoEdge ;


csGroup *groupArray ;
int MPG ;
int ME  ;
edgeBox *edgeArray ;
chkBox *checkArray ;
int *key_queue ;
int numEdges, numGroups , numPins ;
int gxstart , gxstop , top_row ;
/* 当前文件是D:\Read\groute.h*/


#define GRDNULL ( ( CHANGRDPTR ) NULL )
#define DENSENULL ( ( DENSITYPTR ) NULL )

changrid( )
{
CHANGRDPTR **gdptr , grdptr , cgdptr , ngdptr ;
NBOXPTR netptr ;
int row , net , channel , terminal ;
int *numPins , *PinInChan ;
int count , i ;
numPins   = (int *)safe_calloc( sizeof( int ) , numChans+1 ) ;
PinInChan = (int *)safe_calloc( sizeof( int ) , numChans+1 ) ;
for( net = 1 ; net <= numnets ; net++ ) {
for( netptr = netarray[net]->netptr ; netptr != NETNULL ;
					netptr = netptr->nterm ) {
	if( (int) netptr->pinloc == -1 ) {
	    numPins[ netptr->row ]++ ;
	} else if( netptr->pinloc == 1 ) {
	    numPins[ netptr->row + 1 ]++ ;
	} else {
	    if( netptr->row > 0 ) {
		numPins[ netptr->row ]++ ;
	    }
	    if( netptr->row < numChans ) {
		numPins[ netptr->row + 1 ]++ ;
	    }
	}
}
}
gdptr = (CHANGRDPTR **)safe_malloc( (numChans+1) *
				sizeof( CHANGRDPTR *) ) ;
for( channel = 1 ; channel <= numChans ; channel++ ) {
gdptr[channel] = ( CHANGRDPTR * )safe_malloc(
	( numPins[channel] + 1 ) * sizeof( CHANGRDPTR ) ) ;
}
Tgrid = ( TGRIDPTR * )safe_malloc( ( maxterm + 2*numChans + 1 )
					* sizeof( TGRIDPTR ) ) ;
for( terminal = 1 ; terminal <= maxterm + 2*numChans ; terminal++ ) {
Tgrid[ terminal ] = ( TGRIDPTR )safe_malloc( sizeof(TGRIDBOX) ) ;
}
for( net = 1 ; net <= numnets ; net++ ) {
for( netptr = netarray[net]->netptr ; netptr != NETNULL ;
					netptr = netptr->nterm ) {
	row = netptr->row ;
	terminal = netptr->terminal ;
	grdptr = ( CHANGRDPTR )safe_malloc( sizeof( CHANGRDBOX ) ) ;
	if( (int) netptr->pinloc == -1 ) {
	    channel = row ;
	    count = ++(PinInChan[ channel ]) ;
	    gdptr[ channel ][ count ] = grdptr ;
	    Tgrid[ terminal ]->up = grdptr ;
	    Tgrid[ terminal ]->down = grdptr ;
	    grdptr->netptr  = tearray[ terminal ] ;
	    grdptr->tracks  = 0 ;
	    grdptr->SegType = 0 ;
	} else if( netptr->pinloc == 1 ) {
	    channel = row + 1 ;
	    count = ++(PinInChan[ channel ]) ;
	    gdptr[ channel ][ count ] = grdptr ;
	    Tgrid[ terminal ]->up = grdptr ;
	    Tgrid[ terminal ]->down = grdptr ;
	    grdptr->netptr  = tearray[ terminal ] ;
	    grdptr->tracks  = 0 ;
	    grdptr->SegType = 0 ;
	} else {
	    if( 1 <= row && row <= numChans - 1 ) {
		channel = row ;
		count = ++(PinInChan[ channel ]) ;
		gdptr[ channel ][ count ] = grdptr ;
		Tgrid[ terminal ]->down   = grdptr ;
		grdptr->netptr  = tearray[ terminal ] ;
		grdptr->tracks  = 0 ;
		grdptr->SegType = 0 ;
		channel = row + 1 ;
		count = ++(PinInChan[ channel ]) ;
		grdptr = gdptr[ channel ][ count ] =
		 ( CHANGRDPTR )safe_malloc( sizeof( CHANGRDBOX ) ) ;
		Tgrid[ terminal ]->up = grdptr ;
		grdptr->netptr  = tearray[ terminal ] ;
		grdptr->tracks  = 0 ;
		grdptr->SegType = 0 ;
	    } else if( row == 0 ) {
		count = ++(PinInChan[ 1 ]) ;
		gdptr[ 1 ][ count ] = grdptr ;
		Tgrid[ terminal ]->up   = grdptr ;
		Tgrid[ terminal ]->down = grdptr ;
		grdptr->netptr  = tearray[ terminal ] ;
		grdptr->tracks  = 0 ;
		grdptr->SegType = 0 ;
	    } else {
		count = ++(PinInChan[ numChans ]) ;
		gdptr[ numChans ][ count ] = grdptr ;
		Tgrid[ terminal ]->up   = grdptr ;
		Tgrid[ terminal ]->down = grdptr ;
		grdptr->netptr  = tearray[ terminal ] ;
		grdptr->tracks  = 0 ;
		grdptr->SegType = 0 ;
	    }
	}
}
}
for( channel = 1 ; channel <= numChans ; channel++ ) {
qsortgdx( (char *) ( gdptr[channel] + 1 ) , numPins[channel] ,
					    sizeof( CHANGRDPTR ) ) ;
}
Begin = ( CHANGRDPTR * )safe_malloc( (numChans+1)
				* sizeof( CHANGRDPTR ) ) ;
End   = ( CHANGRDPTR * )safe_malloc( (numChans+1)
				* sizeof( CHANGRDPTR ) ) ;
for( channel = 1 ; channel <= numChans ; channel++ ) {
Begin[channel] = ( CHANGRDPTR )safe_calloc( sizeof(CHANGRDBOX) ,1 );
Begin[channel]->netptr = ( NBOXPTR )safe_calloc( sizeof(NBOX) , 1);
Begin[channel]->netptr->xpos = gxstart - 1 ;
Begin[channel]->netptr->terminal = maxterm + channel ;
Begin[channel]->netptr->row = channel ;
Begin[channel]->netptr->pinloc = -1 ;
tearray[maxterm + channel] = Begin[channel]->netptr ;
End[channel] = ( CHANGRDPTR )safe_calloc( sizeof(CHANGRDBOX) , 1 ) ;
End[channel]->netptr = ( NBOXPTR )safe_calloc( sizeof(NBOX) , 1);
End[channel]->netptr->xpos = gxstop + 1 ;
End[channel]->netptr->terminal = maxterm + numChans + channel ;
End[channel]->netptr->row = channel ;
End[channel]->netptr->pinloc = -1 ;
tearray[maxterm + numChans + channel] = End[channel]->netptr ;
}
for( channel = 1 ; channel <= numChans ; channel++ ) {
Tgrid[ maxterm + channel ]->up   = Begin[ channel ] ;
Tgrid[ maxterm + channel ]->down = Begin[ channel ] ;
Tgrid[ maxterm + numChans + channel ]->up   = End[ channel ] ;
Tgrid[ maxterm + numChans + channel ]->down = End[ channel ] ;
}
for( channel = 1 ; channel <= numChans ; channel++ ) {
if( numPins[channel] == 0 ) {
	Begin[channel]->nextgrd = NULL ;
	End[channel]->prevgrd   = NULL ;
} else if( numPins[channel] == 1 ) {
	Begin[channel]->nextgrd = gdptr[channel][1] ;
	gdptr[channel][1]->prevgrd  = Begin[channel] ;
	End[channel]->prevgrd   = gdptr[channel][1] ;
	gdptr[channel][1]->nextgrd  = End[channel] ;
} else {
	Begin[channel]->nextgrd     = gdptr[channel][1] ;
	gdptr[channel][1]->prevgrd  = Begin[channel] ;
	for( i = 1 ; i <= numPins[channel]-1 ; i++ ) {
	    cgdptr = gdptr[channel][i]   ;
	    ngdptr = gdptr[channel][i+1] ;
	    cgdptr->nextgrd   = ngdptr ;
	    ngdptr->prevgrd   = cgdptr ;
	}
	ngdptr->nextgrd  = End[channel] ;
	End[channel]->prevgrd  = ngdptr ;
}
}
for( channel = 1 ; channel <= numChans ; channel++ ) {
safe_free( gdptr[ channel ] ) ;
}
safe_free( gdptr ) ;
safe_cfree( numPins ) ;
safe_cfree( PinInChan ) ;
}
/* 当前文件是D:\Read\clean.c*/

/* 当前文件是D:\Read\ucxxglb.h*/

#define MASK 0x3ff
#define remv_cell( cellptr , post ) (\
( *cellptr != post ) ? (cellptr[ post ] = cellptr[ *cellptr ],\
(*cellptr)-- ) : (*cellptr)-- )

new_old( c )
int c ;
{
int old , new ;
if( ablock != bblock ) {
barray[ablock]->newsize = barray[ablock]->oldsize + c ;
barray[bblock]->newsize = barray[bblock]->oldsize - c ;
old  = ABS(barray[ablock]->oldsize - barray[ablock]->desire) +
	   ABS(barray[bblock]->oldsize - barray[bblock]->desire) ;
new  = ABS(barray[ablock]->newsize - barray[ablock]->desire) +
	   ABS(barray[bblock]->newsize - barray[bblock]->desire) ;
newrowpenal += (new - old) ;
}
}
old_assgnto_new1( alobin , ahibin , anewlobin , anewhibin )
int alobin , ahibin , anewlobin , anewhibin ;
{
int bin , lobin , hibin ;
if( ablock == bblock ) {
lobin = ( alobin <= anewlobin ) ? alobin : anewlobin ;
hibin = ( ahibin >= anewhibin ) ? ahibin : anewhibin ;
for( bin = lobin ; bin <= hibin ; bin++ ) {
	binptr[ablock][bin]->nupenalty =
			 binptr[ablock][bin]->penalty ;
}
} else {
for( bin = alobin ; bin <= ahibin ; bin++ ) {
	binptr[ablock][bin]->nupenalty =
			 binptr[ablock][bin]->penalty ;
}
for( bin = anewlobin ; bin <= anewhibin ; bin++ ) {
	binptr[bblock][bin]->nupenalty =
			 binptr[bblock][bin]->penalty ;
}
}
}
new_assgnto_old1( alobin , ahibin , anewlobin , anewhibin )
int alobin , ahibin , anewlobin , anewhibin ;
{
int bin , lobin , hibin ;
if( ablock == bblock ) {
lobin = ( alobin <= anewlobin ) ? alobin : anewlobin ;
hibin = ( ahibin >= anewhibin ) ? ahibin : anewhibin ;
for( bin = lobin ; bin <= hibin ; bin++ ) {
	binptr[ablock][bin]->penalty =
			 binptr[ablock][bin]->nupenalty ;
}
} else {
for( bin = alobin ; bin <= ahibin ; bin++ ) {
	binptr[ablock][bin]->penalty =
			 binptr[ablock][bin]->nupenalty ;
}
for( bin = anewlobin ; bin <= anewhibin ; bin++ ) {
	binptr[bblock][bin]->penalty =
			 binptr[bblock][bin]->nupenalty ;
}
}
}
old_assgnto_new2( a1lobin , a1hibin , a2lobin , a2hibin ,
		  b1lobin , b1hibin , b2lobin , b2hibin )
int a1lobin , a1hibin , a2lobin , a2hibin ;
int b1lobin , b1hibin , b2lobin , b2hibin ;
{
int clobin , chibin , dlobin , dhibin ;
int lobin , hibin , bin ;
clobin = ( a1lobin <= b2lobin ) ? a1lobin : b2lobin ;
chibin = ( a1hibin >= b2hibin ) ? a1hibin : b2hibin ;
dlobin = ( a2lobin <= b1lobin ) ? a2lobin : b1lobin ;
dhibin = ( a2hibin >= b1hibin ) ? a2hibin : b1hibin ;
if( ablock == bblock ) {
lobin = ( clobin <= dlobin ) ? clobin : dlobin ;
hibin = ( chibin >= dhibin ) ? chibin : dhibin ;
for( bin = lobin ; bin <= hibin ; bin++ ) {
	binptr[ablock][bin]->nupenalty =
		     binptr[ablock][bin]->penalty ;
}
} else {
for( bin = clobin ; bin <= chibin ; bin++ ) {
	binptr[ablock][bin]->nupenalty =
		     binptr[ablock][bin]->penalty ;
}
for( bin = dlobin ; bin <= dhibin ; bin++ ) {
	binptr[bblock][bin]->nupenalty =
		     binptr[bblock][bin]->penalty ;
}
}
}
	
new_assgnto_old2( a1lobin , a1hibin , a2lobin , a2hibin ,
		  b1lobin , b1hibin , b2lobin , b2hibin )
int a1lobin , a1hibin , a2lobin , a2hibin ;
int b1lobin , b1hibin , b2lobin , b2hibin ;
{
int clobin , chibin , dlobin , dhibin ;
int lobin , hibin , bin ;
clobin = ( a1lobin <= b2lobin ) ? a1lobin : b2lobin ;
chibin = ( a1hibin >= b2hibin ) ? a1hibin : b2hibin ;
dlobin = ( a2lobin <= b1lobin ) ? a2lobin : b1lobin ;
dhibin = ( a2hibin >= b1hibin ) ? a2hibin : b1hibin ;
if( ablock == bblock ) {
lobin = ( clobin <= dlobin ) ? clobin : dlobin ;
hibin = ( chibin >= dhibin ) ? chibin : dhibin ;
for( bin = lobin ; bin <= hibin ; bin++ ) {
	binptr[ablock][bin]->penalty =
		     binptr[ablock][bin]->nupenalty ;
}
} else {
for( bin = clobin ; bin <= chibin ; bin++ ) {
	binptr[ablock][bin]->penalty =
		     binptr[ablock][bin]->nupenalty ;
}
for( bin = dlobin ; bin <= dhibin ; bin++ ) {
	binptr[bblock][bin]->penalty =
		     binptr[bblock][bin]->nupenalty ;
}
}
}
sub_penal( startx , endx , block , LoBin , HiBin )
int startx , endx , block , LoBin , HiBin ;
{
BINPTR bptr ;
int bin ;
if( LoBin == HiBin ) {
bptr = binptr[block][LoBin] ;
newbinpenal     -= ABS( bptr->nupenalty ) ;
bptr->nupenalty -= endx - startx          ;
newbinpenal     += ABS( bptr->nupenalty ) ;
} else {
for( bin = LoBin ; bin <= HiBin ; bin++ ) {
	bptr = binptr[block][bin] ;
	if( bin == LoBin ) {
	    newbinpenal     -= ABS( bptr->nupenalty ) ;
	    bptr->nupenalty -= bptr->right - startx   ;
	    newbinpenal     += ABS( bptr->nupenalty ) ;
} else if( bin == HiBin ) {
	    newbinpenal     -= ABS( bptr->nupenalty ) ;
	    bptr->nupenalty -= endx - bptr->left      ;
	    newbinpenal     += ABS( bptr->nupenalty ) ;
} else {
	    newbinpenal     -= ABS( bptr->nupenalty ) ;
	    bptr->nupenalty -= binWidth               ;
	    newbinpenal     += ABS( bptr->nupenalty ) ;
}
}
}
}
add_penal( startx , endx , block , LoBin , HiBin )
int startx , endx , block , LoBin , HiBin ;
{
BINPTR bptr ;
int bin ;
if( LoBin == HiBin ) {
bptr = binptr[block][LoBin] ;
newbinpenal     -= ABS( bptr->nupenalty ) ;
bptr->nupenalty += endx - startx          ;
newbinpenal     += ABS( bptr->nupenalty ) ;
} else {
for( bin = LoBin ; bin <= HiBin ; bin++ ) {
	bptr = binptr[block][bin] ;
	if( bin == LoBin ) {
	    newbinpenal     -= ABS( bptr->nupenalty ) ;
	    bptr->nupenalty += bptr->right - startx   ;
	    newbinpenal     += ABS( bptr->nupenalty ) ;
} else if( bin == HiBin ) {
	    newbinpenal     -= ABS( bptr->nupenalty ) ;
	    bptr->nupenalty += endx - bptr->left      ;
	    newbinpenal     += ABS( bptr->nupenalty ) ;
} else {
	    newbinpenal     -= ABS( bptr->nupenalty ) ;
	    bptr->nupenalty += binWidth               ;
	    newbinpenal     += ABS( bptr->nupenalty ) ;
}
}
}
}
/* 当前文件是D:\Read\closepins.c*/

/* 当前文件是D:\Read\route.h*/













closepins(tw , net )
FILE *tw ;
int net ;
{
int pin , pin1 , pin2 , minP1 , minP2 , minX , sepT , sepB , edge ;
int left , right , group1 , group2 , block1 , block2 , p1 , p2 ;
int minTop  , minBottom , maxTpin , maxBpin , otherTpin ;
int otherBpin , maxTop , maxBottom , key_count , key_flag ;
int segment_count , super_edge , next_edge ;
int e1 , e2 , g1 , g2 , next_g, save_count ;
int ltop , rtop , lbot , rbot ;
csPinBox *pArray1 , *pArray2 , *pArray ;
key_count = 0 ;
segment_count = 0 ;
super_edge = 0 ;
fprintf(tw,"net %d\n", net );
for( ; ; ) {
if( key_count > 0 ) {
	edge = key_queue[ key_count-- ] ;
	group1 = edgeArray[edge].group1 ;
	key_flag = save_count ;
	ltop = lbot = rtop = rbot = -1 ;
	
} else {
	while( ++super_edge <= numEdges ) {
	    if( edgeArray[super_edge].marked == NO ) {
		continue ;
	    }
	    if( edgeArray[super_edge].done == NO ) {
		break ;
	    }
	}
	if( super_edge > numEdges ) {
	    break ;
	}
	edge = super_edge ;
	key_flag = 0 ;
	ltop = lbot = rtop = rbot = 0 ;
	
}
segment_count++ ;
maxTop  = -1000000000 ;
maxBottom = -1000000000 ;
maxTpin = 0 ;
maxBpin = 0 ;
group1  = edgeArray[edge].group1 ;
pArray1 = groupArray[group1].pinArray ;
block1  = groupArray[group1].block ;
group2  = edgeArray[ edge ].group2 ;
pArray2 = groupArray[group2].pinArray ;
block2  = groupArray[group2].block ;
if( edgeArray[edge].poison == NO && key_flag == NO) {
	save_count = segment_count ;
	edgeArray[edge].done = YES ;
	key_flag = save_count ;
	
	e1 = edge ;
	g1 = edgeArray[e1].group1 ;
	for( ; ; ) {
	    if( groupArray[g1].poison == YES ) {
		
		break ;
	    }
	    if( groupArray[g1].edge1 == e1 ) {
		next_edge = groupArray[g1].edge2 ;
	    } else {
		next_edge = groupArray[g1].edge1 ;
	    }
	    if( next_edge == 0 ) {
		break ;
	    }
	    next_g = edgeArray[next_edge].group1 ;
	    if( next_g == g1 ) {
		g1 = edgeArray[next_edge].group2 ;
	    } else {
		g1 = next_g ;
	    }
	    e1 = next_edge ;
	    edgeArray[e1].done = YES ;
	    key_queue[ ++key_count ] = e1 ;
	}
	e2 = edge ;
	g2 = edgeArray[e2].group2 ;
	for( ; ; ) {
	    if( groupArray[g2].poison == YES ) {
		break ;
	    }
	    if( groupArray[g2].edge1 == e2 ) {
		next_edge = groupArray[g2].edge2 ;
	    } else {
		next_edge = groupArray[g2].edge1 ;
	    }
	    if( next_edge == 0 ) {
		break ;
	    }
	    next_g = edgeArray[next_edge].group1 ;
	    if( next_g == g2 ) {
		g2 = edgeArray[next_edge].group2 ;
	    } else {
		g2 = next_g ;
	    }
	    e2 = next_edge ;
	    edgeArray[e2].done = YES ;
	    key_queue[ ++key_count ] = e2 ;
	}
	if( groupArray[g1].aveX <= groupArray[g2].aveX ) {
	    pArray = groupArray[g1].pinArray ;
	    for(pin = 1; pin <= groupArray[g1].numPins; pin++ ){
		if( pArray[pin].top == 1 || pArray[pin].top == 0){
		    ltop = pArray[pin].pin ;
		}
		if(pArray[pin].top == -1 || pArray[pin].top == 0){
		    lbot = pArray[pin].pin ;
		}
	    }
	    pArray = groupArray[g2].pinArray ;
	    for(pin = 1; pin <= groupArray[g2].numPins; pin++ ){
		if( pArray[pin].top == 1 || pArray[pin].top == 0){
		    rtop = pArray[pin].pin ;
		}
		if(pArray[pin].top == -1 || pArray[pin].top == 0){
		    rbot = pArray[pin].pin ;
		}
	    }
	} else {
	    pArray = groupArray[g2].pinArray ;
	    for(pin = 1; pin <= groupArray[g2].numPins; pin++ ){
		if( pArray[pin].top == 1 || pArray[pin].top == 0){
		    ltop = pArray[pin].pin ;
		}
		if(pArray[pin].top == -1 || pArray[pin].top == 0){
		    lbot = pArray[pin].pin ;
		}
	    }
	    pArray = groupArray[g1].pinArray ;
	    for(pin = 1; pin <= groupArray[g1].numPins; pin++ ){
		if( pArray[pin].top == 1 || pArray[pin].top == 0){
		    rtop = pArray[pin].pin ;
		}
		if(pArray[pin].top == -1 || pArray[pin].top == 0){
		    rbot = pArray[pin].pin ;
		}
	    }
	}
}
if( block1 == block2 ) {
	
	if( groupArray[group1].aveX <= groupArray[group2].aveX){
	    for(pin = 1; pin <= groupArray[group1].numPins; pin++ ){
		if( pArray1[pin].top == 1 || pArray1[pin].top == 0){
		    if( pArray1[ pin ].xloc > maxTop ) {
			maxTop = pArray1[ pin ].xloc ;
			maxTpin = pArray1[ pin ].pin ;
		    }
		}
		if(pArray1[pin].top == -1 || pArray1[pin].top == 0){
		    if( pArray1[ pin ].xloc > maxBottom ) {
			maxBottom = pArray1[ pin ].xloc ;
			maxBpin = pArray1[ pin ].pin ;
		    }
		}
	    }
	    sepT = 1000000000 ;
	    sepB = 1000000000 ;
	    otherTpin = 0 ;
	    otherBpin = 0 ;
	    for(pin = 1; pin <= groupArray[group2].numPins; pin++ ){
		if( pArray2[pin].top == 1 || pArray2[pin].top == 0){
		    if( ABS(pArray2[ pin ].xloc - maxTop) < sepT ) {
			otherTpin = pArray2[ pin ].pin ;
			minTop = pArray2[ pin ].xloc ;
			sepT = ABS( minTop - maxTop ) ;
		    }
		}
		if(pArray2[pin].top == -1 || pArray2[pin].top == 0){
		    if( ABS(pArray2[pin].xloc - maxBottom) < sepB ){
			otherBpin = pArray2[ pin ].pin ;
			minBottom = pArray2[ pin ].xloc ;
			sepB = ABS( minBottom - maxBottom );
		    }
		}
	    }
	    if( maxTpin != 0 && otherTpin != 0 && block1 < numChans &&
		    ( (!(maxBpin != 0 && otherBpin != 0)) ||
		      ( (maxBpin != 0 && otherBpin != 0)  &&
			maxBottom != minBottom)  )  ) {
		if( maxBpin != 0 && otherBpin != 0 && block1 > 0 &&
						maxTop != minTop ) {
		
		    fprintf(tw,"segment switchable %d\n", key_flag );
		    fprintf(tw,"top channel %d\n", (block1 + 1) );
		    if( maxTop <= minTop ) {
			p1  = maxTpin ;
			p2  = otherTpin ;
		    } else {
			p1  = otherTpin ;
			p2  = maxTpin ;
		    }
		    fprintf(tw,"pin1 %d  pin2 %d %d %d\n"
		    , p1 , p2 , ltop , rtop ) ;
		    fprintf(tw,"bottom channel %d\n", block1 );
		    if( maxBottom <= minBottom ) {
			p1  = maxBpin ;
			p2  = otherBpin ;
		    } else {
			p1  = otherBpin ;
			p2  = maxBpin ;
		    }
		    fprintf(tw,"pin1 %d  pin2 %d %d %d\n"
		    , p1 , p2 , lbot , rbot ) ;
		} else {
		    fprintf(tw,"segment channel %d\n",(block1 + 1));
		    if( maxTop <= minTop ) {
			p1  = maxTpin ;
			p2  = otherTpin ;
		    } else {
			p1  = otherTpin ;
			p2  = maxTpin ;
		    }
		    fprintf(tw,"pin1 %d  pin2 %d %d %d\n"
		    , p1 , p2 , ltop , rtop ) ;
		}
	    } else if( maxBpin != 0 && otherBpin != 0 ) {
		
		fprintf(tw,"segment channel %d\n", block1);
		if( maxBottom <= minBottom ) {
		    p1  = maxBpin ;
		    p2  = otherBpin ;
		} else {
		    p1  = otherBpin ;
		    p2  = maxBpin ;
		}
		fprintf(tw,"pin1 %d  pin2 %d %d %d\n"
		, p1 , p2 , lbot , rbot ) ;
	    }
	} else {
	    for(pin = 1; pin <= groupArray[group2].numPins ; pin++){
		if( pArray2[pin].top == 1 || pArray2[pin].top == 0){
		    if( pArray2[ pin ].xloc > maxTop ) {
			maxTop  = pArray2[ pin ].xloc ;
			maxTpin = pArray2[ pin ].pin ;
		    }
		}
		if(pArray2[pin].top == -1 || pArray2[pin].top == 0){
		    if( pArray2[ pin ].xloc > maxBottom ) {
			maxBottom = pArray2[ pin ].xloc ;
			maxBpin = pArray2[ pin ].pin ;
		    }
		}
	    }
	    sepT = 1000000000 ;
	    sepB = 1000000000 ;
	    otherTpin = 0 ;
	    otherBpin = 0 ;
	    for(pin = 1; pin <= groupArray[group1].numPins ; pin++){
		if( pArray1[pin].top == 1 || pArray1[pin].top == 0){
		    if( ABS(pArray1[ pin ].xloc - maxTop) < sepT ) {
			otherTpin = pArray1[ pin ].pin ;
			minTop = pArray1[ pin ].xloc ;
			sepT = ABS(minTop - maxTop ) ;
		    }
		}
		if(pArray1[pin].top == -1 || pArray1[pin].top == 0){
		    if( ABS(pArray1[pin].xloc - maxBottom) < sepB ){
		      otherBpin = pArray1[ pin ].pin ;
		      minBottom = pArray1[ pin ].xloc ;
		      sepB = ABS(minBottom - maxBottom) ;
		    }
		}
	    }
	    if( maxTpin != 0 && otherTpin != 0 && block1 < numChans &&
		    ( (!(maxBpin != 0 && otherBpin != 0)) ||
		      ( (maxBpin != 0 && otherBpin != 0)  &&
			maxBottom != minBottom)  )  ) {
		if( maxBpin != 0 && otherBpin != 0 &&
				    block1 > 0 && maxTop != minTop ) {
		
		    fprintf(tw,"segment switchable %d\n", key_flag );
		    fprintf(tw,"top channel %d\n", (block1 + 1) );
		    if( maxTop <= minTop ) {
			p1  = maxTpin ;
			p2  = otherTpin ;
		    } else {
			p1  = otherTpin ;
			p2  = maxTpin ;
		    }
		    fprintf(tw,"pin1 %d  pin2 %d %d %d\n"
		    , p1 , p2 , ltop , rtop ) ;
		    fprintf(tw,"bottom channel %d\n", block1 );
		    if( maxBottom <= minBottom ) {
			p1  = maxBpin ;
			p2  = otherBpin ;
		    } else {
			p1  = otherBpin ;
			p2  = maxBpin ;
		    }
		    fprintf(tw,"pin1 %d  pin2 %d %d %d\n"
		    , p1 , p2 , lbot , rbot ) ;
		} else {
		    fprintf(tw,"segment channel %d\n",(block1 + 1));
		    if( maxTop <= minTop ) {
			p1  = maxTpin ;
			p2  = otherTpin ;
		    } else {
			p1  = otherTpin ;
			p2  = maxTpin ;
		    }
		    fprintf(tw,"pin1 %d  pin2 %d %d %d\n"
		    , p1 , p2 , ltop , rtop ) ;
		}
	    } else if( maxBpin != 0 && otherBpin != 0 ) {
		
		fprintf(tw,"segment channel %d\n", block1 );
		if( maxBottom <= minBottom ) {
		    p1  = maxBpin ;
		    p2  = otherBpin ;
		} else {
		    p1  = otherBpin ;
		    p2  = maxBpin ;
		}
		fprintf(tw,"pin1 %d  pin2 %d %d %d\n"
		, p1 , p2 , lbot , rbot ) ;
	    }
	}
} else {
	minX = 1000000000 ;
	minP1 = 0 ;
	minP2 = 0 ;
	if( block1 > block2 ) {
	    for(pin1 = 1;pin1 <= groupArray[group1].numPins;pin1++){
		if( pArray1[pin1].top == -1 ||
					pArray1[pin1].top == 0 ) {
		    pin2 = 1 ;
		    for(;pin2 <= groupArray[group2].numPins;pin2++){
			if( pArray2[ pin2 ].top == 1 ||
					pArray2[pin2].top == 0 ) {
			    if( ABS( pArray1[ pin1 ].xloc -
				   pArray2[ pin2 ].xloc ) < minX ) {
				left  = pArray1[pin1].xloc;
				right = pArray2[pin2].xloc;
				minX  = ABS( left - right );
				minP1 = pArray1[pin1].pin;
				minP2 = pArray2[pin2].pin;
			    }
			}
		    }
		}
	    }
	    if( minP1 != 0 && minP2 != 0 ) {
		fprintf(tw,"segment channel %d\n", block1 );
		if( left > right ) {
		    fprintf(tw," pin1 %d  pin2 %d %d %d\n"
		    , minP2 , minP1 , ltop , rtop );
		} else {
		    fprintf(tw," pin1 %d  pin2 %d %d %d\n"
		    , minP1 , minP2 , ltop , rtop );
		}
	    }
	} else {
	    pin1 = 1 ;
	    for(; pin1 <= groupArray[group1].numPins; pin1++ ) {
		if( pArray1[pin1].top == 1 ||
					pArray1[pin1].top == 0 ) {
		    pin2 = 1 ;
		    for(;pin2 <= groupArray[group2].numPins;pin2++){
			if( pArray2[ pin2 ].top == -1 ||
					pArray2[pin2].top == 0 ) {
			    if( ABS( pArray1[ pin1 ].xloc -
				   pArray2[ pin2 ].xloc ) < minX ) {
				left = pArray1[pin1].xloc;
				right = pArray2[pin2].xloc;
				minX = ABS( left - right ) ;
				minP1 = pArray1[pin1].pin;
				minP2 = pArray2[pin2].pin;
			    }
			}
		    }
		}
	    }
	    if( minP1 != 0 && minP2 != 0 ) {
		fprintf(tw,"segment channel %d\n", block2 );
		if( left > right ) {
		    fprintf(tw," pin1 %d  pin2 %d %d %d\n"
		    , minP2 , minP1 , ltop , rtop );
		} else {
		    fprintf(tw," pin1 %d  pin2 %d %d %d\n"
		    , minP1 , minP2 , ltop , rtop );
		}
	    }
	}
}
}
return ;
}

/* 当前文件是D:\Read\configure.c*/

#define MAXMACRO 50
#define T 2
#define R 3


double ckt_size_factor ;
configure()
{
config1() ;
xshift = 0 ;
yshift = 0 ;
zxshift = 0 ;
zyshift = 0 ;
for( pad = numcells + 1 ; pad <= numcells + numterms ; pad++ ) {
if( carray[pad]->padside == B ) {
	count = 1 ;
	height = carray[pad]->tileptr->top -
		 carray[pad]->tileptr->bottom ;
	width = carray[pad]->tileptr->right -
		  carray[pad]->tileptr->left ;
	for( pad++ ; pad <= numcells + numterms ; pad++ ) {
	    if( carray[pad]->padside != B ) {
		break ;
	    }
	    count++ ;
	    if( carray[pad]->tileptr->top -
		carray[pad]->tileptr->bottom > height ) {
		height = carray[pad]->tileptr->top
		   - carray[pad]->tileptr->bottom ;
	    }
	    width += carray[pad]->tileptr->right -
		      carray[pad]->tileptr->left ;
	}
	maxHeight = height ;
	if( fixLRBT[2] == 0 ) {
	    space = coreWidth - width ;
	    separation = space / (count + 1) ;
	    if( separation < 0 ) {
		separation = 0 ;
		zxshift = ABS( space ) ;
	    }
	} else {
	    space = ( coreWidth >= width ) ? coreWidth : width ;
	}
	
	yshift = maxHeight + extraSpace ;
	for( row = 1 ; row <= numRows ; row++ ) {
	    rowArray[row].ypos += yshift ;
	}
	for( pad = numcells + 1; pad <= numcells + numterms; pad++){
	    if( carray[pad]->padside == B ) {
		height = carray[pad]->tileptr->top -
			 carray[pad]->tileptr->bottom ;
		width =  carray[pad]->tileptr->right -
			  carray[pad]->tileptr->left ;
		if( fixLRBT[2] == 0 ) {
		    carray[pad]->cxcenter = separation + width / 2 ;
		} else {
		    carray[pad]->cxcenter = padspace[ pad - numcells ]
							    * space ;
		}
		carray[pad]->cycenter = maxHeight - height / 2 - 1 ;
		last = separation + width ;
		for( pad++ ; pad <= numcells + numterms ; pad++ ) {
		    if( carray[pad]->padside != B ) {
			break ;
		    }
		    height = carray[pad]->tileptr->top -
			     carray[pad]->tileptr->bottom ;
		    width =  carray[pad]->tileptr->right -
			      carray[pad]->tileptr->left ;
		    if( fixLRBT[2] == 0 ) {
			carray[pad]->cxcenter = last + separation +
						    width / 2 ;
		    } else {
			carray[pad]->cxcenter =
				    padspace[ pad - numcells ] * space ;
		    }
		    carray[pad]->cycenter = maxHeight -
						    height / 2 - 1 ;
		    last += separation + width ;
		}
	    }
	}
}
}
for( pad = numcells + 1 ; pad <= numcells + numterms ; pad++ ) {
if( carray[pad]->padside == T ) {
	count = 1 ;
	width = carray[pad]->tileptr->right -
		  carray[pad]->tileptr->left ;
	for( pad++ ; pad <= numcells + numterms ; pad++ ) {
	    if( carray[pad]->padside != T ) {
		break ;
	    }
	    count++ ;
	    width += carray[pad]->tileptr->right -
		      carray[pad]->tileptr->left ;
	}
	if( fixLRBT[3] == 0 ) {
	    space = coreWidth - width ;
	    separation = space / (count + 1) ;
	    if( separation < 0 ) {
		separation = 0 ;
		if( ABS( space ) > zxshift ) {
		    zxshift = ABS( space ) ;
		}
	    }
	} else {
	    space = (coreWidth >= width ) ? coreWidth : width ;
	}
	
	coreTop = rowArray[numRows].ypos + rowHeight / 2 + extraSpace +
							 mttshift ;
	for( pad = numcells + 1; pad <= numcells + numterms; pad++){
	    if( carray[pad]->padside == T ) {
		height = carray[pad]->tileptr->top -
			 carray[pad]->tileptr->bottom ;
		width =  carray[pad]->tileptr->right -
			  carray[pad]->tileptr->left ;
		if( fixLRBT[3] == 0 ) {
		    carray[pad]->cxcenter = separation + width / 2 ;
		} else {
		    carray[pad]->cxcenter = padspace[ pad - numcells ]
							    * space ;
		}
		carray[pad]->cycenter = coreTop + height / 2 ;
		last = separation + width ;
		for( pad++ ; pad <= numcells + numterms ; pad++ ) {
		    if( carray[pad]->padside != T ) {
			break ;
		    }
		    height = carray[pad]->tileptr->top -
			     carray[pad]->tileptr->bottom ;
		    width =  carray[pad]->tileptr->right -
			      carray[pad]->tileptr->left ;
		    if( fixLRBT[3] == 0 ) {
			carray[pad]->cxcenter = last + separation +
							    width / 2 ;
		    } else {
			carray[pad]->cxcenter =
				    padspace[ pad - numcells ] * space ;
		    }
		    carray[pad]->cycenter = coreTop + height / 2 ;
		    last += separation + width ;
		}
	    }
	}
}
}
for( pad = numcells + 1 ; pad <= numcells + numterms ; pad++ ) {
if( carray[pad]->padside == L ) {
	count = 1 ;
	height = carray[pad]->tileptr->top -
		 carray[pad]->tileptr->bottom ;
	width = carray[pad]->tileptr->right -
		  carray[pad]->tileptr->left ;
	for( pad++ ; pad <= numcells + numterms ; pad++ ) {
	    if( carray[pad]->padside != L ) {
		break ;
	    }
	    count++ ;
	    if( carray[pad]->tileptr->right -
		carray[pad]->tileptr->left  > width ) {
		width = carray[pad]->tileptr->right -
			 carray[pad]->tileptr->left ;
	    }
	    height += carray[pad]->tileptr->top -
		      carray[pad]->tileptr->bottom ;
	}
	maxWidth = width ;
	if( fixLRBT[0] == 0 ) {
	    space = coreHeight - height ;
	    separation = space / (count + 1) ;
	    if( separation < 0 ) {
		separation = 0 ;
		zyshift = ABS( space ) ;
	    }
	} else {
	    space = (coreHeight >= height ) ? coreHeight : height ;
	}
	
	xshift = maxWidth + extraSpace ;
	for( row = 1 ; row <= numRows ; row++ ) {
	    rowArray[row].startx += xshift ;
	    rowArray[row].endx   += xshift ;
	    if( rowArray[row].endx1 > 0 ) {
		rowArray[row].endx1   += xshift ;
		rowArray[row].startx2 += xshift ;
	    }
	}
	for( pad = numcells + 1; pad <= numcells + numterms; pad++){
	    if( carray[pad]->padside == L ) {
		height = carray[pad]->tileptr->top -
			 carray[pad]->tileptr->bottom ;
		width =  carray[pad]->tileptr->right -
			  carray[pad]->tileptr->left ;
		if( fixLRBT[0] == 0 ) {
		    carray[pad]->cycenter = rowArray[1].ypos -
			    rowHeight / 2 + separation +
			    height / 2 - mbbshift ;
		} else {
		    carray[pad]->cycenter = rowArray[1].ypos -
			    rowHeight / 2 - mbbshift +
			    padspace[ pad - numcells ] * space ;
		}
		carray[pad]->cxcenter = maxWidth - width / 2 - 1 ;
		last = rowArray[1].ypos - rowHeight / 2 +
				separation + height - mbbshift ;
		for( pad++ ; pad <= numcells + numterms ; pad++ ) {
		    if( carray[pad]->padside != L ) {
			break ;
		    }
		    height = carray[pad]->tileptr->top -
			     carray[pad]->tileptr->bottom ;
		    width =  carray[pad]->tileptr->right -
			      carray[pad]->tileptr->left ;
		    if( fixLRBT[0] == 0 ) {
			carray[pad]->cycenter = last + separation +
						    height / 2 ;
		    } else {
			carray[pad]->cycenter = rowArray[1].ypos -
			    rowHeight / 2 - mbbshift +
			    padspace[ pad - numcells ] * space ;
		    }
		    carray[pad]->cxcenter = maxWidth -
						    width / 2 - 1 ;
		    last += separation + height ;
		}
	    }
	}
}
}
for( pad = numcells + 1 ; pad <= numcells + numterms ; pad++ ) {
if( carray[pad]->padside == R ) {
	count = 1 ;
	height = carray[pad]->tileptr->top -
		 carray[pad]->tileptr->bottom ;
	for( pad++ ; pad <= numcells + numterms ; pad++ ) {
	    if( carray[pad]->padside != R ) {
		break ;
	    }
	    count++ ;
	    height += carray[pad]->tileptr->top -
		      carray[pad]->tileptr->bottom ;
	}
	if( fixLRBT[1] == 0 ) {
	    space = coreHeight - height ;
	    separation = space / (count + 1) ;
	    if( separation < 0 ) {
		separation = 0 ;
		if( ABS( space ) > zyshift ) {
		    zyshift = ABS( space ) ;
		}
	    }
	} else {
	    space = (coreHeight >= height) ? coreHeight : height ;
	}
	coreRite = coreWidth + xshift + extraSpace ;
	for( pad = numcells + 1; pad <= numcells + numterms; pad++){
	    if( carray[pad]->padside == R ) {
		height = carray[pad]->tileptr->top -
			 carray[pad]->tileptr->bottom ;
		width =  carray[pad]->tileptr->right -
			  carray[pad]->tileptr->left ;
		if( fixLRBT[1] == 0 ) {
		    carray[pad]->cycenter = rowArray[1].ypos -
					rowHeight / 2 + separation +
					height / 2 - mbbshift ;
		} else {
		    carray[pad]->cycenter = rowArray[1].ypos -
				    rowHeight / 2 - mbbshift +
				    padspace[ pad - numcells ] * space ;
		}
		carray[pad]->cxcenter = coreRite + width / 2 ;
		last = rowArray[1].ypos - rowHeight / 2 +
			    separation + height - mbbshift ;
		for( pad++ ; pad <= numcells + numterms ; pad++ ) {
		    if( carray[pad]->padside != R ) {
			break ;
		    }
		    height = carray[pad]->tileptr->top -
			     carray[pad]->tileptr->bottom ;
		    width =  carray[pad]->tileptr->right -
			      carray[pad]->tileptr->left ;
		    if( fixLRBT[1] == 0 ) {
			carray[pad]->cycenter = last + separation +
						    height / 2 ;
		    } else {
			carray[pad]->cycenter = rowArray[1].ypos -
				    rowHeight / 2 - mbbshift +
				    padspace[ pad - numcells ] * space ;
		    }
		    carray[pad]->cxcenter = coreRite + width / 2 ;
		    last += separation + height ;
		}
	    }
	}
}
}
for( macro = 1 ; macro <= numMacro ; macro++ ) {
pad = padArray[macro] ;
carray[pad]->cxcenter = macroArray[macro].mx + xshift ;
carray[pad]->cycenter = macroArray[macro].my + yshift +
						    mbbshift ;
}
for( pad = numcells + 1 ; pad <= numcells + numterms ; pad++ ) {
if( carray[pad]->padside == B || carray[pad]->padside == T ) {
	carray[pad]->cxcenter += xshift ;
} else if( carray[pad]->padside == MTT ||
				    carray[pad]->padside == MBB ) {
	carray[pad]->cxcenter += xshift ;
	carray[pad]->cycenter += yshift ;
}
}
for( row = 1 ; row <= numRows ; row++ ) {
rowArray[row].startx += zxshift / 2 ;
rowArray[row].endx   += zxshift / 2 ;
if( rowArray[row].endx1 > 0 ) {
	rowArray[row].endx1   += zxshift / 2 ;
	rowArray[row].startx2 += zxshift / 2 ;
}
}
for( macro = 1 ; macro <= numMacro ; macro++ ) {
pad = padArray[macro] ;
carray[pad]->cxcenter += zxshift / 2 ;
}
for( pad = numcells + 1 ; pad <= numcells + numterms ; pad++ ) {
if( carray[pad]->padside == R ) {
	carray[pad]->cxcenter += zxshift ;
} else if( carray[pad]->padside == MTT ||
				    carray[pad]->padside == MBB ) {
	carray[pad]->cxcenter += zxshift / 2 ;
}
}
yshift = maxHeight + rowHeight + extraSpace ;
for( row = 1 ; row <= numRows ; row++ ) {
rowArray[row].ypos += zyshift / 2 ;
}
for( macro = 1 ; macro <= numMacro ; macro++ ) {
pad = padArray[macro] ;
carray[pad]->cycenter += zyshift / 2 ;
}
for( pad = numcells + 1 ; pad <= numcells + numterms ; pad++ ) {
if( carray[pad]->padside == T ) {
	carray[pad]->cycenter += zyshift ;
} else if( carray[pad]->padside == MTT ||
				    carray[pad]->padside == MBB ) {
	carray[pad]->cycenter += zyshift / 2 ;
}
}
block = 0 ;
for( row = 1 ; row <= numRows ; row++ ) {
block++ ;
if( rowArray[row].endx1 > 0 ) {
	block++ ;
}
}
totalBlock = block ;
oldbarray = barray ;
blkToRow = (int *) safe_malloc( (totalBlock + 1) * sizeof(int) ) ;
barray = (BBOXPTR *) safe_malloc( (totalBlock + 1) * sizeof(BBOXPTR) ) ;
for( block = 1 ; block <= totalBlock ; block++ ) {
barray[block] = (BBOXPTR) safe_malloc( sizeof(BBOX) ) ;
}
block = 0 ;
for( row = 1 ; row <= numRows ; row++ ) {
boxptr = oldbarray[row] ;
if( rowArray[row].endx1 > 0 ) {
	block++ ;
	blkToRow[block] = row ;
	barray[block]->bxcenter = (rowArray[row].startx +
				    rowArray[row].endx1 ) / 2 ;
	barray[block]->bycenter = rowArray[row].ypos ;
	barray[block]->bleft   = rowArray[row].startx -
				    barray[block]->bxcenter ;
	barray[block]->bright  = rowArray[row].endx1 -
				    barray[block]->bxcenter ;
	barray[block]->bbottom = boxptr->bbottom ;
	barray[block]->btop    = boxptr->btop ;
	barray[block]->bheight = boxptr->btop - boxptr->bbottom ;
	barray[block]->blength = rowArray[row].endx1 -
				    rowArray[row].startx ;
	barray[block]->bclass  = boxptr->bclass ;
	barray[block]->borient = boxptr->borient ;
	barray[block]->oldsize = 0 ;
	block++ ;
	blkToRow[block] = row ;
	barray[block]->bxcenter = (rowArray[row].startx2 +
				    rowArray[row].endx ) / 2 ;
	barray[block]->bycenter = rowArray[row].ypos ;
	barray[block]->bleft   = rowArray[row].startx2 -
				    barray[block]->bxcenter ;
	barray[block]->bright  = rowArray[row].endx -
				    barray[block]->bxcenter ;
	barray[block]->bbottom = boxptr->bbottom ;
	barray[block]->btop    = boxptr->btop ;
	barray[block]->bheight = boxptr->btop - boxptr->bbottom ;
	barray[block]->blength = rowArray[row].endx -
				    rowArray[row].startx2 ;
	barray[block]->bclass  = boxptr->bclass ;
	barray[block]->borient = boxptr->borient ;
	ratio = (double) barray[block - 1]->blength / (double)
	     (barray[block - 1]->blength + barray[block]->blength) ;
	barray[block]->desire = 1 + (int)((1.0 - ratio) *
				    rowArray[row].desiredL) ;
	barray[block - 1]->desire = 1 + (int)(ratio *
				    rowArray[row].desiredL) ;
	barray[block]->oldsize = 0 ;
} else {
	block++ ;
	blkToRow[block] = row ;
	barray[block]->bxcenter = (rowArray[row].startx +
				    rowArray[row].endx ) / 2 ;
	barray[block]->bycenter = rowArray[row].ypos ;
	barray[block]->bleft   = rowArray[row].startx -
				    barray[block]->bxcenter ;
	barray[block]->bright  = rowArray[row].endx -
				    barray[block]->bxcenter ;
	barray[block]->bbottom = boxptr->bbottom ;
	barray[block]->btop    = boxptr->btop ;
	barray[block]->bheight = boxptr->btop - boxptr->bbottom ;
	barray[block]->blength = rowArray[row].endx -
				    rowArray[row].startx ;
	barray[block]->bclass  = boxptr->bclass ;
	barray[block]->borient = boxptr->borient ;
	barray[block]->desire  = rowArray[row].desiredL ;
	barray[block]->oldsize = 0 ;
}
}
for( row = 1 ; row <= numblock ; row++ ) {
safe_free( oldbarray[row] ) ;
}
safe_free( oldbarray ) ;
numblock = totalBlock ;
fprintf(fpo,"\n******************\nBLOCK DATA\n");
desiredL = 0 ;
for( block = 1 ; block <= numblock ; block++ ) {
desiredL += barray[block]->desire ;
fprintf(fpo,"block:%d desire:%d\n",block,barray[block]->desire);
}
fprintf(fpo,"Total Desired Length: %d\n", desiredL ) ;
ckt_size_factor = (double) desiredL ;
filledTo = (int *) safe_malloc( (numblock + 1) * sizeof( int ) ) ;
endRow = (int *) safe_malloc( (numblock + 1) * sizeof( int ) ) ;
for( row = 1 ; row <= numblock ; row++ ) {
filledTo[row] = barray[row]->bxcenter + barray[row]->bleft ;
endRow[row]  = barray[row]->bxcenter + barray[row]->bright ;
}
for( cell = 1 ; cell <= numcells ; cell++ ) {
cellptr = carray[cell] ;
row = cellptr->cblock ;
if( row == 0 ) {
	continue ;
}
blk = RtoB( row , cellptr->cycenter ) ;
borient = barray[blk]->borient ;
cellptr->cblock = blk ;
width = cellptr->tileptr->right - cellptr->tileptr->left ;
if( cellptr->cycenter > 0 ) {
	carray[cell]->cxcenter = barray[blk]->bxcenter +
				    barray[blk]->bleft +
				    cellptr->cxcenter + width / 2 ;
	carray[cell]->cycenter = barray[blk]->bycenter ;
} else {
	carray[cell]->cxcenter = barray[blk]->bxcenter +
				    barray[blk]->bright +
		    cellptr->cxcenter - (width - width / 2) ;
	carray[cell]->cycenter = barray[blk]->bycenter ;
}
if( borient == 2 ) {
	cellptr->corient = 1 ;
} else {
	cellptr->corient = 0 ;
}
}
for( cell = 1 ; cell <= numcells ; cell++ ) {
if( carray[cell]->cblock != 0 ) {
	continue ;
}
empty = -32000 ;
for( row = 1 ; row <= numblock ; row++ ) {
	if( endRow[row] - filledTo[row] > empty ) {
	    empty = endRow[row] - filledTo[row] ;
	    block = row ;
	}
}
borient = barray[block]->borient ;
width = carray[cell]->tileptr->right - carray[cell]->tileptr->left ;
carray[cell]->cblock = block ;
if( borient > 0 ) {
	carray[cell]->cxcenter = filledTo[block] + width / 2 ;
	carray[cell]->cycenter = barray[block]->bycenter ;
	if( borient == 2 ) {
	    carray[cell]->corient = 1 ;
	} else {
	    carray[cell]->corient = 0 ;
	}
} else {
	carray[cell]->cycenter = filledTo[block] + width / 2 ;
	carray[cell]->cxcenter = barray[block]->bxcenter ;
	if( borient == -2 ) {
	    carray[cell]->corient = 4 ;
	} else {
	    carray[cell]->corient = 7 ;
	}
}
filledTo[block] += width ;
}
return ;
}
RtoB( row , from )
int row , from ;
{
int y , block , block1 , block2 , endx1 , startx2 ;
y = rowArray[row].ypos ;
block1 = 0 ;
block2 = 0 ;
for( block = 1 ; block <= numblock ; block++ ) {
	if( barray[block]->bycenter == y ) {
	    block1 = block ;
	    break ;
	}
}
for( block++ ; block <= numblock ; block++ ) {
	if( barray[block]->bycenter == y ) {
	    block2 = block ;
	    break ;
	}
}
if( block1 == 0 ) {
	fprintf(fpo,"RtoB failed to find block corresponding");
	fprintf(fpo," to row:%d\n", row ) ;
	exit(TW_FAIL) ;
}
if( block2 == 0 ) {
	block = block1 ;
} else {
	endx1 = barray[block1]->bxcenter + barray[block1]->bright ;
	startx2 = barray[block2]->bxcenter + barray[block2]->bleft ;
	if( from > 0 ) {
	    if( endx1 < startx2 ) {
		block = block1 ;
	    } else {
		block = block2 ;
	    }
	} else {
	    if( startx2 > endx1 ) {
		block = block2 ;
	    } else {
		block = block1 ;
	    }
	}
}
return(block) ;
}
/* 当前文件是D:\Read\configuref.c*/


int old_feed_length = 0 ;
configuref( feed_length )
int feed_length ;
{
CBOXPTR padptr ;
int core_left , core_right , core_span , row , pad , right ;
int shift_amount ;
shift_amount = (feed_length / numRows) - (old_feed_length / numRows) ;
if( shift_amount == 0 ) {
for( row = 1 ; row <= numRows ; row++ ) {
	barray[row]->oldsize  = 0 ;
}
return ;
}
core_right = 0 ;
core_left  = 10000000 ;
for( row = 1 ; row <= numRows ; row++ ) {
barray[row]->bright  += shift_amount ;
barray[row]->blength += shift_amount ;
barray[row]->desire  += shift_amount ;
barray[row]->oldsize  = 0 ;
rowArray[row].endx   += shift_amount ;
if( rowArray[row].startx < core_left ) {
	core_left = rowArray[row].startx ;
}
if( rowArray[row].endx > core_right ) {
	core_right = rowArray[row].endx ;
}
}
core_span = core_right - core_left ;
for( pad = numcells + 1 ; pad <= numcells + numterms ; pad++ ) {
padptr = carray[pad] ;
if( padptr->padside == 3 || padptr->padside == MR ||
		padptr->padside == MUR || padptr->padside == MLR ) {
	padptr->cxcenter += shift_amount ;
} else if( padptr->padside == 2 || padptr->padside == B ||
		padptr->padside == MTT || padptr->padside == MBB ) {
	right = padptr->cxcenter + padptr->tileptr->right - core_left;
	padptr->cxcenter += (int)(
		((double)right / (double) core_span) *
		((double) shift_amount) ) ;
}
}
old_feed_length = feed_length ;
return ;
}
/* 当前文件是D:\Read\controlf.c*/

controlf()
{
int feed_length ;
feed_length = countf() ;
configuref( feed_length ) ;
funccost = findcostf() ;
return( feed_length / fdWidth ) ;
}
/* 当前文件是D:\Read\countf.c*/


countf()
{
NBOXPTR netptr ;
CBOXPTR cellptr ;
int check , a , value ;
int net , i , row , toprow , botrow ;
int TOP_ROW_FOR_NET ;
int orig_toprow , orig_botrow ;
if( num_calls == 0 ) {
num_calls = 1 ;
prep_feed_count_1() ;
row_map = ( short int ** ) safe_malloc( (numRows + 2) *
					    sizeof(short int *));
for( row = 0 ; row <= numRows + 1 ; row++ ) {
	row_map[row] = (short int *) safe_malloc( 3 *
				    sizeof( short int ) );
}
insert_row( 0 ) ;
} else {
prep_feed_count() ;
insert_row( 1 ) ;
}
for( net = 1 ; net <= numnets ; net++ ) {
if( (netptr = netarray[net]->netptr) == NETNULL ) {
	continue ;
}
for( i = 0 ; i <= numRows + 1 ; i++ ) {
	row_map[ i ][ RITE_MOST ] = NO_PINS ;
	row_map[ i ][ FEED_FLAG ] = NOT_DONE ;
}
for( ; netptr != NETNULL ; netptr = netptr->nterm ) {
	cellptr = carray[netptr->cell] ;
	if( netptr->cell > numcells &&
		       (cellptr->padside == L ||
			cellptr->padside == ML ||
			cellptr->padside == MUL ||
			cellptr->padside == MLL ||
			cellptr->padside == R ||
			cellptr->padside == MR ||
			cellptr->padside == MUR ||
			cellptr->padside == MLR) ) {
	    continue ;
	}
	row = netptr->row ;
	row_map[ row ][ RITE_MOST ] = netptr->xpos ;
	if( row_map[ row ][ FEED_FLAG ] == NOT_DONE ) {
	    row_map[ row ][ FEED_FLAG ] =
				feed_situation( row , net ) ;
	}
}
botrow = 0 ;
toprow = numRows + 1 ;
for( ; botrow <= numRows + 1 ; botrow++ ) {
	if( row_map[ botrow ][ RITE_MOST ] != NO_PINS ) {
	    break ;
	}
}
for( ; toprow >= 0 ; toprow-- ) {
	if( row_map[ toprow ][ RITE_MOST ] != NO_PINS ) {
	    break ;
	}
}
orig_toprow = toprow ;
orig_botrow = botrow ;
netptr = netarray[net]->netptr ;
for( ; netptr != NETNULL ; netptr = netptr->nterm ) {
	if( netptr->cell <= numcells ) {
	    continue ;
	}
	cellptr = carray[netptr->cell] ;
	if( cellptr->padside != L &&
		    cellptr->padside != ML &&
		    cellptr->padside != MUL &&
		    cellptr->padside != MLL &&
		    cellptr->padside != R &&
		    cellptr->padside != MR &&
		    cellptr->padside != MUR &&
		    cellptr->padside != MLR ) {
	    continue ;
	}
	row = netptr->row ;
	if( row <= orig_toprow && row >= orig_botrow ) {
	    continue ;
	}
	if( row > toprow ) {
	    toprow = row ;
	}
	if( row < botrow ) {
	    botrow = row ;
	}
	row_map[ row ][ RITE_MOST ] = netptr->xpos ;
	if( row_map[ row ][ FEED_FLAG ] == NOT_DONE ) {
	    row_map[ row ][ FEED_FLAG ] = feed_situation( row , net ) ;
	}
}
if( toprow != botrow ) {
	row = toprow ;
	TOP_ROW_FOR_NET = YES ;
	for( row-- ; row >= botrow ; row-- ) {
	    if( row_map[ row ][ RITE_MOST ] == NO_PINS ) {
		continue ;
	    }
	    if( TOP_ROW_FOR_NET == YES ) {
		if( row_map[ toprow ][ FEED_FLAG ] == 1 ||
			    row_map[ toprow ][ FEED_FLAG ] == 3 ) {
		    feeds_in_row[toprow]++ ;
		    xfeeds_in_row[toprow]++ ;
		}
	    }
	    if( row > botrow ) {
		if( row_map[row][ FEED_FLAG ] != 4 ) {
		    feeds_in_row[row]++ ;
		    xfeeds_in_row[row]++ ;
		}
	    }
	    if( row == botrow ) {
		if( row_map[botrow][ FEED_FLAG ] == 2 ||
			     row_map[botrow][ FEED_FLAG ] == 3 ) {
		    feeds_in_row[botrow]++ ;
		    xfeeds_in_row[botrow]++ ;
		}
	    }
	    check = toprow - row - 1 ;
	    if( check != 0 ) {
		for( a = toprow - 1 ; a > row ; a--){
		    feeds_in_row[a]++ ;
		    xfeeds_in_row[a]++ ;
		}
	    }
	    toprow = row ;
	    TOP_ROW_FOR_NET = NO ;
	}
} else {
	if( row_map[toprow][ FEED_FLAG ] == 3 ) {
	    feeds_in_row[toprow]++ ;
	    xfeeds_in_row[toprow]++ ;
	}
}
}
est_fds = 0 ;
for( row = 1 ; row <= numRows ; row++ ) {
if( xfeeds_in_row[row] > 0 ) {
	est_fds += xfeeds_in_row[row] ;
}
value = (feeds_in_row[row] * fdWidth) / binWidth ;
if( feeds_in_row[row] > 0 ) {
	feeds_in_row[row] = 1 + value ;
} else {
	feeds_in_row[row] = 0 ;
}
}
value = 0 ;
for( row = 1 ; row <= numRows ; row++ ) {
value += feeds_in_row[row] ;
}
return( value * binWidth ) ;
}
prep_feed_count_1()
{
TEBOXPTR pinptr  ;
int cell , corient , offset , row ;
double total_row_len ;
total_row_len = 0 ;
for( row = 1 ; row <= numRows ; row++ ) {
total_row_len += (double) barray[row]->blength ;
}
feeds_in_row = (int *) safe_malloc( (1 + numRows) * sizeof(int) );
xfeeds_in_row = (int *) safe_malloc( (1 + numRows) * sizeof(int) );
offset = - (int)((double) implicit_feed_count * 0.90) ;
for( row = 1 ; row <= numRows ; row++ ) {
feeds_in_row[row] = (int)( (double) offset *
	    ((double)(barray[row]->blength) / total_row_len) ) ;
xfeeds_in_row[row] = 0 ;
}
for( cell = 1; cell <= numcells + numterms; cell++){
if( cell <= numcells ) {
	pinptr = carray[cell]->tileptr->termsptr ;
	corient = carray[cell]->corient ;
	for( ; pinptr != TERMNULL ; pinptr = pinptr->nextterm ) {
	    tearray[pinptr->cellterm]->unequiv = pinptr->ue ;
	    tearray[pinptr->cellterm]->cell = cell ;
	    if( ABS( pinptr->typos[ corient%2 ]) > 1 ) {
		if( pinptr->typos[ corient%2 ] > 0 ) {
		    tearray[pinptr->cellterm]->pinloc = 1 ;
		} else {
		    tearray[pinptr->cellterm]->pinloc = -1 ;
		}
	    } else {
		tearray[pinptr->cellterm]->pinloc = 0 ;
	    }
	}
} else if( cell > numcells ) {
	pinptr = carray[cell]->tileptr->termsptr ;
	for( ; pinptr != TERMNULL ; pinptr = pinptr->nextterm ) {
	    tearray[pinptr->cellterm]->unequiv = pinptr->ue ;
	    tearray[pinptr->cellterm]->cell = cell ;
	    tearray[pinptr->cellterm]->pinloc = 0 ;
	}
}
}
return ;
}
prep_feed_count()
{
TEBOXPTR pinptr  ;
int cell , corient , offset , row ;
double total_row_len ;
total_row_len = 0 ;
for( row = 1 ; row <= numRows ; row++ ) {
total_row_len += (double) barray[row]->blength ;
}
offset = - (int)((double) implicit_feed_count * 0.90) ;
for( row = 1 ; row <= numRows ; row++ ) {
feeds_in_row[row] = (int)( (double) offset *
	    ((double)(barray[row]->blength) / total_row_len) ) ;
xfeeds_in_row[row] = 0 ;
}
for( cell = 1; cell <= numcells ; cell++){
pinptr = carray[cell]->tileptr->termsptr ;
corient = carray[cell]->corient ;
for( ; pinptr != TERMNULL ; pinptr = pinptr->nextterm ) {
	if( ABS( pinptr->typos[ corient%2 ]) > 1 ) {
	    if( pinptr->typos[ corient%2 ] > 0 ) {
		tearray[pinptr->cellterm]->pinloc = 1 ;
	    } else {
		tearray[pinptr->cellterm]->pinloc = -1 ;
	    }
	} else {
	    tearray[pinptr->cellterm]->pinloc = 0 ;
	}
}
}
return ;
}
insert_row( flag )
int flag ;
{
TEBOXPTR pinptr ;
int row , cell , pad ;
int yc , yb , blk ;
for( cell = 1 ; cell <= numcells ; cell++ ) {
row = carray[cell]->cblock ;
pinptr = carray[cell]->tileptr->termsptr ;
for( ; pinptr != TERMNULL ; pinptr = pinptr->nextterm ) {
	tearray[pinptr->cellterm]->row = row ;
}
}
if( flag == 0 ) {
for( pad = numcells + 1 ; pad <= numcells + numterms ; pad++ ) {
	if( carray[pad]->padside == 2 || carray[pad]->padside == MTT ) {
	    row = numRows + 1 ;
	    pinptr = carray[pad]->tileptr->termsptr ;
	    for( ; pinptr != TERMNULL ; pinptr = pinptr->nextterm ) {
		tearray[pinptr->cellterm]->row = row ;
	    }
	} else if(carray[pad]->padside == B ||
					carray[pad]->padside == MBB){
	    row = 0 ;
	    pinptr = carray[pad]->tileptr->termsptr ;
	    for( ; pinptr != TERMNULL ; pinptr = pinptr->nextterm ) {
		tearray[pinptr->cellterm]->row = row ;
	    }
	} else {
	    pinptr = carray[pad]->tileptr->termsptr ;
	    for( ; pinptr != TERMNULL ; pinptr = pinptr->nextterm ) {
		yc = carray[pad]->cycenter + pinptr->typos[1] ;
		for( blk = 1 ; blk <= numRows ; blk++ ) {
		    if( rowArray[blk].ypos >= yc ) {
			break ;
		    }
		}
		if( blk == 1 ) {
		    row = 1 ;
		} else if( blk > numRows ) {
		    row = numRows ;
		} else {
		    yb = rowArray[blk].ypos ;
		    if( yb - yc < yc - rowArray[blk - 1].ypos ) {
			row = blk ;
		    } else {
			row = blk - 1 ;
		    }
		}
		tearray[pinptr->cellterm]->row = row ;
	    }
	}
}
}
return ;
}
feed_situation( row , net )
int row , net ;
{
NBOXPTR nptr ;
CBOXPTR cellptr ;
int pinup, pindown , pinloc ;
pinup   = 0 ;
pindown = 0 ;
nptr = netarray[net]->netptr;
for( ; nptr != NETNULL; nptr = nptr->nterm ) {
if( nptr->row != row || nptr->unequiv == 1 ) {
	continue ;
}
cellptr = carray[nptr->cell] ;
if( nptr->cell > numcells &&
		   (cellptr->padside == L ||
		    cellptr->padside == ML ||
		    cellptr->padside == MUL ||
		    cellptr->padside == MLL ||
		    cellptr->padside == R ||
		    cellptr->padside == MR ||
		    cellptr->padside == MUR ||
		    cellptr->padside == MLR) ) {
	continue ;
}
pinloc = nptr->pinloc ;
if( pinloc == 0 ) {
	return(4) ;
}
if( pinloc > 0 ) {
	pinup = 1 ;
} else {
	pindown = 1 ;
}
}
if( pinup == 1 && pindown == 0 ) {
return(1) ;
} else if( pinup == 0 && pindown == 1 ) {
return(2) ;
} else if( pinup == 1 && pindown == 1 ) {
return(3) ;
} else {
return(0);
}
}
/* 当前文件是D:\Read\date.c*/

/* 当前文件是D:\Read\date.h*/

#define DATE "Mon Jan 25 18:50:36 EST 1988"
char *getCompileDate()
{
char *strclone() ;
return(strclone(DATE));
}
/* 当前文件是D:\Read\debug.c*/

cellbox_data( first_cell , last_cell )
int first_cell , last_cell ;
{
FILE *fp ;
CBOXPTR ptr ;
int cell ;
fp = twopen( "debug.cellbox" , "a", ABORT ) ;
fprintf(fp," cell xcenter ycenter corient padside left right\n" ) ;
for( cell = first_cell ; cell <= last_cell ; cell++ ) {
ptr = carray[ cell ] ;
fprintf( fp , "%5d  %6d  %6d      %2d      %2d %4d  %4d\n" ,
	cell , ptr->cxcenter , ptr->cycenter , ptr->corient ,
	ptr->padside , ptr->tileptr->left , ptr->tileptr->right ) ;
}
twclose( fp ) ;
}
cellterm_data( first_cell , last_cell )
int first_cell , last_cell ;
{
FILE *fp ;
CBOXPTR ptr ;
TEBOXPTR termptr ;
NBOXPTR ttermptr ;
int cell , corient ;
fp = twopen( "debug.cellterm" , "a", ABORT ) ;
for( cell = first_cell ; cell <= last_cell ; cell++ ) {
fprintf(fp,"\n cell xcenter ycenter corient padside left right\n");
ptr = carray[ cell ] ;
corient = ptr->corient ;
fprintf( fp , "%5d  %6d  %6d      %2d      %2d %4d  %4d\n" ,
	cell , ptr->cxcenter , ptr->cycenter , corient ,
	ptr->padside , ptr->tileptr->left , ptr->tileptr->right ) ;
fprintf(fp,"   pin  net   tx   ty   xpos   ypos   newx   newy ") ;
fprintf(fp,"loc ue flag\n" ) ;
if( cell <= numcells ) {
	for( termptr = ptr->tileptr->termsptr ; termptr != TERMNULL ;
					termptr = termptr->nextterm ) {
	    ttermptr = tearray[termptr->cellterm] ;
	    fprintf(fp," %5d %4d %4d %4d %6d %6d %6d %6d %3d %2d  %2d\n"
		, termptr->cellterm , ttermptr->net ,
		termptr->txpos[ corient/2 ] ,
		termptr->typos[ corient%2 ] , ttermptr->xpos ,
		ttermptr->ypos , ttermptr->newx , ttermptr->newy ,
		ttermptr->pinloc , ttermptr->unequiv , ttermptr->flag );
	}
} else {
	for( termptr = ptr->tileptr->termsptr ; termptr != TERMNULL ;
					termptr = termptr->nextterm ) {
	    ttermptr = tearray[termptr->cellterm] ;
	    fprintf(fp," %5d %4d %4d %4d %6d %6d %6d %6d %3d %2d  %2d\n"
		, termptr->cellterm , ttermptr->net ,termptr->txpos[ 1 ]
		, termptr->typos[ 1 ] , ttermptr->xpos ,
		ttermptr->ypos , ttermptr->newx , ttermptr->newy ,
		ttermptr->pinloc , ttermptr->unequiv , ttermptr->flag );
	}
}
}
twclose( fp ) ;
}
terminal( first_net , last_net )
int first_net , last_net ;
{
FILE *fp ;
NBOXPTR netptr ;
int net ;
fp = twopen( "debug.terminal" , "a", ABORT ) ;
for( net = first_net ; net <= last_net ; net++ ) {
fprintf(fp,"net %d\n" , net ) ;
fprintf(fp," terminal  xpos  ypos  newx  newy  cell loc ue flag extint\n");
for( netptr = netarray[net]->netptr ; netptr != NETNULL ;
					netptr = netptr->nterm ) {
	fprintf(fp,"    %5d %5d %5d %5d %5d %5d %3d %2d    %1d %6d\n" ,
	    netptr->terminal , netptr->xpos , netptr->ypos ,
	    netptr->newx , netptr->newy , netptr->cell , netptr->pinloc,
	    netptr->unequiv , netptr->flag , netptr->extint ) ;
}
}
twclose( fp ) ;
}
pairCheck( first_row , last_row )
int first_row , last_row ;
{
FILE *fp ;
CBOXPTR cellptr ;
TIBOXPTR tileptr ;
int row , i , j , bin_left_edge , *Aray , cell , bin ;
int most_left , most_rite ;
fp = twopen( "dbg.pairCheck" , "a", ABORT ) ;
fprintf(fp,"cedge_binwidth = %d num_edgebin = %d\n",
			cedge_binwidth, num_edgebin ) ;
for( row = first_row ; row <= last_row ; row++ ) {
Aray = pairArray[row] ;
fprintf(fp,"\nROW %d\n" , row ) ;
fprintf(fp," total number of cells in this row = %d\n",Aray[0] ) ;
cellptr = carray[ Aray[1] ] ;
most_left = cellptr->cxcenter + cellptr->tileptr->left ;
cellptr = carray[ Aray[Aray[0]] ] ;
most_rite = cellptr->cxcenter + cellptr->tileptr->right ;
fprintf(fp," most_left is at %d most_rite is at \n",
				    most_left , most_rite ) ;
fprintf(fp,"   i  cell  left right height   top bottom\n" ) ;
for( i = 1 ; i <= Aray[0] ; i++ ) {
	cell = Aray[i] ;
	cellptr = carray[ cell ] ;
	tileptr = cellptr->tileptr ;
	fprintf(fp," %3d %5d %5d %5d %6d %5d %6d\n",
	    i , cell , tileptr->left + cellptr->cxcenter ,
	    tileptr->right + cellptr->cxcenter , cellptr->cheight ,
				tileptr->top , -tileptr->bottom ) ;
}
fprintf(fp," bin index cell bin_left_edge\n" ) ;
bin_left_edge = most_left ;
for( bin = 1 ; bin <= num_edgebin ; bin++ ) {
	j = cedgebin[row][bin] ;
	fprintf(fp," %3d %5d %4d        %5d\n" ,
	    bin , j , Aray[j] , bin_left_edge ) ;
	bin_left_edge += cedge_binwidth ;
}
}
twclose( fp ) ;
}
trackdebug( status )
int status ;
{
char filename[64] ;
int i , row , fcell , cht , fht , newtrack ;
FILE *fp ;
CHANGRDPTR gdptr , startptr , endptr ;
NBOXPTR netptr ;
fp = twopen( "trackdbg" , "a", ABORT ) ;
fprintf(fp,"\n S nS tk nt Tk rs   pin  xpos  newx  cell  fcel cht fht\n");
for( gdptr = ULgrdptr ; gdptr != URgrdptr->nextgrd ; ) {
netptr = gdptr->netptr ;
fht = fcellheight( netptr->terminal , &fcell , status ) ;
if( netptr->pinloc == 1 ) {
	cht = carray[ netptr->cell ]->tileptr->top ;
} else if( netptr->pinloc == 0 ) {
	cht = 0 ;
} else {
	cht = -carray[ netptr->cell ]->tileptr->bottom ;
}
if( status == OLD ) {
	newtrack = gdptr->tracks - ( cht + fht ) / track_spacing ;
} else {
	newtrack = gdptr->ntracks - ( cht + fht ) / track_spacing ;
}
fprintf(fp ,"%2d %2d %2d %2d %2d %2d %5d %5d %5d %5d %5d %3d %3d\n"
, gdptr->SegType , gdptr->nSegType , gdptr->tracks , gdptr->ntracks
, newtrack , ( cht + fht ) / track_spacing ,
netptr->terminal , netptr->xpos ,netptr->newx , netptr->cell ,
fcell , cht , fht ) ;
if( status == OLD ) {
	gdptr = gdptr->nextgrd ;
} else {
	gdptr = gdptr->nnextgrd ;
}
}
fprintf(fp,"\n S nS tk nt Tk rs   pin  xpos  newx  cell  fcel cht fht\n");
for( gdptr = LLgrdptr ; gdptr != LRgrdptr->nextgrd ; ) {
netptr = gdptr->netptr ;
fht = fcellheight( netptr->terminal , &fcell , status ) ;
if( netptr->pinloc == 1 ) {
	cht = carray[ netptr->cell ]->tileptr->top ;
} else if( netptr->pinloc == 0 ) {
	cht = 0 ;
} else {
	cht = -carray[ netptr->cell ]->tileptr->bottom ;
}
if( status == OLD ) {
	newtrack = gdptr->tracks - ( cht + fht ) / track_spacing ;
} else {
	newtrack = gdptr->ntracks - ( cht + fht ) / track_spacing ;
}
fprintf(fp ,"%2d %2d %2d %2d %2d %2d %5d %5d %5d %5d %5d %3d %3d\n"
, gdptr->SegType , gdptr->nSegType , gdptr->tracks , gdptr->ntracks
, newtrack , ( cht + fht ) / track_spacing ,
netptr->terminal , netptr->xpos ,netptr->newx , netptr->cell ,
fcell , cht , fht ) ;
if( status == OLD ) {
	gdptr = gdptr->nextgrd ;
} else {
	gdptr = gdptr->nnextgrd ;
}
}
twclose( fp ) ;
}
fcellheight( pin , fcell , status )
int pin , *fcell , status ;
{
CBOXPTR cellptr ;
int bin , i , *Aray , most_left , most_rite ;
int nrow , pin_x , crite , row , pinloc ;
row = tearray[pin]->row ;
pinloc = tearray[pin]->pinloc ;
if( 1 <= row  && row <= numRows ) {
nrow = row + pinloc ;
if( nrow == 0 || nrow == numChans || pinloc == 0 ) {
	*fcell = 0 ;
	return(0) ;
}
} else if( row == 0 ) {
nrow = 1 ;
} else {
nrow = numRows ;
}
Aray  = pairArray[nrow] ;
if( status == OLD ) {
pin_x = tearray[pin]->newx ;
} else {
pin_x = tearray[pin]->xpos ;
}
cellptr   = carray[ Aray[1] ] ;
most_left = cellptr->cxcenter + cellptr->tileptr->left ;
cellptr   = carray[ Aray[Aray[0]] ] ;
most_rite = cellptr->cxcenter + cellptr->tileptr->right ;
if( pin_x < most_left || pin_x > most_rite ) {
*fcell = 0 ;
return( 0 ) ;
}
bin = ( pin_x - most_left ) / cedge_binwidth + 1 ;
if( ( i = cedgebin[nrow][bin] ) == 0 ) {
*fcell = 0 ;
return( 0 ) ;
}
*fcell = Aray[i] ;
cellptr =  carray[ *fcell ] ;
crite = cellptr->tileptr->right + cellptr->cxcenter ;
while(  crite < pin_x && i < Aray[0] ) {
*fcell = Aray[++i] ;
cellptr = carray[ *fcell ] ;
crite += cellptr->clength ;
}
if( crite == pin_x && i != Aray[0] ) {
if( carray[ Aray[i+1] ]->cheight > cellptr->cheight ) {
	*fcell = Aray[i+1] ;
	cellptr = carray[ *fcell ] ;
}
}
if( 1 <= row  && row <= numRows ) {
if( pinloc == 1 ) {
	return( -cellptr->tileptr->bottom ) ;
} else {
	return( cellptr->tileptr->top ) ;
}
} else if( row == 0 ) {
return( -cellptr->tileptr->bottom ) ;
} else {
return( cellptr->tileptr->top ) ;
}
}
chan_debug( start_chan , end_chan , status )
int start_chan , end_chan , status ;
{
char filename[64] ;
int i , row , fcell , cht , fht , chan , newtrack ;
FILE *fp ;
CHANGRDPTR gdptr ;
NBOXPTR netptr ;
fp = twopen( "chandbg" , "a", ABORT ) ;
for( chan = start_chan ; chan <= end_chan ; chan++ ) {
fprintf(fp,"\n channel = %d\n" , chan ) ;
fprintf(fp,"\n S nS tk nt Tk rs   pin  xpos  newx  cell  fcel cht fht\n");
if( status == OLD ) {
gdptr = Begin[chan]->nextgrd ;
} else {
gdptr = Begin[chan]->nnextgrd ;
}
for( ; gdptr != End[chan] ; ) {
netptr = gdptr->netptr ;
fht = fcellheight( netptr->terminal , &fcell , status ) ;
if( netptr->pinloc == 1 ) {
	cht = carray[ netptr->cell ]->tileptr->top ;
} else if( netptr->pinloc == 0 ) {
	cht = 0 ;
} else {
	cht = -carray[ netptr->cell ]->tileptr->bottom ;
}
if( status == OLD ) {
	newtrack = gdptr->tracks - ( cht + fht ) / track_spacing ;
} else {
	newtrack = gdptr->ntracks - ( cht + fht ) / track_spacing ;
}
fprintf(fp ,"%2d %2d %2d %2d %2d %2d %5d %5d %5d %5d %5d %3d %3d\n"
, gdptr->SegType , gdptr->nSegType , gdptr->tracks , gdptr->ntracks
, newtrack , ( cht + fht ) / track_spacing ,
netptr->terminal , netptr->xpos ,netptr->newx , netptr->cell ,
fcell , cht , fht ) ;
if( status == OLD ) {
	gdptr = gdptr->nextgrd ;
} else {
	gdptr = gdptr->nnextgrd ;
}
}
}
twclose( fp ) ;
}
negative()
{
NBOXPTR netptr ;
CHANGRDPTR gdptr ;
int channel ;
for( channel = 1 ; channel <= numChans ; channel++ ) {
for( gdptr = Begin[ channel ]->nnextgrd ; gdptr != GRDNULL ;
					gdptr = gdptr->nnextgrd ) {
	netptr = gdptr->netptr ;
	if( gdptr->ntracks < 0 ) {
	    printf("channel   pin  xpos  newx  cell   net\n" ) ;
	    printf("    %3d %5d %5d %5d %5d %5d\n", channel ,
		netptr->terminal , netptr->xpos , netptr->newx ,
		netptr->cell , netptr->net ) ;
	}
}
}
}

/* 当前文件是D:\Read\finalwire.c*/









finalwire( )
{
DBOXPTR dimptr ;
NBOXPTR netptr ;
int x , y , net , cost=0 ;
fwirex = 0 ;
fwirey = 0 ;
for( net = 1 ; net <= numnets ; net++ ) {
dimptr =  netarray[ net ] ;
if( (netptr = dimptr->netptr) != NETNULL ) {
	dimptr->xmin = dimptr->xmax = netptr->xpos ;
	dimptr->ymin = dimptr->ymax = netptr->ypos ;
	netptr = netptr->nterm ;
}
for( ; netptr != NETNULL ; netptr = netptr->nterm ) {
	x = netptr->xpos ;
	y = netptr->ypos ;
	if( x < dimptr->xmin ) {
	    dimptr->xmin = x ;
	} else if( x > dimptr->xmax ) {
	    dimptr->xmax = x ;
	}
	if( y < dimptr->ymin ) {
	    dimptr->ymin = y ;
	} else if( y > dimptr->ymax ) {
	    dimptr->ymax = y ;
	}
}
cost += ((int)( dimptr->Hweight *
	    (double)( dimptr->xmax - dimptr->xmin))) +
	    ((int)( dimptr->Vweight *
	    (double)( dimptr->ymax - dimptr->ymin)));
fwirex += dimptr->xmax - dimptr->xmin ;
fwirey += dimptr->ymax - dimptr->ymin ;
}
fwire = cost ;
fprintf( fpo,"\nInitial Wiring Cost: %d   Final Wiring Cost: %d\n",
						iwire , fwire ) ;
if( iwire != 0 ) {
fprintf(fpo,"############## Percent Wire Cost Reduction: %d\n\n",
	    100 - (int)( (double)fwire / (double)iwire * 100.0 ) ) ;
}
fprintf( fpo,"\nInitial Wire Length: %d   Final Wire Length: %d\n",
	    (iwirex + iwirey) , (fwirex + fwirey) ) ;
if( iwirex + iwirey != 0 ) {
fprintf(fpo,"************** Percent Wire Length Reduction: %d\n\n",
100 - (int)( (double)(fwirex + fwirey) /
		 (double)(iwirex + iwirey) * 100.0 ) ) ;
}
fprintf( fpo,"\nInitial Horiz. Wire: %d   Final Horiz. Wire: %d\n",
					    iwirex , fwirex ) ;
if( iwirex != 0 ) {
fprintf(fpo,"$$$$$$$$$$$ Percent H-Wire Length Reduction: %d\n\n",
100 - (int)( (double)fwirex / (double)iwirex * 100.0 ) ) ;
}
fprintf( fpo,"\nInitial Vert. Wire: %d   Final Vert. Wire: %d\n",
					    iwirey , fwirey ) ;
if( iwirey != 0 ) {
fprintf(fpo,"@@@@@@@@@@@ Percent V-Wire Length Reduction: %d\n\n",
100 - (int)( (double)fwirey / (double)iwirey * 100.0 ) ) ;
}
}
/* 当前文件是D:\Read\findcost.c*/


findcost()
{
FILE *fp ;
TIBOXPTR tile , tileptr1 ;
CBOXPTR cellptr1 , ptr ;
DBOXPTR dimptr ;
NBOXPTR netptr , termptr ;
TEBOXPTR term  ;
BINPTR bptr ;
char filename[64] ;
int left , right , corient ;
int bin , LoBin , HiBin ;
int block , cell , net , blk ;
int startx , endx ;
int x , y , cost=0 ;
int temp , n , k , cbin ;
int net_pin_num[ 11 ] , *adjust_left ;
double deviation , factor ;
blkleft = 32000 ;
blkrite = 0      ;
adjust_left = (int *)safe_malloc( ( numblock + 1 ) * sizeof(int) ) ;
for( block = 1 ; block <= numblock ; block++ ) {
if( barray[ block ]->bxcenter + barray[ block ]->bleft <
						blkleft ) {
	blkleft = barray[ block ]->bxcenter +
					barray[ block ]->bleft ;
}
if( barray[ block ]->bxcenter +
			barray[ block ]->bright > blkrite ) {
	blkrite = barray[ block ]->bxcenter +
				    barray[ block ]->bright ;
}
adjust_left[ block ] = 32000 ;
}
binOffst = blkleft ;
max_blklength = blkrite - blkleft ;
deviation = 0 ;
temp = 0 ;
factor = 0.0 ;
for( cell = 1 ; cell <= numcells ; cell++ ) {
temp += carray[ cell ]->clength ;
}
mean_width = temp / numcells ;
for( cell = 1 ; cell <= numcells ; cell++ ) {
deviation += ( carray[ cell ]->clength - mean_width )
	       * ( carray[ cell ]->clength - mean_width ) ;
}
deviation = sqrt( deviation / numcells ) ;
binWidth  = ( int ) ( factor * deviation + mean_width ) + 1 ;
numBins = (int)( ( blkrite - binOffst ) / binWidth ) ;
if( ( blkrite - binOffst ) > ( numBins * binWidth ) ) {
numBins++ ;
}
fprintf( fpo , "numBins automatically set to:%d\n", numBins);
fprintf( fpo , "binWidth = average_cell_width + %g sigma",factor);
fprintf( fpo , "= %d\n",binWidth ) ;
fprintf( fpo , "average_cell_width is:%g\n",mean_width ) ;
fprintf( fpo , "standard deviation of cell length is:%g\n",
		deviation ) ;
	
minxspan = (int)(mean_width + 3.0 * deviation) ;
offset_limit = (int)(0.05 * mean_width *
			(double) numcells / (double) numblock ) ;
sprintf( filename , "%s.res" , cktName ) ;
fp = twopen( filename , "r", NOABORT) ;
if( !(fp) ) {
if( resume_run == YES ) {
	fprintf(fpo,"Could not use resume file: %s  ", filename ) ;
	fprintf(fpo,"since it could not be found\n");
} else {
	fprintf(fpo,"TimberWolfSC starting from the beginning\n");
}
} else if( resume_run == NO ) {
fprintf(fpo,"Use of resume file: %s was not requested\n", filename);
} else {
fprintf( fpo, "Resuming TimberWolf from previous saved ");
fprintf( fpo, "placement in %s\n", filename );
TW_oldin( fp ) ;
twclose( fp ) ;
}
sortpin() ;
for( cell = 1 ; cell <= numcells + numterms ; cell++ ) {
ptr = carray[ cell ] ;
corient = ptr->corient ;
block   = ptr->cblock  ;
tile    = ptr->tileptr ;
if( cell <= numcells ) {
	ptr->cycenter = barray[block]->bycenter ;
	if( adjust_left[block] > ptr->cxcenter + tile->left ) {
	    adjust_left[block] = ptr->cxcenter + tile->left ;
	}
	for( term = tile->termsptr ; term != TERMNULL ;
				      term = term->nextterm ) {
	    termptr = tearray[ term->cellterm ] ;
	    termptr->xpos = term->txpos[corient/2] + ptr->cxcenter;
	    termptr->ypos = term->typos[corient%2] + ptr->cycenter;
	}
} else {
	for( term = tile->termsptr ; term != TERMNULL ;
				      term = term->nextterm ) {
	    termptr = tearray[ term->cellterm ] ;
	    termptr->xpos = term->txpos[1] + ptr->cxcenter;
	    termptr->ypos = term->typos[1] + ptr->cycenter;
	}
}
}
iwirex = 0 ;
iwirey = 0 ;
for( net = 1 ; net <= numnets ; net++ ) {
dimptr =  netarray[ net ] ;
if( (netptr = dimptr->netptr) != NETNULL ) {
	dimptr->xmin = dimptr->xmax = netptr->xpos ;
	dimptr->ymin = dimptr->ymax = netptr->ypos ;
}
for( netptr = netptr->nterm ; netptr != NETNULL ;
				  netptr = netptr->nterm ) {
	x = netptr->xpos ;
	y = netptr->ypos ;
	if( x < dimptr->xmin ) {
	    dimptr->xmin = x ;
	} else if( x > dimptr->xmax ) {
	    dimptr->xmax = x ;
	}
	if( y < dimptr->ymin ) {
	    dimptr->ymin = y ;
	} else if( y > dimptr->ymax ) {
	    dimptr->ymax = y ;
	}
}
cost += ((int)( dimptr->Hweight *
	    (double)( dimptr->xmax - dimptr->xmin))) +
	    ((int)( dimptr->Vweight *
	    (double)( dimptr->ymax - dimptr->ymin)));
iwirex += dimptr->xmax - dimptr->xmin ;
iwirey += dimptr->ymax - dimptr->ymin ;
}
fprintf( fpo, "\n\n\nTHIS IS THE ROUTE COST OF THE ");
fprintf( fpo, "ORIGINAL PLACEMENT: %d\n" , cost ) ;
if( resume_run == NO ) {
for( cell = 1 ; cell <= numcells ; cell++ ) {
	ptr = carray[cell] ;
	corient = ptr->corient ;
	block   = ptr->cblock ;
	ptr->cxcenter -= adjust_left[block] -
		 barray[block]->bxcenter - barray[block]->bleft ;
	for( term = ptr->tileptr->termsptr ;
			term != TERMNULL ;  term = term->nextterm ) {
	    termptr = tearray[ term->cellterm ] ;
	    termptr->xpos = term->txpos[corient/2] + ptr->cxcenter;
	    termptr->ypos = term->typos[corient%2] + ptr->cycenter;
	}
}
}
cost = 0 ;
iwirex = 0 ;
iwirey = 0 ;
for( net = 1 ; net <= numnets ; net++ ) {
dimptr =  netarray[ net ] ;
if( (netptr = dimptr->netptr) != NETNULL ) {
	dimptr->xmin = dimptr->xmax = netptr->xpos ;
	dimptr->ymin = dimptr->ymax = netptr->ypos ;
	dimptr->Lnum = dimptr->Rnum = 1 ;
	dimptr->Bnum = dimptr->Tnum = 1 ;
	netptr = netptr->nterm ;
}
n = 1 ;
for( ; netptr != NETNULL ; netptr = netptr->nterm ) {
	x = netptr->xpos ;
	y = netptr->ypos ;
	if( x < dimptr->xmin ) {
	    dimptr->xmin = x ;
	    dimptr->Lnum = 1 ;
	} else if( x == dimptr->xmin ) {
	    dimptr->Lnum++ ;
	    if( x == dimptr->xmax ) {
		dimptr->Rnum++ ;
	    }
	} else if( x > dimptr->xmax ) {
	    dimptr->xmax = x ;
	    dimptr->Rnum = 1 ;
	} else if( x == dimptr->xmax ) {
	    dimptr->Rnum++ ;
	}
	if( y < dimptr->ymin ) {
	    dimptr->ymin = y ;
	    dimptr->Bnum = 1  ;
	} else if( y == dimptr->ymin ) {
	    dimptr->Bnum++ ;
	    if( y == dimptr->ymax ) {
		dimptr->Tnum++ ;
	    }
	} else if( y > dimptr->ymax ) {
	    dimptr->ymax = y ;
	    dimptr->Tnum = 1  ;
	} else if( y == dimptr->ymax ) {
	    dimptr->Tnum++ ;
	}
	n++ ;
}
dimptr->numpins = n ;
cost += ((int)( dimptr->Hweight *
	    (double)( dimptr->xmax - dimptr->xmin))) +
	    ((int)( dimptr->Vweight *
	    (double)( dimptr->ymax - dimptr->ymin)));
iwirex += dimptr->xmax - dimptr->xmin ;
iwirey += dimptr->ymax - dimptr->ymin ;
}
iwire = cost ;
for( n = 1 ; n <= 10 ; n++ ) {
net_pin_num[ n ] = 0 ;
}
for( net = 1 ; net <= numnets ; net++ ) {
dimptr =  netarray[ net ] ;
if( dimptr->numpins >= 10 ) {
	net_pin_num[ 10 ]++ ;
} else {
	net_pin_num[ dimptr->numpins ]++ ;
}
}
for( n = 1 ; n <= 9 ; n++ ) {
fprintf( fpo, "The number of nets with %d pin is %d\n",
n , net_pin_num[ n ] ) ;
}
fprintf( fpo, "The number of nets with 10 pin or more is %d\n",
net_pin_num[ 10 ] ) ;
binpenal = 0 ;
rowpenal = 0 ;
penalty = 0 ;
binptr = ( BINPTR ** ) safe_malloc( (numblock + 1 ) *
			      sizeof( BINPTR * ) ) ;
for( block = 1 ; block <= numblock ; block++ ) {
binptr[block] = (BINPTR * ) safe_malloc( (numBins + 1) *
				      sizeof( BINPTR ) ) ;
left  = barray[ block ]->bleft + barray[ block ]->bxcenter ;
right = barray[ block ]->bleft + barray[ block ]->bxcenter
				   + barray[ block ]->desire   ;
LoBin = SetBin( left ) ;
HiBin = SetBin( right ) ;
for( bin = 0 ; bin <= numBins ; bin++ ) {
	binptr[block][bin] = (BINBOX *) safe_malloc(
					    sizeof(BINBOX) ) ;
	binptr[block][bin]->cell = (int *)safe_malloc(
					    10 * sizeof(int) );
	bptr = binptr[block][bin] ;
	bptr->cell[0] = 0 ;
	bptr->right = binOffst + bin * binWidth ;
	bptr->left  = bptr->right - binWidth ;
	if( bin == LoBin ) {
	    bptr->penalty = left - bptr->right ;
	} else if( bin == HiBin ) {
	    bptr->penalty = bptr->left - right ;
	} else if( bin > HiBin || bin < LoBin ) {
	    bptr->penalty = 0 ;
	} else {
	    bptr->penalty = - binWidth ;
	}
}
}
for( cell = 1 ; cell <= numcells ; cell++ ) {
cellptr1 = carray[ cell ] ;
tileptr1 = cellptr1->tileptr ;
block = cellptr1->cblock ;
startx = cellptr1->cxcenter + tileptr1->left  ;
endx   = cellptr1->cxcenter + tileptr1->right ;
barray[block]->oldsize += endx - startx ;
cbin  = SetBin( cellptr1->cxcenter ) ;
LoBin = SetBin( startx ) ;
HiBin = SetBin( endx ) ;
k = ++(binptr[block][cbin]->cell[0]) ;
if( k % 10 == 0 ) {
	binptr[block][cbin]->cell = (int *) safe_realloc(
	      binptr[block][cbin]->cell, (k + 10) * sizeof( int ) ) ;
}
binptr[block][cbin]->cell[k] = cell ;
if( LoBin == HiBin ) {
	binptr[block][LoBin]->penalty +=  ( endx - startx ) ;
} else {
	bptr = binptr[block][LoBin] ;
	bptr->penalty += ( bptr->right - startx ) ;
	bptr = binptr[block][HiBin] ;
	bptr->penalty +=  ( endx - bptr->left ) ;
	if( LoBin + 1 < HiBin ) {
	    for( bin = LoBin + 1 ; bin <= HiBin - 1 ; bin++ ) {
		binptr[block][bin]->penalty += binWidth ;
	    }
	}
}
}
for( block = 1 ; block <= numblock ; block++ ) {
for( bin = 0 ; bin <= numBins ; bin++ ) {
	binpenal += ABS( binptr[block][bin]->penalty ) ;
}
}
for( blk = 1 ; blk <= numblock ; blk++ ) {
rowpenal += ABS(barray[blk]->oldsize - barray[blk]->desire) ;
}
penalty = (int)( binpenCon * (double) binpenal +
				roLenCon * (double) rowpenal ) ;
return( cost ) ;
}
/* 当前文件是D:\Read\findcostf.c*/






findcostf()
{
TIBOXPTR tile , tileptr1 ;
CBOXPTR cellptr1 , ptr ;
DBOXPTR dimptr ;
NBOXPTR netptr , termptr ;
TEBOXPTR term  ;
BINPTR bptr ;
int left , right , corient ;
int bin , LoBin , HiBin ;
int block , cell , net , blk ;
int startx , endx ;
int x , y , cost=0 ;
int n , k , cbin ;
int old_numBins ;
blkleft = 32000 ;
blkrite = 0      ;
for( block = 1 ; block <= numblock ; block++ ) {
if( barray[ block ]->bxcenter + barray[ block ]->bleft <
						blkleft ) {
	blkleft = barray[ block ]->bxcenter +
					barray[ block ]->bleft ;
}
if( barray[ block ]->bxcenter +
			barray[ block ]->bright > blkrite ) {
	blkrite = barray[ block ]->bxcenter +
				    barray[ block ]->bright ;
}
}
binOffst = blkleft ;
max_blklength = blkrite - blkleft ;
old_numBins = numBins ;
numBins = (int)( ( blkrite - binOffst ) / binWidth ) ;
if( ( blkrite - binOffst ) > ( numBins * binWidth ) ) {
numBins++ ;
}
sortpin() ;
for( cell = 1 ; cell <= numcells + numterms ; cell++ ) {
ptr = carray[ cell ] ;
corient = ptr->corient ;
block   = ptr->cblock  ;
tile    = ptr->tileptr ;
if( cell <= numcells ) {
	ptr->cycenter = barray[block]->bycenter ;
	for( term = tile->termsptr ; term != TERMNULL ;
				      term = term->nextterm ) {
	    termptr = tearray[ term->cellterm ] ;
	    termptr->xpos = term->txpos[corient/2] + ptr->cxcenter;
	    termptr->ypos = term->typos[corient%2] + ptr->cycenter;
	}
} else {
	for( term = tile->termsptr ; term != TERMNULL ;
				      term = term->nextterm ) {
	    termptr = tearray[ term->cellterm ] ;
	    termptr->xpos = term->txpos[1] + ptr->cxcenter;
	    termptr->ypos = term->typos[1] + ptr->cycenter;
	}
}
}
cost = 0 ;
for( net = 1 ; net <= numnets ; net++ ) {
dimptr =  netarray[ net ] ;
if( (netptr = dimptr->netptr) != NETNULL ) {
	dimptr->xmin = dimptr->xmax = netptr->xpos ;
	dimptr->ymin = dimptr->ymax = netptr->ypos ;
	dimptr->Lnum = dimptr->Rnum = 1 ;
	dimptr->Bnum = dimptr->Tnum = 1 ;
	netptr = netptr->nterm ;
}
for( ; netptr != NETNULL ; netptr = netptr->nterm ) {
	x = netptr->xpos ;
	y = netptr->ypos ;
	if( x < dimptr->xmin ) {
	    dimptr->xmin = x ;
	    dimptr->Lnum = 1 ;
	} else if( x == dimptr->xmin ) {
	    dimptr->Lnum++ ;
	    if( x == dimptr->xmax ) {
		dimptr->Rnum++ ;
	    }
	} else if( x > dimptr->xmax ) {
	    dimptr->xmax = x ;
	    dimptr->Rnum = 1 ;
	} else if( x == dimptr->xmax ) {
	    dimptr->Rnum++ ;
	}
	if( y < dimptr->ymin ) {
	    dimptr->ymin = y ;
	    dimptr->Bnum = 1  ;
	} else if( y == dimptr->ymin ) {
	    dimptr->Bnum++ ;
	    if( y == dimptr->ymax ) {
		dimptr->Tnum++ ;
	    }
	} else if( y > dimptr->ymax ) {
	    dimptr->ymax = y ;
	    dimptr->Tnum = 1  ;
	} else if( y == dimptr->ymax ) {
	    dimptr->Tnum++ ;
	}
}
cost += ((int)( dimptr->Hweight *
	    (double)( dimptr->xmax - dimptr->xmin))) +
	    ((int)( dimptr->Vweight *
	    (double)( dimptr->ymax - dimptr->ymin)));
}
binpenal = 0 ;
rowpenal = 0 ;
penalty = 0 ;
for( block = 1 ; block <= numblock ; block++ ) {
for( bin = 0 ; bin <= old_numBins ; bin++ ) {
	safe_free( binptr[block][bin]->cell ) ;
	safe_free( binptr[block][bin] ) ;
}
safe_free( binptr[block] ) ;
}
for( block = 1 ; block <= numblock ; block++ ) {
binptr[block] = (BINPTR * ) safe_malloc( (numBins + 1) *
				      sizeof( BINPTR ) ) ;
left  = barray[ block ]->bleft + barray[ block ]->bxcenter ;
right = barray[ block ]->bleft + barray[ block ]->bxcenter
				   + barray[ block ]->desire   ;
LoBin = SetBin( left ) ;
HiBin = SetBin( right ) ;
for( bin = 0 ; bin <= numBins ; bin++ ) {
	binptr[block][bin] = (BINBOX *) safe_malloc(
					    sizeof(BINBOX) ) ;
	binptr[block][bin]->cell = (int *)safe_malloc(
					    10 * sizeof(int) );
	bptr = binptr[block][bin] ;
	bptr->cell[0] = 0 ;
	bptr->right = binOffst + bin * binWidth ;
	bptr->left  = bptr->right - binWidth ;
	if( bin == LoBin ) {
	    bptr->penalty = left - bptr->right ;
	} else if( bin == HiBin ) {
	    bptr->penalty = bptr->left - right ;
	} else if( bin > HiBin || bin < LoBin ) {
	    bptr->penalty = 0 ;
	} else {
	    bptr->penalty = - binWidth ;
	}
}
}
installf() ;
for( cell = 1 ; cell <= numcells ; cell++ ) {
cellptr1 = carray[ cell ] ;
tileptr1 = cellptr1->tileptr ;
block = cellptr1->cblock ;
startx = cellptr1->cxcenter + tileptr1->left  ;
endx   = cellptr1->cxcenter + tileptr1->right ;
barray[block]->oldsize += endx - startx ;
cbin  = SetBin( cellptr1->cxcenter ) ;
LoBin = SetBin( startx ) ;
HiBin = SetBin( endx ) ;
k = ++(binptr[block][cbin]->cell[0]) ;
if( k % 10 == 0 ) {
	binptr[block][cbin]->cell = (int *) safe_realloc(
	      binptr[block][cbin]->cell, (k + 10) * sizeof( int ) ) ;
}
binptr[block][cbin]->cell[k] = cell ;
if( LoBin == HiBin ) {
	binptr[block][LoBin]->penalty +=  ( endx - startx ) ;
} else {
	bptr = binptr[block][LoBin] ;
	bptr->penalty += ( bptr->right - startx ) ;
	bptr = binptr[block][HiBin] ;
	bptr->penalty +=  ( endx - bptr->left ) ;
	if( LoBin + 1 < HiBin ) {
	    for( bin = LoBin + 1 ; bin <= HiBin - 1 ; bin++ ) {
		binptr[block][bin]->penalty += binWidth ;
	    }
	}
}
}
for( block = 1 ; block <= numblock ; block++ ) {
for( bin = 0 ; bin <= numBins ; bin++ ) {
	binpenal += ABS( binptr[block][bin]->penalty ) ;
}
}
for( blk = 1 ; blk <= numblock ; blk++ ) {
rowpenal += ABS(barray[blk]->oldsize - barray[blk]->desire) ;
}
penalty = (int)( binpenCon * (double) binpenal +
				roLenCon * (double) rowpenal ) ;
return( cost ) ;
}
installf()
{
int row , n , left , length , sep , i , bin ;
for( row = 1 ; row <= numRows ; row++ ) {
n = feeds_in_row[row] ;
if( n < 1 ) {
	continue ;
}
left   = barray[row]->bxcenter + barray[row]->bleft ;
length = barray[row]->bright   - barray[row]->bleft ;
sep    = (length - n * binWidth ) / (n + 1) ;
for( i = 1 ; i <= n ; i++ ) {
	bin = SetBin( left + sep * i + binWidth / 2 ) ;
	binptr[row][bin]->penalty += binWidth ;
	barray[row]->oldsize += binWidth ;
}
}
return;
}
/* 当前文件是D:\Read\findest.c*/

assignro()
{
TEBOXPTR pinptr ;
NBOXPTR tmptr ;
int row , cell , pad ;
int yc , yb , blk ;
rowgrid = ( short int ** ) safe_malloc( (numRows + 2) *
					    sizeof(short int *));
for( row = 0 ; row <= numRows + 1 ; row++ ) {
rowgrid[row] = (short int *) safe_malloc( 3 * sizeof( short int ) );
}
for( cell = 1 ; cell <= numcells ; cell++ ) {
pinptr = carray[cell]->tileptr->termsptr ;
row = blkToRow[ carray[cell]->cblock ] ;
for( ; pinptr != TERMNULL ; pinptr = pinptr->nextterm ) {
	tmptr = tearray[pinptr->cellterm] ;
	tmptr->row = row ;
}
}
for( pad = numcells + 1 ; pad <= numcells + numterms ; pad++ ) {
if( carray[pad]->padside == 2 || carray[pad]->padside == MTT ) {
	row = numRows + 1 ;
	pinptr = carray[pad]->tileptr->termsptr ;
	for( ; pinptr != TERMNULL ; pinptr = pinptr->nextterm ) {
	    tmptr = tearray[pinptr->cellterm] ;
	    tmptr->row = row ;
	}
} else if(carray[pad]->padside == B || carray[pad]->padside == MBB){
	row = 0 ;
	pinptr = carray[pad]->tileptr->termsptr ;
	for( ; pinptr != TERMNULL ; pinptr = pinptr->nextterm ) {
	    tmptr = tearray[pinptr->cellterm] ;
	    tmptr->row = row ;
	}
} else {
	pinptr = carray[pad]->tileptr->termsptr ;
	for( ; pinptr != TERMNULL ; pinptr = pinptr->nextterm ) {
	    tmptr = tearray[pinptr->cellterm] ;
	    if( no_feeds_side_nets == 1 ) {
		if( carray[pad]->padside == L ||
				    carray[pad]->padside == 3 ) {
		    netarray[ tmptr->net ]->feedflag = 1 ;
		}
	    }
	    yc = carray[pad]->cycenter + pinptr->typos[1] ;
	    for( blk = 1 ; blk <= numRows ; blk++ ) {
		if( rowArray[blk].ypos >= yc ) {
		    break ;
		}
	    }
	    if( blk == 1 ) {
		row = 1 ;
	    } else if( blk > numRows ) {
		row = numRows ;
	    } else {
		yb = rowArray[blk].ypos ;
		if( yb - yc < yc - rowArray[blk - 1].ypos ) {
		    row = blk ;
		} else {
		    row = blk - 1 ;
		}
	    }
	    tmptr->row = row ;
	}
}
}
return ;
}
reassign()
{
TEBOXPTR pinptr ;
NBOXPTR tmptr ;
int row , cell , pad ;
int yc , yb , blk ;
for( cell = 1 ; cell <= numcells ; cell++ ) {
pinptr = carray[cell]->tileptr->termsptr ;
row = blkToRow[ carray[cell]->cblock ] ;
for( ; pinptr != TERMNULL ; pinptr = pinptr->nextterm ) {
	tmptr = tearray[pinptr->cellterm] ;
	tmptr->row = row ;
}
}
for( pad = numcells + 1 ; pad <= numcells + numterms ; pad++ ) {
if( carray[pad]->padside == 2 || carray[pad]->padside == MTT ) {
	row = numRows + 1 ;
	pinptr = carray[pad]->tileptr->termsptr ;
	for( ; pinptr != TERMNULL ; pinptr = pinptr->nextterm ) {
	    tmptr = tearray[pinptr->cellterm] ;
	    tmptr->row = row ;
	}
} else if(carray[pad]->padside == B || carray[pad]->padside == MBB){
	row = 0 ;
	pinptr = carray[pad]->tileptr->termsptr ;
	for( ; pinptr != TERMNULL ; pinptr = pinptr->nextterm ) {
	    tmptr = tearray[pinptr->cellterm] ;
	    tmptr->row = row ;
	}
} else {
	pinptr = carray[pad]->tileptr->termsptr ;
	for( ; pinptr != TERMNULL ; pinptr = pinptr->nextterm ) {
	    tmptr = tearray[pinptr->cellterm] ;
	    if( no_feeds_side_nets == 1 ) {
		if( carray[pad]->padside == L ||
				    carray[pad]->padside == 2 ) {
		    netarray[ tmptr->net ]->feedflag = 1 ;
		}
	    }
	    yc = carray[pad]->cycenter + pinptr->typos[1] ;
	    for( blk = 1 ; blk <= numRows ; blk++ ) {
		if( rowArray[blk].ypos >= yc ) {
		    break ;
		}
	    }
	    if( blk == 1 ) {
		row = 1 ;
	    } else if( blk > numRows ) {
		row = numRows ;
	    } else {
		yb = rowArray[blk].ypos ;
		if( yb - yc < yc - rowArray[blk - 1].ypos ) {
		    row = blk ;
		} else {
		    row = blk - 1 ;
		}
	    }
	    tmptr->row = row ;
	}
}
}
return ;
}
int *add_to_row ;
int *length_of_row ;
/* 当前文件是D:\Read\findfeeds.c*/
findfeeds( flag )
int flag ;
{
NBOXPTR netptr , saveptr ;
int check , a ;
int net , i , row , l , r , toprow , botrow ;
int orig_toprow , orig_botrow ;
int TOP_ROW_FOR_NET , position , max_row_length ;
int first_ok , second_ok , rowb , rowt , have_to_check ;
feeds = 0 ;
if( ! flag ) {
prepglob(0) ;
impcount = 0 ;
act_feeds_in_row = (int *) safe_malloc( (1 + numRows) *
					    sizeof(int) ) ;
for( row = 1 ; row <= numRows ; row++ ) {
	act_feeds_in_row[row] = 0 ;
}
} else {
pad_line = numcells + ffeeds + add_to_row[0] ;
impfix() ;
}
feed_location = (int *) safe_malloc( (1 + numnets) * sizeof(int) );
for( net = 0 ; net <= numnets ; net++ ) {
feed_location[net] = 0 ;
}
for( net = 1 ; net <= numnets ; net++ ) {
if( netarray[net]->feedflag == 1 ) {
	continue ;
}
if( (netptr = netarray[net]->netptr) != NETNULL ) {
	for( i = 0 ; i <= numRows + 1 ; i++ ) {
	    ROW_STATS[ i ][ LEFT_MOST ] = BIG_NUMBER ;
	    ROW_STATS[ i ][ RITE_MOST ] = NO_PINS ;
	    ROW_STATS[ i ][ FEED_FLAG ] = NOT_DONE ;
	}
	for( ; netptr != NETNULL ; netptr = netptr->nterm ) {
	    if( (flag == 0 && netptr->cell > numcells) ||
		(flag == 1 && netptr->cell > pad_line) ){
		if( carray[netptr->cell]->padside == L ||
			    carray[netptr->cell]->padside == ML ||
			    carray[netptr->cell]->padside == MUL ||
			    carray[netptr->cell]->padside == MLL ||
			    carray[netptr->cell]->padside == R ||
			    carray[netptr->cell]->padside == MR ||
			    carray[netptr->cell]->padside == MUR ||
			    carray[netptr->cell]->padside == MLR ) {
		    continue ;
		} else if( netptr->nterm != NULL ) {
		    if( netptr->nterm->extint == netptr->extint ) {
			for( ; ; ) {
			    if( netptr->nterm->extint == netptr->extint ){
				if( (netptr->row > numRows &&
					netptr->ypos <= netptr->nterm->ypos) ||
				    (netptr->row < 1 &&
					netptr->ypos >= netptr->nterm->ypos) ){
				    saveptr = netptr->nterm ;
				    netptr->nterm = saveptr->nterm ;
				    del_pin( saveptr->cell ,
							saveptr->terminal ) ;
				    safe_free( saveptr ) ;
				} else {
				    if( netptr == netarray[net]->netptr ) {
					netarray[net]->netptr = netptr->nterm;
					del_pin( netptr->cell ,
							netptr->terminal ) ;
					safe_free( netptr ) ;
					netptr = netarray[net]->netptr ;
				    } else {
					saveptr = netarray[net]->netptr ;
					for( ; ; ) {
					    if( saveptr->nterm == netptr ){
						break ;
					    } else {
						saveptr = saveptr->nterm ;
					    }
					}
					saveptr->nterm = netptr->nterm ;
					del_pin( netptr->cell ,
							netptr->terminal ) ;
					safe_free( netptr ) ;
					netptr = saveptr->nterm ;
				    }
				}
				if( netptr->nterm == NULL ) {
				    break ;
				}
			    } else {
				break ;
			    }
			}
		    }
		}
	    }
	    row = netptr->row ;
	    if( netptr->xpos > ROW_STATS[row][ RITE_MOST ] ) {
		ROW_STATS[ row ][ RITE_MOST ] = netptr->xpos ;
	    }
	    if( netptr->xpos < ROW_STATS[row][ LEFT_MOST] ) {
		ROW_STATS[ row ][ LEFT_MOST] = netptr->xpos ;
	    }
	    if( ROW_STATS[ row ][ FEED_FLAG ] == NOT_DONE ) {
		ROW_STATS[ row ][ FEED_FLAG ] = detfeed( flag , row , net ) ;
	    }
	}
	botrow = 0 ;
	toprow = numRows + 1 ;
	for( ; botrow <= numRows + 1 ; botrow++ ) {
	    if( ROW_STATS[ botrow ][ RITE_MOST ] != NO_PINS ) {
		break ;
	    }
	}
	for( ; toprow >= 0 ; toprow-- ) {
	    if( ROW_STATS[ toprow ][ RITE_MOST ] != NO_PINS ) {
		break ;
	    }
	}
	
	orig_toprow = toprow ;
	orig_botrow = botrow ;
	netptr = netarray[net]->netptr ;
	for( ; netptr != NETNULL ; netptr = netptr->nterm ) {
	    if( (flag == 0 && netptr->cell <= numcells) ||
		(flag == 1 && netptr->cell <= pad_line) ){
		continue ;
	    }
	    if( carray[netptr->cell]->padside != L &&
			carray[netptr->cell]->padside != ML &&
			carray[netptr->cell]->padside != MUL &&
			carray[netptr->cell]->padside != MLL &&
			carray[netptr->cell]->padside != R &&
			carray[netptr->cell]->padside != MR &&
			carray[netptr->cell]->padside != MUR &&
			carray[netptr->cell]->padside != MLR ) {
		continue ;
	    }
	    if( netptr->nterm != NULL ) {
		if( netptr->nterm->extint == netptr->extint ) {
		    have_to_check = TRUE ;
		} else {
		    have_to_check = FALSE ;
		}
	    } else {
		have_to_check = FALSE ;
	    }
	    if( have_to_check ) {
		for( ; ; ) {
		    if( netptr->nterm->extint == netptr->extint ) {
			
			row = netptr->row ;
			if( row <= toprow && row >= botrow ) {
			    first_ok = 0 ;
			}
			if( row > toprow ) {
			    first_ok = row - toprow ;
			}
			if( row < botrow ) {
			    first_ok = botrow - row ;
			}
			row = netptr->nterm->row ;
			if( row <= toprow && row >= botrow ) {
			    second_ok = 0 ;
			}
			if( row > toprow ) {
			    second_ok = row - toprow ;
			}
			if( row < botrow ) {
			    second_ok = botrow - row ;
			}
			if( first_ok == second_ok ) {
			    first_ok = 1000000 ;
			    rowb = (netptr->row - 1 >= 0) ?
							netptr->row - 1 : 0 ;
			    rowt = (netptr->row + 1 <= numRows + 1) ?
						netptr->row + 1 : numRows + 1 ;
			    for( row = rowb ; row <= rowt ; row++ ) {
				if( ROW_STATS[row][ RITE_MOST ] == NO_PINS ) {
				    continue ;
				}
				if( netptr->xpos <=
					    ROW_STATS[row][ RITE_MOST ] &&
				    netptr->xpos >=
					    ROW_STATS[row][ LEFT_MOST ] ){
				    first_ok = 0 ;
				} else if( netptr->xpos >
					    ROW_STATS[row][ RITE_MOST ] ) {
				    if( netptr->xpos -
					    ROW_STATS[row][ RITE_MOST ] <
								first_ok){
					first_ok = netptr->xpos -
						ROW_STATS[row][ RITE_MOST ] ;
				    }
				} else {
				    if( ROW_STATS[row][ LEFT_MOST ] -
						    netptr->xpos < first_ok){
					first_ok = ROW_STATS[row][LEFT_MOST] -
								netptr->xpos ;
				    }
				}
			    }
			    second_ok = 1000000 ;
			    rowb = (netptr->nterm->row - 1 >= 0) ?
					    netptr->nterm->row - 1 : 0 ;
			    rowt = (netptr->nterm->row + 1 <= numRows + 1) ?
					    netptr->nterm->row + 1 :
					    numRows + 1 ;
			    for( row = rowb ; row <= rowt ; row++ ) {
				if( ROW_STATS[row][ RITE_MOST ] == NO_PINS ) {
				    continue ;
				}
				if( netptr->nterm->xpos <=
						ROW_STATS[row][ RITE_MOST ] &&
				    netptr->nterm->xpos >=
						ROW_STATS[row][ LEFT_MOST ] ){
				    second_ok = 0 ;
				} else if( netptr->nterm->xpos >
						ROW_STATS[row][ RITE_MOST ] ) {
				    if( netptr->nterm->xpos -
					    ROW_STATS[row][ RITE_MOST ] <
					    second_ok){
					second_ok = netptr->nterm->xpos -
						ROW_STATS[row][ RITE_MOST ] ;
				    }
				} else {
				    if( ROW_STATS[row][ LEFT_MOST ] -
					    netptr->nterm->xpos < second_ok){
					second_ok = ROW_STATS[row][LEFT_MOST] -
							netptr->nterm->xpos ;
				    }
				}
			    }
			}
			if( first_ok <= second_ok ) {
			    saveptr = netptr->nterm ;
			    netptr->nterm = saveptr->nterm ;
			    del_pin( saveptr->cell , saveptr->terminal ) ;
			    safe_free( saveptr ) ;
			} else {
			    if( netptr == netarray[net]->netptr ) {
				netarray[net]->netptr = netptr->nterm ;
				del_pin( netptr->cell , netptr->terminal ) ;
				safe_free( netptr ) ;
				netptr = netarray[net]->netptr ;
			    } else {
				saveptr = netarray[net]->netptr ;
				for( ; ; ) {
				    if( saveptr->nterm == netptr ) {
					break ;
				    } else {
					saveptr = saveptr->nterm ;
				    }
				}
				saveptr->nterm = netptr->nterm ;
				del_pin( netptr->cell , netptr->terminal ) ;
				safe_free( netptr ) ;
				netptr = saveptr->nterm ;
			    }
			}
			if( netptr->nterm == NULL ) {
			    break ;
			}
		    } else {
			break ;
		    }
		}
	    }
	
	    row = netptr->row ;
	    if( row <= orig_toprow && row >= orig_botrow ) {
		continue ;
	    }
	    if( row > toprow ) {
		toprow = row ;
	    }
	    if( row < botrow ) {
		botrow = row ;
	    }
	    if( netptr->xpos > ROW_STATS[row][ RITE_MOST ] ) {
		ROW_STATS[ row ][ RITE_MOST ] = netptr->xpos ;
	    }
	    if( netptr->xpos < ROW_STATS[row][ LEFT_MOST] ) {
		ROW_STATS[ row ][ LEFT_MOST] = netptr->xpos ;
	    }
	    if( ROW_STATS[ row ][ FEED_FLAG ] == NOT_DONE ) {
		ROW_STATS[ row ][ FEED_FLAG ] = detfeed( flag , row , net ) ;
	    }
	}
	
	if( toprow != botrow ) {
	    row = toprow ;
	    TOP_ROW_FOR_NET = YES ;
	    for( row-- ; row >= botrow ; row-- ) {
		if( ROW_STATS[ row ][ RITE_MOST ] == NO_PINS ) {
		    continue ;
		}
		l = ( ROW_STATS[toprow][ LEFT_MOST] <=
					ROW_STATS[row][ LEFT_MOST] ) ?
			ROW_STATS[toprow][ LEFT_MOST] :
					ROW_STATS[row][ LEFT_MOST] ;
		r = ( ROW_STATS[toprow][ RITE_MOST ] >=
					ROW_STATS[row][ RITE_MOST ] ) ?
			ROW_STATS[toprow][ RITE_MOST ] :
					ROW_STATS[row][ RITE_MOST ] ;
		position = (l + r) / 2 ;
		if( gate_array_special ) {
		    if( feed_location[net] == 0 ) {
			feed_location[net] = position ;
		    } else {
			position = feed_location[net];
		    }
		}
		if( TOP_ROW_FOR_NET == YES ) {
		    if( ROW_STATS[ toprow ][ FEED_FLAG ] == 1 ||
				ROW_STATS[ toprow ][ FEED_FLAG ] == 3 ) {
			if( ! nofeed[toprow] ) {
			    if( flag == 0 ) {
				if( implfeeds(toprow, position )){
				    impcount++ ;
				} else {
				    feeds++ ;
				    act_feeds_in_row[toprow]++ ;
				    if( gate_array_special == TRUE ) {
					build_feed_imp( feeds,
					    position - fdWidth / 2 ,
							    toprow ) ;
				    }
				}
			    } else {
				if( implfeeds(toprow, position ) ) {
				    addimp( toprow , net ) ;
				} else {
				    addfeed( toprow, position,
						++feeds, net ) ;
				    if( gate_array_special == TRUE ) {
					build_feed_imp( feeds,
					    position - fdWidth / 2 ,
							    toprow ) ;
				    }
				}
			    }
			}
		    }
		}
		if( row > botrow ) {
		    if( ROW_STATS[row][ FEED_FLAG ] != 4 ) {
			if( ! nofeed[row] ) {
			    if( flag == 0 ) {
				if( implfeeds(row, position ) ){
				    impcount++ ;
				} else {
				    feeds++ ;
				    act_feeds_in_row[row]++ ;
				    if( gate_array_special == TRUE ) {
					build_feed_imp( feeds,
					    position - fdWidth / 2 ,
								row ) ;
				    }
				}
			    } else {
				if( implfeeds(row, position ) ){
				    addimp( row , net ) ;
				} else {
				    addfeed( row, position ,
						++feeds, net ) ;
				    if( gate_array_special == TRUE ) {
					build_feed_imp( feeds,
					    position - fdWidth / 2 ,
								row ) ;
				    }
				}
			    }
			}
		    }
		}
		if( row == botrow ) {
		    if( ROW_STATS[botrow][ FEED_FLAG ] == 2 ||
				 ROW_STATS[botrow][ FEED_FLAG ] == 3 ) {
			if( ! nofeed[botrow] ) {
			    if( flag == 0 ) {
				if( implfeeds(botrow, position ) ){
				    impcount++ ;
				} else {
				    feeds++ ;
				    act_feeds_in_row[botrow]++ ;
				    if( gate_array_special == TRUE ) {
					build_feed_imp( feeds,
					    position - fdWidth / 2 ,
							    botrow ) ;
				    }
				}
			    } else {
				if( implfeeds(botrow, position ) ){
				    addimp( botrow , net ) ;
				} else {
				    addfeed( botrow, position ,
						++feeds, net ) ;
				    if( gate_array_special == TRUE ) {
					build_feed_imp( feeds,
					    position - fdWidth / 2 ,
							    botrow ) ;
				    }
				}
			    }
			}
		    }
		}
		check = toprow - row - 1 ;
		if( check != 0 ) {
		    for( a = toprow - 1 ; a > row ; a--){
			if( ! nofeed[a] ) {
			    if( flag == 0 ) {
				if( implfeeds(a, position ) ){
				    impcount++ ;
				} else {
				    feeds++ ;
				    act_feeds_in_row[a]++ ;
				    if( gate_array_special == TRUE ) {
					build_feed_imp( feeds,
					     position - fdWidth / 2 , a);
				    }
				}
			    } else {
				if( implfeeds(a, position ) ){
				    addimp( a , net ) ;
				} else {
				    addfeed( a, position ,
						++feeds, net ) ;
				    if( gate_array_special == TRUE ) {
					build_feed_imp( feeds,
					     position - fdWidth / 2 , a);
				    }
				}
			    }
			}
		    }
		}
		toprow = row ;
		TOP_ROW_FOR_NET = NO ;
	    }
	} else {
	    if( netarray[net]->feedflag == 0 ) {
		if( ROW_STATS[toprow][ FEED_FLAG ] == 3 ) {
		    if( ! nofeed[toprow] ) {
			l = ROW_STATS[toprow][ LEFT_MOST] ;
			r = ROW_STATS[toprow][ RITE_MOST ] ;
			position = (l + r) / 2 ;
			if( gate_array_special ) {
			    if( feed_location[net] == 0 ) {
				feed_location[net] = position ;
			    } else {
				position = feed_location[net];
			    }
			}
			if( flag == 0 ) {
			    if( implfeeds(toprow, position ) ) {
				impcount++ ;
			    } else {
				feeds++ ;
				act_feeds_in_row[toprow]++ ;
				if( gate_array_special == TRUE ) {
				    build_feed_imp( feeds,
					    position - fdWidth / 2 ,
							    toprow ) ;
				}
			    }
			} else {
			    if( implfeeds( toprow, position ) ) {
				addimp( toprow , net ) ;
			    } else {
				addfeed( toprow, position, ++feeds, net);
				if( gate_array_special == TRUE ) {
				    build_feed_imp( feeds,
					    position - fdWidth / 2 ,
							    toprow ) ;
				}
			    }
			}
		    }
		}
	    }
	}
}
}
if( flag == 0 ) {
ffeeds = feeds ;
for( row = 1 ; row <= numRows ; row++ ) {
	length_of_row[row] += act_feeds_in_row[row] * fdWidth;
}
max_row_length = 0 ;
for( row = 1 ; row <= numRows ; row++ ) {
	if( length_of_row[row] > max_row_length ) {
	    max_row_length = length_of_row[row] ;
	}
}
add_to_row[0] = 0 ;
for( row = 1 ; row <= numRows ; row++ ) {
	add_to_row[row] = (max_row_length - length_of_row[row]) /
							    fdWidth ;
	add_to_row[0] += add_to_row[row] ;
}
safe_free( length_of_row ) ;
if( addFeeds ) {
	prepglob(1) ;
}
} else {
impclobr() ;
last_feed = feeds ;
}
safe_free( feed_location ) ;
return( feeds ) ;
}
del_pin( cell , pin )
int cell , pin ;
{
TEBOXPTR tptr , sptr ;
carray[cell]->numterms-- ;
tptr = carray[cell]->tileptr->termsptr ;
if( tptr->cellterm == pin ) {
sptr = carray[cell]->tileptr->termsptr ;
carray[cell]->tileptr->termsptr = tptr->nextterm ;
safe_free( sptr ) ;
} else {
for( ; ; ) {
	if( tptr->nextterm->cellterm == pin ) {
	    break ;
	} else {
	    tptr = tptr->nextterm ;
	}
}
sptr = tptr->nextterm ;
tptr->nextterm = sptr->nextterm ;
safe_free( sptr ) ;
}
return ;
}
fixwolf( nfeed )
int nfeed ;
{
CBOXPTR *newarray , ptr ;
int i , j , n ;
n = numcells ;
newarray = (CBOXPTR *) safe_malloc( (1 + numcells + numterms +
		    2 * numblock + nfeed) * sizeof(CBOXPTR) );
tearray = ( NBOXPTR * ) safe_realloc( tearray ,
	    (2 * (nfeed + impcount + numblock + 1) + maxterm + 1) * sizeof(NBOXPTR) );
pinnames = (char **) safe_realloc( pinnames,
	    (1 + maxterm + 2 * (nfeed + impcount)) * sizeof( char * ) );
for( i = 1 ; i <= n ; i++ ) {
newarray[i] = carray[i] ;
}
for( j = n + 1 ; j <= n + nfeed ; j++ ) {
newarray[j] = ptr = (CBOXPTR) safe_malloc( sizeof( CBOX ) ) ;
ptr->corient = 0 ;
ptr->cclass  = 0 ;
if( gate_array_special ) {
	ptr->orflag  = 1 ;
} else {
	ptr->orflag  = 0 ;
}
ptr->numterms = 2 ;
ptr->tileptr = (TIBOXPTR) safe_malloc( sizeof( TIBOX ) ) ;
ptr->tileptr->termsptr = (TEBOXPTR) safe_malloc(sizeof(TEBOX));
ptr->tileptr->termsptr->cellterm = ++maxterm ;
pinnames[maxterm] = (char *) safe_malloc( 16 * sizeof( char ) ) ;
sprintf( pinnames[maxterm] , "twfeed%d" , maxterm ) ;
ptr->tileptr->termsptr->ei = maxterm ;
ptr->tileptr->termsptr->ue = 0 ;
ptr->tileptr->termsptr->nextterm = (TEBOXPTR)
					    safe_malloc(sizeof(TEBOX));
ptr->tileptr->termsptr->nextterm->nextterm = TERMNULL  ;
ptr->tileptr->termsptr->nextterm->ei = maxterm ;
ptr->tileptr->termsptr->nextterm->ue = 0 ;
ptr->tileptr->termsptr->nextterm->cellterm = ++maxterm ;
pinnames[maxterm] = (char *) safe_malloc( 16 * sizeof( char ) ) ;
sprintf( pinnames[maxterm] , "twfeed%d" , maxterm ) ;
}
for( ; i <= numcells + numterms ; i++ , j++ ) {
newarray[j] = carray[i] ;
}
safe_free( carray ) ;
carray = (CBOXPTR *)safe_realloc( newarray, (1 + numcells + numterms +
		    2 * numblock + nfeed) * sizeof(CBOXPTR) );
return ;
}
addfeed( row , pos , feednum , net )
int row , pos , feednum , net ;
{
CBOXPTR cellptr ;
TIBOXPTR tileptr ;
NBOXPTR nptr ;
TEBOXPTR termptr ;
int pin , blk , corient ;
blk = rowToBlk( row , pos ) ;
cellptr = carray[ numcells + feednum ] ;
cellptr->padside = 0 ;
cellptr->cxcenter = pos ;
cellptr->cycenter = barray[blk]->bycenter ;
cellptr->cheight  = barray[blk]->bheight  ;
cellptr->clength  = fdWidth ;
if( barray[blk]->borient == 2 ) {
cellptr->corient = 1 ;
}
tileptr = cellptr->tileptr ;
cellptr->cname = (char *) safe_malloc( 16 * sizeof( char ) ) ;
if( gate_array_special ) {
sprintf( cellptr->cname , "twfeed" ) ;
} else {
#ifdef FEED_INSTANCES
sprintf( cellptr->cname , "twfeed%d", feednum ) ;
#else
sprintf( cellptr->cname , "twfeed" ) ;
#endif
}
cellptr->cblock = blk ;
tileptr->left   = -fdWidth / 2 ;
tileptr->right  = fdWidth + tileptr->left ;
tileptr->bottom = -barray[blk]->bheight / 2 ;
tileptr->top    = barray[blk]->bheight + tileptr->bottom ;
termptr = tileptr->termsptr ;
termptr->txpos[0] = 0 ;
termptr->txpos[1] = 0 ;
corient = cellptr->corient ;
if( corient == 0 ) {
termptr->typos[0] = tileptr->top ;
termptr->typos[1] = tileptr->bottom ;
} else {
termptr->typos[0] = tileptr->bottom ;
termptr->typos[1] = tileptr->top ;
}
termptr = termptr->nextterm ;
termptr->txpos[0] = 0 ;
termptr->txpos[1] = 0 ;
if( corient == 0 ) {
termptr->typos[0] = tileptr->bottom ;
termptr->typos[1] = tileptr->top ;
} else {
termptr->typos[0] = tileptr->top ;
termptr->typos[1] = tileptr->bottom ;
}
pin = tileptr->termsptr->cellterm ;
nptr = netarray[net]->netptr ;
if( nptr == NETNULL ) {
fprintf(fpo,"no pins in net to be ");
fprintf(fpo,"connected to feed thru\n");
exit(TW_FAIL);
}
for( ; nptr->nterm != NETNULL ; nptr = nptr->nterm ) ;
nptr = nptr->nterm = (NBOXPTR) safe_malloc( sizeof(NBOX) ) ;
tearray[pin] = nptr ;
nptr->terminal = pin  ;
nptr->flag     = 0    ;
nptr->row      = row  ;
nptr->cell     = numcells + feednum ;
nptr->net      = net ;
nptr->extint   = tileptr->termsptr->ei ;
nptr->unequiv  = tileptr->termsptr->ue ;
nptr->layer    = feedLayer ;
nptr->pinloc = 1 ;
pin = tileptr->termsptr->nextterm->cellterm ;
nptr = nptr->nterm = (NBOXPTR) safe_malloc( sizeof(NBOX) ) ;
tearray[pin] = nptr ;
nptr->nterm = NETNULL ;
nptr->terminal = pin  ;
nptr->flag     = 0    ;
nptr->row      = row  ;
nptr->cell     = numcells + feednum ;
nptr->net      = net ;
nptr->extint   = tileptr->termsptr->nextterm->ei ;
nptr->unequiv  = tileptr->termsptr->nextterm->ue ;
nptr->layer    = feedLayer ;
nptr->pinloc = -1 ;
return ;
}
rowToBlk( row , pos )
int row , pos ;
{
int y , block , block1 , block2 , startx1 , endx1 , startx2 ;
int endx2 ;
y = rowArray[row].ypos ;
block1 = 0 ;
block2 = 0 ;
for( block = 1 ; block <= numblock ; block++ ) {
if( barray[block]->bycenter == y ) {
	block1 = block ;
	break ;
}
}
for( block++ ; block <= numblock ; block++ ) {
if( barray[block]->bycenter == y ) {
	block2 = block ;
	break ;
}
}
if( block1 == 0 ) {
fprintf(fpo,"rowToBlk failed to find block corresponding\n");
fprintf(fpo,"to row:%d\n", row ) ;
exit(TW_FAIL) ;
}
if( block2 == 0 ) {
block = block1 ;
} else {
startx1 = barray[block1]->bxcenter + barray[block1]->bleft ;
endx1 = barray[block1]->bxcenter + barray[block1]->bright ;
startx2 = barray[block2]->bxcenter + barray[block2]->bleft ;
endx2 = barray[block2]->bxcenter + barray[block2]->bright ;
if( pos >= startx1 && pos <= endx1 ) {
	block = block1 ;
} else if( pos >= startx2 && pos <= endx2 ) {
	block = block2 ;
} else {
	
	if( endx2 < startx1 ) {
	    if( pos - endx2 <= startx1 - pos ) {
		block = block2 ;
	    } else {
		block = block1 ;
	    }
	} else {
	    if( pos - endx1 <= startx2 - pos ) {
		block = block1 ;
	    } else {
		block = block2 ;
	    }
	}
}
}
return(block) ;
}
prepglob(degree)
int degree ;
{
TEBOXPTR pinptr  ;
int cell , corient ;
if( degree == 0 ) {
for( cell = 1; cell <= numcells + numterms; cell++){
	if( cell <= numcells ) {
	    pinptr = carray[cell]->tileptr->termsptr ;
	    corient = carray[cell]->corient ;
	    for( ; pinptr != TERMNULL ; pinptr = pinptr->nextterm ) {
		tearray[pinptr->cellterm]->extint = pinptr->ei;
		tearray[pinptr->cellterm]->unequiv= pinptr->ue;
		if( ABS( pinptr->typos[ corient%2 ]) > 1 ) {
		    if( pinptr->typos[ corient%2 ] > 0 ) {
			tearray[pinptr->cellterm]->pinloc = 1 ;
		    } else {
			tearray[pinptr->cellterm]->pinloc = -1 ;
		    }
		} else {
		    tearray[pinptr->cellterm]->pinloc = 0 ;
		}
	    }
	} else if( cell > numcells ) {
	    pinptr = carray[cell]->tileptr->termsptr ;
	    for( ; pinptr != TERMNULL ; pinptr = pinptr->nextterm ) {
		tearray[pinptr->cellterm]->cell = cell ;
		tearray[pinptr->cellterm]->extint = pinptr->ei;
		tearray[pinptr->cellterm]->unequiv = pinptr->ue;
		tearray[pinptr->cellterm]->pinloc = 0 ;
	    }
	}
}
} else {
for( cell = numcells + 1 ; cell <= numcells + numterms; cell++ ) {
	pinptr = carray[cell]->tileptr->termsptr ;
	for( ; pinptr != TERMNULL ; pinptr = pinptr->nextterm ) {
	    tearray[pinptr->cellterm]->cell = cell + ffeeds +
						add_to_row[0] ;
	}
}
}
return ;
}
detfeed( flag , row , net )
int flag ;
int row  ;
int net  ;
{
CBOXPTR cellptr ;
NBOXPTR nptr , nptr2 ;
int pinup, pindown ;
int extint , pinloc ;
pinup   = 0 ;
pindown = 0 ;
for( nptr = netarray[net]->netptr; nptr != NETNULL; nptr = nptr->nterm ){
if( nptr->row != row || nptr->unequiv == 1 ) {
	continue ;
}
if( (flag == 0 && nptr->cell > numcells) ||
	    (flag == 1 && nptr->cell > pad_line) ){
	cellptr = carray[nptr->cell] ;
	if( cellptr->padside == L ||
			cellptr->padside == ML ||
			cellptr->padside == MUL ||
			cellptr->padside == MLL ||
			cellptr->padside == R ||
			cellptr->padside == MR ||
			cellptr->padside == MUR ||
			cellptr->padside == MLR ) {
	    continue ;
	}
}
extint = nptr->extint ;
pinloc = nptr->pinloc ;
if( pinloc == 0 ) {
	return(4) ;
}
if( pinloc > 0 ) {
	pinup = 1 ;
} else {
	pindown = 1 ;
}
nptr2 = nptr->nterm ;
for( ; nptr2 != NETNULL ; nptr2 = nptr2->nterm ) {
	if( nptr2->row != row || nptr2->unequiv == 1 ) {
	    continue ;
	}
	if( (flag == 0 && nptr2->cell > numcells) ||
		(flag == 1 && nptr2->cell > pad_line) ){
	    cellptr = carray[nptr2->cell] ;
	    if( cellptr->padside == L ||
			    cellptr->padside == ML ||
			    cellptr->padside == MUL ||
			    cellptr->padside == MLL ||
			    cellptr->padside == R ||
			    cellptr->padside == MR ||
			    cellptr->padside == MUR ||
			    cellptr->padside == MLR ) {
		continue ;
	    }
	}
	if( nptr2->pinloc == 0 ) {
	    return(4) ;
	}
	if( nptr2->extint == extint ) {
	    if( nptr2->pinloc != pinloc ) {
		return(4) ;
	    }
	} else {
	    if( nptr2->pinloc > 0 ) {
		pinup = 1 ;
	    } else {
		pindown = 1 ;
	    }
	}
}
}
if( pinup == 1 && pindown == 0 ) {
return(1) ;
} else if( pinup == 0 && pindown == 1 ) {
return(2) ;
} else if( pinup == 1 && pindown == 1 ) {
return(3) ;
} else {
return(0);
}
}
/* 当前文件是D:\Read\findrchk.c*/

findrchk()
{
SEGBOXPTR segptr ;
CHANGRDPTR ptr1 , ptr2 , bptr , fptr , sptr , eptr , ptr , gdptr ;
int chan , segment ;
int pin1 , pin2 , x1 , x2 ;
int net , Flag ;
for( chan = 1 ; chan <= numChans ; chan++ ) {
for( gdptr = Begin[ chan ] ; gdptr != GRDNULL ;
				    gdptr = gdptr->nnextgrd ) {
	gdptr->ntracks = 0 ;
	gdptr->nSegType = 0 ;
}
}
for( segment = 1 ; segment <= numSegs ; segment++ ) {
if( aNetSeg[segment].key != 0 ) {
	aNetSeg[segment].current =
		aNetSeg[ aNetSeg[segment].key ].current ;
}
if( aNetSeg[segment].current == 0 ) {
	segptr = aNetSeg[segment].top ;
} else {
	segptr = aNetSeg[segment].bot ;
}
pin1 = segptr->pin1 ;
pin2 = segptr->pin2 ;
if( pin1 > maxterm && pin2 > maxterm ) {
	continue ;
}
ptr1 = segptr->pin1ptr ;
ptr2 = segptr->pin2ptr ;
x1 = ptr1->netptr->xpos ;
x2 = ptr2->netptr->xpos ;
if( x1 == x2 ) {
	continue ;
}
net = aNetSeg[segment].net ;
if( ptr1->nSegType >= 0 ) {
	Flag = 0 ;
	bptr = ptr1 ;
	while( bptr->nprevgrd != GRDNULL
		    && bptr->nprevgrd->netptr->xpos == x1 ) {
	    if( net == tearray[bptr->nprevgrd->netptr->terminal]->net
				&& bptr->nprevgrd->nSegType < 0 ) {
		Flag = 1 ;
		sptr = ptr1->nnextgrd ;
		while( sptr->netptr->xpos == x1 ) {
		    sptr = sptr->nnextgrd ;
		}
		break ;
	    } else {
		bptr = bptr->nprevgrd ;
	    }
	}
	if( !Flag ) {
	    sptr = ptr1->nnextgrd ;
	    while( sptr->netptr->xpos == x1 ) {
		if( net == tearray[sptr->netptr->terminal]->net
				    && sptr->nSegType < 0 ) {
		    Flag = 1 ;
		}
		sptr = sptr->nnextgrd ;
	    }
	}
	if( !Flag ) {
	    sptr = bptr ;
	}
} else {
	sptr = ptr1->nnextgrd ;
	while( sptr->netptr->xpos == x1 ) {
	    sptr = sptr->nnextgrd ;
	}
}
if( ptr2->nSegType <= 0 ) {
	Flag = 0 ;
	fptr = ptr2 ;
	while( fptr->nnextgrd != GRDNULL
		    && fptr->nnextgrd->netptr->xpos == x2 ) {
	    if( net == tearray[fptr->nnextgrd->netptr->terminal]->net
				&& fptr->nnextgrd->nSegType > 0 ) {
		Flag = 1 ;
		eptr = ptr2->nprevgrd ;
		while( eptr->netptr->xpos == x2 ) {
		    eptr = eptr->nprevgrd ;
		}
		break ;
	    } else {
		fptr = fptr->nnextgrd ;
	    }
	}
	if( !Flag ) {
	    eptr = ptr2->nprevgrd ;
	    while( eptr->netptr->xpos == x2 ) {
		if( net == tearray[eptr->netptr->terminal]->net
				    && eptr->nSegType > 0 ) {
		    Flag = 1 ;
		}
		eptr = eptr->nprevgrd ;
	    }
	}
	if( !Flag ) {
	    eptr = fptr ;
	}
} else {
	eptr = ptr2->nprevgrd ;
	while( eptr->netptr->xpos == x2 ) {
	    eptr = eptr->nprevgrd ;
	}
}
eptr = eptr->nnextgrd ;
for( ptr = sptr ; ptr != eptr ; ptr = ptr->nnextgrd ) {
	(ptr->ntracks)++ ;
}
if( pin1 <= maxterm ) {
	ptr1->nSegType += RIGHT ;
}
if( pin2 <= maxterm ) {
	ptr2->nSegType += LEFT ;
}
}
if( uneven_cell_height ) {
reset_ntrack( ) ;
}
for( chan = 1 ; chan <= numChans ; chan++ ) {
for( gdptr = Begin[ chan ] ; gdptr != GRDNULL ;
					gdptr = gdptr->nnextgrd ) {
	if( gdptr->tracks != gdptr->ntracks ) {
	    debug( chan , gdptr ) ;
	    return ;
	}
}
}
}
debug( chan , gdptr )
int chan ;
CHANGRDPTR gdptr ;
{
FILE *fpb ;
char filename[64] ;
NBOXPTR netptr ;
int i ;
sprintf( filename , "%s.debug" , cktName ) ;
fpb = twopen ( filename , "w", ABORT) ;
fprintf(fpb ," channel = %2d nmaxTrack = %2d maxTrack = %2d\n"
		    , chan , nmaxTrack[chan] , maxTrack[chan]) ;
fprintf(fpb,"SegType nSegType track ntrack  pin xpos newx cell  net\n");
for( i = 5 ; i >= 0 ; i-- ) {
if( gdptr->prevgrd != GRDNULL ) {
	gdptr = gdptr->prevgrd ;
}
}
for( ; i <= 12 ; i++ ) {
if( gdptr != GRDNULL ) {
	netptr = gdptr->netptr ;
	fprintf(fpb ,"%7d %8d %5d %6d %4d %4d %4d %4d %4d\n",
	gdptr->SegType , gdptr->nSegType , gdptr->tracks ,
	gdptr->ntracks , netptr->terminal , netptr->xpos ,
	netptr->newx , netptr->cell , tearray[netptr->terminal]->net );
	gdptr = gdptr->nextgrd ;
}
}
}
reset_ntrack()
{
CBOXPTR cellptr ;
TIBOXPTR tileptr ;
TEBOXPTR termptr ;
int cell , pin , pinloc , row , top , bottom ;
for( cell = 1 ; cell <= numcells ; cell++ ) {
cellptr = carray[cell] ;
tileptr = cellptr->tileptr ;
top =  tileptr->top ;
bottom = -tileptr->bottom ;
row = cellptr->cblock ;
for( termptr = tileptr->termsptr ;
	termptr != NULL ; termptr = termptr->nextterm ) {
	pin = termptr->cellterm ;
	pinloc = tearray[pin]->pinloc ;
	if( pinloc == 1 ) {
	    Tgrid[ pin ]->up->ntracks += ( top +
	    facing_cellheight( pin , row , 1 , NEW ) ) / track_spacing ;
	} else if( pinloc == -1 ) {
	    Tgrid[ pin ]->up->ntracks += ( bottom +
	    facing_cellheight( pin , row , -1 , NEW ) ) / track_spacing;
	} else {
	    Tgrid[ pin ]->up->ntracks += ( top +
	    facing_cellheight( pin , row , 1 , NEW ) ) / track_spacing ;
	    Tgrid[ pin ]->down->ntracks += ( bottom +
	    facing_cellheight( pin , row , -1 , NEW ) ) / track_spacing;
	}
}
}
for( ; cell <= numcells + numterms ; cell++ ) {
cellptr = carray[cell] ;
tileptr = cellptr->tileptr ;
for( termptr = tileptr->termsptr ; termptr != NULL ;
			    termptr = termptr->nextterm ) {
	pin = termptr->cellterm ;
	row = tearray[pin]->row ;
	Tgrid[ pin ]->up->ntracks += facing_cellheight(
		pin , row , 0 , NEW ) / track_spacing ;
}
}
}
/* 当前文件是D:\Read\findrcost.c*/

findrcost()
{
SEGBOXPTR segptr ;
CHANGRDPTR ptr1 , ptr2 , bptr , fptr , sptr , eptr , ptr , gdptr ;
DENSITYPTR denptr ;
int chan , segment ;
int track , max_trk ;
int pin1 , pin2 , x1 , x2 ;
int net , Flag ;
for( segment = 1 ; segment <= numSegs ; segment++ ) {
if( aNetSeg[segment].current == 0 ) {
	segptr = aNetSeg[segment].top ;
} else {
	segptr = aNetSeg[segment].bot ;
}
pin1 = segptr->pin1 ;
pin2 = segptr->pin2 ;
ptr1 = segptr->pin1ptr ;
ptr2 = segptr->pin2ptr ;
x1 = ptr1->netptr->xpos ;
x2 = ptr2->netptr->xpos ;
if( x1 == x2 ) {
	continue ;
}
net = aNetSeg[segment].net ;
if( ptr1->SegType >= 0 ) {
	Flag = 0 ;
	bptr = ptr1 ;
	while( bptr->prevgrd != GRDNULL
		    && bptr->prevgrd->netptr->xpos == x1 ) {
	    if( net == tearray[bptr->prevgrd->netptr->terminal]->net
				&& bptr->prevgrd->SegType < 0 ) {
		Flag = 1 ;
		sptr = ptr1->nextgrd ;
		while( sptr->netptr->xpos == x1 ) {
		    sptr = sptr->nextgrd ;
		}
		break ;
	    } else {
		bptr = bptr->prevgrd ;
	    }
	}
	if( !Flag ) {
	    sptr = ptr1->nextgrd ;
	    while( sptr->netptr->xpos == x1 ) {
		if( net == tearray[sptr->netptr->terminal]->net
				    && sptr->SegType < 0 ) {
		    Flag = 1 ;
		}
		sptr = sptr->nextgrd ;
	    }
	}
	if( !Flag ) {
	    sptr = bptr ;
	}
} else {
	sptr = ptr1->nextgrd ;
	while( sptr->netptr->xpos == x1 ) {
	    sptr = sptr->nextgrd ;
	}
}
if( ptr2->SegType <= 0 ) {
	Flag = 0 ;
	fptr = ptr2 ;
	while( fptr->nextgrd != GRDNULL
		    && fptr->nextgrd->netptr->xpos == x2 ) {
	    if( net == tearray[fptr->nextgrd->netptr->terminal]->net
				&& fptr->nextgrd->SegType > 0 ) {
		Flag = 1 ;
		eptr = ptr2->prevgrd ;
		while( eptr->netptr->xpos == x2 ) {
		    eptr = eptr->prevgrd ;
		}
		break ;
	    } else {
		fptr = fptr->nextgrd ;
	    }
	}
	if( !Flag ) {
	    eptr = ptr2->prevgrd ;
	    while( eptr->netptr->xpos == x2 ) {
		if( net == tearray[eptr->netptr->terminal]->net
				    && eptr->SegType > 0 ) {
		    Flag = 1 ;
		}
		eptr = eptr->prevgrd ;
	    }
	}
	if( !Flag ) {
	    eptr = fptr ;
	}
} else {
	eptr = ptr2->prevgrd ;
	while( eptr->netptr->xpos == x2 ) {
	    eptr = eptr->prevgrd ;
	}
}
eptr = eptr->nextgrd ;
for( ptr = sptr ; ptr != eptr ; ptr = ptr->nextgrd ) {
	(ptr->tracks)++ ;
}
if( pin1 <= maxterm ) {
	ptr1->SegType += RIGHT ;
}
if( pin2 <= maxterm ) {
	ptr2->SegType += LEFT ;
}
}
DboxHead  = ( DENSITYPTR ** )safe_calloc( sizeof( DENSITYPTR * )
						, numChans + 1 ) ;
Densebox  = ( DENSITYPTR ** )safe_calloc( sizeof( DENSITYPTR * )
						, numChans + 1 ) ;
maxTrack  = (int *)safe_malloc( ( numChans + 1 ) * sizeof( int ) ) ;
nmaxTrack = (int *)safe_malloc( ( numChans + 1 ) * sizeof( int ) ) ;
max_tdensity = 0 ;
tracks   = 0 ;
if( uneven_cell_height ) {
set_cedgebin( ) ;
reset_track( ) ;
}
for( chan = 1 ; chan <= numChans ; chan++ ) {
max_trk = 0 ;
for( gdptr = Begin[ chan ] ; gdptr != GRDNULL ;
					gdptr = gdptr->nextgrd ) {
	if( gdptr->tracks > max_trk ) {
	    max_trk = gdptr->tracks ;
	}
}
maxTrack[ chan ]   = max_trk ;
if( max_trk > max_tdensity ) {
	max_tdensity = max_trk ;
}
tracks += max_trk ;
}
for( chan = 1 ; chan <= numChans ; chan++ ) {
DboxHead[ chan ]  = ( DENSITYPTR *)safe_calloc(
		sizeof( DENSITYPTR) , max_tdensity + 101 ) ;
Densebox[ chan ]  = ( DENSITYPTR * )safe_calloc(
		sizeof( DENSITYPTR) , max_tdensity + 101 ) ;
for( track = 0 ; track <= max_tdensity + 100 ; track++ ) {
	DboxHead[ chan ][ track ] = ( DENSITYPTR )safe_calloc(
				    sizeof( DENSITYBOX ) , 1 ) ;
}
for( gdptr = Begin[ chan ] ; gdptr != GRDNULL ;
					gdptr = gdptr->nextgrd ) {
	track = gdptr->tracks ;
	if( DboxHead[ chan ][ track ]->next == NULL ) {
	    DboxHead[ chan ][ track ]->next = Densebox[ chan ][ track ]
	        = ( DENSITYPTR )safe_calloc( sizeof( DENSITYBOX ) , 1 );
	    Densebox[ chan ][ track ]->back = DboxHead[ chan ][ track ];
	    Densebox[ chan ][ track ]->grdptr = gdptr ;
	    gdptr->dptr = Densebox[ chan ][ track ] ;
	} else {
	    denptr = Densebox[ chan ][ track ]->next =
		( DENSITYPTR )safe_calloc( sizeof( DENSITYBOX ) , 1 );
	    denptr->back = Densebox[ chan ][ track ] ;
	    denptr->grdptr = gdptr ;
	    gdptr->dptr = denptr ;
	    Densebox[ chan ][ track ] = denptr ;
	}
}
}
}
set_cedgebin()
{
CBOXPTR cellptr ;
int channel , row , bin , bin_rite_edge , cleft , crite ;
int most_left , most_rite , rite , i ;
cedgebin = (int **)safe_malloc( ( numChans + 1 ) * sizeof(int *) ) ;
cedge_binwidth = (int)( 2.0 * mean_width ) ;
cellptr = carray[ pairArray[1][ pairArray[1][0] ] ] ;
most_rite = cellptr->cxcenter + cellptr->tileptr->right ;
for( row = 2 ; row <= numRows ; row++ ) {
cellptr = carray[ pairArray[row][ pairArray[row][0] ] ] ;
rite = cellptr->cxcenter + cellptr->tileptr->right ;
if( rite > most_rite ) {
	most_rite = rite ;
}
}
num_edgebin = ( most_rite - blkleft ) / cedge_binwidth + 1 ;
for( channel = 1 ; channel <= numChans ; channel++ ) {
cedgebin[ channel ] = (int *)safe_malloc(
		( num_edgebin + 1 ) * sizeof( int ) ) ;
}
for( row = 1 ; row <= numRows ; row++ ) {
cellptr = carray[ pairArray[row][1] ] ;
most_left = cellptr->cxcenter + cellptr->tileptr->left ;
bin_rite_edge = most_left + cedge_binwidth ;
cedgebin[row][1] = 1 ;
bin = 1 ;
for( i = 1 ; i <= pairArray[row][0] ; i++ ) {
	cellptr = carray[ pairArray[row][i] ] ;
	crite = cellptr->cxcenter + cellptr->tileptr->right ;
	if( bin_rite_edge < crite ) {
	    while( bin_rite_edge <= crite ) {
		cedgebin[row][++bin] = i ;
		bin_rite_edge += cedge_binwidth ;
	    }
	}
}
for( ++bin ; bin <= num_edgebin ; bin++ ) {
	cedgebin[row][bin] = 0 ;
}
}
}
reset_track()
{
CBOXPTR cellptr ;
TIBOXPTR tileptr ;
TEBOXPTR termptr ;
int cell , pin , pinloc , row , top , bottom ;
for( cell = 1 ; cell <= numcells ; cell++ ) {
cellptr = carray[cell] ;
tileptr = cellptr->tileptr ;
row =  cellptr->cblock ;
top =  tileptr->top ;
bottom = -tileptr->bottom ;
for( termptr = tileptr->termsptr ;
	termptr != TERMNULL ; termptr = termptr->nextterm ) {
	pin = termptr->cellterm ;
	pinloc = tearray[pin]->pinloc ;
	if( pinloc == 1 ) {
	    Tgrid[ pin ]->up->tracks += ( top +
	    facing_cellheight( pin , row , 1 , NEW ) ) / track_spacing ;
	} else if( pinloc == -1 ) {
	    Tgrid[ pin ]->up->tracks += ( bottom +
	    facing_cellheight( pin , row , -1 , NEW ) ) / track_spacing;
	} else {
	    Tgrid[ pin ]->up->tracks += ( top +
	    facing_cellheight( pin , row , 1 , NEW ) ) / track_spacing ;
	    Tgrid[ pin ]->down->tracks += ( bottom +
	    facing_cellheight( pin , row , -1 , NEW ) ) / track_spacing;
	}
}
}
for( ; cell <= numcells + numterms ; cell++ ) {
cellptr = carray[cell] ;
tileptr = cellptr->tileptr ;
for( termptr = tileptr->termsptr ; termptr != TERMNULL ;
			    termptr = termptr->nextterm ) {
	pin = termptr->cellterm ;
	row = tearray[ pin ]->row ;
	Tgrid[ pin ]->up->tracks += facing_cellheight(
		pin , row , 0 , NEW ) / track_spacing ;
}
}
}
facing_cellheight( pin , row , pinloc , status )
int pin, row , pinloc , status ;
{
CBOXPTR cellptr ;
int bin , i , *Aray , most_left , most_rite ;
int nrow , pin_x , crite ;
if( 1 <= row  && row <= numRows ) {
nrow = row + pinloc ;
if( nrow == 0 || nrow == numChans || pinloc == 0 ) {
	return(0) ;
}
} else if( row == 0 ) {
nrow = 1 ;
} else {
nrow = numRows ;
}
Aray  = pairArray[nrow] ;
if( status == OLD ) {
pin_x = tearray[pin]->newx ;
} else {
pin_x = tearray[pin]->xpos ;
}
cellptr   = carray[ Aray[1] ] ;
most_left = cellptr->cxcenter + cellptr->tileptr->left ;
cellptr   = carray[ Aray[Aray[0]] ] ;
most_rite = cellptr->cxcenter + cellptr->tileptr->right ;
if( pin_x < most_left || pin_x > most_rite ) {
return( 0 ) ;
}
bin = ( pin_x - most_left ) / cedge_binwidth + 1 ;
if( ( i = cedgebin[nrow][bin] ) == 0 ) {
return( 0 ) ;
}
cellptr =  carray[ Aray[i] ] ;
if( ( ( cellptr->tileptr->left + cellptr->cxcenter ) == pin_x )
					    && ( bin >= 2 ) ) {
if( carray[ Aray[i-1] ]->cheight > cellptr->cheight ) {
	cellptr = carray[ Aray[--i] ] ;
}
} else {
crite = cellptr->tileptr->right + cellptr->cxcenter ;
while(  crite < pin_x && i < Aray[0] ) {
	cellptr = carray[ Aray[++i] ] ;
	crite += cellptr->clength ;
}
if( crite == pin_x && i != Aray[0] ) {
	if( carray[ Aray[i+1] ]->cheight > cellptr->cheight ) {
	    cellptr = carray[ Aray[i+1] ] ;
	}
}
}
if( 1 <= row  && row <= numRows ) {
if( pinloc == 1 ) {
	return( -cellptr->tileptr->bottom ) ;
} else {
	return( cellptr->tileptr->top ) ;
}
} else if( row == 0 ) {
return( -cellptr->tileptr->bottom ) ;
} else {
return( cellptr->tileptr->top ) ;
}
}
/* 当前文件是D:\Read\findunlap.c*/


findunlap( before_feeds )
int before_feeds ;
{
CBOXPTR cellptr , ptr ;
TIBOXPTR tileptr ;
TEBOXPTR term ;
DBOXPTR dimptr ;
NBOXPTR termptr , netptr ;
int cost , corient ;
int block , cell , bin ;
int i , n ;
int bigblkx ;
int net , x , y , *blklen , row ;
blklen = (int *) safe_malloc( (numblock + 1) * sizeof( int ) ) ;
for( i = 0 ; i <= numblock ; i++ ) {
blklen[i]  = 0 ;
}
if( before_feeds == 1 ) {
unlap(1) ;
} else if( before_feeds == 0 ) {
unlap(0) ;
}
if( before_feeds == 1 ) {
for( block = 1 ; block <= numblock ; block++ ) {
	for( bin = 0 ; bin <= numBins ; bin++ ) {
	    safe_free( binptr[ block ][ bin ]->cell ) ;
	    safe_free( binptr[ block ][ bin ] ) ;
	}
	safe_free( binptr[ block ] ) ;
}
safe_free( binptr ) ;
}
for( cell = 1 ; cell <= numcells ; cell++ ) {
ptr = carray[ cell ] ;
corient = ptr->corient ;
for( term = ptr->tileptr->termsptr ; term != TERMNULL ;
				  term = term->nextterm ) {
	termptr = tearray[ term->cellterm ] ;
termptr->xpos = term->txpos[ corient/2 ] + ptr->cxcenter;
termptr->ypos = term->typos[ corient%2 ] + ptr->cycenter;
}
}
for( cell = numcells + 1 ; cell <= numcells + numterms ; cell++ ) {
ptr = carray[ cell ] ;
for( term = ptr->tileptr->termsptr ; term != TERMNULL ;
				  term = term->nextterm ) {
	termptr = tearray[ term->cellterm ] ;
termptr->xpos = term->txpos[ 1 ] + ptr->cxcenter;
termptr->ypos = term->typos[ 1 ] + ptr->cycenter;
}
}
cost  = 0 ;
for( net = 1 ; net <= numnets ; net++ ) {
dimptr =  netarray[ net ] ;
if( (netptr = dimptr->netptr) != NETNULL ) {
	dimptr->xmin = dimptr->xmax = netptr->xpos ;
	dimptr->ymin = dimptr->ymax = netptr->ypos ;
	dimptr->Lnum = dimptr->Rnum = 1 ;
	dimptr->Bnum = dimptr->Tnum = 1 ;
	netptr = netptr->nterm ;
}
n = 1 ;
for( ; netptr != NETNULL ; netptr = netptr->nterm ) {
	x = netptr->xpos ;
	y = netptr->ypos ;
	if( x < dimptr->xmin ) {
	    dimptr->xmin = x ;
	    dimptr->Lnum = 1 ;
	} else if( x == dimptr->xmin ) {
	    dimptr->Lnum++ ;
	    if( x == dimptr->xmax ) {
		dimptr->Rnum++ ;
	    }
	} else if( x > dimptr->xmax ) {
	    dimptr->xmax = x ;
	    dimptr->Rnum = 1 ;
	} else if( x == dimptr->xmax ) {
	    dimptr->Rnum++ ;
	}
	if( y < dimptr->ymin ) {
	    dimptr->ymin = y ;
	    dimptr->Bnum = 1  ;
	} else if( y == dimptr->ymin ) {
	    dimptr->Bnum++ ;
	    if( y == dimptr->ymax ) {
		dimptr->Tnum++ ;
	    }
	} else if( y > dimptr->ymax ) {
	    dimptr->ymax = y ;
	    dimptr->Tnum = 1  ;
	} else if( y == dimptr->ymax ) {
	    dimptr->Tnum++ ;
	}
	n++ ;
}
dimptr->numpins = n ;
cost += ((int)( dimptr->Hweight *
	    (double)( dimptr->xmax - dimptr->xmin))) +
	    ((int)( dimptr->Vweight *
	    (double)( dimptr->ymax - dimptr->ymin)));
}
funccost = cost ;
for( cell = 1 ; cell <= numcells ; cell++ ) {
cellptr = carray[ cell ] ;
tileptr = cellptr->tileptr ;
block    = cellptr->cblock ;
blklen[ block ] += tileptr->right - tileptr->left  ;
}
if( before_feeds == 1 ) {
length_of_row = (int *) safe_malloc( (numRows+1) * sizeof(int) );
add_to_row = (int *) safe_malloc( (numRows+1) * sizeof(int) );
for( row = 1 ; row <= numRows ; row++ ) {
	length_of_row[row] = blklen[row] ;
	add_to_row[row] = 0 ;
}
}
if( before_feeds >= 0 ) {
bigblkx = 0 ;
if( before_feeds == 1 ) {
	fprintf(fpo,"Before Feeds are Added:\n");
}
fprintf(fpo,"BLOCK      TOTAL CELL LENGTHS      OVER/UNDER TARGET\n");
for( i = 1 ; i <= numblock ; i++ ) {
	if( blklen[i] > blklen[ bigblkx ] ) {
	    bigblkx = i ;
	}
	fprintf( fpo, "%3d            %7d                %6d\n", i,
			blklen[i] ,  (blklen[i] - barray[i]->desire) );
}
fprintf( fpo, "\nLONGEST Block is:%d   Its length is:%d\n",
				bigblkx , blklen[ bigblkx ] ) ;
}
safe_free( blklen ) ;
return ;
}
/* 当前文件是D:\Read\globe.c*/

globe()
{
FILE *twfile ;
NBOXPTR netptr , net_ptr ;
CBOXPTR cellptr1 , cellptr2 ;
char filename[64] ;
int group1 , group2 , edge , i , pin , net , group , jj ;
int cell , cx , cl , cr , top , extint , block , locX , locY ;
int flag1 , flag2 , xstart , xstop ;
int found, type1 ;
int unequiv ;
int added_an_edge , ue_grp , g1 , g2 , ei1 , ei2 , edge2 , done ;
int ei , cell1 , cell2 ;
int a1 , b1 , a2 , b2 , edge1 , ya , yb ;
int max_group , max_size , size , max_local_group ;
int single_pin1 , single_pin2 , unequiv1 , unequiv2 ;
max_group = 2 ;
max_size = 2 ;
for( net = 1 ; net <= numnets ; net++ ) {
net_ptr = netarray[net]->netptr ;
max_local_group = 0 ;
size = 1 ;
extint = -1 ;
for( ; net_ptr != NULL ; net_ptr = net_ptr->nterm ) {
	if( net_ptr->extint != extint ) {
	    extint = net_ptr->extint ;
	    ++max_local_group ;
	    if( size > max_size ) {
		max_size = size ;
	    }
	    size = 1 ;
	} else {
	    ++size ;
	    if( net_ptr->unequiv != NO ) {
		++max_local_group ;
	    }
	}
}
if( size > max_size ) {
	max_size = size ;
}
if( max_local_group > max_group ) {
	max_group = max_local_group ;
}
}
max_group += 2 * (numRows + 2) ;
MPG = max_group ;
ME  = max_group * (max_group - 1) ;
key_queue = (int *) safe_malloc( 101 * sizeof( int ) ) ;
groupArray = (csGroup *) safe_malloc( (MPG + 1) * sizeof( csGroup ) ) ;
checkArray = (chkBox *) safe_malloc( (MPG + 1) * sizeof( chkBox ) ) ;
edgeArray  = (edgeBox *) safe_malloc( (ME + 1) * sizeof( edgeBox ) ) ;
for( i = 0 ; i <= MPG ; i++ ) {
groupArray[i].numPins = 0 ;
groupArray[i].flag    = 0 ;
groupArray[i].poison  = 0 ;
groupArray[i].unequiv = 0 ;
groupArray[i].extint  = 0 ;
groupArray[i].edge1   = 0 ;
groupArray[i].edge2   = 0 ;
groupArray[i].check   = 0 ;
groupArray[i].pinArray = (csPinBox *) safe_malloc(
			    (max_size + 1) * sizeof(csPinBox) );
}
for( i = 0 ; i <= ME ; i++ ) {
edgeArray[i].marked = 0 ;
edgeArray[i].done   = 0 ;
edgeArray[i].poison = 0 ;
}
pseudoPins = (int **) safe_malloc( (numRows + 2) * sizeof(int *) ) ;
for( jj = 0 ; jj <= numRows + 1 ; jj++ ) {
pseudoPins[jj] = (int *) safe_malloc( 2 * sizeof(int) ) ;
}
pseudoEdge = (int **) safe_malloc( (numRows + 2) * sizeof(int *) ) ;
for( jj = 0 ; jj <= numRows + 1 ; jj++ ) {
pseudoEdge[jj] = (int *) safe_malloc( 2 * sizeof(int) ) ;
}
numChans = numRows + 1 ;
xstart = 32000 ;
xstop  = 0     ;
for( cell = 1 ; cell <= numcells + numterms ; cell++ ) {
cx = carray[cell]->cxcenter ;
cl = carray[cell]->tileptr->left ;
cr = carray[cell]->tileptr->right ;
if( cx + cr > xstop ) {
	xstop = cx + cr ;
}
if( cx + cl < xstart ) {
	xstart = cx + cl ;
}
}
gxstart = xstart ;
gxstop  = xstop  ;
sprintf( filename , "%s.twf" , cktName ) ;
twfile = twopen ( filename , "w", ABORT ) ;
for( net = 1 ; net <= numnets ; net++ ) {
for( jj = 0 ; jj <= numRows + 1 ; jj++ ) {
	pseudoPins[jj][0] = 0 ;
	pseudoPins[jj][1] = 0 ;
	pseudoEdge[jj][0] = 0 ;
	pseudoEdge[jj][1] = 0 ;
}
numEdges = 0 ;
top_row = -1 ;
netptr = netarray[net]->netptr ;
for( ; netptr != NETNULL ; netptr = netptr->nterm ) {
	top     = netptr->pinloc   ;
	extint  = netptr->extint   ;
	unequiv = netptr->unequiv ;
	block   = netptr->row      ;
	if( block > top_row ) {
	    if( netptr->cell <= numcells ) {
		top_row = block ;
	    } else if( carray[netptr->cell]->padside != L &&
		       carray[netptr->cell]->padside != R ) {
		top_row = block ;
	    }
	}
	locX    = netptr->xpos     ;
	locY    = netptr->ypos     ;
	pin     = netptr->terminal ;
	found = FAILURE ;
	group = 1 ;
	while( groupArray[ group ].numPins != 0 && found == FAILURE ){
	    if( groupArray[ group ].extint == extint && unequiv == NO) {
		found = SUCCESS ;
	    } else {
		++group ;
	    }
	}
	numPins = ++(groupArray[group].numPins) ;
	groupArray[ group ].pinArray[ numPins ].xloc = locX ;
	groupArray[ group ].pinArray[ numPins ].yloc = locY ;
	groupArray[ group ].pinArray[ numPins ].top = top ;
	groupArray[ group ].pinArray[ numPins ].pin = pin ;
	if( found == FAILURE ) {
	    groupArray[ group ].aveX   = locX   ;
	    groupArray[ group ].aveY   = locY   ;
	    groupArray[ group ].extint = extint ;
	    groupArray[ group ].unequiv = unequiv ;
	    groupArray[ group ].block  = block  ;
	} else {
	
	    groupArray[ group ].aveX += locX ;
	    groupArray[ group ].aveY += locY ;
	}
}
for( group = 1; groupArray[ group ].numPins != 0 ; group++ ) {
	numPins = groupArray[ group ].numPins ;
	if( numPins > 1  ) {
	    groupArray[group].aveX /= numPins ;
	    groupArray[group].aveY /= numPins ;
	}
}
numGroups = group - 1 ;
if( numGroups == 2 ) {
	if( groupArray[1].unequiv == 1 && groupArray[2].unequiv == 1 ) {
	    for( i = 1 ; i <= numGroups ; i++ ) {
		groupArray[i].numPins = 0 ;
		groupArray[i].flag    = 0 ;
		groupArray[i].poison  = 0 ;
		groupArray[i].unequiv = 0 ;
		groupArray[i].extint  = 0 ;
		groupArray[i].edge1   = 0 ;
		groupArray[i].edge2   = 0 ;
		groupArray[i].check   = 0 ;
	    }
	    for( i = 1 ; i <= numEdges ; i++ ) {
		edgeArray[i].marked = 0 ;
		edgeArray[i].done   = 0 ;
		edgeArray[i].poison = 0 ;
	    }
	    continue ;
	}
} else if( numGroups <= 1 ) {
	for( i = 1 ; i <= numGroups ; i++ ) {
	    groupArray[i].numPins = 0 ;
	    groupArray[i].flag    = 0 ;
	    groupArray[i].poison  = 0 ;
	    groupArray[i].unequiv = 0 ;
	    groupArray[i].extint  = 0 ;
	    groupArray[i].edge1   = 0 ;
	    groupArray[i].edge2   = 0 ;
	    groupArray[i].check   = 0 ;
	}
	for( i = 1 ; i <= numEdges ; i++ ) {
	    edgeArray[i].marked = 0 ;
	    edgeArray[i].done   = 0 ;
	    edgeArray[i].poison = 0 ;
	}
	continue ;
}
qsortg((char *)(groupArray + 1), numGroups,sizeof(csGroup));
for( group = 1 ; group < numGroups ; group++ ) {
	block = groupArray[ group ].block ;
	type1 = detGroup( group ) ;
	searchG( group , type1 , block ) ;
}
for( edge1 = 1 ; edge1 <= numEdges ; edge1++ ) {
	a1 = edgeArray[edge1].group1 ;
	a2 = edgeArray[edge1].group2 ;
	if( groupArray[a1].block != groupArray[a2].block ) {
	    continue ;
	}
	for( edge2 = edge1 + 1 ; edge2 <= numEdges ; edge2++ ) {
	    b1 = edgeArray[edge2].group1 ;
	    b2 = edgeArray[edge2].group2 ;
	    if( groupArray[b1].block != groupArray[b2].block ) {
		continue ;
	    }
	    if( (groupArray[a1].unequiv == 1 &&
					groupArray[b1].unequiv == 1 &&
		    groupArray[a1].extint == groupArray[b1].extint  &&
		    groupArray[a2].extint == groupArray[b2].extint) ||
		(groupArray[a2].unequiv == 1 &&
					groupArray[b2].unequiv == 1 &&
		    groupArray[a2].extint == groupArray[b2].extint  &&
		    groupArray[a1].extint == groupArray[b1].extint)  ) {
		ya = (groupArray[a1].aveY +
					groupArray[a2].aveY) / 2 ;
		yb = (groupArray[b1].aveY +
					groupArray[b2].aveY) / 2 ;
		if( groupArray[a1].block == top_row ) {
		    if( ya < yb ) {
			if( edgeArray[edge2].cost <=
					edgeArray[edge1].cost ) {
			    edgeArray[edge2].cost =
					edgeArray[edge1].cost + 1 ;
			}
		    } else {
			if( edgeArray[edge2].cost >=
					edgeArray[edge1].cost ) {
			    edgeArray[edge2].cost =
					edgeArray[edge1].cost - 1 ;
			}
		    }
		} else {
		    if( ya < yb ) {
			if( edgeArray[edge2].cost >=
					edgeArray[edge1].cost ) {
			    edgeArray[edge2].cost =
					edgeArray[edge1].cost - 1 ;
			}
		    } else {
			if( edgeArray[edge2].cost <=
					edgeArray[edge1].cost ) {
			    edgeArray[edge2].cost =
					edgeArray[edge1].cost + 1 ;
			}
		    }
		}
		break ;
	    }
	}
}
qsorte( (char *) (edgeArray + 1) , numEdges ,
					   sizeof( edgeBox ) ) ;
for( group = 1 ; group <= numGroups ; group++ ) {
	groupArray[group].flag = group ;
}
for( edge = 1 ; edge <= numEdges ; edge++ ) {
	group1 = edgeArray[ edge ].group1 ;
	flag1  = groupArray[ group1 ].flag ;
	group2 = edgeArray[ edge ].group2 ;
	flag2  = groupArray[ group2 ].flag ;
	if( flag1 <= 0 || flag2 <= 0 || flag1 == flag2 ) {
	    continue ;
	}
	added_an_edge = NO ;
	edgeArray[ edge ].marked = 1 ;
	for( group = 1; group <= numGroups; group++ ) {
	    if( groupArray[ group ].flag == flag2 ) {
		groupArray[ group ].flag = flag1 ;
	    }
	}
	cell1 = tearray[ groupArray[group1].pinArray[1].pin ]->cell ;
	cell2 = tearray[ groupArray[group2].pinArray[1].pin ]->cell ;
	cellptr1 = carray[cell1] ;
	cellptr2 = carray[cell2] ;
	if( cell1 > numcells && cellptr1->padside != 2 &&
			        cellptr1->padside != MTT &&
			        cellptr1->padside != MBB &&
			        cellptr1->padside != B ) {
	    if( cell2 <= numcells ) {
		groupArray[group1].flag = 0 ;
	    }
	}
	if( cell2 > numcells && cellptr2->padside != 2 &&
			        cellptr2->padside != MTT &&
			        cellptr2->padside != MBB &&
			        cellptr2->padside != B ) {
	    if( cell1 <= numcells ) {
		groupArray[group2].flag = 0 ;
	    }
	}
	if( groupArray[group1].unequiv == 1 ) {
	    ei1 = groupArray[group1].extint ;
	    for( ue_grp = 1; ue_grp <= numGroups; ue_grp++ ) {
		if( ue_grp == group1 ) {
		    continue ;
		}
		if( groupArray[ue_grp].extint == ei1 ) {
		    break ;
		}
	    }
	    if( groupArray[ue_grp].flag > 0 ) {
		g1 = g2 = 0 ;
		groupArray[ue_grp].flag = -1 ;
		for( edge2 = edge + 1 ; edge2 <= numEdges ; edge2++ ) {
		    if( g2 == 0 ) {
			if( edgeArray[edge2].group1 == ue_grp ) {
			    g2 = edgeArray[edge2].group2 ;
			    if( groupArray[g2].flag < 0 ) {
				g2 = 0 ;
			    }
			    continue ;
			}
		    }
		    if( g1 == 0 ) {
			if( edgeArray[edge2].group2 == ue_grp ) {
			    g1 = edgeArray[edge2].group1 ;
			    if( groupArray[g1].flag < 0 ) {
				g1 = 0 ;
			    }
			}
		    }
		}
		if( g1 != 0 && g2 != 0 ) {
		    addEdge( g1, g2 ) ;
		    added_an_edge = YES ;
		}
	    }
	}
	if( groupArray[group2].unequiv == 1 ) {
	    ei2 = groupArray[group2].extint ;
	    for( ue_grp = 1; ue_grp <= numGroups; ue_grp++ ) {
		if( ue_grp == group2 ) {
		    continue ;
		}
		if( groupArray[ue_grp].extint == ei2 ) {
		    break ;
		}
	    }
	    if( groupArray[ue_grp].flag > 0 ) {
		g1 = g2 = 0 ;
		groupArray[ue_grp].flag = -1 ;
		for( edge2 = edge + 1 ; edge2 <= numEdges ; edge2++ ) {
		    if( g2 == 0 ) {
			if( edgeArray[edge2].group1 == ue_grp ) {
			    g2 = edgeArray[edge2].group2 ;
			    if( groupArray[g2].flag < 0 ) {
				g2 = 0 ;
			    }
			    continue ;
			}
		    }
		    if( g1 == 0 ) {
			if( edgeArray[edge2].group2 == ue_grp ) {
			    g1 = edgeArray[edge2].group1 ;
			    if( groupArray[g1].flag < 0 ) {
				g1 = 0 ;
			    }
			}
		    }
		}
		if( g1 != 0 && g2 != 0 ) {
		    addEdge( g1, g2 ) ;
		    added_an_edge = YES ;
		}
	    }
	}
	if( added_an_edge == YES ) {
	    for( edge1 = edge + 1 ; edge1 <= numEdges ; edge1++ ) {
		a1 = edgeArray[edge1].group1 ;
		a2 = edgeArray[edge1].group2 ;
		if( groupArray[a1].block != groupArray[a2].block ) {
		    continue ;
		}
		for( edge2 = edge1 + 1 ; edge2 <= numEdges ; edge2++ ) {
		    b1 = edgeArray[edge2].group1 ;
		    b2 = edgeArray[edge2].group2 ;
		    if( groupArray[b1].block != groupArray[b2].block ) {
			continue ;
		    }
		    if( (groupArray[a1].unequiv == 1 &&
					groupArray[b1].unequiv == 1 &&
			    groupArray[a1].extint ==
					groupArray[b1].extint  &&
			    groupArray[a2].extint ==
					groupArray[b2].extint) ||
			(groupArray[a2].unequiv == 1 &&
					groupArray[b2].unequiv == 1 &&
			    groupArray[a2].extint ==
					groupArray[b2].extint  &&
			    groupArray[a1].extint ==
					groupArray[b1].extint)  ) {
			ya = (groupArray[a1].aveY +
						groupArray[a2].aveY) / 2 ;
			yb = (groupArray[b1].aveY +
						groupArray[b2].aveY) / 2 ;
			if( groupArray[a1].block == top_row ) {
			    if( ya < yb ) {
				if( edgeArray[edge2].cost <=
					    edgeArray[edge1].cost ) {
				    edgeArray[edge2].cost =
					    edgeArray[edge1].cost + 1;
				}
			    } else {
				if( edgeArray[edge2].cost >=
					    edgeArray[edge1].cost ) {
				    edgeArray[edge2].cost =
						edgeArray[edge1].cost - 1;
				}
			    }
			} else {
			    if( ya < yb ) {
				if( edgeArray[edge2].cost >=
					    edgeArray[edge1].cost ) {
				    edgeArray[edge2].cost =
						edgeArray[edge1].cost - 1;
				}
			    } else {
				if( edgeArray[edge2].cost <=
					    edgeArray[edge1].cost ) {
				    edgeArray[edge2].cost =
						edgeArray[edge1].cost + 1;
				}
			    }
			}
			break ;
		    }
		}
	    }
	    qsorte( (char *) (edgeArray + 1 + edge) , numEdges - edge ,
					   sizeof( edgeBox ) ) ;
	}
}
for( group = 1 ; group <= numGroups ; group++ ) {
	if( groupArray[group].flag < 0 ) {
	    continue ;
	}
	if( groupArray[group].unequiv != 1 ) {
	    continue ;
	}
	ei = groupArray[group].extint ;
	for( group2 = group + 1 ; group2 <= numGroups ; group2++ ) {
	    if( groupArray[group2].extint == ei ) {
		if( groupArray[group2].flag >= 0 ) {
		    groupArray[group2].flag = -1 ;
		}
		break ;
	    }
	}
}
done = NO ;
while( done == NO ) {
	done = YES ;
	for( edge = 1 ; edge <= numEdges ; edge++ ) {
	    if( edgeArray[edge].marked == YES &&
					edgeArray[edge].poison == NO ) {
		g1 = edgeArray[edge].group1 ;
		g2 = edgeArray[edge].group2 ;
		unequiv1 = groupArray[g1].unequiv ;
		if( unequiv1 == NO ) {
		    if( groupArray[g1].numPins == 1 &&
				groupArray[g1].pinArray[1].top != 0 ) {
			single_pin1 = YES ;
			unequiv1 = YES ;
		    }
		}
		unequiv2 = groupArray[g2].unequiv ;
		if( unequiv2 == NO ) {
		    if( groupArray[g2].numPins == 1 &&
				groupArray[g2].pinArray[1].top != 0 ) {
			single_pin2 = YES ;
			unequiv2 = YES ;
		    }
		}
		if( (groupArray[g1].poison == YES) ||
					(groupArray[g2].poison == YES) ){
		    done = NO ;
		    edgeArray[edge].poison = YES ;
		    if( unequiv1 == YES ) {
			groupArray[g1].poison = YES ;
		    }
		    if( unequiv2 == YES ) {
			groupArray[g2].poison = YES ;
		    }
		} else if( groupArray[g1].block != groupArray[g2].block){
		    done = NO ;
		    edgeArray[edge].poison = YES ;
		    if( unequiv1 == YES ) {
			groupArray[g1].poison = YES ;
		    }
		    if( unequiv2 == YES ) {
			groupArray[g2].poison = YES ;
		    }
		} else if( single_pin1 == YES || single_pin2 == YES ) {
		    done = NO ;
		    edgeArray[edge].poison = YES ;
		    if( unequiv1 == YES ) {
			groupArray[g1].poison = YES ;
		    }
		    if( unequiv2 == YES ) {
			groupArray[g2].poison = YES ;
		    }
		}
	    }
	}
}
for( edge = 1 ; edge <= numEdges ; edge++ ) {
	if( edgeArray[edge].marked == YES && edgeArray[edge].poison == NO ) {
		
	    g1 = edgeArray[edge].group1 ;
	    g2 = edgeArray[edge].group2 ;
	    if( groupArray[g1].unequiv == NO && groupArray[g2].unequiv == NO ) {
		edgeArray[edge].poison = YES ;
	    }
	    if( groupArray[g1].unequiv == NO ) {
		groupArray[g1].poison = YES ;
	    }
	    if( groupArray[g2].unequiv == NO ) {
		groupArray[g2].poison = YES ;
	    }
	}
}
for( edge = 1 ; edge <= numEdges ; edge++ ) {
	if( edgeArray[edge].marked == YES && edgeArray[edge].poison == NO ) {
		
	    g1 = edgeArray[edge].group1 ;
	    g2 = edgeArray[edge].group2 ;
	    if( groupArray[g1].edge1 == 0 ) {
		groupArray[g1].edge1 = edge ;
	    } else {
		groupArray[g1].edge2 = edge ;
	    }
	    if( groupArray[g2].edge1 == 0 ) {
		groupArray[g2].edge1 = edge ;
	    } else {
		groupArray[g2].edge2 = edge ;
	    }
	    if( groupArray[g1].poison == NO ) {
		ei = groupArray[g1].extint ;
		for( group = 1 ; ; group++ ) {
		    if( (group == g1) || (groupArray[group].extint != ei) ) {
			continue ;
		    }
		    break ;
		}
		groupArray[g1].numPins = 2 ;
		groupArray[g1].pinArray[2].xloc = groupArray[group].pinArray[1].xloc ;
		groupArray[g1].pinArray[2].yloc = groupArray[group].pinArray[1].yloc ;
		groupArray[g1].pinArray[2].top = groupArray[group].pinArray[1].top ;
		groupArray[g1].pinArray[2].pin = groupArray[group].pinArray[1].pin ;
	    }
	    if( groupArray[g2].poison == NO ) {
		ei = groupArray[g2].extint ;
		for( group = 1 ; ; group++ ) {
		    if( (group == g2) || (groupArray[group].extint != ei) ) {
			continue ;
		    }
		    break ;
		}
		groupArray[g2].numPins = 2 ;
		groupArray[g2].pinArray[2].xloc = groupArray[group].pinArray[1].xloc ;
		groupArray[g2].pinArray[2].yloc = groupArray[group].pinArray[1].yloc ;
		groupArray[g2].pinArray[2].top = groupArray[group].pinArray[1].top ;
		groupArray[g2].pinArray[2].pin = groupArray[group].pinArray[1].pin ;
	    }
	}
}
for( edge = 1 ; edge <= numEdges ; edge++ ) {
	if( edgeArray[edge].marked == YES && edgeArray[edge].poison == NO ) {
		
	    g1 = edgeArray[edge].group1 ;
	    g2 = edgeArray[edge].group2 ;
	    if( groupArray[g1].edge2 == 0 && groupArray[g2].edge2 == 0 ) {
		edgeArray[edge].poison = YES ;
	    }
	}
}
closepins( twfile , net ) ;
for( i = 1 ; i <= numGroups ; i++ ) {
	groupArray[i].numPins = 0 ;
	groupArray[i].flag    = 0 ;
	groupArray[i].poison  = 0 ;
	groupArray[i].unequiv = 0 ;
	groupArray[i].extint  = 0 ;
	groupArray[i].edge1   = 0 ;
	groupArray[i].edge2   = 0 ;
	groupArray[i].check   = 0 ;
}
for( i = 1 ; i <= numEdges ; i++ ) {
	edgeArray[i].marked = 0 ;
	edgeArray[i].done   = 0 ;
	edgeArray[i].poison = 0 ;
}
}
twclose(twfile) ;
return ;
}
chkGroup( g1 , g2 , direction )
int g1 , g2 , direction ;
{
int g1type , g2type ;
g1type = detGroup(g1) ;
g2type = detGroup(g2) ;
if( direction == SAME_ROW ) {
if( g1type == GOING_UP_OR_DN ) {
	return( SUCCESS ) ;
} else if( g1type == GOING_UP ) {
	if( g2type == GOING_UP_OR_DN || g2type == GOING_UP ) {
	    return( SUCCESS ) ;
	} else {
	    return( FAILURE ) ;
	}
} else {
	if( g2type == GOING_UP_OR_DN || g2type == GOING_DN ) {
	    return( SUCCESS ) ;
	} else {
	    return( FAILURE ) ;
	}
}
} else if( direction == UP_ROW ) {
if( (g1type == GOING_UP_OR_DN || g1type == GOING_UP) &&
		    (g2type == GOING_UP_OR_DN || g2type == GOING_DN) ) {
	return( SUCCESS ) ;
} else {
	return( FAILURE ) ;
}
} else {
if( (g1type == GOING_UP_OR_DN || g1type == GOING_DN) &&
		    (g2type == GOING_UP_OR_DN || g2type == GOING_UP) ) {
	return( SUCCESS ) ;
} else {
	return( FAILURE ) ;
}
}
}
detGroup( g )
int g ;
{
int p , pt , pb , p0 ;
pt = 0 ;
pb = 0 ;
p0 = 0 ;
for( p = 1 ; p <= groupArray[g].numPins ; p++ ) {
if( groupArray[g].pinArray[p].top == 0 ) {
	p0 = 1 ;
} else if( groupArray[g].pinArray[p].top == 1 ) {
	pt = 1 ;
} else {
	pb = 1 ;
}
}
if( p0 == 1 || (pt == 1 && pb == 1) ) {
return( GOING_UP_OR_DN ) ;
} else if( pt == 1 ) {
return( GOING_UP ) ;
} else {
return( GOING_DN ) ;
}
}
addEdge( g1 , g2 )
int g1 , g2 ;
{
edgeArray[++numEdges].cost = ABS(groupArray[g1].aveX -
					groupArray[g2].aveX) ;
edgeArray[numEdges].group1 = g1 ;
edgeArray[numEdges].group2 = g2 ;
return ;
}
searchG( g , type , block )
int g , type , block ;
{
int og , uptarget , dntarget , type2 ;
uptarget = 0 ;
dntarget = 0 ;
if( type == 0 ) {
for( og = g + 1 ; og <= numGroups ; og++ ) {
	if( groupArray[og].block == block ) {
	    if( chkGroup( g, og, 0 ) ) {
		type2 = detGroup(og) ;
		if( type2 == 0 ) {
		    if( uptarget == 0 && dntarget == 0 ) {
			addEdge( g , og ) ;
		    }
		    uptarget = 1 ;
		    dntarget = 1 ;
		} else if( type2 == 1 ) {
		    if( uptarget == 0 ) {
			addEdge( g , og ) ;
			uptarget = 1 ;
		    }
		} else {
		    if( dntarget == 0 ) {
			addEdge( g , og ) ;
			dntarget = 1 ;
		    }
		}
	    }
	    if( uptarget == 1 && dntarget == 1 ) {
		break ;
	    }
	} else if( groupArray[og].block == block - 1 ) {
	    if( chkGroup( g, og, -1 ) ) {
		if( dntarget == 0 ) {
		    addEdge( g , og ) ;
		    dntarget = 1 ;
		}
	    }
	    if( uptarget == 1 && dntarget == 1 ) {
		break ;
	    }
	} else if( groupArray[og].block == block + 1 ) {
	    if( chkGroup( g, og, 1 ) ) {
		if( uptarget == 0 ) {
		    addEdge( g , og ) ;
		    uptarget = 1 ;
		}
	    }
	    if( uptarget == 1 && dntarget == 1 ) {
		break ;
	    }
	}
}
} else if( type == 1 ) {
for( og = g + 1 ; og <= numGroups ; og++ ) {
	if( groupArray[og].block == block ) {
	    if( chkGroup( g, og, 0 ) ) {
		addEdge( g , og ) ;
		break ;
	    }
	} else if( groupArray[og].block == block + 1 ) {
	    if( chkGroup( g, og, 1 ) ) {
		addEdge( g , og ) ;
		break ;
	    }
	}
}
} else {
for( og = g + 1 ; og <= numGroups ; og++ ) {
	if( groupArray[og].block == block ) {
	    if( chkGroup( g, og, 0 ) ) {
		addEdge( g , og ) ;
		break ;
	    }
	} else if( groupArray[og].block == block - 1 ) {
	    if( chkGroup( g, og, -1 ) ) {
		addEdge( g , og ) ;
		break ;
	    }
	}
}
}
return ;
}
/* 当前文件是D:\Read\globedbg.c*/




#define NEWPOS 1
#define OLDPOS 0
#define ROWCOLOR "aquamarine"
#define NEWNETCOLOR "red"
#define PADCOLOR "aquamarine"
#define OLDNETCOLOR "green"
#define NEWPINCOLOR "white"
#define OLDPINCOLOR "black"
#define EQUIVCOLOR  "orange"
#define UNEQUIVCOLOR "blue"
#define OLDGROUPCOLOR "blue"
#define NEWGROUPCOLOR "red"
globedbg(lowerNet,upperNet)
int lowerNet ;
int upperNet ;
{
int block, left, rite, bot, top , cell , b , e , pin1 , pin2 ;
int net , seg, term1, curExtint, separation, factor ;
int llx, lly, urx, ury ;
void checkPos();
SEGBOXPTR sptr ;
CBOXPTR cellptr ;
NBOXPTR curTerm;
FILE *fp , *fpp ;
fp = twopen( "cell.file","w", ABORT ) ;
for( block = 1 ; block <= numblock ; block++ ) {
left = barray[block]->bxcenter + barray[block]->bleft ;
bot  = barray[block]->bycenter + barray[block]->bbottom ;
top  = barray[block]->bycenter + barray[block]->btop ;
if( pairArray[block][0] > 0 ) {
	cell = pairArray[block][ pairArray[block][0] ] ;
	rite = carray[cell]->cxcenter + carray[cell]->tileptr->right;
} else {
	rite = barray[block]->bxcenter + barray[block]->bright ;
}
fprintf(fp,"%d, %d, %d, %d, color: %s, label: row:%d\n",
		left,bot,rite,top, ROWCOLOR, block ) ;
}
llx = INT_MAX ;
lly = INT_MAX ;
urx = INT_MIN ;
ury = INT_MIN ;
for( cell = numcells + 1 ; cell <= numcells + numterms ; cell++ ) {
cellptr = carray[cell] ;
left = cellptr->cxcenter + cellptr->tileptr->left ;
rite = cellptr->cxcenter + cellptr->tileptr->right ;
bot  = cellptr->cycenter + cellptr->tileptr->bottom ;
top  = cellptr->cycenter + cellptr->tileptr->top ;
fprintf(fp,"%d, %d, %d, %d, color: %s, label: pad:%s\n",
	left,bot,rite,top, PADCOLOR, cellptr->cname ) ;
if( left < llx ){
	llx = left ;
}
if( rite > urx ){
	urx = rite ;
}
if( bot <  lly ){
	lly = bot  ;
}
if( top  > ury ){
	ury = top  ;
}
}
twclose(fp);
fp  = twopen( "net.file","w", ABORT ) ;
fpp = twopen("pin.file","w", ABORT );
separation = (int) rowSep * rowHeight / 3;
for( net = lowerNet ; net <= upperNet ; net++ ) {
b = anet[net] ;
e = anet[net + 1] - 1 ;
for( seg = b ; seg <= e ; seg++ ) {
	if( aNetSeg[seg].nflag == 0 ) {
	
	
	    if( aNetSeg[seg].current == 0 ) {
		sptr = aNetSeg[seg].top ;
	    } else {
		sptr = aNetSeg[seg].bot ;
	    }
	    pin1 = sptr->pin1 ;
	    pin2 = sptr->pin2 ;
	    checkPos(tearray[pin1],NEWPOS,llx,lly,urx,ury) ;
	    checkPos(tearray[pin2],NEWPOS,llx,lly,urx,ury) ;
	    if (tearray[pin1]->ypos != tearray[pin2]->ypos){
		fprintf(fp,"%d, %d, %d, %d, %d, color: %s\n",
			net,
			tearray[pin1]->xpos ,
			tearray[pin1]->ypos ,
			tearray[pin2]->xpos ,
			tearray[pin2]->ypos ,
			NEWNETCOLOR) ;
	    } else {
		if ( (int) tearray[pin1]->pinloc == -1){
		    factor = -1;
		} else {
		    factor = 1;
		}
		fprintf(fp,"%d, %d, %d, %d, %d, color: %s\n",
			net,
			tearray[pin1]->xpos ,
			tearray[pin1]->ypos ,
			(tearray[pin1]->xpos + tearray[pin2]->xpos)/2 ,
			tearray[pin2]->ypos + factor * separation ,
			NEWNETCOLOR) ;
		fprintf(fp,"%d, %d, %d, %d, %d, color: %s\n",
			net,
			(tearray[pin1]->xpos + tearray[pin2]->xpos)/2 ,
			tearray[pin2]->ypos + factor * separation ,
			tearray[pin2]->xpos ,
			tearray[pin2]->ypos ,
			NEWNETCOLOR) ;
	    }
	
	    term1 = tearray[pin1]->terminal ;
	    curExtint = tearray[pin1]->extint ;
	    for (curTerm=netarray[net]->netptr;curTerm;curTerm= curTerm->nterm){
		if (curTerm->extint == curExtint && curTerm->terminal != term1){
		    if (curTerm->unequiv){
			fprintf(fp,"%d, %d, %d, %d, %d, color: %s\n",
			    net,
			    tearray[pin1]->xpos,
			    tearray[pin1]->ypos,
			    curTerm->xpos,
			    curTerm->ypos,
			    UNEQUIVCOLOR) ;
		    } else {
			fprintf(fp,"%d, %d, %d, %d, %d, color: %s\n",
			    net,
			    tearray[pin1]->xpos,
			    tearray[pin1]->ypos,
			    curTerm->xpos,
			    curTerm->ypos,
			    EQUIVCOLOR) ;
		    }
	   	}
	    }
	
	    term1 = tearray[pin2]->terminal ;
	    curExtint = tearray[pin2]->extint ;
	    for (curTerm=netarray[net]->netptr;curTerm;curTerm= curTerm->nterm){
		if (curTerm->extint == curExtint && curTerm->terminal != term1){
		    if (curTerm->unequiv){
			fprintf(fp,"%d, %d, %d, %d, %d, color: %s\n",
			    net,
			    tearray[pin2]->xpos,
			    tearray[pin2]->ypos,
			    curTerm->xpos,
			    curTerm->ypos,
			    UNEQUIVCOLOR) ;
		    } else {
			fprintf(fp,"%d, %d, %d, %d, %d, color: %s\n",
			    net,
			    tearray[pin2]->xpos,
			    tearray[pin2]->ypos,
			    curTerm->xpos,
			    curTerm->ypos,
			    EQUIVCOLOR) ;
		    }
	   	}
	    }
	    fprintf(fpp,"%d, %d, %d, %d, %d, color: %s, label: %d\n",
			net,
			tearray[pin1]->xpos - 1,
			tearray[pin1]->ypos - 1,
			tearray[pin1]->xpos + 1,
			tearray[pin1]->ypos + 1,
			NEWPINCOLOR,
			pin1 ) ;
	    fprintf(fpp,"%d, %d, %d, %d, %d, color: %s, label: %d\n",
			net,
			tearray[pin2]->xpos - 1,
			tearray[pin2]->ypos - 1,
			tearray[pin2]->xpos + 1,
			tearray[pin2]->ypos + 1,
			NEWPINCOLOR,
			pin2 ) ;
	} else {
	    if( aNetSeg[seg].current == 0 ) {
		sptr = aNetSeg[seg].top ;
	    } else {
		sptr = aNetSeg[seg].bot ;
	    }
	    pin1 = sptr->pin1 ;
	    pin2 = sptr->pin2 ;
	
	    checkPos(tearray[pin1],NEWPOS,llx,lly,urx,ury) ;
	    checkPos(tearray[pin2],NEWPOS,llx,lly,urx,ury) ;
	    checkPos(tearray[pin1],OLDPOS,llx,lly,urx,ury) ;
	    checkPos(tearray[pin2],OLDPOS,llx,lly,urx,ury) ;
	    if (tearray[pin1]->newy != tearray[pin2]->newy){
		fprintf(fp,"%d, %d, %d, %d, %d, color: %s\n",
			net,
			tearray[pin1]->newx ,
			tearray[pin1]->newy ,
			tearray[pin1]->newx  - 2 ,
			(tearray[pin1]->newy + tearray[pin2]->newy) / 2,
			OLDNETCOLOR) ;
		fprintf(fp,"%d, %d, %d, %d, %d, color: %s\n",
			net,
			tearray[pin1]->newx  - 2,
			(tearray[pin1]->newy + tearray[pin2]->newy) /2 ,
			tearray[pin2]->newx ,
			tearray[pin2]->newy ,
			OLDNETCOLOR) ;
	    } else {
		if ( (int) tearray[pin1]->pinloc == -1 ){
		    factor = -1;
		} else {
		    factor = 1;
		}
		fprintf(fp,"%d, %d, %d, %d, %d, color: %s\n",
			net,
			tearray[pin1]->newx ,
			tearray[pin1]->newy ,
			(tearray[pin1]->newx + tearray[pin2]->newx)/2 ,
			tearray[pin2]->newy + factor * separation * 3 / 4 ,
			OLDNETCOLOR) ;
		fprintf(fp,"%d, %d, %d, %d, %d, color: %s\n",
			net,
			(tearray[pin1]->newx + tearray[pin2]->newx)/2 ,
			tearray[pin2]->newy + factor * separation * 3 / 4,
			tearray[pin2]->newx ,
			tearray[pin2]->newy ,
			OLDNETCOLOR) ;
	    }
	
	    term1 = tearray[pin1]->terminal ;
	    curExtint = tearray[pin1]->extint ;
	    for (curTerm=netarray[net]->netptr;curTerm;curTerm= curTerm->nterm){
		if (curTerm->extint == curExtint && curTerm->terminal != term1){
		    if (curTerm->unequiv){
			fprintf(fp,"%d, %d, %d, %d, %d, color: %s\n",
			    net,
			    tearray[pin1]->newx ,
			    tearray[pin1]->newy ,
			    curTerm->newx - 2,
			    (curTerm->newy + tearray[pin1]->newy)/2,
			    UNEQUIVCOLOR) ;
			fprintf(fp,"%d, %d, %d, %d, %d, color: %s\n",
			    net,
			    curTerm->newx ,
			    curTerm->newy ,
			    curTerm->newx - 2,
			    (curTerm->newy + tearray[pin1]->newy)/2,
			    UNEQUIVCOLOR) ;
		    } else {
			fprintf(fp,"%d, %d, %d, %d, %d, color: %s\n",
			    net,
			    tearray[pin1]->newx ,
			    tearray[pin1]->newy ,
			    curTerm->newx - 2,
			    (curTerm->newy + tearray[pin1]->newy)/2,
			    EQUIVCOLOR) ;
			fprintf(fp,"%d, %d, %d, %d, %d, color: %s\n",
			    net,
			    curTerm->newx ,
			    curTerm->newy ,
			    curTerm->newx - 2,
			    (curTerm->newy + tearray[pin1]->newy)/2,
			    EQUIVCOLOR) ;
		    }
	   	}
	    }
	
	    term1 = tearray[pin2]->terminal ;
	    curExtint = tearray[pin2]->extint ;
	    for (curTerm=netarray[net]->netptr;curTerm;curTerm= curTerm->nterm){
		if (curTerm->extint == curExtint && curTerm->terminal != term1){
		    if (curTerm->unequiv){
			fprintf(fp,"%d, %d, %d, %d, %d, color: %s\n",
			    net,
			    tearray[pin2]->newx ,
			    tearray[pin2]->newy ,
			    curTerm->newx - 2,
			    (curTerm->newy + tearray[pin2]->newy)/2,
			    UNEQUIVCOLOR) ;
			fprintf(fp,"%d, %d, %d, %d, %d, color: %s\n",
			    net,
			    curTerm->newx ,
			    curTerm->newy ,
			    curTerm->newx - 2,
			    (curTerm->newy + tearray[pin2]->newy)/2,
			    UNEQUIVCOLOR) ;
		    } else {
			fprintf(fp,"%d, %d, %d, %d, %d, color: %s\n",
			    net,
			    tearray[pin2]->newx ,
			    tearray[pin2]->newy ,
			    curTerm->newx - 2,
			    (curTerm->newy + tearray[pin2]->newy)/2,
			    EQUIVCOLOR) ;
			fprintf(fp,"%d, %d, %d, %d, %d, color: %s\n",
			    net,
			    curTerm->newx ,
			    curTerm->newy ,
			    curTerm->newx - 2,
			    (curTerm->newy + tearray[pin2]->newy)/2,
			    EQUIVCOLOR) ;
		    }
	   	}
	    }
	    fprintf(fpp,"%d, %d, %d, %d, %d, color: %s, label: %d\n",
			net,
			tearray[pin1]->newx - 2,
			tearray[pin1]->newy - 2,
			tearray[pin1]->newx + 2,
			tearray[pin1]->newy + 2,
			OLDPINCOLOR,
			pin1 ) ;
	    fprintf(fpp,"%d, %d, %d, %d, %d, color: %s, label: %d\n",
			net,
			tearray[pin2]->newx - 2,
			tearray[pin2]->newy - 2,
			tearray[pin2]->newx + 2,
			tearray[pin2]->newy + 2,
			OLDPINCOLOR,
			pin2 ) ;
	    if( aNetSeg[seg].ncurrent == 0 ) {
		sptr = aNetSeg[seg].ntop ;
	    } else {
		sptr = aNetSeg[seg].nbot ;
	    }
	    pin1 = sptr->pin1 ;
	    pin2 = sptr->pin2 ;
	    if (tearray[pin1]->ypos != tearray[pin2]->ypos){
		fprintf(fp,"%d, %d, %d, %d, %d, color: %s\n",
			net,
			tearray[pin1]->xpos ,
			tearray[pin1]->ypos ,
			tearray[pin2]->xpos ,
			tearray[pin2]->ypos ,
			NEWNETCOLOR) ;
	    } else {
		if( (int) tearray[pin1]->pinloc == -1 ){
		    factor = -1;
		} else {
		    factor = 1;
		}
		fprintf(fp,"%d, %d, %d, %d, %d, color: %s\n",
			net,
			tearray[pin1]->xpos ,
			tearray[pin1]->ypos ,
			(tearray[pin1]->xpos + tearray[pin2]->xpos)/2 ,
			tearray[pin2]->ypos + factor * separation ,
			NEWNETCOLOR) ;
		fprintf(fp,"%d, %d, %d, %d, %d, color: %s\n",
			net,
			(tearray[pin1]->xpos + tearray[pin2]->xpos)/2 ,
			tearray[pin2]->ypos + factor * separation ,
			tearray[pin2]->xpos ,
			tearray[pin2]->ypos ,
			NEWNETCOLOR) ;
	    }
	    term1 = tearray[pin1]->terminal ;
	    curExtint = tearray[pin1]->extint ;
	    for (curTerm=netarray[net]->netptr;curTerm;curTerm= curTerm->nterm){
		if (curTerm->extint == curExtint && curTerm->terminal != term1){
		    if (curTerm->unequiv){
			fprintf(fp,"%d, %d, %d, %d, %d, color: %s\n",
			    net,
			    tearray[pin1]->xpos,
			    tearray[pin1]->ypos,
			    curTerm->xpos,
			    curTerm->ypos,
			    UNEQUIVCOLOR) ;
		    } else {
			fprintf(fp,"%d, %d, %d, %d, %d, color: %s\n",
			    net,
			    tearray[pin1]->xpos,
			    tearray[pin1]->ypos,
			    curTerm->xpos,
			    curTerm->ypos,
			    EQUIVCOLOR) ;
		    }
	   	}
	    }
	
	    term1 = tearray[pin2]->terminal ;
	    curExtint = tearray[pin2]->extint ;
	    for (curTerm=netarray[net]->netptr;curTerm;curTerm= curTerm->nterm){
		if (curTerm->extint == curExtint && curTerm->terminal != term1){
		    if (curTerm->unequiv){
			fprintf(fp,"%d, %d, %d, %d, %d, color: %s\n",
			    net,
			    tearray[pin2]->xpos,
			    tearray[pin2]->ypos,
			    curTerm->xpos,
			    curTerm->ypos,
			    UNEQUIVCOLOR) ;
		    } else {
			fprintf(fp,"%d, %d, %d, %d, %d, color: %s\n",
			    net,
			    tearray[pin2]->xpos,
			    tearray[pin2]->ypos,
			    curTerm->xpos,
			    curTerm->ypos,
			    EQUIVCOLOR) ;
		    }
	   	}
	    }
	    fprintf(fpp,"%d, %d, %d, %d, %d, color: %s, label: %d\n",
			net,
			tearray[pin1]->xpos - 1,
			tearray[pin1]->ypos - 1,
			tearray[pin1]->xpos + 1,
			tearray[pin1]->ypos + 1,
			NEWPINCOLOR ,
			pin1) ;
	    fprintf(fpp,"%d, %d, %d, %d, %d, color: %s, label: %d\n",
			net,
			tearray[pin2]->xpos - 1,
			tearray[pin2]->ypos - 1,
			tearray[pin2]->xpos + 1,
			tearray[pin2]->ypos + 1,
			NEWPINCOLOR,
			pin2) ;
	}
}
}
twclose(fp);
twclose(fpp);
return ;
}
void   checkPos(pin,pos,llx,lly,urx,ury)
NBOXPTR pin ;
int pos ;
int llx ;
int lly ;
int urx ;
int ury ;
{
if( pos == NEWPOS){
if( pin->xpos > urx ){
	printf("ERROR:pin xpos > urx ; set to urx ;");
	pin->xpos = urx ;
}
if( pin->xpos < llx ){
	printf("ERROR:pin xpos < llx ; set to llx ;");
	pin->xpos = llx ;
}
if( pin->ypos > ury ){
	printf("ERROR:pin ypos > ury ; set to ury ;");
	pin->ypos =ury ;
}
if( pin->ypos < lly ){
	printf("ERROR:pin ypos < lly ; set to lly ;");
	pin->ypos =ury ;
}
} else {
if( pin->newx > urx ){
	printf("ERROR:pin newx > urx ; set to urx ;");
	pin->newx = urx ;
}
if( pin->newx < llx ){
	printf("ERROR:pin newx < llx ; set to llx ;");
	pin->newx = llx ;
}
if( pin->newy > ury ){
	printf("ERROR:pin newy > ury ; set to ury ;");
	pin->newy =ury ;
}
if( pin->newy < lly ){
	printf("ERROR:pin newy < lly ; set to lly ;");
	pin->newy =ury ;
}
}
}
void dumpEdgeArray(net)
int net ;
{
int edge ;
FILE *fp , *fpp ;
int block, left, rite, bot, top , cell , g1 , g2 ;
int llx, lly, urx, ury ;
CBOXPTR cellptr ;

fp = twopen("cell.file","w",ABORT);
for( block = 1 ; block <= numblock ; block++ ) {
left = barray[block]->bxcenter + barray[block]->bleft ;
bot  = barray[block]->bycenter + barray[block]->bbottom ;
top  = barray[block]->bycenter + barray[block]->btop ;
if( pairArray[block][0] > 0 ) {
	cell = pairArray[block][ pairArray[block][0] ] ;
	rite = carray[cell]->cxcenter + carray[cell]->tileptr->right;
} else {
	rite = barray[block]->bxcenter + barray[block]->bright ;
}
fprintf(fp,"%d, %d, %d, %d, color: %s, label: row:%d\n",
		left,bot,rite,top, ROWCOLOR, block ) ;
}
llx = INT_MAX ;
lly = INT_MAX ;
urx = INT_MIN ;
ury = INT_MIN ;
for( cell = numcells + 1 ; cell <= numcells + numterms ; cell++ ) {
cellptr = carray[cell] ;
left = cellptr->cxcenter + cellptr->tileptr->left ;
rite = cellptr->cxcenter + cellptr->tileptr->right ;
bot  = cellptr->cycenter + cellptr->tileptr->bottom ;
top  = cellptr->cycenter + cellptr->tileptr->top ;
fprintf(fp,"%d, %d, %d, %d, color: %s, label: pad:%s\n",
	left,bot,rite,top, PADCOLOR, cellptr->cname ) ;
if( left < llx ){
	llx = left ;
}
if( rite > urx ){
	urx = rite ;
}
if( bot <  lly ){
	lly = bot  ;
}
if( top  > ury ){
	ury = top  ;
}
}
twclose(fp);
fp  = twopen("net.file","w",ABORT);
fpp = twopen("pin.file","w",ABORT);
for( edge = 1 ; edge <= numEdges  ; edge++ ) {
	
g1 = edgeArray[edge].group1 ;
g2 = edgeArray[edge].group2 ;
if( edgeArray[edge].marked == YES ) {
	fprintf(fp,"%d, %d, %d, %d, %d, color: %s, label:%d\n",
		net,
	        groupArray[g1].aveX,
	        groupArray[g1].aveY,
	        groupArray[g2].aveX,
	        groupArray[g2].aveY,
		NEWGROUPCOLOR,
		edge) ;
	fprintf(fpp,"%d, %d, %d, %d, %d, color: %s, label:G%d\n",
		net,
	        groupArray[g1].aveX - 1,
	        groupArray[g1].aveY - 1,
	        groupArray[g1].aveX + 1,
	        groupArray[g1].aveY + 1,
		NEWPINCOLOR,
		g1) ;
	fprintf(fpp,"%d, %d, %d, %d, %d, color: %s, label:G%d\n",
		net,
	        groupArray[g2].aveX - 1,
	        groupArray[g2].aveY - 1,
	        groupArray[g2].aveX + 1,
	        groupArray[g2].aveY + 1,
		NEWPINCOLOR,
		g2) ;
} else {
	fprintf(fp,"%d, %d, %d, %d, %d, color: %s, label:%d\n",
		net,
	        groupArray[g1].aveX,
	        groupArray[g1].aveY,
	        groupArray[g2].aveX,
	        groupArray[g2].aveY,
		OLDGROUPCOLOR,
		edge) ;
	fprintf(fpp,"%d, %d, %d, %d, %d, color: %s, label:G%d\n",
		net,
	        groupArray[g1].aveX - 1,
	        groupArray[g1].aveY - 1,
	        groupArray[g1].aveX + 1,
	        groupArray[g1].aveY + 1,
		OLDPINCOLOR,
		g1) ;
	fprintf(fpp,"%d, %d, %d, %d, %d, color: %s, label:G%d\n",
		net,
	        groupArray[g2].aveX - 1,
	        groupArray[g2].aveY - 1,
	        groupArray[g2].aveX + 1,
	        groupArray[g2].aveY + 1,
		OLDPINCOLOR,
		g2) ;
}
}
twclose(fp);
twclose(fpp);
}
/* 当前文件是D:\Read\globroute.c*/




globroute()
{
FILE *fp ;
char filename[64] ;
int attperseg ;
int swSeg , flips , attempts , seg ;
int breakpoint , stoppoint ;
int found ;
SEGBOXPTR segptr ;
DENSITYPTR denptr ;
CHANGRDPTR gdptr , ptr1 , ptr2 ;
int x , x1 , x2 , channel , track ;
attperseg = 40 ;
randVar = randomSeed2 ;
fprintf( fpo, "\nThe rand generator seed was at globroute() : %d\n\n",
							    randVar ) ;
sprintf( filename , "%s.twf" , cktName ) ;
fp = twopen ( filename , "r", ABORT ) ;
changrid( ) ;
readseg( fp ) ;
twclose( fp ) ;
if( stage == 3 ) {
for( seg = 1 ; seg <= numSegs ; seg++ ) {
	aNetSeg[seg].current = fixarray[seg] ;
}
}
findrcost() ;
fprintf(fpo,"\n\nTHIS IS THE ORIGINAL NUMBER OF TRACKS: %d\n\n\n" ,
							tracks ) ;
fflush(fpo);
attlimit = attperseg * numSwSegs ;
attempts = 0 ;
flips = 0    ;
stoppoint = 10 * numSwSegs ;
breakpoint = 0 ;
while( attempts < attlimit ) {
for( ; ; ) {
	do {
	    swSeg = (int) ( (double) numSegs * ( (double) RAND /
					  (double) 0x7fffffff ) ) + 1 ;
	} while( swSeg == numSegs + 1 ) ;
	if( aNetSeg[swSeg].swYorN == 1 && aNetSeg[swSeg].key == 0 ) {
	    break ;
	}
}
if( aNetSeg[swSeg].current == 0 ) {
	segptr = aNetSeg[swSeg].top ;
} else {
	segptr = aNetSeg[swSeg].bot ;
}
channel = segptr->channel ;
ptr1 = segptr->pin1ptr ;
ptr2 = segptr->pin2ptr ;
x1 = ptr1->netptr->xpos ;
x2 = ptr2->netptr->xpos ;
found = NO ;
	
for( denptr = DboxHead[ channel ][ maxTrack[channel] ]->next
		    ; denptr != DENSENULL ; denptr = denptr->next ) {
	x = denptr->grdptr->netptr->xpos ;
	if( x1 <= x && x2 >= x ) {
	    found = YES ;
	    break ;
	}
}
if( !found ) {
	if( ++breakpoint > stoppoint ) {
	    break ;
	}
	attempts++ ;
	continue ;
}
if( urcost( swSeg ) ) {
	flips++    ;
	attempts++ ;
	breakpoint = 0 ;
} else {
	if( ++breakpoint > stoppoint ) {
	    break ;
	}
	attempts++ ;
}
}
for( channel = 1 ; channel <= numChans ; channel++ ) {
for( gdptr = Begin[channel] ; gdptr != GRDNULL ;
			    gdptr = gdptr->nextgrd ) {
	gdptr->ntracks  = gdptr->tracks ;
	gdptr->nSegType = gdptr->SegType ;
	gdptr->nnextgrd = gdptr->nextgrd ;
	gdptr->nprevgrd = gdptr->prevgrd ;
	gdptr->netptr->newx = gdptr->netptr->xpos ;
	gdptr->netptr->newy = gdptr->netptr->ypos ;
}
for( track = 0 ; track <= max_tdensity+100 ; track++ ) {
	for( denptr = DboxHead[channel][track] ;
		denptr != DENSENULL ; denptr = denptr->next ) {
	    denptr->nnext = denptr->next ;
	    denptr->nback = denptr->back ;
	}
}
nmaxTrack[channel] = maxTrack[channel] ;
}
fprintf(fpo,"no. of accepted flips: %d\n", flips ) ;
fprintf(fpo,"no. of attempted flips: %d\n", attempts ) ;
if( numSwSegs != 0 ) {
fprintf(fpo,"no. of attempted flips / numSwSegs: %.1f\n",
			    (double) attempts / (double) numSwSegs ) ;
}
fprintf(fpo,"THIS IS THE NUMBER OF TRACKS: %d\n\n\n" , tracks ) ;
fflush(fpo);
return ;
}
/* 当前文件是D:\Read\gparser.c*/

gparser( fp )
FILE *fp ;
{
int cell , term , pinctr , i , layer ;
int block , left , right , bottom , top ;
int xpos , ypos , orient ;
int from ;
double space ;
char input[1024] ;
char netname[1024] ;
NBOXPTR nptr , zapptr ;
CBOXPTR ptr ;
TEBOXPTR cptr , koptr ;
cell = 0 ;
pinctr = 0 ;
netctr = 0 ;
maketabl() ;
while( fscanf( fp , " %s " , input ) == 1 ) {
if( strcmp( input , "cell") == 0 ) {
	cell++ ;
	fscanf( fp , " %s " , input ) ;
	fscanf( fp , " %s " , input ) ;
	fscanf( fp , " %s " , input ) ;
	fscanf( fp , " %d " , &block ) ;
} else if( strcmp( input , "initially") == 0 ) {
	fscanf( fp , " %s " , input ) ;
	fscanf( fp , " %d " , &from ) ;
	fscanf( fp , " %s " , input ) ;
	fscanf( fp , " %s " , input ) ;
	fscanf( fp , " %s " , input ) ;
	fscanf( fp , " %s " , input ) ;
	fscanf( fp , " %d " , &block ) ;
} else if( strcmp( input , "nomirror") == 0 ) {
} else if( strcmp( input , "left") == 0 ) {
	fscanf( fp , " %d " , &left ) ;
	fscanf( fp , " %s " , input ) ;
	fscanf( fp , " %d " , &right ) ;
	fscanf( fp , " %s " , input ) ;
	fscanf( fp , " %d " , &bottom ) ;
	fscanf( fp , " %s " , input ) ;
	fscanf( fp , " %d " , &top ) ;
} else if( strcmp( input , "pin") == 0 ) {
	fscanf( fp , " %s " , input ) ;
	fscanf( fp , " %s " , input ) ;
	fscanf( fp , " %s " , input ) ;
	fscanf( fp , " %s " , input ) ;
	strcpy( netname , input ) ;
	if( strcmp( input , "TW_PASS_THRU" ) != 0 ) {
	    pinctr++ ;
	    addhash( input ) ;
	}
	if( pin_layers_given != 0 ) {
	    fscanf( fp , " %s " , input ) ;
	    fscanf( fp , " %d " , &layer ) ;
	}
	fscanf( fp , " %d %d " , &xpos , &ypos ) ;
} else if( strcmp( input , "equiv") == 0 ) {
	fscanf( fp , " %s " , input ) ;
	fscanf( fp , " %s " , input ) ;
	if( pin_layers_given != 0 ) {
	    fscanf( fp , " %s " , input ) ;
	    fscanf( fp , " %d " , &layer ) ;
	}
	fscanf( fp , " %d %d " , &xpos , &ypos ) ;
	if( strcmp( netname , "TW_PASS_THRU" ) != 0 ) {
	    pinctr++ ;
	}
} else if( strcmp( input , "unequiv") == 0 ) {
	fscanf( fp , " %s " , input ) ;
	fscanf( fp , " %s " , input ) ;
	if( pin_layers_given != 0 ) {
	    fscanf( fp , " %s " , input ) ;
	    fscanf( fp , " %d " , &layer ) ;
	}
	fscanf( fp , " %d %d " , &xpos , &ypos ) ;
	pinctr++ ;
} else if( strcmp( input , "pad") == 0 ) {
	fscanf( fp , " %s " , input ) ;
	fscanf( fp , " %s " , input ) ;
	fscanf( fp , " %s " , input ) ;
	fscanf( fp , " %d " , &orient ) ;
	fscanf( fp , " %s " , input ) ;
	fscanf( fp , " %d " , input ) ;
	fscanf( fp , " %s " , input ) ;
	fscanf( fp , " %d " , &left ) ;
	fscanf( fp , " %s " , input ) ;
	fscanf( fp , " %d " , &right ) ;
	fscanf( fp , " %s " , input ) ;
	fscanf( fp , " %d " , &bottom ) ;
	fscanf( fp , " %s " , input ) ;
	fscanf( fp , " %d " , &top ) ;
} else if( strcmp( input , "sidespace") == 0 ) {
	fscanf( fp , " %lf " , &space ) ;
}
}
rewind( fp ) ;
top_row_for_this_net = (int *) safe_malloc(
			(numnets + 1) * sizeof(int) ) ;
bot_row_for_this_net = (int *) safe_malloc(
			(numnets + 1) * sizeof(int) ) ;
for( i = 1 ; i <= numnets ; i++ ) {
top_row_for_this_net[i] = -1 ;
bot_row_for_this_net[i] = 10000000 ;
}
insert_row(1) ;
for( i = 1 ; i <= numnets ; i++ ) {
nptr = netarray[i]->netptr ;
for( ; nptr ; nptr = nptr->nterm ) {
	if( nptr->row > top_row_for_this_net[i] ) {
	    top_row_for_this_net[i] = nptr->row ;
	}
	if( nptr->row < bot_row_for_this_net[i] ) {
	    bot_row_for_this_net[i] = nptr->row ;
	}
}
}
for( i = 1 ; i <= numnets ; i++ ) {
nptr = netarray[ i ]->netptr ;
netarray[i]->netptr = NETNULL ;
if( nptr != NETNULL ) {
	zapptr = nptr ;
	while( nptr->nterm != NETNULL ) {
	    nptr = nptr->nterm ;
	    safe_free( zapptr ) ;
	    zapptr = nptr ;
	}
	safe_free( nptr ) ;
}
}
safe_free( tearray ) ;
tearray = (NBOXPTR *) safe_malloc( (pinctr + 1 ) * sizeof( NBOXPTR ) );
for( term = 1 ; term <= pinctr ; term++ ) {
tearray[ term ] = NETNULL ;
}
maxterm = pinctr ;
pinnames = (char **) safe_malloc( (pinctr + 1) * sizeof( char * ) ) ;
for( cell = 1 ; cell <= numcells + numterms ; cell++ ) {
ptr = carray[cell] ;
ptr->numterms = 0 ;
cptr = ptr->tileptr->termsptr ;
ptr->tileptr->termsptr = TERMNULL ;
if( cptr != TERMNULL ) {
	koptr = cptr ;
	while( cptr->nextterm != TERMNULL ) {
	    cptr = cptr->nextterm ;
	    safe_free( koptr ) ;
	    koptr = cptr ;
	}
	safe_free( cptr ) ;
}
}
return ;
}
/* 当前文件是D:\Read\grdcell.c*/









int move()  ;
int rect()  ;
int point() ;



typedef struct impbox {
int x ;
struct impbox *next_pin ;
} IMPBOX ;
typedef struct celltype {
struct celltype *next_cell ;
char *name ;
struct impbox *first_imp ;
} CELLTYPE ;
CELLTYPE *head_type , *active_cell_type ;
IMPBOX *pin_ptr ;
int active_type ;
grdcell( fp )
FILE *fp ;
{
int i , cell , orient , corient ;
int block , left , right , bottom , top ;
int xpos , ypos , pinctr , netx ;
int from , pick_top_pin , hack_off_a_pin ;
int terms , net ;
int extint , layer ;
char input[1024] ;
char netname[1024] ;
char pname[1024] ;
double space ;
CBOXPTR ptr ;
TIBOXPTR tile , tptr ;
TEBOXPTR term , tmptr ;
NBOXPTR netptr , termptr , saveptr ;
gparser( fp ) ;
impFeeds = (IBOXPTR *) safe_malloc( (numRows + 1) * sizeof( IBOXPTR ) ) ;
for( i = 1 ; i <= numRows ; i++ ) {
impFeeds[i] = (IBOXPTR) NULL ;
}
cell   = 0 ;
terms  = 0 ;
pinctr = 0 ;
extint = 0 ;
while( fscanf( fp , " %s " , input ) == 1 ) {
if( strcmp( input , "cell") == 0 ) {
	
	cell++ ;
	ptr = carray[ cell ] ;
	fscanf( fp , " %s " , input ) ;
	fscanf( fp , " %s " , input ) ;
	if( gate_array_special ) {
	    active_type = add_type( input ) ;
	}
} else if( strcmp( input , "initially") == 0 ) {
	fscanf( fp , " %s " , input ) ;
	fscanf( fp , " %d " , &from ) ;
	fscanf( fp , " %s " , input ) ;
	fscanf( fp , " %s " , input ) ;
	fscanf( fp , " %s " , input ) ;
	fscanf( fp , " %s " , input ) ;
	fscanf( fp , " %d " , &block ) ;
} else if( strcmp( input , "nomirror") == 0 ) {
} else if( strcmp( input , "left") == 0 ) {
	tile = ptr->tileptr ;
	fscanf( fp , " %d " , &left ) ;
} else if( strcmp( input , "right") == 0 ) {
	fscanf( fp , " %d " , &right ) ;
} else if( strcmp( input , "bottom") == 0 ) {
	fscanf( fp , " %d " , &bottom ) ;
} else if( strcmp( input , "top") == 0 ) {
	fscanf( fp , " %d " , &top ) ;
} else if( strcmp( input , "pin") == 0 ) {
	fscanf( fp , " %s " , input ) ;
	fscanf( fp , " %s " , input ) ;
	strcpy( pname , input ) ;
	fscanf( fp , " %s " , input ) ;
	fscanf( fp , " %s " , input ) ;
	strcpy( netname , input ) ;
	if( strcmp( netname , "TW_PASS_THRU" ) != 0 ) {
	    pinctr++ ;
	    extint++ ;
	    pinnames[pinctr] = (char *) safe_malloc(
			    (strlen( pname ) + 1) * sizeof( char ) ) ;
	    sprintf( pinnames[pinctr] , "%s" , pname ) ;
	    netx = hashfind( input ) ;
	    if( ++ptr->numterms == 1 ) {
		term = tile->termsptr = (TEBOXPTR) safe_malloc(
						sizeof( TEBOX ) ) ;
	    } else {
		term = term->nextterm = (TEBOXPTR) safe_malloc(
						   sizeof( TEBOX ) ) ;
	    }
	    term->nextterm = TERMNULL ;
	    term->cellterm = pinctr ;
	    term->ei = extint ;
	    term->ue = 0 ;
	    saveptr = netarray[ netx ]->netptr ;
	    netptr = netarray[ netx ]->netptr = (NBOXPTR)
					     safe_malloc( sizeof( NBOX ) ) ;
	    netptr->nterm    = saveptr ;
	    netptr->terminal = pinctr ;
	    if( terms == 0 ) {
		netptr->cell = cell ;
	    }
	    netptr->net      = netx ;
	    netptr->xpos     = 0    ;
	    netptr->ypos     = 0    ;
	    netptr->newx     = 0    ;
	    netptr->newy     = 0    ;
	    netptr->flag     = 0    ;
	    netptr->unequiv  = 0    ;
	    if( pin_layers_given != 0 ) {
		fscanf( fp , " %s " , input ) ;
		fscanf( fp , " %d " , &layer ) ;
	    } else {
		layer = 1 ;
	    }
	    fscanf( fp , " %d %d " , &xpos , &ypos ) ;
	    netptr->layer = layer - 1 ;
	    term->txpos[0] = xpos ;
	    term->typos[0] = ypos ;
	} else {
	    if( pin_layers_given != 0 ) {
		fscanf( fp , " %s " , input ) ;
		fscanf( fp , " %d " , &layer ) ;
	    } else {
		layer = 1 ;
	    }
	    fscanf( fp , " %d %d " , &xpos , &ypos ) ;
	    if( one_pin_feedthru ) {
		buildimp( cell , xpos , top    , pname , 1 , layer-1 ) ;
		buildimp( cell , xpos , bottom , pname , 0 , layer-1 ) ;
	    } else {
		buildimp( cell , xpos , ypos , pname , 1 , layer - 1 ) ;
	    }
	    if( gate_array_special && active_type ) {
		add_pin( xpos ) ;
	    }
	}
} else if( strcmp( input , "equiv") == 0 ) {
	fscanf( fp , " %s " , input ) ;
	fscanf( fp , " %s " , input ) ;
	strcpy( pname , input ) ;
	if( pin_layers_given != 0 ) {
	    fscanf( fp , " %s " , input ) ;
	    fscanf( fp , " %d " , &layer ) ;
	} else {
	    layer = 1 ;
	}
	fscanf( fp , " %d %d " , &xpos , &ypos ) ;
	if( strcmp( netname , "TW_PASS_THRU" ) != 0 ) {
	    pinctr++ ;
	    pinnames[pinctr] = (char *) safe_malloc(
		    (strlen( pname ) + 1) * sizeof( char ) ) ;
	    sprintf( pinnames[pinctr] , "%s" , pname ) ;
	    ++ptr->numterms ;
	    term = term->nextterm = (TEBOXPTR) safe_malloc(
						   sizeof( TEBOX ) ) ;
	    term->nextterm = TERMNULL ;
	    term->cellterm = pinctr ;
	    term->ei = extint ;
	    term->ue = 0 ;
	    saveptr = netarray[ netx ]->netptr ;
	    netptr = netarray[ netx ]->netptr = (NBOXPTR)
					 safe_malloc( sizeof( NBOX ) ) ;
	    netptr->nterm    = saveptr ;
	    netptr->terminal = pinctr ;
	    netptr->net      = netx ;
	    if( terms == 0 ) {
		netptr->cell = cell ;
	    }
	    netptr->xpos     = 0    ;
	    netptr->ypos     = 0    ;
	    netptr->newx     = 0    ;
	    netptr->newy     = 0    ;
	    netptr->flag     = 0    ;
	    netptr->unequiv  = 0    ;
	    netptr->layer    = layer - 1 ;
	    term->txpos[0]   = xpos ;
	    term->typos[0]   = ypos ;
	} else {
	    buildimp( cell , xpos , ypos , pname , 0 , layer - 1 ) ;
	}
} else if( strcmp( input , "unequiv") == 0 ) {
	fscanf( fp , " %s " , input ) ;
	fscanf( fp , " %s " , input ) ;
	strcpy( pname , input ) ;
	if( pin_layers_given != 0 ) {
	    fscanf( fp , " %s " , input ) ;
	    fscanf( fp , " %d " , &layer ) ;
	} else {
	    layer = 1 ;
	}
	fscanf( fp , " %d %d " , &xpos , &ypos ) ;
	hack_off_a_pin = NO ;
	if( netarray[netx]->numpins >= 10 ) {
	    hack_off_a_pin = YES ;
	    if( top_row_for_this_net[netx] % 2 == 0 ) {
		
		if( carray[cell]->cblock !=
				    bot_row_for_this_net[netx] ) {
		    if( carray[cell]->cblock % 2 == 0 ) {
			pick_top_pin = NO  ;
		    } else {
			pick_top_pin = YES ;
		    }
		} else {
		    pick_top_pin = YES ;
		}
	    } else {
		if( carray[cell]->cblock !=
				    bot_row_for_this_net[netx] ) {
		    if( carray[cell]->cblock % 2 == 1 ) {
			pick_top_pin = NO  ;
		    } else {
			pick_top_pin = YES ;
		    }
		} else {
		    pick_top_pin = YES ;
		}
	    }
	    if( barray[ carray[cell]->cblock ]->borient == 2 ) {
		if( pick_top_pin == NO ) {
		    pick_top_pin = YES ;
		} else {
		    pick_top_pin = NO  ;
		}
	    }
	}
	if( hack_off_a_pin == NO ) {
	    pinctr++ ;
	    pinnames[pinctr] = (char *) safe_malloc(
		    (strlen( pname ) + 1) * sizeof( char ) ) ;
	    sprintf( pinnames[pinctr] , "%s" , pname ) ;
	    ++ptr->numterms ;
	    term->ue = 1 ;
	    term = term->nextterm = (TEBOXPTR) safe_malloc(
					   sizeof( TEBOX ) ) ;
	    term->nextterm = TERMNULL ;
	    term->cellterm = pinctr ;
	    term->ei = extint ;
	    term->ue = 1 ;
	    saveptr = netarray[ netx ]->netptr ;
	    saveptr->unequiv = 1 ;
	    netptr = netarray[ netx ]->netptr = (NBOXPTR)
				 safe_malloc( sizeof( NBOX ) ) ;
	    netptr->nterm    = saveptr ;
	    netptr->terminal = pinctr ;
	    netptr->net      = netx   ;
	    if( terms == 0 ) {
		netptr->cell = cell ;
	    }
	    netptr->xpos     = 0    ;
	    netptr->ypos     = 0    ;
	    netptr->newx     = 0    ;
	    netptr->newy     = 0    ;
	    netptr->flag     = 0    ;
	    netptr->unequiv  = 1    ;
	    netptr->layer    = layer - 1 ;
	    term->txpos[0]   = xpos ;
	    term->typos[0]   = ypos ;
	} else {
	    if( ypos < -1 && pick_top_pin == YES ||
				ypos > 1 && pick_top_pin == NO ) {
		continue ;
	    } else {
		sprintf( pinnames[pinctr] , "%s" , pname ) ;
		term->txpos[0] = xpos ;
		term->typos[0] = ypos ;
	    }
	}
} else if( strcmp( input , "pad") == 0 ) {
	terms++ ;
	fscanf( fp , " %s " , input ) ;
	fscanf( fp , " %s " , input ) ;
	ptr = carray[ numcells + terms ] ;
} else if( strcmp( input , "orient") == 0 ) {
	fscanf( fp , " %d " , &orient ) ;
} else if( strcmp( input , "padside") == 0 ) {
	fscanf( fp , " %s " , input ) ;
} else if( strcmp( input , "sidespace") == 0 ) {
	fscanf( fp , " %lf " , &space ) ;
}
}
safe_free( top_row_for_this_net ) ;
delHtab() ;
for( net = 1 ; net <= numnets ; net++ ) {
for( netptr = netarray[ net ]->netptr ; netptr != NETNULL ;
				    netptr = netptr->nterm ) {
	tearray[ netptr->terminal ] = netptr ;
}
}
for( cell = 1 ; cell <= numcells ; cell++ ) {
ptr = carray[ cell ] ;
tptr = ptr->tileptr ;
for( tmptr = tptr->termsptr ; tmptr != TERMNULL ;
				    tmptr = tmptr->nextterm ) {
	if( ( ptr->clength %2 != 0 ) ) {
	    tmptr->txpos[1] = -tmptr->txpos[0] + 1 ;
	} else {
	    tmptr->txpos[1] = -tmptr->txpos[0] ;
	}
	if( ( ptr->cheight %2 != 0 ) ) {
	    tmptr->typos[1] = -tmptr->typos[0] + 1 ;
	} else {
	    tmptr->typos[1] = -tmptr->typos[0] ;
	}
}
}
for( cell = numcells + 1 ; cell <= numcells + numterms ; cell++ ) {
ptr = carray[cell] ;
tptr = ptr->tileptr ;
move( ptr->corient ) ;
for( tmptr = tptr->termsptr ; tmptr != TERMNULL ;
					    tmptr = tmptr->nextterm ) {
	tmptr->txpos[1] = tmptr->txpos[0] ;
	tmptr->typos[1] = tmptr->typos[0] ;
	point( &tmptr->txpos[1] , &tmptr->typos[1] ) ;
	if( (ptr->cheight % 2 != 0 && (orient == 4 || orient == 6))||
	    (ptr->clength % 2 != 0 && (orient == 2 || orient == 3))){
	    tmptr->txpos[1]++ ;
	}
	if( (ptr->cheight % 2 != 0 && (orient == 1 || orient == 3))||
	    (ptr->clength % 2 != 0 && (orient == 4 || orient == 7))){
	    tmptr->typos[1]++ ;
	}
}
}
for( cell = 1 ; cell <= numcells ; cell++ ) {
ptr = carray[cell] ;
tile = ptr->tileptr ;
corient = ptr->corient ;
for( term = tile->termsptr ; term != TERMNULL ;
			    term = term->nextterm ) {
	termptr = tearray[ term->cellterm ] ;
	termptr->xpos = term->txpos[corient/2] + ptr->cxcenter ;
	termptr->ypos = term->typos[corient%2] + ptr->cycenter ;
}
}
for( cell = numcells + 1  ; cell <= numcells + numterms ; cell++ ) {
ptr = carray[cell] ;
tile = ptr->tileptr ;
for( term = tile->termsptr ; term != TERMNULL ;
			    term = term->nextterm ) {
	termptr = tearray[ term->cellterm ] ;
	termptr->xpos = term->txpos[1] + ptr->cxcenter ;
	termptr->ypos = term->typos[1] + ptr->cycenter ;
}
}
return ;
}
add_type( type )
char *type ;
{
CELLTYPE *cell_ptr ;
if( head_type == NULL ) {
head_type = (CELLTYPE *) safe_malloc( sizeof( CELLTYPE ) ) ;
head_type->next_cell = NULL ;
head_type->first_imp = NULL ;
head_type->name = (char *) safe_malloc(
			(strlen(type) + 1) * sizeof( char ) ) ;
sprintf( head_type->name , "%s" , type ) ;
pin_ptr = NULL ;
active_cell_type = head_type ;
return(1) ;
} else {
cell_ptr = head_type ;
for( ; ; ) {
	if( strcmp( cell_ptr->name, type ) == 0 ) {
	    return(0) ;
	}
	if( cell_ptr->next_cell != NULL ) {
	    cell_ptr = cell_ptr->next_cell ;
	} else {
	    cell_ptr->next_cell = (CELLTYPE *)
				    safe_malloc(sizeof(CELLTYPE));
	    cell_ptr->next_cell->next_cell = NULL ;
	    cell_ptr->next_cell->first_imp = NULL ;
	    cell_ptr->next_cell->name = (char *) safe_malloc(
			(strlen(type) + 1) * sizeof( char ) ) ;
	    sprintf( cell_ptr->next_cell->name , "%s" , type ) ;
	    pin_ptr = NULL ;
	    active_cell_type = cell_ptr->next_cell ;
	    return(1) ;
	}
}
}
}
add_pin( x )
int x ;
{
if( pin_ptr == NULL ) {
pin_ptr = active_cell_type->first_imp =
			    (IMPBOX *) safe_malloc(sizeof(IMPBOX));
} else {
pin_ptr = pin_ptr->next_pin = (IMPBOX *) safe_malloc(sizeof(IMPBOX));
}
pin_ptr->x = x ;
pin_ptr->next_pin = NULL ;
return ;
}
find_imp_x( name , x )
char *name ;
int x ;
{
if( strcmp( "twfeed" , name ) == 0 ) {
if( x < 0 ) {
	return( 0 ) ;
} else {
	return( - fdWidth / 2 ) ;
}
}
active_cell_type = head_type ;
for( ; ; ) {
if( active_cell_type == NULL ) {
	fprintf(fpo,"Failed to find implicit type\n");
	printf("Failed to find implicit type: <%s>\n", name);
	fflush(stdout);
	exit(TW_FAIL) ;
}
if( strcmp( active_cell_type->name , name ) == 0 ) {
	break ;
}
active_cell_type = active_cell_type->next_cell ;
}
pin_ptr = active_cell_type->first_imp ;
for( ; ; ) {
if( pin_ptr == NULL ) {
	fprintf(fpo,"Failed to find implicit pin\n");
	printf("Failed to find implicit pin at x=<%d>\n", x);
	fflush(stdout);
	exit(TW_FAIL) ;
}
if( pin_ptr->x == x ) {
	break ;
}
pin_ptr = pin_ptr->next_pin ;
}
if( pin_ptr->next_pin == NULL ) {
return( active_cell_type->first_imp->x ) ;
} else {
return( - pin_ptr->next_pin->x ) ;
}
	
}
/* 当前文件是D:\Read\hash.c*/

maketabl()
{
int i ;
hashtab = ( HASHPTR * ) safe_malloc( 3001 * sizeof( HASHPTR ) ) ;
for( i = 0 ; i < 3001 ; i++ ) {
	hashtab[i] = ( HASHPTR ) NULL ;
}
return ;
}
delHtab()
{
int i ;
HASHPTR hptr , zapptr ;
for( i = 0 ; i < 3001 ; i++ ) {
	hptr = hashtab[i] ;
	if( hptr != (HASHPTR) NULL ) {
	    zapptr = hptr ;
	    while( hptr->hnext != (HASHPTR) NULL ) {
		hptr = hptr->hnext ;
		safe_free( zapptr ) ;
		zapptr = hptr ;
	    }
	    safe_free( hptr ) ;
	}
}
safe_free( hashtab ) ;
return ;
}
addhash( hname )
char hname[] ;
{
int i ;
HASHPTR hptr ;
unsigned int hsum = 0 ;
for( i = 0 ; i < strlen( hname ) ; i++ ) {
	hsum += ( unsigned int ) hname[i] ;
}
hsum %= 3001 ;
if( (hptr = hashtab[hsum]) == (HASHPTR) NULL ) {
	hptr = hashtab[hsum] = (HASHPTR) safe_malloc( sizeof( HASHBOX ) ) ;
	hptr->hnext = (HASHPTR) NULL ;
	hptr->hnum = ++netctr ;
	hptr->hname = (char *) safe_malloc( (strlen( hname ) + 1) *
						sizeof( char ) ) ;
	sprintf( hptr->hname , "%s" , hname ) ;
	return(1) ;
} else {
	for( ; ; ) {
	    if( strcmp( hname , hptr->hname ) == 0 ) {
		return(0) ;
	    }
	    if( hptr->hnext == (HASHPTR) NULL ) {
		hptr = hptr->hnext = (HASHPTR) safe_malloc( sizeof(HASHBOX));
		hptr->hnext = (HASHPTR) NULL ;
		hptr->hnum = ++netctr ;
		hptr->hname = (char *) safe_malloc( (strlen( hname ) + 1) *
						sizeof( char ) ) ;
		sprintf( hptr->hname , "%s" , hname ) ;
		return(1) ;
	    } else {
		hptr = hptr->hnext ;
	    }
	}
}
}
hashfind( hname )
char hname[] ;
{
int i ;
HASHPTR hptr ;
unsigned int hsum = 0 ;
for( i = 0 ; i < strlen( hname ) ; i++ ) {
	hsum += ( unsigned int ) hname[i] ;
}
hsum %= 3001 ;
if( (hptr = hashtab[hsum]) == (HASHPTR) NULL ) {
	return(0) ;
} else {
	for( ; ; ) {
	    if( strcmp( hname , hptr->hname ) == 0 ) {
		return( hptr->hnum ) ;
	    }
	    if( hptr->hnext == (HASHPTR) NULL ) {
		return(0) ;
	    } else {
		hptr = hptr->hnext ;
	    }
	}
}
}
/* 当前文件是D:\Read\implfeeds.c*/

implfeeds( row , xc )
int row , xc ;
{
IBOXPTR iptr ;
int minspan ;
minspan = 32000 ;
siptr = INULL ;
for( iptr = impFeeds[row] ; iptr != INULL ; iptr = iptr->niptr ) {
if( iptr->iactive <= 0 ) {
	if( ABS(iptr->aveXpos - xc) < minspan ) {
	    minspan = ABS(iptr->aveXpos - xc) ;
	    siptr = iptr ;
	}
}
}
if( siptr != INULL && minspan <= ifrange ) {
if( siptr->iactive == 0 ) {
	siptr->iactive = 1 ;
} else {
	siptr->iactive = 2 ;
}
return(1);
} else {
return(0);
}
}
impfix()
{
IBOXPTR iptr , niptr ;
IPBOXPTR ipptr , nipptr ;
int row ;
for( row = 1 ; row <= numRows ; row++ ) {
iptr = impFeeds[row] ;
if( iptr == INULL ) {
	continue ;
}
if( iptr->iactive != 1 ) {
	ipptr = iptr->iptr;
	while( ipptr != IPNULL ) {
	    nipptr = ipptr->npin ;
	    safe_free( ipptr ) ;
	    ipptr = nipptr ;
	}
	niptr = iptr->niptr ;
	safe_free( iptr ) ;
	iptr = niptr ;
	while( iptr != INULL ) {
	    if( iptr->iactive == 1 ) {
		break ;
	    } else {
		for( ipptr = iptr->iptr; ipptr != IPNULL ; ) {
		    nipptr = ipptr->npin ;
		    safe_free( ipptr ) ;
		    ipptr = nipptr ;
		}
		niptr = iptr->niptr ;
		safe_free( iptr ) ;
		iptr = niptr ;
	    }
	}
	impFeeds[row] = iptr ;
}
if( iptr != INULL ) {
	niptr = iptr->niptr ;
	while( niptr != INULL ) {
	    if( niptr->iactive != 1 ) {
		for( ipptr = niptr->iptr; ipptr != IPNULL ; ) {
		    nipptr = ipptr->npin ;
		    safe_free( ipptr ) ;
		    ipptr = nipptr ;
		}
		iptr->niptr = niptr->niptr ;
		safe_free( niptr ) ;
		niptr = iptr->niptr ;
	    } else {
		iptr = niptr ;
		niptr = iptr->niptr ;
	    }
	}
}
}
for( row = 1 ; row <= numRows ; row++ ) {
for( iptr = impFeeds[row] ; iptr != INULL ; iptr = iptr->niptr ) {
	iptr->iactive = 0 ;
}
}
return ;
}
impclobr()
{
IBOXPTR iptr , niptr ;
IPBOXPTR ipptr , nipptr ;
int row ;
for( row = 1 ; row <= numRows ; row++ ) {
iptr = impFeeds[row] ;
while( iptr != INULL ) {
	niptr = iptr->niptr ;
	for( ipptr = iptr->iptr; ipptr != IPNULL ; ) {
	    nipptr = ipptr->npin ;
	    safe_free( ipptr ) ;
	    ipptr = nipptr ;
	}
	safe_free( iptr ) ;
	iptr = niptr ;
}
}
safe_free( impFeeds ) ;
return ;
}
/* 当前文件是D:\Read\main.c*/

#define MAIN_VARS





#ifdef MEMORYMAN
#endif
main( argc , argv )
int argc ;
char *argv[] ;
{
FILE *fp ;
char filename[64] ;
int block ;
int i , net , changes ;
char input[40] ;
int l , r , b , t , cx , cy , cl , cr , cb , ct , cell , row ;
if( argc != 2 ) {
printf("circuit name not entered properly on command line\n");
printf("Proper syntax: TimberwolfSC circuitName\n");
exit(TW_FAIL);
}
sprintf( cktName , "%s" , argv[1] ) ;
sprintf( filename , "%s.out" , cktName ) ;
fpo = twopen( filename, "w" , ABORT ) ;
initProgram( "TimberWolfSC", "v4.3a" );
readParFile();
Yset_random_seed( randomSeed ) ;
sprintf( filename , "%s.blk" , cktName ) ;
fp = twopen( filename , "r" , ABORT ) ;
readblck( fp ) ;
twclose( fp ) ;
maxCellO = 0 ;
for( block = 1 ; block <= numblock ; block++ ) {
if( barray[block]->borient == 2 ) {
	maxCellO = 1 ;
	break ;
}
}
sprintf( filename , "%s.cel" , cktName ) ;
fp = twopen( filename , "r" , ABORT ) ;
readcell( fp ) ;
twclose( fp ) ;
sprintf( filename , "%s.net" , cktName ) ;
fp = twopen( filename , "r", ABORT  ) ;
readnets( fp ) ;
twclose( fp ) ;
iteration = 0 ;
T1 = 500.0 ;
t = 0 ;
b = 32000 ;
r = 0 ;
l = 32000 ;
for( block = 1 ; block <= numblock ; block++ ) {
cx = barray[block]->bxcenter ;
cy = barray[block]->bycenter ;
cl = barray[block]->bleft;
cr = barray[block]->bright;
cb = barray[block]->bbottom;
ct = barray[block]->btop;
if( cx + cr > r ) {
	r = cx + cr ;
}
if( cx + cl < l ) {
	l = cx + cl ;
}
if( cy + ct > t ) {
	t = cy + ct ;
}
if( cy + cb < b ) {
	b = cy + cb ;
}
}
blkxspan = r - l ;
blkyspan = t - b ;
ifrange = blkxspan * imprange ;
fprintf(fpo,"block x-span:%d  block y-span:%d\n",blkxspan,blkyspan);
fprintf(fpo,"implicit feed thru range: %d\n", ifrange ) ;
for( cell = 1 ; cell <= numcells + numterms ; cell++ ) {
cx = carray[ cell ]->cxcenter ;
cy = carray[ cell ]->cycenter ;
cl = carray[cell]->tileptr->left;
cr = carray[cell]->tileptr->right;
cb = carray[cell]->tileptr->bottom;
ct = carray[cell]->tileptr->top;
if( cx + cr > r ) {
	r = cx + cr ;
}
if( cx + cl < l ) {
	l = cx + cl ;
}
if( cy + ct > t ) {
	t = cy + ct ;
}
if( cy + cb < b ) {
	b = cy + cb ;
}
}
bdxlen = r - l ;
bdylen = t - b ;
lrtxspan = r ;
lrtyspan = t ;
for( net = 1 ; net <= numnets ; net++ ) {
netarray[net]->Vweight *= 2.0 / (rowSep + 1.0) ;
}
binpenCon = 4.0 * ((((double) numcells) / ((double) numblock) ) / 39.0) ;
binpenCon = (binpenCon > 4.0) ? binpenCon : 4.0 ;
binpenCon = 1.0 ;
roLenCon  = 3.0 ;
fprintf(fpo,"Using default value of bin.penalty.control:%f\n",
						binpenCon ) ;
funccost = findcost() ;
assignro() ;
initialize_rows() ;
fprintf(fpo,"\nNew Cost Function: Initial Horizontal Cost:%d\n",
					    initialize_cost() ) ;
vert_statistics() ;
fprintf(fpo,"New Cost Function: FEEDS:%d   MISSING_ROWS:%d\n\n",
			    tot_num_feeds , tot_missing_rows ) ;
fprintf( fpo , "bdxlen:%d  bdylen:%d\n", bdxlen , bdylen ) ;
fprintf( fpo , "l:%d  t:%d  r:%d  b:%d\n", l , t , r , b ) ;
			
fprintf( fpo, "\n\n\nTHIS IS THE ROUTE COST OF THE ");
fprintf( fpo, "CURRENT PLACEMENT: %d\n" , funccost ) ;
fprintf( fpo, "\n\n\nTHIS IS THE PENALTY OF THE ") ;
fprintf( fpo , "CURRENT PLACEMENT: %d\n" , penalty ) ;
fflush( fpo ) ;
if( !costonly ) {
Tzero = 0.1 ;
desired_accept = (double *) safe_malloc( 117 * sizeof(double) ) ;
for( i = 0 ; i <= 116 ; i++ ) {
	if( i < 7 ) {
	    desired_accept[i] = 50.0 ;
	} else {
	    desired_accept[i] = 50.5 -
		    ( (50.0 / 110.0) * (double)(i - 6) ) ;
	}
}
utemp() ;
} else {
if( connection_machine ) {
	unlap(-1) ;
	findunlap(-1) ;
	outcm() ;
}
if( doglobal ) {
	countf() ;
	sprintf( filename , "%s.cel" , cktName ) ;
	fp = twopen( filename , "r", ABORT  ) ;
	grdcell( fp ) ;
	twclose( fp ) ;
	reassign() ;
	if( addFeeds == 0 ) {
	    for( row = 1 ; row <= numblock ; row++ ) {
		nofeed[row] = 1 ;
	    }
	}
	findunlap(1) ;
	fdthrus = findfeeds(0) ;
	fdthrus += add_to_row[0] ;
	fixwolf( fdthrus ) ;
	findfeeds(1) ;
	unlap(-2) ;
	add_dummy_feeds( last_feed ) ;
	numcells += fdthrus ;
	if( stage >= 2 ) {
	    sprintf( filename , "%s.rs2" , cktName ) ;
	    fp = twopen( filename , "r", NOABORT  ) ;
	
	    if( fp ){
		fixfdpos(fp) ;
		twclose(fp) ;
	    }
	}
	findunlap(0) ;
	
	
	
	for( i = 1 ; i <= 8 ; i++ ) {
	    align_init() ;
	    changes = alignfeed() ;
	    fprintf(fpo,"Total Feed-Alignment Movement (Pass %d): %d\n",
						    i, changes );
	}
	align_init() ;
	
	findunlap(-1) ;
	moveable_cells = 0 ;
	for( cell = 1 ; cell <= numcells ; cell++ ) {
	    if( carray[cell]->cclass < 0 ) {
		continue ;
	    }
	    moveable_cells++ ;
	}
	globe() ;
	globroute() ;
	if( cswaps ) {
	    ugpair() ;
	}
	findrchk() ;
	fprintf(fpo,"\nFINAL NUMBER OF ROUTING TRACKS: %d\n\n",
						    tracks);
	for( i = 1 ; i <= numChans ; i++ ) {
	    fprintf(fpo,"MAX OF CHANNEL:%3d  is: %3d\n", i
					    , maxTrack[i]);
	}
	mergplist() ;
	outpins() ;
	output() ;
	safe_free( pinlist ) ;
} else {
	reassign() ;
	findunlap(1) ;
	output() ;
}
}
fprintf( fpo , "Number of Feed Thrus: %d\n", ffeeds ) ;
fprintf( fpo , "Number of Implicit Feed Thrus: %d\n", impcount ) ;
fprintf( fpo , "\nStatistics:\n");
fprintf( fpo , "Number of Standard Cells: %d\n",
				    numcells - fdthrus );
fprintf( fpo , "Number of Pads: %d \n", numterms );
fprintf( fpo , "Number of Nets: %d \n", numnets ) ;
fprintf( fpo , "Number of Pins: %d \n", maxterm ) ;
print_stats(fpo);
twclose(fpo) ;
exit(TW_OK);
}
/* 当前文件是D:\Read\mergplist.c*/


typedef struct tmpmerg {
int value ;
int next  ;
int first ;
}
TEMPMERG ;
TEMPMERG *tmp_pinlist ;



int *pinlist ;
int pinGroup ;
int *merge_array ;
int array_length ;
mergplist()
{
int segment , i , current_net ;
int chan , track , terminal ;
DENSITYPTR denptr , temptr ;
for( chan = 1 ; chan <= numChans ; chan++ ) {
for( track = 0 ; track <= max_tdensity+100 ; track++ ) {
	denptr = DboxHead[ chan ][ track ]->next ;
	while( denptr != DENSENULL ) {
	    temptr = denptr->next ;
	    safe_free( denptr->grdptr ) ;
	    safe_cfree( denptr ) ;
	    denptr = temptr ;
	}
	safe_cfree( DboxHead[ chan ][ track ] ) ;
}
safe_cfree( DboxHead[ chan ] ) ;
}
safe_cfree( DboxHead ) ;
for( terminal = 1 ; terminal <= maxterm + 2*numChans ; terminal++ ) {
safe_free( Tgrid[ terminal ] ) ;
}
safe_free( Tgrid ) ;
pinGroup = 0 ;
pinlist = (int *) safe_malloc( (maxterm + 1) * sizeof(int) );
for( i = 1 ; i <= maxterm ; i++ ) {
pinlist[i] = 0 ;
}
merge_array = (int *) safe_malloc( 100 * sizeof(int) );
merge_array[0] = 0 ;
tmp_pinlist = (TEMPMERG *) safe_malloc( 100 * sizeof(TEMPMERG) );
for( i = 0 ; i < 100 ; i++ ) {
tmp_pinlist[i].value = 0 ;
tmp_pinlist[i].next  = 0 ;
tmp_pinlist[i].first = i ;
}
array_length = 100 ;
current_net = aNetSeg[1].net ;
for( segment = 1 ; segment <= numSegs + 1 ; segment++ ) {
if( segment <= numSegs ) {
	if( aNetSeg[segment].net != current_net ) {
	    assign_group_values() ;
	    initialize_pins() ;
	    current_net = aNetSeg[segment].net ;
	}
	merge_pins( segment ) ;
} else {
	assign_group_values() ;
}
}
return ;
}
initialize_pins()
{
int i ;
for( i = 1 ; i <= merge_array[0] ; i++ ) {
tmp_pinlist[i].value = 0 ;
tmp_pinlist[i].next  = 0 ;
tmp_pinlist[i].first = i ;
}
merge_array[0] = 0 ;
return ;
}
add_pins( pin )
int pin ;
{
int i ;
for( i = 1 ; i <= merge_array[0] ; i++ ) {
if( pin == merge_array[i] ) {
	return(i) ;
}
}
if( ++merge_array[0] >= array_length ) {
array_length += 100 ;
merge_array = (int *) safe_realloc( merge_array ,
				(array_length) * sizeof(int) );
tmp_pinlist = (TEMPMERG *) safe_realloc( tmp_pinlist ,
				(array_length) * sizeof(TEMPMERG) );
for( i = merge_array[0] ; i < merge_array[0] + 100 ; i++ ) {
	tmp_pinlist[i].value = 0 ;
	tmp_pinlist[i].next  = 0 ;
	tmp_pinlist[i].first = i ;
}
}
merge_array[ merge_array[0] ] = pin ;
return( merge_array[0] ) ;
}
assign_group_values()
{
int i ;
for( i = 1 ; i <= merge_array[0] ; i++ ) {
pinlist[ merge_array[i] ] = tmp_pinlist[i].value ;
}
return ;
}
merge_pins( segment )
int segment ;
{
SEGBOXPTR boxptr ;
if( aNetSeg[segment].key != 0 ) {
aNetSeg[segment].current = aNetSeg[ aNetSeg[segment].key ].current ;
}
if( aNetSeg[segment].current == 0 ) {
boxptr = aNetSeg[segment].top ;
} else {
boxptr = aNetSeg[segment].bot ;
}
if( (boxptr->pin1 != boxptr->pin2) &&
((pinlist[boxptr->pin1] != pinlist[boxptr->pin2]) ||
			    ((pinlist[boxptr->pin1] == 0) &&
			    (pinlist[boxptr->pin2] == 0)))) {
merge( add_pins(boxptr->pin1) , add_pins(boxptr->pin2) ) ;
}
return ;
}
merge( i , j )
int i , j ;
{
int newval , next , first , secfirst ;
newval = ++pinGroup ;
secfirst = tmp_pinlist[j].first ;
first = tmp_pinlist[i].first ;
next = secfirst ;
do {
tmp_pinlist[next].value = newval ;
tmp_pinlist[next].first = first  ;
next = tmp_pinlist[next].next ;
} while( next != 0 ) ;
next = first ;
for( ; ; ) {
tmp_pinlist[next].value = newval ;
if( tmp_pinlist[next].next != 0 ) {
	next = tmp_pinlist[next].next ;
} else {
	tmp_pinlist[next].next = secfirst ;
	break ;
}
}
return ;
}
/* 当前文件是D:\Read\move.c*/

/* 当前文件是D:\Read\mt.h*/

#define TSTKSIZE 100
typedef struct MTA {
int sp;
int stk[TSTKSIZE][3][3];
int t[3][3];
int ti[3][3]; 
}MTMY;

static MTMY *mt = (MTMY *) NULL ;
point( x , y )
short int *x , *y ;
{
int xx , yy ;
if( mt == (MTMY *) NULL ) {
return;
}
xx = *x ;
yy = *y ;
MTPoint( mt , &xx , &yy ) ;
*x = xx ;
*y = yy ;
return ;
}
rect( l , b , r , t )
short int *l , *b , *r , *t ;
{
short int temp ;
point( l , b ) ;
point( r , t ) ;
if( *l > *r ) {
temp = *l   ;
*l   = *r   ;
*r   = temp ;
}
if( *b > *t ) {
temp = *b   ;
*b   = *t   ;
*t   = temp ;
}
return ;
}
move( moveType )
int moveType ;
{
if( mt == (MTMY *) NULL ) {
	mt = MTBegin() ;
}
MTIdenti( mt ) ;
switch( moveType ) {
case 0 :
return ;
case 1 :
MTM( mt ) ;
	    return     ;
case 2 :
MTMX( mt ) ;
	    return     ;
case 3 :
MTRotate( mt , -1 , 0 ) ;
	    return ;
case 4 :
MTMX( mt ) ;
	    MTRotate( mt , 0 , 1 ) ;
	    return ;
case 5 :
MTMX( mt ) ;
	    MTRotate( mt , 0 , -1 ) ;
	    return ;
case 6 :
MTRotate( mt , 0 , 1 ) ;
	    return ;
case 7 :
MTRotate( mt , 0 , -1 ) ;
	    return ;
}
}
/* 当前文件是D:\Read\mt.c*/

/* 当前文件是D:\Read\kenk.h*/

#define MXNAMLEN 255
#define UNIX42
#define PRIVATE static
#define PUBLIC
#define PROC void
#define FORWARD extern
#define IMPORTS extern
#define EXPORTS extern
#define EOS '\0'
typedef char * String;
#define ELIF else if
#define LOOP for(;;)
#define AND &&
#define OR ||
#define NOT !
#define ABS(dragon) ((dragon) >= 0 ? (dragon) : (-(dragon)))
/* 当前文件是D:\Read\lists.h*/

#ifdef TEST99
#endif
#define ALOCNODE(Type)\
(Type *)safe_malloc(sizeof(Type))
#define INSNODE(Type,head,node,succ)\
{\
if((head) == NULL) {\
(head) = (node);\
(node)->succ = NULL; }\
else {\
(node)->succ = (head);\
(head) = (node); }\
}
#define DELNODE(Type,head,node,succ)\
{\
register Type *lastType,*type;\
\
if((head) == NULL)\
;\
lastType = NULL;\
type = (head);\
while(type->succ != NULL)\
if(type == (node))\
break;\
else {\
lastType = type;\
type = type->succ; }\
if(lastType == NULL)\
(head) = (node)->succ;\
else lastType->succ = (node)->succ;\
}
#define FREENODE(Type,node)\
free(node);

typedef enum {false,true} Bool;
void MTIdenti() ;
static void MTInvert();
MTMY *MTBegin()
{
MTMY *t;
if((t = ALOCNODE(MTMY)) == NULL)
return(NULL);
t->sp = 0;
MTIdenti(t);
return(t);
}
MTEnd(t)
MTMY *t;
{
FREENODE(MTMY,t);
}
void MTIdenti(t)
MTMY *t;
{
t->ti[0][0] = t->ti[1][1] = t->ti[2][2] =
t->t[0][0] = t->t[1][1] = t->t[2][2] = 1;
t->t[0][1] = t->t[1][0] = t->t[0][2] = t->t[1][2] = t->t[2][0] =
t->t[2][1] = t->ti[0][1] = t->ti[1][0] = t->ti[0][2] = t->ti[1][2] =
t->ti[2][0] = t->ti[2][1] = 0;
}
MTTransl(t,x,y)
MTMY *t;
int x,y;
{
t->t[2][0] = t->t[2][0]+x;
t->t[2][1] = t->t[2][1]+y;
MTInvert(t);
}
MTM(t)
MTMY *t;
{
t->t[0][1] = -t->t[0][1];
t->t[1][1] = -t->t[1][1];
t->t[2][1] = -t->t[2][1];
MTInvert(t);
}
MTMX(t)
MTMY *t;
{
t->t[0][0] = -t->t[0][0];
t->t[1][0] = -t->t[1][0];
t->t[2][0] = -t->t[2][0];
MTInvert(t);
}
MTRotate(t,x,y)
MTMY *t;
int x,y;
{
register int i1,i2;
if(x == 0) {
if(ABS(y) > 1)
if(y < 0)
	y = -1;
else y = 1; }
ELIF(y == 0) {
if(ABS(x) > 1)
if(x < 0)
	x = -1;
else x = 1; }
if(x == 1 AND y == 0)
return;
ELIF(x == 0 AND y == -1)  {
i1 = t->t[0][0];
t->t[0][0] = t->t[0][1];
t->t[0][1] = -i1;
i1 = t->t[1][0];
t->t[1][0] = t->t[1][1];
t->t[1][1] = -i1;
i1 = t->t[2][0];
t->t[2][0] = t->t[2][1];
t->t[2][1] = -i1; }
ELIF(x == 0 AND y == 1)  {
i1 = t->t[0][0];
t->t[0][0] = -t->t[0][1];
t->t[0][1] = i1;
i1 = t->t[1][0];
t->t[1][0] = -t->t[1][1];
t->t[1][1] = i1;
i1 = t->t[2][0];
t->t[2][0] = -t->t[2][1];
t->t[2][1] = i1; }
ELIF(x == -1 AND y == 0)  {
register int i,j;
for(i = 0;i < 3;++i)
for(j = 0;j < 2;++j)
t->t[i][j] = -t->t[i][j]; }
MTInvert(t);
}
MTConcat(t,a)
MTMY *t;
int a[3][3];
{
register int i1,i2,i3,i4,i5,i6;
i1 = t->t[0][0]*a[0][0]+
t->t[0][1]*a[1][0];
i2 = t->t[0][0]*a[0][1]+
t->t[0][1]*a[1][1];
i3 = t->t[1][0]*a[0][0]+
t->t[1][1]*a[1][0];
i4 = t->t[1][0]*a[0][1]+
t->t[1][1]*a[1][1];
i5 = t->t[2][0]*a[0][0]+
t->t[2][1]*a[1][0]+
a[2][0];
i6 = t->t[2][0]*a[0][1]+
t->t[2][1]*a[1][1]+
a[2][1];
t->t[0][0] = i1;
t->t[0][1] = i2;
t->t[1][0] = i3;
t->t[1][1] = i4;
t->t[2][0] = i5;
t->t[2][1] = i6;
MTInvert(t);
}
MTPoint(t,x,y)
MTMY *t;
int *x,*y;
{
int i1;
i1 = *x*t->t[0][0]+*y*t->t[1][0]+
t->t[2][0];
*y = *x*t->t[0][1]+*y*t->t[1][1]+
t->t[2][1];
*x = i1;
}
MTIPoint(t,x,y)
MTMY *t;
int *x,*y;
{
int i1;
i1 = *x*t->ti[0][0]+*y*t->ti[1][0]+
t->ti[2][0];
*y = *x*t->ti[0][1]+*y*t->ti[1][1]+
t->ti[2][1];
*x = i1;
}
Bool MTPushP(t)
MTMY *t;
{
register int i,j;
if(t->sp == TSTKSIZE)
return(false);
for(i = 0;i < 3;++i)
for(j = 0;j < 2;++j)
t->stk[t->sp][i][j] =
t->t[i][j];
++t->sp;
return(true);
}
Bool MTPopP(t)
MTMY *t;
{
register int i,j;
if(t->sp == 0)
return(false);
--t->sp;
for(i = 0;i < 3;++i)
for(j = 0;j < 2;++j)
t->t[i][j] = t->stk[t->sp]
[i][j];
MTInvert(t);
return(true);
}
Bool MTPremul(t)
MTMY *t;
{
register int i1,i2,i3,i4,i5,i6,sp;
if(t->sp == 0)
return(false);
sp = t->sp-1;
i1 = t->t[0][0]*t->stk[sp][0][0]+
t->t[0][1]*t->stk[sp][1][0];
i2 = t->t[0][0]*t->stk[sp][0][1]+
t->t[0][1]*t->stk[sp][1][1];
i3 = t->t[1][0]*t->stk[sp][0][0]+
t->t[1][1]*t->stk[sp][1][0];
i4 = t->t[1][0]*t->stk[sp][0][1]+
t->t[1][1]*t->stk[sp][1][1];
i5 = t->t[2][0]*t->stk[sp][0][0]+
t->t[2][1]*t->stk[sp][1][0]+
t->stk[sp][2][0];
i6 = t->t[2][0]*t->stk[sp][0][1]+
t->t[2][1]*t->stk[sp][1][1]+
t->stk[sp][2][1];
t->t[0][0] = i1;
t->t[0][1] = i2;
t->t[1][0] = i3;
t->t[1][1] = i4;
t->t[2][0] = i5;
t->t[2][1] = i6;
MTInvert(t);
return(true);
}
Bool MTDecode(t,s)
MTMY *t;
char **s;
{
register int a,b,c,d,tx,ty;
static char cif[81];
if(NOT MTPushP(t))
return(false);
a = t->t[0][0];
b = t->t[1][0];
c = t->t[0][1];
d = t->t[1][1];
tx = t->t[2][0];
ty = t->t[2][1];
MTIdenti(t);
if(a == 0 AND b == 1 AND c == 1 AND d == 0) {
MTMX(t);
MTRotate(t,0,-1);
MTTransl(t,tx,ty);
if(tx != 0 OR ty != 0)
sprintf(cif,"MX R 0 -1 T %d %d",tx,ty);
else sprintf(cif,"MX R 0 -1"); }
ELIF(a == 0 AND b == -1 AND c == -1 AND d == 0) {
MTMX(t);
MTRotate(t,0,1);
MTTransl(t,tx,ty);
if(tx != 0 OR ty != 0)
sprintf(cif,"MX R 0 1 T %d %d",tx,ty);
else sprintf(cif,"MX R 0 1"); }
ELIF(a == 0 AND b == 1 AND c == -1 AND d == 0) {
MTRotate(t,0,-1);
MTTransl(t,tx,ty);
if(tx != 0 OR ty != 0)
sprintf(cif,"R 0 -1 T %d %d",tx,ty);
else sprintf(cif,"R 0 -1"); }
ELIF(a == 0 AND b == -1 AND c == 1 AND d == 0) {
MTRotate(t,0,1);
MTTransl(t,tx,ty);
if(tx != 0 OR ty != 0)
sprintf(cif,"R 0 1 T %d %d",tx,ty);
else sprintf(cif,"R 0 1"); }
ELIF(a == 1 AND b == 0 AND c == 0 AND d == 1) {
MTTransl(t,tx,ty);
if(tx != 0 OR ty != 0)
sprintf(cif,"T %d %d",tx,ty);
else cif[0] = EOS;}
ELIF(a == -1 AND b == 0 AND c == 0 AND d == -1) {
MTRotate(t,-1,0);
MTTransl(t,tx,ty);
if(tx != 0 OR ty != 0)
sprintf(cif,"R -1 0 T %d %d",tx,ty);
else sprintf(cif,"R -1 0"); }
ELIF(a == -1 AND b == 0 AND c == 0 AND d == 1) {
MTMX(t);
MTTransl(t,tx,ty);
if(tx != 0 OR ty != 0)
sprintf(cif,"MX T %d %d",tx,ty);
else sprintf(cif,"MX"); }
ELIF(a == 1 AND b == 0 AND c == 0 AND d == -1) {
MTM(t);
MTTransl(t,tx,ty);
if(tx != 0 OR ty != 0)
sprintf(cif,"MY T %d %d",tx,ty);
else sprintf(cif,"MY"); }
else {
MTPopP(t);
return(false); }
if(t->t[0][0] == a AND t->t[0][1] == c AND t->t[1][0] == b AND
						     t->t[1][1] == d) {
MTPopP(t);
*s = cif;
return(true); }
else {
MTPopP(t);
return(false); }
}
static void MTInvert(t)
MTMY *t;
{
t->ti[0][0] = t->t[0][0];
t->ti[0][1] = t->t[1][0];
t->ti[1][0] = t->t[0][1];
t->ti[1][1] = t->t[1][1];
t->ti[2][0] = -t->t[2][0]*t->t[0][0]-t->t[2][1]*t->t[0][1];
t->ti[2][1] = -t->t[2][0]*t->t[1][0]-t->t[2][1]*t->t[1][1];
t->ti[0][2] = t->ti[1][2] = 0;
t->ti[2][2] = 1;
}

/* 当前文件是D:\Read\okmalloc.c*/

#define  heap_error_base   0x40060000
#define  heap_bad_block    (heap_error_base + 1)
#define  heap_no_mem       (heap_error_base + 2)
char *safe_malloc(size)
unsigned size;
{
char *p;

if ((p = malloc(size)) == (char *) 0) {
cleanupHandler(heap_no_mem,"safe_malloc");
}
return p;
}
char *safe_realloc(obj, size)
char *obj;
unsigned size;
{
char *p;

if ((p = realloc(obj, size)) == (char *) 0) {
cleanupHandler(heap_no_mem,"safe_realloc");
}
return p;
}
char *safe_calloc(size, num)
unsigned size, num;
{
char *p;

if ((p = calloc(size, num)) == (char *) 0) {
cleanupHandler(heap_no_mem,"safe_calloc");
}
return p;
}
safe_free(ptr)
char *ptr;
{
free(ptr);
return;
}
safe_cfree(ptr)
char *ptr;
{
#ifndef SPEC_CPU2000
cfree(ptr);
#endif
return;
}
int cleanup(sigNum)
int sigNum ;
{
cleanupHandler(-sigNum,NULL) ;
}
int cleanupHandler(status,function)
int status ;
char *function ;
{
exit(1) ;
}
/* 当前文件是D:\Read\outcm.c*/

outcm()
{
char filename[64] ;
FILE *fp ;
NBOXPTR netptr ;
int net , x , local_pin_count , pin_count ;
int cell , row , length , xstart ;
sprintf( filename , "%s.cm" , cktName ) ;
fp = twopen ( filename , "w", ABORT ) ;
pin_count = 0 ;
for( net = 1 ; net <= numnets ; net++ ) {
local_pin_count = 0 ;
for( netptr = netarray[net]->netptr; netptr; netptr = netptr->nterm){
	if( netptr->cell <= numcells ) {
	    local_pin_count++ ;
	}
}
if( local_pin_count > 1 ) {
	pin_count += local_pin_count ;
}
}
fprintf(fp,"%d\n", pin_count ) ;
for( net = 1 ; net <= numnets ; net++ ) {
local_pin_count = 0 ;
for( netptr = netarray[net]->netptr; netptr; netptr = netptr->nterm){
	if( netptr->cell <= numcells ) {
	    local_pin_count++ ;
	}
}
if( local_pin_count <= 1 ) {
	continue ;
}
for( netptr = netarray[net]->netptr; netptr; netptr = netptr->nterm){
	if( netptr->cell > numcells ) {
	    continue ;
	}
	cell = netptr->cell ;
	row  = carray[cell]->cblock ;
	x    = netptr->xpos ;
	length = carray[cell]->tileptr->right -
					carray[cell]->tileptr->left ;
	xstart = carray[cell]->cxcenter + carray[cell]->tileptr->left ;
	fprintf(fp,"%8d %8d %8d %8d %8d %8d\n", row, cell, net,
						 x, length, xstart );
}
}
fclose(fp);
return ;
}
/* 当前文件是D:\Read\outpins.c*/

#define T   2
#define R   3



outpins()
{
char filename[64] ;
FILE *fp ;
NBOXPTR netptr ;
SEGBOXPTR sptr ;
int net , b , e , seg , x , y , pin , pinloc , chan , xx ;
int chan1, chan2 ;
int r_core_edge , l_core_edge , l_end , r_end , cell , blk ;
int pin2_1 , pin2_2 ;
sprintf( filename , "%s.pin" , cktName ) ;
fp = twopen ( filename , "w", ABORT ) ;
r_core_edge = 0 ;
l_core_edge = 32000 ;
for( blk = 1 ; blk <= numblock ; blk++ ) {
cell = pairArray[blk][ pairArray[blk][0] ] ;
r_end = carray[cell]->cxcenter + carray[cell]->tileptr->right ;
cell = pairArray[blk][1] ;
l_end = carray[cell]->cxcenter + carray[cell]->tileptr->left ;
if( r_end > r_core_edge ) {
	r_core_edge = r_end ;
}
if( l_end < l_core_edge ) {
	l_core_edge = l_end ;
}
}
for( net = 1 ; net <= numnets ; net++ ) {
netptr = netarray[net]->netptr ;
for( ; netptr != NETNULL ; netptr = netptr->nterm ) {
	pin = netptr->terminal ;
	if( pinlist[pin] == 0 ) {
	    continue ;
	}
	pinloc = - netptr->pinloc ;
	x = netptr->xpos ;
	y = netptr->ypos ;
	b = anet[net] ;
	e = anet[net + 1] - 1 ;
	
	chan1 = -10 ;
	chan2 = -10 ;
	for( seg = b ; seg <= e ; seg++ ) {
	    if( aNetSeg[seg].current == 0 ) {
		sptr = aNetSeg[seg].top ;
	    } else {
		sptr = aNetSeg[seg].bot ;
	    }
	    if( pin == sptr->pin1 || pin == sptr->pin2 ) {
		chan = sptr->channel ;
		if( chan1 < 0 ) {
		    chan1 = chan ;
		    if( pin == sptr->pin1 ) {
			pin2_1 = sptr->pin2 ;
		    } else {
			pin2_1 = sptr->pin1 ;
		    }
		} else if( chan1 == chan ) {
		    continue ;
		} else if( chan2 < 0 ) {
		    chan2 = chan ;
		    if( pin == sptr->pin1 ) {
			pin2_2 = sptr->pin2 ;
		    } else {
			pin2_2 = sptr->pin1 ;
		    }
		    break ;
		}
	    }
	}
	if( (netptr->cell <= numcells && pinloc != 0) ||
			(netptr->cell > numcells &&
			(carray[netptr->cell]->padside == 2 ||
			 carray[netptr->cell]->padside == B ||
			 carray[netptr->cell]->padside == MTT ||
			 carray[netptr->cell]->padside == MBB)) ) {
	    if( netptr->cell > numcells ) {
		if( carray[netptr->cell]->padside == 2 ||
			carray[netptr->cell]->padside == MTT ) {
		    fprintf(fp,"%s %d %s %s %d %d %d %d 0\n",
				netarray[net]->name, pinlist[pin],
				carray[netptr->cell]->cname,
				pinnames[pin], x, y, chan1 , 1 ) ;
		} else if( carray[netptr->cell]->padside == B ||
			carray[netptr->cell]->padside == MBB ) {
		    fprintf(fp,"%s %d %s %s %d %d %d %d 0\n",
				netarray[net]->name, pinlist[pin],
				carray[netptr->cell]->cname,
				pinnames[pin], x, y, chan1 , -1 ) ;
		}
	    } else {
		fprintf(fp,"%s %d %s %s %d %d %d %d 0\n",
			    netarray[net]->name, pinlist[pin],
			    carray[netptr->cell]->cname,
			    pinnames[pin], x, y, chan1 , pinloc ) ;
	    }
	} else if( netptr->cell > numcells ) {
	    if( carray[netptr->cell]->padside == L   ||
		carray[netptr->cell]->padside == MUL ||
		carray[netptr->cell]->padside == ML  ||
		carray[netptr->cell]->padside == MLL ){
		fprintf(fp,"%s %d %s %s %d %d %d %d 0\n",
				netarray[net]->name, pinlist[pin],
				carray[netptr->cell]->cname,
				pinnames[pin], x, y, -1 , 1 ) ;
		if( carray[tearray[pin2_1]->cell]->padside != L   &&
		    carray[tearray[pin2_1]->cell]->padside != MUL &&
		    carray[tearray[pin2_1]->cell]->padside != ML  &&
		    carray[tearray[pin2_1]->cell]->padside != MLL ){
		    if( carray[netptr->cell]->padside == L ) {
			xx = l_core_edge ;
		    } else {
			xx = min_l_chan_edge( chan1 ) ;
			if( tearray[pin2_1]->xpos < xx ) {
			    xx = x ;
			}
		    }
		    if( netptr->row == chan1 ) {
			y = barray[netptr->row]->bycenter -
						rowHeight ;
		    } else {
			y = barray[netptr->row]->bycenter +
						rowHeight ;
		    }
		    fprintf(fp," %s %d %s %s %d %d %d %d 0\n",
			netarray[net]->name, pinlist[pin],
			"PSEUDO_CELL",
			"PSEUDO_PIN", xx, y, chan1, -2 ) ;
		    fprintf(fp," %s %d %s %s %d %d %d %d 0\n",
			netarray[net]->name, pinlist[pin],
			"PSEUDO_CELL",
			"PSEUDO_PIN", xx, y, -1, -1 ) ;
		    if( chan2 > 0 ) {
			if( carray[tearray[pin2_2]->cell]->padside
							!= L   &&
			    carray[tearray[pin2_2]->cell]->padside
							!= MUL &&
			    carray[tearray[pin2_2]->cell]->padside
							!= ML  &&
			    carray[tearray[pin2_2]->cell]->padside
							!= MLL ){
			    if( carray[netptr->cell]->padside==L){
				xx = l_core_edge ;
			    } else {
				xx = min_l_chan_edge( chan2 ) ;
				if( tearray[pin2_2]->xpos < xx ) {
				    xx = x ;
				}
			    }
			    if( netptr->row == chan2 ) {
				y = barray[netptr->row]->bycenter -
							rowHeight ;
			    } else {
				y = barray[netptr->row]->bycenter +
							rowHeight ;
			    }
			    fprintf(fp,
				" %s %d %s %s %d %d %d %d 0\n",
				netarray[net]->name, pinlist[pin],
				"PSEUDO_CELL",
				"PSEUDO_PIN", xx, y, chan2, -2 ) ;
			    fprintf(fp,
				" %s %d %s %s %d %d %d %d 0\n",
				netarray[net]->name, pinlist[pin],
				"PSEUDO_CELL",
				"PSEUDO_PIN", xx, y, -1, -1 ) ;
			}
		    }
		}
	    } else if( carray[netptr->cell]->padside == R    ||
		       carray[netptr->cell]->padside == MUR  ||
		       carray[netptr->cell]->padside == MR   ||
		       carray[netptr->cell]->padside == MLR  ){
		fprintf(fp,"%s %d %s %s %d %d %d %d 0\n",
				netarray[net]->name, pinlist[pin],
				carray[netptr->cell]->cname,
				pinnames[pin], x, y, -2 , 1 ) ;
		if( carray[tearray[pin2_1]->cell]->padside != R   &&
		    carray[tearray[pin2_1]->cell]->padside != MUR &&
		    carray[tearray[pin2_1]->cell]->padside != MR  &&
		    carray[tearray[pin2_1]->cell]->padside != MLR ){
		    if( carray[netptr->cell]->padside == R ) {
			xx = r_core_edge ;
		    } else {
			xx = min_r_chan_edge( chan1 ) ;
			if( tearray[pin2_1]->xpos > xx ) {
			    xx = x ;
			}
		    }
		    if( netptr->row == chan1 ) {
			y = barray[netptr->row]->bycenter -
						rowHeight ;
		    } else {
			y = barray[netptr->row]->bycenter +
						rowHeight ;
		    }
		    fprintf(fp," %s %d %s %s %d %d %d %d 0\n",
			netarray[net]->name, pinlist[pin],
			"PSEUDO_CELL",
			"PSEUDO_PIN", xx, y, chan1, 2 ) ;
		    fprintf(fp," %s %d %s %s %d %d %d %d 0\n",
			netarray[net]->name, pinlist[pin],
			"PSEUDO_CELL",
			"PSEUDO_PIN", xx, y, -2, -1 ) ;
		    if( chan2 > 0 ) {
			if( carray[tearray[pin2_2]->cell]->padside
							!= R   &&
			    carray[tearray[pin2_2]->cell]->padside
							!= MUR &&
			    carray[tearray[pin2_2]->cell]->padside
							!= MR  &&
			    carray[tearray[pin2_2]->cell]->padside
							!= MLR ){
			    if( carray[netptr->cell]->padside==R){
				xx = r_core_edge ;
			    } else {
				xx = min_r_chan_edge( chan2 ) ;
				if( tearray[pin2_2]->xpos > xx ) {
				    xx = x ;
				}
			    }
			    if( netptr->row == chan2 ) {
				y = barray[netptr->row]->bycenter -
							rowHeight ;
			    } else {
				y = barray[netptr->row]->bycenter +
							rowHeight ;
			    }
			    fprintf(fp,
				" %s %d %s %s %d %d %d %d 0\n",
				netarray[net]->name, pinlist[pin],
				"PSEUDO_CELL",
				"PSEUDO_PIN", xx, y, chan2, 2 ) ;
			    fprintf(fp,
				" %s %d %s %s %d %d %d %d 0\n",
				netarray[net]->name, pinlist[pin],
				"PSEUDO_CELL",
				"PSEUDO_PIN", xx, y, -2, -1 ) ;
			}
		    }
		}
	    }
	} else {
	    if( chan1 == netptr->row ) {
		fprintf(fp,
		     "%s %d %s %s %d %d %d %d 0\n",
		    netarray[net]->name,
		    pinlist[pin],
		    carray[netptr->cell]->cname,
		    pinnames[pin], x, y, chan1 , 1 ) ;
	    } else {
		fprintf(fp,
		     "%s %d %s %s %d %d %d %d 0\n",
		    netarray[net]->name,
		    pinlist[pin],
		    carray[netptr->cell]->cname,
		    pinnames[pin], x, y, chan1 , -1 ) ;
	    }
	    if( chan2 > 0 ) {
		if( chan2 == netptr->row ) {
		    fprintf(fp,
			 "%s %d %s %s %d %d %d %d 0\n",
			netarray[net]->name,
			pinlist[pin],
			carray[netptr->cell]->cname,
			pinnames[pin], x, y, chan2 , 1 ) ;
		} else {
		    fprintf(fp,
			 "%s %d %s %s %d %d %d %d 0\n",
			netarray[net]->name,
			pinlist[pin],
			carray[netptr->cell]->cname,
			pinnames[pin], x, y, chan2 , -1 ) ;
		}
	    }
	}
}
}
twclose(fp);
return ;
}
min_r_chan_edge( channel )
int channel ;
{
int cell , end , end2 ;
if( channel == 1 ) {
cell = pairArray[1][ pairArray[1][0] ] ;
end = carray[cell]->cxcenter + carray[cell]->tileptr->right ;
} else if( channel == numblock + 1 ) {
cell = pairArray[numblock][ pairArray[numblock][0] ] ;
end = carray[cell]->cxcenter + carray[cell]->tileptr->right ;
} else {
cell = pairArray[channel - 1][ pairArray[channel - 1][0] ] ;
end = carray[cell]->cxcenter + carray[cell]->tileptr->right ;
cell = pairArray[channel][ pairArray[channel][0] ] ;
end2 = carray[cell]->cxcenter + carray[cell]->tileptr->right ;
end = (end < end2) ? end : end2 ;
}
return( end );
}
min_l_chan_edge( channel )
int channel ;
{
int cell , end , end2 ;
if( channel == 1 ) {
cell = pairArray[1][1] ;
end = carray[cell]->cxcenter + carray[cell]->tileptr->left ;
} else if( channel == numblock + 1 ) {
cell = pairArray[numblock][1] ;
end = carray[cell]->cxcenter + carray[cell]->tileptr->left ;
} else {
cell = pairArray[channel - 1][1] ;
end = carray[cell]->cxcenter + carray[cell]->tileptr->left ;
cell = pairArray[channel][1] ;
end2 = carray[cell]->cxcenter + carray[cell]->tileptr->left ;
end = (end > end2) ? end : end2 ;
}
return( end );
}
/* 当前文件是D:\Read\output.c*/

int comparex() ;





output()
{
FILE *fpp1 , *fpp2 ;
int locx , locy , height , width , k , Wwd ;
int xloc , i , cell , block , orient ;
int num ;
int xloc2 , yloc2 , yloc ;
int *array , desire ;
int left , right , bottom , top , end ;
char filename[64] ;
CBOXPTR cellptr ;
sprintf( filename , "%s.pl1" , cktName ) ;
fpp1 = twopen( filename , "w", ABORT ) ;
sprintf( filename , "%s.pl2" , cktName ) ;
fpp2 = twopen( filename , "w", ABORT ) ;
for( block = 1 ; block <= numblock ; block++ ) {
left   = barray[block]->bxcenter + barray[block]->bleft   ;
right  = barray[block]->bxcenter + barray[block]->bright  ;
bottom = barray[block]->bycenter + barray[block]->bbottom ;
top    = barray[block]->bycenter + barray[block]->btop    ;
if( restart == 0 && costonly == 1 ) {
	desire = barray[block]->desire ;
} else {
	if( pairArray[block][0] > 0 ) {
	    cell = pairArray[block][ pairArray[block][0] ] ;
	    end  = carray[cell]->cxcenter + carray[cell]->tileptr
			    ->right ;
	    desire = end - left ;
	} else {
	    desire = 0 ;
	}
}
if( barray[block]->borient > 0 ) {
	fprintf(fpp2,"%d %d %d  %d %d  0 0\n", block ,
			    left, bottom, left + desire, top ) ;
} else {
	fprintf(fpp2,"%d %d %d  %d %d  0 0\n", block ,
			    left, bottom, right, bottom + desire ) ;
}
num = pairArray[block][0] ;
if( num == 0 ) {
	continue ;
}
array = pairArray[block] + 1 ;
for( i = 0 ; i < num ; i++ ) {
	cell = array[ i ] ;
	cellptr = carray[ cell ] ;
	orient = cellptr->corient ;
	xloc = cellptr->cxcenter + cellptr->tileptr->left ;
	yloc = cellptr->cycenter + cellptr->tileptr->bottom ;
	xloc2 = cellptr->tileptr->right -
		cellptr->tileptr->left ;
	yloc2 = cellptr->tileptr->top -
		cellptr->tileptr->bottom ;
	fprintf(fpp1,"%s %d %d  %d %d  %d %d\n",
			    cellptr->cname ,
			    xloc, yloc, xloc + xloc2,
			    yloc + yloc2, orient, block ) ;
}
}
for( i = numcells + 1 ; i <= numcells + numterms ; i++ ) {
cellptr = carray[ i ]  ;
orient = cellptr->corient ;
locx = cellptr->cxcenter + cellptr->tileptr->left ;
locy = cellptr->cycenter + cellptr->tileptr->bottom;
height = cellptr->tileptr->top - cellptr->tileptr->bottom ;
width = cellptr->tileptr->right - cellptr->tileptr->left ;
fprintf(fpp1,"%s %d %d  %d %d  %d 0\n", cellptr->cname ,
				    locx, locy, locx + width,
				    locy + height, orient ) ;
fprintf(fpp2,"%s %d %d  %d %d  %d 0\n", cellptr->cname ,
				    locx, locy, locx + width,
				    locy + height, orient ) ;
}
twclose( fpp1 ) ;
twclose( fpp2 ) ;
return ;
}
comparex( a , b )
int *a , *b ;
{
return( carray[ *a ]->cxcenter - carray[ *b ]->cxcenter ) ;
}

/* 当前文件是D:\Read\purcost.c*/


purcost( segment )
int segment ;
{
SEGBOXPTR top , bot , asegptr , bsegptr ;
CHANGRDPTR aptr1 , aptr2 , bptr1 , bptr2 , bptr , fptr , ptr ;
CHANGRDPTR saptr , eaptr , sbptr , ebptr ;
DENSITYPTR denptr , headptr ;
int penalty , current , check ;
int x , achannel , bchannel , aMaxVal , bMaxVal ;
int maxaa , maxbb ;
int aoutside , binside ;
int ax1 , ax2 , bx1 , bx2 ;
int net , Flag , track ;
penalty = 0 ;
if( aNetSeg[segment].nflag == 0 ) {
top = aNetSeg[segment].top ;
bot = aNetSeg[segment].bot ;
current = aNetSeg[segment].current ;
} else {
top = aNetSeg[segment].ntop ;
bot = aNetSeg[segment].nbot ;
current = aNetSeg[segment].ncurrent ;
}
if( current == 0 ) {
asegptr = top ;
bsegptr = bot ;
} else {
asegptr = bot ;
bsegptr = top ;
}
achannel = asegptr->channel ;
bchannel = bsegptr->channel ;
aptr1 = asegptr->pin1ptr ;
aptr2 = asegptr->pin2ptr ;
bptr1 = bsegptr->pin1ptr ;
bptr2 = bsegptr->pin2ptr ;
aMaxVal = nmaxTrack[achannel] ;
bMaxVal = nmaxTrack[bchannel] ;
ax1 = aptr1->netptr->xpos ;
ax2 = aptr2->netptr->xpos ;
bx1 = bptr1->netptr->xpos ;
bx2 = bptr2->netptr->xpos ;
net = aNetSeg[segment].net ;
if( aptr1->nSegType > 0 ) {
Flag = 0 ;
bptr = aptr1 ;
while( bptr->nprevgrd != GRDNULL
		&& bptr->nprevgrd->netptr->xpos == ax1 ) {
	if( net == tearray[bptr->nprevgrd->netptr->terminal]->net
			    && bptr->nprevgrd->nSegType < 0 ) {
	    Flag = 1 ;
	    saptr = aptr1->nnextgrd ;
	    while( saptr->netptr->xpos == ax1 ) {
		saptr = saptr->nnextgrd ;
	    }
	    break ;
	} else {
	    bptr = bptr->nprevgrd ;
	}
}
if( !Flag ) {
	saptr = aptr1->nnextgrd ;
	while( saptr->netptr->xpos == ax1 ) {
	    if( net == tearray[saptr->netptr->terminal]->net
				&& saptr->nSegType < 0 ) {
		Flag = 1 ;
	    }
	    saptr = saptr->nnextgrd ;
	}
}
if( !Flag ) {
	saptr = bptr ;
}
} else {
if( ax1 != gxstart ) {
	saptr = aptr1->nnextgrd ;
	while( saptr->netptr->xpos == ax1 ) {
	    saptr = saptr->nnextgrd ;
	}
} else {
	saptr = aptr1 ;
}
}
if( aptr2->nSegType < 0 ) {
Flag = 0 ;
fptr = aptr2 ;
while( fptr->nnextgrd != GRDNULL
		&& fptr->nnextgrd->netptr->xpos == ax2 ) {
	if( net == tearray[fptr->nnextgrd->netptr->terminal]->net
			    && fptr->nnextgrd->nSegType > 0 ) {
	    Flag = 1 ;
	    eaptr = aptr2->nprevgrd ;
	    while( eaptr->netptr->xpos == ax2 ) {
		eaptr = eaptr->nprevgrd ;
	    }
	    break ;
	} else {
	    fptr = fptr->nnextgrd ;
	}
}
if( !Flag ) {
	eaptr = aptr2->nprevgrd ;
	while( eaptr->netptr->xpos == ax2 ) {
	    if( net == tearray[eaptr->netptr->terminal]->net
				&& eaptr->nSegType > 0 ) {
		Flag = 1 ;
	    }
	    eaptr = eaptr->nprevgrd ;
	}
}
if( !Flag ) {
	eaptr = fptr ;
}
} else {
if( ax2 != gxstop ) {
	eaptr = aptr2->nprevgrd ;
	while( eaptr->netptr->xpos == ax2 ) {
	    eaptr = eaptr->nprevgrd ;
	}
} else {
	eaptr = aptr2 ;
}
}
if( bptr1->nSegType >= 0 ) {
Flag = 0 ;
bptr = bptr1 ;
while( bptr->nprevgrd != GRDNULL
		&& bptr->nprevgrd->netptr->xpos == bx1 ) {
	if( net == tearray[bptr->nprevgrd->netptr->terminal]->net
			    && bptr->nprevgrd->nSegType < 0 ) {
	    Flag = 1 ;
	    sbptr = bptr1->nnextgrd ;
	    while( sbptr->netptr->xpos == bx1 ) {
		sbptr = sbptr->nnextgrd ;
	    }
	    break ;
	} else {
	    bptr = bptr->nprevgrd ;
	}
}
if( !Flag ) {
	sbptr = bptr1->nnextgrd ;
	while( sbptr->netptr->xpos == bx1 ) {
	    if( net == tearray[sbptr->netptr->terminal]->net
				&& sbptr->nSegType < 0 ) {
		Flag = 1 ;
	    }
	    sbptr = sbptr->nnextgrd ;
	}
}
if( !Flag ) {
	sbptr = bptr ;
}
} else {
sbptr = bptr1->nnextgrd ;
while( sbptr->netptr->xpos == bx1 ) {
	sbptr = sbptr->nnextgrd ;
}
}
if( bptr2->nSegType <= 0 ) {
Flag = 0 ;
fptr = bptr2 ;
while( fptr->nnextgrd != GRDNULL
		&& fptr->nnextgrd->netptr->xpos == bx2 ) {
	if( net == tearray[fptr->nnextgrd->netptr->terminal]->net
			    && fptr->nnextgrd->nSegType > 0 ) {
	    Flag = 1 ;
	    ebptr = bptr2->nprevgrd ;
	    while( ebptr->netptr->xpos == bx2 ) {
		ebptr = ebptr->nprevgrd ;
	    }
	    break ;
	} else {
	    fptr = fptr->nnextgrd ;
	}
}
if( !Flag ) {
	ebptr = bptr2->nprevgrd ;
	while( ebptr->netptr->xpos == bx2 ) {
	    if( net == tearray[ebptr->netptr->terminal]->net
				&& ebptr->nSegType > 0 ) {
		Flag = 1 ;
	    }
	    ebptr = ebptr->nprevgrd ;
	}
}
if( !Flag ) {
	ebptr = fptr ;
}
} else {
ebptr = bptr2->nprevgrd ;
while( ebptr->netptr->xpos == bx2 ) {
	ebptr = ebptr->nprevgrd ;
}
}
aoutside = 0 ;
ax1 = saptr->netptr->xpos ;
ax2 = eaptr->netptr->xpos ;
denptr = DboxHead[ achannel ][ aMaxVal ]->nnext ;
for( ; denptr != DENSENULL ; denptr = denptr->nnext ) {
x = denptr->grdptr->netptr->xpos ;
if( !( ax1 <= x && ax2 >= x ) ) {
	aoutside = 1 ;
	break ;
}
}
if( aoutside == 0 ) {
penalty-- ;
}
binside  = 0 ;
bx1 = sbptr->netptr->xpos ;
bx2 = ebptr->netptr->xpos ;
denptr = DboxHead[ bchannel ][ bMaxVal ]->nnext ;
for( ; denptr != DENSENULL ; denptr = denptr->nnext ) {
x = denptr->grdptr->netptr->xpos ;
if( bx1 <= x && bx2 >= x ) {
	binside = 1 ;
	break ;
}
}
if( binside == 1 ) {
penalty++ ;
}
eaptr = eaptr->nnextgrd ;
ebptr = ebptr->nnextgrd ;
if( penalty == 0 ) {
if( binside == 1 && aoutside == 0 ) {
	
	check = bMaxVal - aMaxVal + 2 ;
} else {
	maxaa = 0 ;
	maxbb = 0 ;
	for( ptr = saptr ; ptr != eaptr ; ptr = ptr->nnextgrd ) {
	    if( ptr->ntracks > maxaa ) {
		maxaa = ptr->ntracks ;
	    }
	}
	for( ptr = sbptr ; ptr != ebptr ; ptr = ptr->nnextgrd ) {
	    if( ptr->ntracks > maxbb ) {
		maxbb = ptr->ntracks ;
	    }
	}
	maxaa = aMaxVal  - maxaa + 1 ;
	maxbb = bMaxVal  - maxbb - 1 ;
	check = maxaa - maxbb ;
}
} else {
check = penalty ;
}
if( check <= 0 ) {
if( asegptr->pin1 <= maxterm ) {
	aptr1->nSegType -= RIGHT ;
}
if( asegptr->pin2 <= maxterm ) {
	aptr2->nSegType -= LEFT  ;
}
if( bsegptr->pin1 <= maxterm ) {
	bptr1->nSegType += RIGHT ;
}
if( bsegptr->pin2 <= maxterm ) {
	bptr2->nSegType += LEFT  ;
}
for( ptr = saptr ; ptr != eaptr ; ptr = ptr->nnextgrd ) {
	denptr = ptr->dptr ;
	if( denptr->nnext != DENSENULL ) {
	    denptr->nnext->nback = denptr->nback ;
	}
	denptr->nback->nnext = denptr->nnext ;
	track = --(ptr->ntracks) ;
	headptr = DboxHead[ achannel ][ track ]->nnext ;
	if( headptr != DENSENULL ) {
	    DboxHead[ achannel ][ track ]->nnext = denptr ;
	    denptr->nnext  = headptr ;
	    headptr->nback = denptr  ;
	    denptr->nback  = DboxHead[ achannel ][ track ] ;
	} else {
	    DboxHead[ achannel ][ track ]->nnext = denptr ;
	    denptr->nnext = DENSENULL ;
	    denptr->nback = DboxHead[ achannel ][ track ];
	}
}
if( aoutside == 0 ) {
	--(nmaxTrack[achannel]) ;
}
for( ptr = sbptr ; ptr != ebptr ; ptr = ptr->nnextgrd ) {
	denptr = ptr->dptr ;
	if( denptr->nnext != DENSENULL ) {
	    denptr->nnext->nback = denptr->nback ;
	}
	denptr->nback->nnext = denptr->nnext ;
	track = ++(ptr->ntracks) ;
	headptr = DboxHead[ bchannel ][ track ]->nnext ;
	if( headptr != DENSENULL ) {
	    DboxHead[ bchannel ][ track ]->nnext = denptr ;
	    denptr->nnext  = headptr ;
	    headptr->nback = denptr  ;
	    denptr->nback  = DboxHead[ bchannel ][ track ] ;
	} else {
	    DboxHead[ bchannel ][ track ]->nnext = denptr ;
	    denptr->nnext = DENSENULL ;
	    denptr->nback = DboxHead[ bchannel ][ track ];
	}
}
if( binside == 1 ) {
	nmaxTrack[bchannel]++ ;
}
if( aNetSeg[segment].nflag == 0 ) {
	if( current == 1 ) {
	    aNetSeg[segment].current = 0 ;
	} else {
	    aNetSeg[segment].current = 1 ;
	}
} else {
	if( current == 1 ) {
	    aNetSeg[segment].ncurrent = 0 ;
	} else {
	    aNetSeg[segment].ncurrent = 1 ;
	}
}
tracks += penalty ;
return (1) ;
} else {
return (0) ;
}
}
/* 当前文件是D:\Read\qsorte.c*/


#define		THRESH		4	
#define		MTHRESH		6	
int	qsz;			
int	thresh;			
int	mthresh;		
qsorte(base, n, size)
	char	*base;
	int	n;
	int	size;
{
	register char c, *i, *j, *lo, *hi;
	char *min, *max;
	if (n <= 1)
		return;
	qsz = size;
	thresh = qsz * THRESH;
	mthresh = qsz * MTHRESH;
	max = base + n * qsz;
	if (n >= THRESH) {
		qste(base, max);
		hi = base + thresh;
	} else {
		hi = max;
	}
	for (j = lo = base; (lo += qsz) < hi; )
		if (comparee(j, lo) > 0)
			j = lo;
	if (j != base) {
		
		for (i = base, hi = base + qsz; i < hi; ) {
			c = *j;
			*j++ = *i;
			*i++ = c;
		}
	}
	for (min = base; (hi = min += qsz) < max; ) {
		while (comparee(hi -= qsz, min) > 0)
			;
		if ((hi += qsz) != min) {
			for (lo = min + qsz; --lo >= min; ) {
				c = *lo;
				for (i = j = lo; (j -= qsz) >= hi; i = j)
					*i = *j;
				*i = c;
			}
		}
	}
}
qste(base, max)
	char *base, *max;
{
	register char c, *i, *j, *jj;
	register int ii;
	char *mid, *tmp;
	int lo, hi;
	lo = max - base;		
	do	{
		mid = i = base + qsz * ((lo / qsz) >> 1);
		if (lo >= mthresh) {
			j = (comparee((jj = base), i) > 0 ? jj : i);
			if (comparee(j, (tmp = max - qsz)) > 0) {
				
				j = (j == jj ? i : jj);
				if (comparee(j, tmp) < 0)
					j = tmp;
			}
			if (j != i) {
				ii = qsz;
				do	{
					c = *i;
					*i++ = *j;
					*j++ = c;
				} while (--ii);
			}
		}
		
		for (i = base, j = max - qsz; ; ) {
			while (i < mid && comparee(i, mid) <= 0)
				i += qsz;
			while (j > mid) {
				if (comparee(mid, j) <= 0) {
					j -= qsz;
					continue;
				}
				tmp = i + qsz;	
				if (i == mid) {
					
					mid = jj = j;
				} else {
					
					jj = j;
					j -= qsz;
				}
				goto swap;
			}
			if (i == mid) {
				break;
			} else {
				
				jj = mid;
				tmp = mid = i;	
				j -= qsz;
			}
		swap:
			ii = qsz;
			do	{
				c = *i;
				*i++ = *jj;
				*jj++ = c;
			} while (--ii);
			i = tmp;
		}
		i = (j = mid) + qsz;
		if ((lo = j - base) <= (hi = max - i)) {
			if (lo >= thresh)
				qste(base, j);
			base = i;
			lo = hi;
		} else {
			if (hi >= thresh)
				qste(i, max);
			max = j;
		}
	} while (lo >= thresh);
}
comparee( a , b )
edgeBptr a , b ;
{
return( a->cost - b->cost ) ;
}
/* 当前文件是D:\Read\qsortg.c*/

#define		THRESH		4	
#define		MTHRESH		6	



qsortg(base, n, size)
	char	*base;
	int	n;
	int	size;
{
	register char c, *i, *j, *lo, *hi;
	char *min, *max;
	if (n <= 1)
		return;
	qsz = size;
	thresh = qsz * THRESH;
	mthresh = qsz * MTHRESH;
	max = base + n * qsz;
	if (n >= THRESH) {
		qstg(base, max);
		hi = base + thresh;
	} else {
		hi = max;
	}
	for (j = lo = base; (lo += qsz) < hi; )
		if (compareg(j, lo) > 0)
			j = lo;
	if (j != base) {
		
		for (i = base, hi = base + qsz; i < hi; ) {
			c = *j;
			*j++ = *i;
			*i++ = c;
		}
	}
	for (min = base; (hi = min += qsz) < max; ) {
		while (compareg(hi -= qsz, min) > 0)
			;
		if ((hi += qsz) != min) {
			for (lo = min + qsz; --lo >= min; ) {
				c = *lo;
				for (i = j = lo; (j -= qsz) >= hi; i = j)
					*i = *j;
				*i = c;
			}
		}
	}
}
qstg(base, max)
	char *base, *max;
{
	register char c, *i, *j, *jj;
	register int ii;
	char *mid, *tmp;
	int lo, hi;
	lo = max - base;		
	do	{
		mid = i = base + qsz * ((lo / qsz) >> 1);
		if (lo >= mthresh) {
			j = (compareg((jj = base), i) > 0 ? jj : i);
			if (compareg(j, (tmp = max - qsz)) > 0) {
				
				j = (j == jj ? i : jj);
				if (compareg(j, tmp) < 0)
					j = tmp;
			}
			if (j != i) {
				ii = qsz;
				do	{
					c = *i;
					*i++ = *j;
					*j++ = c;
				} while (--ii);
			}
		}
		
		for (i = base, j = max - qsz; ; ) {
			while (i < mid && compareg(i, mid) <= 0)
				i += qsz;
			while (j > mid) {
				if (compareg(mid, j) <= 0) {
					j -= qsz;
					continue;
				}
				tmp = i + qsz;	
				if (i == mid) {
					
					mid = jj = j;
				} else {
					
					jj = j;
					j -= qsz;
				}
				goto swap;
			}
			if (i == mid) {
				break;
			} else {
				
				jj = mid;
				tmp = mid = i;	
				j -= qsz;
			}
		swap:
			ii = qsz;
			do	{
				c = *i;
				*i++ = *jj;
				*jj++ = c;
			} while (--ii);
			i = tmp;
		}
		i = (j = mid) + qsz;
		if ((lo = j - base) <= (hi = max - i)) {
			if (lo >= thresh)
				qstg(base, j);
			base = i;
			lo = hi;
		} else {
			if (hi >= thresh)
				qstg(i, max);
			max = j;
		}
	} while (lo >= thresh);
}
compareg( a , b )
csGroup *a , *b ;
{
return( a->aveX - b->aveX ) ;
}
/* 当前文件是D:\Read\qsortgdx.c*/


#define		THRESH		4	
#define		MTHRESH		6	



qsortgdx(base, n, size)
	char	*base;
	int	n;
	int	size;
{
	register char c, *i, *j, *lo, *hi;
	char *min, *max;
	if (n <= 1)
		return;
	qsz = size;
	thresh = qsz * THRESH;
	mthresh = qsz * MTHRESH;
	max = base + n * qsz;
	if (n >= THRESH) {
		qstgdx(base, max);
		hi = base + thresh;
	} else {
		hi = max;
	}
	for (j = lo = base; (lo += qsz) < hi; )
		if (comparegdx(j, lo) > 0)
			j = lo;
	if (j != base) {
		
		for (i = base, hi = base + qsz; i < hi; ) {
			c = *j;
			*j++ = *i;
			*i++ = c;
		}
	}
	for (min = base; (hi = min += qsz) < max; ) {
		while (comparegdx(hi -= qsz, min) > 0)
			;
		if ((hi += qsz) != min) {
			for (lo = min + qsz; --lo >= min; ) {
				c = *lo;
				for (i = j = lo; (j -= qsz) >= hi; i = j)
					*i = *j;
				*i = c;
			}
		}
	}
}
qstgdx(base, max)
	char *base, *max;
{
	register char c, *i, *j, *jj;
	register int ii;
	char *mid, *tmp;
	int lo, hi;
	lo = max - base;		
	do	{
		mid = i = base + qsz * ((lo / qsz) >> 1);
		if (lo >= mthresh) {
			j = (comparegdx((jj = base), i) > 0 ? jj : i);
			if (comparegdx(j, (tmp = max - qsz)) > 0) {
				
				j = (j == jj ? i : jj);
				if (comparegdx(j, tmp) < 0)
					j = tmp;
			}
			if (j != i) {
				ii = qsz;
				do	{
					c = *i;
					*i++ = *j;
					*j++ = c;
				} while (--ii);
			}
		}
		
		for (i = base, j = max - qsz; ; ) {
			while (i < mid && comparegdx(i, mid) <= 0)
				i += qsz;
			while (j > mid) {
				if (comparegdx(mid, j) <= 0) {
					j -= qsz;
					continue;
				}
				tmp = i + qsz;	
				if (i == mid) {
					
					mid = jj = j;
				} else {
					
					jj = j;
					j -= qsz;
				}
				goto swap;
			}
			if (i == mid) {
				break;
			} else {
				
				jj = mid;
				tmp = mid = i;	
				j -= qsz;
			}
		swap:
			ii = qsz;
			do	{
				c = *i;
				*i++ = *jj;
				*jj++ = c;
			} while (--ii);
			i = tmp;
		}
		i = (j = mid) + qsz;
		if ((lo = j - base) <= (hi = max - i)) {
			if (lo >= thresh)
				qstgdx(base, j);
			base = i;
			lo = hi;
		} else {
			if (hi >= thresh)
				qstgdx(i, max);
			max = j;
		}
	} while (lo >= thresh);
}
comparegdx( a , b )
CHANGRDPTR *a , *b ;
{
return( (*a)->netptr->xpos - (*b)->netptr->xpos ) ;
}
/* 当前文件是D:\Read\qsortx.c*/

#define		THRESH		4	
#define		MTHRESH		6	



qsortx(base, n, size)
char	*base;
int	n;
int	size;
{
register char c, *i, *j, *lo, *hi;
char *min, *max;
if (n <= 1)
	return;
qsz = size;
thresh = qsz * THRESH;
mthresh = qsz * MTHRESH;
max = base + n * qsz;
if (n >= THRESH) {
	qst(base, max);
	hi = base + thresh;
} else {
	hi = max;
}
for (j = lo = base; (lo += qsz) < hi; )
	if (comparex(j, lo) > 0)
	    j = lo;
if (j != base) {
	
	for (i = base, hi = base + qsz; i < hi; ) {
	    c = *j;
	    *j++ = *i;
	    *i++ = c;
	}
}
for (min = base; (hi = min += qsz) < max; ) {
	while (comparex(hi -= qsz, min) > 0)
		;
	if ((hi += qsz) != min) {
	    for (lo = min + qsz; --lo >= min; ) {
		c = *lo;
		for (i = j = lo; (j -= qsz) >= hi; i = j)
		    *i = *j;
		*i = c;
	    }
	}
}
}
qst(base, max)
char *base, *max;
{
register char c, *i, *j, *jj;
register int ii;
char *mid, *tmp;
int lo, hi;
lo = max - base;		
do	{
	mid = i = base + qsz * ((lo / qsz) >> 1);
	if (lo >= mthresh) {
	    j = (comparex((jj = base), i) > 0 ? jj : i);
	    if (comparex(j, (tmp = max - qsz)) > 0) {
		
		j = (j == jj ? i : jj);
		if (comparex(j, tmp) < 0)
		    j = tmp;
	    }
	    if (j != i) {
		ii = qsz;
		do {
		    c = *i;
		    *i++ = *j;
		    *j++ = c;
		} while (--ii);
	    }
	}
	
	for (i = base, j = max - qsz; ; ) {
	    while (i < mid && comparex(i, mid) <= 0)
		i += qsz;
	    while (j > mid) {
		if (comparex(mid, j) <= 0) {
		    j -= qsz;
		    continue;
		}
		tmp = i + qsz;	
		if (i == mid) {
		
		    mid = jj = j;
		} else {
		
		    jj = j;
		    j -= qsz;
		}
		goto swap;
	    }
	    if (i == mid) {
		break;
	    } else {
		
		jj = mid;
		tmp = mid = i;	
		j -= qsz;
	    }
swap:
	    ii = qsz;
	    do	{
		c = *i;
		*i++ = *jj;
		*jj++ = c;
	    } while (--ii);
	    i = tmp;
	}
	
	i = (j = mid) + qsz;
	if ((lo = j - base) <= (hi = max - i)) {
	    if (lo >= thresh)
		qst(base, j);
	    base = i;
	    lo = hi;
	} else {
	    if (hi >= thresh)
		qst(i, max);
	    max = j;
	}
} while (lo >= thresh);
}
/* 当前文件是D:\Read\rand.c*/

#ifndef VMS
#ifndef lint
static char SccsId[] = "@(#) rand.c (Yale) version 3.1 3/21/90" ;
#endif
#endif
static int randVarS ;
#define A_RAND 16807L
#define M_RAND 2147483647L
#define Q_RAND 127773L
#define R_RAND 2836L
#define ABS(value)   ( (value)>=0 ? (value) : -(value) )
#define M_RANDD 4.65661287524579690000000000000000e-10
int Yacm_random()
{
register int k_rand ;
k_rand = randVarS / Q_RAND ;
randVarS = A_RAND * (randVarS - k_rand * Q_RAND) - (k_rand * R_RAND) ;
if( randVarS < 0 ){
	randVarS += M_RAND ;
}
return( randVarS ) ;
}
Yset_random_seed( seed )
int seed ;
{
seed = ABS(seed) ;
if( seed == 0 ){
	seed++ ;
}
randVarS = seed ;
}

/* 当前文件是D:\Read\readcell.c*/



int totallen ;
int maxterm ;
int move()  ;
int rect()  ;
int point() ;





readcell( fp )
FILE *fp ;
{
int cell , orient  , layer ;
int block , left , right , bottom , top ;
int xpos , ypos , from ;
int terms , pinctr , netx ;
int tot , totx , toty ;
char input[1024] ;
char netname[1024] ;
double space ;
CBOXPTR ptr ;
TIBOXPTR tile , tptr ;
TEBOXPTR term , tmptr ;
NBOXPTR netptr , saveptr ;
parser( fp ) ;
carray = (CBOXPTR *) safe_malloc( ( 1 + numcells +
			       numterms) * sizeof( CBOXPTR ) ) ;
for( cell = 1 ; cell <= numcells + numterms ; cell++ ) {
ptr = carray[ cell ] = (CBOXPTR) safe_malloc( sizeof(CBOX) ) ;
ptr->cxcenter    = 0 ;
ptr->cycenter    = 0 ;
ptr->cheight     = 0 ;
ptr->clength     = 0 ;
ptr->cblock      = 0 ;
ptr->cclass      = 0 ;
ptr->corient     = 0 ;
ptr->orflag      = 1 ;
ptr->numterms    = 0 ;
ptr->padside     = 0 ;
ptr->tileptr     = TILENULL ;
}
implicit_feed_count = 0 ;
cell  = 0 ;
terms = 0 ;
pinctr = 0 ;
while( fscanf( fp , " %s " , input ) == 1 ) {
if( strcmp( input , "cell") == 0 ) {
	
	cell++ ;
	ptr = carray[ cell ] ;
	ptr->corient  = 0       ;
	fscanf( fp , " %s " , input ) ;
	fscanf( fp , " %s " , input ) ;
	ptr->cname = (char *) safe_malloc( (strlen( input ) + 1 ) *
					    sizeof( char ) ) ;
	sprintf( ptr->cname , "%s" , input ) ;
} else if( strcmp( input , "nomirror") == 0 ) {
	ptr->orflag = 0 ;
} else if( strcmp( input , "initially") == 0 ) {
	fscanf( fp , " %s " , input ) ;
	if( strcmp( input , "fixed" ) == 0 ) {
	    ptr->cclass = -1 ;
	    ptr->orflag = 0 ;
	} else if( strcmp( input , "nonfixed" ) == 0 ) {
	    ptr->cclass = 0 ;
	}
	fscanf( fp , " %d " , &from ) ;
	fscanf( fp , " %s " , input ) ;
	fscanf( fp , " %s " , input ) ;
	if( strcmp( input , "left" ) == 0 ) {
	    ptr->cxcenter = from ;
	    ptr->cycenter = 1 ;
	} else if( strcmp( input , "right" ) == 0 ) {
	    ptr->cxcenter = -from ;
	    ptr->cycenter = -1 ;
	}
	fscanf( fp , " %s " , input ) ;
	fscanf( fp , " %s " , input ) ;
	fscanf( fp , " %d " , &block ) ;
	ptr->cblock = block ;
} else if( strcmp( input , "left") == 0 ) {
	tile = ptr->tileptr = (TIBOXPTR) safe_malloc( sizeof(TIBOX) ) ;
	tile->termsptr = TERMNULL ;
	fscanf( fp , " %d " , &left ) ;
	tile->left = left ;
} else if( strcmp( input , "right") == 0 ) {
	fscanf( fp , " %d " , &right ) ;
	tile->right = right ;
} else if( strcmp( input , "bottom") == 0 ) {
	fscanf( fp , " %d " , &bottom ) ;
	tile->bottom = bottom ;
} else if( strcmp( input , "top") == 0 ) {
	fscanf( fp , " %d " , &top ) ;
	tile->top = top ;
	ptr->cheight = top - bottom ;
	ptr->clength = right - left ;
} else if( strcmp( input , "pin") == 0 ) {
	fscanf( fp , " %s " , input ) ;
	fscanf( fp , " %s " , input ) ;
	fscanf( fp , " %s " , input ) ;
	fscanf( fp , " %s " , input ) ;
	strcpy( netname , input ) ;
	if( strcmp( input , "TW_PASS_THRU" ) != 0 ) {
	    netx = hashfind( input ) ;
	    if( netarray[netx]->name == NULL ) {
		netarray[netx]->name = (char *) safe_malloc(
			     (strlen( input ) + 1) * sizeof( char ) ) ;
		sprintf( netarray[netx]->name , "%s" , input ) ;
	    }
	    tot = 1 ;
	    ptr->numterms++ ;
	    if( ptr->numterms == 1 ) {
		term = ptr->tileptr->termsptr = (TEBOXPTR)
					safe_malloc( sizeof( TEBOX ) ) ;
	    } else {
		term = term->nextterm = (TEBOXPTR) safe_malloc(
						   sizeof( TEBOX ) ) ;
	    }
	    term->nextterm = TERMNULL ;
	    term->cellterm = ++pinctr ;
	    term->ue = 0 ;
	    saveptr = netarray[ netx ]->netptr ;
	    netptr = netarray[ netx ]->netptr = (NBOXPTR)
				     safe_malloc( sizeof( NBOX ) ) ;
	    netptr->nterm    = saveptr ;
	    netptr->terminal = pinctr ;
	    netptr->net      = netx ;
	    netptr->xpos     = 0    ;
	    netptr->ypos     = 0    ;
	    netptr->newx     = 0    ;
	    netptr->newy     = 0    ;
	    netptr->flag     = 0    ;
	    netptr->cell     = cell + terms ;
	    if( pin_layers_given != 0 ) {
		fscanf( fp , " %s " , input ) ;
		fscanf( fp , " %d " , &layer ) ;
	    }
	    fscanf( fp , " %d %d " , &xpos , &ypos ) ;
	    totx = xpos ;
	    toty = ypos ;
	    term->txpos[0] = xpos ;
	    term->typos[0] = ypos ;
	} else {
	    implicit_feed_count++ ;
	    if( pin_layers_given != 0 ) {
		fscanf( fp , " %s " , input ) ;
		fscanf( fp , " %d " , &layer ) ;
	    }
	    fscanf( fp , " %d %d " , &xpos , &ypos ) ;
	}
} else if( strcmp( input , "equiv") == 0 ) {
	fscanf( fp , " %s " , input ) ;
	fscanf( fp , " %s " , input ) ;
	if( pin_layers_given != 0 ) {
	    fscanf( fp , " %s " , input ) ;
	    fscanf( fp , " %d " , &layer ) ;
	}
	fscanf( fp , " %d %d " , &xpos , &ypos ) ;
	if( strcmp( netname , "TW_PASS_THRU" ) != 0 ) {
	    tot++ ;
	    totx += xpos ;
	    toty += ypos ;
	    term->txpos[0] = totx / tot ;
	    if( terms == 0 ) {
		term->typos[0] = 0 ;
	    } else {
		term->typos[0] = toty / tot ;
	    }
	}
} else if( strcmp( input , "unequiv") == 0 ) {
	fscanf( fp , " %s " , input ) ;
	fscanf( fp , " %s " , input ) ;
	if( pin_layers_given != 0 ) {
	    fscanf( fp , " %s " , input ) ;
	    fscanf( fp , " %d " , &layer ) ;
	}
	fscanf( fp , " %d %d " , &xpos , &ypos ) ;
	tot++ ;
	totx += xpos ;
	term->txpos[0] = totx / tot ;
	term->typos[0] = 0 ;
	term->ue = 1 ;
} else if( strcmp( input , "pad") == 0 ) {
	terms++ ;
	fscanf( fp , " %s " , input ) ;
	fscanf( fp , " %s " , input ) ;
	ptr = carray[ numcells + terms ] ;
	ptr->cname = (char *) safe_malloc( (strlen( input ) + 1 ) *
					    sizeof( char ) ) ;
	sprintf( ptr->cname , "%s" , input ) ;
	ptr->cclass = 0 ;
	ptr->orflag = 0 ;
} else if( strcmp( input , "orient") == 0 ) {
	fscanf( fp , " %d " , &orient ) ;
	ptr->corient = orient ;
} else if( strcmp( input , "padside") == 0 ) {
	fscanf( fp , " %s " , input ) ;
	if( strcmp( input , "L" ) == 0 ) {
	    ptr->padside = 1 ;
	} else if( strcmp( input , "T" ) == 0 ) {
	    ptr->padside = 2 ;
	} else if( strcmp( input , "R" ) == 0 ) {
	    ptr->padside = 3 ;
	} else if( strcmp( input , "B" ) == 0 ) {
	    ptr->padside = 4 ;
	} else if( strcmp( input , "MUL" ) == 0 ) {
	    ptr->padside = 5 ;
	} else if( strcmp( input , "MUR" ) == 0 ) {
	    ptr->padside = 6 ;
	} else if( strcmp( input , "MLL" ) == 0 ) {
	    ptr->padside = 7 ;
	} else if( strcmp( input , "MLR" ) == 0 ) {
	    ptr->padside = 8 ;
	} else if( strcmp( input , "ML" ) == 0 ) {
	    ptr->padside = 9 ;
	} else if( strcmp( input , "MR" ) == 0 ) {
	    ptr->padside = 10 ;
	} else if( strcmp( input , "MB" ) == 0 ) {
	    printf("macro at position MB is no longer supported -- sorry!\n");
	    exit( TW_FAIL ) ;
	    ptr->padside = 11 ;
	} else if( strcmp( input , "MT" ) == 0 ) {
	    printf("macro at position MT is no longer supported -- sorry!\n");
	    exit( TW_FAIL ) ;
	    ptr->padside = 12 ;
	} else if( strcmp( input , "MM" ) == 0 ) {
	    printf("macro at position MM is no longer supported -- sorry!\n");
	    exit( TW_FAIL ) ;
	    ptr->padside = 13 ;
	} else if( strcmp( input , "MTT" ) == 0 ) {
	    ptr->padside = 14 ;
	} else if( strcmp( input , "MBB" ) == 0 ) {
	    ptr->padside = 15 ;
	} else {
	    fprintf(fpo,"padside not specified properly for ");
	    fprintf(fpo,"pad: %s\n", ptr->cname ) ;
	    exit(TW_FAIL);
	}
} else if( strcmp( input , "sidespace") == 0 ) {
	fscanf( fp , " %lf " , &space ) ;
	if( ptr->padside == 1 ) {
	    fixLRBT[0] = 1 ;	
	    padspace[ terms ] = space ;
	} else if( ptr->padside == 3 ) {
	    fixLRBT[1] = 1 ;	
	    padspace[ terms ] = space ;
	} else if( ptr->padside == 4 ) {
	    fixLRBT[2] = 1 ;	
	    padspace[ terms ] = space ;
	} else if( ptr->padside == 2 ) {
	    fixLRBT[3] = 1 ;	
	    padspace[ terms ] = space ;
	} else {
	    macspace[ ptr->padside ] = space ;
	}
}
}
for( cell = 1 ; cell <= numcells ; cell++ ) {
if( carray[cell]->orflag == 1 ) {
	if( maxCellO == 0 ) {
	    maxCellO = 2 ;
	} else if( maxCellO == 1 ) {
	    maxCellO = 3 ;
	}
	break ;
}
}
for( cell = 1 ; cell <= numcells ; cell++ ) {
ptr = carray[ cell ] ;
tptr = ptr->tileptr ;
for( tmptr = tptr->termsptr ; tmptr != TERMNULL ;
				    tmptr = tmptr->nextterm ) {
	if( ( ptr->clength %2 != 0 ) ) {
	    tmptr->txpos[1] = -tmptr->txpos[0] + 1 ;
	} else {
	    tmptr->txpos[1] = -tmptr->txpos[0] ;
	}
	if( ( ptr->cheight %2 != 0 ) ) {
	    tmptr->typos[1] = -tmptr->typos[0] + 1 ;
	} else {
	    tmptr->typos[1] = -tmptr->typos[0] ;
	}
}
}
for( cell = numcells + 1 ; cell <= numcells + numterms ; cell++ ) {
ptr = carray[ cell ] ;
tptr = ptr->tileptr ;
orient = ptr->corient ;
move( orient ) ;
rect( &tptr->left , &tptr->bottom , &tptr->right ,
						&tptr->top ) ;
if( (ptr->cheight % 2 != 0 && (orient == 4 || orient == 6))||
	(ptr->clength % 2 != 0 && (orient == 2 || orient == 3))){
	tptr->left++ ;
	tptr->right++ ;
}
if( (ptr->cheight % 2 != 0 && (orient == 1 || orient == 3))||
	(ptr->clength % 2 != 0 && (orient == 4 || orient == 7))){
	tptr->bottom++ ;
	tptr->top++ ;
}
for( tmptr = tptr->termsptr ; tmptr != TERMNULL ;
				    tmptr = tmptr->nextterm ) {
	tmptr->txpos[1] = tmptr->txpos[0] ;
	tmptr->typos[1] = tmptr->typos[0] ;
	point( &tmptr->txpos[1] , &tmptr->typos[1] ) ;
	if( (ptr->cheight % 2 != 0 && (orient == 4 || orient == 6))||
	    (ptr->clength % 2 != 0 && (orient == 2 || orient == 3))){
	    tmptr->txpos[1]++ ;
	}
	if( (ptr->cheight % 2 != 0 && (orient == 1 || orient == 3))||
	    (ptr->clength % 2 != 0 && (orient == 4 || orient == 7))){
	    tmptr->typos[1]++ ;
	}
}
}
configure() ;
carray = (CBOXPTR *) safe_realloc( carray, (1 + numcells + numterms) *
						sizeof( CBOXPTR ) ) ;
for( block = 1 ; block <= numblock ; block++ ) {
totallen += barray[ block ]->blength ;
}
fprintf( fpo, "total cell length: %d\n", celllen ) ;
fprintf( fpo, "total block length: %d\n", totallen ) ;
return ;
}
/* 当前文件是D:\Read\readnets.c*/


readnets( fp )
FILE *fp ;
{
int net , test , status ;
double Hweight , Vweight , beta , total_weight ;
NBOXPTR netptr ;
char input[1024] ;
fscanf( fp , " %s ", input ) ;
if( strcmp( input , "allnets") != 0 ) {
fprintf( fpo, "The keyword allnets was ");
fprintf( fpo, "not properly entered in the .net file\n");
exit(TW_FAIL);
}
fscanf( fp , " %s ", input ) ;
if( strcmp( input , "HVweights") != 0 ) {
fprintf( fpo, "The keyword HVweights was ");
fprintf( fpo, "not properly entered in the .net file\n");
exit(TW_FAIL);
}
test = fscanf( fp , "%lf %lf" , &Hweight , &Vweight ) ;
if( test != 2 ) {
fprintf( fpo, "The net weights for allnets were ");
fprintf( fpo, "not properly entered in the .net file\n");
exit(TW_FAIL);
}
if( Hweight <= 0.0 || Vweight <= 0.0 ) {
fprintf( fpo, "A global net weight was ");
fprintf( fpo, "zero or negative in the \n");
fprintf(fpo,".net file\n");
fprintf(fpo,"This is not allowed; choose .0001 instead\n");
exit(TW_FAIL);
}
if( Vweight < 1.0 ) {
Vweight = 1.0 ;
}
for( net = 1 ; net <= numnets ; net++ ) {
netarray[net]->Hweight = Hweight ;
netarray[net]->Vweight = Vweight ;
}
while( fscanf( fp , " %s " , input ) == 1 ) {
if( strcmp( input , "net") == 0 ) {
	fscanf( fp , " %s ", input ) ;
	status = hashfind( input ) ;
	if( status == 0 ) {
	    fprintf( fpo, "The net named: %s  in the .net file\n",
						    input );
	    fprintf( fpo, "was not encountered while reading\n");
	    fprintf( fpo, "the .cel file --- FATAL error\n");
	    exit(TW_FAIL);
	}
} else if( strcmp( input , "HVweights") == 0 ) {
	test = fscanf( fp , "%lf %lf" , &Hweight , &Vweight ) ;
	if( test != 2 ) {
	    fprintf( fpo, "The critical net weights were ");
	    fprintf( fpo, "not properly entered\n");
	    fprintf(fpo,"in the .net file after net: %s\n",
							input);
	    exit(TW_FAIL);
	}
	if( Hweight <= 0.0 || Vweight <= 0.0 ) {
	    fprintf( fpo, "A critical net weight was ");
	    fprintf( fpo, "zero or negative in the \n");
	    fprintf(fpo,".net file after net: %s\n", input);
	    fprintf(fpo,"This is not allowed; choose .0001 instead\n");
	    exit(TW_FAIL);
	}
	netarray[status]->Hweight = Hweight ;
	netarray[status]->Vweight = Vweight ;
} else if( strcmp( input , "nofeeds" ) == 0 ) {
	netarray[status]->feedflag = 1 ;
} else if( strcmp( input , "ignore" ) == 0 ) {
	netarray[status]->ignore = 1 ;
} else {
	fprintf( fpo, "unexpected keyword in the .net file\n");
	exit(TW_FAIL);
}
}
delHtab() ;
if( ! no_net_normalize ) {
total_weight = 0 ;
for( net = 1 ; net <= numnets ; net++ ) {
	total_weight += netarray[net]->Hweight + netarray[net]->Vweight ;
}
beta = 2.0 * (double) numnets / total_weight ;
for( net = 1 ; net <= numnets ; net++ ) {
	netarray[net]->Hweight *= beta ;
	netarray[net]->Vweight *= beta ;
}
}
for( net = 1 ; net <= numnets ; net++ ) {
for( netptr = netarray[ net ]->netptr ; netptr != NETNULL ;
				    netptr = netptr->nterm ) {
	tearray[ netptr->terminal ] = netptr ;
	tearray[ netptr->terminal ]->net = net ;
}
}
return ;
}
/* 当前文件是D:\Read\readpar.c*/

readParFile()
{
FILE *fp ;
char filename[64] , input[64] ;
int test ;
double f ;
sprintf( filename , "%s.par" , cktName ) ;
fp = twopen( filename , "r", ABORT ) ;
route2act = -1;
routeGrid = -1;
gridCell = -1;
while( fscanf( fp , " %s " , input ) == 1 ) {
if( strcmp( input , "implicit.feed.thru.range") == 0 ) {
	test = fscanf( fp , " %lf " , &imprange ) ;
	if( test != 1 ) {
	    fprintf( fpo,"The value of implicit.feed.thru.range");
	    fprintf( fpo," was not properly");
	    fprintf( fpo,"entered in the .par file\n");
	    exit(TW_FAIL);
	}
} else if( strcmp( input , "fast") == 0 ) {
	test = fscanf( fp, " %d ", &tw_fast ) ;
	if( test != 1 ){
	  fprintf( fpo, "The value of fast was not ") ;
	  fprintf( fpo, "properly entered in the .par file\n" ) ;
	  exit(TW_FAIL) ;
	}
} else if( strcmp( input , "slow") == 0 ) {
	test = fscanf( fp, " %d ", &tw_slow ) ;
	if( test != 1 ){
	  fprintf( fpo, "The value of fast was not ") ;
	  fprintf( fpo, "properly entered in the .par file\n" ) ;
	  exit(TW_FAIL) ;
	}
} else if( strcmp( input , "pin_layers_given") == 0 ) {
	pin_layers_given = 1 ;
} else if( strcmp( input , "gate_array_special") == 0 ) {
	gate_array_special = TRUE ;
} else if( strcmp( input , "connection_machine") == 0 ) {
	connection_machine = 1 ;
} else if( strcmp( input , "no_feeds_side_nets") == 0 ) {
	no_feeds_side_nets = 0 ;
} else if( strcmp( input , "no_net_normalize") == 0 ) {
	no_net_normalize = 1 ;
} else if( strcmp( input , "estimate_feeds" ) == 0 ) {
	estimate_feeds = 1 ;
} else if( strcmp( input , "cost_only" ) == 0 ) {
	costonly = 1 ;
} else if(strcmp(input,"do.global.route") == 0 ){
	doglobal = 1 ;
} else if(strcmp(input,"do.global.route.cell.swaps") == 0){
	cswaps = 1 ;
	stopdeg = 0.3 ;
} else if(strcmp(input,"full") == 0 ) {
	if( cswaps ) {
	    stopdeg = 0.5 ;
	}
} else if( strcmp( input , "feedThruWidth") == 0 ) {
	test = fscanf( fp , " %d " , &fdWidth ) ;
	if( test != 1 ) {
	    fprintf( fpo,"The value of feedThruWidth was not ");
	    fprintf( fpo,"properly entered in the .par file\n");
	    exit(TW_FAIL);
	}
} else if( strcmp( input , "layer") == 0 ) {
	test = fscanf( fp , " %d " , &feedLayer ) ;
	if( test != 1 ) {
	    fprintf( fpo,"The value of layer was not ");
	    fprintf( fpo,"properly entered in the .par file\n");
	    exit(TW_FAIL);
	}
	if( feedLayer != 1 && feedLayer != 2 && feedLayer != 3 ) {
	    fprintf( fpo,"The value of layer must currently be one of ");
	    fprintf( fpo,"1, 2, or 3 \n");
	    exit(TW_FAIL);
	} else {
	    feedLayer-- ;
	}
} else if( strcmp( input , "addFeeds") == 0 ) {
	addFeeds = 1 ;
} else if( strcmp( input , "indent") == 0 ) {
	test = fscanf( fp , " %lf " , &indent ) ;
	indent = 1.0 ;
	
} else if( strcmp( input , "random.seed") == 0 ) {
	test = fscanf( fp , " %d " , &randomSeed ) ;
	if( test != 1 ) {
	    fprintf( fpo,"The value of random.seed was not ");
	    fprintf( fpo,"properly entered in the .par file\n");
	    exit(TW_FAIL);
	}
} else if( strcmp( input , "random.seed2") == 0 ) {
	test = fscanf( fp , " %d " , &randomSeed2 ) ;
	if( test != 1 ) {
	    fprintf( fpo,"The value of random.seed2 was not ");
	    fprintf( fpo,"properly entered in the .par file\n");
	    exit(TW_FAIL);
	}
} else if( strcmp( input , "rowSep") == 0 ) {
	test = fscanf( fp , " %lf " , &rowSep ) ;
	if( test != 1 ) {
	    fprintf( fpo,"The value of rowSep was not properly");
	    fprintf( fpo,"entered in the .par file\n");
	    exit(TW_FAIL);
	}
} else if( strcmp( input , "restart") == 0 ) {
	resume_run = YES ;
} else if( strcmp( input , "track.spacing") == 0 ) {
	uneven_cell_height = 1 ;
	test = fscanf( fp , " %d " , &track_spacing ) ;
	if( test != 1 ) {
	    fprintf( fpo,"The value of trackSpacing was not properly");
	    fprintf( fpo,"entered in the .par file\n");
	    exit(TW_FAIL);
	}
} else if( strcmp( input , "one.pin.feedthru") == 0 ) {
	one_pin_feedthru = 1 ;
} else if( strcmp( input , "route2act") == 0 ) {
	test = fscanf( fp , " %d " , &route2act ) ;
	if( test != 1 ) {
	    fprintf( fpo,"The value of route2act was not properly");
	    fprintf( fpo,"entered in the .par file\n");
	    exit(TW_FAIL);
	}
} else if( strcmp( input , "gridCell") == 0 ) {
	test = fscanf( fp , " %d " , &gridCell ) ;
	if( test != 1 ) {
	    fprintf( fpo,"The value of gridCell was not properly");
	    fprintf( fpo,"entered in the .par file\n");
	    exit(TW_FAIL);
	}
} else if( strcmp( input , "routeGrid") == 0 ) {
	test = fscanf( fp , " %d " , &routeGrid ) ;
	if( test != 1 ) {
	    fprintf( fpo,"The value of routeGrid was not properly");
	    fprintf( fpo,"entered in the .par file\n");
	    exit(TW_FAIL);
	}
} else {
	fprintf( fpo, "Unparsable keyword>>> %s\n", input );
	fprintf( fpo, "was found in the .par file\n");
	exit(TW_FAIL);
}
}
twclose( fp ) ;
sprintf( filename , "%s.rs2" , cktName ) ;
if( (fp = twopen ( filename , "r", NOABORT)) && resume_run == YES ) {
fscanf( fp , "%lf" , &f ) ;
fscanf( fp , "%d" , &stage ) ;
fscanf( fp , "%d" , &stage ) ;
fscanf( fp , "%d" , &stage ) ;
fprintf(fpo,"\n\nNOTE: Restart file .rs2 will be used \n\n");
twclose(fp);
restart = 1 ;
} else {
stage = 1 ;
fprintf(fpo,"\n\nNOTE: Restart file .rs2 not used\n\n");
restart = 0 ;
}
if( cswaps != 0 ) {
if( doglobal == 0 ) {
	fprintf(fpo,"user specified cell swaps ");
	fprintf(fpo,"without requesting do.global.route\n");
	exit(TW_FAIL);
}
}
if( doglobal ) {
fprintf(fpo,"TimberWolf will perform a global route step\n");
}
if( cswaps ) {
fprintf(fpo,"TimberWolf will perform final cell placements\n");
fprintf(fpo," by swapping cells based on minimization of\n");
fprintf(fpo," the total number of routing tracks required\n");
}
if( addFeeds && imprange < 0.0 ) {
fprintf( fpo, "implicit.feed.thru.range was ");
fprintf( fpo, "not entered in the .par file\n");
exit(TW_FAIL);
}
if( rowSep < 0.0 ) {
fprintf( fpo, "rowSep was not entered in the .par file\n");
exit(TW_FAIL);
} else {
fprintf( fpo, "rowSep: %f\n" , rowSep ) ;
}
if( addFeeds == 1  &&  fdWidth == -1 ) {
fprintf(fpo,"feedThruWidth was not entered in the .par file\n");
exit(TW_FAIL);
} else {
fprintf( fpo, "feedThruWidth: %d\n" , fdWidth ) ;
}
#ifdef TI
if( track_spacing < 0.0 ) {
fprintf( fpo, "track.spacing was not entered in the .par file\n");
exit(TW_FAIL);
} else {
fprintf( fpo, "trackSpacing: %d\n" , track_spacing ) ;
}
if( route2act < 0.0 ) {
fprintf( fpo, "route2act was not entered in the .par file\n");
exit(TW_FAIL);
} else {
fprintf( fpo, "route2act: %d\n" , route2act ) ;
}
if( gridCell < 0.0 ) {
fprintf( fpo, "gridCell was not entered in the .par file\n" ) ;
fprintf( fpo, "If the user wishes cell dimensions to be output\
					in same scale as input,\n") ;
fprintf( fpo, "gridCell should be set to the ICE characteristic\
							number.\n") ;
exit(TW_FAIL);
} else {
fprintf( fpo, "gridCell: %d\n" , gridCell ) ;
fprintf( fpo, "Cells values will be output by multiplying\
				by gridCell: %d\n" , gridCell ) ;
}
#endif
return ;
}
/* 当前文件是D:\Read\readseg.c*/




readseg( fp )
FILE *fp ;
{
int segment , net , net1 , net2 , key_flag ;
int channel , pin1 , pin2 ;
int ltop , rtop , lbot , rbot ;
int Tleft , Tright , Bleft , Bright ;
char input[16] ;
SEGBOXPTR tmp_ptr ;
segment   = 0 ;
numSwSegs = 0 ;
numSegs   = 0 ;
while( fscanf( fp , " %s " , input ) == 1 ) {
if( strcmp( input , "net") == 0 ) {
	fscanf( fp , " %d " , &net ) ;
} else if( strcmp( input , "segment") == 0 ) {
	numSegs++ ;
	fscanf( fp , " %s " , input ) ;
	if( strcmp( input , "channel") == 0 ) {
	    fscanf( fp , "%d" , &channel ) ;
	    fscanf( fp , " %s " , input )  ;
	    fscanf( fp , "%d" , &pin1 )    ;
	    fscanf( fp , " %s " , input )  ;
	    fscanf( fp , "%d" , &pin2 )    ;
	    fscanf( fp , "%d" , &ltop )    ;
	    fscanf( fp , "%d" , &rtop )    ;
	} else {
	    numSwSegs++ ;
	    fscanf( fp , "%d" , &key_flag ) ;
	    fscanf( fp , " %s " , input )  ;
	    fscanf( fp , " %s " , input )  ;
	    fscanf( fp , "%d" , &channel ) ;
	    fscanf( fp , " %s " , input )  ;
	    fscanf( fp , "%d" , &pin1 )    ;
	    fscanf( fp , " %s " , input )  ;
	    fscanf( fp , "%d" , &pin2 )    ;
	    fscanf( fp , "%d" , &ltop )    ;
	    fscanf( fp , "%d" , &rtop )    ;
	    fscanf( fp , " %s " , input )  ;
	    fscanf( fp , " %s " , input )  ;
	    fscanf( fp , "%d" , &channel ) ;
	    fscanf( fp , " %s " , input )  ;
	    fscanf( fp , "%d" , &pin1 )    ;
	    fscanf( fp , " %s " , input )  ;
	    fscanf( fp , "%d" , &pin2 )    ;
	    fscanf( fp , "%d" , &lbot )    ;
	    fscanf( fp , "%d" , &rbot )    ;
	}
}
}
fprintf(fpo,"\nTotal Number of Net Segments: %d\n", numSegs ) ;
fprintf(fpo,"Number of Switchable Net Segments: %d\n\n", numSwSegs ) ;
fprintf(fpo,"Number of channels: %d\n\n", numChans ) ;
rewind( fp ) ;
aNetSeg = ( SWITCHBOXPTR ) safe_malloc((numSegs + 1)
					* sizeof( SWITCHBOX ) );
fixnetseg = ( int * ) safe_malloc((numSegs + 1) * sizeof( int ) );
anet = (int *) safe_malloc( (numnets + 2) * sizeof( int ) ) ;
for( net = 0 ; net <= numnets + 1 ; net++ ) {
anet[net] = 0 ;
}
netchgs = (int *) safe_malloc( (numnets + 1) * sizeof( int ) ) ;
while( fscanf( fp , " %s " , input ) == 1 ) {
if( strcmp( input , "net") == 0 ) {
	fscanf( fp , " %d " , &net ) ;
	anet[net] = segment + 1 ;
} else if( strcmp( input , "segment") == 0 ) {
	segment++ ;
	fscanf( fp , " %s " , input ) ;
	if( strcmp( input , "channel") == 0 ) {
	    fscanf( fp , "%d" , &channel ) ;
	    fscanf( fp , " %s " , input )  ;
	    fscanf( fp , "%d" , &pin1 )    ;
	    fscanf( fp , " %s " , input )  ;
	    fscanf( fp , "%d" , &pin2 )    ;
	    fscanf( fp , "%d" , &ltop )    ;
	    fscanf( fp , "%d" , &rtop )    ;
	    aNetSeg[segment].top =
		    (SEGBOXPTR) safe_malloc( sizeof(SEGBOX) );
	    aNetSeg[segment].bot =
		    (SEGBOXPTR) safe_malloc( sizeof(SEGBOX) );
	    aNetSeg[segment].ntop =
		    (SEGBOXPTR) safe_malloc( sizeof(SEGBOX));
	    aNetSeg[segment].nbot =
		    (SEGBOXPTR) safe_malloc( sizeof(SEGBOX));
	    aNetSeg[segment].net = net ;
	    aNetSeg[segment].nflag = 0 ;
	    aNetSeg[segment].current = 0 ;
	    aNetSeg[segment].swYorN = 0 ;
	    aNetSeg[segment].key = 0 ;
	    aNetSeg[segment].nkey = 0 ;
	    aNetSeg[segment].top->channel = channel ;
	    aNetSeg[segment].top->pin1    = pin1    ;
	    aNetSeg[segment].top->pin2    = pin2    ;
	    aNetSeg[segment].top->pin1ptr = Tgrid[ pin1 ]->up ;
	    if( tearray[ pin1 ]->pinloc == 0 &&
		tearray[ pin1 ]->row == channel ) {
		aNetSeg[segment].top->pin1ptr = Tgrid[ pin1 ]->down;
	    }
	    aNetSeg[segment].top->pin2ptr = Tgrid[ pin2 ]->up ;
	    if( tearray[ pin2 ]->pinloc == 0 &&
		tearray[ pin2 ]->row == channel ) {
		aNetSeg[segment].top->pin2ptr = Tgrid[ pin2 ]->down;
	    }
	} else {
	    fscanf( fp , "%d" , &key_flag ) ;
	    fscanf( fp , " %s " , input ) ;
	    fscanf( fp , " %s " , input ) ;
	    fscanf( fp , "%d" , &channel ) ;
	    fscanf( fp , " %s " , input ) ;
	    fscanf( fp , "%d" , &pin1 ) ;
	    fscanf( fp , " %s " , input ) ;
	    fscanf( fp , "%d" , &pin2 ) ;
	    fscanf( fp , "%d" , &ltop )    ;
	    fscanf( fp , "%d" , &rtop )    ;
	    aNetSeg[segment].top =
		    (SEGBOXPTR) safe_malloc( sizeof(SEGBOX) );
	    aNetSeg[segment].bot =
		    (SEGBOXPTR) safe_malloc( sizeof(SEGBOX) );
	    aNetSeg[segment].ntop =
		    (SEGBOXPTR) safe_malloc( sizeof(SEGBOX));
	    aNetSeg[segment].nbot =
		    (SEGBOXPTR) safe_malloc( sizeof(SEGBOX));
	    aNetSeg[segment].net = net ;
	    aNetSeg[segment].nflag = 0 ;
	    aNetSeg[segment].current = 0 ;
	    aNetSeg[segment].swYorN = 1 ;
	    if( key_flag == 0 ||
			    ((anet[net] - 1 + key_flag) == segment) ) {
		aNetSeg[segment].key = 0 ;
	    } else {
		aNetSeg[segment].key = key_flag + anet[net] - 1 ;
	    }
	    aNetSeg[segment].nkey = 0 ;
	    aNetSeg[segment].top->channel = channel ;
	    aNetSeg[segment].top->pin1    = pin1    ;
	    aNetSeg[segment].top->pin2    = pin2    ;
	    if( ltop == -1 ) {
		pin1 = pin2 ;
	    } else if( ltop > 0 ) {
		pin1 = ltop ;
		pin2 = rtop ;
	    }
	    Tleft = tearray[ pin1 ]->xpos ;
	    aNetSeg[segment].top->pin1ptr = Tgrid[ pin1 ]->up ;
	    if( tearray[ pin1 ]->pinloc == 0 &&
		tearray[ pin1 ]->row == channel ) {
		aNetSeg[segment].top->pin1ptr = Tgrid[ pin1 ]->down;
	    }
	    Tright = tearray[ pin2 ]->xpos ;
	    aNetSeg[segment].top->pin2ptr = Tgrid[ pin2 ]->up ;
	    if( tearray[ pin2 ]->pinloc == 0 &&
		tearray[ pin2 ]->row == channel ) {
		aNetSeg[segment].top->pin2ptr = Tgrid[ pin2 ]->down;
	    }
	    fscanf( fp , " %s " , input ) ;
	    fscanf( fp , " %s " , input ) ;
	    fscanf( fp , "%d" , &channel ) ;
	    fscanf( fp , " %s " , input ) ;
	    fscanf( fp , "%d" , &pin1 ) ;
	    fscanf( fp , " %s " , input ) ;
	    fscanf( fp , "%d" , &pin2 ) ;
	    fscanf( fp , "%d" , &lbot )    ;
	    fscanf( fp , "%d" , &rbot )    ;
	    aNetSeg[segment].bot->channel = channel ;
	    aNetSeg[segment].bot->pin1    = pin1    ;
	    aNetSeg[segment].bot->pin2    = pin2    ;
	    if( lbot == -1 ) {
		pin1 = pin2 ;
	    } else if( lbot > 0 ) {
		pin1 = lbot ;
		pin2 = rbot ;
	    }
	    Bleft = tearray[ pin1 ]->xpos ;
	    aNetSeg[segment].bot->pin1ptr = Tgrid[ pin1 ]->up ;
	    if( tearray[ pin1 ]->pinloc == 0 &&
		tearray[ pin1 ]->row == channel ) {
		aNetSeg[segment].bot->pin1ptr = Tgrid[ pin1 ]->down;
	    }
	    Bright = tearray[ pin2 ]->xpos ;
	    aNetSeg[segment].bot->pin2ptr = Tgrid[ pin2 ]->up ;
	    if( tearray[ pin2 ]->pinloc == 0 &&
		tearray[ pin2 ]->row == channel ) {
		aNetSeg[segment].bot->pin2ptr = Tgrid[ pin2 ]->down;
	    }
	    if( Bleft == Bright || Tleft == Tright ) {
		aNetSeg[segment].swYorN = 0 ;
		if( Bleft == Bright && Tleft != Tright ) {
		    tmp_ptr = aNetSeg[segment].top ;
		    aNetSeg[segment].top =
				aNetSeg[segment].bot ;
		    aNetSeg[segment].bot = tmp_ptr ;
		}
	    }
	}
}
}
net2 = net + 1 ;
anet[net2] = segment + 1 ;
for( net = 1 ; net < net2 ; net++ ) {
if( anet[net] == 0 ) {
	for( net1 = net + 1 ; net1 <= net2 ; net1++ ) {
	    if( anet[net1] != 0 ) {
		anet[net] = anet[net1] ;
		break ;
	    }
	}
}
}
return ;
}
/* 当前文件是D:\Read\savewolf.c*/

int stage ;






int last_level ;
savewolf( level )
int level ;
{
FILE *fp ;
int xcenter , ycenter ;
int cell , block , orient , seg ;
char filename[64] ;
char file1[1024], file2[1024];
CBOXPTR cellptr ;
double cpu_time();
double current_time;
static double last_time = 0.0;
#ifndef VMS
current_time = cpu_time();
if ((current_time - last_time) < 600.0 &&
		level == last_level && level <= 1 ) {
return;
}
last_time = current_time;
last_level = level;
#endif
#ifdef VMS
if( level == 1 ) {
sprintf( filename , "%s.sav" , cktName ) ;
fp = twopen( filename , "w", ABORT ) ;
sprintf( filename , "%s.sav;-2" , cktName ) ;
delete( filename ) ;
} else {
sprintf( filename , "%s.sv2" , cktName ) ;
fp = twopen( filename , "w", ABORT ) ;
sprintf( filename , "%s.sv2;-2" , cktName ) ;
delete( filename ) ;
}
#else
sprintf( filename , "%s.tmp" , cktName ) ;
fp = twopen( filename , "w", ABORT ) ;
#endif
fprintf( fp, "%f\n", T ) ;
fprintf( fp, "%d\n", iteration ) ;
fprintf( fp, "%d\n", ffeeds ) ;
fprintf( fp, "%d\n", level ) ;
fprintf( fp, "%f\n", binpenCon ) ;
fprintf( fp, "%f\n", roLenCon ) ;
fprintf( fp, "%f\n", cost_scale_factor ) ;
fprintf( fp, "%d\n", estimate_feeds ) ;
if( level == 3 ) {
fprintf(fp,"%d\n", numSegs ) ;
for( seg = 1 ; seg <= numSegs ; seg++ ) {
	fprintf(fp,"%d\n", aNetSeg[seg].current ) ;
}
}
for( cell = 1 ; cell <= numcells + numterms ; cell++ ) {
cellptr = carray[ cell ] ;
orient  = cellptr->corient   ;
block   = cellptr->cblock    ;
xcenter = cellptr->cxcenter  ;
ycenter = cellptr->cycenter  ;
fprintf( fp , "%d %d %d %d %d\n", cell , block ,
			       orient , xcenter , ycenter ) ;
}
twclose( fp ) ;
#ifndef VMS
sprintf(file1, "%s.tmp", cktName);
if( level == 1 ) {
sprintf(file2, "%s.sav", cktName);
} else {
sprintf(file2, "%s.sv2", cktName);
}
unlink(file2);
rename(file1, file2);
#endif
return ;
}
TW_oldin( fp )
FILE *fp ;
{
int cell , orient , numfds ;
int block , xcenter , ycenter , dummy ;
CBOXPTR ptr ;
TEBOXPTR term ;
NBOXPTR termptr ;
fscanf( fp , "%lf" , &T1 ) ;
fscanf( fp , "%d" , &iteration ) ;
fscanf( fp , "%d" , &numfds ) ;
fscanf( fp , "%d" , &dummy ) ;
fscanf( fp , "%lf" , &binpenCon ) ;
fscanf( fp , "%lf" , &roLenCon ) ;
fscanf( fp , "%lf" , &cost_scale_factor ) ;
fscanf( fp , "%d" , &estimate_feeds ) ;
while( fscanf( fp , " %d %d %d %d %d ", &cell , &block , &orient ,
				    &xcenter , &ycenter ) == 5 ) {
ptr = carray[ cell ] ;
ptr->cblock   = block   ;
ptr->corient  = orient  ;
ptr->cxcenter = xcenter ;
ptr->cycenter = ycenter ;
if( cell <= numcells ) {
	for( term = ptr->tileptr->termsptr ;
			term != TERMNULL ; term = term->nextterm ) {
	    termptr = tearray[term->cellterm] ;
	    termptr->xpos = term->txpos[ orient/2 ] + xcenter ;
	    termptr->ypos = term->typos[ orient%2 ] + ycenter ;
	}
} else {
	for( term = ptr->tileptr->termsptr ;
			term != TERMNULL ; term = term->nextterm ) {
	    termptr = tearray[term->cellterm] ;
	    termptr->xpos = term->txpos[ 1 ] + xcenter ;
	    termptr->ypos = term->typos[ 1 ] + ycenter ;
	}
}
}
return ;
}
fixfdpos( fp )
FILE *fp ;
{
int cell , orient , numfds , dummy , number , seg , current ;
int block , xcenter , ycenter , junk ;
double d_dummy ;
CBOXPTR ptr ;
fscanf( fp , "%lf" , &T1 ) ;
fscanf( fp , "%d" , &iteration ) ;
fscanf( fp , "%d" , &numfds ) ;
fscanf( fp , "%d" , &dummy ) ;
fscanf( fp , "%lf" , &d_dummy ) ;
fscanf( fp , "%lf" , &d_dummy ) ;
fscanf( fp , "%lf" , &d_dummy ) ;
fscanf( fp , "%d" , &junk ) ;
if( dummy == 3 ) {
fscanf(fp,"%d", &number ) ;
fixarray = (int *) safe_malloc( (number + 1) * sizeof(int) ) ;
for( seg = 1 ; seg <= number ; seg++ ) {
	fscanf(fp,"%d", &current ) ;
	fixarray[seg] = current ;
}
}
while( fscanf( fp , " %d %d %d %d %d ", &cell , &block , &orient ,
				    &xcenter , &ycenter ) == 5 ) {
ptr = carray[ cell ] ;
ptr->cxcenter = xcenter ;
ptr->cycenter = ycenter ;
ptr->corient  = orient ;
}
return ;
}
/* 当前文件是D:\Read\sortpin.c*/

sortpin()
{
int j , n , cell ;
CBOXPTR ptr ;
TIBOXPTR tile ;
TEBOXPTR term , *xpptr ;
NBOXPTR termptr ;
xpptr = (TEBOXPTR *) safe_malloc( 300 * sizeof( TEBOXPTR ) ) ;
for( cell = 1 ; cell <= numcells + numterms ; cell++ ) {
ptr = carray[ cell ] ;
if( ( tile = ptr->tileptr ) == TILENULL ) {
	continue ;
}
n = 0 ;
for( term = tile->termsptr ; term != TERMNULL ;
				  term = term->nextterm ) {
	termptr = tearray[ term->cellterm ] ;
	term->net = termptr->net ;
	term->termptr = termptr ;
	xpptr[ ++n ] = term ;
}
shellsort( xpptr , n ) ;
xpptr[ n + 1 ] = TERMNULL ;
ptr->tileptr->termsptr = xpptr[ 1 ] ;
for( j = 1 ; j <= n ; j++ ) {
	xpptr[j]->nextterm = xpptr[j+1] ;
}
}
safe_free( xpptr ) ;
}
shellsort( term , n )
TEBOXPTR *term ;
int n ;
{
TEBOXPTR ptr ;
int incr , i , j ;
for( incr = n / 2 ; incr > 0 ; incr /= 2 ) {
for( i = incr + 1 ; i <= n ; i++ ) {
	for( j = i - incr ; j > 0 &&
	(term[j]->net > term[j+incr]->net) ; j -= incr ) {
	    ptr = term[j] ;
	    term[j] = term[j+incr] ;
	    term[j+incr] = ptr ;
	}
}
}
}
/* 当前文件是D:\Read\stats.c*/

#ifndef VMS
#endif
print_stats(fp)
FILE *fp;
{
fprintf(fp, "Usage statistics not available\n");
}
double cpu_time()
{
return 0.0;
}
/* 当前文件是D:\Read\uc0.c*/

uc0( a , newaor )
int a , newaor ;
{
CBOXPTR acellptr ;
TEBOXPTR antrmptr ;
int cost , truth ;
acellptr = carray[ a ]    ;
antrmptr = acellptr->tileptr->termsptr ;
term_newpos( antrmptr, acellptr->cxcenter, acellptr->cycenter, newaor );
cost = funccost ;
new_dbox( antrmptr , &cost ) ;
truth =  acceptt( funccost - cost ) ;
if( truth == 1 ) {
dbox_pos( antrmptr ) ;
acellptr->corient = newaor ;
funccost = cost ;
}
return ;
}
/* 当前文件是D:\Read\ucg0.c*/

ucg0( a , newaor )
int a , newaor ;
{
CBOXPTR acellptr ;
NBOXPTR tmptr ;
TIBOXPTR antilptr ;
TEBOXPTR termptr , antrmptr ;
SEGBOXPTR segptr ;
DENSITYPTR denptr ;
CHANGRDPTR gdptr , endgrd ;
int x , y , oldtracks , track ;
int axcenter , aycenter ;
int i , b , e , seg , chan , net ;
int UpperLeft , UpperRight , LowerLeft , LowerRight ;
int ULpin , URpin , LLpin , LRpin ;
int leftx , ritex , topchan , botchan ;
acellptr = carray[ a ]    ;
axcenter = acellptr->cxcenter ;
aycenter = acellptr->cycenter ;
antilptr = acellptr->tileptr ;
antrmptr = antilptr->termsptr ;
UpperLeft  = LowerLeft  = gxstop ;
UpperRight = LowerRight = gxstart ;
ULpin = URpin = LLpin = LRpin = 0 ;
netchgs[0] = 0 ;
for( termptr = antrmptr ; termptr != TERMNULL ; termptr =
					    termptr->nextterm ) {
x = termptr->txpos[ newaor / 2 ] + axcenter ;
y = termptr->typos[ newaor % 2 ] + aycenter ;
tmptr = tearray[termptr->cellterm] ;
if( tmptr->pinloc == 1 ) {
	if( tmptr->newx < UpperLeft ) {
	    UpperLeft = tmptr->newx ;
	    ULpin = termptr->cellterm ;
	}
	if( tmptr->newx > UpperRight ) {
	    UpperRight = tmptr->newx ;
	    URpin = termptr->cellterm ;
	}
} else {
	if( tmptr->newx < LowerLeft ) {
	    LowerLeft = tmptr->newx ;
	    LLpin = termptr->cellterm ;
	}
	if( tmptr->newx > LowerRight ) {
	    LowerRight = tmptr->newx ;
	    LRpin = termptr->cellterm ;
	}
}
tmptr->xpos = x ;
tmptr->ypos = y ;
for( i = 1 ; i <= netchgs[0] ; i++ ) {
	if( tmptr->net == netchgs[i] ) {
	    break ;
	}
}
if( i > netchgs[0] ) {
	netchgs[ ++netchgs[0] ] = tmptr->net ;
}
}
if( netchgs[0] == 0 ) {
return(0) ;
}
leftx = axcenter + antilptr->left ;
ritex = axcenter + antilptr->right ;
if( ULpin != 0 ) {
ULgrdptr = Tgrid[ ULpin ]->up->prevgrd ;
while( ULgrdptr->netptr->newx >= leftx ) {
	ULgrdptr = ULgrdptr->prevgrd ;
}
URgrdptr = Tgrid[ URpin ]->up->nextgrd ;
while( URgrdptr->netptr->newx <= ritex ) {
	URgrdptr = URgrdptr->nextgrd ;
}
} else {
ULgrdptr = GRDNULL ;
}
if( LLpin != 0 ) {
LLgrdptr = Tgrid[ LLpin ]->down->prevgrd ;
while( LLgrdptr->netptr->newx >= leftx ) {
	LLgrdptr = LLgrdptr->prevgrd ;
}
LRgrdptr = Tgrid[ LRpin ]->down->nextgrd ;
while( LRgrdptr->netptr->newx <= ritex ) {
	LRgrdptr = LRgrdptr->nextgrd ;
}
} else {
LLgrdptr = GRDNULL ;
}
Left_bound = leftx - ( ritex - leftx ) ;
Rite_bound = ritex + ( ritex - leftx ) ;
if( uneven_cell_height ) {
sub_reset1( a ) ;
}
oldtracks = tracks ;
uglobe() ;
topchan = gtopChan + 1 ;
botchan = gbotChan - 1 ;
if( topchan > numChans ) {
topchan = numChans ;
}
if( botchan < 1 ) {
botchan = 1 ;
}
if( tracks < oldtracks ) {
for( i = 1 ; i <= netchgs[0] ; i++ ) {
	net = netchgs[i] ;
	b = anet[net] ;
	e = anet[net + 1] - 1 ;
	for( seg = b ; seg <= e ; seg++ ) {
	    aNetSeg[seg].current = aNetSeg[seg].ncurrent ;
	    aNetSeg[seg].swYorN  = aNetSeg[seg].nswYorN ;
	    aNetSeg[seg].key     = aNetSeg[seg].nkey ;
	    aNetSeg[seg].nflag   = 0 ;
	    segptr               = aNetSeg[seg].top ;
	    aNetSeg[seg].top     = aNetSeg[seg].ntop ;
	    aNetSeg[seg].ntop    = segptr ;
	    segptr               = aNetSeg[seg].bot ;
	    aNetSeg[seg].bot     = aNetSeg[seg].nbot ;
	    aNetSeg[seg].nbot    = segptr ;
	}
}
for( termptr = antrmptr ; termptr != TERMNULL ; termptr =
					    termptr->nextterm ) {
	tmptr = tearray[termptr->cellterm] ;
	tmptr->newx = tmptr->xpos ;
	tmptr->newy = tmptr->ypos ;
}
for( seg = 1 ; seg <= numSegs ; seg++ ) {
	fixnetseg[seg] = aNetSeg[seg].current ;
}
for( chan = botchan ; chan <= topchan ; chan++ ) {
	for( gdptr = Begin[chan] ; gdptr != GRDNULL ;
			    gdptr = gdptr->nnextgrd ) {
	    gdptr->tracks  = gdptr->ntracks ;
	    gdptr->SegType = gdptr->nSegType ;
	}
	for( track = 0 ; track <= max_tdensity+30 ; track++ ) {
	    for( denptr = DboxHead[ chan ][ track ] ;
		denptr != DENSENULL ; denptr = denptr->nnext ) {
		denptr->next = denptr->nnext ;
		denptr->back = denptr->nback ;
	    }
	}
	maxTrack[ chan ] = nmaxTrack[ chan ] ;
}
if( ULgrdptr != GRDNULL ) {
	endgrd = URgrdptr->nnextgrd ;
	for( gdptr = ULgrdptr ; gdptr != endgrd ;
			      gdptr = gdptr->nnextgrd ) {
	    gdptr->nextgrd = gdptr->nnextgrd ;
	    gdptr->prevgrd = gdptr->nprevgrd ;
	}
}
if( LLgrdptr != GRDNULL ) {
	endgrd = LRgrdptr->nnextgrd ;
	for( gdptr = LLgrdptr ; gdptr != endgrd ;
			      gdptr = gdptr->nnextgrd ) {
	    gdptr->nextgrd = gdptr->nnextgrd ;
	    gdptr->prevgrd = gdptr->nprevgrd ;
	}
}
acellptr->corient = newaor ;
return(1);
} else {
for( termptr = antrmptr ; termptr != TERMNULL ; termptr =
					    termptr->nextterm ) {
	tmptr = tearray[termptr->cellterm] ;
	tmptr->xpos = tmptr->newx ;
	tmptr->ypos = tmptr->newy ;
}
for( i = 1 ; i <= netchgs[0] ; i++ ) {
	net = netchgs[i] ;
	b = anet[net] ;
	e = anet[net + 1] - 1 ;
	for( seg = b ; seg <= e ; seg++ ) {
	    aNetSeg[seg].nflag  = 0 ;
	}
}
for( seg = 1 ; seg <= numSegs ; seg++ ) {
	aNetSeg[seg].current = fixnetseg[seg] ;
}
for( chan = botchan ; chan <= topchan ; chan++ ) {
	for( gdptr = Begin[chan] ; gdptr != GRDNULL ;
			       gdptr = gdptr->nextgrd ) {
	    gdptr->ntracks  = gdptr->tracks ;
	    gdptr->nSegType = gdptr->SegType ;
	}
	for( track = 0 ; track <= max_tdensity+30 ; track++ ) {
	    for( denptr = DboxHead[ chan ][ track ] ;
		denptr != DENSENULL ; denptr = denptr->next ) {
		denptr->nnext = denptr->next ;
		denptr->nback = denptr->back ;
	    }
	}
	nmaxTrack[ chan ] = maxTrack[ chan ] ;
}
if( ULgrdptr != GRDNULL ) {
	endgrd = URgrdptr->nextgrd ;
	for( gdptr = ULgrdptr ; gdptr != endgrd ;
			      gdptr = gdptr->nextgrd ) {
	    gdptr->nnextgrd = gdptr->nextgrd ;
	    gdptr->nprevgrd = gdptr->prevgrd ;
	}
}
if( LLgrdptr != GRDNULL ) {
	endgrd = LRgrdptr->nextgrd ;
	for( gdptr = LLgrdptr ; gdptr != endgrd ;
			      gdptr = gdptr->nextgrd ) {
	    gdptr->nnextgrd = gdptr->nextgrd ;
	    gdptr->nprevgrd = gdptr->prevgrd ;
	}
}
tracks = oldtracks ;
return(0);
}
}
sub_reset1( a )
int a ;
{
int row , track , pinloc , self_reset ;
NBOXPTR netptr ;
CHANGRDPTR grdptr ;
DENSITYPTR denptr , headptr ;
row = carray[a]->cblock ;
if( ULgrdptr != GRDNULL ) {
for( grdptr = ULgrdptr ; grdptr != URgrdptr ;
				grdptr = grdptr->nextgrd ) {
	netptr = grdptr->netptr ;
	pinloc = netptr->pinloc ;
	if( pinloc == 1 ) {
	    self_reset = carray[ netptr->cell ]->tileptr->top ;
	} else if( pinloc == -1 ) {
	    self_reset = -carray[ netptr->cell ]->tileptr->bottom ;
	} else {
	    self_reset = 0 ;
	}
	grdptr->ntracks -= ( self_reset + facing_cellheight(
		    netptr->terminal , netptr->row , pinloc ,
				    OLD ) ) / track_spacing ;
}
}
if( LLgrdptr != GRDNULL ) {
for( grdptr = LLgrdptr ; grdptr != LRgrdptr ;
				grdptr = grdptr->nextgrd ) {
	netptr = grdptr->netptr ;
	pinloc = netptr->pinloc ;
	if( pinloc == 1 ) {
	    self_reset = carray[ netptr->cell ]->tileptr->top ;
	} else if( pinloc == -1 ) {
	    self_reset = -carray[ netptr->cell ]->tileptr->bottom ;
	} else {
	    self_reset = 0 ;
	}
	grdptr->ntracks -= ( self_reset + facing_cellheight(
		    netptr->terminal , netptr->row , pinloc ,
				    OLD ) ) / track_spacing ;
}
}
}
/* 当前文件是D:\Read\ucgxp.c*/

static int na_i , nb_i , start_i , end_i ;
static int startcbin , endcbin , rowleft ;
static int leftx , ritex ;
static int old_axcenter , old_bxcenter ;
static CBOXPTR acellptr , bcellptr ;
ucgxp( a , b , anxcenter , bnxcenter )
int a , b , anxcenter , bnxcenter ;
{
CBOXPTR cellptr ;
NBOXPTR tmptr ;
TIBOXPTR atileptr , btileptr ;
TEBOXPTR termptr , atermptr , btermptr ;
SEGBOXPTR segptr ;
DENSITYPTR denptr ;
CHANGRDPTR gdptr , endgrd ;
int oldtracks , track , x , row  ;
int aorient , borient , bin , bin_rite_edge , crite ;
int i , bb , e , seg , chan , net ;
int UpperLeft , UpperRight , LowerLeft , LowerRight ;
int ULpin , URpin , LLpin , LRpin ;
int topchan , botchan ;
acellptr = carray[ a ]    ;
aorient  = acellptr->corient / 2 ;
atileptr = acellptr->tileptr ;
atermptr = atileptr->termsptr ;
bcellptr = carray[ b ]    ;
borient  = bcellptr->corient / 2 ;
btileptr = bcellptr->tileptr ;
btermptr = btileptr->termsptr ;
UpperLeft  = LowerLeft  = gxstop ;
UpperRight = LowerRight = gxstart ;
ULpin = URpin = LLpin = LRpin = 0 ;
netchgs[0] = 0 ;
for( termptr = atermptr ; termptr != TERMNULL ; termptr =
					termptr->nextterm ){
x = termptr->txpos[ aorient ] + anxcenter ;
tmptr = tearray[termptr->cellterm] ;
if( tmptr->pinloc == 1 ) {
	if( tmptr->newx < UpperLeft ) {
	    UpperLeft = tmptr->newx ;
	    ULpin = termptr->cellterm ;
	}
	if( tmptr->newx > UpperRight ) {
	    UpperRight = tmptr->newx ;
	    URpin = termptr->cellterm ;
	}
} else {
	
	if( tmptr->newx < LowerLeft ) {
	    LowerLeft = tmptr->newx ;
	    LLpin = termptr->cellterm ;
	}
	if( tmptr->newx > LowerRight ) {
	    LowerRight = tmptr->newx ;
	    LRpin = termptr->cellterm ;
	}
}
tmptr->xpos = x ;
for( i = 1 ; i <= netchgs[0] ; i++ ) {
	if( tmptr->net == netchgs[i] ) {
	    break ;
	}
}
if( i > netchgs[0] ) {
	netchgs[ ++netchgs[0] ] = tmptr->net ;
}
}
for( termptr = btermptr ; termptr != TERMNULL ; termptr =
				    termptr->nextterm ) {
x = termptr->txpos[ borient ] + bnxcenter ;
tmptr = tearray[termptr->cellterm] ;
if( tmptr->pinloc == 1 ) {
	if( tmptr->newx < UpperLeft ) {
	    UpperLeft = tmptr->newx ;
	    ULpin = termptr->cellterm ;
	}
	if( tmptr->newx > UpperRight ) {
	    UpperRight = tmptr->newx ;
	    URpin = termptr->cellterm ;
	}
} else {
	
	if( tmptr->newx < LowerLeft ) {
	    LowerLeft = tmptr->newx ;
	    LLpin = termptr->cellterm ;
	}
	if( tmptr->newx > LowerRight ) {
	    LowerRight = tmptr->newx ;
	    LRpin = termptr->cellterm ;
	}
}
tmptr->xpos = x ;
for( i = 1 ; i <= netchgs[0] ; i++ ) {
	if( tmptr->net == netchgs[i] ) {
	    break ;
	}
}
if( i > netchgs[0] ) {
	netchgs[ ++netchgs[0] ] = tmptr->net ;
}
}
if( netchgs[0] == 0 ) {
return(0) ;
}
if( anxcenter < bnxcenter ) {
leftx = anxcenter + atileptr->left ;
ritex = bnxcenter + btileptr->right ;
} else {
leftx = bnxcenter + btileptr->left ;
ritex = anxcenter + atileptr->right ;
}
if( ULpin != 0 ) {
ULgrdptr = Tgrid[ ULpin ]->up->prevgrd ;
while( ULgrdptr->netptr->newx >= leftx ) {
	ULgrdptr = ULgrdptr->prevgrd ;
}
URgrdptr = Tgrid[ URpin ]->up->nextgrd ;
while( URgrdptr->netptr->newx <= ritex ) {
	URgrdptr = URgrdptr->nextgrd ;
}
} else {
ULgrdptr = GRDNULL ;
}
if( LLpin != 0 ) {
LLgrdptr = Tgrid[ LLpin ]->down->prevgrd ;
while( LLgrdptr->netptr->newx >= leftx ) {
	LLgrdptr = LLgrdptr->prevgrd ;
}
LRgrdptr = Tgrid[ LRpin ]->down->nextgrd ;
while( LRgrdptr->netptr->newx <= ritex ) {
	LRgrdptr = LRgrdptr->nextgrd ;
}
} else {
LLgrdptr = GRDNULL ;
}
Left_bound = leftx - ( ritex - leftx ) ;
Rite_bound = ritex + ( ritex - leftx ) ;
if( uneven_cell_height ) {
sub_reset2( a , b , anxcenter , bnxcenter ) ;
}
oldtracks = tracks ;
uglobe() ;
topchan = gtopChan + 1 ;
botchan = gbotChan - 1 ;
if( topchan > numChans ) {
topchan = numChans ;
}
if( botchan < 1 ) {
botchan = 1 ;
}
if( tracks <= oldtracks ) {
if( !uneven_cell_height ) {
	acellptr->cxcenter = anxcenter ;
	bcellptr->cxcenter = bnxcenter ;
}
for( termptr = atermptr ; termptr != TERMNULL ; termptr =
					    termptr->nextterm ) {
	tmptr = tearray[termptr->cellterm] ;
	tmptr->newx = tmptr->xpos ;
}
for( termptr = btermptr ; termptr != TERMNULL ; termptr =
					    termptr->nextterm ) {
	tmptr = tearray[termptr->cellterm] ;
	tmptr->newx = tmptr->xpos ;
}
for( i = 1 ; i <= netchgs[0] ; i++ ) {
	net = netchgs[i] ;
	bb = anet[net] ;
	e = anet[net + 1] - 1 ;
	for( seg = bb ; seg <= e ; seg++ ) {
	    aNetSeg[seg].current = aNetSeg[seg].ncurrent ;
	    aNetSeg[seg].swYorN  = aNetSeg[seg].nswYorN ;
	    aNetSeg[seg].key     = aNetSeg[seg].nkey ;
	    aNetSeg[seg].nflag   = 0 ;
	    segptr               = aNetSeg[seg].top ;
	    aNetSeg[seg].top     = aNetSeg[seg].ntop ;
	    aNetSeg[seg].ntop    = segptr ;
	    segptr               = aNetSeg[seg].bot ;
	    aNetSeg[seg].bot     = aNetSeg[seg].nbot ;
	    aNetSeg[seg].nbot    = segptr ;
	}
}
for( seg = 1 ; seg <= numSegs ; seg++ ) {
	fixnetseg[seg] = aNetSeg[seg].current ;
}
for( chan = botchan ; chan <= topchan ; chan++ ) {
	for( gdptr = Begin[chan] ; gdptr != GRDNULL ;
			      gdptr = gdptr->nnextgrd ) {
	    gdptr->tracks  = gdptr->ntracks ;
	    gdptr->SegType = gdptr->nSegType ;
	}
	for( track = 0 ; track <= max_tdensity+30 ; track++ ) {
	    for( denptr = DboxHead[ chan ][ track ] ;
		denptr != DENSENULL ; denptr = denptr->nnext ) {
		denptr->next = denptr->nnext ;
		denptr->back = denptr->nback ;
	    }
	}
	maxTrack[ chan ] = nmaxTrack[ chan ] ;
}
if( ULgrdptr != GRDNULL ) {
	endgrd = URgrdptr->nnextgrd ;
	for( gdptr = ULgrdptr ; gdptr != endgrd ;
			      gdptr = gdptr->nnextgrd ) {
	    gdptr->nextgrd = gdptr->nnextgrd ;
	    gdptr->prevgrd = gdptr->nprevgrd ;
	}
}
if( LLgrdptr != GRDNULL ) {
	endgrd = LRgrdptr->nnextgrd ;
	for( gdptr = LLgrdptr ; gdptr != endgrd ;
			      gdptr = gdptr->nnextgrd ) {
	    gdptr->nextgrd = gdptr->nnextgrd ;
	    gdptr->prevgrd = gdptr->nprevgrd ;
	}
}
return( 1 ) ;
} else {
if( uneven_cell_height ) {
	acellptr->cxcenter = old_axcenter ;
	bcellptr->cxcenter = old_bxcenter ;
}
for( termptr = atermptr ; termptr != TERMNULL ; termptr =
					    termptr->nextterm ) {
	tmptr = tearray[termptr->cellterm] ;
	tmptr->xpos = tmptr->newx ;
}
for( termptr = btermptr ; termptr != TERMNULL ; termptr =
					    termptr->nextterm ) {
	tmptr = tearray[termptr->cellterm] ;
	tmptr->xpos = tmptr->newx ;
}
for( i = 1 ; i <= netchgs[0] ; i++ ) {
	net = netchgs[i] ;
	bb = anet[net] ;
	e = anet[net + 1] - 1 ;
	for( seg = bb ; seg <= e ; seg++ ) {
	    aNetSeg[seg].nflag  = 0 ;
	}
}
for( seg = 1 ; seg <= numSegs ; seg++ ) {
	aNetSeg[seg].current = fixnetseg[seg] ;
}
for( chan = botchan ; chan <= topchan ; chan++ ) {
	for( gdptr = Begin[chan] ; gdptr != GRDNULL ;
			       gdptr = gdptr->nextgrd ) {
	    gdptr->ntracks  = gdptr->tracks ;
	    gdptr->nSegType = gdptr->SegType ;
	}
	for( track = 0 ; track <= max_tdensity+30 ; track++ ) {
	    for( denptr = DboxHead[ chan ][ track ] ;
		denptr != DENSENULL ; denptr = denptr->next ) {
		denptr->nnext = denptr->next ;
		denptr->nback = denptr->back ;
	    }
	}
	nmaxTrack[ chan ] = maxTrack[ chan ] ;
}
if( ULgrdptr != GRDNULL ) {
	endgrd = URgrdptr->nextgrd ;
	for( gdptr = ULgrdptr ; gdptr != endgrd ;
			      gdptr = gdptr->nextgrd ) {
	    gdptr->nnextgrd = gdptr->nextgrd ;
	    gdptr->nprevgrd = gdptr->prevgrd ;
	}
}
if( LLgrdptr != GRDNULL ) {
	endgrd = LRgrdptr->nextgrd ;
	for( gdptr = LLgrdptr ; gdptr != endgrd ;
			      gdptr = gdptr->nextgrd ) {
	    gdptr->nnextgrd = gdptr->nextgrd ;
	    gdptr->nprevgrd = gdptr->prevgrd ;
	}
}
tracks = oldtracks ;
if( uneven_cell_height ) {
	row = carray[a]->cblock ;
	pairArray[row][nb_i] = a ;
	pairArray[row][na_i] = b ;
	bin = startcbin ;
	bin_rite_edge = rowleft + --bin * cedge_binwidth ;
	for( i = start_i ; i <= end_i ; i++ ) {
	    cellptr = carray[ pairArray[row][i] ] ;
	    crite = cellptr->cxcenter + cellptr->tileptr->right ;
	    while( bin_rite_edge < crite ) {
		cedgebin[ row ][ ++bin ] = i ;
		bin_rite_edge += cedge_binwidth ;
	    }
	}
}
return( 0 ) ;
}
}
sub_reset2( a , b , anxcenter , bnxcenter )
int a , b , anxcenter , bnxcenter ;
{
int row , bin , track , *Aray , i , cell ;
int bin_rite_edge , crite , pinloc , self_reset ;
NBOXPTR netptr ;
CBOXPTR cellptr ;
CHANGRDPTR grdptr ;
DENSITYPTR denptr , headptr ;
row = carray[a]->cblock ;
if( ULgrdptr != GRDNULL ) {
for( grdptr = ULgrdptr ; grdptr != URgrdptr ;
				grdptr = grdptr->nextgrd ) {
	netptr = grdptr->netptr ;
	pinloc = netptr->pinloc ;
	if( pinloc == 1 ) {
	    self_reset = carray[ netptr->cell ]->tileptr->top ;
	} else if( pinloc == -1 ) {
	    self_reset = -carray[ netptr->cell ]->tileptr->bottom ;
	} else {
	    self_reset = 0 ;
	}
	grdptr->ntracks -= ( self_reset + facing_cellheight(
		    netptr->terminal , netptr->row , pinloc ,
				    OLD ) ) / track_spacing ;
}
}
if( LLgrdptr != GRDNULL ) {
for( grdptr = LLgrdptr ; grdptr != LRgrdptr ;
				grdptr = grdptr->nextgrd ) {
	netptr = grdptr->netptr ;
	pinloc = netptr->pinloc ;
	if( pinloc == 1 ) {
	    self_reset = carray[ netptr->cell ]->tileptr->top ;
	} else if( pinloc == -1 ) {
	    self_reset = -carray[ netptr->cell ]->tileptr->bottom ;
	} else {
	    self_reset = 0 ;
	}
	grdptr->ntracks -= ( self_reset + facing_cellheight(
		    netptr->terminal , netptr->row , pinloc ,
				    OLD ) ) / track_spacing ;
}
}
old_axcenter = acellptr->cxcenter ;
old_bxcenter = bcellptr->cxcenter ;
acellptr->cxcenter = anxcenter ;
bcellptr->cxcenter = bnxcenter ;
Aray  = pairArray[row] ;
rowleft  = carray[Aray[1]]->cxcenter + carray[Aray[1]]->tileptr->left ;
startcbin = ( leftx - rowleft ) / cedge_binwidth + 1 ;
endcbin   = ( ritex - rowleft ) / cedge_binwidth + 1 ;
start_i = cedgebin[row][startcbin] ;
end_i = cedgebin[row][endcbin]   ;
bin = startcbin ;
i = start_i ;
for( cell = Aray[ i ] ; cell != a ; cell = Aray[ ++i ] ) ;
if( anxcenter < bnxcenter ) {
na_i = i - 1 ;
nb_i = i ;
} else {
na_i = i + 1 ;
nb_i = i ;
}
Aray[na_i] = a ;
Aray[nb_i] = b ;
bin_rite_edge = rowleft + --bin * cedge_binwidth ;
for( i = start_i ; i <= end_i ; i++ ) {
cellptr = carray[ Aray[i] ] ;
crite = cellptr->cxcenter + cellptr->tileptr->right ;
while( bin_rite_edge < crite ) {
	cedgebin[ row ][ ++bin ] = i ;
	bin_rite_edge += cedge_binwidth ;
}
}
}
/* 当前文件是D:\Read\uclosepns.c*/

#define DEBUG
#define YES 1
#define NO 0





uclosepns(net)
int net ;
{
int pin , pin1 , pin2 , minP1 , minP2 , minX , sepT , sepB , edge ;
int group1 , group2 , block1 , block2 , p1 , p2 ;
int Tleft , Tright , Bleft , Bright ;
int minTop  , minBottom , maxTpin , maxBpin , otherTpin ;
int otherBpin , maxTop , maxBottom , segIndex ;
int k_left , k_right , super_edge ;
int e1 , e2 , g1 , g2 , next_edge , next_g, save_count ;
int key_flag , key_count , fault_line ;
int channel , left , right ;
int ltop , rtop , lbot , rbot ;
csPinBox *pArray1 , *pArray2 , *pArray ;
SEGBOXPTR tmp_ptr ;
key_count = 0 ;
super_edge = 0 ;
segIndex = anet[net] - 1 ;
fault_line = anet[net + 1] ;
for( ; ; ) {
if( key_count > 0 ) {
	edge = key_queue[ key_count-- ] ;
	group1 = edgeArray[edge].group1 ;
	k_left  = groupArray[group1].aveX ;
	k_right = k_left ;
	key_flag = save_count ;
} else {
	while( ++super_edge <= numEdges ) {
	    if( edgeArray[super_edge].marked == NO ) {
		continue ;
	    }
	    if( edgeArray[super_edge].done == NO ) {
		break ;
	    }
	}
	if( super_edge > numEdges ) {
	    break ;
	}
	edge = super_edge ;
	key_flag = 0 ;
}
segIndex++ ;
#ifdef DEBUG
if( segIndex >= fault_line ) {
	printf("Serious fault detected in function: uclosepns():");
	printf("   Net:%d\n", net );
	fflush(stdout);
}
#endif
aNetSeg[segIndex].nflag = 1 ;
maxTop  = -1000000000 ;
maxBottom = -1000000000 ;
maxTpin = 0 ;
maxBpin = 0 ;
group1  = edgeArray[edge].group1 ;
pArray1 = groupArray[group1].pinArray ;
block1  = groupArray[group1].block ;
group2  = edgeArray[ edge ].group2 ;
pArray2 = groupArray[group2].pinArray ;
block2  = groupArray[group2].block ;
if( edgeArray[edge].poison == NO && key_flag == NO) {
	save_count = segIndex ;
	edgeArray[edge].done = YES ;
	key_flag = save_count ;
	
	e1 = edge ;
	g1 = edgeArray[e1].group1 ;
	for( ; ; ) {
	    if( groupArray[g1].poison == YES ) {
		break ;
	    }
	    if( groupArray[g1].edge1 == e1 ) {
		next_edge = groupArray[g1].edge2 ;
	    } else {
		next_edge = groupArray[g1].edge1 ;
	    }
	    if( next_edge == 0 ) {
		break ;
	    }
	    next_g = edgeArray[next_edge].group1 ;
	    if( next_g == g1 ) {
		g1 = edgeArray[next_edge].group2 ;
	    } else {
		g1 = next_g ;
	    }
	    e1 = next_edge ;
	    edgeArray[e1].done = YES ;
	    key_queue[ ++key_count ] = e1 ;
	}
	e2 = edge ;
	g2 = edgeArray[e2].group2 ;
	for( ; ; ) {
	    if( groupArray[g2].poison == YES ) {
		break ;
	    }
	    if( groupArray[g2].edge1 == e2 ) {
		next_edge = groupArray[g2].edge2 ;
	    } else {
		next_edge = groupArray[g2].edge1 ;
	    }
	    if( next_edge == 0 ) {
		break ;
	    }
	    next_g = edgeArray[next_edge].group1 ;
	    if( next_g == g2 ) {
		g2 = edgeArray[next_edge].group2 ;
	    } else {
		g2 = next_g ;
	    }
	    e2 = next_edge ;
	    edgeArray[e2].done = YES ;
	    key_queue[ ++key_count ] = e2 ;
	}
	if( groupArray[g1].aveX <= groupArray[g2].aveX ) {
	    k_left  = groupArray[g1].aveX ;
	    k_right = groupArray[g2].aveX ;
	    pArray = groupArray[g1].pinArray ;
	    for(pin = 1; pin <= groupArray[g1].numPins; pin++ ){
		if( pArray[pin].top == 1 || pArray[pin].top == 0){
		    ltop = pArray[pin].pin ;
		}
		if(pArray[pin].top == -1 || pArray[pin].top == 0){
		    lbot = pArray[pin].pin ;
		}
	    }
	    pArray = groupArray[g2].pinArray ;
	    for(pin = 1; pin <= groupArray[g2].numPins; pin++ ){
		if( pArray[pin].top == 1 || pArray[pin].top == 0){
		    rtop = pArray[pin].pin ;
		}
		if(pArray[pin].top == -1 || pArray[pin].top == 0){
		    rbot = pArray[pin].pin ;
		}
	    }
	} else {
	    k_left  = groupArray[g2].aveX ;
	    k_right = groupArray[g1].aveX ;
	    pArray = groupArray[g2].pinArray ;
	    for(pin = 1; pin <= groupArray[g2].numPins; pin++ ){
		if( pArray[pin].top == 1 || pArray[pin].top == 0){
		    ltop = pArray[pin].pin ;
		}
		if(pArray[pin].top == -1 || pArray[pin].top == 0){
		    lbot = pArray[pin].pin ;
		}
	    }
	    pArray = groupArray[g1].pinArray ;
	    for(pin = 1; pin <= groupArray[g1].numPins; pin++ ){
		if( pArray[pin].top == 1 || pArray[pin].top == 0){
		    rtop = pArray[pin].pin ;
		}
		if(pArray[pin].top == -1 || pArray[pin].top == 0){
		    rbot = pArray[pin].pin ;
		}
	    }
	}
}
if( block1 == block2 ) {
	
	if( groupArray[group1].aveX <= groupArray[group2].aveX){
	    for(pin = 1; pin <= groupArray[group1].numPins; pin++ ){
		if( pArray1[pin].top == 1 || pArray1[pin].top == 0){
		    if( pArray1[ pin ].xloc > maxTop ) {
			maxTop = pArray1[ pin ].xloc ;
			maxTpin = pArray1[ pin ].pin ;
		    }
		}
		if(pArray1[pin].top == -1 || pArray1[pin].top == 0){
		    if( pArray1[ pin ].xloc > maxBottom ) {
			maxBottom = pArray1[ pin ].xloc ;
			maxBpin = pArray1[ pin ].pin ;
		    }
		}
	    }
	    sepT = 1000000000 ;
	    sepB = 1000000000 ;
	    otherTpin = 0 ;
	    otherBpin = 0 ;
	    for(pin = 1; pin <= groupArray[group2].numPins; pin++ ){
		if( pArray2[pin].top == 1 || pArray2[pin].top == 0){
		    if( ABS(pArray2[ pin ].xloc - maxTop) < sepT ) {
			otherTpin = pArray2[ pin ].pin ;
			minTop = pArray2[ pin ].xloc ;
			sepT = ABS( minTop - maxTop ) ;
		    }
		}
		if(pArray2[pin].top == -1 || pArray2[pin].top == 0){
		    if( ABS(pArray2[pin].xloc - maxBottom) < sepB ){
			otherBpin = pArray2[ pin ].pin ;
			minBottom = pArray2[ pin ].xloc ;
			sepB = ABS( minBottom - maxBottom );
		    }
		}
	    }
	    if( maxTpin != 0 && otherTpin != 0 &&
					    block1 < numChans ) {
		if( maxBpin != 0 && otherBpin != 0 && block1 > 0 ) {
				
		    aNetSeg[segIndex].nswYorN = 1 ;
		    if( key_flag == 0 || key_flag == segIndex ) {
			aNetSeg[segIndex].nkey = 0 ;
		    } else {
			aNetSeg[segIndex].nkey = key_flag ;
		    }
		    aNetSeg[segIndex].ncurrent = 0 ;
		    if( maxTop <= minTop ) {
			Tleft  = maxTop ;
			Tright = minTop ;
			p1  = maxTpin ;
			p2  = otherTpin ;
		    } else {
			Tleft  = minTop ;
			Tright = maxTop ;
			p1  = otherTpin ;
			p2  = maxTpin ;
		    }
		    if( key_flag != NO ) {
			Tleft  = k_left ;
			Tright = k_right ;
		    }
		    aNetSeg[segIndex].ntop->channel = block1 + 1;
		    aNetSeg[segIndex].ntop->pin1 = p1 ;
		    aNetSeg[segIndex].ntop->pin2 = p2 ;
		    if( maxBottom <= minBottom ) {
			Bleft  = maxBottom ;
			Bright = minBottom ;
			p1  = maxBpin ;
			p2  = otherBpin ;
		    } else {
			Bleft  = minBottom ;
			Bright = maxBottom ;
			p1  = otherBpin ;
			p2  = maxBpin ;
		    }
		    if( key_flag != NO ) {
			Bleft  = k_left ;
			Bright = k_right ;
		    }
		    aNetSeg[segIndex].nbot->channel = block1 ;
		    aNetSeg[segIndex].nbot->pin1 = p1 ;
		    aNetSeg[segIndex].nbot->pin2 = p2 ;
		    if( Bleft == Bright || Tleft == Tright ) {
			aNetSeg[segIndex].nswYorN = 0 ;
			if( Bleft == Bright && Tleft != Tright ) {
			    tmp_ptr = aNetSeg[segIndex].ntop ;
			    aNetSeg[segIndex].ntop =
					aNetSeg[segIndex].nbot ;
			    aNetSeg[segIndex].nbot = tmp_ptr ;
			}
		    }
		} else {
		    aNetSeg[segIndex].nswYorN = 0 ;
		    aNetSeg[segIndex].nkey    = 0 ;
		    aNetSeg[segIndex].ncurrent = 0 ;
		    if( maxTop <= minTop ) {
			p1  = maxTpin ;
			p2  = otherTpin ;
		    } else {
			p1  = otherTpin ;
			p2  = maxTpin ;
		    }
		    aNetSeg[segIndex].ntop->channel = block1 + 1;
		    aNetSeg[segIndex].ntop->pin1 = p1 ;
		    aNetSeg[segIndex].ntop->pin2 = p2 ;
		}
	    } else if( maxBpin != 0 && otherBpin != 0 ) {
		
		aNetSeg[segIndex].nswYorN = 0 ;
		aNetSeg[segIndex].nkey    = 0 ;
		aNetSeg[segIndex].ncurrent = 0 ;
		if( maxBottom <= minBottom ) {
		    p1  = maxBpin ;
		    p2  = otherBpin ;
		} else {
		    p1  = otherBpin ;
		    p2  = maxBpin ;
		}
		aNetSeg[segIndex].ntop->channel = block1 ;
		aNetSeg[segIndex].ntop->pin1 = p1 ;
		aNetSeg[segIndex].ntop->pin2 = p2 ;
	    }
	} else {
	    for(pin = 1; pin <= groupArray[group2].numPins ; pin++){
		if( pArray2[pin].top == 1 || pArray2[pin].top == 0){
		    if( pArray2[ pin ].xloc > maxTop ) {
			maxTop  = pArray2[ pin ].xloc ;
			maxTpin = pArray2[ pin ].pin ;
		    }
		}
		if(pArray2[pin].top == -1 || pArray2[pin].top == 0){
		    if( pArray2[ pin ].xloc > maxBottom ) {
			maxBottom = pArray2[ pin ].xloc ;
			maxBpin = pArray2[ pin ].pin ;
		    }
		}
	    }
	    sepT = 1000000000 ;
	    sepB = 1000000000 ;
	    otherTpin = 0 ;
	    otherBpin = 0 ;
	    for(pin = 1; pin <= groupArray[group1].numPins ; pin++){
		if( pArray1[pin].top == 1 || pArray1[pin].top == 0){
		    if( ABS(pArray1[ pin ].xloc - maxTop) < sepT ) {
			otherTpin = pArray1[ pin ].pin ;
			minTop = pArray1[ pin ].xloc ;
			sepT = ABS(minTop - maxTop ) ;
		    }
		}
		if(pArray1[pin].top == -1 || pArray1[pin].top == 0){
		    if( ABS(pArray1[pin].xloc - maxBottom) < sepB ){
		      otherBpin = pArray1[ pin ].pin ;
		      minBottom = pArray1[ pin ].xloc ;
		      sepB = ABS(minBottom - maxBottom) ;
		    }
		}
	    }
	    if( maxTpin != 0 && otherTpin != 0 &&
					    block1 < numChans ) {
		if( maxBpin != 0 && otherBpin != 0 && block1 > 0 ) {
				
		    aNetSeg[segIndex].nswYorN = 1 ;
		    if( key_flag == 0 || key_flag == segIndex ) {
			aNetSeg[segIndex].nkey = 0 ;
		    } else {
			aNetSeg[segIndex].nkey = key_flag ;
		    }
		    aNetSeg[segIndex].ncurrent = 0 ;
		    if( maxTop <= minTop ) {
			Tleft  = maxTop ;
			Tright = minTop ;
			p1  = maxTpin ;
			p2  = otherTpin ;
		    } else {
			Tleft  = minTop ;
			Tright = maxTop ;
			p1  = otherTpin ;
			p2  = maxTpin ;
		    }
		    if( key_flag != NO ) {
			Tleft  = k_left ;
			Tright = k_right ;
		    }
		    aNetSeg[segIndex].ntop->channel = block1 + 1;
		    aNetSeg[segIndex].ntop->pin1 = p1 ;
		    aNetSeg[segIndex].ntop->pin2 = p2 ;
		    if( maxBottom <= minBottom ) {
			Bleft  = maxBottom ;
			Bright = minBottom ;
			p1  = maxBpin ;
			p2  = otherBpin ;
		    } else {
			Bleft  = minBottom ;
			Bright = maxBottom ;
			p1  = otherBpin ;
			p2  = maxBpin ;
		    }
		    if( key_flag != NO ) {
			Bleft  = k_left ;
			Bright = k_right ;
		    }
		    aNetSeg[segIndex].nbot->channel = block1 ;
		    aNetSeg[segIndex].nbot->pin1 = p1 ;
		    aNetSeg[segIndex].nbot->pin2 = p2 ;
		    if( Bleft == Bright || Tleft == Tright ) {
			aNetSeg[segIndex].nswYorN = 0 ;
			if( Bleft == Bright && Tleft != Tright ) {
			    tmp_ptr = aNetSeg[segIndex].ntop ;
			    aNetSeg[segIndex].ntop =
					aNetSeg[segIndex].nbot ;
			    aNetSeg[segIndex].nbot = tmp_ptr ;
			}
		    }
		} else {
		    aNetSeg[segIndex].nswYorN = 0 ;
		    aNetSeg[segIndex].nkey    = 0 ;
		    aNetSeg[segIndex].ncurrent = 0 ;
		    if( maxTop <= minTop ) {
			p1  = maxTpin ;
			p2  = otherTpin ;
		    } else {
			p1  = otherTpin ;
			p2  = maxTpin ;
		    }
		    aNetSeg[segIndex].ntop->channel = block1 + 1;
		    aNetSeg[segIndex].ntop->pin1 = p1 ;
		    aNetSeg[segIndex].ntop->pin2 = p2 ;
		}
	    } else if( maxBpin != 0 && otherBpin != 0 ) {
		
		aNetSeg[segIndex].nswYorN = 0 ;
		aNetSeg[segIndex].nkey    = 0 ;
		aNetSeg[segIndex].ncurrent = 0 ;
		if( maxBottom <= minBottom ) {
		    p1  = maxBpin ;
		    p2  = otherBpin ;
		} else {
		    p1  = otherBpin ;
		    p2  = maxBpin ;
		}
		aNetSeg[segIndex].ntop->channel = block1 ;
		aNetSeg[segIndex].ntop->pin1 = p1 ;
		aNetSeg[segIndex].ntop->pin2 = p2 ;
	    }
	}
	if( aNetSeg[segIndex].nswYorN == 1 || key_flag != NO ) {
	    channel = aNetSeg[segIndex].ntop->channel ;
	    if( key_flag == NO ) {
		pin1 = aNetSeg[segIndex].ntop->pin1 ;
		pin2 = aNetSeg[segIndex].ntop->pin2 ;
	    } else {
		if( k_right > k_left ) {
		    pin1 = ltop ;
		    pin2 = rtop ;
		} else {
		    pin1 = pin2 = aNetSeg[segIndex].ntop->pin1 ;
		}
	    }
	    aNetSeg[segIndex].ntop->pin1ptr = Tgrid[ pin1 ]->up ;
	    if( tearray[ pin1 ]->pinloc == 0 &&
		tearray[ pin1 ]->row == channel ) {
		aNetSeg[segIndex].ntop->pin1ptr = Tgrid[pin1]->down;
	    }
	    aNetSeg[segIndex].ntop->pin2ptr = Tgrid[ pin2 ]->up ;
	    if( tearray[ pin2 ]->pinloc == 0 &&
		tearray[ pin2 ]->row == channel ) {
		aNetSeg[segIndex].ntop->pin2ptr = Tgrid[pin2]->down;
	    }
	    channel = aNetSeg[segIndex].nbot->channel ;
	    if( key_flag == NO ) {
		pin1 = aNetSeg[segIndex].nbot->pin1 ;
		pin2 = aNetSeg[segIndex].nbot->pin2 ;
	    } else {
		if( k_right > k_left ) {
		    pin1 = lbot ;
		    pin2 = rbot ;
		} else {
		    pin1 = pin2 = aNetSeg[segIndex].nbot->pin1 ;
		}
	    }
	    aNetSeg[segIndex].nbot->pin1ptr = Tgrid[ pin1 ]->up ;
	    if( tearray[ pin1 ]->pinloc == 0 &&
		tearray[ pin1 ]->row == channel ) {
		aNetSeg[segIndex].nbot->pin1ptr = Tgrid[pin1]->down;
	    }
	    aNetSeg[segIndex].nbot->pin2ptr = Tgrid[ pin2 ]->up ;
	    if( tearray[ pin2 ]->pinloc == 0 &&
		tearray[ pin2 ]->row == channel ) {
		aNetSeg[segIndex].nbot->pin2ptr = Tgrid[pin2]->down;
	    }
	} else {
	    channel = aNetSeg[segIndex].ntop->channel ;
	    if( key_flag == NO ) {
		pin1 = aNetSeg[segIndex].ntop->pin1 ;
		pin2 = aNetSeg[segIndex].ntop->pin2 ;
	    } else {
		if( k_right > k_left ) {
		    pin1 = ltop ;
		    pin2 = rtop ;
		} else {
		    pin1 = pin2 = aNetSeg[segIndex].ntop->pin1 ;
		}
	    }
	    aNetSeg[segIndex].ntop->pin1ptr = Tgrid[ pin1 ]->up ;
	    if( tearray[ pin1 ]->pinloc == 0 &&
		tearray[ pin1 ]->row == channel ) {
		aNetSeg[segIndex].ntop->pin1ptr = Tgrid[pin1]->down;
	    }
	    aNetSeg[segIndex].ntop->pin2ptr = Tgrid[ pin2 ]->up ;
	    if( tearray[ pin2 ]->pinloc == 0 &&
		tearray[ pin2 ]->row == channel ) {
		aNetSeg[segIndex].ntop->pin2ptr = Tgrid[pin2]->down;
	    }
	}
} else {
	minX = 1000000000 ;
	minP1 = 0 ;
	minP2 = 0 ;
	if( block1 > block2 ) {
	    for(pin1 = 1;pin1 <= groupArray[group1].numPins;pin1++){
		if( pArray1[pin1].top == -1 ||
					pArray1[pin1].top == 0 ) {
		    pin2 = 1 ;
		    for(;pin2 <= groupArray[group2].numPins;pin2++){
			if( pArray2[ pin2 ].top == 1 ||
					pArray2[pin2].top == 0 ) {
			    if( ABS( pArray1[ pin1 ].xloc -
				   pArray2[ pin2 ].xloc ) < minX ) {
				left  = pArray1[pin1].xloc;
				right = pArray2[pin2].xloc;
				minX  = ABS( left - right );
				minP1 = pArray1[pin1].pin;
				minP2 = pArray2[pin2].pin;
			    }
			}
		    }
		}
	    }
	    if( minP1 != 0 && minP2 != 0 ) {
		aNetSeg[segIndex].nswYorN = 0 ;
		aNetSeg[segIndex].nkey    = 0 ;
		aNetSeg[segIndex].ncurrent = 0 ;
		if( left > right ) {
		    aNetSeg[segIndex].ntop->channel = block1 ;
		    aNetSeg[segIndex].ntop->pin1 = minP2 ;
		    aNetSeg[segIndex].ntop->pin2 = minP1 ;
		} else {
		    aNetSeg[segIndex].ntop->channel = block1 ;
		    aNetSeg[segIndex].ntop->pin1 = minP1 ;
		    aNetSeg[segIndex].ntop->pin2 = minP2 ;
		}
	    }
	} else {
	    pin1 = 1 ;
	    for(; pin1 <= groupArray[group1].numPins; pin1++ ) {
		if( pArray1[pin1].top == 1 ||
					pArray1[pin1].top == 0 ) {
		    pin2 = 1 ;
		    for(;pin2 <= groupArray[group2].numPins;pin2++){
			if( pArray2[ pin2 ].top == -1 ||
					pArray2[pin2].top == 0 ) {
			    if( ABS( pArray1[ pin1 ].xloc -
				   pArray2[ pin2 ].xloc ) < minX ) {
				left = pArray1[pin1].xloc;
				right = pArray2[pin2].xloc;
				minX = ABS( left - right ) ;
				minP1 = pArray1[pin1].pin;
				minP2 = pArray2[pin2].pin;
			    }
			}
		    }
		}
	    }
	    if( minP1 != 0 && minP2 != 0 ) {
		aNetSeg[segIndex].nswYorN = 0 ;
		aNetSeg[segIndex].nkey    = 0 ;
		aNetSeg[segIndex].ncurrent = 0 ;
		if( left > right ) {
		    aNetSeg[segIndex].ntop->channel = block2 ;
		    aNetSeg[segIndex].ntop->pin1 = minP2 ;
		    aNetSeg[segIndex].ntop->pin2 = minP1 ;
		} else {
		    aNetSeg[segIndex].ntop->channel = block2 ;
		    aNetSeg[segIndex].ntop->pin1 = minP1 ;
		    aNetSeg[segIndex].ntop->pin2 = minP2 ;
		}
	    }
	}
	channel = aNetSeg[segIndex].ntop->channel ;
	pin1 = aNetSeg[segIndex].ntop->pin1 ;
	pin2 = aNetSeg[segIndex].ntop->pin2 ;
	aNetSeg[segIndex].ntop->pin1ptr = Tgrid[ pin1 ]->up ;
	if( tearray[ pin1 ]->pinloc == 0 &&
	    tearray[ pin1 ]->row == channel ) {
	    aNetSeg[segIndex].ntop->pin1ptr = Tgrid[pin1]->down;
	}
	aNetSeg[segIndex].ntop->pin2ptr = Tgrid[ pin2 ]->up ;
	if( tearray[ pin2 ]->pinloc == 0 &&
	    tearray[ pin2 ]->row == channel ) {
	    aNetSeg[segIndex].ntop->pin2ptr = Tgrid[pin2]->down;
	}
}
}
#ifdef DEBUG
if( segIndex != fault_line - 1 ) {
printf("Serious FAULT detected in function: uclosepns():");
printf("   Net:%d\n", net );
fflush(stdout);
}
#endif
return ;
}
/* 当前文件是D:\Read\ucxx1.c*/

ucxx1( bxcenter , bycenter )
int bxcenter , bycenter ;
{
CBOXPTR acellptr ;
TIBOXPTR atileptr ;
TEBOXPTR atermptr ;
int cost ;
int axcenter ;
int aleft , aright ;
int a1LoBin , a1HiBin , b1LoBin , b1HiBin ;
int startxa1 , endxa1 , startxb1 , endxb1 ;
int truth , aorient ;
acellptr = carray[ a ]    ;
aorient  = acellptr->corient ;
axcenter = acellptr->cxcenter ;
atileptr = acellptr->tileptr  ;
aleft    = atileptr->left    ;
aright   = atileptr->right   ;
atermptr = atileptr->termsptr ;
newbinpenal = binpenal ;
newrowpenal = rowpenal ;
newpenal    = penalty ;
new_old( aleft-aright ) ;
a1LoBin = SetBin( startxa1 = axcenter + aleft  ) ;
a1HiBin = SetBin( endxa1   = axcenter + aright ) ;
b1LoBin = SetBin( startxb1 = bxcenter + aleft  ) ;
b1HiBin = SetBin( endxb1   = bxcenter + aright ) ;
old_assgnto_new1( a1LoBin , a1HiBin , b1LoBin , b1HiBin ) ;
sub_penal( startxa1 , endxa1 , ablock , a1LoBin , a1HiBin ) ;
add_penal( startxb1 , endxb1 , bblock , b1LoBin , b1HiBin ) ;
if( ablock != bblock ) {
term_newpos_a( atermptr , bxcenter , bycenter , aorient ) ;
} else {
term_newpos( atermptr , bxcenter , bycenter , aorient ) ;
}
cost = funccost ;
delta_vert_cost = 0 ;
if( ablock != bblock ) {
new_dbox_a( atermptr , &cost ) ;
} else {
new_dbox( atermptr , &cost ) ;
}
wire_chg = cost - funccost ;
binpen_chg = newbinpenal - binpenal ;
rowpen_chg = newrowpenal - rowpenal ;
newpenal = (int)( roLenCon * (double) newrowpenal +
				binpenCon * (double) newbinpenal ) ;
truth = acceptt(funccost + penalty - cost - newpenal - delta_vert_cost);
if( truth == 1 ) {
new_assgnto_old1( a1LoBin , a1HiBin , b1LoBin , b1HiBin ) ;
if( ablock != bblock ) {
	dbox_pos_2( atermptr ) ;
} else {
	dbox_pos( atermptr ) ;
}
remv_cell( cellaptr , Apost ) ;
add_cell( &cellbptr , a ) ;
acellptr->cblock   = bblock   ;
acellptr->cxcenter = bxcenter ;
acellptr->cycenter = bycenter ;
funccost = cost ;
binpenal = newbinpenal ;
rowpenal = newrowpenal ;
penalty  = newpenal ;
if( ablock != bblock ) {
	barray[ablock]->oldsize = barray[ablock]->newsize ;
	barray[bblock]->oldsize = barray[bblock]->newsize ;
}
return( 1 ) ;
} else {
return( 0 ) ;
}
}

find_new_pos()
{
int newA_l , newA_r , newB_l , newB_r ;
int oldA_l , oldA_r , oldB_l , oldB_r ;
int span , target , target_l , target_r , blkLeft , blkRite ;
int dist1 , dist2 ;
newA_l = bxcenter + aleft  ;
newA_r = bxcenter + aright ;
newB_l = axcenter + bleft  ;
newB_r = axcenter + bright ;
if( (ablock == bblock) && (!( (newA_l >= newB_r) || (newB_l >= newA_r)))){
oldA_l = axcenter + aleft  ;
oldA_r = axcenter + aright ;
oldB_l = bxcenter + bleft  ;
oldB_r = bxcenter + bright ;
if( !( (oldA_l >= oldB_r) || (oldB_l >= oldA_r) ) ) {
	
	span = aright - aleft + bright - bleft ;
	target = ( ((oldA_l <= oldB_l) ? oldA_l : oldB_l) +
		   ((oldA_r >= oldB_r) ? oldA_r : oldB_r) ) / 2 ;
	target_l = target - span / 2 ;
	target_r = target_l + span ;
	blkLeft = barray[ablock]->bxcenter + barray[ablock]->bleft ;
	blkRite = blkLeft + barray[ablock]->desire  ;
	if( target_l < blkLeft ) {
	    target_l += blkLeft - target_l ;
	    target_r += blkLeft - target_l ;
	} else if( target_r > blkRite ) {
	    target_l -= target_r - blkRite ;
	    target_r -= target_r - blkRite ;
	}
	dist1 = newA_r - newB_l ;
	dist2 = newB_r - newA_l ;
	if( dist1 <= dist2 ) {
	    anxcenter = target_l - aleft  ;
	    bnxcenter = target_r - bright ;
	} else {
	    anxcenter = target_r - aright ;
	    bnxcenter = target_l - bleft  ;
	}
} else {
	
	if( oldA_l <= oldB_l ) {
	    bnxcenter = oldA_l - bleft  ;
	    anxcenter = oldB_r - aright ;
	} else {
	    anxcenter = oldB_l - aleft  ;
	    bnxcenter = oldA_r - bright ;
	}
}
} else {
anxcenter = bxcenter ;
bnxcenter = axcenter ;
}
return ;
}
add_cell( cellptr , c )
int **cellptr , c ;
{
int k ;
if( (k = ++(**cellptr)) % 10 == 0 ) {
*cellptr = (int *) safe_realloc( *cellptr, (k + 10) * sizeof(int));
}
(*cellptr)[k] = c ;
return ;
}
/* 当前文件是D:\Read\ucxxo1.c*/

ucxxo1( bxcenter , bycenter , newaor )
int bxcenter , bycenter , newaor ;
{
CBOXPTR acellptr ;
TIBOXPTR atileptr ;
TEBOXPTR antrmptr ;
int cost ;
int axcenter ;
int aleft , aright ;
int a1LoBin, a1HiBin, b1LoBin, b1HiBin ;
int startxa1 , endxa1 , startxb1 , endxb1 ;
int truth ;
acellptr = carray[ a ]    ;
axcenter = acellptr->cxcenter ;
atileptr = acellptr->tileptr ;
aleft    = atileptr->left ;
aright   = atileptr->right ;
antrmptr = atileptr->termsptr ;
newbinpenal = binpenal ;
newrowpenal = rowpenal ;
newpenal    = penalty ;
new_old( aleft - aright ) ;
a1LoBin = SetBin( startxa1 = axcenter + aleft   ) ;
a1HiBin = SetBin( endxa1   = axcenter + aright  ) ;
b1LoBin = SetBin( startxb1 = bxcenter + aleft   ) ;
b1HiBin = SetBin( endxb1   = bxcenter + aright  ) ;
old_assgnto_new1( a1LoBin , a1HiBin , b1LoBin , b1HiBin ) ;
sub_penal( startxa1 , endxa1 , ablock , a1LoBin , a1HiBin ) ;
add_penal( startxb1 , endxb1 , bblock , b1LoBin , b1HiBin ) ;
if( ablock != bblock ) {
term_newpos_a( antrmptr , bxcenter , bycenter , newaor ) ;
} else {
term_newpos( antrmptr , bxcenter , bycenter , newaor ) ;
}
cost = funccost ;
delta_vert_cost = 0 ;
if( ablock != bblock ) {
new_dbox_a( antrmptr , &cost ) ;
} else {
new_dbox( antrmptr , &cost ) ;
}
wire_chg = cost - funccost ;
binpen_chg = newbinpenal - binpenal ;
rowpen_chg = newrowpenal - rowpenal ;
newpenal = (int)( roLenCon * (double) newrowpenal +
				binpenCon * (double) newbinpenal ) ;
truth = acceptt(funccost + penalty - cost - newpenal - delta_vert_cost);
if( truth == 1 ) {
new_assgnto_old1( a1LoBin , a1HiBin , b1LoBin , b1HiBin ) ;
if( ablock != bblock ) {
	dbox_pos_2( antrmptr ) ;
} else {
	dbox_pos( antrmptr ) ;
}
remv_cell( cellaptr , Apost ) ;
add_cell( &cellbptr , a ) ;
acellptr->cblock   = bblock   ;
acellptr->cxcenter = bxcenter     ;
acellptr->cycenter = bycenter     ;
acellptr->corient  = newaor ;
funccost = cost ;
binpenal = newbinpenal ;
rowpenal = newrowpenal ;
penalty  = newpenal ;
if( ablock != bblock ) {
	barray[ablock]->oldsize = barray[ablock]->newsize ;
	barray[bblock]->oldsize = barray[bblock]->newsize ;
}
return( 1 ) ;
} else {
return( 0 ) ;
}
}
/* 当前文件是D:\Read\ucxxo2.c*/








ucxxo2( newaor , newbor )
int newaor , newbor ;
{
CBOXPTR acellptr , bcellptr ;
TIBOXPTR atileptr , btileptr ;
TEBOXPTR antrmptr , bntrmptr ;
double temp ;
int cost , error_light_is_on ;
int axcenter , aycenter , bxcenter , bycenter ;
int aleft , aright ;
int bleft , bright ;
int a1LoBin, a2LoBin, b1LoBin, b2LoBin ;
int a1HiBin, a2HiBin, b1HiBin, b2HiBin ;
int startxa1 , endxa1 , startxa2 , endxa2 ;
int startxb1 , endxb1 , startxb2 , endxb2 ;
int truth ;
acellptr = carray[ a ]    ;
axcenter = acellptr->cxcenter ;
aycenter = acellptr->cycenter ;
atileptr = acellptr->tileptr ;
aleft    = atileptr->left    ;
aright   = atileptr->right   ;
antrmptr = atileptr->termsptr ;
bcellptr = carray[ b ]        ;
bxcenter = bcellptr->cxcenter ;
bycenter = bcellptr->cycenter ;
btileptr = bcellptr->tileptr  ;
bleft    = btileptr->left     ;
bright   = btileptr->right    ;
bntrmptr = btileptr->termsptr ;
newbinpenal = binpenal ;
newrowpenal = rowpenal ;
newpenal    = penalty ;
new_old( bright - bleft - aright + aleft ) ;
a1LoBin = SetBin( startxa1 = axcenter + aleft    ) ;
a1HiBin = SetBin( endxa1   = axcenter + aright   ) ;
b1LoBin = SetBin( startxb1 = bxcenter + bleft    ) ;
b1HiBin = SetBin( endxb1   = bxcenter + bright   ) ;
a2LoBin = SetBin( startxa2 = bxcenter + aleft    ) ;
a2HiBin = SetBin( endxa2   = bxcenter + aright   ) ;
b2LoBin = SetBin( startxb2 = axcenter + bleft    ) ;
b2HiBin = SetBin( endxb2   = axcenter + bright   ) ;
old_assgnto_new2( a1LoBin , a1HiBin , b1LoBin , b1HiBin ,
		  a2LoBin , a2HiBin , b2LoBin , b2HiBin ) ;
sub_penal( startxa1 , endxa1 , ablock , a1LoBin , a1HiBin ) ;
sub_penal( startxb1 , endxb1 , bblock , b1LoBin , b1HiBin ) ;
add_penal( startxa2 , endxa2 , bblock , a2LoBin , a2HiBin ) ;
add_penal( startxb2 , endxb2 , ablock , b2LoBin , b2HiBin ) ;
binpen_chg = newbinpenal - binpenal ;
rowpen_chg = newrowpenal - rowpenal ;
newpenal = (int)( roLenCon * (double) newrowpenal +
				binpenCon * (double) newbinpenal ) ;
error_light_is_on = 0 ;
if( newpenal - penalty > P_limit ) {
if( potential_errors < 100 ) {
	++potential_errors ;
	error_light_is_on = 1 ;
} else {
	earlyRej++ ;
	return( -1 ) ;
}
}
if( ablock != bblock ) {
term_newpos_a( antrmptr , bxcenter , bycenter , newaor ) ;
term_newpos_b( bntrmptr , axcenter , aycenter , newbor ) ;
} else {
term_newpos( antrmptr , bxcenter , bycenter , newaor ) ;
term_newpos( bntrmptr , axcenter , aycenter , newbor ) ;
}
cost = funccost ;
delta_vert_cost = 0 ;
if( ablock != bblock ) {
new_dbox_a( antrmptr , &cost ) ;
new_dbox_a( bntrmptr , &cost ) ;
} else {
new_dbox( antrmptr , &cost ) ;
new_dbox( bntrmptr , &cost ) ;
}
wire_chg = cost - funccost ;
truth = acceptt(funccost + penalty - cost - newpenal - delta_vert_cost);
if( truth == 1 ) {
if( error_light_is_on ) {
	error_count++ ;
}
new_assgnto_old2( a1LoBin , a1HiBin , b1LoBin , b1HiBin ,
		      a2LoBin , a2HiBin , b2LoBin , b2HiBin ) ;
if( ablock != bblock ) {
	dbox_pos_2( antrmptr ) ;
	dbox_pos_2( bntrmptr ) ;
} else {
	dbox_pos( antrmptr ) ;
	dbox_pos( bntrmptr ) ;
}
if( cellaptr != cellbptr ) {
	remv_cell( cellaptr , Apost ) ;
	remv_cell( cellbptr , Bpost ) ;
	add_cell( &cellbptr , a ) ;
	add_cell( &cellaptr , b ) ;
}
if( wire_chg < 0 ) {
	temp = (double) - wire_chg ;
	total_wire_chg += temp ;
	sigma_wire_chg += (temp - mean_wire_chg) *
					(temp - mean_wire_chg) ;
	wire_chgs++ ;
}
acellptr->cblock   = bblock   ;
acellptr->cxcenter = bxcenter ;
acellptr->cycenter = bycenter ;
bcellptr->cblock   = ablock   ;
bcellptr->cxcenter = axcenter ;
bcellptr->cycenter = aycenter ;
acellptr->corient = newaor ;
bcellptr->corient = newbor ;
funccost = cost ;
binpenal = newbinpenal ;
rowpenal = newrowpenal ;
penalty  = newpenal ;
if( ablock != bblock ) {
	barray[ablock]->oldsize = barray[ablock]->newsize ;
	barray[bblock]->oldsize = barray[bblock]->newsize ;
}
return( 1 ) ;
} else {
return( 0 ) ;
}
}
/* 当前文件是D:\Read\ucxxp.c*/

ucxxp( a , b , anxcenter , bnxcenter )
int a , b , anxcenter , bnxcenter ;
{
CBOXPTR acellptr , bcellptr ;
TIBOXPTR atileptr , btileptr ;
TEBOXPTR atermptr , btermptr ;
int cost ;
int aorient , borient ;
int aycenter , bycenter ;
int truth ;
acellptr = carray[ a ]    ;
aycenter = acellptr->cycenter ;
aorient  = acellptr->corient  ;
atileptr = acellptr->tileptr ;
atermptr = atileptr->termsptr ;
bcellptr = carray[ b ]    ;
bycenter = bcellptr->cycenter ;
borient  = bcellptr->corient  ;
btileptr = bcellptr->tileptr ;
btermptr = btileptr->termsptr ;
term_newpos( atermptr , anxcenter , bycenter , aorient ) ;
term_newpos( btermptr , bnxcenter , aycenter , borient ) ;
cost = funccost ;
new_dbox( atermptr , &cost ) ;
new_dbox( btermptr , &cost ) ;
truth = acceptt( funccost - cost ) ;
if( truth == 1 ) {
dbox_pos( atermptr ) ;
dbox_pos( btermptr ) ;
acellptr->cxcenter = anxcenter ;
acellptr->cycenter = bycenter ;
bcellptr->cxcenter = bnxcenter ;
bcellptr->cycenter = aycenter ;
funccost = cost ;
return( 1 ) ;
} else {
return( 0 ) ;
}
}
/* 当前文件是D:\Read\uglobe.c*/

#define T   2
#define R   3
#define GOING_UP 1
#define GOING_DN -1
#define GOING_UP_OR_DN 0
#define SAME_ROW 0
#define UP_ROW 1
#define DN_ROW -1
#define TOP_SIDE 1
#define BOT_SIDE -1
#define BOTH_SIDES 0
#define UNEQUIV_SIDES 2
#define SUCCESS 1
#define FAILURE 0
uglobe()
{
NBOXPTR netptr ;
CBOXPTR cellptr1 , cellptr2 ;
int group1 , group2 , edge , i , pin , net , group , cell1 , cell2 ;
int top , extint , block , locX , locY ;
int flag1 , flag2 , chgloop ;
int found, type1 ;
int unequiv , added_an_edge , ue_grp , g1 , g2 , ei1 , ei2 ;
int ei , done , edge2 , jj ;
int a1 , b1 , a2 , b2 , edge1 , ya , yb ;
int single_pin1 , single_pin2 , unequiv1 , unequiv2 ;
for(  i = 0 ; i <= MPG ; i++ ){
groupArray[i].numPins = 0 ;
groupArray[i].flag    = 0 ;
groupArray[i].poison  = 0 ;
groupArray[i].unequiv = 0 ;
groupArray[i].extint  = 0 ;
groupArray[i].edge1   = 0 ;
groupArray[i].edge2   = 0 ;
groupArray[i].check   = 0 ;
}
for(  i = 0 ; i <= ME ; i++ ){
edgeArray[i].marked = 0 ;
edgeArray[i].done   = 0 ;
edgeArray[i].poison = 0 ;
}
for( chgloop = 1 ; chgloop <= netchgs[0] ; chgloop++ ) {
net = netchgs[chgloop] ;
numEdges = 0 ;
top_row = -1 ;
for( jj = 0 ; jj <= numRows + 1 ; jj++ ) {
	pseudoPins[jj][0] = 0 ;
	pseudoPins[jj][1] = 0 ;
	pseudoEdge[jj][0] = 0 ;
	pseudoEdge[jj][1] = 0 ;
}
netptr = netarray[net]->netptr ;
for( ; netptr != NETNULL ; netptr = netptr->nterm ) {
	top    = netptr->pinloc   ;
	extint = netptr->extint   ;
	unequiv = netptr->unequiv ;
	block  = netptr->row      ;
	if( block > top_row ) {
	    if( netptr->cell <= numcells ) {
		top_row = block ;
	    } else if( carray[netptr->cell]->padside != L &&
		       carray[netptr->cell]->padside != R ) {
		top_row = block ;
	    }
	}
	locX   = netptr->xpos     ;
	locY   = netptr->ypos     ;
	pin    = netptr->terminal ;
	found = FAILURE ;
	group = 1 ;
	while( groupArray[ group ].numPins != 0 && found == FAILURE ){
	    if( groupArray[ group ].extint == extint && unequiv == NO ) {
		found = SUCCESS ;
	    } else {
		group++ ;
	    }
	}
	numPins = groupArray[ group ].numPins + 1 ;
	groupArray[ group ].numPins = numPins ;
	groupArray[ group ].pinArray[ numPins ].xloc = locX ;
	groupArray[ group ].pinArray[ numPins ].yloc = locY ;
	groupArray[ group ].pinArray[ numPins ].top = top ;
	groupArray[ group ].pinArray[ numPins ].pin = pin ;
	if( found == FAILURE ) {
	    groupArray[ group ].aveX   = locX   ;
	    groupArray[ group ].aveY   = locY   ;
	    groupArray[ group ].extint = extint ;
	    groupArray[ group ].unequiv = unequiv ;
	    groupArray[ group ].block  = block  ;
	} else {
	
	    groupArray[ group ].aveX += locX ;
	    groupArray[ group ].aveY += locY ;
	}
}
group = 1 ;
for( group = 1; groupArray[ group ].numPins != 0 ; group++ ) {
	numPins = groupArray[ group ].numPins ;
	if( numPins > 1  ) {
	    groupArray[group].aveX /= numPins ;
	    groupArray[group].aveY /= numPins ;
	}
}
numGroups = 0 ;
while( groupArray[ numGroups + 1 ].numPins != 0 ) {
	numGroups++ ;
}
if( numGroups == 2 ) {
	if( groupArray[1].unequiv == 1 && groupArray[2].unequiv == 1 ) {
	    for( i = 1 ; i <= numGroups ; i++ ) {
		groupArray[i].numPins = 0 ;
		groupArray[i].flag    = 0 ;
		groupArray[i].poison  = 0 ;
		groupArray[i].unequiv = 0 ;
		groupArray[i].extint  = 0 ;
		groupArray[i].edge1   = 0 ;
		groupArray[i].edge2   = 0 ;
		groupArray[i].check   = 0 ;
	    }
	    for( i = 1 ; i <= numEdges ; i++ ) {
		edgeArray[i].marked = 0 ;
		edgeArray[i].done   = 0 ;
		edgeArray[i].poison = 0 ;
	    }
	    continue ;
	}
} else if( numGroups <= 1 ) {
	for( i = 1 ; i <= numGroups ; i++ ) {
	    groupArray[i].numPins = 0 ;
	    groupArray[i].flag    = 0 ;
	    groupArray[i].poison  = 0 ;
	    groupArray[i].unequiv = 0 ;
	    groupArray[i].extint  = 0 ;
	    groupArray[i].edge1   = 0 ;
	    groupArray[i].edge2   = 0 ;
	    groupArray[i].check   = 0 ;
	}
	for( i = 1 ; i <= numEdges ; i++ ) {
	    edgeArray[i].marked = 0 ;
	    edgeArray[i].done   = 0 ;
	    edgeArray[i].poison = 0 ;
	}
	continue ;
}
qsortg((char *)(groupArray + 1), numGroups,sizeof(csGroup));
for( group = 1 ; group < numGroups ; group++ ) {
	block = groupArray[ group ].block ;
	type1 = detGroup( group ) ;
	searchG( group , type1 , block ) ;
}
for( edge1 = 1 ; edge1 <= numEdges ; edge1++ ) {
	a1 = edgeArray[edge1].group1 ;
	a2 = edgeArray[edge1].group2 ;
	if( groupArray[a1].block != groupArray[a2].block ) {
	    continue ;
	}
	for( edge2 = edge1 + 1 ; edge2 <= numEdges ; edge2++ ) {
	    b1 = edgeArray[edge2].group1 ;
	    b2 = edgeArray[edge2].group2 ;
	    if( groupArray[b1].block != groupArray[b2].block ) {
		continue ;
	    }
	    if( (groupArray[a1].unequiv == 1 &&
					groupArray[b1].unequiv == 1 &&
		    groupArray[a1].extint == groupArray[b1].extint  &&
		    groupArray[a2].extint == groupArray[b2].extint) ||
		(groupArray[a2].unequiv == 1 &&
					groupArray[b2].unequiv == 1 &&
		    groupArray[a2].extint == groupArray[b2].extint  &&
		    groupArray[a1].extint == groupArray[b1].extint)  ) {
		ya = (groupArray[a1].aveY + groupArray[a2].aveY) / 2 ;
		yb = (groupArray[b1].aveY + groupArray[b2].aveY) / 2 ;
		if( groupArray[a1].block == top_row ) {
		    if( ya < yb ) {
			if( edgeArray[edge2].cost <=
					    edgeArray[edge1].cost ) {
			    edgeArray[edge2].cost =
					    edgeArray[edge1].cost + 1 ;
			}
		    } else {
			if( edgeArray[edge2].cost >=
					    edgeArray[edge1].cost ) {
			    edgeArray[edge2].cost =
					    edgeArray[edge1].cost - 1 ;
			}
		    }
		} else {
		    if( ya < yb ) {
			if( edgeArray[edge2].cost >=
					    edgeArray[edge1].cost ) {
			    edgeArray[edge2].cost =
					    edgeArray[edge1].cost - 1 ;
			}
		    } else {
			if( edgeArray[edge2].cost <=
					    edgeArray[edge1].cost ) {
			    edgeArray[edge2].cost =
					    edgeArray[edge1].cost + 1 ;
			}
		    }
		}
		break ;
	    }
	}
}
qsorte( (char *) (edgeArray + 1) , numEdges , sizeof( edgeBox ) ) ;
for( group = 1 ; group <= numGroups ; group++ ) {
	groupArray[group].flag = group ;
}
for( edge = 1 ; edge <= numEdges ; edge++ ) {
	group1 = edgeArray[ edge ].group1 ;
	flag1  = groupArray[ group1 ].flag ;
	group2 = edgeArray[ edge ].group2 ;
	flag2  = groupArray[ group2 ].flag ;
	if( flag1 <= 0 || flag2 <= 0 || flag1 == flag2 ) {
	    continue ;
	}
	added_an_edge = NO ;
	edgeArray[ edge ].marked = 1 ;
	for( group = 1; group <= numGroups; group++ ) {
	    if( groupArray[ group ].flag == flag2 ) {
		groupArray[ group ].flag = flag1 ;
	    }
	}
	cell1 = tearray[ groupArray[group1].pinArray[1].pin ]->cell ;
	cell2 = tearray[ groupArray[group2].pinArray[1].pin ]->cell ;
	cellptr1 = carray[cell1] ;
	cellptr2 = carray[cell2] ;
	if( cell1 > numcells && cellptr1->padside != 2 &&
			        cellptr1->padside != MTT &&
			        cellptr1->padside != MBB &&
			        cellptr1->padside != B ) {
	    if( cell2 <= numcells ) {
		groupArray[group1].flag = 0 ;
	    }
	}
	if( cell2 > numcells && cellptr2->padside != 2 &&
			        cellptr2->padside != MTT &&
			        cellptr2->padside != MBB &&
			        cellptr2->padside != B ) {
	    if( cell1 <= numcells ) {
		groupArray[group2].flag = 0 ;
	    }
	}
	if( groupArray[group1].unequiv == 1 ) {
	    ei1 = groupArray[group1].extint ;
	    for( ue_grp = 1; ue_grp <= numGroups; ue_grp++ ) {
		if( ue_grp == group1 ) {
		    continue ;
		}
		if( groupArray[ue_grp].extint == ei1 ) {
		    break ;
		}
	    }
	    if( groupArray[ue_grp].flag > 0 ) {
		g1 = g2 = 0 ;
		groupArray[ue_grp].flag = -1 ;
		for( edge2 = edge + 1 ; edge2 <= numEdges ; edge2++ ) {
		    if( g2 == 0 ) {
			if( edgeArray[edge2].group1 == ue_grp ) {
			    g2 = edgeArray[edge2].group2 ;
			    if( groupArray[g2].flag < 0 ) {
				g2 = 0 ;
			    }
			    continue ;
			}
		    }
		    if( g1 == 0 ) {
			if( edgeArray[edge2].group2 == ue_grp ) {
			    g1 = edgeArray[edge2].group1 ;
			    if( groupArray[g1].flag < 0 ) {
				g1 = 0 ;
			    }
			}
		    }
		}
		if( g1 != 0 && g2 != 0 ) {
		    addEdge( g1, g2 ) ;
		    added_an_edge = YES ;
		}
	    }
	}
	if( groupArray[group2].unequiv == 1 ) {
	    ei2 = groupArray[group2].extint ;
	    for( ue_grp = 1; ue_grp <= numGroups; ue_grp++ ) {
		if( ue_grp == group2 ) {
		    continue ;
		}
		if( groupArray[ue_grp].extint == ei2 ) {
		    break ;
		}
	    }
	    if( groupArray[ue_grp].flag > 0 ) {
		g1 = g2 = 0 ;
		groupArray[ue_grp].flag = -1 ;
		for( edge2 = edge + 1 ; edge2 <= numEdges ; edge2++ ) {
		    if( g2 == 0 ) {
			if( edgeArray[edge2].group1 == ue_grp ) {
			    g2 = edgeArray[edge2].group2 ;
			    if( groupArray[g2].flag < 0 ) {
				g2 = 0 ;
			    }
			    continue ;
			}
		    }
		    if( g1 == 0 ) {
			if( edgeArray[edge2].group2 == ue_grp ) {
			    g1 = edgeArray[edge2].group1 ;
			    if( groupArray[g1].flag < 0 ) {
				g1 = 0 ;
			    }
			}
		    }
		}
		if( g1 != 0 && g2 != 0 ) {
		    addEdge( g1, g2 ) ;
		    added_an_edge = YES ;
		}
	    }
	}
	if( added_an_edge == YES ) {
	    for( edge1 = edge + 1 ; edge1 <= numEdges ; edge1++ ) {
		a1 = edgeArray[edge1].group1 ;
		a2 = edgeArray[edge1].group2 ;
		if( groupArray[a1].block != groupArray[a2].block ) {
		    continue ;
		}
		for( edge2 = edge1 + 1 ; edge2 <= numEdges ; edge2++ ) {
		    b1 = edgeArray[edge2].group1 ;
		    b2 = edgeArray[edge2].group2 ;
		    if( groupArray[b1].block != groupArray[b2].block ) {
			continue ;
		    }
		    if( (groupArray[a1].unequiv == 1 &&
					groupArray[b1].unequiv == 1 &&
			    groupArray[a1].extint ==
					groupArray[b1].extint  &&
			    groupArray[a2].extint ==
					groupArray[b2].extint) ||
			(groupArray[a2].unequiv == 1 &&
					groupArray[b2].unequiv == 1 &&
			    groupArray[a2].extint ==
					groupArray[b2].extint  &&
			    groupArray[a1].extint ==
					groupArray[b1].extint)  ) {
			ya = (groupArray[a1].aveY +
						groupArray[a2].aveY) / 2 ;
			yb = (groupArray[b1].aveY +
						groupArray[b2].aveY) / 2 ;
			if( groupArray[a1].block == top_row ) {
			    if( ya < yb ) {
				if( edgeArray[edge2].cost <=
					    edgeArray[edge1].cost ) {
				    edgeArray[edge2].cost =
					    edgeArray[edge1].cost + 1;
				}
			    } else {
				if( edgeArray[edge2].cost >=
					    edgeArray[edge1].cost ) {
				    edgeArray[edge2].cost =
						edgeArray[edge1].cost - 1;
				}
			    }
			} else {
			    if( ya < yb ) {
				if( edgeArray[edge2].cost >=
					    edgeArray[edge1].cost ) {
				    edgeArray[edge2].cost =
						edgeArray[edge1].cost - 1;
				}
			    } else {
				if( edgeArray[edge2].cost <=
					    edgeArray[edge1].cost ) {
				    edgeArray[edge2].cost =
						edgeArray[edge1].cost + 1;
				}
			    }
			}
			break ;
		    }
		}
	    }
	    qsorte( (char *) (edgeArray + 1 + edge) , numEdges - edge ,
					   sizeof( edgeBox ) ) ;
	}
}
for( group = 1 ; group <= numGroups ; group++ ) {
	if( groupArray[group].flag < 0 ) {
	    continue ;
	}
	if( groupArray[group].unequiv != 1 ) {
	    continue ;
	}
	ei = groupArray[group].extint ;
	for( group2 = group + 1 ; group2 <= numGroups ; group2++ ) {
	    if( groupArray[group2].extint == ei ) {
		if( groupArray[group2].flag >= 0 ) {
		    groupArray[group2].flag = -1 ;
		}
		break ;
	    }
	}
}
done = NO ;
while( done == NO ) {
	done = YES ;
	for( edge = 1 ; edge <= numEdges ; edge++ ) {
	    if( edgeArray[edge].marked == YES && edgeArray[edge].poison == NO){
		g1 = edgeArray[edge].group1 ;
		g2 = edgeArray[edge].group2 ;
		unequiv1 = groupArray[g1].unequiv ;
		if( unequiv1 == NO ) {
		    if( groupArray[g1].numPins == 1 &&
				groupArray[g1].pinArray[1].top != 0 ) {
			single_pin1 = YES ;
			unequiv1 = YES ;
		    }
		}
		unequiv2 = groupArray[g2].unequiv ;
		if( unequiv2 == NO ) {
		    if( groupArray[g2].numPins == 1 &&
				groupArray[g2].pinArray[1].top != 0 ) {
			single_pin2 = YES ;
			unequiv2 = YES ;
		    }
		}
		if( (groupArray[g1].poison == YES) ||
					(groupArray[g2].poison == YES) ){
		    done = NO ;
		    edgeArray[edge].poison = YES ;
		    if( unequiv1 == YES ) {
			groupArray[g1].poison = YES ;
		    }
		    if( unequiv2 == YES ) {
			groupArray[g2].poison = YES ;
		    }
		} else if( groupArray[g1].block != groupArray[g2].block ) {
		    done = NO ;
		    edgeArray[edge].poison = YES ;
		    if( unequiv1 == YES ) {
			groupArray[g1].poison = YES ;
		    }
		    if( unequiv2 == YES ) {
			groupArray[g2].poison = YES ;
		    }
		} else if( single_pin1 == YES || single_pin2 == YES ) {
		    done = NO ;
		    edgeArray[edge].poison = YES ;
		    if( unequiv1 == YES ) {
			groupArray[g1].poison = YES ;
		    }
		    if( unequiv2 == YES ) {
			groupArray[g2].poison = YES ;
		    }
		}
	    }
	}
}
for( edge = 1 ; edge <= numEdges ; edge++ ) {
	if( edgeArray[edge].marked == YES && edgeArray[edge].poison == NO){
		
	    g1 = edgeArray[edge].group1 ;
	    g2 = edgeArray[edge].group2 ;
	    if( groupArray[g1].unequiv == NO &&
					groupArray[g2].unequiv == NO ) {
		edgeArray[edge].poison = YES ;
	    }
	    if( groupArray[g1].unequiv == NO ) {
		groupArray[g1].poison = YES ;
	    }
	    if( groupArray[g2].unequiv == NO ) {
		groupArray[g2].poison = YES ;
	    }
	}
}
for( edge = 1 ; edge <= numEdges ; edge++ ) {
	if( edgeArray[edge].marked == YES && edgeArray[edge].poison == NO){
		
	    g1 = edgeArray[edge].group1 ;
	    g2 = edgeArray[edge].group2 ;
	    if( groupArray[g1].edge1 == 0 ) {
		groupArray[g1].edge1 = edge ;
	    } else {
		groupArray[g1].edge2 = edge ;
	    }
	    if( groupArray[g2].edge1 == 0 ) {
		groupArray[g2].edge1 = edge ;
	    } else {
		groupArray[g2].edge2 = edge ;
	    }
	    if( groupArray[g1].poison == NO ) {
		ei = groupArray[g1].extint ;
		for( group = 1 ; ; group++ ) {
		    if( (group == g1) || (groupArray[group].extint != ei) ) {
			continue ;
		    }
		    break ;
		}
		groupArray[g1].numPins = 2 ;
		groupArray[g1].pinArray[2].xloc = groupArray[group].pinArray[1].xloc ;
		groupArray[g1].pinArray[2].yloc = groupArray[group].pinArray[1].yloc ;
		groupArray[g1].pinArray[2].top = groupArray[group].pinArray[1].top ;
		groupArray[g1].pinArray[2].pin = groupArray[group].pinArray[1].pin ;
	    }
	    if( groupArray[g2].poison == NO ) {
		ei = groupArray[g2].extint ;
		for( group = 1 ; ; group++ ) {
		    if( (group == g2) || (groupArray[group].extint != ei) ) {
			continue ;
		    }
		    break ;
		}
		groupArray[g2].numPins = 2 ;
		groupArray[g2].pinArray[2].xloc = groupArray[group].pinArray[1].xloc ;
		groupArray[g2].pinArray[2].yloc = groupArray[group].pinArray[1].yloc ;
		groupArray[g2].pinArray[2].top = groupArray[group].pinArray[1].top ;
		groupArray[g2].pinArray[2].pin = groupArray[group].pinArray[1].pin ;
	    }
	}
}
for( edge = 1 ; edge <= numEdges ; edge++ ) {
	if( edgeArray[edge].marked == YES && edgeArray[edge].poison == NO ) {
		
	    g1 = edgeArray[edge].group1 ;
	    g2 = edgeArray[edge].group2 ;
	    if( groupArray[g1].edge2 == 0 && groupArray[g2].edge2 == 0 ) {
		edgeArray[edge].poison = YES ;
	    }
	}
}
uclosepns(net) ;
for( i = 1 ; i <= numGroups ; i++ ) {
	groupArray[i].numPins = 0 ;
	groupArray[i].flag    = 0 ;
	groupArray[i].poison  = 0 ;
	groupArray[i].unequiv = 0 ;
	groupArray[i].extint  = 0 ;
	groupArray[i].edge1   = 0 ;
	groupArray[i].edge2   = 0 ;
	groupArray[i].check   = 0 ;
}
for( i = 1 ; i <= numEdges ; i++ ) {
	edgeArray[i].marked = 0 ;
	edgeArray[i].done   = 0 ;
	edgeArray[i].poison = 0 ;
}
}
uglobrout() ;
return ;
}
/* 当前文件是D:\Read\uglobrout.c*/

#define YES 1
#define NO  0


uglobrout()
{
int attperseg ;
int attlimit , attempts , swSeg ;
int stoppoint , breakpoint ;
int found , channel ;
int x , x1 , x2 ;
SEGBOXPTR segptr ;
DENSITYPTR denptr ;
attperseg = 5 ;
unetseg() ;
attlimit = attperseg * numSwSegs ;
attempts = 0 ;
breakpoint = 0 ;
stoppoint = 1.5 * numSwSegs ;
while( attempts < attlimit ) {
for( ; ; ) {
	do {
	    swSeg = (int) ( (double) numSegs * ( (double) RAND /
					  (double) 0x7fffffff ) ) + 1 ;
	} while( swSeg == numSegs + 1 ) ;
	if( aNetSeg[swSeg].nflag == 1 ) {
	    if( aNetSeg[swSeg].nswYorN == 1 &&
			    aNetSeg[swSeg].nkey == 0 ) {
		break ;
	    }
	} else {
	    if( aNetSeg[swSeg].swYorN == 1 &&
			    aNetSeg[swSeg].key == 0 ) {
		break ;
	    }
	}
}
if( aNetSeg[swSeg].nflag == 0 ) {
	if( aNetSeg[swSeg].current == 0 ) {
	    segptr = aNetSeg[swSeg].top ;
	} else {
	    segptr = aNetSeg[swSeg].bot ;
	}
} else {
	if( aNetSeg[swSeg].ncurrent == 0 ) {
	    segptr = aNetSeg[swSeg].ntop ;
	} else {
	    segptr = aNetSeg[swSeg].nbot ;
	}
}
channel = segptr->channel ;
x1  = segptr->pin1ptr->netptr->xpos ;
x2  = segptr->pin2ptr->netptr->xpos ;
if( ( channel > gtopChan ) || ( channel < gbotChan ) ||
	    ( x2 < Left_bound ) || ( x1 > Rite_bound ) ) {
	attempts++ ;
	continue ;
}
found = NO ;
for( denptr = DboxHead[ channel ][ nmaxTrack[channel] ]->nnext ;
		    denptr != DENSENULL ; denptr = denptr->nnext ) {
	x = denptr->grdptr->netptr->xpos ;
	if( x1 <= x && x2 >= x ) {
	    found = YES ;
	    break ;
	}
}
if( !found ) {
	if( ++breakpoint > stoppoint ) {
	    break ;
	}
	attempts++ ;
	continue ;
}
if( purcost( swSeg ) ) {
	attempts++ ;
	breakpoint = 0 ;
} else {
	if( ++breakpoint > stoppoint ) {
	    break ;
	}
	attempts++ ;
}
}
return ;
}
/* 当前文件是D:\Read\ugpair.c*/






ugpair()
{
CBOXPTR acellptr, bcellptr ;
BBOXPTR ablckptr ;
DENSITYPTR denptr ;
int a , b , ablock , lowValue ;
int flips , attempts , segment ;
int axcenter, bnxcenter, anxcenter ;
int aleft , aright , aorient ;
int startx1, endx1 ;
int cellleft, cellrite ;
int x ;
int leftEdge, riteEdge ;
int aptr , chan1 , chan2 , found ;
int breakpoint , stoppoint ;
double r ;
lowValue = tracks ;
Shuffle = ( CHANGRDPTR * )safe_malloc( 251 * sizeof( CHANGRDPTR ) ) ;
for( segment = 1 ; segment <= numSegs ; segment++ ) {
fixnetseg[segment] = aNetSeg[segment].current ;
}
flips = 0 ;
attempts = 0 ;
breakpoint = 0 ;
stoppoint = moveable_cells * stopdeg ;
while( breakpoint < stoppoint ) {
do {
	ablock = (int) ( (double) numblock * ( (double) RAND /
		      (double) 0x7fffffff ) ) + 1 ;
} while( ablock == numblock + 1 ) ;
if( pairArray[ablock][0] <= 1 ) {
	continue ;
}
chan1 = blkToRow[ablock] + 1 ;
chan2 = blkToRow[ablock] ;
for( found = 0 ; found == 0 ; ) {
	do {
	    aptr = (int) ( (double) pairArray[ablock][0] *
			( (double) RAND / (double) 0x7fffffff ) ) + 1 ;
	} while( aptr == pairArray[ablock][0] + 1 ) ;
	
	a = pairArray[ablock][aptr] ;
	acellptr = carray[a] ;
	aorient = acellptr->corient ;
	axcenter = acellptr->cxcenter ;
	aleft = acellptr->tileptr->left ;
	aright = acellptr->tileptr->right ;
	startx1 = axcenter + aleft ;
	endx1   = axcenter + aright ;
	for( denptr = DboxHead[ chan1 ][ maxTrack[chan1] ]->next ;
		   denptr != DENSENULL ; denptr = denptr->next ) {
	    x = denptr->grdptr->netptr->newx ;
	    if( startx1 <= x && endx1 >= x ) {
		found = 1 ;
		break ;
	    }
	}
	if( found == 0 ) {
	    for( denptr = DboxHead[ chan2 ][ maxTrack[chan2] ]->next
		    ; denptr != DENSENULL ; denptr = denptr->next ) {
		x = denptr->grdptr->netptr->newx ;
		if( startx1 <= x && endx1 >= x ) {
		    found = 1 ;
		    break ;
		}
	    }
	}
}
ablckptr = barray[ ablock ] ;
if( aptr > 1 ) {
	cellleft = pairArray[ablock][aptr - 1] ;
} else {
	cellleft = 0 ;
}
if( aptr < pairArray[ablock][0] ) {
	cellrite = pairArray[ablock][aptr + 1] ;
} else {
	cellrite = 0 ;
}
if( cellleft != 0 && cellrite != 0 &&
			carray[cellleft]->cclass != -1 &&
			acellptr->cclass != -1 &&
			carray[cellrite]->cclass != -1 ) {
	r = (double) RAND / (double) 0x7fffffff ;
	if( r >= 0.5 ) {
	
	    b = cellleft ;
	    bcellptr = carray[b] ;
	    leftEdge = bcellptr->cxcenter + bcellptr->tileptr->left ;
	    anxcenter = leftEdge - aleft ;
	    bnxcenter = endx1 - bcellptr->tileptr->right ;
	    if( ucgxp( a, b, anxcenter, bnxcenter ) ) {
		flips++ ;
		attempts++ ;
		if( attempts % 50 == 0 ) {
		    fprintf(fpo,"current iteration:%d\n",
						attempts ) ;
		    fflush(fpo);
		}
		if( attempts % 150 == 0 ) {
		    savewolf(3) ;
		}
		if( tracks < lowValue ) {
		    lowValue = tracks ;
		    fprintf(fpo,"Routing tracks reduced ");
		    fprintf(fpo,"to: %d  on iteration:%d\n",
					tracks, attempts ) ;	
		    fflush(fpo);
		} else {
		    breakpoint++ ;
		}
		if( !uneven_cell_height ) {
		    pairArray[ablock][aptr] = b ;
		    pairArray[ablock][aptr - 1] = a ;
		}
	    } else {
		breakpoint++ ;
		attempts++ ;
		if( attempts % 50 == 0 ) {
		    fprintf(fpo,"current iteration:%d\n",
						attempts ) ;
		    fflush(fpo);
		}
		if( attempts % 150 == 0 ) {
		    savewolf(3) ;
		}
		b = cellrite ;
		bcellptr = carray[b] ;
		riteEdge = bcellptr->cxcenter
			    + bcellptr->tileptr->right ;
		anxcenter = riteEdge - aright ;
		bnxcenter = startx1 - bcellptr->tileptr->left ;
		if( ucgxp( a, b, anxcenter, bnxcenter ) ) {
		    flips++ ;
		    if( tracks < lowValue ) {
			lowValue = tracks ;
			fprintf(fpo,"Routing tracks reduced ");
			fprintf(fpo,"to: %d  on iteration:%d\n",
					tracks , (attempts +1) );
			fflush(fpo);
		    } else {
			breakpoint++ ;
		    }
		    if( !uneven_cell_height ) {
			pairArray[ablock][aptr] = b ;
			pairArray[ablock][aptr + 1] = a ;
		    }
		} else {
		    breakpoint++ ;
		}
		attempts++ ;
		if( attempts % 50 == 0 ) {
		    fprintf(fpo,"current iteration:%d\n",
						attempts ) ;
		    fflush(fpo);
		}
		if( attempts % 150 == 0 ) {
		    savewolf(3) ;
		}
	    }
	} else {
	    b = cellrite ;
	    bcellptr = carray[b] ;
	    riteEdge = bcellptr->cxcenter + bcellptr->tileptr->right ;
	    anxcenter = riteEdge - aright ;
	    bnxcenter = startx1 - bcellptr->tileptr->left ;
	    if( ucgxp( a, b, anxcenter, bnxcenter ) ) {
		flips++ ;
		attempts++ ;
		if( attempts % 50 == 0 ) {
		    fprintf(fpo,"current iteration:%d\n",
						attempts ) ;
		    fflush(fpo);
		}
		if( attempts % 150 == 0 ) {
		    savewolf(3) ;
		}
		if( tracks < lowValue ) {
		    lowValue = tracks ;
		    fprintf(fpo,"Routing tracks reduced ");
		    fprintf(fpo,"to: %d  on iteration:%d\n",
					    tracks, attempts );
		    fflush(fpo);
		} else {
		    breakpoint++ ;
		}
		if( !uneven_cell_height ) {
		    pairArray[ablock][aptr] = b ;
		    pairArray[ablock][aptr + 1] = a ;
		}
	    } else {
		attempts++ ;
		if( attempts % 50 == 0 ) {
		    fprintf(fpo,"current iteration:%d\n",
						attempts ) ;
		    fflush(fpo);
		}
		if( attempts % 150 == 0 ) {
		    savewolf(3) ;
		}
		breakpoint++ ;
		b = cellleft ;
		bcellptr = carray[b] ;
		leftEdge = bcellptr->cxcenter + bcellptr->tileptr->left;
		anxcenter = leftEdge - aleft ;
		bnxcenter = endx1 - bcellptr->tileptr->right ;
		if( ucgxp( a, b, anxcenter, bnxcenter ) ) {
		    flips++ ;
		    if( tracks < lowValue ) {
			lowValue = tracks ;
			fprintf(fpo,"Routing tracks reduced ");
			fprintf(fpo,"to: %d  on iteration:%d\n",
					tracks, (attempts + 1) );
			fflush(fpo);
		    } else {
			breakpoint++ ;
		    }
		    if( !uneven_cell_height ) {
			pairArray[ablock][aptr] = b ;
			pairArray[ablock][aptr - 1] = a ;
		    }
		} else {
		    breakpoint++ ;
		}
		attempts++ ;
		if( attempts % 50 == 0 ) {
		    fprintf(fpo,"current iteration:%d\n",
						attempts ) ;
		    fflush(fpo);
		}
		if( attempts % 150 == 0 ) {
		    savewolf(3) ;
		}
	    }
	}
} else {
	if( cellleft != 0 &&
		    carray[cellleft]->cclass != -1 &&
		    acellptr->cclass != -1 ) {
	    b = cellleft ;
	    bcellptr = carray[b] ;
	    leftEdge = bcellptr->cxcenter + bcellptr->tileptr->left ;
	    anxcenter = leftEdge - aleft ;
	    bnxcenter = endx1 - bcellptr->tileptr->right ;
	    if( ucgxp( a, b, anxcenter, bnxcenter ) ) {
		flips++ ;
		if( tracks < lowValue ) {
		    lowValue = tracks ;
		    fprintf(fpo,"Routing tracks reduced ");
		    fprintf(fpo,"to: %d  on iteration:%d\n",
					    tracks, (attempts + 1) );
		    fflush(fpo);
		} else {
		    breakpoint++ ;
		}
		if( !uneven_cell_height ) {
		    pairArray[ablock][aptr] = b ;
		    pairArray[ablock][aptr - 1] = a ;
		}
	    } else {
		breakpoint++ ;
	    }
	    attempts++ ;
	    if( attempts % 50 == 0 ) {
		fprintf(fpo,"current iteration:%d\n",
					    attempts ) ;
		fflush(fpo);
	    }
	    if( attempts % 150 == 0 ) {
		savewolf(3) ;
	    }
	} else if( cellrite != 0 &&
		    carray[cellrite]->cclass != -1 &&
		    acellptr->cclass != -1 ) {
	    b = cellrite ;
	    bcellptr = carray[b] ;
	    riteEdge = bcellptr->cxcenter + bcellptr->tileptr->right ;
	    anxcenter = riteEdge - aright ;
	    bnxcenter = startx1 - bcellptr->tileptr->left ;
	    if( ucgxp( a, b, anxcenter, bnxcenter ) ) {
		flips++ ;
		if( tracks < lowValue ) {
		    lowValue = tracks ;
		    fprintf(fpo,"Routing tracks reduced ");
		    fprintf(fpo,"to: %d  on iteration:%d\n",
					    tracks, (attempts +1) );
		    fflush(fpo);
		} else {
		    breakpoint++ ;
		}
		if( !uneven_cell_height ) {
		    pairArray[ablock][aptr] = b ;
		    pairArray[ablock][aptr + 1] = a ;
		}
	    } else {
		breakpoint++ ;
	    }
	    attempts++ ;
	    if( attempts % 50 == 0 ) {
		fprintf(fpo,"current iteration:%d\n",
					    attempts ) ;
		fflush(fpo);
	    }
	    if( attempts % 150 == 0 ) {
		savewolf(3) ;
	    }
	}
}
switch( ablckptr->borient ) {
	case  1 :
	    if( acellptr->orflag != 0 ) {
		if( ucg0( a , (aorient == 0) ? 2 : 0 ) ) {
		    if( tracks < lowValue ) {
			lowValue = tracks ;
			fprintf(fpo,"Routing tracks reduced ");
			fprintf(fpo,"to: %d  on iteration:%d\n",
						    tracks, attempts );
			fprintf(fpo,"  ----by an orientation change\n");
			fflush(fpo);
		    }
		}
	    }
	    break ;
	case  2 :
	    if( acellptr->orflag != 0 ) {
		if( ucg0( a , (aorient == 1) ? 3 : 1 ) ) {
		    if( tracks < lowValue ) {
			lowValue = tracks ;
			fprintf(fpo,"Routing tracks reduced ");
			fprintf(fpo,"to: %d  on iteration:%d\n",
						    tracks, attempts );
			fprintf(fpo,"  ----by an orientation change\n");
			fflush(fpo);
		    }
		}
	    }
	    break ;
}
}
if( attempts != 0 ) {
fprintf( fpo, "    no. of accepted gflips: %d --->%d%s\n",
			    flips , (int)( 100.0 * (double)(flips) /
				    (double)(attempts) ) , "%" ) ;
fflush(fpo);
}
safe_free( Shuffle ) ;
return;
}

rowcon()
{
int C , RM , p_first , totalCells , cellsPerRow , temp_R ;
int over, under ;
double states , value , expect , variance ;
double expectedExtraRowLength , rowControl , x , minDev ;
totalCells = numcells ;
RM = numRows ;
cellsPerRow = totalCells / RM ;
temp_R = RM - RM / 3 ;
rowControl = 0.0 ;
do {
rowControl += 0.001 ;
C = (int)( rowControl * (double) totalCells / 2.0 ) ;
if( 2.0 * (double)(C+1) - rowControl * totalCells <=
		    rowControl * totalCells - 2.0 * (double) C ) {
	C++ ;
}
} while( 2 * C < temp_R ) ;
p_first = C / RM ;
if( p_first * RM < C ) {
p_first++ ;
}
RM -= RM / 3 ;
under = 0 ;
over  = 0 ;
for( ; ; ) {
value = expected_value( C , 0 , p_first , RM ) ;
states = combination( C+RM-1, C ) ;
expect = value / states ;
expectedExtraRowLength = 100.0 * expect / (double) cellsPerRow ;
value = expected_svalue( C , 0 , p_first , RM ) ;
variance = value / states - (expect * expect) ;
x = 100.0 * sqrt( variance ) / (double) cellsPerRow ;
minDev = 100.0 / (double) cellsPerRow ;
value = x+expectedExtraRowLength - minDev ;
if( value > 2.7 && value < 3.3 ) {
	break ;
} else if( value <= 2.7 ) {
	rowControl += 0.001 ;
	if( !over ) {
	    under = 1 ;
	} else {
	    break ;
	}
} else if( value >= 3.3 ) {
	if( !under ) {
	    rowControl -= 0.001 ;
	    over = 1 ;
	} else {
	    break ;
	}
}
C = (int)( rowControl * (double) totalCells / 2.0 ) ;
if( 2.0 * (double)(C+1) - rowControl * totalCells <=
		    rowControl * totalCells - 2.0 * (double) C ) {
	C++ ;
}
p_first = C / RM ;
if( p_first * RM < C ) {
	p_first++ ;
}
}
initialRowControl =  5.5 * rowControl ;
finalRowControl   =  rowControl ;
return ;
}
double partition( C_initial , k_initial , p_initial , R_initial )
int C_initial , k_initial , p_initial , R_initial ;
{
int RM , C , k , p , k_limit , p_limit ;
double states , equivs ;
states = 0.0 ;
RM = k_limit = R_initial - k_initial ;
C = C_initial - p_initial * k_initial ;
for( k = 1 ; k <= k_limit ; k++ ) {
equivs = combination( RM , k ) ;
p_limit = C / k ;
for( p = p_initial ; p <= p_limit ; p++ ) {
	if( C - (p-1)*RM > k ) { ;
	    continue ;
	}
	states += equivs * (compute_and_combination( C , k , p , RM ) -
					partition( C , k , p , RM ) ) ;
	continue ;
}
}
return( states ) ;
}
double expected_value( C_initial , k_initial , p_initial , R_initial )
int C_initial , k_initial , p_initial , R_initial ;
{
int RM , C , k , p , k_limit , p_limit ;
double value , equivs ;
value = 0.0 ;
RM = k_limit = R_initial - k_initial ;
C = C_initial - p_initial * k_initial ;
for( k = 1 ; k <= k_limit ; k++ ) {
equivs = combination( RM , k ) ;
p_limit = C / k ;
for( p = p_initial ; p <= p_limit ; p++ ) {
	if( C - (p-1)*RM > k ) { ;
	    continue ;
	}
	value += (double) p * equivs *
			(compute_and_combination( C , k , p , RM ) -
				    partition( C , k , p , RM ) ) ;
}
}
return( value ) ;
}
double expected_svalue( C_initial , k_initial , p_initial , R_initial )
int C_initial , k_initial , p_initial , R_initial ;
{
int RM , C , k , p , k_limit , p_limit ;
double value , equivs ;
value = 0.0 ;
RM = k_limit = R_initial - k_initial ;
C = C_initial - p_initial * k_initial ;
for( k = 1 ; k <= k_limit ; k++ ) {
equivs = combination( RM , k ) ;
p_limit = C / k ;
for( p = p_initial ; p <= p_limit ; p++ ) {
	if( C - (p-1)*RM > k ) { ;
	    continue ;
	}
	value += (double)(p * p) * equivs *
			(compute_and_combination( C , k , p , RM ) -
				    partition( C , k , p , RM ) ) ;
}
}
return( value ) ;
}
double compute_and_combination( C , k , p , RM )
int C , k , p , RM ;
{
int numerator , denom1 , denom2 , temp ;
double states ;
states = 1.0  ;
numerator = C - k*p + RM - k - 1 ;
denom1 = C - k*p ;
denom2 = RM - k - 1 ;
if( denom1 > denom2 ) {
temp = denom1 ;
denom1 = denom2 ;
denom2 = temp ;
}
for( ; numerator > denom2 ; numerator-- , denom1-- ) {
states *= (double) numerator ;
states /= (double) denom1 ;
}
return( states ) ;
}
double combination( numerator , denominator )
int numerator , denominator ;
{
double states ;
int temp , denom1 , denom2 ;
states = 1.0  ;
denom1 = denominator ;
denom2 = numerator - denominator ;
if( denom1 > denom2 ) {
temp = denom1 ;
denom1 = denom2 ;
denom2 = temp ;
}
for( ; numerator > denom2 ; numerator-- , denom1-- ) {
states *= (double) numerator ;
states /= (double) denom1 ;
}
return( states ) ;
}
/* 当前文件是D:\Read\uloop2.c*/

#define DELTA_B 1
#define PICK_INT(l,u) (((l)<(u)) ? ((RAND % ((u)-(l)+1))+(l)) : (l))


uloop2()
{
CBOXPTR acellptr, bcellptr ;
BBOXPTR ablckptr , bblckptr ;
int botblk , topblk ;
int flips ;
int axcenter , bxcenter , bycenter ;
int aorient , borient ;
int bleft , bright ;
int blk , pairflips ;
int i , r , l , t ;
int abin , bbin ;
int firstTry , fds ;
double temp , fp_ratio , percent_error ;
attempts  = 0 ;
flips     = 0 ;
pairflips = 0 ;
earlyRej  = 0 ;
P_limit = -1 ;
windx = minxspan ;
attmax = 2 * attprcel * numcells ;
binpenCon = 0.0 ;
fds = 0 ;
if( estimate_feeds ) {
fds = controlf( 1 ) ;
}
while( attempts < attmax ) {
a = PICK_INT( 1 , numcells ) ;
acellptr = carray[ a ]  ;
if( acellptr->cclass == -1 ) {
	continue ;
}
ablock   = acellptr->cblock ;
ablckptr = barray[ ablock ] ;
axcenter = acellptr->cxcenter ;
aorient = acellptr->corient ;
abin = SetBin( axcenter ) ;
cellaptr = binptr[ablock][abin]->cell ;
for( i = 1 ; i <= *cellaptr ; i++ ) {
	if( cellaptr[i] == a ) {
	     Apost = i ;
	     break ;
	}
}
bblock = 0 ;
firstTry = 0 ;
if( (botblk = ablock - DELTA_B) < 1) {
	botblk = 1 ;
}
if( (topblk = ablock + DELTA_B) > numblock ) {
	 topblk = numblock ;
}
for( i = 1 ; ; i++ ) {
	do {
	    blk = XPICK_INT( botblk , topblk , firstTry ) ;
	    bblckptr = barray[ blk ] ;
	} while( ablock == blk ||
			ablckptr->bclass != bblckptr->bclass ) ;
	
	bleft = bblckptr->bxcenter + bblckptr->bleft ;
	bright = bblckptr->bxcenter + bblckptr->bright ;
	l = (bleft >= axcenter - windx) ? bleft : (axcenter-windx);
	r = (bright <= axcenter + windx) ? bright : (axcenter+windx);
	if( l > r ) {
	    if( i == 1 ) {
		firstTry = blk ;
		continue ;
	    } else if( i == 3 ) {
		if( r < bleft ) {
		    l = r = bleft ;
		} else {
		    l = r = bright ;
		}
	    } else {
		firstTry = - ablock ;
		continue ;
	    }
	}
	bblock = blk ;
	bycenter = bblckptr->bycenter ;
	if( bblock == ablock ) {
	    bxcenter = XPICK_INT( l, r, axcenter ) ;
	} else {
	    bxcenter = XPICK_INT( l, r, 0 ) ;
	}
	break ;
}
bbin = SetBin( bxcenter ) ;
cellbptr = binptr[bblock][bbin]->cell ;
if( *cellbptr == 0 ) {
	if( ablckptr->borient == 1 ) {
	    if( bblckptr->borient == 1 ) {
		if( ucxx1( bxcenter, bycenter)){
		    flips++ ;
		}
	    } else {
		if( ucxxo1( bxcenter,bycenter,(aorient == 0) ? 1 : 3 )){
		    flips++ ;
		}
	    }
	} else {  	
	    if( bblckptr->borient == 1 ) {
		if( ucxxo1( bxcenter, bycenter,
			    (aorient == 1) ? 0 : 2)){
		    flips++ ;
		}
	    } else {
		if( ucxx1( bxcenter, bycenter) ){
		    flips++ ;
		}
	    }
	}
} else {
	Bpost = PICK_INT( 1 , *cellbptr ) ;
	b = cellbptr[ Bpost ] ;
	bcellptr  = carray[b] ;
	bblock    = bcellptr->cblock   ;
	bblckptr = barray[ bblock ] ;
	if( bcellptr->cclass == -1 || a == b ) {
	    continue ;
	}
	
	borient   = bcellptr->corient  ;
	if( ablckptr->borient == 1 ) {
	    if( bblckptr->borient == 1 ) {
		t = ucxx2( ) ;
		if( t == 1 ) {
		    pairflips++ ;
		}
	    } else {
		t = ucxxo2( (aorient == 0) ? 1:3, (borient == 1)
							 ? 0:2 ) ;
		if( t == 1 ) {
		    pairflips++ ;
		}
	    }
	} else {
	    if( bblckptr->borient == 1 ) {
		t = ucxxo2( (aorient == 1) ? 0:2, (borient == 0)
							    ? 1:3) ;
		if( t == 1 ) {
		    pairflips++ ;
		}
	    } else {
		t = ucxx2( ) ;
		if( t == 1 ) {
		    pairflips++ ;
		}
	    }
	}
}
attempts++ ;
}
temp = 100.0 * (double)(pairflips + flips) / (double)(attmax) ;
if( pairflips > 0.0001 ) {
fp_ratio = 100.0 * (double)flips/(double)pairflips ;
} else {
fp_ratio = 100.0 ;
}
fprintf(fpo,"%3d %3d %4d %8d %7d %5d 0.0 %4.1f %4.1f %4.1f %4.1f",
	iteration+1, (int)T, fds , funccost, penalty, P_limit,
	binpenCon, roLenCon, temp, fp_ratio);
fprintf(fpo," %4.1f\n", 100.0*(double)earlyRej/(double)attmax );
fflush( fpo ) ;
return ;
}
/* 当前文件是D:\Read\unetseg.c*/

unetseg()
{
SEGBOXPTR segptr ;
CHANGRDPTR ptr1 , ptr2 , bptr , fptr , sptr , eptr , ptr , gdptr ;
CHANGRDPTR tryptr[500] ;
DENSITYPTR denptr , headptr ;
NBOXPTR netptr ;
int pin1 , pin2 , x1 , x2 , x , i ;
int channel , chan , up_channel , segment , Flag , changes ;
int index , b , e , net , track , dtrack ;
int Ucount , Lcount ;
int j , t , tryFlag[500] , trynet , pinloc , self_reset ;
gtopChan = 1 ;
gbotChan = numChans ;
tracks = 0 ;
for( index = 1 ; index <= netchgs[0] ; index++ ) {
net = netchgs[index] ;
b = anet[net] ;
e = anet[net + 1] - 1 ;
for( segment = b ; segment <= e ; segment++ ) {
	if( aNetSeg[segment].current == 0 ) {
	    segptr = aNetSeg[segment].top ;
	} else {
	    segptr = aNetSeg[segment].bot ;
	}
	pin1 = segptr->pin1 ;
	pin2 = segptr->pin2 ;
	if( pin1 > maxterm && pin2 > maxterm ) {
	    continue ;
	}
	ptr1 = segptr->pin1ptr ;
	ptr2 = segptr->pin2ptr ;
	x1 = ptr1->netptr->newx ;
	x2 = ptr2->netptr->newx ;
	if( x1 == x2 ) {
	    continue ;
	}
	channel = segptr->channel ;
	if( channel > gtopChan ) {
	    gtopChan = channel ;
	}
	if( channel < gbotChan ) {
	    gbotChan = channel ;
	}
	net = aNetSeg[segment].net ;
	if( ptr1->nSegType > 0 ) {
	    Flag = 0 ;
	    bptr = ptr1 ;
	    while( bptr->prevgrd != GRDNULL
			&& bptr->prevgrd->netptr->newx == x1 ) {
		if( net == tearray[bptr->prevgrd->netptr->terminal]->net
				   && bptr->prevgrd->nSegType < 0 ){
		    Flag = 1 ;
		    sptr = ptr1->nextgrd ;
		    while( sptr->netptr->newx == x1 ) {
			sptr = sptr->nextgrd ;
		    }
		    break ;
		} else {
		    bptr = bptr->prevgrd ;
		}
	    }
	    if( !Flag ) {
		sptr = ptr1->nextgrd ;
		while( sptr->netptr->newx == x1 ) {
		    if( net == tearray[sptr->netptr->terminal]->net
					&& sptr->nSegType < 0 ) {
			Flag = 1 ;
		    }
		    sptr = sptr->nextgrd ;
		}
	    }
	    if( !Flag ) {
		sptr = bptr ;
	    }
	} else {
	    if( x1 != gxstart ) {
		sptr = ptr1->nextgrd ;
		while( sptr->netptr->newx == x1 ) {
		    sptr = sptr->nextgrd ;
		}
	    } else {
		sptr = ptr1 ;
	    }
	}
	if( ptr2->nSegType < 0 ) {
	    Flag = 0 ;
	    fptr = ptr2 ;
	    while( fptr->nextgrd != GRDNULL
			&& fptr->nextgrd->netptr->newx == x2 ) {
		if( net == tearray[fptr->nextgrd->netptr->terminal]->net
				   && fptr->nextgrd->nSegType > 0 ){
		    Flag = 1 ;
		    eptr = ptr2->prevgrd ;
		    while( eptr->netptr->newx == x2 ) {
			eptr = eptr->prevgrd ;
		    }
		    break ;
		} else {
		    fptr = fptr->nextgrd ;
		}
	    }
	    if( !Flag ) {
		eptr = ptr2->prevgrd ;
		while( eptr->netptr->newx == x2 ) {
		    if( net == tearray[eptr->netptr->terminal]->net
					&& eptr->nSegType > 0 ) {
			Flag = 1 ;
		    }
		    eptr = eptr->prevgrd ;
		}
	    }
	    if( !Flag ) {
		eptr = fptr ;
	    }
	} else {
	    if( x2 != gxstop ) {
		eptr = ptr2->prevgrd ;
		while( eptr->netptr->newx == x2 ) {
		    eptr = eptr->prevgrd ;
		}
	    } else {
		eptr = ptr2 ;
	    }
	}
	eptr = eptr->nextgrd ;
	if( pin1 <= maxterm ) {
	    ptr1->nSegType -= RIGHT ;
	}
	if( pin2 <= maxterm ) {
	    ptr2->nSegType -= LEFT  ;
	}
	for( ptr = sptr ; ptr != eptr ; ptr = ptr->nextgrd ) {
	    denptr = ptr->dptr ;
	    if( denptr->nnext != DENSENULL ) {
		denptr->nnext->nback = denptr->nback ;
	    }
	    denptr->nback->nnext = denptr->nnext ;
	    track = --(ptr->ntracks) ;
	    headptr = DboxHead[ channel ][ track ]->nnext ;
	    if( headptr != DENSENULL ) {
		DboxHead[ channel ][ track ]->nnext = denptr ;
		denptr->nnext  = headptr ;
		headptr->nback = denptr  ;
		denptr->nback  = DboxHead[ channel ][ track ] ;
	    } else {
		DboxHead[ channel ][ track ]->nnext = denptr ;
		denptr->nnext = DENSENULL ;
		denptr->nback = DboxHead[ channel ][ track ];
	    }
	}
}
}
Ucount = Lcount = 0 ;
if( ULgrdptr != GRDNULL ) {
if( ULgrdptr->netptr->pinloc == 0 ) {
	gdptr = ULgrdptr->nnextgrd ;
	while( gdptr->netptr->pinloc == 0 ) {
	    gdptr = gdptr->nnextgrd ;
	}
	if( (int) gdptr->netptr->pinloc == -1 ) {
	    channel = gdptr->netptr->row ;
	} else {
	    channel = gdptr->netptr->row + 1 ;
	}
} else {
	if( (int) ULgrdptr->netptr->pinloc == -1 ) {
	    channel = ULgrdptr->netptr->row ;
	} else {
	    channel = ULgrdptr->netptr->row + 1 ;
	}
}
} else {
if( LLgrdptr->netptr->pinloc == 0 ) {
	gdptr = LLgrdptr->nnextgrd ;
	while( gdptr->netptr->pinloc == 0 ) {
	    gdptr = gdptr->nnextgrd ;
	}
	if( (int) gdptr->netptr->pinloc == -1 ) {
	    channel = gdptr->netptr->row ;
	} else {
	    channel = gdptr->netptr->row + 1 ;
	}
} else {
	if( (int) LLgrdptr->netptr->pinloc == -1 ) {
	    channel = LLgrdptr->netptr->row ;
	} else {
	    channel = LLgrdptr->netptr->row + 1 ;
	}
}
channel++ ;
}
up_channel = channel ;
if( ULgrdptr != GRDNULL ) {
for( gdptr = ULgrdptr->nextgrd ; gdptr != URgrdptr ;
				    gdptr = gdptr->nextgrd ) {
	Shuffle[ Ucount++ ] = gdptr ;
}
qsortgdx( (char *)Shuffle , Ucount , sizeof( CHANGRDPTR ) ) ;
ULgrdptr->nnextgrd = Shuffle[ 0 ] ;
Shuffle[ 0 ]->nprevgrd = ULgrdptr ;
if( Ucount >= 2 ) {
	for( i = 0 ; i <= Ucount - 2 ; i++ ) {
	    Shuffle[ i ]->nnextgrd = Shuffle[ i+1 ] ;
	    Shuffle[ i+1 ]->nprevgrd = Shuffle[ i ] ;
	}
}
Shuffle[ Ucount-1 ]->nnextgrd = URgrdptr ;
URgrdptr->nprevgrd = Shuffle[ Ucount-1 ] ;
for( gdptr = ULgrdptr->nnextgrd ; gdptr != URgrdptr ;
				    gdptr = gdptr->nnextgrd ) {
	x = gdptr->netptr->xpos ;
	dtrack = 0 ;
	if( x != gdptr->netptr->newx ) {
	    denptr = gdptr->dptr ;
	    if( denptr->nnext != DENSENULL ) {
		denptr->nnext->nback = denptr->nback ;
	    }
	    denptr->nback->nnext = denptr->nnext ;
	    tryptr[0] = gdptr->nprevgrd ;
	    if( tryptr[0]->netptr->xpos != x ) {
		tryFlag[ t=0 ] = 0 ;
		while( tryptr[t]->nprevgrd != GRDNULL &&
		       tryptr[t]->nprevgrd->netptr->xpos ==
				    tryptr[0]->netptr->xpos ) {
		    t++ ;
		    tryptr[ t ] = tryptr[ t-1 ]->nprevgrd ;
		    tryFlag[ t ] = 0 ;
		}
		for( i = 0 ; i <= t ; i++ ) {
		    if( tryFlag[i] == 0 ) {
			changes = 0 ;
			trynet =
			    tearray[tryptr[i]->netptr->terminal]->net ;
			changes += tryptr[i]->nSegType ;
			for( j = i+1 ; j <= t ; j++ ) {
			    if( tearray[tryptr[j]->netptr->terminal]
						    ->net == trynet ) {
				tryFlag[j] = 1 ;
				changes += tryptr[j]->nSegType ;
			    }
			}
			if( changes < 0 ) {
			    dtrack += changes ;
			}
		    }
		}
		tryptr[0] = gdptr->nnextgrd ;
		if( tryptr[0]->netptr->xpos == x ) {
		    tryFlag[ t=0 ] = 0 ;
		    while( tryptr[t]->nnextgrd != GRDNULL &&
			   tryptr[t]->nnextgrd->netptr->xpos ==
					tryptr[0]->netptr->xpos ) {
			t++ ;
			tryptr[ t ] = tryptr[ t-1 ]->nnextgrd ;
			tryFlag[ t ] = 0 ;
		    }
		    for( i = 0 ; i <= t ; i++ ) {
			if( tryFlag[i] == 0 ) {
			    changes = 0 ;
			    trynet =
			      tearray[tryptr[i]->netptr->terminal]->net;
			    changes += tryptr[i]->nSegType ;
			    for( j = i+1 ; j <= t ; j++ ) {
				if( tearray[tryptr[j]->netptr->terminal]
						    ->net == trynet ) {
				    tryFlag[j] = 1 ;
				    changes += tryptr[j]->nSegType ;
				}
			    }
			    if( changes > 0 ) {
				dtrack += changes ;
			    }
			}
		    }
		}
	    }
			
	    gdptr->ntracks = gdptr->nprevgrd->ntracks + dtrack ;
	    track = gdptr->ntracks ;
	    headptr = DboxHead[ channel ][ track ]->nnext ;
	    if( headptr != DENSENULL ) {
		DboxHead[ channel ][ track ]->nnext = denptr ;
		denptr->nnext  = headptr ;
		headptr->nback = denptr  ;
		denptr->nback  = DboxHead[ channel ][ track ] ;
	    } else {
		DboxHead[ channel ][ track ]->nnext = denptr ;
		denptr->nnext = DENSENULL ;
		denptr->nback = DboxHead[ channel ][ track ];
	    }
	}
}
}
if( LLgrdptr != GRDNULL ) {
channel-- ;
for( gdptr = LLgrdptr->nextgrd ; gdptr != LRgrdptr ;
				    gdptr = gdptr->nextgrd ) {
	Shuffle[ Lcount++ ] = gdptr ;
}
qsortgdx( (char *)Shuffle , Lcount , sizeof( CHANGRDPTR ) ) ;
LLgrdptr->nnextgrd = Shuffle[ 0 ] ;
Shuffle[ 0 ]->nprevgrd = LLgrdptr ;
if( Lcount >= 2 ) {
	for( i = 0 ; i <= Lcount - 2 ; i++ ) {
	    Shuffle[ i ]->nnextgrd = Shuffle[ i+1 ] ;
	    Shuffle[ i+1 ]->nprevgrd = Shuffle[ i ] ;
	}
}
Shuffle[ Lcount-1 ]->nnextgrd = LRgrdptr ;
LRgrdptr->nprevgrd = Shuffle[ Lcount-1 ] ;
for( gdptr = LLgrdptr->nnextgrd ; gdptr != LRgrdptr ;
				    gdptr = gdptr->nnextgrd ) {
	x = gdptr->netptr->xpos ;
	dtrack = 0 ;
	if( x != gdptr->netptr->newx ) {
	    denptr = gdptr->dptr ;
	    if( denptr->nnext != DENSENULL ) {
		denptr->nnext->nback = denptr->nback ;
	    }
	    denptr->nback->nnext = denptr->nnext ;
	    tryptr[0] = gdptr->nprevgrd ;
	    if( tryptr[0]->netptr->xpos != x ) {
		tryFlag[ t=0 ] = 0 ;
		while( tryptr[t]->nprevgrd != GRDNULL &&
		       tryptr[t]->nprevgrd->netptr->xpos ==
				    tryptr[0]->netptr->xpos ) {
		    t++ ;
		    tryptr[ t ] = tryptr[ t-1 ]->nprevgrd ;
		    tryFlag[ t ] = 0 ;
		}
		for( i = 0 ; i <= t ; i++ ) {
		    if( tryFlag[i] == 0 ) {
			changes = 0 ;
			trynet =
			    tearray[tryptr[i]->netptr->terminal]->net ;
			changes += tryptr[i]->nSegType ;
			for( j = i+1 ; j <= t ; j++ ) {
			    if( tearray[tryptr[j]->netptr->terminal]
						    ->net == trynet ) {
				tryFlag[j] = 1 ;
				changes += tryptr[j]->nSegType ;
			    }
			}
			if( changes < 0 ) {
			    dtrack += changes ;
			}
		    }
		}
		tryptr[0] = gdptr->nnextgrd ;
		if( tryptr[0]->netptr->xpos == x ) {
		    tryFlag[ t=0 ] = 0 ;
		    while( tryptr[t]->nnextgrd != GRDNULL &&
			   tryptr[t]->nnextgrd->netptr->xpos ==
					tryptr[0]->netptr->xpos ) {
			t++ ;
			tryptr[ t ] = tryptr[ t-1 ]->nnextgrd ;
			tryFlag[ t ] = 0 ;
		    }
		    for( i = 0 ; i <= t ; i++ ) {
			if( tryFlag[i] == 0 ) {
			    changes = 0 ;
			    trynet =
			      tearray[tryptr[i]->netptr->terminal]->net;
			    changes += tryptr[i]->nSegType ;
			    for( j = i+1 ; j <= t ; j++ ) {
				if( tearray[tryptr[j]->netptr->terminal]
						    ->net == trynet ) {
				    tryFlag[j] = 1 ;
				    changes += tryptr[j]->nSegType ;
				}
			    }
			    if( changes > 0 ) {
				dtrack += changes ;
			    }
			}
		    }
		}
	    }
			
	    gdptr->ntracks = gdptr->nprevgrd->ntracks + dtrack ;
	    track = gdptr->ntracks ;
	    headptr = DboxHead[ channel ][ track ]->nnext ;
	    if( headptr != DENSENULL ) {
		DboxHead[ channel ][ track ]->nnext = denptr ;
		denptr->nnext  = headptr ;
		headptr->nback = denptr  ;
		denptr->nback  = DboxHead[ channel ][ track ] ;
	    } else {
		DboxHead[ channel ][ track ]->nnext = denptr ;
		denptr->nnext = DENSENULL ;
		denptr->nback = DboxHead[ channel ][ track ];
	    }
	}
}
}
if( uneven_cell_height ) {
if( ULgrdptr != GRDNULL ) {
	channel = up_channel ;
	for( gdptr = ULgrdptr ; gdptr != URgrdptr ;
				    gdptr = gdptr->nnextgrd ) {
	    netptr = gdptr->netptr ;
	    pinloc = netptr->pinloc ;
	    if( pinloc == 1 ) {
		self_reset = carray[ netptr->cell ]->tileptr->top ;
	    } else if( pinloc == -1 ) {
		self_reset = -carray[ netptr->cell ]->tileptr->bottom ;
	    } else {
		self_reset = 0 ;
	    }
	    gdptr->ntracks += ( self_reset + facing_cellheight(
			netptr->terminal , netptr->row , pinloc ,
					NEW ) ) / track_spacing ;
	    denptr = gdptr->dptr ;
	    if( denptr->nnext != DENSENULL ) {
		denptr->nnext->nback = denptr->nback ;
	    }
	    denptr->nback->nnext = denptr->nnext ;
	    track = gdptr->ntracks ;
	    headptr = DboxHead[ channel ][ track ]->nnext ;
	    if( headptr != DENSENULL ) {
		DboxHead[ channel ][ track ]->nnext = denptr ;
		denptr->nnext = headptr ;
		headptr->nback = denptr ;
		denptr->nback = DboxHead[ channel ][ track ] ;
	    } else {
		DboxHead[ channel ][ track ]->nnext = denptr ;
		denptr->nnext = DENSENULL ;
		denptr->nback = DboxHead[ channel ][ track ] ;
	    }
	}
}
if( LLgrdptr != GRDNULL ) {
	channel = up_channel - 1 ;
	for( gdptr = LLgrdptr ; gdptr != LRgrdptr ;
				    gdptr = gdptr->nnextgrd ) {
	    netptr = gdptr->netptr ;
	    pinloc = netptr->pinloc ;
	    if( pinloc == 1 ) {
		self_reset = carray[ netptr->cell ]->tileptr->top ;
	    } else if( pinloc == -1 ) {
		self_reset = -carray[ netptr->cell ]->tileptr->bottom ;
	    } else {
		self_reset = 0 ;
	    }
	    gdptr->ntracks += ( self_reset + facing_cellheight(
			netptr->terminal , netptr->row , pinloc ,
					NEW ) ) / track_spacing ;
	    denptr = gdptr->dptr ;
	    if( denptr->nnext != DENSENULL ) {
		denptr->nnext->nback = denptr->nback ;
	    }
	    denptr->nback->nnext = denptr->nnext ;
	    track = gdptr->ntracks ;
	    headptr = DboxHead[ channel ][ track ]->nnext ;
	    if( headptr != DENSENULL ) {
		DboxHead[ channel ][ track ]->nnext = denptr ;
		denptr->nnext = headptr ;
		headptr->nback = denptr ;
		denptr->nback = DboxHead[ channel ][ track ] ;
	    } else {
		DboxHead[ channel ][ track ]->nnext = denptr ;
		denptr->nnext = DENSENULL ;
		denptr->nback = DboxHead[ channel ][ track ] ;
	    }
	}
}
}
for( index = 1 ; index <= netchgs[0] ; index++ ) {
net = netchgs[index] ;
b = anet[net] ;
e = anet[net + 1] - 1 ;
for( segment = b ; segment <= e ; segment++ ) {
	if( aNetSeg[segment].ncurrent == 0 ) {
	    segptr = aNetSeg[segment].ntop ;
	} else {
	    segptr = aNetSeg[segment].nbot ;
	}
	pin1 = segptr->pin1 ;
	pin2 = segptr->pin2 ;
	if( pin1 > maxterm && pin2 > maxterm ) {
	    continue ;
	}
	ptr1 = segptr->pin1ptr ;
	ptr2 = segptr->pin2ptr ;
	x1 = ptr1->netptr->xpos ;
	x2 = ptr2->netptr->xpos ;
	if( x1 == x2 ) {
	    continue ;
	}
	channel = segptr->channel ;
	if( channel > gtopChan ) {
	    gtopChan = channel ;
	}
	if( channel < gbotChan ) {
	    gbotChan = channel ;
	}
	net = aNetSeg[segment].net ;
	if( ptr1->nSegType >= 0 ) {
	    Flag = 0 ;
	    bptr = ptr1 ;
	    while( bptr->nprevgrd != GRDNULL
			&& bptr->nprevgrd->netptr->xpos == x1 ) {
		if( tearray[bptr->nprevgrd->netptr->terminal]->net
			== net && bptr->nprevgrd->nSegType < 0 ){
		    Flag = 1 ;
		    sptr = ptr1->nnextgrd ;
		    while( sptr->netptr->xpos == x1 ) {
			sptr = sptr->nnextgrd ;
		    }
		    break ;
		} else {
		    bptr = bptr->nprevgrd ;
		}
	    }
	    if( !Flag ) {
		sptr = ptr1->nnextgrd ;
		while( sptr->netptr->xpos == x1 ) {
		    if( net == tearray[sptr->netptr->terminal]->net
					&& sptr->nSegType < 0 ) {
			Flag = 1 ;
		    }
		    sptr = sptr->nnextgrd ;
		}
	    }
	    if( !Flag ) {
		sptr = bptr ;
	    }
	} else {
	    sptr = ptr1->nnextgrd ;
	    while( sptr->netptr->xpos == x1 ) {
		sptr = sptr->nnextgrd ;
	    }
	}
	if( ptr2->nSegType <= 0 ) {
	    Flag = 0 ;
	    fptr = ptr2 ;
	    while( fptr->nnextgrd != GRDNULL
			&& fptr->nnextgrd->netptr->xpos == x2 ) {
		if( tearray[fptr->nnextgrd->netptr->terminal]->net
			== net && fptr->nnextgrd->nSegType > 0 ){
		    Flag = 1 ;
		    eptr = ptr2->nprevgrd ;
		    while( eptr->netptr->xpos == x2 ) {
			eptr = eptr->nprevgrd ;
		    }
		    break ;
		} else {
		    fptr = fptr->nnextgrd ;
		}
	    }
	    if( !Flag ) {
		eptr = ptr2->nprevgrd ;
		while( eptr->netptr->xpos == x2 ) {
		    if( net == tearray[eptr->netptr->terminal]->net
					&& eptr->nSegType > 0 ) {
			Flag = 1 ;
		    }
		    eptr = eptr->nprevgrd ;
		}
	    }
	    if( !Flag ) {
		eptr = fptr ;
	    }
	} else {
	    eptr = ptr2->nprevgrd ;
	    while( eptr->netptr->xpos == x2 ) {
		eptr = eptr->nprevgrd ;
	    }
	}
	eptr = eptr->nnextgrd ;
	if( pin1 <= maxterm ) {
	    ptr1->nSegType += RIGHT ;
	}
	if( pin2 <= maxterm ) {
	    ptr2->nSegType += LEFT  ;
	}
	for( ptr = sptr ; ptr != eptr ; ptr = ptr->nnextgrd ) {
	    denptr = ptr->dptr ;
	    if( denptr->nnext != DENSENULL ) {
		denptr->nnext->nback = denptr->nback ;
	    }
	    denptr->nback->nnext = denptr->nnext ;
	    track = ++(ptr->ntracks) ;
	    headptr = DboxHead[ channel ][ track ]->nnext ;
	    if( headptr != DENSENULL ) {
		DboxHead[ channel ][ track ]->nnext = denptr ;
		denptr->nnext  = headptr ;
		headptr->nback = denptr  ;
		denptr->nback  = DboxHead[ channel ][ track ] ;
	    } else {
		DboxHead[ channel ][ track ]->nnext = denptr ;
		denptr->nnext = DENSENULL ;
		denptr->nback = DboxHead[ channel ][ track ];
	    }
	}
}
}
for( chan = 1 ; chan <= numChans ; chan++ ) {
for( track = max_tdensity+30 ; track >= 0 ; track-- ) {
	if( DboxHead[ chan ][ track ]->nnext != DENSENULL ) {
	    break ;
	}
}
nmaxTrack[ chan ]  = track ;
tracks += track ;
}
return;
}
/* 当前文件是D:\Read\unlap.c*/

#define TRUE 1
#define FALSE 0
int first_time_in_unlap = 1 ;



int noPairs ;
unlap( flag )
int flag ;
{
CBOXPTR cellptr ;
int *num , i , cell_count , space ;
int cell , block ;
int cell_left , left_edge , right_edge ;
int fixed , unfixed ;
int *left_queue , *right_queue , *center_queue ;
int max_cell_in_blk ;
int min_right_fixed_cell ;
int max_left_fixed_cell ;
int pair_array_index , total_cells ;
num = (int *) safe_malloc( ( numblock + 1 ) * sizeof(int) ) ;
for( block = 0 ; block <= numblock ; block++ ) {
num[block] = 0 ;
}
if( flag == -2 ) {
total_cells = numcells + ffeeds ;
} else {
total_cells = numcells ;
}
for( cell = 1 ; cell <= total_cells ; cell++ ) {
num[ carray[ cell ]->cblock ]++ ;
}
if( ! first_time_in_unlap ) {
for( block = 1 ; block <= numblock ; block++ ) {
	safe_free( pairArray[ block ] ) ;
}
safe_free( pairArray ) ;
} else {
first_time_in_unlap = 0 ;
}
pairArray = (int **) safe_malloc( ( numblock + 1 ) *
						sizeof(int *) ) ;
max_cell_in_blk = 0 ;
for( block = 1 ; block <= numblock ; block++ ) {
pairArray[ block ] = (int *) safe_malloc( ( num[block] + 1 )
					    * sizeof( int ) ) ;
pairArray[block][0] = num[block] ;
if( num[block] > max_cell_in_blk ) {
	max_cell_in_blk = num[block] ;
}
}
left_queue = (int *) safe_malloc((max_cell_in_blk + 1) * sizeof(int));
right_queue = (int *) safe_malloc((max_cell_in_blk + 1) * sizeof(int));
center_queue = (int *) safe_malloc((max_cell_in_blk + 1) * sizeof(int));
for( cell = 1 ; cell <= total_cells ; cell++ ) {
block = carray[ cell ]->cblock ;
pairArray[block][ num[block]-- ] = cell ;
}
for( block = 1 ; block <= numblock ; block++ ) {
qsortx( (char *) ( pairArray[block] + 1 ) ,
		    pairArray[block][0] , sizeof( int ) ) ;
}
for( block = 1 ; block <= numblock ; block++ ) {
left_edge  = barray[block]->bxcenter + barray[block]->bleft ;
right_edge = barray[block]->bxcenter + barray[block]->bright ;
if( ( cell_count = pairArray[ block ][0] ) > 1 ) {
	noPairs = 0 ;
}
fixed   = FALSE ;
unfixed = FALSE ;
for( i = 1 ; i <= cell_count ; i++ ) {
	if( carray[pairArray[block][i]]->cclass == -1 ) {
	    fixed = TRUE ;
	} else {
	    unfixed = TRUE ;
	}
}
if( fixed == TRUE && unfixed == TRUE ) {
	for( i = 0 ; i <= max_cell_in_blk ; i++ ) {
	    left_queue[i]   = 0 ;
	    right_queue[i]  = 0 ;
	    center_queue[i] = 0 ;
	}
	max_left_fixed_cell = 0 ;
	for( i = 1 ; i <= cell_count ; i++ ) {
	    cellptr = carray[ pairArray[block][i] ] ;
	    if( cellptr->cclass == -1 ) {
		if( left_edge == cellptr->cxcenter +
		      cellptr->tileptr->left ) {
		    left_edge += cellptr->clength ;
		    left_queue[++(*left_queue)] = pairArray[block][i];
		    max_left_fixed_cell = i ;
		} else {
		    break ;
		}
	    }
	}
	min_right_fixed_cell = cell_count + 1 ;
	for( i = cell_count ; i >= 1 ; i-- ) {
	    cellptr = carray[ pairArray[block][i] ] ;
	    if( cellptr->cclass == -1 ) {
		if( right_edge == cellptr->cxcenter +
		      cellptr->tileptr->right ) {
		    right_edge -= cellptr->clength ;
		    right_queue[++(*right_queue)] = pairArray[block][i];
		    min_right_fixed_cell = i ;
		} else {
		    break ;
		}
	    }
	}
	for( i = 1 ; i <= cell_count ; i++ ) {
	    cellptr = carray[ pairArray[block][i] ] ;
	    if( (cellptr->cclass != -1) ||
		    (cellptr->cclass == -1 && i > max_left_fixed_cell &&
			i < min_right_fixed_cell)) {
		center_queue[++(*center_queue)] = pairArray[block][i];
	    }
	}
	pair_array_index = 0 ;
	for( i = 1 ; i <= *left_queue ; i++ ) {
	    pairArray[block][++pair_array_index] = left_queue[i] ;
	}
	for( i = 1 ; i <= *center_queue ; i++ ) {
	    pairArray[block][++pair_array_index] = center_queue[i] ;
	}
	for( i = *right_queue ; i >= 1 ; i-- ) {
	    pairArray[block][++pair_array_index] = right_queue[i] ;
	}
}
left_edge  = barray[block]->bxcenter + barray[block]->bleft ;
if( flag == 1 ) {
	space = (int)( (double)(feeds_in_row[block] * binWidth) /
					(double)(cell_count - 1) ) ;
} else {
	space = 0 ;
}
for( i = 1 ; i <= cell_count ; i++ ) {
	cellptr = carray[ pairArray[block][i] ] ;
cell_left = cellptr->tileptr->left ;
cellptr->cxcenter = left_edge - cell_left ;
	left_edge += cellptr->tileptr->right - cell_left + space ;
}
}
safe_free(num);
safe_free(left_queue) ;
safe_free(right_queue) ;
safe_free(center_queue) ;
if( flag >= 0 ) {
xcompact() ;
}
return ;
}
/* 当前文件是D:\Read\upair.c*/

#define PICK_INT(l,u) (((l)<(u)) ? ((RAND % ((u)-(l)+1))+(l)) : (l))





upair()
{
CBOXPTR acellptr, bcellptr ;
BBOXPTR ablckptr ;
int a , b , ablock , aorient ;
int flips , attempts ;
int axcenter,anxcenter, bnxcenter ;
int aleft , aright ;
int startx1, endx1;
int cellleft, cellrite;
int leftEdge, riteEdge;
int aptr ;
flips = 0 ;
attempts = 0 ;
while( attempts < attmax ) {
ablock = PICK_INT( 1 , numblock ) ;
if( pairArray[ablock][0] <= 1 ) {
	continue ;
}
aptr = PICK_INT( 1 , pairArray[ablock][0] ) ;
a = pairArray[ablock][aptr] ;
acellptr = carray[ a ]  ;
if( acellptr->cclass == -1 ) {
	continue ;
}
aorient = acellptr->corient ;
ablckptr = barray[ ablock ] ;
axcenter = acellptr->cxcenter ;
aleft = acellptr->tileptr->left ;
aright = acellptr->tileptr->right ;
startx1 = axcenter + aleft    ;
endx1   = axcenter + aright   ;
if( aptr > 1 ) {
	cellleft = pairArray[ablock][aptr - 1] ;
	if( carray[cellleft]->cclass == -1 ) {
	    cellleft = 0 ;
	}
} else {
	cellleft = 0 ;
}
if( aptr < pairArray[ablock][0] ) {
	cellrite = pairArray[ablock][aptr + 1] ;
	if( carray[cellrite]->cclass == -1 ) {
	    cellrite = 0 ;
	}
} else {
	cellrite = 0 ;
}
if( cellleft == 0 && cellrite == 0 ) {
	continue ;
}
if( cellleft != 0 && cellrite != 0 ) {
	if( PICK_INT(1 , 2) == 1 ){
	
	    b = cellleft ;
	    bcellptr = carray[b] ;
	    leftEdge = bcellptr->cxcenter + bcellptr->tileptr->left ;
	    anxcenter = leftEdge - aleft ;
	    bnxcenter = endx1 - bcellptr->tileptr->right ;
	    if( ucxxp( a, b, anxcenter, bnxcenter ) ) {
		flips++ ;
		attempts++ ;
		pairArray[ablock][aptr] = b ;
		pairArray[ablock][aptr - 1] = a ;
	    } else {
		attempts++ ;
		b = cellrite ;
		bcellptr = carray[b] ;
		riteEdge = bcellptr->cxcenter
				+ bcellptr->tileptr->right ;
		anxcenter = riteEdge - aright ;
		bnxcenter = startx1 - bcellptr->tileptr->left ;
		if( ucxxp( a, b, anxcenter, bnxcenter ) ) {
		    flips++ ;
		    pairArray[ablock][aptr] = b ;
		    pairArray[ablock][aptr + 1] = a ;
		}
		attempts++ ;
	    }
	} else {
	    b = cellrite ;
	    bcellptr = carray[b] ;
	    riteEdge = bcellptr->cxcenter + bcellptr->tileptr->right ;
	    anxcenter = riteEdge - aright ;
	    bnxcenter = startx1 - bcellptr->tileptr->left ;
	    if( ucxxp( a, b, anxcenter, bnxcenter ) ) {
		flips++ ;
		attempts++ ;
		pairArray[ablock][aptr] = b ;
		pairArray[ablock][aptr + 1] = a ;
	    } else {
		attempts++ ;
		b = cellleft ;
		bcellptr = carray[b] ;
		leftEdge = bcellptr->cxcenter + bcellptr->tileptr->left;
		anxcenter = leftEdge - aleft ;
		bnxcenter = endx1 - bcellptr->tileptr->right ;
		if( ucxxp( a, b, anxcenter, bnxcenter ) ) {
		    flips++ ;
		    pairArray[ablock][aptr] = b ;
		    pairArray[ablock][aptr - 1] = a ;
		}
		attempts++ ;
	    }
	}
} else {
	if( cellleft ) {
	    b = cellleft ;
	    bcellptr = carray[b] ;
	    leftEdge = bcellptr->cxcenter + bcellptr->tileptr->left ;
	    anxcenter = leftEdge - aleft ;
	    bnxcenter = endx1 - bcellptr->tileptr->right ;
	    if( ucxxp( a, b, anxcenter, bnxcenter ) ) {
		flips++ ;
		pairArray[ablock][aptr] = b ;
		pairArray[ablock][aptr - 1] = a ;
	    }
	    attempts++ ;
	} else if( cellrite != 0 &&
		    carray[cellrite]->cclass != -1 &&
		    acellptr->cclass != -1 ) {
	    b = cellrite ;
	    bcellptr = carray[b] ;
	    riteEdge = bcellptr->cxcenter + bcellptr->tileptr->right ;
	    anxcenter = riteEdge - aright ;
	    bnxcenter = startx1 - bcellptr->tileptr->left ;
	    if( ucxxp( a, b, anxcenter, bnxcenter ) ) {
		flips++ ;
		pairArray[ablock][aptr] = b ;
		pairArray[ablock][aptr + 1] = a ;
	    }
	    attempts++ ;
	}
}
if( ablckptr->borient == 1 ) {
	if( acellptr->orflag != 0 ) {
	    uc0( a , (aorient == 0) ? 2 : 0 ) ;
	}
} else {
	if( acellptr->orflag != 0 ) {
	    uc0( a , (aorient == 1) ? 3 : 1 ) ;
	}
}
}
fprintf( fpo, " %3d %6.3f %9d  %3d%s\n", iteration+1 , T , funccost ,
	(int)( 100.0 * (double)(flips) / (double)(attmax) ) , "%" ) ;
fflush( fpo ) ;
return;
}
/* 当前文件是D:\Read\urcost.c*/

urcost( segment )
int segment ;
{
SEGBOXPTR asegptr , bsegptr ;
CHANGRDPTR aptr1 , aptr2 , bptr1 , bptr2 , bptr , fptr , ptr ;
CHANGRDPTR saptr , eaptr , sbptr , ebptr ;
DENSITYPTR denptr , headptr ;
int penalty , check ;
int x , achannel , bchannel , aMaxVal , bMaxVal ;
int maxaa , maxbb ;
int aoutside , binside ;
int ax1 , ax2 , bx1 , bx2 ;
int net , Flag , track ;
penalty = 0 ;
net = aNetSeg[segment].net ;
if( aNetSeg[segment].current == 0 ) {
asegptr = aNetSeg[segment].top ;
bsegptr = aNetSeg[segment].bot ;
} else {
asegptr = aNetSeg[segment].bot ;
bsegptr = aNetSeg[segment].top ;
}
achannel = asegptr->channel ;
bchannel = bsegptr->channel ;
aptr1 = asegptr->pin1ptr ;
aptr2 = asegptr->pin2ptr ;
bptr1 = bsegptr->pin1ptr ;
bptr2 = bsegptr->pin2ptr ;
aMaxVal = maxTrack[achannel] ;
bMaxVal = maxTrack[bchannel] ;
ax1 = aptr1->netptr->xpos ;
ax2 = aptr2->netptr->xpos ;
bx1 = bptr1->netptr->xpos ;
bx2 = bptr2->netptr->xpos ;
net = aNetSeg[segment].net ;
if( aptr1->SegType > 0 ) {
Flag = 0 ;
bptr = aptr1 ;
while( bptr->prevgrd != GRDNULL
		&& bptr->prevgrd->netptr->xpos == ax1 ) {
	if( net == tearray[bptr->prevgrd->netptr->terminal]->net
			    && bptr->prevgrd->SegType < 0 ) {
	    Flag = 1 ;
	    saptr = aptr1->nextgrd ;
	    while( saptr->netptr->xpos == ax1 ) {
		saptr = saptr->nextgrd ;
	    }
	    break ;
	} else {
	    bptr = bptr->prevgrd ;
	}
}
if( !Flag ) {
	saptr = aptr1->nextgrd ;
	while( saptr->netptr->xpos == ax1 ) {
	    if( net == tearray[saptr->netptr->terminal]->net
				&& saptr->SegType < 0 ) {
		Flag = 1 ;
	    }
	    saptr = saptr->nextgrd ;
	}
}
if( !Flag ) {
	saptr = bptr ;
}
} else {
if( ax1 != gxstart ) {
	saptr = aptr1->nextgrd ;
	while( saptr->netptr->xpos == ax1 ) {
	    saptr = saptr->nextgrd ;
	}
} else {
	saptr = aptr1 ;
}
}
if( aptr2->SegType < 0 ) {
Flag = 0 ;
fptr = aptr2 ;
while( fptr->nextgrd != GRDNULL
		&& fptr->nextgrd->netptr->xpos == ax2 ) {
	if( net == tearray[fptr->nextgrd->netptr->terminal]->net
			    && fptr->nextgrd->SegType > 0 ) {
	    Flag = 1 ;
	    eaptr = aptr2->prevgrd ;
	    while( eaptr->netptr->xpos == ax2 ) {
		eaptr = eaptr->prevgrd ;
	    }
	    break ;
	} else {
	    fptr = fptr->nextgrd ;
	}
}
if( !Flag ) {
	eaptr = aptr2->prevgrd ;
	while( eaptr->netptr->xpos == ax2 ) {
	    if( net == tearray[eaptr->netptr->terminal]->net
				&& eaptr->SegType > 0 ) {
		Flag = 1 ;
	    }
	    eaptr = eaptr->prevgrd ;
	}
}
if( !Flag ) {
	eaptr = fptr ;
}
} else {
if( ax2 != gxstop ) {
	eaptr = aptr2->prevgrd ;
	while( eaptr->netptr->xpos == ax2 ) {
	    eaptr = eaptr->prevgrd ;
	}
} else {
	eaptr = aptr2 ;
}
}
if( bptr1->SegType >= 0 ) {
Flag = 0 ;
bptr = bptr1 ;
while( bptr->prevgrd != GRDNULL
		&& bptr->prevgrd->netptr->xpos == bx1 ) {
	if( net == tearray[bptr->prevgrd->netptr->terminal]->net
			    && bptr->prevgrd->SegType < 0 ) {
	    Flag = 1 ;
	    sbptr = bptr1->nextgrd ;
	    while( sbptr->netptr->xpos == bx1 ) {
		sbptr = sbptr->nextgrd ;
	    }
	    break ;
	} else {
	    bptr = bptr->prevgrd ;
	}
}
if( !Flag ) {
	sbptr = bptr1->nextgrd ;
	while( sbptr->netptr->xpos == bx1 ) {
	    if( net == tearray[sbptr->netptr->terminal]->net
				&& sbptr->SegType < 0 ) {
		Flag = 1 ;
	    }
	    sbptr = sbptr->nextgrd ;
	}
}
if( !Flag ) {
	sbptr = bptr ;
}
} else {
sbptr = bptr1->nextgrd ;
while( sbptr->netptr->xpos == bx1 ) {
	sbptr = sbptr->nextgrd ;
}
}
if( bptr2->SegType <= 0 ) {
Flag = 0 ;
fptr = bptr2 ;
while( fptr->nextgrd != GRDNULL
		&& fptr->nextgrd->netptr->xpos == bx2 ) {
	if( net == tearray[fptr->nextgrd->netptr->terminal]->net
			    && fptr->nextgrd->SegType > 0 ) {
	    Flag = 1 ;
	    ebptr = bptr2->prevgrd ;
	    while( ebptr->netptr->xpos == bx2 ) {
		ebptr = ebptr->prevgrd ;
	    }
	    break ;
	} else {
	    fptr = fptr->nextgrd ;
	}
}
if( !Flag ) {
	ebptr = bptr2->prevgrd ;
	while( ebptr->netptr->xpos == bx2 ) {
	    if( net == tearray[ebptr->netptr->terminal]->net
				&& ebptr->SegType > 0 ) {
		Flag = 1 ;
	    }
	    ebptr = ebptr->prevgrd ;
	}
}
if( !Flag ) {
	ebptr = fptr ;
}
} else {
ebptr = bptr2->prevgrd ;
while( ebptr->netptr->xpos == bx2 ) {
	ebptr = ebptr->prevgrd ;
}
}
aoutside = 0 ;
ax1 = saptr->netptr->xpos ;
ax2 = eaptr->netptr->xpos ;
denptr = DboxHead[ achannel ][ aMaxVal ]->next ;
for( ; denptr != DENSENULL ; denptr = denptr->next ) {
x = denptr->grdptr->netptr->xpos ;
if( !( ax1 <= x && ax2 >= x ) ) {
	aoutside = 1 ;
	break ;
}
}
if( aoutside == 0 ) {
penalty-- ;
}
binside  = 0 ;
bx1 = sbptr->netptr->xpos ;
bx2 = ebptr->netptr->xpos ;
denptr = DboxHead[ bchannel ][ bMaxVal ]->next ;
for( ; denptr != DENSENULL ; denptr = denptr->next ) {
x = denptr->grdptr->netptr->xpos ;
if( bx1 <= x && bx2 >= x ) {
	binside = 1 ;
	break ;
}
}
if( binside == 1 ) {
penalty++ ;
}
eaptr = eaptr->nextgrd ;
ebptr = ebptr->nextgrd ;
if( penalty == 0 ) {
if( binside == 1 && aoutside == 0 ) {
	
	check = bMaxVal - aMaxVal + 2 ;
} else {
	maxaa = 0 ;
	maxbb = 0 ;
	for( ptr = saptr ; ptr != eaptr ; ptr = ptr->nextgrd ) {
	    if( ptr->tracks > maxaa ) {
		maxaa = ptr->tracks ;
	    }
	}
	for( ptr = sbptr ; ptr != ebptr ; ptr = ptr->nextgrd ) {
	    if( ptr->tracks > maxbb ) {
		maxbb = ptr->tracks ;
	    }
	}
	maxaa = aMaxVal  - maxaa + 1 ;
	maxbb = bMaxVal  - maxbb - 1 ;
	check = maxaa - maxbb ;
}
} else {
check = penalty ;
}
if( check <= 0 ) {
if( asegptr->pin1 <= maxterm ) {
	aptr1->SegType -= RIGHT ;
}
if( asegptr->pin2 <= maxterm ) {
	aptr2->SegType -= LEFT  ;
}
if( bsegptr->pin1 <= maxterm ) {
	bptr1->SegType += RIGHT ;
}
if( bsegptr->pin2 <= maxterm ) {
	bptr2->SegType += LEFT  ;
}
for( ptr = saptr ; ptr != eaptr ; ptr = ptr->nextgrd ) {
	denptr = ptr->dptr ;
	if( denptr->next != DENSENULL ) {
	    denptr->next->back = denptr->back ;
	}
	denptr->back->next = denptr->next ;
	track = --(ptr->tracks) ;
	headptr = DboxHead[ achannel ][ track ]->next ;
	if( headptr != DENSENULL ) {
	    DboxHead[ achannel ][ track ]->next = denptr ;
	    denptr->next  = headptr ;
	    headptr->back = denptr  ;
	    denptr->back  = DboxHead[ achannel ][ track ] ;
	} else {
	    DboxHead[ achannel ][ track ]->next = denptr ;
	    denptr->next = DENSENULL ;
	    denptr->back = DboxHead[ achannel ][ track ];
	}
}
if( aoutside == 0 ) {
	maxTrack[achannel]-- ;
}
for( ptr = sbptr ; ptr != ebptr ; ptr = ptr->nextgrd ) {
	denptr = ptr->dptr ;
	if( denptr->next != DENSENULL ) {
	    denptr->next->back = denptr->back ;
	}
	denptr->back->next = denptr->next ;
	track = ++(ptr->tracks) ;
	headptr = DboxHead[ bchannel ][ track ]->next ;
	if( headptr != DENSENULL ) {
	    DboxHead[ bchannel ][ track ]->next = denptr ;
	    denptr->next  = headptr ;
	    headptr->back = denptr  ;
	    denptr->back  = DboxHead[ bchannel ][ track ] ;
	} else {
	    DboxHead[ bchannel ][ track ]->next = denptr ;
	    denptr->next = DENSENULL ;
	    denptr->back = DboxHead[ bchannel ][ track ];
	}
}
if( binside == 1 ) {
	maxTrack[bchannel]++ ;
}
if( aNetSeg[segment].current == 1 ) {
	aNetSeg[segment].current = 0 ;
} else {
	aNetSeg[segment].current = 1 ;
}
tracks += penalty ;
return (1) ;
} else {
return (0) ;
}
}
/* 当前文件是D:\Read\utemp.c*/
utemp()
{
double TloRange , Tfactor ;
int pairtest , check ;
unsigned i2 ;
double **tempfile ;
char filename[64] ;
int t , i , row , freeze , cell , changes ;
FILE *fp ;
last_level = -1 ;
if( stage >= 2 ) {
pairtest = 1 ;
} else {
pairtest = 0 ;
}
initialRowControl = 0.0 ;
finalRowControl = 0.0 ;
check = 0 ;
freeze = 10000000 ;
randVar = randomSeed ;
fprintf( fpo, "\nThe rand generator seed was at utemp() : %d\n\n\n",
						    randVar ) ;
table1[0] = 1.0 ;
table2[0] = 1.0 ;
table3[0] = 1.0 ;
for( i2 = 1 ; i2 <= 1023 ; i2++ ) {
table1[ i2 ] = exp( -(double) i2 / 8.0 ) ;
table2[ i2 ] = exp( -(double) i2 / 8192.0 ) ;
table3[ i2 ] = exp( -(double) i2 / 8388608.0 ) ;
}
moveable_cells = 0 ;
for( cell = 1 ; cell <= numcells ; cell++ ) {
if( carray[cell]->cclass < 0 ) {
continue ;
}
moveable_cells++ ;
}
if( moveable_cells <= 500 ) {
attprcel = 25 ;
} else {
attprcel = (int)(25.0 *
		pow( (double) moveable_cells / 500.0, 1.0 / 3.0 ) ) ;
}
if( tw_fast ) {
attprcel /= 5 ;
}
tempfile = (double **) safe_malloc( 4 * sizeof( double * ) ) ;
for( t = 0 ; t <= 3 ; t++ ) {
tempfile[t] = (double *) safe_malloc( 2 * sizeof( double ) ) ;
}
tempfile[0][0] = 0.9825 ;
tempfile[0][1] = 90.0 ;
fprintf(fpo,"  tempfile[0][0] = %f    ", tempfile[0][0] );
fprintf(fpo,  "tempfile[0][1] = %f\n  ", tempfile[0][1] );
tempfile[1][0] = 0.915 ;
tempfile[1][1] = 20.0 ;
fprintf(fpo,"tempfile[1][0] = %f    ", tempfile[1][0] );
fprintf(fpo,"tempfile[1][1] = %f\n  ", tempfile[1][1] );
tempfile[2][0] = 0.70 ;
tempfile[2][1] = 10.0 ;
fprintf(fpo,"tempfile[2][0] = %f    ", tempfile[2][0] );
fprintf(fpo,"tempfile[2][1] = %f\n  ", tempfile[2][1] );
tempfile[3][0] = 0.10 ;
tempfile[3][1] = 0.0 ;
fprintf(fpo,"tempfile[3][0] = %f    ", tempfile[3][0] );
fprintf(fpo,"tempfile[3][1] = %f\n\n", tempfile[3][1] );
TloRange = 10000000000.0 ;
t = -1 ;
fprintf(fpo , "  I   T  fds     Wire Penalty P_lim Epct " ) ;
fprintf(fpo , "binC rowC  acc  s/p early  FDs    MRs\n" ) ;
for( ; ; ) {
while( T1 < TloRange ) {
	t++ ;
	if( t > 3 ) {
	    fprintf( fpo, "exceeded tempfile array in ");
	    fprintf( fpo, "utemp.c \n");
	    exit(TW_FAIL);
	}
	Tfactor  = tempfile[t][0] ;
	TloRange = tempfile[t][1] ;
}
if( pairtest == 0 ) {
	uloop() ;
	if( T1 < Tzero ) {
	    pairtest = 1 ;
	}
	savewolf(1) ;
} else {
	if( check == 0 ) {
	    check = 1 ;
	    if( stage == 1 ) {
		uloop2() ;
		++iteration ;
	    }
	    last_level = -1 ;
	    savewolf(1) ;
	    freeze = iteration ;
	    if( connection_machine ) {
		unlap(-1) ;
		findunlap(-1) ;
		outcm() ;
	    }
	    countf() ;
	    if( doglobal ) {
		sprintf( filename , "%s.cel" , cktName ) ;
		fp = twopen (filename , "r", ABORT ) ;
		finalwire() ;
		grdcell( fp ) ;
		twclose( fp ) ;
	    }
	    reassign() ;
	    if( doglobal ) {
		if( addFeeds == 0 ) {
		    for( row = 1 ; row <= numblock ; row++ ) {
			nofeed[row] = 1 ;
		    }
		}
		findunlap(1) ;
		fdthrus = findfeeds(0) ;
		fdthrus += add_to_row[0] ;
		fixwolf( fdthrus ) ;
		findfeeds(1) ;
		unlap(-2) ;
		add_dummy_feeds( last_feed ) ;
		numcells += fdthrus ;
		moveable_cells += fdthrus ;
		if( stage >= 2 ) {
		    sprintf( filename , "%s.rs2" , cktName ) ;
		    if( fp = twopen ( filename , "r", NOABORT )) {
			fixfdpos(fp) ;
			twclose(fp) ;
		    }
		}
	    }
	    sortpin() ;
	    findunlap(0) ;
	    penalty = 0 ;
	    initialize_cost() ;
	
	    fprintf(fpo,"Added: %d  feed-through cells\n\n",fdthrus);
	    fprintf(fpo,"Removed the cell overlaps --- ");
	    fprintf(fpo,"Will do neighbor interchanges only now\n");
	    fprintf( fpo, "\nTOTAL INTERCONNECT LENGTH: %d\n",funccost);
	    fprintf(fpo,"OVERLAP PENALTY: %d\n\n", penalty );
	    fprintf(fpo,"initialRowControl:%8.3f\n", initialRowControl);
	    fprintf(fpo,"finalRowControl:%8.3f\n", finalRowControl);
	    fflush(fpo);
	    attmax = 5 * moveable_cells ;
	    if( stage != 3 ) {
		if( noPairs == 0 ) {
		    T1 = 0.001 ;
		    fprintf( fpo, "iter      T      Wire accept\n" ) ;
		    upair() ;
		    savewolf(2) ;
		}
	    }
	} else {
	    if( noPairs == 0 ) {
		T1 = 0.001 ;
		upair() ;
		savewolf(2) ;
	    }
	}
}
if( stage != 3 ) {
	printf("%3d ", ++iteration );
	if( iteration % 15 == 0 ) {
	    printf("\n");
	}
	fflush( stdout ) ;
}
if( iteration >= freeze + 3 || stage == 3 ) {
	
	
	for( i = 1 ; i <= 8 ; i++ ) {
	    align_init() ;
	    changes = alignfeed() ;
	    fprintf(fpo,"Total Feed-Alignment Movement (Pass %d): %d\n",
						    i, changes );
	}
	align_init() ;
	
	findunlap(-1) ;
	if( doglobal ) {
	    globe() ;
	    globroute() ;
	    if( cswaps ) {
		if( noPairs == 0 ) {
		    ugpair() ;
		}
	    }
	    findrchk() ;
	    fprintf(fpo,"\nFINAL NUMBER OF ROUTING TRACKS: %d\n\n",
							    tracks ) ;
	    for( i = 1 ; i <= numChans ; i++ ) {
		fprintf(fpo,"MAX OF CHANNEL:%3d  is: %3d\n",i
						,maxTrack[i]);
	    }
	    mergplist() ;
	    outpins() ;
	    output() ;
	} else {
	    output() ;
	}
	fprintf(fpo,"FINAL TOTAL INTERCONNECT LENGTH: %d\n",funccost);
	fprintf(fpo,"FINAL OVERLAP PENALTY: %d    ", penalty );
	fprintf(fpo, "FINAL VALUE OF TOTAL COST IS: %d\n",
					    funccost + penalty ) ;
	fprintf(fpo,"MAX NUMBER OF ATTEMPTED FLIPS PER T:%8d\n",attmax);
	break ;
} else {
	T1 = Tfactor * T1 ;
}
}
fprintf(fpo,"\n\ncost_scale_factor:%g\n\n", cost_scale_factor ) ;
return ;
}
add_dummy_feeds( feednum )
int feednum ;
{
CBOXPTR cellptr ;
TIBOXPTR tileptr ;
int pin , corient , left , right ;
int pos , row , i , last_cell ;
for( row = 1 ; row <= numRows ; row++ ) {
last_cell = pairArray[row][ pairArray[row][0] ] ;
pos = carray[last_cell]->cxcenter +
			carray[last_cell]->tileptr->right - fdWidth ;
for( i = 1 ; i <= add_to_row[row] ; i++ ) {
	pos += fdWidth ;
	cellptr = carray[ numcells + ++feednum ] ;
	cellptr->padside = 0 ;
	cellptr->cxcenter = pos ;
	cellptr->cycenter = barray[row]->bycenter ;
	cellptr->cheight  = barray[row]->bheight  ;
	cellptr->clength  = fdWidth ;
	if( barray[row]->borient == 2 ) {
	    cellptr->corient = 1 ;
	}
	tileptr = cellptr->tileptr ;
	cellptr->cname = (char *) safe_malloc( 16 * sizeof( char ) ) ;
#ifdef FEED_INSTANCES
	sprintf( cellptr->cname , "twfeed%d", feednum ) ;
#else
	sprintf( cellptr->cname , "twfeed" ) ;
#endif
	cellptr->cblock = row ;
	tileptr->left   = -fdWidth / 2 ;
	tileptr->right  = fdWidth + tileptr->left ;
	tileptr->bottom = -barray[row]->bheight / 2 ;
	tileptr->top    = barray[row]->bheight + tileptr->bottom ;
	safe_free( tileptr->termsptr->nextterm ) ;
	safe_free( tileptr->termsptr ) ;
	tileptr->termsptr = TERMNULL ;
}
}
return ;
}
/* 当前文件是D:\Read\utils.c*/

#ifndef UTILS_H
#endif
static char programName[LRECL];
static char progVersion[LRECL];
static char progDate[LRECL];
initProgram(name,version)
char *name ;
char *version ;
{
char    message[LRECL] ,
	    *date ,
	    *getCompileDate() ;
int     i ;
sprintf(programName,"%s",name);
sprintf(progVersion,"%s",version);
if ( date = getCompileDate() ){
	sprintf(progDate,"%s",date);
} else {
	sprintf(progDate,"unknown") ;
}
fprintf(fpo,"\n%s version:%s date:%s\n",programName,progVersion,progDate) ;
fprintf(fpo,"Standard Cell Placement and Global Routing Program\n");
fprintf(fpo,"Authors: Carl Sechen, Bill Swartz\n");
fprintf(fpo,"          Yale University\n");
printf("\n%s version:%s date:%s\n",programName,progVersion,progDate) ;
printf("Standard Cell Placement and Global Routing Program\n");
printf("Authors: Carl Sechen, Bill Swartz\n");
printf("         Yale University\n");
safe_free(date) ;
#if 0
randomSeed  = time(0) ;
#endif
randomSeed  = 123456789 ;
fixarray = (int *) NULL ;
ffeeds = 0 ;
for( i = 1 ; i <= 15 ; i++ ) {
	macspace[i] = -1.0 ;
}
costonly = 0 ;
fdthrus = 0 ;
doglobal = 0 ;
cswaps = 0 ;
imprange = -1.0 ;
attprcel = 0 ;
addFeeds = 0 ;
fdWidth  = -1 ;
rowSep = -1.0 ;
indent = 1.0 ;
numSegs = 0 ;
resume_run = NO ;
pin_layers_given = 0 ;
no_feeds_side_nets = 0 ;
no_net_normalize = 0 ;
cost_scale_factor = 1.0 ;
feedLayer = 0 ;
tw_fast = 0 ;
estimate_feeds = 1 ;
connection_machine = 0 ;
gate_array_special = FALSE ;
#if 0
randomSeed  = time(0) ;
#endif
randomSeed2 = 987654321;
}
char *getProgName()
{
return(strclone(programName));
}
char *strclone(str)
char *str ;
{
char *copy ;
if( str ){
	if( *str ){
	    copy = (char *) safe_malloc(strlen(str)+1) ;
	    sprintf(copy,"%s",str) ;
	    return(copy) ;
	}
}
return(NULL) ;
}
FILE *openFile(filename,readwrite,abort)
char *filename ;
char *readwrite ;
int  abort ;
{
FILE *fileptr ;
fileptr = fopen( filename, readwrite );
if( !(fileptr) && abort ){
	printf("could not open file %s\n",filename ) ;
	exit(TW_FAIL) ;
}
return( fileptr ) ;
}
/* 当前文件是D:\Read\xcompact.c*/


int *blklist ;



typedef struct int2 {
int sleft ;
int srite ;
} INT2 ;
INT2 *blkshifts ;
#define L   1
#define T   2
#define R   3
#define B   4
#define MUL 5
#define MUR 6
#define MLL 7
#define MLR 8
#define ML  9
#define MR  10
#define MB  11
#define MT  12
#define MM  13
#define MTT 14
#define MBB 15

xcompact()
{
int blk , pad , k , bot , top , rite , left , maxd , cell , end , mind ;
int padside ;
CBOXPTR padptr , cellptr ;
blklist = (int *) safe_malloc( (numblock + 1) * sizeof( int ) ) ;
blkshifts = (INT2 *) safe_malloc( (numblock + 1) * sizeof( INT2 ) ) ;
for( blk = 1 ; blk <= numblock ; blk++ ) {
blkshifts[blk].sleft = -1000 ;
}
for( pad = numcells + 1 ; pad <= numcells + numterms ; pad++ ) {
if( carray[pad]->padside == MT || carray[pad]->padside == MM ||
				      carray[pad]->padside == MB ) {
	padptr  = carray[pad] ;
	padside = padptr->padside ;
	rite = padptr->cxcenter + padptr->tileptr->right ;
	left = padptr->cxcenter + padptr->tileptr->left ;
	bot = padptr->cycenter + padptr->tileptr->bottom
				    - rowSep * rowHeight * 0.67;
	top = padptr->cycenter + padptr->tileptr->top
				    + rowSep * rowHeight * 0.67 ;
	findblks( bot , top , rite , -1 ) ;
	maxd = 0 ;
	for( k = 1 ; k <= blklist[0] ; k++ ) {
	    blk = blklist[k] ;
	    cell = pairArray[blk][ pairArray[blk][0] ] ;
	    cellptr = carray[cell] ;
	    if( cellptr->cxcenter + cellptr->tileptr->right > maxd ) {
		maxd = cellptr->cxcenter + cellptr->tileptr->right  ;
	    }
	}
	for( k = 1 ; k <= blklist[0] ; k++ ) {
	    blk = blklist[k] ;
	    blkshifts[blk].srite = maxd ;
	    blkshifts[blk].sleft = barray[blk]->bxcenter +
						    barray[blk]->bleft ;
	}
	findblks( bot , top , rite , 1 ) ;
	carray[pad]->cxcenter += macspace[padside] - (left - maxd);
	for( k = 1 ; k <= blklist[0] ; k++ ) {
	    blk = blklist[k] ;
	    barray[blk]->bxcenter += macspace[padside] -
						    (left - maxd) ;
	    for( k = 1 ; k <= pairArray[blk][0] ; k++ ) {
		cell = pairArray[blk][k] ;
		carray[cell]->cxcenter += macspace[padside] -
						    (left - maxd) ;
	    }
	}
}
}
for( pad = numcells + 1 ; pad <= numcells + numterms ; pad++ ) {
padptr = carray[ pad ] ;
if( padptr->padside == MUR || padptr->padside == MR ||
				      padptr->padside == MLR ) {
	padside = padptr->padside ;
	rite = padptr->cxcenter + padptr->tileptr->right ;
	left = padptr->cxcenter + padptr->tileptr->left ;
	bot = padptr->cycenter + padptr->tileptr->bottom
					- rowSep * rowHeight * 0.33 ;
	top = padptr->cycenter + padptr->tileptr->top
					+ rowSep * rowHeight * 0.33 ;
	findblks( bot , top , rite , -1 ) ;
	maxd = 0 ;
	for( k = 1 ; k <= blklist[0] ; k++ ) {
	    blk = blklist[k] ;
	    cell = pairArray[blk][ pairArray[blk][0] ] ;
	    cellptr = carray[cell] ;
	    if( cellptr->cxcenter + cellptr->tileptr->right > maxd ) {
		maxd = cellptr->cxcenter + cellptr->tileptr->right ;
	    }
	}
	for( k = 1 ; k <= blklist[0] ; k++ ) {
	    blk = blklist[k] ;
	    blkshifts[blk].srite = maxd ;
	    blkshifts[blk].sleft = barray[blk]->bxcenter +
						    barray[blk]->bleft ;
	}
	carray[pad]->cxcenter += macspace[padside] - (left - maxd);
}
}
maxd = 0 ;
for( blk = 1 ; blk <= numblock ; blk++ ) {
if( pairArray[blk][0] <= 0 ) {
	continue ;
}
cell = pairArray[blk][ pairArray[blk][0] ] ;
end = carray[cell]->cxcenter + carray[cell]->tileptr->right ;
if( end > maxd ) {
	maxd = end ;
}
}
for( pad = numcells + 1 ; pad <= numcells + numterms ; pad++ ) {
padptr = carray[pad] ;
if( padptr->padside == MUR || padptr->padside == MR ||
padptr->padside == MLR || padptr->padside == MTT ||
padptr->padside == MBB ) {
	if( padptr->cxcenter + padptr->tileptr->right  > maxd ) {
	    maxd = padptr->cxcenter + padptr->tileptr->right ;
	}
}
}
for( blk = 1 ; blk <= numblock ; blk++ ) {
if( blkshifts[blk].sleft == -1000 ) {
	blkshifts[blk].srite = maxd ;
	blkshifts[blk].sleft = barray[blk]->bxcenter +
						    barray[blk]->bleft ;
}
}
mind = 32000 ;
for( pad = numcells + 1 ; pad <= numcells + numterms ; pad++ ) {
padptr = carray[pad] ;
if( padptr->padside == R ) {
	if( padptr->cxcenter + padptr->tileptr->left < mind ) {
	    mind = padptr->cxcenter + padptr->tileptr->left ;
	}
}
}
for( pad = numcells + 1 ; pad <= numcells + numterms ; pad++ ) {
if( carray[pad]->padside == R ) {
	carray[pad]->cxcenter += rowSep * rowHeight - (mind - maxd);
}
}
#ifdef DEBUG
for( blk = 1 ; blk <= numblock ; blk++ ) {
fprintf(fpo,"blk:%d  sleft:%d  srite:%d\n",blk,blkshifts[blk].sleft,
					blkshifts[blk].srite ) ;
}
#endif
return ;
}
findblks( bot , top , rite , direction )
int bot , top , rite , direction ;
{
int blk ;
blklist[0] = 0 ;
for( blk = 1 ; blk <= numblock ; blk++ ) {
if( barray[blk]->bycenter > bot && barray[blk]->bycenter < top ) {
	if( direction == -1 ) {
	    if( barray[blk]->bxcenter + barray[blk]->bright < rite ) {
		if( blkshifts[blk].sleft == -1000 ) {
		    blklist[ ++blklist[0] ] = blk ;
		}
	    }
	} else {
	    if( barray[blk]->bxcenter + barray[blk]->bleft > rite ) {
		blklist[ ++blklist[0] ] = blk ;
	    }
	}
}
}
return ;
}
/* 当前文件是D:\Read\xpickint.c*/

#define RAND (Yacm_random() )
#define PICK_INT(l,u) (((l)<(u)) ? ((RAND % ((u)-(l)+1))+(l)) : (l))

XPICK_INT( l , u , c )
int l , u , c ;
{
int d ;
if ( c < 0 ) {
	return(-c) ;
} else {
do {
	    d = PICK_INT(l,u) ;
	} while ( d == c ) ;
	return(d) ;
}
}
