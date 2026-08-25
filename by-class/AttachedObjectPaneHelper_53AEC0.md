*** UID:00000N | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:95 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:NONE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:FALSE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# AttachedObjectPaneHelper_53AEC0

## Status

- Confidence is very strong that `AttachedObjectPaneHelper_53AEC0` is a rejected generated pseudo-class, not an allocated source-level type. Exact original identifier spelling remains an archival uncertainty, not an active naming blocker.
- Source disposition: no standalone class. The exact body [UID:0001DF][0x0053aec0-0x0053b012.LivingObjectPaneUnregisterAttachedObjectPane](by-memory/0x0053aec0-0x0053b012.LivingObjectPaneUnregisterAttachedObjectPane.md) is owned/emitted by [UID:00007B][LivingObjectPane](by-class/LivingObjectPane.md) through [UID:0000KU][LivingObjectPane](by-file/LivingObjectPane.md).
- Caller context only: [UID:0000HJ][AttachedObjectPane](by-file/AttachedObjectPane.md) supplies the sole destructor call at `0x005382b0` through `LivingObjectPane *m_livingObjectPane` at `AttachedObjectPane +0x128`.
- Metadata remains intentionally `RECONSTRUCTABLE:FALSE`, `CANONICAL_OWNER:NONE`, with blank emitters and blank formal CPP/H.

## Class Purpose

`AttachedObjectPaneHelper_53AEC0` is a rejected pseudo-class label around one owner-side deregistration method. Current IDA evidence shows that the receiver is a typed `LivingObjectPane *`, not an instance of a separate helper class. The object passed from [UID:00000M][AttachedObjectPane](by-class/AttachedObjectPane.md) offset `+0x128` is the same LivingObjectPane whose constructors, registration methods, and teardown own the affected lists and singleton slots.

The method removes a destroyed attached overlay from registry storage. It uses the destroyed object's type byte at `+0xf8` to decide whether to remove it from a pointer list or clear a singleton slot.

## Ownership Decision

- Treat this as a generated pseudo-class name retained only for quarantine/index history. Do not create a source class, constructor, destructor, vtable, RTTI object, data member layout, source file, or header for it.
- The real receiver is `LivingObjectPane *m_livingObjectPane`, loaded by the sole caller from [UID:00000M][AttachedObjectPane](by-class/AttachedObjectPane.md) offset `+0x128`. The callee mutates fields owned and lifecycle-managed by [UID:00007B][LivingObjectPane](by-class/LivingObjectPane.md).
- The accepted source method is `LivingObjectPane::UnregisterAttachedObjectPane(AttachedObjectPane *pane)` under UID0001DF. AttachedObjectPane is destruction-time caller context and does not own the function.
- Keep this page as a non-reconstructable, ownerless, non-emitting index. A class declaration or formal CPP/H payload here would duplicate accepted source and misrepresent the original source shape.

## Method Notes

| Method | Address | Role |
| --- | --- | --- |
| `LivingObjectPane::UnregisterAttachedObjectPane` | `[0x0053aec0,0x0053b012)` | Null-checks the pane; removes the first type `2` or `4` pointer match from the primary/secondary Effect list; clears type `6`, `7`, and `9` singleton slots; clears type `8` only when [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md) is true. Owned by LivingObjectPane, not this pseudo-class. |

## Layout Notes

| Offset | Field | Notes |
| --- | --- | --- |
| `+0x170` | `List *m_primaryEffectObjectPanes` | LivingObjectPane-owned primary Effect list; type `2` removes the first matching pointer. |
| `+0x174` | `List *m_secondaryEffectObjectPanes` | LivingObjectPane-owned secondary Effect list; type `4` removes the first matching pointer. |
| `+0x1d8` | `BalloonObjectPane *m_balloonObjectPane` | LivingObjectPane singleton slot cleared by type `6`. |
| `+0x1dc` | `HitBarObjectPane *m_hitBarObjectPane` | LivingObjectPane singleton slot cleared by type `7`. |
| `+0x1e0` | `DamageNumberObjectPane *m_damageNumberObjectPane` | LivingObjectPane singleton slot cleared by type `8` only in EPF/current mode. |
| `+0x1e4` | `ObjectInfoObjectPane *m_objectInfoObjectPane` | LivingObjectPane singleton slot cleared by type `9`. |

## Complete No-Class Inventory

| Candidate class artifact | Current evidence | Disposition |
| --- | --- | --- |
| allocated helper object | No allocation, object-size use, instance storage, or class-sized data object exists. | Rejected. |
| helper constructor/destructor | No constructor or destructor for a helper type exists. `0x00538100` is the AttachedObjectPane non-deleting destructor and only calls the owner method. | Rejected. |
| vtable / RTTI | No vtable store, vftable object, RTTI descriptor, or dynamic-cast route identifies this pseudo-class. | Rejected. |
| class receiver | UID0001DF is typed `void __thiscall(LivingObjectPane *this, AttachedObjectPane *pane)`. | Actual receiver is LivingObjectPane. |
| independent methods | Only UID0001DF was assigned to the generated identity; adjacent methods are the LivingObjectPane registration/teardown family. | No class method family. |
| fields | All mutated storage is the typed LivingObjectPane registry at `+0x170/+0x174/+0x1d8/+0x1dc/+0x1e0/+0x1e4`. | No pseudo-class layout. |
| globals/statics/data | `g_useEpfAssets` is process-wide state owned elsewhere; the two adjacent tables are compiler switch support. | No class-owned data. |
| callbacks/exports/pointers | One external direct call from `0x005382b0`; no independent callback, export, function-pointer table, or encoded VA/RVA pointer route. | No class interface. |
| source cluster | UID0001DF is physically adjacent to LivingObjectPane teardown and registration methods and uses their exact fields. | LivingObjectPane source island. |
| generated class/source/header | LivingObjectPane.cpp contains the sole declaration/definition; no target class, `.cpp`, or `.h` is generated. | Absence is correct. |

The pseudo-class therefore has zero source-level members, methods, declarations, definitions, or data of its own. Its only valid role is preserving the rejected historical identity and pointing to the actual source route.

## Exact Current Method And Boundary Context

- UID0001DF is `[0x0053aec0,0x0053b012)`, size `0x152`, with 29 basic blocks, cyclomatic complexity 19, and zero direct ordinary callees. Its exact typed receiver/parameter are `LivingObjectPane *this` and `AttachedObjectPane *pane`.
- The sole external code xref is the call at `0x005382b0`. The caller loads `m_livingObjectPane` from `AttachedObjectPane +0x128` and passes the dying AttachedObjectPane as the second argument.
- `LivingObjectPane` is `0x20c` bytes and `AttachedObjectPane` is `0x12c` bytes in the current typed UDTs. Constructors at `0x0053a110` and `0x0053a360`, teardown at `0x0053ab40`, and setters/adders at `0x0053ada0-0x0053aeb4` own the exact same registry fields.
- `[0x0053aeb4,0x0053aec0)` is twelve `0xCC` bytes; `[0x0053b012,0x0053b014)` is `66 90`; `[0x0053b014,0x0053b034)` and `[0x0053b034,0x0053b054)` are compiler jump tables; `[0x0053b054,0x0053b060)` is twelve `0xCC` bytes. None is pseudo-class source.
- `jpt_53AEEE` and `jpt_53AF69` each have one inbound switch reference, and every target is internal to UID0001DF. They require no source-authored table member.

## No-Code / No-Header And Generated Readback

- `RECONSTRUCTABLE:FALSE`, `CANONICAL_OWNER:NONE`, blank `EMITTER_UIDS`, and blank formal `RECONSTRUCTION_CPP CODE` / `RECONSTRUCTION_H CODE` are the required source-quality state for this rejected class identity.
- Dated pre-callback physical readback on 2026-08-14: `auto-generated/NexusTK/map/LivingObjectPane.cpp`, validator command `000000023592`, 35,754 bytes, 1,156 lines, SHA256 `26AD636D9F63CF00092CDEF4EEC4C3059AF93F82DC9DB567F6FA791B8ECA33DF`.
- The generated source contains exactly one LivingObjectPane declaration and one complete UID0001DF definition. It contains no stub, placeholder, empty marker, duplicate body, or ordering defect for this method.
- No `AttachedObjectPaneHelper_53AEC0.cpp` or `.h` exists or is required. Adding formal code here would emit duplicate behavior and invent an unsupported class/interface.

## Evidence Notes

- 2026-08-14 B003 live read-only IDA MCP session `supervisor-uid0000IW-recovery-20260814` passed canonical runtime attestation and reconfirmed the typed method, exact range, one caller, UDT sizes/fields, table items/xrefs, boundary bytes, and broad one-byte `bool g_useEpfAssets` state with 366 xrefs.
- Current source-facing names are resolved strongly enough for reconstruction: `LivingObjectPane::UnregisterAttachedObjectPane`, `m_primaryEffectObjectPanes`, `m_secondaryEffectObjectPanes`, `m_balloonObjectPane`, `m_hitBarObjectPane`, `m_damageNumberObjectPane`, `m_objectInfoObjectPane`, and the six public `ObjectPaneType` names. Lack of original debug symbols remains a confidence cap, not a reason to use raw labels.

- 2026-06-16 A001 live IDA MCP session `c001_midiplayer_rdata_20260615` reconfirmed `sub_53AEC0` at `0x0053aec0` size `0x152`, `sub_538100` at `0x00538100` size `0x1f8`, `0x0053b011` still inside the helper, and no function at `0x0053b012`.
- 2026-06-16 `xrefs_to 0x0053aec0` returned exactly one code xref, `0x005382b0` inside `sub_538100`; `analyze_component` on `0x00538100` and `0x0053aec0` reported the same single internal edge from the destructor to the detach helper, with `0x0053aec0` internal-only and zero ordinary callees.
- 2026-06-16 listing search for the registry field offsets found setup/cleanup evidence outside the generated pseudo-class: [UID:0002R0][0x0053a110-0x0053a6a6.LivingObjectPaneConstructionAndCleanup](by-memory/0x0053a110-0x0053a6a6.LivingObjectPaneConstructionAndCleanup.md) writes the same `+0x170`, `+0x174`, `+0x1d8`, `+0x1dc`, `+0x1e0`, and `+0x1e4` fields in the two `LivingObjectPane` constructor variants. This resolves the old "registry setup not found" blocker and, with B001's same-field cleanup/replacement and raw PE negative-route evidence, resolves the exact helper body to [UID:00007B][LivingObjectPane](by-class/LivingObjectPane.md). The attached-pane destructor remains the caller/source-use context only.
- 2026-06-16 section-mapped PE scan found zero absolute-VA and zero RVA dword encodings for `0x0053aec0`, with the single direct `E8`/`E9` hit at `0x005382b0`. The same scan found direct constructor branches to `0x0053a110` at `0x0050609b` and `0x0053a360` at `0x005a256b`, matching the documented `LivingObjectPane` setup evidence.
- 2026-05-25 IDA MCP recheck confirms `0x0053aec0` is still only referenced from `0x005382b0` inside `AttachedObjectPane::~AttachedObjectPane`.
- 2026-05-26 IDA MCP recheck again reports `sub_53AEC0` size `0x152`, a single caller/xref at `0x005382b0`, and the destructor call shape `sub_53AEC0(*(this + 0x128), this)`.
- `AttachedObjectPane::~AttachedObjectPane` at `0x00538100-0x005382f8` is the only IDA-confirmed caller.
- The call passes the `AttachedObjectPane` itself as the detached object and the field at `AttachedObjectPane + 0x128` as this helper's `this` pointer.
- The historical generated global name `g_attachmentModeFlag` is misleading. The canonical global is [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md); preserve `byte_66DA97` only as the IDA lookup alias.
- 2026-05-26 decompilation reconfirmed the current/EPF branch clears type `8` at registry `+0x1e0`; the legacy branch does not clear that slot.

## Non-Standalone State

- `RECONSTRUCTABLE:FALSE` is intentional for this class page. The exact body is reconstructable through [UID:0001DF][0x0053aec0-0x0053b012.LivingObjectPaneUnregisterAttachedObjectPane](by-memory/0x0053aec0-0x0053b012.LivingObjectPaneUnregisterAttachedObjectPane.md), not through a declaration named `AttachedObjectPaneHelper_53AEC0`.
- Do not attach this page to a file root or emit class C++. The complete no-class inventory rejects an allocated registry type, and the actual method/declaration already emit once through LivingObjectPane.
- No active method, field, enum, ownership, or CPP/H blocker remains for this disposition. Exact original spelling/source-control history remains the only archival uncertainty and is represented by the confidence cap.

## Score Rationale

- Completion is `94` because the page now contains the complete no-class inventory, typed receiver and field route, exact caller/range/behavior, compiler-boundary exclusions, rejected alternatives, actual source placement, and formal no-code/no-header proof.
- Confidence is `95` because live IDA, raw PE, UDT, neighboring lifecycle methods, accepted support docs, and generated output independently reject the pseudo-class and confirm LivingObjectPane ownership. The remaining cap reflects unavailable original symbols/history, not unresolved source-quality names.

## Cross-References

- [UID:0000HJ][AttachedObjectPane](by-file/AttachedObjectPane.md)
- [UID:00007B][LivingObjectPane](by-class/LivingObjectPane.md)
- [UID:0000HK][AttachedObjectPaneHelper_53AEC0](by-file/AttachedObjectPaneHelper_53AEC0.md)
- [UID:0001DF][0x0053aec0-0x0053b012.LivingObjectPaneUnregisterAttachedObjectPane](by-memory/0x0053aec0-0x0053b012.LivingObjectPaneUnregisterAttachedObjectPane.md)
- [UID:0001TR][AttachedObjectRegistryLayout](by-type/by-struct/AttachedObjectRegistryLayout.md)
- [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md)

## Changes

- 2026-08-14 B003 UID0000HK/UID00000N implementation callback:
  - Raised scores from `85/89` to `94/95` while preserving `RECONSTRUCTABLE:FALSE`, `CANONICAL_OWNER:NONE`, blank emitters, and blank formal CPP/H.
  - Added the complete no-class inventory, exact typed method/caller/field/boundary evidence, actual LivingObjectPane route, generated-source readback, and explicit no-code/no-header proof.
  - Historical raw/generated method, field, enum, and AttachedObjectPane-owner assumptions remain below as dated superseded provenance; they are no longer active blockers.

- 2026-06-16 B001 source-shape execution:
  - Scores unchanged at `85/89`; `RECONSTRUCTABLE:FALSE`, `CANONICAL_OWNER:NONE`, and blank emitters remain correct for this rejected pseudo-class.
  - Resolved the B-agent handoff question: exact body [UID:0001DF][0x0053aec0-0x0053b012.LivingObjectPaneUnregisterAttachedObjectPane](by-memory/0x0053aec0-0x0053b012.LivingObjectPaneUnregisterAttachedObjectPane.md) belongs to [UID:00007B][LivingObjectPane](by-class/LivingObjectPane.md), not to this pseudo-class and not to [UID:0000HJ][AttachedObjectPane](by-file/AttachedObjectPane.md).
  - Evidence: B001 checked the sole attached-pane destructor call, LivingObjectPane constructor/list setup, same-field cleanup/replacement helpers, attached-overlay constructors storing the owner pointer at `+0x128`, raw PE pointer/branch scans, and the compiler switch tables after the function body.

- 2026-06-16 A001 Goal 2 file/class completion pass:
  - Before: `COMPLETION:82`, `CONFIDENCE:88`; the page rejected the pseudo-class but still treated the registry setup/owner as unresolved.
  - Changed to: `COMPLETION:85`, `CONFIDENCE:89`, with current live IDA evidence, LivingObjectPane registry-field setup evidence, and a concrete B-agent source-shape handoff question.
  - Evidence: `lookup_funcs`, `xrefs_to`, `analyze_component`, `search_text`, and a section-mapped PE scan reconfirmed the sole destructor edge to `0x0053aec0`, zero pointer encodings, LivingObjectPane constructor setup writes for the same registry offsets, and direct constructor branches to `0x0053a110`/`0x0053a360`. The page remains non-reconstructable and ownerless because `AttachedObjectPaneHelper_53AEC0` is still only a rejected generated identity.
- 2026-06-07 A008 alias cleanup:
  - Before: method and evidence notes still described the type `8` branch through the bare `byte_66DA97` / generated `g_attachmentModeFlag` names.
  - Changed to: canonical [UID:0000SW][g_useEpfAssets](by-global/g_useEpfAssets.md) wording with `byte_66DA97` retained as the historical IDA alias.
  - Evidence: this does not change class disposition or behavior; it only aligns the helper with the reviewed global identity.
- 2026-06-06 non-standalone cleanup:
  - Before: the page already rejected the helper name but still used recovered-source/Wave-derived status wording and the manual coverage row still treated it as reconstructable.
  - Changed to: `82/88`, explicit exact-helper range reference, non-standalone state, and historical-generated-name wording while preserving `RECONSTRUCTABLE:FALSE`.
  - Evidence at that time: [UID:0001DF][0x0053aec0-0x0053b012.LivingObjectPaneUnregisterAttachedObjectPane](by-memory/0x0053aec0-0x0053b012.LivingObjectPaneUnregisterAttachedObjectPane.md) records the exact helper, [UID:00000M][AttachedObjectPane](by-class/AttachedObjectPane.md) records the destructor caller and registry field, and [UID:0000HJ][AttachedObjectPane](by-file/AttachedObjectPane.md) was the then-current source root. B001's 2026-06-16 source-shape pass supersedes that route for the exact helper body and assigns it to [UID:00007B][LivingObjectPane](by-class/LivingObjectPane.md).
- 2026-06-05: Changed autogen reconstructability from blank to `FALSE`.
  - Before: the page already rejected `AttachedObjectPaneHelper_53AEC0` as a final class name, but blank metadata left it unclassified in `-ag-class-coverage.md`.
  - After: the page is explicitly non-reconstructable as a standalone class; the real helper behavior stays documented under [UID:00000M][AttachedObjectPane](by-class/AttachedObjectPane.md), [UID:0000HJ][AttachedObjectPane](by-file/AttachedObjectPane.md), and the exact memory range.
  - Evidence: live IDA MCP on 2026-06-05 confirms `sub_53AEC0` at `0x0053aec0` (`0x152` bytes) and a single direct caller at `0x005382b0` inside `sub_538100`, matching the documented destructor-owned registry helper.
- What existed before: the page documented the detach helper and provisional-name warning but still had unevaluated scores.
- What it was changed to: scores were set to `76/88`, and an ownership-decision section was added to make the pseudo-class status explicit.
- Summary and evidence: IDA confirms a single caller from `AttachedObjectPane::~AttachedObjectPane`, the registry pointer call shape, and clear slot/list behavior; confidence is strong for behavior but the final source owner is intentionally not treated as a standalone class.
