static void
tile(Monitor *m)
{
	unsigned int i, n;
	int mx = 0, my = 0, mh = 0, mw = 0;
	int sx = 0, sy = 0, sh = 0, sw = 0;
	float mfacts, sfacts;
	int mrest, srest;
	Client *c;


	for (n = 0, c = nexttiled(m->clients); c; c = nexttiled(c->next), n++);

	if (n == 0)
		return;

	sx = mx = m->wx;
	sy = my = m->wy;
	sh = mh = m->wh;
	sw = mw = m->ww;

	if (m->nmaster && n > m->nmaster) {
		sw = mw * (1 - m->mfact);
		mw = mw * m->mfact;
		sx = mx + mw;
	}

	getfacts(m, mh, sh, &mfacts, &sfacts, &mrest, &srest);

	for (i = 0, c = nexttiled(m->clients); c; c = nexttiled(c->next), i++)
		if (i < m->nmaster) {
			resize(c, mx, my, mw - (2*c->bw), (mh / mfacts) + (i < mrest ? 1 : 0) - (2*c->bw), 0);
			my += HEIGHT(c);
		} else {
			resize(c, sx, sy, sw - (2*c->bw), (sh / sfacts) + ((i - m->nmaster) < srest ? 1 : 0) - (2*c->bw), 0);
			sy += HEIGHT(c);
		}
}

