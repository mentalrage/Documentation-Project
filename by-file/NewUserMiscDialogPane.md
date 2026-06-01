*** UID:0000LX | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:68 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:62 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# NewUserMiscDialogPane

## Status

- Confidence: medium; behavior is clear enough for a candidate page, but final owner needs review.
- Proposed module: `login/NewUserMiscDialogPane.cpp`, or folded into [UID:0000IK][CreateUserDialogs](by-file/CreateUserDialogs.md) if it proves to be a create-character companion.
- Umbrella doc: [UID:0000IK][CreateUserDialogs](by-file/CreateUserDialogs.md)
- Current recovered source: `source-3/simroot_v2/class_NewUserMiscDialogPane.cpp` (constructor currently missing from emitted source)
- Main class: [UID:00009F][NewUserMiscDialogPane](by-class/NewUserMiscDialogPane.md)

## File Role

`NewUserMiscDialogPane.cpp` is a tentative owner for the new-user customization/misc dialog. The class manages gender, body/shape, and style controls and uses packet-buffer/send helpers through the broad `CashShopRequest` send queue.

Keep this as a separate candidate until the packet behavior and destructor boundary are reviewed. IDA now confirms a constructor and an indirect message-wrapper path, but the exact external trigger remains indirect.

## Proposed Contents

| Entity | Address evidence | Role |
| --- | --- | --- |
| `NewUserMiscDialogPane` constructor | `0x004fb630`, size `0x99f` | Builds `DLGNEW02.EPD`, gender/body/style controls, random initial shape/style selections, and opens the dialog under the main UI graph. |
| `NewUserMiscDialogPane` destructor row | `0x004fbfd0` | Wave3-projected start; IDA does not define a function here. |
| `HandleCommand` | `0x004fc010`, size `0x56e` | Handles accept/cancel, gender, shape, and style-control commands. |
| `OnKeyDown` | `0x004fc5f0`, size `0x18c` | Keyboard handling. |
| `OnShowHelp` | `0x004fc780`, size `0x267` | Help/description display. |
| destructor family | `0x00502524`, `0x0050252f`, `0x005029f0` | Adjustor and scalar deleting destructor logic. |

## Boundary Notes

- Treat `0x004fbfd0` as a boundary caveat until IDA or manual disassembly confirms whether it is a true function start.
- 2026-05-24 IDA MCP recheck: `lookup_funcs 0x004fb630` returns a real constructor-sized function of `0x99f` bytes.
- 2026-05-24 IDA MCP recheck: constructor xrefs write vtables at `0x0061d424`, `0x0061d484`, and `0x0061d4b4`; `callers 0x004fb630` reports `0x004fa74e` inside `0x004fa5b0`.
- `0x004fa5b0` is referenced from `0x004fa111` inside the small wrapper at `0x004fa0f0`; the wrapper itself is vtable/data-referenced at `0x0061d35c`, so the top-level trigger is still indirect rather than a plain code caller.
- 2026-05-24 IDA MCP recheck: `lookup_funcs 0x004fbfd0` returns no function and `xrefs_to 0x004fbfd0` returns none.
- 2026-05-24 IDA MCP recheck: `callers 0x004fc010` returns none, while `xrefs_to 0x004fc010` reports only data xref `0x0061d46c`; command handling is reached virtually through the class vtable rather than by a direct call xref.
- Destructor-family target `0x005029f0` is a real `0x71`-byte function with thunk xrefs at `0x0050252a` and `0x00502535` plus vtable data xref `0x0061d424`.
- Do not merge this into [UID:0000I0][CashShopRequest](by-file/CashShopRequest.md). The packet queue is a dependency, not source ownership evidence.
- Do not merge this into [UID:0000LV][NewUserDialogPane](by-file/NewUserDialogPane.md). The account-registration dialog has a different address cluster and responsibility.

## Cross-References

- [UID:0000IK][CreateUserDialogs](by-file/CreateUserDialogs.md)
- [UID:00009F][NewUserMiscDialogPane](by-class/NewUserMiscDialogPane.md)
- [UID:00019U][0x004fb630-0x004fe782.NewUserMiscShapeAndPasswordDialogs](by-memory/0x004fb630-0x004fe782.NewUserMiscShapeAndPasswordDialogs.md)
- [UID:0000LY][NewUserShapeSelectControlPane](by-file/NewUserShapeSelectControlPane.md)
- [UID:0000I0][CashShopRequest](by-file/CashShopRequest.md)
- [Wave3 data issues](../wave3_data_issues.md)

## Changes

- Before: completion/confidence were ungraded at `0/0`.
- Changed to: completion `68`, confidence `62`.
- Summary/evidence: the page documents a tentative role, constructor/handler/destructor ranges, boundary notes, and IDA checks, but it explicitly remains a candidate owner with unresolved trigger, destructor-boundary, and final ownership questions.
