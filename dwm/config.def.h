#include <X11/XF86keysym.h>
/*See LICENSE file for copyright and license details. */
// THIS IS A CHANGE
/* appearance */
static const unsigned int borderpx  = 2;        /* border pixel of windows */
static const unsigned int gappx     = 0;        /* gaps between windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const unsigned int gappih    = 10;       /* horiz inner gap between windows */
static const unsigned int gappiv    = 10;       /* vert inner gap between windows */
static const unsigned int gappoh    = 10;       /* horiz outer gap between windows and screen edge */
static const unsigned int gappov    = 10;       /* vert outer gap between windows and screen edge */
static       int smartgaps          = 0;        /* 1 means no outer gap when there is only one window */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const int splitstatus        = 0;        /* 1 for split status items */
static const char *splitdelim        = " | ";       /* Character used for separating status */
// static const char *fonts[]          = { "Hack Nerd Font:size=12" };
static const char *fonts[]          = { "Roboto Mono Nerd Font:size=12", "fontawesome:size=12" };
static const char dmenufont[]       = "Roboto Mono Nerd Font:size=12";

// #include "color_schemes/default_one.h"
#include "color_schemes/gruv.h"

static const unsigned int baralpha = 140;
static const unsigned int borderalpha = 140;

static const char *colors[][3]      = {
	/*               fg         bg         border   */
	[SchemeNorm] = { col_gray3, col_gray1, col_gray2 },
	[SchemeSel]  = { col_gray4, col_cyan,  col_gray4 },
};

static const unsigned int alphas[][3]      = {
	/*               fg      bg        border     */
	[SchemeNorm] = { OPAQUE, baralpha, borderalpha },
	[SchemeSel]  = { OPAQUE, baralpha, borderalpha },
};

/* tagging */
// static const char *tags[] = { "", "", "", "", "󰑴", "󰇧", "", "", "", "", "󰶵", "󰮯", "", "󱍢" };
// static const char *tags[] = { "", "", "", "", "", "󰈹", };
static const char *tags[] = { "󰋜","", "󰮯", "", "", "" };
// static const char *tags[] = { "", "", "󰚩", "", "󰂺", "", "", "", "", "", "", "", };
// static const char *tags[] = { "", "󰣇", "󰈹", "󰂺", "", "", "󰚩", "󰌪", "" };
// static const char *tags[] = { "", "", "", "󰻀", "", "󰑴", "󰇧", "󰈹", "󰀼", "󰣇", "", "󰲓", "󰌪", "" };
// static const char *tags[] = { "󰈹", "󰣇", "󰻀", "", "", "󰀼", "󰌪", "" };

static const unsigned int ulinepad	= 5;	/* horizontal padding between the underline and tag */
static const unsigned int ulinestroke	= 2;	/* thickness / height of the underline */
static const unsigned int ulinevoffset	= 0;	/* how far above the bottom of the bar the line should appear */
static const int ulineall 		= 0;	/* 1 to show underline on all tags, 0 for just the active ones */

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      instance    title       tags mask     isfloating   monitor */
	{ "Gimp",     NULL,       NULL,       0,            1,           -1 },
	{ "Firefox",  NULL,       NULL,       1 << 8,       0,           -1 },
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 0;    /* 1 means respect size hints in tiled resizals */
static const int attachbelow = 1;    /* 1 means attach after the currently active window */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */

#define FORCE_VSPLIT 1  /* nrowgrid layout: force two clients to always split vertically */
#include "vanitygaps.c"

#include "fibonacci.c"

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile                   },    /* first entry is default */
	{ "><>",      NULL                   },    /* no layout function means floating behavior */
	{ "[M]",      monocle                },    /*  */
	{ "|M|",      centeredmaster         },    /*  */
	{ ">M>",      centeredfloatingmaster },    /*  */
	{ "(@)",      spiral                 },    /* fibonacci - spiral  */
	{ "[\\]",     dwindle                },    /* fibonacci - dwindle */
};

/* key definitions */
#define MODKEY Mod1Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
// brightness commands
//static const char *light_up[]   = { "light", "-A", "5", NULL };
//static const char *light_down[] = { "light", "-U", "5", NULL };

static const char *light_up[]   = { "brightnessctl", "set", "5%+", NULL };
static const char *light_down[] = { "brightnessctl", "set", "5%-", NULL };

// audio commands
static const char *audio_up[]   = { "amixer", "set", "Master", "5%+",    NULL };
static const char *audio_down[] = { "amixer", "set", "Master", "5%-",    NULL };

//static const char *audio_up[]   = { "amixer", "-D", "pulse", "sset", "Master", "5%+", NULL };
//static const char *audio_down[] = { "amixer", "-D", "pulse", "sset", "Master", "5%-", NULL };

#define DEF_TERM	"alacritty"
#define DEF_BROWSER	"firefox"
#define DEF_PRVTWIN	"firefox --private-window"
#define DEF_EC		"thunderbird"
#define DEF_FM		"ranger"
#define DEF_NOTE	"nb edit note.md"
#define DEF_TODO	"nb edit todo.md"
#define DEF_LOCK	"slock"
#define NCMD_PATH	"/home/karim/.dwm/scripts/notecmd"
#define RWP_PATH	"/home/karim/.dwm/scripts/refreshwp.sh"

static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", col_gray1, "-nf", col_gray3, "-sb", col_cyan, "-sf", col_gray4, NULL };
static const char *termcmd[] = { DEF_TERM, NULL };
static const char *browsercmd[] = { DEF_BROWSER, NULL };
static const char *prvtwincmd[] = { DEF_PRVTWIN, NULL };
static const char *eccmd[] = { DEF_EC, NULL };
static const char *prtscrcmd[] = { "flameshot", "gui", NULL};
static const char *refreshwpcmd[] = { RWP_PATH, NULL };
static const char *fmcmd[] = { DEF_TERM, "-e", DEF_FM, NULL };
static const char *lockcmd[] = { DEF_LOCK, NULL };
static const char *notecmd[] = { DEF_TERM, "-e", DEF_NOTE, NULL};
static const char *todocmd[] = { DEF_TERM, "-e", DEF_TODO, NULL};
// static const char *notecmd[] = { NCMD_PATH, NULL};

#include "movestack.c"
static Key keys[] = {
	/* modifier                     key        function        argument */
	{ MODKEY,                       XK_p,      spawn,          {.v = dmenucmd } },
	{ MODKEY|ShiftMask,             XK_Return, spawn,          {.v = termcmd } },
	{ Mod4Mask,                     XK_l,      spawn,          {.v = lockcmd } },
	{ MODKEY,                       XK_e,      spawn,          {.v = eccmd } },
	{ MODKEY,                       XK_w,      spawn,          {.v = browsercmd } },
	{ MODKEY|ShiftMask,             XK_p,      spawn,          {.v = prvtwincmd } },
	{ MODKEY|ShiftMask,             XK_w,      spawn,          {.v = refreshwpcmd } },
	{ MODKEY|ShiftMask,             XK_f,      spawn,          {.v = fmcmd } },
	{ MODKEY|ShiftMask,             XK_n,      spawn,          {.v = notecmd } },
	{ MODKEY|ShiftMask,             XK_d,      spawn,          {.v = todocmd } },
	{ MODKEY,                       XK_b,      togglebar,      {0} },
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_d,      incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
	{ MODKEY|ShiftMask,             XK_j,      movestack,      {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_k,      movestack,      {.i = -1 } },
	{ MODKEY,                       XK_Return, zoom,           {0} },
	{ MODKEY|ShiftMask,             XK_h,      setcfact,       {.f = +0.25} }, // increase all gaps
	{ MODKEY|ShiftMask,             XK_l,      setcfact,       {.f = -0.25} }, // decrease all gaps
	{ MODKEY|Mod4Mask,              XK_0,      togglegaps,     {0} }, // toggle gaps on and off
	{ MODKEY|Mod4Mask|ShiftMask,    XK_0,      defaultgaps,    {0} }, // reset gaps back to default
	{ MODKEY,                       XK_Tab,    view,           {0} },
	{ MODKEY|ShiftMask,             XK_c,      killclient,     {0} },
	{ MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       XK_f,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                       XK_m,      setlayout,      {.v = &layouts[2]} },
//	{ MODKEY,                       XK_u,      setlayout,      {.v = &layouts[3]} },
	{ MODKEY|ShiftMask,             XK_o,      setlayout,      {.v = &layouts[3]} },
	{ MODKEY,                       XK_o,      setlayout,      {.v = &layouts[4]} },
	{ MODKEY,                       XK_r,      setlayout,      {.v = &layouts[5]} },
	{ MODKEY|ShiftMask,             XK_r,      setlayout,      {.v = &layouts[6]} },
	{ MODKEY,                       XK_space,  setlayout,      {0} },
	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
	{ MODKEY|ShiftMask,             XK_q,      quit,           {0} },
  	{ 0,			        XK_Print,                 spawn, { .v = prtscrcmd  } },
  	{ 0,                            XF86XK_MonBrightnessUp,   spawn, { .v = light_up   } },
  	{ 0,                            XF86XK_MonBrightnessDown, spawn, { .v = light_down } },
  	{ 0,                            XF86XK_AudioRaiseVolume,  spawn, { .v = audio_up   } },
  	{ 0,                            XF86XK_AudioLowerVolume,  spawn, { .v = audio_down } },
//	{ 0,                            XF86XK_AudioMute,         spawn, SHCMD("$HOME/.dwm/scripts/audio_tgl.sh") },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};
