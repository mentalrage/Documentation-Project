// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028271
// validator-refreshed-at: 2026-08-25T19:07:41-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000MB
// Source by-file doc: by-file/PaletteLib.md
// UID:0002ZD | by-memory/0x0066dee8-0x0066df00.SuperPaletteFilenameBuffer.md | Completion:90 | Confidence:94
static wchar_t s_superPaletteFilename[] = L"SUPER0.PAL";

// UID:0000A1 | by-class/PaletteLib.md | Completion:93 | Confidence:94
// UID:0003MT | by-memory/0x00543150-0x005431b9.PaletteLibFindLoadedPaletteIndexRaw.md | Completion:94 | Confidence:95
int PaletteLib::FindLoadedPaletteIndexByName(const wchar_t *paletteName) const
{
    int count = m_loadedPalettes->GetCount();

    for (int index = 0; index < count; ++index) {
        PaletteLibLoadedEntry *entry = static_cast<PaletteLibLoadedEntry *>(
            m_loadedPalettes->GetElementAt(index));

        if (wcscmp(paletteName, entry->name) == 0)
            return index;
    }

    return -1;
}

// UID:0001E8 | by-memory/0x00543d30-0x00543f54.ScreenPanePaletteState.md | Completion:92 | Confidence:94
void PaletteLib::SetScreenPaletteMode(int mode)
{
    m_screenPaletteMode = mode;
}

void PaletteLib::ResetScreenPaletteSlots()
{
    for (int index = m_loadedPalettes->GetCount() - 1; index >= 0; --index) {
        PaletteLibLoadedEntry *entry = static_cast<PaletteLibLoadedEntry *>(
            m_loadedPalettes->GetElementAt(index));
        entry->palette->ApplyPaletteEntryMoves();
    }

    List **paletteSets = g_pConfig->m_shadowEnabled
        ? m_sourcePaletteSets
        : m_runtimePaletteSets;

    for (int slot = 0; slot < 25; ++slot)
        ApplyPaletteEntryMovesToCollection(paletteSets[slot]);
}

// UID:0001E9 | by-memory/0x00543f60-0x005440f0.PaletteLibPaletteFilterHelpers.md | Completion:91 | Confidence:91
bool PaletteLib::SetPaletteFilterActive(bool active)
{
    m_useFilteredPalettes = active;
    return active;
}

float PaletteLib::GetPaletteFilterWeight() const
{
    return m_paletteFilterWeight;
}

void PaletteLib::UpdatePaletteFilterTables(float weight)
{
    if (weight == m_paletteFilterWeight) {
        return;
    }

    m_paletteFilterWeight = weight;

    const unsigned char strength = static_cast<unsigned char>((weight * 32.0f) + 0.5f);

    for (int color = 1; color < 256; ++color) {
        m_filteredBasePalette.m_mappedColors[color] =
            g_pfnTransformPaletteColor(m_basePalette.m_mappedColors[color], strength);
    }

    for (int paletteIndex = 0; paletteIndex < 7; ++paletteIndex) {
        DLPalette& sourcePalette = m_superPalettes[paletteIndex];
        DLPalette& filteredPalette = m_filteredSuperPalettes[paletteIndex];

        for (int color = 1; color < 256; ++color) {
            filteredPalette.m_mappedColors[color] =
                g_pfnTransformPaletteColor(sourcePalette.m_mappedColors[color], strength);
        }
    }

    for (int slot = 0; slot < 25; ++slot) {
        if (slot == 11) {
            continue;
        }

        List* sourceList = m_sourcePaletteSets[slot];
        List* filteredList = m_runtimePaletteSets[slot];
        const int count = sourceList->GetCount();

        for (int index = 0; index < count; ++index) {
            DLPalette* sourcePalette = *reinterpret_cast<DLPalette**>(sourceList->GetAt(index));
            DLPalette* filteredPalette = *reinterpret_cast<DLPalette**>(filteredList->GetAt(index));

            for (int color = 1; color < 256; ++color) {
                filteredPalette->m_mappedColors[color] =
                    g_pfnTransformPaletteColor(sourcePalette->m_mappedColors[color], strength);
            }
        }
    }
}

// UID:0000RW | by-global/g_pPaletteLib.md | Completion:92 | Confidence:94
PaletteLib *g_pPaletteLib = 0;

// UID:00028T | by-memory/0x0067a7e0-0x0067a7e4.g_pPaletteLib.md | Completion:92 | Confidence:94
// Exact storage for g_pPaletteLib at 0x0067a7e0.
// The source definition is emitted by [UID:0000RW][g_pPaletteLib](by-global/g_pPaletteLib.md);
// do not duplicate the pointer definition from this storage child.
