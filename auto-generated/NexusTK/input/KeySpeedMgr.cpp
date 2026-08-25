// AUTO-GENERATED FROM project-documentation validator autogen. DO NOT EDIT BY HAND.
// validator-command-id: 000000028271
// validator-refreshed-at: 2026-08-25T19:07:41-04:00
// validator-refresh-source: foreground-generated-refresh
// Source by-file UID: 0000KJ
// Source by-file doc: by-file/KeySpeedMgr.md
// UID:00006Z | by-class/KeySpeedMgr.md | Completion:88 | Confidence:91
#include "KeySpeedMgr.h"

// UID:0002IP | by-memory/0x004efea0-0x004efedd.KeySpeedMgrConstructor.md | Completion:88 | Confidence:92
KeySpeedMgr::KeySpeedMgr()
{
    g_pKeySpeedMgr = this;
    m_savedKeyboardDelay = UINT(-1);
    m_savedKeyboardSpeed = UINT(-1);
}

// UID:0002IQ | by-memory/0x004efee0-0x004efef5.KeySpeedMgrDestructor.md | Completion:87 | Confidence:92
KeySpeedMgr::~KeySpeedMgr()
{
    g_pKeySpeedMgr = 0;
}

// UID:0002IR | by-memory/0x004eff00-0x004eff25.KeySpeedMgrLoadSystemKeyboardSettings.md | Completion:87 | Confidence:92
void KeySpeedMgr::LoadSystemKeyboardSettings()
{
    SystemParametersInfoW(SPI_GETKEYBOARDDELAY, 0, &m_savedKeyboardDelay, 0);
    SystemParametersInfoW(SPI_GETKEYBOARDSPEED, 0, &m_savedKeyboardSpeed, 0);
}

// UID:00018P | by-memory/0x004eff30-0x004eff5d.KeySpeedMgrRestoreSystemKeyboardSettings.md | Completion:88 | Confidence:92
void KeySpeedMgr::RestoreSystemKeyboardSettings()
{
    if (m_savedKeyboardDelay <= 3) {
        ::SystemParametersInfoW(SPI_SETKEYBOARDDELAY, m_savedKeyboardDelay, 0, SPIF_UPDATEINIFILE);
    }

    if (m_savedKeyboardSpeed <= 31) {
        ::SystemParametersInfoW(SPI_SETKEYBOARDSPEED, m_savedKeyboardSpeed, 0, SPIF_UPDATEINIFILE);
    }
}

// UID:0002IT | by-memory/0x004effc0-0x004f0008.KeySpeedMgrScalarDeletingDestructor.md | Completion:86 | Confidence:91
// Compiler-generated scalar deleting destructor for KeySpeedMgr; source is KeySpeedMgr::~KeySpeedMgr().




// UID:0000RB | by-global/g_pKeySpeedMgr.md | Completion:89 | Confidence:91
KeySpeedMgr *g_pKeySpeedMgr = 0;

// UID:0002IS | by-memory/0x004eff60-0x004eff91.KeySpeedMgrApplyKeyboardRepeatSettingsRaw.md | Completion:87 | Confidence:91
static void __stdcall ApplyKeyboardRepeatSettings(UINT delay, UINT speed)
{
    if (delay <= 3) {
        ::SystemParametersInfoW(SPI_SETKEYBOARDDELAY, delay, 0, SPIF_UPDATEINIFILE);
    }

    if (speed <= 31) {
        ::SystemParametersInfoW(SPI_SETKEYBOARDSPEED, speed, 0, SPIF_UPDATEINIFILE);
    }
}

// UID:00018Q | by-memory/0x004effa0-0x004effbd.ApplyFastKeyboardRepeatSettings.md | Completion:88 | Confidence:92
static void ApplyFastKeyboardRepeatSettings()
{
    ::SystemParametersInfoW(SPI_SETKEYBOARDDELAY, 0, 0, SPIF_UPDATEINIFILE);
    ::SystemParametersInfoW(SPI_SETKEYBOARDSPEED, 31, 0, SPIF_UPDATEINIFILE);
}

// UID:00031P | by-memory\0x0061c9c4-0x0061c9d4.KeySpeedMgrVtableData.md | Completion:88 | Confidence:92 | Empty Emitter Marker

// UID:0001UV | by-type\by-struct\KeySpeedMgrLayout.md | Completion:88 | Confidence:91 | Empty Emitter Marker

// UID:0001XX | by-type\by-vtable\KeySpeedMgrVtable.md | Completion:86 | Confidence:90 | Empty Emitter Marker
