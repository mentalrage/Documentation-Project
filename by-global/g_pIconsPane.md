*** UID:0000R6 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000JZ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000JZ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:30 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
IconsPane *g_pIconsPane = NULL;
[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# g_pIconsPane

## Status

- Confidence: very strong for address, loader state, six-xref lifecycle/consumer inventory, external linkage, semantic/file ownership, source order, and one-definition/one-extern topology; exact original lexical formatting remains inferred.
- Address: `0x0069b41c`
- Exact storage doc: [UID:0002XU][0x0069b41c-0x0069b420.g_pIconsPane](by-memory/0x0069b41c-0x0069b420.g_pIconsPane.md)
- Current IDA identity: `inspect_items` reports auto-name `unk_69B41C`; the persisted names table has literal `absent` at `0x0069b41c`, and an exact `g_pIconsPane` collision search returns zero.
- Historical aliases: `dword_69B41C`, `DAT_0069b41c`
- Kind: process-wide singleton pointer to [UID:00006B][IconsPane](by-class/IconsPane.md)
- Source type: `IconsPane *`, one native 32-bit pointer; pointer signedness is not applicable.
- Owner module: [UID:0000JZ][IconsPane](by-file/IconsPane.md), the sole source-file owner.
- Rebuild handling: source-declared module/global singleton pointer; exact address and binary initializer are rebuilt by the linker.
- Autogen parent: [UID:0000JZ][IconsPane](by-file/IconsPane.md). This page emits the sole namespace-scope external definition `IconsPane *g_pIconsPane = NULL;` at position `30`, followed by `[[CHILDREN]]`; physical storage child UID0002XU emits only its covered-by marker at child position `10`.
- Header route: [UID:00006B][IconsPane](by-class/IconsPane.md) owns the sole `extern IconsPane *g_pIconsPane;`; this global H channel remains blank to avoid a duplicate declaration.
- Evidence basis: IDA MCP xrefs/decompilation.

## Lifecycle

- Published at `0x004cf215` by direct `Singleton<IconsPane>` construction after complete-object adjustment. This is base/compiler lowering, not an authored `g_pIconsPane = this` statement.
- Cleared at `0x004cf27a` by reverse direct-Singleton lowering in the ordinary/non-deleting destructor range. The exact human `IconsPane::~IconsPane()` body is empty.
- Cleared again at `0x004cfdc0` inside the compiler scalar-deleting wrapper before inherited cleanup/free handling. UID00034V is comment-only support and must not emit a second destructor or global assignment.
- Read during old-asset exit-to-menu teardown at `0x00504a07` and queued at `0x00504a13`; that consumer neither owns nor explicitly clears the global.
- Read by the old OptionPane constructor at `0x0053da72`; it calls `IsShowingAllIcons` at `0x0053da83`, inverts the result through `setz`, and initializes control `6`.
- Read by the old OptionPane command path at `0x0053dec2`, which routes control `6` to `ShowAllIcons` or `ShowReducedIcons` and mirrors persisted state.
- B004 old `OptionPane` pass identifies those option UI reads as control id `6`: the constructor probes reduced/full icon state through `0x004cf290`, and the command handler applies show-all/reduced modes through `0x004cf2a0`/`0x004cf2d0` while mirroring persisted state through `g_pConfig+0x28de32`.

## Evidence Table

| Site | Use | Evidence owner |
| --- | --- | --- |
| `0x004cf215` | Direct `Singleton<IconsPane>` lowering publishes the adjusted complete object; no authored assignment. | [UID:0002SW][0x004cf1f0-0x004cf25d.IconsPaneConstructor](by-memory/0x004cf1f0-0x004cf25d.IconsPaneConstructor.md). |
| `0x004cf27a` | Reverse direct-base lowering clears the singleton; the ordinary human destructor body remains empty. | [UID:0002SX][0x004cf260-0x004cf289.IconsPaneCleanupHelper](by-memory/0x004cf260-0x004cf289.IconsPaneCleanupHelper.md). |
| `0x004cfdc0` | Compiler scalar-deleting wrapper repeats the clear before shared cleanup/delete handling; no second source body. | [UID:00034V][0x004cfda0-0x004cfdff.IconsPaneScalarDeletingDestructor](by-memory/0x004cfda0-0x004cfdff.IconsPaneScalarDeletingDestructor.md). |
| `0x00504a07` | Exit-to-menu teardown reads the pointer and queues it at `0x00504a13`, without ownership or explicit clear. | [UID:0002QH][0x005047f0-0x00504b6b.MapPaneExitToMenuTeardown](by-memory/0x005047f0-0x00504b6b.MapPaneExitToMenuTeardown.md). |
| `0x0053da72` | Constructor calls `IsShowingAllIcons` at `0x0053da83`, inverts with `setz`, and initializes control `6`. | [UID:00040F][0x0053d820-0x0053dd4f.OptionPaneConstructor](by-memory/0x0053d820-0x0053dd4f.OptionPaneConstructor.md). |
| `0x0053dec2` | Command route applies `ShowAllIcons`/`ShowReducedIcons` for control `6` and mirrors config state. | [UID:00040H][0x0053ddb0-0x0053e191.OptionPaneOnOptionCommand](by-memory/0x0053ddb0-0x0053e191.OptionPaneOnOptionCommand.md). |

The exact storage bytes are `00 00 00 00`, SHA256 `DF3F619804A92FDB4057192DC43DD748EA778ADC52BC498CE80524C014B81119`. PE RVA `0x29b41c` lies beyond `.data` raw size `0xd800` but within virtual size `0x2fe24`, so the loader supplies zero and `= NULL` is source-faithful. The head has inbound code `0/{}`, inbound data `6/{0x4cf215,0x4cf27a,0x4cfdc0,0x504a07,0x53da72,0x53dec2}`, and outbound `0/{}`; the three interior bytes have no xrefs.

The 2026-06-16 C001 session and its saved-name statements remain dated evidence. The bounded 2026-08-17 readback supersedes current-name prose with inspect auto `unk_69B41C` and persisted name literal absent; it does not change the source-facing `g_pIconsPane` inference.

## Ownership Notes

This global is the singleton for the old-layout icon strip. It should be owned by `IconsPane.cpp`, not by [UID:0000OF][TabPane](by-file/TabPane.md), even though the two classes are adjacent and their destructor thunks are interleaved.

Keep the singleton with `IconsPane.cpp` rather than `OptionPane.cpp` or main UI graph ownership. Those modules read or remove the pane; constructor/cleanup/destructor code owns the storage lifetime.

The nonduplicating source order is class UID00006B at `10`, this semantic global at `30`, then physical child UID0002XU at `10` under this global. The class CPP contributes only a topology comment; exact method children retain all human method definitions.

## Data Caveats

The main UI shutdown and option UI consumers sit outside the `IconsPane` lifecycle island, so they are evidence rather than owners. Reject file-local `static`, class-static storage, raw-address aliases, a duplicate physical definition, modern `nullptr`, and manual lifecycle assignments. The direct `Singleton<IconsPane>`/EBO model also means IDA should retain its safe `Pane *` approximation until a separately accepted base-aware UDT exists.

## Cross-References

- [UID:00006B][IconsPane](by-class/IconsPane.md)
- [UID:0000JZ][IconsPane](by-file/IconsPane.md)
- [UID:00016Z][0x004cf1f0-0x004cf8d5.IconsPaneCore](by-memory/0x004cf1f0-0x004cf8d5.IconsPaneCore.md)
- [UID:0002XU][0x0069b41c-0x0069b420.g_pIconsPane](by-memory/0x0069b41c-0x0069b420.g_pIconsPane.md)
- [UID:000170][0x004cf980-0x004cfe5f.TabPaneAndIconsPaneDestructorTail](by-memory/0x004cf980-0x004cfe5f.TabPaneAndIconsPaneDestructorTail.md)
- [UID:0000R4][g_pHourPane](by-global/g_pHourPane.md)

## Changes

- 2026-08-17 B002 UID0002XU accepted ordinary implementation callback:
  - Raised completion/confidence from `88/89` to `92/94`, preserved owner/emitter UID0000JZ and reconstructable true, and set emitter position `30`.
  - Added the sole external definition `IconsPane *g_pIconsPane = NULL;` followed by `[[CHILDREN]]`; kept formal H blank because UID00006B owns the sole extern.
  - Added exact loader-zero/hash, current inspect-versus-persisted IDA identity, six-xref lifecycle/consumer evidence, class/global/physical source order, ownership, type/linkage, and rejected alternatives.
  - Corrected current lifecycle prose to empty human destructor plus direct-Singleton/compiler publication and clearing while retaining prior explicit-clear drafts below as dated superseded history.

- 2026-07-04 B014 UID0002SX destructor source-route sync, dated and superseded for authored-body content:
  - No score change; global owner/emitter remains [UID:0000JZ][IconsPane](by-file/IconsPane.md).
  - Historical summary/evidence: that callback routed a source-visible `g_pIconsPane = NULL;` statement through [UID:0002SX][0x004cf260-0x004cf289.IconsPaneCleanupHelper](by-memory/0x004cf260-0x004cf289.IconsPaneCleanupHelper.md) and kept the scalar wrapper comment-only. Later direct-Singleton/EBO causality and complete instruction accounting superseded the authored statement: current UID0002SX emits an empty human destructor, while both binary clears remain compiler/direct-base lifecycle evidence.
- 2026-06-06 A010 singleton evidence consolidation:
  - Before: `COMPLETION:82`, `CONFIDENCE:78`, with lifecycle bullets but no explicit rebuild handling, likely pointer type, source-gate note, or evidence table.
  - Changed to: `COMPLETION:86`, `CONFIDENCE:86`, source-declared singleton handling, likely `IconsPane*` type, final declaration caveat, lifecycle/user evidence table, and clearer owner separation from `TabPane`, `OptionPane`, and main UI shutdown.
  - Summary/evidence: existing IDA-backed docs record constructor store at `0x004cf215`, cleanup/destructor clears at `0x004cf260` and `0x004cfda0`, shutdown read at `0x00504a07`, and option UI reads at `0x0053da72` and `0x0053dec2`; the by-file page owns the old-layout icon strip under `NexusTK/ui/panels/`.
- 2026-05-30: Changed completion/confidence from `0/0` to `82/78`.
  - Before: The page had strong lifecycle/address notes but was unscored and still described active output as omitting helper functions that clear the singleton.
  - After: The page records that constructor, cleanup helper, and scalar deleting destructor singleton writes/clears are known, while consumer paths remain outside this file.
  - Evidence: IDA notes record writes/clears at `0x004cf1f0`, `0x004cf260`, and `0x004cfda0`, plus reads from main UI shutdown and option UI paths.
- 2026-06-05: Marked reconstructable under [UID:0000JZ][IconsPane](by-file/IconsPane.md). Evidence: live IDA MCP reports six xrefs to `0x0069b41c`; decompilation confirms constructor `0x004cf1f0`, cleanup helper `0x004cf260`, and scalar deleting destructor `0x004cfda0` write/clear `dword_69B41C`.
- 2026-06-07 A007 Batch 041 split-link update: added the exact by-memory storage doc [UID:0002XU][0x0069b41c-0x0069b420.g_pIconsPane](by-memory/0x0069b41c-0x0069b420.g_pIconsPane.md) after the mixed Hour/Icons singleton range was split into separate `HourPane` and `IconsPane` slots.
- 2026-06-16 C001 Goal 2 global/IDA refresh (dated and superseded): raised `86/86` to `88/89` after live IDA reconfirmed storage bytes, xrefs, lifecycle writers/clears, option consumers, owner route through [UID:0000JZ][IconsPane](by-file/IconsPane.md), and saved the singleton plus lifecycle function names in the IDB. That dated pass added no final C++ because it treated the raw action-dispatch candidate and exact source grouping with [UID:0000OF][TabPane](by-file/TabPane.md) as unresolved; the 2026-08-17 callback above closes that source-placement question with the semantic global definition and physical covered-by child.
- 2026-06-20 B004 old OptionPane support sync: no score change; documented control-id-6 constructor/command-handler semantics and retained `OptionPane` as a consumer rather than owner.
