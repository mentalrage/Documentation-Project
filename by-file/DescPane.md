*** UID:0000IS | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/controls/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:FILE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# DescPane

## Status

- Confidence: very strong for complete header/source shape, reusable-control
  placement, singleton/vtable ownership, all five method definitions, exact
  source ordering, compiler exclusions, and generated output route.
- Proposed module: `ui/controls/DescPane.cpp`
- Proposed header: `ui/controls/DescPane.h`
- Main class: [UID:00003Q][DescPane](by-class/DescPane.md)
- Main address doc: [UID:00012K][0x0049d6f0-0x0049d89f.DescPane](by-memory/0x0049d6f0-0x0049d89f.DescPane.md)
- Evidence basis: live IDA MCP disassembly/decompilation, vtable rows, singleton xrefs, and current project source-tree placement.
- Source route: UID00003Q emits the complete declaration and `[[CHILDREN]]`
  at file position 10; UID00012K is a false/non-emitting split index. The
  singleton definition UID0000QR emits at file position 20.

## File Role

`DescPane.cpp` owns a reusable `Pane`-derived description control. The pane stores borrowed `Pane *m_pDescriptionSource` at `+0xf8` and `int m_selectedDescriptionIndex` at `+0xfc`. The setter invalidates bounds only on a pair change. `OnPaint` unconditionally clears/fills inherited pane state, then asks the Pane source for a description through primary slot `+0x24` / [UID:0004IX][0x00544a20-0x00544a35.PaneGetDescription](by-memory/0x00544a20-0x00544a35.PaneGetDescription.md) when source/index guards pass.

Keep this separate from feature dialogs. Caller evidence is sparse, but the class is generic UI infrastructure: it has a singleton accessor, a Pane/index setter, and a primary `+0x44` `OnPaint` override. No custom provider UDT/vtable, source-pointer release, persistent description field, post-call buffer read, fallback/error branch, or feature-dialog ownership evidence exists.

## Proposed Contents

| Entity | Address evidence | Role |
| --- | --- | --- |
| [UID:00003Q][DescPane](by-class/DescPane.md) | `0x0049d6f0-0x0049d89f` | Complete class declaration at position 10 followed by constructor, ordinary destructor, singleton getter, Pane/index setter, and `OnPaint` definitions at 10/20/30/40/50; UID00012K is a non-emitting split/index. |
| [UID:0001U3][DescPaneLayout](by-type/by-struct/DescPaneLayout.md) | size `0x100`, fields `+0xf8` and `+0xfc` | `Pane` base plus borrowed `Pane *m_pDescriptionSource` and `int m_selectedDescriptionIndex`. |
| [UID:0001XC][DescPaneVtables](by-type/by-vtable/DescPaneVtables.md), [UID:0002NA][0x006189dc-0x00618a60.DescPaneVtableData](by-memory/0x006189dc-0x00618a60.DescPaneVtableData.md) | `0x006189dc`, `0x00618a28`, `0x00618a58` | Three vtable views installed by constructor and destructor paths. |
| [UID:0000QR][g_pDescPane](by-global/g_pDescPane.md) | [UID:0001PB][0x0069adf8-0x0069adfc.g_pDescPane](by-memory/0x0069adf8-0x0069adfc.g_pDescPane.md) | Active global singleton for the description pane. |

## Evidence Notes

- 2026-06-14 A002 live IDA refresh against session `a001_goal2_class_batch`: `lookup_funcs` reconfirmed raw starts `0x0049d6f0` and `0x0049d780` are still `Not a function`, while modeled methods remain `0x0049d740` size `0x29`, `0x0049d770` size `0x6`, `0x0049d7c0` size `0x5e`, and `0x0049d840` size `0x5f`.
- Historical 2026-06-14 `analyze_component` wording called `0x0049d7c0`
  `RefreshDescription`. Current analysis resolves it as `OnPaint`, calling
  `SetDrawColor`, `FillRect`, and the security-cookie check. The modeled
  methods have no internal call edges to unrelated feature-dialog code,
  supporting a standalone reusable-control file.
- 2026-06-14 `xrefs_to 0x0069adf8` returned exactly four data xrefs: raw constructor store `0x0049d731`, non-deleting destructor clear `0x0049d75a`, singleton getter read `0x0049d770`, and scalar deleting destructor clear `0x0049d860`.
- 2026-06-14 vtable xrefs again tie all three views to the DescPane island: `0x006189dc` at `0x0049d701`, `0x0049d740`, `0x0049d846`; `0x00618a28` at `0x0049d709`, `0x0049d746`, `0x0049d84c`; and `0x00618a58` at `0x0049d713`, `0x0049d750`, `0x0049d856`.
- Numeric evidence used here was verified with IDA `int_convert`: object size `0x100` / 256 bytes, provider pointer offset `+0xf8` / 248, selected-index offset `+0xfc` / 252, local refresh buffer size `0x800` / 2048, secondary view offset `+0xa0` / 160, and tertiary view offset `+0xa4` / 164.
- IDA MCP reports no function at the constructor-shaped raw start `0x0049d6f0`. Raw disassembly at `0x0049d6f0-0x0049d73b` calls the `Pane` constructor helper `sub_544460(1)`, installs three `DescPane` vtables, clears `+0xf8`, sets `+0xfc` to `-1`, and stores `g_pDescPane`.
- IDA models `0x0049d740` as a non-deleting destructor, `0x0049d770` as a singleton getter, `0x0049d7c0` as the virtual refresh routine, `0x0049d81e`/`0x0049d829` as adjustor thunks, and `0x0049d840` as the scalar deleting destructor.
- IDA MCP reports no function at the raw helper start `0x0049d780`. Current B006 implementation evidence from session `46666bf7` corrects the helper range to `0x0049d780-0x0049d7b2`, including the `retn 8` immediate bytes at `0x0049d7b0-0x0049d7b1`; raw instruction scan updates `+0xf8`/`+0xfc` when either value changes, then calls primary-vtable slot `+0x20` with the pane bounds at `this+0x44`.
- Vtable data at `0x006189dc`, `0x00618a28`, and `0x00618a58` points at the virtual refresh and destructor thunk rows; see [UID:0001XC][DescPaneVtables](by-type/by-vtable/DescPaneVtables.md).
- Live vtable data places the scalar deleting destructor at `0x006189dc`, refresh at `0x00618a20`, adjustor thunk `sub_49D81E` at `0x00618a28`, adjustor thunk `sub_49D829` at `0x00618a58`, and the next `DialogPane` RTTI at `0x00618a60`.
- IDA xrefs to [UID:0001PB][0x0069adf8-0x0069adfc.g_pDescPane](by-memory/0x0069adf8-0x0069adfc.g_pDescPane.md) are limited to the DescPane island: constructor store at `0x0049d731`, non-deleting destructor clear at `0x0049d75a`, singleton getter read at `0x0049d770`, and scalar deleting destructor clear at `0x0049d860`.
- Accepted complete analysis resolves `0x0049d7c0-0x0049d81e` as `DescPane::OnPaint`: `SetDrawColor(0)`, draw-mode clear, `FillRect(&m_bounds)`, then guarded Pane `GetDescription` with an uninitialized `wchar_t[1024]` local and no post-call read. Historical refresh/invalidation/narrow-buffer wording is superseded.
- 2026-06-18 B005 rechecked the raw constructor from memory and confirmed exact 76-byte range `0x0049d6f0-0x0049d73c`, three-byte prepad, four-byte postpad, `Pane(1)` base construction, vtable writes to `0x006189dc`/`0x00618a28`/`0x00618a58`, provider/source clear at `+0xf8`, selected-index sentinel `-1` at `+0xfc`, and `g_pDescPane` publish at `0x0069adf8`.
- B005 found no raw pointer or rel32 call/jump route to raw constructor start `0x0049d6f0` or raw setter start `0x0049d780`. That keeps confidence capped but does not move ownership away from this file because the positive vtable, singleton, destructor, getter, setter, refresh, and scalar destructor evidence is all local to the `DescPane` island.
- 2026-07-04 B008 implementation evidence from MCP session `73c77998` reconfirms the aggregate route: `lookup_funcs` still reports raw starts `0x0049d6f0` and `0x0049d780` as `Not a function`, modeled children remain `0x29`, `0x6`, `0x5e`, `0xb`, `0xb`, and `0x5f` bytes, `0x0049d89f-0x0049d8a0` is the one-byte successor gap before `DialogPane`, `xrefs_to` reconfirms no direct raw-start xrefs and the four local `g_pDescPane` refs, vtable slot checks keep `0x00618a20 -> 0x0049d7c0`, `0x00618a28 -> 0x0049d81e`, `0x00618a58 -> 0x0049d829`, and `0x006189dc -> 0x0049d840`, and type queries still find no local `DescPane`/provider UDT. The old generated UID00012K bare empty marker is therefore an aggregate-route defect, not an ownership or child-body blocker.

## Reconstruction Caveats

- Keep `0x0049d740`, `0x0049d770`, and raw `0x0049d780` with the file even though some partial reconstruction outputs omit them.
- 2026-05-25 follow-up data records [UID:0000QR][g_pDescPane](by-global/g_pDescPane.md) as resolved global-data at the four-byte storage range `0x0069adf8-0x0069adfc`.
- 2026-05-25 follow-up data says the earlier duplicate memory issue for `method:0x0049d6f0` is no longer active.
- IDA still decompiles both 11-byte adjustor thunks. The thunks are recorded in [UID:0000VN][-ignored](by-memory/-ignored.md) as compiler glue, not handwritten source.

## Source-Structure Decision

Use separate `ui/controls/DescPane.cpp`. It is higher-level than `Pane.cpp` but not feature-dialog owned. The class consumes the existing Pane virtual contract at primary `+0x24`; no separate provider interface should be declared.

B005's owner ranking keeps this file placement and rejects less-specific or unsupported alternatives:

| Candidate | Decision |
| --- | --- |
| `Pane.cpp` | Reject: base constructor/inherited slots only; `DescPane` vtables, singleton, tail fields, and refresh override are class-specific. |
| `DialogPane.cpp` | Reject: `DialogPane` RTTI begins at `0x00618a60`; this constructor has no dialog-control or dialog-title behavior. |
| Feature dialog modules | Reject: no caller/xref fanout ties the constructor to a feature dialog. |
| Generic UI core | Reject as too broad; `ui/controls/DescPane.cpp` is already supported by project structure and class behavior. |

## C++ Staging

UID00003Q owns the complete managed class declaration and places its closing
`};` before `[[CHILDREN]]`. UID00012J, UID00012L, UID00012M, UID00012N, and
UID00012O own the exact constructor, destructor, singleton getter,
source/index setter, and `OnPaint` managed definitions. UID0000QR owns the one
managed `g_pDescPane` definition. UID0001U3, UID0001XC, UID0002NA, and
UID0001PB carry nonduplicating declaration/vtable/data coverage markers.

UID00012K is a blank non-emitting split/index. UID00012P and UID00012Q are
blank compiler glue. The file route emits no literal vtable arrays, RTTI
objects, vptr assignments, adjustor bodies, scalar deleting wrapper, explicit
Pane destructor call, duplicate method, or duplicate storage definition.

## Score Rationale

- Completion is `92` because the file page carries the complete declaration,
  exact five-method order, singleton definition, layout/vtable/data markers,
  split index, compiler exclusions, generated assertions, Pane/index lifetime,
  source placement, negatives, and rejected alternatives.
- Confidence is `94` because all class/memory/type/global and generated-route
  evidence agrees on the reusable control and concrete Pane contract.
  Original spellings and direct raw constructor/setter reachability remain the
  only caps.

## Cross-References

- [UID:00003Q][DescPane](by-class/DescPane.md)
- [UID:00012K][0x0049d6f0-0x0049d89f.DescPane](by-memory/0x0049d6f0-0x0049d89f.DescPane.md)
- [UID:0001U3][DescPaneLayout](by-type/by-struct/DescPaneLayout.md)
- [UID:0001XC][DescPaneVtables](by-type/by-vtable/DescPaneVtables.md)
- [UID:0002NA][0x006189dc-0x00618a60.DescPaneVtableData](by-memory/0x006189dc-0x00618a60.DescPaneVtableData.md)
- [UID:0000QR][g_pDescPane](by-global/g_pDescPane.md)
- [UID:0001PB][0x0069adf8-0x0069adfc.g_pDescPane](by-memory/0x0069adf8-0x0069adfc.g_pDescPane.md)
- [UID:0000MC][Pane](by-file/Pane.md)
- [UID:0001QV][client_ui_core](by-meta/client_ui_core.md)

## 2026-07-16 B001 UID0002NA Accepted Callback

- Applied `92/94` and preserved `NexusTK/ui/controls/`.
- Header/source shape is complete: class declaration and extern at file
  position 10; constructor/destructor/getter/setter/OnPaint at
  10/20/30/40/50 beneath the class; layout/vtable support at 60/70; one
  singleton definition at file position 20 with storage child position 10.
- Generated `DescPane.cpp` must contain one closed class followed by five
  qualified definitions, one global definition, one storage marker, and one
  each layout/vtable/target marker.
- UID00012K, adjustors, scalar wrapper, RTTI/table bytes, vptr stores, and base
  teardown remain non-emitting compiler/index evidence.
- Historical aggregate-marker, RefreshDescription, custom-provider,
  narrow-buffer, incomplete-header, and feature-dialog placement claims are
  superseded while their dated provenance remains preserved.

## Changes

- 2026-07-16 B001 UID0002NA accepted callback:
  - Raised `88/90 -> 92/94`; recorded the complete header/source/global order,
    current marker route, compiler exclusions, and structural generated-output
    assertions.
- 2026-07-12 B003 UID00012O accepted callback: raised `86/87 -> 88/90`; synchronized the source route to borrowed `Pane *`, exact `Pane::GetDescription(int,wchar_t *)`, `wchar_t[1024]`, and `DescPane::OnPaint`; retained aggregate `[[CHILDREN]]`, all other child bodies, raw-start/no-route evidence, singleton/vtables, compiler exclusions, and rejected source placements. Earlier custom-provider/RefreshDescription/narrow-buffer statements below are historical and superseded.
- 2026-07-04 B008 aggregate marker implementation callback:
  - Before: UID00012K's child methods were generated through `DescPane.cpp`, but the aggregate itself still rendered as a bare empty emitter because its formal block was blank.
  - Changed to: documents UID00012K as an `88/90` aggregate marker route with formal `[[CHILDREN]]`, while keeping child method bodies on child pages and this file-level formal block blank.
  - Summary/evidence: current MCP session `73c77998` confirms exact range/padding, raw constructor/setter non-function starts and no-xref caps, modeled child sizes, singleton refs, vtable refs/slots, provider/index fields, no local `DescPane` or provider UDT, generated empty-marker defect, child-source/no-code split, and rejected `Pane`/`DialogPane`/feature-dialog/generic-UI/no-owner/range-extension alternatives.
- 2026-06-29 B006 setter implementation callback:
  - Before: C++ staging listed constructor/getter child bodies but still treated the raw setter helper source name as a blocker for emission.
  - Changed to: added [UID:00012N][0x0049d780-0x0049d7b2.DescPaneSetSourceAndIndexRaw](by-memory/0x0049d780-0x0049d7b2.DescPaneSetSourceAndIndexRaw.md) as a child-owned first-draft `DescPane::SetSourceAndIndex(DescPaneDescriptionSource *source, int selectedIndex)` method under `NexusTK/ui/controls/DescPane.cpp`; kept the file-level formal block blank to avoid duplicating child methods.
  - Summary/evidence: current MCP session `46666bf7` proves the corrected setter range, no direct raw-start route, paired `m_pDescriptionSource`/`m_selectedDescriptionIndex` update, inherited `InvalidateRect(&m_bounds)` dispatch, and refresh-side provider/index consumption.
- 2026-06-19 B010 getter source-quality incorporation:
  - Before: C++ staging only named the constructor child as first-draft source code.
  - Changed to: added [UID:00012M][0x0049d770-0x0049d776.DescPaneGetSingleton](by-memory/0x0049d770-0x0049d776.DescPaneGetSingleton.md) as a child-owned first-draft getter body returning `g_pDescPane`, while keeping the file-level formal block blank.
  - Summary/evidence: exact getter bytes, DescPane-island-only singleton refs, source-facing [UID:0000QR][g_pDescPane](by-global/g_pDescPane.md), and the unchanged `ui/controls/DescPane.cpp` route support this staging.
- 2026-06-18 B005 constructor source-quality incorporation:
  - Before: the file page kept broad raw-start/provider caveats and did not state that the constructor child can now emit first-draft C++.
  - Changed to: added field names `m_pDescriptionSource`/`m_selectedDescriptionIndex`, exact constructor byte/boundary/no-route evidence, owner-candidate rejection table, and C++ staging policy that allows [UID:00012J][0x0049d6f0-0x0049d73c.DescPaneConstructorRaw](by-memory/0x0049d6f0-0x0049d73c.DescPaneConstructorRaw.md) constructor code while keeping file-level/header output provisional.
  - Summary/evidence: B005 verified `Pane(1)` construction, vtable stores, singleton publish, provider/index initialization, no pointer/rel32 route to raw starts, and source placement under `NexusTK/ui/controls/DescPane.cpp`.
- 2026-06-14 A002 Goal2 by-file refresh:
  - Before: `COMPLETION:84`, `CONFIDENCE:84`; the page had good behavior notes but did not include the newer aggregate child split or a current live xref/component refresh.
  - Changed to: `COMPLETION:86`, `CONFIDENCE:87`, with live IDA function/xref evidence, verified numeric conversions, and explicit score rationale.
  - Evidence: IDA MCP session `a001_goal2_class_batch` reconfirmed raw `0x0049d6f0`/`0x0049d780` non-function starts, modeled methods at `0x0049d740`, `0x0049d770`, `0x0049d7c0`, and `0x0049d840`, four singleton xrefs to `0x0069adf8`, three-view vtable xrefs, and the reusable-control isolation from feature-dialog code.
- 2026-05-30 completion/confidence scoring:
  - What existed before: `COMPLETION:0` and `CONFIDENCE:0`.
  - Changed to: `COMPLETION:82` and `CONFIDENCE:78`.
  - Summary/evidence: class role, layout/vtable/global anchors, raw setter/destructor gaps, reconstruction caveats, singleton resolution, and source-structure decision are documented; confidence remains medium-high because final folder and provider-interface naming remain open.
- 2026-05-31 projected reconstruction path:
  - What existed before: `PROPOSED_RECONSTRUCTION_PATH` was blank.
  - Changed to: `NexusTK/ui/controls/`.
  - Summary/evidence: `by-project-structure/proposed-source-tree.md` places `DescPane.cpp` under `ui/controls`, and the 2026-05-31 IDA MCP recheck confirms this is a reusable pane/control class rather than a feature-dialog owner.
- 2026-06-04 live IDA refresh:
  - What existed before: the file was scored `82/78` and still mixed live IDA facts with stale source/cache caveats.
  - Changed to: `COMPLETION:84`, `CONFIDENCE:84`.
  - Summary/evidence: live IDA confirms the raw constructor-shaped block, raw source/index setter block, modeled lifecycle/getter/refresh/destructor functions, singleton xrefs to `0x0069adf8`, exact vtable rows through `0x00618a60`, and the reusable-control source placement. Confidence remains below final because the provider interface is behaviorally understood but not source-named, and two class-local blocks are still raw non-function starts with no direct callers.
