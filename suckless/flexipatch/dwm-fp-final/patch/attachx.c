void
attachx(Client *c)
{


	if (!(c->mon->sel == NULL || c->mon->sel == c || c->mon->sel->isfloating)) {
		c->next = c->mon->sel->next;
		c->mon->sel->next = c;
		return;
	}
	attach(c); // master (default)
}

