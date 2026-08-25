*** UID:0000LZ | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:89 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:93 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/dialogs/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:FILE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# NexonclubProxyDialog

## Status

- Confidence: very strong for declaration-before-definition order, direct Pursuit base, constructor/callback behavior, callback-object construction, and source-folder placement; the possible registration-flow merge remains a packaging caveat only.
- Proposed module: `NexusTK/ui/dialogs/NexonclubProxyDialog.cpp`
- Current recovered source: `source-3/simroot_v2/class_NexonclubProxyDialog.cpp`
- Main memory range: [UID:0001FK][0x00553610-0x005538fd.NexonclubProxyDialogConstructor](by-memory/0x00553610-0x005538fd.NexonclubProxyDialogConstructor.md)
- Supporting read-only data: [UID:000268][0x006224c0-0x00622d24.MessageDialogReadOnlyData](by-memory/0x006224c0-0x00622d24.MessageDialogReadOnlyData.md)

## File Role

`NexonclubProxyDialog` is a small anonymous-namespace packet adapter that directly derives from [UID:0000BE][PursuitMessageDialogPane](by-class/PursuitMessageDialogPane.md). It parses a proxy dialog packet, creates a callback object targeting its private reply member, and opens [UID:0000M0][NexonclubRegistrationDialog](by-file/NexonclubRegistrationDialog.md).

This source may eventually fold into `NexonclubRegistrationDialog.cpp` if original-source evidence favors one file for the whole registration flow. Current class identity, anonymous-namespace vtables, and compact constructor make a separate staging file useful.

The projected reconstruction folder is `NexusTK/ui/dialogs/`, matching the packet-driven dialog cluster in [UID:0001R1][proposed-source-tree](by-project-structure/proposed-source-tree.md). That project-structure page keeps `TextDialog.cpp`, `NexonclubProxyDialog.cpp`, and `NexonclubRegistrationDialog.cpp` adjacent and records the same IDA-confirmed function starts for the split.

The current source-placement decision treats this as a compact private proxy adapter, not `TextDialog`, not a generic message-dispatch source, and not the registration-dialog owner after construction. [UID:00023M][0x0054c200-0x0054caa9.MessageDialogPacketDispatcherAndWrappers](by-memory/0x0054c200-0x0054caa9.MessageDialogPacketDispatcherAndWrappers.md) is the caller/dispatcher wrapper that allocates and calls this constructor; [UID:0000M0][NexonclubRegistrationDialog](by-file/NexonclubRegistrationDialog.md) is the callee/consumer that receives the decoded prompt and result callback. A future source-tree pass may fold this small adapter into a broader dialog source file only if stronger original-source packaging evidence appears; that packaging uncertainty is not an ownership or C++ blocker for the current exact by-memory pages.

B010 2026-07-01 support sync: [UID:00023M][0x0054c200-0x0054caa9.MessageDialogPacketDispatcherAndWrappers](by-memory/0x0054c200-0x0054caa9.MessageDialogPacketDispatcherAndWrappers.md) owns the wrapper call site `0x0054c9f0 -> new NexonclubProxyDialog(payload)`. This page keeps proxy constructor internals, callback wiring, and registration handoff ownership.

The source unit now has complete declaration ordering:

1. source-position-zero [UID:00009H][NexonclubProxyDialog](by-class/NexonclubProxyDialog.md) declaration and required include surface;
2. [UID:0003GL][0x005534a0-0x00553609.NexonclubProxyDialogReplyCallback](by-memory/0x005534a0-0x00553609.NexonclubProxyDialogReplyCallback.md) private callback definition;
3. [UID:0001FK][0x00553610-0x005538fd.NexonclubProxyDialogConstructor](by-memory/0x00553610-0x005538fd.NexonclubProxyDialogConstructor.md) constructor definition through `[[CHILDREN]]`.

The class adds no data members because allocation size `0x278` equals the Pursuit base size. It inherits the four packet members and protected current-dialog fallback method.

## Proposed Contents

| Entity | Address evidence | Role |
| --- | --- | --- |
| proxy reply callback | [UID:0003GL][0x005534a0-0x00553609.NexonclubProxyDialogReplyCallback](by-memory/0x005534a0-0x00553609.NexonclubProxyDialogReplyCallback.md) | `NexonclubProxyDialog::OnReplyText`; bound member body that serializes opcode `0x3a` registration reply text, handles empty/cancel fallback, and closes the dialog. |
| `NexonclubProxyDialog` | [UID:0001FK][0x00553610-0x005538fd.NexonclubProxyDialogConstructor](by-memory/0x00553610-0x005538fd.NexonclubProxyDialogConstructor.md) | `NexonclubProxyDialog::NexonclubProxyDialog`; parses proxy packet fields, constructs the `OnReplyText` callback wrapper, and launches the registration dialog. |
| adjustor/destructor thunks | `0x005539c3-0x005539d8` | Disabled generated thunks with owner/base-label pollution; keep as compiler glue pending final inheritance cleanup. |
| anonymous-namespace vtables | [UID:0003DE][0x00622c54-0x00622cf0.NexonclubProxyDialogVtableData](by-memory/0x00622c54-0x00622cf0.NexonclubProxyDialogVtableData.md) | Read-only data island proves an independent local proxy class rather than a trailing `TextDialog` body. |
| member-function callback table | [UID:0003GK][PlainMemberFunctionObjectT_NexonclubProxyDialogStringCallback](by-class/PlainMemberFunctionObjectT_NexonclubProxyDialogStringCallback.md) / `0x00622cf4` | Concrete proxy-dialog string callback wrapper used by the constructor's reply object and regenerated from source declarations/template instantiation. |

## Function Map

| Range | Function | Notes |
| --- | --- | --- |
| `0x005534a0-0x00553609` | `NexonclubProxyDialog::OnReplyText` | Bound callback member stored into the callback wrapper at `0x00553895`; builds opcode `0x3a` reply packets from the callback string. |
| `0x00553610-0x005538fd` | `NexonclubProxyDialog::NexonclubProxyDialog` | Source-initializes `PursuitMessageDialogPane()`, assigns inherited packet state in exact observed order, parses text/button/object fields, allocates a callback, and constructs `NexonclubRegistrationDialog`. |
| `0x005539ce-0x005539d8` | thunk | Current generated disabled source labels this through another dialog base; treat the label as polluted until the actual base path is reconciled. |

## Ownership Notes

- The constructor calls [UID:0000M0][NexonclubRegistrationDialog](by-file/NexonclubRegistrationDialog.md) and passes a callback that targets [UID:0003GL][0x005534a0-0x00553609.NexonclubProxyDialogReplyCallback](by-memory/0x005534a0-0x00553609.NexonclubProxyDialogReplyCallback.md).
- 2026-06-12 live IDA MCP recheck shows the constructor creates [UID:0003GK][PlainMemberFunctionObjectT_NexonclubProxyDialogStringCallback](by-class/PlainMemberFunctionObjectT_NexonclubProxyDialogStringCallback.md): it allocates 24 bytes, writes vtable `0x00622cf4`, stores callback target `0x005534a0`, zero adjustment, and bound proxy object, then passes the object to `NexonclubRegistrationDialog`.
- 2026-06-26 B008 reanalysis resolves the source-facing fields as `m_dialogType`, `m_dialogId`, `m_dialogState`, and `m_dialogPageIndex`. The constructor writes those fields from packet header/status words, while `OnReplyText` reuses them to build the opcode `0x3a` reply packet and sends `m_dialogPageIndex + 1`.
- RTTI class hierarchy descriptor `0x0064e85c` and base array `0x0064e86c` prove direct Pursuit inheritance through descriptor `0x0064e3a4`. The machine-level direct DialogPane call is inlined base lowering, not the human source initializer.
- Do not attach this constructor to [UID:0000OL][TextDialog](by-file/TextDialog.md) or [UID:0000JT][HeadSelectDialog](by-file/HeadSelectDialog.md) by address locality. Its vtable names and behavior form a separate registration proxy.
- The generated `struct_path` uses an anonymous namespace, which supports a small private adapter class shape.
- Shared default destructor note: the anonymous proxy primary vtable slot `0x00622c58` uses [UID:0001C0][0x00520b70-0x00520bab.SharedDialogDefaultScalarDestructor](by-memory/0x00520b70-0x00520bab.SharedDialogDefaultScalarDestructor.md), with secondary/tertiary slots routed through [UID:00023N][0x005539c3-0x005539d9.SharedDialogDefaultDestructorThunksLate](by-memory/0x005539c3-0x005539d9.SharedDialogDefaultDestructorThunksLate.md). The proxy declares no explicit destructor and adds no cleanup; its implicitly declared virtual destructor follows the Pursuit/DialogPane contract. Do not hand-port the wrapper or adjustors.
- [UID:00023M][0x0054c200-0x0054caa9.MessageDialogPacketDispatcherAndWrappers](by-memory/0x0054c200-0x0054caa9.MessageDialogPacketDispatcherAndWrappers.md) records the allocation wrapper that creates a `0x278`-byte object and calls the proxy constructor from the message-dialog dispatcher path.
- [UID:000268][0x006224c0-0x00622d24.MessageDialogReadOnlyData](by-memory/0x006224c0-0x00622d24.MessageDialogReadOnlyData.md) records the proxy vtables at `0x00622c58-0x00622ce8`, callback vtable at `0x00622cf4`, and xrefs back to the constructor range.

## Reconstruction Notes

- Rebuild handling is source-authored for the class declaration, constructor, and callback; vtables, callback vtable, implicit destructor dispatch, and adjustor/deleting wrappers are source-declared/generated-binary.
- Method-body C++ now belongs in the exact by-memory pages for [UID:0001FK][0x00553610-0x005538fd.NexonclubProxyDialogConstructor](by-memory/0x00553610-0x005538fd.NexonclubProxyDialogConstructor.md) and [UID:0003GL][0x005534a0-0x00553609.NexonclubProxyDialogReplyCallback](by-memory/0x005534a0-0x00553609.NexonclubProxyDialogReplyCallback.md). The file page stays a source-root/index and should not duplicate those method bodies.
- The current separate `NexonclubProxyDialog.cpp` staging path is strong enough for validator projection and child attachment, but the registration-flow merge question should remain open until the surrounding registration helpers are final-audited.

## Cross-References

- [UID:00009H][NexonclubProxyDialog](by-class/NexonclubProxyDialog.md)
- [UID:0001FK][0x00553610-0x005538fd.NexonclubProxyDialogConstructor](by-memory/0x00553610-0x005538fd.NexonclubProxyDialogConstructor.md)
- [UID:0003GL][0x005534a0-0x00553609.NexonclubProxyDialogReplyCallback](by-memory/0x005534a0-0x00553609.NexonclubProxyDialogReplyCallback.md)
- [UID:0003DE][0x00622c54-0x00622cf0.NexonclubProxyDialogVtableData](by-memory/0x00622c54-0x00622cf0.NexonclubProxyDialogVtableData.md)
- [UID:0003GK][PlainMemberFunctionObjectT_NexonclubProxyDialogStringCallback](by-class/PlainMemberFunctionObjectT_NexonclubProxyDialogStringCallback.md)
- [UID:0001C0][0x00520b70-0x00520bab.SharedDialogDefaultScalarDestructor](by-memory/0x00520b70-0x00520bab.SharedDialogDefaultScalarDestructor.md)
- [UID:00023N][0x005539c3-0x005539d9.SharedDialogDefaultDestructorThunksLate](by-memory/0x005539c3-0x005539d9.SharedDialogDefaultDestructorThunksLate.md)
- [UID:0000M0][NexonclubRegistrationDialog](by-file/NexonclubRegistrationDialog.md)
- [UID:0000OL][TextDialog](by-file/TextDialog.md)
- [UID:00023M][0x0054c200-0x0054caa9.MessageDialogPacketDispatcherAndWrappers](by-memory/0x0054c200-0x0054caa9.MessageDialogPacketDispatcherAndWrappers.md)
- [UID:000268][0x006224c0-0x00622d24.MessageDialogReadOnlyData](by-memory/0x006224c0-0x00622d24.MessageDialogReadOnlyData.md)

## Changes

- 2026-07-16 Agent-B004 UID0001FE support callback:
  - Raised `87/90 -> 89/93`.
  - Added complete declaration-before-definition ordering, required dependency surface, RTTI-proven direct Pursuit inheritance, inherited packet/navigation state, and implicit virtual destructor disposition.
  - Preserved the separate-file/registration-merge caveat and all B008 callback/field/source behavior.
- 2026-07-01 Agent-B010 implementation callback: added support note for [UID:00023M][0x0054c200-0x0054caa9.MessageDialogPacketDispatcherAndWrappers](by-memory/0x0054c200-0x0054caa9.MessageDialogPacketDispatcherAndWrappers.md) wrapper `0x0054c9f0 -> new NexonclubProxyDialog(payload)` without moving proxy callback or registration ownership.
- Before: the `NexonclubProxyDialog` constructor range ended at `0x005538fc`.
- Changed to: the constructor range ends at `0x005538fd`.
- Summary/evidence: 2026-05-28 IDA MCP byte/function review shows `0x005538fc` is the final byte of the range-check failure call operand; the next byte is alignment before `HeadSelectDialog` destructor thunks.

- Before: completion/confidence were ungraded at `0/0`.
- Changed to: completion `78`, confidence `74`.
- Summary/evidence: the page documents the adapter role, constructor/thunk map, ownership notes, IDA recheck, range correction, and cross-references; confidence remains limited by possible fold-in with `NexonclubRegistrationDialog`.
- Before: `PROPOSED_RECONSTRUCTION_PATH` was blank and completion/confidence were `78/74`.
- Changed to: projected path `NexusTK/ui/dialogs/`, completion `82`, and confidence `82`.
- Summary/evidence: [UID:0001R1][proposed-source-tree](by-project-structure/proposed-source-tree.md) already places `NexonclubProxyDialog.cpp` in the adjacent dialog module cluster; [UID:00023M][0x0054c200-0x0054caa9.MessageDialogPacketDispatcherAndWrappers](by-memory/0x0054c200-0x0054caa9.MessageDialogPacketDispatcherAndWrappers.md) documents the allocation wrapper, and [UID:000268][0x006224c0-0x00622d24.MessageDialogReadOnlyData](by-memory/0x006224c0-0x00622d24.MessageDialogReadOnlyData.md) documents the anonymous proxy vtables and callback vtable. The score remains below final-audit levels because the registration-flow merge question and callback type naming are not fully closed.
- 2026-06-12 Agent-A003 Batch 285 callback-owner refresh:
  - Before: `COMPLETION:82`, `CONFIDENCE:82`, with the callback table noted but not resolved to a direct concrete owner.
  - Changed to: `COMPLETION:85`, `CONFIDENCE:87`.
  - Summary/evidence: live IDA MCP recovered the concrete `PlainMemberFunctionObjectT<NexonclubProxyDialog,const StringBase&>` vtable symbol and constructor stores, proving this source root owns the feature construction site while [UID:0000JO][FunctionObjects](by-file/FunctionObjects.md) owns the reusable template declaration. The separate-file caveat versus a future registration-flow merge remains open, so confidence stays below final-audit quality.
- 2026-06-12 Agent-A001 Batch 284 follow-up: Added exact proxy member callback child [UID:0003GL][0x005534a0-0x00553609.NexonclubProxyDialogReplyCallback](by-memory/0x005534a0-0x00553609.NexonclubProxyDialogReplyCallback.md) and exact vtable child [UID:0003DE][0x00622c54-0x00622cf0.NexonclubProxyDialogVtableData](by-memory/0x00622c54-0x00622cf0.NexonclubProxyDialogVtableData.md). Scores remain `85/87`; the file parent already clears the strict gate.
- 2026-06-26 Agent-B008 Rule 26 implementation:
  - Before: `COMPLETION:85`, `CONFIDENCE:87`, with separate-file placement still described as useful but callback/field/source role detail not fully carried into the file page.
  - Changed to: `COMPLETION:87`, `CONFIDENCE:90`, adding source-placement rationale, method-map source names, proxy-vs-registration-vs-message-dispatch ownership separation, and the accepted field/callback relationship.
  - Evidence: B008 live MCP session `80de0a67` confirms the constructor caller at `0x0054ca33`, the proxy constructor/callback relationship, and field reuse across the constructor and `OnReplyText`; no evidence supports moving this source root to TextDialog, direct registration ownership, or generic message dispatcher ownership.
