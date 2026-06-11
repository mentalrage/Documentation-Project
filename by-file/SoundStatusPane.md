*** UID:0000NX | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:84 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/panels/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# SoundStatusPane

## Status

- Confidence: strong for class/file role, medium for exact base-class naming.
- Proposed module: `ui/panels/SoundStatusPane.cpp`
- Projected reconstruction path: `NexusTK/ui/panels/SoundStatusPane.cpp`
- Main class: [UID:0000DJ][SoundStatusPane](by-class/SoundStatusPane.md)
- Main address doc: [UID:0001IG][0x0057bf70-0x0057c2cf.SoundStatusPane](by-memory/0x0057bf70-0x0057c2cf.SoundStatusPane.md)
- Singleton global: [UID:0000SB][g_pSoundStatusPane](by-global/g_pSoundStatusPane.md)
- Evidence basis: live IDA MCP decompilation, caller, and xref checks on 2026-05-24 and 2026-05-30.

## File Role

`SoundStatusPane.cpp` owns the small in-game sound/music status pane and its keyboard shortcuts. It is created by `InitializeMainUiGraph` in both the newer and older main UI layouts, computes a bottom-right position from current screen dimensions, toggles sound and music state through [UID:0000NV][SoundManager](by-file/SoundManager.md), and formats the visible `Sound On/Off` plus `Music On/Off` caption.

This should remain a UI panel source, not part of `audio/SoundManager.cpp`. `SoundManager` owns playback and resource policy; this file owns the HUD status/control surface over that audio state.

## Proposed Contents

| Entity | Address evidence | Role |
| --- | --- | --- |
| `SoundStatusPane` | `0x0057bf70-0x0057c2cf` | Constructor, virtual hotkey handler, caption refresh, cleanup helpers, destructor thunks, scalar deleting destructor. |
| `g_pSoundStatusPane` | `0x0069b4d4` | Singleton pointer registered by the constructor, cleared by cleanup/destructor paths, and removed during main UI shutdown. |
| Vtable set | `0x0062cef4`, `0x0062cf40`, `0x0062cf70` | Main and adjustor vtables installed at object offsets `0x0`, `0xa0`, and `0xa4`. |

## Behavior Notes

- The constructor at `0x0057bf70` calls `Pane::Pane(..., 1)`, installs three `SoundStatusPane` vtables, writes [UID:0000SB][g_pSoundStatusPane](by-global/g_pSoundStatusPane.md), and stores bounds at offsets `0xf8`, `0xfc`, `0x100`, and `0x104`.
- The pane bounds are derived from `g_screenWidth - 354`, `left + 114`, `g_screenHeight - 11`, and `top + 12`.
- `HandleSoundHotkeys` at `0x0057c080` only handles key-event type `8`. Lowercase `m` with exact modifier `2` toggles sound effects and mirrors the state into `g_pConfig + 0x28de48`. Uppercase `M` with modifier bit `2` toggles MIDI playback and the paired `SoundManager` music state.
- After a handled toggle, the method refreshes the owner pane by subtracting `0xa0` from the subobject `this` pointer and calling the owner repaint vtable slot with the stored bounds rectangle.
- `RefreshSoundStatusText` at `0x0057c160` resets inherited selector/page state, chooses `Sound On`/`Sound Off` and `Music On`/`Music Off`, formats `%s/%s`, and pushes the caption through the inherited status-text setter.

## Source Grouping

Keep this source adjacent to other main HUD panels:

```text
ui/panels/
  UserStatusPane.cpp
  SoundStatusPane.cpp
  UserPane.cpp
```

It should cross-reference [UID:0000LN][MusicControlDialog](by-file/MusicControlDialog.md), which is the full settings dialog for the same sound/music subsystem, but the two should not be merged. `MusicControlDialog` owns `DLGSCNTL.EPF` dialog controls and music-folder/CD-drive UI; `SoundStatusPane` owns the always-present HUD shortcut/caption.

## Data Caveats

Earlier source-output views did not consistently model IDA-confirmed helpers at `0x0057c050` and `0x0057c240`, and they mishandled thunk/adjusted-this evidence around `0x0057c24b` and `0x0057c256`. Use the memory doc as the range anchor before applying source migration.

The destructor output labels base cleanup as `TextButtonExControlPane::~Pane`. IDA confirms a shared pane-base cleanup call at `0x00544580`, but the exact inherited class name should stay provisional until the control-pane hierarchy is reviewed.

## Cross-References

- [UID:0000DJ][SoundStatusPane](by-class/SoundStatusPane.md)
- [UID:0001IG][0x0057bf70-0x0057c2cf.SoundStatusPane](by-memory/0x0057bf70-0x0057c2cf.SoundStatusPane.md)
- [UID:0000SB][g_pSoundStatusPane](by-global/g_pSoundStatusPane.md)
- [UID:0000NV][SoundManager](by-file/SoundManager.md)
- [UID:0000LN][MusicControlDialog](by-file/MusicControlDialog.md)
- [UID:0001R1][proposed-source-tree](by-project-structure/proposed-source-tree.md)

## Changes

- 2026-06-05: Assigned projected reconstruction path `NexusTK/ui/panels/` to resolve the by-file generated-root coverage error.
  - Before: the validator path metadata was blank even though the document and proposed source tree both placed `SoundStatusPane.cpp` under `ui/panels/`.
  - After: set `PROPOSED_RECONSTRUCTION_PATH` to `NexusTK/ui/panels/` without changing completion/confidence or writing reconstruction C++.
  - Evidence: `by-project-structure/proposed-source-tree.md` lists `SoundStatusPane.cpp` with the HUD status panels, and live IDA xrefs show [UID:0000SB][g_pSoundStatusPane](by-global/g_pSoundStatusPane.md) is created and destroyed inside the `0x0057bf70-0x0057c2cf` pane island.
- 2026-05-30: Scored documentation completeness/confidence.
  - Before: completion/confidence metadata was ungraded at `0/0`.
  - After: set completion to `84` and confidence to `80`.
  - Evidence: document covers UI panel role, proposed contents, singleton/vtable anchors, hotkey/caption behavior, source grouping, data caveats, and cross-references; confidence remains capped by exact base-class naming and omitted helper cleanup.
