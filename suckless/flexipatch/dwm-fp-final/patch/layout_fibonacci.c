void
fibonacci(Monitor *m, int s)
{
	unsigned int i, n;
	int nx, ny, nw, nh;
	int nv, hrest = 0, wrest = 0, r = 1;
	Client *c;

	for (n = 0, c = nexttiled(m->clients); c; c = nexttiled(c->next), n++);
	if (n == 0)
		return;

	nx = m->wx;
	ny = m->wy;
	nw = m->ww;
	nh = m->wh;

	for (i = 0, c = nexttiled(m->clients); c; c = nexttiled(c->next)) {
		if (r) {
			if ((i % 2 && nh / 2 <= (bh + 2*c->bw))
			   || (!(i % 2) && nw / 2 <= (bh + 2*c->bw))) {
				r = 0;
			}
			if (r && i < n - 1) {
				if (i % 2) {
					nv = nh / 2;
					hrest = nh - 2*nv;
					nh = nv;
				} else {
					nv = nw / 2;
					wrest = nw - 2*nv;
					nw = nv;
				}

				if ((i % 4) == 2 && !s)
					nx += nw;
				else if ((i % 4) == 3 && !s)
					ny += nh;
			}

			if ((i % 4) == 0) {
				if (s) {
					ny += nh;
					nh += hrest;
				}
				else {
					nh -= hrest;
					ny -= nh;
				}
			}
			else if ((i % 4) == 1) {
				nx += nw;
				nw += wrest;
			}
			else if ((i % 4) == 2) {
				ny += nh;
				nh += hrest;
				if (i < n - 1)
					nw += wrest;
			}
			else if ((i % 4) == 3) {
				if (s) {
					nx += nw;
					nw -= wrest;
				} else {
					nw -= wrest;
					nx -= nw;
					nh += hrest;
				}
			}
			if (i == 0)	{
				if (n != 1) {
					nw = m->ww - m->ww * (1 - m->mfact);
					wrest = 0;
				}
				ny = m->wy;
			}
			else if (i == 1)
				nw = m->ww - nw;
			i++;
		}

		resize(c, nx, ny, nw - (2*c->bw), nh - (2*c->bw), False);
	}
}

static void
dwindle(Monitor *m)
{
	fibonacci(m, 1);
}

static void
spiral(Monitor *m)
{
	fibonacci(m, 0);
}

