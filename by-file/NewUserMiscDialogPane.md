*** UID:0000LX | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:74 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:80 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/login/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# NewUserMiscDialogPane

## Status

- Confidence: medium; behavior is clear enough for a candidate page, but final owner needs review.
- Proposed module: `login/NewUserMiscDialogPane.cpp`, or folded into [UID:0000IK][CreateUserDialogs](by-file/CreateUserDialogs.md) if it proves to be a create-character companion.
- Umbrella doc: [UID:0000IK][CreateUserDialogs](by-file/CreateUserDialogs.md)
- Current recovered source: `source-3/simroot_v2/class_NewUserMiscDialogPane.cpp` (constructor currently missing from emitted source)
- Main class: [UID:00009F][NewUserMiscDialogPane](by-class/NewUserMiscDialogPane.md)
- Proposed reconstruction path: `NexusTK/login/`

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

## Current Ownership Decision

| Candidate owner | Evidence | Decision |
| --- | --- | --- |
| Standalone `login/NewUserMiscDialogPane.cpp` | The class has its own singleton at [UID:00029H][0x0069b480-0x0069b490.MainMenuAccountDialogSingletons](by-memory/0x0069b480-0x0069b490.MainMenuAccountDialogSingletons.md), a large constructor at `0x004fb630`, virtual command/key/help handlers, and a distinct projected recovered source file. | Current file page remains the canonical source candidate. |
| Folded into [UID:0000IK][CreateUserDialogs](by-file/CreateUserDialogs.md) | The constructor is reached from the new-user reply path and builds create-user customization controls. | Keep as umbrella relationship only until final source split is proven. |
| [UID:0000I0][CashShopRequest](by-file/CashShopRequest.md) | Command handling sends packets through the shared send queue. | Dependency only; not source ownership. |
| [UID:0000LV][NewUserDialogPane](by-file/NewUserDialogPane.md) | The indirect trigger comes from the account/new-user dialog path. | Related caller, not the same dialog class or source unit. |

## Boundary Notes

- Treat `0x004fbfd0` as a boundary caveat until IDA or manual disassembly confirms whether it is a true function start.
- 2026-05-24 IDA MCP recheck: `lookup_funcs 0x004fb630` returns a real constructor-sized function of `0x99f` bytes.
- 2026-05-24 IDA MCP recheck: constructor xrefs write vtables at `0x0061d424`, `0x0061d484`, and `0x0061d4b4`; `callers 0x004fb630` reports `0x004fa74e` inside `0x004fa5b0`.
- `0x004fa5b0` is referenced from `0x004fa111` inside the small wrapper at `0x004fa0f0`; the wrapper itself is vtable/data-referenced at `0x0061d35c`, so the top-level trigger is still indirect rather than a plain code caller.
- 2026-05-24 IDA MCP recheck: `lookup_funcs 0x004fbfd0` returns no function and `xrefs_to 0x004fbfd0` returns none.
- 2026-05-24 IDA MCP recheck: `callers 0x004fc010` returns none, while `xrefs_to 0x004fc010` reports only data xref `0x0061d46c`; command handling is reached virtually through the class vtable rather than by a direct call xref.
- Destructor-family target `0x005029f0` is a real `0x71`-byte function with thunk xrefs at `0x0050252a` and `0x00502535` plus vtable data xref `0x0061d424`.
- [UID:0002Q7][0x004fb630-0x004fccee.NewUserMiscDialogPaneCoreAndPacketHelpers](by-memory/0x004fb630-0x004fccee.NewUserMiscDialogPaneCoreAndPacketHelpers.md) now splits the constructor, raw destructor-shaped island, command/key/help handlers, raw packet senders, switch table, reply handler, and local padding from the broader aggregate.
- [UID:00029H][0x0069b480-0x0069b490.MainMenuAccountDialogSingletons](by-memory/0x0069b480-0x0069b490.MainMenuAccountDialogSingletons.md) confirms `0x0069b488` as the active `NewUserMiscDialogPane` singleton slot, written/read/cleared by the constructor and destructor family.
- Do not merge this into [UID:0000I0][CashShopRequest](by-file/CashShopRequest.md). The packet queue is a dependency, not source ownership evidence.
- Do not merge this into [UID:0000LV][NewUserDialogPane](by-file/NewUserDialogPane.md). The account-registration dialog has a different address cluster and responsibility.

## Reconstruction Notes

- Keep `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/login/"` because this is pre-login/create-user UI code under the [UID:0000IK][CreateUserDialogs](by-file/CreateUserDialogs.md) umbrella.
- Do not emit file-level C++ yet. The constructor and handlers are strong, but the `0x004fbfd0` raw destructor-shaped island, packet helper naming, and final split versus the umbrella create-user file are still below the final-source threshold.
- Treat the current emitted `class_NewUserMiscDialogPane.cpp` as incomplete because it omits the constructor that IDA confirms at `0x004fb630`.

## Score Rationale

| Field | Value | Rationale |
| --- | ---: | --- |
| Completion | 74 | The page now records the projected folder, canonical ownership decision, method/range map, exact split child page, singleton evidence, dependency exclusions, and reconstruction gates. |
| Confidence | 80 | Class ownership and login/create-user placement are supported by constructor/caller/vtable evidence, singleton storage, and the exact child memory page. Confidence is capped by the raw destructor boundary and unresolved final standalone-vs-umbrella source split. |

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
- 2026-06-02 ownership/path pass:
  - What existed before: the page had a blank projected path and remained low confidence despite newer exact child and singleton documentation.
  - Changed to: `COMPLETION:74`, `CONFIDENCE:80`, `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/login/"`, with ownership decision, reconstruction notes, and score rationale.
  - Summary/evidence: [UID:0002Q7][0x004fb630-0x004fccee.NewUserMiscDialogPaneCoreAndPacketHelpers](by-memory/0x004fb630-0x004fccee.NewUserMiscDialogPaneCoreAndPacketHelpers.md), [UID:00029H][0x0069b480-0x0069b490.MainMenuAccountDialogSingletons](by-memory/0x0069b480-0x0069b490.MainMenuAccountDialogSingletons.md), and [UID:0000IK][CreateUserDialogs](by-file/CreateUserDialogs.md) justify the login/create-user source candidate while preserving final-source caveats.
