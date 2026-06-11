*** UID:0000LX | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:85 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:87 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/login/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***

# NewUserMiscDialogPane

## Status

- Confidence: medium-high; behavior, singleton storage, and current source owner are clear enough for direct child attachment, but final standalone-vs-umbrella source grouping still needs review.
- Proposed module: `login/NewUserMiscDialogPane.cpp`, or folded into [UID:0000IK][CreateUserDialogs](by-file/CreateUserDialogs.md) if it proves to be a create-character companion.
- Umbrella doc: [UID:0000IK][CreateUserDialogs](by-file/CreateUserDialogs.md)
- Main class: [UID:00009F][NewUserMiscDialogPane](by-class/NewUserMiscDialogPane.md)
- Exact executable child: [UID:0002Q7][0x004fb630-0x004fccee.NewUserMiscDialogPaneCoreAndPacketHelpers](by-memory/0x004fb630-0x004fccee.NewUserMiscDialogPaneCoreAndPacketHelpers.md)
- Exact singleton child: [UID:0002XL][0x0069b488-0x0069b48c.g_pNewUserMiscDialogPane](by-memory/0x0069b488-0x0069b48c.g_pNewUserMiscDialogPane.md)
- Proposed reconstruction path: `NexusTK/login/`
- 2026-06-04 live IDA refresh confirms constructor, virtual handlers, raw destructor-shaped island, raw packet helpers, reply wrapper, vtable stores, singleton refs, and local padding.

## File Role

`NewUserMiscDialogPane.cpp` is a tentative owner for the new-user customization/misc dialog. The class manages gender, body/shape, and style controls and uses packet-buffer/send helpers through the broad `CashShopRequest` send queue.

Keep this as a separate candidate until the packet behavior and destructor boundary are reviewed. IDA now confirms a constructor and an indirect message-wrapper path, but the exact external trigger remains indirect.

## Proposed Contents

| Entity | Address evidence | Role |
| --- | --- | --- |
| `NewUserMiscDialogPane` constructor | `0x004fb630`, size `0x99f` | Builds `DLGNEW02.EPD`, gender/body/style controls, random initial shape/style selections, and opens the dialog under the main UI graph. |
| `NewUserMiscDialogPane` raw destructor-shaped island | `0x004fbfd0-0x004fc00f` | Not an IDA function; raw bytes write the vtable family, clear the singleton, and tail into base cleanup. |
| `HandleCommand` | `0x004fc010`, size `0x56e` | Handles accept/cancel, gender, shape, and style-control commands. |
| reply wrapper | `0x004fc5c0-0x004fc5e6` | IDA-modeled wrapper that calls the reply handler at `0x004fcb10`. |
| `OnKeyDown` | `0x004fc5f0`, size `0x18c` | Keyboard handling. |
| `OnShowHelp` | `0x004fc780`, size `0x267` | Help/description display. |
| raw packet senders | `0x004fca20-0x004fcb04` | Raw opcode `4` and opcode `0x15` send helpers with local padding. |
| reply handler | `0x004fcb10-0x004fccee` | Parses reply result/message, shows alert text, and closes/dismisses on success. |
| destructor family | `0x00502524`, `0x0050252f`, `0x005029f0` | Adjustor and scalar deleting destructor logic. |

## Current Ownership Decision

| Candidate owner | Evidence | Decision |
| --- | --- | --- |
| Standalone `login/NewUserMiscDialogPane.cpp` | The class has its own exact singleton child [UID:0002XL][0x0069b488-0x0069b48c.g_pNewUserMiscDialogPane](by-memory/0x0069b488-0x0069b48c.g_pNewUserMiscDialogPane.md), a large constructor at `0x004fb630`, virtual command/key/help handlers, and a distinct projected recovered source file. | Current file page remains the canonical source candidate and clears the direct parent gate for the singleton child. |
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
- 2026-06-04 IDA MCP refresh confirms the exact child function run at `0x004fb630`, `0x004fc010`, `0x004fc5c0`, `0x004fc5f0`, `0x004fc780`, and `0x004fcb10`; raw non-function bodies at `0x004fbfd0`, `0x004fca20`, and `0x004fcac0`; padding at `0x004fbfcf`, `0x004fcab8`, and `0x004fccee`; and singleton `0x0069b488` refs from constructor, raw destructor island, cleanup wrapper, and scalar deleting destructor.
- [UID:0002Q7][0x004fb630-0x004fccee.NewUserMiscDialogPaneCoreAndPacketHelpers](by-memory/0x004fb630-0x004fccee.NewUserMiscDialogPaneCoreAndPacketHelpers.md) now splits the constructor, raw destructor-shaped island, command/key/help handlers, raw packet senders, switch table, reply handler, and local padding from the broader aggregate.
- [UID:0002XL][0x0069b488-0x0069b48c.g_pNewUserMiscDialogPane](by-memory/0x0069b488-0x0069b48c.g_pNewUserMiscDialogPane.md) now documents `0x0069b488` as the exact active `NewUserMiscDialogPane` singleton slot, with constructor publish/fallback refs, raw cleanup clear, support-helper clear, and scalar deleting destructor clear. [UID:00029H][0x0069b480-0x0069b490.MainMenuAccountDialogSingletons](by-memory/0x0069b480-0x0069b490.MainMenuAccountDialogSingletons.md) remains the mixed neighbor bridge.
- Do not merge this into [UID:0000I0][CashShopRequest](by-file/CashShopRequest.md). The packet queue is a dependency, not source ownership evidence.
- Do not merge this into [UID:0000LV][NewUserDialogPane](by-file/NewUserDialogPane.md). The account-registration dialog has a different address cluster and responsibility.

## Reconstruction Notes

- Keep `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/login/"` because this is pre-login/create-user UI code under the [UID:0000IK][CreateUserDialogs](by-file/CreateUserDialogs.md) umbrella.
- Do not emit file-level C++ yet. The constructor and handlers are strong, but the `0x004fbfd0` raw destructor-shaped island, packet helper naming, and final split versus the umbrella create-user file are still below the final-source threshold.
- Use live IDA and the exact memory child as the migration anchor; local packet-helper and destructor-shaped raw bodies still need final source names before C++ is emitted.

## Score Rationale

| Field | Value | Rationale |
| --- | ---: | --- |
| Completion | 85 | The page records the projected folder, ownership decision, live IDA method/range map, exact executable child page, exact singleton child page, raw helper islands, dependency exclusions, and reconstruction gates. |
| Confidence | 87 | Class ownership and login/create-user placement are supported by live constructor/caller/vtable evidence, exact singleton storage, exact child memory coverage, and local padding/raw-island checks. Confidence is capped by the raw destructor boundary and unresolved final standalone-vs-umbrella source split. |

## Cross-References

- [UID:0000IK][CreateUserDialogs](by-file/CreateUserDialogs.md)
- [UID:00009F][NewUserMiscDialogPane](by-class/NewUserMiscDialogPane.md)
- [UID:00019U][0x004fb630-0x004fe782.NewUserMiscShapeAndPasswordDialogs](by-memory/0x004fb630-0x004fe782.NewUserMiscShapeAndPasswordDialogs.md)
- [UID:0002XL][0x0069b488-0x0069b48c.g_pNewUserMiscDialogPane](by-memory/0x0069b488-0x0069b48c.g_pNewUserMiscDialogPane.md)
- [UID:0000LY][NewUserShapeSelectControlPane](by-file/NewUserShapeSelectControlPane.md)
- [UID:0000I0][CashShopRequest](by-file/CashShopRequest.md)

## Changes

- 2026-06-04: Raised from `74/80` to `82/86` and attached the exact child page after a live IDA refresh.
  - Before: the file page had a reasonable login/create-user owner candidate but still carried stale source-provenance notes, treated the destructor island as an external projected row, and did not attach the exact executable child.
  - After: the page records the current IDA function run, raw destructor/packet islands, reply wrapper, vtable refs, singleton refs, padding, score rationale, and final C++ blockers while keeping the standalone-vs-umbrella source split explicit.
  - Evidence: 2026-06-04 IDA MCP `py_eval` over `0x004fb630-0x004fccee` confirmed modeled functions `0x004fb630`, `0x004fc010`, `0x004fc5c0`, `0x004fc5f0`, `0x004fc780`, and `0x004fcb10`, raw non-function bodies at `0x004fbfd0`, `0x004fca20`, and `0x004fcac0`, constructor caller `0x004fa74e`, wrapper chain `0x004fa111 -> 0x004fa5b0`, vtable refs to `0x0061d424`/`0x0061d484`/`0x0061d4b4`, and singleton `0x0069b488` refs from constructor/destructor-family paths.

- Before: completion/confidence were ungraded at `0/0`.
- Changed to: completion `68`, confidence `62`.
- Summary/evidence: the page documents a tentative role, constructor/handler/destructor ranges, boundary notes, and IDA checks, but it explicitly remains a candidate owner with unresolved trigger, destructor-boundary, and final ownership questions.
- 2026-06-02 ownership/path pass:
  - What existed before: the page had a blank projected path and remained low confidence despite newer exact child and singleton documentation.
  - Changed to: `COMPLETION:74`, `CONFIDENCE:80`, `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/login/"`, with ownership decision, reconstruction notes, and score rationale.
  - Summary/evidence: [UID:0002Q7][0x004fb630-0x004fccee.NewUserMiscDialogPaneCoreAndPacketHelpers](by-memory/0x004fb630-0x004fccee.NewUserMiscDialogPaneCoreAndPacketHelpers.md), [UID:00029H][0x0069b480-0x0069b490.MainMenuAccountDialogSingletons](by-memory/0x0069b480-0x0069b490.MainMenuAccountDialogSingletons.md), and [UID:0000IK][CreateUserDialogs](by-file/CreateUserDialogs.md) justify the login/create-user source candidate while preserving final-source caveats.
- 2026-06-07 A002 Batch 042 singleton parent-gate refresh:
  - What existed before: `COMPLETION:82`, `CONFIDENCE:86`, and the singleton evidence was only anchored through the mixed account-dialog aggregate.
  - Changed to: `COMPLETION:85`, `CONFIDENCE:87`, with exact singleton child [UID:0002XL][0x0069b488-0x0069b48c.g_pNewUserMiscDialogPane](by-memory/0x0069b488-0x0069b48c.g_pNewUserMiscDialogPane.md).
  - Summary/evidence: the split child records exact one-dword storage, initialized value, constructor publish/fallback refs, raw cleanup clear, support-helper clear, and scalar deleting destructor clear. This page now clears the strict direct-parent gate for [UID:0002XL][0x0069b488-0x0069b48c.g_pNewUserMiscDialogPane](by-memory/0x0069b488-0x0069b48c.g_pNewUserMiscDialogPane.md) while remaining capped by raw destructor-boundary and standalone-vs-umbrella source-split caveats.
