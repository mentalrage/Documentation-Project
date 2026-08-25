// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028271
// validator-refreshed-at: 2026-08-25T19:07:41-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000MB
// Source by-file doc: by-file/PaletteLib.md
// UID:0000A1 | by-class/PaletteLib.md | Completion:93 | Confidence:94
#include "../util/LObject.h"
#include "../util/Singleton.h"
#include "../util/List.h"
#include "Palette.h"

struct PaletteLibLoadedEntry
{
    wchar_t *name;
    DLPalette *palette;
};

void __stdcall ApplyPaletteEntryMovesToCollection(List *palettes);

class PaletteLib : public LObject, public Singleton<PaletteLib>
{
public:
    PaletteLib();
    virtual ~PaletteLib();

    int GetScreenPaletteMode() const;
    void SetScreenPaletteMode(int mode);
    DLPalette *GetCurrentPalette();
    DLPalette *GetTextPalette();
    DLPalette *GetPaletteByName(const wchar_t *paletteName);
    DLPalette *GetSlotPalette(int slot, int paletteIndex, int superPaletteIndex);
    void ResetScreenPaletteSlots();
    bool SetPaletteFilterActive(bool active);
    float GetPaletteFilterWeight() const;
    void UpdatePaletteFilterTables(float weight);

private:
    int FindLoadedPaletteIndexByName(const wchar_t *paletteName) const;
    int LoadNamedPalette(const wchar_t *paletteName);
    List *LoadPaletteList(const wchar_t *paletteName);
    void LoadPaletteSet(int slot, const wchar_t *paletteName);

    int m_screenPaletteMode;
    List *m_loadedPalettes;
    DLPalette m_basePalette;
    DLPalette m_filteredBasePalette;
    DLPalette m_textPalette;
    List *m_sourcePaletteSets[25];
    List *m_runtimePaletteSets[25];
    bool m_useFilteredPalettes;
    float m_paletteFilterWeight;
    DLPalette m_superPalettes[7];
    DLPalette m_filteredSuperPalettes[7];
};

// UID:0000RW | by-global/g_pPaletteLib.md | Completion:92 | Confidence:94
extern PaletteLib *g_pPaletteLib;
