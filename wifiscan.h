typedef struct{
	unsigned char MAC[6];	// 6 bytes of MAC address of AP
	int channel;			// channel number 1 to 13
	double frequency;		// frequency of this channel
	char essid[100];		// ESSID of the network
	int slevel;			// signal level in dBm
}WIFI_INFO;

#define CMD "sudo iwlist wlan0 scan | egrep \"Address|Frequency|ESSID|Quality\" > scan.txt"
#define DEBUG 1

// function prototypes
int read_data(void);
void remove_spaces(char *);
void get_MAC(char *, unsigned char*);
double get_freq(char *);
int get_slevel(char *);
void get_essid(char *, char *);