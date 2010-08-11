#ifndef INLINE_HOSTSERV_H
#define INLINE_HOSTSERV_H
/*
 * do_sethost(user_t *u, char *host)
 *
 * Sets a virtual host on a single nickname/user.
 *
 * Inputs:
 *      - User to set a vHost on
 *      - a vHost
 * 
 * Outputs:
 *      - none
 *
 * Side Effects:
 *      - The vHost is set on the user.
 */
static inline void do_sethost(user_t *u, char *host)
{
        if (!strcmp(u->vhost, host ? host : u->host))
                return;
        strlcpy(u->vhost, host ? host : u->host, HOSTLEN);
        sethost_sts(hostsvs.me->me, u, u->vhost);
}

/*
 * do_sethost_all(myuser_t *mu, char *host)
 *
 * Sets a virtual host on all nicknames in an account.
 *
 * Inputs:
 *      - an account name
 *      - a vHost
 * 
 * Outputs:
 *      - none
 *
 * Side Effects:
 *      - The vHost is set on all users logged into
 *        the account.
 */
static inline void do_sethost_all(myuser_t *mu, char *host)
{
        node_t *n;
        user_t *u;

        LIST_FOREACH(n, mu->logins.head)
        {
                u = n->data;

                do_sethost(u, host);
        }
}
#endif
