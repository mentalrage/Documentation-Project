*** UID:0000IU | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/dialogs/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# DialogSession

## Status

- Confidence: strong for class grouping, session-stack behavior, and file-root ownership; medium-high for exact original folder name.
- Proposed source file: `ui/dialogs/DialogSession.cpp`
- Alternative placement: `ui/session/DialogSession.cpp`
- Current generated sources: `class_DialogSession.cpp` and `class_DialogInSession.cpp`
- Type docs: [UID:0001U5][DialogSessionLayouts](by-type/by-struct/DialogSessionLayouts.md)
- Vtables: [UID:0001XD][DialogSessionVtables](by-type/by-vtable/DialogSessionVtables.md), exact data [UID:0002NB][0x00618d30-0x00618e50.DialogSessionVtableData](by-memory/0x00618d30-0x00618e50.DialogSessionVtableData.md)
- Evidence basis: current by-class/by-memory/by-type pages, `source-3/simroot_v2` generated files, IDA MCP checks on 2026-05-24 and 2026-05-26, and the 2026-06-06 `DialogSessionCore` memory audit.

## Hypothesis

The original source likely kept `DialogSession` and `DialogInSession` together. `DialogSession` is a pane-derived session container that owns the active dialog stack/list, pushes and pops session-bound dialogs, tears down the current stack, and attaches a full-screen renderer. `DialogInSession` is the session-bound dialog base over `DialogPane` with stored session data and dialog type fields.

This source is a shared dialog/session infrastructure file. Feature dialogs such as bulletin, mail, article, and ranking dialogs should derive from or call it, but their feature-specific packet parsing and UI controls belong in their own modules.

## Proposed Contents

| Entity | Current range | Current file | Role |
| --- | --- | --- | --- |
| `DialogSession` | `0x004a0d80-0x004a15f8` | `class_DialogSession.cpp` | Session pane, active dialog list/stack owner, session renderer attachment, dialog push/pop/close helpers, and scalar deleting destructor. |
| `DialogInSession` | `0x004a1400-0x004a14f5` | `class_DialogInSession.cpp` | Base dialog stored inside a `DialogSession`; keeps session data and dialog type. |

## Vtable Layout

| Class | Primary | Secondary | Tertiary | Notes |
| --- | --- | --- | --- | --- |
| `DialogSession` | `0x00618d30` | `0x00618d7c` | `0x00618dac` | Constructor installs these at `0x004a0dc1`, `0x004a0dc7`, and `0x004a0dd1`; destructor paths reinstall them before cleanup. |
| `DialogInSession` | `0x00618db8` | `0x00618e18` | `0x00618e48` | Constructor installs these at `0x004a142d`, `0x004a1433`, and `0x004a143d`; destructor paths reinstall them before base teardown. |

The short tertiary tables end at `0x00618db4` for `DialogSession` and `0x00618e50` for `DialogInSession`; the following RTTI belongs to the next class.

## Exact Support Pages

| Evidence page | Current score | Why it supports this file root |
| --- | ---: | --- |
| [UID:000131][0x004a0d80-0x004a15f8.DialogSessionCore](by-memory/0x004a0d80-0x004a15f8.DialogSessionCore.md) | `86/88` | Exact mixed code island covering the `DialogSession` constructor/destructor/stack helpers, `DialogInSession` constructor/destructor, adjustor thunks, runtime-helper caveat, and the separately owned ScreenDimmer factory split. |
| [UID:0002NB][0x00618d30-0x00618e50.DialogSessionVtableData](by-memory/0x00618d30-0x00618e50.DialogSessionVtableData.md) | `86/90` | Exact six-table `.rdata` cluster for the `DialogSession` and `DialogInSession` primary/secondary/tertiary views, with constructor/destructor store xrefs and DIBitmap boundary. |
| [UID:0001U5][DialogSessionLayouts](by-type/by-struct/DialogSessionLayouts.md) | `82/88` | Layout page records `DialogSession +0xf8/+0xfc` stack state and `DialogInSession +0x26c/+0x270` tail fields. |
| [UID:0001XD][DialogSessionVtables](by-type/by-vtable/DialogSessionVtables.md) | `86/90` | Type-level vtable owner for the same six table bases and destructor adjustor thunk relationships. |

## IDA MCP Evidence

- IDA confirms `DialogSession` constructor/destructor at `0x004a0d80` and `0x004a0e70`.
- IDA confirms additional `DialogSession` helpers at `0x004a0f40`, `0x004a0fc0`, `0x004a10e0`, `0x004a1250`, `0x004a1360`, and `0x004a1390` that active generated output omits. The adjacent `0x004a12b0` helper is now documented as the shared [UID:0000PJ][CreateScreenDimmer_4A12B0](by-global/CreateScreenDimmer_4A12B0.md) factory and should migrate with [UID:0000NA][ScreenDimmer](by-file/ScreenDimmer.md), not `DialogSession`.
- IDA confirms `DialogInSession` constructor at `0x004a1400`, non-deleting destructor at `0x004a1450`, destructor thunks at `0x004a146f` and `0x004a147a`, and scalar deleting destructor at `0x004a14a0`.
- IDA confirms `DialogSession` destructor thunks at `0x004a1485` and `0x004a1490`, and scalar deleting destructor at `0x004a1500`.
- IDA confirms six vtable bases: `DialogSession` at `0x00618d30`, `0x00618d7c`, and `0x00618dac`; `DialogInSession` at `0x00618db8`, `0x00618e18`, and `0x00618e48`.
- `xrefs_to 0x004a1400` shows construction from several bulletin/session dialog constructors, while `xrefs_to 0x004a0fc0`, `0x004a10e0`, and `0x004a1250` show broad use by the bulletin/session family.

## Ownership Notes

- Keep `DialogSession` infrastructure out of feature-specific files like [UID:0000HX][BulletinSession](by-file/BulletinSession.md) except as a dependency/base.
- `DialogInSession` should stay beside `DialogSession`; it is the session-bound dialog base used by bulletin-style dialogs.
- [UID:00003U][DialogSession](by-class/DialogSession.md) and [UID:00003S][DialogInSession](by-class/DialogInSession.md) are now intended direct class children of this file root once their class pages clear 85/85. The shared physical memory island and vtable/type pages document both classes together, so splitting one class into a different source root is not supported by current evidence.
- The active generated `class_DialogSession.cpp` is incomplete as a source-layout guide because it omits the central stack push/pop helpers.
- The active generated `class_DialogInSession.cpp` omits the non-deleting destructor and has local type alias pollution referencing `BackGroundPane`.
- Current Wave3 metadata for both classes reports `vtable_count: 0`; use the IDA-confirmed table bases until generated metadata is corrected.

## Parent-Gate Readiness

This file page now clears the strict 85/85 gate as a direct parent for [UID:00003U][DialogSession](by-class/DialogSession.md) and [UID:00003S][DialogInSession](by-class/DialogInSession.md). Completion is `86` because the page records the proposed source path, class grouping, exact code island, vtable cluster, layout evidence, generated-output omissions, caller/ownership notes, and the ScreenDimmer exclusion. Confidence is `86` because the direct file-root relationship is corroborated by the exact memory/type pages and proposed source tree, while exact historical folder naming and final method declarations remain below final-source certainty.

## Cross-References

- [UID:00003U][DialogSession](by-class/DialogSession.md)
- [UID:00003S][DialogInSession](by-class/DialogInSession.md)
- [UID:000131][0x004a0d80-0x004a15f8.DialogSessionCore](by-memory/0x004a0d80-0x004a15f8.DialogSessionCore.md)
- [UID:0001U5][DialogSessionLayouts](by-type/by-struct/DialogSessionLayouts.md)
- [UID:0001XD][DialogSessionVtables](by-type/by-vtable/DialogSessionVtables.md)
- [UID:0002NB][0x00618d30-0x00618e50.DialogSessionVtableData](by-memory/0x00618d30-0x00618e50.DialogSessionVtableData.md)
- [UID:000134][0x004a146f-0x004a149b.DialogSessionAdjustorThunks](by-memory/0x004a146f-0x004a149b.DialogSessionAdjustorThunks.md)
- [UID:0000IT][DialogPane](by-file/DialogPane.md)
- [UID:0000A2][Pane](by-class/Pane.md)
- [UID:0000HX][BulletinSession](by-file/BulletinSession.md)
- [UID:0000HT][BoardDialogs](by-file/BoardDialogs.md)

## Changes

- 2026-06-07 A003 Batch 084 parent-gate update:
  - Changed to: `COMPLETION:86`, `CONFIDENCE:86`.
  - Summary/evidence: added exact support-page table and parent-gate rationale for using this file as the direct owner of [UID:00003U][DialogSession](by-class/DialogSession.md) and [UID:00003S][DialogInSession](by-class/DialogInSession.md). The raised scores are justified by [UID:000131][0x004a0d80-0x004a15f8.DialogSessionCore](by-memory/0x004a0d80-0x004a15f8.DialogSessionCore.md) at `86/88`, [UID:0002NB][0x00618d30-0x00618e50.DialogSessionVtableData](by-memory/0x00618d30-0x00618e50.DialogSessionVtableData.md) at `86/90`, the layout/vtable type pages, and the documented ScreenDimmer ownership split.

- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:84` and `CONFIDENCE:80`.
  - Summary/evidence: session/dialog base grouping, vtable layouts, IDA helper inventory, screen-dimmer exclusion, infrastructure ownership notes, active generated-output omissions, and cross-references are documented; confidence is strong but exact folder naming remains open.
- 2026-05-31 projected reconstruction path:
  - What existed before: `PROPOSED_RECONSTRUCTION_PATH` was blank.
  - Changed to: `NexusTK/ui/dialogs/`.
  - Summary/evidence: `by-project-structure/proposed-source-tree.md` places `DialogSession.cpp` under `ui/dialogs`, and the 2026-05-31 IDA MCP recheck confirms `DialogSession`/`DialogInSession` are shared session-dialog infrastructure used by bulletin/session dialog families.
