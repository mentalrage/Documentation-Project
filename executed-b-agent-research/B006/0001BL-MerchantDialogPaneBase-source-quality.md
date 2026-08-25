** TARGET-REPORT-UID:0001BL **
** AUTHOR-AGENT-ID:B006 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0001BL MerchantDialogPaneBase Source-Quality Research

Assignment: `B006-rework-0001BL-merchant-dialog-pane-base-20260625`  
Agent: Agent-B006  
Date: 2026-06-25  
Target: `[UID:0001BL] by-memory/0x00517d30-0x00517ebf.MerchantDialogPaneBase.md`

This is a report-only rework after supervisor rejection. I did not edit any `by-*` documentation, generated output, project-level generated file, validator state/cache, coverage report, lock/lease state, or the IDA database. I did not spawn subagents.

## Executive Recommendation

`[UID:0001BL]` should stop being a source-body emitter. Treat it as a reviewed, non-emitting split/container page for the physical MerchantDialogPane base range after the implementation callback creates an exact constructor child.

Recommended target metadata after implementation:

| Field | Recommended value |
| --- | --- |
| `COMPLETION` | `88` |
| `CONFIDENCE` | `91` |
| `CANONICAL_OWNER` | `000083` |
| `RECONSTRUCTABLE` | `FALSE` |
| `EMITTER_UIDS` | blank |
| Formal C++ | blank |

Do not add a formal C++ block to `[UID:0001BL]`. The current target is not one source-level unit: it contains an unmodeled raw constructor body, alignment, and the already split exact action-string virtual `[UID:0001BM]`. Emitting method bodies or a comment marker from the aggregate would either duplicate `[UID:0001BM]` or hide the missing exact constructor child.

Create a new exact constructor child during the later implementation callback:

| Proposed child | Recommended route |
| --- | --- |
| `by-memory/0x00517d30-0x00517d74.MerchantDialogPaneConstructor.md` | owner/emitter `[UID:000083] MerchantDialogPane`; file root `[UID:0000L9] MerchantDialogPane` |

Recommended constructor-child metadata:

| Field | Recommended value |
| --- | --- |
| `COMPLETION` | `89` |
| `CONFIDENCE` | `90` |
| `CANONICAL_OWNER` | `000083` |
| `RECONSTRUCTABLE` | `TRUE` |
| `EMITTER_UIDS` | `000083` |
| `EMITTER_POSITION_OPTIONAL` | blank |
| Formal C++ | exact constructor block supplied in this report |

The existing child `[UID:0001BM] by-memory/0x00517d80-0x00517ebf.MerchantDialogPaneActionStringVirtual.md` should remain the exact action-string virtual page, with owner/emitter `[UID:000083]`. It is an eligible emitter with blank formal C++ today, so the implementation callback should update it with a target-specific no-code proof for the current signature/type blocker rather than leaving the blocker unexplained.

## Current Target State Checked

Live target metadata:

- `COMPLETION:86`
- `CONFIDENCE:88`
- `CANONICAL_OWNER:000083`
- `RECONSTRUCTABLE:TRUE`
- `EMITTER_UIDS:000083`
- Formal C++ block is blank.

The current owner direction is correct, but the emission unit is wrong. `[UID:0001BL]` currently mixes a raw constructor body with a separately documented child function. The page should become a non-emitting split index once the raw constructor has its own exact child.

Generated output is stale relative to the live docs:

- `auto-generated/NexusTK/ui/dialogs/MerchantDialogPane.cpp` contains Empty Emitter Markers for `[UID:000083]`, `[UID:0001BL]`, `[UID:0001BM]`, and `[UID:00031W]`.
- The generated marker scores for `[UID:0001BL]` and `[UID:0001BM]` are stale versus the live target pages.
- Generated output should refresh only through the normal validator/generator path after approved documentation edits. Do not manually patch generated files.

## MCP Requirement And Status

IDA MCP was mandatory and was used. This report is MCP-backed, not fallback-only.

Verified MCP/database status:

- MCP endpoint: `http://127.0.0.1:13337/mcp`
- Active IDB session from `idb_list`: `80de0a67`
- IDB path: `E:\NTK\Resources\NexusTK\NexusTK.exe.i64`
- Module: `NexusTK.exe`
- Input path reported by MCP: `C:\Users\admin\Desktop\Clone\NexusTK\NexusTK.exe`
- `server_health` on 2026-06-25: `status:"ok"`, imagebase `0x400000`, auto-analysis ready, Hex-Rays ready, strings cache ready, strings cache size `2067`.

Read-only MCP tools used in the rework pass: `idb_list`, `server_health`, `tools/list`, `lookup_funcs`, `entity_query`, `xrefs_to`, `xref_query`, `callees`, `get_int`, `get_bytes`, `find_bytes`, `decompile`, and `disasm`. No MCP edit, patch, rename, comment, type, save, or IDB mutation tool was used.

## Evidence Checked

Primary target and owner pages:

- `by-memory/0x00517d30-0x00517ebf.MerchantDialogPaneBase.md`
- `by-memory/0x00517d80-0x00517ebf.MerchantDialogPaneActionStringVirtual.md`
- `by-class/MerchantDialogPane.md`
- `by-file/MerchantDialogPane.md`
- `by-type/by-vtable/MerchantDialogPaneVtables.md`
- `by-type/by-vtable/MerchantMenuDialogVtableFamily.md`
- `by-memory/0x0061ec10-0x0061fa3c.MerchantMenuDialogReadOnlyData.md`

Adjacent and sibling menu pages:

- `by-memory/0x00517450-0x00517d23.MenuDialogFactoryHelpers.md`
- `by-memory/0x00517ec0-0x0051a417.TextMenuDialogs.md`
- `by-memory/0x0051a520-0x0051c46d.ItemMenuDialogs.md`
- `by-memory/0x0051ca40-0x0051e998.SpellMenuDialogs.md`
- `by-memory/0x0051e9a0-0x0051fc8d.ArgumentedMenuDialogs.md`
- `by-file/TextMenuDialogs.md`
- `by-file/ItemMenuDialogs.md`
- `by-file/SpellMenuDialogs.md`
- `by-file/ArgumentedMenuDialogs.md`
- class pages for `TextMenuDialog`, `TextInputMenuDialog`, `ServerItemMenuDialog`, `ClientItemMenuDialog`, `ServerSpellMenuDialog`, `ClientSpellMenuDialog`, and `ArgumentedMenuMenuDialog`.

Packet, parser, and inherited-layout support:

- `by-global/g_packetSender.md`
- `by-memory/0x00574bb0-0x00574c13.QueueAndSendPacket.md`
- `by-memory/0x00575380-0x00575470.PacketBufferScalarBigEndianWriteHelpers.md`
- `by-memory/0x00575480-0x00575574.PacketBufferScalarBigEndianReadHelpers.md`
- `by-memory/0x004d1f30-0x004d2697.ObjectStatusBlobParsers.md`
- `by-class/DialogPane.md`
- `by-file/DialogPane.md`
- `by-memory/0x0049d8a0-0x0049feae.DialogPane.md`
- `auto-generated/NexusTK/ui/core/DialogPane.cpp` as read-only generated-output shape context for class `[[CHILDREN]]` insertion behavior

Generated/stale-state docs checked:

- `auto-generated/NexusTK/ui/dialogs/MerchantDialogPane.cpp`
- `auto-generated/-ag-memory-coverage.md`
- `auto-generated/-ag-research-tracker.md`
- `auto-generated/-ag-coverage-report-by-memory.md`

## IDA MCP Facts

Function and boundary facts:

- `lookup_funcs` confirms `0x00517d30`, `0x00517d53`, `0x00517d71`, `0x00517d72`, `0x00517d74`, and `0x00517ebf` are not function starts.
- `lookup_funcs` confirms `0x00517d80` is modeled as `sub_517D80`, size `0x13f`.
- `lookup_funcs` confirms `0x00517ec0` is modeled as `sub_517EC0`, size `0x66`.
- `lookup_funcs` confirms `0x0049d8a0` is modeled as `sub_49D8A0`, size `0x148`, the `DialogPane` base constructor called by the raw constructor.
- `lookup_funcs` confirms the predecessor factory at `0x00517450` is modeled as `sub_517450`, size `0x321`.
- `entity_query` over `0x00517400-0x00517f00` returns thirteen modeled functions. There is no modeled function between the factory/wrapper island and `0x00517d80`.

Constructor bytes and boundary facts:

- `get_bytes 0x00517d23 size 13` returns thirteen `0xcc` bytes, confirming predecessor padding before the constructor-shaped body.
- `disasm 0x00517d30` disassembles a raw `<no function>` constructor-shaped body. It pushes `1`, pushes `1`, pushes `word_60DB20`, calls `0x0049d8a0`, stores the one-byte constructor argument at `this + 0x26c`, installs three MerchantDialogPane vtables, and returns with `retn 4`.
- `get_bytes 0x0060db20 size 32` shows `word_60DB20` begins with UTF-16 NUL bytes, followed by the neighboring `L"Basic"` literal at `0x0060db24`; the constructor argument is therefore the shared empty title literal, not the `Basic` string.
- `decompile 0x0049d8a0` confirms the base constructor signature shape as `DialogPane(wchar_t *Source, __int16 dialogConfigId, char paneMode)` in current IDA terms and documents source-facing `DialogPane(const wchar_t *title, unsigned short dialogConfigId, unsigned char paneMode)` in `[UID:00003T]`.
- `get_bytes 0x00517d30` plus the follow-up byte check shows the constructor body is `0x00517d30-0x00517d74`, not `0x00517d30-0x00517d72`. The `retn 4` immediate bytes occupy `0x00517d72-0x00517d73`, and alignment begins at `0x00517d74`.
- `0x00517d74-0x00517d80` is twelve bytes of `0xcc` alignment before `sub_517D80`.
- The exact constructor-child range should therefore be half-open `0x00517d30-0x00517d74`, size `0x44`.

Raw constructor liveness facts:

- `xrefs_to 0x00517d30` returns zero xrefs.
- `xref_query` to `0x00517d30` with code xrefs returns total `0`, and the matching data-xref query also returns total `0`.
- `find_bytes` finds no VA pointer bytes for `0x00517d30` (`30 7D 51 00`) and no RVA pointer bytes (`30 7D 11 00`).
- This does not make the bytes padding. The raw disassembly is a complete source-shaped constructor body with a base-constructor call and vtable stores. It should be documented as an exact raw constructor child with a no-direct-route caveat.

Vtable and inherited virtual facts:

- `xrefs_to 0x00517d80` returns exactly eight data refs: `0x0061ec80`, `0x0061ed1c`, `0x0061ee7c`, `0x0061ef18`, `0x0061f078`, `0x0061f1d8`, `0x0061f338`, and `0x0061f498`.
- `find_bytes` finds exactly the same eight VA pointer hits for `0x00517d80` and no RVA pointer hits.
- `get_int` confirms all eight slots resolve to `0x00517d80`.
- `entity_query` over the vtable-name range identifies the owning class views: MerchantDialogPane, TextMenuDialog, TextInputMenuDialog, ServerItemMenuDialog, ClientItemMenuDialog, ServerSpellMenuDialog, ClientSpellMenuDialog, and ArgumentedMenuMenuDialog.
- MerchantDialogPane constructor stores the three vtable bases at `0x00517d53 -> 0x0061ec10`, `0x00517d59 -> 0x0061ec70`, and `0x00517d63 -> 0x0061eca0`.
- `get_int` at the three MerchantDialogPane vtable bases confirms the primary destructor slot points to `0x00520b70`, and secondary/tertiary views point to the shared adjusted destructor thunks at `0x00520aa5` and `0x00520ab0`.

Action-string virtual facts:

- `decompile 0x00517d80` reads the candidate action string pointer from the argument object at offset `+0x0c`.
- Leading `/` returns success without sending a packet.
- A first byte other than ASCII `0` returns false.
- For the accepted `0...` form, the function reads an action byte from string offset `+2`, a 32-bit big-endian value from `+3`, calls the shared `ObjectStatusBlob::ParseTaggedStatus` parser on string offset `+8`, then reads two later 16-bit big-endian values.
- It builds a ten-byte payload: leading `0x3a` / `':'`, action byte, one 32-bit value, and two 16-bit values. A local zero is written after the ten sent bytes.
- It sends length `10` through `g_packetSender` and `Socket::QueueAndSendPacket`.
- `callees 0x00517d80` reports the expected dependencies: packet scalar readers/writers, `0x004d1f30`, `0x00574bb0`, and stack-cookie validation.

Neighbor request-helper facts:

- `xrefs_to 0x00517ec0` returns seven code refs from derived menu command handlers.
- `decompile 0x00517ec0` builds opcode `0x43`, subtype byte `1`, the menu/object id at `this + 0x270`, sends length `6`, then closes the dialog.
- The sibling menu pages now correctly distinguish command id `2` request/cancel behavior at `0x00517ec0` from inherited vtable glue at `0x00517d80`.

Inherited DialogPane and field facts:

- `DialogPane` owns inherited state through `+0x268`, including `m_dialogConfigId` at `+0x1f8`, `m_controlManager` at `+0x1fc`, control IDs/state through `+0x229`, and background/tile state through `+0x268`.
- `MerchantDialogPane` owns the derived byte at `+0x26c`. Best current source-facing name is a merchant/menu dialog type byte; derived pages may describe it as menu mode where the concrete class semantics require that alias.
- Packet helpers, `g_packetSender`, ObjectStatusBlob parsing, and DialogPane config/control-manager state are dependencies, not MerchantDialogPane ownership transfers.

## Required Focus Findings

Raw constructor liveness:

- The constructor is source-shaped code but no-route in current IDA: no IDA function object, no code xrefs, and no VA/RVA pointer bytes.
- This should no longer block documentation structure. The implementation callback should split it into an exact raw constructor child and record the no-route caveat there.
- The existing target wording should be corrected from the old constructor endpoint/padding description: `0x00517d72-0x00517d73` are part of the `retn 4`, not padding.

Vtable-only action virtual:

- `[UID:0001BM]` is correctly an exact action-string virtual child with vtable-only reachability.
- It belongs to MerchantDialogPane because the slot is inherited across the merchant/text/item/spell/argumented menu-dialog family.
- Do not move it to TextMenuDialogs, ItemMenuDialogs, SpellMenuDialogs, ArgumentedMenuDialogs, PacketBuffer, Socket, ObjectStatusBlob, or a generic protocol module. Those pages are consumers or callees.

Constructor/action split:

- Correct physical split:
  - `0x00517d23-0x00517d30`: predecessor padding after MenuDialogFactoryHelpers.
  - `0x00517d30-0x00517d74`: exact raw MerchantDialogPane constructor child.
  - `0x00517d74-0x00517d80`: alignment padding.
  - `0x00517d80-0x00517ebf`: exact action-string virtual child `[UID:0001BM]`.
  - `0x00517ebf-0x00517ec0`: one byte of padding.
  - `0x00517ec0`: TextMenuDialog request/cancel helper successor.
- `[UID:0001BL]` should become the split/container page over the constructor child plus existing action virtual child.

Source-facing names and dependencies:

- Constructor role: MerchantDialogPane base constructor with one unsigned byte dialog-type argument; it calls `DialogPane` with the shared empty title and two `1` arguments, stores the derived type byte at `+0x26c`, and installs the three vtable views.
- Derived byte role: prefer merchant/menu dialog type wording on the base page; allow concrete pages to document class-specific aliases.
- Action virtual role: keep the documented action-string virtual wording unless a later exact signature pass proves the original method name.
- Packet helper names should normalize to the support pages: `PacketBufferWriteUInt8`, `PacketBufferWriteUInt16BE`, `PacketBufferWriteUInt32BE`, `PacketBufferReadUInt16BE`, `PacketBufferReadUInt32BE`, `Socket::QueueAndSendPacket`, and `g_packetSender` as the process Socket sender.
- `ObjectStatusBlob::ParseTaggedStatus` is the variable-length parser dependency in the accepted action-string path.

First-draft C++ decision:

- Do not add formal C++ to `[UID:0001BL]`.
- Do not add a comment-only marker to `[UID:0001BL]` before the split. A marker would make the aggregate appear handled while the constructor still lacks an exact page.
- After the constructor child exists, `[UID:0001BL]` should be non-reconstructable/non-emitting with a blank formal C++ block. Exact child pages carry method-body reconstruction: the new constructor child carries the constructor C++ now, while `[UID:0001BM]` carries a target-specific no-code proof until its virtual signature/action-object type is resolved.
- The new constructor child is ready for formal C++ now. The raw no-route status is a liveness caveat, not a source-shape blocker: the body is complete, source-shaped, and matches an ordinary constructor with a base initializer and one member initializer.

Exact formal `RECONSTRUCTION_CPP CODE` insertion text for `by-memory/0x00517d30-0x00517d74.MerchantDialogPaneConstructor.md`:

```text
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
MerchantDialogPane::MerchantDialogPane(unsigned char menuDialogType)
    : DialogPane(L"", 1, 1),
      m_menuDialogType(menuDialogType)
{
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
```

Why this preserves behavior:

- `DialogPane(L"", 1, 1)` matches the raw pushes of `word_60DB20`, `1`, and `1` before `call sub_49D8A0`; `word_60DB20` begins with a UTF-16 NUL and is the shared empty title literal.
- `m_menuDialogType(menuDialogType)` matches `mov al, [ebp+8]` and `mov [esi+26Ch], al`. The name is inferred but source-facing: it is the derived merchant/menu dialog type byte used by the menu-dialog family.
- The three vtable stores at `0x00517d53`, `0x00517d59`, and `0x00517d63`, the returned `this` in `eax`, stack cleanup `retn 4`, and base-class vtable writes are compiler lowering from the class declaration and constructor; they should not be hand-authored in the body.

`[UID:0001BM]` formal C++ disposition:

- `[UID:0001BM]` is currently an eligible emitter (`86/89`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:000083`) with blank formal C++. The implementation callback should update that page with an explicit no-code proof, not with action-virtual C++ in this pass.
- Target-specific no-code proof: current IDA proves behavior but not the source-level virtual signature or action-object type. The function is vtable-reached and does not use the `MerchantDialogPane` receiver, so Hex-Rays collapses it to `char __stdcall sub_517D80(int a1)`. The only semantic parameter is an object pointer whose `+0x0c` field is the action-string pointer; no checked support page defines that object type, its ownership, or the virtual slot name. A formal body today would have to invent both the method name and parameter type (`MenuActionString *`, `MenuItemAction *`, `DialogAction *`, or similar) without a caller-side declaration, and using `int`, `void *`, or `a1` would violate the source-quality rule. Packet helper names and parser roles are understood well enough for documentation, but the virtual interface itself is not source-ready.
- Rejected code shapes for `[UID:0001BM]`: a raw decompiler signature, a direct `const char *actionString` parameter, a PacketBuffer/ObjectStatusBlob-owned helper, or assigning it to Text/Item/Spell/Argumented pages. The page should stay owned/emitted by `[UID:000083]`, keep C++ blank, and record that resolving the menu action argument type or vtable-slot declaration is the concrete condition for later method-body C++.

## Ownership Ranking

| Candidate | Decision |
| --- | --- |
| `[UID:000083] MerchantDialogPane` | Correct direct class owner for the constructor, inherited action virtual, and MerchantDialogPane vtable support. |
| `[UID:0000L9] MerchantDialogPane` | Correct file root for class emission after exact child pages are split. |
| `[UID:0000OP] TextMenuDialogs` | Neighbor/factory and derived-consumer owner only. It should not own the MerchantDialogPane base constructor or inherited action virtual. |
| `[UID:0000KF] ItemMenuDialogs` | Derived consumer only; command id `2` routes to `0x00517ec0`, not `0x00517d80`. |
| `[UID:0000O2] SpellMenuDialogs` | Derived consumer only; inherited action-string slot remains MerchantDialogPane. |
| `[UID:0000HI] ArgumentedMenuDialogs` | Derived consumer only; inherited action-string slot remains MerchantDialogPane. |
| `[UID:0001Y5] MerchantMenuDialogVtableFamily` | Mixed-owner non-emitting context only. Keep owner-specific vtable pages for source routing. |
| PacketBuffer, Socket, ObjectStatusBlob, DialogPane | Callee/base dependencies only, not owners of this target. |

## Implementation Callback Plan

When the supervisor validates this report and authorizes implementation, use a lease only for the immediate edit batch and release it afterward.

Recommended edits:

1. Create exact child `by-memory/0x00517d30-0x00517d74.MerchantDialogPaneConstructor.md`.
2. Populate that child with current MCP evidence: no IDA function object, no direct route, no VA/RVA pointer hits, full raw constructor disassembly behavior, corrected `retn 4` endpoint, empty-title `DialogPane(L"", 1, 1)` base call, `m_menuDialogType` store at `+0x26c`, vtable stores, and the formal constructor C++ block above.
3. Update `[UID:0001BL]` to a non-emitting split/container page with `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, blank formal C++ block, corrected boundary table, and cross-links to the new constructor child plus `[UID:0001BM]`.
4. Update `[UID:0001BM]` with current helper names, vtable-only evidence, and the no-code proof above; do not move ownership and do not enter action-virtual C++ until the action-object type/slot declaration is source-ready.
5. Update `[UID:000083]` and `[UID:0000L9]` to replace stale old code-gate wording and describe the constructor/action split.
6. Update `[UID:00031W]` only if needed to reference the exact constructor child and preserve the vtable-store evidence.
7. Do not manually edit generated files, coverage reports, validator state/cache, or the IDA database. Regenerate only through the approved validator/generator workflow.

Suggested score effects:

- `[UID:0001BL]`: `86/88` to `88/91`, with `RECONSTRUCTABLE:FALSE` because it becomes a reviewed split index.
- New constructor child: `89/90`, capped below final-audit confidence by raw no-route status and inferred class member spelling, but high enough for formal constructor C++ because the body is complete and source-shaped.
- `[UID:0001BM]`: no ownership/emitter/reconstructable change; `87/90` is justified if the implementation incorporates the current helper-name, packet-semantics, and no-code-proof evidence.

## Validation Notes

No validator was run because this is a report-only pass and no by-documentation implementation edits were authorized.

No leases were acquired because no target/support `by-*` files were edited.

The report attacks the named blockers directly: raw constructor liveness, vtable-only action virtual routing, exact child split, field/helper names, inherited DialogPane support, packet/action-string semantics, sibling menu command-route confusion, and first-draft C++ versus no-code handling.

## Implementation Tracking Checklist

Implementation callback pass completed by Agent-B006 on 2026-06-25.

- [x] Supervisor validation required before implementation; proof: supervisor/user accepted this report for implementation in assignment `B006-implement-0001BL-merchant-dialog-pane-base-20260625`.
- [x] Lease only the immediate edit set during callback, release immediately after the edit/validator batch, and do not edit through another agent's active lease; proof: first batch leased parent `by-memory/0x00517d30-0x00517ebf.MerchantDialogPaneBase.md`, created/validated child, then released parent/child leases successfully. Second batch leased parent, `[UID:0001BM]`, class, file, and vtable support docs; cleanup unlease reported `Rejected[No active lease]` because those short leases had already expired, and `tools/leaser/Agents/current_leases.md` showed no active `B006` or MerchantDialogPane entries afterward.
- [x] Create `by-memory/0x00517d30-0x00517d74.MerchantDialogPaneConstructor.md` under `by-memory/`, then run the validator on the new file so it receives a real UID. Do not guess the UID; proof: validator command `python .\tools\validator.py --mode file --file by-memory/0x00517d30-0x00517d74.MerchantDialogPaneConstructor.md --apply --queue-timeout 240 --wait-generated` assigned real UID `00041Q` in command `000000001515` at `2026-06-25T13:48:29-04:00`.
- [x] Populate the new constructor child with metadata `COMPLETION:89`, `CONFIDENCE:90`, `CANONICAL_OWNER:000083`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:000083`, blank `EMITTER_POSITION_OPTIONAL`, `Nested:0`, and an `Item Summary` that does not repeat auto-generated fields; proof: [UID:00041Q] now has those fields, and follow-up validator command `000000001518` recorded completion `89`, confidence `90`, owner `000083`, reconstructable `true`, emitter `000083`, `ok: 1`.
- [x] Add the constructor-child evidence at report-level detail: active MCP session `80de0a67`, `server_health` OK, no IDA function at `0x00517d30`, no function at `0x00517d74`, modeled successor `0x00517d80`, thirteen modeled functions in `0x00517400-0x00517f00`, raw constructor disassembly, `word_60DB20` empty-title literal, `DialogPane(L"", 1, 1)` base call, `m_menuDialogType` store at `+0x26c`, three vtable stores, `retn 4` endpoint, predecessor and successor padding, zero xrefs, and no VA/RVA pointer-byte hits; proof: incorporated in [UID:00041Q] sections `Status`, `Constructor Behavior`, `IDA MCP Evidence`, `Rejected Alternatives And Negative Evidence`, and `Reconstruction Notes`.
- [x] Insert the exact formal constructor `RECONSTRUCTION_CPP CODE` block from this report into the new child. Do not hand-author vtable stores, raw stack cleanup, or IDA labels in the code; proof: [UID:00041Q] formal block contains only the approved constructor with `DialogPane(L"", 1, 1)` and `m_menuDialogType(menuDialogType)`.
- [x] Update `[UID:0001BL]` `by-memory/0x00517d30-0x00517ebf.MerchantDialogPaneBase.md`: change `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, keep `CANONICAL_OWNER:000083`, update `COMPLETION:88` and `CONFIDENCE:91`, keep formal C++ blank, correct the endpoint/padding table to `0x00517d30-0x00517d74` constructor and `0x00517d74-0x00517d80` alignment, set `Nested` appropriately for the constructor child plus `[UID:0001BM]`, and add a change note explaining the split-container reclassification; proof: [UID:0001BL] metadata/body updated and validator command `000000001531` recorded completion `88`, confidence `91`, reconstructable `true -> false`, `ok: 1`.
- [x] Update `[UID:0001BL]` cross-references to include the new constructor child UID after validation and retain `[UID:0001BM]`, `[UID:000083]`, `[UID:0000L9]`, `[UID:00031W]`, and sibling menu-dialog references; proof: [UID:0001BL] now references `[UID:00041Q]` in `Status`, `Anchors`, `IDA Evidence`, `Reconstruction Notes`, `Cross-References`, and `Changes`.
- [x] Update `[UID:0001BM]` `by-memory/0x00517d80-0x00517ebf.MerchantDialogPaneActionStringVirtual.md`: keep `CANONICAL_OWNER:000083`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:000083`, and blank formal C++; add current MCP evidence for the eight vtable-only refs, packet parser/encoder callees, 10-byte send path, helper-name normalization, and the explicit no-code proof that the source virtual signature/action-object type is not yet safe; proof: [UID:0001BM] `Status`, `IDA Evidence`, `Reconstruction Notes`, and `Score Rationale` updated, and validator command `000000001533` recorded owner `000083`, emitter `000083`, `ok: 1`.
- [x] If `[UID:0001BM]` receives the no-code proof, update its score to `87/90`; proof: [UID:0001BM] score is `87/90`, validator command `000000001533` recorded completion `87` and confidence `90`.
- [x] Update `[UID:000083]` `by-class/MerchantDialogPane.md`: replace stale constructor range `0x00517d30-0x00517d71` with exact child `0x00517d30-0x00517d74`, record inferred `m_menuDialogType` at `+0x26c`, link the constructor child and `[UID:0001BM]`, preserve the action-virtual no-code condition, and keep owner/emitter `[UID:0000L9]`; proof: class `Status`, `Method Notes`, `Evidence Notes`, `Reconstruction Notes`, `Score Rationale`, `Cross-References`, and `Changes` updated. Validator command `000000001537` recorded owner `0000L9`, emitter `0000L9`, `ok: 1`.
- [x] Update `[UID:0000L9]` `by-file/MerchantDialogPane.md`: list the exact constructor child and exact action-string virtual as the class source contents, preserve standalone-versus-folded source-file uncertainty, and remove wording that treats `[UID:0001BL]` as a source-body emitter; proof: file `Status`, `File Role`, `Proposed Contents`, `Boundary Notes`, `Placement Notes`, `Score Rationale`, `Cross-References`, and `Changes` updated. Validator command `000000001543` recorded file root `ok: 1`.
- [x] Update `[UID:00031W]` `by-type/by-vtable/MerchantDialogPaneVtables.md` only if the implementation creates a new constructor UID that should be linked from the vtable-store evidence; preserve the three owner-specific vtable bases and compiler-generated vtable handling; proof: vtable doc links [UID:00041Q] in `Status`, `Binary Evidence`, `Ownership Inference`, `Cross-References`, and `Changes`, while preserving the three bases and no hand-authored vtable C++. Validator command `000000001547` recorded `ok: 1`.
- [x] Update `[UID:0001Y5]` and `[UID:00025U]` only if validator or supervisor review finds stale wording that directly contradicts the new constructor child; otherwise treat them as already sufficient support docs and do not churn mixed-family context; proof: not edited. No validator or implementation review blocker required churn in those mixed-family context pages for this accepted callback.
- [x] Preserve rejected alternatives and negative evidence: TextMenuDialogs, ItemMenuDialogs, SpellMenuDialogs, ArgumentedMenuDialogs, PacketBuffer, Socket, ObjectStatusBlob, DialogPane, broad `MerchantMenuDialogVtableFamily`, raw padding/dead-code interpretation, and aggregate `[UID:0001BL]` emission are all rejected for the reasons in this report; proof: [UID:00041Q], [UID:0001BL], [UID:0001BM], [UID:000083], and [UID:0000L9] each preserve the relevant rejected-owner, dependency-only, no-dead-code, and non-aggregate-emission reasoning.
- [x] Run scoped validators from `source-3/project-documentation` after implementation edits: proof: all required file validators were run with `--apply --queue-timeout 240 --wait-generated`.
- [x] Report each validator command, working directory, command id, command timestamp, exit code, `ok` count, generated-refresh state, and any generated side effects; proof:
  - `E:\NTK\GhidraBridge\source-3\project-documentation`; `python .\tools\validator.py --mode file --file by-memory/0x00517d30-0x00517d74.MerchantDialogPaneConstructor.md --apply --queue-timeout 240 --wait-generated`; command `000000001515`; timestamp `2026-06-25T13:48:29-04:00`; exit `0`; assigned UID `00041Q`; generated refresh completed. The initial registration output was truncated before the `ok` line was visible in the captured console, so final child validation below is the recorded `ok` proof.
  - Same command/file after metadata and C++ insertion; command `000000001518`; timestamp `2026-06-25T13:49:15-04:00`; exit `0`; `ok: 1`; generated refresh completed.
  - `python .\tools\validator.py --mode file --file by-memory/0x00517d30-0x00517ebf.MerchantDialogPaneBase.md --apply --queue-timeout 240 --wait-generated`; command `000000001531`; timestamp `2026-06-25T13:54:29-04:00`; exit `0`; `ok: 1`; generated refresh completed.
  - `python .\tools\validator.py --mode file --file by-memory/0x00517d80-0x00517ebf.MerchantDialogPaneActionStringVirtual.md --apply --queue-timeout 240 --wait-generated`; command `000000001533`; timestamp `2026-06-25T13:54:56-04:00`; exit `0`; `ok: 1`; generated refresh completed.
  - `python .\tools\validator.py --mode file --file by-class/MerchantDialogPane.md --apply --queue-timeout 240 --wait-generated`; command `000000001537`; timestamp `2026-06-25T13:55:14-04:00`; exit `0`; `ok: 1`; generated refresh completed.
  - `python .\tools\validator.py --mode file --file by-file/MerchantDialogPane.md --apply --queue-timeout 240 --wait-generated`; command `000000001543`; timestamp `2026-06-25T13:55:55-04:00`; exit `0`; `ok: 1`; generated refresh completed.
  - `python .\tools\validator.py --mode file --file by-type/by-vtable/MerchantDialogPaneVtables.md --apply --queue-timeout 240 --wait-generated`; command `000000001547`; timestamp `2026-06-25T13:56:37-04:00`; exit `0`; `ok: 1`; generated refresh completed.
- [x] Generated refresh expectation: normal validator runs may refresh `auto-generated/NexusTK/ui/dialogs/MerchantDialogPane.cpp`, `auto-generated/-ag-research-tracker.md`, `auto-generated/-ag-coverage-report-by-memory.md`, and project stats through validator-owned paths. Do not manually edit those files. If generated output is inspected after validation, compare generated headers against the returned command metadata or use `--wait-generated` if current generated output matters; proof: all scoped validators used `--wait-generated` and returned `generated_refresh: completed`. Generated outputs were validator-owned side effects only and were not manually edited.
- [x] Manual coverage exclusion: do not edit `by-memory/-coverage-report.md` or any `-coverage-report.md`. Do not provide manual row text for validator-owned `auto-generated/-ag-*` reports; update source metadata and rely on the validator refresh; proof: no manual coverage report was edited and no manual generated-report row text was added.
- [x] Do not edit project-level generated files, validator state/cache, lock files, IDA DB, generated reports, or generated C++ by hand; proof: only by-* source docs listed above and this Agent-B006 report were manually edited. Validator/tool-owned generated/state side effects occurred only through `tools/validator.py`.
- [x] Report execution remains supervisor-owned: after claim-by-claim implementation verification, the supervisor should execute the report with `python .\tools\validator.py execute_report B006 0001BL-MerchantDialogPaneBase-source-quality.md 0001BL --apply`; proof: report was not moved or executed by Agent-B006.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B006","command_id":"000000004165","destination_path":"executed-b-agent-research/B006/0001BL-MerchantDialogPaneBase-source-quality.md","details":"legacy registry reconstruction","event":"executed","source_path":"tools/leaser/Agents/Agent-B006/research/0001BL-MerchantDialogPaneBase-source-quality.md","timestamp":"2026-06-25T14:13:27","uid":"0001BL"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
