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

#ifndef UTIL_H
#define UTIL_H

#ifdef _AUDACIOUS_CORE
# ifdef HAVE_CONFIG_H
#  include "config.h"
# endif
#endif

#include <glib.h>
#include <gtk/gtk.h>

G_BEGIN_DECLS

#define SWAP(a, b)      { a^=b; b^=a; a^=b; }

typedef gboolean(*DirForeachFunc) (const gchar * path,
                                   const gchar * basename,
                                   gpointer user_data);


gchar *find_file_recursively(const gchar * dirname, const gchar * file);
void del_directory(const gchar * dirname);
gboolean dir_foreach(const gchar * path, DirForeachFunc function,
                     gpointer user_data, GError ** error);

gchar *read_ini_string(const gchar * filename, const gchar * section,
                       const gchar * key);
GArray *read_ini_array(const gchar * filename, const gchar * section,
                       const gchar * key);

GArray *string_to_garray(const gchar * str);

void glist_movedown(GList * list);
void glist_moveup(GList * list);

void util_menu_position(GtkMenu * menu, gint * x, gint * y,
                        gboolean * push_in, gpointer data);

GdkFont *util_font_load(const gchar * name);
void util_set_cursor(GtkWidget * window);
gboolean text_get_extents(const gchar * fontname, const gchar * text,
                          gint * width, gint * height, gint * ascent,
                          gint * descent);

gboolean file_is_archive(const gchar * filename);
gchar *archive_decompress(const gchar * path);
gchar *archive_basename(const gchar * path);

guint gint_count_digits(gint n);


#if ENABLE_NLS
gchar *bmp_menu_translate(const gchar * path, gpointer func_data);
#else
#  define bmp_menu_translate NULL
#endif

GtkWidget *make_filebrowser(const gchar * title,
                            gboolean save);

typedef struct {
    gint x;
    gint y;
} MenuPos;


GdkPixmap *audacious_pixmap_resize(GdkWindow *src, GdkGC *src_gc, GdkPixmap *in, gint width, gint height);

/* XMMS names */

#define bmp_info_dialog(title, text, button_text, model, button_action, action_data) \
  xmms_show_message(title, text, button_text, model, button_action, action_data)

#define bmp_usleep(usec) \
  xmms_usleep(usec)

#define bmp_check_realtime_priority() \
  xmms_check_realtime_priority()

GtkWidget *xmms_show_message(const gchar * title, const gchar * text,
                             const gchar * button_text, gboolean modal,
                             GtkSignalFunc button_action,
                             gpointer action_data);
gboolean xmms_check_realtime_priority(void);
void xmms_usleep(gint usec);

GdkImage *create_dblsize_image(GdkImage * img);

gchar *xmms_urldecode_path(const gchar * encoded_path);

GdkPixbuf *audacious_create_colorized_pixbuf(GdkPixbuf *src, gint red, gint green, gint blue);

gchar *audacious_get_localdir(void);

void audacious_menu_main_show( gint x , gint y , guint button , guint time );

G_END_DECLS

#endif
