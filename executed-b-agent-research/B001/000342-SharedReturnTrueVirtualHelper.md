** TARGET-REPORT-UID:000342 **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# Finalized Recommendation

Target: [UID:000342][0x004b0ba0-0x004b0ba5.SharedReturnTrueVirtualHelper](../../../../../by-memory/0x004b0ba0-0x004b0ba5.SharedReturnTrueVirtualHelper.md)  
Queue status: B001-055, supervisor-classified `reviewed-85-but-ownership-unknown-under-review`.

Recommendation: reclassify `000342` as an ignored/non-emitting folded event-handler virtual override body, keep `AUTOGEN_PARENT_UID` blank, and do not attach it to `ExchangeMoneyEditControlPane`, `ControlPane`, `Pane`, `EventHandler`, `EventDispatcher`, or any one concrete consumer class.

This is not an unresolved ownership failure. IDA proves the exact five-byte body is shared by multiple concrete secondary vtables whose source owners differ, while the candidate base classes/interfaces use different false-return or purecall defaults. The source-level C++ work belongs in the concrete class/vtable docs that declare the actual virtual overrides; this one physical function should not emit as a standalone reconstructed source function.

Final disposition after B001-055 repair:

| UID | Path | Before | After | Parent |
| --- | --- | --- | --- | --- |
| `000342` | `by-memory/0x004b0ba0-0x004b0ba5.SharedReturnTrueVirtualHelper.md` | `86/88`, `RECONSTRUCTABLE:TRUE` | `88/92`, `RECONSTRUCTABLE:FALSE` | blank by structure |
| `00014V` | `by-memory/0x004b0490-0x004b0ba5.ExchangeDialogTail.md` | already `90/92`, `RECONSTRUCTABLE:FALSE`; stale coverage row said `83`/reconstructable | remains `90/92`, `RECONSTRUCTABLE:FALSE` | blank mixed inventory |

Split requirement: no split required. The target is an indivisible `0x5` / 5-byte function body (`mov al,1; retn 4`). The correct repair is structural reclassification, plus documentation of the vtable-sharing evidence.

Supervisor-owned coverage-report action: do not edit `by-memory/-coverage-report.md` by hand during this task. Replace the stale `00014V` and `000342` rows in the current `0x004b0490` area with the exact rows below.

```text
    - [UID:00014V][0x004b0490-0x004b0ba5.ExchangeDialogTail](by-memory/0x004b0490-0x004b0ba5.ExchangeDialogTail.md) 0x004b0490-0x004b0ba5 | mixed split inventory | ExchangeDialogTail : ignored : 90% : very-strong : Parent-blank non-emitting split inventory for an interleaved exchange/item/mix/control helper island. B001-055 keeps the aggregate non-reconstructable after reclassifying exact child [UID:000342] as a folded/shared event-handler override body; exact source-bearing children such as [UID:00033Z], [UID:000340], and [UID:000341] carry their direct parents, while compiler thunks, padding, item/mix neighbors, and the folded return-true body do not emit from this aggregate.
        - [UID:000342][0x004b0ba0-0x004b0ba5.SharedReturnTrueVirtualHelper](by-memory/0x004b0ba0-0x004b0ba5.SharedReturnTrueVirtualHelper.md) 0x004b0ba0-0x004b0ba5 | folded event-handler virtual override body | SharedReturnTrueVirtualHelper : ignored : 88% : very-strong : B001-055 reclassified this exact `0x5` / 5-byte body (Verified with int_convert.py) as non-emitting compiler/linker folded/shared virtual override code: IDA confirms `mov al, 1; retn 4`, no callers, no callees, and seven secondary-vtable refs from `ExchangeMoneyEditControlPane`, `MapRefreshDimmer`, `ScreenDimmer`, and `InputBlockerPane`. EventDispatcher dispatches the relevant secondary slots, but base `EventHandler` has purecall entries and base `Pane`/`ControlPane` use false-return defaults, so there is no single direct source parent to assign. Reconstruct source-level overrides through concrete class/vtable pages; do not emit a standalone helper.
```

Placement context: replace the current `00014V` row immediately after the `0x004b048a-0x004b0490` padding row, and replace the current `000342` row immediately before the `0x004b0ba5-0x004b0bb0` padding row.

Confidence: `92/100` for the non-emitting folded-body disposition; `98/100` for the exact bytes, range, xrefs, and vtable-sharing facts; `85/100` for the still-unrecovered source-facing event slot names.

# Supporting Research

## Target Facts

- IDB: `NexusTK.exe`, MD5 `4247e04e20b65d6414c7238aa8ff5515`, SHA256 `9aec210bbc5ce592176a21dd8e9d9fd8f250b8d9ea78237915a99ba8cfa9a632`.
- IDA function: `sub_4B0BA0`, range `0x004b0ba0-0x004b0ba5`, size `0x5` / 5 bytes (Verified with `int_convert.py`).
- Disassembly/decompile: `mov al, 1; retn 4`, decompiled as returning `1`.
- Stack convention: `retn 4` consumes one argument, `0x4` / 4 bytes (Verified with `int_convert.py`).
- Boundary evidence: predecessor `0x004b0b96-0x004b0ba0` is ten `0xcc` bytes; successor `0x004b0ba5-0x004b0bb0` is eleven `0xcc` bytes. `0x004b0bb0` starts [UID:00014Z][FieldMapPane](../../../../../by-memory/0x004b0bb0-0x004b129b.FieldMapPane.md).
- Direct call graph: no ordinary callers and no callees.

## IDA Vtable Evidence

Live IDA MCP `xrefs_to 0x004b0ba0` reports exactly seven data xrefs, all from secondary event-handler vtable cells:

| Ref | Owning table evidence | Slot role |
| --- | --- | --- |
| `0x0061a2d0` | `ExchangeMoneyEditControlPane` secondary vtable | slot 1 true-return override |
| `0x0061e8a8` | `MapRefreshDimmer` secondary vtable | slot 1 true-return override |
| `0x0061e8ac` | `MapRefreshDimmer` secondary vtable | slot 2 true-return override |
| `0x006234d4` | `ScreenDimmer` secondary vtable | slot 1 true-return override |
| `0x006234d8` | `ScreenDimmer` secondary vtable | slot 2 true-return override |
| `0x0062f01c` | `InputBlockerPane` secondary vtable | slot 1 true-return override |
| `0x0062f020` | `InputBlockerPane` secondary vtable | slot 2 true-return override |

The four containing secondary vtables are each an 11-slot `0x2c` / 44-byte table body (Verified with `int_convert.py`) after the RTTI-adjacent dword. IDA vtable-store refs confirm they are concrete class tables:

- `ExchangeMoneyEditControlPane` secondary table refs from `0x004accd9` and `0x004b0a6c`.
- `MapRefreshDimmer` secondary table refs from `0x00506fd5` and `0x00514974`.
- `ScreenDimmer` secondary table refs from `0x00559c04`, `0x00559d1d`, and `0x0055a09d`.
- `InputBlockerPane` secondary table refs from `0x005a7d5f` and `0x005abd18`.

`EventDispatcher::CallHandler` at `0x004a77d0` dispatches these secondary-event slots: slot `+0x04` for one event category, slot `+0x08` for another event category, and slot `+0x28` / 40 bytes as an active/eligible predicate (Verified with `int_convert.py`). That proves the references are real event-handler virtual dispatch slots, not arbitrary pointer-table noise.

## Negative Base-Class Evidence

The strongest prior competing inference was that this might belong to a base UI/event class. IDA contradicts that:

- Base `EventHandler` vtable `0x00619674` has `__purecall` in slots 1 through 6, not `0x004b0ba0`.
- Base `Pane` secondary vtable `0x00621a34` uses false-return bodies `0x00544db0` and `0x00544dc0` for slots 1 and 2.
- Base `ControlPane` secondary vtable `0x00617af8` uses false-return defaults `0x00544db0` and `0x0041d6b0` for slots 1 and 2.

So `Pane`, `ControlPane`, and `EventHandler` define the interface/layout, but they do not own this true-return body. The body exists only in concrete override slots.

## Candidate Owner Ranking

1. Accepted: non-emitting folded/shared concrete override body. This best matches the facts: one tiny body, no callers/callees, only vtable data refs, refs from multiple concrete owners, and base interfaces that do not contain this implementation. The source reconstruction should express the source-level overrides in the concrete classes, not emit a fake common helper.

2. Rejected: [UID:00004T][ExchangeMoneyEditControlPane](../../../../../by-class/ExchangeMoneyEditControlPane.md). It has the nearest text address and one vtable ref, but six other refs are outside exchange ownership. Assigning the body to ExchangeMoney would turn unrelated `MapRefreshDimmer`, `ScreenDimmer`, and `InputBlockerPane` override cells into consumers of an exchange-owned function, which is not a defensible original source model.

3. Rejected: [UID:000038][ControlPane](../../../../../by-class/ControlPane.md). Prior notes cited ControlPane as below gate, but the stronger issue is structural: IDA shows ControlPane does not use this function in the relevant slots. It uses false-return defaults.

4. Rejected: [UID:0000A2][Pane](../../../../../by-class/Pane.md). Pane is a broad UI base and also uses false-return slot defaults, so it cannot own this true-return override body.

5. Rejected: [UID:00004N][EventHandler](../../../../../by-class/EventHandler.md) or [UID:00004M][EventDispatcher](../../../../../by-class/EventDispatcher.md). EventHandler defines abstract/pure virtual slots, and EventDispatcher calls through them. Neither owns the concrete true-return implementation.

6. Rejected as individual direct owners: [UID:00007S][MapRefreshDimmer](../../../../../by-class/MapRefreshDimmer.md), [UID:0000C8][ScreenDimmer](../../../../../by-class/ScreenDimmer.md), or a future exact `InputBlockerPane` page. Each owns some source-level overrides, but none owns the shared physical code body for all four classes.

7. Rejected: new source helper/global owner. There is no code caller, no symbol/name pattern, and no table indicating an intentional reusable helper function. The body looks like folded compiler/linker output from identical virtual overrides, not a handwritten shared API.

## Documentation Repairs Made

Edited under lease:

- [UID:000342][SharedReturnTrueVirtualHelper](../../../../../by-memory/0x004b0ba0-0x004b0ba5.SharedReturnTrueVirtualHelper.md)
  - Changed `COMPLETION:86` to `88`.
  - Changed `CONFIDENCE:88` to `92`.
  - Changed `RECONSTRUCTABLE:TRUE` to `FALSE`.
  - Kept parent blank and documented the folded/non-emitting disposition.
  - Added IDA-backed vtable, base-rejection, EventDispatcher, padding, and score rationale evidence.

- [UID:00014V][ExchangeDialogTail](../../../../../by-memory/0x004b0490-0x004b0ba5.ExchangeDialogTail.md)
  - Kept `90/92`, `RECONSTRUCTABLE:FALSE`, parent blank.
  - Updated the `000342` covered-range row and score rationale to reflect the non-emitting folded body decision.

- [UID:0000VN][-ignored](../../../../../by-memory/-ignored.md)
  - Added the exact ignored-range entry for `0x004b0ba0-0x004b0ba5`.
  - The ledger entry records why the physical body is ignored and points source-level reconstruction to the concrete class/vtable docs.

No direct edit was made to `by-memory/-coverage-report.md`, supervisor notes, or generated/project-level reports. Validator `--apply` did refresh validator metadata and projected stats as a tool-managed side effect.

## Validation

Commands run from `E:\NTK\GhidraBridge\source-3\project-documentation`:

> Executable block R001 was removed from this report and preserved verbatim in [000342-SharedReturnTrueVirtualHelper-removed.md](000342-SharedReturnTrueVirtualHelper-removed.md). The archived block is non-authoritative and must not be executed.

Results:

- `SharedReturnTrueVirtualHelper`: exit `0`, `scanned markdown files: 1`, `ok: 1`; apply run registered `COMPLETION:88`, `CONFIDENCE:92`, and `RECONSTRUCTABLE:false`.
- `ExchangeDialogTail`: exit `0`, `scanned markdown files: 1`, `ok: 1`.
- `-ignored.md`: exit `0`, `scanned markdown files: 1`, `ok: 1`; apply run added reference-index edges for `00007S`, `0000C8`, and `000342`, rebuilt `validator.ini`, and reported generated C++/report noops.

## Leases

Leases used for project documentation edits:

- `by-memory/0x004b0ba0-0x004b0ba5.SharedReturnTrueVirtualHelper.md`
- `by-memory/0x004b0490-0x004b0ba5.ExchangeDialogTail.md`
- `by-memory/-ignored.md`

The final lease release/check is recorded in the chat final response.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B001","command_id":"000000004165","destination_path":"executed-b-agent-research/B001/000342-SharedReturnTrueVirtualHelper.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:22","uid":"000342"} -->
<!-- {"agent":"B001","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 000342-SharedReturnTrueVirtualHelper-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B001/000342-SharedReturnTrueVirtualHelper.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"000342"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
