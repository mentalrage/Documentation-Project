*** UID:000040 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:87 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000JO | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000JO | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
// Concrete UserPane item-action callback instantiation.
// The reusable FunctionObjects template declaration is emitted by [UID:0001WQ][FunctionObjectTemplates](by-type/by-template/FunctionObjectTemplates.md);
// concrete allocation and binding are emitted by [UID:0002VM][0x005b7450-0x005b74dd.CreateUserPaneDoubleParamCallback](by-memory/0x005b7450-0x005b74dd.CreateUserPaneDoubleParamCallback.md), and the invoke wrapper is covered by [UID:0001N5][0x005b77b0-0x005b77c8.UserPaneDoubleParamCallback](by-memory/0x005b77b0-0x005b77c8.UserPaneDoubleParamCallback.md).
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# DoubleParamMemberFunctionObject0_void____thiscall_UserPane_____signed_char__h43ff6c8e0528

## Status

- Confidence: very strong for the concrete `UserPane` slot/bool callback role, field layout, vtable route, and four construction callers.
- Likely source: [UID:0000JO][FunctionObjects](by-file/FunctionObjects.md) template support, instantiated by drop/give input pane code.
- Rebuild handling: `source-declared/generated-binary`; the rebuilt source should declare the reusable callback template and let the compiler emit the concrete instantiation.
- Constructor helper: [UID:0002VM][0x005b7450-0x005b74dd.CreateUserPaneDoubleParamCallback](by-memory/0x005b7450-0x005b74dd.CreateUserPaneDoubleParamCallback.md)
- Related memory: [UID:0001N5][0x005b77b0-0x005b77c8.UserPaneDoubleParamCallback](by-memory/0x005b77b0-0x005b77c8.UserPaneDoubleParamCallback.md)
- Vtable data: [UID:0002YW][0x00630a78-0x00630a90.UserPaneDoubleParamCallbackVtableData](by-memory/0x00630a78-0x00630a90.UserPaneDoubleParamCallbackVtableData.md)
- Reconstructable class/template instantiation attached to [UID:0000JO][FunctionObjects](by-file/FunctionObjects.md). Formal class C++ remains blank here because the reusable template declaration belongs in the FunctionObjects/template docs and [UID:0002VM][0x005b7450-0x005b74dd.CreateUserPaneDoubleParamCallback](by-memory/0x005b7450-0x005b74dd.CreateUserPaneDoubleParamCallback.md) carries the source-equivalent emitted factory body; exact original header spelling is still open but no longer blocks this concrete instantiation route.

## Class Purpose

This callback wrapper binds a `UserPane` member function with two captured arguments: a signed slot byte and an all-items boolean. Current IDA MCP evidence ties construction to drop/give confirmation prompt paths. The clearer source-facing alias is:

```cpp
typedef void (__thiscall UserPane::*UserPaneItemActionCallback)(signed char, bool);
typedef DoubleParamMemberFunctionObject0<UserPaneItemActionCallback, UserPane, signed char, bool>
    UserPaneItemActionCallbackObject;
```

Use the short alias in prose and local draft code instead of forcing the full decorated compiler class spelling into final source.

## B014 Source-Quality Verification

B014 direct PE reanalysis keeps this concrete wrapper attached to [UID:0000JO][FunctionObjects](by-file/FunctionObjects.md) and confirms the source-facing type direction:

```cpp
DoubleParamMemberFunctionObject0<
    void (UserPane::*)(signed char, bool),
    UserPane,
    signed char,
    bool>
```

The decorated vtable spelling at `0x00630a78` is `??_7?$DoubleParamMemberFunctionObject0@P8UserPane@@AEXC_N@ZV1@C_N@@6B@`, which confirms the `UserPane`, signed-char slot, and bool/all-items template shape. The exact original header basename and template spelling are still inferred, so keep the long slug as a compiler/documentation identifier and use `DoubleParamMemberFunctionObject0<UserPane, signed char, bool>` or `UserPaneItemActionCallbackObject` as the source-facing prose name.

The exact invoke body [UID:0001N5][0x005b77b0-0x005b77c8.UserPaneDoubleParamCallback](by-memory/0x005b77b0-0x005b77c8.UserPaneDoubleParamCallback.md) must stay generated-template proof, not a handwritten standalone function body. B014 scans found no direct rel32 caller route to the invoke wrapper, one vtable pointer at `0x00630a84`, and construction helper [UID:0002VM][0x005b7450-0x005b74dd.CreateUserPaneDoubleParamCallback](by-memory/0x005b7450-0x005b74dd.CreateUserPaneDoubleParamCallback.md) stores the vtable at `0x005b7495`. This is the expected source-declared/generated-binary route for a reusable function-object template instantiation.

B014 also confirms the two bound `UserPane` member targets: `0x005ad7a0` sends drop opcode `0x08`, and `0x005ad720` sends give opcode `0x29`. Both consume `(signed char slot, bool allItems)`, queue three bytes through [UID:0000Q5][g_packetSender](by-global/g_packetSender.md), and do not dereference `ecx`; the member-function-pointer type and the captured [UID:0000QK][g_pCollectionData](by-global/g_pCollectionData.md) / `g_pUserPane` target still make them `UserPane` callback methods rather than free functions.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| construction helper | `0x005b7450-0x005b74dd` | Allocates a 24-byte callback object, initializes the function-object base, installs vtable `0x00630a78`, and stores `m_callback`, `m_thisAdjust`, `m_target`, `m_slot`, and `m_allItems`. |
| `Invoke` | `0x005b77b0-0x005b77c8` | Applies `m_thisAdjust` to `m_target` and calls the captured `UserPane` callback as `(adjustedTarget->*m_callback)(m_slot, m_allItems)`. |
| vtable data | `0x00630a78-0x00630a90` | Compiler-emitted `DoubleParamMemberFunctionObject0<UserPane,...>` vtable split from the UserPane prompt string island. |

## Field Layout

| Offset | Field | Meaning |
| --- | --- | --- |
| `+0x00` | vtable | [UID:0002YW][0x00630a78-0x00630a90.UserPaneDoubleParamCallbackVtableData](by-memory/0x00630a78-0x00630a90.UserPaneDoubleParamCallbackVtableData.md) |
| `+0x08` | `m_callback` | `UserPane::SendDropItemPacket(signed char,bool)` or `UserPane::SendGiveItemPacket(signed char,bool)` |
| `+0x0c` | `m_thisAdjust` | Member-function this adjustment; zero in the current four callers. |
| `+0x10` | `m_target` | Captured [UID:0000QK][g_pCollectionData](by-global/g_pCollectionData.md) / source-facing `g_pUserPane` target viewed as `UserPane *`. |
| `+0x14` | `m_slot` | Captured signed inventory slot. |
| `+0x15` | `m_allItems` | `true` for DropAll/GiveAll, `false` for Drop/Give. |

## Dispatch Route

The four construction callers are [UID:000042][DropAllInputPane](by-class/DropAllInputPane.md), [UID:000044][DropInputPane](by-class/DropInputPane.md), [UID:00005S][GiveAllInputPane](by-class/GiveAllInputPane.md), and [UID:00005U][GiveInputPane](by-class/GiveInputPane.md). Drop callers bind `UserPane::SendDropItemPacket(signed char,bool)` at `0x005ad7a0`; give callers bind `UserPane::SendGiveItemPacket(signed char,bool)` at `0x005ad720`. Each caller immediately passes the constructed action object to [UID:0001N4][0x005b75d0-0x005b760e.ConfirmInputPaneConstructor](by-memory/0x005b75d0-0x005b760e.ConfirmInputPaneConstructor.md), which stores it at `ConfirmInputPane + 0x108`. [UID:000366][0x004f2a10-0x004f2a58.ConfirmInputPaneInvokeAcceptedAction](by-memory/0x004f2a10-0x004f2a58.ConfirmInputPaneInvokeAcceptedAction.md) later invokes the `+0x0c` virtual slot only after a `y`/`Y` response, reaching [UID:0001N5][0x005b77b0-0x005b77c8.UserPaneDoubleParamCallback](by-memory/0x005b77b0-0x005b77c8.UserPaneDoubleParamCallback.md).

## Evidence Notes

- IDA `lookup_funcs` confirms `sub_5B7450` as a real `0x8d` byte construction helper and `sub_5B77B0` as a real `0x18` byte invoke wrapper.
- IDA `decompile 0x005b7450` shows allocation of 24 bytes, base initializer `sub_4F4A80`, vtable store `0x00630a78`, callback pointer at `+0x08`, object adjustment at `+0x0c`, target object pointer at `+0x10`, slot byte at `+0x14`, and bool flag at `+0x15`.
- IDA `decompile 0x005b77b0` shows the invoke wrapper calling `*(this + 0x08)` with adjusted target `*(this + 0x0c) + *(this + 0x10)` and the captured bytes at `+0x14` / `+0x15`.
- IDA `callers` / `xrefs_to 0x005b7450` report four construction callers from [UID:000042][DropAllInputPane](by-class/DropAllInputPane.md), [UID:000044][DropInputPane](by-class/DropInputPane.md), [UID:00005S][GiveAllInputPane](by-class/GiveAllInputPane.md), and [UID:00005U][GiveInputPane](by-class/GiveInputPane.md).
- IDA `xrefs_to 0x005b77b0` reports the vtable/data reference at `0x00630a84`; direct callers are absent, matching virtual callback dispatch.
- Byte checks confirm `0x005b7447-0x005b7450` and `0x005b74dd-0x005b74e0` are `0xcc` padding around the construction helper, and `0x005b77c8` starts the next function after the invoke wrapper.
- 2026-06-07 Batch 050 live IDA MCP rechecked the vtable data child: `0x00630a78` is named as the concrete `DoubleParamMemberFunctionObject0<UserPane,...>` vtable, `0x005b7495` stores that vtable in the construction helper, `0x00630a84` points to the invoke wrapper at `0x005b77b0`, and `0x00630a90` starts the following drop-confirmation string.
- 2026-06-20 B003 Rule 26 reanalysis resolves the concrete source-facing alias, field names, callback methods, and ConfirmInputPane dispatch route. Exact original template header spelling remains a final-source question, but the concrete instantiation is source-quality ready for owner/emitter routing.

## Cross-References

- [UID:0000JO][FunctionObjects](by-file/FunctionObjects.md)
- [UID:0001WQ][FunctionObjectTemplates](by-type/by-template/FunctionObjectTemplates.md)
- [UID:0002VM][0x005b7450-0x005b74dd.CreateUserPaneDoubleParamCallback](by-memory/0x005b7450-0x005b74dd.CreateUserPaneDoubleParamCallback.md)
- [UID:0002YW][0x00630a78-0x00630a90.UserPaneDoubleParamCallbackVtableData](by-memory/0x00630a78-0x00630a90.UserPaneDoubleParamCallbackVtableData.md)
- [UID:0000FQ][UserPane](by-class/UserPane.md)
- [UID:0000P1][UserPane](by-file/UserPane.md)
- [UID:000042][DropAllInputPane](by-class/DropAllInputPane.md)
- [UID:000044][DropInputPane](by-class/DropInputPane.md)
- [UID:00005S][GiveAllInputPane](by-class/GiveAllInputPane.md)
- [UID:00005U][GiveInputPane](by-class/GiveInputPane.md)

## 2026-06-29 Empty-Emitter Closeout

This concrete `UserPane` item-action callback instantiation now carries a formal covered-by marker instead of duplicating the shared template declaration. Current MCP evidence confirms UID0002VM allocates 24 bytes, installs vtable `0x00630a78`, stores callback/adjustor/target at `+8/+12/+16`, and stores bound byte arguments at `+20/+21`. The reusable declaration is emitted by [UID:0001WQ][FunctionObjectTemplates](by-type/by-template/FunctionObjectTemplates.md), the source-equivalent factory is emitted by [UID:0002VM][0x005b7450-0x005b74dd.CreateUserPaneDoubleParamCallback](by-memory/0x005b7450-0x005b74dd.CreateUserPaneDoubleParamCallback.md), and the invoke wrapper is covered by [UID:0001N5][0x005b77b0-0x005b77c8.UserPaneDoubleParamCallback](by-memory/0x005b77b0-0x005b77c8.UserPaneDoubleParamCallback.md).

The child vtable row [UID:0002YW][0x00630a78-0x00630a90.UserPaneDoubleParamCallbackVtableData](by-memory/0x00630a78-0x00630a90.UserPaneDoubleParamCallbackVtableData.md) remains compiler-emitted vtable data and carries a no-raw-vtable marker. This class row remains the concrete instantiation anchor for that data; it should not hand-port vtable dwords or duplicate the central template declarations.

## Changes

- 2026-06-22 B014 Rule 26 source-quality verification:
  - Score remains `87/90`; B014 corroborates the already-incorporated owner/emitter route through [UID:0000JO][FunctionObjects](by-file/FunctionObjects.md).
  - Added the full source-facing template direction, decorated-vtable evidence, direct no-route/vtable-only invoke evidence, generated-template no-handwritten-body policy, and bound `UserPane` packet-target behavior.
- 2026-06-20 B003 Rule 26 source-quality incorporation:
  - Changed from `85/89` to `87/90`.
  - Added `UserPaneItemActionCallback` / `UserPaneItemActionCallbackObject` source aliases, field names `m_callback`, `m_thisAdjust`, `m_target`, `m_slot`, and `m_allItems`, and the four-caller ConfirmInputPane route.
  - Replaced stale below-95 final-source wording with the current split: [UID:0002VM][0x005b7450-0x005b74dd.CreateUserPaneDoubleParamCallback](by-memory/0x005b7450-0x005b74dd.CreateUserPaneDoubleParamCallback.md) carries the source-equivalent factory body, while this class page documents the reusable generated-template instantiation.
- 2026-06-05: Marked `RECONSTRUCTABLE:TRUE` after live IDA MCP on `NexusTK.exe` confirmed the callback invoke wrapper at `0x005b77b0` as a real `0x18` byte function. At that point, `AUTOGEN_PARENT_UID` stayed blank because the callback-instantiation page was below the 80 completion parent-attachment gate even though [UID:0000JO][FunctionObjects](by-file/FunctionObjects.md) was the likely source-family parent.
- 2026-06-05: Raised from `76/84` to `84/88` and attached to [UID:0000JO][FunctionObjects](by-file/FunctionObjects.md).
  - Before: the page still cited stale provenance, lacked the exact construction helper page, and stayed below the parent-attachment gate.
  - After: removed stale provenance, documented current IDA evidence for both constructor helper and invoke wrapper, linked the new [UID:0002VM][0x005b7450-0x005b74dd.CreateUserPaneDoubleParamCallback](by-memory/0x005b7450-0x005b74dd.CreateUserPaneDoubleParamCallback.md) split, and attached the class/template instantiation to the FunctionObjects source family.
  - Evidence: current IDA MCP confirms `0x005b7450-0x005b74dd`, `0x005b77b0-0x005b77c8`, vtable `0x00630a78`, invoke slot `0x00630a84`, object fields, four drop/give callers, and adjacent padding.
- 2026-06-07 Batch 050 vtable-child split:
  - Before: `84/88`, with constructor and invoke evidence but the `.rdata` vtable still embedded only in the broad UserPane strings page.
  - After: `85/89`, adding [UID:0002YW][0x00630a78-0x00630a90.UserPaneDoubleParamCallbackVtableData](by-memory/0x00630a78-0x00630a90.UserPaneDoubleParamCallbackVtableData.md) as the exact compiler-emitted vtable child.
  - Evidence: live IDA MCP confirms vtable base `0x00630a78`, construction-store xref `0x005b7495`, invoke slot `0x00630a84 -> 0x005b77b0`, and `0x00630a90` as the following string boundary.
- 2026-05-30:
  - Before: completion/confidence metadata was left at unevaluated `0/0`.
  - After: scored as `76/84`.
  - Summary/evidence: callback wrapper role, invoke method, vtable xref, object layout, and drop/give `UserPane` construction-site ownership are documented; remaining uncertainty is final source-facing template/header spelling.
