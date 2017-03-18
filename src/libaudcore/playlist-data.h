/*
 * playlist-data.h
 * Copyright 2017 John Lindgren
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions, and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions, and the following disclaimer in the documentation
 *    provided with the distribution.
 *
 * This software is provided "as is" and without any warranty, express or
 * implied. In no event shall the authors be liable for any damages arising from
 * the use of this software.
 */

#ifndef PLAYLIST_DATA_H
#define PLAYLIST_DATA_H

#include "playlist.h"

class TupleCompiler;

struct PlaylistEntry
{
    PlaylistEntry (PlaylistAddItem && item);
    ~PlaylistEntry ();

    void format ();
    void set_tuple (Tuple && new_tuple);

    static void update_formatting ();
    static void cleanup ();

    String filename;
    PluginHandle * decoder;
    Tuple tuple;
    String error;
    int number;
    int length;
    int shuffle_num;
    bool selected, queued;

private:
    static TupleCompiler s_compiler;
    static bool s_use_fallbacks;
};

struct PlaylistData
{
    /* update flags */
    enum {
        QueueChanged  = (1 << 0),
        DelayedUpdate = (1 << 1)
    };

    /* scan status */
    enum ScanStatus {
        NotScanning,
        ScanActive,
        ScanEnding
    };

    struct CompareData {
        Playlist::StringCompareFunc filename_compare;
        Playlist::TupleCompareFunc tuple_compare;
    };

    PlaylistData (Playlist::ID * m_id, const char * title);
    ~PlaylistData ();

    void set_entry_tuple (PlaylistEntry * entry, Tuple && tuple);
    void number_entries (int at, int length);

    PlaylistEntry * lookup_entry (int i);
    const PlaylistEntry * lookup_entry (int i) const;

    void queue_update (Playlist::UpdateLevel level, int at, int count, int flags = 0);
    void cancel_updates ();
    void swap_updates ();

    void insert_items (int at, Index<PlaylistAddItem> && items);
    void remove_entries (int at, int number, bool & position_changed);

    bool entry_selected (int entry_num) const;
    int n_selected (int at, int number) const;

    void select_entry (int entry_num, bool selected);
    void select_all (bool selected);
    int shift_entries (int entry_num, int distance);
    void remove_selected (bool & position_changed, int & next_song_hint);

    void sort (const CompareData & data);
    void sort_selected (const CompareData & data);

    void reverse_order ();
    void randomize_order ();
    void reverse_selected ();
    void randomize_selected ();

    void set_position (PlaylistEntry * entry, bool update_shuffle);
    PlaylistEntry * find_unselected_focus ();

    Playlist::ID * id () const { return m_id; }
    int n_entries () const { return entries.len (); }

    const Playlist::Update & last_update () const { return m_last_update; }
    bool update_pending () const { return m_next_update.level != Playlist::NoUpdate; }

    Playlist::ID * m_id;
    bool modified;
    ScanStatus scan_status;
    String filename, title;
    Index<SmartPtr<PlaylistEntry>> entries;
    PlaylistEntry * position, * focus;
    int selected_count;
    int last_shuffle_num;
    Index<PlaylistEntry *> queued;
    int64_t total_length, selected_length;
    Playlist::Update m_last_update, m_next_update;
    int resume_time;
};

/* callbacks or "signals" (in the QObject sense) */
void pl_signal_entry_deleted (PlaylistEntry * entry);
void pl_signal_update_queued (Playlist::ID * id, Playlist::UpdateLevel level, int flags);
void pl_signal_playlist_deleted (Playlist::ID * id);

#endif // PLAYLIST_DATA_H