*** UID:0000ME | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:89 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/core/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:FILE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# PanelPane

## UID0000KA Activation Consumers - 2026-08-15

The common pure `OnActivate(const unsigned char *)` route now explicitly includes legacy `InventoryPane` (`0x0061c7a0 -> 0x004ea280`) and `InventoryPane2` (`0x0061c8b8 -> 0x004ee6d0`). Both ignore the packet and invalidate inherited embedded-pane bounds. Their definitions remain in `NexusTK/ui/inventory/InventoryPane.cpp`; this file owns only the PanelPane declaration/lifecycle contract. The old `InventoryPane2::RefreshEmbeddedPane` spelling is superseded history. File score and source ownership are unchanged.

## Status

- Confidence: very strong for source ownership, exact lifecycle source, direct `PanelPane : Pane` RTTI/layout, three-view compiler ABI, pure activation contract, broad feature-pane fan-in, and UI-core placement. Whether the original developers colocated this declaration with `Pane.cpp` remains a bounded historical question.
- Proposed module: `ui/core/PanelPane.cpp`
- Current recovered source: `class_PanelPane.cpp`
- Main address doc: [UID:0001EC][0x00545090-0x00545165.PanelPane](by-memory/0x00545090-0x00545165.PanelPane.md)
- Type docs: [UID:0001YD][PanelPaneVtables](by-type/by-vtable/PanelPaneVtables.md)
- Evidence basis: existing by-* docs plus IDA MCP lookup/xref/callee/raw-byte checks through 2026-06-16.

## Role

`PanelPane` is a reusable `Pane`-derived base for panel-style UI containers. It installs a three-vtable layout used by derived panels such as `NewOptionPane`, group panes, and other in-game panel surfaces. The source route remains `NexusTK/ui/core/PanelPane.cpp`; [UID:0001EC][0x00545090-0x00545165.PanelPane](by-memory/0x00545090-0x00545165.PanelPane.md) now emits `PanelPane::PanelPane() : Pane(1) {}` and empty `PanelPane::~PanelPane()` through that route after the target validator refresh.

Exact RTTI establishes a six-descriptor chain `PanelPane`, `Pane`, `GrafPort`, `LObject`, `EventHandler`, `TimerHandler`. PanelPane directly derives only from Pane; EventHandler and TimerHandler are inherited Pane facets at object offsets `+0xa0` and `+0xa4`. Pane and PanelPane are both `0xf8` bytes, so PanelPane adds no fields. Its source-level addition is the pure activation virtual at primary `+0x48`.

Derived panel families inherit primary `+0x48` as the common `virtual void OnActivate(const unsigned char *packetData)` contract. The base `PanelPane` table cell is `__purecall`; eight concrete implementations either consume packet data or ignore it while rebuilding/requesting state. The behavior-specific aliases remain documented on their feature owners. Inherited primary `+0x0c` is `UpdateRenderRegion(const RectBounds *)`, used by exact PaneCollapse support and distinct from `SetBounds` at `+0x2c`.

## Proposed Contents

| Structure | Address evidence | Role |
| --- | --- | --- |
| `PanelPane` | `0x00545090-0x00545165` | Source-ready base constructor and ordinary destructor, plus prose-only compiler scalar deleting destructor evidence. |
| vtable family | `0x00621a70`, `0x00621ac0`, `0x00621af0` | Three `PanelPane` vtable views installed at object offsets `+0x00`, `+0xa0`, and `+0xa4`. |
| inherited virtual contracts | primary `+0x0c`, `+0x48` | `UpdateRenderRegion(const RectBounds *)` and pure/common `OnActivate(const unsigned char *)`; exact derived matrix is retained in UID0001YD rather than emitted as file-level code. |
| adjustor thunk helpers | `0x005450ef`, `0x005450fa` | Tiny IDA-confirmed functions that forward into the deleting destructor island; compiler-generated and not handwritten source. |
| exact RTTI/vtable child | `0x00621a6c-0x00621af8` | Three COL records, 35 total dwords, inherited Pane/EventHandler/TimerHandler contracts, pure PanelPane activation cell, and exact Pane/EditablePaperPane fences. |

The source file must not contain literal vtable arrays, complete-object locators, RTTI descriptors, explicit vptr stores, the scalar deleting wrapper, or the two adjustor thunks. MSVC emits those from the class hierarchy and virtual declarations. UID0002OG and UID0001YD therefore use covered-by comments, while UID0001EC emits the ordinary human-written lifecycle methods.

## Observed Derived Constructor Callers

IDA MCP xref checks show `PanelPane::PanelPane` at `0x00545090` has direct constructor calls from these panel families. The current count is sixteen xrefs: thirteen modeled-function constructor callers plus three raw constructor/setup sites that are already documented as no-function constructor bodies in their own owner pages.

| Caller address | Current owner | Source-module implication |
| --- | --- | --- |
| `0x004ea15b` | `InventoryPane` | Item inventory panel family; keep in [UID:0000KA][InventoryPane](by-file/InventoryPane.md). |
| `0x004eb44b` | `NewInventoryPane` | New item inventory panel; keep in [UID:0000LS][NewInventoryPane](by-file/NewInventoryPane.md). |
| `0x0053ffbd` | `NewOptionPane` | Options UI panel; keep in [UID:0000M7][OptionPane](by-file/OptionPane.md). |
| `0x0056563b` | `SelfLookPane` | Self-look/status panel; keep in [UID:0000NL][SelfLookPane](by-file/SelfLookPane.md). |
| `0x0056c4ec`, `0x0056c79c`, `0x0056ca4b` | `GroupPane`, `GroupPane2`, `NewGroupPane` | Group/social panel family; keep in [UID:0000JS][Group](by-file/Group.md). |
| `0x0056e96b` | `CollectionPane` | Collection UI; keep in [UID:0000IC][CollectionPane](by-file/CollectionPane.md). |
| `0x0056fd7a` | raw `CollectionPane2` constructor | Alternate collection frame raw constructor; keep in [UID:0000IC][CollectionPane](by-file/CollectionPane.md) through [UID:0001HG][0x0056fd70-0x0056fda0.CollectionPane2RawConstructor](by-memory/0x0056fd70-0x0056fda0.CollectionPane2RawConstructor.md). |
| `0x0056feab` | `SelfLookPane2` | Compact self-look panel; keep in [UID:0000NL][SelfLookPane](by-file/SelfLookPane.md). |
| `0x0057c2fb` | `SpellInventoryPane` | Spell inventory panel; keep in [UID:0000O1][SpellInventoryPane](by-file/SpellInventoryPane.md). |
| `0x0057cf9b` | `NewSpellInventoryPane` | New spell inventory panel; keep in [UID:0000LU][NewSpellInventoryPane](by-file/NewSpellInventoryPane.md). |
| `0x0057ea6a` | raw `SpellInventoryPane2` constructor | Alternate spell-inventory raw constructor/setup body; keep in [UID:0000O1][SpellInventoryPane](by-file/SpellInventoryPane.md) through [UID:0002RK][0x0057ea60-0x0057f58b.SpellInventoryPane2CoreAndHelpers](by-memory/0x0057ea60-0x0057f58b.SpellInventoryPane2CoreAndHelpers.md). |
| `0x0058859c` | `NewSystemMessagePane` | New system-message panel wrapper; keep in [UID:0000OE][SystemMessagePanes](by-file/SystemMessagePanes.md). |
| `0x0059f28c` | `UserLookPane` | Remote user-look/profile panel; keep in [UID:0000P0][UserLookPane](by-file/UserLookPane.md). |

The third raw constructor xref is `0x004ee65a` inside [UID:00031V][0x004ee650-0x004ee6a7.InventoryPane2RawConstructor](by-memory/0x004ee650-0x004ee6a7.InventoryPane2RawConstructor.md). It is kept under [UID:0000KA][InventoryPane](by-file/InventoryPane.md), not treated as a modeled `PanelPane` caller.

This fan-in supports `PanelPane` as a core UI base class, not a feature-owned helper.

## Boundaries

- Keep `PanelPane` near `Pane`, `DialogPane`, and `ControlPane` under `ui/core`.
- Keep feature panels such as [UID:0000JQ][GeneralPurposePanel](by-file/GeneralPurposePanel.md), [UID:0000M7][OptionPane](by-file/OptionPane.md), group panes, and status panes in their feature modules.

## Caveats And Historical Corrections

Historical generated output labeled the teardown path `TextButtonExControlPane::~TextButtonExControlPane`, even though exact disassembly flows through Pane construction/teardown. That generated owner label is superseded and retained only as history; it is not a current source-owner or score blocker.

Historical disabled output listed `0x005450ef` as missing code, but current IDA recognizes it as an `0xb`-byte compiler adjustor with vtable data xref at `0x00621ac0`. See [UID:0001ED][0x005450ef-0x00545105.PanelPaneAdjustorThunks](by-memory/0x005450ef-0x00545105.PanelPaneAdjustorThunks.md).

The old teardown/thunk issues do not block confidence: [UID:0001YD][PanelPaneVtables](by-type/by-vtable/PanelPaneVtables.md) records the full 35-dword map, six-base RTTI, lifecycle stores, compiler/source identities, and exact tertiary boundary; [UID:0001ED][0x005450ef-0x00545105.PanelPaneAdjustorThunks](by-memory/0x005450ef-0x00545105.PanelPaneAdjustorThunks.md) records both adjustors as compiler-generated ABI glue. The remaining standalone `PanelPane.cpp` versus adjacent `Pane.cpp` uncertainty is bounded historical colocation uncertainty, not an unresolved source split or code blocker.

## Source Route And Confidence

- Current project route: `NexusTK/ui/core/PanelPane.cpp`, owner UID0000ME, class UID0000A4.
- Human source: UID0001EC constructor/destructor plus the PanelPane declaration contract; derived overrides stay in their feature modules.
- Compiler-generated support: UID0002OG vtable/RTTI bytes, UID0001ED adjustors, and the scalar deleting wrapper inside UID0001EC's aggregate range.
- Completion `89` and confidence `92` reflect complete target-family routing and compiler policy without claiming proof of the exact original physical file colocation or a complete emitted Pane/PanelPane header pair.

## 2026-06-11 Parent-Gate Refresh

Live IDA MCP reconfirms the file's direct `PanelPane` ownership rather than feature-module ownership:

- `lookup_funcs` confirms constructor `0x00545090-0x005450c2`, non-deleting destructor `0x005450d0-0x005450ef`, adjustor thunks `0x005450ef-0x005450fa` and `0x005450fa-0x00545105`, scalar deleting destructor `0x00545110-0x00545165`, base `Pane` teardown at `0x00544580`, and successor `EditablePaperPane` constructor at `0x00545170`.
- `xrefs_to 0x00545090` reports sixteen constructor xrefs across inventory, option, self-look, group, collection, spell inventory, system-message, and user-look panes. Thirteen are ordinary modeled-function callers; `0x004ee65a`, `0x0056fd7a`, and `0x0057ea6a` are raw/no-function constructor bodies for `InventoryPane2`, `CollectionPane2`, and `SpellInventoryPane2` respectively. This keeps the file as a reusable UI-core base rather than any one feature pane's private helper.
- `callers 0x005450d0` reports cleanup/destructor callers across the same derived panel families, while `callers 0x00545110` reports no ordinary direct callers because the scalar deleting destructor is vtable/thunk-dispatched.
- Disassembly confirms constructor stores all three `PanelPane` vtable views at object offsets `+0x00`, `+0xa0`, and `+0xa4`; the non-deleting destructor restores those views then tail-jumps to `Pane` teardown; the scalar deleting destructor restores them, calls `Pane` teardown, then uses the delete flag for normal free versus vector-delete guard handling.
- `xrefs_to` confirms the complete table-store triads for `0x00621a70`, `0x00621ac0`, and `0x00621af0` from constructor, non-deleting destructor, and scalar deleting destructor.

## 2026-06-16 Source-Quality Refresh

Live IDA MCP on database `c001_midiplayer_rdata_20260615` reconfirmed the constructor `0x00545090`, non-deleting destructor `0x005450d0`, adjustor thunks `0x005450ef`/`0x005450fa`, scalar deleting destructor `0x00545110`, base `Pane` constructor/teardown at `0x00544460`/`0x00544580`, and successor `EditablePaperPane` constructor at `0x00545170`. `xrefs_to` reconfirmed the three table-store refs for each vtable base, plus vtable/thunk-only dispatch to the scalar deleting destructor. Bytes at `0x00545086-0x00545090` and `0x00545165-0x00545170` are `0xcc` alignment. The original file grouping (`PanelPane.cpp` standalone versus adjacent `Pane.cpp`) remains unresolved only as an exact-original-source caveat; current generated output should use this route for UID0001EC's two method definitions.

## Cross References

- [UID:0000A4][PanelPane](by-class/PanelPane.md)
- [UID:0001YD][PanelPaneVtables](by-type/by-vtable/PanelPaneVtables.md)
- [UID:0001ED][0x005450ef-0x00545105.PanelPaneAdjustorThunks](by-memory/0x005450ef-0x00545105.PanelPaneAdjustorThunks.md)
- [UID:0000MC][Pane](by-file/Pane.md)
- [UID:0000JQ][GeneralPurposePanel](by-file/GeneralPurposePanel.md)
- [UID:0000KA][InventoryPane](by-file/InventoryPane.md)
- [UID:0000M7][OptionPane](by-file/OptionPane.md)
- [UID:0000JS][Group](by-file/Group.md)
- [UID:0000IC][CollectionPane](by-file/CollectionPane.md)
- [UID:0000NL][SelfLookPane](by-file/SelfLookPane.md)
- [UID:0000O1][SpellInventoryPane](by-file/SpellInventoryPane.md)
- [UID:0000OE][SystemMessagePanes](by-file/SystemMessagePanes.md)
- [UID:0000P0][UserLookPane](by-file/UserLookPane.md)
- [UID:0001EC][0x00545090-0x00545165.PanelPane](by-memory/0x00545090-0x00545165.PanelPane.md)

## Changes

- 2026-07-29 B002 UID0002OG accepted implementation callback:
  - Raised `86/88 -> 89/92`; retained `NexusTK/ui/core/`, file ownership, and the UID0000A4/UID0001EC route.
  - Incorporated direct `PanelPane : Pane` RTTI inheritance, inherited EventHandler/TimerHandler facets, no-new-field `0xf8` layout, exact 35-dword vtable child, pure activation extension, and the compiler-causal no-literal-vtable source policy.
  - Historicalized broad source-split, missing-thunk, and `TextButtonExControlPane` owner-pollution blockers. Only exact original file colocation remains inferential, and it no longer suppresses source emission or ownership confidence.

- 2026-07-13 B004 UID00015Y accepted callback: scores remain `86/88`; synchronized the inherited `UpdateRenderRegion` and pointer-valued `OnActivate` contracts and their source route, while preserving all constructor/destructor/vtable/thunk/compiler evidence and leaving the file-level formal class surface blank.
- 2026-06-05 projected-path assignment:
  - What existed before: `PROPOSED_RECONSTRUCTION_PATH` was blank, so the by-file row remained a generated-root coverage error.
  - Changed to: `NexusTK/ui/core/`.
  - Summary/evidence: live IDA MCP lookup confirms the documented `PanelPane` constructor anchor at `0x00545090`; proposed-source-tree treats `PanelPane.cpp` as a reusable UI-core base for multiple panel families, not as a feature-panel child file.
- Before: the `PanelPane` memory page ended at `0x00545164`.
- Changed to: the page ends at `0x00545165`.
- Summary/evidence: 2026-05-28 IDA MCP byte/function review shows `0x00545164` is the final operand byte of the `retn 4` in the scalar deleting destructor; `0x00545165-0x00545170` is alignment padding.

- Before: completion/confidence were ungraded at `0/0`.
- Changed to: completion `84`, confidence `78`.
- Summary/evidence: the page documents base behavior, vtable family, derived constructor callers, boundaries, generated destructor caveat, range correction, and cross-references; confidence remains capped by uncertainty over standalone file versus `Pane.cpp` grouping.
- 2026-06-06: Raised confidence to `84`.
  - Summary/evidence: [UID:0001YD][PanelPaneVtables](by-type/by-vtable/PanelPaneVtables.md) now records exact vtable-data dwords, constructor/destructor stores to all three vtable views, the direct `Pane` teardown target, and the `0x00621af8` neighboring RTTI boundary; [UID:0001ED][0x005450ef-0x00545105.PanelPaneAdjustorThunks](by-memory/0x005450ef-0x00545105.PanelPaneAdjustorThunks.md) classifies the missing generated body as compiler-generated adjustor glue. The page remains below final-source confidence because original file split versus `Pane.cpp` grouping is still open.
- 2026-06-11 A006 parent-gate refresh:
  - Before: `84/84`, below the strict parent-side gate for the `PanelPane` class and vtable family.
  - After: `85/86`.
  - Summary/evidence: live IDA MCP reconfirmed constructor/destructor/scalar-deleting destructor bounds, thirteen constructor callers, broad destructor cleanup callers, no ordinary direct scalar-destructor callers, complete constructor/destructor vtable-store triads, direct `Pane` teardown, vector-delete guard/free behavior, and the exact `PanelPane` vtable-data boundary before `EditablePaperPane`. The remaining standalone-file-versus-`Pane.cpp` split caveat is documented but no longer blocks this file as the direct UI-core owner.
- 2026-06-16 A002 source-quality refresh:
  - Before: `85/86`.
  - After: `86/88`.
  - Summary/evidence: live IDA MCP reconfirmed function/thunk boundaries, table-store triads, scalar-destructor thunk/vtable dispatch, `Pane` constructor/teardown edges, and alignment bytes, and expanded the constructor fan-in evidence from thirteen modeled callers to sixteen total xrefs by accounting for raw `InventoryPane2`, `CollectionPane2`, and `SpellInventoryPane2` constructor bodies. Owner/emitter remain this UI-core file; at that time generated C++ was still blank pending inherited slot names and original `PanelPane.cpp` versus `Pane.cpp` source grouping, but the 2026-07-06 B002 callback now emits UID0001EC method bodies through this route.
- 2026-07-06 B002 support sync:
  - Metadata remains unchanged.
  - Summary/evidence: accepted UID0001EC callback keeps the source route at `NexusTK/ui/core/PanelPane.cpp` and replaces the target's empty generated marker with the source-ready constructor/destructor first draft after scoped validation. Vptr stores, adjustor thunks, scalar deleting wrapper, and vtable data remain compiler output/declaration evidence rather than handwritten file-level source.
