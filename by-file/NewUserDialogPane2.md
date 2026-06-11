*** UID:0000LW | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:86 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/login/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# NewUserDialogPane2

## Status

- Confidence: strong for behavior, path placement, and variant ownership; medium-high for final standalone source split.
- Proposed module: `login/NewUserDialogPane2.cpp`, or folded into [UID:0000IK][CreateUserDialogs](by-file/CreateUserDialogs.md).
- Umbrella doc: [UID:0000IK][CreateUserDialogs](by-file/CreateUserDialogs.md)
- Current recovered source: `source-3/simroot_v2/class_NewUserDialogPane2.cpp`
- Main class: [UID:00009E][NewUserDialogPane2](by-class/NewUserDialogPane2.md)
- Exact executable island: [UID:0002QR][0x0052a540-0x0052c325.NewUserDialogPane2CreateUserVariant](by-memory/0x0052a540-0x0052c325.NewUserDialogPane2CreateUserVariant.md)
- Exact vtable data: [UID:0002SH][0x0061fd04-0x0061fd94.NewUserDialogPane2VtableData](by-memory/0x0061fd04-0x0061fd94.NewUserDialogPane2VtableData.md)
- Singleton slot: [UID:00029W][0x0069b4a4-0x0069b4b4.MainMenuDialogSingletonSlots](by-memory/0x0069b4a4-0x0069b4b4.MainMenuDialogSingletonSlots.md)

## File Role

`NewUserDialogPane2.cpp` is the alternate 640x480 create-character dialog candidate. It uses `DLGNEW02.EPD` and `NPAL3.PAL`, displays several shape previews, handles gender/totem/body-shape/direction selection, and submits the create-user request.

This is not the same source role as [UID:0000LV][NewUserDialogPane](by-file/NewUserDialogPane.md). `NewUserDialogPane` is the older account-registration dialog; `NewUserDialogPane2` belongs to the character creation UI family with [UID:0000IJ][CreateUserDialogPane](by-file/CreateUserDialogPane.md) and [UID:0000LP][NewCreateUserDialogPane](by-file/NewCreateUserDialogPane.md).

## Proposed Contents

| Entity | Address evidence | Role |
| --- | --- | --- |
| `NewUserDialogPane2` constructor | `0x0052a540` | Builds the alternate 640x480 create-character dialog. |
| shape/gender/totem selectors | `0x0052b090-0x0052b5c0` | Rotates and applies preview/selection state. |
| command/event handlers | `0x0052b760-0x0052b940` | Dispatches dialog commands and notifications. |
| `SubmitCreateUser` | `0x0052b9f0` | Validates and sends the create-user request. |
| packet/reply helpers | `0x0052bbc0-0x0052c325` | Encodes login/create-character payloads, sends through [UID:0000Q5][g_packetSender](by-global/g_packetSender.md) / historical `dword_67A7EC`, and handles server replies. |
| vtable data | `0x0061fd04-0x0061fd94` | Source-declared/generated-binary vtable block for the class declaration and destructor/handler layout. |
| singleton slot | `0x0069b4a4` | Pre-login dialog singleton published/cleared by constructor/destructor/helper paths. |
| destructor family | `0x0052f767`, `0x0052f772`, `0x0052f8e0` | Adjustor and scalar deleting destructor logic in the shared create-user destructor/thunk island. |

## Boundary Notes

- Wave3 currently names the `0x0052a540` row like a destructor, but the generated body and IDA-confirmed behavior are constructor-like.
- Keep the shape-preview control implementation in [UID:0000LY][NewUserShapeSelectControlPane](by-file/NewUserShapeSelectControlPane.md) unless final source-size review folds it into this file.
- Keep account registration/password-only behavior in [UID:0000LV][NewUserDialogPane](by-file/NewUserDialogPane.md) and [UID:0000KX][LoginDialogPane](by-file/LoginDialogPane.md).
- Keep [UID:0000TB][OpenCreateUserDialog_4F8FA0](by-global/OpenCreateUserDialog_4F8FA0.md) under [UID:0000L0][MainMenuPane](by-file/MainMenuPane.md). It constructs `NewUserDialogPane2` in one branch, but it is a retained main-menu launcher rather than a method owned by this dialog implementation.
- Treat [UID:0002SH][0x0061fd04-0x0061fd94.NewUserDialogPane2VtableData](by-memory/0x0061fd04-0x0061fd94.NewUserDialogPane2VtableData.md) as compiler output generated from the class declaration and virtual layout; do not hand-port the bytes into this source file.
- The executable child ends at `0x0052c325`; the next create-user variant starts at `0x0052c360`, so this file's modeled core should not absorb the intervening padding or the [UID:0000LP][NewCreateUserDialogPane](by-file/NewCreateUserDialogPane.md) method island.

## Evidence Notes

- [UID:0002QR][0x0052a540-0x0052c325.NewUserDialogPane2CreateUserVariant](by-memory/0x0052a540-0x0052c325.NewUserDialogPane2CreateUserVariant.md) records the constructor-like body at `0x0052a540-0x0052b047`, selector helpers through `0x0052b648`, command/event/notify handlers, submit validation at `0x0052b9f0`, and packet/reply helpers through `0x0052c325`.
- Constructor reachability is documented from `0x004f7ad0` and from [UID:00019P][0x004f8fa0-0x004f9055.OpenCreateUserDialog](by-memory/0x004f8fa0-0x004f9055.OpenCreateUserDialog.md) at `0x004f9041`; the launcher itself remains a [UID:0000L0][MainMenuPane](by-file/MainMenuPane.md) concern.
- [UID:0002SH][0x0061fd04-0x0061fd94.NewUserDialogPane2VtableData](by-memory/0x0061fd04-0x0061fd94.NewUserDialogPane2VtableData.md) records constructor/destructor vtable references at `0x0052a5b2`, `0x0052b059`, and `0x0052f8ec`, with the adjacent `NewCreateUserDialogPane` vtable block beginning at `0x0061fda0`.
- [UID:00029W][0x0069b4a4-0x0069b4b4.MainMenuDialogSingletonSlots](by-memory/0x0069b4a4-0x0069b4b4.MainMenuDialogSingletonSlots.md) records `0x0069b4a4` as `g_pNewUserDialogPane2`, including constructor publish/fallback clear, constructor-adjacent cleanup clear, explicit clear helper, scalar deleting destructor clear, and main-menu cleanup read.
- Submit-path documentation records the three edit-field reads, digit-in-password requirement, password confirmation comparison, alert fallback, length-prefixed packet encoding, send through [UID:0000Q5][g_packetSender](by-global/g_packetSender.md) / historical `dword_67A7EC`, and server-reply alert/reset behavior.
- Current-session limitation: IDA MCP was unavailable on 2026-06-07 (`Unable to connect to the remote server`), so this pass integrates existing written project-documentation evidence rather than adding fresh live checks.
- Later 2026-06-07 Batch 043 live IDA MCP was available and reconfirmed `0x0069b4a4-0x0069b4a8` as a clean `0xffffffff` singleton item with six xrefs: main-menu cleanup read, constructor publish/fallback clear, constructor-adjacent cleanup clear, singleton helper clear, and scalar deleting destructor clear. The exact storage now has a split page [UID:0002X4][0x0069b4a4-0x0069b4a8.g_pNewUserDialogPane2](by-memory/0x0069b4a4-0x0069b4a8.g_pNewUserDialogPane2.md) and a canonical global page [UID:0002X3][g_pNewUserDialogPane2](by-global/g_pNewUserDialogPane2.md).

## Score Rationale

The page is now treated as a high-confidence `NexusTK/login/` source candidate because [UID:0000IK][CreateUserDialogs](by-file/CreateUserDialogs.md) already lists `login/NewUserDialogPane2.cpp`, [UID:0001CR][0x0052a540-0x0052f94c.CreateUserDialogVariants](by-memory/0x0052a540-0x0052f94c.CreateUserDialogVariants.md) owns the create-user dialog family under the same login path, and [UID:0002QR][0x0052a540-0x0052c325.NewUserDialogPane2CreateUserVariant](by-memory/0x0052a540-0x0052c325.NewUserDialogPane2CreateUserVariant.md) records exact constructor, selector, submit, packet, caller, and boundary evidence for this variant. [UID:0002SH][0x0061fd04-0x0061fd94.NewUserDialogPane2VtableData](by-memory/0x0061fd04-0x0061fd94.NewUserDialogPane2VtableData.md) and [UID:00029W][0x0069b4a4-0x0069b4b4.MainMenuDialogSingletonSlots](by-memory/0x0069b4a4-0x0069b4b4.MainMenuDialogSingletonSlots.md) add the exact vtable/singleton evidence now summarized here.

| Field | Value | Rationale |
| --- | ---: | --- |
| Completion | 82 | The file page now records the executable island, method families, packet/reply helpers, vtable data range, singleton slot, launcher ownership boundary, neighboring variant boundary, and account-registration exclusion. It remains below final-audit range because exact field names, helper names, and the final split versus neighboring create-user variants are not source-quality yet. |
| Confidence | 84 | Written IDA-backed class/memory/global pages support the source ownership and behavior. Confidence stays conservative because this session had no live MCP access, Wave3 still misnames the constructor row, and the broader old/new create-user source split is unresolved. |

## Cross-References

- [UID:0000IK][CreateUserDialogs](by-file/CreateUserDialogs.md)
- [UID:00009E][NewUserDialogPane2](by-class/NewUserDialogPane2.md)
- [UID:0001CR][0x0052a540-0x0052f94c.CreateUserDialogVariants](by-memory/0x0052a540-0x0052f94c.CreateUserDialogVariants.md)
- [UID:0002QR][0x0052a540-0x0052c325.NewUserDialogPane2CreateUserVariant](by-memory/0x0052a540-0x0052c325.NewUserDialogPane2CreateUserVariant.md)
- [UID:0002SH][0x0061fd04-0x0061fd94.NewUserDialogPane2VtableData](by-memory/0x0061fd04-0x0061fd94.NewUserDialogPane2VtableData.md)
- [UID:00029W][0x0069b4a4-0x0069b4b4.MainMenuDialogSingletonSlots](by-memory/0x0069b4a4-0x0069b4b4.MainMenuDialogSingletonSlots.md)
- [UID:0000Q5][g_packetSender](by-global/g_packetSender.md)
- [UID:0000TB][OpenCreateUserDialog_4F8FA0](by-global/OpenCreateUserDialog_4F8FA0.md)
- [UID:0000LY][NewUserShapeSelectControlPane](by-file/NewUserShapeSelectControlPane.md)
- [UID:0000LV][NewUserDialogPane](by-file/NewUserDialogPane.md)

## Changes

- 2026-06-07: Replaced raw create-character packet-send references with canonical [UID:0000Q5][g_packetSender](by-global/g_packetSender.md) wording.
  - Before: the file role and submit-path evidence described the send path through historical `dword_67A7EC` only.
  - After: the page links the resolved packet sender while retaining the historical global for IDA traceability.
  - Evidence: the generated resolved-name report maps `dword_67A7EC` to `g_packetSender`, and the linked `NewUserDialogPane2CreateUserVariant` memory page records the payload send through that global.

- 2026-06-07 A010 evidence consolidation:
  - What existed before: scores were `80/82`; the page had correct login placement and broad method-family notes, but did not summarize the exact vtable data, singleton slot, launcher ownership boundary, or packet/reply evidence already present in linked pages.
  - Changed to: completion `82`, confidence `84`.
  - Summary/evidence: integrated [UID:0002QR][0x0052a540-0x0052c325.NewUserDialogPane2CreateUserVariant](by-memory/0x0052a540-0x0052c325.NewUserDialogPane2CreateUserVariant.md), [UID:0002SH][0x0061fd04-0x0061fd94.NewUserDialogPane2VtableData](by-memory/0x0061fd04-0x0061fd94.NewUserDialogPane2VtableData.md), [UID:00029W][0x0069b4a4-0x0069b4b4.MainMenuDialogSingletonSlots](by-memory/0x0069b4a4-0x0069b4b4.MainMenuDialogSingletonSlots.md), and [UID:0000TB][OpenCreateUserDialog_4F8FA0](by-global/OpenCreateUserDialog_4F8FA0.md) into the file-source summary. IDA MCP was unavailable in this session, so no fresh live evidence was added and C++ remains blank.
- 2026-06-07 Batch 043 parent-gate refresh:
  - Before: `82/84`.
  - After: `85/86`.
  - Evidence: live IDA MCP reconfirmed the exact singleton slot, item bounds, initial value, and all six xrefs. The page already links exact executable and vtable children, so the direct global parent for the split storage page can route through this file without violating the corrected `85/85` gate. C++ remains blank because field names and the final standalone-vs-umbrella split are still below the final reconstruction bar.
- Before: completion/confidence were ungraded at `0/0`.
- Changed to: completion `74`, confidence `72`.
- Summary/evidence: the page documents the alternate create-character role, major method families, boundary distinctions, and cross-references; confidence is limited by final standalone-source split and the generated constructor/destructor naming issue.
- 2026-06-02 path and confidence update:
  - What existed before: `PROPOSED_RECONSTRUCTION_PATH` was blank and the page was scored `74/72`.
  - Changed to: `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/login/"`, completion `80`, and confidence `82`.
  - Summary/evidence: the create-user umbrella, proposed source tree, aggregate memory page, and exact child memory page all place this alternate create-character dialog in the login/create-user source family.
