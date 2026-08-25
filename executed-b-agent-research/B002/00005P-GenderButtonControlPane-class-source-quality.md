** TARGET-REPORT-UID:00005P **
** AUTHOR-AGENT-ID:B002 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 00005P GenderButtonControlPane Class Source-Quality Report

## Finalized Report / Current Recommendation

- FINISHED.
- Assignment: B002 report-only source-quality pass for [UID:00005P] `by-class/GenderButtonControlPane.md`.
- Required output path: `E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\Agent-B002\research\00005P-GenderButtonControlPane-class-source-quality.md`.
- Write-scope status: this pass did not edit any `by-*` documentation file and did not edit `by-memory/-coverage-report.md`. The only intended writes are this report and `Agent-B002/notes.md`.
- Current target metadata: `COMPLETION:85`, `CONFIDENCE:86`, `CANONICAL_OWNER:0000NY`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000NY`, blank `RECONSTRUCTION_CPP CODE`.
- Recommendation: keep `CANONICAL_OWNER:0000NY`, keep `EMITTER_UIDS:0000NY`, and keep current source-family route through [UID:0000NY] `by-file/SpecializedButtonPanes.md` / `auto-generated/NexusTK/ui/controls/SpecializedButtonPanes.cpp`.
- Score recommendation after incorporation: raise [UID:00005P] to `COMPLETION:88`, `CONFIDENCE:89`.
- C++ recommendation: do not populate [UID:00005P] formal `RECONSTRUCTION_CPP CODE` yet. The class is reconstructable and routed, but source-quality blockers remain target-specific: final `ButtonControlPane` base declaration/inheritance shape is not source-quality, the raw constructor has no live route and an unresolved fourth/base-argument type, and the current method carrier [UID:00036V] is a mixed Gender/Direction physical cluster. The report includes a later-use declaration sketch and exact method-child split route, but recommends no formal class C++ insertion during the first implementation callback.
- High-priority correction: existing target/support docs repeatedly say the paint method uses `GENDERBT.EPF`; the local PE scan proves the pushed UTF-16 resource string is `GENDER.EPF` at `0x0061e528`, and no ASCII or UTF-16 `GENDERBT.EPF` string exists in the checked client binary.

## Scope And Instructions Rechecked

- Read and followed:
  - `tools/leaser/Agents/Supervisor.md`.
  - `E:\NTK\GhidraBridge\.codex\AGENTS.md`.
  - `tools/leaser/Agents/Agent-B002/goal.md`.
  - `by-structure.md` and `inference_research.md` guidance for inference, code-entry, source placement, and coverage-row discipline.
  - `by-class/-guidance.md` for class-page scope.
- Active constraints applied:
  - Report-only first pass.
  - No by-* edits.
  - No `by-memory/-coverage-report.md` edit.
  - No `auto-generated`, project-level, tool-state, or coverage file edits.
  - No Wave2/Wave3 generated source was used as authority. Existing by-* docs, validator-generated coverage/source reports, and local PE bytes were used as evidence; generated/Wave references in older docs were treated only as stale-name leads.

## Evidence Checked

### Target And Direct Support Docs

- [UID:00005P] `by-class/GenderButtonControlPane.md`.
- [UID:0000NY] `by-file/SpecializedButtonPanes.md`.
- [UID:0001A4] `by-memory/0x00500640-0x00502755.SpecializedButtonPanes.md`.
- [UID:00036V] `by-memory/0x00500640-0x005008c0.GenderDirectionButtonControlPaneMethods.md`.
- [UID:00036X] `by-memory/0x00502700-0x00502755.GenderButtonControlPaneScalarDeletingDestructor.md`.
- [UID:0002OV] `by-memory/0x0061db8c-0x0061dc30.GenderButtonControlPaneVtableData.md`.
- [UID:0001W7] `by-type/by-struct/SpecializedButtonPaneLayouts.md`.
- [UID:0001YW] `by-type/by-vtable/SpecializedButtonPaneVtables.md`.
- [UID:00009F] `by-class/NewUserMiscDialogPane.md`.
- [UID:0002Q7] `by-memory/0x004fb630-0x004fccee.NewUserMiscDialogPaneCoreAndPacketHelpers.md`.
- [UID:00001E] `by-class/ButtonControlPane.md`.
- [UID:0000HY] `by-file/ButtonControlPane.md`.
- [UID:0003N2] `by-memory/0x00494b80-0x00494bad.ControlPaneSetVisualState.md`.

### Coverage And Generated-State Evidence

- `by-class/-coverage-report.md`: current [UID:00005P] row still says `80%`, stale relative to the target page metadata `85/86`.
- `by-file/-coverage-report.md`: [UID:0000NY] row is current at `86%`, with provisional `NexusTK/ui/controls/` ownership.
- `by-memory/-coverage-report.md`: current rows are stale for this neighborhood:
  - [UID:0001A4] still says reconstructable `82%` and displays stale half-open text `0x00500640-0x00502754`, while the page itself is `RECONSTRUCTABLE:FALSE`, `88/91`, half-open `0x00500640-0x00502755`.
  - [UID:0002OV] still says it was left unassigned because class/file/type parents failed older gate scores, while the page itself is assigned to [UID:00005P] at `86/91`.
  - Current `by-memory/-coverage-report.md` did not surface rows for exact children [UID:00036V] and [UID:00036X] via direct string search, while `tools/tmp-corrupt-by-memory-coverage-report-20260612-140047.md` contains appropriate recovered rows for both exact children.
- `auto-generated/-ag-class-coverage.md`: [UID:00005P] emits through `0000NY` to `auto-generated/NexusTK/ui/controls/SpecializedButtonPanes.cpp`.
- `auto-generated/-ag-memory-coverage.md`: [UID:00036V], [UID:00036X], and [UID:0002OV] emit through the same generated file route.
- `auto-generated/NexusTK/ui/controls/SpecializedButtonPanes.cpp`: current output contains only empty emitter markers for [UID:00005P] and its support children, proving no formal C++ is currently emitted.

### Existing B-Agent Research Checked

- Read [Agent-B004 report] `tools/leaser/Agents/Agent-B004/research/00003X-DirectionButtonControlPane-class-source-quality.md` as sibling evidence only.
- Relevant sibling conclusions validated against Gender evidence instead of copied:
  - Keep [UID:0000NY] `SpecializedButtonPanes` as the current source-family owner/emitter.
  - Treat raw constructor-shaped bodies as byte-real but no-route.
  - Prefer `SetState` / visual-state wording over boolean-only `SetEnabled`.
  - Prefer field name shape `m_*Index` and `m_stateFrameOffset`.
  - Defer formal class C++ until exact method children or final class declarations are accepted.

### IDA/MCP Availability

Attempted current MCP status check:

> Executable block R001 was removed from this report and preserved verbatim in [00005P-GenderButtonControlPane-class-source-quality-removed.md](00005P-GenderButtonControlPane-class-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Result:

- `Invoke-WebRequest : Unable to connect to the remote server`
- No live IDA/MCP calls were available during this B002 pass.
- Replacement evidence used: current IDA-backed by-* docs and a local PE byte/pointer/string scan of the read-only client binary identified below.

### Local PE Binary Recheck

Binary checked:

- Path: `E:\2026\Resources\Read_Only\NexusTK\NexusTK.exe`
- Size: `2679296`
- MD5: `4247e04e20b65d6414c7238aa8ff5515`
- SHA-256: `9aec210bbc5ce592176a21dd8e9d9fd8f250b8d9ea78237915a99ba8cfa9a632`
- Image base: `0x00400000`
- Sections:
  - `.text 0x00401000-0x0060c4ac`, raw `0x400-0x20ba00`
  - `.rdata 0x0060d000-0x0066c0be`, raw `0x20ba00-0x26ac00`
  - `.data 0x0066d000-0x0069ce24`, raw `0x26ac00-0x278400`
  - `.rsrc 0x0069d000-0x006b2c38`, raw `0x278400-0x28e200`

Pointer/branch scan facts:

| Target | Absolute VA hits | RVA hits | Direct `E8`/`E9` branches | Meaning |
| --- | ---: | ---: | --- | --- |
| `0x00500640` | `0` | `0` | none | No direct executable/data route to the raw constructor-shaped body. |
| `0x00500690` | `0` | `0` | none | The tiny `+0x114` accessor has no direct pointer/branch route in the PE scan. |
| `0x005006d0` | `1` at `0x0061dbd8` | `0` | none | Vtable slot only; exact modeled state override. |
| `0x00500700` | `1` at `0x0061dbd4` | `2` incidental RVA-pattern hits at `0x0063477f`, `0x0063dc07` | none | Absolute vtable slot is the meaningful route; RVA-pattern hits are not treated as caller proof. |
| `0x00502700` | `1` at `0x0061db90` | `0` | `0x005024a6`, `0x005024b1` | Vtable destructor slot plus two adjustor-thunk jumps. |
| `0x0061db90` | `4` at `0x004fb7ea`, `0x004fb86b`, `0x00500671`, `0x00502708` | `0` | none | Primary vtable immediate stores in inline setup, raw constructor, and destructor reset. |
| `0x0061dbf8` | `4` at `0x004fb7f4`, `0x004fb875`, `0x0050067b`, `0x00502712` | `0` | none | Secondary vtable immediate stores. |
| `0x0061dc28` | `4` at `0x004fb7fe`, `0x004fb87f`, `0x00500685`, `0x0050271c` | `0` | none | Tertiary vtable immediate stores. |
| `0x004fb630` | `0` | `0` | `0x004fa74e` | Confirms the polluted row is a real NewUserMiscDialogPane constructor call target, not a GenderButtonControlPane method. |

Resource/string scan facts:

| String | ASCII hits | UTF-16 hits | Meaning |
| --- | ---: | ---: | --- |
| `GENDERBT.EPF` | `0` | `0` | Current docs using this spelling are stale for this binary. |
| `GENDER.EPF` | `0` | `1` at `0x0061e528` | Actual resource passed by `GenderButtonControlPane::OnPaint`. |
| `DIREC.EPD` | `0` | `1` at `0x0061e540` | Sibling Direction evidence, matches B004 report. |

Resource/global pointer-hit scan:

| Target | Absolute hits relevant to Gender paint |
| --- | --- |
| `0x0061e528` (`GENDER.EPF`) | `0x00500742`, plus create-user related hits `0x0052c612`, `0x0052c673`, `0x0052dfdf`, `0x0052e03e`. |
| `0x0061e40c` | `0x0050086e` in Direction paint and other rendering sites; not class-owned by Gender. |
| `0x0069b3e8` | includes `0x00500761`; shared draw callback/global, not class-owned. |
| `0x0069b3fc` | includes `0x00500783`; shared disabled/overlay callback/global, not class-owned. |
| `0x0067a744` | includes `0x00500722`; current docs resolve this as `g_pEPFLib`. |

Raw byte slices checked:

```text
0x00500640:
55 8b ec 51 56 ff 75 14 8b f1 89 75 fc e8 5e 48 f9 ff 8b 45 08 89 86 0c 01 00 00 8b 45 0c 89 86 10 01 00 00 8a 45 10 88 86 14 01 00 00 8b c6 c7 06 90 db 61 00 c7 86 a0 00 00 00 f8 db 61 00 c7 86 a4 00 00 00 28 dc 61 00 5e 8b e5 5d c2 10 00

0x00500690:
8a 81 14 01 00 00 c3 cc cc cc cc cc cc cc cc cc

0x005006d0:
55 8b ec 0f be 91 03 01 00 00 53 8b 5d 08 0f b6 c3 3b d0 74 0f 80 fb 0b 75 0a c7 81 10 01 00 00 01 00 00 00 53 e8 86 44 f9 ff 5b 5d c2 04 00 cc

0x00500700:
55 8b ec 83 ec 3c a1 24 2f 67 00 33 c5 89 45 fc 56 8b f1 8d 4d c4 57 e8 44 73 f5 ff 0f 10 46 44 8b 0d 44 a7 67 00 8d 45 c4 50 8b 86 0c 01 00 00 8d 7e 44 0f 11 45 ec 8d 04 40 03 86 10 01 00 00 50 68 28 e5 61 00 e8 a5 fb fc ff 6a 00 6a 00 6a 00 8d 45 ec 8b ce 50 8d 45 d4 50 8d 45 c4 50 ff 15 e8 b3 69 00 80 be 01 01 00 00 00 75 19 68 8f 00 00 00 8b ce e8 e6 8e fb ff 57 8b ce c6 46 70 02 ff 15 fc b3 69 00 8b 4d fc 5f 33 cd 5e e8 9c 6f 0c 00 8b e5 5d c3 cc cc cc cc cc cc cc cc cc

0x00502700:
55 8b ec 56 8b f1 c7 06 90 db 61 00 c7 86 a0 00 00 00 f8 db 61 00 c7 86 a4 00 00 00 28 dc 61 00 e8 5b 1e 04 00 8b 45 08 a8 01 74 22 a8 04 75 10 56 e8 8a 23 ff ff 83 c4 04 8b c6 5e 5d c2 04 00 68 18 01 00 00 56 e8 55 8f f1 ff 83 c4 08 8b c6 5e 5d c2 04 00
```

Inline `NewUserMiscDialogPane` setup byte slices checked:

```text
0x004fb7d0:
c4 18 89 7d c8 c6 45 fc 05 85 ff 74 42 8d 45 e0 8b cf 50 e8 c8 96 f9 ff c7 07 90 db 61 00 c7 87 a0 00 00 00 f8 db 61 00 c7 87 a4 00 00 00 28 dc 61 00 c7 87 0c 01 00 00 00 00 00 00 c7 87 10 01 00 00 02 00 00 00 c6 87 14 01 00 00 01 ...

0x004fb850:
83 c4 18 89 7d c8 c6 45 fc 06 85 ff 74 42 8d 45 e0 8b cf 50 e8 47 96 f9 ff c7 07 90 db 61 00 c7 87 a0 00 00 00 f8 db 61 00 c7 87 a4 00 00 00 28 dc 61 00 c7 87 0c 01 00 00 01 00 00 00 c7 87 10 01 00 00 00 00 00 00 c6 87 14 01 00 00 00 ...
```

These slices prove the two inline child setup variants:

- First setup writes gender vtables, `+0x10c = 0`, `+0x110 = 2`, `+0x114 = 1`.
- Second setup writes gender vtables, `+0x10c = 1`, `+0x110 = 0`, `+0x114 = 0`.

## Current Target State

The target page is already broadly correct about the class existence, owner route, vtable family, raw constructor caveat, inline setup pollution, and destructor/thunk split. It is incomplete or stale in these source-quality areas:

- The class coverage row is stale at `80%` even though the target page metadata is `85/86`.
- The target/support docs use the stale resource spelling `GENDERBT.EPF`; PE evidence proves `GENDER.EPF`.
- Field names remain generic: "gender index", "visual-state frame offset", "selected/default flag". They can be upgraded to source-facing descriptive names.
- The tiny accessor at `0x00500690` is listed but its no-route status and likely source-facing role are not fully resolved.
- The raw constructor is correctly marked `NOFUNC`/no-xref in current docs, but the final interpretation should be tightened: it is source-shaped byte code with a complete four-argument constructor ABI, not just an uncertain boundary; however it still has no proven live route.
- The class-level C++ block is blank. The report needs a target-specific decision, not just "pending".
- The memory coverage report is stale for the surrounding aggregate and vtable child, and appears to be missing rows for exact child splits [UID:00036V] and [UID:00036X].

## Function / Child Inventory

| Range / Item | UID / Path | Role | Current route | Current score | Recommendation |
| --- | --- | --- | --- | --- | --- |
| Class page | [UID:00005P] `by-class/GenderButtonControlPane.md` | Gender selection button class | [UID:0000NY] `SpecializedButtonPanes` | `85/86` | Raise to `88/89`; keep route; no formal C++ yet. |
| `0x00500640-0x00500690` | inside [UID:00036V] | Raw constructor-shaped body | [UID:0000NY] through mixed method cluster | [UID:00036V] `86/88` | Keep as source-shaped/no-route constructor evidence; do not emit constructor now. |
| `0x00500690-0x00500697` | inside [UID:00036V] | Tiny accessor returning byte `+0x114` | [UID:0000NY] through mixed method cluster | [UID:00036V] `86/88` | Best descriptive name `IsDefaultSelected()` / `GetDefaultSelectedFlag()`; no direct route found. |
| `0x00500697-0x005006a0` | [UID:0000VN] ignored padding | Alignment | ignored | `100` ignored | Keep ignored. |
| `0x005006d0-0x005006ff` | inside [UID:00036V] | Gender visual-state override | [UID:0000NY] through mixed method cluster | [UID:00036V] `86/88` | Prefer `SetState` / `SetVisualState` wording; behavior-ready if exact child split occurs. |
| `0x00500700-0x00500797` | inside [UID:00036V] | Gender paint override | [UID:0000NY] through mixed method cluster | [UID:00036V] `86/88` | Correct resource to `GENDER.EPF`; behavior-ready if exact child split occurs. |
| `0x00500797-0x005007a0` | [UID:0000VN] ignored padding | Alignment before Direction constructor | ignored | `100` ignored | Keep ignored. |
| `0x005024a0-0x005024ab` | [UID:0000VN] ignored thunk | Secondary adjustor into `0x00502700` | ignored | ignored | Compiler-generated; not source method. |
| `0x005024ab-0x005024b6` | [UID:0000VN] ignored thunk | Tertiary adjustor into `0x00502700` | ignored | ignored | Compiler-generated; not source method. |
| `0x00502700-0x00502755` | [UID:00036X] `GenderButtonControlPaneScalarDeletingDestructor` | MSVC scalar deleting destructor wrapper | [UID:00005P] | `86/90` | Keep exact; no handwritten method C++. |
| `0x0061db8c-0x0061dc30` | [UID:0002OV] `GenderButtonControlPaneVtableData` | RTTI/vtable data | [UID:00005P] | `86/91` | Keep exact; vtables regenerated from class declaration, not hand-ported. |

## Heuristic / Inference Reanalysis And Validation

### Raw Constructor Reachability And Source Shape `0x00500640-0x00500690`

- Existing target label: `GenderButtonControlPane` constructor-shaped body.
- Current evidence:
  - Existing IDA-backed docs repeatedly report `0x00500640` as `NOFUNC`, no xrefs/callers, no raw pointer hits.
  - Current local PE scan found zero absolute VA hits, zero RVA hits, and zero direct `E8`/`E9` branch hits to `0x00500640`.
  - Raw bytes form a complete normal `thiscall` constructor-shaped body: stack frame, `esi = this`, `push [ebp+0x14]`, call to base constructor `0x00494eb0`, writes arguments into `this+0x10c`, `this+0x110`, byte `this+0x114`, installs primary/secondary/tertiary vtables, returns `ret 0x10`.
  - Immediate vtable store hits include `0x00500671`, `0x0050067b`, and `0x00500685`, matching the raw body.
- Best source-facing inference:
  - This is a real source-shaped out-of-line constructor body for `GenderButtonControlPane`, but no live call route is proven in the checked binary. The most likely explanation is an unused out-of-line constructor copy while observed construction sites inline the equivalent setup. A weaker alternative is that the source constructor exists but all source call sites in this binary were optimized/expanded into inline setup.
  - Inferred descriptive constructor signature shape: `GenderButtonControlPane(int genderIndex, int stateFrameOffset, bool defaultSelected, <base constructor argument>)`. The fourth parameter type is not safe; byte evidence only proves it is passed directly to `ButtonControlPane` constructor `0x00494eb0`.
- Rejected alternatives:
  - "Padding or accidental disassembly": rejected because the body has a valid prologue, base constructor call, field stores, vtable installs, and a stdcall-style `ret 0x10`.
  - "Active constructor called by NewUserMiscDialogPane": rejected because the NewUserMisc constructor writes equivalent setup inline; local PE scan found no branch/pointer route to `0x00500640`.
  - "NewUserMiscDialogPane owns the constructor": rejected because vtables and virtual methods prove a reusable class; NewUserMisc is a construction consumer/inline setup site.
- C++ impact:
  - Do not emit the constructor body now. Formal source would need the final base constructor argument type and a policy for no-route out-of-line constructor artifacts.

### Inline Setup Versus Real Constructor

- Existing docs correctly say `NewUserMiscDialogPane` inlines gender child setup.
- Local PE byte slices tighten the exact values:
  - First setup around `0x004fb7d0` writes primary/secondary/tertiary gender vtables and fields `+0x10c = 0`, `+0x110 = 2`, `+0x114 = 1`.
  - Second setup around `0x004fb850` writes the same vtables and fields `+0x10c = 1`, `+0x110 = 0`, `+0x114 = 0`.
- Inference:
  - Inline setup is the observed runtime construction path for two gender choice buttons in the new-user customization dialog.
  - The field triplet likely represents gender frame group, initial/default frame offset, and initially-selected/default flag.
- Ownership impact:
  - Inline setup is consumer evidence only. It explains generated owner pollution but does not transfer class ownership to `NewUserMiscDialogPane`.

### Field Names And Types

Recommended source-facing field names for [UID:00005P]:

| Offset | Current wording | Recommended name | Type | Evidence |
| ---: | --- | --- | --- | --- |
| `+0x10c` | gender index | `m_genderIndex` | `int` | Constructor and inline setup store dwords `0` or `1`; paint computes `3 * m_genderIndex + m_stateFrameOffset`; class/resource role is gender selection. |
| `+0x110` | visual-state frame offset | `m_stateFrameOffset` preferred, `m_visualStateFrameOffset` acceptable in prose | `int` | Constructor/inline setup store dwords `2` or `0`; `SetState` writes dword `1` only when incoming state byte is `0x0b`; paint adds it to `3 * m_genderIndex`. |
| `+0x114` | selected/default flag | `m_defaultSelected` or `m_initiallySelected`; use `m_defaultSelected` in compact tables and explain it is inferred | `bool` / byte | Constructor stores byte argument; inline setup writes `1` for the initially selected/default gender button and `0` for the other; accessor at `0x00500690` returns this byte. |

Rejected field names:

- `m_gender`: acceptable shorthand in prose but less precise than `m_genderIndex` because the value is used as a frame-group index.
- `m_frameIndex`: rejected for `+0x10c` because final frame is computed with `+0x110`.
- `m_enabled`: rejected for `+0x110` because it is a sprite frame offset, not the inherited enabled flag.
- `m_pressed`: too specific for `+0x110`; state byte `0x0b` may correspond to pressed/hover/active depending on the base control state enum, but this pass did not prove final enum names.
- `m_selected`: risky for `+0x114` because base `ButtonControlPane` already has selected-state evidence around `+0x108`; `+0x114` is better described as the subclass default/initial-selection flag until a caller proves a stronger name.

### Tiny Accessor `0x00500690-0x00500697`

- Behavior from raw bytes: `mov al, [ecx+0x114]; ret`.
- Current local PE scan: zero absolute VA hits, zero RVA hits, zero direct branch hits to `0x00500690`.
- Existing docs: IDA recognizes it as a modeled function, but no direct route is documented.
- Best source-facing inference:
  - Descriptive names: `IsDefaultSelected()` or `GetDefaultSelectedFlag()`. Prefer `IsDefaultSelected()` for class prose if returning a `bool`, but keep "descriptive, original spelling unproved" in docs.
  - Treat it as an unused/no-route out-of-line accessor over the default/initial-selection byte unless a future caller/vtable route is found.
- Rejected alternatives:
  - `GetGender()`: rejected because the gender index is at `+0x10c`, not `+0x114`.
  - `IsSelected()`: rejected as final name because base button selected state likely lives elsewhere (`+0x108` in ButtonControlPane); `+0x114` is initialized asymmetrically only by gender setup.
- C++ impact:
  - Do not emit this accessor body from the class page. If [UID:00036V] is later split, this can be an exact tiny child with a very small method-body C++ draft or a no-route note.

### State Method `0x005006d0-0x005006ff`

- Existing target name: `SetState`.
- Best source-facing name: `SetState(unsigned char state)` or `SetVisualState(unsigned char state)`. Keep `SetState` for consistency with current target and B004 sibling report.
- Evidence:
  - Vtable absolute hit at `0x0061dbd8`.
  - Raw bytes compare inherited byte `this+0x103` against incoming state byte.
  - If state changed and incoming state is `0x0b`, writes dword `1` to `this+0x110`.
  - Delegates to `0x00494b80`, documented as [UID:0003N2] `ControlPaneSetVisualState`, with the same state byte.
- Important correction:
  - Do not describe the method as simply "SetEnabled". The method consumes a byte visual/control state, not a boolean. The existing docs that say "state/key `0x0b`" should be normalized to "state byte `0x0b`"; no keyboard key is proven by this method.
- Remaining uncertainty:
  - The final enum name for state `0x0b` remains outside this target. It may be pressed/hover/active depending on base control semantics; docs should not over-name it.

### Paint Method `0x00500700-0x00500797`

- Best source-facing name: `OnPaint()`.
- Evidence:
  - Vtable absolute hit at `0x0061dbd4`.
  - Paint copies/draws using inherited bounds at `this+0x44`.
  - Uses `g_pEPFLib` pointer/global at `0x0067a744`.
  - Computes frame index as `3 * m_genderIndex + m_stateFrameOffset`.
  - Pushes UTF-16 `GENDER.EPF` at `0x0061e528`; no `GENDERBT.EPF` string exists in the checked PE.
  - Calls resource/layout lookup `0x004d02f0` and draw callback `0x0069b3e8`.
  - Tests byte `this+0x101`; if zero, calls disabled/overlay helper with `0x8f`, writes byte `this+0x70 = 2`, and calls callback `0x0069b3fc` with the bounds/rect view.
- Helper/global naming recommendations:
  - Use [UID:0000QU] `g_pEPFLib` instead of `dword_67A744`.
  - Use [UID:0002KP] `ResourceLayoutTableLookupLayoutEntry` or descriptive "resource layout lookup" for `0x004d02f0`.
  - Keep `0x0069b3e8`, `0x0069b3fc`, and `0x004b9660` descriptive if no current exact owner page is being edited in the callback; they are shared render callback/helper infrastructure, not Gender-owned fields.
- Rejected alternatives:
  - `GENDERBT.EPF`: rejected by current PE string scan and paint byte `push 0x0061e528`.
  - `GENDER.EPF` as class-owned resource declaration: not proven. It is a string/resource literal used here and also by newer create-user code; direct resource ownership likely belongs to the account-creation/resource family, while this class consumes it.

### Destructor And Thunks

- `0x005024a0` and `0x005024ab`: compiler-generated adjustor thunks. They jump into `0x00502700` after receiver adjustment and should stay in ignored/thunk docs, not source method lists.
- `0x00502700-0x00502755`: MSVC scalar deleting destructor wrapper.
- Evidence:
  - Vtable absolute hit `0x0061db90`.
  - Direct branch hits from thunks `0x005024a6` and `0x005024b1`.
  - Resets primary/secondary/tertiary vtables to `0x0061db90`, `0x0061dbf8`, `0x0061dc28`.
  - Calls base teardown `0x00544580`.
  - If `(flags & 1) == 0`, returns `this`.
  - If `(flags & 1) != 0` and `(flags & 4) == 0`, calls delete helper `0x004f4ac0(this)`.
  - If `(flags & 4) != 0`, calls guarded/vector helper with object size `0x118`.
- Source-shape recommendation:
  - Do not hand-write a scalar deleting destructor in final NexusTK C++. Model a normal `~GenderButtonControlPane()` declaration/body only when exact base destructor and class declaration quality are ready; let MSVC regenerate wrapper/thunks/vtable resets.

### Vtable / Base Layout

- Object size: `0x118`, supported by inline allocation/setup and scalar destructor guarded-helper object size.
- Base: strongest current source-facing base is `ButtonControlPane`, itself deriving through `ControlPane` / `Pane` control layout. Evidence:
  - Raw constructor calls `0x00494eb0`, documented as `ButtonControlPane::ButtonControlPane`.
  - `ButtonControlPane` constructor call fan-in includes raw code refs from gender/direction constructor-shaped starts and inline setup in `NewUserMiscDialogPane`.
  - State method delegates to [UID:0003N2] `ControlPaneSetVisualState`.
- Multiple-vtable layout:
  - Primary vptr at `+0x00`.
  - Secondary vptr at `+0xa0`.
  - Tertiary vptr at `+0xa4`.
  - These are compiler/object-layout views, not ordinary source data members.
- Inherited fields:
  - `+0x44` bounds/draw rectangle, owned by base ControlPane/ButtonControlPane layout.
  - `+0x101` inherited enabled/visible/draw-state byte tested by paint.
  - `+0x103` inherited visual/control state byte consumed before base `SetVisualState`.
  - `+0x70` inherited draw/render mode byte written during disabled overlay path.
- Remaining blocker:
  - The final source-level inheritance declaration is not ready because [UID:00001E] `ButtonControlPane` itself keeps its formal C++ blank pending base layout/source-quality field names. Gender should not leapfrog the base class with a pretend-final class declaration.

### Owner-Pollution Exclusion

- Polluted/generated row: `0x004fb630-0x004fbfcf`.
- Confirmed owner: [UID:00009F] / [UID:0000LX] `NewUserMiscDialogPane`.
- Evidence:
  - Existing IDA-backed docs: `0x004fb630` is `NewUserMiscDialogPane::NewUserMiscDialogPane`, size `0x99f`, called from `0x004fa74e`.
  - Current local PE scan found one direct branch to `0x004fb630` from `0x004fa74e`, and no direct branch/pointer route tying it to `GenderButtonControlPane`.
  - The only reason it mentions Gender is inline child-control setup and immediate stores of the Gender vtables at `0x004fb7ea`, `0x004fb7f4`, `0x004fb7fe`, `0x004fb86b`, `0x004fb875`, and `0x004fb87f`.
- Recommendation:
  - Keep `0x004fb630` out of Gender method inventory except as inline setup/consumer evidence.
  - If generated or support docs still imply `0x004fb630` is a Gender method, move that into stale/generated-owner-pollution notes.

### Source Placement

Ranked source-placement decision:

1. Keep [UID:0000NY] `SpecializedButtonPanes` / `NexusTK/ui/controls/` as current owner/emitter.
   - Evidence for: file page is `86/88`, valid projected path, explicit specialized-control bucket for Direction/Gender/CheckBox, current autogen route exists, class and support children already emit through it, and it records future split caveats.
   - Evidence against: final original filename may not literally be `SpecializedButtonPanes.cpp`; the bucket is provisional.
   - Decision: keep as current direct route.
2. Future `GenderButtonControlPane.cpp`.
   - Evidence for: the class has own vtables, resource-specific paint, state override, destructor, and fields.
   - Evidence against: no original source filename/compilation-unit evidence proves a separate file; project docs intentionally keep the provisional bucket.
   - Decision: note as future split candidate only, not current route.
3. `NewUserMiscDialogPane.cpp`.
   - Evidence for: observed inline setup constructs two gender buttons.
   - Evidence against: construction consumer only; reusable class vtables/methods/destructor prove separate control class; NewUserMisc already owns its own constructor and packet helpers.
   - Decision: reject as owner.
4. `ButtonControlPane.cpp`.
   - Evidence for: base constructor and visual-state helper dependencies.
   - Evidence against: base dependency, not subclass owner. Gender owns subclass fields/resource/vtables.
   - Decision: reject as direct owner; keep as base dependency.
5. `MainMenuNewUserReadOnlyData` / vtable aggregate.
   - Evidence for: contains Gender vtable data and nearby resource strings.
   - Evidence against: mixed non-emitting `.rdata` aggregate; exact vtable child routes to class.
   - Decision: reject as owner.

### Split / Range Decisions

- Keep [UID:00005P] as a class page, not a by-memory split target.
- Keep [UID:00036X] destructor exact; no split needed.
- Keep [UID:0002OV] vtable data exact; no split needed.
- [UID:00036V] is exact physically but mixed as a source-emission unit. It contains both Gender and Direction methods plus padding.
- Recommended later split if method C++ is accepted:
  - `0x00500640-0x00500690` `GenderButtonControlPaneConstructorRaw` - no-code/no-route source-shaped constructor evidence.
  - `0x00500690-0x00500697` `GenderButtonControlPaneIsDefaultSelected` - tiny accessor, no-route unless a caller is later found.
  - `0x005006d0-0x005006ff` `GenderButtonControlPaneSetState` - behavior-ready exact method child.
  - `0x00500700-0x00500797` `GenderButtonControlPaneOnPaint` - behavior-ready exact method child after resource string correction.
  - Preserve `0x00500697-0x005006a0` and `0x00500797-0x005007a0` as ignored padding.
  - Coordinate with B004 Direction recommendation for sibling splits inside the same [UID:00036V] physical cluster.
- Do not emit partial Gender method C++ from [UID:00036V] without either splitting or a full cluster-level source plan, because the current child spans two classes.

## First-Draft C++ Recommendation / Target-Specific Defer Proof

### Recommendation

Do not populate [UID:00005P] formal `RECONSTRUCTION_CPP CODE` in the first implementation callback.

### Why The Minimum Route Is Not Enough Here

[UID:00005P] technically has `RECONSTRUCTABLE:TRUE`, nonblank `EMITTER_UIDS:0000NY`, and average score above `85`. That makes it a candidate for C++ review, but not a safe insertion target yet. The blockers are target-specific and source-quality, not generic:

- Class pages should emit class-level declarations, not method bodies. The behavior-ready source bodies are in by-memory method ranges, and [UID:00036V] is still a mixed Gender/Direction cluster.
- The final base class declaration is not ready. [UID:00001E] `ButtonControlPane` itself has blank C++ because its exact inheritance/subobject view and field map remain below source-quality.
- `GenderButtonControlPane` raw constructor has a four-argument ABI shape, but the fourth/base constructor argument type is unknown and no live route to the constructor exists.
- Writing a constructor declaration with guessed parameter types would make a no-route artifact look more source-certain than the evidence supports.
- Writing method declarations without a settled base class and without exact method children would be a low-value shell that still fails Rule 24 source-readiness.
- Existing target/support docs must first correct `GENDERBT.EPF` to `GENDER.EPF`, or any inserted paint-related C++ would immediately bake in a proven stale resource name.

### Later Declaration Sketch, Not For Immediate Formal Insertion

Use this only as a later source-shape guide after the base class declaration and exact method children are accepted:

```cpp
class GenderButtonControlPane : public ButtonControlPane
{
public:
    // Constructor parameter spelling and the base-argument type remain unresolved.
    // Raw bytes prove: (genderIndex, stateFrameOffset, defaultSelected, baseCtorArg).
    GenderButtonControlPane(/* base ctor arg unresolved */);
    virtual ~GenderButtonControlPane();

    bool IsDefaultSelected() const;
    virtual void SetState(unsigned char state);
    virtual void OnPaint();

private:
    int m_genderIndex;        // +0x10c
    int m_stateFrameOffset;   // +0x110; frame offset added to 3 * gender index
    bool m_defaultSelected;   // +0x114; inferred default/initial selected flag
};
```

Do not insert this sketch verbatim. It intentionally contains an unresolved constructor placeholder and would not meet the source-quality standard for formal reconstruction.

## Score / Metadata Recommendation

Recommended target metadata after accepted implementation:

```text
COMPLETION:88
CONFIDENCE:89
CANONICAL_OWNER:0000NY
RECONSTRUCTABLE:TRUE
EMITTER_UIDS:0000NY
RECONSTRUCTION_CPP CODE: blank
```

Justification:

- Completion `88`: target can incorporate exact PE scan facts, raw constructor ABI, inline setup values, resource spelling correction, field names, accessor no-route role, state/paint/destructor behavior, owner-pollution exclusion, source-placement ranking, split policy, and no-code proof.
- Confidence `89`: class identity/source route/fields/vtables/destructor/inline setup are corroborated by current by-* docs and local PE bytes. Confidence stays below `90+` because live IDA/MCP was unavailable during this pass, the constructor route remains unproved, and formal base/class C++ remains deferred.
- Keep owner/emitter: [UID:0000NY] is current best direct source-family route and already surfaces to generated output.
- Keep reconstructable: this is project-owned UI control code; the blank C++ recommendation is source-quality defer, not non-reconstructable classification.

## Exact Implementation Checklist For Later Callback

### Target [UID:00005P] `by-class/GenderButtonControlPane.md`

- Update scores to `88/89`.
- Keep `CANONICAL_OWNER:0000NY`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000NY`.
- Keep formal `RECONSTRUCTION_CPP CODE` blank and add the target-specific no-code/defer proof from this report.
- Correct resource references from `GENDERBT.EPF` to `GENDER.EPF`.
- Add current local PE evidence:
  - binary path/hash/sections,
  - zero VA/RVA/rel32 route to `0x00500640`,
  - zero VA/RVA/rel32 route to `0x00500690`,
  - vtable-only refs for `0x005006d0` and `0x00500700`,
  - thunk/vtable refs for `0x00502700`,
  - immediate vtable stores to `0x0061db90/0x0061dbf8/0x0061dc28`,
  - actual UTF-16 `GENDER.EPF` at `0x0061e528`.
- Record exact raw constructor argument/field behavior:
  - base constructor argument passed to `0x00494eb0`,
  - `+0x10c` from first argument,
  - `+0x110` from second argument,
  - `+0x114` from third byte argument,
  - `ret 0x10`.
- Record inline setup values:
  - first button `+0x10c=0`, `+0x110=2`, `+0x114=1`;
  - second button `+0x10c=1`, `+0x110=0`, `+0x114=0`.
- Rename field hypotheses:
  - `+0x10c` -> `m_genderIndex`,
  - `+0x110` -> `m_stateFrameOffset` / `m_visualStateFrameOffset`,
  - `+0x114` -> `m_defaultSelected` / `m_initiallySelected`, with exact evidence and rejection of stronger unproved names.
- Name method roles:
  - `0x00500690` -> descriptive `IsDefaultSelected()` / `GetDefaultSelectedFlag()` accessor; no direct route currently found.
  - `0x005006d0` -> `SetState` / `SetVisualState`, not boolean-only `SetEnabled`.
  - `0x00500700` -> `OnPaint()`.
- Clarify `NewUserMiscDialogPane` as construction consumer/inline setup owner-pollution source, not direct owner.
- Add later split recommendation for exact Gender method children inside [UID:00036V].

### Support [UID:00036V] `by-memory/0x00500640-0x005008c0.GenderDirectionButtonControlPaneMethods.md`

- Add Gender-specific local PE scan facts for `0x00500640`, `0x00500690`, `0x005006d0`, `0x00500700`, and `0x0061db90/0x0061dbf8/0x0061dc28`.
- Correct Gender paint resource to `GENDER.EPF`.
- Add inline setup byte/value details for both gender buttons.
- Upgrade field names to `m_genderIndex`, `m_stateFrameOffset`, and `m_defaultSelected`.
- Note that `0x00500690` currently has no direct route.
- Add exact split recommendation for Gender and Direction method children if method C++ is later accepted.
- Keep current [UID:00036V] formal C++ blank unless the mixed cluster is split or a full cluster-level source plan is explicitly accepted.

### Support [UID:00036X] `by-memory/0x00502700-0x00502755.GenderButtonControlPaneScalarDeletingDestructor.md`

- Add the local PE recheck details:
  - vtable hit `0x0061db90`,
  - thunk branches `0x005024a6` and `0x005024b1`,
  - vtable reset stores at `0x00502708`, `0x00502712`, `0x0050271c`,
  - base teardown `0x00544580`,
  - delete helper `0x004f4ac0`,
  - guarded/vector helper with size `0x118`.
- Preserve no-code proof: compiler scalar deleting destructor wrapper and adjustor thunks should be regenerated, not hand-written.

### Support [UID:0002OV] `by-memory/0x0061db8c-0x0061dc30.GenderButtonControlPaneVtableData.md`

- Add PE scan confirmation that `0x0061db90`, `0x0061dbf8`, and `0x0061dc28` each have four immediate store hits from inline setup, raw constructor, and destructor reset.
- Preserve source-declared/generated-binary handling for vtable data.
- Ensure the page and coverage language no longer say it is unassigned due old parent-gate failure.

### Support [UID:0001W7] `by-type/by-struct/SpecializedButtonPaneLayouts.md`

- Correct resource text for Gender from `GENDERBT.EPF` to `GENDER.EPF`.
- Synchronize field names:
  - `m_genderIndex`,
  - `m_stateFrameOffset` / `m_visualStateFrameOffset`,
  - `m_defaultSelected` / `m_initiallySelected`.
- Keep inherited fields owned by ControlPane/ButtonControlPane.
- Record no-route status for the raw constructor and accessor as source-quality caveats, not generic open questions.

### Support [UID:0001YW] `by-type/by-vtable/SpecializedButtonPaneVtables.md`

- No metadata change required.
- Optionally add the current PE vtable store hits for the Gender table bases.
- Preserve adjustor thunks as compiler-generated glue.

### Support [UID:0000NY] `by-file/SpecializedButtonPanes.md`

- No owner/path change.
- Add a short source-quality note:
  - Gender docs corrected to `GENDER.EPF`;
  - [UID:00005P] keeps current route through this provisional source-family bucket;
  - future split candidates remain `GenderButtonControlPane.cpp`, `DirectionButtonControlPane.cpp`, and `CheckBoxTextControlPane.cpp`;
  - method-body C++ should wait for exact method-child splits or final class declaration policy.

### Support [UID:00009F] / [UID:0002Q7] `NewUserMiscDialogPane`

- Only update if callback scope includes support docs:
  - Add the exact Gender inline setup values from the byte slices.
  - Clarify they are consumer setup, not Gender method ownership.
  - Keep `0x004fb630` as NewUserMisc constructor.

### Generated Docs / Autogen

- Do not edit generated C++ by hand.
- After accepted by-* edits, run the exact validator commands below so generated marker state refreshes normally.
- Expected generated state if no C++ is inserted: `auto-generated/NexusTK/ui/controls/SpecializedButtonPanes.cpp` should still contain empty markers for [UID:00005P], [UID:00036V], [UID:00036X], [UID:0002OV], and related support pages, but completion/confidence metadata in marker comments should update if target/support scores change.

## Exact Coverage Row Text

### Current `by-class/-coverage-report.md` Row

Current row at `by-class/-coverage-report.md:230`:

```markdown
- [UID:00005P][GenderButtonControlPane](by-class/GenderButtonControlPane.md) : reconstructable : 80% : strong : Live IDA MCP reconfirmed `0x00500640` as a raw `NOFUNC`/no-xref constructor-shaped start, modeled accessor/state/paint/destructor functions at `0x00500690`/`0x005006d0`/`0x00500700`/`0x00502700`, vtable refs at `0x0061dbd8`/`0x0061dbd4`/`0x0061db90`, inline `NewUserMiscDialogPane` setup stores and owner-pollution guard, state delegation through `0x00494b80`, resource/render paint callees, destructor cleanup/delete callees, and final C++ blank pending raw-constructor and inherited-slot naming resolution.
```

Recommended replacement:

```markdown
- [UID:00005P][GenderButtonControlPane](by-class/GenderButtonControlPane.md) : reconstructable : 88% : strong : B002 2026-06-19 source-quality reanalysis keeps [UID:0000NY][SpecializedButtonPanes](by-file/SpecializedButtonPanes.md) as the current provisional `NexusTK/ui/controls/` owner/emitter and closes the major source-facing questions: `0x00500640-0x00500690` is a source-shaped but no-route constructor body with zero VA/RVA/rel32 refs, `0x00500690-0x00500697` is a no-route `m_defaultSelected` accessor, `0x005006d0-0x005006ff` is best documented as `SetState`/visual-state override, `0x00500700-0x00500797` is the `GENDER.EPF` paint override using `g_pEPFLib`/`ResourceLayoutTableLookupLayoutEntry`, fields `+0x10c/+0x110/+0x114` are `m_genderIndex`, `m_stateFrameOffset`, and inferred `m_defaultSelected`, vtable child [UID:0002OV] and destructor child [UID:00036X] prove the class layout/compiler glue, `0x004fb630` remains NewUserMiscDialogPane owner-pollution/inline setup evidence only, and final C++ remains blank until exact Gender method children or a final base/class declaration route are accepted.
```

### Supervisor-Owned `by-memory/-coverage-report.md` Rows

Do not let B002 edit `by-memory/-coverage-report.md`. These are exact supervisor-owned row recommendations if the supervisor chooses to repair the stale memory coverage discovered during this class pass.

Current stale aggregate row at `by-memory/-coverage-report.md:2148`:

```markdown
    - [UID:0001A4][0x00500640-0x00502755.SpecializedButtonPanes](by-memory/0x00500640-0x00502755.SpecializedButtonPanes.md) 0x00500640-0x00502754 | aggregate/control cluster | SpecializedButtonPanes : reconstructable : 82% : strong : Mixed source-owner aggregate for raw gender/direction constructors, modeled virtual methods, vtable refs, adjustor/destructor tail, contained BlueAlert/UserCreate child clusters, and corrected-gate parent blocker; raw constructor starts still have no IDA function, xrefs, or pointer hits.
```

Recommended replacement:

```markdown
    - [UID:0001A4][0x00500640-0x00502755.SpecializedButtonPanes](by-memory/0x00500640-0x00502755.SpecializedButtonPanes.md) 0x00500640-0x00502755 | mixed executable index | SpecializedButtonPanes : not_reconstructable : 88% : strong : Reviewed non-emitting mixed-owner container over specialized-control children, BlueAlertPane code, user-create appearance controls, singleton-clear helpers, compiler adjustor thunks, and exact direction/gender scalar deleting destructors; exact children carry source or ignored ownership, raw gender/direction constructor-shaped starts remain no-route, and no single direct parent owns the whole span.
```

Recommended insertion under the [UID:0001A4] aggregate, if the row is missing:

```markdown
        - [UID:00036V][0x00500640-0x005008c0.GenderDirectionButtonControlPaneMethods](by-memory/0x00500640-0x005008c0.GenderDirectionButtonControlPaneMethods.md) 0x00500640-0x005008c0 | executable method cluster | GenderDirectionButtonControlPaneMethods : reconstructable : 86% : strong : Exact child split for gender/direction reusable control methods; docs and B002/B004 source-quality passes confirm modeled accessor/state/paint functions and vtable refs, raw constructor-shaped starts at `0x00500640`/`0x005007a0` with no VA/RVA/rel32 route, Gender paint uses `GENDER.EPF`, Direction paint uses `DIREC.EPD`, and direct file parent [UID:0000NY][SpecializedButtonPanes](by-file/SpecializedButtonPanes.md) clears `85/85`.
```

Recommended insertion/replacement for the exact Gender destructor child:

```markdown
    - [UID:00036X][0x00502700-0x00502755.GenderButtonControlPaneScalarDeletingDestructor](by-memory/0x00502700-0x00502755.GenderButtonControlPaneScalarDeletingDestructor.md) 0x00502700-0x00502755 | scalar deleting destructor | GenderButtonControlPaneScalarDeletingDestructor : reconstructable : 86% : strong : Exact destructor child and corrected aggregate endpoint with thunk branches at `0x005024a6`/`0x005024b1`, primary vtable ref `0x0061db90`, vtable reset stores at `this+0x00/+0xa0/+0xa4`, base teardown through `0x00544580`, guarded delete/free paths through `0x004f4ac0` and `0x0041b6a0` with object size `0x118`, and direct class parent [UID:00005P][GenderButtonControlPane](by-class/GenderButtonControlPane.md) clearing `85/85`.
```

Current stale vtable child row at `by-memory/-coverage-report.md:3720` says it was left unassigned due old parent-gate scores. Recommended replacement:

```markdown
        - [UID:0002OV][0x0061db8c-0x0061dc30.GenderButtonControlPaneVtableData](by-memory/0x0061db8c-0x0061dc30.GenderButtonControlPaneVtableData.md) 0x0061db8c-0x0061dc30 | vtable-data | GenderButtonControlPaneVtableData : reconstructable : 86% : very strong : Exact source-declared/generated-binary vtable-data child assigned to [UID:00005P][GenderButtonControlPane](by-class/GenderButtonControlPane.md); records the `0xa4` range, primary/secondary/tertiary RTTI-adjacent words and table bases `0x0061db90`/`0x0061dbf8`/`0x0061dc28`, key slots for scalar deleting destructor `0x00502700`, paint `0x00500700`, state override `0x005006d0`, adjustor thunks `0x005024a0`/`0x005024ab`, inline setup/raw constructor/destructor reset store refs, and boundary before `DirectionButtonControlPane`.
```

## Exact Validator Commands

No validator command was run during this report-only pass because the user limited writes to this report and `Agent-B002/notes.md`; normal file scans refresh autogen/coverage state and may modify files outside that write scope.

Exact commands to run during the implementation callback after accepted by-* edits:

> Executable block R002 was removed from this report and preserved verbatim in [00005P-GenderButtonControlPane-class-source-quality-removed.md](00005P-GenderButtonControlPane-class-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

If the supervisor also applies `by-class/-coverage-report.md` and `by-memory/-coverage-report.md` row fixes, run scoped file validators for those coverage reports if the validator accepts report files:

> Executable block R003 was removed from this report and preserved verbatim in [00005P-GenderButtonControlPane-class-source-quality-removed.md](00005P-GenderButtonControlPane-class-source-quality-removed.md). The archived block is non-authoritative and must not be executed.

Expected post-implementation validator result:

- Exit code `0`.
- `ok: 1` for each scoped file scan.
- Generated `auto-generated/NexusTK/ui/controls/SpecializedButtonPanes.cpp` remains marker-only unless the supervisor explicitly accepts formal C++ insertion.

## Changed Files In This Report-Only Pass

Created:

- `E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\Agent-B002\research\00005P-GenderButtonControlPane-class-source-quality.md`

Modified:

- `E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\Agent-B002\notes.md`

Not edited:

- No `by-*` documentation file was edited.
- `by-memory/-coverage-report.md` was not edited.
- `by-class/-coverage-report.md` was not edited.
- No generated file was edited.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B002","command_id":"000000004165","destination_path":"executed-b-agent-research/B002/00005P-GenderButtonControlPane-class-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:23","uid":"00005P"} -->
<!-- {"agent":"B002","command_id":"000000023039","details":"supervisor-confirmed removal of executable report automation; inert archive preserved at 00005P-GenderButtonControlPane-class-source-quality-removed.md","event":"content-change-confirmed","source_path":"executed-b-agent-research/B002/00005P-GenderButtonControlPane-class-source-quality.md","timestamp":"2026-08-13T00:48:55-04:00","uid":"00005P"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
