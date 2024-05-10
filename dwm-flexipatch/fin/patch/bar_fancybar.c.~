int
width_fancybar(Bar *bar, BarArg *a)
{
	return a->w;
}

int
draw_fancybar(Bar *bar, BarArg *a)
{
	int tabw, mw, ew = 0, n = 0, tx, tw;
	unsigned int i;
	Client *c;
	Monitor *m = bar->mon;

	int x = a->x, w = a->w;

	for (c = m->clients; c; c = c->next) {
		if (ISVISIBLE(c))
			n++;
	}

	if (n > 0) {
		tabw = TEXTW(m->sel->name);
		mw = (tabw >= w || n == 1) ? 0 : (w - tabw) / (n - 1);

		i = 0;

		for (c = m->clients; c; c = c->next) {
			if (!ISVISIBLE(c) || c == m->sel)
				continue;
			tabw = TEXTW(c->name);
			if (tabw < mw)
				ew += (mw - tabw);
			else
				i++;
		}

		if (i > 0)
			mw += ew / i;

		for (c = m->clients; c; c = c->next) {
			if (!ISVISIBLE(c))
				continue;
			tabw = MIN(m->sel == c ? w : mw, TEXTW(c->name));
			tx = x;
			tw = tabw;
			drw_setscheme(drw, scheme[m->sel == c ? SchemeTitleSel : SchemeTitleNorm]);

			XSetForeground(drw->dpy, drw->gc, drw->scheme[ColBg].pixel);
			XFillRectangle(drw->dpy, drw->drawable, drw->gc, tx, a->y, tw, a->h);

			if (tabw <= 0) /* trap special handling of 0 in drw_text */
				continue;

			tx += lrpad / 2;
			tw -= lrpad;


			drw_text(drw, tx, a->y, tw, a->h, 0, c->name, 0, False);
			drawstateindicator(c->mon, c, 1, x, a->y, tabw, a->h, 0, 0, c->isfixed);
			x += tabw;
			w -= tabw;
		}
	}
	return n;
}

int
click_fancybar(Bar *bar, Arg *arg, BarArg *a)
{
	return ClkWinTitle;
}

