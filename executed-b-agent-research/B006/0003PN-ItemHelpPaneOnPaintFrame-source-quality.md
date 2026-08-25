** TARGET-REPORT-UID:0003PN **
** AUTHOR-AGENT-ID:B006 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
** REPORT-VALIDATION-STATUS: needs-revalidation **
** REPORT-REVALIDATION-REASON: target_uid_unknown: 0003PN **
# [UID:0003PN] ItemHelpPaneOnPaintFrame source-quality report

Status: FINISHED report-only B006 research pass.

Target: `source-3/project-documentation/by-memory/0x004c8bd0-0x004ccba0.ItemHelpPaneOnPaintFrame.md`  
Required report: `source-3/project-documentation/tools/leaser/Agents/Agent-B006/research/0003PN-ItemHelpPaneOnPaintFrame-source-quality.md`

No by-* target/support documentation and no `by-memory/-coverage-report.md` file were edited.

## Final recommendation

- Keep [UID:0003PN] as one exact source-authored virtual method: `void ItemHelpPane::OnPaintFrame()`.
- Keep `CANONICAL_OWNER:00006U`, `EMITTER_UIDS:00006U`, and source routing through [UID:00006U] `ItemHelpPane` under [UID:0000N4] `HelpPanes`. The most likely future source-file split is `NexusTK/ui/controls/ItemHelpPane.cpp`, but current generated route remains `auto-generated/NexusTK/ui/controls/HelpPanes.cpp`.
- Raise the target from `COMPLETION:85`, `CONFIDENCE:88` to `COMPLETION:88`, `CONFIDENCE:90`.
- Do not create additional child pages inside `0x004c8bd0-0x004ccba0`. The executable range is one large paint method. The existing non-code child [UID:0003PO] already owns the immediately following compiler switch tables at `0x004ccba0-0x004ccc1c`.
- Keep [UID:0003PO] `RECONSTRUCTABLE:FALSE`, no emitter, no formal C++. It is generated switch data for this method.
- Keep formal C++ blank in [UID:0003PN] for the first implementation callback, but replace the passive "blockers" wording with the target-specific defer proof below. The method is source-authored and reconstructable, but a source-quality formal block should not be entered until the support docs accept the inferred class layout and a policy for the unrolled stat/requirement drawing helpers. Behavior and names are now sufficiently resolved for support-doc incorporation and a later draft.

Rejected high-level alternatives:

- Do not split the item-stat rows or requirement cases into artificial child functions. The binary has one method body and private jump-table labels, not separate source functions.
- Do not merge the jump tables back into [UID:0003PN]. They are non-code dword tables after the method epilogue and before `0x004ccc20`.
- Do not route ownership to `GrafPort`, `SurfaceRenderCallbackTable`, `MetaMan`, or generic help-pane infrastructure. Those are dependencies. The vtable xref and field accesses make `ItemHelpPane` the source owner.
- Do not retain compiler names such as `sub_4C8BD0`, `jpt_4CB035`, `sub_41B9B0`, or `unknown_libname_24` in final prose except as historical labels with resolved source-facing roles.

## Target facts

| Item | Value |
| --- | --- |
| UID | `0003PN` |
| Range | `0x004c8bd0-0x004ccba0` |
| Size | `0x3fd0` / 16336 bytes |
| Kind | source-authored virtual paint method |
| Recommended source name | `ItemHelpPane::OnPaintFrame` |
| Recommended signature | `void ItemHelpPane::OnPaintFrame()` |
| Current owner/emitter | [UID:00006U] `ItemHelpPane` |
| Current source route | [UID:0000N4] `HelpPanes`, generated route `NexusTK/ui/controls/HelpPanes.cpp` |
| Vtable xref | `0x0061ae48`, primary `ItemHelpPane` vtable slot index 17 / offset `+0x44` from `0x0061ae04` |
| Ordinary direct callers | none; virtual dispatch only |
| Private switch-table child | [UID:0003PO] `0x004ccba0-0x004ccc1c.ItemHelpPaneOnPaintFrameJumpTables` |
| Main helper calls | GrafPort color/frame/text/measure helpers, [UID:0003PT] `ItemHelpPaneCountTextLines`, SurfaceRenderCallbackTable slot `0x0069b3fc`, `_memset`, wide `swprintf_s` wrapper `0x0041b9b0`, `_wtol` |

## Evidence checked

Documentation and project files:

- `tools/leaser/Agents/Supervisor.md`, `.codex/AGENTS.md`, `tools/leaser/Agents/Agent-B006/goal.md`
- Target [UID:0003PN] `by-memory/0x004c8bd0-0x004ccba0.ItemHelpPaneOnPaintFrame.md`
- [UID:0003PO] `by-memory/0x004ccba0-0x004ccc1c.ItemHelpPaneOnPaintFrameJumpTables.md`
- [UID:00016V] `by-memory/0x004c82d0-0x004ce160.ItemHelpPaneCore.md`
- [UID:00006U] `by-class/ItemHelpPane.md`
- [UID:0000N4] `by-file/HelpPanes.md`
- [UID:0003PM] `by-memory/0x004c82d0-0x004c8b13.ItemHelpPaneConstructor.md`
- [UID:0003PS] `by-memory/0x004ccca0-0x004ce0f6.ItemHelpPanePopulateItemData.md`
- [UID:0003PT] `by-memory/0x004ce100-0x004ce160.ItemHelpPaneCountTextLines.md`
- [UID:00025G] `by-memory/0x0061aad4-0x0061b340.HelpItemHelpReadOnlyData.md`
- GrafPort support docs:
  - `by-memory/0x004b95e0-0x004b969f.GrafPortDrawStateAccessors.md`
  - `by-memory/0x004ba450-0x004ba53b.GrafPortDrawRectFrame.md`
  - `by-memory/0x004ba9a0-0x004bad66.GrafPortTextRunHelpers.md`
  - `by-memory/0x004bad70-0x004baf92.DrawTextInRect.md`
- [UID:0002H9] `by-memory/0x0069b3e0-0x0069b410.SurfaceRenderCallbackTable.md`
- Current coverage rows for `0003PN` and `0003PO` in `by-memory/-coverage-report.md`
- Existing B006 research folder; no prior `*ItemHelpPane*` B006 report existed at the required report path.

Generated/exported evidence:

- `resources/exported_data/functions/0x004c8bd0.json`
- `resources/exported_data/functions/0x0041b9b0.json`
- `resources/exported_data/master_vtables.json`
- `resources/exported_data/master_globals.json`
- `source-3/simroot_v2/class_ItemHelpPane.cpp`
- `source-3/project-documentation/auto-generated/NexusTK/ui/controls/HelpPanes.cpp`

Direct checks run:

- Raw PE read against `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe` using image base `0x00400000` to verify the function prologue, epilogue, switch-table dwords, and padding.
- Coverage row lookup with `rg -n "0003PN|ItemHelpPaneOnPaintFrame" source-3/project-documentation/by-memory/-coverage-report.md`.

IDA MCP was not assumed live for this pass. Existing live-IDA-backed docs plus exported IDA/Ghidra records and direct PE bytes were sufficient for the boundary, xref, and switch-table conclusions.

## Boundary and bytes

The method boundary is exact:

- Function start: `0x004c8bd0`
- Function end, exclusive: `0x004ccba0`
- Raw start bytes: `55 8b ec 81 ec d4 00 00 00 ...`
- Raw end bytes before `0x004ccba0`: normal method epilogue ending `8b e5 5d c3`
- No evidence supports an alternate entry point inside the method.
- No ordinary direct callers are expected because this is reached through the `ItemHelpPane` virtual paint slot.

The following range is not executable method code:

- `0x004ccba0-0x004ccc1c`: 31 dword compiler switch entries, all pointing back into labels inside `0x004c8bd0-0x004ccba0`.
- `0x004ccc1c-0x004ccc20`: `CC CC CC CC` padding.
- `0x004ccc20`: next method prologue for [UID:0003PP] `ItemHelpPaneOnTimerEvent`.

The existing split is therefore correct:

- [UID:0003PN] owns exactly the paint method.
- [UID:0003PO] owns exactly the generated switch data.
- [UID:0003PP] starts at the next code boundary.

## Xref and reachability

Best conclusion: `ItemHelpPane::OnPaintFrame()` is vtable-reachable, source-authored UI code.

Evidence:

- `resources/exported_data/functions/0x004c8bd0.json` models the function at `0x004c8bd0`, size `16336`, not a thunk.
- Exported IDA xrefs show one data xref from `0x0061ae48`, the `ItemHelpPane` primary vtable paint slot.
- `resources/exported_data/master_vtables.json` records `vftable_0061ae04` entry index 17 / offset `+0x44` pointing to `0x004c8bd0`.
- No ordinary direct callers are required for a pane paint method. The vtable slot is the correct caller/reachability route.

Rejected alternatives:

- "Dead retained function": rejected. The vtable slot proves live virtual dispatch.
- "Standalone helper": rejected. The body reads many `ItemHelpPane` object fields and is vtable-owned.
- "Compiler thunk": rejected. The function has a large semantic paint body and no thunk shape.

## Callee and helper resolution

| Raw label/address | Recommended source-facing role | Confidence | Evidence and notes |
| --- | --- | --- | --- |
| `0x004b9660` | `GrafPort::SetDrawColor` / active draw/fill color setter | high | GrafPort draw-state docs show this writes the draw color field at GrafPort `+0x74`. Used before background invalidation/fill and frame draw. |
| `0x004ba450` | `GrafPort::DrawRectFrame(const RectBounds *rect)` | very high | Support doc has first-draft C++; paint calls it after setting frame color `0x80`. |
| `0x004b7c30` | `Point`/two-coordinate helper | medium | Used to initialize coordinate pairs. Keep as layout helper until `RectGeometry` names are finalized. |
| `0x004baaa0` | `GrafPort::GetLineHeight()` | very high | Text-run support doc identifies this helper. |
| `0x004b9680` | `GrafPort::SetTextColor` / primary text color setter | high | GrafPort docs show this writes `m_textColor` at `+0x7c`; reject older "background color" alias. |
| `0x004b78d0` | `RectBounds::SetLTRB` / `SetRectLTRB` | high | Used to form draw rectangles from left/top/right/bottom coordinates. |
| `0x004bad70` | `GrafPort::DrawTextInRect(const wchar_t *text, int length, const RectBounds *rect)` | very high | Support doc has first-draft C++ and exact `ret 0x0c` argument cleanup. |
| `0x004ce100` | `ItemHelpPane::CountTextLines(...)` | high | Existing child [UID:0003PT]. Called twice at `0x004c8e39` and `0x004c8e68` for description layout. |
| `0x004ba9a0` | `GrafPort::GetTextWidth(const wchar_t *text, int charCount)` | very high | Text-run support doc identifies the exact helper. Used repeatedly to center label/value pairs. |
| `0x004b78f0` | `RectBounds::Offset` / rectangle offset helper | medium-high | Used by repeated text-layout fragments. Prefer support-doc final spelling if available. |
| `0x005ca0b0` | `_memset` | very high | CRT helper. Used for stack buffers. |
| `0x0041b9b0` | `swprintf_s` wrapper / wide safe sprintf helper | high | Exported signature is `int sub_41B9B0(wchar_t *Buffer, size_t BufferCount, wchar_t *Format, ...)`; calls `__stdio_common_vswprintf_s`. Used for `PROTECTED (%d)` and generated/temporary label formatting. |
| `0x005cea43` / `unknown_libname_24` | `_wtol` / wide string to long | high | Used to parse class/tier requirement codes from stat-value text buffers. Generated alias should be replaced with `_wtol` in prose. |
| `0x0069b3fc` | Surface render callback slot for fill/invalidate/presentation over a rect | medium-high | Surface callback table doc identifies slot 7. Current generated alias `g_pfnLockSurface` is stale for this use; the call happens after draw color setup and before frame drawing. |

## Field and layout recommendations

These names should be used consistently in [UID:0003PN], [UID:0003PS], [UID:0003PM], and [UID:00006U]. Confidence values reflect source-facing naming, not offset correctness.

| Full-object offset | Recommended field name | Type/source shape | Confidence | Evidence |
| --- | --- | --- | --- | --- |
| `+0x100` | `m_isEquipmentItem` | `bool` / byte flag | medium-high | False path draws compact value/durability rows; true path draws equipment stat list, owner, protection, and requirements. Reject `m_drawFlag` and other generated aliases. |
| `+0x101` | `m_hasItemInstanceState` | `bool` / byte flag | medium | In simple-item path, gates whether current durability/state rows are present. Name remains inferred because final item-slot source type is not recovered. |
| `+0x104` | `m_currentDurability` | `int` | medium-high | Populate/draw paths use it with durability display and percentage-like logic. Reject generated uses that treat it as a generic item id. |
| `+0x108` | `m_itemMetaKey` / `m_itemKeyText` | `wchar_t[64]`-like buffer | medium | Populated from item metadata route and used by lookup/populate code, not directly central to paint. |
| `+0x188` | `m_itemDisplayName` | `wchar_t[64]`-like buffer | high | Title drawn at top of tooltip. Constructor/populate copy the display name here. |
| `+0x208` | `m_ownerName` | `wchar_t[64]`-like buffer | high | Compared against empty string, then drawn after `Owner ` label. |
| `+0x288` | `m_helpDescription` | `wchar_t[64]`-like buffer | high | Description text drawn through `DrawTextInRect`; line count drives vertical layout. |
| `+0x308` | `m_protectionCount` | `int` | high | If positive, formatted as `PROTECTED (%d)` and drawn in warning/protection color. |
| `+0x334` | `m_valueLabel` | 20-wchar label buffer | high | Literal source is `Value`; paired with `m_statValueTextBuffers[1]`. |
| `+0x35c` | `m_durabilityLabel` | 20-wchar label buffer | high | Literal source is `Durability`; paired with row 2. |
| `+0x384` | `m_armorLabel` or `m_damageSmallLabel` | 20-wchar label buffer | medium | Populate docs call nearby stat labels `Armor`, `Hit`, `Damage`; generated label name is not trustworthy. Prefer exact literal mapping from [UID:00025G] during implementation. |
| `+0x3ac` | `m_hitLabel` | 20-wchar label buffer | high | Literal `Hit`; paired with row 4. |
| `+0x3d4` | `m_damageLabel` | 20-wchar label buffer | high | Literal `Damage`; paired with row 5. |
| `+0x3fc` | `m_vitalityIncreaseLabel` | 20-wchar label buffer | high | Literal `Vitality increase`; paired with row 6. |
| `+0x424` | `m_manaIncreaseLabel` | 20-wchar label buffer | high | Literal `Mana increase`; paired with row 7. |
| `+0x44c` | `m_mightIncreaseLabel` | 20-wchar label buffer | high | Literal `Might increase`; paired with row 8. |
| `+0x474` | `m_graceIncreaseLabel` | 20-wchar label buffer | high | Literal `Grace increase`; paired with row 9. |
| `+0x49c` | `m_willIncreaseLabel` | 20-wchar label buffer | high | Literal `Will increase`; paired with row 10. |
| `+0x4c4` | `m_wisdomIncreaseLabel` | 20-wchar label buffer | high | Literal `Wisdom increase`; paired with row 11. |
| `+0x4ec` | `m_constitutionLabel` | 20-wchar label buffer | high | Literal `Con`; paired with row 12. |
| `+0x514` | `m_requirementClassText` | 20-wchar scratch/label buffer | medium-high | Used for class requirement display such as `Any Class`, `Warrior`, or ascension-class labels. |
| `+0x53c` | `m_requirementLevelLabel` | 20-wchar scratch/label buffer | high | Literal `   Level ` copied before requirement triplet drawing. |
| `+0x564` | `m_requirementSuffix` | 20-wchar scratch/label buffer | high | Literal ` Req ` copied before requirement triplet drawing. |
| `+0x58c` | `m_regenLabel` | 20-wchar label buffer | high | Literal `Regen`; paired with row 16. |
| `+0x5b4` | `m_protectionLabel` | 20-wchar label buffer | high | Literal `Protection`; paired with row 17. |
| `+0x62c` | `m_statValueTextBuffers` | pointer/table of 20 text-row buffers, each approximately `wchar_t[0x28]` | high | Destructor/source-quality docs already recommend this over generic `m_pItemData`; PopulateItemData fills it; paint reads rows by index. |

Implementation note for `+0x384`: the generated view has naming pollution around the first stat labels. The support docs already list literals in order: `Armor`, `Hit`, `Damage`, then vitality/mana/might/will/grace/wisdom/con/regen/protection. During implementation, bind `+0x384` to the exact literal write in [UID:0003PS] before choosing `m_armorLabel` over an alternate generated label. The paint behavior is stable either way: it draws the label at `+0x384` with stat value row 3.

## Stat-value row semantics

Recommended row map for `m_statValueTextBuffers`:

| Row | Source-facing meaning | Paint use |
| --- | --- | --- |
| `1` | item value / price text | Drawn in simple and equipment paths with `m_valueLabel`. |
| `2` | durability text | Drawn when durability/state data is present. |
| `3` | armor/stat row 1 | Equipment stat list. |
| `4` | hit | Equipment stat list. |
| `5` | damage | Equipment stat list. |
| `6` | vitality increase | Equipment stat list. |
| `7` | mana increase | Equipment stat list. |
| `8` | might increase | Equipment stat list. |
| `9` | grace increase | Equipment stat list. |
| `10` | will increase | Equipment stat list. |
| `11` | wisdom increase | Equipment stat list. |
| `12` | constitution | Equipment stat list. |
| `13` | class requirement code text | Parsed with `_wtol` for outer switch. |
| `14` | tier/ascension requirement code text | Parsed with `_wtol` for nested switch. |
| `15` | level requirement text | Drawn between `   Level ` and ` Req ` for tier-0 requirement rows. |
| `16` | regeneration | Equipment stat list. |
| `17` | protection stat text | Equipment stat list. |

Rows `0`, `18`, and `19` are not required by the observed paint path. They may exist because the allocation/destructor treats the table as a fixed 20-row store.

The stat-row drawing is hand-unrolled in the compiled body. It is not a separate switch table and not a separate source function in the binary.

## Paint behavior

The method's source behavior should be documented in [UID:0003PN] and summarized in [UID:00006U]:

1. Query or receive the current clip/client rectangle for the pane.
2. Set GrafPort draw/fill color `0x97` and invoke the surface render callback at `0x0069b3fc` over the pane rectangle. This is best described as a fill/invalidate/presentation step, not a lock-surface operation.
3. Set draw color `0x80` and draw a rectangular frame around the tooltip.
4. Establish inset layout coordinates, roughly `10` pixels from the top/left and bottom/right.
5. Read line height from `GrafPort::GetLineHeight()`.
6. Draw `m_itemDisplayName` near the top, using a shadow/offset-style double draw with text colors `0x8f` and the foreground title color.
7. Check `m_helpDescription` against empty/placeholder strings. If present, draw it through `GrafPort::DrawTextInRect` in a multiline description rectangle. Use [UID:0003PT] `ItemHelpPane::CountTextLines` to advance the current row.
8. If `m_isEquipmentItem` is false, draw the compact/simple-item block:
   - if `m_hasItemInstanceState` and `m_currentDurability > 0`, draw durability and value rows centered in the pane;
   - otherwise draw the value row only.
9. If `m_isEquipmentItem` is true, draw the full equipment block:
   - value and optional durability/state rows;
   - equipment stat label/value pairs for armor/hit/damage/vitality/mana/might/grace/will/wisdom/con/regen/protection according to the populated rows;
   - owner row if `m_ownerName` is nonempty;
   - `PROTECTED (%d)` warning row if `m_protectionCount > 0`;
   - class/tier/level requirement row or ascension label using the switch-table logic.
10. Repeated label/value row drawing uses text-width measurement to center the combined label and value. The label and value are drawn in adjacent rectangles with different text colors.

The generated `source-3/simroot_v2/class_ItemHelpPane.cpp` is useful behavior evidence but not name authority. It has stale aliases such as `SetFont`, `MeasureTextWidth`, `m_secondaryName`, and helper abstractions like `DrawRequirementTriplet` that are not directly present as calls in the binary.

## Requirement switch-table mapping

The switch data in [UID:0003PO] is now source-mapped. Use this mapping in the target and support doc updates.

### Raw dword entries

```text
0x004ccba0: 0x004cb03c
0x004ccba4: 0x004cb374
0x004ccba8: 0x004cb840
0x004ccbac: 0x004cbd10
0x004ccbb0: 0x004cc1e0
0x004ccbb4: 0x004cc6b0
0x004ccbb8: 0x004cb395
0x004ccbbc: 0x004cb6b4
0x004ccbc0: 0x004cb715
0x004ccbc4: 0x004cb776
0x004ccbc8: 0x004cb7d7
0x004ccbcc: 0x004cb861
0x004ccbd0: 0x004cbb84
0x004ccbd4: 0x004cbbe5
0x004ccbd8: 0x004cbc46
0x004ccbdc: 0x004cbca7
0x004ccbe0: 0x004cbd31
0x004ccbe4: 0x004cc054
0x004ccbe8: 0x004cc0b5
0x004ccbec: 0x004cc116
0x004ccbf0: 0x004cc177
0x004ccbf4: 0x004cc201
0x004ccbf8: 0x004cc524
0x004ccbfc: 0x004cc585
0x004ccc00: 0x004cc5e6
0x004ccc04: 0x004cc647
0x004ccc08: 0x004cc6d1
0x004ccc0c: 0x004cc9f4
0x004ccc10: 0x004cca55
0x004ccc14: 0x004ccab6
0x004ccc18: 0x004ccb17
```

### Source-facing interpretation

Outer switch:

- `jpt_4CB035` at `0x004ccba0`, 6 entries, keyed by `_wtol(m_statValueTextBuffers[13])`.
- Case `0`: any-class requirement path. If tier is also `0`, draw `Any Class`, `   Level `, row 15 level text, and ` Req `.
- Case `1`: Warrior requirement path.
- Case `2`: Rogue requirement path.
- Case `3`: Mage requirement path.
- Case `4`: Poet requirement path.
- Case `5`: Archer requirement path.

Nested switches:

- Keyed by `_wtol(m_statValueTextBuffers[14])`.
- Tier `0`: draw full class name plus `   Level `, row 15 level text, and ` Req `.
- Tier `1`: draw `Il San` class abbreviation label.
- Tier `2`: draw `Ee San` class abbreviation label.
- Tier `3`: draw `Sam San` class abbreviation label.
- Tier `4`: draw `Sa San` class abbreviation label.

Nested table mapping:

| Table | Class | Entries |
| --- | --- | --- |
| `0x004ccbb8` / `jpt_4CB38E` | Warrior | tier 0 `Warrior`, tier 1 `Il San (W)`, tier 2 `Ee San (W)`, tier 3 `Sam San (W)`, tier 4 `Sa San (W)` |
| `0x004ccbcc` / `jpt_4CB85A` | Rogue | tier 0 `Rogue`, tier 1 `Il San (R)`, tier 2 `Ee San (R)`, tier 3 `Sam San (R)`, tier 4 `Sa San (R)` |
| `0x004ccbe0` / `jpt_4CBD2A` | Mage | tier 0 `Mage`, tier 1 `Il San (M)`, tier 2 `Ee San (M)`, tier 3 `Sam San (M)`, tier 4 `Sa San (M)` |
| `0x004ccbf4` / `jpt_4CC1FA` | Poet | tier 0 `Poet`, tier 1 `Il San (P)`, tier 2 `Ee San (P)`, tier 3 `Sam San (P)`, tier 4 `Sa San (P)` |
| `0x004ccc08` / `jpt_4CC6CA` | Archer | tier 0 `Archer`, tier 1 `Il San (A)`, tier 2 `Ee San (A)`, tier 3 `Sam San (A)`, tier 4 `Sa San (A)` |

Rejected alternatives:

- The outer switch is not item type or stat type. It is keyed from row 13, which is populated as a class requirement code and immediately paired with class names.
- The nested switches are not protection or durability tiers. They are keyed from row 14 and select Korean ascension-rank labels with class abbreviations.
- The `Any Class` path only has source meaning when tier is zero. Invalid class/tier combinations fall out or return without drawing a final requirement row.

## Read-only literal/resource mapping

[UID:00025G] should cross-link these literals to `ItemHelpPane::OnPaintFrame`:

- `Owner `
- `PROTECTED (%d)`
- `Any Class`
- `   Level `
- ` Req `
- `Warrior`, `Rogue`, `Mage`, `Poet`, `Archer`
- `Il San`, `Ee San`, `Sam San`, `Sa San` class-abbreviation variants for `(W)`, `(R)`, `(M)`, `(P)`, `(A)`
- Stat labels populated by [UID:0003PS] and consumed here: `Value`, `Durability`, `Armor`, `Hit`, `Damage`, `Vitality increase`, `Mana increase`, `Might increase`, `Grace increase`, `Will increase`, `Wisdom increase`, `Con`, `Regen`, `Protection`

Do not move these literals into the method doc as if they were inline data. They are support/read-only data consumed by the method.

## Heuristic / inference reanalysis and validation

### Method name and signature

Best name: `ItemHelpPane::OnPaintFrame()`.

Evidence:

- Vtable slot route is the paint slot in the primary `ItemHelpPane` vtable.
- Existing class docs already list `OnPaintFrame`.
- The method performs pane paint/frame/text rendering and has no meaningful return value.
- Generated IDA `int __thiscall(int this)` is a byproduct of default decompiler typing. Ghidra `undefined __thiscall virt_meth_0x4c8bd0(ItemHelpPane *this)` is closer to the no-return-value source shape.

Rejected alternatives:

- `Paint`, `Render`, or `DrawTooltip`: acceptable descriptive aliases, but less consistent with existing pane virtual names and class docs.
- `ItemHelpPaneOnPaintFrame` as a source name: use only for doc filename/coverage row. Source-facing method should be `ItemHelpPane::OnPaintFrame`.
- `int` return type: rejected as source-facing shape. Tail expressions and decompiler artifacts do not establish an integer return contract for a paint virtual.

### Source placement

Best current placement: `HelpPanes` / `NexusTK/ui/controls/HelpPanes.cpp`, owned by `ItemHelpPane`.

Reasoning:

- Current class and by-file docs route ItemHelpPane through `HelpPanes`.
- The generated route `auto-generated/NexusTK/ui/controls/HelpPanes.cpp` already contains empty emitter markers for the class and its children.
- The source body depends on GrafPort and Surface helpers, but those are UI infrastructure dependencies, not ownership.
- The method also depends on item metadata populated by [UID:0003PS], but the paint body consumes already-populated fields and does not perform direct MetaMan lookup.

Future split recommendation:

- If source-tree refinement later splits broad `HelpPanes.cpp`, move the whole `ItemHelpPane` class family to `NexusTK/ui/controls/ItemHelpPane.cpp`. Do not split only `OnPaintFrame`; keep constructor/destructor/timer/mouse/populate/count-lines with the class.

### ItemHelpPane field names

The field names above are high-probability source names derived from cross-method use:

- Constructor and populate pages fill display name, owner, description, protection, stat labels, and `m_statValueTextBuffers`.
- Destructor support notes already identify `+0x62c` as the allocated stat-value text buffer table.
- Paint consumes those fields in the same literal order and display order.

Rejected alternatives:

- `m_secondaryName` for `+0x208`: rejected. The paint literal and item-slot copy path show owner name semantics.
- `m_durability` for `+0x308`: rejected. Paint formats `+0x308` as `PROTECTED (%d)`. Durability/state belongs to `+0x104` and stat row 2.
- `m_pItemData` for `+0x62c`: rejected. The table is a display text-buffer table, not an opaque item-data pointer.

### GrafPort/text helper names

The helper names are no longer blockers:

- Text width, line height, and draw-text helpers are already source-quality in GrafPort support docs.
- `0x004b9680` should be called a text color setter, not a background color setter.
- `0x0041b9b0` should be called a wide safe-formatting wrapper. Do not leave it as `sub_41B9B0`.
- `unknown_libname_24` should be called `_wtol`.

Remaining uncertainty:

- The exact source name for the surface callback at `0x0069b3fc` is not recoverable from this method alone. Best prose: "SurfaceRenderCallbackTable slot 7, used here as the pane-rectangle fill/invalidate/presentation callback." Do not use the stale generated alias `g_pfnLockSurface`.

### Jump-table source meaning

Resolved. The jump tables implement class and ascension-tier requirement rendering, not a generic item-stat switch. The outer table uses the class requirement code; nested tables use the tier/ascension requirement code.

### Subsplit policy

No additional split is recommended:

- The stat-row fragments are ordinary repeated code inside one method.
- The requirement labels are branch labels inside one switch nest.
- The existing [UID:0003PO] split is the only non-code split needed.

Rejected alternatives:

- Create one doc per switch case: rejected as artificial compiler-label fragmentation.
- Create a separate "requirement renderer" child: rejected because no call boundary exists.
- Merge [UID:0003PO] into target: rejected because the dwords are non-executable compiler output after the method return.

### C++ readiness and exact defer proof

The target is source-authored and reconstructable, but formal C++ should remain blank for the first implementation callback.

This is not a no-code/generated-binary proof. It is a target-specific first-draft defer proof:

- The body is one `0x3fd0`-byte paint method with many repeated text-measure and draw fragments. A literal draft would be very large and would encode unresolved support-doc layout names directly into formal code.
- The behavior is now resolved, but several source-facing class-layout names still need to be accepted into [UID:00006U] and [UID:0003PS]. Entering a large formal block before those support docs are aligned would either keep raw offsets or use names that later need churn.
- A readable source-style draft naturally wants small helpers such as `DrawCenteredLabelValue`, `DrawRequirementTriplet`, or `DrawAscensionRequirement`. The binary has no ordinary call boundaries for these helpers. They may have been inlined, macro-expanded, or never existed. The support docs need to accept an "inlined source helper/macro" policy before formal C++ uses those abstractions.
- The jump-table mapping is now strong enough for prose and later source code, but the exact original source spelling of class/tier enums is still inferred. Formal C++ should avoid inventing enum names until the class/source support docs agree on `ItemClassRequirement` and `ItemAscensionRequirement` names.

Recommended implementation order:

1. First callback: update [UID:0003PN], [UID:0003PO], [UID:00006U], [UID:0003PS], [UID:0003PT], [UID:00025G], and [UID:0000N4] with the resolved behavior, field map, helper map, and switch map. Keep [UID:0003PN] formal C++ blank with this defer proof.
2. Later C++ callback: after field/support names are accepted, populate [UID:0003PN] with a source-style draft that uses either accepted inline helper names or a deliberately unrolled row-drawing structure.

The following source-shape sketch is suitable for documentation prose and later implementation planning, but it is not recommended as the target's formal C++ block yet:

```cpp
void ItemHelpPane::OnPaintFrame()
{
    RectBounds frame;
    GetClipRect(&frame);

    SetDrawColor(0x97);
    g_surfaceRenderCallbacks.FillOrInvalidate(&frame);

    SetDrawColor(0x80);
    DrawRectFrame(&frame);

    const int left = frame.left + 10;
    const int top = frame.top + 10;
    const int right = frame.right - 10;
    const int bottom = frame.bottom - 10;
    const int centerX = (left + right) / 2;
    const int lineHeight = GetLineHeight();

    DrawTitleWithShadow(m_itemDisplayName, left, top, right);

    int row = 0;
    if (!IsEmptyOrPlaceholder(m_helpDescription)) {
        DrawDescription(m_helpDescription, left, top + lineHeight * 2, right, bottom);
        row += CountTextLines(m_helpDescription) + 3;
    }

    if (!m_isEquipmentItem) {
        DrawSimpleItemRows(centerX, row, m_hasItemInstanceState, m_currentDurability);
        return;
    }

    DrawEquipmentStatRows(centerX, row);
    DrawOwnerAndProtectionRows(centerX, row);

    const int classReq = _wtol(m_statValueTextBuffers[13]);
    const int tierReq = _wtol(m_statValueTextBuffers[14]);
    DrawRequirementRows(centerX, row, classReq, tierReq, m_statValueTextBuffers[15]);
}
```

The actual later formal code should either expand the helper calls above into the observed measure/draw fragments or document that the helpers represent accepted inline/macro source shape. Do not submit this sketch directly as reconstruction C++.

## IDA rename/type/comment recommendations

Recommended renames:

- `sub_4C8BD0` -> `ItemHelpPane_OnPaintFrame` or method name `ItemHelpPane::OnPaintFrame`.
- `jpt_4CB035` -> comment/name as `ItemHelpPane_OnPaintFrame_ClassRequirementSwitch`.
- `jpt_4CB38E` -> `ItemHelpPane_OnPaintFrame_WarriorTierSwitch`.
- `jpt_4CB85A` -> `ItemHelpPane_OnPaintFrame_RogueTierSwitch`.
- `jpt_4CBD2A` -> `ItemHelpPane_OnPaintFrame_MageTierSwitch`.
- `jpt_4CC1FA` -> `ItemHelpPane_OnPaintFrame_PoetTierSwitch`.
- `jpt_4CC6CA` -> `ItemHelpPane_OnPaintFrame_ArcherTierSwitch`.
- `sub_41B9B0` -> `swprintf_s_wrapper` or `WideSprintfS`.
- `unknown_libname_24` -> `_wtol`.

Recommended type/comment work:

- Type `0x004c8bd0` as `void __thiscall ItemHelpPane::OnPaintFrame(ItemHelpPane *this)` in IDA-style notation.
- Add a comment at vtable slot `0x0061ae48`: `ItemHelpPane::OnPaintFrame`.
- Add struct comments for offsets `+0x188`, `+0x208`, `+0x288`, `+0x308`, and `+0x62c`.
- Add comments to row-index reads from `m_statValueTextBuffers[13]`, `[14]`, and `[15]` identifying class requirement, tier requirement, and level requirement text.
- Add a warning comment on the `0x0069b3fc` callback use: generated alias `g_pfnLockSurface` is not source-quality for this paint-site role.

## Support-doc update checklist

### Target: `by-memory/0x004c8bd0-0x004ccba0.ItemHelpPaneOnPaintFrame.md`

Update:

- Metadata to `COMPLETION:88`, `CONFIDENCE:90`.
- Status to "source-authored virtual `ItemHelpPane::OnPaintFrame()` method, vtable-reachable through `0x0061ae48`."
- Keep `CANONICAL_OWNER:00006U`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:00006U`.
- Add exact boundary and split facts:
  - method `0x004c8bd0-0x004ccba0`;
  - switch tables [UID:0003PO] `0x004ccba0-0x004ccc1c`;
  - padding `0x004ccc1c-0x004ccc20`;
  - next method [UID:0003PP] at `0x004ccc20`.
- Replace stale "field/helper-name blockers" with:
  - resolved helper map;
  - field map;
  - stat-value row semantics;
  - requirement switch mapping;
  - formal C++ defer proof.
- Keep `RECONSTRUCTION_CPP` blank for now.

### Switch data: `by-memory/0x004ccba0-0x004ccc1c.ItemHelpPaneOnPaintFrameJumpTables.md`

Update:

- Consider score to `COMPLETION:88`, `CONFIDENCE:92`.
- Keep `RECONSTRUCTABLE:FALSE`, no emitter, no formal C++.
- Add the 31 exact dword entries from this report.
- Add the source meaning:
  - outer class requirement switch keyed by row 13;
  - nested tier/ascension switches keyed by row 14;
  - class names and ascension labels for Warrior/Rogue/Mage/Poet/Archer.
- Keep the `0x004ccc1c-0x004ccc20` padding note.

### Class doc: `by-class/ItemHelpPane.md`

Update:

- Add method signature `void OnPaintFrame();`.
- Add class layout facts:
  - `m_isEquipmentItem` at `+0x100`;
  - `m_hasItemInstanceState` at `+0x101`;
  - `m_currentDurability` at `+0x104`;
  - `m_itemDisplayName` at `+0x188`;
  - `m_ownerName` at `+0x208`;
  - `m_helpDescription` at `+0x288`;
  - `m_protectionCount` at `+0x308`;
  - stat label buffers at `+0x334` through `+0x5b4`;
  - `m_statValueTextBuffers` at `+0x62c`.
- Add `OnPaintFrame` behavior summary with title, description, simple item, equipment stats, owner, protection, and requirement sections.
- Add the source-file route note: current route `HelpPanes.cpp`; future class split candidate `ItemHelpPane.cpp`.

### Source-file doc: `by-file/HelpPanes.md`

Update:

- Add [UID:0003PN] as the source-owned `ItemHelpPane::OnPaintFrame` method.
- Add dependency summary: GrafPort drawing/text helpers, SurfaceRenderCallbackTable slot `0x0069b3fc`, ItemHelpPane count-lines helper, read-only item-help strings.
- Add note that [UID:0003PO] is generated switch data for this source method and should remain non-emitting.
- Add future split guidance: if `ItemHelpPane.cpp` is created, move the whole ItemHelpPane family, not this method alone.

### Populate helper: `by-memory/0x004ccca0-0x004ce0f6.ItemHelpPanePopulateItemData.md`

Update:

- Align populated field names with this report:
  - display name, owner name, description, protection count;
  - current durability/state;
  - stat label buffers;
  - `m_statValueTextBuffers`.
- Add row-index contract for rows 1 through 17, especially rows 13, 14, and 15.
- Mark [UID:0003PN] as the main consumer of the populated display table.
- Clarify `+0x308` as protection count, not durability.

### Count-lines helper: `by-memory/0x004ce100-0x004ce160.ItemHelpPaneCountTextLines.md`

Update lightly:

- Keep source-facing helper name `ItemHelpPane::CountTextLines` or `CountWrappedTextLines` only if class docs later standardize the longer name.
- Add that [UID:0003PN] calls it twice for `m_helpDescription` at `0x004c8e39` and `0x004c8e68`.
- Do not overstate it as a generic GrafPort method; it is an ItemHelpPane layout helper using shared text measurement.

### Read-only data: `by-memory/0x0061aad4-0x0061b340.HelpItemHelpReadOnlyData.md`

Update:

- Add [UID:0003PN] as consumer of owner/protection/class/tier/level requirement strings.
- Add [UID:0003PS] as producer/populator of stat labels and [UID:0003PN] as consumer/drawer of those labels.
- Preserve rdata/no-code policy for strings and vtables.

### GrafPort and Surface support docs

Update only if not already present:

- GrafPort draw-state accessor doc should identify `0x004b9680` as the primary text color setter, not a background color setter.
- SurfaceRenderCallbackTable doc should note [UID:0003PN] calls slot `0x0069b3fc` as a rectangle fill/invalidate/presentation dependency and should flag `g_pfnLockSurface` as a stale generated alias for this call site.

## Exact coverage row replacement

Do not edit `by-memory/-coverage-report.md` during this B report. If the supervisor accepts implementation, replace the current `0003PN` row with:

```text
        - [UID:0003PN][0x004c8bd0-0x004ccba0.ItemHelpPaneOnPaintFrame](by-memory/0x004c8bd0-0x004ccba0.ItemHelpPaneOnPaintFrame.md) 0x004c8bd0-0x004ccba0 | method | ItemHelpPane::OnPaintFrame : reconstructable : 88% : strong : B006 source-quality pass confirms the exact 0x3fd0-byte vtable-only ItemHelpPane paint method at primary vtable slot 0x0061ae48, keeps the generated jump-table data split to UID:0003PO, resolves GrafPort/text/SurfaceRender helper roles, maps item display/description/value/durability/stat/owner/protection drawing, maps the 31-entry class/tier requirement switch, names the ItemHelpPane display fields and stat-value rows, and keeps formal C++ deferred until accepted support docs lock the large unrolled paint-body source shape.
```

Replace the current `0003PO` row with:

```text
        - [UID:0003PO][0x004ccba0-0x004ccc1c.ItemHelpPaneOnPaintFrameJumpTables](by-memory/0x004ccba0-0x004ccc1c.ItemHelpPaneOnPaintFrameJumpTables.md) 0x004ccba0-0x004ccc1c | switch table | ItemHelpPaneOnPaintFrameJumpTables : not_reconstructable : 88% : very-strong : Compiler-emitted switch data for `ItemHelpPane::OnPaintFrame`; raw PE decodes 31 dwords as one outer class-requirement switch over stat row 13 plus five nested tier/ascension switches over stat row 14, mapping Warrior/Rogue/Mage/Poet/Archer tier labels from `Warrior` through `Sa San (A)`, with all entries targeting labels inside UID:0003PN and trailing `0x004ccc1c-0x004ccc20` padding before the timer handler.
```

## Validation commands for implementation pass

Run from `source-3/project-documentation` after any accepted implementation callback:

> Executable block R001 was removed from this report and preserved verbatim in [0003PN-ItemHelpPaneOnPaintFrame-source-quality-removed.md](0003PN-ItemHelpPaneOnPaintFrame-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Expected validation outcome:

- [UID:0003PN] passes with updated score, source-owner route, support links, and explicit C++ defer proof.
- [UID:0003PO] passes as non-reconstructable no-code switch data with no emitter.
- Support docs retain consistent field names and no duplicate emission scope.
- Coverage row update remains supervisor-owned unless explicitly authorized.

## Exact implementation checklist for callback

If the supervisor sends an implementation callback, apply these changes:

1. Update `source-3/project-documentation/by-memory/0x004c8bd0-0x004ccba0.ItemHelpPaneOnPaintFrame.md`.
   - Set score to `88/90`.
   - Keep owner/emitter as [UID:00006U].
   - Add method signature, boundary/xref facts, helper map, field map, stat-row map, behavior summary, switch mapping, rejected alternatives, and C++ defer proof.
   - Keep formal C++ blank.
2. Update `source-3/project-documentation/by-memory/0x004ccba0-0x004ccc1c.ItemHelpPaneOnPaintFrameJumpTables.md`.
   - Keep non-emitting/no-code.
   - Add exact dword list and source meaning of every table.
   - Optionally set score to `88/92`.
3. Update `source-3/project-documentation/by-class/ItemHelpPane.md`.
   - Add method signature and class field/source-layout recommendations.
   - Add OnPaintFrame behavior and dependency summary.
4. Update `source-3/project-documentation/by-file/HelpPanes.md`.
   - Add source-placement and future `ItemHelpPane.cpp` split note.
   - Add [UID:0003PN]/[UID:0003PO] emission policy.
5. Update `source-3/project-documentation/by-memory/0x004ccca0-0x004ce0f6.ItemHelpPanePopulateItemData.md`.
   - Align field names and row semantics.
6. Update `source-3/project-documentation/by-memory/0x004ce100-0x004ce160.ItemHelpPaneCountTextLines.md`.
   - Add caller/use facts from [UID:0003PN].
7. Update `source-3/project-documentation/by-memory/0x0061aad4-0x0061b340.HelpItemHelpReadOnlyData.md`.
   - Add literal-to-paint mappings.
8. Update GrafPort/Surface support docs only if they still carry stale aliases.
9. Do not edit `by-memory/-coverage-report.md` unless the supervisor explicitly includes coverage implementation authority. If authorized, use the exact replacement rows above.
10. Run the scoped validators above.

## Open questions closed or bounded

| Question | Resolution |
| --- | --- |
| Is the function boundary exact? | Yes. Exported size, existing live IDA notes, and PE bytes all support `0x004c8bd0-0x004ccba0`; following bytes are switch data and padding. |
| Is [UID:0003PO] executable code? | No. It is 31 code-pointer dwords plus separate padding before the timer method. |
| What is the source method name? | `ItemHelpPane::OnPaintFrame()`. |
| Is there a direct caller? | No ordinary direct caller is expected; vtable data xref at `0x0061ae48` proves virtual reachability. |
| What does the switch table do? | It renders class/tier/level requirements using class code row 13 and tier code row 14. |
| What is `unknown_libname_24` here? | `_wtol`, parsing requirement code text. |
| What is `sub_41B9B0` here? | Wide safe formatting wrapper compatible with `swprintf_s`. |
| What is field `+0x62c`? | `m_statValueTextBuffers`, a fixed table of allocated text rows. |
| Should formal C++ be emitted now? | Not in the first callback. The behavior is reconstructable, but the large unrolled source shape should wait for accepted support field names and helper/macro policy. |
| Are more splits needed? | No. Only the existing switch-table split is needed. |

## Implementation readiness

Ready for supervisor implementation callback as a report-only B006 source-quality pass.

Recommended callback scope:

1. Update target and named support docs with the resolved evidence.
2. Keep [UID:0003PN] formal C++ blank with target-specific defer proof.
3. Keep [UID:0003PO] no-code.
4. Apply exact coverage rows only if supervisor authorizes coverage edit.
5. Run scoped validator file mode with `--apply --queue-timeout 240`.

## Final status

FINISHED

Report path: `source-3/project-documentation/tools/leaser/Agents/Agent-B006/research/0003PN-ItemHelpPaneOnPaintFrame-source-quality.md`

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"command_id":"000000004167","details":"report marked for revalidation","event":"needs-revalidation","issue":"target_uid_unknown: 0003PN","source_path":"executed-b-agent-research/B006/0003PN-ItemHelpPaneOnPaintFrame-source-quality.md","timestamp":"2026-07-01T19:52:03-04:00"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
