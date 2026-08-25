// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028253
// validator-refreshed-at: 2026-08-25T17:55:53-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000L2
// Source by-file doc: by-file/MapNamePane.md
// UID:00007P | by-class/MapNamePane.md | Completion:94 | Confidence:95
#ifndef NEXUSTK_MAP_MAPNAMEPANE_H
#define NEXUSTK_MAP_MAPNAMEPANE_H

#include "../render/EPFTileContext.h"
#include "../ui/core/Pane.h"
#include "../util/Singleton.h"

class Event;

class MapNamePane : public Pane, public Singleton<MapNamePane>
{
public:
    MapNamePane();
    virtual ~MapNamePane();

protected:
    virtual void OnPaint();
    virtual bool HandlePacketEvent(Event *event);

private:
    void DrawNumberGlyphString(
        const wchar_t *text, int x, int y, signed char glyphRow);

    wchar_t m_mapNameText[128];
    EPFTileContext m_mapNameImage;
    unsigned char *m_mapNameGlyphs;
};

extern MapNamePane *g_pMapNamePane;

typedef char MapNamePaneSizeMustBe548[
    sizeof(MapNamePane) == 0x224 ? 1 : -1];

#endif
