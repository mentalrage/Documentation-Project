*** UID:00050J | DO NOT MODIFY OR REMOVE!!! ***
*** COMPLETION:94 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:96 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000K6 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000K6 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_POSITION_OPTIONAL:0 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:[[[]]] | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_CPP CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
#include "InputMan.h"

InputMan *g_pInputMan = 0;

template <>
Singleton<InputMan>::Singleton()
{
    g_pInputMan = static_cast<InputMan *>(this);
}

template <>
Singleton<InputMan>::~Singleton()
{
    g_pInputMan = 0;
}
*** RECONSTRUCTION_CPP CODE:END | DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:BEGIN | ONLY MODIFY BETWEEN BEGIN/END - DO NOT REMOVE!!! ***
*** RECONSTRUCTION_H CODE:END | DO NOT REMOVE!!! ***

# g_pInputMan

## Status And Source Contract

- Entity: process-wide `InputMan *` singleton pointer.
- Physical backing storage: [UID:000299][0x0067ab44-0x0067ab48.g_pInputMan](by-memory/0x0067ab44-0x0067ab48.g_pInputMan.md).
- Definition/specialization owner and output route: [UID:0000K6][InputMan](by-file/InputMan.md), reconstructed as `NexusTK/input/InputMan.cpp`; this page emits the one definition followed by both explicit class-specific `Singleton<InputMan>` specializations.
- Declaration owner: [UID:00006J][InputMan](by-class/InputMan.md), whose formal `InputMan.h` block already emits exactly `extern InputMan *g_pInputMan;`.
- Runtime initial state: null through loader-zero-filled `.data` storage.
- Confidence: very strong for address, type, lifetime, one-definition route, and human source name. The exact original initializer token (`= 0`, `= NULL`, or implicit zero) is not recoverable; `= 0` is the accepted C++03-era source form.

This semantic page owns the sole source definition. The physical memory page documents the address-backed evidence and intentionally emits no duplicate source.

## Purpose And Runtime Role

`g_pInputMan` stores the active process-wide [UID:00006J][InputMan](by-class/InputMan.md) instance used by Application message dispatch, Win32/IMM composition handling, MainMenu setup, Pane input-target registration, TextEdit mouse handling, and UserPane initialization. It is not a class static: callers access one external global address directly, `Singleton<InputMan>::Singleton()` publishes the complete object with `static_cast<InputMan *>(this)`, and `Singleton<InputMan>::~Singleton()` clears the same slot.

The pointer is null before successful `InputMan` construction. Compiler lowering of the constructor specialization publishes the completed object; reverse base destruction clears it during ordinary and scalar teardown, while the constructor EH path invokes the same destructor specialization through the retained action at `0x004e9650`. Consumers only read or dispatch through the current pointer; no second storage alias or alternate writer is supported.

## Static Storage And Loader Initialization

- Virtual address: `0x0067ab44`, exact half-open range `[0x0067ab44,0x0067ab48)`.
- PE image base: `0x00400000`; target RVA: `0x0027ab44`.
- Section: `.data`, starting at RVA `0x0026d000`, virtual size `0x0002fe24`, raw size `0x0000d800`, raw pointer `0x0026ac00`.
- Target section offset: `0x0000db44`, beyond the section's raw extent. The executable therefore has no file-backed initializer bytes for this slot; the Windows loader supplies four zero bytes.
- Dated 2026-08-06 read-only IDB evidence also reports `00 00 00 00` at the target.
- Source consequence: the runtime must begin null. `InputMan *g_pInputMan = 0;` preserves that behavior without reproducing linker/loader artifacts.

## IDA Physical Prestate

The 2026-08-06 bounded read-only MCP snapshot records an under-defined four-byte slot rather than a valid typed global:

| Address | Item head/end | Size | Name | Displayed type | Kind | Address comments |
| --- | --- | ---: | --- | --- | --- | --- |
| `0x0067ab44` | `0x0067ab44-0x0067ab45` | `1` | `unk_67AB44` | `_DWORD *` | unknown; not code/data | regular absent; repeatable absent |
| `0x0067ab45` | `0x0067ab45-0x0067ab46` | `1` | absent | absent | unknown; not code/data | regular absent; repeatable absent |
| `0x0067ab46` | `0x0067ab46-0x0067ab47` | `1` | absent | absent | unknown; not code/data | regular absent; repeatable absent |
| `0x0067ab47` | `0x0067ab47-0x0067ab48` | `1` | absent | absent | unknown; not code/data | regular absent; repeatable absent |

`type_inspect` found no local `InputMan` type and `list_globals` found no modeled `g_pInputMan` global in that dated snapshot. These are IDA-model gaps, not source uncertainty: direct code use proves a four-byte object pointer and the current class/file documentation establishes `InputMan`.

## Lifetime Writes

| Address | Containing routine | Access | Meaning |
| --- | --- | --- | --- |
| `0x004e8b33` | `InputMan` constructor lowering | write constructed pointer | `Singleton<InputMan>::Singleton()` publishes the successfully constructed complete manager after adjusting from the empty base. |
| `0x004e8b3a` | `InputMan` constructor EH lowering | write `0` | Constructor failure invokes `Singleton<InputMan>::~Singleton()` after publication. |
| `0x004e8c81` | ordinary destructor lowering | write `0` | Reverse-base destruction invokes the Singleton destructor specialization before `LObject` teardown. |
| `0x004e9650` | compiler-retained constructor-unwind action | write `0` | Two-instruction lowering of `Singleton<InputMan>::~Singleton()` with one EH xref and no ordinary caller; no handwritten helper. |
| `0x004e96c8` | scalar deleting destructor lowering | write `0` | The compiler-inlined Singleton destructor specialization clears during scalar teardown. |

The five writes close the lifetime contract: one successful publication and four clear paths generated from the two class-specific specializations. No manual assignment belongs in `InputMan::InputMan` or `InputMan::~InputMan`; no instruction writes `0xffffffff`, and no alternate non-null writer was found.

## Consumer Xrefs

The dated bounded `xrefs_to(0x0067ab44, limit 100)` result contains exactly 18 untruncated direct references: the five writes above plus these thirteen consumers.

| Address | Containing routine | Consumer role |
| --- | --- | --- |
| `0x00464bff` | Application cleanup at `0x00464a60` | Loads the active manager during application resource cleanup. |
| `0x00464d94` | Application run/message-loop path at `0x00464cd0` | Reads the manager for input-mode/message-loop work. |
| `0x00465f84` | main window-message dispatcher at `0x00465f20` | Loads the manager for Win32 input dispatch. |
| `0x004661c7` | same application dispatcher | Reads the manager in the key/input-mode branch. |
| `0x004e7600` | IME composition helper at `0x004e7470` | Uses the active manager during composition processing. |
| `0x004f6796` | `MainMenuPane` construction | Reads the manager during MainMenu input setup. |
| `0x004f8ae4` | `MainMenuPane::InitializeMainUiGraph` | Uses the manager while building the main UI/input graph. |
| `0x005445cc` | `Pane` destructor | Deregisters pane input-target state through the manager. |
| `0x00544ebb` | pane input-target helper at `0x00544ea0` | Reads the manager in the active-tracking branch. |
| `0x00544ecd` | same pane helper | Reads the manager in the opposite tracking branch. |
| `0x00544fa3` | pane scalar teardown helper at `0x00544f50` | Performs input-target cleanup. |
| `0x00590f65` | `TextEditPane::OnMouseEvent` | Uses input/IME state during text-edit mouse handling. |
| `0x005a25e0` | `UserPane` initialization at `0x005a2530` | Reads the manager during user-pane input setup. |

Consumer count does not establish source ownership by itself. The decisive source-owner evidence is the constructor/destructor write cluster in the `InputMan` executable island plus the established `InputMan.h` declaration.

## Boundaries And Physical Relationship

- Predecessor `[0x0067ab40,0x0067ab44)` is the separate `g_pDATFileMgr` singleton slot and ends exactly at this range.
- Successor item begins exactly at `0x0067ab48`, has its own xrefs, and is not part of `InputMan` storage.
- Every one of the 18 target references lands at `0x0067ab44`; none targets an interior byte.
- There is no padding, split, merge, or wider InputMan data range to reconstruct. The only structural separation is semantic: this page owns the source symbol, while [UID:000299][0x0067ab44-0x0067ab48.g_pInputMan](by-memory/0x0067ab44-0x0067ab48.g_pInputMan.md) owns exact physical-address evidence.

## Source Placement And One-Definition Rationale

The best late-1999-through-mid-2000s source shape is one externally linked file-scope pointer definition in `InputMan.cpp` and one `extern` declaration in `InputMan.h`:

- [UID:0000K6][InputMan](by-file/InputMan.md) owns the constructor, destructors, input/IME methods, and therefore the global definition's source module.
- [UID:00006J][InputMan](by-class/InputMan.md) owns the complete header declaration and already emits `extern InputMan *g_pInputMan;` exactly once.
- This page emits `InputMan *g_pInputMan = 0;` followed by `template <> Singleton<InputMan>::Singleton()` and `template <> Singleton<InputMan>::~Singleton()` through the `InputMan.cpp` route at direct-file position `0`, before the UID00006J class child route at position `1`. Its H channel remains blank to avoid a duplicate declaration.
- [UID:000299][0x0067ab44-0x0067ab48.g_pInputMan](by-memory/0x0067ab44-0x0067ab48.g_pInputMan.md) becomes non-reconstructable/non-emitting physical evidence after this semantic page exists; it must not emit a second definition.

Rejected alternatives:

- Class-static member: rejected because code uses a free global address and current source/header documentation already uses an external `g_pInputMan` contract.
- `Application.cpp` ownership: rejected because Application is a constructor/consumer/cleanup client; the lifecycle writers and implementation island belong to InputMan.
- `IMEPanes.cpp`, MainMenu, Pane, TextEditPane, or UserPane ownership: rejected because those modules only consume the pointer.
- Broad `.data` container ownership: rejected because an exact semantic global page provides the narrow source entity.
- Definition on the physical by-memory page: rejected because that would duplicate this page's sole source symbol.
- Raw IDA labels such as `unk_67AB44` or `dword_67AB44`: rejected as binary-analysis artifacts rather than plausible human source names.

## Formal Source Decision

The formal CPP channel contains exactly one null definition followed by the two explicit class-specific specializations. The constructor specialization publishes `static_cast<InputMan *>(this)`; the destructor specialization stores `0`. This is source-authored global/base-specialization state whose publication, ordinary/scalar clear, and constructor-unwind clear are compiler lowering. It preserves exact null startup and lifetime behavior without address-derived or decompiler-shaped syntax.

The formal H channel is intentionally blank. [UID:00006J][InputMan](by-class/InputMan.md) already emits the sole accepted header declaration `extern InputMan *g_pInputMan;`; repeating it here would produce duplicate header text without adding a distinct declaration owner.

## Historical And Superseded Assumptions

- Historical June documentation described `ff ff ff ff` / `0xffffffff` as the current initializer. That interpretation is disproved by the PE mapping: the target lies beyond `.data` raw bytes and is loader-zero-filled; current IDB bytes are also `00 00 00 00`. The old claim is retained here as disproved history so it is not silently lost or reused.
- Historical ownership attached [UID:000299][0x0067ab44-0x0067ab48.g_pInputMan](by-memory/0x0067ab44-0x0067ab48.g_pInputMan.md) directly to [UID:0000K6][InputMan](by-file/InputMan.md) because `by-global/g_pInputMan.md` did not exist and could not be leased. That was a tooling/path workaround, not the best semantic hierarchy. This page now provides the narrow global owner while still emitting through InputMan.cpp.
- The exact original spelling of the initializer token is unrecoverable. The accepted `= 0` spelling follows nearby project singleton definitions and period-appropriate C++ style; it is an inference about source spelling, not runtime behavior.

## Score Rationale

| Metric | Value | Rationale |
| --- | ---: | --- |
| Completion | `94` | The page records exact storage/range and PE zero-fill, all 18 xrefs, all five compiler-lowered writes and thirteen consumers, direct Singleton base/specialization lifetime, source order, one-definition routing, formal CPP/H decisions, rejected owners/forms, and disproved history. |
| Confidence | `96` | Address, runtime bytes, pointer role, COL-proven direct base, specialization lowering, source owner, declaration/definition split, and emitted behavior agree across bounded IDA evidence, executable mapping, class/file/template docs, and adjacent singleton patterns. Confidence is not higher because no original PDB/source proves the initializer token spelling. |

## Cross-References

- [UID:000299][0x0067ab44-0x0067ab48.g_pInputMan](by-memory/0x0067ab44-0x0067ab48.g_pInputMan.md)
- [UID:00006J][InputMan](by-class/InputMan.md)
- [UID:00018E][0x004e8af0-0x004e970d.InputMan](by-memory/0x004e8af0-0x004e970d.InputMan.md)
- [UID:0000K6][InputMan](by-file/InputMan.md)
- [UID:0000HG][Application](by-file/Application.md)
- [UID:0000K5][IMEPanes](by-file/IMEPanes.md)

## Changes

- 2026-08-24 B008 UID0000K6 accepted implementation callback: retained `94/96` and semantic/physical ownership; set direct-file emitter position `0`; expanded formal CPP from the sole definition to that definition followed by exact `Singleton<InputMan>` constructor/destructor specializations; reclassified all publication/ordinary/scalar/unwind writes as compiler lowering of those specializations; documented `0x004e9650` as EH-only/no-source and removed the historical manual-derived/helper source model.

- 2026-08-06 B002 UID000299 accepted callback: created the semantic `g_pInputMan` global page with the sole formal CPP definition, blank H disposition, complete PE/IDA/xref/lifetime evidence, InputMan.cpp/InputMan.h one-definition route, rejected alternatives, and historicalized `0xffffffff` plus temporary direct-file-owner assumptions.
