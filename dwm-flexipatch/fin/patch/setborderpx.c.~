void
setborderpx(const Arg *arg)
{
	Client *c;
	Monitor *m = selmon;
	int prev_borderpx = m->borderpx;
	m->borderpx = arg->i
		? MAX(m->borderpx + arg->i, 0)
		: m->borderpx == borderpx
		? 0
		: borderpx;
	int delta = 2 * (m->borderpx - prev_borderpx);


	for (c = m->clients; c; c = c->next) {
		c->bw = m->borderpx;
		if (c->isfullscreen)
			continue;
		if (!c->isfloating && m->lt[m->sellt]->arrange)
			continue;

		resizeclient(c, c->x, c->y, c->w - delta, c->h - delta);
	}
	arrange(m);
}
