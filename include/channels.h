/*
 * Copyright (C) 2005 William Pitcock, et al.
 * Rights to this code are as documented in doc/LICENSE.
 *
 * Data structures for channel information.
 *
 * $Id: channels.h 3101 2005-10-22 13:59:52Z jilles $
 */

#ifndef CHANNELS_H
#define CHANNELS_H

typedef struct user_ user_t; /* XXX: Should be in users.h */
typedef struct channel_ channel_t;
typedef struct chanuser_ chanuser_t;
typedef struct chanban_ chanban_t;

struct channel_
{
  char *name;

  uint32_t modes;
  char *key;
  uint32_t limit;

  uint32_t nummembers;

  time_t ts;
  int32_t hash;

  char *topic;
  char *topic_setter;

  list_t members;
  list_t bans;

  time_t topicts; /* keep binary compatibility for now -- jilles */
};

/* struct for channel users */
struct chanuser_
{
  channel_t *chan;
  user_t *user;
  uint32_t modes;
};

struct chanban_
{
  channel_t *chan;
  char *mask;
};

#define CMODE_OP        0x00000020      /* SPECIAL */
#define CMODE_VOICE     0x00000200      /* SPECIAL */

#define CMODE_INVITE    0x00000001
#define CMODE_KEY       0x00000002
#define CMODE_LIMIT     0x00000004
#define CMODE_MOD       0x00000008
#define CMODE_NOEXT     0x00000010
#define CMODE_PRIV      0x00000040      /* AKA PARA */
#define CMODE_SEC       0x00000080
#define CMODE_TOPIC     0x00000100

#endif
