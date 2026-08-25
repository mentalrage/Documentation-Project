*** UID:0000IU | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/dialogs/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:FILE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# DialogSession

## Status

- Confidence: very strong for class grouping, complete source declarations, session-stack behavior, compiler/source split, and file-root ownership; strong for the inferred historical folder spelling.
- Proposed source file: `ui/dialogs/DialogSession.cpp`
- Alternative placement: `ui/session/DialogSession.cpp`
- Current generated sources: `class_DialogSession.cpp` and `class_DialogInSession.cpp`
- Type docs: [UID:0001U5][DialogSessionLayouts](by-type/by-struct/DialogSessionLayouts.md)
- Vtables: [UID:0001XD][DialogSessionVtables](by-type/by-vtable/DialogSessionVtables.md), exact data [UID:0002NB][0x00618d2c-0x00618e50.DialogSessionVtableData](by-memory/0x00618d2c-0x00618e50.DialogSessionVtableData.md)
- Evidence basis: current by-class/by-memory/by-type pages, `source-3/simroot_v2` generated files, IDA MCP checks on 2026-05-24 and 2026-05-26, and the 2026-06-06 `DialogSessionCore` memory audit.

## Hypothesis

The original source kept `DialogSession` and `DialogInSession` together. `DialogSession` is a Pane-derived session container with protected `List *m_dialogList` and byte `m_activeDialogIndex`, pushes and pops session-bound dialogs, tears down the current stack, and attaches a full-screen renderer. `DialogInSession` is the DialogPane-derived base with exact `DialogSession *`, `unsigned short dialogConfigId`, `unsigned char dialogType`, public `m_dialogType`, and public `m_session` source contract.

This source is a shared dialog/session infrastructure file. Feature dialogs such as bulletin, mail, article, and ranking dialogs should derive from or call it, but their feature-specific packet parsing and UI controls belong in their own modules.

## Proposed Contents

| Entity | Current range | Current file | Role |
| --- | --- | --- | --- |
| `DialogSession` | source class plus exact method children inside `0x004a0d80-0x004a15f8` | generated in `DialogSession.cpp` | Session pane, protected active-dialog list/index state, constructor, ordinary virtual destructor, and exact stack helper source. Scalar deleting wrappers/adjustors are compiler output. |
| `DialogInSession` | source class plus constructor/ordinary destructor inside `0x004a1400-0x004a14f5` | generated in `DialogSession.cpp` | Base dialog stored inside a DialogSession with exact constructor types and public tail fields. Scalar deleting wrapper/adjustors are compiler output. |
| compiler/layout support | UID000131, UID000134, UID0001U5, UID0001XD, UID0002NB | non-emitting | Physical index, adjustor thunks, layout notes, vtable type authority, and exact RTTI/vtable bytes document the binary but do not emit C++. |

## Vtable Layout

| Class | Primary | Secondary | Tertiary | Notes |
| --- | --- | --- | --- | --- |
| `DialogSession` | `0x00618d30` | `0x00618d7c` | `0x00618dac` | Constructor installs these at `0x004a0dc1`, `0x004a0dc7`, and `0x004a0dd1`; destructor paths reinstall them before cleanup. |
| `DialogInSession` | `0x00618db8` | `0x00618e18` | `0x00618e48` | Constructor installs these at `0x004a142d`, `0x004a1433`, and `0x004a143d`; destructor paths reinstall them before base teardown. |

The exact compiler-data child begins at `0x00618d2c` with the primary DialogSession COL pointer. Table counts are DialogSession 18/11/2 and DialogInSession 23/11/2; object facets are `0/+0xa0/+0xa4`. The short DialogSession tertiary table ends before the DialogInSession primary COL at `0x00618db4`; the DialogInSession tertiary table ends at the exact DIBitmap successor `0x00618e50`.

## Exact Support Pages

| Evidence page | Current score | Why it supports this file root |
| --- | ---: | --- |
| [UID:000131][0x004a0d80-0x004a15f8.DialogSessionCore](by-memory/0x004a0d80-0x004a15f8.DialogSessionCore.md) | `90/92` | Non-emitting mixed physical index preserving the complete constructor/destructor/helper, ScreenDimmer, compiler, caller, and historical union without duplicate aggregate source. |
| [UID:000132][0x004a0f40-0x004a14a7.BulletinSessionDialogStack](by-memory/0x004a0f40-0x004a14a7.BulletinSessionDialogStack.md) | `86/90` | Historical overlapping stack-helper split/index. It is now non-emitting because the source-bearing payload is five DialogSession helper leaves while the parent range also crosses ScreenDimmer, runtime/resource, DialogInSession, thunk, and scalar-destructor bytes. |
| [UID:0002NB][0x00618d2c-0x00618e50.DialogSessionVtableData](by-memory/0x00618d2c-0x00618e50.DialogSessionVtableData.md) | `93/94` | Non-emitting 292-byte compiler cluster with six COL pointers, all 67 slots, exact store triads, source/compiler disposition, and DIBitmap boundary. |
| [UID:0001U5][DialogSessionLayouts](by-type/by-struct/DialogSessionLayouts.md) | `91/94` | Non-emitting layout authority for direct bases, inherited facets, protected/public fields, constructor widths, and natural alignment. |
| [UID:0001XD][DialogSessionVtables](by-type/by-vtable/DialogSessionVtables.md) | `92/94` | Non-emitting type authority for all six table views and exact inherited method identities. |

## IDA MCP Evidence

- IDA confirms `DialogSession` constructor/destructor at `0x004a0d80` and `0x004a0e70`.
- IDA confirms additional `DialogSession` helpers at `0x004a0f40`, `0x004a0fc0`, `0x004a10e0`, `0x004a11e0`, `0x004a1250`, `0x004a1390`, and `0x004a13b0`. The `0x004a11e0` and `0x004a13b0` pockets have no direct callers but are coherent source-shaped helpers, best documented as private/protected `ActivateNextDialog(bool shouldAnimate)` and `FindDialogIndex(DialogInSession *dialog)`. The adjacent `0x004a12b0` helper is the shared [UID:0000PJ][CreateScreenDimmer_4A12B0](by-global/CreateScreenDimmer_4A12B0.md) factory and should migrate with [UID:0000NA][ScreenDimmer](by-file/ScreenDimmer.md), not `DialogSession`.
- B001 2026-06-17 rechecked the historical [UID:000132][0x004a0f40-0x004a14a7.BulletinSessionDialogStack](by-memory/0x004a0f40-0x004a14a7.BulletinSessionDialogStack.md) page and reclassified it as a non-emitting split/index. Exact helper leaves remain DialogSession-owned, but the mixed parent range must not duplicate [UID:000131][0x004a0d80-0x004a15f8.DialogSessionCore](by-memory/0x004a0d80-0x004a15f8.DialogSessionCore.md) emission.
- IDA confirms `DialogInSession` constructor at `0x004a1400`, non-deleting destructor at `0x004a1450`, destructor thunks at `0x004a146f` and `0x004a147a`, and scalar deleting destructor at `0x004a14a0`.
- IDA confirms `DialogSession` destructor thunks at `0x004a1485` and `0x004a1490`, and scalar deleting destructor at `0x004a1500`.
- IDA confirms six vtable bases: `DialogSession` at `0x00618d30`, `0x00618d7c`, and `0x00618dac`; `DialogInSession` at `0x00618db8`, `0x00618e18`, and `0x00618e48`.
- `xrefs_to 0x004a1400` shows construction from several bulletin/session dialog constructors, while `xrefs_to 0x004a0fc0`, `0x004a10e0`, and `0x004a1250` show broad use by the bulletin/session family.
- The source class declarations regenerate the complete compiler cluster. Do not add literal vtable/RTTI/COL/base-array definitions, explicit vptr stores, adjustor arithmetic, scalar-wrapper deletion flags, or a synthetic `DialogSessionVtables.cpp`.

## Ownership Notes

- Keep `DialogSession` infrastructure out of feature-specific files like [UID:0000HX][BulletinSession](by-file/BulletinSession.md) except as a dependency/base.
- `DialogInSession` should stay beside `DialogSession`; it is the session-bound dialog base used by bulletin-style dialogs.
- [UID:00003U][DialogSession](by-class/DialogSession.md) at `92/93` and [UID:00003S][DialogInSession](by-class/DialogInSession.md) at `92/93` are complete direct class children of this file root. The shared physical island and vtable/type pages document both classes together, so splitting one class into a different source root is unsupported.
- Historical recovered class files omitted helpers/destructors and carried `BackGroundPane`/feature type pollution. Current validator-generated source is authoritative only for assembly of accepted managed blocks; live IDA and current docs remain authority for behavior.
- Historical zero-vtable metadata is superseded by exact three-view evidence for each class.
- Active generated `RankingDialog*` helper typings are not source-quality for this shared stack. Use `DialogInSession*` as the best tracked-entry direction until final declarations are coordinated. Generated/recovered `ChattingColorPane` close-helper names are also pollution; the shared close/teardown behavior is dialog-session infrastructure.

## Parent-Gate Readiness

This file page is `90/93` and directly owns/emits both complete class declarations. Completion reflects the source/module union, exact classes, helper inventory, compiler/layout support division, source-compatible access/types, ScreenDimmer exclusions, table maps, and no-handwritten-ABI policy. Confidence remains below absolute certainty only because the historical folder spelling and a few private helper names are inferred.

## MailDialogs Shared-Stack Boundary

- [UID:0000KZ][MailDialogs](by-file/MailDialogs.md) owns the feature-specific `MailListDialog`, `MailListPane`, `MailDialog`, and `NewMailDialog` declarations and their 53 source-shaped bodies. Those dialogs depend on this file's `DialogSession`/`DialogInSession` infrastructure but do not transfer their feature code here.
- Calls from the mail family to `DialogSession::PushDialog` at `0x004a0fc0`, lookup/pop helpers, active-dialog tracking, and screen-dimmer/session behavior remain shared stack operations owned by DialogSession. Conversely, mail packet parsing, control construction, request helpers, navigation, deletion, send, quote, and save/export behavior remain MailDialogs-owned.
- The broad physical MailDialogs index and BulletinSession call-ins therefore treat DialogSession as a dependency only. This clarification changes no DialogSession score, source path, class ownership, emitter route, or formal source content.

## Cross-References

- [UID:00003U][DialogSession](by-class/DialogSession.md)
- [UID:00003S][DialogInSession](by-class/DialogInSession.md)
- [UID:000131][0x004a0d80-0x004a15f8.DialogSessionCore](by-memory/0x004a0d80-0x004a15f8.DialogSessionCore.md)
- [UID:0001U5][DialogSessionLayouts](by-type/by-struct/DialogSessionLayouts.md)
- [UID:0001XD][DialogSessionVtables](by-type/by-vtable/DialogSessionVtables.md)
- [UID:0002NB][0x00618d2c-0x00618e50.DialogSessionVtableData](by-memory/0x00618d2c-0x00618e50.DialogSessionVtableData.md)
- [UID:000134][0x004a146f-0x004a149b.DialogSessionAdjustorThunks](by-memory/0x004a146f-0x004a149b.DialogSessionAdjustorThunks.md)
- [UID:0000IT][DialogPane](by-file/DialogPane.md)
- [UID:0000A2][Pane](by-class/Pane.md)
- [UID:0000HX][BulletinSession](by-file/BulletinSession.md)
- [UID:0000HT][BoardDialogs](by-file/BoardDialogs.md)

## Changes

- 2026-08-11 Agent-B002 UID0000KZ whole-file implementation callback: added the no-change shared-stack boundary between DialogSession infrastructure and MailDialogs feature code; preserved `90/93`, FILE ownership, and all existing class/helper routes.

- 2026-07-16 B004 UID0002NB accepted implementation callback:
  - Changed `88/90 -> 90/93`, preserving `NexusTK/ui/dialogs/`, FILE ownership, all helper/caller/ScreenDimmer/history evidence, and every unrelated source-family relationship.
  - Synchronized the complete DialogSession/DialogInSession declarations, protected/public access, `unsigned short` config type, direct bases, exact compiler views, renamed UID0002NB path, and non-emitting UID000131/UID0001U5/UID0001XD support routes.
  - Historical incomplete generated-class and zero-vtable claims are superseded; no literal vtable, RTTI, adjustor, or scalar deleting-wrapper source is permitted.
- 2026-06-07 A003 Batch 084 parent-gate update:
  - Changed to: `COMPLETION:86`, `CONFIDENCE:86`.
  - Summary/evidence: added exact support-page table and parent-gate rationale for using this file as the direct owner of [UID:00003U][DialogSession](by-class/DialogSession.md) and [UID:00003S][DialogInSession](by-class/DialogInSession.md). The raised scores are justified by [UID:000131][0x004a0d80-0x004a15f8.DialogSessionCore](by-memory/0x004a0d80-0x004a15f8.DialogSessionCore.md) at `86/88`, [UID:0002NB][0x00618d2c-0x00618e50.DialogSessionVtableData](by-memory/0x00618d2c-0x00618e50.DialogSessionVtableData.md) at `86/90`, the layout/vtable type pages, and the documented ScreenDimmer ownership split.
- 2026-06-17 B001 stack-index execution:
  - Score unchanged at `86/86`.
  - Added the accepted non-emitting policy for [UID:000132][0x004a0f40-0x004a14a7.BulletinSessionDialogStack](by-memory/0x004a0f40-0x004a14a7.BulletinSessionDialogStack.md), preserving DialogSession source ownership for exact helper leaves while preventing duplicate aggregate emission.
- 2026-06-20 B002 Rule 26 incorporation:
  - Changed to: `COMPLETION:88`, `CONFIDENCE:90`.
  - Summary/evidence: added the missing raw no-direct-call helpers `0x004a11e0`/`0x004a13b0`, corrected current generated-output and vtable metadata wording, rejected `RankingDialog*` and `ChattingColorPane` pollution, preserved `DialogInSession*` stack typing, and documented `ReleaseScreenDimmer`/`IsScreenDimmerActive` as ScreenDimmer/global helpers outside the DialogSession class.

- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:84` and `CONFIDENCE:80`.
  - Summary/evidence: session/dialog base grouping, vtable layouts, IDA helper inventory, screen-dimmer exclusion, infrastructure ownership notes, active generated-output omissions, and cross-references are documented; confidence is strong but exact folder naming remains open.
- 2026-05-31 projected reconstruction path:
  - What existed before: `PROPOSED_RECONSTRUCTION_PATH` was blank.
  - Changed to: `NexusTK/ui/dialogs/`.
  - Summary/evidence: `by-project-structure/proposed-source-tree.md` places `DialogSession.cpp` under `ui/dialogs`, and the 2026-05-31 IDA MCP recheck confirms `DialogSession`/`DialogInSession` are shared session-dialog infrastructure used by bulletin/session dialog families.
