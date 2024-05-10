//Modify this file to change what commands output to your statusbar, and recompile using the make command.

#define DATE		"$HOME/scripts/dwmblocks/date"
#define TIME		"$HOME/scripts/dwmblocks/time"
#define IP			"$HOME/scripts/dwmblocks/ip"
#define BAT			"$HOME/scripts/dwmblocks/batperc"
#define WTTR		"$HOME/scripts/dwmblocks/wttr"
#define RAM			"$HOME/scripts/dwmblocks/ram"
#define CPU			"$HOME/scripts/dwmblocks/cpu"
#define NETSPEED	"$HOME/scripts/dwmblocks/netspeed"
#define AUDIO		"$HOME/scripts/dwmblocks/audio"
#define BRIGHT		"$HOME/scripts/dwmblocks/bright"
#define SCRNTIME	"$HOME/scripts/screentime/get"


static const Block blocks[] = {
	/*Icon*/		/*Command*/			/*Update Interval*/		/*Update Signal*/
	{ "",			WTTR,				3600,					0					},
	{ "",			CPU,				1,					0					},
	{ "",			RAM,				1,					0					},
	{ "",			SCRNTIME,			60,						0					},
	{ "",			BRIGHT,				0,						20					},
	{ "",			AUDIO,				0,						21					},
	{ "",			BAT,				30,						0					},
	{ "",			DATE,				1,						0					},
	{ "",			TIME,				1,						0					},
};

//sets delimiter between status commands. NULL character ('\0') means no delimiter.
static char delim[] = "  |  ";
static unsigned int delimLen = 5;

