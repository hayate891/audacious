/*  Audacious - Cross-platform multimedia player
 *  Copyright (C) 2005-2007  Audacious development team
 *
 *  Based on BMP:
 *  Copyright (C) 2003-2004  BMP development team
 *
 *  Based on XMMS:
 *  Copyright (C) 1998-2003  XMMS development team
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; under version 2 of the License.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 */

#ifndef __AUDACIOUS_UI_URLOPENER_H__
#define __AUDACIOUS_UI_URLOPENER_H__

#ifdef _AUDACIOUS_CORE
# ifdef HAVE_CONFIG_H
#  include "config.h"
# endif
#endif

#include <glib.h>
#include <gtk/gtk.h>

G_BEGIN_DECLS

GtkWidget *util_add_url_dialog_new(const gchar * caption, GCallback ok_func,
                                   GCallback enqueue_func);

G_END_DECLS

#endif
