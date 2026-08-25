*** UID:0000LV | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/login/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:FILE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# NewUserDialogPane

## Status

- Confidence: very strong for account-registration behavior, exact child boundaries, class/file emitter routing, packet flow, lifecycle ownership, and standalone login source placement; original manifest/spellings and the retained no-route constructor remain bounded caps.
- Source module: standalone `NexusTK/login/NewUserDialogPane.cpp`; the older folded-into-`LoginDialogPane.cpp` alternative is rejected.
- Main class: [UID:00009D][NewUserDialogPane](by-class/NewUserDialogPane.md)

## File Role

`NewUserDialogPane.cpp` should own the older account-registration dialog. It collects username, password, and password confirmation text, validates password content/match state, shows alert/dimmer feedback for failures, and sends the new-account request.

Do not confuse this with [UID:0000LW][NewUserDialogPane2](by-file/NewUserDialogPane2.md). `NewUserDialogPane2` is a create-character dialog variant in the [UID:0000IK][CreateUserDialogs](by-file/CreateUserDialogs.md) family, while this page is for account registration near [UID:0000KX][LoginDialogPane](by-file/LoginDialogPane.md) and [UID:0000I3][ChangePasswordDialogPane](by-file/ChangePasswordDialogPane.md).

## Proposed Contents

| Entity | Address evidence | Role |
| --- | --- | --- |
| `NewUserDialogPane` class | [UID:00009D][NewUserDialogPane](by-class/NewUserDialogPane.md) | Owns the older account-registration dialog object. |
| `g_pNewUserDialogPane` singleton declaration | [UID:0002X9][0x0069b480-0x0069b484.g_pNewUserDialogPane](by-memory/0x0069b480-0x0069b484.g_pNewUserDialogPane.md) | Source-ready old account-registration singleton pointer declaration emitted through this file route as `NewUserDialogPane *g_pNewUserDialogPane;`. |
| constructor | [UID:0004PB][0x004f9d30-0x004fa0a9.NewUserDialogPaneConstructor](by-memory/0x004f9d30-0x004fa0a9.NewUserDialogPaneConstructor.md) | Class child position 1; exact resource, controls, singleton, layer attachment, and retained zero-route caveat. |
| compiler raw cleanup | [UID:0004PC][0x004fa0b0-0x004fa0ef.NewUserDialogPaneRawCleanupIsland](by-memory/0x004fa0b0-0x004fa0ef.NewUserDialogPaneRawCleanupIsland.md) | No-function/no-xref non-deleting cleanup copy; blank C++, not a second destructor. |
| `HandlePacketEvent` override | [UID:0004PD][0x004fa0f0-0x004fa116.NewUserDialogPaneHandlePacketEvent](by-memory/0x004fa0f0-0x004fa116.NewUserDialogPaneHandlePacketEvent.md) | Class position 3; EventHandler secondary slot `+0x10`, reads `event->m_payload.m_packet.m_data` at exact `Event +0x0c`, accepts opcode `2`, compiler adjusts only the secondary receiver, and forwards the packet. |
| control command | [UID:0004PE][0x004fa120-0x004fa14e.NewUserDialogPaneOnControlCommand](by-memory/0x004fa120-0x004fa14e.NewUserDialogPaneOnControlCommand.md) | Class position 4; create/close commands. |
| button-state updater | [UID:0004PF][0x004fa150-0x004fa1c9.NewUserDialogPaneUpdateCreateUserButtonEnabledState](by-memory/0x004fa150-0x004fa1c9.NewUserDialogPaneUpdateCreateUserButtonEnabledState.md) | Class position 5; create button enabled only when controls `3/4/5` are nonempty. |
| submit/validation | [UID:0004PG][0x004fa1d0-0x004fa39c.NewUserDialogPaneSubmitCreateUser](by-memory/0x004fa1d0-0x004fa39c.NewUserDialogPaneSubmitCreateUser.md) | Class position 6; exact digit/match alerts, dimmer, and request call. |
| request encoder | [UID:0004PH][0x004fa3a0-0x004fa5a5.SendCreateAccountRequest](by-memory/0x004fa3a0-0x004fa5a5.SendCreateAccountRequest.md) | Direct file child position 1; file-local `static __stdcall` helper with opcode `2`, three byte-length MBC fields, and sent trailing zero. |
| reply handler | [UID:0004PI][0x004fa5b0-0x004fa773.NewUserDialogPaneHandleCreateUserReply](by-memory/0x004fa5b0-0x004fa773.NewUserDialogPaneHandleCreateUserReply.md) | Class position 7; exact dimmer-gated failure path, direct 256-byte narrow/256-wide copy and `MultiByteToWideChar` conversion with unsigned-byte returned-length termination, and success close/config/misc-dialog handoff. |
| reply switch data | [UID:0004PK][0x004fa773-0x004fa793.NewUserDialogPaneReplySwitchTable](by-memory/0x004fa773-0x004fa793.NewUserDialogPaneReplySwitchTable.md) | Compiler-local table; blank C++; trailing `[0x004fa793,0x004fa7a0)` padding stays ignored. |
| constructor-EH clear | [UID:0004PL][0x005023f0-0x005023fb.NewUserDialogPaneSingletonClearUnwindHelper](by-memory/0x005023f0-0x005023fb.NewUserDialogPaneSingletonClearUnwindHelper.md) | One unwind-map xref; compiler rollback helper; blank C++. |
| destructor adjustors | [UID:0004PM][0x0050250e-0x00502524.NewUserDialogPaneDestructorAdjustorThunks](by-memory/0x0050250e-0x00502524.NewUserDialogPaneDestructorAdjustorThunks.md) | Compiler `-0xa0/-0xa4` receiver thunks; blank C++. |
| destructor | [UID:0004PO][0x00502970-0x005029e1.NewUserDialogPaneDestructor](by-memory/0x00502970-0x005029e1.NewUserDialogPaneDestructor.md) | Class position 2; sole routed ordinary source-destructor semantics. |
| vtable data | [UID:0004PP][0x0061d2ec-0x0061d384.NewUserDialogPaneVtableData](by-memory/0x0061d2ec-0x0061d384.NewUserDialogPaneVtableData.md) | Compiler-generated primary/secondary/tertiary views; blank C++; exact Login boundary. |

## Boundary Notes

- Keep login submission and server response handling in [UID:0000KX][LoginDialogPane](by-file/LoginDialogPane.md).
- Keep password-change behavior in [UID:0000I3][ChangePasswordDialogPane](by-file/ChangePasswordDialogPane.md).
- Keep create-character variants in [UID:0000IK][CreateUserDialogs](by-file/CreateUserDialogs.md), [UID:0000IJ][CreateUserDialogPane](by-file/CreateUserDialogPane.md), [UID:0000LP][NewCreateUserDialogPane](by-file/NewCreateUserDialogPane.md), and [UID:0000LW][NewUserDialogPane2](by-file/NewUserDialogPane2.md).
- The standalone route is resolved: dedicated class, singleton declaration, file-local request helper, contiguous method island, exact vtables, and separate adjacent Login ownership outweigh physical proximity to LoginDialogPane.
- No derived child-control fields are needed; inherited typed child lookup preserves the binary. The hidden cleanup/table/thunk/vtable forms are compiler-only children and do not block human source.
- Preserve exact source ordering: singleton declaration, file-local request helper position 1, complete class declaration, then class constructor/destructor/`HandlePacketEvent`/command/updater/submit/reply children positions 1-7.
- Reject a synthetic aggregate source file, folded Login ownership, PacketBuffer/Socket ownership, duplicate cleanup destructor, handwritten ABI/table/vtable source, and raw `sub_`/offset forms.

## Live IDA Evidence

- Function enumeration on 2026-06-05 confirms the constructor and local helper island at `0x004f9d30`, `0x004fa0f0`, `0x004fa120`, `0x004fa150`, `0x004fa1d0`, `0x004fa3a0`, and `0x004fa5b0`, plus the lifecycle helpers at `0x005023f0`, `0x0050250e`, `0x00502519`, and `0x00502970`.
- `??_7NewUserDialogPane@@6B@`, `??_7NewUserDialogPane@@6B@_0`, and `??_7NewUserDialogPane@@6B@_1` bind the primary command/default handlers, the secondary packet adapter, and the deleting destructor through read-only data slots.
- `dword_69B480` xrefs show constructor setup, hidden-fragment cleanup, explicit clear helper cleanup, and deleting-destructor cleanup for the older account-registration singleton.
- Raw-byte checks keep the memory page split precise: the internal gaps are `0xcc` padding, while `0x004fa773-0x004fa793` is local reply switch/table data before padding to the next constructor.
- Fresh MCP session `6b2e78f3` at bounded callback recovery reconfirmed the EventHandler `HandlePacketEvent(Event *)` payload read at `Event +0x0c`, opcode-2 route, `this-0xa0` compiler adjustment, and reply handler's direct `CHAR[256]`/`WCHAR[256]` stack buffers, exact-length copy, terminators, and direct `MultiByteToWideChar` call. The old target-specific `PacketEvent` virtual and `SimpleUString` conversion are rejected source forms, not aliases.

## UID0002X9 Singleton Declaration Route

[UID:0002X9][0x0069b480-0x0069b484.g_pNewUserDialogPane](by-memory/0x0069b480-0x0069b484.g_pNewUserDialogPane.md) is the source-ready singleton pointer declaration for this file's older account-registration dialog. The historical B004 `supervisor_recovery_20260705` evidence session reported no function at `0x0069b480`, no durable data symbol/global, operand label `unk_69B480`, zero `get_bytes`/`get_global_value`, and exactly five lifecycle refs: constructor publish/fallback `0x004f9d91`/`0x004f9d98`, raw-cleanup clear `0x004fa0df`, constructor-EH child [UID:0004PL][0x005023f0-0x005023fb.NewUserDialogPaneSingletonClearUnwindHelper](by-memory/0x005023f0-0x005023fb.NewUserDialogPaneSingletonClearUnwindHelper.md), and destructor child [UID:0004PO][0x00502970-0x005029e1.NewUserDialogPaneDestructor](by-memory/0x00502970-0x005029e1.NewUserDialogPaneDestructor.md) clear `0x005029a2`. Manual PE review places the RVA in `.data` virtual zero-fill, so the file route emits:

```cpp
NewUserDialogPane *g_pNewUserDialogPane;
```

The declaration name is inferred source-facing spelling, not a recovered IDA symbol. `make_signature_for_range 0x0069b480-0x0069b484` returned `FF FF FF FF`; keep that as a historical signature-layer confidence cap/tool discrepancy, not as a reason to emit an explicit `-1` initializer. A new by-global page is not required because UID0002X9 has lifecycle writes/clears only, no external consumer/read matrix, and no durable symbol; sibling [UID:0000RE][g_pLoginDialogPane](by-global/g_pLoginDialogPane.md) remains separate. The standalone NewUserDialogPane.cpp route is now resolved rather than left as a folded-file blocker.

## Score Rationale

| Score | Rationale |
| --- | --- |
| Completion `91` | The page now has a resolved standalone route, exact singleton/file-helper/class contents, all thirteen split children, source order, packet/control/resource behavior, compiler exclusions, family boundaries, and historical/rejected alternatives. |
| Confidence `92` | Exact child bytes/routes plus class/vtable/singleton/file-local-helper evidence strongly support the route. Original manifest/spellings and retained constructor no-route cap confidence without blocking emission. |

## Cross-References

- [UID:00009D][NewUserDialogPane](by-class/NewUserDialogPane.md)
- [UID:0000KX][LoginDialogPane](by-file/LoginDialogPane.md)
- [UID:0000I3][ChangePasswordDialogPane](by-file/ChangePasswordDialogPane.md)
- [UID:00019I][0x004f6700-0x004fb62a.MainMenuLoginAndAccountDialogs](by-memory/0x004f6700-0x004fb62a.MainMenuLoginAndAccountDialogs.md)
- [UID:0000IK][CreateUserDialogs](by-file/CreateUserDialogs.md)
- [UID:0000LW][NewUserDialogPane2](by-file/NewUserDialogPane2.md)
- [UID:0004PH][0x004fa3a0-0x004fa5a5.SendCreateAccountRequest](by-memory/0x004fa3a0-0x004fa5a5.SendCreateAccountRequest.md)
- [UID:0004PP][0x0061d2ec-0x0061d384.NewUserDialogPaneVtableData](by-memory/0x0061d2ec-0x0061d384.NewUserDialogPaneVtableData.md)

## Changes

- 2026-07-14 B004 UID0002Q3 bounded implementation repair: synchronized the standalone source inventory to UID0004PD `HandlePacketEvent(Event *)` with exact Event payload access and UID0004PI's direct fixed-buffer conversion, preserving file score/path, source order, all children, B005 family content, and unrelated historical evidence.
- 2026-07-14 B004 UID0002Q3 implementation callback: Raised `86/88 -> 91/92`; resolved standalone `NexusTK/login/NewUserDialogPane.cpp`; linked the singleton, direct file helper, complete class and thirteen exact source/compiler/data children; preserved account-family boundaries, retained constructor caveat, singleton storage discrepancy, and rejected folded/aggregate/compiler-body alternatives.
- 2026-07-05 B004 UID0002X9 implementation callback: Added the source-ready singleton declaration route for [UID:0002X9][0x0069b480-0x0069b484.g_pNewUserDialogPane](by-memory/0x0069b480-0x0069b484.g_pNewUserDialogPane.md) without changing file scores. Evidence: current MCP session `supervisor_recovery_20260705`, zero value/PE zero-fill proof, exact five lifecycle refs, no durable symbol/global, generated empty-marker repair, and preserved `FF FF FF FF` signature-layer confidence cap.
- 2026-06-05: Raised completion/confidence from `80/80` to `86/88` after live IDA MCP evidence confirmed the local method island, hidden cleanup fragment, packet adapter, request/reply helpers, lifecycle helpers, vtable slots, singleton xrefs, and table/padding split. The file stays below final reconstruction quality because the exact standalone/folded source split and member names remain unresolved.
- 2026-06-02: Raised completion/confidence from `74/72` to `80/80` and set `PROPOSED_RECONSTRUCTION_PATH` to `NexusTK/login/`. Evidence: exact NewUser core memory page records corrected account-flow boundaries through `0x004fa7a0`, packet sender/reply helpers, and login-family placement.
- Before: completion/confidence were ungraded at `0/0`.
- Changed to: completion `74`, confidence `72`.
- Summary/evidence: the page documents account-registration role, key method ranges, boundary exclusions, and cross-references; confidence is limited by the exact split from `LoginDialogPane`.
