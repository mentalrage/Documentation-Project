** TARGET-REPORT-UID:0002VM **
** AUTHOR-AGENT-ID:B003 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# B003 Source-Quality Research: 0002VM CreateUserPaneDoubleParamCallback

## Assignment

- Agent: B003
- UID: 0002VM
- Target: `source-3/project-documentation/by-memory/0x005b7450-0x005b74dd.CreateUserPaneDoubleParamCallback.md`
- Required report: `source-3/project-documentation/tools/leaser/Agents/Agent-B003/research/0002VM-CreateUserPaneDoubleParamCallback-source-quality.md`
- Scope: report-only source-quality / heuristic research. No target, support, generated C++, or coverage files were edited.

## Short Recommendation

Keep [UID:0002VM] as a reconstructable executable helper owned and emitted by [UID:000040], the concrete `DoubleParamMemberFunctionObject0` instantiation for `UserPane` item-action confirmation callbacks. The current no-C++ reason is stale: the doc cites an old 95/95 gate, while current rules allow code entry when the route is valid and average score exceeds 85. This item has a valid owner/emitter route, exact helper boundary, exact caller set, exact field stores, exact invoke wrapper, and source-quality names for the remaining raw helpers.

Primary implementation recommendation:

- `COMPLETION: 87`
- `CONFIDENCE: 91`
- `RECONSTRUCTABLE: TRUE`
- `CANONICAL_OWNER: 000040`
- `EMITTER_UIDS: 000040`
- Add first-draft C++ to the target doc as a concrete callback factory helper.

Fallback if the supervisor applies a strict "generated template helper stays no-code" policy:

- Keep the target formal C++ blank or replace it with a one-line no-code/generated-binary marker.
- Move the C++ declaration shape into [UID:000040], [UID:0000JO], and [UID:0001WQ].
- Do not use this fallback unless the policy is explicit. The executable range is not just vtable glue or a thunk; it is a four-caller allocation/configuration helper with a stable source route.

## Evidence Checked

Documentation checked:

- Target doc: `by-memory/0x005b7450-0x005b74dd.CreateUserPaneDoubleParamCallback.md`
- Class owner: `by-class/DoubleParamMemberFunctionObject0_void____thiscall_UserPane_____signed_char__h43ff6c8e0528.md` [UID:000040]
- Invoke wrapper: `by-memory/0x005b77b0-0x005b77c8.UserPaneDoubleParamCallback.md` [UID:0001N5]
- Confirm pane constructor: `by-memory/0x005b75d0-0x005b760e.ConfirmInputPaneConstructor.md` [UID:0001N4]
- Confirm accepted-action dispatch: `by-memory/0x004f2a10-0x004f2a58.ConfirmInputPaneInvokeAcceptedAction.md` [UID:000366]
- Vtable data: `by-memory/0x00630a78-0x00630a90.UserPaneDoubleParamCallbackVtableData.md` [UID:0002YW]
- Function-object file/template docs: `by-file/FunctionObjects.md` [UID:0000JO], `by-type/by-template/FunctionObjectTemplates.md` [UID:0001WQ]
- UserPane docs: `by-file/UserPane.md` [UID:0000P1], `by-class/UserPane.md` [UID:0000FQ]
- Global pointer doc: `by-global/g_pCollectionData.md` [UID:0000QK]
- Caller/support docs: DropAllInputPane [UID:000042], DropInputPane [UID:000044], GiveAllInputPane [UID:00005S], GiveInputPane [UID:00005U], DropGiveInputPanes aggregate [UID:0001MG], InputPanes file [UID:0000K7]
- Helper docs: `OperatorNewWrapper` [UID:000196], `LObjectConstructor` [UID:00036Z], `LObjectRuntimeClassAccessor` [UID:000371], `LObjectDefaultNoOpVirtual` [UID:0000WM], callback object-size helper [UID:00032C], callback scalar destructor variant [UID:000327]

Binary evidence checked directly against `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`:

- `0x005b7450-0x005b74dd` disassembly
- `0x005b77b0-0x005b77c8` disassembly
- `0x005ad720` and `0x005ad7a0` disassembly
- `.rdata` dwords around `0x00630a78`
- absolute references to `0x00630a78`, `0x0067a748`, `0x005ad720`, and `0x005ad7a0`
- rel32 callers of `0x005b7450`, `0x005b75d0`, `0x005b77b0`, `0x005ad720`, and `0x005ad7a0`

## Raw Findings

### Helper 0x005b7450

The helper is a `__cdecl` factory with five explicit arguments. Every caller adjusts the stack by `0x14`.

Observed behavior:

1. Allocates `0x18` bytes through `sub_4F4AA0`.
2. Returns null if allocation fails.
3. Calls `sub_4F4A80` as the `LObject` base constructor.
4. Installs vtable `0x00630a78`.
5. Stores:
   - `this + 0x08`: member callback pointer
   - `this + 0x0c`: this-adjustment dword
   - `this + 0x10`: target object pointer
   - `this + 0x14`: captured signed-char slot
   - `this + 0x15`: captured bool/all-items flag
6. Returns the configured callback object.

Best source-facing signature:

```cpp
typedef void (__thiscall UserPane::*UserPaneItemActionCallback)(signed char, bool);

DoubleParamMemberFunctionObject0<UserPaneItemActionCallback, UserPane, signed char, bool> *
__cdecl CreateUserPaneDoubleParamCallback(UserPaneItemActionCallback callback,
                                          int thisAdjust,
                                          UserPane *target,
                                          signed char slot,
                                          bool allItems);
```

The existing target name can remain as the stable documentation name, but the doc should clarify that `CreateUserPane...` means "create a UserPane callback object", not a `CreateUserPane` UI feature. For source-facing prose, `CreateUserPaneDoubleParamMemberCallback` is less ambiguous. I would not rename the markdown file unless the supervisor wants a broad rename pass.

### Allocation/Base Helpers

- `sub_4F4AA0` is not a blocker. It is already resolved project-wide as MemoryMan-backed global `operator new` [UID:000196].
- `sub_4F4A80` is not a blocker. It is `LObject::LObject` [UID:00036Z], writing vtable `0x0061cf68` and returning `this`.

Recommended target wording should use those names and link the helper docs.

### Vtable 0x00630a78

The vtable is the concrete vftable for the UserPane slot/bool callback object. The decorated name in [UID:0002YW] is:

```text
??_7?$DoubleParamMemberFunctionObject0@P8UserPane@@AEXC_N@ZV1@C_N@@6B@
```

The raw layout is:

| Address | Value | Recommended role |
| --- | --- | --- |
| `0x00630a78` | `0x004671f0` | 24-byte callback scalar-deleting destructor variant |
| `0x00630a7c` | `0x004f4b10` | inherited `LObject::GetRuntimeClass`-style accessor |
| `0x00630a80` | `0x0041b6c0` | inherited `LObject` no-op virtual |
| `0x00630a84` | `0x005b77b0` | invoke wrapper [UID:0001N5] |
| `0x00630a88` | `0x004673f0` | object-size virtual, returns `0x18` |
| `0x00630a8c` | `0x00000000` | trailing null/alignment before the UTF-16 prompt at `0x00630a90`, not another virtual slot |

Only one code reference writes this vtable: `0x005b7497` inside [UID:0002VM]. The invoke wrapper is referenced through the vtable slot only.

### Invoke Wrapper 0x005b77b0

[UID:0001N5] is the virtual call target for the object built by [UID:0002VM]. It:

1. Loads the callback object from `ecx`.
2. Computes the adjusted target object as `*(this + 0x10) + *(this + 0x0c)`.
3. Pushes `*(this + 0x15)` as the bool/all-items parameter.
4. Pushes `*(this + 0x14)` as the signed-char slot.
5. Calls the member callback pointer at `*(this + 0x08)`.

Recommended field names for both [UID:0002VM] and [UID:0001N5]:

- `m_callback`
- `m_thisAdjust`
- `m_target`
- `m_slot`
- `m_allItems`

The wrapper is not a generic unknown thunk; it is the concrete `DoubleParamMemberFunctionObject0<UserPaneItemActionCallback, UserPane, signed char, bool>::Invoke` body for this instantiation.

### Member Callback Methods

`sub_5AD7A0` and `sub_5AD720` are not passive blockers. Both are UserPane-bound packet helper methods used as member function pointers, although neither body reads `ecx`.

`sub_5AD7A0`:

- Best source-facing name: `UserPane::SendDropItemPacket(signed char slot, bool allItems)`
- IDA-safe label: `UserPane_SendDropItemPacket`
- Packet layout:
  - byte 0: opcode `0x08`
  - byte 1: slot
  - byte 2: bool/all-items mode
  - byte 3: zero terminator/local buffer padding
- Sends exactly 3 bytes through the packet sender global at `dword_67A7EC`.
- Used by DropAll and Drop confirmation construction sites.

`sub_5AD720`:

- Best source-facing name: `UserPane::SendGiveItemPacket(signed char slot, bool allItems)`
- IDA-safe label: `UserPane_SendGiveItemPacket`
- Packet layout:
  - byte 0: opcode `0x29`
  - byte 1: slot
  - byte 2: bool/all-items mode
  - byte 3: zero terminator/local buffer padding
- Sends exactly 3 bytes through the same packet sender global.
- Used by GiveAll and Give confirmation construction sites.

These names align with the existing Drop/Give raw helper docs:

- opcode `0x08`, mode `1`: drop all
- opcode `0x08`, mode `0`: drop one
- opcode `0x29`, mode `1`: give all
- opcode `0x29`, mode `0`: give one

The confirmation path reuses the same packet contract after the user accepts the ConfirmInputPane prompt.

### Global Target Object

`dword_67A748` is already documented as [UID:0000QK] `g_pCollectionData`, with UserPane constructor/destructor lifetime in [UID:0000FQ]. In this target, the source-facing typed role is the local `UserPane *` target captured into the callback object.

Recommended wording:

- Keep the project UID/name link as `g_pCollectionData` for continuity.
- Add a target-local alias/role such as `UserPane *g_pLocalUserPane` or "`g_pCollectionData` viewed as the active local UserPane pointer".
- Do not globally rename `dword_67A748` from this target alone. It has hundreds of references and broader naming needs should stay coordinated through [UID:0000QK].

### Caller Route and ConfirmInputPane Relationship

Direct rel32 callers of [UID:0002VM] are exactly four:

| Caller family | Call site | Callback | Target | Slot source | Bool | Confirm prompt |
| --- | ---: | --- | --- | --- | --- | --- |
| DropAllInputPane | `0x005b46d6` | `UserPane::SendDropItemPacket` | `dword_67A748` | selected slot local | `true` | literal at `0x00630a90` |
| DropInputPane | `0x005b4a05` | `UserPane::SendDropItemPacket` | `dword_67A748` | selected slot local | `false` | literal at `0x00630a90` |
| GiveAllInputPane | `0x005b4ec0` | `UserPane::SendGiveItemPacket` | `dword_67A748` | selected slot local | `true` | LanguageMan string id `0xdf` |
| GiveInputPane | `0x005b5198` | `UserPane::SendGiveItemPacket` | `dword_67A748` | selected slot local | `false` | LanguageMan string id `0xdf` |

Each caller immediately passes the returned object to [UID:0001N4] `ConfirmInputPaneConstructor`. [UID:0001N4] stores the action object at `ConfirmInputPane + 0x108`. [UID:000366] later checks for a one-character `y` or `Y` answer and invokes the stored action object's virtual slot `+0x0c`, which resolves to [UID:0001N5]. That wrapper then calls the captured UserPane packet method.

This route reconciles the four construction sites, [UID:0001N4], [UID:000366], [UID:0001N5], and the packet helper methods. It also proves [UID:0002VM] is not dead support code.

## Heuristic / Inference Reanalysis And Validation

### Ownership and Emitter

Best route:

```text
0002VM executable helper
  -> 000040 concrete DoubleParamMemberFunctionObject0<UserPane, signed char, bool> class
  -> 0000JO FunctionObjects file family
  -> auto-generated/NexusTK/util/FunctionObjects.cpp
```

Keep `CANONICAL_OWNER: 000040` and `EMITTER_UIDS: 000040`. The helper is configured by Drop/Give pane code and targets `UserPane`, but the object layout, vtable, scalar destructor, invoke wrapper, and object-size virtual belong to the concrete FunctionObjects instantiation. `InputPanes`/`ConfirmInputPane` consume the object; they do not own its type.

### Source Placement

Most likely source placements:

1. A template-generated concrete factory/new-expression emitted from FunctionObjects support. This best matches the existing owner/emitter route and the specialized vtable/invoke/object-size family.
2. A small hand-written helper near the Drop/Give pane construction sites that returns a FunctionObjects template object. This is possible because all callers are item-action panes, but weaker because the type/vtable route is already represented by [UID:000040].

Recommendation: keep the target emitted by [UID:000040] and document caller semantics in the Drop/Give pane support docs.

### Function-Object Template Name

Best reconstructed source type:

```cpp
typedef void (__thiscall UserPane::*UserPaneItemActionCallback)(signed char, bool);
typedef DoubleParamMemberFunctionObject0<UserPaneItemActionCallback, UserPane, signed char, bool>
    UserPaneItemActionCallbackObject;
```

The existing generated markdown filename uses a long compiler/decorator-derived name. Keep it as a stable doc filename, but in prose prefer:

- `DoubleParamMemberFunctionObject0<UserPaneItemActionCallback, UserPane, signed char, bool>`
- or `UserPaneItemActionCallbackObject` as a local typedef/alias.

Do not expose the full mangled/decorated class spelling as the only source-facing name.

### Generated-Binary Treatment

This is source-declared/generated-binary support, not anonymous compiler glue that must stay uncovered:

- It has an address range in executable code.
- It has four direct callers.
- It performs allocation, base construction, vtable installation, and field initialization.
- The invoke wrapper and vtable data are separately documented and route cleanly to [UID:000040].
- The active C++ gate is met after the recommended score update.

No-code proof is not strong enough to justify leaving the target blank. A no-code marker is only appropriate if the supervisor decides concrete template instantiation helpers must not receive formal C++ despite executable helper bodies.

### Range / Split / Merge

No split or merge is recommended for [UID:0002VM]. The range `0x005b7450-0x005b74dd` is a complete helper body including prologue/epilogue and local EH/security scaffolding. The nearby invoke wrapper [UID:0001N5], ConfirmInputPane constructor [UID:0001N4], vtable data [UID:0002YW], and packet methods should remain separate support docs.

### Negative Checks

- Not a `CreateUserPane` account/dialog feature. All direct callers are Drop/Give item-action confirmation construction sites.
- Not owned by ConfirmInputPane. ConfirmInputPane stores and invokes the action object but does not define its layout.
- Not owned directly by UserPane. UserPane supplies the target object and member callbacks; the callback-object type is FunctionObjects-owned.
- Not pure vtable/data glue. It is executable allocation/configuration code.
- Not blocked by `sub_4F4AA0`, `sub_4F4A80`, `sub_5AD7A0`, `sub_5AD720`, `dword_67A748`, or `0x00630a78`; all have best-supported names/roles above.

## First-Draft C++ Recommendation

Recommended target C++ body for [UID:0002VM]:

```cpp
typedef void (__thiscall UserPane::*UserPaneItemActionCallback)(signed char slot, bool allItems);

DoubleParamMemberFunctionObject0<UserPaneItemActionCallback, UserPane, signed char, bool> *
CreateUserPaneDoubleParamCallback(UserPaneItemActionCallback callback,
                                  int thisAdjust,
                                  UserPane *target,
                                  signed char slot,
                                  bool allItems)
{
    return new DoubleParamMemberFunctionObject0<UserPaneItemActionCallback, UserPane, signed char, bool>(
        callback,
        thisAdjust,
        target,
        slot,
        allItems);
}
```

Required note beside the C++:

```text
The concrete emitted helper stores the constructor arguments at callback-object offsets +0x08, +0x0c, +0x10, +0x14, and +0x15 after a MemoryMan-backed operator-new allocation and LObject base initialization. The exact original helper spelling is not symbol-proven; the body above is the source-equivalent factory shape.
```

If the local template declaration is added in support docs, use this constructor shape:

```cpp
template <class TMember, class TObject, class TBound0, class TBound1>
class DoubleParamMemberFunctionObject0 : public FunctionObject0
{
public:
    DoubleParamMemberFunctionObject0(TMember callback,
                                     int thisAdjust,
                                     TObject *target,
                                     TBound0 value0,
                                     TBound1 value1);

    virtual void Invoke();

private:
    TMember m_callback;
    int m_thisAdjust;
    TObject *m_target;
    TBound0 m_value0;
    TBound1 m_value1;
};
```

Do not overfit the final source with decompiler-shaped null-check scaffolding unless the project's FunctionObjects style requires it. The compiled body's allocation null branch is real, but a human C++ `new` expression is the better first draft.

## Recommended Exact Doc Changes

### Target [UID:0002VM]

Apply these content changes:

- Replace the stale "below 95/95 gate" C++-blocking language with the current gate analysis and first-draft C++ readiness.
- Add source-facing helper role:
  - "Concrete factory for a `DoubleParamMemberFunctionObject0<UserPaneItemActionCallback, UserPane, signed char, bool>` action object used by Drop/Give confirmation panes."
- Add helper name resolution:
  - `sub_4F4AA0` -> global `operator new` [UID:000196]
  - `sub_4F4A80` -> `LObject::LObject` [UID:00036Z]
  - `sub_5AD7A0` -> `UserPane::SendDropItemPacket(signed char,bool)`
  - `sub_5AD720` -> `UserPane::SendGiveItemPacket(signed char,bool)`
  - `dword_67A748` -> [UID:0000QK] `g_pCollectionData`, target-local role `UserPane *active/local UserPane`
  - `0x00630a78` -> vtable [UID:0002YW]
- Add the field layout table:
  - `+0x00` vtable `0x00630a78`
  - `+0x08` `m_callback`
  - `+0x0c` `m_thisAdjust`
  - `+0x10` `m_target`
  - `+0x14` `m_slot`
  - `+0x15` `m_allItems`
- Add caller table from the evidence above.
- Add the ConfirmInputPane dispatch route:
  - [UID:0001N4] stores returned action object at `+0x108`.
  - [UID:000366] invokes action virtual slot `+0x0c` only after `y`/`Y`.
  - [UID:0001N5] calls the captured member callback.
- Insert the first-draft C++ shown above.
- Recommended score/metadata: `87/91`, owner/emitter unchanged.

### Class Owner [UID:000040]

Recommended additions:

- Add local source alias:

```cpp
typedef void (__thiscall UserPane::*UserPaneItemActionCallback)(signed char, bool);
typedef DoubleParamMemberFunctionObject0<UserPaneItemActionCallback, UserPane, signed char, bool>
    UserPaneItemActionCallbackObject;
```

- Add field names `m_callback`, `m_thisAdjust`, `m_target`, `m_slot`, `m_allItems`.
- Add the exact relationship:
  - construction helper [UID:0002VM]
  - invoke wrapper [UID:0001N5]
  - vtable [UID:0002YW]
  - consumed by ConfirmInputPane [UID:0001N4]/[UID:000366]
- Replace "full template declaration remains below 95/95" with "exact original template header spelling remains open, but this concrete instantiation is source-quality ready."
- Recommended score after update: `87/90`.

### Invoke Wrapper [UID:0001N5]

Recommended additions:

- Rename field prose to match [UID:0002VM]:
  - `m_callback`, `m_thisAdjust`, `m_target`, `m_slot`, `m_allItems`
- State that `m_callback` is one of:
  - `UserPane::SendDropItemPacket(signed char,bool)`
  - `UserPane::SendGiveItemPacket(signed char,bool)`
- Add the exact dispatch expression:

```cpp
(adjustedTarget->*m_callback)(m_slot, m_allItems);
```

- Recommended score after update: `86/91`.

### Vtable Data [UID:0002YW]

Recommended additions:

- Keep decorated name as binary evidence.
- Add the slot table from this report.
- Clarify that `0x00630a8c` is trailing null/alignment before the prompt string at `0x00630a90`, not a virtual slot.
- No owner/emitter change.

### FunctionObjects File [UID:0000JO] and Template Docs [UID:0001WQ]

Recommended additions:

- Document that [UID:0002VM] is a concrete out-of-line factory/new helper for the `UserPaneItemActionCallbackObject` instantiation.
- Add the source alias and field layout.
- Record that `sub_5AD7A0`/`sub_5AD720` are now resolved behaviorally as UserPane drop/give packet send callbacks.
- Preserve the current caution that exact original template header spelling is not symbol-proven.

### UserPane File/Class and Global Pointer Docs

Recommended additions:

- In [UID:0000P1] and [UID:0000FQ], add the two member callback methods:
  - `UserPane::SendDropItemPacket(signed char slot, bool allItems)` at `0x005ad7a0`
  - `UserPane::SendGiveItemPacket(signed char slot, bool allItems)` at `0x005ad720`
- Mention that these methods are bound into FunctionObjects callback objects for Drop/Give confirmation panes. The bodies currently use packet-sender globals and do not read `ecx`, but their member-function-pointer type and construction sites bind them as UserPane callbacks.
- In [UID:0000QK], add a cross-reference note that [UID:0002VM] captures `g_pCollectionData` as the active local `UserPane *` target.

### Drop/Give Input Pane Docs

Recommended additions for [UID:000042], [UID:000044], [UID:00005S], [UID:00005U], and aggregate [UID:0001MG]:

- Add [UID:0002VM] as the confirmation action-object factory.
- Name the callback methods:
  - DropAll/Drop -> `UserPane::SendDropItemPacket`
  - GiveAll/Give -> `UserPane::SendGiveItemPacket`
- Add the captured bool meanings:
  - `true`: all-items mode
  - `false`: single-item mode
- Add the route through [UID:0001N4] and [UID:000366] before packet emission.

### ConfirmInputPane Docs

Recommended additions for [UID:0001N4], [UID:000366], and [UID:000035]:

- Add a cross-reference that Drop/Give panes pass action objects created by [UID:0002VM].
- State that the stored action at `+0x108` is a FunctionObjects callback object whose virtual invoke slot reaches [UID:0001N5].
- No ownership change.

## IDA Rename / Type / Comment Recommendations

Recommended names:

- `sub_5B7450` -> `CreateUserPaneDoubleParamCallback` or `CreateUserPaneDoubleParamMemberCallback`
  - Confidence: high for role, medium for exact original spelling.
  - Comment: "Allocates/configures a UserPane slot/bool FunctionObject action for Drop/Give ConfirmInputPane prompts."
- `sub_5AD7A0` -> `UserPane_SendDropItemPacket`
  - Confidence: high for behavior, medium-high for exact source spelling.
  - Type: `void __thiscall UserPane::SendDropItemPacket(signed char slot, bool allItems)`
- `sub_5AD720` -> `UserPane_SendGiveItemPacket`
  - Confidence: high for behavior, medium-high for exact source spelling.
  - Type: `void __thiscall UserPane::SendGiveItemPacket(signed char slot, bool allItems)`
- `sub_4F4AA0` -> `operator_new`
  - Confidence: high; already resolved by [UID:000196].
- `sub_4F4A80` -> `LObject_ctor`
  - Confidence: high; already resolved by [UID:00036Z].
- `dword_67A748` -> keep coordinated project name `g_pCollectionData`; add typed comments where used as `UserPane *activeLocalUserPane`.
  - Confidence: high for role in this helper, lower for global original spelling.
- `0x00630a78` -> `vftable_DoubleParamMemberFunctionObject0_UserPane_schar_bool`
  - Confidence: high; decorated name is known.
- `0x005b77b0` -> `UserPaneDoubleParamCallback_Invoke`
  - Confidence: high for role, medium for exact original spelling.

Recommended struct/type for the concrete callback object:

```cpp
struct UserPaneItemActionCallbackObject
{
    void **vftable;                  // +0x00
    /* inherited LObject storage */  // +0x04
    UserPaneItemActionCallback m_callback; // +0x08
    int m_thisAdjust;                      // +0x0c
    UserPane *m_target;                    // +0x10
    signed char m_slot;                    // +0x14
    bool m_allItems;                       // +0x15
};
```

Do not force this exact typedef name into global docs if the project prefers the template spelling; use it as an IDA/local readability aid.

## Open Questions After Reanalysis

These remain real but are no longer blockers:

- Exact original helper spelling is not symbol-proven. The stable doc name is acceptable; `CreateUserPaneDoubleParamMemberCallback` is the clearer descriptive alternative.
- Exact original global spelling for `dword_67A748` is project-wide and should stay coordinated through [UID:0000QK].
- Exact original template header declaration spelling for `DoubleParamMemberFunctionObject0` is not proven. The decorated vtable name and field layout support the template/source alias above.
- The helper may be a compiler-outlined template instantiation rather than a hand-written function. This affects source-placement prose, not reconstruction of the helper body or owner route.

## Exact Coverage Text

Do not edit `by-memory/-coverage-report.md` directly. If the supervisor accepts the source-quality update and target score recommendation, replace the existing [UID:0002VM] row with:

```text
    - [UID:0002VM][0x005b7450-0x005b74dd.CreateUserPaneDoubleParamCallback](by-memory/0x005b7450-0x005b74dd.CreateUserPaneDoubleParamCallback.md) 0x005b7450-0x005b74dd | constructor helper | CreateUserPaneDoubleParamCallback : reconstructable : 87% : very strong : B003 2026-06-19 source-quality reanalysis confirms exact factory boundary, MemoryMan-backed operator-new allocation of a 24-byte `DoubleParamMemberFunctionObject0<UserPane,signed char,bool>` action object, `LObject::LObject` base init, vtable `0x00630a78`, callback/adjust/target/slot/all-items field stores, four Drop/Give confirmation callers, `g_pCollectionData` as the active local `UserPane` target, `UserPane::SendDropItemPacket`/`UserPane::SendGiveItemPacket` member callbacks, pairing with `ConfirmInputPane` constructor/action dispatch and `0x005b77b0` invoke wrapper, adjacent padding, and first-draft factory C++ readiness.
```

Expected generated memory-coverage row after formal C++ is added and reports are regenerated:

```text
| [UID:0002VM][0x005b7450-0x005b74dd.CreateUserPaneDoubleParamCallback](by-memory/0x005b7450-0x005b74dd.CreateUserPaneDoubleParamCallback.md) | emits | `000040` | `000040` |  | yes | `auto-generated/NexusTK/util/FunctionObjects.cpp` | `by-memory/0x005b7450-0x005b74dd.CreateUserPaneDoubleParamCallback.md` |  |
```

If the supervisor chooses the strict generated-binary/no-code fallback, keep the generated row's C++ column as `no` and use the by-memory coverage prose above minus the final "first-draft factory C++ readiness" phrase.

## Validator Needs

No validators were run because this assignment was report-only and no by-* docs were edited. After implementation, run at minimum:

> Executable block R001 was removed from this report and preserved verbatim in [0002VM-CreateUserPaneDoubleParamCallback-source-quality-removed.md](0002VM-CreateUserPaneDoubleParamCallback-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If generated outputs are refreshed after implementation, regenerate the coverage/autogen reports through the project-approved generator rather than editing generated files manually.

## Implementation Readiness

Ready for implementation callback.

The target is reconstructable, has a valid owner/emitter route, clears the current C++ gate after recommended scoring, and has a plausible source-quality first draft. Remaining uncertainty is limited to exact original naming/policy, not behavior, reachability, type ownership, or emitted source route.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B003","command_id":"000000004165","destination_path":"executed-b-agent-research/B003/0002VM-CreateUserPaneDoubleParamCallback-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:28","uid":"0002VM"} -->
<!-- {"agent":"B003","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 0002VM-CreateUserPaneDoubleParamCallback-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B003/0002VM-CreateUserPaneDoubleParamCallback-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"0002VM"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
