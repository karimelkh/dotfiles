/* user and group to drop privileges to */
static const char *user  = "karim";
static const char *group = "karim";

static const char *colorname[NUMCOLS] = {
	[INIT] =   "black",     /* after initialization */
	[INPUT] =  "#005577",   /* during input */
	[FAILED] = "#CC3333",   /* wrong password */
	[CAPS] = "#551A8B",     /* CapsLock on */
};

/* treat a cleared input like a wrong password (color) */
static const int failonclear = 0;

/* Background image path, should be available to the user above */
static const char* background_image = "/home/karim/.local/share/backgrounds/waves.png";
