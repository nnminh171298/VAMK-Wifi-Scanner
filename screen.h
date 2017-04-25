// includes the function prototypes for screen manipulation
enum COLOR{RED = 31, GREEN, YELLOW, BLUE, MAGENTA, CYAN, WHITE};
#define UNICODE
#define VER "\u2503"	//unicode for a bar
#define HOR "\u2501"
#define COR "\u254B"

// function prototypes
void setFGcolor(int fg);
void resetColors(void);
void gotoXY(int row, int col);
void displayBar(char *, double, int);
void displayBack(void);
void clearScreen(void);
