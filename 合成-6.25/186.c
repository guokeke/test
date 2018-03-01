/* 当前文件是D:\Read\main.c*/

/* 当前文件是D:\Read\chess.h*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <signal.h>
#include <ctype.h>
#include <time.h>
#include <limits.h>
#include <errno.h>
#if !defined(TYPES_INCLUDED)
#  define TYPES_INCLUDED
#if defined(AIX)
#  undef  LONG_HAS_64BITS
#  define HAS_LONGLONG
#  undef  LITTLE_ENDIAN_ARCH
#  define UNIX
#endif
#if defined(SIEMENS_MIPS)
#  undef LONG_HAS_64BITS
#  define  HAS_LONGLONG
#  undef LITTLE_ENDIAN_ARCH
#  define UNIX
#endif
#if defined(ALPHA)
#  define LONG_HAS_64BITS
#  undef  HAS_LONGLONG
#  define LITTLE_ENDIAN_ARCH
#  define UNIX
#endif
#if defined(AMIGA)
#  undef  LONG_HAS_64BITS
#  define HAS_LONGLONG
#  undef  LITTLE_ENDIAN_ARCH
#  undef  UNIX
#endif
#if defined(CRAY1)
#  define LONG_HAS_64BITS
#  undef  HAS_LONGLONG
#  undef  LITTLE_ENDIAN_ARCH
#  define UNIX
#endif
#if defined(DOS)
#  undef  LONG_HAS_64BITS
#  define HAS_LONGLONG
#  define LITTLE_ENDIAN_ARCH
#  undef  UNIX
#endif
#if defined(FreeBSD)
#  undef  LONG_HAS_64BITS
#  define HAS_LONGLONG
#  define LITTLE_ENDIAN_ARCH
#  define UNIX
#endif
#if defined(HP)
#  undef  LONG_HAS_64BITS
#  define HAS_LONGLONG
#  undef  LITTLE_ENDIAN_ARCH
#  define UNIX
#endif
#if defined(LINUX_i386)
#  undef  LONG_HAS_64BITS
#  define HAS_LONGLONG
#  define LITTLE_ENDIAN_ARCH
#  define UNIX
#  define LINUX
#endif
#if defined(LINUX_PPC32)
#  undef  LONG_HAS_64BITS
#  define HAS_LONGLONG
#  undef LITTLE_ENDIAN_ARCH
#  define UNIX
#  define LINUX
#endif
#if defined(MIPS)
#  undef  LONG_HAS_64BITS
#  define HAS_LONGLONG
#  undef  LITTLE_ENDIAN_ARCH
#  define UNIX
#endif
#if defined(NEXT)
#  undef  LONG_HAS_64BITS
#  define HAS_LONGLONG
#  undef  LITTLE_ENDIAN_ARCH
#  define UNIX
#endif
#if defined(NT_AXP)
#  undef  LONG_HAS_64BITS
#  define HAS_LONGLONG
#  define LITTLE_ENDIAN_ARCH
#  undef  UNIX
#endif
#if defined(NT_i386)
#  undef  LONG_HAS_64BITS
#  define HAS_LONGLONG
#  define LITTLE_ENDIAN_ARCH
#  undef  UNIX
#endif
#if defined(SGI)
#  undef  LONG_HAS_64BITS
#  define HAS_LONGLONG
#  undef  LITTLE_ENDIAN_ARCH
#  define UNIX
#endif
#if defined(SOLARIS_X64) || defined(SOLARIS_X86)
#  if defined(SOLARIS_X64)
#    define LONG_HAS_64BITS
#  else
#    undef  LONG_HAS_64BITS
#  endif
#  define HAS_LONGLONG
#  define LITTLE_ENDIAN_ARCH
#  define UNIX
#elif defined(SUN)
#  if defined(SPEC_CPU2000_LP64)
#    define LONG_HAS_64BITS
#  else
#    undef  LONG_HAS_64BITS
#  endif
#  define HAS_LONGLONG
#  undef  LITTLE_ENDIAN_ARCH
#  define UNIX
#endif
#if defined(LINUX_SPARC)
# undef LONG_HAS_64BITS
# define HAS_LONGLONG
# undef LITTLE_ENDIAN_ARCH
# define UNIX
# define LINUX
#endif
#if defined(SUN_BSD)
#  undef  LONG_HAS_64BITS
#  define HAS_LONGLONG
#  undef  LITTLE_ENDIAN_ARCH
#  define UNIX
#endif
#  define INCREMENT_PLY            60
#  define NULL_MOVE_DEPTH         120
#  define RAZORING_DEPTH           60
#  define IN_CHECK                 60
#  define ONE_REPLY_TO_CHECK       45
#  define RECAPTURE                60
#  define PASSED_PAWN_PUSH         60
#  define MATE                  32768
#  define PAWN_VALUE              100
#  define KNIGHT_VALUE            330
#  define BISHOP_VALUE            330
#  define ROOK_VALUE              520
#  define QUEEN_VALUE             980
#  define KING_VALUE            40000
#  define MAXPLY 65
#  if defined(LONG_HAS_64BITS)
typedef unsigned long BITBOARD;
#  else
#    if defined(NT_i386) || defined(NT_AXP)
typedef unsigned _int64 BITBOARD;
#    else
typedef unsigned long long BITBOARD;
#    endif
#  endif
#if !defined(CLOCKS_PER_SEC)
#  define CLOCKS_PER_SEC 1000000
#endif
typedef enum { A1,B1,C1,D1,E1,F1,G1,H1,
A2,B2,C2,D2,E2,F2,G2,H2,
A3,B3,C3,D3,E3,F3,G3,H3,
A4,B4,C4,D4,E4,F4,G4,H4,
A5,B5,C5,D5,E5,F5,G5,H5,
A6,B6,C6,D6,E6,F6,G6,H6,
A7,B7,C7,D7,E7,F7,G7,H7,
A8,B8,C8,D8,E8,F8,G8,H8,
BAD_SQUARE } squares;
typedef enum {FILEA, FILEB, FILEC, FILED, FILEE, FILEF, FILEG, FILEH} files;
typedef enum {RANK1, RANK2, RANK3, RANK4, RANK5, RANK6, RANK7, RANK8} ranks;
typedef enum {empty=0, pawn=1, knight=2, king=3,
bishop=5, rook=6, queen=7} PIECE;
typedef enum {empty_v=0, pawn_v=1, knight_v=2,
bishop_v=3, rook_v=5, queen_v=9} PIECE_V;
typedef enum {no_extension=0, check_extension=1, recapture_extension=2,
passed_pawn_extension=4, one_reply_extension=8} EXTENSIONS;
typedef enum {cpu, elapsed, microseconds} TIME_TYPE;
typedef enum {think=1, puzzle=2, book=3, annotate=4} SEARCH_TYPE;
typedef enum {normal_mode, tournament_mode} PLAYING_MODE;
typedef enum {crafty, opponent} PLAYER;
typedef enum {book_learning=1, position_learning=2} LEARNING_MODE;
typedef struct {
unsigned char enpassant_target;
signed   char w_castle;
signed   char b_castle;
unsigned char rule_50_moves;
} SEARCH_POSITION;
typedef  struct {
BITBOARD       w_occupied;
BITBOARD       b_occupied;
BITBOARD       occupied_rl90;
BITBOARD       occupied_rl45;
BITBOARD       occupied_rr45;
BITBOARD       rooks_queens;
BITBOARD       bishops_queens;
BITBOARD       w_pawn;
BITBOARD       w_knight;
BITBOARD       w_bishop;
BITBOARD       w_rook;
BITBOARD       w_queen;
BITBOARD       b_pawn;
BITBOARD       b_knight;
BITBOARD       b_bishop;
BITBOARD       b_rook;
BITBOARD       b_queen;
BITBOARD       hash_key;
unsigned int   pawn_hash_key;
int            material_evaluation;
signed char    white_king;
signed char    black_king;
signed char    board[64];
signed char    white_pieces;
signed char    white_pawns;
signed char    black_pieces;
signed char    black_pawns;
signed char    total_pieces;
} CHESS_POSITION;
typedef struct {
BITBOARD word1;
BITBOARD word2;
} HASH_ENTRY;
typedef struct {
unsigned int key;
short    p_score;
unsigned char black_protected;
unsigned char black_pof;
unsigned char weak_b;
unsigned char passed_b;
unsigned char black_defects_k;
unsigned char black_defects_q;
unsigned char white_protected;
unsigned char white_pof;
unsigned char weak_w;
unsigned char passed_w;
unsigned char white_defects_k;
unsigned char white_defects_q;
unsigned char outside;
} PAWN_HASH_ENTRY;
typedef struct {
int path[MAXPLY];
unsigned char path_hashed;
unsigned char path_length;
unsigned char path_iteration_depth;
} CHESS_PATH;
typedef struct {
int phase;
int remaining;
int *last;
} NEXT_MOVE;
typedef struct {
BITBOARD position;
BITBOARD status;
int learn;
} BOOK_POSITION;
#  define WORTHLESS                 0
#  define LOWER_BOUND               1
#  define UPPER_BOUND               2
#  define EXACT_SCORE               3
#  define AVOID_NULL_MOVE           4
#  define NULL_MOVE                 0
#  define DO_NULL                   1
#  define NO_NULL                   0
#  define NONE                      0
#  define FIRST_PHASE               1
#  define HASH_MOVE                 1
#  define GENERATE_CAPTURE_MOVES    2
#  define CAPTURE_MOVES             3
#  define KILLER_MOVE_1             4
#  define KILLER_MOVE_2             5
#  define GENERATE_ALL_MOVES        6
#  define SORT_ALL_MOVES            7
#  define HISTORY_MOVES_1           8
#  define HISTORY_MOVES_2           9
#  define REMAINING_MOVES          10
#  define ROOT_MOVES               11
#  if !defined(CRAY1)
BITBOARD     Mask(int);
int          PopCnt(BITBOARD);
int          FirstOne(BITBOARD);
int          LastOne(BITBOARD);
#  endif
void           Analyze();
void           Annotate();
int            Attacked(int, int);
BITBOARD       AttacksFrom(int, int);
BITBOARD       AttacksTo(int);
int            Book(int,int);
int            BookMask(char*);
void           BookUp(char*,int,char**);
#  if defined(NT_i386) || defined(NT_AXP)
int _cdecl     BookUpCompare(const void *, const void *);
#  else
int            BookUpCompare(const void *, const void *);
#  endif
int            CheckInput(void);
void           ClearHashTables(void);
void           ComputeAttacksAndMobility(void);
void           Delay(int);
void           DisplayBitBoard(BITBOARD);
void           DisplayChessBoard(FILE*, CHESS_POSITION);
char*          DisplayEvaluation(int);
char*          DisplayEvaluationWhisper(int);
void           DisplayFT(int, int, int);
char*          DisplayHHMM(unsigned int);
void           DisplayPieceBoards(int*, int*);
char*          DisplayTime(unsigned int);
char*          DisplayTimeWhisper(unsigned int);
void           Display2BitBoards(BITBOARD, BITBOARD);
void           DisplayChessMove(char*, int);
int            DrawScore(void);
int            Drawn(int);
void           Edit(void);
int            EnPrise(int, int);
int            Evaluate(int, int, int, int);
int            EvaluateDevelopment(int);
int            EvaluateDraws();
int            EvaluateMate(void);
int            EvaluatePassedPawns(void);
int            EvaluatePassedPawnRaces(int);
int            EvaluatePawns(void);
int*           GenerateCaptures(int, int, int*);
int*           GenerateCheckEvasions(int, int, int*);
int*           GenerateNonCaptures(int, int, int*);
unsigned int   GetTime(TIME_TYPE);
int            HasOpposition(int, int, int);
void           HistoryBest(int, int, int);
void           HistoryRefutation(int, int, int);
void           Initialize(int);
void           InitializeAttackBoards(void);
void           InitializeChessBoard(SEARCH_POSITION*);
int            InitializeFindAttacks(int, int, int);
void           InitializeHashTables(void);
void           InitializeMasks(void);
void           InitializePawnMasks(void);
void           InitializePieceMasks(void);
void           InitializeRandomHash(void);
void           InitializeZeroMasks(void);
int            InputMove(char*, int, int, int, int);
int            InputMoveICS(char*, int, int, int, int);
BITBOARD       InterposeSquares(int, int, int);
void           Interrupt(int);
int            Iterate(int, int, int);
int            KingPawnSquare(int, int, int, int);
int            LookUp(int, int, int, int*, int*);
void           MakeMove(int, int, int);
void           MakeMoveRoot(int, int);
void           NewGame(int);
int            NextEvasion(int, int);
int            NextMove(int, int);
int            NextRootMove(int);
char*          Normal(void);
int            Option(void);
int            OptionMatch(char*, char*);
void           OptionPerft(int,int,int);
char*          OutputMove(int*, int, int);
char*          OutputMoveICS(int*);
int            OutputGood(char*, int, int);
int            ParseTime(char*);
void           Phase(void);
int            PinnedOnKing(int,int);
int            Ponder(int);
void           PreEvaluate(int);
int            Quiesce(int, int, int, int);
unsigned int   Random32(void);
BITBOARD       Random64(void);
int            Read(int, char*);
int            ReadChessMove(FILE*, int, int);
void           ReadClear();
int            ReadNextMove(char*, int, int);
int            ReadParse(char*, char *args[], char*);
int            SpecReadRaw();
int            RepetitionCheck(int,int);
int            RepetitionDraw(int);
void           ResignOrDraw(int,int);
char*          Reverse(void);
void           RootMoveList(int);
int            Search(int, int, int, int, int, int);
void           SearchOutput(int,int);
int            SearchRoot(int, int, int, int);
void           SearchTrace(int,int,int,int,int,char*,int);
void           SetBoard(int,char**,int);
void           SetChessBitBoards(SEARCH_POSITION*);
void           StoreBest(int,int,int,int,int);
void           StorePV(int,int);
void           StoreRefutation(int,int,int,int);
int            Swap(int, int, int);
BITBOARD       SwapXray(BITBOARD, int, int);
void           TimeAdjust(int,PLAYER);
int            TimeCheck(int);
void           TimeSet(int);
void           UnMakeMove(int, int, int);
void           ValidatePosition(int,int,char*);
BITBOARD       ValidateComputeBishopAttacks(int);
BITBOARD       ValidateComputeRookAttacks(int);
int            ValidMove(int, int, int);
void           Whisper(int, int, int, int, unsigned int, int, char*);
#  if defined(LONG_HAS_64BITS) || defined(HAS_LONGLONG)
#    define And(a,b)    ((a) & (b))
#    define Or(a,b)     ((a) | (b))
#    define Xor(a,b)    ((a) ^ (b))
#    define Compl(a)    (~(a))
#    define Shiftl(a,b) ((a) << (b))
#    define Shiftr(a,b) ((a) >> (b))
#    if defined(CRAY1)
#      define PopCnt(a)     _popcnt(a)
#      define FirstOne(a)   _leadz(a)
#      define LastOne(a)    _leadz((a)^(a-1))
#      define Mask(a)       _mask(a)
#      define mask_1        _mask(1)
#      define mask_2        _mask(2)
#      define mask_3        _mask(3)
#      define mask_4        _mask(4)
#      define mask_8        _mask(8)
#      define mask_16       _mask(16)
#      define mask_32       _mask(32)
#      define mask_72       _mask(72)
#      define mask_80       _mask(80)
#      define mask_85       _mask(85)
#      define mask_96       _mask(96)
#      define mask_107      _mask(107)
#      define mask_108      _mask(108)
#      define mask_112      _mask(112)
#      define mask_118      _mask(118)
#      define mask_120      _mask(120)
#      define mask_121      _mask(121)
#      define mask_127      _mask(127)
#    endif
#  endif
#  define ABSearch(alpha,beta,wtm,depth,ply,donull)              \
(((depth) >= INCREMENT_PLY) ?                                 \
Search(alpha,beta,wtm,depth,ply,donull) :                  \
Quiesce(alpha,beta,wtm,ply))
#  define Max(a,b)  (((a) > (b)) ? (a) : (b))
#  define Min(a,b)  (((a) < (b)) ? (a) : (b))
#  define FileDistance(a,b) abs(((a)&7) - ((b)&7))
#  define RankDistance(a,b) abs(((a)>>3) - ((b)>>3))
#  define Distance(a,b) Max(FileDistance(a,b),RankDistance(a,b))
#  define Check(wtm)                                                     \
Attacked((wtm)?WhiteKingSQ:BlackKingSQ,ChangeSide(wtm))
#  define Attack(square,queen,ply) !And(obstructed[square][queen],Occupied)
#  define AttacksRook(a)    Or(AttacksRank(a),AttacksFile(a))
#  define AttacksBishop(a)  Or(AttacksDiaga1(a),AttacksDiagh1(a))
#  define AttacksQueen(a)   Or(AttacksBishop(a),AttacksRook(a))
#  define Rank(x)       (((x)>>3)&7)
#  define File(x)       ((x)&7)
#  define ChangeSide(x) ((x)^1)
#  define AttacksRank(a)                                               \
rook_attacks_r0[(a)][And(Shiftr(Or(search.w_occupied,search.b_occupied),\
56-((a)&56)),255)]
#  define AttacksFile(a)                                               \
rook_attacks_rl90[(a)][And(Shiftr(search.occupied_rl90,   \
56-(((a)&7)<<3)),255)]
#  define AttacksDiaga1(a)                                             \
bishop_attacks_rl45[(a)][And(Shiftr(search.occupied_rl45, \
bishop_shift_rl45[(a)]),255)]
#  define AttacksDiagh1(a)                                             \
bishop_attacks_rr45[(a)][And(Shiftr(search.occupied_rr45, \
bishop_shift_rr45[(a)]),255)]
#  define MobilityRook(a)   (MobilityRank(a)+MobilityFile(a))
#  define MobilityBishop(a) (MobilityDiaga1(a)+MobilityDiagh1(a))
#  define MobilityQueen(a)  (MobilityBishop(a)+MobilityRook(a))
#  define MobilityRank(a)                                                   \
rook_mobility_r0[(a)][And(Shiftr(Or(search.w_occupied,search.b_occupied),            \
56-((a)&56)),255)]
#  define MobilityFile(a)                                                   \
rook_mobility_rl90[(a)][And(Shiftr(search.occupied_rl90,   \
56-(((a)&7)<<3)),255)]
#  define MobilityDiaga1(a)                                                 \
bishop_mobility_rl45[(a)][And(Shiftr(search.occupied_rl45, \
bishop_shift_rl45[(a)]),255)]
#  define MobilityDiagh1(a)                                                 \
bishop_mobility_rr45[(a)][And(Shiftr(search.occupied_rr45, \
bishop_shift_rr45[(a)]),255)]
#  define From(a)             ((a)&63)
#  define To(a)               (((a)>>6)&63)
#  define Piece(a)            (((a)>>12)&7)
#  define Captured(a)         (((a)>>15)&7)
#  define Promote(a)          (((a)>>18)&7)
#  define CaptureOrPromote(a) (((a)>>15)&63)
#  define SetMask(a)          (set_mask[a])
#  define ClearMask(a)        (clear_mask[a])
#  define BlackPawns            search.b_pawn
#  define BlackKnights          search.b_knight
#  define BlackBishops          search.b_bishop
#  define BlackRooks            search.b_rook
#  define BlackQueens           search.b_queen
#  define BlackKing             set_mask[search.black_king]
#  define BlackKingSQ           search.black_king
#  define BlackCastle(ply)      position[ply].b_castle
#  define TotalBlackPawns       search.black_pawns
#  define TotalBlackPieces      search.black_pieces
#  define TotalBlackMaterial    search.black_pieces+search.black_pawns
#  define BlackPieces           search.b_occupied
#  define WhitePawns            search.w_pawn
#  define WhiteKnights          search.w_knight
#  define WhiteBishops          search.w_bishop
#  define WhiteRooks            search.w_rook
#  define WhiteQueens           search.w_queen
#  define WhiteKing             set_mask[search.white_king]
#  define WhiteKingSQ           search.white_king
#  define WhiteCastle(ply)      position[ply].w_castle
#  define TotalWhitePawns       search.white_pawns
#  define TotalWhitePieces      search.white_pieces
#  define TotalWhiteMaterial    search.white_pieces+search.white_pawns
#  define WhitePieces           search.w_occupied
#  define TotalPieces           search.total_pieces
#  define Material              search.material_evaluation
#  define Rule50Moves(ply)      position[ply].rule_50_moves
#  define HashKey               search.hash_key
#  define PawnHashKey           search.pawn_hash_key
#  define EnPassant(ply)        position[ply].enpassant_target
#  define EnPassantTarget(ply)  (EnPassant(ply) ? set_mask[EnPassant(ply)] : 0)
#  define PieceOnSquare(sq)     search.board[sq]
#  define BishopsQueens         search.bishops_queens
#  define RooksQueens           search.rooks_queens
#  define Occupied              Or(search.w_occupied,search.b_occupied)
#  define OccupiedRL90          search.occupied_rl90
#  define OccupiedRL45          search.occupied_rl45
#  define OccupiedRR45          search.occupied_rr45
#  define Sliding(piece)        ((piece) & 4)
#  define SlidingDiag(piece)    (((piece) & 5) == 5)
#  define SlidingRow(piece)     (((piece) & 6) == 6)
#  define ClearSet(a,b)  b=Xor(a,b)
#  define Clear(a,b)     b=And(clear_mask[a],b)
#  define ClearRL90(a,b) b=And(clear_mask_rl90[a],b)
#  define ClearRL45(a,b) b=And(clear_mask_rl45[a],b)
#  define ClearRR45(a,b) b=And(clear_mask_rr45[a],b)
#  define Set(a,b)       b=Or(set_mask[a],b)
#  define SetRL90(a,b)   b=Or(set_mask_rl90[a],b)
#  define SetRL45(a,b)   b=Or(set_mask_rl45[a],b)
#  define SetRR45(a,b)   b=Or(set_mask_rr45[a],b)
#  define HashPB32(a,b)       b=b_pawn_random32[a]^(b)
#  define HashPW32(a,b)       b=w_pawn_random32[a]^(b)
#  define HashPB(a,b)         b=Xor(b_pawn_random[a],b)
#  define HashPW(a,b)         b=Xor(w_pawn_random[a],b)
#  define HashNB(a,b)         b=Xor(b_knight_random[a],b)
#  define HashNW(a,b)         b=Xor(w_knight_random[a],b)
#  define HashBB(a,b)         b=Xor(b_bishop_random[a],b)
#  define HashBW(a,b)         b=Xor(w_bishop_random[a],b)
#  define HashRB(a,b)         b=Xor(b_rook_random[a],b)
#  define HashRW(a,b)         b=Xor(w_rook_random[a],b)
#  define HashQB(a,b)         b=Xor(b_queen_random[a],b)
#  define HashQW(a,b)         b=Xor(w_queen_random[a],b)
#  define HashKB(a,b)         b=Xor(b_king_random[a],b)
#  define HashKW(a,b)         b=Xor(w_king_random[a],b)
#  define HashEP(a,b)         b=Xor(enpassant_random[a],b)
#  define HashCastleW(a,b)    b=Xor(castle_random_w[a],b);
#  define HashCastleB(a,b)    b=Xor(castle_random_b[a],b);
#  define SavePV(ply,value,ph) do {\
pv[ply-1].path[ply-1]=current_move[ply-1];\
pv[ply-1].path_length=ply-1; \
pv[ply-1].path_hashed=ph; \
pv[ply-1].path_iteration_depth=iteration_depth;} while(0)
#  define SavePVS(ply,value,ph) do {\
pv[ply-1].path[ply-1]=current_move[ply-1];\
pv[ply-1].path_length=ply-1; \
pv[ply-1].path_hashed=ph; \
pv[ply-1].path_iteration_depth=iteration_depth; \
SearchOutput(value,beta);} while(0)
#endif
/* 当前文件是D:\Read\initdata.h*/

/* 当前文件是D:\Read\data.c*/

/* 当前文件是D:\Read\evaluate.h*/

#if !defined(EVALUATE_INCLUDED)
#  define    EVALUATE_INCLUDED
#  define                                 DRAW           (0)
#  define                       PAWN_UNBLOCKED           (4)
#  define                         PAWN_BLOCKED           (1)
#  define                        PAWN_ISOLATED          (12)
#  define                         PAWN_DOUBLED           (2)
#  define                         PAWN_WEAK_P1           (7)
#  define                         PAWN_WEAK_P2          (11)
#  define                          PAWN_PASSED           (4)
#  define           PAWN_PROTECTED_PASSER_WINS          (11)
#  define                         CENTER_PAWNS           (5)
#  define                       PAWN_ADVANCE_A          (-1)
#  define                       PAWN_ADVANCE_B          (-1)
#  define                       PAWN_ADVANCE_C           (1)
#  define                       PAWN_ADVANCE_D           (1)
#  define                       PAWN_ADVANCE_E           (1)
#  define                       PAWN_ADVANCE_F          (-1)
#  define                       PAWN_ADVANCE_G          (-1)
#  define                       PAWN_ADVANCE_H          (-1)
#  define                    PAWN_ADVANCE_BC_A          (-1)
#  define                    PAWN_ADVANCE_BC_B          (-1)
#  define                    PAWN_ADVANCE_BC_C           (1)
#  define                    PAWN_ADVANCE_BC_D           (1)
#  define                    PAWN_ADVANCE_BC_E           (1)
#  define                    PAWN_ADVANCE_BC_F          (-1)
#  define                    PAWN_ADVANCE_BC_G          (-1)
#  define                    PAWN_ADVANCE_BC_H          (-1)
#  define                    PAWN_ADVANCE_KING           (1)
#  define                    PAWN_ADVANCE_EG_A           (1)
#  define                    PAWN_ADVANCE_EG_B           (1)
#  define                    PAWN_ADVANCE_EG_C           (1)
#  define                    PAWN_ADVANCE_EG_D           (1)
#  define                    PAWN_ADVANCE_EG_E           (1)
#  define                    PAWN_ADVANCE_EG_F           (1)
#  define                    PAWN_ADVANCE_EG_G           (1)
#  define                    PAWN_ADVANCE_EG_H           (1)
#  define          PAWN_CONNECTED_PASSED_6TH (PAWN_VALUE+20)
#  define          PAWN_SUPPORTED_PASSED_RANK2           (0)
#  define          PAWN_SUPPORTED_PASSED_RANK3           (0)
#  define          PAWN_SUPPORTED_PASSED_RANK4           (0)
#  define          PAWN_SUPPORTED_PASSED_RANK5           (8)
#  define          PAWN_SUPPORTED_PASSED_RANK6          (20)
#  define          PAWN_SUPPORTED_PASSED_RANK7          (40)
#  define                  KNIGHT_KING_TROPISM           (3)
#  define                  BISHOP_KING_TROPISM           (3)
#  define                    ROOK_KING_TROPISM           (5)
#  define                   QUEEN_KING_TROPISM          (10)
#  define                       KNIGHT_OUTPOST           (2)
#  define                       BISHOP_TRAPPED         (150)
#  define                       BISHOP_OUTPOST           (2)
#  define                      BISHOP_MOBILITY           (1)
#  define                          BISHOP_PAIR          (10)
#  define                          ROOK_ON_7TH          (10)
#  define                    ROOK_ABSOLUTE_7TH          (15)
#  define              ROOK_CONNECTED_7TH_RANK          (15)
#  define                       ROOK_OPEN_FILE           (7)
#  define             ROOK_CONNECTED_OPEN_FILE           (3)
#  define              ROOK_BEHIND_PASSED_PAWN           (3)
#  define                         ROOK_TRAPPED          (15)
#  define                       ROOK_WEAK_PAWN           (3)
#  define               QUEEN_ROOK_ON_7TH_RANK          (20)
#  define              KING_SAFETY_GOOD_BISHOP           (2)
#  define                KING_SAFETY_MATE_G2G7           (3)
#  define              KING_SAFETY_MATE_THREAT          (50)
#  define                KING_SAFETY_OPEN_FILE           (3)
#  define                       KING_BACK_RANK           (5)
#  define          KING_SAFETY_PAWN_ATTACK_4TH           (3)
#  define          KING_SAFETY_PAWN_ATTACK_5TH           (4)
#  define              KING_SAFETY_PAWN_ATTACK           (3)
#  define                KING_SAFETY_STONEWALL           (4)
#  define                  KING_SAFETY_RP_ADV1           (1)
#  define                  KING_SAFETY_RP_ADV2           (2)
#  define               KING_SAFETY_RP_TOO_FAR           (2)
#  define               KING_SAFETY_RP_MISSING           (3)
#  define             KING_SAFETY_RP_FILE_OPEN           (3)
#  define                  KING_SAFETY_NP_ADV1           (1)
#  define                  KING_SAFETY_NP_ADV2           (2)
#  define               KING_SAFETY_NP_TOO_FAR           (3)
#  define               KING_SAFETY_NP_MISSING           (4)
#  define             KING_SAFETY_NP_FILE_OPEN           (3)
#  define                  KING_SAFETY_BP_ADV1           (1)
#  define                  KING_SAFETY_BP_ADV2           (1)
#  define               KING_SAFETY_BP_TOO_FAR           (2)
#  define               KING_SAFETY_BP_MISSING           (2)
#  define             KING_SAFETY_BP_FILE_OPEN           (2)
#  define               KING_SAFETY_RP_BP_ADV1           (2)
#  define                 DEVELOPMENT_THEMATIC           (2)
#  define                  DEVELOPMENT_UNMOVED           (4)
#  define             DEVELOPMENT_BLOCKED_PAWN           (6)
#  define            DEVELOPMENT_LOSING_CASTLE          (20)
#  define              DEVELOPMENT_NOT_CASTLED          (10)
#  define              DEVELOPMENT_QUEEN_EARLY           (5)
#  define                         TRADE_PIECES           (3)
#  define                          TRADE_PAWNS           (9)
#endif
#define     VERSION                             "14.3"
char      version[6] =                    {VERSION};
PLAYING_MODE mode =                     normal_mode;
int       batch_mode =                            0;
int       crafty_rating =                      2500;
int       opponent_rating =                    2500;
char      pgn_event[32] = {"Private Match"};
char      pgn_site[32] = {"Birmingham, AL"};
char      pgn_date[32] = {"????.??.??"};
char      pgn_round[32] = {"1"};
char      pgn_white[64] = {"unknown"};
char      pgn_white_elo[32] = {""};
char      pgn_black[64] = {"Crafty " VERSION};
char      pgn_black_elo[32] = {""};
char      pgn_result[32] = {"*"};
int       number_auto_kibitzers =                 8;
char      auto_kibitz_list[100][20] = {
{"diepx"},
{"ferret"},
{"knightc"},
{"knightcap"},
{"nowx"},
{"rajah"},
{"tcb"},
{"zarkovx"}};
int       number_of_computers =                  80;
char      computer_list[100][20] = {
{"abner"},
{"aragorn"},
{"babyblue"},
{"ban"},
{"bigblue"},
{"bikerbabe"},
{"bobbyfischer"},
{"braincan"},
{"brause"},
{"carokann"},
{"chameleon"},
{"chesskid"},
{"chesst"},
{"chessica"},
{"chesscomputer"},
{"chinook"},
{"crazyknight"},
{"cstal-x"},
{"deep-modem"},
{"deepviolet"},
{"diep"},
{"diepx"},
{"destroyer"},
{"doctorwho"},
{"dominator"},
{"dustbin"},
{"ego-crusher"},
{"ferret"},
{"fitter"},
{"fritzpentium"},
{"futuregm"},
{"gammaray"},
{"gazaboy"},
{"gballa"},
{"gnusurf"},
{"hiarcs"},
{"kerrigan"},
{"knightc"},
{"knightcap"},
{"kingtwoft"},
{"killerchess"},
{"killergrob"},
{"klamath"},
{"lightpurple"},
{"lonnie"},
{"lynnett"},
{"mchesspro"},
{"mephistoiii"},
{"netsurfer"},
{"norpico"},
{"nowx"},
{"otter"},
{"pecabale"},
{"phibs"},
{"rajah"},
{"ratbert"},
{"rdx"},
{"rebel"},
{"rebel8"},
{"robocop"},
{"roborvl"},
{"selectric"},
{"shredder"},
{"silmaril"},
{"spectronic"},
{"stobor"},
{"tcb"},
{"theextreme"},
{"tingle"},
{"turbocrafty"},
{"turbogm"},
{"ultragnu"},
{"viktor2000"},
{"virtualmachine"},
{"wchess"},
{"wchessx"},
{"wheeler"},
{"whoknows"},
{"zarkovx"},
{"zuntsu"}};
int       number_of_GMs =                        27;
char      GM_list[100][20] =       {
{"anat"},
{"badviking"},
{"devin"},
{"cleaner"},
{"dgurevich"},
{"dlugy"},
{"flamingskull"},
{"gum"},
{"gmsoffer"},
{"junior"},
{"kaidanov"},
{"kc"},
{"kevlar"},
{"kingloek"},
{"kudrin"},
{"logofet"},
{"lombardy"},
{"mohegan"},
{"pnin"},
{"psakhis"},
{"roman"},
{"sagalchik"},
{"securitron"},
{"smirin"},
{"stefansson"},
{"silvester"},
{"wbrowne"}};
int       number_of_IMs =                        11;
char      IM_list[100][20] =       {
{"adolf"},
{"badviking"},
{"bandora"},
{"imorlov"},
{"impolzin"},
{"laflair"},
{"lsokol"},
{"oed"},
{"thutters"},
{"thumpster"},
{"tim"}};
int       ics =                                   0;
int       output_format =                         0;
int       EGTBlimit =                             5;
int       xboard =                                0;
int       whisper =                               0;
int       channel =                               0;
int       early_exit =                           99;
int       new_game =                              0;
char      channel_title[32] =                  {""};
int       initialized =                           0;
int       kibitz =                                0;
int       post =                                  0;
int       log_id =                                1;
int       move_number =                           1;
int       wtm =                                   1;
int       crafty_is_white =                       0;
int       last_opponent_move =                    0;
int       largest_positional_score =            100;
int       search_depth =                          0;
int       search_move =                           0;
TIME_TYPE time_type =                       elapsed;
int       nodes_between_time_checks =         10000;
int       nodes_per_second =                  10000;
int       predicted =                             0;
int       time_used =                             0;
int       time_used_opponent =                    0;
int       auto_kibitzing =                        0;
signed char transposition_id =                    0;
int       opening =                               1;
int       middle_game =                           0;
int       end_game =                              0;
signed char thinking =                            0;
signed char pondering =                           0;
signed char puzzling =                            0;
signed char booking =                             0;
int       analyze_mode =                          0;
int       annotate_mode =                         0;
int       test_mode =                             0;
int       analyze_move_read =                     0;
signed char resign =                              5;
signed char resign_counter =                      0;
signed char resign_count =                        5;
signed char draw_counter =                        0;
signed char draw_count =                         10;
int       tc_moves =                             60;
int       tc_time =                          180000;
int       tc_time_remaining =                180000;
int       tc_time_remaining_opponent =       180000;
int       tc_moves_remaining =                   60;
int       tc_secondary_moves =                   30;
int       tc_secondary_time =                 90000;
int       tc_increment =                          0;
int       tc_sudden_death =                       0;
int       tc_operator_time =                      0;
int       tc_safety_margin =                      0;
int       time_limit =                          100;
int       force =                                 0;
char      initial_position[80] =               {""};
int       over =                                  0;
int       draw_score_is_zero =                    0;
int       usage_level =                           0;
char      audible_alarm =                         0;
int       ansi =                                  1;
int       book_accept_mask =                    ~03;
int       book_reject_mask =                      3;
int       book_random =                           3;
int       book_search_trigger =                  20;
int       learning =                              3;
int       moves_out_of_book =                     0;
int       show_book =                             0;
int       book_selection_width =                  5;
int       ponder =                                1;
int       trace_level =                           0;
int       verbosity_level =                       9;
unsigned int noise_level =                    10000;
int       hash_table_size =                    8192;
int       log_hash =                             13;
int       pawn_hash_table_size =               4096;
int       log_pawn_hash =                        12;
int       default_draw_score =                 DRAW;
int       passed_pawn_value[8] = { 0,
PAWN_PASSED*2, PAWN_PASSED*3,
PAWN_PASSED*4, PAWN_PASSED*6,
PAWN_PASSED*9, PAWN_PASSED*12,
0};
int       supported_passer[8] =  { 0,
PAWN_SUPPORTED_PASSED_RANK2,
PAWN_SUPPORTED_PASSED_RANK3,
PAWN_SUPPORTED_PASSED_RANK4,
PAWN_SUPPORTED_PASSED_RANK5,
PAWN_SUPPORTED_PASSED_RANK6,
PAWN_SUPPORTED_PASSED_RANK7,
0};
int       reduced_material_passer[20] = { 10,10,9,9,8,8,7,7,6,6,
5,5,4,4,3,3,2,2,1,1};
int       outside_passed[128] = { 30, 30, 27, 27, 27, 25, 24, 23,
22, 21, 20, 19, 18, 17, 16, 15,
14, 13, 12, 11, 10,  9,  8,  7,
6,  5,  4,  3,  2,  1,  1,  1,
1,  1,  1,  1,  1,  1,  1,  1,
1,  1,  1,  1,  1,  1,  1,  1,
1,  1,  1,  1,  1,  1,  1,  1,
1,  1,  1,  1,  1,  1,  1,  1,
1,  1,  1,  1,  1,  1,  1,  1,
1,  1,  1,  1,  1,  1,  1,  1,
1,  1,  1,  1,  1,  1,  1,  1,
1,  1,  1,  1,  1,  1,  1,  1,
1,  1,  1,  1,  1,  1,  1,  1,
1,  1,  1,  1,  1,  1,  1,  1,
1,  1,  1,  1,  1,  1,  1,  1,
1,  1,  1,  1,  1,  1,  1,  1};
char      square_color[64]  = { 1, 0, 1, 0, 1, 0, 1, 0,
0, 1, 0, 1, 0, 1, 0, 1,
1, 0, 1, 0, 1, 0, 1, 0,
0, 1, 0, 1, 0, 1, 0, 1,
1, 0, 1, 0, 1, 0, 1, 0,
0, 1, 0, 1, 0, 1, 0, 1,
1, 0, 1, 0, 1, 0, 1, 0,
0, 1, 0, 1, 0, 1, 0, 1 };
int       b_n_mate_dark_squares[64] =
{ 20, 15, 10,  5, -5,-10,-15,-20,
15, 15, 10,  5, -5,-10,-15,-15,
10, 10, 10,  5, -5,-10,-10,-10,
5,  5,  5,  5, -5, -5, -5, -5,
-5, -5, -5, -5,  5,  5,  5,  5,
-10,-10,-10, -5,  5, 10, 10, 10,
-15,-15,-10, -5,  5, 10, 15, 15,
-20,-15,-10, -5,  5, 10, 15, 20};
int       b_n_mate_light_squares[64] =
{-20,-15,-10, -5,  5, 10, 15, 20,
-15,-15,-10, -5,  5, 10, 15, 15,
-10,-10,-10, -5,  5, 10, 10, 10,
-5, -5, -5, -5,  5,  5,  5,  5,
5,  5,  5,  5, -5, -5, -5, -5,
10, 10, 10,  5, -5,-10,-10,-10,
15, 15, 10,  5, -5,-10,-15,-15,
20, 15, 10,  5, -5,-10,-15,-20};
int       mate[64] =        {28, 26, 24, 22, 22, 24, 26, 28,
26, 16, 14, 12, 12, 14, 16, 26,
24, 14,  4,  2,  2,  4, 14, 24,
22, 12,  2,  0,  0,  2, 12, 22,
22, 12,  2,  0,  0,  2, 12, 22,
24, 14,  4,  2,  2,  4, 14, 24,
26, 16, 14, 12, 12, 14, 16, 26,
28, 26, 24, 22, 22, 24, 26, 28};
char            white_outpost[64] = { 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 2, 2, 0, 0, 0,
0, 0, 4, 5, 5, 4, 0, 0,
0, 0, 3, 6, 6, 3, 0, 0,
0, 0, 0, 1, 1, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0 };
char            black_outpost[64] = { 0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 1, 1, 0, 0, 0,
0, 0, 3, 6, 6, 3, 0, 0,
0, 0, 4, 5, 5, 4, 0, 0,
0, 0, 0, 2, 2, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0 };
char           push_extensions[64] = { 0, 0, 0, 0, 0, 0, 0, 0,
1, 1, 1, 1, 1, 1, 1, 1,
0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0,
1, 1, 1, 1, 1, 1, 1, 1,
0, 0, 0, 0, 0, 0, 0, 0 };
int    pawn_value_b[64] = { 0,  0,  0,  0,  0,  0,  0,  0,
0,  0,  0,  0,  0,  0,  0,  0,
0,  0,  3,  3,  3,  3,  0,  0,
0,  0,  3,  3,  3,  3,  0,  0,
0,  0,  0,  3,  3,  0,  0,  0,
0,  0,  0,  0,  0,  0,  0,  0,
0,  0,  0,  0,  0,  0,  0,  0,
0,  0,  0,  0,  0,  0,  0,  0};
int    pawn_value_w[64] = { 0,  0,  0,  0,  0,  0,  0,  0,
0,  0,  0,  0,  0,  0,  0,  0,
0,  0,  0,  0,  0,  0,  0,  0,
0,  0,  0,  3,  3,  0,  0,  0,
0,  0,  3,  3,  3,  3,  0,  0,
0,  0,  3,  3,  3,  3,  0,  0,
0,  0,  0,  0,  0,  0,  0,  0,
0,  0,  0,  0,  0,  0,  0,  0};
int  knight_value_w[64] = { -9, -3, -3, -2, -2, -3, -3,  -9,
-5, -3, -1,  0,  0, -1, -3,  -5,
-6,  0,  1,  1,  1,  1,  0,  -6,
-5,  0,  1,  2,  2,  1,  0,  -5,
-5,  0,  1,  2,  2,  1,  0,  -5,
-5,  0,  1,  1,  1,  1,  0,  -5,
-5,  0,  0,  0,  0,  0,  0,  -5,
-10, -5, -5, -5, -5, -5, -5, -10};
int  knight_value_b[64] ={ -10, -5, -5, -5, -5, -5, -5, -10,
-5,  0,  0,  0,  0,  0,  0,  -5,
-5,  0,  1,  1,  1,  1,  0,  -5,
-5,  0,  1,  2,  2,  1,  0,  -5,
-5,  0,  1,  2,  2,  1,  0,  -5,
-6,  0,  1,  1,  1,  1,  0,  -6,
-5, -3, -1,  0,  0, -1, -3,  -5,
-9, -3, -3, -2, -2, -3, -3,  -9};
int  bishop_value_w[64] = { -3, -3, -3, -3, -3, -3, -3, -3,
-3,  0,  0,  0,  0,  0,  0, -3,
-3,  0,  2,  2,  2,  2,  0, -2,
-3,  0,  2,  3,  3,  2,  0, -3,
-3,  0,  2,  3,  3,  2,  0, -3,
-3,  0,  2,  2,  2,  2,  0, -3,
-3,  0,  0,  0,  0,  0,  0, -3,
-3, -3, -3, -3, -3, -3, -3, -3};
int  bishop_value_b[64] = { -3, -3, -3, -3, -3, -3, -3, -3,
-3,  0,  0,  0,  0,  0,  0, -3,
-3,  0,  2,  2,  2,  2,  0, -3,
-3,  0,  2,  3,  3,  2,  0, -3,
-3,  0,  2,  3,  3,  2,  0, -3,
-3,  0,  2,  2,  2,  2,  0, -3,
-3,  0,  0,  0,  0,  0,  0, -3,
-3, -3, -3, -3, -3, -3, -3, -3};
int    rook_value_w[64] = {  0,  2,  3,  4,  4,  3,  2,  0,
-4,  2,  3,  4,  4,  3,  2, -4,
-4,  2,  3,  4,  4,  3,  2, -4,
-4,  2,  3,  4,  4,  3,  2, -4,
0,  2,  3,  4,  4,  3,  2,  0,
0,  2,  3,  4,  4,  3,  2,  0,
0,  2,  3,  4,  4,  3,  2,  0,
0,  2,  3,  4,  4,  3,  2,  0};
int    rook_value_b[64] = {  0,  2,  3,  4,  4,  3,  2,  0,
0,  2,  3,  4,  4,  3,  2,  0,
0,  2,  3,  4,  4,  3,  2,  0,
0,  2,  3,  4,  4,  3,  2,  0,
-4,  2,  3,  4,  4,  3,  2, -4,
-4,  2,  3,  4,  4,  3,  2, -4,
-4,  2,  3,  4,  4,  3,  2, -4,
0,  2,  3,  4,  4,  3,  2,  0};
int   queen_value_w[64] = {  0,  0,  0,  0,  0,  0,  0,  0,
0,  2,  2,  2,  2,  2,  2,  0,
0,  2,  4,  5,  5,  4,  2,  0,
0,  2,  4,  6,  6,  4,  2,  0,
0,  2,  4,  6,  6,  4,  2,  0,
0,  2,  4,  6,  6,  4,  2,  0,
0,  2,  4,  5,  5,  4,  2,  0,
0,  0,  0,  0,  0,  0,  0,  0};
int   queen_value_b[64] = {  0,  0,  0,  0,  0,  0,  0,  0,
0,  2,  4,  5,  5,  4,  2,  0,
0,  2,  4,  6,  6,  4,  2,  0,
0,  2,  4,  6,  6,  4,  2,  0,
0,  2,  4,  6,  6,  4,  2,  0,
0,  2,  4,  5,  5,  4,  2,  0,
0,  2,  2,  2,  2,  2,  2,  0,
0,  0,  0,  0,  0,  0,  0,  0};
int    king_value_w[64] = { -3,  0,  0,  0,  0,  0,  0, -3,
0,  0,  3,  3,  3,  3,  0,  0,
0,  3,  3,  5,  5,  3,  3,  0,
0,  3,  5,  8,  8,  5,  3,  0,
0,  3,  5,  8,  8,  5,  3,  0,
0,  3,  3,  5,  5,  3,  3,  0,
0,  0,  3,  3,  3,  3,  0,  0,
-3,  0,  0,  0,  0,  0,  0, -3};
int    king_value_b[64] = { -3,  0,  0,  0,  0,  0,  0, -3,
0,  0,  3,  3,  3,  3,  0,  0,
0,  3,  3,  5,  5,  3,  3,  0,
0,  3,  5,  8,  8,  5,  3,  0,
0,  3,  5,  8,  8,  5,  3,  0,
0,  3,  3,  5,  5,  3,  3,  0,
0,  0,  3,  3,  3,  3,  0,  0,
-3,  0,  0,  0,  0,  0,  0, -3};
char king_defects_w[64]= { 4, 3, 2, 3, 3, 1, 1, 2,
4, 3, 3, 7, 7, 3, 2, 2,
6, 4, 6, 7, 7, 6, 4, 6,
8, 5, 6, 8, 8, 6, 5, 8,
8, 5, 6, 8, 8, 6, 5, 8,
8, 5, 6, 8, 8, 6, 5, 8,
8, 5, 6, 8, 8, 6, 5, 8,
8, 5, 6, 8, 8, 6, 5, 8};
char king_defects_b[64]= { 8, 5, 6, 8, 8, 6, 5, 8,
8, 5, 6, 8, 8, 6, 5, 8,
8, 5, 6, 8, 8, 6, 5, 8,
8, 5, 6, 8, 8, 6, 5, 8,
8, 5, 6, 8, 8, 6, 5, 8,
6, 4, 6, 7, 7, 6, 4, 6,
4, 3, 3, 7, 7, 3, 2, 2,
4, 3, 2, 3, 3, 1, 1, 2};
int       p_values[15] =       {QUEEN_VALUE,ROOK_VALUE,BISHOP_VALUE,0,
KING_VALUE,KNIGHT_VALUE,PAWN_VALUE,
0,PAWN_VALUE,KNIGHT_VALUE,KING_VALUE,
0, BISHOP_VALUE,ROOK_VALUE,QUEEN_VALUE};
int       unblocked_pawns[9] = {-PAWN_UNBLOCKED*2,0,PAWN_UNBLOCKED,
PAWN_UNBLOCKED*2, PAWN_UNBLOCKED*3,
PAWN_UNBLOCKED*4, PAWN_UNBLOCKED*5,
PAWN_UNBLOCKED*6, PAWN_UNBLOCKED*7};
int            bishop_shift_rl45[64] = { 63, 61, 58, 54, 49, 43, 36, 28,
61, 58, 54, 49, 43, 36, 28, 21,
58, 54, 49, 43, 36, 28, 21, 15,
54, 49, 43, 36, 28, 21, 15, 10,
49, 43, 36, 28, 21, 15, 10,  6,
43, 36, 28, 21, 15, 10,  6,  3,
36, 28, 21, 15, 10,  6,  3,  1,
28, 21, 15, 10,  6,  3,  1,  0 };
int            bishop_shift_rr45[64] = { 28, 36, 43, 49, 54, 58, 61, 63,
21, 28, 36, 43, 49, 54, 58, 61,
15, 21, 28, 36, 43, 49, 54, 58,
10, 15, 21, 28, 36, 43, 49, 54,
6, 10, 15, 21, 28, 36, 43, 49,
3,  6, 10, 15, 21, 28, 36, 43,
1,  3,  6, 10, 15, 21, 28, 36,
0,  1,  3,  6, 10, 15, 21, 28 };
/*initdata.h continue*/
#if !defined(DATA_INCLUDED)
#  define DATA_INCLUDED

int            total_moves;
FILE           *input_stream;
FILE           *book_file;
FILE           *books_file;
FILE           *history_file;
FILE           *log_file;
FILE           *auto_file;
FILE           *book_lrn_file;
FILE           *position_file;
FILE           *position_lrn_file;
char           whisper_text[500];
int            whisper_value;
int            whisper_depth;
int            last_mate_score;
char           log_filename[64];
char           history_filename[64];
int            number_of_solutions;
int            solutions[10];
int            solution_type;
int            auto232;
int            auto232_delay;
char           book_path[128];
char           log_path[128];
char           tb_path[128];
char           cmd_buffer[512];
char           *args[32];
char           buffer[512];
int            nargs;
int            iteration_depth;
int            last_search_value;
int            previous_search_value;
int            search_failed_high;
int            search_failed_low;
int            root_alpha;
int            root_beta;
int            root_value;
int            root_wtm;
int            root_move;
int            root_total_white_pieces;
int            root_total_white_pawns;
int            root_total_black_pieces;
int            root_total_black_pawns;
int            cpu_percent;
int            tb_probes;
int            tb_probes_successful;
char           hint[16];
int            easy_move;
int            absolute_time_limit;
int            search_time_limit;
int            next_time_check;
int            time_abort;
#if 0
signed char    pondering;
signed char    thinking;
signed char    puzzling;
signed char    booking;
#endif
signed char    abort_search;
int            ponder_move;
int            made_predicted_move;
int            ponder_moves[220];
int            num_ponder_moves;
unsigned int   opponent_start_time, opponent_end_time;
unsigned int   program_start_time, program_end_time;
unsigned int   start_time, end_time;
unsigned int   elapsed_start, elapsed_end;
unsigned int   nodes_searched;
unsigned int   evaluations;
int            transposition_probes;
int            transposition_hits;
int            pawn_probes;
int            pawn_hits;
int            check_extensions_done;
int            recapture_extensions_done;
int            passed_pawn_extensions_done;
int            one_reply_extensions_done;
int            burp;
int            book_move;
int            log_hash;
int            pawn_hash_table_size;
int            hash_maska;
int            hash_maskb;
unsigned int   pawn_hash_mask;
HASH_ENTRY      *trans_ref_wa;
HASH_ENTRY      *trans_ref_wb;
HASH_ENTRY      *trans_ref_ba;
HASH_ENTRY      *trans_ref_bb;
PAWN_HASH_ENTRY *pawn_hash_table;
int            hash_move[MAXPLY];
int            history_w[4096], history_b[4096];
int            killer_move1[MAXPLY];
int            killer_move2[MAXPLY];
int            killer_count1[MAXPLY];
int            killer_count2[MAXPLY];
BITBOARD       replist_w[50+MAXPLY/2];
BITBOARD       replist_b[50+MAXPLY/2];
BITBOARD       *rephead_w;
BITBOARD       *rephead_b;
int            unblocked_pawns[9];
int            p_values[15];
int            current_move[MAXPLY];
int            *last[MAXPLY];
signed char    in_check[MAXPLY];
signed char    extended_reason[MAXPLY];
signed char    current_phase[MAXPLY];
int            move_list[5120];
int            sort_value[256];
signed char    searched_this_root_move[256];
unsigned int   root_nodes[256];
CHESS_PATH     pv[MAXPLY];
CHESS_PATH     last_pv;
int            last_value;
NEXT_MOVE      next_status[MAXPLY];
SEARCH_POSITION position[MAXPLY+2];
BITBOARD       save_hash_key[MAXPLY+2];
unsigned int   save_pawn_hash_key[MAXPLY+2];
char           white_outpost[64];
char           black_outpost[64];
char           square_color[64];
int            passed_pawn_value[8];
int            supported_passer[8];
int            reduced_material_passer[20];
int            pawn_advance[8];
int            outside_passed[128];
int            pawn_value_w[64];
int            pawn_value_b[64];
int            knight_value_w[64];
int            knight_value_b[64];
int            bishop_value_w[64];
int            bishop_value_b[64];
int            rook_value_w[64];
int            rook_value_b[64];
int            queen_value_w[64];
int            queen_value_b[64];
int            king_value_w[64];
int            king_value_b[64];
char           king_defects_w[64];
char           king_defects_b[64];
int            b_n_mate_dark_squares[64];
int            b_n_mate_light_squares[64];
int            mate[64];
char           push_extensions[64];
signed char    directions[64][64];
BITBOARD       w_pawn_attacks[64];
BITBOARD       b_pawn_attacks[64];
BITBOARD       knight_attacks[64];
BITBOARD       bishop_attacks[64];
BITBOARD       bishop_attacks_rl45[64][256];
BITBOARD       bishop_attacks_rr45[64][256];
int            bishop_mobility_rl45[64][256];
int            bishop_mobility_rr45[64][256];
int            bishop_shift_rl45[64];
int            bishop_shift_rr45[64];
BITBOARD       rook_attacks[64];
BITBOARD       rook_attacks_r0[64][256];
BITBOARD       rook_attacks_rl90[64][256];
int            rook_mobility_r0[64][256];
int            rook_mobility_rl90[64][256];
CHESS_POSITION search;
CHESS_POSITION display;
BITBOARD       queen_attacks[64];
BITBOARD       king_attacks[64];
BITBOARD       king_attacks_1[64];
BITBOARD       king_attacks_2[64];
BITBOARD       obstructed[64][64];
unsigned int   w_pawn_random32[64];
unsigned int   b_pawn_random32[64];
BITBOARD       w_pawn_random[64];
BITBOARD       b_pawn_random[64];
BITBOARD       w_knight_random[64];
BITBOARD       b_knight_random[64];
BITBOARD       w_bishop_random[64];
BITBOARD       b_bishop_random[64];
BITBOARD       w_rook_random[64];
BITBOARD       b_rook_random[64];
BITBOARD       w_queen_random[64];
BITBOARD       b_queen_random[64];
BITBOARD       w_king_random[64];
BITBOARD       b_king_random[64];
BITBOARD       enpassant_random[65];
BITBOARD       castle_random_w[2];
BITBOARD       castle_random_b[2];
BITBOARD       wtm_random[2];
BITBOARD       endgame_random_w;
BITBOARD       endgame_random_b;
BITBOARD       w_rooks_random;
BITBOARD       b_rooks_random;
BITBOARD       clear_mask[65];
BITBOARD       clear_mask_rl45[65];
BITBOARD       clear_mask_rr45[65];
BITBOARD       clear_mask_rl90[65];
BITBOARD       set_mask[65];
BITBOARD       set_mask_rl45[65];
BITBOARD       set_mask_rr45[65];
BITBOARD       set_mask_rl90[65];
BITBOARD       file_mask[8];
BITBOARD       rank_mask[8];
BITBOARD       mask_not_rank8;
BITBOARD       mask_not_rank1;
BITBOARD       right_side_mask[8];
BITBOARD       left_side_mask[8];
BITBOARD       right_side_empty_mask[8];
BITBOARD       left_side_empty_mask[8];
BITBOARD       right_half_mask, left_half_mask;
BITBOARD       mask_abs7_w, mask_abs7_b;
BITBOARD       pawns_cramp_black;
BITBOARD       pawns_cramp_white;
BITBOARD       mask_advance_2_w;
BITBOARD       mask_advance_2_b;
BITBOARD       mask_left_edge;
BITBOARD       mask_right_edge;
BITBOARD       mask_corner_squares;
BITBOARD       promote_mask_w;
BITBOARD       promote_mask_b;
BITBOARD       mask_G2G3;
BITBOARD       mask_B2B3;
BITBOARD       mask_G6G7;
BITBOARD       mask_B6B7;
BITBOARD       mask_F3H3;
BITBOARD       mask_F6H6;
BITBOARD       mask_A3C3;
BITBOARD       mask_A6C6;
BITBOARD       mask_A7H7;
BITBOARD       mask_A2H2;
BITBOARD       center;
BITBOARD       stonewall_white;
BITBOARD       stonewall_black;
BITBOARD       mask_kr_trapped_w[3];
BITBOARD       mask_qr_trapped_w[3];
BITBOARD       mask_kr_trapped_b[3];
BITBOARD       mask_qr_trapped_b[3];
BITBOARD       good_bishop_kw;
BITBOARD       good_bishop_qw;
BITBOARD       good_bishop_kb;
BITBOARD       good_bishop_qb;
BITBOARD       light_squares;
BITBOARD       dark_squares;
BITBOARD       not_rook_pawns;
BITBOARD       plus1dir[65];
BITBOARD       plus7dir[65];
BITBOARD       plus8dir[65];
BITBOARD       plus9dir[65];
BITBOARD       minus1dir[65];
BITBOARD       minus7dir[65];
BITBOARD       minus8dir[65];
BITBOARD       minus9dir[65];
BITBOARD       mask_eptest[64];
#  if !defined(CRAY1)
BITBOARD       mask_1;
BITBOARD       mask_2;
BITBOARD       mask_3;
BITBOARD       mask_4;
BITBOARD       mask_8;
BITBOARD       mask_16;
BITBOARD       mask_32;
BITBOARD       mask_72;
BITBOARD       mask_80;
BITBOARD       mask_85;
BITBOARD       mask_96;
BITBOARD       mask_107;
BITBOARD       mask_108;
BITBOARD       mask_112;
BITBOARD       mask_118;
BITBOARD       mask_120;
BITBOARD       mask_121;
BITBOARD       mask_127;
#  endif
BITBOARD       mask_clear_entry;
#  if !defined(CRAY1)
unsigned char  first_ones[65536];
unsigned char  last_ones[65536];
#  endif
unsigned char  first_ones_8bit[256];
unsigned char  last_ones_8bit[256];
unsigned char  connected_passed[256];
BITBOARD       mask_kingside_attack_w1;
BITBOARD       mask_kingside_attack_w2;
BITBOARD       mask_kingside_attack_b1;
BITBOARD       mask_kingside_attack_b2;
BITBOARD       mask_queenside_attack_w1;
BITBOARD       mask_queenside_attack_w2;
BITBOARD       mask_queenside_attack_b1;
BITBOARD       mask_queenside_attack_b2;
BITBOARD       mask_pawn_protected_b[64];
BITBOARD       mask_pawn_protected_w[64];
BITBOARD       mask_pawn_isolated[64];
BITBOARD       mask_pawn_passed_w[64];
BITBOARD       mask_pawn_passed_b[64];
BITBOARD       mask_promotion_threat_w[64];
BITBOARD       mask_promotion_threat_b[64];
BITBOARD       mask_pawn_connected[64];
BITBOARD       mask_no_pawn_attacks_w[64];
BITBOARD       mask_no_pawn_attacks_b[64];
BITBOARD       mask_a1_corner;
BITBOARD       mask_a8_corner;
BITBOARD       mask_h1_corner;
BITBOARD       mask_h8_corner;
BITBOARD       white_minor_pieces;
BITBOARD       black_minor_pieces;
BITBOARD       white_center_pawns;
BITBOARD       black_center_pawns;
BITBOARD       white_pawn_race_wtm[64];
BITBOARD       white_pawn_race_btm[64];
BITBOARD       black_pawn_race_wtm[64];
BITBOARD       black_pawn_race_btm[64];
BITBOARD       mask_wk_4th, mask_wq_4th, mask_bk_4th, mask_bq_4th;
BITBOARD       mask_wk_5th, mask_wq_5th, mask_bk_5th, mask_bq_5th;
#endif
#if defined(UNIX) || defined(AMIGA)
//#  include <unistd.h>
#  include <pwd.h>
#  include <sys/types.h>
#endif

/* 当前文件是D:\Read\attacks.c*/

/* 当前文件是D:\Read\data.h*/

#if !defined(DATA_INCLUDED)
#  define DATA_INCLUDED
#endif
BITBOARD AttacksFrom(int square, int wtm) {
switch (abs(PieceOnSquare(square))) {
case pawn:
if (wtm) return(w_pawn_attacks[square]);
else return(b_pawn_attacks[square]);
case knight:
return(knight_attacks[square]);
case bishop:
return(AttacksBishop(square));
case rook:
return(AttacksRook(square));
case queen:
return(AttacksQueen(square));
case king:
return(king_attacks[square]);
default:
return(0);
}
}
BITBOARD AttacksTo(int square) {
register BITBOARD attacks;
attacks=And(w_pawn_attacks[square],BlackPawns);
attacks=Or(attacks,And(b_pawn_attacks[square],WhitePawns));
attacks=Or(attacks,And(knight_attacks[square],Or(BlackKnights,
WhiteKnights)));
attacks=Or(attacks,And(AttacksBishop(square),BishopsQueens));
attacks=Or(attacks,And(AttacksRook(square),RooksQueens));
attacks=Or(attacks,And(king_attacks[square],Or(BlackKing,
WhiteKing)));
return(attacks);
}
int Attacked(int square, int wtm) {
register BITBOARD attacks;
if (wtm) {
attacks=And(b_pawn_attacks[square],WhitePawns);
if (attacks) return(1);
attacks=And(knight_attacks[square],WhiteKnights);
if(attacks) return(1);
attacks=And(And(AttacksBishop(square),BishopsQueens),WhitePieces);
if(attacks) return(1);
attacks=And(And(AttacksRook(square),RooksQueens),WhitePieces);
if(attacks) return(1);
attacks=And(king_attacks[square],WhiteKing);
if(attacks) return(1);
return(0);
}
else {
attacks= And(w_pawn_attacks[square],BlackPawns);
if (attacks) return(1);
attacks=And(knight_attacks[square],BlackKnights);
if(attacks) return(1);
attacks=And(And(AttacksBishop(square),BishopsQueens),BlackPieces);
if (attacks) return(1);
attacks=And(And(AttacksRook(square),RooksQueens),BlackPieces);
if(attacks) return(1);
attacks=And(king_attacks[square],BlackKing);
if(attacks) return(1);
return(0);
}
}
/* 当前文件是D:\Read\boolean.c*/

#if !defined(CRAY1)
BITBOARD Mask(int arg1)
{
register BITBOARD i;
i=(BITBOARD) -1;
if (arg1 == 128)
return(0);
else if (arg1 > 64)
return(i>>(arg1-64));
else
return(i<<(64-arg1));
}
#if !defined(USE_ASSEMBLY_B)
int PopCnt(register BITBOARD a)
{
register int c=0;
while(a) {
c++;
a &= a - 1;
}
return(c);
}
int FirstOne(BITBOARD arg1)
{
union doub {
unsigned short i[4];
BITBOARD d;
};
#ifndef SPEC_CPU2000
register union doub x;
#else
union doub x;
#endif
x.d=arg1;
#  if defined(LITTLE_ENDIAN_ARCH)
if (x.i[3])
return (first_ones[x.i[3]]);
if (x.i[2])
return (first_ones[x.i[2]]+16);
if (x.i[1])
return (first_ones[x.i[1]]+32);
if (x.i[0])
return (first_ones[x.i[0]]+48);
#  endif
#  if !defined(LITTLE_ENDIAN_ARCH)
if (x.i[0])
return (first_ones[x.i[0]]);
if (x.i[1])
return (first_ones[x.i[1]]+16);
if (x.i[2])
return (first_ones[x.i[2]]+32);
if (x.i[3])
return (first_ones[x.i[3]]+48);
#  endif
return(64);
}
int LastOne(BITBOARD arg1)
{
union doub {
unsigned short i[4];
BITBOARD d;
};
#ifndef SPEC_CPU2000
register union doub x;
#else
union doub x;
#endif
x.d=arg1;
#  if defined(LITTLE_ENDIAN_ARCH)
if (x.i[0])
return (last_ones[x.i[0]]+48);
if (x.i[1])
return (last_ones[x.i[1]]+32);
if (x.i[2])
return (last_ones[x.i[2]]+16);
if (x.i[3])
return (last_ones[x.i[3]]);
#  endif
#  if !defined(LITTLE_ENDIAN_ARCH)
if (x.i[3])
return (last_ones[x.i[3]]+48);
if (x.i[2])
return (last_ones[x.i[2]]+32);
if (x.i[1])
return (last_ones[x.i[1]]+16);
if (x.i[0])
return (last_ones[x.i[0]]);
#  endif
return(64);
}
#  endif
#endif
/* 当前文件是D:\Read\draw.c*/

int DrawScore(void)
{
register int draw_score;
if (draw_score_is_zero) return(default_draw_score);
if (opening)
draw_score=default_draw_score-66;
else if (middle_game)
draw_score=default_draw_score-33;
else
draw_score=default_draw_score;
if (tc_increment <= 200) {
if (tc_time_remaining_opponent < 6000)
draw_score=default_draw_score-50;
if (tc_time_remaining_opponent < 3000)
draw_score=default_draw_score-100;
}
return(draw_score);
}
/* 当前文件是D:\Read\drawn.c*/

int Drawn(int value)
{
if (TotalWhitePawns || TotalBlackPawns) return(0);
if (value != DrawScore()) return(0);
if (TotalWhitePieces == TotalBlackPieces) return(1);
if (TotalWhitePieces>4 || TotalBlackPieces>4) return(0);
return(1);
}
/* 当前文件是D:\Read\edit.c*/

void Edit(void)
{
int athome=1, i, piece, readstat, square, tfile, trank, wtm=1;
char pieces[]={'x','X','P','p','N','n','K','k','*','*',
'B','b','R','r','Q','q','\0'};
while (1) {
if ((input_stream == stdin) && !xboard)
if (wtm) printf("edit(white): ");
else printf("edit(black): ");
fflush(stdout);
readstat=Read(1,buffer);
if (readstat < 0) return;
nargs=ReadParse(buffer,args," 	;");
if (xboard) printf("edit.command:%s\n",args[0]);
if (!strcmp(args[0],"white")) wtm=1;
else if (!strcmp(args[0],"black")) wtm=0;
if (!strcmp(args[0],"#"))
for (i=0;i<64;i++) PieceOnSquare(i)=0;
else if (!strcmp(args[0],"c")) wtm=ChangeSide(wtm);
else if (!strcmp(args[0],"end") || (!strcmp(args[0],"."))) break;
else if (!strcmp(args[0],"d")) DisplayChessBoard(stdout,search);
else if (strlen(args[0]) == 3) {
if (strchr(pieces,args[0][0])) {
piece=(strchr(pieces,args[0][0])-pieces) >> 1;
tfile=args[0][1]-'a';
trank=args[0][2]-'1';
square=(trank<<3)+tfile;
if ((square < 0) || (square > 63))
printf("unrecognized square %s\n",args[0]);
if (wtm) PieceOnSquare(square)=piece;
else PieceOnSquare(square)=-piece;
}
}
else if(strlen(args[0]) == 2) {
piece=pawn;
tfile=args[0][0]-'a';
trank=args[0][1]-'1';
square=(trank<<3)+tfile;
if ((square < 0) || (square > 63))
printf("unrecognized square %s\n",args[0]);
if (wtm) PieceOnSquare(square)=piece;
else PieceOnSquare(square)=-piece;
}
else printf("unrecognized piece %s\n",args[0]);
}
WhiteCastle(0)=0;
BlackCastle(0)=0;
EnPassant(0)=0;
for (i=0;i<16;i++)
if (PieceOnSquare(i)==0 || PieceOnSquare(i+48)==0) athome=0;
if (!athome ||
(PieceOnSquare(A1)==rook    && PieceOnSquare(B1)==knight &&
PieceOnSquare(C1)==bishop  && PieceOnSquare(D1)==queen &&
PieceOnSquare(E1)==king    && PieceOnSquare(F1)==bishop &&
PieceOnSquare(G1)==knight  && PieceOnSquare(H1)==rook &&
PieceOnSquare(A8)==-rook   && PieceOnSquare(B8)==-knight &&
PieceOnSquare(C8)==-bishop && PieceOnSquare(D8)==-queen &&
PieceOnSquare(E8)==-king   && PieceOnSquare(F8)==-bishop &&
PieceOnSquare(G8)==-knight && PieceOnSquare(H8)==-rook)) {
if (PieceOnSquare(E1) == king) {
if (PieceOnSquare(A1) == rook) WhiteCastle(0)=WhiteCastle(0)|2;
if (PieceOnSquare(H1) == rook) WhiteCastle(0)=WhiteCastle(0)|1;
}
if (PieceOnSquare(E8) == -king) {
if (PieceOnSquare(A8) == -rook) BlackCastle(0)=BlackCastle(0)|2;
if (PieceOnSquare(H8) == -rook) BlackCastle(0)=BlackCastle(0)|1;
}
}
SetChessBitBoards(&position[0]);
if (log_file) DisplayChessBoard(log_file,search);
wtm=1;
move_number=1;
rephead_b=replist_b;
rephead_w=replist_w;
if (wtm) *rephead_w++=HashKey;
else *rephead_b++=HashKey;
position[0].rule_50_moves=0;
moves_out_of_book=0;
largest_positional_score=60;
opening=0;
middle_game=1;
end_game=0;
}
/* 当前文件是D:\Read\enprise.c*/

int EnPrise(int target, int wtm)
{
BITBOARD white_attackers, black_attackers;
BITBOARD attacks, temp_attacks;
BITBOARD *pawns[2], *knights[2], *bishops[2],
*rooks[2], *queens[2], *kings[2];
int attacked_piece;
int square, direction;
int swap_sign, color, next_capture=0;
int swap_list[32];
temp_attacks=AttacksTo(target);
white_attackers=And(temp_attacks,WhitePieces);
black_attackers=And(temp_attacks,BlackPieces);
if (wtm) {
if (!white_attackers) return(0);
}
else {
if (!black_attackers) return(0);
}
swap_list[0]=0;
attacked_piece=p_values[PieceOnSquare(target)+7];
pawns[0]=&BlackPawns;
pawns[1]=&WhitePawns;
knights[0]=&BlackKnights;
knights[1]=&WhiteKnights;
bishops[0]=&BlackBishops;
bishops[1]=&WhiteBishops;
rooks[0]=&BlackRooks;
rooks[1]=&WhiteRooks;
queens[0]=&BlackQueens;
queens[1]=&WhiteQueens;
kings[0]=&BlackKing;
kings[1]=&WhiteKing;
swap_sign=1;
attacks=AttacksTo(target);
color=wtm;
while (attacks) {
if (And(*pawns[color],attacks))
square=FirstOne(And(*pawns[color],attacks));
else if (And(*knights[color],attacks))
square=FirstOne(And(*knights[color],attacks));
else if (And(*bishops[color],attacks))
square=FirstOne(And(*bishops[color],attacks));
else if (And(*rooks[color],attacks))
square=FirstOne(And(*rooks[color],attacks));
else if (And(*queens[color],attacks))
square=FirstOne(And(*queens[color],attacks));
else if (And(*kings[color],attacks))
square=FirstOne(And(*kings[color],attacks));
else
square=-1;
if (square < 0) break;
if (next_capture)
swap_list[next_capture]=swap_list[next_capture-1]+
swap_sign*attacked_piece;
else
swap_list[next_capture]=attacked_piece;
attacked_piece=p_values[PieceOnSquare(square)+7];
Clear(square,attacks);
direction=directions[target][square];
if (direction) attacks=SwapXray(attacks,square,direction);
next_capture++;
swap_sign=-swap_sign;
color=ChangeSide(color);
}
next_capture--;
if(next_capture&1)
swap_sign=-1;
else
swap_sign=1;
while (next_capture) {
if (swap_sign < 0) {
if(swap_list[next_capture] <= swap_list[next_capture-1])
swap_list[next_capture-1]=swap_list[next_capture];
}
else {
if(swap_list[next_capture] >= swap_list[next_capture-1])
swap_list[next_capture-1]=swap_list[next_capture];
}
next_capture--;
swap_sign=-swap_sign;
}
return (swap_list[0]);
}
/* 当前文件是D:\Read\evaluate.c*/

BITBOARD all_pawns;
PAWN_HASH_ENTRY pawn_score;
int Evaluate(int ply, int wtm, int alpha, int beta)
{
register BITBOARD temp;
register int square, file, score, tscore;
register int w_safety, b_safety;
register int bishops_opposite_color=0, drawn_ending=0;
if (TotalWhitePieces<5 && TotalBlackPieces<5) drawn_ending=EvaluateDraws();
if (drawn_ending > 0) return((root_wtm) ? DrawScore() : -DrawScore());
score=Material;
#ifdef DEBUGEV
printf("score[material]=                  %d\n",score);
#endif
all_pawns=Or(BlackPawns,WhitePawns);
if ((TotalWhitePawns+TotalBlackPawns) == 0) {
score+=EvaluateMate();
#ifdef DEBUGEV
printf("score[mater]=                     %d\n",score);
#endif
pawn_score.p_score=0;
pawn_score.passed_w=0;
pawn_score.passed_b=0;
pawn_score.weak_w=0;
pawn_score.weak_b=0;
pawn_score.white_pof=0;
pawn_score.black_pof=0;
pawn_score.black_protected=0;
pawn_score.white_protected=0;
pawn_score.white_defects_k=0;
pawn_score.white_defects_q=0;
pawn_score.black_defects_k=0;
pawn_score.black_defects_q=0;
pawn_score.outside=0;
}
else {
#if !defined(FAST)
pawn_probes++;
#endif
if (PawnHashKey == pawn_score.key) {
#if !defined(FAST)
pawn_hits++;
#endif
score+=pawn_score.p_score;
}
else score+=EvaluatePawns();
#ifdef DEBUGEV
printf("score[pawns]=                     %d\n",score);
#endif
}
if (pawn_score.passed_b || pawn_score.passed_w) {
score+=EvaluatePassedPawns();
if (pawn_score.outside&1) score+=outside_passed[(int) TotalBlackPieces];
if (pawn_score.outside&2) score-=outside_passed[(int) TotalWhitePieces];
if ((TotalWhitePieces==0 && pawn_score.passed_b) ||
(TotalBlackPieces==0 && pawn_score.passed_w))
score+=EvaluatePassedPawnRaces(wtm);
#ifdef DEBUGEV
printf("score[passed pawns]=              %d\n",score);
#endif
}
if (Material >= PAWN_VALUE) {
if (root_total_black_pieces > TotalBlackPieces) {
score+=(root_total_black_pieces-TotalBlackPieces)*TRADE_PIECES;
score-=(root_total_white_pawns-TotalWhitePawns)*TRADE_PAWNS;
}
}
else if (Material <= -PAWN_VALUE) {
if (root_total_white_pieces > TotalWhitePieces) {
score-=(root_total_white_pieces-TotalWhitePieces)*TRADE_PIECES;
score+=(root_total_black_pawns-TotalBlackPawns)*TRADE_PAWNS;
}
}
#ifdef DEBUGEV
printf("score[trades]=                    %d\n",score);
#endif
temp=And(WhiteBishops,mask_A7H7);
while(temp) {
square=FirstOne(temp);
if (square == A7 && And(mask_B6B7,BlackPawns)) {
if (And(set_mask[B6],BlackPawns) || Swap(B7,B6,0)>=0)
score-=BISHOP_TRAPPED;
}
else if (square == H7 &&And(mask_G6G7,BlackPawns)) {
if (And(set_mask[G6],BlackPawns) || Swap(G7,G6,0)>=0)
score-=BISHOP_TRAPPED;
}
Clear(square,temp);
}
temp=And(BlackBishops,mask_A2H2);
while(temp) {
square=FirstOne(temp);
if (square == A2 &&And(mask_B2B3,WhitePawns)) {
if (And(set_mask[B3],WhitePawns) || Swap(B2,B3,1)>=0)
score+=BISHOP_TRAPPED;
}
else if (square == H2 && And(mask_G2G3,WhitePawns)) {
if (And(set_mask[G3],WhitePawns) || Swap(G2,G3,1)>=0)
score+=BISHOP_TRAPPED;
}
Clear(square,temp);
}
if (!drawn_ending) {
register int tscore=(wtm)?score:-score;
if (tscore-largest_positional_score >= beta) return(beta);
if (tscore+largest_positional_score <= alpha) return(alpha);
}
tscore=score;
if (opening) score+=EvaluateDevelopment(ply);
#ifdef DEBUGEV
printf("score[development]=               %d\n",score);
#endif
if (TotalWhitePieces > 13 && TotalBlackPieces > 13) {
w_safety=king_defects_w[WhiteKingSQ];
if (WhiteCastle(ply) <= 0) {
if (File(WhiteKingSQ) >= FILEE) {
w_safety+=pawn_score.white_defects_k;
if (!And(WhitePawns,set_mask[G2])) {
if (And(WhitePawns,set_mask[G3]) && Distance(WhiteKingSQ,G2)==1 &&
And(WhiteBishops,good_bishop_kw))
w_safety-=KING_SAFETY_GOOD_BISHOP;
if ((And(mask_F3H3,BlackPawns) || And(mask_F3H3,BlackBishops)) &&
BlackQueens) w_safety+=KING_SAFETY_MATE_G2G7;
}
if (root_wtm && File(WhiteKingSQ) > FILEE) {
if (!And(all_pawns,file_mask[FILEH])) {
if (And(BlackRooks,file_mask[FILEH]) &&
And(BlackQueens,file_mask[FILEH]))
w_safety+=KING_SAFETY_MATE_THREAT;
}
}
}
else if (File(WhiteKingSQ) <= FILED) {
w_safety+=pawn_score.white_defects_q;
if (!And(WhitePawns,set_mask[B2])) {
if (And(WhitePawns,set_mask[B3]) && Distance(WhiteKingSQ,B2)==1 &&
And(WhiteBishops,good_bishop_qw))
w_safety-=KING_SAFETY_GOOD_BISHOP;
if ((And(mask_A3C3,BlackPawns) || And(mask_A3C3,BlackBishops)) &&
BlackQueens) w_safety+=KING_SAFETY_MATE_G2G7;
}
}
}
else {
if (WhiteCastle(ply) == 3)
w_safety+=Min(pawn_score.white_defects_k,pawn_score.white_defects_q);
else if (WhiteCastle(ply) & 1)
w_safety+=pawn_score.white_defects_k;
else if (WhiteCastle(ply) & 2)
w_safety+=pawn_score.white_defects_q;
}
b_safety=king_defects_b[BlackKingSQ];
if (BlackCastle(ply) <= 0) {
if (File(BlackKingSQ) >= FILEE) {
b_safety+=pawn_score.black_defects_k;
if (!And(BlackPawns,set_mask[G7])) {
if (And(BlackPawns,set_mask[G6]) && Distance(BlackKingSQ,G7)==1 &&
And(BlackBishops,good_bishop_kb))
b_safety-=KING_SAFETY_GOOD_BISHOP;
if ((And(mask_F6H6,WhitePawns) || And(mask_F6H6,WhiteBishops)) &&
WhiteQueens) b_safety+=KING_SAFETY_MATE_G2G7;
}
if (!root_wtm && File(BlackKingSQ) > FILEE) {
if (!And(all_pawns,file_mask[FILEH])) {
if (And(WhiteRooks,file_mask[FILEH]) &&
And(WhiteQueens,file_mask[FILEH]))
b_safety+=KING_SAFETY_MATE_THREAT;
}
}
}
else if (File(BlackKingSQ) <= FILED) {
b_safety+=pawn_score.black_defects_q;
if (!And(BlackPawns,set_mask[B7])) {
if (And(BlackPawns,set_mask[B6]) && Distance(BlackKingSQ,B7)==1 &&
And(BlackBishops,good_bishop_qb))
b_safety-=KING_SAFETY_GOOD_BISHOP;
if ((And(mask_A6C6,WhitePawns) || And(mask_A6C6,WhiteBishops)) &&
WhiteQueens) b_safety+=KING_SAFETY_MATE_G2G7;
}
}
}
else {
if (BlackCastle(ply) == 3)
b_safety+=Min(pawn_score.black_defects_k,pawn_score.black_defects_q);
else if (BlackCastle(ply) & 1)
b_safety+=pawn_score.black_defects_k;
else if (BlackCastle(ply) & 2)
b_safety+=pawn_score.black_defects_q;
}
}
else {
w_safety=0;
b_safety=0;
if (TotalWhitePieces==bishop_v && TotalBlackPieces==bishop_v) {
if (square_color[FirstOne(BlackBishops)] !=
square_color[FirstOne(WhiteBishops)])
bishops_opposite_color=1;
}
}
#ifdef DEBUGEV
printf("score[king safety]=               %d\n",score);
#endif
if (drawn_ending == 0) {
register int tscore=(wtm)?score:-score;
if (tscore-largest_positional_score>= beta) return(beta);
if (tscore+largest_positional_score<= alpha) return(alpha);
}
tscore=score;
evaluations++;
if (TotalBlackPieces < 14) score+=king_value_w[WhiteKingSQ];
if (WhiteKingSQ < A2) {
if (!And(And(king_attacks[WhiteKingSQ],rank_mask[RANK2]),
Compl(WhitePawns))) score-=KING_BACK_RANK;
if (WhiteKingSQ > FILEE) {
if (And(WhiteRooks,mask_kr_trapped_w[FILEH-WhiteKingSQ]))
score-=ROOK_TRAPPED;
}
else if (WhiteKingSQ < FILED) {
if (And(WhiteRooks,mask_qr_trapped_w[WhiteKingSQ]))
score-=ROOK_TRAPPED;
}
}
#ifdef DEBUGEV
printf("score[kings(white)]=              %d\n",score);
#endif
if (TotalWhitePieces < 14) score-=king_value_b[BlackKingSQ];
if (BlackKingSQ > H7) {
if (!And(And(king_attacks[BlackKingSQ],rank_mask[RANK7]),
Compl(BlackPawns))) score+=KING_BACK_RANK;
if (File(BlackKingSQ) > FILEE) {
if (And(BlackRooks,mask_kr_trapped_b[FILEH-File(BlackKingSQ)]))
score+=ROOK_TRAPPED;
}
else if (File(BlackKingSQ) < FILED) {
if (And(BlackRooks,mask_qr_trapped_b[File(BlackKingSQ)]))
score+=ROOK_TRAPPED;
}
}
#ifdef DEBUGEV
printf("score[kings(black)]=              %d\n",score);
#endif
temp=WhiteKnights;
while(temp) {
square=FirstOne(temp);
if (white_outpost[square] &&
!And(mask_no_pawn_attacks_b[square],BlackPawns)) {
score+=KNIGHT_OUTPOST*white_outpost[square];
if(And(b_pawn_attacks[square],WhitePawns)) score+=KNIGHT_OUTPOST;
}
score+=knight_value_w[square];
if (knight_value_w[square] >= 0)
score+=(7-Distance(square,BlackKingSQ))*b_safety*KNIGHT_KING_TROPISM/10;
Clear(square,temp);
}
#ifdef DEBUGEV
printf("score[knights(white)]=            %d\n",score);
#endif
temp=BlackKnights;
while(temp) {
square=FirstOne(temp);
if (black_outpost[square] &&
!And(mask_no_pawn_attacks_w[square],WhitePawns)) {
score-=KNIGHT_OUTPOST*black_outpost[square];
if (And(w_pawn_attacks[square],BlackPawns)) score-=KNIGHT_OUTPOST;
}
score-=knight_value_b[square];
if (knight_value_b[square] >= 0)
score-=(7-Distance(square,WhiteKingSQ))*w_safety*KNIGHT_KING_TROPISM/10;
Clear(square,temp);
}
#ifdef DEBUGEV
printf("score[knights(black)]=            %d\n",score);
#endif
temp=WhiteBishops;
while(temp) {
square=FirstOne(temp);
score+=bishop_value_w[square];
score+=BISHOP_MOBILITY*MobilityBishop(square);
if (white_outpost[square] &&
!And(mask_no_pawn_attacks_b[square],BlackPawns)) {
score+=BISHOP_OUTPOST*white_outpost[square];
if(And(b_pawn_attacks[square],WhitePawns)) score+=BISHOP_OUTPOST;
}
score+=(7-Distance(square,BlackKingSQ))*b_safety*BISHOP_KING_TROPISM/10;
Clear(square,temp);
}
#ifdef DEBUGEV
printf("score[bishops(white)]=            %d\n",score);
#endif
temp=BlackBishops;
while(temp) {
square=FirstOne(temp);
score-=bishop_value_b[square];
score-=BISHOP_MOBILITY*MobilityBishop(square);
if (black_outpost[square] &&
!And(mask_no_pawn_attacks_w[square],WhitePawns)) {
score-=BISHOP_OUTPOST*black_outpost[square];
if (And(w_pawn_attacks[square],BlackPawns)) score-=BISHOP_OUTPOST;
}
score-=(7-Distance(square,WhiteKingSQ))*w_safety*BISHOP_KING_TROPISM/10;
Clear(square,temp);
}
#ifdef DEBUGEV
printf("score[bishops(black)]=            %d\n",score);
#endif
if (And(WhiteBishops,WhiteBishops-1)) score+=BISHOP_PAIR;
if (And(BlackBishops,BlackBishops-1)) score-=BISHOP_PAIR;
#ifdef DEBUGEV
printf("score[bishop pair]=               %d\n",score);
#endif
temp=WhiteRooks;
while(temp) {
square=FirstOne(temp);
file=File(square);
score+=rook_value_w[square];
if (!And(file_mask[file],WhitePawns && pawn_score.weak_b & (128>>file)))
score+=ROOK_OPEN_FILE/2;
if (!And(file_mask[file],all_pawns)) {
score+=ROOK_OPEN_FILE;
if (FileDistance(square,BlackKingSQ) <= 1) score+=b_safety*ROOK_KING_TROPISM;
if (And(AttacksFile(square),WhiteRooks)) score+=ROOK_CONNECTED_OPEN_FILE;
}
if (128>>file & pawn_score.passed_w) {
register int pawnsq=LastOne(And(WhitePawns,file_mask[file]));
if (square<pawnsq && !And(BlackPieces,set_mask[pawnsq+8]))
score+=ROOK_BEHIND_PASSED_PAWN;
if (And(AttacksFile(square),WhiteRooks)) score-=ROOK_BEHIND_PASSED_PAWN/2;
}
if (128>>file & pawn_score.passed_b) {
register int pawnsq=FirstOne(And(BlackPawns,file_mask[file]));
if (square > pawnsq) score+=ROOK_BEHIND_PASSED_PAWN;
}
score+=pawn_score.black_pof*ROOK_WEAK_PAWN;
if (!And(WhitePawns,plus8dir[square]))
score+=(7-FileDistance(square,BlackKingSQ))*b_safety*ROOK_KING_TROPISM/10;
if (Rank(square)==RANK7 && (BlackKingSQ>H7 ||
And(BlackPawns,rank_mask[RANK7]))) {
score+=ROOK_ON_7TH;
if (TotalBlackPieces < 14) {
if (BlackKingSQ > H7) score+=ROOK_ON_7TH;
if (pawn_score.passed_w && !And(BlackPieces,mask_abs7_w)) score+=ROOK_ABSOLUTE_7TH;
}
if (And(AttacksRank(square),Or(WhiteRooks,WhiteQueens)))
score+=ROOK_CONNECTED_7TH_RANK;
}
Clear(square,temp);
}
#ifdef DEBUGEV
printf("score[rooks(white)]=              %d\n",score);
#endif
temp=BlackRooks;
while(temp) {
square=FirstOne(temp);
file=File(square);
score-=rook_value_b[square];
if (!And(file_mask[file],BlackPawns && pawn_score.weak_w & (128>>file)))
score-=ROOK_OPEN_FILE/2;
if (!And(file_mask[file],all_pawns)) {
score-=ROOK_OPEN_FILE;
if (FileDistance(square,WhiteKingSQ) <= 1) score-=w_safety*ROOK_KING_TROPISM;
if (And(AttacksFile(square),BlackRooks)) score-=ROOK_CONNECTED_OPEN_FILE;
}
if (128>>file & pawn_score.passed_b) {
register int pawnsq=FirstOne(And(BlackPawns,file_mask[file]));
if (square>pawnsq && !And(WhitePieces,set_mask[pawnsq-8]))
score-=ROOK_BEHIND_PASSED_PAWN;
if (And(AttacksFile(square),BlackRooks)) score+=ROOK_BEHIND_PASSED_PAWN/2;
}
if (128>>file & pawn_score.passed_w) {
register int pawnsq=LastOne(And(WhitePawns,file_mask[file]));
if (square < pawnsq) score-=ROOK_BEHIND_PASSED_PAWN;
}
score-=pawn_score.white_pof*ROOK_WEAK_PAWN;
if (!And(BlackPawns,minus8dir[square]))
score-=(7-FileDistance(square,WhiteKingSQ))*w_safety*ROOK_KING_TROPISM/10;
if (Rank(square)==RANK2 && (WhiteKingSQ<A2 ||
And(WhitePawns,rank_mask[RANK2]))) {
score-=ROOK_ON_7TH;
if (TotalWhitePieces < 14) {
if (WhiteKingSQ < A2) score-=ROOK_ON_7TH;
if (pawn_score.passed_b && !And(WhitePieces,mask_abs7_b)) score-=ROOK_ABSOLUTE_7TH;
}
if (And(AttacksRank(square),Or(BlackRooks,BlackQueens)))
score-=ROOK_CONNECTED_7TH_RANK;
}
Clear(square,temp);
}
#ifdef DEBUGEV
printf("score[rooks(black)]=              %d\n",score);
#endif
temp=WhiteQueens;
while(temp) {
square=FirstOne(temp);
score+=queen_value_w[square];
if ((Rank(square) == RANK7) && (And(BlackPawns,rank_mask[RANK7]) ||
(BlackKingSQ > H7))) {
if (And(AttacksRank(square),WhiteRooks)) score+=QUEEN_ROOK_ON_7TH_RANK;
}
score+=(7-Distance(square,BlackKingSQ))*b_safety*QUEEN_KING_TROPISM/10;
Clear(square,temp);
}
temp=BlackQueens;
while(temp) {
square=FirstOne(temp);
score-=queen_value_b[square];
if ((Rank(square) == RANK2) && (And(WhitePawns,rank_mask[RANK2]) ||
(WhiteKingSQ < A2))) {
if (And(AttacksRank(square),BlackRooks)) score-=QUEEN_ROOK_ON_7TH_RANK;
}
score-=(7-Distance(square,WhiteKingSQ))*w_safety*QUEEN_KING_TROPISM/10;
Clear(square,temp);
}
#ifdef DEBUGEV
printf("score[queens]=                    %d\n",score);
#endif
if (abs(score-tscore) > largest_positional_score)
largest_positional_score=abs(score-tscore);
if (bishops_opposite_color) score=score>>1;
if (drawn_ending < 0) {
if (drawn_ending == -1 && score > 0) score=DrawScore();
else if (drawn_ending == -2 && score < 0) score=DrawScore();
}
#ifdef DEBUGEV
printf("score[draws]=                     %d\n",score);
#endif
return((wtm) ? score : -score);
}
int EvaluateDevelopment(int ply)
{
register int possible, real, score=0;
BITBOARD unmoved_pieces;
if (root_wtm) {
if (!And(set_mask[E4],WhitePawns) && And(set_mask[D4],WhitePawns)) {
if (And(set_mask[C2],WhitePawns) &&
And(set_mask[C3],Or(WhiteKnights,WhiteBishops)))
score-=DEVELOPMENT_THEMATIC;
}
if (And(Occupied,And(Shiftr(And(WhitePawns,rank_mask[RANK2]),8),
Or(file_mask[FILED],file_mask[FILEE]))))
score-=DEVELOPMENT_BLOCKED_PAWN;
}
else {
if (!And(set_mask[E4],WhitePawns) && And(set_mask[D4],WhitePawns)) {
if (And(set_mask[C7],BlackPawns) &&
And(set_mask[C6],Or(BlackKnights,BlackBishops)))
score+=DEVELOPMENT_THEMATIC;
}
if (And(Occupied,And(Shiftl(And(BlackPawns,rank_mask[RANK7]),8),
Or(file_mask[FILED],file_mask[FILEE]))))
score+=DEVELOPMENT_BLOCKED_PAWN;
}
#ifdef DEBUGDV
printf("development.1 score=%d\n", score);
#endif
if ((unmoved_pieces=And(Or(WhiteKnights,WhiteBishops),white_minor_pieces))) {
int unmoved=PopCnt(unmoved_pieces);
score-=unmoved*DEVELOPMENT_UNMOVED;
if ((unmoved>1 || WhiteCastle(ply)>0) && !And(WhiteQueens,set_mask[D1])) score-=DEVELOPMENT_QUEEN_EARLY;
}
if ((unmoved_pieces=And(Or(BlackKnights,BlackBishops),black_minor_pieces))) {
int unmoved=PopCnt(unmoved_pieces);
score+=unmoved*DEVELOPMENT_UNMOVED;
if ((unmoved>1 || BlackCastle(ply)>0) && !And(BlackQueens,set_mask[D8])) score+=DEVELOPMENT_QUEEN_EARLY;
}
#ifdef DEBUGDV
printf("development.2 score=%d\n",score);
#endif
if (WhiteCastle(1) > 0) {
register int bq, mult;
possible=0;
real=0;
if (WhiteCastle(ply) == 0)
score-=(root_wtm) ? 2*DEVELOPMENT_LOSING_CASTLE :
DEVELOPMENT_LOSING_CASTLE;
bq=(BlackQueens) ? 2 : 1;
if (WhiteCastle(ply) < 0) {
if (File(WhiteKingSQ) > FILEE) {
mult=TotalBlackPieces*bq+10;
if (root_wtm) {
real=-mult*pawn_score.white_defects_k/10;
possible=-mult*pawn_score.white_defects_q/10;
}
else {
real=-mult*pawn_score.white_defects_k/15;
possible=-mult*pawn_score.white_defects_q/15;
}
}
else if (File(WhiteKingSQ) < FILED) {
mult=TotalBlackPieces*bq+10;
if (root_wtm) {
real=-mult*pawn_score.white_defects_q/10;
possible=-mult*pawn_score.white_defects_k/10;
}
else {
real=-mult*pawn_score.white_defects_q/15;
possible=-mult*pawn_score.white_defects_k/15;
}
}
}
if (WhiteCastle(1)==3 && WhiteCastle(ply)>0 && WhiteCastle(ply)!=3) {
if (WhiteCastle(ply)&1) {
mult=TotalBlackPieces*bq+10;
if (root_wtm) {
real=-mult*pawn_score.white_defects_k/10;
possible=-mult*pawn_score.white_defects_q/10;
}
else {
real=-mult*pawn_score.white_defects_k/15;
possible=-mult*pawn_score.white_defects_q/15;
}
}
else if (WhiteCastle(ply)&2) {
mult=TotalBlackPieces*bq+10;
if (root_wtm) {
real=-mult*pawn_score.white_defects_q/10;
possible=-mult*pawn_score.white_defects_k/10;
}
else {
real=-mult*pawn_score.white_defects_q/15;
possible=-mult*pawn_score.white_defects_k/15;
}
}
}
if (possible > real) score-=possible-real;
if (WhiteCastle(ply) > 0) score-=DEVELOPMENT_NOT_CASTLED;
}
if (BlackCastle(1) > 0) {
register int wq, mult;
possible=0;
real=0;
if (BlackCastle(ply) == 0)
score+=(!root_wtm) ? 2*DEVELOPMENT_LOSING_CASTLE :
DEVELOPMENT_LOSING_CASTLE;
wq=(WhiteQueens) ? 2 : 1;
if (BlackCastle(ply) < 0) {
if (File(BlackKingSQ) > FILEE) {
mult=TotalWhitePieces*wq+10;
if (root_wtm) {
real=-mult*pawn_score.black_defects_k/15;
possible=-mult*pawn_score.black_defects_q/15;
}
else {
real=-mult*pawn_score.black_defects_k/10;
possible=-mult*pawn_score.black_defects_q/10;
}
}
else {
mult=TotalWhitePieces*wq+10;
if (root_wtm) {
real=-mult*pawn_score.black_defects_q/15;
possible=-mult*pawn_score.black_defects_k/15;
}
else {
real=-mult*pawn_score.black_defects_q/10;
possible=-mult*pawn_score.black_defects_k/10;
}
}
}
if (BlackCastle(1)==3 && BlackCastle(ply)>0 && BlackCastle(ply)!=3) {
if (BlackCastle(ply)&1) {
mult=TotalWhitePieces*wq+10;
if (root_wtm) {
real=-mult*pawn_score.black_defects_k/15;
possible=-mult*pawn_score.black_defects_q/15;
}
else {
real=-mult*pawn_score.black_defects_k/10;
possible=-mult*pawn_score.black_defects_q/10;
}
}
else if (BlackCastle(ply)&2) {
mult=TotalWhitePieces*wq+10;
if (root_wtm) {
real=-mult*pawn_score.black_defects_q/15;
possible=-mult*pawn_score.black_defects_k/15;
}
else {
real=-mult*pawn_score.black_defects_q/10;
possible=-mult*pawn_score.black_defects_k/10;
}
}
}
if (possible > real) score+=possible-real;
if (BlackCastle(ply) > 0) score+=DEVELOPMENT_NOT_CASTLED;
}
#ifdef DEBUGDV
printf("development.3 score=%d\n",score);
#endif
return(score);
}
int EvaluateDraws()
{
register int square;
if (TotalWhitePieces >= 5 || TotalBlackPieces >=5) return(0);
if (TotalBlackPieces==0 && TotalWhitePawns &&
!And(WhitePawns,not_rook_pawns)) {
if (TotalWhitePieces==3) {
if (And(WhiteBishops,dark_squares)) {
if (And(file_mask[FILEH],WhitePawns)) return(0);
}
else if (And(file_mask[FILEA],WhitePawns)) return(0);
}
else if (TotalWhitePieces==0) {
if (And(file_mask[FILEA],WhitePawns) &&
And(file_mask[FILEH],WhitePawns)) return(0);
}
else return(0);
if (!And(WhitePawns,file_mask[FILEA]) ||
!And(WhitePawns,file_mask[FILEH])) {
square=LastOne(WhitePawns);
if (Rank(BlackKingSQ) >= Rank(square))
if (FileDistance(BlackKingSQ,square)<=1) return(1);
return(0);
}
}
if (TotalWhitePieces==0 && TotalBlackPawns &&
!And(BlackPawns,not_rook_pawns)) {
if (TotalBlackPieces==3) {
if (And(BlackBishops,dark_squares)) {
if (And(file_mask[FILEA],BlackPawns)) return(0);
}
else if (And(file_mask[FILEH],BlackPawns)) return(0);
}
else if (TotalBlackPieces==0) {
if (And(file_mask[FILEA],BlackPawns) &&
And(file_mask[FILEH],BlackPawns)) return(0);
}
else return(0);
if (!And(BlackPawns,file_mask[FILEA]) ||
!And(BlackPawns,file_mask[FILEH])) {
square=FirstOne(BlackPawns);
if (Rank(WhiteKingSQ) <= Rank(square))
if (FileDistance(WhiteKingSQ,square)<=1) return(1);
return(0);
}
}
if (!TotalWhitePawns && !TotalBlackPawns &&
TotalWhitePieces < 5 && TotalBlackPieces < 5) return(1);
if (TotalWhitePawns == 0 && TotalWhitePieces < 4) return(-1);
else if (TotalBlackPawns == 0 && TotalBlackPieces < 4) return(-2);
return(0);
}
int EvaluateMate(void)
{
register int mate_score;
mate_score=0;
if ((TotalBlackPieces==0) && (TotalWhitePieces==5) &&
(!WhitePawns) && (!BlackPawns) && WhiteBishops) {
if (And(dark_squares,WhiteBishops))
mate_score=b_n_mate_dark_squares[BlackKingSQ];
else
mate_score=b_n_mate_light_squares[BlackKingSQ];
}
if ((TotalBlackPieces==5) && (TotalWhitePieces==0) &&
(!WhitePawns) && (!BlackPawns) && BlackBishops) {
if (And(dark_squares,BlackBishops))
mate_score=-b_n_mate_dark_squares[WhiteKingSQ];
else
mate_score=-b_n_mate_light_squares[WhiteKingSQ];
}
if (!mate_score) {
if (Material >= 300) mate_score=mate[BlackKingSQ];
else if (Material <= -300) mate_score=-mate[WhiteKingSQ];
}
return(mate_score);
}
int EvaluatePassedPawns(void)
{
register int file, square, score=0;
register int white_king_sq, black_king_sq;
register int pawns;
if (pawn_score.passed_b) {
black_king_sq=BlackKingSQ;
pawns=pawn_score.passed_b;
while (pawns) {
file=first_ones_8bit[pawns];
pawns&=~(128>>file);
square=FirstOne(And(BlackPawns,file_mask[file]));
if (TotalWhitePieces < 20)
score-=reduced_material_passer[TotalWhitePieces]*(RANK8-Rank(square));
if (Distance(square,black_king_sq) < 2)
score-=supported_passer[RANK8-Rank(square)];
if (And(set_mask[square-8],WhitePieces))
score+=passed_pawn_value[RANK8-Rank(square)]/2;
}
#ifdef DEBUGPP
printf("score.1 after black passers = %d\n", score);
#endif
pawns=pawn_score.passed_b;
while ((file=connected_passed[pawns])) {
register int square1,square2;
pawns&=~(128>>file);
square1=FirstOne(And(BlackPawns,file_mask[file-1]));
if (Rank(square1) > RANK3) continue;
square2=FirstOne(And(BlackPawns,file_mask[file]));
if (Rank(square2) > RANK3) continue;
score-=PAWN_CONNECTED_PASSED_6TH;
if (TotalWhitePieces < queen_v &&
!And(set_mask[square1-8],WhitePieces) &&
!And(set_mask[square2-8],WhitePieces)) {
score-=PAWN_CONNECTED_PASSED_6TH;
if ((TotalWhitePieces <= rook_v) &&
(!And(WhiteKing,black_pawn_race_btm[square1]) ||
!And(WhiteKing,black_pawn_race_btm[square2])))
score-=3*PAWN_CONNECTED_PASSED_6TH;
}
}
}
#ifdef DEBUGPP
printf("score.2 after black passers = %d\n", score);
#endif
if (pawn_score.passed_w) {
white_king_sq=WhiteKingSQ;
pawns=pawn_score.passed_w;
while (pawns) {
file=first_ones_8bit[pawns];
pawns&=~(128>>file);
square=LastOne(And(WhitePawns,file_mask[file]));
if (TotalBlackPieces < 20)
score+=reduced_material_passer[TotalBlackPieces]*Rank(square);
if (Distance(square,white_king_sq) < 2)
score+=supported_passer[Rank(square)];
if (And(set_mask[square+8],BlackPieces))
score-=passed_pawn_value[Rank(square)]/2;
}
#ifdef DEBUGPP
printf("score.1 after white passers = %d\n", score);
#endif
pawns=pawn_score.passed_w;
while ((file=connected_passed[pawns])) {
register int square1,square2;
pawns&=~(128>>file);
square1=LastOne(And(WhitePawns,file_mask[file-1]));
if (Rank(square1) < RANK6) continue;
square2=LastOne(And(WhitePawns,file_mask[file]));
if (Rank(square2) < RANK6) continue;
score+=PAWN_CONNECTED_PASSED_6TH;
if (TotalBlackPieces < queen_v &&
!And(set_mask[square1+8],BlackPieces) &&
!And(set_mask[square2+8],BlackPieces)) {
score+=PAWN_CONNECTED_PASSED_6TH;
if ((TotalBlackPieces <= rook_v) &&
(!And(BlackKing,white_pawn_race_wtm[square1]) ||
!And(BlackKing,white_pawn_race_wtm[square2])))
score+=3*PAWN_CONNECTED_PASSED_6TH;
}
}
}
#ifdef DEBUGPP
printf("score.2 after white passers = %d\n", score);
#endif
if (TotalBlackPawns==1 && TotalWhitePawns==0 &&
TotalBlackPieces==5 && BlackRooks &&
TotalWhitePieces==5 && WhiteRooks) {
square=FirstOne(BlackPawns);
if (FileDistance(WhiteKingSQ,square)<=1 &&
Rank(WhiteKingSQ)<Rank(square)) return(0);
if (Rank(BlackKingSQ)>Rank(square) ||
FileDistance(BlackKingSQ,square) > 1) return(0);
}
if (TotalWhitePawns==1 && TotalBlackPawns==0 &&
TotalWhitePieces==5 && WhiteRooks &&
TotalBlackPieces==5 && BlackRooks) {
square=FirstOne(WhitePawns);
if (FileDistance(BlackKingSQ,square)<=1 &&
Rank(BlackKingSQ)>Rank(square)) return(0);
if (Rank(WhiteKingSQ)<Rank(square) ||
FileDistance(WhiteKingSQ,square) > 1) return(0);
}
return(score);
}
int EvaluatePassedPawnRaces(int wtm)
{
register int file, square;
register int white_queener=8, white_square=0;
register int black_queener=8, black_square=0;
register int white_pawn=0, black_pawn=0, queen_distance;
register int white_protected=0, black_protected=0;
register int pawnsq;
register BITBOARD tempw, tempb;
register int passed;
if (WhitePawns && !BlackPawns &&
!TotalWhitePieces && !TotalBlackPieces) do {
pawnsq=LastOne(WhitePawns);
if (Rank(WhiteKingSQ) <= Rank(pawnsq)) break;
if (File(pawnsq) == FILEA) {
if ((File(WhiteKingSQ) == FILEB) &&
(Distance(WhiteKingSQ,56) < Distance(BlackKingSQ,56)))
return(QUEEN_VALUE-BISHOP_VALUE);
break;
}
else if (File(pawnsq) == FILEH) {
if ((File(WhiteKingSQ) == FILEG) &&
(Distance(WhiteKingSQ,63) < Distance(BlackKingSQ,63)))
return(QUEEN_VALUE-BISHOP_VALUE);
break;
}
if (Distance(WhiteKingSQ,pawnsq)<=Distance(BlackKingSQ,pawnsq)) {
if (Rank(WhiteKingSQ) > Rank(pawnsq)+1)
return(QUEEN_VALUE-BISHOP_VALUE);
if (Rank(WhiteKingSQ) == RANK6)
return(QUEEN_VALUE-BISHOP_VALUE);
}
if ((Rank(WhiteKingSQ) == Rank(pawnsq)+1) &&
HasOpposition(wtm,WhiteKingSQ,BlackKingSQ))
return(QUEEN_VALUE-BISHOP_VALUE);
} while(0);
if (BlackPawns && !WhitePawns &&
!TotalWhitePieces && !TotalBlackPieces) do {
pawnsq=FirstOne(BlackPawns);
if (Rank(BlackKingSQ) >= Rank(pawnsq)) break;
if (File(pawnsq) == FILEA) {
if ((File(BlackKingSQ) == FILEB) &&
(Distance(BlackKingSQ,0) < Distance(WhiteKingSQ,0)))
return(-(QUEEN_VALUE-BISHOP_VALUE));
break;
}
else if (File(pawnsq) == FILEH) {
if ((File(WhiteKingSQ) == FILEG) &&
(Distance(BlackKingSQ,8) < Distance(WhiteKingSQ,8)))
return(-(QUEEN_VALUE-BISHOP_VALUE));
break;
}
if (Distance(BlackKingSQ,pawnsq)<=Distance(WhiteKingSQ,pawnsq)) {
if (Rank(BlackKingSQ) < Rank(pawnsq)-1)
return(-(QUEEN_VALUE-BISHOP_VALUE));
if (Rank(BlackKingSQ) == RANK3)
return(-(QUEEN_VALUE-BISHOP_VALUE));
}
if ((Rank(BlackKingSQ) == Rank(pawnsq)-1) &&
HasOpposition(ChangeSide(wtm),BlackKingSQ,WhiteKingSQ))
return(-(QUEEN_VALUE-BISHOP_VALUE));
} while(0);
if (!TotalWhitePieces && pawn_score.passed_b) {
passed=pawn_score.passed_b;
while ((file=first_ones_8bit[passed]) != 8) {
passed&=~(128>>file);
square=FirstOne(And(BlackPawns,file_mask[file]));
if ((wtm && !And(black_pawn_race_wtm[square],WhiteKing)) ||
(ChangeSide(wtm) && !And(black_pawn_race_btm[square],WhiteKing))) {
queen_distance=Rank(square);
if (And(BlackKing,minus8dir[square])) {
if (File(square)==FILEA || File(square)==FILEH) queen_distance=99;
queen_distance++;
}
if (Rank(square) == RANK7) queen_distance--;
if (queen_distance < black_queener) {
black_queener=queen_distance;
black_square=File(square);
black_pawn=square;
}
}
}
}
#ifdef DEBUGPP
printf("black pawn on %d can promote at %d in %d moves.\n",
black_pawn,black_square,black_queener);
#endif
if (!TotalBlackPieces && pawn_score.passed_w) {
passed=pawn_score.passed_w;
while ((file=first_ones_8bit[passed]) != 8) {
passed&=~(128>>file);
square=LastOne(And(WhitePawns,file_mask[file]));
if ((wtm && !And(white_pawn_race_wtm[square],BlackKing)) ||
(ChangeSide(wtm) && !And(white_pawn_race_btm[square],BlackKing))) {
queen_distance=RANK8-Rank(square);
if (And(WhiteKing,plus8dir[square])) {
if (File(square)==FILEA || File(square)==FILEH) queen_distance=99;
queen_distance++;
}
if (Rank(square) == RANK2) queen_distance--;
if (queen_distance < white_queener) {
white_queener=queen_distance;
white_square=File(square)+56;
white_pawn=square;
}
}
}
}
#ifdef DEBUGPP
printf("white pawn on %d can promote at %d in %d moves.\n",
white_pawn,white_square,white_queener);
#endif
do {
if ((white_queener==8) && (black_queener==8)) break;
if ((white_queener < 8) && (black_queener == 8))
return(QUEEN_VALUE-BISHOP_VALUE+white_queener*PAWN_VALUE/10);
else if ((black_queener < 8) && (white_queener == 8))
return(-(QUEEN_VALUE-BISHOP_VALUE+black_queener*PAWN_VALUE/10));
if (ChangeSide(wtm)) black_queener--;
if (white_queener < black_queener)
return(QUEEN_VALUE-BISHOP_VALUE+white_queener*PAWN_VALUE/10);
else if (black_queener < white_queener-1)
return(-(QUEEN_VALUE-BISHOP_VALUE+black_queener*PAWN_VALUE/10));
if ((white_queener==8) || (black_queener==8)) break;
if (white_queener == black_queener) {
tempw=WhitePieces;
Clear(white_pawn,WhitePieces);
WhitePieces=Or(WhitePieces,set_mask[white_square]);
tempb=BlackPieces;
Clear(black_pawn,BlackPieces);
BlackPieces=Or(BlackPieces,set_mask[black_square]);
if (Attack(BlackKingSQ,white_square,ply)) {
WhitePieces=tempw;
BlackPieces=tempb;
return(QUEEN_VALUE-BISHOP_VALUE+white_queener*PAWN_VALUE/10);
}
if (Attack(black_square,white_square,ply) &&
!And(king_attacks[black_square],BlackKing)) {
WhitePieces=tempw;
BlackPieces=tempb;
return(QUEEN_VALUE-BISHOP_VALUE+white_queener*PAWN_VALUE/10);
}
WhitePieces=tempw;
BlackPieces=tempb;
}
if (black_queener == white_queener-1) {
tempw=WhitePieces;
Clear(white_pawn,WhitePieces);
WhitePieces=Or(WhitePieces,set_mask[white_square]);
tempb=BlackPieces;
Clear(black_pawn,BlackPieces);
BlackPieces=Or(BlackPieces,set_mask[black_square]);
if (Attack(WhiteKingSQ,black_square,ply)) {
WhitePieces=tempw;
BlackPieces=tempb;
return(-(QUEEN_VALUE-BISHOP_VALUE+black_queener*PAWN_VALUE/10));
}
if (Attack(white_square,black_square,ply) &&
!And(king_attacks[white_square],WhiteKing)) {
WhitePieces=tempw;
BlackPieces=tempb;
return(-(QUEEN_VALUE-BISHOP_VALUE+black_queener*PAWN_VALUE/10));
}
WhitePieces=tempw;
BlackPieces=tempb;
}
} while(0);
if (white_protected && !black_protected)
return(PAWN_PROTECTED_PASSER_WINS);
else if (!white_protected && black_protected)
return(-PAWN_PROTECTED_PASSER_WINS);
else
return(0);
}
int EvaluatePawns()
{
register PAWN_HASH_ENTRY *ptable;
register BITBOARD pawns;
register BITBOARD temp;
register BITBOARD wp_moves, bp_moves;
register int square, file;
register int w_weak, w_isolated=0, b_weak, b_isolated=0;
register int w_blocked=0, w_unblocked=0, b_blocked=0, b_unblocked=0;
register int w_file_l, w_file_r, b_file_l, b_file_r;
register int defenders, attackers, weakness, blocked, sq, adv;
ptable=pawn_hash_table+(PawnHashKey&pawn_hash_mask);
if (ptable->key == PawnHashKey) {
#if !defined(FAST)
pawn_hits++;
#endif
pawn_score=*ptable;
return(pawn_score.p_score);
}
pawn_score.key=PawnHashKey;
pawn_score.p_score=0;
pawn_score.passed_w=0;
pawn_score.passed_b=0;
pawn_score.weak_w=0;
pawn_score.weak_b=0;
pawn_score.white_pof=0;
pawn_score.black_pof=0;
pawn_score.white_protected=0;
pawn_score.black_protected=0;
pawn_score.white_defects_k=0;
pawn_score.white_defects_q=0;
pawn_score.black_defects_k=0;
pawn_score.black_defects_q=0;
pawn_score.outside=0;
pawns=WhitePawns;
wp_moves=0;
while (pawns) {
square=FirstOne(pawns);
for (sq=square;sq<A7;sq+=8) {
wp_moves|=set_mask[sq];
if (And(set_mask[sq+8],all_pawns)) break;
defenders=PopCnt(And(b_pawn_attacks[sq+8],WhitePawns));
attackers=PopCnt(And(w_pawn_attacks[sq+8],BlackPawns));
if (attackers-defenders == 2) break;
}
Clear(square,pawns);
}
pawns=BlackPawns;
bp_moves=0;
while (pawns) {
square=FirstOne(pawns);
for (sq=square;sq>H2;sq-=8) {
bp_moves|=set_mask[sq];
if (And(set_mask[sq-8],all_pawns)) break;
attackers=PopCnt(And(b_pawn_attacks[sq-8],WhitePawns));
defenders=PopCnt(And(w_pawn_attacks[sq-8],BlackPawns));
if (attackers-defenders == 2) break;
}
Clear(square,pawns);
}
pawns=WhitePawns;
while (pawns) {
w_weak=0;
square=FirstOne(pawns);
file=File(square);
pawn_score.p_score+=pawn_value_w[square];
#ifdef DEBUGP
printf("white pawn[static] file=%d,   score=%d\n",file,pawn_score.p_score);
#endif
if (!And(mask_pawn_isolated[square],WhitePawns)) {
w_isolated++;
w_weak=128;
}
else do {
weakness=0;
defenders=PopCnt(And(b_pawn_attacks[square],WhitePawns));
attackers=PopCnt(And(w_pawn_attacks[square],BlackPawns));
if (defenders > attackers) break;
for (sq=square+8;sq<A7;sq+=8) {
defenders=PopCnt(And(b_pawn_attacks[sq],WhitePawns));
attackers=PopCnt(And(w_pawn_attacks[sq],BlackPawns));
if (And(set_mask[sq],all_pawns)) {
weakness=1;
break;
}
if (attackers > defenders) {
weakness=attackers-defenders;
break;
}
else if (defenders && defenders >= attackers) break;
}
if (!weakness) break;
if ((temp=And(mask_no_pawn_attacks_w[square],WhitePawns))) {
if (file > FILEA) {
BITBOARD temp1=And(temp,file_mask[file-1]);
attackers=1;
if (temp1) {
int defend_sq=LastOne(temp1);
for (sq=defend_sq;sq<(Rank(square)<<3);sq+=8) {
attackers=1;
if (sq!=defend_sq && And(all_pawns,set_mask[sq])) break;
attackers=PopCnt(And(w_pawn_attacks[sq],BlackPawns));
if (attackers) break;
}
if (!attackers) weakness=0;
}
if (!weakness) break;
}
if (file < FILEH) {
BITBOARD temp1=And(temp,file_mask[file+1]);
if (temp1) {
int defend_sq=LastOne(temp1);
for (sq=defend_sq;sq<(Rank(square)<<3);sq+=8) {
attackers=1;
if (sq != defend_sq && And(all_pawns,set_mask[sq])) break;
attackers=PopCnt(And(w_pawn_attacks[sq],BlackPawns));
if (attackers) break;
}
if (!attackers) weakness=0;
}
}
}
if (weakness > 0) {
w_weak=128;
if (weakness == 1) pawn_score.p_score-=PAWN_WEAK_P1;
else pawn_score.p_score-=PAWN_WEAK_P2;
}
} while(0);
if (w_weak) {
if (!And(plus8dir[square],BlackPawns)) {
pawn_score.white_pof++;
pawn_score.weak_w|=w_weak>>file;
}
}
#ifdef DEBUGP
printf("white pawn[weak] file=%d,     score=%d\n",file,pawn_score.p_score);
#endif
if (PopCnt(And(file_mask[file],WhitePawns)) > 1) {
pawn_score.p_score-=PAWN_DOUBLED;
}
#ifdef DEBUGP
printf("white pawn[doubled] file=%d,     score=%d\n",file,pawn_score.p_score);
#endif
if (!And(mask_pawn_passed_w[square],BlackPawns)) {
pawn_score.p_score+=passed_pawn_value[Rank(square)];
if (And(mask_pawn_protected_w[square],WhitePawns))
pawn_score.white_protected=1;
pawn_score.passed_w|=128>>file;
}
#ifdef DEBUGP
printf("white pawn[passed] file=%d,   score=%d\n",file,pawn_score.p_score);
#endif
if (Rank(square) > RANK4 && And(set_mask[square+8],BlackPawns) &&
!And(mask_pawn_passed_w[square+8],BlackPawns) &&
((File(square) < FILEH && And(set_mask[square-7],WhitePawns) &&
!And(plus8dir[square-7],BlackPawns) &&
!And(plus8dir[square-6],BlackPawns)) ||
(File(square) > FILEA && And(set_mask[square-9],WhitePawns) &&
!And(plus8dir[square-9],BlackPawns) &&
!And(plus8dir[square-10],BlackPawns)))) {
pawn_score.p_score+=passed_pawn_value[Rank(square)];
}
#ifdef DEBUGP
printf("white pawn[hidden] file=%d,   score=%d\n",file,pawn_score.p_score);
#endif
if (!end_game) {
blocked=1;
do {
adv=2;
for (sq=square;sq<Min(square+24,A8);sq+=8) {
defenders=PopCnt(And(b_pawn_attacks[sq],wp_moves));
attackers=PopCnt(And(w_pawn_attacks[sq],BlackPawns));
if (attackers-defenders==2 ||
(attackers==1 && defenders==0)) break;
else if (attackers) {
blocked=0;
break;
}
if (And(set_mask[sq+8],all_pawns)) break;
adv=1;
}
if (sq >= Min(square+24,A8)) blocked=0;
} while(0);
if (blocked) w_blocked+=adv;
else w_unblocked++;
}
Clear(square,pawns);
}
pawns=BlackPawns;
while(pawns) {
b_weak=0;
square=FirstOne(pawns);
file=File(square);
pawn_score.p_score-=pawn_value_b[square];
#ifdef DEBUGP
printf("black pawn[static] file=%d,   score=%d\n",file,pawn_score.p_score);
#endif
if (!And(mask_pawn_isolated[square],BlackPawns)) {
b_isolated++;
b_weak=128;
}
else do {
weakness=0;
attackers=PopCnt(And(b_pawn_attacks[square],WhitePawns));
defenders=PopCnt(And(w_pawn_attacks[square],BlackPawns));
if (defenders > attackers) break;
for (sq=square-8;sq>H2;sq-=8) {
attackers=PopCnt(And(b_pawn_attacks[sq],WhitePawns));
defenders=PopCnt(And(w_pawn_attacks[sq],BlackPawns));
if (And(set_mask[sq],all_pawns)) {
weakness=1;
break;
}
if (attackers > defenders) {
weakness=attackers-defenders;
break;
}
else if (defenders && defenders >= attackers) break;
}
if (!weakness) break;
if ((temp=And(mask_no_pawn_attacks_b[square],BlackPawns))) {
if (file > FILEA) {
BITBOARD temp1=And(temp,file_mask[file-1]);
attackers=1;
if (temp1) {
int defend_sq=FirstOne(temp1);
for (sq=defend_sq;sq>=((Rank(square)+1)<<3);sq-=8) {
attackers=1;
if (sq!=defend_sq && And(all_pawns,set_mask[sq])) break;
attackers=PopCnt(And(b_pawn_attacks[sq],WhitePawns));
if (attackers) break;
}
if (!attackers) weakness=0;
}
if (!weakness) break;
}
if (file < FILEH) {
BITBOARD temp1=And(temp,file_mask[file+1]);
if (temp1) {
int defend_sq=FirstOne(temp1);
for (sq=defend_sq;sq>=((Rank(square)+1)<<3);sq-=8) {
attackers=1;
if (sq!=defend_sq && And(all_pawns,set_mask[sq])) break;
attackers=PopCnt(And(b_pawn_attacks[sq],WhitePawns));
if (attackers) break;
}
if (!attackers) weakness=0;
}
}
}
if (weakness > 0) {
b_weak=128;
if (weakness == 1) pawn_score.p_score+=PAWN_WEAK_P1;
else pawn_score.p_score+=PAWN_WEAK_P2;
}
} while(0);
if (b_weak) {
if (!And(minus8dir[square],WhitePawns)) {
pawn_score.black_pof++;
pawn_score.weak_b|=b_weak>>file;
}
}
#ifdef DEBUGP
printf("black pawn[weak] file=%d,     score=%d\n",file,pawn_score.p_score);
#endif
if (PopCnt(And(file_mask[file],BlackPawns)) > 1) {
pawn_score.p_score+=PAWN_DOUBLED;
}
#ifdef DEBUGP
printf("black pawn[doubled] file=%d,     score=%d\n",file,pawn_score.p_score);
#endif
if (!And(mask_pawn_passed_b[square],WhitePawns)) {
pawn_score.p_score-=passed_pawn_value[(RANK8-Rank(square))];
if (And(mask_pawn_protected_b[square],BlackPawns))
pawn_score.black_protected=1;
pawn_score.passed_b|=128>>file;
}
#ifdef DEBUGP
printf("black pawn[passed] file=%d,   score=%d\n",file,pawn_score.p_score);
#endif
if (Rank(square) < RANK5 && And(set_mask[square-8],WhitePawns) &&
!And(mask_pawn_passed_b[square-8],WhitePawns) &&
((File(square) < FILEH && And(set_mask[square+9],BlackPawns) &&
!And(minus8dir[square+9],WhitePawns) &&
!And(minus8dir[square+10],WhitePawns)) ||
(File(square) > FILEA && And(set_mask[square+7],BlackPawns) &&
!And(minus8dir[square+7],WhitePawns) &&
!And(minus8dir[square+6],WhitePawns)))) {
pawn_score.p_score-=passed_pawn_value[(RANK8-Rank(square))];
}
#ifdef DEBUGP
printf("black pawn[hidden] file=%d,   score=%d\n",file,pawn_score.p_score);
#endif
if (!end_game) {
blocked=1;
do {
adv=2;
for (sq=square;sq>Max(square-24,H1);sq-=8) {
attackers=PopCnt(And(b_pawn_attacks[sq],WhitePawns));
defenders=PopCnt(And(w_pawn_attacks[sq],bp_moves));
if (attackers-defenders==2 ||
(attackers==1 && defenders==0)) break;
else if (attackers) {
blocked=0;
break;
}
if (And(set_mask[sq-8],all_pawns)) break;
adv=1;
}
if (sq <= Max(square-24,H1)) blocked=0;
} while(0);
if (blocked) b_blocked+=adv;
else b_unblocked++;
}
Clear(square,pawns);
}
pawn_score.p_score+=PAWN_ISOLATED*b_isolated-PAWN_ISOLATED*w_isolated;
#ifdef DEBUGP
printf("pawn[isolated]          score=%d\n",pawn_score.p_score);
#endif
square=pawn_score.p_score;
pawn_score.p_score+=unblocked_pawns[w_unblocked]-
unblocked_pawns[b_unblocked];
if (root_wtm) pawn_score.p_score-=w_blocked*w_blocked*PAWN_BLOCKED;
else pawn_score.p_score+=b_blocked*b_blocked*PAWN_BLOCKED;
#ifdef DEBUGP
printf("pawn[blocked]           score=%d\n",pawn_score.p_score);
#endif
pawn_score.black_defects_k=0;
pawn_score.black_defects_q=0;
if (And(BlackPawns,set_mask[A7]));
else if (And(BlackPawns,set_mask[A6]))
pawn_score.black_defects_q+=KING_SAFETY_RP_ADV1;
else if (And(BlackPawns,set_mask[A5]))
pawn_score.black_defects_q+=KING_SAFETY_RP_ADV2;
else if (!And(BlackPawns,file_mask[FILEA]))
pawn_score.black_defects_q+=KING_SAFETY_RP_MISSING;
else
pawn_score.black_defects_q+=KING_SAFETY_RP_TOO_FAR;
if (!And(WhitePawns,file_mask[FILEA]))
pawn_score.black_defects_q+=KING_SAFETY_RP_FILE_OPEN;
if (And(BlackPawns,set_mask[H7]));
else if (And(BlackPawns,set_mask[H6]))
pawn_score.black_defects_k+=KING_SAFETY_RP_ADV1;
else if (And(BlackPawns,set_mask[H5]))
pawn_score.black_defects_k+=KING_SAFETY_RP_ADV2;
else if (!And(BlackPawns,file_mask[FILEH]))
pawn_score.black_defects_k+=KING_SAFETY_RP_MISSING;
else
pawn_score.black_defects_k+=KING_SAFETY_RP_TOO_FAR;
if (!And(WhitePawns,file_mask[FILEH]))
pawn_score.black_defects_k+=KING_SAFETY_RP_FILE_OPEN;
#ifdef DEBUGK
printf("black.RP, defects=%d(q)  %d(k)\n",
pawn_score.black_defects_q,pawn_score.black_defects_k);
#endif
if (And(set_mask[B7],BlackPawns));
else if (And(BlackPawns,set_mask[B6]))
pawn_score.black_defects_q+=KING_SAFETY_NP_ADV1;
else if (And(BlackPawns,set_mask[B5]))
pawn_score.black_defects_q+=KING_SAFETY_NP_ADV2;
else if (!And(BlackPawns,file_mask[FILEB]))
pawn_score.black_defects_q+=KING_SAFETY_NP_MISSING;
else
pawn_score.black_defects_q+=KING_SAFETY_NP_TOO_FAR;
if (!And(WhitePawns,file_mask[FILEB]))
pawn_score.black_defects_q+=KING_SAFETY_NP_FILE_OPEN;
if (And(set_mask[G7],BlackPawns));
else if (And(BlackPawns,set_mask[G6]))
pawn_score.black_defects_k+=KING_SAFETY_NP_ADV1;
else if (And(BlackPawns,set_mask[G5]))
pawn_score.black_defects_k+=KING_SAFETY_NP_ADV2;
else if (!And(BlackPawns,file_mask[FILEG]))
pawn_score.black_defects_k+=KING_SAFETY_NP_MISSING;
else
pawn_score.black_defects_k+=KING_SAFETY_NP_TOO_FAR;
if (!And(WhitePawns,file_mask[FILEG]))
pawn_score.black_defects_k+=KING_SAFETY_NP_FILE_OPEN;
#ifdef DEBUGK
printf("black.NP, defects=%d(q)  %d(k)\n",
pawn_score.black_defects_q,pawn_score.black_defects_k);
#endif
if (And(BlackPawns,set_mask[C7]));
else if (And(BlackPawns,set_mask[C6]))
pawn_score.black_defects_q+=KING_SAFETY_BP_ADV1;
else if (And(BlackPawns,set_mask[C5]))
pawn_score.black_defects_q+=KING_SAFETY_BP_ADV2;
else if (!And(BlackPawns,file_mask[FILEC]))
pawn_score.black_defects_q+=KING_SAFETY_BP_MISSING;
else
pawn_score.black_defects_q+=KING_SAFETY_BP_TOO_FAR;
if (!And(WhitePawns,file_mask[FILEC]))
pawn_score.black_defects_q+=KING_SAFETY_BP_FILE_OPEN;
if (And(BlackPawns,set_mask[F7]));
else if (And(BlackPawns,set_mask[F6]))
pawn_score.black_defects_k+=KING_SAFETY_BP_ADV1;
else if (And(BlackPawns,set_mask[F5]))
pawn_score.black_defects_k+=KING_SAFETY_BP_ADV2;
else if (!And(BlackPawns,file_mask[FILEF]))
pawn_score.black_defects_k+=KING_SAFETY_BP_MISSING;
else
pawn_score.black_defects_k+=KING_SAFETY_BP_TOO_FAR;
if (!And(WhitePawns,file_mask[FILEF]))
pawn_score.black_defects_k+=KING_SAFETY_BP_FILE_OPEN;
#ifdef DEBUGK
printf("black.BP, defects=%d(q)  %d(k)\n",
pawn_score.black_defects_q,pawn_score.black_defects_k);
#endif
if (!And(BlackPawns,set_mask[A7]) && !And(BlackPawns,set_mask[C7]))
pawn_score.black_defects_q+=KING_SAFETY_RP_BP_ADV1;
if (!And(BlackPawns,set_mask[F7]) && !And(BlackPawns,set_mask[H7]))
pawn_score.black_defects_k+=KING_SAFETY_RP_BP_ADV1;
#ifdef DEBUGK
printf("black.BRP, defects=%d(q)  %d(k)\n",
pawn_score.black_defects_q,pawn_score.black_defects_k);
#endif
if (And(WhitePawns,set_mask[F5])) {
if (PopCnt(And(BlackPawns,mask_no_pawn_attacks_b[F5])) < 2) {
adv=PopCnt(And(mask_wk_4th,WhitePawns));
pawn_score.black_defects_k+=adv*KING_SAFETY_PAWN_ATTACK_4TH;
adv=PopCnt(And(mask_wk_5th,WhitePawns));
pawn_score.black_defects_k+=adv*KING_SAFETY_PAWN_ATTACK_5TH;
}
}
if (And(WhitePawns,set_mask[C5])) {
if (PopCnt(And(BlackPawns,mask_no_pawn_attacks_b[C5])) < 2) {
adv=PopCnt(And(mask_wq_4th,WhitePawns));
pawn_score.black_defects_q+=adv*KING_SAFETY_PAWN_ATTACK_4TH;
adv=PopCnt(And(mask_wq_5th,WhitePawns));
pawn_score.black_defects_q+=adv*KING_SAFETY_PAWN_ATTACK_5TH;
}
}
#ifdef DEBUGK
printf("black.AT, defects=%d(q)  %d(k)\n",
pawn_score.black_defects_q,pawn_score.black_defects_k);
#endif
if (!root_wtm) {
if (PopCnt(And(WhitePawns,stonewall_white)) == 3)
pawn_score.black_defects_k+=KING_SAFETY_STONEWALL;
}
#ifdef DEBUGK
printf("black.SW, defects=%d(q)  %d(k)\n",
pawn_score.black_defects_q,pawn_score.black_defects_k);
#endif
pawn_score.white_defects_k=0;
pawn_score.white_defects_q=0;
if (And(WhitePawns,set_mask[A2]));
else if (And(WhitePawns,set_mask[A3]))
pawn_score.white_defects_q+=KING_SAFETY_RP_ADV1;
else if (And(WhitePawns,set_mask[A4]))
pawn_score.white_defects_q+=KING_SAFETY_RP_ADV2;
else if (!And(WhitePawns,file_mask[FILEA]))
pawn_score.white_defects_q+=KING_SAFETY_RP_MISSING;
else
pawn_score.white_defects_q+=KING_SAFETY_RP_TOO_FAR;
if (!And(BlackPawns,file_mask[FILEA]))
pawn_score.white_defects_q+=KING_SAFETY_RP_FILE_OPEN;
if (And(WhitePawns,set_mask[H2]));
else if (And(WhitePawns,set_mask[H3]))
pawn_score.white_defects_k+=KING_SAFETY_RP_ADV1;
else if (And(WhitePawns,set_mask[H4]))
pawn_score.white_defects_k+=KING_SAFETY_RP_ADV2;
else if (!And(WhitePawns,file_mask[FILEH]))
pawn_score.white_defects_k+=KING_SAFETY_RP_MISSING;
else
pawn_score.white_defects_k+=KING_SAFETY_RP_TOO_FAR;
if (!And(BlackPawns,file_mask[FILEH]))
pawn_score.white_defects_k+=KING_SAFETY_RP_FILE_OPEN;
#ifdef DEBUGK
printf("white.RP, defects=%d(q)  %d(k)\n",
pawn_score.white_defects_q,pawn_score.white_defects_k);
#endif
if (And(set_mask[B2],WhitePawns));
else if (And(WhitePawns,set_mask[B3]))
pawn_score.white_defects_q+=KING_SAFETY_NP_ADV1;
else if (And(WhitePawns,set_mask[B4]))
pawn_score.white_defects_q+=KING_SAFETY_NP_ADV2;
else if (!And(WhitePawns,file_mask[FILEB]))
pawn_score.white_defects_q+=KING_SAFETY_NP_MISSING;
else
pawn_score.white_defects_q+=KING_SAFETY_NP_TOO_FAR;
if (!And(BlackPawns,file_mask[FILEB]))
pawn_score.white_defects_q+=KING_SAFETY_NP_FILE_OPEN;
if (And(set_mask[G2],WhitePawns));
else if (And(WhitePawns,set_mask[G3]))
pawn_score.white_defects_k+=KING_SAFETY_NP_ADV1;
else if (And(WhitePawns,set_mask[G4]))
pawn_score.white_defects_k+=KING_SAFETY_NP_ADV2;
else if (!And(WhitePawns,file_mask[FILEG]))
pawn_score.white_defects_k+=KING_SAFETY_NP_MISSING;
else
pawn_score.white_defects_k+=KING_SAFETY_NP_TOO_FAR;
if (!And(BlackPawns,file_mask[FILEG]))
pawn_score.white_defects_k+=KING_SAFETY_NP_FILE_OPEN;
#ifdef DEBUGK
printf("white.NP, defects=%d(q)  %d(k)\n",
pawn_score.white_defects_q,pawn_score.white_defects_k);
#endif
if (And(WhitePawns,set_mask[C2]));
else if (And(WhitePawns,set_mask[C3]))
pawn_score.white_defects_q+=KING_SAFETY_BP_ADV1;
else if (And(WhitePawns,set_mask[C4]))
pawn_score.white_defects_q+=KING_SAFETY_BP_ADV2;
else if (!And(WhitePawns,file_mask[FILEC]))
pawn_score.white_defects_q+=KING_SAFETY_BP_MISSING;
else
pawn_score.white_defects_q+=KING_SAFETY_BP_TOO_FAR;
if (!And(BlackPawns,file_mask[FILEC]))
pawn_score.white_defects_q+=KING_SAFETY_BP_FILE_OPEN;
if (And(WhitePawns,set_mask[F2]));
else if (And(WhitePawns,set_mask[F3]))
pawn_score.white_defects_k+=KING_SAFETY_BP_ADV1;
else if (And(WhitePawns,set_mask[F4]))
pawn_score.white_defects_k+=KING_SAFETY_BP_ADV2;
else if (!And(WhitePawns,file_mask[FILEF]))
pawn_score.white_defects_k+=KING_SAFETY_BP_MISSING;
else
pawn_score.white_defects_k+=KING_SAFETY_BP_TOO_FAR;
if (!And(BlackPawns,file_mask[FILEF]))
pawn_score.white_defects_k+=KING_SAFETY_BP_FILE_OPEN;
#ifdef DEBUGK
printf("white.BP, defects=%d(q)  %d(k)\n",
pawn_score.white_defects_q,pawn_score.white_defects_k);
#endif
if (!And(WhitePawns,set_mask[A2]) && !And(WhitePawns,set_mask[C2]))
pawn_score.white_defects_q+=KING_SAFETY_RP_BP_ADV1;
if (!And(WhitePawns,set_mask[F2]) && !And(WhitePawns,set_mask[H2]))
pawn_score.white_defects_k+=KING_SAFETY_RP_BP_ADV1;
#ifdef DEBUGK
printf("white.BRP, defects=%d(q)  %d(k)\n",
pawn_score.white_defects_q,pawn_score.white_defects_k);
#endif
if (And(BlackPawns,set_mask[F4])) {
if (PopCnt(And(WhitePawns,mask_no_pawn_attacks_w[F4])) < 2) {
adv=PopCnt(And(mask_bk_4th,BlackPawns));
pawn_score.white_defects_k+=adv*KING_SAFETY_PAWN_ATTACK_4TH;
adv=PopCnt(And(mask_bk_5th,BlackPawns));
pawn_score.white_defects_k+=adv*KING_SAFETY_PAWN_ATTACK_5TH;
}
}
if (And(BlackPawns,set_mask[C4])) {
if (PopCnt(And(WhitePawns,mask_no_pawn_attacks_w[C4])) < 2) {
adv=PopCnt(And(mask_bq_5th,BlackPawns));
pawn_score.white_defects_q+=adv*KING_SAFETY_PAWN_ATTACK_4TH;
adv=PopCnt(And(mask_bq_4th,BlackPawns));
pawn_score.white_defects_q+=adv*KING_SAFETY_PAWN_ATTACK_5TH;
}
}
#ifdef DEBUGK
printf("white.AT, defects=%d(q)  %d(k)\n",
pawn_score.white_defects_q,pawn_score.white_defects_k);
#endif
if (root_wtm) {
if (PopCnt(And(BlackPawns,stonewall_black)) == 3)
pawn_score.white_defects_k+=KING_SAFETY_STONEWALL;
}
#ifdef DEBUGK
printf("black.SW, defects=%d(q)  %d(k)\n",
pawn_score.black_defects_q,pawn_score.black_defects_k);
#endif
pawn_score.outside=0;
w_file_l=first_ones_8bit[pawn_score.passed_w];
if (w_file_l == 8) w_file_l=9;
b_file_l=first_ones_8bit[pawn_score.passed_b];
if (b_file_l == 8) b_file_l=9;
w_file_r=last_ones_8bit[pawn_score.passed_w];
if (w_file_r == 8) w_file_r=-9;
b_file_r=last_ones_8bit[pawn_score.passed_b];
if (b_file_r == 8) b_file_r=-9;
if (w_file_l != 9) {
if ((w_file_l < b_file_l-1) || (w_file_r > b_file_r+1)) do {
if (w_file_l < 4) {
if(And(all_pawns,right_side_mask[w_file_l]) &&
!And(BlackPawns,left_side_empty_mask[w_file_l])) {
if (!pawn_score.black_protected ||
pawn_score.white_protected) pawn_score.outside|=1;
break;
}
}
if (w_file_r > 3) {
if (And(all_pawns,left_side_mask[w_file_r]) &&
!And(BlackPawns,right_side_empty_mask[w_file_r])) {
if (!pawn_score.black_protected ||
pawn_score.white_protected) pawn_score.outside|=1;
}
}
} while(0);
}
if (b_file_l != 9) {
if ((b_file_l < w_file_l-1) || (b_file_r > w_file_r+1)) do {
if (b_file_l < 4) {
if(And(all_pawns,right_side_mask[b_file_l]) &&
!And(WhitePawns,left_side_empty_mask[b_file_l])) {
if (!pawn_score.white_protected ||
pawn_score.black_protected) pawn_score.outside|=2;
break;
}
}
if (b_file_r > 3) {
if (And(all_pawns,left_side_mask[b_file_r]) &&
!And(WhitePawns,right_side_empty_mask[b_file_r])) {
if (!pawn_score.white_protected ||
pawn_score.black_protected) pawn_score.outside|=2;
}
}
} while(0);
}
if (!pawn_score.outside) {
if (pawn_score.white_protected && !pawn_score.black_protected)
pawn_score.outside|=1;
if (pawn_score.black_protected && !pawn_score.white_protected)
pawn_score.outside|=2;
}
*ptable=pawn_score;
return(pawn_score.p_score);
}
/* 当前文件是D:\Read\history.c*/

void HistoryBest(int ply, int depth, int wtm)
{
register int index, temp;
if (CaptureOrPromote(pv[ply].path[ply])) return;
index=pv[ply].path[ply] & 4095;
if (wtm) history_w[index]+=depth*depth;
else history_b[index]+=depth*depth;
if (killer_move1[ply] == pv[ply].path[ply]) killer_count1[ply]++;
else if (killer_move2[ply] == pv[ply].path[ply]) {
killer_count2[ply]++;
if (killer_count1[ply] < killer_count2[ply]) {
temp=killer_count1[ply];
killer_count1[ply]=killer_count2[ply];
killer_count2[ply]=temp;
temp=killer_move1[ply];
killer_move1[ply]=killer_move2[ply];
killer_move2[ply]=temp;
}
}
else {
killer_count2[ply]=1;
killer_move2[ply]=pv[ply].path[ply];
}
}
void HistoryRefutation(int ply, int depth, int wtm)
{
register int index, temp;
if (CaptureOrPromote(current_move[ply])) return;
index=current_move[ply] & 4095;
if (wtm) history_w[index]+=depth*depth;
else history_b[index]+=depth*depth;
if (killer_move1[ply] == current_move[ply]) killer_count1[ply]++;
else if (killer_move2[ply] == current_move[ply]) {
killer_count2[ply]++;
if (killer_count1[ply] < killer_count2[ply]) {
temp=killer_count1[ply];
killer_count1[ply]=killer_count2[ply];
killer_count2[ply]=temp;
temp=killer_move1[ply];
killer_move1[ply]=killer_move2[ply];
killer_move2[ply]=temp;
}
}
else {
killer_count2[ply]=1;
killer_move2[ply]=current_move[ply];
}
}
/* 当前文件是D:\Read\init.c*/

#if defined(UNIX) || defined(AMIGA)
#  include <unistd.h>
#endif
#if defined(NT_i386) || defined(NT_AXP)
#  include <fcntl.h>
#endif
int init_r90[64] = { 56, 48, 40, 32, 24, 16,  8,  0,
57, 49, 41, 33, 25, 17,  9,  1,
58, 50, 42, 34, 26, 18, 10,  2,
59, 51, 43, 35, 27, 19, 11,  3,
60, 52, 44, 36, 28, 20, 12,  4,
61, 53, 45, 37, 29, 21, 13,  5,
62, 54, 46, 38, 30, 22, 14,  6,
63, 55, 47, 39, 31, 23, 15,  7 };
int init_l90[64] = {  7, 15, 23, 31, 39, 47, 55, 63,
6, 14, 22, 30, 38, 46, 54, 62,
5, 13, 21, 29, 37, 45, 53, 61,
4, 12, 20, 28, 36, 44, 52, 60,
3, 11, 19, 27, 35, 43, 51, 59,
2, 10, 18, 26, 34, 42, 50, 58,
1,  9, 17, 25, 33, 41, 49, 57,
0,  8, 16, 24, 32, 40, 48, 56 };
int init_l45[64] = {                0,
2,  5,
9, 14, 20,
27, 35,  1,  4,
8, 13, 19, 26, 34,
42,  3,  7, 12, 18, 25,
33, 41, 48,  6, 11, 17, 24,
32, 40, 47, 53, 10, 16, 23, 31,
39, 46, 52, 57, 15, 22, 30,
38, 45, 51, 56, 60, 21,
29, 37, 44, 50, 55,
59, 62, 28, 36,
43, 49, 54,
58, 61,
63 };
int init_ul45[64] = {               0,
8,  1,
16,  9,  2,
24, 17, 10,  3,
32, 25, 18, 11,  4,
40, 33, 26, 19, 12,  5,
48, 41, 34, 27, 20, 13,  6,
56, 49, 42, 35, 28, 21, 14,  7,
57, 50, 43, 36, 29, 22, 15,
58, 51, 44, 37, 30, 23,
59, 52, 45, 38, 31,
60, 53, 46, 39,
61, 54, 47,
62, 55,
63 };
int init_r45[64] = {               28,
21, 15,
10,  6,  3,
1,  0, 36, 29,
22, 16, 11,  7,  4,
2, 43, 37, 30, 23, 17,
12,  8,  5, 49, 44, 38, 31,
24, 18, 13,  9, 54, 50, 45, 39,
32, 25, 19, 14, 58, 55, 51,
46, 40, 33, 26, 20, 61,
59, 56, 52, 47, 41,
34, 27, 63, 62,
60, 57, 53,
48, 42,
35  };
int init_ur45[64] = {               7,
6, 15,
5, 14, 23,
4, 13, 22, 31,
3, 12, 21, 30, 39,
2, 11, 20, 29, 38, 47,
1, 10, 19, 28, 37, 46, 55,
0,  9, 18, 27, 36, 45, 54, 63,
8, 17, 26, 35, 44, 53, 62,
16, 25, 34, 43, 52, 61,
24, 33, 42, 51, 60,
32, 41, 50, 59,
40, 49, 58,
48, 57,
56 };
int diagonal_length[64] = {         1,
2,  2,
3,  3,  3,
4,  4,  4,  4,
5,  5,  5,  5,  5,
6,  6,  6,  6,  6,  6,
7,  7,  7,  7,  7,  7,  7,
8,  8,  8,  8,  8,  8,  8,  8,
7,  7,  7,  7,  7,  7,  7,
6,  6,  6,  6,  6,  6,
5,  5,  5,  5,  5,
4,  4,  4,  4,
3,  3,  3,
2,  2,
1 };
void Initialize(int continuing)
{
int i=0;
InitializeZeroMasks();
InitializeMasks();
InitializeRandomHash();
InitializeAttackBoards();
InitializePawnMasks();
InitializePieceMasks();
InitializeChessBoard(&position[0]);
#if defined(NT_i386) || defined(NT_AXP)
_fmode = _O_BINARY;
#endif
last[0]=move_list;
if (continuing) {
history_file=fopen("game.001","r+");
if (!log_file || !history_file) {
printf("\nsorry.  nothing to continue.\n\n");
history_file=fopen("game.001","w+");
}
else {
sprintf(buffer,"read game.001");
(void) Option();
}
}
else {
history_file=fopen("game.001","w+");
}
trans_ref_wa=malloc(16*hash_table_size);
trans_ref_wb=malloc(16*2*hash_table_size);
trans_ref_ba=malloc(16*hash_table_size);
trans_ref_bb=malloc(16*2*hash_table_size);
pawn_hash_table=malloc(sizeof(PAWN_HASH_ENTRY)*pawn_hash_table_size);
InitializeHashTables();
if (!trans_ref_wa || !trans_ref_wb || !trans_ref_ba || !trans_ref_bb ) {
printf("malloc() failed, not enough memory.\n");
free(trans_ref_wa);
free(trans_ref_wb);
free(trans_ref_ba);
free(trans_ref_bb);
free(pawn_hash_table);
hash_table_size=0;
pawn_hash_table_size=0;
log_hash=0;
log_pawn_hash=0;
trans_ref_wa=0;
trans_ref_wb=0;
trans_ref_ba=0;
trans_ref_bb=0;
pawn_hash_table=0;
}
hash_maska=(1<<log_hash)-1;
hash_maskb=(1<<(log_hash+1))-1;
pawn_hash_mask=((unsigned int) 037777777777)>>(32-log_pawn_hash);
}
void InitializeAttackBoards(void)
{
int i, j, frank, ffile, trank, tfile;
int sq, lastsq;
int knightsq[8]={-17,-15,-10,-6,6,10,15,17};
int bishopsq[4]={-9,-7,7,9};
int rooksq[4]={-8,-1,1,8};
BITBOARD sqs;
for(i=0;i<64;i++) {
w_pawn_attacks[i]=0;
if (i < 56)
for(j=2;j<4;j++) {
sq=i+bishopsq[j];
if((abs(sq/8-i/8)==1) &&
(abs((sq&7) - (i&7))==1) &&
(sq < 64) && (sq > -1))
w_pawn_attacks[i]=Or(w_pawn_attacks[i],Shiftr(mask_1,sq));
}
b_pawn_attacks[i]=0;
if (i > 7)
for(j=0;j<2;j++) {
sq=i+bishopsq[j];
if((abs(sq/8-i/8)==1) &&
(abs((sq&7)-(i&7))==1) &&
(sq < 64) && (sq > -1))
b_pawn_attacks[i]=Or(b_pawn_attacks[i],Shiftr(mask_1,sq));
}
}
for(i=0;i<64;i++) {
knight_attacks[i]=0;
frank=i/8;
ffile=i&7;
for(j=0;j<8;j++) {
sq=i+knightsq[j];
if((sq < 0) || (sq > 63)) continue;
trank=sq/8;
tfile=sq&7;
if((abs(frank-trank) > 2) ||
(abs(ffile-tfile) > 2)) continue;
knight_attacks[i]=Or(knight_attacks[i],Shiftr(mask_1,sq));
}
}
for(i=0;i<64;i++) {
bishop_attacks[i]=0;
for(j=0;j<4;j++) {
sq=i;
lastsq=sq;
sq=sq+bishopsq[j];
while((abs(sq/8-lastsq/8)==1) &&
(abs((sq&7)-(lastsq&7))==1) &&
(sq < 64) && (sq > -1)) {
bishop_attacks[i]=Or(bishop_attacks[i],Shiftr(mask_1,sq));
queen_attacks[i]=Or(queen_attacks[i],Shiftr(mask_1,sq));
if(bishopsq[j]==7)
plus7dir[i]=Or(plus7dir[i],Shiftr(mask_1,sq));
else if(bishopsq[j]==9)
plus9dir[i]=Or(plus9dir[i],Shiftr(mask_1,sq));
else if(bishopsq[j]==-7)
minus7dir[i]=Or(minus7dir[i],Shiftr(mask_1,sq));
else
minus9dir[i]=Or(minus9dir[i],Shiftr(mask_1,sq));
lastsq=sq;
sq=sq+bishopsq[j];
}
}
}
plus1dir[64]=0;
plus7dir[64]=0;
plus8dir[64]=0;
plus9dir[64]=0;
minus1dir[64]=0;
minus7dir[64]=0;
minus8dir[64]=0;
minus9dir[64]=0;
for(i=0;i<64;i++) {
rook_attacks[i]=0;
for(j=0;j<4;j++) {
sq=i;
lastsq=sq;
sq=sq+rooksq[j];
while((((abs(sq/8-lastsq/8)==1) &&
(abs((sq&7)-(lastsq&7))==0)) ||
((abs(sq/8-lastsq/8)==0) &&
(abs((sq&7)-(lastsq&7))==1))) &&
(sq < 64) && (sq > -1)) {
rook_attacks[i]=Or(rook_attacks[i],Shiftr(mask_1,sq));
queen_attacks[i]=Or(queen_attacks[i],Shiftr(mask_1,sq));
if(rooksq[j]==1)
plus1dir[i]=Or(plus1dir[i],Shiftr(mask_1,sq));
else if(rooksq[j]==8)
plus8dir[i]=Or(plus8dir[i],Shiftr(mask_1,sq));
else if(rooksq[j]==-1)
minus1dir[i]=Or(minus1dir[i],Shiftr(mask_1,sq));
else
minus8dir[i]=Or(minus8dir[i],Shiftr(mask_1,sq));
lastsq=sq;
sq=sq+rooksq[j];
}
}
}
for(i=0;i<64;i++) {
king_attacks[i]=0;
king_attacks_1[i]=0;
king_attacks_2[i]=0;
for (j=0;j<64;j++) {
if (Distance(i,j) == 1)
king_attacks[i]=Or(king_attacks[i],set_mask[j]);
if (Distance(i,j) <= 1)
king_attacks_1[i]=Or(king_attacks_1[i],set_mask[j]);
if (Distance(i,j) <= 2)
king_attacks_2[i]=Or(king_attacks_2[i],set_mask[j]);
}
}
for (i=0;i<64;i++) {
for (j=0;j<64;j++)
obstructed[i][j]=(BITBOARD) -1;
sqs=plus1dir[i];
while (sqs) {
j=FirstOne(sqs);
directions[i][j]=1;
obstructed[i][j]=Xor(plus1dir[i],plus1dir[j-1]);
Clear(j,sqs);
}
sqs=plus7dir[i];
while (sqs) {
j=FirstOne(sqs);
directions[i][j]=7;
obstructed[i][j]=Xor(plus7dir[i],plus7dir[j-7]);
Clear(j,sqs);
}
sqs=plus8dir[i];
while (sqs) {
j=FirstOne(sqs);
directions[i][j]=8;
obstructed[i][j]=Xor(plus8dir[i],plus8dir[j-8]);
Clear(j,sqs);
}
sqs=plus9dir[i];
while (sqs) {
j=FirstOne(sqs);
directions[i][j]=9;
obstructed[i][j]=Xor(plus9dir[i],plus9dir[j-9]);
Clear(j,sqs);
}
sqs=minus1dir[i];
while (sqs) {
j=FirstOne(sqs);
directions[i][j]=-1;
obstructed[i][j]=Xor(minus1dir[i],minus1dir[j+1]);
Clear(j,sqs);
}
sqs=minus7dir[i];
while (sqs) {
j=FirstOne(sqs);
directions[i][j]=-7;
obstructed[i][j]=Xor(minus7dir[i],minus7dir[j+7]);
Clear(j,sqs);
}
sqs=minus8dir[i];
while (sqs) {
j=FirstOne(sqs);
directions[i][j]=-8;
obstructed[i][j]=Xor(minus8dir[i],minus8dir[j+8]);
Clear(j,sqs);
}
sqs=minus9dir[i];
while (sqs) {
j=FirstOne(sqs);
directions[i][j]=-9;
obstructed[i][j]=Xor(minus9dir[i],minus9dir[j+9]);
Clear(j,sqs);
}
}
{
int diag_sq[64] = {                0,
1,  0,
2,  1,  0,
3,  2,  1,  0,
4,  3,  2,  1,  0,
5,  4,  3,  2,  1,  0,
6,  5,  4,  3,  2,  1,  0,
7,  6,  5,  4,  3,  2,  1,  0,
6,  5,  4,  3,  2,  1,  0,
5,  4,  3,  2,  1,  0,
4,  3,  2,  1,  0,
3,  2,  1,  0,
2,  1,  0,
1,  0,
0 };
int bias_rl45[64] = {              0,
1,  1,
3,  3,  3,
6,  6,  6,  6,
10, 10, 10, 10, 10,
15, 15, 15, 15, 15, 15,
21, 21, 21, 21, 21, 21, 21,
28, 28, 28, 28, 28, 28, 28, 28,
36, 36, 36, 36, 36, 36, 36,
43, 43, 43, 43, 43, 43,
49, 49, 49, 49, 49,
54, 54, 54, 54,
58, 58, 58,
61, 61,
63 };
int square, pcs, attacks;
int rsq, tsq;
int mask;
for (square=0;square<64;square++) {
for (i=0;i<256;i++) {
rook_attacks_r0[square][i]=0;
rook_mobility_r0[square][i]=0;
}
for (pcs=0;pcs<256;pcs++) {
attacks=InitializeFindAttacks(7-File(square),pcs,8);
while (attacks) {
sq=first_ones_8bit[attacks];
rook_attacks_r0[square][pcs]=
Or(rook_attacks_r0[square][pcs],set_mask[(square&56)+sq]);
attacks=attacks&(~(1<<(7-sq)));
}
rook_mobility_r0[square][pcs]=PopCnt(rook_attacks_r0[square][pcs]);
}
}
for (square=0;square<64;square++) {
for (i=0;i<256;i++) {
rook_attacks_rl90[square][i]=0;
rook_mobility_rl90[square][i]=0;
}
for (pcs=0;pcs<256;pcs++) {
attacks=InitializeFindAttacks(Rank(square),pcs,8);
while (attacks) {
sq=first_ones_8bit[attacks];
rook_attacks_rl90[square][pcs]=
Or(rook_attacks_rl90[square][pcs],
set_mask[init_r90[((square&7)<<3)+sq]]);
attacks=attacks&(~(1<<(7-sq)));
}
rook_mobility_rl90[square][pcs]=PopCnt(rook_attacks_rl90[square][pcs]);
}
}
for (square=0;square<64;square++) {
for (i=0;i<256;i++) {
bishop_attacks_rl45[square][i]=0;
bishop_mobility_rl45[square][i]=0;
}
for (pcs=0;pcs<(1<<diagonal_length[init_l45[square]]);pcs++) {
rsq=init_l45[square];
tsq=diag_sq[rsq];
attacks=InitializeFindAttacks(tsq,pcs,diagonal_length[rsq])<<
(8-diagonal_length[rsq]);
while (attacks) {
sq=first_ones_8bit[attacks];
bishop_attacks_rl45[square][pcs]=
Or(bishop_attacks_rl45[square][pcs],
set_mask[init_ul45[sq+bias_rl45[rsq]]]);
attacks=attacks&(~(1<<(7-sq)));
}
}
mask=(1<<diagonal_length[init_l45[square]])-1;
for (pcs=0;pcs<256;pcs++) {
if ((pcs&mask) != pcs)
bishop_attacks_rl45[square][pcs]=
bishop_attacks_rl45[square][pcs&mask];
bishop_mobility_rl45[square][pcs]=
PopCnt(bishop_attacks_rl45[square][pcs]);
}
}
for (square=0;square<64;square++) {
for (i=0;i<256;i++) {
bishop_attacks_rr45[square][i]=0;
bishop_mobility_rr45[square][i]=0;
}
for (pcs=0;pcs<(1<<diagonal_length[init_r45[square]]);pcs++) {
rsq=init_r45[square];
tsq=diag_sq[rsq];
attacks=InitializeFindAttacks(tsq,pcs,diagonal_length[rsq])<<
(8-diagonal_length[rsq]);
while (attacks) {
sq=first_ones_8bit[attacks];
bishop_attacks_rr45[square][pcs]=
Or(bishop_attacks_rr45[square][pcs],
set_mask[init_ur45[sq+bias_rl45[rsq]]]);
attacks=attacks&(~(1<<(7-sq)));
}
}
mask=(1<<diagonal_length[init_r45[square]])-1;
for (pcs=0;pcs<256;pcs++) {
if ((pcs&mask) != pcs)
bishop_attacks_rr45[square][pcs]=
bishop_attacks_rr45[square][pcs&mask];
bishop_mobility_rr45[square][pcs]=
PopCnt(bishop_attacks_rr45[square][pcs]);
}
}
}
}
void InitializeChessBoard(SEARCH_POSITION *new_pos)
{
int i;
if (strlen(initial_position)) {
static char a1[80], a2[16], a3[16], a4[16], a5[16];
static char *args[16]={a1,a2,a3,a4,a5,a5,a5,a5,a5,a5,a5,a5,a5,a5,a5,a5};
int nargs;
nargs=ReadParse(initial_position,args," ;");
SetBoard(nargs,args,1);
}
else {
for(i=0;i<64;i++) search.board[i]=empty;
new_pos->rule_50_moves=0;
opening=1;
middle_game=0;
end_game=0;
largest_positional_score=60;
for (i=0;i<8;i++) {
search.board[i+8]=pawn;
search.board[i+48]=-pawn;
}
search.board[B1]=knight;
search.board[G1]=knight;
search.board[B8]=-knight;
search.board[G8]=-knight;
search.board[C1]=bishop;
search.board[F1]=bishop;
search.board[C8]=-bishop;
search.board[F8]=-bishop;
search.board[A1]=rook;
search.board[H1]=rook;
search.board[A8]=-rook;
search.board[H8]=-rook;
search.board[D1]=queen;
search.board[D8]=-queen;
search.board[E1]=king;
search.board[E8]=-king;
new_pos->w_castle=3;
new_pos->b_castle=3;
new_pos->enpassant_target=0;
SetChessBitBoards(new_pos);
}
}
void SetChessBitBoards(SEARCH_POSITION *new_pos)
{
int i;
search.hash_key=0;
search.pawn_hash_key=0;
search.w_pawn=0;
search.b_pawn=0;
for (i=0;i<64;i++) {
if(search.board[i]==pawn) {
search.w_pawn=Or(search.w_pawn,set_mask[i]);
search.hash_key=Xor(search.hash_key,w_pawn_random[i]);
search.pawn_hash_key=search.pawn_hash_key^w_pawn_random32[i];
}
if(search.board[i]==-pawn) {
search.b_pawn=Or(search.b_pawn,set_mask[i]);
search.hash_key=Xor(search.hash_key,b_pawn_random[i]);
search.pawn_hash_key=search.pawn_hash_key^b_pawn_random32[i];
}
}
search.w_knight=0;
search.b_knight=0;
for (i=0;i<64;i++) {
if(search.board[i] == knight) {
search.w_knight=Or(search.w_knight,set_mask[i]);
search.hash_key=Xor(search.hash_key,w_knight_random[i]);
}
if(search.board[i] == -knight) {
search.b_knight=Or(search.b_knight,set_mask[i]);
search.hash_key=Xor(search.hash_key,b_knight_random[i]);
}
}
search.w_bishop=0;
search.b_bishop=0;
for (i=0;i<64;i++) {
if(search.board[i] == bishop) {
search.w_bishop=Or(search.w_bishop,set_mask[i]);
search.hash_key=Xor(search.hash_key,w_bishop_random[i]);
}
if(search.board[i] == -bishop) {
search.b_bishop=Or(search.b_bishop,set_mask[i]);
search.hash_key=Xor(search.hash_key,b_bishop_random[i]);
}
}
search.w_rook=0;
search.b_rook=0;
for (i=0;i<64;i++) {
if(search.board[i] == rook) {
search.w_rook=Or(search.w_rook,set_mask[i]);
search.hash_key=Xor(search.hash_key,w_rook_random[i]);
}
if(search.board[i] == -rook) {
search.b_rook=Or(search.b_rook,set_mask[i]);
search.hash_key=Xor(search.hash_key,b_rook_random[i]);
}
}
search.w_queen=0;
search.b_queen=0;
for (i=0;i<64;i++) {
if(search.board[i] == queen) {
search.w_queen=Or(search.w_queen,set_mask[i]);
search.hash_key=Xor(search.hash_key,w_queen_random[i]);
}
if(search.board[i] == -queen) {
search.b_queen=Or(search.b_queen,set_mask[i]);
search.hash_key=Xor(search.hash_key,b_queen_random[i]);
}
}
for (i=0;i<64;i++) {
if(search.board[i] == king) {
search.white_king=i;
search.hash_key=Xor(search.hash_key,w_king_random[i]);
}
if(search.board[i] == -king) {
search.black_king=i;
search.hash_key=Xor(search.hash_key,b_king_random[i]);
}
}
if (new_pos->enpassant_target)
HashEP(new_pos->enpassant_target,search.hash_key);
if (!(new_pos->w_castle&1)) HashCastleW(0,search.hash_key);
if (!(new_pos->w_castle&2)) HashCastleW(1,search.hash_key);
if (!(new_pos->b_castle&1)) HashCastleB(0,search.hash_key);
if (!(new_pos->b_castle&2)) HashCastleB(1,search.hash_key);
search.bishops_queens=Or(Or(Or(search.w_bishop,search.w_queen),search.b_bishop),search.b_queen);
search.rooks_queens=Or(Or(Or(search.w_rook,search.w_queen),search.b_rook),search.b_queen);
search.w_occupied=Or(Or(Or(Or(Or(search.w_pawn,search.w_knight),search.w_bishop),search.w_rook),
search.w_queen),set_mask[search.white_king]);
search.b_occupied=Or(Or(Or(Or(Or(search.b_pawn,search.b_knight),search.b_bishop),search.b_rook),
search.b_queen),set_mask[search.black_king]);
search.occupied_rl90=0;
search.occupied_rl45=0;
search.occupied_rr45=0;
for (i=0;i<64;i++) {
if (search.board[i]) {
search.occupied_rl90=Or(search.occupied_rl90,set_mask_rl90[i]);
search.occupied_rl45=Or(search.occupied_rl45,set_mask_rl45[i]);
search.occupied_rr45=Or(search.occupied_rr45,set_mask_rr45[i]);
}
}
search.white_pieces=0;
search.white_pawns=0;
search.black_pieces=0;
search.black_pawns=0;
search.material_evaluation=0;
for (i=0;i<64;i++) {
switch (search.board[i]) {
case pawn:
search.material_evaluation+=PAWN_VALUE;
search.white_pawns+=pawn_v;
break;
case knight:
search.material_evaluation+=KNIGHT_VALUE;
search.white_pieces+=knight_v;
break;
case bishop:
search.material_evaluation+=BISHOP_VALUE;
search.white_pieces+=bishop_v;
break;
case rook:
search.material_evaluation+=ROOK_VALUE;
search.white_pieces+=rook_v;
break;
case queen:
search.material_evaluation+=QUEEN_VALUE;
search.white_pieces+=queen_v;
break;
case -pawn:
search.material_evaluation-=PAWN_VALUE;
search.black_pawns+=pawn_v;
break;
case -knight:
search.material_evaluation-=KNIGHT_VALUE;
search.black_pieces+=knight_v;
break;
case -bishop:
search.material_evaluation-=BISHOP_VALUE;
search.black_pieces+=bishop_v;
break;
case -rook:
search.material_evaluation-=ROOK_VALUE;
search.black_pieces+=rook_v;
break;
case -queen:
search.material_evaluation-=QUEEN_VALUE;
search.black_pieces+=queen_v;
break;
default:
;
}
}
TotalPieces=PopCnt(Occupied);
if (new_pos == &position[0]) {
rephead_b=replist_b;
rephead_w=replist_w;
}
}
int InitializeFindAttacks(int square, int pieces, int length)
{
int result, start;
result=0;
if (square < 7) {
start=1<<(square+1);
while (start < 256) {
result=result | start;
if (pieces & start) break;
start=start<<1;
}
}
if (square > 0) {
start=1<<(square-1);
while (start > 0) {
result=result | start;
if (pieces & start) break;
start=start>>1;
}
}
return(result&((1<<length)-1));
}
void InitializeHashTables(void)
{
int i;
transposition_id=0;
for (i=0;i<hash_table_size;i++) {
(trans_ref_wa+i)->word1=Shiftl((BITBOARD) 7,61);
(trans_ref_wa+i)->word2=0;
(trans_ref_ba+i)->word1=Shiftl((BITBOARD) 7,61);
(trans_ref_ba+i)->word2=0;
}
for (i=0;i<2*hash_table_size;i++) {
(trans_ref_wb+i)->word1=Shiftl((BITBOARD) 7,61);
(trans_ref_wb+i)->word2=0;
(trans_ref_bb+i)->word1=Shiftl((BITBOARD) 7,61);
(trans_ref_bb+i)->word2=0;
}
for (i=0;i<pawn_hash_table_size;i++) {
(pawn_hash_table+i)->key=0;
(pawn_hash_table+i)->p_score=0;
(pawn_hash_table+i)->black_protected=0;
(pawn_hash_table+i)->white_protected=0;
(pawn_hash_table+i)->black_pof=0;
(pawn_hash_table+i)->white_pof=0;
(pawn_hash_table+i)->weak_b=0;
(pawn_hash_table+i)->weak_w=0;
(pawn_hash_table+i)->black_defects_k=0;
(pawn_hash_table+i)->black_defects_q=0;
(pawn_hash_table+i)->white_defects_k=0;
(pawn_hash_table+i)->white_defects_q=0;
(pawn_hash_table+i)->passed_w=0;
(pawn_hash_table+i)->passed_w=0;
(pawn_hash_table+i)->outside=0;
}
}
void InitializeMasks(void) {
int i, j;
#  if !defined(CRAY1)
mask_1=Mask(1);
mask_2=Mask(2);
mask_3=Mask(3);
mask_4=Mask(4);
mask_8=Mask(8);
mask_16=Mask(16);
mask_32=Mask(32);
mask_72=Mask(72);
mask_80=Mask(80);
mask_85=Mask(85);
mask_96=Mask(96);
mask_107=Mask(107);
mask_108=Mask(108);
mask_112=Mask(112);
mask_118=Mask(118);
mask_120=Mask(120);
mask_121=Mask(121);
mask_127=Mask(127);
#  endif
mask_clear_entry=Compl(Or(Shiftl(Mask(109),21),Shiftr(Mask(3),3)));
for (i=0;i<64;i++) {
clear_mask[i]=Compl(Shiftr(mask_1,i));
clear_mask_rl45[i]=Compl(Shiftr(mask_1,init_l45[i]));
clear_mask_rr45[i]=Compl(Shiftr(mask_1,init_r45[i]));
clear_mask_rl90[i]=Compl(Shiftr(mask_1,init_l90[i]));
set_mask[i]=Shiftr(mask_1,i);
set_mask_rl45[i]=Shiftr(mask_1,init_l45[i]);
set_mask_rr45[i]=Shiftr(mask_1,init_r45[i]);
set_mask_rl90[i]=Shiftr(mask_1,init_l90[i]);
}
clear_mask[BAD_SQUARE]=0;
clear_mask_rl45[BAD_SQUARE]=0;
clear_mask_rr45[BAD_SQUARE]=0;
clear_mask_rl90[BAD_SQUARE]=0;
set_mask[BAD_SQUARE]=0;
set_mask_rl45[BAD_SQUARE]=0;
set_mask_rr45[BAD_SQUARE]=0;
set_mask_rl90[BAD_SQUARE]=0;
rank_mask[0]=mask_8;
for (i=1;i<8;i++) rank_mask[i]=Shiftr(rank_mask[i-1],8);
file_mask[FILEA]=mask_1;
for (i=1;i<8;i++) file_mask[FILEA]=Or(file_mask[FILEA],Shiftr(file_mask[FILEA],8));
for (i=1;i<8;i++) file_mask[i]=Shiftr(file_mask[i-1],1);
for (i=8;i<56;i++) {
mask_pawn_protected_w[i]=Or(set_mask[i-1],set_mask[i+1]);
if (i > 15) mask_pawn_protected_w[i]|=Or(set_mask[i-7],set_mask[i-9]);
mask_pawn_protected_b[i]=Or(set_mask[i-1],set_mask[i+1]);
if (i < 48) mask_pawn_protected_b[i]|=Or(set_mask[i+7],set_mask[i+9]);
}
for (i=0;i<8;i++) {
right_side_mask[i]=0;
for (j=i+2;j<8;j++)
right_side_mask[i]=Or(right_side_mask[i],file_mask[j]);
left_side_mask[i]=0;
for (j=i-2;j>=0;j--)
left_side_mask[i]=Or(left_side_mask[i],file_mask[j]);
}
for (i=0;i<8;i++) {
right_side_empty_mask[i]=0;
for (j=i+1;j<8;j++)
right_side_empty_mask[i]=Or(right_side_empty_mask[i],file_mask[j]);
left_side_empty_mask[i]=0;
for (j=i-1;j>=0;j--)
left_side_empty_mask[i]=Or(left_side_empty_mask[i],file_mask[j]);
}
right_half_mask=Or(Or(Or(file_mask[FILEE],file_mask[FILEF]),file_mask[FILEG]),file_mask[FILEH]);
left_half_mask=Or(Or(Or(file_mask[FILEA],file_mask[FILEB]),file_mask[FILEC]),file_mask[FILED]);
mask_kr_trapped_w[0]=set_mask[H2];
mask_kr_trapped_w[1]=Or(set_mask[H1],set_mask[H2]);
mask_kr_trapped_w[2]=Or(Or(set_mask[G1],set_mask[H1]),set_mask[H2]);
mask_qr_trapped_w[0]=set_mask[A2];
mask_qr_trapped_w[1]=Or(set_mask[A1],set_mask[A2]);
mask_qr_trapped_w[2]=Or(Or(set_mask[A1],set_mask[B1]),set_mask[A2]);
mask_kr_trapped_b[0]=set_mask[H7];
mask_kr_trapped_b[1]=Or(set_mask[H8],set_mask[H7]);
mask_kr_trapped_b[2]=Or(Or(set_mask[H8],set_mask[G8]),set_mask[H7]);
mask_qr_trapped_b[0]=set_mask[A7];
mask_qr_trapped_b[1]=Or(set_mask[A8],set_mask[A7]);
mask_qr_trapped_b[2]=Or(Or(set_mask[A8],set_mask[B8]),set_mask[A7]);
mask_abs7_w=Xor(rank_mask[RANK7],Or(set_mask[H7],set_mask[A7]));
mask_abs7_b=Xor(rank_mask[RANK2],Or(set_mask[H2],set_mask[A2]));
mask_not_rank8=~rank_mask[RANK8];
mask_not_rank1=~rank_mask[RANK1];
mask_F3H3=Or(set_mask[F3],set_mask[H3]);
mask_F6H6=Or(set_mask[F6],set_mask[H6]);
mask_A3C3=Or(set_mask[A3],set_mask[C3]);
mask_A6C6=Or(set_mask[A6],set_mask[C6]);
mask_A7H7=Or(set_mask[A7],set_mask[H7]);
mask_A2H2=Or(set_mask[A2],set_mask[H2]);
center=Or(Or(set_mask[D4],set_mask[E4]),
Or(set_mask[D5],set_mask[E5]));
}
void InitializePawnMasks(void)
{
int i;
BITBOARD m1,m2;
for (i=0;i<64;i++) {
if (!(i&7)) mask_pawn_isolated[i]=file_mask[(i&7)+1];
else if ((i&7) == 7) mask_pawn_isolated[i]=file_mask[(i&7)-1];
else mask_pawn_isolated[i]=Or(file_mask[(i&7)-1],file_mask[(i&7)+1]);
}
for (i=8;i<56;i++) {
if (((i&7)>0) && ((i&7)<7))
mask_pawn_connected[i]=Or(Or(Or(Or(Or(set_mask[i-9],set_mask[i-7]),
set_mask[i-1]),
set_mask[i+1]),
set_mask[i+7]),
set_mask[i+9]);
else if ((i&7)==0)
mask_pawn_connected[i]=Or(Or(set_mask[i-7],set_mask[i+1]),
set_mask[i+9]);
else if ((i&7)==7)
mask_pawn_connected[i]=Or(Or(set_mask[i-9],set_mask[i-1]),
set_mask[i+7]);
}
for (i=0;i<64;i++) {
if (!(i&7)) {
mask_pawn_passed_w[i]=Or(plus8dir[i],plus8dir[i+1]);
mask_pawn_passed_b[i]=Or(minus8dir[i],minus8dir[i+1]);
}
else if ((i&7) == 7) {
mask_pawn_passed_w[i]=Or(plus8dir[i-1],plus8dir[i]);
mask_pawn_passed_b[i]=Or(minus8dir[i-1],minus8dir[i]);
}
else {
mask_pawn_passed_w[i]=Or(Or(plus8dir[i-1],plus8dir[i]),
plus8dir[i+1]);
mask_pawn_passed_b[i]=Or(Or(minus8dir[i-1],minus8dir[i]),
minus8dir[i+1]);
}
}
for (i=8;i<56;i++) {
if (!(i&7)) {
mask_no_pawn_attacks_w[i]=minus8dir[i+1];
mask_no_pawn_attacks_b[i]=plus8dir[i+1];
}
else if ((i&7) == 7) {
mask_no_pawn_attacks_w[i]=minus8dir[i-1];
mask_no_pawn_attacks_b[i]=plus8dir[i-1];
}
else {
mask_no_pawn_attacks_w[i]=Or(minus8dir[i-1],minus8dir[i+1]);
mask_no_pawn_attacks_b[i]=Or(plus8dir[i+1],plus8dir[i-1]);
}
}
for (i=0;i<64;i++) mask_eptest[i]=0;
for (i=25;i<31;i++) mask_eptest[i]=Or(set_mask[i-1],set_mask[i+1]);
for (i=33;i<39;i++) mask_eptest[i]=Or(set_mask[i-1],set_mask[i+1]);
mask_eptest[A4]=set_mask[B4];
mask_eptest[H4]=set_mask[G4];
mask_eptest[A5]=set_mask[B5];
mask_eptest[H5]=set_mask[G5];
mask_kingside_attack_w1=Or(Or(minus8dir[F5],minus8dir[G5]),
minus8dir[H5]);
mask_kingside_attack_w2=Or(Or(minus8dir[F4],minus8dir[G4]),
minus8dir[H4]);
mask_queenside_attack_w1=Or(Or(minus8dir[A5],minus8dir[B5]),
minus8dir[C5]);
mask_queenside_attack_w2=Or(Or(minus8dir[A4],minus8dir[B4]),
minus8dir[C4]);
mask_kingside_attack_b1=Or(Or(plus8dir[F4],plus8dir[G4]),
plus8dir[H4]);
mask_kingside_attack_b2=Or(Or(plus8dir[F5],plus8dir[G5]),
plus8dir[H5]);
mask_queenside_attack_b1=Or(Or(plus8dir[A4],plus8dir[B4]),
plus8dir[C4]);
mask_queenside_attack_b2=Or(Or(plus8dir[A5],plus8dir[B5]),
plus8dir[C5]);
pawns_cramp_black=Or(Or(set_mask[D5],set_mask[E5]),
set_mask[F5]);
pawns_cramp_white=Or(Or(set_mask[D4],set_mask[E4]),
set_mask[F4]);
m1=Mask(1);
m2=Shiftr(m1,1);
for (i=1;i<4;i++) {
m1=Or(m1,Shiftr(m1,2));
m2=Or(m2,Shiftr(m2,2));
}
for (i=0;i<64;i+=8) {
if ((i/8)&1) {
dark_squares=Or(dark_squares,Shiftr(m2,i));
light_squares=Or(light_squares,Shiftr(m1,i));
}
else {
dark_squares=Or(dark_squares,Shiftr(m1,i));
light_squares=Or(light_squares,Shiftr(m2,i));
}
}
not_rook_pawns=Or(Or(Or(file_mask[FILEB],file_mask[FILEC]),
Or(file_mask[FILED],file_mask[FILEE])),
Or(file_mask[FILEF],file_mask[FILEG]));
mask_left_edge=Compl(file_mask[FILEA]);
mask_right_edge=Compl(file_mask[FILEH]);
mask_advance_2_w=rank_mask[RANK3];
mask_advance_2_b=rank_mask[RANK6];
mask_corner_squares=Or(Or(set_mask[A1],set_mask[H1]),
Or(set_mask[A8],set_mask[H8]));
good_bishop_kw=Or(Or(set_mask[F1],set_mask[H1]),set_mask[G2]);
good_bishop_qw=Or(Or(set_mask[A1],set_mask[C1]),set_mask[B2]);
good_bishop_kb=Or(Or(set_mask[G7],set_mask[F8]),set_mask[H8]);
good_bishop_qb=Or(Or(set_mask[B7],set_mask[A8]),set_mask[C8]);
for (i=0;i<64;i++) {
mask_promotion_threat_w[i]=0;
mask_promotion_threat_b[i]=0;
}
for (i=8;i<24;i++) {
if (!(i&7)) {
mask_promotion_threat_b[i]=Or(set_mask[B2],set_mask[B3]);
}
else if ((i&7) == 7) {
mask_promotion_threat_b[i]=Or(set_mask[G2],set_mask[G3]);
}
else {
mask_promotion_threat_b[i]=Or(Or(set_mask[(i&7)+7],set_mask[(i&7)+9]),
Or(set_mask[(i&7)+15],set_mask[(i&7)+17]));
}
}
for (i=40;i<56;i++) {
if (!(i&7)) {
mask_promotion_threat_w[i]=Or(set_mask[B6],set_mask[B7]);
}
else if ((i&7) == 7) {
mask_promotion_threat_w[i]=Or(set_mask[G6],set_mask[G7]);
}
else {
mask_promotion_threat_w[i]=Or(Or(set_mask[(i&7)+39],set_mask[(i&7)+47]),
Or(set_mask[(i&7)+41],set_mask[(i&7)+49]));
}
}
promote_mask_w=Compl(Or(rank_mask[5],rank_mask[6]));
promote_mask_b=Compl(Or(rank_mask[1],rank_mask[2]));
mask_G2G3=Or(set_mask[G2],set_mask[G3]);
mask_B2B3=Or(set_mask[B2],set_mask[B3]);
mask_G6G7=Or(set_mask[G6],set_mask[G7]);
mask_B6B7=Or(set_mask[B6],set_mask[B7]);
mask_wq_4th=Or(Or(set_mask[A4],set_mask[B4]),set_mask[C4]);
mask_wq_5th=Or(Or(set_mask[A5],set_mask[B5]),set_mask[C5]);
mask_wk_4th=Or(Or(set_mask[F4],set_mask[G4]),set_mask[H4]);
mask_wk_5th=Or(Or(set_mask[F5],set_mask[G5]),set_mask[H5]);
mask_bk_4th=mask_wk_5th;
mask_bq_4th=mask_wq_5th;
mask_bk_5th=mask_wk_4th;
mask_bq_5th=mask_wq_4th;
stonewall_white=Or(Or(set_mask[D4],set_mask[E3]),set_mask[F4]);
stonewall_black=Or(Or(set_mask[D5],set_mask[E6]),set_mask[F5]);
}
void InitializePieceMasks(void)
{
int i, j;
mask_a1_corner=Or(mask_2,Shiftr(mask_2,8));
mask_h1_corner=Or(Shiftr(mask_2,6),Shiftr(mask_2,14));
mask_a8_corner=Or(Shiftr(mask_2,48),Shiftr(mask_2,56));
mask_h8_corner=Or(Shiftr(mask_2,54),Shiftr(mask_2,62));
white_minor_pieces=Or(Shiftr(mask_2,1),Shiftr(mask_2,5));
black_minor_pieces=Or(Shiftr(mask_2,57),Shiftr(mask_2,61));
white_center_pawns=Shiftr(mask_2,11);
black_center_pawns=Shiftr(mask_2,51);
for (i=0;i<64;i++) {
white_pawn_race_wtm[i]=0;
white_pawn_race_btm[i]=0;
black_pawn_race_wtm[i]=0;
black_pawn_race_btm[i]=0;
}
for (j=8;j<56;j++) {
for (i=0;i<64;i++) {
if (j < 16) {
if (KingPawnSquare(j+8,i,(j&7)+56,1))
white_pawn_race_wtm[j]=Or(white_pawn_race_wtm[j],set_mask[i]);
}
else {
if (KingPawnSquare(j,i,(j&7)+56,1))
white_pawn_race_wtm[j]=Or(white_pawn_race_wtm[j],set_mask[i]);
}
if (j < 16) {
if (KingPawnSquare(j+8,i,(j&7)+56,0))
white_pawn_race_btm[j]=Or(white_pawn_race_btm[j],set_mask[i]);
}
else {
if (KingPawnSquare(j,i,(j&7)+56,0))
white_pawn_race_btm[j]=Or(white_pawn_race_btm[j],set_mask[i]);
}
if (j > 47) {
if (KingPawnSquare(j-8,i,j&7,0))
black_pawn_race_wtm[j]=Or(black_pawn_race_wtm[j],set_mask[i]);
}
else {
if (KingPawnSquare(j,i,j&7,0))
black_pawn_race_wtm[j]=Or(black_pawn_race_wtm[j],set_mask[i]);
}
if (j > 47) {
if (KingPawnSquare(j-8,i,j&7,1))
black_pawn_race_btm[j]=Or(black_pawn_race_btm[j],set_mask[i]);
}
else {
if (KingPawnSquare(j,i,j&7,1))
black_pawn_race_btm[j]=Or(black_pawn_race_btm[j],set_mask[i]);
}
}
}
}
void InitializeRandomHash(void)
{
int i;
for (i=0;i<64;i++) {
w_pawn_random[i]=Random64();
b_pawn_random[i]=Random64();
w_knight_random[i]=Random64();
b_knight_random[i]=Random64();
w_bishop_random[i]=Random64();
b_bishop_random[i]=Random64();
w_rook_random[i]=Random64();
b_rook_random[i]=Random64();
w_queen_random[i]=Random64();
b_queen_random[i]=Random64();
w_king_random[i]=Random64();
b_king_random[i]=Random64();
}
for (i=0;i<2;i++) {
castle_random_w[i]=Random64();
castle_random_b[i]=Random64();
}
enpassant_random[0]=0;
for (i=1;i<65;i++) {
enpassant_random[i]=Random64();
}
for (i=0;i<2;i++) {
wtm_random[i]=Random64();
}
endgame_random_w=Random64();
endgame_random_b=Random64();
w_rooks_random=Random64();
b_rooks_random=Random64();
for (i=0;i<64;i++) {
w_pawn_random32[i]=Random32();
b_pawn_random32[i]=Random32();
}
}
void InitializeZeroMasks(void)
{
int i,j,maskl,maskr;
#if !defined(CRAY1)
first_ones[0]=16;
last_ones[0]=16;
for (i=1;i<65536;i++){
maskl=32768;
for(j=0;j<16;j++){
if ((maskl & i)){
first_ones[i]=j;
break;
}
maskl=maskl>>1;
}
maskr=1;
for(j=0;j<16;j++){
if ((maskr & i)){
last_ones[i]=15-j;
break;
}
maskr=maskr<<1;
}
}
#endif
first_ones_8bit[0]=8;
last_ones_8bit[0]=8;
connected_passed[0]=0;
for (i=0;i<256;i++){
connected_passed[i]=0;
for (j=0;j<8;j++){
if (i & (1<<(7-j))){
first_ones_8bit[i]=j;
break;
}
}
for (j=7;j>=0;j--){
if (i & (1<<(7-j))){
last_ones_8bit[i]=j;
break;
}
}
for (j=7;j>0;j--){
if ((i & (3<<(7-j))) == (3<<(7-j))){
connected_passed[i]=j;
break;
}
}
}
}
/* 当前文件是D:\Read\input.c*/

int InputMove(char *text, int ply, int wtm, int silent, int ponder_list)
{
int moves[220], *mv, *mvp, *goodmove=0;
int piece=-1, capture, promote, give_check;
int ffile, frank, tfile, trank;
int current, i, nleft, ambig;
char *goodchar;
char movetext[128];
char pieces[17]={' ',' ','P','p','N','n','K','k',' ',' ',
'B','B','R','r','Q','q','\0'};
char pro_pieces[17]={' ',' ','P','p','N','n','K','k',' ',' ',
'B','b','R','r','Q','q','\0'};
if ((text[0] >= 'a') && (text[0] <= 'h') &&
(text[1] >= '1') && (text[1] <= '8') &&
(text[2] >= 'a') && (text[2] <= 'h') &&
(text[3] >= '1') && (text[3] <= '8'))
return(InputMoveICS(text,ply,wtm,silent,ponder_list));
position[MAXPLY]=position[ply];
strcpy(movetext,text);
moves[0]=0;
piece=0;
capture=0;
promote=0;
give_check=0;
frank=-1;
ffile=-1;
trank=-1;
tfile=-1;
ambig=0;
goodchar=strchr(movetext,'#');
if (goodchar) *goodchar=0;
if (!strcmp(movetext,"o-o") || !strcmp(movetext,"o-o+") ||
!strcmp(movetext,"O-O") || !strcmp(movetext,"O-O+") ||
!strcmp(movetext,"0-0") || !strcmp(movetext,"0-0+")) {
piece=king;
if(wtm) {
ffile=4;
frank=0;
tfile=6;
trank=0;
}
else {
ffile=4;
frank=7;
tfile=6;
trank=7;
}
}
else
if (!strcmp(movetext,"o-o-o") || !strcmp(movetext,"o-o-o+") ||
!strcmp(movetext,"O-O-O") || !strcmp(movetext,"O-O-O+") ||
!strcmp(movetext,"0-0-0") || !strcmp(movetext,"0-0-0+")) {
piece=king;
if(wtm) {
ffile=4;
frank=0;
tfile=2;
trank=0;
}
else {
ffile=4;
frank=7;
tfile=2;
trank=7;
}
}
else {
if ((movetext[0] == 'b') && (movetext[1] == 'b')) movetext[0]='B';
if (strchr(movetext,'+')) {
*strchr(movetext,'+')=0;
give_check=1;
}
if (strchr(movetext,'=')) {
goodchar=strchr(movetext,'=');
goodchar++;
promote=(strchr(pro_pieces,*goodchar)-pro_pieces) >> 1;
*strchr(movetext,'=')=0;
}
current=strlen(movetext)-1;
trank=movetext[current]-'1';
if ((trank >= 0) && (trank <= 7))
movetext[current]=0;
else
trank=-1;
current=strlen(movetext)-1;
tfile=movetext[current]-'a';
if ((tfile >= 0) || (tfile <= 7))
movetext[current]=0;
else
tfile=-1;
if (strlen(movetext)) {
if (strchr("  PpNnBBRrQqKk",*movetext)) {
piece=(strchr(pieces,movetext[0])-pieces) >> 1;
for(i=0;i<(int) strlen(movetext);i++)
movetext[i]=movetext[i+1];
}
if ((strlen(movetext)) && (movetext[strlen(movetext)-1] == 'x')) {
capture=1;
movetext[strlen(movetext)-1]=0;
}
else
capture=0;
if (strlen(movetext)) {
ffile=movetext[0]-'a';
if ((ffile < 0) || (ffile > 7)) {
ffile=-1;
frank=movetext[0]-'1';
if ((frank < 0) || (frank > 7)) piece=-1;
}
else {
if (strlen(movetext) == 2) {
frank=movetext[1]-'1';
if ((frank < 0) || (frank > 7)) piece=-1;
}
}
}
}
}
if (!piece) piece=1;
if (!ponder_list) {
mvp=GenerateCaptures(MAXPLY, wtm, moves);
mvp=GenerateNonCaptures(MAXPLY, wtm, mvp);
}
else {
for (i=0;i<num_ponder_moves;i++)
moves[i]=ponder_moves[i];
mvp=moves+num_ponder_moves;
}
for (mv=&moves[0];mv<mvp;mv++) {
if (piece && (Piece(*mv) != piece)) *mv=0;
if ((ffile >= 0) && (File(From(*mv)) != ffile)) *mv=0;
if (capture && (!Captured(*mv))) *mv=0;
if (promote && (Promote(*mv) != promote)) *mv=0;
if ((frank >= 0)  && (Rank(From(*mv)) != frank)) *mv=0;
if ((tfile >= 0)  && (File(To(*mv)) != tfile)) *mv=0;
if ((trank >= 0)  && (Rank(To(*mv)) != trank)) *mv=0;
if (!ponder_list && *mv) {
MakeMove(MAXPLY, *mv, wtm);
if (Check(wtm) || (give_check && !Check(ChangeSide(wtm)))) {
UnMakeMove(MAXPLY, *mv, wtm);
*mv=0;
}
else UnMakeMove(MAXPLY, *mv, wtm);
}
}
nleft=0;
for (mv=&moves[0];mv<mvp;mv++) {
if (*mv) {
nleft++;
goodmove=mv;
}
}
if (nleft == 1) return(*goodmove);
if (ambig) {
if (nleft > 1) {
for (mv=&moves[0];mv<mvp;mv++)
if (Piece(*mv) != pawn) *mv=0;
nleft=0;
for (mv=&moves[0];mv<mvp;mv++) {
if (*mv) {
nleft++;
goodmove=mv;
}
}
if (nleft == 1)
return(*goodmove);
}
}
if (!silent) {
if (!nleft) printf("illegal move.\n");
else if (piece < 0) printf("unrecognizable move.\n");
else printf("move is ambiguous.\n");
}
return(0);
}
int InputMoveICS(char *text, int ply, int wtm, int silent, int ponder_list)
{
int moves[220], *mv, *mvp, *goodmove=0;
int piece=-1, promote;
int ffile, frank, tfile, trank;
int i, nleft;
char movetext[128];
char pieces[17]={' ',' ','P','p','N','n','K','k',' ',' ',
'B','b','R','r','Q','q','\0'};
position[MAXPLY]=position[ply];
strcpy(movetext,text);
moves[0]=0;
promote=0;
if (!strcmp(movetext,"o-o") || !strcmp(movetext,"O-O") ||
!strcmp(movetext,"0-0")) {
piece=king;
if(wtm) {
ffile=4;
frank=0;
tfile=6;
trank=0;
}
else {
ffile=4;
frank=7;
tfile=6;
trank=7;
}
}
else
if (!strcmp(movetext,"o-o-o") || !strcmp(movetext,"O-O-O") ||
!strcmp(movetext,"0-0-0")) {
piece=king;
if(wtm) {
ffile=4;
frank=0;
tfile=2;
trank=0;
}
else {
ffile=4;
frank=7;
tfile=2;
trank=7;
}
}
else {
ffile=movetext[0]-'a';
frank=movetext[1]-'1';
tfile=movetext[2]-'a';
trank=movetext[3]-'1';
if (movetext[4]=='=')
promote=(strchr(pieces,movetext[5])-pieces) >> 1;
else if ((movetext[4] != 0) && (movetext[4] != ' '))
promote=(strchr(pieces,movetext[4])-pieces) >> 1;
}
if (!ponder_list) {
mvp=GenerateCaptures(MAXPLY, wtm, moves);
mvp=GenerateNonCaptures(MAXPLY, wtm, mvp);
}
else {
for (i=0;i<num_ponder_moves;i++) moves[i]=ponder_moves[i];
mvp=moves+num_ponder_moves;
}
for (mv=&moves[0];mv<mvp;mv++) {
if (auto232 && Promote(*mv) && (Promote(*mv) != queen)) *mv = 0;
if (!auto232 && Promote(*mv) != promote) *mv=0;
if (Rank(From(*mv)) != frank) *mv=0;
if (File(From(*mv)) != ffile) *mv=0;
if (Rank(To(*mv)) != trank) *mv=0;
if (File(To(*mv)) != tfile) *mv=0;
if (!ponder_list && *mv) {
MakeMove(MAXPLY, *mv, wtm);
if(Check(wtm)) {
UnMakeMove(MAXPLY, *mv, wtm);
*mv=0;
}
else UnMakeMove(MAXPLY, *mv, wtm);
}
}
nleft=0;
for (mv=&moves[0];mv<mvp;mv++) {
if (*mv) {
nleft++;
goodmove=mv;
}
}
if (nleft == 1) return(*goodmove);
if (!silent) {
if (!nleft) printf("illegal move.\n");
else if (piece < 0) printf("unrecognizable move.\n");
else printf("move is ambiguous.\n");
}
return(0);
}
/* 当前文件是D:\Read\interupt.c*/

void Interrupt(int ply)
{
int temp, *mvp, i, left, readstat, result, time_used;
if (puzzling)
abort_search=1;
else do {
readstat=Read(0,buffer);
if (readstat <= 0) return;
nargs=ReadParse(buffer,args," 	;");
if (nargs == 0) {
printf("ok.\n");
return;
}
if (wtm)
printf("White(%d): %s\n",move_number,buffer);
else
printf("Black(%d): %s\n",move_number,buffer);
if (!strcmp(args[0],".")) {
if (xboard) {
end_time=GetTime(time_type);
time_used=(end_time-start_time);
printf("stat01: %d ",time_used);
printf("%d ",nodes_searched);
printf("%d ",iteration_depth);
for (left=0,mvp=last[0];mvp<last[1];mvp++)
if (!searched_this_root_move[mvp-last[0]]) left++;
printf("%d %ld\n",left,last[1]-last[0]);
return;
}
else {
end_time=GetTime(time_type);
time_used=(end_time-start_time);
printf("time:%s ",DisplayTime(time_used));
printf("nodes:%d\n",nodes_searched);
for (left=0,mvp=last[0];mvp<last[1];mvp++)
if (!searched_this_root_move[mvp-last[0]]) left++;
printf("%d:%d/%ld  ",1,left,last[1]-last[0]);
for (i=2;i<=ply;i++) {
left=0;
for (mvp=last[i-1];mvp<last[i];mvp++)
if (*mvp) left++;
printf("%d:%d/%ld  ",i,left,last[i]-last[i-1]);
if (!(i%8)) printf("\n");
}
printf("\n");
}
}
else if (!strcmp(args[0],"?")) {
if (thinking) {
time_abort=1;
abort_search=1;
}
}
else {
result=Option();
if (result >= 2) {
if (thinking && result!=3)
printf("command not legal now.\n");
else {
abort_search=1;
analyze_move_read=1;
return;
}
}
else if ((result != 1) && analyze_mode) {
abort_search=1;
analyze_move_read=1;
return;
}
else if (!result) {
if (pondering) {
nargs=ReadParse(buffer,args," 	;");
temp=InputMove(args[0],0,ChangeSide(root_wtm),1,1);
if (temp) {
if (auto232) {
char *mv=OutputMoveICS(&temp);
Delay(auto232_delay);
if (!wtm) fprintf(auto_file,"\t");
fprintf(auto_file, " %c%c-%c%c", mv[0], mv[1], mv[2], mv[3]);
if ((mv[4] != ' ') && (mv[4] != 0))
fprintf(auto_file, "/%c", mv[4]);
fprintf(auto_file, "\n");
fflush(auto_file);
}
if ((From(temp) == From(ponder_move)) &&
(To(temp) == To(ponder_move)) &&
(Piece(temp) == Piece(ponder_move)) &&
(Captured(temp) == Captured(ponder_move)) &&
(Promote(temp) == Promote(ponder_move))) {
predicted++;
made_predicted_move=1;
pondering=0;
thinking=1;
opponent_end_time=GetTime(elapsed);
program_start_time=GetTime(time_type);
printf("predicted move made.\n");
}
else {
abort_search=1;
return;
}
}
else if (!strcmp(args[0],"go") || !strcmp(args[0],"move") ||
!strcmp(args[0],"SP")) {
abort_search=1;
return;
}
else printf("illegal move.\n");
}
else printf("unrecognized/illegal command.\n");
}
}
} while (1);
if (log_file) fflush(log_file);
}
#if defined(NT_i386) || defined(NT_AXP)
void _cdecl SignalInterrupt(int signal_type)
#else
void SignalInterrupt(int signal_type)
#endif
{
switch (signal_type) {
case SIGINT:
if (xboard) {
if (thinking) {
time_abort=1;
abort_search=1;
}
signal(SIGINT,SignalInterrupt);
break;
}
break;
case SIGTERM:
break;
}
}
/* 当前文件是D:\Read\iterate.c*/

int Iterate(int wtm, int search_type, int root_list_done)
{
int *mvp;
char buffer[500], *buffp, *bufftemp;
int i, value=0, time_used;
int twtm, used_w, used_b;
int cpu_start, cpu_end;
int correct, correct_count, material=0, sorted, temp;
time_abort=0;
abort_search=0;
book_move=0;
program_start_time=GetTime(time_type);
start_time=GetTime(time_type);
cpu_start=GetTime(cpu);
elapsed_start=GetTime(elapsed);
PreEvaluate(wtm);
if (!root_list_done) RootMoveList(wtm);
correct_count=0;
burp=15*100;
transposition_id++;
transposition_id=transposition_id&7;
if (!transposition_id) transposition_id++;
program_start_time=GetTime(time_type);
start_time=GetTime(time_type);
cpu_start=GetTime(cpu);
cpu_percent=0;
elapsed_start=GetTime(elapsed);
nodes_searched=0;
next_time_check=nodes_between_time_checks;
evaluations=0;
#if !defined(FAST)
transposition_hits=0;
transposition_probes=0;
pawn_probes=0;
pawn_hits=0;
#endif
tb_probes=0;
tb_probes_successful=0;
check_extensions_done=0;
recapture_extensions_done=0;
passed_pawn_extensions_done=0;
one_reply_extensions_done=0;
root_wtm=wtm;
root_total_white_pieces=TotalWhitePieces;
root_total_white_pawns=TotalWhitePawns;
root_total_black_pieces=TotalBlackPieces;
root_total_black_pawns=TotalBlackPawns;
if (last[0] == last[1]) {
program_end_time=GetTime(time_type);
pv[0].path_length=0;
pv[0].path_iteration_depth=10;
if (Check(wtm)) {
root_value=-(MATE-1);
last_search_value=-(MATE-1);
}
else {
root_value=DrawScore();
last_search_value=DrawScore();
}
printf("\n              depth   time  score   variation\n");
printf("                                    (no moves)\n");
nodes_searched=1;
return(root_value);
}
if (last[0]==(last[1]-1) && !booking && !pondering && annotate_mode==0) {
program_end_time=GetTime(time_type);
pv[0].path_length=1;
pv[0].path_hashed=0;
pv[0].path_iteration_depth=10;
pv[0].path[1]=*last[0];
nodes_searched=1;
printf("\n              depth   time  score   variation\n");
if (analyze_mode && xboard) {
printf("                       (only move)   ");
printf(" %s\n",OutputMove(last[0],1,wtm));
}
else {
printf("                       (only move)   ");
printf(" %s\n",OutputMove(last[0],1,wtm));
}
if (last_search_value > MATE-200) {
last_search_value+=2;
return(last_search_value);
}
else if (last_search_value < -MATE+200) {
last_search_value-=2;
return(last_search_value);
}
else
return(last_search_value);
}
TimeSet(search_type);
iteration_depth=1;
if (last_pv.path_iteration_depth > 1)
iteration_depth=last_pv.path_iteration_depth+1;
printf("\n              depth   time  score   variation (%d)\n",
iteration_depth);
time_abort=0;
abort_search=0;
program_start_time=GetTime(time_type);
start_time=GetTime(time_type);
cpu_start=GetTime(cpu);
elapsed_start=GetTime(elapsed);
if (iteration_depth > 1) {
twtm=wtm;
pv[0]=last_pv;
for (i=1;i<=(int) last_pv.path_length;i++) {
pv[i]=pv[i-1];
StorePV(i, twtm);
MakeMove(i,last_pv.path[i],twtm);
twtm=ChangeSide(twtm);
}
for (i=last_pv.path_length;i>0;i--) {
twtm=ChangeSide(twtm);
UnMakeMove(i,last_pv.path[i],twtm);
}
root_alpha=last_value-30;
root_value=last_value-30;
root_beta=last_value+30;
}
else {
root_alpha=-MATE-1;
root_value=-MATE-1;
root_beta=MATE+1;
}
for (i=0;i<256;i++) root_nodes[i]=0;
for (;iteration_depth<=60;iteration_depth++) {
if (trace_level) {
printf("==================================\n");
printf("=      search iteration %2d       =\n",iteration_depth);
printf("==================================\n");
}
for (mvp=last[0];mvp<last[1];mvp++)
searched_this_root_move[mvp-last[0]]=0;
search_failed_high=0;
search_failed_low=0;
if (nodes_searched) {
nodes_between_time_checks=nodes_per_second;
nodes_between_time_checks=Min(nodes_between_time_checks,200000);
if (!analyze_mode) {
if (time_limit>300 && !auto232);
else if (time_limit>100 || auto232) nodes_between_time_checks/=10;
else if (time_limit > 50) nodes_between_time_checks/=20;
else nodes_between_time_checks/=100;
} else {
nodes_between_time_checks=4000;
}
}
while (!time_abort && !abort_search) {
value=SearchRoot(root_alpha, root_beta, wtm,
iteration_depth*INCREMENT_PLY);
if (value >= root_beta) {
search_failed_high=1;
root_alpha=root_beta-1;
root_value=root_alpha;
root_beta=MATE+1;
searched_this_root_move[0]=0;
}
else if (value <= root_alpha) {
if (!search_failed_high) {
for (mvp=last[0];mvp<last[1];mvp++)
searched_this_root_move[mvp-last[0]]=0;
search_failed_low=1;
root_alpha=-MATE-1;
root_value=root_alpha;
easy_move=0;
if (nodes_searched>noise_level && !time_abort && !abort_search) {
printf("               %2i   %s     --   ",iteration_depth,
DisplayTime(GetTime(time_type)-start_time));
printf("%s\n",OutputMove(last[0],1,wtm));
}
}
else break;
}
else
break;
}
if (root_value>root_alpha && root_value<root_beta)
last_search_value=root_value;
correct=solution_type;
for (i=0;i<number_of_solutions;i++) {
if (!solution_type) {
if (solutions[i] == pv[1].path[1]) correct=1;
}
else
if (solutions[i] == pv[1].path[1]) correct=0;
}
if (correct) correct_count++;
else correct_count=0;
twtm=wtm;
end_time=GetTime(time_type);
cpu_end=GetTime(cpu)-cpu_start;
cpu_end=(cpu_end > 0) ? cpu_end : 1;
if (cpu_end > 100)
nodes_per_second=(BITBOARD) nodes_searched*100/(BITBOARD) cpu_end;
if (value != -(MATE-1)) {
buffer[0]=0;
for (i=1;i<=(int) pv[1].path_length;i++) {
pv[i+1]=pv[i];
if (!time_abort && !abort_search && (nodes_searched>noise_level ||
abs(value)>MATE-100 || correct_count>=early_exit ||
pv[1].path_hashed==2)) {
sprintf(buffer+strlen(buffer)," %s",OutputMove(&pv[1].path[i],i,twtm));
}
if(!time_abort && !abort_search) StorePV(i, twtm);
MakeMove(i,pv[1].path[i],twtm);
twtm=ChangeSide(twtm);
}
material=0;
for (i=0;i<64;i++)
switch (PieceOnSquare(i)) {
case 0:
break;
case pawn:
material+=1;
break;
case knight:
material+=3;
break;
case king:
break;
case bishop:
material+=3;
break;
case rook:
material+=5;
break;
case queen:
material+=9;
break;
case -pawn:
material-=1;
break;
case -knight:
material-=3;
break;
case -king:
break;
case -bishop:
material-=3;
break;
case -rook:
material-=5;
break;
case -queen:
material-=9;
}
for (i=pv[1].path_length;i>0;i--) {
twtm=ChangeSide(twtm);
UnMakeMove(i,pv[1].path[i],twtm);
}
}
if (pv[1].path_hashed == 1)
sprintf(buffer+strlen(buffer)," <HT>");
else if(pv[1].path_hashed == 2)
sprintf(buffer+strlen(buffer)," <EGTB>");
if (!time_abort && !abort_search && (nodes_searched>noise_level ||
correct_count>=early_exit || value>MATE-100 || pv[1].path_hashed==2)) {
Whisper(5,iteration_depth,end_time-start_time,whisper_value,
nodes_searched,0,buffer);
printf("               %2i-> %s%s   ",iteration_depth,
DisplayTime(end_time-start_time),DisplayEvaluation(value));
buffp=buffer+1;
do {
if ((int) strlen(buffp) > 34)
bufftemp=strchr(buffp+34,' ');
else
bufftemp=0;
if (bufftemp) *bufftemp=0;
printf("%s\n",buffp);
buffp=bufftemp+1;
if (bufftemp)
printf("                                    ");
} while(bufftemp);
}
root_alpha=value-30;
root_value=root_alpha;
root_beta=value+30;
if ((iteration_depth > 1) && (value > MATE-100) &&
(value > last_mate_score)) break;
if ((iteration_depth >= search_depth) && search_depth) break;
if (time_abort || abort_search) break;
end_time=GetTime(time_type)-start_time;
if (thinking && ((int) end_time >= time_limit)) break;
if (correct_count >= early_exit) break;
do {
sorted=1;
for (mvp=last[0]+1;mvp<last[1]-1;mvp++) {
if (root_nodes[mvp-last[0]] < root_nodes[mvp-last[0]+1]) {
temp=*mvp;
*mvp=*(mvp+1);
*(mvp+1)=temp;
temp=root_nodes[mvp-last[0]];
root_nodes[mvp-last[0]]=root_nodes[mvp-last[0]+1];
root_nodes[mvp-last[0]+1]=temp;
sorted=0;
}
}
} while(!sorted);
}
used_w=0;
used_b=0;
#if !defined(FAST)
for (i=0;i<hash_table_size;i++) {
if (Shiftr((trans_ref_ba+i)->word1,61) == transposition_id) used_b++;
if (Shiftr((trans_ref_wa+i)->word1,61) == transposition_id) used_w++;
}
#endif
end_time=GetTime(time_type);
time_used=(end_time-start_time);
if (time_used < 10) time_used=10;
cpu_end=GetTime(cpu)-cpu_start;
cpu_end=(cpu_end > 0) ? cpu_end : 1;
elapsed_end=GetTime(elapsed)-elapsed_start;
if (elapsed_end) cpu_percent=Min(100*cpu_end/elapsed_end,100);
else cpu_percent=100;
if (time_used > 100)
nodes_per_second=(BITBOARD) nodes_searched*100/(BITBOARD) cpu_end;
evaluations=(evaluations) ? evaluations : 1;
if ((!abort_search || time_abort) && !puzzling) {
if (ChangeSide(wtm)) material=-material;
printf("              time:###  cpu:###  mat:%d",
material);
printf("  n:%u", nodes_searched);
printf("  nps: ####\n");
printf("              ext-> checks:%d recaps:%d pawns:%d 1rep:%d\n",
check_extensions_done, recapture_extensions_done,
passed_pawn_extensions_done,one_reply_extensions_done);
printf("              predicted:%d  nodes:%u  evals:%u\n",
predicted,nodes_searched, evaluations);
printf("              endgame tablebase-> probes done: %d  successful: %d\n",
tb_probes, tb_probes_successful);
#if !defined(FAST)
printf("              hashing-> trans/ref:%d%%  pawn:%d%%  used:w%d%% b%d%%\n",
100*transposition_hits/(transposition_probes+1),
100*pawn_hits/(pawn_probes+1),
used_w*100/(hash_table_size+1), used_b*100/(hash_table_size+1));
#endif
}
program_end_time=GetTime(time_type);
pv[0]=pv[1];
return(last_search_value);
}
/* 当前文件是D:\Read\lookup.c*/

int LookUp(int ply, int depth, int wtm, int *alpha, int *beta)
{
register BITBOARD temp_hash_key;
register HASH_ENTRY *htable;
register int type, draft, avoid_null=WORTHLESS, val;
hash_move[ply]=0;
temp_hash_key=HashKey>>16;
#if !defined(FAST)
transposition_probes++;
#endif
htable=((wtm)?trans_ref_wa:trans_ref_ba)+(((int) HashKey) & hash_maska);
if (!Xor(And(htable->word2,mask_80),temp_hash_key)) do {
#if !defined(FAST)
transposition_hits++;
#endif
hash_move[ply]=((int) htable->word1) & 07777777;
type=((int) Shiftr(htable->word1,59)) & 03;
draft=(int) Shiftr(htable->word2,48);
val=(((int) Shiftr(htable->word1,21)) & 01777777)-65536;
if ((type & UPPER_BOUND) &&
depth-NULL_MOVE_DEPTH-INCREMENT_PLY <= draft &&
val < *beta) avoid_null=AVOID_NULL_MOVE;
if (depth > draft) break;
switch (type) {
case EXACT_SCORE:
if (abs(val) > MATE-100) {
if (val > 0) val-=(ply-1);
else val+=(ply-1);
}
*alpha=val;
return(EXACT_SCORE);
case UPPER_BOUND:
if (val <= *alpha) {
*alpha=val;
return(UPPER_BOUND);
}
break;
case LOWER_BOUND:
if (val >= *beta) {
*beta=val;
return(LOWER_BOUND);
}
break;
}
} while(0);
htable=((wtm)?trans_ref_wb:trans_ref_bb)+(((int) HashKey) & hash_maskb);
if (!Xor(And(htable->word2,mask_80),temp_hash_key)) {
#if !defined(FAST)
transposition_hits++;
#endif
if (hash_move[ply]==0)
hash_move[ply]=((int) htable->word1) & 07777777;
type=((int) Shiftr(htable->word1,59)) & 03;
draft=Shiftr(htable->word2,48);
val=(((int) Shiftr(htable->word1,21)) & 01777777)-65536;
if ((type & UPPER_BOUND) &&
depth-NULL_MOVE_DEPTH-INCREMENT_PLY <= draft &&
val < *beta) avoid_null=AVOID_NULL_MOVE;
if (depth > draft) return(avoid_null);
switch (type) {
case EXACT_SCORE:
if (abs(val) > MATE-100) {
if (val > 0) val-=(ply-1);
else val+=(ply-1);
}
*alpha=val;
return(EXACT_SCORE);
case UPPER_BOUND:
if (val <= *alpha) {
*alpha=val;
return(UPPER_BOUND);
}
return(avoid_null);
case LOWER_BOUND:
if (val >= *beta) {
*beta=val;
return(LOWER_BOUND);
}
return(avoid_null);
}
}
return(avoid_null);
}
/* 当前文件是D:\Read\make.c*/

static BITBOARD bit_move;
void MakeMove(int ply, int move, int wtm)
{
register int piece, from, to, captured, promote;
#if defined(DEBUG)
ValidatePosition(ply,move,"MakeMove(1)");
#endif
position[ply+1]=position[ply];
save_hash_key[ply]=HashKey;
save_pawn_hash_key[ply]=PawnHashKey;
if (EnPassant(ply+1)) {
HashEP(EnPassant(ply+1),HashKey);
EnPassant(ply+1)=0;
}
Rule50Moves(ply+1)++;
piece=Piece(move);
from=From(move);
to=To(move);
captured=Captured(move);
promote=Promote(move);
MakePieceMove:
ClearRL90(from,OccupiedRL90);
ClearRL45(from,OccupiedRL45);
ClearRR45(from,OccupiedRR45);
SetRL90(to,OccupiedRL90);
SetRL45(to,OccupiedRL45);
SetRR45(to,OccupiedRR45);
bit_move=Or(set_mask[from],set_mask[to]);
PieceOnSquare(from)=0;
switch (piece) {
case pawn:
if (wtm) {
ClearSet(bit_move,WhitePawns);
ClearSet(bit_move,WhitePieces);
HashPW(from,HashKey);
HashPW32(from,PawnHashKey);
HashPW(to,HashKey);
HashPW32(to,PawnHashKey);
PieceOnSquare(to)=pawn;
if (captured == 1) {
if(!And(BlackPawns,set_mask[to])) {
ClearRL90(to-8,OccupiedRL90);
ClearRL45(to-8,OccupiedRL45);
ClearRR45(to-8,OccupiedRR45);
Clear(to-8,BlackPawns);
Clear(to-8,BlackPieces);
HashPB(to-8,HashKey);
HashPB32(to-8,PawnHashKey);
PieceOnSquare(to-8)=0;
Material+=PAWN_VALUE;
TotalBlackPawns--;
TotalPieces--;
captured=0;
}
}
if (promote) {
TotalWhitePawns--;
Material-=PAWN_VALUE;
Clear(to,WhitePawns);
HashPW(to,HashKey);
HashPW32(to,PawnHashKey);
switch (promote) {
case knight:
Set(to,WhiteKnights);
HashNW(to,HashKey);
PieceOnSquare(to)=knight;
TotalWhitePieces+=knight_v;
Material+=KNIGHT_VALUE;
break;
case bishop:
Set(to,WhiteBishops);
Set(to,BishopsQueens);
HashBW(to,HashKey);
PieceOnSquare(to)=bishop;
TotalWhitePieces+=bishop_v;
Material+=BISHOP_VALUE;
break;
case rook:
Set(to,WhiteRooks);
Set(to,RooksQueens);
HashRW(to,HashKey);
PieceOnSquare(to)=rook;
TotalWhitePieces+=rook_v;
Material+=ROOK_VALUE;
break;
case queen:
Set(to,WhiteQueens);
Set(to,BishopsQueens);
Set(to,RooksQueens);
HashQW(to,HashKey);
PieceOnSquare(to)=queen;
TotalWhitePieces+=queen_v;
Material+=QUEEN_VALUE;
break;
}
}
else
if (((to-from) == 16) && And(mask_eptest[to],BlackPawns)) {
EnPassant(ply+1)=to-8;
HashEP(to-8,HashKey);
}
}
else {
ClearSet(bit_move,BlackPawns);
ClearSet(bit_move,BlackPieces);
HashPB(from,HashKey);
HashPB32(from,PawnHashKey);
HashPB(to,HashKey);
HashPB32(to,PawnHashKey);
PieceOnSquare(to)=-pawn;
if (captured == 1) {
if(!And(WhitePawns,set_mask[to])) {
ClearRL90(to+8,OccupiedRL90);
ClearRL45(to+8,OccupiedRL45);
ClearRR45(to+8,OccupiedRR45);
Clear(to+8,WhitePawns);
Clear(to+8,WhitePieces);
HashPW(to+8,HashKey);
HashPW32(to+8,PawnHashKey);
PieceOnSquare(to+8)=0;
Material-=PAWN_VALUE;
TotalWhitePawns--;
TotalPieces--;
captured=0;
}
}
if (promote) {
TotalBlackPawns--;
Material+=PAWN_VALUE;
Clear(to,BlackPawns);
HashPB(to,HashKey);
HashPB32(to,PawnHashKey);
switch (promote) {
case knight:
Set(to,BlackKnights);
HashNB(to,HashKey);
PieceOnSquare(to)=-knight;
TotalBlackPieces+=knight_v;
Material-=KNIGHT_VALUE;
break;
case bishop:
Set(to,BlackBishops);
Set(to,BishopsQueens);
HashBB(to,HashKey);
PieceOnSquare(to)=-bishop;
TotalBlackPieces+=bishop_v;
Material-=BISHOP_VALUE;
break;
case rook:
Set(to,BlackRooks);
Set(to,RooksQueens);
HashRB(to,HashKey);
PieceOnSquare(to)=-rook;
TotalBlackPieces+=rook_v;
Material-=ROOK_VALUE;
break;
case queen:
Set(to,BlackQueens);
Set(to,BishopsQueens);
Set(to,RooksQueens);
HashQB(to,HashKey);
PieceOnSquare(to)=-queen;
TotalBlackPieces+=queen_v;
Material-=QUEEN_VALUE;
break;
}
}
else
if (((from-to) == 16) && And(mask_eptest[to],WhitePawns)) {
EnPassant(ply+1)=to+8;
HashEP(to+8,HashKey);
}
}
Rule50Moves(ply+1)=0;
break;
case knight:
if (wtm) {
ClearSet(bit_move,WhiteKnights);
ClearSet(bit_move,WhitePieces);
HashNW(from,HashKey);
HashNW(to,HashKey);
PieceOnSquare(to)=knight;
}
else {
ClearSet(bit_move,BlackKnights);
ClearSet(bit_move,BlackPieces);
HashNB(from,HashKey);
HashNB(to,HashKey);
PieceOnSquare(to)=-knight;
}
break;
case bishop:
ClearSet(bit_move,BishopsQueens);
if (wtm) {
ClearSet(bit_move,WhiteBishops);
ClearSet(bit_move,WhitePieces);
HashBW(from,HashKey);
HashBW(to,HashKey);
PieceOnSquare(to)=bishop;
}
else {
ClearSet(bit_move,BlackBishops);
ClearSet(bit_move,BlackPieces);
HashBB(from,HashKey);
HashBB(to,HashKey);
PieceOnSquare(to)=-bishop;
}
break;
case rook:
ClearSet(bit_move,RooksQueens);
if (wtm) {
ClearSet(bit_move,WhiteRooks);
ClearSet(bit_move,WhitePieces);
HashRW(from,HashKey);
HashRW(to,HashKey);
PieceOnSquare(to)=rook;
if (WhiteCastle(ply+1) > 0) {
if ((from == 0) && (WhiteCastle(ply+1)&2)) {
WhiteCastle(ply+1)&=1;
HashCastleW(1,HashKey);
}
else if ((from == 7) && (WhiteCastle(ply+1)&1)) {
WhiteCastle(ply+1)&=2;
HashCastleW(0,HashKey);
}
}
}
else {
ClearSet(bit_move,BlackRooks);
ClearSet(bit_move,BlackPieces);
HashRB(from,HashKey);
HashRB(to,HashKey);
PieceOnSquare(to)=-rook;
if (BlackCastle(ply+1) > 0) {
if ((from == 56) && (BlackCastle(ply+1)&2)) {
BlackCastle(ply+1)&=1;
HashCastleB(1,HashKey);
}
else if ((from == 63) && (BlackCastle(ply+1)&1)) {
BlackCastle(ply+1)&=2;
HashCastleB(0,HashKey);
}
}
}
break;
case queen:
ClearSet(bit_move,BishopsQueens);
ClearSet(bit_move,RooksQueens);
if (wtm) {
ClearSet(bit_move,WhiteQueens);
ClearSet(bit_move,WhitePieces);
HashQW(from,HashKey);
HashQW(to,HashKey);
PieceOnSquare(to)=queen;
}
else {
ClearSet(bit_move,BlackQueens);
ClearSet(bit_move,BlackPieces);
HashQB(from,HashKey);
HashQB(to,HashKey);
PieceOnSquare(to)=-queen;
}
break;
case king:
if (wtm) {
ClearSet(bit_move,WhitePieces);
HashKW(from,HashKey);
HashKW(to,HashKey);
PieceOnSquare(to)=king;
WhiteKingSQ=to;
if (WhiteCastle(ply) > 0) {
if (WhiteCastle(ply+1)&2) HashCastleW(1,HashKey);
if (WhiteCastle(ply+1)&1) HashCastleW(0,HashKey);
if (abs(to-from) == 2) WhiteCastle(ply+1)=-4;
else WhiteCastle(ply+1)=0;
if (abs(to-from) == 2)
if (to == G1) {
from=H1;
to=F1;
piece=rook;
goto MakePieceMove;
}
else {
from=A1;
to=D1;
piece=rook;
goto MakePieceMove;
}
}
}
else {
ClearSet(bit_move,BlackPieces);
HashKB(from,HashKey);
HashKB(to,HashKey);
PieceOnSquare(to)=-king;
BlackKingSQ=to;
if (BlackCastle(ply+1) > 0) {
if (BlackCastle(ply+1)&2) HashCastleB(1,HashKey);
if (BlackCastle(ply+1)&1) HashCastleB(0,HashKey);
if (abs(to-from) == 2) BlackCastle(ply+1)=-4;
else BlackCastle(ply+1)=0;
if (abs(to-from) == 2)
if (to == G8) {
from=H8;
to=F8;
piece=rook;
goto MakePieceMove;
}
else {
from=A8;
to=D8;
piece=rook;
goto MakePieceMove;
}
}
}
break;
}
if(captured) {
Rule50Moves(ply+1)=0;
TotalPieces--;
if (promote) piece=promote;
switch (captured) {
case pawn:
if (wtm) {
Clear(to,BlackPawns);
Clear(to,BlackPieces);
HashPB(to,HashKey);
HashPB32(to,PawnHashKey);
Material+=PAWN_VALUE;
TotalBlackPawns--;
}
else {
Clear(to,WhitePawns);
Clear(to,WhitePieces);
HashPW(to,HashKey);
HashPW32(to,PawnHashKey);
Material-=PAWN_VALUE;
TotalWhitePawns--;
}
break;
case knight:
if (wtm) {
Clear(to,BlackKnights);
Clear(to,BlackPieces);
HashNB(to,HashKey);
TotalBlackPieces-=knight_v;
Material+=KNIGHT_VALUE;
}
else {
Clear(to,WhiteKnights);
Clear(to,WhitePieces);
HashNW(to,HashKey);
TotalWhitePieces-=knight_v;
Material-=KNIGHT_VALUE;
}
break;
case bishop:
if (SlidingDiag(piece)) Set(to,BishopsQueens);
else Clear(to,BishopsQueens);
if (wtm) {
Clear(to,BlackBishops);
Clear(to,BlackPieces);
HashBB(to,HashKey);
TotalBlackPieces-=bishop_v;
Material+=BISHOP_VALUE;
}
else {
Clear(to,WhiteBishops);
Clear(to,WhitePieces);
HashBW(to,HashKey);
TotalWhitePieces-=bishop_v;
Material-=BISHOP_VALUE;
}
break;
case rook:
if (SlidingRow(piece)) Set(to,RooksQueens);
else Clear(to,RooksQueens);
if (wtm) {
Clear(to,BlackRooks);
Clear(to,BlackPieces);
HashRB(to,HashKey);
if (BlackCastle(ply) > 0) {
if ((to == 56) && (BlackCastle(ply+1)&2)) {
BlackCastle(ply+1)&=1;
HashCastleB(1,HashKey);
}
else if ((to == 63) && (BlackCastle(ply+1)&1)) {
BlackCastle(ply+1)&=2;
HashCastleB(0,HashKey);
}
}
TotalBlackPieces-=rook_v;
Material+=ROOK_VALUE;
}
else {
Clear(to,WhiteRooks);
Clear(to,WhitePieces);
HashRW(to,HashKey);
if (WhiteCastle(ply) > 0) {
if ((to == 0) && (WhiteCastle(ply+1)&2)) {
WhiteCastle(ply+1)&=1;
HashCastleW(1,HashKey);
}
else if ((to == 7) && (WhiteCastle(ply+1)&1)) {
WhiteCastle(ply+1)&=2;
HashCastleW(0,HashKey);
}
}
TotalWhitePieces-=rook_v;
Material-=ROOK_VALUE;
}
break;
case queen:
if (SlidingDiag(piece)) Set(to,BishopsQueens);
else Clear(to,BishopsQueens);
if (SlidingRow(piece)) Set(to,RooksQueens);
else Clear(to,RooksQueens);
if (wtm) {
Clear(to,BlackQueens);
Clear(to,BlackPieces);
HashQB(to,HashKey);
TotalBlackPieces-=queen_v;
Material+=QUEEN_VALUE;
}
else {
Clear(to,WhiteQueens);
Clear(to,WhitePieces);
HashQW(to,HashKey);
TotalWhitePieces-=queen_v;
Material-=QUEEN_VALUE;
}
break;
case king:
printf("captured a king\n");
printf("piece=%d,from=%d,to=%d,captured=%d\n",
piece,from,to,captured);
printf("ply=%d\n",ply);
if (log_file) DisplayChessBoard(log_file,search);
}
}
#if defined(DEBUG)
ValidatePosition(ply+1,move,"MakeMove(2)");
#endif
return;
}
void MakeMoveRoot(int move, int wtm)
{
MakeMove(0,move,wtm);
if (Rule50Moves(1) == 0) {
rephead_b=replist_b;
rephead_w=replist_w;
}
WhiteCastle(1)=Max(0,WhiteCastle(1));
BlackCastle(1)=Max(0,BlackCastle(1));
position[0]=position[1];
if (ChangeSide(wtm))
*rephead_w++=HashKey;
else
*rephead_b++=HashKey;
}
/* 当前文件是D:\Read\movgen.c*/

int* GenerateCaptures(int ply, int wtm, int *move)
{
register BITBOARD target, piecebd, moves;
register BITBOARD  promotions, pcapturesl, pcapturesr;
register int from, to, temp;
if (wtm) {
piecebd=WhiteKnights;
while (piecebd) {
from=LastOne(piecebd);
moves=And(knight_attacks[from],BlackPieces);
temp=from+(knight<<12);
while (moves) {
to=LastOne(moves);
*move++=temp|(to<<6)|((-PieceOnSquare(to))<<15);
Clear(to,moves);
}
Clear(from,piecebd);
}
piecebd=WhiteBishops;
while (piecebd) {
from=LastOne(piecebd);
moves=And(AttacksBishop(from),BlackPieces);
temp=from+(bishop<<12);
while (moves) {
to=LastOne(moves);
*move++=temp|(to<<6)|((-PieceOnSquare(to))<<15);
Clear(to,moves);
}
Clear(from,piecebd);
}
piecebd=WhiteRooks;
while (piecebd) {
from=LastOne(piecebd);
moves=And(AttacksRook(from),BlackPieces);
temp=from+(rook<<12);
while (moves) {
to=LastOne(moves);
*move++=temp|(to<<6)|((-PieceOnSquare(to))<<15);
Clear(to,moves);
}
Clear(from,piecebd);
}
piecebd=WhiteQueens;
while (piecebd) {
from=LastOne(piecebd);
moves=And(AttacksQueen(from),BlackPieces);
temp=from+(queen<<12);
while (moves) {
to=LastOne(moves);
*move++=temp|(to<<6)|((-PieceOnSquare(to))<<15);
Clear(to,moves);
}
Clear(from,piecebd);
}
from=WhiteKingSQ;
moves=And(king_attacks[from],BlackPieces);
temp=from+(king<<12);
while (moves) {
to=LastOne(moves);
*move++=temp|(to<<6)|((-PieceOnSquare(to))<<15);
Clear(to,moves);
}
promotions=And(Shiftr(And(WhitePawns,rank_mask[RANK7]),8),Compl(Occupied));
while (promotions) {
to=LastOne(promotions);
*move++=(to-8)|(to<<6)|(pawn<<12)|(queen<<18);
Clear(to,promotions);
}
target=Or(BlackPieces,EnPassantTarget(ply));
pcapturesl=And(Shiftr(And(WhitePawns,mask_left_edge),7),target);
while (pcapturesl) {
to=LastOne(pcapturesl);
if (to < 56) {
if(PieceOnSquare(to))
*move++=(to-7)|(to<<6)|(pawn<<12)|((-PieceOnSquare(to))<<15);
else
*move++=(to-7)|(to<<6)|(pawn<<12)|(pawn<<15);
}
else
*move++=(to-7)|(to<<6)|(pawn<<12)|((-PieceOnSquare(to))<<15)|(queen<<18);
Clear(to,pcapturesl);
}
pcapturesr=And(Shiftr(And(WhitePawns,mask_right_edge),9),target);
while (pcapturesr) {
to=LastOne(pcapturesr);
if (to < 56) {
if(PieceOnSquare(to))
*move++=(to-9)|(to<<6)|(pawn<<12)|(-PieceOnSquare(to)<<15);
else
*move++=(to-9)|(to<<6)|(pawn<<12)|(pawn<<15);
}
else
*move++=(to-9)|(to<<6)|(pawn<<12)|((-PieceOnSquare(to))<<15)|(queen<<18);
Clear(to,pcapturesr);
}
}
else {
piecebd=BlackKnights;
while (piecebd) {
from=FirstOne(piecebd);
moves=And(knight_attacks[from],WhitePieces);
temp=from+(knight<<12);
while (moves) {
to=FirstOne(moves);
*move++=temp|(to<<6)|(PieceOnSquare(to)<<15);
Clear(to,moves);
}
Clear(from,piecebd);
}
piecebd=BlackBishops;
while (piecebd) {
from=FirstOne(piecebd);
moves=And(AttacksBishop(from),WhitePieces);
temp=from+(bishop<<12);
while (moves) {
to=FirstOne(moves);
*move++=temp|(to<<6)|(PieceOnSquare(to)<<15);
Clear(to,moves);
}
Clear(from,piecebd);
}
piecebd=BlackRooks;
while (piecebd) {
from=FirstOne(piecebd);
moves=And(AttacksRook(from),WhitePieces);
temp=from+(rook<<12);
while (moves) {
to=FirstOne(moves);
*move++=temp|(to<<6)|(PieceOnSquare(to)<<15);
Clear(to,moves);
}
Clear(from,piecebd);
}
piecebd=BlackQueens;
while (piecebd) {
from=FirstOne(piecebd);
moves=And(AttacksQueen(from),WhitePieces);
temp=from+(queen<<12);
while (moves) {
to=FirstOne(moves);
*move++=temp|(to<<6)|(PieceOnSquare(to)<<15);
Clear(to,moves);
}
Clear(from,piecebd);
}
from=BlackKingSQ;
moves=And(king_attacks[from],WhitePieces);
temp=from+(king<<12);
while (moves) {
to=FirstOne(moves);
*move++=temp|(to<<6)|(PieceOnSquare(to)<<15);
Clear(to,moves);
}
promotions=And(Shiftl(And(BlackPawns,rank_mask[RANK2]),8),
Compl(Occupied));
while (promotions) {
to=FirstOne(promotions);
*move++=(to+8)|(to<<6)|(pawn<<12)|(queen<<18);
Clear(to,promotions);
}
target=Or(WhitePieces,EnPassantTarget(ply));
pcapturesl=And(Shiftl(And(BlackPawns,mask_left_edge),9),target);
while (pcapturesl) {
to=FirstOne(pcapturesl);
if (to > 7) {
if(PieceOnSquare(to))
*move++=(to+9)|(to<<6)|(pawn<<12)|(PieceOnSquare(to)<<15);
else
*move++=(to+9)|(to<<6)|(pawn<<12)|(pawn<<15);
}
else
*move++=(to+9)|(to<<6)|(pawn<<12)|(PieceOnSquare(to)<<15)|(queen<<18);
Clear(to,pcapturesl);
}
pcapturesr=And(Shiftl(And(BlackPawns,mask_right_edge),7),target);
while (pcapturesr) {
to=FirstOne(pcapturesr);
if (to > 7) {
if(PieceOnSquare(to))
*move++=(to+7)|(to<<6)|(pawn<<12)|(PieceOnSquare(to)<<15);
else
*move++=(to+7)|(to<<6)|(pawn<<12)|(pawn<<15);
}
else
*move++=(to+7)|(to<<6)|(pawn<<12)|(PieceOnSquare(to)<<15)|(queen<<18);
Clear(to,pcapturesr);
}
}
return(move);
}
int* GenerateCheckEvasions(int ply, int wtm, int *move)
{
register BITBOARD target, targetc, targetp, piecebd, moves;
register BITBOARD padvances1, padvances2, pcapturesl, pcapturesr;
register BITBOARD padvances1_all, empty, checksqs;
register int from, to, temp;
register int king_square, checkers, checking_square;
register int check_direction1=0, check_direction2=0;
if (wtm) {
king_square=WhiteKingSQ;
checksqs=And(AttacksTo(king_square),BlackPieces);
checkers=PopCnt(checksqs);
if (checkers == 1) {
checking_square=FirstOne(And(AttacksTo(king_square),
BlackPieces));
if (PieceOnSquare(checking_square) != -pawn)
check_direction1=directions[checking_square][king_square];
target=InterposeSquares(check_direction1,king_square,checking_square);
target=Or(target,And(AttacksTo(king_square),BlackPieces));
target=Or(target,BlackKing);
}
else {
target=BlackKing;
checking_square=FirstOne(checksqs);
if (PieceOnSquare(checking_square) != -pawn)
check_direction1=directions[checking_square][king_square];
Clear(checking_square,checksqs);
checking_square=FirstOne(checksqs);
if (PieceOnSquare(checking_square) != -pawn)
check_direction2=directions[checking_square][king_square];
}
from=king_square;
moves=And(king_attacks[from],Compl(WhitePieces));
temp=from+(king<<12);
while (moves) {
to=LastOne(moves);
if (!Attacked(to,0) && (directions[from][to] != check_direction1) &&
(directions[from][to] != check_direction2))
*move++=temp|(to<<6)|((-PieceOnSquare(to))<<15);
Clear(to,moves);
}
if (checkers == 1) {
piecebd=WhiteKnights;
while (piecebd) {
from=LastOne(piecebd);
if (!PinnedOnKing(wtm,from)) {
moves=And(knight_attacks[from],target);
temp=from+(knight<<12);
while (moves) {
to=LastOne(moves);
*move++=temp|(to<<6)|((-PieceOnSquare(to))<<15);
Clear(to,moves);
}
}
Clear(from,piecebd);
}
piecebd=WhiteBishops;
while (piecebd) {
from=LastOne(piecebd);
if (!PinnedOnKing(wtm,from)) {
moves=And(AttacksBishop(from),target);
temp=from+(bishop<<12);
while (moves) {
to=LastOne(moves);
*move++=temp|(to<<6)|((-PieceOnSquare(to))<<15);
Clear(to,moves);
}
}
Clear(from,piecebd);
}
piecebd=WhiteRooks;
while (piecebd) {
from=LastOne(piecebd);
if (!PinnedOnKing(wtm,from)) {
moves=And(AttacksRook(from),target);
temp=from+(rook<<12);
while (moves) {
to=LastOne(moves);
*move++=temp|(to<<6)|((-PieceOnSquare(to))<<15);
Clear(to,moves);
}
}
Clear(from,piecebd);
}
piecebd=WhiteQueens;
while (piecebd) {
from=LastOne(piecebd);
if (!PinnedOnKing(wtm,from)) {
moves=And(AttacksQueen(from),target);
temp=from+(queen<<12);
while (moves) {
to=LastOne(moves);
*move++=temp|(to<<6)|((-PieceOnSquare(to))<<15);
Clear(to,moves);
}
}
Clear(from,piecebd);
}
empty=Compl(Occupied);
targetp=And(target,empty);
padvances1=And(Shiftr(WhitePawns,8),targetp);
padvances1_all=And(Shiftr(WhitePawns,8),empty);
padvances2=And(Shiftr(And(padvances1_all,Shiftr(mask_8,16)),8),targetp);
while (padvances2) {
to=LastOne(padvances2);
if (!PinnedOnKing(wtm,to-16)) *move++=(to-16)|(to<<6)|(pawn<<12);
Clear(to,padvances2);
}
while (padvances1) {
to=LastOne(padvances1);
if (!PinnedOnKing(wtm,to-8)) {
if (to < 56) *move++=(to-8)|(to<<6)|(pawn<<12);
else {
*move++=(to-8)|(to<<6)|(pawn<<12)|(queen<<18);
*move++=(to-8)|(to<<6)|(pawn<<12)|(rook<<18);
*move++=(to-8)|(to<<6)|(pawn<<12)|(bishop<<18);
*move++=(to-8)|(to<<6)|(pawn<<12)|(knight<<18);
}
}
Clear(to,padvances1);
}
targetc=Or(BlackPieces,EnPassantTarget(ply));
targetc=And(targetc,target);
if (And(And(BlackPawns,target),Shiftl(EnPassantTarget(ply),8)))
targetc=Or(targetc,EnPassantTarget(ply));
pcapturesl=And(Shiftr(And(WhitePawns,mask_left_edge),7),targetc);
pcapturesr=And(Shiftr(And(WhitePawns,mask_right_edge),9),targetc);
while (pcapturesl) {
to=LastOne(pcapturesl);
if (!PinnedOnKing(wtm,to-7)) {
if (to < 56) {
if(PieceOnSquare(to))
*move++=(to-7)|(to<<6)|(pawn<<12)|((-PieceOnSquare(to))<<15);
else
*move++=(to-7)|(to<<6)|(pawn<<12)|(pawn<<15);
}
else {
*move++=(to-7)|(to<<6)|(pawn<<12)|((-PieceOnSquare(to))<<15)|(queen<<18);
*move++=(to-7)|(to<<6)|(pawn<<12)|((-PieceOnSquare(to))<<15)|(rook<<18);
*move++=(to-7)|(to<<6)|(pawn<<12)|((-PieceOnSquare(to))<<15)|(bishop<<18);
*move++=(to-7)|(to<<6)|(pawn<<12)|((-PieceOnSquare(to))<<15)|(knight<<18);
}
}
Clear(to,pcapturesl);
}
while (pcapturesr) {
to=LastOne(pcapturesr);
if (!PinnedOnKing(wtm,to-9)) {
if (to < 56) {
if(PieceOnSquare(to))
*move++=(to-9)|(to<<6)|(pawn<<12)|((-PieceOnSquare(to))<<15);
else
*move++=(to-9)|(to<<6)|(pawn<<12)|(pawn<<15);
}
else {
*move++=(to-9)|(to<<6)|(pawn<<12)|((-PieceOnSquare(to))<<15)|(queen<<18);
*move++=(to-9)|(to<<6)|(pawn<<12)|((-PieceOnSquare(to))<<15)|(rook<<18);
*move++=(to-9)|(to<<6)|(pawn<<12)|((-PieceOnSquare(to))<<15)|(bishop<<18);
*move++=(to-9)|(to<<6)|(pawn<<12)|((-PieceOnSquare(to))<<15)|(knight<<18);
}
}
Clear(to,pcapturesr);
}
}
}
else {
king_square=BlackKingSQ;
checksqs=And(AttacksTo(king_square),WhitePieces);
checkers=PopCnt(checksqs);
if (checkers == 1) {
checking_square=FirstOne(And(AttacksTo(king_square),
WhitePieces));
if (PieceOnSquare(checking_square) != pawn)
check_direction1=directions[checking_square][king_square];
target=InterposeSquares(check_direction1,king_square,checking_square);
target=Or(target,And(AttacksTo(king_square),WhitePieces));
target=Or(target,WhiteKing);
}
else {
target=WhiteKing;
checking_square=FirstOne(checksqs);
if (PieceOnSquare(checking_square) != pawn)
check_direction1=directions[checking_square][king_square];
Clear(checking_square,checksqs);
checking_square=FirstOne(checksqs);
if (PieceOnSquare(checking_square) != pawn)
check_direction2=directions[checking_square][king_square];
}
from=king_square;
moves=And(king_attacks[from],Compl(BlackPieces));
temp=from+(king<<12);
while (moves) {
to=FirstOne(moves);
if (!Attacked(to,1) && (directions[from][to] != check_direction1) &&
(directions[from][to] != check_direction2))
*move++=temp|(to<<6)|(PieceOnSquare(to)<<15);
Clear(to,moves);
}
if (checkers == 1) {
piecebd=BlackKnights;
while (piecebd) {
from=FirstOne(piecebd);
if (!PinnedOnKing(wtm,from)) {
moves=And(knight_attacks[from],target);
temp=from+(knight<<12);
while (moves) {
to=FirstOne(moves);
*move++=temp|(to<<6)|(PieceOnSquare(to)<<15);
Clear(to,moves);
}
}
Clear(from,piecebd);
}
piecebd=BlackBishops;
while (piecebd) {
from=FirstOne(piecebd);
if (!PinnedOnKing(wtm,from)) {
moves=And(AttacksBishop(from),target);
temp=from+(bishop<<12);
while (moves) {
to=FirstOne(moves);
*move++=temp|(to<<6)|(PieceOnSquare(to)<<15);
Clear(to,moves);
}
}
Clear(from,piecebd);
}
piecebd=BlackRooks;
while (piecebd) {
from=FirstOne(piecebd);
if (!PinnedOnKing(wtm,from)) {
moves=And(AttacksRook(from),target);
temp=from+(rook<<12);
while (moves) {
to=FirstOne(moves);
*move++=temp|(to<<6)|(PieceOnSquare(to)<<15);
Clear(to,moves);
}
}
Clear(from,piecebd);
}
piecebd=BlackQueens;
while (piecebd) {
from=FirstOne(piecebd);
if (!PinnedOnKing(wtm,from)) {
moves=And(AttacksQueen(from),target);
temp=from+(queen<<12);
while (moves) {
to=FirstOne(moves);
*move++=temp|(to<<6)|(PieceOnSquare(to)<<15);
Clear(to,moves);
}
}
Clear(from,piecebd);
}
empty=Compl(Occupied);
targetp=And(target,empty);
padvances1=And(Shiftl(BlackPawns,8),targetp);
padvances1_all=And(Shiftl(BlackPawns,8),empty);
padvances2=And(Shiftl(And(padvances1_all,Shiftl(mask_120,16)),8),targetp);
while (padvances2) {
to=FirstOne(padvances2);
if (!PinnedOnKing(wtm,to+16)) *move++=(to+16)|(to<<6)|(pawn<<12);
Clear(to,padvances2);
}
while (padvances1) {
to=FirstOne(padvances1);
if (!PinnedOnKing(wtm,to+8)) {
if (to > 7) *move++=(to+8)|(to<<6)|(pawn<<12);
else {
*move++=(to+8)|(to<<6)|(pawn<<12)|(queen<<18);
*move++=(to+8)|(to<<6)|(pawn<<12)|(rook<<18);
*move++=(to+8)|(to<<6)|(pawn<<12)|(bishop<<18);
*move++=(to+8)|(to<<6)|(pawn<<12)|(knight<<18);
}
}
Clear(to,padvances1);
}
targetc=Or(WhitePieces,EnPassantTarget(ply));
targetc=And(targetc,target);
if (And(And(WhitePawns,target),Shiftr(EnPassantTarget(ply),8)))
targetc=Or(targetc,EnPassantTarget(ply));
pcapturesl=And(Shiftl(And(BlackPawns,mask_left_edge),9),targetc);
pcapturesr=And(Shiftl(And(BlackPawns,mask_right_edge),7),targetc);
while (pcapturesl) {
to=FirstOne(pcapturesl);
if (!PinnedOnKing(wtm,to+9)) {
if (to > 7) {
if(PieceOnSquare(to))
*move++=(to+9)|(to<<6)|(pawn<<12)|(PieceOnSquare(to)<<15);
else
*move++=(to+9)|(to<<6)|(pawn<<12)|(pawn<<15);
}
else {
*move++=(to+9)|(to<<6)|(pawn<<12)|(PieceOnSquare(to)<<15)|(queen<<18);
*move++=(to+9)|(to<<6)|(pawn<<12)|(PieceOnSquare(to)<<15)|(rook<<18);
*move++=(to+9)|(to<<6)|(pawn<<12)|(PieceOnSquare(to)<<15)|(bishop<<18);
*move++=(to+9)|(to<<6)|(pawn<<12)|(PieceOnSquare(to)<<15)|(knight<<18);
}
}
Clear(to,pcapturesl);
}
while (pcapturesr) {
to=FirstOne(pcapturesr);
if (!PinnedOnKing(wtm,to+7)) {
if (to > 7) {
if(PieceOnSquare(to))
*move++=(to+7)|(to<<6)|(pawn<<12)|(PieceOnSquare(to)<<15);
else
*move++=(to+7)|(to<<6)|(pawn<<12)|(pawn<<15);
}
else {
*move++=(to+7)|(to<<6)|(pawn<<12)|(PieceOnSquare(to)<<15)|(queen<<18);
*move++=(to+7)|(to<<6)|(pawn<<12)|(PieceOnSquare(to)<<15)|(rook<<18);
*move++=(to+7)|(to<<6)|(pawn<<12)|(PieceOnSquare(to)<<15)|(bishop<<18);
*move++=(to+7)|(to<<6)|(pawn<<12)|(PieceOnSquare(to)<<15)|(knight<<18);
}
}
Clear(to,pcapturesr);
}
}
}
return(move);
}
int* GenerateNonCaptures(int ply, int wtm, int *move)
{
register BITBOARD target, piecebd, moves;
register BITBOARD  padvances1, padvances2, pcapturesl, pcapturesr;
register int from, to, temp;
if (wtm) {
if (WhiteCastle(ply) > 0) {
if ((WhiteCastle(ply)&1) && !And(Occupied,Shiftr(mask_2,5)) &&
!Attacked(E1,0) && !Attacked(F1,0) && !Attacked(G1,0)) {
*move++=12676;
}
if ((WhiteCastle(ply)&2) && !And(Occupied,Shiftr(mask_3,1)) &&
!Attacked(C1,0) && !Attacked(D1,0) && !Attacked(E1,0)) {
*move++=12420;
}
}
target=Compl(Occupied);
piecebd=WhiteKnights;
while (piecebd) {
from=LastOne(piecebd);
moves=And(knight_attacks[from],target);
temp=from+(knight<<12);
while (moves) {
to=LastOne(moves);
*move++=temp|(to<<6);
Clear(to,moves);
}
Clear(from,piecebd);
}
piecebd=WhiteBishops;
while (piecebd) {
from=LastOne(piecebd);
moves=And(AttacksBishop(from),target);
temp=from+(bishop<<12);
while (moves) {
to=LastOne(moves);
*move++=temp|(to<<6);
Clear(to,moves);
}
Clear(from,piecebd);
}
piecebd=WhiteRooks;
while (piecebd) {
from=LastOne(piecebd);
moves=And(AttacksRook(from),target);
temp=from+(rook<<12);
while (moves) {
to=LastOne(moves);
*move++=temp|(to<<6);
Clear(to,moves);
}
Clear(from,piecebd);
}
piecebd=WhiteQueens;
while (piecebd) {
from=LastOne(piecebd);
moves=And(AttacksQueen(from),target);
temp=from+(queen<<12);
while (moves) {
to=LastOne(moves);
*move++=temp|(to<<6);
Clear(to,moves);
}
Clear(from,piecebd);
}
from=WhiteKingSQ;
moves=And(king_attacks[from],target);
temp=from+(king<<12);
while (moves) {
to=LastOne(moves);
*move++=temp|(to<<6);
Clear(to,moves);
}
padvances1=And(Shiftr(WhitePawns,8),target);
padvances2=And(Shiftr(And(padvances1,mask_advance_2_w),8),target);
while (padvances2) {
to=LastOne(padvances2);
*move++=(to-16)|(to<<6)|(pawn<<12);
Clear(to,padvances2);
}
while (padvances1) {
to=LastOne(padvances1);
if (to < 56) *move++=(to-8)|(to<<6)|(pawn<<12);
else {
*move++=(to-8)|(to<<6)|(pawn<<12)|(rook<<18);
*move++=(to-8)|(to<<6)|(pawn<<12)|(bishop<<18);
*move++=(to-8)|(to<<6)|(pawn<<12)|(knight<<18);
}
Clear(to,padvances1);
}
target=And(BlackPieces,rank_mask[RANK8]);
pcapturesl=And(Shiftr(And(WhitePawns,mask_left_edge),7),target);
pcapturesr=And(Shiftr(And(WhitePawns,mask_right_edge),9),target);
while (pcapturesl) {
to=LastOne(pcapturesl);
*move++=(to-7)|(to<<6)|(pawn<<12)|((-PieceOnSquare(to))<<15)|(rook<<18);
*move++=(to-7)|(to<<6)|(pawn<<12)|((-PieceOnSquare(to))<<15)|(bishop<<18);
*move++=(to-7)|(to<<6)|(pawn<<12)|((-PieceOnSquare(to))<<15)|(knight<<18);
Clear(to,pcapturesl);
}
while (pcapturesr) {
to=LastOne(pcapturesr);
*move++=(to-9)|(to<<6)|(pawn<<12)|((-PieceOnSquare(to))<<15)|(rook<<18);
*move++=(to-9)|(to<<6)|(pawn<<12)|((-PieceOnSquare(to))<<15)|(bishop<<18);
*move++=(to-9)|(to<<6)|(pawn<<12)|((-PieceOnSquare(to))<<15)|(knight<<18);
Clear(to,pcapturesr);
}
}
else {
if (BlackCastle(ply) > 0) {
if ((BlackCastle(ply)&1) && !And(Occupied,Shiftr(mask_2,61)) &&
!Attacked(E8,1) && !Attacked(F8,1) && !Attacked(G8,1)) {
*move++=16316;
}
if ((BlackCastle(ply)&2) && !And(Occupied,Shiftr(mask_3,57)) &&
!Attacked(C8,1) && !Attacked(D8,1) && !Attacked(E8,1)) {
*move++=16060;
}
}
target=Compl(Occupied);
piecebd=BlackKnights;
while (piecebd) {
from=FirstOne(piecebd);
moves=And(knight_attacks[from],target);
temp=from+(knight<<12);
while (moves) {
to=FirstOne(moves);
*move++=temp|(to<<6);
Clear(to,moves);
}
Clear(from,piecebd);
}
piecebd=BlackBishops;
while (piecebd) {
from=FirstOne(piecebd);
moves=And(AttacksBishop(from),target);
temp=from+(bishop<<12);
while (moves) {
to=FirstOne(moves);
*move++=temp|(to<<6);
Clear(to,moves);
}
Clear(from,piecebd);
}
piecebd=BlackRooks;
while (piecebd) {
from=FirstOne(piecebd);
moves=And(AttacksRook(from),target);
temp=from+(rook<<12);
while (moves) {
to=FirstOne(moves);
*move++=temp|(to<<6);
Clear(to,moves);
}
Clear(from,piecebd);
}
piecebd=BlackQueens;
while (piecebd) {
from=FirstOne(piecebd);
moves=And(AttacksQueen(from),target);
temp=from+(queen<<12);
while (moves) {
to=FirstOne(moves);
*move++=temp|(to<<6);
Clear(to,moves);
}
Clear(from,piecebd);
}
from=BlackKingSQ;
moves=And(king_attacks[from],target);
temp=from+(king<<12);
while (moves) {
to=FirstOne(moves);
*move++=temp|(to<<6);
Clear(to,moves);
}
padvances1=And(Shiftl(BlackPawns,8),target);
padvances2=And(Shiftl(And(padvances1,mask_advance_2_b),8),target);
while (padvances2) {
to=FirstOne(padvances2);
*move++=(to+16)|(to<<6)|(pawn<<12);
Clear(to,padvances2);
}
while (padvances1) {
to=FirstOne(padvances1);
if (to > 7) *move++=(to+8)|(to<<6)|(pawn<<12);
else {
*move++=(to+8)|(to<<6)|(pawn<<12)|(rook<<18);
*move++=(to+8)|(to<<6)|(pawn<<12)|(bishop<<18);
*move++=(to+8)|(to<<6)|(pawn<<12)|(knight<<18);
}
Clear(to,padvances1);
}
target=And(WhitePieces,rank_mask[RANK1]);
pcapturesl=And(Shiftl(And(BlackPawns,mask_left_edge),9),target);
pcapturesr=And(Shiftl(And(BlackPawns,mask_right_edge),7),target);
while (pcapturesl) {
to=FirstOne(pcapturesl);
*move++=(to+9)|(to<<6)|(pawn<<12)|(PieceOnSquare(to)<<15)|(rook<<18);
*move++=(to+9)|(to<<6)|(pawn<<12)|(PieceOnSquare(to)<<15)|(bishop<<18);
*move++=(to+9)|(to<<6)|(pawn<<12)|(PieceOnSquare(to)<<15)|(knight<<18);
Clear(to,pcapturesl);
}
while (pcapturesr) {
to=FirstOne(pcapturesr);
*move++=(to+7)|(to<<6)|(pawn<<12)|(PieceOnSquare(to)<<15)|(rook<<18);
*move++=(to+7)|(to<<6)|(pawn<<12)|(PieceOnSquare(to)<<15)|(bishop<<18);
*move++=(to+7)|(to<<6)|(pawn<<12)|(PieceOnSquare(to)<<15)|(knight<<18);
Clear(to,pcapturesr);
}
}
return(move);
}
/* 当前文件是D:\Read\next.c*/

int NextMove(int ply, int wtm)
{
register int *bestp, *movep, *sortv, temp;
register int history_value, bestval, done, index;
switch (next_status[ply].phase) {
case HASH_MOVE:
next_status[ply].phase=GENERATE_CAPTURE_MOVES;
if (hash_move[ply]) {
current_move[ply]=hash_move[ply];
if (ValidMove(ply,wtm,current_move[ply])) return(HASH_MOVE);
else printf("bad move from hash table, ply=%d\n",ply);
}
case GENERATE_CAPTURE_MOVES:
next_status[ply].phase=CAPTURE_MOVES;
last[ply]=GenerateCaptures(ply, wtm, last[ply-1]);
next_status[ply].remaining=0;
if (hash_move[ply]) {
for (movep=last[ply-1],sortv=sort_value;movep<last[ply];movep++,sortv++)
if (*movep == hash_move[ply]) {
*sortv=-999999;
*movep=0;
hash_move[ply]=0;
}
else {
if (p_values[Piece(*movep)+7] < p_values[Captured(*movep)+7]) {
*sortv=p_values[Captured(*movep)+7]-p_values[Piece(*movep)+7];
next_status[ply].remaining++;
}
else {
*sortv=Swap(From(*movep),To(*movep),wtm);
if (*sortv >= 0)  next_status[ply].remaining++;
}
}
}
else {
for (movep=last[ply-1],sortv=sort_value;movep<last[ply];movep++,sortv++)
if (p_values[Piece(*movep)+7] < p_values[Captured(*movep)+7]) {
*sortv=p_values[Captured(*movep)+7]-p_values[Piece(*movep)+7];
next_status[ply].remaining++;
}
else {
*sortv=Swap(From(*movep),To(*movep),wtm);
if (*sortv >= 0)  next_status[ply].remaining++;
}
}
do {
done=1;
for (movep=last[ply-1],sortv=sort_value;movep<last[ply]-1;movep++,sortv++)
if (*sortv < *(sortv+1)) {
temp=*sortv;
*sortv=*(sortv+1);
*(sortv+1)=temp;
temp=*movep;
*movep=*(movep+1);
*(movep+1)=temp;
done=0;
}
} while(!done);
next_status[ply].last=last[ply-1];
case CAPTURE_MOVES:
if (next_status[ply].remaining) {
current_move[ply]=*(next_status[ply].last);
*next_status[ply].last++=0;
next_status[ply].remaining--;
if (!next_status[ply].remaining) next_status[ply].phase=KILLER_MOVE_1;
return(CAPTURE_MOVES);
}
next_status[ply].phase=KILLER_MOVE_1;
case KILLER_MOVE_1:
if ((hash_move[ply] != killer_move1[ply]) &&
ValidMove(ply,wtm,killer_move1[ply])) {
current_move[ply]=killer_move1[ply];
next_status[ply].phase=KILLER_MOVE_2;
return(KILLER_MOVE_1);
}
case KILLER_MOVE_2:
if ((hash_move[ply] != killer_move2[ply]) &&
ValidMove(ply,wtm,killer_move2[ply])) {
current_move[ply]=killer_move2[ply];
next_status[ply].phase=GENERATE_ALL_MOVES;
return(KILLER_MOVE_2);
}
next_status[ply].phase=GENERATE_ALL_MOVES;
case GENERATE_ALL_MOVES:
last[ply]=GenerateNonCaptures(ply, wtm, last[ply]);
next_status[ply].phase=HISTORY_MOVES_1;
case HISTORY_MOVES_1:
next_status[ply].remaining=1;
next_status[ply].phase=HISTORY_MOVES_2;
bestval=0;
bestp=0;
for (movep=last[ply-1];movep<last[ply];movep++)
if (*movep && ((*movep == hash_move[ply]) || (*movep == killer_move1[ply]) ||
(*movep == killer_move2[ply]))) *movep=0;
else {
index=*movep&4095;
history_value= (wtm) ? history_w[index] : history_b[index];
if (history_value > bestval) {
bestval=history_value;
bestp=movep;
}
}
if (bestp) {
current_move[ply]=*bestp;
*bestp=0;
return(HISTORY_MOVES_1);
}
goto remaining_moves;
case HISTORY_MOVES_2:
bestval=0;
bestp=0;
for (movep=last[ply-1];movep<last[ply];movep++)
if (*movep) {
index=*movep&4095;
history_value= (wtm) ? history_w[index] : history_b[index];
if (history_value > bestval) {
bestval=history_value;
bestp=movep;
}
}
if (bestval) {
current_move[ply]=*bestp;
*bestp=0;
next_status[ply].remaining++;
if (next_status[ply].remaining > 3) {
next_status[ply].phase=REMAINING_MOVES;
next_status[ply].last=last[ply-1];
}
return(HISTORY_MOVES_2);
}
remaining_moves:
next_status[ply].phase=REMAINING_MOVES;
next_status[ply].last=last[ply-1];
case REMAINING_MOVES:
for (;next_status[ply].last<last[ply];next_status[ply].last++)
if (*next_status[ply].last) {
current_move[ply]=*next_status[ply].last;
*next_status[ply].last++=0;
return(REMAINING_MOVES);
}
return(NONE);
default:
printf("oops!  next_status.phase is bad! [normal %d]\n",next_status[ply].phase);
return(NONE);
}
}
/* 当前文件是D:\Read\nexte.c*/

int NextEvasion(int ply, int wtm)
{
register int *movep, *sortv;
register int done, temp;
switch (next_status[ply].phase) {
case HASH_MOVE:
last[ply]=GenerateCheckEvasions(ply, wtm, last[ply-1]);
if (hash_move[ply]) {
next_status[ply].phase=SORT_ALL_MOVES;
current_move[ply]=hash_move[ply];
if (ValidMove(ply,wtm,current_move[ply])) return(HASH_MOVE);
else printf("bad move from hash table, ply=%d\n",ply);
}
case SORT_ALL_MOVES:
next_status[ply].phase=REMAINING_MOVES;
if (hash_move[ply]) {
for (movep=last[ply-1],sortv=sort_value;movep<last[ply];movep++,sortv++)
if (*movep == hash_move[ply]) {
*sortv=-999999;
*movep=0;
}
else {
if (p_values[Piece(*movep)+7] < p_values[Captured(*movep)+7])
*sortv=p_values[Captured(*movep)+7]-p_values[Piece(*movep)+7];
else *sortv=Swap(From(*movep),To(*movep),wtm);
}
}
else {
for (movep=last[ply-1],sortv=sort_value;movep<last[ply];movep++,sortv++)
if (p_values[Piece(*movep)+7] < p_values[Captured(*movep)+7])
*sortv=p_values[Captured(*movep)+7]-p_values[Piece(*movep)+7];
else *sortv=Swap(From(*movep),To(*movep),wtm);
}
do {
done=1;
for (movep=last[ply-1],sortv=sort_value;movep<last[ply]-1;movep++,sortv++)
if (*sortv < *(sortv+1)) {
temp=*sortv;
*sortv=*(sortv+1);
*(sortv+1)=temp;
temp=*movep;
*movep=*(movep+1);
*(movep+1)=temp;
done=0;
}
} while(!done);
next_status[ply].last=last[ply-1];
case REMAINING_MOVES:
for (;next_status[ply].last<last[ply];next_status[ply].last++)
if ((*next_status[ply].last)) {
current_move[ply]=*next_status[ply].last++;
return(REMAINING_MOVES);
}
return(NONE);
default:
printf("oops!  next_status.phase is bad! [evasion %d]\n",next_status[ply].phase);
return(NONE);
}
}
/* 当前文件是D:\Read\nextr.c*/

int NextRootMove(int wtm)
{
register int done, *movep;
char remaining_moves[10];
time_abort+=TimeCheck(1);
if (time_abort) {
abort_search=1;
return(NONE);
}
done=0;
if (!annotate_mode && !pondering && !booking && last[1]-last[0] == 1) {
abort_search=1;
return(NONE);
}
for (movep=last[0];movep<last[1];movep++)
if (searched_this_root_move[movep-last[0]]) done++;
if ((done==1) && searched_this_root_move[0] &&
(root_value==root_alpha) && !search_failed_high) return(NONE);
for (movep=last[0];movep<last[1];movep++)
if (!searched_this_root_move[movep-last[0]]) {
if (search_move) {
if (search_move > 0) {
if(*movep != search_move) {
searched_this_root_move[movep-last[0]]=1;
continue;
}
}
else {
if(*movep == -search_move) {
searched_this_root_move[movep-last[0]]=1;
continue;
}
}
}
current_move[1]=*movep;
root_move=movep-last[0];
searched_this_root_move[root_move]=1;
return(ROOT_MOVES);
}
return(NONE);
}
/* 当前文件是D:\Read\option.c*/

#if defined(UNIX) || defined(AMIGA)
#  include <unistd.h>
#endif

int Option()
{
char **saveargs;
saveargs=args;
nargs=ReadParse(buffer,args," 	;=/");
if (!nargs) return(1);
if (OptionMatch("alarm",*args)) {
if (!strcmp(args[1],"on")) audible_alarm=0x07;
else if (!strcmp(args[1],"off")) audible_alarm=0x00;
else printf("usage:  alarm on|off\n");
}
else if (OptionMatch("ansi",*args)) {
if (nargs < 2) printf("usage:  ansi on|off\n");
if (!strcmp(args[1],"on")) ansi=1;
else if (!strcmp(args[1],"off")) ansi=0;
}
else if (OptionMatch("auto232",*args) || OptionMatch("DR",*args)) {
if (auto_file) {
fclose(auto_file);
auto_file=0;
auto232=0;
printf("auto232 disabled\n");
}
else {
auto_file=fopen("PRN", "w");
auto232=1;
printf("auto232 enabled\n");
draw_score_is_zero=1;
book_random=3;
book_selection_width=3;
mode=tournament_mode;
}
}
else if (OptionMatch("batch",*args)) {
if (!strcmp(args[1],"on")) batch_mode=1;
else if (!strcmp(args[1],"off")) batch_mode=0;
else printf("usage:  batch on|off\n");
}
else if (OptionMatch("beep",*args)) {
return(xboard);
}
else if (OptionMatch("black",*args)) {
if (strlen(*args) == 1) return(1);
if (thinking || pondering) return (2);
ponder_move=0;
last_pv.path_iteration_depth=0;
last_pv.path_length=0;
wtm=0;
force=0;
}
else if (OptionMatch("bogus",*args)) {
return(xboard);
}
else if (OptionMatch("channel",*args)) {
int tchannel;
nargs=ReadParse(buffer,args," 	;");
if (nargs < 2) {
printf("usage:  channel <n> [title]\n");
return(1);
}
tchannel=atoi(args[1]);
if (tchannel) channel=tchannel;
if (nargs > 1) strcpy(channel_title,args[2]);
}
else if (OptionMatch("clock",*args)) {
if (nargs > 1)
tc_time_remaining=ParseTime(args[1])*6000;
if (tc_time_remaining <= tc_operator_time) {
printf("ERROR:  remaining time less than operator time\n");
printf("ERROR:  resetting operator time to 0:00.\n");
printf("ERROR:  use \"operator n\" command to correct after time control\n");
tc_operator_time=0;
}
if (nargs > 2)
tc_time_remaining_opponent=ParseTime(args[2])*6000;
printf("time remaining %s (Crafty)",
DisplayHHMM(tc_time_remaining));
printf("  %s (opponent).\n",
DisplayHHMM(tc_time_remaining_opponent));
printf("%d moves to next time control (Crafty)\n",
tc_moves_remaining);
}
else if (OptionMatch("display",*args)) {
int i;
if (nargs > 1) {
if (thinking || pondering) return (2);
position[1]=position[0];
PreEvaluate(wtm);
if (OptionMatch("pawn",args[1])) {
DisplayPieceBoards(pawn_value_w,pawn_value_b);
i=Evaluate(1,1,-99999,99999);
printf(" -----------------weak-----------------");
printf("      -----------------weak-----------------\n");
for (i=128;i;i=(i>>1)) printf("%4d ",(i&pawn_score.weak_w)!=0);
printf("    ");
for (i=128;i;i=(i>>1)) printf("%4d ",(i&pawn_score.weak_b)!=0);
printf("\n");
}
if (OptionMatch("knight",args[1]))
DisplayPieceBoards(knight_value_w,knight_value_b);
if (OptionMatch("bishop",args[1]))
DisplayPieceBoards(bishop_value_w,bishop_value_b);
if (OptionMatch("rook",args[1]))
DisplayPieceBoards(rook_value_w,rook_value_b);
if (OptionMatch("queen",args[1]))
DisplayPieceBoards(queen_value_w,queen_value_b);
if (OptionMatch("king",args[1]))
DisplayPieceBoards(king_value_w,king_value_b);
}
else DisplayChessBoard(stdout,display);
}
else if (!strcmp("delay",*args)) {
if (nargs < 2) {
printf("usage:  delay <n>\n");
return(1);
}
auto232_delay=atoi(args[1]);
printf("auto232 delay value set to %d ms.\n",auto232_delay);
}
else if (!strcmp("depth",*args)) {
if (nargs < 2) {
printf("usage:  depth <n>\n");
return(1);
}
search_depth=atoi(args[1]);
printf("search depth set to %d.\n",search_depth);
}
else if (OptionMatch("draw",*args)) {
}
else if (OptionMatch("drawscore",*args)) {
if (nargs < 2) {
printf("usage:  drawscore <n>\n");
return(1);
}
default_draw_score=atoi(args[1]);
printf("draw score set to %7.2f pawns.\n",
((double) default_draw_score) / 100.0);
}
else if (OptionMatch("easy",*args)) {
return(xboard);
}
else if (OptionMatch("echo",*args) || OptionMatch("title",*args)) {
}
else if (OptionMatch("edit",*args) && strcmp(*args,"ed")) {
if (thinking || pondering) return (2);
Edit();
ponder_move=0;
last_pv.path_iteration_depth=0;
last_pv.path_length=0;
strcpy(buffer,"savepos *");
(void) Option();
}
else if (OptionMatch("egtb",*args)) {
if (nargs < 2) printf("usage:  tb <n>\n");
EGTBlimit=atoi(args[1]);
if (EGTBlimit!=0 && EGTBlimit!=4 && EGTBlimit!=5) {
printf("egtb value must be 0, 4 or 5 *only*\n");
EGTBlimit=0;
}
}
else if (OptionMatch("end",*args) || OptionMatch("quit",*args)) {
printf("execution complete.\n");
fflush(stdout);
if (history_file) fclose(history_file);
exit(0);
}
else if (OptionMatch("eot",*args)) {
}
else if (OptionMatch("exit",*args)) {
if (analyze_mode) return(0);
if (input_stream != stdin) fclose(input_stream);
input_stream=stdin;
ReadClear();
printf("\n");
}
else if (OptionMatch("flip",*args)) {
int file, rank, piece;
if (thinking || pondering) return(2);
for (rank=0;rank<4;rank++) {
for (file=0;file<8;file++) {
piece=-PieceOnSquare((rank<<3)+file);
PieceOnSquare((rank<<3)+file)=-PieceOnSquare(((7-rank)<<3)+file);
PieceOnSquare(((7-rank)<<3)+file)=piece;
}
}
SetChessBitBoards(&position[0]);
}
else if (OptionMatch("flop",*args)) {
int file, rank, piece;
if (thinking || pondering) return(2);
for (rank=0;rank<8;rank++) {
for (file=0;file<4;file++) {
piece=PieceOnSquare((rank<<3)+file);
PieceOnSquare((rank<<3)+file)=PieceOnSquare((rank<<3)+7-file);
PieceOnSquare((rank<<3)+7-file)=piece;
}
}
SetChessBitBoards(&position[0]);
}
else if (OptionMatch("force",*args)) {
int move, movenum, save_move_number;
char text[16];
if (xboard) {
force=1;
return(3);
}
if (thinking || pondering) return (2);
if (nargs < 2) {
printf("usage:  force <move>\n");
return(1);
}
ponder_move=0;
last_pv.path_iteration_depth=0;
last_pv.path_length=0;
save_move_number=move_number;
movenum=move_number;
if (wtm) movenum--;
strcpy(text,args[1]);
sprintf(buffer,"reset %d",movenum);
wtm=ChangeSide(wtm);
(void) Option();
move=InputMove(text,0,wtm,0,0);
if (move) {
if (input_stream != stdin) printf("%s\n",OutputMove(&move,0,wtm));
fseek(history_file,((movenum-1)*2+1-wtm)*10,SEEK_SET);
fprintf(history_file,"%9s\n",OutputMove(&move,0,wtm));
MakeMoveRoot(move,wtm);
last_pv.path_iteration_depth=0;
last_pv.path_length=0;
}
else if (input_stream == stdin) printf("illegal move.\n");
wtm=ChangeSide(wtm);
move_number=save_move_number;
}
else if (OptionMatch("go",*args) || OptionMatch("move",*args)) {
char temp[64];
if (thinking) return(2);
if (wtm) {
if (strncmp(pgn_white,"Crafty",6)) {
strcpy(temp,pgn_white);
strcpy(pgn_white,pgn_black);
strcpy(pgn_black,temp);
}
}
else{
if (strncmp(pgn_black,"Crafty",6)) {
strcpy(temp,pgn_white);
strcpy(pgn_white,pgn_black);
strcpy(pgn_black,temp);
}
}
return(-1);
}
else if (OptionMatch("history",*args)) {
int i;
char buffer[128];
printf("    white       black\n");
for (i=0;i<(move_number-1)*2-wtm+1;i++) {
fseek(history_file,i*10,SEEK_SET);
fscanf(history_file,"%s",buffer);
if (!(i%2)) printf("%3d",i/2+1);
printf("  %-10s",buffer);
if (i%2 == 1) printf("\n");
}
if (ChangeSide(wtm))printf("  ...\n");
}
else if (OptionMatch("hard",*args)) {
return(xboard);
}
else if (OptionMatch("hash",*args)) {
int i, new_hash_size;
if (thinking || pondering) return(2);
if (nargs > 1) {
new_hash_size=atoi(args[1]);
if (strchr(args[1],'K') || strchr(args[1],'k')) new_hash_size*=1<<10;
if (strchr(args[1],'M') || strchr(args[1],'m')) new_hash_size*=1<<20;
if (new_hash_size < 65536) {
printf("ERROR.  Minimum hash table size is 64K bytes.\n");
return(1);
}
if (new_hash_size > 0) {
if (hash_table_size) {
free(trans_ref_wa);
free(trans_ref_wb);
free(trans_ref_ba);
free(trans_ref_bb);
}
new_hash_size/=16*6;
for (log_hash=0;log_hash<(int) (8*sizeof(int));log_hash++)
if ((1<<(log_hash+1)) > new_hash_size) break;
if (log_hash) {
hash_table_size=1<<log_hash;
trans_ref_wa=malloc(16*hash_table_size);
trans_ref_wb=malloc(16*2*hash_table_size);
trans_ref_ba=malloc(16*hash_table_size);
trans_ref_bb=malloc(16*2*hash_table_size);
if (!trans_ref_wa || !trans_ref_wb || !trans_ref_ba || !trans_ref_bb) {
printf("malloc() failed, not enough memory.\n");
free(trans_ref_wa);
free(trans_ref_wb);
free(trans_ref_ba);
free(trans_ref_bb);
hash_table_size=0;
log_hash=0;
trans_ref_wa=0;
trans_ref_wb=0;
trans_ref_ba=0;
trans_ref_bb=0;
}
hash_maska=(1<<log_hash)-1;
hash_maskb=(1<<(log_hash+1))-1;
for (i=0;i<hash_table_size;i++) {
(trans_ref_wa+i)->word1=Shiftl((BITBOARD) 7,61);
(trans_ref_wa+i)->word2=0;
(trans_ref_ba+i)->word1=Shiftl((BITBOARD) 7,61);
(trans_ref_ba+i)->word2=0;
}
for (i=0;i<2*hash_table_size;i++) {
(trans_ref_wb+i)->word1=0;
(trans_ref_wb+i)->word2=0;
(trans_ref_bb+i)->word1=0;
(trans_ref_bb+i)->word2=0;
}
}
else {
trans_ref_wa=0;
trans_ref_wb=0;
trans_ref_ba=0;
trans_ref_bb=0;
hash_table_size=0;
log_hash=0;
}
}
else printf("ERROR:  hash table size must be > 0\n");
}
if (hash_table_size*6*sizeof(HASH_ENTRY) < 1<<20)
printf("hash table memory = %luK bytes.\n",
(unsigned long) hash_table_size*6*sizeof(HASH_ENTRY)/(1<<10));
else {
if (hash_table_size*6*sizeof(HASH_ENTRY)%(1<<20))
printf("hash table memory = %.1fM bytes.\n",
(double) hash_table_size*6*sizeof(HASH_ENTRY)/(1<<20));
else
printf("hash table memory = %luM bytes.\n",
(unsigned long) hash_table_size*6*sizeof(HASH_ENTRY)/(1<<20));
}
}
else if (OptionMatch("hashp",*args)) {
int i, new_hash_size;
if (thinking || pondering) return(2);
if (nargs > 1) {
new_hash_size=atoi(args[1]);
if (strchr(args[1],'K') || strchr(args[1],'k')) new_hash_size*=1<<10;
if (strchr(args[1],'M') || strchr(args[1],'m')) new_hash_size*=1<<20;
if (new_hash_size > 0) {
if (pawn_hash_table) {
free(pawn_hash_table);
pawn_hash_table_size=0;
log_pawn_hash=0;
pawn_hash_table=0;
}
new_hash_size/=sizeof(PAWN_HASH_ENTRY);
for (log_pawn_hash=0;
log_pawn_hash<(int) (8*sizeof(int));
log_pawn_hash++)
if ((1<<(log_pawn_hash+1)) > new_hash_size) break;
pawn_hash_table_size=1<<log_pawn_hash;
pawn_hash_table=malloc(sizeof(PAWN_HASH_ENTRY)*pawn_hash_table_size);
if (!pawn_hash_table) {
printf("malloc() failed, not enough memory.\n");
free(pawn_hash_table);
pawn_hash_table_size=0;
log_pawn_hash=0;
pawn_hash_table=0;
}
pawn_hash_mask=((unsigned int) 037777777777)>>(32-log_pawn_hash);
for (i=0;i<pawn_hash_table_size;i++) {
(pawn_hash_table+i)->key=0;
(pawn_hash_table+i)->p_score=0;
(pawn_hash_table+i)->black_protected=0;
(pawn_hash_table+i)->white_protected=0;
(pawn_hash_table+i)->black_pof=0;
(pawn_hash_table+i)->white_pof=0;
(pawn_hash_table+i)->weak_b=0;
(pawn_hash_table+i)->weak_w=0;
(pawn_hash_table+i)->black_defects_k=0;
(pawn_hash_table+i)->black_defects_q=0;
(pawn_hash_table+i)->white_defects_k=0;
(pawn_hash_table+i)->white_defects_q=0;
(pawn_hash_table+i)->passed_w=0;
(pawn_hash_table+i)->passed_w=0;
(pawn_hash_table+i)->outside=0;
}
}
else printf("ERROR:  pawn hash table size must be > 0\n");
}
if (pawn_hash_table_size*sizeof(PAWN_HASH_ENTRY) < 1<<20)
printf("pawn hash table memory = %luK bytes.\n",
(unsigned long) pawn_hash_table_size*sizeof(PAWN_HASH_ENTRY)/(1<<10));
else {
if (pawn_hash_table_size*sizeof(PAWN_HASH_ENTRY)%(1<<20))
printf("pawn hash table memory = %.1fM bytes.\n",
(double) pawn_hash_table_size*sizeof(PAWN_HASH_ENTRY)/(1<<20));
else
printf("pawn hash table memory = %luM bytes.\n",
(unsigned long) pawn_hash_table_size*sizeof(PAWN_HASH_ENTRY)/(1<<20));
}
}
else if (OptionMatch("help",*args)) {
if (nargs > 1) {
if (!strcmp("analyze",args[1])) {
printf("analyze\n");
printf("the analyze command puts Crafty into a mode where it will\n");
printf("search forever in the current position.  when a move is\n");
printf("entered, crafty will make that move, switch sides, and\n");
printf("again compute, printing analysis as it searches.  you can\n");
printf("back up a move by entering \"back\" or you can back up\n");
printf("several moves by entering \"back <n>\".  note that <n> is\n");
printf("the number of moves, counting each player's move as one.\n");
}
else if (!strcmp("annotate",args[1])) {
printf("annotate filename b|w|bw moves margin time [n]\n");
printf("where filename is the input file with game moves, while the\n");
printf("output will be written to filename.can.  the input file is\n");
printf("PGN-compatible with one addition, the ability to request that\n");
printf("alternative moves also be analyzed at any point.  to do this\n");
printf("at the point where you have alternative moves, simply include\n");
printf("them in braces {move1, move2}, and Crafty will then search\n");
printf("them also. b/w/bw indicates whether to annotate only the white\n");
printf("side (w), the black side (b) or both (bw).  moves indicates\n");
printf("which moves to annotate.  a single value says start at the\n");
printf("indicated move and go through the entire game.  a range (20-30)\n");
printf("annoates the given range only. margin is the difference between\n");
printf("the search value for the move played in the game, and the best move\n");
printf("crafty found, before a comment is generated (pawn=1.0).  time is\n");
printf("the time limit per move in seconds.  if the optional \"n\" is\n");
printf("appended, this produces N best moves/scores/PV's, rather than\n");
printf("just the very best move.  it won't display any move that is worse\n");
printf("than the actual game move played, but you can use -N to force\n");
printf("Crafty to produce N PV's regardless of how bad they get.\n");
}
else if (!strcmp("book",args[1])) {
printf("you can use the following commands to customize how the\n");
printf("program uses the opening book(book.bin and books.bin).\n");
printf("typically, book.bin contains a large opening database made\n");
printf("from GM games.  books.bin is a short, customized book that\n");
printf("contains selected lines that are well-suited to Crafty's\n");
printf("style of play.  the <flags> can further refine how this\n");
printf("small book file is used to encourage/avoid specific lines.\n");
printf("book[s] create [<filename>] [maxply] [mp]...creates a new\n");
printf("   book by first removing the old book.bin.  it then will\n");
printf("   parse <filename> and add the moves to either book.bin (if\n");
printf("   the book create command was used) or to books.bin (if the\n");
printf("   books create command was used.)  <maxply> truncates book\n");
printf("   lines after that many plies (typically 60).  <mp> will \n");
printf("   exclude *any* move not appearing <mp> times in the input.\n");
printf("book mask accept <chars>...............sets the accept mask to\n");
printf("   the flag characters in <chars> (see flags below.)  any flags\n");
printf("   set in this mask will include either (a) moves with the \n");
printf("   flag set, or (b) moves with no flags set.\n");
printf("more...");
fflush(stdout);
(void) Read(1,buffer);
printf("book mask reject <chars>...............sets the reject mask to\n");
printf("   the flag characters in <chars> (see flags below.)  any flags\n");
printf("   set in this mask will reject any moves with the flag\n");
printf("   set (in the opening book.)\n");
printf("book off...............................turns the book completely off.\n");
printf("book random n..........................controls how random the program\n");
printf("   chooses its opening moves.  <0> will play the least\n");
printf("   randomly and follow book lines that are well-suited to\n");
printf("   Crafty's style of play.  this mode also uses an alpha/beta\n");
printf("   search to select from the set of book moves.  <1> chooses\n");
printf("   from the book moves with the best winning percentage.\n");
printf("   <2> chooses from the book moves that were played the\n");
printf("   most frequently in the GM database. <3> uses popularity,\n");
printf("   win/loss ration, and learned results. <4> chooses from the\n");
printf("   moves with the best learned result.  <5> uses the learned\n");
printf("   result, but gives even bad moves a small chance to be played\n");
printf("   even if it was learned to be bad.  <6> similar to <4> but\n");
printf("   this folds in the popularity of a move based on the number\n");
printf("   of times it was played.  <7> chooses from theset of book\n");
printf("   moves that produce the best static evaluation.  <8> chooses\n");
printf("   completely randomly from the known book moves.\n");
printf("book width n...........................specifies how many moves from\n");
printf("   the sorted set of book moves are to be considered.  1 produces\n");
printf("   the best move from the set, but provides little randomness.\n");
printf("   99 includes all moves in the book move set.\n");
printf("more...");
fflush(stdout);
(void) Read(1,buffer);
printf("flags are one (or more) members of the following set of\n");
printf("characters:  {?? ? = ! !! 0 1 2 3 4 5 6 7 8 9 A B C D E F}\n");
printf("normally, ?? means never play, ? means rarely play,\n");
printf("= means drawish opening, ! means good move, !! means always\n");
printf("play, and 0-F are user flags that a user can add to any\n");
printf("move in the book, and by setting the right mask (above) can\n");
printf("force the program to either always play the move or never\n");
printf("play the move.  the special character * means all flags\n");
printf("and is probably dangerous to use.\n");
printf("flags are added to a move by entering the move, a / or \\\n");
printf("followed by the flags.  / means add the flags to the move\n");
printf("preserving other flags already there while \\ means replace\n");
printf("any flags with those following the \\.\n");
printf("the format of the book text (raw data) is as follows:\n");
printf("[title information] (required)\n");
printf("e4 e5 ... (a sequence of moves)\n");
printf("[title information for next line] (required)\n");
printf("e4 e6 ...\n");
printf("end (optional)\n");
printf("\n");
}
else if (OptionMatch("edit",args[1])) {
printf("edit is used to set up or modify a board position.  it \n");
printf("recognizes 4 \"commands\" that it uses to alter/set up the\n");
printf("board position (with appropriate aliases to interface with\n");
printf("x\n");
printf("\n");
printf("# command causes edit to clear the chess board\n");
printf("c command causes edit to toggle piece color.\n");
printf("white command causes edit to place white pieces on the\n");
printf("board; black command causes edit to place black pieces on\n");
printf("the \n");
printf("end (\".\" for xboard) causes edit to exit.\n");
printf("\n");
printf("three strings of the form [piece][file][rank] will\n");
printf("place a [piece] on square [file][rank].  the color is set\n");
printf("by the previous white/black command.  ex:  Ke8 puts a king\n");
printf("on square e8\n");
printf("\n");
}
else if (OptionMatch("list",args[1])) {
printf("list is used to update the GM/IM/computer lists, which are\n");
printf("used internally to control how crafty uses the opening book.\n");
printf("Syntax:  list GM|IM|C [+|-name] ...\n");
printf("   GM/IM/C selects the appropriate list.  if no name is given,\n");
printf("the list is displayed.  if a name is given, it must be preceeded\n");
printf("by a + (add to list) or -(remove from list).  note that this\n");
printf("list is not saved in a file, so that anything added or removed\n");
printf("will be lost when Crafty is re-started.  To solve this, these\n");
printf("commands can be added to the .craftyrc file.\n");
}
else if (OptionMatch("pgn",args[1])) {
printf("the pgn command is used to set the various PGN headers\n");
printf("which are printed at the top of a PGN file produced by the\n");
printf("savegame command.\n");
printf("options are Event, Site, Round, White, WhiteElo, Black,\n");
printf("BlackElo, and Result.  each is followed by the appropriate\n");
printf("value.  most of these should likely be placed in the\n");
printf("crafty.rc/.craftyrc file since they will be constant for a\n");
printf("complete event.\n");
}
else if (OptionMatch("setboard",args[1])) {
printf("sb is used to set up the board in any position desired.  it\n");
printf("uses a forsythe-like string of characters to describe the\n");
printf("board position.\n");
printf("the standard piece codes p,n,b,r,q,k are used to denote the\n");
printf("piece on a square, upper/lower case is used to indicate the\n");
printf("color (WHITE/black) of the piece.\n");
printf("\n");
printf("the pieces are entered with the ranks on the black side of\n");
printf("the board entered first, and the ranks on the white side\n");
printf("entered last (ie rank 8 through rank 1).  empty squares, \n");
printf("a number between 1 and 8 to indicate how many adjacent\n");
printf("squares are empty.  use a / to terminate each rank after\n");
printf("all pieces for that rank have been entered.\n");
printf("\n");
printf("more...");
fflush(stdout);
(void) Read(1,buffer);
printf("the following input will setup the board position that\n");
printf("is given below:\n");
printf("\n");
printf("                  K2R/PPP////q/5ppp/7k/ b\n");
printf("\n");
printf("this assumes that k represents a white king and -q\n");
printf("represents a black queen.\n");
printf("\n");
printf("                   k  *  *  r  *  *  *  *\n");
printf("                   p  p  p  *  *  *  *  *\n");
printf("                   *  *  *  *  *  *  *  *\n");
printf("                   *  *  *  *  *  *  *  *\n");
printf("                   *  *  *  *  *  *  *  *\n");
printf("                  -q  *  *  *  *  *  *  *\n");
printf("                   *  *  *  *  * -p -p -p\n");
printf("                   *  *  *  *  *  *  * -k\n");
printf("\n");
printf("the character after the final / should be either b or w to\n");
printf("indicate the side to move.  after this side-to-move field\n");
printf("any of the following characters can appear to indicate the\n");
printf("following:  KQ: white can castle kingside/queenside/both;\n");
printf("kq: same for black;  a1-h8: indicates the square occupied\n");
printf("by a pawn that can be captured en passant.\n");
}
else if (!strcmp("test",args[1])) {
printf("test <filename> [N]\n");
printf("test is used to run a suite of \"crafty format\"\n");
printf("test positions in a batch run.  <filename> is the\n");
printf("name of the file in crafty test format.  [N] is an\n");
printf("optional paremeter that is used to shorten the test\n");
printf("time.  If crafty likes the solution move for [N]\n");
printf("consecutive iterations, it will stop searching that\n");
printf("position and consider it correct.  This makes a Win At\n");
printf("Chess 60 second run take under 1/2 hour, for example.\n");
printf("the \"crafty format\" requires three lines per position.\n");
printf("The first line must be a \"title\" line and is used to\n");
printf("identify each position.  The second line is a \"setboard\"\n");
printf("command to set the position.  The third line is a line that\n");
printf("begins with \"solution\", and then is followed by one or\n");
printf("more solution moves.  If a position is correct only if a\n");
printf("particular move or moves is *not* played, enter the move\n");
printf("followed by a \"?\?, as in Nf3?, which means that this\n");
printf("position will be counted as correct only if Nf3 is not\n");
printf("played.\n");
}
else if (!strcmp("time",args[1])) {
printf("time controls whether the program uses cpu time or\n");
printf("wall-clock time for timing.  for tournament play,\n");
printf("it is safer to use wall-clock timing, for testing it\n");
printf("may be more consistent to use cpu timing if the\n");
printf("machine is used for other things concurrently with the\n");
printf("tests being run.\n");
printf("\n");
printf("time is also used to set the basic search timing\n");
printf("controls.  the general form of the command is as\n");
printf("follows:\n");
printf("\n");
printf("      time nmoves/ntime/[nmoves/ntime]/[increment]\n");
printf("\n");
printf("nmoves/ntime represents a traditional first time\n");
printf("control when nmoves is an integer representing the\n");
printf("number of moves and ntime is the total time allowed\n");
printf("for these moves.  the [optional] nmoves/ntime is a\n");
printf("traditional secondary time control.  increment is a\n");
printf("feature related to ics play and emulates the fischer\n");
printf("clock where <increment> is added to the time left\n");
printf("after each move is made.\n");
printf("\n");
printf("as an alternative, nmoves can be \"sd\" which represents\n");
printf("a sudden death time control of the remainder of the\n");
printf("game played in ntime.  the optional secondary time\n");
printf("control can be a sudden-death time control, as in the\n");
printf("following example:\n");
printf("\n");
printf("        time 60/30/sd/30\n");
printf("\n");
printf("this sets 60 moves in 30 minutes, then game in 30\n");
printf("additional minutes.  an increment can be added if\n");
printf("desired.\n");
}
else if (!strcmp("verbose",args[1])) {
printf("verbose  0 -> no informational output except moves.\n");
printf("verbose  1 -> display time for moves.\n");
printf("verbose  2 -> display variation when it changes.\n");
printf("verbose  3 -> display variation at end of iteration.\n");
printf("verbose  4 -> display basic search statistics.\n");
printf("verbose  5 -> display search extension statistics.\n");
printf("verbose  6 -> display search hashing statistics.\n");
printf("verbose  9 -> display root moves as they are searched.\n");
}
else printf("no help available for that command\n");
}
else {
printf("alarm on|off..............turns audible alarm on/off.\n");
printf("analyze...................analyze a game in progress\n");
printf("annotate..................annotate game [help].\n");
printf("ansi......................toggles reverse video highlighting.\n");
printf("book......................controls book [help].\n");
printf("black.....................sets black to move.\n");
printf("clock.....................displays chess clock.\n");
printf("d.........................displays chess \n");
printf("draw <n>..................sets default draw score.\n");
printf("echo......................echos output to display.\n");
printf("edit......................edit board position. [help]\n");
printf("end.......................terminates program.\n");
printf("exit......................restores STDIN to key\n");
printf("force <move>..............forces specific move.\n");
printf("help [command]............displays help.\n");
printf("hash n....................sets transposition table size\n");
printf("                          (n bytes, nK bytes or nM bytes)\n");
printf("hashp n...................sets pawn hash table size\n");
printf("history...................display game moves.\n");
printf("import <filename>.........imports learning data (.lrn files).\n");
printf("info......................displays program settings.\n");
printf("more...");
fflush(stdout);
(void) Read(1,buffer);
printf("input <filename> [title]..sets STDIN to <filename>.\n");
printf("                          (and positions to [title] record.)\n");
printf("kibitz <n>................sets kibitz mode <n> on ICS.\n");
printf("level <m> <t> <i>.........sets ICS time controls.\n");
printf("list                      update/display GM/IM/computer lists.\n");
printf("load <file> <title>       load a position from problem file.\n");
printf("log on|off................turn logging on/off.\n");
printf("mode normal|tournament....toggles tournament mode.\n");
printf("move......................initiates search (same as go).\n");
printf("name......................sets opponent's name.\n");
printf("new.......................initialize and start new game.\n");
printf("noise n...................no status until n nodes searched.\n");
printf("operator <minutes>........allocates operator time.\n");
printf("perf......................times the move generator/make_move.\n");
printf("perft.....................tests the move generator/make_move.\n");
printf("pgn option value..........set PGN header information. [help]\n");
printf("ponder on|off.............toggle pondering off/on.\n");
printf("ponder move...............ponder \"move\" as predicted move.\n");
printf("read <filename>...........read moves in [from <filename>].\n");
printf("reada <filename>..........read moves in [from <filename>].\n");
printf("                          (appends to current game history.)\n");
printf("reset n...................reset game to move n.\n");
printf("resign <m> <n>............set resign threshold to <m> pawns.\n");
printf("                          <n> = # of moves before resigning.\n");
printf("more...");
fflush(stdout);
(void) Read(1,buffer);
printf("savegame <filename>.......saves game in PGN format.\n");
printf("savepos <filename>........saves position in FEN string.\n");
printf("score.....................print evaluation of position.\n");
printf("sd n......................sets absolute search depth.\n");
printf("search <move>.............search specified move only.\n");
printf("setboard <FEN>............sets board position to FEN position. [help]\n");
printf("settc.....................set time controls.\n");
printf("show book.................toggle book statistics.\n");
printf("st n......................sets absolute search time.\n");
printf("test <file> [N]...........test a suite of problems. [help]\n");
printf("time......................time controls. [help]\n");
printf("trace n...................display search tree below depth n.\n");
printf("usage <percentage>........adjusts crafty's time usage up or down.\n");
printf("verbose n.................set verbosity level. [help]\n");
printf("whisper n.................sets ICS whisper mode n.\n");
printf("wild n....................sets ICS wild position (7 for now)\n");
printf("white.....................sets white to move.\n");
printf("xboard....................sets xboard compatibility mode.\n");
}
}
else if (!strcmp("hint",*args)) {
printf("Hint: %s\n",hint);
}
else if (OptionMatch("ics",*args)) {
ics=1;
verbosity_level=0;
resign=0;
}
else if (OptionMatch("input",*args)) {
if (thinking || pondering) return(2);
nargs=ReadParse(buffer,args," 	=");
if (nargs < 2) {
printf("usage:  input <filename>\n");
return(1);
}
if (!(input_stream=fopen(args[1],"r"))) {
printf("file does not exist.\n");
input_stream=stdin;
}
}
else if (OptionMatch("info",*args)) {
printf("Crafty version %s\n",version);
if (hash_table_size*6*sizeof(HASH_ENTRY) < 1<<20)
printf("hash table memory = %luK bytes.\n",
(unsigned long) hash_table_size*6*sizeof(HASH_ENTRY)/(1<<10));
else {
if (hash_table_size*6*sizeof(HASH_ENTRY)%(1<<20))
printf("hash table memory = %.1fM bytes.\n",
(double) hash_table_size*6*sizeof(HASH_ENTRY)/(1<<20));
else
printf("hash table memory = %luM bytes.\n",
(unsigned long) hash_table_size*6*sizeof(HASH_ENTRY)/(1<<20));
}
if (pawn_hash_table_size*sizeof(PAWN_HASH_ENTRY) < 1<<20)
printf("pawn hash table memory = %luK bytes.\n",
(unsigned long) pawn_hash_table_size*sizeof(PAWN_HASH_ENTRY)/(1<<10));
else {
if (pawn_hash_table_size*6*sizeof(PAWN_HASH_ENTRY)%(1<<20))
printf("pawn hash table memory = %.1fM bytes.\n",
(double) pawn_hash_table_size*sizeof(PAWN_HASH_ENTRY)/(1<<20));
else
printf("hash table memory = %luM bytes.\n",
(unsigned long) pawn_hash_table_size*sizeof(PAWN_HASH_ENTRY)/(1<<20));
}
if (!tc_sudden_death) {
printf("%d moves/%d minutes %d seconds primary time control\n",
tc_moves, tc_time/6000, (tc_time/100)%60);
printf("%d moves/%d minutes %d seconds secondary time control\n",
tc_secondary_moves, tc_secondary_time/6000,
(tc_secondary_time/100)%60);
if (tc_increment) printf("increment %d seconds.\n",tc_increment/100);
}
else if (tc_sudden_death == 1) {
printf(" game/%d minutes primary time control\n", tc_time/100);
if (tc_increment) printf("increment %d seconds.\n",(tc_increment/100)%60);
}
else if (tc_sudden_death == 2) {
printf("%d moves/%d minutes primary time control\n",
tc_moves, tc_time/6000);
printf("game/%d minutes secondary time control\n",
tc_secondary_time/6000);
if (tc_increment) printf("increment %d seconds.\n",tc_increment/100);
}
}
else if (OptionMatch("kibitz",*args)) {
if (nargs < 2) {
printf("usage:  kibitz <level>\n");
return(1);
}
kibitz=atoi(args[1]);
}
else if (OptionMatch("learn",*args)) {
if (nargs < 2) {
printf("usage:  learn <types>\n");
return(1);
}
learning=atoi(args[1]);
if (learning&book_learning)
printf("book learning enabled\n");
else
printf("book learning disabled\n");
if (learning&position_learning)
printf("position learning enabled\n");
else
printf("position learning disabled\n");
}
else if (OptionMatch("level",*args)) {
if (nargs < 4) {
printf("usage:  level <nmoves> <stime> <inc>\n");
return(1);
}
tc_moves=atoi(args[1]);
tc_time=atoi(args[2])*100;
tc_increment=atoi(args[3])*100;
tc_time_remaining=tc_time;
tc_time_remaining_opponent=tc_time;
if (!tc_moves) {
tc_sudden_death=1;
tc_moves=1000;
tc_moves_remaining=1000;
}
else tc_sudden_death=0;
if (tc_moves) {
tc_secondary_moves=tc_moves;
tc_secondary_time=tc_time;
tc_moves_remaining=tc_moves;
}
if (!tc_sudden_death) {
printf("%d moves/%d minutes primary time control\n",
tc_moves, tc_time/100);
printf("%d moves/%d minutes secondary time control\n",
tc_secondary_moves, tc_secondary_time/100);
if (tc_increment) printf("increment %d seconds.\n",tc_increment/100);
}
else if (tc_sudden_death == 1) {
printf(" game/%d minutes primary time control\n",tc_time/100);
if (tc_increment) printf("increment %d seconds.\n",tc_increment/100);
}
tc_time*=60;
tc_time_remaining=tc_time;
tc_secondary_time*=60;
if (tc_time > 30000 || tc_increment > 300) whisper=0;
if (tc_time <= 6000 && tc_increment <= 100) whisper=0;
}
else if (OptionMatch("list",*args)) {
int i, j;
char listname[8];
char **targs;
targs=args;
strcpy(listname,args[1]);
nargs-=2;
targs+=2;
if (nargs) {
if (!strcmp(listname,"GM")) {
if (targs[0][0] == '-') {
for (i=0;i<number_of_GMs;i++)
if (!strcmp(GM_list[i],targs[0]+1)) {
for (j=i;j<number_of_GMs;j++)
strcpy(GM_list[j],GM_list[j+1]);
number_of_GMs--;
i=0;
printf("%s removed from GM list.\n",targs[0]+1);
break;
}
}
else if (targs[0][0] == '+') {
for (i=0;i<number_of_GMs;i++)
if (!strcmp(GM_list[i],targs[0]+1)) {
printf( "Warning: %s is already in GM list.\n",targs[0]+1);
break;
}
if (number_of_GMs >= 100) printf("ERROR!  GM list is full at 100 entries\n");
else if (i==number_of_GMs) {
strcpy(GM_list[number_of_GMs++],targs[0]+1);
printf("%s added to GM list.\n",targs[0]+1);
}
}
else if (!strcmp(targs[0],"clear")) {
number_of_GMs=0;
}
else printf("error, name must be preceeded by +/- flag.\n");
}
if (!strcmp(listname,"IM")) {
if (targs[0][0] == '-') {
for (i=0;i<number_of_IMs;i++)
if (!strcmp(IM_list[i],targs[0]+1)) {
for (j=i;j<number_of_IMs;j++)
strcpy(IM_list[j],IM_list[j+1]);
number_of_IMs--;
i=0;
printf("%s removed from IM list.\n",targs[0]+1);
break;
}
}
else if (targs[0][0] == '+') {
for (i=0;i<number_of_IMs;i++)
if (!strcmp(IM_list[i],targs[0]+1)) {
printf( "Warning: %s is already in IM list.\n",targs[0]+1);
break;
}
if (number_of_IMs >= 100) printf("ERROR!  IM list is full at 100 entries\n");
else if (i==number_of_IMs) {
strcpy(IM_list[number_of_IMs++],targs[0]+1);
printf("%s added to IM list.\n",targs[0]+1);
}
}
else if (!strcmp(targs[0],"clear")) {
number_of_IMs=0;
}
else printf("error, name must be preceeded by +/- flag.\n");
}
if (!strcmp(listname,"C")) {
if (targs[0][0] == '-') {
for (i=0;i<number_of_computers;i++)
if (!strcmp(computer_list[i],targs[0]+1)) {
for (j=i;j<number_of_computers;j++)
strcpy(computer_list[j],computer_list[j+1]);
number_of_computers--;
i=0;
printf("%s removed from computer list.\n",targs[0]+1);
break;
}
}
else if (targs[0][0] == '+') {
for (i=0;i<number_of_computers;i++)
if (!strcmp(computer_list[i],targs[0]+1)) {
printf( "Warning: %s is already in computer list.\n",targs[0]+1);
break;
}
if (number_of_computers >= 100) printf("ERROR!  C list is full at 100 entries\n");
else if (i==number_of_computers) {
strcpy(computer_list[number_of_computers++],targs[0]+1);
printf("%s added to computer list.\n",targs[0]+1);
}
}
else if (!strcmp(targs[0],"clear")) {
number_of_computers=0;
}
else printf("error, name must be preceeded by +/- flag.\n");
}
if (!strcmp(listname,"AK")) {
if (targs[0][0] == '-') {
for (i=0;i<number_auto_kibitzers;i++)
if (!strcmp(auto_kibitz_list[i],targs[0]+1)) {
for (j=i;j<number_auto_kibitzers;j++)
strcpy(auto_kibitz_list[j],auto_kibitz_list[j+1]);
number_auto_kibitzers--;
i=0;
printf("%s removed from auto kibitz list.\n",targs[0]+1);
break;
}
}
else if (targs[0][0] == '+') {
for (i=0;i<number_auto_kibitzers;i++)
if (!strcmp(auto_kibitz_list[i],targs[0]+1)) {
printf( "Warning: %s is already in auto kibitz list.\n",targs[0]+1);
break;
}
if (number_auto_kibitzers >= 100) printf("ERROR!  AK list is full at 100 entries\n");
else if (i==number_auto_kibitzers) {
strcpy(auto_kibitz_list[number_auto_kibitzers++],targs[0]+1);
printf("%s added to auto kibitz list.\n",targs[0]+1);
}
}
else if (!strcmp(targs[0],"clear")) {
number_auto_kibitzers=0;
}
else printf("error, name must be preceeded by +/- flag.\n");
}
}
else {
if (!strcmp(listname,"GM")) {
printf("GM List:\n");
for (i=0;i<number_of_GMs;i++)
printf("%s\n",GM_list[i]);
}
else if (!strcmp(listname,"IM")) {
printf("IM List:\n");
for (i=0;i<number_of_IMs;i++)
printf("%s\n",IM_list[i]);
}
else if (!strcmp(listname,"C")) {
printf( "computer list:\n");
for (i=0;i<number_of_computers;i++)
printf("%s\n",computer_list[i]);
}
else if (!strcmp(listname,"AK")) {
printf( "auto kibitz list:\n");
for (i=0;i<number_auto_kibitzers;i++)
printf("%s\n",auto_kibitz_list[i]);
}
}
}
else if (OptionMatch("load",*args)) {
char title[64];
char *readstat;
FILE *prob_file;
if (thinking || pondering) return(2);
nargs=ReadParse(buffer,args," 	=");
if (nargs < 3) {
printf("usage:  input <filename> title\n");
return(1);
}
if (!(prob_file=fopen(args[1],"r"))) {
printf("file does not exist.\n");
return(1);
}
strcpy(title,args[2]);
while (!feof(prob_file)) {
readstat=fgets(buffer,128,prob_file);
if (readstat) {
char *delim;
delim=strchr(buffer,'\n');
if (delim) *delim=0;
delim=strchr(buffer,'\r');
if (delim) *delim=0;
}
if (readstat == NULL) break;
nargs=ReadParse(buffer,args," 	;\n");
if (!strcmp(args[0],"title") && strstr(buffer,title)) break;
}
while (!feof(prob_file)) {
readstat=fgets(buffer,128,prob_file);
if (readstat) {
char *delim;
delim=strchr(buffer,'\n');
if (delim) *delim=0;
delim=strchr(buffer,'\r');
if (delim) *delim=0;
}
if (readstat == NULL) break;
nargs=ReadParse(buffer,args," 	;\n");
if (!strcmp(args[0],"setboard")) {
Option();
break;
}
}
}
else if (OptionMatch("log",*args)) {
FILE *output_file;
char filename[64], buffer[128];
if (nargs < 2) {
printf("usage:  log on|off|n [filename]\n");
return(1);
}
if (!strcmp(args[1],"on")) {
for (log_id=1;log_id <300;log_id++) {
sprintf(log_filename,"%s/log.%03d",log_path,log_id);
sprintf(history_filename,"%s/game.%03d",log_path,log_id);
log_file=fopen(log_filename,"r");
if (!log_file) break;
fclose(log_file);
}
log_file=fopen(log_filename,"w");
history_file=fopen(history_filename,"w+");
}
else if (!strcmp(args[1],"off")) {
if (log_file) fclose(log_file);
log_file=0;
sprintf(filename,"%s/log.%03d",log_path,log_id);
remove(filename);
}
else {
int nrecs, trecs, lrecs;
char *eof;
FILE *log;
nrecs=atoi(args[1]);
output_file=stdout;
if (nargs > 2) output_file=fopen(args[2],"w");
log=fopen(log_filename,"r");
for (trecs=1; trecs<99999999; trecs++) {
eof=fgets(buffer,128,log);
if (eof) {
char *delim;
delim=strchr(buffer,'\n');
if (delim) *delim=0;
delim=strchr(buffer,'\r');
if (delim) *delim=0;
}
else break;
}
fseek(log,0,SEEK_SET);
for (lrecs=1; lrecs<trecs-nrecs; lrecs++) {
eof=fgets(buffer,128,log);
if (eof) {
char *delim;
delim=strchr(buffer,'\n');
if (delim) *delim=0;
delim=strchr(buffer,'\r');
if (delim) *delim=0;
}
else break;
}
for (;lrecs<trecs; lrecs++) {
eof=fgets(buffer,128,log);
if (eof) {
char *delim;
delim=strchr(buffer,'\n');
if (delim) *delim=0;
delim=strchr(buffer,'\r');
if (delim) *delim=0;
}
else break;
fprintf(output_file,"%s\n",buffer);
}
if (output_file != stdout) fclose(output_file);
}
}
else if (OptionMatch("mode",*args)) {
if (nargs > 1) {
if (!strcmp(args[1],"tournament")) {
mode=tournament_mode;
draw_score_is_zero=1;
printf("use 'settc' command if a game is restarted after crafty\n");
printf("has been terminated for any reason.\n");
}
else if (!strcmp(args[1],"normal")) {
mode=normal_mode;
draw_score_is_zero=0;
}
else {
printf("usage:  mode normal|tournament\n");
mode=normal_mode;
}
}
if (mode == tournament_mode) printf("tournament mode.\n");
else if (mode == normal_mode) printf("normal mode.\n");
}
else if (OptionMatch("name",*args)) {
int i;
char *next;
if (nargs < 2) {
printf("usage:  name <name>\n");
return(1);
}
if (wtm) {
strcpy(pgn_white,args[1]);
sprintf(pgn_black,"Crafty %s",version);
}
else {
strcpy(pgn_black,args[1]);
sprintf(pgn_white,"Crafty %s",version);
}
printf("Crafty %s vs %s\n",version,args[1]);
next=args[1];
while (*next) {
*next=tolower(*next);
next++;
}
if (mode != tournament_mode) {
for (i=0;i<number_auto_kibitzers;i++)
if (!strcmp(auto_kibitz_list[i],args[1])) {
kibitz=4;
auto_kibitzing=1;
break;
}
for (i=0;i<number_of_computers;i++)
if (!strcmp(computer_list[i],args[1])) {
draw_score_is_zero=1;
book_random=3;
book_selection_width=2;
printf("playing a computer!\n");
break;
}
for (i=0;i<number_of_GMs;i++)
if (!strcmp(GM_list[i],args[1])) {
printf("playing a GM!\n");
book_random=3;
book_selection_width=3;
resign=3;
resign_count=3;
draw_count=6;
kibitz=0;
break;
}
for (i=0;i<number_of_IMs;i++)
if (!strcmp(IM_list[i],args[1])) {
printf("playing an IM!\n");
book_random=3;
book_selection_width=4;
resign=9;
resign_count=5;
draw_count=8;
kibitz=0;
break;
}
}
}
else if (OptionMatch("new",*args) || OptionMatch("AN",*args)) {
new_game=1;
if (thinking || pondering) return(3);
NewGame(0);
return(3);
}
else if (OptionMatch("noise",*args)) {
if (nargs < 2) {
printf("usage:  noise <n>\n");
return(1);
}
noise_level=atoi(args[1]);
printf("noise level set to %d.\n",noise_level);
}
else if (OptionMatch("operator",*args)) {
if (nargs < 2) {
printf("usage:  operator <seconds>\n");
return(1);
}
tc_operator_time=ParseTime(args[1])*100;
printf("reserving %d seconds per move for operator overhead.\n",
tc_operator_time/100);
}
else if (OptionMatch("otime",*args)) {
if (nargs < 2) {
printf("usage:  otime <time(unit=.01 secs))>\n");
return(1);
}
tc_time_remaining_opponent=atoi(args[1]);
if (log_file && time_limit>99)
fprintf(log_file,"time remaining: %s (opponent).\n",
DisplayTime(tc_time_remaining_opponent));
}
else if (OptionMatch("output",*args)) {
if (nargs < 2) {
printf("usage:  output long|short\n");
return(1);
}
if (!strcmp(args[1],"long")) output_format=1;
else if (!strcmp(args[1],"short")) output_format=0;
else printf("usage:  output long|short\n");
if (output_format == 1)
printf("output moves in long algebraic format\n");
else if (output_format == 0)
printf("output moves in short algebraic format\n");
}
else if (OptionMatch("logpath",*args) ||
OptionMatch("bookpath",*args) ||
OptionMatch("tbpath",*args)) {
if (log_file)
printf("ERROR -- this must be used on command line only\n");
else {
nargs=ReadParse(buffer,args," 	=");
if (nargs < 2) {
printf("usage:  bookpath|logpath|tbpath <path>\n");
return(1);
}
if (strstr(args[0],"bookpath")) strcpy(book_path,args[1]);
else if (strstr(args[0],"logpath")) strcpy(log_path,args[1]);
else if (strstr(args[0],"tbpath")) strcpy(tb_path,args[1]);
}
}
#define PERF_CYCLES 100000
else if (OptionMatch("perf",*args)) {
int i, *mv, clock_before, clock_after;
double time_used;
if (thinking || pondering) return(2);
clock_before = clock();
while (clock() == clock_before);
clock_before = clock();
for (i=0;i<PERF_CYCLES;i++) {
last[1]=GenerateCaptures(0, wtm, last[0]);
last[1]=GenerateNonCaptures(0, wtm, last[1]);
}
clock_after=clock();
time_used=((double) clock_after-(double) clock_before) /
(double) CLOCKS_PER_SEC;
printf("generated %ld moves, time=%.2f seconds\n",
(last[1]-last[0])*PERF_CYCLES,time_used);
printf("generated %d moves per second\n",(int) (((double) (PERF_CYCLES*
(last[1]-last[0])))/time_used));
clock_before=clock();
while (clock() == clock_before);
clock_before = clock();
for (i=0;i<PERF_CYCLES;i++) {
last[1]=GenerateCaptures(0, wtm, last[0]);
last[1]=GenerateNonCaptures(0, wtm, last[1]);
for (mv=last[0];mv<last[1];mv++) {
MakeMove(0,*mv,wtm);
UnMakeMove(0,*mv,wtm);
}
}
clock_after=clock();
time_used=((double) clock_after-(double) clock_before) /
(double) CLOCKS_PER_SEC;
printf("generated/made/unmade %ld moves, time=%.2f seconds\n",
(last[1]-last[0])*PERF_CYCLES, time_used);
printf("generated/made/unmade %d moves per second\n",(int) (((double) (PERF_CYCLES*
(last[1]-last[0])))/time_used));
}
else if (OptionMatch("perft",*args)) {
int i;
if (thinking || pondering) return(2);
if (nargs < 2) {
printf("usage:  perftest <depth>\n");
return(1);
}
position[1]=position[0];
last[0]=move_list;
i=atoi(args[1]);
total_moves=0;
OptionPerft(1,i,wtm);
printf("total moves=%d\n",total_moves);
}
else if (OptionMatch("pgn",*args)) {
int i;
if (nargs < 3) {
printf("usage:  pgn <tag> <value>\n");
return(1);
}
if (!strcmp(args[1],"Event")) {
pgn_event[0]=0;
for (i=2;i<nargs;i++) {
strcpy(pgn_event+strlen(pgn_event),args[i]);
strcpy(pgn_event+strlen(pgn_event)," ");
}
}
else if (!strcmp(args[1],"Site")) {
pgn_site[0]=0;
for (i=2;i<nargs;i++) {
strcpy(pgn_site+strlen(pgn_site),args[i]);
strcpy(pgn_site+strlen(pgn_site)," ");
}
}
else if (!strcmp(args[1],"Round")) {
pgn_round[0]=0;
strcpy(pgn_round,args[2]);
}
else if (!strcmp(args[1],"White")) {
pgn_white[0]=0;
for (i=2;i<nargs;i++) {
strcpy(pgn_white+strlen(pgn_white),args[i]);
strcpy(pgn_white+strlen(pgn_white)," ");
}
}
else if (!strcmp(args[1],"WhiteElo")) {
pgn_white_elo[0]=0;
strcpy(pgn_white_elo,args[2]);
}
else if (!strcmp(args[1],"Black")) {
pgn_black[0]=0;
for (i=2;i<nargs;i++) {
strcpy(pgn_black+strlen(pgn_black),args[i]);
strcpy(pgn_black+strlen(pgn_black)," ");
}
}
else if (!strcmp(args[1],"BlackElo")) {
pgn_black_elo[0]=0;
strcpy(pgn_black_elo,args[2]);
}
}
else if (OptionMatch("ponder",*args)) {
if (thinking || pondering) return(2);
if (nargs < 2) {
printf("usage:  ponder off|on|<move>\n");
return(1);
}
if (!strcmp(args[1],"on")) {
ponder=1;
printf("pondering enabled.\n");
}
else if (!strcmp(args[1],"off")) {
ponder=0;
printf("pondering disabled.\n");
}
else {
ponder_move=InputMove(args[1],0,wtm,0,0);
}
}
else if (!strcmp("post",*args)) {
post=1;
}
else if (!strcmp("nopost",*args)) {
post=0;
}
else if (OptionMatch("random",*args)) {
return(xboard);
}
else if (OptionMatch("rating",*args)) {
if (nargs < 3) {
printf("usage:  rating <crafty> <opponent>\n");
return(1);
}
crafty_rating=atoi(args[1]);
opponent_rating=atoi(args[2]);
if (opponent_rating-crafty_rating > 0)
default_draw_score=20;
if (log_file) {
fprintf(log_file,"Crafty's rating: %d.\n",crafty_rating);
fprintf(log_file,"opponent's rating: %d.\n",opponent_rating);
}
}
else if (!strcmp("remove",*args)) {
if (thinking || pondering) return(2);
move_number--;
sprintf(buffer,"reset %d",move_number);
(void) Option();
}
else if (OptionMatch("reset",*args)) {
int i, move, nmoves;
if (thinking || pondering) return(2);
if (nargs < 2) {
printf("usage:  reset <movenumber>\n");
return(1);
}
ponder_move=0;
last_mate_score=0;
last_pv.path_iteration_depth=0;
last_pv.path_length=0;
if (thinking || pondering) return(2);
over=0;
move_number=atoi(args[1]);
if (!move_number) {
move_number=1;
return(1);
}
nmoves=(move_number-1)*2+1-wtm;
root_wtm=ChangeSide(wtm);
InitializeChessBoard(&position[0]);
wtm=1;
move_number=1;
for (i=0;i<nmoves;i++) {
fseek(history_file,i*10,SEEK_SET);
fscanf(history_file,"%s",buffer);
if(strlen(buffer)==0 && i==0) {
	wtm=ChangeSide(wtm);
	continue;
}
move=InputMove(buffer,0,wtm,0,0);
if (move) {
MakeMoveRoot(move,wtm);
}
else {
printf("ERROR!  move %s is illegal\n",buffer);
break;
}
wtm=ChangeSide(wtm);
if (wtm) move_number++;
Phase();
}
moves_out_of_book=0;
tc_moves_remaining=tc_moves-move_number+1;
while (tc_moves_remaining < 0) tc_moves_remaining+=tc_secondary_moves;
printf("NOTICE: %d moves to next time control\n",tc_moves_remaining);
}
else if (OptionMatch("read",*args) || OptionMatch("reada",*args)) {
char *bracket1, *bracket2, **targs;
char text[128], value[32];
int append, move;
	char * readstat;
FILE *read_input=0;
if (thinking || pondering) return(2);
nargs=ReadParse(buffer,args," 	=");
if (!strcmp("reada",*args))
append=1;
else
append=0;
targs=args;
ponder_move=0;
last_pv.path_iteration_depth=0;
last_pv.path_length=0;
if (nargs > 1) {
if (!(read_input=fopen(targs[1],"r"))) {
printf("file %s does not exist.\n",targs[1]);
return(1);
}
nargs--;
targs++;
}
if (!read_input) printf("type \"exit\" to terminate.\n");
if (!append) {
InitializeChessBoard(&position[0]);
wtm=1;
move_number=1;
}
nargs=0;
do {
if (!read_input) {
if (wtm)
printf("read.White(%d): ",move_number);
else
printf("read.Black(%d): ",move_number);
fflush(stdout);
}
if (nargs == 0) {
if (read_input) {
readstat= fgets(buffer,512,read_input);
if (readstat) {
char *delim;
delim=strchr(buffer,'\n');
if (delim) *delim=0;
delim=strchr(buffer,'\r');
if (delim) *delim=0;
}
else break;
}
else {
int readstat=Read(1,buffer);
if (readstat == 0) break;
}
nargs=ReadParse(buffer,saveargs," 	;\n");
targs=saveargs;
if (nargs == -1) {
if (read_input) fclose(read_input);
return(1);
}
else if (nargs == 0) continue;
}
if (!strchr(*targs,'[')) break;
text[0]=0;
strcpy(text,*targs);
while (--nargs) {
strcpy(text+strlen(text)," ");
strcpy(text+strlen(text),*++targs);
}
bracket1=strchr(text,'\"');
bracket2=strchr(bracket1+1,'\"');
if (bracket1 == 0 || bracket2 == 0) break;
*bracket2=0;
strcpy(value,bracket1+1);
if (bracket2 == 0) break;
if (strstr(text,"Event")) strcpy(pgn_event,value);
else if (strstr(text,"Site")) strcpy(pgn_site,value);
else if (strstr(text,"Round")) strcpy(pgn_round,value);
else if (strstr(text,"Date")) strcpy(pgn_date,value);
else if (strstr(text,"WhiteElo")) strcpy(pgn_white_elo,value);
else if (strstr(text,"White")) strcpy(pgn_white,value);
else if (strstr(text,"BlackElo")) strcpy(pgn_black_elo,value);
else if (strstr(text,"Black")) strcpy(pgn_black,value);
else if (strstr(text,"Result")) strcpy(pgn_result,value);
} while (1);
do {
move=0;
if (!read_input) {
if (wtm)
printf("read.White(%d): ",move_number);
else
printf("read.Black(%d): ",move_number);
fflush(stdout);
}
if (nargs == 0) {
if (read_input) {
readstat= fgets(buffer,512,read_input);
if (readstat) {
char *delim;
delim=strchr(buffer,'\n');
if (delim) *delim=0;
delim=strchr(buffer,'\r');
if (delim) *delim=0;
}
else break;
}
else {
int readstat=Read(1,buffer);
if (readstat == 0) break;
}
nargs=ReadParse(buffer,saveargs," 	;\n\r");
targs=saveargs;
if (nargs == 0) continue;
}
if (strchr(*targs,'{')) do {
targs++;
if (!strchr(targs[0],'}')) {
nargs--;
if (nargs==0) {
if (read_input) {
readstat= fgets(buffer,512,read_input);
if (readstat) {
char *delim;
delim=strchr(buffer,'\n');
if (delim) *delim=0;
delim=strchr(buffer,'\r');
if (delim) *delim=0;
}
else break;
}
else {
int readstat=Read(1,buffer);
if (readstat == 0) break;
}
nargs=ReadParse(buffer,saveargs," 	;\n\r");
targs=saveargs;
}
}
else break;
} while(1);
else {
if (!strcmp(*targs,"exit")) {
if (read_input) fclose(read_input);
return(1);
}
move=ReadNextMove(*targs,0,wtm);
if (move) {
if (read_input) {
printf("%s ",OutputMove(&move,0,wtm));
if (!(move_number % 8) && ChangeSide(wtm))
printf("\n");
}
fseek(history_file,((move_number-1)*2+1-wtm)*10,SEEK_SET);
fprintf(history_file,"%9s\n",OutputMove(&move,0,wtm));
MakeMoveRoot(move,wtm);
#if defined(DEBUG)
ValidatePosition(1,move,"Option()");
#endif
}
else if (!read_input) printf("illegal move.\n");
}
if (move) {
wtm=ChangeSide(wtm);
Phase();
if (wtm) move_number++;
}
targs++;
nargs--;
} while (1);
moves_out_of_book=0;
if (read_input) {
printf("\n");
fclose(read_input);
}
}
else if (OptionMatch("resign",*args)) {
if (nargs < 2) {
printf("usage:  resign <value>\n");
return(1);
}
resign=atoi(args[1]);
if (resign)
printf("resignation threshold set to %d pawns.\n",resign);
else
printf("resignations disabled.\n");
}
else if (OptionMatch("savegame",*args) ||
OptionMatch("SR",*args)) {
struct tm *timestruct;
int i, secs, more;
FILE *output_file;
char input[128], text[128], *next;
output_file=stdout;
secs=time(0);
timestruct=localtime((time_t*) &secs);
if (nargs > 1) {
if (!(output_file=fopen(args[1],"w"))) {
printf("unable to open %s for write.\n",args[1]);
return(1);
}
}
fprintf(output_file,"[Event \"%s\"]\n",pgn_event);
fprintf(output_file,"[Site \"%s\"]\n",pgn_site);
fprintf(output_file,"[Date \"%4d.%02d.%02d\"]\n",timestruct->tm_year+1900,
timestruct->tm_mon+1,timestruct->tm_mday);
fprintf(output_file,"[Round \"%s\"]\n",pgn_round);
fprintf(output_file,"[White \"%s\"]\n",pgn_white);
fprintf(output_file,"[WhiteElo \"%s\"]\n",pgn_white_elo);
fprintf(output_file,"[Black \"%s\"]\n",pgn_black);
fprintf(output_file,"[BlackElo \"%s\"]\n",pgn_black_elo);
fprintf(output_file,"[Result \"%s\"]\n\n",pgn_result);
next=text;
more=0;
for (i=0;i<(move_number-1)*2-wtm+1;i++) {
fseek(history_file,i*10,SEEK_SET);
fscanf(history_file,"%s",input);
if (!(i%2)) {
sprintf(next,"%d. ",i/2+1);
next=text+strlen(text);
}
sprintf(next,"%s ",input);
next=text+strlen(text);
more=1;
if (next-text >= 60) {
fprintf(output_file,"%s\n",text);
more=0;
next=text;
}
}
if (more)
fprintf(output_file,"%s\n",text);
if (output_file != stdout) fclose(output_file);
printf("PGN save complete.\n");
}
else if (OptionMatch("savepos",*args)) {
char xlate[15]={'q','r','b',0,'k','n','p',0,'P','N','K',0,'B','R','Q'};
char empty[9]={' ','1','2','3','4','5','6','7','8'};
int rank, file, nempty;
FILE *output_file;
output_file=stdout;
if (nargs > 1)
if (!strcmp(args[1],"*")) {
output_file=0;
strcpy(initial_position,"");
}
else if (!(output_file=fopen(args[1],"w"))) {
printf("unable to open %s for write.\n",args[1]);
return(1);
}
if (output_file) fprintf(output_file,"setboard ");
for (rank=RANK8;rank>=RANK1;rank--) {
nempty=0;
for (file=FILEA;file<=FILEH;file++) {
if (PieceOnSquare((rank<<3)+file)) {
if (nempty) {
if (output_file)
fprintf(output_file,"%c",empty[nempty]);
else
sprintf(initial_position+strlen(initial_position),"%c",
empty[nempty]);
nempty=0;
}
if (output_file)
fprintf(output_file,"%c",xlate[PieceOnSquare((rank<<3)+file)+7]);
else
sprintf(initial_position+strlen(initial_position),"%c",
xlate[PieceOnSquare((rank<<3)+file)+7]);
}
else nempty++;
}
if (output_file)
fprintf(output_file,"/");
else
sprintf(initial_position+strlen(initial_position),"%c",'/');
}
if (output_file)
fprintf(output_file," %c ",(wtm)?'w':'b');
else
sprintf(initial_position+strlen(initial_position)," %c ", (wtm)?'w':'b');
if (WhiteCastle(0) & 1)
if (output_file)
fprintf(output_file,"K");
else
sprintf(initial_position+strlen(initial_position),"%c",'K');
if (WhiteCastle(0) & 2)
if (output_file)
fprintf(output_file,"Q");
else
sprintf(initial_position+strlen(initial_position),"%c",'Q');
if (BlackCastle(0) & 1)
if (output_file)
fprintf(output_file,"k");
else
sprintf(initial_position+strlen(initial_position),"%c",'k');
if (BlackCastle(0) & 2)
if (output_file)
fprintf(output_file,"q");
else
sprintf(initial_position+strlen(initial_position),"%c",'q');
if (EnPassant(0))
if (output_file)
fprintf(output_file," %c%c",File(EnPassant(0))+'a',
Rank(EnPassant(0))+'1');
else
sprintf(initial_position+strlen(initial_position), "%c%c",
File(EnPassant(0))+'a',
Rank(EnPassant(0))+'1');
if (output_file) fprintf(output_file,"\n");
if (output_file && output_file != stdout) {
fprintf(output_file,"exit\n");
fclose(output_file);
}
if (output_file) printf("FEN save complete.\n");
}
else if (OptionMatch("search",*args)) {
if (thinking || pondering) return(2);
if (nargs < 2) {
printf("usage:  search <move>\n");
return(1);
}
search_move=InputMove(args[1],0,wtm,0,0);
if (!search_move) search_move=InputMove(args[1],0,ChangeSide(wtm),0,0);
if (!search_move) printf("illegal move.\n");
}
else if (OptionMatch("settc",*args)) {
if (thinking || pondering) return(2);
if (nargs < 4) {
printf("usage:  settc <moves> <ctime> <otime>\n");
return(1);
}
tc_moves_remaining=atoi(args[1]);
tc_time_remaining=ParseTime(args[2])*6000;
tc_time_remaining_opponent=ParseTime(args[3])*6000;
printf("time remaining: %s (crafty).\n",
DisplayTime(tc_time_remaining));
printf("time remaining: %s (opponent).\n",
DisplayTime(tc_time_remaining_opponent));
printf("%d moves to next time control (Crafty)\n",
tc_moves_remaining);
}
else if (OptionMatch("setboard",*args)) {
if (thinking || pondering) return(2);
nargs=ReadParse(buffer,args," 	;=");
SetBoard(nargs-1,args+1,0);
ponder_move=0;
last_pv.path_iteration_depth=0;
last_pv.path_length=0;
over=0;
strcpy(buffer,"savepos *");
(void) Option();
}
else if (OptionMatch("score",*args)) {
int s1, s2=0, s3=0, s4=0, s5=0, s6;
if (thinking || pondering) return(2);
root_wtm=ChangeSide(wtm);
position[1]=position[0];
PreEvaluate(wtm);
s6=Evaluate(1,1,-99999,99999);
s1=Material;
if (opening) s2=EvaluateDevelopment(1);
if (TotalWhitePawns+TotalBlackPawns) {
s3=EvaluatePawns();
s4=EvaluatePassedPawns();
s5=EvaluatePassedPawnRaces(wtm);
}
printf("note: scores are for the white side\n");
printf("material evaluation.................%s\n",
DisplayEvaluation(s1));
printf("development.........................%s\n",
DisplayEvaluation(s2));
printf("pawn evaluation.....................%s\n",
DisplayEvaluation(s3));
printf("passed pawn evaluation..............%s\n",
DisplayEvaluation(s4));
printf("passed pawn race evaluation.........%s\n",
DisplayEvaluation(s5));
printf("interactive piece evaluation........%s\n",
DisplayEvaluation(s6-s1-s2-s3-s4-s5));
printf("total evaluation....................%s\n",
DisplayEvaluation(s6));
}
else if (OptionMatch("sd",*args)) {
if (nargs < 2) {
printf("usage:  sd <depth>\n");
return(1);
}
search_depth=atoi(args[1]);
printf("search depth set to %d.\n",search_depth);
}
else if (OptionMatch("show",*args)) {
if (nargs < 2) {
printf("usage:  show book\n");
return(1);
}
if (OptionMatch("book",args[1])) {
show_book=!show_book;
if (show_book) printf("show book statistics\n");
else printf("don't show book statistics\n");
}
}
else if (OptionMatch("SP",*args)) {
if (thinking) return(2);
return(-1);
}
else if (OptionMatch("st",*args)) {
int fract;
if (nargs < 2) {
printf("usage:  st <time>\n");
return(1);
}
search_time_limit=atoi(args[1])*100;
if (strchr(args[1],'.')) {
fract=atoi(strchr(args[1],'.')+1);
if (fract<10 && *(strchr(args[1],'.')+1) != '0') fract*=10;
search_time_limit+=fract;
}
printf("search time set to %.2f.\n",(double)search_time_limit/100.0);
}
else if (OptionMatch("surplus",*args)) {
if (nargs == 2) tc_safety_margin=atoi(args[1])*6000;
printf("time surplus set to %s.\n",DisplayTime(tc_safety_margin));
}
else if (OptionMatch("time",*args)) {
if (ics || xboard) {
tc_time_remaining=atoi(args[1]);
if (log_file && time_limit>99)
fprintf(log_file,"time remaining: %s (crafty).\n",
DisplayTime(tc_time_remaining));
}
else {
if (thinking || pondering) return(2);
if (nargs == 2) {
if (!strcmp("cpu",args[1])) {
time_type=cpu;
}
else if (!strcmp("elapsed",args[1])) {
time_type=elapsed;
}
else printf("usage:  time cpu|elapsed|<controls>\n");
}
else {
tc_moves=60;
tc_time=180000;
tc_moves_remaining=60;
tc_time_remaining=180000;
tc_time_remaining_opponent=180000;
tc_secondary_moves=60;
tc_secondary_time=180000;
tc_increment=0;
tc_sudden_death=0;
if (nargs > 1)
if (!strcmp(args[1],"sd")) {
tc_sudden_death=1;
tc_moves=1000;
}
if (nargs > 2) {
tc_moves=atoi(args[1]);
tc_time=atoi(args[2])*100;
}
tc_secondary_time=tc_time;
tc_secondary_moves=tc_moves;
if (nargs > 3)
if (!strcmp(args[3],"sd")) {
tc_sudden_death=2;
tc_secondary_moves=1000;
}
if (nargs > 4) {
tc_secondary_moves=atoi(args[3]);
tc_secondary_time=atoi(args[4])*100;
}
if (nargs > 5)
tc_increment=atoi(args[5])*100;
tc_time_remaining=tc_time;
tc_time_remaining_opponent=tc_time;
tc_moves_remaining=tc_moves;
if (!tc_sudden_death) {
printf("%d moves/%d minutes primary time control\n",
tc_moves, tc_time/100);
printf("%d moves/%d minutes secondary time control\n",
tc_secondary_moves, tc_secondary_time/100);
if (tc_increment) printf("increment %d seconds.\n",tc_increment/100);
}
else if (tc_sudden_death == 1) {
printf(" game/%d minutes primary time control\n",
tc_time/100);
if (tc_increment) printf("increment %d seconds.\n",tc_increment/100);
}
else if (tc_sudden_death == 2) {
printf("%d moves/%d minutes primary time control\n",
tc_moves, tc_time/100);
printf("game/%d minutes secondary time control\n",
tc_secondary_time/100);
if (tc_increment) printf("increment %d seconds.\n",tc_increment/100);
}
tc_time*=60;
tc_time_remaining*=60;
tc_time_remaining_opponent*=60;
tc_secondary_time*=60;
tc_safety_margin=tc_time/6;
}
}
}
else if (OptionMatch("timeleft",*args)) {
if (nargs < 3) {
printf("usage:  timeleft <wtime> <btime>\n");
return(1);
}
if (crafty_is_white) {
tc_time_remaining=atoi(args[1]);
tc_time_remaining_opponent=atoi(args[2]);
}
else {
tc_time_remaining_opponent=atoi(args[1]);
tc_time_remaining=atoi(args[2]);
}
if (log_file) {
fprintf(log_file,"time remaining: %s (crafty).\n",
DisplayTime(tc_time_remaining));
fprintf(log_file,"time remaining: %s (opponent).\n",
DisplayTime(tc_time_remaining_opponent));
}
}
else if (OptionMatch("trace",*args)) {
#if defined(FAST)
printf("Sorry, but I can't display traces when compiled with -DFAST\n");
#else
if (nargs < 2) {
printf("usage:  trace <depth>\n");
return(1);
}
trace_level=atoi(args[1]);
printf("trace=%d\n",trace_level);
#endif
}
else if (OptionMatch("tt",*args)) {
int time_used;
do {
TimeSet(think);
printf("time used? ");
fflush(stdout);
gets(buffer);
if (strlen(buffer)) time_used=atoi(buffer);
else time_used=time_limit;
TimeAdjust(time_used,opponent);
TimeAdjust(time_used,crafty);
sprintf(buffer,"clock");
Option();
move_number++;
} while (time_used >= 0);
}
else if (!strcmp("undo",*args)) {
if (thinking || pondering) return(2);
wtm=ChangeSide(wtm);
if (ChangeSide(wtm)) move_number--;
sprintf(buffer,"reset %d",move_number);
(void) Option();
}
else if (OptionMatch("usage",*args)) {
if (nargs < 2) {
printf("usage:  usage <percentage>\n");
return(1);
}
usage_level=atoi(args[1]);
if (usage_level > 50) usage_level=50;
else if (usage_level < -50) usage_level=-50;
printf("time usage up front set to %d percent increase/(-)decrease.\n",
usage_level);
}
else if (OptionMatch("verbose",*args)) {
if (nargs < 2) {
printf("usage:  verbose <level>\n");
return(1);
}
verbosity_level=atoi(args[1]);
printf("verbosity set to %d.\n",verbosity_level);
}
else if (OptionMatch("whisper",*args)) {
if (nargs < 2) {
printf("usage:  whisper <level>\n");
return(1);
}
whisper=atoi(args[1]);
}
else if (OptionMatch("wild",*args)) {
int i;
if (nargs < 2) {
printf("usage:  wild <value>\n");
return(1);
}
i=atoi(args[1]);
switch (i) {
case 7:
strcpy(buffer,"setboard 4k/5ppp/////PPP/3K/ w");
(void) Option();
break;
default:
printf("sorry, only wild7 implemented at present\n");
break;
}
}
else if (OptionMatch("white",*args)) {
if (thinking || pondering) return(2);
ponder_move=0;
last_pv.path_iteration_depth=0;
last_pv.path_length=0;
wtm=1;
force=0;
}
else if (OptionMatch("xboard",*args) || OptionMatch("winboard",*args)) {
xboard=1;
verbosity_level=0;
resign=0;
ansi=0;
}
else if (OptionMatch("?",*args)) {
}
else
return(0);
return(1);
}
int OptionMatch(char *command, char *input)
{
if (!strcmp(command,input)) return(1);
if (strstr(command,input) == command) return(1);
return(0);
}
void OptionPerft(int ply,int depth,int wtm)
{
int i, *mv;
last[ply]=GenerateCaptures(ply, wtm, last[ply-1]);
last[ply]=GenerateNonCaptures(ply, wtm, last[ply]);
for (mv=last[ply-1];mv<last[ply];mv++) {
MakeMove(ply,*mv,wtm);
if (!Check(wtm)) {
if (ply <= trace_level) {
for (i=1;i<ply;i++) printf("  ");
printf("%s\n", OutputMove(mv,ply,wtm));
}
total_moves++;
if (depth-1) OptionPerft(ply+1,depth-1,ChangeSide(wtm));
}
UnMakeMove(ply,*mv,wtm);
}
}
/* 当前文件是D:\Read\output.c*/

char* OutputMove(int *move, int ply, int wtm)
{
static char text_move[10], new_text[10];
int *mvp;
char *text;
char piece_names[8] = { ' ','P','N','K',' ','B','R','Q'};
text=text_move;
if (*move == 0) {
strcpy(text,"null");
return(text);
}
if ((Piece(*move) == king) &&
(abs(From(*move)-To(*move)) == 2)) {
if (wtm) {
if (To(*move) == 2) strcpy(text,"O-O-O");
else strcpy(text,"O-O");
}
else {
if (To(*move) == 58) strcpy(text,"O-O-O");
else strcpy(text,"O-O");
}
return(text);
}
text=new_text;
if ((int) Piece(*move) > pawn) *text++=piece_names[Piece(*move)];
*text++=(From(*move) & 7)+'a';
*text++=(From(*move) / 8)+'1';
if (Captured(*move)) *text++='x';
*text++=(To(*move) & 7)+'a';
*text++=(To(*move) / 8)+'1';
if (Promote(*move)) {
*text++='=';
*text++=piece_names[Promote(*move)];
}
position[MAXPLY]=position[ply];
MakeMove(MAXPLY, *move, wtm);
if (Check(ChangeSide(wtm))) {
mvp=GenerateCheckEvasions(1, ChangeSide(wtm), move_list+4800);
if (mvp == (move_list+4800))
*text++='#';
else
*text++='+';
}
UnMakeMove(MAXPLY, *move, wtm);
*text='\0';
if (output_format > 0) return (new_text);
if (Piece(*move) == pawn) {
if (!Captured(*move)) {
strcpy(text_move,new_text+2);
if (OutputGood(text_move,ply,wtm)) return (text_move);
}
text_move[0]=new_text[0];
strcpy(text_move+1,new_text+2);
if (OutputGood(text_move,ply,wtm)) return (text_move);
strcpy(text_move,new_text);
return (text_move);
}
if (!Captured(*move)) {
text_move[0]=new_text[0];
strcpy(text_move+1,new_text+3);
if (OutputGood(text_move,ply,wtm)) return (text_move);
text_move[0]=new_text[0];
text_move[1]=new_text[1];
strcpy(text_move+2,new_text+3);
if (OutputGood(text_move,ply,wtm)) return (text_move);
text_move[0]=new_text[0];
strcpy(text_move+1,new_text+2);
if (OutputGood(text_move,ply,wtm)) return (text_move);
strcpy(text_move,new_text);
return (text_move);
}
else {
text_move[0]=new_text[0];
strcpy(text_move+1,new_text+3);
if (OutputGood(text_move,ply,wtm)) return (text_move);
text_move[0]=new_text[0];
text_move[1]=new_text[1];
strcpy(text_move+2,new_text+3);
if (OutputGood(text_move,ply,wtm)) return (text_move);
text_move[0]=new_text[0];
strcpy(text_move+1,new_text+2);
if (OutputGood(text_move,ply,wtm)) return (text_move);
strcpy(text_move,new_text);
return (text_move);
}
}
char* OutputMoveICS(int *move)
{
static char text_move[10];
char *text;
char piece_names[8] = { ' ','P','N','K',' ','B','R','Q'};
text=text_move;
*text++=(From(*move) & 7)+'a';
*text++=(From(*move) / 8)+'1';
*text++=(To(*move) & 7)+'a';
*text++=(To(*move) / 8)+'1';
if (Promote(*move))
*text++=piece_names[Promote(*move)];
*text='\0';
return (text_move);
}
int OutputGood(char* text, int ply, int wtm)
{
int new_move;
new_move=InputMove(text,ply,wtm,1,0);
return (Piece(new_move));
}
/* 当前文件是D:\Read\phase.c*/

void Phase(void)
{
int t_opening, t_middle_game, t_end_game;
t_opening=opening;
t_middle_game=middle_game;
t_end_game=end_game;
if (opening) {
do {
if (move_number < 26) {
if (root_wtm) {
if (WhiteCastle(1)>0) break;
if (And(WhiteBishops,white_minor_pieces)) break;
if (And(WhiteKnights,white_minor_pieces)) break;
}
else {
if (BlackCastle(1)>0) break;
if (And(BlackBishops,black_minor_pieces)) break;
if (And(BlackKnights,black_minor_pieces)) break;
}
}
opening=0;
middle_game=1;
end_game=0;
} while (0);
}
if (TotalWhitePieces < 14 && TotalBlackPieces < 14) {
opening=0;
middle_game=0;
end_game=1;
}
if (opening && opening != t_opening)
printf("opening phase\n");
else if (middle_game && middle_game != t_middle_game)
printf("middle-game phase\n");
else if (end_game != t_end_game)
printf("end-game phase\n");
}
/* 当前文件是D:\Read\ponder.c*/

int Ponder(int wtm)
{
int dummy=0, i, *n_ponder_moves, *mv;
if (!ponder || force || over || CheckInput()) return(0);
strcpy(hint,"none");
if (!ponder_move) {
(void) LookUp(0,0,wtm,&dummy,&dummy);
if (hash_move[0]) ponder_move=hash_move[0];
}
if (!ponder_move) {
TimeSet(puzzle);
if (time_limit < 3) return(0);
puzzling=1;
position[1]=position[0];
printf("              puzzling over a move to ponder.\n");
last_pv.path_length=0;
last_pv.path_iteration_depth=0;
for (i=0;i<MAXPLY;i++) {
killer_move1[i]=0;
killer_move2[i]=0;
killer_count1[i]=0;
killer_count2[i]=0;
}
(void) Iterate(wtm,puzzle,0);
for (i=0;i<MAXPLY;i++) {
killer_move1[i]=0;
killer_move2[i]=0;
killer_count1[i]=0;
killer_count2[i]=0;
}
puzzling=0;
if (pv[0].path_length) ponder_move=pv[0].path[1];
if (!ponder_move) return(0);
for (i=1;i<(int) pv[0].path_length-1;i++) last_pv.path[i]=pv[0].path[i+1];
last_pv.path_length=pv[0].path_length-1;
last_pv.path_iteration_depth=0;
if (!ValidMove(1,wtm,ponder_move)) {
ponder_move=0;
return(0);
}
}
if (wtm)
printf("White(%d): %s [pondering]\n",
move_number,OutputMove(&ponder_move,0,wtm));
else
printf("Black(%d): %s [pondering]\n",
move_number,OutputMove(&ponder_move,0,wtm));
sprintf(hint,"%s",OutputMove(&ponder_move,0,wtm));
if (post) printf("Hint: %s\n",hint);
n_ponder_moves=GenerateCaptures(0, wtm, ponder_moves);
num_ponder_moves=GenerateNonCaptures(0, wtm, n_ponder_moves)-ponder_moves;
for (mv=ponder_moves;mv<ponder_moves+num_ponder_moves;mv++) {
MakeMove(0, *mv, wtm);
if (Check(wtm)) {
UnMakeMove(0, *mv, wtm);
*mv=0;
}
else UnMakeMove(0, *mv, wtm);
}
MakeMove(0,ponder_move,wtm);
if (Rule50Moves(1)==90 || Rule50Moves(1)==91) ClearHashTables();
last_opponent_move=ponder_move;
if (ChangeSide(wtm))
*rephead_w++=HashKey;
else
*rephead_b++=HashKey;
if (RepetitionDraw(wtm)) printf("game is a draw by repetition\n");
if (whisper) strcpy(whisper_text,"n/a");
thinking=0;
pondering=1;
(void) Iterate(ChangeSide(wtm),think,0);
pondering=0;
thinking=0;
if (ChangeSide(wtm))
rephead_w--;
else
rephead_b--;
last_opponent_move=0;
UnMakeMove(0,ponder_move,wtm);
if (made_predicted_move) return(1);
if (abort_search) return(3);
return(2);
}
/* 当前文件是D:\Read\preeval.c*/

void PreEvaluate(int wtm)
{
int i, j;
static int hashing_pawns = 0;
static int hashing_opening = 0;
static int hashing_middle_game = 0;
static int hashing_end_game = 0;
static int last_wtm = 0;
int hash_pawns=0;
Phase();
if (opening) {
hash_pawns=1;
pawn_advance[0]=PAWN_ADVANCE_BC_A;
pawn_advance[1]=PAWN_ADVANCE_BC_B;
pawn_advance[2]=PAWN_ADVANCE_BC_C;
pawn_advance[3]=PAWN_ADVANCE_BC_D;
pawn_advance[4]=PAWN_ADVANCE_BC_E;
pawn_advance[5]=PAWN_ADVANCE_BC_F;
pawn_advance[6]=PAWN_ADVANCE_BC_G;
pawn_advance[7]=PAWN_ADVANCE_BC_H;
}
else if (middle_game) {
hash_pawns=2;
pawn_advance[0]=PAWN_ADVANCE_A;
pawn_advance[1]=PAWN_ADVANCE_B;
pawn_advance[2]=PAWN_ADVANCE_C;
pawn_advance[3]=PAWN_ADVANCE_D;
pawn_advance[4]=PAWN_ADVANCE_E;
pawn_advance[5]=PAWN_ADVANCE_F;
pawn_advance[6]=PAWN_ADVANCE_G;
pawn_advance[7]=PAWN_ADVANCE_H;
}
else {
hash_pawns=3;
pawn_advance[0]=PAWN_ADVANCE_EG_A;
pawn_advance[1]=PAWN_ADVANCE_EG_B;
pawn_advance[2]=PAWN_ADVANCE_EG_C;
pawn_advance[3]=PAWN_ADVANCE_EG_D;
pawn_advance[4]=PAWN_ADVANCE_EG_E;
pawn_advance[5]=PAWN_ADVANCE_EG_F;
pawn_advance[6]=PAWN_ADVANCE_EG_G;
pawn_advance[7]=PAWN_ADVANCE_EG_H;
}
for (i=0;i<8;i++)
for (j=0;j<8;j++)
pawn_value_w[i*8+j]=pawn_advance[j]*(((i-1)>0) ? i-1 : 0);
if (!end_game) {
pawn_value_w[C5]+=CENTER_PAWNS;
pawn_value_w[C6]+=CENTER_PAWNS;
pawn_value_w[E4]+=CENTER_PAWNS;
pawn_value_w[E5]+=CENTER_PAWNS;
pawn_value_w[E6]+=CENTER_PAWNS;
pawn_value_w[D4]+=CENTER_PAWNS;
pawn_value_w[D5]+=CENTER_PAWNS;
pawn_value_w[D6]+=CENTER_PAWNS;
pawn_value_w[F5]+=CENTER_PAWNS;
pawn_value_w[F6]+=CENTER_PAWNS;
}
for (i=7;i>=0;i--)
for (j=0;j<8;j++)
pawn_value_b[i*8+j]=pawn_advance[j]*(((6-i)>0) ? 6-i : 0);
if (!end_game) {
pawn_value_b[C3]+=CENTER_PAWNS;
pawn_value_b[C4]+=CENTER_PAWNS;
pawn_value_b[E3]+=CENTER_PAWNS;
pawn_value_b[E4]+=CENTER_PAWNS;
pawn_value_b[E5]+=CENTER_PAWNS;
pawn_value_b[D3]+=CENTER_PAWNS;
pawn_value_b[D4]+=CENTER_PAWNS;
pawn_value_b[D5]+=CENTER_PAWNS;
pawn_value_b[F3]+=CENTER_PAWNS;
pawn_value_b[F4]+=CENTER_PAWNS;
}
if (((last_wtm            != wtm) ||
(hashing_pawns       != hash_pawns) ||
(hashing_opening     != opening) ||
(hashing_middle_game != middle_game) ||
(hashing_end_game    != end_game)) && !test_mode) {
printf("\n              clearing hash tables\n");
ClearHashTables();
}
hashing_pawns=hash_pawns;
hashing_opening=opening;
hashing_middle_game=middle_game;
hashing_end_game=end_game;
last_wtm=wtm;
}
/* 当前文件是D:\Read\quiesce.c*/

int Quiesce(int alpha, int beta, int wtm, int ply)
{
register int initial_alpha, value, delta;
register int *next_move;
register int *goodmv, *movep, moves=0, *sortv, temp;
if (ply >= MAXPLY-2) return(beta);
nodes_searched++;
next_time_check--;
last[ply]=last[ply-1];
initial_alpha=alpha;
value=Evaluate(ply,wtm,alpha,beta);
if (value > alpha) {
if (value >= beta) return(value);
alpha=value;
pv[ply].path_length=ply-1;
pv[ply].path_hashed=0;
pv[ply].path_iteration_depth=iteration_depth;
}
last[ply]=GenerateCaptures(ply, wtm, last[ply-1]);
delta=alpha-500-(wtm?Material:-Material);
goodmv=last[ply-1];
sortv=sort_value;
for (movep=last[ply-1];movep<last[ply];movep++)
if (p_values[Captured(*movep)+7]+p_values[Promote(*movep)+7] >= delta) {
if (Captured(*movep) == king) return(beta);
if (p_values[Piece(*movep)+7] < p_values[Captured(*movep)+7] ||
(p_values[Piece(*movep)+7] <= p_values[Captured(*movep)+7] &&
delta<=0)) {
*goodmv++=*movep;
*sortv++=p_values[Captured(*movep)+7];
moves++;
}
else {
temp=Swap(From(*movep),To(*movep),wtm);
if (temp >= 0) {
*sortv++=temp;
*goodmv++=*movep;
moves++;
}
}
}
if (moves > 1) {
register int done;
register int *end=last[ply-1]+moves-1;
do {
done=1;
sortv=sort_value;
movep=last[ply-1];
for (;movep<end;movep++,sortv++)
if (*sortv < *(sortv+1)) {
temp=*sortv;
*sortv=*(sortv+1);
*(sortv+1)=temp;
temp=*movep;
*movep=*(movep+1);
*(movep+1)=temp;
done=0;
}
} while(!done);
}
next_move=last[ply-1];
while (moves--) {
current_move[ply]=*(next_move++);
#if !defined(FAST)
if (ply <= trace_level)
SearchTrace(ply,0,wtm,alpha,beta,"quiesce",CAPTURE_MOVES);
#endif
MakeMove(ply,current_move[ply],wtm);
value=-Quiesce(-beta,-alpha,ChangeSide(wtm),ply+1);
UnMakeMove(ply,current_move[ply],wtm);
if (value > alpha) {
if(value >= beta) return(value);
alpha=value;
}
}
if (alpha != initial_alpha) {
memcpy(&pv[ply-1].path[ply],&pv[ply].path[ply],
(pv[ply].path_length-ply+1)*sizeof(int));
memcpy(&pv[ply-1].path_hashed,&pv[ply].path_hashed,3);
pv[ply-1].path[ply-1]=current_move[ply-1];
}
return(alpha);
}
/* 当前文件是D:\Read\repeat.c*/

int RepetitionCheck(int ply, int wtm)
{
register int entries;
register BITBOARD *replist, *thispos;
if (!(TotalWhitePawns+TotalBlackPawns) &&
TotalWhitePieces<5 && TotalBlackPieces<5) return(1);
entries=Rule50Moves(ply)>>1;
thispos=((wtm)?rephead_w:rephead_b)+((ply-1)>>1);
*thispos=HashKey;
for (replist=thispos-1;entries;replist--,entries--)
if(*thispos == *replist) return(1);
return(0);
}
int RepetitionDraw(int wtm)
{
register int reps;
BITBOARD *thispos;
if (Rule50Moves(0) > 99) return(2);
reps=0;
if (wtm) {
for (thispos=replist_w;thispos<rephead_w;thispos++)
if(HashKey == *thispos) reps++;
}
else {
for (thispos=replist_b;thispos<rephead_b;thispos++)
if(HashKey == *thispos) reps++;
}
return(reps == 3);
}
/* 当前文件是D:\Read\resign.c*/

void ResignOrDraw(int value, int wtm)
{
int returnv=0;
if (RepetitionDraw(ChangeSide(wtm)) || Drawn(value)) returnv=2;
if ((tc_increment > 200) || (tc_time_remaining_opponent >= 3000)) {
if (resign) {
if (value < -(MATE-15)) {
if (++resign_counter >= resign_count) returnv=1;
}
else if (value<-resign*100 && value>-(MATE-100)) {
if (++resign_counter >= resign_count) returnv=1;
}
else resign_counter=0;
}
}
if ((tc_increment > 200) || (tc_time_remaining_opponent >= 3000)) {
if (value==DrawScore() && moves_out_of_book>3) {
if (++draw_counter >= draw_count) {
draw_counter=0;
returnv=3;
}
}
else draw_counter=0;
}
if (returnv == 1) {
if (!ics && !xboard) printf("\nCrafty resigns.\n\n");
else if (xboard) {
printf("tellics resign\n");
if (crafty_is_white) printf("Black wins - Crafty resigns.\n");
else printf("White wins - Crafty resigns.\n");
}
else printf("\n*resign\n");
}
if (returnv >= 2) {
if (!ics && !xboard) printf("\nCrafty offers a draw.\n\n");
else if (xboard) {
printf("tellics draw\n");
if (xboard && returnv==2) printf("Draw\n");
}
else printf("\n*draw\n");
}
}
/* 当前文件是D:\Read\root.c*/

void RootMoveList(int wtm)
{
int *mvp, tempm;
int square, side, i, done, temp, value;
easy_move=0;
last[1]=GenerateCaptures(1, wtm, last[0]);
last[1]=GenerateNonCaptures(1, wtm, last[1]);
if (last[1] == last[0]+1) return;
for (mvp=last[0];mvp<last[1];mvp++) {
value=-4000000;
MakeMove(1, *mvp, wtm);
if (!Check(wtm)) {
current_move[1]=*mvp;
value=-Evaluate(2,ChangeSide(wtm),-99999,99999);
side=(wtm) ? 1 : -1;
for (square=0;square<64;square++)
if (PieceOnSquare(square)*side > 0)
value-=Max(EnPrise(square,ChangeSide(wtm)),0);
if((Piece(*mvp)    == Piece(last_pv.path[1])) &&
(From(*mvp)     == From(last_pv.path[1])) &&
(To(*mvp)       == To(last_pv.path[1])) &&
(Captured(*mvp) == Captured(last_pv.path[1])) &&
(Promote(*mvp)  == Promote(last_pv.path[1]))) {
value+=2000000;
}
if (Promote(*mvp) && (Promote(*mvp) != queen)) value-=50;
}
sort_value[mvp-last[0]]=value;
UnMakeMove(1, *mvp, wtm);
}
do {
done=1;
for (i=0;i<last[1]-last[0]-1;i++) {
if (sort_value[i] < sort_value[i+1]) {
temp=sort_value[i];
sort_value[i]=sort_value[i+1];
sort_value[i+1]=temp;
tempm=*(last[0]+i);
*(last[0]+i)=*(last[0]+i+1);
*(last[0]+i+1)=tempm;
done=0;
}
}
} while(!done);
for (;last[1]>last[0];last[1]--)
if (sort_value[last[1]-last[0]-1] > -3000000) break;
if (sort_value[0] > 1000000) sort_value[0]-=2000000;
if (sort_value[0] > sort_value[1]+2000 &&
((To(*last[0]) == To(last_opponent_move) &&
Captured(*last[0]) == Piece(last_opponent_move)) ||
sort_value[0] < PAWN_VALUE)) easy_move=1;
if (trace_level > 0) {
printf("produced %ld moves at root\n",last[1]-last[0]);
for (mvp=last[0];mvp<last[1];mvp++) {
current_move[1]=*mvp;
printf("%s",OutputMove(mvp,1,wtm));
MakeMove(1, *mvp, wtm);
printf("/%d/%d  ",sort_value[mvp-last[0]],
-Evaluate(2,ChangeSide(wtm),-99999,99999));
if (!((mvp-last[0]+1) % 5)) printf("\n");
UnMakeMove(1, *mvp, wtm);
}
}
return;
}
/* 当前文件是D:\Read\search.c*/

int Search(int alpha, int beta, int wtm, int depth, int ply, int do_null)
{
register int first_move=1, threat=0;
register BITBOARD save_hash_key;
register int initial_alpha, value;
register int extensions, pieces;
if (ply >= MAXPLY-2) return(beta);
nodes_searched++;
if (--next_time_check <= 0) {
next_time_check=nodes_between_time_checks;
if (CheckInput()) Interrupt(ply);
time_abort+=TimeCheck(0);
if (time_abort) {
abort_search=1;
return(0);
}
}
if (RepetitionCheck(ply,wtm)) {
value=(wtm==root_wtm) ? DrawScore() : -DrawScore();
if (value < beta) SavePV(ply,value,0);
#if !defined(FAST)
if(ply <= trace_level) printf("draw by repetition detected, ply=%d.\n",ply);
#endif
return(value);
}
switch (LookUp(ply,depth,wtm,&alpha,&beta)) {
case EXACT_SCORE:
if(alpha < beta) SavePV(ply,alpha,1);
return(alpha);
case LOWER_BOUND:
return(beta);
case UPPER_BOUND:
return(alpha);
case AVOID_NULL_MOVE:
do_null=0;
}
in_check[ply+1]=0;
extended_reason[ply+1]=no_extension;
initial_alpha=alpha;
last[ply]=last[ply-1];
killer_count1[ply+1]=0;
killer_count2[ply+1]=0;
# if defined(NULL_MOVE_DEPTH)
pieces=(wtm) ? TotalWhitePieces : TotalBlackPieces;
if (do_null && !in_check[ply] && pieces &&
(pieces>5 || depth<421)) {
current_move[ply]=0;
current_phase[ply]=NULL_MOVE;
#if !defined(FAST)
if (ply <= trace_level)
SearchTrace(ply,depth,wtm,alpha,beta,"Search",0);
#endif
position[ply+1]=position[ply];
Rule50Moves(ply+1)++;
save_hash_key=HashKey;
if (EnPassant(ply)) {
HashEP(EnPassant(ply+1),HashKey);
EnPassant(ply+1)=0;
}
value=-ABSearch(-beta,-alpha,ChangeSide(wtm),
depth-NULL_MOVE_DEPTH-INCREMENT_PLY,ply+1,NO_NULL);
HashKey=save_hash_key;
if (abort_search) return(0);
if (value >= beta) {
StoreRefutation(ply,depth,wtm,value);
return(value);
}
if (value == MATE-ply-2) threat=1;
}
# endif
next_status[ply].phase=FIRST_PHASE;
if (hash_move[ply]==0 && (depth > 2*INCREMENT_PLY) &&
(((ply & 1) && alpha == root_alpha && beta == root_beta) ||
(!(ply & 1) && alpha == -root_beta && beta == -root_alpha))) {
current_move[ply]=0;
value=ABSearch(alpha,beta,wtm,depth-2*INCREMENT_PLY,ply,DO_NULL);
if (abort_search) return(0);
if (value <= alpha) {
value=ABSearch(-MATE,beta,wtm,depth-2*INCREMENT_PLY,ply,DO_NULL);
if (abort_search) return(0);
}
else if (value < beta) {
if ((int) pv[ply-1].path_length >= ply) hash_move[ply]=pv[ply-1].path[ply];
}
else hash_move[ply]=current_move[ply];
last[ply]=last[ply-1];
next_status[ply].phase=FIRST_PHASE;
}
while ((current_phase[ply]=(in_check[ply]) ? NextEvasion(ply,wtm) :
NextMove(ply,wtm))) {
extended_reason[ply]&=check_extension;
#if !defined(FAST)
if (ply <= trace_level) SearchTrace(ply,depth,wtm,alpha,beta,"Search",current_phase[ply]);
#endif
extensions=(threat) ? 0 : -INCREMENT_PLY;
if (Captured(current_move[ply]) && Captured(current_move[ply-1]) &&
To(current_move[ply-1]) == To(current_move[ply]) &&
(p_values[Captured(current_move[ply-1])+7] ==
p_values[Captured(current_move[ply])+7] ||
Promote(current_move[ply-1])) &&
!(extended_reason[ply-1]&recapture_extension)) {
if (extensions < 0) {
extended_reason[ply]|=recapture_extension;
recapture_extensions_done++;
extensions=0;
}
}
if (Piece(current_move[ply])==pawn &&
((wtm && To(current_move[ply])>H5 && TotalBlackPieces<16 &&
!And(mask_pawn_passed_w[To(current_move[ply])],BlackPawns)) ||
(!wtm && To(current_move[ply])<A4 && TotalWhitePieces<16 &&
!And(mask_pawn_passed_b[To(current_move[ply])],WhitePawns)) ||
push_extensions[To(current_move[ply])]) &&
Swap(From(current_move[ply]),To(current_move[ply]),wtm) ==
p_values[Captured(current_move[ply])+7]) {
if (extensions < 0) {
extended_reason[ply]|=passed_pawn_extension;
passed_pawn_extensions_done++;
extensions=0;
}
}
MakeMove(ply,current_move[ply],wtm);
if (in_check[ply] || !Check(wtm)) {
if (Check(ChangeSide(wtm))) {
in_check[ply+1]=1;
extended_reason[ply+1]=check_extension;
if (extensions < 0) {
check_extensions_done++;
extensions=0;
}
}
else {
in_check[ply+1]=0;
extended_reason[ply+1]=no_extension;
}
if (depth<3*INCREMENT_PLY && depth>=2*INCREMENT_PLY &&
!in_check[ply] && extensions == -INCREMENT_PLY &&
ply <= iteration_depth) {
register int value=-Evaluate(ply+1,ChangeSide(wtm),-(beta+501),-(alpha-501));
if (value+50 < alpha) extensions-=60;
}
if (first_move) {
if (last[ply]-last[ply-1] == 1) {
extended_reason[ply]|=one_reply_extension;
one_reply_extensions_done++;
if (extensions < 0) extensions+=ONE_REPLY_TO_CHECK;
}
value=-ABSearch(-beta,-alpha,ChangeSide(wtm),
depth+extensions,ply+1,DO_NULL);
if (abort_search) {
UnMakeMove(ply,current_move[ply],wtm);
return(0);
}
first_move=0;
}
else {
value=-ABSearch(-alpha-1,-alpha,ChangeSide(wtm),
depth+extensions,ply+1,DO_NULL);
if (abort_search) {
UnMakeMove(ply,current_move[ply],wtm);
return(0);
}
if (value>alpha && value<beta) {
value=-ABSearch(-beta,-alpha,ChangeSide(wtm),
depth+extensions,ply+1,DO_NULL);
if (abort_search) {
UnMakeMove(ply,current_move[ply],wtm);
return(0);
}
}
}
if (value > alpha) {
if(value >= beta) {
HistoryRefutation(ply,depth,wtm);
UnMakeMove(ply,current_move[ply],wtm);
StoreRefutation(ply,depth,wtm,value);
return(value);
}
alpha=value;
}
}
UnMakeMove(ply,current_move[ply],wtm);
}
if (first_move == 1) {
value=(Check(wtm)) ? -(MATE-ply) :
((wtm==root_wtm) ? DrawScore() : -DrawScore());
if (value >=alpha && value <beta) {
SavePV(ply,value,0);
#if !defined(FAST)
if (ply <= trace_level) printf("Search() no moves!  ply=%d\n",ply);
#endif
}
return(value);
}
else {
if (alpha != initial_alpha) {
memcpy(&pv[ply-1].path[ply],&pv[ply].path[ply],(pv[ply].path_length-ply+1)*4);
memcpy(&pv[ply-1].path_hashed,&pv[ply].path_hashed,3);
pv[ply-1].path[ply-1]=current_move[ply-1];
HistoryBest(ply,depth,wtm);
}
StoreBest(ply,depth,wtm,alpha,initial_alpha);
if (Rule50Moves(ply) >= 99) {
value=(wtm==root_wtm) ? DrawScore() : -DrawScore();
if (value < beta) SavePV(ply,value,0);
#if !defined(FAST)
if(ply <= trace_level) printf("draw by 50-move rule detected, ply=%d.\n",ply);
#endif
return(value);
}
return(alpha);
}
}
/* 当前文件是D:\Read\searchr.c*/

int SearchRoot(int alpha, int beta, int wtm, int depth)
{
register int first_move=1;
register int initial_alpha, value;
register int extensions, begin_root_nodes;
in_check[2]=0;
extended_reason[2]=no_extension;
initial_alpha=alpha;
RepetitionCheck(1,wtm);
in_check[1]=Check(wtm);
next_status[1].phase=ROOT_MOVES;
killer_count1[2]=0;
killer_count2[2]=0;
while ((current_phase[1]=NextRootMove(wtm))) {
extended_reason[1]=0;
#if !defined(FAST)
if (1 <= trace_level)
SearchTrace(1,depth,wtm,alpha,beta,"SearchRoot",current_phase[1]);
#endif
extensions=-INCREMENT_PLY;
if (Piece(current_move[1])==pawn &&
((wtm && To(current_move[1]) > H5 && TotalBlackPieces<16 &&
!And(mask_pawn_passed_w[To(current_move[1])],BlackPawns)) ||
(!wtm && To(current_move[1]) < A4 && TotalWhitePieces<16 &&
!And(mask_pawn_passed_b[To(current_move[1])],WhitePawns)) ||
push_extensions[To(current_move[1])]) &&
Swap(From(current_move[1]),To(current_move[1]),wtm) >= 0) {
extended_reason[1]|=passed_pawn_extension;
passed_pawn_extensions_done++;
extensions=0;
}
MakeMove(1,current_move[1],wtm);
if (Check(ChangeSide(wtm))) {
in_check[2]=1;
if (extensions < 0) {
extended_reason[2]=check_extension;
check_extensions_done++;
extensions=0;
}
}
else {
in_check[2]=0;
extended_reason[2]=no_extension;
}
begin_root_nodes=nodes_searched;
if (first_move) {
value=-ABSearch(-beta,-alpha,ChangeSide(wtm),
depth+extensions,2,DO_NULL);
if (abort_search) {
UnMakeMove(1,current_move[1],wtm);
return(alpha);
}
first_move=0;
}
else {
value=-ABSearch(-alpha-1,-alpha,ChangeSide(wtm),
depth+extensions,2,DO_NULL);
if (abort_search) {
UnMakeMove(1,current_move[1],wtm);
return(alpha);
}
if ((value > alpha) && (value < beta)) {
value=-ABSearch(-beta,-alpha,ChangeSide(wtm),
depth+extensions,2,DO_NULL);
if (abort_search) {
UnMakeMove(1,current_move[1],wtm);
return(alpha);
}
}
}
root_nodes[root_move]=nodes_searched-begin_root_nodes;
if (value > alpha) {
SearchOutput(value,beta);
if(value >= beta) {
HistoryRefutation(1,depth,wtm);
UnMakeMove(1,current_move[1],wtm);
StoreRefutation(1,depth,wtm,value);
return(value);
}
alpha=value;
root_value=alpha;
}
UnMakeMove(1,current_move[1],wtm);
}
if (first_move == 1) {
value=(Check(wtm)) ? -(MATE-1) :
((wtm==root_wtm) ? DrawScore() : -DrawScore());
if (value >=alpha && value <beta) {
SavePVS(1,value,0);
#if !defined(FAST)
if (1 <= trace_level) printf("Search() no moves!  ply=1\n");
#endif
}
return(value);
}
else {
if (alpha != initial_alpha) {
memcpy(&pv[0].path[1],&pv[1].path[1],(pv[1].path_length)*4);
memcpy(&pv[0].path_hashed,&pv[1].path_hashed,3);
pv[0].path[0]=current_move[0];
HistoryBest(1,depth,wtm);
}
StoreBest(1,depth,wtm,alpha,initial_alpha);
return(alpha);
}
}
void SearchOutput(int value, int bound)
{
#define PrintOK() (nodes_searched>noise_level || value>(MATE-100))
char buffer[500], *buffp, *bufftemp;
register int *mv, *mvp;
register int i, j, wtm;
int dummy=0, temp_root_nodes;
wtm=root_wtm;
if (!abort_search) {
whisper_value=(analyze_mode && !root_wtm) ? -value : value;
whisper_depth=iteration_depth;
for (mvp=last[0];mvp<last[1];mvp++) if(current_move[1]== *mvp) break;
if (mvp != last[0]) {
temp_root_nodes=root_nodes[mvp-last[0]];
for (mv=mvp;mv>last[0];mv--) {
*mv=*(mv-1);
root_nodes[mv-last[0]]=root_nodes[mv-1-last[0]];
}
root_nodes[0]=temp_root_nodes;
*last[0]=current_move[1];
easy_move=0;
}
end_time=GetTime(time_type);
if(value < bound) {
buffer[0]=0;
UnMakeMove(1,pv[1].path[1],root_wtm);
for (i=1;i<=(int) pv[1].path_length;i++) {
sprintf(buffer+strlen(buffer)," %s",OutputMove(&pv[1].path[i],i,wtm));
MakeMove(i,pv[1].path[i],wtm);
wtm=ChangeSide(wtm);
}
if(pv[1].path_hashed == 1) {
for (i=pv[1].path_length+1;i<=MAXPLY;i++) {
LookUp(i,0,wtm,&dummy,&dummy);
if (hash_move[i] && ValidMove(i,wtm,hash_move[i])) {
pv[1].path[i]=hash_move[i];
for (j=1;j<i;j++)
if (pv[1].path[i] == pv[1].path[j]) break;
if (j < i) break;
pv[1].path_length++;
sprintf(buffer+strlen(buffer)," %s",OutputMove(&pv[1].path[i],i,wtm));
MakeMove(i,pv[1].path[i],wtm);
}
else break;
wtm=ChangeSide(wtm);
}
sprintf(buffer+strlen(buffer)," <HT>");
}
else if(pv[1].path_hashed == 2)
sprintf(buffer+strlen(buffer)," <EGTB>");
strcpy(whisper_text,buffer);
if (PrintOK()) {
printf("               %2i   %s%s   ",iteration_depth,
DisplayTime(end_time-start_time),DisplayEvaluation(value));
buffp=buffer+1;
do {
if ((int) strlen(buffp) > 34)
bufftemp=strchr(buffp+34,' ');
else
bufftemp=0;
if (bufftemp) *bufftemp=0;
printf("%s\n",buffp);
buffp=bufftemp+1;
if (bufftemp) printf("                                    ");
} while(bufftemp);
Whisper(6,iteration_depth,end_time-start_time,whisper_value,
nodes_searched,0,whisper_text);
}
for (i=pv[1].path_length;i>1;i--) {
wtm=ChangeSide(wtm);
UnMakeMove(i,pv[1].path[i],wtm);
}
}
else {
if (PrintOK()) {
printf("               %2i   %s     ++   ",iteration_depth,
DisplayTime(end_time-start_time));
UnMakeMove(1,current_move[1],wtm);
printf("%s!!\n",OutputMove(&current_move[1],1,wtm));
sprintf(whisper_text," %s!!",OutputMove(&current_move[1],1,wtm));
MakeMove(1,current_move[1],wtm);
Whisper(6,iteration_depth,end_time-start_time,whisper_value,
nodes_searched,-1,whisper_text);
}
if (current_move[1] != pv[1].path[1]) {
pv[1].path[1]=current_move[1];
pv[1].path_length=1;
pv[1].path_hashed=0;
pv[1].path_iteration_depth=iteration_depth;
}
}
}
}
void SearchTrace(int ply, int depth, int wtm, int alpha, int beta, char* name,
int phase)
{
int i;
for (i=1;i<ply;i++) printf("  ");
printf("%d  %s d:%5.2f [%s,",ply,OutputMove(&current_move[ply],ply,wtm),
(double) depth/ (double) INCREMENT_PLY,DisplayEvaluation(alpha));
printf("%s] n:%d %s(%d)\n", DisplayEvaluation(beta),
(nodes_searched),name,phase);
}
/* 当前文件是D:\Read\setboard.c*/

void SetBoard(int nargs, char *args[], int special)
{
int twtm, i, match, num, pos, square, tboard[64];
int bcastle, ep, wcastle;
char input[80];
char bdinfo[] = {'q','r','b','*','k','n','p','*','P','N','K','*','B','R',
'Q','*', '1','2','3','4','5','6','7','8','/'};
char status[13]={'K','Q','k','q','a','b','c','d','e','f','g','h',' '};
int whichsq, firstsq[8]={56,48,40,32,24,16,8,0};
if (special)
strcpy(input,initial_position);
else
strcpy(input,args[0]);
for (i=0;i<64;i++) tboard[i]=0;
whichsq=0;
square=firstsq[whichsq];
num=0;
for (pos=0;pos<(int) strlen(args[0]);pos++) {
for (match=0;match<25 && args[0][pos]!=bdinfo[match];match++);
if (match > 24) break;
else if (match == 24) {
num=0;
	
	  whichsq++;
	  if (whichsq > 7) break ;
square=firstsq[whichsq];
}
else if (match >= 16) {
num+=match-15;
square+=match-15;
if (num > 8) {
printf("more than 8 squares on one rank\n");
return;
}
continue;
}
else {
if (++num > 8) {
printf("more than 8 squares on one rank\n");
return;
}
tboard[square++]=match-7;
}
}
twtm=0;
ep=0;
wcastle=0;
bcastle=0;
if (args[1][0] == 'w') twtm=1;
else if (args[1][0] == 'b') twtm=0;
else printf("side to move is bad\n");
if (nargs>2 && strlen(args[2])) {
if (args[2][0]>='a' && args[2][0]<='h' &&
args[2][1]>'0' && args[2][1]<'9') {
ep=(args[2][1]-'1')*8+args[2][0]-'a';
pos++;
}
else for (pos=0;pos<(int) strlen(args[2]);pos++) {
for (match=0;(match<13) && (args[2][pos]!=status[match]);match++);
if (match == 0) wcastle+=1;
else if (match == 1) wcastle+=2;
else if (match == 2) bcastle+=1;
else if (match == 3) bcastle+=2;
else printf("castling status is bad.\n");
}
}
if (nargs>3 && strlen(args[3])) {
if (args[3][0]>='a' && args[3][0]<='h' &&
args[3][1]>'0' && args[3][1]<'9') {
ep=(args[3][1]-'1')*8+args[3][0]-'a';
pos++;
}
else printf("enpassant status is bad.\n");
}
for (i=0;i<64;i++) PieceOnSquare(i)=tboard[i];
WhiteCastle(0)=wcastle;
BlackCastle(0)=bcastle;
EnPassant(0)=ep;
if (((WhiteCastle(0) & 2) && (PieceOnSquare(A1) != rook)) ||
((WhiteCastle(0) & 1) && (PieceOnSquare(H1) != rook)) ||
((BlackCastle(0) & 2) && (PieceOnSquare(A8) != -rook)) ||
((BlackCastle(0) & 1) && (PieceOnSquare(H8) != -rook))) {
printf("ERROR-- castling status does not match board position\n");
InitializeChessBoard(&position[0]);
}
if ((twtm && EnPassant(0) && (PieceOnSquare(EnPassant(0)+8) != -pawn) &&
(PieceOnSquare(EnPassant(0)-7) != pawn) &&
(PieceOnSquare(EnPassant(0)-9) != pawn)) ||
(ChangeSide(twtm) && EnPassant(0) && (PieceOnSquare(EnPassant(0)-8) != pawn) &&
(PieceOnSquare(EnPassant(0)+7) != -pawn) &&
(PieceOnSquare(EnPassant(0)+9) != -pawn))) {
EnPassant(0)=0;
}
SetChessBitBoards(&position[0]);
if (log_file) DisplayChessBoard(log_file,search);
if (!special) {
rephead_b=replist_b;
rephead_w=replist_w;
if (twtm) *rephead_w++=HashKey;
else *rephead_b++=HashKey;
position[0].rule_50_moves=0;
last_mate_score=0;
for (i=0;i<4096;i++) {
history_w[i]=0;
history_b[i]=0;
}
for (i=0;i<MAXPLY;i++) {
killer_move1[i]=0;
killer_move2[i]=0;
killer_count1[i]=0;
killer_count2[i]=0;
}
last_pv.path_iteration_depth=0;
last_pv.path_length=0;
pv[0].path_iteration_depth=0;
pv[0].path_length=0;
moves_out_of_book=0;
largest_positional_score=60;
opening=0;
middle_game=1;
end_game=0;
wtm=twtm;
}
}
/* 当前文件是D:\Read\store.c*/

void StoreBest(int ply, int depth, int wtm, int value, int alpha)
{
register HASH_ENTRY *htablea, *htableb;
register BITBOARD word1, word2;
register int draft, age;
if (value > alpha) {
if (abs(value) < MATE-100) word1=Shiftl((BITBOARD) (value+65536),21);
else if (value > 0) word1=Shiftl((BITBOARD) (value+ply-1+65536),21);
else word1=Shiftl((BITBOARD) (value-ply+1+65536),21);
word1=Or(word1,Shiftl((BITBOARD) ((transposition_id<<2)+EXACT_SCORE),59));
if ((int) pv[ply].path_length >= ply)
word1=Or(word1,(BITBOARD) pv[ply].path[ply]);
}
else {
word1=Shiftl((BITBOARD) (value+65536),21);
word1=Or(word1,Shiftl((BITBOARD) ((transposition_id<<2)+UPPER_BOUND),59));
}
word2=Or(HashKey>>16,Shiftl((BITBOARD) depth,48));
if (wtm) {
htablea=trans_ref_wa+(((int) HashKey) & hash_maska);
htableb=trans_ref_wb+(((int) HashKey) & hash_maskb);
}
else {
htablea=trans_ref_ba+(((int) HashKey) & hash_maska);
htableb=trans_ref_bb+(((int) HashKey) & hash_maskb);
}
draft=(int) Shiftr(htablea->word2,48);
age=(unsigned int) Shiftr(htablea->word1,61);
age=age && (age!=transposition_id);
if (age || (depth >= draft)) {
htableb->word1=htablea->word1;
htableb->word2=htablea->word2;
htablea->word1=word1;
htablea->word2=word2;
}
else {
htableb->word1=word1;
htableb->word2=word2;
}
}
void StorePV(int ply, int wtm)
{
register BITBOARD temp_hash_key;
register HASH_ENTRY *htable;
if (!ValidMove(ply,wtm,pv[ply].path[ply])) {
printf("\ninstalling bogus move...ply=%d\n",ply);
printf("installing %s\n",OutputMove(&pv[ply].path[ply],ply,wtm));
return;
}
temp_hash_key=HashKey;
htable=((wtm) ? trans_ref_wb : trans_ref_bb)+(((int) temp_hash_key)&hash_maskb);
temp_hash_key=temp_hash_key>>16;
htable->word1=Shiftl((BITBOARD) 65536,21);
htable->word1=Or(htable->word1,Shiftl((BITBOARD) ((transposition_id<<2)+WORTHLESS),59));
htable->word1=Or(htable->word1,(BITBOARD) pv[ply].path[ply]);
htable->word2=temp_hash_key;
}
void StoreRefutation(int ply, int depth, int wtm, int bound)
{
register HASH_ENTRY *htablea, *htableb;
register BITBOARD word1, word2;
register int draft, age;
word1=Shiftl((BITBOARD) (bound+65536),21);
word1=Or(word1,Shiftl((BITBOARD) ((transposition_id<<2)+LOWER_BOUND),59));
word1=Or(word1,(BITBOARD) current_move[ply]);
word2=Or(HashKey>>16,Shiftl((BITBOARD) depth,48));
if (wtm) {
htablea=trans_ref_wa+(((int) HashKey) & hash_maska);
htableb=trans_ref_wb+(((int) HashKey) & hash_maskb);
}
else {
htablea=trans_ref_ba+(((int) HashKey) & hash_maska);
htableb=trans_ref_bb+(((int) HashKey) & hash_maskb);
}
draft=(int) Shiftr(htablea->word2,48);
age=(unsigned int) Shiftr(htablea->word1,61);
age=age && (age!=transposition_id);
if (age || (depth >= draft)) {
htableb->word1=htablea->word1;
htableb->word2=htablea->word2;
htablea->word1=word1;
htablea->word2=word2;
}
else {
htableb->word1=word1;
htableb->word2=word2;
}
}
/* 当前文件是D:\Read\swap.c*/

int Swap(int source, int target, int wtm)
{
register BITBOARD attacks;
register int attacked_piece;
register int square, direction;
register int sign, color, next_capture=1;
int swap_list[32];
attacks=AttacksTo(target);
attacked_piece=p_values[PieceOnSquare(target)+7];
color=ChangeSide(wtm);
swap_list[0]=attacked_piece;
sign=-1;
attacked_piece=p_values[PieceOnSquare(source)+7];
Clear(source,attacks);
direction=directions[target][source];
if (direction) attacks=SwapXray(attacks,source,direction);
while (attacks) {
if (color) {
if (And(WhitePawns,attacks))
square=FirstOne(And(WhitePawns,attacks));
else if (And(WhiteKnights,attacks))
square=FirstOne(And(WhiteKnights,attacks));
else if (And(WhiteBishops,attacks))
square=FirstOne(And(WhiteBishops,attacks));
else if (And(WhiteRooks,attacks))
square=FirstOne(And(WhiteRooks,attacks));
else if (And(WhiteQueens,attacks))
square=FirstOne(And(WhiteQueens,attacks));
else if (And(WhiteKing,attacks))
square=WhiteKingSQ;
else break;
}
else {
if (And(BlackPawns,attacks))
square=FirstOne(And(BlackPawns,attacks));
else if (And(BlackKnights,attacks))
square=FirstOne(And(BlackKnights,attacks));
else if (And(BlackBishops,attacks))
square=FirstOne(And(BlackBishops,attacks));
else if (And(BlackRooks,attacks))
square=FirstOne(And(BlackRooks,attacks));
else if (And(BlackQueens,attacks))
square=FirstOne(And(BlackQueens,attacks));
else if (And(BlackKing,attacks))
square=BlackKingSQ;
else break;
}
swap_list[next_capture]=swap_list[next_capture-1]+sign*attacked_piece;
attacked_piece=p_values[PieceOnSquare(square)+7];
Clear(square,attacks);
direction=directions[target][square];
if (direction) attacks=SwapXray(attacks,square,direction);
next_capture++;
sign=-sign;
color=ChangeSide(color);
}
next_capture--;
if(next_capture&1) sign=-1;
else sign=1;
while (next_capture) {
if (sign < 0) {
if(swap_list[next_capture] <= swap_list[next_capture-1])
swap_list[next_capture-1]=swap_list[next_capture];
}
else {
if(swap_list[next_capture] >= swap_list[next_capture-1])
swap_list[next_capture-1]=swap_list[next_capture];
}
next_capture--;
sign=-sign;
}
return (swap_list[0]);
}
BITBOARD SwapXray(BITBOARD attacks, int from, int direction)
{
switch (direction) {
case 1:
return(Or(attacks,
And(And(AttacksRank(from),RooksQueens),plus1dir[from])));
case 7:
return(Or(attacks,
And(And(AttacksDiaga1(from),BishopsQueens),plus7dir[from])));
case 8:
return(Or(attacks,
And(And(AttacksFile(from),RooksQueens),plus8dir[from])));
case 9:
return(Or(attacks,
And(And(AttacksDiagh1(from),BishopsQueens),plus9dir[from])));
case -1:
return(Or(attacks,
And(And(AttacksRank(from),RooksQueens),minus1dir[from])));
case -7:
return(Or(attacks,
And(And(AttacksDiaga1(from),BishopsQueens),minus7dir[from])));
case -8:
return(Or(attacks,
And(And(AttacksFile(from),RooksQueens),minus8dir[from])));
case -9:
return(Or(attacks,
And(And(AttacksDiagh1(from),BishopsQueens),minus9dir[from])));
}
return(attacks);
}
/* 当前文件是D:\Read\time.c*/

void TimeAdjust(int time_used, PLAYER player)
{
if (player == crafty) {
tc_moves_remaining--;
tc_time_remaining-=(tc_time_remaining > time_used) ?
time_used : tc_time_remaining;
if (!tc_moves_remaining) {
if (tc_sudden_death == 2) tc_sudden_death=1;
tc_moves_remaining+=tc_secondary_moves;
tc_time_remaining+=tc_secondary_time;
tc_time_remaining_opponent+=tc_secondary_time;
printf("time control reached\n");
}
if (tc_increment) tc_time_remaining+=tc_increment;
}
else {
tc_time_remaining_opponent-=(tc_time_remaining_opponent > time_used) ?
time_used : tc_time_remaining_opponent;
if (tc_increment) tc_time_remaining_opponent+=tc_increment;
}
}
int TimeCheck(int abort)
{
int time_used;
int value, last_value, searched;
int *i, ndone;
if (last[0]==(last[1]-1) && !pondering && !booking) return(1);
ndone=0;
for (i=last[0];i<last[1];i++)
if (searched_this_root_move[i-last[0]]) ndone++;
if (ndone == 1) abort=1;
if (iteration_depth <= 2) return(0);
time_used=(GetTime(time_type)-start_time);
if (search_depth || pondering || analyze_mode) return(0);
if (time_used > absolute_time_limit) return(1);
if (easy_move && !search_time_limit) {
if (time_limit>100 && time_used<time_limit/3) return (0);
}
else if (time_used < time_limit) return(0);
if (search_time_limit) return(1);
if ((root_value == root_alpha) && !search_failed_low) {
searched=0;
for (i=last[0];i<last[1];i++)
if (searched_this_root_move[i-last[0]]) searched++;
if (searched == 1) return(1);
}
value=root_value;
last_value=last_search_value;
if ((value>=last_value-33 && !search_failed_low) ||
(value>350 && value >= last_value-67)) {
if (time_used > time_limit*2) return(1);
else return(abort);
}
if (time_used < time_limit*2.5 && time_used+500<tc_time_remaining) return(0);
if ((value >= last_value-67 && !search_failed_low) ||
value>550) return(abort);
if (time_used < time_limit*6 && time_used+500<tc_time_remaining) return(0);
return(1);
}
void TimeSet(int search_type)
{
double behind[6] = {32.0, 16.0, 8.0, 4.0, 2.0, 1.5};
int reduce[6] = {96, 48, 24, 12, 6, 3};
int i;
int surplus, average;
int simple_average;
surplus=0;
average=0;
if (tc_sudden_death == 1) {
if (tc_increment) {
time_limit=(tc_time_remaining-tc_operator_time*tc_moves_remaining)/25+
tc_increment;
if (tc_time_remaining < 3000) time_limit=tc_increment;
if (tc_time_remaining < 1500) time_limit=tc_increment/2;
absolute_time_limit=tc_time_remaining/2;
}
else {
time_limit=tc_time_remaining/30;
absolute_time_limit=Min(time_limit*6,tc_time_remaining/2);
}
}
else {
if (move_number <= tc_moves)
simple_average=(tc_time-(tc_operator_time*tc_moves_remaining))/tc_moves;
else
simple_average=(tc_secondary_time-(tc_operator_time*tc_moves_remaining))/
tc_secondary_moves;
surplus=Max(tc_time_remaining-(tc_operator_time*tc_moves_remaining)-
simple_average*tc_moves_remaining,0);
average=(tc_time_remaining-(tc_operator_time*tc_moves_remaining)+
tc_moves_remaining*tc_increment)
/tc_moves_remaining;
if (surplus < tc_safety_margin)
time_limit = (average<simple_average) ? average : simple_average;
else
time_limit=(average<2.0*simple_average) ? average : 2.0*simple_average;
}
if (surplus < 0) surplus=0;
if (tc_increment>200 && moves_out_of_book<2) time_limit*=1.2;
if (time_limit <= 0) time_limit=5;
absolute_time_limit=time_limit+surplus/2+((tc_time_remaining-
tc_operator_time*tc_moves_remaining)/4);
if (absolute_time_limit > 6*time_limit) absolute_time_limit=6*time_limit;
if (absolute_time_limit > tc_time_remaining/2)
absolute_time_limit=tc_time_remaining/2;
if (usage_level)  time_limit*=1.0+usage_level/100.0;
if (mode!=tournament_mode && !tc_increment) {
for (i=0;i<6;i++) {
if ((double)tc_time_remaining*behind[i] <
(double)tc_time_remaining_opponent) {
time_limit=time_limit/reduce[i];
printf("crafty is behind %4.1f on time, reducing by 1/%d.\n",
behind[i],reduce[i]);
break;
}
}
if (tc_increment==0 && tc_time_remaining_opponent>tc_time_remaining) {
if (tc_time_remaining < 3000) time_limit/=2;
if (tc_time_remaining < 2000) time_limit/=2;
if (tc_time_remaining < 1000) time_limit=1;
}
}
if (search_time_limit) {
time_limit=search_time_limit;
absolute_time_limit=time_limit;
}
if (search_type==puzzle || booking) {
time_limit/=10;
absolute_time_limit=time_limit*3;
}
if (!tc_sudden_death && !search_time_limit && time_limit>3*tc_time/tc_moves)
time_limit=3*tc_time/tc_moves;
if (time_limit <= 1) {
time_limit= 1;
usage_level=0;
}
}
/* 当前文件是D:\Read\unmake.c*/

static BITBOARD bit_move;
void UnMakeMove(int ply, int move, int wtm)
{
register int piece, from, to, captured, promote;
HashKey=save_hash_key[ply];
PawnHashKey=save_pawn_hash_key[ply];
piece=Piece(move);
from=From(move);
to=To(move);
captured=Captured(move);
promote=Promote(move);
UnMakePieceMove:
SetRL90(from,OccupiedRL90);
SetRL45(from,OccupiedRL45);
SetRR45(from,OccupiedRR45);
ClearRL90(to,OccupiedRL90);
ClearRL45(to,OccupiedRL45);
ClearRR45(to,OccupiedRR45);
bit_move=Or(set_mask[from],set_mask[to]);
PieceOnSquare(to)=0;
switch (piece) {
case pawn:
if (wtm) {
ClearSet(bit_move,WhitePawns);
ClearSet(bit_move,WhitePieces);
PieceOnSquare(from)=pawn;
if (captured == 1) {
if(EnPassant(ply) == to) {
TotalPieces++;
SetRL90(to-8,OccupiedRL90);
SetRL45(to-8,OccupiedRL45);
SetRR45(to-8,OccupiedRR45);
Set(to-8,BlackPawns);
Set(to-8,BlackPieces);
PieceOnSquare(to-8)=-pawn;
Material-=PAWN_VALUE;
TotalBlackPawns++;
captured=0;
}
}
if (promote) {
TotalWhitePawns++;
Material+=PAWN_VALUE;
Clear(to,WhitePawns);
Clear(to,WhitePieces);
switch (promote) {
case knight:
Clear(to,WhiteKnights);
TotalWhitePieces-=knight_v;
Material-=KNIGHT_VALUE;
break;
case bishop:
Clear(to,WhiteBishops);
Clear(to,BishopsQueens);
TotalWhitePieces-=bishop_v;
Material-=BISHOP_VALUE;
break;
case rook:
Clear(to,WhiteRooks);
Clear(to,RooksQueens);
TotalWhitePieces-=rook_v;
Material-=ROOK_VALUE;
break;
case queen:
Clear(to,WhiteQueens);
Clear(to,BishopsQueens);
Clear(to,RooksQueens);
TotalWhitePieces-=queen_v;
Material-=QUEEN_VALUE;
break;
}
}
}
else {
ClearSet(bit_move,BlackPawns);
ClearSet(bit_move,BlackPieces);
PieceOnSquare(from)=-pawn;
if (captured == 1) {
if(EnPassant(ply) == to) {
TotalPieces++;
SetRL90(to+8,OccupiedRL90);
SetRL45(to+8,OccupiedRL45);
SetRR45(to+8,OccupiedRR45);
Set(to+8,WhitePawns);
Set(to+8,WhitePieces);
PieceOnSquare(to+8)=pawn;
Material+=PAWN_VALUE;
TotalWhitePawns++;
captured=0;
}
}
if (promote) {
TotalBlackPawns++;
Material-=PAWN_VALUE;
Clear(to,BlackPawns);
Clear(to,BlackPieces);
switch (promote) {
case knight:
Clear(to,BlackKnights);
TotalBlackPieces-=knight_v;
Material+=KNIGHT_VALUE;
break;
case bishop:
Clear(to,BlackBishops);
Clear(to,BishopsQueens);
TotalBlackPieces-=bishop_v;
Material+=BISHOP_VALUE;
break;
case rook:
Clear(to,BlackRooks);
Clear(to,RooksQueens);
TotalBlackPieces-=rook_v;
Material+=ROOK_VALUE;
break;
case queen:
Clear(to,BlackQueens);
Clear(to,BishopsQueens);
Clear(to,RooksQueens);
TotalBlackPieces-=queen_v;
Material+=QUEEN_VALUE;
break;
}
}
}
break;
case knight:
if (wtm) {
ClearSet(bit_move,WhiteKnights);
ClearSet(bit_move,WhitePieces);
PieceOnSquare(from)=knight;
}
else {
ClearSet(bit_move,BlackKnights);
ClearSet(bit_move,BlackPieces);
PieceOnSquare(from)=-knight;
}
break;
case bishop:
ClearSet(bit_move,BishopsQueens);
if (wtm) {
ClearSet(bit_move,WhiteBishops);
ClearSet(bit_move,WhitePieces);
PieceOnSquare(from)=bishop;
}
else {
ClearSet(bit_move,BlackBishops);
ClearSet(bit_move,BlackPieces);
PieceOnSquare(from)=-bishop;
}
break;
case rook:
ClearSet(bit_move,RooksQueens);
if (wtm) {
ClearSet(bit_move,WhiteRooks);
ClearSet(bit_move,WhitePieces);
PieceOnSquare(from)=rook;
}
else {
ClearSet(bit_move,BlackRooks);
ClearSet(bit_move,BlackPieces);
PieceOnSquare(from)=-rook;
}
break;
case queen:
ClearSet(bit_move,BishopsQueens);
ClearSet(bit_move,RooksQueens);
if (wtm) {
ClearSet(bit_move,WhiteQueens);
ClearSet(bit_move,WhitePieces);
PieceOnSquare(from)=queen;
}
else {
ClearSet(bit_move,BlackQueens);
ClearSet(bit_move,BlackPieces);
PieceOnSquare(from)=-queen;
}
break;
case king:
if (wtm) {
ClearSet(bit_move,WhitePieces);
PieceOnSquare(from)=king;
WhiteKingSQ=from;
if (abs(to-from) == 2) {
if (to == 6) {
from=H1;
to=F1;
piece=rook;
goto UnMakePieceMove;
}
else {
from=A1;
to=D1;
piece=rook;
goto UnMakePieceMove;
}
}
}
else {
ClearSet(bit_move,BlackPieces);
PieceOnSquare(from)=-king;
BlackKingSQ=from;
if (abs(to-from) == 2) {
if (to == 62) {
from=H8;
to=F8;
piece=rook;
goto UnMakePieceMove;
}
else {
from=A8;
to=D8;
piece=rook;
goto UnMakePieceMove;
}
}
}
break;
}
if(captured) {
TotalPieces++;
SetRL90(to,OccupiedRL90);
SetRL45(to,OccupiedRL45);
SetRR45(to,OccupiedRR45);
switch (captured) {
case pawn:
if (wtm) {
Set(to,BlackPawns);
Set(to,BlackPieces);
PieceOnSquare(to)=-pawn;
Material-=PAWN_VALUE;
TotalBlackPawns++;
}
else {
Set(to,WhitePawns);
Set(to,WhitePieces);
PieceOnSquare(to)=pawn;
Material+=PAWN_VALUE;
TotalWhitePawns++;
}
break;
case knight:
if (wtm) {
Set(to,BlackKnights);
Set(to,BlackPieces);
PieceOnSquare(to)=-knight;
TotalBlackPieces+=knight_v;
Material-=KNIGHT_VALUE;
}
else {
Set(to,WhiteKnights);
Set(to,WhitePieces);
PieceOnSquare(to)=knight;
TotalWhitePieces+=knight_v;
Material+=KNIGHT_VALUE;
}
break;
case bishop:
Set(to,BishopsQueens);
if (wtm) {
Set(to,BlackBishops);
Set(to,BlackPieces);
PieceOnSquare(to)=-bishop;
TotalBlackPieces+=bishop_v;
Material-=BISHOP_VALUE;
}
else {
Set(to,WhiteBishops);
Set(to,WhitePieces);
PieceOnSquare(to)=bishop;
TotalWhitePieces+=bishop_v;
Material+=BISHOP_VALUE;
}
break;
case rook:
Set(to,RooksQueens);
if (wtm) {
Set(to,BlackRooks);
Set(to,BlackPieces);
PieceOnSquare(to)=-rook;
TotalBlackPieces+=rook_v;
Material-=ROOK_VALUE;
}
else {
Set(to,WhiteRooks);
Set(to,WhitePieces);
PieceOnSquare(to)=rook;
TotalWhitePieces+=rook_v;
Material+=ROOK_VALUE;
}
break;
case queen:
Set(to,BishopsQueens);
Set(to,RooksQueens);
if (wtm) {
Set(to,BlackQueens);
Set(to,BlackPieces);
PieceOnSquare(to)=-queen;
TotalBlackPieces+=queen_v;
Material-=QUEEN_VALUE;
}
else {
Set(to,WhiteQueens);
Set(to,WhitePieces);
PieceOnSquare(to)=queen;
TotalWhitePieces+=queen_v;
Material+=QUEEN_VALUE;
}
break;
case king:
printf("captured a king\n");
printf("piece=%d,from=%d,to=%d,captured=%d\n",
piece,from,to,captured);
printf("ply=%d\n",ply);
if (log_file) DisplayChessBoard(log_file,search);
}
}
#if defined(DEBUG)
ValidatePosition(ply,move,"UnMakeMove(2)");
#endif
return;
}
/* 当前文件是D:\Read\utility.c*/

#if !defined(AMIGA)
#  include <limits.h>
#endif
#if defined(NT_i386) || defined(NT_AXP)
#  include <windows.h>
#  include <winbase.h>
//#  include <wincon.h>
#  include <io.h>
#else
//#  include <sys/times.h>
//#  include <sys/time.h>
#endif
#if defined(UNIX)
#  include <unistd.h>
#  include <sys/types.h>
#  if !defined(LINUX) && !defined(ALPHA) && !defined(HP) && !defined(CRAY1) && !defined(FreeBSD)
#    if defined(AIX)
#      include <sys/termio.h>
#      include <sys/select.h>
#    else
#      if defined(NEXT)
#        include <bsd/termios.h>
#        include <sys/ioctl.h>
#      else
#        include <sys/filio.h>
#      endif
#    endif
#    if !defined(NEXT)
#      include <stropts.h>
#    endif
#    include <sys/conf.h>
#  else
#    include <sys/ioctl.h>
#  endif
#endif
#if defined(UNIX)
#  if !defined(CLK_TCK)
static clock_t clk_tck = 0;
#  endif
#endif
#if defined(AMIGA)
#  include <proto/dos.h>
#  define tv_sec tv_secs
#  define tv_usec tv_micro
#  include <exec/types.h>
#  define RAW 1
#  define CON 0
#  include <limits.h>
int _kbhit(void)
{
BPTR  inp;
BOOLEAN  ret;
inp=Input();
if(!IsInteractive(inp)) return FALSE;
Flush(inp);
(void) SetMode(inp,RAW);
ret=WaitForChar(inp,1);
(void) SetMode(inp,CON);
return ret;
}
#endif
# if defined(NT_i386) || defined(NT_AXP)
#  include <windows.h>
#  include <conio.h>
int CheckInput(void)
{
int i;
static int init = 0, pipe;
static HANDLE inh;
DWORD dw;
if (!xboard && !ics && !isatty(fileno(stdin))) return(0);
if (batch_mode) return(0);
if (strchr(cmd_buffer,'\n')) return(1);
if (xboard) {
#if defined(FILE_CNT)
if (stdin->_cnt > 0) return stdin->_cnt;
#endif
if (!init) {
init = 1;
inh = GetStdHandle(STD_INPUT_HANDLE);
pipe = !GetConsoleMode(inh, &dw);
if (!pipe) {
SetConsoleMode(inh, dw & ~(ENABLE_MOUSE_INPUT|ENABLE_WINDOW_INPUT));
FlushConsoleInputBuffer(inh);
}
}
if (pipe) {
if (!PeekNamedPipe(inh, NULL, 0, NULL, &dw, NULL)) {
return 1;
}
return dw;
} else {
GetNumberOfConsoleInputEvents(inh, &dw);
return dw <= 1 ? 0 : dw;
}
}
else {
i=_kbhit();
}
return(i);
}
#endif
#if defined(DOS)
int CheckInput(void)
{
int i;
if (!xboard && !ics && !isatty(fileno(stdin))) return(0);
if (batch_mode) return(0);
if (strchr(cmd_buffer,'\n')) return(1);
i=bioskey(1);
return(i);
}
#endif
#if defined(UNIX)
int CheckInput(void) {
fd_set readfds;
struct timeval tv;
int data;
if (!xboard && !ics && !isatty(fileno(stdin))) return(0);
if (batch_mode) return(0);
if (strchr(cmd_buffer,'\n')) return(1);
FD_ZERO (&readfds);
FD_SET (fileno(stdin), &readfds);
tv.tv_sec=0;
tv.tv_usec=0;
select(16, &readfds, 0, 0, &tv);
data=FD_ISSET(fileno(stdin), &readfds);
return(data);
}
#endif
void Delay(int ms)
{
int old,new;
old=GetTime(elapsed);
do {
new=GetTime(elapsed);
} while (new-ms/10 < old);
}
void ClearHashTables(void)
{
int i;
if (trans_ref_ba && trans_ref_wa) {
for (i=0;i<hash_table_size;i++) {
(trans_ref_ba+i)->word1=Or(And((trans_ref_ba+i)->word1,
			      mask_clear_entry),Shiftl((BITBOARD) 65536,21));
	      (trans_ref_wa+i)->word1=Or(And((trans_ref_wa+i)->word1,
			      mask_clear_entry),Shiftl((BITBOARD) 65536,21));
}
for (i=0;i<2*hash_table_size;i++) {
(trans_ref_bb+i)->word1=Or(And((trans_ref_bb+i)->word1,
mask_clear_entry),Shiftl((BITBOARD) 65536,21));
(trans_ref_wb+i)->word1=Or(And((trans_ref_wb+i)->word1,
mask_clear_entry),Shiftl((BITBOARD) 65536,21));
}
}
}
void DisplayBitBoard(BITBOARD board)
{
union doub {
char i[8];
BITBOARD d;
};
union doub x;
int i,j;
#if defined(LITTLE_ENDIAN_ARCH) && defined(HAS_LONGLONG)
int subs[8]={7,6,5,4,3,2,1,0};
#endif
#if defined(LITTLE_ENDIAN_ARCH) && !defined(HAS_LONGLONG)
int subs[8]={3,2,1,0,7,6,5,4};
#endif
x.d=board;
#if defined(LITTLE_ENDIAN_ARCH)
for(i=7;i>=0;i--) {
printf("  %2d ",i*8);
for(j=128;j>0;j=j>>1)
if(x.i[subs[i]] & j)
printf("X ");
else
printf("- ");
printf("\n");
}
#else
for(i=7;i>=0;i--) {
printf("  %2d ",i*8);
for(j=128;j>0;j=j>>1)
if(x.i[i] & j)
printf("X ");
else
printf("- ");
printf("\n");
}
#endif
}
void DisplayChessBoard(FILE *display_file, CHESS_POSITION pos)
{
int display_board[64];
char display_string[] =
{"*Q\0*R\0*B\0  \0*K\0*N\0*P\0  \0P \0N \0K \0  \0B \0R \0Q \0"};
int i,j;
for(i=0;i<64;i++) display_board[i]=(pos.board[i]+7)*3;
fprintf(display_file,"\n       +---+---+---+---+---+---+---+---+\n");
for(i=7;i>=0;i--) {
fprintf(display_file,"   %2d  ",i+1);
for(j=0;j<8;j++)
fprintf(display_file,"| %s",&display_string[display_board[i*8+j]]);
fprintf(display_file,"|\n");
fprintf(display_file,"       +---+---+---+---+---+---+---+---+\n");
}
fprintf(display_file,"         a   b   c   d   e   f   g   h\n\n");
}
char* DisplayEvaluation(int value)
{
static char out[10];
if (abs(value) < MATE-100)
sprintf(out,"%7.2f",((double) value)/100.0);
else if (abs(value) > MATE) {
if (value < 0) sprintf(out," -infnty");
else sprintf(out," +infnty");
}
else if (value == MATE-2) sprintf(out,"   Mate");
else if (value == -(MATE-1)) sprintf(out,"  -Mate");
else if (value > 0) sprintf(out,"  Mat%.2d",(MATE-value)/2);
else sprintf(out," -Mat%.2d",(MATE-abs(value))/2);
return(out);
}
char* DisplayEvaluationWhisper(int value)
{
static char out[10];
if (abs(value) < MATE-100)
sprintf(out,"%+.2f",((double) value)/100.0);
else if (abs(value) > MATE) {
if (value < 0) sprintf(out,"-infnty");
else sprintf(out,"+infnty");
}
else if (value == MATE-2) sprintf(out,"Mate");
else if (value == -(MATE-1)) sprintf(out,"-Mate");
else if (value > 0) sprintf(out,"Mat%.2d",(MATE-value)/2);
else sprintf(out,"-Mat%.2d",(MATE-abs(value))/2);
return(out);
}
void DisplayPieceBoards(int *white, int *black)
{
int i,j;
printf("                 white                      ");
printf("                 black\n");
for (i=7;i>=0;i--) {
for (j=i*8;j<i*8+8;j++) printf("%4d ",white[j]);
printf("    ");
for (j=i*8;j<i*8+8;j++) printf("%4d ",black[j]);
printf("\n");
}
}
char* DisplayHHMM(unsigned int time)
{
static char out[10];
time=time/6000;
sprintf(out,"###.##");
return(out);
}
char* DisplayTime(unsigned int time)
{
static char out[10];
if (time < 6000) {
sprintf(out,"###.##");
} else {
time=time/100;
sprintf(out,"###.##");
}
return(out);
}
char* DisplayTimeWhisper(unsigned int time)
{
static char out[10];
if (time < 6000) sprintf(out,"%.2f",(double) time/100.0);
else {
time=time/100;
sprintf(out,"#:##");
}
return(out);
}
void Display64bitWord(BITBOARD word)
{
union doub {
unsigned int i[2];
BITBOARD d;
};
union doub x;
x.d=word;
#if defined(LITTLE_ENDIAN_ARCH)
printf("%08x%08x\n",x.i[1],x.i[0]);
#else
printf("%08x%08x\n",x.i[0],x.i[1]);
#endif
}
void Display2BitBoards(BITBOARD board1, BITBOARD board2)
{
union doub {
char i[8];
BITBOARD d;
};
union doub x,y;
int i,j;
#if defined(LITTLE_ENDIAN_ARCH) && defined(HAS_LONGLONG)
int subs[8]={7,6,5,4,3,2,1,0};
#endif
#if defined(LITTLE_ENDIAN_ARCH) && !defined(HAS_LONGLONG)
int subs[8]={3,2,1,0,7,6,5,4};
#endif
x.d=board1;
y.d=board2;
printf("          good                     bad\n");
#if defined(LITTLE_ENDIAN_ARCH)
for(i=7;i>=0;i--) {
printf("  %2d ",i*8);
for(j=128;j>0;j=j>>1)
if(x.i[subs[i]] & j) printf("X ");
else printf("- ");
printf("     %2d ",i*8);
for(j=128;j>0;j=j>>1)
if(y.i[subs[i]] & j) printf("X ");
else printf("- ");
printf("\n");
}
#else
for(i=7;i>=0;i--) {
printf("  %2d ",i*8);
for(j=128;j>0;j=j>>1)
if(x.i[i] & j) printf("X ");
else printf("- ");
printf("     %2d ",i*8);
for(j=128;j>0;j=j>>1)
if(y.i[i] & j) printf("X ");
else printf("- ");
printf("\n");
}
#endif
}
void DisplayChessMove(char *title, int move)
{
printf("%s  piece=%d, from=%d, to=%d, captured=%d, promote=%d\n",
title,Piece(move),From(move), To(move),Captured(move),
Promote(move));
}
unsigned int GetTime(TIME_TYPE type)
{
#ifdef SPEC_CPU2000
return 0;
}
#else
#if defined(UNIX) || defined(AMIGA)
static struct tms t;
static struct timeval timeval;
static struct timezone timezone;
#endif
switch (type) {
case cpu:
#if defined(UNIX) || defined(AMIGA)
(void) times(&t);
#  if defined(CLK_TCK)
return((t.tms_utime+t.tms_stime)*100/CLK_TCK);
#  else
if (!clk_tck) clk_tck = sysconf(_SC_CLK_TCK);
return((t.tms_utime+t.tms_stime)*100/clk_tck);
#  endif
case elapsed:
gettimeofday(&timeval, &timezone);
return(timeval.tv_sec*100+(timeval.tv_usec / 10000L));
default:
gettimeofday(&timeval, &timezone);
return(timeval.tv_usec);
#endif
//#if defined(NT_i386) || defined(NT_AXP)
case elapsed:
return( (unsigned int) GetTickCount()/10);
default:
return( (unsigned int) GetTickCount()/10);
//#endif
//#if defined(DOS)
case elapsed:
return(time(0)*100);
default:
return(time(0)*100);
//#endif
}
}
#endif
int HasOpposition(int on_move, int white_king, int black_king)
{
register int file_distance, rank_distance;
file_distance=FileDistance(white_king,black_king);
rank_distance=RankDistance(white_king,black_king);
if (rank_distance < 2) return(1);
if (on_move) {
if (rank_distance > 2) rank_distance--;
else file_distance--;
}
if ((file_distance == 2) && (rank_distance == 2)) return(1);
if ((file_distance == 0) && (rank_distance == 2)) return(1);
return(0);
}
BITBOARD InterposeSquares(int check_direction, int king_square,
int checking_square)
{
register BITBOARD target;
switch (check_direction) {
case +1:
target=Xor(plus1dir[king_square-1],plus1dir[checking_square]);
break;
case +7:
target=Xor(plus7dir[king_square-7],plus7dir[checking_square]);
break;
case +8:
target=Xor(plus8dir[king_square-8],plus8dir[checking_square]);
break;
case +9:
target=Xor(plus9dir[king_square-9],plus9dir[checking_square]);
break;
case -1:
target=Xor(minus1dir[king_square+1],minus1dir[checking_square]);
break;
case -7:
target=Xor(minus7dir[king_square+7],minus7dir[checking_square]);
break;
case -8:
target=Xor(minus8dir[king_square+8],minus8dir[checking_square]);
break;
case -9:
target=Xor(minus9dir[king_square+9],minus9dir[checking_square]);
break;
default:
target=0;
break;
}
return(target);
}
int KingPawnSquare(int pawn, int king, int queen, int ptm)
{
register int pdist, kdist;
pdist=abs((pawn>>3)-(queen>>3));
kdist=(abs((king>>3)-(queen>>3)) > abs((king&7)-(queen&7))) ?
abs((king>>3)-(queen>>3)) : abs((king&7)-(queen&7));
if (!ptm) pdist++;
if (pdist < kdist) return(0);
else return(1);
}
void NewGame(int save) {
char filename[64];
static int save_book_selection_width=5, save_book_random=2;
static int save_whisper=0, save_kibitz=0, save_channel=0;
static int save_resign=0, save_resign_count=0, save_draw_count=0;
static int save_learning=0;
new_game=0;
if (save) {
save_book_selection_width=book_selection_width;
save_book_random=book_random;
save_whisper=whisper;
save_kibitz=kibitz;
save_channel=channel;
save_resign=resign;
save_resign_count=resign_count;
save_draw_count=draw_count;
save_learning=learning;
}
else {
over=0;
moves_out_of_book=0;
ponder_move=0;
previous_search_value=0;
last_pv.path_iteration_depth=0;
last_pv.path_length=0;
strcpy(initial_position,"");
InitializeChessBoard(&position[0]);
InitializeHashTables();
force=0;
wtm=1;
move_number=1;
tc_time_remaining=tc_time;
tc_time_remaining_opponent=tc_time;
tc_moves_remaining=tc_moves;
if (history_file) fclose(history_file);
history_file=fopen("game.001","w+");
book_selection_width=save_book_selection_width;
book_random=save_book_random;
whisper=save_whisper;
kibitz=save_kibitz;
channel=save_channel;
resign=save_resign;
resign_count=save_resign_count;
resign_counter=0;
draw_count=save_draw_count;
draw_counter=0;
usage_level=0;
learning=save_learning;
largest_positional_score=60;
predicted=0;
whisper_depth=0;
whisper_value=0;
nodes_searched=0;
cpu_percent=0;
whisper_text[0]=0;
}
}
char* Normal(void)
{
#if defined(NT_i386) || defined(NT_AXP)
HANDLE  std_console;
std_console = GetStdHandle(STD_OUTPUT_HANDLE);
#endif
if (ansi) {
#if defined(UNIX) || defined(AMIGA)
return("\033[0m");
#elif defined(NT_i386) || defined(NT_AXP)
SetConsoleTextAttribute(std_console, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
return("");
#else
return("\033[1;44;37m");
#endif
}
return("");
}
int ParseTime(char* string)
{
int time=0;
int minutes=0;
while (*string) {
switch (*string) {
case '0':
case '1':
case '2':
case '3':
case '4':
case '5':
case '6':
case '7':
case '8':
case '9':
minutes=minutes*10+(*string)-'0';
break;
case ':':
time=time*60+minutes;
minutes=0;
break;
default: printf("illegal character in time, please re-enter\n");
break;
}
string++;
}
return(time*60+minutes);
}
int PinnedOnKing(int wtm, int square)
{
register int ray;
if (wtm) {
ray=directions[square][WhiteKingSQ];
if (!ray) return(0);
switch (abs(ray)) {
case 1:
if (And(AttacksRank(square),WhiteKing) != 0)
return(And(And(AttacksRank(square),RooksQueens),
BlackPieces) != 0);
else return(0);
case 7:
if (And(AttacksDiaga1(square),WhiteKing) != 0)
return(And(And(AttacksDiaga1(square),BishopsQueens),
BlackPieces) != 0);
else return(0);
case 8:
if (And(AttacksFile(square),WhiteKing) != 0)
return(And(And(AttacksFile(square),RooksQueens),
BlackPieces) != 0);
else return(0);
case 9:
if (And(AttacksDiagh1(square),WhiteKing) != 0)
return(And(And(AttacksDiagh1(square),BishopsQueens),
BlackPieces) != 0);
else return(0);
}
}
else {
ray=directions[BlackKingSQ][square];
if (!ray) return(0);
switch (abs(ray)) {
case 1:
if (And(AttacksRank(square),BlackKing) != 0)
return(And(And(AttacksRank(square),RooksQueens),
WhitePieces) != 0);
else return(0);
case 7:
if (And(AttacksDiaga1(square),BlackKing) != 0)
return(And(And(AttacksDiaga1(square),BishopsQueens),
WhitePieces) != 0);
else return(0);
case 8:
if (And(AttacksFile(square),BlackKing) != 0)
return(And(And(AttacksFile(square),RooksQueens),
WhitePieces) != 0);
else return(0);
case 9:
if (And(AttacksDiagh1(square),BlackKing) != 0)
return(And(And(AttacksDiagh1(square),BishopsQueens),
WhitePieces) != 0);
else return(0);
}
}
return(0);
}
unsigned int Random32(void)
{
static unsigned long x[55] = {
1410651636UL, 3012776752UL, 3497475623UL, 2892145026UL, 1571949714UL,
3253082284UL, 3489895018UL, 387949491UL, 2597396737UL, 1981903553UL,
3160251843UL, 129444464UL, 1851443344UL, 4156445905UL, 224604922UL,
1455067070UL, 3953493484UL, 1460937157UL, 2528362617UL, 317430674UL,
3229354360UL, 117491133UL, 832845075UL, 1961600170UL, 1321557429UL,
747750121UL, 545747446UL, 810476036UL, 503334515UL, 4088144633UL,
2824216555UL, 3738252341UL, 3493754131UL, 3672533954UL, 29494241UL,
1180928407UL, 4213624418UL, 33062851UL, 3221315737UL, 1145213552UL,
2957984897UL, 4078668503UL, 2262661702UL, 65478801UL, 2527208841UL,
1960622036UL, 315685891UL, 1196037864UL, 804614524UL, 1421733266UL,
2017105031UL, 3882325900UL, 810735053UL, 384606609UL, 2393861397UL };
static int init = 1;
static unsigned long y[55];
static int j, k;
unsigned long ul;
if (init)
{
int i;
init = 0;
for (i = 0; i < 55; i++) y[i] = x[i];
j = 24 - 1;
k = 55 - 1;
}
ul = (y[k] += y[j]);
if (--j < 0) j = 55 - 1;
if (--k < 0) k = 55 - 1;
return((unsigned int)ul);
}
BITBOARD Random64(void)
{
BITBOARD result;
unsigned int r1, r2;
r1=Random32();
r2=Random32();
result=Or(r1,Shiftl((BITBOARD) r2,32));
return (result);
}
int Read(int wait, char *buffer) {
char *eol, *ret, readdata;
*buffer=0;
if (strchr(cmd_buffer,'\n'));
else if (!wait) {
if (CheckInput()) {
readdata=SpecReadRaw();
if (!strchr(cmd_buffer,'\n')) return(0);
if (!readdata) return(-1);
}
else return(0);
}
else while (!strchr(cmd_buffer,'\n')) {
readdata=SpecReadRaw();
if (!readdata) return(-1);
}
eol=strchr(cmd_buffer,'\n');
*eol=0;
ret=strchr(cmd_buffer,'\r');
if (ret) *ret=' ';
strcpy(buffer,cmd_buffer);
memmove(cmd_buffer,eol+1,strlen(eol+1)+1);
return(1);
}
void ReadClear() {
cmd_buffer[0]=0;
}
int ReadParse(char *buffer, char *args[], char *delims) {
char *next, tbuffer[512];
int nargs;
strcpy(tbuffer,buffer);
for (nargs=0;nargs<16;nargs++) *(args[nargs])=0;
next=strtok(tbuffer,delims);
if (!next) return(0);
strcpy(args[0],next);
for (nargs=1;nargs<32;nargs++) {
next=strtok(0,delims);
if (!next) break;
strcpy(args[nargs],next);
}
return(nargs);
}
int SpecReadRaw(void) {
char buffer[512], *end;
int bytes;
do
bytes=read(fileno(input_stream),buffer,512);
while (bytes<0 && errno==EINTR);
if (bytes == 0) {
if (input_stream != stdin) fclose(input_stream);
input_stream=stdin;
return(0);
}
else if (bytes < 0) {
printf("ERROR!  input I/O stream is unreadable, exiting.\n");
exit(1);
}
end=cmd_buffer+strlen(cmd_buffer);
memcpy(end,buffer,bytes);
*(end+bytes)=0;
return(1);
}
int ReadChessMove(FILE *input, int wtm, int one_move) {
static char text[128];
char *tmove;
int move=0, status;
while (move == 0) {
status=fscanf(input,"%s",text);
if (status <= 0) return(-1);
if (strcmp(text,"0-0") && strcmp(text,"0-0-0"))
tmove=text+strspn(text,"0123456789.");
else
tmove=text;
if (((tmove[0]>='a' && tmove[0]<='z') ||
(tmove[0]>='A' && tmove[0]<='Z')) ||
!strcmp(tmove,"0-0") || !strcmp(tmove,"0-0-0")) {
if (!strcmp(tmove,"exit")) return(-1);
move=InputMove(tmove,0,wtm,1,0);
}
if (one_move) break;
}
return(move);
}
int ReadNextMove(char *text, int ply, int wtm) {
char *tmove;
int move=0;
if (strcmp(text,"0-0") && strcmp(text,"0-0-0"))
tmove=text+strspn(text,"0123456789./-");
else
tmove=text;
if (((tmove[0]>='a' && tmove[0]<='z') ||
(tmove[0]>='A' && tmove[0]<='Z')) ||
!strcmp(tmove,"0-0") || !strcmp(tmove,"0-0-0")) {
if (!strcmp(tmove,"exit")) return(-1);
move=InputMove(tmove,ply,wtm,1,0);
}
return(move);
}
char* Reverse(void)
{
#if defined(NT_i386) || defined(NT_AXP)
HANDLE  std_console;
std_console = GetStdHandle(STD_OUTPUT_HANDLE);
#endif
if (ansi) {
#if defined(UNIX) || defined(AMIGA)
return("\033[7m");
#elif defined(NT_i386) || defined(NT_AXP)
SetConsoleTextAttribute(std_console, BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
return("");
#else
return("\033[7;47;33m");
#endif
}
return("");
}
void Whisper(int level,int depth,int time,int value,unsigned int nodes,
int cpu,char* pv)
{
if (!puzzling) {
char prefix[128];
if (strlen(channel_title) && channel)
sprintf(prefix,"tellics tell %d (%s) ",channel, channel_title);
else if (channel) sprintf(prefix,"tellics tell %d",channel);
else sprintf(prefix,"tellics whisper");
switch (level) {
case 1:
if (kibitz && (value > 0)) {
if (ics) printf("*");
printf("tellics kibitz mate in %d moves.\n\n",value);
}
else if (whisper && (value > 0)) {
if (ics) printf("*");
printf("%s mate in %d moves.\n\n",prefix,value);
}
if (kibitz && (value < 0)) {
if (ics) printf("*");
printf("%s mated in %d moves.\n\n",prefix,-value);
}
break;
case 2:
if (kibitz >= 2) {
if (ics) printf("*");
printf("tellics kibitz d%d; %s; nps %d; time %s; cpu %d%%; p:%d\n",
depth,DisplayEvaluationWhisper(value),
(time)?100*nodes/time:nodes,DisplayTimeWhisper(time),cpu,predicted);
}
else if (whisper >= 2) {
if (ics) printf("*");
printf("%s d%d; %s; nps %d; time %s; cpu %d%%; p:%d\n",
prefix,depth,DisplayEvaluationWhisper(value),
(time)?100*nodes/time:nodes,DisplayTimeWhisper(time),cpu,predicted);
}
case 3:
if ((kibitz >= 3) && nodes>5000) {
if (ics) printf("*");
printf("tellics kibitz pv:%s\n",pv);
}
else if ((whisper >= 3) && nodes>5000) {
if (ics) printf("*");
printf("%s pv:%s\n",prefix,pv);
}
break;
case 4:
if (kibitz >= 4) {
if (ics) printf("*");
printf("tellics kibitz %s\n",pv);
}
else if (whisper >= 4) {
if (ics) printf("*");
printf("%s %s\n",prefix,pv);
}
break;
case 5:
if (kibitz>=5 && nodes>5000) {
if (ics) printf("*");
printf("tellics kibitz d%d-> %s %s %s\n",depth, DisplayTimeWhisper(time),
DisplayEvaluationWhisper(value),pv);
}
else if (whisper>=5 && nodes>5000) {
if (ics) printf("*");
printf("%s d%d-> %s %s %s\n",prefix,depth, DisplayTimeWhisper(time),
DisplayEvaluationWhisper(value),pv);
}
break;
case 6:
if (kibitz>=6 && nodes>5000) {
if (ics) printf("*");
if (cpu == 0)
printf("tellics kibitz d%d+ %s %s %s\n",depth, DisplayTimeWhisper(time),
DisplayEvaluationWhisper(value),pv);
else
printf("tellics kibitz d%d+ %s >(%s) %s <re-searching>\n",depth,
DisplayTimeWhisper(time),DisplayEvaluationWhisper(value),pv);
}
else if (whisper>=6 && nodes>5000) {
if (ics) printf("*");
if (cpu == 0)
printf("%s d%d+ %s %s %s\n",prefix,depth, DisplayTimeWhisper(time),
DisplayEvaluationWhisper(value),pv);
else
printf("%s d%d+ %s >(%s) %s <re-searching>\n",prefix,depth,
DisplayTimeWhisper(time),DisplayEvaluationWhisper(value),pv);
}
break;
}
if (post) {
if (strstr(pv,"book"))
printf("	%2d  %5d %7d %6u %s\n",depth,value,time,nodes,pv+10);
else
printf("	%2d  %5d %7d %6u %s\n",depth,value,time,nodes,pv);
}
fflush(stdout);
}
}
/* 当前文件是D:\Read\valid.c*/

int ValidMove(int ply, int wtm, int move)
{
if (wtm) {
if (PieceOnSquare(From(move)) != Piece(move)) return(0);
}
else {
if (PieceOnSquare(From(move)) != -Piece(move)) return(0);
}
switch (Piece(move)) {
case empty:
return(0);
case king:
if (abs(From(move)-To(move)) == 2) {
if (wtm) {
if (WhiteCastle(ply) > 0) {
if (To(move) == 2) {
if ((!(WhiteCastle(ply)&2)) ||
And(Occupied,Shiftr(mask_3,1)) ||
And(AttacksTo(2),BlackPieces) ||
And(AttacksTo(3),BlackPieces) ||
And(AttacksTo(4),BlackPieces)) return(0);
}
else if (To(move) == 6) {
if ((!(WhiteCastle(ply)&1)) ||
And(Occupied,Shiftr(mask_2,5)) ||
And(AttacksTo(4),BlackPieces) ||
And(AttacksTo(5),BlackPieces) ||
And(AttacksTo(6),BlackPieces)) return(0);
}
}
else return(0);
}
else {
if (BlackCastle(ply) > 0) {
if (To(move) == 58) {
if ((!(BlackCastle(ply)&2)) ||
And(Occupied,Shiftr(mask_3,57)) ||
And(AttacksTo(58),WhitePieces) ||
And(AttacksTo(59),WhitePieces) ||
And(AttacksTo(60),WhitePieces)) return(0);
}
if (To(move) == 62) {
if ((!(BlackCastle(ply)&1)) ||
And(Occupied,Shiftr(mask_2,61)) ||
And(AttacksTo(60),WhitePieces) ||
And(AttacksTo(61),WhitePieces) ||
And(AttacksTo(62),WhitePieces)) return(0);
}
}
else return(0);
}
return(1);
}
break;
case pawn:
if (abs(From(move)-To(move)) == 8) {
if (wtm) {
if ((Piece(move) == PieceOnSquare(From(move))) &&
(From(move) < To(move)) && !PieceOnSquare(To(move))) return(1);
}
else {
if ((Piece(move) == -PieceOnSquare(From(move))) &&
(From(move) > To(move)) && !PieceOnSquare(To(move))) return(1);
}
return(0);
}
else if (abs(From(move)-To(move)) == 16) {
if (wtm) {
if ((Piece(move) == PieceOnSquare(From(move))) &&
!PieceOnSquare(To(move)-8) && !PieceOnSquare(To(move))) return(1);
}
else {
if ((Piece(move) == -PieceOnSquare(From(move))) &&
!PieceOnSquare(To(move)+8) && !PieceOnSquare(To(move))) return(1);
}
return(0);
}
if (!Captured(move)) return(0);
if (wtm) {
if ((PieceOnSquare(From(move)) == pawn) &&
(PieceOnSquare(To(move)) == 0) &&
(PieceOnSquare(To(move)-8) == -pawn) &&
And(EnPassantTarget(ply),set_mask[To(move)])) return(1);
}
else {
if ((PieceOnSquare(From(move)) == -pawn) &&
(PieceOnSquare(To(move)) == 0) &&
(PieceOnSquare(To(move)+8) == pawn) &&
And(EnPassantTarget(ply),set_mask[To(move)])) return(1);
}
case queen:
case rook:
case bishop:
case knight:
break;
}
if (wtm) {
if ((Piece(move) == PieceOnSquare(From(move))) &&
(Captured(move) == -PieceOnSquare(To(move))) &&
And(AttacksFrom(From(move),wtm),set_mask[To(move)])) return(1);
}
else {
if ((Piece(move) == -PieceOnSquare(From(move))) &&
(Captured(move) == PieceOnSquare(To(move))) &&
And(AttacksFrom(From(move),wtm),set_mask[To(move)])) return(1);
}
return(0);
}
/* 当前文件是D:\Read\validate.c*/

void ValidatePosition(int ply, int move, char *caller)
{
BITBOARD temp, temp_occ, temp_occ_rl90, temp_occ_rl45;
BITBOARD temp_occ_rr45, temp_occx, cattacks, rattacks;
unsigned int temp1;
int i,square,error;
int temp_score;
error=0;
temp_occ=Or(Or(Or(Or(Or(WhitePawns,WhiteKnights),WhiteBishops),
WhiteRooks),WhiteQueens),WhiteKing);
if(Xor(WhitePieces,temp_occ)) {
printf("ERROR white occupied squares is bad!\n");
Display2BitBoards(temp_occ,WhitePieces);
error=1;
}
temp_occ=Or(Or(Or(Or(Or(BlackPawns,BlackKnights),BlackBishops),
BlackRooks),BlackQueens),BlackKing);
if(Xor(BlackPieces,temp_occ)) {
printf("ERROR black occupied squares is bad!\n");
Display2BitBoards(temp_occ,BlackPieces);
error=1;
}
temp_occ_rl90=0;
temp_occ_rl45=0;
temp_occ_rr45=0;
for (i=0;i<64;i++) {
if (PieceOnSquare(i)) {
temp_occ_rl90=Or(temp_occ_rl90,set_mask_rl90[i]);
temp_occ_rl45=Or(temp_occ_rl45,set_mask_rl45[i]);
temp_occ_rr45=Or(temp_occ_rr45,set_mask_rr45[i]);
}
}
if(Xor(OccupiedRL90,temp_occ_rl90)) {
printf("ERROR occupied squares (rotated left 90) is bad!\n");
Display2BitBoards(temp_occ_rl90,OccupiedRL90);
error=1;
}
if(Xor(OccupiedRL45,temp_occ_rl45)) {
printf("ERROR occupied squares (rotated left 45) is bad!\n");
Display2BitBoards(temp_occ_rl45,OccupiedRL45);
error=1;
}
if(Xor(OccupiedRR45,temp_occ_rr45)) {
printf("ERROR occupied squares (rotated right 45) is bad!\n");
Display2BitBoards(temp_occ_rr45,OccupiedRR45);
error=1;
}
temp_occ=Or(Or(Or(WhiteBishops,WhiteQueens),BlackBishops),
BlackQueens);
if(Xor(BishopsQueens,temp_occ)) {
printf("ERROR bishops_queens is bad!\n");
Display2BitBoards(temp_occ,BishopsQueens);
error=1;
}
temp_occ=Or(Or(Or(WhiteRooks,WhiteQueens),BlackRooks),
BlackQueens);
if(Xor(RooksQueens,temp_occ)) {
printf("ERROR rooks_queens is bad!\n");
Display2BitBoards(temp_occ,RooksQueens);
error=1;
}
temp_occ=Xor(Xor(Xor(Xor(Xor(Xor(Xor(Xor(Xor(Xor(Xor(
WhitePawns,WhiteKnights),WhiteBishops),WhiteRooks),
WhiteQueens),BlackPawns),BlackKnights),BlackBishops),
BlackRooks),BlackQueens),WhiteKing),BlackKing);
temp_occx=Or(Or(Or(Or(Or(Or(Or(Or(Or(Or(Or(
WhitePawns,WhiteKnights),WhiteBishops),WhiteRooks),
WhiteQueens),BlackPawns),BlackKnights),BlackBishops),
BlackRooks),BlackQueens),WhiteKing),BlackKing);
if(Xor(temp_occ,temp_occx)) {
printf("ERROR two pieces on same square\n");
error=1;
}
temp_score=PopCnt(WhitePawns)*PAWN_VALUE;
temp_score-=PopCnt(BlackPawns)*PAWN_VALUE;
temp_score+=PopCnt(WhiteKnights)*KNIGHT_VALUE;
temp_score-=PopCnt(BlackKnights)*KNIGHT_VALUE;
temp_score+=PopCnt(WhiteBishops)*BISHOP_VALUE;
temp_score-=PopCnt(BlackBishops)*BISHOP_VALUE;
temp_score+=PopCnt(WhiteRooks)*ROOK_VALUE;
temp_score-=PopCnt(BlackRooks)*ROOK_VALUE;
temp_score+=PopCnt(WhiteQueens)*QUEEN_VALUE;
temp_score-=PopCnt(BlackQueens)*QUEEN_VALUE;
if(temp_score != Material) {
printf("ERROR  material_evaluation is wrong, good=%d, bad=%d\n",
temp_score,Material);
error=1;
}
temp_score=PopCnt(WhiteKnights)*knight_v;
temp_score+=PopCnt(WhiteBishops)*bishop_v;
temp_score+=PopCnt(WhiteRooks)*rook_v;
temp_score+=PopCnt(WhiteQueens)*queen_v;
if(temp_score != TotalWhitePieces) {
printf("ERROR  white_pieces is wrong, good=%d, bad=%d\n",
temp_score,TotalWhitePieces);
error=1;
}
temp_score=PopCnt(WhitePawns);
if(temp_score != TotalWhitePawns) {
printf("ERROR  white_pawns is wrong, good=%d, bad=%d\n",
temp_score,TotalWhitePawns);
error=1;
}
temp_score=PopCnt(BlackKnights)*knight_v;
temp_score+=PopCnt(BlackBishops)*bishop_v;
temp_score+=PopCnt(BlackRooks)*rook_v;
temp_score+=PopCnt(BlackQueens)*queen_v;
if(temp_score != TotalBlackPieces) {
printf("ERROR  black_pieces is wrong, good=%d, bad=%d\n",
temp_score,TotalBlackPieces);
error=1;
}
temp_score=PopCnt(BlackPawns);
if(temp_score != TotalBlackPawns) {
printf("ERROR  black_pawns is wrong, good=%d, bad=%d\n",
temp_score,TotalBlackPawns);
error=1;
}
temp=WhitePawns;
while(temp) {
square=FirstOne(temp);
if (PieceOnSquare(square) != pawn) {
printf("ERROR!  board[%d]=%d, should be 1\n",square,
PieceOnSquare(square));
error=1;
}
Clear(square,temp);
}
temp=BlackPawns;
while(temp) {
square=FirstOne(temp);
if (PieceOnSquare(square) != -pawn) {
printf("ERROR!  board[%d]=%d, should be -1\n",square,
PieceOnSquare(square));
error=1;
}
Clear(square,temp);
}
temp=WhiteKnights;
while(temp) {
square=FirstOne(temp);
if (PieceOnSquare(square) != knight) {
printf("ERROR!  board[%d]=%d, should be 2\n",square,
PieceOnSquare(square));
error=1;
}
Clear(square,temp);
}
temp=BlackKnights;
while(temp) {
square=FirstOne(temp);
if (PieceOnSquare(square) != -knight) {
printf("ERROR!  board[%d]=%d, should be -2\n",square,
PieceOnSquare(square));
error=1;
}
Clear(square,temp);
}
temp=WhiteBishops;
while(temp) {
square=FirstOne(temp);
if (PieceOnSquare(square) != bishop) {
printf("ERROR!  board[%d]=%d, should be 3\n",square,
PieceOnSquare(square));
error=1;
}
rattacks=AttacksBishop(square);
cattacks=ValidateComputeBishopAttacks(square);
if (rattacks != cattacks) {
printf("ERROR!  bishop attacks wrong, square=%d\n",square);
Display2BitBoards(cattacks,rattacks);
error=1;
}
Clear(square,temp);
}
temp=BlackBishops;
while(temp) {
square=FirstOne(temp);
if (PieceOnSquare(square) != -bishop) {
printf("ERROR!  board[%d]=%d, should be -3\n",square,
PieceOnSquare(square));
error=1;
}
rattacks=AttacksBishop(square);
cattacks=ValidateComputeBishopAttacks(square);
if (rattacks != cattacks) {
printf("ERROR!  bishop attacks wrong, square=%d\n",square);
Display2BitBoards(cattacks,rattacks);
error=1;
}
Clear(square,temp);
}
temp=WhiteRooks;
while(temp) {
square=FirstOne(temp);
if (PieceOnSquare(square) != rook) {
printf("ERROR!  board[%d]=%d, should be 4\n",square,
PieceOnSquare(square));
error=1;
}
rattacks=AttacksRook(square);
cattacks=ValidateComputeRookAttacks(square);
if (rattacks != cattacks) {
printf("ERROR!  Rook attacks wrong, square=%d\n",square);
Display2BitBoards(cattacks,rattacks);
error=1;
}
Clear(square,temp);
}
temp=BlackRooks;
while(temp) {
square=FirstOne(temp);
if (PieceOnSquare(square) != -rook) {
printf("ERROR!  board[%d]=%d, should be -4\n",square,
PieceOnSquare(square));
error=1;
}
rattacks=AttacksRook(square);
cattacks=ValidateComputeRookAttacks(square);
if (rattacks != cattacks) {
printf("ERROR!  Rook attacks wrong, square=%d\n",square);
Display2BitBoards(cattacks,rattacks);
error=1;
}
Clear(square,temp);
}
temp=WhiteQueens;
while(temp) {
square=FirstOne(temp);
if (PieceOnSquare(square) != queen) {
printf("ERROR!  board[%d]=%d, should be 5\n",square,
PieceOnSquare(square));
error=1;
}
rattacks=AttacksQueen(square);
cattacks=Or(ValidateComputeRookAttacks(square),ValidateComputeBishopAttacks(square));
if (rattacks != cattacks) {
printf("ERROR!  queen attacks wrong, square=%d\n",square);
Display2BitBoards(cattacks,rattacks);
error=1;
}
Clear(square,temp);
}
temp=BlackQueens;
while(temp) {
square=FirstOne(temp);
if (PieceOnSquare(square) != -queen) {
printf("ERROR!  board[%d]=%d, should be -5\n",square,
PieceOnSquare(square));
error=1;
}
rattacks=AttacksQueen(square);
cattacks=Or(ValidateComputeRookAttacks(square),ValidateComputeBishopAttacks(square));
if (rattacks != cattacks) {
printf("ERROR!  queen attacks wrong, square=%d\n",square);
Display2BitBoards(cattacks,rattacks);
error=1;
}
Clear(square,temp);
}
temp=WhiteKing;
while(temp) {
square=FirstOne(temp);
if (PieceOnSquare(square) != king) {
printf("ERROR!  board[%d]=%d, should be 6\n",square,
PieceOnSquare(square));
error=1;
}
if (WhiteKingSQ != square) {
printf("ERROR!  white_king is %d, should be %d\n",
WhiteKingSQ,square);
error=1;
}
Clear(square,temp);
}
temp=BlackKing;
while(temp) {
square=FirstOne(temp);
if (PieceOnSquare(square) != -king) {
printf("ERROR!  board[%d]=%d, should be -6\n",square,
PieceOnSquare(square));
error=1;
}
if (BlackKingSQ != square) {
printf("ERROR!  black_king is %d, should be %d\n",
BlackKingSQ,square);
error=1;
}
Clear(square,temp);
}
for (i=0;i<64;i++)
switch (PieceOnSquare(i)) {
case -king:
if (!And(BlackKing,set_mask[i])) {
printf("ERROR!  b_king/board[%d] don't agree!\n",i);
error=1;
}
break;
case -queen:
if (!And(BlackQueens,set_mask[i])) {
printf("ERROR!  b_queen/board[%d] don't agree!\n",i);
error=1;
}
break;
case -rook:
if (!And(BlackRooks,set_mask[i])) {
printf("ERROR!  b_rook/board[%d] don't agree!\n",i);
error=1;
}
break;
case -bishop:
if (!And(BlackBishops,set_mask[i])) {
printf("ERROR!  b_bishop/board[%d] don't agree!\n",i);
error=1;
}
break;
case -knight:
if (!And(BlackKnights,set_mask[i])) {
printf("ERROR!  b_knight/board[%d] don't agree!\n",i);
error=1;
}
break;
case -pawn:
if (!And(BlackPawns,set_mask[i])) {
printf("ERROR!  b_pawn/board[%d] don't agree!\n",i);
error=1;
}
break;
case king:
if (!And(WhiteKing,set_mask[i])) {
printf("ERROR!  w_king/board[%d] don't agree!\n",i);
error=1;
}
break;
case queen:
if (!And(WhiteQueens,set_mask[i])) {
printf("ERROR!  w_queen/board[%d] don't agree!\n",i);
error=1;
}
break;
case rook:
if (!And(WhiteRooks,set_mask[i])) {
printf("ERROR!  w_rook/board[%d] don't agree!\n",i);
error=1;
}
break;
case bishop:
if (!And(WhiteBishops,set_mask[i])) {
printf("ERROR!  w_bishop/board[%d] don't agree!\n",i);
error=1;
}
break;
case knight:
if (!And(WhiteKnights,set_mask[i])) {
printf("ERROR!  w_knight/board[%d] don't agree!\n",i);
error=1;
}
break;
case pawn:
if (!And(WhitePawns,set_mask[i])) {
printf("ERROR!  w_pawn/board[%d] don't agree!\n",i);
error=1;
}
break;
}
temp=Compl(Or(temp_occ,temp_occx));
while(temp) {
square=FirstOne(temp);
if (PieceOnSquare(square)) {
printf("ERROR!  board[%d]=%d, should be 0\n",square,
PieceOnSquare(square));
error=1;
}
Clear(square,temp);
}
i=PopCnt(Occupied);
if (i != TotalPieces) {
printf("ERROR!  TotalPieces is wrong, correct=%d  bad=%d\n",
i,TotalPieces);
error=1;
}
temp=0;
temp1=0;
for (i=0;i<64;i++) {
switch (PieceOnSquare(i)) {
case king:
temp=Xor(temp,w_king_random[i]);
break;
case queen:
temp=Xor(temp,w_queen_random[i]);
break;
case rook:
temp=Xor(temp,w_rook_random[i]);
break;
case bishop:
temp=Xor(temp,w_bishop_random[i]);
break;
case knight:
temp=Xor(temp,w_knight_random[i]);
break;
case pawn:
temp=Xor(temp,w_pawn_random[i]);
temp1=temp1^w_pawn_random32[i];
break;
case -pawn:
temp=Xor(temp,b_pawn_random[i]);
temp1=temp1^b_pawn_random32[i];
break;
case -knight:
temp=Xor(temp,b_knight_random[i]);
break;
case -bishop:
temp=Xor(temp,b_bishop_random[i]);
break;
case -rook:
temp=Xor(temp,b_rook_random[i]);
break;
case -queen:
temp=Xor(temp,b_queen_random[i]);
break;
case -king:
temp=Xor(temp,b_king_random[i]);
break;
default:
break;
}
}
if (EnPassant(ply)) HashEP(EnPassant(ply),temp);
if (!(WhiteCastle(ply)&1)) HashCastleW(0,temp);
if (!(WhiteCastle(ply)&2)) HashCastleW(1,temp);
if (!(BlackCastle(ply)&1)) HashCastleB(0,temp);
if (!(BlackCastle(ply)&2)) HashCastleB(1,temp);
if(Xor(temp,HashKey)) {
printf("ERROR!  hash_key is bad.\n");
error=1;
}
if(temp1^PawnHashKey) {
printf("ERROR!  pawn_hash_key is bad.\n");
error=1;
}
if (error) {
printf("current move:\n");
DisplayChessMove("move=",move);
DisplayChessBoard(stdout,search);
printf("called from %s, ply=%d\n",caller,ply);
printf("node=%d\n",nodes_searched);
exit(1);
}
}
BITBOARD ValidateComputeBishopAttacks(int square)
{
BITBOARD attacks, temp_attacks;
BITBOARD temp7, temp9;
attacks=bishop_attacks[square];
temp_attacks=And(attacks,Compl(Occupied));
temp_attacks=Compl(Or(temp_attacks,Compl(bishop_attacks[square])));
temp7=And(temp_attacks,plus7dir[square]);
temp9=And(temp_attacks,plus9dir[square]);
attacks=Xor(attacks,plus7dir[FirstOne(temp7)]);
attacks=Xor(attacks,plus9dir[FirstOne(temp9)]);
temp7=And(temp_attacks,minus7dir[square]);
temp9=And(temp_attacks,minus9dir[square]);
attacks=Xor(attacks,minus7dir[LastOne(temp7)]);
attacks=Xor(attacks,minus9dir[LastOne(temp9)]);
return(attacks);
}
BITBOARD ValidateComputeRookAttacks(int square)
{
BITBOARD attacks, temp_attacks;
BITBOARD temp1, temp8;
attacks=rook_attacks[square];
temp_attacks=And(attacks,Compl(Occupied));
temp_attacks=Compl(Or(temp_attacks,Compl(rook_attacks[square])));
temp1=And(temp_attacks,plus1dir[square]);
temp8=And(temp_attacks,plus8dir[square]);
attacks=Xor(attacks,plus1dir[FirstOne(temp1)]);
attacks=Xor(attacks,plus8dir[FirstOne(temp8)]);
temp1=And(temp_attacks,minus1dir[square]);
temp8=And(temp_attacks,minus8dir[square]);
attacks=Xor(attacks,minus1dir[LastOne(temp1)]);
attacks=Xor(attacks,minus8dir[LastOne(temp8)]);
return(attacks);
}
int main(int argc, char **argv)
{
int move, presult, readstat;
int value=0, i, cont=0, result;
char *targs[32];
#  if defined(NT_i386) || defined(NT_AXP)

#  else

#  endif
#  if defined(UNIX)
char path[1024];
struct passwd *pwd;
#  endif
input_stream=stdin;
for (i=0;i<32;i++) args[i]=malloc(128);
if (argc > 1) {
for (i=0;i<32;i++) targs[i]=malloc(128);
for (i=1;i<argc;i++) {
if (!strcmp(argv[i],"c")) cont=1;
else if (argv[i][0]>='0' && argv[i][0] <= '9' && i+1<argc) {
tc_moves=atoi(argv[i]);
tc_time=atoi(argv[i+1]);
tc_increment=0;
tc_secondary_moves=tc_moves;
tc_secondary_time=tc_time;
tc_time*=60;
tc_time_remaining=tc_time;
tc_secondary_time*=60;
i++;
}
else if (strstr(argv[i],"path")) {
strcpy(buffer,argv[i]);
result=Option();
if (result == 0)
printf("ERROR \"%s\" is unknown command-line option\n",buffer);
display=search;
}
}
}
if (cont) Initialize(1);
else Initialize(0);
printf("\nCrafty v%s\n\n",version);
if (argc > 1) {
for (i=1;i<argc;i++) if (strcmp(argv[i],"c"))
if ((argv[i][0]<'0' || argv[i][0] > '9') &&
!strstr(argv[i],"path")) {
strcpy(buffer,argv[i]);
result=Option();
if (result == 0)
printf("ERROR \"%s\" is unknown command-line option\n",buffer);
}
for (i=0;i<32;i++) free(targs[i]);
}
display=search;
initialized=1;
#ifndef SPEC_CPU2000
#if defined(UNIX)
input_stream=fopen(".craftyrc","r");
if (!input_stream)
if ((pwd=getpwuid(getuid()))) {
sprintf(path, "%s/.craftyrc", pwd->pw_dir);
input_stream=fopen(path,"r");
}
if (input_stream)
#else
if ((input_stream=fopen("crafty.rc","r")))
#endif
#endif
if ((input_stream=fopen("crafty.rc","r")))
while (1) {
readstat=Read(1,buffer);
if (readstat) {
char *delim;
delim=strchr(buffer,'\n');
if (delim) *delim=0;
delim=strchr(buffer,'\r');
if (delim) *delim=0;
}
if (readstat < 0) break;
result=Option();
if (result == 0)
printf("ERROR \"%s\" is unknown rc-file option\n",buffer);
if (input_stream == stdin) break;
}
input_stream=stdin;
if (xboard) signal(SIGINT,SIG_IGN);
signal(SIGTERM,SignalInterrupt);
if (ics) printf("*whisper Hello from Crafty v%s !\n",version);
if (xboard) {
printf("kibitz Hello from Crafty v%s !\n",version);
printf("tellics set 1 Crafty v%s\n",version);
}
NewGame(1);
while (1) {
presult=0;
do {
if (new_game) NewGame(0);
opponent_start_time=GetTime(elapsed);
made_predicted_move=0;
display=search;
move=0;
presult=0;
do {
if (presult != 2) presult=0;
result=0;
display=search;
if (presult !=2 && (move_number!=1 || !wtm)) presult=Ponder(wtm);
if (presult==0 || presult==2) {
if (!ics && !xboard) {
if (wtm) printf("White(%d): ",move_number);
else printf("Black(%d): ",move_number);
fflush(stdout);
}
readstat=Read(1,buffer);
if (log_file) {
if (wtm) fprintf(log_file,"White(%d): %s\n",move_number,buffer);
else fprintf(log_file,"Black(%d): %s\n",move_number,buffer);
}
if (readstat<0 && input_stream==stdin) {
strcpy(buffer,"end");
(void) Option();
}
}
if (presult == 1) break;
opponent_end_time=GetTime(elapsed);
result=Option();
if (result == 0) {
nargs=ReadParse(buffer,args," 	;");
move=InputMove(args[0],0,wtm,0,0);
last_opponent_move=move;
if (auto232 && presult!=3) {
char *mv=OutputMoveICS(&move);
Delay(auto232_delay);
if (!wtm) fprintf(auto_file,"\t");
fprintf(auto_file, " %c%c-%c%c", mv[0], mv[1], mv[2], mv[3]);
if ((mv[4] != ' ') && (mv[4] != 0))
fprintf(auto_file, "/%c", mv[4]);
fprintf(auto_file, "\n");
fflush(auto_file);
}
result=!move;
}
else if (result == 3) presult=0;
} while (result > 0);
if (presult == 1) move=ponder_move;
if(result == 0) {
fseek(history_file,((move_number-1)*2+1-wtm)*10,SEEK_SET);
fprintf(history_file,"%9s\n",OutputMove(&move,0,wtm));
MakeMoveRoot(move,wtm);
if (RepetitionDraw(ChangeSide(wtm))==1) {
printf("%sgame is a draw by repetition.%s\n",Reverse(),Normal());
value=DrawScore();
if (xboard) printf("Draw\n");
}
if (RepetitionDraw(ChangeSide(wtm))==2) {
printf("%sgame is a draw by the 50 move rule.%s\n",Reverse(),Normal());
value=DrawScore();
}
wtm=ChangeSide(wtm);
if (wtm) move_number++;
time_used_opponent=opponent_end_time-opponent_start_time;
if (!force)
printf("              time used: %s\n",
DisplayTime(time_used_opponent));
TimeAdjust(time_used_opponent,opponent);
}
else {
position[1]=position[0];
presult=0;
}
ValidatePosition(0,move,"Main(1)");
} while(force);
crafty_is_white=wtm;
if (presult == 2) {
if((From(ponder_move) == From(move)) &&
(To(ponder_move) == To(move)) &&
(Piece(ponder_move) == Piece(move)) &&
(Captured(ponder_move) == Captured(move)) &&
(Promote(ponder_move) == Promote(move))) {
presult=1;
if (!book_move) predicted++;
}
else presult=0;
}
ponder_move=0;
thinking=1;
if (presult == 1) value=last_search_value;
else {
strcpy(whisper_text,"n/a");
last_pv.path_iteration_depth=0;
last_pv.path_length=0;
display=search;
value=Iterate(wtm,think,0);
}
last_pv=pv[0];
last_value=value;
if (abs(last_value) > (MATE-100)) last_mate_score=last_value;
thinking=0;
if (!last_pv.path_length) {
if (value == -MATE+1) {
over=1;
printf("%s",Reverse());
printf("checkmate\n");
printf("%s",Normal());
if (xboard)
if(wtm) printf("Black mates\n");
else printf("White mates\n");
}
}
else {
if ((value > MATE-100) && (value < MATE-2)) {
printf("\nCrafty will mate in %d moves.\n\n",(MATE-value)/2);
Whisper(1,0,0,(MATE-value)/2,nodes_searched,0," ");
}
else if ((-value > MATE-100) && (-value < MATE-1)) {
printf("\nmated in %d moves.\n\n",(MATE+value)/2);
Whisper(1,0,0,-(MATE+value)/2,nodes_searched,0," ");
}
if (wtm) {
if (!xboard && !ics) {
printf("\n");
printf("%s",Reverse());
if (audible_alarm) printf("%c",audible_alarm);
printf("White(%d): %s ",move_number,
OutputMove(&last_pv.path[1],0,wtm));
printf("%s",Normal());
printf("\n");
if (auto232) {
char *mv=OutputMoveICS(&last_pv.path[1]);
Delay(auto232_delay);
fprintf(auto_file, " %c%c-%c%c", mv[0],mv[1],mv[2],mv[3]);
if ((mv[4]!=' ') && (mv[4]!=0))
fprintf(auto_file, "/%c", mv[4]);
fprintf(auto_file, "\n");
fflush(auto_file);
}
}
else if (xboard) {
if (log_file) fprintf(log_file,"White(%d): %s\n",move_number,
OutputMove(&last_pv.path[1],0,wtm));
printf("%d. ... %s\n",move_number,OutputMoveICS(&last_pv.path[1]));
}
else printf("*%s\n",OutputMove(&last_pv.path[1],0,wtm));
}
else {
if (!xboard && !ics) {
printf("\n");
printf("%s",Reverse());
if (audible_alarm) printf("%c",audible_alarm);
printf("Black(%d): %s ",move_number,OutputMove(&last_pv.path[1],0,wtm));
printf("%s",Normal());
printf("\n");
if (auto232) {
char *mv=OutputMoveICS(&last_pv.path[1]);
Delay(auto232_delay);
fprintf(auto_file, "\t %c%c-%c%c", mv[0],mv[1],mv[2],mv[3]);
if ((mv[4]!=' ') && (mv[4]!=0))
fprintf(auto_file, "/%c", mv[4]);
fprintf(auto_file, "\n");
fflush(auto_file);
}
}
else {
if (log_file) fprintf(log_file,"Black(%d): %s\n",move_number,
OutputMove(&last_pv.path[1],0,wtm));
printf("%d. ... %s\n",move_number,OutputMoveICS(&last_pv.path[1]));
}
}
if (value == MATE-2) {
printf("checkmate\n");
if (xboard)
if(wtm) printf("White mates\n");
else printf("Black mates\n");
}
time_used=program_end_time-program_start_time;
printf("              time used: %s\n",DisplayTime(time_used));
TimeAdjust(time_used,crafty);
fseek(history_file,((move_number-1)*2+1-wtm)*10,SEEK_SET);
fprintf(history_file,"%9s\n",OutputMove(&last_pv.path[1],0,wtm));
previous_search_value=last_search_value;
MakeMoveRoot(last_pv.path[1],wtm);
if (RepetitionDraw(ChangeSide(wtm))==1) {
printf("%sgame is a draw by repetition.%s\n",Reverse(),Normal());
value=DrawScore();
}
if (RepetitionDraw(ChangeSide(wtm))==2) {
printf("%sgame is a draw by the 50 move rule.%s\n",Reverse(),Normal());
value=DrawScore();
}
if (log_file && time_limit > 500) DisplayChessBoard(log_file,search);
if (last_pv.path_length>1 &&
ValidMove(0,ChangeSide(wtm),last_pv.path[2])) {
ponder_move=last_pv.path[2];
for (i=1;i<=(int) last_pv.path_length-2;i++)
last_pv.path[i]=last_pv.path[i+2];
last_pv.path_length=(last_pv.path_length > 2) ? last_pv.path_length-2 : 0;
last_pv.path_iteration_depth-=2;
if (last_pv.path_iteration_depth > last_pv.path_length)
last_pv.path_iteration_depth=last_pv.path_length;
if (last_pv.path_length == 0) last_pv.path_iteration_depth=0;
}
else {
last_pv.path_iteration_depth=0;
last_pv.path_length=0;
ponder_move=0;
}
}
if (book_move) {
moves_out_of_book=0;
predicted++;
}
else moves_out_of_book++;
wtm=ChangeSide(wtm);
if (wtm) move_number++;
ValidatePosition(0,last_pv.path[1],"Main(2)");
if (kibitz || whisper) {
if (nodes_searched)
Whisper(2,whisper_depth,end_time-start_time,whisper_value,
nodes_searched,cpu_percent,whisper_text);
}
for (i=0;i<4096;i++) {
history_w[i]=history_w[i]>>8;
history_b[i]=history_b[i]>>8;
}
for (i=0;i<MAXPLY;i++) {
killer_count1[i]=0;
killer_count2[i]=0;
}
if (mode == tournament_mode) {
strcpy(buffer,"clock");
Option();
printf("if clocks are wrong, use 'clock' command to adjust them\n");
}
}
return 0;
}
