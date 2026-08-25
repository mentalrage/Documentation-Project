** TARGET-REPORT-UID:0002NE **
** AUTHOR-AGENT-ID:B005 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0002NE PasswordErrorVtableData Source-Quality / Ownership Research

## Finalized Report / Current Recommendation

- Current recommendation: keep the target as the exact five-slot `PasswordError` vtable range `0x006125a8-0x006125bc`, but update semantic ownership from file-level [UID:0000J5] `Error` to class-level [UID:0000A8] `PasswordError`.
- Final disposition: reconstructable `source-declared/generated-binary` vtable data. The vtable bytes must not be hand-emitted; the rebuild source is the `PasswordError` class declaration and its virtual override shape in the shared Error hierarchy.
- Required action: recommend metadata `COMPLETION:88`, `CONFIDENCE:91`, `CANONICAL_OWNER:0000A8`, `EMITTER_UIDS:0000A8`; keep `RECONSTRUCTABLE:TRUE` and keep the target `RECONSTRUCTION_CPP CODE` block blank.
- Confidence: high for range, slots, descriptor boundary, and owner class; medium-high for final source spelling of the shared `+0x10` virtual (`GetErrorName` versus `GetErrorDescriptor`).

## Supporting Research

## Target

- Target UID: `0002NE`
- Target path: `E:\NTK\GhidraBridge\source-3\project-documentation\by-memory\0x006125a8-0x006125bc.PasswordErrorVtableData.md`
- Required report path: `E:\NTK\GhidraBridge\source-3\project-documentation\tools\leaser\Agents\Agent-B005\research\0002NE-PasswordErrorVtableData-source-quality.md`
- Source queue/report row: refreshed `project-level/-auto-completion-stats.md`, row `0002NE | 82 | 90 | 86.0`.
- Current supervisor classification: report-only B-preferred source-quality and heuristic/inference pass from refreshed auto-completion stats.
- Current target metadata: `COMPLETION:82`, `CONFIDENCE:90`, `CANONICAL_OWNER:0000J5`, `RECONSTRUCTABLE:TRUE`, `EMITTER_UIDS:0000J5`.

## Executive Recommendation

The target range is already the correct half-open range. Do not expand it left to include the RTTI complete-object-locator pointer at `0x006125a4`, because [UID:0003P1] already covers `0x006125a4-0x006125a8`. Do not expand it right to include `0x006125bc`, because raw bytes prove that address is the first UTF-16 code unit of `Password Warning`.

The current file-level canonical owner is the main stale issue. Under current `by-structure.md`, a vtable that belongs directly to a class should use the class UID as `CANONICAL_OWNER` when the class clears the gate. [UID:0000A8] `PasswordError` is `86/90`, [UID:0000J5] `Error` is `87/85`, and the exact constructor/destructor/descriptor children already use [UID:0000A8] as canonical owner. Therefore [UID:0002NE] should be changed to `CANONICAL_OWNER:0000A8`. I recommend `EMITTER_UIDS:0000A8` so it routes through the class to `auto-generated/NexusTK/util/Error.cpp`, matching [UID:0002VJ], [UID:0002VK], and [UID:0002VL].

Do not populate final C++ on this exact vtable-data page. The correct source code belongs on the class/file declaration path after the Error hierarchy virtual names are standardized. A raw vtable initializer would be wrong, and a complete class declaration in this exact data page would duplicate broader class/type responsibility.

## Supervisor Active Recheck

- Assignment confirmed from `Agent-B005/goal.md` and `Agent-B005/notes.md`: [UID:0002NE] `PasswordErrorVtableData`, report-only, no direct edits to by-* docs or coverage reports.
- Split repair is not required for the assigned target. The target is already a clean five-slot vtable child.
- Adjacent support cleanup is recommended, not directly applied: parent [UID:00024T] has one row that says `Password Warning` bytes at `0x006125c0`; raw bytes show the descriptor starts at `0x006125bc`.
- IDA MCP was attempted on 2026-06-18 at `http://127.0.0.1:13337/mcp`; the endpoint refused connections after retry. This pass therefore uses raw `memory.bin` checks plus existing documentation that records prior live IDA MCP results.

## Inference Research Guidance Check

`by-structure.md` changes the recommendation because it separates semantic owner from emitter route. The current target routes directly to [UID:0000J5] `Error`, but current ownership rules say class-owned vtables should use the class UID when the class clears the gate. `inference_research.md` also cautions that consumers do not prove ownership. The PasswordGuard throw path is a consumer of `PasswordError`; it is not the vtable/class declaration owner.

Evidence categories used here:

- Raw fact: byte reads and byte-pattern scans from `C:\Users\admin\Desktop\CTools\Output\ida\memory\memory.bin`, using offset `VA - 0x00401000`.
- Documentation evidence: target/support docs with prior live IDA MCP xrefs, function sizes, and decompilation observations.
- Inference: source placement and final C++ policy, based on class ownership rules, slot layout, and source-declared/generated-binary rebuild handling.

## Heuristic / Inference Reanalysis And Validation

### 1. Exact Half-Open Vtable Range

- Evidence checked: raw bytes at `0x006125a0` show `0x00641fa4` at `0x006125a4`, then five dwords at `0x006125a8-0x006125b8`, then UTF-16 `Password Warning` beginning at `0x006125bc`.
- Size: `0x14` is 20 decimal, verified with `tools/int_convert.py`.
- Rejected alternatives: expanding left to include RTTI would duplicate [UID:0003P1]; expanding right would swallow descriptor string data.
- Final inference: target range `0x006125a8-0x006125bc` is correct and should not be split or renamed.
- Impact: supports score increase; no range repair needed.

### 2. RTTI Locator Boundary

- Evidence checked: raw dword `0x006125a4 -> 0x00641fa4`; [UID:0003P1] documents this as the `PasswordError` RTTI complete-object-locator pointer with owner [UID:0000A8].
- Rejected alternatives: treating `0x006125a4` as part of [UID:0003P0] literal tail or this vtable page.
- Final inference: current separate RTTI child is correct. Its class-level owner reinforces changing [UID:0002NE] to [UID:0000A8].
- Impact: no split action for [UID:0002NE]; metadata consistency issue remains.

### 3. Adjacent Descriptor String Boundary

- Evidence checked: raw bytes at `0x006125bc` decode as UTF-16 `Password Warning`, followed by a double NUL and then `0x00641ff8` at `0x006125e0`, the next Application RTTI pointer before the Application vtable head at `0x006125e4`.
- Pattern scan: dword `0x006125bc` appears once in `memory.bin`, at `0x00467401`, the immediate returned by the descriptor helper.
- Rejected alternatives: treating `0x006125bc` as a sixth vtable slot; treating the whole `0x006125bc-0x006125e4` band as only descriptor text.
- Final inference: `0x006125bc-0x006125e0` is the PasswordError descriptor string; `0x006125e0-0x006125e4` is the successor Application RTTI pointer.
- Impact: target score can rise; support doc [UID:00024T] should fix its row wording and optionally split the successor Application RTTI pointer later.

### 4. Slot Identities

- Evidence checked: raw dwords are:
  - `0x006125a8 -> 0x00467300`
  - `0x006125ac -> 0x004f4b10`
  - `0x006125b0 -> 0x0041b6c0`
  - `0x006125b4 -> 0x004a6840`
  - `0x006125b8 -> 0x00467400`
- Existing IDA-backed docs identify these as the scalar deleting destructor, inherited runtime/LObject slot, no-op slot, heap-message copy slot, and descriptor/name slot.
- Rejected alternatives: `0x004a6840` as PasswordGuard-owned helper, because it also appears as the `MyError` message-copy slot at `0x00619440`; `0x00467400` as a standalone literal helper, because its only function-address hit is the vtable slot.
- Final inference: all five slot identities are known enough for `88/91`, but final source spelling of the `+0x10` virtual is not final-audit ready.
- Impact: no slot blocker for ownership; final C++ remains withheld pending naming standardization.

### 5. Constructor / Destructor / Descriptor Xrefs

- Evidence checked:
  - Raw constructor bytes at `0x00467160` include `c7 06 a8 25 61 00`; the store instruction starts at `0x00467172` and the immediate `0x006125a8` starts at `0x00467174`.
  - Pattern scan for dword `0x006125a8` found one hit: `0x00467174`.
  - Raw call bytes around `0x00465abe` include `e8 9d 16 00 00`, which targets `0x00467160`.
  - Pattern scan for dword `0x00467300` found one hit: `0x006125a8`.
  - Pattern scan for dword `0x00467400` found one hit: `0x006125b8`.
  - Raw descriptor helper bytes at `0x00467400` are `b8 bc 25 61 00 c3`, returning `0x006125bc`.
- Documentation evidence checked: [UID:0002VJ], [UID:0002VK], [UID:0002VL], [UID:0000YS], [UID:0000A8], and [UID:0001XI] record prior live IDA `lookup_funcs`, `xrefs_to`, `callers`, and decompile evidence for these same relationships.
- Rejected alternatives: direct PasswordGuard ownership from the constructor caller; source-authored scalar-deleting wrapper body; descriptor helper returning vtable address.
- Final inference: constructor/destructor/descriptor evidence proves class ownership and the descriptor boundary. The throw-site caller only proves use by PasswordGuard.
- Impact: supports `CANONICAL_OWNER:0000A8`; generated `class_PasswordError.cpp` remains a data issue because it returns `&PasswordError_vtable`.

### 6. Error Versus PasswordGuard Source-Owner Ranking

- Evidence checked: [UID:0000MG] owns the setter, validator, token buffer, and seed. [UID:0000A8], [UID:00008V], [UID:0000J5], [UID:0001XI], and [UID:0001UE] own the class, heap-message family, vtable/layout family, and Error source module.
- Rejected alternatives: `PasswordGuard.cpp` as owner of the `PasswordError` class because it constructs/throws the class; `ApplicationStartupReadOnlyData` as owner because it physically contains the vtable; `ErrorHierarchyVtables` as canonical owner because it is a type/layout support page.
- Final inference: `PasswordError` class is the direct semantic owner; `Error.cpp` is the source file route; `PasswordGuard.cpp` is only a consumer/dependency.
- Impact: target owner should become [UID:0000A8]; [UID:0000MG] should remain linked as a related consumer.

### 7. ErrorHierarchyVtables Implications

- Evidence checked: [UID:0001XI] records the shared five-slot shape, the main `0x00619340-0x00619448` run, and the separate `PasswordError` vtable at `0x006125a8`.
- Rejected alternatives: using [UID:0001XI]'s file-level owner as proof that every exact vtable child should bypass its concrete class.
- Final inference: [UID:0001XI] should remain a family-level type page owned by [UID:0000J5], while [UID:0002NE] should use class-level semantic owner [UID:0000A8].
- Impact: no change needed to [UID:0001XI] ownership, but its text should not be cited as a reason to keep [UID:0002NE] file-owned.

### 8. Virtual Name Heuristic

- Evidence checked: B002's 2026-06-17 report selected `Error::GetErrorName` as the best current source-facing name for shared `0x004a6a70`, while allowing `GetErrorDescriptor` as a consistent project-wide alternative. [UID:0002VL] uses `PasswordErrorGetErrorDescriptor` because the returned literal is `Password Warning`.
- Rejected alternatives: `what()` because the message-copy slot is separate at `+0x0c`; `GetClassName` because the returned text is a UI/error label, not RTTI; keeping `sub_467400` in final source.
- Final inference: for target documentation, `PasswordErrorGetErrorDescriptor` is a good descriptive name. For final C++, the entire hierarchy must choose one virtual spelling, likely `GetErrorName` or `GetErrorDescriptor`, before any class declaration is populated.
- Impact: caps target below final-audit quality and blocks formal C++ on [UID:0002NE].

### 9. Source-Declared / Generated-Vtable Policy

- Evidence checked: `by-structure.md` classifies vtables as `source-declared/generated-binary`; [UID:0002NE], [UID:0002ND], [UID:0003P1], and [UID:0001XI] all record the same rebuild handling.
- Rejected alternatives: emitting raw dword arrays or trying to force an exact vtable object initializer in C++.
- Final inference: the vtable must be regenerated by the compiler from `PasswordError` inheritance and virtual declarations.
- Impact: `RECONSTRUCTABLE:TRUE` is correct, but `RECONSTRUCTION_CPP CODE` should remain blank on this exact page.

### 10. Open Support-Doc / Final-C++ Blockers

- Evidence checked: [UID:0000J5] `Error` still has open questions about `ErrorMessage`, PasswordError declaration/header split, and raw constructor starts; [UID:0001XI] has final virtual-name caveats; [UID:0001UE] has final field/member-name caveats; [UID:00013X] has aggregate-only formatter/destructor rows; [UID:00008V] notes `0x004a6860` lacks an exact child page; [UID:0000MG] has PasswordGuard final-name/resource-helper caveats.
- Rejected alternatives: treating these as reasons to leave [UID:0002NE] unowned or non-emitting. They do not affect vtable owner/range proof.
- Final inference: these blockers affect final source code readiness, not ownership. The target can rise to `88/91` and route through [UID:0000A8], but formal C++ should be withheld until the hierarchy declaration is settled.
- Impact: score below `95`; no direct code-entry on [UID:0002NE].

## Evidence Standards Used

- Raw memory bytes from `C:\Users\admin\Desktop\CTools\Output\ida\memory\memory.bin`.
- Byte-pattern scans for unique dword references.
- Existing by-* docs containing prior live IDA MCP `lookup_funcs`, `xrefs_to`, `callers`, `callees`, `decompile`, `py_eval`, `get_bytes`, and `get_int` findings.
- `tools/int_convert.py` for numeric conversions.
- Generated reports: `project-level/-auto-completion-stats.md`, `auto-generated/-ag-memory-coverage.md`, `auto-generated/-ag-class-coverage.md`, `auto-generated/-ag-type-coverage.md`, and `by-memory/-coverage-report.md`.
- Negative evidence: no fresh IDA MCP connection available in this session; no direct source/PDB proof of original method spelling.

## IDA MCP And Raw Facts

- IDA MCP status: unavailable in this session. `Test-NetConnection 127.0.0.1:13337` failed and JSON-RPC `tools/list` could not connect.
- Raw memory base: `memory.bin` starts at `.text` VA `0x00401000`, so checked offsets use `VA - 0x00401000`.
- Target data bytes at `0x006125a0`:
  - `72 00 00 00 a4 1f 64 00 00 73 46 00 10 4b 4f 00 c0 b6 41 00 40 68 4a 00 00 74 46 00 50 00 61 00 ...`
- Vtable dwords:
  - `0x006125a4 -> 0x00641fa4` RTTI/COL pointer.
  - `0x006125a8 -> 0x00467300`
  - `0x006125ac -> 0x004f4b10`
  - `0x006125b0 -> 0x0041b6c0`
  - `0x006125b4 -> 0x004a6840`
  - `0x006125b8 -> 0x00467400`
  - `0x006125bc` begins UTF-16 `Password Warning`.
- Function bytes:
  - `0x00467160` constructor includes store of `0x006125a8` and ends before `0xcc` padding at `0x00467181`.
  - `0x00467300` scalar deleting destructor bytes end before `0xcc` padding at `0x00467338`.
  - `0x00467400` descriptor helper is `mov eax, 0x006125bc; ret`.
- Pattern scans:
  - Dword `0x006125a8`: one hit at `0x00467174`.
  - Dword `0x006125bc`: one hit at `0x00467401`.
  - Dword `0x00467300`: one hit at `0x006125a8`.
  - Dword `0x00467400`: one hit at `0x006125b8`.
  - Dword `0x004a6840`: two hits, `0x006125b4` and `0x00619440`, matching PasswordError/MyError shared heap-message copy slot use.

## Function / Child Inventory

| Range / Item | UID / Path | Role | Reconstructable | Direct Parent | Score | Status |
| --- | --- | --- | --- | --- | --- | --- |
| `0x006125a4-0x006125a8` | [UID:0003P1] `PasswordErrorRttiLocatorPointer` | RTTI/COL pointer before vtable | TRUE | [UID:0000A8] | `86/91` | Correct separate predecessor child |
| `0x006125a8-0x006125bc` | [UID:0002NE] target | Five-slot `PasswordError` vtable | TRUE | Recommend [UID:0000A8] | Recommend `88/91` | Keep exact range; metadata update |
| `0x006125bc-0x006125e0` | no exact child found | UTF-16 `Password Warning` descriptor string | likely TRUE if split | likely [UID:0000A8] | not scored | Support split candidate, not part of target |
| `0x006125e0-0x006125e4` | no exact child found | Application RTTI/COL pointer before Application vtable | TRUE if split | [UID:00000D] / [UID:0000HG] | not scored | Support split candidate |
| `0x00467160-0x00467181` | [UID:0002VJ] `PasswordErrorConstructor` | Constructor installs vtable | TRUE | [UID:0000A8] | `86/90` | Supports owner |
| `0x00467300-0x00467338` | [UID:0002VK] `PasswordErrorScalarDeletingDestructor` | Scalar deleting destructor slot | TRUE | [UID:0000A8] | `85/88` | Compiler ABI wrapper; no raw final body |
| `0x00467400-0x00467406` | [UID:0002VL] `PasswordErrorGetErrorDescriptor` | Descriptor/name virtual | TRUE | [UID:0000A8] | `88/92` | Returns `0x006125bc` |

## Direct Xref / Caller Inventory

| Address / Item | Xref / Caller / Callee | Meaning |
| --- | --- | --- |
| `0x00467174` | only raw dword hit for `0x006125a8` | Constructor writes `PasswordError` vtable |
| `0x00465abe` | raw `call` to `0x00467160`; documented by [UID:0002VH] | PasswordGuard throw path constructs `PasswordError` |
| `0x006125a8` | only raw dword hit for `0x00467300` | First vtable slot is destructor |
| `0x006125b4` | one of two raw hits for `0x004a6840` | PasswordError inherits heap-message copy slot |
| `0x006125b8` | only raw dword hit for `0x00467400` | Fifth slot is PasswordError descriptor/name helper |
| `0x00467401` | only raw dword hit for `0x006125bc` | Descriptor helper returns the adjacent string |

## Documentation Evidence And IDA Status

- [UID:0002NE] already records the correct five slot entries and descriptor boundary, but its owner is file-level [UID:0000J5].
- [UID:0003P1] uses class-level [UID:0000A8] ownership for the adjacent RTTI locator pointer.
- [UID:0002VJ], [UID:0002VK], and [UID:0002VL] all use class-level [UID:0000A8] ownership and emit through the class chain.
- [UID:0000A8] `PasswordError` is `86/90`, clearing the strict gate.
- [UID:0000J5] `Error` is `87/85`, clearing the source-file parent gate.
- [UID:0000MG] `PasswordGuard` is `86/90`, but it owns only the password-token helpers/globals and throw path.
- [UID:0001XI] correctly treats the vtable family as Error hierarchy evidence, but that family-level type owner does not override the narrow class owner for [UID:0002NE].
- `source-3/simroot_v2/class_PasswordError.cpp` still emits the descriptor helper as returning `&PasswordError_vtable`; this contradicts raw bytes and the by-* docs.
- `auto-generated/NexusTK/util/Error.cpp` and `auto-generated/NexusTK/auth/PasswordGuard.cpp` currently have length `0`, so generated output routing exists but final source has not been populated.

## Ranked Ownership Analysis

### 1. [UID:0000A8] PasswordError Class

- Evidence for: constructor writes `0x006125a8`; destructor and descriptor helper are vtable-only class members; descriptor string is uniquely returned by [UID:0002VL]; adjacent RTTI child is already class-owned; class page clears `86/90`; exact method children are class-owned.
- Evidence against: implementation source file is likely [UID:0000J5] `Error`, and the only constructor caller is in [UID:0000MG] `PasswordGuard`.
- Decision: accepted as canonical owner. Use [UID:0000A8] as both semantic owner and emitter route so generated output still surfaces through [UID:0000J5] `Error.cpp`.

### 2. [UID:0000J5] Error File

- Evidence for: source file likely owns the whole Error hierarchy; [UID:0001XI] and [UID:0002ND] use file-level family ownership; [UID:0000J5] clears `87/85`; target currently routes there without generated dead-end.
- Evidence against: current `by-structure.md` says class-owned vtables should use the class UID as canonical owner. Direct file ownership bypasses the already documented [UID:0000A8] class page and conflicts with [UID:0003P1], [UID:0002VJ], [UID:0002VK], and [UID:0002VL].
- Decision: use as source file/emitter chain, not canonical owner.

### 3. [UID:0000MG] PasswordGuard File

- Evidence for: `ValidateChatInputOrThrowPasswordError` constructs `PasswordError` at `0x00465abe`, and the error exists to report password disclosure.
- Evidence against: all vtable, RTTI, constructor, destructor, descriptor, and heap-message storage evidence is class/Error hierarchy evidence. PasswordGuard owns token state and validation, not the exception class declaration.
- Decision: rejected as owner or emitter for [UID:0002NE]. Keep as related consumer/dependency only.

### 4. [UID:00024T] ApplicationStartupReadOnlyData / Physical Parent

- Evidence for: physically contains the target range and successor strings/vtables.
- Evidence against: mixed read-only-data aggregate with Application, PasswordError, FunctionObject0, strings, and patcher literals; physical adjacency is weaker than class/xref evidence.
- Decision: rejected as canonical owner. It remains a coverage/parent aggregate.

### 5. [UID:0001XI] ErrorHierarchyVtables

- Evidence for: records the vtable family and slot layout.
- Evidence against: type support pages should not take ownership of exact class vtable bytes when a concrete class page exists and clears the gate.
- Decision: support doc only.

## Negative Evidence Summary

- No fresh IDA MCP facts could be gathered in this session because the endpoint was unavailable; this limits the report to raw byte verification and existing IDA-backed docs.
- No evidence shows another source module writes, references, or owns the `PasswordError` vtable.
- PasswordGuard consumer evidence is not ownership evidence.
- Address adjacency to Application startup data does not prove Application ownership.
- The current generated `class_PasswordError.cpp` descriptor body is contradicted by raw bytes and should not be used as source-quality evidence.

## First-Draft C++ Recommendation

Do not populate the target [UID:0002NE] `RECONSTRUCTION_CPP CODE` block.

Reason: [UID:0002NE] covers compiler-generated vtable data. A correct source reconstruction should declare the class hierarchy and virtual methods so the compiler emits the vtable. Putting raw dwords in this page would be wrong, and putting a full class declaration here would duplicate [UID:0000A8], [UID:0001XI], and [UID:0000J5]. The descriptor method body belongs to [UID:0002VL], and the constructor/destructor behavior belongs to [UID:0002VJ]/[UID:0002VK].

Review-only shape for the class/file route after virtual-name standardization:

```cpp
class PasswordError : public MyError {
public:
    explicit PasswordError(const wchar_t *message);
    virtual ~PasswordError();

    // Name subject to hierarchy-wide standardization:
    // GetErrorName and GetErrorDescriptor are the two currently documented candidates.
    virtual const wchar_t *GetErrorDescriptor() const;
};

const wchar_t *PasswordError::GetErrorDescriptor() const
{
    return L"Password Warning";
}
```

If the supervisor standardizes the shared `+0x10` slot as `GetErrorName`, apply that name consistently to `PasswordError` as well. Do not preserve the active generated output that returns `&PasswordError_vtable`.

## Recommended Target Metadata And Text Changes

Recommended metadata for [UID:0002NE]:

```text
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:91 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:0000A8 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:TRUE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS:0000A8 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Recommended target status replacement context:

Replace:

```text
- Covered source files: [UID:0000J5][Error](by-file/Error.md) and [UID:0000MG][PasswordGuard](by-file/PasswordGuard.md)
```

With:

```text
- Covered semantic owner: [UID:0000A8][PasswordError](by-class/PasswordError.md), emitted through [UID:0000J5][Error](by-file/Error.md).
- Related consumer/source dependency: [UID:0000MG][PasswordGuard](by-file/PasswordGuard.md) constructs and throws `PasswordError` from the password-disclosure guard, but does not own the vtable/class declaration.
```

Recommended reconstruction note addition:

```text
Under the current owner/emitter split, this exact vtable page should use `CANONICAL_OWNER:0000A8` because the vtable belongs directly to the `PasswordError` class. `Error.cpp` remains the final source file route through the `PasswordError` class emitter chain. Keep final C++ blank on this page; source should be emitted from the class/file declaration route, not as raw vtable dwords.
```

## Supervisor-Owned Coverage Replacement Row

Placement context: replace the existing [UID:0002NE] child row under [UID:00024T] in `by-memory/-coverage-report.md`.

Replacement row:

```text
        - [UID:0002NE][0x006125a8-0x006125bc.PasswordErrorVtableData](by-memory/0x006125a8-0x006125bc.PasswordErrorVtableData.md) 0x006125a8-0x006125bc | vtable-data | PasswordErrorVtableData : reconstructable : 88% : strong : Exact five-slot `PasswordError` vtable (`0x14` / 20 bytes, Verified with int_convert.py); raw memory confirms predecessor RTTI pointer [UID:0003P1] at `0x006125a4`, slot targets `0x00467300`, `0x004f4b10`, `0x0041b6c0`, `0x004a6840`, `0x00467400`, constructor store to `0x006125a8`, descriptor helper return to `0x006125bc`, and UTF-16 `Password Warning` successor boundary. Recommend canonical owner [UID:0000A8] `PasswordError`, emitter [UID:0000A8] through `Error.cpp`, and blank final C++ because this is source-declared/generated-binary vtable data.
```

## Support Docs To Update

- [UID:00024T] `ApplicationStartupReadOnlyData`: replace `wide Password Warning bytes at 0x006125c0` with `wide Password Warning bytes start at 0x006125bc; IDA label aSswordWarning at 0x006125c0 points inside the literal`. Also clarify that `0x006125e0-0x006125e4` is the successor Application RTTI pointer, not descriptor string text.
- [UID:0001XI] `ErrorHierarchyVtables`: keep family owner [UID:0000J5], but add a note that [UID:0002NE] should use concrete class [UID:0000A8] as canonical owner under current by-structure rules.
- [UID:0000A8] `PasswordError`: update source-split wording from "medium-high" uncertainty to "class owner resolved to Error hierarchy; only original header/virtual spelling remains unproven."
- [UID:0000J5] `Error`: narrow the open question about PasswordError. Best current inference is that `PasswordError` declaration/virtuals belong to `Error.h`/`Error.cpp`, while password filtering remains in `PasswordGuard.cpp`; only recovered symbols could overturn this.
- [UID:0002VL] `PasswordErrorGetErrorDescriptor`: preserve the corrected return target `0x006125bc`; add a warning not to use the active generated `class_PasswordError.cpp` return expression.
- Optional future split: create `0x006125bc-0x006125e0.PasswordErrorDescriptorString.md` and `0x006125e0-0x006125e4.ApplicationRttiLocatorPointer.md` if the supervisor wants the successor band represented with the same exact-child precision as [UID:0003P1]. This is not required to complete [UID:0002NE].

## Final Recommendation

- Apply metadata recommendation to [UID:0002NE]: `88/91`, `CANONICAL_OWNER:0000A8`, `EMITTER_UIDS:0000A8`.
- Keep target range and filename unchanged.
- Keep `RECONSTRUCTION_CPP CODE` blank on the target.
- Do not assign anything to PasswordGuard for this vtable. Keep PasswordGuard linked as the throw-site consumer only.
- Fix the [UID:00024T] descriptor-boundary wording and the by-memory coverage row when supervisor-owned report edits are next applied.

## Follow-Up Actions

- Supervisor actions: apply the metadata/text/coverage recommendations above or assign an A-agent to apply them under normal lease rules.
- A-agent actions: standardize the Error hierarchy `+0x10` virtual name before entering class/file C++; update generated-source route by populating the class/file docs, not by editing generated files.
- B005 future research: none required for [UID:0002NE] unless the supervisor wants the successor descriptor string and Application RTTI pointer split as separate support targets.

## Confidence

- Recommendation confidence: high.
- Score confidence: high for `88/91`; not higher because final source spelling, Error.h declaration shape, and related Error aggregate raw-constructor caveats remain open.
- Remaining uncertainty: original method name for the `+0x10` virtual and exact original header/source organization cannot be proven without recovered symbols/PDB/source. This does not block owner/range decisions.

## Validator Results

- Commands run: none.
- Reason: report-only assignment; no by-* docs or generated files were edited.
- Tooling note: IDA MCP connection attempts failed on 2026-06-18; raw `memory.bin` checks were used instead.

## Changed Files

- Created: `tools/leaser/Agents/Agent-B005/research/0002NE-PasswordErrorVtableData-source-quality.md`
- Modified: none outside this report.
- Renamed: none.
- Moved to executed: none.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B005","command_id":"000000004165","destination_path":"executed-b-agent-research/B005/0002NE-PasswordErrorVtableData-source-quality.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:31","uid":"0002NE"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
