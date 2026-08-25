** TARGET-REPORT-UID:00016V **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 00016V ItemHelpPaneCore Source-Quality Research

## Final Recommendation

Split [UID:00016V][0x004c82d0-0x004ce160.ItemHelpPaneCore](../../../../../by-memory/0x004c82d0-0x004ce160.ItemHelpPaneCore.md) into exact method/data child pages, then reclassify `00016V` as a reviewed non-emitting ItemHelpPane migration index.

Recommended child pages:

| Range | Page name | Direct owner/emitter | Disposition |
| --- | --- | --- | --- |
| `0x004c82d0-0x004c8b13` | `ItemHelpPaneConstructor` | [UID:00006U][ItemHelpPane](../../../../../by-class/ItemHelpPane.md) | `RECONSTRUCTABLE:TRUE`, blank final C++ |
| `0x004c8b20-0x004c8bc2` | `ItemHelpPaneNonDeletingDestructor` | [UID:00006U][ItemHelpPane](../../../../../by-class/ItemHelpPane.md) | `RECONSTRUCTABLE:TRUE`, blank final C++ |
| `0x004c8bd0-0x004ccba0` | `ItemHelpPaneOnPaintFrame` | [UID:00006U][ItemHelpPane](../../../../../by-class/ItemHelpPane.md) | `RECONSTRUCTABLE:TRUE`, blank final C++ |
| `0x004ccba0-0x004ccc1c` | `ItemHelpPaneOnPaintFrameJumpTables` | [UID:00006U][ItemHelpPane](../../../../../by-class/ItemHelpPane.md) | `RECONSTRUCTABLE:FALSE`, blank emitters/C++ |
| `0x004ccc20-0x004ccc3a` | `ItemHelpPaneOnTimerEvent` | [UID:00006U][ItemHelpPane](../../../../../by-class/ItemHelpPane.md) | `RECONSTRUCTABLE:TRUE`, blank final C++ |
| `0x004ccc40-0x004ccc7e` | `ItemHelpPaneOnMouseEvent` | [UID:00006U][ItemHelpPane](../../../../../by-class/ItemHelpPane.md) | `RECONSTRUCTABLE:TRUE`, blank final C++ |
| `0x004ccc80-0x004ccc95` | `ItemHelpPaneDismissItemHelp` | [UID:00006U][ItemHelpPane](../../../../../by-class/ItemHelpPane.md) | `RECONSTRUCTABLE:TRUE`, blank final C++ |
| `0x004ccca0-0x004ce0f6` | `ItemHelpPanePopulateItemData` | [UID:00006U][ItemHelpPane](../../../../../by-class/ItemHelpPane.md) | `RECONSTRUCTABLE:TRUE`, blank final C++ |
| `0x004ce100-0x004ce160` | `ItemHelpPaneCountTextLines` | [UID:00006U][ItemHelpPane](../../../../../by-class/ItemHelpPane.md) | `RECONSTRUCTABLE:TRUE`, blank final C++ |

After the child pages exist, change `00016V` to `COMPLETION:86`, `CONFIDENCE:90`, `CANONICAL_OWNER:00006U`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, and blank final C++. The broad page will remain useful as a source-quality migration index for the ItemHelpPane executable cluster, but it should not emit source once exact children carry the actual method bodies and switch-table evidence.

Do not move the class/file route from [UID:0000JU][HelpPanes](../../../../../by-file/HelpPanes.md) to a new `ItemHelpPane.cpp` in this pass. Current evidence supports `ItemHelpPane` as the direct class owner and `HelpPanes.cpp` as the conservative source-family emitter. A later source-layout pass can move the class emitter if real compilation-unit evidence appears.

No final C++ and no IDA DB edit are recommended.

## Current State Checked

- Assignment: `B001-goal2-memory-tool-item-help-pane-core-source-quality-00016V-20260616`.
- Target before this report: `COMPLETION:82`, `CONFIDENCE:88`, `CANONICAL_OWNER:0000JU`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000JU`, blank final C++.
- Generated memory route: `auto-generated/-ag-memory-coverage.md` emits `00016V` through `0000JU` to `auto-generated/NexusTK/ui/controls/HelpPanes.cpp`; the staged `HelpPanes.cpp` currently contains no source because the routed pages have blank C++.
- Support state:
  - [UID:00006U][ItemHelpPane](../../../../../by-class/ItemHelpPane.md) is `86/86`, reconstructable, owner/emitter [UID:0000JU][HelpPanes](../../../../../by-file/HelpPanes.md).
  - [UID:0000JU][HelpPanes](../../../../../by-file/HelpPanes.md) is `90/86` and already records the possible future `ItemHelpPane.cpp` split.
  - [UID:0001PD][g_pItemHelpPane storage](../../../../../by-memory/0x0069ae04-0x0069ae08.g_pItemHelpPane.md) is `86/90`.
  - [UID:00025G][HelpItemHelpReadOnlyData](../../../../../by-memory/0x0061aad4-0x0061b340.HelpItemHelpReadOnlyData.md) is `88/91`.

B001 did not directly edit by-* docs, generated reports, IDA DB, or `by-memory/-coverage-report.md`.

## Evidence Checked

### Documentation and Source Layout

`HelpPanes.md` and `proposed-source-tree.md` both place the `0x004c65a0-0x004ce34b` tooltip/help family under `ui/controls/HelpPanes.cpp`, with a written caveat that `ItemHelpPane` may later deserve a dedicated `ItemHelpPane.cpp`.

The current evidence favors a HelpPanes source-family route:

- The executable order is a contiguous tooltip/help sequence: `HelpPane`, `SimpleHelpPane`, `SimpleHelpPane2`, `WillBeChanged*Pane`, `ItemHelpPane`, support helpers, then destructor thunks.
- `HelpItemHelpReadOnlyData` groups `ItemHelpPane` vtables/literals with HelpPane/SimpleHelpPane/WillBeChanged vtables before the `HierList` successor.
- The `g_pItemHelpPane` singleton sits with the help/tooltip singleton model and close/clear helper family.
- No source path, PDB, linker map, or compilation-unit string evidence was found in current docs or live IDA output to prove a separate original `ItemHelpPane.cpp`.

The generated `source-3/simroot_v2/class_ItemHelpPane.cpp` was reviewed only as a lead source. It sketches the right method roles but is not final-source quality: it includes synthetic lambdas, invented local helper names, unstable field names, `reinterpret_cast` scaffolding, and known polluted base-owner labels such as `TextButtonExControlPane::~Pane`.

### Live IDA MCP

Active session:

- Session: `c001_midiplayer_rdata_20260615`.
- Input: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`.
- Hex-Rays ready: true.

`entity_query(kind=functions)` over `0x004c82d0-0x004ce160` confirms the exact modeled functions:

| Address | IDA name | Size | End |
| --- | --- | ---: | --- |
| `0x004c82d0` | `sub_4C82D0` | `0x843` | `0x004c8b13` |
| `0x004c8b20` | `??1exception@boost@@MAE@XZ_2` | `0xa2` | `0x004c8bc2` |
| `0x004c8bd0` | `sub_4C8BD0` | `0x3fd0` | `0x004ccba0` |
| `0x004ccc20` | `sub_4CCC20` | `0x1a` | `0x004ccc3a` |
| `0x004ccc40` | `sub_4CCC40` | `0x3e` | `0x004ccc7e` |
| `0x004ccc80` | `sub_4CCC80` | `0x15` | `0x004ccc95` |
| `0x004ccca0` | `sub_4CCCA0` | `0x1456` | `0x004ce0f6` |
| `0x004ce100` | `sub_4CE100` | `0x60` | `0x004ce160` |

IDA also reports `0x004ccba0` as non-function `jpt_4CB035`, with additional jump-table labels at `0x004ccbb8`, `0x004ccbcc`, `0x004ccbe0`, `0x004ccbf4`, and `0x004ccc08`.

Inter-function gaps checked with `get_bytes` are compiler alignment:

| Gap | Evidence |
| --- | --- |
| `0x004c8b13-0x004c8b20` | `0xc2 20 00` return at `0x004c8b10-0x004c8b12`, then 13 `0xcc` bytes |
| `0x004c8bc2-0x004c8bd0` | `0x5d 0xc3`, then 14 `0xcc` bytes |
| `0x004ccc1c-0x004ccc20` | `0xcccccccc` after the 31 jump-table dwords |
| `0x004ccc3a-0x004ccc40` | 6 `0xcc` bytes |
| `0x004ccc7e-0x004ccc80` | 2 `0xcc` bytes |
| `0x004ccc95-0x004ccca0` | 11 `0xcc` bytes |
| `0x004ce0f6-0x004ce100` | 10 `0xcc` bytes |
| `0x004ce160` | first byte of the successor helper `sub_4CE160`; no gap after `CountTextLines` |

Constructor and singleton reachability:

- `xrefs_to 0x004c82d0` reports exactly four constructor callers: `0x004ed957` inside `NewInventoryPane` mouse/input, `0x0051b383` inside `ServerItemMenuItemList`, `0x0051f7e3` inside `ArgumentedMenuMenuItemList`, and `0x00568e84` inside `SelfLookPane`.
- `xrefs_to 0x0069ae04` reports 20 singleton refs, including constructor publish/fallback clear at `0x004c832e` and `0x004c8335`, non-deleting destructor clear at `0x004c8ba1`, `DismissItemHelp` read at `0x004ccc80`, clear helper `0x004ce310`, scalar deleting destructor clear at `0x004ce4b2`, and item/inventory/tooltip caller-side tests.
- Constructor disassembly/decompile confirms vtable stores to `0x0061ae04`, `0x0061ae50`, and `0x0061ae80` at `0x004c8341`, `0x004c8347`, and `0x004c8351`.

Vtable and method dispatch:

- `xrefs_to 0x004c8bd0` reports the paint vtable slot at `0x0061ae48`.
- `xrefs_to 0x004ccc20`, `0x004ccc40`, and `0x004ccc80` report vtable slots at `0x0061ae84`, `0x0061ae54`, and `0x0061ae58`.
- `xrefs_to 0x004ccca0` is the constructor call at `0x004c85a2`.
- `xrefs_to 0x004ce100` reports constructor calls at `0x004c8660` and `0x004c896e`, plus paint calls at `0x004c8e39` and `0x004c8e68`.

Main callee sets:

- Constructor calls base pane setup `0x00544460`, context lookup `0x004b85f0`, item slot lookup `0x005a3870`, `_wcscpy_s`, `PopulateItemData`, `CountTextLines`, text measurement helpers, rectangle/screen clamp helpers, pane add/order helpers, and timer schedule `0x005975e0`.
- `OnPaintFrame` calls GrafPort/text/frame helpers, callback slot `0x0069b3fc`, `CountTextLines`, `_memset`, `sub_41B9B0`, and numeric conversion `unknown_libname_24`.
- `PopulateItemData` calls allocation/free helpers, string format/copy helpers, SSO string construction/destruction (`0x00421590` and `0x00421310`), MetaMan helpers `0x00523120`, `0x005231f0`, `0x00523330`, local compare helper `0x004ce160`, range/invalid-parameter paths, and a fixed 20-row stat buffer allocation at `this + 0x62c`.
- `CountTextLines` only calls the text segment measurement helper `0x004ba8b0`.

Metadata helper/source ownership:

- `PopulateItemData` reads `g_pMetaMan` (`0x0069b410`) at repeated sites such as `0x004cce48`, `0x004cd028`, `0x004cd1e8`, `0x004cd402`, `0x004cd4f9`, `0x004cd818`, and `0x004cdec8`.
- The metadata file/page already owns the MetaMan helper side. `ItemHelpPane` remains the owner of the tooltip presentation state, labels, stat formatting, durability formatting, owner/protection lines, and requirement/class labels.

### Jump Table Modeling

Raw IDA and local PE decoding agree that `0x004ccba0-0x004ccc1c` is a 31-entry code-pointer table inside `.text`, followed by `0x004ccc1c-0x004ccc20` padding:

```text
0x004ccba0 -> 0x004cb03c
0x004ccba4 -> 0x004cb374
0x004ccba8 -> 0x004cb840
0x004ccbac -> 0x004cbd10
0x004ccbb0 -> 0x004cc1e0
0x004ccbb4 -> 0x004cc6b0
0x004ccbb8 -> 0x004cb395
0x004ccbbc -> 0x004cb6b4
0x004ccbc0 -> 0x004cb715
0x004ccbc4 -> 0x004cb776
0x004ccbc8 -> 0x004cb7d7
0x004ccbcc -> 0x004cb861
0x004ccbd0 -> 0x004cbb84
0x004ccbd4 -> 0x004cbbe5
0x004ccbd8 -> 0x004cbc46
0x004ccbdc -> 0x004cbca7
0x004ccbe0 -> 0x004cbd31
0x004ccbe4 -> 0x004cc054
0x004ccbe8 -> 0x004cc0b5
0x004ccbec -> 0x004cc116
0x004ccbf0 -> 0x004cc177
0x004ccbf4 -> 0x004cc201
0x004ccbf8 -> 0x004cc524
0x004ccbfc -> 0x004cc585
0x004ccc00 -> 0x004cc5e6
0x004ccc04 -> 0x004cc647
0x004ccc08 -> 0x004cc6d1
0x004ccc0c -> 0x004cc9f4
0x004ccc10 -> 0x004cca55
0x004ccc14 -> 0x004ccab6
0x004ccc18 -> 0x004ccb17
0x004ccc1c -> 0xcccccccc
```

This should not become emitted C++ as a hand-authored table. It is compiler-generated data from switch statements inside `OnPaintFrame`. It should get a non-emitting evidence child so the parent can be split cleanly without hiding the non-code island inside a method body.

### Local PE Scan

Independent read-only PE scan:

- File: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`.
- MD5: `4247e04e20b65d6414c7238aa8ff5515`.
- SHA256: `9aec210bbc5ce592176a21dd8e9d9fd8f250b8d9ea78237915a99ba8cfa9a632`.
- Imagebase: `0x400000`.
- `.text`: `0x00401000-0x0060c4ac`, raw `0x400-0x20ba00`.
- `.rdata`: `0x0060d000-0x0066c0be`, raw `0x20ba00-0x26ac00`.
- `.data`: `0x0066d000-0x0069ce24`, raw `0x26ac00-0x278400`.

Raw bytes confirm:

- `0x004c82d0` maps to file offset `0x000c76d0` and begins with a normal function prologue.
- `0x004c8b13-0x004c8b20`, `0x004c8bc2-0x004c8bd0`, and all later gaps listed above are `0xcc` alignment.
- `0x004ce100` ends with `5f 5e 5b 8b e5 5d c2 0c 00`; `0x004ce160` begins the next helper.
- Absolute pointer-byte hits match expected vtable/table evidence:
  - `0x004c8bd0`: one hit at `.rdata` VA `0x0061ae48`.
  - `0x004ccba0`: one hit at `.text` VA `0x004cb038`, the switch-indirect-table reference.
  - `0x004ccc20`: one hit at `.rdata` VA `0x0061ae84`.
  - `0x004ccc40`: one hit at `.rdata` VA `0x0061ae54`.
  - `0x004ccc80`: one hit at `.rdata` VA `0x0061ae58`.
  - `0x004ce430`: one hit at `.rdata` VA `0x0061ae04`.
  - No absolute pointer hits for constructor `0x004c82d0`, `PopulateItemData` `0x004ccca0`, `CountTextLines` `0x004ce100`, or support helper `0x004ce160`, matching direct-call/internal-helper reachability rather than vtable entry points.

The PE scan did not reveal duplicate retained copies, alternate raw starts, or extra source-path/debug metadata that would change the source-placement decision.

## Source-Placement Analysis

### Why the current broad page should be split

The target is a very large method cluster, not one original source-level construct. It contains eight IDA functions, a compiler-emitted switch-table island, and seven padding gaps. The exact children have stable method-level ownership and source meaning; keeping them only inside one `24,208` byte leaf is the reason the target remains a largest-reconstructable memory-tool item and blocks final source-quality auditing.

The split is low-risk:

- Every function boundary is already modeled in IDA.
- The switch table is byte-backed and not a function.
- Internal padding is all `0xcc`.
- The direct class parent [UID:00006U] clears `85/85`.
- The class emitter already routes through [UID:0000JU], so children can use direct class `EMITTER_UIDS:00006U` and still surface to `HelpPanes.cpp`.

If the supervisor does not perform the split immediately, keep `00016V` source-bearing temporarily so the executable code is still covered. Do not add final C++ to the broad page.

### Why direct owner should be `ItemHelpPane`, not `HelpPanes`

`HelpPanes` is the conservative source-family/file route. The direct semantic owner of these method bodies is the `ItemHelpPane` class:

- All modeled functions in `00016V` are ItemHelpPane methods or compiler data generated from `ItemHelpPane::OnPaintFrame`.
- Vtable refs are ItemHelpPane vtable slots.
- Constructor/destructor bodies publish/clear `g_pItemHelpPane`.
- Support docs already describe [UID:00006U] as the rich item tooltip class and it now clears `86/86`.

This is not a move away from `HelpPanes.cpp`. It is the current `by-structure.md` split between semantic owner and output route: child pages should attach to the class, while the class emitter remains `0000JU`.

### Why not move to `ItemHelpPane.cpp` now

Evidence checked:

- `HelpPanes.md` and `proposed-source-tree.md` explicitly preserve `ItemHelpPane.cpp` as a possible future split.
- Generated source has `class_ItemHelpPane.cpp`, but generated one-class output is not original source-file evidence.
- `HelpItemHelpReadOnlyData` mixes ItemHelpPane vtables/literals with HelpPane, SimpleHelpPane, SimpleHelpPane2, and WillBeChanged vtables.
- No `.cpp`, `.pdb`, CodeView/source path, linker-map, or compilation-unit strings were found that identify original source files.
- Constructor callers come from inventory/item-menu/self-look consumers, but those are call sites, not source ownership.

Why unresolved safely:

The current evidence proves a coherent tooltip/help source family and a direct ItemHelpPane class owner. It does not prove that the original project used a standalone `ItemHelpPane.cpp`. Moving the class emitter would be source-layout speculation and should be a later family-wide decision.

### Why not move parts to `MetaMan`

Evidence checked:

- `PopulateItemData` calls MetaMan lookup/load helpers and reads `g_pMetaMan`.
- `MetaMan.md`, `g_pMetaMan.md`, and `MetaManLookupHelpers.md` already own metadata storage/helper behavior.
- The body at `0x004ccca0` writes ItemHelpPane fields, labels, descriptions, stat strings, value formatting, owner/protection text, requirement/class labels, and the stat-value table at `this + 0x62c`.

Why resolved:

Metadata lookup helpers are dependencies. The source-placement owner of `PopulateItemData` is ItemHelpPane because the method formats ItemHelpPane presentation state from metadata results. No split/merge into MetaMan is justified.

## Remaining Blockers

### Paint/populate field names

Status: unresolved; keep child and parent C++ blank.

Evidence checked:

- Constructor decompile/disassembly stabilizes major offsets: `+0xf8` width, `+0xfc` line count, `+0x100` item/equipment mode byte, `+0x101` item-data/source flag, `+0x104` item icon/durability-related value, name buffers around `+0x108`, `+0x188`, `+0x208`, description text at `+0x288`, durability/protection count at `+0x308`, labels from `+0x334` onward, and stat pointer table at `+0x62c`.
- `PopulateItemData` writes fixed 20-wide-character labels at offsets including `+0x334`, `+0x35c`, `+0x384`, `+0x3ac`, `+0x3d4`, `+0x3fc`, `+0x424`, `+0x44c`, `+0x474`, `+0x49c`, `+0x4c4`, `+0x58c`, `+0x5b4`, `+0x5dc`, and `+0x604`.
- Destructor/scalar deleting destructor iterate and free 20 pointer slots from the table at `+0x62c`.
- Generated `class_ItemHelpPane.cpp` proposes names such as `m_displayName`, `m_descriptionText`, `m_statLabels`, and `m_statTable`, but it is polluted and not a reliable final source layout.

Why unresolved safely:

The offsets and behavior are strong enough for child split and source ownership. They are not strong enough to commit final member names and a complete class layout. A later dedicated `ItemHelpPane` layout pass should reconcile these offsets with `ItemSlot`, `MyItem`, metadata payload fields, and draw-method consumers before any final C++ is added.

### Metadata helper names/signatures

Status: source ownership resolved; exact final signatures unresolved.

Evidence checked:

- `PopulateItemData` calls `0x00523120`, `0x005231f0`, and `0x00523330`.
- Existing MetaMan docs name these roles as lookup/load/section-existence helpers and explicitly say they are not ItemHelpPane-owned.
- `PopulateItemData` also calls local support helper `0x004ce160` for wide SSO string comparison, documented in [UID:00022P][HelpTooltipSupportHelpers](../../../../../by-memory/0x004ce160-0x004ce34b.HelpTooltipSupportHelpers.md).

Why unresolved safely:

The helper owners are clear, but exact original function names and signatures remain below final-source quality. This blocks final C++ naming, not the child split.

### Singleton/lifetime role

Status: resolved.

Evidence checked:

- `xrefs_to 0x0069ae04` reports 20 refs.
- Constructor publishes and fallback-clears the singleton at `0x004c832e`/`0x004c8335`.
- Non-deleting destructor clears it at `0x004c8ba1`.
- `DismissItemHelp` reads it at `0x004ccc80` and calls virtual slot 0 with flag `1`.
- Support helper `0x004ce310` and scalar deleting destructor `0x004ce430` clear it.
- Caller-side consumers test/read it before replacing or closing tooltips.

No score reduction or reclassification is needed for singleton ownership.

### Jump-table modeling

Status: resolved by recommended non-emitting child.

Evidence checked:

- IDA names and disassembly show the jump table is referenced from `OnPaintFrame` at `0x004cb035`.
- Raw PE bytes decode 31 code pointers into `OnPaintFrame` labels followed by a padding dword.
- `lookup_funcs 0x004ccba0` returns not-a-function.

The table is compiler-generated switch data and should not emit as standalone source. A non-emitting child page plus an ignored padding row is the cleanest documentation model.

### Final source placement

Status: unresolved between `HelpPanes.cpp` and possible `ItemHelpPane.cpp`, but resolved for current routing.

Evidence checked:

- Proposed source tree and HelpPanes file docs.
- Mixed help/item-help read-only data island.
- Singleton and destructor/support-helper family.
- Constructor call-site owners.
- Generated one-class output limitations.
- Absence of source-path/debug metadata.

Why unresolved safely:

No direct build/source artifact proves a separate original `ItemHelpPane.cpp`. Keep class emitter through `HelpPanes` for now. Do not add a new file root or move emitters based only on class size.

## Supervisor Actions

Use normal UID assignment for new pages. Replace `<UID-...>` placeholders below with assigned UIDs before applying docs or coverage rows.

### New Child Page Metadata

Use these headers:

```text
0x004c82d0-0x004c8b13.ItemHelpPaneConstructor.md
*** COMPLETION:86 ***
*** CONFIDENCE:90 ***
*** CANONICAL_OWNER:00006U ***
*** RECONSTRUCTABLE:TRUE ***
*** EMITTER_UIDS:00006U ***

0x004c8b20-0x004c8bc2.ItemHelpPaneNonDeletingDestructor.md
*** COMPLETION:85 ***
*** CONFIDENCE:90 ***
*** CANONICAL_OWNER:00006U ***
*** RECONSTRUCTABLE:TRUE ***
*** EMITTER_UIDS:00006U ***

0x004c8bd0-0x004ccba0.ItemHelpPaneOnPaintFrame.md
*** COMPLETION:85 ***
*** CONFIDENCE:88 ***
*** CANONICAL_OWNER:00006U ***
*** RECONSTRUCTABLE:TRUE ***
*** EMITTER_UIDS:00006U ***

0x004ccba0-0x004ccc1c.ItemHelpPaneOnPaintFrameJumpTables.md
*** COMPLETION:86 ***
*** CONFIDENCE:91 ***
*** CANONICAL_OWNER:00006U ***
*** RECONSTRUCTABLE:FALSE ***
*** EMITTER_UIDS: ***

0x004ccc20-0x004ccc3a.ItemHelpPaneOnTimerEvent.md
*** COMPLETION:86 ***
*** CONFIDENCE:90 ***
*** CANONICAL_OWNER:00006U ***
*** RECONSTRUCTABLE:TRUE ***
*** EMITTER_UIDS:00006U ***

0x004ccc40-0x004ccc7e.ItemHelpPaneOnMouseEvent.md
*** COMPLETION:86 ***
*** CONFIDENCE:90 ***
*** CANONICAL_OWNER:00006U ***
*** RECONSTRUCTABLE:TRUE ***
*** EMITTER_UIDS:00006U ***

0x004ccc80-0x004ccc95.ItemHelpPaneDismissItemHelp.md
*** COMPLETION:86 ***
*** CONFIDENCE:90 ***
*** CANONICAL_OWNER:00006U ***
*** RECONSTRUCTABLE:TRUE ***
*** EMITTER_UIDS:00006U ***

0x004ccca0-0x004ce0f6.ItemHelpPanePopulateItemData.md
*** COMPLETION:85 ***
*** CONFIDENCE:88 ***
*** CANONICAL_OWNER:00006U ***
*** RECONSTRUCTABLE:TRUE ***
*** EMITTER_UIDS:00006U ***

0x004ce100-0x004ce160.ItemHelpPaneCountTextLines.md
*** COMPLETION:86 ***
*** CONFIDENCE:90 ***
*** CANONICAL_OWNER:00006U ***
*** RECONSTRUCTABLE:TRUE ***
*** EMITTER_UIDS:00006U ***
```

Each source-bearing child should keep final C++ blank and include:

- Link to [UID:00016V] as parent migration index.
- Link to [UID:00006U] as direct class owner.
- Function start/end and IDA size.
- Relevant xrefs/callers/vtable refs/callees.
- Current final-C++ blockers for field/helper/source-file names.

The jump-table child should explicitly state it is compiler-emitted switch data from `ItemHelpPane::OnPaintFrame`, source-relevant evidence but non-emitting.

### Parent Target Metadata

After child pages and internal padding rows exist, update `by-memory/0x004c82d0-0x004ce160.ItemHelpPaneCore.md`:

```text
*** COMPLETION:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:00006U | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:FALSE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Recommended status wording:

```text
- Disposition: reviewed non-emitting ItemHelpPane migration index/source-quality map.
- Reconstruction handling: `RECONSTRUCTABLE:FALSE`; exact child pages carry the source-bearing ItemHelpPane methods, the non-emitting switch table, and internal padding rows. Keep this page as the audited parent range and source-placement summary only.
- Direct owner: [UID:00006U][ItemHelpPane](by-class/ItemHelpPane.md). The class currently emits through [UID:0000JU][HelpPanes](by-file/HelpPanes.md); a possible future `ItemHelpPane.cpp` split remains unresolved.
```

Recommended change note:

```text
- 2026-06-16 B001 source-quality split review:
  - After creation of exact child method/data pages, changed from `82/88`, `CANONICAL_OWNER:0000JU`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000JU` to `86/90`, `CANONICAL_OWNER:00006U`, `RECONSTRUCTABLE:FALSE`, and blank `EMITTER_UIDS`.
  - Summary/evidence: live IDA MCP, local PE byte/pointer scan, support docs, generated-output review, and source-placement heuristics show this broad range is an ItemHelpPane method cluster plus compiler switch table and padding. Exact children now carry source ownership; the parent is a migration index and should not emit aggregate C++.
```

If the split is delayed, keep the current target metadata and C++ blank as a temporary source-bearing aggregate. Do not only change `00016V` to non-emitting without creating children.

### Support Doc Actions

After child UIDs are assigned:

- Update [UID:00006U][ItemHelpPane](../../../../../by-class/ItemHelpPane.md) Method Notes to link the eight method child pages and the switch-table child. Keep scores unchanged unless a separate layout/naming pass is completed.
- Update [UID:0000JU][HelpPanes](../../../../../by-file/HelpPanes.md) Proposed Contents to reference the child pages and describe `00016V` as a non-emitting migration index. Keep `HelpPanes` score unchanged.
- Update [UID:00025G][HelpItemHelpReadOnlyData](../../../../../by-memory/0x0061aad4-0x0061b340.HelpItemHelpReadOnlyData.md) only if desired for cross-link clarity; no score or metadata change is required.
- Do not create `ItemHelpPane.cpp` or change the class emitter in this pass.
- Do not create a final `ItemHelpPaneLayout` type page yet unless a dedicated field-layout pass is assigned; current field names are not final-source quality.

### Shared Coverage Row Actions

B001 must not edit `by-memory/-coverage-report.md` directly. Supervisor should replace the current single `00016V` row immediately after the existing `0x004c82cf-0x004c82d0` padding row and before [UID:00022P] `0x004ce160-0x004ce34b`.

Use this replacement block after substituting real child UIDs:

```text
    - [UID:00016V][0x004c82d0-0x004ce160.ItemHelpPaneCore](by-memory/0x004c82d0-0x004ce160.ItemHelpPaneCore.md) 0x004c82d0-0x004ce160 | migration index | ItemHelpPaneCore : not_reconstructable : 86% : strong : B001 2026-06-16 source-quality split review reclassifies this large ItemHelpPane method/switch-table island as a non-emitting migration index under [UID:00006U][ItemHelpPane](by-class/ItemHelpPane.md); exact child method pages carry constructor/destructor/paint/timer/mouse/dismiss/populate/line-count source ownership, the jump-table child carries compiler switch-table evidence, and internal padding rows carry alignment state, so no aggregate final C++ should emit from this range.
        - [UID:<UID-ITEMHELP-CTOR>][0x004c82d0-0x004c8b13.ItemHelpPaneConstructor](by-memory/0x004c82d0-0x004c8b13.ItemHelpPaneConstructor.md) 0x004c82d0-0x004c8b13 | constructor | ItemHelpPaneConstructor : reconstructable : 86% : strong : Exact ItemHelpPane constructor; live IDA reports size 0x843, constructor callers at 0x004ed957/0x0051b383/0x0051f7e3/0x00568e84, singleton publish/fallback clear at 0x004c832e/0x004c8335, ItemHelpPane vtable stores at 0x004c8341/0x004c8347/0x004c8351, PopulateItemData and CountTextLines calls, layout/timer setup, unique PE byte evidence, and 0xcc successor padding.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x004c8b13-0x004c8b20 | padding | ItemHelpPane constructor to non-deleting destructor alignment : ignored : 100% : strong : Live IDA/local PE bytes confirm thirteen `0xcc` alignment bytes after the constructor `retn 20h`.
        - [UID:<UID-ITEMHELP-DTOR>][0x004c8b20-0x004c8bc2.ItemHelpPaneNonDeletingDestructor](by-memory/0x004c8b20-0x004c8bc2.ItemHelpPaneNonDeletingDestructor.md) 0x004c8b20-0x004c8bc2 | destructor | ItemHelpPaneNonDeletingDestructor : reconstructable : 85% : strong : Exact ItemHelpPane non-deleting destructor despite polluted current IDA Boost exception name; live IDA reports size 0xa2, clears g_pItemHelpPane at 0x004c8ba1, restores ItemHelpPane vtable views, frees the 20-entry stat/text pointer table at +0x62c, tears down the base pane, and ends before 0xcc alignment.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x004c8bc2-0x004c8bd0 | padding | ItemHelpPane destructor to OnPaintFrame alignment : ignored : 100% : strong : Live IDA/local PE bytes confirm fourteen `0xcc` alignment bytes.
        - [UID:<UID-ITEMHELP-PAINT>][0x004c8bd0-0x004ccba0.ItemHelpPaneOnPaintFrame](by-memory/0x004c8bd0-0x004ccba0.ItemHelpPaneOnPaintFrame.md) 0x004c8bd0-0x004ccba0 | method | ItemHelpPaneOnPaintFrame : reconstructable : 85% : strong : Exact ItemHelpPane paint method; live IDA reports size 0x3fd0, vtable slot ref at 0x0061ae48, CountTextLines calls at 0x004c8e39/0x004c8e68, switch-table reference at 0x004cb035, item-help literal refs, GrafPort/text/render callees, and remaining field/helper-name blockers.
        - [UID:<UID-ITEMHELP-JMPTABLES>][0x004ccba0-0x004ccc1c.ItemHelpPaneOnPaintFrameJumpTables](by-memory/0x004ccba0-0x004ccc1c.ItemHelpPaneOnPaintFrameJumpTables.md) 0x004ccba0-0x004ccc1c | switch table | ItemHelpPaneOnPaintFrameJumpTables : not_reconstructable : 86% : strong : Compiler-emitted switch data for ItemHelpPane::OnPaintFrame; IDA names jpt_4CB035 and related tables, raw PE decodes 31 dwords to OnPaintFrame labels from 0x004cb03c through 0x004ccb17, and the table is source-relevant evidence but not standalone emitted C++.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x004ccc1c-0x004ccc20 | padding | ItemHelpPane OnPaintFrame jump table to timer alignment : ignored : 100% : strong : Live IDA/local PE bytes confirm a trailing `0xcccccccc` padding dword after the jump-table entries.
        - [UID:<UID-ITEMHELP-TIMER>][0x004ccc20-0x004ccc3a.ItemHelpPaneOnTimerEvent](by-memory/0x004ccc20-0x004ccc3a.ItemHelpPaneOnTimerEvent.md) 0x004ccc20-0x004ccc3a | method | ItemHelpPaneOnTimerEvent : reconstructable : 86% : strong : Exact ItemHelpPane timer handler; live IDA reports size 0x1a, vtable slot ref at 0x0061ae84, timer id zero path calls pane deletion/close behavior through 0x00544d30, returns zero, and ends before 0xcc alignment.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x004ccc3a-0x004ccc40 | padding | ItemHelpPane timer to mouse alignment : ignored : 100% : strong : Live IDA/local PE bytes confirm six `0xcc` alignment bytes.
        - [UID:<UID-ITEMHELP-MOUSE>][0x004ccc40-0x004ccc7e.ItemHelpPaneOnMouseEvent](by-memory/0x004ccc40-0x004ccc7e.ItemHelpPaneOnMouseEvent.md) 0x004ccc40-0x004ccc7e | method | ItemHelpPaneOnMouseEvent : reconstructable : 86% : strong : Exact ItemHelpPane mouse handler; live IDA reports size 0x3e, vtable slot ref at 0x0061ae54, repaints the pane, cancels/resets timer through 0x005975e0 for mouse-down/double-click event types, returns true, and ends before 0xcc alignment.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x004ccc7e-0x004ccc80 | padding | ItemHelpPane mouse to dismiss alignment : ignored : 100% : strong : Live IDA/local PE bytes confirm two `0xcc` alignment bytes.
        - [UID:<UID-ITEMHELP-DISMISS>][0x004ccc80-0x004ccc95.ItemHelpPaneDismissItemHelp](by-memory/0x004ccc80-0x004ccc95.ItemHelpPaneDismissItemHelp.md) 0x004ccc80-0x004ccc95 | helper | ItemHelpPaneDismissItemHelp : reconstructable : 86% : strong : Exact ItemHelpPane singleton dismiss helper; live IDA reports size 0x15, reads g_pItemHelpPane at 0x004ccc80, null-checks it, calls virtual slot 0 with flag 1, returns zero, and has the matching vtable/helper relationship documented by singleton pages.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x004ccc95-0x004ccca0 | padding | ItemHelpPane dismiss to PopulateItemData alignment : ignored : 100% : strong : Live IDA/local PE bytes confirm eleven `0xcc` alignment bytes.
        - [UID:<UID-ITEMHELP-POPULATE>][0x004ccca0-0x004ce0f6.ItemHelpPanePopulateItemData](by-memory/0x004ccca0-0x004ce0f6.ItemHelpPanePopulateItemData.md) 0x004ccca0-0x004ce0f6 | method | ItemHelpPanePopulateItemData : reconstructable : 85% : strong : Exact ItemHelpPane metadata population method; live IDA reports size 0x1456, constructor caller at 0x004c85a2, MetaMan helper calls 0x00523120/0x005231f0/0x00523330, local wide-string compare helper 0x004ce160, g_pMetaMan reads, ItemHelp/ItemInfo/CharicInfo and stat/class literal refs, 20-row stat table allocation at +0x62c, and remaining field/helper-name blockers.
        - [UID:0000VN][-ignored](by-memory/-ignored.md) 0x004ce0f6-0x004ce100 | padding | ItemHelpPane PopulateItemData to CountTextLines alignment : ignored : 100% : strong : Live IDA/local PE bytes confirm ten `0xcc` alignment bytes.
        - [UID:<UID-ITEMHELP-COUNT>][0x004ce100-0x004ce160.ItemHelpPaneCountTextLines](by-memory/0x004ce100-0x004ce160.ItemHelpPaneCountTextLines.md) 0x004ce100-0x004ce160 | helper | ItemHelpPaneCountTextLines : reconstructable : 86% : strong : Exact ItemHelpPane wrapped-line count helper; live IDA reports size 0x60, callers at 0x004c8660/0x004c896e/0x004c8e39/0x004c8e68, sole callee 0x004ba8b0 for segment-width measurement, returns line count, and ends exactly before successor support helper 0x004ce160.
```

### IDA DB Recommendation

No IDA DB edit is recommended for this B001 report.

Safe future C-agent rename candidates exist, but they are not required to classify or split the range:

- `sub_4C82D0 -> ItemHelpPane_Constructor`
- `??1exception@boost@@MAE@XZ_2 -> ItemHelpPane_NonDeletingDestructor`
- `sub_4C8BD0 -> ItemHelpPane_OnPaintFrame`
- `sub_4CCC20 -> ItemHelpPane_OnTimerEvent`
- `sub_4CCC40 -> ItemHelpPane_OnMouseEvent`
- `sub_4CCC80 -> ItemHelpPane_DismissItemHelp`
- `sub_4CCCA0 -> ItemHelpPane_PopulateItemData`
- `sub_4CE100 -> ItemHelpPane_CountTextLines`
- `unk_69AE04 -> g_pItemHelpPane`

Do not block the documentation split on these cosmetic IDA names. The existing live IDA function boundaries and xrefs are already sufficient.

## Rejected Alternatives

- Keep `00016V` as one source-bearing leaf forever: rejected because exact method, switch-table, and padding children are known and the broad page is not one source-level construct.
- Treat `00016V` as dead/duplicate retained code: rejected. Constructor, vtable slots, singleton reads/writes, internal calls, and caller sites prove live ItemHelpPane behavior.
- Reclassify `00016V` to non-emitting immediately without children: rejected. Until child pages exist, it is still the only exact page covering these executable bodies.
- Move `PopulateItemData` or helper names into MetaMan: rejected. MetaMan owns lookup services; this body owns item-tooltip presentation state.
- Create or route through a new `ItemHelpPane.cpp` now: rejected as unproven original-source speculation.
- Enter final C++ now: rejected because field names, helper signatures, source-file placement, and large-body structure remain below final-source quality.

## Validation Order

After supervisor creates the new pages and substitutes real UIDs:

> Executable block R001 was removed from this report and preserved verbatim in [00016V-item-help-pane-core-source-quality-removed.md](00016V-item-help-pane-core-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Then apply optional support-doc link updates and validate each touched support doc.

## Changed Files

- Created this report: `tools/leaser/Agents/Agent-B001/research/00016V-item-help-pane-core-source-quality.md`.
- No by-* documentation changed by B001.
- No generated reports changed by B001.
- No IDA DB edits made by B001.
- `by-memory/-coverage-report.md` was not edited by B001.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B001","command_id":"000000004165","destination_path":"executed-b-agent-research/B001/00016V-item-help-pane-core-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:18","uid":"00016V"} -->
<!-- {"agent":"B001","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 00016V-item-help-pane-core-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B001/00016V-item-help-pane-core-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"00016V"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
