*** UID:0000DJ | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:95 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000NX | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000NX | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#include "../../app/Application.h"
#include "../../audio/MidiPlayer.h"
#include "../../audio/SoundManager.h"
#include "../../config/Config.h"
#include "../../render/Surface.h"
#include "../core/Event.h"
#include "SoundStatusPane.h"

#include <cwchar>

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#ifndef NEXUSTK_UI_PANELS_SOUNDSTATUSPANE_H
#define NEXUSTK_UI_PANELS_SOUNDSTATUSPANE_H

#include "../../util/Singleton.h"
#include "../core/Pane.h"

class Event;

class SoundStatusPane : public Pane,
                        public Singleton<SoundStatusPane>
{
public:
    SoundStatusPane();
    virtual ~SoundStatusPane();

    virtual void OnPaint();
    virtual bool HandleKeyOrTextEvent(Event *event);

private:
    int m_statusLeft;
    int m_statusRight;
    int m_statusTop;
    int m_statusBottom;
};

typedef char SoundStatusPaneSizeMustBe264[
    sizeof(SoundStatusPane) == 0x108 ? 1 : -1];

#endif
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# SoundStatusPane

## Status

- Confidence: source-ready for behavior, range, class ownership, direct bases, complete layout, lifecycle lowering, override declarations, dependencies, and source placement.
- Likely source module: [UID:0000NX][SoundStatusPane](by-file/SoundStatusPane.md)
- Main range: [UID:0001IG][0x0057bf70-0x0057c2cf.SoundStatusPane](by-memory/0x0057bf70-0x0057c2cf.SoundStatusPane.md)
- Singleton global: [UID:0000SB][g_pSoundStatusPane](by-global/g_pSoundStatusPane.md)
- Proven source-level relationship: direct `public Singleton<SoundStatusPane>` base in addition to the established Pane/EventHandler layout.
- Evidence basis: live IDA MCP function, xref, vtable, decompilation, byte, and instruction checks through B003's 2026-06-17 source-quality pass.

## Responsibility

`SoundStatusPane` is a compact HUD/control pane for sound and music state. It displays the current sound-effect and music enabled state, handles keyboard shortcuts for toggling them, and forwards actual playback changes to [UID:0000DG][SoundManager](by-class/SoundManager.md) and the global MIDI player.

## Layout Evidence

- RTTI independently names `SoundStatusPane` and `Singleton<SoundStatusPane>`. The direct Singleton base-class descriptor records PMD `+0xf8,-1,0`, zero contained bases, and attributes `0x40`.
- Current `Pane` type evidence is exactly `0xf8` bytes. Both `MainMenuPane_InitializeMainUiGraph` branches allocate `0x108` bytes before calling the same `SoundStatusPane` constructor at `0x0057bf70`.
- The empty Singleton base can share offset `+0xf8` with the first derived status-bound dword through empty-base optimization. Four derived dwords at `+0xf8/+0xfc/+0x100/+0x104` then account for the full `0x108` allocation without inventing physical singleton-registry storage.
- Constructor writes primary and secondary vtables at object offsets `0x0`, `0xa0`, and `0xa4`, matching a Pane-derived object with EventHandler-style secondary views.
- Constructor writes four distinct SoundStatusPane-owned integers in source order: `m_statusLeft` at `+0xf8`, `m_statusRight` at `+0xfc`, `m_statusTop` at `+0x100`, and `m_statusBottom` at `+0x104`. The constructor derives a separate non-escaping `RectBounds` local from those values and passes it to `InitRectBounds`; the local is not hidden object storage.
- `HandleSoundHotkeys` receives an adjusted subobject `this` pointer and subtracts `0xa0` before invoking the owner pane invalidation/repaint slot.
- Vtable addresses observed by IDA: `0x0062cef4`, `0x0062cf40`, and `0x0062cf70`.
- The constructor stack `RectBounds` local mirrors the same rectangle but has no proven escaped use; it is not authoritative hidden state and should not cap source confidence.

## Singleton Lifecycle And Compiler Lowering

- Constructor write `0x0057bfc0` publishes the adjusted `this` pointer through [UID:0000SB][g_pSoundStatusPane](by-global/g_pSoundStatusPane.md); fallback `0x0057bfc7` writes zero.
- Ordinary destructor `0x0057c06a`, constructor-unwind helper `0x0057c240`, and scalar deleting destructor `0x0057c290` each clear the same global on their respective teardown paths.
- This publish/clear pattern, direct RTTI base, PMD, and EBO-compatible layout are the compiler/runtime lowering of `Singleton<SoundStatusPane>` inheritance. Recovered source should declare the direct base and ordinary constructor/destructor; it should not hand-write an unrelated registry API, EH clear helper, adjustor thunks, or scalar deleting destructor.
- Both construction callers at `0x004f8460` and `0x004f89c7` belong to `MainMenuPane_InitializeMainUiGraph` and use `new(0x108)`, independently confirming one complete class layout in both UI branches.

## Important Methods

| Address | Current source role | Notes |
| --- | --- | --- |
| `0x0057bf70-0x0057c04d` | constructor | Registers singleton, installs vtables, computes bottom-right status bounds from screen dimensions. |
| `0x0057c050-0x0057c079` | destructor body / non-deleting cleanup | Reinstalls vtables, clears singleton, calls shared Pane cleanup. |
| `0x0057c080-0x0057c15b` | `HandleSoundHotkeys` / `OnKeyEvent` | Handles key event type `8`; `modifier == 2 && 'm'` toggles SFX/config byte, `modifier & 2 && 'M'` toggles music/MIDI. |
| `0x0057c160-0x0057c23e` | `RefreshSoundStatusText` / caption paint method | Draws or refreshes `Sound On/Off` plus `Music On/Off`. |
| `0x0057c240-0x0057c24b` | constructor-unwind singleton clear helper | Clears [UID:0000SB][g_pSoundStatusPane](by-global/g_pSoundStatusPane.md) from EH cleanup support; not a public source method. |
| `0x0057c24b-0x0057c256` | adjustor thunk | Subtracts `0xa0` and forwards to scalar deleting destructor. |
| `0x0057c256-0x0057c261` | adjustor thunk | Subtracts `0xa4` and forwards to scalar deleting destructor. |
| `0x0057c270-0x0057c2cf` | scalar deleting destructor | Compiler-generated delete wrapper; source should declare the ordinary destructor. |

## External State

- [UID:0000SB][g_pSoundStatusPane](by-global/g_pSoundStatusPane.md) at `0x0069b4d4`.
- `g_pSoundManager` at `0x0067a7d0` for music/sound enabled state and toggles.
- `g_pMidiPlayer` at `0x0067ab4c` for MIDI play/stop state.
- `g_pConfig` at `0x0067a7c8`, sound-effect enabled byte at offset `0x28de48`.
- `g_screenWidth` at `0x0066da94` and `g_screenHeight` at `0x0066da98`.

## Source-Quality Notes

- The class is a Pane-derived UI pane with EventHandler secondary views at `+0xa0` and `+0xa4`; `TextButtonExControlPane` is decompiler/base-name pollution from shared Pane cleanup and should not be used as the declared base.
- Direct `Singleton<SoundStatusPane>` inheritance is source evidence, not a decompiler convenience: RTTI names the template specialization and places it at `+0xf8`, while the constructor/destructor family performs the expected publication/clear lowering.
- The vtable slots and adjustor thunks should remain documented as compiler/runtime artifacts. Source should declare class methods and let the compiler regenerate thunks and scalar deleting destructor support.
- The four derived dwords are modeled as distinct left/right/top/bottom integers, matching the four independent constructor stores and exact `0x108` allocation. Collapsing them into a speculative aggregate member would obscure the observed storage order.
- The event record uses kind `+0x04`, key/character byte `+0x08`, and modifier/filter state `+0x10a`; do not lock `+0x10a` to a physical key/modifier enum until the shared event type pass proves it.
- The CPP channel is the complete translation-unit preamble followed by `[[CHILDREN]]`; UID0001IG owns exactly the four ordinary method definitions. The H channel owns the complete class declaration, exact direct bases, four fields, overrides, and `0x108` compile-time size assertion.

## Dependency Closure

- `SoundStatusPane.h` directly includes the complete `Singleton` and `Pane` base definitions and forward-declares pointer-only `Event`; it does not depend on a precompiled header or an incomplete base.
- The CPP preamble directly includes complete producers for `Application`/screen globals, `MidiPlayer` and `g_pMidiPlayer`, standalone `SoundManager` and `g_pSoundManager`, `Config`, the surface fill callback, `Event`/event manager contracts, and this class header. `<cwchar>` supplies `wchar_t`, `swprintf_s`, and `wcslen` use in the child paint body.
- The repaired `MidiPlayer.h` owns the full class declaration plus the semantic-global extern route. The repaired `SoundManager.h` owns its guard, seven direct prerequisites, bounded local Miles ABI declarations, semantic-global extern, complete class, and closing guard. Every project include in this preamble therefore has a formal producer.
- No unavailable Miles SDK include, new compatibility source file, implicit declaration, or precompiled-header assumption is required by this class.

## Global And Source Route

- [UID:0000SB][g_pSoundStatusPane](by-global/g_pSoundStatusPane.md) is the sole semantic global identity. It emits `SoundStatusPane *g_pSoundStatusPane = NULL;` in CPP and the matching forward declaration plus `extern` declaration in H at position `0` under [UID:0000NX][SoundStatusPane](by-file/SoundStatusPane.md).
- Physical child [UID:0002WA][0x0069b4d4-0x0069b4d8.g_pSoundStatusPane](by-memory/0x0069b4d4-0x0069b4d8.g_pSoundStatusPane.md) is exact loader-zeroed storage evidence only: it remains owned by UID0000SB but is false/non-emitting with blank formal channels.
- MapPane teardown reads the global at `0x005048e6` from separately documented `MapPane.cpp` code. That consumer proves external linkage and the header route; it does not transfer ownership away from `SoundStatusPane.cpp`.
- Reject SoundManager/MidiPlayer ownership, file-local `static`, duplicate physical/global definitions, modern smart pointers/`nullptr`, IDA integer casts, and a hand-written singleton registry. Those alternatives conflict with UI lifetime ownership, cross-TU use, raw-pointer ABI, one-definition routing, or era-appropriate source shape.

## Score Rationale

- Completion `94`: direct Pane and Singleton inheritance, exact PMD/EBO-compatible layout, both `0x108` allocations, complete publication/teardown lowering, exact overrides and fields, CPP child route, standalone dependencies, and full H declaration are documented and emitted.
- Confidence `95`: RTTI, PMDs, object/allocation size, constructor stores, exact global accesses, vtable slots, two callers, method bodies, and one-definition ownership all converge on the emitted declaration and source route.
- Compiler-generated thunks, unwind cleanup, scalar deleting destructor, vtables, and RTTI remain non-emitting evidence; their absence from the formal channels is intentional rather than an unresolved class gap.

## Cross-References

- [UID:0000NX][SoundStatusPane](by-file/SoundStatusPane.md)
- [UID:0001IG][0x0057bf70-0x0057c2cf.SoundStatusPane](by-memory/0x0057bf70-0x0057c2cf.SoundStatusPane.md)
- [UID:0000SB][g_pSoundStatusPane](by-global/g_pSoundStatusPane.md)
- [UID:0000DG][SoundManager](by-class/SoundManager.md)
- [UID:0000NV][SoundManager](by-file/SoundManager.md)
- [UID:0000LD][MidiPlayer](by-file/MidiPlayer.md)
- [UID:0000RM][g_pMidiPlayer](by-global/g_pMidiPlayer.md)
- [UID:0002WA][0x0069b4d4-0x0069b4d8.g_pSoundStatusPane](by-memory/0x0069b4d4-0x0069b4d8.g_pSoundStatusPane.md)

## Changes

- 2026-08-24 B009 UID0000NX callback: Raised `90/92` to `94/95`. Replaced the empty formal channels with the exact CPP include/child route and complete guarded class declaration, fixed the four distinct left/right/top/bottom fields and `0x108` assertion, and documented the now-complete MidiPlayer/SoundManager/platform dependency closure.
- 2026-08-01 B010 UID0002WA callback: Raised `88/89` to `90/92`. Added direct `public Singleton<SoundStatusPane>` RTTI/PMD evidence, EBO overlap at `+0xf8`, complete `0x108` allocation accounting, two caller routes, constructor/destructor compiler lowering, sole UID0000SB CPP/H route, physical UID0002WA non-emission, rejected alternatives, and score rationale. Class formal CPP/H remain blank because complete shared virtual/member source is separate work.
- 2026-06-17 B003 source-quality execution: Raised `86/86` to `88/89`.
  - Evidence: B003's source-quality audit resolved the stale inherited-base question, confirmed Pane/EventHandler subobject layout, status-rectangle fields, constructor stack-local treatment, compiler thunk/destructor policy, SoundManager/MidiPlayer consumer boundaries, singleton lifecycle, and source placement. Formal C++ remains blank pending shared Pane/EventHandler naming.
- 2026-06-11 A005 Batch236 parent-gate repair:
  - Before: `84/84`, below the corrected 85/85 gate even though the file/global chain was already known.
  - After: `86/86`; the class and file now both clear the gate supporting [UID:0000SB][g_pSoundStatusPane](by-global/g_pSoundStatusPane.md) and exact memory child [UID:0002WA][0x0069b4d4-0x0069b4d8.g_pSoundStatusPane](by-memory/0x0069b4d4-0x0069b4d8.g_pSoundStatusPane.md).
  - Evidence: existing documented checks cover the constructor, cleanup helper, hotkey handler, caption refresh, singleton clear helper, adjustor thunks, scalar deleting destructor, three vtable bases, screen-size bounds, SoundManager/MIDI/config interactions, and all six singleton lifecycle refs.
