** TARGET-REPORT-UID:0003VG **
** AUTHOR-AGENT-ID:B002 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
** REPORT-VALIDATION-STATUS: needs-revalidation **
** REPORT-REVALIDATION-REASON: target_uid_unknown: 0003VG **
# 0003VG ArgumentedMenuMenuItemListRawContextConstructor Source-Quality Report

Agent: B002  
Assignment: `B002-goal2-argumented-menu-item-list-raw-context-constructor-source-quality-0003VG-20260619`  
Target UID: [UID:0003VG]  
Target path: `source-3/project-documentation/by-memory/0x0051f310-0x0051f37a.ArgumentedMenuMenuItemListRawContextConstructor.md`  
Required report path: `source-3/project-documentation/tools/leaser/Agents/Agent-B002/research/0003VG-ArgumentedMenuMenuItemListRawContextConstructor-source-quality.md`  
Report-only status: no by-* docs edited, and `by-memory/-coverage-report.md` was not edited.

## Executive Recommendation

Update [UID:0003VG] from `85/86` to `87/88`, keep `CANONICAL_OWNER:00000I`, `RECONSTRUCTABLE:TRUE`, and `EMITTER_UIDS:00000I`, and add first-draft C++ for an unreferenced retained constructor overload:

```cpp
ArgumentedMenuMenuItemList::ArgumentedMenuMenuItemList(
    unsigned char commandType,
    unsigned int ownerId,
    unsigned short listParameter,
    ArgumentedMenuMenuDialog *ownerDialog)
    : ListPane(0x410, 0x10, 0x16a, 0x18, 0, 1, 1)
{
    m_commandType = commandType;
    m_ownerId = ownerId;
    m_listParameter = listParameter;
    m_ownerDialog = ownerDialog;
}
```

This should be documented as source-shaped retained code with no proven live entry ref. The no-xref/no-IDA-function state remains the confidence cap, but it is not enough to keep the page C++-blank now that the signature, field widths, base constructor, owner route, and rejected alternatives are resolved to source-quality direction.

If the implementation pass also introduces or reuses an `ArgumentedMenuMenuItemRow` layout name, the `ListPane` first argument can be source-polished from `0x410` to `sizeof(ArgumentedMenuMenuItemRow)`. Do not do that only in this page unless the row struct is documented in support docs; the literal `0x410` is the lower-risk first draft.

## Evidence Checked

Primary target/support docs read:

- `by-memory/0x0051f310-0x0051f37a.ArgumentedMenuMenuItemListRawContextConstructor.md`
- `by-class/ArgumentedMenuMenuItemList.md`
- `by-file/ArgumentedMenuDialogs.md`
- `by-memory/0x0051e9a0-0x0051fc8d.ArgumentedMenuDialogs.md`
- `by-memory/0x0051f290-0x0051f30b.ArgumentedMenuMenuItemListCopyConstructor.md`
- `by-memory/0x0051f3c0-0x0051f44e.ArgumentedMenuMenuItemListRawAppendEntryHelper.md`
- `by-memory/0x0051f450-0x0051f4fe.ArgumentedMenuOpenBuyConfirmDialog.md`
- `by-memory/0x0051f510-0x0051f5a5.ArgumentedMenuOpenQuantityDialogOrSendSingle.md`
- `by-memory/0x0051f5b0-0x0051f63d.ArgumentedMenuMenuItemListSelectItemAndUpdateText.md`
- `by-memory/0x0051f640-0x0051f706.ArgumentedMenuSendItemQuantityPacket.md`
- `by-memory/0x0051f710-0x0051f71b.ArgumentedMenuMenuItemListForwardOwnerStateUpdate.md`
- `by-memory/0x0051f720-0x0051f840.ArgumentedMenuMenuItemListHandleMouseEvent.md`
- `by-memory/0x0051f840-0x0051fc8d.ArgumentedMenuMenuItemListDrawMenuItem.md`
- `by-memory/0x0051e9a0-0x0051f28d.ArgumentedMenuMenuDialog.md`
- `by-class/ArgumentedMenuMenuDialog.md`
- `by-item/ArgumentedItemPurchaseHelpers_51f450_51f640.md`
- `by-file/ArgumentedItemInputDialogs.md`
- `by-type/by-vtable/ArgumentedMenuDialogVtables.md`
- `by-memory/0x0061ec10-0x0061fa3c.MerchantMenuDialogReadOnlyData.md`
- `by-memory/0x004f3a50-0x004f3bb0.ListPaneConstructionAndBaseDestructor.md`
- `by-class/ListPane.md`
- `by-file/ListPane.md`
- `by-memory/0x004f3bb0-0x004f3f20.ListPaneItemSelectionStorageHelpers.md`

Searches and local checks:

- `rg` for `0003VG`, `ArgumentedMenuMenuItemListRawContextConstructor`, `0051f310`, `sub_4F3A50`, `sub_4F3C50`, `m_commandType`, `m_ownerId`, and related ArgumentedMenu names.
- `auto-generated/-ag-memory-coverage.md` confirms [UID:0003VG] is currently an emitting row through [UID:00000I] to `auto-generated/NexusTK/ui/dialogs/ArgumentedMenuDialogs.cpp`, with `code` still `no`.
- `by-memory/-coverage-report.md` current row checked for exact pending replacement text.
- Local section-mapped PE/Capstone disassembly of `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe` over:
  - `0x0051f290-0x0051f30b` copy constructor.
  - `0x0051f30b-0x0051f380` padding plus raw constructor.
  - `0x0051f380-0x0051f3c0` duplicate destructor glue/padding.
  - `0x0051f640-0x0051f706` packet helper.
  - `0x0051f710-0x0051f71b` owner forwarder.
  - `0x0051eb38-0x0051eba6` owning dialog inline list construction.
  - `0x0051feec` and `0x00520347` input-dialog calls to the copy constructor.
- Local PE scans for absolute VA, RVA, direct `E8/E9 rel32`, and conditional `0F 8x rel32` refs to `0x0051f310`, `0x0051f290`, `0x0051f3c0`, `0x004f3a50`, and vtable bases.
- `tools/int_convert.py` verified: `0x410` is decimal `1040`; `0x16a` is decimal `362`; `0x14c` is decimal `332`; `0x150` is decimal `336`; `0x154` is decimal `340`; `0x158` is decimal `344`.

I did not use live IDA MCP in this pass. Existing docs preserve B001/A002 live IDA facts; I independently rechecked the target bytes and refs from the local PE.

## Raw Constructor Findings

Exact raw body:

```asm
0051f310  push ebp
0051f311  mov ebp, esp
0051f313  push ecx
0051f314  push esi
0051f315  push 1
0051f317  push 1
0051f319  push 0
0051f31b  push 0x18
0051f31d  push 0x16a
0051f322  push 0x10
0051f324  mov esi, ecx
0051f326  push 0x410
0051f32b  mov [ebp-4], esi
0051f32e  call 0x004f3a50
0051f333  mov al, [ebp+8]
0051f336  mov [esi+0x14c], al
0051f33c  mov eax, [ebp+0x0c]
0051f33f  mov [esi+0x150], eax
0051f345  mov ax, [ebp+0x10]
0051f349  mov [esi+0x154], ax
0051f350  mov eax, [ebp+0x14]
0051f353  mov [esi+0x158], eax
0051f359  mov eax, esi
0051f35b  mov [esi], 0x0061f4c4
0051f361  mov [esi+0xa0], 0x0061f54c
0051f36b  mov [esi+0xa4], 0x0061f57c
0051f375  pop esi
0051f376  mov esp, ebp
0051f378  pop ebp
0051f379  ret 0x10
```

The body has a normal thiscall constructor shape: `ecx` is `this`, the four explicit stack slots are cleaned by `ret 0x10`, and field widths are narrower than the stack slots where appropriate. The source-facing signature should therefore use four logical arguments:

```cpp
ArgumentedMenuMenuItemList::ArgumentedMenuMenuItemList(
    unsigned char commandType,
    unsigned int ownerId,
    unsigned short listParameter,
    ArgumentedMenuMenuDialog *ownerDialog)
```

The constructor calls the established [UID:0003TZ] `ListPane::ListPane` at `0x004f3a50`, not an unresolved raw `sub_4F3A50`. The base constructor arguments are:

| Source argument position | Observed value | Best source meaning |
| --- | ---: | --- |
| 1 | `0x410` / 1040 | argumented row byte stride; likely `sizeof(ArgumentedMenuMenuItemRow)` once the row struct is documented |
| 2 | `0x10` / 16 | list cell/content width-style parameter, consistent with sibling menu list constructors |
| 3 | `0x16a` / 362 | list content height/extent-style parameter |
| 4 | `0x18` / 24 | row height |
| 5 | `0` | selection/mode flag false |
| 6 | `1` | enabled/visible/layout flag true |
| 7 | `1` | enabled/visible/layout flag true |

The exact ListPane parameter names are still a ListPane-wide open item, but the callee identity and values are resolved enough for this target's source draft. Do not leave `sub_4F3A50` in the target doc except as a historical generated/raw label.

## Field Names And Use-Site Reconciliation

The constructor arguments map directly to already documented `ArgumentedMenuMenuItemList` context fields:

| Offset | Width | Constructor source | Best field name | Evidence |
| --- | --- | --- | --- | --- |
| `this+0x14c` | byte | `[ebp+0x08]` low byte | `m_commandType` | `0x0051f640` serializes this byte after opcode `0x39`; dialog inline construction copies `ArgumentedMenuMenuDialog+0x274` here. |
| `this+0x150` | dword | `[ebp+0x0c]` | `m_ownerId` | `0x0051f640` writes this dword after the command byte; docs call it owner id / owner dialog id. |
| `this+0x154` | word | `[ebp+0x10]` low word | `m_listParameter` | `0x0051f640` writes this word; class/file docs call it list parameter. |
| `this+0x158` | pointer | `[ebp+0x14]` | `m_ownerDialog` | `0x0051f710` loads it and tail-forwards to owner `0x0049de70`; selection/update methods also update owner controls through it. |

The copy constructor at `0x0051f290` confirms the same layout by copying `source+0x150`, byte `source+0x14c`, word `source+0x154`, and `source+0x158` into the new list object. The order difference in the copy constructor is compiler scheduling, not a semantic field-order disagreement.

The owning dialog's inline list construction at `0x0051eb38-0x0051eba6` confirms the raw constructor is not fantasy code: it makes the same `ListPane::ListPane(0x410, 0x10, 0x16a, 0x18, 0, 1, 1)` call, stores the same `+0x14c/+0x150/+0x154/+0x158` context, and installs the same vtable trio `0x0061f4c4/0x0061f54c/0x0061f57c`.

## Liveness And No-Xref Interpretation

Local PE scan results:

| Target | Absolute VA hits | RVA hits | Direct rel32 hits |
| --- | ---: | ---: | --- |
| `0x0051f310` | 0 | 0 | 0 |
| `0x0051f290` | 0 | 0 | 2 (`0x0051feec`, `0x00520347`) |
| `0x0051f3c0` | 0 | 0 | 0 |
| `0x004f3a50` | 0 | 0 | 39 |

The no-xref result is real and should stay in the page. It means current binary liveness is unproven. It does not prove "padding" or "compiler glue" because:

- the range is alignment-separated after five `0xcc` bytes and before six `0xcc` bytes;
- it has a full prologue/epilogue, calls the live shared `ListPane::ListPane`, stores semantic list context, returns `this`, and uses `ret 0x10`;
- it has no destructor/free/delete shape and no base cleanup call;
- it is source-distinct from the live copy constructor because it takes four explicit context values rather than a source list pointer;
- the owning dialog contains an equivalent inline construction sequence, which supports this as a retained overload whose calls were optimized away or removed.

Best-supported interpretation: source had a constructor overload for explicit argumented-menu context, but this binary only reaches the inline construction path and the copy constructor path. Keep the raw/no-function caveat as a confidence cap, but emit a guarded first-draft constructor because reconstructable emitting targets over the gate should not stay blank once the source signature and fields are resolved.

## Owner And Source Placement

Keep the direct owner/emitter as [UID:00000I] `ArgumentedMenuMenuItemList`.

Source route:

```text
ArgumentedMenuMenuItemList
  -> ArgumentedMenuDialogs
  -> NexusTK/ui/dialogs/ArgumentedMenuDialogs.cpp
```

Rejected alternatives:

- `ArgumentedItemInputDialogs`: rejected as direct owner. Input dialog constructors call the live copy constructor and action handlers call the packet helper, but the target constructs the list context itself.
- `ListPane`: rejected as owner. `ListPane::ListPane` is only the base constructor callee; the vtable stores and fields are `ArgumentedMenuMenuItemList` specific.
- `ArgumentedMenuDialogs` broad aggregate [UID:0001BS]: rejected as emitter. It is a non-emitting split index; exact child pages own source.
- `TextMenuDialogs`: keep only as a folded-file possibility at the file-root level. It does not displace [UID:0000HI] as the current direct source route.
- compiler-generated glue / duplicate destructor: rejected by constructor shape, base construction, field stores, return `this`, and `ret 0x10`.
- raw append helper: rejected by lack of row stack record and no `ListPane::AddEntry`/`0x004f3c50` call.

## Open Questions Resolved Or Bounded

| Question | Resolution |
| --- | --- |
| Is `0x0051f310` a live callable entry? | Not proven. Local PE scan found no VA/RVA/rel32 refs; existing docs also report no IDA function/xrefs. Treat as retained unreferenced source overload. |
| Should the target emit C++? | Yes. The page is reconstructable, has owner/emitter [UID:00000I], clears the active combined gate, and the source signature/fields are now inferred with high confidence. The no-xref state caps confidence but is not a no-code proof. |
| What is `sub_4F3A50`? | Established `ListPane::ListPane` from [UID:0003TZ]/[UID:00007A]/[UID:0000KT]. |
| What are `+0x14c/+0x150/+0x154/+0x158`? | `m_commandType` byte, `m_ownerId` dword, `m_listParameter` word, and `m_ownerDialog` pointer. These names align with class docs, packet helper, forwarder, copy constructor, and owning dialog inline construction. |
| Does vtable order imply source statements after field assignment? | No. Vtable writes are compiler-generated constructor mechanics. Do not include them in C++ body. |
| Is the row type name known? | Not fully. Use literal `0x410` in the first draft unless an implementation pass documents a `ArgumentedMenuMenuItemRow` or equivalent 1040-byte record. |
| Should this split further? | No. The target is already exact `0x0051f310-0x0051f37a`. Padding before/after and duplicate destructor glue remain separate ignored rows. |

## Recommended Target Doc Changes

For `by-memory/0x0051f310-0x0051f37a.ArgumentedMenuMenuItemListRawContextConstructor.md`:

1. Change metadata:
   - `COMPLETION:85` -> `COMPLETION:87`
   - `CONFIDENCE:86` -> `CONFIDENCE:88`
   - Keep `CANONICAL_OWNER:00000I`
   - Keep `RECONSTRUCTABLE:TRUE`
   - Keep `EMITTER_UIDS:00000I`

2. Replace unresolved `sub_4F3A50` wording with `ListPane::ListPane()` / established shared ListPane constructor at `0x004f3a50`.

3. Add the constructor signature and field mapping:
   - `[ebp+0x08]` low byte -> `m_commandType` at `+0x14c`
   - `[ebp+0x0c]` dword -> `m_ownerId` at `+0x150`
   - `[ebp+0x10]` low word -> `m_listParameter` at `+0x154`
   - `[ebp+0x14]` pointer -> `m_ownerDialog` at `+0x158`

4. Add exact base constructor argument evidence:
   - `ListPane(0x410, 0x10, 0x16a, 0x18, 0, 1, 1)`
   - `0x410` is 1040-byte row stride; `0x16a` is 362; `0x18` is 24.

5. Preserve no-function/no-xref/no-pointer evidence, but change the interpretation from "liveness/signature unresolved, C++ blank" to "unreferenced retained constructor overload; liveness unproven but source signature resolved enough for guarded first-draft C++."

6. Add first-draft C++ exactly as shown in the Executive Recommendation unless support docs introduce the 1040-byte row struct during implementation.

## Recommended Support Doc Changes

`by-class/ArgumentedMenuMenuItemList.md`

- Refresh the [UID:0003VG] method row to say "retained explicit-context constructor overload" rather than generic raw context constructor/helper.
- Add that the explicit constructor signature is best reconstructed as:
  `ArgumentedMenuMenuItemList(unsigned char commandType, unsigned int ownerId, unsigned short listParameter, ArgumentedMenuMenuDialog *ownerDialog)`.
- Add that `m_commandType`, `m_ownerId`, `m_listParameter`, and `m_ownerDialog` are the source-facing field names for the `+0x14c/+0x150/+0x154/+0x158` storage.
- Keep a liveness caveat: no direct start xrefs or pointer hits to `0x0051f310`, but source shape and inline/copy-constructor comparison support retaining it as an overload.

`by-file/ArgumentedMenuDialogs.md`

- In Proposed Contents / Autogen status, mark [UID:0003VG] as ready for guarded first-draft constructor C++ under `ArgumentedMenuMenuItemList`.
- Preserve the possible fold into `TextMenuDialogs.cpp` only as a file-root source-split question; do not reroute the target away from [UID:0000HI].

`by-memory/0x0051e9a0-0x0051fc8d.ArgumentedMenuDialogs.md`

- In Covered Ranges, update the [UID:0003VG] row to "retained explicit-context constructor overload" and include the field names/signature.
- Keep this page non-emitting.

`by-memory/0x0051f290-0x0051f30b.ArgumentedMenuMenuItemListCopyConstructor.md`

- Add cross-note that the copy constructor copies the same four context fields from an existing list object, while [UID:0003VG] takes those four values explicitly.
- Preserve its own C++ blank state unless a separate source-quality pass resolves its exact copy-constructor declaration.

`by-memory/0x0051f640-0x0051f706.ArgumentedMenuSendItemQuantityPacket.md`

- Replace generic "context byte/dword/word fields" wording with the field names `m_commandType`, `m_ownerId`, and `m_listParameter`, while retaining widths and opcode `0x39`.

`by-type/by-vtable/ArgumentedMenuDialogVtables.md`

- Tighten the "raw/list helper stores" note to exact [UID:0003VG] vtable writes at `0x0051f35b`, `0x0051f361`, and `0x0051f36b`, plus duplicate destructor glue writes at `0x0051f383`, `0x0051f389`, and `0x0051f393`.

`by-type/by-struct` support

- If the implementation pass has an established row-layout page, add or cross-reference a 1040-byte `ArgumentedMenuMenuItemRow` or equivalent. If no row-layout page exists, do not block this target; keep the constructor C++ first argument as literal `0x410`.

## Exact Pending Coverage Row Text

Supervisor-owned replacement row for `by-memory/-coverage-report.md`:

```text
        - [UID:0003VG][0x0051f310-0x0051f37a.ArgumentedMenuMenuItemListRawContextConstructor](by-memory/0x0051f310-0x0051f37a.ArgumentedMenuMenuItemListRawContextConstructor.md) 0x0051f310-0x0051f37a | raw class constructor | ArgumentedMenuMenuItemListRawContextConstructor : reconstructable : 87% : strong : Raw no-function retained `ArgumentedMenuMenuItemList` explicit-context constructor overload; local PE/Capstone recheck confirms `ListPane::ListPane(0x410, 0x10, 0x16a, 0x18, 0, 1, 1)`, context args copied as `m_commandType` byte at `+0x14c`, `m_ownerId` dword at `+0x150`, `m_listParameter` word at `+0x154`, and `m_ownerDialog` pointer at `+0x158`, vtable stores `0x0061f4c4/0x0061f54c/0x0061f57c`, return `this`, `ret 0x10`, and zero direct start VA/RVA/rel32 refs. Emit guarded first-draft constructor C++; no-function/no-xref status remains the confidence cap.
```

No other coverage rows need replacement for this target. Existing padding rows `0x0051f30b-0x0051f310` and `0x0051f37a-0x0051f380` remain valid.

## Validation Commands Needed

Run from `source-3/project-documentation` after implementation:

> Executable block R001 was removed from this report and preserved verbatim in [0003VG-ArgumentedMenuMenuItemListRawContextConstructor-source-quality-removed.md](0003VG-ArgumentedMenuMenuItemListRawContextConstructor-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If the supervisor applies the coverage row, also validate:

> Executable block R002 was removed from this report and preserved verbatim in [0003VG-ArgumentedMenuMenuItemListRawContextConstructor-source-quality-removed.md](0003VG-ArgumentedMenuMenuItemListRawContextConstructor-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If adding the C++ block causes generated-output changes, run the repo's standard autogen/rescore workflow for the affected `ArgumentedMenuDialogs.cpp` output before supervisor verification.

## IDA Rename, Type, And Comment Recommendations

High confidence:

- Rename/comment `0x004f3a50` as `ListPane::ListPane` in target comments instead of `sub_4F3A50`.
- Keep vtable bases named as `ArgumentedMenuMenuItemList` primary/secondary/tertiary views:
  - `0x0061f4c4`
  - `0x0061f54c`
  - `0x0061f57c`
- Field names for `ArgumentedMenuMenuItemList`:
  - `+0x14c`: `m_commandType` (`unsigned char`)
  - `+0x150`: `m_ownerId` (`unsigned int`)
  - `+0x154`: `m_listParameter` (`unsigned short`)
  - `+0x158`: `m_ownerDialog` (`ArgumentedMenuMenuDialog *`)

Medium-high confidence:

- If IDA policy permits creating a function for unreferenced raw constructor bodies, define `0x0051f310-0x0051f37a` as:
  `ArgumentedMenuMenuItemList::ArgumentedMenuMenuItemList(unsigned char commandType, unsigned int ownerId, unsigned short listParameter, ArgumentedMenuMenuDialog *ownerDialog)`.
- If the project avoids creating functions for no-xref raw islands, leave it as raw bytes but add a repeatable comment at `0x0051f310` with the same signature and "no direct VA/RVA/rel32 refs found; retained explicit-context constructor overload".

Do not rename [UID:0003VG] as a copy constructor, destructor thunk, or append helper.

## Implementation Readiness

Ready for implementation after supervisor acceptance.

The only remaining risk is liveness, not source shape. The target should receive first-draft C++ with the explicit no-xref caveat and score cap. Support docs should absorb the field/signature/base-constructor details so future passes on [UID:0003VF], [UID:0003VH], and [UID:0003VL] can reuse the same names instead of reopening the context-layout question.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"command_id":"000000004167","details":"report marked for revalidation","event":"needs-revalidation","issue":"target_uid_unknown: 0003VG","source_path":"executed-b-agent-research/B002/0003VG-ArgumentedMenuMenuItemListRawContextConstructor-source-quality.md","timestamp":"2026-07-01T19:52:03-04:00"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
