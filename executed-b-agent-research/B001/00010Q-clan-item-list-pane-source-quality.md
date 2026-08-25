** TARGET-REPORT-UID:00010Q **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# B001-goal2-clan-item-list-pane-source-quality-00010Q-20260616

Agent: B001
Target: [UID:00010Q] `by-memory/0x0048ae70-0x0048b1b1.ClanItemListPane.md`
Assignment: `B001-goal2-clan-item-list-pane-source-quality-00010Q-20260616`
Status: report-only source-quality/source-inference audit

## Decision

Raise [UID:00010Q] from `82/88` to `85/90`.

Keep:
- `CANONICAL_OWNER: 00002G`
- `EMITTER_UIDS: 00002G`
- `RECONSTRUCTABLE: TRUE`
- final C++ blank

Reason: the class method ownership, constructor caller, packet row parser, draw method dependency chain, and raw helper byte semantics are now independently validated. The item-list record and source placement can be named defensibly enough for 85+ source-quality. Do not raise above this yet because the retained helper island at `0x0048b090-0x0048b09e` has no inbound VA/RVA/rel32 route in the binary, the constructor decompile still has a compiler/control-flow artifact around the slot-publication loop, and final source-facing ListPane API names are inferred rather than recovered.

## Inputs Inspected

Required workflow docs:
- `tools/leaser/Agents/Supervisor.md`
- `tools/leaser/Agents/Supervisor_notes.md`
- `tools/leaser/Agents/SupervisorAssignments.md`
- `tools/leaser/Agents/Agent-B001/goal.md`
- `tools/leaser/Agents/Agent-B001/notes.md`

Target/support docs:
- `by-memory/0x0048ae70-0x0048b1b1.ClanItemListPane.md`
- `by-class/ClanItemListPane.md`
- `by-class/ClanWidItemDialog.md`
- `by-class/ClanDepItemDialog.md`
- `by-file/ClanBank.md`
- `by-file/Clan.md`
- `by-memory/0x0048a810-0x0048ae65.ClanWidItemDialog.md`
- `by-memory/0x0048a1c0-0x0048a805.ClanDepItemDialog.md`
- `by-memory/0x004ba820-0x004ba991.TextFitAndSuffixHelpers.md`
- `by-memory/-ignored.md`
- `by-memory/-coverage-report.md`
- `auto-generated/by-memory-tool-report.md`
- `auto-generated/-ag-memory-coverage.md`
- `project-level/-auto-completion-stats.md`

Additional local support checked:
- `by-memory/0x004aec80-0x004aec8e.MyItemListPaneGetSelectedSlotIndex.md`
- `by-structure.md`
- `by-project-structure/proposed-source-tree.md`
- `tools/leaser/Agents/Agent-B001/inference_research.md`

## Evidence Summary

IDA opened `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe` read-only through MCP session `b001_00010q_20260616`. Reported image base was `0x00400000`; Hex-Rays and auto-analysis were ready.

Function/range facts:
- `0x0048ae70` is `sub_48AE70`, size `0x21c`.
- `0x0048b090-0x0048b09e` is not an IDA function.
- `0x0048b0a0` is `sub_48B0A0`, size `0x111`.
- `0x0048b0a0` has vtable/data reference at `0x0061623c`.
- Padding/support rows still frame the target cleanly: ignored padding before `0x0048ae65-0x0048ae70` and after `0x0048b1b1-0x0048b1c0`.

Constructor evidence:
- Single direct constructor caller: `0x0048ab68` inside `ClanWidItemDialog` range.
- The constructor calls `sub_4F3A50((int)this, 516, 8, 205, 24, 0, 1, 1)`, confirming an item-list row payload size of `0x204` bytes (`516`).
- Vtable stores are present around `0x0048aedb`, `0x0048aee1`, and `0x0048aeeb`.
- Packet parse order is recoverable: count byte, slot byte, 16-bit item id read through `0x00575480`, name-length byte, byte copy through `0x00516220`, null termination, and `MultiByteToWideChar` conversion into a wide display name.
- The per-slot cache uses an active byte, item id word, and wide name buffer. Slot-derived offsets follow the existing doc's stride model and support source-facing fields like `slotIndex`, `itemId`, `displayName`, and `active`.
- Active records are republished as `0x204`-byte ListPane entries and inserted through `sub_4F3C50`.

Draw method evidence:
- `0x0048b0a0` checks row selection state with `sub_4F3F00(this, row)`.
- It draws item icon/name data from the row entry: the item id is at entry offset `+2`, and the wide display name begins at entry offset `+4`.
- It calls shared GrafPort/text helpers, including the text-fit helper at `0x004ba820`, then draws the fitted text. This is dependency evidence, not ClanItemListPane ownership evidence.

## Heuristic / Inference Reanalysis And Validation

### Source-facing type and field names

Best defensible row type:

```cpp
struct ClanItemListEntry {
    uint8_t slotIndex;
    uint8_t reservedOrPadding;
    uint16_t itemId;
    wchar_t displayName[256];
};
```

Validation:
- The constructor publishes `0x204` bytes per row, matching `1 + 1 + 2 + 512`.
- The draw method reads `*(WORD *)(entry + 2)` for the item id.
- The draw method copies/renders the wide string beginning at `entry + 4`.
- The selected-entry helper returns the first byte of the selected entry, matching `slotIndex`.

Rejected alternatives:
- `slotId` is possible, but `slotIndex` is preferred because `ClanWidItemDialog` consumes it as the source bank slot for the withdraw packet and sibling documentation names the same byte as a selected slot index.
- `itemNo`/`itemNum` is possible, but `itemId` is preferred because the value is passed to icon/metadata lookup (`sub_4DF460`) and behaves as a catalog identifier.
- `char name[256]` is rejected for the ListPane row payload because draw reads a wide string at `entry + 4`; MBCS packet bytes are only an input representation before `MultiByteToWideChar`.

### Constructor packet row parsing

Best source interpretation:
- Packet byte 0 is an entry count.
- Each entry contains slot byte, item id word, byte-length MBCS item name, and item name bytes.
- Parsed entries populate an internal 256-slot cache keyed by slot byte.
- Active cache slots are republished into visible ListPane rows.

Validation:
- The constructor's `516` row size and draw offsets match the republished row type exactly.
- The helper `0x00575480` is used at the 16-bit item id read point.
- `MultiByteToWideChar` appears after byte-name copy and null termination, matching packet MBCS to UI UTF-16 conversion.

Unresolved compiler artifact:
- Hex-Rays represents the active-slot publication loop with a suspicious `cmp eax, 0x100` / `jbe` shape after an 8-bit increment. This is a decompiler/control-flow artifact or optimized bounded byte loop. It does not change the row format evidence, but it blocks final C++.

### Selected-entry/raw helper island

Raw bytes at `0x0048b090-0x0048b09e`:

```asm
FF B1 34 01 00 00    push dword ptr [ecx+134h]
E8 25 8D 06 00       call 004F3DC0
8A 00                mov al, [eax]
C3                   ret
```

Best source-facing name if retained:
- `ClanItemListPane::GetSelectedSlotIndexRaw`
- Acceptable alternate: `ClanItemListPane::GetSelectedSlotIndex`

Validation:
- `0x004f3dc0` loads the ListPane storage object from `[ecx+0x130]` and tail-jumps through vtable slot `+0x10`.
- The helper passes `[this+0x134]`, then returns the first byte of the selected row. For the reconstructed row type, that byte is `slotIndex`.
- Sibling [UID:0002JP] `MyItemListPaneGetSelectedSlotIndex` has the same semantic byte shape and active caller evidence.

Rejected alternatives:
- Padding/alignment is rejected: the bytes form a coherent call/return helper, the relative call resolves to a live generic ListPane selected-entry accessor, and the byte load matches the row type.
- Active public API method is not proven: IDA has no function at the raw island and no direct binary route to the island start.

### Raw no-function/no-xref liveness

This was checked beyond IDA's "no xref" statement.

Independent PE scan facts:
- Image base: `0x00400000`.
- `.text`: VA `0x00401000-0x0060c600`, raw `0x400+0x20b600`.
- File offsets:
  - `0x0048b090` -> file `0x8a490`
  - `0x0048b09e` -> file `0x8a49e`
  - `0x0048b0a0` -> file `0x8a4a0`
  - `0x0048ae70` -> file `0x8a270`
  - `0x004f3dc0` -> file `0xf31c0`
- Absolute VA/RVA scan found no pointer to `0x0048b090` or `0x0048b09e`.
- Relative branch/call scan found no inbound `rel32` target to `0x0048b090` or `0x0048b09e`.
- Sanity checks succeeded:
  - VA pointer to draw method `0x0048b0a0` exists at file `0x214c3c` / VA `0x0061623c`.
  - Constructor `0x0048ae70` has one rel32 call at `0x0048ab68`.
  - Generic selected-entry thunk `0x004f3dc0` has 98 rel32 hits, including from the raw island at `0x0048b096`, from `ClanWidItemDialog` action logic at `0x0048ad99`, and from sibling selected-slot helper `0x004aec86`.

Conclusion:
- The raw island is source-shaped and semantically meaningful, but no live inbound route was found in vtables, absolute pointers, RVAs, or rel32 calls. Score can rise because semantics are validated; final C++ should remain blank because liveness/source emission of this exact helper is not proven.

### Relationship to ClanDepItemDialog and ClanWidItemDialog

`ClanWidItemDialog`:
- Owns the active constructor call to `ClanItemListPane` at `0x0048ab68`.
- Its action handler reads the selected row through the generic ListPane selected-entry thunk and sends the selected slot/quantity through the withdraw path.
- This validates `ClanItemListPane` as the withdraw/bank item picker.

`ClanDepItemDialog`:
- Uses the shared `MyItemListPane` deposit inventory picker, not this `ClanItemListPane`.
- It is contextual support for the item dialog family and source split, not a direct owner/caller of [UID:00010Q].

Best placement:
- Keep [UID:00010Q] routed through ClanBank ownership (`00002G`) and likely source `NexusTK/social/ClanBank.cpp`.
- A future split to `ClanItemDialogs.cpp` remains plausible because `ClanDepItemDialog`, `ClanWidItemDialog`, and `ClanItemListPane` form a dialog cluster. Current docs already identify this as a possible split, but the current auto-generated placement in `auto-generated/NexusTK/social/ClanBank.cpp` is defensible.
- Do not move to `Clan.cpp`: `by-file/Clan.md` is higher-level clan/social logic, while the target is bank/item-dialog UI code.

### Shared text-fit helper ownership

The draw method depends on `0x004ba820`, but [UID:00016B] should remain GrafPort/shared-helper owned.

Validation:
- `0x004ba820` has 21 callers.
- `0x004ba8b0` has 4 callers, including internal/helper fan-in.
- The helper uses receiver font/style state and FontImageLib-backed glyph measurement patterns according to the support doc.
- `ClanItemListPane` is one caller, not the owner.

Rejected alternative:
- Do not fold `TextFitAndSuffixHelpers` into `ClanItemListPane` or `ClanBank`; the fan-in and GrafPort behavior show shared UI text-rendering ownership.

## Exact Score, Metadata, And Final C++ Decisions

Recommended target metadata:

```yaml
COMPLETION: 85
CONFIDENCE: 90
RECONSTRUCTABLE: TRUE
CANONICAL_OWNER: 00002G
EMITTER_UIDS: 00002G
FINAL_CPP:
```

Final C++ decision:
- Leave final C++ blank.
- Do not emit decompiled C++ yet.

Reasons final C++ stays blank:
- Raw helper island is meaningful but has no proven inbound route.
- Constructor publication loop still has a decompiler artifact around byte-index termination.
- Final source-facing names for the inherited ListPane API (`sub_4F3A50`, `sub_4F3C50`, `sub_4F3DC0`, `sub_4F3F00`) remain inferred.
- Source file split between `ClanBank.cpp` and a possible `ClanItemDialogs.cpp` is not fully settled.

Why 85/90 and not lower:
- Constructor caller and vtable anchor are live.
- Packet schema and row payload size are independently supported by constructor and draw method.
- Selected-slot byte semantics are validated by the raw helper and by active `ClanWidItemDialog` selected-row consumption.
- Shared helper ownership has been separated from class ownership.

Why not above 85 completion:
- The raw helper remains a no-route island.
- Final C++ and exact source file split are unresolved.
- Several inherited ListPane helper names are still source-facing guesses.

## Supervisor Actions

1. Update [UID:00010Q] header metadata to `COMPLETION:85` and `CONFIDENCE:90`.
2. Keep `CANONICAL_OWNER:00002G`, `EMITTER_UIDS:00002G`, `RECONSTRUCTABLE:TRUE`, and blank final C++.
3. Add/update target notes with the constructor packet schema, row type, raw-helper no-route validation, ClanWid/ClanDep relationship, and GrafPort text-fit ownership split.
4. Replace the [UID:00010Q] row in `by-memory/-coverage-report.md` with the exact row below.
5. Add support-doc notes below if supervisor chooses to update support docs.
6. Run validator/rescore commands listed in this report after edits.

## Exact Coverage Row Replacement

Replace only the [UID:00010Q] row in `by-memory/-coverage-report.md` with:

```markdown
- [UID:00010Q][0x0048ae70-0x0048b1b1.ClanItemListPane](by-memory/0x0048ae70-0x0048b1b1.ClanItemListPane.md) 0x0048ae70-0x0048b1b1 | class methods | ClanItemListPane : reconstructable : 85% : strong : ClanItemListPane constructor, retained selected-slot raw helper, and draw virtual; B001 recheck confirms the single withdraw-dialog constructor caller, vtable draw/destructor anchors, packet row layout (`count`, slot byte, big-endian item id, byte-length MBCS name to UTF-16), `0x204`-byte list entry payload, GrafPort-owned text-fit dependency, and no VA/RVA/rel32 inbound route to the raw helper start; final C++ remains blank pending final ListPane API names and source rendering.
```

Optional dependency clarification row for [UID:00016B] if the supervisor updates text-fit dependency wording:

```markdown
- [UID:00016B][0x004ba820-0x004ba991.TextFitAndSuffixHelpers](by-memory/0x004ba820-0x004ba991.TextFitAndSuffixHelpers.md) 0x004ba820-0x004ba991 | methods | TextFitAndSuffixHelpers : reconstructable : 86% : strong : Shared GrafPort text fit/suffix helper pair; IDA confirms exact function extents, internal edge `0x004ba820 -> 0x004ba8b0`, broad `21`/`4` caller fan-in, receiver font/style state, FontImageLib-backed glyph measurement, and GrafPort owner/emitter route; ClanItemListPane uses this as a dependency, not as class-owned code.
```

## Support Doc Update Text

Suggested addition for `by-memory/0x0048ae70-0x0048b1b1.ClanItemListPane.md`:

```markdown
B001 source-quality recheck (2026-06-16): raise to 85/90. Constructor caller is the withdraw dialog at `0x0048ab68`; constructor initializes an inherited ListPane row size of `0x204`, parses packet rows as count, slot byte, 16-bit item id, byte-length MBCS name, converts names to UTF-16, and republishes active slots as `{slotIndex, reserved, itemId, wcharName[256]}` rows. Raw island `0x0048b090-0x0048b09e` is a coherent selected-slot helper (`push [ecx+0x134]`, call generic selected-entry thunk `0x004f3dc0`, return first row byte), but PE VA/RVA/rel32 scans found no inbound route to the island start, so final C++ remains blank. Draw virtual `0x0048b0a0` consumes item id at row `+2`, wide name at row `+4`, and uses GrafPort-owned text-fit helper `0x004ba820` as a dependency.
```

Suggested addition for `by-class/ClanItemListPane.md`:

```markdown
B001 [UID:00010Q] source-quality note (2026-06-16): source-facing row type is best modeled as `ClanItemListEntry { uint8_t slotIndex; uint8_t reservedOrPadding; uint16_t itemId; wchar_t displayName[256]; }`. `ClanWidItemDialog` is the confirmed active constructor/consumer; `ClanDepItemDialog` remains related dialog-family context but uses `MyItemListPane`. The selected-slot raw helper is retained/source-shaped but has no proven inbound binary route.
```

Suggested addition for `by-class/ClanWidItemDialog.md`:

```markdown
B001 [UID:00010Q] relationship note (2026-06-16): `ClanWidItemDialog` constructs `ClanItemListPane` at `0x0048ab68` and its OK/action path reads the selected row through the generic ListPane selected-entry thunk before sending withdraw slot/quantity data. This confirms `ClanItemListPane` as the withdraw-side bank item picker.
```

Suggested addition for `by-class/ClanDepItemDialog.md`:

```markdown
B001 [UID:00010Q] relationship note (2026-06-16): `ClanDepItemDialog` is source-family context for the clan item dialogs but does not construct [UID:00010Q]; it uses the shared `MyItemListPane` deposit inventory picker instead.
```

Suggested addition for `by-file/ClanBank.md`:

```markdown
B001 [UID:00010Q] placement note (2026-06-16): keep `ClanItemListPane` under ClanBank/source UID `00002G` for now. A later `ClanItemDialogs.cpp` split is plausible, but current evidence ties the pane to the bank withdraw dialog and auto-generated route `NexusTK/social/ClanBank.cpp`; do not move it to `Clan.cpp`.
```

Suggested addition for `by-memory/0x004ba820-0x004ba991.TextFitAndSuffixHelpers.md`:

```markdown
B001 [UID:00010Q] dependency note (2026-06-16): `ClanItemListPane::DrawListItem` calls `0x004ba820`, but the 21-caller fan-in and GrafPort/font measurement behavior keep this helper pair shared/GrafPort-owned. It should not be re-owned by ClanBank or ClanItemListPane.
```

## Validation Performed

IDA MCP checks performed:
- `lookup_funcs` for `0x0048ae70`, `0x0048b090`, `0x0048b09e`, `0x0048b0a0`, `0x0048c2ff`, `0x0048c30a`, `0x0048c510`, `0x004f3dc0`, `0x004ba820`, `0x004ba8b0`.
- `xrefs_to` for constructor, raw island bounds, draw method, destructor-related support, generic selected-entry thunk, and text-fit helpers.
- `decompile` for `0x0048ae70`, `0x0048b0a0`, and `0x0048ad10`.
- `disasm` for `0x0048b090-0x0048b09e` and `0x004f3dc0`.
- `make_signature_for_range(0x0048b090,0x0048b09e,wildcard=false)` returned `FF B1 34 01 00 00 E8 25 8D 06 00 8A 00 C3`.
- `analyze_component` for `0x0048ae70`, `0x0048b0a0`, `0x0048c510`, and `0x004f3dc0`.

PE scan performed:
- Parsed PE headers from `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`.
- Scanned for absolute VA pointers, RVA pointers, and `rel32` branch/call targets to `0x0048b090` and `0x0048b09e`.
- Sanity-checked positive hits for `0x0048b0a0`, `0x0048ae70`, and `0x004f3dc0`.

Validator dry run performed from `e:\NTK\GhidraBridge\source-3\project-documentation`:

> Executable block R001 was removed from this report and preserved verbatim in [00010Q-clan-item-list-pane-source-quality-removed.md](00010Q-clan-item-list-pane-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Result:
- dry run completed with `ok:1`
- no `--apply` was used
- no target/support docs were edited by B001

## Recommended Post-edit Validation Commands

After supervisor-owned edits, run:

> Executable block R002 was removed from this report and preserved verbatim in [00010Q-clan-item-list-pane-source-quality-removed.md](00010Q-clan-item-list-pane-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

## Final Recommendation

[UID:00010Q] is eligible for a defended 85+ raise. Use `85/90`, keep ClanBank ownership, leave final C++ blank, and update the coverage row exactly as provided.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B001","command_id":"000000004165","destination_path":"executed-b-agent-research/B001/00010Q-clan-item-list-pane-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:18","uid":"00010Q"} -->
<!-- {"agent":"B001","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 00010Q-clan-item-list-pane-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B001/00010Q-clan-item-list-pane-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"00010Q"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
