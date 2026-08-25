*** UID:00009D | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000LV | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000LV | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
class Event;

class NewUserDialogPane : public DialogPane
{
public:
    NewUserDialogPane();
    virtual ~NewUserDialogPane();

protected:
    virtual bool HandlePacketEvent(Event *event);
    virtual void OnControlCommand(int controlIndex, int notifyCode);
    virtual void UpdateCreateUserButtonEnabledState();

private:
    void SubmitCreateUser();
    bool HandleCreateUserReply(const unsigned char *packet);
};

[[CHILDREN]]
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# NewUserDialogPane

## Status

- Confidence: very strong for account-registration behavior, class declaration, exact method children, vtable binding, packet/control flow, no-new-field layout, and lifecycle ownership; original private/virtual spelling and retained constructor liveness remain bounded caps.
- Source file: [UID:0000LV][NewUserDialogPane](by-file/NewUserDialogPane.md) as standalone `NexusTK/login/NewUserDialogPane.cpp`; [UID:0000KX][LoginDialogPane](by-file/LoginDialogPane.md) remains the broader account/login family/index rather than this class's direct source owner.
- Address range: [UID:0002Q3][0x004f9d30-0x004fa7a0.NewUserDialogPaneCoreAndPacketHelpers](by-memory/0x004f9d30-0x004fa7a0.NewUserDialogPaneCoreAndPacketHelpers.md), inside [UID:00019I][0x004f6700-0x004fb62a.MainMenuLoginAndAccountDialogs](by-memory/0x004f6700-0x004fb62a.MainMenuLoginAndAccountDialogs.md)
- Reconstruction status: source-ready class attached to UID0000LV with a complete declaration closed before `[[CHILDREN]]`. Seven class child definitions emit in exact source order; file-local request encoding emits separately through UID0000LV. Compiler cleanup/table/thunk/vtable pages remain blank. Singleton child [UID:0002X9][0x0069b480-0x0069b484.g_pNewUserDialogPane](by-memory/0x0069b480-0x0069b484.g_pNewUserDialogPane.md) retains its declaration through the file route.

## Class Purpose

`NewUserDialogPane` is the older account-registration dialog. It collects username, password, and confirmation text, validates that the password contains a digit and matches confirmation, shows alerts for validation failures, and sends a new-user request.

The binary allocates and accesses exactly the inherited `DialogPane` size `0x26c`; no NewUserDialogPane-specific data member is required. Controls remain inherited registry children addressed by ids `1` through `5`. The three vptr views at offsets `0`, `0xa0`, and `0xa4` are compiler multiple-interface layout, not source fields.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `NewUserDialogPane` | [UID:0004PB][0x004f9d30-0x004fa0a9.NewUserDialogPaneConstructor](by-memory/0x004f9d30-0x004fa0a9.NewUserDialogPaneConstructor.md) | Position 1; builds exact resource/controls/singleton/layer/open flow. Retained source has zero direct current callers. |
| `~NewUserDialogPane` | [UID:0004PO][0x00502970-0x005029e1.NewUserDialogPaneDestructor](by-memory/0x00502970-0x005029e1.NewUserDialogPaneDestructor.md) | Position 2; one ordinary source body anchored at the routed scalar entry; dimmer delete and singleton clear only. |
| `HandlePacketEvent` | [UID:0004PD][0x004fa0f0-0x004fa116.NewUserDialogPaneHandlePacketEvent](by-memory/0x004fa0f0-0x004fa116.NewUserDialogPaneHandlePacketEvent.md) | Position 3; EventHandler secondary slot `+0x10` override; reads `event->m_payload.m_packet.m_data` at exact `Event +0x0c`, accepts opcode `2`, compiler-adjusts only `this-0xa0`, and forwards to `HandleCreateUserReply`. |
| `OnControlCommand` | [UID:0004PE][0x004fa120-0x004fa14e.NewUserDialogPaneOnControlCommand](by-memory/0x004fa120-0x004fa14e.NewUserDialogPaneOnControlCommand.md) | Position 4; control `1` submits, control `2` slides/closes, notify unused, no base call. |
| `UpdateCreateUserButtonEnabledState` | [UID:0004PF][0x004fa150-0x004fa1c9.NewUserDialogPaneUpdateCreateUserButtonEnabledState](by-memory/0x004fa150-0x004fa1c9.NewUserDialogPaneUpdateCreateUserButtonEnabledState.md) | Position 5; enable create control `1` iff text controls `3/4/5` are all nonempty. |
| `SubmitCreateUser` | [UID:0004PG][0x004fa1d0-0x004fa39c.NewUserDialogPaneSubmitCreateUser](by-memory/0x004fa1d0-0x004fa39c.NewUserDialogPaneSubmitCreateUser.md) | Position 6; exact field reads, digit/match validation, typo/localized alerts, dimmer, request call. |
| `HandleCreateUserReply` | [UID:0004PI][0x004fa5b0-0x004fa773.NewUserDialogPaneHandleCreateUserReply](by-memory/0x004fa5b0-0x004fa773.NewUserDialogPaneHandleCreateUserReply.md) | Position 7; exact packet/status/message handling, dimmer-gated error path, success config/misc-dialog handoff. |
| file-local `SendCreateAccountRequest` | [UID:0004PH][0x004fa3a0-0x004fa5a5.SendCreateAccountRequest](by-memory/0x004fa3a0-0x004fa5a5.SendCreateAccountRequest.md) | Not a class child: direct UID0000LV file emitter position 1; exact opcode/three-field request. |

## Compiler And Data Exclusions

- [UID:0004PC][0x004fa0b0-0x004fa0ef.NewUserDialogPaneRawCleanupIsland](by-memory/0x004fa0b0-0x004fa0ef.NewUserDialogPaneRawCleanupIsland.md) is a no-function/no-xref compiler non-deleting cleanup copy, not a second destructor.
- [UID:0004PK][0x004fa773-0x004fa793.NewUserDialogPaneReplySwitchTable](by-memory/0x004fa773-0x004fa793.NewUserDialogPaneReplySwitchTable.md) is compiler switch-lowering data owned semantically by this class but not emitted manually.
- [UID:0004PL][0x005023f0-0x005023fb.NewUserDialogPaneSingletonClearUnwindHelper](by-memory/0x005023f0-0x005023fb.NewUserDialogPaneSingletonClearUnwindHelper.md) is constructor-EH-only rollback support.
- [UID:0004PM][0x0050250e-0x00502524.NewUserDialogPaneDestructorAdjustorThunks](by-memory/0x0050250e-0x00502524.NewUserDialogPaneDestructorAdjustorThunks.md) contains compiler receiver-adjusting destructor thunks.
- [UID:0004PP][0x0061d2ec-0x0061d384.NewUserDialogPaneVtableData](by-memory/0x0061d2ec-0x0061d384.NewUserDialogPaneVtableData.md) is source-declared/compiler-generated vtable data ending before LoginDialogPane data.
- Explicit vptr fields/stores, deleting flags/free, base-destructor calls, EH helpers, adjusted wrappers, switch bytes, raw child offsets, and a decompiler aggregate body are rejected from source.

## Evidence Notes

- Live IDA MCP on 2026-06-05 reports normal function starts at `0x004f9d30`, `0x004fa0f0`, `0x004fa120`, `0x004fa150`, `0x004fa1d0`, `0x004fa3a0`, `0x004fa5b0`, `0x005023f0`, `0x0050250e`, `0x00502519`, and `0x00502970`; `0x004fa0b0` remains an unregistered cleanup fragment with code heads.
- RTTI/vtable data names `??_7NewUserDialogPane@@6B@`, `??_7NewUserDialogPane@@6B@_0`, and `??_7NewUserDialogPane@@6B@_1` bind the primary command/default handlers and secondary packet adapter. Slots include `0x0061d334 -> 0x004fa120`, `0x0061d338 -> 0x004fa150`, `0x0061d35c -> 0x004fa0f0`, and `0x0061d2ec -> 0x00502970`.
- Fresh MCP session `6b2e78f3` at callback recovery reproduced `0x004fa0f0` as a `0x26`-byte EventHandler packet override: it reads `[event+0x0c]`, tests opcode `2`, adjusts the secondary receiver by `-0xa0`, and tail-forwards to `0x004fa5b0`. Current Event/EventHandler declarations and Login sibling UID0004PQ establish `HandlePacketEvent(Event *)`; the superseded `PacketEvent`/`OnCreateUserReplyEvent` contract is rejected.
- `dword_69B480` xrefs tie singleton setup to the constructor, cleanup clearing to the hidden fragment, the explicit clear helper at `0x005023f0`, and destructor clearing at `0x005029a2`.
- Raw-byte checks confirm the internal alignment ranges are `0xcc` padding and that the reply handler is followed by local switch/table bytes through `0x004fa793` before padding to the next `LoginDialogPane` constructor at `0x004fa7a0`.

## Singleton State

[UID:0002X9][0x0069b480-0x0069b484.g_pNewUserDialogPane](by-memory/0x0069b480-0x0069b484.g_pNewUserDialogPane.md) is this class's source-ready singleton pointer state. The source-facing spelling `g_pNewUserDialogPane` is inferred because the historical B004 `supervisor_recovery_20260705` evidence session found no durable IDA data symbol/global and reported `unk_69B480`. The slot is nevertheless strongly class-owned: the constructor publishes or fallback-clears it at `0x004f9d91`/`0x004f9d98`, raw cleanup clears it at `0x004fa0df`, constructor-EH helper [UID:0004PL][0x005023f0-0x005023fb.NewUserDialogPaneSingletonClearUnwindHelper](by-memory/0x005023f0-0x005023fb.NewUserDialogPaneSingletonClearUnwindHelper.md) clears it, and destructor [UID:0004PO][0x00502970-0x005029e1.NewUserDialogPaneDestructor](by-memory/0x00502970-0x005029e1.NewUserDialogPaneDestructor.md) clears it at `0x005029a2`.

B004 current evidence supports the declaration form `NewUserDialogPane *g_pNewUserDialogPane;`: `lookup_funcs 0x0069b480` returns no function, `get_bytes`/`get_global_value` return zero, and PE `.data` section review places the target RVA in virtual zero-fill. `make_signature_for_range` still returns `FF FF FF FF`, so the exact initializer remains a byte-tool confidence cap; this does not change the class owner/emitter route. The child emits through [UID:0000LV][NewUserDialogPane](by-file/NewUserDialogPane.md); no new by-global page is created for this callback because the refs are lifecycle-only and no external consumer/read matrix was found.

## Score Rationale

| Score | Rationale |
| --- | --- |
| Completion `92` | Exact class declaration, no-new-field layout, seven source child methods, file-helper relationship, compiler/data exclusions, packet/control/resource behavior, source ordering, singleton/vtable/destructor lifecycle, and complete formal C++ are resolved. |
| Confidence `94` | Live IDA function/CFG/bytes/xrefs plus RTTI/vtable/singleton symmetry strongly support the class. Original symbols/file manifest and the constructor's zero direct route remain explicit bounded caps. |

## Cross-References

- [UID:0000LV][NewUserDialogPane](by-file/NewUserDialogPane.md)
- [UID:0000KX][LoginDialogPane](by-file/LoginDialogPane.md)
- [UID:00019I][0x004f6700-0x004fb62a.MainMenuLoginAndAccountDialogs](by-memory/0x004f6700-0x004fb62a.MainMenuLoginAndAccountDialogs.md)
- [UID:0004PB][0x004f9d30-0x004fa0a9.NewUserDialogPaneConstructor](by-memory/0x004f9d30-0x004fa0a9.NewUserDialogPaneConstructor.md)
- [UID:0004PO][0x00502970-0x005029e1.NewUserDialogPaneDestructor](by-memory/0x00502970-0x005029e1.NewUserDialogPaneDestructor.md)
- [UID:0004PD][0x004fa0f0-0x004fa116.NewUserDialogPaneHandlePacketEvent](by-memory/0x004fa0f0-0x004fa116.NewUserDialogPaneHandlePacketEvent.md)
- [UID:0004PE][0x004fa120-0x004fa14e.NewUserDialogPaneOnControlCommand](by-memory/0x004fa120-0x004fa14e.NewUserDialogPaneOnControlCommand.md)
- [UID:0004PF][0x004fa150-0x004fa1c9.NewUserDialogPaneUpdateCreateUserButtonEnabledState](by-memory/0x004fa150-0x004fa1c9.NewUserDialogPaneUpdateCreateUserButtonEnabledState.md)
- [UID:0004PG][0x004fa1d0-0x004fa39c.NewUserDialogPaneSubmitCreateUser](by-memory/0x004fa1d0-0x004fa39c.NewUserDialogPaneSubmitCreateUser.md)
- [UID:0004PI][0x004fa5b0-0x004fa773.NewUserDialogPaneHandleCreateUserReply](by-memory/0x004fa5b0-0x004fa773.NewUserDialogPaneHandleCreateUserReply.md)

## Changes

- 2026-07-14 B004 UID0002Q3 bounded implementation repair: replaced the rejected `PacketEvent`/`OnCreateUserReplyEvent` declaration with the exact managed `Event` forward declaration and `virtual bool HandlePacketEvent(Event *event)` while preserving the complete class block, closure before `[[CHILDREN]]`, scores, layout, source order, B005 content, and all unrelated child evidence.
- 2026-07-14 B004 UID0002Q3 implementation callback: Raised `86/90 -> 92/94`; inserted the complete class declaration closed before `[[CHILDREN]]`; linked seven real source children in positions 1-7, the direct file helper, and five compiler/data exclusions; resolved no-new-field layout, source placement, names/types, packet/control behavior, one-destructor source shape, and historical blockers.
- 2026-07-05 B004 UID0002X9 implementation callback: Added class-owned singleton state detail for [UID:0002X9][0x0069b480-0x0069b484.g_pNewUserDialogPane](by-memory/0x0069b480-0x0069b484.g_pNewUserDialogPane.md) without changing class scores. Evidence: current MCP session `supervisor_recovery_20260705`, constructor/cleanup/helper/destructor lifecycle refs, zero value/PE zero-fill proof, missing-symbol caveat, and preserved signature-layer `FF FF FF FF` confidence cap.
- 2026-06-05: Raised completion/confidence from `72/80` to `86/90` after a live IDA MCP refresh verified the full method island, hidden cleanup fragment, request/reply helpers, singleton clear helper, adjustor/deleting destructor family, exact vtable slots, singleton xrefs, and padding/table bytes. C++ remains blank because source-level member names and the cleanup-fragment declaration are still below the 95/95 reconstruction threshold.
- 2026-06-02: Raised completion/confidence from `68/64` to `72/80`, marked reconstructable, and attached to [UID:0000LV][NewUserDialogPane](by-file/NewUserDialogPane.md). Evidence: exact NewUser core memory page records corrected boundaries, packet sender/reply helper coverage, and login-family placement.
- Before: completion/confidence metadata were `0/0` despite basic method, validation, and file/memory ownership notes.
- Changed to: `COMPLETION:68` and `CONFIDENCE:64`.
- Evidence: the page covers purpose, local method roles, destructor family, and validation behavior; confidence stays medium because the page lacks detailed layout/state-field documentation.
