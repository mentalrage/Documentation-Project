*** UID:00008Z | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:90 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000LP | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000LP | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:10 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#pragma once

#include "../ui/core/DialogPane.h"
#include "../util/Singleton.h"
#include "../util/StringBase.h"

class Event;
class NewCreateUserDialogPane;
extern NewCreateUserDialogPane *g_pNewCreateUserDialogPane;

class NewCreateUserDialogPane : public DialogPane,
                                public Singleton<NewCreateUserDialogPane>
{
public:
    NewCreateUserDialogPane();
    virtual ~NewCreateUserDialogPane() {}

protected:
    virtual void OnControlCommand(int controlIndex, int notifyCode);
    virtual bool HandlePointerOrMouseEvent(Event *event);
    virtual bool HandleKeyOrTextEvent(Event *event);
    virtual bool HandlePacketEvent(Event *event);

    void SelectGender(short genderOrNation);
    void SelectTotem(short totem);
    void SelectMale();
    void SelectFemale();
    void OpenNexonclubRegistrationOrSendCharacterRequest(bool openRegistration);
    void OnNexonclubRegistrationResult(
        const mystr::StringBase<
            wchar_t,
            mystr::mychar_traits<wchar_t> > &accountName);

    void SubmitCreateUser();
    void SendCreateCharacterRequest();
    bool HandleCreateUserReply(const unsigned char *packet);

private:
    int m_selectedGenderOrNation;
    int m_selectedTotem;
    int m_compatibilitySelectionState;
    bool m_waitingForCharacterReply;
    mystr::StringBase<wchar_t, mystr::mychar_traits<wchar_t> >
        m_nexonclubAccountName;
};
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# NewCreateUserDialogPane

## Status

- Confidence: very strong for method/vtable/singleton evidence, direct `Singleton<NewCreateUserDialogPane>` inheritance, class/file ownership, login/create-user placement, retained-code interpretation, and H-channel declaration source; direct constructor reachability remains absent after exhaustive current binary checks.
- Likely source file: [UID:0000LP][NewCreateUserDialogPane](by-file/NewCreateUserDialogPane.md), under the [UID:0000IK][CreateUserDialogs](by-file/CreateUserDialogs.md) umbrella
- Address range: [UID:0001CR][0x0052a540-0x0052f94c.CreateUserDialogVariants](by-memory/0x0052a540-0x0052f94c.CreateUserDialogVariants.md)
- Evidence basis: live IDA MCP function, xref, vtable, Singleton RTTI/PMD, constructor-lowering, command-dispatch, PE reachability, and boundary checks through the 2026-07-29 UID0002X8 pass.

## Class Purpose

`NewCreateUserDialogPane` is a newer full-screen create-user dialog variant. It uses `DLGNEW.EPF`, `GENDER.EPF`, `DIREC.EPF`, and `NEWBUTT.PAL`, with username/password fields, gender and totem selection, child id `8` body-shape selection through `NewUserShapeSelectControlPane`, and submit validation.

The formal H carries the complete direct `DialogPane`/`Singleton` declaration, exact four-event virtual surface, inline empty destructor, and recovered tail state. The selector is child id `8`, not a stored `m_shapeSelector` member; [UID:0002QS][0x0052c360-0x0052dcf5.NewCreateUserDialogPaneCore](by-memory/0x0052c360-0x0052dcf5.NewCreateUserDialogPaneCore.md) includes the complete selector header and resolves it with `GetChild<NewUserShapeSelectControlPane>(8)` before selector calls.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `NewCreateUserDialogPane` | `0x0052c360` | Builds the newer full-screen create-user dialog and child controls. |
| `SelectGender` / `SelectTotem` | `0x0052cef0`, `0x0052cf80` | Updates selection buttons and state. |
| `SelectMale` / `SelectFemale` | `0x0052d060`, `0x0052d0b0` | Gender-specific selection setup; terminal tails set the child shape selector body mode to `2`/`6` and invalidate it. |
| `OnControlCommand` | `0x0052d210` | Dialog command dispatcher. |
| `HandleKeyOrTextEvent` / `HandlePacketEvent` / `HandlePointerOrMouseEvent` | `0x0052d2f0`, `0x0052d300`, `0x0052d330` | Exact event forwarder, opcode-`0x02` packet bridge, and pointer/mouse forwarder. |
| `SubmitCreateUser` | `0x0052d3e0` | Validates and sends create-user request. |
| `SendCreateCharacterRequest` | `0x0052d7c0` | Builds the opcode `0x04` create-character payload: reads child selector state, calls `BuildPreviewParams`, then serializes descriptor fields in the dialog. |
| Destructor family | `0x0052f751`, `0x0052f75c`, `0x0052f870` | Adjustor and scalar deleting destructor logic. |

## Evidence Notes

- 2026-06-04 live IDA confirms the constructor, selector helpers, command/event/notify handlers, submit helper, packet/reply helpers, singleton clear helper, adjustor thunks, and scalar deleting destructor starts.
- Live IDA MCP caller checks still show no direct callers for constructor `0x0052c360`, even though the constructor is fully modeled and constructs `NewUserShapeSelectControlPane` through `0x004fd520` at `0x0052c7aa`. B001's selector pass resolves the construction detail as a `0x11c` allocation, `rand()%15` initial selected slot, `ControlPane(8, bounds)` selector construction, and child id `8` registration.
- Live IDA confirms constructor-side writes to singleton `0x0069b4a8` and three `NewCreateUserDialogPane` vtable slots at `0x0061fda0`, `0x0061fe00`, and `0x0061fe30`; the scalar deleting destructor at `0x0052f870` writes the same vtable slots and clears the singleton.
- The `0x0052d210` command dispatcher is a 16-case jump table: case 17 calls submit helper `0x0052d3e0`; cases 4/5 call the local select-male/select-female helpers that tail into selector body-mode writes; cases 9-14 call the local gender/totem selector helpers.
- Reconstructable attachment: this class attaches to [UID:0000LP][NewCreateUserDialogPane](by-file/NewCreateUserDialogPane.md). The formal CPP channel is blank and the complete declaration is in H without an invalid H `[[CHILDREN]]` token; exact method bodies are emitted from [UID:0002QS][0x0052c360-0x0052dcf5.NewCreateUserDialogPaneCore](by-memory/0x0052c360-0x0052dcf5.NewCreateUserDialogPaneCore.md).
- 2026-06-16 A001 live IDA MCP refresh on database `c001_midiplayer_rdata_20260615` reconfirmed the exact core method group: constructor-like body `0x0052c360` size `0x9e9` / 2537 bytes, submit helper `0x0052d3e0` size `0x1cc` / 460 bytes, packet encoder `0x0052d5b0` size `0x205` / 517 bytes, shape-control payload builder `0x0052d7c0` size `0x1df` / 479 bytes, reply handler `0x0052d9a0` size `0x355` / 853 bytes, and scalar deleting destructor `0x0052f870` size `0x6c` / 108 bytes (decimal conversions verified with `tools/int_convert.py` where newly cited).
- The same live pass reconfirmed the internal command/submit/packet/reply chain: `OnCommand` calls local selector helpers and `0x0052d3e0`; `0x0052d3e0` calls packet encoder `0x0052d5b0`; reply handler `0x0052d9a0` calls shape payload builder `0x0052d7c0`; [UID:00009G][NewUserShapeSelectControlPane](by-class/NewUserShapeSelectControlPane.md) constructor `0x004fd520` is called from `0x0052c7aa`.
- B001's 2026-06-25 selector synchronization clarifies that `0x0052d7c0` does not call a selector packet-writer method. It reads the selector's selected slot/page, computes `selectedSlot + 15 * page`, calls `NewUserShapeSelectControlPane::BuildPreviewParams`, then serializes the descriptor fields in this dialog's opcode `0x04` payload builder.
- Live `xrefs_to` still reports zero xrefs to constructor start `0x0052c360`; local PE scans of `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe` found zero absolute-VA pointer hits, zero RVA pointer hits, and zero direct `E8`/`E9` branch or call hits to `0x0052c360`. This confirms the retained reachability blocker is real rather than an unrecorded documentation gap.
- Live `xrefs_to` reconfirmed singleton slot `0x0069b4a8` has six refs and the three vtable views `0x0061fda0`, `0x0061fe00`, and `0x0061fe30` are written from the constructor/fallback cleanup and scalar deleting destructor family.
- Verified supervisor Gate 2B catalog entry `0362` added only an incomplete no-layout `NewCreateUserDialogPane` type and normalized `[0x0069b4a8,0x0069b4ac)` to one size-four `NewCreateUserDialogPane *` data item named `g_pNewCreateUserDialogPane`. Its exact regular/repeatable comments describe active singleton storage and direct `Singleton<NewCreateUserDialogPane>` publication/clear behavior; zero bytes, six start xrefs, zero interior xrefs, both neighboring slots, and all six protected RTTI dependencies remain unchanged.
- The catalog action-time saved IDB for that readback was SHA256 `3C8F31781C94DF74AADDB65B3D944CD2CA4387C448918BBBFFD60B41C3625B69`, 143,191,631 bytes, saved `2026-07-29T14:12:44.7229687-04:00`. Backup `E:/NTK/Resources/NexusTK/backups/NexusTK.exe.pre-B008-UID0002X8-20260729-1412.i64` preserves historical pre-action SHA256 `0E0AF938...AB481` and its four-byte-head/blank-comment state. Later shared-IDB SHA256 values `296ED21C...63CF8B` and `905D1AB1...604C1` are dated no-drift checkpoints. The current authoritative save is SHA256 `412DA7E81557538D283BBFBC18875CACC6C1DBBC662E88BEC71307E0AE0519CD`, 143,191,140 bytes, saved `2026-07-29T15:00:32.0998001-04:00`; bounded read-only MCP checks reconfirmed the class type, target item/comments, bytes/xrefs, neighbors, and six RTTI dependencies without drift.
- 2026-07-05 B001 UID0002SJ support sync: [UID:0002SJ][0x0061fda0-0x0061fe3c.NewCreateUserDialogPaneVtableData](by-memory/0x0061fda0-0x0061fe3c.NewCreateUserDialogPaneVtableData.md) is class-owned but non-reconstructable/non-emitting compiler-generated vtable support. MCP session `supervisor_recovery_20260705` confirmed decorated primary, secondary, and tertiary `NewCreateUserDialogPane` table views at `0x0061fda0`, `0x0061fe00`, and `0x0061fe30`, the `0x0061fe3c` successor boundary, constructor/fallback/destructor stores to all three bases, exact dwords/bytes, no local IDA UDT, and a generated empty-marker state before repair. The class declaration and exact virtual method children are the source representation that regenerates this data; the no-direct-caller caveat remains a confidence cap only.

## Direct Singleton And Header Contract

- Decorated RTTI directly names `NewCreateUserDialogPane` and `Singleton<NewCreateUserDialogPane>`. The direct Singleton base descriptor references type descriptor `0x00677f90`, has contained-base count `0`, PMD `620/-1/0`, and attributes `0x40`.
- PMD displacement `620` is `0x26c`, matching the constructor's adjusted-base sequence. Constructor lowering forms the Singleton subobject at `this+0x26c`, recovers the complete object with `-0x26c`, and publishes/clears loader-zeroed storage `0x0069b4a8`. This proves direct CRTP inheritance and rejects a handwritten global assignment in authored constructor C++.
- Semantic [UID:0002X7][g_pNewCreateUserDialogPane](by-global/g_pNewCreateUserDialogPane.md) is the sole position-0 CPP definition. Physical [UID:0002X8][0x0069b4a8-0x0069b4ac.g_pNewCreateUserDialogPane](by-memory/0x0069b4a8-0x0069b4ac.g_pNewCreateUserDialogPane.md) is `92/94`, false/non-emitting loader-zeroed evidence. This class H block owns the complete declaration and one matching `extern` contract.
- IDA's incomplete no-layout class type is intentionally narrower than this source H declaration: it safely types the global pointer without asserting recovered member layout, inheritance metadata, vtable layout, or size. The formal H block remains the human source reconstruction authority.
- The class formal CPP block is intentionally blank. Declarations belong in H; exact method bodies remain on [UID:0002QS][0x0052c360-0x0052dcf5.NewCreateUserDialogPaneCore](by-memory/0x0052c360-0x0052dcf5.NewCreateUserDialogPaneCore.md). The compiler regenerates the Singleton publication/clear sequence, three vtable views, RTTI, adjustor thunks, and scalar deleting destructor from ordinary class/global/method source.
- Source position `10` places the class/header contract after the position-0 global definition route. Exact CPP children remain attached through their owner/emitter metadata; no H-channel child token is required.

## Singleton Storage And Lifecycle Evidence

- Physical target RVA `0x29b4a8` lies beyond raw-backed `.data`; the absent relocation directory and current `00 00 00 00` bytes prove loader-zeroed BSS-style storage rather than historical `0xffffffff`.
- Exactly six refs reach the pointer start: main-menu cleanup read `0x004f6a13`; constructor publish/fallback `0x0052c3b8`/`0x0052c3bf`; constructor-unwind clear `0x0052cd7a`; Singleton clear helper `0x0052f720`; scalar deleting destructor clear `0x0052f89d`. Target interior bytes have zero refs.
- The class's primary/secondary/tertiary vtable views at `0x0061fda0`, `0x0061fe00`, and `0x0061fe30` are generated support owned by this class. The successor `CreateUserDialogPane` table begins exactly at `0x0061fe3c` and must not be merged.
- Constructor `0x0052c360` still has zero direct xrefs, absolute-VA/RVA pointer hits, and direct branch/call hits. That result remains a retained/indirect-route confidence cap; it does not block the coherent class, method, Singleton, global, vtable, or source-file model.

## Rejected And Historical Source Shapes

- Historical declaration placement in the class CPP block was structurally wrong. The same declaration now lives in the formal H block; the CPP channel is blank.
- Historical omission of the direct Singleton base is superseded by decorated RTTI, PMD `620/-1/0`, and matching constructor lowering.
- Reject historical pre-Gate2B `unk_69B4A8`/`dword_69B4A8` names, explicit address-backed data, handwritten publication/clear code, raw vtable/RTTI arrays, adjustor-thunk bodies, scalar-deleting-destructor flag handling, and source arrays of function pointers. Current IDA uses `g_pNewCreateUserDialogPane` for the exact typed storage.
- Field and helper spellings remain inferred source-facing names rather than recovered symbols. They are retained because they are internally consistent and human-readable; raw decompiler aliases are not acceptable final source alternatives.

## Source-Quality Decision

The class clears the documentation gate because its constructor-like body, selector helpers, four-event virtual surface, submit/packet/reply flow, shape-control dependency, three-view vtable data, direct Singleton RTTI/PMD, exact singleton storage/lifecycle, and file route are all supported by exact child pages and current live IDA checks. Child id `8` supplies selector state and descriptor params through a local `GetChild` lookup; no selector pointer exists in the recovered tail layout. The exact tail is `m_selectedGenderOrNation` at `+0x26c`, `m_selectedTotem` at `+0x270`, unreferenced compatibility storage at `+0x274`, reply state at `+0x278`, and account text at `+0x27c`. The unreferenced constructor start remains retained/no-direct-caller evidence, not a reason to suppress method-body source.

## Score Rationale

| Metric | Score | Rationale |
| --- | ---: | --- |
| Completion | `90` | The page records exact method families, current live sizes/edges, direct Singleton inheritance and PMD/lowering, loader-zeroed singleton storage, three vtable views, shape-control dependency, file/source placement, explicit reachability checks, separate CPP/H dispositions, the extern contract, source-facing names, and generated-artifact exclusions. |
| Confidence | `92` | Behavior, inheritance, ownership, and source channels are strongly corroborated by exact memory/global/vtable children, decorated RTTI, constructor lowering, and live IDA. Confidence remains below final-source audit because constructor reachability is absent and exact original field/helper spellings are inferred. |

## 2026-06-21 B010 Source-Quality Incorporation

- [UID:0002QS][0x0052c360-0x0052dcf5.NewCreateUserDialogPaneCore](by-memory/0x0052c360-0x0052dcf5.NewCreateUserDialogPaneCore.md) now routes directly through this class, while this class emits through [UID:0000LP][NewCreateUserDialogPane](by-file/NewCreateUserDialogPane.md). [UID:0000IK][CreateUserDialogs](by-file/CreateUserDialogs.md) is non-emitting family context only.
- The no-direct-caller status is kept as positive retained-code evidence: live xrefs and local PE scans find no constructor caller, no absolute/RVA pointer to `0x0052c360`, and no direct branch/call target. The class is still coherent from constructor, selector helpers, command dispatch, submit/packet/reply helpers, `NewUserShapeSelectControlPane` construction, singleton `g_pNewCreateUserDialogPane`, and vtable groups.
- Source-facing method names are constructor, gender/totem selectors, `SelectMale`, `SelectFemale`, `OnCommand`, submit, file-local opcode `0x02` account helper, opcode `0x04` create-character payload builder, and two-phase reply handler.
- Field candidates are selected option bytes for gender/nation and totem/style, `m_shapeSelector` for the child id `8` `NewUserShapeSelectControlPane` dependency, `m_waitingForCharacterReply`, and `m_createdUserName`. Exact original spellings remain provisional, but descriptive names are strong enough for draft C++ and should not be left as uninvestigated blockers. The selector builds descriptor params; the dialog serializes them.

## Cross-References

- [UID:0000LP][NewCreateUserDialogPane](by-file/NewCreateUserDialogPane.md)
- [UID:0000IK][CreateUserDialogs](by-file/CreateUserDialogs.md)
- [UID:00009G][NewUserShapeSelectControlPane](by-class/NewUserShapeSelectControlPane.md)
- [UID:00003B][CreateUserDialogPane](by-class/CreateUserDialogPane.md)

## 2026-08-11 UID0001CU Registration-Provider Incorporation

- Metadata remains `90/92`; owner/emitter remain [UID:0000LP][NewCreateUserDialogPane](by-file/NewCreateUserDialogPane.md), reconstructable remains true, position remains `10`, and `Nested:0` remains exact.
- Formal CPP remains blank. Formal H now preserves the complete declaration, singleton pointer, existing event/selection methods, registration opener/result pair, request/reply methods, selector state, waiting byte, and wide account-name field.
- UID0002QS owns the complete aggregate CPP and its translation-unit-local RegistrationString alias. The public H uses full StringBase spelling, closes the class without a `[[CHILDREN]]` token, and leaves all qualified method definitions on the CPP route.

## Changes

- 2026-08-11 B005 UID0000LY consumer closure:
  - Added the exact `class NewUserShapeSelectControlPane;` formal-H declaration immediately after `class NewCreateUserDialogPane;`, preserving the established extern and class order.
  - Documented the division between this pointer-level H contract and the complete selector include required by [UID:0002QS][0x0052c360-0x0052dcf5.NewCreateUserDialogPaneCore](by-memory/0x0052c360-0x0052dcf5.NewCreateUserDialogPaneCore.md) method bodies.

- 2026-06-25 B001 selector synchronization:
  - Score unchanged.
  - Summary/evidence: synchronized the `m_shapeSelector` member/control relationship with accepted [UID:0002Q9][0x004fd520-0x004fdd33.NewUserShapeSelectControlPaneCore](by-memory/0x004fd520-0x004fdd33.NewUserShapeSelectControlPaneCore.md) evidence. Constructor setup now records allocation size `0x11c`, child id `8`, and initial `rand()%15` selected slot; `SelectMale`/`SelectFemale` now mention selector body-mode tail writes; `SendCreateCharacterRequest` now describes `BuildPreviewParams` followed by dialog-side packet serialization.
- Before: completion/confidence metadata were `0/0` even though the page already contained purpose, method, evidence, and cross-reference documentation.
- Changed to: `COMPLETION:72` and `CONFIDENCE:84`.
- Evidence: the page documents the dialog's assets, major controls, command/submit methods, destructor family, and file/memory/class relationships; remaining gaps are detailed layout/state fields and confirmed live constructor reachability.
- 2026-06-02 autogen attachment:
  - What existed before: the class had no reconstructable flag or parent attachment.
  - Changed to: `RECONSTRUCTABLE:TRUE` and attachment to [UID:0000LP][NewCreateUserDialogPane](by-file/NewCreateUserDialogPane.md), now represented by `CANONICAL_OWNER:0000LP` and `EMITTER_UIDS:0000LP`.
  - Summary/evidence: exact child memory evidence and the validated login/create-user file parent support attachment; reconstructed C++ remains blank until final names, layout, and reachability are audited.
- 2026-06-04 live IDA evidence update:
  - What existed before: completion/confidence were `72/84`, with stale recovered-source provenance and lighter evidence notes.
  - Changed to: completion `82`, confidence `86`, and evidence notes now cite live IDA MCP function starts, vtable/singleton writes, shape-control construction, command dispatch, and destructor support.
  - Summary/evidence: the class method map is now backed by live disassembly/xrefs rather than stale provenance. The score remains below final-source status because direct constructor reachability and field/layout names are still unresolved.
- 2026-06-16 A001 class low-confidence refresh: raised from `82/86` to `85/88`. Live IDA MCP reconfirmed constructor/submit/packet/payload/reply/destructor sizes, internal command and reply edges, shape-control construction, vtable/singleton refs, and zero constructor xrefs. Local PE scans found no absolute VA/RVA pointer hits and no direct branch/call hits to `0x0052c360`, so the retained direct-constructor reachability blocker is documented as real. Owner/emitter remain [UID:0000LP][NewCreateUserDialogPane](by-file/NewCreateUserDialogPane.md); final C++ remains blank pending source-placement and field/helper naming.
- 2026-06-21 B010 Rule 26 source-quality incorporation:
  - Changed to: `87/89`, first-draft class declaration C++ populated, owner/emitter unchanged [UID:0000LP][NewCreateUserDialogPane](by-file/NewCreateUserDialogPane.md).
  - Summary/evidence: incorporated B010's retained/no-direct-caller interpretation, direct child routing through this class, method/helper names, field candidates, `g_pNewCreateUserDialogPane` naming, packet-helper alias rejection, and the correction that final method C++ should live on the exact child page rather than a synthetic umbrella.
- 2026-07-05 B001 UID0002SJ vtable-data support sync:
  - Score unchanged.
  - Summary/evidence: synchronized the class page with UID0002SJ after live MCP confirmed the full `0x0061fda0-0x0061fe3c` `NewCreateUserDialogPane` vtable block. UID0002SJ is direct class-owned generated-binary support and remains no-code/non-emitting; this class declaration plus virtual method children are the source-level route.
- 2026-07-29 B008 UID0002X8 Rule 26 implementation:
  - Changed to `90/92`, source position `10`, blank formal CPP, and exact formal H declaration.
  - Added direct `Singleton<NewCreateUserDialogPane>` inheritance, the matching global extern, RTTI/PMD `620/-1/0` and constructor-lowering evidence, PE loader-zero/six-reference lifecycle evidence, physical-versus-semantic one-definition routing, generated vtable/thunk/scalar-wrapper exclusions, and historicalized the old CPP-channel declaration and missing-Singleton model.
- 2026-07-29 supervisor Gate 2B catalog entry `0362` synchronization:
  - Recorded the verified incomplete no-layout type and exact typed/named physical singleton item/comments without treating the IDA type as a recovered complete class layout.
  - Preserved catalog action-time save SHA256 `3C8F31781C94DF74AADDB65B3D944CD2CA4387C448918BBBFFD60B41C3625B69`, backup/prestate chronology, unchanged bytes/xrefs/neighbors, and all six protected RTTI dependency readbacks; dated checkpoints `296ED21C...63CF8B`/`905D1AB1...604C1` and current shared-IDB SHA256 `412DA7E8...519CD` retain the same target state.
