typedef struct{
	unsigned char MAC[6];	// 6 bytes of MAC address of AP
	int channel;			// channel number 1 to 13
	double frequency;		// frequency of this channel
	char essid[100];		// ESSID of the network
	double slevel;			// signal level in dBm
}WIFI_INFO;

#define CMD "sudo iwlist wlan0 scan | egrep \"Address|Frequency|ESSID|Quality\" > scan.txt"

// function prototypes
void read_data(void);