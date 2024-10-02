/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 2;        /* border pixel of windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const unsigned int gappx     = 6;	/* gaps between windows */
static const unsigned int systraypinning = 0;   /* 0: sloppy systray follows selected monitor, >0: pin systray to monitor X */
static const unsigned int systrayonleft = 0;    /* 0: systray in the right corner, >0: systray on left of status text */
static const unsigned int systrayspacing = 2;   /* systray spacing */
static const int systraypinningfailfirst = 1;   /* 1: if pinning fails, display systray on the first monitor, False: display systray on the last monitor*/
static const int showsystray        = 1;        /* 0 means no systray */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const char *fonts[]          = { "monospace:size=10" };

//Deklaracja kolorów
static const char col_gray1[]       = "#2E3440";
static const char col_gray2[]       = "#3B4252";
static const char col_gray3[]       = "#D8DEE9";
static const char col_gray4[]       = "#ECEFF4";
static const char col_white[]	    = "#e5e9f0";
static const char col_cyan[]        = "#434C5E";

static const char *colors[][3]      = {
        [SchemeNorm] = { col_gray3, col_gray1, col_gray2 },
        [SchemeSel]  = { col_gray4, col_cyan,  col_white  },
};


/* tagging */
static const char *tags[] = { "", "", "", "", "", "","","", ""};

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      instance    title       tags mask     isfloating   monitor */
	{ "Gimp",     NULL,       NULL,       0,            1,           -1 },
};

/* layout(s) */
static const float mfact     	= 0.7; /* factor of master area size [0.05..0.95] */
static const int nmaster     	= 1;    /* number of clients in master area */
static const int resizehints 	= 0;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[][]=",    tilewide },
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ "[M]",      monocle },
	{ "[]=",      tile },    /* first entry is default */
	{ "|M|",      centeredmaster },
	{ ">M>",      centeredfloatingmaster },
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static const char *roficmd[] = { "rofi", "-show", "drun", "-show-icons", NULL };
static const char *termcmd[]  = { "alacritty", NULL };

/* Additional libraries */
#include <X11/XF86keysym.h>
#include "movestack.c"

static const char *upvol[]      = { "/usr/bin/amixer",  "set", "Master", "5%+", NULL };
static const char *downvol[]    = { "/usr/bin/amixer",  "set", "Master", "5%-", NULL };
static const char *mutevol[]    = { "/usr/bin/amixer",  "set", "Master", "toggle", NULL };
static const char *mutemic[]    = { "/usr/bin/amixer", "set", "Capture", "toggle", NULL };
static const char *brighup[]    = { "/usr/bin/brightnessctl", "set", "10%+", NULL };
static const char *brighdown[]  = { "/usr/bin/brightnessctl", "set", "10%-", NULL };
static const char *play[]       = { "/usr/bin/playerctl", "play-pause", "toggle", NULL };
static const char *next[]       = { "/usr/bin/playerctl", "next", "toggle", NULL };
static const char *previous[]   = { "/usr/bin/playerctl", "previous", "toggle", NULL };
static const char *display[]    = { "/home/kamil/Git/dwm-config/display.sh", NULL};

static const Key keys[] = {
	/* modifier                     key        	function        argument */
	{ MODKEY,                       XK_r,      	spawn,          {.v = roficmd } },
	{ MODKEY|ShiftMask,             XK_Return, 	spawn,          {.v = termcmd } },
	{ MODKEY,                       XK_b,      	spawn,          SHCMD ("firefox")},
	{ 0,                            0xff61,    	spawn,          SHCMD ("flameshot gui")},
        { MODKEY,                       XK_e,      	spawn,          SHCMD ("thunar")},
        { 0,                            0x1008ff59,     spawn,          SHCMD ("arandr")},
	{ MODKEY,                       XK_j,      	focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      	focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_i,      	incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_d,      	incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_h,      	setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,      	setmfact,       {.f = +0.05} },
 	{ MODKEY|ShiftMask,             XK_j,      	movestack,      {.i = +1 } },
 	{ MODKEY|ShiftMask,             XK_k,      	movestack,      {.i = -1 } },
	{ MODKEY,                       XK_Return, 	zoom,           {0} },
	{ MODKEY,                       XK_Tab,    	view,           {0} }, 
	{ MODKEY|ShiftMask,             XK_c,      	killclient,     {0} },
	{ MODKEY,                       XK_t,      	setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       XK_f,      	setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                       XK_m,      	setlayout,      {.v = &layouts[2]} },
	{ MODKEY|ShiftMask,             XK_t,      	setlayout,      {.v = &layouts[3]} },
	{ MODKEY,                       XK_y,      	setlayout,      {.v = &layouts[4]} },
	{ MODKEY,                       XK_u,      	setlayout,      {.v = &layouts[5]} },
	{ MODKEY,                       XK_space,  	setlayout,      {0} },
	{ MODKEY|ShiftMask,             XK_space,  	togglefloating, {0} },
	{ MODKEY,                       XK_0,      	view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      	tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_comma,  	focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, 	focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  	tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, 	tagmon,         {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_q, 		quit,           {0} },
	{ MODKEY,                       XK_q, 		spawn,          {.v = display } },
	{ 0,                     	0x1008ff11,     spawn, 		{.v = downvol } },
	{ 0,                       	0x1008ff13,     spawn, 		{.v = upvol   } },
	{ 0,                       	0x1008ff12,     spawn, 		{.v = mutevol } },
	{ 0,                       	0x1008ff12,     spawn, 		{.v = mutevol } },
        { 0,                            0x1008ffb2,     spawn,          {.v = mutemic } },
        { Mod1Mask,                     XK_m,           spawn,          {.v = mutemic } },
        { 0,                            0x1008ff02,     spawn,          {.v = brighup } },
        { 0,                            0x1008ff03,     spawn,          {.v = brighdown} },
	{ 0,                       	0x1008ff14,     spawn, 		{.v = play    } },
	{ 0,                       	0x1008ff17,     spawn, 		{.v = next    } },
	{ 0,                       	0x1008ff16,     spawn, 		{.v = previous} },
	TAGKEYS(                        XK_1,                      	0)
	TAGKEYS(                        XK_2,                      	1)
	TAGKEYS(                        XK_3,                      	2)
	TAGKEYS(                        XK_4,                      	3)
	TAGKEYS(                        XK_5,                      	4)
	TAGKEYS(                        XK_6,                      	5)
	TAGKEYS(                        XK_7,                      	6)
	TAGKEYS(                        XK_8,                      	7)
	TAGKEYS(                        XK_9,                      	8)
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static const Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
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
