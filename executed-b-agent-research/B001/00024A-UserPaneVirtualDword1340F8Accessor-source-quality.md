** TARGET-REPORT-UID:00024A **
** AUTHOR-AGENT-ID:B001 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 00024A UserPane Virtual Dword1340F8 Accessor Source-Quality Research

## Finalized Report / Current Recommendation

- Assignment id: `B001-goal2-userpane-virtual-dword1340f8-accessor-source-quality-00024A-20260618`.
- Target: [UID:00024A] `by-memory/0x005b83a0-0x005b83a7.UserPaneVirtualDword1340F8Accessor.md`.
- Current state: `COMPLETION:82`, `CONFIDENCE:90`, `CANONICAL_OWNER:0000P1`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000P1`, blank formal C++.
- Recommendation: rename the page to `by-memory/0x005b83a0-0x005b83a7.UserPaneGetMapPane.md`, retitle it `UserPane GetMapPane`, replace the stale `dword`/`field_1340F8` wording with `MapPane *m_mapPane`, and populate formal C++ with the one-line `UserPane::GetMapPane` body below.
- Metadata recommendation: `COMPLETION:89`, `CONFIDENCE:92`, `CANONICAL_OWNER:0000FQ`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000FQ`, `EMITTER_POSITION_OPTIONAL:` blank.
- Source placement: direct semantic owner is [UID:0000FQ] `UserPane` class; generated source still surfaces through [UID:0000P1] `NexusTK/ui/panels/UserPane.cpp` because the class page already has `EMITTER_UIDS:0000P1`.
- Confidence: very strong for range, vtable ownership, field type as a `MapPane *`, lifetime semantics, and source route. The exact original spelling is not proven, so the recommended name is descriptive/high-probability rather than symbol-proof.

## Target And Support Context

- Primary target path read: `E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\0x005b83a0-0x005b83a7.UserPaneVirtualDword1340F8Accessor.md`.
- Required rules read: `Supervisor.md`, Agent-B001 `goal.md`, Agent-B001 `notes.md`, `by-structure.md`, `inference_research.md`, and `by-project-structure/proposed-source-tree.md`.
- Support pages inspected:
  - [UID:0000P1] `by-file/UserPane.md`.
  - [UID:0000FQ] `by-class/UserPane.md`.
  - [UID:0001KL] `by-memory/0x005a2530-0x005b8395.UserPane.md`.
  - [UID:0002YU] `by-memory/0x0062ef0c-0x0062efcc.UserPaneVtableData.md`.
  - [UID:00026W] `by-memory/0x0062ef0c-0x006307ec.UserPaneInputVtables.md`.
  - [UID:0000L3] `by-file/MapPane.md`.
  - [UID:00007Q] `by-class/MapPane.md`.
  - [UID:0002QM] `by-memory/0x005059d0-0x00505bf8.MapPaneRecenterAndSendPosition.md`.
  - [UID:00037Q] `by-memory/0x00506970-0x00506cdd.MapPaneObjectLookupHelpers.md`.
  - [UID:0000PR] `by-global/g_activeMapPane.md`.
  - [UID:0001OW] `by-memory/0x0067a764-0x0067a768.ActiveMapPaneSingleton.md`.
  - Recent executed B001 reports under `research/executed` were searched for `00024A`, `0x005b83a0`, and `1340f8`; no prior dedicated B-agent report for this target was found.

## Evidence Checked

### Exact Target Facts

- The target body bytes are `8B 81 F8 40 13 00 C3`, decoded as `mov eax, dword ptr [ecx + 0x1340f8]; ret`.
- Function range remains exact: `0x005b83a0-0x005b83a7`, size `0x7`.
- Boundary padding remains exact: `0x005b8395-0x005b83a0` is eleven `0xcc` bytes after the UserPane scalar destructor, and `0x005b83a7-0x005b83b0` is nine `0xcc` bytes before the UserStatusPane range.
- Static xrefs/callers: the only documented xref is the data xref from UserPane vtable slot `0x0062ef28`; no static callers or callees are known for the function body.
- Vtable context: [UID:0002YU] records the `0x0062ef0c-0x0062efcc` UserPane vtable data, including `0x0062ef28 -> 0x005b83a0`; neighboring slots include UserPane virtual handlers at `0x005a5b80`, `0x005a8840`, `0x005a8e70`, `0x005a8f60`, `0x005a5bd0`, `0x005a76c0`, and `0x005a83b0`.

### Raw Operand Search

I rechecked the read-only PE `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe` with a Capstone 32-bit disassembly pass over the known UserPane/local-player function ranges. The scan found exactly 68 instruction operands using memory displacement `0x1340f8`, matching the current target's "68 known displacement users" premise.

| Function range | Count | Operand addresses checked | Behavior group |
| --- | ---: | --- | --- |
| `0x005a2530-0x005a2c5b` `sub_5A2530` | 6 | `0x005a277b`, `0x005a2792`, `0x005a27e7`, `0x005a2a85`, `0x005a2a9c`, `0x005a2ae8` | UserPane constructor duplicates: zero the field, copy `g_activeMapPane`, write `MapPane+0x418 = this`, then call a MapPane coordinate helper when non-null. |
| `0x005a2e00-0x005a36de` `sub_5A2E00` | 9 | `0x005a2fcf`, `0x005a300e`, `0x005a31ac`, `0x005a31f4`, `0x005a3227`, `0x005a323a`, `0x005a3429`, `0x005a34f6`, `0x005a360c` | Local-player movement processing; uses the field as `ecx` for MapPane coordinate/viewport helper calls and reads MapPane dimension/state fields. |
| `0x005a36f0-0x005a3766` `sub_5A36F0` | 1 | `0x005a3754` | Movement/timer follow-up; loads the field as `ecx` and calls `0x00506980`. |
| `0x005a3770-0x005a386a` `sub_5A3770` | 2 | `0x005a380e`, `0x005a3858` | Companion movement/timer path; loads the field as `ecx` for `0x00506980`. |
| `0x005a5a90-0x005a5b79` `sub_5A5A90` | 3 | `0x005a5aa8`, `0x005a5ae9`, `0x005a5b46` | Warp/position reset helper; calls MapPane helpers `0x00505230`, `0x00505940`, and `0x00506980` through the field. |
| `0x005a76c0-0x005a82bd` [UID:0003VB] `UserPaneHandleServerMessage` | 5 | `0x005a79ef`, `0x005a7afa`, `0x005a8224`, `0x005a822f`, `0x005a8242` | UserPane server-message dispatcher; uses the field for MapPane recenter/object-update work and passes `field+0xa4` to TimerMgr cleanup when the pointer is non-null. |
| `0x005a88d0-0x005a89c9` `sub_5A88D0` | 3 | `0x005a88e7`, `0x005a88fd`, `0x005a890d` | Screen-position/hit-bounds update; calls MapPane coordinate helpers `0x00505130`, `0x00505080`, and `0x00505100`. |
| `0x005aa480-0x005aa702` `sub_5AA480` | 2 | `0x005aa575`, `0x005aa584` | Player visual/settings packet; invalidates/redraws through BackPane/Pane-style calls on the same pointee when display settings change. |
| `0x005aac80-0x005aafe3` `sub_5AAC80` | 2 | `0x005aad6a`, `0x005aaedd` | Login/status/update packet path; calls `0x00506980` on the field after local status state updates. |
| `0x005aaff0-0x005ab084` `meth_0x5aaff0` | 1 | `0x005ab04c` | Raw movement-correction helper; calls a MapPane coordinate/update helper through the field. |
| `0x005ab090-0x005ab410` `sub_5AB090` | 13 | `0x005ab0ff`, `0x005ab157`, `0x005ab16e`, `0x005ab181`, `0x005ab1aa`, `0x005ab26a`, `0x005ab2a1`, `0x005ab2b7`, `0x005ab2ca`, `0x005ab387`, `0x005ab3be`, `0x005ab3d4`, `0x005ab3e7` | Movement correction packet path; repeatedly calls MapPane gate/recenter/object-update helpers and TimerMgr cleanup via `field+0xa4`. |
| `0x005ab410-0x005ab75d` `sub_5AB410` | 11 | `0x005ab47f`, `0x005ab4c6`, `0x005ab4e2`, `0x005ab50b`, `0x005ab5d4`, `0x005ab604`, `0x005ab617`, `0x005ab6d4`, `0x005ab70b`, `0x005ab721`, `0x005ab734` | Second movement correction packet path; same MapPane helper and TimerMgr cleanup pattern as `0x005ab090`. |
| `0x005ab760-0x005ab802` `FUN_005ab760` | 2 | `0x005ab7ba`, `0x005ab7c9` | Visual/options update; calls `0x004b8e00` and then the pointee vtable slot `+0x20` for redraw/invalidation when `this+0x134100` changes. |
| `0x005ab810-0x005ab85f` `FUN_005ab810` | 1 | `0x005ab825` | Visual/movement reset helper; calls `0x00506980` through the field. |
| `0x005ac1b0-0x005ac27c` `meth_0x5ac1b0` | 3 | `0x005ac235`, `0x005ac240`, `0x005ac253` | Raw position-sync helper; uses MapPane recenter/object-update helpers and `field+0xa4` TimerMgr cleanup. |
| `0x005ac7e0-0x005ac99b` `meth_0x5ac7e0` | 1 | `0x005ac802` | Waypoint/path packet path; calls a MapPane movement gate/helper through the field. |
| `0x005ac9a0-0x005acad5` `meth_0x5ac9a0` | 1 | `0x005ac9cf` | Facing packet path; calls a MapPane movement gate/helper through the field. |
| `0x005ad360-0x005ad441` `sub_5AD360` | 1 | `0x005ad380` | Attack-target packet path; calls a MapPane coordinate/helper through the field. |
| `0x005b83a0-0x005b83a7` [UID:00024A] | 1 | `0x005b83a0` | The virtual accessor returns the same field. |

### Decisive Constructor Evidence

The constructor has two duplicate initialization arms. Both use the same pattern:

```asm
0x005a277b  mov dword ptr [ebx + 0x1340f8], 0
0x005a2785  mov eax, dword ptr [0x67a764]      ; g_activeMapPane
0x005a278e  test eax, eax
0x005a2790  je 0x005a279e
0x005a2792  mov dword ptr [ebx + 0x1340f8], eax
0x005a2798  mov dword ptr [eax + 0x418], ebx
...
0x005a27e7  mov ecx, dword ptr [ebx + 0x1340f8]
0x005a27f4  test ecx, ecx
0x005a27f6  je 0x005a2833
0x005a27fc  call 0x00505350
```

```asm
0x005a2a85  mov dword ptr [ebx + 0x1340f8], 0
0x005a2a8f  mov eax, dword ptr [0x67a764]      ; g_activeMapPane
0x005a2a98  test eax, eax
0x005a2a9a  je 0x005a2aa8
0x005a2a9c  mov dword ptr [ebx + 0x1340f8], eax
0x005a2aa2  mov dword ptr [eax + 0x418], ebx
...
0x005a2ae8  mov ecx, dword ptr [ebx + 0x1340f8]
0x005a2af5  test ecx, ecx
0x005a2af7  je 0x005a2b34
0x005a2afd  call 0x00505350
```

This is the key source-quality closure. `0x0067a764` is already documented by [UID:0000PR] and [UID:0001OW] as `g_activeMapPane`. The constructor copies that pointer into `UserPane + 0x1340f8`, then writes the current `UserPane`/local-player object pointer back to `MapPane + 0x418`. [UID:00007Q] already documents `MapPane + 0x418` as `m_activeObjectPane` / `m_localPlayerObjectPane`, and [UID:0002QM] uses the same field in active-player recentering. The source-facing field at `UserPane + 0x1340f8` is therefore a nullable cached `MapPane *`, not an integer or flags field.

### Representative Consumer Evidence

The dispatcher tail at `0x005a8218-0x005a8250` demonstrates typical use:

```asm
0x005a8224  mov ecx, dword ptr [ebx + 0x1340f8]
0x005a822a  call 0x005059d0       ; MapPane::RecenterAndSendPosition
0x005a822f  mov ecx, dword ptr [ebx + 0x1340f8]
0x005a8236  call 0x00506980       ; MapPane object/coordinate update helper
0x005a823d  call 0x0053c1d0       ; LivingObjectPane helper on the local object
0x005a8242  mov ecx, dword ptr [ebx + 0x1340f8]
0x005a8248  lea eax, [ecx + 0xa4]
```

The visual-options path at `0x005ab7ba-0x005ab7d6` also treats the pointee as a Pane/MapPane object:

```asm
0x005ab7ba  mov ecx, dword ptr [edi + 0x1340f8]
0x005ab7c4  call 0x004b8e00
0x005ab7c9  mov ecx, dword ptr [edi + 0x1340f8]
0x005ab7d3  mov eax, dword ptr [ecx]
```

The field is passed as a `this` pointer, dereferenced for known MapPane fields, and used for a virtual invalidation/redraw call. These uses cannot be reconciled with a scalar `dword`, simple state flag, object id, or callback cookie.

## Heuristic / Inference Reanalysis And Validation

### Field Type And Name

- Existing claim checked: current target, UserPane class page, UserPane file page, UserPane memory aggregate, and coverage row all describe the field as a dword at `this+0x1340f8` with unresolved semantics.
- Validation result: the raw address and field offset are correct, but the `dword` wording is stale as source-quality documentation. The constructor stores `g_activeMapPane` into the field, writes `this` to `MapPane+0x418`, and every meaningful consumer passes the field as a MapPane/Pane-style `this` pointer.
- Best inferred type: `MapPane *`.
- Best inferred member name: `m_mapPane`.
- Acceptable alternate spelling: `m_activeMapPane`.
- Rejected name: `field_1340F8`, because the role is no longer unknown.
- Rejected name: `m_activeObjectPane`, because that name belongs to `MapPane + 0x418`, the back-pointer written by the constructor; using it for `UserPane + 0x1340f8` would invert the relationship.
- Rejected name: `g_activeMapPane`, because this is not global storage. It is a per-UserPane cached copy/alias of the active map pane pointer.
- Remaining uncertainty: original spelling is not symbol-proof. `m_mapPane` is recommended as a high-probability descriptive member name because it is shorter, avoids collision with the global name, and matches the member's usage in ordinary source.

### Virtual Method Name And Signature

- Existing claim checked: target title `UserPaneVirtualDword1340F8Accessor` and behavior text use a generated placeholder.
- Best inferred method name: `GetMapPane`.
- Best inferred source-facing signature: `MapPane *UserPane::GetMapPane()`.
- Header/declaration shape if represented: `virtual MapPane *GetMapPane();`.
- I do not recommend adding `const` to the signature. A const accessor would be plausible in modern C++, but the binary gives no source-level const proof, and the surrounding mid-2000s codebase generally uses non-const simple accessors/virtuals in recovered source shape.
- Rejected method name: `GetActiveObjectPane`, because the returned object is the MapPane, not the active object pane; the active object pointer is `MapPane+0x418`.
- Rejected method name: `GetLocalPlayerObjectPane`, because the method returns the map pane pointer stored on UserPane, not the local-player object pointer stored on MapPane.
- Rejected method name: `GetMapTimerHandler`, because `field+0xa4` is only a MapPane subobject/facet passed to TimerMgr in some consumers. The field itself is the enclosing MapPane pointer.
- Remaining uncertainty: no direct virtual-call site names the slot, so `GetMapPane` is descriptive. It is still strong enough for final C++ because the method body and return type are exact.

### Pointer/State/Flags/Object-Handle/Callback Decision

- Pointer: accepted. Constructor stores `g_activeMapPane`, consumers load it into `ecx`, calls use it as `this`, code reads MapPane fields, and visual paths dereference the vtable.
- State scalar or flags: rejected. The value is not masked, shifted, enumerated, or compared as a scalar state. It is dereferenced and used as an object receiver.
- Object id/handle: rejected. It is not passed to lookup functions as an id; it is directly used as a pointer and has field accesses at MapPane offsets.
- Callback context: rejected. Some paths pass `field+0xa4` to TimerMgr, but that is a subobject inside MapPane. Other paths call MapPane coordinate and object-update methods directly.
- Embedded object: rejected. The constructor copies an external global pointer into the slot and null-checks it; an embedded object would not be initialized by storing `g_activeMapPane`.
- Module static state: rejected. Storage is per object at `this+0x1340f8`, not the global `0x0067a764`.

### Lifetime And Ownership

- The slot is one 32-bit pointer field at `UserPane + 0x1340f8`.
- The field is nullable and initialized to zero before being populated.
- The constructor conditionally copies [UID:0000PR]/[UID:0001OW] `g_activeMapPane` into the field.
- The constructor writes the inverse relationship `MapPane+0x418 = this`, matching documented MapPane active/local object pointer usage.
- The scalar destructor range `0x005b8230-0x005b8395` has no `+0x1340f8` operand in the displacement scan. The field is not owned/freed by UserPane, and no destructor reset/free pattern is evidenced among the 68 uses; MapPane lifecycle is handled by MapPane constructor/destructor and `g_activeMapPane` storage.
- Source declaration should be a class member on `UserPane`, not a global, not a child object with ownership semantics, and not a standalone helper state.

### Owner/Emitter/Source Placement

- Current owner/emitter [UID:0000P1] is acceptable as a broad file route but not the narrowest semantic owner under current by-structure rules.
- Best direct owner: [UID:0000FQ] `UserPane` class. The target is a UserPane vtable slot method, and recent accepted UserPane method page [UID:0003VB] already uses `CANONICAL_OWNER:0000FQ` and `EMITTER_UIDS:0000FQ`.
- Best emitter: [UID:0000FQ] `UserPane`, because the class page already emits through [UID:0000P1] `UserPane.cpp`.
- Source file: [UID:0000P1] `NexusTK/ui/panels/UserPane.cpp`.
- Rejected direct owner [UID:0000P1] as final owner: too broad for a class virtual method now that [UID:0000FQ] clears the ownership/emission gate.
- Rejected MapPane owner: the returned pointer is a MapPane, but the function body is a UserPane method and the only vtable xref is in UserPane vtable data.
- Rejected LivingObjectPane owner: many consumers are local-player/LivingObjectPane movement helpers, but the accessor itself is in the UserPane vtable and the constructor stores the member during UserPane construction. LivingObjectPane remains an important consumer/source-family overlap, not the direct owner of this virtual accessor.
- Rejected UserStatusPane owner: padding separates the function from UserStatusPane; the vtable slot is UserPane; the next function at `0x005b83b0` starts UserStatusPane.
- Rejected UserLookPane/SelfLookPane/Chatting/SayInputPanes owners: no constructor store, vtable data, or direct method evidence ties this accessor to those classes/modules. They are neighboring or consumer families only.

### Vtable Slot Role

- `0x0062ef28` is inside [UID:0002YU] UserPane vtable data and points to `0x005b83a0`.
- The slot is a virtual getter-style method: no static callers, no side effects, no arguments besides `this`, and a single pointer return from a stable member offset.
- Neighboring slots are UserPane virtual methods, not arbitrary free functions or compiler thunks. The slot should be named rather than left as `sub_5B83A0`.

### Generated-Name Rejection

- `sub_5B83A0`: rejected for source-facing documentation because the body and vtable route are exact.
- `UserPaneVirtualDword1340F8Accessor`: useful as stale search history only. It should not be the current filename/title because `dword` and raw offset are no longer the best source-level description.
- `dword_67A764`: use only as legacy alias/search term for [UID:0000PR] `g_activeMapPane`.
- `field_1340F8`: rejected for emitted C++ because the field has a strong descriptive type/name.

### Score And C++ Impact

- The source-quality blocker that capped completion is resolved: field type, field role, method name, owner route, and first-draft C++ are now defensible.
- The target should not exceed final-audit scores because original spelling is not proven and many surrounding UserPane/local-player handlers remain under active reconstruction. Recommended `89/92` is strong but below the `95+` final-audit barrier.
- Formal C++ should be populated. The body is exact, range-local, and does not require speculative behavior beyond the recommended member name/type.

## Open Questions Resolved Or Remaining

- Resolved: `this+0x1340f8` is a nullable cached `MapPane *`, copied from `g_activeMapPane`, not an unknown dword.
- Resolved: the virtual accessor should be source-facing `GetMapPane`, not a raw offset accessor.
- Resolved: the field should be documented as `MapPane *m_mapPane` at `UserPane + 0x1340f8`.
- Resolved: source placement is `UserPane` class under `NexusTK/ui/panels/UserPane.cpp`; the method is not MapPane-owned, UserStatusPane-owned, or a LivingObjectPane standalone helper.
- Resolved: all 68 known displacement users were grouped and checked for role inference.
- Remaining: exact original source spelling is not proven. This should not block target C++ because the descriptive name/type are high-probability and the body is exact. It does justify keeping confidence below final-audit level.
- Remaining support-level issue: [UID:0000FQ] still says class C++ is blank because of an old `95/95` code-emission bar. That statement is stale under current Supervisor Rule 20. The class can remain blank if its full declaration is not ready, but the reason should be "full class declaration/large handler source shape remains incomplete," not the obsolete gate.

## First-Draft C++ Recommendation

Populate [UID:00024A]'s formal `RECONSTRUCTION_CPP CODE` block with this exact body after applying the metadata/name changes:

```cpp
MapPane *UserPane::GetMapPane()
{
    return m_mapPane;
}
```

Recommended supporting class declaration/member names when the class layout is updated:

```cpp
class UserPane
{
public:
    virtual MapPane *GetMapPane();

private:
    MapPane *m_mapPane; // +0x1340f8
};
```

Do not include constructor, MapPane back-pointer setup, or any consumer helper logic in [UID:00024A]'s C++ block. This by-memory page covers only the seven-byte accessor.

## Exact Supervisor Changes Required

### [UID:00024A] Target Page

Recommended rename:

- From: `by-memory/0x005b83a0-0x005b83a7.UserPaneVirtualDword1340F8Accessor.md`
- To: `by-memory/0x005b83a0-0x005b83a7.UserPaneGetMapPane.md`

Recommended metadata:

```text
*** UID:00024A | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:89 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000FQ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000FQ | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Recommended title replacement:

```markdown
# 0x005b83a0-0x005b83a7 UserPane GetMapPane
```

Recommended replacement for the current `## Behavior` section:

```markdown
## Behavior

This is a seven-byte `UserPane` virtual accessor for the cached active map pane pointer. It returns the `MapPane *` stored at `this + 0x1340f8`, recommended source member `m_mapPane`, and has no side effects.

The source-facing method name should be `UserPane::GetMapPane`. The field is no longer an unresolved dword: the UserPane constructor zeroes the slot, copies [UID:0000PR] `g_activeMapPane` / [UID:0001OW] storage `0x0067a764` into it when the active map pane exists, and writes the inverse relationship `MapPane + 0x418 = this`. Existing MapPane support docs identify `MapPane + 0x418` as the active/local object pane pointer.
```

Recommended insertion in the target `## Evidence` section after the exact bytes/vtable facts:

```markdown
- A 2026-06-18 B001 read-only Capstone scan over `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe` found exactly 68 instruction operands using displacement `0x1340f8` across the UserPane/local-player neighborhood. The constructor contributes six of those operands and proves the field source: it writes zero at `0x005a277b` / `0x005a2a85`, loads `g_activeMapPane` from `0x0067a764` at `0x005a2785` / `0x005a2a8f`, stores that pointer into `this+0x1340f8` at `0x005a2792` / `0x005a2a9c`, and writes `this` to `MapPane+0x418` at `0x005a2798` / `0x005a2aa2`.
- Representative consumer paths load `this+0x1340f8` into `ecx` and call MapPane helpers, including `0x005059d0` at `0x005a822a`, `0x00506980` at `0x005a8236`, and multiple coordinate helpers in `0x005a2e00`, `0x005a5a90`, and `0x005a88d0`. Visual/options helpers also dereference the pointee vtable after loading the field, proving object-pointer semantics.
- The field is a nullable borrowed/cached `MapPane *`; UserPane does not own or delete it. MapPane lifecycle remains documented under [UID:0000L3] / [UID:00007Q], and the active singleton storage remains [UID:0000PR] / [UID:0001OW].
```

Recommended replacement for the current `## Reconstruction Notes` section:

````markdown
## Reconstruction Notes

Emit this as a tiny virtual `UserPane` method in `NexusTK/ui/panels/UserPane.cpp` through the [UID:0000FQ] class route:

```cpp
MapPane *UserPane::GetMapPane()
{
    return m_mapPane;
}
```

The recommended member declaration is `MapPane *m_mapPane;` at `UserPane + 0x1340f8`. Keep `field_1340F8`, `dword`, and `sub_5B83A0` only as historical/search aliases, not source-facing names.
````

Recommended replacement for the score rationale:

```markdown
## Score Rationale

`COMPLETION:89` reflects exact range, bytes, disassembly, padding boundaries, sole UserPane vtable slot, all 68 known `+0x1340f8` operand users grouped, constructor proof that the field is copied from `g_activeMapPane`, consumer proof that it is used as a MapPane receiver, resolved source-facing field/method names, corrected class owner/emitter route, and formal first-draft C++ readiness.

`CONFIDENCE:92` is justified for boundary, behavior, type, and owner because independent evidence from vtable data, constructor writes, MapPane support fields, and consumer call patterns all agree. Confidence stays below final-audit level because the exact original source spelling of `m_mapPane` / `GetMapPane` is inferred rather than recovered from symbols.
```

### [UID:0000FQ] `by-class/UserPane.md`

Replace method-table row:

```markdown
| virtual dword `+0x1340f8` accessor | `0x005b83a0-0x005b83a7` | Tiny vtable accessor returning `this+0x1340f8`; semantic field name still provisional. |
```

with:

```markdown
| `GetMapPane` virtual accessor | `0x005b83a0-0x005b83a7` | Tiny vtable accessor returning `MapPane *m_mapPane` at `this+0x1340f8`; B001 2026-06-18 operand scan resolves the field from constructor copies of `g_activeMapPane` and MapPane-helper consumers. |
```

Replace constructor setup bullet text that ends with "`0x005a277b` initializes the `+0x1340f8` accessor field to zero." with:

```markdown
- Constructor setup: `0x005a2587` stores `this` into [UID:0000QK] `g_pCollectionData` / `dword_67A748`; `0x005a25b7`, `0x005a25bd`, and `0x005a25c7` install the three `UserPane` vtables; `0x005a2598-0x005a25d1` vector-constructs 128 records of size `0x2604`; `0x005a277b` / `0x005a2a85` zero the cached map-pane member, `0x005a2785` / `0x005a2a8f` load [UID:0000PR] `g_activeMapPane`, `0x005a2792` / `0x005a2a9c` store it into `MapPane *m_mapPane` at `+0x1340f8`, and `0x005a2798` / `0x005a2aa2` write the inverse `MapPane+0x418 = this` active/local object pointer.
```

Recommended status/reconstruction wording replacement for the obsolete `95/95` gate sentence:

```markdown
- Reconstruction status: reconstructable under [UID:0000P1] `UserPane.cpp`; class-level declaration C++ remains blank until the large handler/member layout is coherent enough, but exact child methods such as [UID:00024A] may emit through this class when they meet the active combined-score/emitter gate.
```

No mandatory score change for [UID:0000FQ] is required. If the supervisor wants to reflect the resolved field, a conservative support score change from `86/86` to `87/87` is defensible, but this report does not require it.

### [UID:0000P1] `by-file/UserPane.md`

Replace proposed-contents row:

```markdown
| [UID:00024A][0x005b83a0-0x005b83a7.UserPaneVirtualDword1340F8Accessor](by-memory/0x005b83a0-0x005b83a7.UserPaneVirtualDword1340F8Accessor.md) | `0x005b83a0-0x005b83a7` | Tiny `UserPane` vtable accessor for the dword at `this + 0x1340f8`; field semantics remain unresolved. |
```

with:

```markdown
| [UID:00024A] `UserPaneGetMapPane` | `0x005b83a0-0x005b83a7` | Tiny `UserPane` vtable accessor `MapPane *UserPane::GetMapPane()` returning cached member `m_mapPane` at `this + 0x1340f8`; B001 2026-06-18 resolved the field from constructor copies of `g_activeMapPane`, the `MapPane+0x418` back-pointer write, and 68 displacement-user contexts. |
```

Replace source-boundary bullet:

```markdown
- IDA MCP on 2026-05-28 confirms the adjacent `0x005b83a0-0x005b83a7` function is a `UserPane` vtable accessor, not part of `UserStatusPane`; keep it with `UserPane.cpp` unless later field semantics tie it to a narrower helper.
```

with:

```markdown
- IDA MCP on 2026-05-28 confirms the adjacent `0x005b83a0-0x005b83a7` function is a `UserPane` vtable accessor, not part of `UserStatusPane`; B001 2026-06-18 resolves it as `MapPane *UserPane::GetMapPane()`, returning cached member `m_mapPane` copied from `g_activeMapPane`, so it should stay with the `UserPane` class in `UserPane.cpp`.
```

No file score change is required; [UID:0000P1] can remain `89/85`.

### [UID:0001KL] `by-memory/0x005a2530-0x005b8395.UserPane.md`

Replace child-summary row:

```markdown
| `0x005b83a0-0x005b83a7` | [UID:00024A][0x005b83a0-0x005b83a7.UserPaneVirtualDword1340F8Accessor](by-memory/0x005b83a0-0x005b83a7.UserPaneVirtualDword1340F8Accessor.md) | Adjacent `UserPane` vtable accessor returning the dword at `this + 0x1340f8`; separated from this page by `0xcc` alignment at `0x005b8395-0x005b83a0`. |
```

with:

```markdown
| `0x005b83a0-0x005b83a7` | [UID:00024A] `UserPaneGetMapPane` | Adjacent `UserPane` vtable accessor returning cached `MapPane *m_mapPane` at `this + 0x1340f8`; separated from this page by `0xcc` alignment at `0x005b8395-0x005b83a0`. |
```

Replace evidence bullet:

```markdown
- IDA MCP on 2026-05-28 confirms the adjacent function at `0x005b83a0-0x005b83a7` is a `UserPane` vtable accessor (`mov eax, [ecx+0x1340f8]; retn`) rather than padding or `UserStatusPane` code.
```

with:

```markdown
- IDA MCP on 2026-05-28 confirms the adjacent function at `0x005b83a0-0x005b83a7` is a `UserPane` vtable accessor (`mov eax, [ecx+0x1340f8]; retn`) rather than padding or `UserStatusPane` code. B001 2026-06-18 resolves the returned field as `MapPane *m_mapPane`: the constructor copies [UID:0000PR] `g_activeMapPane` from `0x0067a764` into `+0x1340f8` and writes the inverse `MapPane+0x418 = this` active/local object pointer.
```

No score change is required for [UID:0001KL].

### [UID:0002YU] `by-memory/0x0062ef0c-0x0062efcc.UserPaneVtableData.md`

Replace representative slot wording:

```markdown
`0x0062ef28 -> 0x005b83a0`
```

with:

```markdown
`0x0062ef28 -> 0x005b83a0` (`UserPane::GetMapPane`, returns `MapPane *m_mapPane`)
```

No score change is required.

### MapPane / ActiveMapPane Support

Recommended insertion in [UID:00007Q] `by-class/MapPane.md` field glossary row for `+0x418`:

```markdown
B001 2026-06-18 confirms the UserPane constructor stores the active `MapPane *` in `UserPane::m_mapPane` at `+0x1340f8` and writes `this` back to `MapPane+0x418`, strengthening the `m_activeObjectPane` / `m_localPlayerObjectPane` interpretation.
```

Recommended insertion in [UID:0000PR] `by-global/g_activeMapPane.md` and [UID:0001OW] `ActiveMapPaneSingleton` evidence:

```markdown
- B001 2026-06-18 confirms `UserPane` constructor arms at `0x005a2785` and `0x005a2a8f` read this singleton, copy it into `UserPane::m_mapPane` at `this+0x1340f8`, and write the inverse `MapPane+0x418 = this` local-player/active-object pointer.
```

No score changes are required for these support pages.

## Coverage Report Replacement Text

Do not edit `by-memory/-coverage-report.md` directly from B001. Supervisor should apply this row replacement after renaming [UID:00024A].

Placement context: replace the existing [UID:00024A] row immediately after the padding row for `0x005b8395-0x005b83a0` and before the padding/UserStatusPane rows.

Replace current row:

```markdown
    - [UID:00024A][0x005b83a0-0x005b83a7.UserPaneVirtualDword1340F8Accessor](by-memory/0x005b83a0-0x005b83a7.UserPaneVirtualDword1340F8Accessor.md) 0x005b83a0-0x005b83a7 | class method | UserPaneVirtualDword1340F8Accessor : reconstructable : 82% : strong : Tiny `UserPane` vtable accessor returning `this+0x1340f8`, with live IDA-confirmed seven-byte body, sole vtable xref at `0x0062ef28`, no static callers/callees, padding-separated `UserPane`/`UserStatusPane` boundaries, field-offset operand context, parent `UserPane`, and final field-name caveat.
```

with:

```markdown
    - [UID:00024A][0x005b83a0-0x005b83a7.UserPaneGetMapPane](by-memory/0x005b83a0-0x005b83a7.UserPaneGetMapPane.md) 0x005b83a0-0x005b83a7 | virtual accessor | UserPaneGetMapPane : reconstructable : 89% : very strong : Tiny `UserPane` virtual `MapPane *UserPane::GetMapPane()` returning cached `MapPane *m_mapPane` at `this+0x1340f8`; B001 2026-06-18 reanalysis confirms exact seven-byte body `8B 81 F8 40 13 00 C3`, sole UserPane vtable xref at `0x0062ef28`, no static callers/callees, padding-separated UserPane/UserStatusPane boundaries, constructor copies from [UID:0000PR] `g_activeMapPane` at `0x0067a764`, inverse `MapPane+0x418 = this` local-player/active-object write, all 68 known displacement users grouped across movement/server-message/packet/update paths, corrected class owner/emitter [UID:0000FQ], and formal first-draft C++ populated.
```

If the supervisor chooses not to rename the file immediately, keep the old path in the row but still replace the item name, description, score, and field-type evidence. The rename is recommended because the old filename preserves a stale generated `dword` claim.

## Validator Results

- No by-* documentation, generated report/source, IDA DB, or `by-memory/-coverage-report.md` file was edited by B001.
- No validator run was required for this report-only research file.
- Files created by B001: `E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\Agent-B001\research\00024A-UserPaneVirtualDword1340F8Accessor-source-quality.md`.

## Final Disposition

[UID:00024A] is eligible for formal C++ now. The only remaining uncertainty is original spelling, and the recommended descriptive names are strongly supported by constructor and consumer evidence. The stale `dword` blocker should be removed from the target and support docs, the owner/emitter should move to [UID:0000FQ], and the coverage row should be refreshed with the `UserPaneGetMapPane` name and `89/92` target state.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B001","command_id":"000000004165","destination_path":"executed-b-agent-research/B001/00024A-UserPaneVirtualDword1340F8Accessor-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:20","uid":"00024A"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
