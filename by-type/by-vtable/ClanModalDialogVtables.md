*** UID:0003HE | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:87 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000I8 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000I8 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# Clan Modal Dialog Vtables

## Status

- Entity kind: source-local vtable family.
- Scope: `ClanNameInputDialog` through `ClanLeaveConfirmDialog`.
- Direct owner: [UID:0000I8][Clan](by-file/Clan.md). [UID:0000IA][ClanDialogs](by-file/ClanDialogs.md) is a non-standalone, non-emitting family/index and historical split record, not a possible direct owner under current evidence.
- Exact data page: [UID:0002MN][0x006158f4-0x00615fd8.ClanModalDialogVtableData](by-memory/0x006158f4-0x00615fd8.ClanModalDialogVtableData.md).
- Split from: [UID:0001X9][ClanDialogVtableFamily](by-type/by-vtable/ClanDialogVtableFamily.md), which remains a broad non-emitting modal-plus-bank index.

## Vtable Groups

| Class | Exact data range | Primary | Secondary | Tertiary | Store/xref evidence |
| --- | --- | --- | --- | --- | --- |
| `ClanNameInputDialog` | `0x006158f4-0x00615994` | `0x006158f8` | `0x0061595c` | `0x0061598c` | Constructor store at `0x00488b9e` plus companion secondary/tertiary stores. |
| `ClanDepMoneyInputDialog` | `0x00615994-0x00615a34` | `0x00615998` | `0x006159fc` | `0x00615a2c` | Inline construction refs at `0x00485120/0x00485126/0x00485130` and `0x00487de4/0x00487dea/0x00487df4`, raw constructor stores at `0x00488fb2/0x00488fba/0x00488fc4`, and submit slot `0x006159f4 -> 0x00488fe0`. |
| `ClanWidMoneyInputDialog` | `0x00615a34-0x00615ad4` | `0x00615a38` | `0x00615a9c` | `0x00615acc` | Raw constructor and caller-context refs at `0x00485398`, `0x004884d4`, and `0x00489082`. |
| `ClanExpelNameInputDialog` | `0x00615ad4-0x00615b74` | `0x00615ad8` | `0x00615b3c` | `0x00615b6c` | Raw constructor and caller-context refs at `0x004851cb`, `0x004881e4`, and `0x00489152`; submit slot `0x00615b34 -> 0x00489180` is `ClanExpelNameInputDialog::OnSubmitText(const wchar_t *)`. |
| `ClanSummonNameInputDialog` | `0x00615b74-0x00615c14` | `0x00615b78` | `0x00615bdc` | `0x00615c0c` | Raw constructor and caller-context refs at `0x0048522c`, `0x00488294`, and `0x00489282`. |
| `ClanAppearNameInputDialog` | `0x00615c14-0x00615cb4` | `0x00615c18` | `0x00615c7c` | `0x00615cac` | Raw constructor and caller-context refs at `0x00485284`, `0x0048833c`, and `0x004893b2`. |
| `ClanChangeNameInputDialog` | `0x00615cb4-0x00615d54` | `0x00615cb8` | `0x00615d1c` | `0x00615d4c` | Raw constructor and caller-context refs at `0x00485337`, `0x0048842e`, and `0x004894e2`. |
| `ClanAttrInputDialog` | `0x00615d54-0x00615df4` | `0x00615d58` | `0x00615dbc` | `0x00615dec` | Constructor stores at `0x00489660`, `0x00489666`, and `0x00489670`. |
| `ClanEnlistInputDialog` | `0x00615df4-0x00615e94` | `0x00615df8` | `0x00615e5c` | `0x00615e8c` | Raw constructor and submitter-path refs at `0x00487f34` and `0x00489f92` plus companion stores. |
| `ClanChangeInputDialog` | `0x00615e94-0x00615f34` | `0x00615e98` | `0x00615efc` | `0x00615f2c` | Raw constructor and caller-context refs at `0x004852ee`, `0x004883ed`, and `0x0048a002`. |
| `ClanLeaveConfirmDialog` | `0x00615f34-0x00615fd8` | `0x00615f38` | `0x00615fa0` | `0x00615fd0` | Constructor/callback refs at `0x004850a7`, `0x00487d22`, and `0x0048a07b` plus AlertPane-derived destructor paths. |

### DLGCLAN2 Primary Table Contract

All 24 entries in the `ClanAttrInputDialog` primary table `0x00615d58`, `ClanEnlistInputDialog` table `0x00615df8`, and `ClanChangeInputDialog` table `0x00615e98` were compared. The tables are identical through `+0x58`. Common `+0x48` cells `0x00615da0`, `0x00615e40`, and `0x00615ee0` all point to UID0004HI `0x00489df0`, establishing inherited `OnControlCommand(int,int)`. At `+0x5c`, base cell `0x00615db4` is `__purecall`, Enlist cell `0x00615e54` points to UID0002O3 `0x00489fc0`, and Change cell `0x00615ef4` points to UID0002O5 `0x0048a030`, establishing pure virtual inferred `int OnSubmit()` with two derived overrides.

Historical `OnDialogAction`, `OnSubmitEnlistment`, and method-level `SubmitClanChange` are descriptive aliases rather than separate source slots. `SubmitClanChangeHelper` remains the unchanged helper called by the Change override. This page documents source-declared virtual requirements and compiler-generated binary tables; it does not emit handwritten vtable arrays or method bodies.

## Boundary Evidence

- The exact span is `0x006158f4-0x00615fd8`, or `0x6e4` / 1764 bytes (Verified with int_convert.py).
- Live IDA MCP on 2026-06-12 lists 33 decorated modal-dialog vtable names in the range, from `??_7ClanNameInputDialog@@6B@` at `0x006158f8` through `??_7ClanLeaveConfirmDialog@@6B@_1` at `0x00615fd0`.
- Live bytes at `0x006158f4` are `68 4c 64 00 50 c3 48 00`, matching the `ClanNameInputDialog` complete-object-locator pointer followed by the first primary slot.
- Live bytes at `0x00615fd0` are `20 c3 48 00 90 4e 54 00`, the final `ClanLeaveConfirmDialog` tertiary entries before the bank handoff.
- Address `0x00615fd8` begins the next source-local bank/item-dialog block with `ClanItemDialog` RTTI and primary slot bytes `64 52 64 00 70 c4 48 00`.
- 2026-06-20 B002 [UID:000023][ClanAppearNameInputDialog](by-class/ClanAppearNameInputDialog.md) refresh treats `0x00615c74 -> 0x004893e0` as `ClanAppearNameInputDialog::OnSubmitText(const wchar_t *)`; primary/secondary/tertiary vtable bases `0x00615c18/0x00615c7c/0x00615cac` remain generated-binary support for the class declaration, not standalone source emitters.
- 2026-06-20 B002/B009 [UID:00010J][0x00488b40-0x00488fa0.ClanNameInputDialogCore](by-memory/0x00488b40-0x00488fa0.ClanNameInputDialogCore.md) reanalysis treats the shared `ClanNameInputDialog` primary slot `+0x5c` / slot index `23` as inferred/descriptive `OnSubmitText(const wchar_t *)`, based on the base `OnButtonClick` dispatch plus the six accepted derived submitter implementations.
- 2026-06-20 B004 [UID:00002A][ClanDepMoneyInputDialog](by-class/ClanDepMoneyInputDialog.md) reanalysis treats primary slot `0x006159f4 -> 0x00488fe0` as `ClanDepMoneyInputDialog::OnSubmitText(const wchar_t *)`, confirms the raw constructor stores the primary/secondary/tertiary views but has no live raw-entry route, and uses the two inline vtable-store groups as the live construction evidence.
- 2026-06-21 B011 [UID:00002D][ClanExpelNameInputDialog](by-class/ClanExpelNameInputDialog.md) reanalysis treats primary slot `0x00615b34 -> 0x00489180` as `ClanExpelNameInputDialog::OnSubmitText(const wchar_t *)`, confirms the retained raw constructor stores the primary/secondary/tertiary views but has no VA/RVA/direct-branch route to `0x00489140`, and uses inline construction sites `0x004851c6` and `0x004881df` as the live class-construction evidence.

## Assignment Gate

`AUTOGEN_PARENT_UID` is [UID:0000I8][Clan](by-file/Clan.md). This page covers the modal-dialog half of the Clan vtable family and the accepted direct source owner is UID0000I8. UID0000IA remains documentation-only with path/owner `NONE`; changing that disposition would require new direct historical source/object provenance, not score movement. The broad [UID:0001X9][ClanDialogVtableFamily](by-type/by-vtable/ClanDialogVtableFamily.md) remains parent-blank because it also includes clan-bank vtables owned by [UID:0000I9][ClanBank](by-file/ClanBank.md).

## Score Rationale

Completion `87` and confidence `92` are supported by exact `.rdata` boundaries, decorated vtable names, modal class inventory, complete-object-locator handoff bytes, live store/xref checks for representative base classes, the exhaustive DLGCLAN2 `+0x48/+0x5c` result, and the Clan source route. Source placement is resolved to `Clan.cpp`; the score remains below final-source quality because many other virtual-slot lexical names and exact historical object boundaries remain inferred. The resolved placement and DLGCLAN2 contract do not justify unrelated score inflation.

## Cross-References

- [UID:0001X9][ClanDialogVtableFamily](by-type/by-vtable/ClanDialogVtableFamily.md)
- [UID:0000I8][Clan](by-file/Clan.md)
- [UID:0000IA][ClanDialogs](by-file/ClanDialogs.md)
- [UID:0002MN][0x006158f4-0x00615fd8.ClanModalDialogVtableData](by-memory/0x006158f4-0x00615fd8.ClanModalDialogVtableData.md)
- [UID:0001TY][ClanInputDialogLayouts](by-type/by-struct/ClanInputDialogLayouts.md)
- [UID:00010J][0x00488b40-0x00488fa0.ClanNameInputDialogCore](by-memory/0x00488b40-0x00488fa0.ClanNameInputDialogCore.md)
- [UID:00010L][0x00489600-0x00489f80.ClanAttrInputDialogCore](by-memory/0x00489600-0x00489f80.ClanAttrInputDialogCore.md)

## Changes

- 2026-07-13 B004 UID0004HI contract implementation: added the exact DLGCLAN2 24-entry comparison, common inherited `OnControlCommand` cells, base `__purecall`, and derived `OnSubmit` cells. Preserved `87/92`, owner/emitter/formal disposition, complete modal inventory and boundaries, compiler-generated/non-body treatment, Clan source route, ClanDialogs split caveat, and unrelated slot evidence.

- 2026-06-12 A004 Batch 308:
  - Created as the source-local modal-dialog by-vtable child of [UID:0001X9][ClanDialogVtableFamily](by-type/by-vtable/ClanDialogVtableFamily.md).
  - Evidence: live IDA MCP confirmed the `0x006158f4-0x00615fd8` span, 33 decorated modal vtable names, boundary bytes, representative constructor stores at `0x00488b9e` and `0x00489660`, and the `ClanItemDialog` successor boundary at `0x00615fd8`.
- 2026-06-20 B002 ClanAppearNameInputDialog refresh:
  - Added the source-facing submit-slot interpretation for `0x00615c74 -> 0x004893e0` while keeping vtable data non-emitting support under the Clan source owner.
- 2026-06-20 B002/B009 ClanNameInputDialogCore refresh:
  - Added the shared `OnSubmitText(const wchar_t *)` interpretation for the base primary slot `+0x5c` / index `23`, while keeping this vtable page as generated-binary support rather than a source emitter.
- 2026-06-20 B004 ClanDepMoneyInputDialog vtable sync:
  - Expanded the `ClanDepMoneyInputDialog` row with exact inline and raw vtable store sites plus submit slot `0x006159f4 -> 0x00488fe0`; the page remains non-emitting generated-binary support under the Clan source owner.
- 2026-06-21 B011 ClanExpelNameInputDialog vtable sync:
  - Expanded the `ClanExpelNameInputDialog` row with exact submit slot `0x00615b34 -> 0x00489180` and the source-facing `OnSubmitText(const wchar_t *)` interpretation; the page remains non-emitting generated-binary support under the Clan source owner.
