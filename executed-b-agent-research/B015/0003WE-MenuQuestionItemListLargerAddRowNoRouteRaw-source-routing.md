** TARGET-REPORT-UID:0003WE **
** AUTHOR-AGENT-ID:B015 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
** REPORT-VALIDATION-STATUS: needs-revalidation **
** REPORT-REVALIDATION-REASON: target_uid_unknown: 0003WE **
# 0003WE MenuQuestionItemListLargerAddRowNoRouteRaw Source-Routing Report

## Finalized Report / Current Recommendation

- Current recommendation: keep [UID:0003WE] `MenuQuestionItemListLargerAddRowNoRouteRaw` as exact no-owner/non-emitting raw code evidence.
- Final disposition: `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, blank formal C++.
- Required action: update the target/support docs with the stronger B015 no-code proof, row-record naming, active-constructor comparison, rejected generated routes, and route-scan positive controls. Do not assign the raw helper to `MenuQuestionItemListLarger` unless a future caller, pointer, vtable slot, or other runtime route to `0x00550f20` is proven.
- Score recommendation: raise documentation quality from `85/86` to `88/88`. The score is for evidence quality and no-code proof, not for emission eligibility.
- Confidence: high for behavior and non-emitting disposition; medium-low for original source liveness because no route is proven.

## Target

- Target UID: `0003WE`
- Target path: `source-3/project-documentation/by-memory/0x00550f20-0x00550f76.MenuQuestionItemListLargerAddRowNoRouteRaw.md`
- Required report path: `source-3/project-documentation/tools/leaser/Agents/Agent-B015/research/0003WE-MenuQuestionItemListLargerAddRowNoRouteRaw-source-routing.md`
- Current metadata: `COMPLETION:85`, `CONFIDENCE:86`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, blank emitters, blank C++.
- Current classification: raw source-shaped no-route helper candidate for the larger menu-question item list.

## Executive Recommendation

The raw bytes at `0x00550f20-0x00550f76` are a complete custom helper body that would be source-shaped as a private row append method:

```cpp
void MenuQuestionItemListLarger::AddRow(unsigned char optionId, const wchar_t *label);
```

or, with more descriptive source wording:

```cpp
void MenuQuestionItemListLarger::AppendOptionRow(unsigned char optionId, const wchar_t *label);
```

However, do not emit or assign the target now. The active larger dialog constructor at [UID:0003W4] already performs the same row-building sequence inline, and the raw out-of-line clone has no static route. The best current interpretation is retained dead/private helper code or an unreferenced out-of-line clone from the same source family, not a live class method.

If a future route is found, the best owner would be [UID:000080] `MenuQuestionItemListLarger` under [UID:0000LA] `MessageDialogs`. Until then, the exact by-structure-safe result is no-owner/non-emitting with a target-specific no-code proof.

## Evidence Checked

- Target/support documentation:
  - `by-memory/0x00550f20-0x00550f76.MenuQuestionItemListLargerAddRowNoRouteRaw.md`
  - `by-memory/0x00550dc0-0x00550e16.MenuQuestionItemListAddRowNoRouteRaw.md`
  - `by-memory/0x00550f80-0x00550f8e.MenuQuestionItemListLargerHasSelectableEntryNoRouteRaw.md`
  - `by-memory/0x00550ed0-0x00550f1f.MenuQuestionItemListLargerConstructor.md`
  - `by-memory/0x00550f90-0x00550f9b.MenuQuestionItemListLargerConfirmSelection.md`
  - `by-memory/0x00550fa0-0x00551021.MenuQuestionItemListLargerDrawRow.md`
  - `by-memory/0x0054fb30-0x00550afb.MenuQuestionDialogLargerConstructor.md`
  - `by-memory/0x00550b00-0x00550c30.MenuQuestionDialogLargerActionHandler.md`
  - `by-memory/0x00550c40-0x00550c7d.MenuQuestionDialogLargerUpdateConfirmButtonState.md`
  - `by-class/MenuQuestionItemListLarger.md`
  - `by-class/MenuQuestionItemList.md`
  - `by-class/MenuQuestionDialogLarger.md`
  - `by-class/MenuQuestionDialog.md`
  - `by-file/MessageDialogs.md`
  - `by-memory/0x0054ce10-0x00551021.NpcMessageAndMenuQuestionDialogs.md`
  - `by-memory/0x004f3bb0-0x004f3f20.ListPaneItemSelectionStorageHelpers.md`
  - `by-class/ListPane.md`
  - `by-file/ListPane.md`
- Prior B report:
  - `tools/leaser/Agents/Agent-B001/research/executed/older/0001FH-npc-message-menu-question-source-split.md`
- Generated/function-data leads checked as non-authoritative route clues:
  - `hooks-generation/tests/function_data/combined/functions/0x00550f20.json`
  - `hooks-generation/tests/function_data/combined/functions/0x0054fb30.json`
  - `resources/exported_data/functions/0x00550f20.json`
  - `source-3/simroot_v2/class_ChattingColorListPane.cpp.source_map.json`
- Raw PE evidence:
  - Image: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`
  - MD5: `4247E04E20B65D6414C7238AA8FF5515`
  - SHA256: `9AEC210BBC5CE592176A21DD8E9D9FD8F250B8D9EA78237915A99BA8CFA9A632`
  - Image base: `0x00400000`
  - `.text`: VA `0x00401000`, raw `0x00000400`, raw size `0x0020b600`
  - `.rdata`: VA `0x0060d000`, raw `0x0020ba00`

## Raw Bytes, Boundary, And Padding

Exact helper range: `0x00550f20-0x00550f76`, size `0x56`.

Boundary:

- `0x00550ed0-0x00550f1f`: live larger-list constructor [UID:0003WD].
- `0x00550f1f-0x00550f20`: one `0xcc` padding byte.
- `0x00550f20-0x00550f76`: this raw add-row helper.
- `0x00550f76-0x00550f80`: ten `0xcc` padding bytes.
- `0x00550f80-0x00550f8e`: sibling raw selected-entry probe [UID:0003WF].

Raw bytes:

```text
00550f20: 55 8B EC 81 EC 08 02 00 00 A1 24 2F 67 00 33 C5
00550f30: 89 45 FC 8B 55 0C 8A 45 08 56 52 88 85 F8 FD FF
00550f40: FF 8B F1 8D 85 FA FD FF FF 68 00 01 00 00 50 E8
00550f50: 03 C7 07 00 83 C4 0C 8D 85 F8 FD FF FF 8B CE 50
00550f60: E8 EB 2C FA FF 8B 4D FC 33 CD 5E E8 BF 67 07 00
00550f70: 8B E5 5D C2 08 00
```

Disassembly:

```asm
00550f20  push    ebp
00550f21  mov     ebp, esp
00550f23  sub     esp, 0x208
00550f29  mov     eax, dword ptr [0x00672f24]
00550f2e  xor     eax, ebp
00550f30  mov     dword ptr [ebp - 4], eax
00550f33  mov     edx, dword ptr [ebp + 0x0c]
00550f36  mov     al, byte ptr [ebp + 8]
00550f39  push    esi
00550f3a  push    edx
00550f3b  mov     byte ptr [ebp - 0x208], al
00550f41  mov     esi, ecx
00550f43  lea     eax, [ebp - 0x206]
00550f49  push    0x100
00550f4e  push    eax
00550f4f  call    0x005cd657 ; _wcscpy_s
00550f54  add     esp, 0x0c
00550f57  lea     eax, [ebp - 0x208]
00550f5d  mov     ecx, esi
00550f5f  push    eax
00550f60  call    0x004f3c50 ; ListPane::AddEntry / append item
00550f65  mov     ecx, dword ptr [ebp - 4]
00550f68  xor     ecx, ebp
00550f6a  pop     esi
00550f6b  call    0x005c772f ; __security_check_cookie
00550f70  mov     esp, ebp
00550f72  pop     ebp
00550f73  ret     8
```

The body is complete and source-shaped. It is not padding, a switch table, a thunk, or CRT code.

## Behavior And Source Shape

The helper receives:

- `ecx`: the `MenuQuestionItemListLarger` object, semantically a `ListPane`-derived object.
- `arg1` at `[ebp+8]`: one-byte menu option id / row id.
- `arg2` at `[ebp+0x0c]`: UTF-16 label pointer.

It builds a temporary row record on the stack:

- offset `+0`: one-byte `optionId`.
- offset `+1`: alignment/padding byte, not explicitly written by this helper.
- offset `+2`: `wchar_t label[0x100]`, copied by `_wcscpy_s(dest, 0x100, label)`.

Then it calls [UID:0003U0] `ListPane::AddEntry` / append item at `0x004f3c50`, passing the temporary row record pointer. The selected-entry/action path later consumes the first byte as the selected option id, while the row renderer reads the UTF-16 display label at `itemData+2`.

Recommended row type wording:

```cpp
struct MenuQuestionOptionRow
{
    unsigned char optionId;
    wchar_t label[0x100]; // naturally aligned at +2 by MSVC
};
```

Do not force a `uint16_t optionId` name. The helper writes only the low byte. The byte at `+1` is alignment/padding for the `wchar_t` label field.

If this helper becomes live later, a source-quality draft would be:

```cpp
void MenuQuestionItemListLarger::AddRow(unsigned char optionId, const wchar_t *label)
{
    MenuQuestionOptionRow row;
    row.optionId = optionId;
    wcscpy_s(row.label, 0x100, label);
    AddEntry(&row);
}
```

This draft is only a route-contingent reference. It should not be put into the target's formal C++ block under the current evidence.

## Route And Liveness Recheck

Raw PE route scan results for `0x00550f20`:

- Little-endian VA pointer hits: `0`.
- Little-endian RVA pointer hits: `0`.
- Little-endian raw-offset pointer hits: `0`.
- `.text` `E8`/`E9` rel32 call or jump hits: `0`.
- `.text` `0F 8x` rel32 conditional branch hits: `0`.

Sibling raw larger probe `0x00550f80` also has zero VA/RVA/raw pointer hits and zero rel32 branch hits.

Positive controls from the same scan:

- Live larger-list constructor `0x00550ed0` has rel32 call hits at `0x0054fd14` and `0x00550489` from `MenuQuestionDialogLarger` construction paths.
- Live larger-list selection delegator `0x00550f90` has a VA data ref at `.rdata` VA `0x00622874`.
- Live larger-list draw row `0x00550fa0` has a VA data ref at `.rdata` VA `0x00622878`.
- Normal draw row `0x00550e40` has a VA data ref at `.rdata` VA `0x006227b4`.

These positive controls show the scan finds nearby real routes. The lack of equivalent hits for `0x00550f20` is meaningful, not a tool failure.

Documentation/function-data route status:

- Current target and B001 split report say IDA does not model a function at `0x00550f20` and IDA xrefs are absent.
- The combined function-data JSON has Ghidra-only `meth_0x550f20` with zero callers and no IDA function. It also assigns the body to `ChattingColorListPane`, which is address-owner pollution and contradicts the `MessageDialogs` cluster, sibling helper, and surrounding live `MenuQuestionItemListLarger` methods.
- The active generated `MessageDialogs.cpp` omits [UID:0003WE], while it includes the live larger-list constructor, selection, draw, and vtable pages.

## Relationship To Live Larger Menu-Question Code

The live [UID:0003W4] `MenuQuestionDialogLarger` constructor performs the same source operation inline when it parses list labels:

- It allocates/constructs `MenuQuestionItemListLarger` through `sub_550ED0`.
- It reads a one-byte item count.
- For each byte-length-prefixed menu label, it copies the bytes to a temporary buffer, converts to UTF-16 with `MultiByteToWideChar`, stores `++optionIndex` into a two-byte local row prefix (`v84[0] = ++v83`), copies the UTF-16 label with `wcscpy_s(Destination, 0x100, Source)`, and calls `0x004f3c50` directly.

This is the same row-building pattern as the raw helper, but the constructor does not call `0x00550f20`. The likely source explanation is one of:

- a private helper existed in the original class but the constructor's call was inlined or duplicated, leaving an unreferenced out-of-line copy retained in the binary;
- an older/source-adjacent helper remained compiled into the object file but no longer has callers;
- a function-discovery artifact exposed valid code bytes that the linker did not route.

The least likely explanation is a missed ordinary call, because the rel32 scan found no direct calls and positive controls found nearby constructor routes. A computed function pointer route remains theoretically possible, but there is no vtable slot, no VA/RVA pointer, and no table evidence.

## Heuristic / Inference Reanalysis And Validation

| Issue | Evidence checked | Best-supported direction | Rejected alternatives | Impact |
| --- | --- | --- | --- | --- |
| Source-facing helper name | Raw body, normal sibling [UID:0003W9], live constructor row loop, draw/action consumers | If live, call it `MenuQuestionItemListLarger::AddRow` or `AppendOptionRow` | Keep `sub_550F20`; call it `ChattingColorListPane::meth_0x550f20`; generic `ListPane` method | Name is source-quality ready as a hypothetical, but not eligible for formal emitted C++. |
| Row record type | Store at stack row `+0`, label copy to `+2`, draw rows read `itemData+2`, action paths serialize selected row byte | `MenuQuestionOptionRow` / `MenuQuestionListRow` with `unsigned char optionId` and `wchar_t label[0x100]` aligned to `+2` | `uint16_t optionId`; label starts at `+1`; generic string-only row | Support docs should use one-byte option id plus aligned UTF-16 label wording. |
| Insertion helper | Target call to `0x004f3c50`, ListPane support docs, broad caller fanout | [UID:0003U0] `ListPane::AddEntry` / append item at tail | `MenuQuestionItemListLarger`-owned insertion helper; `ChattingColorListPane` ownership | Dependency only; does not prove target ownership. |
| Source placement if live | Address cluster, class pages, constructors, vtables, `MessageDialogs` source family | [UID:000080] `MenuQuestionItemListLarger`, emitted through [UID:0000LA] `MessageDialogs` | `ListPane.cpp`, `ChattingColorListPane`, `MenuQuestionDialogLarger` action/update pages, new standalone file | Strong semantic owner if a route is found; not enough to assign now. |
| Liveness | Raw PE VA/RVA/raw/rel32 scans, current docs, B001 report, Ghidra zero callers, positive controls | No live route currently proven; keep non-emitting | Assign because byte shape is valid; delete as padding; treat as compiler switch data | Blocks owner/emitter and formal C++. |
| Dead retained code vs missed route | No static route, active constructor inline duplicate, complete stack-cookie body, source-order adjacency | Most likely retained dead/private helper or unreferenced out-of-line clone | Ordinary direct caller missed; virtual method; callback table; CRT/compiler-generated helper | Explains source-shaped bytes without generating duplicate C++ output. |
| Generated-name pollution | Ghidra/OOAnalyzer class `ChattingColorListPane`, simroot source map entries under `class_ChattingColorListPane.cpp.source_map.json` | Generated class route is caller/address pollution | Use Ghidra class as owner | Must be recorded as rejected historical/generated route. |
| No-code proof | Non-reconstructable metadata, no owner/emitter, constructor inline equivalent, no route hits | Keep C++ block blank with exact no-code proof | Emit route-contingent helper C++; attach to class to reduce no-owner count | No-code proof is now strong and target-specific. |

## Ranked Ownership Analysis

### 1. [UID:000080] `MenuQuestionItemListLarger` / [UID:0000LA] `MessageDialogs`

Evidence for:

- The helper sits immediately after the live larger-list constructor and before larger-list probe/select/draw methods.
- It mirrors the normal menu-question list add-row raw helper.
- It builds exactly the row record used by `MenuQuestionItemListLarger::DrawRow` and by larger menu-question action/update paths.
- The live larger constructor constructs this list class and performs the same append operation inline.

Evidence against:

- No IDA-modeled function at `0x00550f20`.
- No static caller, vtable slot, VA/RVA/raw pointer, or rel32 branch route.
- Active source behavior is already present in the live constructor; assigning this raw clone would add dead duplicate emission.

Decision: best semantic owner if a route appears, but do not assign under current evidence.

### 2. [UID:00007Y] `MenuQuestionDialogLarger`

Evidence for:

- The larger dialog constructor parses packet labels and inlines the same row append shape.
- The list exists only as private support for the larger dialog.

Evidence against:

- The raw helper's `ecx` is the list object, not the dialog.
- The body calls `ListPane::AddEntry` on `ecx`.
- If live, it is a list method/helper, not a dialog method.

Decision: reject as direct owner. Mention constructor inline equivalent in support docs.

### 3. [UID:0000KT] `ListPane`

Evidence for:

- The helper calls `ListPane::AddEntry`.
- The row record is inserted into ListPane storage.

Evidence against:

- It builds a menu-question-specific row with an option id and label.
- `ListPane::AddEntry` is a shared dependency and already documented as `ListPane` infrastructure.
- The helper sits in the MessageDialogs item-list class cluster, not in the `ListPane` address family.

Decision: reject as direct owner. Keep `ListPane::AddEntry` as callee/dependency.

### 4. `ChattingColorListPane`

Evidence for:

- Ghidra/OOAnalyzer function-data labels the body as `ChattingColorListPane::meth_0x550f20`.
- Source map artifacts mention `0x00550f20` in `class_ChattingColorListPane.cpp.source_map.json`.

Evidence against:

- Address cluster is `MessageDialogs`, not chat-color UI.
- The normal/larger menu-question sibling bytes and row layout match this target.
- There are zero Ghidra callers and no IDA function/xref route.
- `ListPane::AddEntry` and `GetSelectedEntry` are known generated ownership-pollution hotspots currently scattered under chat-color output.

Decision: reject as generated/class-owner pollution.

### 5. Compiler/linker artifact only

Evidence for:

- No route and active inline duplicate point to dead retained code.

Evidence against:

- The bytes are a complete custom helper, not compiler-generated glue.
- It has a source-facing signature and source-family semantic role.

Decision: classify as custom source-shaped raw evidence, not compiler glue. Still non-emitting because liveness is unproven.

## Negative Evidence Summary

- No `0x00550f20` VA pointer hit.
- No `0x00150f20` RVA pointer hit.
- No raw-offset pointer hit for the file offset `0x00150320`.
- No `.text` rel32 `call`, `jmp`, or conditional branch target to `0x00550f20`.
- No vtable data cell points to `0x00550f20`; nearby live vtable cells point to `0x00550f90` and `0x00550fa0`.
- No constructor call points to `0x00550f20`; nearby live constructor calls point to `0x00550ed0`.
- Ghidra function-data has zero callers and no IDA counterpart.
- The active larger constructor duplicates the append logic inline and calls `0x004f3c50` directly, not this helper.

## Recommended Target Edits

For `by-memory/0x00550f20-0x00550f76.MenuQuestionItemListLargerAddRowNoRouteRaw.md`:

1. Update metadata:

```text
COMPLETION:88
CONFIDENCE:88
CANONICAL_OWNER:NONE
RECONSTRUCTABLE:FALSE
EMITTER_UIDS:
RECONSTRUCTION_CPP CODE:
```

2. Keep formal C++ blank. Add explicit no-code proof:

> This is a complete custom row-append helper body, but no caller/pointer/vtable/runtime route to `0x00550f20` is currently proven. The active larger menu-question constructor already emits the same row-building behavior inline and calls `ListPane::AddEntry` directly. Emitting this raw clone would duplicate dead/unrouted behavior, so the target stays no-owner/non-emitting until a route is found.

3. Add exact raw boundary and padding:

> [UID:0003WD] ends at `0x00550f1f`; `0x00550f1f-0x00550f20` is one `0xcc`; this helper is `0x00550f20-0x00550f76`; `0x00550f76-0x00550f80` is ten `0xcc` bytes before [UID:0003WF].

4. Add behavior/source-shape detail:

> The helper takes `optionId` as the low byte at `[ebp+8]` and `label` at `[ebp+0x0c]`, saves `ecx` as the target list, writes the option byte at local row offset `+0`, copies `label` to aligned `wchar_t` storage at local row offset `+2` with `_wcscpy_s(..., 0x100, ...)`, appends the row through [UID:0003U0] `ListPane::AddEntry` at `0x004f3c50`, checks the security cookie, and returns `ret 8`.

5. Add route scan and positive controls from this report.

6. Add rejected alternatives:

> Reject `ChattingColorListPane` generated ownership as source-map/OOAnalyzer pollution; reject `ListPane` ownership because `0x004f3c50` is only a dependency; reject `MenuQuestionDialogLarger` direct ownership because `ecx` is the list object; reject padding/compiler-switch treatment because the bytes are executable custom code.

7. Add the route-contingent source name:

> If a future route is found, use `MenuQuestionItemListLarger::AddRow(unsigned char optionId, const wchar_t *label)` or `AppendOptionRow`; until then the name is descriptive only and must not trigger emission.

## Recommended Support Edits

### `by-class/MenuQuestionItemListLarger.md`

- Expand the raw helper note for [UID:0003WE]:
  - It is a source-shaped but unrouted append-row clone.
  - If live, its best name is `AddRow` / `AppendOptionRow`.
  - It builds a row with `optionId` at `+0` and UTF-16 label at `+2`.
  - It stays non-emitting because no caller/pointer/vtable route exists and the live constructor inlines equivalent row insertion.
- Keep class score unchanged unless the supervisor wants to raise confidence for the raw-helper caveat. No ownership change.

### `by-file/MessageDialogs.md`

- Under the `MenuQuestionItemListLarger` row, replace the broad "raw helper remains non-emitting" wording with this more precise route:
  - Active constructor row population is in [UID:0003W4] and calls `ListPane::AddEntry` directly.
  - [UID:0003WE] is retained raw source-shaped no-route evidence only.
  - Future proof needed: caller, table pointer, vtable entry, or other runtime route to `0x00550f20`.

### `by-memory/0x0054ce10-0x00551021.NpcMessageAndMenuQuestionDialogs.md`

- Update the split child row for [UID:0003WE] with the stronger summary:
  - exact stack-cookie row append helper;
  - `optionId` byte plus aligned UTF-16 label;
  - `ListPane::AddEntry` callee;
  - no route despite positive controls;
  - no-owner/non-emitting.

### `by-memory/0x0054fb30-0x00550afb.MenuQuestionDialogLargerConstructor.md`

- Add the row-population detail that the constructor itself loops over packet item labels, stores `++optionIndex` in the row prefix, copies UTF-16 label text with `wcscpy_s`, and calls `0x004f3c50` directly. This explains why [UID:0003WE] is not needed as emitted C++ under current route evidence.

### `by-memory/0x00550fa0-0x00551021.MenuQuestionItemListLargerDrawRow.md`

- Strengthen the row-record note:
  - The displayed text begins at item data `+2`.
  - The first byte is the menu option id serialized by the action handler.
  - The byte at `+1` is alignment/padding for the UTF-16 label.

### `by-memory/0x00550b00-0x00550c30.MenuQuestionDialogLargerActionHandler.md`

- Clarify "selected list-row byte" as the `MenuQuestionOptionRow::optionId` first byte from the selected entry.

### `by-memory/0x004f3bb0-0x004f3f20.ListPaneItemSelectionStorageHelpers.md`

- No required metadata change. If touched, ensure `0x004f3c50` keeps the accepted descriptive name `ListPane::AddEntry` / append item and note that callers may pass feature-specific row structs.

### `by-memory/0x00550dc0-0x00550e16.MenuQuestionItemListAddRowNoRouteRaw.md`

- Optional parallel update: the normal raw add-row helper has the same proof shape as this target. If the supervisor wants symmetry, update it later with the same option-id/label/layout and no-route wording.

## Score Rationale

Recommended target score: `88/88`.

Completion increases because the target can now document:

- exact raw bytes and disassembly;
- exact padding before and after;
- source-shaped signature and row layout;
- `_wcscpy_s`, `ListPane::AddEntry`, and security-cookie behavior;
- active constructor inline equivalent;
- route-scan negative evidence with nearby positive controls;
- generated `ChattingColorListPane` route rejection;
- exact no-code proof and route-contingent owner/name policy.

Confidence remains below `90` because no static route is proven. The helper's behavior is certain, but its original source liveness and whether it was intentionally retained dead code cannot be proven from current evidence.

## Exact Pending `by-memory/-coverage-report.md` Replacement

Do not edit `by-memory/-coverage-report.md` directly. If the supervisor accepts the score update, replace the current [UID:0003WE] row with:

```text
        - [UID:0003WE][0x00550f20-0x00550f76.MenuQuestionItemListLargerAddRowNoRouteRaw](by-memory/0x00550f20-0x00550f76.MenuQuestionItemListLargerAddRowNoRouteRaw.md) 0x00550f20-0x00550f76 | no-route raw code island | MenuQuestionItemListLargerAddRowNoRouteRaw : ignored/non-emitting : 88% : strong : B015 source-routing recheck disassembles a complete stack-cookie row append clone: `ret 8` helper writes one-byte `optionId` into a temporary menu-question row prefix, copies the UTF-16 label with `_wcscpy_s` into the aligned `+2` field, and calls [UID:0003U0][0x004f3bb0-0x004f3f20.ListPaneItemSelectionStorageHelpers](by-memory/0x004f3bb0-0x004f3f20.ListPaneItemSelectionStorageHelpers.md) / `ListPane::AddEntry` at `0x004f3c50`. Raw PE VA/RVA/raw-offset and `.text` rel32 scans found no route to `0x00550f20`, while positive controls found constructor calls to `0x00550ed0` and vtable refs to `0x00550f90`/`0x00550fa0`; the active larger dialog constructor already inlines equivalent row insertion, so keep `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, blank emitter/C++ until a caller, pointer, or table route is proven.
```

No other coverage row must change for this target-only callback.

## Implementation Callback Checklist

If accepted, send B015 a callback with these exact edits:

1. Edit `by-memory/0x00550f20-0x00550f76.MenuQuestionItemListLargerAddRowNoRouteRaw.md`.
   - Set `COMPLETION:88`, `CONFIDENCE:88`.
   - Keep `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, blank formal C++.
   - Add the exact range/padding, raw disassembly summary, behavior/source-shape, row layout, route scan, positive controls, generated-pollution rejection, ranked owner alternatives, and no-code proof from this report.
2. Edit `by-class/MenuQuestionItemListLarger.md`.
   - Expand the [UID:0003WE] raw helper caveat with the source-shaped name, row layout, active constructor inline duplicate, and no-route proof.
   - Do not add the raw helper to the method map as an emitted method.
3. Edit `by-file/MessageDialogs.md`.
   - Clarify that [UID:0003WE] is retained no-route row-append evidence only; active row insertion belongs to the larger dialog constructor path until a helper route is found.
4. Edit `by-memory/0x0054ce10-0x00551021.NpcMessageAndMenuQuestionDialogs.md`.
   - Update the split child row for [UID:0003WE] with report-level detail and the `88/88` target score if accepted.
5. Edit `by-memory/0x0054fb30-0x00550afb.MenuQuestionDialogLargerConstructor.md`.
   - Add the constructor's inline row-population loop detail and its direct `ListPane::AddEntry` call.
6. Edit `by-memory/0x00550fa0-0x00551021.MenuQuestionItemListLargerDrawRow.md`.
   - Add the row-record field layout: option id at first byte, alignment byte, label at `+2`.
7. Edit `by-memory/0x00550b00-0x00550c30.MenuQuestionDialogLargerActionHandler.md`.
   - Clarify selected row byte as the row option id.
8. Optional low-risk support edits:
   - `by-memory/0x004f3bb0-0x004f3f20.ListPaneItemSelectionStorageHelpers.md`: keep `0x004f3c50` named `ListPane::AddEntry` / append item.
   - `by-memory/0x00550dc0-0x00550e16.MenuQuestionItemListAddRowNoRouteRaw.md`: apply parallel normal-list wording in a later paired pass if desired.
9. Do not edit `by-memory/-coverage-report.md`; supervisor applies the exact row replacement above.

## Validation Commands For Callback

Run only for files actually edited, from `source-3/project-documentation`:

> Executable block R001 was removed from this report and preserved verbatim in [0003WE-MenuQuestionItemListLargerAddRowNoRouteRaw-source-routing-removed.md](0003WE-MenuQuestionItemListLargerAddRowNoRouteRaw-source-routing-removed.md). The archived block is non-authoritative and must not be executed.

If the optional `ListPane` or normal-list sibling pages are edited, run scoped validators for those files too.

## IDA Rename, Type, And Comment Recommendations

- Do not create or rename an IDA function as live at `0x00550f20` without a route decision. If an analyst marks it for documentation, use a non-emitting/comment name such as `MenuQuestionItemListLarger_AddRow_NoRouteRaw`.
- If a future route is discovered, source type should be `void __thiscall MenuQuestionItemListLarger::AddRow(unsigned char optionId, const wchar_t *label)`.
- Comment `0x00550f20`: "Complete source-shaped row append clone; writes one-byte option id, copies label to aligned +2 WCHAR field, calls ListPane::AddEntry; no caller/pointer/vtable route currently proven."
- Comment `0x004f3c50`: `ListPane::AddEntry` / append item at tail; caller-supplied row struct is feature-specific.
- Comment generated-source artifacts: reject `ChattingColorListPane::meth_0x550f20` as generated owner pollution.

## Remaining Open Questions

- No defensible live route exists from current evidence. Checked raw VA/RVA/raw pointer scans, `.text` rel32 call/jump scans, nearby vtable/caller positive controls, docs, B001 report, generated/function-data, and active constructor decompilation leads.
- The exact original source reason for retaining the unrouted body is not provable. Best inference is retained dead/private helper or an unreferenced out-of-line clone. This uncertainty blocks owner/emitter/C++ but does not block documenting behavior and no-code disposition.

## Validator Results

No validators were run because this assignment is report-only and no by-* documentation was edited.

## Changed Files

- Created: `source-3/project-documentation/tools/leaser/Agents/Agent-B015/research/0003WE-MenuQuestionItemListLargerAddRowNoRouteRaw-source-routing.md`
- Modified: none outside B015 research folder.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"command_id":"000000004167","details":"report marked for revalidation","event":"needs-revalidation","issue":"target_uid_unknown: 0003WE","source_path":"executed-b-agent-research/B015/0003WE-MenuQuestionItemListLargerAddRowNoRouteRaw-source-routing.md","timestamp":"2026-07-01T19:52:03-04:00"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
