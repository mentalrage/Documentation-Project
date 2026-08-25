# UID0000NX SoundStatusPane Whole-File Empty-Emitter Source-Quality Report
** TARGET-REPORT-UID:0000NX **
** AUTHOR-AGENT-ID:B009 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.6 | xHigh **

## Finalized Report / Current Recommendation

The accepted ordinary callback has completed the `NexusTK/ui/panels/SoundStatusPane.cpp` source unit and its required `SoundStatusPane.h` through the existing owner/emitter topology. The generated source unit now has one process global, two class-specific `Singleton<SoundStatusPane>` specializations, four handwritten `SoundStatusPane` methods, and one complete class declaration. It does not hand-emit the constructor-unwind helper, two secondary-base adjustor thunks, scalar deleting destructor, vtables, RTTI, or padding.

The primary by-file target is UID0000NX. Its two formerly empty emitters are now filled and physically verified with zero target empty markers. The dependency closure is source-complete: `SoundManager.h` has one guarded, self-contained Win32/DirectSound/project-header preamble and a bounded local Miles ABI declaration block derived from the executable's complete 37-import surface, so no unavailable SDK header or new compatibility file is assumed.

- UID0000DJ owns the class declaration/header route and a CPP preamble followed by `[[CHILDREN]]`.
- UID0001IG owns the four ordinary method definitions and a blank H channel because declarations are class-owned.
- UID0000SB remains the sole semantic global emitter at position zero and owns the external definition, matching H declaration, and explicit singleton constructor/destructor specializations.
- UID0002WA remains non-emitting physical storage evidence only. Its dated report-time IDB model is four target bytes represented by four separate one-byte undefined heads inside the verified six-head neighborhood, not one four-byte data item; fresh Gate 2B readback must match before C031 is closed.

Report execution and archive state remain supervisor-owned and authoritative only from the report's current path plus validator-owned status/history metadata. This callback report contains exactly one final readiness marker after the checklist; it does not claim execution or archive state.

## Supporting Research

The whole-file pass reconciled the primary page, both empty emitters, semantic and physical global pages, mixed read-only-data page, base/type contracts, main-UI construction, MapPane teardown, audio consumers, current generated CPP/H, manual coverage rows, relevant archived B reports, and dated report-time canonical IDA evidence.

Relevant prior reports were treated as dated leads, not current authority:

- B003 `executed-b-agent-research/B003/0001IG-soundstatuspane-source-quality.md`, which correctly identified the method island but retained now-resolved virtual-name and event-shape blockers and incorrectly associated invalidation with the four derived status coordinates.
- B010 `executed-b-agent-research/B010/0002WA-g_pSoundStatusPane-empty-emitter-source-quality.md`, which established the physical singleton storage and one-definition topology.

The current Pane, GrafPort, Event, EventHandler, RectBounds, SingletonTemplate, SoundManager, MidiPlayer, Config, Surface callback, Application global, main-UI, MapPane, and generated artifacts supersede stale assumptions in those reports.

## Target

- Primary UID: `0000NX`.
- Primary page: `by-file/SoundStatusPane.md`.
- Source path: `NexusTK/ui/panels/SoundStatusPane.cpp`.
- Required sibling header: `NexusTK/ui/panels/SoundStatusPane.h`.
- Class emitter: UID0000DJ `by-class/SoundStatusPane.md`.
- Method emitter: UID0001IG `by-memory/0x0057bf70-0x0057c2cf.SoundStatusPane.md`.
- Semantic global emitter: UID0000SB `by-global/g_pSoundStatusPane.md`.
- Physical global evidence: UID0002WA `by-memory/0x0069b4d4-0x0069b4d8.g_pSoundStatusPane.md`.
- Read-only compiler/data evidence: UID00026I `by-memory/0x0062ce50-0x0062cfd8.NetworkAndAudioReadOnlyData.md`.

No additional report UID is declared. Support UIDs are researched because they are required to complete the primary whole-file unit; they do not become separate report targets.

## Current Target State

The pre-callback tracker recorded UID0000NX under `Files With Empty Emitters`: three emitters, one filled, two empty, and 33.3% generated completion, with zero direct and zero additional B-report coverage in its by-file bucket. Tracker and manual coverage state remain validator/supervisor-owned and were not edited by B009.

Historical generated evidence: the prior physical snapshot carried validator command `000000027302`, refreshed `2026-08-23T22:55:19-04:00`. That command is dated history only and is not current generated authority.

The generated artifacts were physically reread at `2026-08-24T04:52:41.6321272Z`. Every present artifact below carried validator command `000000027320`, refreshed `2026-08-23T23:56:45-04:00`; this is an explicitly dated pre-callback snapshot, not current authority:

- `auto-generated/NexusTK/ui/panels/SoundStatusPane.cpp`: 685 bytes, SHA256 `76B5CDE434D91A1E15D3EB68C81DBDB8BD119FC335DFF2BA61ADD7F574F389B4`; UID0000SB forward declaration and `g_pSoundStatusPane = NULL`; empty markers for UID0000DJ and UID0001IG; no constructor, destructor, key handler, paint handler, or singleton specialization.
- `auto-generated/NexusTK/ui/panels/SoundStatusPane.h`: 462 bytes, SHA256 `10BDBB1D697FBCA65250EB65BD1484893F71C5FB2903AA360E72735E864363F6`; only UID0000SB forward declaration and extern; empty UID0000DJ contributes nothing.
- `auto-generated/NexusTK/audio/MidiPlayer.cpp`: 44,896 bytes, SHA256 `B94A5C7003FD9AEA88ADB16F1F2A4193643DC82DCA2AB2B7877A6D576D8D4430`; it still has no `#include "MidiPlayer.h"` and continues to define the singleton and child source inline.
- `auto-generated/NexusTK/audio/MidiPlayer.h`: physically absent, although SoundStatusPane must invoke `MidiPlayer` member functions through `g_pMidiPlayer`.
- `auto-generated/NexusTK/audio/SoundManager.h`: 3,846 bytes, SHA256 `3DD97FE9E75A2235575666DCFDBD2098B07471073E87420DDEC2F582408EDA55`; its class text is not a standalone header. It has no include guard; no direct `<windows.h>`, `<dsound.h>`, or `<vector>` prerequisites; no complete `Singleton`, `TimerHandler`, or `StringBase` includes; no local `HSAMPLE`/`HDIGDRIVER`/`HSTREAM`/`HREDBOOK`/`U32`/`S32`/`AILCALLBACK` or 37-function Miles declaration route; and no required cross-translation-unit `extern SoundManager *g_pSoundManager` reserved by UID0004UF.

That pre-callback by-file statement and generated state are superseded. Final callback readback after the command-27405 refresh proves SoundStatusPane.cpp/.h contain the complete accepted union with zero target empty markers; exact hashes and the corresponding MidiPlayer/SoundManager readback are recorded in Validator Results.

## Executive Recommendation

1. Keep the source unit, path, ownership, and existing three-emitter ordering.
2. Populate UID0000DJ CPP/H with the exact preamble/child routing and class declaration in Section 22.
3. Populate UID0001IG CPP with the exact four ordinary methods in Section 22; leave its H channel blank.
4. Extend UID0000SB CPP with the header include, one external pointer definition, and two explicit Singleton specializations; preserve its forward/extern H route.
5. Replace UID00008A's CPP commentary with `#include "MidiPlayer.h"`, add its complete class H declaration, and route the matching singleton extern through semantic global UID0000RM so both producer and consumer are legal.
6. Make UID0004UF's position-zero H channel open `NEXUSTK_AUDIO_SOUNDMANAGER_H`, include the direct Win32/DirectSound/CRT/STL/project prerequisites, provide the exact local Miles compatibility declarations in Section 22, and declare `g_pSoundManager`; make UID0000DG emit the complete class and close the guard. This uses only repository headers plus installed platform/CRT headers and does not name an unavailable `<mss.h>`.
7. Correct both stale `g_pSoundStatusPane` ordinary pages. The semantic page must distinguish the sole `g_pSoundStatusPane -> 0x69B4D4` address/global-name binding from empty physical item-name fields. The physical page must describe six one-byte undefined heads at `0x69B4D3-0x69B4D9`, four target heads at `0x69B4D4-0x69B4D8`, first-head type `SoundStatusPane *`, untyped remaining target heads, zero bytes, and no authorized aggregation or mutation.
8. Preserve compiler artifacts and read-only data as covered/non-emitting evidence.
9. During supervisor Gate 2B, apply exactly two actions plus one no-change verification: C029/C030 are pure function rename plus function-repeatable-comment actions, while C031 only verifies and protects the existing global state. Perform no function/global type or physical-item change.
10. Keep actor allocation atomic: B009 may implement ordinary pages, run scoped ordinary-page validators, and perform generated readback only after an accepted callback; the supervisor alone applies all twelve Section 28 manual coverage replacements and owns every report-lifecycle action.

## Supervisor Active Recheck

A pre-callback artifact revision, SHA256 `D66BEF174786161E3C0DD56B3B233E7172D668501D3F964E11F9D8599794E976`, passed Gate 1 and authorized the ordinary callback. That acceptance is dated history only: it does not validate the changed post-callback report or this additive repair. This exact repaired artifact requires a wholly fresh, hash-matching Gate 1.

For that fresh review, the supervisor should recheck this exact artifact for all 33 H2 headings, exact 37 ledger/checklist twins, 33 B009-owned checked rows, four supervisor-owned unchecked rows, exactly one final readiness marker, zero executable-script fences, complete whole-file inventory, literal formal source channels, 17 scoped receipts, and six generated artifacts. Gate 2A should compare every checked ordinary row to current pages and generated output. Gate 2B should establish fresh runtime/session/path/disk authority, independently re-read every Section 21 literal prestate, and perform exactly two actions plus one no-change verification for C029-C031; C033 remains supervisor-owned manual coverage/lifecycle work. No manual coverage application, IDA mutation, Gate 2 completion, lifecycle execution, or archive movement is claimed here.

## Inference Research Guidance Check

The reconstruction distinguishes binary fact from source-facing inference:

- Addresses, ranges, calls, branches, offsets, vtable cells, RTTI PMDs, strings, xrefs, object allocation size, and global accesses are live IDA facts.
- `SoundStatusPane`, `OnPaint`, and `HandleKeyOrTextEvent` are strongly constrained by current base-class declarations and exact override slots.
- `m_statusLeft`, `m_statusRight`, `m_statusTop`, and `m_statusBottom` are descriptive source-facing field names. Four distinct integers are required; a `RectBounds` member is rejected because binary field order is left/right/top/bottom, unlike `RectBounds` left/top/right/bottom.
- The stack `RectBounds` in the constructor is a real source-visible call result with no later read or escape. It is retained as a local because removing the call would lose binary behavior.
- `Singleton<SoundStatusPane>` publication/clear behavior belongs to explicit base-template specializations, not handwritten assignments duplicated in the derived constructor/destructor.
- Compiler helper names are descriptive binary labels and do not imply handwritten source functions.

## Heuristic / Inference Reanalysis And Validation

Previously open blockers are resolved:

- Direct source bases are `Pane` and `Singleton<SoundStatusPane>`. `EventHandler` and `TimerHandler` are inherited through Pane, as proved by the RTTI base graph and secondary offsets `+0xa0` and `+0xa4`.
- Pane's exact primary slot `+0x44` is `OnPaint`; Pane's EventHandler secondary slot `+0x08` is `HandleKeyOrTextEvent(Event *)`.
- Event fields and constants are current and exact: `Event::m_type`, `Event::m_payload.m_key.m_key`, `Event::m_payload.m_key.m_modifiers`, `kEventKeyDown`, and `kEventModifierControl`.
- Invalidation uses inherited `GrafPort::m_visibleBounds` at complete-object offset `+0x44`, not the four derived status coordinates at `+0xf8..+0x104`.
- Painting also fills inherited `m_visibleBounds`; the four derived integers are constructor-initialized status geometry retained for layout/source fidelity but are not the invalidation rectangle in this method island.
- The uppercase music branch intentionally calls `MidiPlayer::EnableMidiPlayback`/`DisableMidiPlayback` and then `SoundManager::UnmuteMusic`/`MuteMusic`; SoundManager's own MIDI coordination does not justify deleting the explicit first call.
- The method-island aggregate can emit only ordinary source methods while classifying the four compiler functions as covered, so mixed source/compiler membership is not a blank-channel blocker.
- Section 22 closes every direct dependency: it supplies the absent `MidiPlayer.h`, the `g_pSoundManager` extern, a complete guarded `SoundManager.h` route, all complete-base/member prerequisites, Win32/DirectSound types, and a local 37-import Miles compatibility block. No unavailable SDK include, implicit precompiled-header dependency, or undeclared external remains in the recommended headers.

Rejected alternatives include direct EventHandler/TimerHandler bases, a TextButtonExControlPane base, a packed RectBounds member, SoundManager or MidiPlayer ownership, a separate compiler-helper source file, raw vtable/RTTI emission, and duplicate semantic/physical global definitions.

## Evidence Standards Used

- `original-proof`: literal bytes, modeled boundaries, exact xrefs/calls, exact current metadata, exact generated readback, or direct canonical IDA pre-state.
- `very-strong`: multiple independent original-proof facts plus current source contracts with no material contradiction.
- `strong`: best-supported source spelling or documentation placement where binary semantics are settled but original identifier spelling is unavailable.

Every formal source recommendation preserves observable behavior. Descriptive names are identified as inference; no claim depends on decompiler text alone.

## Evidence Checked

Historical identity note: the pre-repair observations through `2026-08-24T04:52:45.2009630Z`, including session `supervisor_canonical_research_20260824_0215`, PID `13088`, and the earlier physical hash/size tuple, remain dated history and preserve the valid C029-C031 proof recorded below. They are not current session or physical-file authority.

A dated report-time read-only observation used session `supervisor_canonical_research_20260824_0503`, worker PID `21796`. At that observation, `idb_list` showed canonical path `E:\\NTK\\Resources\\NexusTK\\NexusTK.exe.i64`; `server_health` returned `status:ok`, module `NexusTK.exe`, image base `0x400000`, Hex-Rays ready, strings cache ready with 2,067 entries, and `auto_analysis_ready:false` as non-blocking context. The corresponding closed-file physical observation returned 143,211,656 bytes, last write `2026-08-24T04:50:38.7719770Z`, SHA256 `457A3EF7DAEB4E22245E115EAAB4EEB2CE9695CCC965891A9663F866C264F087`. This tuple is dated report-time evidence, not present runtime/session/path/disk authority. Future supervisor Gate 2B must establish fresh authority for each of those dimensions and recheck every literal prestate before action or no-change verification. No IDA mutation or save was performed.

Documentation and generated evidence checked:

- UID0000NX, UID0000DJ, UID0001IG, UID0000SB, UID0002WA, and UID00026I.
- Pane, GrafPort, EventHandler, Event, RectBounds, SingletonTemplate, SurfaceRenderCallbackTable, Application screen globals, Config, SoundManager, MidiPlayer, and `g_pMidiPlayer` pages and generated interfaces.
- `InitializeMainUiGraph_004F7D10`, `MapPaneExitToMenuTeardown`, `client_audio`, and `proposed-source-tree`.
- Current manual by-file, by-class, by-memory, and by-global coverage rows.
- The dated pre-callback generated SoundStatusPane CPP/H and MidiPlayer CPP/header-absence baseline, plus Section 31's post-callback physical readback proving complete SoundStatusPane CPP/H and the now-present MidiPlayer header.
- The dated pre-callback generated `SoundManager.cpp/.h`, Section 31's post-callback standalone `SoundManager.h` readback, UID0000NV/UID0000DG/UID0004UF/UID0004WV, complete generated `Singleton.h`, `TimerHandler.h`, and `StringBase.h`, repository and `third_party_embeds` filename/content searches for `mss`, `Miles`, handle typedefs, `AILCALL`, and `AILCALLBACK`, and the report-time platform-type use.
- The repository contains no Miles SDK header, import-definition file, library, or equivalent typedef shim. `third_party_embeds` contains jsoncpp, libjpeg, lodepng, and zlib only. The dated report-time runtime/import evidence supplied `mss32.dll`, all 37 decorated `_AIL_*@N` names, exact stack-byte arities, and SoundManager call-site semantics.
- Dated report-time `type_inspect` proved `HSAMPLE`, `HDIGDRIVER`, `HSTREAM`, `HREDBOOK`, and `LPDIRECTSOUND` were four-byte pointers, while `U32` and `S32` were absent named IDB types. `SoundManager` was 4,268 bytes with 32 modeled members; its `SoundSampleSlot` was eight bytes with a four-byte `HSAMPLE` plus `int`. The same dated `inspect_items` evidence proved every Miles import was a four-byte data slot and preserved the decorated `__stdcall` arity; string readback found `mss32.dll` at `0x66BC20` and the Redbook decorated-name strings at `0x66BA38-0x66BB1A`.
- Searches for `0000NX`, `0000DJ`, `0001IG`, `0000SB`, `0002WA`, `SoundStatusPane`, `57bf70`, `57c2cf`, `69b4d4`, and relevant report names across active and executed B-report locations.

## Claim And Incorporation Ledger

| Claim ID | Target UID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- | --- |
| C0000NX-001 | 0000NX | Replace the sampled/stale file summary with the complete source-unit inventory, exact semantic/physical global model, and closed dependency/header route, and raise metadata from 89/91 to 94/95. | very-strong | Four source methods, four compiler functions, complete code/data inventory, generated audit, dated report-time canonical IDA readback, and source-complete SoundManager/MidiPlayer prerequisites. | by-file/SoundStatusPane.md metadata, Status, Likely Contents, dependency audit, Generated Output Caveats, Score Rationale | incorporate | implemented-awaiting-supervisor-Gate2A |
| C0000NX-002 | 0000DJ | Record direct bases Pane plus Singleton<SoundStatusPane>, the 0x108 layout, EBO overlap at +0xf8, and four distinct integer fields in left/right/top/bottom storage order. | very-strong | RTTI PMDs 0, +0xa0, +0xa4, +0xf8; constructor writes; Pane size 0xf8. | by-class/SoundStatusPane.md metadata, inheritance, layout, fields | incorporate | implemented-awaiting-supervisor-Gate2A |
| C0000NX-003 | 0000DJ | Replace class CPP commentary with the exact include preamble and `[[CHILDREN]]` route from Section 22; every included project header has a complete formal producer, including the repaired SoundManager and MidiPlayer headers. | very-strong | Existing emitter order, UID0001IG child ownership, and complete direct dependency audit. | by-class/SoundStatusPane.md RECONSTRUCTION_CPP CODE and dependency rationale | incorporate | implemented-awaiting-supervisor-Gate2A |
| C0000NX-004 | 0000DJ | Populate the exact complete SoundStatusPane class declaration and 0x108 size assertion from Section 22. | very-strong | Exact base declarations, override slots, field layout, constructor allocation size, and RTTI. | by-class/SoundStatusPane.md RECONSTRUCTION_H CODE | incorporate | implemented-awaiting-supervisor-Gate2A |
| C0000NX-005 | 0001IG | Replace the aggregate blank-policy text with the exact eight-function source/compiler disposition and raise metadata from 89/92 to 94/95. | very-strong | Exact modeled ranges, five internal padding spans, and source/compiler lowering. | by-memory/0x0057bf70-0x0057c2cf.SoundStatusPane.md metadata, Status, Item Summary, boundary map, Score Rationale | incorporate | implemented-awaiting-supervisor-Gate2A |
| C0000NX-006 | 0001IG | Emit the constructor with Pane(1), Singleton base construction, four screen-relative integers, and the non-escaping InitRectBounds local call. | original-proof | 0x57bf70-0x57c04d disassembly/decompilation and two 0x108-byte allocation callsites. | UID0001IG RECONSTRUCTION_CPP CODE and constructor evidence | incorporate | implemented-awaiting-supervisor-Gate2A |
| C0000NX-007 | 0000SB | Make UID0000SB CPP position zero include SoundStatusPane.h, define the sole pointer, and define exact Singleton constructor/destructor specializations. | very-strong | Singleton RTTI PMD +0xf8, publication/clear lowering, MiscWorkThread precedent, six global xrefs. | by-global/g_pSoundStatusPane.md RECONSTRUCTION_CPP CODE, ownership, lifecycle | incorporate | implemented-awaiting-supervisor-Gate2A |
| C0000NX-008 | 0001IG | Emit an empty ordinary SoundStatusPane destructor and attribute singleton clear/base teardown to implicit base destruction. | very-strong | 0x57c050-0x57c079 clear then Pane teardown; explicit Singleton specialization reproduces it. | UID0001IG RECONSTRUCTION_CPP CODE and destructor evidence | incorporate | implemented-awaiting-supervisor-Gate2A |
| C0000NX-009 | 0001IG | Emit exact HandleKeyOrTextEvent behavior, including pre-type key translation, lowercase exact-Control sound toggle, uppercase Control-bit music toggle, config write, duplicate MIDI/music calls, and inherited-bounds invalidation. | original-proof | 0x57c080-0x57c15b branches, calls, fields, vtable slot, and return values. | UID0001IG RECONSTRUCTION_CPP CODE and hotkey evidence | incorporate | implemented-awaiting-supervisor-Gate2A |
| C0000NX-010 | 0001IG | Emit exact OnPaint behavior, draw state, inherited-bounds fill, four caption choices, 128-wide-char buffer, `%s/%s` formatting, and text draw. | original-proof | 0x57c160-0x57c23e calls, callback, literals, and primary vtable slot +0x44. | UID0001IG RECONSTRUCTION_CPP CODE and paint evidence | incorporate | implemented-awaiting-supervisor-Gate2A |
| C0000NX-011 | 0001IG | Populate UID0001IG CPP with exactly the four ordinary methods from Section 22. | very-strong | Constructor/destructor/override source lowering is complete and compiler artifacts are separately covered. | UID0001IG RECONSTRUCTION_CPP CODE | incorporate | implemented-awaiting-supervisor-Gate2A |
| C0000NX-012 | 0001IG | Keep UID0001IG H blank because every declaration is owned by UID0000DJ's class header. | very-strong | One class declaration route avoids duplicate declarations and matches child emission topology. | UID0001IG RECONSTRUCTION_H CODE and source placement | already-present | already-present-awaiting-supervisor-Gate2A |
| C0000NX-013 | 0001IG | Classify 0x57c240-0x57c24b as compiler constructor-unwind singleton cleanup covered by the constructor and Singleton specialization; do not emit it. | original-proof | Constructor EH action calls the helper after adjusting to the Singleton subobject. | UID0001IG compiler-artifact map | incorporate | implemented-awaiting-supervisor-Gate2A |
| C0000NX-014 | 0001IG | Classify 0x57c24b-0x57c256 as the +0xa0 EventHandler-view scalar-destructor adjustor thunk; do not emit it. | original-proof | Exact subtract 0xa0 tail jump and secondary vtable slot zero. | UID0001IG compiler-artifact map | incorporate | implemented-awaiting-supervisor-Gate2A |
| C0000NX-015 | 0001IG | Classify 0x57c256-0x57c261 as the +0xa4 TimerHandler-view scalar-destructor adjustor thunk; do not emit it. | original-proof | Exact subtract 0xa4 tail jump and tertiary vtable slot zero. | UID0001IG compiler-artifact map | incorporate | implemented-awaiting-supervisor-Gate2A |
| C0000NX-016 | 0001IG | Classify 0x57c270-0x57c2cf as compiler scalar deleting destructor covered by the virtual destructor/delete lowering; do not emit it. | original-proof | Flags-based delete path, vtable references, singleton clear, base teardown, operator delete. | UID0001IG compiler-artifact map | incorporate | implemented-awaiting-supervisor-Gate2A |
| C0000NX-017 | 0001IG | Preserve the exact range and five internal plus two boundary padding spans without split, widening, or source emission. | original-proof | CC bytes at bf6e-bf70, c04d-c050, c079-c080, c15b-c160, c23e-c240, c261-c270, c2cf-c2d0. | UID0001IG range/padding analysis | incorporate | implemented-awaiting-supervisor-Gate2A |
| C0000NX-018 | 00026I | Add the exact three-vtable, 31-cell slot map and state that tables rebuild from class inheritance/overrides rather than raw source bytes. | original-proof | COLs at 62cef0/62cf3c/62cf6c and callable tables at 62cef4/62cf40/62cf70. | UID00026I SoundStatusPane read-only-data subsection | incorporate | implemented-awaiting-supervisor-Gate2A |
| C0000NX-019 | 00026I | Add the exact seven-node RTTI graph and preserve it as compiler-generated non-emitting evidence. | original-proof | Shared type descriptor/CHD, three COL offsets, seven BCD records and PMDs. | UID00026I SoundStatusPane RTTI subsection | incorporate | implemented-awaiting-supervisor-Gate2A |
| C0000NX-020 | 00026I | Preserve five caption literals as source literals consumed by OnPaint, not separately emitted aggregate data. | original-proof | UTF-16 strings at 62cf78, 62cf8c, 62cfa0, 62cfb4, 62cfc8 and direct method xrefs. | UID00026I literal ownership and UID0001IG paint evidence | incorporate | implemented-awaiting-supervisor-Gate2A |
| C0000NX-021 | 0000SB | Preserve one external-linkage H declaration and semantic ownership while raising metadata from 92/94 to 94/95; bind the semantic name only to address `0x69B4D4`, never to a claimed physical item name. | very-strong | Sole definition route, six xrefs, exact semantic `g_pSoundStatusPane -> 0x69B4D4` binding, physical child, and complete singleton specialization source. | by-global/g_pSoundStatusPane.md metadata, H channel, lifecycle, Score Rationale | incorporate | implemented-awaiting-supervisor-Gate2A |
| C0000NX-022 | 0002WA | Preserve range `[0x69B4D4,0x69B4D8)` as ignored, non-reconstructable/non-emitting evidence with unchanged metadata and blank formal source, but replace its obsolete single-four-byte-item description with the exact four target one-byte undefined heads inside the six-head neighborhood. | original-proof | Dated report-time item/type/name/comment/byte readback, exact six/zero/eight adjacent xref partition, semantic one-definition route, and C031 NO_CHANGE protection. | by-memory/0x0069b4d4-0x0069b4d8.g_pSoundStatusPane.md Status, Item Summary, Current IDA State, physical model, Score Rationale | incorporate | implemented-awaiting-supervisor-Gate2A |
| C0000NX-023 | 0000NX | Preserve both InitializeMainUiGraph constructor calls and their preceding operator new(0x108) allocations as the two layout branches. | original-proof | Calls at 4f8460 and 4f89c7 from the same main-UI function. | by-file/SoundStatusPane.md callers and by-item/InitializeMainUiGraph_004F7D10.md | already-present | already-present-awaiting-supervisor-Gate2A |
| C0000NX-024 | 0002QH | Record MapPane exit-to-menu as the sole external global consumer and preserve deferred BlackHole deletion rather than direct delete or global clear. | original-proof | Read at 0x5048e6 and current source-ready teardown body. | UID0002QH relationship/callee evidence and SoundStatusPane cross-reference | incorporate | implemented-awaiting-supervisor-Gate2A |
| C0000NX-025 | 0000DG,0004UF | Preserve SoundManager as the external effect/music dependency; make UID0004UF open the guarded standalone H preamble, emit the local platform/Miles declarations and exact `g_pSoundManager` extern, and make UID0000DG emit the complete class then close the guard while retaining internal MIDI coordination. | very-strong | Exact live calls, current class surface, deterministic emitter order, complete project/platform prerequisites, all 37 decorated Miles imports, current handle widths, and UID0004UF's cross-module contract. | by-global/g_pSoundManager.md H channel/dependency/coverage; by-class/SoundManager.md H channel/dependencies/cross-reference; UID0000NX dependency audit | incorporate | implemented-awaiting-supervisor-Gate2A |
| C0000NX-026 | 00008A,0000LD,0000RM | Replace MidiPlayer class CPP commentary with `#include "MidiPlayer.h"`, add the complete class H declaration and UID0000RM singleton extern, document SoundStatusPane as a consumer, and raise class/file/global metadata to 89/92, 89/91, and 89/92. | strong | At the dated pre-callback baseline, generated MidiPlayer.cpp defined the full public surface without any include, MidiPlayer.h was absent, and semantic global UID0000RM had a blank H channel; producer and consumer require one class declaration plus one extern. | by-class/MidiPlayer.md CPP/H channels/cross-reference/metadata; by-file/MidiPlayer.md generated audit/metadata; by-global/g_pMidiPlayer.md H channel/metadata | incorporate | implemented-awaiting-supervisor-Gate2A |
| C0000NX-027 | 0000NX | Preserve Application, Config, Event/EventMan, Pane/GrafPort/RectBounds, Surface callback, SoundManager, and MidiPlayer contracts as exact dependencies and document the now-complete direct include/type/declaration closure. | very-strong | Section 22 supplies every required name, complete base/member type, enum, method, callback, global, Win32/DirectSound type, and local Miles declaration without implicit PCH or unavailable SDK assumptions. | by-file/SoundStatusPane.md dependency/include audit | incorporate | implemented-awaiting-supervisor-Gate2A |
| C0000NX-028 | 0000NX | Keep `NexusTK/ui/panels/` placement, update client_audio relationships, and reject proposed-tree/generated caveats that treat the empty output as complete. | very-strong | Main UI ownership, pane inheritance, audio-HUD role, and literal generated readback. | by-project-structure/proposed-source-tree.md, by-meta/client_audio.md, by-file/SoundStatusPane.md | reject-stale | implemented-awaiting-supervisor-Gate2A |
| C0000NX-029 | 0001IG | At 0x57c080 use current-schema `rename` with `pure:true` for `SoundStatusPane__HandleKeyOrTextEvent`, then `set_repeatable_comments` for the one permitted function-repeatable comment; create no action-attributable `/vibe/` directory placement or decompiler/cache refresh and permit no other delta. | original-proof | Dated report-time canonical readback: exact function [57c080,57c15b), raw type, four absent comment channels, three frame rows, 219-byte SHA256 6B8B023994A746CD9B1141861950F0E839EC2038FD2788BEC1C2D2BE78FBDFD7, sole incoming xref 62cf48, zero desired-name collisions, and pure dry-run with no `dir`/`dir_error` fields while the non-pure control reports planned `dir:"vibe"`. | Section 21 C029 literal prestate/request/poststate | incorporate | proposed |
| C0000NX-030 | 0001IG | At 0x57c160 use current-schema `rename` with `pure:true` for `SoundStatusPane__OnPaint`, then `set_repeatable_comments` for the one permitted function-repeatable comment; create no action-attributable `/vibe/` directory placement or decompiler/cache refresh and permit no other delta. | original-proof | Dated report-time canonical readback: exact function [57c160,57c23e), raw type, four absent comment channels, four frame rows, 222-byte SHA256 F6484919A4F824DF33F445EC2B1B4F51CA87D008FCE5805DD035EDCB08C14AC3, sole incoming xref 62cf38, zero desired-name collisions, and pure dry-run with no `dir`/`dir_error` fields while the non-pure control reports planned `dir:"vibe"`. | Section 21 C030 literal prestate/request/poststate | incorporate | proposed |
| C0000NX-031 | 0000SB,0002WA | `NO_CHANGE`: verify and preserve the six one-byte undefined heads at 0x69b4d3-0x69b4d9, including four target heads, first-head type `SoundStatusPane *`, empty physical item names/comments, zero bytes, adjacent-head types, and complete target/predecessor/successor xrefs 6/0/8; call no data, rename, type, or comment endpoint. | original-proof | Dated report-time canonical readback preserved all six heads and bytes; `g_pSoundStatusPane` resolves as the sole existing address/global name at the target while every inspected physical item name remains empty, so there is no off-target collision and no deterministic typed-aggregate mutation is authorized. | Section 21 C031 literal NO_CHANGE prestate/protection/readback | already-present | proposed |
| C0000NX-032 | 0000NX | During an accepted callback, B009 implements/verifies C001-C028 plus C034-C037 ordinary-page work, runs only scoped ordinary-page validators, records their receipts, waits for generated refresh, and physically proves SoundStatusPane/MidiPlayer/SoundManager output against the command/timestamp actually returned by that callback; no fixed earlier command is timeless authority, and B009 does not edit manual coverage or lifecycle state. | strong | Dated pre-callback physical baseline at 2026-08-24T04:52:41.6321272Z is command 27320 with exact CPP/H hashes and MidiPlayer.h absence; Section 31 requires fresh callback receipts and exact standalone SoundManager.h inventory readback without supervisor-owned side effects. | Changed ordinary pages, Section 31 validator receipts, generated CPP/H readback | incorporate | implemented-awaiting-supervisor-Gate2A |
| C0000NX-033 | 0000NX | After B009 callback work and supervisor verification, only the supervisor applies Section 28's twelve literal rows for by-file UID0000NX/UID0000LD/UID0000NV, by-class UID0000DJ/UID00008A/UID0000DG, by-memory UID0001IG/UID0002WA, by-global UID0000SB/UID0004UF/UID0000RM, and by-item UID0004WV, then owns Gate 2, report execution, archive movement/history, and archived-artifact audit. | original-proof | Section 28 contains those twelve exact rows; skill/goal assign every manual coverage replacement and lifecycle boundary to the supervisor, never B009. | Twelve named manual coverage rows in Section 28 and supervisor-owned lifecycle | incorporate | proposed |
| C0000NX-034 | 0000SB | Atomically replace every obsolete four-byte/current-physical-name statement on the semantic global page with the verified six one-byte-head neighborhood, four target heads, first-head-only type, empty physical item names/comments, and separate semantic `g_pSoundStatusPane -> 0x69B4D4` binding; preserve C031 NO_CHANGE. | original-proof | Dated report-time `inspect_items`, bytes/hash, type, comments, exact name/global collision readback, and xrefs 6/0/8. | by-global/g_pSoundStatusPane.md Status, Current IDA State, lifecycle, storage, IDA mapping, Score Rationale, Changes | incorporate | implemented-awaiting-supervisor-Gate2A |
| C0000NX-035 | 0002WA | Atomically replace every obsolete single-four-byte-item/current-name statement on the physical page with the exact six-head table and target/subrange distinction; state that range metadata does not imply an IDA aggregate and that no rename/type/data/comment endpoint is authorized. | original-proof | Six separate one-byte undefined heads at 0x69B4D3-0x69B4D8, zero-byte hash, d4-only pointer type, empty physical names/comments, and C031 NO_CHANGE. | by-memory/0x0069b4d4-0x0069b4d8.g_pSoundStatusPane.md Status, Item Summary, Current IDA State, evidence, non-emission, Score Rationale, Changes | incorporate | implemented-awaiting-supervisor-Gate2A |
| C0000NX-036 | 0004UF,0000DG | Add the exact standalone SoundManager header split: UID0004UF opens `NEXUSTK_AUDIO_SOUNDMANAGER_H`, includes `<windows.h>`, `<dsound.h>`, `<string.h>`, `<vector>`, `../util/Singleton.h`, `../util/StringBase.h`, and `../util/TimerHandler.h`, then declares the global; UID0000DG removes incomplete forward substitutes, emits the full class with era-compatible integer spellings, and closes the guard. | very-strong | Complete bases and vector element require full definitions; current StringBase inline requires `_strlwr_s`; current sibling generated guards and relative include style; Windows SDK owns HWND/DirectSound types; deterministic positions 0/10. | by-global/g_pSoundManager.md and by-class/SoundManager.md exact RECONSTRUCTION_H CODE/dependency prose | incorporate | implemented-awaiting-supervisor-Gate2A |
| C0000NX-037 | 0004UF,0000DG,0000NV,0004WV | Add the exact in-header local Miles compatibility block from Section 22: 32-bit signed/unsigned aliases, four opaque four-byte handles, `AILCALL`/`AILCALLBACK`, five callback-pointer types, and all 37 `extern "C"` declarations; document why the unavailable SDK/new shim/PCH/implicit-declaration alternatives are rejected and preserve UID0004WV's four source-static callback declarations unchanged. | strong | No local SDK/header/shim/import library; dated report-time 37-name decorated import set and arities; IDB handle widths; callback bodies/signatures; runtime `mss32.dll` string; complete SoundManager use inventory. | by-global/g_pSoundManager.md H channel; by-class/SoundManager.md dependency audit; by-file/SoundManager.md source/header/platform audit; by-item/SoundManagerMilesCallbackDeclarations.md type-source rationale | incorporate | implemented-awaiting-supervisor-Gate2A |

## Positive Evidence Summary

The binary contains a coherent 0x108-byte `SoundStatusPane` object with Pane at offset zero, inherited EventHandler and TimerHandler views at `+0xa0`/`+0xa4`, an empty Singleton base at `+0xf8`, and four derived integers through `+0x104`. Two main-UI branches allocate 0x108 bytes and call the same constructor. The source island has exactly four handwritten methods and four compiler-generated functions. The global has exact publication, ordinary destruction, unwind, scalar destruction, and MapPane consumer xrefs. Three vtables and a seven-node RTTI graph agree with the source inheritance. Five captions and every called method surface are resolved. Section 22 repairs both missing producer/consumer declaration routes and closes SoundManager's complete direct header chain with repository, platform-SDK, and bounded local Miles declarations.

This evidence is sufficient to remove both valid empty emitters without inventing raw compiler bodies.

## IDA MCP Facts

- Preserved C029-C031 observation (`2026-08-24T04:49:23.8395869Z` physical identity; bounded sweep complete `2026-08-24T04:52:45.2009630Z`): session `supervisor_canonical_research_20260824_0215`; 143,210,351 bytes; SHA256 `E9B0427DE8B83E74DB479218B3B640AAAC78961813222A2B52B11A8927E9E104`; worker PID `13088`. This is dated proof for those rows, not the active session/file tuple.
- Dated report-time read-only observation: session `supervisor_canonical_research_20260824_0503`, worker PID `21796`, canonical IDB path `E:\\NTK\\Resources\\NexusTK\\NexusTK.exe.i64`, 143,211,656 bytes, last write `2026-08-24T04:50:38.7719770Z`, SHA256 `457A3EF7DAEB4E22245E115EAAB4EEB2CE9695CCC965891A9663F866C264F087`; health was `ok`, image base `0x400000`, Hex-Rays and 2,067-entry string cache were ready. This tuple is historical evidence, not current authority. Future supervisor Gate 2B must establish fresh runtime/session/path/disk authority and recheck every literal prestate.
- Names/types observed in that dated read were `SoundStatusPane__Constructor` at `0x57bf70`, `SoundStatusPane__Destructor` at `0x57c050`, raw `sub_57C080`, raw `sub_57C160`, `SoundStatusPane__ConstructorUnwindClearSingleton`, raw adjustors `sub_57C24B`/`sub_57C256`, and `SoundStatusPane__ScalarDeletingDestructor`.
- The raw override types observed in that dated read are unsafe to replace: `char __thiscall(_DWORD *this, _BYTE *)` at `0x57c080` and `void __thiscall(GrafPort *this)` at `0x57c160`. The first receives an adjusted secondary `this`; no stable complete SoundStatusPane UDT was present. Recommend rename/comment only after fresh supervisor prestate verification.
- The physical neighborhood observed in that dated read had six separate one-byte undefined heads from `0x69B4D3` through `0x69B4D8`. The four target heads were `0x69B4D4-0x69B4D7`; only `0x69B4D4` had type `SoundStatusPane *`, all four target physical item-name/comment fields were empty, and all six bytes were zero. Separately, the dated exact names/globals lookup resolved the semantic `g_pSoundStatusPane` binding to `0x69B4D4` with no off-target collision. A semantic address binding is not a physical item-name field and does not imply one four-byte IDA item.
- The dated dependency sweep found exactly 37 `mss32` imports from `0x60D5B4-0x60D644`. Decorated `@N` suffixes proved `__stdcall` stack arities 0/4/8/12/16; the report-time IDB modeled the four handles and `LPDIRECTSOUND` as four-byte pointers, had no named `U32`/`S32`, and exposed the exact SoundManager/SoundSampleSlot sizes used by Section 22.
- Repeatable function comments observed in that dated read on constructor, ordinary destructor, unwind helper, and scalar deleting destructor are usable and should be preserved if fresh Gate 2B readback matches. The two overrides had no function comments at report time.
- No IDA mutation or save was performed.

The exact primary vtable is preceded by COL pointer `0x62cef0 -> 0x650530` and starts at `0x62cef4`:

| Slot | Target | Source disposition |
| --- | --- | --- |
| `+0x00` | `0x57c270` SoundStatusPane scalar deleting destructor | Compiler-covered from virtual destructor. |
| `+0x04` | `0x4f4b10` LObject::GetRuntimeClass | Inherited. |
| `+0x08` | `0x41b6c0` LObject::OnChangeMessage | Inherited. |
| `+0x0c` | `0x4b8e20` GrafPort::UpdateRenderRegion | Inherited. |
| `+0x10` | `0x41d680` Pane::DrawOnTarget | Inherited. |
| `+0x14` | `0x544730` Pane::Show | Inherited. |
| `+0x18` | `0x544750` Pane::Hide | Inherited. |
| `+0x1c` | `0x5447a0` Pane::GetParentPane | Inherited. |
| `+0x20` | `0x544800` Pane::InvalidateRect | Inherited. |
| `+0x24` | `0x544a20` Pane::GetDescription | Inherited. |
| `+0x28` | `0x544b80` Pane::GetScreenBounds | Inherited. |
| `+0x2c` | `0x544bd0` Pane::SetBounds | Inherited. |
| `+0x30` | `0x544c70` Pane::AddToLayer | Inherited. |
| `+0x34` | `0x544cb0` Pane::InsertInLayer | Inherited. |
| `+0x38` | `0x544ce0` Pane::RemoveFromLayer | Inherited. |
| `+0x3c` | `0x544d30` Pane::SetPaneOrder | Inherited. |
| `+0x40` | `0x544d70` Pane::UnregisterEventHandler | Inherited. |
| `+0x44` | `0x57c160` SoundStatusPane::OnPaint | Handwritten override; emit. |

The exact EventHandler secondary vtable is preceded by COL pointer `0x62cf3c -> 0x6505e0` and starts at `0x62cf40`:

| Slot | Target | Source disposition |
| --- | --- | --- |
| `+0x00` | `0x57c24b` +0xa0 scalar-destructor adjustor | Compiler-covered. |
| `+0x04` | `0x544db0` Pane::HandlePointerOrMouseEvent | Inherited. |
| `+0x08` | `0x57c080` SoundStatusPane::HandleKeyOrTextEvent | Handwritten override; emit. |
| `+0x0c` | `0x544dd0` Pane::HandleImeEvent | Inherited. |
| `+0x10` | `0x544de0` Pane::HandlePacketEvent | Inherited. |
| `+0x14` | `0x544df0` Pane::HandleSystemOrControlEvent | Inherited. |
| `+0x18` | `0x544e00` Pane::HandleType19Event | Inherited. |
| `+0x1c` | `0x4a89f0` EventHandler::ForwardHandlerOrder | Inherited. |
| `+0x20` | `0x544e10` Pane::GetLocalOffset | Inherited. |
| `+0x24` | `0x544e30` Pane::GetScreenOffset | Inherited. |
| `+0x28` | `0x544e70` Pane::ShouldAcceptEvent | Inherited. |

The exact TimerHandler tertiary vtable is preceded by COL pointer `0x62cf6c -> 0x6505f4` and starts at `0x62cf70`:

| Slot | Target | Source disposition |
| --- | --- | --- |
| `+0x00` | `0x57c256` +0xa4 scalar-destructor adjustor | Compiler-covered. |
| `+0x04` | `0x544e90` Pane::OnTimer | Inherited. |

All three COLs share type descriptor `0x6792b8` and class hierarchy descriptor `0x650544`; COL object offsets are zero, `0xa0`, and `0xa4`. The hierarchy has signature zero, attributes one, seven base descriptors, and base array `0x650554`:

| BCD | Type descriptor / decorated name | Contained bases | PMD mdisp/pdisp/vdisp | Attribute |
| --- | --- | ---: | --- | --- |
| `0x650574` | `0x6792b8` / `.?AVSoundStatusPane@@` | 6 | `0/-1/0` | `0x40` |
| `0x640540` | `0x6739a0` / `.?AVPane@@` | 4 | `0/-1/0` | `0x40` |
| `0x640584` | `0x6739b4` / `.?AVGrafPort@@` | 1 | `0/-1/0` | `0x40` |
| `0x640348` | `0x6738c0` / `.?AVLObject@@` | 0 | `0/-1/0` | `0x40` |
| `0x6405bc` | `0x6739cc` / `.?AVEventHandler@@` | 0 | `0xa0/-1/0` | `0x40` |
| `0x64060c` | `0x6739e8` / `.?AVTimerHandler@@` | 0 | `0xa4/-1/0` | `0x40` |
| `0x650590` | `0x6792d8` / `.?AV?$Singleton@VSoundStatusPane@@@@` | 0 | `0xf8/-1/0` | `0x40` |

The exact source-owned caption literals are `Music On` at `0x62cf78`, `Music Off` at `0x62cf8c`, `Sound On` at `0x62cfa0`, `Sound Off` at `0x62cfb4`, and `%s/%s` at `0x62cfc8`.

## Function / Child Inventory

| Range | Bytes | Disposition |
| --- | ---: | --- |
| `0x57bf6e-0x57bf70` | 2 | Preceding CC padding; exclude. |
| `0x57bf70-0x57c04d` | 221 | Handwritten constructor; emit. |
| `0x57c04d-0x57c050` | 3 | CC alignment; exclude. |
| `0x57c050-0x57c079` | 41 | Handwritten ordinary destructor lowering; emit empty source destructor. |
| `0x57c079-0x57c080` | 7 | CC alignment; exclude. |
| `0x57c080-0x57c15b` | 219 | Handwritten `HandleKeyOrTextEvent`; emit. |
| `0x57c15b-0x57c160` | 5 | CC alignment; exclude. |
| `0x57c160-0x57c23e` | 222 | Handwritten `OnPaint`; emit. |
| `0x57c23e-0x57c240` | 2 | CC alignment; exclude. |
| `0x57c240-0x57c24b` | 11 | Compiler constructor-unwind singleton clear; covered, no emission. |
| `0x57c24b-0x57c256` | 11 | Compiler +0xa0 adjustor thunk; covered, no emission. |
| `0x57c256-0x57c261` | 11 | Compiler +0xa4 adjustor thunk; covered, no emission. |
| `0x57c261-0x57c270` | 15 | CC alignment; exclude. |
| `0x57c270-0x57c2cf` | 95 | Compiler scalar deleting destructor; covered, no emission. |
| `0x57c2cf-0x57c2d0` | 1 | Trailing CC padding; exclude. |
| `0x57c2d0...` | n/a | SpellInventoryPane constructor successor; exclude. |

Whole-file totals: four ordinary methods; four compiler functions; five internal alignment spans; two external boundary spans; one semantic global and one physical backing child; three vtables with 31 callable cells; three COL pointers; seven RTTI base descriptors; five caption literals; four derived integers; zero file-owned resources, imports, other statics, or standalone helpers.

## Direct Xref / Caller Inventory

- Constructor: calls at `0x4f8460` and `0x4f89c7`, both from `MainMenuPane_InitializeMainUiGraph`; each is immediately preceded by `operator new(0x108)`.
- Ordinary destructor: no direct ordinary caller; reached through virtual/compiler destruction lowering.
- Key handler: secondary vtable cell `0x62cf48`; no direct source caller.
- OnPaint: primary vtable cell `0x62cf38`; no direct source caller.
- Constructor-unwind helper: constructor EH action near `0x608658` after selecting the Singleton subobject; not a source callsite.
- Adjustors: secondary and tertiary vtable slot-zero entries; both tail-jump to scalar destruction.
- Scalar deleting destructor: referenced by primary vtable and both adjustors.
- `g_pSoundStatusPane` six refs: MapPane read `0x5048e6`; constructor publish/fallback `0x57bfc0`/`0x57bfc7`; ordinary destructor clear `0x57c06a`; unwind clear `0x57c240`; scalar destructor clear `0x57c290`.
- External callees are Pane/Singleton construction and teardown, `InitRectBounds`, EventMan translation, SoundManager and MidiPlayer state/toggle methods, GrafPort drawing methods, `g_pfnFillRect`, `swprintf_s`, and `wcslen`.

## Documentation Evidence And IDA Status

Before the accepted callback, the ordinary pages established source placement, Pane-derived purpose, singleton ownership, main-UI construction, physical storage, and audio-HUD behavior, but still had stale generated-output claims, blank formal channels, the old aggregate blank policy, incomplete override/field detail, an incomplete vtable/RTTI map, and stale one-four-byte-item prose on both `g_pSoundStatusPane` pages. Those defects are historical pre-callback findings. The callback populated the accepted formal CPP/H channels and complete ordinary detail, added the exact compiler-data map, and corrected both semantic/physical global pages. Section 31 records the 17 scoped receipts and the post-callback physical readback: generated SoundStatusPane CPP/H are complete with zero target empty markers, and `MidiPlayer.h` now exists with its complete class/extern route.

Before the callback, generated `SoundManager.h` was dependency-incomplete: it used complete bases and `std::vector<SoundPathString>` members without including their definitions, used Win32/DirectSound/Miles types without providers, and had no guard/global extern. That pre-callback defect justified C025/C027/C036/C037 and Section 22's exact local preamble. A new compatibility file remains rejected because no owner/UID or existing source artifact supports it; `<mss.h>` remains rejected because it is absent; precompiled-header and implicit-declaration routes remain rejected because generated headers must be standalone; copying an unverifiable third-party SDK remains rejected. The current post-callback truth is the Section 31 command-27401 physical readback: `SoundManager.h` is standalone with one main guard, seven direct includes, the bounded local Miles compatibility block, one global extern, one complete class, and no unavailable Miles include or unresolved declaration.

The dated report-time IDA read observed stable descriptive names for construction/destruction compiler endpoints and raw names for both source overrides. It is not current authority. Section 21 therefore hands the supervisor exactly two conditional actions plus one no-change verification: C029/C030 are deterministic pure rename/comment improvements only if fresh Gate 2B prestate matches, while C031 protects the existing global heads and authorizes no endpoint.

## Ranked Ownership Analysis

1. UID0000NX / `NexusTK/ui/panels/SoundStatusPane.cpp`: definitive compilation-unit owner. All object-specific code, semantic global, captions, and compiler metadata cohere here.
2. UID0000DJ: definitive class declaration and class-level CPP preamble emitter.
3. UID0001IG: definitive ordinary method-body emitter; compiler members are coverage-only within the same island.
4. UID0000SB: definitive semantic singleton symbol and explicit Singleton-specialization emitter.
5. UID0002WA: definitive physical storage evidence, intentionally non-emitting.
6. UID00026I: definitive mixed read-only compiler/data index, intentionally non-emitting.

Rejected owners: SoundManager and MidiPlayer own audio engines, MapPane is a teardown consumer, Application/main UI is a constructor caller, Pane/EventHandler/TimerHandler are inherited framework bases, and Surface owns the fill callback.

## Source Placement

Keep `SoundStatusPane.cpp` and `SoundStatusPane.h` under `NexusTK/ui/panels/`. The unit is a small persistent HUD pane driven by main-UI construction, Pane rendering/event virtuals, and audio managers. It is not an audio-engine source file because it owns no playback engine state. It is not a core Pane source because its singleton, geometry, hotkeys, and captions are feature-specific.

Emission order remains UID0000SB at position zero, UID0000DJ class aggregate, then UID0001IG through `[[CHILDREN]]`. UID0000SB's first line includes `SoundStatusPane.h`, so its pointer definition and explicit template specializations see the complete derived type before the later child method definitions.

## Range / Split / Padding / Reclassification Analysis

Keep UID0001IG at `0x57bf70-0x57c2cf`. No split is warranted: all eight modeled functions are one class-local lowering family, exact subranges are documented, and source/compiler dispositions are individually explicit. Splitting compiler artifacts would create emitters with no legitimate handwritten source and would not improve ownership.

Preserve all five internal CC gaps and the two one-sided boundary gaps exactly. Do not widen into predecessor padding or the SpellInventoryPane successor. Do not reclassify vtables, RTTI, or captions into the code range; UID00026I remains their mixed read-only index.

## Negative Evidence Summary

- No SoundStatusPane-owned resource, import, message map, packet protocol, file-static helper, additional writable static, or hidden sibling method was found.
- No evidence supports TextButtonExControlPane inheritance or direct EventHandler/TimerHandler source bases.
- No evidence supports a RectBounds member at `+0xf8`; field storage order contradicts it.
- No event path references the four derived geometry integers after construction within this island; invalidation and fill use inherited `m_visibleBounds`.
- No ordinary caller reaches the destructor, unwind helper, adjustors, or scalar destructor directly.
- No legitimate source requires raw vtable, RTTI, COL, BCD, or padding definitions.
- No duplicate definition belongs on UID0002WA.
- At the dated pre-callback command-27320 baseline, no generated SoundStatusPane method or class declaration was present despite stale documentation saying otherwise. That negative evidence is historical; Section 31's command-27405 post-callback readback proves complete generated CPP/H with zero target empty markers.
- At the dated pre-callback baseline, no MidiPlayer sibling header existed, so a forward declaration alone was insufficient. That negative evidence is historical; Section 31's command-27397 post-callback readback proves `MidiPlayer.h` now exists with one guard, complete 0x0c class/size assertion, and singleton extern.
- At the dated pre-callback baseline, generated `SoundManager.h` was not standalone. That negative evidence is historical; Section 31's command-27401 post-callback readback proves the complete standalone guard/include/local-Miles/global/class route.

Evidence that would change the result would require contradictory original symbols/source, a distinct function/data xref inside the unit, or a current base/header contract that invalidates one of the exact calls. None was found.

## IDA Rename / Type / Comment Recommendations

Only the supervisor may perform this exact Gate 2B disposition: two actions plus one no-change verification. Fresh read-only evidence was rebound at `2026-08-24T04:49:15Z` and physically sealed at `2026-08-24T04:49:23.8395869Z` from canonical IDB `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`, 143,210,351 bytes, SHA256 `E9B0427DE8B83E74DB479218B3B640AAAC78961813222A2B52B11A8927E9E104`; the dated session/PID observation was `supervisor_canonical_research_20260824_0215` / `13088`. Health was `ok`, image base `0x400000`, Hex-Rays/string cache ready, with `auto_analysis_ready:false` retained as non-blocking context. The bounded C029-C031 sweep completed at `2026-08-24T04:52:45.2009630Z`. No IDA mutation/save was performed.

The request records below are inert schema handoffs, not a transaction package. The schema-valid string value `"DB"` is a stand-in that the supervisor must replace with the exact transaction session identifier returned by its runtime-bound `idb_open` with `run_auto_analysis:false`; it never denotes the read-only canonical research session. Every other request field/value is literal. Before each action, the supervisor must freshly re-read the prestate, use current runtime attestation/backup/save/rollback controls, and stop on any mismatch.

**C0000NX-029: `0x57c080` function prestate**

| Property | Literal current value |
| --- | --- |
| Function bounds | `[0x57c080,0x57c15b)`, size `0xdb` / 219 bytes. Entry instruction item is head `0x57c080`, end `0x57c081`, size 1, `is_code:true`, `is_data:false`. |
| Name | `sub_57C080` |
| Desired-name collision | `lookup_funcs("SoundStatusPane__HandleKeyOrTextEvent")` returned `Not found`; exact-name `entity_query(kind:"names")` returned total 0. Both current-schema dry-runs passed with `allow_overwrite:false`; there is no occupant to overwrite. |
| `/vibe/` / cache prestate | The `pure:true` dry-run returned only address, old name, desired name, and `dry_run:true`, with no `dir` or `dir_error`; the paired non-pure control returned planned `dir:"vibe"`. No rename, directory placement, force-recompile, decompile, or cache-refresh operation ran. This is the endpoint-visible prestate/side-effect boundary. |
| Type | `char __thiscall(_DWORD *this, _BYTE *)` |
| Address regular comment | absent (`regular:""`) |
| Address repeatable comment | absent (`repeatable:""`) |
| Function regular comment | absent (`function_regular:""`) |
| Function repeatable comment | absent (`function_repeatable:""`) |
| Frame/local row 1 | `__saved_registers`, offset `0x8`, size `0x4`, type `_DWORD` |
| Frame/local row 2 | `__return_address`, offset `0xc`, size `0x4`, type `_UNKNOWN *` |
| Frame/local row 3 | `arg_0`, offset `0x10`, size `0x4`, type `_DWORD` |
| Other frame/local rows | none returned by `stack_frame` |
| Body seal | 219 bytes; SHA256 `6B8B023994A746CD9B1141861950F0E839EC2038FD2788BEC1C2D2BE78FBDFD7`; first 8 bytes `55 8b ec 56 8b 75 08 57`; last 8 bytes `5f 32 c0 5e 5d c2 04 00`. |
| Complete incoming xref set | Exactly one data xref, `0x62cf48 -> 0x57c080`; no next page. |

Exact current-schema requests, in order:

1. Endpoint `rename`; request `{"database":"DB","batch":{"func":[{"addr":"0x57c080","name":"SoundStatusPane__HandleKeyOrTextEvent"}],"pure":true,"allow_overwrite":false,"dry_run":false,"stop_on_error":true}}`.
2. Endpoint `set_repeatable_comments`; request `{"database":"DB","items":[{"addr":"0x57c080","comment":"SoundStatusPane key handler: Ctrl+m toggles sound effects, Ctrl+Shift+M toggles MIDI/music, then invalidates the inherited visible bounds."}]}`.

Permitted deltas are only the function name and function-repeatable comment. Expected literal readback: bounds `[0x57c080,0x57c15b)`, entry code item `[0x57c080,0x57c081)`, type `char __thiscall(_DWORD *this, _BYTE *)`, all three frame rows and no others, 219-byte body seal/edge bytes, and sole incoming xref `0x62cf48` remain exact; name becomes `SoundStatusPane__HandleKeyOrTextEvent`; function-repeatable comment becomes the exact text above; address regular, address repeatable, and function regular channels remain absent. Because `pure:true` skips function-directory placement and decompiler refresh, the receipt must contain no action-attributable `dir`/`dir_error`, `/vibe/` state, force-recompile, decompile, or cache-refresh effect. No type, frame, local, byte, xref, bound, entry-item, or unlisted-comment change is allowed.

**C0000NX-030: `0x57c160` function prestate**

| Property | Literal current value |
| --- | --- |
| Function bounds | `[0x57c160,0x57c23e)`, size `0xde` / 222 bytes. Entry instruction item is head `0x57c160`, end `0x57c161`, size 1, `is_code:true`, `is_data:false`. |
| Name | `sub_57C160` |
| Desired-name collision | `lookup_funcs("SoundStatusPane__OnPaint")` returned `Not found`; exact-name `entity_query(kind:"names")` returned total 0. Both current-schema dry-runs passed with `allow_overwrite:false`; there is no occupant to overwrite. |
| `/vibe/` / cache prestate | The `pure:true` dry-run returned only address, old name, desired name, and `dry_run:true`, with no `dir` or `dir_error`; the paired non-pure control returned planned `dir:"vibe"`. No rename, directory placement, force-recompile, decompile, or cache-refresh operation ran. This is the endpoint-visible prestate/side-effect boundary. |
| Type | `void __thiscall(GrafPort *this)` |
| Address regular comment | absent (`regular:""`) |
| Address repeatable comment | absent (`repeatable:""`) |
| Function regular comment | absent (`function_regular:""`) |
| Function repeatable comment | absent (`function_repeatable:""`) |
| Frame/local row 1 | `Buffer`, offset `0x8`, size `0x2`, type `wchar_t` |
| Frame/local row 2 | `var_4`, offset `0x108`, size `0x4`, type `_DWORD` |
| Frame/local row 3 | `__saved_registers`, offset `0x10c`, size `0x4`, type `_DWORD` |
| Frame/local row 4 | `__return_address`, offset `0x110`, size `0x4`, type `_UNKNOWN *` |
| Other frame/local rows | none returned by `stack_frame` |
| Body seal | 222 bytes; SHA256 `F6484919A4F824DF33F445EC2B1B4F51CA87D008FCE5805DD035EDCB08C14AC3`; first 8 bytes `55 8b ec 81 ec 04 01 00`; last 8 bytes `f5 b4 04 00 8b e5 5d c3`. |
| Complete incoming xref set | Exactly one data xref, `0x62cf38 -> 0x57c160`; no next page. |

Exact current-schema requests, in order:

1. Endpoint `rename`; request `{"database":"DB","batch":{"func":[{"addr":"0x57c160","name":"SoundStatusPane__OnPaint"}],"pure":true,"allow_overwrite":false,"dry_run":false,"stop_on_error":true}}`.
2. Endpoint `set_repeatable_comments`; request `{"database":"DB","items":[{"addr":"0x57c160","comment":"Paints the inherited visible bounds and draws the current Sound On/Off and Music On/Off status caption."}]}`.

Permitted deltas are only the function name and function-repeatable comment. Expected literal readback: bounds `[0x57c160,0x57c23e)`, entry code item `[0x57c160,0x57c161)`, type `void __thiscall(GrafPort *this)`, all four frame rows and no others, 222-byte body seal/edge bytes, and sole incoming xref `0x62cf38` remain exact; name becomes `SoundStatusPane__OnPaint`; function-repeatable comment becomes the exact text above; address regular, address repeatable, and function regular channels remain absent. Because `pure:true` skips function-directory placement and decompiler refresh, the receipt must contain no action-attributable `dir`/`dir_error`, `/vibe/` state, force-recompile, decompile, or cache-refresh effect. No type, frame, local, byte, xref, bound, entry-item, or unlisted-comment change is allowed.

**C0000NX-031: `0x69b4d4` `NO_CHANGE` data protection**

All four target heads and both adjacent heads were enumerated in the dated report-time canonical observation. None may be replaced unless fresh supervisor Gate 2B readback exactly matches:

| Address/head range | Name | Type | Width | Kind | Regular / repeatable address comments | Byte |
| --- | --- | --- | ---: | --- | --- | --- |
| Protected `0x69b4d3-0x69b4d4` | absent | absent | 1 | undefined (`is_code:false`, `is_data:false`) | absent / absent | `00` |
| Protected target `0x69b4d4-0x69b4d5` | absent | `SoundStatusPane *` | 1 | undefined (`is_code:false`, `is_data:false`) | absent / absent | `00` |
| Protected target `0x69b4d5-0x69b4d6` | absent | absent | 1 | undefined (`is_code:false`, `is_data:false`) | absent / absent | `00` |
| Protected target `0x69b4d6-0x69b4d7` | absent | absent | 1 | undefined (`is_code:false`, `is_data:false`) | absent / absent | `00` |
| Protected target `0x69b4d7-0x69b4d8` | absent | absent | 1 | undefined (`is_code:false`, `is_data:false`) | absent / absent | `00` |
| Protected `0x69b4d8-0x69b4d9` | absent | `TimerPane *` | 1 | undefined (`is_code:false`, `is_data:false`) | absent / absent | `00` |

The exact six-byte protected window `0x69b4d3-0x69b4d9` is `00 00 00 00 00 00`, SHA256 `B0F66ADC83641586656866813FD9DD0B8EBB63796075661BA45D1AA8089E1D44`. The complete incoming xref set for `0x69b4d4` is exactly six data xrefs: `0x5048e6` in `[0x5047f0,0x504b6b)`, `0x57bfc0` and `0x57bfc7` in constructor `[0x57bf70,0x57c04d)`, `0x57c06a` in destructor `[0x57c050,0x57c079)`, `0x57c240` in unwind helper `[0x57c240,0x57c24b)`, and `0x57c290` in scalar destructor `[0x57c270,0x57c2cf)`; no next page exists. Protected predecessor `0x69b4d3` has exactly zero incoming xrefs. Protected successor `0x69b4d8` has exactly eight data xrefs at `0x504ac2`, `0x50884c`, `0x5140e1`, `0x598731`, `0x598738`, `0x59886a`, `0x598c30`, and `0x598c80`; no next page exists.

Desired-name collision readback is exact and non-mutating: `lookup_funcs("g_pSoundStatusPane")` returned `Not a function`; exact-name `entity_query(kind:"names")` and `list_globals` each returned one existing binding, `g_pSoundStatusPane -> 0x69b4d4`, and no off-target occupant. `inspect_items` still returned an empty physical item-name field for every head in the table. The existing address/global-name binding and the six physical item prestates are both protected facts; neither authorizes a rename or aggregation.

`NO_CHANGE` is the complete C031 disposition. The supervisor performs read-only verification only and must call no `make_data`, `undefine`, `rename`, `set_type`, `set_address_comments`, `set_address_repeatable_comments`, or other mutation endpoint for this row. Expected readback is byte-for-byte and field-for-field identical to the prestate: six separate one-byte undefined heads, exact first-head `SoundStatusPane *` type, all physical item names and address comments empty, adjacent types unchanged, six zero bytes/hash unchanged, the sole target-bound global name unchanged, and complete incoming xrefs still exactly `6/0/8`. Any delta is a stop condition attributable outside C031, never a repair opportunity within this report.

Global no-change protections:

- Preserve constructor/destructor/unwind/scalar names, prototypes, existing comments, function bounds, frames/locals, xrefs, and bytes.
- Preserve the two raw adjustor prototypes and boundaries; no unsafe synthetic source type is recommended.
- Preserve all vtable/RTTI/literal addresses and identities.
- Do not create a SoundStatusPane UDT solely to type these functions in this pass.

## First-Draft C++ Recommendation

These are exact formal-channel contents for the later accepted callback, not illustrative snippets.

UID0000SB `RECONSTRUCTION_CPP CODE`:

```cpp
#include "SoundStatusPane.h"

SoundStatusPane *g_pSoundStatusPane = NULL;

template <>
Singleton<SoundStatusPane>::Singleton()
{
    g_pSoundStatusPane = static_cast<SoundStatusPane *>(this);
}

template <>
Singleton<SoundStatusPane>::~Singleton()
{
    g_pSoundStatusPane = NULL;
}
```

UID0000SB `RECONSTRUCTION_H CODE`:

```cpp
class SoundStatusPane;

extern SoundStatusPane *g_pSoundStatusPane;
```

UID0000DJ `RECONSTRUCTION_CPP CODE`:

```cpp
#include "../../app/Application.h"
#include "../../audio/MidiPlayer.h"
#include "../../audio/SoundManager.h"
#include "../../config/Config.h"
#include "../../render/Surface.h"
#include "../core/Event.h"
#include "SoundStatusPane.h"

#include <cwchar>

[[CHILDREN]]
```

UID0000DJ `RECONSTRUCTION_H CODE`:

```cpp
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
```

UID0001IG `RECONSTRUCTION_CPP CODE`:

```cpp
SoundStatusPane::SoundStatusPane()
    : Pane(1), Singleton<SoundStatusPane>()
{
    m_statusLeft = g_screenWidth - 354;
    m_statusRight = m_statusLeft + 114;
    m_statusTop = g_screenHeight - 11;
    m_statusBottom = m_statusTop + 12;

    RectBounds statusBounds;
    InitRectBounds(&statusBounds,
                   m_statusLeft,
                   m_statusTop,
                   m_statusRight,
                   m_statusBottom);
}

SoundStatusPane::~SoundStatusPane()
{
}

bool SoundStatusPane::HandleKeyOrTextEvent(Event *event)
{
    unsigned char modifiers = event->m_payload.m_key.m_modifiers;
    unsigned char key = g_pEventMan->TranslateEventKey(
        event->m_payload.m_key.m_key,
        modifiers);

    if (event->m_type != kEventKeyDown) {
        return false;
    }

    if (key == 'm' && modifiers == kEventModifierControl) {
        if (g_pSoundManager->IsSoundEffectsEnabled()) {
            g_pSoundManager->DisableSoundEffects();
            g_pConfig->m_soundEffectsEnabled = 0;
        } else {
            g_pSoundManager->EnableSoundEffects();
            g_pConfig->m_soundEffectsEnabled = 1;
        }
    } else if (key == 'M' &&
               (modifiers & kEventModifierControl) != 0) {
        if (g_pMidiPlayer->IsPlaybackEnabled()) {
            g_pMidiPlayer->DisableMidiPlayback();
            g_pSoundManager->MuteMusic();
        } else {
            g_pMidiPlayer->EnableMidiPlayback();
            g_pSoundManager->UnmuteMusic();
        }
    } else {
        return false;
    }

    InvalidateRect(&m_visibleBounds);
    return true;
}

void SoundStatusPane::OnPaint()
{
    SetDrawMode(0);
    SetDrawColor(0);
    g_pfnFillRect(this, &m_visibleBounds);

    SetTextDrawMode(0);
    SetTextColor(0x8f);
    SetTextBackFillColor(0);
    MoveTo(0, 11);

    const wchar_t *musicStatus =
        g_pSoundManager->IsPlaybackEnabled() ? L"Music On" : L"Music Off";
    const wchar_t *soundStatus =
        g_pSoundManager->IsSoundEffectsEnabled() ? L"Sound On" : L"Sound Off";

    wchar_t statusText[128];
    swprintf_s(statusText, 128, L"%s/%s", soundStatus, musicStatus);
    DrawWideText(statusText, static_cast<int>(wcslen(statusText)));
}
```

UID0001IG `RECONSTRUCTION_H CODE`: blank. All declarations are in UID0000DJ.

UID0004UF position-zero `RECONSTRUCTION_H CODE` opens the standalone SoundManager header, supplies every direct prerequisite and the local Miles compatibility boundary, and declares the semantic global:

```cpp
#ifndef NEXUSTK_AUDIO_SOUNDMANAGER_H
#define NEXUSTK_AUDIO_SOUNDMANAGER_H

#include <windows.h>
#include <dsound.h>
#include <string.h>
#include <vector>

#include "../util/Singleton.h"
#include "../util/StringBase.h"
#include "../util/TimerHandler.h"

typedef signed long S32;
typedef unsigned long U32;

typedef void *HSAMPLE;
typedef void *HDIGDRIVER;
typedef void *HSTREAM;
typedef void *HREDBOOK;

#ifndef AILCALL
#define AILCALL __stdcall
#endif

#ifndef AILCALLBACK
#define AILCALLBACK __stdcall
#endif

typedef U32 (AILCALLBACK *AILFileOpenCallbackProc)(const char *, U32 *);
typedef void (AILCALLBACK *AILFileCloseCallbackProc)(U32);
typedef S32 (AILCALLBACK *AILFileSeekCallbackProc)(U32, S32, U32);
typedef U32 (AILCALLBACK *AILFileReadCallbackProc)(U32, void *, U32);
typedef void (AILCALLBACK *AILStreamCallbackProc)(HSTREAM);

extern "C"
{
U32 AILCALL AIL_sample_status(HSAMPLE sample);
void AILCALL AIL_set_sample_volume(HSAMPLE sample, S32 volume);
void AILCALL AIL_start_sample(HSAMPLE sample);
S32 AILCALL AIL_set_sample_file(HSAMPLE sample, const void *fileImage,
                                S32 block);
void AILCALL AIL_set_DirectSound_HWND(HDIGDRIVER driver, HWND window);
void AILCALL AIL_release_sample_handle(HSAMPLE sample);
HSAMPLE AILCALL AIL_allocate_sample_handle(HDIGDRIVER driver);
void AILCALL AIL_set_redist_directory(const char *directory);
void AILCALL AIL_close_digital_driver(HDIGDRIVER driver);
HDIGDRIVER AILCALL AIL_open_digital_driver(U32 frequency, S32 bits,
                                            S32 channels, U32 flags);
void AILCALL AIL_release_all_timers();
const char *AILCALL AIL_last_error();
S32 AILCALL AIL_set_preference(U32 preference, S32 value);
void AILCALL AIL_shutdown();
S32 AILCALL AIL_get_DirectSound_info(
    HDIGDRIVER driver,
    LPDIRECTSOUND *directSound,
    LPDIRECTSOUNDBUFFER *primaryBuffer);
void AILCALL AIL_redbook_close(HREDBOOK redbook);
U32 AILCALL AIL_redbook_tracks(HREDBOOK redbook);
void AILCALL AIL_init_sample(HSAMPLE sample);
void AILCALL AIL_redbook_track_info(HREDBOOK redbook, U32 track,
                                     U32 *start, U32 *end);
U32 AILCALL AIL_redbook_position(HREDBOOK redbook);
U32 AILCALL AIL_redbook_play(HREDBOOK redbook, U32 start, U32 end);
void AILCALL AIL_redbook_stop(HREDBOOK redbook);
void AILCALL AIL_redbook_pause(HREDBOOK redbook);
void AILCALL AIL_redbook_resume(HREDBOOK redbook);
void AILCALL AIL_set_file_callbacks(
    AILFileOpenCallbackProc openCallback,
    AILFileCloseCallbackProc closeCallback,
    AILFileSeekCallbackProc seekCallback,
    AILFileReadCallbackProc readCallback);
AILStreamCallbackProc AILCALL AIL_register_stream_callback(
    HSTREAM stream, AILStreamCallbackProc callback);
U32 AILCALL AIL_stream_status(HSTREAM stream);
void AILCALL AIL_set_stream_loop_count(HSTREAM stream, S32 loopCount);
void AILCALL AIL_set_stream_volume(HSTREAM stream, S32 volume);
void AILCALL AIL_startup();
void AILCALL AIL_set_digital_master_volume(HDIGDRIVER driver, S32 volume);
void AILCALL AIL_pause_stream(HSTREAM stream, S32 paused);
void AILCALL AIL_start_stream(HSTREAM stream);
void AILCALL AIL_close_stream(HSTREAM stream);
HSTREAM AILCALL AIL_open_stream(HDIGDRIVER driver, const char *filename,
                                S32 streamMemory);
HREDBOOK AILCALL AIL_redbook_open_drive(S32 drive);
S32 AILCALL AIL_redbook_set_volume(HREDBOOK redbook, S32 volume);
}

class SoundManager;

extern SoundManager *g_pSoundManager;
```

UID0000DG `RECONSTRUCTION_H CODE` follows UID0004UF at position ten, uses the complete included definitions, and closes the same guard:

```cpp
typedef mystr::StringBase<char, mystr::mychar_traits<char> > SoundPathString;

class SimpleUString;
class Application;
class BaramApp;

struct SoundSampleSlot
{
    HSAMPLE handle;
    int playVolumeScale;
};

class SoundManager : public Singleton<SoundManager>, public TimerHandler
{
public:
    SoundManager();
    virtual ~SoundManager();
    virtual bool OnTimer(int timerId, int arg0, int arg1);

    void LoadTrackListFromFile(const SimpleUString &playlistName);
    void StopStreamAndResetZone(int fadeOutMilliseconds);
    HDIGDRIVER GetDigitalDriver() const;
    void PlayTrackByIndex(int trackIndex, int volumeScale, int loopCount);
    void PlayMusicByZone(int zoneId, int fallbackTrackIndex,
                         int volumeScale, int loopCount);
    void StopStream(int fadeOutMilliseconds);
    int GetStreamVolume() const;
    void SetStreamVolume(unsigned int volume);
    bool IsPlaybackEnabled() const;
    void MuteMusic();
    void UnmuteMusic();
    void SetStreamPaused(bool paused);
    void PlayNextTrack();
    void PlayNextPlaylistTrack();
    void PlaySample(unsigned int sampleId, int playVolumeScale);
    void PlayEffect(unsigned int sampleId, int playVolumeScale)
    {
        PlaySample(sampleId, playVolumeScale);
    }
    int GetSampleVolume() const;
    void SetSampleVolume(unsigned int volume);
    bool IsSoundEffectsEnabled() const;
    void EnableSoundEffects();
    void DisableSoundEffects();
    void SuspendSoundEffectsForApplicationDeactivate();
    void RestoreSoundEffectsAfterAppFocus();
    LPDIRECTSOUND GetDirectSound();
    void ScanMusicDirectory(
        const mystr::StringBase<wchar_t,
                                mystr::mychar_traits<wchar_t> > &directoryPath,
        bool randomize,
        bool recursive);
    void OpenRedbookDrive(unsigned short driveLetter);
    void CloseRedbookDevice();
    void PlayRedbookTrack(unsigned int trackNumber);
    bool AdvanceRedbookTrack();
    bool RewindRedbookTrack();
    void SetRedbookPaused(bool paused);
    void RestartMusic(int fadeOutMilliseconds);
    void ReinitializeAudioDriver();

private:
    friend class Application;
    friend class BaramApp;

    void SetDigitalAudioMuted(bool muted);
    void StopRedbookAndCancelTrackTimer();
    void ReinitializeAudioDriverAndResumeMusic();
    void ShutdownAudioDriver();
    static void AILCALLBACK AILStreamEndCallback(HSTREAM stream);

    bool m_musicOptionEnabled;
    bool m_soundEffectsOptionEnabled;
    HDIGDRIVER m_digitalDriver;
    bool m_musicPlaybackEnabled;
    int m_streamVolume;
    HSTREAM m_stream;
    HREDBOOK m_redbookHandle;
    int m_redbookTrackCount;
    int m_redbookOrderIndex;
    int m_currentRedbookTrack;
    int m_currentTrackVolumeScale;
    int m_currentTrackIndex;
    int m_currentLoopCount;
    int m_pendingTrackIndex;
    int m_pendingTrackVolumeScale;
    int m_pendingLoopCount;
    bool m_musicAdvanceRequested;
    bool m_soundEffectsEnabled;
    int m_soundEffectVolume;
    SoundSampleSlot m_sampleSlots[8];
    void *m_samplePayloads[1000];
    std::vector<SoundPathString> m_localMusicPaths;
    unsigned char m_redbookOrder[100];
    int m_currentMusicZoneId;
    std::vector<SoundPathString> m_zoneMusicTracks;
    bool m_randomizeZonePlaylist;
    bool m_zonePlaylistActive;
};

#endif
```

The 37 declarations are deliberately local compatibility declarations, not copied Miles source. Their names and stack arities are exact import facts; consumed return categories and pointer/handle widths are corroborated by dated report-time call-site and IDA-type evidence. `signed long`/`unsigned long`, opaque pointer handles, and `__stdcall` are era-compatible x86 source forms. The header does not claim unavailable proprietary structure layouts. Return spellings that are not consumed remain the best-supported contemporary API form and are the bounded reason dependency confidence is `strong`, not `original-proof`.

UID00008A `RECONSTRUCTION_CPP CODE` required before the existing MidiPlayer children:

```cpp
#include "MidiPlayer.h"
```

UID00008A `RECONSTRUCTION_H CODE` required by this unit and the existing MidiPlayer source:

```cpp
#ifndef NEXUSTK_AUDIO_MIDIPLAYER_H
#define NEXUSTK_AUDIO_MIDIPLAYER_H

#include "../util/LObject.h"

class MidiPlayer : public LObject
{
public:
    MidiPlayer();
    virtual ~MidiPlayer();

    void IncreaseMidiVolume();
    void DecreaseMidiVolume();
    int IsPlaybackEnabled() const;
    void EnableMidiPlayback();
    void DisableMidiPlayback();
    void SelectTrack(unsigned short trackId);
    void StopPlayback();

private:
    int m_playbackEnabled;
    int m_selectedTrackId;
};

typedef char MidiPlayerSizeMustBe12[
    sizeof(MidiPlayer) == 0x0c ? 1 : -1];

#endif
```

UID0000RM `RECONSTRUCTION_H CODE` for the semantic MidiPlayer global:

```cpp
class MidiPlayer;

extern MidiPlayer *g_pMidiPlayer;
```

No third-party source import applies.

## Final Recommendation

Accept the existing whole-file owner and emitters, fill both empty markers, and preserve compiler-only members as covered. The exact source in Section 22 is behaviorally complete for every discovered SoundStatusPane source item, supplies the missing MidiPlayer producer/header route, and makes SoundManager.h standalone through an exact guard/include/global split plus bounded local Miles declarations. Correct both stale `g_pSoundStatusPane` pages to the current semantic-binding/four-target-head model. No split, new UID, new source file, raw compiler-data definition, duplicate global, unavailable SDK include, or third-party source import is justified.

After callback implementation and scoped validation, expected SoundStatusPane.cpp content is one global definition, two explicit Singleton specializations, and four ordinary method definitions, with zero empty markers. Expected SoundStatusPane.h content is one forward/extern global declaration and one complete class declaration. Expected MidiPlayer.cpp begins with exactly one `#include "MidiPlayer.h"` before its existing global/child source, and MidiPlayer.h contains one complete 0x0c class declaration and singleton extern. Expected SoundManager.h has one guard, seven direct includes, one local Miles block containing two integer aliases/four handles/two calling-convention macros/five callback types/all 37 imported API declarations, one `g_pSoundManager` extern, one complete class declaration, and one closing `#endif`.

## Recommended Target Doc Changes

Update `by-file/SoundStatusPane.md` at full report detail:

- Replace stale generated claims with a callback-time physical snapshot tied to the validator command/timestamp actually returned for that callback and the exact expected CPP/H inventory. Command 27302 is historical, and this report's command-27320 baseline is explicitly dated rather than timeless authority.
- Add the complete code/data/type/resource inventory and source/compiler dispositions.
- Add exact function ranges, padding, callers, callees, global xrefs, vtable/RTTI/caption ownership, field layout, dependencies, and source order.
- State why both empty emitters are valid and how each formal channel is completed.
- Record the MidiPlayer and standalone SoundManager header dependencies, exact local Miles/platform route, and generated-header audit.
- Raise metadata to 94/95 and update score rationale/open questions/changes.

Update UID0000DJ, UID0001IG, and UID0000SB with Sections 8, 13-22 at same-or-greater detail and exact formal channels. Update UID0002WA prose exactly under C022/C035 while preserving its metadata, ignored/non-reconstructable/non-emitting disposition, range, and blank formal channels.

## Recommended Support Doc Changes

- UID00026I: add exact three-table/31-cell vtable map, exact RTTI graph, caption addresses, and source/non-emission disposition.
- UID0000SB: in addition to formal source and metadata work, replace stale physical-item wording with the exact semantic binding versus empty physical fields and six-head/four-target-head model from C034.
- UID0002WA: replace stale single-four-byte-item wording with C035's exact one-byte-head table and NO_CHANGE boundary; preserve metadata and blank formal channels.
- UID0004UF: replace its blank H channel with Section 22's exact guard/direct-includes/local-Miles/global-declaration preamble; preserve its sole CPP definition and raise completion to 93.
- UID0000DG: replace its current dependency-incomplete H block with Section 22's exact complete class tail and guard closure; remove redundant StringBase forward substitutes, use era-compatible integer spellings, add the dependency evidence, and raise completion to 93.
- UID0000NV: document the complete standalone-header route, all 37 imports, local declaration ownership, rejected unavailable SDK/new-file/PCH routes, and unchanged whole-file score.
- UID0004WV: preserve the existing CPP include and four file-static callback declarations byte-for-byte; add only the fact that their U32/S32/AILCALLBACK providers now come from the local SoundManager.h compatibility preamble.
- UID00008A, UID0000LD, and UID0000RM MidiPlayer: replace class CPP commentary with the header include, add the complete class H channel and semantic-global extern H channel, generated-header requirement, SoundStatusPane consumer relationship, and metadata/coverage updates.
- UID0002QH MapPane teardown: add the exact `g_pSoundStatusPane` read and deferred BlackHole deletion relationship if not already literal at same detail.
- `by-item/InitializeMainUiGraph_004F7D10.md`: preserve/confirm both allocation/call pairs and exact 0x108 size.
- `by-meta/client_audio.md`: state that SoundStatusPane is a UI consumer coordinating SoundManager and MidiPlayer, not an audio-state owner.
- `by-project-structure/proposed-source-tree.md`: retain `ui/panels/SoundStatusPane.cpp/.h` and remove stale wording that treats current empty generated output as complete.
- Pane, GrafPort, Event, EventHandler, RectBounds, SingletonTemplate, SurfaceRenderCallbackTable, Application, and Config already contain same-or-greater dependency facts; verify rather than rewrite them.

## Score And Metadata Recommendation

| UID | Pre-callback | Recommended | Current post-callback | Owner/emitter/reconstructable disposition |
| --- | --- | --- | --- | --- |
| 0000NX | 89/91 | 94/95 | 94/95 | Keep FILE owner/path and three existing emitters; reconstructable. |
| 0000DJ | 90/92 | 94/95 | 94/95 | Keep owner/emitter UID0000NX; reconstructable; fill CPP/H. |
| 0001IG | 89/92 | 94/95 | 94/95 | Keep owner UID0000DJ/emitter UID0000NX; reconstructable; emit ordinary methods only. |
| 0000SB | 92/94 | 94/95 | 94/95 | Keep owner/emitter UID0000NX at position zero; reconstructable. |
| 0002WA | 92/94 | no change | 92/94 | Keep physical evidence ignored/non-emitting; correct stale one-item prose only. |
| 00026I | 88/91 | no change | 88/91 | Keep mixed read-only index non-reconstructable/non-emitting. |
| 0004UF | 92/94 | 93/94 | 93/94 | Keep sole SoundManager global definition; add exact standalone-header preamble, local compatibility declarations, and matching extern. |
| 0000DG | 92/94 | 93/94 | 93/94 | Keep complete SoundManager class ownership; close all direct H prerequisites while unrelated source-body gaps remain outside this class declaration. |
| 0000NV | 92/93 | no change | 92/93 | Document the closed H dependency route, but retain the file score because unrelated SoundManager body gaps remain. |
| 0004WV | 93/94 | no change | 93/94 | Preserve exact callback declarations; document their now-explicit local type provider. |
| 00008A | 87/90 | 89/92 | 89/92 | Keep owner/emitter UID0000LD; add complete H declaration. |
| 0000LD | 88/89 | 89/91 | 89/91 | Keep audio source path/emitters; document and generate required H. |
| 0000RM | 87/90 | 89/92 | 89/92 | Keep semantic global owner UID0000LD and physical-child CPP definition; add matching H extern. |

No score is raised merely for association. Each increase reflects closed source-shape blockers, exact formal output, and literal whole-file evidence. Residual confidence limits are original field-name spelling and exact historical include style, not behavior or layout.

## Open Questions With Attempted Resolution

- Original names of the four derived integers: unresolved lexically, resolved structurally. Use descriptive `m_statusLeft`, `m_statusRight`, `m_statusTop`, `m_statusBottom`; no binary behavior depends on exact spelling.
- Why the constructor builds an unused stack RectBounds: exact call is proven, but original intent is unavailable. Preserve it without claiming hidden state transfer.
- Whether lowercase and uppercase hotkeys were documented to users: no resource evidence found. Preserve binary key/modifier logic only.
- Whether the original project used precompiled headers instead of explicit includes: not recoverable. Use current project-relative explicit includes required by generated reconstruction.
- Whether the old compiler emitted Singleton specializations in another include: no separate source owner or symbol evidence exists. Current SingletonTemplate policy and class-specific lowering place them in the consuming module.
- Whether an original Miles SDK header can be restored verbatim: repository, third-party, generated, documentation, and active source searches found none. Resolution is not deferred: use Section 22's local declarations, whose names/arity/handle widths/callback forms are bounded by the executable. An unavailable `<mss.h>`, a new ownerless shim, and implicit/PCH declarations are rejected.
- Exact proprietary return typedef spelling for API results ignored by every current call site: not lexically recoverable. Section 22 uses the contemporary call-compatible form, keeps all consumed status/handle/pointer results exact, and records this as the confidence cap without leaving any undeclared identifier.

None of these questions blocks complete source emission, layout, ownership, or behavior.

## Exact Manual Supervisor-Owned Coverage Or Tracker Text

Only the supervisor, after B009 ordinary/scoped-validator/generated-readback work and independent verification, replaces the following twelve current manual rows. B009 must not edit, validate, or claim application of any row in this section:

`by-file/-coverage-report.md` UID0000NX:

`- [UID:0000NX][SoundStatusPane](by-file/SoundStatusPane.md) : reconstructable : 94% : very-strong : Complete HUD sound/music status source unit with exact 0x108 Pane plus Singleton layout, four ordinary methods, four covered compiler functions, singleton specializations/global linkage, both main-UI construction branches, MapPane deferred teardown consumer, complete CPP/H emission, vtable/RTTI/literal ownership, and zero valid empty emitters.`

`by-class/-coverage-report.md` UID0000DJ:

`- [UID:0000DJ][SoundStatusPane](by-class/SoundStatusPane.md) : reconstructable : 94% : very-strong : Complete SoundStatusPane declaration with direct Pane plus Singleton<SoundStatusPane> inheritance, 0x108 EBO-compatible layout, four integer geometry fields, exact OnPaint and HandleKeyOrTextEvent overrides, singleton lifecycle, and complete CPP child/header routing.`

`by-memory/-coverage-report.md` UID0001IG:

`    - [UID:0001IG][0x0057bf70-0x0057c2cf.SoundStatusPane](by-memory/0x0057bf70-0x0057c2cf.SoundStatusPane.md) 0x0057bf70-0x0057c2cf | class method island | SoundStatusPane : reconstructable : 94% : very-strong : Complete constructor, ordinary destructor, hotkey handler, and paint method source with exact ranges and padding; constructor-unwind clear, two adjustor thunks, and scalar deleting destructor are individually proven compiler-covered and intentionally non-emitting.`

`by-global/-coverage-report.md` UID0000SB:

`- [UID:0000SB][g_pSoundStatusPane](by-global/g_pSoundStatusPane.md) : reconstructable : 94% : very-strong : Sole external-linkage SoundStatusPane singleton definition and declaration with exact class-specific Singleton constructor/destructor specializations, six lifecycle/consumer xrefs, semantic g_pSoundStatusPane binding at 0x69B4D4 distinct from empty physical item-name fields, exact six-one-byte-head neighborhood/four-target-head physical child UID0002WA, and one-definition position-zero emission in SoundStatusPane.cpp.`

`by-memory/-coverage-report.md` UID0002WA:

`    - [UID:0002WA][0x0069b4d4-0x0069b4d8.g_pSoundStatusPane](by-memory/0x0069b4d4-0x0069b4d8.g_pSoundStatusPane.md) 0x0069b4d4-0x0069b4d8 | physical singleton storage | g_pSoundStatusPane : ignored : 92% : very-strong : Non-emitting four-byte semantic storage range currently represented by four separate one-byte undefined target heads inside the six-head 0x69B4D3-0x69B4D9 neighborhood; only 0x69B4D4 carries SoundStatusPane * type, all physical item names/comments are empty, all bytes are zero, semantic name binding is separate, and exact NO_CHANGE protection forbids aggregation or mutation.`

`by-class/-coverage-report.md` UID00008A:

`- [UID:00008A][MidiPlayer](by-class/MidiPlayer.md) : reconstructable : 89% : strong : WinMM MIDI playback controller with a MidiPlayer.cpp header include, complete 0x0c class/header declaration, public playback/toggle surface required by SoundStatusPane, existing child-owned method bodies and private helpers, and singleton extern; unresolved private helper spellings remain bounded outside the public header.`

`by-global/-coverage-report.md` UID0004UF:

`- [UID:0004UF][g_pSoundManager](by-global/g_pSoundManager.md) : reconstructable : 93% : very-strong : Sole externally linked SoundManager pointer definition in SoundManager.cpp plus position-zero SoundManager.h owner for the exact include guard, seven direct platform/CRT/STL/project includes, bounded local 37-import Miles compatibility declarations, matching forward/extern declaration, exact backing storage UID00028R, 117 live refs, direct Singleton<SoundManager> lifecycle, and one-definition cross-module topology.`

`by-global/-coverage-report.md` UID0000RM:

`- [UID:0000RM][g_pMidiPlayer](by-global/g_pMidiPlayer.md) : reconstructable : 89% : strong : Semantic MidiPlayer singleton owner with matching MidiPlayer.h forward/extern declaration, exact physical-child definition UID00029A, 18 direct xrefs, constructor/destructor/compiler-cleanup lifecycle, and SoundStatusPane plus application/audio consumers under a one-definition route.`

`by-file/-coverage-report.md` UID0000LD:

`- [UID:0000LD][MidiPlayer](by-file/MidiPlayer.md) : reconstructable : 89% : strong : WinMM MIDI source module projected to NexusTK/audio/ with MidiPlayer.cpp including its complete required MidiPlayer.h class declaration and singleton extern before existing child-owned bodies, providing a legal consumer interface for SoundStatusPane while private parser/helper ownership remains unchanged.`

`by-class/-coverage-report.md` UID0000DG:

`- [UID:0000DG][SoundManager](by-class/SoundManager.md) : reconstructable : 93% : very-strong : Complete 0x10AC SoundManager declaration with Singleton<SoundManager> and TimerHandler bases, exact fields/public-private surface, complete StringBase/vector members, DirectSound interface use, era-compatible integer spellings, and deterministic SoundManager.h guard/include/local-Miles dependency closure shared with semantic global UID0004UF.`

`by-file/-coverage-report.md` UID0000NV:

`- [UID:0000NV][SoundManager](by-file/SoundManager.md) : reconstructable : 92% : very-strong : NexusTK/audio SoundManager source root with exact class/global/lifecycle/playback/callback ownership and a standalone SoundManager.h route using repository Singleton/StringBase/TimerHandler headers, platform windows.h/dsound.h, CRT string.h, STL vector prerequisites, and a bounded local declaration block for all 37 observed mss32 imports; no unavailable Miles SDK or ownerless shim is assumed, while unrelated source-body gaps retain the existing score.`

`by-item/-coverage-report.md` UID0004WV:

`- [UID:0004WV][SoundManagerMilesCallbackDeclarations](by-item/SoundManagerMilesCallbackDeclarations.md) : reconstructable : 93% : very-strong : Exact SoundManager.cpp preamble with SoundManager.h include and four file-static AIL open/close/seek/read callback declarations in source-before-use order; U32, S32, AILCALLBACK, and handle providers now resolve through SoundManager.h's bounded local Miles compatibility block without changing callback bodies, linkage, or emitter route.`

No manual row change is recommended for UID00026I, UID0002QH, or other already-complete dependency pages. The generated tracker is validator-owned; do not hand-edit it. Its expected refreshed state is three SoundStatusPane emitters filled, zero empty, and 100.0% generated completion; generated SoundManager.h must also satisfy Section 23's exact standalone inventory.

## Follow-Up Actions

1. Fresh supervisor Gate 1 on this exact callback artifact.
2. Supervisor Gate 2A claim-by-claim verification of the 33 checked ordinary/scoped-validator/generated-readback rows.
3. Supervisor Gate 2B completion of exactly two actions plus one no-change verification for unchecked C029-C031.
4. Supervisor-only application of all twelve Section 28 rows under unchecked C033.
5. Supervisor-owned report lifecycle only after every ordinary, IDA, manual-coverage, and generated-readback row is checked and verified.

Do not start a different target until this report's supervisor-owned lifecycle and archived-artifact audit are complete.

## Confidence

Overall confidence is very strong for ownership, range, inheritance, object size, source/compiler partition, method behavior, global lifecycle, semantic-versus-physical global state, vtable/RTTI mapping, source placement, direct header prerequisites, import names/arities, and formal output topology. Confidence is strong for descriptive field names, explicit include spelling, and unconsumed proprietary Miles return spellings. There are no unresolved behavioral or source-legality blockers.

Completeness proof: every discovered function, padding span, semantic/physical global, vtable, RTTI record, literal, field, caller/callee, dependency, generated defect, and affected destination has an emit/covered/preserve/update disposition.

## Validator Results

The accepted callback ran exactly one scoped file validator for each changed ordinary page using the documented inline command form `python .\tools\validator.py --mode file --file <relative-by-star-path> --apply --queue-timeout 240`. Every receipt exited `0`, reported `ok:1`, and returned `generated_refresh: deferred`; no broad validator, coverage validator, report lifecycle, or execution command ran.

| Command | Timestamp | Scoped ordinary page | Result |
| --- | --- | --- | --- |
| `000000027388` | `2026-08-24T02:28:01-04:00` | `by-class/SoundStatusPane.md` | exit 0; ok 1; generated deferred |
| `000000027389` | `2026-08-24T02:28:57-04:00` | `by-memory/0x0057bf70-0x0057c2cf.SoundStatusPane.md` | exit 0; ok 1; generated deferred |
| `000000027390` | `2026-08-24T02:29:48-04:00` | `by-global/g_pSoundStatusPane.md` | exit 0; ok 1; generated deferred |
| `000000027391` | `2026-08-24T02:30:40-04:00` | `by-memory/0x0069b4d4-0x0069b4d8.g_pSoundStatusPane.md` | exit 0; ok 1; generated deferred |
| `000000027392` | `2026-08-24T02:31:27-04:00` | `by-memory/0x0062ce50-0x0062cfd8.NetworkAndAudioReadOnlyData.md` | exit 0; ok 1; generated deferred |
| `000000027393` | `2026-08-24T02:32:05-04:00` | `by-item/InitializeMainUiGraph_004F7D10.md` | exit 0; ok 1; generated deferred |
| `000000027394` | `2026-08-24T02:32:36-04:00` | `by-memory/0x005047f0-0x00504b6b.MapPaneExitToMenuTeardown.md` | exit 0; ok 1; generated deferred |
| `000000027395` | `2026-08-24T02:33:57-04:00` | `by-class/MidiPlayer.md` | exit 0; ok 1; generated deferred |
| `000000027396` | `2026-08-24T02:34:29-04:00` | `by-global/g_pMidiPlayer.md` | exit 0; ok 1; generated deferred |
| `000000027397` | `2026-08-24T02:35:10-04:00` | `by-file/MidiPlayer.md` | exit 0; ok 1; generated deferred |
| `000000027398` | `2026-08-24T02:36:14-04:00` | `by-global/g_pSoundManager.md` | exit 0; ok 1; generated deferred |
| `000000027399` | `2026-08-24T02:37:25-04:00` | `by-class/SoundManager.md` | exit 0; ok 1; generated deferred |
| `000000027400` | `2026-08-24T02:38:11-04:00` | `by-file/SoundManager.md` | exit 0; ok 1; generated deferred |
| `000000027401` | `2026-08-24T02:38:52-04:00` | `by-item/SoundManagerMilesCallbackDeclarations.md` | exit 0; ok 1; generated deferred |
| `000000027402` | `2026-08-24T02:39:24-04:00` | `by-meta/client_audio.md` | exit 0; ok 1; generated deferred |
| `000000027403` | `2026-08-24T02:40:14-04:00` | `by-project-structure/proposed-source-tree.md` | exit 0; ok 1; generated deferred |
| `000000027405` | `2026-08-24T02:42:48-04:00` | `by-file/SoundStatusPane.md` | exit 0; ok 1; generated deferred |

Read-only queue observations `000000027404`, `000000027406`, and `000000027407` were not validation or lifecycle runs. The final observation at `2026-08-24T02:43:05-04:00` reported zero queued/processing ordinary jobs and zero queued/processing generated-refresh jobs after command 27405 completed.

### Generated Physical Readback

| Artifact | Embedded generated authority | Physical readback |
| --- | --- | --- |
| `auto-generated/NexusTK/ui/panels/SoundStatusPane.cpp` | command `000000027405`; refresh `2026-08-24T02:42:48-04:00` | 3,297 bytes; 111 lines; mtime `2026-08-24T06:42:58.1551737Z`; SHA256 `71E16E39167B44F503C59BE831952723C7D0CE4AAEE5AEAD997AE9BA974AF01B` |
| `auto-generated/NexusTK/ui/panels/SoundStatusPane.h` | command `000000027405`; refresh `2026-08-24T02:42:48-04:00` | 1,146 bytes; 41 lines; mtime `2026-08-24T06:42:58.1941836Z`; SHA256 `CECC171AA494016A5010C7C9E13E4851A66BCDEF99FA272B3017BC2CB8684CE8` |
| `auto-generated/NexusTK/audio/MidiPlayer.cpp` | command `000000027397`; refresh `2026-08-24T02:35:10-04:00` | 44,591 bytes; 1,433 lines; mtime `2026-08-24T06:35:20.3928766Z`; SHA256 `A9946BF0F5E4A63914933DC3B6ED55858382F90AD7BC27FA71495CAD6D5ECEF6` |
| `auto-generated/NexusTK/audio/MidiPlayer.h` | command `000000027397`; refresh `2026-08-24T02:35:10-04:00` | 1,084 bytes; 40 lines; mtime `2026-08-24T06:35:20.4345602Z`; SHA256 `D7577BB69850BA4D8E1D97A70E0BCC0F15D69C1B812D74112230B535B99D89C8` |
| `auto-generated/NexusTK/audio/SoundManager.cpp` | command `000000027401`; refresh `2026-08-24T02:38:52-04:00` | 27,742 bytes; 836 lines; mtime `2026-08-24T06:39:01.8613933Z`; SHA256 `A25EA6F1B8FDC1B138D23C1DD2DC5FEB1B700647886E223CFFD39818911720BD` |
| `auto-generated/NexusTK/audio/SoundManager.h` | command `000000027401`; refresh `2026-08-24T02:38:52-04:00` | 7,242 bytes; 200 lines; mtime `2026-08-24T06:39:01.8987583Z`; SHA256 `2AB6F1CC00D7B412EA02738D450F631FB6A02A92E6D7AC448B5E7740EB3FC00D` |

SoundStatusPane proof is exact: CPP has zero empty markers, one pointer definition, two Singleton specializations, and exactly one each of constructor, ordinary destructor, key override, and paint override; H has zero empty markers, one extern, and one complete class. MidiPlayer proof is exact for this claim: CPP has exactly one leading `#include "MidiPlayer.h"`; H has one guard, one `0x0c` class/size assertion, and one singleton extern. One unrelated pre-existing UID0001CE empty marker remains later in MidiPlayer.cpp and was not a UID0000NX claim.

SoundManager.h proof is exact: one main guard, seven direct includes, two integer aliases, four opaque handles, two calling-convention macros, five callback-pointer types, all 37 AIL declarations, one `g_pSoundManager` extern, one complete class, and the final guard close; the other two `#endif` lines close the two local macro guards. It contains no unavailable Miles include or unresolved declaration. SoundManager.cpp retains two observable generated markers: UID0000DG reflects its intentionally blank CPP/nonblank H class emitter, and UID0001I7 is unrelated pre-existing aggregate drift. Neither changes the accepted standalone H inventory or callback declarations, and both are surfaced for supervisor Gate 2A rather than hidden.

## Changed Files

Ordinary callback changed-file set:

- `by-file/SoundStatusPane.md`
- `by-class/SoundStatusPane.md`
- `by-memory/0x0057bf70-0x0057c2cf.SoundStatusPane.md`
- `by-global/g_pSoundStatusPane.md`
- `by-memory/0x0069b4d4-0x0069b4d8.g_pSoundStatusPane.md`
- `by-memory/0x0062ce50-0x0062cfd8.NetworkAndAudioReadOnlyData.md`
- `by-item/InitializeMainUiGraph_004F7D10.md`
- `by-memory/0x005047f0-0x00504b6b.MapPaneExitToMenuTeardown.md`
- `by-class/MidiPlayer.md`
- `by-global/g_pMidiPlayer.md`
- `by-file/MidiPlayer.md`
- `by-global/g_pSoundManager.md`
- `by-class/SoundManager.md`
- `by-file/SoundManager.md`
- `by-item/SoundManagerMilesCallbackDeclarations.md`
- `by-meta/client_audio.md`
- `by-project-structure/proposed-source-tree.md`
- `tools/leaser/Agents/Agent-B009/research/0000NX-SoundStatusPane-empty-emitter-whole-file-source-quality.md`

Generated files changed only as validator-owned side effects and were never leased or hand-edited. No manual coverage, audit, catalog, tracker, registry, goal, IDA database, or lifecycle file was edited. B009 used short ordinary leases and released each immediately after its edit/validator batch. Exact final report SHA256, bytes, LF/CR, heading/twin/allocation/marker/hygiene metrics, and zero-active-lease proof are supplied in the status-tool completion receipt because embedding a report's own final hash is self-referential.

## Implementation Tracking Checklist

This table is an exact claim twin of Section 11 with one added Done column. Accepted-callback allocation: 33 checked B009 rows (C001-C028, C032, and C034-C037) and exactly four unchecked supervisor-owned rows (C029-C031 and C033). C029-C031 remain supervisor-only IDA; C033 remains supervisor-only manual coverage and lifecycle. No actor may claim another actor's row.

| Done | Claim ID | Target UID | Claim | Confidence | Evidence | Destination doc/section | Action | Verification state |
| --- | --- | --- | --- | --- | --- | --- | --- | --- |
| [x] | C0000NX-001 | 0000NX | Replace the sampled/stale file summary with the complete source-unit inventory, exact semantic/physical global model, and closed dependency/header route, and raise metadata from 89/91 to 94/95. | very-strong | Four source methods, four compiler functions, complete code/data inventory, generated audit, dated report-time canonical IDA readback, and source-complete SoundManager/MidiPlayer prerequisites. | by-file/SoundStatusPane.md metadata, Status, Likely Contents, dependency audit, Generated Output Caveats, Score Rationale | incorporate | implemented-awaiting-supervisor-Gate2A |
| [x] | C0000NX-002 | 0000DJ | Record direct bases Pane plus Singleton<SoundStatusPane>, the 0x108 layout, EBO overlap at +0xf8, and four distinct integer fields in left/right/top/bottom storage order. | very-strong | RTTI PMDs 0, +0xa0, +0xa4, +0xf8; constructor writes; Pane size 0xf8. | by-class/SoundStatusPane.md metadata, inheritance, layout, fields | incorporate | implemented-awaiting-supervisor-Gate2A |
| [x] | C0000NX-003 | 0000DJ | Replace class CPP commentary with the exact include preamble and `[[CHILDREN]]` route from Section 22; every included project header has a complete formal producer, including the repaired SoundManager and MidiPlayer headers. | very-strong | Existing emitter order, UID0001IG child ownership, and complete direct dependency audit. | by-class/SoundStatusPane.md RECONSTRUCTION_CPP CODE and dependency rationale | incorporate | implemented-awaiting-supervisor-Gate2A |
| [x] | C0000NX-004 | 0000DJ | Populate the exact complete SoundStatusPane class declaration and 0x108 size assertion from Section 22. | very-strong | Exact base declarations, override slots, field layout, constructor allocation size, and RTTI. | by-class/SoundStatusPane.md RECONSTRUCTION_H CODE | incorporate | implemented-awaiting-supervisor-Gate2A |
| [x] | C0000NX-005 | 0001IG | Replace the aggregate blank-policy text with the exact eight-function source/compiler disposition and raise metadata from 89/92 to 94/95. | very-strong | Exact modeled ranges, five internal padding spans, and source/compiler lowering. | by-memory/0x0057bf70-0x0057c2cf.SoundStatusPane.md metadata, Status, Item Summary, boundary map, Score Rationale | incorporate | implemented-awaiting-supervisor-Gate2A |
| [x] | C0000NX-006 | 0001IG | Emit the constructor with Pane(1), Singleton base construction, four screen-relative integers, and the non-escaping InitRectBounds local call. | original-proof | 0x57bf70-0x57c04d disassembly/decompilation and two 0x108-byte allocation callsites. | UID0001IG RECONSTRUCTION_CPP CODE and constructor evidence | incorporate | implemented-awaiting-supervisor-Gate2A |
| [x] | C0000NX-007 | 0000SB | Make UID0000SB CPP position zero include SoundStatusPane.h, define the sole pointer, and define exact Singleton constructor/destructor specializations. | very-strong | Singleton RTTI PMD +0xf8, publication/clear lowering, MiscWorkThread precedent, six global xrefs. | by-global/g_pSoundStatusPane.md RECONSTRUCTION_CPP CODE, ownership, lifecycle | incorporate | implemented-awaiting-supervisor-Gate2A |
| [x] | C0000NX-008 | 0001IG | Emit an empty ordinary SoundStatusPane destructor and attribute singleton clear/base teardown to implicit base destruction. | very-strong | 0x57c050-0x57c079 clear then Pane teardown; explicit Singleton specialization reproduces it. | UID0001IG RECONSTRUCTION_CPP CODE and destructor evidence | incorporate | implemented-awaiting-supervisor-Gate2A |
| [x] | C0000NX-009 | 0001IG | Emit exact HandleKeyOrTextEvent behavior, including pre-type key translation, lowercase exact-Control sound toggle, uppercase Control-bit music toggle, config write, duplicate MIDI/music calls, and inherited-bounds invalidation. | original-proof | 0x57c080-0x57c15b branches, calls, fields, vtable slot, and return values. | UID0001IG RECONSTRUCTION_CPP CODE and hotkey evidence | incorporate | implemented-awaiting-supervisor-Gate2A |
| [x] | C0000NX-010 | 0001IG | Emit exact OnPaint behavior, draw state, inherited-bounds fill, four caption choices, 128-wide-char buffer, `%s/%s` formatting, and text draw. | original-proof | 0x57c160-0x57c23e calls, callback, literals, and primary vtable slot +0x44. | UID0001IG RECONSTRUCTION_CPP CODE and paint evidence | incorporate | implemented-awaiting-supervisor-Gate2A |
| [x] | C0000NX-011 | 0001IG | Populate UID0001IG CPP with exactly the four ordinary methods from Section 22. | very-strong | Constructor/destructor/override source lowering is complete and compiler artifacts are separately covered. | UID0001IG RECONSTRUCTION_CPP CODE | incorporate | implemented-awaiting-supervisor-Gate2A |
| [x] | C0000NX-012 | 0001IG | Keep UID0001IG H blank because every declaration is owned by UID0000DJ's class header. | very-strong | One class declaration route avoids duplicate declarations and matches child emission topology. | UID0001IG RECONSTRUCTION_H CODE and source placement | already-present | already-present-awaiting-supervisor-Gate2A |
| [x] | C0000NX-013 | 0001IG | Classify 0x57c240-0x57c24b as compiler constructor-unwind singleton cleanup covered by the constructor and Singleton specialization; do not emit it. | original-proof | Constructor EH action calls the helper after adjusting to the Singleton subobject. | UID0001IG compiler-artifact map | incorporate | implemented-awaiting-supervisor-Gate2A |
| [x] | C0000NX-014 | 0001IG | Classify 0x57c24b-0x57c256 as the +0xa0 EventHandler-view scalar-destructor adjustor thunk; do not emit it. | original-proof | Exact subtract 0xa0 tail jump and secondary vtable slot zero. | UID0001IG compiler-artifact map | incorporate | implemented-awaiting-supervisor-Gate2A |
| [x] | C0000NX-015 | 0001IG | Classify 0x57c256-0x57c261 as the +0xa4 TimerHandler-view scalar-destructor adjustor thunk; do not emit it. | original-proof | Exact subtract 0xa4 tail jump and tertiary vtable slot zero. | UID0001IG compiler-artifact map | incorporate | implemented-awaiting-supervisor-Gate2A |
| [x] | C0000NX-016 | 0001IG | Classify 0x57c270-0x57c2cf as compiler scalar deleting destructor covered by the virtual destructor/delete lowering; do not emit it. | original-proof | Flags-based delete path, vtable references, singleton clear, base teardown, operator delete. | UID0001IG compiler-artifact map | incorporate | implemented-awaiting-supervisor-Gate2A |
| [x] | C0000NX-017 | 0001IG | Preserve the exact range and five internal plus two boundary padding spans without split, widening, or source emission. | original-proof | CC bytes at bf6e-bf70, c04d-c050, c079-c080, c15b-c160, c23e-c240, c261-c270, c2cf-c2d0. | UID0001IG range/padding analysis | incorporate | implemented-awaiting-supervisor-Gate2A |
| [x] | C0000NX-018 | 00026I | Add the exact three-vtable, 31-cell slot map and state that tables rebuild from class inheritance/overrides rather than raw source bytes. | original-proof | COLs at 62cef0/62cf3c/62cf6c and callable tables at 62cef4/62cf40/62cf70. | UID00026I SoundStatusPane read-only-data subsection | incorporate | implemented-awaiting-supervisor-Gate2A |
| [x] | C0000NX-019 | 00026I | Add the exact seven-node RTTI graph and preserve it as compiler-generated non-emitting evidence. | original-proof | Shared type descriptor/CHD, three COL offsets, seven BCD records and PMDs. | UID00026I SoundStatusPane RTTI subsection | incorporate | implemented-awaiting-supervisor-Gate2A |
| [x] | C0000NX-020 | 00026I | Preserve five caption literals as source literals consumed by OnPaint, not separately emitted aggregate data. | original-proof | UTF-16 strings at 62cf78, 62cf8c, 62cfa0, 62cfb4, 62cfc8 and direct method xrefs. | UID00026I literal ownership and UID0001IG paint evidence | incorporate | implemented-awaiting-supervisor-Gate2A |
| [x] | C0000NX-021 | 0000SB | Preserve one external-linkage H declaration and semantic ownership while raising metadata from 92/94 to 94/95; bind the semantic name only to address `0x69B4D4`, never to a claimed physical item name. | very-strong | Sole definition route, six xrefs, exact semantic `g_pSoundStatusPane -> 0x69B4D4` binding, physical child, and complete singleton specialization source. | by-global/g_pSoundStatusPane.md metadata, H channel, lifecycle, Score Rationale | incorporate | implemented-awaiting-supervisor-Gate2A |
| [x] | C0000NX-022 | 0002WA | Preserve range `[0x69B4D4,0x69B4D8)` as ignored, non-reconstructable/non-emitting evidence with unchanged metadata and blank formal source, but replace its obsolete single-four-byte-item description with the exact four target one-byte undefined heads inside the six-head neighborhood. | original-proof | Dated report-time item/type/name/comment/byte readback, exact six/zero/eight adjacent xref partition, semantic one-definition route, and C031 NO_CHANGE protection. | by-memory/0x0069b4d4-0x0069b4d8.g_pSoundStatusPane.md Status, Item Summary, Current IDA State, physical model, Score Rationale | incorporate | implemented-awaiting-supervisor-Gate2A |
| [x] | C0000NX-023 | 0000NX | Preserve both InitializeMainUiGraph constructor calls and their preceding operator new(0x108) allocations as the two layout branches. | original-proof | Calls at 4f8460 and 4f89c7 from the same main-UI function. | by-file/SoundStatusPane.md callers and by-item/InitializeMainUiGraph_004F7D10.md | already-present | already-present-awaiting-supervisor-Gate2A |
| [x] | C0000NX-024 | 0002QH | Record MapPane exit-to-menu as the sole external global consumer and preserve deferred BlackHole deletion rather than direct delete or global clear. | original-proof | Read at 0x5048e6 and current source-ready teardown body. | UID0002QH relationship/callee evidence and SoundStatusPane cross-reference | incorporate | implemented-awaiting-supervisor-Gate2A |
| [x] | C0000NX-025 | 0000DG,0004UF | Preserve SoundManager as the external effect/music dependency; make UID0004UF open the guarded standalone H preamble, emit the local platform/Miles declarations and exact `g_pSoundManager` extern, and make UID0000DG emit the complete class then close the guard while retaining internal MIDI coordination. | very-strong | Exact live calls, current class surface, deterministic emitter order, complete project/platform prerequisites, all 37 decorated Miles imports, current handle widths, and UID0004UF's cross-module contract. | by-global/g_pSoundManager.md H channel/dependency/coverage; by-class/SoundManager.md H channel/dependencies/cross-reference; UID0000NX dependency audit | incorporate | implemented-awaiting-supervisor-Gate2A |
| [x] | C0000NX-026 | 00008A,0000LD,0000RM | Replace MidiPlayer class CPP commentary with `#include "MidiPlayer.h"`, add the complete class H declaration and UID0000RM singleton extern, document SoundStatusPane as a consumer, and raise class/file/global metadata to 89/92, 89/91, and 89/92. | strong | At the dated pre-callback baseline, generated MidiPlayer.cpp defined the full public surface without any include, MidiPlayer.h was absent, and semantic global UID0000RM had a blank H channel; producer and consumer require one class declaration plus one extern. | by-class/MidiPlayer.md CPP/H channels/cross-reference/metadata; by-file/MidiPlayer.md generated audit/metadata; by-global/g_pMidiPlayer.md H channel/metadata | incorporate | implemented-awaiting-supervisor-Gate2A |
| [x] | C0000NX-027 | 0000NX | Preserve Application, Config, Event/EventMan, Pane/GrafPort/RectBounds, Surface callback, SoundManager, and MidiPlayer contracts as exact dependencies and document the now-complete direct include/type/declaration closure. | very-strong | Section 22 supplies every required name, complete base/member type, enum, method, callback, global, Win32/DirectSound type, and local Miles declaration without implicit PCH or unavailable SDK assumptions. | by-file/SoundStatusPane.md dependency/include audit | incorporate | implemented-awaiting-supervisor-Gate2A |
| [x] | C0000NX-028 | 0000NX | Keep `NexusTK/ui/panels/` placement, update client_audio relationships, and reject proposed-tree/generated caveats that treat the empty output as complete. | very-strong | Main UI ownership, pane inheritance, audio-HUD role, and literal generated readback. | by-project-structure/proposed-source-tree.md, by-meta/client_audio.md, by-file/SoundStatusPane.md | reject-stale | implemented-awaiting-supervisor-Gate2A |
| [ ] | C0000NX-029 | 0001IG | At 0x57c080 use current-schema `rename` with `pure:true` for `SoundStatusPane__HandleKeyOrTextEvent`, then `set_repeatable_comments` for the one permitted function-repeatable comment; create no action-attributable `/vibe/` directory placement or decompiler/cache refresh and permit no other delta. | original-proof | Dated report-time canonical readback: exact function [57c080,57c15b), raw type, four absent comment channels, three frame rows, 219-byte SHA256 6B8B023994A746CD9B1141861950F0E839EC2038FD2788BEC1C2D2BE78FBDFD7, sole incoming xref 62cf48, zero desired-name collisions, and pure dry-run with no `dir`/`dir_error` fields while the non-pure control reports planned `dir:"vibe"`. | Section 21 C029 literal prestate/request/poststate | incorporate | proposed |
| [ ] | C0000NX-030 | 0001IG | At 0x57c160 use current-schema `rename` with `pure:true` for `SoundStatusPane__OnPaint`, then `set_repeatable_comments` for the one permitted function-repeatable comment; create no action-attributable `/vibe/` directory placement or decompiler/cache refresh and permit no other delta. | original-proof | Dated report-time canonical readback: exact function [57c160,57c23e), raw type, four absent comment channels, four frame rows, 222-byte SHA256 F6484919A4F824DF33F445EC2B1B4F51CA87D008FCE5805DD035EDCB08C14AC3, sole incoming xref 62cf38, zero desired-name collisions, and pure dry-run with no `dir`/`dir_error` fields while the non-pure control reports planned `dir:"vibe"`. | Section 21 C030 literal prestate/request/poststate | incorporate | proposed |
| [ ] | C0000NX-031 | 0000SB,0002WA | `NO_CHANGE`: verify and preserve the six one-byte undefined heads at 0x69b4d3-0x69b4d9, including four target heads, first-head type `SoundStatusPane *`, empty physical item names/comments, zero bytes, adjacent-head types, and complete target/predecessor/successor xrefs 6/0/8; call no data, rename, type, or comment endpoint. | original-proof | Dated report-time canonical readback preserved all six heads and bytes; `g_pSoundStatusPane` resolves as the sole existing address/global name at the target while every inspected physical item name remains empty, so there is no off-target collision and no deterministic typed-aggregate mutation is authorized. | Section 21 C031 literal NO_CHANGE prestate/protection/readback | already-present | proposed |
| [x] | C0000NX-032 | 0000NX | During an accepted callback, B009 implements/verifies C001-C028 plus C034-C037 ordinary-page work, runs only scoped ordinary-page validators, records their receipts, waits for generated refresh, and physically proves SoundStatusPane/MidiPlayer/SoundManager output against the command/timestamp actually returned by that callback; no fixed earlier command is timeless authority, and B009 does not edit manual coverage or lifecycle state. | strong | Dated pre-callback physical baseline at 2026-08-24T04:52:41.6321272Z is command 27320 with exact CPP/H hashes and MidiPlayer.h absence; Section 31 requires fresh callback receipts and exact standalone SoundManager.h inventory readback without supervisor-owned side effects. | Changed ordinary pages, Section 31 validator receipts, generated CPP/H readback | incorporate | implemented-awaiting-supervisor-Gate2A |
| [ ] | C0000NX-033 | 0000NX | After B009 callback work and supervisor verification, only the supervisor applies Section 28's twelve literal rows for by-file UID0000NX/UID0000LD/UID0000NV, by-class UID0000DJ/UID00008A/UID0000DG, by-memory UID0001IG/UID0002WA, by-global UID0000SB/UID0004UF/UID0000RM, and by-item UID0004WV, then owns Gate 2, report execution, archive movement/history, and archived-artifact audit. | original-proof | Section 28 contains those twelve exact rows; skill/goal assign every manual coverage replacement and lifecycle boundary to the supervisor, never B009. | Twelve named manual coverage rows in Section 28 and supervisor-owned lifecycle | incorporate | proposed |
| [x] | C0000NX-034 | 0000SB | Atomically replace every obsolete four-byte/current-physical-name statement on the semantic global page with the verified six one-byte-head neighborhood, four target heads, first-head-only type, empty physical item names/comments, and separate semantic `g_pSoundStatusPane -> 0x69B4D4` binding; preserve C031 NO_CHANGE. | original-proof | Dated report-time `inspect_items`, bytes/hash, type, comments, exact name/global collision readback, and xrefs 6/0/8. | by-global/g_pSoundStatusPane.md Status, Current IDA State, lifecycle, storage, IDA mapping, Score Rationale, Changes | incorporate | implemented-awaiting-supervisor-Gate2A |
| [x] | C0000NX-035 | 0002WA | Atomically replace every obsolete single-four-byte-item/current-name statement on the physical page with the exact six-head table and target/subrange distinction; state that range metadata does not imply an IDA aggregate and that no rename/type/data/comment endpoint is authorized. | original-proof | Six separate one-byte undefined heads at 0x69B4D3-0x69B4D8, zero-byte hash, d4-only pointer type, empty physical names/comments, and C031 NO_CHANGE. | by-memory/0x0069b4d4-0x0069b4d8.g_pSoundStatusPane.md Status, Item Summary, Current IDA State, evidence, non-emission, Score Rationale, Changes | incorporate | implemented-awaiting-supervisor-Gate2A |
| [x] | C0000NX-036 | 0004UF,0000DG | Add the exact standalone SoundManager header split: UID0004UF opens `NEXUSTK_AUDIO_SOUNDMANAGER_H`, includes `<windows.h>`, `<dsound.h>`, `<string.h>`, `<vector>`, `../util/Singleton.h`, `../util/StringBase.h`, and `../util/TimerHandler.h`, then declares the global; UID0000DG removes incomplete forward substitutes, emits the full class with era-compatible integer spellings, and closes the guard. | very-strong | Complete bases and vector element require full definitions; current StringBase inline requires `_strlwr_s`; current sibling generated guards and relative include style; Windows SDK owns HWND/DirectSound types; deterministic positions 0/10. | by-global/g_pSoundManager.md and by-class/SoundManager.md exact RECONSTRUCTION_H CODE/dependency prose | incorporate | implemented-awaiting-supervisor-Gate2A |
| [x] | C0000NX-037 | 0004UF,0000DG,0000NV,0004WV | Add the exact in-header local Miles compatibility block from Section 22: 32-bit signed/unsigned aliases, four opaque four-byte handles, `AILCALL`/`AILCALLBACK`, five callback-pointer types, and all 37 `extern "C"` declarations; document why the unavailable SDK/new shim/PCH/implicit-declaration alternatives are rejected and preserve UID0004WV's four source-static callback declarations unchanged. | strong | No local SDK/header/shim/import library; dated report-time 37-name decorated import set and arities; IDB handle widths; callback bodies/signatures; runtime `mss32.dll` string; complete SoundManager use inventory. | by-global/g_pSoundManager.md H channel; by-class/SoundManager.md dependency audit; by-file/SoundManager.md source/header/platform audit; by-item/SoundManagerMilesCallbackDeclarations.md type-source rationale | incorporate | implemented-awaiting-supervisor-Gate2A |

READY_FOR_SUPERVISOR_EXECUTE

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B009","command_id":"000000027519","destination_path":"executed-b-agent-research/B009/0000NX-SoundStatusPane-empty-emitter-whole-file-source-quality.md","details":"report executed into central archive","event":"executed","source_path":"tools/leaser/Agents/Agent-B009/research/0000NX-SoundStatusPane-empty-emitter-whole-file-source-quality.md","timestamp":"2026-08-24T04:24:24-04:00","uid":"0000NX"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
