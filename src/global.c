/*****************************************************************************
 * HTICK --- FTN Ticker / Request Processor
 *****************************************************************************
 * Copyright (C) 1999 by
 *
 * Gabriel Plutzar
 *
 * Fido:     2:31/1
 * Internet: gabriel@hit.priv.at
 *
 * Vienna, Austria, Europe
 *
 * This file is part of HTICK, which is based on HPT by Matthias Tichy, 
 * 2:2432/605.14 2:2433/1245, mtt@tichy.de
 *
 * HTICK is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2, or (at your option) any
 * later version.
 *
 * HTICK is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with HTICK; see the file COPYING.  If not, write to the Free
 * Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.
 *****************************************************************************/

#include <global.h>
#include <string.h>

s_log     *htick_log;
s_fidoconfig *config;

char *print_ch(int len, char ch)
{
    static char tmp[256];
    
    memset(tmp, ch, len);
    tmp[len]=0;
    return tmp;
}

const int VER_MAJOR = 0;
const int VER_MINOR = 9;

/* branch is "" for CVS current, "-stable" for the release candiate branch  */
const char *VER_BRANCH  = "-stable";

/* The service version string is empty for the first release done from a    */
/* release candidate branch.  If subsequent service releases are necessary, */
/* single letters are used, like "a", "b", ...                              */
const char *VER_SERVICE = "";  

char      versionStr[30];

int       cmToss = 0;
int       cmScan = 0;
int       cmHatch = 0;
int       hatchReplace = 0;
int       cmSend = 0;
int       cmFlist = 0;
int       cmClean = 0;

char      flistfile[256];

char      hatchfile[256];
char      hatcharea[256];
char      hatchdesc[256];
char      replaceMask[256];

char      sendfile[256];
char      sendarea[256];
char      sendaddr[256];

int       cmAnnounce = 0;
char      announceArea[256];

int       cmAnnFile = 0;
char      announcefile[256];

int       cmAnnNewFileecho = 0;
char      announcenewfileecho[256];

