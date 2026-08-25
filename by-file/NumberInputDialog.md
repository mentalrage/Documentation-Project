*** UID:0000M1 | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/dialogs/" | ONLY MODIFY PATH INSIDE QUOTES - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:FILE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***

# NumberInputDialog

## Status

- Confidence: very strong for class boundary, behavior, vtable ownership, callback/source separation, first-draft C++ readiness, and source placement; medium-high for exact original filename.
- Proposed module: `ui/dialogs/NumberInputDialog.cpp`
- Proposed header: `ui/dialogs/NumberInputDialog.h`
- Current recovered source: `source-3/simroot_v2/class_NumberInputDialog.cpp`
- Main memory range: [UID:0001CW][0x00530640-0x00530cf7.NumberInputDialog](by-memory/0x00530640-0x00530cf7.NumberInputDialog.md)
- Related support docs: [UID:0001CV][0x00530640-0x00530b00.NumberInputDialogConstructor](by-memory/0x00530640-0x00530b00.NumberInputDialogConstructor.md), [UID:0001CY][0x00530b40-0x00530c78.NumberInputDialogActionHandler](by-memory/0x00530b40-0x00530c78.NumberInputDialogActionHandler.md), [UID:0001CX][0x00530b00-0x00530b35.NumberInputDialogRawDestructor](by-memory/0x00530b00-0x00530b35.NumberInputDialogRawDestructor.md), [UID:0001CZ][0x00530c78-0x00530c8e.NumberInputDialogAdjustorThunks](by-memory/0x00530c78-0x00530c8e.NumberInputDialogAdjustorThunks.md), [UID:0001D0][0x00530c90-0x00530cf7.NumberInputDialogScalarDeletingDestructor](by-memory/0x00530c90-0x00530cf7.NumberInputDialogScalarDeletingDestructor.md), [UID:0001RJ][number-input-dialog-resources](by-resource/number-input-dialog-resources.md)
- Class-owned read-only data: [UID:0003C8][0x006201d0-0x0062026c.NumberInputDialogVtableData](by-memory/0x006201d0-0x0062026c.NumberInputDialogVtableData.md)
- Evidence basis: generated source as a lead plus read-only IDA MCP checks through 2026-06-01. `wave3.py` was not executed for this pass.

## File Role

`NumberInputDialog` is a reusable modal numeric input dialog. It displays a prompt, OK/cancel buttons, a single text edit field, a configurable min/max range, and callback objects for confirmed and cancelled input.

Keep it as a generic `ui/dialogs/` source rather than attaching it to item/mix dialogs. Current direct constructor callers are item-mixing quantity paths, but the class itself is a standalone prompt that validates arbitrary integer input and reports through callback interfaces.

B002's 2026-06-17 source-quality pass confirms this file should receive constructor, ordinary destructor, and action-handler source from the exact child pages. Caller-specific callback wrapper classes remain with `FunctionObjects` / `ItemDialogs`, and the scalar deleting destructor remains compiler-generated ABI output.

## Proposed Contents

| Entity | Address evidence | Role |
| --- | --- | --- |
| [UID:00009K][NumberInputDialog](by-class/NumberInputDialog.md) | `0x00530640-0x00530cf7` | Modal numeric prompt with dual EPF/EPD layouts, min/max validation, callback dispatch, and destructor thunks. |
| `g_alertPaneButtonLayout` | generated global-data reference | Button layout passed to the out-of-range [UID:00000B][AlertPane](by-class/AlertPane.md). |
| `g_pGrafPort` | generated global-data reference | Dialog bounds/context setup. |
| `g_pLanguageMan` | generated global-data reference | Localized prompt/error string lookups. |
| `g_useEpfAssets` | generated global-data reference | Chooses the high-resolution EPF layout versus older EPD layout. |

## Function Map

| Range | Function | Notes |
| --- | --- | --- |
| [UID:0001CV][0x00530640-0x00530b00.NumberInputDialogConstructor](by-memory/0x00530640-0x00530b00.NumberInputDialogConstructor.md) | constructor | Builds the dialog controls, stores abstract confirm/cancel callbacks and min/max range fields, sets focus/default/cancel controls, positions the dialog, opens it, and now carries first-draft C++. |
| [UID:0001CX][0x00530b00-0x00530b35.NumberInputDialogRawDestructor](by-memory/0x00530b00-0x00530b35.NumberInputDialogRawDestructor.md) | ordinary destructor body | IDA now persists exact function `[0x00530b00,0x00530b35)` as `NumberInputDialog__Destructor`; UID0001CX remains the authored source-body route. Source C++ deletes only the owned confirm callback; vtable/base cleanup remains compiler output. |
| [UID:0001CY][0x00530b40-0x00530c78.NumberInputDialogActionHandler](by-memory/0x00530b40-0x00530c78.NumberInputDialogActionHandler.md) | `OnControlCommand(int,int)` override | Button `1` parses and validates edit text; button `2` closes and dispatches cancel. Exact `DialogPane` slot comparison resolves the inherited virtual name. |
| [UID:0001CZ][0x00530c78-0x00530c8e.NumberInputDialogAdjustorThunks](by-memory/0x00530c78-0x00530c8e.NumberInputDialogAdjustorThunks.md) | secondary adjustor thunk | Real `0x0b` thunk forwarding to `0x00530c90` with `this - 0xa0` / decimal `160`; excluded through [UID:0000VN][-ignored](by-memory/-ignored.md) and regenerated from the `NumberInputDialog` class layout rather than emitted as C++. |
| [UID:0001CZ][0x00530c78-0x00530c8e.NumberInputDialogAdjustorThunks](by-memory/0x00530c78-0x00530c8e.NumberInputDialogAdjustorThunks.md) | tertiary adjustor thunk | Real `0x0b` thunk forwarding to `0x00530c90` with `this - 0xa4` / decimal `164`; excluded through [UID:0000VN][-ignored](by-memory/-ignored.md) and regenerated from the `NumberInputDialog` class layout rather than emitted as C++. |
| [UID:0001D0][0x00530c90-0x00530cf7.NumberInputDialogScalarDeletingDestructor](by-memory/0x00530c90-0x00530cf7.NumberInputDialogScalarDeletingDestructor.md) | scalar deleting destructor | Class-owned generated ABI output from the virtual destructor declaration and UID0001CX body; represented by an exact covered-by marker, never a handwritten wrapper. |

## Layout And Resource Notes

- EPF layout uses `DLGEXC3.EPF`, palette `PAL01.PAL`, outer rect `239x283`, OK button image `14`, cancel image `22`, label control `3`, and edit control `4`.
- EPD layout uses `DLGEXC3.EPD`, palette `NPAL8.PAL`, outer rect `287x277`, OK button image `14`, cancel image `22`, label control `3`, and edit control `4`; see [UID:0001RJ][number-input-dialog-resources](by-resource/number-input-dialog-resources.md).
- The active generated source currently prints the EPD palette as `L"NP"`; IDA string bytes at symbol `aNp` decode to `NPAL8.PAL`.
- The out-of-range path creates an [UID:00000B][AlertPane](by-class/AlertPane.md) using localized string id `217`.
- The item quantity prompt callers use localized string id `218` and min/max `1..itemInfo->m_maxStack`.

## Historical 2026-06-17 Source-Quality Integration

Accepted source model:

- `NumberInputDialog.cpp` owns a reusable modal numeric prompt, not caller-specific quantity business logic.
- `m_confirmCallback` is an owned abstract one-argument numeric callback at `+0x26c`; destructor code deletes this field.
- `m_cancelCallback` is a nullable/externally managed no-argument callback at `+0x270`; the cancel path invokes it, but destructor evidence does not delete it.
- `m_minValue` and `m_maxValue` at `+0x274/+0x278` are inclusive integer bounds.
- Control ids `1/2/3/4` are OK, cancel, prompt label, and edit control; button image/frame ids are `14` and `22`; localized invalid-number string id is `217`.
- `sub_498C20`, `sub_582670`, `sub_4F0380`, `sub_49FEB0`, and `sub_49DAD0` should be documented in first-draft source through descriptive text-edit, parse, LanguageMan, AlertPane, and close/dismiss helper names until wider subsystem naming is finalized.

Rejected source placement and ownership alternatives:

- `ItemDialogs`, `MixItemDialog`, `AddMixingItemDialog`, and concrete stack-quantity flows own prompt parameters and callback allocation, not this dialog implementation.
- `FunctionObjects` owns concrete callback adapter/template mechanics, not the modal numeric prompt.
- `AlertPanes`, `LanguageMan`, `TextEditControlPane`, string parsing, and close helpers are dependencies of [UID:0001CY][0x00530b40-0x00530c78.NumberInputDialogActionHandler](by-memory/0x00530b40-0x00530c78.NumberInputDialogActionHandler.md), not owners.
- `NumberInputDialog` source should not handwrite scalar deleting destructor or adjustor thunk bodies; normal virtual destructor source and the class inheritance/vtable layout regenerate those compiler ABI artifacts. [UID:0001CZ][0x00530c78-0x00530c8e.NumberInputDialogAdjustorThunks](by-memory/0x00530c78-0x00530c8e.NumberInputDialogAdjustorThunks.md) is the resolved ignored evidence page for the secondary/tertiary thunk pair, not a source method container.

At the time of this historical integration, generated `NumberInputDialog.cpp` being empty was identified as a documentation/C++ block issue rather than absence of a source route. The 2026-08-02 accepted model below now supplies the complete class H, exact constructor/destructor/`OnControlCommand` children, and class-covered compiler-product markers.

## 2026-08-02 B010 Complete Source Route And Generated Topology

### Translation-Unit Ownership

- Proposed reconstruction path remains exactly `NexusTK/ui/dialogs/`; no proposed-source-tree edit is required.
- `NumberInputDialog.h` owns the sole complete [UID:00009K][NumberInputDialog](by-class/NumberInputDialog.md) declaration: direct `DialogPane` base, exact five-argument constructor, public virtual destructor, protected `OnControlCommand(int,int)`, control/resource constants, and four tail fields.
- `NumberInputDialog.cpp` owns only human-authored definitions from UID0001CV constructor, UID0001CX ordinary destructor, and UID0001CY `OnControlCommand`.
- UID0001D0 scalar wrapper and UID0003C8 vtable/RTTI cluster are source-declared/generated-binary evidence represented by covered-by comments. UID0001CZ thunks and UID0001CW range index remain blank non-emitting support.

### Corrected Source Topology

| UID | Source role | Formal destination |
| --- | --- | --- |
| `00009K` | sole complete class declaration and class child insertion point | H declaration; CPP support comment plus `[[CHILDREN]]` |
| `0001CV` | exact five-argument constructor, no parent parameter | CPP definition |
| `0001CX` | ordinary `NumberInputDialog::~NumberInputDialog()` source body | CPP definition |
| `0001CY` | exact `OnControlCommand(int,int)` inherited override | CPP definition |
| `0001D0` | compiler scalar deleting wrapper | UID0001CX covered-by marker only; H blank |
| `0001CZ` | EventHandler/TimerHandler destructor adjustors | CPP/H blank, false/non-emitting |
| `0003C8` | compiler vtable/RTTI/COL cluster | UID00009K covered-by marker only; H blank |
| `0001CW` | executable-range index | CPP/H blank, false/non-emitting |

### Human Source Versus Compiler Lowering

Human source contains the class declaration, constructor, ordinary destructor, and action override. It does not contain explicit vptr stores, scalar-delete flags, size-guard calls, deleting-wrapper bodies, `this`-adjustor thunks, raw vtable arrays, COLs, or RTTI objects. Those products are regenerated by the class layout, direct base, virtual destructor, and inherited facet topology.

The constructor uses exact declaration-backed APIs and complete EPF/EPD geometry; the action uses typed `GetChild<TextEditControlPane>`, `StringBase::ToLong`, exact `g_pLanguageMan`/`CopyLocalizedString` routing, `AlertPane`, and callback interfaces. Older descriptive convenience wrappers and provisional `OnButtonAction`/`OnConfirm` spellings remain historical and are not part of current source.

The invalid-number branch at UID0001CY consumes `LanguageMan::CopyLocalizedString(217)` as a const by-value `mystr::StringBase<wchar_t,...>` result. The machine-level explicit result pointer at `0x00530c27` is hidden-sret lowering; source does not default-construct a message and pass `&message`. The result remains live through `AlertPane(message.c_str(), this, L"OK", 0)` and its destructor.

### Expected Generated Result

After the supervisor-owned generated phase, `NumberInputDialog.cpp` should contain exactly one constructor, ordinary destructor, and `OnControlCommand` body; `NumberInputDialog.h` should contain exactly one complete class declaration. It should contain no handwritten scalar wrapper, adjustor thunk, vtable/RTTI array, or explicit vptr-store product, and no empty markers for UID0001D0, UID00009K, UID0003C8, or UID0001CW. These are expectations for later generated readback, not claims that this callback edited generated files.

Completion/confidence `94/94` remains below final because the exact original filename/source arrangement and full-project byte-identical build are final-audit constraints. The complete family inventory, corrected signatures, class/header route, child CPP topology, compiler-product exclusions, and generated expectations close the local file-routing blockers.

## Read-Only Data Evidence

| Range | Owner | Evidence |
| --- | --- | --- |
| [UID:0003C8][0x006201d0-0x0062026c.NumberInputDialogVtableData](by-memory/0x006201d0-0x0062026c.NumberInputDialogVtableData.md) | [UID:00009K][NumberInputDialog](by-class/NumberInputDialog.md) | Exact source-declared/generated-binary vtable child. 2026-06-12 live IDA MCP confirms primary/secondary/tertiary complete-object-locator plus vtable chunks, constructor and destructor vtable stores, action-handler slot `0x0062021c -> 0x00530b40`, secondary thunk `0x00530c78`, tertiary thunk `0x00530c83`, scalar deleting destructor slot `0x006201d4 -> 0x00530c90`, and the `DLGEXC3.EPD` successor boundary. |

## Caller Evidence

- `xrefs_to 0x00530640` reports direct constructor calls from `0x004afdce` inside the mix/item add helper at `0x004afcc0` and from `0x004b03d6` inside `AddMixingItemDialog::OnConfirm`.
- Both callers allocate 636 bytes and pass callback objects that call `MixItemDialog` quantity-add logic after the user chooses a number. IDA MCP decompilation on 2026-05-25 shows the callback objects being constructed at `0x004afd62` and `0x004b0370`; the generated wrapper is documented as [UID:000041][DoubleParamMemberFunctionObject_void____thiscall_MixItemDialog_____unsigne__h9ece1f1df45d](by-class/DoubleParamMemberFunctionObject_void____thiscall_MixItemDialog_____unsigne__h9ece1f1df45d.md).
- Vtable data refs confirm the action-handler slot at `0x62021c`, adjustor thunk `0x00530c78` at `0x620234`, adjustor thunk `0x00530c83` at `0x620264`, and scalar deleting destructor `0x00530c90` at `0x6201d4`.

## Ownership Notes

- This range starts immediately after [UID:0000M0][NexonclubRegistrationDialog](by-file/NexonclubRegistrationDialog.md), but it is not part of account registration. Treat `0x00530640` as the start of this separate dialog class.
- `ItemDialogs.cpp` and `MixItemDialog.cpp` should call this class for stack quantities; they should not own the implementation.
- IDA does not define the ordinary destructor at `0x00530b00`, but the raw bytes are documented at [UID:0001CX][0x00530b00-0x00530b35.NumberInputDialogRawDestructor](by-memory/0x00530b00-0x00530b35.NumberInputDialogRawDestructor.md).
- Historical disabled generated output decoded `0x00530c78` with the wrong `this - 0x1dc` adjustment and omitted `0x00530c83`. Current source-quality state is resolved ignored thunk evidence: `0x00530c78` uses `this - 0xa0`, `0x00530c83` uses `this - 0xa4`, both jump to [UID:0001D0][0x00530c90-0x00530cf7.NumberInputDialogScalarDeletingDestructor](by-memory/0x00530c90-0x00530cf7.NumberInputDialogScalarDeletingDestructor.md), and neither thunk should appear as C++ in `NumberInputDialog.cpp`; the raw destructor and scalar deleting destructor remain separately documented.
- 2026-05-26 IDA MCP recheck confirms `0x00530b00` is still absent from the function table, the adjustor thunks forward after `this - 0xa0` / `this - 0xa4`, and the EPD branch resource should remain `NPAL8.PAL`.
- 2026-06-01 IDA MCP recheck confirms the same boundaries and ownership: `lookup_funcs` reports `0x00530640` size `0x4c0`, `0x00530b00` as `Not a function`, `0x00530b40` size `0x138`, `0x00530c78` and `0x00530c83` as 0xb thunks, and `0x00530c90` size `0x67`; raw bytes at `0x00530636-0x00530640` and `0x00530cf7-0x00530d00` are `0xcc` padding.
- 2026-06-01 IDA MCP decompilation records constructor fields at `+0x26c/+0x270/+0x274/+0x278`, vtable stores through `0x006201d4/0x00620234/0x00620264`, action-handler use of edit control `4`, localized error string `217`, confirm/cancel callback dispatch, and scalar-deleting destructor callback cleanup.
- 2026-06-12 IDA MCP refresh confirms the read-only vtable child belongs to this class/source module rather than the neighboring create-user or registration dialogs: the preceding bytes are the registration URL tail, `0x006201d0` points to `??_R4NumberInputDialog@@6B@`, all three vtable bases are written only by the `NumberInputDialog` constructor/raw destructor/scalar deleting destructor, and `0x0062026c` begins the `DLGEXC3.EPD` resource literal consumed by the `NumberInputDialog` constructor.

## Cross-References

- [UID:00009K][NumberInputDialog](by-class/NumberInputDialog.md)
- [UID:0001CW][0x00530640-0x00530cf7.NumberInputDialog](by-memory/0x00530640-0x00530cf7.NumberInputDialog.md)
- [UID:0001CX][0x00530b00-0x00530b35.NumberInputDialogRawDestructor](by-memory/0x00530b00-0x00530b35.NumberInputDialogRawDestructor.md)
- [UID:0001CZ][0x00530c78-0x00530c8e.NumberInputDialogAdjustorThunks](by-memory/0x00530c78-0x00530c8e.NumberInputDialogAdjustorThunks.md)
- [UID:0001D0][0x00530c90-0x00530cf7.NumberInputDialogScalarDeletingDestructor](by-memory/0x00530c90-0x00530cf7.NumberInputDialogScalarDeletingDestructor.md)
- [UID:0001RJ][number-input-dialog-resources](by-resource/number-input-dialog-resources.md)
- [UID:0000KE][ItemDialogs](by-file/ItemDialogs.md)
- [UID:000009][AddMixingItemDialog](by-class/AddMixingItemDialog.md)
- [UID:00008J][MixItemDialog](by-class/MixItemDialog.md)
- [UID:0000JO][FunctionObjects](by-file/FunctionObjects.md)
- [UID:00014W][0x004b0880-0x004b08a1.MixItemDialogDoubleParamCallback](by-memory/0x004b0880-0x004b08a1.MixItemDialogDoubleParamCallback.md)
- [UID:0000IT][DialogPane](by-file/DialogPane.md)
- [UID:0000OM][TextEditControlPane](by-file/TextEditControlPane.md)
- [UID:0000E3][StaticTextControlPane](by-class/StaticTextControlPane.md)
- [UID:00006D][ImageButtonControlPane](by-class/ImageButtonControlPane.md)
- [UID:00004G][EPFImageControlPane](by-class/EPFImageControlPane.md)
- [UID:0000KK][LanguageMan](by-file/LanguageMan.md)
- [UID:0000HE][AlertPanes](by-file/AlertPanes.md)
- [UID:0003C8][0x006201d0-0x0062026c.NumberInputDialogVtableData](by-memory/0x006201d0-0x0062026c.NumberInputDialogVtableData.md)

## Changes

- 2026-08-24 B005 UID0000KK support sync: synchronized the file inventory with UID0001CY's corrected by-value LanguageMan/StringBase dependency and rejected the stale explicit output-source call while preserving id `217`, AlertPane use, and result lifetime.

- 2026-06-17 B002 source-quality execution:
  - Before: the file was `90/86`; it documented the source route and class map but still left callback/declaration/destructor policy as active blockers and generated output empty.
  - Changed to: `COMPLETION:91`, `CONFIDENCE:90`; added report-level callback ownership/type direction, method C++ readiness, scalar wrapper policy, dependency/source-placement rejections, helper-name directions, and generated-output explanation.
  - Evidence: B002 report-level review of the four exact child methods, aggregate, class page, resource page, FunctionObjects/caller docs, and generated-output state.
- Before: completion/confidence were ungraded at `0/0`.
- Changed to: completion `88`, confidence `82`.
- Summary/evidence: the page documents role, constructor/action/destructor function map, resources, callers, vtable refs, ownership notes, generated-data defects, and cross-references; confidence remains capped by exact original filename and raw destructor treatment.
- 2026-06-01 path and evidence refresh:
  - What existed before: `PROPOSED_RECONSTRUCTION_PATH` was blank and the page was scored `88/82`.
  - Changed to: `PROPOSED_RECONSTRUCTION_PATH:"NexusTK/ui/dialogs/"`, `COMPLETION:89`, and `CONFIDENCE:84`.
  - Summary/evidence: refreshed IDA MCP lookup/caller/xref/decompile/raw-byte checks confirm the range boundaries, raw destructor gap, vtable refs, callback fields, action flow, and padding; original filename remains a source-layout hypothesis rather than final proof.
- 2026-06-12 A004 Batch 258:
  - What existed before: the file page was `89/84`, which kept the direct class parent just below the strict confidence gate for routing [UID:0003C8][0x006201d0-0x0062026c.NumberInputDialogVtableData](by-memory/0x006201d0-0x0062026c.NumberInputDialogVtableData.md).
  - Changed to: `COMPLETION:90`, `CONFIDENCE:86`; added class-owned read-only-data evidence for [UID:0003C8][0x006201d0-0x0062026c.NumberInputDialogVtableData](by-memory/0x006201d0-0x0062026c.NumberInputDialogVtableData.md).
  - Summary/evidence: live IDA MCP confirms the exact `NumberInputDialog` vtable child, constructor/destructor vtable stores, method slot targets, resource boundary, and separation from neighboring registration/create-user `.rdata`. Exact original filename remains a hypothesis, but ownership is strong enough for class and child routing.
