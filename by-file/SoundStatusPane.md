*** UID:0000NX | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:95 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/panels/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:FILE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# SoundStatusPane

## Status

- Confidence: source-ready for the complete compilation unit, direct Pane/Singleton declaration, four ordinary methods, four compiler functions, singleton global/specializations, dependencies, generated CPP/H route, and source placement.
- Proposed module: `ui/panels/SoundStatusPane.cpp`
- Projected reconstruction path: `NexusTK/ui/panels/SoundStatusPane.cpp`
- Main class: [UID:0000DJ][SoundStatusPane](by-class/SoundStatusPane.md)
- Main address doc: [UID:0001IG][0x0057bf70-0x0057c2cf.SoundStatusPane](by-memory/0x0057bf70-0x0057c2cf.SoundStatusPane.md)
- Singleton global: [UID:0000SB][g_pSoundStatusPane](by-global/g_pSoundStatusPane.md)
- Source topology: UID0000SB is the position-zero semantic global/specialization emitter; UID0000DJ emits the CPP preamble and complete H declaration; UID0001IG emits exactly four ordinary methods. Physical UID0002WA and compiler data/functions do not emit.
- Evidence basis: accepted UID0000NX report, current canonical IDA evidence captured there, exact ordinary-page formals, scoped validator receipts, and callback-time physical generated readback.

## File Role

`SoundStatusPane.cpp` owns the small in-game sound/music status pane and its keyboard shortcuts. It is created by `InitializeMainUiGraph` in both the newer and older main UI layouts, computes a bottom-right position from current screen dimensions, toggles sound and music state through [UID:0000DG][SoundManager](by-class/SoundManager.md), and formats the visible `Sound On/Off` plus `Music On/Off` caption.

This should remain a UI panel source, not part of `audio/SoundManager.cpp`. `SoundManager` owns playback and resource policy; this file owns the HUD status/control surface over that audio state. [UID:0000LD][MidiPlayer](by-file/MidiPlayer.md) remains the MIDI owner; this pane only consumes MIDI state/toggle helpers.

## Proposed Contents

| Entity | Address evidence | Role |
| --- | --- | --- |
| `SoundStatusPane` | `0x0057bf70-0x0057c2cf` | Four ordinary methods: constructor, empty ordinary destructor, `HandleKeyOrTextEvent`, and `OnPaint`; four compiler functions are covered and intentionally non-emitting. |
| `g_pSoundStatusPane` | `0x0069b4d4` | Position-0 external-linkage pointer definition plus exact Singleton constructor/destructor specializations in CPP and matching H extern; MapPane is the sole external consumer. |
| Vtable set | `0x0062cef4`, `0x0062cf40`, `0x0062cf70` | Main Pane-derived table plus EventHandler secondary-view tables installed at object offsets `0x0`, `0xa0`, and `0xa4`. |

## Singleton And Global Source Route

- RTTI names both `SoundStatusPane` and direct `Singleton<SoundStatusPane>`. The Singleton base descriptor uses PMD `+0xf8,-1,0`, while `Pane` is `0xf8` bytes and both main-UI construction branches allocate `0x108` bytes.
- Empty-base optimization permits the empty Singleton base to share `+0xf8` with the first derived status-bound dword; four dwords through `+0x104` account for the complete allocation.
- [UID:0000SB][g_pSoundStatusPane](by-global/g_pSoundStatusPane.md) emits `#include "SoundStatusPane.h"`, the sole `SoundStatusPane *g_pSoundStatusPane = NULL;` definition, and explicit `Singleton<SoundStatusPane>` constructor/destructor specializations that publish the adjusted object pointer and clear it. Its H channel emits one forward/extern declaration.
- [UID:0002WA][0x0069b4d4-0x0069b4d8.g_pSoundStatusPane](by-memory/0x0069b4d4-0x0069b4d8.g_pSoundStatusPane.md) records four target one-byte undefined heads inside the protected six-head zero neighborhood. Only the first target head carries `SoundStatusPane *`; physical names/comments are empty, semantic lookup separately binds `g_pSoundStatusPane` to `0x0069b4d4`, and C031 is strict `NO_CHANGE`. UID0002WA remains false/non-emitting with blank formals.
- MapPane exit-to-menu teardown reads the global at `0x005048e6` from separately documented `MapPane.cpp` code. This is an external consumer requiring the H declaration, not evidence that MapPane owns the definition.
- The constructor publishes the singleton at `0x0057bfc0`; fallback `0x0057bfc7`, ordinary destructor `0x0057c06a`, unwind helper `0x0057c240`, and scalar deleting destructor `0x0057c290` clear it. These paths are compiler lowering around the ordinary Singleton-aware constructor/destructor source.

## Behavior Notes

- The constructor at `0x0057bf70` calls the Pane base constructor, installs three `SoundStatusPane` vtables, writes [UID:0000SB][g_pSoundStatusPane](by-global/g_pSoundStatusPane.md), and stores bounds at offsets `0xf8`, `0xfc`, `0x100`, and `0x104`.
- Four distinct integer fields are stored in order at `+0xf8/+0xfc/+0x100/+0x104`: `m_statusLeft = g_screenWidth - 354`, right `= left + 114`, top `= g_screenHeight - 11`, and bottom `= top + 12`. A non-escaping local `RectBounds` is passed to `InitRectBounds`.
- `HandleKeyOrTextEvent` at `0x0057c080` translates the key before testing `kEventKeyDown`. Lowercase `m` with exact Control toggles SoundManager effects and mirrors `Config::m_soundEffectsEnabled`; uppercase `M` with the Control bit makes paired MidiPlayer enable/disable and SoundManager mute/unmute calls. Other inputs return false; handled inputs invalidate `m_visibleBounds` and return true.
- `OnPaint` at `0x0057c160` sets exact draw/text state, fills inherited visible bounds, moves to `(0,11)`, chooses the four SoundManager-backed wide captions, formats `L"%s/%s"` into `wchar_t[128]`, and draws the resulting length.

## Source Grouping

Keep this source adjacent to other main HUD panels:

```text
ui/panels/
  UserStatusPane.cpp
  SoundStatusPane.cpp
  SoundStatusPane.h
  UserPane.cpp
```

It should cross-reference [UID:0000LN][MusicControlDialog](by-file/MusicControlDialog.md), which is the full settings dialog for the same sound/music subsystem, but the two should not be merged. `MusicControlDialog` owns `DLGSCNTL.EPF` dialog controls and music-folder/CD-drive UI; `SoundStatusPane` owns the always-present HUD shortcut/caption.

## Whole-File Inventory And Compiler Disposition

- Handwritten source is exactly four methods: constructor `[0x0057bf70,0x0057c04d)`, ordinary destructor `[0x0057c050,0x0057c079)`, key override `[0x0057c080,0x0057c15b)`, and paint override `[0x0057c160,0x0057c23e)`.
- Compiler functions are constructor-unwind Singleton cleanup `[0x0057c240,0x0057c24b)`, `+0xa0` and `+0xa4` scalar-destructor adjustors `[0x0057c24b,0x0057c256)` / `[0x0057c256,0x0057c261)`, and scalar deleting destructor `[0x0057c270,0x0057c2cf)`. They rebuild from the ordinary source and are not emitted.
- Internal `CC` alignment spans are `[0x0057c04d,0x0057c050)`, `[0x0057c079,0x0057c080)`, `[0x0057c15b,0x0057c160)`, `[0x0057c23e,0x0057c240)`, and `[0x0057c261,0x0057c270)`; external boundaries are `[0x0057bf6e,0x0057bf70)` and `[0x0057c2cf,0x0057c2d0)`.
- Compiler data is three COL/vtable groups with 31 callable cells, one seven-node RTTI graph, and five source-owned caption literals. UID00026I records every address/slot/PMD and remains non-emitting.
- Both `InitializeMainUiGraph` branches call the constructor at `0x004f8460` and `0x004f89c7`, each immediately after `operator new(0x108)`. MapPane reads the global at `0x005048e6` and uses deferred BlackHole deletion rather than direct delete/global clear.
- The unit owns no resources, imports, other statics, or standalone helpers. SoundManager, MidiPlayer, Config, Application, Event/Pane/GrafPort, RectBounds, and Surface callback state are dependencies.

## Dependency And Include Closure

- UID0000DJ CPP includes complete producers for Application/screen dimensions, MidiPlayer, SoundManager, Config, Surface fill callback, Event/EventMan, and `SoundStatusPane.h`, plus `<cwchar>` for formatting/length calls.
- `SoundStatusPane.h` directly includes complete `Singleton` and `Pane` bases and forward-declares pointer-only `Event`. It declares the two overrides, four integers, and exact `0x108` size assertion.
- `MidiPlayer.h` now has one guarded `0x0c` class declaration plus `g_pMidiPlayer` extern; `MidiPlayer.cpp` begins with its header include.
- `SoundManager.h` now has one guard, exactly seven direct includes, local 32-bit Miles aliases/handles/calling conventions/five callback types/all 37 observed API declarations, one `g_pSoundManager` extern, one complete class, and one closing guard. Windows/DirectSound types come from the SDK; project bases/members come from complete local headers.
- Rejected dependency routes are unavailable `<mss.h>`, a new unowned shim, copied proprietary middleware source, implicit declarations, PCH-only availability, duplicate global definitions, and moving this UI unit into either audio owner.

## Callback-Time Generated Snapshot

- Dated physical snapshot: generated command `000000027390`, refreshed `2026-08-24T02:29:48-04:00` by deferred generated refresh. This is callback evidence, not timeless current authority; later validators may advance the command while preserving content.
- `auto-generated/NexusTK/ui/panels/SoundStatusPane.cpp`: 3,297 bytes, 111 lines, last write `2026-08-24T06:29:57.5926176Z`, SHA256 `0C4179F44BA081B8C950402893AC837C195D0CF3002C13FE602ED44C8490BA35`. It contains one pointer definition, two explicit Singleton specializations, one constructor, one ordinary destructor, one key override, one paint override, and zero empty-emitter markers.
- `auto-generated/NexusTK/ui/panels/SoundStatusPane.h`: 1,146 bytes, 41 lines, last write `2026-08-24T06:29:57.6386207Z`, SHA256 `B223BD3680722F8E4289CB39C0325BEBF3ECD361567F8C9359AA4951CFE6BDC0`. It contains one forward/extern global route and one complete guarded class declaration, with zero empty-emitter markers.
- The former sampled/partial output, `TextButtonExControlPane` base-name pollution, and class/method/global empty-marker state are superseded. Compiler cleanup/thunks/vtables/RTTI are intentionally absent as handwritten source, not omissions.

## Ownership Alternatives And Score Rationale

- Keep the file under `NexusTK/ui/panels/`. SoundManager and MidiPlayer own audio behavior, while this source owns the visible pane, its shortcut/caption behavior, and its singleton lifetime. MapPane is an external consumer only.
- Reject file-local `static` because MapPane consumes the pointer across the current translation-unit split. Reject moving the global to MapPane, SoundManager, or MidiPlayer because their evidence is consumer/dependency evidence rather than writer/lifetime ownership.
- Reject duplicate physical/semantic definitions, a hand-written registry, compiler-artifact wrappers as ordinary source, raw IDA labels/casts, `nullptr`, and smart pointers. These conflict with one-definition routing, direct Singleton RTTI lowering, the raw-pointer ABI, or mid-2000s source shape.
- Completion `94`: the complete source/compiler/data inventory, formal CPP/H union, direct dependencies, singleton specializations/global route, both construction branches, MapPane deferred consumer, vtable/RTTI/literal ownership, and generated physical output are resolved.
- Confidence `95`: exact ranges/bytes, decompilation, callers/callees, allocation sizes, RTTI/PMDs, vtable slots, lifecycle xrefs, current physical global model, ordinary formals, and generated readback converge on one whole-file source shape.

## Cross-References

- [UID:0000DJ][SoundStatusPane](by-class/SoundStatusPane.md)
- [UID:0001IG][0x0057bf70-0x0057c2cf.SoundStatusPane](by-memory/0x0057bf70-0x0057c2cf.SoundStatusPane.md)
- [UID:0000SB][g_pSoundStatusPane](by-global/g_pSoundStatusPane.md)
- [UID:0000DG][SoundManager](by-class/SoundManager.md)
- [UID:0000NV][SoundManager](by-file/SoundManager.md)
- [UID:0000LD][MidiPlayer](by-file/MidiPlayer.md)
- [UID:0000LN][MusicControlDialog](by-file/MusicControlDialog.md)
- [UID:0001R1][proposed-source-tree](by-project-structure/proposed-source-tree.md)
- [UID:0002WA][0x0069b4d4-0x0069b4d8.g_pSoundStatusPane](by-memory/0x0069b4d4-0x0069b4d8.g_pSoundStatusPane.md)

## Changes

- 2026-08-24 B009 UID0000NX callback: Raised `89/91` to `94/95`. Replaced the sampled/partial file model with the complete four-source/four-compiler inventory, exact range/padding/global/vtable/RTTI/literal ownership, both `operator new(0x108)` branches, MapPane deferred consumer, full CPP/H and dependency closure, and dated callback-time generated CPP/H hashes with zero target empty markers.
- 2026-08-01 B010 UID0002WA callback: Raised `88/88` to `89/91`. Added direct Singleton RTTI/PMD/EBO and allocation evidence, the sole position-0 UID0000SB CPP/H route, MapPane external consumer proof, exact lifecycle lowering, physical UID0002WA non-emission, generated one-definition expectations, rejected ownership/source alternatives, and score rationale. No proposed-source-tree edit was needed because the existing path is already correct.
- 2026-06-17 B003 source-quality execution: Raised `86/86` to `88/88`.
  - Evidence: B003 validated source placement under `NexusTK/ui/panels/SoundStatusPane.cpp`, resolved the Pane/EventHandler source shape, rejected SoundManager/MidiPlayer/EventDispatcher ownership alternatives, bounded generated-output omissions, and confirmed the singleton/vtable/method island relationships.
- 2026-06-11 A005 Batch236 parent-gate repair:
  - Before: `84/80`, below the strict gate for attached globals.
  - After: `86/86`; the file now supports [UID:0000SB][g_pSoundStatusPane](by-global/g_pSoundStatusPane.md) as a direct module-level singleton parent.
  - Evidence: the page already records both main UI construction paths, bottom-right screen-derived bounds, hotkey/caption behavior, cleanup/destructor helpers, the three vtable bases, and the exact singleton memory child [UID:0002WA][0x0069b4d4-0x0069b4d8.g_pSoundStatusPane](by-memory/0x0069b4d4-0x0069b4d8.g_pSoundStatusPane.md).
- 2026-06-05: Assigned projected reconstruction path `NexusTK/ui/panels/` to resolve the by-file generated-root coverage error.
  - Evidence: `by-project-structure/proposed-source-tree.md` lists `SoundStatusPane.cpp` with the HUD status panels, and live IDA xrefs show [UID:0000SB][g_pSoundStatusPane](by-global/g_pSoundStatusPane.md) is created and destroyed inside the `0x0057bf70-0x0057c2cf` pane island.
