** TARGET-REPORT-UID:0002CZ **
** AUTHOR-AGENT-ID:B010 **
** AUTHOR-AGENT-SPECS: CHATGPT | 5.5 | xHigh **
# 0002CZ SmallStringStorageAssign Source-Routing Report

## Finalized Report / Current Recommendation

- Current recommendation: keep [UID:0002CZ] `0x0041d3b0-0x0041d431.SmallStringStorageAssign` as ignored/non-emitting MSVC/Dinkumware-style `std::string` small-string support. Do not assign it to FittingRoom, JsonCpp, `StringBase`, `StringUtil`, `SimpleUString`, or a new NexusTK utility file.
- Final disposition: `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, blank formal `RECONSTRUCTION_CPP`.
- Recommended score: raise `COMPLETION:84 -> 88`, `CONFIDENCE:90 -> 92`.
- Source-facing role: descriptive analysis name `MsvcSmallStringStorageCopyConstruct` or `std_string_sso15_copy_construct`. This is a runtime/compiler helper for a 24-byte byte-string object, not a recovered product class named `SmallStringStorage`.
- Required action: update the target and supporting docs with the source-routing/no-code proof below. Do not edit `by-memory/-coverage-report.md`; supervisor should apply the exact row text in this report.
- Confidence: high for range, behavior, layout, caller spread, and non-product source classification; capped below final because the exact vendor/internal symbol name and precise MSVC/Dinkumware library version are not recovered.

## Target

- Target UID: `0002CZ`
- Target path: `source-3/project-documentation/by-memory/0x0041d3b0-0x0041d431.SmallStringStorageAssign.md`
- Required report path: `source-3/project-documentation/tools/leaser/Agents/Agent-B010/research/0002CZ-SmallStringStorageAssign-source-routing.md`
- Current metadata: `COMPLETION:84`, `CONFIDENCE:90`, `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, blank formal C++.
- Current coverage row: `ignored : 84% : strong`.
- Current target range: exact half-open `0x0041d3b0-0x0041d431`, size `0x81` / 129 bytes.

## Evidence Checked

- Re-read the active B-agent instructions in `tools/leaser/Agents/Supervisor.md`, `.codex/AGENTS.md`, and `Agent-B010/goal.md`.
- Read target [UID:0002CZ] and sibling/runtime pages:
  - [UID:0000WN] `by-memory/0x0041b6d0-0x0041b9a0.MsvcStringSupportHelpers.md`
  - [UID:0003GZ] `by-memory/0x0041b300-0x0041b34a.SmallStringStorageReset.md`
  - [UID:0002UG] `by-memory/0x00423960-0x00423a57.SmallString24AssignCopyHelper.md`
  - [UID:0000WR] `by-memory/0x0041ba40-0x004245f5.FittingRoomUiCore.md`
  - [UID:0000WU] `by-memory/0x00421a40-0x00422e91.FittingRoomItemShopCatalogState.md`
  - [UID:0000WY] `by-memory/0x00424630-0x00428b4b.JsonCppValueCore.md`
  - [UID:0000X5] `by-memory/0x00430040-0x00430092.GenericStringAppendHelper.md`
  - [UID:0001ZX] `by-memory/0x00442090-0x00443a55.JsonCppWriterRuntimeTailSupport.md`
- Read source-placement/support pages:
  - [UID:0000JE] `by-file/FittingRoom.md`
  - [UID:0000KI] `by-file/JsonCpp.md`
  - [UID:0000OA] `by-file/StringBase.md`
  - [UID:0000OB] `by-file/StringUtil.md`
  - [UID:0000D9] `by-class/SimpleUString.md`
  - [UID:0001QE] `by-meta/client_libraries.md`
  - [UID:0001QS] `by-meta/client_string_handling.md`
- Checked current generated/project rows:
  - `project-level/-auto-completion-stats.md` lists `0002CZ` at `84/90`.
  - `auto-generated/-ag-memory-coverage.md` lists `0002CZ` as `not_reconstructable`, owner `NONE`, no emitter.
  - `by-memory/-coverage-report.md` has the current stale `84% : strong` row.
  - `by-memory/-ignored.md` already has an ignored row for the helper, but it should receive the more explicit ownership/name/no-code proof.
- Checked unresolved/generated-name evidence:
  - `project-level/-unresolved.md` still lists `FUN_0041d3b0`, `sub_41D3B0`, and the legacy `cls_0x427990` bucket.
  - `by-memory/-report.old.md` records that `cls_0x427990` was a polluted legacy bucket that conflated unrelated wide-string, byte-string, and vector helpers.
- Checked local export `exports/0041d3b0.json`:
  - name `cls_0x427990`, size `129`, signature `cls_0x427990 * __thiscall cls_0x427990(cls_0x427990 * this, uint * param_1)`;
  - decompile initializes destination length/capacity, reads source length/capacity at source slots `+0x10/+0x14`, copies inline 16 bytes when `length < 0x10`, otherwise allocates through `FUN_0041b6e0((length | 0x0f) + 1)` and copies `length + 1` bytes through `memcpy_optimized`;
  - callers span FittingRoom item-state/action paths, JsonCpp exception/value/writer/parser support, and later runtime/string/iostream helpers;
  - callees are only `0x0041b6e0` and `0x005c95b0 memcpy_optimized`.
- Attempted live IDA MCP at `http://127.0.0.1:13337/mcp`; endpoint was unavailable: `IDA_MCP_ERROR: Unable to connect to the remote server`. No live IDA mutation or direct IDA rename was performed for this report.
- Used `tools/int_convert.py` for constants: `0x18` = 24, `0x10` = 16, `0x0f` = 15, `0x81` = 129, `0x7fffffff` = 2147483647.

## Heuristic / Inference Reanalysis And Validation

### Exact Range And Boundary

Best conclusion: keep the exact half-open range `0x0041d3b0-0x0041d431` unchanged.

Evidence:

- Target doc records 2026-06-04 live IDA MCP `sub_41D3B0` at `0x0041d3b0-0x0041d431`, size `0x81`.
- Neighbor evidence: previous function [UID:0002CY] `CompareEquipmentNames` ends at `0x0041d3b0`; next function [UID:0002D0] `ClearFittingRoomDialogGlobal` starts at `0x0041d440`.
- `by-memory/-ignored.md` records `0x0041d431-0x0041d440` as `0xcc` alignment padding.
- No split/merge correction is justified. Do not merge this with `CompareEquipmentNames`; that helper has fitting-room-only comparison callers, while this helper has broad string-storage callers.

### SSO Layout

Best conclusion: this is a 24-byte SSO-15 byte-string storage object, equivalent to an MSVC/Dinkumware `std::string`-like representation.

Analysis-only layout:

```cpp
struct MsvcSmallString24 {
    union {
        char inlineBytes[16];  // capacity < 0x10
        char* heapBytes;       // capacity >= 0x10
    };
    unsigned int length;       // +0x10
    unsigned int capacity;     // +0x14
};
```

Evidence:

- Object footprint is `0x18` / 24 bytes.
- Inline capacity is `0x0f` / 15 data bytes plus terminator.
- Capacity `< 0x10` means inline bytes at offset `0`; capacity `>= 0x10` means offset `0` is a heap pointer.
- Length is read/written at `+0x10`; capacity is read/written at `+0x14`.
- Inline copy path copies four dwords / 16 bytes, stores the source length, and stores capacity `0x0f`.
- Heap copy path computes capacity as `length | 0x0f` capped to `0x7fffffff`, allocates `capacity + 1`, copies `length + 1` bytes, then stores length/capacity.
- [UID:0000WN], [UID:0003GZ], and [UID:0002UG] document the same SSO-15 byte-string support family, including the runtime allocation/free/large-allocation guard lineage.

### Helper Name And Signature

Best descriptive name: `MsvcSmallStringStorageCopyConstruct` or `std_string_sso15_copy_construct`.

Best analysis-only signature:

```cpp
MsvcSmallString24* __thiscall MsvcSmallStringStorageCopyConstruct(
    MsvcSmallString24* dst,
    const MsvcSmallString24* src);
```

Why this is descriptive, not source-original:

- Local export names `cls_0x427990` and `FUN_0041d3b0` are generated/decompiler names.
- IDA name `sub_41D3B0` is a raw address label.
- `cls_0x427990` is not a usable class name: unresolved/project-level notes show it is a polluted legacy bucket that conflates unrelated wide-string, byte-string, and vector helpers.
- The body shape is copy-constructor/copy-storage support, not a feature method. It returns `this`, receives source storage, and does not touch any NexusTK class fields.

### Caller And Reachability Spread

The caller spread is the strongest ownership discriminator. The helper is live code, but not a NexusTK source unit.

| Caller group | Evidence | Meaning |
| --- | --- | --- |
| FittingRoom action/item-state | `0x0041cb70` three calls; `0x00422020`, `0x004229f0`, `0x00422ec0`; [UID:0000WU] docs use it for `ItemShop.jbn`/decoded text state | Product fitting-room code consumes SSO byte strings; caller locality is not ownership. |
| JsonCpp exception/value core | `0x00424630`, `0x00424710`, `0x00424780`, `0x00428490`, `0x00429090`, `0x00429410`; [UID:0000WY] starts immediately after fitting-room range and owns JsonCpp value/exception support | JsonCpp uses standard/string-like storage; it is a consumer, not owner of the compiler helper. |
| JsonCpp writer support | `0x0042e850`, `0x0042f460`, `0x0042f800`, `0x0042fc00`, `0x00430058`, `0x00430610`, `0x00430ae0`, `0x00430ff0`, `0x00432460`, `0x004353c0`, `0x00435db0` | Writer/parser paths use the same support across many JsonCpp source methods. |
| Later MSVC/STL/runtime support | `0x004375d0`, `0x00437290`, `0x00437470`, `0x004394d0`, `0x00439550`, `0x004395d0`, `0x00439710`, `0x004429a0`; [UID:0001ZX] and JsonCpp runtime support pages show broad STL/string/iostream support around these ranges | Confirms compiler/runtime helper fan-out beyond any single source file. |

No data refs are listed in `exports/0041d3b0.json`. The helper is reached by ordinary calls from emitted code, not a vtable slot or product callback.

### FittingRoom Relation

Best conclusion: FittingRoom is a consumer only.

Evidence for considering FittingRoom:

- The helper is physically inside the broad [UID:0000WR] FittingRoom UI address neighborhood.
- [UID:0002CT] `FittingRoomDialogHandleFittingAction` calls it for request-buffer copying.
- [UID:0000WU] item-shop catalog state and raw/no-caller cache/test helpers use the same SSO byte-string family for local decoded text.

Evidence against FittingRoom ownership:

- Body has no FittingRoom fields, no UI controls, no item-state offsets, no category constants, and no fitting-room globals.
- Caller set extends into JsonCpp value/writer/parser and standard-library support.
- Sibling [UID:0002UG] has only fitting-room direct callers but is still generic SSO-15 support; [UID:0002CZ] has even stronger cross-subsystem proof.
- [UID:0000WR] already correctly records the target as address-neighbor only.

Decision: keep nested-by-address references in FittingRoom aggregate docs, but do not assign owner/emitter or add any C++ to `NexusTK/cashshop/FittingRoom.cpp`.

### JsonCpp Relation

Best conclusion: JsonCpp is a major consumer and should remain a cross-reference, not the direct owner.

Evidence for considering JsonCpp:

- Many direct callers are inside [UID:0000WY] JsonCpp value/exception helpers and writer/parser support.
- [UID:0000X5] `GenericStringAppendHelper`/`StyledWriter::pushValue` copies through `0x0041d3b0` and advances a `0x18`-byte element pointer, matching `MsvcSmallString24`.
- [UID:0000KI] documents vendored JsonCpp as a static third-party source embed that uses standard strings.

Evidence against JsonCpp ownership:

- FittingRoom callers precede JsonCpp code and use the same helper.
- Later runtime/STL support callers also use it.
- The body is not a JsonCpp algorithm, does not reference JsonCpp RTTI/literals, and has only runtime allocation/copy callees.
- JsonCpp source should emit normal `JSONCPP_STRING` / `std::string` operations from the vendored source; the helper itself should be regenerated by the selected compiler/runtime.

Decision: JsonCpp docs should mention this only as a consumed SSO/runtime helper where needed.

### StringBase / StringUtil / SimpleUString Relation

Best conclusion: do not route this to project string utilities.

Rejected `StringBase`:

- [UID:0000OA] owns the ref-counted ANSI/UTF-16 `mystr::StringBase` family at `0x00582500-0x00584d7d`.
- That family uses a data pointer and a 12-byte header before the data (`refCount`, `length`, `capacity`), plus sentinels/pools.
- 0002CZ uses an inline/heap union inside a 24-byte object with length/capacity in the object at `+0x10/+0x14`. It does not use `InterlockedDecrement`, sentinels, pools, or `StringBase` vtable/RTTI evidence.

Rejected `StringUtil`:

- [UID:0000OB] owns shared wide-string utilities, fixed wide-format wrappers, `SimpleUString`, `SimpleUStringVector`, and `StringIter`.
- 0002CZ is byte-string STL support with only `0x0041b6e0` and `memcpy_optimized` callees. It is not a wide-format, conversion, iterator, or project utility wrapper.

Rejected `SimpleUString`:

- [UID:0000D9] owns an SSO-7 UTF-16 representation with inline threshold 8, two-byte character storage, and narrow-to-wide append helpers.
- 0002CZ is SSO-15 byte storage with inline threshold 16, one-byte character storage, and `std::string`-like allocation.
- [UID:0001QS] already warns against merging unrelated SSO-15 byte-string helpers into `SimpleUString`; this report confirms that warning for 0002CZ.

Decision: update `client_string_handling.md` only to make the exclusion explicit for the SSO-15 helper family (`0003GZ`, `0000WN`, `0002CZ`, `0002UG`) if accepted.

### Compiler/Runtime Versus Product Source

Best conclusion: compiler/runtime support, no product source owner.

Positive evidence:

- Same SSO layout and growth pattern as [UID:0000WN] MSVC/Dinkumware helpers.
- Uses `0x0041b6e0`, which [UID:0000WN] documents as aligned large-allocation string storage support.
- Broad callers span product, third-party JsonCpp, and STL/runtime support islands.
- No NexusTK feature fields/literals/resources/protocol structures appear in the body.

Remaining uncertainty:

- Exact original vendor/internal symbol is not recovered.
- Exact compiler/runtime library version is inferred from behavior and surrounding Dinkumware support, not symbolized.

Impact:

- Strong enough for `88/92` and exact no-code proof.
- Not strong enough for a `95+` final audit or a final vendor symbol name.

### Final C++ / No-Code Proof

Do not populate formal `RECONSTRUCTION_CPP` for [UID:0002CZ].

Proof:

- Active code-entry rules require `RECONSTRUCTABLE:TRUE` and a valid nonblank emitter route. This page is correctly `RECONSTRUCTABLE:FALSE` and should keep blank emitters.
- The helper is not handwritten NexusTK product code. It is support emitted from source-level string use by product and third-party code.
- Hand-writing a `SmallStringStorageAssign` function in reconstructed output would introduce a fake product API and duplicate compiler/runtime responsibility.
- The correct source expression is ordinary source string ownership in callers:
  - FittingRoom should keep `std::string`/byte-buffer/JsonCpp source types for cache/request text.
  - JsonCpp should come from the vendored upstream source using `JSONCPP_STRING` / `std::string`.
  - The selected MSVC-era toolchain/runtime model should emit equivalent SSO/storage support.

Analysis-only pseudocode may be useful in the target prose, but it should not be placed in formal C++ output:

```cpp
// Analysis only, not reconstruction output:
// copy-construct one 24-byte SSO-15 byte-string storage object from another.
```

## Ranked Ownership Analysis

### 1. MSVC/Dinkumware `std::string` SSO-15 support, no canonical owner - Selected

- Evidence for: exact 24-byte SSO-15 layout, `0x0041b6e0` allocation helper, byte-string copy semantics, broad FittingRoom/JsonCpp/STL caller spread, sibling ignored SSO helper pages, and no product-specific state.
- Evidence against: exact vendor/internal symbol name is not recovered.
- Decision: selected. Keep `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, no emitter, blank C++.

### 2. FittingRoom / FittingRoomDialogItemState - Rejected

- Evidence for: address neighborhood and several fitting-room callers.
- Evidence against: broad non-fitting-room callers, generic body, no fitting-room data, and sibling support-helper classification.
- Decision: rejected as direct owner. Keep cross-links only.

### 3. JsonCpp - Rejected As Direct Owner

- Evidence for: many JsonCpp caller sites and `StyledWriter::pushValue` dependency.
- Evidence against: product and runtime callers also use it; body is compiler/string support, not JsonCpp source logic.
- Decision: JsonCpp is a consumer. Vendored JsonCpp source should use normal source string operations.

### 4. StringBase / StringUtil / SimpleUString - Rejected

- Evidence for: superficial "string" and 24-byte layout overlap with some string-family pages.
- Evidence against: `StringBase` is ref-counted pointer-backed ANSI/UTF-16, `StringUtil` is project utility-string coordination, and `SimpleUString` SSO is UTF-16 SSO-7. This helper is byte SSO-15 std-string support.
- Decision: reject direct source placement in project string utilities. Add explicit support-doc warning if accepted.

### 5. New `SmallStringStorage.cpp` / product utility file - Rejected

- Evidence for: would provide a tidy name for several helper pages.
- Evidence against: no source-level product class or file is proven, and a new file would collect compiler/runtime code that should be supplied by the toolchain.
- Decision: do not create.

## Score And Metadata Recommendation

Recommended target metadata:

```text
*** COMPLETION:88 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CONFIDENCE:92 | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** CANONICAL_OWNER:NONE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** RECONSTRUCTABLE:FALSE | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
*** EMITTER_UIDS: | ONLY MODIFY VALUE - DO NOT REMOVE!!! ***
```

Rationale:

- Completion `88`: exact range, body, constants, layout, caller/callee spread, related support family, generated-name rejection, owner rejection, source-routing, support-doc update list, and no-code proof are now documented. Not higher because exact vendor/internal symbol and runtime version are not recovered.
- Confidence `92`: strong binary/documentation evidence confirms behavior and classification. Not higher because live IDA MCP was unavailable for a fresh 2026-06-19 check and exact vendor symbol provenance remains inferred.
- Reconstructable stays `FALSE`: this is compiler/runtime support, not NexusTK source.

## Recommended Target Doc Changes

For `by-memory/0x0041d3b0-0x0041d431.SmallStringStorageAssign.md`:

1. Change score metadata to `COMPLETION:88`, `CONFIDENCE:92`.
2. Keep `CANONICAL_OWNER:NONE`, `RECONSTRUCTABLE:FALSE`, blank `EMITTER_UIDS`, blank formal C++.
3. Replace the passive compiler/runtime wording with an explicit B010 source-routing section:
   - descriptive analysis name `MsvcSmallStringStorageCopyConstruct` / `std_string_sso15_copy_construct`;
   - analysis-only signature with `MsvcSmallString24* dst, const MsvcSmallString24* src`;
   - 24-byte layout fields at `+0x00/+0x10/+0x14`;
   - inline threshold/capacity: `0x10` / 16 and `0x0f` / 15;
   - heap capacity formula `(length | 0x0f)`, capped at `0x7fffffff`;
   - callees `0x0041b6e0` and `memcpy_optimized`/memmove-equivalent copy;
   - direct caller groups from FittingRoom, JsonCpp value/writer/parser, and runtime/STL support.
4. Add generated-name cleanup text:
   - `sub_41D3B0` and `FUN_0041d3b0` are raw labels.
   - `cls_0x427990` is a polluted legacy bucket, not a source class.
5. Add rejected alternatives:
   - FittingRoom/private helper;
   - JsonCpp-owned helper;
   - `StringBase`, `StringUtil`, `SimpleUString`;
   - new NexusTK `SmallStringStorage` utility file;
   - formal C++ body emission.
6. Add exact no-code proof from this report.
7. Keep range and filename unchanged.

## Recommended Support Doc Changes

- `by-memory/-ignored.md`: strengthen the `0x0041d3b0-0x0041d431` entry with the descriptive name, layout, caller spread, and rejected project/string owners. This is allowed in implementation callback but not in this report-only pass.
- `by-memory/0x0041ba40-0x004245f5.FittingRoomUiCore.md`: keep existing address-neighbor exclusion, but add that B010 resolved `cls_0x427990`/`sub_41D3B0` as compiler/runtime SSO-15 copy support and not a fitting-room method.
- `by-file/FittingRoom.md`: no score change required. Add or keep an explicit note that [UID:0002CZ] remains excluded from strong fitting-room contents despite fitting-room callers; fitting-room source should use source string/JsonCpp types.
- `by-file/JsonCpp.md`: add a short support note that JsonCpp calls [UID:0002CZ] through `JSONCPP_STRING`/`std::string` storage, but the helper itself is compiler/runtime support and should not become a JsonCpp-authored source body.
- `by-meta/client_libraries.md`: update the MSVC CRT/STL/Dinkumware support row to include the early SSO helper family: [UID:0003GZ] `SmallStringStorageReset`, [UID:0000WN] `MsvcStringSupportHelpers`, [UID:0002CZ] `SmallStringStorageAssign`, and [UID:0002UG] `SmallString24AssignCopyHelper`.
- `by-meta/client_string_handling.md`: add an explicit exclusion that SSO-15 byte-string helper pages (`0003GZ`, `0000WN`, `0002CZ`, `0002UG`) are separate compiler/runtime `std::string` support and should not be merged into `StringBase`, `StringUtil`, or `SimpleUString`.
- Optional sibling cross-link updates only if implementation has room:
  - [UID:0000WN] can list [UID:0002CZ] as a nearby same-family copy-constructor/storage sibling outside its exact range.
  - [UID:0003GZ] and [UID:0002UG] already link enough; no mandatory score changes.

## Exact Pending Coverage Replacement Text

Replace the current `by-memory/-coverage-report.md` row for [UID:0002CZ] with:

```text
        - [UID:0002CZ][0x0041d3b0-0x0041d431.SmallStringStorageAssign](by-memory/0x0041d3b0-0x0041d431.SmallStringStorageAssign.md) 0x0041d3b0-0x0041d431 | MSVC/Dinkumware SSO-15 copy helper | SmallStringStorageAssign : ignored/non-emitting : 88% : very strong : B010 source-routing reanalysis identifies a 0x81-byte `std::string`-like 24-byte SSO-15 copy/storage constructor helper: inline bytes or heap pointer at +0x00, length +0x10, capacity +0x14, inline threshold 0x10, inline capacity 0x0f, destination zero-init, inline 16-byte copy for length < 0x10, heap path allocation through 0x0041b6e0 with capacity `(length | 0x0f)` and length+1 copy through memcpy/memmove. Callers span FittingRoom action/item-state paths, JsonCpp exception/value/writer/parser support, and later MSVC/STL/runtime string/iostream support; callees are only runtime string allocation and memcpy. Keep owner NONE, reconstructable FALSE, blank emitter/C++; regenerate through source string/JsonCpp/product types and compiler/runtime support. Reject FittingRoom, JsonCpp, StringBase, StringUtil, SimpleUString, polluted `cls_0x427990`, and new product utility ownership.
```

Do not edit `by-memory/-coverage-report.md` directly during B-agent implementation unless the supervisor lifts the shared-file ban.

## Implementation Checklist For Supervisor Callback

1. Lease every target/support doc before editing.
2. Update [UID:0002CZ] target metadata to `88/92`, preserving owner/emitter/reconstructable state.
3. Add the report-level source-routing/no-code proof to the target doc.
4. Update `by-memory/-ignored.md` with the strengthened ignored entry.
5. Update support docs listed above only where the report detail is missing or weaker.
6. Do not edit `by-memory/-coverage-report.md`; place the exact replacement row in B010 notes after implementation.
7. Validate every touched doc from `source-3/project-documentation` with file-mode validator:
   - `python .\tools\validator.py --mode file --file by-memory/0x0041d3b0-0x0041d431.SmallStringStorageAssign.md --apply --queue-timeout 240`
   - `python .\tools\validator.py --mode file --file by-memory/-ignored.md --apply --queue-timeout 240`
   - `python .\tools\validator.py --mode file --file by-memory/0x0041ba40-0x004245f5.FittingRoomUiCore.md --apply --queue-timeout 240` if edited
   - `python .\tools\validator.py --mode file --file by-file/FittingRoom.md --apply --queue-timeout 240` if edited
   - `python .\tools\validator.py --mode file --file by-file/JsonCpp.md --apply --queue-timeout 240` if edited
   - `python .\tools\validator.py --mode file --file by-meta/client_libraries.md --apply --queue-timeout 240` if edited
   - `python .\tools\validator.py --mode file --file by-meta/client_string_handling.md --apply --queue-timeout 240` if edited
   - validate optional sibling docs if edited.
8. Report validator exit codes and whether `project-level/-auto-completion-stats.md`, `tools/validator.ini`, generated reports, or other side-effect files changed.

## IDA Rename / Type / Comment Recommendations

No IDA changes were performed in this report-only pass.

Recommended descriptive rename if IDA naming cleanup is later authorized:

- Rename `sub_41D3B0` to `MsvcSmallStringStorageCopyConstruct` or `std_string_sso15_copy_construct`.
- Do not rename it to `SmallStringStorage::Assign`, `FittingRoom*`, `JsonCpp*`, `StringBase*`, `StringUtil*`, or `SimpleUString*`.
- Mark the name as descriptive/inferred, not original-symbol proof.

Recommended analysis type:

```cpp
struct MsvcSmallString24 {
    union {
        char inlineBytes[16];
        char* heapBytes;
    };
    unsigned int length;
    unsigned int capacity;
};

MsvcSmallString24* __thiscall MsvcSmallStringStorageCopyConstruct(
    MsvcSmallString24* this_,
    const MsvcSmallString24* source);
```

Recommended repeatable comment:

```text
MSVC/Dinkumware-style std::string SSO-15 storage copy helper. Shared compiler/runtime support; callers span FittingRoom, JsonCpp, and STL/runtime support. Do not reconstruct as NexusTK product source.
```

## Open Questions With Attempted Resolution

- Exact vendor/internal helper symbol: unresolved. Checked local export, target docs, sibling MSVC support docs, project unresolved aliases, and legacy report notes. No symbolized source name is available. Use a descriptive/inferred name only. This caps confidence but does not affect ownership/no-code recommendation.
- Exact compiler/runtime version: unresolved. Behavior matches MSVC/Dinkumware support documented by [UID:0000WN] and adjacent JsonCpp/STL runtime islands. A future toolchain/version audit could narrow this further, but it is not needed to reject product ownership.
- Whether the helper is emitted from JsonCpp or product instantiation: not separable from current evidence, and not necessary. Caller spread shows a shared template/runtime helper used by both. The rebuilt source should let the compiler/runtime emit equivalent support from all string-using source contexts.

## Validator Results

- No validator was run because this is a report-only assignment and no by-* docs were edited.
- No leases were used.

## Changed Files

- Created: `source-3/project-documentation/tools/leaser/Agents/Agent-B010/research/0002CZ-SmallStringStorageAssign-source-routing.md`
- Modified: none outside the B010 research folder.
- Moved to executed: none.

<!-- VALIDATOR-REPORT-HISTORY:BEGIN | DO NOT EDIT BY HAND -->
<!-- {"agent":"B010","command_id":"000000004165","destination_path":"executed-b-agent-research/B010/0002CZ-SmallStringStorageAssign-source-routing.md","details":"legacy registry reconstruction","event":"executed","timestamp":"2026-06-23T21:10:34","uid":"0002CZ"} -->
<!-- VALIDATOR-REPORT-HISTORY:END -->
