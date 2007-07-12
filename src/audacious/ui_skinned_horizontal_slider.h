/*
 * Audacious - a cross-platform multimedia player
 * Copyright (c) 2007  Audacious development team.
 *
 * Based on:
 * BMP - Cross-platform multimedia player
 * Copyright (C) 2003-2004  BMP development team.
 * XMMS:
 * Copyright (C) 1998-2003  XMMS development team.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; under version 2 of the License.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 */

#ifndef UISKINNEDHORIZONTAL_SLIDER_H
#define UISKINNEDHORIZONTAL_SLIDER_H

#include <gdk/gdk.h>
#include <gtk/gtkadjustment.h>
#include <gtk/gtkwidget.h>

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#define UI_SKINNED_HORIZONTAL_SLIDER(obj)          GTK_CHECK_CAST (obj, ui_skinned_horizontal_slider_get_type (), UiSkinnedHorizontalSlider)
#define UI_SKINNED_HORIZONTAL_SLIDER_CLASS(klass)  GTK_CHECK_CLASS_CAST (klass, ui_skinned_horizontal_slider_get_type (), UiSkinnedHorizontalSliderClass)
#define UI_SKINNED_IS_HORIZONTAL_SLIDER(obj)       GTK_CHECK_TYPE (obj, ui_skinned_horizontal_slider_get_type ())

typedef struct _UiSkinnedHorizontalSlider        UiSkinnedHorizontalSlider;
typedef struct _UiSkinnedHorizontalSliderClass   UiSkinnedHorizontalSliderClass;

struct _UiSkinnedHorizontalSlider {
    GtkWidget   widget;
    gboolean    pressed;
    gint        x, y;
};

struct _UiSkinnedHorizontalSliderClass {
    GtkWidgetClass    parent_class;
    void (* motion)   (UiSkinnedHorizontalSlider *horizontal_slider);
    void (* release)  (UiSkinnedHorizontalSlider *horizontal_slider);
    void (* doubled)  (UiSkinnedHorizontalSlider *horizontal_slider);
    void (* redraw)   (UiSkinnedHorizontalSlider *horizontal_slider);
};
GtkWidget* ui_skinned_horizontal_slider_new(GtkWidget *fixed, gint x, gint y, gint w, gint h, gint knx, gint kny,
                                            gint kpx, gint kpy, gint kw, gint kh, gint fh,
                                            gint fo, gint min, gint max, gint(*fcb) (gint), SkinPixmapId si);
GtkType ui_skinned_horizontal_slider_get_type(void);
void ui_skinned_horizontal_slider_set_position(GtkWidget *widget, gint pos);
gint ui_skinned_horizontal_slider_get_position(GtkWidget *widget);

#ifdef __cplusplus
}
#endif

#endif
