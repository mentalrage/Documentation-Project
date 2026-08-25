*** UID:0000SE | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000OF | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000OF | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// Emitted definition for this global storage is covered by [UID:00029C][0x0069adfc-0x0069ae00.g_pTabPane](by-memory/0x0069adfc-0x0069ae00.g_pTabPane.md).
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# g_pTabPane

## Status

- Confidence: very strong for address, zero-filled storage, exact lifecycle/users, class/file owner, and one-definition output route.
- Address: `0x0069adfc`
- Source-facing name/type: `TabPane *g_pTabPane`.
- Historical/raw aliases: `unk_69ADFC`, `dword_69ADFC`, and `DAT_0069adfc`; recovered database `6b2e78f3` has no explicit names/globals row in the singleton window.
- Kind: process-wide singleton pointer to [UID:0000EB][TabPane](by-class/TabPane.md)
- Owner/emitter module: [UID:0000OF][TabPane](by-file/TabPane.md), `NexusTK/ui/panels/TabPane.cpp`.
- Exact definition carrier: [UID:00029C][0x0069adfc-0x0069ae00.g_pTabPane](by-memory/0x0069adfc-0x0069ae00.g_pTabPane.md), which emits `TabPane *g_pTabPane;`.
- Declaration carrier: [UID:0000EB][TabPane](by-class/TabPane.md), which retains the sole `extern TabPane *g_pTabPane;`.
- Formal disposition: covered-by marker only, preventing a duplicate storage definition while keeping this alias/lifecycle page non-empty.
- Evidence basis: live IDA MCP bytes/xrefs/instruction contexts, exact PE virtual-tail analysis, current class/file routes, and generated output.

## Storage And Initialization

- Exact storage is one dword at `0x0069adfc-0x0069ae00` in the writable `.data` virtual tail.
- PE imagebase is `0x00400000`; target RVA is `0x0029adfc`. `.data` starts at RVA `0x0026d000`, raw bytes end at `0x0027a800`, and virtual extent ends at `0x0029ce24`; the target is `0x205fc` bytes beyond the raw end.
- Recovered MCP database `6b2e78f3` returned a zero-filled 32-byte singleton window at `0x0069adf0`, matching the earlier healthy `9df6e9a0` evidence. There is no file-backed `0xffffffff` initializer.
- Static-storage zero initialization is naturally reconstructed by the exact storage definition `TabPane *g_pTabPane;`. `= NULL` or `= 0` would be behaviorally equivalent but are weaker lexical alternatives; `nullptr` is rejected as era-inconsistent.
- The old 2026-05-28 `py_eval` `0xffffffff` observation is historical/superseded provenance. Its evaluated expression/result details were not preserved and it does not represent current PE or IDB bytes.

## Lifecycle

Live `xref_query` on recovered database `6b2e78f3` reconfirmed exactly five refs:

| Site | Function | Role |
| --- | --- | --- |
| `0x0049e5e6` | `sub_49E240`, size `0x476` | `DialogPane::OnInputEvent` consumer: loads TabPane, obtains bounds, translates coordinates, hit-tests, and forwards to the pane facet. |
| `0x004cf9a4` | `sub_4CF980`, size `0x4a` | [UID:00034L][0x004cf980-0x004cf9ca.TabPaneConstructor](by-memory/0x004cf980-0x004cf9ca.TabPaneConstructor.md) publishes `g_pTabPane = this;`. |
| `0x004cf9ea` | `sub_4CF9D0`, size `0x29` | [UID:00034M][0x004cf9d0-0x004cf9f9.TabPaneCleanupHelper](by-memory/0x004cf9d0-0x004cf9f9.TabPaneCleanupHelper.md) is the single source-visible ordinary destructor clear. |
| `0x004cfe20` | `sub_4CFE00`, size `0x5f` | [UID:00034W][0x004cfe00-0x004cfe5f.TabPaneScalarDeletingDestructor](by-memory/0x004cfe00-0x004cfe5f.TabPaneScalarDeletingDestructor.md) repeats the clear as compiler scalar-wrapper glue and emits no duplicate destructor/global source. |
| `0x00504936` | `sub_5047F0`, size `0x37b` | [UID:0002QH][0x005047f0-0x00504b6b.MapPaneExitToMenuTeardown](by-memory/0x005047f0-0x00504b6b.MapPaneExitToMenuTeardown.md) checks and removes the pane from the layer. |

Exact target VA pattern `FC AD 69 00` occurs only at these five instruction operands; target RVA pattern `FC AD 29 00` has zero hits. There is no sixth xref, hidden pointer table, dynamic initializer, or alternate storage route.

The ordinary/scalar decomposition is deliberate: source C++ contains one `TabPane::~TabPane()` singleton clear, while the compiler regenerates scalar wrapper behavior. Consumers read/remove the object but do not own its storage.

## Ownership Notes

This global tracks the active `TabPane` instance. The exact by-memory page directly emits the definition through the existing TabPane file root; this by-global page owns symbol meaning, lifetime, users, and source placement only. The class page supplies the extern, so all three documentation layers have non-overlapping source responsibilities.

The direct lifecycle rejects DialogPane, MapPane, generic UI-global, and [UID:0000JZ][IconsPane](by-file/IconsPane.md) ownership. Those modules are consumers or physical neighbors. `IconsPane` has its own distinct singleton/vtable lifecycle.

Adjacent boundaries are exact: predecessor [UID:0001PB][0x0069adf8-0x0069adfc.g_pDescPane](by-memory/0x0069adf8-0x0069adfc.g_pDescPane.md) has four refs, this slot has five, and successor [UID:0001PC][0x0069ae00-0x0069ae04.g_pSimpleHelpPane](by-memory/0x0069ae00-0x0069ae04.g_pSimpleHelpPane.md) has 23. No merge, split, array, or padding interpretation is supported.

## Assignment Gate

The global remains owner/emitter-qualified under [UID:0000OF][TabPane](by-file/TabPane.md), now `92/93`; this page is `90/92`. Exact storage page UID00029C is independently source-ready at `92/93` and directly emits through the same file root. This removes the obsolete transitive `86/85` gate narrative.

Blank optional position remains correct. The class declaration and sole extern already precede generated methods; UID00029C may define the symbol later at namespace scope without a new forward declaration.

## Data Caveats

Generated/recovered views can expose compiler scalar cleanup as a second binary clear. Preserve it as lifecycle evidence, not authored source. Do not handwrite vptr stores, wrapper flags, base-destructor calls, vtable/RTTI arrays, raw addresses, or a second global definition.

## Score Rationale

- Completion `90`: exact storage/definition carrier, PE zero fill, all five refs and roles, source/compiler destructor split, event/teardown consumers, type/name/linkage, one-definition marker route, boundaries, negatives, and historical correction are present.
- Confidence `92`: exact binary and accepted source routes agree. The remaining cap is absence of an original IDA/debug symbol and token-level uncertainty over omitted versus explicit zero initializer.

## Cross-References

- [UID:0000EB][TabPane](by-class/TabPane.md)
- [UID:0000OF][TabPane](by-file/TabPane.md)
- [UID:000170][0x004cf980-0x004cfe5f.TabPaneAndIconsPaneDestructorTail](by-memory/0x004cf980-0x004cfe5f.TabPaneAndIconsPaneDestructorTail.md)
- [UID:0000JZ][IconsPane](by-file/IconsPane.md)
- [UID:00029C][0x0069adfc-0x0069ae00.g_pTabPane](by-memory/0x0069adfc-0x0069ae00.g_pTabPane.md)
- [UID:0001PB][0x0069adf8-0x0069adfc.g_pDescPane](by-memory/0x0069adf8-0x0069adfc.g_pDescPane.md)
- [UID:0001PC][0x0069ae00-0x0069ae04.g_pSimpleHelpPane](by-memory/0x0069ae00-0x0069ae04.g_pSimpleHelpPane.md)

## Changes

- 2026-07-14 B003 UID00029C implementation callback:
  - Before: `86/89`, owner/emitter UID0000OF, true, blank formal, stale raw-name/current-gate claims, and an Empty Emitter Marker beside UID00029C's marker.
  - Changed to: `90/92`, owner/emitter preserved, exact covered-by R2 marker, zero-fill/PE storage, recovered MCP database `6b2e78f3`, all five lifecycle/consumer refs, source/compiler destructor split, exact storage-definition/class-extern factorization, `4/5/23` boundaries, negative routes, and score rationale.
  - Historical preservation: old `dword_69ADFC` and `0xffffffff` statements remain search provenance only; current source name and storage value are evidence-backed.
- 2026-06-05: Marked reconstructable and attached to [UID:0000OF][TabPane](by-file/TabPane.md) to resolve the global unclassified coverage row.
  - Reasoning: live IDA xrefs bind the singleton to the `TabPane` constructor, cleanup helper, scalar deleting destructor, application/message read, and main UI shutdown read. No score change and no reconstruction C++ were added.
- What existed before: this page had the correct lifecycle outline but unevaluated completion/confidence metadata and an evidence-basis line that mixed source output with IDA checks.
- What changed to: the page now cites live IDA MCP evidence for storage shape and all five direct xrefs. Completion/confidence were set to `82/88`.
- Summary and evidence: IDA MCP on 2026-05-30 verified `0x0069adfc` / `dword_69ADFC` as a 4-byte `.data` singleton pointer with five xrefs: application/message read at `0x0049e5e6`, constructor assignment at `0x004cf9a4`, cleanup clear at `0x004cf9ea`, scalar deleting destructor clear at `0x004cfe20`, and main UI shutdown read at `0x00504936`.
- 2026-06-07 A008 Batch 037 parent-gate refresh:
  - Changed to: `COMPLETION:86`, `CONFIDENCE:89`.
  - Summary/evidence: added the exact storage child [UID:00029C][0x0069adfc-0x0069ae00.g_pTabPane](by-memory/0x0069adfc-0x0069ae00.g_pTabPane.md) and documented the corrected assignment gate. The direct file parent [UID:0000OF][TabPane](by-file/TabPane.md) now clears `85/85`, while this global's direct five-xref lifecycle evidence already distinguishes it from adjacent `IconsPane` and `SimpleHelpPane` storage.
