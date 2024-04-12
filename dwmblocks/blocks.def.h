//Modify this file to change what commands output to your statusbar, and recompile using the make command.

#define DATE		"$HOME/.dwm/scripts/getdate"
#define TIME		"$HOME/.dwm/scripts/gettime"
#define IP			"$HOME/.dwm/scripts/getip"
#define BAT			"$HOME/.dwm/scripts/getbatperc"
#define WTTR		"$HOME/.dwm/scripts/getwttr"
#define RAM			"$HOME/.dwm/scripts/getram"
#define CPU			"$HOME/.dwm/scripts/getcpu"
#define NETSPEED	"$HOME/.dwm/scripts/getnetspeed"


static const Block blocks[] = {
	/*Icon*/		/*Command*/			/*Update Interval*/			/*Update Signal*/
	{ " ",			IP,					3600,						0					},
	{ "",			NETSPEED,			60,							0					},
	{ "  ",		CPU,				10,							0					},
	{ "  ",		RAM,				10,							0					},
	{ "  ",		BAT,				60,							0					},
	{ "󰖐  ",		WTTR,				3600,						0					},
	{ "  ",		DATE,				1,							0					},
	{ "󱑂 ",			TIME,				1,							0					},
};

//sets delimiter between status commands. NULL character ('\0') means no delimiter.
static char delim[] = " | ";
static unsigned int delimLen = 5;

