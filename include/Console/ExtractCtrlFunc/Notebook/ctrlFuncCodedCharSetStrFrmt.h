#define CBT(Pn) CSI "%d" "Z", Pn
#define CHA(Pn) CSI "%d" "G", Pn
#define CHT(Pn) CSI "%d" "I", Pn
#define CMD(Fs) ESC "d", Fs
#define CNL(Pn) CSI "%d" "E", Pn
#define CPL(Pn) CSI "%d" "F", Pn
#define CPR(Pn1, Pn2) CSI "%d" ";" "%d" "R", Pn1, Pn2
#define _CPR(Pn1) CSI "%d" ";" "R", Pn1
#define __CPR(Pn2) CSI ";" "%d" "R", Pn2
#define CTC(Ps) CSI "%d" "W", Ps
#define CUB(Pn) CSI "%d" "D", Pn
#define CUD(Pn) CSI "%d" "B", Pn
#define CUF(Pn) CSI "%d" "C", Pn
#define CUP(Pn1, Pn2) CSI "%d" ";" "%d" "H", Pn1, Pn2
#define _CUP(Pn1) CSI "%d" ";" "H", Pn1
#define __CUP(Pn2) CSI ";" "%d" "H", Pn2
#define CUU(Pn) CSI "%d" "A", Pn
#define CVT(Pn) CSI "%d" "Y", Pn
#define DA(Ps) CSI "%d" "c", Ps
#define DAQ(Ps) CSI "%d" "o", Ps
#define DCH(Pn) CSI "%d" "P", Pn
#define DL(Pn) CSI "%d" "M", Pn
#define DMI(Fs) ESC "`", Fs
#define DSR(Ps) CSI "%d" "n", Ps
#define DTA(Pn1, Pn2) CSI "%d" ";" "%d" " " "T", Pn1, Pn2
#define EA(Ps) CSI "%d" "O", Ps
#define ECH(Pn) CSI "%d" "X", Pn
#define ED(Ps) CSI "%d" "J", Ps
#define EF(Ps) CSI "%d" "N", Ps
#define EL(Ps) CSI "%d" "K", Ps
#define EMI(Fs) ESC "b", Fs
#define FNK(Pn) CSI "%d" " " "W", Pn
#define FNT(Ps1, Ps2) CSI "%d" ";" "%d" " " "D", Ps1, Ps2
#define _FNT(Ps1) CSI "%d" ";" " " "D", Ps1
#define __FNT(Ps2) CSI ";" "%d" " " "D", Ps2
#define GCC(Ps) CSI "%d" " " "_", Ps
#define GSM(Pn1, Pn2) CSI "%d" ";" "%d" " " "B", Pn1, Pn2
#define _GSM(Pn1) CSI "%d" ";" " " "B", Pn1
#define __GSM(Pn2) CSI ";" "%d" " " "B", Pn2
#define GSS(Pn) CSI "%d" " " "C", Pn
#define HPA(Pn) CSI "%d" "`", Pn
#define HPB(Pn) CSI "%d" "j", Pn
#define HPR(Pn) CSI "%d" "a", Pn
#define HVP(Pn1, Pn2) CSI "%d" ";" "%d" "f", Pn1, Pn2
#define _HVP(Pn1) CSI "%d" ";" "f", Pn1
#define __HVP(Pn2) CSI ";" "%d" "f", Pn2
#define ICH(Pn) CSI "%d" "@", Pn
#define IDCS(Ps) CSI "%d" " " "O", Ps
#define IGS(Ps) CSI "%d" " " "M", Ps
#define IL(Pn) CSI "%d" "L", Pn
#define INT(Fs) ESC "a", Fs
#define JFY(Ps) CSI "%d" " " "F", Ps
#define LS1R(Fs) ESC "~", Fs
#define LS2(Fs) ESC "n", Fs
#define LS2R(Fs) ESC "}", Fs
#define LS3(Fs) ESC "o", Fs
#define LS3R(Fs) ESC "|", Fs
#define MC(Ps) CSI "%d" "i", Ps
#define NP(Pn) CSI "%d" "U", Pn
#define PEC(Ps) CSI "%d" " " "Z", Ps
#define PFS(Ps) CSI "%d" " " "J", Ps
#define PP(Pn) CSI "%d" "V", Pn
#define PPA(Pn) CSI "%d" " " "P", Pn
#define PPB(Pn) CSI "%d" " " "R", Pn
#define PPR(Pn) CSI "%d" " " "Q", Pn
#define PTX(Ps) CSI "%d" "\\", Ps
#define QUAD(Ps) CSI "%d" " " "H", Ps
#define REP(Pn) CSI "%d" "b", Pn
#define RIS(Fs) ESC "c", Fs
#define RM(Ps) CSI "%d" "l", Ps
#define SACS(Pn) CSI "%d" " " "\\", Pn
#define SCO(Ps) CSI "%d" " " "e", Ps
#define SCP(Ps1, Ps2) CSI "%d" ";" "%d" " " "k", Ps1, Ps2
#define SCS(Pn) CSI "%d" " " "g", Pn
#define SD(Pn) CSI "%d" "T", Pn
#define SDS(Ps) CSI "%d" "]", Ps
#define SEE(Ps) CSI "%d" "Q", Ps
#define SEF(Ps1, Ps2) CSI "%d" ";" "%d" " " "Y", Ps1, Ps2
#define _SEF(Ps1) CSI "%d" ";" " " "Y", Ps1
#define __SEF(Ps2) CSI ";" "%d" " " "Y", Ps2
#define SGR(Ps) CSI "%d" "m", Ps
#define SHS(Ps) CSI "%d" " " "K", Ps
#define SIMD(Ps) CSI "%d" "^", Ps
#define SL(Pn) CSI "%d" " " "@", Pn
#define SLH(Pn) CSI "%d" " " "U", Pn
#define SLL(Pn) CSI "%d" " " "V", Pn
#define SLS(Pn) CSI "%d" " " "h", Pn
#define SM(Ps) CSI "%d" "h", Ps
#define SPD(Ps1, Ps2) CSI "%d" ";" "%d"  " " "S", Ps1, Ps2
#define _SPD(Ps1) CSI "%d" ";" " " "S", Ps1
#define __SPD(Ps2) CSI ";" "%d" " " "S", Ps2
#define SPH(Pn) CSI "%d" " " "i", Pn
#define SPI(Pn1, Pn2) CSI "%d" ";" "%d" " " "G", Pn1, Pn2
#define SPL(Pn) CSI "%d" " " "j", Pn
#define SPQR(Ps) CSI "%d" " " "X", Ps
#define SR(Pn) CSI "%d" " " "A", Pn
#define SRCS(Pn) CSI "%d" " " "f", Pn
#define SRS(Ps) CSI "%d" "[", Ps
#define SSU(Ps) CSI "%d" " " "I", Ps
#define SSW(Pn) CSI "%d" " " "[", Pn
#define STAB(Ps) CSI "%d" " " "^", Ps
#define SU(Pn) CSI "%d" "S", Pn
#define SVS(Ps) CSI "%d" " " "L", Ps
#define TAC(Pn) CSI "%d" " " "b", Pn
#define TALE(Pn) CSI "%d" " " "a", Pn
#define TATE(Pn) CSI "%d" " " "`", Pn
#define TBC(Ps) CSI "%d" "g", Ps
#define TCC(Pn1, Pn2) CSI "%d" ";" "%d" " " "c", Pn1, Pn2
#define _TCC(Pn1) CSI "%d" ";" " " "c", Pn1
#define TSR(Pn) CSI "%d" " " "d", Pn
#define TSS(Pn) CSI "%d" " " "E", Pn
#define VPA(Pn) CSI "%d" "d", Pn
#define VPB(Pn) CSI "%d" "k", Pn
#define VPR(Pn) CSI "%d" "e", Pn
